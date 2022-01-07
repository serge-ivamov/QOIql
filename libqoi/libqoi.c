#define QOI_IMPLEMENTATION
#include "qoi.h"
#include "libqoi.h"

#define EXPORT __attribute__((visibility("default")))

EXPORT
char *libqoi_getversion() {
    return LIBQOI_VERS;
} // libqoi_getversion()

EXPORT
char *libqoi_getversion_major() {
    return LIBQOI_VERS_MAJOR;
} // libqoi_getversion_major()

EXPORT
char *libqoi_getversion_minor() {
    return LIBQOI_VERS_MINOR;
} // libqoi_getversion_minor()

EXPORT
char *libqoi_getversion_patch() {
    return LIBQOI_VERS_PATCH;
} // libqoi_getversion_patch()

EXPORT
char *qoif_getversion() {
    return QOIF_VERS;
} // qoif_getversion()

EXPORT
char *qoif_getversion_major() {
    return QOIF_VERS_MAJOR;
} // qoif_getversion_major()

EXPORT
char *qoif_getversion_minor() {
    return QOIF_VERS_MINOR;
} // qoif_getversion_minor()

EXPORT
void *libqoi_encode(const void *data, const qoi_desc *desc, int *out_len) {
    return qoi_encode(data, desc, out_len);
} // libqoi_encode()

EXPORT
int libqoi_write(const char *filename, const void *data, const qoi_desc *desc) {
    return qoi_write(filename, data, desc);
} // libqoi_write()

EXPORT
void *libqoi_decode(const void *data, int size, qoi_desc *desc, int channels) {
    return qoi_decode(data, size, desc, channels);
} // libqoi_decode()

EXPORT
void *libqoi_read(const char *filename, qoi_desc *desc, int channels) {
    return qoi_read(filename, desc, channels);
} // libqoi_read()

