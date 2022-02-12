static struct mdp5_kms *get_kms(struct drm_crtc *crtc)
{
struct msm_drm_private *priv = crtc->dev->dev_private;
return to_mdp5_kms(to_mdp_kms(priv->kms));
}
static void request_pending(struct drm_crtc *crtc, uint32_t pending)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
atomic_or(pending, &mdp5_crtc->pending);
mdp_irq_register(&get_kms(crtc)->base, &mdp5_crtc->vblank);
}
static void crtc_flush(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
int id = mdp5_crtc->id;
uint32_t i, flush = 0;
for (i = 0; i < ARRAY_SIZE(mdp5_crtc->planes); i++) {
struct drm_plane *plane = mdp5_crtc->planes[i];
if (plane) {
enum mdp5_pipe pipe = mdp5_plane_pipe(plane);
flush |= pipe2flush(pipe);
}
}
flush |= mixer2flush(mdp5_crtc->id);
flush |= MDP5_CTL_FLUSH_CTL;
DBG("%s: flush=%08x", mdp5_crtc->name, flush);
mdp5_write(mdp5_kms, REG_MDP5_CTL_FLUSH(id), flush);
}
static void update_fb(struct drm_crtc *crtc, struct drm_framebuffer *new_fb)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_framebuffer *old_fb = mdp5_crtc->fb;
drm_framebuffer_reference(new_fb);
mdp5_crtc->base.primary->fb = new_fb;
mdp5_crtc->fb = new_fb;
if (old_fb)
drm_flip_work_queue(&mdp5_crtc->unref_fb_work, old_fb);
}
static void update_scanout(struct drm_crtc *crtc, struct drm_framebuffer *fb)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
crtc_flush(crtc);
if (mdp5_crtc->scanout_fb)
drm_flip_work_queue(&mdp5_crtc->unref_fb_work,
mdp5_crtc->scanout_fb);
mdp5_crtc->scanout_fb = fb;
request_pending(crtc, PENDING_FLIP);
}
static void complete_flip(struct drm_crtc *crtc, struct drm_file *file)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct drm_pending_vblank_event *event;
unsigned long flags, i;
spin_lock_irqsave(&dev->event_lock, flags);
event = mdp5_crtc->event;
if (event) {
if (!file || (event->base.file_priv == file)) {
mdp5_crtc->event = NULL;
drm_send_vblank_event(dev, mdp5_crtc->id, event);
}
}
spin_unlock_irqrestore(&dev->event_lock, flags);
for (i = 0; i < ARRAY_SIZE(mdp5_crtc->planes); i++) {
struct drm_plane *plane = mdp5_crtc->planes[i];
if (plane)
mdp5_plane_complete_flip(plane);
}
}
static void pageflip_cb(struct msm_fence_cb *cb)
{
struct mdp5_crtc *mdp5_crtc =
container_of(cb, struct mdp5_crtc, pageflip_cb);
struct drm_crtc *crtc = &mdp5_crtc->base;
struct drm_framebuffer *fb = mdp5_crtc->fb;
if (!fb)
return;
drm_framebuffer_reference(fb);
mdp5_plane_set_scanout(mdp5_crtc->plane, fb);
update_scanout(crtc, fb);
}
static void unref_fb_worker(struct drm_flip_work *work, void *val)
{
struct mdp5_crtc *mdp5_crtc =
container_of(work, struct mdp5_crtc, unref_fb_work);
struct drm_device *dev = mdp5_crtc->base.dev;
mutex_lock(&dev->mode_config.mutex);
drm_framebuffer_unreference(val);
mutex_unlock(&dev->mode_config.mutex);
}
static void mdp5_crtc_destroy(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
mdp5_crtc->plane->funcs->destroy(mdp5_crtc->plane);
drm_crtc_cleanup(crtc);
drm_flip_work_cleanup(&mdp5_crtc->unref_fb_work);
kfree(mdp5_crtc);
}
static void mdp5_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
bool enabled = (mode == DRM_MODE_DPMS_ON);
DBG("%s: mode=%d", mdp5_crtc->name, mode);
if (enabled != mdp5_crtc->enabled) {
if (enabled) {
mdp5_enable(mdp5_kms);
mdp_irq_register(&mdp5_kms->base, &mdp5_crtc->err);
} else {
mdp_irq_unregister(&mdp5_kms->base, &mdp5_crtc->err);
mdp5_disable(mdp5_kms);
}
mdp5_crtc->enabled = enabled;
}
}
static bool mdp5_crtc_mode_fixup(struct drm_crtc *crtc,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void blend_setup(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
int id = mdp5_crtc->id;
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_COLOR_OUT(id),
MDP5_LM_BLEND_COLOR_OUT_STAGE0_FG_ALPHA);
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_OP_MODE(id, 0),
MDP5_LM_BLEND_OP_MODE_FG_ALPHA(FG_CONST) |
MDP5_LM_BLEND_OP_MODE_BG_ALPHA(FG_PIXEL) |
MDP5_LM_BLEND_OP_MODE_BG_INV_ALPHA);
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_FG_ALPHA(id, 0), 0xff);
mdp5_write(mdp5_kms, REG_MDP5_LM_BLEND_BG_ALPHA(id, 0), 0x00);
mdp5_write(mdp5_kms, REG_MDP5_CTL_LAYER_REG(id, 0),
MDP5_CTL_LAYER_REG_RGB0(STAGE0) |
MDP5_CTL_LAYER_REG_BORDER_COLOR);
mdp5_write(mdp5_kms, REG_MDP5_CTL_LAYER_REG(id, 1), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_LAYER_REG(id, 2), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_LAYER_REG(id, 3), 0);
mdp5_write(mdp5_kms, REG_MDP5_CTL_LAYER_REG(id, 4), 0);
}
static int mdp5_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
int ret;
mode = adjusted_mode;
DBG("%s: set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",
mdp5_crtc->name, mode->base.id, mode->name,
mode->vrefresh, mode->clock,
mode->hdisplay, mode->hsync_start,
mode->hsync_end, mode->htotal,
mode->vdisplay, mode->vsync_start,
mode->vsync_end, mode->vtotal,
mode->type, mode->flags);
drm_framebuffer_reference(crtc->primary->fb);
ret = mdp5_plane_mode_set(mdp5_crtc->plane, crtc, crtc->primary->fb,
0, 0, mode->hdisplay, mode->vdisplay,
x << 16, y << 16,
mode->hdisplay << 16, mode->vdisplay << 16);
if (ret) {
drm_framebuffer_unreference(crtc->primary->fb);
dev_err(crtc->dev->dev, "%s: failed to set mode on plane: %d\n",
mdp5_crtc->name, ret);
return ret;
}
mdp5_write(mdp5_kms, REG_MDP5_LM_OUT_SIZE(mdp5_crtc->id),
MDP5_LM_OUT_SIZE_WIDTH(mode->hdisplay) |
MDP5_LM_OUT_SIZE_HEIGHT(mode->vdisplay));
update_fb(crtc, crtc->primary->fb);
update_scanout(crtc, crtc->primary->fb);
return 0;
}
static void mdp5_crtc_prepare(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
DBG("%s", mdp5_crtc->name);
mdp5_enable(get_kms(crtc));
mdp5_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void mdp5_crtc_commit(struct drm_crtc *crtc)
{
mdp5_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
crtc_flush(crtc);
mdp5_disable(get_kms(crtc));
}
static int mdp5_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_plane *plane = mdp5_crtc->plane;
struct drm_display_mode *mode = &crtc->mode;
int ret;
drm_framebuffer_reference(crtc->primary->fb);
ret = mdp5_plane_mode_set(plane, crtc, crtc->primary->fb,
0, 0, mode->hdisplay, mode->vdisplay,
x << 16, y << 16,
mode->hdisplay << 16, mode->vdisplay << 16);
if (ret) {
drm_framebuffer_unreference(crtc->primary->fb);
return ret;
}
update_fb(crtc, crtc->primary->fb);
update_scanout(crtc, crtc->primary->fb);
return 0;
}
static void mdp5_crtc_load_lut(struct drm_crtc *crtc)
{
}
static int mdp5_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *new_fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct drm_gem_object *obj;
unsigned long flags;
if (mdp5_crtc->event) {
dev_err(dev->dev, "already pending flip!\n");
return -EBUSY;
}
obj = msm_framebuffer_bo(new_fb, 0);
spin_lock_irqsave(&dev->event_lock, flags);
mdp5_crtc->event = event;
spin_unlock_irqrestore(&dev->event_lock, flags);
update_fb(crtc, new_fb);
return msm_gem_queue_inactive_cb(obj, &mdp5_crtc->pageflip_cb);
}
static int mdp5_crtc_set_property(struct drm_crtc *crtc,
struct drm_property *property, uint64_t val)
{
return -EINVAL;
}
static void mdp5_crtc_vblank_irq(struct mdp_irq *irq, uint32_t irqstatus)
{
struct mdp5_crtc *mdp5_crtc = container_of(irq, struct mdp5_crtc, vblank);
struct drm_crtc *crtc = &mdp5_crtc->base;
struct msm_drm_private *priv = crtc->dev->dev_private;
unsigned pending;
mdp_irq_unregister(&get_kms(crtc)->base, &mdp5_crtc->vblank);
pending = atomic_xchg(&mdp5_crtc->pending, 0);
if (pending & PENDING_FLIP) {
complete_flip(crtc, NULL);
drm_flip_work_commit(&mdp5_crtc->unref_fb_work, priv->wq);
}
}
static void mdp5_crtc_err_irq(struct mdp_irq *irq, uint32_t irqstatus)
{
struct mdp5_crtc *mdp5_crtc = container_of(irq, struct mdp5_crtc, err);
struct drm_crtc *crtc = &mdp5_crtc->base;
DBG("%s: error: %08x", mdp5_crtc->name, irqstatus);
crtc_flush(crtc);
}
uint32_t mdp5_crtc_vblank(struct drm_crtc *crtc)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
return mdp5_crtc->vblank.irqmask;
}
void mdp5_crtc_cancel_pending_flip(struct drm_crtc *crtc, struct drm_file *file)
{
DBG("cancel: %p", file);
complete_flip(crtc, file);
}
void mdp5_crtc_set_intf(struct drm_crtc *crtc, int intf,
enum mdp5_intf intf_id)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
struct mdp5_kms *mdp5_kms = get_kms(crtc);
static const enum mdp5_intfnum intfnum[] = {
INTF0, INTF1, INTF2, INTF3,
};
uint32_t intf_sel;
mdp5_crtc->err.irqmask = intf2err(intf);
mdp5_crtc->vblank.irqmask = intf2vblank(intf);
if (!mdp5_kms)
return;
intf_sel = mdp5_read(mdp5_kms, REG_MDP5_DISP_INTF_SEL);
switch (intf) {
case 0:
intf_sel &= ~MDP5_DISP_INTF_SEL_INTF0__MASK;
intf_sel |= MDP5_DISP_INTF_SEL_INTF0(intf_id);
break;
case 1:
intf_sel &= ~MDP5_DISP_INTF_SEL_INTF1__MASK;
intf_sel |= MDP5_DISP_INTF_SEL_INTF1(intf_id);
break;
case 2:
intf_sel &= ~MDP5_DISP_INTF_SEL_INTF2__MASK;
intf_sel |= MDP5_DISP_INTF_SEL_INTF2(intf_id);
break;
case 3:
intf_sel &= ~MDP5_DISP_INTF_SEL_INTF3__MASK;
intf_sel |= MDP5_DISP_INTF_SEL_INTF3(intf_id);
break;
default:
BUG();
break;
}
blend_setup(crtc);
DBG("%s: intf_sel=%08x", mdp5_crtc->name, intf_sel);
mdp5_write(mdp5_kms, REG_MDP5_DISP_INTF_SEL, intf_sel);
mdp5_write(mdp5_kms, REG_MDP5_CTL_OP(mdp5_crtc->id),
MDP5_CTL_OP_MODE(MODE_NONE) |
MDP5_CTL_OP_INTF_NUM(intfnum[intf]));
crtc_flush(crtc);
}
static void set_attach(struct drm_crtc *crtc, enum mdp5_pipe pipe_id,
struct drm_plane *plane)
{
struct mdp5_crtc *mdp5_crtc = to_mdp5_crtc(crtc);
BUG_ON(pipe_id >= ARRAY_SIZE(mdp5_crtc->planes));
if (mdp5_crtc->planes[pipe_id] == plane)
return;
mdp5_crtc->planes[pipe_id] = plane;
blend_setup(crtc);
if (mdp5_crtc->enabled && (plane != mdp5_crtc->plane))
crtc_flush(crtc);
}
void mdp5_crtc_attach(struct drm_crtc *crtc, struct drm_plane *plane)
{
set_attach(crtc, mdp5_plane_pipe(plane), plane);
}
void mdp5_crtc_detach(struct drm_crtc *crtc, struct drm_plane *plane)
{
if (to_mdp5_crtc(crtc)->plane == plane)
return;
set_attach(crtc, mdp5_plane_pipe(plane), NULL);
}
struct drm_crtc *mdp5_crtc_init(struct drm_device *dev,
struct drm_plane *plane, int id)
{
struct drm_crtc *crtc = NULL;
struct mdp5_crtc *mdp5_crtc;
int ret;
mdp5_crtc = kzalloc(sizeof(*mdp5_crtc), GFP_KERNEL);
if (!mdp5_crtc) {
ret = -ENOMEM;
goto fail;
}
crtc = &mdp5_crtc->base;
mdp5_crtc->plane = plane;
mdp5_crtc->id = id;
mdp5_crtc->vblank.irq = mdp5_crtc_vblank_irq;
mdp5_crtc->err.irq = mdp5_crtc_err_irq;
snprintf(mdp5_crtc->name, sizeof(mdp5_crtc->name), "%s:%d",
pipe2name(mdp5_plane_pipe(plane)), id);
ret = drm_flip_work_init(&mdp5_crtc->unref_fb_work, 16,
"unref fb", unref_fb_worker);
if (ret)
goto fail;
INIT_FENCE_CB(&mdp5_crtc->pageflip_cb, pageflip_cb);
drm_crtc_init_with_planes(dev, crtc, plane, NULL, &mdp5_crtc_funcs);
drm_crtc_helper_add(crtc, &mdp5_crtc_helper_funcs);
mdp5_plane_install_properties(mdp5_crtc->plane, &crtc->base);
return crtc;
fail:
if (crtc)
mdp5_crtc_destroy(crtc);
return ERR_PTR(ret);
}
