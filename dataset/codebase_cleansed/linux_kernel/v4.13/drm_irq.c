int drm_irq_install(struct drm_device *dev, int irq)
{
int ret;
unsigned long sh_flags = 0;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return -EINVAL;
if (irq == 0)
return -EINVAL;
if (!dev->dev_private)
return -EINVAL;
if (dev->irq_enabled)
return -EBUSY;
dev->irq_enabled = true;
DRM_DEBUG("irq=%d\n", irq);
if (dev->driver->irq_preinstall)
dev->driver->irq_preinstall(dev);
if (drm_core_check_feature(dev, DRIVER_IRQ_SHARED))
sh_flags = IRQF_SHARED;
ret = request_irq(irq, dev->driver->irq_handler,
sh_flags, dev->driver->name, dev);
if (ret < 0) {
dev->irq_enabled = false;
return ret;
}
if (dev->driver->irq_postinstall)
ret = dev->driver->irq_postinstall(dev);
if (ret < 0) {
dev->irq_enabled = false;
if (drm_core_check_feature(dev, DRIVER_LEGACY))
vga_client_register(dev->pdev, NULL, NULL, NULL);
free_irq(irq, dev);
} else {
dev->irq = irq;
}
return ret;
}
int drm_irq_uninstall(struct drm_device *dev)
{
unsigned long irqflags;
bool irq_enabled;
int i;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return -EINVAL;
irq_enabled = dev->irq_enabled;
dev->irq_enabled = false;
if (dev->num_crtcs) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
for (i = 0; i < dev->num_crtcs; i++) {
struct drm_vblank_crtc *vblank = &dev->vblank[i];
if (!vblank->enabled)
continue;
WARN_ON(drm_core_check_feature(dev, DRIVER_MODESET));
drm_vblank_disable_and_save(dev, i);
wake_up(&vblank->queue);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
if (!irq_enabled)
return -EINVAL;
DRM_DEBUG("irq=%d\n", dev->irq);
if (drm_core_check_feature(dev, DRIVER_LEGACY))
vga_client_register(dev->pdev, NULL, NULL, NULL);
if (dev->driver->irq_uninstall)
dev->driver->irq_uninstall(dev);
free_irq(dev->irq, dev);
return 0;
}
int drm_legacy_irq_control(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_control *ctl = data;
int ret = 0, irq;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return 0;
if (!drm_core_check_feature(dev, DRIVER_LEGACY))
return 0;
if (WARN_ON(!dev->pdev))
return -EINVAL;
switch (ctl->func) {
case DRM_INST_HANDLER:
irq = dev->pdev->irq;
if (dev->if_version < DRM_IF_VERSION(1, 2) &&
ctl->irq != irq)
return -EINVAL;
mutex_lock(&dev->struct_mutex);
ret = drm_irq_install(dev, irq);
mutex_unlock(&dev->struct_mutex);
return ret;
case DRM_UNINST_HANDLER:
mutex_lock(&dev->struct_mutex);
ret = drm_irq_uninstall(dev);
mutex_unlock(&dev->struct_mutex);
return ret;
default:
return -EINVAL;
}
}
