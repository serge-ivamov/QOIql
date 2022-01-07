#ifndef LIBQOI_H
#define LIBQOI_H

#define LIBQOI_VERS_MAJOR "1"
#define LIBQOI_VERS_MINOR "0"
#define LIBQOI_VERS_PATCH "0"
#define LIBQOI_VERS LIBQOI_VERS_MAJOR "." LIBQOI_VERS_MINOR "." LIBQOI_VERS_PATCH

#define QOIF_VERS_MAJOR "1"
#define QOIF_VERS_MINOR "0"
#define QOIF_VERS QOIF_VERS_MAJOR "." QOIF_VERS_MINOR

#ifndef QOI_H
#define QOI_SRGB   0
#define QOI_LINEAR 1

typedef struct {
        unsigned int width;
        unsigned int height;
        unsigned char channels;
        unsigned char colorspace;
} qoi_desc;
#endif // QOI_H

char *libqoi_getversion(void);
char *libqoi_getversion_major(void);
char *libqoi_getversion_minor(void);
char *libqoi_getversion_patch(void);
char *qoif_getversion(void);
char *qoif_getversion_major(void);
char *qoif_getversion_minor(void);

void *libqoi_encode(const void *data, const qoi_desc *desc, int *out_len);
int  libqoi_write(const char *filename, const void *data, const qoi_desc *desc);
void *libqoi_decode(const void *data, int size, qoi_desc *desc, int channels);
void *libqoi_read(const char *filename, qoi_desc *desc, int channels);

#endif // LIBQOI_H
