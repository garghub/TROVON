static int lgtdqcs001f_tuner_set(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct mantis_pci *mantis = fe->dvb->priv;
struct i2c_adapter *adapter = &mantis->adapter;
u8 buf[4];
u32 div;
struct i2c_msg msg = {.addr = 0x61, .flags = 0, .buf = buf, .len = sizeof(buf)};
div = p->frequency / 250;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x83;
buf[3] = 0xc0;
if (p->frequency < 1531000)
buf[3] |= 0x04;
else
buf[3] &= ~0x04;
if (i2c_transfer(adapter, &msg, 1) < 0) {
dprintk(MANTIS_ERROR, 1, "Write: I2C Transfer failed");
return -EIO;
}
msleep_interruptible(100);
return 0;
}
static int lgtdqcs001f_set_symbol_rate(struct dvb_frontend *fe,
u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
if (srate < 1500000) {
aclk = 0xb7;
bclk = 0x47;
} else if (srate < 3000000) {
aclk = 0xb7;
bclk = 0x4b;
} else if (srate < 7000000) {
aclk = 0xb7;
bclk = 0x4f;
} else if (srate < 14000000) {
aclk = 0xb7;
bclk = 0x53;
} else if (srate < 30000000) {
aclk = 0xb6;
bclk = 0x53;
} else if (srate < 45000000) {
aclk = 0xb4;
bclk = 0x51;
}
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, ratio & 0xf0);
return 0;
}
static int vp1033_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
struct i2c_adapter *adapter = &mantis->adapter;
int err = 0;
err = mantis_frontend_power(mantis, POWER_ON);
if (err == 0) {
mantis_frontend_soft_reset(mantis);
msleep(250);
dprintk(MANTIS_ERROR, 1, "Probing for STV0299 (DVB-S)");
fe = dvb_attach(stv0299_attach, &lgtdqcs001f_config, adapter);
if (fe) {
fe->ops.tuner_ops.set_params = lgtdqcs001f_tuner_set;
dprintk(MANTIS_ERROR, 1, "found STV0299 DVB-S frontend @ 0x%02x",
lgtdqcs001f_config.demod_address);
dprintk(MANTIS_ERROR, 1, "Mantis DVB-S STV0299 frontend attach success");
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
dprintk(MANTIS_ERROR, 1, "Done!");
return 0;
}
