void cx23885_card_list(struct cx23885_dev *dev)
{
int i;
if (0 == dev->pci->subsystem_vendor &&
0 == dev->pci->subsystem_device) {
pr_info("%s: Board has no valid PCIe Subsystem ID and can't\n"
"%s: be autodetected. Pass card=<n> insmod option\n"
"%s: to workaround that. Redirect complaints to the\n"
"%s: vendor of the TV card. Best regards,\n"
"%s: -- tux\n",
dev->name, dev->name, dev->name, dev->name, dev->name);
} else {
pr_info("%s: Your board isn't known (yet) to the driver.\n"
"%s: Try to pick one of the existing card configs via\n"
"%s: card=<n> insmod option. Updating to the latest\n"
"%s: version might help as well.\n",
dev->name, dev->name, dev->name, dev->name);
}
pr_info("%s: Here is a list of valid choices for the card=<n> insmod option:\n",
dev->name);
for (i = 0; i < cx23885_bcount; i++)
pr_info("%s: card=%d -> %s\n",
dev->name, i, cx23885_boards[i].name);
}
static void viewcast_eeprom(struct cx23885_dev *dev, u8 *eeprom_data)
{
u32 sn;
if (*(eeprom_data + 0x00) != 0x59) {
pr_info("%s() eeprom records are undefined, no serial number\n",
__func__);
return;
}
sn = (*(eeprom_data + 0x06) << 24) |
(*(eeprom_data + 0x05) << 16) |
(*(eeprom_data + 0x04) << 8) |
(*(eeprom_data + 0x03));
pr_info("%s: card '%s' sn# MM%d\n",
dev->name,
cx23885_boards[dev->board].name,
sn);
}
static void hauppauge_eeprom(struct cx23885_dev *dev, u8 *eeprom_data)
{
struct tveeprom tv;
tveeprom_hauppauge_analog(&tv, eeprom_data);
switch (tv.model) {
case 22001:
case 22009:
case 22011:
case 22019:
case 22021:
case 22029:
case 22101:
case 22109:
case 22111:
case 22119:
case 22121:
case 22129:
case 71009:
case 71100:
case 71359:
case 71439:
case 71449:
case 71939:
case 71949:
case 71959:
case 71979:
case 71999:
case 76601:
case 77001:
case 77011:
case 77041:
case 77051:
case 78011:
case 78501:
case 78521:
case 78531:
case 78631:
case 79001:
case 79101:
case 79501:
case 79561:
case 79571:
case 79671:
case 80019:
case 81509:
case 81519:
break;
case 85021:
break;
case 85721:
case 150329:
break;
case 166100:
break;
case 166101:
break;
case 165100:
break;
case 165101:
break;
default:
pr_warn("%s: warning: unknown hauppauge model #%d\n",
dev->name, tv.model);
break;
}
pr_info("%s: hauppauge eeprom: model=%d\n",
dev->name, tv.model);
}
static void tbs_card_init(struct cx23885_dev *dev)
{
int i;
const u8 buf[] = {
0xe0, 0x06, 0x66, 0x33, 0x65,
0x01, 0x17, 0x06, 0xde};
switch (dev->board) {
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
cx_set(GP0_IO, 0x00070007);
usleep_range(1000, 10000);
cx_clear(GP0_IO, 2);
usleep_range(1000, 10000);
for (i = 0; i < 9 * 8; i++) {
cx_clear(GP0_IO, 7);
usleep_range(1000, 10000);
cx_set(GP0_IO,
((buf[i >> 3] >> (7 - (i & 7))) & 1) | 4);
usleep_range(1000, 10000);
}
cx_set(GP0_IO, 7);
break;
}
}
int cx23885_tuner_callback(void *priv, int component, int command, int arg)
{
struct cx23885_tsport *port = priv;
struct cx23885_dev *dev = port->dev;
u32 bitmask = 0;
if ((command == XC2028_RESET_CLK) || (command == XC2028_I2C_FLUSH))
return 0;
if (command != 0) {
pr_err("%s(): Unknown command 0x%x.\n",
__func__, command);
return -EINVAL;
}
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1400:
case CX23885_BOARD_HAUPPAUGE_HVR1500:
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H:
case CX23885_BOARD_LEADTEK_WINFAST_PXPVR2200:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H_XC4000:
case CX23885_BOARD_COMPRO_VIDEOMATE_E650F:
case CX23885_BOARD_COMPRO_VIDEOMATE_E800:
case CX23885_BOARD_LEADTEK_WINFAST_PXTV1200:
bitmask = 0x04;
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_7_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP2:
if (port->nr == 1)
bitmask = 0x01;
else if (port->nr == 2)
bitmask = 0x04;
break;
case CX23885_BOARD_GOTVIEW_X5_3D_HYBRID:
bitmask = 0x02;
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
altera_ci_tuner_reset(dev, port->nr);
break;
case CX23885_BOARD_AVERMEDIA_HC81R:
bitmask = 1 << 2;
break;
}
if (bitmask) {
cx_clear(GP0_IO, bitmask);
mdelay(200);
cx_set(GP0_IO, bitmask);
}
return 0;
}
void cx23885_gpio_setup(struct cx23885_dev *dev)
{
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1250:
cx_set(GP0_IO, 0x00010001);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500:
cx_set(GP0_IO, 0x00050000);
cx_clear(GP0_IO, 0x00000005);
msleep(5);
cx_set(GP0_IO, 0x00050005);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
cx_set(GP0_IO, 0x00050005);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1800:
mc417_gpio_enable(dev, GPIO_15 | GPIO_14, 1);
mc417_gpio_clear(dev, GPIO_15 | GPIO_14);
mdelay(100);
mc417_gpio_set(dev, GPIO_15 | GPIO_14);
mdelay(100);
cx23885_gpio_enable(dev, GPIO_2, 1);
cx23885_gpio_set(dev, GPIO_2);
mdelay(20);
cx23885_gpio_clear(dev, GPIO_2);
mdelay(20);
cx23885_gpio_set(dev, GPIO_2);
mdelay(20);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1200:
cx_set(GP0_IO, 0x00050000);
mdelay(20);
cx_clear(GP0_IO, 0x00000005);
mdelay(20);
cx_set(GP0_IO, 0x00050005);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1700:
cx_set(GP0_IO, 0x00050000);
mdelay(20);
cx_clear(GP0_IO, 0x00000005);
mdelay(20);
cx_set(GP0_IO, 0x00050005);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1400:
cx_set(GP0_IO, 0x00050000);
mdelay(20);
cx_clear(GP0_IO, 0x00000005);
mdelay(20);
cx_set(GP0_IO, 0x00050005);
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_7_DUAL_EXP:
cx_set(GP0_IO, 0x000f0000);
mdelay(20);
cx_clear(GP0_IO, 0x0000000f);
mdelay(20);
cx_set(GP0_IO, 0x000f000f);
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP2:
cx_set(GP0_IO, 0x000f0000);
mdelay(20);
cx_clear(GP0_IO, 0x0000000f);
mdelay(20);
cx_set(GP0_IO, 0x000f000f);
break;
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H:
case CX23885_BOARD_LEADTEK_WINFAST_PXPVR2200:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H_XC4000:
case CX23885_BOARD_COMPRO_VIDEOMATE_E650F:
case CX23885_BOARD_COMPRO_VIDEOMATE_E800:
case CX23885_BOARD_LEADTEK_WINFAST_PXTV1200:
cx_set(GP0_IO, 0x00040000);
mdelay(20);
cx_clear(GP0_IO, 0x00000004);
mdelay(20);
cx_set(GP0_IO, 0x00040004);
break;
case CX23885_BOARD_TBS_6920:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_PROF_8000:
cx_write(MC417_CTL, 0x00000036);
cx_write(MC417_OEN, 0x00001000);
cx_set(MC417_RWD, 0x00000002);
mdelay(200);
cx_clear(MC417_RWD, 0x00000800);
mdelay(200);
cx_set(MC417_RWD, 0x00000800);
mdelay(200);
break;
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
cx_set(GP0_IO, 0x00040000);
cx_clear(GP0_IO, 0x00030004);
mdelay(100);
cx_set(GP0_IO, 0x00040004);
cx_write(MC417_CTL, 0x00000037);
cx_write(MC417_OEN, 0x00001000);
cx_write(MC417_RWD, 0x0000c300);
cx_write(GPIO_ISM, 0x00000000);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1210:
cx23885_gpio_enable(dev, GPIO_9 | GPIO_6 | GPIO_5, 1);
cx23885_gpio_set(dev, GPIO_9 | GPIO_6 | GPIO_5);
cx23885_gpio_clear(dev, GPIO_9);
mdelay(20);
cx23885_gpio_set(dev, GPIO_9);
break;
case CX23885_BOARD_MYGICA_X8506:
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
case CX23885_BOARD_MYGICA_X8507:
cx23885_gpio_enable(dev, GPIO_0 | GPIO_1 | GPIO_2, 1);
cx23885_gpio_clear(dev, GPIO_1 | GPIO_2);
mdelay(100);
cx23885_gpio_set(dev, GPIO_0 | GPIO_1 | GPIO_2);
mdelay(100);
break;
case CX23885_BOARD_MYGICA_X8558PRO:
cx23885_gpio_enable(dev, GPIO_0 | GPIO_1, 1);
cx23885_gpio_clear(dev, GPIO_0 | GPIO_1);
mdelay(100);
cx23885_gpio_set(dev, GPIO_0 | GPIO_1);
mdelay(100);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
mc417_gpio_enable(dev, GPIO_14 | GPIO_13, 1);
mc417_gpio_clear(dev, GPIO_14 | GPIO_13);
mdelay(100);
mc417_gpio_set(dev, GPIO_14);
mdelay(100);
break;
case CX23885_BOARD_GOTVIEW_X5_3D_HYBRID:
cx_set(GP0_IO, 0x00010001);
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
cx_set(GP0_IO, 0x00060000);
cx_clear(GP0_IO, 0x00010006);
mdelay(100);
cx_set(GP0_IO, 0x00000004);
cx_write(MC417_CTL, 0x00000037);
cx_write(MC417_OEN, 0x00005000);
cx_write(MC417_RWD, 0x00000d00);
cx_write(GPIO_ISM, 0x00000000);
break;
case CX23885_BOARD_HAUPPAUGE_HVR4400:
case CX23885_BOARD_HAUPPAUGE_STARBURST:
cx23885_gpio_enable(dev, GPIO_8 | GPIO_9, 1);
cx23885_gpio_clear(dev, GPIO_8 | GPIO_9);
mdelay(100);
cx23885_gpio_set(dev, GPIO_8 | GPIO_9);
mdelay(100);
break;
case CX23885_BOARD_AVERMEDIA_HC81R:
cx_clear(MC417_CTL, 1);
cx_set(GP0_IO, 0x00070000);
mdelay(10);
cx_set(GP0_IO, 0x00010001);
mdelay(10);
cx_clear(GP0_IO, 0x00010001);
mdelay(10);
cx_set(GP0_IO, 0x00010001);
mdelay(10);
cx_clear(GP0_IO, 0x00030003);
mdelay(10);
cx_set(GP0_IO, 0x00020002);
mdelay(10);
cx_set(GP0_IO, 0x00010001);
mdelay(10);
cx_clear(GP0_IO, 0x00020002);
cx_set(GP0_IO, 0x00040004);
cx_clear(GP0_IO, 0x00040004);
cx_set(GP0_IO, 0x00040004);
mdelay(60);
break;
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
cx_write(MC417_CTL, 0x00000037);
cx23885_gpio_enable(dev, GPIO_2 | GPIO_11, 1);
cx23885_gpio_clear(dev, GPIO_2 | GPIO_11);
mdelay(100);
cx23885_gpio_set(dev, GPIO_2 | GPIO_11);
break;
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
cx_set(GP0_IO, 0x00060002);
cx_clear(GP0_IO, 0x00010004);
mdelay(100);
cx_set(GP0_IO, 0x00060004);
cx_clear(GP0_IO, 0x00010002);
cx_write(MC417_CTL, 0x00000037);
cx_write(MC417_OEN, 0x00001000);
cx_write(MC417_RWD, 0x0000c300);
cx_write(GPIO_ISM, 0x00000000);
break;
case CX23885_BOARD_DVBSKY_S950:
cx23885_gpio_enable(dev, GPIO_2, 1);
cx23885_gpio_clear(dev, GPIO_2);
msleep(100);
cx23885_gpio_set(dev, GPIO_2);
break;
case CX23885_BOARD_HAUPPAUGE_HVR5525:
case CX23885_BOARD_HAUPPAUGE_QUADHD_DVB:
case CX23885_BOARD_HAUPPAUGE_QUADHD_ATSC:
cx23885_gpio_enable(dev, GPIO_8 | GPIO_9, 1);
cx23885_gpio_clear(dev, GPIO_8 | GPIO_9);
msleep(100);
cx23885_gpio_set(dev, GPIO_8 | GPIO_9);
msleep(100);
break;
case CX23885_BOARD_VIEWCAST_260E:
case CX23885_BOARD_VIEWCAST_460E:
break;
}
}
int cx23885_ir_init(struct cx23885_dev *dev)
{
static struct v4l2_subdev_io_pin_config ir_rxtx_pin_cfg[] = {
{
.flags = V4L2_SUBDEV_IO_PIN_INPUT,
.pin = CX23885_PIN_IR_RX_GPIO19,
.function = CX23885_PAD_IR_RX,
.value = 0,
.strength = CX25840_PIN_DRIVE_MEDIUM,
}, {
.flags = V4L2_SUBDEV_IO_PIN_OUTPUT,
.pin = CX23885_PIN_IR_TX_GPIO20,
.function = CX23885_PAD_IR_TX,
.value = 0,
.strength = CX25840_PIN_DRIVE_MEDIUM,
}
};
const size_t ir_rxtx_pin_cfg_count = ARRAY_SIZE(ir_rxtx_pin_cfg);
static struct v4l2_subdev_io_pin_config ir_rx_pin_cfg[] = {
{
.flags = V4L2_SUBDEV_IO_PIN_INPUT,
.pin = CX23885_PIN_IR_RX_GPIO19,
.function = CX23885_PAD_IR_RX,
.value = 0,
.strength = CX25840_PIN_DRIVE_MEDIUM,
}
};
const size_t ir_rx_pin_cfg_count = ARRAY_SIZE(ir_rx_pin_cfg);
struct v4l2_subdev_ir_parameters params;
int ret = 0;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1500:
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
case CX23885_BOARD_HAUPPAUGE_HVR1800:
case CX23885_BOARD_HAUPPAUGE_HVR1200:
case CX23885_BOARD_HAUPPAUGE_HVR1400:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1210:
case CX23885_BOARD_HAUPPAUGE_QUADHD_DVB:
case CX23885_BOARD_HAUPPAUGE_QUADHD_ATSC:
break;
case CX23885_BOARD_HAUPPAUGE_HVR1270:
ret = cx23888_ir_probe(dev);
if (ret)
break;
dev->sd_ir = cx23885_find_hw(dev, CX23885_HW_888_IR);
v4l2_subdev_call(dev->sd_cx25840, core, s_io_pin_config,
ir_rx_pin_cfg_count, ir_rx_pin_cfg);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
ret = cx23888_ir_probe(dev);
if (ret)
break;
dev->sd_ir = cx23885_find_hw(dev, CX23885_HW_888_IR);
v4l2_subdev_call(dev->sd_cx25840, core, s_io_pin_config,
ir_rxtx_pin_cfg_count, ir_rxtx_pin_cfg);
v4l2_subdev_call(dev->sd_ir, ir, tx_g_parameters, &params);
params.enable = false;
params.shutdown = false;
params.invert_level = true;
v4l2_subdev_call(dev->sd_ir, ir, tx_s_parameters, &params);
params.shutdown = true;
v4l2_subdev_call(dev->sd_ir, ir, tx_s_parameters, &params);
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
if (!enable_885_ir)
break;
dev->sd_ir = cx23885_find_hw(dev, CX23885_HW_AV_CORE);
if (dev->sd_ir == NULL) {
ret = -ENODEV;
break;
}
v4l2_subdev_call(dev->sd_cx25840, core, s_io_pin_config,
ir_rx_pin_cfg_count, ir_rx_pin_cfg);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1250:
if (!enable_885_ir)
break;
dev->sd_ir = cx23885_find_hw(dev, CX23885_HW_AV_CORE);
if (dev->sd_ir == NULL) {
ret = -ENODEV;
break;
}
v4l2_subdev_call(dev->sd_cx25840, core, s_io_pin_config,
ir_rxtx_pin_cfg_count, ir_rxtx_pin_cfg);
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP2:
request_module("ir-kbd-i2c");
break;
}
return ret;
}
void cx23885_ir_fini(struct cx23885_dev *dev)
{
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
cx23885_irq_remove(dev, PCI_MSK_IR);
cx23888_ir_remove(dev);
dev->sd_ir = NULL;
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
cx23885_irq_remove(dev, PCI_MSK_AV_CORE);
dev->sd_ir = NULL;
break;
}
}
static int netup_jtag_io(void *device, int tms, int tdi, int read_tdo)
{
int data;
int tdo = 0;
struct cx23885_dev *dev = (struct cx23885_dev *)device;
data = ((cx_read(GP0_IO)) & (~0x00000002));
data |= (tms ? 0x00020002 : 0x00020000);
cx_write(GP0_IO, data);
data = ((cx_read(MC417_RWD)) & (~0x0000a000));
data |= (tdi ? 0x00008000 : 0);
cx_write(MC417_RWD, data);
if (read_tdo)
tdo = (data & 0x00004000) ? 1 : 0;
cx_write(MC417_RWD, data | 0x00002000);
udelay(1);
cx_write(MC417_RWD, data);
return tdo;
}
void cx23885_ir_pci_int_enable(struct cx23885_dev *dev)
{
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
if (dev->sd_ir)
cx23885_irq_add_enable(dev, PCI_MSK_IR);
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
if (dev->sd_ir)
cx23885_irq_add_enable(dev, PCI_MSK_AV_CORE);
break;
}
}
void cx23885_card_setup(struct cx23885_dev *dev)
{
struct cx23885_tsport *ts1 = &dev->ts1;
struct cx23885_tsport *ts2 = &dev->ts2;
static u8 eeprom[256];
if (dev->i2c_bus[0].i2c_rc == 0) {
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client,
eeprom, sizeof(eeprom));
}
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1250:
if (dev->i2c_bus[0].i2c_rc == 0) {
if (eeprom[0x80] != 0x84)
hauppauge_eeprom(dev, eeprom+0xc0);
else
hauppauge_eeprom(dev, eeprom+0x80);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500:
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
case CX23885_BOARD_HAUPPAUGE_HVR1400:
if (dev->i2c_bus[0].i2c_rc == 0)
hauppauge_eeprom(dev, eeprom+0x80);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1800:
case CX23885_BOARD_HAUPPAUGE_HVR1800lp:
case CX23885_BOARD_HAUPPAUGE_HVR1200:
case CX23885_BOARD_HAUPPAUGE_HVR1700:
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1210:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_HAUPPAUGE_HVR4400:
case CX23885_BOARD_HAUPPAUGE_STARBURST:
case CX23885_BOARD_HAUPPAUGE_IMPACTVCBE:
case CX23885_BOARD_HAUPPAUGE_HVR5525:
case CX23885_BOARD_HAUPPAUGE_QUADHD_DVB:
case CX23885_BOARD_HAUPPAUGE_QUADHD_ATSC:
if (dev->i2c_bus[0].i2c_rc == 0)
hauppauge_eeprom(dev, eeprom+0xc0);
break;
case CX23885_BOARD_VIEWCAST_260E:
case CX23885_BOARD_VIEWCAST_460E:
dev->i2c_bus[1].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[1].i2c_client,
eeprom, sizeof(eeprom));
if (dev->i2c_bus[0].i2c_rc == 0)
viewcast_eeprom(dev, eeprom);
break;
}
switch (dev->board) {
case CX23885_BOARD_AVERMEDIA_HC81R:
ts1->gen_ctrl_val = 0x4;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0x10e;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_7_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP:
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP2:
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
case CX23885_BOARD_DVICO_FUSIONHDTV_5_EXP:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1800:
ts1->gen_ctrl_val = 0x10e;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts1->vld_misc_val = 0x2000;
ts1->hw_sop_ctrl_val = (0x47 << 16 | 188 << 4 | 0xc);
cx_write(0x130184, 0xc);
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_TBS_6920:
ts1->gen_ctrl_val = 0x4;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_TEVII_S471:
case CX23885_BOARD_DVBWORLD_2005:
case CX23885_BOARD_PROF_8000:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
tbs_card_init(dev);
break;
case CX23885_BOARD_MYGICA_X8506:
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
case CX23885_BOARD_MYGICA_X8507:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_MYGICA_X8558PRO:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_HVR4400:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_STARBURST:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T982:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0x8;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_DVBSKY_S952:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xe;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_HVR5525:
ts1->gen_ctrl_val = 0x5;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_QUADHD_DVB:
case CX23885_BOARD_HAUPPAUGE_QUADHD_ATSC:
ts1->gen_ctrl_val = 0xc;
ts1->ts_clk_en_val = 0x1;
ts1->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
break;
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_HAUPPAUGE_HVR1500:
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
case CX23885_BOARD_HAUPPAUGE_HVR1800lp:
case CX23885_BOARD_HAUPPAUGE_HVR1200:
case CX23885_BOARD_HAUPPAUGE_HVR1700:
case CX23885_BOARD_HAUPPAUGE_HVR1400:
case CX23885_BOARD_HAUPPAUGE_IMPACTVCBE:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H:
case CX23885_BOARD_LEADTEK_WINFAST_PXPVR2200:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H_XC4000:
case CX23885_BOARD_COMPRO_VIDEOMATE_E650F:
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1210:
case CX23885_BOARD_COMPRO_VIDEOMATE_E800:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_GOTVIEW_X5_3D_HYBRID:
default:
ts2->gen_ctrl_val = 0xc;
ts2->ts_clk_en_val = 0x1;
ts2->src_sel_val = CX23885_SRC_SEL_PARALLEL_MPEG_VIDEO;
}
switch (dev->board) {
case CX23885_BOARD_TEVII_S470:
if (!enable_885_ir)
break;
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_HAUPPAUGE_HVR1800:
case CX23885_BOARD_HAUPPAUGE_IMPACTVCBE:
case CX23885_BOARD_HAUPPAUGE_HVR1800lp:
case CX23885_BOARD_HAUPPAUGE_HVR1700:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H:
case CX23885_BOARD_LEADTEK_WINFAST_PXPVR2200:
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H_XC4000:
case CX23885_BOARD_COMPRO_VIDEOMATE_E650F:
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
case CX23885_BOARD_COMPRO_VIDEOMATE_E800:
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_MYGICA_X8506:
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_LEADTEK_WINFAST_PXTV1200:
case CX23885_BOARD_GOTVIEW_X5_3D_HYBRID:
case CX23885_BOARD_HAUPPAUGE_HVR1500:
case CX23885_BOARD_MPX885:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_AVERMEDIA_HC81R:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
case CX23885_BOARD_VIEWCAST_260E:
case CX23885_BOARD_VIEWCAST_460E:
dev->sd_cx25840 = v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[2].i2c_adap,
"cx25840", 0x88 >> 1, NULL);
if (dev->sd_cx25840) {
dev->sd_cx25840->grp_id = CX23885_HW_AV_CORE;
v4l2_subdev_call(dev->sd_cx25840, core, load_fw);
}
break;
}
switch (dev->board) {
case CX23885_BOARD_VIEWCAST_260E:
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[0].i2c_adap,
"cs3308", 0x82 >> 1, NULL);
break;
case CX23885_BOARD_VIEWCAST_460E:
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[0].i2c_adap,
"cs3308", 0x80 >> 1, NULL);
v4l2_i2c_new_subdev(&dev->v4l2_dev,
&dev->i2c_bus[0].i2c_adap,
"cs3308", 0x82 >> 1, NULL);
break;
}
switch (dev->board) {
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
netup_initialize(dev);
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF: {
int ret;
const struct firmware *fw;
const char *filename = "dvb-netup-altera-01.fw";
char *action = "configure";
static struct netup_card_info cinfo;
struct altera_config netup_config = {
.dev = dev,
.action = action,
.jtag_io = netup_jtag_io,
};
netup_initialize(dev);
netup_get_card_info(&dev->i2c_bus[0].i2c_adap, &cinfo);
if (netup_card_rev)
cinfo.rev = netup_card_rev;
switch (cinfo.rev) {
case 0x4:
filename = "dvb-netup-altera-04.fw";
break;
default:
filename = "dvb-netup-altera-01.fw";
break;
}
pr_info("NetUP card rev=0x%x fw_filename=%s\n",
cinfo.rev, filename);
ret = request_firmware(&fw, filename, &dev->pci->dev);
if (ret != 0)
pr_err("did not find the firmware file. (%s) Please see linux/Documentation/dvb/ for more details on firmware-problems.",
filename);
else
altera_init(&netup_config, fw);
release_firmware(fw);
break;
}
}
}
