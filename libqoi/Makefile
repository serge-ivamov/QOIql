
SRCS = qoibench.c qoiconv.c qoifuzz.c
CFLAGS = -std=c99 -O3 -mmacosx-version-min=10.13
TARGETS = libqoi test
ARCH_X64 = -target x86_64-apple-macos10.13
ARCH_ARM = -target arm64-apple-macos11
ARCH_UNI = -arch x86_64 -arch arm64
DYLIB = -dynamiclib -current_version 1.0 -compatibility_version 1.0 -fvisibility=hidden -o libqoi.A.dylib
STATICLIB = -static -o libqoi.a

all: libqoi test
old: ${TARGETS}

libqoi:
	cc ${CFLAGS} ${ARCH_UNI} -c libqoi.c
	cc ${DYLIB} ${ARCH_UNI} libqoi.o
	libtool ${STATICLIB} libqoi.o

test: libqoi
	cc test.c libqoi.A.dylib -o test

clean:
	rm -f ${TARGETS} *.o *.dylib *.a
