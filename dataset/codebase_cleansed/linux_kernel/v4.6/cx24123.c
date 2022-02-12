static int cx24123_i2c_writereg(struct cx24123_state *state,
u8 i2c_addr, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = i2c_addr, .flags = 0, .buf = buf, .len = 2
};
int err;
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1) {
printk("%s: writereg error(err == %i, reg == 0x%02x,"
" data == 0x%02x)\n", __func__, err, reg, data);
return err;
}
return 0;
}
static int cx24123_i2c_readreg(struct cx24123_state *state, u8 i2c_addr, u8 reg)
{
int ret;
u8 b = 0;
struct i2c_msg msg[] = {
{ .addr = i2c_addr, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = i2c_addr, .flags = I2C_M_RD, .buf = &b, .len = 1 }
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
err("%s: reg=0x%x (error=%d)\n", __func__, reg, ret);
return ret;
}
return b;
}
static int cx24123_set_inversion(struct cx24123_state *state,
enum fe_spectral_inversion inversion)
{
u8 nom_reg = cx24123_readreg(state, 0x0e);
u8 auto_reg = cx24123_readreg(state, 0x10);
switch (inversion) {
case INVERSION_OFF:
dprintk("inversion off\n");
cx24123_writereg(state, 0x0e, nom_reg & ~0x80);
cx24123_writereg(state, 0x10, auto_reg | 0x80);
break;
case INVERSION_ON:
dprintk("inversion on\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x80);
cx24123_writereg(state, 0x10, auto_reg | 0x80);
break;
case INVERSION_AUTO:
dprintk("inversion auto\n");
cx24123_writereg(state, 0x10, auto_reg & ~0x80);
break;
default:
return -EINVAL;
}
return 0;
}
static int cx24123_get_inversion(struct cx24123_state *state,
enum fe_spectral_inversion *inversion)
{
u8 val;
val = cx24123_readreg(state, 0x1b) >> 7;
if (val == 0) {
dprintk("read inversion off\n");
*inversion = INVERSION_OFF;
} else {
dprintk("read inversion on\n");
*inversion = INVERSION_ON;
}
return 0;
}
static int cx24123_set_fec(struct cx24123_state *state, enum fe_code_rate fec)
{
u8 nom_reg = cx24123_readreg(state, 0x0e) & ~0x07;
if (((int)fec < FEC_NONE) || (fec > FEC_AUTO))
fec = FEC_AUTO;
if (fec == FEC_1_2)
cx24123_writereg(state, 0x43,
cx24123_readreg(state, 0x43) | 0x01);
else
cx24123_writereg(state, 0x43,
cx24123_readreg(state, 0x43) & ~0x01);
switch (fec) {
case FEC_1_2:
dprintk("set FEC to 1/2\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x01);
cx24123_writereg(state, 0x0f, 0x02);
break;
case FEC_2_3:
dprintk("set FEC to 2/3\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x02);
cx24123_writereg(state, 0x0f, 0x04);
break;
case FEC_3_4:
dprintk("set FEC to 3/4\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x03);
cx24123_writereg(state, 0x0f, 0x08);
break;
case FEC_4_5:
dprintk("set FEC to 4/5\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x04);
cx24123_writereg(state, 0x0f, 0x10);
break;
case FEC_5_6:
dprintk("set FEC to 5/6\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x05);
cx24123_writereg(state, 0x0f, 0x20);
break;
case FEC_6_7:
dprintk("set FEC to 6/7\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x06);
cx24123_writereg(state, 0x0f, 0x40);
break;
case FEC_7_8:
dprintk("set FEC to 7/8\n");
cx24123_writereg(state, 0x0e, nom_reg | 0x07);
cx24123_writereg(state, 0x0f, 0x80);
break;
case FEC_AUTO:
dprintk("set FEC to auto\n");
cx24123_writereg(state, 0x0f, 0xfe);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int cx24123_get_fec(struct cx24123_state *state, enum fe_code_rate *fec)
{
int ret;
ret = cx24123_readreg(state, 0x1b);
if (ret < 0)
return ret;
ret = ret & 0x07;
switch (ret) {
case 1:
*fec = FEC_1_2;
break;
case 2:
*fec = FEC_2_3;
break;
case 3:
*fec = FEC_3_4;
break;
case 4:
*fec = FEC_4_5;
break;
case 5:
*fec = FEC_5_6;
break;
case 6:
*fec = FEC_6_7;
break;
case 7:
*fec = FEC_7_8;
break;
default:
*fec = FEC_NONE;
}
return 0;
}
static u32 cx24123_int_log2(u32 a, u32 b)
{
u32 exp, nearest = 0;
u32 div = a / b;
if (a % b >= b / 2)
++div;
if (div < (1 << 31)) {
for (exp = 1; div > exp; nearest++)
exp += exp;
}
return nearest;
}
static int cx24123_set_symbolrate(struct cx24123_state *state, u32 srate)
{
u64 tmp;
u32 sample_rate, ratio, sample_gain;
u8 pll_mult;
if ((srate > state->frontend.ops.info.symbol_rate_max) ||
(srate < state->frontend.ops.info.symbol_rate_min))
return -EOPNOTSUPP;
if (srate < (XTAL*2)/2)
pll_mult = 2;
else if (srate < (XTAL*3)/2)
pll_mult = 3;
else if (srate < (XTAL*4)/2)
pll_mult = 4;
else if (srate < (XTAL*5)/2)
pll_mult = 5;
else if (srate < (XTAL*6)/2)
pll_mult = 6;
else if (srate < (XTAL*7)/2)
pll_mult = 7;
else if (srate < (XTAL*8)/2)
pll_mult = 8;
else
pll_mult = 9;
sample_rate = pll_mult * XTAL;
tmp = ((u64)srate) << 23;
do_div(tmp, sample_rate);
ratio = (u32) tmp;
cx24123_writereg(state, 0x01, pll_mult * 6);
cx24123_writereg(state, 0x08, (ratio >> 16) & 0x3f);
cx24123_writereg(state, 0x09, (ratio >> 8) & 0xff);
cx24123_writereg(state, 0x0a, ratio & 0xff);
sample_gain = cx24123_int_log2(sample_rate, srate);
tmp = cx24123_readreg(state, 0x0c) & ~0xe0;
cx24123_writereg(state, 0x0c, tmp | sample_gain << 5);
dprintk("srate=%d, ratio=0x%08x, sample_rate=%i sample_gain=%d\n",
srate, ratio, sample_rate, sample_gain);
return 0;
}
static int cx24123_pll_calculate(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct cx24123_state *state = fe->demodulator_priv;
u32 ndiv = 0, adiv = 0, vco_div = 0;
int i = 0;
int pump = 2;
int band = 0;
int num_bands = ARRAY_SIZE(cx24123_bandselect_vals);
struct cx24123_bandselect_val *bsv = NULL;
struct cx24123_AGC_val *agcv = NULL;
state->VCAarg = cx24123_AGC_vals[0].VCAprogdata;
state->VGAarg = cx24123_AGC_vals[0].VGAprogdata;
state->bandselectarg = cx24123_bandselect_vals[0].progdata;
vco_div = cx24123_bandselect_vals[0].VCOdivider;
for (i = 0; i < ARRAY_SIZE(cx24123_AGC_vals); i++) {
agcv = &cx24123_AGC_vals[i];
if ((agcv->symbolrate_low <= p->symbol_rate) &&
(agcv->symbolrate_high >= p->symbol_rate)) {
state->VCAarg = agcv->VCAprogdata;
state->VGAarg = agcv->VGAprogdata;
state->FILTune = agcv->FILTune;
}
}
if (force_band < 1 || force_band > num_bands) {
for (i = 0; i < num_bands; i++) {
bsv = &cx24123_bandselect_vals[i];
if ((bsv->freq_low <= p->frequency) &&
(bsv->freq_high >= p->frequency))
band = i;
}
} else
band = force_band - 1;
state->bandselectarg = cx24123_bandselect_vals[band].progdata;
vco_div = cx24123_bandselect_vals[band].VCOdivider;
if (p->frequency < (cx24123_bandselect_vals[band].freq_low +
cx24123_bandselect_vals[band].freq_high) / 2)
pump = 0x01;
else
pump = 0x02;
ndiv = (((p->frequency * vco_div * 10) /
(2 * XTAL / 1000)) / 32) & 0x1ff;
adiv = (((p->frequency * vco_div * 10) /
(2 * XTAL / 1000)) % 32) & 0x1f;
if (adiv == 0 && ndiv > 0)
ndiv--;
state->pllarg = (3 << 19) | (3 << 17) | (1 << 16) |
(pump << 14) | (ndiv << 5) | adiv;
return 0;
}
static int cx24123_pll_writereg(struct dvb_frontend *fe, u32 data)
{
struct cx24123_state *state = fe->demodulator_priv;
unsigned long timeout;
dprintk("pll writereg called, data=0x%08x\n", data);
data = data << 3;
cx24123_writereg(state, 0x21, 0x15);
timeout = jiffies + msecs_to_jiffies(40);
cx24123_writereg(state, 0x22, (data >> 16) & 0xff);
while ((cx24123_readreg(state, 0x20) & 0x40) == 0) {
if (time_after(jiffies, timeout)) {
err("%s: demodulator is not responding, "\
"possibly hung, aborting.\n", __func__);
return -EREMOTEIO;
}
msleep(10);
}
timeout = jiffies + msecs_to_jiffies(40);
cx24123_writereg(state, 0x22, (data >> 8) & 0xff);
while ((cx24123_readreg(state, 0x20) & 0x40) == 0) {
if (time_after(jiffies, timeout)) {
err("%s: demodulator is not responding, "\
"possibly hung, aborting.\n", __func__);
return -EREMOTEIO;
}
msleep(10);
}
timeout = jiffies + msecs_to_jiffies(40);
cx24123_writereg(state, 0x22, (data) & 0xff);
while ((cx24123_readreg(state, 0x20) & 0x80)) {
if (time_after(jiffies, timeout)) {
err("%s: demodulator is not responding," \
"possibly hung, aborting.\n", __func__);
return -EREMOTEIO;
}
msleep(10);
}
cx24123_writereg(state, 0x20, cx24123_readreg(state, 0x20) | 2);
cx24123_writereg(state, 0x20, cx24123_readreg(state, 0x20) & 0xfd);
return 0;
}
static int cx24123_pll_tune(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct cx24123_state *state = fe->demodulator_priv;
u8 val;
dprintk("frequency=%i\n", p->frequency);
if (cx24123_pll_calculate(fe) != 0) {
err("%s: cx24123_pll_calcutate failed\n", __func__);
return -EINVAL;
}
cx24123_pll_writereg(fe, state->VCAarg);
cx24123_pll_writereg(fe, state->VGAarg);
cx24123_pll_writereg(fe, state->bandselectarg);
cx24123_pll_writereg(fe, state->pllarg);
val = cx24123_readreg(state, 0x28) & ~0x3;
cx24123_writereg(state, 0x27, state->FILTune >> 2);
cx24123_writereg(state, 0x28, val | (state->FILTune & 0x3));
dprintk("pll tune VCA=%d, band=%d, pll=%d\n", state->VCAarg,
state->bandselectarg, state->pllarg);
return 0;
}
static int cx24123_repeater_mode(struct cx24123_state *state, u8 mode, u8 start)
{
u8 r = cx24123_readreg(state, 0x23) & 0x1e;
if (mode)
r |= (1 << 6) | (start << 5);
else
r |= (1 << 7) | (start);
return cx24123_writereg(state, 0x23, r);
}
static int cx24123_initfe(struct dvb_frontend *fe)
{
struct cx24123_state *state = fe->demodulator_priv;
int i;
dprintk("init frontend\n");
for (i = 0; i < ARRAY_SIZE(cx24123_regdata); i++)
cx24123_writereg(state, cx24123_regdata[i].reg,
cx24123_regdata[i].data);
if (state->config->lnb_polarity)
cx24123_writereg(state, 0x32,
cx24123_readreg(state, 0x32) | 0x02);
if (state->config->dont_use_pll)
cx24123_repeater_mode(state, 1, 0);
return 0;
}
static int cx24123_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx24123_state *state = fe->demodulator_priv;
u8 val;
val = cx24123_readreg(state, 0x29) & ~0x40;
switch (voltage) {
case SEC_VOLTAGE_13:
dprintk("setting voltage 13V\n");
return cx24123_writereg(state, 0x29, val & 0x7f);
case SEC_VOLTAGE_18:
dprintk("setting voltage 18V\n");
return cx24123_writereg(state, 0x29, val | 0x80);
case SEC_VOLTAGE_OFF:
return 0;
default:
return -EINVAL;
}
return 0;
}
static void cx24123_wait_for_diseqc(struct cx24123_state *state)
{
unsigned long timeout = jiffies + msecs_to_jiffies(200);
while (!(cx24123_readreg(state, 0x29) & 0x40)) {
if (time_after(jiffies, timeout)) {
err("%s: diseqc queue not ready, " \
"command may be lost.\n", __func__);
break;
}
msleep(10);
}
}
static int cx24123_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *cmd)
{
struct cx24123_state *state = fe->demodulator_priv;
int i, val, tone;
dprintk("\n");
tone = cx24123_readreg(state, 0x29);
if (tone & 0x10)
cx24123_writereg(state, 0x29, tone & ~0x50);
cx24123_wait_for_diseqc(state);
cx24123_writereg(state, 0x2a, cx24123_readreg(state, 0x2a) & 0xfb);
for (i = 0; i < cmd->msg_len; i++)
cx24123_writereg(state, 0x2C + i, cmd->msg[i]);
val = cx24123_readreg(state, 0x29);
cx24123_writereg(state, 0x29, ((val & 0x90) | 0x40) |
((cmd->msg_len-3) & 3));
cx24123_wait_for_diseqc(state);
if (tone & 0x10)
cx24123_writereg(state, 0x29, tone & ~0x40);
return 0;
}
static int cx24123_diseqc_send_burst(struct dvb_frontend *fe,
enum fe_sec_mini_cmd burst)
{
struct cx24123_state *state = fe->demodulator_priv;
int val, tone;
dprintk("\n");
tone = cx24123_readreg(state, 0x29);
if (tone & 0x10)
cx24123_writereg(state, 0x29, tone & ~0x50);
cx24123_wait_for_diseqc(state);
cx24123_writereg(state, 0x2a, cx24123_readreg(state, 0x2a) | 0x4);
msleep(30);
val = cx24123_readreg(state, 0x29);
if (burst == SEC_MINI_A)
cx24123_writereg(state, 0x29, ((val & 0x90) | 0x40 | 0x00));
else if (burst == SEC_MINI_B)
cx24123_writereg(state, 0x29, ((val & 0x90) | 0x40 | 0x08));
else
return -EINVAL;
cx24123_wait_for_diseqc(state);
cx24123_writereg(state, 0x2a, cx24123_readreg(state, 0x2a) & 0xfb);
if (tone & 0x10)
cx24123_writereg(state, 0x29, tone & ~0x40);
return 0;
}
static int cx24123_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct cx24123_state *state = fe->demodulator_priv;
int sync = cx24123_readreg(state, 0x14);
*status = 0;
if (state->config->dont_use_pll) {
u32 tun_status = 0;
if (fe->ops.tuner_ops.get_status)
fe->ops.tuner_ops.get_status(fe, &tun_status);
if (tun_status & TUNER_STATUS_LOCKED)
*status |= FE_HAS_SIGNAL;
} else {
int lock = cx24123_readreg(state, 0x20);
if (lock & 0x01)
*status |= FE_HAS_SIGNAL;
}
if (sync & 0x02)
*status |= FE_HAS_CARRIER;
if (sync & 0x04)
*status |= FE_HAS_VITERBI;
if (sync & 0x08)
*status |= FE_HAS_SYNC;
if (sync & 0x80)
*status |= FE_HAS_LOCK;
return 0;
}
static int cx24123_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct cx24123_state *state = fe->demodulator_priv;
*ber = ((cx24123_readreg(state, 0x1c) & 0x3f) << 16) |
(cx24123_readreg(state, 0x1d) << 8 |
cx24123_readreg(state, 0x1e));
dprintk("BER = %d\n", *ber);
return 0;
}
static int cx24123_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct cx24123_state *state = fe->demodulator_priv;
*signal_strength = cx24123_readreg(state, 0x3b) << 8;
dprintk("Signal strength = %d\n", *signal_strength);
return 0;
}
static int cx24123_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct cx24123_state *state = fe->demodulator_priv;
*snr = 65535 - (((u16)cx24123_readreg(state, 0x18) << 8) |
(u16)cx24123_readreg(state, 0x19));
dprintk("read S/N index = %d\n", *snr);
return 0;
}
static int cx24123_set_frontend(struct dvb_frontend *fe)
{
struct cx24123_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
dprintk("\n");
if (state->config->set_ts_params)
state->config->set_ts_params(fe, 0);
state->currentfreq = p->frequency;
state->currentsymbolrate = p->symbol_rate;
cx24123_set_inversion(state, p->inversion);
cx24123_set_fec(state, p->fec_inner);
cx24123_set_symbolrate(state, p->symbol_rate);
if (!state->config->dont_use_pll)
cx24123_pll_tune(fe);
else if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
else
err("it seems I don't have a tuner...");
cx24123_writereg(state, 0x03, (cx24123_readreg(state, 0x03) | 0x07));
cx24123_writereg(state, 0x00, 0x10);
cx24123_writereg(state, 0x00, 0);
if (state->config->agc_callback)
state->config->agc_callback(fe);
return 0;
}
static int cx24123_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *p)
{
struct cx24123_state *state = fe->demodulator_priv;
dprintk("\n");
if (cx24123_get_inversion(state, &p->inversion) != 0) {
err("%s: Failed to get inversion status\n", __func__);
return -EREMOTEIO;
}
if (cx24123_get_fec(state, &p->fec_inner) != 0) {
err("%s: Failed to get fec status\n", __func__);
return -EREMOTEIO;
}
p->frequency = state->currentfreq;
p->symbol_rate = state->currentsymbolrate;
return 0;
}
static int cx24123_set_tone(struct dvb_frontend *fe, enum fe_sec_tone_mode tone)
{
struct cx24123_state *state = fe->demodulator_priv;
u8 val;
cx24123_wait_for_diseqc(state);
val = cx24123_readreg(state, 0x29) & ~0x40;
switch (tone) {
case SEC_TONE_ON:
dprintk("setting tone on\n");
return cx24123_writereg(state, 0x29, val | 0x10);
case SEC_TONE_OFF:
dprintk("setting tone off\n");
return cx24123_writereg(state, 0x29, val & 0xef);
default:
err("CASE reached default with tone=%d\n", tone);
return -EINVAL;
}
return 0;
}
static int cx24123_tune(struct dvb_frontend *fe,
bool re_tune,
unsigned int mode_flags,
unsigned int *delay,
enum fe_status *status)
{
int retval = 0;
if (re_tune)
retval = cx24123_set_frontend(fe);
if (!(mode_flags & FE_TUNE_MODE_ONESHOT))
cx24123_read_status(fe, status);
*delay = HZ/10;
return retval;
}
static int cx24123_get_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
static void cx24123_release(struct dvb_frontend *fe)
{
struct cx24123_state *state = fe->demodulator_priv;
dprintk("\n");
i2c_del_adapter(&state->tuner_i2c_adapter);
kfree(state);
}
static int cx24123_tuner_i2c_tuner_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
struct cx24123_state *state = i2c_get_adapdata(i2c_adap);
cx24123_repeater_mode(state, 1, 1);
return i2c_transfer(state->i2c, msg, num);
}
static u32 cx24123_tuner_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
struct i2c_adapter *
cx24123_get_tuner_i2c_adapter(struct dvb_frontend *fe)
{
struct cx24123_state *state = fe->demodulator_priv;
return &state->tuner_i2c_adapter;
}
struct dvb_frontend *cx24123_attach(const struct cx24123_config *config,
struct i2c_adapter *i2c)
{
struct cx24123_state *state =
kzalloc(sizeof(struct cx24123_state), GFP_KERNEL);
dprintk("\n");
if (state == NULL) {
err("Unable to kzalloc\n");
goto error;
}
state->config = config;
state->i2c = i2c;
state->demod_rev = cx24123_readreg(state, 0x00);
switch (state->demod_rev) {
case 0xe1:
info("detected CX24123C\n");
break;
case 0xd1:
info("detected CX24123\n");
break;
default:
err("wrong demod revision: %x\n", state->demod_rev);
goto error;
}
memcpy(&state->frontend.ops, &cx24123_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
if (config->dont_use_pll)
cx24123_repeater_mode(state, 1, 0);
strlcpy(state->tuner_i2c_adapter.name, "CX24123 tuner I2C bus",
sizeof(state->tuner_i2c_adapter.name));
state->tuner_i2c_adapter.algo = &cx24123_tuner_i2c_algo;
state->tuner_i2c_adapter.algo_data = NULL;
state->tuner_i2c_adapter.dev.parent = i2c->dev.parent;
i2c_set_adapdata(&state->tuner_i2c_adapter, state);
if (i2c_add_adapter(&state->tuner_i2c_adapter) < 0) {
err("tuner i2c bus could not be initialized\n");
goto error;
}
return &state->frontend;
error:
kfree(state);
return NULL;
}
