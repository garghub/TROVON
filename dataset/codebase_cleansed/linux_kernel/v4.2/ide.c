int ide_device_get(ide_drive_t *drive)
{
struct device *host_dev;
struct module *module;
if (!get_device(&drive->gendev))
return -ENXIO;
host_dev = drive->hwif->host->dev[0];
module = host_dev ? host_dev->driver->owner : NULL;
if (module && !try_module_get(module)) {
put_device(&drive->gendev);
return -ENXIO;
}
return 0;
}
void ide_device_put(ide_drive_t *drive)
{
#ifdef CONFIG_MODULE_UNLOAD
struct device *host_dev = drive->hwif->host->dev[0];
struct module *module = host_dev ? host_dev->driver->owner : NULL;
module_put(module);
#endif
put_device(&drive->gendev);
}
static int ide_bus_match(struct device *dev, struct device_driver *drv)
{
return 1;
}
static int ide_uevent(struct device *dev, struct kobj_uevent_env *env)
{
ide_drive_t *drive = to_ide_device(dev);
add_uevent_var(env, "MEDIA=%s", ide_media_string(drive));
add_uevent_var(env, "DRIVENAME=%s", drive->name);
add_uevent_var(env, "MODALIAS=ide:m-%s", ide_media_string(drive));
return 0;
}
static int generic_ide_probe(struct device *dev)
{
ide_drive_t *drive = to_ide_device(dev);
struct ide_driver *drv = to_ide_driver(dev->driver);
return drv->probe ? drv->probe(drive) : -ENODEV;
}
static int generic_ide_remove(struct device *dev)
{
ide_drive_t *drive = to_ide_device(dev);
struct ide_driver *drv = to_ide_driver(dev->driver);
if (drv->remove)
drv->remove(drive);
return 0;
}
static void generic_ide_shutdown(struct device *dev)
{
ide_drive_t *drive = to_ide_device(dev);
struct ide_driver *drv = to_ide_driver(dev->driver);
if (dev->driver && drv->shutdown)
drv->shutdown(drive);
}
static int ide_set_dev_param_mask(const char *s, const struct kernel_param *kp)
{
int a, b, i, j = 1;
unsigned int *dev_param_mask = (unsigned int *)kp->arg;
if (sscanf(s, "%d.%d:%d", &a, &b, &j) != 3 &&
sscanf(s, "%d.%d", &a, &b) != 2)
return -EINVAL;
i = a * MAX_DRIVES + b;
if (i >= MAX_HWIFS * MAX_DRIVES || j < 0 || j > 1)
return -EINVAL;
if (j)
*dev_param_mask |= (1 << i);
else
*dev_param_mask &= ~(1 << i);
return 0;
}
static int ide_set_disk_chs(const char *str, struct kernel_param *kp)
{
int a, b, c = 0, h = 0, s = 0, i, j = 1;
if (sscanf(str, "%d.%d:%d,%d,%d", &a, &b, &c, &h, &s) != 5 &&
sscanf(str, "%d.%d:%d", &a, &b, &j) != 3)
return -EINVAL;
i = a * MAX_DRIVES + b;
if (i >= MAX_HWIFS * MAX_DRIVES || j < 0 || j > 1)
return -EINVAL;
if (c > INT_MAX || h > 255 || s > 255)
return -EINVAL;
if (j)
ide_disks |= (1 << i);
else
ide_disks &= ~(1 << i);
ide_disks_chs[i].cyl = c;
ide_disks_chs[i].head = h;
ide_disks_chs[i].sect = s;
return 0;
}
static void ide_dev_apply_params(ide_drive_t *drive, u8 unit)
{
int i = drive->hwif->index * MAX_DRIVES + unit;
if (ide_nodma & (1 << i)) {
printk(KERN_INFO "ide: disallowing DMA for %s\n", drive->name);
drive->dev_flags |= IDE_DFLAG_NODMA;
}
if (ide_noflush & (1 << i)) {
printk(KERN_INFO "ide: disabling flush requests for %s\n",
drive->name);
drive->dev_flags |= IDE_DFLAG_NOFLUSH;
}
if (ide_nohpa & (1 << i)) {
printk(KERN_INFO "ide: disabling Host Protected Area for %s\n",
drive->name);
drive->dev_flags |= IDE_DFLAG_NOHPA;
}
if (ide_noprobe & (1 << i)) {
printk(KERN_INFO "ide: skipping probe for %s\n", drive->name);
drive->dev_flags |= IDE_DFLAG_NOPROBE;
}
if (ide_nowerr & (1 << i)) {
printk(KERN_INFO "ide: ignoring the ATA_DF bit for %s\n",
drive->name);
drive->bad_wstat = BAD_R_STAT;
}
if (ide_cdroms & (1 << i)) {
printk(KERN_INFO "ide: forcing %s as a CD-ROM\n", drive->name);
drive->dev_flags |= IDE_DFLAG_PRESENT;
drive->media = ide_cdrom;
drive->ready_stat = 0;
}
if (ide_disks & (1 << i)) {
drive->cyl = drive->bios_cyl = ide_disks_chs[i].cyl;
drive->head = drive->bios_head = ide_disks_chs[i].head;
drive->sect = drive->bios_sect = ide_disks_chs[i].sect;
printk(KERN_INFO "ide: forcing %s as a disk (%d/%d/%d)\n",
drive->name,
drive->cyl, drive->head, drive->sect);
drive->dev_flags |= IDE_DFLAG_FORCED_GEOM | IDE_DFLAG_PRESENT;
drive->media = ide_disk;
drive->ready_stat = ATA_DRDY;
}
}
static int ide_set_ignore_cable(const char *s, struct kernel_param *kp)
{
int i, j = 1;
if (sscanf(s, "%d:%d", &i, &j) != 2 && sscanf(s, "%d", &i) != 1)
return -EINVAL;
if (i >= MAX_HWIFS || j < 0 || j > 1)
return -EINVAL;
if (j)
ide_ignore_cable |= (1 << i);
else
ide_ignore_cable &= ~(1 << i);
return 0;
}
void ide_port_apply_params(ide_hwif_t *hwif)
{
ide_drive_t *drive;
int i;
if (ide_ignore_cable & (1 << hwif->index)) {
printk(KERN_INFO "ide: ignoring cable detection for %s\n",
hwif->name);
hwif->cbl = ATA_CBL_PATA40_SHORT;
}
ide_port_for_each_dev(i, drive, hwif)
ide_dev_apply_params(drive, i);
}
static int __init ide_init(void)
{
int ret;
printk(KERN_INFO "Uniform Multi-Platform E-IDE driver\n");
ret = bus_register(&ide_bus_type);
if (ret < 0) {
printk(KERN_WARNING "IDE: bus_register error: %d\n", ret);
return ret;
}
ide_port_class = class_create(THIS_MODULE, "ide_port");
if (IS_ERR(ide_port_class)) {
ret = PTR_ERR(ide_port_class);
goto out_port_class;
}
ide_acpi_init();
proc_ide_create();
return 0;
out_port_class:
bus_unregister(&ide_bus_type);
return ret;
}
static void __exit ide_exit(void)
{
proc_ide_destroy();
class_destroy(ide_port_class);
bus_unregister(&ide_bus_type);
}
