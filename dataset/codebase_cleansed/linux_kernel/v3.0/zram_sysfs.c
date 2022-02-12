static u64 zram_stat64_read(struct zram *zram, u64 *v)
{
u64 val;
spin_lock(&zram->stat64_lock);
val = *v;
spin_unlock(&zram->stat64_lock);
return val;
}
static struct zram *dev_to_zram(struct device *dev)
{
int i;
struct zram *zram = NULL;
for (i = 0; i < num_devices; i++) {
zram = &devices[i];
if (disk_to_dev(zram->disk) == dev)
break;
}
return zram;
}
static ssize_t disksize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n", zram->disksize);
}
static ssize_t disksize_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
int ret;
struct zram *zram = dev_to_zram(dev);
if (zram->init_done) {
pr_info("Cannot change disksize for initialized device\n");
return -EBUSY;
}
ret = strict_strtoull(buf, 10, &zram->disksize);
if (ret)
return ret;
zram->disksize = PAGE_ALIGN(zram->disksize);
set_capacity(zram->disk, zram->disksize >> SECTOR_SHIFT);
return len;
}
static ssize_t initstate_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%u\n", zram->init_done);
}
static ssize_t reset_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
int ret;
unsigned long do_reset;
struct zram *zram;
struct block_device *bdev;
zram = dev_to_zram(dev);
bdev = bdget_disk(zram->disk, 0);
if (bdev->bd_holders)
return -EBUSY;
ret = strict_strtoul(buf, 10, &do_reset);
if (ret)
return ret;
if (!do_reset)
return -EINVAL;
if (bdev)
fsync_bdev(bdev);
if (zram->init_done)
zram_reset_device(zram);
return len;
}
static ssize_t num_reads_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
zram_stat64_read(zram, &zram->stats.num_reads));
}
static ssize_t num_writes_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
zram_stat64_read(zram, &zram->stats.num_writes));
}
static ssize_t invalid_io_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
zram_stat64_read(zram, &zram->stats.invalid_io));
}
static ssize_t notify_free_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
zram_stat64_read(zram, &zram->stats.notify_free));
}
static ssize_t zero_pages_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%u\n", zram->stats.pages_zero);
}
static ssize_t orig_data_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
(u64)(zram->stats.pages_stored) << PAGE_SHIFT);
}
static ssize_t compr_data_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zram *zram = dev_to_zram(dev);
return sprintf(buf, "%llu\n",
zram_stat64_read(zram, &zram->stats.compr_size));
}
static ssize_t mem_used_total_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u64 val = 0;
struct zram *zram = dev_to_zram(dev);
if (zram->init_done) {
val = xv_get_total_size_bytes(zram->mem_pool) +
((u64)(zram->stats.pages_expand) << PAGE_SHIFT);
}
return sprintf(buf, "%llu\n", val);
}
