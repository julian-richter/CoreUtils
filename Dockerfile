# Use Debian ARM64 (arm64v8) base image suitable for Apple Silicon
FROM arm64v8/debian:bookworm-slim

# Install build dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    uuid-dev \
    ca-certificates \
    bash \
    && rm -rf /var/lib/apt/lists/*

# Create a working directory
WORKDIR /app

# Copy the project files to the container
COPY . /app/

RUN mkdir -p build

# Configure and build the project
RUN cd build && \
    cmake .. && \
    make -j$(nproc)

RUN mkdir -p artifacts/linux

# Create a run script that will execute all examples
RUN echo '#!/bin/bash' > run_examples.sh && \
    echo 'echo "Running all example applications:"' >> run_examples.sh && \
    echo 'echo "============================="' >> run_examples.sh && \
    echo 'cd /app/build/bin/*/Linux' >> run_examples.sh && \
    echo 'echo "Directory contents:"' >> run_examples.sh && \
    echo 'ls -la' >> run_examples.sh && \
    echo 'echo ""' >> run_examples.sh && \
    echo 'for exe in ex_* example; do' >> run_examples.sh && \
    echo '  if [ -f "$exe" ] && [ -x "$exe" ]; then' >> run_examples.sh && \
    echo '    echo ""' >> run_examples.sh && \
    echo '    echo "Running $exe:"' >> run_examples.sh && \
    echo '    echo "----------------------------"' >> run_examples.sh && \
    echo '    ./$exe' >> run_examples.sh && \
    echo '    echo "----------------------------"' >> run_examples.sh && \
    echo '    echo "Exit code: $?"' >> run_examples.sh && \
    echo '  fi' >> run_examples.sh && \
    echo 'done' >> run_examples.sh && \
    chmod +x run_examples.sh

CMD ["/app/run_examples.sh"]