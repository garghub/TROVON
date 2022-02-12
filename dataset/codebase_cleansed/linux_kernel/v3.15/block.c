static int __init ubiblock_set_param(const char *val,
const struct kernel_param *kp)
{
int i, ret;
size_t len;
struct ubiblock_param *param;
char buf[UBIBLOCK_PARAM_LEN];
char *pbuf = &buf[0];
char *tokens[UBIBLOCK_PARAM_COUNT];
if (!val)
return -EINVAL;
len = strnlen(val, UBIBLOCK_PARAM_LEN);
if (len == 0) {
ubi_warn("block: empty 'block=' parameter - ignored\n");
return 0;
}
if (len == UBIBLOCK_PARAM_LEN) {
ubi_err("block: parameter \"%s\" is too long, max. is %d\n",
val, UBIBLOCK_PARAM_LEN);
return -EINVAL;
}
strcpy(buf, val);
if (buf[len - 1] == '\n')
buf[len - 1] = '\0';
for (i = 0; i < UBIBLOCK_PARAM_COUNT; i++)
tokens[i] = strsep(&pbuf, ",");
param = &ubiblock_param[ubiblock_devs];
if (tokens[1]) {
ret = kstrtoint(tokens[0], 10, &param->ubi_num);
if (ret < 0)
return -EINVAL;
ret = kstrtoint(tokens[1], 10, &param->vol_id);
if (ret < 0) {
param->vol_id = -1;
strcpy(param->name, tokens[1]);
}
} else {
strcpy(param->name, tokens[0]);
param->ubi_num = -1;
param->vol_id = -1;
}
ubiblock_devs++;
return 0;
}
static struct ubiblock *find_dev_nolock(int ubi_num, int vol_id)
{
struct ubiblock *dev;
list_for_each_entry(dev, &ubiblock_devices, list)
if (dev->ubi_num == ubi_num && dev->vol_id == vol_id)
return dev;
return NULL;
}
static int ubiblock_read_to_buf(struct ubiblock *dev, char *buffer,
int leb, int offset, int len)
{
int ret;
ret = ubi_read(dev->desc, leb, buffer, offset, len);
if (ret) {
ubi_err("%s ubi_read error %d",
dev->gd->disk_name, ret);
return ret;
}
return 0;
}
static int ubiblock_read(struct ubiblock *dev, char *buffer,
sector_t sec, int len)
{
int ret, leb, offset;
int bytes_left = len;
int to_read = len;
u64 pos = sec << 9;
offset = do_div(pos, dev->leb_size);
leb = pos;
while (bytes_left) {
if (offset + to_read > dev->leb_size)
to_read = dev->leb_size - offset;
ret = ubiblock_read_to_buf(dev, buffer, leb, offset, to_read);
if (ret)
return ret;
buffer += to_read;
bytes_left -= to_read;
to_read = bytes_left;
leb += 1;
offset = 0;
}
return 0;
}
static int do_ubiblock_request(struct ubiblock *dev, struct request *req)
{
int len, ret;
sector_t sec;
if (req->cmd_type != REQ_TYPE_FS)
return -EIO;
if (blk_rq_pos(req) + blk_rq_cur_sectors(req) >
get_capacity(req->rq_disk))
return -EIO;
if (rq_data_dir(req) != READ)
return -ENOSYS;
sec = blk_rq_pos(req);
len = blk_rq_cur_bytes(req);
mutex_lock(&dev->dev_mutex);
ret = ubiblock_read(dev, req->buffer, sec, len);
mutex_unlock(&dev->dev_mutex);
return ret;
}
static void ubiblock_do_work(struct work_struct *work)
{
struct ubiblock *dev =
container_of(work, struct ubiblock, work);
struct request_queue *rq = dev->rq;
struct request *req;
int res;
spin_lock_irq(rq->queue_lock);
req = blk_fetch_request(rq);
while (req) {
spin_unlock_irq(rq->queue_lock);
res = do_ubiblock_request(dev, req);
spin_lock_irq(rq->queue_lock);
if (!__blk_end_request_cur(req, res))
req = blk_fetch_request(rq);
}
spin_unlock_irq(rq->queue_lock);
}
static void ubiblock_request(struct request_queue *rq)
{
struct ubiblock *dev;
struct request *req;
dev = rq->queuedata;
if (!dev)
while ((req = blk_fetch_request(rq)) != NULL)
__blk_end_request_all(req, -ENODEV);
else
queue_work(dev->wq, &dev->work);
}
static int ubiblock_open(struct block_device *bdev, fmode_t mode)
{
struct ubiblock *dev = bdev->bd_disk->private_data;
int ret;
mutex_lock(&dev->dev_mutex);
if (dev->refcnt > 0) {
goto out_done;
}
if (mode & FMODE_WRITE) {
ret = -EPERM;
goto out_unlock;
}
dev->desc = ubi_open_volume(dev->ubi_num, dev->vol_id, UBI_READONLY);
if (IS_ERR(dev->desc)) {
ubi_err("%s failed to open ubi volume %d_%d",
dev->gd->disk_name, dev->ubi_num, dev->vol_id);
ret = PTR_ERR(dev->desc);
dev->desc = NULL;
goto out_unlock;
}
out_done:
dev->refcnt++;
mutex_unlock(&dev->dev_mutex);
return 0;
out_unlock:
mutex_unlock(&dev->dev_mutex);
return ret;
}
static void ubiblock_release(struct gendisk *gd, fmode_t mode)
{
struct ubiblock *dev = gd->private_data;
mutex_lock(&dev->dev_mutex);
dev->refcnt--;
if (dev->refcnt == 0) {
ubi_close_volume(dev->desc);
dev->desc = NULL;
}
mutex_unlock(&dev->dev_mutex);
}
static int ubiblock_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
geo->heads = 1;
geo->cylinders = 1;
geo->sectors = get_capacity(bdev->bd_disk);
geo->start = 0;
return 0;
}
int ubiblock_create(struct ubi_volume_info *vi)
{
struct ubiblock *dev;
struct gendisk *gd;
int disk_capacity;
int ret;
mutex_lock(&devices_mutex);
if (find_dev_nolock(vi->ubi_num, vi->vol_id)) {
mutex_unlock(&devices_mutex);
return -EEXIST;
}
mutex_unlock(&devices_mutex);
dev = kzalloc(sizeof(struct ubiblock), GFP_KERNEL);
if (!dev)
return -ENOMEM;
mutex_init(&dev->dev_mutex);
dev->ubi_num = vi->ubi_num;
dev->vol_id = vi->vol_id;
dev->leb_size = vi->usable_leb_size;
gd = alloc_disk(1);
if (!gd) {
ubi_err("block: alloc_disk failed");
ret = -ENODEV;
goto out_free_dev;
}
gd->fops = &ubiblock_ops;
gd->major = ubiblock_major;
gd->first_minor = dev->ubi_num * UBI_MAX_VOLUMES + dev->vol_id;
gd->private_data = dev;
sprintf(gd->disk_name, "ubiblock%d_%d", dev->ubi_num, dev->vol_id);
disk_capacity = (vi->size * vi->usable_leb_size) >> 9;
set_capacity(gd, disk_capacity);
dev->gd = gd;
spin_lock_init(&dev->queue_lock);
dev->rq = blk_init_queue(ubiblock_request, &dev->queue_lock);
if (!dev->rq) {
ubi_err("block: blk_init_queue failed");
ret = -ENODEV;
goto out_put_disk;
}
dev->rq->queuedata = dev;
dev->gd->queue = dev->rq;
dev->wq = alloc_workqueue("%s", 0, 0, gd->disk_name);
if (!dev->wq)
goto out_free_queue;
INIT_WORK(&dev->work, ubiblock_do_work);
mutex_lock(&devices_mutex);
list_add_tail(&dev->list, &ubiblock_devices);
mutex_unlock(&devices_mutex);
add_disk(dev->gd);
ubi_msg("%s created from ubi%d:%d(%s)",
dev->gd->disk_name, dev->ubi_num, dev->vol_id, vi->name);
return 0;
out_free_queue:
blk_cleanup_queue(dev->rq);
out_put_disk:
put_disk(dev->gd);
out_free_dev:
kfree(dev);
return ret;
}
static void ubiblock_cleanup(struct ubiblock *dev)
{
del_gendisk(dev->gd);
blk_cleanup_queue(dev->rq);
ubi_msg("%s released", dev->gd->disk_name);
put_disk(dev->gd);
}
int ubiblock_remove(struct ubi_volume_info *vi)
{
struct ubiblock *dev;
mutex_lock(&devices_mutex);
dev = find_dev_nolock(vi->ubi_num, vi->vol_id);
if (!dev) {
mutex_unlock(&devices_mutex);
return -ENODEV;
}
mutex_lock(&dev->dev_mutex);
if (dev->refcnt > 0) {
mutex_unlock(&dev->dev_mutex);
mutex_unlock(&devices_mutex);
return -EBUSY;
}
list_del(&dev->list);
mutex_unlock(&devices_mutex);
destroy_workqueue(dev->wq);
ubiblock_cleanup(dev);
mutex_unlock(&dev->dev_mutex);
kfree(dev);
return 0;
}
static void ubiblock_resize(struct ubi_volume_info *vi)
{
struct ubiblock *dev;
int disk_capacity;
mutex_lock(&devices_mutex);
dev = find_dev_nolock(vi->ubi_num, vi->vol_id);
if (!dev) {
mutex_unlock(&devices_mutex);
return;
}
mutex_lock(&dev->dev_mutex);
disk_capacity = (vi->size * vi->usable_leb_size) >> 9;
set_capacity(dev->gd, disk_capacity);
ubi_msg("%s resized to %d LEBs", dev->gd->disk_name, vi->size);
mutex_unlock(&dev->dev_mutex);
mutex_unlock(&devices_mutex);
}
static int ubiblock_notify(struct notifier_block *nb,
unsigned long notification_type, void *ns_ptr)
{
struct ubi_notification *nt = ns_ptr;
switch (notification_type) {
case UBI_VOLUME_ADDED:
break;
case UBI_VOLUME_REMOVED:
ubiblock_remove(&nt->vi);
break;
case UBI_VOLUME_RESIZED:
ubiblock_resize(&nt->vi);
break;
default:
break;
}
return NOTIFY_OK;
}
static struct ubi_volume_desc * __init
open_volume_desc(const char *name, int ubi_num, int vol_id)
{
if (ubi_num == -1)
return ubi_open_volume_path(name, UBI_READONLY);
else if (vol_id == -1)
return ubi_open_volume_nm(ubi_num, name, UBI_READONLY);
else
return ubi_open_volume(ubi_num, vol_id, UBI_READONLY);
}
static int __init ubiblock_create_from_param(void)
{
int i, ret;
struct ubiblock_param *p;
struct ubi_volume_desc *desc;
struct ubi_volume_info vi;
for (i = 0; i < ubiblock_devs; i++) {
p = &ubiblock_param[i];
desc = open_volume_desc(p->name, p->ubi_num, p->vol_id);
if (IS_ERR(desc)) {
ubi_err("block: can't open volume, err=%ld\n",
PTR_ERR(desc));
ret = PTR_ERR(desc);
break;
}
ubi_get_volume_info(desc, &vi);
ubi_close_volume(desc);
ret = ubiblock_create(&vi);
if (ret) {
ubi_err("block: can't add '%s' volume, err=%d\n",
vi.name, ret);
break;
}
}
return ret;
}
static void ubiblock_remove_all(void)
{
struct ubiblock *next;
struct ubiblock *dev;
list_for_each_entry_safe(dev, next, &ubiblock_devices, list) {
destroy_workqueue(dev->wq);
WARN_ON(dev->desc);
list_del(&dev->list);
ubiblock_cleanup(dev);
kfree(dev);
}
}
int __init ubiblock_init(void)
{
int ret;
ubiblock_major = register_blkdev(0, "ubiblock");
if (ubiblock_major < 0)
return ubiblock_major;
ret = ubiblock_create_from_param();
if (ret)
goto err_remove;
ret = ubi_register_volume_notifier(&ubiblock_notifier, 1);
if (ret)
goto err_unreg;
return 0;
err_unreg:
unregister_blkdev(ubiblock_major, "ubiblock");
err_remove:
ubiblock_remove_all();
return ret;
}
void __exit ubiblock_exit(void)
{
ubi_unregister_volume_notifier(&ubiblock_notifier);
ubiblock_remove_all();
unregister_blkdev(ubiblock_major, "ubiblock");
}
