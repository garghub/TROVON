int gma_backlight_init(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
struct drm_psb_private *dev_priv = dev->dev_private;
return dev_priv->ops->backlight_init(dev);
#else
return 0;
#endif
}
void gma_backlight_exit(struct drm_device *dev)
{
#ifdef CONFIG_BACKLIGHT_CLASS_DEVICE
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->backlight_device) {
dev_priv->backlight_device->props.brightness = 0;
backlight_update_status(dev_priv->backlight_device);
backlight_device_unregister(dev_priv->backlight_device);
}
#endif
}
