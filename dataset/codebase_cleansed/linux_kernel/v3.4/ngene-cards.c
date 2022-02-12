static int tuner_attach_stv6110(struct ngene_channel *chan)
{
struct i2c_adapter *i2c;
struct stv090x_config *feconf = (struct stv090x_config *)
chan->dev->card_info->fe_config[chan->number];
struct stv6110x_config *tunerconf = (struct stv6110x_config *)
chan->dev->card_info->tuner_config[chan->number];
struct stv6110x_devctl *ctl;
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
static pci_ers_result_t ngene_link_reset(struct pci_dev *dev)
{
printk(KERN_INFO DEVICE_NAME ": link reset\n");
return 0;
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
