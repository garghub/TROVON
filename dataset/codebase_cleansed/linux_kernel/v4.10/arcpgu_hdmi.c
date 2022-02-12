int arcpgu_drm_hdmi_init(struct drm_device *drm, struct device_node *np)
{
struct drm_encoder *encoder;
struct drm_bridge *bridge;
int ret = 0;
encoder = devm_kzalloc(drm->dev, sizeof(*encoder), GFP_KERNEL);
if (encoder == NULL)
return -ENOMEM;
bridge = of_drm_find_bridge(np);
if (!bridge)
return -EPROBE_DEFER;
encoder->possible_crtcs = 1;
encoder->possible_clones = 0;
ret = drm_encoder_init(drm, encoder, &arcpgu_drm_encoder_funcs,
DRM_MODE_ENCODER_TMDS, NULL);
if (ret)
return ret;
bridge->encoder = encoder;
encoder->bridge = bridge;
ret = drm_bridge_attach(drm, bridge);
if (ret)
drm_encoder_cleanup(encoder);
return ret;
}
