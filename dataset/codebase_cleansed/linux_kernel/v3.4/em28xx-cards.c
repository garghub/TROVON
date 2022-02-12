int em28xx_tuner_callback(void *ptr, int component, int command, int arg)
{
int rc = 0;
struct em28xx *dev = ptr;
if (dev->tuner_type != TUNER_XC2028 && dev->tuner_type != TUNER_XC5000)
return 0;
if (command != XC2028_TUNER_RESET && command != XC5000_TUNER_RESET)
return 0;
rc = em28xx_gpio_set(dev, dev->board.tuner_gpio);
return rc;
}
static inline void em28xx_set_model(struct em28xx *dev)
{
memcpy(&dev->board, &em28xx_boards[dev->model], sizeof(dev->board));
if (!dev->board.xclk)
dev->board.xclk = EM28XX_XCLK_IR_RC5_MODE |
EM28XX_XCLK_FREQUENCY_12MHZ;
if (!dev->board.i2c_speed)
dev->board.i2c_speed = EM28XX_I2C_CLK_WAIT_ENABLE |
EM28XX_I2C_FREQ_100_KHZ;
}
static int em28xx_initialize_mt9m111(struct em28xx *dev)
{
int i;
unsigned char regs[][3] = {
{ 0x0d, 0x00, 0x01, },
{ 0x0d, 0x00, 0x00, },
{ 0x0a, 0x00, 0x21, },
{ 0x21, 0x04, 0x00, },
};
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client, &regs[i][0], 3);
return 0;
}
static int em28xx_initialize_mt9m001(struct em28xx *dev)
{
int i;
unsigned char regs[][3] = {
{ 0x0d, 0x00, 0x01, },
{ 0x0d, 0x00, 0x00, },
{ 0x04, 0x05, 0x00, },
{ 0x03, 0x04, 0x00, },
{ 0x20, 0x11, 0x00, },
{ 0x06, 0x00, 0x10, },
{ 0x2b, 0x00, 0x24, },
{ 0x2e, 0x00, 0x24, },
{ 0x35, 0x00, 0x24, },
{ 0x2d, 0x00, 0x20, },
{ 0x2c, 0x00, 0x20, },
{ 0x09, 0x0a, 0xd4, },
{ 0x35, 0x00, 0x57, },
};
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client, &regs[i][0], 3);
return 0;
}
static int em28xx_hint_sensor(struct em28xx *dev)
{
int rc;
char *sensor_name;
unsigned char cmd;
__be16 version_be;
u16 version;
dev->i2c_client.addr = 0xba >> 1;
cmd = 0;
i2c_master_send(&dev->i2c_client, &cmd, 1);
rc = i2c_master_recv(&dev->i2c_client, (char *)&version_be, 2);
if (rc != 2)
return -EINVAL;
version = be16_to_cpu(version_be);
switch (version) {
case 0x8232:
case 0x8243:
dev->model = EM2820_BOARD_SILVERCREST_WEBCAM;
em28xx_set_model(dev);
sensor_name = "mt9v011";
dev->em28xx_sensor = EM28XX_MT9V011;
dev->sensor_xres = 640;
dev->sensor_yres = 480;
dev->board.xclk = EM28XX_XCLK_FREQUENCY_4_3MHZ;
dev->sensor_xtal = 4300000;
dev->vinmode = 0x0d;
dev->vinctl = 0x00;
break;
case 0x143a:
dev->model = EM2750_BOARD_UNKNOWN;
em28xx_set_model(dev);
sensor_name = "mt9m111";
dev->board.xclk = EM28XX_XCLK_FREQUENCY_48MHZ;
dev->em28xx_sensor = EM28XX_MT9M111;
em28xx_initialize_mt9m111(dev);
dev->sensor_xres = 640;
dev->sensor_yres = 512;
dev->vinmode = 0x0a;
dev->vinctl = 0x00;
break;
case 0x8431:
dev->model = EM2750_BOARD_UNKNOWN;
em28xx_set_model(dev);
sensor_name = "mt9m001";
dev->em28xx_sensor = EM28XX_MT9M001;
em28xx_initialize_mt9m001(dev);
dev->sensor_xres = 1280;
dev->sensor_yres = 1024;
dev->vinmode = 0x0c;
dev->vinctl = 0x00;
break;
default:
printk("Unknown Micron Sensor 0x%04x\n", version);
return -EINVAL;
}
em28xx_pre_card_setup(dev);
em28xx_errdev("Sensor is %s, using model %s entry.\n",
sensor_name, em28xx_boards[dev->model].name);
return 0;
}
void em28xx_pre_card_setup(struct em28xx *dev)
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
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0x6d);
msleep(10);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0x7d);
msleep(10);
break;
case EM2870_BOARD_COMPRO_VIDEOMATE:
em28xx_write_reg(dev, EM2880_R04_GPO, 0x00);
msleep(10);
em28xx_write_reg(dev, EM2880_R04_GPO, 0x01);
msleep(10);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfd);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfc);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xdc);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfc);
mdelay(70);
break;
case EM2870_BOARD_TERRATEC_XS_MT2060:
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xde);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
mdelay(70);
break;
case EM2870_BOARD_PINNACLE_PCTV_DVB:
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xde);
mdelay(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
mdelay(70);
break;
case EM2820_BOARD_GADMEI_UTV310:
case EM2820_BOARD_MSI_VOX_USB_2:
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfd);
break;
case EM2882_BOARD_KWORLD_ATSC_315U:
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xff);
msleep(10);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
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
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xff);
msleep(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xf7);
msleep(10);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfe);
msleep(70);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfd);
msleep(70);
break;
}
em28xx_gpio_set(dev, dev->board.tuner_gpio);
em28xx_set_mode(dev, EM28XX_ANALOG_MODE);
em28xx_set_mode(dev, EM28XX_SUSPEND);
}
static void em28xx_setup_xc3028(struct em28xx *dev, struct xc2028_ctrl *ctl)
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
static void em28xx_tuner_setup(struct em28xx *dev)
{
struct tuner_setup tun_setup;
struct v4l2_frequency f;
if (dev->tuner_type == TUNER_ABSENT)
return;
memset(&tun_setup, 0, sizeof(tun_setup));
tun_setup.mode_mask = T_ANALOG_TV | T_RADIO;
tun_setup.tuner_callback = em28xx_tuner_callback;
if (dev->board.radio.type) {
tun_setup.type = dev->board.radio.type;
tun_setup.addr = dev->board.radio_addr;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_type_addr, &tun_setup);
}
if ((dev->tuner_type != TUNER_ABSENT) && (dev->tuner_type)) {
tun_setup.type = dev->tuner_type;
tun_setup.addr = dev->tuner_addr;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_type_addr, &tun_setup);
}
if (dev->tda9887_conf) {
struct v4l2_priv_tun_config tda9887_cfg;
tda9887_cfg.tuner = TUNER_TDA9887;
tda9887_cfg.priv = &dev->tda9887_conf;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_config, &tda9887_cfg);
}
if (dev->tuner_type == TUNER_XC2028) {
struct v4l2_priv_tun_config xc2028_cfg;
struct xc2028_ctrl ctl;
memset(&xc2028_cfg, 0, sizeof(xc2028_cfg));
memset(&ctl, 0, sizeof(ctl));
em28xx_setup_xc3028(dev, &ctl);
xc2028_cfg.tuner = TUNER_XC2028;
xc2028_cfg.priv = &ctl;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_config, &xc2028_cfg);
}
f.tuner = 0;
f.type = V4L2_TUNER_ANALOG_TV;
f.frequency = 9076;
dev->ctl_freq = f.frequency;
v4l2_device_call_all(&dev->v4l2_dev, 0, tuner, s_frequency, &f);
}
static int em28xx_hint_board(struct em28xx *dev)
{
int i;
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
em28xx_do_i2c_scan(dev);
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
void em28xx_register_i2c_ir(struct em28xx *dev)
{
struct i2c_board_info info;
const unsigned short addr_list[] = {
0x1f, 0x30, 0x47, I2C_CLIENT_END
};
if (disable_ir)
return;
memset(&info, 0, sizeof(struct i2c_board_info));
memset(&dev->init_data, 0, sizeof(dev->init_data));
strlcpy(info.type, "ir_video", I2C_NAME_SIZE);
switch (dev->model) {
case EM2800_BOARD_TERRATEC_CINERGY_200:
case EM2820_BOARD_TERRATEC_CINERGY_250:
dev->init_data.ir_codes = RC_MAP_EM_TERRATEC;
dev->init_data.get_key = em28xx_get_key_terratec;
dev->init_data.name = "i2c IR (EM28XX Terratec)";
break;
case EM2820_BOARD_PINNACLE_USB_2:
dev->init_data.ir_codes = RC_MAP_PINNACLE_GREY;
dev->init_data.get_key = em28xx_get_key_pinnacle_usb_grey;
dev->init_data.name = "i2c IR (EM28XX Pinnacle PCTV)";
break;
case EM2820_BOARD_HAUPPAUGE_WINTV_USB_2:
dev->init_data.ir_codes = RC_MAP_HAUPPAUGE;
dev->init_data.get_key = em28xx_get_key_em_haup;
dev->init_data.name = "i2c IR (EM2840 Hauppauge)";
break;
case EM2820_BOARD_LEADTEK_WINFAST_USBII_DELUXE:
dev->init_data.ir_codes = RC_MAP_WINFAST_USBII_DELUXE;
dev->init_data.get_key = em28xx_get_key_winfast_usbii_deluxe;
dev->init_data.name = "i2c IR (EM2820 Winfast TV USBII Deluxe)";
break;
}
if (dev->init_data.name)
info.platform_data = &dev->init_data;
i2c_new_probed_device(&dev->i2c_adap, &info, addr_list, NULL);
}
void em28xx_card_setup(struct em28xx *dev)
{
if (dev->board.is_webcam) {
if (em28xx_hint_sensor(dev) < 0)
dev->board.is_webcam = 0;
else
dev->progressive = 1;
}
if (!dev->board.is_webcam) {
switch (dev->model) {
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
}
em28xx_info("Identified as %s (card=%d)\n",
dev->board.name, dev->model);
dev->tuner_type = em28xx_boards[dev->model].tuner_type;
if (em28xx_boards[dev->model].tuner_addr)
dev->tuner_addr = em28xx_boards[dev->model].tuner_addr;
if (em28xx_boards[dev->model].tda9887_conf)
dev->tda9887_conf = em28xx_boards[dev->model].tda9887_conf;
switch (dev->model) {
case EM2820_BOARD_HAUPPAUGE_WINTV_USB_2:
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900:
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900_R2:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_850:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_950:
{
struct tveeprom tv;
#if defined(CONFIG_MODULES) && defined(MODULE)
request_module("tveeprom");
#endif
dev->i2c_client.addr = 0xa0 >> 1;
tveeprom_hauppauge_analog(&dev->i2c_client, &tv, dev->eedata);
dev->tuner_type = tv.tuner_type;
if (tv.audio_processor == V4L2_IDENT_MSPX4XX) {
dev->i2s_speed = 2048000;
dev->board.has_msp34xx = 1;
}
break;
}
case EM2882_BOARD_KWORLD_ATSC_315U:
em28xx_write_reg(dev, 0x0d, 0x42);
msleep(10);
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xfd);
msleep(10);
break;
case EM2820_BOARD_KWORLD_PVRTV2800RF:
em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xf9);
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
#if defined(CONFIG_MODULES) && defined(MODULE)
if (dev->board.has_ir_i2c && !disable_ir)
request_module("ir-kbd-i2c");
#endif
if (dev->board.has_snapshot_button)
em28xx_register_snapshot_button(dev);
if (dev->board.valid == EM28XX_BOARD_NOT_VALIDATED) {
em28xx_errdev("\n\n");
em28xx_errdev("The support for this board weren't "
"valid yet.\n");
em28xx_errdev("Please send a report of having this working\n");
em28xx_errdev("not to V4L mailing list (and/or to other "
"addresses)\n\n");
}
if (tuner >= 0)
dev->tuner_type = tuner;
if (dev->board.has_msp34xx)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"msp3400", 0, msp3400_addrs);
if (dev->board.decoder == EM28XX_SAA711X)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"saa7115_auto", 0, saa711x_addrs);
if (dev->board.decoder == EM28XX_TVP5150)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tvp5150", 0, tvp5150_addrs);
if (dev->em28xx_sensor == EM28XX_MT9V011) {
struct mt9v011_platform_data pdata;
struct i2c_board_info mt9v011_info = {
.type = "mt9v011",
.addr = 0xba >> 1,
.platform_data = &pdata,
};
pdata.xtal = dev->sensor_xtal;
v4l2_i2c_new_subdev_board(&dev->v4l2_dev, &dev->i2c_adap,
&mt9v011_info, NULL);
}
if (dev->board.adecoder == EM28XX_TVAUDIO)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tvaudio", dev->board.tvaudio_addr, NULL);
if (dev->board.tuner_type != TUNER_ABSENT) {
int has_demod = (dev->tda9887_conf & TDA9887_PRESENT);
if (dev->board.radio.type)
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tuner", dev->board.radio_addr, NULL);
if (has_demod)
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
if (dev->tuner_addr == 0) {
enum v4l2_i2c_tuner_type type =
has_demod ? ADDRS_TV_WITH_DEMOD : ADDRS_TV;
struct v4l2_subdev *sd;
sd = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(type));
if (sd)
dev->tuner_addr = v4l2_i2c_subdev_addr(sd);
} else {
v4l2_i2c_new_subdev(&dev->v4l2_dev, &dev->i2c_adap,
"tuner", dev->tuner_addr, NULL);
}
}
em28xx_tuner_setup(dev);
if(!disable_ir)
em28xx_ir_init(dev);
}
static void request_module_async(struct work_struct *work)
{
struct em28xx *dev = container_of(work,
struct em28xx, request_module_wk);
if (dev->has_audio_class)
request_module("snd-usb-audio");
else if (dev->has_alsa_audio)
request_module("em28xx-alsa");
if (dev->board.has_dvb)
request_module("em28xx-dvb");
}
static void request_modules(struct em28xx *dev)
{
INIT_WORK(&dev->request_module_wk, request_module_async);
schedule_work(&dev->request_module_wk);
}
static void flush_request_modules(struct em28xx *dev)
{
flush_work_sync(&dev->request_module_wk);
}
void em28xx_release_resources(struct em28xx *dev)
{
if (dev->sbutton_input_dev)
em28xx_deregister_snapshot_button(dev);
if (dev->ir)
em28xx_ir_fini(dev);
em28xx_release_analog_resources(dev);
em28xx_i2c_unregister(dev);
v4l2_device_unregister(&dev->v4l2_dev);
usb_put_dev(dev->udev);
clear_bit(dev->devno, &em28xx_devused);
}
static int em28xx_init_dev(struct em28xx *dev, struct usb_device *udev,
struct usb_interface *interface,
int minor)
{
int retval;
dev->udev = udev;
mutex_init(&dev->ctrl_urb_lock);
spin_lock_init(&dev->slock);
init_waitqueue_head(&dev->open);
init_waitqueue_head(&dev->wait_frame);
init_waitqueue_head(&dev->wait_stream);
dev->em28xx_write_regs = em28xx_write_regs;
dev->em28xx_read_reg = em28xx_read_reg;
dev->em28xx_read_reg_req_len = em28xx_read_reg_req_len;
dev->em28xx_write_regs_req = em28xx_write_regs_req;
dev->em28xx_read_reg_req = em28xx_read_reg_req;
dev->board.is_em2800 = em28xx_boards[dev->model].is_em2800;
em28xx_set_model(dev);
dev->reg_gpo_num = EM2880_R04_GPO;
dev->reg_gpio_num = EM28XX_R08_GPIO;
dev->wait_after_write = 5;
retval = em28xx_read_reg(dev, EM28XX_R0A_CHIPID);
if (retval > 0) {
dev->chip_id = retval;
switch (dev->chip_id) {
case CHIP_ID_EM2800:
em28xx_info("chip ID is em2800\n");
break;
case CHIP_ID_EM2710:
em28xx_info("chip ID is em2710\n");
break;
case CHIP_ID_EM2750:
em28xx_info("chip ID is em2750\n");
break;
case CHIP_ID_EM2820:
em28xx_info("chip ID is em2820 (or em2710)\n");
break;
case CHIP_ID_EM2840:
em28xx_info("chip ID is em2840\n");
break;
case CHIP_ID_EM2860:
em28xx_info("chip ID is em2860\n");
break;
case CHIP_ID_EM2870:
em28xx_info("chip ID is em2870\n");
dev->wait_after_write = 0;
break;
case CHIP_ID_EM2874:
em28xx_info("chip ID is em2874\n");
dev->reg_gpio_num = EM2874_R80_GPIO;
dev->wait_after_write = 0;
break;
case CHIP_ID_EM28174:
em28xx_info("chip ID is em28174\n");
dev->reg_gpio_num = EM2874_R80_GPIO;
dev->wait_after_write = 0;
break;
case CHIP_ID_EM2883:
em28xx_info("chip ID is em2882/em2883\n");
dev->wait_after_write = 0;
break;
case CHIP_ID_EM2884:
em28xx_info("chip ID is em2884\n");
dev->reg_gpio_num = EM2874_R80_GPIO;
dev->wait_after_write = 0;
break;
default:
em28xx_info("em28xx chip ID = %d\n", dev->chip_id);
}
}
if (dev->is_audio_only) {
retval = em28xx_audio_setup(dev);
if (retval)
return -ENODEV;
em28xx_init_extension(dev);
return 0;
}
retval = em28xx_read_reg(dev, dev->reg_gpo_num);
if (retval >= 0)
dev->reg_gpo = retval;
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
retval = v4l2_device_register(&interface->dev, &dev->v4l2_dev);
if (retval < 0) {
em28xx_errdev("Call to v4l2_device_register() failed!\n");
return retval;
}
retval = em28xx_i2c_register(dev);
if (retval < 0) {
em28xx_errdev("%s: em28xx_i2c_register - error [%d]!\n",
__func__, retval);
goto unregister_dev;
}
dev->vinmode = 0x10;
dev->vinctl = EM28XX_VINCTRL_INTERLACED |
EM28XX_VINCTRL_CCIR656_ENABLE;
em28xx_card_setup(dev);
retval = em28xx_audio_setup(dev);
if (retval < 0) {
em28xx_errdev("%s: Error while setting audio - error [%d]!\n",
__func__, retval);
goto fail;
}
em28xx_wake_i2c(dev);
INIT_LIST_HEAD(&dev->vidq.active);
INIT_LIST_HEAD(&dev->vidq.queued);
INIT_LIST_HEAD(&dev->vbiq.active);
INIT_LIST_HEAD(&dev->vbiq.queued);
if (dev->board.has_msp34xx) {
retval = em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xf7);
if (retval < 0) {
em28xx_errdev("%s: em28xx_write_reg - "
"msp34xx(1) failed! error [%d]\n",
__func__, retval);
goto fail;
}
msleep(3);
retval = em28xx_write_reg(dev, EM28XX_R08_GPIO, 0xff);
if (retval < 0) {
em28xx_errdev("%s: em28xx_write_reg - "
"msp34xx(2) failed! error [%d]\n",
__func__, retval);
goto fail;
}
msleep(3);
}
retval = em28xx_register_analog_devices(dev);
if (retval < 0) {
goto fail;
}
v4l2_device_call_all(&dev->v4l2_dev, 0, core, s_power, 0);
return 0;
fail:
em28xx_i2c_unregister(dev);
unregister_dev:
v4l2_device_unregister(&dev->v4l2_dev);
return retval;
}
static int em28xx_usb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *udev;
struct em28xx *dev = NULL;
int retval;
bool has_audio = false, has_video = false, has_dvb = false;
int i, nr;
const int ifnum = interface->altsetting[0].desc.bInterfaceNumber;
char *speed;
udev = usb_get_dev(interface_to_usbdev(interface));
do {
nr = find_first_zero_bit(&em28xx_devused, EM28XX_MAXBOARDS);
if (nr >= EM28XX_MAXBOARDS) {
printk(DRIVER_NAME ": Supports only %i em28xx boards.\n",
EM28XX_MAXBOARDS);
retval = -ENOMEM;
goto err_no_slot;
}
} while (test_and_set_bit(nr, &em28xx_devused));
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
dev->alt_max_pkt_size = kmalloc(sizeof(dev->alt_max_pkt_size[0]) *
interface->num_altsetting, GFP_KERNEL);
if (dev->alt_max_pkt_size == NULL) {
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
if (usb_endpoint_xfer_isoc(e) &&
usb_endpoint_dir_in(e)) {
switch (e->bEndpointAddress) {
case EM28XX_EP_AUDIO:
has_audio = true;
break;
case EM28XX_EP_ANALOG:
has_video = true;
dev->alt_max_pkt_size[i] = size;
break;
case EM28XX_EP_DIGITAL:
has_dvb = true;
if (size > dev->dvb_max_pkt_size) {
dev->dvb_max_pkt_size = size;
dev->dvb_alt = i;
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
if (has_audio)
printk(KERN_INFO DRIVER_NAME
": Audio Vendor Class interface %i found\n",
ifnum);
if (has_video)
printk(KERN_INFO DRIVER_NAME
": Video interface %i found\n",
ifnum);
if (has_dvb)
printk(KERN_INFO DRIVER_NAME
": DVB interface %i found\n",
ifnum);
if (udev->speed != USB_SPEED_HIGH && disable_usb_speed_check == 0) {
printk(DRIVER_NAME ": Device initialization failed.\n");
printk(DRIVER_NAME ": Device must be connected to a high-speed"
" USB 2.0 port.\n");
retval = -ENODEV;
goto err_free;
}
snprintf(dev->name, sizeof(dev->name), "em28xx #%d", nr);
dev->devno = nr;
dev->model = id->driver_info;
dev->alt = -1;
dev->is_audio_only = has_audio && !(has_video || has_dvb);
dev->has_alsa_audio = has_audio;
dev->audio_ifnum = ifnum;
for (i = 0; i < udev->config->desc.bNumInterfaces; i++) {
struct usb_interface *uif = udev->config->interface[i];
if (uif->altsetting[0].desc.bInterfaceClass == USB_CLASS_AUDIO) {
dev->has_audio_class = 1;
break;
}
}
dev->num_alt = interface->num_altsetting;
if ((card[nr] >= 0) && (card[nr] < em28xx_bcount))
dev->model = card[nr];
usb_set_intfdata(interface, dev);
mutex_init(&dev->lock);
mutex_lock(&dev->lock);
retval = em28xx_init_dev(dev, udev, interface, nr);
if (retval) {
goto unlock_and_free;
}
if (has_dvb) {
retval = em28xx_alloc_isoc(dev, EM28XX_DIGITAL_MODE,
EM28XX_DVB_MAX_PACKETS,
EM28XX_DVB_NUM_BUFS,
dev->dvb_max_pkt_size);
if (retval) {
goto unlock_and_free;
}
}
request_modules(dev);
mutex_unlock(&dev->lock);
em28xx_init_extension(dev);
return 0;
unlock_and_free:
mutex_unlock(&dev->lock);
err_free:
kfree(dev->alt_max_pkt_size);
kfree(dev);
err:
clear_bit(nr, &em28xx_devused);
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
if (dev->is_audio_only) {
mutex_lock(&dev->lock);
em28xx_close_extension(dev);
mutex_unlock(&dev->lock);
return;
}
em28xx_info("disconnecting %s\n", dev->vdev->name);
flush_request_modules(dev);
mutex_lock(&dev->lock);
wake_up_interruptible_all(&dev->open);
v4l2_device_disconnect(&dev->v4l2_dev);
if (dev->users) {
em28xx_warn
("device %s is open! Deregistration and memory "
"deallocation are deferred on close.\n",
video_device_node_name(dev->vdev));
dev->state |= DEV_MISCONFIGURED;
em28xx_uninit_isoc(dev, dev->mode);
dev->state |= DEV_DISCONNECTED;
wake_up_interruptible(&dev->wait_frame);
wake_up_interruptible(&dev->wait_stream);
} else {
dev->state |= DEV_DISCONNECTED;
em28xx_release_resources(dev);
}
em28xx_uninit_isoc(dev, EM28XX_DIGITAL_MODE);
mutex_unlock(&dev->lock);
em28xx_close_extension(dev);
if (!dev->users) {
kfree(dev->alt_max_pkt_size);
kfree(dev);
}
}
