static int si21_writeregs(struct si21xx_state *state, u8 reg1,
u8 *data, int len)
{
int ret;
u8 buf[60];
struct i2c_msg msg = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf,
.len = len + 1
};
msg.buf[0] = reg1;
memcpy(msg.buf + 1, data, len);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: writereg error (reg1 == 0x%02x, data == 0x%02x, "
"ret == %i)\n", __func__, reg1, data[0], ret);
return (ret != 1) ? -EREMOTEIO : 0;
}
static int si21_writereg(struct si21xx_state *state, u8 reg, u8 data)
{
int ret;
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf,
.len = 2
};
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: writereg error (reg == 0x%02x, data == 0x%02x, "
"ret == %i)\n", __func__, reg, data, ret);
return (ret != 1) ? -EREMOTEIO : 0;
}
static int si21_write(struct dvb_frontend *fe, const u8 buf[], int len)
{
struct si21xx_state *state = fe->demodulator_priv;
if (len != 2)
return -EINVAL;
return si21_writereg(state, buf[0], buf[1]);
}
static u8 si21_readreg(struct si21xx_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 1
}, {
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
dprintk("%s: readreg error (reg == 0x%02x, ret == %i)\n",
__func__, reg, ret);
return b1[0];
}
static int si21_readregs(struct si21xx_state *state, u8 reg1, u8 *b, u8 len)
{
int ret;
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = &reg1,
.len = 1
}, {
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = b,
.len = len
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
dprintk("%s: readreg error (ret == %i)\n", __func__, ret);
return ret == 2 ? 0 : -1;
}
static int si21xx_wait_diseqc_idle(struct si21xx_state *state, int timeout)
{
unsigned long start = jiffies;
dprintk("%s\n", __func__);
while ((si21_readreg(state, LNB_CTRL_REG_1) & 0x8) == 8) {
if (jiffies - start > timeout) {
dprintk("%s: timeout!!\n", __func__);
return -ETIMEDOUT;
}
msleep(10);
};
return 0;
}
static int si21xx_set_symbolrate(struct dvb_frontend *fe, u32 srate)
{
struct si21xx_state *state = fe->demodulator_priv;
u32 sym_rate, data_rate;
int i;
u8 sym_rate_bytes[3];
dprintk("%s : srate = %i\n", __func__ , srate);
if ((srate < 1000000) || (srate > 45000000))
return -EINVAL;
data_rate = srate;
sym_rate = 0;
for (i = 0; i < 4; ++i) {
sym_rate /= 100;
sym_rate = sym_rate + ((data_rate % 100) * 0x800000) /
state->fs;
data_rate /= 100;
}
for (i = 0; i < 3; ++i)
sym_rate_bytes[i] = (u8)((sym_rate >> (i * 8)) & 0xff);
si21_writeregs(state, SYM_RATE_REG_L, sym_rate_bytes, 0x03);
return 0;
}
static int si21xx_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *m)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 lnb_status;
u8 LNB_CTRL_1;
int status;
dprintk("%s\n", __func__);
status = PASS;
LNB_CTRL_1 = 0;
status |= si21_readregs(state, LNB_CTRL_STATUS_REG, &lnb_status, 0x01);
status |= si21_readregs(state, LNB_CTRL_REG_1, &lnb_status, 0x01);
status |= si21_writeregs(state, LNB_FIFO_REGS_0, m->msg, m->msg_len);
LNB_CTRL_1 = (lnb_status & 0x70);
LNB_CTRL_1 |= m->msg_len;
LNB_CTRL_1 |= 0x80;
status |= si21_writeregs(state, LNB_CTRL_REG_1, &LNB_CTRL_1, 0x01);
return status;
}
static int si21xx_send_diseqc_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 val;
dprintk("%s\n", __func__);
if (si21xx_wait_diseqc_idle(state, 100) < 0)
return -ETIMEDOUT;
val = (0x80 | si21_readreg(state, 0xc1));
if (si21_writereg(state, LNB_CTRL_REG_1,
burst == SEC_MINI_A ? (val & ~0x10) : (val | 0x10)))
return -EREMOTEIO;
if (si21xx_wait_diseqc_idle(state, 100) < 0)
return -ETIMEDOUT;
if (si21_writereg(state, LNB_CTRL_REG_1, val))
return -EREMOTEIO;
return 0;
}
static int si21xx_set_tone(struct dvb_frontend *fe, fe_sec_tone_mode_t tone)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 val;
dprintk("%s\n", __func__);
val = (0x80 | si21_readreg(state, LNB_CTRL_REG_1));
switch (tone) {
case SEC_TONE_ON:
return si21_writereg(state, LNB_CTRL_REG_1, val | 0x20);
case SEC_TONE_OFF:
return si21_writereg(state, LNB_CTRL_REG_1, (val & ~0x20));
default:
return -EINVAL;
}
}
static int si21xx_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t volt)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 val;
dprintk("%s: %s\n", __func__,
volt == SEC_VOLTAGE_13 ? "SEC_VOLTAGE_13" :
volt == SEC_VOLTAGE_18 ? "SEC_VOLTAGE_18" : "??");
val = (0x80 | si21_readreg(state, LNB_CTRL_REG_1));
switch (volt) {
case SEC_VOLTAGE_18:
return si21_writereg(state, LNB_CTRL_REG_1, val | 0x40);
break;
case SEC_VOLTAGE_13:
return si21_writereg(state, LNB_CTRL_REG_1, (val & ~0x40));
break;
default:
return -EINVAL;
};
}
static int si21xx_init(struct dvb_frontend *fe)
{
struct si21xx_state *state = fe->demodulator_priv;
int i;
int status = 0;
u8 reg1;
u8 val;
u8 reg2[2];
dprintk("%s\n", __func__);
for (i = 0; ; i += 2) {
reg1 = serit_sp1511lhb_inittab[i];
val = serit_sp1511lhb_inittab[i+1];
if (reg1 == 0xff && val == 0xff)
break;
si21_writeregs(state, reg1, &val, 1);
}
reg1 = 0x08;
si21_writeregs(state, SYSTEM_MODE_REG, &reg1, 0x01);
reg2[0] =
PARALLEL + (LSB_FIRST << 1)
+ (FALLING_EDGE << 2) + (CLK_GAPPED_MODE << 3)
+ (BYTE_WIDE << 4) + (ACTIVE_HIGH << 5)
+ (ACTIVE_HIGH << 6) + (ACTIVE_HIGH << 7);
reg2[1] = 0;
status |= si21_writeregs(state, TS_CTRL_REG_1, reg2, 0x02);
if (status != 0)
dprintk(" %s : TS Set Error\n", __func__);
return 0;
}
static int si21_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 regs_read[2];
u8 reg_read;
u8 i;
u8 lock;
u8 signal = si21_readreg(state, ANALOG_AGC_POWER_LEVEL_REG);
si21_readregs(state, LOCK_STATUS_REG_1, regs_read, 0x02);
reg_read = 0;
for (i = 0; i < 7; ++i)
reg_read |= ((regs_read[0] >> i) & 0x01) << (6 - i);
lock = ((reg_read & 0x7f) | (regs_read[1] & 0x80));
dprintk("%s : FE_READ_STATUS : VSTATUS: 0x%02x\n", __func__, lock);
*status = 0;
if (signal > 10)
*status |= FE_HAS_SIGNAL;
if (lock & 0x2)
*status |= FE_HAS_CARRIER;
if (lock & 0x20)
*status |= FE_HAS_VITERBI;
if (lock & 0x40)
*status |= FE_HAS_SYNC;
if ((lock & 0x7b) == 0x7b)
*status |= FE_HAS_LOCK;
return 0;
}
static int si21_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct si21xx_state *state = fe->demodulator_priv;
u16 signal = (3 * si21_readreg(state, 0x27) *
si21_readreg(state, 0x28));
dprintk("%s : AGCPWR: 0x%02x%02x, signal=0x%04x\n", __func__,
si21_readreg(state, 0x27),
si21_readreg(state, 0x28), (int) signal);
signal <<= 4;
*strength = signal;
return 0;
}
static int si21_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct si21xx_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
if (state->errmode != STATUS_BER)
return 0;
*ber = (si21_readreg(state, 0x1d) << 8) |
si21_readreg(state, 0x1e);
return 0;
}
static int si21_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct si21xx_state *state = fe->demodulator_priv;
s32 xsnr = 0xffff - ((si21_readreg(state, 0x24) << 8) |
si21_readreg(state, 0x25));
xsnr = 3 * (xsnr - 0xa100);
*snr = (xsnr > 0xffff) ? 0xffff : (xsnr < 0) ? 0 : xsnr;
dprintk("%s\n", __func__);
return 0;
}
static int si21_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct si21xx_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
if (state->errmode != STATUS_UCBLOCKS)
*ucblocks = 0;
else
*ucblocks = (si21_readreg(state, 0x1d) << 8) |
si21_readreg(state, 0x1e);
return 0;
}
static int si21xx_setacquire(struct dvb_frontend *fe, int symbrate,
fe_code_rate_t crate)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 coderates[] = {
0x0, 0x01, 0x02, 0x04, 0x00,
0x8, 0x10, 0x20, 0x00, 0x3f
};
u8 coderate_ptr;
int status;
u8 start_acq = 0x80;
u8 reg, regs[3];
dprintk("%s\n", __func__);
status = PASS;
coderate_ptr = coderates[crate];
si21xx_set_symbolrate(fe, symbrate);
status |= si21_writeregs(state,
VIT_SRCH_CTRL_REG_1,
&coderate_ptr, 0x01);
status |= si21_readregs(state, ACQ_CTRL_REG_2, &reg, 0x01);
reg &= ~start_acq;
status |= si21_writeregs(state, ACQ_CTRL_REG_2, &reg, 0x01);
regs[0] = 0xCB;
regs[1] = 0x40;
regs[2] = 0xCB;
status |= si21_writeregs(state,
TWO_DB_BNDWDTH_THRSHLD_REG,
&regs[0], 0x03);
reg = 0x56;
status |= si21_writeregs(state,
LSA_CTRL_REG_1, &reg, 1);
reg = 0x05;
status |= si21_writeregs(state,
BLIND_SCAN_CTRL_REG, &reg, 1);
status |= si21_writeregs(state,
ACQ_CTRL_REG_2, &start_acq, 0x01);
return status;
}
static int si21xx_set_frontend(struct dvb_frontend *fe)
{
struct si21xx_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
unsigned char coarse_tune_freq;
int fine_tune_freq;
unsigned char sample_rate = 0;
bool inband_interferer_ind;
int icoarse_tune_freq;
int ifine_tune_freq;
unsigned int band_high;
unsigned int band_low;
unsigned int x1;
unsigned int x2;
int i;
bool inband_interferer_div2[ALLOWABLE_FS_COUNT];
bool inband_interferer_div4[ALLOWABLE_FS_COUNT];
int status;
int afs[ALLOWABLE_FS_COUNT] = { 200, 192, 193, 194, 195,
196, 204, 205, 206, 207
};
int if_limit_high;
int if_limit_low;
int lnb_lo;
int lnb_uncertanity;
int rf_freq;
int data_rate;
unsigned char regs[4];
dprintk("%s : FE_SET_FRONTEND\n", __func__);
if (c->delivery_system != SYS_DVBS) {
dprintk("%s: unsupported delivery system selected (%d)\n",
__func__, c->delivery_system);
return -EOPNOTSUPP;
}
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i)
inband_interferer_div2[i] = inband_interferer_div4[i] = false;
if_limit_high = -700000;
if_limit_low = -100000;
lnb_lo = 0;
lnb_uncertanity = 0;
rf_freq = 10 * c->frequency ;
data_rate = c->symbol_rate / 100;
status = PASS;
band_low = (rf_freq - lnb_lo) - ((lnb_uncertanity * 200)
+ (data_rate * 135)) / 200;
band_high = (rf_freq - lnb_lo) + ((lnb_uncertanity * 200)
+ (data_rate * 135)) / 200;
icoarse_tune_freq = 100000 *
(((rf_freq - lnb_lo) -
(if_limit_low + if_limit_high) / 2)
/ 100000);
ifine_tune_freq = (rf_freq - lnb_lo) - icoarse_tune_freq ;
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i) {
x1 = ((rf_freq - lnb_lo) / (afs[i] * 2500)) *
(afs[i] * 2500) + afs[i] * 2500;
x2 = ((rf_freq - lnb_lo) / (afs[i] * 2500)) *
(afs[i] * 2500);
if (((band_low < x1) && (x1 < band_high)) ||
((band_low < x2) && (x2 < band_high)))
inband_interferer_div4[i] = true;
}
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i) {
x1 = ((rf_freq - lnb_lo) / (afs[i] * 5000)) *
(afs[i] * 5000) + afs[i] * 5000;
x2 = ((rf_freq - lnb_lo) / (afs[i] * 5000)) *
(afs[i] * 5000);
if (((band_low < x1) && (x1 < band_high)) ||
((band_low < x2) && (x2 < band_high)))
inband_interferer_div2[i] = true;
}
inband_interferer_ind = true;
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i) {
if (inband_interferer_div2[i] || inband_interferer_div4[i]) {
inband_interferer_ind = false;
break;
}
}
if (inband_interferer_ind) {
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i) {
if (!inband_interferer_div2[i]) {
sample_rate = (u8) afs[i];
break;
}
}
} else {
for (i = 0; i < ALLOWABLE_FS_COUNT; ++i) {
if ((inband_interferer_div2[i] ||
!inband_interferer_div4[i])) {
sample_rate = (u8) afs[i];
break;
}
}
}
if (sample_rate > 207 || sample_rate < 192)
sample_rate = 200;
fine_tune_freq = ((0x4000 * (ifine_tune_freq / 10)) /
((sample_rate) * 1000));
coarse_tune_freq = (u8)(icoarse_tune_freq / 100000);
regs[0] = sample_rate;
regs[1] = coarse_tune_freq;
regs[2] = fine_tune_freq & 0xFF;
regs[3] = fine_tune_freq >> 8 & 0xFF;
status |= si21_writeregs(state, PLL_DIVISOR_REG, &regs[0], 0x04);
state->fs = sample_rate;
si21xx_setacquire(fe, c->symbol_rate, c->fec_inner);
return 0;
}
static int si21xx_sleep(struct dvb_frontend *fe)
{
struct si21xx_state *state = fe->demodulator_priv;
u8 regdata;
dprintk("%s\n", __func__);
si21_readregs(state, SYSTEM_MODE_REG, &regdata, 0x01);
regdata |= 1 << 6;
si21_writeregs(state, SYSTEM_MODE_REG, &regdata, 0x01);
state->initialised = 0;
return 0;
}
static void si21xx_release(struct dvb_frontend *fe)
{
struct si21xx_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
kfree(state);
}
struct dvb_frontend *si21xx_attach(const struct si21xx_config *config,
struct i2c_adapter *i2c)
{
struct si21xx_state *state = NULL;
int id;
dprintk("%s\n", __func__);
state = kzalloc(sizeof(struct si21xx_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->initialised = 0;
state->errmode = STATUS_BER;
id = si21_readreg(state, SYSTEM_MODE_REG);
si21_writereg(state, SYSTEM_MODE_REG, id | 0x40);
msleep(200);
id = si21_readreg(state, 0x00);
if (id != 0x04 && id != 0x14)
goto error;
memcpy(&state->frontend.ops, &si21xx_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
