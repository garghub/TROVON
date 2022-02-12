static int s5h1432_writereg(struct s5h1432_state *state,
u8 addr, u8 reg, u8 data)
{
int ret;
u8 buf[] = { reg, data };
struct i2c_msg msg = {.addr = addr, .flags = 0, .buf = buf, .len = 2 };
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
printk(KERN_ERR "%s: writereg error 0x%02x 0x%02x 0x%04x, ret == %i)\n",
__func__, addr, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static u8 s5h1432_readreg(struct s5h1432_state *state, u8 addr, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{.addr = addr, .flags = 0, .buf = b0, .len = 1},
{.addr = addr, .flags = I2C_M_RD, .buf = b1, .len = 1}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
printk(KERN_ERR "%s: readreg error (ret == %i)\n",
__func__, ret);
return b1[0];
}
static int s5h1432_sleep(struct dvb_frontend *fe)
{
return 0;
}
static int s5h1432_set_channel_bandwidth(struct dvb_frontend *fe,
u32 bandwidth)
{
struct s5h1432_state *state = fe->demodulator_priv;
u8 reg = 0;
reg = s5h1432_readreg(state, S5H1432_I2C_TOP_ADDR, 0x2E);
reg &= ~(0x0C);
switch (bandwidth) {
case 6:
reg |= 0x08;
break;
case 7:
reg |= 0x04;
break;
case 8:
reg |= 0x00;
break;
default:
return 0;
}
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x2E, reg);
return 1;
}
static int s5h1432_set_IF(struct dvb_frontend *fe, u32 ifFreqHz)
{
struct s5h1432_state *state = fe->demodulator_priv;
switch (ifFreqHz) {
case TAIWAN_HI_IF_FREQ_44_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x55);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x55);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0x15);
break;
case EUROPE_HI_IF_FREQ_36_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0x40);
break;
case IF_FREQ_6_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0xe0);
break;
case IF_FREQ_3point3_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x66);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x66);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0xEE);
break;
case IF_FREQ_3point5_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x55);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x55);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0xED);
break;
case IF_FREQ_4_MHZ:
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0xAA);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0xAA);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0xEA);
break;
default:
{
u32 value = 0;
value = (u32) (((48000 - (ifFreqHz / 1000)) * 512 *
(u32) 32768) / (48 * 1000));
printk(KERN_INFO
"Default IFFreq %d :reg value = 0x%x\n",
ifFreqHz, value);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4,
(u8) value & 0xFF);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5,
(u8) (value >> 8) & 0xFF);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7,
(u8) (value >> 16) & 0xFF);
break;
}
}
return 1;
}
static int s5h1432_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
u32 dvb_bandwidth = 8;
struct s5h1432_state *state = fe->demodulator_priv;
if (p->frequency == state->current_frequency) {
} else {
fe->ops.tuner_ops.set_params(fe);
msleep(300);
s5h1432_set_channel_bandwidth(fe, dvb_bandwidth);
switch (p->bandwidth_hz) {
case 6000000:
dvb_bandwidth = 6;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
case 7000000:
dvb_bandwidth = 7;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
case 8000000:
dvb_bandwidth = 8;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
default:
return 0;
}
msleep(30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1a);
msleep(30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1b);
s5h1432_set_channel_bandwidth(fe, dvb_bandwidth);
switch (p->bandwidth_hz) {
case 6000000:
dvb_bandwidth = 6;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
case 7000000:
dvb_bandwidth = 7;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
case 8000000:
dvb_bandwidth = 8;
s5h1432_set_IF(fe, IF_FREQ_4_MHZ);
break;
default:
return 0;
}
msleep(30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1a);
msleep(30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1b);
}
state->current_frequency = p->frequency;
return 0;
}
static int s5h1432_init(struct dvb_frontend *fe)
{
struct s5h1432_state *state = fe->demodulator_priv;
u8 reg = 0;
state->current_frequency = 0;
printk(KERN_INFO " s5h1432_init().\n");
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x04, 0xa8);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x05, 0x01);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x07, 0x70);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x19, 0x80);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x1b, 0x9D);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x1c, 0x30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x1d, 0x20);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x1e, 0x1B);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x2e, 0x40);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x42, 0x84);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x50, 0x5a);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x5a, 0xd3);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x68, 0x50);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xb8, 0x3c);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xc4, 0x10);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xcc, 0x9c);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xDA, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe1, 0x94);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xf9, 0x00);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe4, 0x66);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe5, 0x66);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0xe7, 0xEE);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x1e, 0x31);
reg = s5h1432_readreg(state, S5H1432_I2C_TOP_ADDR, 0x42);
reg |= 0x80;
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x42, reg);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1a);
msleep(30);
s5h1432_writereg(state, S5H1432_I2C_TOP_ADDR, 0x09, 0x1b);
return 0;
}
static int s5h1432_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
return 0;
}
static int s5h1432_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
return 0;
}
static int s5h1432_read_snr(struct dvb_frontend *fe, u16 *snr)
{
return 0;
}
static int s5h1432_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
return 0;
}
static int s5h1432_read_ber(struct dvb_frontend *fe, u32 *ber)
{
return 0;
}
static int s5h1432_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
return 0;
}
static void s5h1432_release(struct dvb_frontend *fe)
{
struct s5h1432_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *s5h1432_attach(const struct s5h1432_config *config,
struct i2c_adapter *i2c)
{
struct s5h1432_state *state = NULL;
printk(KERN_INFO " Enter s5h1432_attach(). attach success!\n");
state = kmalloc(sizeof(struct s5h1432_state), GFP_KERNEL);
if (!state)
return NULL;
state->config = config;
state->i2c = i2c;
state->current_modulation = QAM_16;
state->inversion = state->config->inversion;
memcpy(&state->frontend.ops, &s5h1432_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
