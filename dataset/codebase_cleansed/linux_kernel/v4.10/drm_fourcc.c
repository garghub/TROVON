static char printable_char(int c)
{
return isascii(c) && isprint(c) ? c : '?';
}
uint32_t drm_mode_legacy_fb_format(uint32_t bpp, uint32_t depth)
{
uint32_t fmt;
switch (bpp) {
case 8:
fmt = DRM_FORMAT_C8;
break;
case 16:
if (depth == 15)
fmt = DRM_FORMAT_XRGB1555;
else
fmt = DRM_FORMAT_RGB565;
break;
case 24:
fmt = DRM_FORMAT_RGB888;
break;
case 32:
if (depth == 24)
fmt = DRM_FORMAT_XRGB8888;
else if (depth == 30)
fmt = DRM_FORMAT_XRGB2101010;
else
fmt = DRM_FORMAT_ARGB8888;
break;
default:
DRM_ERROR("bad bpp, assuming x8r8g8b8 pixel format\n");
fmt = DRM_FORMAT_XRGB8888;
break;
}
return fmt;
}
const char *drm_get_format_name(uint32_t format, struct drm_format_name_buf *buf)
{
snprintf(buf->str, sizeof(buf->str),
"%c%c%c%c %s-endian (0x%08x)",
printable_char(format & 0xff),
printable_char((format >> 8) & 0xff),
printable_char((format >> 16) & 0xff),
printable_char((format >> 24) & 0x7f),
format & DRM_FORMAT_BIG_ENDIAN ? "big" : "little",
format);
return buf->str;
}
const struct drm_format_info *__drm_format_info(u32 format)
{
static const struct drm_format_info formats[] = {
{ .format = DRM_FORMAT_C8, .depth = 8, .num_planes = 1, .cpp = { 1, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGB332, .depth = 8, .num_planes = 1, .cpp = { 1, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGR233, .depth = 8, .num_planes = 1, .cpp = { 1, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XRGB4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XBGR4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBX4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRX4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ARGB4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ABGR4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBA4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRA4444, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XRGB1555, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XBGR1555, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBX5551, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRX5551, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ARGB1555, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ABGR1555, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBA5551, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRA5551, .depth = 15, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGB565, .depth = 16, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGR565, .depth = 16, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGB888, .depth = 24, .num_planes = 1, .cpp = { 3, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGR888, .depth = 24, .num_planes = 1, .cpp = { 3, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XRGB8888, .depth = 24, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XBGR8888, .depth = 24, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBX8888, .depth = 24, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRX8888, .depth = 24, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XRGB2101010, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_XBGR2101010, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBX1010102, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRX1010102, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ARGB2101010, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ABGR2101010, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBA1010102, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRA1010102, .depth = 30, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ARGB8888, .depth = 32, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_ABGR8888, .depth = 32, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_RGBA8888, .depth = 32, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_BGRA8888, .depth = 32, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_YUV410, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 4, .vsub = 4 },
{ .format = DRM_FORMAT_YVU410, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 4, .vsub = 4 },
{ .format = DRM_FORMAT_YUV411, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 4, .vsub = 1 },
{ .format = DRM_FORMAT_YVU411, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 4, .vsub = 1 },
{ .format = DRM_FORMAT_YUV420, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 2, .vsub = 2 },
{ .format = DRM_FORMAT_YVU420, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 2, .vsub = 2 },
{ .format = DRM_FORMAT_YUV422, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_YVU422, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_YUV444, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_YVU444, .depth = 0, .num_planes = 3, .cpp = { 1, 1, 1 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_NV12, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 2, .vsub = 2 },
{ .format = DRM_FORMAT_NV21, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 2, .vsub = 2 },
{ .format = DRM_FORMAT_NV16, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_NV61, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_NV24, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_NV42, .depth = 0, .num_planes = 2, .cpp = { 1, 2, 0 }, .hsub = 1, .vsub = 1 },
{ .format = DRM_FORMAT_YUYV, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_YVYU, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_UYVY, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_VYUY, .depth = 0, .num_planes = 1, .cpp = { 2, 0, 0 }, .hsub = 2, .vsub = 1 },
{ .format = DRM_FORMAT_AYUV, .depth = 0, .num_planes = 1, .cpp = { 4, 0, 0 }, .hsub = 1, .vsub = 1 },
};
unsigned int i;
for (i = 0; i < ARRAY_SIZE(formats); ++i) {
if (formats[i].format == format)
return &formats[i];
}
return NULL;
}
const struct drm_format_info *drm_format_info(u32 format)
{
const struct drm_format_info *info;
info = __drm_format_info(format);
WARN_ON(!info);
return info;
}
int drm_format_num_planes(uint32_t format)
{
const struct drm_format_info *info;
info = drm_format_info(format);
return info ? info->num_planes : 1;
}
int drm_format_plane_cpp(uint32_t format, int plane)
{
const struct drm_format_info *info;
info = drm_format_info(format);
if (!info || plane >= info->num_planes)
return 0;
return info->cpp[plane];
}
int drm_format_horz_chroma_subsampling(uint32_t format)
{
const struct drm_format_info *info;
info = drm_format_info(format);
return info ? info->hsub : 1;
}
int drm_format_vert_chroma_subsampling(uint32_t format)
{
const struct drm_format_info *info;
info = drm_format_info(format);
return info ? info->vsub : 1;
}
int drm_format_plane_width(int width, uint32_t format, int plane)
{
const struct drm_format_info *info;
info = drm_format_info(format);
if (!info || plane >= info->num_planes)
return 0;
if (plane == 0)
return width;
return width / info->hsub;
}
int drm_format_plane_height(int height, uint32_t format, int plane)
{
const struct drm_format_info *info;
info = drm_format_info(format);
if (!info || plane >= info->num_planes)
return 0;
if (plane == 0)
return height;
return height / info->vsub;
}
