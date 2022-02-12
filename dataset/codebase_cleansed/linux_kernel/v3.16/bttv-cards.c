void bttv_idcard(struct bttv *btv)
{
unsigned int gpiobits;
int i,type;
btv->cardid = btv->c.pci->subsystem_device << 16;
btv->cardid |= btv->c.pci->subsystem_vendor;
if (0 != btv->cardid && 0xffffffff != btv->cardid) {
for (type = -1, i = 0; cards[i].id != 0; i++)
if (cards[i].id == btv->cardid)
type = i;
if (type != -1) {
pr_info("%d: detected: %s [card=%d], PCI subsystem ID is %04x:%04x\n",
btv->c.nr, cards[type].name, cards[type].cardnr,
btv->cardid & 0xffff,
(btv->cardid >> 16) & 0xffff);
btv->c.type = cards[type].cardnr;
} else {
pr_info("%d: subsystem: %04x:%04x (UNKNOWN)\n",
btv->c.nr, btv->cardid & 0xffff,
(btv->cardid >> 16) & 0xffff);
pr_debug("please mail id, board name and the correct card= insmod option to linux-media@vger.kernel.org\n");
}
}
if (card[btv->c.nr] < bttv_num_tvcards)
btv->c.type=card[btv->c.nr];
pr_info("%d: using: %s [card=%d,%s]\n",
btv->c.nr, bttv_tvcards[btv->c.type].name, btv->c.type,
card[btv->c.nr] < bttv_num_tvcards
? "insmod option" : "autodetected");
if (UNSET == audioall && UNSET == audiomux[0])
return;
if (UNSET != audiomux[0]) {
gpiobits = 0;
for (i = 0; i < ARRAY_SIZE(bttv_tvcards->gpiomux); i++) {
bttv_tvcards[btv->c.type].gpiomux[i] = audiomux[i];
gpiobits |= audiomux[i];
}
} else {
gpiobits = audioall;
for (i = 0; i < ARRAY_SIZE(bttv_tvcards->gpiomux); i++) {
bttv_tvcards[btv->c.type].gpiomux[i] = audioall;
}
}
bttv_tvcards[btv->c.type].gpiomask = (UNSET != gpiomask) ? gpiomask : gpiobits;
pr_info("%d: gpio config override: mask=0x%x, mux=",
btv->c.nr, bttv_tvcards[btv->c.type].gpiomask);
for (i = 0; i < ARRAY_SIZE(bttv_tvcards->gpiomux); i++) {
pr_cont("%s0x%x",
i ? "," : "", bttv_tvcards[btv->c.type].gpiomux[i]);
}
pr_cont("\n");
}
static void identify_by_eeprom(struct bttv *btv, unsigned char eeprom_data[256])
{
int type = -1;
if (0 == strncmp(eeprom_data,"GET MM20xPCTV",13))
type = BTTV_BOARD_MODTEC_205;
else if (0 == strncmp(eeprom_data+20,"Picolo",7))
type = BTTV_BOARD_EURESYS_PICOLO;
else if (eeprom_data[0] == 0x84 && eeprom_data[2]== 0)
type = BTTV_BOARD_HAUPPAUGE;
if (-1 != type) {
btv->c.type = type;
pr_info("%d: detected by eeprom: %s [card=%d]\n",
btv->c.nr, bttv_tvcards[btv->c.type].name, btv->c.type);
}
}
static void flyvideo_gpio(struct bttv *btv)
{
int gpio, has_remote, has_radio, is_capture_only;
int is_lr90, has_tda9820_tda9821;
int tuner_type = UNSET, ttype;
gpio_inout(0xffffff, 0);
udelay(8);
gpio = gpio_read();
ttype = (gpio & 0x0f0000) >> 16;
switch (ttype) {
case 0x0:
tuner_type = 2;
break;
case 0x2:
tuner_type = 39;
break;
case 0x4:
tuner_type = 5;
break;
case 0x6:
tuner_type = 37;
break;
case 0xC:
tuner_type = 3;
break;
default:
pr_info("%d: FlyVideo_gpio: unknown tuner type\n", btv->c.nr);
break;
}
has_remote = gpio & 0x800000;
has_radio = gpio & 0x400000;
is_capture_only = !(gpio & 0x008000);
has_tda9820_tda9821 = !(gpio & 0x004000);
is_lr90 = !(gpio & 0x002000);
if (is_capture_only)
tuner_type = TUNER_ABSENT;
pr_info("%d: FlyVideo Radio=%s RemoteControl=%s Tuner=%d gpio=0x%06x\n",
btv->c.nr, has_radio ? "yes" : "no",
has_remote ? "yes" : "no", tuner_type, gpio);
pr_info("%d: FlyVideo LR90=%s tda9821/tda9820=%s capture_only=%s\n",
btv->c.nr, is_lr90 ? "yes" : "no",
has_tda9820_tda9821 ? "yes" : "no",
is_capture_only ? "yes" : "no");
if (tuner_type != UNSET)
btv->tuner_type = tuner_type;
btv->has_radio = has_radio;
if (has_tda9820_tda9821)
btv->audio_mode_gpio = lt9415_audio;
}
static void miro_pinnacle_gpio(struct bttv *btv)
{
int id,msp,gpio;
char *info;
gpio_inout(0xffffff, 0);
gpio = gpio_read();
id = ((gpio>>10) & 63) -1;
msp = bttv_I2CRead(btv, I2C_ADDR_MSP3400, "MSP34xx");
if (id < 32) {
btv->tuner_type = miro_tunermap[id];
if (0 == (gpio & 0x20)) {
btv->has_radio = 1;
if (!miro_fmtuner[id]) {
btv->has_matchbox = 1;
btv->mbox_we = (1<<6);
btv->mbox_most = (1<<7);
btv->mbox_clk = (1<<8);
btv->mbox_data = (1<<9);
btv->mbox_mask = (1<<6)|(1<<7)|(1<<8)|(1<<9);
}
} else {
btv->has_radio = 0;
}
if (-1 != msp) {
if (btv->c.type == BTTV_BOARD_MIRO)
btv->c.type = BTTV_BOARD_MIROPRO;
if (btv->c.type == BTTV_BOARD_PINNACLE)
btv->c.type = BTTV_BOARD_PINNACLEPRO;
}
pr_info("%d: miro: id=%d tuner=%d radio=%s stereo=%s\n",
btv->c.nr, id+1, btv->tuner_type,
!btv->has_radio ? "no" :
(btv->has_matchbox ? "matchbox" : "fmtuner"),
(-1 == msp) ? "no" : "yes");
} else {
id = 63 - id;
btv->has_radio = 0;
switch (id) {
case 1:
info = "PAL / mono";
btv->tda9887_conf = TDA9887_INTERCARRIER;
break;
case 2:
info = "PAL+SECAM / stereo";
btv->has_radio = 1;
btv->tda9887_conf = TDA9887_QSS;
break;
case 3:
info = "NTSC / stereo";
btv->has_radio = 1;
btv->tda9887_conf = TDA9887_QSS;
break;
case 4:
info = "PAL+SECAM / mono";
btv->tda9887_conf = TDA9887_QSS;
break;
case 5:
info = "NTSC / mono";
btv->tda9887_conf = TDA9887_INTERCARRIER;
break;
case 6:
info = "NTSC / stereo";
btv->tda9887_conf = TDA9887_INTERCARRIER;
break;
case 7:
info = "PAL / stereo";
btv->tda9887_conf = TDA9887_INTERCARRIER;
break;
default:
info = "oops: unknown card";
break;
}
if (-1 != msp)
btv->c.type = BTTV_BOARD_PINNACLEPRO;
pr_info("%d: pinnacle/mt: id=%d info=\"%s\" radio=%s\n",
btv->c.nr, id, info, btv->has_radio ? "yes" : "no");
btv->tuner_type = TUNER_MT2032;
}
}
static void init_ids_eagle(struct bttv *btv)
{
gpio_inout(0xffffff,0xFFFF37);
gpio_write(0x200020);
gpio_write(0x200024);
gpio_bits(LM1882_SYNC_DRIVE,LM1882_SYNC_DRIVE);
btaor((2)<<5, ~(2<<5), BT848_IFORM);
}
static void eagle_muxsel(struct bttv *btv, unsigned int input)
{
gpio_bits(3, input & 3);
btor(BT848_ADC_C_SLEEP, BT848_ADC);
btand(~BT848_CONTROL_COMP, BT848_E_CONTROL);
btand(~BT848_CONTROL_COMP, BT848_O_CONTROL);
gpio_bits(LM1882_SYNC_DRIVE,LM1882_SYNC_DRIVE);
}
static void gvc1100_muxsel(struct bttv *btv, unsigned int input)
{
static const int masks[] = {0x30, 0x01, 0x12, 0x23};
gpio_write(masks[input%4]);
}
static void init_lmlbt4x(struct bttv *btv)
{
pr_debug("LMLBT4x init\n");
btwrite(0x000000, BT848_GPIO_REG_INP);
gpio_inout(0xffffff, 0x0006C0);
gpio_write(0x000000);
}
static void sigmaSQ_muxsel(struct bttv *btv, unsigned int input)
{
unsigned int inmux = input % 8;
gpio_inout( 0xf, 0xf );
gpio_bits( 0xf, inmux );
}
static void sigmaSLC_muxsel(struct bttv *btv, unsigned int input)
{
unsigned int inmux = input % 4;
gpio_inout( 3<<9, 3<<9 );
gpio_bits( 3<<9, inmux<<9 );
}
static void geovision_muxsel(struct bttv *btv, unsigned int input)
{
unsigned int inmux = input % 16;
gpio_inout(0xf, 0xf);
gpio_bits(0xf, inmux);
}
static void td3116_latch_value(struct bttv *btv, u32 value)
{
gpio_bits((1<<18) | 0xff, value);
gpio_bits((1<<18) | 0xff, (1<<18) | value);
udelay(1);
gpio_bits((1<<18) | 0xff, value);
}
static void td3116_muxsel(struct bttv *btv, unsigned int input)
{
u32 value;
u32 highbit;
highbit = (input & 0x8) >> 3 ;
value = 0x11;
value |= ((input & 0x7) << 1) << (4 * highbit);
td3116_latch_value(btv, value);
value &= ~0x11;
value |= ((highbit ^ 0x1) << 4) | highbit;
td3116_latch_value(btv, value);
}
static void bttv_reset_audio(struct bttv *btv)
{
if (btv->id != 878)
return;
if (bttv_debug)
pr_debug("%d: BT878A ARESET\n", btv->c.nr);
btwrite((1<<7), 0x058);
udelay(10);
btwrite( 0, 0x058);
}
void bttv_init_card1(struct bttv *btv)
{
switch (btv->c.type) {
case BTTV_BOARD_HAUPPAUGE:
case BTTV_BOARD_HAUPPAUGE878:
boot_msp34xx(btv,5);
break;
case BTTV_BOARD_VOODOOTV_200:
case BTTV_BOARD_VOODOOTV_FM:
boot_msp34xx(btv,20);
break;
case BTTV_BOARD_AVERMEDIA98:
boot_msp34xx(btv,11);
break;
case BTTV_BOARD_HAUPPAUGEPVR:
pvr_boot(btv);
break;
case BTTV_BOARD_TWINHAN_DST:
case BTTV_BOARD_AVDVBT_771:
case BTTV_BOARD_PINNACLESAT:
btv->use_i2c_hw = 1;
break;
case BTTV_BOARD_ADLINK_RTV24:
init_RTV24( btv );
break;
case BTTV_BOARD_PCI_8604PW:
init_PCI8604PW(btv);
break;
}
if (!bttv_tvcards[btv->c.type].has_dvb)
bttv_reset_audio(btv);
}
void bttv_init_card2(struct bttv *btv)
{
btv->tuner_type = UNSET;
if (BTTV_BOARD_UNKNOWN == btv->c.type) {
bttv_readee(btv,eeprom_data,0xa0);
identify_by_eeprom(btv,eeprom_data);
}
switch (btv->c.type) {
case BTTV_BOARD_MIRO:
case BTTV_BOARD_MIROPRO:
case BTTV_BOARD_PINNACLE:
case BTTV_BOARD_PINNACLEPRO:
miro_pinnacle_gpio(btv);
break;
case BTTV_BOARD_FLYVIDEO_98:
case BTTV_BOARD_MAXI:
case BTTV_BOARD_LIFE_FLYKIT:
case BTTV_BOARD_FLYVIDEO:
case BTTV_BOARD_TYPHOON_TVIEW:
case BTTV_BOARD_CHRONOS_VS2:
case BTTV_BOARD_FLYVIDEO_98FM:
case BTTV_BOARD_FLYVIDEO2000:
case BTTV_BOARD_FLYVIDEO98EZ:
case BTTV_BOARD_CONFERENCETV:
case BTTV_BOARD_LIFETEC_9415:
flyvideo_gpio(btv);
break;
case BTTV_BOARD_HAUPPAUGE:
case BTTV_BOARD_HAUPPAUGE878:
case BTTV_BOARD_HAUPPAUGEPVR:
bttv_readee(btv,eeprom_data,0xa0);
hauppauge_eeprom(btv);
break;
case BTTV_BOARD_AVERMEDIA98:
case BTTV_BOARD_AVPHONE98:
bttv_readee(btv,eeprom_data,0xa0);
avermedia_eeprom(btv);
break;
case BTTV_BOARD_PXC200:
init_PXC200(btv);
break;
case BTTV_BOARD_PICOLO_TETRA_CHIP:
picolo_tetra_init(btv);
break;
case BTTV_BOARD_VHX:
btv->has_radio = 1;
btv->has_matchbox = 1;
btv->mbox_we = 0x20;
btv->mbox_most = 0;
btv->mbox_clk = 0x08;
btv->mbox_data = 0x10;
btv->mbox_mask = 0x38;
break;
case BTTV_BOARD_VOBIS_BOOSTAR:
case BTTV_BOARD_TERRATV:
terratec_active_radio_upgrade(btv);
break;
case BTTV_BOARD_MAGICTVIEW061:
if (btv->cardid == 0x3002144f) {
btv->has_radio=1;
pr_info("%d: radio detected by subsystem id (CPH05x)\n",
btv->c.nr);
}
break;
case BTTV_BOARD_STB2:
if (btv->cardid == 0x3060121a) {
btv->has_radio=0;
btv->tuner_type=TUNER_TEMIC_NTSC;
}
break;
case BTTV_BOARD_OSPREY1x0:
case BTTV_BOARD_OSPREY1x0_848:
case BTTV_BOARD_OSPREY101_848:
case BTTV_BOARD_OSPREY1x1:
case BTTV_BOARD_OSPREY1x1_SVID:
case BTTV_BOARD_OSPREY2xx:
case BTTV_BOARD_OSPREY2x0_SVID:
case BTTV_BOARD_OSPREY2x0:
case BTTV_BOARD_OSPREY440:
case BTTV_BOARD_OSPREY500:
case BTTV_BOARD_OSPREY540:
case BTTV_BOARD_OSPREY2000:
bttv_readee(btv,eeprom_data,0xa0);
osprey_eeprom(btv, eeprom_data);
break;
case BTTV_BOARD_IDS_EAGLE:
init_ids_eagle(btv);
break;
case BTTV_BOARD_MODTEC_205:
bttv_readee(btv,eeprom_data,0xa0);
modtec_eeprom(btv);
break;
case BTTV_BOARD_LMLBT4:
init_lmlbt4x(btv);
break;
case BTTV_BOARD_TIBET_CS16:
tibetCS16_init(btv);
break;
case BTTV_BOARD_KODICOM_4400R:
kodicom4400r_init(btv);
break;
case BTTV_BOARD_GEOVISION_GV800S:
gv800s_init(btv);
break;
}
if (!(btv->id==848 && btv->revision==0x11)) {
if (PLL_28 == bttv_tvcards[btv->c.type].pll) {
btv->pll.pll_ifreq=28636363;
btv->pll.pll_crystal=BT848_IFORM_XT0;
}
if (PLL_35 == bttv_tvcards[btv->c.type].pll) {
btv->pll.pll_ifreq=35468950;
btv->pll.pll_crystal=BT848_IFORM_XT1;
}
if (PLL_14 == bttv_tvcards[btv->c.type].pll) {
btv->pll.pll_ifreq = 14318181;
btv->pll.pll_crystal = BT848_IFORM_XT0;
}
switch (pll[btv->c.nr]) {
case 0:
btv->pll.pll_crystal = 0;
btv->pll.pll_ifreq = 0;
btv->pll.pll_ofreq = 0;
break;
case 1:
case 28:
btv->pll.pll_ifreq = 28636363;
btv->pll.pll_ofreq = 0;
btv->pll.pll_crystal = BT848_IFORM_XT0;
break;
case 2:
case 35:
btv->pll.pll_ifreq = 35468950;
btv->pll.pll_ofreq = 0;
btv->pll.pll_crystal = BT848_IFORM_XT1;
break;
case 3:
case 14:
btv->pll.pll_ifreq = 14318181;
btv->pll.pll_ofreq = 0;
btv->pll.pll_crystal = BT848_IFORM_XT0;
break;
}
}
btv->pll.pll_current = -1;
if (UNSET != bttv_tvcards[btv->c.type].tuner_type)
if (UNSET == btv->tuner_type)
btv->tuner_type = bttv_tvcards[btv->c.type].tuner_type;
if (UNSET != tuner[btv->c.nr])
btv->tuner_type = tuner[btv->c.nr];
if (btv->tuner_type == TUNER_ABSENT)
pr_info("%d: tuner absent\n", btv->c.nr);
else if (btv->tuner_type == UNSET)
pr_warn("%d: tuner type unset\n", btv->c.nr);
else
pr_info("%d: tuner type=%d\n", btv->c.nr, btv->tuner_type);
if (autoload != UNSET) {
pr_warn("%d: the autoload option is obsolete\n", btv->c.nr);
pr_warn("%d: use option msp3400, tda7432 or tvaudio to override which audio module should be used\n",
btv->c.nr);
}
if (UNSET == btv->tuner_type)
btv->tuner_type = TUNER_ABSENT;
btv->dig = bttv_tvcards[btv->c.type].has_dig_in ?
bttv_tvcards[btv->c.type].video_inputs - 1 : UNSET;
btv->svhs = bttv_tvcards[btv->c.type].svhs == NO_SVHS ?
UNSET : bttv_tvcards[btv->c.type].svhs;
if (svhs[btv->c.nr] != UNSET)
btv->svhs = svhs[btv->c.nr];
if (remote[btv->c.nr] != UNSET)
btv->has_remote = remote[btv->c.nr];
if (bttv_tvcards[btv->c.type].has_radio)
btv->has_radio = 1;
if (bttv_tvcards[btv->c.type].has_remote)
btv->has_remote = 1;
if (!bttv_tvcards[btv->c.type].no_gpioirq)
btv->gpioirq = 1;
if (bttv_tvcards[btv->c.type].volume_gpio)
btv->volume_gpio = bttv_tvcards[btv->c.type].volume_gpio;
if (bttv_tvcards[btv->c.type].audio_mode_gpio)
btv->audio_mode_gpio = bttv_tvcards[btv->c.type].audio_mode_gpio;
if (btv->tuner_type == TUNER_ABSENT)
return;
if (btv->has_saa6588 || saa6588[btv->c.nr]) {
static const unsigned short addrs[] = {
0x20 >> 1,
0x22 >> 1,
I2C_CLIENT_END
};
struct v4l2_subdev *sd;
sd = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "saa6588", 0, addrs);
btv->has_saa6588 = (sd != NULL);
}
switch (audiodev[btv->c.nr]) {
case -1:
return;
case 0:
break;
case 1: {
static const unsigned short addrs[] = {
I2C_ADDR_MSP3400 >> 1,
I2C_ADDR_MSP3400_ALT >> 1,
I2C_CLIENT_END
};
btv->sd_msp34xx = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "msp3400", 0, addrs);
if (btv->sd_msp34xx)
return;
goto no_audio;
}
case 2: {
static const unsigned short addrs[] = {
I2C_ADDR_TDA7432 >> 1,
I2C_CLIENT_END
};
if (v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tda7432", 0, addrs))
return;
goto no_audio;
}
case 3: {
btv->sd_tvaudio = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tvaudio", 0, tvaudio_addrs());
if (btv->sd_tvaudio)
return;
goto no_audio;
}
default:
pr_warn("%d: unknown audiodev value!\n", btv->c.nr);
return;
}
if (!bttv_tvcards[btv->c.type].no_msp34xx) {
btv->sd_msp34xx = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "msp3400",
0, I2C_ADDRS(I2C_ADDR_MSP3400 >> 1));
} else if (bttv_tvcards[btv->c.type].msp34xx_alt) {
btv->sd_msp34xx = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "msp3400",
0, I2C_ADDRS(I2C_ADDR_MSP3400_ALT >> 1));
}
if (btv->sd_msp34xx)
return;
btv->sd_tvaudio = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tvaudio", 0, tvaudio_addrs());
if (btv->sd_tvaudio) {
v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tvaudio", 0, tvaudio_addrs());
}
if (!bttv_tvcards[btv->c.type].no_tda7432) {
static const unsigned short addrs[] = {
I2C_ADDR_TDA7432 >> 1,
I2C_CLIENT_END
};
btv->sd_tda7432 = v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tda7432", 0, addrs);
if (btv->sd_tda7432)
return;
}
if (btv->sd_tvaudio)
return;
no_audio:
pr_warn("%d: audio absent, no audio device found!\n", btv->c.nr);
}
void bttv_init_tuner(struct bttv *btv)
{
int addr = ADDR_UNSET;
if (ADDR_UNSET != bttv_tvcards[btv->c.type].tuner_addr)
addr = bttv_tvcards[btv->c.type].tuner_addr;
if (btv->tuner_type != TUNER_ABSENT) {
struct tuner_setup tun_setup;
if (btv->has_radio)
v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_RADIO));
v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
v4l2_i2c_new_subdev(&btv->c.v4l2_dev,
&btv->c.i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_TV_WITH_DEMOD));
tun_setup.mode_mask = T_ANALOG_TV;
tun_setup.type = btv->tuner_type;
tun_setup.addr = addr;
if (btv->has_radio)
tun_setup.mode_mask |= T_RADIO;
bttv_call_all(btv, tuner, s_type_addr, &tun_setup);
}
if (btv->tda9887_conf) {
struct v4l2_priv_tun_config tda9887_cfg;
tda9887_cfg.tuner = TUNER_TDA9887;
tda9887_cfg.priv = &btv->tda9887_conf;
bttv_call_all(btv, tuner, s_config, &tda9887_cfg);
}
}
static void modtec_eeprom(struct bttv *btv)
{
if( strncmp(&(eeprom_data[0x1e]),"Temic 4066 FY5",14) ==0) {
btv->tuner_type=TUNER_TEMIC_4066FY5_PAL_I;
pr_info("%d: Modtec: Tuner autodetected by eeprom: %s\n",
btv->c.nr, &eeprom_data[0x1e]);
} else if (strncmp(&(eeprom_data[0x1e]),"Alps TSBB5",10) ==0) {
btv->tuner_type=TUNER_ALPS_TSBB5_PAL_I;
pr_info("%d: Modtec: Tuner autodetected by eeprom: %s\n",
btv->c.nr, &eeprom_data[0x1e]);
} else if (strncmp(&(eeprom_data[0x1e]),"Philips FM1246",14) ==0) {
btv->tuner_type=TUNER_PHILIPS_NTSC;
pr_info("%d: Modtec: Tuner autodetected by eeprom: %s\n",
btv->c.nr, &eeprom_data[0x1e]);
} else {
pr_info("%d: Modtec: Unknown TunerString: %s\n",
btv->c.nr, &eeprom_data[0x1e]);
}
}
static void hauppauge_eeprom(struct bttv *btv)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&btv->i2c_client, &tv, eeprom_data);
btv->tuner_type = tv.tuner_type;
btv->has_radio = tv.has_radio;
pr_info("%d: Hauppauge eeprom indicates model#%d\n",
btv->c.nr, tv.model);
if(tv.model == 64900) {
pr_info("%d: Switching board type from %s to %s\n",
btv->c.nr,
bttv_tvcards[btv->c.type].name,
bttv_tvcards[BTTV_BOARD_HAUPPAUGE_IMPACTVCB].name);
btv->c.type = BTTV_BOARD_HAUPPAUGE_IMPACTVCB;
}
if (tv.model == 61334)
btv->radio_uses_msp_demodulator = 1;
}
static int terratec_active_radio_upgrade(struct bttv *btv)
{
int freq;
btv->has_radio = 1;
btv->has_matchbox = 1;
btv->mbox_we = 0x10;
btv->mbox_most = 0x20;
btv->mbox_clk = 0x08;
btv->mbox_data = 0x04;
btv->mbox_mask = 0x3c;
btv->mbox_iow = 1 << 8;
btv->mbox_ior = 1 << 9;
btv->mbox_csel = 1 << 10;
freq=88000/62.5;
tea5757_write(btv, 5 * freq + 0x358);
if (0x1ed8 == tea5757_read(btv)) {
pr_info("%d: Terratec Active Radio Upgrade found\n", btv->c.nr);
btv->has_radio = 1;
btv->has_saa6588 = 1;
btv->has_matchbox = 1;
} else {
btv->has_radio = 0;
btv->has_matchbox = 0;
}
return 0;
}
static int pvr_altera_load(struct bttv *btv, const u8 *micro, u32 microlen)
{
u32 n;
u8 bits;
int i;
gpio_inout(0xffffff,BTTV_ALT_DATA|BTTV_ALT_DCLK|BTTV_ALT_NCONFIG);
gpio_write(0);
udelay(PVR_GPIO_DELAY);
gpio_write(BTTV_ALT_NCONFIG);
udelay(PVR_GPIO_DELAY);
for (n = 0; n < microlen; n++) {
bits = micro[n];
for (i = 0 ; i < 8 ; i++) {
gpio_bits(BTTV_ALT_DCLK,0);
if (bits & 0x01)
gpio_bits(BTTV_ALT_DATA,BTTV_ALT_DATA);
else
gpio_bits(BTTV_ALT_DATA,0);
gpio_bits(BTTV_ALT_DCLK,BTTV_ALT_DCLK);
bits >>= 1;
}
}
gpio_bits(BTTV_ALT_DCLK,0);
udelay(PVR_GPIO_DELAY);
for (i = 0 ; i < 30 ; i++) {
gpio_bits(BTTV_ALT_DCLK,0);
gpio_bits(BTTV_ALT_DCLK,BTTV_ALT_DCLK);
}
gpio_bits(BTTV_ALT_DCLK,0);
return 0;
}
static int pvr_boot(struct bttv *btv)
{
const struct firmware *fw_entry;
int rc;
rc = request_firmware(&fw_entry, "hcwamc.rbf", &btv->c.pci->dev);
if (rc != 0) {
pr_warn("%d: no altera firmware [via hotplug]\n", btv->c.nr);
return rc;
}
rc = pvr_altera_load(btv, fw_entry->data, fw_entry->size);
pr_info("%d: altera firmware upload %s\n",
btv->c.nr, (rc < 0) ? "failed" : "ok");
release_firmware(fw_entry);
return rc;
}
static void osprey_eeprom(struct bttv *btv, const u8 ee[256])
{
int i;
u32 serial = 0;
int cardid = -1;
if (btv->c.type == BTTV_BOARD_UNKNOWN) {
if (!strncmp(ee, "MMAC", 4)) {
u8 checksum = 0;
for (i = 0; i < 21; i++)
checksum += ee[i];
if (checksum != ee[21])
return;
cardid = BTTV_BOARD_OSPREY1x0_848;
for (i = 12; i < 21; i++)
serial *= 10, serial += ee[i] - '0';
}
} else {
unsigned short type;
for (i = 4*16; i < 8*16; i += 16) {
u16 checksum = ip_compute_csum(ee + i, 16);
if ((checksum&0xff) + (checksum>>8) == 0xff)
break;
}
if (i >= 8*16)
return;
ee += i;
type = get_unaligned_be16((__be16 *)(ee+4));
switch(type) {
case 0x0004:
cardid = BTTV_BOARD_OSPREY1x0_848;
break;
case 0x0005:
cardid = BTTV_BOARD_OSPREY101_848;
break;
case 0x0012:
case 0x0013:
cardid = BTTV_BOARD_OSPREY1x0;
break;
case 0x0014:
case 0x0015:
cardid = BTTV_BOARD_OSPREY1x1;
break;
case 0x0016:
case 0x0017:
case 0x0020:
cardid = BTTV_BOARD_OSPREY1x1_SVID;
break;
case 0x0018:
case 0x0019:
case 0x001E:
case 0x001F:
cardid = BTTV_BOARD_OSPREY2xx;
break;
case 0x001A:
case 0x001B:
cardid = BTTV_BOARD_OSPREY2x0_SVID;
break;
case 0x0040:
cardid = BTTV_BOARD_OSPREY500;
break;
case 0x0050:
case 0x0056:
cardid = BTTV_BOARD_OSPREY540;
break;
case 0x0060:
case 0x0070:
case 0x00A0:
cardid = BTTV_BOARD_OSPREY2x0;
gpio_inout(0xffffff,0x000303);
break;
case 0x00D8:
cardid = BTTV_BOARD_OSPREY440;
break;
default:
pr_info("%d: osprey eeprom: unknown card type 0x%04x\n",
btv->c.nr, type);
break;
}
serial = get_unaligned_be32((__be32 *)(ee+6));
}
pr_info("%d: osprey eeprom: card=%d '%s' serial=%u\n",
btv->c.nr, cardid,
cardid > 0 ? bttv_tvcards[cardid].name : "Unknown", serial);
if (cardid<0 || btv->c.type == cardid)
return;
if (card[btv->c.nr] < bttv_num_tvcards) {
pr_warn("%d: osprey eeprom: Not overriding user specified card type\n",
btv->c.nr);
} else {
pr_info("%d: osprey eeprom: Changing card type from %d to %d\n",
btv->c.nr, btv->c.type, cardid);
btv->c.type = cardid;
}
}
static void avermedia_eeprom(struct bttv *btv)
{
int tuner_make, tuner_tv_fm, tuner_format, tuner_type = 0;
tuner_make = (eeprom_data[0x41] & 0x7);
tuner_tv_fm = (eeprom_data[0x41] & 0x18) >> 3;
tuner_format = (eeprom_data[0x42] & 0xf0) >> 4;
btv->has_remote = (eeprom_data[0x42] & 0x01);
if (tuner_make == 0 || tuner_make == 2)
if (tuner_format <= 0x0a)
tuner_type = tuner_0_table[tuner_format];
if (tuner_make == 1)
if (tuner_format <= 9)
tuner_type = tuner_1_table[tuner_format];
if (tuner_make == 4)
if (tuner_format == 0x09)
tuner_type = TUNER_LG_NTSC_NEW_TAPC;
pr_info("%d: Avermedia eeprom[0x%02x%02x]: tuner=",
btv->c.nr, eeprom_data[0x41], eeprom_data[0x42]);
if (tuner_type) {
btv->tuner_type = tuner_type;
pr_cont("%d", tuner_type);
} else
pr_cont("Unknown type");
pr_cont(" radio:%s remote control:%s\n",
tuner_tv_fm ? "yes" : "no",
btv->has_remote ? "yes" : "no");
}
u32 bttv_tda9880_setnorm(struct bttv *btv, u32 gpiobits)
{
if (btv->audio_input == TVAUDIO_INPUT_TUNER) {
if (bttv_tvnorms[btv->tvnorm].v4l2_id & V4L2_STD_MN)
gpiobits |= 0x10000;
else
gpiobits &= ~0x10000;
}
gpio_bits(bttv_tvcards[btv->c.type].gpiomask, gpiobits);
return gpiobits;
}
static void boot_msp34xx(struct bttv *btv, int pin)
{
int mask = (1 << pin);
gpio_inout(mask,mask);
gpio_bits(mask,0);
mdelay(2);
udelay(500);
gpio_bits(mask,mask);
if (bttv_gpio)
bttv_gpio_tracking(btv,"msp34xx");
if (bttv_verbose)
pr_info("%d: Hauppauge/Voodoo msp34xx: reset line init [%d]\n",
btv->c.nr, pin);
}
static void init_PXC200(struct bttv *btv)
{
static int vals[] = { 0x08, 0x09, 0x0a, 0x0b, 0x0d, 0x0d, 0x01, 0x02,
0x03, 0x04, 0x05, 0x06, 0x00 };
unsigned int i;
int tmp;
u32 val;
gpio_inout(0xffffff, (1<<13));
gpio_write(0);
udelay(3);
gpio_write(1<<13);
gpio_bits(0xffffff, 0);
if (bttv_gpio)
bttv_gpio_tracking(btv,"pxc200");
btwrite(BT848_ADC_RESERVED|BT848_ADC_AGC_EN, BT848_ADC);
pr_info("Setting DAC reference voltage level ...\n");
bttv_I2CWrite(btv,0x5E,0,0x80,1);
pr_info("Initialising 12C508 PIC chip ...\n");
val = btread(BT848_GPIO_DMA_CTL);
val |= BT848_GPIO_DMA_CTL_GPCLKMODE;
btwrite(val, BT848_GPIO_DMA_CTL);
gpio_inout(0xffffff,(1<<2));
gpio_write(0);
udelay(10);
gpio_write(1<<2);
for (i = 0; i < ARRAY_SIZE(vals); i++) {
tmp=bttv_I2CWrite(btv,0x1E,0,vals[i],1);
if (tmp != -1) {
pr_info("I2C Write(%2.2x) = %i\nI2C Read () = %2.2x\n\n",
vals[i],tmp,bttv_I2CRead(btv,0x1F,NULL));
}
}
pr_info("PXC200 Initialised\n");
}
static void
init_RTV24 (struct bttv *btv)
{
uint32_t dataRead = 0;
long watchdog_value = 0x0E;
pr_info("%d: Adlink RTV-24 initialisation in progress ...\n",
btv->c.nr);
btwrite (0x00c3feff, BT848_GPIO_OUT_EN);
btwrite (0 + watchdog_value, BT848_GPIO_DATA);
msleep (1);
btwrite (0x10 + watchdog_value, BT848_GPIO_DATA);
msleep (10);
btwrite (0 + watchdog_value, BT848_GPIO_DATA);
dataRead = btread (BT848_GPIO_DATA);
if ((((dataRead >> 18) & 0x01) != 0) || (((dataRead >> 19) & 0x01) != 1)) {
pr_info("%d: Adlink RTV-24 initialisation(1) ERROR_CPLD_Check_Failed (read %d)\n",
btv->c.nr, dataRead);
}
btwrite (0x4400 + watchdog_value, BT848_GPIO_DATA);
msleep (10);
btwrite (0x4410 + watchdog_value, BT848_GPIO_DATA);
msleep (1);
btwrite (watchdog_value, BT848_GPIO_DATA);
msleep (1);
dataRead = btread (BT848_GPIO_DATA);
if ((((dataRead >> 18) & 0x01) != 0) || (((dataRead >> 19) & 0x01) != 0)) {
pr_info("%d: Adlink RTV-24 initialisation(2) ERROR_CPLD_Check_Failed (read %d)\n",
btv->c.nr, dataRead);
return;
}
pr_info("%d: Adlink RTV-24 initialisation complete\n", btv->c.nr);
}
static void
init_PCI8604PW(struct bttv *btv)
{
int state;
if ((PCI_SLOT(btv->c.pci->devfn) & ~3) != 0xC) {
pr_warn("This is not a PCI-8604PW\n");
return;
}
if (PCI_SLOT(btv->c.pci->devfn) != 0xD)
return;
btwrite(0x080002, BT848_GPIO_OUT_EN);
state = (btread(BT848_GPIO_DATA) >> 21) & 7;
for (;;) {
switch (state) {
case 1:
case 5:
case 6:
case 4:
pr_debug("PCI-8604PW in state %i, toggling pin\n",
state);
btwrite(0x080000, BT848_GPIO_DATA);
msleep(1);
btwrite(0x000000, BT848_GPIO_DATA);
msleep(1);
break;
case 7:
pr_info("PCI-8604PW unlocked\n");
return;
case 0:
pr_err("PCI-8604PW locked until reset\n");
return;
default:
pr_err("PCI-8604PW in unknown state %i\n", state);
return;
}
state = (state << 4) | ((btread(BT848_GPIO_DATA) >> 21) & 7);
switch (state) {
case 0x15:
case 0x56:
case 0x64:
case 0x47:
break;
default:
pr_err("PCI-8604PW invalid transition %i -> %i\n",
state >> 4, state & 7);
return;
}
state &= 7;
}
}
static void bus_low(struct bttv *btv, int bit)
{
if (btv->mbox_ior) {
gpio_bits(btv->mbox_ior | btv->mbox_iow | btv->mbox_csel,
btv->mbox_ior | btv->mbox_iow | btv->mbox_csel);
udelay(5);
}
gpio_bits(bit,0);
udelay(5);
if (btv->mbox_ior) {
gpio_bits(btv->mbox_iow | btv->mbox_csel, 0);
udelay(5);
}
}
static void bus_high(struct bttv *btv, int bit)
{
if (btv->mbox_ior) {
gpio_bits(btv->mbox_ior | btv->mbox_iow | btv->mbox_csel,
btv->mbox_ior | btv->mbox_iow | btv->mbox_csel);
udelay(5);
}
gpio_bits(bit,bit);
udelay(5);
if (btv->mbox_ior) {
gpio_bits(btv->mbox_iow | btv->mbox_csel, 0);
udelay(5);
}
}
static int bus_in(struct bttv *btv, int bit)
{
if (btv->mbox_ior) {
gpio_bits(btv->mbox_ior | btv->mbox_iow | btv->mbox_csel,
btv->mbox_ior | btv->mbox_iow | btv->mbox_csel);
udelay(5);
gpio_bits(btv->mbox_iow | btv->mbox_csel, 0);
udelay(5);
}
return gpio_read() & (bit);
}
static int tea5757_read(struct bttv *btv)
{
unsigned long timeout;
int value = 0;
int i;
gpio_inout(btv->mbox_mask, btv->mbox_clk | btv->mbox_we);
if (btv->mbox_ior) {
gpio_bits(btv->mbox_ior | btv->mbox_iow | btv->mbox_csel,
btv->mbox_ior | btv->mbox_iow | btv->mbox_csel);
udelay(5);
}
if (bttv_gpio)
bttv_gpio_tracking(btv,"tea5757 read");
bus_low(btv,btv->mbox_we);
bus_low(btv,btv->mbox_clk);
udelay(10);
timeout= jiffies + msecs_to_jiffies(1000);
while (bus_in(btv,btv->mbox_data) && time_before(jiffies, timeout))
schedule();
if (bus_in(btv,btv->mbox_data)) {
pr_warn("%d: tea5757: read timeout\n", btv->c.nr);
return -1;
}
dprintk("%d: tea5757:", btv->c.nr);
for (i = 0; i < 24; i++) {
udelay(5);
bus_high(btv,btv->mbox_clk);
udelay(5);
dprintk_cont("%c",
bus_in(btv, btv->mbox_most) == 0 ? 'T' : '-');
bus_low(btv,btv->mbox_clk);
value <<= 1;
value |= (bus_in(btv,btv->mbox_data) == 0)?0:1;
dprintk_cont("%c",
bus_in(btv, btv->mbox_most) == 0 ? 'S' : 'M');
}
dprintk_cont("\n");
dprintk("%d: tea5757: read 0x%X\n", btv->c.nr, value);
return value;
}
static int tea5757_write(struct bttv *btv, int value)
{
int i;
int reg = value;
gpio_inout(btv->mbox_mask, btv->mbox_clk | btv->mbox_we | btv->mbox_data);
if (btv->mbox_ior) {
gpio_bits(btv->mbox_ior | btv->mbox_iow | btv->mbox_csel,
btv->mbox_ior | btv->mbox_iow | btv->mbox_csel);
udelay(5);
}
if (bttv_gpio)
bttv_gpio_tracking(btv,"tea5757 write");
dprintk("%d: tea5757: write 0x%X\n", btv->c.nr, value);
bus_low(btv,btv->mbox_clk);
bus_high(btv,btv->mbox_we);
for (i = 0; i < 25; i++) {
if (reg & 0x1000000)
bus_high(btv,btv->mbox_data);
else
bus_low(btv,btv->mbox_data);
reg <<= 1;
bus_high(btv,btv->mbox_clk);
udelay(10);
bus_low(btv,btv->mbox_clk);
udelay(10);
}
bus_low(btv,btv->mbox_we);
return 0;
}
void tea5757_set_freq(struct bttv *btv, unsigned short freq)
{
dprintk("tea5757_set_freq %d\n",freq);
tea5757_write(btv, 5 * freq + 0x358);
}
static void rv605_muxsel(struct bttv *btv, unsigned int input)
{
static const u8 muxgpio[] = { 0x3, 0x1, 0x2, 0x4, 0xf, 0x7, 0xe, 0x0,
0xd, 0xb, 0xc, 0x6, 0x9, 0x5, 0x8, 0xa };
gpio_bits(0x07f, muxgpio[input]);
gpio_bits(0x200,0x200);
mdelay(1);
gpio_bits(0x200,0x000);
mdelay(1);
gpio_bits(0x480,0x480);
mdelay(1);
gpio_bits(0x480,0x080);
mdelay(1);
}
static void tibetCS16_muxsel(struct bttv *btv, unsigned int input)
{
gpio_bits(0x0f0000, input << 16);
}
static void tibetCS16_init(struct bttv *btv)
{
gpio_inout(0xffffff, 0x0f7fff);
gpio_write(0x0f7fff);
}
static void kodicom4400r_write(struct bttv *btv,
unsigned char xaddr,
unsigned char yaddr,
unsigned char data) {
unsigned int udata;
udata = (data << 7) | ((yaddr&3) << 4) | (xaddr&0xf);
gpio_bits(0x1ff, udata);
gpio_bits(0x1ff, udata | (1 << 8));
gpio_bits(0x1ff, udata);
}
static void kodicom4400r_muxsel(struct bttv *btv, unsigned int input)
{
int xaddr, yaddr;
struct bttv *mctlr;
static unsigned char map[4] = {3, 0, 2, 1};
mctlr = master[btv->c.nr];
if (mctlr == NULL) {
return;
}
yaddr = (btv->c.nr - mctlr->c.nr + 1) & 3;
yaddr = map[yaddr];
xaddr = input & 0xf;
if (mctlr->sw_status[yaddr] != xaddr)
{
kodicom4400r_write(mctlr, mctlr->sw_status[yaddr], yaddr, 0);
mctlr->sw_status[yaddr] = xaddr;
kodicom4400r_write(mctlr, xaddr, yaddr, 1);
}
}
static void kodicom4400r_init(struct bttv *btv)
{
int ix;
gpio_inout(0x0003ff, 0x0003ff);
gpio_write(1 << 9);
gpio_write(0);
for (ix = 0; ix < 4; ix++) {
btv->sw_status[ix] = ix;
kodicom4400r_write(btv, ix, ix, 1);
}
if ((btv->c.nr<1) || (btv->c.nr>BTTV_MAX-3))
return;
master[btv->c.nr-1] = btv;
master[btv->c.nr] = btv;
master[btv->c.nr+1] = btv;
master[btv->c.nr+2] = btv;
}
static void xguard_muxsel(struct bttv *btv, unsigned int input)
{
static const int masks[] = {
ENB0, ENB0|IN00, ENB0|IN10, ENB0|IN00|IN10,
ENA0, ENA0|IN00, ENA0|IN10, ENA0|IN00|IN10,
ENB1, ENB1|IN01, ENB1|IN11, ENB1|IN01|IN11,
ENA1, ENA1|IN01, ENA1|IN11, ENA1|IN01|IN11,
};
gpio_write(masks[input%16]);
}
static void picolo_tetra_init(struct bttv *btv)
{
btwrite (0x08<<16,BT848_GPIO_DATA);
btwrite (0x04<<16,BT848_GPIO_DATA);
}
static void picolo_tetra_muxsel (struct bttv* btv, unsigned int input)
{
dprintk("%d : picolo_tetra_muxsel => input = %d\n", btv->c.nr, input);
btwrite (input<<20,BT848_GPIO_DATA);
}
static void ivc120_muxsel(struct bttv *btv, unsigned int input)
{
int key = input % 4;
int matrix = input / 4;
dprintk("%d: ivc120_muxsel: Input - %02d | TDA - %02d | In - %02d\n",
btv->c.nr, input, matrix, key);
bttv_I2CWrite(btv, I2C_TDA8540_ALT3, 0x00,
((matrix == 3) ? (key | key << 2) : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT4, 0x00,
((matrix == 0) ? (key | key << 2) : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT5, 0x00,
((matrix == 1) ? (key | key << 2) : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT6, 0x00,
((matrix == 2) ? (key | key << 2) : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT3, 0x02,
((matrix == 3) ? 0x03 : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT4, 0x02,
((matrix == 0) ? 0x03 : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT5, 0x02,
((matrix == 1) ? 0x03 : 0x00), 1);
bttv_I2CWrite(btv, I2C_TDA8540_ALT6, 0x02,
((matrix == 2) ? 0x03 : 0x00), 1);
}
static void PXC200_muxsel(struct bttv *btv, unsigned int input)
{
int rc;
long mux;
int bitmask;
unsigned char buf[2];
buf[0]=0;
buf[1]=0;
rc=bttv_I2CWrite(btv,(PX_I2C_PIC<<1),buf[0],buf[1],1);
if (rc) {
pr_debug("%d: PXC200_muxsel: pic cfg write failed:%d\n",
btv->c.nr, rc);
return;
}
rc=bttv_I2CRead(btv,(PX_I2C_PIC<<1),NULL);
if (!(rc & PX_CFG_PXC200F)) {
pr_debug("%d: PXC200_muxsel: not PXC200F rc:%d\n",
btv->c.nr, rc);
return;
}
mux = input;
bitmask=0x302;
if (btv->cardid == PX_PXC200A_CARDID) {
bitmask ^= 0x180;
bitmask |= 7<<4;
}
btwrite(bitmask, BT848_GPIO_OUT_EN);
bitmask = btread(BT848_GPIO_DATA);
if (btv->cardid == PX_PXC200A_CARDID)
bitmask = (bitmask & ~0x280) | ((mux & 2) << 8) | ((mux & 1) << 7);
else
bitmask = (bitmask & ~0x300) | ((mux & 3) << 8);
btwrite(bitmask,BT848_GPIO_DATA);
if (btv->cardid == PX_PXC200A_CARDID)
btaor(2<<5, ~BT848_IFORM_MUXSEL, BT848_IFORM);
else
btand(~BT848_IFORM_MUXSEL,BT848_IFORM);
pr_debug("%d: setting input channel to:%d\n", btv->c.nr, (int)mux);
}
static void phytec_muxsel(struct bttv *btv, unsigned int input)
{
unsigned int mux = input % 4;
if (input == btv->svhs)
mux = 0;
gpio_bits(0x3, mux);
}
static void gv800s_write(struct bttv *btv,
unsigned char xaddr,
unsigned char yaddr,
unsigned char data) {
const u32 ADDRESS = ((xaddr&0xf) | (yaddr&3)<<4);
const u32 CSELECT = 1<<16;
const u32 STROBE = 1<<17;
const u32 DATA = data<<18;
gpio_bits(0x1007f, ADDRESS | CSELECT);
gpio_bits(0x20000, STROBE);
gpio_bits(0x40000, DATA);
gpio_bits(0x20000, ~STROBE);
}
static void gv800s_muxsel(struct bttv *btv, unsigned int input)
{
struct bttv *mctlr;
int xaddr, yaddr;
static unsigned int map[4][4] = { { 0x0, 0x4, 0xa, 0x6 },
{ 0x1, 0x5, 0xb, 0x7 },
{ 0x2, 0x8, 0xc, 0xe },
{ 0x3, 0x9, 0xd, 0xf } };
input = input%4;
mctlr = master[btv->c.nr];
if (mctlr == NULL) {
return;
}
yaddr = (btv->c.nr - mctlr->c.nr) & 3;
xaddr = map[yaddr][input] & 0xf;
if (mctlr->sw_status[yaddr] != xaddr) {
gv800s_write(mctlr, mctlr->sw_status[yaddr], yaddr, 0);
mctlr->sw_status[yaddr] = xaddr;
gv800s_write(mctlr, xaddr, yaddr, 1);
}
}
static void gv800s_init(struct bttv *btv)
{
int ix;
gpio_inout(0xf107f, 0xf107f);
gpio_write(1<<19);
gpio_write(0);
for (ix = 0; ix < 4; ix++) {
btv->sw_status[ix] = ix;
gv800s_write(btv, ix, ix, 1);
}
bttv_I2CWrite(btv, 0x18, 0x5, 0x90, 1);
if (btv->c.nr > BTTV_MAX-4)
return;
master[btv->c.nr] = btv;
master[btv->c.nr+1] = btv;
master[btv->c.nr+2] = btv;
master[btv->c.nr+3] = btv;
}
void __init bttv_check_chipset(void)
{
int pcipci_fail = 0;
struct pci_dev *dev = NULL;
if (pci_pci_problems & (PCIPCI_FAIL|PCIAGP_FAIL))
pcipci_fail = 1;
if (pci_pci_problems & (PCIPCI_TRITON|PCIPCI_NATOMA|PCIPCI_VIAETBF))
triton1 = 1;
if (pci_pci_problems & PCIPCI_VSFX)
vsfx = 1;
#ifdef PCIPCI_ALIMAGIK
if (pci_pci_problems & PCIPCI_ALIMAGIK)
latency = 0x0A;
#endif
if (triton1)
pr_info("Host bridge needs ETBF enabled\n");
if (vsfx)
pr_info("Host bridge needs VSFX enabled\n");
if (pcipci_fail) {
pr_info("bttv and your chipset may not work together\n");
if (!no_overlay) {
pr_info("overlay will be disabled\n");
no_overlay = 1;
} else {
pr_info("overlay forced. Use this option at your own risk.\n");
}
}
if (UNSET != latency)
pr_info("pci latency fixup [%d]\n", latency);
while ((dev = pci_get_device(PCI_VENDOR_ID_INTEL,
PCI_DEVICE_ID_INTEL_82441, dev))) {
unsigned char b;
pci_read_config_byte(dev, 0x53, &b);
if (bttv_debug)
pr_info("Host bridge: 82441FX Natoma, bufcon=0x%02x\n",
b);
}
}
int bttv_handle_chipset(struct bttv *btv)
{
unsigned char command;
if (!triton1 && !vsfx && UNSET == latency)
return 0;
if (bttv_verbose) {
if (triton1)
pr_info("%d: enabling ETBF (430FX/VP3 compatibility)\n",
btv->c.nr);
if (vsfx && btv->id >= 878)
pr_info("%d: enabling VSFX\n", btv->c.nr);
if (UNSET != latency)
pr_info("%d: setting pci timer to %d\n",
btv->c.nr, latency);
}
if (btv->id < 878) {
if (triton1)
btv->triton1 = BT848_INT_ETBF;
} else {
pci_read_config_byte(btv->c.pci, BT878_DEVCTRL, &command);
if (triton1)
command |= BT878_EN_TBFX;
if (vsfx)
command |= BT878_EN_VSFX;
pci_write_config_byte(btv->c.pci, BT878_DEVCTRL, command);
}
if (UNSET != latency)
pci_write_config_byte(btv->c.pci, PCI_LATENCY_TIMER, latency);
return 0;
}
