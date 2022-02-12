static int proc_viocd_show(struct seq_file *m, void *v)
{
int i;
for (i = 0; i < viocd_numdev; i++) {
seq_printf(m, "viocd device %d is iSeries resource %10.10s"
"type %4.4s, model %3.3s\n",
i, viocd_diskinfo[i].rsrcname,
viocd_diskinfo[i].type,
viocd_diskinfo[i].model);
}
return 0;
}
static int proc_viocd_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_viocd_show, NULL);
}
static int viocd_blk_open(struct block_device *bdev, fmode_t mode)
{
struct disk_info *di = bdev->bd_disk->private_data;
int ret;
mutex_lock(&viocd_mutex);
ret = cdrom_open(&di->viocd_info, bdev, mode);
mutex_unlock(&viocd_mutex);
return ret;
}
static int viocd_blk_release(struct gendisk *disk, fmode_t mode)
{
struct disk_info *di = disk->private_data;
mutex_lock(&viocd_mutex);
cdrom_release(&di->viocd_info, mode);
mutex_unlock(&viocd_mutex);
return 0;
}
static int viocd_blk_ioctl(struct block_device *bdev, fmode_t mode,
unsigned cmd, unsigned long arg)
{
struct disk_info *di = bdev->bd_disk->private_data;
int ret;
mutex_lock(&viocd_mutex);
ret = cdrom_ioctl(&di->viocd_info, bdev, mode, cmd, arg);
mutex_unlock(&viocd_mutex);
return ret;
}
static unsigned int viocd_blk_check_events(struct gendisk *disk,
unsigned int clearing)
{
struct disk_info *di = disk->private_data;
return cdrom_check_events(&di->viocd_info, clearing);
}
static int viocd_open(struct cdrom_device_info *cdi, int purpose)
{
struct disk_info *diskinfo = cdi->handle;
int device_no = DEVICE_NR(diskinfo);
HvLpEvent_Rc hvrc;
struct viocd_waitevent we;
init_completion(&we.com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_cdio | viocdopen,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)&we, VIOVERSION << 16, ((u64)device_no << 48),
0, 0, 0);
if (hvrc != 0) {
pr_warning("bad rc on HvCallEvent_signalLpEventFast %d\n",
(int)hvrc);
return -EIO;
}
wait_for_completion(&we.com);
if (we.rc) {
const struct vio_error_entry *err =
vio_lookup_rc(viocd_err_table, we.sub_result);
pr_warning("bad rc %d:0x%04X on open: %s\n",
we.rc, we.sub_result, err->msg);
return -err->errno;
}
return 0;
}
static void viocd_release(struct cdrom_device_info *cdi)
{
int device_no = DEVICE_NR((struct disk_info *)cdi->handle);
HvLpEvent_Rc hvrc;
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_cdio | viocdclose,
HvLpEvent_AckInd_NoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp), 0,
VIOVERSION << 16, ((u64)device_no << 48), 0, 0, 0);
if (hvrc != 0)
pr_warning("bad rc on HvCallEvent_signalLpEventFast %d\n",
(int)hvrc);
}
static int send_request(struct request *req)
{
HvLpEvent_Rc hvrc;
struct disk_info *diskinfo = req->rq_disk->private_data;
u64 len;
dma_addr_t dmaaddr;
int direction;
u16 cmd;
struct scatterlist sg;
BUG_ON(req->nr_phys_segments > 1);
if (rq_data_dir(req) == READ) {
direction = DMA_FROM_DEVICE;
cmd = viomajorsubtype_cdio | viocdread;
} else {
direction = DMA_TO_DEVICE;
cmd = viomajorsubtype_cdio | viocdwrite;
}
sg_init_table(&sg, 1);
if (blk_rq_map_sg(req->q, req, &sg) == 0) {
pr_warning("error setting up scatter/gather list\n");
return -1;
}
if (dma_map_sg(diskinfo->dev, &sg, 1, direction) == 0) {
pr_warning("error allocating sg tce\n");
return -1;
}
dmaaddr = sg_dma_address(&sg);
len = sg_dma_len(&sg);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo, cmd,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)req, VIOVERSION << 16,
((u64)DEVICE_NR(diskinfo) << 48) | dmaaddr,
(u64)blk_rq_pos(req) * 512, len, 0);
if (hvrc != HvLpEvent_Rc_Good) {
pr_warning("hv error on op %d\n", (int)hvrc);
return -1;
}
return 0;
}
static void do_viocd_request(struct request_queue *q)
{
struct request *req;
while ((rwreq == 0) && ((req = blk_fetch_request(q)) != NULL)) {
if (req->cmd_type != REQ_TYPE_FS)
__blk_end_request_all(req, -EIO);
else if (send_request(req) < 0) {
pr_warning("unable to send message to OS/400!\n");
__blk_end_request_all(req, -EIO);
} else
rwreq++;
}
}
static unsigned int viocd_check_events(struct cdrom_device_info *cdi,
unsigned int clearing, int disc_nr)
{
struct viocd_waitevent we;
HvLpEvent_Rc hvrc;
int device_no = DEVICE_NR((struct disk_info *)cdi->handle);
init_completion(&we.com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_cdio | viocdcheck,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)&we, VIOVERSION << 16, ((u64)device_no << 48),
0, 0, 0);
if (hvrc != 0) {
pr_warning("bad rc on HvCallEvent_signalLpEventFast %d\n",
(int)hvrc);
return 0;
}
wait_for_completion(&we.com);
if (we.rc) {
const struct vio_error_entry *err =
vio_lookup_rc(viocd_err_table, we.sub_result);
pr_warning("bad rc %d:0x%04X on check_change: %s; Assuming no change\n",
we.rc, we.sub_result, err->msg);
return 0;
}
return we.changed ? DISK_EVENT_MEDIA_CHANGE : 0;
}
static int viocd_lock_door(struct cdrom_device_info *cdi, int locking)
{
HvLpEvent_Rc hvrc;
u64 device_no = DEVICE_NR((struct disk_info *)cdi->handle);
u64 flags = !!locking;
struct viocd_waitevent we;
init_completion(&we.com);
hvrc = HvCallEvent_signalLpEventFast(viopath_hostLp,
HvLpEvent_Type_VirtualIo,
viomajorsubtype_cdio | viocdlockdoor,
HvLpEvent_AckInd_DoAck, HvLpEvent_AckType_ImmediateAck,
viopath_sourceinst(viopath_hostLp),
viopath_targetinst(viopath_hostLp),
(u64)&we, VIOVERSION << 16,
(device_no << 48) | (flags << 32), 0, 0, 0);
if (hvrc != 0) {
pr_warning("bad rc on HvCallEvent_signalLpEventFast %d\n",
(int)hvrc);
return -EIO;
}
wait_for_completion(&we.com);
if (we.rc != 0)
return -EIO;
return 0;
}
static int viocd_packet(struct cdrom_device_info *cdi,
struct packet_command *cgc)
{
unsigned int buflen = cgc->buflen;
int ret = -EIO;
switch (cgc->cmd[0]) {
case GPCMD_READ_DISC_INFO:
{
disc_information *di = (disc_information *)cgc->buffer;
if (buflen >= 2) {
di->disc_information_length = cpu_to_be16(1);
ret = 0;
}
if (buflen >= 3)
di->erasable =
(cdi->ops->capability & ~cdi->mask
& (CDC_DVD_RAM | CDC_RAM)) != 0;
}
break;
case GPCMD_GET_CONFIGURATION:
if (cgc->cmd[3] == CDF_RWRT) {
struct rwrt_feature_desc *rfd = (struct rwrt_feature_desc *)(cgc->buffer + sizeof(struct feature_header));
if ((buflen >=
(sizeof(struct feature_header) + sizeof(*rfd))) &&
(cdi->ops->capability & ~cdi->mask
& (CDC_DVD_RAM | CDC_RAM))) {
rfd->feature_code = cpu_to_be16(CDF_RWRT);
rfd->curr = 1;
ret = 0;
}
}
break;
default:
if (cgc->sense) {
cgc->sense->sense_key = 0x05;
cgc->sense->asc = 0x20;
cgc->sense->ascq = 0x00;
}
break;
}
cgc->stat = ret;
return ret;
}
static void restart_all_queues(int first_index)
{
int i;
for (i = first_index + 1; i < viocd_numdev; i++)
if (viocd_diskinfo[i].viocd_disk)
blk_run_queue(viocd_diskinfo[i].viocd_disk->queue);
for (i = 0; i <= first_index; i++)
if (viocd_diskinfo[i].viocd_disk)
blk_run_queue(viocd_diskinfo[i].viocd_disk->queue);
}
static void vio_handle_cd_event(struct HvLpEvent *event)
{
struct viocdlpevent *bevent;
struct viocd_waitevent *pwe;
struct disk_info *di;
unsigned long flags;
struct request *req;
if (event == NULL)
return;
if (hvlpevent_is_int(event)) {
pr_warning("Yikes! got an int in viocd event handler!\n");
if (hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
}
bevent = (struct viocdlpevent *)event;
switch (event->xSubtype & VIOMINOR_SUBTYPE_MASK) {
case viocdopen:
if (event->xRc == 0) {
di = &viocd_diskinfo[bevent->disk];
blk_queue_logical_block_size(di->viocd_disk->queue,
bevent->block_size);
set_capacity(di->viocd_disk,
bevent->media_size *
bevent->block_size / 512);
}
case viocdlockdoor:
pwe = (struct viocd_waitevent *)event->xCorrelationToken;
return_complete:
pwe->rc = event->xRc;
pwe->sub_result = bevent->sub_result;
complete(&pwe->com);
break;
case viocdcheck:
pwe = (struct viocd_waitevent *)event->xCorrelationToken;
pwe->changed = bevent->flags;
goto return_complete;
case viocdclose:
break;
case viocdwrite:
case viocdread:
di = &viocd_diskinfo[bevent->disk];
spin_lock_irqsave(&viocd_reqlock, flags);
dma_unmap_single(di->dev, bevent->token, bevent->len,
((event->xSubtype & VIOMINOR_SUBTYPE_MASK) == viocdread)
? DMA_FROM_DEVICE : DMA_TO_DEVICE);
req = (struct request *)bevent->event.xCorrelationToken;
rwreq--;
if (event->xRc != HvLpEvent_Rc_Good) {
const struct vio_error_entry *err =
vio_lookup_rc(viocd_err_table,
bevent->sub_result);
pr_warning("request %p failed with rc %d:0x%04X: %s\n",
req, event->xRc,
bevent->sub_result, err->msg);
__blk_end_request_all(req, -EIO);
} else
__blk_end_request_all(req, 0);
spin_unlock_irqrestore(&viocd_reqlock, flags);
restart_all_queues(bevent->disk);
break;
default:
pr_warning("message with invalid subtype %0x04X!\n",
event->xSubtype & VIOMINOR_SUBTYPE_MASK);
if (hvlpevent_need_ack(event)) {
event->xRc = HvLpEvent_Rc_InvalidSubtype;
HvCallEvent_ackLpEvent(event);
}
}
}
static int viocd_audio_ioctl(struct cdrom_device_info *cdi, unsigned int cmd,
void *arg)
{
return -EINVAL;
}
static int find_capability(const char *type)
{
struct capability_entry *entry;
for(entry = capability_table; entry->type; ++entry)
if(!strncmp(entry->type, type, 4))
break;
return entry->capability;
}
static int viocd_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
struct gendisk *gendisk;
int deviceno;
struct disk_info *d;
struct cdrom_device_info *c;
struct request_queue *q;
struct device_node *node = vdev->dev.of_node;
deviceno = vdev->unit_address;
if (deviceno >= VIOCD_MAX_CD)
return -ENODEV;
if (!node)
return -ENODEV;
if (deviceno >= viocd_numdev)
viocd_numdev = deviceno + 1;
d = &viocd_diskinfo[deviceno];
d->rsrcname = of_get_property(node, "linux,vio_rsrcname", NULL);
d->type = of_get_property(node, "linux,vio_type", NULL);
d->model = of_get_property(node, "linux,vio_model", NULL);
c = &d->viocd_info;
c->ops = &viocd_dops;
c->speed = 4;
c->capacity = 1;
c->handle = d;
c->mask = ~find_capability(d->type);
sprintf(c->name, VIOCD_DEVICE "%c", 'a' + deviceno);
if (register_cdrom(c) != 0) {
pr_warning("Cannot register viocd CD-ROM %s!\n", c->name);
goto out;
}
pr_info("cd %s is iSeries resource %10.10s type %4.4s, model %3.3s\n",
c->name, d->rsrcname, d->type, d->model);
q = blk_init_queue(do_viocd_request, &viocd_reqlock);
if (q == NULL) {
pr_warning("Cannot allocate queue for %s!\n", c->name);
goto out_unregister_cdrom;
}
gendisk = alloc_disk(1);
if (gendisk == NULL) {
pr_warning("Cannot create gendisk for %s!\n", c->name);
goto out_cleanup_queue;
}
gendisk->major = VIOCD_MAJOR;
gendisk->first_minor = deviceno;
strncpy(gendisk->disk_name, c->name,
sizeof(gendisk->disk_name));
blk_queue_max_segments(q, 1);
blk_queue_max_hw_sectors(q, 4096 / 512);
gendisk->queue = q;
gendisk->fops = &viocd_fops;
gendisk->flags = GENHD_FL_CD | GENHD_FL_REMOVABLE |
GENHD_FL_BLOCK_EVENTS_ON_EXCL_WRITE;
set_capacity(gendisk, 0);
gendisk->private_data = d;
d->viocd_disk = gendisk;
d->dev = &vdev->dev;
gendisk->driverfs_dev = d->dev;
add_disk(gendisk);
return 0;
out_cleanup_queue:
blk_cleanup_queue(q);
out_unregister_cdrom:
unregister_cdrom(c);
out:
return -ENODEV;
}
static int viocd_remove(struct vio_dev *vdev)
{
struct disk_info *d = &viocd_diskinfo[vdev->unit_address];
unregister_cdrom(&d->viocd_info);
del_gendisk(d->viocd_disk);
blk_cleanup_queue(d->viocd_disk->queue);
put_disk(d->viocd_disk);
return 0;
}
static int __init viocd_init(void)
{
int ret = 0;
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return -ENODEV;
if (viopath_hostLp == HvLpIndexInvalid) {
vio_set_hostlp();
if (viopath_hostLp == HvLpIndexInvalid)
return -ENODEV;
}
pr_info("vers " VIOCD_VERS ", hosting partition %d\n", viopath_hostLp);
if (register_blkdev(VIOCD_MAJOR, VIOCD_DEVICE) != 0) {
pr_warning("Unable to get major %d for %s\n",
VIOCD_MAJOR, VIOCD_DEVICE);
return -EIO;
}
ret = viopath_open(viopath_hostLp, viomajorsubtype_cdio,
MAX_CD_REQ + 2);
if (ret) {
pr_warning("error opening path to host partition %d\n",
viopath_hostLp);
goto out_unregister;
}
vio_setHandler(viomajorsubtype_cdio, vio_handle_cd_event);
spin_lock_init(&viocd_reqlock);
ret = vio_register_driver(&viocd_driver);
if (ret)
goto out_free_info;
proc_create("iSeries/viocd", S_IFREG|S_IRUGO, NULL,
&proc_viocd_operations);
return 0;
out_free_info:
vio_clearHandler(viomajorsubtype_cdio);
viopath_close(viopath_hostLp, viomajorsubtype_cdio, MAX_CD_REQ + 2);
out_unregister:
unregister_blkdev(VIOCD_MAJOR, VIOCD_DEVICE);
return ret;
}
static void __exit viocd_exit(void)
{
remove_proc_entry("iSeries/viocd", NULL);
vio_unregister_driver(&viocd_driver);
viopath_close(viopath_hostLp, viomajorsubtype_cdio, MAX_CD_REQ + 2);
vio_clearHandler(viomajorsubtype_cdio);
unregister_blkdev(VIOCD_MAJOR, VIOCD_DEVICE);
}
