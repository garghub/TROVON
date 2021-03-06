static int blkvsc_device_add(struct hv_device *device,
void *additional_info)
{
struct storvsc_device_info *device_info;
int ret = 0;
device_info = (struct storvsc_device_info *)additional_info;
device_info->ring_buffer_size = blkvsc_ringbuffer_size;
ret = storvsc_dev_add(device, additional_info);
if (ret != 0)
return ret;
device_info->path_id = device->dev_instance.data[3] << 24 |
device->dev_instance.data[2] << 16 |
device->dev_instance.data[1] << 8 |
device->dev_instance.data[0];
device_info->target_id = device->dev_instance.data[5] << 8 |
device->dev_instance.data[4];
return ret;
}
static int blkvsc_submit_request(struct blkvsc_request *blkvsc_req,
void (*request_completion)(struct hv_storvsc_request *))
{
struct block_device_context *blkdev = blkvsc_req->dev;
struct hv_storvsc_request *storvsc_req;
struct vmscsi_request *vm_srb;
int ret;
storvsc_req = &blkvsc_req->request;
vm_srb = &storvsc_req->vstor_packet.vm_srb;
vm_srb->data_in = blkvsc_req->write ? WRITE_TYPE : READ_TYPE;
storvsc_req->on_io_completion = request_completion;
storvsc_req->context = blkvsc_req;
vm_srb->port_number = blkdev->port;
vm_srb->path_id = blkdev->path;
vm_srb->target_id = blkdev->target;
vm_srb->lun = 0;
vm_srb->cdb_length = blkvsc_req->cmd_len;
memcpy(vm_srb->cdb, blkvsc_req->cmnd, vm_srb->cdb_length);
storvsc_req->sense_buffer = blkvsc_req->sense_buffer;
ret = storvsc_do_io(blkdev->device_ctx,
&blkvsc_req->request);
if (ret == 0)
blkdev->num_outstanding_reqs++;
return ret;
}
static int blkvsc_open(struct block_device *bdev, fmode_t mode)
{
struct block_device_context *blkdev = bdev->bd_disk->private_data;
unsigned long flags;
spin_lock_irqsave(&blkdev->lock, flags);
blkdev->users++;
spin_unlock_irqrestore(&blkdev->lock, flags);
return 0;
}
static int blkvsc_getgeo(struct block_device *bd, struct hd_geometry *hg)
{
sector_t nsect = get_capacity(bd->bd_disk);
sector_t cylinders = nsect;
hg->heads = 0xff;
hg->sectors = 0x3f;
sector_div(cylinders, hg->heads * hg->sectors);
hg->cylinders = cylinders;
if ((sector_t)(hg->cylinders + 1) * hg->heads * hg->sectors < nsect)
hg->cylinders = 0xffff;
return 0;
}
static void blkvsc_init_rw(struct blkvsc_request *blkvsc_req)
{
blkvsc_req->cmd_len = 16;
if (rq_data_dir(blkvsc_req->req)) {
blkvsc_req->write = 1;
blkvsc_req->cmnd[0] = WRITE_16;
} else {
blkvsc_req->write = 0;
blkvsc_req->cmnd[0] = READ_16;
}
blkvsc_req->cmnd[1] |=
(blkvsc_req->req->cmd_flags & REQ_FUA) ? 0x8 : 0;
*(unsigned long long *)&blkvsc_req->cmnd[2] =
cpu_to_be64(blkvsc_req->sector_start);
*(unsigned int *)&blkvsc_req->cmnd[10] =
cpu_to_be32(blkvsc_req->sector_count);
}
static int blkvsc_ioctl(struct block_device *bd, fmode_t mode,
unsigned cmd, unsigned long arg)
{
struct block_device_context *blkdev = bd->bd_disk->private_data;
int ret = 0;
switch (cmd) {
case HDIO_GET_IDENTITY:
if (copy_to_user((void __user *)arg, blkdev->device_id,
blkdev->device_id_len))
ret = -EFAULT;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static void blkvsc_cmd_completion(struct hv_storvsc_request *request)
{
struct blkvsc_request *blkvsc_req =
(struct blkvsc_request *)request->context;
struct block_device_context *blkdev =
(struct block_device_context *)blkvsc_req->dev;
struct scsi_sense_hdr sense_hdr;
struct vmscsi_request *vm_srb;
unsigned long flags;
vm_srb = &blkvsc_req->request.vstor_packet.vm_srb;
spin_lock_irqsave(&blkdev->lock, flags);
blkdev->num_outstanding_reqs--;
spin_unlock_irqrestore(&blkdev->lock, flags);
if (vm_srb->scsi_status)
if (scsi_normalize_sense(blkvsc_req->sense_buffer,
SCSI_SENSE_BUFFERSIZE, &sense_hdr))
scsi_print_sense_hdr("blkvsc", &sense_hdr);
complete(&blkvsc_req->request.wait_event);
}
static int blkvsc_do_operation(struct block_device_context *blkdev,
enum blkvsc_op_type op)
{
struct blkvsc_request *blkvsc_req;
struct page *page_buf;
unsigned char *buf;
unsigned char device_type;
struct scsi_sense_hdr sense_hdr;
struct vmscsi_request *vm_srb;
unsigned long flags;
int ret = 0;
blkvsc_req = kmem_cache_zalloc(blkdev->request_pool, GFP_KERNEL);
if (!blkvsc_req)
return -ENOMEM;
page_buf = alloc_page(GFP_KERNEL);
if (!page_buf) {
kmem_cache_free(blkdev->request_pool, blkvsc_req);
return -ENOMEM;
}
vm_srb = &blkvsc_req->request.vstor_packet.vm_srb;
init_completion(&blkvsc_req->request.wait_event);
blkvsc_req->dev = blkdev;
blkvsc_req->req = NULL;
blkvsc_req->write = 0;
blkvsc_req->request.data_buffer.pfn_array[0] =
page_to_pfn(page_buf);
blkvsc_req->request.data_buffer.offset = 0;
switch (op) {
case DO_INQUIRY:
blkvsc_req->cmnd[0] = INQUIRY;
blkvsc_req->cmnd[1] = 0x1;
blkvsc_req->cmnd[2] = 0x83;
blkvsc_req->cmnd[4] = 64;
blkvsc_req->cmd_len = 6;
blkvsc_req->request.data_buffer.len = 64;
break;
case DO_CAPACITY:
blkdev->sector_size = 0;
blkdev->capacity = 0;
blkvsc_req->cmnd[0] = READ_CAPACITY;
blkvsc_req->cmd_len = 16;
blkvsc_req->request.data_buffer.len = 8;
break;
case DO_FLUSH:
blkvsc_req->cmnd[0] = SYNCHRONIZE_CACHE;
blkvsc_req->cmd_len = 10;
blkvsc_req->request.data_buffer.pfn_array[0] = 0;
blkvsc_req->request.data_buffer.len = 0;
break;
default:
ret = -EINVAL;
goto cleanup;
}
spin_lock_irqsave(&blkdev->lock, flags);
blkvsc_submit_request(blkvsc_req, blkvsc_cmd_completion);
spin_unlock_irqrestore(&blkdev->lock, flags);
wait_for_completion_interruptible(&blkvsc_req->request.wait_event);
if (vm_srb->scsi_status) {
scsi_normalize_sense(blkvsc_req->sense_buffer,
SCSI_SENSE_BUFFERSIZE, &sense_hdr);
return 0;
}
buf = kmap(page_buf);
switch (op) {
case DO_INQUIRY:
device_type = buf[0] & 0x1F;
if (device_type == 0x0)
blkdev->device_type = HARDDISK_TYPE;
else
blkdev->device_type = UNKNOWN_DEV_TYPE;
blkdev->device_id_len = buf[7];
if (blkdev->device_id_len > 64)
blkdev->device_id_len = 64;
memcpy(blkdev->device_id, &buf[8], blkdev->device_id_len);
break;
case DO_CAPACITY:
blkdev->capacity =
((buf[0] << 24) | (buf[1] << 16) |
(buf[2] << 8) | buf[3]) + 1;
blkdev->sector_size =
(buf[4] << 24) | (buf[5] << 16) |
(buf[6] << 8) | buf[7];
break;
default:
break;
}
cleanup:
kunmap(page_buf);
__free_page(page_buf);
kmem_cache_free(blkdev->request_pool, blkvsc_req);
return ret;
}
static int blkvsc_cancel_pending_reqs(struct block_device_context *blkdev)
{
struct blkvsc_request *pend_req, *tmp;
struct blkvsc_request *comp_req, *tmp2;
struct vmscsi_request *vm_srb;
int ret = 0;
list_for_each_entry_safe(pend_req, tmp, &blkdev->pending_list,
pend_entry) {
list_for_each_entry_safe(comp_req, tmp2,
&pend_req->group->blkvsc_req_list,
req_entry) {
if (comp_req == pend_req)
break;
list_del(&comp_req->req_entry);
if (comp_req->req) {
vm_srb =
&comp_req->request.vstor_packet.
vm_srb;
ret = __blk_end_request(comp_req->req,
(!vm_srb->scsi_status ? 0 : -EIO),
comp_req->sector_count *
blkdev->sector_size);
if (ret)
goto out;
}
kmem_cache_free(blkdev->request_pool, comp_req);
}
list_del(&pend_req->pend_entry);
list_del(&pend_req->req_entry);
if (comp_req->req) {
if (!__blk_end_request(pend_req->req, -EIO,
pend_req->sector_count *
blkdev->sector_size)) {
kmem_cache_free(blkdev->request_pool,
pend_req->group);
}
}
kmem_cache_free(blkdev->request_pool, pend_req);
}
out:
return ret;
}
static int blkvsc_remove(struct hv_device *dev)
{
struct block_device_context *blkdev = dev_get_drvdata(&dev->device);
unsigned long flags;
spin_lock_irqsave(&blkdev->lock, flags);
blkdev->shutting_down = 1;
blk_stop_queue(blkdev->gd->queue);
blkvsc_cancel_pending_reqs(blkdev);
spin_unlock_irqrestore(&blkdev->lock, flags);
blkvsc_do_operation(blkdev, DO_FLUSH);
if (blkdev->users == 0) {
del_gendisk(blkdev->gd);
put_disk(blkdev->gd);
blk_cleanup_queue(blkdev->gd->queue);
storvsc_dev_remove(blkdev->device_ctx);
kmem_cache_destroy(blkdev->request_pool);
kfree(blkdev);
}
return 0;
}
static void blkvsc_shutdown(struct hv_device *dev)
{
struct block_device_context *blkdev = dev_get_drvdata(&dev->device);
unsigned long flags;
if (!blkdev)
return;
spin_lock_irqsave(&blkdev->lock, flags);
blkdev->shutting_down = 1;
blk_stop_queue(blkdev->gd->queue);
blkvsc_cancel_pending_reqs(blkdev);
spin_unlock_irqrestore(&blkdev->lock, flags);
blkvsc_do_operation(blkdev, DO_FLUSH);
storvsc_wait_to_drain((struct storvsc_device *)dev->ext);
}
static int blkvsc_release(struct gendisk *disk, fmode_t mode)
{
struct block_device_context *blkdev = disk->private_data;
unsigned long flags;
spin_lock_irqsave(&blkdev->lock, flags);
if ((--blkdev->users == 0) && (blkdev->shutting_down)) {
blk_stop_queue(blkdev->gd->queue);
spin_unlock_irqrestore(&blkdev->lock, flags);
blkvsc_do_operation(blkdev, DO_FLUSH);
del_gendisk(blkdev->gd);
put_disk(blkdev->gd);
blk_cleanup_queue(blkdev->gd->queue);
storvsc_dev_remove(blkdev->device_ctx);
kmem_cache_destroy(blkdev->request_pool);
kfree(blkdev);
} else
spin_unlock_irqrestore(&blkdev->lock, flags);
return 0;
}
static int blkvsc_do_request(struct block_device_context *blkdev,
struct request *req)
{
struct bio *bio = NULL;
struct bio_vec *bvec = NULL;
struct bio_vec *prev_bvec = NULL;
struct blkvsc_request *blkvsc_req = NULL;
struct blkvsc_request *tmp;
int databuf_idx = 0;
int seg_idx = 0;
sector_t start_sector;
unsigned long num_sectors = 0;
int ret = 0;
int pending = 0;
struct blkvsc_request_group *group = NULL;
group = kmem_cache_zalloc(blkdev->request_pool, GFP_ATOMIC);
if (!group)
return -ENOMEM;
INIT_LIST_HEAD(&group->blkvsc_req_list);
group->outstanding = group->status = 0;
start_sector = blk_rq_pos(req);
if (req->bio) {
for (bio = req->bio; bio; bio = bio->bi_next) {
bio_for_each_segment(bvec, bio, seg_idx) {
if ((!blkvsc_req) ||
(databuf_idx >= MAX_MULTIPAGE_BUFFER_COUNT)
|| (bvec->bv_offset != 0) ||
(prev_bvec &&
(prev_bvec->bv_len != PAGE_SIZE))) {
if (blkvsc_req) {
blkvsc_req->sector_start =
start_sector;
sector_div(
blkvsc_req->sector_start,
(blkdev->sector_size >> 9));
blkvsc_req->sector_count =
num_sectors /
(blkdev->sector_size >> 9);
blkvsc_init_rw(blkvsc_req);
}
blkvsc_req =
kmem_cache_zalloc(
blkdev->request_pool, GFP_ATOMIC);
if (!blkvsc_req) {
list_for_each_entry_safe(
blkvsc_req, tmp,
&group->blkvsc_req_list,
req_entry) {
list_del(
&blkvsc_req->req_entry);
kmem_cache_free(
blkdev->request_pool,
blkvsc_req);
}
kmem_cache_free(
blkdev->request_pool, group);
return -ENOMEM;
}
memset(blkvsc_req, 0,
sizeof(struct blkvsc_request));
blkvsc_req->dev = blkdev;
blkvsc_req->req = req;
blkvsc_req->request.
data_buffer.offset
= bvec->bv_offset;
blkvsc_req->request.
data_buffer.len = 0;
blkvsc_req->group = group;
blkvsc_req->group->outstanding++;
list_add_tail(&blkvsc_req->req_entry,
&blkvsc_req->group->blkvsc_req_list);
start_sector += num_sectors;
num_sectors = 0;
databuf_idx = 0;
}
blkvsc_req->request.data_buffer.
pfn_array[databuf_idx]
= page_to_pfn(bvec->bv_page);
blkvsc_req->request.data_buffer.len
+= bvec->bv_len;
prev_bvec = bvec;
databuf_idx++;
num_sectors += bvec->bv_len >> 9;
}
}
}
if (blkvsc_req) {
blkvsc_req->sector_start = start_sector;
sector_div(blkvsc_req->sector_start,
(blkdev->sector_size >> 9));
blkvsc_req->sector_count = num_sectors /
(blkdev->sector_size >> 9);
blkvsc_init_rw(blkvsc_req);
}
list_for_each_entry(blkvsc_req, &group->blkvsc_req_list, req_entry) {
if (pending) {
list_add_tail(&blkvsc_req->pend_entry,
&blkdev->pending_list);
} else {
ret = blkvsc_submit_request(blkvsc_req,
blkvsc_request_completion);
if (ret == -1) {
pending = 1;
list_add_tail(&blkvsc_req->pend_entry,
&blkdev->pending_list);
}
}
}
return pending;
}
static int blkvsc_do_pending_reqs(struct block_device_context *blkdev)
{
struct blkvsc_request *pend_req, *tmp;
int ret = 0;
list_for_each_entry_safe(pend_req, tmp, &blkdev->pending_list,
pend_entry) {
ret = blkvsc_submit_request(pend_req,
blkvsc_request_completion);
if (ret != 0)
break;
else
list_del(&pend_req->pend_entry);
}
return ret;
}
static void blkvsc_request(struct request_queue *queue)
{
struct block_device_context *blkdev = NULL;
struct request *req;
int ret = 0;
while ((req = blk_peek_request(queue)) != NULL) {
blkdev = req->rq_disk->private_data;
if (blkdev->shutting_down || req->cmd_type != REQ_TYPE_FS) {
__blk_end_request_cur(req, 0);
continue;
}
ret = blkvsc_do_pending_reqs(blkdev);
if (ret != 0) {
blk_stop_queue(queue);
break;
}
blk_start_request(req);
ret = blkvsc_do_request(blkdev, req);
if (ret > 0) {
blk_stop_queue(queue);
break;
} else if (ret < 0) {
blk_requeue_request(queue, req);
blk_stop_queue(queue);
break;
}
}
}
static int blkvsc_drv_init(void)
{
struct hv_driver *drv = &blkvsc_drv;
int ret;
BUILD_BUG_ON(sizeof(sector_t) != 8);
memcpy(&drv->dev_type, &dev_type, sizeof(struct hv_guid));
drv->driver.name = drv_name;
ret = vmbus_child_driver_register(&drv->driver);
return ret;
}
static void blkvsc_drv_exit(void)
{
vmbus_child_driver_unregister(&blkvsc_drv.driver);
}
static int blkvsc_probe(struct hv_device *dev)
{
struct block_device_context *blkdev = NULL;
struct storvsc_device_info device_info;
struct storvsc_major_info major_info;
int ret = 0;
blkdev = kzalloc(sizeof(struct block_device_context), GFP_KERNEL);
if (!blkdev) {
ret = -ENOMEM;
goto cleanup;
}
INIT_LIST_HEAD(&blkdev->pending_list);
spin_lock_init(&blkdev->lock);
blkdev->request_pool = kmem_cache_create(dev_name(&dev->device),
sizeof(struct blkvsc_request), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (!blkdev->request_pool) {
ret = -ENOMEM;
goto cleanup;
}
ret = blkvsc_device_add(dev, &device_info);
if (ret != 0)
goto cleanup;
blkdev->device_ctx = dev;
blkdev->target = device_info.target_id;
blkdev->path = device_info.path_id;
dev_set_drvdata(&dev->device, blkdev);
ret = storvsc_get_major_info(&device_info, &major_info);
if (ret)
goto cleanup;
if (major_info.do_register) {
ret = register_blkdev(major_info.major, major_info.devname);
if (ret != 0) {
DPRINT_ERR(BLKVSC_DRV,
"register_blkdev() failed! ret %d", ret);
goto remove;
}
}
DPRINT_INFO(BLKVSC_DRV, "blkvsc registered for major %d!!",
major_info.major);
blkdev->gd = alloc_disk(BLKVSC_MINORS);
if (!blkdev->gd) {
ret = -1;
goto cleanup;
}
blkdev->gd->queue = blk_init_queue(blkvsc_request, &blkdev->lock);
blk_queue_max_segment_size(blkdev->gd->queue, PAGE_SIZE);
blk_queue_max_segments(blkdev->gd->queue, MAX_MULTIPAGE_BUFFER_COUNT);
blk_queue_segment_boundary(blkdev->gd->queue, PAGE_SIZE-1);
blk_queue_bounce_limit(blkdev->gd->queue, BLK_BOUNCE_ANY);
blk_queue_dma_alignment(blkdev->gd->queue, 511);
blkdev->gd->major = major_info.major;
if (major_info.index == 1 || major_info.index == 3)
blkdev->gd->first_minor = BLKVSC_MINORS;
else
blkdev->gd->first_minor = 0;
blkdev->gd->fops = &block_ops;
blkdev->gd->private_data = blkdev;
blkdev->gd->driverfs_dev = &(blkdev->device_ctx->device);
sprintf(blkdev->gd->disk_name, "hd%c", 'a' + major_info.index);
blkvsc_do_operation(blkdev, DO_INQUIRY);
blkvsc_do_operation(blkdev, DO_CAPACITY);
set_capacity(blkdev->gd, blkdev->capacity * (blkdev->sector_size/512));
blk_queue_logical_block_size(blkdev->gd->queue, blkdev->sector_size);
add_disk(blkdev->gd);
DPRINT_INFO(BLKVSC_DRV, "%s added!! capacity %lu sector_size %d",
blkdev->gd->disk_name, (unsigned long)blkdev->capacity,
blkdev->sector_size);
return ret;
remove:
storvsc_dev_remove(dev);
cleanup:
if (blkdev) {
if (blkdev->request_pool) {
kmem_cache_destroy(blkdev->request_pool);
blkdev->request_pool = NULL;
}
kfree(blkdev);
blkdev = NULL;
}
return ret;
}
static void blkvsc_request_completion(struct hv_storvsc_request *request)
{
struct blkvsc_request *blkvsc_req =
(struct blkvsc_request *)request->context;
struct block_device_context *blkdev =
(struct block_device_context *)blkvsc_req->dev;
unsigned long flags;
struct blkvsc_request *comp_req, *tmp;
struct vmscsi_request *vm_srb;
spin_lock_irqsave(&blkdev->lock, flags);
blkdev->num_outstanding_reqs--;
blkvsc_req->group->outstanding--;
if (blkvsc_req->group->outstanding == 0) {
list_for_each_entry_safe(comp_req, tmp,
&blkvsc_req->group->blkvsc_req_list,
req_entry) {
list_del(&comp_req->req_entry);
vm_srb =
&comp_req->request.vstor_packet.vm_srb;
if (!__blk_end_request(comp_req->req,
(!vm_srb->scsi_status ? 0 : -EIO),
comp_req->sector_count * blkdev->sector_size)) {
kmem_cache_free(blkdev->request_pool,
comp_req->group);
}
kmem_cache_free(blkdev->request_pool, comp_req);
}
if (!blkdev->shutting_down) {
blkvsc_do_pending_reqs(blkdev);
blk_start_queue(blkdev->gd->queue);
blkvsc_request(blkdev->gd->queue);
}
}
spin_unlock_irqrestore(&blkdev->lock, flags);
}
static void __exit blkvsc_exit(void)
{
blkvsc_drv_exit();
}
