static int tda1002x_cu1216_tuner_set(struct dvb_frontend *fe, struct dvb_frontend_parameters *params)
{
struct mantis_pci *mantis = fe->dvb->priv;
struct i2c_adapter *adapter = &mantis->adapter;
u8 buf[6];
struct i2c_msg msg = {.addr = 0x60, .flags = 0, .buf = buf, .len = sizeof(buf)};
int i;
#define CU1216_IF 36125000
#define TUNER_MUL 62500
u32 div = (params->frequency + CU1216_IF + TUNER_MUL / 2) / TUNER_MUL;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0xce;
buf[3] = (params->frequency < 150000000 ? 0x01 :
params->frequency < 445000000 ? 0x02 : 0x04);
buf[4] = 0xde;
buf[5] = 0x20;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(adapter, &msg, 1) != 1)
return -EIO;
msg.flags = I2C_M_RD;
msg.len = 1;
for (i = 0; i < 20; i++) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(adapter, &msg, 1) == 1 && (buf[0] & 0x40))
break;
msleep(10);
}
msg.flags = 0;
msg.len = 2;
msg.buf = &buf[2];
buf[2] &= ~0x40;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(adapter, &msg, 1) != 1)
return -EIO;
return 0;
}
static u8 read_pwm(struct mantis_pci *mantis)
{
struct i2c_adapter *adapter = &mantis->adapter;
u8 b = 0xff;
u8 pwm;
struct i2c_msg msg[] = {
{.addr = 0x50, .flags = 0, .buf = &b, .len = 1},
{.addr = 0x50, .flags = I2C_M_RD, .buf = &pwm, .len = 1}
};
if ((i2c_transfer(adapter, msg, 2) != 2)
|| (pwm == 0xff))
pwm = 0x48;
return pwm;
}
static int vp2040_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
struct i2c_adapter *adapter = &mantis->adapter;
int err = 0;
err = mantis_frontend_power(mantis, POWER_ON);
if (err == 0) {
mantis_frontend_soft_reset(mantis);
msleep(250);
dprintk(MANTIS_ERROR, 1, "Probing for CU1216 (DVB-C)");
fe = dvb_attach(tda10021_attach, &vp2040_tda1002x_cu1216_config,
adapter,
read_pwm(mantis));
if (fe) {
dprintk(MANTIS_ERROR, 1,
"found Philips CU1216 DVB-C frontend (TDA10021) @ 0x%02x",
vp2040_tda1002x_cu1216_config.demod_address);
} else {
fe = dvb_attach(tda10023_attach, &vp2040_tda10023_cu1216_config,
adapter,
read_pwm(mantis));
if (fe) {
dprintk(MANTIS_ERROR, 1,
"found Philips CU1216 DVB-C frontend (TDA10023) @ 0x%02x",
vp2040_tda1002x_cu1216_config.demod_address);
}
}
if (fe) {
fe->ops.tuner_ops.set_params = tda1002x_cu1216_tuner_set;
dprintk(MANTIS_ERROR, 1, "Mantis DVB-C Philips CU1216 frontend attach success");
} else {
return -1;
}
} else {
dprintk(MANTIS_ERROR, 1, "Frontend on <%s> POWER ON failed! <%d>",
adapter->name,
err);
return -EIO;
}
mantis->fe = fe;
dprintk(MANTIS_DEBUG, 1, "Done!");
return 0;
}
