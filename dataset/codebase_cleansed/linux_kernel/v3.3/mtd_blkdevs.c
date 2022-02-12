static void blktrans_dev_release(struct kref *kref)
{
struct mtd_blktrans_dev *dev =
container_of(kref, struct mtd_blktrans_dev, ref);
dev->disk->private_data = NULL;
blk_cleanup_queue(dev->rq);
put_disk(dev->disk);
list_del(&dev->list);
kfree(dev);
}
static struct mtd_blktrans_dev *blktrans_dev_get(struct gendisk *disk)
{
struct mtd_blktrans_dev *dev;
mutex_lock(&blktrans_ref_mutex);
dev = disk->private_data;
if (!dev)
goto unlock;
kref_get(&dev->ref);
unlock:
mutex_unlock(&blktrans_ref_mutex);
return dev;
}
static void blktrans_dev_put(struct mtd_blktrans_dev *dev)
{
mutex_lock(&blktrans_ref_mutex);
kref_put(&dev->ref, blktrans_dev_release);
mutex_unlock(&blktrans_ref_mutex);
}
static int do_blktrans_request(struct mtd_blktrans_ops *tr,
struct mtd_blktrans_dev *dev,
struct request *req)
{
unsigned long block, nsect;
char *buf;
block = blk_rq_pos(req) << 9 >> tr->blkshift;
nsect = blk_rq_cur_bytes(req) >> tr->blkshift;
buf = req->buffer;
if (req->cmd_type != REQ_TYPE_FS)
return -EIO;
if (blk_rq_pos(req) + blk_rq_cur_sectors(req) >
get_capacity(req->rq_disk))
return -EIO;
if (req->cmd_flags & REQ_DISCARD)
return tr->discard(dev, block, nsect);
switch(rq_data_dir(req)) {
case READ:
for (; nsect > 0; nsect--, block++, buf += tr->blksize)
if (tr->readsect(dev, block, buf))
return -EIO;
rq_flush_dcache_pages(req);
return 0;
case WRITE:
if (!tr->writesect)
return -EIO;
rq_flush_dcache_pages(req);
for (; nsect > 0; nsect--, block++, buf += tr->blksize)
if (tr->writesect(dev, block, buf))
return -EIO;
return 0;
default:
printk(KERN_NOTICE "Unknown request %u\n", rq_data_dir(req));
return -EIO;
}
}
int mtd_blktrans_cease_background(struct mtd_blktrans_dev *dev)
{
if (kthread_should_stop())
return 1;
return dev->bg_stop;
}
static int mtd_blktrans_thread(void *arg)
{
struct mtd_blktrans_dev *dev = arg;
struct mtd_blktrans_ops *tr = dev->tr;
struct request_queue *rq = dev->rq;
struct request *req = NULL;
int background_done = 0;
spin_lock_irq(rq->queue_lock);
while (!kthread_should_stop()) {
int res;
dev->bg_stop = false;
if (!req && !(req = blk_fetch_request(rq))) {
if (tr->background && !background_done) {
spin_unlock_irq(rq->queue_lock);
mutex_lock(&dev->lock);
tr->background(dev);
mutex_unlock(&dev->lock);
spin_lock_irq(rq->queue_lock);
background_done = !dev->bg_stop;
continue;
}
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop())
set_current_state(TASK_RUNNING);
spin_unlock_irq(rq->queue_lock);
schedule();
spin_lock_irq(rq->queue_lock);
continue;
}
spin_unlock_irq(rq->queue_lock);
mutex_lock(&dev->lock);
res = do_blktrans_request(dev->tr, dev, req);
mutex_unlock(&dev->lock);
spin_lock_irq(rq->queue_lock);
if (!__blk_end_request_cur(req, res))
req = NULL;
background_done = 0;
}
if (req)
__blk_end_request_all(req, -EIO);
spin_unlock_irq(rq->queue_lock);
return 0;
}
static void mtd_blktrans_request(struct request_queue *rq)
{
struct mtd_blktrans_dev *dev;
struct request *req = NULL;
dev = rq->queuedata;
if (!dev)
while ((req = blk_fetch_request(rq)) != NULL)
__blk_end_request_all(req, -ENODEV);
else {
dev->bg_stop = true;
wake_up_process(dev->thread);
}
}
static int blktrans_open(struct block_device *bdev, fmode_t mode)
{
struct mtd_blktrans_dev *dev = blktrans_dev_get(bdev->bd_disk);
int ret = 0;
if (!dev)
return -ERESTARTSYS;
mutex_lock(&dev->lock);
if (dev->open)
goto unlock;
kref_get(&dev->ref);
__module_get(dev->tr->owner);
if (!dev->mtd)
goto unlock;
if (dev->tr->open) {
ret = dev->tr->open(dev);
if (ret)
goto error_put;
}
ret = __get_mtd_device(dev->mtd);
if (ret)
goto error_release;
unlock:
dev->open++;
mutex_unlock(&dev->lock);
blktrans_dev_put(dev);
return ret;
error_release:
if (dev->tr->release)
dev->tr->release(dev);
error_put:
module_put(dev->tr->owner);
kref_put(&dev->ref, blktrans_dev_release);
mutex_unlock(&dev->lock);
blktrans_dev_put(dev);
return ret;
}
static int blktrans_release(struct gendisk *disk, fmode_t mode)
{
struct mtd_blktrans_dev *dev = blktrans_dev_get(disk);
int ret = 0;
if (!dev)
return ret;
mutex_lock(&dev->lock);
if (--dev->open)
goto unlock;
kref_put(&dev->ref, blktrans_dev_release);
module_put(dev->tr->owner);
if (dev->mtd) {
ret = dev->tr->release ? dev->tr->release(dev) : 0;
__put_mtd_device(dev->mtd);
}
unlock:
mutex_unlock(&dev->lock);
blktrans_dev_put(dev);
return ret;
}
static int blktrans_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct mtd_blktrans_dev *dev = blktrans_dev_get(bdev->bd_disk);
int ret = -ENXIO;
if (!dev)
return ret;
mutex_lock(&dev->lock);
if (!dev->mtd)
goto unlock;
ret = dev->tr->getgeo ? dev->tr->getgeo(dev, geo) : 0;
unlock:
mutex_unlock(&dev->lock);
blktrans_dev_put(dev);
return ret;
}
static int blktrans_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
struct mtd_blktrans_dev *dev = blktrans_dev_get(bdev->bd_disk);
int ret = -ENXIO;
if (!dev)
return ret;
mutex_lock(&dev->lock);
if (!dev->mtd)
goto unlock;
switch (cmd) {
case BLKFLSBUF:
ret = dev->tr->flush ? dev->tr->flush(dev) : 0;
break;
default:
ret = -ENOTTY;
}
unlock:
mutex_unlock(&dev->lock);
blktrans_dev_put(dev);
return ret;
}
int add_mtd_blktrans_dev(struct mtd_blktrans_dev *new)
{
struct mtd_blktrans_ops *tr = new->tr;
struct mtd_blktrans_dev *d;
int last_devnum = -1;
struct gendisk *gd;
int ret;
if (mutex_trylock(&mtd_table_mutex)) {
mutex_unlock(&mtd_table_mutex);
BUG();
}
mutex_lock(&blktrans_ref_mutex);
list_for_each_entry(d, &tr->devs, list) {
if (new->devnum == -1) {
if (d->devnum != last_devnum+1) {
new->devnum = last_devnum+1;
list_add_tail(&new->list, &d->list);
goto added;
}
} else if (d->devnum == new->devnum) {
mutex_unlock(&blktrans_ref_mutex);
return -EBUSY;
} else if (d->devnum > new->devnum) {
list_add_tail(&new->list, &d->list);
goto added;
}
last_devnum = d->devnum;
}
ret = -EBUSY;
if (new->devnum == -1)
new->devnum = last_devnum+1;
if (new->devnum > (MINORMASK >> tr->part_bits) ||
(tr->part_bits && new->devnum >= 27 * 26)) {
mutex_unlock(&blktrans_ref_mutex);
goto error1;
}
list_add_tail(&new->list, &tr->devs);
added:
mutex_unlock(&blktrans_ref_mutex);
mutex_init(&new->lock);
kref_init(&new->ref);
if (!tr->writesect)
new->readonly = 1;
ret = -ENOMEM;
gd = alloc_disk(1 << tr->part_bits);
if (!gd)
goto error2;
new->disk = gd;
gd->private_data = new;
gd->major = tr->major;
gd->first_minor = (new->devnum) << tr->part_bits;
gd->fops = &mtd_blktrans_ops;
if (tr->part_bits)
if (new->devnum < 26)
snprintf(gd->disk_name, sizeof(gd->disk_name),
"%s%c", tr->name, 'a' + new->devnum);
else
snprintf(gd->disk_name, sizeof(gd->disk_name),
"%s%c%c", tr->name,
'a' - 1 + new->devnum / 26,
'a' + new->devnum % 26);
else
snprintf(gd->disk_name, sizeof(gd->disk_name),
"%s%d", tr->name, new->devnum);
set_capacity(gd, (new->size * tr->blksize) >> 9);
spin_lock_init(&new->queue_lock);
new->rq = blk_init_queue(mtd_blktrans_request, &new->queue_lock);
if (!new->rq)
goto error3;
new->rq->queuedata = new;
blk_queue_logical_block_size(new->rq, tr->blksize);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, new->rq);
if (tr->discard) {
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, new->rq);
new->rq->limits.max_discard_sectors = UINT_MAX;
}
gd->queue = new->rq;
new->thread = kthread_run(mtd_blktrans_thread, new,
"%s%d", tr->name, new->mtd->index);
if (IS_ERR(new->thread)) {
ret = PTR_ERR(new->thread);
goto error4;
}
gd->driverfs_dev = &new->mtd->dev;
if (new->readonly)
set_disk_ro(gd, 1);
add_disk(gd);
if (new->disk_attributes) {
ret = sysfs_create_group(&disk_to_dev(gd)->kobj,
new->disk_attributes);
WARN_ON(ret);
}
return 0;
error4:
blk_cleanup_queue(new->rq);
error3:
put_disk(new->disk);
error2:
list_del(&new->list);
error1:
return ret;
}
int del_mtd_blktrans_dev(struct mtd_blktrans_dev *old)
{
unsigned long flags;
if (mutex_trylock(&mtd_table_mutex)) {
mutex_unlock(&mtd_table_mutex);
BUG();
}
if (old->disk_attributes)
sysfs_remove_group(&disk_to_dev(old->disk)->kobj,
old->disk_attributes);
del_gendisk(old->disk);
kthread_stop(old->thread);
spin_lock_irqsave(&old->queue_lock, flags);
old->rq->queuedata = NULL;
blk_start_queue(old->rq);
spin_unlock_irqrestore(&old->queue_lock, flags);
mutex_lock(&old->lock);
if (old->open) {
if (old->tr->release)
old->tr->release(old);
__put_mtd_device(old->mtd);
}
old->mtd = NULL;
mutex_unlock(&old->lock);
blktrans_dev_put(old);
return 0;
}
static void blktrans_notify_remove(struct mtd_info *mtd)
{
struct mtd_blktrans_ops *tr;
struct mtd_blktrans_dev *dev, *next;
list_for_each_entry(tr, &blktrans_majors, list)
list_for_each_entry_safe(dev, next, &tr->devs, list)
if (dev->mtd == mtd)
tr->remove_dev(dev);
}
static void blktrans_notify_add(struct mtd_info *mtd)
{
struct mtd_blktrans_ops *tr;
if (mtd->type == MTD_ABSENT)
return;
list_for_each_entry(tr, &blktrans_majors, list)
tr->add_mtd(tr, mtd);
}
int register_mtd_blktrans(struct mtd_blktrans_ops *tr)
{
struct mtd_info *mtd;
int ret;
if (!blktrans_notifier.list.next)
register_mtd_user(&blktrans_notifier);
mutex_lock(&mtd_table_mutex);
ret = register_blkdev(tr->major, tr->name);
if (ret < 0) {
printk(KERN_WARNING "Unable to register %s block device on major %d: %d\n",
tr->name, tr->major, ret);
mutex_unlock(&mtd_table_mutex);
return ret;
}
if (ret)
tr->major = ret;
tr->blkshift = ffs(tr->blksize) - 1;
INIT_LIST_HEAD(&tr->devs);
list_add(&tr->list, &blktrans_majors);
mtd_for_each_device(mtd)
if (mtd->type != MTD_ABSENT)
tr->add_mtd(tr, mtd);
mutex_unlock(&mtd_table_mutex);
return 0;
}
int deregister_mtd_blktrans(struct mtd_blktrans_ops *tr)
{
struct mtd_blktrans_dev *dev, *next;
mutex_lock(&mtd_table_mutex);
list_del(&tr->list);
list_for_each_entry_safe(dev, next, &tr->devs, list)
tr->remove_dev(dev);
unregister_blkdev(tr->major, tr->name);
mutex_unlock(&mtd_table_mutex);
BUG_ON(!list_empty(&tr->devs));
return 0;
}
static void __exit mtd_blktrans_exit(void)
{
if (blktrans_notifier.list.next)
unregister_mtd_user(&blktrans_notifier);
}
