static int si470x_get_report(struct si470x_device *radio, void *buf, int size)
{
unsigned char *report = buf;
int retval;
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
HID_REQ_GET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_IN,
report[0], 2,
buf, size, usb_timeout);
if (retval < 0)
dev_warn(&radio->intf->dev,
"si470x_get_report: usb_control_msg returned %d\n",
retval);
return retval;
}
static int si470x_set_report(struct si470x_device *radio, void *buf, int size)
{
unsigned char *report = buf;
int retval;
retval = usb_control_msg(radio->usbdev,
usb_sndctrlpipe(radio->usbdev, 0),
HID_REQ_SET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_OUT,
report[0], 2,
buf, size, usb_timeout);
if (retval < 0)
dev_warn(&radio->intf->dev,
"si470x_set_report: usb_control_msg returned %d\n",
retval);
return retval;
}
int si470x_get_register(struct si470x_device *radio, int regnr)
{
int retval;
radio->usb_buf[0] = REGISTER_REPORT(regnr);
retval = si470x_get_report(radio, radio->usb_buf, REGISTER_REPORT_SIZE);
if (retval >= 0)
radio->registers[regnr] = get_unaligned_be16(&radio->usb_buf[1]);
return (retval < 0) ? -EINVAL : 0;
}
int si470x_set_register(struct si470x_device *radio, int regnr)
{
int retval;
radio->usb_buf[0] = REGISTER_REPORT(regnr);
put_unaligned_be16(radio->registers[regnr], &radio->usb_buf[1]);
retval = si470x_set_report(radio, radio->usb_buf, REGISTER_REPORT_SIZE);
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_get_all_registers(struct si470x_device *radio)
{
int retval;
unsigned char regnr;
radio->usb_buf[0] = ENTIRE_REPORT;
retval = si470x_get_report(radio, radio->usb_buf, ENTIRE_REPORT_SIZE);
if (retval >= 0)
for (regnr = 0; regnr < RADIO_REGISTER_NUM; regnr++)
radio->registers[regnr] = get_unaligned_be16(
&radio->usb_buf[regnr * RADIO_REGISTER_SIZE + 1]);
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_set_led_state(struct si470x_device *radio,
unsigned char led_state)
{
int retval;
radio->usb_buf[0] = LED_REPORT;
radio->usb_buf[1] = LED_COMMAND;
radio->usb_buf[2] = led_state;
retval = si470x_set_report(radio, radio->usb_buf, LED_REPORT_SIZE);
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_get_scratch_page_versions(struct si470x_device *radio)
{
int retval;
radio->usb_buf[0] = SCRATCH_REPORT;
retval = si470x_get_report(radio, radio->usb_buf, SCRATCH_REPORT_SIZE);
if (retval < 0)
dev_warn(&radio->intf->dev, "si470x_get_scratch: "
"si470x_get_report returned %d\n", retval);
else {
radio->software_version = radio->usb_buf[1];
radio->hardware_version = radio->usb_buf[2];
}
return (retval < 0) ? -EINVAL : 0;
}
static void si470x_int_in_callback(struct urb *urb)
{
struct si470x_device *radio = urb->context;
int retval;
unsigned char regnr;
unsigned char blocknum;
unsigned short bler;
unsigned short rds;
unsigned char tmpbuf[3];
if (urb->status) {
if (urb->status == -ENOENT ||
urb->status == -ECONNRESET ||
urb->status == -ESHUTDOWN) {
return;
} else {
dev_warn(&radio->intf->dev,
"non-zero urb status (%d)\n", urb->status);
goto resubmit;
}
}
if (urb->actual_length != RDS_REPORT_SIZE)
goto resubmit;
radio->registers[STATUSRSSI] =
get_unaligned_be16(&radio->int_in_buffer[1]);
if (radio->registers[STATUSRSSI] & STATUSRSSI_STC)
complete(&radio->completion);
if ((radio->registers[SYSCONFIG1] & SYSCONFIG1_RDS)) {
for (regnr = 1; regnr < RDS_REGISTER_NUM; regnr++)
radio->registers[STATUSRSSI + regnr] =
get_unaligned_be16(&radio->int_in_buffer[
regnr * RADIO_REGISTER_SIZE + 1]);
if ((radio->registers[STATUSRSSI] & STATUSRSSI_RDSR) == 0) {
goto resubmit;
}
if ((radio->registers[STATUSRSSI] & STATUSRSSI_RDSS) == 0) {
goto resubmit;
}
for (blocknum = 0; blocknum < 4; blocknum++) {
switch (blocknum) {
default:
bler = (radio->registers[STATUSRSSI] &
STATUSRSSI_BLERA) >> 9;
rds = radio->registers[RDSA];
break;
case 1:
bler = (radio->registers[READCHAN] &
READCHAN_BLERB) >> 14;
rds = radio->registers[RDSB];
break;
case 2:
bler = (radio->registers[READCHAN] &
READCHAN_BLERC) >> 12;
rds = radio->registers[RDSC];
break;
case 3:
bler = (radio->registers[READCHAN] &
READCHAN_BLERD) >> 10;
rds = radio->registers[RDSD];
break;
}
put_unaligned_le16(rds, &tmpbuf);
tmpbuf[2] = blocknum;
tmpbuf[2] |= blocknum << 3;
if (bler > max_rds_errors)
tmpbuf[2] |= 0x80;
else if (bler > 0)
tmpbuf[2] |= 0x40;
memcpy(&radio->buffer[radio->wr_index], &tmpbuf, 3);
radio->wr_index += 3;
if (radio->wr_index >= radio->buf_size)
radio->wr_index = 0;
if (radio->wr_index == radio->rd_index) {
radio->rd_index += 3;
if (radio->rd_index >= radio->buf_size)
radio->rd_index = 0;
}
}
if (radio->wr_index != radio->rd_index)
wake_up_interruptible(&radio->read_queue);
}
resubmit:
if (radio->int_in_running && radio->usbdev) {
retval = usb_submit_urb(radio->int_in_urb, GFP_ATOMIC);
if (retval) {
dev_warn(&radio->intf->dev,
"resubmitting urb failed (%d)", retval);
radio->int_in_running = 0;
}
}
radio->status_rssi_auto_update = radio->int_in_running;
}
int si470x_fops_open(struct file *file)
{
return v4l2_fh_open(file);
}
int si470x_fops_release(struct file *file)
{
return v4l2_fh_release(file);
}
static void si470x_usb_release(struct v4l2_device *v4l2_dev)
{
struct si470x_device *radio =
container_of(v4l2_dev, struct si470x_device, v4l2_dev);
usb_free_urb(radio->int_in_urb);
v4l2_ctrl_handler_free(&radio->hdl);
v4l2_device_unregister(&radio->v4l2_dev);
kfree(radio->int_in_buffer);
kfree(radio->buffer);
kfree(radio->usb_buf);
kfree(radio);
}
int si470x_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *capability)
{
struct si470x_device *radio = video_drvdata(file);
strlcpy(capability->driver, DRIVER_NAME, sizeof(capability->driver));
strlcpy(capability->card, DRIVER_CARD, sizeof(capability->card));
usb_make_path(radio->usbdev, capability->bus_info,
sizeof(capability->bus_info));
capability->device_caps = V4L2_CAP_HW_FREQ_SEEK | V4L2_CAP_READWRITE |
V4L2_CAP_TUNER | V4L2_CAP_RADIO | V4L2_CAP_RDS_CAPTURE;
capability->capabilities = capability->device_caps | V4L2_CAP_DEVICE_CAPS;
return 0;
}
static int si470x_start_usb(struct si470x_device *radio)
{
int retval;
usb_fill_int_urb(radio->int_in_urb, radio->usbdev,
usb_rcvintpipe(radio->usbdev,
radio->int_in_endpoint->bEndpointAddress),
radio->int_in_buffer,
le16_to_cpu(radio->int_in_endpoint->wMaxPacketSize),
si470x_int_in_callback,
radio,
radio->int_in_endpoint->bInterval);
radio->int_in_running = 1;
mb();
retval = usb_submit_urb(radio->int_in_urb, GFP_KERNEL);
if (retval) {
dev_info(&radio->intf->dev,
"submitting int urb failed (%d)\n", retval);
radio->int_in_running = 0;
}
radio->status_rssi_auto_update = radio->int_in_running;
retval = si470x_start(radio);
if (retval < 0)
return retval;
v4l2_ctrl_handler_setup(&radio->hdl);
return retval;
}
static int si470x_usb_driver_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct si470x_device *radio;
struct usb_host_interface *iface_desc;
struct usb_endpoint_descriptor *endpoint;
int i, int_end_size, retval = 0;
unsigned char version_warning = 0;
radio = kzalloc(sizeof(struct si470x_device), GFP_KERNEL);
if (!radio) {
retval = -ENOMEM;
goto err_initial;
}
radio->usb_buf = kmalloc(MAX_REPORT_SIZE, GFP_KERNEL);
if (radio->usb_buf == NULL) {
retval = -ENOMEM;
goto err_radio;
}
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
radio->band = 1;
mutex_init(&radio->lock);
init_completion(&radio->completion);
iface_desc = intf->cur_altsetting;
for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
endpoint = &iface_desc->endpoint[i].desc;
if (((endpoint->bEndpointAddress & USB_ENDPOINT_DIR_MASK) ==
USB_DIR_IN) && ((endpoint->bmAttributes &
USB_ENDPOINT_XFERTYPE_MASK) == USB_ENDPOINT_XFER_INT))
radio->int_in_endpoint = endpoint;
}
if (!radio->int_in_endpoint) {
dev_info(&intf->dev, "could not find interrupt in endpoint\n");
retval = -EIO;
goto err_usbbuf;
}
int_end_size = le16_to_cpu(radio->int_in_endpoint->wMaxPacketSize);
radio->int_in_buffer = kmalloc(int_end_size, GFP_KERNEL);
if (!radio->int_in_buffer) {
dev_info(&intf->dev, "could not allocate int_in_buffer");
retval = -ENOMEM;
goto err_usbbuf;
}
radio->int_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!radio->int_in_urb) {
dev_info(&intf->dev, "could not allocate int_in_urb");
retval = -ENOMEM;
goto err_intbuffer;
}
radio->v4l2_dev.release = si470x_usb_release;
if (id->idVendor == 0x10c4 && id->idProduct == 0x818a) {
retval = usb_control_msg(radio->usbdev,
usb_rcvctrlpipe(radio->usbdev, 0),
HID_REQ_GET_REPORT,
USB_TYPE_CLASS | USB_RECIP_INTERFACE | USB_DIR_IN,
1, 2,
radio->usb_buf, 3, 500);
if (retval != 3 ||
(get_unaligned_be16(&radio->usb_buf[1]) & 0xfff) != 0x0242) {
dev_info(&intf->dev, "this is not a si470x device.\n");
retval = -ENODEV;
goto err_urb;
}
}
retval = v4l2_device_register(&intf->dev, &radio->v4l2_dev);
if (retval < 0) {
dev_err(&intf->dev, "couldn't register v4l2_device\n");
goto err_urb;
}
v4l2_ctrl_handler_init(&radio->hdl, 2);
v4l2_ctrl_new_std(&radio->hdl, &si470x_ctrl_ops,
V4L2_CID_AUDIO_MUTE, 0, 1, 1, 1);
v4l2_ctrl_new_std(&radio->hdl, &si470x_ctrl_ops,
V4L2_CID_AUDIO_VOLUME, 0, 15, 1, 15);
if (radio->hdl.error) {
retval = radio->hdl.error;
dev_err(&intf->dev, "couldn't register control\n");
goto err_dev;
}
radio->videodev = si470x_viddev_template;
radio->videodev.ctrl_handler = &radio->hdl;
radio->videodev.lock = &radio->lock;
radio->videodev.v4l2_dev = &radio->v4l2_dev;
radio->videodev.release = video_device_release_empty;
video_set_drvdata(&radio->videodev, radio);
if (si470x_get_all_registers(radio) < 0) {
retval = -EIO;
goto err_ctrl;
}
dev_info(&intf->dev, "DeviceID=0x%4.4hx ChipID=0x%4.4hx\n",
radio->registers[DEVICEID], radio->registers[CHIPID]);
if ((radio->registers[CHIPID] & CHIPID_FIRMWARE) < RADIO_FW_VERSION) {
dev_warn(&intf->dev,
"This driver is known to work with "
"firmware version %hu,\n", RADIO_FW_VERSION);
dev_warn(&intf->dev,
"but the device has firmware version %hu.\n",
radio->registers[CHIPID] & CHIPID_FIRMWARE);
version_warning = 1;
}
if (si470x_get_scratch_page_versions(radio) < 0) {
retval = -EIO;
goto err_ctrl;
}
dev_info(&intf->dev, "software version %d, hardware version %d\n",
radio->software_version, radio->hardware_version);
if (radio->hardware_version < RADIO_HW_VERSION) {
dev_warn(&intf->dev,
"This driver is known to work with "
"hardware version %hu,\n", RADIO_HW_VERSION);
dev_warn(&intf->dev,
"but the device has hardware version %hu.\n",
radio->hardware_version);
version_warning = 1;
}
if (version_warning == 1) {
dev_warn(&intf->dev,
"If you have some trouble using this driver,\n");
dev_warn(&intf->dev,
"please report to V4L ML at "
"linux-media@vger.kernel.org\n");
}
si470x_set_led_state(radio, BLINK_GREEN_LED);
radio->buf_size = rds_buf * 3;
radio->buffer = kmalloc(radio->buf_size, GFP_KERNEL);
if (!radio->buffer) {
retval = -EIO;
goto err_ctrl;
}
radio->wr_index = 0;
radio->rd_index = 0;
init_waitqueue_head(&radio->read_queue);
usb_set_intfdata(intf, radio);
retval = si470x_start_usb(radio);
if (retval < 0)
goto err_all;
si470x_set_freq(radio, 87.5 * FREQ_MUL);
retval = video_register_device(&radio->videodev, VFL_TYPE_RADIO,
radio_nr);
if (retval) {
dev_err(&intf->dev, "Could not register video device\n");
goto err_all;
}
return 0;
err_all:
kfree(radio->buffer);
err_ctrl:
v4l2_ctrl_handler_free(&radio->hdl);
err_dev:
v4l2_device_unregister(&radio->v4l2_dev);
err_urb:
usb_free_urb(radio->int_in_urb);
err_intbuffer:
kfree(radio->int_in_buffer);
err_usbbuf:
kfree(radio->usb_buf);
err_radio:
kfree(radio);
err_initial:
return retval;
}
static int si470x_usb_driver_suspend(struct usb_interface *intf,
pm_message_t message)
{
struct si470x_device *radio = usb_get_intfdata(intf);
dev_info(&intf->dev, "suspending now...\n");
if (radio->int_in_running) {
radio->int_in_running = 0;
if (radio->int_in_urb)
usb_kill_urb(radio->int_in_urb);
}
wake_up_interruptible(&radio->read_queue);
si470x_stop(radio);
return 0;
}
static int si470x_usb_driver_resume(struct usb_interface *intf)
{
struct si470x_device *radio = usb_get_intfdata(intf);
int ret;
dev_info(&intf->dev, "resuming now...\n");
ret = si470x_start_usb(radio);
if (ret == 0)
v4l2_ctrl_handler_setup(&radio->hdl);
return ret;
}
static void si470x_usb_driver_disconnect(struct usb_interface *intf)
{
struct si470x_device *radio = usb_get_intfdata(intf);
mutex_lock(&radio->lock);
v4l2_device_disconnect(&radio->v4l2_dev);
video_unregister_device(&radio->videodev);
usb_set_intfdata(intf, NULL);
mutex_unlock(&radio->lock);
v4l2_device_put(&radio->v4l2_dev);
}
