int em28xx_tuner_callback(void *ptr, int component, int command, int arg)
{
struct em28xx_i2c_bus *i2c_bus = ptr;
struct em28xx *dev = i2c_bus->dev;
int rc = 0;
if (dev->tuner_type != TUNER_XC2028 && dev->tuner_type != TUNER_XC5000)
return 0;
if (command != XC2028_TUNER_RESET && command != XC5000_TUNER_RESET)
return 0;
rc = em28xx_gpio_set(dev, dev->board.tuner_gpio);
return rc;
}
static inline void em28xx_set_model(struct em28xx *dev)
{
dev->board = em28xx_boards[dev->model];
if (!dev->board.xclk)
dev->board.xclk = EM28XX_XCLK_IR_RC5_MODE |
EM28XX_XCLK_FREQUENCY_12MHZ;
if (!dev->board.i2c_speed)
dev->board.i2c_speed = EM28XX_I2C_CLK_WAIT_ENABLE |
EM28XX_I2C_FREQ_100_KHZ;
dev->def_i2c_bus = dev->board.def_i2c_bus;
}
static void em28xx_pre_card_setup(struct em28xx *dev)
{
em28xx_write_reg(dev, EM28XX_R0F_XCLK, dev->board.xclk & 0x7f);
if (!dev->board.is_em2800)
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, dev->board.i2c_speed);
msleep(50);
switch (dev->model) {
case EM2861_BOARD_PLEXTOR_PX_TV100U:
dev->i2s_speed = 2048000;
break;
case EM2861_BOARD_KWORLD_PVRTV_300U:
case EM2880_BOARD_KWORLD_DVB_305U:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0x6d);
msleep(10);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0x7d);
msleep(10);
break;
case EM2870_BOARD_COMPRO_VIDEOMATE:
em28xx_write_reg(dev, EM2880_R04_GPO, 0x00);
msleep(10);
em28xx_write_reg(dev, EM2880_R04_GPO, 0x01);
msleep(10);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfd);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfc);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xdc);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfc);
mdelay(70);
break;
case EM2870_BOARD_TERRATEC_XS_MT2060:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xde);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
mdelay(70);
break;
case EM2870_BOARD_PINNACLE_PCTV_DVB:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xde);
mdelay(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
mdelay(70);
break;
case EM2820_BOARD_GADMEI_UTV310:
case EM2820_BOARD_MSI_VOX_USB_2:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfd);
break;
case EM2882_BOARD_KWORLD_ATSC_315U:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xff);
msleep(10);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
msleep(10);
em28xx_write_reg(dev, EM2880_R04_GPO, 0x00);
msleep(10);
em28xx_write_reg(dev, EM2880_R04_GPO, 0x08);
msleep(10);
break;
case EM2860_BOARD_KAIOMY_TVNPC_U2:
em28xx_write_regs(dev, EM28XX_R0F_XCLK, "\x07", 1);
em28xx_write_regs(dev, EM28XX_R06_I2C_CLK, "\x40", 1);
em28xx_write_regs(dev, 0x0d, "\x42", 1);
em28xx_write_regs(dev, 0x08, "\xfd", 1);
msleep(10);
em28xx_write_regs(dev, 0x08, "\xff", 1);
msleep(10);
em28xx_write_regs(dev, 0x08, "\x7f", 1);
msleep(10);
em28xx_write_regs(dev, 0x08, "\x6b", 1);
break;
case EM2860_BOARD_EASYCAP:
em28xx_write_regs(dev, 0x08, "\xf8", 1);
break;
case EM2820_BOARD_IODATA_GVMVP_SZ:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xff);
msleep(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xf7);
msleep(10);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfe);
msleep(70);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfd);
msleep(70);
break;
}
em28xx_gpio_set(dev, dev->board.tuner_gpio);
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
em28xx_set_mode(dev, EM28XX_SUSPEND);
}
static int em28xx_hint_board(struct em28xx *dev)
{
int i;
if (dev->board.is_webcam) {
if (dev->em28xx_sensor == EM28XX_MT9V011) {
dev->model = EM2820_BOARD_SILVERCREST_WEBCAM;
} else if (dev->em28xx_sensor == EM28XX_MT9M001 ||
dev->em28xx_sensor == EM28XX_MT9M111) {
dev->model = EM2750_BOARD_UNKNOWN;
}
return 0;
}
for (i = 0; i < ARRAY_SIZE(em28xx_eeprom_hash); i++) {
if (dev->hash == em28xx_eeprom_hash[i].hash) {
dev->model = em28xx_eeprom_hash[i].model;
dev->tuner_type = em28xx_eeprom_hash[i].tuner;
em28xx_errdev("Your board has no unique USB ID.\n");
em28xx_errdev("A hint were successfully done, "
"based on eeprom hash.\n");
em28xx_errdev("This method is not 100%% failproof.\n");
em28xx_errdev("If the board were missdetected, "
"please email this log to:\n");
em28xx_errdev("\tV4L Mailing List "
" <linux-media@vger.kernel.org>\n");
em28xx_errdev("Board detected as %s\n",
em28xx_boards[dev->model].name);
return 0;
}
}
if (!dev->i2c_hash)
em28xx_do_i2c_scan(dev, dev->def_i2c_bus);
for (i = 0; i < ARRAY_SIZE(em28xx_i2c_hash); i++) {
if (dev->i2c_hash == em28xx_i2c_hash[i].hash) {
dev->model = em28xx_i2c_hash[i].model;
dev->tuner_type = em28xx_i2c_hash[i].tuner;
em28xx_errdev("Your board has no unique USB ID.\n");
em28xx_errdev("A hint were successfully done, "
"based on i2c devicelist hash.\n");
em28xx_errdev("This method is not 100%% failproof.\n");
em28xx_errdev("If the board were missdetected, "
"please email this log to:\n");
em28xx_errdev("\tV4L Mailing List "
" <linux-media@vger.kernel.org>\n");
em28xx_errdev("Board detected as %s\n",
em28xx_boards[dev->model].name);
return 0;
}
}
em28xx_errdev("Your board has no unique USB ID and thus need a "
"hint to be detected.\n");
em28xx_errdev("You may try to use card=<n> insmod option to "
"workaround that.\n");
em28xx_errdev("Please send an email with this log to:\n");
em28xx_errdev("\tV4L Mailing List <linux-media@vger.kernel.org>\n");
em28xx_errdev("Board eeprom hash is 0x%08lx\n", dev->hash);
em28xx_errdev("Board i2c devicelist hash is 0x%08lx\n", dev->i2c_hash);
em28xx_errdev("Here is a list of valid choices for the card=<n>"
" insmod option:\n");
for (i = 0; i < em28xx_bcount; i++) {
em28xx_errdev(" card=%d -> %s\n",
i, em28xx_boards[i].name);
}
return -1;
}
static void em28xx_card_setup(struct em28xx *dev)
{
if (dev->board.is_webcam) {
if (em28xx_detect_sensor(dev) < 0)
dev->board.is_webcam = 0;
}
switch (dev->model) {
case EM2750_BOARD_UNKNOWN:
case EM2820_BOARD_UNKNOWN:
case EM2800_BOARD_UNKNOWN:
if (em28xx_hint_board(dev) < 0)
em28xx_errdev("Board not discovered\n");
else {
em28xx_set_model(dev);
em28xx_pre_card_setup(dev);
}
break;
default:
em28xx_set_model(dev);
}
em28xx_info("Identified as %s (card=%d)\n",
dev->board.name, dev->model);
dev->tuner_type = em28xx_boards[dev->model].tuner_type;
switch (dev->model) {
case EM2820_BOARD_HAUPPAUGE_WINTV_USB_2:
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900:
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900_R2:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_850:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_950:
case EM2884_BOARD_HAUPPAUGE_WINTV_HVR_930C:
{
struct tveeprom tv;
if (dev->eedata == NULL)
break;
#if defined(CONFIG_MODULES) && defined(MODULE)
request_module("tveeprom");
#endif
dev->i2c_client[dev->def_i2c_bus].addr = 0xa0 >> 1;
tveeprom_hauppauge_analog(&dev->i2c_client[dev->def_i2c_bus], &tv, dev->eedata);
dev->tuner_type = tv.tuner_type;
if (tv.audio_processor == TVEEPROM_AUDPROC_MSP) {
dev->i2s_speed = 2048000;
dev->board.has_msp34xx = 1;
}
break;
}
case EM2882_BOARD_KWORLD_ATSC_315U:
em28xx_write_reg(dev, 0x0d, 0x42);
msleep(10);
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xfd);
msleep(10);
break;
case EM2820_BOARD_KWORLD_PVRTV2800RF:
em28xx_write_reg(dev, EM2820_R08_GPIO_CTRL, 0xf9);
break;
case EM2820_BOARD_UNKNOWN:
case EM2800_BOARD_UNKNOWN:
case EM2880_BOARD_MSI_DIGIVOX_AD:
if (!em28xx_hint_board(dev))
em28xx_set_model(dev);
em28xx_gpio_set(dev, dev->board.tuner_gpio);
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
break;
case EM2882_BOARD_KWORLD_VS_DVBT:
if (!em28xx_hint_board(dev))
em28xx_set_model(dev);
em28xx_gpio_set(dev, dev->board.tuner_gpio);
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
break;
}
if (dev->board.valid == EM28XX_BOARD_NOT_VALIDATED) {
em28xx_errdev("\n\n");
em28xx_errdev("The support for this board weren't "
"valid yet.\n");
em28xx_errdev("Please send a report of having this working\n");
em28xx_errdev("not to V4L mailing list (and/or to other "
"addresses)\n\n");
}
kfree(dev->eedata);
dev->eedata = NULL;
if (tuner >= 0)
dev->tuner_type = tuner;
}
void em28xx_setup_xc3028(struct em28xx *dev, struct xc2028_ctrl *ctl)
{
memset(ctl, 0, sizeof(*ctl));
ctl->fname = XC2028_DEFAULT_FIRMWARE;
ctl->max_len = 64;
ctl->mts = em28xx_boards[dev->model].mts_firmware;
switch (dev->model) {
case EM2880_BOARD_EMPIRE_DUAL_TV:
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900:
case EM2882_BOARD_TERRATEC_HYBRID_XS:
ctl->demod = XC3028_FE_ZARLINK456;
break;
case EM2880_BOARD_TERRATEC_HYBRID_XS:
case EM2880_BOARD_TERRATEC_HYBRID_XS_FR:
case EM2881_BOARD_PINNACLE_HYBRID_PRO:
ctl->demod = XC3028_FE_ZARLINK456;
break;
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900_R2:
case EM2882_BOARD_PINNACLE_HYBRID_PRO_330E:
ctl->demod = XC3028_FE_DEFAULT;
break;
case EM2880_BOARD_AMD_ATI_TV_WONDER_HD_600:
ctl->demod = XC3028_FE_DEFAULT;
ctl->fname = XC3028L_DEFAULT_FIRMWARE;
break;
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_850:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_950:
case EM2880_BOARD_PINNACLE_PCTV_HD_PRO:
ctl->demod = XC3028_FE_DEFAULT;
break;
case EM2883_BOARD_KWORLD_HYBRID_330U:
case EM2882_BOARD_DIKOM_DK300:
case EM2882_BOARD_KWORLD_VS_DVBT:
ctl->demod = XC3028_FE_CHINA;
ctl->fname = XC2028_DEFAULT_FIRMWARE;
break;
case EM2882_BOARD_EVGA_INDTUBE:
ctl->demod = XC3028_FE_CHINA;
ctl->fname = XC3028L_DEFAULT_FIRMWARE;
break;
default:
ctl->demod = XC3028_FE_OREN538;
}
}
static void request_module_async(struct work_struct *work)
{
struct em28xx *dev = container_of(work,
struct em28xx, request_module_wk);
if (dev->is_audio_only) {
#if defined(CONFIG_MODULES) && defined(MODULE)
request_module("em28xx-alsa");
#endif
return;
}
em28xx_init_extension(dev);
#if defined(CONFIG_MODULES) && defined(MODULE)
if (dev->has_video)
request_module("em28xx-v4l");
if (dev->has_audio_class)
request_module("snd-usb-audio");
else if (dev->has_alsa_audio)
request_module("em28xx-alsa");
if (dev->board.has_dvb)
request_module("em28xx-dvb");
if (dev->board.buttons ||
((dev->board.ir_codes || dev->board.has_ir_i2c) && !disable_ir))
request_module("em28xx-rc");
#endif
}
static void request_modules(struct em28xx *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct em28xx *dev)
{
flush_work(&dev->request_module_wk);
}
static void em28xx_release_resources(struct em28xx *dev)
{
mutex_lock(&dev->lock);
if (dev->def_i2c_bus)
em28xx_i2c_unregister(dev, 1);
em28xx_i2c_unregister(dev, 0);
usb_put_dev(dev->udev);
clear_bit(dev->devno, em28xx_devused);
mutex_unlock(&dev->lock);
}
void em28xx_free_device(struct kref *ref)
{
struct em28xx *dev = kref_to_dev(ref);
em28xx_info("Freeing device\n");
if (!dev->disconnected)
em28xx_release_resources(dev);
kfree(dev->alt_max_pkt_size_isoc);
kfree(dev);
}
static int em28xx_init_dev(struct em28xx *dev, struct usb_device *udev,
struct usb_interface *interface,
int minor)
{
int retval;
static const char *default_chip_name = "em28xx";
const char *chip_name = default_chip_name;
dev->udev = udev;
mutex_init(&dev->ctrl_urb_lock);
spin_lock_init(&dev->slock);
dev->em28xx_write_regs = em28xx_write_regs;
dev->em28xx_read_reg = em28xx_read_reg;
dev->em28xx_read_reg_req_len = em28xx_read_reg_req_len;
dev->em28xx_write_regs_req = em28xx_write_regs_req;
dev->em28xx_read_reg_req = em28xx_read_reg_req;
dev->board.is_em2800 = em28xx_boards[dev->model].is_em2800;
em28xx_set_model(dev);
dev->wait_after_write = 5;
retval = em28xx_read_reg(dev, EM28XX_R0A_CHIPID);
if (retval > 0) {
dev->chip_id = retval;
switch (dev->chip_id) {
case CHIP_ID_EM2800:
chip_name = "em2800";
break;
case CHIP_ID_EM2710:
chip_name = "em2710";
break;
case CHIP_ID_EM2750:
chip_name = "em2750";
break;
case CHIP_ID_EM2765:
chip_name = "em2765";
dev->wait_after_write = 0;
dev->is_em25xx = 1;
dev->eeprom_addrwidth_16bit = 1;
break;
case CHIP_ID_EM2820:
chip_name = "em2710/2820";
if (le16_to_cpu(dev->udev->descriptor.idVendor)
== 0xeb1a) {
__le16 idProd = dev->udev->descriptor.idProduct;
if (le16_to_cpu(idProd) == 0x2710)
chip_name = "em2710";
else if (le16_to_cpu(idProd) == 0x2820)
chip_name = "em2820";
}
break;
case CHIP_ID_EM2840:
chip_name = "em2840";
break;
case CHIP_ID_EM2860:
chip_name = "em2860";
break;
case CHIP_ID_EM2870:
chip_name = "em2870";
dev->wait_after_write = 0;
break;
case CHIP_ID_EM2874:
chip_name = "em2874";
dev->wait_after_write = 0;
dev->eeprom_addrwidth_16bit = 1;
break;
case CHIP_ID_EM28174:
chip_name = "em28174";
dev->wait_after_write = 0;
dev->eeprom_addrwidth_16bit = 1;
break;
case CHIP_ID_EM28178:
chip_name = "em28178";
dev->wait_after_write = 0;
dev->eeprom_addrwidth_16bit = 1;
break;
case CHIP_ID_EM2883:
chip_name = "em2882/3";
dev->wait_after_write = 0;
break;
case CHIP_ID_EM2884:
chip_name = "em2884";
dev->wait_after_write = 0;
dev->eeprom_addrwidth_16bit = 1;
break;
default:
printk(KERN_INFO DRIVER_NAME
": unknown em28xx chip ID (%d)\n", dev->chip_id);
}
}
if (dev->chip_id == CHIP_ID_EM2870 ||
dev->chip_id == CHIP_ID_EM2874 ||
dev->chip_id == CHIP_ID_EM28174 ||
dev->chip_id == CHIP_ID_EM28178) {
dev->audio_mode.has_audio = false;
dev->has_audio_class = false;
dev->has_alsa_audio = false;
}
if (chip_name != default_chip_name)
printk(KERN_INFO DRIVER_NAME
": chip ID is %s\n", chip_name);
snprintf(dev->name, sizeof(dev->name), "%s #%d", chip_name, dev->devno);
if (dev->is_audio_only) {
retval = em28xx_audio_setup(dev);
if (retval)
return -ENODEV;
em28xx_init_extension(dev);
return 0;
}
em28xx_pre_card_setup(dev);
if (!dev->board.is_em2800) {
retval = em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, dev->board.i2c_speed);
if (retval < 0) {
em28xx_errdev("%s: em28xx_write_reg failed!"
" retval [%d]\n",
__func__, retval);
return retval;
}
}
rt_mutex_init(&dev->i2c_bus_lock);
if (dev->board.is_em2800)
retval = em28xx_i2c_register(dev, 0, EM28XX_I2C_ALGO_EM2800);
else
retval = em28xx_i2c_register(dev, 0, EM28XX_I2C_ALGO_EM28XX);
if (retval < 0) {
em28xx_errdev("%s: em28xx_i2c_register bus 0 - error [%d]!\n",
__func__, retval);
return retval;
}
if (dev->def_i2c_bus) {
if (dev->is_em25xx)
retval = em28xx_i2c_register(dev, 1,
EM28XX_I2C_ALGO_EM25XX_BUS_B);
else
retval = em28xx_i2c_register(dev, 1,
EM28XX_I2C_ALGO_EM28XX);
if (retval < 0) {
em28xx_errdev("%s: em28xx_i2c_register bus 1 - error [%d]!\n",
__func__, retval);
em28xx_i2c_unregister(dev, 0);
return retval;
}
}
em28xx_card_setup(dev);
return 0;
}
static int em28xx_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev;
struct em28xx *dev = NULL;
int retval;
bool has_audio = false, has_video = false, has_dvb = false;
int i, nr, try_bulk;
const int ifnum = interface->altsetting[0].desc.bInterfaceNumber;
char *speed;
udev = usb_get_dev(interface_to_usbdev(interface));
do {
nr = find_first_zero_bit(em28xx_devused, EM28XX_MAXBOARDS);
if (nr >= EM28XX_MAXBOARDS) {
printk(DRIVER_NAME ": Supports only %i em28xx boards.\n",
EM28XX_MAXBOARDS);
retval = -ENOMEM;
goto err_no_slot;
}
} while (test_and_set_bit(nr, em28xx_devused));
if (interface->altsetting[0].desc.bInterfaceClass == USB_CLASS_AUDIO) {
em28xx_err(DRIVER_NAME " audio device (%04x:%04x): "
"interface %i, class %i\n",
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting[0].desc.bInterfaceClass);
retval = -ENODEV;
goto err;
}
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (dev == NULL) {
em28xx_err(DRIVER_NAME ": out of memory!\n");
retval = -ENOMEM;
goto err;
}
dev->alt_max_pkt_size_isoc =
kmalloc(sizeof(dev->alt_max_pkt_size_isoc[0]) *
interface->num_altsetting, GFP_KERNEL);
if (dev->alt_max_pkt_size_isoc == NULL) {
em28xx_errdev("out of memory!\n");
kfree(dev);
retval = -ENOMEM;
goto err;
}
for (i = 0; i < interface->num_altsetting; i++) {
int ep;
for (ep = 0; ep < interface->altsetting[i].desc.bNumEndpoints; ep++) {
const struct usb_endpoint_descriptor *e;
int sizedescr, size;
e = &interface->altsetting[i].endpoint[ep].desc;
sizedescr = le16_to_cpu(e->wMaxPacketSize);
size = sizedescr & 0x7ff;
if (udev->speed == USB_SPEED_HIGH)
size = size * hb_mult(sizedescr);
if (usb_endpoint_dir_in(e)) {
switch (e->bEndpointAddress) {
case 0x82:
has_video = true;
if (usb_endpoint_xfer_isoc(e)) {
dev->analog_ep_isoc =
e->bEndpointAddress;
dev->alt_max_pkt_size_isoc[i] = size;
} else if (usb_endpoint_xfer_bulk(e)) {
dev->analog_ep_bulk =
e->bEndpointAddress;
}
break;
case 0x83:
if (usb_endpoint_xfer_isoc(e)) {
has_audio = true;
} else {
printk(KERN_INFO DRIVER_NAME
": error: skipping audio endpoint 0x83, because it uses bulk transfers !\n");
}
break;
case 0x84:
if (has_video &&
(usb_endpoint_xfer_bulk(e))) {
dev->analog_ep_bulk =
e->bEndpointAddress;
} else {
if (usb_endpoint_xfer_isoc(e)) {
if (size > dev->dvb_max_pkt_size_isoc) {
has_dvb = true;
dev->dvb_ep_isoc = e->bEndpointAddress;
dev->dvb_max_pkt_size_isoc = size;
dev->dvb_alt_isoc = i;
}
} else {
has_dvb = true;
dev->dvb_ep_bulk = e->bEndpointAddress;
}
}
break;
}
}
}
}
if (!(has_audio || has_video || has_dvb)) {
retval = -ENODEV;
goto err_free;
}
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
printk(KERN_INFO DRIVER_NAME
": New device %s %s @ %s Mbps "
"(%04x:%04x, interface %d, class %d)\n",
udev->manufacturer ? udev->manufacturer : "",
udev->product ? udev->product : "",
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber);
if (udev->speed != USB_SPEED_HIGH && disable_usb_speed_check == 0) {
printk(DRIVER_NAME ": Device initialization failed.\n");
printk(DRIVER_NAME ": Device must be connected to a high-speed"
" USB 2.0 port.\n");
retval = -ENODEV;
goto err_free;
}
dev->devno = nr;
dev->model = id->driver_info;
dev->alt = -1;
dev->is_audio_only = has_audio && !(has_video || has_dvb);
dev->has_alsa_audio = has_audio;
dev->audio_mode.has_audio = has_audio;
dev->has_video = has_video;
dev->ifnum = ifnum;
for (i = 0; i < udev->config->desc.bNumInterfaces; i++) {
struct usb_interface *uif = udev->config->interface[i];
if (uif->altsetting[0].desc.bInterfaceClass == USB_CLASS_AUDIO) {
dev->has_audio_class = 1;
break;
}
}
if (has_audio)
printk(KERN_INFO DRIVER_NAME
": Audio interface %i found %s\n",
ifnum,
dev->has_audio_class ? "(USB Audio Class)" : "(Vendor Class)");
if (has_video)
printk(KERN_INFO DRIVER_NAME
": Video interface %i found:%s%s\n",
ifnum,
dev->analog_ep_bulk ? " bulk" : "",
dev->analog_ep_isoc ? " isoc" : "");
if (has_dvb)
printk(KERN_INFO DRIVER_NAME
": DVB interface %i found:%s%s\n",
ifnum,
dev->dvb_ep_bulk ? " bulk" : "",
dev->dvb_ep_isoc ? " isoc" : "");
dev->num_alt = interface->num_altsetting;
if ((unsigned)card[nr] < em28xx_bcount)
dev->model = card[nr];
usb_set_intfdata(interface, dev);
mutex_init(&dev->lock);
retval = em28xx_init_dev(dev, udev, interface, nr);
if (retval) {
goto err_free;
}
if (usb_xfer_mode < 0) {
if (dev->board.is_webcam)
try_bulk = 1;
else
try_bulk = 0;
} else {
try_bulk = usb_xfer_mode > 0;
}
if (has_video) {
if (!dev->analog_ep_isoc || (try_bulk && dev->analog_ep_bulk))
dev->analog_xfer_bulk = 1;
em28xx_info("analog set to %s mode.\n",
dev->analog_xfer_bulk ? "bulk" : "isoc");
}
if (has_dvb) {
if (!dev->dvb_ep_isoc || (try_bulk && dev->dvb_ep_bulk))
dev->dvb_xfer_bulk = 1;
em28xx_info("dvb set to %s mode.\n",
dev->dvb_xfer_bulk ? "bulk" : "isoc");
}
kref_init(&dev->ref);
request_modules(dev);
return 0;
err_free:
kfree(dev->alt_max_pkt_size_isoc);
kfree(dev);
err:
clear_bit(nr, em28xx_devused);
err_no_slot:
usb_put_dev(udev);
return retval;
}
static void em28xx_usb_disconnect(struct usb_interface *interface)
{
struct em28xx *dev;
dev = usb_get_intfdata(interface);
usb_set_intfdata(interface, NULL);
if (!dev)
return;
dev->disconnected = 1;
em28xx_info("Disconnecting %s\n", dev->name);
flush_request_modules(dev);
em28xx_close_extension(dev);
em28xx_release_resources(dev);
kref_put(&dev->ref, em28xx_free_device);
}
static int em28xx_usb_suspend(struct usb_interface *interface,
pm_message_t message)
{
struct em28xx *dev;
dev = usb_get_intfdata(interface);
if (!dev)
return 0;
em28xx_suspend_extension(dev);
return 0;
}
static int em28xx_usb_resume(struct usb_interface *interface)
{
struct em28xx *dev;
dev = usb_get_intfdata(interface);
if (!dev)
return 0;
em28xx_resume_extension(dev);
return 0;
}
