uint32_t omap_framebuffer_get_formats(uint32_t *pixel_formats,
uint32_t max_formats, enum omap_color_mode supported_modes)
{
uint32_t nformats = 0;
int i = 0;
for (i = 0; i < ARRAY_SIZE(formats) && nformats < max_formats; i++)
if (formats[i].dss_format & supported_modes)
pixel_formats[nformats++] = formats[i].pixel_format;
return nformats;
}
static int omap_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
return drm_gem_handle_create(file_priv,
omap_fb->planes[0].bo, handle);
}
static void omap_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
int i, n = drm_format_num_planes(fb->pixel_format);
DBG("destroy: FB ID: %d (%p)", fb->base.id, fb);
drm_framebuffer_cleanup(fb);
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
drm_gem_object_unreference_unlocked(plane->bo);
}
kfree(omap_fb);
}
static uint32_t get_linear_addr(struct plane *plane,
const struct format *format, int n, int x, int y)
{
uint32_t offset;
offset = plane->offset +
(x * format->planes[n].stride_bpp) +
(y * plane->pitch / format->planes[n].sub_y);
return plane->paddr + offset;
}
bool omap_framebuffer_supports_rotation(struct drm_framebuffer *fb)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
struct plane *plane = &omap_fb->planes[0];
return omap_gem_flags(plane->bo) & OMAP_BO_TILED;
}
void omap_framebuffer_update_scanout(struct drm_framebuffer *fb,
struct omap_drm_window *win, struct omap_overlay_info *info)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
const struct format *format = omap_fb->format;
struct plane *plane = &omap_fb->planes[0];
uint32_t x, y, orient = 0;
info->color_mode = format->dss_format;
info->pos_x = win->crtc_x;
info->pos_y = win->crtc_y;
info->out_width = win->crtc_w;
info->out_height = win->crtc_h;
info->width = win->src_w;
info->height = win->src_h;
x = win->src_x;
y = win->src_y;
if (omap_gem_flags(plane->bo) & OMAP_BO_TILED) {
uint32_t w = win->src_w;
uint32_t h = win->src_h;
switch (win->rotation & DRM_ROTATE_MASK) {
default:
dev_err(fb->dev->dev, "invalid rotation: %02x",
(uint32_t)win->rotation);
case 0:
case DRM_ROTATE_0:
orient = 0;
break;
case DRM_ROTATE_90:
orient = MASK_XY_FLIP | MASK_X_INVERT;
break;
case DRM_ROTATE_180:
orient = MASK_X_INVERT | MASK_Y_INVERT;
break;
case DRM_ROTATE_270:
orient = MASK_XY_FLIP | MASK_Y_INVERT;
break;
}
if (win->rotation & DRM_REFLECT_X)
orient ^= MASK_X_INVERT;
if (win->rotation & DRM_REFLECT_Y)
orient ^= MASK_Y_INVERT;
if (orient & MASK_XY_FLIP)
swap(w, h);
if (orient & MASK_Y_INVERT)
y += h - 1;
if (orient & MASK_X_INVERT)
x += w - 1;
omap_gem_rotated_paddr(plane->bo, orient, x, y, &info->paddr);
info->rotation_type = OMAP_DSS_ROT_TILER;
info->screen_width = omap_gem_tiled_stride(plane->bo, orient);
} else {
switch (win->rotation & DRM_ROTATE_MASK) {
case 0:
case DRM_ROTATE_0:
break;
default:
dev_warn(fb->dev->dev,
"rotation '%d' ignored for non-tiled fb\n",
win->rotation);
win->rotation = 0;
break;
}
info->paddr = get_linear_addr(plane, format, 0, x, y);
info->rotation_type = OMAP_DSS_ROT_DMA;
info->screen_width = plane->pitch;
}
info->screen_width /= format->planes[0].stride_bpp;
if (format->dss_format == OMAP_DSS_COLOR_NV12) {
plane = &omap_fb->planes[1];
if (info->rotation_type == OMAP_DSS_ROT_TILER) {
WARN_ON(!(omap_gem_flags(plane->bo) & OMAP_BO_TILED));
omap_gem_rotated_paddr(plane->bo, orient,
x/2, y/2, &info->p_uv_addr);
} else {
info->p_uv_addr = get_linear_addr(plane, format, 1, x, y);
}
} else {
info->p_uv_addr = 0;
}
}
int omap_framebuffer_pin(struct drm_framebuffer *fb)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
int ret, i, n = drm_format_num_planes(fb->pixel_format);
mutex_lock(&omap_fb->lock);
if (omap_fb->pin_count > 0) {
omap_fb->pin_count++;
mutex_unlock(&omap_fb->lock);
return 0;
}
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
ret = omap_gem_get_paddr(plane->bo, &plane->paddr, true);
if (ret)
goto fail;
omap_gem_dma_sync(plane->bo, DMA_TO_DEVICE);
}
omap_fb->pin_count++;
mutex_unlock(&omap_fb->lock);
return 0;
fail:
for (i--; i >= 0; i--) {
struct plane *plane = &omap_fb->planes[i];
omap_gem_put_paddr(plane->bo);
plane->paddr = 0;
}
mutex_unlock(&omap_fb->lock);
return ret;
}
void omap_framebuffer_unpin(struct drm_framebuffer *fb)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
int i, n = drm_format_num_planes(fb->pixel_format);
mutex_lock(&omap_fb->lock);
omap_fb->pin_count--;
if (omap_fb->pin_count > 0) {
mutex_unlock(&omap_fb->lock);
return;
}
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
omap_gem_put_paddr(plane->bo);
plane->paddr = 0;
}
mutex_unlock(&omap_fb->lock);
}
struct drm_connector *omap_framebuffer_get_next_connector(
struct drm_framebuffer *fb, struct drm_connector *from)
{
struct drm_device *dev = fb->dev;
struct list_head *connector_list = &dev->mode_config.connector_list;
struct drm_connector *connector = from;
if (!from)
return list_first_entry_or_null(connector_list, typeof(*from),
head);
list_for_each_entry_from(connector, connector_list, head) {
if (connector != from) {
struct drm_encoder *encoder = connector->encoder;
struct drm_crtc *crtc = encoder ? encoder->crtc : NULL;
if (crtc && crtc->primary->fb == fb)
return connector;
}
}
return NULL;
}
void omap_framebuffer_describe(struct drm_framebuffer *fb, struct seq_file *m)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
int i, n = drm_format_num_planes(fb->pixel_format);
seq_printf(m, "fb: %dx%d@%4.4s\n", fb->width, fb->height,
(char *)&fb->pixel_format);
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
seq_printf(m, " %d: offset=%d pitch=%d, obj: ",
i, plane->offset, plane->pitch);
omap_gem_describe(plane->bo, m);
}
}
struct drm_framebuffer *omap_framebuffer_create(struct drm_device *dev,
struct drm_file *file, const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *bos[4];
struct drm_framebuffer *fb;
int ret;
ret = objects_lookup(file, mode_cmd->pixel_format,
bos, mode_cmd->handles);
if (ret)
return ERR_PTR(ret);
fb = omap_framebuffer_init(dev, mode_cmd, bos);
if (IS_ERR(fb)) {
int i, n = drm_format_num_planes(mode_cmd->pixel_format);
for (i = 0; i < n; i++)
drm_gem_object_unreference_unlocked(bos[i]);
return fb;
}
return fb;
}
struct drm_framebuffer *omap_framebuffer_init(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode_cmd, struct drm_gem_object **bos)
{
struct omap_framebuffer *omap_fb = NULL;
struct drm_framebuffer *fb = NULL;
const struct format *format = NULL;
int ret, i, n = drm_format_num_planes(mode_cmd->pixel_format);
DBG("create framebuffer: dev=%p, mode_cmd=%p (%dx%d@%4.4s)",
dev, mode_cmd, mode_cmd->width, mode_cmd->height,
(char *)&mode_cmd->pixel_format);
for (i = 0; i < ARRAY_SIZE(formats); i++) {
if (formats[i].pixel_format == mode_cmd->pixel_format) {
format = &formats[i];
break;
}
}
if (!format) {
dev_err(dev->dev, "unsupported pixel format: %4.4s\n",
(char *)&mode_cmd->pixel_format);
ret = -EINVAL;
goto fail;
}
omap_fb = kzalloc(sizeof(*omap_fb), GFP_KERNEL);
if (!omap_fb) {
ret = -ENOMEM;
goto fail;
}
fb = &omap_fb->base;
omap_fb->format = format;
mutex_init(&omap_fb->lock);
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
int size, pitch = mode_cmd->pitches[i];
if (pitch < (mode_cmd->width * format->planes[i].stride_bpp)) {
dev_err(dev->dev, "provided buffer pitch is too small! %d < %d\n",
pitch, mode_cmd->width * format->planes[i].stride_bpp);
ret = -EINVAL;
goto fail;
}
if (pitch % format->planes[i].stride_bpp != 0) {
dev_err(dev->dev,
"buffer pitch (%d bytes) is not a multiple of pixel size (%d bytes)\n",
pitch, format->planes[i].stride_bpp);
ret = -EINVAL;
goto fail;
}
size = pitch * mode_cmd->height / format->planes[i].sub_y;
if (size > (omap_gem_mmap_size(bos[i]) - mode_cmd->offsets[i])) {
dev_err(dev->dev, "provided buffer object is too small! %d < %d\n",
bos[i]->size - mode_cmd->offsets[i], size);
ret = -EINVAL;
goto fail;
}
if (i > 0 && pitch != mode_cmd->pitches[i - 1]) {
dev_err(dev->dev,
"pitches are not the same between framebuffer planes %d != %d\n",
pitch, mode_cmd->pitches[i - 1]);
ret = -EINVAL;
goto fail;
}
plane->bo = bos[i];
plane->offset = mode_cmd->offsets[i];
plane->pitch = pitch;
plane->paddr = 0;
}
drm_helper_mode_fill_fb_struct(fb, mode_cmd);
ret = drm_framebuffer_init(dev, fb, &omap_framebuffer_funcs);
if (ret) {
dev_err(dev->dev, "framebuffer init failed: %d\n", ret);
goto fail;
}
DBG("create: FB ID: %d (%p)", fb->base.id, fb);
return fb;
fail:
kfree(omap_fb);
return ERR_PTR(ret);
}
