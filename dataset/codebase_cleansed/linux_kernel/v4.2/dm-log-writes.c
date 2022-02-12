static void put_pending_block(struct log_writes_c *lc)
{
if (atomic_dec_and_test(&lc->pending_blocks)) {
smp_mb__after_atomic();
if (waitqueue_active(&lc->wait))
wake_up(&lc->wait);
}
}
static void put_io_block(struct log_writes_c *lc)
{
if (atomic_dec_and_test(&lc->io_blocks)) {
smp_mb__after_atomic();
if (waitqueue_active(&lc->wait))
wake_up(&lc->wait);
}
}
static void log_end_io(struct bio *bio, int err)
{
struct log_writes_c *lc = bio->bi_private;
struct bio_vec *bvec;
int i;
if (err) {
unsigned long flags;
DMERR("Error writing log block, error=%d", err);
spin_lock_irqsave(&lc->blocks_lock, flags);
lc->logging_enabled = false;
spin_unlock_irqrestore(&lc->blocks_lock, flags);
}
bio_for_each_segment_all(bvec, bio, i)
__free_page(bvec->bv_page);
put_io_block(lc);
bio_put(bio);
}
static void free_pending_block(struct log_writes_c *lc,
struct pending_block *block)
{
int i;
for (i = 0; i < block->vec_cnt; i++) {
if (block->vecs[i].bv_page)
__free_page(block->vecs[i].bv_page);
}
kfree(block->data);
kfree(block);
put_pending_block(lc);
}
static int write_metadata(struct log_writes_c *lc, void *entry,
size_t entrylen, void *data, size_t datalen,
sector_t sector)
{
struct bio *bio;
struct page *page;
void *ptr;
size_t ret;
bio = bio_alloc(GFP_KERNEL, 1);
if (!bio) {
DMERR("Couldn't alloc log bio");
goto error;
}
bio->bi_iter.bi_size = 0;
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = lc->logdev->bdev;
bio->bi_end_io = log_end_io;
bio->bi_private = lc;
set_bit(BIO_UPTODATE, &bio->bi_flags);
page = alloc_page(GFP_KERNEL);
if (!page) {
DMERR("Couldn't alloc log page");
bio_put(bio);
goto error;
}
ptr = kmap_atomic(page);
memcpy(ptr, entry, entrylen);
if (datalen)
memcpy(ptr + entrylen, data, datalen);
memset(ptr + entrylen + datalen, 0,
lc->sectorsize - entrylen - datalen);
kunmap_atomic(ptr);
ret = bio_add_page(bio, page, lc->sectorsize, 0);
if (ret != lc->sectorsize) {
DMERR("Couldn't add page to the log block");
goto error_bio;
}
submit_bio(WRITE, bio);
return 0;
error_bio:
bio_put(bio);
__free_page(page);
error:
put_io_block(lc);
return -1;
}
static int log_one_block(struct log_writes_c *lc,
struct pending_block *block, sector_t sector)
{
struct bio *bio;
struct log_write_entry entry;
size_t ret;
int i;
entry.sector = cpu_to_le64(block->sector);
entry.nr_sectors = cpu_to_le64(block->nr_sectors);
entry.flags = cpu_to_le64(block->flags);
entry.data_len = cpu_to_le64(block->datalen);
if (write_metadata(lc, &entry, sizeof(entry), block->data,
block->datalen, sector)) {
free_pending_block(lc, block);
return -1;
}
if (!block->vec_cnt)
goto out;
sector++;
bio = bio_alloc(GFP_KERNEL, block->vec_cnt);
if (!bio) {
DMERR("Couldn't alloc log bio");
goto error;
}
atomic_inc(&lc->io_blocks);
bio->bi_iter.bi_size = 0;
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = lc->logdev->bdev;
bio->bi_end_io = log_end_io;
bio->bi_private = lc;
set_bit(BIO_UPTODATE, &bio->bi_flags);
for (i = 0; i < block->vec_cnt; i++) {
ret = bio_add_page(bio, block->vecs[i].bv_page,
block->vecs[i].bv_len, 0);
if (ret != block->vecs[i].bv_len) {
atomic_inc(&lc->io_blocks);
submit_bio(WRITE, bio);
bio = bio_alloc(GFP_KERNEL, block->vec_cnt - i);
if (!bio) {
DMERR("Couldn't alloc log bio");
goto error;
}
bio->bi_iter.bi_size = 0;
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = lc->logdev->bdev;
bio->bi_end_io = log_end_io;
bio->bi_private = lc;
set_bit(BIO_UPTODATE, &bio->bi_flags);
ret = bio_add_page(bio, block->vecs[i].bv_page,
block->vecs[i].bv_len, 0);
if (ret != block->vecs[i].bv_len) {
DMERR("Couldn't add page on new bio?");
bio_put(bio);
goto error;
}
}
sector += block->vecs[i].bv_len >> SECTOR_SHIFT;
}
submit_bio(WRITE, bio);
out:
kfree(block->data);
kfree(block);
put_pending_block(lc);
return 0;
error:
free_pending_block(lc, block);
put_io_block(lc);
return -1;
}
static int log_super(struct log_writes_c *lc)
{
struct log_write_super super;
super.magic = cpu_to_le64(WRITE_LOG_MAGIC);
super.version = cpu_to_le64(WRITE_LOG_VERSION);
super.nr_entries = cpu_to_le64(lc->logged_entries);
super.sectorsize = cpu_to_le32(lc->sectorsize);
if (write_metadata(lc, &super, sizeof(super), NULL, 0, 0)) {
DMERR("Couldn't write super");
return -1;
}
return 0;
}
static inline sector_t logdev_last_sector(struct log_writes_c *lc)
{
return i_size_read(lc->logdev->bdev->bd_inode) >> SECTOR_SHIFT;
}
static int log_writes_kthread(void *arg)
{
struct log_writes_c *lc = (struct log_writes_c *)arg;
sector_t sector = 0;
while (!kthread_should_stop()) {
bool super = false;
bool logging_enabled;
struct pending_block *block = NULL;
int ret;
spin_lock_irq(&lc->blocks_lock);
if (!list_empty(&lc->logging_blocks)) {
block = list_first_entry(&lc->logging_blocks,
struct pending_block, list);
list_del_init(&block->list);
if (!lc->logging_enabled)
goto next;
sector = lc->next_sector;
if (block->flags & LOG_DISCARD_FLAG)
lc->next_sector++;
else
lc->next_sector += block->nr_sectors + 1;
if (!lc->end_sector)
lc->end_sector = logdev_last_sector(lc);
if (lc->end_sector &&
lc->next_sector >= lc->end_sector) {
DMERR("Ran out of space on the logdev");
lc->logging_enabled = false;
goto next;
}
lc->logged_entries++;
atomic_inc(&lc->io_blocks);
super = (block->flags & (LOG_FUA_FLAG | LOG_MARK_FLAG));
if (super)
atomic_inc(&lc->io_blocks);
}
next:
logging_enabled = lc->logging_enabled;
spin_unlock_irq(&lc->blocks_lock);
if (block) {
if (logging_enabled) {
ret = log_one_block(lc, block, sector);
if (!ret && super)
ret = log_super(lc);
if (ret) {
spin_lock_irq(&lc->blocks_lock);
lc->logging_enabled = false;
spin_unlock_irq(&lc->blocks_lock);
}
} else
free_pending_block(lc, block);
continue;
}
if (!try_to_freeze()) {
set_current_state(TASK_INTERRUPTIBLE);
if (!kthread_should_stop() &&
!atomic_read(&lc->pending_blocks))
schedule();
__set_current_state(TASK_RUNNING);
}
}
return 0;
}
static int log_writes_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
struct log_writes_c *lc;
struct dm_arg_set as;
const char *devname, *logdevname;
as.argc = argc;
as.argv = argv;
if (argc < 2) {
ti->error = "Invalid argument count";
return -EINVAL;
}
lc = kzalloc(sizeof(struct log_writes_c), GFP_KERNEL);
if (!lc) {
ti->error = "Cannot allocate context";
return -ENOMEM;
}
spin_lock_init(&lc->blocks_lock);
INIT_LIST_HEAD(&lc->unflushed_blocks);
INIT_LIST_HEAD(&lc->logging_blocks);
init_waitqueue_head(&lc->wait);
lc->sectorsize = 1 << SECTOR_SHIFT;
atomic_set(&lc->io_blocks, 0);
atomic_set(&lc->pending_blocks, 0);
devname = dm_shift_arg(&as);
if (dm_get_device(ti, devname, dm_table_get_mode(ti->table), &lc->dev)) {
ti->error = "Device lookup failed";
goto bad;
}
logdevname = dm_shift_arg(&as);
if (dm_get_device(ti, logdevname, dm_table_get_mode(ti->table), &lc->logdev)) {
ti->error = "Log device lookup failed";
dm_put_device(ti, lc->dev);
goto bad;
}
lc->log_kthread = kthread_run(log_writes_kthread, lc, "log-write");
if (!lc->log_kthread) {
ti->error = "Couldn't alloc kthread";
dm_put_device(ti, lc->dev);
dm_put_device(ti, lc->logdev);
goto bad;
}
lc->next_sector = 1;
lc->logging_enabled = true;
lc->end_sector = logdev_last_sector(lc);
lc->device_supports_discard = true;
ti->num_flush_bios = 1;
ti->flush_supported = true;
ti->num_discard_bios = 1;
ti->discards_supported = true;
ti->per_bio_data_size = sizeof(struct per_bio_data);
ti->private = lc;
return 0;
bad:
kfree(lc);
return -EINVAL;
}
static int log_mark(struct log_writes_c *lc, char *data)
{
struct pending_block *block;
size_t maxsize = lc->sectorsize - sizeof(struct log_write_entry);
block = kzalloc(sizeof(struct pending_block), GFP_KERNEL);
if (!block) {
DMERR("Error allocating pending block");
return -ENOMEM;
}
block->data = kstrndup(data, maxsize, GFP_KERNEL);
if (!block->data) {
DMERR("Error copying mark data");
kfree(block);
return -ENOMEM;
}
atomic_inc(&lc->pending_blocks);
block->datalen = strlen(block->data);
block->flags |= LOG_MARK_FLAG;
spin_lock_irq(&lc->blocks_lock);
list_add_tail(&block->list, &lc->logging_blocks);
spin_unlock_irq(&lc->blocks_lock);
wake_up_process(lc->log_kthread);
return 0;
}
static void log_writes_dtr(struct dm_target *ti)
{
struct log_writes_c *lc = ti->private;
spin_lock_irq(&lc->blocks_lock);
list_splice_init(&lc->unflushed_blocks, &lc->logging_blocks);
spin_unlock_irq(&lc->blocks_lock);
log_mark(lc, "dm-log-writes-end");
wake_up_process(lc->log_kthread);
wait_event(lc->wait, !atomic_read(&lc->io_blocks) &&
!atomic_read(&lc->pending_blocks));
kthread_stop(lc->log_kthread);
WARN_ON(!list_empty(&lc->logging_blocks));
WARN_ON(!list_empty(&lc->unflushed_blocks));
dm_put_device(ti, lc->dev);
dm_put_device(ti, lc->logdev);
kfree(lc);
}
static void normal_map_bio(struct dm_target *ti, struct bio *bio)
{
struct log_writes_c *lc = ti->private;
bio->bi_bdev = lc->dev->bdev;
}
static int log_writes_map(struct dm_target *ti, struct bio *bio)
{
struct log_writes_c *lc = ti->private;
struct per_bio_data *pb = dm_per_bio_data(bio, sizeof(struct per_bio_data));
struct pending_block *block;
struct bvec_iter iter;
struct bio_vec bv;
size_t alloc_size;
int i = 0;
bool flush_bio = (bio->bi_rw & REQ_FLUSH);
bool fua_bio = (bio->bi_rw & REQ_FUA);
bool discard_bio = (bio->bi_rw & REQ_DISCARD);
pb->block = NULL;
if (!lc->logging_enabled)
goto map_bio;
if (bio_data_dir(bio) == READ)
goto map_bio;
if (!bio_sectors(bio) && !flush_bio)
goto map_bio;
if (discard_bio)
alloc_size = sizeof(struct pending_block);
else
alloc_size = sizeof(struct pending_block) + sizeof(struct bio_vec) * bio_segments(bio);
block = kzalloc(alloc_size, GFP_NOIO);
if (!block) {
DMERR("Error allocating pending block");
spin_lock_irq(&lc->blocks_lock);
lc->logging_enabled = false;
spin_unlock_irq(&lc->blocks_lock);
return -ENOMEM;
}
INIT_LIST_HEAD(&block->list);
pb->block = block;
atomic_inc(&lc->pending_blocks);
if (flush_bio)
block->flags |= LOG_FLUSH_FLAG;
if (fua_bio)
block->flags |= LOG_FUA_FLAG;
if (discard_bio)
block->flags |= LOG_DISCARD_FLAG;
block->sector = bio->bi_iter.bi_sector;
block->nr_sectors = bio_sectors(bio);
if (discard_bio) {
WARN_ON(flush_bio || fua_bio);
if (lc->device_supports_discard)
goto map_bio;
bio_endio(bio, 0);
return DM_MAPIO_SUBMITTED;
}
if (flush_bio && !bio_sectors(bio)) {
spin_lock_irq(&lc->blocks_lock);
list_splice_init(&lc->unflushed_blocks, &block->list);
spin_unlock_irq(&lc->blocks_lock);
goto map_bio;
}
bio_for_each_segment(bv, bio, iter) {
struct page *page;
void *src, *dst;
page = alloc_page(GFP_NOIO);
if (!page) {
DMERR("Error allocing page");
free_pending_block(lc, block);
spin_lock_irq(&lc->blocks_lock);
lc->logging_enabled = false;
spin_unlock_irq(&lc->blocks_lock);
return -ENOMEM;
}
src = kmap_atomic(bv.bv_page);
dst = kmap_atomic(page);
memcpy(dst, src + bv.bv_offset, bv.bv_len);
kunmap_atomic(dst);
kunmap_atomic(src);
block->vecs[i].bv_page = page;
block->vecs[i].bv_len = bv.bv_len;
block->vec_cnt++;
i++;
}
if (flush_bio) {
spin_lock_irq(&lc->blocks_lock);
list_splice_init(&lc->unflushed_blocks, &block->list);
spin_unlock_irq(&lc->blocks_lock);
}
map_bio:
normal_map_bio(ti, bio);
return DM_MAPIO_REMAPPED;
}
static int normal_end_io(struct dm_target *ti, struct bio *bio, int error)
{
struct log_writes_c *lc = ti->private;
struct per_bio_data *pb = dm_per_bio_data(bio, sizeof(struct per_bio_data));
if (bio_data_dir(bio) == WRITE && pb->block) {
struct pending_block *block = pb->block;
unsigned long flags;
spin_lock_irqsave(&lc->blocks_lock, flags);
if (block->flags & LOG_FLUSH_FLAG) {
list_splice_tail_init(&block->list, &lc->logging_blocks);
list_add_tail(&block->list, &lc->logging_blocks);
wake_up_process(lc->log_kthread);
} else if (block->flags & LOG_FUA_FLAG) {
list_add_tail(&block->list, &lc->logging_blocks);
wake_up_process(lc->log_kthread);
} else
list_add_tail(&block->list, &lc->unflushed_blocks);
spin_unlock_irqrestore(&lc->blocks_lock, flags);
}
return error;
}
static void log_writes_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result,
unsigned maxlen)
{
unsigned sz = 0;
struct log_writes_c *lc = ti->private;
switch (type) {
case STATUSTYPE_INFO:
DMEMIT("%llu %llu", lc->logged_entries,
(unsigned long long)lc->next_sector - 1);
if (!lc->logging_enabled)
DMEMIT(" logging_disabled");
break;
case STATUSTYPE_TABLE:
DMEMIT("%s %s", lc->dev->name, lc->logdev->name);
break;
}
}
static int log_writes_ioctl(struct dm_target *ti, unsigned int cmd,
unsigned long arg)
{
struct log_writes_c *lc = ti->private;
struct dm_dev *dev = lc->dev;
int r = 0;
if (ti->len != i_size_read(dev->bdev->bd_inode) >> SECTOR_SHIFT)
r = scsi_verify_blk_ioctl(NULL, cmd);
return r ? : __blkdev_driver_ioctl(dev->bdev, dev->mode, cmd, arg);
}
static int log_writes_merge(struct dm_target *ti, struct bvec_merge_data *bvm,
struct bio_vec *biovec, int max_size)
{
struct log_writes_c *lc = ti->private;
struct request_queue *q = bdev_get_queue(lc->dev->bdev);
if (!q->merge_bvec_fn)
return max_size;
bvm->bi_bdev = lc->dev->bdev;
bvm->bi_sector = dm_target_offset(ti, bvm->bi_sector);
return min(max_size, q->merge_bvec_fn(q, bvm, biovec));
}
static int log_writes_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn,
void *data)
{
struct log_writes_c *lc = ti->private;
return fn(ti, lc->dev, 0, ti->len, data);
}
static int log_writes_message(struct dm_target *ti, unsigned argc, char **argv)
{
int r = -EINVAL;
struct log_writes_c *lc = ti->private;
if (argc != 2) {
DMWARN("Invalid log-writes message arguments, expect 2 arguments, got %d", argc);
return r;
}
if (!strcasecmp(argv[0], "mark"))
r = log_mark(lc, argv[1]);
else
DMWARN("Unrecognised log writes target message received: %s", argv[0]);
return r;
}
static void log_writes_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct log_writes_c *lc = ti->private;
struct request_queue *q = bdev_get_queue(lc->dev->bdev);
if (!q || !blk_queue_discard(q)) {
lc->device_supports_discard = false;
limits->discard_granularity = 1 << SECTOR_SHIFT;
limits->max_discard_sectors = (UINT_MAX >> SECTOR_SHIFT);
}
}
static int __init dm_log_writes_init(void)
{
int r = dm_register_target(&log_writes_target);
if (r < 0)
DMERR("register failed %d", r);
return r;
}
static void __exit dm_log_writes_exit(void)
{
dm_unregister_target(&log_writes_target);
}
