# Onion Docker Helloworld

This is a demo project to show how to run [Onion](https://github.com/davidmoreno/onion) apps in docker and maybe even on K8s clouds.

## Build

```bash
docker build -t onion-docker-helloworld .
```

## Run

```bash
docker run -p 127.0.0.1:8084:8084/tcp --rm onion-docker-helloworld
```

With `curl http://127.0.0.1:8084/whatever` you'll see:

```
HTTP/1.1 200 OK
Content-Length: 23
Content-Type: application/json; charset=utf-8
Date: Wed, 26 May 2021 09:12:31 UTC
Server: libonion v0.8.157.c202c - coralbits.com
access-control-allow-origin: *

{ "msg": "helloworld" }
```


Press <kbd>Ctrl+C</kbd> to exit. The port is defined in [main.c](./main.c).

## Docker

There're two `Dockerfile`s in this repo. [One](./Dockerfile) is for building the app itself, [the other](./Dockerfile.onion) is for building the runtime container of Onion. I've shipped [a minimum build at dockerhub](https://hub.docker.com/r/ironblood/onion-runtime) which is also used by this repo, however, you may want to enable more Onion features, update Onion to the latest version or switch another Linux distro image, please check out the comments in [Dockerfile.onion](./Dockerfile.onion).

## License

MIT
