static void osdblk_make_credential(u8 cred_a[OSD_CAP_LEN],
const struct osd_obj_id *obj)
{
osd_sec_init_nosec_doall_caps(cred_a, obj, false, true);
}
static int osd_sync_op(struct osd_request *or, int timeout, uint8_t *credential)
{
int ret;
or->timeout = timeout;
ret = osd_finalize_request(or, 0, credential, NULL);
if (ret)
return ret;
ret = osd_execute_request(or);
return ret;
}
static int osd_async_op(struct osd_request *or, osd_req_done_fn *async_done,
void *caller_context, u8 *cred)
{
int ret;
ret = osd_finalize_request(or, 0, cred, NULL);
if (ret)
return ret;
ret = osd_execute_request_async(or, async_done, caller_context);
return ret;
}
static int extract_attr_from_req(struct osd_request *or, struct osd_attr *attr)
{
struct osd_attr cur_attr = {.attr_page = 0};
void *iter = NULL;
int nelem;
do {
nelem = 1;
osd_req_decode_get_attr_list(or, &cur_attr, &nelem, &iter);
if ((cur_attr.attr_page == attr->attr_page) &&
(cur_attr.attr_id == attr->attr_id)) {
attr->len = cur_attr.len;
attr->val_ptr = cur_attr.val_ptr;
return 0;
}
} while (iter);
return -EIO;
}
static int osdblk_get_obj_size(struct osdblk_device *osdev, u64 *size_out)
{
struct osd_request *or;
struct osd_attr attr;
int ret;
or = osd_start_request(osdev->osd, GFP_KERNEL);
if (!or)
return -ENOMEM;
osd_req_get_attributes(or, &osdev->obj);
osd_req_add_get_attr_list(or, &g_attr_logical_length, 1);
ret = osd_sync_op(or, OSDBLK_OP_TIMEOUT, osdev->obj_cred);
if (ret)
goto out;
attr = g_attr_logical_length;
ret = extract_attr_from_req(or, &attr);
if (ret)
goto out;
*size_out = get_unaligned_be64(attr.val_ptr);
out:
osd_end_request(or);
return ret;
}
static void osdblk_osd_complete(struct osd_request *or, void *private)
{
struct osdblk_request *orq = private;
struct osd_sense_info osi;
int ret = osd_req_decode_sense(or, &osi);
if (ret) {
ret = -EIO;
OSDBLK_DEBUG("osdblk_osd_complete with err=%d\n", ret);
}
osd_end_request(or);
__blk_end_request_all(orq->rq, ret);
}
static void bio_chain_put(struct bio *chain)
{
struct bio *tmp;
while (chain) {
tmp = chain;
chain = chain->bi_next;
bio_put(tmp);
}
}
static struct bio *bio_chain_clone(struct bio *old_chain, gfp_t gfpmask)
{
struct bio *tmp, *new_chain = NULL, *tail = NULL;
while (old_chain) {
tmp = bio_clone_kmalloc(old_chain, gfpmask);
if (!tmp)
goto err_out;
tmp->bi_bdev = NULL;
gfpmask &= ~__GFP_DIRECT_RECLAIM;
tmp->bi_next = NULL;
if (!new_chain)
new_chain = tail = tmp;
else {
tail->bi_next = tmp;
tail = tmp;
}
old_chain = old_chain->bi_next;
}
return new_chain;
err_out:
OSDBLK_DEBUG("bio_chain_clone with err\n");
bio_chain_put(new_chain);
return NULL;
}
static void osdblk_rq_fn(struct request_queue *q)
{
struct osdblk_device *osdev = q->queuedata;
while (1) {
struct request *rq;
struct osdblk_request *orq;
struct osd_request *or;
struct bio *bio;
bool do_write, do_flush;
rq = blk_fetch_request(q);
if (!rq)
break;
do_flush = (req_op(rq) == REQ_OP_FLUSH);
do_write = (rq_data_dir(rq) == WRITE);
if (!do_flush) {
bio = bio_chain_clone(rq->bio, GFP_ATOMIC);
if (!bio)
break;
} else
bio = NULL;
or = osd_start_request(osdev->osd, GFP_ATOMIC);
if (!or) {
bio_chain_put(bio);
OSDBLK_DEBUG("osd_start_request with err\n");
break;
}
orq = &osdev->req[rq->tag];
orq->rq = rq;
orq->bio = bio;
orq->osdev = osdev;
if (do_flush)
osd_req_flush_object(or, &osdev->obj,
OSD_CDB_FLUSH_ALL, 0, 0);
else if (do_write)
osd_req_write(or, &osdev->obj, blk_rq_pos(rq) * 512ULL,
bio, blk_rq_bytes(rq));
else
osd_req_read(or, &osdev->obj, blk_rq_pos(rq) * 512ULL,
bio, blk_rq_bytes(rq));
OSDBLK_DEBUG("%s 0x%x bytes at 0x%llx\n",
do_flush ? "flush" : do_write ?
"write" : "read", blk_rq_bytes(rq),
blk_rq_pos(rq) * 512ULL);
if (osd_async_op(or, osdblk_osd_complete, orq,
osdev->obj_cred)) {
osd_end_request(or);
blk_requeue_request(q, rq);
bio_chain_put(bio);
OSDBLK_DEBUG("osd_execute_request_async with err\n");
break;
}
rq->special = NULL;
}
}
static void osdblk_free_disk(struct osdblk_device *osdev)
{
struct gendisk *disk = osdev->disk;
if (!disk)
return;
if (disk->flags & GENHD_FL_UP)
del_gendisk(disk);
if (disk->queue)
blk_cleanup_queue(disk->queue);
put_disk(disk);
}
static int osdblk_init_disk(struct osdblk_device *osdev)
{
struct gendisk *disk;
struct request_queue *q;
int rc;
u64 obj_size = 0;
rc = osdblk_get_obj_size(osdev, &obj_size);
if (rc)
return rc;
disk = alloc_disk(OSDBLK_MINORS_PER_MAJOR);
if (!disk)
return -ENOMEM;
sprintf(disk->disk_name, DRV_NAME "%d", osdev->id);
disk->major = osdev->major;
disk->first_minor = 0;
disk->fops = &osdblk_bd_ops;
disk->private_data = osdev;
q = blk_init_queue(osdblk_rq_fn, &osdev->lock);
if (!q) {
put_disk(disk);
return -ENOMEM;
}
rc = blk_queue_init_tags(q, OSDBLK_MAX_REQ, NULL, BLK_TAG_ALLOC_FIFO);
if (rc) {
blk_cleanup_queue(q);
put_disk(disk);
return rc;
}
blk_queue_stack_limits(q, osd_request_queue(osdev->osd));
blk_queue_prep_rq(q, blk_queue_start_tag);
blk_queue_write_cache(q, true, false);
disk->queue = q;
q->queuedata = osdev;
osdev->disk = disk;
osdev->q = q;
set_capacity(disk, obj_size / 512ULL);
add_disk(disk);
printk(KERN_INFO "%s: Added of size 0x%llx\n",
disk->disk_name, (unsigned long long)obj_size);
return 0;
}
static void class_osdblk_release(struct class *cls)
{
kfree(cls);
}
static ssize_t class_osdblk_list(struct class *c,
struct class_attribute *attr,
char *data)
{
int n = 0;
struct list_head *tmp;
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
list_for_each(tmp, &osdblkdev_list) {
struct osdblk_device *osdev;
osdev = list_entry(tmp, struct osdblk_device, node);
n += sprintf(data+n, "%d %d %llu %llu %s\n",
osdev->id,
osdev->major,
osdev->obj.partition,
osdev->obj.id,
osdev->osd_path);
}
mutex_unlock(&ctl_mutex);
return n;
}
static ssize_t class_osdblk_add(struct class *c,
struct class_attribute *attr,
const char *buf, size_t count)
{
struct osdblk_device *osdev;
ssize_t rc;
int irc, new_id = 0;
struct list_head *tmp;
if (!try_module_get(THIS_MODULE))
return -ENODEV;
osdev = kzalloc(sizeof(*osdev) + strlen(buf) + 1, GFP_KERNEL);
if (!osdev) {
rc = -ENOMEM;
goto err_out_mod;
}
spin_lock_init(&osdev->lock);
INIT_LIST_HEAD(&osdev->node);
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
list_for_each(tmp, &osdblkdev_list) {
struct osdblk_device *osdev;
osdev = list_entry(tmp, struct osdblk_device, node);
if (osdev->id > new_id)
new_id = osdev->id + 1;
}
osdev->id = new_id;
list_add_tail(&osdev->node, &osdblkdev_list);
mutex_unlock(&ctl_mutex);
if (sscanf(buf, "%llu %llu %s", &osdev->obj.partition, &osdev->obj.id,
osdev->osd_path) != 3) {
rc = -EINVAL;
goto err_out_slot;
}
sprintf(osdev->name, DRV_NAME "%d", osdev->id);
osdev->osd = osduld_path_lookup(osdev->osd_path);
if (IS_ERR(osdev->osd)) {
rc = PTR_ERR(osdev->osd);
goto err_out_slot;
}
osdblk_make_credential(osdev->obj_cred, &osdev->obj);
irc = register_blkdev(0, osdev->name);
if (irc < 0) {
rc = irc;
goto err_out_osd;
}
osdev->major = irc;
rc = osdblk_init_disk(osdev);
if (rc)
goto err_out_blkdev;
return count;
err_out_blkdev:
unregister_blkdev(osdev->major, osdev->name);
err_out_osd:
osduld_put_device(osdev->osd);
err_out_slot:
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
list_del_init(&osdev->node);
mutex_unlock(&ctl_mutex);
kfree(osdev);
err_out_mod:
OSDBLK_DEBUG("Error adding device %s\n", buf);
module_put(THIS_MODULE);
return rc;
}
static ssize_t class_osdblk_remove(struct class *c,
struct class_attribute *attr,
const char *buf,
size_t count)
{
struct osdblk_device *osdev = NULL;
int target_id, rc;
unsigned long ul;
struct list_head *tmp;
rc = kstrtoul(buf, 10, &ul);
if (rc)
return rc;
target_id = (int) ul;
if (target_id != ul)
return -EINVAL;
mutex_lock_nested(&ctl_mutex, SINGLE_DEPTH_NESTING);
list_for_each(tmp, &osdblkdev_list) {
osdev = list_entry(tmp, struct osdblk_device, node);
if (osdev->id == target_id) {
list_del_init(&osdev->node);
break;
}
osdev = NULL;
}
mutex_unlock(&ctl_mutex);
if (!osdev)
return -ENOENT;
osdblk_free_disk(osdev);
unregister_blkdev(osdev->major, osdev->name);
osduld_put_device(osdev->osd);
kfree(osdev);
module_put(THIS_MODULE);
return count;
}
static int osdblk_sysfs_init(void)
{
int ret = 0;
class_osdblk = kzalloc(sizeof(*class_osdblk), GFP_KERNEL);
if (!class_osdblk)
return -ENOMEM;
class_osdblk->name = DRV_NAME;
class_osdblk->owner = THIS_MODULE;
class_osdblk->class_release = class_osdblk_release;
class_osdblk->class_attrs = class_osdblk_attrs;
ret = class_register(class_osdblk);
if (ret) {
kfree(class_osdblk);
class_osdblk = NULL;
printk(PFX "failed to create class osdblk\n");
return ret;
}
return 0;
}
static void osdblk_sysfs_cleanup(void)
{
if (class_osdblk)
class_destroy(class_osdblk);
class_osdblk = NULL;
}
static int __init osdblk_init(void)
{
int rc;
rc = osdblk_sysfs_init();
if (rc)
return rc;
return 0;
}
static void __exit osdblk_exit(void)
{
osdblk_sysfs_cleanup();
}
