static int fmc_check_version(unsigned long version, const char *name)
{
if (__FMC_MAJOR(version) != FMC_MAJOR) {
pr_err("%s: \"%s\" has wrong major (has %li, expected %i)\n",
__func__, name, __FMC_MAJOR(version), FMC_MAJOR);
return -EINVAL;
}
if (__FMC_MINOR(version) != FMC_MINOR)
pr_info("%s: \"%s\" has wrong minor (has %li, expected %i)\n",
__func__, name, __FMC_MINOR(version), FMC_MINOR);
return 0;
}
static int fmc_uevent(struct device *dev, struct kobj_uevent_env *env)
{
add_uevent_var(env, "MODALIAS=%s", "fmc");
return 0;
}
static int fmc_probe(struct device *dev)
{
struct fmc_driver *fdrv = to_fmc_driver(dev->driver);
struct fmc_device *fdev = to_fmc_device(dev);
return fdrv->probe(fdev);
}
static int fmc_remove(struct device *dev)
{
struct fmc_driver *fdrv = to_fmc_driver(dev->driver);
struct fmc_device *fdev = to_fmc_device(dev);
return fdrv->remove(fdev);
}
static void fmc_shutdown(struct device *dev)
{
}
static void fmc_release(struct device *dev)
{
struct fmc_device *fmc = container_of(dev, struct fmc_device, dev);
kfree(fmc);
}
static ssize_t fmc_read_eeprom(struct file *file, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev;
struct fmc_device *fmc;
int eelen;
dev = container_of(kobj, struct device, kobj);
fmc = container_of(dev, struct fmc_device, dev);
eelen = fmc->eeprom_len;
if (off > eelen)
return -ESPIPE;
if (off == eelen)
return 0;
if (off + count > eelen)
count = eelen - off;
memcpy(buf, fmc->eeprom + off, count);
return count;
}
static ssize_t fmc_write_eeprom(struct file *file, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct device *dev;
struct fmc_device *fmc;
dev = container_of(kobj, struct device, kobj);
fmc = container_of(dev, struct fmc_device, dev);
return fmc->op->write_ee(fmc, off, buf, count);
}
int fmc_irq_request(struct fmc_device *fmc, irq_handler_t h,
char *name, int flags)
{
if (fmc->op->irq_request)
return fmc->op->irq_request(fmc, h, name, flags);
return -EPERM;
}
void fmc_irq_free(struct fmc_device *fmc)
{
if (fmc->op->irq_free)
fmc->op->irq_free(fmc);
}
void fmc_irq_ack(struct fmc_device *fmc)
{
if (likely(fmc->op->irq_ack))
fmc->op->irq_ack(fmc);
}
int fmc_validate(struct fmc_device *fmc, struct fmc_driver *drv)
{
if (fmc->op->validate)
return fmc->op->validate(fmc, drv);
return -EPERM;
}
int fmc_gpio_config(struct fmc_device *fmc, struct fmc_gpio *gpio, int ngpio)
{
if (fmc->op->gpio_config)
return fmc->op->gpio_config(fmc, gpio, ngpio);
return -EPERM;
}
int fmc_read_ee(struct fmc_device *fmc, int pos, void *d, int l)
{
if (fmc->op->read_ee)
return fmc->op->read_ee(fmc, pos, d, l);
return -EPERM;
}
int fmc_write_ee(struct fmc_device *fmc, int pos, const void *d, int l)
{
if (fmc->op->write_ee)
return fmc->op->write_ee(fmc, pos, d, l);
return -EPERM;
}
int fmc_driver_register(struct fmc_driver *drv)
{
if (fmc_check_version(drv->version, drv->driver.name))
return -EINVAL;
drv->driver.bus = &fmc_bus_type;
return driver_register(&drv->driver);
}
void fmc_driver_unregister(struct fmc_driver *drv)
{
driver_unregister(&drv->driver);
}
int fmc_device_register_n_gw(struct fmc_device **devs, int n,
struct fmc_gateware *gw)
{
struct fmc_device *fmc, **devarray;
uint32_t device_id;
int i, ret = 0;
if (n < 1)
return 0;
if (fmc_check_version(devs[0]->version, devs[0]->carrier_name))
return -EINVAL;
devarray = kmemdup(devs, n * sizeof(*devs), GFP_KERNEL);
if (!devarray)
return -ENOMEM;
for (i = 0; i < n; i++) {
fmc = devarray[i];
if (!fmc->hwdev) {
pr_err("%s: device nr. %i has no hwdev pointer\n",
__func__, i);
ret = -EINVAL;
break;
}
if (fmc->flags & FMC_DEVICE_NO_MEZZANINE) {
dev_info(fmc->hwdev, "absent mezzanine in slot %d\n",
fmc->slot_id);
continue;
}
if (!fmc->eeprom) {
dev_err(fmc->hwdev, "no eeprom provided for slot %i\n",
fmc->slot_id);
ret = -EINVAL;
}
if (!fmc->eeprom_addr) {
dev_err(fmc->hwdev, "no eeprom_addr for slot %i\n",
fmc->slot_id);
ret = -EINVAL;
}
if (!fmc->carrier_name || !fmc->carrier_data ||
!fmc->device_id) {
dev_err(fmc->hwdev,
"deivce nr %i: carrier name, "
"data or dev_id not set\n", i);
ret = -EINVAL;
}
if (ret)
break;
}
if (ret) {
kfree(devarray);
return ret;
}
for (i = 0; i < n; i++) {
fmc = devarray[i];
fmc->nr_slots = n;
fmc->devarray = devarray;
device_initialize(&fmc->dev);
fmc->dev.release = fmc_release;
fmc->dev.parent = fmc->hwdev;
fmc_fill_id_info(fmc);
fmc->dev.bus = &fmc_bus_type;
device_id = fmc->device_id;
if (!fmc->mezzanine_name)
dev_set_name(&fmc->dev, "fmc-%04x", device_id);
else
dev_set_name(&fmc->dev, "%s-%04x", fmc->mezzanine_name,
device_id);
if (gw) {
ret = fmc->op->reprogram_raw(fmc, NULL,
gw->bitstream, gw->len);
if (ret) {
dev_warn(fmc->hwdev,
"Invalid gateware for FMC mezzanine\n");
goto out;
}
}
ret = device_add(&fmc->dev);
if (ret < 0) {
dev_err(fmc->hwdev, "Slot %i: Failed in registering "
"\"%s\"\n", fmc->slot_id, fmc->dev.kobj.name);
goto out;
}
ret = sysfs_create_bin_file(&fmc->dev.kobj, &fmc_eeprom_attr);
if (ret < 0) {
dev_err(&fmc->dev, "Failed in registering eeprom\n");
goto out1;
}
fmc_dump_eeprom(fmc);
fmc_debug_init(fmc);
}
return 0;
out1:
device_del(&fmc->dev);
out:
kfree(devarray);
for (i--; i >= 0; i--) {
fmc_debug_exit(devs[i]);
sysfs_remove_bin_file(&devs[i]->dev.kobj, &fmc_eeprom_attr);
device_del(&devs[i]->dev);
fmc_free_id_info(devs[i]);
put_device(&devs[i]->dev);
}
return ret;
}
int fmc_device_register_n(struct fmc_device **devs, int n)
{
return fmc_device_register_n_gw(devs, n, NULL);
}
int fmc_device_register_gw(struct fmc_device *fmc, struct fmc_gateware *gw)
{
return fmc_device_register_n_gw(&fmc, 1, gw);
}
int fmc_device_register(struct fmc_device *fmc)
{
return fmc_device_register_n(&fmc, 1);
}
void fmc_device_unregister_n(struct fmc_device **devs, int n)
{
int i;
if (n < 1)
return;
kfree(devs[0]->devarray);
for (i = 0; i < n; i++) {
fmc_debug_exit(devs[i]);
sysfs_remove_bin_file(&devs[i]->dev.kobj, &fmc_eeprom_attr);
device_del(&devs[i]->dev);
fmc_free_id_info(devs[i]);
put_device(&devs[i]->dev);
}
}
void fmc_device_unregister(struct fmc_device *fmc)
{
fmc_device_unregister_n(&fmc, 1);
}
static int fmc_init(void)
{
return bus_register(&fmc_bus_type);
}
static void fmc_exit(void)
{
bus_unregister(&fmc_bus_type);
}
