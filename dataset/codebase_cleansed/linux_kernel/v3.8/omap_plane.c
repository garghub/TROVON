static void unpin(void *arg, struct drm_gem_object *bo)
{
struct drm_plane *plane = arg;
struct omap_plane *omap_plane = to_omap_plane(plane);
if (kfifo_put(&omap_plane->unpin_fifo,
(const struct drm_gem_object **)&bo)) {
drm_gem_object_reference(bo);
} else {
dev_err(plane->dev->dev, "unpin fifo full!\n");
omap_gem_put_paddr(bo);
}
}
static int update_pin(struct drm_plane *plane, struct drm_framebuffer *fb)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct drm_framebuffer *pinned_fb = omap_plane->pinned_fb;
if (pinned_fb != fb) {
int ret;
DBG("%p -> %p", pinned_fb, fb);
if (fb)
drm_framebuffer_reference(fb);
ret = omap_framebuffer_replace(pinned_fb, fb, plane, unpin);
if (pinned_fb)
drm_framebuffer_unreference(pinned_fb);
if (ret) {
dev_err(plane->dev->dev, "could not swap %p -> %p\n",
omap_plane->pinned_fb, fb);
if (fb)
drm_framebuffer_unreference(fb);
omap_plane->pinned_fb = NULL;
return ret;
}
omap_plane->pinned_fb = fb;
}
return 0;
}
static void omap_plane_pre_apply(struct omap_drm_apply *apply)
{
struct omap_plane *omap_plane =
container_of(apply, struct omap_plane, apply);
struct omap_drm_window *win = &omap_plane->win;
struct drm_plane *plane = &omap_plane->base;
struct drm_device *dev = plane->dev;
struct omap_overlay_info *info = &omap_plane->info;
struct drm_crtc *crtc = plane->crtc;
enum omap_channel channel;
bool enabled = omap_plane->enabled && crtc;
bool ilace, replication;
int ret;
DBG("%s, enabled=%d", omap_plane->name, enabled);
update_pin(plane, enabled ? plane->fb : NULL);
if (!enabled) {
dispc_ovl_enable(omap_plane->id, false);
return;
}
channel = omap_crtc_channel(crtc);
omap_framebuffer_update_scanout(plane->fb, win, info);
DBG("%dx%d -> %dx%d (%d)", info->width, info->height,
info->out_width, info->out_height,
info->screen_width);
DBG("%d,%d %08x %08x", info->pos_x, info->pos_y,
info->paddr, info->p_uv_addr);
ilace = false;
replication = false;
ret = dispc_ovl_setup(omap_plane->id, info,
replication, omap_crtc_timings(crtc), false);
if (ret) {
dev_err(dev->dev, "dispc_ovl_setup failed: %d\n", ret);
return;
}
dispc_ovl_enable(omap_plane->id, true);
dispc_ovl_set_channel_out(omap_plane->id, channel);
}
static void omap_plane_post_apply(struct omap_drm_apply *apply)
{
struct omap_plane *omap_plane =
container_of(apply, struct omap_plane, apply);
struct drm_plane *plane = &omap_plane->base;
struct omap_overlay_info *info = &omap_plane->info;
struct drm_gem_object *bo = NULL;
struct callback cb;
cb = omap_plane->apply_done_cb;
omap_plane->apply_done_cb.fxn = NULL;
while (kfifo_get(&omap_plane->unpin_fifo, &bo)) {
omap_gem_put_paddr(bo);
drm_gem_object_unreference_unlocked(bo);
}
if (cb.fxn)
cb.fxn(cb.arg);
if (omap_plane->enabled) {
omap_framebuffer_flush(plane->fb, info->pos_x, info->pos_y,
info->out_width, info->out_height);
}
}
static int apply(struct drm_plane *plane)
{
if (plane->crtc) {
struct omap_plane *omap_plane = to_omap_plane(plane);
return omap_crtc_apply(plane->crtc, &omap_plane->apply);
}
return 0;
}
int omap_plane_mode_set(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h,
void (*fxn)(void *), void *arg)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_drm_window *win = &omap_plane->win;
win->crtc_x = crtc_x;
win->crtc_y = crtc_y;
win->crtc_w = crtc_w;
win->crtc_h = crtc_h;
win->src_x = src_x >> 16;
win->src_y = src_y >> 16;
win->src_w = src_w >> 16;
win->src_h = src_h >> 16;
if (fxn) {
BUG_ON(omap_plane->apply_done_cb.fxn);
omap_plane->apply_done_cb.fxn = fxn;
omap_plane->apply_done_cb.arg = arg;
}
plane->fb = fb;
plane->crtc = crtc;
return apply(plane);
}
static int omap_plane_update(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
omap_plane->enabled = true;
return omap_plane_mode_set(plane, crtc, fb,
crtc_x, crtc_y, crtc_w, crtc_h,
src_x, src_y, src_w, src_h,
NULL, NULL);
}
static int omap_plane_disable(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
omap_plane->win.rotation = BIT(DRM_ROTATE_0);
return omap_plane_dpms(plane, DRM_MODE_DPMS_OFF);
}
static void omap_plane_destroy(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
DBG("%s", omap_plane->name);
omap_irq_unregister(plane->dev, &omap_plane->error_irq);
omap_plane_disable(plane);
drm_plane_cleanup(plane);
WARN_ON(!kfifo_is_empty(&omap_plane->unpin_fifo));
kfifo_free(&omap_plane->unpin_fifo);
kfree(omap_plane);
}
int omap_plane_dpms(struct drm_plane *plane, int mode)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
bool enabled = (mode == DRM_MODE_DPMS_ON);
int ret = 0;
if (enabled != omap_plane->enabled) {
omap_plane->enabled = enabled;
ret = apply(plane);
}
return ret;
}
void omap_plane_install_properties(struct drm_plane *plane,
struct drm_mode_object *obj)
{
struct drm_device *dev = plane->dev;
struct omap_drm_private *priv = dev->dev_private;
struct drm_property *prop;
if (priv->has_dmm) {
prop = priv->rotation_prop;
if (!prop) {
const struct drm_prop_enum_list props[] = {
{ DRM_ROTATE_0, "rotate-0" },
{ DRM_ROTATE_90, "rotate-90" },
{ DRM_ROTATE_180, "rotate-180" },
{ DRM_ROTATE_270, "rotate-270" },
{ DRM_REFLECT_X, "reflect-x" },
{ DRM_REFLECT_Y, "reflect-y" },
};
prop = drm_property_create_bitmask(dev, 0, "rotation",
props, ARRAY_SIZE(props));
if (prop == NULL)
return;
priv->rotation_prop = prop;
}
drm_object_attach_property(obj, prop, 0);
}
prop = priv->zorder_prop;
if (!prop) {
prop = drm_property_create_range(dev, 0, "zorder", 0, 3);
if (prop == NULL)
return;
priv->zorder_prop = prop;
}
drm_object_attach_property(obj, prop, 0);
}
int omap_plane_set_property(struct drm_plane *plane,
struct drm_property *property, uint64_t val)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_drm_private *priv = plane->dev->dev_private;
int ret = -EINVAL;
if (property == priv->rotation_prop) {
DBG("%s: rotation: %02x", omap_plane->name, (uint32_t)val);
omap_plane->win.rotation = val;
ret = apply(plane);
} else if (property == priv->zorder_prop) {
DBG("%s: zorder: %02x", omap_plane->name, (uint32_t)val);
omap_plane->info.zorder = val;
ret = apply(plane);
}
return ret;
}
static void omap_plane_error_irq(struct omap_drm_irq *irq, uint32_t irqstatus)
{
struct omap_plane *omap_plane =
container_of(irq, struct omap_plane, error_irq);
DRM_ERROR("%s: errors: %08x\n", omap_plane->name, irqstatus);
}
struct drm_plane *omap_plane_init(struct drm_device *dev,
int id, bool private_plane)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_plane *plane = NULL;
struct omap_plane *omap_plane;
struct omap_overlay_info *info;
int ret;
DBG("%s: priv=%d", plane_names[id], private_plane);
omap_plane = kzalloc(sizeof(*omap_plane), GFP_KERNEL);
if (!omap_plane) {
dev_err(dev->dev, "could not allocate plane\n");
goto fail;
}
ret = kfifo_alloc(&omap_plane->unpin_fifo, 16, GFP_KERNEL);
if (ret) {
dev_err(dev->dev, "could not allocate unpin FIFO\n");
goto fail;
}
omap_plane->nformats = omap_framebuffer_get_formats(
omap_plane->formats, ARRAY_SIZE(omap_plane->formats),
dss_feat_get_supported_color_modes(id));
omap_plane->id = id;
omap_plane->name = plane_names[id];
plane = &omap_plane->base;
omap_plane->apply.pre_apply = omap_plane_pre_apply;
omap_plane->apply.post_apply = omap_plane_post_apply;
omap_plane->error_irq.irqmask = error_irqs[id];
omap_plane->error_irq.irq = omap_plane_error_irq;
omap_irq_register(dev, &omap_plane->error_irq);
drm_plane_init(dev, plane, (1 << priv->num_crtcs) - 1, &omap_plane_funcs,
omap_plane->formats, omap_plane->nformats, private_plane);
omap_plane_install_properties(plane, &plane->base);
info = &omap_plane->info;
info->rotation_type = OMAP_DSS_ROT_DMA;
info->rotation = OMAP_DSS_ROT_0;
info->global_alpha = 0xff;
info->mirror = 0;
if (private_plane)
omap_plane->info.zorder = 0;
else
omap_plane->info.zorder = id;
return plane;
fail:
if (plane)
omap_plane_destroy(plane);
return NULL;
}
