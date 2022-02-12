char *ide_media_string(ide_drive_t *drive)
{
switch (drive->media) {
case ide_disk:
return "disk";
case ide_cdrom:
return "cdrom";
case ide_tape:
return "tape";
case ide_floppy:
return "floppy";
case ide_optical:
return "optical";
default:
return "UNKNOWN";
}
}
static ssize_t media_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "%s\n", ide_media_string(drive));
}
static ssize_t drivename_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "%s\n", drive->name);
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "ide:m-%s\n", ide_media_string(drive));
}
static ssize_t model_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "%s\n", (char *)&drive->id[ATA_ID_PROD]);
}
static ssize_t firmware_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "%s\n", (char *)&drive->id[ATA_ID_FW_REV]);
}
static ssize_t serial_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
ide_drive_t *drive = to_ide_device(dev);
return sprintf(buf, "%s\n", (char *)&drive->id[ATA_ID_SERNO]);
}
static ssize_t store_delete_devices(struct device *portdev,
struct device_attribute *attr,
const char *buf, size_t n)
{
ide_hwif_t *hwif = dev_get_drvdata(portdev);
if (strncmp(buf, "1", n))
return -EINVAL;
ide_port_unregister_devices(hwif);
return n;
}
static ssize_t store_scan(struct device *portdev,
struct device_attribute *attr,
const char *buf, size_t n)
{
ide_hwif_t *hwif = dev_get_drvdata(portdev);
if (strncmp(buf, "1", n))
return -EINVAL;
ide_port_unregister_devices(hwif);
ide_port_scan(hwif);
return n;
}
int ide_sysfs_register_port(ide_hwif_t *hwif)
{
int i, uninitialized_var(rc);
for (i = 0; ide_port_attrs[i]; i++) {
rc = device_create_file(hwif->portdev, ide_port_attrs[i]);
if (rc)
break;
}
return rc;
}
