static ssize_t serial_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zorro_dev *z;
z = to_zorro_dev(dev);
return sprintf(buf, "0x%08x\n", be32_to_cpu(z->rom.er_SerialNumber));
}
static ssize_t resource_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zorro_dev *z = to_zorro_dev(dev);
return sprintf(buf, "0x%08lx 0x%08lx 0x%08lx\n",
(unsigned long)zorro_resource_start(z),
(unsigned long)zorro_resource_end(z),
zorro_resource_flags(z));
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct zorro_dev *z = to_zorro_dev(dev);
return sprintf(buf, ZORRO_DEVICE_MODALIAS_FMT "\n", z->id);
}
static ssize_t zorro_read_config(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t off, size_t count)
{
struct zorro_dev *z = to_zorro_dev(kobj_to_dev(kobj));
struct ConfigDev cd;
memset(&cd, 0, sizeof(cd));
cd.cd_Rom = z->rom;
cd.cd_SlotAddr = cpu_to_be16(z->slotaddr);
cd.cd_SlotSize = cpu_to_be16(z->slotsize);
cd.cd_BoardAddr = cpu_to_be32(zorro_resource_start(z));
cd.cd_BoardSize = cpu_to_be32(zorro_resource_len(z));
return memory_read_from_buffer(buf, count, &off, &cd, sizeof(cd));
}
