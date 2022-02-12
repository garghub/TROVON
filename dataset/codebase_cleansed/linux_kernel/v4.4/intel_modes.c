int intel_connector_update_modes(struct drm_connector *connector,
struct edid *edid)
{
int ret;
drm_mode_connector_update_edid_property(connector, edid);
ret = drm_add_edid_modes(connector, edid);
drm_edid_to_eld(connector, edid);
return ret;
}
int intel_ddc_get_modes(struct drm_connector *connector,
struct i2c_adapter *adapter)
{
struct edid *edid;
int ret;
edid = drm_get_edid(connector, adapter);
if (!edid)
return 0;
ret = intel_connector_update_modes(connector, edid);
kfree(edid);
return ret;
}
void
intel_attach_force_audio_property(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_property *prop;
prop = dev_priv->force_audio_property;
if (prop == NULL) {
prop = drm_property_create_enum(dev, 0,
"audio",
force_audio_names,
ARRAY_SIZE(force_audio_names));
if (prop == NULL)
return;
dev_priv->force_audio_property = prop;
}
drm_object_attach_property(&connector->base, prop, 0);
}
void
intel_attach_broadcast_rgb_property(struct drm_connector *connector)
{
struct drm_device *dev = connector->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_property *prop;
prop = dev_priv->broadcast_rgb_property;
if (prop == NULL) {
prop = drm_property_create_enum(dev, DRM_MODE_PROP_ENUM,
"Broadcast RGB",
broadcast_rgb_names,
ARRAY_SIZE(broadcast_rgb_names));
if (prop == NULL)
return;
dev_priv->broadcast_rgb_property = prop;
}
drm_object_attach_property(&connector->base, prop, 0);
}
void
intel_attach_aspect_ratio_property(struct drm_connector *connector)
{
if (!drm_mode_create_aspect_ratio_property(connector->dev))
drm_object_attach_property(&connector->base,
connector->dev->mode_config.aspect_ratio_property,
DRM_MODE_PICTURE_ASPECT_NONE);
}
