static char printable_char(int c)
{
return isascii(c) && isprint(c) ? c : '?';
}
const char *drm_get_format_name(uint32_t format)
{
static char buf[32];
snprintf(buf, sizeof(buf),
"%c%c%c%c %s-endian (0x%08x)",
printable_char(format & 0xff),
printable_char((format >> 8) & 0xff),
printable_char((format >> 16) & 0xff),
printable_char((format >> 24) & 0x7f),
format & DRM_FORMAT_BIG_ENDIAN ? "big" : "little",
format);
return buf;
}
void drm_fb_get_bpp_depth(uint32_t format, unsigned int *depth,
int *bpp)
{
switch (format) {
case DRM_FORMAT_C8:
case DRM_FORMAT_RGB332:
case DRM_FORMAT_BGR233:
*depth = 8;
*bpp = 8;
break;
case DRM_FORMAT_XRGB1555:
case DRM_FORMAT_XBGR1555:
case DRM_FORMAT_RGBX5551:
case DRM_FORMAT_BGRX5551:
case DRM_FORMAT_ARGB1555:
case DRM_FORMAT_ABGR1555:
case DRM_FORMAT_RGBA5551:
case DRM_FORMAT_BGRA5551:
*depth = 15;
*bpp = 16;
break;
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
*depth = 16;
*bpp = 16;
break;
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
*depth = 24;
*bpp = 24;
break;
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_BGRX8888:
*depth = 24;
*bpp = 32;
break;
case DRM_FORMAT_XRGB2101010:
case DRM_FORMAT_XBGR2101010:
case DRM_FORMAT_RGBX1010102:
case DRM_FORMAT_BGRX1010102:
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_ABGR2101010:
case DRM_FORMAT_RGBA1010102:
case DRM_FORMAT_BGRA1010102:
*depth = 30;
*bpp = 32;
break;
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_BGRA8888:
*depth = 32;
*bpp = 32;
break;
default:
DRM_DEBUG_KMS("unsupported pixel format %s\n",
drm_get_format_name(format));
*depth = 0;
*bpp = 0;
break;
}
}
int drm_format_num_planes(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
case DRM_FORMAT_YUV411:
case DRM_FORMAT_YVU411:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
case DRM_FORMAT_YUV444:
case DRM_FORMAT_YVU444:
return 3;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_NV24:
case DRM_FORMAT_NV42:
return 2;
default:
return 1;
}
}
int drm_format_plane_cpp(uint32_t format, int plane)
{
unsigned int depth;
int bpp;
if (plane >= drm_format_num_planes(format))
return 0;
switch (format) {
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
return 2;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_NV24:
case DRM_FORMAT_NV42:
return plane ? 2 : 1;
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
case DRM_FORMAT_YUV411:
case DRM_FORMAT_YVU411:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
case DRM_FORMAT_YUV444:
case DRM_FORMAT_YVU444:
return 1;
default:
drm_fb_get_bpp_depth(format, &depth, &bpp);
return bpp >> 3;
}
}
int drm_format_horz_chroma_subsampling(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUV411:
case DRM_FORMAT_YVU411:
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
return 4;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_YVYU:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_VYUY:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
case DRM_FORMAT_NV16:
case DRM_FORMAT_NV61:
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
return 2;
default:
return 1;
}
}
int drm_format_vert_chroma_subsampling(uint32_t format)
{
switch (format) {
case DRM_FORMAT_YUV410:
case DRM_FORMAT_YVU410:
return 4;
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV21:
return 2;
default:
return 1;
}
}
int drm_format_plane_width(int width, uint32_t format, int plane)
{
if (plane >= drm_format_num_planes(format))
return 0;
if (plane == 0)
return width;
return width / drm_format_horz_chroma_subsampling(format);
}
int drm_format_plane_height(int height, uint32_t format, int plane)
{
if (plane >= drm_format_num_planes(format))
return 0;
if (plane == 0)
return height;
return height / drm_format_vert_chroma_subsampling(format);
}
