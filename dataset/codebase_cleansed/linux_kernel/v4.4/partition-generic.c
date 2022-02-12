char *disk_name(struct gendisk *hd, int partno, char *buf)
{
if (!partno)
snprintf(buf, BDEVNAME_SIZE, "%s", hd->disk_name);
else if (isdigit(hd->disk_name[strlen(hd->disk_name)-1]))
snprintf(buf, BDEVNAME_SIZE, "%sp%d", hd->disk_name, partno);
else
snprintf(buf, BDEVNAME_SIZE, "%s%d", hd->disk_name, partno);
return buf;
}
const char *bdevname(struct block_device *bdev, char *buf)
{
return disk_name(bdev->bd_disk, bdev->bd_part->partno, buf);
}
const char *__bdevname(dev_t dev, char *buffer)
{
scnprintf(buffer, BDEVNAME_SIZE, "unknown-block(%u,%u)",
MAJOR(dev), MINOR(dev));
return buffer;
}
static ssize_t part_partition_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%d\n", p->partno);
}
static ssize_t part_start_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%llu\n",(unsigned long long)p->start_sect);
}
ssize_t part_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%llu\n",(unsigned long long)part_nr_sects_read(p));
}
static ssize_t part_ro_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%d\n", p->policy ? 1 : 0);
}
static ssize_t part_alignment_offset_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%llu\n", (unsigned long long)p->alignment_offset);
}
static ssize_t part_discard_alignment_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%u\n", p->discard_alignment);
}
ssize_t part_stat_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
int cpu;
cpu = part_stat_lock();
part_round_stats(cpu, p);
part_stat_unlock();
return sprintf(buf,
"%8lu %8lu %8llu %8u "
"%8lu %8lu %8llu %8u "
"%8u %8u %8u"
"\n",
part_stat_read(p, ios[READ]),
part_stat_read(p, merges[READ]),
(unsigned long long)part_stat_read(p, sectors[READ]),
jiffies_to_msecs(part_stat_read(p, ticks[READ])),
part_stat_read(p, ios[WRITE]),
part_stat_read(p, merges[WRITE]),
(unsigned long long)part_stat_read(p, sectors[WRITE]),
jiffies_to_msecs(part_stat_read(p, ticks[WRITE])),
part_in_flight(p),
jiffies_to_msecs(part_stat_read(p, io_ticks)),
jiffies_to_msecs(part_stat_read(p, time_in_queue)));
}
ssize_t part_inflight_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%8u %8u\n", atomic_read(&p->in_flight[0]),
atomic_read(&p->in_flight[1]));
}
ssize_t part_fail_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hd_struct *p = dev_to_part(dev);
return sprintf(buf, "%d\n", p->make_it_fail);
}
ssize_t part_fail_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct hd_struct *p = dev_to_part(dev);
int i;
if (count > 0 && sscanf(buf, "%d", &i) > 0)
p->make_it_fail = (i == 0) ? 0 : 1;
return count;
}
static void part_release(struct device *dev)
{
struct hd_struct *p = dev_to_part(dev);
blk_free_devt(dev->devt);
hd_free_part(p);
kfree(p);
}
static void delete_partition_rcu_cb(struct rcu_head *head)
{
struct hd_struct *part = container_of(head, struct hd_struct, rcu_head);
part->start_sect = 0;
part->nr_sects = 0;
part_stat_set_all(part, 0);
put_device(part_to_dev(part));
}
void __delete_partition(struct percpu_ref *ref)
{
struct hd_struct *part = container_of(ref, struct hd_struct, ref);
call_rcu(&part->rcu_head, delete_partition_rcu_cb);
}
void delete_partition(struct gendisk *disk, int partno)
{
struct disk_part_tbl *ptbl = disk->part_tbl;
struct hd_struct *part;
if (partno >= ptbl->len)
return;
part = ptbl->part[partno];
if (!part)
return;
rcu_assign_pointer(ptbl->part[partno], NULL);
rcu_assign_pointer(ptbl->last_lookup, NULL);
kobject_put(part->holder_dir);
device_del(part_to_dev(part));
hd_struct_kill(part);
}
static ssize_t whole_disk_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return 0;
}
struct hd_struct *add_partition(struct gendisk *disk, int partno,
sector_t start, sector_t len, int flags,
struct partition_meta_info *info)
{
struct hd_struct *p;
dev_t devt = MKDEV(0, 0);
struct device *ddev = disk_to_dev(disk);
struct device *pdev;
struct disk_part_tbl *ptbl;
const char *dname;
int err;
err = disk_expand_part_tbl(disk, partno);
if (err)
return ERR_PTR(err);
ptbl = disk->part_tbl;
if (ptbl->part[partno])
return ERR_PTR(-EBUSY);
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p)
return ERR_PTR(-EBUSY);
if (!init_part_stats(p)) {
err = -ENOMEM;
goto out_free;
}
seqcount_init(&p->nr_sects_seq);
pdev = part_to_dev(p);
p->start_sect = start;
p->alignment_offset =
queue_limit_alignment_offset(&disk->queue->limits, start);
p->discard_alignment =
queue_limit_discard_alignment(&disk->queue->limits, start);
p->nr_sects = len;
p->partno = partno;
p->policy = get_disk_ro(disk);
if (info) {
struct partition_meta_info *pinfo = alloc_part_info(disk);
if (!pinfo)
goto out_free_stats;
memcpy(pinfo, info, sizeof(*info));
p->info = pinfo;
}
dname = dev_name(ddev);
if (isdigit(dname[strlen(dname) - 1]))
dev_set_name(pdev, "%sp%d", dname, partno);
else
dev_set_name(pdev, "%s%d", dname, partno);
device_initialize(pdev);
pdev->class = &block_class;
pdev->type = &part_type;
pdev->parent = ddev;
err = blk_alloc_devt(p, &devt);
if (err)
goto out_free_info;
pdev->devt = devt;
dev_set_uevent_suppress(pdev, 1);
err = device_add(pdev);
if (err)
goto out_put;
err = -ENOMEM;
p->holder_dir = kobject_create_and_add("holders", &pdev->kobj);
if (!p->holder_dir)
goto out_del;
dev_set_uevent_suppress(pdev, 0);
if (flags & ADDPART_FLAG_WHOLEDISK) {
err = device_create_file(pdev, &dev_attr_whole_disk);
if (err)
goto out_del;
}
rcu_assign_pointer(ptbl->part[partno], p);
if (!dev_get_uevent_suppress(ddev))
kobject_uevent(&pdev->kobj, KOBJ_ADD);
if (!hd_ref_init(p))
return p;
out_free_info:
free_part_info(p);
out_free_stats:
free_part_stats(p);
out_free:
kfree(p);
return ERR_PTR(err);
out_del:
kobject_put(p->holder_dir);
device_del(pdev);
out_put:
put_device(pdev);
blk_free_devt(devt);
return ERR_PTR(err);
}
static bool disk_unlock_native_capacity(struct gendisk *disk)
{
const struct block_device_operations *bdops = disk->fops;
if (bdops->unlock_native_capacity &&
!(disk->flags & GENHD_FL_NATIVE_CAPACITY)) {
printk(KERN_CONT "enabling native capacity\n");
bdops->unlock_native_capacity(disk);
disk->flags |= GENHD_FL_NATIVE_CAPACITY;
return true;
} else {
printk(KERN_CONT "truncated\n");
return false;
}
}
static int drop_partitions(struct gendisk *disk, struct block_device *bdev)
{
struct disk_part_iter piter;
struct hd_struct *part;
int res;
if (bdev->bd_part_count || bdev->bd_super)
return -EBUSY;
res = invalidate_partition(disk, 0);
if (res)
return res;
disk_part_iter_init(&piter, disk, DISK_PITER_INCL_EMPTY);
while ((part = disk_part_iter_next(&piter)))
delete_partition(disk, part->partno);
disk_part_iter_exit(&piter);
return 0;
}
int rescan_partitions(struct gendisk *disk, struct block_device *bdev)
{
struct parsed_partitions *state = NULL;
struct hd_struct *part;
int p, highest, res;
rescan:
if (state && !IS_ERR(state)) {
free_partitions(state);
state = NULL;
}
res = drop_partitions(disk, bdev);
if (res)
return res;
if (disk->fops->revalidate_disk)
disk->fops->revalidate_disk(disk);
blk_integrity_revalidate(disk);
check_disk_size_change(disk, bdev);
bdev->bd_invalidated = 0;
if (!get_capacity(disk) || !(state = check_partition(disk, bdev)))
return 0;
if (IS_ERR(state)) {
if (PTR_ERR(state) == -ENOSPC) {
printk(KERN_WARNING "%s: partition table beyond EOD, ",
disk->disk_name);
if (disk_unlock_native_capacity(disk))
goto rescan;
}
return -EIO;
}
if (state->access_beyond_eod) {
printk(KERN_WARNING
"%s: partition table partially beyond EOD, ",
disk->disk_name);
if (disk_unlock_native_capacity(disk))
goto rescan;
}
kobject_uevent(&disk_to_dev(disk)->kobj, KOBJ_CHANGE);
for (p = 1, highest = 0; p < state->limit; p++)
if (state->parts[p].size)
highest = p;
disk_expand_part_tbl(disk, highest);
for (p = 1; p < state->limit; p++) {
sector_t size, from;
struct partition_meta_info *info = NULL;
size = state->parts[p].size;
if (!size)
continue;
from = state->parts[p].from;
if (from >= get_capacity(disk)) {
printk(KERN_WARNING
"%s: p%d start %llu is beyond EOD, ",
disk->disk_name, p, (unsigned long long) from);
if (disk_unlock_native_capacity(disk))
goto rescan;
continue;
}
if (from + size > get_capacity(disk)) {
printk(KERN_WARNING
"%s: p%d size %llu extends beyond EOD, ",
disk->disk_name, p, (unsigned long long) size);
if (disk_unlock_native_capacity(disk)) {
goto rescan;
} else {
size = get_capacity(disk) - from;
}
}
if (state->parts[p].has_info)
info = &state->parts[p].info;
part = add_partition(disk, p, from, size,
state->parts[p].flags,
&state->parts[p].info);
if (IS_ERR(part)) {
printk(KERN_ERR " %s: p%d could not be added: %ld\n",
disk->disk_name, p, -PTR_ERR(part));
continue;
}
#ifdef CONFIG_BLK_DEV_MD
if (state->parts[p].flags & ADDPART_FLAG_RAID)
md_autodetect_dev(part_to_dev(part)->devt);
#endif
}
free_partitions(state);
return 0;
}
int invalidate_partitions(struct gendisk *disk, struct block_device *bdev)
{
int res;
if (!bdev->bd_invalidated)
return 0;
res = drop_partitions(disk, bdev);
if (res)
return res;
set_capacity(disk, 0);
check_disk_size_change(disk, bdev);
bdev->bd_invalidated = 0;
kobject_uevent(&disk_to_dev(disk)->kobj, KOBJ_CHANGE);
return 0;
}
unsigned char *read_dev_sector(struct block_device *bdev, sector_t n, Sector *p)
{
struct address_space *mapping = bdev->bd_inode->i_mapping;
struct page *page;
page = read_mapping_page(mapping, (pgoff_t)(n >> (PAGE_CACHE_SHIFT-9)),
NULL);
if (!IS_ERR(page)) {
if (PageError(page))
goto fail;
p->v = page;
return (unsigned char *)page_address(page) + ((n & ((1 << (PAGE_CACHE_SHIFT - 9)) - 1)) << 9);
fail:
page_cache_release(page);
}
p->v = NULL;
return NULL;
}
