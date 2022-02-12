static int isl6421_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct isl6421 *isl6421 = (struct isl6421 *) fe->sec_priv;
struct i2c_msg msg = { .addr = isl6421->i2c_addr, .flags = 0,
.buf = &isl6421->config,
.len = sizeof(isl6421->config) };
isl6421->config &= ~(ISL6421_VSEL1 | ISL6421_EN1);
switch(voltage) {
case SEC_VOLTAGE_OFF:
break;
case SEC_VOLTAGE_13:
isl6421->config |= ISL6421_EN1;
break;
case SEC_VOLTAGE_18:
isl6421->config |= (ISL6421_EN1 | ISL6421_VSEL1);
break;
default:
return -EINVAL;
}
isl6421->config |= isl6421->override_or;
isl6421->config &= isl6421->override_and;
return (i2c_transfer(isl6421->i2c, &msg, 1) == 1) ? 0 : -EIO;
}
static int isl6421_enable_high_lnb_voltage(struct dvb_frontend *fe, long arg)
{
struct isl6421 *isl6421 = (struct isl6421 *) fe->sec_priv;
struct i2c_msg msg = { .addr = isl6421->i2c_addr, .flags = 0,
.buf = &isl6421->config,
.len = sizeof(isl6421->config) };
if (arg)
isl6421->config |= ISL6421_LLC1;
else
isl6421->config &= ~ISL6421_LLC1;
isl6421->config |= isl6421->override_or;
isl6421->config &= isl6421->override_and;
return (i2c_transfer(isl6421->i2c, &msg, 1) == 1) ? 0 : -EIO;
}
static int isl6421_set_tone(struct dvb_frontend *fe,
enum fe_sec_tone_mode tone)
{
struct isl6421 *isl6421 = (struct isl6421 *) fe->sec_priv;
struct i2c_msg msg = { .addr = isl6421->i2c_addr, .flags = 0,
.buf = &isl6421->config,
.len = sizeof(isl6421->config) };
switch (tone) {
case SEC_TONE_ON:
isl6421->config |= ISL6421_ENT1;
break;
case SEC_TONE_OFF:
isl6421->config &= ~ISL6421_ENT1;
break;
default:
return -EINVAL;
}
isl6421->config |= isl6421->override_or;
isl6421->config &= isl6421->override_and;
return (i2c_transfer(isl6421->i2c, &msg, 1) == 1) ? 0 : -EIO;
}
static void isl6421_release(struct dvb_frontend *fe)
{
isl6421_set_voltage(fe, SEC_VOLTAGE_OFF);
kfree(fe->sec_priv);
fe->sec_priv = NULL;
}
struct dvb_frontend *isl6421_attach(struct dvb_frontend *fe, struct i2c_adapter *i2c, u8 i2c_addr,
u8 override_set, u8 override_clear, bool override_tone)
{
struct isl6421 *isl6421 = kmalloc(sizeof(struct isl6421), GFP_KERNEL);
if (!isl6421)
return NULL;
isl6421->config = ISL6421_ISEL1;
isl6421->i2c = i2c;
isl6421->i2c_addr = i2c_addr;
fe->sec_priv = isl6421;
isl6421->override_or = override_set;
isl6421->override_and = ~override_clear;
if (isl6421_set_voltage(fe, SEC_VOLTAGE_OFF)) {
kfree(isl6421);
fe->sec_priv = NULL;
return NULL;
}
fe->ops.release_sec = isl6421_release;
fe->ops.set_voltage = isl6421_set_voltage;
fe->ops.enable_high_lnb_voltage = isl6421_enable_high_lnb_voltage;
if (override_tone)
fe->ops.set_tone = isl6421_set_tone;
return fe;
}
