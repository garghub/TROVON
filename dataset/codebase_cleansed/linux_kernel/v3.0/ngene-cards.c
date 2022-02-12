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
fe_conf = chan->dev->card_info->fe_config[chan->number];
i2c_msg.addr = fe_conf->address;
i2c_msg.len = 2;
buf[0] = 0xf1;
buf[1] = 0x00;
rc = i2c_transfer(i2c, &i2c_msg, 1);
if (rc != 1)
return -ENODEV;
rc = demod_attach_stv0900(chan);
if (rc < 0 || chan->number < 2)
return rc;
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
