bool intel_ddc_probe(struct intel_encoder *intel_encoder, int ddc_bus)
{
struct drm_i915_private *dev_priv = intel_encoder->base.dev->dev_private;
u8 out_buf[] = { 0x0, 0x0};
u8 buf[2];
struct i2c_msg msgs[] = {
{
.addr = 0x50,
.flags = 0,
.len = 1,
.buf = out_buf,
},
{
.addr = 0x50,
.flags = I2C_M_RD,
.len = 1,
.buf = buf,
}
};
return i2c_transfer(&dev_priv->gmbus[ddc_bus].adapter, msgs, 2) == 2;
}
int intel_ddc_get_modes(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct edid *edid;
int ret = 0;
edid = drm_get_edid(connector, adapter);
if (edid) {
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
connector->display_info.raw_edid = NULL;
kfree(edid);
}
return ret;
}
void
intel_attach_force_audio_property(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_property *prop;
int i;
prop = dev_priv->force_audio_property;
if (prop == NULL) {
prop = drm_property_create(dev, DRM_MODE_PROP_ENUM,
"audio",
ARRAY_SIZE(force_audio_names));
if (prop == NULL)
return;
for (i = 0; i < ARRAY_SIZE(force_audio_names); i++)
drm_property_add_enum(prop, i, i-1, force_audio_names[i]);
dev_priv->force_audio_property = prop;
}
drm_connector_attach_property(connector, prop, 0);
}
void
intel_attach_broadcast_rgb_property(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_property *prop;
int i;
prop = dev_priv->broadcast_rgb_property;
if (prop == NULL) {
prop = drm_property_create(dev, DRM_MODE_PROP_ENUM,
"Broadcast RGB",
ARRAY_SIZE(broadcast_rgb_names));
if (prop == NULL)
return;
for (i = 0; i < ARRAY_SIZE(broadcast_rgb_names); i++)
drm_property_add_enum(prop, i, i, broadcast_rgb_names[i]);
dev_priv->broadcast_rgb_property = prop;
}
drm_connector_attach_property(connector, prop, 0);
}
