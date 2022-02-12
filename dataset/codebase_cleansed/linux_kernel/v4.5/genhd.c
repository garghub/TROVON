struct hd_struct *disk_get_part(struct gendisk *disk, int partno)
{
struct hd_struct *part = NULL;
struct disk_part_tbl *ptbl;
if (unlikely(partno < 0))
return NULL;
rcu_read_lock();
ptbl = rcu_dereference(disk->part_tbl);
if (likely(partno < ptbl->len)) {
part = rcu_dereference(ptbl->part[partno]);
if (part)
get_device(part_to_dev(part));
}
rcu_read_unlock();
return part;
}
void disk_part_iter_init(struct disk_part_iter *piter, struct gendisk *disk,
unsigned int flags)
{
struct disk_part_tbl *ptbl;
rcu_read_lock();
ptbl = rcu_dereference(disk->part_tbl);
piter->disk = disk;
piter->part = NULL;
if (flags & DISK_PITER_REVERSE)
piter->idx = ptbl->len - 1;
else if (flags & (DISK_PITER_INCL_PART0 | DISK_PITER_INCL_EMPTY_PART0))
piter->idx = 0;
else
piter->idx = 1;
piter->flags = flags;
rcu_read_unlock();
}
struct hd_struct *disk_part_iter_next(struct disk_part_iter *piter)
{
struct disk_part_tbl *ptbl;
int inc, end;
disk_put_part(piter->part);
piter->part = NULL;
rcu_read_lock();
ptbl = rcu_dereference(piter->disk->part_tbl);
if (piter->flags & DISK_PITER_REVERSE) {
inc = -1;
if (piter->flags & (DISK_PITER_INCL_PART0 |
DISK_PITER_INCL_EMPTY_PART0))
end = -1;
else
end = 0;
} else {
inc = 1;
end = ptbl->len;
}
for (; piter->idx != end; piter->idx += inc) {
struct hd_struct *part;
part = rcu_dereference(ptbl->part[piter->idx]);
if (!part)
continue;
if (!part_nr_sects_read(part) &&
!(piter->flags & DISK_PITER_INCL_EMPTY) &&
!(piter->flags & DISK_PITER_INCL_EMPTY_PART0 &&
piter->idx == 0))
continue;
get_device(part_to_dev(part));
piter->part = part;
piter->idx += inc;
break;
}
rcu_read_unlock();
return piter->part;
}
void disk_part_iter_exit(struct disk_part_iter *piter)
{
disk_put_part(piter->part);
piter->part = NULL;
}
static inline int sector_in_part(struct hd_struct *part, sector_t sector)
{
return part->start_sect <= sector &&
sector < part->start_sect + part_nr_sects_read(part);
}
struct hd_struct *disk_map_sector_rcu(struct gendisk *disk, sector_t sector)
{
struct disk_part_tbl *ptbl;
struct hd_struct *part;
int i;
ptbl = rcu_dereference(disk->part_tbl);
part = rcu_dereference(ptbl->last_lookup);
if (part && sector_in_part(part, sector))
return part;
for (i = 1; i < ptbl->len; i++) {
part = rcu_dereference(ptbl->part[i]);
if (part && sector_in_part(part, sector)) {
rcu_assign_pointer(ptbl->last_lookup, part);
return part;
}
}
return &disk->part0;
}
static inline int major_to_index(unsigned major)
{
return major % BLKDEV_MAJOR_HASH_SIZE;
}
void blkdev_show(struct seq_file *seqf, off_t offset)
{
struct blk_major_name *dp;
if (offset < BLKDEV_MAJOR_HASH_SIZE) {
mutex_lock(&block_class_lock);
for (dp = major_names[offset]; dp; dp = dp->next)
seq_printf(seqf, "%3d %s\n", dp->major, dp->name);
mutex_unlock(&block_class_lock);
}
}
int register_blkdev(unsigned int major, const char *name)
{
struct blk_major_name **n, *p;
int index, ret = 0;
mutex_lock(&block_class_lock);
if (major == 0) {
for (index = ARRAY_SIZE(major_names)-1; index > 0; index--) {
if (major_names[index] == NULL)
break;
}
if (index == 0) {
printk("register_blkdev: failed to get major for %s\n",
name);
ret = -EBUSY;
goto out;
}
major = index;
ret = major;
}
p = kmalloc(sizeof(struct blk_major_name), GFP_KERNEL);
if (p == NULL) {
ret = -ENOMEM;
goto out;
}
p->major = major;
strlcpy(p->name, name, sizeof(p->name));
p->next = NULL;
index = major_to_index(major);
for (n = &major_names[index]; *n; n = &(*n)->next) {
if ((*n)->major == major)
break;
}
if (!*n)
*n = p;
else
ret = -EBUSY;
if (ret < 0) {
printk("register_blkdev: cannot get major %d for %s\n",
major, name);
kfree(p);
}
out:
mutex_unlock(&block_class_lock);
return ret;
}
void unregister_blkdev(unsigned int major, const char *name)
{
struct blk_major_name **n;
struct blk_major_name *p = NULL;
int index = major_to_index(major);
mutex_lock(&block_class_lock);
for (n = &major_names[index]; *n; n = &(*n)->next)
if ((*n)->major == major)
break;
if (!*n || strcmp((*n)->name, name)) {
WARN_ON(1);
} else {
p = *n;
*n = p->next;
}
mutex_unlock(&block_class_lock);
kfree(p);
}
static int blk_mangle_minor(int minor)
{
#ifdef CONFIG_DEBUG_BLOCK_EXT_DEVT
int i;
for (i = 0; i < MINORBITS / 2; i++) {
int low = minor & (1 << i);
int high = minor & (1 << (MINORBITS - 1 - i));
int distance = MINORBITS - 1 - 2 * i;
minor ^= low | high;
low <<= distance;
high >>= distance;
minor |= low | high;
}
#endif
return minor;
}
int blk_alloc_devt(struct hd_struct *part, dev_t *devt)
{
struct gendisk *disk = part_to_disk(part);
int idx;
if (part->partno < disk->minors) {
*devt = MKDEV(disk->major, disk->first_minor + part->partno);
return 0;
}
idr_preload(GFP_KERNEL);
spin_lock_bh(&ext_devt_lock);
idx = idr_alloc(&ext_devt_idr, part, 0, NR_EXT_DEVT, GFP_NOWAIT);
spin_unlock_bh(&ext_devt_lock);
idr_preload_end();
if (idx < 0)
return idx == -ENOSPC ? -EBUSY : idx;
*devt = MKDEV(BLOCK_EXT_MAJOR, blk_mangle_minor(idx));
return 0;
}
void blk_free_devt(dev_t devt)
{
if (devt == MKDEV(0, 0))
return;
if (MAJOR(devt) == BLOCK_EXT_MAJOR) {
spin_lock_bh(&ext_devt_lock);
idr_remove(&ext_devt_idr, blk_mangle_minor(MINOR(devt)));
spin_unlock_bh(&ext_devt_lock);
}
}
static char *bdevt_str(dev_t devt, char *buf)
{
if (MAJOR(devt) <= 0xff && MINOR(devt) <= 0xff) {
char tbuf[BDEVT_SIZE];
snprintf(tbuf, BDEVT_SIZE, "%02x%02x", MAJOR(devt), MINOR(devt));
snprintf(buf, BDEVT_SIZE, "%-9s", tbuf);
} else
snprintf(buf, BDEVT_SIZE, "%03x:%05x", MAJOR(devt), MINOR(devt));
return buf;
}
void blk_unregister_region(dev_t devt, unsigned long range)
{
kobj_unmap(bdev_map, devt, range);
}
static struct kobject *exact_match(dev_t devt, int *partno, void *data)
{
struct gendisk *p = data;
return &disk_to_dev(p)->kobj;
}
static int exact_lock(dev_t devt, void *data)
{
struct gendisk *p = data;
if (!get_disk(p))
return -1;
return 0;
}
static void register_disk(struct gendisk *disk)
{
struct device *ddev = disk_to_dev(disk);
struct block_device *bdev;
struct disk_part_iter piter;
struct hd_struct *part;
int err;
ddev->parent = disk->driverfs_dev;
dev_set_name(ddev, "%s", disk->disk_name);
dev_set_uevent_suppress(ddev, 1);
if (device_add(ddev))
return;
if (!sysfs_deprecated) {
err = sysfs_create_link(block_depr, &ddev->kobj,
kobject_name(&ddev->kobj));
if (err) {
device_del(ddev);
return;
}
}
pm_runtime_set_memalloc_noio(ddev, true);
disk->part0.holder_dir = kobject_create_and_add("holders", &ddev->kobj);
disk->slave_dir = kobject_create_and_add("slaves", &ddev->kobj);
if (!disk_part_scan_enabled(disk))
goto exit;
if (!get_capacity(disk))
goto exit;
bdev = bdget_disk(disk, 0);
if (!bdev)
goto exit;
bdev->bd_invalidated = 1;
err = blkdev_get(bdev, FMODE_READ, NULL);
if (err < 0)
goto exit;
blkdev_put(bdev, FMODE_READ);
exit:
dev_set_uevent_suppress(ddev, 0);
kobject_uevent(&ddev->kobj, KOBJ_ADD);
disk_part_iter_init(&piter, disk, 0);
while ((part = disk_part_iter_next(&piter)))
kobject_uevent(&part_to_dev(part)->kobj, KOBJ_ADD);
disk_part_iter_exit(&piter);
}
void add_disk(struct gendisk *disk)
{
struct backing_dev_info *bdi;
dev_t devt;
int retval;
WARN_ON(disk->minors && !(disk->major || disk->first_minor));
WARN_ON(!disk->minors && !(disk->flags & GENHD_FL_EXT_DEVT));
disk->flags |= GENHD_FL_UP;
retval = blk_alloc_devt(&disk->part0, &devt);
if (retval) {
WARN_ON(1);
return;
}
disk_to_dev(disk)->devt = devt;
disk->major = MAJOR(devt);
disk->first_minor = MINOR(devt);
disk_alloc_events(disk);
bdi = &disk->queue->backing_dev_info;
bdi_register_dev(bdi, disk_devt(disk));
blk_register_region(disk_devt(disk), disk->minors, NULL,
exact_match, exact_lock, disk);
register_disk(disk);
blk_register_queue(disk);
WARN_ON_ONCE(!blk_get_queue(disk->queue));
retval = sysfs_create_link(&disk_to_dev(disk)->kobj, &bdi->dev->kobj,
"bdi");
WARN_ON(retval);
disk_add_events(disk);
blk_integrity_add(disk);
}
void del_gendisk(struct gendisk *disk)
{
struct disk_part_iter piter;
struct hd_struct *part;
blk_integrity_del(disk);
disk_del_events(disk);
disk_part_iter_init(&piter, disk,
DISK_PITER_INCL_EMPTY | DISK_PITER_REVERSE);
while ((part = disk_part_iter_next(&piter))) {
invalidate_partition(disk, part->partno);
delete_partition(disk, part->partno);
}
disk_part_iter_exit(&piter);
invalidate_partition(disk, 0);
set_capacity(disk, 0);
disk->flags &= ~GENHD_FL_UP;
sysfs_remove_link(&disk_to_dev(disk)->kobj, "bdi");
blk_unregister_queue(disk);
blk_unregister_region(disk_devt(disk), disk->minors);
part_stat_set_all(&disk->part0, 0);
disk->part0.stamp = 0;
kobject_put(disk->part0.holder_dir);
kobject_put(disk->slave_dir);
if (!sysfs_deprecated)
sysfs_remove_link(block_depr, dev_name(disk_to_dev(disk)));
pm_runtime_set_memalloc_noio(disk_to_dev(disk), false);
device_del(disk_to_dev(disk));
}
static ssize_t disk_badblocks_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
struct gendisk *disk = dev_to_disk(dev);
if (!disk->bb)
return sprintf(page, "\n");
return badblocks_show(disk->bb, page, 0);
}
static ssize_t disk_badblocks_store(struct device *dev,
struct device_attribute *attr,
const char *page, size_t len)
{
struct gendisk *disk = dev_to_disk(dev);
if (!disk->bb)
return -ENXIO;
return badblocks_store(disk->bb, page, len, 0);
}
struct gendisk *get_gendisk(dev_t devt, int *partno)
{
struct gendisk *disk = NULL;
if (MAJOR(devt) != BLOCK_EXT_MAJOR) {
struct kobject *kobj;
kobj = kobj_lookup(bdev_map, devt, partno);
if (kobj)
disk = dev_to_disk(kobj_to_dev(kobj));
} else {
struct hd_struct *part;
spin_lock_bh(&ext_devt_lock);
part = idr_find(&ext_devt_idr, blk_mangle_minor(MINOR(devt)));
if (part && get_disk(part_to_disk(part))) {
*partno = part->partno;
disk = part_to_disk(part);
}
spin_unlock_bh(&ext_devt_lock);
}
return disk;
}
struct block_device *bdget_disk(struct gendisk *disk, int partno)
{
struct hd_struct *part;
struct block_device *bdev = NULL;
part = disk_get_part(disk, partno);
if (part)
bdev = bdget(part_devt(part));
disk_put_part(part);
return bdev;
}
void __init printk_all_partitions(void)
{
struct class_dev_iter iter;
struct device *dev;
class_dev_iter_init(&iter, &block_class, NULL, &disk_type);
while ((dev = class_dev_iter_next(&iter))) {
struct gendisk *disk = dev_to_disk(dev);
struct disk_part_iter piter;
struct hd_struct *part;
char name_buf[BDEVNAME_SIZE];
char devt_buf[BDEVT_SIZE];
if (get_capacity(disk) == 0 ||
(disk->flags & GENHD_FL_SUPPRESS_PARTITION_INFO))
continue;
disk_part_iter_init(&piter, disk, DISK_PITER_INCL_PART0);
while ((part = disk_part_iter_next(&piter))) {
bool is_part0 = part == &disk->part0;
printk("%s%s %10llu %s %s", is_part0 ? "" : " ",
bdevt_str(part_devt(part), devt_buf),
(unsigned long long)part_nr_sects_read(part) >> 1
, disk_name(disk, part->partno, name_buf),
part->info ? part->info->uuid : "");
if (is_part0) {
if (disk->driverfs_dev != NULL &&
disk->driverfs_dev->driver != NULL)
printk(" driver: %s\n",
disk->driverfs_dev->driver->name);
else
printk(" (driver?)\n");
} else
printk("\n");
}
disk_part_iter_exit(&piter);
}
class_dev_iter_exit(&iter);
}
static void *disk_seqf_start(struct seq_file *seqf, loff_t *pos)
{
loff_t skip = *pos;
struct class_dev_iter *iter;
struct device *dev;
iter = kmalloc(sizeof(*iter), GFP_KERNEL);
if (!iter)
return ERR_PTR(-ENOMEM);
seqf->private = iter;
class_dev_iter_init(iter, &block_class, NULL, &disk_type);
do {
dev = class_dev_iter_next(iter);
if (!dev)
return NULL;
} while (skip--);
return dev_to_disk(dev);
}
static void *disk_seqf_next(struct seq_file *seqf, void *v, loff_t *pos)
{
struct device *dev;
(*pos)++;
dev = class_dev_iter_next(seqf->private);
if (dev)
return dev_to_disk(dev);
return NULL;
}
static void disk_seqf_stop(struct seq_file *seqf, void *v)
{
struct class_dev_iter *iter = seqf->private;
if (iter) {
class_dev_iter_exit(iter);
kfree(iter);
}
}
static void *show_partition_start(struct seq_file *seqf, loff_t *pos)
{
void *p;
p = disk_seqf_start(seqf, pos);
if (!IS_ERR_OR_NULL(p) && !*pos)
seq_puts(seqf, "major minor #blocks name\n\n");
return p;
}
static int show_partition(struct seq_file *seqf, void *v)
{
struct gendisk *sgp = v;
struct disk_part_iter piter;
struct hd_struct *part;
char buf[BDEVNAME_SIZE];
if (!get_capacity(sgp) || (!disk_max_parts(sgp) &&
(sgp->flags & GENHD_FL_REMOVABLE)))
return 0;
if (sgp->flags & GENHD_FL_SUPPRESS_PARTITION_INFO)
return 0;
disk_part_iter_init(&piter, sgp, DISK_PITER_INCL_PART0);
while ((part = disk_part_iter_next(&piter)))
seq_printf(seqf, "%4d %7d %10llu %s\n",
MAJOR(part_devt(part)), MINOR(part_devt(part)),
(unsigned long long)part_nr_sects_read(part) >> 1,
disk_name(sgp, part->partno, buf));
disk_part_iter_exit(&piter);
return 0;
}
static int partitions_open(struct inode *inode, struct file *file)
{
return seq_open(file, &partitions_op);
}
static struct kobject *base_probe(dev_t devt, int *partno, void *data)
{
if (request_module("block-major-%d-%d", MAJOR(devt), MINOR(devt)) > 0)
request_module("block-major-%d", MAJOR(devt));
return NULL;
}
static int __init genhd_device_init(void)
{
int error;
block_class.dev_kobj = sysfs_dev_block_kobj;
error = class_register(&block_class);
if (unlikely(error))
return error;
bdev_map = kobj_map_init(base_probe, &block_class_lock);
blk_dev_init();
register_blkdev(BLOCK_EXT_MAJOR, "blkext");
if (!sysfs_deprecated)
block_depr = kobject_create_and_add("block", NULL);
return 0;
}
static ssize_t disk_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n", disk->minors);
}
static ssize_t disk_ext_range_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n", disk_max_parts(disk));
}
static ssize_t disk_removable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n",
(disk->flags & GENHD_FL_REMOVABLE ? 1 : 0));
}
static ssize_t disk_ro_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n", get_disk_ro(disk) ? 1 : 0);
}
static ssize_t disk_capability_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%x\n", disk->flags);
}
static ssize_t disk_alignment_offset_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n", queue_alignment_offset(disk->queue));
}
static ssize_t disk_discard_alignment_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%d\n", queue_discard_alignment(disk->queue));
}
static void disk_replace_part_tbl(struct gendisk *disk,
struct disk_part_tbl *new_ptbl)
{
struct disk_part_tbl *old_ptbl = disk->part_tbl;
rcu_assign_pointer(disk->part_tbl, new_ptbl);
if (old_ptbl) {
rcu_assign_pointer(old_ptbl->last_lookup, NULL);
kfree_rcu(old_ptbl, rcu_head);
}
}
int disk_expand_part_tbl(struct gendisk *disk, int partno)
{
struct disk_part_tbl *old_ptbl = disk->part_tbl;
struct disk_part_tbl *new_ptbl;
int len = old_ptbl ? old_ptbl->len : 0;
int i, target;
size_t size;
target = partno + 1;
if (target < 0)
return -EINVAL;
if (disk_max_parts(disk) && target > disk_max_parts(disk))
return -EINVAL;
if (target <= len)
return 0;
size = sizeof(*new_ptbl) + target * sizeof(new_ptbl->part[0]);
new_ptbl = kzalloc_node(size, GFP_KERNEL, disk->node_id);
if (!new_ptbl)
return -ENOMEM;
new_ptbl->len = target;
for (i = 0; i < len; i++)
rcu_assign_pointer(new_ptbl->part[i], old_ptbl->part[i]);
disk_replace_part_tbl(disk, new_ptbl);
return 0;
}
static void disk_release(struct device *dev)
{
struct gendisk *disk = dev_to_disk(dev);
blk_free_devt(dev->devt);
disk_release_events(disk);
kfree(disk->random);
disk_replace_part_tbl(disk, NULL);
hd_free_part(&disk->part0);
if (disk->queue)
blk_put_queue(disk->queue);
kfree(disk);
}
static char *block_devnode(struct device *dev, umode_t *mode,
kuid_t *uid, kgid_t *gid)
{
struct gendisk *disk = dev_to_disk(dev);
if (disk->devnode)
return disk->devnode(disk, mode);
return NULL;
}
static int diskstats_show(struct seq_file *seqf, void *v)
{
struct gendisk *gp = v;
struct disk_part_iter piter;
struct hd_struct *hd;
char buf[BDEVNAME_SIZE];
int cpu;
disk_part_iter_init(&piter, gp, DISK_PITER_INCL_EMPTY_PART0);
while ((hd = disk_part_iter_next(&piter))) {
cpu = part_stat_lock();
part_round_stats(cpu, hd);
part_stat_unlock();
seq_printf(seqf, "%4d %7d %s %lu %lu %lu "
"%u %lu %lu %lu %u %u %u %u\n",
MAJOR(part_devt(hd)), MINOR(part_devt(hd)),
disk_name(gp, hd->partno, buf),
part_stat_read(hd, ios[READ]),
part_stat_read(hd, merges[READ]),
part_stat_read(hd, sectors[READ]),
jiffies_to_msecs(part_stat_read(hd, ticks[READ])),
part_stat_read(hd, ios[WRITE]),
part_stat_read(hd, merges[WRITE]),
part_stat_read(hd, sectors[WRITE]),
jiffies_to_msecs(part_stat_read(hd, ticks[WRITE])),
part_in_flight(hd),
jiffies_to_msecs(part_stat_read(hd, io_ticks)),
jiffies_to_msecs(part_stat_read(hd, time_in_queue))
);
}
disk_part_iter_exit(&piter);
return 0;
}
static int diskstats_open(struct inode *inode, struct file *file)
{
return seq_open(file, &diskstats_op);
}
static int __init proc_genhd_init(void)
{
proc_create("diskstats", 0, NULL, &proc_diskstats_operations);
proc_create("partitions", 0, NULL, &proc_partitions_operations);
return 0;
}
dev_t blk_lookup_devt(const char *name, int partno)
{
dev_t devt = MKDEV(0, 0);
struct class_dev_iter iter;
struct device *dev;
class_dev_iter_init(&iter, &block_class, NULL, &disk_type);
while ((dev = class_dev_iter_next(&iter))) {
struct gendisk *disk = dev_to_disk(dev);
struct hd_struct *part;
if (strcmp(dev_name(dev), name))
continue;
if (partno < disk->minors) {
devt = MKDEV(MAJOR(dev->devt),
MINOR(dev->devt) + partno);
break;
}
part = disk_get_part(disk, partno);
if (part) {
devt = part_devt(part);
disk_put_part(part);
break;
}
disk_put_part(part);
}
class_dev_iter_exit(&iter);
return devt;
}
struct gendisk *alloc_disk(int minors)
{
return alloc_disk_node(minors, NUMA_NO_NODE);
}
struct gendisk *alloc_disk_node(int minors, int node_id)
{
struct gendisk *disk;
disk = kzalloc_node(sizeof(struct gendisk), GFP_KERNEL, node_id);
if (disk) {
if (!init_part_stats(&disk->part0)) {
kfree(disk);
return NULL;
}
disk->node_id = node_id;
if (disk_expand_part_tbl(disk, 0)) {
free_part_stats(&disk->part0);
kfree(disk);
return NULL;
}
disk->part_tbl->part[0] = &disk->part0;
seqcount_init(&disk->part0.nr_sects_seq);
if (hd_ref_init(&disk->part0)) {
hd_free_part(&disk->part0);
kfree(disk);
return NULL;
}
disk->minors = minors;
rand_initialize_disk(disk);
disk_to_dev(disk)->class = &block_class;
disk_to_dev(disk)->type = &disk_type;
device_initialize(disk_to_dev(disk));
}
return disk;
}
struct kobject *get_disk(struct gendisk *disk)
{
struct module *owner;
struct kobject *kobj;
if (!disk->fops)
return NULL;
owner = disk->fops->owner;
if (owner && !try_module_get(owner))
return NULL;
kobj = kobject_get(&disk_to_dev(disk)->kobj);
if (kobj == NULL) {
module_put(owner);
return NULL;
}
return kobj;
}
void put_disk(struct gendisk *disk)
{
if (disk)
kobject_put(&disk_to_dev(disk)->kobj);
}
static void set_disk_ro_uevent(struct gendisk *gd, int ro)
{
char event[] = "DISK_RO=1";
char *envp[] = { event, NULL };
if (!ro)
event[8] = '0';
kobject_uevent_env(&disk_to_dev(gd)->kobj, KOBJ_CHANGE, envp);
}
void set_device_ro(struct block_device *bdev, int flag)
{
bdev->bd_part->policy = flag;
}
void set_disk_ro(struct gendisk *disk, int flag)
{
struct disk_part_iter piter;
struct hd_struct *part;
if (disk->part0.policy != flag) {
set_disk_ro_uevent(disk, flag);
disk->part0.policy = flag;
}
disk_part_iter_init(&piter, disk, DISK_PITER_INCL_EMPTY);
while ((part = disk_part_iter_next(&piter)))
part->policy = flag;
disk_part_iter_exit(&piter);
}
int bdev_read_only(struct block_device *bdev)
{
if (!bdev)
return 0;
return bdev->bd_part->policy;
}
int invalidate_partition(struct gendisk *disk, int partno)
{
int res = 0;
struct block_device *bdev = bdget_disk(disk, partno);
if (bdev) {
fsync_bdev(bdev);
res = __invalidate_device(bdev, true);
bdput(bdev);
}
return res;
}
static unsigned long disk_events_poll_jiffies(struct gendisk *disk)
{
struct disk_events *ev = disk->ev;
long intv_msecs = 0;
if (ev->poll_msecs >= 0)
intv_msecs = ev->poll_msecs;
else if (disk->events & ~disk->async_events)
intv_msecs = disk_events_dfl_poll_msecs;
return msecs_to_jiffies(intv_msecs);
}
void disk_block_events(struct gendisk *disk)
{
struct disk_events *ev = disk->ev;
unsigned long flags;
bool cancel;
if (!ev)
return;
mutex_lock(&ev->block_mutex);
spin_lock_irqsave(&ev->lock, flags);
cancel = !ev->block++;
spin_unlock_irqrestore(&ev->lock, flags);
if (cancel)
cancel_delayed_work_sync(&disk->ev->dwork);
mutex_unlock(&ev->block_mutex);
}
static void __disk_unblock_events(struct gendisk *disk, bool check_now)
{
struct disk_events *ev = disk->ev;
unsigned long intv;
unsigned long flags;
spin_lock_irqsave(&ev->lock, flags);
if (WARN_ON_ONCE(ev->block <= 0))
goto out_unlock;
if (--ev->block)
goto out_unlock;
intv = disk_events_poll_jiffies(disk);
set_timer_slack(&ev->dwork.timer, intv / 4);
if (check_now)
queue_delayed_work(system_freezable_power_efficient_wq,
&ev->dwork, 0);
else if (intv)
queue_delayed_work(system_freezable_power_efficient_wq,
&ev->dwork, intv);
out_unlock:
spin_unlock_irqrestore(&ev->lock, flags);
}
void disk_unblock_events(struct gendisk *disk)
{
if (disk->ev)
__disk_unblock_events(disk, false);
}
void disk_flush_events(struct gendisk *disk, unsigned int mask)
{
struct disk_events *ev = disk->ev;
if (!ev)
return;
spin_lock_irq(&ev->lock);
ev->clearing |= mask;
if (!ev->block)
mod_delayed_work(system_freezable_power_efficient_wq,
&ev->dwork, 0);
spin_unlock_irq(&ev->lock);
}
unsigned int disk_clear_events(struct gendisk *disk, unsigned int mask)
{
const struct block_device_operations *bdops = disk->fops;
struct disk_events *ev = disk->ev;
unsigned int pending;
unsigned int clearing = mask;
if (!ev) {
if ((mask & DISK_EVENT_MEDIA_CHANGE) &&
bdops->media_changed && bdops->media_changed(disk))
return DISK_EVENT_MEDIA_CHANGE;
return 0;
}
disk_block_events(disk);
spin_lock_irq(&ev->lock);
clearing |= ev->clearing;
ev->clearing = 0;
spin_unlock_irq(&ev->lock);
disk_check_events(ev, &clearing);
__disk_unblock_events(disk, ev->clearing ? true : false);
spin_lock_irq(&ev->lock);
pending = ev->pending & mask;
ev->pending &= ~mask;
spin_unlock_irq(&ev->lock);
WARN_ON_ONCE(clearing & mask);
return pending;
}
static void disk_events_workfn(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct disk_events *ev = container_of(dwork, struct disk_events, dwork);
disk_check_events(ev, &ev->clearing);
}
static void disk_check_events(struct disk_events *ev,
unsigned int *clearing_ptr)
{
struct gendisk *disk = ev->disk;
char *envp[ARRAY_SIZE(disk_uevents) + 1] = { };
unsigned int clearing = *clearing_ptr;
unsigned int events;
unsigned long intv;
int nr_events = 0, i;
events = disk->fops->check_events(disk, clearing);
spin_lock_irq(&ev->lock);
events &= ~ev->pending;
ev->pending |= events;
*clearing_ptr &= ~clearing;
intv = disk_events_poll_jiffies(disk);
if (!ev->block && intv)
queue_delayed_work(system_freezable_power_efficient_wq,
&ev->dwork, intv);
spin_unlock_irq(&ev->lock);
for (i = 0; i < ARRAY_SIZE(disk_uevents); i++)
if (events & disk->events & (1 << i))
envp[nr_events++] = disk_uevents[i];
if (nr_events)
kobject_uevent_env(&disk_to_dev(disk)->kobj, KOBJ_CHANGE, envp);
}
static ssize_t __disk_events_show(unsigned int events, char *buf)
{
const char *delim = "";
ssize_t pos = 0;
int i;
for (i = 0; i < ARRAY_SIZE(disk_events_strs); i++)
if (events & (1 << i)) {
pos += sprintf(buf + pos, "%s%s",
delim, disk_events_strs[i]);
delim = " ";
}
if (pos)
pos += sprintf(buf + pos, "\n");
return pos;
}
static ssize_t disk_events_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return __disk_events_show(disk->events, buf);
}
static ssize_t disk_events_async_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return __disk_events_show(disk->async_events, buf);
}
static ssize_t disk_events_poll_msecs_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct gendisk *disk = dev_to_disk(dev);
return sprintf(buf, "%ld\n", disk->ev->poll_msecs);
}
static ssize_t disk_events_poll_msecs_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct gendisk *disk = dev_to_disk(dev);
long intv;
if (!count || !sscanf(buf, "%ld", &intv))
return -EINVAL;
if (intv < 0 && intv != -1)
return -EINVAL;
disk_block_events(disk);
disk->ev->poll_msecs = intv;
__disk_unblock_events(disk, true);
return count;
}
static int disk_events_set_dfl_poll_msecs(const char *val,
const struct kernel_param *kp)
{
struct disk_events *ev;
int ret;
ret = param_set_ulong(val, kp);
if (ret < 0)
return ret;
mutex_lock(&disk_events_mutex);
list_for_each_entry(ev, &disk_events, node)
disk_flush_events(ev->disk, 0);
mutex_unlock(&disk_events_mutex);
return 0;
}
static void disk_alloc_events(struct gendisk *disk)
{
struct disk_events *ev;
if (!disk->fops->check_events)
return;
ev = kzalloc(sizeof(*ev), GFP_KERNEL);
if (!ev) {
pr_warn("%s: failed to initialize events\n", disk->disk_name);
return;
}
INIT_LIST_HEAD(&ev->node);
ev->disk = disk;
spin_lock_init(&ev->lock);
mutex_init(&ev->block_mutex);
ev->block = 1;
ev->poll_msecs = -1;
INIT_DELAYED_WORK(&ev->dwork, disk_events_workfn);
disk->ev = ev;
}
static void disk_add_events(struct gendisk *disk)
{
if (!disk->ev)
return;
if (sysfs_create_files(&disk_to_dev(disk)->kobj, disk_events_attrs) < 0)
pr_warn("%s: failed to create sysfs files for events\n",
disk->disk_name);
mutex_lock(&disk_events_mutex);
list_add_tail(&disk->ev->node, &disk_events);
mutex_unlock(&disk_events_mutex);
__disk_unblock_events(disk, true);
}
static void disk_del_events(struct gendisk *disk)
{
if (!disk->ev)
return;
disk_block_events(disk);
mutex_lock(&disk_events_mutex);
list_del_init(&disk->ev->node);
mutex_unlock(&disk_events_mutex);
sysfs_remove_files(&disk_to_dev(disk)->kobj, disk_events_attrs);
}
static void disk_release_events(struct gendisk *disk)
{
WARN_ON_ONCE(disk->ev && disk->ev->block != 1);
kfree(disk->ev);
}
