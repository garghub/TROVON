static void leadtek_eeprom(struct cx88_core *core, u8 *eeprom_data)
{
if (eeprom_data[4] != 0x7d ||
eeprom_data[5] != 0x10 ||
eeprom_data[7] != 0x66) {
warn_printk(core, "Leadtek eeprom invalid.\n");
return;
}
switch (eeprom_data[6]) {
case 0x13:
case 0x21:
case 0x31:
case 0x37:
case 0x3d:
core->board.tuner_type = TUNER_PHILIPS_FM1236_MK3;
break;
default:
core->board.tuner_type = TUNER_PHILIPS_FM1216ME_MK3;
break;
}
info_printk(core, "Leadtek Winfast 2000XP Expert config: "
"tuner=%d, eeprom[0]=0x%02x\n",
core->board.tuner_type, eeprom_data[0]);
}
static void hauppauge_eeprom(struct cx88_core *core, u8 *eeprom_data)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&core->i2c_client, &tv, eeprom_data);
core->board.tuner_type = tv.tuner_type;
core->tuner_formats = tv.tuner_formats;
core->board.radio.type = tv.has_radio ? CX88_RADIO : 0;
core->model = tv.model;
switch (tv.model)
{
case 14009:
case 14019:
case 14029:
case 14109:
case 14129:
case 14559:
case 14569:
case 14659:
case 14669:
case 28552:
case 34519:
case 69009:
case 69100:
case 69500:
case 69559:
case 69569:
case 90002:
case 92001:
case 92002:
case 90003:
case 90500:
case 90501:
case 92000:
case 92900:
case 94009:
case 94501:
case 96009:
case 96019:
case 96559:
case 96569:
case 96659:
case 98559:
break;
case CX88_BOARD_SAMSUNG_SMT_7020:
cx_set(MO_GP0_IO, 0x008989FF);
break;
default:
warn_printk(core, "warning: unknown hauppauge model #%d\n",
tv.model);
break;
}
info_printk(core, "hauppauge eeprom: model=%d\n", tv.model);
}
static void gdi_eeprom(struct cx88_core *core, u8 *eeprom_data)
{
const char *name = (eeprom_data[0x0d] < ARRAY_SIZE(gdi_tuner))
? gdi_tuner[eeprom_data[0x0d]].name : NULL;
info_printk(core, "GDI: tuner=%s\n", name ? name : "unknown");
if (NULL == name)
return;
core->board.tuner_type = gdi_tuner[eeprom_data[0x0d]].id;
core->board.radio.type = gdi_tuner[eeprom_data[0x0d]].fm ?
CX88_RADIO : 0;
}
static int cx88_dvico_xc2028_callback(struct cx88_core *core,
int command, int arg)
{
switch (command) {
case XC2028_TUNER_RESET:
switch (core->boardnr) {
case CX88_BOARD_DVICO_FUSIONHDTV_5_PCI_NANO:
cx_set(MO_GP0_IO, 0x00001000);
cx_clear(MO_GP0_IO, 0x00000010);
msleep(100);
cx_set(MO_GP0_IO, 0x00000010);
msleep(100);
break;
default:
cx_write(MO_GP0_IO, 0x101000);
mdelay(5);
cx_set(MO_GP0_IO, 0x101010);
}
break;
default:
return -EINVAL;
}
return 0;
}
static int cx88_xc3028_geniatech_tuner_callback(struct cx88_core *core,
int command, int mode)
{
switch (command) {
case XC2028_TUNER_RESET:
switch (INPUT(core->input).type) {
case CX88_RADIO:
break;
case CX88_VMUX_DVB:
cx_write(MO_GP1_IO, 0x030302);
mdelay(50);
break;
default:
cx_write(MO_GP1_IO, 0x030301);
mdelay(50);
}
cx_write(MO_GP1_IO, 0x101010);
mdelay(50);
cx_write(MO_GP1_IO, 0x101000);
mdelay(50);
cx_write(MO_GP1_IO, 0x101010);
mdelay(50);
return 0;
}
return -EINVAL;
}
static int cx88_xc3028_winfast1800h_callback(struct cx88_core *core,
int command, int arg)
{
switch (command) {
case XC2028_TUNER_RESET:
cx_set(MO_GP1_IO, 0x1010);
mdelay(50);
cx_clear(MO_GP1_IO, 0x10);
mdelay(75);
cx_set(MO_GP1_IO, 0x10);
mdelay(75);
return 0;
}
return -EINVAL;
}
static int cx88_xc4000_winfast2000h_plus_callback(struct cx88_core *core,
int command, int arg)
{
switch (command) {
case XC4000_TUNER_RESET:
cx_set(MO_GP1_IO, 0x1010);
mdelay(50);
cx_clear(MO_GP1_IO, 0x10);
mdelay(75);
cx_set(MO_GP1_IO, 0x10);
mdelay(75);
return 0;
}
return -EINVAL;
}
static int cx88_pv_8000gt_callback(struct cx88_core *core,
int command, int arg)
{
switch (command) {
case XC2028_TUNER_RESET:
cx_write(MO_GP2_IO, 0xcf7);
mdelay(50);
cx_write(MO_GP2_IO, 0xef5);
mdelay(50);
cx_write(MO_GP2_IO, 0xcf7);
break;
default:
return -EINVAL;
}
return 0;
}
static void dvico_fusionhdtv_hybrid_init(struct cx88_core *core)
{
struct i2c_msg msg = { .addr = 0x45, .flags = 0 };
int i, err;
static u8 init_bufs[13][5] = {
{ 0x10, 0x00, 0x20, 0x01, 0x03 },
{ 0x10, 0x10, 0x01, 0x00, 0x21 },
{ 0x10, 0x10, 0x10, 0x00, 0xCA },
{ 0x10, 0x10, 0x12, 0x00, 0x08 },
{ 0x10, 0x10, 0x13, 0x00, 0x0A },
{ 0x10, 0x10, 0x16, 0x01, 0xC0 },
{ 0x10, 0x10, 0x22, 0x01, 0x3D },
{ 0x10, 0x10, 0x73, 0x01, 0x2E },
{ 0x10, 0x10, 0x72, 0x00, 0xC5 },
{ 0x10, 0x10, 0x71, 0x01, 0x97 },
{ 0x10, 0x10, 0x70, 0x00, 0x0F },
{ 0x10, 0x10, 0xB0, 0x00, 0x01 },
{ 0x03, 0x0C },
};
for (i = 0; i < ARRAY_SIZE(init_bufs); i++) {
msg.buf = init_bufs[i];
msg.len = (i != 12 ? 5 : 2);
err = i2c_transfer(&core->i2c_adap, &msg, 1);
if (err != 1) {
warn_printk(core, "dvico_fusionhdtv_hybrid_init buf %d "
"failed (err = %d)!\n", i, err);
return;
}
}
}
static int cx88_xc2028_tuner_callback(struct cx88_core *core,
int command, int arg)
{
switch (core->boardnr) {
case CX88_BOARD_POWERCOLOR_REAL_ANGEL:
case CX88_BOARD_GENIATECH_X8000_MT:
case CX88_BOARD_KWORLD_ATSC_120:
return cx88_xc3028_geniatech_tuner_callback(core,
command, arg);
case CX88_BOARD_PROLINK_PV_8000GT:
case CX88_BOARD_PROLINK_PV_GLOBAL_XTREME:
return cx88_pv_8000gt_callback(core, command, arg);
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PRO:
case CX88_BOARD_DVICO_FUSIONHDTV_5_PCI_NANO:
return cx88_dvico_xc2028_callback(core, command, arg);
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL:
case CX88_BOARD_WINFAST_DTV1800H:
return cx88_xc3028_winfast1800h_callback(core, command, arg);
}
switch (command) {
case XC2028_TUNER_RESET:
switch (INPUT(core->input).type) {
case CX88_RADIO:
dprintk(1, "setting GPIO to radio!\n");
cx_write(MO_GP0_IO, 0x4ff);
mdelay(250);
cx_write(MO_GP2_IO, 0xff);
mdelay(250);
break;
case CX88_VMUX_DVB:
default:
dprintk(1, "setting GPIO to TV!\n");
break;
}
cx_write(MO_GP1_IO, 0x101010);
mdelay(250);
cx_write(MO_GP1_IO, 0x101000);
mdelay(250);
cx_write(MO_GP1_IO, 0x101010);
mdelay(250);
return 0;
}
return -EINVAL;
}
static int cx88_xc4000_tuner_callback(struct cx88_core *core,
int command, int arg)
{
switch (core->boardnr) {
case CX88_BOARD_WINFAST_DTV1800H_XC4000:
case CX88_BOARD_WINFAST_DTV2000H_PLUS:
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL_6F36:
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL_6F43:
return cx88_xc4000_winfast2000h_plus_callback(core,
command, arg);
}
return -EINVAL;
}
static int cx88_xc5000_tuner_callback(struct cx88_core *core,
int command, int arg)
{
switch (core->boardnr) {
case CX88_BOARD_PINNACLE_PCTV_HD_800i:
if (command == 0) {
return 0;
} else {
dprintk(1, "xc5000: unknown tuner callback command.\n");
return -EINVAL;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_7_GOLD:
if (command == 0) {
cx_clear(MO_GP0_IO, 0x00000010);
msleep(10);
cx_set(MO_GP0_IO, 0x00000010);
return 0;
} else {
dprintk(1, "xc5000: unknown tuner callback command.\n");
return -EINVAL;
}
break;
}
return 0;
}
int cx88_tuner_callback(void *priv, int component, int command, int arg)
{
struct i2c_algo_bit_data *i2c_algo = priv;
struct cx88_core *core;
if (!i2c_algo) {
printk(KERN_ERR "cx88: Error - i2c private data undefined.\n");
return -EINVAL;
}
core = i2c_algo->data;
if (!core) {
printk(KERN_ERR "cx88: Error - device struct undefined.\n");
return -EINVAL;
}
if (component != DVB_FRONTEND_COMPONENT_TUNER)
return -EINVAL;
switch (core->board.tuner_type) {
case TUNER_XC2028:
dprintk(1, "Calling XC2028/3028 callback\n");
return cx88_xc2028_tuner_callback(core, command, arg);
case TUNER_XC4000:
dprintk(1, "Calling XC4000 callback\n");
return cx88_xc4000_tuner_callback(core, command, arg);
case TUNER_XC5000:
dprintk(1, "Calling XC5000 callback\n");
return cx88_xc5000_tuner_callback(core, command, arg);
}
err_printk(core, "Error: Calling callback for tuner %d\n",
core->board.tuner_type);
return -EINVAL;
}
static void cx88_card_list(struct cx88_core *core, struct pci_dev *pci)
{
int i;
if (0 == pci->subsystem_vendor &&
0 == pci->subsystem_device) {
printk(KERN_ERR
"%s: Your board has no valid PCI Subsystem ID and thus can't\n"
"%s: be autodetected. Please pass card=<n> insmod option to\n"
"%s: workaround that. Redirect complaints to the vendor of\n"
"%s: the TV card. Best regards,\n"
"%s: -- tux\n",
core->name,core->name,core->name,core->name,core->name);
} else {
printk(KERN_ERR
"%s: Your board isn't known (yet) to the driver. You can\n"
"%s: try to pick one of the existing card configs via\n"
"%s: card=<n> insmod option. Updating to the latest\n"
"%s: version might help as well.\n",
core->name,core->name,core->name,core->name);
}
err_printk(core, "Here is a list of valid choices for the card=<n> "
"insmod option:\n");
for (i = 0; i < ARRAY_SIZE(cx88_boards); i++)
printk(KERN_ERR "%s: card=%d -> %s\n",
core->name, i, cx88_boards[i].name);
}
static void cx88_card_setup_pre_i2c(struct cx88_core *core)
{
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
cx_write(MO_GP0_IO, 0x0000ef88);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000088);
udelay(50);
cx_set(MO_GP0_IO, 0x00000088);
udelay(1000);
break;
case CX88_BOARD_PROLINK_PV_GLOBAL_XTREME:
case CX88_BOARD_PROLINK_PV_8000GT:
cx_write(MO_GP2_IO, 0xcf7);
mdelay(50);
cx_write(MO_GP2_IO, 0xef5);
mdelay(50);
cx_write(MO_GP2_IO, 0xcf7);
msleep(10);
break;
case CX88_BOARD_DVICO_FUSIONHDTV_7_GOLD:
cx_set(MO_GP0_IO, 0x00001010);
break;
case CX88_BOARD_WINFAST_DTV2000H_J:
case CX88_BOARD_HAUPPAUGE_HVR3000:
case CX88_BOARD_HAUPPAUGE_HVR4000:
cx_write(MO_GP0_IO, core->board.input[0].gpio0);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000080);
udelay(50);
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
break;
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL:
case CX88_BOARD_WINFAST_DTV1800H:
cx88_xc3028_winfast1800h_callback(core, XC2028_TUNER_RESET, 0);
break;
case CX88_BOARD_WINFAST_DTV1800H_XC4000:
case CX88_BOARD_WINFAST_DTV2000H_PLUS:
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL_6F36:
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL_6F43:
cx88_xc4000_winfast2000h_plus_callback(core,
XC4000_TUNER_RESET, 0);
break;
case CX88_BOARD_TWINHAN_VP1027_DVBS:
cx_write(MO_GP0_IO, 0x00003230);
cx_write(MO_GP0_IO, 0x00003210);
msleep(1);
cx_write(MO_GP0_IO, 0x00001230);
break;
}
}
void cx88_setup_xc3028(struct cx88_core *core, struct xc2028_ctrl *ctl)
{
memset(ctl, 0, sizeof(*ctl));
ctl->fname = XC2028_DEFAULT_FIRMWARE;
ctl->max_len = 64;
switch (core->boardnr) {
case CX88_BOARD_POWERCOLOR_REAL_ANGEL:
if (core->i2c_algo.udelay < 16)
core->i2c_algo.udelay = 16;
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PRO:
case CX88_BOARD_WINFAST_DTV1800H:
ctl->demod = XC3028_FE_ZARLINK456;
break;
case CX88_BOARD_KWORLD_ATSC_120:
case CX88_BOARD_DVICO_FUSIONHDTV_5_PCI_NANO:
ctl->demod = XC3028_FE_OREN538;
break;
case CX88_BOARD_GENIATECH_X8000_MT:
ctl->disable_power_mgmt = 1;
break;
case CX88_BOARD_WINFAST_TV2000_XP_GLOBAL:
case CX88_BOARD_PROLINK_PV_GLOBAL_XTREME:
case CX88_BOARD_PROLINK_PV_8000GT:
break;
case CX88_BOARD_PINNACLE_HYBRID_PCTV:
case CX88_BOARD_TERRATEC_CINERGY_HT_PCI_MKII:
ctl->demod = XC3028_FE_ZARLINK456;
ctl->mts = 1;
break;
default:
ctl->demod = XC3028_FE_OREN538;
ctl->mts = 1;
}
}
static void cx88_card_setup(struct cx88_core *core)
{
static u8 eeprom[256];
struct tuner_setup tun_setup;
unsigned int mode_mask = T_RADIO | T_ANALOG_TV;
memset(&tun_setup, 0, sizeof(tun_setup));
if (0 == core->i2c_rc) {
core->i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&core->i2c_client, eeprom, sizeof(eeprom));
}
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE:
case CX88_BOARD_HAUPPAUGE_ROSLYN:
if (0 == core->i2c_rc)
hauppauge_eeprom(core, eeprom+8);
break;
case CX88_BOARD_GDI:
if (0 == core->i2c_rc)
gdi_eeprom(core, eeprom);
break;
case CX88_BOARD_LEADTEK_PVR2000:
case CX88_BOARD_WINFAST_DV2000:
case CX88_BOARD_WINFAST2000XP_EXPERT:
if (0 == core->i2c_rc)
leadtek_eeprom(core, eeprom);
break;
case CX88_BOARD_HAUPPAUGE_NOVASPLUS_S1:
case CX88_BOARD_HAUPPAUGE_NOVASE2_S1:
case CX88_BOARD_HAUPPAUGE_DVB_T1:
case CX88_BOARD_HAUPPAUGE_HVR1100:
case CX88_BOARD_HAUPPAUGE_HVR1100LP:
case CX88_BOARD_HAUPPAUGE_HVR3000:
case CX88_BOARD_HAUPPAUGE_HVR1300:
case CX88_BOARD_HAUPPAUGE_HVR4000:
case CX88_BOARD_HAUPPAUGE_HVR4000LITE:
case CX88_BOARD_HAUPPAUGE_IRONLY:
if (0 == core->i2c_rc)
hauppauge_eeprom(core, eeprom);
break;
case CX88_BOARD_KWORLD_DVBS_100:
cx_write(MO_GP0_IO, 0x000007f8);
cx_write(MO_GP1_IO, 0x00000001);
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PRO:
cx_write(MO_GP0_IO, 0x00111100);
msleep(1);
cx_write(MO_GP0_IO, 0x00111111);
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL:
cx_set(MO_GP0_IO, 0x00004040);
cx_clear(MO_GP0_IO, 0x00000040);
msleep(1000);
cx_set(MO_GP0_IO, 0x00004040);
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T1:
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PLUS:
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_HYBRID:
cx_set(MO_GP0_IO, 0x00000101);
cx_clear(MO_GP0_IO, 0x00000001);
msleep(1);
cx_set(MO_GP0_IO, 0x00000101);
if (0 == core->i2c_rc &&
core->boardnr == CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_HYBRID)
dvico_fusionhdtv_hybrid_init(core);
break;
case CX88_BOARD_KWORLD_DVB_T:
case CX88_BOARD_DNTV_LIVE_DVB_T:
cx_set(MO_GP0_IO, 0x00000707);
cx_set(MO_GP2_IO, 0x00000101);
cx_clear(MO_GP2_IO, 0x00000001);
msleep(1);
cx_clear(MO_GP0_IO, 0x00000007);
cx_set(MO_GP2_IO, 0x00000101);
break;
case CX88_BOARD_DNTV_LIVE_DVB_T_PRO:
cx_write(MO_GP0_IO, 0x00080808);
break;
case CX88_BOARD_ATI_HDTVWONDER:
if (0 == core->i2c_rc) {
int i;
static const u8 buffer [][2] = {
{0x10,0x12},
{0x13,0x04},
{0x16,0x00},
{0x14,0x04},
{0x17,0x00}
};
core->i2c_client.addr = 0x0a;
for (i = 0; i < ARRAY_SIZE(buffer); i++)
if (2 != i2c_master_send(&core->i2c_client,
buffer[i],2))
warn_printk(core, "Unable to enable "
"tuner(%i).\n", i);
}
break;
case CX88_BOARD_MSI_TVANYWHERE_MASTER:
{
struct v4l2_priv_tun_config tea5767_cfg;
struct tea5767_ctrl ctl;
memset(&ctl, 0, sizeof(ctl));
ctl.high_cut = 1;
ctl.st_noise = 1;
ctl.deemph_75 = 1;
ctl.xtal_freq = TEA5767_HIGH_LO_13MHz;
tea5767_cfg.tuner = TUNER_TEA5767;
tea5767_cfg.priv = &ctl;
call_all(core, tuner, s_config, &tea5767_cfg);
break;
}
case CX88_BOARD_TEVII_S420:
case CX88_BOARD_TEVII_S460:
case CX88_BOARD_TEVII_S464:
case CX88_BOARD_OMICOM_SS4_PCI:
case CX88_BOARD_TBS_8910:
case CX88_BOARD_TBS_8920:
case CX88_BOARD_PROF_6200:
case CX88_BOARD_PROF_7300:
case CX88_BOARD_PROF_7301:
case CX88_BOARD_SATTRADE_ST4200:
cx_write(MO_GP0_IO, 0x8000);
msleep(100);
cx_write(MO_SRST_IO, 0);
msleep(10);
cx_write(MO_GP0_IO, 0x8080);
msleep(100);
cx_write(MO_SRST_IO, 1);
msleep(100);
break;
}
if ((core->board.radio_type != UNSET)) {
tun_setup.mode_mask = T_RADIO;
tun_setup.type = core->board.radio_type;
tun_setup.addr = core->board.radio_addr;
tun_setup.tuner_callback = cx88_tuner_callback;
call_all(core, tuner, s_type_addr, &tun_setup);
mode_mask &= ~T_RADIO;
}
if (core->board.tuner_type != TUNER_ABSENT) {
tun_setup.mode_mask = mode_mask;
tun_setup.type = core->board.tuner_type;
tun_setup.addr = core->board.tuner_addr;
tun_setup.tuner_callback = cx88_tuner_callback;
call_all(core, tuner, s_type_addr, &tun_setup);
}
if (core->board.tda9887_conf) {
struct v4l2_priv_tun_config tda9887_cfg;
tda9887_cfg.tuner = TUNER_TDA9887;
tda9887_cfg.priv = &core->board.tda9887_conf;
call_all(core, tuner, s_config, &tda9887_cfg);
}
if (core->board.tuner_type == TUNER_XC2028) {
struct v4l2_priv_tun_config xc2028_cfg;
struct xc2028_ctrl ctl;
cx88_setup_xc3028(core, &ctl);
memset(&xc2028_cfg, 0, sizeof(xc2028_cfg));
xc2028_cfg.tuner = TUNER_XC2028;
xc2028_cfg.priv = &ctl;
dprintk(1, "Asking xc2028/3028 to load firmware %s\n",
ctl.fname);
call_all(core, tuner, s_config, &xc2028_cfg);
}
call_all(core, core, s_power, 0);
}
static int cx88_pci_quirks(const char *name, struct pci_dev *pci)
{
unsigned int lat = UNSET;
u8 ctrl = 0;
u8 value;
if (pci_pci_problems & PCIPCI_TRITON) {
printk(KERN_INFO "%s: quirk: PCIPCI_TRITON -- set TBFX\n",
name);
ctrl |= CX88X_EN_TBFX;
}
if (pci_pci_problems & PCIPCI_NATOMA) {
printk(KERN_INFO "%s: quirk: PCIPCI_NATOMA -- set TBFX\n",
name);
ctrl |= CX88X_EN_TBFX;
}
if (pci_pci_problems & PCIPCI_VIAETBF) {
printk(KERN_INFO "%s: quirk: PCIPCI_VIAETBF -- set TBFX\n",
name);
ctrl |= CX88X_EN_TBFX;
}
if (pci_pci_problems & PCIPCI_VSFX) {
printk(KERN_INFO "%s: quirk: PCIPCI_VSFX -- set VSFX\n",
name);
ctrl |= CX88X_EN_VSFX;
}
#ifdef PCIPCI_ALIMAGIK
if (pci_pci_problems & PCIPCI_ALIMAGIK) {
printk(KERN_INFO "%s: quirk: PCIPCI_ALIMAGIK -- latency fixup\n",
name);
lat = 0x0A;
}
#endif
if (UNSET != latency)
lat = latency;
if (ctrl) {
pci_read_config_byte(pci, CX88X_DEVCTRL, &value);
value |= ctrl;
pci_write_config_byte(pci, CX88X_DEVCTRL, value);
}
if (UNSET != lat) {
printk(KERN_INFO "%s: setting pci latency timer to %d\n",
name, latency);
pci_write_config_byte(pci, PCI_LATENCY_TIMER, latency);
}
return 0;
}
int cx88_get_resources(const struct cx88_core *core, struct pci_dev *pci)
{
if (request_mem_region(pci_resource_start(pci,0),
pci_resource_len(pci,0),
core->name))
return 0;
printk(KERN_ERR
"%s/%d: Can't get MMIO memory @ 0x%llx, subsystem: %04x:%04x\n",
core->name, PCI_FUNC(pci->devfn),
(unsigned long long)pci_resource_start(pci, 0),
pci->subsystem_vendor, pci->subsystem_device);
return -EBUSY;
}
struct cx88_core *cx88_core_create(struct pci_dev *pci, int nr)
{
struct cx88_core *core;
int i;
core = kzalloc(sizeof(*core), GFP_KERNEL);
if (core == NULL)
return NULL;
atomic_inc(&core->refcount);
core->pci_bus = pci->bus->number;
core->pci_slot = PCI_SLOT(pci->devfn);
core->pci_irqmask = PCI_INT_RISC_RD_BERRINT | PCI_INT_RISC_WR_BERRINT |
PCI_INT_BRDG_BERRINT | PCI_INT_SRC_DMA_BERRINT |
PCI_INT_DST_DMA_BERRINT | PCI_INT_IPB_DMA_BERRINT;
mutex_init(&core->lock);
core->nr = nr;
sprintf(core->name, "cx88[%d]", core->nr);
strcpy(core->v4l2_dev.name, core->name);
if (v4l2_device_register(NULL, &core->v4l2_dev)) {
kfree(core);
return NULL;
}
if (v4l2_ctrl_handler_init(&core->video_hdl, 13)) {
v4l2_device_unregister(&core->v4l2_dev);
kfree(core);
return NULL;
}
if (v4l2_ctrl_handler_init(&core->audio_hdl, 13)) {
v4l2_ctrl_handler_free(&core->video_hdl);
v4l2_device_unregister(&core->v4l2_dev);
kfree(core);
return NULL;
}
if (0 != cx88_get_resources(core, pci)) {
v4l2_ctrl_handler_free(&core->video_hdl);
v4l2_ctrl_handler_free(&core->audio_hdl);
v4l2_device_unregister(&core->v4l2_dev);
kfree(core);
return NULL;
}
cx88_pci_quirks(core->name, pci);
core->lmmio = ioremap(pci_resource_start(pci, 0),
pci_resource_len(pci, 0));
core->bmmio = (u8 __iomem *)core->lmmio;
if (core->lmmio == NULL) {
release_mem_region(pci_resource_start(pci, 0),
pci_resource_len(pci, 0));
v4l2_ctrl_handler_free(&core->video_hdl);
v4l2_ctrl_handler_free(&core->audio_hdl);
v4l2_device_unregister(&core->v4l2_dev);
kfree(core);
return NULL;
}
core->boardnr = UNSET;
if (card[core->nr] < ARRAY_SIZE(cx88_boards))
core->boardnr = card[core->nr];
for (i = 0; UNSET == core->boardnr && i < ARRAY_SIZE(cx88_subids); i++)
if (pci->subsystem_vendor == cx88_subids[i].subvendor &&
pci->subsystem_device == cx88_subids[i].subdevice)
core->boardnr = cx88_subids[i].card;
if (UNSET == core->boardnr) {
core->boardnr = CX88_BOARD_UNKNOWN;
cx88_card_list(core, pci);
}
core->board = cx88_boards[core->boardnr];
if (!core->board.num_frontends && (core->board.mpeg & CX88_MPEG_DVB))
core->board.num_frontends = 1;
info_printk(core, "subsystem: %04x:%04x, board: %s [card=%d,%s], frontend(s): %d\n",
pci->subsystem_vendor, pci->subsystem_device, core->board.name,
core->boardnr, card[core->nr] == core->boardnr ?
"insmod option" : "autodetected",
core->board.num_frontends);
if (tuner[core->nr] != UNSET)
core->board.tuner_type = tuner[core->nr];
if (radio[core->nr] != UNSET)
core->board.radio_type = radio[core->nr];
dprintk(1, "TV tuner type %d, Radio tuner type %d\n",
core->board.tuner_type, core->board.radio_type);
cx88_reset(core);
cx88_card_setup_pre_i2c(core);
cx88_i2c_init(core, pci);
if (TUNER_ABSENT != core->board.tuner_type) {
static const unsigned short tv_addrs[] = {
0x42, 0x43, 0x4a, 0x4b,
0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
0x68, 0x69, 0x6a, 0x6c, 0x6d, 0x6e,
I2C_CLIENT_END
};
int has_demod = (core->board.tda9887_conf & TDA9887_PRESENT);
v4l2_i2c_new_subdev(&core->v4l2_dev, &core->i2c_adap,
"tuner", 0, v4l2_i2c_tuner_addrs(ADDRS_RADIO));
if (has_demod)
v4l2_i2c_new_subdev(&core->v4l2_dev,
&core->i2c_adap, "tuner",
0, v4l2_i2c_tuner_addrs(ADDRS_DEMOD));
if (core->board.tuner_addr == ADDR_UNSET) {
v4l2_i2c_new_subdev(&core->v4l2_dev,
&core->i2c_adap, "tuner",
0, has_demod ? tv_addrs + 4 : tv_addrs);
} else {
v4l2_i2c_new_subdev(&core->v4l2_dev, &core->i2c_adap,
"tuner", core->board.tuner_addr, NULL);
}
}
cx88_card_setup(core);
if (!disable_ir) {
cx88_i2c_init_ir(core);
cx88_ir_init(core, pci);
}
return core;
}
