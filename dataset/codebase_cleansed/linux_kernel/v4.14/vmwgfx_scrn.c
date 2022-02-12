static void vmw_sou_destroy(struct vmw_screen_object_unit *sou)
{
vmw_du_cleanup(&sou->base);
kfree(sou);
}
static void vmw_sou_crtc_destroy(struct drm_crtc *crtc)
{
vmw_sou_destroy(vmw_crtc_to_sou(crtc));
}
static int vmw_sou_fifo_create(struct vmw_private *dev_priv,
struct vmw_screen_object_unit *sou,
uint32_t x, uint32_t y,
struct drm_display_mode *mode)
{
size_t fifo_size;
struct {
struct {
uint32_t cmdType;
} header;
SVGAScreenObject obj;
} *cmd;
BUG_ON(!sou->buffer);
fifo_size = sizeof(*cmd);
cmd = vmw_fifo_reserve(dev_priv, fifo_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Fifo reserve failed.\n");
return -ENOMEM;
}
memset(cmd, 0, fifo_size);
cmd->header.cmdType = SVGA_CMD_DEFINE_SCREEN;
cmd->obj.structSize = sizeof(SVGAScreenObject);
cmd->obj.id = sou->base.unit;
cmd->obj.flags = SVGA_SCREEN_HAS_ROOT |
(sou->base.unit == 0 ? SVGA_SCREEN_IS_PRIMARY : 0);
cmd->obj.size.width = mode->hdisplay;
cmd->obj.size.height = mode->vdisplay;
if (sou->base.is_implicit) {
cmd->obj.root.x = x;
cmd->obj.root.y = y;
} else {
cmd->obj.root.x = sou->base.gui_x;
cmd->obj.root.y = sou->base.gui_y;
}
sou->base.set_gui_x = cmd->obj.root.x;
sou->base.set_gui_y = cmd->obj.root.y;
vmw_bo_get_guest_ptr(&sou->buffer->base, &cmd->obj.backingStore.ptr);
cmd->obj.backingStore.pitch = mode->hdisplay * 4;
vmw_fifo_commit(dev_priv, fifo_size);
sou->defined = true;
return 0;
}
static int vmw_sou_fifo_destroy(struct vmw_private *dev_priv,
struct vmw_screen_object_unit *sou)
{
size_t fifo_size;
int ret;
struct {
struct {
uint32_t cmdType;
} header;
SVGAFifoCmdDestroyScreen body;
} *cmd;
if (unlikely(!sou->defined))
return 0;
fifo_size = sizeof(*cmd);
cmd = vmw_fifo_reserve(dev_priv, fifo_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Fifo reserve failed.\n");
return -ENOMEM;
}
memset(cmd, 0, fifo_size);
cmd->header.cmdType = SVGA_CMD_DESTROY_SCREEN;
cmd->body.screenId = sou->base.unit;
vmw_fifo_commit(dev_priv, fifo_size);
ret = vmw_fallback_wait(dev_priv, false, true, 0, false, 3*HZ);
if (unlikely(ret != 0))
DRM_ERROR("Failed to sync with HW");
else
sou->defined = false;
return ret;
}
static void vmw_sou_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct vmw_private *dev_priv;
struct vmw_screen_object_unit *sou;
struct vmw_framebuffer *vfb;
struct drm_framebuffer *fb;
struct drm_plane_state *ps;
struct vmw_plane_state *vps;
int ret;
sou = vmw_crtc_to_sou(crtc);
dev_priv = vmw_priv(crtc->dev);
ps = crtc->primary->state;
fb = ps->fb;
vps = vmw_plane_state_to_vps(ps);
vfb = (fb) ? vmw_framebuffer_to_vfb(fb) : NULL;
if (sou->defined) {
ret = vmw_sou_fifo_destroy(dev_priv, sou);
if (ret) {
DRM_ERROR("Failed to destroy Screen Object\n");
return;
}
}
if (vfb) {
sou->buffer = vps->dmabuf;
sou->buffer_size = vps->dmabuf_size;
ret = vmw_sou_fifo_create(dev_priv, sou, crtc->x, crtc->y,
&crtc->mode);
if (ret)
DRM_ERROR("Failed to define Screen Object %dx%d\n",
crtc->x, crtc->y);
vmw_kms_add_active(dev_priv, &sou->base, vfb);
} else {
sou->buffer = NULL;
sou->buffer_size = 0;
vmw_kms_del_active(dev_priv, &sou->base);
}
}
static void vmw_sou_crtc_helper_prepare(struct drm_crtc *crtc)
{
}
static void vmw_sou_crtc_atomic_enable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
}
static void vmw_sou_crtc_atomic_disable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct vmw_private *dev_priv;
struct vmw_screen_object_unit *sou;
int ret;
if (!crtc) {
DRM_ERROR("CRTC is NULL\n");
return;
}
sou = vmw_crtc_to_sou(crtc);
dev_priv = vmw_priv(crtc->dev);
if (sou->defined) {
ret = vmw_sou_fifo_destroy(dev_priv, sou);
if (ret)
DRM_ERROR("Failed to destroy Screen Object\n");
}
}
static int vmw_sou_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *new_fb,
struct drm_pending_vblank_event *event,
uint32_t flags,
struct drm_modeset_acquire_ctx *ctx)
{
struct vmw_private *dev_priv = vmw_priv(crtc->dev);
struct drm_framebuffer *old_fb = crtc->primary->fb;
struct vmw_framebuffer *vfb = vmw_framebuffer_to_vfb(new_fb);
struct vmw_fence_obj *fence = NULL;
struct drm_vmw_rect vclips;
int ret;
if (!vmw_kms_crtc_flippable(dev_priv, crtc))
return -EINVAL;
flags &= ~DRM_MODE_PAGE_FLIP_ASYNC;
ret = drm_atomic_helper_page_flip(crtc, new_fb, NULL, flags, ctx);
if (ret) {
DRM_ERROR("Page flip error %d.\n", ret);
return ret;
}
vclips.x = crtc->x;
vclips.y = crtc->y;
vclips.w = crtc->mode.hdisplay;
vclips.h = crtc->mode.vdisplay;
if (vfb->dmabuf)
ret = vmw_kms_sou_do_dmabuf_dirty(dev_priv, vfb,
NULL, &vclips, 1, 1,
true, &fence);
else
ret = vmw_kms_sou_do_surface_dirty(dev_priv, vfb,
NULL, &vclips, NULL,
0, 0, 1, 1, &fence);
if (ret != 0)
goto out_no_fence;
if (!fence) {
ret = -EINVAL;
goto out_no_fence;
}
if (event) {
struct drm_file *file_priv = event->base.file_priv;
ret = vmw_event_fence_action_queue(file_priv, fence,
&event->base,
&event->event.tv_sec,
&event->event.tv_usec,
true);
}
vmw_fence_obj_unreference(&fence);
if (vmw_crtc_to_du(crtc)->is_implicit)
vmw_kms_update_implicit_fb(dev_priv, crtc);
return ret;
out_no_fence:
drm_atomic_set_fb_for_plane(crtc->primary->state, old_fb);
return ret;
}
static void vmw_sou_encoder_destroy(struct drm_encoder *encoder)
{
vmw_sou_destroy(vmw_encoder_to_sou(encoder));
}
static void vmw_sou_connector_destroy(struct drm_connector *connector)
{
vmw_sou_destroy(vmw_connector_to_sou(connector));
}
static void
vmw_sou_primary_plane_cleanup_fb(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct vmw_plane_state *vps = vmw_plane_state_to_vps(old_state);
vmw_dmabuf_unreference(&vps->dmabuf);
vps->dmabuf_size = 0;
vmw_du_plane_cleanup_fb(plane, old_state);
}
static int
vmw_sou_primary_plane_prepare_fb(struct drm_plane *plane,
struct drm_plane_state *new_state)
{
struct drm_framebuffer *new_fb = new_state->fb;
struct drm_crtc *crtc = plane->state->crtc ?: new_state->crtc;
struct vmw_plane_state *vps = vmw_plane_state_to_vps(new_state);
struct vmw_private *dev_priv;
size_t size;
int ret;
if (!new_fb) {
vmw_dmabuf_unreference(&vps->dmabuf);
vps->dmabuf_size = 0;
return 0;
}
size = new_state->crtc_w * new_state->crtc_h * 4;
if (vps->dmabuf) {
if (vps->dmabuf_size == size)
return 0;
vmw_dmabuf_unreference(&vps->dmabuf);
vps->dmabuf_size = 0;
}
vps->dmabuf = kzalloc(sizeof(*vps->dmabuf), GFP_KERNEL);
if (!vps->dmabuf)
return -ENOMEM;
dev_priv = vmw_priv(crtc->dev);
vmw_svga_enable(dev_priv);
vmw_overlay_pause_all(dev_priv);
ret = vmw_dmabuf_init(dev_priv, vps->dmabuf, size,
&vmw_vram_ne_placement,
false, &vmw_dmabuf_bo_free);
vmw_overlay_resume_all(dev_priv);
if (ret != 0)
vps->dmabuf = NULL;
else
vps->dmabuf_size = size;
return ret;
}
static void
vmw_sou_primary_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct drm_crtc *crtc = plane->state->crtc;
if (crtc)
crtc->primary->fb = plane->state->fb;
}
static int vmw_sou_init(struct vmw_private *dev_priv, unsigned unit)
{
struct vmw_screen_object_unit *sou;
struct drm_device *dev = dev_priv->dev;
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_plane *primary, *cursor;
struct drm_crtc *crtc;
int ret;
sou = kzalloc(sizeof(*sou), GFP_KERNEL);
if (!sou)
return -ENOMEM;
sou->base.unit = unit;
crtc = &sou->base.crtc;
encoder = &sou->base.encoder;
connector = &sou->base.connector;
primary = &sou->base.primary;
cursor = &sou->base.cursor;
sou->base.active_implicit = false;
sou->base.pref_active = (unit == 0);
sou->base.pref_width = dev_priv->initial_width;
sou->base.pref_height = dev_priv->initial_height;
sou->base.pref_mode = NULL;
sou->base.is_implicit = false;
vmw_du_plane_reset(primary);
ret = drm_universal_plane_init(dev, &sou->base.primary,
0, &vmw_sou_plane_funcs,
vmw_primary_plane_formats,
ARRAY_SIZE(vmw_primary_plane_formats),
NULL, DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret) {
DRM_ERROR("Failed to initialize primary plane");
goto err_free;
}
drm_plane_helper_add(primary, &vmw_sou_primary_plane_helper_funcs);
vmw_du_plane_reset(cursor);
ret = drm_universal_plane_init(dev, &sou->base.cursor,
0, &vmw_sou_cursor_funcs,
vmw_cursor_plane_formats,
ARRAY_SIZE(vmw_cursor_plane_formats),
NULL, DRM_PLANE_TYPE_CURSOR, NULL);
if (ret) {
DRM_ERROR("Failed to initialize cursor plane");
drm_plane_cleanup(&sou->base.primary);
goto err_free;
}
drm_plane_helper_add(cursor, &vmw_sou_cursor_plane_helper_funcs);
vmw_du_connector_reset(connector);
ret = drm_connector_init(dev, connector, &vmw_sou_connector_funcs,
DRM_MODE_CONNECTOR_VIRTUAL);
if (ret) {
DRM_ERROR("Failed to initialize connector\n");
goto err_free;
}
drm_connector_helper_add(connector, &vmw_sou_connector_helper_funcs);
connector->status = vmw_du_connector_detect(connector, true);
vmw_connector_state_to_vcs(connector->state)->is_implicit = false;
ret = drm_encoder_init(dev, encoder, &vmw_screen_object_encoder_funcs,
DRM_MODE_ENCODER_VIRTUAL, NULL);
if (ret) {
DRM_ERROR("Failed to initialize encoder\n");
goto err_free_connector;
}
(void) drm_mode_connector_attach_encoder(connector, encoder);
encoder->possible_crtcs = (1 << unit);
encoder->possible_clones = 0;
ret = drm_connector_register(connector);
if (ret) {
DRM_ERROR("Failed to register connector\n");
goto err_free_encoder;
}
vmw_du_crtc_reset(crtc);
ret = drm_crtc_init_with_planes(dev, crtc, &sou->base.primary,
&sou->base.cursor,
&vmw_screen_object_crtc_funcs, NULL);
if (ret) {
DRM_ERROR("Failed to initialize CRTC\n");
goto err_free_unregister;
}
drm_crtc_helper_add(crtc, &vmw_sou_crtc_helper_funcs);
drm_mode_crtc_set_gamma_size(crtc, 256);
drm_object_attach_property(&connector->base,
dev_priv->hotplug_mode_update_property, 1);
drm_object_attach_property(&connector->base,
dev->mode_config.suggested_x_property, 0);
drm_object_attach_property(&connector->base,
dev->mode_config.suggested_y_property, 0);
if (dev_priv->implicit_placement_property)
drm_object_attach_property
(&connector->base,
dev_priv->implicit_placement_property,
sou->base.is_implicit);
return 0;
err_free_unregister:
drm_connector_unregister(connector);
err_free_encoder:
drm_encoder_cleanup(encoder);
err_free_connector:
drm_connector_cleanup(connector);
err_free:
kfree(sou);
return ret;
}
int vmw_kms_sou_init_display(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
int i, ret;
if (!(dev_priv->capabilities & SVGA_CAP_SCREEN_OBJECT_2)) {
DRM_INFO("Not using screen objects,"
" missing cap SCREEN_OBJECT_2\n");
return -ENOSYS;
}
ret = -ENOMEM;
dev_priv->num_implicit = 0;
dev_priv->implicit_fb = NULL;
ret = drm_vblank_init(dev, VMWGFX_NUM_DISPLAY_UNITS);
if (unlikely(ret != 0))
return ret;
vmw_kms_create_implicit_placement_property(dev_priv, false);
for (i = 0; i < VMWGFX_NUM_DISPLAY_UNITS; ++i)
vmw_sou_init(dev_priv, i);
dev_priv->active_display_unit = vmw_du_screen_object;
DRM_INFO("Screen Objects Display Unit initialized\n");
return 0;
}
static int do_dmabuf_define_gmrfb(struct vmw_private *dev_priv,
struct vmw_framebuffer *framebuffer)
{
struct vmw_dma_buffer *buf =
container_of(framebuffer, struct vmw_framebuffer_dmabuf,
base)->buffer;
int depth = framebuffer->base.format->depth;
struct {
uint32_t header;
SVGAFifoCmdDefineGMRFB body;
} *cmd;
if (depth == 32)
depth = 24;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (!cmd) {
DRM_ERROR("Out of fifo space for dirty framebuffer command.\n");
return -ENOMEM;
}
cmd->header = SVGA_CMD_DEFINE_GMRFB;
cmd->body.format.bitsPerPixel = framebuffer->base.format->cpp[0] * 8;
cmd->body.format.colorDepth = depth;
cmd->body.format.reserved = 0;
cmd->body.bytesPerLine = framebuffer->base.pitches[0];
vmw_bo_get_guest_ptr(&buf->base, &cmd->body.ptr);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
}
static void vmw_sou_surface_fifo_commit(struct vmw_kms_dirty *dirty)
{
struct vmw_kms_sou_surface_dirty *sdirty =
container_of(dirty, typeof(*sdirty), base);
struct vmw_kms_sou_dirty_cmd *cmd = dirty->cmd;
s32 trans_x = dirty->unit->crtc.x - sdirty->dst_x;
s32 trans_y = dirty->unit->crtc.y - sdirty->dst_y;
size_t region_size = dirty->num_hits * sizeof(SVGASignedRect);
SVGASignedRect *blit = (SVGASignedRect *) &cmd[1];
int i;
if (!dirty->num_hits) {
vmw_fifo_commit(dirty->dev_priv, 0);
return;
}
cmd->header.id = SVGA_3D_CMD_BLIT_SURFACE_TO_SCREEN;
cmd->header.size = sizeof(cmd->body) + region_size;
cmd->body.destRect.left = sdirty->left;
cmd->body.destRect.right = sdirty->right;
cmd->body.destRect.top = sdirty->top;
cmd->body.destRect.bottom = sdirty->bottom;
cmd->body.srcRect.left = sdirty->left + trans_x;
cmd->body.srcRect.right = sdirty->right + trans_x;
cmd->body.srcRect.top = sdirty->top + trans_y;
cmd->body.srcRect.bottom = sdirty->bottom + trans_y;
cmd->body.srcImage.sid = sdirty->sid;
cmd->body.destScreenId = dirty->unit->unit;
for (i = 0; i < dirty->num_hits; ++i, ++blit) {
blit->left -= sdirty->left;
blit->right -= sdirty->left;
blit->top -= sdirty->top;
blit->bottom -= sdirty->top;
}
vmw_fifo_commit(dirty->dev_priv, region_size + sizeof(*cmd));
sdirty->left = sdirty->top = S32_MAX;
sdirty->right = sdirty->bottom = S32_MIN;
}
static void vmw_sou_surface_clip(struct vmw_kms_dirty *dirty)
{
struct vmw_kms_sou_surface_dirty *sdirty =
container_of(dirty, typeof(*sdirty), base);
struct vmw_kms_sou_dirty_cmd *cmd = dirty->cmd;
SVGASignedRect *blit = (SVGASignedRect *) &cmd[1];
blit += dirty->num_hits;
blit->left = dirty->unit_x1;
blit->top = dirty->unit_y1;
blit->right = dirty->unit_x2;
blit->bottom = dirty->unit_y2;
sdirty->left = min_t(s32, sdirty->left, dirty->unit_x1);
sdirty->top = min_t(s32, sdirty->top, dirty->unit_y1);
sdirty->right = max_t(s32, sdirty->right, dirty->unit_x2);
sdirty->bottom = max_t(s32, sdirty->bottom, dirty->unit_y2);
dirty->num_hits++;
}
int vmw_kms_sou_do_surface_dirty(struct vmw_private *dev_priv,
struct vmw_framebuffer *framebuffer,
struct drm_clip_rect *clips,
struct drm_vmw_rect *vclips,
struct vmw_resource *srf,
s32 dest_x,
s32 dest_y,
unsigned num_clips, int inc,
struct vmw_fence_obj **out_fence)
{
struct vmw_framebuffer_surface *vfbs =
container_of(framebuffer, typeof(*vfbs), base);
struct vmw_kms_sou_surface_dirty sdirty;
int ret;
if (!srf)
srf = &vfbs->surface->res;
ret = vmw_kms_helper_resource_prepare(srf, true);
if (ret)
return ret;
sdirty.base.fifo_commit = vmw_sou_surface_fifo_commit;
sdirty.base.clip = vmw_sou_surface_clip;
sdirty.base.dev_priv = dev_priv;
sdirty.base.fifo_reserve_size = sizeof(struct vmw_kms_sou_dirty_cmd) +
sizeof(SVGASignedRect) * num_clips;
sdirty.sid = srf->id;
sdirty.left = sdirty.top = S32_MAX;
sdirty.right = sdirty.bottom = S32_MIN;
sdirty.dst_x = dest_x;
sdirty.dst_y = dest_y;
ret = vmw_kms_helper_dirty(dev_priv, framebuffer, clips, vclips,
dest_x, dest_y, num_clips, inc,
&sdirty.base);
vmw_kms_helper_resource_finish(srf, out_fence);
return ret;
}
static void vmw_sou_dmabuf_fifo_commit(struct vmw_kms_dirty *dirty)
{
if (!dirty->num_hits) {
vmw_fifo_commit(dirty->dev_priv, 0);
return;
}
vmw_fifo_commit(dirty->dev_priv,
sizeof(struct vmw_kms_sou_dmabuf_blit) *
dirty->num_hits);
}
static void vmw_sou_dmabuf_clip(struct vmw_kms_dirty *dirty)
{
struct vmw_kms_sou_dmabuf_blit *blit = dirty->cmd;
blit += dirty->num_hits;
blit->header = SVGA_CMD_BLIT_GMRFB_TO_SCREEN;
blit->body.destScreenId = dirty->unit->unit;
blit->body.srcOrigin.x = dirty->fb_x;
blit->body.srcOrigin.y = dirty->fb_y;
blit->body.destRect.left = dirty->unit_x1;
blit->body.destRect.top = dirty->unit_y1;
blit->body.destRect.right = dirty->unit_x2;
blit->body.destRect.bottom = dirty->unit_y2;
dirty->num_hits++;
}
int vmw_kms_sou_do_dmabuf_dirty(struct vmw_private *dev_priv,
struct vmw_framebuffer *framebuffer,
struct drm_clip_rect *clips,
struct drm_vmw_rect *vclips,
unsigned num_clips, int increment,
bool interruptible,
struct vmw_fence_obj **out_fence)
{
struct vmw_dma_buffer *buf =
container_of(framebuffer, struct vmw_framebuffer_dmabuf,
base)->buffer;
struct vmw_kms_dirty dirty;
int ret;
ret = vmw_kms_helper_buffer_prepare(dev_priv, buf, interruptible,
false);
if (ret)
return ret;
ret = do_dmabuf_define_gmrfb(dev_priv, framebuffer);
if (unlikely(ret != 0))
goto out_revert;
dirty.fifo_commit = vmw_sou_dmabuf_fifo_commit;
dirty.clip = vmw_sou_dmabuf_clip;
dirty.fifo_reserve_size = sizeof(struct vmw_kms_sou_dmabuf_blit) *
num_clips;
ret = vmw_kms_helper_dirty(dev_priv, framebuffer, clips, vclips,
0, 0, num_clips, increment, &dirty);
vmw_kms_helper_buffer_finish(dev_priv, NULL, buf, out_fence, NULL);
return ret;
out_revert:
vmw_kms_helper_buffer_revert(buf);
return ret;
}
static void vmw_sou_readback_fifo_commit(struct vmw_kms_dirty *dirty)
{
if (!dirty->num_hits) {
vmw_fifo_commit(dirty->dev_priv, 0);
return;
}
vmw_fifo_commit(dirty->dev_priv,
sizeof(struct vmw_kms_sou_readback_blit) *
dirty->num_hits);
}
static void vmw_sou_readback_clip(struct vmw_kms_dirty *dirty)
{
struct vmw_kms_sou_readback_blit *blit = dirty->cmd;
blit += dirty->num_hits;
blit->header = SVGA_CMD_BLIT_SCREEN_TO_GMRFB;
blit->body.srcScreenId = dirty->unit->unit;
blit->body.destOrigin.x = dirty->fb_x;
blit->body.destOrigin.y = dirty->fb_y;
blit->body.srcRect.left = dirty->unit_x1;
blit->body.srcRect.top = dirty->unit_y1;
blit->body.srcRect.right = dirty->unit_x2;
blit->body.srcRect.bottom = dirty->unit_y2;
dirty->num_hits++;
}
int vmw_kms_sou_readback(struct vmw_private *dev_priv,
struct drm_file *file_priv,
struct vmw_framebuffer *vfb,
struct drm_vmw_fence_rep __user *user_fence_rep,
struct drm_vmw_rect *vclips,
uint32_t num_clips)
{
struct vmw_dma_buffer *buf =
container_of(vfb, struct vmw_framebuffer_dmabuf, base)->buffer;
struct vmw_kms_dirty dirty;
int ret;
ret = vmw_kms_helper_buffer_prepare(dev_priv, buf, true, false);
if (ret)
return ret;
ret = do_dmabuf_define_gmrfb(dev_priv, vfb);
if (unlikely(ret != 0))
goto out_revert;
dirty.fifo_commit = vmw_sou_readback_fifo_commit;
dirty.clip = vmw_sou_readback_clip;
dirty.fifo_reserve_size = sizeof(struct vmw_kms_sou_readback_blit) *
num_clips;
ret = vmw_kms_helper_dirty(dev_priv, vfb, NULL, vclips,
0, 0, num_clips, 1, &dirty);
vmw_kms_helper_buffer_finish(dev_priv, file_priv, buf, NULL,
user_fence_rep);
return ret;
out_revert:
vmw_kms_helper_buffer_revert(buf);
return ret;
}
