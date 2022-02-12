static int viodasd_open(struct block_device *bdev, fmode_t mode)
{
struct viodasd_device *d = bdev->bd_disk->private_data;
HvLpEvent_Rc hvrc;
struct viodasd_waitevent we;
u16 flags = 0;
if (d->read_only) {
if (mode & FMODE_WRITE)
return -EROFS;
flags = vioblockflags_ro;
}
init_completion(&we.com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_blockio | vioblockopen,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)&we, VIOVERSION << 16,
((u64)DEVICE_NO(d) << 48) | ((u64)flags << 32),
0, 0, 0);
if (hvrc != 0) {
pr_warning("HV open failed %d\n", (int)hvrc);
return -EIO;
}
wait_for_completion(&we.com);
if (we.rc != 0) {
const struct vio_error_entry *err =
vio_lookup_rc(viodasd_err_table, we.sub_result);
pr_warning("bad rc opening disk: %d:0x%04x (%s)\n",
(int)we.rc, we.sub_result, err->msg);
return -EIO;
}
return 0;
}
static int viodasd_unlocked_open(struct block_device *bdev, fmode_t mode)
{
int ret;
mutex_lock(&viodasd_mutex);
ret = viodasd_open(bdev, mode);
mutex_unlock(&viodasd_mutex);
return ret;
}
static int viodasd_release(struct gendisk *disk, fmode_t mode)
{
struct viodasd_device *d = disk->private_data;
HvLpEvent_Rc hvrc;
mutex_lock(&viodasd_mutex);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_blockio | vioblockclose,
HvLpEvent_AckInd_NoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
0, VIOVERSION << 16,
((u64)DEVICE_NO(d) << 48) ,
0, 0, 0);
if (hvrc != 0)
pr_warning("HV close call failed %d\n", (int)hvrc);
mutex_unlock(&viodasd_mutex);
return 0;
}
static int viodasd_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct gendisk *disk = bdev->bd_disk;
struct viodasd_device *d = disk->private_data;
geo->sectors = d->sectors ? d->sectors : 32;
geo->heads = d->tracks ? d->tracks : 64;
geo->cylinders = d->cylinders ? d->cylinders :
get_capacity(disk) / (geo->sectors * geo->heads);
return 0;
}
static void viodasd_end_request(struct request *req, int error,
int num_sectors)
{
__blk_end_request(req, error, num_sectors << 9);
}
static int send_request(struct request *req)
{
u64 start;
int direction;
int nsg;
u16 viocmd;
HvLpEvent_Rc hvrc;
struct vioblocklpevent *bevent;
struct HvLpEvent *hev;
struct scatterlist sg[VIOMAXBLOCKDMA];
int sgindex;
struct viodasd_device *d;
unsigned long flags;
start = (u64)blk_rq_pos(req) << 9;
if (rq_data_dir(req) == READ) {
direction = DMA_FROM_DEVICE;
viocmd = viomajorsubtype_blockio | vioblockread;
} else {
direction = DMA_TO_DEVICE;
viocmd = viomajorsubtype_blockio | vioblockwrite;
}
d = req->rq_disk->private_data;
sg_init_table(sg, VIOMAXBLOCKDMA);
nsg = blk_rq_map_sg(req->q, req, sg);
nsg = dma_map_sg(d->dev, sg, nsg, direction);
spin_lock_irqsave(&viodasd_spinlock, flags);
num_req_outstanding++;
if (nsg == 1)
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo, viocmd,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)req, VIOVERSION << 16,
((u64)DEVICE_NO(d) << 48), start,
((u64)sg_dma_address(&sg[0])) << 32,
sg_dma_len(&sg[0]));
else {
bevent = (struct vioblocklpevent *)
vio_get_event_buffer(viomajorsubtype_blockio);
if (bevent == NULL) {
pr_warning("error allocating disk event buffer\n");
goto error_ret;
}
memset(bevent, 0, sizeof(struct vioblocklpevent));
hev = &bevent->event;
hev->flags = HV_LP_EVENT_VALID | HV_LP_EVENT_DO_ACK |
HV_LP_EVENT_INT;
hev->xType = HvLpEvent_Type_VirtualIo;
hev->xSubtype = viocmd;
hev->xSourceLp = HvLpConfig_getLpIndex();
hev->xTargetLp = viopath_hostLp;
hev->xSizeMinus1 =
offsetof(struct vioblocklpevent, u.rw_data.dma_info) +
(sizeof(bevent->u.rw_data.dma_info[0]) * nsg) - 1;
hev->xSourceInstanceId = viopath_sourceinst(viopath_hostLp);
hev->xTargetInstanceId = viopath_targetinst(viopath_hostLp);
hev->xCorrelationToken = (u64)req;
bevent->version = VIOVERSION;
bevent->disk = DEVICE_NO(d);
bevent->u.rw_data.offset = start;
for (sgindex = 0; sgindex < nsg; sgindex++) {
bevent->u.rw_data.dma_info[sgindex].token =
sg_dma_address(&sg[sgindex]);
bevent->u.rw_data.dma_info[sgindex].len =
sg_dma_len(&sg[sgindex]);
}
hvrc = HvCallEvent_signalLpEvent(&bevent->event);
vio_free_event_buffer(viomajorsubtype_blockio, bevent);
}
if (hvrc != HvLpEvent_Rc_Good) {
pr_warning("error sending disk event to OS/400 (rc %d)\n",
(int)hvrc);
goto error_ret;
}
spin_unlock_irqrestore(&viodasd_spinlock, flags);
return 0;
error_ret:
num_req_outstanding--;
spin_unlock_irqrestore(&viodasd_spinlock, flags);
dma_unmap_sg(d->dev, sg, nsg, direction);
return -1;
}
static void do_viodasd_request(struct request_queue *q)
{
struct request *req;
while (num_req_outstanding < VIOMAXREQ) {
req = blk_fetch_request(q);
if (req == NULL)
return;
if (req->cmd_type != REQ_TYPE_FS) {
viodasd_end_request(req, -EIO, blk_rq_sectors(req));
continue;
}
if (send_request(req) != 0)
viodasd_end_request(req, -EIO, blk_rq_sectors(req));
}
}
static int probe_disk(struct viodasd_device *d)
{
HvLpEvent_Rc hvrc;
struct viodasd_waitevent we;
int dev_no = DEVICE_NO(d);
struct gendisk *g;
struct request_queue *q;
u16 flags = 0;
retry:
init_completion(&we.com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_blockio | vioblockopen,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)(unsigned long)&we, VIOVERSION << 16,
((u64)dev_no << 48) | ((u64)flags<< 32),
0, 0, 0);
if (hvrc != 0) {
pr_warning("bad rc on HV open %d\n", (int)hvrc);
return 0;
}
wait_for_completion(&we.com);
if (we.rc != 0) {
if (flags != 0)
return 0;
flags = vioblockflags_ro;
goto retry;
}
if (we.max_disk > (MAX_DISKNO - 1)) {
printk_once(KERN_INFO pr_fmt("Only examining the first %d of %d disks connected\n"),
MAX_DISKNO, we.max_disk + 1);
}
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_blockio | vioblockclose,
HvLpEvent_AckInd_NoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
0, VIOVERSION << 16,
((u64)dev_no << 48) | ((u64)flags << 32),
0, 0, 0);
if (hvrc != 0) {
pr_warning("bad rc sending event to OS/400 %d\n", (int)hvrc);
return 0;
}
if (d->dev == NULL) {
if (vio_create_viodasd(dev_no) == NULL) {
pr_warning("cannot allocate virtual device for disk %d\n",
dev_no);
return 0;
}
return 1;
}
spin_lock_init(&d->q_lock);
q = blk_init_queue(do_viodasd_request, &d->q_lock);
if (q == NULL) {
pr_warning("cannot allocate queue for disk %d\n", dev_no);
return 0;
}
g = alloc_disk(1 << PARTITION_SHIFT);
if (g == NULL) {
pr_warning("cannot allocate disk structure for disk %d\n",
dev_no);
blk_cleanup_queue(q);
return 0;
}
d->disk = g;
blk_queue_max_segments(q, VIOMAXBLOCKDMA);
blk_queue_max_hw_sectors(q, VIODASD_MAXSECTORS);
g->major = VIODASD_MAJOR;
g->first_minor = dev_no << PARTITION_SHIFT;
if (dev_no >= 26)
snprintf(g->disk_name, sizeof(g->disk_name),
VIOD_GENHD_NAME "%c%c",
'a' + (dev_no / 26) - 1, 'a' + (dev_no % 26));
else
snprintf(g->disk_name, sizeof(g->disk_name),
VIOD_GENHD_NAME "%c", 'a' + (dev_no % 26));
g->fops = &viodasd_fops;
g->queue = q;
g->private_data = d;
g->driverfs_dev = d->dev;
set_capacity(g, d->size >> 9);
pr_info("disk %d: %lu sectors (%lu MB) CHS=%d/%d/%d sector size %d%s\n",
dev_no, (unsigned long)(d->size >> 9),
(unsigned long)(d->size >> 20),
(int)d->cylinders, (int)d->tracks,
(int)d->sectors, (int)d->bytes_per_sector,
d->read_only ? " (RO)" : "");
add_disk(g);
return 1;
}
static int block_event_to_scatterlist(const struct vioblocklpevent *bevent,
struct scatterlist *sg, int *total_len)
{
int i, numsg;
const struct rw_data *rw_data = &bevent->u.rw_data;
static const int offset =
offsetof(struct vioblocklpevent, u.rw_data.dma_info);
static const int element_size = sizeof(rw_data->dma_info[0]);
numsg = ((bevent->event.xSizeMinus1 + 1) - offset) / element_size;
if (numsg > VIOMAXBLOCKDMA)
numsg = VIOMAXBLOCKDMA;
*total_len = 0;
sg_init_table(sg, VIOMAXBLOCKDMA);
for (i = 0; (i < numsg) && (rw_data->dma_info[i].len > 0); ++i) {
sg_dma_address(&sg[i]) = rw_data->dma_info[i].token;
sg_dma_len(&sg[i]) = rw_data->dma_info[i].len;
*total_len += rw_data->dma_info[i].len;
}
return i;
}
static void viodasd_restart_all_queues_starting_from(int first_index)
{
int i;
for (i = first_index + 1; i < MAX_DISKNO; ++i)
if (viodasd_devices[i].disk)
blk_run_queue(viodasd_devices[i].disk->queue);
for (i = 0; i <= first_index; ++i)
if (viodasd_devices[i].disk)
blk_run_queue(viodasd_devices[i].disk->queue);
}
static int viodasd_handle_read_write(struct vioblocklpevent *bevent)
{
int num_sg, num_sect, pci_direction, total_len;
struct request *req;
struct scatterlist sg[VIOMAXBLOCKDMA];
struct HvLpEvent *event = &bevent->event;
unsigned long irq_flags;
struct viodasd_device *d;
int error;
spinlock_t *qlock;
num_sg = block_event_to_scatterlist(bevent, sg, &total_len);
num_sect = total_len >> 9;
if (event->xSubtype == (viomajorsubtype_blockio | vioblockread))
pci_direction = DMA_FROM_DEVICE;
else
pci_direction = DMA_TO_DEVICE;
req = (struct request *)bevent->event.xCorrelationToken;
d = req->rq_disk->private_data;
dma_unmap_sg(d->dev, sg, num_sg, pci_direction);
spin_lock_irqsave(&viodasd_spinlock, irq_flags);
num_req_outstanding--;
spin_unlock_irqrestore(&viodasd_spinlock, irq_flags);
error = (event->xRc == HvLpEvent_Rc_Good) ? 0 : -EIO;
if (error) {
const struct vio_error_entry *err;
err = vio_lookup_rc(viodasd_err_table, bevent->sub_result);
pr_warning("read/write error %d:0x%04x (%s)\n",
event->xRc, bevent->sub_result, err->msg);
num_sect = blk_rq_sectors(req);
}
qlock = req->q->queue_lock;
spin_lock_irqsave(qlock, irq_flags);
viodasd_end_request(req, error, num_sect);
spin_unlock_irqrestore(qlock, irq_flags);
viodasd_restart_all_queues_starting_from(DEVICE_NO(d));
return 0;
}
static void handle_block_event(struct HvLpEvent *event)
{
struct vioblocklpevent *bevent = (struct vioblocklpevent *)event;
struct viodasd_waitevent *pwe;
if (event == NULL)
return;
if (hvlpevent_is_int(event)) {
pr_warning("Yikes! got an int in viodasd event handler!\n");
if (hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
}
switch (event->xSubtype & VIOMINOR_SUBTYPE_MASK) {
case vioblockopen:
pwe = (struct viodasd_waitevent *)event->xCorrelationToken;
pwe->rc = event->xRc;
pwe->sub_result = bevent->sub_result;
if (event->xRc == HvLpEvent_Rc_Good) {
const struct open_data *data = &bevent->u.open_data;
struct viodasd_device *device =
&viodasd_devices[bevent->disk];
device->read_only =
bevent->flags & vioblockflags_ro;
device->size = data->disk_size;
device->cylinders = data->cylinders;
device->tracks = data->tracks;
device->sectors = data->sectors;
device->bytes_per_sector = data->bytes_per_sector;
pwe->max_disk = data->max_disk;
}
complete(&pwe->com);
break;
case vioblockclose:
break;
case vioblockread:
case vioblockwrite:
viodasd_handle_read_write(bevent);
break;
default:
pr_warning("invalid subtype!");
if (hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
}
}
static ssize_t probe_disks(struct device_driver *drv, const char *buf,
size_t count)
{
struct viodasd_device *d;
for (d = viodasd_devices; d < &viodasd_devices[MAX_DISKNO]; d++) {
if (d->disk == NULL)
probe_disk(d);
}
return count;
}
static int viodasd_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
struct viodasd_device *d = &viodasd_devices[vdev->unit_address];
d->dev = &vdev->dev;
if (!probe_disk(d))
return -ENODEV;
return 0;
}
static int viodasd_remove(struct vio_dev *vdev)
{
struct viodasd_device *d;
d = &viodasd_devices[vdev->unit_address];
if (d->disk) {
del_gendisk(d->disk);
blk_cleanup_queue(d->disk->queue);
put_disk(d->disk);
d->disk = NULL;
}
d->dev = NULL;
return 0;
}
static int __init viodasd_init(void)
{
int rc;
if (!firmware_has_feature(FW_FEATURE_ISERIES)) {
rc = -ENODEV;
goto early_fail;
}
if (viopath_hostLp == HvLpIndexInvalid)
vio_set_hostlp();
if (viopath_hostLp == HvLpIndexInvalid) {
pr_warning("invalid hosting partition\n");
rc = -EIO;
goto early_fail;
}
pr_info("vers " VIOD_VERS ", hosting partition %d\n", viopath_hostLp);
rc = register_blkdev(VIODASD_MAJOR, VIOD_GENHD_NAME);
if (rc) {
pr_warning("Unable to get major number %d for %s\n",
VIODASD_MAJOR, VIOD_GENHD_NAME);
goto early_fail;
}
rc = viopath_open(viopath_hostLp, viomajorsubtype_blockio,
VIOMAXREQ + 2);
if (rc) {
pr_warning("error opening path to host partition %d\n",
viopath_hostLp);
goto unregister_blk;
}
vio_setHandler(viomajorsubtype_blockio, handle_block_event);
rc = vio_register_driver(&viodasd_driver);
if (rc) {
pr_warning("vio_register_driver failed\n");
goto unset_handler;
}
if (!driver_create_file(&viodasd_driver.driver, &driver_attr_probe))
need_delete_probe = 1;
return 0;
unset_handler:
vio_clearHandler(viomajorsubtype_blockio);
viopath_close(viopath_hostLp, viomajorsubtype_blockio, VIOMAXREQ + 2);
unregister_blk:
unregister_blkdev(VIODASD_MAJOR, VIOD_GENHD_NAME);
early_fail:
return rc;
}
void __exit viodasd_exit(void)
{
if (need_delete_probe)
driver_remove_file(&viodasd_driver.driver, &driver_attr_probe);
vio_unregister_driver(&viodasd_driver);
vio_clearHandler(viomajorsubtype_blockio);
viopath_close(viopath_hostLp, viomajorsubtype_blockio, VIOMAXREQ + 2);
unregister_blkdev(VIODASD_MAJOR, VIOD_GENHD_NAME);
}
