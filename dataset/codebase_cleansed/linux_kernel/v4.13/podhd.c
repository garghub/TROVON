static ssize_t serial_number_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct snd_card *card = dev_to_snd_card(dev);
struct usb_line6_podhd *pod = card->private_data;
return sprintf(buf, "%u\n", pod->serial_number);
}
static ssize_t firmware_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct snd_card *card = dev_to_snd_card(dev);
struct usb_line6_podhd *pod = card->private_data;
return sprintf(buf, "%06x\n", pod->firmware_version);
}
static void podhd_startup(struct usb_line6_podhd *pod)
{
CHECK_STARTUP_PROGRESS(pod->startup_progress, PODHD_STARTUP_INIT);
line6_start_timer(&pod->startup_timer, PODHD_STARTUP_DELAY,
podhd_startup_start_workqueue, (unsigned long)pod);
}
static void podhd_startup_start_workqueue(unsigned long data)
{
struct usb_line6_podhd *pod = (struct usb_line6_podhd *)data;
CHECK_STARTUP_PROGRESS(pod->startup_progress,
PODHD_STARTUP_SCHEDULE_WORKQUEUE);
schedule_work(&pod->startup_work);
}
static int podhd_dev_start(struct usb_line6_podhd *pod)
{
int ret;
u8 init_bytes[8];
int i;
struct usb_device *usbdev = pod->line6.usbdev;
ret = usb_control_msg(usbdev, usb_sndctrlpipe(usbdev, 0),
0x67, USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_OUT,
0x11, 0,
NULL, 0, LINE6_TIMEOUT * HZ);
if (ret < 0) {
dev_err(pod->line6.ifcdev, "read request failed (error %d)\n", ret);
return ret;
}
ret = usb_control_msg(usbdev, usb_rcvctrlpipe(usbdev, 0), 0x67,
USB_TYPE_VENDOR | USB_RECIP_DEVICE | USB_DIR_IN,
0x11, 0x0,
&init_bytes, 3, LINE6_TIMEOUT * HZ);
if (ret < 0) {
dev_err(pod->line6.ifcdev,
"receive length failed (error %d)\n", ret);
return ret;
}
pod->firmware_version =
(init_bytes[0] << 16) | (init_bytes[1] << 8) | (init_bytes[2] << 0);
for (i = 0; i <= 16; i++) {
ret = line6_read_data(&pod->line6, 0xf000 + 0x08 * i, init_bytes, 8);
if (ret < 0)
return ret;
}
ret = usb_control_msg(usbdev, usb_sndctrlpipe(usbdev, 0),
USB_REQ_SET_FEATURE,
USB_TYPE_STANDARD | USB_RECIP_DEVICE | USB_DIR_OUT,
1, 0,
NULL, 0, LINE6_TIMEOUT * HZ);
if (ret < 0)
return ret;
return 0;
}
static void podhd_startup_workqueue(struct work_struct *work)
{
struct usb_line6_podhd *pod =
container_of(work, struct usb_line6_podhd, startup_work);
CHECK_STARTUP_PROGRESS(pod->startup_progress, PODHD_STARTUP_SETUP);
podhd_dev_start(pod);
line6_read_serial_number(&pod->line6, &pod->serial_number);
podhd_startup_finalize(pod);
}
static int podhd_startup_finalize(struct usb_line6_podhd *pod)
{
struct usb_line6 *line6 = &pod->line6;
return snd_card_register(line6->card);
}
static void podhd_disconnect(struct usb_line6 *line6)
{
struct usb_line6_podhd *pod = (struct usb_line6_podhd *)line6;
if (pod->line6.properties->capabilities & LINE6_CAP_CONTROL_INFO) {
struct usb_interface *intf;
del_timer_sync(&pod->startup_timer);
cancel_work_sync(&pod->startup_work);
intf = usb_ifnum_to_if(line6->usbdev,
pod->line6.properties->ctrl_if);
usb_driver_release_interface(&podhd_driver, intf);
}
}
static int podhd_init(struct usb_line6 *line6,
const struct usb_device_id *id)
{
int err;
struct usb_line6_podhd *pod = (struct usb_line6_podhd *) line6;
struct usb_interface *intf;
line6->disconnect = podhd_disconnect;
if (pod->line6.properties->capabilities & LINE6_CAP_CONTROL) {
intf = usb_ifnum_to_if(line6->usbdev,
pod->line6.properties->ctrl_if);
if (!intf) {
dev_err(pod->line6.ifcdev, "interface %d not found\n",
pod->line6.properties->ctrl_if);
return -ENODEV;
}
err = usb_driver_claim_interface(&podhd_driver, intf, NULL);
if (err != 0) {
dev_err(pod->line6.ifcdev, "can't claim interface %d, error %d\n",
pod->line6.properties->ctrl_if, err);
return err;
}
}
if (pod->line6.properties->capabilities & LINE6_CAP_CONTROL_INFO) {
err = snd_card_add_dev_attr(line6->card, &podhd_dev_attr_group);
if (err < 0)
return err;
}
if (pod->line6.properties->capabilities & LINE6_CAP_PCM) {
err = line6_init_pcm(line6,
(id->driver_info == LINE6_PODX3 ||
id->driver_info == LINE6_PODX3LIVE) ? &podx3_pcm_properties :
&podhd_pcm_properties);
if (err < 0)
return err;
}
if (!(pod->line6.properties->capabilities & LINE6_CAP_CONTROL_INFO)) {
return podhd_startup_finalize(pod);
}
init_timer(&pod->startup_timer);
INIT_WORK(&pod->startup_work, podhd_startup_workqueue);
podhd_startup(pod);
return 0;
}
static int podhd_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
return line6_probe(interface, id, "Line6-PODHD",
&podhd_properties_table[id->driver_info],
podhd_init, sizeof(struct usb_line6_podhd));
}
