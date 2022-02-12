static void board_flyvideo(struct saa7134_dev *dev)
{
printk("%s: there are different flyvideo cards with different tuners\n"
"%s: out there, you might have to use the tuner=<nr> insmod\n"
"%s: option to override the default value.\n",
dev->name, dev->name, dev->name);
}
static int saa7134_xc2028_callback(struct saa7134_dev *dev,
int command, int arg)
{
switch (command) {
case XC2028_TUNER_RESET:
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x00008000, 0x00000000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x00008000, 0x00008000);
switch (dev->board) {
case SAA7134_BOARD_AVERMEDIA_CARDBUS_506:
case SAA7134_BOARD_AVERMEDIA_M103:
saa7134_set_gpio(dev, 23, 0);
msleep(10);
saa7134_set_gpio(dev, 23, 1);
break;
case SAA7134_BOARD_AVERMEDIA_A16D:
saa7134_set_gpio(dev, 21, 0);
msleep(10);
saa7134_set_gpio(dev, 21, 1);
break;
case SAA7134_BOARD_AVERMEDIA_A700_HYBRID:
saa7134_set_gpio(dev, 18, 0);
msleep(10);
saa7134_set_gpio(dev, 18, 1);
break;
case SAA7134_BOARD_VIDEOMATE_T750:
saa7134_set_gpio(dev, 20, 0);
msleep(10);
saa7134_set_gpio(dev, 20, 1);
break;
}
return 0;
}
return -EINVAL;
}
static int saa7134_xc5000_callback(struct saa7134_dev *dev,
int command, int arg)
{
switch (dev->board) {
case SAA7134_BOARD_BEHOLD_X7:
case SAA7134_BOARD_BEHOLD_H7:
case SAA7134_BOARD_BEHOLD_A7:
if (command == XC5000_TUNER_RESET) {
saa_writeb(SAA7134_SPECIAL_MODE, 0x00);
msleep(10);
saa_writeb(SAA7134_SPECIAL_MODE, 0x01);
msleep(10);
}
break;
default:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x06e20000, 0x06e20000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x06a20000, 0x06a20000);
saa_andorl(SAA7133_ANALOG_IO_SELECT >> 2, 0x02, 0x02);
saa_andorl(SAA7134_ANALOG_IN_CTRL1 >> 2, 0x81, 0x81);
saa_andorl(SAA7134_AUDIO_CLOCK0 >> 2, 0x03187de7, 0x03187de7);
saa_andorl(SAA7134_AUDIO_PLL_CTRL >> 2, 0x03, 0x03);
saa_andorl(SAA7134_AUDIO_CLOCKS_PER_FIELD0 >> 2,
0x0001e000, 0x0001e000);
break;
}
return 0;
}
static int saa7134_tda8290_827x_callback(struct saa7134_dev *dev,
int command, int arg)
{
u8 sync_control;
switch (command) {
case 0:
saa7134_set_gpio(dev, 22, arg) ;
break;
case 1:
saa_andorb(SAA7134_VIDEO_PORT_CTRL3, 0x80, 0x80);
saa_andorb(SAA7134_VIDEO_PORT_CTRL6, 0x0f, 0x03);
if (arg == 1)
sync_control = 11;
else
sync_control = 17;
saa_writeb(SAA7134_VGATE_START, sync_control);
saa_writeb(SAA7134_VGATE_STOP, sync_control + 1);
saa_andorb(SAA7134_MISC_VGATE_MSB, 0x03, 0x00);
break;
default:
return -EINVAL;
}
return 0;
}
static inline int saa7134_tda18271_hvr11x0_toggle_agc(struct saa7134_dev *dev,
enum tda18271_mode mode)
{
switch (mode) {
case TDA18271_ANALOG:
saa7134_set_gpio(dev, 26, 0);
break;
case TDA18271_DIGITAL:
saa7134_set_gpio(dev, 26, 1);
break;
default:
return -EINVAL;
}
return 0;
}
static inline int saa7134_kworld_sbtvd_toggle_agc(struct saa7134_dev *dev,
enum tda18271_mode mode)
{
switch (mode) {
case TDA18271_ANALOG:
saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x4000);
saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x4000);
msleep(20);
break;
case TDA18271_DIGITAL:
saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x14000);
saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x14000);
msleep(20);
saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x54000);
saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x54000);
msleep(30);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa7134_kworld_pc150u_toggle_agc(struct saa7134_dev *dev,
enum tda18271_mode mode)
{
switch (mode) {
case TDA18271_ANALOG:
saa7134_set_gpio(dev, 18, 0);
break;
case TDA18271_DIGITAL:
saa7134_set_gpio(dev, 18, 1);
msleep(30);
break;
default:
return -EINVAL;
}
return 0;
}
static int saa7134_tda8290_18271_callback(struct saa7134_dev *dev,
int command, int arg)
{
int ret = 0;
switch (command) {
case TDA18271_CALLBACK_CMD_AGC_ENABLE:
switch (dev->board) {
case SAA7134_BOARD_HAUPPAUGE_HVR1150:
case SAA7134_BOARD_HAUPPAUGE_HVR1120:
case SAA7134_BOARD_MAGICPRO_PROHDTV_PRO2:
ret = saa7134_tda18271_hvr11x0_toggle_agc(dev, arg);
break;
case SAA7134_BOARD_KWORLD_PCI_SBTVD_FULLSEG:
ret = saa7134_kworld_sbtvd_toggle_agc(dev, arg);
break;
case SAA7134_BOARD_KWORLD_PC150U:
ret = saa7134_kworld_pc150u_toggle_agc(dev, arg);
break;
default:
break;
}
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int saa7134_tda8290_callback(struct saa7134_dev *dev,
int command, int arg)
{
int ret;
switch (dev->board) {
case SAA7134_BOARD_HAUPPAUGE_HVR1150:
case SAA7134_BOARD_HAUPPAUGE_HVR1120:
case SAA7134_BOARD_AVERMEDIA_M733A:
case SAA7134_BOARD_KWORLD_PCI_SBTVD_FULLSEG:
case SAA7134_BOARD_KWORLD_PC150U:
case SAA7134_BOARD_MAGICPRO_PROHDTV_PRO2:
ret = saa7134_tda8290_18271_callback(dev, command, arg);
break;
default:
ret = saa7134_tda8290_827x_callback(dev, command, arg);
break;
}
return ret;
}
int saa7134_tuner_callback(void *priv, int component, int command, int arg)
{
struct saa7134_dev *dev = priv;
if (dev != NULL) {
switch (dev->tuner_type) {
case TUNER_PHILIPS_TDA8290:
return saa7134_tda8290_callback(dev, command, arg);
case TUNER_XC2028:
return saa7134_xc2028_callback(dev, command, arg);
case TUNER_XC5000:
return saa7134_xc5000_callback(dev, command, arg);
}
} else {
printk(KERN_ERR "saa7134: Error - device struct undefined.\n");
return -EINVAL;
}
return -EINVAL;
}
static void hauppauge_eeprom(struct saa7134_dev *dev, u8 *eeprom_data)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&dev->i2c_client, &tv, eeprom_data);
switch (tv.model) {
case 67019:
case 67109:
case 67201:
case 67301:
case 67209:
case 67559:
case 67569:
case 67579:
case 67589:
case 67599:
case 67651:
case 67659:
break;
default:
printk(KERN_WARNING "%s: warning: "
"unknown hauppauge model #%d\n", dev->name, tv.model);
break;
}
printk(KERN_INFO "%s: hauppauge eeprom: model=%d\n",
dev->name, tv.model);
}
int saa7134_board_init1(struct saa7134_dev *dev)
{
saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0);
dev->gpio_value = saa_readl(SAA7134_GPIO_GPSTATUS0 >> 2);
printk(KERN_INFO "%s: board init: gpio is %x\n", dev->name, dev->gpio_value);
switch (dev->board) {
case SAA7134_BOARD_FLYVIDEO2000:
case SAA7134_BOARD_FLYVIDEO3000:
case SAA7134_BOARD_FLYVIDEO3000_NTSC:
dev->has_remote = SAA7134_REMOTE_GPIO;
board_flyvideo(dev);
break;
case SAA7134_BOARD_FLYTVPLATINUM_MINI2:
case SAA7134_BOARD_FLYTVPLATINUM_FM:
case SAA7134_BOARD_CINERGY400:
case SAA7134_BOARD_CINERGY600:
case SAA7134_BOARD_CINERGY600_MK3:
case SAA7134_BOARD_ECS_TVP3XP:
case SAA7134_BOARD_ECS_TVP3XP_4CB5:
case SAA7134_BOARD_ECS_TVP3XP_4CB6:
case SAA7134_BOARD_MD2819:
case SAA7134_BOARD_KWORLD_VSTREAM_XPERT:
case SAA7134_BOARD_KWORLD_XPERT:
case SAA7134_BOARD_AVERMEDIA_STUDIO_305:
case SAA7134_BOARD_AVERMEDIA_STUDIO_505:
case SAA7134_BOARD_AVERMEDIA_305:
case SAA7134_BOARD_AVERMEDIA_STUDIO_307:
case SAA7134_BOARD_AVERMEDIA_307:
case SAA7134_BOARD_AVERMEDIA_STUDIO_507:
case SAA7134_BOARD_AVERMEDIA_GO_007_FM:
case SAA7134_BOARD_AVERMEDIA_777:
case SAA7134_BOARD_AVERMEDIA_M135A:
case SAA7134_BOARD_VIDEOMATE_TV_PVR:
case SAA7134_BOARD_VIDEOMATE_GOLD_PLUS:
case SAA7134_BOARD_VIDEOMATE_TV_GOLD_PLUSII:
case SAA7134_BOARD_VIDEOMATE_M1F:
case SAA7134_BOARD_VIDEOMATE_DVBT_300:
case SAA7134_BOARD_VIDEOMATE_DVBT_200:
case SAA7134_BOARD_VIDEOMATE_DVBT_200A:
case SAA7134_BOARD_MANLI_MTV001:
case SAA7134_BOARD_MANLI_MTV002:
case SAA7134_BOARD_BEHOLD_409FM:
case SAA7134_BOARD_AVACSSMARTTV:
case SAA7134_BOARD_GOTVIEW_7135:
case SAA7134_BOARD_KWORLD_TERMINATOR:
case SAA7134_BOARD_SEDNA_PC_TV_CARDBUS:
case SAA7134_BOARD_FLYDVBT_LR301:
case SAA7134_BOARD_ASUSTeK_P7131_DUAL:
case SAA7134_BOARD_ASUSTeK_P7131_HYBRID_LNA:
case SAA7134_BOARD_ASUSTeK_P7131_ANALOG:
case SAA7134_BOARD_FLYDVBTDUO:
case SAA7134_BOARD_PROTEUS_2309:
case SAA7134_BOARD_AVERMEDIA_A16AR:
case SAA7134_BOARD_ENCORE_ENLTV:
case SAA7134_BOARD_ENCORE_ENLTV_FM:
case SAA7134_BOARD_ENCORE_ENLTV_FM53:
case SAA7134_BOARD_ENCORE_ENLTV_FM3:
case SAA7134_BOARD_10MOONSTVMASTER3:
case SAA7134_BOARD_BEHOLD_401:
case SAA7134_BOARD_BEHOLD_403:
case SAA7134_BOARD_BEHOLD_403FM:
case SAA7134_BOARD_BEHOLD_405:
case SAA7134_BOARD_BEHOLD_405FM:
case SAA7134_BOARD_BEHOLD_407:
case SAA7134_BOARD_BEHOLD_407FM:
case SAA7134_BOARD_BEHOLD_409:
case SAA7134_BOARD_BEHOLD_505FM:
case SAA7134_BOARD_BEHOLD_505RDS_MK5:
case SAA7134_BOARD_BEHOLD_505RDS_MK3:
case SAA7134_BOARD_BEHOLD_507_9FM:
case SAA7134_BOARD_BEHOLD_507RDS_MK3:
case SAA7134_BOARD_BEHOLD_507RDS_MK5:
case SAA7134_BOARD_GENIUS_TVGO_A11MCE:
case SAA7134_BOARD_REAL_ANGEL_220:
case SAA7134_BOARD_KWORLD_PLUS_TV_ANALOG:
case SAA7134_BOARD_AVERMEDIA_GO_007_FM_PLUS:
case SAA7134_BOARD_ROVERMEDIA_LINK_PRO_FM:
case SAA7134_BOARD_LEADTEK_WINFAST_DTV1000S:
dev->has_remote = SAA7134_REMOTE_GPIO;
break;
case SAA7134_BOARD_FLYDVBS_LR300:
saa_writeb(SAA7134_GPIO_GPMODE3, 0x80);
saa_writeb(SAA7134_GPIO_GPSTATUS2, 0x40);
dev->has_remote = SAA7134_REMOTE_GPIO;
break;
case SAA7134_BOARD_MD5044:
printk("%s: seems there are two different versions of the MD5044\n"
"%s: (with the same ID) out there. If sound doesn't work for\n"
"%s: you try the audio_clock_override=0x200000 insmod option.\n",
dev->name,dev->name,dev->name);
break;
case SAA7134_BOARD_CINERGY400_CARDBUS:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x00040000, 0x00040000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x00040000, 0x00000000);
break;
case SAA7134_BOARD_PINNACLE_300I_DVBT_PAL:
saa_writeb(SAA7134_GPIO_GPMODE1, 0x80);
saa_writeb(SAA7134_GPIO_GPSTATUS1, 0x80);
break;
case SAA7134_BOARD_MONSTERTV_MOBILE:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x00040000, 0x00040000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x00040000, 0x00000004);
break;
case SAA7134_BOARD_FLYDVBT_DUO_CARDBUS:
saa_writeb(SAA7134_GPIO_GPMODE3, 0x08);
saa_writeb(SAA7134_GPIO_GPSTATUS3, 0x06);
break;
case SAA7134_BOARD_ADS_DUO_CARDBUS_PTV331:
case SAA7134_BOARD_FLYDVBT_HYBRID_CARDBUS:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x08000000, 0x08000000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x08000000, 0x00000000);
break;
case SAA7134_BOARD_AVERMEDIA_CARDBUS:
case SAA7134_BOARD_AVERMEDIA_M115:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0xffffffff, 0);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0xffffffff, 0);
msleep(10);
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0xffffffff, 0xffffffff);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0xffffffff, 0xffffffff);
msleep(10);
break;
case SAA7134_BOARD_AVERMEDIA_CARDBUS_501:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x08400000, 0x08400000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x08400000, 0);
msleep(10);
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x08400000, 0x08400000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x08400000, 0x08400000);
msleep(10);
dev->has_remote = SAA7134_REMOTE_I2C;
break;
case SAA7134_BOARD_AVERMEDIA_CARDBUS_506:
saa7134_set_gpio(dev, 23, 0);
msleep(10);
saa7134_set_gpio(dev, 23, 1);
dev->has_remote = SAA7134_REMOTE_I2C;
break;
case SAA7134_BOARD_AVERMEDIA_M103:
saa7134_set_gpio(dev, 23, 0);
msleep(10);
saa7134_set_gpio(dev, 23, 1);
break;
case SAA7134_BOARD_AVERMEDIA_A16D:
saa7134_set_gpio(dev, 21, 0);
msleep(10);
saa7134_set_gpio(dev, 21, 1);
msleep(1);
dev->has_remote = SAA7134_REMOTE_GPIO;
break;
case SAA7134_BOARD_BEHOLD_COLUMBUS_TVFM:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x000A8004, 0x000A8004);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x000A8004, 0);
msleep(10);
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x000A8004, 0x000A8004);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x000A8004, 0x000A8004);
msleep(10);
dev->has_remote = SAA7134_REMOTE_GPIO;
break;
case SAA7134_BOARD_RTD_VFG7350:
saa_writeb (SAA7134_PRODUCTION_TEST_MODE, 0x00);
break;
case SAA7134_BOARD_HAUPPAUGE_HVR1150:
case SAA7134_BOARD_HAUPPAUGE_HVR1120:
dev->has_remote = SAA7134_REMOTE_GPIO;
saa7134_set_gpio(dev, 26, 0);
msleep(1);
saa7134_set_gpio(dev, 22, 0);
msleep(10);
saa7134_set_gpio(dev, 22, 1);
break;
case SAA7134_BOARD_PINNACLE_PCTV_110i:
case SAA7134_BOARD_PINNACLE_PCTV_310i:
case SAA7134_BOARD_UPMOST_PURPLE_TV:
case SAA7134_BOARD_MSI_TVATANYWHERE_PLUS:
case SAA7134_BOARD_HAUPPAUGE_HVR1110:
case SAA7134_BOARD_BEHOLD_607FM_MK3:
case SAA7134_BOARD_BEHOLD_607FM_MK5:
case SAA7134_BOARD_BEHOLD_609FM_MK3:
case SAA7134_BOARD_BEHOLD_609FM_MK5:
case SAA7134_BOARD_BEHOLD_607RDS_MK3:
case SAA7134_BOARD_BEHOLD_607RDS_MK5:
case SAA7134_BOARD_BEHOLD_609RDS_MK3:
case SAA7134_BOARD_BEHOLD_609RDS_MK5:
case SAA7134_BOARD_BEHOLD_M6:
case SAA7134_BOARD_BEHOLD_M63:
case SAA7134_BOARD_BEHOLD_M6_EXTRA:
case SAA7134_BOARD_BEHOLD_H6:
case SAA7134_BOARD_BEHOLD_X7:
case SAA7134_BOARD_BEHOLD_H7:
case SAA7134_BOARD_BEHOLD_A7:
case SAA7134_BOARD_KWORLD_PC150U:
dev->has_remote = SAA7134_REMOTE_I2C;
break;
case SAA7134_BOARD_AVERMEDIA_A169_B:
printk("%s: %s: dual saa713x broadcast decoders\n"
"%s: Sorry, none of the inputs to this chip are supported yet.\n"
"%s: Dual decoder functionality is disabled for now, use the other chip.\n",
dev->name,card(dev).name,dev->name,dev->name);
break;
case SAA7134_BOARD_AVERMEDIA_M102:
dev->has_remote = SAA7134_REMOTE_GPIO;
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x8c040007, 0x8c040007);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x0c0007cd, 0x0c0007cd);
break;
case SAA7134_BOARD_AVERMEDIA_A700_HYBRID:
case SAA7134_BOARD_AVERMEDIA_A700_PRO:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x80040100, 0x80040100);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x80040100, 0x00040100);
break;
case SAA7134_BOARD_VIDEOMATE_S350:
dev->has_remote = SAA7134_REMOTE_GPIO;
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x0000C000, 0x0000C000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x0000C000, 0x0000C000);
break;
case SAA7134_BOARD_AVERMEDIA_M733A:
saa7134_set_gpio(dev, 1, 1);
msleep(10);
saa7134_set_gpio(dev, 1, 0);
msleep(10);
saa7134_set_gpio(dev, 1, 1);
dev->has_remote = SAA7134_REMOTE_GPIO;
break;
case SAA7134_BOARD_MAGICPRO_PROHDTV_PRO2:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x0e050000, 0x0c050000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x0e050000, 0x0c050000);
break;
case SAA7134_BOARD_VIDEOMATE_T750:
saa_andorl(SAA7134_GPIO_GPMODE0 >> 2, 0x00008000, 0x00008000);
saa_andorl(SAA7134_GPIO_GPSTATUS0 >> 2, 0x00008000, 0x00008000);
break;
}
return 0;
}
static void saa7134_tuner_setup(struct saa7134_dev *dev)
{
struct tuner_setup tun_setup;
unsigned int mode_mask = T_RADIO | T_ANALOG_TV;
memset(&tun_setup, 0, sizeof(tun_setup));
tun_setup.tuner_callback = saa7134_tuner_callback;
if (saa7134_boards[dev->board].radio_type != UNSET) {
tun_setup.type = saa7134_boards[dev->board].radio_type;
tun_setup.addr = saa7134_boards[dev->board].radio_addr;
tun_setup.mode_mask = T_RADIO;
saa_call_all(dev, tuner, s_type_addr, &tun_setup);
mode_mask &= ~T_RADIO;
}
if ((dev->tuner_type != TUNER_ABSENT) && (dev->tuner_type != UNSET)) {
tun_setup.type = dev->tuner_type;
tun_setup.addr = dev->tuner_addr;
tun_setup.config = saa7134_boards[dev->board].tuner_config;
tun_setup.tuner_callback = saa7134_tuner_callback;
tun_setup.mode_mask = mode_mask;
saa_call_all(dev, tuner, s_type_addr, &tun_setup);
}
if (dev->tda9887_conf) {
struct v4l2_priv_tun_config tda9887_cfg;
tda9887_cfg.tuner = TUNER_TDA9887;
tda9887_cfg.priv = &dev->tda9887_conf;
saa_call_all(dev, tuner, s_config, &tda9887_cfg);
}
if (dev->tuner_type == TUNER_XC2028) {
struct v4l2_priv_tun_config xc2028_cfg;
struct xc2028_ctrl ctl;
memset(&xc2028_cfg, 0, sizeof(xc2028_cfg));
memset(&ctl, 0, sizeof(ctl));
ctl.fname = XC2028_DEFAULT_FIRMWARE;
ctl.max_len = 64;
switch (dev->board) {
case SAA7134_BOARD_AVERMEDIA_A16D:
case SAA7134_BOARD_AVERMEDIA_CARDBUS_506:
case SAA7134_BOARD_AVERMEDIA_M103:
case SAA7134_BOARD_AVERMEDIA_A700_HYBRID:
ctl.demod = XC3028_FE_ZARLINK456;
break;
default:
ctl.demod = XC3028_FE_OREN538;
ctl.mts = 1;
}
xc2028_cfg.tuner = TUNER_XC2028;
xc2028_cfg.priv = &ctl;
saa_call_all(dev, tuner, s_config, &xc2028_cfg);
}
}
int saa7134_board_init2(struct saa7134_dev *dev)
{
unsigned char buf;
int board;
switch (dev->board) {
case SAA7134_BOARD_BMK_MPEX_NOTUNER:
case SAA7134_BOARD_BMK_MPEX_TUNER:
dev->i2c_client.addr = 0x60;
board = (i2c_master_recv(&dev->i2c_client, &buf, 0) < 0)
? SAA7134_BOARD_BMK_MPEX_NOTUNER
: SAA7134_BOARD_BMK_MPEX_TUNER;
if (board == dev->board)
break;
dev->board = board;
printk("%s: board type fixup: %s\n", dev->name,
saa7134_boards[dev->board].name);
dev->tuner_type = saa7134_boards[dev->board].tuner_type;
break;
case SAA7134_BOARD_MD7134:
{
u8 subaddr;
u8 data[3];
int ret, tuner_t;
struct i2c_msg msg[] = {{.addr=0x50, .flags=0, .buf=&subaddr, .len = 1},
{.addr=0x50, .flags=I2C_M_RD, .buf=data, .len = 3}};
subaddr= 0x14;
tuner_t = 0;
ret = i2c_transfer(&dev->i2c_adap, msg, 2);
if (ret != 2) {
printk(KERN_ERR "EEPROM read failure\n");
} else if ((data[0] != 0) && (data[0] != 0xff)) {
subaddr = data[0] + 2;
msg[1].len = 2;
i2c_transfer(&dev->i2c_adap, msg, 2);
tuner_t = (data[0] << 8) + data[1];
switch (tuner_t){
case 0x0103:
dev->tuner_type = TUNER_PHILIPS_PAL;
break;
case 0x010C:
dev->tuner_type = TUNER_PHILIPS_FM1216ME_MK3;
break;
default:
printk(KERN_ERR "%s Can't determine tuner type %x from EEPROM\n", dev->name, tuner_t);
}
} else if ((data[1] != 0) && (data[1] != 0xff)) {
subaddr = data[1] + 1;
msg[1].len = 1;
i2c_transfer(&dev->i2c_adap, msg, 2);
subaddr = data[0] + 1;
msg[1].len = 2;
i2c_transfer(&dev->i2c_adap, msg, 2);
tuner_t = (data[1] << 8) + data[0];
switch (tuner_t) {
case 0x0005:
dev->tuner_type = TUNER_PHILIPS_FM1216ME_MK3;
break;
case 0x001d:
dev->tuner_type = TUNER_PHILIPS_FMD1216ME_MK3;
printk(KERN_INFO "%s Board has DVB-T\n", dev->name);
break;
default:
printk(KERN_ERR "%s Can't determine tuner type %x from EEPROM\n", dev->name, tuner_t);
}
} else {
printk(KERN_ERR "%s unexpected config structure\n", dev->name);
}
printk(KERN_INFO "%s Tuner type is %d\n", dev->name, dev->tuner_type);
break;
}
case SAA7134_BOARD_PHILIPS_EUROPA:
if (dev->autodetected && (dev->eedata[0x41] == 0x1c)) {
dev->board = SAA7134_BOARD_PHILIPS_SNAKE;
dev->tuner_type = saa7134_boards[dev->board].tuner_type;
printk(KERN_INFO "%s: Reconfigured board as %s\n",
dev->name, saa7134_boards[dev->board].name);
break;
}
case SAA7134_BOARD_VIDEOMATE_DVBT_300:
case SAA7134_BOARD_ASUS_EUROPA2_HYBRID:
case SAA7134_BOARD_ASUS_EUROPA_HYBRID:
case SAA7134_BOARD_TECHNOTREND_BUDGET_T3000:
{
u8 data[] = { 0x07, 0x02};
struct i2c_msg msg = {.addr=0x08, .flags=0, .buf=data, .len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_PHILIPS_TIGER:
case SAA7134_BOARD_PHILIPS_TIGER_S:
{
u8 data[] = { 0x3c, 0x33, 0x60};
struct i2c_msg msg = {.addr=0x08, .flags=0, .buf=data, .len = sizeof(data)};
if (dev->autodetected && (dev->eedata[0x49] == 0x50)) {
dev->board = SAA7134_BOARD_PHILIPS_TIGER_S;
printk(KERN_INFO "%s: Reconfigured board as %s\n",
dev->name, saa7134_boards[dev->board].name);
}
if (dev->board == SAA7134_BOARD_PHILIPS_TIGER_S) {
dev->tuner_type = TUNER_PHILIPS_TDA8290;
data[2] = 0x68;
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_ASUSTeK_TVFM7135:
if (dev->autodetected && (dev->eedata[0x27] == 0x03)) {
dev->board = SAA7134_BOARD_ASUSTeK_P7131_ANALOG;
printk(KERN_INFO "%s: P7131 analog only, using "
"entry of %s\n",
dev->name, saa7134_boards[dev->board].name);
dev->has_remote = SAA7134_REMOTE_GPIO;
saa7134_input_init1(dev);
}
break;
case SAA7134_BOARD_HAUPPAUGE_HVR1150:
case SAA7134_BOARD_HAUPPAUGE_HVR1120:
hauppauge_eeprom(dev, dev->eedata+0x80);
break;
case SAA7134_BOARD_HAUPPAUGE_HVR1110:
hauppauge_eeprom(dev, dev->eedata+0x80);
case SAA7134_BOARD_PINNACLE_PCTV_310i:
case SAA7134_BOARD_KWORLD_DVBT_210:
case SAA7134_BOARD_TEVION_DVBT_220RF:
case SAA7134_BOARD_ASUSTeK_TIGER:
case SAA7134_BOARD_ASUSTeK_P7131_DUAL:
case SAA7134_BOARD_ASUSTeK_P7131_HYBRID_LNA:
case SAA7134_BOARD_MEDION_MD8800_QUADRO:
case SAA7134_BOARD_AVERMEDIA_SUPER_007:
case SAA7134_BOARD_TWINHAN_DTV_DVB_3056:
case SAA7134_BOARD_CREATIX_CTX953:
{
u8 data[] = { 0x3c, 0x33, 0x60};
struct i2c_msg msg = {.addr=0x08, .flags=0, .buf=data, .len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_ASUSTeK_TIGER_3IN1:
{
u8 data[] = { 0x3c, 0x33, 0x60};
struct i2c_msg msg = {.addr = 0x0b, .flags = 0, .buf = data,
.len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_FLYDVB_TRIO:
{
u8 temp = 0;
int rc;
u8 data[] = { 0x3c, 0x33, 0x62};
struct i2c_msg msg = {.addr=0x09, .flags=0, .buf=data, .len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
msg.buf = &temp;
msg.addr = 0x0b;
msg.len = 1;
if (1 != i2c_transfer(&dev->i2c_adap, &msg, 1)) {
printk(KERN_WARNING "%s: send wake up byte to pic16C505"
"(IR chip) failed\n", dev->name);
} else {
msg.flags = I2C_M_RD;
rc = i2c_transfer(&dev->i2c_adap, &msg, 1);
printk(KERN_INFO "%s: probe IR chip @ i2c 0x%02x: %s\n",
dev->name, msg.addr,
(1 == rc) ? "yes" : "no");
if (rc == 1)
dev->has_remote = SAA7134_REMOTE_I2C;
}
break;
}
case SAA7134_BOARD_ADS_DUO_CARDBUS_PTV331:
case SAA7134_BOARD_FLYDVBT_HYBRID_CARDBUS:
{
u8 data[] = { 0x3c, 0x33, 0x6a};
struct i2c_msg msg = {.addr=0x08, .flags=0, .buf=data, .len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_CINERGY_HT_PCMCIA:
case SAA7134_BOARD_CINERGY_HT_PCI:
{
u8 data[] = { 0x3c, 0x33, 0x68};
struct i2c_msg msg = {.addr=0x08, .flags=0, .buf=data, .len = sizeof(data)};
i2c_transfer(&dev->i2c_adap, &msg, 1);
break;
}
case SAA7134_BOARD_VIDEOMATE_DVBT_200:
case SAA7134_BOARD_VIDEOMATE_DVBT_200A:
if (!dev->autodetected || (dev->eedata[0x41] == 0xd0))
break;
if (dev->eedata[0x41] == 0x02) {
dev->board = SAA7134_BOARD_VIDEOMATE_DVBT_200A;
dev->tuner_type = saa7134_boards[dev->board].tuner_type;
dev->tda9887_conf = saa7134_boards[dev->board].tda9887_conf;
printk(KERN_INFO "%s: Reconfigured board as %s\n",
dev->name, saa7134_boards[dev->board].name);
} else {
printk(KERN_WARNING "%s: Unexpected tuner type info: %x in eeprom\n",
dev->name, dev->eedata[0x41]);
break;
}
break;
case SAA7134_BOARD_ADS_INSTANT_HDTV_PCI:
case SAA7134_BOARD_KWORLD_ATSC110:
{
struct i2c_msg msg = { .addr = 0x0a, .flags = 0 };
int i;
static u8 buffer[][2] = {
{ 0x10, 0x12 },
{ 0x13, 0x04 },
{ 0x16, 0x00 },
{ 0x14, 0x04 },
{ 0x17, 0x00 },
};
for (i = 0; i < ARRAY_SIZE(buffer); i++) {
msg.buf = &buffer[i][0];
msg.len = ARRAY_SIZE(buffer[0]);
if (i2c_transfer(&dev->i2c_adap, &msg, 1) != 1)
printk(KERN_WARNING
"%s: Unable to enable tuner(%i).\n",
dev->name, i);
}
break;
}
case SAA7134_BOARD_BEHOLD_H6:
{
u8 data[] = { 0x09, 0x9f, 0x86, 0x11};
struct i2c_msg msg = {.addr = 0x61, .flags = 0, .buf = data,
.len = sizeof(data)};
if (i2c_transfer(&dev->i2c_adap, &msg, 1) != 1)
printk(KERN_WARNING
"%s: Unable to enable IF of the tuner.\n",
dev->name);
break;
}
case SAA7134_BOARD_KWORLD_PCI_SBTVD_FULLSEG:
saa_writel(SAA7134_GPIO_GPMODE0 >> 2, 0x4000);
saa_writel(SAA7134_GPIO_GPSTATUS0 >> 2, 0x4000);
saa7134_set_gpio(dev, 27, 0);
break;
}
if (TUNER_ABSENT != dev->tuner_type) {
int has_demod = (dev->tda9887_conf & TDA9887_PRESENT);
if (dev->radio_type != UNSET)
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
dev->radio_addr, NULL);
if (has_demod)
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
if (dev->tuner_addr == ADDR_UNSET) {
enum v4l2_i2c_tuner_type type =
has_demod ? ADDRS_TV_WITH_DEMOD : ADDRS_TV;
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(type));
} else {
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_adap, "tuner",
dev->tuner_addr, NULL);
}
}
saa7134_tuner_setup(dev);
switch (dev->board) {
case SAA7134_BOARD_BEHOLD_COLUMBUS_TVFM:
case SAA7134_BOARD_AVERMEDIA_CARDBUS_501:
{
struct v4l2_priv_tun_config tea5767_cfg;
struct tea5767_ctrl ctl;
dev->i2c_client.addr = 0xC0;
memset(&ctl, 0, sizeof(ctl));
ctl.xtal_freq = TEA5767_HIGH_LO_13MHz;
tea5767_cfg.tuner = TUNER_TEA5767;
tea5767_cfg.priv = &ctl;
saa_call_all(dev, tuner, s_config, &tea5767_cfg);
break;
}
}
return 0;
}
