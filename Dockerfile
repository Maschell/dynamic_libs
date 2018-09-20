FROM wiiulegacy/core:0.1

RUN rm -rf $DEVKITPRO/portlibs
RUN git clone https://github.com/Maschell/dynamic_libs -b lib
WORKDIR dynamic_libs
RUN git checkout -b v0.1
RUN 7z x -y ./libs/portlibs.zip -o${DEVKITPRO}
RUN make && make install
WORKDIR ..
RUN rm -rf dynamic_libs