FROM wiiulegacy/core:0.1

MAINTAINER Maschell <maschell@gmx.de>

RUN git clone https://github.com/Maschell/dynamic_libs -b lib && cd dynamic_libs
WORKDIR dynamic_libs

RUN rm -rf $DEVKITPRO/portlibs && 7z x -y ./libs/portlibs.zip -o${DEVKITPRO}

RUN make && make install && \
	cp -r ${DEVKITPRO}/portlibs /artifacts
	
WORKDIR /artifacts

FROM scratch
COPY --from=0 /artifacts /artifacts