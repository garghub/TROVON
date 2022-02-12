static loff_t get_loop_size(struct lloop_device *lo, struct file *file)
{
loff_t size, offset, loopsize;
size = i_size_read(file->f_mapping->host);
offset = lo->lo_offset;
loopsize = size - offset;
if (lo->lo_sizelimit > 0 && lo->lo_sizelimit < loopsize)
loopsize = lo->lo_sizelimit;
return loopsize >> 9;
}
static int do_bio_lustrebacked(struct lloop_device *lo, struct bio *head)
{
const struct lu_env *env = lo->lo_env;
struct cl_io *io = &lo->lo_io;
struct inode *inode = file_inode(lo->lo_backing_file);
struct cl_object *obj = ll_i2info(inode)->lli_clob;
pgoff_t offset;
int ret;
int rw;
u32 page_count = 0;
struct bio_vec bvec;
struct bvec_iter iter;
struct bio *bio;
ssize_t bytes;
struct ll_dio_pages *pvec = &lo->lo_pvec;
struct page **pages = pvec->ldp_pages;
loff_t *offsets = pvec->ldp_offsets;
truncate_inode_pages(inode->i_mapping, 0);
memset(io, 0, sizeof(*io));
io->ci_obj = obj;
ret = cl_io_init(env, io, CIT_MISC, obj);
if (ret)
return io->ci_result;
io->ci_lockreq = CILR_NEVER;
rw = head->bi_rw;
for (bio = head; bio ; bio = bio->bi_next) {
LASSERT(rw == bio->bi_rw);
offset = (pgoff_t)(bio->bi_iter.bi_sector << 9) + lo->lo_offset;
bio_for_each_segment(bvec, bio, iter) {
BUG_ON(bvec.bv_offset != 0);
BUG_ON(bvec.bv_len != PAGE_SIZE);
pages[page_count] = bvec.bv_page;
offsets[page_count] = offset;
page_count++;
offset += bvec.bv_len;
}
LASSERT(page_count <= LLOOP_MAX_SEGMENTS);
}
ll_stats_ops_tally(ll_i2sbi(inode),
(rw == WRITE) ? LPROC_LL_BRW_WRITE : LPROC_LL_BRW_READ,
page_count);
pvec->ldp_size = page_count << PAGE_SHIFT;
pvec->ldp_nr = page_count;
inode_lock(inode);
bytes = ll_direct_rw_pages(env, io, rw, inode, pvec);
inode_unlock(inode);
cl_io_fini(env, io);
return (bytes == pvec->ldp_size) ? 0 : (int)bytes;
}
static void loop_add_bio(struct lloop_device *lo, struct bio *bio)
{
unsigned long flags;
spin_lock_irqsave(&lo->lo_lock, flags);
if (lo->lo_biotail) {
lo->lo_biotail->bi_next = bio;
lo->lo_biotail = bio;
} else {
lo->lo_bio = lo->lo_biotail = bio;
}
spin_unlock_irqrestore(&lo->lo_lock, flags);
atomic_inc(&lo->lo_pending);
if (waitqueue_active(&lo->lo_bh_wait))
wake_up(&lo->lo_bh_wait);
}
static unsigned int loop_get_bio(struct lloop_device *lo, struct bio **req)
{
struct bio *first;
struct bio **bio;
unsigned int count = 0;
unsigned int page_count = 0;
int rw;
spin_lock_irq(&lo->lo_lock);
first = lo->lo_bio;
if (unlikely(!first)) {
spin_unlock_irq(&lo->lo_lock);
return 0;
}
LASSERT(first->bi_vcnt <= LLOOP_MAX_SEGMENTS);
rw = first->bi_rw;
bio = &lo->lo_bio;
while (*bio && (*bio)->bi_rw == rw) {
CDEBUG(D_INFO, "bio sector %llu size %u count %u vcnt%u\n",
(unsigned long long)(*bio)->bi_iter.bi_sector,
(*bio)->bi_iter.bi_size,
page_count, (*bio)->bi_vcnt);
if (page_count + (*bio)->bi_vcnt > LLOOP_MAX_SEGMENTS)
break;
page_count += (*bio)->bi_vcnt;
count++;
bio = &(*bio)->bi_next;
}
if (*bio) {
lo->lo_bio = *bio;
*bio = NULL;
} else {
lo->lo_biotail = NULL;
lo->lo_bio = NULL;
}
*req = first;
spin_unlock_irq(&lo->lo_lock);
return count;
}
static blk_qc_t loop_make_request(struct request_queue *q, struct bio *old_bio)
{
struct lloop_device *lo = q->queuedata;
int rw = bio_rw(old_bio);
int inactive;
blk_queue_split(q, &old_bio, q->bio_split);
if (!lo)
goto err;
CDEBUG(D_INFO, "submit bio sector %llu size %u\n",
(unsigned long long)old_bio->bi_iter.bi_sector,
old_bio->bi_iter.bi_size);
spin_lock_irq(&lo->lo_lock);
inactive = lo->lo_state != LLOOP_BOUND;
spin_unlock_irq(&lo->lo_lock);
if (inactive)
goto err;
if (rw == WRITE) {
if (lo->lo_flags & LO_FLAGS_READ_ONLY)
goto err;
} else if (rw == READA) {
rw = READ;
} else if (rw != READ) {
CERROR("lloop: unknown command (%x)\n", rw);
goto err;
}
loop_add_bio(lo, old_bio);
return BLK_QC_T_NONE;
err:
bio_io_error(old_bio);
return BLK_QC_T_NONE;
}
static inline void loop_handle_bio(struct lloop_device *lo, struct bio *bio)
{
int ret;
ret = do_bio_lustrebacked(lo, bio);
while (bio) {
struct bio *tmp = bio->bi_next;
bio->bi_next = NULL;
bio->bi_error = ret;
bio_endio(bio);
bio = tmp;
}
}
static inline int loop_active(struct lloop_device *lo)
{
return atomic_read(&lo->lo_pending) ||
(lo->lo_state == LLOOP_RUNDOWN);
}
static int loop_thread(void *data)
{
struct lloop_device *lo = data;
struct bio *bio;
unsigned int count;
unsigned long times = 0;
unsigned long total_count = 0;
struct lu_env *env;
int refcheck;
int ret = 0;
set_user_nice(current, MIN_NICE);
lo->lo_state = LLOOP_BOUND;
env = cl_env_get(&refcheck);
if (IS_ERR(env)) {
ret = PTR_ERR(env);
goto out;
}
lo->lo_env = env;
memset(&lo->lo_pvec, 0, sizeof(lo->lo_pvec));
lo->lo_pvec.ldp_pages = lo->lo_requests[0].lrd_pages;
lo->lo_pvec.ldp_offsets = lo->lo_requests[0].lrd_offsets;
up(&lo->lo_sem);
for (;;) {
wait_event(lo->lo_bh_wait, loop_active(lo));
if (!atomic_read(&lo->lo_pending)) {
int exiting = 0;
spin_lock_irq(&lo->lo_lock);
exiting = (lo->lo_state == LLOOP_RUNDOWN);
spin_unlock_irq(&lo->lo_lock);
if (exiting)
break;
}
bio = NULL;
count = loop_get_bio(lo, &bio);
if (!count) {
CWARN("lloop(minor: %d): missing bio\n", lo->lo_number);
continue;
}
total_count += count;
if (total_count < count) {
total_count = count;
times = 1;
} else {
times++;
}
if ((times & 127) == 0) {
CDEBUG(D_INFO, "total: %lu, count: %lu, avg: %lu\n",
total_count, times, total_count / times);
}
LASSERT(bio);
LASSERT(count <= atomic_read(&lo->lo_pending));
loop_handle_bio(lo, bio);
atomic_sub(count, &lo->lo_pending);
}
cl_env_put(env, &refcheck);
out:
up(&lo->lo_sem);
return ret;
}
static int loop_set_fd(struct lloop_device *lo, struct file *unused,
struct block_device *bdev, struct file *file)
{
struct inode *inode;
struct address_space *mapping;
int lo_flags = 0;
int error;
loff_t size;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
error = -EBUSY;
if (lo->lo_state != LLOOP_UNBOUND)
goto out;
mapping = file->f_mapping;
inode = mapping->host;
error = -EINVAL;
if (!S_ISREG(inode->i_mode) || inode->i_sb->s_magic != LL_SUPER_MAGIC)
goto out;
if (!(file->f_mode & FMODE_WRITE))
lo_flags |= LO_FLAGS_READ_ONLY;
size = get_loop_size(lo, file);
if ((loff_t)(sector_t)size != size) {
error = -EFBIG;
goto out;
}
truncate_inode_pages(mapping, 0);
set_device_ro(bdev, (lo_flags & LO_FLAGS_READ_ONLY) != 0);
lo->lo_blocksize = PAGE_SIZE;
lo->lo_device = bdev;
lo->lo_flags = lo_flags;
lo->lo_backing_file = file;
lo->lo_sizelimit = 0;
lo->old_gfp_mask = mapping_gfp_mask(mapping);
mapping_set_gfp_mask(mapping, lo->old_gfp_mask & ~(__GFP_IO|__GFP_FS));
lo->lo_bio = lo->lo_biotail = NULL;
blk_queue_make_request(lo->lo_queue, loop_make_request);
lo->lo_queue->queuedata = lo;
CLASSERT(PAGE_SIZE < (1 << (sizeof(unsigned short) * 8)));
blk_queue_logical_block_size(lo->lo_queue,
(unsigned short)PAGE_SIZE);
blk_queue_max_hw_sectors(lo->lo_queue,
LLOOP_MAX_SEGMENTS << (PAGE_SHIFT - 9));
blk_queue_max_segments(lo->lo_queue, LLOOP_MAX_SEGMENTS);
set_capacity(disks[lo->lo_number], size);
bd_set_size(bdev, size << 9);
set_blocksize(bdev, lo->lo_blocksize);
kthread_run(loop_thread, lo, "lloop%d", lo->lo_number);
down(&lo->lo_sem);
return 0;
out:
module_put(THIS_MODULE);
return error;
}
static int loop_clr_fd(struct lloop_device *lo, struct block_device *bdev,
int count)
{
struct file *filp = lo->lo_backing_file;
gfp_t gfp = lo->old_gfp_mask;
if (lo->lo_state != LLOOP_BOUND)
return -ENXIO;
if (lo->lo_refcnt > count)
return -EBUSY;
if (!filp)
return -EINVAL;
spin_lock_irq(&lo->lo_lock);
lo->lo_state = LLOOP_RUNDOWN;
spin_unlock_irq(&lo->lo_lock);
wake_up(&lo->lo_bh_wait);
down(&lo->lo_sem);
lo->lo_backing_file = NULL;
lo->lo_device = NULL;
lo->lo_offset = 0;
lo->lo_sizelimit = 0;
lo->lo_flags = 0;
invalidate_bdev(bdev);
set_capacity(disks[lo->lo_number], 0);
bd_set_size(bdev, 0);
mapping_set_gfp_mask(filp->f_mapping, gfp);
lo->lo_state = LLOOP_UNBOUND;
fput(filp);
module_put(THIS_MODULE);
return 0;
}
static int lo_open(struct block_device *bdev, fmode_t mode)
{
struct lloop_device *lo = bdev->bd_disk->private_data;
mutex_lock(&lo->lo_ctl_mutex);
lo->lo_refcnt++;
mutex_unlock(&lo->lo_ctl_mutex);
return 0;
}
static void lo_release(struct gendisk *disk, fmode_t mode)
{
struct lloop_device *lo = disk->private_data;
mutex_lock(&lo->lo_ctl_mutex);
--lo->lo_refcnt;
mutex_unlock(&lo->lo_ctl_mutex);
}
static int lo_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct lloop_device *lo = bdev->bd_disk->private_data;
struct inode *inode = NULL;
int err = 0;
mutex_lock(&lloop_mutex);
switch (cmd) {
case LL_IOC_LLOOP_DETACH: {
err = loop_clr_fd(lo, bdev, 2);
if (err == 0)
blkdev_put(bdev, 0);
break;
}
case LL_IOC_LLOOP_INFO: {
struct lu_fid fid;
if (!lo->lo_backing_file) {
err = -ENOENT;
break;
}
if (!inode)
inode = file_inode(lo->lo_backing_file);
if (lo->lo_state == LLOOP_BOUND)
fid = ll_i2info(inode)->lli_fid;
else
fid_zero(&fid);
if (copy_to_user((void __user *)arg, &fid, sizeof(fid)))
err = -EFAULT;
break;
}
default:
err = -EINVAL;
break;
}
mutex_unlock(&lloop_mutex);
return err;
}
static enum llioc_iter lloop_ioctl(struct inode *unused, struct file *file,
unsigned int cmd, unsigned long arg,
void *magic, int *rcp)
{
struct lloop_device *lo = NULL;
struct block_device *bdev = NULL;
int err = 0;
dev_t dev;
if (magic != ll_iocontrol_magic)
return LLIOC_CONT;
if (!disks) {
err = -ENODEV;
goto out1;
}
CWARN("Enter llop_ioctl\n");
mutex_lock(&lloop_mutex);
switch (cmd) {
case LL_IOC_LLOOP_ATTACH: {
struct lloop_device *lo_free = NULL;
int i;
for (i = 0; i < max_loop; i++, lo = NULL) {
lo = &loop_dev[i];
if (lo->lo_state == LLOOP_UNBOUND) {
if (!lo_free)
lo_free = lo;
continue;
}
if (file_inode(lo->lo_backing_file) == file_inode(file))
break;
}
if (lo || !lo_free) {
err = -EBUSY;
goto out;
}
lo = lo_free;
dev = MKDEV(lloop_major, lo->lo_number);
if (put_user((long)old_encode_dev(dev), (long __user *)arg)) {
err = -EFAULT;
goto out;
}
bdev = blkdev_get_by_dev(dev, file->f_mode, NULL);
if (IS_ERR(bdev)) {
err = PTR_ERR(bdev);
goto out;
}
get_file(file);
err = loop_set_fd(lo, NULL, bdev, file);
if (err) {
fput(file);
blkdev_put(bdev, 0);
}
break;
}
case LL_IOC_LLOOP_DETACH_BYDEV: {
int minor;
dev = old_decode_dev(arg);
if (MAJOR(dev) != lloop_major) {
err = -EINVAL;
goto out;
}
minor = MINOR(dev);
if (minor > max_loop - 1) {
err = -EINVAL;
goto out;
}
lo = &loop_dev[minor];
if (lo->lo_state != LLOOP_BOUND) {
err = -EINVAL;
goto out;
}
bdev = lo->lo_device;
err = loop_clr_fd(lo, bdev, 1);
if (err == 0)
blkdev_put(bdev, 0);
break;
}
default:
err = -EINVAL;
break;
}
out:
mutex_unlock(&lloop_mutex);
out1:
if (rcp)
*rcp = err;
return LLIOC_STOP;
}
static int __init lloop_init(void)
{
int i;
unsigned int cmdlist[] = {
LL_IOC_LLOOP_ATTACH,
LL_IOC_LLOOP_DETACH_BYDEV,
};
if (max_loop < 1 || max_loop > 256) {
max_loop = MAX_LOOP_DEFAULT;
CWARN("lloop: invalid max_loop (must be between 1 and 256), using default (%u)\n",
max_loop);
}
lloop_major = register_blkdev(0, "lloop");
if (lloop_major < 0)
return -EIO;
CDEBUG(D_CONFIG, "registered lloop major %d with %u minors\n",
lloop_major, max_loop);
ll_iocontrol_magic = ll_iocontrol_register(lloop_ioctl, 2, cmdlist);
if (!ll_iocontrol_magic)
goto out_mem1;
loop_dev = kcalloc(max_loop, sizeof(*loop_dev), GFP_KERNEL);
if (!loop_dev)
goto out_mem1;
disks = kcalloc(max_loop, sizeof(*disks), GFP_KERNEL);
if (!disks)
goto out_mem2;
for (i = 0; i < max_loop; i++) {
disks[i] = alloc_disk(1);
if (!disks[i])
goto out_mem3;
}
mutex_init(&lloop_mutex);
for (i = 0; i < max_loop; i++) {
struct lloop_device *lo = &loop_dev[i];
struct gendisk *disk = disks[i];
lo->lo_queue = blk_alloc_queue(GFP_KERNEL);
if (!lo->lo_queue)
goto out_mem4;
mutex_init(&lo->lo_ctl_mutex);
sema_init(&lo->lo_sem, 0);
init_waitqueue_head(&lo->lo_bh_wait);
lo->lo_number = i;
spin_lock_init(&lo->lo_lock);
disk->major = lloop_major;
disk->first_minor = i;
disk->fops = &lo_fops;
sprintf(disk->disk_name, "lloop%d", i);
disk->private_data = lo;
disk->queue = lo->lo_queue;
}
for (i = 0; i < max_loop; i++)
add_disk(disks[i]);
return 0;
out_mem4:
while (i--)
blk_cleanup_queue(loop_dev[i].lo_queue);
i = max_loop;
out_mem3:
while (i--)
put_disk(disks[i]);
kfree(disks);
out_mem2:
kfree(loop_dev);
out_mem1:
unregister_blkdev(lloop_major, "lloop");
ll_iocontrol_unregister(ll_iocontrol_magic);
CERROR("lloop: ran out of memory\n");
return -ENOMEM;
}
static void lloop_exit(void)
{
int i;
ll_iocontrol_unregister(ll_iocontrol_magic);
for (i = 0; i < max_loop; i++) {
del_gendisk(disks[i]);
blk_cleanup_queue(loop_dev[i].lo_queue);
put_disk(disks[i]);
}
unregister_blkdev(lloop_major, "lloop");
kfree(disks);
kfree(loop_dev);
}
