static int
qxl_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
if (pdev->revision < 4) {
DRM_ERROR("qxl too old, doesn't support client_monitors_config,"
" use xf86-video-qxl in user mode");
return -EINVAL;
}
return drm_get_pci_dev(pdev, ent, &qxl_driver);
}
static void
qxl_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int qxl_drm_freeze(struct drm_device *dev)
{
struct pci_dev *pdev = dev->pdev;
struct qxl_device *qdev = dev->dev_private;
struct drm_crtc *crtc;
drm_kms_helper_poll_disable(dev);
console_lock();
qxl_fbdev_set_suspend(qdev, 1);
console_unlock();
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
struct drm_crtc_helper_funcs *crtc_funcs = crtc->helper_private;
if (crtc->enabled)
(*crtc_funcs->disable)(crtc);
}
qxl_destroy_monitors_object(qdev);
qxl_surf_evict(qdev);
qxl_vram_evict(qdev);
while (!qxl_check_idle(qdev->command_ring));
while (!qxl_check_idle(qdev->release_ring))
qxl_queue_garbage_collect(qdev, 1);
pci_save_state(pdev);
return 0;
}
static int qxl_drm_resume(struct drm_device *dev, bool thaw)
{
struct qxl_device *qdev = dev->dev_private;
qdev->ram_header->int_mask = QXL_INTERRUPT_MASK;
if (!thaw) {
qxl_reinit_memslots(qdev);
qxl_ring_init_hdr(qdev->release_ring);
}
qxl_create_monitors_object(qdev);
drm_helper_resume_force_mode(dev);
console_lock();
qxl_fbdev_set_suspend(qdev, 0);
console_unlock();
drm_kms_helper_poll_enable(dev);
return 0;
}
static int qxl_pm_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
int error;
error = qxl_drm_freeze(drm_dev);
if (error)
return error;
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int qxl_pm_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if (pci_enable_device(pdev)) {
return -EIO;
}
return qxl_drm_resume(drm_dev, false);
}
static int qxl_pm_thaw(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return qxl_drm_resume(drm_dev, true);
}
static int qxl_pm_freeze(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
return qxl_drm_freeze(drm_dev);
}
static int qxl_pm_restore(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct drm_device *drm_dev = pci_get_drvdata(pdev);
struct qxl_device *qdev = drm_dev->dev_private;
qxl_io_reset(qdev);
return qxl_drm_resume(drm_dev, false);
}
static int __init qxl_init(void)
{
#ifdef CONFIG_VGA_CONSOLE
if (vgacon_text_force() && qxl_modeset == -1)
return -EINVAL;
#endif
if (qxl_modeset == 0)
return -EINVAL;
qxl_driver.num_ioctls = qxl_max_ioctls;
return drm_pci_init(&qxl_driver, &qxl_pci_driver);
}
static void __exit qxl_exit(void)
{
drm_pci_exit(&qxl_driver, &qxl_pci_driver);
}
