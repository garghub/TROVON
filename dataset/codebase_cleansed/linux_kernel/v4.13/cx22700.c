static int cx22700_writereg (struct cx22700_state* state, u8 reg, u8 data)
{
int ret;
u8 buf [] = { reg, data };
struct i2c_msg msg = { .addr = state->config->demod_address, .flags = 0, .buf = buf, .len = 2 };
dprintk ("%s\n", __func__);
ret = i2c_transfer (state->i2c, &msg, 1);
if (ret != 1)
printk("%s: writereg error (reg == 0x%02x, val == 0x%02x, ret == %i)\n",
__func__, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static int cx22700_readreg (struct cx22700_state* state, u8 reg)
{
int ret;
u8 b0 [] = { reg };
u8 b1 [] = { 0 };
struct i2c_msg msg [] = { { .addr = state->config->demod_address, .flags = 0, .buf = b0, .len = 1 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD, .buf = b1, .len = 1 } };
dprintk ("%s\n", __func__);
ret = i2c_transfer (state->i2c, msg, 2);
if (ret != 2) return -EIO;
return b1[0];
}
static int cx22700_set_inversion (struct cx22700_state* state, int inversion)
{
u8 val;
dprintk ("%s\n", __func__);
switch (inversion) {
case INVERSION_AUTO:
return -EOPNOTSUPP;
case INVERSION_ON:
val = cx22700_readreg (state, 0x09);
return cx22700_writereg (state, 0x09, val | 0x01);
case INVERSION_OFF:
val = cx22700_readreg (state, 0x09);
return cx22700_writereg (state, 0x09, val & 0xfe);
default:
return -EINVAL;
}
}
static int cx22700_set_tps(struct cx22700_state *state,
struct dtv_frontend_properties *p)
{
static const u8 qam_tab [4] = { 0, 1, 0, 2 };
static const u8 fec_tab [6] = { 0, 1, 2, 0, 3, 4 };
u8 val;
dprintk ("%s\n", __func__);
if (p->code_rate_HP < FEC_1_2 || p->code_rate_HP > FEC_7_8)
return -EINVAL;
if (p->code_rate_LP < FEC_1_2 || p->code_rate_LP > FEC_7_8)
return -EINVAL;
if (p->code_rate_HP == FEC_4_5 || p->code_rate_LP == FEC_4_5)
return -EINVAL;
if ((int)p->guard_interval < GUARD_INTERVAL_1_32 ||
p->guard_interval > GUARD_INTERVAL_1_4)
return -EINVAL;
if (p->transmission_mode != TRANSMISSION_MODE_2K &&
p->transmission_mode != TRANSMISSION_MODE_8K)
return -EINVAL;
if (p->modulation != QPSK &&
p->modulation != QAM_16 &&
p->modulation != QAM_64)
return -EINVAL;
if ((int)p->hierarchy < HIERARCHY_NONE ||
p->hierarchy > HIERARCHY_4)
return -EINVAL;
if (p->bandwidth_hz > 8000000 || p->bandwidth_hz < 6000000)
return -EINVAL;
if (p->bandwidth_hz == 7000000)
cx22700_writereg (state, 0x09, cx22700_readreg (state, 0x09 | 0x10));
else
cx22700_writereg (state, 0x09, cx22700_readreg (state, 0x09 & ~0x10));
val = qam_tab[p->modulation - QPSK];
val |= p->hierarchy - HIERARCHY_NONE;
cx22700_writereg (state, 0x04, val);
if (p->code_rate_HP - FEC_1_2 >= sizeof(fec_tab) ||
p->code_rate_LP - FEC_1_2 >= sizeof(fec_tab))
return -EINVAL;
val = fec_tab[p->code_rate_HP - FEC_1_2] << 3;
val |= fec_tab[p->code_rate_LP - FEC_1_2];
cx22700_writereg (state, 0x05, val);
val = (p->guard_interval - GUARD_INTERVAL_1_32) << 2;
val |= p->transmission_mode - TRANSMISSION_MODE_2K;
cx22700_writereg (state, 0x06, val);
cx22700_writereg (state, 0x08, 0x04 | 0x02);
cx22700_writereg (state, 0x08, 0x04);
return 0;
}
static int cx22700_get_tps(struct cx22700_state *state,
struct dtv_frontend_properties *p)
{
static const enum fe_modulation qam_tab[3] = { QPSK, QAM_16, QAM_64 };
static const enum fe_code_rate fec_tab[5] = {
FEC_1_2, FEC_2_3, FEC_3_4, FEC_5_6, FEC_7_8
};
u8 val;
dprintk ("%s\n", __func__);
if (!(cx22700_readreg(state, 0x07) & 0x20))
return -EAGAIN;
val = cx22700_readreg (state, 0x01);
if ((val & 0x7) > 4)
p->hierarchy = HIERARCHY_AUTO;
else
p->hierarchy = HIERARCHY_NONE + (val & 0x7);
if (((val >> 3) & 0x3) > 2)
p->modulation = QAM_AUTO;
else
p->modulation = qam_tab[(val >> 3) & 0x3];
val = cx22700_readreg (state, 0x02);
if (((val >> 3) & 0x07) > 4)
p->code_rate_HP = FEC_AUTO;
else
p->code_rate_HP = fec_tab[(val >> 3) & 0x07];
if ((val & 0x07) > 4)
p->code_rate_LP = FEC_AUTO;
else
p->code_rate_LP = fec_tab[val & 0x07];
val = cx22700_readreg (state, 0x03);
p->guard_interval = GUARD_INTERVAL_1_32 + ((val >> 6) & 0x3);
p->transmission_mode = TRANSMISSION_MODE_2K + ((val >> 5) & 0x1);
return 0;
}
static int cx22700_init (struct dvb_frontend* fe)
{ struct cx22700_state* state = fe->demodulator_priv;
int i;
dprintk("cx22700_init: init chip\n");
cx22700_writereg (state, 0x00, 0x02);
cx22700_writereg (state, 0x00, 0x00);
msleep(10);
for (i=0; i<sizeof(init_tab); i+=2)
cx22700_writereg (state, init_tab[i], init_tab[i+1]);
cx22700_writereg (state, 0x00, 0x01);
return 0;
}
static int cx22700_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct cx22700_state* state = fe->demodulator_priv;
u16 rs_ber = (cx22700_readreg (state, 0x0d) << 9)
| (cx22700_readreg (state, 0x0e) << 1);
u8 sync = cx22700_readreg (state, 0x07);
*status = 0;
if (rs_ber < 0xff00)
*status |= FE_HAS_SIGNAL;
if (sync & 0x20)
*status |= FE_HAS_CARRIER;
if (sync & 0x10)
*status |= FE_HAS_VITERBI;
if (sync & 0x10)
*status |= FE_HAS_SYNC;
if (*status == 0x0f)
*status |= FE_HAS_LOCK;
return 0;
}
static int cx22700_read_ber(struct dvb_frontend* fe, u32* ber)
{
struct cx22700_state* state = fe->demodulator_priv;
*ber = cx22700_readreg (state, 0x0c) & 0x7f;
cx22700_writereg (state, 0x0c, 0x00);
return 0;
}
static int cx22700_read_signal_strength(struct dvb_frontend* fe, u16* signal_strength)
{
struct cx22700_state* state = fe->demodulator_priv;
u16 rs_ber = (cx22700_readreg (state, 0x0d) << 9)
| (cx22700_readreg (state, 0x0e) << 1);
*signal_strength = ~rs_ber;
return 0;
}
static int cx22700_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct cx22700_state* state = fe->demodulator_priv;
u16 rs_ber = (cx22700_readreg (state, 0x0d) << 9)
| (cx22700_readreg (state, 0x0e) << 1);
*snr = ~rs_ber;
return 0;
}
static int cx22700_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
struct cx22700_state* state = fe->demodulator_priv;
*ucblocks = cx22700_readreg (state, 0x0f);
cx22700_writereg (state, 0x0f, 0x00);
return 0;
}
static int cx22700_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx22700_state* state = fe->demodulator_priv;
cx22700_writereg (state, 0x00, 0x02);
cx22700_writereg (state, 0x00, 0x00);
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
cx22700_set_inversion(state, c->inversion);
cx22700_set_tps(state, c);
cx22700_writereg (state, 0x37, 0x01);
cx22700_writereg (state, 0x00, 0x01);
return 0;
}
static int cx22700_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *c)
{
struct cx22700_state* state = fe->demodulator_priv;
u8 reg09 = cx22700_readreg (state, 0x09);
c->inversion = reg09 & 0x1 ? INVERSION_ON : INVERSION_OFF;
return cx22700_get_tps(state, c);
}
static int cx22700_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
struct cx22700_state* state = fe->demodulator_priv;
if (enable) {
return cx22700_writereg(state, 0x0a, 0x00);
} else {
return cx22700_writereg(state, 0x0a, 0x01);
}
}
static int cx22700_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings* fesettings)
{
fesettings->min_delay_ms = 150;
fesettings->step_size = 166667;
fesettings->max_drift = 166667*2;
return 0;
}
static void cx22700_release(struct dvb_frontend* fe)
{
struct cx22700_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* cx22700_attach(const struct cx22700_config* config,
struct i2c_adapter* i2c)
{
struct cx22700_state* state = NULL;
state = kzalloc(sizeof(struct cx22700_state), GFP_KERNEL);
if (state == NULL) goto error;
state->config = config;
state->i2c = i2c;
if (cx22700_readreg(state, 0x07) < 0) goto error;
memcpy(&state->frontend.ops, &cx22700_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
