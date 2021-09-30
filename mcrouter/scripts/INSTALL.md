# Mcrouter Installation on Amazon Linux 2

We need to do this for both x86_64 architecture and graviton. Repeat the following steps
for each architecture

1. Launch a temporary instance for each x86_64 and ARM instance type and use Session Manager to connect.
    - Amazon Linux 2 AMI [ebs, hvm]
    - x86: m5ad.2xlarge
    - arm: m6gd.2xlarge

1. Switch to root for all subsequent commands
    ```shell
    sudo su -
    ```

1. Attach the EBS volume. Mcrouter needs a little more space than default 8GB volume.
    ```shell
    file -s /dev/nvme1n1
    mkfs -t xfs /dev/nvme1n1
    mkdir /build
    mount /dev/nvme1n1 /build
    ```

1. Clone the `useshortcut\mcrouter` repo.
    ```shell
    yum -y update
    yum -y install git
    cd /build
    git clone https://github.com/useshortcut/mcrouter.git
    cd mcrouter
    # Switch to branch if necessary
    # git checkout <branch>
    ```

1. Install Pre-built Dependencies
    ```shell
    cd /build/mcrouter/mcrouter/scripts
    ./install_deps_amazon-linux-2.sh
    ```

1. Compile additional dependencies, mcrouter and then archive
    ```shell
    cd /build/mcrouter/mcrouter/scripts
    INSTALL_DIR=/build/output
    # Build dependencies and mcrouter
    ./get_and_build_by_make.sh $INSTALL_DIR all
    # Now archive
    ./get_and_build_by_make.sh $INSTALL_DIR archive
    ```
