static int tuner_attach_stv6110(struct ngene_channel *chan)
{
struct i2c_adapter *i2c;
struct stv090x_config *feconf = (struct stv090x_config *)
chan->dev->card_info->fe_config[chan->number];
struct stv6110x_config *tunerconf = (struct stv6110x_config *)
chan->dev->card_info->tuner_config[chan->number];
const struct stv6110x_devctl *ctl;
if (chan->number < 2)
i2c = &chan->dev->channel[0].i2c_adapter;
else
i2c = &chan->dev->channel[1].i2c_adapter;
ctl = dvb_attach(stv6110x_attach, chan->fe, tunerconf, i2c);
if (ctl == NULL) {
printk(KERN_ERR DEVICE_NAME ": No STV6110X found!\n");
return -ENODEV;
}
feconf->tuner_init = ctl->tuner_init;
feconf->tuner_sleep = ctl->tuner_sleep;
feconf->tuner_set_mode = ctl->tuner_set_mode;
feconf->tuner_set_frequency = ctl->tuner_set_frequency;
feconf->tuner_get_frequency = ctl->tuner_get_frequency;
feconf->tuner_set_bandwidth = ctl->tuner_set_bandwidth;
feconf->tuner_get_bandwidth = ctl->tuner_get_bandwidth;
feconf->tuner_set_bbgain = ctl->tuner_set_bbgain;
feconf->tuner_get_bbgain = ctl->tuner_get_bbgain;
feconf->tuner_set_refclk = ctl->tuner_set_refclk;
feconf->tuner_get_status = ctl->tuner_get_status;
return 0;
}
static int drxk_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct ngene_channel *chan = fe->sec_priv;
int status;
if (enable) {
down(&chan->dev->pll_mutex);
status = chan->gate_ctrl(fe, 1);
} else {
status = chan->gate_ctrl(fe, 0);
up(&chan->dev->pll_mutex);
}
return status;
}
static int tuner_attach_tda18271(struct ngene_channel *chan)
{
struct i2c_adapter *i2c;
struct dvb_frontend *fe;
i2c = &chan->dev->channel[0].i2c_adapter;
if (chan->fe->ops.i2c_gate_ctrl)
chan->fe->ops.i2c_gate_ctrl(chan->fe, 1);
fe = dvb_attach(tda18271c2dd_attach, chan->fe, i2c, 0x60);
if (chan->fe->ops.i2c_gate_ctrl)
chan->fe->ops.i2c_gate_ctrl(chan->fe, 0);
if (!fe) {
printk(KERN_ERR "No TDA18271 found!\n");
return -ENODEV;
}
return 0;
}
static int tuner_attach_probe(struct ngene_channel *chan)
{
if (chan->demod_type == 0)
return tuner_attach_stv6110(chan);
if (chan->demod_type == 1)
return tuner_attach_tda18271(chan);
return -EINVAL;
}
static int demod_attach_stv0900(struct ngene_channel *chan)
{
struct i2c_adapter *i2c;
struct stv090x_config *feconf = (struct stv090x_config *)
chan->dev->card_info->fe_config[chan->number];
if (chan->number < 2)
i2c = &chan->dev->channel[0].i2c_adapter;
else
i2c = &chan->dev->channel[1].i2c_adapter;
chan->fe = dvb_attach(stv090x_attach, feconf, i2c,
(chan->number & 1) == 0 ? STV090x_DEMODULATOR_0
: STV090x_DEMODULATOR_1);
if (chan->fe == NULL) {
printk(KERN_ERR DEVICE_NAME ": No STV0900 found!\n");
return -ENODEV;
}
if (feconf->tuner_i2c_lock)
chan->fe->analog_demod_priv = chan;
if (!dvb_attach(lnbh24_attach, chan->fe, i2c, 0,
0, chan->dev->card_info->lnb[chan->number])) {
printk(KERN_ERR DEVICE_NAME ": No LNBH24 found!\n");
dvb_frontend_detach(chan->fe);
chan->fe = NULL;
return -ENODEV;
}
return 0;
}
static void cineS2_tuner_i2c_lock(struct dvb_frontend *fe, int lock)
{
struct ngene_channel *chan = fe->analog_demod_priv;
if (lock)
down(&chan->dev->pll_mutex);
else
up(&chan->dev->pll_mutex);
}
static int i2c_read(struct i2c_adapter *adapter, u8 adr, u8 *val)
{
struct i2c_msg msgs[1] = {{.addr = adr, .flags = I2C_M_RD,
.buf = val, .len = 1 } };
return (i2c_transfer(adapter, msgs, 1) == 1) ? 0 : -1;
}
static int i2c_read_reg16(struct i2c_adapter *adapter, u8 adr,
u16 reg, u8 *val)
{
u8 msg[2] = {reg>>8, reg&0xff};
struct i2c_msg msgs[2] = {{.addr = adr, .flags = 0,
.buf = msg, .len = 2},
{.addr = adr, .flags = I2C_M_RD,
.buf = val, .len = 1} };
return (i2c_transfer(adapter, msgs, 2) == 2) ? 0 : -1;
}
static int port_has_stv0900(struct i2c_adapter *i2c, int port)
{
u8 val;
if (i2c_read_reg16(i2c, 0x68+port/2, 0xf100, &val) < 0)
return 0;
return 1;
}
static int port_has_drxk(struct i2c_adapter *i2c, int port)
{
u8 val;
if (i2c_read(i2c, 0x29+port, &val) < 0)
return 0;
return 1;
}
static int demod_attach_drxk(struct ngene_channel *chan,
struct i2c_adapter *i2c)
{
struct drxk_config config;
memset(&config, 0, sizeof(config));
config.microcode_name = "drxk_a3.mc";
config.qam_demod_parameter_count = 4;
config.adr = 0x29 + (chan->number ^ 2);
chan->fe = dvb_attach(drxk_attach, &config, i2c);
if (!chan->fe) {
printk(KERN_ERR "No DRXK found!\n");
return -ENODEV;
}
chan->fe->sec_priv = chan;
chan->gate_ctrl = chan->fe->ops.i2c_gate_ctrl;
chan->fe->ops.i2c_gate_ctrl = drxk_gate_ctrl;
return 0;
}
static int cineS2_probe(struct ngene_channel *chan)
{
struct i2c_adapter *i2c;
struct stv090x_config *fe_conf;
u8 buf[3];
struct i2c_msg i2c_msg = { .flags = 0, .buf = buf };
int rc;
if (chan->number < 2)
i2c = &chan->dev->channel[0].i2c_adapter;
else
i2c = &chan->dev->channel[1].i2c_adapter;
if (port_has_stv0900(i2c, chan->number)) {
chan->demod_type = 0;
fe_conf = chan->dev->card_info->fe_config[chan->number];
rc = demod_attach_stv0900(chan);
if (rc < 0 || chan->number < 2)
return rc;
i2c_msg.addr = fe_conf->address;
i2c_msg.len = 3;
buf[0] = 0xf1;
switch (chan->number) {
case 2:
buf[1] = 0x5c;
buf[2] = 0xc2;
break;
case 3:
buf[1] = 0x61;
buf[2] = 0xcc;
break;
default:
return -ENODEV;
}
rc = i2c_transfer(i2c, &i2c_msg, 1);
if (rc != 1) {
printk(KERN_ERR DEVICE_NAME ": could not setup DPNx\n");
return -EIO;
}
} else if (port_has_drxk(i2c, chan->number^2)) {
chan->demod_type = 1;
demod_attach_drxk(chan, i2c);
} else {
printk(KERN_ERR "No demod found on chan %d\n", chan->number);
return -ENODEV;
}
return 0;
}
static int demod_attach_lg330x(struct ngene_channel *chan)
{
chan->fe = dvb_attach(lgdt330x_attach, &aver_m780, &chan->i2c_adapter);
if (chan->fe == NULL) {
printk(KERN_ERR DEVICE_NAME ": No LGDT330x found!\n");
return -ENODEV;
}
dvb_attach(mt2131_attach, chan->fe, &chan->i2c_adapter,
&m780_tunerconfig, 0);
return (chan->fe) ? 0 : -ENODEV;
}
static int demod_attach_drxd(struct ngene_channel *chan)
{
struct drxd_config *feconf;
feconf = chan->dev->card_info->fe_config[chan->number];
chan->fe = dvb_attach(drxd_attach, feconf, chan,
&chan->i2c_adapter, &chan->dev->pci_dev->dev);
if (!chan->fe) {
pr_err("No DRXD found!\n");
return -ENODEV;
}
return 0;
}
static int tuner_attach_dtt7520x(struct ngene_channel *chan)
{
struct drxd_config *feconf;
feconf = chan->dev->card_info->fe_config[chan->number];
if (!dvb_attach(dvb_pll_attach, chan->fe, feconf->pll_address,
&chan->i2c_adapter,
feconf->pll_type)) {
pr_err("No pll(%d) found!\n", feconf->pll_type);
return -ENODEV;
}
return 0;
}
static int i2c_write_eeprom(struct i2c_adapter *adapter,
u8 adr, u16 reg, u8 data)
{
u8 m[3] = {(reg >> 8), (reg & 0xff), data};
struct i2c_msg msg = {.addr = adr, .flags = 0, .buf = m,
.len = sizeof(m)};
if (i2c_transfer(adapter, &msg, 1) != 1) {
pr_err(DEVICE_NAME ": Error writing EEPROM!\n");
return -EIO;
}
return 0;
}
static int i2c_read_eeprom(struct i2c_adapter *adapter,
u8 adr, u16 reg, u8 *data, int len)
{
u8 msg[2] = {(reg >> 8), (reg & 0xff)};
struct i2c_msg msgs[2] = {{.addr = adr, .flags = 0,
.buf = msg, .len = 2 },
{.addr = adr, .flags = I2C_M_RD,
.buf = data, .len = len} };
if (i2c_transfer(adapter, msgs, 2) != 2) {
pr_err(DEVICE_NAME ": Error reading EEPROM\n");
return -EIO;
}
return 0;
}
static int ReadEEProm(struct i2c_adapter *adapter,
u16 Tag, u32 MaxLen, u8 *data, u32 *pLength)
{
int status = 0;
u16 Addr = MICNG_EE_START, Length, tag = 0;
u8 EETag[3];
while (Addr + sizeof(u16) + 1 < MICNG_EE_END) {
if (i2c_read_eeprom(adapter, 0x50, Addr, EETag, sizeof(EETag)))
return -1;
tag = (EETag[0] << 8) | EETag[1];
if (tag == MICNG_EETAG_END0 || tag == MICNG_EETAG_END1)
return -1;
if (tag == Tag)
break;
Addr += sizeof(u16) + 1 + EETag[2];
}
if (Addr + sizeof(u16) + 1 + EETag[2] > MICNG_EE_END) {
pr_err(DEVICE_NAME
": Reached EOEE @ Tag = %04x Length = %3d\n",
tag, EETag[2]);
return -1;
}
Length = EETag[2];
if (Length > MaxLen)
Length = (u16) MaxLen;
if (Length > 0) {
Addr += sizeof(u16) + 1;
status = i2c_read_eeprom(adapter, 0x50, Addr, data, Length);
if (!status) {
*pLength = EETag[2];
#if 0
if (Length < EETag[2])
status = STATUS_BUFFER_OVERFLOW;
#endif
}
}
return status;
}
static int WriteEEProm(struct i2c_adapter *adapter,
u16 Tag, u32 Length, u8 *data)
{
int status = 0;
u16 Addr = MICNG_EE_START;
u8 EETag[3];
u16 tag = 0;
int retry, i;
while (Addr + sizeof(u16) + 1 < MICNG_EE_END) {
if (i2c_read_eeprom(adapter, 0x50, Addr, EETag, sizeof(EETag)))
return -1;
tag = (EETag[0] << 8) | EETag[1];
if (tag == MICNG_EETAG_END0 || tag == MICNG_EETAG_END1)
return -1;
if (tag == Tag)
break;
Addr += sizeof(u16) + 1 + EETag[2];
}
if (Addr + sizeof(u16) + 1 + EETag[2] > MICNG_EE_END) {
pr_err(DEVICE_NAME
": Reached EOEE @ Tag = %04x Length = %3d\n",
tag, EETag[2]);
return -1;
}
if (Length > EETag[2])
return -EINVAL;
Addr += sizeof(u16) + 1;
for (i = 0; i < Length; i++, Addr++) {
status = i2c_write_eeprom(adapter, 0x50, Addr, data[i]);
if (status)
break;
retry = 10;
while (retry) {
u8 Tmp;
msleep(50);
status = i2c_read_eeprom(adapter, 0x50, Addr, &Tmp, 1);
if (status)
break;
if (Tmp != data[i])
pr_err(DEVICE_NAME
"eeprom write error\n");
retry -= 1;
}
if (status) {
pr_err(DEVICE_NAME
": Timeout polling eeprom\n");
break;
}
}
return status;
}
static int eeprom_read_ushort(struct i2c_adapter *adapter, u16 tag, u16 *data)
{
int stat;
u8 buf[2];
u32 len = 0;
stat = ReadEEProm(adapter, tag, 2, buf, &len);
if (stat)
return stat;
if (len != 2)
return -EINVAL;
*data = (buf[0] << 8) | buf[1];
return 0;
}
static int eeprom_write_ushort(struct i2c_adapter *adapter, u16 tag, u16 data)
{
int stat;
u8 buf[2];
buf[0] = data >> 8;
buf[1] = data & 0xff;
stat = WriteEEProm(adapter, tag, 2, buf);
if (stat)
return stat;
return 0;
}
static s16 osc_deviation(void *priv, s16 deviation, int flag)
{
struct ngene_channel *chan = priv;
struct i2c_adapter *adap = &chan->i2c_adapter;
u16 data = 0;
if (flag) {
data = (u16) deviation;
pr_info(DEVICE_NAME ": write deviation %d\n",
deviation);
eeprom_write_ushort(adap, 0x1000 + chan->number, data);
} else {
if (eeprom_read_ushort(adap, 0x1000 + chan->number, &data))
data = 0;
pr_info(DEVICE_NAME ": read deviation %d\n",
(s16) data);
}
return (s16) data;
}
static pci_ers_result_t ngene_error_detected(struct pci_dev *dev,
enum pci_channel_state state)
{
printk(KERN_ERR DEVICE_NAME ": PCI error\n");
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (state == pci_channel_io_frozen)
return PCI_ERS_RESULT_NEED_RESET;
return PCI_ERS_RESULT_CAN_RECOVER;
}
static pci_ers_result_t ngene_slot_reset(struct pci_dev *dev)
{
printk(KERN_INFO DEVICE_NAME ": slot reset\n");
return 0;
}
static void ngene_resume(struct pci_dev *dev)
{
printk(KERN_INFO DEVICE_NAME ": resume\n");
}
static __init int module_init_ngene(void)
{
printk(KERN_INFO
"nGene PCIE bridge driver, Copyright (C) 2005-2007 Micronas\n");
return pci_register_driver(&ngene_pci_driver);
}
static __exit void module_exit_ngene(void)
{
pci_unregister_driver(&ngene_pci_driver);
}
