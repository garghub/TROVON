static ssize_t routes_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct rio_dev *rdev = to_rio_dev(dev);
char *str = buf;
int i;
for (i = 0; i < RIO_MAX_ROUTE_ENTRIES(rdev->net->hport->sys_size);
i++) {
if (rdev->rswitch->route_table[i] == RIO_INVALID_ROUTE)
continue;
str +=
sprintf(str, "%04x %02x\n", i,
rdev->rswitch->route_table[i]);
}
return (str - buf);
}
static ssize_t lprev_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rio_dev *rdev = to_rio_dev(dev);
return sprintf(buf, "%s\n",
(rdev->prev) ? rio_name(rdev->prev) : "root");
}
static ssize_t lnext_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rio_dev *rdev = to_rio_dev(dev);
char *str = buf;
int i;
if (rdev->pef & RIO_PEF_SWITCH) {
for (i = 0; i < RIO_GET_TOTAL_PORTS(rdev->swpinfo); i++) {
if (rdev->rswitch->nextdev[i])
str += sprintf(str, "%s\n",
rio_name(rdev->rswitch->nextdev[i]));
else
str += sprintf(str, "null\n");
}
}
return str - buf;
}
static ssize_t modalias_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct rio_dev *rdev = to_rio_dev(dev);
return sprintf(buf, "rapidio:v%04Xd%04Xav%04Xad%04X\n",
rdev->vid, rdev->did, rdev->asm_vid, rdev->asm_did);
}
static ssize_t
rio_read_config(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct rio_dev *dev =
to_rio_dev(container_of(kobj, struct device, kobj));
unsigned int size = 0x100;
loff_t init_off = off;
u8 *data = (u8 *) buf;
if (capable(CAP_SYS_ADMIN))
size = RIO_MAINT_SPACE_SZ;
if (off >= size)
return 0;
if (off + count > size) {
size -= off;
count = size;
} else {
size = count;
}
if ((off & 1) && size) {
u8 val;
rio_read_config_8(dev, off, &val);
data[off - init_off] = val;
off++;
size--;
}
if ((off & 3) && size > 2) {
u16 val;
rio_read_config_16(dev, off, &val);
data[off - init_off] = (val >> 8) & 0xff;
data[off - init_off + 1] = val & 0xff;
off += 2;
size -= 2;
}
while (size > 3) {
u32 val;
rio_read_config_32(dev, off, &val);
data[off - init_off] = (val >> 24) & 0xff;
data[off - init_off + 1] = (val >> 16) & 0xff;
data[off - init_off + 2] = (val >> 8) & 0xff;
data[off - init_off + 3] = val & 0xff;
off += 4;
size -= 4;
}
if (size >= 2) {
u16 val;
rio_read_config_16(dev, off, &val);
data[off - init_off] = (val >> 8) & 0xff;
data[off - init_off + 1] = val & 0xff;
off += 2;
size -= 2;
}
if (size > 0) {
u8 val;
rio_read_config_8(dev, off, &val);
data[off - init_off] = val;
off++;
--size;
}
return count;
}
static ssize_t
rio_write_config(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct rio_dev *dev =
to_rio_dev(container_of(kobj, struct device, kobj));
unsigned int size = count;
loff_t init_off = off;
u8 *data = (u8 *) buf;
if (off >= RIO_MAINT_SPACE_SZ)
return 0;
if (off + count > RIO_MAINT_SPACE_SZ) {
size = RIO_MAINT_SPACE_SZ - off;
count = size;
}
if ((off & 1) && size) {
rio_write_config_8(dev, off, data[off - init_off]);
off++;
size--;
}
if ((off & 3) && (size > 2)) {
u16 val = data[off - init_off + 1];
val |= (u16) data[off - init_off] << 8;
rio_write_config_16(dev, off, val);
off += 2;
size -= 2;
}
while (size > 3) {
u32 val = data[off - init_off + 3];
val |= (u32) data[off - init_off + 2] << 8;
val |= (u32) data[off - init_off + 1] << 16;
val |= (u32) data[off - init_off] << 24;
rio_write_config_32(dev, off, val);
off += 4;
size -= 4;
}
if (size >= 2) {
u16 val = data[off - init_off + 1];
val |= (u16) data[off - init_off] << 8;
rio_write_config_16(dev, off, val);
off += 2;
size -= 2;
}
if (size) {
rio_write_config_8(dev, off, data[off - init_off]);
off++;
--size;
}
return count;
}
int rio_create_sysfs_dev_files(struct rio_dev *rdev)
{
int err = 0;
err = device_create_bin_file(&rdev->dev, &rio_config_attr);
if (!err && (rdev->pef & RIO_PEF_SWITCH)) {
err |= device_create_file(&rdev->dev, &dev_attr_routes);
err |= device_create_file(&rdev->dev, &dev_attr_lnext);
err |= device_create_file(&rdev->dev, &dev_attr_hopcount);
}
if (err)
pr_warning("RIO: Failed to create attribute file(s) for %s\n",
rio_name(rdev));
return err;
}
void rio_remove_sysfs_dev_files(struct rio_dev *rdev)
{
device_remove_bin_file(&rdev->dev, &rio_config_attr);
if (rdev->pef & RIO_PEF_SWITCH) {
device_remove_file(&rdev->dev, &dev_attr_routes);
device_remove_file(&rdev->dev, &dev_attr_lnext);
device_remove_file(&rdev->dev, &dev_attr_hopcount);
}
}
static ssize_t bus_scan_store(struct bus_type *bus, const char *buf,
size_t count)
{
long val;
int rc;
if (kstrtol(buf, 0, &val) < 0)
return -EINVAL;
if (val == RIO_MPORT_ANY) {
rc = rio_init_mports();
goto exit;
}
if (val < 0 || val >= RIO_MAX_MPORTS)
return -EINVAL;
rc = rio_mport_scan((int)val);
exit:
if (!rc)
rc = count;
return rc;
}
