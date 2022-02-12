static int s5h1409_writereg(struct s5h1409_state *state, u8 reg, u16 data)
{
int ret;
u8 buf[] = { reg, data >> 8, data & 0xff };
struct i2c_msg msg = { .addr = state->config->demod_address,
.flags = 0, .buf = buf, .len = 3 };
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
printk(KERN_ERR "%s: error (reg == 0x%02x, val == 0x%04x, "
"ret == %i)\n", __func__, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static u16 s5h1409_readreg(struct s5h1409_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0, 0 };
struct i2c_msg msg[] = {
{ .addr = state->config->demod_address, .flags = 0,
.buf = b0, .len = 1 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD,
.buf = b1, .len = 2 } };
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
printk("%s: readreg error (ret == %i)\n", __func__, ret);
return (b1[0] << 8) | b1[1];
}
static int s5h1409_softreset(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
s5h1409_writereg(state, 0xf5, 0);
s5h1409_writereg(state, 0xf5, 1);
state->is_qam_locked = 0;
state->qam_state = QAM_STATE_UNTUNED;
return 0;
}
static int s5h1409_set_if_freq(struct dvb_frontend *fe, int KHz)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(%d KHz)\n", __func__, KHz);
switch (KHz) {
case 4000:
s5h1409_writereg(state, 0x87, 0x014b);
s5h1409_writereg(state, 0x88, 0x0cb5);
s5h1409_writereg(state, 0x89, 0x03e2);
break;
case 5380:
case 44000:
default:
s5h1409_writereg(state, 0x87, 0x01be);
s5h1409_writereg(state, 0x88, 0x0436);
s5h1409_writereg(state, 0x89, 0x054d);
break;
}
state->if_freq = KHz;
return 0;
}
static int s5h1409_set_spectralinversion(struct dvb_frontend *fe, int inverted)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, inverted);
if (inverted == 1)
return s5h1409_writereg(state, 0x1b, 0x1101);
else
return s5h1409_writereg(state, 0x1b, 0x0110);
}
static int s5h1409_enable_modulation(struct dvb_frontend *fe,
fe_modulation_t m)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(0x%08x)\n", __func__, m);
switch (m) {
case VSB_8:
dprintk("%s() VSB_8\n", __func__);
if (state->if_freq != S5H1409_VSB_IF_FREQ)
s5h1409_set_if_freq(fe, S5H1409_VSB_IF_FREQ);
s5h1409_writereg(state, 0xf4, 0);
break;
case QAM_64:
case QAM_256:
case QAM_AUTO:
dprintk("%s() QAM_AUTO (64/256)\n", __func__);
if (state->if_freq != S5H1409_QAM_IF_FREQ)
s5h1409_set_if_freq(fe, S5H1409_QAM_IF_FREQ);
s5h1409_writereg(state, 0xf4, 1);
s5h1409_writereg(state, 0x85, 0x110);
break;
default:
dprintk("%s() Invalid modulation\n", __func__);
return -EINVAL;
}
state->current_modulation = m;
s5h1409_softreset(fe);
return 0;
}
static int s5h1409_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, enable);
if (enable)
return s5h1409_writereg(state, 0xf3, 1);
else
return s5h1409_writereg(state, 0xf3, 0);
}
static int s5h1409_set_gpio(struct dvb_frontend *fe, int enable)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, enable);
if (enable)
return s5h1409_writereg(state, 0xe3,
s5h1409_readreg(state, 0xe3) | 0x1100);
else
return s5h1409_writereg(state, 0xe3,
s5h1409_readreg(state, 0xe3) & 0xfeff);
}
static int s5h1409_sleep(struct dvb_frontend *fe, int enable)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, enable);
return s5h1409_writereg(state, 0xf2, enable);
}
static int s5h1409_register_reset(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
return s5h1409_writereg(state, 0xfa, 0);
}
static void s5h1409_set_qam_amhum_mode(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg;
if (state->qam_state < QAM_STATE_INTERLEAVE_SET) {
return;
}
if (state->qam_state == QAM_STATE_QAM_OPTIMIZED_L3) {
return;
}
reg = s5h1409_readreg(state, 0xf0);
if ((reg >> 13) & 0x1) {
reg &= 0xff;
s5h1409_writereg(state, 0x96, 0x000c);
if (reg < 0x68) {
if (state->qam_state < QAM_STATE_QAM_OPTIMIZED_L3) {
dprintk("%s() setting QAM state to OPT_L3\n",
__func__);
s5h1409_writereg(state, 0x93, 0x3130);
s5h1409_writereg(state, 0x9e, 0x2836);
state->qam_state = QAM_STATE_QAM_OPTIMIZED_L3;
}
} else {
if (state->qam_state < QAM_STATE_QAM_OPTIMIZED_L2) {
dprintk("%s() setting QAM state to OPT_L2\n",
__func__);
s5h1409_writereg(state, 0x93, 0x3332);
s5h1409_writereg(state, 0x9e, 0x2c37);
state->qam_state = QAM_STATE_QAM_OPTIMIZED_L2;
}
}
} else {
if (state->qam_state < QAM_STATE_QAM_OPTIMIZED_L1) {
dprintk("%s() setting QAM state to OPT_L1\n", __func__);
s5h1409_writereg(state, 0x96, 0x0008);
s5h1409_writereg(state, 0x93, 0x3332);
s5h1409_writereg(state, 0x9e, 0x2c37);
state->qam_state = QAM_STATE_QAM_OPTIMIZED_L1;
}
}
}
static void s5h1409_set_qam_amhum_mode_legacy(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg;
if (state->is_qam_locked)
return;
reg = s5h1409_readreg(state, 0xf0);
if ((reg >> 13) & 0x1) {
state->is_qam_locked = 1;
reg &= 0xff;
s5h1409_writereg(state, 0x96, 0x00c);
if ((reg < 0x38) || (reg > 0x68)) {
s5h1409_writereg(state, 0x93, 0x3332);
s5h1409_writereg(state, 0x9e, 0x2c37);
} else {
s5h1409_writereg(state, 0x93, 0x3130);
s5h1409_writereg(state, 0x9e, 0x2836);
}
} else {
s5h1409_writereg(state, 0x96, 0x0008);
s5h1409_writereg(state, 0x93, 0x3332);
s5h1409_writereg(state, 0x9e, 0x2c37);
}
}
static void s5h1409_set_qam_interleave_mode(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg, reg1, reg2;
if (state->qam_state >= QAM_STATE_INTERLEAVE_SET) {
return;
}
reg = s5h1409_readreg(state, 0xf1);
if ((reg >> 15) & 0x1) {
if (state->qam_state == QAM_STATE_UNTUNED ||
state->qam_state == QAM_STATE_TUNING_STARTED) {
dprintk("%s() setting QAM state to INTERLEAVE_SET\n",
__func__);
reg1 = s5h1409_readreg(state, 0xb2);
reg2 = s5h1409_readreg(state, 0xad);
s5h1409_writereg(state, 0x96, 0x0020);
s5h1409_writereg(state, 0xad,
(((reg1 & 0xf000) >> 4) | (reg2 & 0xf0ff)));
state->qam_state = QAM_STATE_INTERLEAVE_SET;
}
} else {
if (state->qam_state == QAM_STATE_UNTUNED) {
dprintk("%s() setting QAM state to TUNING_STARTED\n",
__func__);
s5h1409_writereg(state, 0x96, 0x08);
s5h1409_writereg(state, 0xab,
s5h1409_readreg(state, 0xab) | 0x1001);
state->qam_state = QAM_STATE_TUNING_STARTED;
}
}
}
static void s5h1409_set_qam_interleave_mode_legacy(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg, reg1, reg2;
reg = s5h1409_readreg(state, 0xf1);
if ((reg >> 15) & 0x1) {
if (state->qam_state != 2) {
state->qam_state = 2;
reg1 = s5h1409_readreg(state, 0xb2);
reg2 = s5h1409_readreg(state, 0xad);
s5h1409_writereg(state, 0x96, 0x20);
s5h1409_writereg(state, 0xad,
(((reg1 & 0xf000) >> 4) | (reg2 & 0xf0ff)));
s5h1409_writereg(state, 0xab,
s5h1409_readreg(state, 0xab) & 0xeffe);
}
} else {
if (state->qam_state != 1) {
state->qam_state = 1;
s5h1409_writereg(state, 0x96, 0x08);
s5h1409_writereg(state, 0xab,
s5h1409_readreg(state, 0xab) | 0x1001);
}
}
}
static int s5h1409_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s(frequency=%d)\n", __func__, p->frequency);
s5h1409_softreset(fe);
state->current_frequency = p->frequency;
s5h1409_enable_modulation(fe, p->u.vsb.modulation);
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe, p);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
s5h1409_softreset(fe);
if (state->current_modulation != VSB_8) {
if (state->config->hvr1600_opt == S5H1409_HVR1600_OPTIMIZE) {
s5h1409_set_qam_interleave_mode(fe);
s5h1409_set_qam_amhum_mode(fe);
} else {
s5h1409_set_qam_amhum_mode_legacy(fe);
s5h1409_set_qam_interleave_mode_legacy(fe);
}
}
return 0;
}
static int s5h1409_set_mpeg_timing(struct dvb_frontend *fe, int mode)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 val;
dprintk("%s(%d)\n", __func__, mode);
val = s5h1409_readreg(state, 0xac) & 0xcfff;
switch (mode) {
case S5H1409_MPEGTIMING_CONTINOUS_INVERTING_CLOCK:
val |= 0x0000;
break;
case S5H1409_MPEGTIMING_CONTINOUS_NONINVERTING_CLOCK:
dprintk("%s(%d) Mode1 or Defaulting\n", __func__, mode);
val |= 0x1000;
break;
case S5H1409_MPEGTIMING_NONCONTINOUS_INVERTING_CLOCK:
val |= 0x2000;
break;
case S5H1409_MPEGTIMING_NONCONTINOUS_NONINVERTING_CLOCK:
val |= 0x3000;
break;
default:
return -EINVAL;
}
return s5h1409_writereg(state, 0xac, val);
}
static int s5h1409_init(struct dvb_frontend *fe)
{
int i;
struct s5h1409_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
s5h1409_sleep(fe, 0);
s5h1409_register_reset(fe);
for (i = 0; i < ARRAY_SIZE(init_tab); i++)
s5h1409_writereg(state, init_tab[i].reg, init_tab[i].data);
state->current_modulation = VSB_8;
if (state->config->hvr1600_opt == S5H1409_HVR1600_OPTIMIZE) {
s5h1409_writereg(state, 0x09, 0x0050);
s5h1409_writereg(state, 0x21, 0x0001);
s5h1409_writereg(state, 0x50, 0x030e);
s5h1409_writereg(state, 0x82, 0x0800);
}
if (state->config->output_mode == S5H1409_SERIAL_OUTPUT)
s5h1409_writereg(state, 0xab,
s5h1409_readreg(state, 0xab) | 0x100);
else
s5h1409_writereg(state, 0xab,
s5h1409_readreg(state, 0xab) & 0xfeff);
s5h1409_set_spectralinversion(fe, state->config->inversion);
s5h1409_set_if_freq(fe, state->if_freq);
s5h1409_set_gpio(fe, state->config->gpio);
s5h1409_set_mpeg_timing(fe, state->config->mpeg_timing);
s5h1409_softreset(fe);
s5h1409_i2c_gate_ctrl(fe, 0);
return 0;
}
static int s5h1409_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg;
u32 tuner_status = 0;
*status = 0;
if (state->current_modulation != VSB_8) {
if (state->config->hvr1600_opt == S5H1409_HVR1600_OPTIMIZE) {
s5h1409_set_qam_interleave_mode(fe);
s5h1409_set_qam_amhum_mode(fe);
}
}
reg = s5h1409_readreg(state, 0xf1);
if (reg & 0x1000)
*status |= FE_HAS_VITERBI;
if (reg & 0x8000)
*status |= FE_HAS_LOCK | FE_HAS_SYNC;
switch (state->config->status_mode) {
case S5H1409_DEMODLOCKING:
if (*status & FE_HAS_VITERBI)
*status |= FE_HAS_CARRIER | FE_HAS_SIGNAL;
break;
case S5H1409_TUNERLOCKING:
if (fe->ops.tuner_ops.get_status) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.get_status(fe, &tuner_status);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
if (tuner_status)
*status |= FE_HAS_CARRIER | FE_HAS_SIGNAL;
break;
}
dprintk("%s() status 0x%08x\n", __func__, *status);
return 0;
}
static int s5h1409_qam256_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
{
int i, ret = -EINVAL;
dprintk("%s()\n", __func__);
for (i = 0; i < ARRAY_SIZE(qam256_snr_tab); i++) {
if (v < qam256_snr_tab[i].val) {
*snr = qam256_snr_tab[i].data;
ret = 0;
break;
}
}
return ret;
}
static int s5h1409_qam64_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
{
int i, ret = -EINVAL;
dprintk("%s()\n", __func__);
for (i = 0; i < ARRAY_SIZE(qam64_snr_tab); i++) {
if (v < qam64_snr_tab[i].val) {
*snr = qam64_snr_tab[i].data;
ret = 0;
break;
}
}
return ret;
}
static int s5h1409_vsb_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
{
int i, ret = -EINVAL;
dprintk("%s()\n", __func__);
for (i = 0; i < ARRAY_SIZE(vsb_snr_tab); i++) {
if (v > vsb_snr_tab[i].val) {
*snr = vsb_snr_tab[i].data;
ret = 0;
break;
}
}
dprintk("%s() snr=%d\n", __func__, *snr);
return ret;
}
static int s5h1409_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct s5h1409_state *state = fe->demodulator_priv;
u16 reg;
dprintk("%s()\n", __func__);
switch (state->current_modulation) {
case QAM_64:
reg = s5h1409_readreg(state, 0xf0) & 0xff;
return s5h1409_qam64_lookup_snr(fe, snr, reg);
case QAM_256:
reg = s5h1409_readreg(state, 0xf0) & 0xff;
return s5h1409_qam256_lookup_snr(fe, snr, reg);
case VSB_8:
reg = s5h1409_readreg(state, 0xf1) & 0x3ff;
return s5h1409_vsb_lookup_snr(fe, snr, reg);
default:
break;
}
return -EINVAL;
}
static int s5h1409_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
return s5h1409_read_snr(fe, signal_strength);
}
static int s5h1409_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct s5h1409_state *state = fe->demodulator_priv;
*ucblocks = s5h1409_readreg(state, 0xb5);
return 0;
}
static int s5h1409_read_ber(struct dvb_frontend *fe, u32 *ber)
{
return s5h1409_read_ucblocks(fe, ber);
}
static int s5h1409_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct s5h1409_state *state = fe->demodulator_priv;
p->frequency = state->current_frequency;
p->u.vsb.modulation = state->current_modulation;
return 0;
}
static int s5h1409_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void s5h1409_release(struct dvb_frontend *fe)
{
struct s5h1409_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *s5h1409_attach(const struct s5h1409_config *config,
struct i2c_adapter *i2c)
{
struct s5h1409_state *state = NULL;
u16 reg;
state = kzalloc(sizeof(struct s5h1409_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->current_modulation = 0;
state->if_freq = S5H1409_VSB_IF_FREQ;
reg = s5h1409_readreg(state, 0x04);
if ((reg != 0x0066) && (reg != 0x007f))
goto error;
memcpy(&state->frontend.ops, &s5h1409_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
if (s5h1409_init(&state->frontend) != 0) {
printk(KERN_ERR "%s: Failed to initialize correctly\n",
__func__);
goto error;
}
s5h1409_i2c_gate_ctrl(&state->frontend, 1);
return &state->frontend;
error:
kfree(state);
return NULL;
}
