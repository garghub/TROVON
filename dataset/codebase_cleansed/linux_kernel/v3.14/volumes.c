static void lock_chunks(struct btrfs_root *root)
{
mutex_lock(&root->fs_info->chunk_mutex);
}
static void unlock_chunks(struct btrfs_root *root)
{
mutex_unlock(&root->fs_info->chunk_mutex);
}
static struct btrfs_fs_devices *__alloc_fs_devices(void)
{
struct btrfs_fs_devices *fs_devs;
fs_devs = kzalloc(sizeof(*fs_devs), GFP_NOFS);
if (!fs_devs)
return ERR_PTR(-ENOMEM);
mutex_init(&fs_devs->device_list_mutex);
INIT_LIST_HEAD(&fs_devs->devices);
INIT_LIST_HEAD(&fs_devs->alloc_list);
INIT_LIST_HEAD(&fs_devs->list);
return fs_devs;
}
static struct btrfs_fs_devices *alloc_fs_devices(const u8 *fsid)
{
struct btrfs_fs_devices *fs_devs;
fs_devs = __alloc_fs_devices();
if (IS_ERR(fs_devs))
return fs_devs;
if (fsid)
memcpy(fs_devs->fsid, fsid, BTRFS_FSID_SIZE);
else
generate_random_uuid(fs_devs->fsid);
return fs_devs;
}
static void free_fs_devices(struct btrfs_fs_devices *fs_devices)
{
struct btrfs_device *device;
WARN_ON(fs_devices->opened);
while (!list_empty(&fs_devices->devices)) {
device = list_entry(fs_devices->devices.next,
struct btrfs_device, dev_list);
list_del(&device->dev_list);
rcu_string_free(device->name);
kfree(device);
}
kfree(fs_devices);
}
static void btrfs_kobject_uevent(struct block_device *bdev,
enum kobject_action action)
{
int ret;
ret = kobject_uevent(&disk_to_dev(bdev->bd_disk)->kobj, action);
if (ret)
pr_warn("BTRFS: Sending event '%d' to kobject: '%s' (%p): failed\n",
action,
kobject_name(&disk_to_dev(bdev->bd_disk)->kobj),
&disk_to_dev(bdev->bd_disk)->kobj);
}
void btrfs_cleanup_fs_uuids(void)
{
struct btrfs_fs_devices *fs_devices;
while (!list_empty(&fs_uuids)) {
fs_devices = list_entry(fs_uuids.next,
struct btrfs_fs_devices, list);
list_del(&fs_devices->list);
free_fs_devices(fs_devices);
}
}
static struct btrfs_device *__alloc_device(void)
{
struct btrfs_device *dev;
dev = kzalloc(sizeof(*dev), GFP_NOFS);
if (!dev)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&dev->dev_list);
INIT_LIST_HEAD(&dev->dev_alloc_list);
spin_lock_init(&dev->io_lock);
spin_lock_init(&dev->reada_lock);
atomic_set(&dev->reada_in_flight, 0);
INIT_RADIX_TREE(&dev->reada_zones, GFP_NOFS & ~__GFP_WAIT);
INIT_RADIX_TREE(&dev->reada_extents, GFP_NOFS & ~__GFP_WAIT);
return dev;
}
noinline struct btrfs_fs_devices *find_fsid(u8 *fsid)
{
struct btrfs_fs_devices *fs_devices;
list_for_each_entry(fs_devices, &fs_uuids, list) {
if (memcmp(fsid, fs_devices->fsid, BTRFS_FSID_SIZE) == 0)
return fs_devices;
}
return NULL;
}
static int
btrfs_get_bdev_and_sb(const char *device_path, fmode_t flags, void *holder,
int flush, struct block_device **bdev,
struct buffer_head **bh)
{
int ret;
*bdev = blkdev_get_by_path(device_path, flags, holder);
if (IS_ERR(*bdev)) {
ret = PTR_ERR(*bdev);
printk(KERN_INFO "BTRFS: open %s failed\n", device_path);
goto error;
}
if (flush)
filemap_write_and_wait((*bdev)->bd_inode->i_mapping);
ret = set_blocksize(*bdev, 4096);
if (ret) {
blkdev_put(*bdev, flags);
goto error;
}
invalidate_bdev(*bdev);
*bh = btrfs_read_dev_super(*bdev);
if (!*bh) {
ret = -EINVAL;
blkdev_put(*bdev, flags);
goto error;
}
return 0;
error:
*bdev = NULL;
*bh = NULL;
return ret;
}
static void requeue_list(struct btrfs_pending_bios *pending_bios,
struct bio *head, struct bio *tail)
{
struct bio *old_head;
old_head = pending_bios->head;
pending_bios->head = head;
if (pending_bios->tail)
tail->bi_next = old_head;
else
pending_bios->tail = tail;
}
static noinline void run_scheduled_bios(struct btrfs_device *device)
{
struct bio *pending;
struct backing_dev_info *bdi;
struct btrfs_fs_info *fs_info;
struct btrfs_pending_bios *pending_bios;
struct bio *tail;
struct bio *cur;
int again = 0;
unsigned long num_run;
unsigned long batch_run = 0;
unsigned long limit;
unsigned long last_waited = 0;
int force_reg = 0;
int sync_pending = 0;
struct blk_plug plug;
blk_start_plug(&plug);
bdi = blk_get_backing_dev_info(device->bdev);
fs_info = device->dev_root->fs_info;
limit = btrfs_async_submit_limit(fs_info);
limit = limit * 2 / 3;
loop:
spin_lock(&device->io_lock);
loop_lock:
num_run = 0;
if (!force_reg && device->pending_sync_bios.head) {
pending_bios = &device->pending_sync_bios;
force_reg = 1;
} else {
pending_bios = &device->pending_bios;
force_reg = 0;
}
pending = pending_bios->head;
tail = pending_bios->tail;
WARN_ON(pending && !tail);
if (device->pending_sync_bios.head == NULL &&
device->pending_bios.head == NULL) {
again = 0;
device->running_pending = 0;
} else {
again = 1;
device->running_pending = 1;
}
pending_bios->head = NULL;
pending_bios->tail = NULL;
spin_unlock(&device->io_lock);
while (pending) {
rmb();
if ((num_run > 32 &&
pending_bios != &device->pending_sync_bios &&
device->pending_sync_bios.head) ||
(num_run > 64 && pending_bios == &device->pending_sync_bios &&
device->pending_bios.head)) {
spin_lock(&device->io_lock);
requeue_list(pending_bios, pending, tail);
goto loop_lock;
}
cur = pending;
pending = pending->bi_next;
cur->bi_next = NULL;
if (atomic_dec_return(&fs_info->nr_async_bios) < limit &&
waitqueue_active(&fs_info->async_submit_wait))
wake_up(&fs_info->async_submit_wait);
BUG_ON(atomic_read(&cur->bi_cnt) == 0);
if (pending_bios == &device->pending_sync_bios) {
sync_pending = 1;
} else if (sync_pending) {
blk_finish_plug(&plug);
blk_start_plug(&plug);
sync_pending = 0;
}
btrfsic_submit_bio(cur->bi_rw, cur);
num_run++;
batch_run++;
if (need_resched())
cond_resched();
if (pending && bdi_write_congested(bdi) && batch_run > 8 &&
fs_info->fs_devices->open_devices > 1) {
struct io_context *ioc;
ioc = current->io_context;
if (ioc && ioc->nr_batch_requests > 0 &&
time_before(jiffies, ioc->last_waited + HZ/50UL) &&
(last_waited == 0 ||
ioc->last_waited == last_waited)) {
last_waited = ioc->last_waited;
if (need_resched())
cond_resched();
continue;
}
spin_lock(&device->io_lock);
requeue_list(pending_bios, pending, tail);
device->running_pending = 1;
spin_unlock(&device->io_lock);
btrfs_requeue_work(&device->work);
goto done;
}
if (batch_run % 64 == 0) {
blk_finish_plug(&plug);
blk_start_plug(&plug);
sync_pending = 0;
}
}
cond_resched();
if (again)
goto loop;
spin_lock(&device->io_lock);
if (device->pending_bios.head || device->pending_sync_bios.head)
goto loop_lock;
spin_unlock(&device->io_lock);
done:
blk_finish_plug(&plug);
}
static void pending_bios_fn(struct btrfs_work *work)
{
struct btrfs_device *device;
device = container_of(work, struct btrfs_device, work);
run_scheduled_bios(device);
}
static noinline int device_list_add(const char *path,
struct btrfs_super_block *disk_super,
u64 devid, struct btrfs_fs_devices **fs_devices_ret)
{
struct btrfs_device *device;
struct btrfs_fs_devices *fs_devices;
struct rcu_string *name;
u64 found_transid = btrfs_super_generation(disk_super);
fs_devices = find_fsid(disk_super->fsid);
if (!fs_devices) {
fs_devices = alloc_fs_devices(disk_super->fsid);
if (IS_ERR(fs_devices))
return PTR_ERR(fs_devices);
list_add(&fs_devices->list, &fs_uuids);
fs_devices->latest_devid = devid;
fs_devices->latest_trans = found_transid;
device = NULL;
} else {
device = __find_device(&fs_devices->devices, devid,
disk_super->dev_item.uuid);
}
if (!device) {
if (fs_devices->opened)
return -EBUSY;
device = btrfs_alloc_device(NULL, &devid,
disk_super->dev_item.uuid);
if (IS_ERR(device)) {
return PTR_ERR(device);
}
name = rcu_string_strdup(path, GFP_NOFS);
if (!name) {
kfree(device);
return -ENOMEM;
}
rcu_assign_pointer(device->name, name);
mutex_lock(&fs_devices->device_list_mutex);
list_add_rcu(&device->dev_list, &fs_devices->devices);
fs_devices->num_devices++;
mutex_unlock(&fs_devices->device_list_mutex);
device->fs_devices = fs_devices;
} else if (!device->name || strcmp(device->name->str, path)) {
name = rcu_string_strdup(path, GFP_NOFS);
if (!name)
return -ENOMEM;
rcu_string_free(device->name);
rcu_assign_pointer(device->name, name);
if (device->missing) {
fs_devices->missing_devices--;
device->missing = 0;
}
}
if (found_transid > fs_devices->latest_trans) {
fs_devices->latest_devid = devid;
fs_devices->latest_trans = found_transid;
}
*fs_devices_ret = fs_devices;
return 0;
}
static struct btrfs_fs_devices *clone_fs_devices(struct btrfs_fs_devices *orig)
{
struct btrfs_fs_devices *fs_devices;
struct btrfs_device *device;
struct btrfs_device *orig_dev;
fs_devices = alloc_fs_devices(orig->fsid);
if (IS_ERR(fs_devices))
return fs_devices;
fs_devices->latest_devid = orig->latest_devid;
fs_devices->latest_trans = orig->latest_trans;
fs_devices->total_devices = orig->total_devices;
list_for_each_entry(orig_dev, &orig->devices, dev_list) {
struct rcu_string *name;
device = btrfs_alloc_device(NULL, &orig_dev->devid,
orig_dev->uuid);
if (IS_ERR(device))
goto error;
name = rcu_string_strdup(orig_dev->name->str, GFP_NOFS);
if (!name) {
kfree(device);
goto error;
}
rcu_assign_pointer(device->name, name);
list_add(&device->dev_list, &fs_devices->devices);
device->fs_devices = fs_devices;
fs_devices->num_devices++;
}
return fs_devices;
error:
free_fs_devices(fs_devices);
return ERR_PTR(-ENOMEM);
}
void btrfs_close_extra_devices(struct btrfs_fs_info *fs_info,
struct btrfs_fs_devices *fs_devices, int step)
{
struct btrfs_device *device, *next;
struct block_device *latest_bdev = NULL;
u64 latest_devid = 0;
u64 latest_transid = 0;
mutex_lock(&uuid_mutex);
again:
list_for_each_entry_safe(device, next, &fs_devices->devices, dev_list) {
if (device->in_fs_metadata) {
if (!device->is_tgtdev_for_dev_replace &&
(!latest_transid ||
device->generation > latest_transid)) {
latest_devid = device->devid;
latest_transid = device->generation;
latest_bdev = device->bdev;
}
continue;
}
if (device->devid == BTRFS_DEV_REPLACE_DEVID) {
if (step == 0 || device->is_tgtdev_for_dev_replace) {
continue;
}
}
if (device->bdev) {
blkdev_put(device->bdev, device->mode);
device->bdev = NULL;
fs_devices->open_devices--;
}
if (device->writeable) {
list_del_init(&device->dev_alloc_list);
device->writeable = 0;
if (!device->is_tgtdev_for_dev_replace)
fs_devices->rw_devices--;
}
list_del_init(&device->dev_list);
fs_devices->num_devices--;
rcu_string_free(device->name);
kfree(device);
}
if (fs_devices->seed) {
fs_devices = fs_devices->seed;
goto again;
}
fs_devices->latest_bdev = latest_bdev;
fs_devices->latest_devid = latest_devid;
fs_devices->latest_trans = latest_transid;
mutex_unlock(&uuid_mutex);
}
static void __free_device(struct work_struct *work)
{
struct btrfs_device *device;
device = container_of(work, struct btrfs_device, rcu_work);
if (device->bdev)
blkdev_put(device->bdev, device->mode);
rcu_string_free(device->name);
kfree(device);
}
static void free_device(struct rcu_head *head)
{
struct btrfs_device *device;
device = container_of(head, struct btrfs_device, rcu);
INIT_WORK(&device->rcu_work, __free_device);
schedule_work(&device->rcu_work);
}
static int __btrfs_close_devices(struct btrfs_fs_devices *fs_devices)
{
struct btrfs_device *device;
if (--fs_devices->opened > 0)
return 0;
mutex_lock(&fs_devices->device_list_mutex);
list_for_each_entry(device, &fs_devices->devices, dev_list) {
struct btrfs_device *new_device;
struct rcu_string *name;
if (device->bdev)
fs_devices->open_devices--;
if (device->writeable &&
device->devid != BTRFS_DEV_REPLACE_DEVID) {
list_del_init(&device->dev_alloc_list);
fs_devices->rw_devices--;
}
if (device->can_discard)
fs_devices->num_can_discard--;
if (device->missing)
fs_devices->missing_devices--;
new_device = btrfs_alloc_device(NULL, &device->devid,
device->uuid);
BUG_ON(IS_ERR(new_device));
if (device->name) {
name = rcu_string_strdup(device->name->str, GFP_NOFS);
BUG_ON(!name);
rcu_assign_pointer(new_device->name, name);
}
list_replace_rcu(&device->dev_list, &new_device->dev_list);
new_device->fs_devices = device->fs_devices;
call_rcu(&device->rcu, free_device);
}
mutex_unlock(&fs_devices->device_list_mutex);
WARN_ON(fs_devices->open_devices);
WARN_ON(fs_devices->rw_devices);
fs_devices->opened = 0;
fs_devices->seeding = 0;
return 0;
}
int btrfs_close_devices(struct btrfs_fs_devices *fs_devices)
{
struct btrfs_fs_devices *seed_devices = NULL;
int ret;
mutex_lock(&uuid_mutex);
ret = __btrfs_close_devices(fs_devices);
if (!fs_devices->opened) {
seed_devices = fs_devices->seed;
fs_devices->seed = NULL;
}
mutex_unlock(&uuid_mutex);
while (seed_devices) {
fs_devices = seed_devices;
seed_devices = fs_devices->seed;
__btrfs_close_devices(fs_devices);
free_fs_devices(fs_devices);
}
rcu_barrier();
return ret;
}
static int __btrfs_open_devices(struct btrfs_fs_devices *fs_devices,
fmode_t flags, void *holder)
{
struct request_queue *q;
struct block_device *bdev;
struct list_head *head = &fs_devices->devices;
struct btrfs_device *device;
struct block_device *latest_bdev = NULL;
struct buffer_head *bh;
struct btrfs_super_block *disk_super;
u64 latest_devid = 0;
u64 latest_transid = 0;
u64 devid;
int seeding = 1;
int ret = 0;
flags |= FMODE_EXCL;
list_for_each_entry(device, head, dev_list) {
if (device->bdev)
continue;
if (!device->name)
continue;
if (btrfs_get_bdev_and_sb(device->name->str, flags, holder, 1,
&bdev, &bh))
continue;
disk_super = (struct btrfs_super_block *)bh->b_data;
devid = btrfs_stack_device_id(&disk_super->dev_item);
if (devid != device->devid)
goto error_brelse;
if (memcmp(device->uuid, disk_super->dev_item.uuid,
BTRFS_UUID_SIZE))
goto error_brelse;
device->generation = btrfs_super_generation(disk_super);
if (!latest_transid || device->generation > latest_transid) {
latest_devid = devid;
latest_transid = device->generation;
latest_bdev = bdev;
}
if (btrfs_super_flags(disk_super) & BTRFS_SUPER_FLAG_SEEDING) {
device->writeable = 0;
} else {
device->writeable = !bdev_read_only(bdev);
seeding = 0;
}
q = bdev_get_queue(bdev);
if (blk_queue_discard(q)) {
device->can_discard = 1;
fs_devices->num_can_discard++;
}
device->bdev = bdev;
device->in_fs_metadata = 0;
device->mode = flags;
if (!blk_queue_nonrot(bdev_get_queue(bdev)))
fs_devices->rotating = 1;
fs_devices->open_devices++;
if (device->writeable &&
device->devid != BTRFS_DEV_REPLACE_DEVID) {
fs_devices->rw_devices++;
list_add(&device->dev_alloc_list,
&fs_devices->alloc_list);
}
brelse(bh);
continue;
error_brelse:
brelse(bh);
blkdev_put(bdev, flags);
continue;
}
if (fs_devices->open_devices == 0) {
ret = -EINVAL;
goto out;
}
fs_devices->seeding = seeding;
fs_devices->opened = 1;
fs_devices->latest_bdev = latest_bdev;
fs_devices->latest_devid = latest_devid;
fs_devices->latest_trans = latest_transid;
fs_devices->total_rw_bytes = 0;
out:
return ret;
}
int btrfs_open_devices(struct btrfs_fs_devices *fs_devices,
fmode_t flags, void *holder)
{
int ret;
mutex_lock(&uuid_mutex);
if (fs_devices->opened) {
fs_devices->opened++;
ret = 0;
} else {
ret = __btrfs_open_devices(fs_devices, flags, holder);
}
mutex_unlock(&uuid_mutex);
return ret;
}
int btrfs_scan_one_device(const char *path, fmode_t flags, void *holder,
struct btrfs_fs_devices **fs_devices_ret)
{
struct btrfs_super_block *disk_super;
struct block_device *bdev;
struct page *page;
void *p;
int ret = -EINVAL;
u64 devid;
u64 transid;
u64 total_devices;
u64 bytenr;
pgoff_t index;
bytenr = btrfs_sb_offset(0);
flags |= FMODE_EXCL;
mutex_lock(&uuid_mutex);
bdev = blkdev_get_by_path(path, flags, holder);
if (IS_ERR(bdev)) {
ret = PTR_ERR(bdev);
goto error;
}
if (bytenr + PAGE_CACHE_SIZE >= i_size_read(bdev->bd_inode))
goto error_bdev_put;
if (sizeof(*disk_super) > PAGE_CACHE_SIZE)
goto error_bdev_put;
index = bytenr >> PAGE_CACHE_SHIFT;
if ((bytenr + sizeof(*disk_super) - 1) >> PAGE_CACHE_SHIFT != index)
goto error_bdev_put;
page = read_cache_page_gfp(bdev->bd_inode->i_mapping,
index, GFP_NOFS);
if (IS_ERR_OR_NULL(page))
goto error_bdev_put;
p = kmap(page);
disk_super = p + (bytenr & ~PAGE_CACHE_MASK);
if (btrfs_super_bytenr(disk_super) != bytenr ||
btrfs_super_magic(disk_super) != BTRFS_MAGIC)
goto error_unmap;
devid = btrfs_stack_device_id(&disk_super->dev_item);
transid = btrfs_super_generation(disk_super);
total_devices = btrfs_super_num_devices(disk_super);
if (disk_super->label[0]) {
if (disk_super->label[BTRFS_LABEL_SIZE - 1])
disk_super->label[BTRFS_LABEL_SIZE - 1] = '\0';
printk(KERN_INFO "BTRFS: device label %s ", disk_super->label);
} else {
printk(KERN_INFO "BTRFS: device fsid %pU ", disk_super->fsid);
}
printk(KERN_CONT "devid %llu transid %llu %s\n", devid, transid, path);
ret = device_list_add(path, disk_super, devid, fs_devices_ret);
if (!ret && fs_devices_ret)
(*fs_devices_ret)->total_devices = total_devices;
error_unmap:
kunmap(page);
page_cache_release(page);
error_bdev_put:
blkdev_put(bdev, flags);
error:
mutex_unlock(&uuid_mutex);
return ret;
}
int btrfs_account_dev_extents_size(struct btrfs_device *device, u64 start,
u64 end, u64 *length)
{
struct btrfs_key key;
struct btrfs_root *root = device->dev_root;
struct btrfs_dev_extent *dev_extent;
struct btrfs_path *path;
u64 extent_end;
int ret;
int slot;
struct extent_buffer *l;
*length = 0;
if (start >= device->total_bytes || device->is_tgtdev_for_dev_replace)
return 0;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
path->reada = 2;
key.objectid = device->devid;
key.offset = start;
key.type = BTRFS_DEV_EXTENT_KEY;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto out;
if (ret > 0) {
ret = btrfs_previous_item(root, path, key.objectid, key.type);
if (ret < 0)
goto out;
}
while (1) {
l = path->nodes[0];
slot = path->slots[0];
if (slot >= btrfs_header_nritems(l)) {
ret = btrfs_next_leaf(root, path);
if (ret == 0)
continue;
if (ret < 0)
goto out;
break;
}
btrfs_item_key_to_cpu(l, &key, slot);
if (key.objectid < device->devid)
goto next;
if (key.objectid > device->devid)
break;
if (btrfs_key_type(&key) != BTRFS_DEV_EXTENT_KEY)
goto next;
dev_extent = btrfs_item_ptr(l, slot, struct btrfs_dev_extent);
extent_end = key.offset + btrfs_dev_extent_length(l,
dev_extent);
if (key.offset <= start && extent_end > end) {
*length = end - start + 1;
break;
} else if (key.offset <= start && extent_end > start)
*length += extent_end - start;
else if (key.offset > start && extent_end <= end)
*length += extent_end - key.offset;
else if (key.offset > start && key.offset <= end) {
*length += end - key.offset + 1;
break;
} else if (key.offset > end)
break;
next:
path->slots[0]++;
}
ret = 0;
out:
btrfs_free_path(path);
return ret;
}
static int contains_pending_extent(struct btrfs_trans_handle *trans,
struct btrfs_device *device,
u64 *start, u64 len)
{
struct extent_map *em;
int ret = 0;
list_for_each_entry(em, &trans->transaction->pending_chunks, list) {
struct map_lookup *map;
int i;
map = (struct map_lookup *)em->bdev;
for (i = 0; i < map->num_stripes; i++) {
if (map->stripes[i].dev != device)
continue;
if (map->stripes[i].physical >= *start + len ||
map->stripes[i].physical + em->orig_block_len <=
*start)
continue;
*start = map->stripes[i].physical +
em->orig_block_len;
ret = 1;
}
}
return ret;
}
int find_free_dev_extent(struct btrfs_trans_handle *trans,
struct btrfs_device *device, u64 num_bytes,
u64 *start, u64 *len)
{
struct btrfs_key key;
struct btrfs_root *root = device->dev_root;
struct btrfs_dev_extent *dev_extent;
struct btrfs_path *path;
u64 hole_size;
u64 max_hole_start;
u64 max_hole_size;
u64 extent_end;
u64 search_start;
u64 search_end = device->total_bytes;
int ret;
int slot;
struct extent_buffer *l;
search_start = max(root->fs_info->alloc_start, 1024ull * 1024);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
again:
max_hole_start = search_start;
max_hole_size = 0;
hole_size = 0;
if (search_start >= search_end || device->is_tgtdev_for_dev_replace) {
ret = -ENOSPC;
goto out;
}
path->reada = 2;
path->search_commit_root = 1;
path->skip_locking = 1;
key.objectid = device->devid;
key.offset = search_start;
key.type = BTRFS_DEV_EXTENT_KEY;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto out;
if (ret > 0) {
ret = btrfs_previous_item(root, path, key.objectid, key.type);
if (ret < 0)
goto out;
}
while (1) {
l = path->nodes[0];
slot = path->slots[0];
if (slot >= btrfs_header_nritems(l)) {
ret = btrfs_next_leaf(root, path);
if (ret == 0)
continue;
if (ret < 0)
goto out;
break;
}
btrfs_item_key_to_cpu(l, &key, slot);
if (key.objectid < device->devid)
goto next;
if (key.objectid > device->devid)
break;
if (btrfs_key_type(&key) != BTRFS_DEV_EXTENT_KEY)
goto next;
if (key.offset > search_start) {
hole_size = key.offset - search_start;
if (contains_pending_extent(trans, device,
&search_start,
hole_size))
hole_size = 0;
if (hole_size > max_hole_size) {
max_hole_start = search_start;
max_hole_size = hole_size;
}
if (hole_size >= num_bytes) {
ret = 0;
goto out;
}
}
dev_extent = btrfs_item_ptr(l, slot, struct btrfs_dev_extent);
extent_end = key.offset + btrfs_dev_extent_length(l,
dev_extent);
if (extent_end > search_start)
search_start = extent_end;
next:
path->slots[0]++;
cond_resched();
}
if (search_end > search_start)
hole_size = search_end - search_start;
if (hole_size > max_hole_size) {
max_hole_start = search_start;
max_hole_size = hole_size;
}
if (contains_pending_extent(trans, device, &search_start, hole_size)) {
btrfs_release_path(path);
goto again;
}
if (hole_size < num_bytes)
ret = -ENOSPC;
else
ret = 0;
out:
btrfs_free_path(path);
*start = max_hole_start;
if (len)
*len = max_hole_size;
return ret;
}
static int btrfs_free_dev_extent(struct btrfs_trans_handle *trans,
struct btrfs_device *device,
u64 start)
{
int ret;
struct btrfs_path *path;
struct btrfs_root *root = device->dev_root;
struct btrfs_key key;
struct btrfs_key found_key;
struct extent_buffer *leaf = NULL;
struct btrfs_dev_extent *extent = NULL;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = device->devid;
key.offset = start;
key.type = BTRFS_DEV_EXTENT_KEY;
again:
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret > 0) {
ret = btrfs_previous_item(root, path, key.objectid,
BTRFS_DEV_EXTENT_KEY);
if (ret)
goto out;
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
extent = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_dev_extent);
BUG_ON(found_key.offset > start || found_key.offset +
btrfs_dev_extent_length(leaf, extent) < start);
key = found_key;
btrfs_release_path(path);
goto again;
} else if (ret == 0) {
leaf = path->nodes[0];
extent = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_dev_extent);
} else {
btrfs_error(root->fs_info, ret, "Slot search failed");
goto out;
}
if (device->bytes_used > 0) {
u64 len = btrfs_dev_extent_length(leaf, extent);
device->bytes_used -= len;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space += len;
spin_unlock(&root->fs_info->free_chunk_lock);
}
ret = btrfs_del_item(trans, root, path);
if (ret) {
btrfs_error(root->fs_info, ret,
"Failed to remove dev extent item");
}
out:
btrfs_free_path(path);
return ret;
}
static int btrfs_alloc_dev_extent(struct btrfs_trans_handle *trans,
struct btrfs_device *device,
u64 chunk_tree, u64 chunk_objectid,
u64 chunk_offset, u64 start, u64 num_bytes)
{
int ret;
struct btrfs_path *path;
struct btrfs_root *root = device->dev_root;
struct btrfs_dev_extent *extent;
struct extent_buffer *leaf;
struct btrfs_key key;
WARN_ON(!device->in_fs_metadata);
WARN_ON(device->is_tgtdev_for_dev_replace);
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = device->devid;
key.offset = start;
key.type = BTRFS_DEV_EXTENT_KEY;
ret = btrfs_insert_empty_item(trans, root, path, &key,
sizeof(*extent));
if (ret)
goto out;
leaf = path->nodes[0];
extent = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_dev_extent);
btrfs_set_dev_extent_chunk_tree(leaf, extent, chunk_tree);
btrfs_set_dev_extent_chunk_objectid(leaf, extent, chunk_objectid);
btrfs_set_dev_extent_chunk_offset(leaf, extent, chunk_offset);
write_extent_buffer(leaf, root->fs_info->chunk_tree_uuid,
btrfs_dev_extent_chunk_tree_uuid(extent), BTRFS_UUID_SIZE);
btrfs_set_dev_extent_length(leaf, extent, num_bytes);
btrfs_mark_buffer_dirty(leaf);
out:
btrfs_free_path(path);
return ret;
}
static u64 find_next_chunk(struct btrfs_fs_info *fs_info)
{
struct extent_map_tree *em_tree;
struct extent_map *em;
struct rb_node *n;
u64 ret = 0;
em_tree = &fs_info->mapping_tree.map_tree;
read_lock(&em_tree->lock);
n = rb_last(&em_tree->map);
if (n) {
em = rb_entry(n, struct extent_map, rb_node);
ret = em->start + em->len;
}
read_unlock(&em_tree->lock);
return ret;
}
static noinline int find_next_devid(struct btrfs_fs_info *fs_info,
u64 *devid_ret)
{
int ret;
struct btrfs_key key;
struct btrfs_key found_key;
struct btrfs_path *path;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.type = BTRFS_DEV_ITEM_KEY;
key.offset = (u64)-1;
ret = btrfs_search_slot(NULL, fs_info->chunk_root, &key, path, 0, 0);
if (ret < 0)
goto error;
BUG_ON(ret == 0);
ret = btrfs_previous_item(fs_info->chunk_root, path,
BTRFS_DEV_ITEMS_OBJECTID,
BTRFS_DEV_ITEM_KEY);
if (ret) {
*devid_ret = 1;
} else {
btrfs_item_key_to_cpu(path->nodes[0], &found_key,
path->slots[0]);
*devid_ret = found_key.offset + 1;
}
ret = 0;
error:
btrfs_free_path(path);
return ret;
}
static int btrfs_add_device(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_device *device)
{
int ret;
struct btrfs_path *path;
struct btrfs_dev_item *dev_item;
struct extent_buffer *leaf;
struct btrfs_key key;
unsigned long ptr;
root = root->fs_info->chunk_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.type = BTRFS_DEV_ITEM_KEY;
key.offset = device->devid;
ret = btrfs_insert_empty_item(trans, root, path, &key,
sizeof(*dev_item));
if (ret)
goto out;
leaf = path->nodes[0];
dev_item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_dev_item);
btrfs_set_device_id(leaf, dev_item, device->devid);
btrfs_set_device_generation(leaf, dev_item, 0);
btrfs_set_device_type(leaf, dev_item, device->type);
btrfs_set_device_io_align(leaf, dev_item, device->io_align);
btrfs_set_device_io_width(leaf, dev_item, device->io_width);
btrfs_set_device_sector_size(leaf, dev_item, device->sector_size);
btrfs_set_device_total_bytes(leaf, dev_item, device->total_bytes);
btrfs_set_device_bytes_used(leaf, dev_item, device->bytes_used);
btrfs_set_device_group(leaf, dev_item, 0);
btrfs_set_device_seek_speed(leaf, dev_item, 0);
btrfs_set_device_bandwidth(leaf, dev_item, 0);
btrfs_set_device_start_offset(leaf, dev_item, 0);
ptr = btrfs_device_uuid(dev_item);
write_extent_buffer(leaf, device->uuid, ptr, BTRFS_UUID_SIZE);
ptr = btrfs_device_fsid(dev_item);
write_extent_buffer(leaf, root->fs_info->fsid, ptr, BTRFS_UUID_SIZE);
btrfs_mark_buffer_dirty(leaf);
ret = 0;
out:
btrfs_free_path(path);
return ret;
}
static int btrfs_rm_dev_item(struct btrfs_root *root,
struct btrfs_device *device)
{
int ret;
struct btrfs_path *path;
struct btrfs_key key;
struct btrfs_trans_handle *trans;
root = root->fs_info->chunk_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
btrfs_free_path(path);
return PTR_ERR(trans);
}
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.type = BTRFS_DEV_ITEM_KEY;
key.offset = device->devid;
lock_chunks(root);
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret < 0)
goto out;
if (ret > 0) {
ret = -ENOENT;
goto out;
}
ret = btrfs_del_item(trans, root, path);
if (ret)
goto out;
out:
btrfs_free_path(path);
unlock_chunks(root);
btrfs_commit_transaction(trans, root);
return ret;
}
int btrfs_rm_device(struct btrfs_root *root, char *device_path)
{
struct btrfs_device *device;
struct btrfs_device *next_device;
struct block_device *bdev;
struct buffer_head *bh = NULL;
struct btrfs_super_block *disk_super;
struct btrfs_fs_devices *cur_devices;
u64 all_avail;
u64 devid;
u64 num_devices;
u8 *dev_uuid;
unsigned seq;
int ret = 0;
bool clear_super = false;
mutex_lock(&uuid_mutex);
do {
seq = read_seqbegin(&root->fs_info->profiles_lock);
all_avail = root->fs_info->avail_data_alloc_bits |
root->fs_info->avail_system_alloc_bits |
root->fs_info->avail_metadata_alloc_bits;
} while (read_seqretry(&root->fs_info->profiles_lock, seq));
num_devices = root->fs_info->fs_devices->num_devices;
btrfs_dev_replace_lock(&root->fs_info->dev_replace);
if (btrfs_dev_replace_is_ongoing(&root->fs_info->dev_replace)) {
WARN_ON(num_devices < 1);
num_devices--;
}
btrfs_dev_replace_unlock(&root->fs_info->dev_replace);
if ((all_avail & BTRFS_BLOCK_GROUP_RAID10) && num_devices <= 4) {
ret = BTRFS_ERROR_DEV_RAID10_MIN_NOT_MET;
goto out;
}
if ((all_avail & BTRFS_BLOCK_GROUP_RAID1) && num_devices <= 2) {
ret = BTRFS_ERROR_DEV_RAID1_MIN_NOT_MET;
goto out;
}
if ((all_avail & BTRFS_BLOCK_GROUP_RAID5) &&
root->fs_info->fs_devices->rw_devices <= 2) {
ret = BTRFS_ERROR_DEV_RAID5_MIN_NOT_MET;
goto out;
}
if ((all_avail & BTRFS_BLOCK_GROUP_RAID6) &&
root->fs_info->fs_devices->rw_devices <= 3) {
ret = BTRFS_ERROR_DEV_RAID6_MIN_NOT_MET;
goto out;
}
if (strcmp(device_path, "missing") == 0) {
struct list_head *devices;
struct btrfs_device *tmp;
device = NULL;
devices = &root->fs_info->fs_devices->devices;
list_for_each_entry(tmp, devices, dev_list) {
if (tmp->in_fs_metadata &&
!tmp->is_tgtdev_for_dev_replace &&
!tmp->bdev) {
device = tmp;
break;
}
}
bdev = NULL;
bh = NULL;
disk_super = NULL;
if (!device) {
ret = BTRFS_ERROR_DEV_MISSING_NOT_FOUND;
goto out;
}
} else {
ret = btrfs_get_bdev_and_sb(device_path,
FMODE_WRITE | FMODE_EXCL,
root->fs_info->bdev_holder, 0,
&bdev, &bh);
if (ret)
goto out;
disk_super = (struct btrfs_super_block *)bh->b_data;
devid = btrfs_stack_device_id(&disk_super->dev_item);
dev_uuid = disk_super->dev_item.uuid;
device = btrfs_find_device(root->fs_info, devid, dev_uuid,
disk_super->fsid);
if (!device) {
ret = -ENOENT;
goto error_brelse;
}
}
if (device->is_tgtdev_for_dev_replace) {
ret = BTRFS_ERROR_DEV_TGT_REPLACE;
goto error_brelse;
}
if (device->writeable && root->fs_info->fs_devices->rw_devices == 1) {
ret = BTRFS_ERROR_DEV_ONLY_WRITABLE;
goto error_brelse;
}
if (device->writeable) {
lock_chunks(root);
list_del_init(&device->dev_alloc_list);
unlock_chunks(root);
root->fs_info->fs_devices->rw_devices--;
clear_super = true;
}
mutex_unlock(&uuid_mutex);
ret = btrfs_shrink_device(device, 0);
mutex_lock(&uuid_mutex);
if (ret)
goto error_undo;
ret = btrfs_rm_dev_item(root->fs_info->chunk_root, device);
if (ret)
goto error_undo;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space = device->total_bytes -
device->bytes_used;
spin_unlock(&root->fs_info->free_chunk_lock);
device->in_fs_metadata = 0;
btrfs_scrub_cancel_dev(root->fs_info, device);
cur_devices = device->fs_devices;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
list_del_rcu(&device->dev_list);
device->fs_devices->num_devices--;
device->fs_devices->total_devices--;
if (device->missing)
root->fs_info->fs_devices->missing_devices--;
next_device = list_entry(root->fs_info->fs_devices->devices.next,
struct btrfs_device, dev_list);
if (device->bdev == root->fs_info->sb->s_bdev)
root->fs_info->sb->s_bdev = next_device->bdev;
if (device->bdev == root->fs_info->fs_devices->latest_bdev)
root->fs_info->fs_devices->latest_bdev = next_device->bdev;
if (device->bdev)
device->fs_devices->open_devices--;
call_rcu(&device->rcu, free_device);
num_devices = btrfs_super_num_devices(root->fs_info->super_copy) - 1;
btrfs_set_super_num_devices(root->fs_info->super_copy, num_devices);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
if (cur_devices->open_devices == 0) {
struct btrfs_fs_devices *fs_devices;
fs_devices = root->fs_info->fs_devices;
while (fs_devices) {
if (fs_devices->seed == cur_devices)
break;
fs_devices = fs_devices->seed;
}
fs_devices->seed = cur_devices->seed;
cur_devices->seed = NULL;
lock_chunks(root);
__btrfs_close_devices(cur_devices);
unlock_chunks(root);
free_fs_devices(cur_devices);
}
root->fs_info->num_tolerated_disk_barrier_failures =
btrfs_calc_num_tolerated_disk_barrier_failures(root->fs_info);
if (clear_super && disk_super) {
memset(&disk_super->magic, 0, sizeof(disk_super->magic));
set_buffer_dirty(bh);
sync_dirty_buffer(bh);
}
ret = 0;
if (bdev)
btrfs_kobject_uevent(bdev, KOBJ_CHANGE);
error_brelse:
brelse(bh);
if (bdev)
blkdev_put(bdev, FMODE_READ | FMODE_EXCL);
out:
mutex_unlock(&uuid_mutex);
return ret;
error_undo:
if (device->writeable) {
lock_chunks(root);
list_add(&device->dev_alloc_list,
&root->fs_info->fs_devices->alloc_list);
unlock_chunks(root);
root->fs_info->fs_devices->rw_devices++;
}
goto error_brelse;
}
void btrfs_rm_dev_replace_srcdev(struct btrfs_fs_info *fs_info,
struct btrfs_device *srcdev)
{
WARN_ON(!mutex_is_locked(&fs_info->fs_devices->device_list_mutex));
list_del_rcu(&srcdev->dev_list);
list_del_rcu(&srcdev->dev_alloc_list);
fs_info->fs_devices->num_devices--;
if (srcdev->missing) {
fs_info->fs_devices->missing_devices--;
fs_info->fs_devices->rw_devices++;
}
if (srcdev->can_discard)
fs_info->fs_devices->num_can_discard--;
if (srcdev->bdev) {
fs_info->fs_devices->open_devices--;
btrfs_scratch_superblock(srcdev);
}
call_rcu(&srcdev->rcu, free_device);
}
void btrfs_destroy_dev_replace_tgtdev(struct btrfs_fs_info *fs_info,
struct btrfs_device *tgtdev)
{
struct btrfs_device *next_device;
WARN_ON(!tgtdev);
mutex_lock(&fs_info->fs_devices->device_list_mutex);
if (tgtdev->bdev) {
btrfs_scratch_superblock(tgtdev);
fs_info->fs_devices->open_devices--;
}
fs_info->fs_devices->num_devices--;
if (tgtdev->can_discard)
fs_info->fs_devices->num_can_discard++;
next_device = list_entry(fs_info->fs_devices->devices.next,
struct btrfs_device, dev_list);
if (tgtdev->bdev == fs_info->sb->s_bdev)
fs_info->sb->s_bdev = next_device->bdev;
if (tgtdev->bdev == fs_info->fs_devices->latest_bdev)
fs_info->fs_devices->latest_bdev = next_device->bdev;
list_del_rcu(&tgtdev->dev_list);
call_rcu(&tgtdev->rcu, free_device);
mutex_unlock(&fs_info->fs_devices->device_list_mutex);
}
static int btrfs_find_device_by_path(struct btrfs_root *root, char *device_path,
struct btrfs_device **device)
{
int ret = 0;
struct btrfs_super_block *disk_super;
u64 devid;
u8 *dev_uuid;
struct block_device *bdev;
struct buffer_head *bh;
*device = NULL;
ret = btrfs_get_bdev_and_sb(device_path, FMODE_READ,
root->fs_info->bdev_holder, 0, &bdev, &bh);
if (ret)
return ret;
disk_super = (struct btrfs_super_block *)bh->b_data;
devid = btrfs_stack_device_id(&disk_super->dev_item);
dev_uuid = disk_super->dev_item.uuid;
*device = btrfs_find_device(root->fs_info, devid, dev_uuid,
disk_super->fsid);
brelse(bh);
if (!*device)
ret = -ENOENT;
blkdev_put(bdev, FMODE_READ);
return ret;
}
int btrfs_find_device_missing_or_by_path(struct btrfs_root *root,
char *device_path,
struct btrfs_device **device)
{
*device = NULL;
if (strcmp(device_path, "missing") == 0) {
struct list_head *devices;
struct btrfs_device *tmp;
devices = &root->fs_info->fs_devices->devices;
list_for_each_entry(tmp, devices, dev_list) {
if (tmp->in_fs_metadata && !tmp->bdev) {
*device = tmp;
break;
}
}
if (!*device) {
btrfs_err(root->fs_info, "no missing device found");
return -ENOENT;
}
return 0;
} else {
return btrfs_find_device_by_path(root, device_path, device);
}
}
static int btrfs_prepare_sprout(struct btrfs_root *root)
{
struct btrfs_fs_devices *fs_devices = root->fs_info->fs_devices;
struct btrfs_fs_devices *old_devices;
struct btrfs_fs_devices *seed_devices;
struct btrfs_super_block *disk_super = root->fs_info->super_copy;
struct btrfs_device *device;
u64 super_flags;
BUG_ON(!mutex_is_locked(&uuid_mutex));
if (!fs_devices->seeding)
return -EINVAL;
seed_devices = __alloc_fs_devices();
if (IS_ERR(seed_devices))
return PTR_ERR(seed_devices);
old_devices = clone_fs_devices(fs_devices);
if (IS_ERR(old_devices)) {
kfree(seed_devices);
return PTR_ERR(old_devices);
}
list_add(&old_devices->list, &fs_uuids);
memcpy(seed_devices, fs_devices, sizeof(*seed_devices));
seed_devices->opened = 1;
INIT_LIST_HEAD(&seed_devices->devices);
INIT_LIST_HEAD(&seed_devices->alloc_list);
mutex_init(&seed_devices->device_list_mutex);
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
list_splice_init_rcu(&fs_devices->devices, &seed_devices->devices,
synchronize_rcu);
list_splice_init(&fs_devices->alloc_list, &seed_devices->alloc_list);
list_for_each_entry(device, &seed_devices->devices, dev_list) {
device->fs_devices = seed_devices;
}
fs_devices->seeding = 0;
fs_devices->num_devices = 0;
fs_devices->open_devices = 0;
fs_devices->total_devices = 0;
fs_devices->seed = seed_devices;
generate_random_uuid(fs_devices->fsid);
memcpy(root->fs_info->fsid, fs_devices->fsid, BTRFS_FSID_SIZE);
memcpy(disk_super->fsid, fs_devices->fsid, BTRFS_FSID_SIZE);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
super_flags = btrfs_super_flags(disk_super) &
~BTRFS_SUPER_FLAG_SEEDING;
btrfs_set_super_flags(disk_super, super_flags);
return 0;
}
static int btrfs_finish_sprout(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_dev_item *dev_item;
struct btrfs_device *device;
struct btrfs_key key;
u8 fs_uuid[BTRFS_UUID_SIZE];
u8 dev_uuid[BTRFS_UUID_SIZE];
u64 devid;
int ret;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
root = root->fs_info->chunk_root;
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.offset = 0;
key.type = BTRFS_DEV_ITEM_KEY;
while (1) {
ret = btrfs_search_slot(trans, root, &key, path, 0, 1);
if (ret < 0)
goto error;
leaf = path->nodes[0];
next_slot:
if (path->slots[0] >= btrfs_header_nritems(leaf)) {
ret = btrfs_next_leaf(root, path);
if (ret > 0)
break;
if (ret < 0)
goto error;
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
btrfs_release_path(path);
continue;
}
btrfs_item_key_to_cpu(leaf, &key, path->slots[0]);
if (key.objectid != BTRFS_DEV_ITEMS_OBJECTID ||
key.type != BTRFS_DEV_ITEM_KEY)
break;
dev_item = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_dev_item);
devid = btrfs_device_id(leaf, dev_item);
read_extent_buffer(leaf, dev_uuid, btrfs_device_uuid(dev_item),
BTRFS_UUID_SIZE);
read_extent_buffer(leaf, fs_uuid, btrfs_device_fsid(dev_item),
BTRFS_UUID_SIZE);
device = btrfs_find_device(root->fs_info, devid, dev_uuid,
fs_uuid);
BUG_ON(!device);
if (device->fs_devices->seeding) {
btrfs_set_device_generation(leaf, dev_item,
device->generation);
btrfs_mark_buffer_dirty(leaf);
}
path->slots[0]++;
goto next_slot;
}
ret = 0;
error:
btrfs_free_path(path);
return ret;
}
int btrfs_init_new_device(struct btrfs_root *root, char *device_path)
{
struct request_queue *q;
struct btrfs_trans_handle *trans;
struct btrfs_device *device;
struct block_device *bdev;
struct list_head *devices;
struct super_block *sb = root->fs_info->sb;
struct rcu_string *name;
u64 total_bytes;
int seeding_dev = 0;
int ret = 0;
if ((sb->s_flags & MS_RDONLY) && !root->fs_info->fs_devices->seeding)
return -EROFS;
bdev = blkdev_get_by_path(device_path, FMODE_WRITE | FMODE_EXCL,
root->fs_info->bdev_holder);
if (IS_ERR(bdev))
return PTR_ERR(bdev);
if (root->fs_info->fs_devices->seeding) {
seeding_dev = 1;
down_write(&sb->s_umount);
mutex_lock(&uuid_mutex);
}
filemap_write_and_wait(bdev->bd_inode->i_mapping);
devices = &root->fs_info->fs_devices->devices;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
list_for_each_entry(device, devices, dev_list) {
if (device->bdev == bdev) {
ret = -EEXIST;
mutex_unlock(
&root->fs_info->fs_devices->device_list_mutex);
goto error;
}
}
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
device = btrfs_alloc_device(root->fs_info, NULL, NULL);
if (IS_ERR(device)) {
ret = PTR_ERR(device);
goto error;
}
name = rcu_string_strdup(device_path, GFP_NOFS);
if (!name) {
kfree(device);
ret = -ENOMEM;
goto error;
}
rcu_assign_pointer(device->name, name);
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
rcu_string_free(device->name);
kfree(device);
ret = PTR_ERR(trans);
goto error;
}
lock_chunks(root);
q = bdev_get_queue(bdev);
if (blk_queue_discard(q))
device->can_discard = 1;
device->writeable = 1;
device->generation = trans->transid;
device->io_width = root->sectorsize;
device->io_align = root->sectorsize;
device->sector_size = root->sectorsize;
device->total_bytes = i_size_read(bdev->bd_inode);
device->disk_total_bytes = device->total_bytes;
device->dev_root = root->fs_info->dev_root;
device->bdev = bdev;
device->in_fs_metadata = 1;
device->is_tgtdev_for_dev_replace = 0;
device->mode = FMODE_EXCL;
device->dev_stats_valid = 1;
set_blocksize(device->bdev, 4096);
if (seeding_dev) {
sb->s_flags &= ~MS_RDONLY;
ret = btrfs_prepare_sprout(root);
BUG_ON(ret);
}
device->fs_devices = root->fs_info->fs_devices;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
list_add_rcu(&device->dev_list, &root->fs_info->fs_devices->devices);
list_add(&device->dev_alloc_list,
&root->fs_info->fs_devices->alloc_list);
root->fs_info->fs_devices->num_devices++;
root->fs_info->fs_devices->open_devices++;
root->fs_info->fs_devices->rw_devices++;
root->fs_info->fs_devices->total_devices++;
if (device->can_discard)
root->fs_info->fs_devices->num_can_discard++;
root->fs_info->fs_devices->total_rw_bytes += device->total_bytes;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space += device->total_bytes;
spin_unlock(&root->fs_info->free_chunk_lock);
if (!blk_queue_nonrot(bdev_get_queue(bdev)))
root->fs_info->fs_devices->rotating = 1;
total_bytes = btrfs_super_total_bytes(root->fs_info->super_copy);
btrfs_set_super_total_bytes(root->fs_info->super_copy,
total_bytes + device->total_bytes);
total_bytes = btrfs_super_num_devices(root->fs_info->super_copy);
btrfs_set_super_num_devices(root->fs_info->super_copy,
total_bytes + 1);
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
if (seeding_dev) {
ret = init_first_rw_device(trans, root, device);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
goto error_trans;
}
ret = btrfs_finish_sprout(trans, root);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
goto error_trans;
}
} else {
ret = btrfs_add_device(trans, root, device);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
goto error_trans;
}
}
btrfs_clear_space_info_full(root->fs_info);
unlock_chunks(root);
root->fs_info->num_tolerated_disk_barrier_failures =
btrfs_calc_num_tolerated_disk_barrier_failures(root->fs_info);
ret = btrfs_commit_transaction(trans, root);
if (seeding_dev) {
mutex_unlock(&uuid_mutex);
up_write(&sb->s_umount);
if (ret)
return ret;
ret = btrfs_relocate_sys_chunks(root);
if (ret < 0)
btrfs_error(root->fs_info, ret,
"Failed to relocate sys chunks after "
"device initialization. This can be fixed "
"using the \"btrfs balance\" command.");
trans = btrfs_attach_transaction(root);
if (IS_ERR(trans)) {
if (PTR_ERR(trans) == -ENOENT)
return 0;
return PTR_ERR(trans);
}
ret = btrfs_commit_transaction(trans, root);
}
return ret;
error_trans:
unlock_chunks(root);
btrfs_end_transaction(trans, root);
rcu_string_free(device->name);
kfree(device);
error:
blkdev_put(bdev, FMODE_EXCL);
if (seeding_dev) {
mutex_unlock(&uuid_mutex);
up_write(&sb->s_umount);
}
return ret;
}
int btrfs_init_dev_replace_tgtdev(struct btrfs_root *root, char *device_path,
struct btrfs_device **device_out)
{
struct request_queue *q;
struct btrfs_device *device;
struct block_device *bdev;
struct btrfs_fs_info *fs_info = root->fs_info;
struct list_head *devices;
struct rcu_string *name;
u64 devid = BTRFS_DEV_REPLACE_DEVID;
int ret = 0;
*device_out = NULL;
if (fs_info->fs_devices->seeding)
return -EINVAL;
bdev = blkdev_get_by_path(device_path, FMODE_WRITE | FMODE_EXCL,
fs_info->bdev_holder);
if (IS_ERR(bdev))
return PTR_ERR(bdev);
filemap_write_and_wait(bdev->bd_inode->i_mapping);
devices = &fs_info->fs_devices->devices;
list_for_each_entry(device, devices, dev_list) {
if (device->bdev == bdev) {
ret = -EEXIST;
goto error;
}
}
device = btrfs_alloc_device(NULL, &devid, NULL);
if (IS_ERR(device)) {
ret = PTR_ERR(device);
goto error;
}
name = rcu_string_strdup(device_path, GFP_NOFS);
if (!name) {
kfree(device);
ret = -ENOMEM;
goto error;
}
rcu_assign_pointer(device->name, name);
q = bdev_get_queue(bdev);
if (blk_queue_discard(q))
device->can_discard = 1;
mutex_lock(&root->fs_info->fs_devices->device_list_mutex);
device->writeable = 1;
device->generation = 0;
device->io_width = root->sectorsize;
device->io_align = root->sectorsize;
device->sector_size = root->sectorsize;
device->total_bytes = i_size_read(bdev->bd_inode);
device->disk_total_bytes = device->total_bytes;
device->dev_root = fs_info->dev_root;
device->bdev = bdev;
device->in_fs_metadata = 1;
device->is_tgtdev_for_dev_replace = 1;
device->mode = FMODE_EXCL;
device->dev_stats_valid = 1;
set_blocksize(device->bdev, 4096);
device->fs_devices = fs_info->fs_devices;
list_add(&device->dev_list, &fs_info->fs_devices->devices);
fs_info->fs_devices->num_devices++;
fs_info->fs_devices->open_devices++;
if (device->can_discard)
fs_info->fs_devices->num_can_discard++;
mutex_unlock(&root->fs_info->fs_devices->device_list_mutex);
*device_out = device;
return ret;
error:
blkdev_put(bdev, FMODE_EXCL);
return ret;
}
void btrfs_init_dev_replace_tgtdev_for_resume(struct btrfs_fs_info *fs_info,
struct btrfs_device *tgtdev)
{
WARN_ON(fs_info->fs_devices->rw_devices == 0);
tgtdev->io_width = fs_info->dev_root->sectorsize;
tgtdev->io_align = fs_info->dev_root->sectorsize;
tgtdev->sector_size = fs_info->dev_root->sectorsize;
tgtdev->dev_root = fs_info->dev_root;
tgtdev->in_fs_metadata = 1;
}
static noinline int btrfs_update_device(struct btrfs_trans_handle *trans,
struct btrfs_device *device)
{
int ret;
struct btrfs_path *path;
struct btrfs_root *root;
struct btrfs_dev_item *dev_item;
struct extent_buffer *leaf;
struct btrfs_key key;
root = device->dev_root->fs_info->chunk_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.type = BTRFS_DEV_ITEM_KEY;
key.offset = device->devid;
ret = btrfs_search_slot(trans, root, &key, path, 0, 1);
if (ret < 0)
goto out;
if (ret > 0) {
ret = -ENOENT;
goto out;
}
leaf = path->nodes[0];
dev_item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_dev_item);
btrfs_set_device_id(leaf, dev_item, device->devid);
btrfs_set_device_type(leaf, dev_item, device->type);
btrfs_set_device_io_align(leaf, dev_item, device->io_align);
btrfs_set_device_io_width(leaf, dev_item, device->io_width);
btrfs_set_device_sector_size(leaf, dev_item, device->sector_size);
btrfs_set_device_total_bytes(leaf, dev_item, device->disk_total_bytes);
btrfs_set_device_bytes_used(leaf, dev_item, device->bytes_used);
btrfs_mark_buffer_dirty(leaf);
out:
btrfs_free_path(path);
return ret;
}
static int __btrfs_grow_device(struct btrfs_trans_handle *trans,
struct btrfs_device *device, u64 new_size)
{
struct btrfs_super_block *super_copy =
device->dev_root->fs_info->super_copy;
u64 old_total = btrfs_super_total_bytes(super_copy);
u64 diff = new_size - device->total_bytes;
if (!device->writeable)
return -EACCES;
if (new_size <= device->total_bytes ||
device->is_tgtdev_for_dev_replace)
return -EINVAL;
btrfs_set_super_total_bytes(super_copy, old_total + diff);
device->fs_devices->total_rw_bytes += diff;
device->total_bytes = new_size;
device->disk_total_bytes = new_size;
btrfs_clear_space_info_full(device->dev_root->fs_info);
return btrfs_update_device(trans, device);
}
int btrfs_grow_device(struct btrfs_trans_handle *trans,
struct btrfs_device *device, u64 new_size)
{
int ret;
lock_chunks(device->dev_root);
ret = __btrfs_grow_device(trans, device, new_size);
unlock_chunks(device->dev_root);
return ret;
}
static int btrfs_free_chunk(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
u64 chunk_tree, u64 chunk_objectid,
u64 chunk_offset)
{
int ret;
struct btrfs_path *path;
struct btrfs_key key;
root = root->fs_info->chunk_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = chunk_objectid;
key.offset = chunk_offset;
key.type = BTRFS_CHUNK_ITEM_KEY;
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret < 0)
goto out;
else if (ret > 0) {
btrfs_error(root->fs_info, -ENOENT,
"Failed lookup while freeing chunk.");
ret = -ENOENT;
goto out;
}
ret = btrfs_del_item(trans, root, path);
if (ret < 0)
btrfs_error(root->fs_info, ret,
"Failed to delete chunk item.");
out:
btrfs_free_path(path);
return ret;
}
static int btrfs_del_sys_chunk(struct btrfs_root *root, u64 chunk_objectid, u64
chunk_offset)
{
struct btrfs_super_block *super_copy = root->fs_info->super_copy;
struct btrfs_disk_key *disk_key;
struct btrfs_chunk *chunk;
u8 *ptr;
int ret = 0;
u32 num_stripes;
u32 array_size;
u32 len = 0;
u32 cur;
struct btrfs_key key;
array_size = btrfs_super_sys_array_size(super_copy);
ptr = super_copy->sys_chunk_array;
cur = 0;
while (cur < array_size) {
disk_key = (struct btrfs_disk_key *)ptr;
btrfs_disk_key_to_cpu(&key, disk_key);
len = sizeof(*disk_key);
if (key.type == BTRFS_CHUNK_ITEM_KEY) {
chunk = (struct btrfs_chunk *)(ptr + len);
num_stripes = btrfs_stack_chunk_num_stripes(chunk);
len += btrfs_chunk_item_size(num_stripes);
} else {
ret = -EIO;
break;
}
if (key.objectid == chunk_objectid &&
key.offset == chunk_offset) {
memmove(ptr, ptr + len, array_size - (cur + len));
array_size -= len;
btrfs_set_super_sys_array_size(super_copy, array_size);
} else {
ptr += len;
cur += len;
}
}
return ret;
}
static int btrfs_relocate_chunk(struct btrfs_root *root,
u64 chunk_tree, u64 chunk_objectid,
u64 chunk_offset)
{
struct extent_map_tree *em_tree;
struct btrfs_root *extent_root;
struct btrfs_trans_handle *trans;
struct extent_map *em;
struct map_lookup *map;
int ret;
int i;
root = root->fs_info->chunk_root;
extent_root = root->fs_info->extent_root;
em_tree = &root->fs_info->mapping_tree.map_tree;
ret = btrfs_can_relocate(extent_root, chunk_offset);
if (ret)
return -ENOSPC;
ret = btrfs_relocate_block_group(extent_root, chunk_offset);
if (ret)
return ret;
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
ret = PTR_ERR(trans);
btrfs_std_error(root->fs_info, ret);
return ret;
}
lock_chunks(root);
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, chunk_offset, 1);
read_unlock(&em_tree->lock);
BUG_ON(!em || em->start > chunk_offset ||
em->start + em->len < chunk_offset);
map = (struct map_lookup *)em->bdev;
for (i = 0; i < map->num_stripes; i++) {
ret = btrfs_free_dev_extent(trans, map->stripes[i].dev,
map->stripes[i].physical);
BUG_ON(ret);
if (map->stripes[i].dev) {
ret = btrfs_update_device(trans, map->stripes[i].dev);
BUG_ON(ret);
}
}
ret = btrfs_free_chunk(trans, root, chunk_tree, chunk_objectid,
chunk_offset);
BUG_ON(ret);
trace_btrfs_chunk_free(root, map, chunk_offset, em->len);
if (map->type & BTRFS_BLOCK_GROUP_SYSTEM) {
ret = btrfs_del_sys_chunk(root, chunk_objectid, chunk_offset);
BUG_ON(ret);
}
ret = btrfs_remove_block_group(trans, extent_root, chunk_offset);
BUG_ON(ret);
write_lock(&em_tree->lock);
remove_extent_mapping(em_tree, em);
write_unlock(&em_tree->lock);
kfree(map);
em->bdev = NULL;
free_extent_map(em);
free_extent_map(em);
unlock_chunks(root);
btrfs_end_transaction(trans, root);
return 0;
}
static int btrfs_relocate_sys_chunks(struct btrfs_root *root)
{
struct btrfs_root *chunk_root = root->fs_info->chunk_root;
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_chunk *chunk;
struct btrfs_key key;
struct btrfs_key found_key;
u64 chunk_tree = chunk_root->root_key.objectid;
u64 chunk_type;
bool retried = false;
int failed = 0;
int ret;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
again:
key.objectid = BTRFS_FIRST_CHUNK_TREE_OBJECTID;
key.offset = (u64)-1;
key.type = BTRFS_CHUNK_ITEM_KEY;
while (1) {
ret = btrfs_search_slot(NULL, chunk_root, &key, path, 0, 0);
if (ret < 0)
goto error;
BUG_ON(ret == 0);
ret = btrfs_previous_item(chunk_root, path, key.objectid,
key.type);
if (ret < 0)
goto error;
if (ret > 0)
break;
leaf = path->nodes[0];
btrfs_item_key_to_cpu(leaf, &found_key, path->slots[0]);
chunk = btrfs_item_ptr(leaf, path->slots[0],
struct btrfs_chunk);
chunk_type = btrfs_chunk_type(leaf, chunk);
btrfs_release_path(path);
if (chunk_type & BTRFS_BLOCK_GROUP_SYSTEM) {
ret = btrfs_relocate_chunk(chunk_root, chunk_tree,
found_key.objectid,
found_key.offset);
if (ret == -ENOSPC)
failed++;
else if (ret)
BUG();
}
if (found_key.offset == 0)
break;
key.offset = found_key.offset - 1;
}
ret = 0;
if (failed && !retried) {
failed = 0;
retried = true;
goto again;
} else if (WARN_ON(failed && retried)) {
ret = -ENOSPC;
}
error:
btrfs_free_path(path);
return ret;
}
static int insert_balance_item(struct btrfs_root *root,
struct btrfs_balance_control *bctl)
{
struct btrfs_trans_handle *trans;
struct btrfs_balance_item *item;
struct btrfs_disk_balance_args disk_bargs;
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_key key;
int ret, err;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
btrfs_free_path(path);
return PTR_ERR(trans);
}
key.objectid = BTRFS_BALANCE_OBJECTID;
key.type = BTRFS_BALANCE_ITEM_KEY;
key.offset = 0;
ret = btrfs_insert_empty_item(trans, root, path, &key,
sizeof(*item));
if (ret)
goto out;
leaf = path->nodes[0];
item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_balance_item);
memset_extent_buffer(leaf, 0, (unsigned long)item, sizeof(*item));
btrfs_cpu_balance_args_to_disk(&disk_bargs, &bctl->data);
btrfs_set_balance_data(leaf, item, &disk_bargs);
btrfs_cpu_balance_args_to_disk(&disk_bargs, &bctl->meta);
btrfs_set_balance_meta(leaf, item, &disk_bargs);
btrfs_cpu_balance_args_to_disk(&disk_bargs, &bctl->sys);
btrfs_set_balance_sys(leaf, item, &disk_bargs);
btrfs_set_balance_flags(leaf, item, bctl->flags);
btrfs_mark_buffer_dirty(leaf);
out:
btrfs_free_path(path);
err = btrfs_commit_transaction(trans, root);
if (err && !ret)
ret = err;
return ret;
}
static int del_balance_item(struct btrfs_root *root)
{
struct btrfs_trans_handle *trans;
struct btrfs_path *path;
struct btrfs_key key;
int ret, err;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
btrfs_free_path(path);
return PTR_ERR(trans);
}
key.objectid = BTRFS_BALANCE_OBJECTID;
key.type = BTRFS_BALANCE_ITEM_KEY;
key.offset = 0;
ret = btrfs_search_slot(trans, root, &key, path, -1, 1);
if (ret < 0)
goto out;
if (ret > 0) {
ret = -ENOENT;
goto out;
}
ret = btrfs_del_item(trans, root, path);
out:
btrfs_free_path(path);
err = btrfs_commit_transaction(trans, root);
if (err && !ret)
ret = err;
return ret;
}
static void update_balance_args(struct btrfs_balance_control *bctl)
{
if (bctl->data.flags & BTRFS_BALANCE_ARGS_CONVERT)
bctl->data.flags |= BTRFS_BALANCE_ARGS_SOFT;
if (bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT)
bctl->sys.flags |= BTRFS_BALANCE_ARGS_SOFT;
if (bctl->meta.flags & BTRFS_BALANCE_ARGS_CONVERT)
bctl->meta.flags |= BTRFS_BALANCE_ARGS_SOFT;
if (!(bctl->data.flags & BTRFS_BALANCE_ARGS_USAGE) &&
!(bctl->data.flags & BTRFS_BALANCE_ARGS_CONVERT)) {
bctl->data.flags |= BTRFS_BALANCE_ARGS_USAGE;
bctl->data.usage = 90;
}
if (!(bctl->sys.flags & BTRFS_BALANCE_ARGS_USAGE) &&
!(bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT)) {
bctl->sys.flags |= BTRFS_BALANCE_ARGS_USAGE;
bctl->sys.usage = 90;
}
if (!(bctl->meta.flags & BTRFS_BALANCE_ARGS_USAGE) &&
!(bctl->meta.flags & BTRFS_BALANCE_ARGS_CONVERT)) {
bctl->meta.flags |= BTRFS_BALANCE_ARGS_USAGE;
bctl->meta.usage = 90;
}
}
static void set_balance_control(struct btrfs_balance_control *bctl)
{
struct btrfs_fs_info *fs_info = bctl->fs_info;
BUG_ON(fs_info->balance_ctl);
spin_lock(&fs_info->balance_lock);
fs_info->balance_ctl = bctl;
spin_unlock(&fs_info->balance_lock);
}
static void unset_balance_control(struct btrfs_fs_info *fs_info)
{
struct btrfs_balance_control *bctl = fs_info->balance_ctl;
BUG_ON(!fs_info->balance_ctl);
spin_lock(&fs_info->balance_lock);
fs_info->balance_ctl = NULL;
spin_unlock(&fs_info->balance_lock);
kfree(bctl);
}
static int chunk_profiles_filter(u64 chunk_type,
struct btrfs_balance_args *bargs)
{
chunk_type = chunk_to_extended(chunk_type) &
BTRFS_EXTENDED_PROFILE_MASK;
if (bargs->profiles & chunk_type)
return 0;
return 1;
}
static int chunk_usage_filter(struct btrfs_fs_info *fs_info, u64 chunk_offset,
struct btrfs_balance_args *bargs)
{
struct btrfs_block_group_cache *cache;
u64 chunk_used, user_thresh;
int ret = 1;
cache = btrfs_lookup_block_group(fs_info, chunk_offset);
chunk_used = btrfs_block_group_used(&cache->item);
if (bargs->usage == 0)
user_thresh = 1;
else if (bargs->usage > 100)
user_thresh = cache->key.offset;
else
user_thresh = div_factor_fine(cache->key.offset,
bargs->usage);
if (chunk_used < user_thresh)
ret = 0;
btrfs_put_block_group(cache);
return ret;
}
static int chunk_devid_filter(struct extent_buffer *leaf,
struct btrfs_chunk *chunk,
struct btrfs_balance_args *bargs)
{
struct btrfs_stripe *stripe;
int num_stripes = btrfs_chunk_num_stripes(leaf, chunk);
int i;
for (i = 0; i < num_stripes; i++) {
stripe = btrfs_stripe_nr(chunk, i);
if (btrfs_stripe_devid(leaf, stripe) == bargs->devid)
return 0;
}
return 1;
}
static int chunk_drange_filter(struct extent_buffer *leaf,
struct btrfs_chunk *chunk,
u64 chunk_offset,
struct btrfs_balance_args *bargs)
{
struct btrfs_stripe *stripe;
int num_stripes = btrfs_chunk_num_stripes(leaf, chunk);
u64 stripe_offset;
u64 stripe_length;
int factor;
int i;
if (!(bargs->flags & BTRFS_BALANCE_ARGS_DEVID))
return 0;
if (btrfs_chunk_type(leaf, chunk) & (BTRFS_BLOCK_GROUP_DUP |
BTRFS_BLOCK_GROUP_RAID1 | BTRFS_BLOCK_GROUP_RAID10)) {
factor = num_stripes / 2;
} else if (btrfs_chunk_type(leaf, chunk) & BTRFS_BLOCK_GROUP_RAID5) {
factor = num_stripes - 1;
} else if (btrfs_chunk_type(leaf, chunk) & BTRFS_BLOCK_GROUP_RAID6) {
factor = num_stripes - 2;
} else {
factor = num_stripes;
}
for (i = 0; i < num_stripes; i++) {
stripe = btrfs_stripe_nr(chunk, i);
if (btrfs_stripe_devid(leaf, stripe) != bargs->devid)
continue;
stripe_offset = btrfs_stripe_offset(leaf, stripe);
stripe_length = btrfs_chunk_length(leaf, chunk);
do_div(stripe_length, factor);
if (stripe_offset < bargs->pend &&
stripe_offset + stripe_length > bargs->pstart)
return 0;
}
return 1;
}
static int chunk_vrange_filter(struct extent_buffer *leaf,
struct btrfs_chunk *chunk,
u64 chunk_offset,
struct btrfs_balance_args *bargs)
{
if (chunk_offset < bargs->vend &&
chunk_offset + btrfs_chunk_length(leaf, chunk) > bargs->vstart)
return 0;
return 1;
}
static int chunk_soft_convert_filter(u64 chunk_type,
struct btrfs_balance_args *bargs)
{
if (!(bargs->flags & BTRFS_BALANCE_ARGS_CONVERT))
return 0;
chunk_type = chunk_to_extended(chunk_type) &
BTRFS_EXTENDED_PROFILE_MASK;
if (bargs->target == chunk_type)
return 1;
return 0;
}
static int should_balance_chunk(struct btrfs_root *root,
struct extent_buffer *leaf,
struct btrfs_chunk *chunk, u64 chunk_offset)
{
struct btrfs_balance_control *bctl = root->fs_info->balance_ctl;
struct btrfs_balance_args *bargs = NULL;
u64 chunk_type = btrfs_chunk_type(leaf, chunk);
if (!((chunk_type & BTRFS_BLOCK_GROUP_TYPE_MASK) &
(bctl->flags & BTRFS_BALANCE_TYPE_MASK))) {
return 0;
}
if (chunk_type & BTRFS_BLOCK_GROUP_DATA)
bargs = &bctl->data;
else if (chunk_type & BTRFS_BLOCK_GROUP_SYSTEM)
bargs = &bctl->sys;
else if (chunk_type & BTRFS_BLOCK_GROUP_METADATA)
bargs = &bctl->meta;
if ((bargs->flags & BTRFS_BALANCE_ARGS_PROFILES) &&
chunk_profiles_filter(chunk_type, bargs)) {
return 0;
}
if ((bargs->flags & BTRFS_BALANCE_ARGS_USAGE) &&
chunk_usage_filter(bctl->fs_info, chunk_offset, bargs)) {
return 0;
}
if ((bargs->flags & BTRFS_BALANCE_ARGS_DEVID) &&
chunk_devid_filter(leaf, chunk, bargs)) {
return 0;
}
if ((bargs->flags & BTRFS_BALANCE_ARGS_DRANGE) &&
chunk_drange_filter(leaf, chunk, chunk_offset, bargs)) {
return 0;
}
if ((bargs->flags & BTRFS_BALANCE_ARGS_VRANGE) &&
chunk_vrange_filter(leaf, chunk, chunk_offset, bargs)) {
return 0;
}
if ((bargs->flags & BTRFS_BALANCE_ARGS_SOFT) &&
chunk_soft_convert_filter(chunk_type, bargs)) {
return 0;
}
return 1;
}
static int __btrfs_balance(struct btrfs_fs_info *fs_info)
{
struct btrfs_balance_control *bctl = fs_info->balance_ctl;
struct btrfs_root *chunk_root = fs_info->chunk_root;
struct btrfs_root *dev_root = fs_info->dev_root;
struct list_head *devices;
struct btrfs_device *device;
u64 old_size;
u64 size_to_free;
struct btrfs_chunk *chunk;
struct btrfs_path *path;
struct btrfs_key key;
struct btrfs_key found_key;
struct btrfs_trans_handle *trans;
struct extent_buffer *leaf;
int slot;
int ret;
int enospc_errors = 0;
bool counting = true;
devices = &fs_info->fs_devices->devices;
list_for_each_entry(device, devices, dev_list) {
old_size = device->total_bytes;
size_to_free = div_factor(old_size, 1);
size_to_free = min(size_to_free, (u64)1 * 1024 * 1024);
if (!device->writeable ||
device->total_bytes - device->bytes_used > size_to_free ||
device->is_tgtdev_for_dev_replace)
continue;
ret = btrfs_shrink_device(device, old_size - size_to_free);
if (ret == -ENOSPC)
break;
BUG_ON(ret);
trans = btrfs_start_transaction(dev_root, 0);
BUG_ON(IS_ERR(trans));
ret = btrfs_grow_device(trans, device, old_size);
BUG_ON(ret);
btrfs_end_transaction(trans, dev_root);
}
path = btrfs_alloc_path();
if (!path) {
ret = -ENOMEM;
goto error;
}
spin_lock(&fs_info->balance_lock);
memset(&bctl->stat, 0, sizeof(bctl->stat));
spin_unlock(&fs_info->balance_lock);
again:
key.objectid = BTRFS_FIRST_CHUNK_TREE_OBJECTID;
key.offset = (u64)-1;
key.type = BTRFS_CHUNK_ITEM_KEY;
while (1) {
if ((!counting && atomic_read(&fs_info->balance_pause_req)) ||
atomic_read(&fs_info->balance_cancel_req)) {
ret = -ECANCELED;
goto error;
}
ret = btrfs_search_slot(NULL, chunk_root, &key, path, 0, 0);
if (ret < 0)
goto error;
if (ret == 0)
BUG();
ret = btrfs_previous_item(chunk_root, path, 0,
BTRFS_CHUNK_ITEM_KEY);
if (ret) {
ret = 0;
break;
}
leaf = path->nodes[0];
slot = path->slots[0];
btrfs_item_key_to_cpu(leaf, &found_key, slot);
if (found_key.objectid != key.objectid)
break;
chunk = btrfs_item_ptr(leaf, slot, struct btrfs_chunk);
if (!counting) {
spin_lock(&fs_info->balance_lock);
bctl->stat.considered++;
spin_unlock(&fs_info->balance_lock);
}
ret = should_balance_chunk(chunk_root, leaf, chunk,
found_key.offset);
btrfs_release_path(path);
if (!ret)
goto loop;
if (counting) {
spin_lock(&fs_info->balance_lock);
bctl->stat.expected++;
spin_unlock(&fs_info->balance_lock);
goto loop;
}
ret = btrfs_relocate_chunk(chunk_root,
chunk_root->root_key.objectid,
found_key.objectid,
found_key.offset);
if (ret && ret != -ENOSPC)
goto error;
if (ret == -ENOSPC) {
enospc_errors++;
} else {
spin_lock(&fs_info->balance_lock);
bctl->stat.completed++;
spin_unlock(&fs_info->balance_lock);
}
loop:
if (found_key.offset == 0)
break;
key.offset = found_key.offset - 1;
}
if (counting) {
btrfs_release_path(path);
counting = false;
goto again;
}
error:
btrfs_free_path(path);
if (enospc_errors) {
btrfs_info(fs_info, "%d enospc errors during balance",
enospc_errors);
if (!ret)
ret = -ENOSPC;
}
return ret;
}
static int alloc_profile_is_valid(u64 flags, int extended)
{
u64 mask = (extended ? BTRFS_EXTENDED_PROFILE_MASK :
BTRFS_BLOCK_GROUP_PROFILE_MASK);
flags &= ~BTRFS_BLOCK_GROUP_TYPE_MASK;
if (flags & ~mask)
return 0;
if (flags == 0)
return !extended;
return (flags & (flags - 1)) == 0;
}
static inline int balance_need_close(struct btrfs_fs_info *fs_info)
{
return atomic_read(&fs_info->balance_cancel_req) ||
(atomic_read(&fs_info->balance_pause_req) == 0 &&
atomic_read(&fs_info->balance_cancel_req) == 0);
}
static void __cancel_balance(struct btrfs_fs_info *fs_info)
{
int ret;
unset_balance_control(fs_info);
ret = del_balance_item(fs_info->tree_root);
if (ret)
btrfs_std_error(fs_info, ret);
atomic_set(&fs_info->mutually_exclusive_operation_running, 0);
}
int btrfs_balance(struct btrfs_balance_control *bctl,
struct btrfs_ioctl_balance_args *bargs)
{
struct btrfs_fs_info *fs_info = bctl->fs_info;
u64 allowed;
int mixed = 0;
int ret;
u64 num_devices;
unsigned seq;
if (btrfs_fs_closing(fs_info) ||
atomic_read(&fs_info->balance_pause_req) ||
atomic_read(&fs_info->balance_cancel_req)) {
ret = -EINVAL;
goto out;
}
allowed = btrfs_super_incompat_flags(fs_info->super_copy);
if (allowed & BTRFS_FEATURE_INCOMPAT_MIXED_GROUPS)
mixed = 1;
allowed = BTRFS_BALANCE_DATA | BTRFS_BALANCE_METADATA;
if (mixed && (bctl->flags & allowed)) {
if (!(bctl->flags & BTRFS_BALANCE_DATA) ||
!(bctl->flags & BTRFS_BALANCE_METADATA) ||
memcmp(&bctl->data, &bctl->meta, sizeof(bctl->data))) {
btrfs_err(fs_info, "with mixed groups data and "
"metadata balance options must be the same");
ret = -EINVAL;
goto out;
}
}
num_devices = fs_info->fs_devices->num_devices;
btrfs_dev_replace_lock(&fs_info->dev_replace);
if (btrfs_dev_replace_is_ongoing(&fs_info->dev_replace)) {
BUG_ON(num_devices < 1);
num_devices--;
}
btrfs_dev_replace_unlock(&fs_info->dev_replace);
allowed = BTRFS_AVAIL_ALLOC_BIT_SINGLE;
if (num_devices == 1)
allowed |= BTRFS_BLOCK_GROUP_DUP;
else if (num_devices > 1)
allowed |= (BTRFS_BLOCK_GROUP_RAID0 | BTRFS_BLOCK_GROUP_RAID1);
if (num_devices > 2)
allowed |= BTRFS_BLOCK_GROUP_RAID5;
if (num_devices > 3)
allowed |= (BTRFS_BLOCK_GROUP_RAID10 |
BTRFS_BLOCK_GROUP_RAID6);
if ((bctl->data.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(!alloc_profile_is_valid(bctl->data.target, 1) ||
(bctl->data.target & ~allowed))) {
btrfs_err(fs_info, "unable to start balance with target "
"data profile %llu",
bctl->data.target);
ret = -EINVAL;
goto out;
}
if ((bctl->meta.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(!alloc_profile_is_valid(bctl->meta.target, 1) ||
(bctl->meta.target & ~allowed))) {
btrfs_err(fs_info,
"unable to start balance with target metadata profile %llu",
bctl->meta.target);
ret = -EINVAL;
goto out;
}
if ((bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(!alloc_profile_is_valid(bctl->sys.target, 1) ||
(bctl->sys.target & ~allowed))) {
btrfs_err(fs_info,
"unable to start balance with target system profile %llu",
bctl->sys.target);
ret = -EINVAL;
goto out;
}
if (!mixed && (bctl->data.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(bctl->data.target & BTRFS_BLOCK_GROUP_DUP)) {
btrfs_err(fs_info, "dup for data is not allowed");
ret = -EINVAL;
goto out;
}
allowed = BTRFS_BLOCK_GROUP_DUP | BTRFS_BLOCK_GROUP_RAID1 |
BTRFS_BLOCK_GROUP_RAID10 |
BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_RAID6;
do {
seq = read_seqbegin(&fs_info->profiles_lock);
if (((bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(fs_info->avail_system_alloc_bits & allowed) &&
!(bctl->sys.target & allowed)) ||
((bctl->meta.flags & BTRFS_BALANCE_ARGS_CONVERT) &&
(fs_info->avail_metadata_alloc_bits & allowed) &&
!(bctl->meta.target & allowed))) {
if (bctl->flags & BTRFS_BALANCE_FORCE) {
btrfs_info(fs_info, "force reducing metadata integrity");
} else {
btrfs_err(fs_info, "balance will reduce metadata "
"integrity, use force if you want this");
ret = -EINVAL;
goto out;
}
}
} while (read_seqretry(&fs_info->profiles_lock, seq));
if (bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT) {
int num_tolerated_disk_barrier_failures;
u64 target = bctl->sys.target;
num_tolerated_disk_barrier_failures =
btrfs_calc_num_tolerated_disk_barrier_failures(fs_info);
if (num_tolerated_disk_barrier_failures > 0 &&
(target &
(BTRFS_BLOCK_GROUP_DUP | BTRFS_BLOCK_GROUP_RAID0 |
BTRFS_AVAIL_ALLOC_BIT_SINGLE)))
num_tolerated_disk_barrier_failures = 0;
else if (num_tolerated_disk_barrier_failures > 1 &&
(target &
(BTRFS_BLOCK_GROUP_RAID1 | BTRFS_BLOCK_GROUP_RAID10)))
num_tolerated_disk_barrier_failures = 1;
fs_info->num_tolerated_disk_barrier_failures =
num_tolerated_disk_barrier_failures;
}
ret = insert_balance_item(fs_info->tree_root, bctl);
if (ret && ret != -EEXIST)
goto out;
if (!(bctl->flags & BTRFS_BALANCE_RESUME)) {
BUG_ON(ret == -EEXIST);
set_balance_control(bctl);
} else {
BUG_ON(ret != -EEXIST);
spin_lock(&fs_info->balance_lock);
update_balance_args(bctl);
spin_unlock(&fs_info->balance_lock);
}
atomic_inc(&fs_info->balance_running);
mutex_unlock(&fs_info->balance_mutex);
ret = __btrfs_balance(fs_info);
mutex_lock(&fs_info->balance_mutex);
atomic_dec(&fs_info->balance_running);
if (bctl->sys.flags & BTRFS_BALANCE_ARGS_CONVERT) {
fs_info->num_tolerated_disk_barrier_failures =
btrfs_calc_num_tolerated_disk_barrier_failures(fs_info);
}
if (bargs) {
memset(bargs, 0, sizeof(*bargs));
update_ioctl_balance_args(fs_info, 0, bargs);
}
if ((ret && ret != -ECANCELED && ret != -ENOSPC) ||
balance_need_close(fs_info)) {
__cancel_balance(fs_info);
}
wake_up(&fs_info->balance_wait_q);
return ret;
out:
if (bctl->flags & BTRFS_BALANCE_RESUME)
__cancel_balance(fs_info);
else {
kfree(bctl);
atomic_set(&fs_info->mutually_exclusive_operation_running, 0);
}
return ret;
}
static int balance_kthread(void *data)
{
struct btrfs_fs_info *fs_info = data;
int ret = 0;
mutex_lock(&fs_info->volume_mutex);
mutex_lock(&fs_info->balance_mutex);
if (fs_info->balance_ctl) {
btrfs_info(fs_info, "continuing balance");
ret = btrfs_balance(fs_info->balance_ctl, NULL);
}
mutex_unlock(&fs_info->balance_mutex);
mutex_unlock(&fs_info->volume_mutex);
return ret;
}
int btrfs_resume_balance_async(struct btrfs_fs_info *fs_info)
{
struct task_struct *tsk;
spin_lock(&fs_info->balance_lock);
if (!fs_info->balance_ctl) {
spin_unlock(&fs_info->balance_lock);
return 0;
}
spin_unlock(&fs_info->balance_lock);
if (btrfs_test_opt(fs_info->tree_root, SKIP_BALANCE)) {
btrfs_info(fs_info, "force skipping balance");
return 0;
}
tsk = kthread_run(balance_kthread, fs_info, "btrfs-balance");
return PTR_ERR_OR_ZERO(tsk);
}
int btrfs_recover_balance(struct btrfs_fs_info *fs_info)
{
struct btrfs_balance_control *bctl;
struct btrfs_balance_item *item;
struct btrfs_disk_balance_args disk_bargs;
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_key key;
int ret;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
key.objectid = BTRFS_BALANCE_OBJECTID;
key.type = BTRFS_BALANCE_ITEM_KEY;
key.offset = 0;
ret = btrfs_search_slot(NULL, fs_info->tree_root, &key, path, 0, 0);
if (ret < 0)
goto out;
if (ret > 0) {
ret = 0;
goto out;
}
bctl = kzalloc(sizeof(*bctl), GFP_NOFS);
if (!bctl) {
ret = -ENOMEM;
goto out;
}
leaf = path->nodes[0];
item = btrfs_item_ptr(leaf, path->slots[0], struct btrfs_balance_item);
bctl->fs_info = fs_info;
bctl->flags = btrfs_balance_flags(leaf, item);
bctl->flags |= BTRFS_BALANCE_RESUME;
btrfs_balance_data(leaf, item, &disk_bargs);
btrfs_disk_balance_args_to_cpu(&bctl->data, &disk_bargs);
btrfs_balance_meta(leaf, item, &disk_bargs);
btrfs_disk_balance_args_to_cpu(&bctl->meta, &disk_bargs);
btrfs_balance_sys(leaf, item, &disk_bargs);
btrfs_disk_balance_args_to_cpu(&bctl->sys, &disk_bargs);
WARN_ON(atomic_xchg(&fs_info->mutually_exclusive_operation_running, 1));
mutex_lock(&fs_info->volume_mutex);
mutex_lock(&fs_info->balance_mutex);
set_balance_control(bctl);
mutex_unlock(&fs_info->balance_mutex);
mutex_unlock(&fs_info->volume_mutex);
out:
btrfs_free_path(path);
return ret;
}
int btrfs_pause_balance(struct btrfs_fs_info *fs_info)
{
int ret = 0;
mutex_lock(&fs_info->balance_mutex);
if (!fs_info->balance_ctl) {
mutex_unlock(&fs_info->balance_mutex);
return -ENOTCONN;
}
if (atomic_read(&fs_info->balance_running)) {
atomic_inc(&fs_info->balance_pause_req);
mutex_unlock(&fs_info->balance_mutex);
wait_event(fs_info->balance_wait_q,
atomic_read(&fs_info->balance_running) == 0);
mutex_lock(&fs_info->balance_mutex);
BUG_ON(atomic_read(&fs_info->balance_running));
atomic_dec(&fs_info->balance_pause_req);
} else {
ret = -ENOTCONN;
}
mutex_unlock(&fs_info->balance_mutex);
return ret;
}
int btrfs_cancel_balance(struct btrfs_fs_info *fs_info)
{
if (fs_info->sb->s_flags & MS_RDONLY)
return -EROFS;
mutex_lock(&fs_info->balance_mutex);
if (!fs_info->balance_ctl) {
mutex_unlock(&fs_info->balance_mutex);
return -ENOTCONN;
}
atomic_inc(&fs_info->balance_cancel_req);
if (atomic_read(&fs_info->balance_running)) {
mutex_unlock(&fs_info->balance_mutex);
wait_event(fs_info->balance_wait_q,
atomic_read(&fs_info->balance_running) == 0);
mutex_lock(&fs_info->balance_mutex);
} else {
mutex_unlock(&fs_info->balance_mutex);
mutex_lock(&fs_info->volume_mutex);
mutex_lock(&fs_info->balance_mutex);
if (fs_info->balance_ctl)
__cancel_balance(fs_info);
mutex_unlock(&fs_info->volume_mutex);
}
BUG_ON(fs_info->balance_ctl || atomic_read(&fs_info->balance_running));
atomic_dec(&fs_info->balance_cancel_req);
mutex_unlock(&fs_info->balance_mutex);
return 0;
}
static int btrfs_uuid_scan_kthread(void *data)
{
struct btrfs_fs_info *fs_info = data;
struct btrfs_root *root = fs_info->tree_root;
struct btrfs_key key;
struct btrfs_key max_key;
struct btrfs_path *path = NULL;
int ret = 0;
struct extent_buffer *eb;
int slot;
struct btrfs_root_item root_item;
u32 item_size;
struct btrfs_trans_handle *trans = NULL;
path = btrfs_alloc_path();
if (!path) {
ret = -ENOMEM;
goto out;
}
key.objectid = 0;
key.type = BTRFS_ROOT_ITEM_KEY;
key.offset = 0;
max_key.objectid = (u64)-1;
max_key.type = BTRFS_ROOT_ITEM_KEY;
max_key.offset = (u64)-1;
path->keep_locks = 1;
while (1) {
ret = btrfs_search_forward(root, &key, path, 0);
if (ret) {
if (ret > 0)
ret = 0;
break;
}
if (key.type != BTRFS_ROOT_ITEM_KEY ||
(key.objectid < BTRFS_FIRST_FREE_OBJECTID &&
key.objectid != BTRFS_FS_TREE_OBJECTID) ||
key.objectid > BTRFS_LAST_FREE_OBJECTID)
goto skip;
eb = path->nodes[0];
slot = path->slots[0];
item_size = btrfs_item_size_nr(eb, slot);
if (item_size < sizeof(root_item))
goto skip;
read_extent_buffer(eb, &root_item,
btrfs_item_ptr_offset(eb, slot),
(int)sizeof(root_item));
if (btrfs_root_refs(&root_item) == 0)
goto skip;
if (!btrfs_is_empty_uuid(root_item.uuid) ||
!btrfs_is_empty_uuid(root_item.received_uuid)) {
if (trans)
goto update_tree;
btrfs_release_path(path);
trans = btrfs_start_transaction(fs_info->uuid_root, 2);
if (IS_ERR(trans)) {
ret = PTR_ERR(trans);
break;
}
continue;
} else {
goto skip;
}
update_tree:
if (!btrfs_is_empty_uuid(root_item.uuid)) {
ret = btrfs_uuid_tree_add(trans, fs_info->uuid_root,
root_item.uuid,
BTRFS_UUID_KEY_SUBVOL,
key.objectid);
if (ret < 0) {
btrfs_warn(fs_info, "uuid_tree_add failed %d",
ret);
break;
}
}
if (!btrfs_is_empty_uuid(root_item.received_uuid)) {
ret = btrfs_uuid_tree_add(trans, fs_info->uuid_root,
root_item.received_uuid,
BTRFS_UUID_KEY_RECEIVED_SUBVOL,
key.objectid);
if (ret < 0) {
btrfs_warn(fs_info, "uuid_tree_add failed %d",
ret);
break;
}
}
skip:
if (trans) {
ret = btrfs_end_transaction(trans, fs_info->uuid_root);
trans = NULL;
if (ret)
break;
}
btrfs_release_path(path);
if (key.offset < (u64)-1) {
key.offset++;
} else if (key.type < BTRFS_ROOT_ITEM_KEY) {
key.offset = 0;
key.type = BTRFS_ROOT_ITEM_KEY;
} else if (key.objectid < (u64)-1) {
key.offset = 0;
key.type = BTRFS_ROOT_ITEM_KEY;
key.objectid++;
} else {
break;
}
cond_resched();
}
out:
btrfs_free_path(path);
if (trans && !IS_ERR(trans))
btrfs_end_transaction(trans, fs_info->uuid_root);
if (ret)
btrfs_warn(fs_info, "btrfs_uuid_scan_kthread failed %d", ret);
else
fs_info->update_uuid_tree_gen = 1;
up(&fs_info->uuid_tree_rescan_sem);
return 0;
}
static int btrfs_check_uuid_tree_entry(struct btrfs_fs_info *fs_info,
u8 *uuid, u8 type, u64 subid)
{
struct btrfs_key key;
int ret = 0;
struct btrfs_root *subvol_root;
if (type != BTRFS_UUID_KEY_SUBVOL &&
type != BTRFS_UUID_KEY_RECEIVED_SUBVOL)
goto out;
key.objectid = subid;
key.type = BTRFS_ROOT_ITEM_KEY;
key.offset = (u64)-1;
subvol_root = btrfs_read_fs_root_no_name(fs_info, &key);
if (IS_ERR(subvol_root)) {
ret = PTR_ERR(subvol_root);
if (ret == -ENOENT)
ret = 1;
goto out;
}
switch (type) {
case BTRFS_UUID_KEY_SUBVOL:
if (memcmp(uuid, subvol_root->root_item.uuid, BTRFS_UUID_SIZE))
ret = 1;
break;
case BTRFS_UUID_KEY_RECEIVED_SUBVOL:
if (memcmp(uuid, subvol_root->root_item.received_uuid,
BTRFS_UUID_SIZE))
ret = 1;
break;
}
out:
return ret;
}
static int btrfs_uuid_rescan_kthread(void *data)
{
struct btrfs_fs_info *fs_info = (struct btrfs_fs_info *)data;
int ret;
ret = btrfs_uuid_tree_iterate(fs_info, btrfs_check_uuid_tree_entry);
if (ret < 0) {
btrfs_warn(fs_info, "iterating uuid_tree failed %d", ret);
up(&fs_info->uuid_tree_rescan_sem);
return ret;
}
return btrfs_uuid_scan_kthread(data);
}
int btrfs_create_uuid_tree(struct btrfs_fs_info *fs_info)
{
struct btrfs_trans_handle *trans;
struct btrfs_root *tree_root = fs_info->tree_root;
struct btrfs_root *uuid_root;
struct task_struct *task;
int ret;
trans = btrfs_start_transaction(tree_root, 2);
if (IS_ERR(trans))
return PTR_ERR(trans);
uuid_root = btrfs_create_tree(trans, fs_info,
BTRFS_UUID_TREE_OBJECTID);
if (IS_ERR(uuid_root)) {
btrfs_abort_transaction(trans, tree_root,
PTR_ERR(uuid_root));
return PTR_ERR(uuid_root);
}
fs_info->uuid_root = uuid_root;
ret = btrfs_commit_transaction(trans, tree_root);
if (ret)
return ret;
down(&fs_info->uuid_tree_rescan_sem);
task = kthread_run(btrfs_uuid_scan_kthread, fs_info, "btrfs-uuid");
if (IS_ERR(task)) {
btrfs_warn(fs_info, "failed to start uuid_scan task");
up(&fs_info->uuid_tree_rescan_sem);
return PTR_ERR(task);
}
return 0;
}
int btrfs_check_uuid_tree(struct btrfs_fs_info *fs_info)
{
struct task_struct *task;
down(&fs_info->uuid_tree_rescan_sem);
task = kthread_run(btrfs_uuid_rescan_kthread, fs_info, "btrfs-uuid");
if (IS_ERR(task)) {
btrfs_warn(fs_info, "failed to start uuid_rescan task");
up(&fs_info->uuid_tree_rescan_sem);
return PTR_ERR(task);
}
return 0;
}
int btrfs_shrink_device(struct btrfs_device *device, u64 new_size)
{
struct btrfs_trans_handle *trans;
struct btrfs_root *root = device->dev_root;
struct btrfs_dev_extent *dev_extent = NULL;
struct btrfs_path *path;
u64 length;
u64 chunk_tree;
u64 chunk_objectid;
u64 chunk_offset;
int ret;
int slot;
int failed = 0;
bool retried = false;
struct extent_buffer *l;
struct btrfs_key key;
struct btrfs_super_block *super_copy = root->fs_info->super_copy;
u64 old_total = btrfs_super_total_bytes(super_copy);
u64 old_size = device->total_bytes;
u64 diff = device->total_bytes - new_size;
if (device->is_tgtdev_for_dev_replace)
return -EINVAL;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
path->reada = 2;
lock_chunks(root);
device->total_bytes = new_size;
if (device->writeable) {
device->fs_devices->total_rw_bytes -= diff;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space -= diff;
spin_unlock(&root->fs_info->free_chunk_lock);
}
unlock_chunks(root);
again:
key.objectid = device->devid;
key.offset = (u64)-1;
key.type = BTRFS_DEV_EXTENT_KEY;
do {
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto done;
ret = btrfs_previous_item(root, path, 0, key.type);
if (ret < 0)
goto done;
if (ret) {
ret = 0;
btrfs_release_path(path);
break;
}
l = path->nodes[0];
slot = path->slots[0];
btrfs_item_key_to_cpu(l, &key, path->slots[0]);
if (key.objectid != device->devid) {
btrfs_release_path(path);
break;
}
dev_extent = btrfs_item_ptr(l, slot, struct btrfs_dev_extent);
length = btrfs_dev_extent_length(l, dev_extent);
if (key.offset + length <= new_size) {
btrfs_release_path(path);
break;
}
chunk_tree = btrfs_dev_extent_chunk_tree(l, dev_extent);
chunk_objectid = btrfs_dev_extent_chunk_objectid(l, dev_extent);
chunk_offset = btrfs_dev_extent_chunk_offset(l, dev_extent);
btrfs_release_path(path);
ret = btrfs_relocate_chunk(root, chunk_tree, chunk_objectid,
chunk_offset);
if (ret && ret != -ENOSPC)
goto done;
if (ret == -ENOSPC)
failed++;
} while (key.offset-- > 0);
if (failed && !retried) {
failed = 0;
retried = true;
goto again;
} else if (failed && retried) {
ret = -ENOSPC;
lock_chunks(root);
device->total_bytes = old_size;
if (device->writeable)
device->fs_devices->total_rw_bytes += diff;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space += diff;
spin_unlock(&root->fs_info->free_chunk_lock);
unlock_chunks(root);
goto done;
}
trans = btrfs_start_transaction(root, 0);
if (IS_ERR(trans)) {
ret = PTR_ERR(trans);
goto done;
}
lock_chunks(root);
device->disk_total_bytes = new_size;
ret = btrfs_update_device(trans, device);
if (ret) {
unlock_chunks(root);
btrfs_end_transaction(trans, root);
goto done;
}
WARN_ON(diff > old_total);
btrfs_set_super_total_bytes(super_copy, old_total - diff);
unlock_chunks(root);
btrfs_end_transaction(trans, root);
done:
btrfs_free_path(path);
return ret;
}
static int btrfs_add_system_chunk(struct btrfs_root *root,
struct btrfs_key *key,
struct btrfs_chunk *chunk, int item_size)
{
struct btrfs_super_block *super_copy = root->fs_info->super_copy;
struct btrfs_disk_key disk_key;
u32 array_size;
u8 *ptr;
array_size = btrfs_super_sys_array_size(super_copy);
if (array_size + item_size > BTRFS_SYSTEM_CHUNK_ARRAY_SIZE)
return -EFBIG;
ptr = super_copy->sys_chunk_array + array_size;
btrfs_cpu_key_to_disk(&disk_key, key);
memcpy(ptr, &disk_key, sizeof(disk_key));
ptr += sizeof(disk_key);
memcpy(ptr, chunk, item_size);
item_size += sizeof(disk_key);
btrfs_set_super_sys_array_size(super_copy, array_size + item_size);
return 0;
}
static int btrfs_cmp_device_info(const void *a, const void *b)
{
const struct btrfs_device_info *di_a = a;
const struct btrfs_device_info *di_b = b;
if (di_a->max_avail > di_b->max_avail)
return -1;
if (di_a->max_avail < di_b->max_avail)
return 1;
if (di_a->total_avail > di_b->total_avail)
return -1;
if (di_a->total_avail < di_b->total_avail)
return 1;
return 0;
}
static u32 find_raid56_stripe_len(u32 data_devices, u32 dev_stripe_target)
{
return 64 * 1024;
}
static void check_raid56_incompat_flag(struct btrfs_fs_info *info, u64 type)
{
if (!(type & (BTRFS_BLOCK_GROUP_RAID5 | BTRFS_BLOCK_GROUP_RAID6)))
return;
btrfs_set_fs_incompat(info, RAID56);
}
static int __btrfs_alloc_chunk(struct btrfs_trans_handle *trans,
struct btrfs_root *extent_root, u64 start,
u64 type)
{
struct btrfs_fs_info *info = extent_root->fs_info;
struct btrfs_fs_devices *fs_devices = info->fs_devices;
struct list_head *cur;
struct map_lookup *map = NULL;
struct extent_map_tree *em_tree;
struct extent_map *em;
struct btrfs_device_info *devices_info = NULL;
u64 total_avail;
int num_stripes;
int data_stripes;
int sub_stripes;
int dev_stripes;
int devs_max;
int devs_min;
int devs_increment;
int ncopies;
int ret;
u64 max_stripe_size;
u64 max_chunk_size;
u64 stripe_size;
u64 num_bytes;
u64 raid_stripe_len = BTRFS_STRIPE_LEN;
int ndevs;
int i;
int j;
int index;
BUG_ON(!alloc_profile_is_valid(type, 0));
if (list_empty(&fs_devices->alloc_list))
return -ENOSPC;
index = __get_raid_index(type);
sub_stripes = btrfs_raid_array[index].sub_stripes;
dev_stripes = btrfs_raid_array[index].dev_stripes;
devs_max = btrfs_raid_array[index].devs_max;
devs_min = btrfs_raid_array[index].devs_min;
devs_increment = btrfs_raid_array[index].devs_increment;
ncopies = btrfs_raid_array[index].ncopies;
if (type & BTRFS_BLOCK_GROUP_DATA) {
max_stripe_size = 1024 * 1024 * 1024;
max_chunk_size = 10 * max_stripe_size;
} else if (type & BTRFS_BLOCK_GROUP_METADATA) {
if (fs_devices->total_rw_bytes > 50ULL * 1024 * 1024 * 1024)
max_stripe_size = 1024 * 1024 * 1024;
else
max_stripe_size = 256 * 1024 * 1024;
max_chunk_size = max_stripe_size;
} else if (type & BTRFS_BLOCK_GROUP_SYSTEM) {
max_stripe_size = 32 * 1024 * 1024;
max_chunk_size = 2 * max_stripe_size;
} else {
btrfs_err(info, "invalid chunk type 0x%llx requested\n",
type);
BUG_ON(1);
}
max_chunk_size = min(div_factor(fs_devices->total_rw_bytes, 1),
max_chunk_size);
devices_info = kzalloc(sizeof(*devices_info) * fs_devices->rw_devices,
GFP_NOFS);
if (!devices_info)
return -ENOMEM;
cur = fs_devices->alloc_list.next;
ndevs = 0;
while (cur != &fs_devices->alloc_list) {
struct btrfs_device *device;
u64 max_avail;
u64 dev_offset;
device = list_entry(cur, struct btrfs_device, dev_alloc_list);
cur = cur->next;
if (!device->writeable) {
WARN(1, KERN_ERR
"BTRFS: read-only device in alloc_list\n");
continue;
}
if (!device->in_fs_metadata ||
device->is_tgtdev_for_dev_replace)
continue;
if (device->total_bytes > device->bytes_used)
total_avail = device->total_bytes - device->bytes_used;
else
total_avail = 0;
if (total_avail == 0)
continue;
ret = find_free_dev_extent(trans, device,
max_stripe_size * dev_stripes,
&dev_offset, &max_avail);
if (ret && ret != -ENOSPC)
goto error;
if (ret == 0)
max_avail = max_stripe_size * dev_stripes;
if (max_avail < BTRFS_STRIPE_LEN * dev_stripes)
continue;
if (ndevs == fs_devices->rw_devices) {
WARN(1, "%s: found more than %llu devices\n",
__func__, fs_devices->rw_devices);
break;
}
devices_info[ndevs].dev_offset = dev_offset;
devices_info[ndevs].max_avail = max_avail;
devices_info[ndevs].total_avail = total_avail;
devices_info[ndevs].dev = device;
++ndevs;
}
sort(devices_info, ndevs, sizeof(struct btrfs_device_info),
btrfs_cmp_device_info, NULL);
ndevs -= ndevs % devs_increment;
if (ndevs < devs_increment * sub_stripes || ndevs < devs_min) {
ret = -ENOSPC;
goto error;
}
if (devs_max && ndevs > devs_max)
ndevs = devs_max;
stripe_size = devices_info[ndevs-1].max_avail;
num_stripes = ndevs * dev_stripes;
data_stripes = num_stripes / ncopies;
if (type & BTRFS_BLOCK_GROUP_RAID5) {
raid_stripe_len = find_raid56_stripe_len(ndevs - 1,
btrfs_super_stripesize(info->super_copy));
data_stripes = num_stripes - 1;
}
if (type & BTRFS_BLOCK_GROUP_RAID6) {
raid_stripe_len = find_raid56_stripe_len(ndevs - 2,
btrfs_super_stripesize(info->super_copy));
data_stripes = num_stripes - 2;
}
if (stripe_size * data_stripes > max_chunk_size) {
u64 mask = (1ULL << 24) - 1;
stripe_size = max_chunk_size;
do_div(stripe_size, data_stripes);
stripe_size = (stripe_size + mask) & ~mask;
if (stripe_size > devices_info[ndevs-1].max_avail)
stripe_size = devices_info[ndevs-1].max_avail;
}
do_div(stripe_size, dev_stripes);
do_div(stripe_size, raid_stripe_len);
stripe_size *= raid_stripe_len;
map = kmalloc(map_lookup_size(num_stripes), GFP_NOFS);
if (!map) {
ret = -ENOMEM;
goto error;
}
map->num_stripes = num_stripes;
for (i = 0; i < ndevs; ++i) {
for (j = 0; j < dev_stripes; ++j) {
int s = i * dev_stripes + j;
map->stripes[s].dev = devices_info[i].dev;
map->stripes[s].physical = devices_info[i].dev_offset +
j * stripe_size;
}
}
map->sector_size = extent_root->sectorsize;
map->stripe_len = raid_stripe_len;
map->io_align = raid_stripe_len;
map->io_width = raid_stripe_len;
map->type = type;
map->sub_stripes = sub_stripes;
num_bytes = stripe_size * data_stripes;
trace_btrfs_chunk_alloc(info->chunk_root, map, start, num_bytes);
em = alloc_extent_map();
if (!em) {
ret = -ENOMEM;
goto error;
}
em->bdev = (struct block_device *)map;
em->start = start;
em->len = num_bytes;
em->block_start = 0;
em->block_len = em->len;
em->orig_block_len = stripe_size;
em_tree = &extent_root->fs_info->mapping_tree.map_tree;
write_lock(&em_tree->lock);
ret = add_extent_mapping(em_tree, em, 0);
if (!ret) {
list_add_tail(&em->list, &trans->transaction->pending_chunks);
atomic_inc(&em->refs);
}
write_unlock(&em_tree->lock);
if (ret) {
free_extent_map(em);
goto error;
}
ret = btrfs_make_block_group(trans, extent_root, 0, type,
BTRFS_FIRST_CHUNK_TREE_OBJECTID,
start, num_bytes);
if (ret)
goto error_del_extent;
free_extent_map(em);
check_raid56_incompat_flag(extent_root->fs_info, type);
kfree(devices_info);
return 0;
error_del_extent:
write_lock(&em_tree->lock);
remove_extent_mapping(em_tree, em);
write_unlock(&em_tree->lock);
free_extent_map(em);
free_extent_map(em);
error:
kfree(map);
kfree(devices_info);
return ret;
}
int btrfs_finish_chunk_alloc(struct btrfs_trans_handle *trans,
struct btrfs_root *extent_root,
u64 chunk_offset, u64 chunk_size)
{
struct btrfs_key key;
struct btrfs_root *chunk_root = extent_root->fs_info->chunk_root;
struct btrfs_device *device;
struct btrfs_chunk *chunk;
struct btrfs_stripe *stripe;
struct extent_map_tree *em_tree;
struct extent_map *em;
struct map_lookup *map;
size_t item_size;
u64 dev_offset;
u64 stripe_size;
int i = 0;
int ret;
em_tree = &extent_root->fs_info->mapping_tree.map_tree;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, chunk_offset, chunk_size);
read_unlock(&em_tree->lock);
if (!em) {
btrfs_crit(extent_root->fs_info, "unable to find logical "
"%Lu len %Lu", chunk_offset, chunk_size);
return -EINVAL;
}
if (em->start != chunk_offset || em->len != chunk_size) {
btrfs_crit(extent_root->fs_info, "found a bad mapping, wanted"
" %Lu-%Lu, found %Lu-%Lu\n", chunk_offset,
chunk_size, em->start, em->len);
free_extent_map(em);
return -EINVAL;
}
map = (struct map_lookup *)em->bdev;
item_size = btrfs_chunk_item_size(map->num_stripes);
stripe_size = em->orig_block_len;
chunk = kzalloc(item_size, GFP_NOFS);
if (!chunk) {
ret = -ENOMEM;
goto out;
}
for (i = 0; i < map->num_stripes; i++) {
device = map->stripes[i].dev;
dev_offset = map->stripes[i].physical;
device->bytes_used += stripe_size;
ret = btrfs_update_device(trans, device);
if (ret)
goto out;
ret = btrfs_alloc_dev_extent(trans, device,
chunk_root->root_key.objectid,
BTRFS_FIRST_CHUNK_TREE_OBJECTID,
chunk_offset, dev_offset,
stripe_size);
if (ret)
goto out;
}
spin_lock(&extent_root->fs_info->free_chunk_lock);
extent_root->fs_info->free_chunk_space -= (stripe_size *
map->num_stripes);
spin_unlock(&extent_root->fs_info->free_chunk_lock);
stripe = &chunk->stripe;
for (i = 0; i < map->num_stripes; i++) {
device = map->stripes[i].dev;
dev_offset = map->stripes[i].physical;
btrfs_set_stack_stripe_devid(stripe, device->devid);
btrfs_set_stack_stripe_offset(stripe, dev_offset);
memcpy(stripe->dev_uuid, device->uuid, BTRFS_UUID_SIZE);
stripe++;
}
btrfs_set_stack_chunk_length(chunk, chunk_size);
btrfs_set_stack_chunk_owner(chunk, extent_root->root_key.objectid);
btrfs_set_stack_chunk_stripe_len(chunk, map->stripe_len);
btrfs_set_stack_chunk_type(chunk, map->type);
btrfs_set_stack_chunk_num_stripes(chunk, map->num_stripes);
btrfs_set_stack_chunk_io_align(chunk, map->stripe_len);
btrfs_set_stack_chunk_io_width(chunk, map->stripe_len);
btrfs_set_stack_chunk_sector_size(chunk, extent_root->sectorsize);
btrfs_set_stack_chunk_sub_stripes(chunk, map->sub_stripes);
key.objectid = BTRFS_FIRST_CHUNK_TREE_OBJECTID;
key.type = BTRFS_CHUNK_ITEM_KEY;
key.offset = chunk_offset;
ret = btrfs_insert_item(trans, chunk_root, &key, chunk, item_size);
if (ret == 0 && map->type & BTRFS_BLOCK_GROUP_SYSTEM) {
ret = btrfs_add_system_chunk(chunk_root, &key, chunk,
item_size);
}
out:
kfree(chunk);
free_extent_map(em);
return ret;
}
int btrfs_alloc_chunk(struct btrfs_trans_handle *trans,
struct btrfs_root *extent_root, u64 type)
{
u64 chunk_offset;
chunk_offset = find_next_chunk(extent_root->fs_info);
return __btrfs_alloc_chunk(trans, extent_root, chunk_offset, type);
}
static noinline int init_first_rw_device(struct btrfs_trans_handle *trans,
struct btrfs_root *root,
struct btrfs_device *device)
{
u64 chunk_offset;
u64 sys_chunk_offset;
u64 alloc_profile;
struct btrfs_fs_info *fs_info = root->fs_info;
struct btrfs_root *extent_root = fs_info->extent_root;
int ret;
chunk_offset = find_next_chunk(fs_info);
alloc_profile = btrfs_get_alloc_profile(extent_root, 0);
ret = __btrfs_alloc_chunk(trans, extent_root, chunk_offset,
alloc_profile);
if (ret)
return ret;
sys_chunk_offset = find_next_chunk(root->fs_info);
alloc_profile = btrfs_get_alloc_profile(fs_info->chunk_root, 0);
ret = __btrfs_alloc_chunk(trans, extent_root, sys_chunk_offset,
alloc_profile);
if (ret) {
btrfs_abort_transaction(trans, root, ret);
goto out;
}
ret = btrfs_add_device(trans, fs_info->chunk_root, device);
if (ret)
btrfs_abort_transaction(trans, root, ret);
out:
return ret;
}
int btrfs_chunk_readonly(struct btrfs_root *root, u64 chunk_offset)
{
struct extent_map *em;
struct map_lookup *map;
struct btrfs_mapping_tree *map_tree = &root->fs_info->mapping_tree;
int readonly = 0;
int i;
read_lock(&map_tree->map_tree.lock);
em = lookup_extent_mapping(&map_tree->map_tree, chunk_offset, 1);
read_unlock(&map_tree->map_tree.lock);
if (!em)
return 1;
if (btrfs_test_opt(root, DEGRADED)) {
free_extent_map(em);
return 0;
}
map = (struct map_lookup *)em->bdev;
for (i = 0; i < map->num_stripes; i++) {
if (!map->stripes[i].dev->writeable) {
readonly = 1;
break;
}
}
free_extent_map(em);
return readonly;
}
void btrfs_mapping_init(struct btrfs_mapping_tree *tree)
{
extent_map_tree_init(&tree->map_tree);
}
void btrfs_mapping_tree_free(struct btrfs_mapping_tree *tree)
{
struct extent_map *em;
while (1) {
write_lock(&tree->map_tree.lock);
em = lookup_extent_mapping(&tree->map_tree, 0, (u64)-1);
if (em)
remove_extent_mapping(&tree->map_tree, em);
write_unlock(&tree->map_tree.lock);
if (!em)
break;
kfree(em->bdev);
free_extent_map(em);
free_extent_map(em);
}
}
int btrfs_num_copies(struct btrfs_fs_info *fs_info, u64 logical, u64 len)
{
struct btrfs_mapping_tree *map_tree = &fs_info->mapping_tree;
struct extent_map *em;
struct map_lookup *map;
struct extent_map_tree *em_tree = &map_tree->map_tree;
int ret;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, logical, len);
read_unlock(&em_tree->lock);
if (!em) {
btrfs_crit(fs_info, "No mapping for %Lu-%Lu\n", logical,
logical+len);
return 1;
}
if (em->start > logical || em->start + em->len < logical) {
btrfs_crit(fs_info, "Invalid mapping for %Lu-%Lu, got "
"%Lu-%Lu\n", logical, logical+len, em->start,
em->start + em->len);
free_extent_map(em);
return 1;
}
map = (struct map_lookup *)em->bdev;
if (map->type & (BTRFS_BLOCK_GROUP_DUP | BTRFS_BLOCK_GROUP_RAID1))
ret = map->num_stripes;
else if (map->type & BTRFS_BLOCK_GROUP_RAID10)
ret = map->sub_stripes;
else if (map->type & BTRFS_BLOCK_GROUP_RAID5)
ret = 2;
else if (map->type & BTRFS_BLOCK_GROUP_RAID6)
ret = 3;
else
ret = 1;
free_extent_map(em);
btrfs_dev_replace_lock(&fs_info->dev_replace);
if (btrfs_dev_replace_is_ongoing(&fs_info->dev_replace))
ret++;
btrfs_dev_replace_unlock(&fs_info->dev_replace);
return ret;
}
unsigned long btrfs_full_stripe_len(struct btrfs_root *root,
struct btrfs_mapping_tree *map_tree,
u64 logical)
{
struct extent_map *em;
struct map_lookup *map;
struct extent_map_tree *em_tree = &map_tree->map_tree;
unsigned long len = root->sectorsize;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, logical, len);
read_unlock(&em_tree->lock);
BUG_ON(!em);
BUG_ON(em->start > logical || em->start + em->len < logical);
map = (struct map_lookup *)em->bdev;
if (map->type & (BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_RAID6)) {
len = map->stripe_len * nr_data_stripes(map);
}
free_extent_map(em);
return len;
}
int btrfs_is_parity_mirror(struct btrfs_mapping_tree *map_tree,
u64 logical, u64 len, int mirror_num)
{
struct extent_map *em;
struct map_lookup *map;
struct extent_map_tree *em_tree = &map_tree->map_tree;
int ret = 0;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, logical, len);
read_unlock(&em_tree->lock);
BUG_ON(!em);
BUG_ON(em->start > logical || em->start + em->len < logical);
map = (struct map_lookup *)em->bdev;
if (map->type & (BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_RAID6))
ret = 1;
free_extent_map(em);
return ret;
}
static int find_live_mirror(struct btrfs_fs_info *fs_info,
struct map_lookup *map, int first, int num,
int optimal, int dev_replace_is_ongoing)
{
int i;
int tolerance;
struct btrfs_device *srcdev;
if (dev_replace_is_ongoing &&
fs_info->dev_replace.cont_reading_from_srcdev_mode ==
BTRFS_DEV_REPLACE_ITEM_CONT_READING_FROM_SRCDEV_MODE_AVOID)
srcdev = fs_info->dev_replace.srcdev;
else
srcdev = NULL;
for (tolerance = 0; tolerance < 2; tolerance++) {
if (map->stripes[optimal].dev->bdev &&
(tolerance || map->stripes[optimal].dev != srcdev))
return optimal;
for (i = first; i < first + num; i++) {
if (map->stripes[i].dev->bdev &&
(tolerance || map->stripes[i].dev != srcdev))
return i;
}
}
return optimal;
}
static inline int parity_smaller(u64 a, u64 b)
{
return a > b;
}
static void sort_parity_stripes(struct btrfs_bio *bbio, u64 *raid_map)
{
struct btrfs_bio_stripe s;
int i;
u64 l;
int again = 1;
while (again) {
again = 0;
for (i = 0; i < bbio->num_stripes - 1; i++) {
if (parity_smaller(raid_map[i], raid_map[i+1])) {
s = bbio->stripes[i];
l = raid_map[i];
bbio->stripes[i] = bbio->stripes[i+1];
raid_map[i] = raid_map[i+1];
bbio->stripes[i+1] = s;
raid_map[i+1] = l;
again = 1;
}
}
}
}
static int __btrfs_map_block(struct btrfs_fs_info *fs_info, int rw,
u64 logical, u64 *length,
struct btrfs_bio **bbio_ret,
int mirror_num, u64 **raid_map_ret)
{
struct extent_map *em;
struct map_lookup *map;
struct btrfs_mapping_tree *map_tree = &fs_info->mapping_tree;
struct extent_map_tree *em_tree = &map_tree->map_tree;
u64 offset;
u64 stripe_offset;
u64 stripe_end_offset;
u64 stripe_nr;
u64 stripe_nr_orig;
u64 stripe_nr_end;
u64 stripe_len;
u64 *raid_map = NULL;
int stripe_index;
int i;
int ret = 0;
int num_stripes;
int max_errors = 0;
struct btrfs_bio *bbio = NULL;
struct btrfs_dev_replace *dev_replace = &fs_info->dev_replace;
int dev_replace_is_ongoing = 0;
int num_alloc_stripes;
int patch_the_first_stripe_for_dev_replace = 0;
u64 physical_to_patch_in_first_stripe = 0;
u64 raid56_full_stripe_start = (u64)-1;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, logical, *length);
read_unlock(&em_tree->lock);
if (!em) {
btrfs_crit(fs_info, "unable to find logical %llu len %llu",
logical, *length);
return -EINVAL;
}
if (em->start > logical || em->start + em->len < logical) {
btrfs_crit(fs_info, "found a bad mapping, wanted %Lu, "
"found %Lu-%Lu\n", logical, em->start,
em->start + em->len);
free_extent_map(em);
return -EINVAL;
}
map = (struct map_lookup *)em->bdev;
offset = logical - em->start;
stripe_len = map->stripe_len;
stripe_nr = offset;
do_div(stripe_nr, stripe_len);
stripe_offset = stripe_nr * stripe_len;
BUG_ON(offset < stripe_offset);
stripe_offset = offset - stripe_offset;
if (map->type & (BTRFS_BLOCK_GROUP_RAID5 | BTRFS_BLOCK_GROUP_RAID6)) {
unsigned long full_stripe_len = stripe_len * nr_data_stripes(map);
raid56_full_stripe_start = offset;
do_div(raid56_full_stripe_start, full_stripe_len);
raid56_full_stripe_start *= full_stripe_len;
}
if (rw & REQ_DISCARD) {
if (map->type &
(BTRFS_BLOCK_GROUP_RAID5 | BTRFS_BLOCK_GROUP_RAID6)) {
ret = -EOPNOTSUPP;
goto out;
}
*length = min_t(u64, em->len - offset, *length);
} else if (map->type & BTRFS_BLOCK_GROUP_PROFILE_MASK) {
u64 max_len;
if (map->type & (BTRFS_BLOCK_GROUP_RAID5 | BTRFS_BLOCK_GROUP_RAID6) &&
(rw & REQ_WRITE)) {
max_len = stripe_len * nr_data_stripes(map) -
(offset - raid56_full_stripe_start);
} else {
max_len = stripe_len - stripe_offset;
}
*length = min_t(u64, em->len - offset, max_len);
} else {
*length = em->len - offset;
}
if (!bbio_ret)
goto out;
btrfs_dev_replace_lock(dev_replace);
dev_replace_is_ongoing = btrfs_dev_replace_is_ongoing(dev_replace);
if (!dev_replace_is_ongoing)
btrfs_dev_replace_unlock(dev_replace);
if (dev_replace_is_ongoing && mirror_num == map->num_stripes + 1 &&
!(rw & (REQ_WRITE | REQ_DISCARD | REQ_GET_READ_MIRRORS)) &&
dev_replace->tgtdev != NULL) {
u64 tmp_length = *length;
struct btrfs_bio *tmp_bbio = NULL;
int tmp_num_stripes;
u64 srcdev_devid = dev_replace->srcdev->devid;
int index_srcdev = 0;
int found = 0;
u64 physical_of_found = 0;
ret = __btrfs_map_block(fs_info, REQ_GET_READ_MIRRORS,
logical, &tmp_length, &tmp_bbio, 0, NULL);
if (ret) {
WARN_ON(tmp_bbio != NULL);
goto out;
}
tmp_num_stripes = tmp_bbio->num_stripes;
if (mirror_num > tmp_num_stripes) {
ret = -EIO;
kfree(tmp_bbio);
goto out;
}
for (i = 0; i < tmp_num_stripes; i++) {
if (tmp_bbio->stripes[i].dev->devid == srcdev_devid) {
if (found &&
physical_of_found <=
tmp_bbio->stripes[i].physical)
continue;
index_srcdev = i;
found = 1;
physical_of_found =
tmp_bbio->stripes[i].physical;
}
}
if (found) {
mirror_num = index_srcdev + 1;
patch_the_first_stripe_for_dev_replace = 1;
physical_to_patch_in_first_stripe = physical_of_found;
} else {
WARN_ON(1);
ret = -EIO;
kfree(tmp_bbio);
goto out;
}
kfree(tmp_bbio);
} else if (mirror_num > map->num_stripes) {
mirror_num = 0;
}
num_stripes = 1;
stripe_index = 0;
stripe_nr_orig = stripe_nr;
stripe_nr_end = ALIGN(offset + *length, map->stripe_len);
do_div(stripe_nr_end, map->stripe_len);
stripe_end_offset = stripe_nr_end * map->stripe_len -
(offset + *length);
if (map->type & BTRFS_BLOCK_GROUP_RAID0) {
if (rw & REQ_DISCARD)
num_stripes = min_t(u64, map->num_stripes,
stripe_nr_end - stripe_nr_orig);
stripe_index = do_div(stripe_nr, map->num_stripes);
} else if (map->type & BTRFS_BLOCK_GROUP_RAID1) {
if (rw & (REQ_WRITE | REQ_DISCARD | REQ_GET_READ_MIRRORS))
num_stripes = map->num_stripes;
else if (mirror_num)
stripe_index = mirror_num - 1;
else {
stripe_index = find_live_mirror(fs_info, map, 0,
map->num_stripes,
current->pid % map->num_stripes,
dev_replace_is_ongoing);
mirror_num = stripe_index + 1;
}
} else if (map->type & BTRFS_BLOCK_GROUP_DUP) {
if (rw & (REQ_WRITE | REQ_DISCARD | REQ_GET_READ_MIRRORS)) {
num_stripes = map->num_stripes;
} else if (mirror_num) {
stripe_index = mirror_num - 1;
} else {
mirror_num = 1;
}
} else if (map->type & BTRFS_BLOCK_GROUP_RAID10) {
int factor = map->num_stripes / map->sub_stripes;
stripe_index = do_div(stripe_nr, factor);
stripe_index *= map->sub_stripes;
if (rw & (REQ_WRITE | REQ_GET_READ_MIRRORS))
num_stripes = map->sub_stripes;
else if (rw & REQ_DISCARD)
num_stripes = min_t(u64, map->sub_stripes *
(stripe_nr_end - stripe_nr_orig),
map->num_stripes);
else if (mirror_num)
stripe_index += mirror_num - 1;
else {
int old_stripe_index = stripe_index;
stripe_index = find_live_mirror(fs_info, map,
stripe_index,
map->sub_stripes, stripe_index +
current->pid % map->sub_stripes,
dev_replace_is_ongoing);
mirror_num = stripe_index - old_stripe_index + 1;
}
} else if (map->type & (BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_RAID6)) {
u64 tmp;
if (bbio_ret && ((rw & REQ_WRITE) || mirror_num > 1)
&& raid_map_ret) {
int i, rot;
stripe_nr = raid56_full_stripe_start;
do_div(stripe_nr, stripe_len);
stripe_index = do_div(stripe_nr, nr_data_stripes(map));
num_stripes = map->num_stripes;
max_errors = nr_parity_stripes(map);
raid_map = kmalloc_array(num_stripes, sizeof(u64),
GFP_NOFS);
if (!raid_map) {
ret = -ENOMEM;
goto out;
}
tmp = stripe_nr;
rot = do_div(tmp, num_stripes);
tmp = stripe_nr * nr_data_stripes(map);
for (i = 0; i < nr_data_stripes(map); i++)
raid_map[(i+rot) % num_stripes] =
em->start + (tmp + i) * map->stripe_len;
raid_map[(i+rot) % map->num_stripes] = RAID5_P_STRIPE;
if (map->type & BTRFS_BLOCK_GROUP_RAID6)
raid_map[(i+rot+1) % num_stripes] =
RAID6_Q_STRIPE;
*length = map->stripe_len;
stripe_index = 0;
stripe_offset = 0;
} else {
stripe_index = do_div(stripe_nr, nr_data_stripes(map));
if (mirror_num > 1)
stripe_index = nr_data_stripes(map) +
mirror_num - 2;
tmp = stripe_nr + stripe_index;
stripe_index = do_div(tmp, map->num_stripes);
}
} else {
stripe_index = do_div(stripe_nr, map->num_stripes);
mirror_num = stripe_index + 1;
}
BUG_ON(stripe_index >= map->num_stripes);
num_alloc_stripes = num_stripes;
if (dev_replace_is_ongoing) {
if (rw & (REQ_WRITE | REQ_DISCARD))
num_alloc_stripes <<= 1;
if (rw & REQ_GET_READ_MIRRORS)
num_alloc_stripes++;
}
bbio = kzalloc(btrfs_bio_size(num_alloc_stripes), GFP_NOFS);
if (!bbio) {
kfree(raid_map);
ret = -ENOMEM;
goto out;
}
atomic_set(&bbio->error, 0);
if (rw & REQ_DISCARD) {
int factor = 0;
int sub_stripes = 0;
u64 stripes_per_dev = 0;
u32 remaining_stripes = 0;
u32 last_stripe = 0;
if (map->type &
(BTRFS_BLOCK_GROUP_RAID0 | BTRFS_BLOCK_GROUP_RAID10)) {
if (map->type & BTRFS_BLOCK_GROUP_RAID0)
sub_stripes = 1;
else
sub_stripes = map->sub_stripes;
factor = map->num_stripes / sub_stripes;
stripes_per_dev = div_u64_rem(stripe_nr_end -
stripe_nr_orig,
factor,
&remaining_stripes);
div_u64_rem(stripe_nr_end - 1, factor, &last_stripe);
last_stripe *= sub_stripes;
}
for (i = 0; i < num_stripes; i++) {
bbio->stripes[i].physical =
map->stripes[stripe_index].physical +
stripe_offset + stripe_nr * map->stripe_len;
bbio->stripes[i].dev = map->stripes[stripe_index].dev;
if (map->type & (BTRFS_BLOCK_GROUP_RAID0 |
BTRFS_BLOCK_GROUP_RAID10)) {
bbio->stripes[i].length = stripes_per_dev *
map->stripe_len;
if (i / sub_stripes < remaining_stripes)
bbio->stripes[i].length +=
map->stripe_len;
if (i < sub_stripes)
bbio->stripes[i].length -=
stripe_offset;
if (stripe_index >= last_stripe &&
stripe_index <= (last_stripe +
sub_stripes - 1))
bbio->stripes[i].length -=
stripe_end_offset;
if (i == sub_stripes - 1)
stripe_offset = 0;
} else
bbio->stripes[i].length = *length;
stripe_index++;
if (stripe_index == map->num_stripes) {
stripe_index = 0;
stripe_nr++;
}
}
} else {
for (i = 0; i < num_stripes; i++) {
bbio->stripes[i].physical =
map->stripes[stripe_index].physical +
stripe_offset +
stripe_nr * map->stripe_len;
bbio->stripes[i].dev =
map->stripes[stripe_index].dev;
stripe_index++;
}
}
if (rw & (REQ_WRITE | REQ_GET_READ_MIRRORS)) {
if (map->type & (BTRFS_BLOCK_GROUP_RAID1 |
BTRFS_BLOCK_GROUP_RAID10 |
BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_DUP)) {
max_errors = 1;
} else if (map->type & BTRFS_BLOCK_GROUP_RAID6) {
max_errors = 2;
}
}
if (dev_replace_is_ongoing && (rw & (REQ_WRITE | REQ_DISCARD)) &&
dev_replace->tgtdev != NULL) {
int index_where_to_add;
u64 srcdev_devid = dev_replace->srcdev->devid;
index_where_to_add = num_stripes;
for (i = 0; i < num_stripes; i++) {
if (bbio->stripes[i].dev->devid == srcdev_devid) {
struct btrfs_bio_stripe *new =
bbio->stripes + index_where_to_add;
struct btrfs_bio_stripe *old =
bbio->stripes + i;
new->physical = old->physical;
new->length = old->length;
new->dev = dev_replace->tgtdev;
index_where_to_add++;
max_errors++;
}
}
num_stripes = index_where_to_add;
} else if (dev_replace_is_ongoing && (rw & REQ_GET_READ_MIRRORS) &&
dev_replace->tgtdev != NULL) {
u64 srcdev_devid = dev_replace->srcdev->devid;
int index_srcdev = 0;
int found = 0;
u64 physical_of_found = 0;
for (i = 0; i < num_stripes; i++) {
if (bbio->stripes[i].dev->devid == srcdev_devid) {
if (found &&
physical_of_found <=
bbio->stripes[i].physical)
continue;
index_srcdev = i;
found = 1;
physical_of_found = bbio->stripes[i].physical;
}
}
if (found) {
u64 length = map->stripe_len;
if (physical_of_found + length <=
dev_replace->cursor_left) {
struct btrfs_bio_stripe *tgtdev_stripe =
bbio->stripes + num_stripes;
tgtdev_stripe->physical = physical_of_found;
tgtdev_stripe->length =
bbio->stripes[index_srcdev].length;
tgtdev_stripe->dev = dev_replace->tgtdev;
num_stripes++;
}
}
}
*bbio_ret = bbio;
bbio->num_stripes = num_stripes;
bbio->max_errors = max_errors;
bbio->mirror_num = mirror_num;
if (patch_the_first_stripe_for_dev_replace && num_stripes > 0) {
WARN_ON(num_stripes > 1);
bbio->stripes[0].dev = dev_replace->tgtdev;
bbio->stripes[0].physical = physical_to_patch_in_first_stripe;
bbio->mirror_num = map->num_stripes + 1;
}
if (raid_map) {
sort_parity_stripes(bbio, raid_map);
*raid_map_ret = raid_map;
}
out:
if (dev_replace_is_ongoing)
btrfs_dev_replace_unlock(dev_replace);
free_extent_map(em);
return ret;
}
int btrfs_map_block(struct btrfs_fs_info *fs_info, int rw,
u64 logical, u64 *length,
struct btrfs_bio **bbio_ret, int mirror_num)
{
return __btrfs_map_block(fs_info, rw, logical, length, bbio_ret,
mirror_num, NULL);
}
int btrfs_rmap_block(struct btrfs_mapping_tree *map_tree,
u64 chunk_start, u64 physical, u64 devid,
u64 **logical, int *naddrs, int *stripe_len)
{
struct extent_map_tree *em_tree = &map_tree->map_tree;
struct extent_map *em;
struct map_lookup *map;
u64 *buf;
u64 bytenr;
u64 length;
u64 stripe_nr;
u64 rmap_len;
int i, j, nr = 0;
read_lock(&em_tree->lock);
em = lookup_extent_mapping(em_tree, chunk_start, 1);
read_unlock(&em_tree->lock);
if (!em) {
printk(KERN_ERR "BTRFS: couldn't find em for chunk %Lu\n",
chunk_start);
return -EIO;
}
if (em->start != chunk_start) {
printk(KERN_ERR "BTRFS: bad chunk start, em=%Lu, wanted=%Lu\n",
em->start, chunk_start);
free_extent_map(em);
return -EIO;
}
map = (struct map_lookup *)em->bdev;
length = em->len;
rmap_len = map->stripe_len;
if (map->type & BTRFS_BLOCK_GROUP_RAID10)
do_div(length, map->num_stripes / map->sub_stripes);
else if (map->type & BTRFS_BLOCK_GROUP_RAID0)
do_div(length, map->num_stripes);
else if (map->type & (BTRFS_BLOCK_GROUP_RAID5 |
BTRFS_BLOCK_GROUP_RAID6)) {
do_div(length, nr_data_stripes(map));
rmap_len = map->stripe_len * nr_data_stripes(map);
}
buf = kzalloc(sizeof(u64) * map->num_stripes, GFP_NOFS);
BUG_ON(!buf);
for (i = 0; i < map->num_stripes; i++) {
if (devid && map->stripes[i].dev->devid != devid)
continue;
if (map->stripes[i].physical > physical ||
map->stripes[i].physical + length <= physical)
continue;
stripe_nr = physical - map->stripes[i].physical;
do_div(stripe_nr, map->stripe_len);
if (map->type & BTRFS_BLOCK_GROUP_RAID10) {
stripe_nr = stripe_nr * map->num_stripes + i;
do_div(stripe_nr, map->sub_stripes);
} else if (map->type & BTRFS_BLOCK_GROUP_RAID0) {
stripe_nr = stripe_nr * map->num_stripes + i;
}
bytenr = chunk_start + stripe_nr * rmap_len;
WARN_ON(nr >= map->num_stripes);
for (j = 0; j < nr; j++) {
if (buf[j] == bytenr)
break;
}
if (j == nr) {
WARN_ON(nr >= map->num_stripes);
buf[nr++] = bytenr;
}
}
*logical = buf;
*naddrs = nr;
*stripe_len = rmap_len;
free_extent_map(em);
return 0;
}
static void btrfs_end_bio(struct bio *bio, int err)
{
struct btrfs_bio *bbio = bio->bi_private;
int is_orig_bio = 0;
if (err) {
atomic_inc(&bbio->error);
if (err == -EIO || err == -EREMOTEIO) {
unsigned int stripe_index =
btrfs_io_bio(bio)->stripe_index;
struct btrfs_device *dev;
BUG_ON(stripe_index >= bbio->num_stripes);
dev = bbio->stripes[stripe_index].dev;
if (dev->bdev) {
if (bio->bi_rw & WRITE)
btrfs_dev_stat_inc(dev,
BTRFS_DEV_STAT_WRITE_ERRS);
else
btrfs_dev_stat_inc(dev,
BTRFS_DEV_STAT_READ_ERRS);
if ((bio->bi_rw & WRITE_FLUSH) == WRITE_FLUSH)
btrfs_dev_stat_inc(dev,
BTRFS_DEV_STAT_FLUSH_ERRS);
btrfs_dev_stat_print_on_error(dev);
}
}
}
if (bio == bbio->orig_bio)
is_orig_bio = 1;
if (atomic_dec_and_test(&bbio->stripes_pending)) {
if (!is_orig_bio) {
bio_put(bio);
bio = bbio->orig_bio;
}
atomic_inc(&bio->bi_remaining);
bio->bi_private = bbio->private;
bio->bi_end_io = bbio->end_io;
btrfs_io_bio(bio)->mirror_num = bbio->mirror_num;
if (atomic_read(&bbio->error) > bbio->max_errors) {
err = -EIO;
} else {
set_bit(BIO_UPTODATE, &bio->bi_flags);
err = 0;
}
kfree(bbio);
bio_endio(bio, err);
} else if (!is_orig_bio) {
bio_put(bio);
}
}
static noinline void btrfs_schedule_bio(struct btrfs_root *root,
struct btrfs_device *device,
int rw, struct bio *bio)
{
int should_queue = 1;
struct btrfs_pending_bios *pending_bios;
if (device->missing || !device->bdev) {
bio_endio(bio, -EIO);
return;
}
if (!(rw & REQ_WRITE)) {
bio_get(bio);
btrfsic_submit_bio(rw, bio);
bio_put(bio);
return;
}
atomic_inc(&root->fs_info->nr_async_bios);
WARN_ON(bio->bi_next);
bio->bi_next = NULL;
bio->bi_rw |= rw;
spin_lock(&device->io_lock);
if (bio->bi_rw & REQ_SYNC)
pending_bios = &device->pending_sync_bios;
else
pending_bios = &device->pending_bios;
if (pending_bios->tail)
pending_bios->tail->bi_next = bio;
pending_bios->tail = bio;
if (!pending_bios->head)
pending_bios->head = bio;
if (device->running_pending)
should_queue = 0;
spin_unlock(&device->io_lock);
if (should_queue)
btrfs_queue_worker(&root->fs_info->submit_workers,
&device->work);
}
static int bio_size_ok(struct block_device *bdev, struct bio *bio,
sector_t sector)
{
struct bio_vec *prev;
struct request_queue *q = bdev_get_queue(bdev);
unsigned int max_sectors = queue_max_sectors(q);
struct bvec_merge_data bvm = {
.bi_bdev = bdev,
.bi_sector = sector,
.bi_rw = bio->bi_rw,
};
if (WARN_ON(bio->bi_vcnt == 0))
return 1;
prev = &bio->bi_io_vec[bio->bi_vcnt - 1];
if (bio_sectors(bio) > max_sectors)
return 0;
if (!q->merge_bvec_fn)
return 1;
bvm.bi_size = bio->bi_iter.bi_size - prev->bv_len;
if (q->merge_bvec_fn(q, &bvm, prev) < prev->bv_len)
return 0;
return 1;
}
static void submit_stripe_bio(struct btrfs_root *root, struct btrfs_bio *bbio,
struct bio *bio, u64 physical, int dev_nr,
int rw, int async)
{
struct btrfs_device *dev = bbio->stripes[dev_nr].dev;
bio->bi_private = bbio;
btrfs_io_bio(bio)->stripe_index = dev_nr;
bio->bi_end_io = btrfs_end_bio;
bio->bi_iter.bi_sector = physical >> 9;
#ifdef DEBUG
{
struct rcu_string *name;
rcu_read_lock();
name = rcu_dereference(dev->name);
pr_debug("btrfs_map_bio: rw %d, sector=%llu, dev=%lu "
"(%s id %llu), size=%u\n", rw,
(u64)bio->bi_sector, (u_long)dev->bdev->bd_dev,
name->str, dev->devid, bio->bi_size);
rcu_read_unlock();
}
#endif
bio->bi_bdev = dev->bdev;
if (async)
btrfs_schedule_bio(root, dev, rw, bio);
else
btrfsic_submit_bio(rw, bio);
}
static int breakup_stripe_bio(struct btrfs_root *root, struct btrfs_bio *bbio,
struct bio *first_bio, struct btrfs_device *dev,
int dev_nr, int rw, int async)
{
struct bio_vec *bvec = first_bio->bi_io_vec;
struct bio *bio;
int nr_vecs = bio_get_nr_vecs(dev->bdev);
u64 physical = bbio->stripes[dev_nr].physical;
again:
bio = btrfs_bio_alloc(dev->bdev, physical >> 9, nr_vecs, GFP_NOFS);
if (!bio)
return -ENOMEM;
while (bvec <= (first_bio->bi_io_vec + first_bio->bi_vcnt - 1)) {
if (bio_add_page(bio, bvec->bv_page, bvec->bv_len,
bvec->bv_offset) < bvec->bv_len) {
u64 len = bio->bi_iter.bi_size;
atomic_inc(&bbio->stripes_pending);
submit_stripe_bio(root, bbio, bio, physical, dev_nr,
rw, async);
physical += len;
goto again;
}
bvec++;
}
submit_stripe_bio(root, bbio, bio, physical, dev_nr, rw, async);
return 0;
}
static void bbio_error(struct btrfs_bio *bbio, struct bio *bio, u64 logical)
{
atomic_inc(&bbio->error);
if (atomic_dec_and_test(&bbio->stripes_pending)) {
bio->bi_private = bbio->private;
bio->bi_end_io = bbio->end_io;
btrfs_io_bio(bio)->mirror_num = bbio->mirror_num;
bio->bi_iter.bi_sector = logical >> 9;
kfree(bbio);
bio_endio(bio, -EIO);
}
}
int btrfs_map_bio(struct btrfs_root *root, int rw, struct bio *bio,
int mirror_num, int async_submit)
{
struct btrfs_device *dev;
struct bio *first_bio = bio;
u64 logical = (u64)bio->bi_iter.bi_sector << 9;
u64 length = 0;
u64 map_length;
u64 *raid_map = NULL;
int ret;
int dev_nr = 0;
int total_devs = 1;
struct btrfs_bio *bbio = NULL;
length = bio->bi_iter.bi_size;
map_length = length;
ret = __btrfs_map_block(root->fs_info, rw, logical, &map_length, &bbio,
mirror_num, &raid_map);
if (ret)
return ret;
total_devs = bbio->num_stripes;
bbio->orig_bio = first_bio;
bbio->private = first_bio->bi_private;
bbio->end_io = first_bio->bi_end_io;
atomic_set(&bbio->stripes_pending, bbio->num_stripes);
if (raid_map) {
if (rw & WRITE) {
return raid56_parity_write(root, bio, bbio,
raid_map, map_length);
} else {
return raid56_parity_recover(root, bio, bbio,
raid_map, map_length,
mirror_num);
}
}
if (map_length < length) {
btrfs_crit(root->fs_info, "mapping failed logical %llu bio len %llu len %llu",
logical, length, map_length);
BUG();
}
while (dev_nr < total_devs) {
dev = bbio->stripes[dev_nr].dev;
if (!dev || !dev->bdev || (rw & WRITE && !dev->writeable)) {
bbio_error(bbio, first_bio, logical);
dev_nr++;
continue;
}
if (!bio_size_ok(dev->bdev, first_bio,
bbio->stripes[dev_nr].physical >> 9)) {
ret = breakup_stripe_bio(root, bbio, first_bio, dev,
dev_nr, rw, async_submit);
BUG_ON(ret);
dev_nr++;
continue;
}
if (dev_nr < total_devs - 1) {
bio = btrfs_bio_clone(first_bio, GFP_NOFS);
BUG_ON(!bio);
} else {
bio = first_bio;
}
submit_stripe_bio(root, bbio, bio,
bbio->stripes[dev_nr].physical, dev_nr, rw,
async_submit);
dev_nr++;
}
return 0;
}
struct btrfs_device *btrfs_find_device(struct btrfs_fs_info *fs_info, u64 devid,
u8 *uuid, u8 *fsid)
{
struct btrfs_device *device;
struct btrfs_fs_devices *cur_devices;
cur_devices = fs_info->fs_devices;
while (cur_devices) {
if (!fsid ||
!memcmp(cur_devices->fsid, fsid, BTRFS_UUID_SIZE)) {
device = __find_device(&cur_devices->devices,
devid, uuid);
if (device)
return device;
}
cur_devices = cur_devices->seed;
}
return NULL;
}
static struct btrfs_device *add_missing_dev(struct btrfs_root *root,
u64 devid, u8 *dev_uuid)
{
struct btrfs_device *device;
struct btrfs_fs_devices *fs_devices = root->fs_info->fs_devices;
device = btrfs_alloc_device(NULL, &devid, dev_uuid);
if (IS_ERR(device))
return NULL;
list_add(&device->dev_list, &fs_devices->devices);
device->fs_devices = fs_devices;
fs_devices->num_devices++;
device->missing = 1;
fs_devices->missing_devices++;
return device;
}
struct btrfs_device *btrfs_alloc_device(struct btrfs_fs_info *fs_info,
const u64 *devid,
const u8 *uuid)
{
struct btrfs_device *dev;
u64 tmp;
if (WARN_ON(!devid && !fs_info))
return ERR_PTR(-EINVAL);
dev = __alloc_device();
if (IS_ERR(dev))
return dev;
if (devid)
tmp = *devid;
else {
int ret;
ret = find_next_devid(fs_info, &tmp);
if (ret) {
kfree(dev);
return ERR_PTR(ret);
}
}
dev->devid = tmp;
if (uuid)
memcpy(dev->uuid, uuid, BTRFS_UUID_SIZE);
else
generate_random_uuid(dev->uuid);
dev->work.func = pending_bios_fn;
return dev;
}
static int read_one_chunk(struct btrfs_root *root, struct btrfs_key *key,
struct extent_buffer *leaf,
struct btrfs_chunk *chunk)
{
struct btrfs_mapping_tree *map_tree = &root->fs_info->mapping_tree;
struct map_lookup *map;
struct extent_map *em;
u64 logical;
u64 length;
u64 devid;
u8 uuid[BTRFS_UUID_SIZE];
int num_stripes;
int ret;
int i;
logical = key->offset;
length = btrfs_chunk_length(leaf, chunk);
read_lock(&map_tree->map_tree.lock);
em = lookup_extent_mapping(&map_tree->map_tree, logical, 1);
read_unlock(&map_tree->map_tree.lock);
if (em && em->start <= logical && em->start + em->len > logical) {
free_extent_map(em);
return 0;
} else if (em) {
free_extent_map(em);
}
em = alloc_extent_map();
if (!em)
return -ENOMEM;
num_stripes = btrfs_chunk_num_stripes(leaf, chunk);
map = kmalloc(map_lookup_size(num_stripes), GFP_NOFS);
if (!map) {
free_extent_map(em);
return -ENOMEM;
}
em->bdev = (struct block_device *)map;
em->start = logical;
em->len = length;
em->orig_start = 0;
em->block_start = 0;
em->block_len = em->len;
map->num_stripes = num_stripes;
map->io_width = btrfs_chunk_io_width(leaf, chunk);
map->io_align = btrfs_chunk_io_align(leaf, chunk);
map->sector_size = btrfs_chunk_sector_size(leaf, chunk);
map->stripe_len = btrfs_chunk_stripe_len(leaf, chunk);
map->type = btrfs_chunk_type(leaf, chunk);
map->sub_stripes = btrfs_chunk_sub_stripes(leaf, chunk);
for (i = 0; i < num_stripes; i++) {
map->stripes[i].physical =
btrfs_stripe_offset_nr(leaf, chunk, i);
devid = btrfs_stripe_devid_nr(leaf, chunk, i);
read_extent_buffer(leaf, uuid, (unsigned long)
btrfs_stripe_dev_uuid_nr(chunk, i),
BTRFS_UUID_SIZE);
map->stripes[i].dev = btrfs_find_device(root->fs_info, devid,
uuid, NULL);
if (!map->stripes[i].dev && !btrfs_test_opt(root, DEGRADED)) {
kfree(map);
free_extent_map(em);
return -EIO;
}
if (!map->stripes[i].dev) {
map->stripes[i].dev =
add_missing_dev(root, devid, uuid);
if (!map->stripes[i].dev) {
kfree(map);
free_extent_map(em);
return -EIO;
}
}
map->stripes[i].dev->in_fs_metadata = 1;
}
write_lock(&map_tree->map_tree.lock);
ret = add_extent_mapping(&map_tree->map_tree, em, 0);
write_unlock(&map_tree->map_tree.lock);
BUG_ON(ret);
free_extent_map(em);
return 0;
}
static void fill_device_from_item(struct extent_buffer *leaf,
struct btrfs_dev_item *dev_item,
struct btrfs_device *device)
{
unsigned long ptr;
device->devid = btrfs_device_id(leaf, dev_item);
device->disk_total_bytes = btrfs_device_total_bytes(leaf, dev_item);
device->total_bytes = device->disk_total_bytes;
device->bytes_used = btrfs_device_bytes_used(leaf, dev_item);
device->type = btrfs_device_type(leaf, dev_item);
device->io_align = btrfs_device_io_align(leaf, dev_item);
device->io_width = btrfs_device_io_width(leaf, dev_item);
device->sector_size = btrfs_device_sector_size(leaf, dev_item);
WARN_ON(device->devid == BTRFS_DEV_REPLACE_DEVID);
device->is_tgtdev_for_dev_replace = 0;
ptr = btrfs_device_uuid(dev_item);
read_extent_buffer(leaf, device->uuid, ptr, BTRFS_UUID_SIZE);
}
static int open_seed_devices(struct btrfs_root *root, u8 *fsid)
{
struct btrfs_fs_devices *fs_devices;
int ret;
BUG_ON(!mutex_is_locked(&uuid_mutex));
fs_devices = root->fs_info->fs_devices->seed;
while (fs_devices) {
if (!memcmp(fs_devices->fsid, fsid, BTRFS_UUID_SIZE)) {
ret = 0;
goto out;
}
fs_devices = fs_devices->seed;
}
fs_devices = find_fsid(fsid);
if (!fs_devices) {
ret = -ENOENT;
goto out;
}
fs_devices = clone_fs_devices(fs_devices);
if (IS_ERR(fs_devices)) {
ret = PTR_ERR(fs_devices);
goto out;
}
ret = __btrfs_open_devices(fs_devices, FMODE_READ,
root->fs_info->bdev_holder);
if (ret) {
free_fs_devices(fs_devices);
goto out;
}
if (!fs_devices->seeding) {
__btrfs_close_devices(fs_devices);
free_fs_devices(fs_devices);
ret = -EINVAL;
goto out;
}
fs_devices->seed = root->fs_info->fs_devices->seed;
root->fs_info->fs_devices->seed = fs_devices;
out:
return ret;
}
static int read_one_dev(struct btrfs_root *root,
struct extent_buffer *leaf,
struct btrfs_dev_item *dev_item)
{
struct btrfs_device *device;
u64 devid;
int ret;
u8 fs_uuid[BTRFS_UUID_SIZE];
u8 dev_uuid[BTRFS_UUID_SIZE];
devid = btrfs_device_id(leaf, dev_item);
read_extent_buffer(leaf, dev_uuid, btrfs_device_uuid(dev_item),
BTRFS_UUID_SIZE);
read_extent_buffer(leaf, fs_uuid, btrfs_device_fsid(dev_item),
BTRFS_UUID_SIZE);
if (memcmp(fs_uuid, root->fs_info->fsid, BTRFS_UUID_SIZE)) {
ret = open_seed_devices(root, fs_uuid);
if (ret && !btrfs_test_opt(root, DEGRADED))
return ret;
}
device = btrfs_find_device(root->fs_info, devid, dev_uuid, fs_uuid);
if (!device || !device->bdev) {
if (!btrfs_test_opt(root, DEGRADED))
return -EIO;
if (!device) {
btrfs_warn(root->fs_info, "devid %llu missing", devid);
device = add_missing_dev(root, devid, dev_uuid);
if (!device)
return -ENOMEM;
} else if (!device->missing) {
root->fs_info->fs_devices->missing_devices++;
device->missing = 1;
}
}
if (device->fs_devices != root->fs_info->fs_devices) {
BUG_ON(device->writeable);
if (device->generation !=
btrfs_device_generation(leaf, dev_item))
return -EINVAL;
}
fill_device_from_item(leaf, dev_item, device);
device->in_fs_metadata = 1;
if (device->writeable && !device->is_tgtdev_for_dev_replace) {
device->fs_devices->total_rw_bytes += device->total_bytes;
spin_lock(&root->fs_info->free_chunk_lock);
root->fs_info->free_chunk_space += device->total_bytes -
device->bytes_used;
spin_unlock(&root->fs_info->free_chunk_lock);
}
ret = 0;
return ret;
}
int btrfs_read_sys_array(struct btrfs_root *root)
{
struct btrfs_super_block *super_copy = root->fs_info->super_copy;
struct extent_buffer *sb;
struct btrfs_disk_key *disk_key;
struct btrfs_chunk *chunk;
u8 *ptr;
unsigned long sb_ptr;
int ret = 0;
u32 num_stripes;
u32 array_size;
u32 len = 0;
u32 cur;
struct btrfs_key key;
sb = btrfs_find_create_tree_block(root, BTRFS_SUPER_INFO_OFFSET,
BTRFS_SUPER_INFO_SIZE);
if (!sb)
return -ENOMEM;
btrfs_set_buffer_uptodate(sb);
btrfs_set_buffer_lockdep_class(root->root_key.objectid, sb, 0);
if (PAGE_CACHE_SIZE > BTRFS_SUPER_INFO_SIZE)
SetPageUptodate(sb->pages[0]);
write_extent_buffer(sb, super_copy, 0, BTRFS_SUPER_INFO_SIZE);
array_size = btrfs_super_sys_array_size(super_copy);
ptr = super_copy->sys_chunk_array;
sb_ptr = offsetof(struct btrfs_super_block, sys_chunk_array);
cur = 0;
while (cur < array_size) {
disk_key = (struct btrfs_disk_key *)ptr;
btrfs_disk_key_to_cpu(&key, disk_key);
len = sizeof(*disk_key); ptr += len;
sb_ptr += len;
cur += len;
if (key.type == BTRFS_CHUNK_ITEM_KEY) {
chunk = (struct btrfs_chunk *)sb_ptr;
ret = read_one_chunk(root, &key, sb, chunk);
if (ret)
break;
num_stripes = btrfs_chunk_num_stripes(sb, chunk);
len = btrfs_chunk_item_size(num_stripes);
} else {
ret = -EIO;
break;
}
ptr += len;
sb_ptr += len;
cur += len;
}
free_extent_buffer(sb);
return ret;
}
int btrfs_read_chunk_tree(struct btrfs_root *root)
{
struct btrfs_path *path;
struct extent_buffer *leaf;
struct btrfs_key key;
struct btrfs_key found_key;
int ret;
int slot;
root = root->fs_info->chunk_root;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
mutex_lock(&uuid_mutex);
lock_chunks(root);
key.objectid = BTRFS_DEV_ITEMS_OBJECTID;
key.offset = 0;
key.type = 0;
ret = btrfs_search_slot(NULL, root, &key, path, 0, 0);
if (ret < 0)
goto error;
while (1) {
leaf = path->nodes[0];
slot = path->slots[0];
if (slot >= btrfs_header_nritems(leaf)) {
ret = btrfs_next_leaf(root, path);
if (ret == 0)
continue;
if (ret < 0)
goto error;
break;
}
btrfs_item_key_to_cpu(leaf, &found_key, slot);
if (found_key.type == BTRFS_DEV_ITEM_KEY) {
struct btrfs_dev_item *dev_item;
dev_item = btrfs_item_ptr(leaf, slot,
struct btrfs_dev_item);
ret = read_one_dev(root, leaf, dev_item);
if (ret)
goto error;
} else if (found_key.type == BTRFS_CHUNK_ITEM_KEY) {
struct btrfs_chunk *chunk;
chunk = btrfs_item_ptr(leaf, slot, struct btrfs_chunk);
ret = read_one_chunk(root, &found_key, leaf, chunk);
if (ret)
goto error;
}
path->slots[0]++;
}
ret = 0;
error:
unlock_chunks(root);
mutex_unlock(&uuid_mutex);
btrfs_free_path(path);
return ret;
}
void btrfs_init_devices_late(struct btrfs_fs_info *fs_info)
{
struct btrfs_fs_devices *fs_devices = fs_info->fs_devices;
struct btrfs_device *device;
mutex_lock(&fs_devices->device_list_mutex);
list_for_each_entry(device, &fs_devices->devices, dev_list)
device->dev_root = fs_info->dev_root;
mutex_unlock(&fs_devices->device_list_mutex);
}
static void __btrfs_reset_dev_stats(struct btrfs_device *dev)
{
int i;
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++)
btrfs_dev_stat_reset(dev, i);
}
int btrfs_init_dev_stats(struct btrfs_fs_info *fs_info)
{
struct btrfs_key key;
struct btrfs_key found_key;
struct btrfs_root *dev_root = fs_info->dev_root;
struct btrfs_fs_devices *fs_devices = fs_info->fs_devices;
struct extent_buffer *eb;
int slot;
int ret = 0;
struct btrfs_device *device;
struct btrfs_path *path = NULL;
int i;
path = btrfs_alloc_path();
if (!path) {
ret = -ENOMEM;
goto out;
}
mutex_lock(&fs_devices->device_list_mutex);
list_for_each_entry(device, &fs_devices->devices, dev_list) {
int item_size;
struct btrfs_dev_stats_item *ptr;
key.objectid = 0;
key.type = BTRFS_DEV_STATS_KEY;
key.offset = device->devid;
ret = btrfs_search_slot(NULL, dev_root, &key, path, 0, 0);
if (ret) {
__btrfs_reset_dev_stats(device);
device->dev_stats_valid = 1;
btrfs_release_path(path);
continue;
}
slot = path->slots[0];
eb = path->nodes[0];
btrfs_item_key_to_cpu(eb, &found_key, slot);
item_size = btrfs_item_size_nr(eb, slot);
ptr = btrfs_item_ptr(eb, slot,
struct btrfs_dev_stats_item);
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++) {
if (item_size >= (1 + i) * sizeof(__le64))
btrfs_dev_stat_set(device, i,
btrfs_dev_stats_value(eb, ptr, i));
else
btrfs_dev_stat_reset(device, i);
}
device->dev_stats_valid = 1;
btrfs_dev_stat_print_on_load(device);
btrfs_release_path(path);
}
mutex_unlock(&fs_devices->device_list_mutex);
out:
btrfs_free_path(path);
return ret < 0 ? ret : 0;
}
static int update_dev_stat_item(struct btrfs_trans_handle *trans,
struct btrfs_root *dev_root,
struct btrfs_device *device)
{
struct btrfs_path *path;
struct btrfs_key key;
struct extent_buffer *eb;
struct btrfs_dev_stats_item *ptr;
int ret;
int i;
key.objectid = 0;
key.type = BTRFS_DEV_STATS_KEY;
key.offset = device->devid;
path = btrfs_alloc_path();
BUG_ON(!path);
ret = btrfs_search_slot(trans, dev_root, &key, path, -1, 1);
if (ret < 0) {
printk_in_rcu(KERN_WARNING "BTRFS: "
"error %d while searching for dev_stats item for device %s!\n",
ret, rcu_str_deref(device->name));
goto out;
}
if (ret == 0 &&
btrfs_item_size_nr(path->nodes[0], path->slots[0]) < sizeof(*ptr)) {
ret = btrfs_del_item(trans, dev_root, path);
if (ret != 0) {
printk_in_rcu(KERN_WARNING "BTRFS: "
"delete too small dev_stats item for device %s failed %d!\n",
rcu_str_deref(device->name), ret);
goto out;
}
ret = 1;
}
if (ret == 1) {
btrfs_release_path(path);
ret = btrfs_insert_empty_item(trans, dev_root, path,
&key, sizeof(*ptr));
if (ret < 0) {
printk_in_rcu(KERN_WARNING "BTRFS: "
"insert dev_stats item for device %s failed %d!\n",
rcu_str_deref(device->name), ret);
goto out;
}
}
eb = path->nodes[0];
ptr = btrfs_item_ptr(eb, path->slots[0], struct btrfs_dev_stats_item);
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++)
btrfs_set_dev_stats_value(eb, ptr, i,
btrfs_dev_stat_read(device, i));
btrfs_mark_buffer_dirty(eb);
out:
btrfs_free_path(path);
return ret;
}
int btrfs_run_dev_stats(struct btrfs_trans_handle *trans,
struct btrfs_fs_info *fs_info)
{
struct btrfs_root *dev_root = fs_info->dev_root;
struct btrfs_fs_devices *fs_devices = fs_info->fs_devices;
struct btrfs_device *device;
int ret = 0;
mutex_lock(&fs_devices->device_list_mutex);
list_for_each_entry(device, &fs_devices->devices, dev_list) {
if (!device->dev_stats_valid || !device->dev_stats_dirty)
continue;
ret = update_dev_stat_item(trans, dev_root, device);
if (!ret)
device->dev_stats_dirty = 0;
}
mutex_unlock(&fs_devices->device_list_mutex);
return ret;
}
void btrfs_dev_stat_inc_and_print(struct btrfs_device *dev, int index)
{
btrfs_dev_stat_inc(dev, index);
btrfs_dev_stat_print_on_error(dev);
}
static void btrfs_dev_stat_print_on_error(struct btrfs_device *dev)
{
if (!dev->dev_stats_valid)
return;
printk_ratelimited_in_rcu(KERN_ERR "BTRFS: "
"bdev %s errs: wr %u, rd %u, flush %u, corrupt %u, gen %u\n",
rcu_str_deref(dev->name),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_WRITE_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_READ_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_FLUSH_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_CORRUPTION_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_GENERATION_ERRS));
}
static void btrfs_dev_stat_print_on_load(struct btrfs_device *dev)
{
int i;
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++)
if (btrfs_dev_stat_read(dev, i) != 0)
break;
if (i == BTRFS_DEV_STAT_VALUES_MAX)
return;
printk_in_rcu(KERN_INFO "BTRFS: "
"bdev %s errs: wr %u, rd %u, flush %u, corrupt %u, gen %u\n",
rcu_str_deref(dev->name),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_WRITE_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_READ_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_FLUSH_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_CORRUPTION_ERRS),
btrfs_dev_stat_read(dev, BTRFS_DEV_STAT_GENERATION_ERRS));
}
int btrfs_get_dev_stats(struct btrfs_root *root,
struct btrfs_ioctl_get_dev_stats *stats)
{
struct btrfs_device *dev;
struct btrfs_fs_devices *fs_devices = root->fs_info->fs_devices;
int i;
mutex_lock(&fs_devices->device_list_mutex);
dev = btrfs_find_device(root->fs_info, stats->devid, NULL, NULL);
mutex_unlock(&fs_devices->device_list_mutex);
if (!dev) {
btrfs_warn(root->fs_info, "get dev_stats failed, device not found");
return -ENODEV;
} else if (!dev->dev_stats_valid) {
btrfs_warn(root->fs_info, "get dev_stats failed, not yet valid");
return -ENODEV;
} else if (stats->flags & BTRFS_DEV_STATS_RESET) {
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++) {
if (stats->nr_items > i)
stats->values[i] =
btrfs_dev_stat_read_and_reset(dev, i);
else
btrfs_dev_stat_reset(dev, i);
}
} else {
for (i = 0; i < BTRFS_DEV_STAT_VALUES_MAX; i++)
if (stats->nr_items > i)
stats->values[i] = btrfs_dev_stat_read(dev, i);
}
if (stats->nr_items > BTRFS_DEV_STAT_VALUES_MAX)
stats->nr_items = BTRFS_DEV_STAT_VALUES_MAX;
return 0;
}
int btrfs_scratch_superblock(struct btrfs_device *device)
{
struct buffer_head *bh;
struct btrfs_super_block *disk_super;
bh = btrfs_read_dev_super(device->bdev);
if (!bh)
return -EINVAL;
disk_super = (struct btrfs_super_block *)bh->b_data;
memset(&disk_super->magic, 0, sizeof(disk_super->magic));
set_buffer_dirty(bh);
sync_dirty_buffer(bh);
brelse(bh);
return 0;
}
