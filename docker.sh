sudo docker build buildenv -t riskyos-buildenv
sudo docker run --rm -it -v $(pwd):/root/env riskyos-buildenv
