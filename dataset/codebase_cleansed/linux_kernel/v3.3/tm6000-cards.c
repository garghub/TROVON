void tm6000_flash_led(struct tm6000_core *dev, u8 state)
{
if (!dev->gpio.power_led)
return;
if (state) {
switch (dev->model) {
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x00);
break;
case TM6010_BOARD_BEHOLD_WANDER:
case TM6010_BOARD_BEHOLD_VOYAGER:
case TM6010_BOARD_BEHOLD_WANDER_LITE:
case TM6010_BOARD_BEHOLD_VOYAGER_LITE:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x01);
break;
}
}
else {
switch (dev->model) {
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x01);
break;
case TM6010_BOARD_BEHOLD_WANDER:
case TM6010_BOARD_BEHOLD_VOYAGER:
case TM6010_BOARD_BEHOLD_WANDER_LITE:
case TM6010_BOARD_BEHOLD_VOYAGER_LITE:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x00);
break;
}
}
}
int tm6000_xc5000_callback(void *ptr, int component, int command, int arg)
{
int rc = 0;
struct tm6000_core *dev = ptr;
if (dev->tuner_type != TUNER_XC5000)
return 0;
switch (command) {
case XC5000_TUNER_RESET:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x00);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
break;
}
return rc;
}
int tm6000_tuner_callback(void *ptr, int component, int command, int arg)
{
int rc = 0;
struct tm6000_core *dev = ptr;
if (dev->tuner_type != TUNER_XC2028)
return 0;
switch (command) {
case XC2028_RESET_CLK:
tm6000_ir_wait(dev, 0);
tm6000_set_reg(dev, REQ_04_EN_DISABLE_MCU_INT,
0x02, arg);
msleep(10);
rc = tm6000_i2c_reset(dev, 10);
break;
case XC2028_TUNER_RESET:
switch (arg) {
case 0:
switch (dev->model) {
case TM5600_BOARD_10MOONS_UT821:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
0x300, 0x01);
msleep(10);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x00);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
0x300, 0x00);
msleep(10);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
0x300, 0x01);
break;
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
msleep(60);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x00);
msleep(75);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
msleep(60);
break;
default:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x00);
msleep(130);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
msleep(130);
break;
}
tm6000_ir_wait(dev, 1);
break;
case 1:
tm6000_set_reg(dev, REQ_04_EN_DISABLE_MCU_INT,
0x02, 0x01);
msleep(10);
break;
case 2:
rc = tm6000_i2c_reset(dev, 100);
break;
}
break;
case XC2028_I2C_FLUSH:
tm6000_set_reg(dev, REQ_50_SET_START, 0, 0);
tm6000_set_reg(dev, REQ_51_SET_STOP, 0, 0);
break;
}
return rc;
}
int tm6000_cards_setup(struct tm6000_core *dev)
{
switch (dev->model) {
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
case TM6010_BOARD_GENERIC:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.tuner_on, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_on, 0x00);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_reset, 0x00);
msleep(50);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_reset, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_on, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.ir, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.power_led, 0x00);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.dvb_led, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_on, 0x00);
msleep(15);
break;
case TM6010_BOARD_BEHOLD_WANDER:
case TM6010_BOARD_BEHOLD_WANDER_LITE:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.power_led, 0x01);
msleep(15);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_reset, 0x00);
msleep(50);
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.demod_reset, 0x01);
msleep(15);
break;
case TM6010_BOARD_BEHOLD_VOYAGER:
case TM6010_BOARD_BEHOLD_VOYAGER_LITE:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN, dev->gpio.power_led, 0x01);
msleep(15);
break;
default:
break;
}
if (dev->gpio.tuner_reset) {
int rc;
int i;
for (i = 0; i < 2; i++) {
rc = tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x00);
if (rc < 0) {
printk(KERN_ERR "Error %i doing tuner reset\n", rc);
return rc;
}
msleep(10);
rc = tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.tuner_reset, 0x01);
if (rc < 0) {
printk(KERN_ERR "Error %i doing tuner reset\n", rc);
return rc;
}
}
} else {
printk(KERN_ERR "Tuner reset is not configured\n");
return -1;
}
msleep(50);
return 0;
}
static void tm6000_config_tuner(struct tm6000_core *dev)
{
struct tuner_setup tun_setup;
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tuner", dev->tuner_addr, NULL);
memset(&tun_setup, 0, sizeof(tun_setup));
tun_setup.type = dev->tuner_type;
tun_setup.addr = dev->tuner_addr;
tun_setup.mode_mask = 0;
if (dev->caps.has_tuner)
tun_setup.mode_mask |= (T_ANALOG_TV | T_RADIO);
switch (dev->tuner_type) {
case TUNER_XC2028:
tun_setup.tuner_callback = tm6000_tuner_callback;
break;
case TUNER_XC5000:
tun_setup.tuner_callback = tm6000_xc5000_callback;
break;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_type_addr, &tun_setup);
switch (dev->tuner_type) {
case TUNER_XC2028: {
struct v4l2_priv_tun_config xc2028_cfg;
struct xc2028_ctrl ctl;
memset(&xc2028_cfg, 0, sizeof(xc2028_cfg));
memset(&ctl, 0, sizeof(ctl));
ctl.demod = XC3028_FE_ZARLINK456;
xc2028_cfg.tuner = TUNER_XC2028;
xc2028_cfg.priv = &ctl;
switch (dev->model) {
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
ctl.max_len = 80;
ctl.fname = "xc3028L-v36.fw";
break;
default:
if (dev->dev_type == TM6010)
ctl.fname = "xc3028-v27.fw";
else
ctl.fname = "xc3028-v24.fw";
}
printk(KERN_INFO "Setting firmware parameters for xc2028\n");
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_config,
&xc2028_cfg);
}
break;
case TUNER_XC5000:
{
struct v4l2_priv_tun_config xc5000_cfg;
struct xc5000_config ctl = {
.i2c_address = dev->tuner_addr,
.if_khz = 4570,
.radio_input = XC5000_RADIO_FM1_MONO,
};
xc5000_cfg.tuner = TUNER_XC5000;
xc5000_cfg.priv = &ctl;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_config,
&xc5000_cfg);
}
break;
default:
printk(KERN_INFO "Unknown tuner type. Tuner is not configured.\n");
break;
}
}
static int fill_board_specific_data(struct tm6000_core *dev)
{
int rc;
dev->dev_type = tm6000_boards[dev->model].type;
dev->tuner_type = tm6000_boards[dev->model].tuner_type;
dev->tuner_addr = tm6000_boards[dev->model].tuner_addr;
dev->gpio = tm6000_boards[dev->model].gpio;
dev->ir_codes = tm6000_boards[dev->model].ir_codes;
dev->demod_addr = tm6000_boards[dev->model].demod_addr;
dev->caps = tm6000_boards[dev->model].caps;
dev->vinput[0] = tm6000_boards[dev->model].vinput[0];
dev->vinput[1] = tm6000_boards[dev->model].vinput[1];
dev->vinput[2] = tm6000_boards[dev->model].vinput[2];
dev->rinput = tm6000_boards[dev->model].rinput;
switch (dev->model) {
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_HAUPPAUGE_900H:
dev->quirks |= TM6000_QUIRK_NO_USB_DELAY;
break;
default:
break;
}
rc = tm6000_init(dev);
if (rc < 0)
return rc;
return v4l2_device_register(&dev->udev->dev, &dev->v4l2_dev);
}
static void use_alternative_detection_method(struct tm6000_core *dev)
{
int i, model = -1;
if (!dev->eedata_size)
return;
for (i = 0; i < ARRAY_SIZE(tm6000_boards); i++) {
if (!tm6000_boards[i].eename_size)
continue;
if (dev->eedata_size < tm6000_boards[i].eename_pos +
tm6000_boards[i].eename_size)
continue;
if (!memcmp(&dev->eedata[tm6000_boards[i].eename_pos],
tm6000_boards[i].eename,
tm6000_boards[i].eename_size)) {
model = i;
break;
}
}
if (model < 0) {
printk(KERN_INFO "Device has eeprom but is currently unknown\n");
return;
}
dev->model = model;
printk(KERN_INFO "Device identified via eeprom as %s (type = %d)\n",
tm6000_boards[model].name, model);
}
static void request_module_async(struct work_struct *work)
{
struct tm6000_core *dev = container_of(work, struct tm6000_core,
request_module_wk);
request_module("tm6000-alsa");
if (dev->caps.has_dvb)
request_module("tm6000-dvb");
}
static void request_modules(struct tm6000_core *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct tm6000_core *dev)
{
flush_work_sync(&dev->request_module_wk);
}
static int tm6000_init_dev(struct tm6000_core *dev)
{
struct v4l2_frequency f;
int rc = 0;
mutex_init(&dev->lock);
mutex_lock(&dev->lock);
if (!is_generic(dev->model)) {
rc = fill_board_specific_data(dev);
if (rc < 0)
goto err;
rc = tm6000_i2c_register(dev);
if (rc < 0)
goto err;
} else {
rc = tm6000_i2c_register(dev);
if (rc < 0)
goto err;
use_alternative_detection_method(dev);
rc = fill_board_specific_data(dev);
if (rc < 0)
goto err;
}
dev->width = 720;
dev->height = 480;
dev->norm = V4L2_STD_PAL_M;
tm6000_config_tuner(dev);
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_std, dev->norm);
f.tuner = 0;
f.type = V4L2_TUNER_ANALOG_TV;
f.frequency = 3092;
dev->freq = f.frequency;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, &f);
if (dev->caps.has_tda9874)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tvaudio", I2C_ADDR_TDA9874, NULL);
rc = tm6000_v4l2_register(dev);
if (rc < 0)
goto err;
tm6000_add_into_devlist(dev);
tm6000_init_extension(dev);
tm6000_ir_init(dev);
request_modules(dev);
mutex_unlock(&dev->lock);
return 0;
err:
mutex_unlock(&dev->lock);
return rc;
}
static void get_max_endpoint(struct usb_device *udev,
struct usb_host_interface *alt,
char *msgtype,
struct usb_host_endpoint *curr_e,
struct tm6000_endpoint *tm_ep)
{
u16 tmp = le16_to_cpu(curr_e->desc.wMaxPacketSize);
unsigned int size = tmp & 0x7ff;
if (udev->speed == USB_SPEED_HIGH)
size = size * hb_mult(tmp);
if (size > tm_ep->maxsize) {
tm_ep->endp = curr_e;
tm_ep->maxsize = size;
tm_ep->bInterfaceNumber = alt->desc.bInterfaceNumber;
tm_ep->bAlternateSetting = alt->desc.bAlternateSetting;
printk(KERN_INFO "tm6000: %s endpoint: 0x%02x (max size=%u bytes)\n",
msgtype, curr_e->desc.bEndpointAddress,
size);
}
}
static int tm6000_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usbdev;
struct tm6000_core *dev = NULL;
int i, rc = 0;
int nr = 0;
char *speed;
usbdev = usb_get_dev(interface_to_usbdev(interface));
rc = usb_set_interface(usbdev, 0, 1);
if (rc < 0)
goto err;
nr = find_first_zero_bit(&tm6000_devused, TM6000_MAXBOARDS);
if (nr >= TM6000_MAXBOARDS) {
printk(KERN_ERR "tm6000: Supports only %i tm60xx boards.\n", TM6000_MAXBOARDS);
usb_put_dev(usbdev);
return -ENOMEM;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
printk(KERN_ERR "tm6000" ": out of memory!\n");
usb_put_dev(usbdev);
return -ENOMEM;
}
spin_lock_init(&dev->slock);
mutex_init(&dev->usb_lock);
set_bit(nr, &tm6000_devused);
snprintf(dev->name, 29, "tm6000 #%d", nr);
dev->model = id->driver_info;
if (card[nr] < ARRAY_SIZE(tm6000_boards))
dev->model = card[nr];
dev->udev = usbdev;
dev->devno = nr;
switch (usbdev->speed) {
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
for (i = 0; i < interface->num_altsetting; i++) {
int ep;
for (ep = 0; ep < interface->altsetting[i].desc.bNumEndpoints; ep++) {
struct usb_host_endpoint *e;
int dir_out;
e = &interface->altsetting[i].endpoint[ep];
dir_out = ((e->desc.bEndpointAddress &
USB_ENDPOINT_DIR_MASK) == USB_DIR_OUT);
printk(KERN_INFO "tm6000: alt %d, interface %i, class %i\n",
i,
interface->altsetting[i].desc.bInterfaceNumber,
interface->altsetting[i].desc.bInterfaceClass);
switch (e->desc.bmAttributes) {
case USB_ENDPOINT_XFER_BULK:
if (!dir_out) {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"Bulk IN", e,
&dev->bulk_in);
} else {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"Bulk OUT", e,
&dev->bulk_out);
}
break;
case USB_ENDPOINT_XFER_ISOC:
if (!dir_out) {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"ISOC IN", e,
&dev->isoc_in);
} else {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"ISOC OUT", e,
&dev->isoc_out);
}
break;
case USB_ENDPOINT_XFER_INT:
if (!dir_out) {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"INT IN", e,
&dev->int_in);
} else {
get_max_endpoint(usbdev,
&interface->altsetting[i],
"INT OUT", e,
&dev->int_out);
}
break;
}
}
}
printk(KERN_INFO "tm6000: New video device @ %s Mbps (%04x:%04x, ifnum %d)\n",
speed,
le16_to_cpu(dev->udev->descriptor.idVendor),
le16_to_cpu(dev->udev->descriptor.idProduct),
interface->altsetting->desc.bInterfaceNumber);
if (!dev->isoc_in.endp) {
printk(KERN_ERR "tm6000: probing error: no IN ISOC endpoint!\n");
rc = -ENODEV;
goto err;
}
usb_set_intfdata(interface, dev);
printk(KERN_INFO "tm6000: Found %s\n", tm6000_boards[dev->model].name);
rc = tm6000_init_dev(dev);
if (rc < 0)
goto err;
return 0;
err:
printk(KERN_ERR "tm6000: Error %d while registering\n", rc);
clear_bit(nr, &tm6000_devused);
usb_put_dev(usbdev);
kfree(dev);
return rc;
}
static void tm6000_usb_disconnect(struct usb_interface *interface)
{
struct tm6000_core *dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (!dev)
return;
printk(KERN_INFO "tm6000: disconnecting %s\n", dev->name);
flush_request_modules(dev);
tm6000_ir_fini(dev);
if (dev->gpio.power_led) {
switch (dev->model) {
case TM6010_BOARD_HAUPPAUGE_900H:
case TM6010_BOARD_TERRATEC_CINERGY_HYBRID_XE:
case TM6010_BOARD_TWINHAN_TU501:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x01);
msleep(15);
break;
case TM6010_BOARD_BEHOLD_WANDER:
case TM6010_BOARD_BEHOLD_VOYAGER:
case TM6010_BOARD_BEHOLD_WANDER_LITE:
case TM6010_BOARD_BEHOLD_VOYAGER_LITE:
tm6000_set_reg(dev, REQ_03_SET_GET_MCU_PIN,
dev->gpio.power_led, 0x00);
msleep(15);
break;
}
}
tm6000_v4l2_unregister(dev);
tm6000_i2c_unregister(dev);
v4l2_device_unregister(&dev->v4l2_dev);
dev->state |= DEV_DISCONNECTED;
usb_put_dev(dev->udev);
tm6000_close_extension(dev);
tm6000_remove_from_devlist(dev);
clear_bit(dev->devno, &tm6000_devused);
kfree(dev);
}
