FROM ironblood/onion-runtime:c202c AS compile
WORKDIR /root
COPY . .

# Uncomment this line if you're in China to speed up installing dependencies
# RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.ustc.edu.cn/g' /etc/apk/repositories

RUN apk add cmake make alpine-sdk
RUN (rm -rf build; mkdir build; cd build; cmake ..; make)

FROM ironblood/onion-runtime:c202c
WORKDIR /root
COPY --from=compile /root/build/onion-docker-helloworld .
CMD ["./onion-docker-helloworld"]
