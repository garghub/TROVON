static void
nv04_display_store_initial_head_owner(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (dev_priv->chipset != 0x11) {
dev_priv->crtc_owner = NVReadVgaCrtc(dev, 0, NV_CIO_CRE_44);
return;
}
if (nvReadMC(dev, NV_PBUS_DEBUG_1) & (1 << 28))
dev_priv->crtc_owner = 0x4;
else {
uint8_t slaved_on_A, slaved_on_B;
bool tvA = false;
bool tvB = false;
slaved_on_B = NVReadVgaCrtc(dev, 1, NV_CIO_CRE_PIXEL_INDEX) &
0x80;
if (slaved_on_B)
tvB = !(NVReadVgaCrtc(dev, 1, NV_CIO_CRE_LCD__INDEX) &
MASK(NV_CIO_CRE_LCD_LCD_SELECT));
slaved_on_A = NVReadVgaCrtc(dev, 0, NV_CIO_CRE_PIXEL_INDEX) &
0x80;
if (slaved_on_A)
tvA = !(NVReadVgaCrtc(dev, 0, NV_CIO_CRE_LCD__INDEX) &
MASK(NV_CIO_CRE_LCD_LCD_SELECT));
if (slaved_on_A && !tvA)
dev_priv->crtc_owner = 0x0;
else if (slaved_on_B && !tvB)
dev_priv->crtc_owner = 0x3;
else if (slaved_on_A)
dev_priv->crtc_owner = 0x0;
else if (slaved_on_B)
dev_priv->crtc_owner = 0x3;
else
dev_priv->crtc_owner = 0x0;
}
}
int
nv04_display_early_init(struct drm_device *dev)
{
if (!nv_gf4_disp_arch(dev)) {
uint32_t pmc_enable = nv_rd32(dev, NV03_PMC_ENABLE);
if (!(pmc_enable & 1))
nv_wr32(dev, NV03_PMC_ENABLE, pmc_enable | 1);
}
NVLockVgaCrtcs(dev, false);
if (nv_two_heads(dev)) {
nv04_display_store_initial_head_owner(dev);
NVSetOwner(dev, 0);
}
NVWriteCRTC(dev, 0, NV_PCRTC_INTR_EN_0, 0);
if (nv_two_heads(dev))
NVWriteCRTC(dev, 1, NV_PCRTC_INTR_EN_0, 0);
return 0;
}
void
nv04_display_late_takedown(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (nv_two_heads(dev))
NVSetOwner(dev, dev_priv->crtc_owner);
NVLockVgaCrtcs(dev, true);
}
int
nv04_display_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct dcb_table *dcb = &dev_priv->vbios.dcb;
struct drm_connector *connector, *ct;
struct drm_encoder *encoder;
struct drm_crtc *crtc;
int i, ret;
NV_DEBUG_KMS(dev, "\n");
nouveau_hw_save_vga_fonts(dev, 1);
nv04_crtc_create(dev, 0);
if (nv_two_heads(dev))
nv04_crtc_create(dev, 1);
for (i = 0; i < dcb->entries; i++) {
struct dcb_entry *dcbent = &dcb->entry[i];
connector = nouveau_connector_create(dev, dcbent->connector);
if (IS_ERR(connector))
continue;
switch (dcbent->type) {
case OUTPUT_ANALOG:
ret = nv04_dac_create(connector, dcbent);
break;
case OUTPUT_LVDS:
case OUTPUT_TMDS:
ret = nv04_dfp_create(connector, dcbent);
break;
case OUTPUT_TV:
if (dcbent->location == DCB_LOC_ON_CHIP)
ret = nv17_tv_create(connector, dcbent);
else
ret = nv04_tv_create(connector, dcbent);
break;
default:
NV_WARN(dev, "DCB type %d not known\n", dcbent->type);
continue;
}
if (ret)
continue;
}
list_for_each_entry_safe(connector, ct,
&dev->mode_config.connector_list, head) {
if (!connector->encoder_ids[0]) {
NV_WARN(dev, "%s has no encoders, removing\n",
drm_get_connector_name(connector));
connector->funcs->destroy(connector);
}
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
crtc->funcs->save(crtc);
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct drm_encoder_helper_funcs *func = encoder->helper_private;
func->save(encoder);
}
nouveau_irq_register(dev, 24, nv04_vblank_crtc0_isr);
nouveau_irq_register(dev, 25, nv04_vblank_crtc1_isr);
return 0;
}
void
nv04_display_destroy(struct drm_device *dev)
{
struct drm_encoder *encoder;
struct drm_crtc *crtc;
NV_DEBUG_KMS(dev, "\n");
nouveau_irq_unregister(dev, 24);
nouveau_irq_unregister(dev, 25);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct drm_mode_set modeset = {
.crtc = crtc,
};
crtc->funcs->set_config(&modeset);
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct drm_encoder_helper_funcs *func = encoder->helper_private;
func->restore(encoder);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
crtc->funcs->restore(crtc);
nouveau_hw_save_vga_fonts(dev, 0);
}
int
nv04_display_init(struct drm_device *dev)
{
struct drm_encoder *encoder;
struct drm_crtc *crtc;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct drm_encoder_helper_funcs *func = encoder->helper_private;
func->restore(encoder);
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head)
crtc->funcs->restore(crtc);
return 0;
}
void
nv04_display_fini(struct drm_device *dev)
{
NVWriteCRTC(dev, 0, NV_PCRTC_INTR_EN_0, 0);
if (nv_two_heads(dev))
NVWriteCRTC(dev, 1, NV_PCRTC_INTR_EN_0, 0);
}
static void
nv04_vblank_crtc0_isr(struct drm_device *dev)
{
nv_wr32(dev, NV_CRTC0_INTSTAT, NV_CRTC_INTR_VBLANK);
drm_handle_vblank(dev, 0);
}
static void
nv04_vblank_crtc1_isr(struct drm_device *dev)
{
nv_wr32(dev, NV_CRTC1_INTSTAT, NV_CRTC_INTR_VBLANK);
drm_handle_vblank(dev, 1);
}
