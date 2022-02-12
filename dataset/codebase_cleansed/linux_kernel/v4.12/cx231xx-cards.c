int cx231xx_tuner_callback(void *ptr, int component, int command, int arg)
{
int rc = 0;
struct cx231xx *dev = ptr;
if (dev->tuner_type == TUNER_XC5000) {
if (command == XC5000_TUNER_RESET) {
dev_dbg(dev->dev,
"Tuner CB: RESET: cmd %d : tuner type %d\n",
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
static void cx231xx_reset_out(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, CX23417_RESET, 1);
msleep(200);
cx231xx_set_gpio_value(dev, CX23417_RESET, 0);
msleep(200);
cx231xx_set_gpio_value(dev, CX23417_RESET, 1);
}
static void cx231xx_enable_OSC(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, CX23417_OSC_EN, 1);
}
static void cx231xx_sleep_s5h1432(struct cx231xx *dev)
{
cx231xx_set_gpio_value(dev, SLEEP_S5H1432, 0);
}
static inline void cx231xx_set_model(struct cx231xx *dev)
{
dev->board = cx231xx_boards[dev->model];
}
void cx231xx_pre_card_setup(struct cx231xx *dev)
{
dev_info(dev->dev, "Identified as %s (card=%d)\n",
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
static int read_eeprom(struct cx231xx *dev, struct i2c_client *client,
u8 *eedata, int len)
{
int ret = 0;
u8 start_offset = 0;
int len_todo = len;
u8 *eedata_cur = eedata;
int i;
struct i2c_msg msg_write = { .addr = client->addr, .flags = 0,
.buf = &start_offset, .len = 1 };
struct i2c_msg msg_read = { .addr = client->addr, .flags = I2C_M_RD };
ret = i2c_transfer(client->adapter, &msg_write, 1);
if (ret < 0) {
dev_err(dev->dev, "Can't read eeprom\n");
return ret;
}
while (len_todo > 0) {
msg_read.len = (len_todo > 64) ? 64 : len_todo;
msg_read.buf = eedata_cur;
ret = i2c_transfer(client->adapter, &msg_read, 1);
if (ret < 0) {
dev_err(dev->dev, "Can't read eeprom\n");
return ret;
}
eedata_cur += msg_read.len;
len_todo -= msg_read.len;
}
for (i = 0; i + 15 < len; i += 16)
dev_dbg(dev->dev, "i2c eeprom %02x: %*ph\n",
i, 16, &eedata[i]);
return 0;
}
void cx231xx_card_setup(struct cx231xx *dev)
{
cx231xx_set_model(dev);
dev->tuner_type = cx231xx_boards[dev->model].tuner_type;
if (cx231xx_boards[dev->model].tuner_addr)
dev->tuner_addr = cx231xx_boards[dev->model].tuner_addr;
if (dev->board.decoder == CX231XX_AVDECODER) {
dev->sd_cx25840 = v4l2_i2c_new_subdev(&dev->v4l2_dev,
cx231xx_get_i2c_adap(dev, I2C_0),
"cx25840", 0x88 >> 1, NULL);
if (dev->sd_cx25840 == NULL)
dev_err(dev->dev,
"cx25840 subdev registration failure\n");
cx25840_call(dev, core, load_fw);
}
if (dev->board.tuner_type != TUNER_ABSENT) {
struct i2c_adapter *tuner_i2c = cx231xx_get_i2c_adap(dev,
dev->board.tuner_i2c_master);
dev->sd_tuner = v4l2_i2c_new_subdev(&dev->v4l2_dev,
tuner_i2c,
"tuner",
dev->tuner_addr, NULL);
if (dev->sd_tuner == NULL)
dev_err(dev->dev,
"tuner subdev registration failure\n");
else
cx231xx_config_tuner(dev);
}
switch (dev->model) {
case CX231XX_BOARD_HAUPPAUGE_930C_HD_1113xx:
case CX231XX_BOARD_HAUPPAUGE_930C_HD_1114xx:
case CX231XX_BOARD_HAUPPAUGE_955Q:
{
struct eeprom {
struct tveeprom tvee;
u8 eeprom[256];
struct i2c_client client;
};
struct eeprom *e = kzalloc(sizeof(*e), GFP_KERNEL);
if (e == NULL) {
dev_err(dev->dev,
"failed to allocate memory to read eeprom\n");
break;
}
e->client.adapter = cx231xx_get_i2c_adap(dev, I2C_1_MUX_1);
e->client.addr = 0xa0 >> 1;
read_eeprom(dev, &e->client, e->eeprom, sizeof(e->eeprom));
tveeprom_hauppauge_analog(&e->tvee, e->eeprom + 0xc0);
kfree(e);
break;
}
}
}
int cx231xx_config(struct cx231xx *dev)
{
return 0;
}
void cx231xx_config_i2c(struct cx231xx *dev)
{
call_all(dev, video, s_stream, 1);
}
static void cx231xx_unregister_media_device(struct cx231xx *dev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
if (dev->media_dev) {
media_device_unregister(dev->media_dev);
media_device_cleanup(dev->media_dev);
kfree(dev->media_dev);
dev->media_dev = NULL;
}
#endif
}
void cx231xx_release_resources(struct cx231xx *dev)
{
cx231xx_ir_exit(dev);
cx231xx_release_analog_resources(dev);
cx231xx_remove_from_devlist(dev);
cx231xx_dev_uninit(dev);
v4l2_device_unregister(&dev->v4l2_dev);
cx231xx_unregister_media_device(dev);
usb_put_dev(dev->udev);
clear_bit(dev->devno, &cx231xx_devused);
}
static int cx231xx_media_device_init(struct cx231xx *dev,
struct usb_device *udev)
{
#ifdef CONFIG_MEDIA_CONTROLLER
struct media_device *mdev;
mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
if (!mdev)
return -ENOMEM;
media_device_usb_init(mdev, udev, dev->board.name);
dev->media_dev = mdev;
#endif
return 0;
}
static int cx231xx_init_dev(struct cx231xx *dev, struct usb_device *udev,
int minor)
{
int retval = -ENOMEM;
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
retval = initialize_cx231xx(dev);
if (retval < 0) {
dev_err(dev->dev, "Failed to read PCB config\n");
return retval;
}
if (dev->model == CX231XX_BOARD_CNXT_VIDEO_GRABBER ||
dev->model == CX231XX_BOARD_HAUPPAUGE_USBLIVE2) {
cx231xx_set_alt_setting(dev, INDEX_VIDEO, 3);
cx231xx_set_alt_setting(dev, INDEX_VANC, 1);
}
cx231xx_pre_card_setup(dev);
retval = cx231xx_config(dev);
if (retval) {
dev_err(dev->dev, "error configuring device\n");
return -ENOMEM;
}
dev->norm = dev->board.norm;
retval = cx231xx_dev_init(dev);
if (retval) {
dev_err(dev->dev,
"%s: cx231xx_i2c_register - errCode [%d]!\n",
__func__, retval);
goto err_dev_init;
}
cx231xx_card_setup(dev);
cx231xx_config_i2c(dev);
maxw = norm_maxw(dev);
maxh = norm_maxh(dev);
dev->width = maxw;
dev->height = maxh;
dev->interlaced = 0;
dev->video_input = 0;
retval = cx231xx_config(dev);
if (retval) {
dev_err(dev->dev, "%s: cx231xx_config - errCode [%d]!\n",
__func__, retval);
goto err_dev_init;
}
INIT_LIST_HEAD(&dev->video_mode.vidq.active);
INIT_LIST_HEAD(&dev->video_mode.vidq.queued);
INIT_LIST_HEAD(&dev->vbi_mode.vidq.active);
INIT_LIST_HEAD(&dev->vbi_mode.vidq.queued);
cx231xx_add_into_devlist(dev);
if (dev->board.has_417) {
dev_info(dev->dev, "attach 417 %d\n", dev->model);
if (cx231xx_417_register(dev) < 0) {
dev_err(dev->dev,
"%s() Failed to register 417 on VID_B\n",
__func__);
}
}
retval = cx231xx_register_analog_devices(dev);
if (retval)
goto err_analog;
cx231xx_ir_init(dev);
cx231xx_init_extension(dev);
return 0;
err_analog:
cx231xx_unregister_media_device(dev);
cx231xx_release_analog_resources(dev);
cx231xx_remove_from_devlist(dev);
err_dev_init:
cx231xx_dev_uninit(dev);
return retval;
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
flush_work(&dev->request_module_wk);
}
static int cx231xx_init_v4l2(struct cx231xx *dev,
struct usb_device *udev,
struct usb_interface *interface,
int isoc_pipe)
{
struct usb_interface *uif;
int i, idx;
idx = dev->current_pcb_config.hs_config_info[0].interface_info.video_index + 1;
if (idx >= dev->max_iad_interface_count) {
dev_err(dev->dev,
"Video PCB interface #%d doesn't exist\n", idx);
return -ENODEV;
}
uif = udev->actconfig->interface[idx];
if (uif->altsetting[0].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
dev->video_mode.end_point_addr = uif->altsetting[0].endpoint[isoc_pipe].desc.bEndpointAddress;
dev->video_mode.num_alt = uif->num_altsetting;
dev_info(dev->dev,
"video EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->video_mode.end_point_addr,
dev->video_mode.num_alt);
dev->video_mode.alt_max_pkt_size = devm_kmalloc_array(&udev->dev, 32, dev->video_mode.num_alt, GFP_KERNEL);
if (dev->video_mode.alt_max_pkt_size == NULL)
return -ENOMEM;
for (i = 0; i < dev->video_mode.num_alt; i++) {
u16 tmp;
if (uif->altsetting[i].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
tmp = le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].desc.wMaxPacketSize);
dev->video_mode.alt_max_pkt_size[i] = (tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
dev_dbg(dev->dev,
"Alternate setting %i, max size= %i\n", i,
dev->video_mode.alt_max_pkt_size[i]);
}
idx = dev->current_pcb_config.hs_config_info[0].interface_info.vanc_index + 1;
if (idx >= dev->max_iad_interface_count) {
dev_err(dev->dev,
"VBI PCB interface #%d doesn't exist\n", idx);
return -ENODEV;
}
uif = udev->actconfig->interface[idx];
if (uif->altsetting[0].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
dev->vbi_mode.end_point_addr =
uif->altsetting[0].endpoint[isoc_pipe].desc.
bEndpointAddress;
dev->vbi_mode.num_alt = uif->num_altsetting;
dev_info(dev->dev,
"VBI EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->vbi_mode.end_point_addr,
dev->vbi_mode.num_alt);
dev->vbi_mode.alt_max_pkt_size = devm_kmalloc_array(&udev->dev, 32, dev->vbi_mode.num_alt, GFP_KERNEL);
if (dev->vbi_mode.alt_max_pkt_size == NULL)
return -ENOMEM;
for (i = 0; i < dev->vbi_mode.num_alt; i++) {
u16 tmp;
if (uif->altsetting[i].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
tmp = le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].
desc.wMaxPacketSize);
dev->vbi_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
dev_dbg(dev->dev,
"Alternate setting %i, max size= %i\n", i,
dev->vbi_mode.alt_max_pkt_size[i]);
}
idx = dev->current_pcb_config.hs_config_info[0].interface_info.hanc_index + 1;
if (idx >= dev->max_iad_interface_count) {
dev_err(dev->dev,
"Sliced CC PCB interface #%d doesn't exist\n", idx);
return -ENODEV;
}
uif = udev->actconfig->interface[idx];
if (uif->altsetting[0].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
dev->sliced_cc_mode.end_point_addr =
uif->altsetting[0].endpoint[isoc_pipe].desc.
bEndpointAddress;
dev->sliced_cc_mode.num_alt = uif->num_altsetting;
dev_info(dev->dev,
"sliced CC EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->sliced_cc_mode.end_point_addr,
dev->sliced_cc_mode.num_alt);
dev->sliced_cc_mode.alt_max_pkt_size = devm_kmalloc_array(&udev->dev, 32, dev->sliced_cc_mode.num_alt, GFP_KERNEL);
if (dev->sliced_cc_mode.alt_max_pkt_size == NULL)
return -ENOMEM;
for (i = 0; i < dev->sliced_cc_mode.num_alt; i++) {
u16 tmp;
if (uif->altsetting[i].desc.bNumEndpoints < isoc_pipe + 1)
return -ENODEV;
tmp = le16_to_cpu(uif->altsetting[i].endpoint[isoc_pipe].
desc.wMaxPacketSize);
dev->sliced_cc_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
dev_dbg(dev->dev,
"Alternate setting %i, max size= %i\n", i,
dev->sliced_cc_mode.alt_max_pkt_size[i]);
}
return 0;
}
static int cx231xx_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev;
struct device *d = &interface->dev;
struct usb_interface *uif;
struct cx231xx *dev = NULL;
int retval = -ENODEV;
int nr = 0, ifnum;
int i, isoc_pipe = 0;
char *speed;
u8 idx;
struct usb_interface_assoc_descriptor *assoc_desc;
ifnum = interface->altsetting[0].desc.bInterfaceNumber;
if (ifnum != 1)
return -ENODEV;
do {
nr = find_first_zero_bit(&cx231xx_devused, CX231XX_MAXBOARDS);
if (nr >= CX231XX_MAXBOARDS) {
dev_err(d,
"Supports only %i devices.\n",
CX231XX_MAXBOARDS);
return -ENOMEM;
}
} while (test_and_set_bit(nr, &cx231xx_devused));
udev = usb_get_dev(interface_to_usbdev(interface));
dev = devm_kzalloc(&udev->dev, sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
retval = -ENOMEM;
goto err_if;
}
snprintf(dev->name, 29, "cx231xx #%d", nr);
dev->devno = nr;
dev->model = id->driver_info;
dev->video_mode.alt = -1;
dev->dev = d;
cx231xx_set_model(dev);
dev->interface_count++;
dev->gpio_dir = 0;
dev->gpio_val = 0;
dev->xc_fw_load_done = 0;
dev->has_alsa_audio = 1;
dev->power_mode = -1;
atomic_set(&dev->devlist_count, 0);
dev->vbi_or_sliced_cc_mode = 0;
dev->max_iad_interface_count = udev->config->desc.bNumInterfaces;
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
dev_info(d,
"New device %s %s @ %s Mbps (%04x:%04x) with %d interfaces\n",
udev->manufacturer ? udev->manufacturer : "",
udev->product ? udev->product : "",
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
dev->max_iad_interface_count);
dev->interface_count++;
nr = dev->devno;
assoc_desc = udev->actconfig->intf_assoc[0];
if (assoc_desc->bFirstInterface != ifnum) {
dev_err(d, "Not found matching IAD interface\n");
retval = -ENODEV;
goto err_if;
}
dev_dbg(d, "registering interface %d\n", ifnum);
usb_set_intfdata(interface, dev);
retval = cx231xx_media_device_init(dev, udev);
if (retval) {
dev_err(d, "cx231xx_media_device_init failed\n");
goto err_media_init;
}
#ifdef CONFIG_MEDIA_CONTROLLER
dev->v4l2_dev.mdev = dev->media_dev;
#endif
retval = v4l2_device_register(&interface->dev, &dev->v4l2_dev);
if (retval) {
dev_err(d, "v4l2_device_register failed\n");
goto err_v4l2;
}
retval = cx231xx_init_dev(dev, udev, nr);
if (retval)
goto err_init;
retval = cx231xx_init_v4l2(dev, udev, interface, isoc_pipe);
if (retval)
goto err_init;
if (dev->current_pcb_config.ts1_source != 0xff) {
idx = dev->current_pcb_config.hs_config_info[0].interface_info.ts1_index + 1;
if (idx >= dev->max_iad_interface_count) {
dev_err(d, "TS1 PCB interface #%d doesn't exist\n",
idx);
retval = -ENODEV;
goto err_video_alt;
}
uif = udev->actconfig->interface[idx];
if (uif->altsetting[0].desc.bNumEndpoints < isoc_pipe + 1) {
retval = -ENODEV;
goto err_video_alt;
}
dev->ts1_mode.end_point_addr =
uif->altsetting[0].endpoint[isoc_pipe].
desc.bEndpointAddress;
dev->ts1_mode.num_alt = uif->num_altsetting;
dev_info(d,
"TS EndPoint Addr 0x%x, Alternate settings: %i\n",
dev->ts1_mode.end_point_addr,
dev->ts1_mode.num_alt);
dev->ts1_mode.alt_max_pkt_size = devm_kmalloc_array(&udev->dev, 32, dev->ts1_mode.num_alt, GFP_KERNEL);
if (dev->ts1_mode.alt_max_pkt_size == NULL) {
retval = -ENOMEM;
goto err_video_alt;
}
for (i = 0; i < dev->ts1_mode.num_alt; i++) {
u16 tmp;
if (uif->altsetting[i].desc.bNumEndpoints < isoc_pipe + 1) {
retval = -ENODEV;
goto err_video_alt;
}
tmp = le16_to_cpu(uif->altsetting[i].
endpoint[isoc_pipe].desc.
wMaxPacketSize);
dev->ts1_mode.alt_max_pkt_size[i] =
(tmp & 0x07ff) * (((tmp & 0x1800) >> 11) + 1);
dev_dbg(d, "Alternate setting %i, max size= %i\n",
i, dev->ts1_mode.alt_max_pkt_size[i]);
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
#ifdef CONFIG_MEDIA_CONTROLLER
cx231xx_v4l2_create_entities(dev);
retval = v4l2_mc_create_media_graph(dev->media_dev);
if (!retval)
retval = media_device_register(dev->media_dev);
#endif
if (retval < 0)
cx231xx_release_resources(dev);
return retval;
err_video_alt:
cx231xx_close_extension(dev);
cx231xx_ir_exit(dev);
cx231xx_release_analog_resources(dev);
cx231xx_417_unregister(dev);
cx231xx_remove_from_devlist(dev);
cx231xx_dev_uninit(dev);
err_init:
v4l2_device_unregister(&dev->v4l2_dev);
err_v4l2:
cx231xx_unregister_media_device(dev);
err_media_init:
usb_set_intfdata(interface, NULL);
err_if:
usb_put_dev(udev);
clear_bit(nr, &cx231xx_devused);
return retval;
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
dev->state |= DEV_DISCONNECTED;
flush_request_modules(dev);
mutex_lock(&dev->lock);
wake_up_interruptible_all(&dev->open);
if (dev->users) {
dev_warn(dev->dev,
"device %s is open! Deregistration and memory deallocation are deferred on close.\n",
video_device_node_name(&dev->vdev));
cx231xx_ir_exit(dev);
if (dev->USE_ISO)
cx231xx_uninit_isoc(dev);
else
cx231xx_uninit_bulk(dev);
wake_up_interruptible(&dev->wait_frame);
wake_up_interruptible(&dev->wait_stream);
} else {
}
cx231xx_close_extension(dev);
mutex_unlock(&dev->lock);
if (!dev->users)
cx231xx_release_resources(dev);
}
