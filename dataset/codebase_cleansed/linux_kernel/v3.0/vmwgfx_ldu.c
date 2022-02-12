static void vmw_ldu_destroy(struct vmw_legacy_display_unit *ldu)
{
list_del_init(&ldu->active);
vmw_display_unit_cleanup(&ldu->base);
kfree(ldu);
}
static void vmw_ldu_crtc_save(struct drm_crtc *crtc)
{
}
static void vmw_ldu_crtc_restore(struct drm_crtc *crtc)
{
}
static void vmw_ldu_crtc_gamma_set(struct drm_crtc *crtc,
u16 *r, u16 *g, u16 *b,
uint32_t start, uint32_t size)
{
}
static void vmw_ldu_crtc_destroy(struct drm_crtc *crtc)
{
vmw_ldu_destroy(vmw_crtc_to_ldu(crtc));
}
static int vmw_ldu_commit_list(struct vmw_private *dev_priv)
{
struct vmw_legacy_display *lds = dev_priv->ldu_priv;
struct vmw_legacy_display_unit *entry;
struct drm_framebuffer *fb = NULL;
struct drm_crtc *crtc = NULL;
int i = 0;
if (!(dev_priv->capabilities & SVGA_CAP_DISPLAY_TOPOLOGY)) {
int w = 0, h = 0;
list_for_each_entry(entry, &lds->active, active) {
crtc = &entry->base.crtc;
w = max(w, crtc->x + crtc->mode.hdisplay);
h = max(h, crtc->y + crtc->mode.vdisplay);
i++;
}
if (crtc == NULL)
return 0;
fb = entry->base.crtc.fb;
vmw_kms_write_svga(dev_priv, w, h, fb->pitch,
fb->bits_per_pixel, fb->depth);
return 0;
}
if (!list_empty(&lds->active)) {
entry = list_entry(lds->active.next, typeof(*entry), active);
fb = entry->base.crtc.fb;
vmw_kms_write_svga(dev_priv, fb->width, fb->height, fb->pitch,
fb->bits_per_pixel, fb->depth);
}
vmw_write(dev_priv, SVGA_REG_NUM_GUEST_DISPLAYS,
lds->num_active ? lds->num_active : 1);
i = 0;
list_for_each_entry(entry, &lds->active, active) {
crtc = &entry->base.crtc;
vmw_write(dev_priv, SVGA_REG_DISPLAY_ID, i);
vmw_write(dev_priv, SVGA_REG_DISPLAY_IS_PRIMARY, !i);
vmw_write(dev_priv, SVGA_REG_DISPLAY_POSITION_X, crtc->x);
vmw_write(dev_priv, SVGA_REG_DISPLAY_POSITION_Y, crtc->y);
vmw_write(dev_priv, SVGA_REG_DISPLAY_WIDTH, crtc->mode.hdisplay);
vmw_write(dev_priv, SVGA_REG_DISPLAY_HEIGHT, crtc->mode.vdisplay);
vmw_write(dev_priv, SVGA_REG_DISPLAY_ID, SVGA_ID_INVALID);
i++;
}
BUG_ON(i != lds->num_active);
lds->last_num_active = lds->num_active;
return 0;
}
static int vmw_ldu_del_active(struct vmw_private *vmw_priv,
struct vmw_legacy_display_unit *ldu)
{
struct vmw_legacy_display *ld = vmw_priv->ldu_priv;
if (list_empty(&ldu->active))
return 0;
list_del_init(&ldu->active);
if (--(ld->num_active) == 0) {
BUG_ON(!ld->fb);
if (ld->fb->unpin)
ld->fb->unpin(ld->fb);
ld->fb = NULL;
}
return 0;
}
static int vmw_ldu_add_active(struct vmw_private *vmw_priv,
struct vmw_legacy_display_unit *ldu,
struct vmw_framebuffer *vfb)
{
struct vmw_legacy_display *ld = vmw_priv->ldu_priv;
struct vmw_legacy_display_unit *entry;
struct list_head *at;
BUG_ON(!ld->num_active && ld->fb);
if (vfb != ld->fb) {
if (ld->fb && ld->fb->unpin)
ld->fb->unpin(ld->fb);
if (vfb->pin)
vfb->pin(vfb);
ld->fb = vfb;
}
if (!list_empty(&ldu->active))
return 0;
at = &ld->active;
list_for_each_entry(entry, &ld->active, active) {
if (entry->base.unit > ldu->base.unit)
break;
at = &entry->active;
}
list_add(&ldu->active, at);
ld->num_active++;
return 0;
}
static int vmw_ldu_crtc_set_config(struct drm_mode_set *set)
{
struct vmw_private *dev_priv;
struct vmw_legacy_display_unit *ldu;
struct drm_connector *connector;
struct drm_display_mode *mode;
struct drm_encoder *encoder;
struct vmw_framebuffer *vfb;
struct drm_framebuffer *fb;
struct drm_crtc *crtc;
if (!set)
return -EINVAL;
if (!set->crtc)
return -EINVAL;
crtc = set->crtc;
ldu = vmw_crtc_to_ldu(crtc);
vfb = set->fb ? vmw_framebuffer_to_vfb(set->fb) : NULL;
dev_priv = vmw_priv(crtc->dev);
if (set->num_connectors > 1) {
DRM_ERROR("to many connectors\n");
return -EINVAL;
}
if (set->num_connectors == 1 &&
set->connectors[0] != &ldu->base.connector) {
DRM_ERROR("connector doesn't match %p %p\n",
set->connectors[0], &ldu->base.connector);
return -EINVAL;
}
if (dev_priv->ldu_priv->fb && vfb &&
!(dev_priv->ldu_priv->num_active == 1 &&
!list_empty(&ldu->active)) &&
dev_priv->ldu_priv->fb != vfb) {
DRM_ERROR("Multiple framebuffers not supported\n");
return -EINVAL;
}
connector = &ldu->base.connector;
encoder = &ldu->base.encoder;
if (set->num_connectors == 0 || !set->mode || !set->fb) {
connector->encoder = NULL;
encoder->crtc = NULL;
crtc->fb = NULL;
vmw_ldu_del_active(dev_priv, ldu);
vmw_ldu_commit_list(dev_priv);
return 0;
}
mode = set->mode;
fb = set->fb;
if (set->x + mode->hdisplay > fb->width ||
set->y + mode->vdisplay > fb->height) {
DRM_ERROR("set outside of framebuffer\n");
return -EINVAL;
}
vmw_fb_off(dev_priv);
crtc->fb = fb;
encoder->crtc = crtc;
connector->encoder = encoder;
crtc->x = set->x;
crtc->y = set->y;
crtc->mode = *mode;
vmw_ldu_add_active(dev_priv, ldu, vfb);
vmw_ldu_commit_list(dev_priv);
return 0;
}
static void vmw_ldu_encoder_destroy(struct drm_encoder *encoder)
{
vmw_ldu_destroy(vmw_encoder_to_ldu(encoder));
}
static void vmw_ldu_connector_dpms(struct drm_connector *connector, int mode)
{
}
static void vmw_ldu_connector_save(struct drm_connector *connector)
{
}
static void vmw_ldu_connector_restore(struct drm_connector *connector)
{
}
static enum drm_connector_status
vmw_ldu_connector_detect(struct drm_connector *connector,
bool force)
{
if (vmw_connector_to_ldu(connector)->pref_active)
return connector_status_connected;
return connector_status_disconnected;
}
static int vmw_ldu_connector_fill_modes(struct drm_connector *connector,
uint32_t max_width, uint32_t max_height)
{
struct vmw_legacy_display_unit *ldu = vmw_connector_to_ldu(connector);
struct drm_device *dev = connector->dev;
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_display_mode *mode = NULL;
struct drm_display_mode prefmode = { DRM_MODE("preferred",
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
};
int i;
{
mode = drm_mode_duplicate(dev, &prefmode);
if (!mode)
return 0;
mode->hdisplay = ldu->pref_width;
mode->vdisplay = ldu->pref_height;
mode->vrefresh = drm_mode_vrefresh(mode);
if (vmw_kms_validate_mode_vram(dev_priv, mode->hdisplay * 2,
mode->vdisplay)) {
drm_mode_probed_add(connector, mode);
if (ldu->pref_mode) {
list_del_init(&ldu->pref_mode->head);
drm_mode_destroy(dev, ldu->pref_mode);
}
ldu->pref_mode = mode;
}
}
for (i = 0; vmw_ldu_connector_builtin[i].type != 0; i++) {
const struct drm_display_mode *bmode;
bmode = &vmw_ldu_connector_builtin[i];
if (bmode->hdisplay > max_width ||
bmode->vdisplay > max_height)
continue;
if (!vmw_kms_validate_mode_vram(dev_priv, bmode->hdisplay * 2,
bmode->vdisplay))
continue;
mode = drm_mode_duplicate(dev, bmode);
if (!mode)
return 0;
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_probed_add(connector, mode);
}
drm_mode_connector_list_update(connector);
return 1;
}
static int vmw_ldu_connector_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
return 0;
}
static void vmw_ldu_connector_destroy(struct drm_connector *connector)
{
vmw_ldu_destroy(vmw_connector_to_ldu(connector));
}
static int vmw_ldu_init(struct vmw_private *dev_priv, unsigned unit)
{
struct vmw_legacy_display_unit *ldu;
struct drm_device *dev = dev_priv->dev;
struct drm_connector *connector;
struct drm_encoder *encoder;
struct drm_crtc *crtc;
ldu = kzalloc(sizeof(*ldu), GFP_KERNEL);
if (!ldu)
return -ENOMEM;
ldu->base.unit = unit;
crtc = &ldu->base.crtc;
encoder = &ldu->base.encoder;
connector = &ldu->base.connector;
INIT_LIST_HEAD(&ldu->active);
ldu->pref_active = (unit == 0);
ldu->pref_width = 800;
ldu->pref_height = 600;
ldu->pref_mode = NULL;
drm_connector_init(dev, connector, &vmw_legacy_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
connector->status = vmw_ldu_connector_detect(connector, true);
drm_encoder_init(dev, encoder, &vmw_legacy_encoder_funcs,
DRM_MODE_ENCODER_LVDS);
drm_mode_connector_attach_encoder(connector, encoder);
encoder->possible_crtcs = (1 << unit);
encoder->possible_clones = 0;
drm_crtc_init(dev, crtc, &vmw_legacy_crtc_funcs);
drm_connector_attach_property(connector,
dev->mode_config.dirty_info_property,
1);
return 0;
}
int vmw_kms_init_legacy_display_system(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
int i;
int ret;
if (dev_priv->ldu_priv) {
DRM_INFO("ldu system already on\n");
return -EINVAL;
}
dev_priv->ldu_priv = kmalloc(sizeof(*dev_priv->ldu_priv), GFP_KERNEL);
if (!dev_priv->ldu_priv)
return -ENOMEM;
INIT_LIST_HEAD(&dev_priv->ldu_priv->active);
dev_priv->ldu_priv->num_active = 0;
dev_priv->ldu_priv->last_num_active = 0;
dev_priv->ldu_priv->fb = NULL;
drm_mode_create_dirty_info_property(dev_priv->dev);
if (dev_priv->capabilities & SVGA_CAP_MULTIMON) {
for (i = 0; i < VMWGFX_LDU_NUM_DU; ++i)
vmw_ldu_init(dev_priv, i);
ret = drm_vblank_init(dev, VMWGFX_LDU_NUM_DU);
} else {
vmw_ldu_init(dev_priv, 0);
ret = drm_vblank_init(dev, 1);
}
return ret;
}
int vmw_kms_close_legacy_display_system(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
drm_vblank_cleanup(dev);
if (!dev_priv->ldu_priv)
return -ENOSYS;
BUG_ON(!list_empty(&dev_priv->ldu_priv->active));
kfree(dev_priv->ldu_priv);
return 0;
}
int vmw_kms_ldu_update_layout(struct vmw_private *dev_priv, unsigned num,
struct drm_vmw_rect *rects)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_legacy_display_unit *ldu;
struct drm_connector *con;
int i;
mutex_lock(&dev->mode_config.mutex);
#if 0
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < (int)num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
#else
(void)i;
#endif
list_for_each_entry(con, &dev->mode_config.connector_list, head) {
ldu = vmw_connector_to_ldu(con);
if (num > ldu->base.unit) {
ldu->pref_width = rects[ldu->base.unit].w;
ldu->pref_height = rects[ldu->base.unit].h;
ldu->pref_active = true;
} else {
ldu->pref_width = 800;
ldu->pref_height = 600;
ldu->pref_active = false;
}
con->status = vmw_ldu_connector_detect(con, true);
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
