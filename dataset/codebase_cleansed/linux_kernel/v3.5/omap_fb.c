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
if (plane->bo)
drm_gem_object_unreference_unlocked(plane->bo);
}
kfree(omap_fb);
}
static int omap_framebuffer_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned flags, unsigned color,
struct drm_clip_rect *clips, unsigned num_clips)
{
int i;
for (i = 0; i < num_clips; i++) {
omap_framebuffer_flush(fb, clips[i].x1, clips[i].y1,
clips[i].x2 - clips[i].x1,
clips[i].y2 - clips[i].y1);
}
return 0;
}
void omap_framebuffer_update_scanout(struct drm_framebuffer *fb, int x, int y,
struct omap_overlay_info *info)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
const struct format *format = omap_fb->format;
struct plane *plane = &omap_fb->planes[0];
unsigned int offset;
offset = plane->offset +
(x * format->planes[0].stride_bpp) +
(y * plane->pitch / format->planes[0].sub_y);
info->color_mode = format->dss_format;
info->paddr = plane->paddr + offset;
info->screen_width = plane->pitch / format->planes[0].stride_bpp;
if (format->dss_format == OMAP_DSS_COLOR_NV12) {
plane = &omap_fb->planes[1];
offset = plane->offset +
(x * format->planes[1].stride_bpp) +
(y * plane->pitch / format->planes[1].sub_y);
info->p_uv_addr = plane->paddr + offset;
} else {
info->p_uv_addr = 0;
}
}
int omap_framebuffer_replace(struct drm_framebuffer *a,
struct drm_framebuffer *b, void *arg,
void (*unpin)(void *arg, struct drm_gem_object *bo))
{
int ret = 0, i, na, nb;
struct omap_framebuffer *ofba = to_omap_framebuffer(a);
struct omap_framebuffer *ofbb = to_omap_framebuffer(b);
na = a ? drm_format_num_planes(a->pixel_format) : 0;
nb = b ? drm_format_num_planes(b->pixel_format) : 0;
for (i = 0; i < max(na, nb); i++) {
struct plane *pa, *pb;
pa = (i < na) ? &ofba->planes[i] : NULL;
pb = (i < nb) ? &ofbb->planes[i] : NULL;
if (pa) {
unpin(arg, pa->bo);
pa->paddr = 0;
}
if (pb && !ret) {
ret = omap_gem_get_paddr(pb->bo, &pb->paddr, true);
if (!ret)
omap_gem_dma_sync(pb->bo, DMA_TO_DEVICE);
}
}
if (ret) {
for (i = 0; i < nb; i++) {
struct plane *pb = &ofba->planes[i];
if (pb->paddr) {
unpin(arg, pb->bo);
pb->paddr = 0;
}
}
}
return ret;
}
struct drm_gem_object *omap_framebuffer_bo(struct drm_framebuffer *fb, int p)
{
struct omap_framebuffer *omap_fb = to_omap_framebuffer(fb);
if (p >= drm_format_num_planes(fb->pixel_format))
return NULL;
return omap_fb->planes[p].bo;
}
struct drm_connector *omap_framebuffer_get_next_connector(
struct drm_framebuffer *fb, struct drm_connector *from)
{
struct drm_device *dev = fb->dev;
struct list_head *connector_list = &dev->mode_config.connector_list;
struct drm_connector *connector = from;
if (!from) {
return list_first_entry(connector_list, typeof(*from), head);
}
list_for_each_entry_from(connector, connector_list, head) {
if (connector != from) {
struct drm_encoder *encoder = connector->encoder;
struct drm_crtc *crtc = encoder ? encoder->crtc : NULL;
if (crtc && crtc->fb == fb) {
return connector;
}
}
}
return NULL;
}
void omap_framebuffer_flush(struct drm_framebuffer *fb,
int x, int y, int w, int h)
{
struct drm_connector *connector = NULL;
VERB("flush: %d,%d %dx%d, fb=%p", x, y, w, h, fb);
while ((connector = omap_framebuffer_get_next_connector(fb, connector))) {
if (connector->encoder && connector->encoder->crtc) {
struct drm_crtc *crtc = connector->encoder->crtc;
int cx = max(0, x - crtc->x);
int cy = max(0, y - crtc->y);
int cw = w + (x - crtc->x) - cx;
int ch = h + (y - crtc->y) - cy;
omap_connector_flush(connector, cx, cy, cw, ch);
}
}
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
struct drm_file *file, struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *bos[4];
struct drm_framebuffer *fb;
int ret;
ret = objects_lookup(dev, file, mode_cmd->pixel_format,
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
struct drm_mode_fb_cmd2 *mode_cmd, struct drm_gem_object **bos)
{
struct omap_framebuffer *omap_fb;
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
dev_err(dev->dev, "could not allocate fb\n");
ret = -ENOMEM;
goto fail;
}
fb = &omap_fb->base;
ret = drm_framebuffer_init(dev, fb, &omap_framebuffer_funcs);
if (ret) {
dev_err(dev->dev, "framebuffer init failed: %d\n", ret);
goto fail;
}
DBG("create: FB ID: %d (%p)", fb->base.id, fb);
omap_fb->format = format;
for (i = 0; i < n; i++) {
struct plane *plane = &omap_fb->planes[i];
int size, pitch = mode_cmd->pitches[i];
if (pitch < (mode_cmd->width * format->planes[i].stride_bpp)) {
dev_err(dev->dev, "provided buffer pitch is too small! %d < %d\n",
pitch, mode_cmd->width * format->planes[i].stride_bpp);
ret = -EINVAL;
goto fail;
}
size = pitch * mode_cmd->height / format->planes[i].sub_y;
if (size > (bos[i]->size - mode_cmd->offsets[i])) {
dev_err(dev->dev, "provided buffer object is too small! %d < %d\n",
bos[i]->size - mode_cmd->offsets[i], size);
ret = -EINVAL;
goto fail;
}
plane->bo = bos[i];
plane->offset = mode_cmd->offsets[i];
plane->pitch = pitch;
plane->paddr = 0;
}
drm_helper_mode_fill_fb_struct(fb, mode_cmd);
return fb;
fail:
if (fb) {
omap_framebuffer_destroy(fb);
}
return ERR_PTR(ret);
}
