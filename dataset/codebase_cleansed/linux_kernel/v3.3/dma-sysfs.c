static ssize_t dma_show_devices(struct device *dev,
struct device_attribute *attr, char *buf)
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
static int __init dma_subsys_init(void)
{
int ret;
ret = subsys_system_register(&dma_subsys, NULL);
if (unlikely(ret))
return ret;
return device_create_file(dma_subsys.dev_root, &dev_attr_devices.attr);
}
static ssize_t dma_show_dev_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dma_channel *channel = to_dma_channel(dev);
return sprintf(buf, "%s\n", channel->dev_id);
}
static ssize_t dma_store_dev_id(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
strcpy(channel->dev_id, buf);
return count;
}
static ssize_t dma_store_config(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
unsigned long config;
config = simple_strtoul(buf, NULL, 0);
dma_configure_channel(channel->vchan, config);
return count;
}
static ssize_t dma_show_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dma_channel *channel = to_dma_channel(dev);
return sprintf(buf, "0x%08x\n", channel->mode);
}
static ssize_t dma_store_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct dma_channel *channel = to_dma_channel(dev);
channel->mode = simple_strtoul(buf, NULL, 0);
return count;
}
int dma_create_sysfs_files(struct dma_channel *chan, struct dma_info *info)
{
struct device *dev = &chan->dev;
char name[16];
int ret;
dev->id = chan->vchan;
dev->bus = &dma_subsys;
ret = device_register(dev);
if (ret)
return ret;
ret |= device_create_file(dev, &dev_attr_dev_id);
ret |= device_create_file(dev, &dev_attr_count);
ret |= device_create_file(dev, &dev_attr_mode);
ret |= device_create_file(dev, &dev_attr_flags);
ret |= device_create_file(dev, &dev_attr_config);
if (unlikely(ret)) {
dev_err(&info->pdev->dev, "Failed creating attrs\n");
return ret;
}
snprintf(name, sizeof(name), "dma%d", chan->chan);
return sysfs_create_link(&info->pdev->dev.kobj, &dev->kobj, name);
}
void dma_remove_sysfs_files(struct dma_channel *chan, struct dma_info *info)
{
struct device *dev = &chan->dev;
char name[16];
device_remove_file(dev, &dev_attr_dev_id);
device_remove_file(dev, &dev_attr_count);
device_remove_file(dev, &dev_attr_mode);
device_remove_file(dev, &dev_attr_flags);
device_remove_file(dev, &dev_attr_config);
snprintf(name, sizeof(name), "dma%d", chan->chan);
sysfs_remove_link(&info->pdev->dev.kobj, name);
device_unregister(dev);
}
