# Matchbox Wallet - installation

## 1. Download the latest version of this software on your Matchbox device

Log in as "root" on your Matchbox and run the following commands to download the necessary dependencies and the latest version of this software from GitHub:

```sh
apt update
apt -y upgrade
apt -y install git openssl
git clone https://github.com/libersoft-org/matchbox-wallet.git
cd matchbox-wallet/
```

## 2. Build the software from source codes

If you'd like to build this software from source code:

```sh
./build.sh
```

## 3. Run the software

If you'd like to run it on X / Wayland:

```sh
./start.sh
```

or if you'd like to run it from shell (without X / Wayland):

```sh
./start-fb.sh
```
