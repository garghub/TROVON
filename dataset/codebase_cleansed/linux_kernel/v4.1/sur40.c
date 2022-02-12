static int sur40_command(struct sur40_state *dev,
u8 command, u16 index, void *buffer, u16 size)
{
return usb_control_msg(dev->usbdev, usb_rcvctrlpipe(dev->usbdev, 0),
command,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x00, index, buffer, size, 1000);
}
static int sur40_init(struct sur40_state *dev)
{
int result;
u8 buffer[24];
result = sur40_command(dev, SUR40_GET_VERSION, 0x00, buffer, 12);
if (result < 0)
return result;
result = sur40_command(dev, SUR40_GET_VERSION, 0x01, buffer, 12);
if (result < 0)
return result;
result = sur40_command(dev, SUR40_GET_VERSION, 0x02, buffer, 12);
if (result < 0)
return result;
result = sur40_command(dev, SUR40_UNKNOWN2, 0x00, buffer, 24);
if (result < 0)
return result;
result = sur40_command(dev, SUR40_UNKNOWN1, 0x00, buffer, 5);
if (result < 0)
return result;
result = sur40_command(dev, SUR40_GET_VERSION, 0x03, buffer, 12);
return result;
}
static void sur40_open(struct input_polled_dev *polldev)
{
struct sur40_state *sur40 = polldev->private;
dev_dbg(sur40->dev, "open\n");
sur40_init(sur40);
}
static void sur40_close(struct input_polled_dev *polldev)
{
struct sur40_state *sur40 = polldev->private;
dev_dbg(sur40->dev, "close\n");
}
static void sur40_report_blob(struct sur40_blob *blob, struct input_dev *input)
{
int wide, major, minor;
int bb_size_x = le16_to_cpu(blob->bb_size_x);
int bb_size_y = le16_to_cpu(blob->bb_size_y);
int pos_x = le16_to_cpu(blob->pos_x);
int pos_y = le16_to_cpu(blob->pos_y);
int ctr_x = le16_to_cpu(blob->ctr_x);
int ctr_y = le16_to_cpu(blob->ctr_y);
int slotnum = input_mt_get_slot_by_key(input, blob->blob_id);
if (slotnum < 0 || slotnum >= MAX_CONTACTS)
return;
input_mt_slot(input, slotnum);
input_mt_report_slot_state(input, MT_TOOL_FINGER, 1);
wide = (bb_size_x > bb_size_y);
major = max(bb_size_x, bb_size_y);
minor = min(bb_size_x, bb_size_y);
input_report_abs(input, ABS_MT_POSITION_X, pos_x);
input_report_abs(input, ABS_MT_POSITION_Y, pos_y);
input_report_abs(input, ABS_MT_TOOL_X, ctr_x);
input_report_abs(input, ABS_MT_TOOL_Y, ctr_y);
input_report_abs(input, ABS_MT_ORIENTATION, wide);
input_report_abs(input, ABS_MT_TOUCH_MAJOR, major);
input_report_abs(input, ABS_MT_TOUCH_MINOR, minor);
}
static void sur40_poll(struct input_polled_dev *polldev)
{
struct sur40_state *sur40 = polldev->private;
struct input_dev *input = polldev->input;
int result, bulk_read, need_blobs, packet_blobs, i;
u32 uninitialized_var(packet_id);
struct sur40_header *header = &sur40->bulk_in_buffer->header;
struct sur40_blob *inblob = &sur40->bulk_in_buffer->blobs[0];
dev_dbg(sur40->dev, "poll\n");
need_blobs = -1;
do {
result = usb_bulk_msg(sur40->usbdev,
usb_rcvbulkpipe(sur40->usbdev, sur40->bulk_in_epaddr),
sur40->bulk_in_buffer, sur40->bulk_in_size,
&bulk_read, 1000);
dev_dbg(sur40->dev, "received %d bytes\n", bulk_read);
if (result < 0) {
dev_err(sur40->dev, "error in usb_bulk_read\n");
return;
}
result = bulk_read - sizeof(struct sur40_header);
if (result % sizeof(struct sur40_blob) != 0) {
dev_err(sur40->dev, "transfer size mismatch\n");
return;
}
if (need_blobs == -1) {
need_blobs = le16_to_cpu(header->count);
dev_dbg(sur40->dev, "need %d blobs\n", need_blobs);
packet_id = le32_to_cpu(header->packet_id);
}
if (packet_id != header->packet_id)
dev_warn(sur40->dev, "packet ID mismatch\n");
packet_blobs = result / sizeof(struct sur40_blob);
dev_dbg(sur40->dev, "received %d blobs\n", packet_blobs);
if (packet_blobs > need_blobs)
packet_blobs = need_blobs;
for (i = 0; i < packet_blobs; i++) {
need_blobs--;
dev_dbg(sur40->dev, "processing blob\n");
sur40_report_blob(&(inblob[i]), input);
}
} while (need_blobs > 0);
input_mt_sync_frame(input);
input_sync(input);
sur40_process_video(sur40);
}
static void sur40_process_video(struct sur40_state *sur40)
{
struct sur40_image_header *img = (void *)(sur40->bulk_in_buffer);
struct sur40_buffer *new_buf;
struct usb_sg_request sgr;
struct sg_table *sgt;
int result, bulk_read;
if (!vb2_start_streaming_called(&sur40->queue))
return;
spin_lock(&sur40->qlock);
if (list_empty(&sur40->buf_list)) {
dev_dbg(sur40->dev, "buffer queue empty\n");
spin_unlock(&sur40->qlock);
return;
}
new_buf = list_entry(sur40->buf_list.next, struct sur40_buffer, list);
list_del(&new_buf->list);
spin_unlock(&sur40->qlock);
result = usb_bulk_msg(sur40->usbdev,
usb_rcvbulkpipe(sur40->usbdev, VIDEO_ENDPOINT),
sur40->bulk_in_buffer, sur40->bulk_in_size,
&bulk_read, 1000);
if (result < 0) {
dev_err(sur40->dev, "error in usb_bulk_read\n");
goto err_poll;
}
if (bulk_read != sizeof(struct sur40_image_header)) {
dev_err(sur40->dev, "received %d bytes (%zd expected)\n",
bulk_read, sizeof(struct sur40_image_header));
goto err_poll;
}
if (le32_to_cpu(img->magic) != VIDEO_HEADER_MAGIC) {
dev_err(sur40->dev, "image magic mismatch\n");
goto err_poll;
}
if (le32_to_cpu(img->size) != sur40_video_format.sizeimage) {
dev_err(sur40->dev, "image size mismatch\n");
goto err_poll;
}
sgt = vb2_dma_sg_plane_desc(&new_buf->vb, 0);
result = usb_sg_init(&sgr, sur40->usbdev,
usb_rcvbulkpipe(sur40->usbdev, VIDEO_ENDPOINT), 0,
sgt->sgl, sgt->nents, sur40_video_format.sizeimage, 0);
if (result < 0) {
dev_err(sur40->dev, "error %d in usb_sg_init\n", result);
goto err_poll;
}
usb_sg_wait(&sgr);
if (sgr.status < 0) {
dev_err(sur40->dev, "error %d in usb_sg_wait\n", sgr.status);
goto err_poll;
}
v4l2_get_timestamp(&new_buf->vb.v4l2_buf.timestamp);
new_buf->vb.v4l2_buf.sequence = sur40->sequence++;
new_buf->vb.v4l2_buf.field = V4L2_FIELD_NONE;
vb2_buffer_done(&new_buf->vb, VB2_BUF_STATE_DONE);
return;
err_poll:
vb2_buffer_done(&new_buf->vb, VB2_BUF_STATE_ERROR);
}
static void sur40_input_setup(struct input_dev *input_dev)
{
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_MT_POSITION_X,
0, SENSOR_RES_X, 0, 0);
input_set_abs_params(input_dev, ABS_MT_POSITION_Y,
0, SENSOR_RES_Y, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOOL_X,
0, SENSOR_RES_X, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOOL_Y,
0, SENSOR_RES_Y, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MAJOR,
0, SENSOR_RES_X, 0, 0);
input_set_abs_params(input_dev, ABS_MT_TOUCH_MINOR,
0, SENSOR_RES_Y, 0, 0);
input_set_abs_params(input_dev, ABS_MT_ORIENTATION, 0, 1, 0, 0);
input_mt_init_slots(input_dev, MAX_CONTACTS,
INPUT_MT_DIRECT | INPUT_MT_DROP_UNUSED);
}
static int sur40_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev = interface_to_usbdev(interface);
struct sur40_state *sur40;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
struct input_polled_dev *poll_dev;
int error;
iface_desc = &interface->altsetting[0];
if (iface_desc->desc.bInterfaceClass != 0xFF)
return -ENODEV;
endpoint = &iface_desc->endpoint[4].desc;
if (endpoint->bEndpointAddress != TOUCH_ENDPOINT)
return -ENODEV;
sur40 = kzalloc(sizeof(struct sur40_state), GFP_KERNEL);
if (!sur40)
return -ENOMEM;
poll_dev = input_allocate_polled_device();
if (!poll_dev) {
error = -ENOMEM;
goto err_free_dev;
}
INIT_LIST_HEAD(&sur40->buf_list);
spin_lock_init(&sur40->qlock);
mutex_init(&sur40->lock);
poll_dev->private = sur40;
poll_dev->poll_interval = POLL_INTERVAL;
poll_dev->open = sur40_open;
poll_dev->poll = sur40_poll;
poll_dev->close = sur40_close;
sur40_input_setup(poll_dev->input);
poll_dev->input->name = DRIVER_LONG;
usb_to_input_id(usbdev, &poll_dev->input->id);
usb_make_path(usbdev, sur40->phys, sizeof(sur40->phys));
strlcat(sur40->phys, "/input0", sizeof(sur40->phys));
poll_dev->input->phys = sur40->phys;
poll_dev->input->dev.parent = &interface->dev;
sur40->usbdev = usbdev;
sur40->dev = &interface->dev;
sur40->input = poll_dev;
sur40->bulk_in_size = usb_endpoint_maxp(endpoint);
sur40->bulk_in_epaddr = endpoint->bEndpointAddress;
sur40->bulk_in_buffer = kmalloc(sur40->bulk_in_size, GFP_KERNEL);
if (!sur40->bulk_in_buffer) {
dev_err(&interface->dev, "Unable to allocate input buffer.");
error = -ENOMEM;
goto err_free_polldev;
}
error = input_register_polled_device(poll_dev);
if (error) {
dev_err(&interface->dev,
"Unable to register polled input device.");
goto err_free_buffer;
}
snprintf(sur40->v4l2.name, sizeof(sur40->v4l2.name), "%s", DRIVER_LONG);
error = v4l2_device_register(sur40->dev, &sur40->v4l2);
if (error) {
dev_err(&interface->dev,
"Unable to register video master device.");
goto err_unreg_v4l2;
}
sur40->queue = sur40_queue;
sur40->queue.drv_priv = sur40;
sur40->queue.lock = &sur40->lock;
error = vb2_queue_init(&sur40->queue);
if (error)
goto err_unreg_v4l2;
sur40->alloc_ctx = vb2_dma_sg_init_ctx(sur40->dev);
if (IS_ERR(sur40->alloc_ctx)) {
dev_err(sur40->dev, "Can't allocate buffer context");
goto err_unreg_v4l2;
}
sur40->vdev = sur40_video_device;
sur40->vdev.v4l2_dev = &sur40->v4l2;
sur40->vdev.lock = &sur40->lock;
sur40->vdev.queue = &sur40->queue;
video_set_drvdata(&sur40->vdev, sur40);
error = video_register_device(&sur40->vdev, VFL_TYPE_GRABBER, -1);
if (error) {
dev_err(&interface->dev,
"Unable to register video subdevice.");
goto err_unreg_video;
}
usb_set_intfdata(interface, sur40);
dev_dbg(&interface->dev, "%s is now attached\n", DRIVER_DESC);
return 0;
err_unreg_video:
video_unregister_device(&sur40->vdev);
err_unreg_v4l2:
v4l2_device_unregister(&sur40->v4l2);
err_free_buffer:
kfree(sur40->bulk_in_buffer);
err_free_polldev:
input_free_polled_device(sur40->input);
err_free_dev:
kfree(sur40);
return error;
}
static void sur40_disconnect(struct usb_interface *interface)
{
struct sur40_state *sur40 = usb_get_intfdata(interface);
video_unregister_device(&sur40->vdev);
v4l2_device_unregister(&sur40->v4l2);
vb2_dma_sg_cleanup_ctx(sur40->alloc_ctx);
input_unregister_polled_device(sur40->input);
input_free_polled_device(sur40->input);
kfree(sur40->bulk_in_buffer);
kfree(sur40);
usb_set_intfdata(interface, NULL);
dev_dbg(&interface->dev, "%s is now disconnected\n", DRIVER_DESC);
}
static int sur40_queue_setup(struct vb2_queue *q, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct sur40_state *sur40 = vb2_get_drv_priv(q);
if (q->num_buffers + *nbuffers < 3)
*nbuffers = 3 - q->num_buffers;
if (fmt && fmt->fmt.pix.sizeimage < sur40_video_format.sizeimage)
return -EINVAL;
*nplanes = 1;
sizes[0] = fmt ? fmt->fmt.pix.sizeimage : sur40_video_format.sizeimage;
alloc_ctxs[0] = sur40->alloc_ctx;
return 0;
}
static int sur40_buffer_prepare(struct vb2_buffer *vb)
{
struct sur40_state *sur40 = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size = sur40_video_format.sizeimage;
if (vb2_plane_size(vb, 0) < size) {
dev_err(&sur40->usbdev->dev, "buffer too small (%lu < %lu)\n",
vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
return 0;
}
static void sur40_buffer_queue(struct vb2_buffer *vb)
{
struct sur40_state *sur40 = vb2_get_drv_priv(vb->vb2_queue);
struct sur40_buffer *buf = (struct sur40_buffer *)vb;
spin_lock(&sur40->qlock);
list_add_tail(&buf->list, &sur40->buf_list);
spin_unlock(&sur40->qlock);
}
static void return_all_buffers(struct sur40_state *sur40,
enum vb2_buffer_state state)
{
struct sur40_buffer *buf, *node;
spin_lock(&sur40->qlock);
list_for_each_entry_safe(buf, node, &sur40->buf_list, list) {
vb2_buffer_done(&buf->vb, state);
list_del(&buf->list);
}
spin_unlock(&sur40->qlock);
}
static int sur40_start_streaming(struct vb2_queue *vq, unsigned int count)
{
struct sur40_state *sur40 = vb2_get_drv_priv(vq);
sur40->sequence = 0;
return 0;
}
static void sur40_stop_streaming(struct vb2_queue *vq)
{
struct sur40_state *sur40 = vb2_get_drv_priv(vq);
return_all_buffers(sur40, VB2_BUF_STATE_ERROR);
}
static int sur40_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct sur40_state *sur40 = video_drvdata(file);
strlcpy(cap->driver, DRIVER_SHORT, sizeof(cap->driver));
strlcpy(cap->card, DRIVER_LONG, sizeof(cap->card));
usb_make_path(sur40->usbdev, cap->bus_info, sizeof(cap->bus_info));
cap->device_caps = V4L2_CAP_VIDEO_CAPTURE |
V4L2_CAP_READWRITE |
V4L2_CAP_STREAMING;
cap->capabilities = cap->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int sur40_vidioc_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
if (i->index != 0)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
i->std = V4L2_STD_UNKNOWN;
strlcpy(i->name, "In-Cell Sensor", sizeof(i->name));
i->capabilities = 0;
return 0;
}
static int sur40_vidioc_s_input(struct file *file, void *priv, unsigned int i)
{
return (i == 0) ? 0 : -EINVAL;
}
static int sur40_vidioc_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int sur40_vidioc_fmt(struct file *file, void *priv,
struct v4l2_format *f)
{
f->fmt.pix = sur40_video_format;
return 0;
}
static int sur40_vidioc_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index != 0)
return -EINVAL;
strlcpy(f->description, "8-bit greyscale", sizeof(f->description));
f->pixelformat = V4L2_PIX_FMT_GREY;
f->flags = 0;
return 0;
}
