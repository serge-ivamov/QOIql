#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>

#include "../libqoi/libqoi.h"

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options);
void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview);

/* -----------------------------------------------------------------------------
   Generate a preview for file

   This function's job is to create preview for designated file
   ----------------------------------------------------------------------------- */

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
    printf("\nQuickLook Preview generator for QOI\n");
    printf("libqoi version:\t%s\n", libqoi_getversion());
    printf("qoif version:\t%s\n", qoif_getversion());

    CFStringRef path = CFURLCopyPath(url);
    path = CFURLCreateStringByReplacingPercentEscapes(kCFAllocatorDefault, path, CFSTR(""));
    CFIndex length  = CFStringGetLength(path);
    CFIndex maxlen = CFStringGetMaximumSizeForEncoding(length, kCFStringEncodingUTF8);

    char* file = (char*)malloc(maxlen);
    CFStringGetCString(path, file, maxlen, kCFStringEncodingUTF8);

    qoi_desc desc;
    void *pixels = NULL;
    pixels = libqoi_read(file, &desc, 0); // load and decode .qoi file
    int width = desc.width;
    int height = desc.height;
    int channels = desc.channels;
    int layers = kCGImageAlphaLast;
    if (channels == 3)
        layers = kCGImageAlphaNone;

    printf("(%s) channels: %d, width: %d, height: %d, colorspace: %d\n",
           file, channels, width, height, desc.colorspace);

    CGSize imageSize = CGSizeMake(desc.width, desc.height);
    CGContextRef ctx = QLPreviewRequestCreateContext(preview, imageSize, true, options);
    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, pixels, width*height*channels, NULL);
    CGImageRef image =  CGImageCreate(width, height, 8, 8*channels, width * channels, CGColorSpaceCreateDeviceRGB(), layers, provider, NULL, false, kCGRenderingIntentDefault);
    CGContextDrawImage(ctx, CGRectMake(0, 0, width, height), image);
    CGContextFlush(ctx);
    QLPreviewRequestFlushContext(preview, ctx);
    CFRelease(ctx);
    free(pixels);

    return noErr;
}

void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview)
{
    // Implement only if supported
}
