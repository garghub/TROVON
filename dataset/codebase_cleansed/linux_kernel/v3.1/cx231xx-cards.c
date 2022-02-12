int cx231xx_tuner_callback(void *ptr, int component, int command, int arg)
{
int rc = 0;
struct cx231xx *dev = ptr;
if (dev->tuner_type == TUNER_XC5000) {
if (command == XC5000_TUNER_RESET) {
cx231xx_info
("Tuner CB: RESET: cmd %d : tuner type %d \n",
command, dev->tuner_type);
cx231xx_set_gpio_value(dev, dev->board.tuner_gpio->bit,
1);
msleep(10);
cx231xx_set_gpio_value(dev, dev->board.tuner_gpio->bit,
0);
msleep(330);
cx231xx_set_gpio_value(dev, dev->board.tuner_gpio->bit,
1);
msleep(10);
}
} else if (dev->tuner_type == TUNER_NXP_TDA18271) {
switch (command) {
case TDA18271_CALLBACK_CMD_AGC_ENABLE:
if (dev->model == CX231XX_BOARD_PV_PLAYTV_USB_HYBRID)
rc = cx231xx_set_agc_analog_digital_mux_select(dev, arg);
break;
default:
rc = -EINVAL;
break;
}
}
return rc;
}
void cx231xx_reset_out(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, CX23417_RESET, 1);
msleep(200);
cx231xx_set_gpio_value(dev, CX23417_RESET, 0);
msleep(200);
cx231xx_set_gpio_value(dev, CX23417_RESET, 1);
}
void cx231xx_enable_OSC(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, CX23417_OSC_EN, 1);
}
void cx231xx_sleep_s5h1432(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, SLEEP_S5H1432, 0);
}
static inline void cx231xx_set_model(struct cx231xx *dev)
{
memcpy(&dev->board, &cx231xx_boards[dev->model], sizeof(dev->board));
}
void cx231xx_pre_card_setup(struct cx231xx *dev)
{
cx231xx_set_model(dev);
cx231xx_info("Identified as %s (card=%d)\n",
dev->board.name, dev->model);
if (dev->board.tuner_gpio) {
cx231xx_set_gpio_direction(dev, dev->board.tuner_gpio->bit, 1);
cx231xx_set_gpio_value(dev, dev->board.tuner_gpio->bit, 1);
}
if (dev->board.tuner_sif_gpio >= 0)
cx231xx_set_gpio_direction(dev, dev->board.tuner_sif_gpio, 1);
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
}
static void cx231xx_config_tuner(struct cx231xx *dev)
{
struct tuner_setup tun_setup;
struct v4l2_frequency f;
if (dev->tuner_type == TUNER_ABSENT)
return;
tun_setup.mode_mask = T_ANALOG_TV | T_RADIO;
tun_setup.type = dev->tuner_type;
tun_setup.addr = dev->tuner_addr;
tun_setup.tuner_callback = cx231xx_tuner_callback;
tuner_call(dev, tuner, s_type_addr, &tun_setup);
#if 0
if (tun_setup.type == TUNER_XC5000) {
static struct xc2028_ctrl ctrl = {
.fname = XC5000_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = 0;
};
struct v4l2_priv_tun_config cfg = {
.tuner = dev->tuner_type,
.priv = &ctrl,
};
tuner_call(dev, tuner, s_config, &cfg);
}
#endif
f.tuner = 0;
f.type = V4L2_TUNER_ANALOG_TV;
f.frequency = 9076;
dev->ctl_freq = f.frequency;
call_all(dev, tuner, s_frequency, &f);
}
void cx231xx_card_setup(struct cx231xx *dev)
{
cx231xx_set_model(dev);
dev->tuner_type = cx231xx_boards[dev->model].tuner_type;
if (cx231xx_boards[dev->model].tuner_addr)
dev->tuner_addr = cx231xx_boards[dev->model].tuner_addr;
if (dev->board.decoder == CX231XX_AVDECODER) {
dev->sd_cx25840 = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[0].i2c_adap,
"cx25840", 0x88 >> 1, NULL);
if (dev->sd_cx25840 == NULL)
cx231xx_info("cx25840 subdev registration failure\n");
cx25840_call(dev, core, load_fw);
}
if (dev->board.tuner_type != TUNER_ABSENT) {
dev->sd_tuner = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[dev->board.tuner_i2c_master].i2c_adap,
"tuner",
dev->tuner_addr, NULL);
if (dev->sd_tuner == NULL)
cx231xx_info("tuner subdev registration failure\n");
else
cx231xx_config_tuner(dev);
}
}
int cx231xx_config(struct cx231xx *dev)
{
dev->mute = 1;
dev->volume = 0x1f;
return 0;
}
void cx231xx_config_i2c(struct cx231xx *dev)
{
call_all(dev, video, s_stream, 1);
}
void cx231xx_release_resources(struct cx231xx *dev)
{
cx231xx_release_analog_resources(dev);
cx231xx_remove_from_devlist(dev);
cx231xx_dev_uninit(dev);
cx231xx_ir_exit(dev);
usb_put_dev(dev->udev);
cx231xx_devused &= ~(1 << dev->devno);
}
static int cx231xx_init_dev(struct cx231xx **devhandle, struct usb_device *udev,
int minor)
{
struct cx231xx *dev = *devhandle;
int retval = -ENOMEM;
int errCode;
unsigned int maxh, maxw;
dev->udev = udev;
mutex_init(&dev->lock);
mutex_init(&dev->ctrl_urb_lock);
mutex_init(&dev->gpio_i2c_lock);
mutex_init(&dev->i2c_lock);
spin_lock_init(&dev->video_mode.slock);
spin_lock_init(&dev->vbi_mode.slock);
spin_lock_init(&dev->sliced_cc_mode.slock);
init_waitqueue_head(&dev->open);
init_waitqueue_head(&dev->wait_frame);
init_waitqueue_head(&dev->wait_stream);
dev->cx231xx_read_ctrl_reg = cx231xx_read_ctrl_reg;
dev->cx231xx_write_ctrl_reg = cx231xx_write_ctrl_reg;
dev->cx231xx_send_usb_command = cx231xx_send_usb_command;
dev->cx231xx_gpio_i2c_read = cx231xx_gpio_i2c_read;
dev->cx231xx_gpio_i2c_write = cx231xx_gpio_i2c_write;
initialize_cx231xx(dev);
if (dev->model == CX231XX_BOARD_CNXT_VIDEO_GRABBER ||
dev->model == CX231XX_BOARD_HAUPPAUGE_USBLIVE2) {
cx231xx_set_alt_setting(dev, INDEX_VIDEO, 3);
cx231xx_set_alt_setting(dev, INDEX_VANC, 1);
}
cx231xx_pre_card_setup(dev);
errCode = cx231xx_config(dev);
if (errCode) {
cx231xx_errdev("error configuring device\n");
return -ENOMEM;
}
dev->norm = dev->board.norm;
errCode = cx231xx_dev_init(dev);
if (errCode < 0) {
cx231xx_dev_uninit(dev);
cx231xx_errdev("%s: cx231xx_i2c_register - errCode [%d]!\n",
__func__, errCode);
return errCode;
}
cx231xx_card_setup(dev);
cx231xx_config_i2c(dev);
maxw = norm_maxw(dev);
maxh = norm_maxh(dev);
dev->width = maxw;
dev->height = maxh;
dev->interlaced = 0;
dev->video_input = 0;
errCode = cx231xx_config(dev);
if (errCode < 0) {
cx231xx_errdev("%s: cx231xx_config - errCode [%d]!\n",
__func__, errCode);
return errCode;
}
INIT_LIST_HEAD(&dev->video_mode.vidq.active);
INIT_LIST_HEAD(&dev->video_mode.vidq.queued);
INIT_LIST_HEAD(&dev->vbi_mode.vidq.active);
INIT_LIST_HEAD(&dev->vbi_mode.vidq.queued);
cx231xx_add_into_devlist(dev);
if (dev->board.has_417) {
printk(KERN_INFO "attach 417 %d\n", dev->model);
if (cx231xx_417_register(dev) < 0) {
printk(KERN_ERR
"%s() Failed to register 417 on VID_B\n",
__func__);
}
}
retval = cx231xx_register_analog_devices(dev);
if (retval < 0) {
cx231xx_release_resources(dev);
return retval;
}
cx231xx_ir_init(dev);
cx231xx_init_extension(dev);
return 0;
}
static void request_module_async(struct work_struct *work)
{
struct cx231xx *dev = container_of(work,
struct cx231xx, request_module_wk);
if (dev->has_alsa_audio)
request_module("cx231xx-alsa");
if (dev->board.has_dvb)
request_module("cx231xx-dvb");
}
static void request_modules(struct cx231xx *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct cx231xx *dev)
{
flush_work_sync(&dev->request_module_wk);
}
static int cx231xx_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev;
struct usb_interface *uif;
struct cx231xx *dev = NULL;
int retval = -ENODEV;
int nr = 0, ifnum;
int i, isoc_pipe = 0;
char *speed;
char descr[255] = "";
struct usb_interface *lif = NULL;
struct usb_interface_assoc_descriptor *assoc_desc;
udev = usb_get_dev(interface_to_usbdev(interface));
ifnum = interface->altsetting[0].desc.bInterfaceNumber;
if (ifnum != 1)
return -ENODEV;
nr = find_first_zero_bit(&cx231xx_devused, CX231XX_MAXBOARDS);
cx231xx_devused |= 1 << nr;
if (nr >= CX231XX_MAXBOARDS) {
cx231xx_err(DRIVER_NAME
": Supports only %i cx231xx boards.\n", CX231XX_MAXBOARDS);
cx231xx_devused &= ~(1 << nr);
return -ENOMEM;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
cx231xx_err(DRIVER_NAME ": out of memory!\n");
cx231xx_devused &= ~(1 << nr);
return -ENOMEM;
}
snprintf(dev->name, 29, "cx231xx #%d", nr);
dev->devno = nr;
dev->model = id->driver_info;
dev->video_mode.alt = -1;
dev->interface_count++;
dev->gpio_dir = 0;
dev->gpio_val = 0;
dev->xc_fw_load_done = 0;
dev->has_alsa_audio = 1;
dev->power_mode = -1;
atomic_set(&dev->devlist_count, 0);
dev->vbi_or_sliced_cc_mode = 0;
assoc_desc = udev->actconfig->intf_assoc[0];
dev->max_iad_interface_count = assoc_desc->bInterfaceCount;
lif = interface;
dev->mode_tv = 0;
dev->USE_ISO = transfer_mode;
switch (udev->speed) {
case USB_SPEED_LOW:
speed = "1.5";
break;
case USB_SPEED_UNKNOWN:
case USB_SPEED_FULL:
speed = "12";
break;
case USB_SPEED_HIGH:
speed = "480";
break;
default:
speed = "unknown";
}
if (udev->manufacturer)
strlcpy(descr, udev->manufacturer, sizeof(descr));
if (udev->product) {
if (*descr)
strlcat(descr, " ", sizeof(descr));
strlcat(descr, udev->product, sizeof(descr));
}
if (*descr)
strlcat(descr, " ", sizeof(descr));
cx231xx_info("New device %s@ %s Mbps "
"(%04x:%04x) with %d interfaces\n",
descr,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
dev->max_iad_interface_count);
lif = udev->actconfig->interface[0];
dev->interface_count++;
nr = dev->devno;
assoc_desc = udev->actconfig->intf_assoc[0];
if (assoc_desc->bFirstInterface != ifnum) {
cx231xx_err(DRIVER_NAME ": Not found "
"matching IAD interface\n");
cx231xx_devused &= ~(1 << nr);
kfree(dev);
dev = NULL;
return -ENODEV;
}
cx231xx_info("registering interface %d\n", ifnum);
usb_set_intfdata(lif, dev);
retval = v4l2_device_register(&interface->dev, &dev->v4l2_dev);
if (retval) {
cx231xx_errdev("v4l2_device_register failed\n");
cx231xx_devused &= ~(1 << nr);
kfree(dev);
dev = NULL;
return -EIO;
}
retval = cx231xx_init_dev(&dev, udev, nr);
if (retval) {
cx231xx_devused &= ~(1 << dev->devno);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
dev = NULL;
usb_set_intfdata(lif, NULL);
return retval;
}
uif = udev->actconfig->interface[dev->current_pcb_config.
hs_config_info[0].interface_info.video_index + 1];
dev->video_mode.end_point_addr = le16_to_cpu(uif->altsetting[0].
endpoint[isoc_pipe].desc.bEndpointAddress);
dev->video_mode.num_alt = uif->num_altsetting;
cx231xx_info("EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->video_mode.end_point_addr,
dev->video_mode.num_alt);
dev->video_mode.alt_max_pkt_size =
kmalloc(32 * dev->video_mode.num_alt, GFP_KERNEL);
if (dev->video_mode.alt_max_pkt_size == NULL) {
cx231xx_errdev("out of memory!\n");
cx231xx_devused &= ~(1 << nr);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
dev = NULL;
return -ENOMEM;
}
for (i = 0; i < dev->video_mode.num_alt; i++) {
u16 tmp = le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].
desc.wMaxPacketSize);
dev->video_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
cx231xx_info("Alternate setting %i, max size= %i\n", i,
dev->video_mode.alt_max_pkt_size[i]);
}
uif = udev->actconfig->interface[dev->current_pcb_config.
hs_config_info[0].interface_info.
vanc_index + 1];
dev->vbi_mode.end_point_addr =
le16_to_cpu(uif->altsetting[0].endpoint[isoc_pipe].desc.
bEndpointAddress);
dev->vbi_mode.num_alt = uif->num_altsetting;
cx231xx_info("EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->vbi_mode.end_point_addr,
dev->vbi_mode.num_alt);
dev->vbi_mode.alt_max_pkt_size =
kmalloc(32 * dev->vbi_mode.num_alt, GFP_KERNEL);
if (dev->vbi_mode.alt_max_pkt_size == NULL) {
cx231xx_errdev("out of memory!\n");
cx231xx_devused &= ~(1 << nr);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
dev = NULL;
return -ENOMEM;
}
for (i = 0; i < dev->vbi_mode.num_alt; i++) {
u16 tmp =
le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].
desc.wMaxPacketSize);
dev->vbi_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
cx231xx_info("Alternate setting %i, max size= %i\n", i,
dev->vbi_mode.alt_max_pkt_size[i]);
}
uif = udev->actconfig->interface[dev->current_pcb_config.
hs_config_info[0].interface_info.
hanc_index + 1];
dev->sliced_cc_mode.end_point_addr =
le16_to_cpu(uif->altsetting[0].endpoint[isoc_pipe].desc.
bEndpointAddress);
dev->sliced_cc_mode.num_alt = uif->num_altsetting;
cx231xx_info("EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->sliced_cc_mode.end_point_addr,
dev->sliced_cc_mode.num_alt);
dev->sliced_cc_mode.alt_max_pkt_size =
kmalloc(32 * dev->sliced_cc_mode.num_alt, GFP_KERNEL);
if (dev->sliced_cc_mode.alt_max_pkt_size == NULL) {
cx231xx_errdev("out of memory!\n");
cx231xx_devused &= ~(1 << nr);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
dev = NULL;
return -ENOMEM;
}
for (i = 0; i < dev->sliced_cc_mode.num_alt; i++) {
u16 tmp = le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].
desc.wMaxPacketSize);
dev->sliced_cc_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
cx231xx_info("Alternate setting %i, max size= %i\n", i,
dev->sliced_cc_mode.alt_max_pkt_size[i]);
}
if (dev->current_pcb_config.ts1_source != 0xff) {
uif = udev->actconfig->interface[dev->current_pcb_config.
hs_config_info[0].
interface_info.
ts1_index + 1];
dev->ts1_mode.end_point_addr =
le16_to_cpu(uif->altsetting[0].endpoint[isoc_pipe].
desc.bEndpointAddress);
dev->ts1_mode.num_alt = uif->num_altsetting;
cx231xx_info("EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->ts1_mode.end_point_addr,
dev->ts1_mode.num_alt);
dev->ts1_mode.alt_max_pkt_size =
kmalloc(32 * dev->ts1_mode.num_alt, GFP_KERNEL);
if (dev->ts1_mode.alt_max_pkt_size == NULL) {
cx231xx_errdev("out of memory!\n");
cx231xx_devused &= ~(1 << nr);
v4l2_device_unregister(&dev->v4l2_dev);
kfree(dev);
dev = NULL;
return -ENOMEM;
}
for (i = 0; i < dev->ts1_mode.num_alt; i++) {
u16 tmp = le16_to_cpu(uif->altsetting[i].
endpoint[isoc_pipe].desc.
wMaxPacketSize);
dev->ts1_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
cx231xx_info("Alternate setting %i, max size= %i\n", i,
dev->ts1_mode.alt_max_pkt_size[i]);
}
}
if (dev->model == CX231XX_BOARD_CNXT_VIDEO_GRABBER) {
cx231xx_enable_OSC(dev);
cx231xx_reset_out(dev);
cx231xx_set_alt_setting(dev, INDEX_VIDEO, 3);
}
if (dev->model == CX231XX_BOARD_CNXT_RDE_253S)
cx231xx_sleep_s5h1432(dev);
request_modules(dev);
return 0;
}
static void cx231xx_usb_disconnect(struct usb_interface *interface)
{
struct cx231xx *dev;
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (!dev)
return;
if (!dev->udev)
return;
flush_request_modules(dev);
v4l2_device_unregister(&dev->v4l2_dev);
mutex_lock(&dev->lock);
wake_up_interruptible_all(&dev->open);
if (dev->users) {
cx231xx_warn
("device %s is open! Deregistration and memory "
"deallocation are deferred on close.\n",
video_device_node_name(dev->vdev));
dev->state |= DEV_MISCONFIGURED;
if (dev->USE_ISO)
cx231xx_uninit_isoc(dev);
else
cx231xx_uninit_bulk(dev);
dev->state |= DEV_DISCONNECTED;
wake_up_interruptible(&dev->wait_frame);
wake_up_interruptible(&dev->wait_stream);
} else {
dev->state |= DEV_DISCONNECTED;
cx231xx_release_resources(dev);
}
cx231xx_close_extension(dev);
mutex_unlock(&dev->lock);
if (!dev->users) {
kfree(dev->video_mode.alt_max_pkt_size);
kfree(dev->vbi_mode.alt_max_pkt_size);
kfree(dev->sliced_cc_mode.alt_max_pkt_size);
kfree(dev->ts1_mode.alt_max_pkt_size);
kfree(dev);
dev = NULL;
}
}
static int __init cx231xx_module_init(void)
{
int result;
printk(KERN_INFO DRIVER_NAME " v4l2 driver loaded.\n");
result = usb_register(&cx231xx_usb_driver);
if (result)
cx231xx_err(DRIVER_NAME
" usb_register failed. Error number %d.\n", result);
return result;
}
static void __exit cx231xx_module_exit(void)
{
usb_deregister(&cx231xx_usb_driver);
}
