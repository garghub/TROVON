u32 mga_get_vblank_counter(struct drm_device *dev, int crtc)
{
const drm_mga_private_t *const dev_priv =
(drm_mga_private_t *) dev->dev_private;
if (crtc != 0)
return 0;
return atomic_read(&dev_priv->vbl_received);
}
irqreturn_t mga_driver_irq_handler(int irq, void *arg)
{
struct drm_device *dev = (struct drm_device *) arg;
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
int status;
int handled = 0;
status = MGA_READ(MGA_STATUS);
if (status & MGA_VLINEPEN) {
MGA_WRITE(MGA_ICLEAR, MGA_VLINEICLR);
atomic_inc(&dev_priv->vbl_received);
drm_handle_vblank(dev, 0);
handled = 1;
}
if (status & MGA_SOFTRAPEN) {
const u32 prim_start = MGA_READ(MGA_PRIMADDRESS);
const u32 prim_end = MGA_READ(MGA_PRIMEND);
MGA_WRITE(MGA_ICLEAR, MGA_SOFTRAPICLR);
if ((prim_start & ~0x03) != (prim_end & ~0x03))
MGA_WRITE(MGA_PRIMEND, prim_end);
atomic_inc(&dev_priv->last_fence_retired);
wake_up(&dev_priv->fence_queue);
handled = 1;
}
if (handled)
return IRQ_HANDLED;
return IRQ_NONE;
}
int mga_enable_vblank(struct drm_device *dev, int crtc)
{
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
if (crtc != 0) {
DRM_ERROR("tried to enable vblank on non-existent crtc %d\n",
crtc);
return 0;
}
MGA_WRITE(MGA_IEN, MGA_VLINEIEN | MGA_SOFTRAPEN);
return 0;
}
void mga_disable_vblank(struct drm_device *dev, int crtc)
{
if (crtc != 0) {
DRM_ERROR("tried to disable vblank on non-existent crtc %d\n",
crtc);
}
}
int mga_driver_fence_wait(struct drm_device *dev, unsigned int *sequence)
{
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
unsigned int cur_fence;
int ret = 0;
DRM_WAIT_ON(ret, dev_priv->fence_queue, 3 * HZ,
(((cur_fence = atomic_read(&dev_priv->last_fence_retired))
- *sequence) <= (1 << 23)));
*sequence = cur_fence;
return ret;
}
void mga_driver_irq_preinstall(struct drm_device *dev)
{
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
MGA_WRITE(MGA_IEN, 0);
MGA_WRITE(MGA_ICLEAR, ~0);
}
int mga_driver_irq_postinstall(struct drm_device *dev)
{
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
init_waitqueue_head(&dev_priv->fence_queue);
MGA_WRITE(MGA_IEN, MGA_SOFTRAPEN);
return 0;
}
void mga_driver_irq_uninstall(struct drm_device *dev)
{
drm_mga_private_t *dev_priv = (drm_mga_private_t *) dev->dev_private;
if (!dev_priv)
return;
MGA_WRITE(MGA_IEN, 0);
dev->irq_enabled = false;
}
