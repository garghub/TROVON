u32 r128_get_vblank_counter(struct drm_device *dev, int crtc)
{
const drm_r128_private_t *dev_priv = dev->dev_private;
if (crtc != 0)
return 0;
return atomic_read(&dev_priv->vbl_received);
}
irqreturn_t r128_driver_irq_handler(int irq, void *arg)
{
struct drm_device *dev = (struct drm_device *) arg;
drm_r128_private_t *dev_priv = (drm_r128_private_t *) dev->dev_private;
int status;
status = R128_READ(R128_GEN_INT_STATUS);
if (status & R128_CRTC_VBLANK_INT) {
R128_WRITE(R128_GEN_INT_STATUS, R128_CRTC_VBLANK_INT_AK);
atomic_inc(&dev_priv->vbl_received);
drm_handle_vblank(dev, 0);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
int r128_enable_vblank(struct drm_device *dev, int crtc)
{
drm_r128_private_t *dev_priv = dev->dev_private;
if (crtc != 0) {
DRM_ERROR("%s: bad crtc %d\n", __func__, crtc);
return -EINVAL;
}
R128_WRITE(R128_GEN_INT_CNTL, R128_CRTC_VBLANK_INT_EN);
return 0;
}
void r128_disable_vblank(struct drm_device *dev, int crtc)
{
if (crtc != 0)
DRM_ERROR("%s: bad crtc %d\n", __func__, crtc);
}
void r128_driver_irq_preinstall(struct drm_device *dev)
{
drm_r128_private_t *dev_priv = (drm_r128_private_t *) dev->dev_private;
R128_WRITE(R128_GEN_INT_CNTL, 0);
R128_WRITE(R128_GEN_INT_STATUS, R128_CRTC_VBLANK_INT_AK);
}
int r128_driver_irq_postinstall(struct drm_device *dev)
{
return 0;
}
void r128_driver_irq_uninstall(struct drm_device *dev)
{
drm_r128_private_t *dev_priv = (drm_r128_private_t *) dev->dev_private;
if (!dev_priv)
return;
R128_WRITE(R128_GEN_INT_CNTL, 0);
}
