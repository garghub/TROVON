static void uas_do_work(struct work_struct *work)
{
struct uas_cmd_info *cmdinfo;
struct uas_cmd_info *temp;
struct list_head list;
unsigned long flags;
int err;
spin_lock_irq(&uas_work_lock);
list_replace_init(&uas_work_list, &list);
spin_unlock_irq(&uas_work_lock);
list_for_each_entry_safe(cmdinfo, temp, &list, list) {
struct scsi_pointer *scp = (void *)cmdinfo;
struct scsi_cmnd *cmnd = container_of(scp,
struct scsi_cmnd, SCp);
struct uas_dev_info *devinfo = (void *)cmnd->device->hostdata;
spin_lock_irqsave(&devinfo->lock, flags);
err = uas_submit_urbs(cmnd, cmnd->device->hostdata, GFP_ATOMIC);
spin_unlock_irqrestore(&devinfo->lock, flags);
if (err) {
list_del(&cmdinfo->list);
spin_lock_irq(&uas_work_lock);
list_add_tail(&cmdinfo->list, &uas_work_list);
spin_unlock_irq(&uas_work_lock);
schedule_work(&uas_work);
}
}
}
static void uas_sense(struct urb *urb, struct scsi_cmnd *cmnd)
{
struct sense_iu *sense_iu = urb->transfer_buffer;
struct scsi_device *sdev = cmnd->device;
if (urb->actual_length > 16) {
unsigned len = be16_to_cpup(&sense_iu->len);
if (len + 16 != urb->actual_length) {
int newlen = min(len + 16, urb->actual_length) - 16;
if (newlen < 0)
newlen = 0;
sdev_printk(KERN_INFO, sdev, "%s: urb length %d "
"disagrees with IU sense data length %d, "
"using %d bytes of sense data\n", __func__,
urb->actual_length, len, newlen);
len = newlen;
}
memcpy(cmnd->sense_buffer, sense_iu->sense, len);
}
cmnd->result = sense_iu->status;
}
static void uas_sense_old(struct urb *urb, struct scsi_cmnd *cmnd)
{
struct sense_iu_old *sense_iu = urb->transfer_buffer;
struct scsi_device *sdev = cmnd->device;
if (urb->actual_length > 8) {
unsigned len = be16_to_cpup(&sense_iu->len) - 2;
if (len + 8 != urb->actual_length) {
int newlen = min(len + 8, urb->actual_length) - 8;
if (newlen < 0)
newlen = 0;
sdev_printk(KERN_INFO, sdev, "%s: urb length %d "
"disagrees with IU sense data length %d, "
"using %d bytes of sense data\n", __func__,
urb->actual_length, len, newlen);
len = newlen;
}
memcpy(cmnd->sense_buffer, sense_iu->sense, len);
}
cmnd->result = sense_iu->status;
}
static void uas_log_cmd_state(struct scsi_cmnd *cmnd, const char *caller)
{
struct uas_cmd_info *ci = (void *)&cmnd->SCp;
scmd_printk(KERN_INFO, cmnd, "%s %p tag %d, inflight:"
"%s%s%s%s%s%s%s%s%s%s%s%s\n",
caller, cmnd, cmnd->request->tag,
(ci->state & SUBMIT_STATUS_URB) ? " s-st" : "",
(ci->state & ALLOC_DATA_IN_URB) ? " a-in" : "",
(ci->state & SUBMIT_DATA_IN_URB) ? " s-in" : "",
(ci->state & ALLOC_DATA_OUT_URB) ? " a-out" : "",
(ci->state & SUBMIT_DATA_OUT_URB) ? " s-out" : "",
(ci->state & ALLOC_CMD_URB) ? " a-cmd" : "",
(ci->state & SUBMIT_CMD_URB) ? " s-cmd" : "",
(ci->state & COMMAND_INFLIGHT) ? " CMD" : "",
(ci->state & DATA_IN_URB_INFLIGHT) ? " IN" : "",
(ci->state & DATA_OUT_URB_INFLIGHT) ? " OUT" : "",
(ci->state & COMMAND_COMPLETED) ? " done" : "",
(ci->state & COMMAND_ABORTED) ? " abort" : "");
}
static int uas_try_complete(struct scsi_cmnd *cmnd, const char *caller)
{
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
struct uas_dev_info *devinfo = (void *)cmnd->device->hostdata;
WARN_ON(!spin_is_locked(&devinfo->lock));
if (cmdinfo->state & (COMMAND_INFLIGHT |
DATA_IN_URB_INFLIGHT |
DATA_OUT_URB_INFLIGHT))
return -EBUSY;
BUG_ON(cmdinfo->state & COMMAND_COMPLETED);
cmdinfo->state |= COMMAND_COMPLETED;
usb_free_urb(cmdinfo->data_in_urb);
usb_free_urb(cmdinfo->data_out_urb);
if (cmdinfo->state & COMMAND_ABORTED) {
scmd_printk(KERN_INFO, cmnd, "abort completed\n");
cmnd->result = DID_ABORT << 16;
}
cmnd->scsi_done(cmnd);
return 0;
}
static void uas_xfer_data(struct urb *urb, struct scsi_cmnd *cmnd,
unsigned direction)
{
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
int err;
cmdinfo->state |= direction | SUBMIT_STATUS_URB;
err = uas_submit_urbs(cmnd, cmnd->device->hostdata, GFP_ATOMIC);
if (err) {
spin_lock(&uas_work_lock);
list_add_tail(&cmdinfo->list, &uas_work_list);
spin_unlock(&uas_work_lock);
schedule_work(&uas_work);
}
}
static void uas_stat_cmplt(struct urb *urb)
{
struct iu *iu = urb->transfer_buffer;
struct Scsi_Host *shost = urb->context;
struct uas_dev_info *devinfo = (void *)shost->hostdata[0];
struct scsi_cmnd *cmnd;
struct uas_cmd_info *cmdinfo;
unsigned long flags;
u16 tag;
if (urb->status) {
dev_err(&urb->dev->dev, "URB BAD STATUS %d\n", urb->status);
usb_free_urb(urb);
return;
}
if (devinfo->resetting) {
usb_free_urb(urb);
return;
}
spin_lock_irqsave(&devinfo->lock, flags);
tag = be16_to_cpup(&iu->tag) - 1;
if (tag == 0)
cmnd = devinfo->cmnd;
else
cmnd = scsi_host_find_tag(shost, tag - 1);
if (!cmnd) {
if (iu->iu_id == IU_ID_RESPONSE) {
memcpy(&devinfo->response, iu, sizeof(devinfo->response));
}
usb_free_urb(urb);
spin_unlock_irqrestore(&devinfo->lock, flags);
return;
}
cmdinfo = (void *)&cmnd->SCp;
switch (iu->iu_id) {
case IU_ID_STATUS:
if (devinfo->cmnd == cmnd)
devinfo->cmnd = NULL;
if (urb->actual_length < 16)
devinfo->uas_sense_old = 1;
if (devinfo->uas_sense_old)
uas_sense_old(urb, cmnd);
else
uas_sense(urb, cmnd);
if (cmnd->result != 0) {
if (cmdinfo->state & DATA_IN_URB_INFLIGHT) {
spin_unlock_irqrestore(&devinfo->lock, flags);
usb_unlink_urb(cmdinfo->data_in_urb);
spin_lock_irqsave(&devinfo->lock, flags);
}
if (cmdinfo->state & DATA_OUT_URB_INFLIGHT) {
spin_unlock_irqrestore(&devinfo->lock, flags);
usb_unlink_urb(cmdinfo->data_out_urb);
spin_lock_irqsave(&devinfo->lock, flags);
}
}
cmdinfo->state &= ~COMMAND_INFLIGHT;
uas_try_complete(cmnd, __func__);
break;
case IU_ID_READ_READY:
uas_xfer_data(urb, cmnd, SUBMIT_DATA_IN_URB);
break;
case IU_ID_WRITE_READY:
uas_xfer_data(urb, cmnd, SUBMIT_DATA_OUT_URB);
break;
default:
scmd_printk(KERN_ERR, cmnd,
"Bogus IU (%d) received on status pipe\n", iu->iu_id);
}
usb_free_urb(urb);
spin_unlock_irqrestore(&devinfo->lock, flags);
}
static void uas_data_cmplt(struct urb *urb)
{
struct scsi_cmnd *cmnd = urb->context;
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
struct uas_dev_info *devinfo = (void *)cmnd->device->hostdata;
struct scsi_data_buffer *sdb = NULL;
unsigned long flags;
spin_lock_irqsave(&devinfo->lock, flags);
if (cmdinfo->data_in_urb == urb) {
sdb = scsi_in(cmnd);
cmdinfo->state &= ~DATA_IN_URB_INFLIGHT;
} else if (cmdinfo->data_out_urb == urb) {
sdb = scsi_out(cmnd);
cmdinfo->state &= ~DATA_OUT_URB_INFLIGHT;
}
BUG_ON(sdb == NULL);
if (urb->status) {
sdb->resid = sdb->length;
} else {
sdb->resid = sdb->length - urb->actual_length;
}
uas_try_complete(cmnd, __func__);
spin_unlock_irqrestore(&devinfo->lock, flags);
}
static struct urb *uas_alloc_data_urb(struct uas_dev_info *devinfo, gfp_t gfp,
unsigned int pipe, u16 stream_id,
struct scsi_cmnd *cmnd,
enum dma_data_direction dir)
{
struct usb_device *udev = devinfo->udev;
struct urb *urb = usb_alloc_urb(0, gfp);
struct scsi_data_buffer *sdb = (dir == DMA_FROM_DEVICE)
? scsi_in(cmnd) : scsi_out(cmnd);
if (!urb)
goto out;
usb_fill_bulk_urb(urb, udev, pipe, NULL, sdb->length,
uas_data_cmplt, cmnd);
if (devinfo->use_streams)
urb->stream_id = stream_id;
urb->num_sgs = udev->bus->sg_tablesize ? sdb->table.nents : 0;
urb->sg = sdb->table.sgl;
out:
return urb;
}
static struct urb *uas_alloc_sense_urb(struct uas_dev_info *devinfo, gfp_t gfp,
struct Scsi_Host *shost, u16 stream_id)
{
struct usb_device *udev = devinfo->udev;
struct urb *urb = usb_alloc_urb(0, gfp);
struct sense_iu *iu;
if (!urb)
goto out;
iu = kzalloc(sizeof(*iu), gfp);
if (!iu)
goto free;
usb_fill_bulk_urb(urb, udev, devinfo->status_pipe, iu, sizeof(*iu),
uas_stat_cmplt, shost);
urb->stream_id = stream_id;
urb->transfer_flags |= URB_FREE_BUFFER;
out:
return urb;
free:
usb_free_urb(urb);
return NULL;
}
static struct urb *uas_alloc_cmd_urb(struct uas_dev_info *devinfo, gfp_t gfp,
struct scsi_cmnd *cmnd, u16 stream_id)
{
struct usb_device *udev = devinfo->udev;
struct scsi_device *sdev = cmnd->device;
struct urb *urb = usb_alloc_urb(0, gfp);
struct command_iu *iu;
int len;
if (!urb)
goto out;
len = cmnd->cmd_len - 16;
if (len < 0)
len = 0;
len = ALIGN(len, 4);
iu = kzalloc(sizeof(*iu) + len, gfp);
if (!iu)
goto free;
iu->iu_id = IU_ID_COMMAND;
if (blk_rq_tagged(cmnd->request))
iu->tag = cpu_to_be16(cmnd->request->tag + 2);
else
iu->tag = cpu_to_be16(1);
iu->prio_attr = UAS_SIMPLE_TAG;
iu->len = len;
int_to_scsilun(sdev->lun, &iu->lun);
memcpy(iu->cdb, cmnd->cmnd, cmnd->cmd_len);
usb_fill_bulk_urb(urb, udev, devinfo->cmd_pipe, iu, sizeof(*iu) + len,
usb_free_urb, NULL);
urb->transfer_flags |= URB_FREE_BUFFER;
out:
return urb;
free:
usb_free_urb(urb);
return NULL;
}
static int uas_submit_task_urb(struct scsi_cmnd *cmnd, gfp_t gfp,
u8 function, u16 stream_id)
{
struct uas_dev_info *devinfo = (void *)cmnd->device->hostdata;
struct usb_device *udev = devinfo->udev;
struct urb *urb = usb_alloc_urb(0, gfp);
struct task_mgmt_iu *iu;
int err = -ENOMEM;
if (!urb)
goto err;
iu = kzalloc(sizeof(*iu), gfp);
if (!iu)
goto err;
iu->iu_id = IU_ID_TASK_MGMT;
iu->tag = cpu_to_be16(stream_id);
int_to_scsilun(cmnd->device->lun, &iu->lun);
iu->function = function;
switch (function) {
case TMF_ABORT_TASK:
if (blk_rq_tagged(cmnd->request))
iu->task_tag = cpu_to_be16(cmnd->request->tag + 2);
else
iu->task_tag = cpu_to_be16(1);
break;
}
usb_fill_bulk_urb(urb, udev, devinfo->cmd_pipe, iu, sizeof(*iu),
usb_free_urb, NULL);
urb->transfer_flags |= URB_FREE_BUFFER;
err = usb_submit_urb(urb, gfp);
if (err)
goto err;
usb_anchor_urb(urb, &devinfo->cmd_urbs);
return 0;
err:
usb_free_urb(urb);
return err;
}
static int uas_submit_sense_urb(struct Scsi_Host *shost,
gfp_t gfp, unsigned int stream)
{
struct uas_dev_info *devinfo = (void *)shost->hostdata[0];
struct urb *urb;
urb = uas_alloc_sense_urb(devinfo, gfp, shost, stream);
if (!urb)
return SCSI_MLQUEUE_DEVICE_BUSY;
if (usb_submit_urb(urb, gfp)) {
shost_printk(KERN_INFO, shost,
"sense urb submission failure\n");
usb_free_urb(urb);
return SCSI_MLQUEUE_DEVICE_BUSY;
}
usb_anchor_urb(urb, &devinfo->sense_urbs);
return 0;
}
static int uas_submit_urbs(struct scsi_cmnd *cmnd,
struct uas_dev_info *devinfo, gfp_t gfp)
{
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
int err;
WARN_ON(!spin_is_locked(&devinfo->lock));
if (cmdinfo->state & SUBMIT_STATUS_URB) {
err = uas_submit_sense_urb(cmnd->device->host, gfp,
cmdinfo->stream);
if (err) {
return err;
}
cmdinfo->state &= ~SUBMIT_STATUS_URB;
}
if (cmdinfo->state & ALLOC_DATA_IN_URB) {
cmdinfo->data_in_urb = uas_alloc_data_urb(devinfo, gfp,
devinfo->data_in_pipe, cmdinfo->stream,
cmnd, DMA_FROM_DEVICE);
if (!cmdinfo->data_in_urb)
return SCSI_MLQUEUE_DEVICE_BUSY;
cmdinfo->state &= ~ALLOC_DATA_IN_URB;
}
if (cmdinfo->state & SUBMIT_DATA_IN_URB) {
if (usb_submit_urb(cmdinfo->data_in_urb, gfp)) {
scmd_printk(KERN_INFO, cmnd,
"data in urb submission failure\n");
return SCSI_MLQUEUE_DEVICE_BUSY;
}
cmdinfo->state &= ~SUBMIT_DATA_IN_URB;
cmdinfo->state |= DATA_IN_URB_INFLIGHT;
usb_anchor_urb(cmdinfo->data_in_urb, &devinfo->data_urbs);
}
if (cmdinfo->state & ALLOC_DATA_OUT_URB) {
cmdinfo->data_out_urb = uas_alloc_data_urb(devinfo, gfp,
devinfo->data_out_pipe, cmdinfo->stream,
cmnd, DMA_TO_DEVICE);
if (!cmdinfo->data_out_urb)
return SCSI_MLQUEUE_DEVICE_BUSY;
cmdinfo->state &= ~ALLOC_DATA_OUT_URB;
}
if (cmdinfo->state & SUBMIT_DATA_OUT_URB) {
if (usb_submit_urb(cmdinfo->data_out_urb, gfp)) {
scmd_printk(KERN_INFO, cmnd,
"data out urb submission failure\n");
return SCSI_MLQUEUE_DEVICE_BUSY;
}
cmdinfo->state &= ~SUBMIT_DATA_OUT_URB;
cmdinfo->state |= DATA_OUT_URB_INFLIGHT;
usb_anchor_urb(cmdinfo->data_out_urb, &devinfo->data_urbs);
}
if (cmdinfo->state & ALLOC_CMD_URB) {
cmdinfo->cmd_urb = uas_alloc_cmd_urb(devinfo, gfp, cmnd,
cmdinfo->stream);
if (!cmdinfo->cmd_urb)
return SCSI_MLQUEUE_DEVICE_BUSY;
cmdinfo->state &= ~ALLOC_CMD_URB;
}
if (cmdinfo->state & SUBMIT_CMD_URB) {
usb_get_urb(cmdinfo->cmd_urb);
if (usb_submit_urb(cmdinfo->cmd_urb, gfp)) {
scmd_printk(KERN_INFO, cmnd,
"cmd urb submission failure\n");
return SCSI_MLQUEUE_DEVICE_BUSY;
}
usb_anchor_urb(cmdinfo->cmd_urb, &devinfo->cmd_urbs);
usb_put_urb(cmdinfo->cmd_urb);
cmdinfo->cmd_urb = NULL;
cmdinfo->state &= ~SUBMIT_CMD_URB;
cmdinfo->state |= COMMAND_INFLIGHT;
}
return 0;
}
static int uas_queuecommand_lck(struct scsi_cmnd *cmnd,
void (*done)(struct scsi_cmnd *))
{
struct scsi_device *sdev = cmnd->device;
struct uas_dev_info *devinfo = sdev->hostdata;
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
unsigned long flags;
int err;
BUILD_BUG_ON(sizeof(struct uas_cmd_info) > sizeof(struct scsi_pointer));
spin_lock_irqsave(&devinfo->lock, flags);
if (devinfo->cmnd) {
spin_unlock_irqrestore(&devinfo->lock, flags);
return SCSI_MLQUEUE_DEVICE_BUSY;
}
if (blk_rq_tagged(cmnd->request)) {
cmdinfo->stream = cmnd->request->tag + 2;
} else {
devinfo->cmnd = cmnd;
cmdinfo->stream = 1;
}
cmnd->scsi_done = done;
cmdinfo->state = SUBMIT_STATUS_URB |
ALLOC_CMD_URB | SUBMIT_CMD_URB;
switch (cmnd->sc_data_direction) {
case DMA_FROM_DEVICE:
cmdinfo->state |= ALLOC_DATA_IN_URB | SUBMIT_DATA_IN_URB;
break;
case DMA_BIDIRECTIONAL:
cmdinfo->state |= ALLOC_DATA_IN_URB | SUBMIT_DATA_IN_URB;
case DMA_TO_DEVICE:
cmdinfo->state |= ALLOC_DATA_OUT_URB | SUBMIT_DATA_OUT_URB;
case DMA_NONE:
break;
}
if (!devinfo->use_streams) {
cmdinfo->state &= ~(SUBMIT_DATA_IN_URB | SUBMIT_DATA_OUT_URB);
cmdinfo->stream = 0;
}
err = uas_submit_urbs(cmnd, devinfo, GFP_ATOMIC);
if (err) {
if (cmdinfo->state & SUBMIT_STATUS_URB) {
spin_unlock_irqrestore(&devinfo->lock, flags);
return SCSI_MLQUEUE_DEVICE_BUSY;
}
spin_lock(&uas_work_lock);
list_add_tail(&cmdinfo->list, &uas_work_list);
spin_unlock(&uas_work_lock);
schedule_work(&uas_work);
}
spin_unlock_irqrestore(&devinfo->lock, flags);
return 0;
}
int uas_eh_abort_handler(struct scsi_cmnd *cmnd)
{
struct uas_cmd_info *cmdinfo = (void *)&cmnd->SCp;
struct uas_dev_info *devinfo = (void *)cmnd->device->hostdata;
unsigned long flags;
int ret;
uas_log_cmd_state(cmnd, __func__);
spin_lock_irqsave(&devinfo->lock, flags);
cmdinfo->state |= COMMAND_ABORTED;
spin_unlock_irqrestore(&devinfo->lock, flags);
ret = uas_eh_task_mgmt(cmnd, "ABORT TASK", TMF_ABORT_TASK);
return ret;
}
static int uas_eh_device_reset_handler(struct scsi_cmnd *cmnd)
{
sdev_printk(KERN_INFO, cmnd->device, "%s\n", __func__);
return uas_eh_task_mgmt(cmnd, "LOGICAL UNIT RESET",
TMF_LOGICAL_UNIT_RESET);
}
static int uas_eh_bus_reset_handler(struct scsi_cmnd *cmnd)
{
struct scsi_device *sdev = cmnd->device;
struct uas_dev_info *devinfo = sdev->hostdata;
struct usb_device *udev = devinfo->udev;
int err;
devinfo->resetting = 1;
usb_kill_anchored_urbs(&devinfo->cmd_urbs);
usb_kill_anchored_urbs(&devinfo->sense_urbs);
usb_kill_anchored_urbs(&devinfo->data_urbs);
err = usb_reset_device(udev);
devinfo->resetting = 0;
if (err) {
shost_printk(KERN_INFO, sdev->host, "%s FAILED\n", __func__);
return FAILED;
}
shost_printk(KERN_INFO, sdev->host, "%s success\n", __func__);
return SUCCESS;
}
static int uas_slave_alloc(struct scsi_device *sdev)
{
sdev->hostdata = (void *)sdev->host->hostdata[0];
return 0;
}
static int uas_slave_configure(struct scsi_device *sdev)
{
struct uas_dev_info *devinfo = sdev->hostdata;
scsi_set_tag_type(sdev, MSG_ORDERED_TAG);
scsi_activate_tcq(sdev, devinfo->qdepth - 3);
return 0;
}
static int uas_is_interface(struct usb_host_interface *intf)
{
return (intf->desc.bInterfaceClass == USB_CLASS_MASS_STORAGE &&
intf->desc.bInterfaceSubClass == USB_SC_SCSI &&
intf->desc.bInterfaceProtocol == USB_PR_UAS);
}
static int uas_isnt_supported(struct usb_device *udev)
{
struct usb_hcd *hcd = bus_to_hcd(udev->bus);
dev_warn(&udev->dev, "The driver for the USB controller %s does not "
"support scatter-gather which is\n",
hcd->driver->description);
dev_warn(&udev->dev, "required by the UAS driver. Please try an"
"alternative USB controller if you wish to use UAS.\n");
return -ENODEV;
}
static int uas_switch_interface(struct usb_device *udev,
struct usb_interface *intf)
{
int i;
int sg_supported = udev->bus->sg_tablesize != 0;
for (i = 0; i < intf->num_altsetting; i++) {
struct usb_host_interface *alt = &intf->altsetting[i];
if (uas_is_interface(alt)) {
if (!sg_supported)
return uas_isnt_supported(udev);
return usb_set_interface(udev,
alt->desc.bInterfaceNumber,
alt->desc.bAlternateSetting);
}
}
return -ENODEV;
}
static void uas_configure_endpoints(struct uas_dev_info *devinfo)
{
struct usb_host_endpoint *eps[4] = { };
struct usb_interface *intf = devinfo->intf;
struct usb_device *udev = devinfo->udev;
struct usb_host_endpoint *endpoint = intf->cur_altsetting->endpoint;
unsigned i, n_endpoints = intf->cur_altsetting->desc.bNumEndpoints;
devinfo->uas_sense_old = 0;
devinfo->cmnd = NULL;
for (i = 0; i < n_endpoints; i++) {
unsigned char *extra = endpoint[i].extra;
int len = endpoint[i].extralen;
while (len > 1) {
if (extra[1] == USB_DT_PIPE_USAGE) {
unsigned pipe_id = extra[2];
if (pipe_id > 0 && pipe_id < 5)
eps[pipe_id - 1] = &endpoint[i];
break;
}
len -= extra[0];
extra += extra[0];
}
}
if (!eps[0]) {
devinfo->cmd_pipe = usb_sndbulkpipe(udev, 1);
devinfo->status_pipe = usb_rcvbulkpipe(udev, 1);
devinfo->data_in_pipe = usb_rcvbulkpipe(udev, 2);
devinfo->data_out_pipe = usb_sndbulkpipe(udev, 2);
eps[1] = usb_pipe_endpoint(udev, devinfo->status_pipe);
eps[2] = usb_pipe_endpoint(udev, devinfo->data_in_pipe);
eps[3] = usb_pipe_endpoint(udev, devinfo->data_out_pipe);
} else {
devinfo->cmd_pipe = usb_sndbulkpipe(udev,
eps[0]->desc.bEndpointAddress);
devinfo->status_pipe = usb_rcvbulkpipe(udev,
eps[1]->desc.bEndpointAddress);
devinfo->data_in_pipe = usb_rcvbulkpipe(udev,
eps[2]->desc.bEndpointAddress);
devinfo->data_out_pipe = usb_sndbulkpipe(udev,
eps[3]->desc.bEndpointAddress);
}
devinfo->qdepth = usb_alloc_streams(devinfo->intf, eps + 1, 3, 256,
GFP_KERNEL);
if (devinfo->qdepth < 0) {
devinfo->qdepth = 256;
devinfo->use_streams = 0;
} else {
devinfo->use_streams = 1;
}
}
static void uas_free_streams(struct uas_dev_info *devinfo)
{
struct usb_device *udev = devinfo->udev;
struct usb_host_endpoint *eps[3];
eps[0] = usb_pipe_endpoint(udev, devinfo->status_pipe);
eps[1] = usb_pipe_endpoint(udev, devinfo->data_in_pipe);
eps[2] = usb_pipe_endpoint(udev, devinfo->data_out_pipe);
usb_free_streams(devinfo->intf, eps, 3, GFP_KERNEL);
}
static int uas_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
int result;
struct Scsi_Host *shost;
struct uas_dev_info *devinfo;
struct usb_device *udev = interface_to_usbdev(intf);
if (uas_switch_interface(udev, intf))
return -ENODEV;
devinfo = kmalloc(sizeof(struct uas_dev_info), GFP_KERNEL);
if (!devinfo)
return -ENOMEM;
result = -ENOMEM;
shost = scsi_host_alloc(&uas_host_template, sizeof(void *));
if (!shost)
goto free;
shost->max_cmd_len = 16 + 252;
shost->max_id = 1;
shost->sg_tablesize = udev->bus->sg_tablesize;
devinfo->intf = intf;
devinfo->udev = udev;
devinfo->resetting = 0;
init_usb_anchor(&devinfo->cmd_urbs);
init_usb_anchor(&devinfo->sense_urbs);
init_usb_anchor(&devinfo->data_urbs);
spin_lock_init(&devinfo->lock);
uas_configure_endpoints(devinfo);
result = scsi_init_shared_tag_map(shost, devinfo->qdepth - 3);
if (result)
goto free;
result = scsi_add_host(shost, &intf->dev);
if (result)
goto deconfig_eps;
shost->hostdata[0] = (unsigned long)devinfo;
scsi_scan_host(shost);
usb_set_intfdata(intf, shost);
return result;
deconfig_eps:
uas_free_streams(devinfo);
free:
kfree(devinfo);
if (shost)
scsi_host_put(shost);
return result;
}
static int uas_pre_reset(struct usb_interface *intf)
{
return 0;
}
static int uas_post_reset(struct usb_interface *intf)
{
return 0;
}
static void uas_disconnect(struct usb_interface *intf)
{
struct Scsi_Host *shost = usb_get_intfdata(intf);
struct uas_dev_info *devinfo = (void *)shost->hostdata[0];
scsi_remove_host(shost);
usb_kill_anchored_urbs(&devinfo->cmd_urbs);
usb_kill_anchored_urbs(&devinfo->sense_urbs);
usb_kill_anchored_urbs(&devinfo->data_urbs);
uas_free_streams(devinfo);
kfree(devinfo);
}
