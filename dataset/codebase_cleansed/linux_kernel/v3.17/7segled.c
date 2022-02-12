void __init txx9_7segled_init(unsigned int num,
void (*putc)(unsigned int pos, unsigned char val))
{
tx_7segled_num = num;
tx_7segled_putc = putc;
}
int txx9_7segled_putc(unsigned int pos, char c)
{
if (pos >= tx_7segled_num)
return -EINVAL;
c = map_to_seg7(&txx9_seg7map, c);
if (c < 0)
return c;
tx_7segled_putc(pos, c);
return 0;
}
static ssize_t ascii_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned int ch = dev->id;
txx9_7segled_putc(ch, buf[0]);
return size;
}
static ssize_t raw_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
unsigned int ch = dev->id;
tx_7segled_putc(ch, buf[0]);
return size;
}
static ssize_t map_seg7_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
memcpy(buf, &txx9_seg7map, sizeof(txx9_seg7map));
return sizeof(txx9_seg7map);
}
static ssize_t map_seg7_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
if (size != sizeof(txx9_seg7map))
return -EINVAL;
memcpy(&txx9_seg7map, buf, size);
return size;
}
static void tx_7segled_release(struct device *dev)
{
kfree(dev);
}
static int __init tx_7segled_init_sysfs(void)
{
int error, i;
if (!tx_7segled_num)
return -ENODEV;
error = subsys_system_register(&tx_7segled_subsys, NULL);
if (error)
return error;
error = device_create_file(tx_7segled_subsys.dev_root, &dev_attr_map_seg7);
if (error)
return error;
for (i = 0; i < tx_7segled_num; i++) {
struct device *dev;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
error = -ENODEV;
break;
}
dev->id = i;
dev->bus = &tx_7segled_subsys;
dev->release = &tx_7segled_release;
error = device_register(dev);
if (error) {
put_device(dev);
return error;
}
device_create_file(dev, &dev_attr_ascii);
device_create_file(dev, &dev_attr_raw);
}
return error;
}
