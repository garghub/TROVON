static int scsi_dev_type_suspend(struct device *dev, int (*cb)(struct device *))
{
int err;
err = scsi_device_quiesce(to_scsi_device(dev));
if (err == 0) {
if (cb) {
err = cb(dev);
if (err)
scsi_device_resume(to_scsi_device(dev));
}
}
dev_dbg(dev, "scsi suspend: %d\n", err);
return err;
}
static int scsi_dev_type_resume(struct device *dev, int (*cb)(struct device *))
{
int err = 0;
if (cb)
err = cb(dev);
scsi_device_resume(to_scsi_device(dev));
dev_dbg(dev, "scsi resume: %d\n", err);
return err;
}
static int
scsi_bus_suspend_common(struct device *dev, int (*cb)(struct device *))
{
int err = 0;
if (scsi_is_sdev_device(dev)) {
if (pm_runtime_suspended(dev))
return 0;
err = scsi_dev_type_suspend(dev, cb);
}
return err;
}
static int
scsi_bus_resume_common(struct device *dev, int (*cb)(struct device *))
{
int err = 0;
if (scsi_is_sdev_device(dev))
err = scsi_dev_type_resume(dev, cb);
if (err == 0) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
return err;
}
static int scsi_bus_prepare(struct device *dev)
{
if (scsi_is_sdev_device(dev)) {
async_synchronize_full_domain(&scsi_sd_probe_domain);
} else if (scsi_is_host_device(dev)) {
scsi_complete_async_scans();
}
return 0;
}
static int scsi_bus_suspend(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_suspend_common(dev, pm ? pm->suspend : NULL);
}
static int scsi_bus_resume(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_resume_common(dev, pm ? pm->resume : NULL);
}
static int scsi_bus_freeze(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_suspend_common(dev, pm ? pm->freeze : NULL);
}
static int scsi_bus_thaw(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_resume_common(dev, pm ? pm->thaw : NULL);
}
static int scsi_bus_poweroff(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_suspend_common(dev, pm ? pm->poweroff : NULL);
}
static int scsi_bus_restore(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
return scsi_bus_resume_common(dev, pm ? pm->restore : NULL);
}
static int sdev_runtime_suspend(struct device *dev)
{
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
struct scsi_device *sdev = to_scsi_device(dev);
int err;
err = blk_pre_runtime_suspend(sdev->request_queue);
if (err)
return err;
if (pm && pm->runtime_suspend)
err = pm->runtime_suspend(dev);
blk_post_runtime_suspend(sdev->request_queue, err);
return err;
}
static int scsi_runtime_suspend(struct device *dev)
{
int err = 0;
dev_dbg(dev, "scsi_runtime_suspend\n");
if (scsi_is_sdev_device(dev))
err = sdev_runtime_suspend(dev);
return err;
}
static int sdev_runtime_resume(struct device *dev)
{
struct scsi_device *sdev = to_scsi_device(dev);
const struct dev_pm_ops *pm = dev->driver ? dev->driver->pm : NULL;
int err = 0;
blk_pre_runtime_resume(sdev->request_queue);
if (pm && pm->runtime_resume)
err = pm->runtime_resume(dev);
blk_post_runtime_resume(sdev->request_queue, err);
return err;
}
static int scsi_runtime_resume(struct device *dev)
{
int err = 0;
dev_dbg(dev, "scsi_runtime_resume\n");
if (scsi_is_sdev_device(dev))
err = sdev_runtime_resume(dev);
return err;
}
static int scsi_runtime_idle(struct device *dev)
{
dev_dbg(dev, "scsi_runtime_idle\n");
if (scsi_is_sdev_device(dev)) {
pm_runtime_mark_last_busy(dev);
pm_runtime_autosuspend(dev);
return -EBUSY;
}
return 0;
}
int scsi_autopm_get_device(struct scsi_device *sdev)
{
int err;
err = pm_runtime_get_sync(&sdev->sdev_gendev);
if (err < 0 && err !=-EACCES)
pm_runtime_put_sync(&sdev->sdev_gendev);
else
err = 0;
return err;
}
void scsi_autopm_put_device(struct scsi_device *sdev)
{
pm_runtime_put_sync(&sdev->sdev_gendev);
}
void scsi_autopm_get_target(struct scsi_target *starget)
{
pm_runtime_get_sync(&starget->dev);
}
void scsi_autopm_put_target(struct scsi_target *starget)
{
pm_runtime_put_sync(&starget->dev);
}
int scsi_autopm_get_host(struct Scsi_Host *shost)
{
int err;
err = pm_runtime_get_sync(&shost->shost_gendev);
if (err < 0 && err !=-EACCES)
pm_runtime_put_sync(&shost->shost_gendev);
else
err = 0;
return err;
}
void scsi_autopm_put_host(struct Scsi_Host *shost)
{
pm_runtime_put_sync(&shost->shost_gendev);
}
