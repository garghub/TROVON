void via_init_futex(drm_via_private_t *dev_priv)
{
unsigned int i;
DRM_DEBUG("\n");
for (i = 0; i < VIA_NR_XVMC_LOCKS; ++i) {
init_waitqueue_head(&(dev_priv->decoder_queue[i]));
XVMCLOCKPTR(dev_priv->sarea_priv, i)->lock = 0;
}
}
void via_cleanup_futex(drm_via_private_t *dev_priv)
{
}
void via_release_futex(drm_via_private_t *dev_priv, int context)
{
unsigned int i;
volatile int *lock;
if (!dev_priv->sarea_priv)
return;
for (i = 0; i < VIA_NR_XVMC_LOCKS; ++i) {
lock = (volatile int *)XVMCLOCKPTR(dev_priv->sarea_priv, i);
if ((_DRM_LOCKING_CONTEXT(*lock) == context)) {
if (_DRM_LOCK_IS_HELD(*lock)
&& (*lock & _DRM_LOCK_CONT)) {
wake_up(&(dev_priv->decoder_queue[i]));
}
*lock = 0;
}
}
}
int via_decoder_futex(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_futex_t *fx = data;
volatile int *lock;
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
drm_via_sarea_t *sAPriv = dev_priv->sarea_priv;
int ret = 0;
DRM_DEBUG("\n");
if (fx->lock >= VIA_NR_XVMC_LOCKS)
return -EFAULT;
lock = (volatile int *)XVMCLOCKPTR(sAPriv, fx->lock);
switch (fx->func) {
case VIA_FUTEX_WAIT:
DRM_WAIT_ON(ret, dev_priv->decoder_queue[fx->lock],
(fx->ms / 10) * (HZ / 100), *lock != fx->val);
return ret;
case VIA_FUTEX_WAKE:
wake_up(&(dev_priv->decoder_queue[fx->lock]));
return 0;
}
return 0;
}
