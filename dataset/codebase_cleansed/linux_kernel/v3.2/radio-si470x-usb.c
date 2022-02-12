static int si470x_get_report(struct si470x_device *radio, void *buf, int size)
{
unsigned char *report = (unsigned char *) buf;
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
unsigned char *report = (unsigned char *) buf;
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
unsigned char buf[REGISTER_REPORT_SIZE];
int retval;
buf[0] = REGISTER_REPORT(regnr);
retval = si470x_get_report(radio, (void *) &buf, sizeof(buf));
if (retval >= 0)
radio->registers[regnr] = get_unaligned_be16(&buf[1]);
return (retval < 0) ? -EINVAL : 0;
}
int si470x_set_register(struct si470x_device *radio, int regnr)
{
unsigned char buf[REGISTER_REPORT_SIZE];
int retval;
buf[0] = REGISTER_REPORT(regnr);
put_unaligned_be16(radio->registers[regnr], &buf[1]);
retval = si470x_set_report(radio, (void *) &buf, sizeof(buf));
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_get_all_registers(struct si470x_device *radio)
{
unsigned char buf[ENTIRE_REPORT_SIZE];
int retval;
unsigned char regnr;
buf[0] = ENTIRE_REPORT;
retval = si470x_get_report(radio, (void *) &buf, sizeof(buf));
if (retval >= 0)
for (regnr = 0; regnr < RADIO_REGISTER_NUM; regnr++)
radio->registers[regnr] = get_unaligned_be16(
&buf[regnr * RADIO_REGISTER_SIZE + 1]);
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_set_led_state(struct si470x_device *radio,
unsigned char led_state)
{
unsigned char buf[LED_REPORT_SIZE];
int retval;
buf[0] = LED_REPORT;
buf[1] = LED_COMMAND;
buf[2] = led_state;
retval = si470x_set_report(radio, (void *) &buf, sizeof(buf));
return (retval < 0) ? -EINVAL : 0;
}
static int si470x_get_scratch_page_versions(struct si470x_device *radio)
{
unsigned char buf[SCRATCH_REPORT_SIZE];
int retval;
buf[0] = SCRATCH_REPORT;
retval = si470x_get_report(radio, (void *) &buf, sizeof(buf));
if (retval < 0)
dev_warn(&radio->intf->dev, "si470x_get_scratch: "
"si470x_get_report returned %d\n", retval);
else {
radio->software_version = buf[1];
radio->hardware_version = buf[2];
}
return (retval < 0) ? -EINVAL : 0;
}
int si470x_disconnect_check(struct si470x_device *radio)
{
if (radio->disconnected)
return -EIO;
else
return 0;
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
if (radio->disconnected)
return;
if ((radio->registers[SYSCONFIG1] & SYSCONFIG1_RDS) == 0)
goto resubmit;
if (urb->actual_length > 0) {
for (regnr = 0; regnr < RDS_REGISTER_NUM; regnr++)
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
};
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
}
int si470x_fops_open(struct file *file)
{
struct si470x_device *radio = video_drvdata(file);
int retval;
mutex_lock(&radio->lock);
radio->users++;
retval = usb_autopm_get_interface(radio->intf);
if (retval < 0) {
radio->users--;
retval = -EIO;
goto done;
}
if (radio->users == 1) {
retval = si470x_start(radio);
if (retval < 0) {
usb_autopm_put_interface(radio->intf);
goto done;
}
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
usb_autopm_put_interface(radio->intf);
}
}
done:
mutex_unlock(&radio->lock);
return retval;
}
int si470x_fops_release(struct file *file)
{
struct si470x_device *radio = video_drvdata(file);
int retval = 0;
if (!radio) {
retval = -ENODEV;
goto done;
}
mutex_lock(&radio->lock);
radio->users--;
if (radio->users == 0) {
if (radio->int_in_running) {
radio->int_in_running = 0;
if (radio->int_in_urb)
usb_kill_urb(radio->int_in_urb);
}
if (radio->disconnected) {
video_unregister_device(radio->videodev);
kfree(radio->int_in_buffer);
kfree(radio->buffer);
mutex_unlock(&radio->lock);
kfree(radio);
goto done;
}
wake_up_interruptible(&radio->read_queue);
retval = si470x_stop(radio);
usb_autopm_put_interface(radio->intf);
}
mutex_unlock(&radio->lock);
done:
return retval;
}
int si470x_vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *capability)
{
struct si470x_device *radio = video_drvdata(file);
strlcpy(capability->driver, DRIVER_NAME, sizeof(capability->driver));
strlcpy(capability->card, DRIVER_CARD, sizeof(capability->card));
usb_make_path(radio->usbdev, capability->bus_info,
sizeof(capability->bus_info));
capability->capabilities = V4L2_CAP_HW_FREQ_SEEK |
V4L2_CAP_TUNER | V4L2_CAP_RADIO | V4L2_CAP_RDS_CAPTURE;
return 0;
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
radio->users = 0;
radio->disconnected = 0;
radio->usbdev = interface_to_usbdev(intf);
radio->intf = intf;
mutex_init(&radio->lock);
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
goto err_radio;
}
int_end_size = le16_to_cpu(radio->int_in_endpoint->wMaxPacketSize);
radio->int_in_buffer = kmalloc(int_end_size, GFP_KERNEL);
if (!radio->int_in_buffer) {
dev_info(&intf->dev, "could not allocate int_in_buffer");
retval = -ENOMEM;
goto err_radio;
}
radio->int_in_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!radio->int_in_urb) {
dev_info(&intf->dev, "could not allocate int_in_urb");
retval = -ENOMEM;
goto err_intbuffer;
}
radio->videodev = video_device_alloc();
if (!radio->videodev) {
retval = -ENOMEM;
goto err_urb;
}
memcpy(radio->videodev, &si470x_viddev_template,
sizeof(si470x_viddev_template));
video_set_drvdata(radio->videodev, radio);
if (si470x_get_all_registers(radio) < 0) {
retval = -EIO;
goto err_video;
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
goto err_video;
}
dev_info(&intf->dev, "software version %d, hardware version %d\n",
radio->software_version, radio->hardware_version);
if (radio->software_version < RADIO_SW_VERSION) {
dev_warn(&intf->dev,
"This driver is known to work with "
"software version %hu,\n", RADIO_SW_VERSION);
dev_warn(&intf->dev,
"but the device has software version %hu.\n",
radio->software_version);
version_warning = 1;
}
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
si470x_set_freq(radio, 87.5 * FREQ_MUL);
si470x_set_led_state(radio, BLINK_GREEN_LED);
radio->buf_size = rds_buf * 3;
radio->buffer = kmalloc(radio->buf_size, GFP_KERNEL);
if (!radio->buffer) {
retval = -EIO;
goto err_video;
}
radio->wr_index = 0;
radio->rd_index = 0;
init_waitqueue_head(&radio->read_queue);
retval = video_register_device(radio->videodev, VFL_TYPE_RADIO,
radio_nr);
if (retval) {
dev_warn(&intf->dev, "Could not register video device\n");
goto err_all;
}
usb_set_intfdata(intf, radio);
return 0;
err_all:
kfree(radio->buffer);
err_video:
video_device_release(radio->videodev);
err_urb:
usb_free_urb(radio->int_in_urb);
err_intbuffer:
kfree(radio->int_in_buffer);
err_radio:
kfree(radio);
err_initial:
return retval;
}
static int si470x_usb_driver_suspend(struct usb_interface *intf,
pm_message_t message)
{
dev_info(&intf->dev, "suspending now...\n");
return 0;
}
static int si470x_usb_driver_resume(struct usb_interface *intf)
{
dev_info(&intf->dev, "resuming now...\n");
return 0;
}
static void si470x_usb_driver_disconnect(struct usb_interface *intf)
{
struct si470x_device *radio = usb_get_intfdata(intf);
mutex_lock(&radio->lock);
radio->disconnected = 1;
usb_set_intfdata(intf, NULL);
if (radio->users == 0) {
si470x_set_led_state(radio, BLINK_ORANGE_LED);
usb_free_urb(radio->int_in_urb);
kfree(radio->int_in_buffer);
video_unregister_device(radio->videodev);
kfree(radio->buffer);
mutex_unlock(&radio->lock);
kfree(radio);
} else {
mutex_unlock(&radio->lock);
}
}
static int __init si470x_module_init(void)
{
printk(KERN_INFO DRIVER_DESC ", Version " DRIVER_VERSION "\n");
return usb_register(&si470x_usb_driver);
}
static void __exit si470x_module_exit(void)
{
usb_deregister(&si470x_usb_driver);
}
