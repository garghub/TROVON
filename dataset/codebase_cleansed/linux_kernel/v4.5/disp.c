int
nv04_display_create(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_i2c *i2c = nvxx_i2c(&drm->device);
struct dcb_table *dcb = &drm->vbios.dcb;
struct drm_connector *connector, *ct;
struct drm_encoder *encoder;
struct nouveau_encoder *nv_encoder;
struct nouveau_crtc *crtc;
struct nv04_display *disp;
int i, ret;
disp = kzalloc(sizeof(*disp), GFP_KERNEL);
if (!disp)
return -ENOMEM;
nvif_object_map(&drm->device.object);
nouveau_display(dev)->priv = disp;
nouveau_display(dev)->dtor = nv04_display_destroy;
nouveau_display(dev)->init = nv04_display_init;
nouveau_display(dev)->fini = nv04_display_fini;
nouveau_hw_save_vga_fonts(dev, 1);
nv04_crtc_create(dev, 0);
if (nv_two_heads(dev))
nv04_crtc_create(dev, 1);
for (i = 0; i < dcb->entries; i++) {
struct dcb_output *dcbent = &dcb->entry[i];
connector = nouveau_connector_create(dev, dcbent->connector);
if (IS_ERR(connector))
continue;
switch (dcbent->type) {
case DCB_OUTPUT_ANALOG:
ret = nv04_dac_create(connector, dcbent);
break;
case DCB_OUTPUT_LVDS:
case DCB_OUTPUT_TMDS:
ret = nv04_dfp_create(connector, dcbent);
break;
case DCB_OUTPUT_TV:
if (dcbent->location == DCB_LOC_ON_CHIP)
ret = nv17_tv_create(connector, dcbent);
else
ret = nv04_tv_create(connector, dcbent);
break;
default:
NV_WARN(drm, "DCB type %d not known\n", dcbent->type);
continue;
}
if (ret)
continue;
}
list_for_each_entry_safe(connector, ct,
&dev->mode_config.connector_list, head) {
if (!connector->encoder_ids[0]) {
NV_WARN(drm, "%s has no encoders, removing\n",
connector->name);
connector->funcs->destroy(connector);
}
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
struct nouveau_encoder *nv_encoder = nouveau_encoder(encoder);
struct nvkm_i2c_bus *bus =
nvkm_i2c_bus_find(i2c, nv_encoder->dcb->i2c_index);
nv_encoder->i2c = bus ? &bus->i2c : NULL;
}
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head)
crtc->save(&crtc->base);
list_for_each_entry(nv_encoder, &dev->mode_config.encoder_list, base.base.head)
nv_encoder->enc_save(&nv_encoder->base.base);
nouveau_overlay_init(dev);
return 0;
}
void
nv04_display_destroy(struct drm_device *dev)
{
struct nv04_display *disp = nv04_display(dev);
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_encoder *encoder;
struct drm_crtc *crtc;
struct nouveau_crtc *nv_crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct drm_mode_set modeset = {
.crtc = crtc,
};
drm_mode_set_config_internal(&modeset);
}
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.base.head)
encoder->enc_restore(&encoder->base.base);
list_for_each_entry(nv_crtc, &dev->mode_config.crtc_list, base.head)
nv_crtc->restore(&nv_crtc->base);
nouveau_hw_save_vga_fonts(dev, 0);
nouveau_display(dev)->priv = NULL;
kfree(disp);
nvif_object_unmap(&drm->device.object);
}
int
nv04_display_init(struct drm_device *dev)
{
struct nouveau_encoder *encoder;
struct nouveau_crtc *crtc;
list_for_each_entry(crtc, &dev->mode_config.crtc_list, base.head)
crtc->save(&crtc->base);
list_for_each_entry(encoder, &dev->mode_config.encoder_list, base.base.head)
encoder->enc_save(&encoder->base.base);
return 0;
}
void
nv04_display_fini(struct drm_device *dev)
{
NVWriteCRTC(dev, 0, NV_PCRTC_INTR_EN_0, 0);
if (nv_two_heads(dev))
NVWriteCRTC(dev, 1, NV_PCRTC_INTR_EN_0, 0);
}
