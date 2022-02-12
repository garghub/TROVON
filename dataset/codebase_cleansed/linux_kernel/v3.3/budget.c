static void Set22K (struct budget *budget, int state)
{
struct saa7146_dev *dev=budget->dev;
dprintk(2, "budget: %p\n", budget);
saa7146_setgpio(dev, 3, (state ? SAA7146_GPIO_OUTHI : SAA7146_GPIO_OUTLO));
}
static void DiseqcSendBit (struct budget *budget, int data)
{
struct saa7146_dev *dev=budget->dev;
dprintk(2, "budget: %p\n", budget);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
udelay(data ? 500 : 1000);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
udelay(data ? 1000 : 500);
}
static void DiseqcSendByte (struct budget *budget, int data)
{
int i, par=1, d;
dprintk(2, "budget: %p\n", budget);
for (i=7; i>=0; i--) {
d = (data>>i)&1;
par ^= d;
DiseqcSendBit(budget, d);
}
DiseqcSendBit(budget, par);
}
static int SendDiSEqCMsg (struct budget *budget, int len, u8 *msg, unsigned long burst)
{
struct saa7146_dev *dev=budget->dev;
int i;
dprintk(2, "budget: %p\n", budget);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
mdelay(16);
for (i=0; i<len; i++)
DiseqcSendByte(budget, msg[i]);
mdelay(16);
if (burst!=-1) {
if (burst)
DiseqcSendByte(budget, 0xff);
else {
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTHI);
mdelay(12);
udelay(500);
saa7146_setgpio(dev, 3, SAA7146_GPIO_OUTLO);
}
msleep(20);
}
return 0;
}
static int SetVoltage_Activy (struct budget *budget, fe_sec_voltage_t voltage)
{
struct saa7146_dev *dev=budget->dev;
dprintk(2, "budget: %p\n", budget);
switch (voltage) {
case SEC_VOLTAGE_13:
saa7146_setgpio(dev, 1, SAA7146_GPIO_OUTHI);
saa7146_setgpio(dev, 2, SAA7146_GPIO_OUTLO);
break;
case SEC_VOLTAGE_18:
saa7146_setgpio(dev, 1, SAA7146_GPIO_OUTHI);
saa7146_setgpio(dev, 2, SAA7146_GPIO_OUTHI);
break;
case SEC_VOLTAGE_OFF:
saa7146_setgpio(dev, 1, SAA7146_GPIO_OUTLO);
break;
default:
return -EINVAL;
}
return 0;
}
static int siemens_budget_set_voltage(struct dvb_frontend* fe, fe_sec_voltage_t voltage)
{
struct budget* budget = (struct budget*) fe->dvb->priv;
return SetVoltage_Activy (budget, voltage);
}
static int budget_set_tone(struct dvb_frontend* fe, fe_sec_tone_mode_t tone)
{
struct budget* budget = (struct budget*) fe->dvb->priv;
switch (tone) {
case SEC_TONE_ON:
Set22K (budget, 1);
break;
case SEC_TONE_OFF:
Set22K (budget, 0);
break;
default:
return -EINVAL;
}
return 0;
}
static int budget_diseqc_send_master_cmd(struct dvb_frontend* fe, struct dvb_diseqc_master_cmd* cmd)
{
struct budget* budget = (struct budget*) fe->dvb->priv;
SendDiSEqCMsg (budget, cmd->msg_len, cmd->msg, 0);
return 0;
}
static int budget_diseqc_send_burst(struct dvb_frontend* fe, fe_sec_mini_cmd_t minicmd)
{
struct budget* budget = (struct budget*) fe->dvb->priv;
SendDiSEqCMsg (budget, 0, NULL, minicmd);
return 0;
}
static int alps_bsrv2_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget* budget = (struct budget*) fe->dvb->priv;
u8 pwr = 0;
u8 buf[4];
struct i2c_msg msg = { .addr = 0x61, .flags = 0, .buf = buf, .len = sizeof(buf) };
u32 div = (c->frequency + 479500) / 125;
if (c->frequency > 2000000)
pwr = 3;
else if (c->frequency > 1800000)
pwr = 2;
else if (c->frequency > 1600000)
pwr = 1;
else if (c->frequency > 1200000)
pwr = 0;
else if (c->frequency >= 1100000)
pwr = 1;
else pwr = 2;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = ((div & 0x18000) >> 10) | 0x95;
buf[3] = (pwr << 6) | 0x30;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int alps_tdbe2_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget* budget = (struct budget*) fe->dvb->priv;
u32 div;
u8 data[4];
struct i2c_msg msg = { .addr = 0x62, .flags = 0, .buf = data, .len = sizeof(data) };
div = (c->frequency + 35937500 + 31250) / 62500;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = 0x85 | ((div >> 10) & 0x60);
data[3] = (c->frequency < 174000000 ? 0x88 : c->frequency < 470000000 ? 0x84 : 0x81);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int grundig_29504_401_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget *budget = fe->dvb->priv;
u8 *tuner_addr = fe->tuner_priv;
u32 div;
u8 cfg, cpump, band_select;
u8 data[4];
struct i2c_msg msg = { .flags = 0, .buf = data, .len = sizeof(data) };
if (tuner_addr)
msg.addr = *tuner_addr;
else
msg.addr = 0x61;
div = (36125000 + c->frequency) / 166666;
cfg = 0x88;
if (c->frequency < 175000000)
cpump = 2;
else if (c->frequency < 390000000)
cpump = 1;
else if (c->frequency < 470000000)
cpump = 2;
else if (c->frequency < 750000000)
cpump = 1;
else
cpump = 3;
if (c->frequency < 175000000)
band_select = 0x0e;
else if (c->frequency < 470000000)
band_select = 0x05;
else
band_select = 0x03;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = ((div >> 10) & 0x60) | cfg;
data[3] = (cpump << 6) | band_select;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int grundig_29504_451_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget* budget = (struct budget*) fe->dvb->priv;
u32 div;
u8 data[4];
struct i2c_msg msg = { .addr = 0x61, .flags = 0, .buf = data, .len = sizeof(data) };
div = c->frequency / 125;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = 0x8e;
data[3] = 0x00;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int s5h1420_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct budget* budget = (struct budget*) fe->dvb->priv;
u32 div;
u8 data[4];
struct i2c_msg msg = { .addr = 0x61, .flags = 0, .buf = data, .len = sizeof(data) };
div = c->frequency / 1000;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = 0xc2;
if (div < 1450)
data[3] = 0x00;
else if (div < 1850)
data[3] = 0x40;
else if (div < 2000)
data[3] = 0x80;
else
data[3] = 0xc0;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&budget->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int alps_tdhd1_204_request_firmware(struct dvb_frontend *fe, const struct firmware **fw, char *name)
{
struct budget *budget = (struct budget *)fe->dvb->priv;
return request_firmware(fw, name, &budget->dev->pci->dev);
}
static int i2c_readreg(struct i2c_adapter *i2c, u8 adr, u8 reg)
{
u8 val;
struct i2c_msg msg[] = {
{ .addr = adr, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = adr, .flags = I2C_M_RD, .buf = &val, .len = 1 }
};
return (i2c_transfer(i2c, msg, 2) != 2) ? -EIO : val;
}
static u8 read_pwm(struct budget* budget)
{
u8 b = 0xff;
u8 pwm;
struct i2c_msg msg[] = { { .addr = 0x50,.flags = 0,.buf = &b,.len = 1 },
{ .addr = 0x50,.flags = I2C_M_RD,.buf = &pwm,.len = 1} };
if ((i2c_transfer(&budget->i2c_adap, msg, 2) != 2) || (pwm == 0xff))
pwm = 0x48;
return pwm;
}
static void frontend_init(struct budget *budget)
{
(void)alps_bsbe1_config;
switch(budget->dev->pci->subsystem_device) {
case 0x1003:
case 0x1013:
budget->dvb_frontend = dvb_attach(ves1x93_attach, &alps_bsrv2_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsrv2_tuner_set_params;
budget->dvb_frontend->ops.diseqc_send_master_cmd = budget_diseqc_send_master_cmd;
budget->dvb_frontend->ops.diseqc_send_burst = budget_diseqc_send_burst;
budget->dvb_frontend->ops.set_tone = budget_set_tone;
break;
}
budget->dvb_frontend = dvb_attach(stv0299_attach, &alps_bsru6_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsru6_tuner_set_params;
budget->dvb_frontend->tuner_priv = &budget->i2c_adap;
if (budget->dev->pci->subsystem_device == 0x1003 && diseqc_method == 0) {
budget->dvb_frontend->ops.diseqc_send_master_cmd = budget_diseqc_send_master_cmd;
budget->dvb_frontend->ops.diseqc_send_burst = budget_diseqc_send_burst;
budget->dvb_frontend->ops.set_tone = budget_set_tone;
}
break;
}
break;
case 0x1004:
budget->dvb_frontend = dvb_attach(ves1820_attach, &alps_tdbe2_config, &budget->i2c_adap, read_pwm(budget));
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = alps_tdbe2_tuner_set_params;
break;
}
break;
case 0x1005:
budget->dvb_frontend = dvb_attach(l64781_attach, &grundig_29504_401_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = grundig_29504_401_tuner_set_params;
budget->dvb_frontend->tuner_priv = NULL;
break;
}
break;
case 0x4f60:
{
int subtype = i2c_readreg(&budget->i2c_adap, 0x50, 0x67);
if (subtype < 0)
break;
if (subtype < 0x36) {
budget->dvb_frontend = dvb_attach(stv0299_attach, &alps_bsru6_config_activy, &budget->i2c_adap);
if (budget->dvb_frontend) {
printk(KERN_INFO "budget: tuner ALPS BSRU6 detected\n");
budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsru6_tuner_set_params;
budget->dvb_frontend->tuner_priv = &budget->i2c_adap;
budget->dvb_frontend->ops.set_voltage = siemens_budget_set_voltage;
budget->dvb_frontend->ops.dishnetwork_send_legacy_command = NULL;
break;
}
} else {
saa7146_setgpio(budget->dev, 3, SAA7146_GPIO_OUTLO);
msleep(50);
saa7146_setgpio(budget->dev, 3, SAA7146_GPIO_OUTHI);
msleep(250);
budget->dvb_frontend = dvb_attach(stv0299_attach, &alps_bsbe1_config_activy, &budget->i2c_adap);
if (budget->dvb_frontend) {
printk(KERN_INFO "budget: tuner ALPS BSBE1 detected\n");
budget->dvb_frontend->ops.tuner_ops.set_params = alps_bsbe1_tuner_set_params;
budget->dvb_frontend->tuner_priv = &budget->i2c_adap;
budget->dvb_frontend->ops.set_voltage = siemens_budget_set_voltage;
budget->dvb_frontend->ops.dishnetwork_send_legacy_command = NULL;
break;
}
}
break;
}
case 0x4f61:
budget->dvb_frontend = dvb_attach(tda8083_attach, &grundig_29504_451_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = grundig_29504_451_tuner_set_params;
budget->dvb_frontend->ops.set_voltage = siemens_budget_set_voltage;
budget->dvb_frontend->ops.dishnetwork_send_legacy_command = NULL;
}
break;
case 0x5f60:
budget->dvb_frontend = dvb_attach(tda10046_attach, &alps_tdhd1_204a_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = alps_tdhd1_204a_tuner_set_params;
budget->dvb_frontend->tuner_priv = &budget->i2c_adap;
}
break;
case 0x5f61:
budget->dvb_frontend = dvb_attach(l64781_attach, &grundig_29504_401_config_activy, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->tuner_priv = &tuner_address_grundig_29504_401_activy;
budget->dvb_frontend->ops.tuner_ops.set_params = grundig_29504_401_tuner_set_params;
}
break;
case 0x1016:
budget->dvb_frontend = dvb_attach(s5h1420_attach, &s5h1420_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
budget->dvb_frontend->ops.tuner_ops.set_params = s5h1420_tuner_set_params;
if (dvb_attach(lnbp21_attach, budget->dvb_frontend, &budget->i2c_adap, 0, 0) == NULL) {
printk("%s: No LNBP21 found!\n", __func__);
goto error_out;
}
break;
}
case 0x1018:
saa7146_setgpio(budget->dev, 2, SAA7146_GPIO_OUTLO);
msleep(1);
saa7146_setgpio(budget->dev, 2, SAA7146_GPIO_OUTHI);
msleep(1);
budget->dvb_frontend = dvb_attach(tda10086_attach, &tda10086_config, &budget->i2c_adap);
if (budget->dvb_frontend) {
if (dvb_attach(tda826x_attach, budget->dvb_frontend, 0x60, &budget->i2c_adap, 0) == NULL)
printk("%s: No tda826x found!\n", __func__);
if (dvb_attach(lnbp21_attach, budget->dvb_frontend, &budget->i2c_adap, 0, 0) == NULL) {
printk("%s: No LNBP21 found!\n", __func__);
goto error_out;
}
break;
}
case 0x101c: {
struct stv6110x_devctl *ctl;
saa7146_setgpio(budget->dev, 2, SAA7146_GPIO_OUTLO);
msleep(50);
saa7146_setgpio(budget->dev, 2, SAA7146_GPIO_OUTHI);
msleep(250);
budget->dvb_frontend = dvb_attach(stv090x_attach,
&tt1600_stv090x_config,
&budget->i2c_adap,
STV090x_DEMODULATOR_0);
if (budget->dvb_frontend) {
ctl = dvb_attach(stv6110x_attach,
budget->dvb_frontend,
&tt1600_stv6110x_config,
&budget->i2c_adap);
if (ctl) {
tt1600_stv090x_config.tuner_init = ctl->tuner_init;
tt1600_stv090x_config.tuner_sleep = ctl->tuner_sleep;
tt1600_stv090x_config.tuner_set_mode = ctl->tuner_set_mode;
tt1600_stv090x_config.tuner_set_frequency = ctl->tuner_set_frequency;
tt1600_stv090x_config.tuner_get_frequency = ctl->tuner_get_frequency;
tt1600_stv090x_config.tuner_set_bandwidth = ctl->tuner_set_bandwidth;
tt1600_stv090x_config.tuner_get_bandwidth = ctl->tuner_get_bandwidth;
tt1600_stv090x_config.tuner_set_bbgain = ctl->tuner_set_bbgain;
tt1600_stv090x_config.tuner_get_bbgain = ctl->tuner_get_bbgain;
tt1600_stv090x_config.tuner_set_refclk = ctl->tuner_set_refclk;
tt1600_stv090x_config.tuner_get_status = ctl->tuner_get_status;
if (budget->dvb_frontend->ops.init)
budget->dvb_frontend->ops.init(budget->dvb_frontend);
if (dvb_attach(isl6423_attach,
budget->dvb_frontend,
&budget->i2c_adap,
&tt1600_isl6423_config) == NULL) {
printk(KERN_ERR "%s: No Intersil ISL6423 found!\n", __func__);
goto error_out;
}
} else {
printk(KERN_ERR "%s: No STV6110(A) Silicon Tuner found!\n", __func__);
goto error_out;
}
}
}
break;
}
if (budget->dvb_frontend == NULL) {
printk("budget: A frontend driver was not found for device [%04x:%04x] subsystem [%04x:%04x]\n",
budget->dev->pci->vendor,
budget->dev->pci->device,
budget->dev->pci->subsystem_vendor,
budget->dev->pci->subsystem_device);
} else {
if (dvb_register_frontend(&budget->dvb_adapter, budget->dvb_frontend))
goto error_out;
}
return;
error_out:
printk("budget: Frontend registration failed!\n");
dvb_frontend_detach(budget->dvb_frontend);
budget->dvb_frontend = NULL;
return;
}
static int budget_attach (struct saa7146_dev* dev, struct saa7146_pci_extension_data *info)
{
struct budget *budget = NULL;
int err;
budget = kmalloc(sizeof(struct budget), GFP_KERNEL);
if( NULL == budget ) {
return -ENOMEM;
}
dprintk(2, "dev:%p, info:%p, budget:%p\n", dev, info, budget);
dev->ext_priv = budget;
err = ttpci_budget_init(budget, dev, info, THIS_MODULE, adapter_nr);
if (err) {
printk("==> failed\n");
kfree (budget);
return err;
}
budget->dvb_adapter.priv = budget;
frontend_init(budget);
ttpci_budget_init_hooks(budget);
return 0;
}
static int budget_detach (struct saa7146_dev* dev)
{
struct budget *budget = (struct budget*) dev->ext_priv;
int err;
if (budget->dvb_frontend) {
dvb_unregister_frontend(budget->dvb_frontend);
dvb_frontend_detach(budget->dvb_frontend);
}
err = ttpci_budget_deinit (budget);
kfree (budget);
dev->ext_priv = NULL;
return err;
}
static int __init budget_init(void)
{
return saa7146_register_extension(&budget_extension);
}
static void __exit budget_exit(void)
{
saa7146_unregister_extension(&budget_extension);
}
