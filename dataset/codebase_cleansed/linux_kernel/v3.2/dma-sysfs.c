static ssize_t dma_show_devices(struct sys_device *dev,
struct sysdev_attribute *attr, char *buf)
{
ssize_t len = 0;
int i;
for (i = 0; i < MAX_DMA_CHANNELS; i++) {
struct dma_info *info = get_dma_info(i);
struct dma_channel *channel = get_dma_channel(i);
if (unlikely(!info) || !channel)
continue;
len += sprintf(buf + len, "%2d: %14s %s\n",
channel->chan, info->name,
channel->dev_id);
}
return len;
}
static int __init dma_sysclass_init(void)
{
int ret;
ret = sysdev_class_register(&dma_sysclass);
if (unlikely(ret))
return ret;
return sysfs_create_file(&dma_sysclass.kset.kobj, &attr_devices.attr);
}
static ssize_t dma_show_dev_id(struct sys_device *dev,
struct sysdev_attribute *attr, char *buf)
{
struct dma_channel *channel = to_dma_channel(dev);
return sprintf(buf, "%s\n", channel->dev_id);
}
static ssize_t dma_store_dev_id(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
strcpy(channel->dev_id, buf);
return count;
}
static ssize_t dma_store_config(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
unsigned long config;
config = simple_strtoul(buf, NULL, 0);
dma_configure_channel(channel->vchan, config);
return count;
}
static ssize_t dma_show_mode(struct sys_device *dev,
struct sysdev_attribute *attr, char *buf)
{
struct dma_channel *channel = to_dma_channel(dev);
return sprintf(buf, "0x%08x\n", channel->mode);
}
static ssize_t dma_store_mode(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
channel->mode = simple_strtoul(buf, NULL, 0);
return count;
}
int dma_create_sysfs_files(struct dma_channel *chan, struct dma_info *info)
{
struct sys_device *dev = &chan->dev;
char name[16];
int ret;
dev->id = chan->vchan;
dev->cls = &dma_sysclass;
ret = sysdev_register(dev);
if (ret)
return ret;
ret |= sysdev_create_file(dev, &attr_dev_id);
ret |= sysdev_create_file(dev, &attr_count);
ret |= sysdev_create_file(dev, &attr_mode);
ret |= sysdev_create_file(dev, &attr_flags);
ret |= sysdev_create_file(dev, &attr_config);
if (unlikely(ret)) {
dev_err(&info->pdev->dev, "Failed creating attrs\n");
return ret;
}
snprintf(name, sizeof(name), "dma%d", chan->chan);
return sysfs_create_link(&info->pdev->dev.kobj, &dev->kobj, name);
}
void dma_remove_sysfs_files(struct dma_channel *chan, struct dma_info *info)
{
struct sys_device *dev = &chan->dev;
char name[16];
sysdev_remove_file(dev, &attr_dev_id);
sysdev_remove_file(dev, &attr_count);
sysdev_remove_file(dev, &attr_mode);
sysdev_remove_file(dev, &attr_flags);
sysdev_remove_file(dev, &attr_config);
snprintf(name, sizeof(name), "dma%d", chan->chan);
sysfs_remove_link(&info->pdev->dev.kobj, name);
sysdev_unregister(dev);
}
