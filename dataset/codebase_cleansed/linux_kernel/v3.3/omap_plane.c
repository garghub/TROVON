static int commit(struct drm_plane *plane)
{
struct drm_device *dev = plane->dev;
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_overlay *ovl = omap_plane->ovl;
struct omap_overlay_info *info = &omap_plane->info;
int ret;
DBG("%s", ovl->name);
DBG("%dx%d -> %dx%d (%d)", info->width, info->height, info->out_width,
info->out_height, info->screen_width);
DBG("%d,%d %08x %08x", info->pos_x, info->pos_y,
info->paddr, info->p_uv_addr);
ret = ovl->set_overlay_info(ovl, info);
if (ret) {
dev_err(dev->dev, "could not set overlay info\n");
return ret;
}
if (ovl->manager) {
ret = ovl->manager->apply(ovl->manager);
if (ret) {
dev_err(dev->dev, "could not apply settings\n");
return ret;
}
}
if (ovl->is_enabled(ovl)) {
omap_framebuffer_flush(plane->fb, info->pos_x, info->pos_y,
info->out_width, info->out_height);
}
return 0;
}
static void update_manager(struct drm_plane *plane)
{
struct omap_drm_private *priv = plane->dev->dev_private;
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_overlay *ovl = omap_plane->ovl;
struct omap_overlay_manager *mgr = NULL;
int i;
if (plane->crtc) {
for (i = 0; i < priv->num_encoders; i++) {
struct drm_encoder *encoder = priv->encoders[i];
if (encoder->crtc == plane->crtc) {
mgr = omap_encoder_get_manager(encoder);
break;
}
}
}
if (ovl->manager != mgr) {
bool enabled = ovl->is_enabled(ovl);
if (enabled)
omap_plane_dpms(plane, DRM_MODE_DPMS_OFF);
if (ovl->manager) {
DBG("disconnecting %s from %s", ovl->name,
ovl->manager->name);
ovl->unset_manager(ovl);
}
if (mgr) {
DBG("connecting %s to %s", ovl->name, mgr->name);
ovl->set_manager(ovl, mgr);
}
if (enabled && mgr)
omap_plane_dpms(plane, DRM_MODE_DPMS_ON);
}
}
static int update_pin(struct drm_plane *plane, struct drm_framebuffer *fb)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
int ret = 0;
if (omap_plane->pinned_fb != fb) {
if (omap_plane->pinned_fb)
omap_framebuffer_unpin(omap_plane->pinned_fb);
omap_plane->pinned_fb = fb;
if (fb)
ret = omap_framebuffer_pin(fb);
}
return ret;
}
static void update_scanout(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_overlay_info *info = &omap_plane->info;
int ret;
ret = update_pin(plane, plane->fb);
if (ret) {
dev_err(plane->dev->dev,
"could not pin fb: %d\n", ret);
omap_plane_dpms(plane, DRM_MODE_DPMS_OFF);
return;
}
omap_framebuffer_update_scanout(plane->fb,
omap_plane->src_x, omap_plane->src_y, info);
DBG("%s: %d,%d: %08x %08x (%d)", omap_plane->ovl->name,
omap_plane->src_x, omap_plane->src_y,
(u32)info->paddr, (u32)info->p_uv_addr,
info->screen_width);
}
int omap_plane_mode_set(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
src_x = src_x >> 16;
src_y = src_y >> 16;
src_w = src_w >> 16;
src_h = src_h >> 16;
omap_plane->info.pos_x = crtc_x;
omap_plane->info.pos_y = crtc_y;
omap_plane->info.out_width = crtc_w;
omap_plane->info.out_height = crtc_h;
omap_plane->info.width = src_w;
omap_plane->info.height = src_h;
omap_plane->src_x = src_x;
omap_plane->src_y = src_y;
plane->fb = fb;
plane->crtc = crtc;
update_scanout(plane);
update_manager(plane);
return 0;
}
static int omap_plane_update(struct drm_plane *plane,
struct drm_crtc *crtc, struct drm_framebuffer *fb,
int crtc_x, int crtc_y,
unsigned int crtc_w, unsigned int crtc_h,
uint32_t src_x, uint32_t src_y,
uint32_t src_w, uint32_t src_h)
{
omap_plane_mode_set(plane, crtc, fb, crtc_x, crtc_y, crtc_w, crtc_h,
src_x, src_y, src_w, src_h);
return omap_plane_dpms(plane, DRM_MODE_DPMS_ON);
}
static int omap_plane_disable(struct drm_plane *plane)
{
return omap_plane_dpms(plane, DRM_MODE_DPMS_OFF);
}
static void omap_plane_destroy(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
DBG("%s", omap_plane->ovl->name);
omap_plane_disable(plane);
drm_plane_cleanup(plane);
kfree(omap_plane);
}
int omap_plane_dpms(struct drm_plane *plane, int mode)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_overlay *ovl = omap_plane->ovl;
int r;
DBG("%s: %d", omap_plane->ovl->name, mode);
if (mode == DRM_MODE_DPMS_ON) {
update_scanout(plane);
r = commit(plane);
if (!r)
r = ovl->enable(ovl);
} else {
r = ovl->disable(ovl);
update_pin(plane, NULL);
}
return r;
}
struct drm_plane *omap_plane_init(struct drm_device *dev,
struct omap_overlay *ovl, unsigned int possible_crtcs,
bool priv)
{
struct drm_plane *plane = NULL;
struct omap_plane *omap_plane;
DBG("%s: possible_crtcs=%08x, priv=%d", ovl->name,
possible_crtcs, priv);
omap_plane = kzalloc(sizeof(*omap_plane), GFP_KERNEL);
if (!omap_plane) {
dev_err(dev->dev, "could not allocate plane\n");
goto fail;
}
omap_plane->ovl = ovl;
plane = &omap_plane->base;
drm_plane_init(dev, plane, possible_crtcs, &omap_plane_funcs,
formats, ARRAY_SIZE(formats), priv);
ovl->get_overlay_info(ovl, &omap_plane->info);
omap_plane->info.rotation_type = OMAP_DSS_ROT_DMA;
omap_plane->info.rotation = OMAP_DSS_ROT_0;
omap_plane->info.global_alpha = 0xff;
omap_plane->info.mirror = 0;
omap_plane->info.mirror = 0;
if (priv)
omap_plane->info.zorder = 0;
else
omap_plane->info.zorder = 1;
update_manager(plane);
return plane;
fail:
if (plane) {
omap_plane_destroy(plane);
}
return NULL;
}
