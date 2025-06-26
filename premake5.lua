function getExampleFiles()
    -- Match files in 'examples' starting with 'ex_' and ending with '.c' or '.cxx'
    local c_files = os.matchfiles("examples/ex_*.c")
    local cxx_files = os.matchfiles("examples/ex_*.cxx")

    -- Combine tables
    local exampleFiles = {}
    for _, f in ipairs(c_files) do table.insert(exampleFiles, f) end
    for _, f in ipairs(cxx_files) do table.insert(exampleFiles, f) end

    return exampleFiles
end

workspace "coreUtils"
    configurations { "Debug", "Release" }
    location "build"
    language "C++"
    cppdialect "C++17"
    cdialect "C11"
    startproject "example"

    -- Detect architecture automatically
    filter "architecture:x86_64 or architecture:x64"
        architecture "x86_64"
    filter "architecture:arm64 or architecture:aarch64"
        architecture "ARM64"
    filter {}

    -- Platform-specific settings
    filter "system:macosx"
        defines { "PLATFORM_MACOS=1" }
        buildoptions { "-Wall", "-Werror" }
        
    filter "system:linux"
        defines { "PLATFORM_LINUX=1" }
        buildoptions { "-Wall", "-Werror" }
        
    filter {}

project "coreUtils"
    kind "SharedLib"
    language "C"
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}"
    objdir "%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}"

    files { "src/**.c", "include/**.h" }
    includedirs { "include" }

    -- Copy build artifacts to the 'artifacts' folder
    postbuildcommands {
        "{MKDIR} %{wks.location}/../artifacts/%{cfg.system}",
        "{COPY} %{cfg.buildtarget.abspath} %{wks.location}/../artifacts/%{cfg.system}/"
    }

    -- Platform-specific files and settings
    filter "system:macosx"
        targetextension ".dylib"
        
    filter "system:linux"
        targetextension ".so"
        pic "On"

    -- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "example"
    kind "ConsoleApp"
    language "C++"
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}"
    objdir "%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}"

    files { "examples/**.cxx" }
    includedirs { "include" }
    links { "coreUtils" }

    -- Copy build artifacts to the 'artifacts' folder
    postbuildcommands {
        "{MKDIR} %{wks.location}/../artifacts/%{cfg.system}",
        "{COPY} %{cfg.buildtarget.abspath} %{wks.location}/../artifacts/%{cfg.system}/"
    }

    -- Platform-specific settings
    filter "system:macosx"
        defines { "PLATFORM_MACOS=1" }
        
    filter "system:linux"
        defines { "PLATFORM_LINUX=1" }
        
    -- Configuration-specific settings
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

-- Create projects for each example file that matches the pattern
for _, filepath in ipairs(getExampleFiles()) do
    local file = filepath:match("examples/(.+)$") -- get file name only
    local name = file:match("^(.-)%.")  -- remove extension for project name

    project(name)
        kind "ConsoleApp"
        language "C++"
        targetdir "%{wks.location}/bin/%{cfg.buildcfg}/%{cfg.system}"
        objdir "%{wks.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}"

        files { filepath }
        includedirs { "include" }
        links { "coreUtils" }

        postbuildcommands {
            "{MKDIR} %{wks.location}/../artifacts/%{cfg.system}",
            "{COPY} %{cfg.buildtarget.abspath} %{wks.location}/../artifacts/%{cfg.system}/"
        }

        filter "system:macosx"
            defines { "PLATFORM_MACOS=1" }

        filter "system:linux"
            defines { "PLATFORM_LINUX=1" }

        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "NDEBUG" }
            optimize "On"

        filter {}
end
