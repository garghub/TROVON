static int stv0297_writereg(struct stv0297_state *state, u8 reg, u8 data)
{
int ret;
u8 buf[] = { reg, data };
struct i2c_msg msg = {.addr = state->config->demod_address,.flags = 0,.buf = buf,.len = 2 };
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: writereg error (reg == 0x%02x, val == 0x%02x, "
"ret == %i)\n", __func__, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static int stv0297_readreg(struct stv0297_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = { {.addr = state->config->demod_address,.flags = 0,.buf = b0,.len = 1},
{.addr = state->config->demod_address,.flags = I2C_M_RD,.buf = b1,.len = 1}
};
if (state->config->stop_during_read) {
if ((ret = i2c_transfer(state->i2c, &msg[0], 1)) != 1) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg, ret);
return -1;
}
if ((ret = i2c_transfer(state->i2c, &msg[1], 1)) != 1) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg, ret);
return -1;
}
} else {
if ((ret = i2c_transfer(state->i2c, msg, 2)) != 2) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg, ret);
return -1;
}
}
return b1[0];
}
static int stv0297_writereg_mask(struct stv0297_state *state, u8 reg, u8 mask, u8 data)
{
int val;
val = stv0297_readreg(state, reg);
val &= ~mask;
val |= (data & mask);
stv0297_writereg(state, reg, val);
return 0;
}
static int stv0297_readregs(struct stv0297_state *state, u8 reg1, u8 * b, u8 len)
{
int ret;
struct i2c_msg msg[] = { {.addr = state->config->demod_address,.flags = 0,.buf =
&reg1,.len = 1},
{.addr = state->config->demod_address,.flags = I2C_M_RD,.buf = b,.len = len}
};
if (state->config->stop_during_read) {
if ((ret = i2c_transfer(state->i2c, &msg[0], 1)) != 1) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg1, ret);
return -1;
}
if ((ret = i2c_transfer(state->i2c, &msg[1], 1)) != 1) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg1, ret);
return -1;
}
} else {
if ((ret = i2c_transfer(state->i2c, msg, 2)) != 2) {
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n", __func__, reg1, ret);
return -1;
}
}
return 0;
}
static u32 stv0297_get_symbolrate(struct stv0297_state *state)
{
u64 tmp;
tmp = stv0297_readreg(state, 0x55);
tmp |= stv0297_readreg(state, 0x56) << 8;
tmp |= stv0297_readreg(state, 0x57) << 16;
tmp |= stv0297_readreg(state, 0x58) << 24;
tmp *= STV0297_CLOCK_KHZ;
tmp >>= 32;
return (u32) tmp;
}
static void stv0297_set_symbolrate(struct stv0297_state *state, u32 srate)
{
long tmp;
tmp = 131072L * srate;
tmp = tmp / (STV0297_CLOCK_KHZ / 4);
tmp = tmp * 8192L;
stv0297_writereg(state, 0x55, (unsigned char) (tmp & 0xFF));
stv0297_writereg(state, 0x56, (unsigned char) (tmp >> 8));
stv0297_writereg(state, 0x57, (unsigned char) (tmp >> 16));
stv0297_writereg(state, 0x58, (unsigned char) (tmp >> 24));
}
static void stv0297_set_sweeprate(struct stv0297_state *state, short fshift, long symrate)
{
long tmp;
tmp = (long) fshift *262144L;
tmp /= symrate;
tmp *= 1024;
if (tmp >= 0) {
tmp += 500000;
} else {
tmp -= 500000;
}
tmp /= 1000000;
stv0297_writereg(state, 0x60, tmp & 0xFF);
stv0297_writereg_mask(state, 0x69, 0xF0, (tmp >> 4) & 0xf0);
}
static void stv0297_set_carrieroffset(struct stv0297_state *state, long offset)
{
long tmp;
tmp = offset * 26844L;
if (tmp < 0)
tmp += 0x10000000;
tmp &= 0x0FFFFFFF;
stv0297_writereg(state, 0x66, (unsigned char) (tmp & 0xFF));
stv0297_writereg(state, 0x67, (unsigned char) (tmp >> 8));
stv0297_writereg(state, 0x68, (unsigned char) (tmp >> 16));
stv0297_writereg_mask(state, 0x69, 0x0F, (tmp >> 24) & 0x0f);
}
static void stv0297_set_initialdemodfreq(struct stv0297_state *state, long freq)
{
s32 tmp;
if (freq > 10000)
freq -= STV0297_CLOCK_KHZ;
tmp = (STV0297_CLOCK_KHZ * 1000) / (1 << 16);
tmp = (freq * 1000) / tmp;
if (tmp > 0xffff)
tmp = 0xffff;
stv0297_writereg_mask(state, 0x25, 0x80, 0x80);
stv0297_writereg(state, 0x21, tmp >> 8);
stv0297_writereg(state, 0x20, tmp);
}
static int stv0297_set_qam(struct stv0297_state *state, fe_modulation_t modulation)
{
int val = 0;
switch (modulation) {
case QAM_16:
val = 0;
break;
case QAM_32:
val = 1;
break;
case QAM_64:
val = 4;
break;
case QAM_128:
val = 2;
break;
case QAM_256:
val = 3;
break;
default:
return -EINVAL;
}
stv0297_writereg_mask(state, 0x00, 0x70, val << 4);
return 0;
}
static int stv0297_set_inversion(struct stv0297_state *state, fe_spectral_inversion_t inversion)
{
int val = 0;
switch (inversion) {
case INVERSION_OFF:
val = 0;
break;
case INVERSION_ON:
val = 1;
break;
default:
return -EINVAL;
}
stv0297_writereg_mask(state, 0x83, 0x08, val << 3);
return 0;
}
static int stv0297_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct stv0297_state *state = fe->demodulator_priv;
if (enable) {
stv0297_writereg(state, 0x87, 0x78);
stv0297_writereg(state, 0x86, 0xc8);
}
return 0;
}
static int stv0297_init(struct dvb_frontend *fe)
{
struct stv0297_state *state = fe->demodulator_priv;
int i;
for (i=0; !(state->config->inittab[i] == 0xff && state->config->inittab[i+1] == 0xff); i+=2)
stv0297_writereg(state, state->config->inittab[i], state->config->inittab[i+1]);
msleep(200);
state->last_ber = 0;
return 0;
}
static int stv0297_sleep(struct dvb_frontend *fe)
{
struct stv0297_state *state = fe->demodulator_priv;
stv0297_writereg_mask(state, 0x80, 1, 1);
return 0;
}
static int stv0297_read_status(struct dvb_frontend *fe, fe_status_t * status)
{
struct stv0297_state *state = fe->demodulator_priv;
u8 sync = stv0297_readreg(state, 0xDF);
*status = 0;
if (sync & 0x80)
*status |=
FE_HAS_SYNC | FE_HAS_SIGNAL | FE_HAS_CARRIER | FE_HAS_VITERBI | FE_HAS_LOCK;
return 0;
}
static int stv0297_read_ber(struct dvb_frontend *fe, u32 * ber)
{
struct stv0297_state *state = fe->demodulator_priv;
u8 BER[3];
stv0297_readregs(state, 0xA0, BER, 3);
if (!(BER[0] & 0x80)) {
state->last_ber = BER[2] << 8 | BER[1];
stv0297_writereg_mask(state, 0xA0, 0x80, 0x80);
}
*ber = state->last_ber;
return 0;
}
static int stv0297_read_signal_strength(struct dvb_frontend *fe, u16 * strength)
{
struct stv0297_state *state = fe->demodulator_priv;
u8 STRENGTH[3];
u16 tmp;
stv0297_readregs(state, 0x41, STRENGTH, 3);
tmp = (STRENGTH[1] & 0x03) << 8 | STRENGTH[0];
if (STRENGTH[2] & 0x20) {
if (tmp < 0x200)
tmp = 0;
else
tmp = tmp - 0x200;
} else {
if (tmp > 0x1ff)
tmp = 0;
else
tmp = 0x1ff - tmp;
}
*strength = (tmp << 7) | (tmp >> 2);
return 0;
}
static int stv0297_read_snr(struct dvb_frontend *fe, u16 * snr)
{
struct stv0297_state *state = fe->demodulator_priv;
u8 SNR[2];
stv0297_readregs(state, 0x07, SNR, 2);
*snr = SNR[1] << 8 | SNR[0];
return 0;
}
static int stv0297_read_ucblocks(struct dvb_frontend *fe, u32 * ucblocks)
{
struct stv0297_state *state = fe->demodulator_priv;
stv0297_writereg_mask(state, 0xDF, 0x03, 0x03);
*ucblocks = (stv0297_readreg(state, 0xD5) << 8)
| stv0297_readreg(state, 0xD4);
stv0297_writereg_mask(state, 0xDF, 0x03, 0x02);
stv0297_writereg_mask(state, 0xDF, 0x03, 0x01);
return 0;
}
static int stv0297_set_frontend(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
struct stv0297_state *state = fe->demodulator_priv;
int u_threshold;
int initial_u;
int blind_u;
int delay;
int sweeprate;
int carrieroffset;
unsigned long starttime;
unsigned long timeout;
fe_spectral_inversion_t inversion;
switch (p->u.qam.modulation) {
case QAM_16:
case QAM_32:
case QAM_64:
delay = 100;
sweeprate = 1000;
break;
case QAM_128:
case QAM_256:
delay = 200;
sweeprate = 500;
break;
default:
return -EINVAL;
}
inversion = p->inversion;
if (state->config->invert)
inversion = (inversion == INVERSION_ON) ? INVERSION_OFF : INVERSION_ON;
carrieroffset = -330;
switch (inversion) {
case INVERSION_OFF:
break;
case INVERSION_ON:
sweeprate = -sweeprate;
carrieroffset = -carrieroffset;
break;
default:
return -EINVAL;
}
stv0297_init(fe);
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe, p);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
stv0297_writereg(state, 0x82, 0x0);
stv0297_set_initialdemodfreq(state, 7250);
stv0297_writereg_mask(state, 0x43, 0x10, 0x00);
stv0297_writereg(state, 0x41, 0x00);
stv0297_writereg_mask(state, 0x42, 0x03, 0x01);
stv0297_writereg_mask(state, 0x36, 0x60, 0x00);
stv0297_writereg_mask(state, 0x36, 0x18, 0x00);
stv0297_writereg_mask(state, 0x71, 0x80, 0x80);
stv0297_writereg(state, 0x72, 0x00);
stv0297_writereg(state, 0x73, 0x00);
stv0297_writereg_mask(state, 0x74, 0x0F, 0x00);
stv0297_writereg_mask(state, 0x43, 0x08, 0x00);
stv0297_writereg_mask(state, 0x71, 0x80, 0x00);
stv0297_writereg_mask(state, 0x5a, 0x20, 0x20);
stv0297_writereg_mask(state, 0x5b, 0x02, 0x02);
stv0297_writereg_mask(state, 0x5b, 0x02, 0x00);
stv0297_writereg_mask(state, 0x5b, 0x01, 0x00);
stv0297_writereg_mask(state, 0x5a, 0x40, 0x40);
stv0297_writereg_mask(state, 0x6a, 0x01, 0x00);
stv0297_writereg_mask(state, 0x81, 0x01, 0x01);
stv0297_writereg_mask(state, 0x81, 0x01, 0x00);
stv0297_writereg_mask(state, 0x83, 0x20, 0x20);
stv0297_writereg_mask(state, 0x83, 0x20, 0x00);
u_threshold = stv0297_readreg(state, 0x00) & 0xf;
initial_u = stv0297_readreg(state, 0x01) >> 4;
blind_u = stv0297_readreg(state, 0x01) & 0xf;
stv0297_writereg_mask(state, 0x84, 0x01, 0x01);
stv0297_writereg_mask(state, 0x84, 0x01, 0x00);
stv0297_writereg_mask(state, 0x00, 0x0f, u_threshold);
stv0297_writereg_mask(state, 0x01, 0xf0, initial_u << 4);
stv0297_writereg_mask(state, 0x01, 0x0f, blind_u);
stv0297_writereg_mask(state, 0x87, 0x80, 0x00);
stv0297_writereg(state, 0x63, 0x00);
stv0297_writereg(state, 0x64, 0x00);
stv0297_writereg(state, 0x65, 0x00);
stv0297_writereg(state, 0x66, 0x00);
stv0297_writereg(state, 0x67, 0x00);
stv0297_writereg(state, 0x68, 0x00);
stv0297_writereg_mask(state, 0x69, 0x0f, 0x00);
stv0297_set_qam(state, p->u.qam.modulation);
stv0297_set_symbolrate(state, p->u.qam.symbol_rate / 1000);
stv0297_set_sweeprate(state, sweeprate, p->u.qam.symbol_rate / 1000);
stv0297_set_carrieroffset(state, carrieroffset);
stv0297_set_inversion(state, inversion);
if (p->u.qam.modulation == QAM_128 ||
p->u.qam.modulation == QAM_256)
stv0297_writereg_mask(state, 0x88, 0x08, 0x00);
else
stv0297_writereg_mask(state, 0x88, 0x08, 0x08);
stv0297_writereg_mask(state, 0x5a, 0x20, 0x00);
stv0297_writereg_mask(state, 0x6a, 0x01, 0x01);
stv0297_writereg_mask(state, 0x43, 0x40, 0x40);
stv0297_writereg_mask(state, 0x5b, 0x30, 0x00);
stv0297_writereg_mask(state, 0x03, 0x0c, 0x0c);
stv0297_writereg_mask(state, 0x03, 0x03, 0x03);
stv0297_writereg_mask(state, 0x43, 0x10, 0x10);
starttime = jiffies;
timeout = jiffies + msecs_to_jiffies(2000);
while (time_before(jiffies, timeout)) {
msleep(10);
if (stv0297_readreg(state, 0x43) & 0x08)
break;
}
if (time_after(jiffies, timeout)) {
goto timeout;
}
msleep(20);
timeout = jiffies + msecs_to_jiffies(500);
while (time_before(jiffies, timeout)) {
msleep(10);
if (stv0297_readreg(state, 0x82) & 0x04) {
break;
}
}
if (time_after(jiffies, timeout)) {
goto timeout;
}
timeout = jiffies + msecs_to_jiffies(delay);
while (time_before(jiffies, timeout)) {
msleep(10);
if (stv0297_readreg(state, 0x82) & 0x08) {
break;
}
}
if (time_after(jiffies, timeout)) {
goto timeout;
}
stv0297_writereg_mask(state, 0x6a, 1, 0);
stv0297_writereg_mask(state, 0x88, 8, 0);
timeout = jiffies + msecs_to_jiffies(20);
while (time_before(jiffies, timeout)) {
msleep(10);
if (stv0297_readreg(state, 0xDF) & 0x80) {
break;
}
}
if (time_after(jiffies, timeout)) {
goto timeout;
}
msleep(100);
if (!(stv0297_readreg(state, 0xDF) & 0x80)) {
goto timeout;
}
stv0297_writereg_mask(state, 0x5a, 0x40, 0x00);
state->base_freq = p->frequency;
return 0;
timeout:
stv0297_writereg_mask(state, 0x6a, 0x01, 0x00);
return 0;
}
static int stv0297_get_frontend(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
struct stv0297_state *state = fe->demodulator_priv;
int reg_00, reg_83;
reg_00 = stv0297_readreg(state, 0x00);
reg_83 = stv0297_readreg(state, 0x83);
p->frequency = state->base_freq;
p->inversion = (reg_83 & 0x08) ? INVERSION_ON : INVERSION_OFF;
if (state->config->invert)
p->inversion = (p->inversion == INVERSION_ON) ? INVERSION_OFF : INVERSION_ON;
p->u.qam.symbol_rate = stv0297_get_symbolrate(state) * 1000;
p->u.qam.fec_inner = FEC_NONE;
switch ((reg_00 >> 4) & 0x7) {
case 0:
p->u.qam.modulation = QAM_16;
break;
case 1:
p->u.qam.modulation = QAM_32;
break;
case 2:
p->u.qam.modulation = QAM_128;
break;
case 3:
p->u.qam.modulation = QAM_256;
break;
case 4:
p->u.qam.modulation = QAM_64;
break;
}
return 0;
}
static void stv0297_release(struct dvb_frontend *fe)
{
struct stv0297_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *stv0297_attach(const struct stv0297_config *config,
struct i2c_adapter *i2c)
{
struct stv0297_state *state = NULL;
state = kzalloc(sizeof(struct stv0297_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->last_ber = 0;
state->base_freq = 0;
if ((stv0297_readreg(state, 0x80) & 0x70) != 0x20)
goto error;
memcpy(&state->frontend.ops, &stv0297_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
