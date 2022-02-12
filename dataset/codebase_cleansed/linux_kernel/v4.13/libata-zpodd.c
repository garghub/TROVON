static int eject_tray(struct ata_device *dev)
{
struct ata_taskfile tf;
const char cdb[] = { GPCMD_START_STOP_UNIT,
0, 0, 0,
0x02,
0, 0, 0, 0, 0, 0, 0,
};
ata_tf_init(dev, &tf);
tf.flags = ATA_TFLAG_ISADDR | ATA_TFLAG_DEVICE;
tf.command = ATA_CMD_PACKET;
tf.protocol = ATAPI_PROT_NODATA;
return ata_exec_internal(dev, &tf, cdb, DMA_NONE, NULL, 0, 0);
}
static enum odd_mech_type zpodd_get_mech_type(struct ata_device *dev)
{
char buf[16];
unsigned int ret;
struct rm_feature_desc *desc = (void *)(buf + 8);
struct ata_taskfile tf;
char cdb[] = { GPCMD_GET_CONFIGURATION,
2,
0, 3,
0, 0, 0,
0, sizeof(buf),
0, 0, 0,
};
ata_tf_init(dev, &tf);
tf.flags = ATA_TFLAG_ISADDR | ATA_TFLAG_DEVICE;
tf.command = ATA_CMD_PACKET;
tf.protocol = ATAPI_PROT_PIO;
tf.lbam = sizeof(buf);
ret = ata_exec_internal(dev, &tf, cdb, DMA_FROM_DEVICE,
buf, sizeof(buf), 0);
if (ret)
return ODD_MECH_TYPE_UNSUPPORTED;
if (be16_to_cpu(desc->feature_code) != 3)
return ODD_MECH_TYPE_UNSUPPORTED;
if (desc->mech_type == 0 && desc->load == 0 && desc->eject == 1)
return ODD_MECH_TYPE_SLOT;
else if (desc->mech_type == 1 && desc->load == 0 && desc->eject == 1)
return ODD_MECH_TYPE_DRAWER;
else
return ODD_MECH_TYPE_UNSUPPORTED;
}
static bool zpready(struct ata_device *dev)
{
u8 sense_key, *sense_buf;
unsigned int ret, asc, ascq, add_len;
struct zpodd *zpodd = dev->zpodd;
ret = atapi_eh_tur(dev, &sense_key);
if (!ret || sense_key != NOT_READY)
return false;
sense_buf = dev->link->ap->sector_buf;
ret = atapi_eh_request_sense(dev, sense_buf, sense_key);
if (ret)
return false;
if ((sense_buf[0] & 0x7f) != 0x70)
return false;
add_len = sense_buf[7];
if (add_len < 6)
return false;
asc = sense_buf[12];
ascq = sense_buf[13];
if (zpodd->mech_type == ODD_MECH_TYPE_SLOT)
return asc == 0x3a;
else
return asc == 0x3a && ascq == 0x01;
}
void zpodd_on_suspend(struct ata_device *dev)
{
struct zpodd *zpodd = dev->zpodd;
unsigned long expires;
if (!zpready(dev)) {
zpodd->zp_sampled = false;
zpodd->zp_ready = false;
return;
}
if (!zpodd->zp_sampled) {
zpodd->zp_sampled = true;
zpodd->last_ready = jiffies;
return;
}
expires = zpodd->last_ready +
msecs_to_jiffies(zpodd_poweroff_delay * 1000);
if (time_before(jiffies, expires))
return;
zpodd->zp_ready = true;
}
bool zpodd_zpready(struct ata_device *dev)
{
struct zpodd *zpodd = dev->zpodd;
return zpodd->zp_ready;
}
void zpodd_enable_run_wake(struct ata_device *dev)
{
struct zpodd *zpodd = dev->zpodd;
sdev_disable_disk_events(dev->sdev);
zpodd->powered_off = true;
acpi_pm_set_device_wakeup(&dev->tdev, true);
}
void zpodd_disable_run_wake(struct ata_device *dev)
{
struct zpodd *zpodd = dev->zpodd;
if (zpodd->powered_off)
acpi_pm_set_device_wakeup(&dev->tdev, false);
}
void zpodd_post_poweron(struct ata_device *dev)
{
struct zpodd *zpodd = dev->zpodd;
if (!zpodd->powered_off)
return;
zpodd->powered_off = false;
if (zpodd->from_notify) {
zpodd->from_notify = false;
if (zpodd->mech_type == ODD_MECH_TYPE_DRAWER)
eject_tray(dev);
}
zpodd->zp_sampled = false;
zpodd->zp_ready = false;
sdev_enable_disk_events(dev->sdev);
}
static void zpodd_wake_dev(acpi_handle handle, u32 event, void *context)
{
struct ata_device *ata_dev = context;
struct zpodd *zpodd = ata_dev->zpodd;
struct device *dev = &ata_dev->sdev->sdev_gendev;
if (event == ACPI_NOTIFY_DEVICE_WAKE && pm_runtime_suspended(dev)) {
zpodd->from_notify = true;
pm_runtime_resume(dev);
}
}
static void ata_acpi_add_pm_notifier(struct ata_device *dev)
{
acpi_handle handle = ata_dev_acpi_handle(dev);
acpi_install_notify_handler(handle, ACPI_SYSTEM_NOTIFY,
zpodd_wake_dev, dev);
}
static void ata_acpi_remove_pm_notifier(struct ata_device *dev)
{
acpi_handle handle = ata_dev_acpi_handle(dev);
acpi_remove_notify_handler(handle, ACPI_SYSTEM_NOTIFY, zpodd_wake_dev);
}
void zpodd_init(struct ata_device *dev)
{
struct acpi_device *adev = ACPI_COMPANION(&dev->tdev);
enum odd_mech_type mech_type;
struct zpodd *zpodd;
if (dev->zpodd || !adev || !acpi_device_can_poweroff(adev))
return;
mech_type = zpodd_get_mech_type(dev);
if (mech_type == ODD_MECH_TYPE_UNSUPPORTED)
return;
zpodd = kzalloc(sizeof(struct zpodd), GFP_KERNEL);
if (!zpodd)
return;
zpodd->mech_type = mech_type;
ata_acpi_add_pm_notifier(dev);
zpodd->dev = dev;
dev->zpodd = zpodd;
dev_pm_qos_expose_flags(&dev->tdev, 0);
}
void zpodd_exit(struct ata_device *dev)
{
ata_acpi_remove_pm_notifier(dev);
kfree(dev->zpodd);
dev->zpodd = NULL;
}
