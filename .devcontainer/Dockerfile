FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    cmake \
    git \
    wget \
    curl \
    unzip \
    libgtest-dev \
    libgmock-dev \
    && apt-get clean

# Install Google Test and Google Mock
# Google Test and Google Mock need to be built manually as they are not in the official repositories
# RUN cd /usr/src/gtest && \
#     cmake . && \
#     make && \
#     make install && \
#     cd /usr/src/gmock && \
#     cmake . && \
#     make && \
#     make install

# Set the default shell to bash
SHELL ["/bin/bash", "-c"]

# Set the working directory inside the container
WORKDIR /workspace

# The default command to run when the container starts (opens bash terminal)
CMD ["bash"]
