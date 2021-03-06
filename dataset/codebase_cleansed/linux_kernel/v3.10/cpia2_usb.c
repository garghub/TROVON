static void process_frame(struct camera_data *cam)
{
static int frame_count;
unsigned char *inbuff = cam->workbuff->data;
DBG("Processing frame #%d, current:%d\n",
cam->workbuff->num, cam->curbuff->num);
if(cam->workbuff->length > cam->workbuff->max_length)
cam->workbuff->max_length = cam->workbuff->length;
if ((inbuff[0] == 0xFF) && (inbuff[1] == 0xD8)) {
frame_count++;
} else {
cam->workbuff->status = FRAME_ERROR;
DBG("Start of frame not found\n");
return;
}
if(!cam->first_image_seen) {
cam->first_image_seen = 1;
cam->workbuff->status = FRAME_EMPTY;
return;
}
if (cam->workbuff->length > 3) {
if(cam->mmapped &&
cam->workbuff->length < cam->workbuff->max_length) {
memset(cam->workbuff->data+cam->workbuff->length,
0, cam->workbuff->max_length-
cam->workbuff->length);
}
cam->workbuff->max_length = cam->workbuff->length;
cam->workbuff->status = FRAME_READY;
if(!cam->mmapped && cam->num_frames > 2) {
cam->curbuff->status = FRAME_EMPTY;
}
cam->curbuff = cam->workbuff;
cam->workbuff = cam->workbuff->next;
DBG("Changed buffers, work:%d, current:%d\n",
cam->workbuff->num, cam->curbuff->num);
return;
} else {
DBG("Not enough data for an image.\n");
}
cam->workbuff->status = FRAME_ERROR;
return;
}
static void add_APPn(struct camera_data *cam)
{
if(cam->APP_len > 0) {
cam->workbuff->data[cam->workbuff->length++] = 0xFF;
cam->workbuff->data[cam->workbuff->length++] = 0xE0+cam->APPn;
cam->workbuff->data[cam->workbuff->length++] = 0;
cam->workbuff->data[cam->workbuff->length++] = cam->APP_len+2;
memcpy(cam->workbuff->data+cam->workbuff->length,
cam->APP_data, cam->APP_len);
cam->workbuff->length += cam->APP_len;
}
}
static void add_COM(struct camera_data *cam)
{
if(cam->COM_len > 0) {
cam->workbuff->data[cam->workbuff->length++] = 0xFF;
cam->workbuff->data[cam->workbuff->length++] = 0xFE;
cam->workbuff->data[cam->workbuff->length++] = 0;
cam->workbuff->data[cam->workbuff->length++] = cam->COM_len+2;
memcpy(cam->workbuff->data+cam->workbuff->length,
cam->COM_data, cam->COM_len);
cam->workbuff->length += cam->COM_len;
}
}
static void cpia2_usb_complete(struct urb *urb)
{
int i;
unsigned char *cdata;
static int frame_ready = false;
struct camera_data *cam = (struct camera_data *) urb->context;
if (urb->status!=0) {
if (!(urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN))
{
DBG("urb->status = %d!\n", urb->status);
}
DBG("Stopping streaming\n");
return;
}
if (!cam->streaming || !video_is_registered(&cam->vdev)) {
LOG("Will now stop the streaming: streaming = %d, present=%d\n",
cam->streaming, video_is_registered(&cam->vdev));
return;
}
for (i = 0; i < urb->number_of_packets; i++) {
u16 checksum, iso_checksum;
int j;
int n = urb->iso_frame_desc[i].actual_length;
int st = urb->iso_frame_desc[i].status;
if(cam->workbuff->status == FRAME_READY) {
struct framebuf *ptr;
DBG("workbuff full, searching\n");
for (ptr = cam->workbuff->next;
ptr != cam->workbuff;
ptr = ptr->next)
{
if (ptr->status == FRAME_EMPTY) {
ptr->status = FRAME_READING;
ptr->length = 0;
break;
}
}
if (ptr == cam->workbuff)
break;
cam->workbuff = ptr;
}
if (cam->workbuff->status == FRAME_EMPTY ||
cam->workbuff->status == FRAME_ERROR) {
cam->workbuff->status = FRAME_READING;
cam->workbuff->length = 0;
}
cdata = urb->transfer_buffer + urb->iso_frame_desc[i].offset;
if (st) {
LOG("cpia2 data error: [%d] len=%d, status = %d\n",
i, n, st);
if(!ALLOW_CORRUPT)
cam->workbuff->status = FRAME_ERROR;
continue;
}
if(n<=2)
continue;
checksum = 0;
for(j=0; j<n-2; ++j)
checksum += cdata[j];
iso_checksum = cdata[j] + cdata[j+1]*256;
if(checksum != iso_checksum) {
LOG("checksum mismatch: [%d] len=%d, calculated = %x, checksum = %x\n",
i, n, (int)checksum, (int)iso_checksum);
if(!ALLOW_CORRUPT) {
cam->workbuff->status = FRAME_ERROR;
continue;
}
}
n -= 2;
if(cam->workbuff->status != FRAME_READING) {
if((0xFF == cdata[0] && 0xD8 == cdata[1]) ||
(0xD8 == cdata[0] && 0xFF == cdata[1] &&
0 != cdata[2])) {
cam->frame_count++;
}
DBG("workbuff not reading, status=%d\n",
cam->workbuff->status);
continue;
}
if (cam->frame_size < cam->workbuff->length + n) {
ERR("buffer overflow! length: %d, n: %d\n",
cam->workbuff->length, n);
cam->workbuff->status = FRAME_ERROR;
if(cam->workbuff->length > cam->workbuff->max_length)
cam->workbuff->max_length =
cam->workbuff->length;
continue;
}
if (cam->workbuff->length == 0) {
int data_offset;
if ((0xD8 == cdata[0]) && (0xFF == cdata[1])) {
data_offset = 1;
} else if((0xFF == cdata[0]) && (0xD8 == cdata[1])
&& (0xFF == cdata[2])) {
data_offset = 2;
} else {
DBG("Ignoring packet, not beginning!\n");
continue;
}
DBG("Start of frame pattern found\n");
v4l2_get_timestamp(&cam->workbuff->timestamp);
cam->workbuff->seq = cam->frame_count++;
cam->workbuff->data[0] = 0xFF;
cam->workbuff->data[1] = 0xD8;
cam->workbuff->length = 2;
add_APPn(cam);
add_COM(cam);
memcpy(cam->workbuff->data+cam->workbuff->length,
cdata+data_offset, n-data_offset);
cam->workbuff->length += n-data_offset;
} else if (cam->workbuff->length > 0) {
memcpy(cam->workbuff->data + cam->workbuff->length,
cdata, n);
cam->workbuff->length += n;
}
if ((cam->workbuff->length >= 3) &&
(cam->workbuff->data[cam->workbuff->length - 3] == 0xFF) &&
(cam->workbuff->data[cam->workbuff->length - 2] == 0xD9) &&
(cam->workbuff->data[cam->workbuff->length - 1] == 0xFF)) {
frame_ready = true;
cam->workbuff->data[cam->workbuff->length - 1] = 0;
cam->workbuff->length -= 1;
} else if ((cam->workbuff->length >= 2) &&
(cam->workbuff->data[cam->workbuff->length - 2] == 0xFF) &&
(cam->workbuff->data[cam->workbuff->length - 1] == 0xD9)) {
frame_ready = true;
}
if (frame_ready) {
DBG("Workbuff image size = %d\n",cam->workbuff->length);
process_frame(cam);
frame_ready = false;
if (waitqueue_active(&cam->wq_stream))
wake_up_interruptible(&cam->wq_stream);
}
}
if(cam->streaming) {
urb->dev = cam->dev;
if ((i = usb_submit_urb(urb, GFP_ATOMIC)) != 0)
ERR("%s: usb_submit_urb ret %d!\n", __func__, i);
}
}
static int configure_transfer_mode(struct camera_data *cam, unsigned int alt)
{
static unsigned char iso_regs[8][4] = {
{0x00, 0x00, 0x00, 0x00},
{0x00, 0x00, 0x00, 0x00},
{0xB9, 0x00, 0x00, 0x7E},
{0xB9, 0x00, 0x01, 0x7E},
{0xB9, 0x00, 0x02, 0x7E},
{0xB9, 0x00, 0x02, 0xFE},
{0xB9, 0x00, 0x03, 0x7E},
{0xB9, 0x00, 0x03, 0xFD}
};
struct cpia2_command cmd;
unsigned char reg;
if (!video_is_registered(&cam->vdev))
return -ENODEV;
cmd.direction = TRANSFER_WRITE;
cmd.buffer.block_data[0] = iso_regs[alt][0];
cmd.buffer.block_data[1] = iso_regs[alt][1];
cmd.buffer.block_data[2] = iso_regs[alt][2];
cmd.buffer.block_data[3] = iso_regs[alt][3];
cmd.req_mode = CAMERAACCESS_TYPE_BLOCK | CAMERAACCESS_VC;
cmd.start = CPIA2_VC_USB_ISOLIM;
cmd.reg_count = 4;
cpia2_send_command(cam, &cmd);
cmd.direction = TRANSFER_READ;
cmd.req_mode = CAMERAACCESS_TYPE_BLOCK | CAMERAACCESS_VC;
cmd.start = CPIA2_VC_USB_STRM;
cmd.reg_count = 1;
cpia2_send_command(cam, &cmd);
reg = cmd.buffer.block_data[0];
reg &= ~(CPIA2_VC_USB_STRM_BLK_ENABLE |
CPIA2_VC_USB_STRM_ISO_ENABLE |
CPIA2_VC_USB_STRM_INT_ENABLE);
if (alt == USBIF_BULK) {
DBG("Enabling bulk xfer\n");
reg |= CPIA2_VC_USB_STRM_BLK_ENABLE;
cam->xfer_mode = XFER_BULK;
} else if (alt >= USBIF_ISO_1) {
DBG("Enabling ISOC xfer\n");
reg |= CPIA2_VC_USB_STRM_ISO_ENABLE;
cam->xfer_mode = XFER_ISOC;
}
cmd.buffer.block_data[0] = reg;
cmd.direction = TRANSFER_WRITE;
cmd.start = CPIA2_VC_USB_STRM;
cmd.reg_count = 1;
cmd.req_mode = CAMERAACCESS_TYPE_BLOCK | CAMERAACCESS_VC;
cpia2_send_command(cam, &cmd);
return 0;
}
int cpia2_usb_change_streaming_alternate(struct camera_data *cam,
unsigned int alt)
{
int ret = 0;
if(alt < USBIF_ISO_1 || alt > USBIF_ISO_6)
return -EINVAL;
if(alt == cam->params.camera_state.stream_mode)
return 0;
cpia2_usb_stream_pause(cam);
configure_transfer_mode(cam, alt);
cam->params.camera_state.stream_mode = alt;
cpia2_reset_camera(cam);
cpia2_usb_stream_resume(cam);
return ret;
}
static int set_alternate(struct camera_data *cam, unsigned int alt)
{
int ret = 0;
if(alt == cam->cur_alt)
return 0;
if (cam->cur_alt != USBIF_CMDONLY) {
DBG("Changing from alt %d to %d\n", cam->cur_alt, USBIF_CMDONLY);
ret = usb_set_interface(cam->dev, cam->iface, USBIF_CMDONLY);
if (ret != 0)
return ret;
}
if (alt != USBIF_CMDONLY) {
DBG("Changing from alt %d to %d\n", USBIF_CMDONLY, alt);
ret = usb_set_interface(cam->dev, cam->iface, alt);
if (ret != 0)
return ret;
}
cam->old_alt = cam->cur_alt;
cam->cur_alt = alt;
return ret;
}
static void free_sbufs(struct camera_data *cam)
{
int i;
for (i = 0; i < NUM_SBUF; i++) {
if(cam->sbuf[i].urb) {
usb_kill_urb(cam->sbuf[i].urb);
usb_free_urb(cam->sbuf[i].urb);
cam->sbuf[i].urb = NULL;
}
if(cam->sbuf[i].data) {
kfree(cam->sbuf[i].data);
cam->sbuf[i].data = NULL;
}
}
}
static int write_packet(struct usb_device *udev,
u8 request, u8 * registers, u16 start, size_t size)
{
if (!registers || size <= 0)
return -EINVAL;
return usb_control_msg(udev,
usb_sndctrlpipe(udev, 0),
request,
USB_TYPE_VENDOR | USB_RECIP_DEVICE,
start,
0,
registers,
size,
HZ);
}
static int read_packet(struct usb_device *udev,
u8 request, u8 * registers, u16 start, size_t size)
{
if (!registers || size <= 0)
return -EINVAL;
return usb_control_msg(udev,
usb_rcvctrlpipe(udev, 0),
request,
USB_DIR_IN|USB_TYPE_VENDOR|USB_RECIP_DEVICE,
start,
0,
registers,
size,
HZ);
}
int cpia2_usb_transfer_cmd(struct camera_data *cam,
void *registers,
u8 request, u8 start, u8 count, u8 direction)
{
int err = 0;
struct usb_device *udev = cam->dev;
if (!udev) {
ERR("%s: Internal driver error: udev is NULL\n", __func__);
return -EINVAL;
}
if (!registers) {
ERR("%s: Internal driver error: register array is NULL\n", __func__);
return -EINVAL;
}
if (direction == TRANSFER_READ) {
err = read_packet(udev, request, (u8 *)registers, start, count);
if (err > 0)
err = 0;
} else if (direction == TRANSFER_WRITE) {
err =write_packet(udev, request, (u8 *)registers, start, count);
if (err < 0) {
LOG("Control message failed, err val = %d\n", err);
LOG("Message: request = 0x%0X, start = 0x%0X\n",
request, start);
LOG("Message: count = %d, register[0] = 0x%0X\n",
count, ((unsigned char *) registers)[0]);
} else
err=0;
} else {
LOG("Unexpected first byte of direction: %d\n",
direction);
return -EINVAL;
}
if(err != 0)
LOG("Unexpected error: %d\n", err);
return err;
}
static int submit_urbs(struct camera_data *cam)
{
struct urb *urb;
int fx, err, i, j;
for(i=0; i<NUM_SBUF; ++i) {
if (cam->sbuf[i].data)
continue;
cam->sbuf[i].data =
kmalloc(FRAMES_PER_DESC * FRAME_SIZE_PER_DESC, GFP_KERNEL);
if (!cam->sbuf[i].data) {
while (--i >= 0) {
kfree(cam->sbuf[i].data);
cam->sbuf[i].data = NULL;
}
return -ENOMEM;
}
}
for(i=0; i<NUM_SBUF; ++i) {
if(cam->sbuf[i].urb) {
continue;
}
urb = usb_alloc_urb(FRAMES_PER_DESC, GFP_KERNEL);
if (!urb) {
ERR("%s: usb_alloc_urb error!\n", __func__);
for (j = 0; j < i; j++)
usb_free_urb(cam->sbuf[j].urb);
return -ENOMEM;
}
cam->sbuf[i].urb = urb;
urb->dev = cam->dev;
urb->context = cam;
urb->pipe = usb_rcvisocpipe(cam->dev, 1 );
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = cam->sbuf[i].data;
urb->complete = cpia2_usb_complete;
urb->number_of_packets = FRAMES_PER_DESC;
urb->interval = 1;
urb->transfer_buffer_length =
FRAME_SIZE_PER_DESC * FRAMES_PER_DESC;
for (fx = 0; fx < FRAMES_PER_DESC; fx++) {
urb->iso_frame_desc[fx].offset =
FRAME_SIZE_PER_DESC * fx;
urb->iso_frame_desc[fx].length = FRAME_SIZE_PER_DESC;
}
}
for(i=0; i<NUM_SBUF; ++i) {
err = usb_submit_urb(cam->sbuf[i].urb, GFP_KERNEL);
if (err) {
ERR("usb_submit_urb[%d]() = %d\n", i, err);
return err;
}
}
return 0;
}
int cpia2_usb_stream_start(struct camera_data *cam, unsigned int alternate)
{
int ret;
int old_alt;
if(cam->streaming)
return 0;
if (cam->flush) {
int i;
DBG("Flushing buffers\n");
for(i=0; i<cam->num_frames; ++i) {
cam->buffers[i].status = FRAME_EMPTY;
cam->buffers[i].length = 0;
}
cam->curbuff = &cam->buffers[0];
cam->workbuff = cam->curbuff->next;
cam->flush = false;
}
old_alt = cam->params.camera_state.stream_mode;
cam->params.camera_state.stream_mode = 0;
ret = cpia2_usb_change_streaming_alternate(cam, alternate);
if (ret < 0) {
int ret2;
ERR("cpia2_usb_change_streaming_alternate() = %d!\n", ret);
cam->params.camera_state.stream_mode = old_alt;
ret2 = set_alternate(cam, USBIF_CMDONLY);
if (ret2 < 0) {
ERR("cpia2_usb_change_streaming_alternate(%d) =%d has already "
"failed. Then tried to call "
"set_alternate(USBIF_CMDONLY) = %d.\n",
alternate, ret, ret2);
}
} else {
cam->frame_count = 0;
cam->streaming = 1;
ret = cpia2_usb_stream_resume(cam);
}
return ret;
}
int cpia2_usb_stream_pause(struct camera_data *cam)
{
int ret = 0;
if(cam->streaming) {
free_sbufs(cam);
ret = set_alternate(cam, USBIF_CMDONLY);
}
return ret;
}
int cpia2_usb_stream_resume(struct camera_data *cam)
{
int ret = 0;
if(cam->streaming) {
cam->first_image_seen = 0;
ret = set_alternate(cam, cam->params.camera_state.stream_mode);
if(ret == 0) {
cpia2_do_command(cam, CPIA2_CMD_SET_USER_EFFECTS, TRANSFER_WRITE,
cam->params.vp_params.user_effects);
ret = submit_urbs(cam);
}
}
return ret;
}
int cpia2_usb_stream_stop(struct camera_data *cam)
{
int ret;
ret = cpia2_usb_stream_pause(cam);
cam->streaming = 0;
configure_transfer_mode(cam, 0);
return ret;
}
static int cpia2_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct usb_interface_descriptor *interface;
struct camera_data *cam;
int ret;
if (udev->descriptor.bNumConfigurations != 1)
return -ENODEV;
interface = &intf->cur_altsetting->desc;
LOG("CPiA2 USB camera found\n");
cam = cpia2_init_camera_struct(intf);
if (cam == NULL)
return -ENOMEM;
cam->dev = udev;
cam->iface = interface->bInterfaceNumber;
ret = set_alternate(cam, USBIF_CMDONLY);
if (ret < 0) {
ERR("%s: usb_set_interface error (ret = %d)\n", __func__, ret);
kfree(cam);
return ret;
}
if((ret = cpia2_init_camera(cam)) < 0) {
ERR("%s: failed to initialize cpia2 camera (ret = %d)\n", __func__, ret);
kfree(cam);
return ret;
}
LOG(" CPiA Version: %d.%02d (%d.%d)\n",
cam->params.version.firmware_revision_hi,
cam->params.version.firmware_revision_lo,
cam->params.version.asic_id,
cam->params.version.asic_rev);
LOG(" CPiA PnP-ID: %04x:%04x:%04x\n",
cam->params.pnp_id.vendor,
cam->params.pnp_id.product,
cam->params.pnp_id.device_revision);
LOG(" SensorID: %d.(version %d)\n",
cam->params.version.sensor_flags,
cam->params.version.sensor_rev);
usb_set_intfdata(intf, cam);
ret = cpia2_register_camera(cam);
if (ret < 0) {
ERR("%s: Failed to register cpia2 camera (ret = %d)\n", __func__, ret);
kfree(cam);
return ret;
}
return 0;
}
static void cpia2_usb_disconnect(struct usb_interface *intf)
{
struct camera_data *cam = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
DBG("Stopping stream\n");
cpia2_usb_stream_stop(cam);
mutex_lock(&cam->v4l2_lock);
DBG("Unregistering camera\n");
cpia2_unregister_camera(cam);
v4l2_device_disconnect(&cam->v4l2_dev);
mutex_unlock(&cam->v4l2_lock);
v4l2_device_put(&cam->v4l2_dev);
if(cam->buffers) {
DBG("Wakeup waiting processes\n");
cam->curbuff->status = FRAME_READY;
cam->curbuff->length = 0;
if (waitqueue_active(&cam->wq_stream))
wake_up_interruptible(&cam->wq_stream);
}
DBG("Releasing interface\n");
usb_driver_release_interface(&cpia2_driver, intf);
LOG("CPiA2 camera disconnected.\n");
}
static int cpia2_usb_suspend(struct usb_interface *intf, pm_message_t message)
{
struct camera_data *cam = usb_get_intfdata(intf);
mutex_lock(&cam->v4l2_lock);
if (cam->streaming) {
cpia2_usb_stream_stop(cam);
cam->streaming = 1;
}
mutex_unlock(&cam->v4l2_lock);
dev_info(&intf->dev, "going into suspend..\n");
return 0;
}
static int cpia2_usb_resume(struct usb_interface *intf)
{
struct camera_data *cam = usb_get_intfdata(intf);
mutex_lock(&cam->v4l2_lock);
v4l2_ctrl_handler_setup(&cam->hdl);
if (cam->streaming) {
cam->streaming = 0;
cpia2_usb_stream_start(cam,
cam->params.camera_state.stream_mode);
}
mutex_unlock(&cam->v4l2_lock);
dev_info(&intf->dev, "coming out of suspend..\n");
return 0;
}
int cpia2_usb_init(void)
{
return usb_register(&cpia2_driver);
}
void cpia2_usb_cleanup(void)
{
schedule_timeout(2 * HZ);
usb_deregister(&cpia2_driver);
}
