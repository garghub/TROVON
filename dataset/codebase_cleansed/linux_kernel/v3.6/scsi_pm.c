static int scsi_dev_type_suspend(struct device *dev, pm_message_t msg)
{
struct device_driver *drv;
int err;
err = scsi_device_quiesce(to_scsi_device(dev));
if (err == 0) {
drv = dev->driver;
if (drv && drv->suspend) {
err = drv->suspend(dev, msg);
if (err)
scsi_device_resume(to_scsi_device(dev));
}
}
dev_dbg(dev, "scsi suspend: %d\n", err);
return err;
}
static int scsi_dev_type_resume(struct device *dev)
{
struct device_driver *drv;
int err = 0;
drv = dev->driver;
if (drv && drv->resume)
err = drv->resume(dev);
scsi_device_resume(to_scsi_device(dev));
dev_dbg(dev, "scsi resume: %d\n", err);
return err;
}
static int scsi_bus_suspend_common(struct device *dev, pm_message_t msg)
{
int err = 0;
if (scsi_is_sdev_device(dev)) {
if (pm_runtime_suspended(dev)) {
if (msg.event == PM_EVENT_SUSPEND ||
msg.event == PM_EVENT_HIBERNATE)
return 0;
pm_runtime_resume(dev);
}
err = scsi_dev_type_suspend(dev, msg);
}
return err;
}
static int scsi_bus_resume_common(struct device *dev)
{
int err = 0;
pm_runtime_get_sync(dev->parent);
if (scsi_is_sdev_device(dev))
err = scsi_dev_type_resume(dev);
if (err == 0) {
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
}
pm_runtime_put_sync(dev->parent);
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
return scsi_bus_suspend_common(dev, PMSG_SUSPEND);
}
static int scsi_bus_freeze(struct device *dev)
{
return scsi_bus_suspend_common(dev, PMSG_FREEZE);
}
static int scsi_bus_poweroff(struct device *dev)
{
return scsi_bus_suspend_common(dev, PMSG_HIBERNATE);
}
static int scsi_runtime_suspend(struct device *dev)
{
int err = 0;
dev_dbg(dev, "scsi_runtime_suspend\n");
if (scsi_is_sdev_device(dev)) {
err = scsi_dev_type_suspend(dev, PMSG_AUTO_SUSPEND);
if (err == -EAGAIN)
pm_schedule_suspend(dev, jiffies_to_msecs(
round_jiffies_up_relative(HZ/10)));
}
return err;
}
static int scsi_runtime_resume(struct device *dev)
{
int err = 0;
dev_dbg(dev, "scsi_runtime_resume\n");
if (scsi_is_sdev_device(dev))
err = scsi_dev_type_resume(dev);
return err;
}
static int scsi_runtime_idle(struct device *dev)
{
int err;
dev_dbg(dev, "scsi_runtime_idle\n");
if (scsi_is_sdev_device(dev))
err = pm_schedule_suspend(dev, 100);
else
err = pm_runtime_suspend(dev);
return err;
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
