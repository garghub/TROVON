static int s5h1411_writereg(struct s5h1411_state *state,
u8 addr, u8 reg, u16 data)
{
int ret;
u8 buf[] = { reg, data >> 8, data & 0xff };
struct i2c_msg msg = { .addr = addr, .flags = 0, .buf = buf, .len = 3 };
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
printk(KERN_ERR "%s: writereg error 0x%02x 0x%02x 0x%04x, ret == %i)\n",
__func__, addr, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static u16 s5h1411_readreg(struct s5h1411_state *state, u8 addr, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0, 0 };
struct i2c_msg msg[] = {
{ .addr = addr, .flags = 0, .buf = b0, .len = 1 },
{ .addr = addr, .flags = I2C_M_RD, .buf = b1, .len = 2 } };
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
printk(KERN_ERR "%s: readreg error (ret == %i)\n",
__func__, ret);
return (b1[0] << 8) | b1[1];
}
static int s5h1411_softreset(struct dvb_frontend *fe)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf7, 0);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf7, 1);
return 0;
}
static int s5h1411_set_if_freq(struct dvb_frontend *fe, int KHz)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s(%d KHz)\n", __func__, KHz);
switch (KHz) {
case 3250:
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x38, 0x10d5);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x39, 0x5342);
s5h1411_writereg(state, S5H1411_I2C_QAM_ADDR, 0x2c, 0x10d9);
break;
case 3500:
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x38, 0x1225);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x39, 0x1e96);
s5h1411_writereg(state, S5H1411_I2C_QAM_ADDR, 0x2c, 0x1225);
break;
case 4000:
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x38, 0x14bc);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x39, 0xb53e);
s5h1411_writereg(state, S5H1411_I2C_QAM_ADDR, 0x2c, 0x14bd);
break;
default:
dprintk("%s(%d KHz) Invalid, defaulting to 5380\n",
__func__, KHz);
case 5380:
case 44000:
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x38, 0x1be4);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x39, 0x3655);
s5h1411_writereg(state, S5H1411_I2C_QAM_ADDR, 0x2c, 0x1be4);
break;
}
state->if_freq = KHz;
return 0;
}
static int s5h1411_set_mpeg_timing(struct dvb_frontend *fe, int mode)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 val;
dprintk("%s(%d)\n", __func__, mode);
val = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xbe) & 0xcfff;
switch (mode) {
case S5H1411_MPEGTIMING_CONTINOUS_INVERTING_CLOCK:
val |= 0x0000;
break;
case S5H1411_MPEGTIMING_CONTINOUS_NONINVERTING_CLOCK:
dprintk("%s(%d) Mode1 or Defaulting\n", __func__, mode);
val |= 0x1000;
break;
case S5H1411_MPEGTIMING_NONCONTINOUS_INVERTING_CLOCK:
val |= 0x2000;
break;
case S5H1411_MPEGTIMING_NONCONTINOUS_NONINVERTING_CLOCK:
val |= 0x3000;
break;
default:
return -EINVAL;
}
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xbe, val);
}
static int s5h1411_set_spectralinversion(struct dvb_frontend *fe, int inversion)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 val;
dprintk("%s(%d)\n", __func__, inversion);
val = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0x24) & ~0x1000;
if (inversion == 1)
val |= 0x1000;
state->inversion = inversion;
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x24, val);
}
static int s5h1411_set_serialmode(struct dvb_frontend *fe, int serial)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 val;
dprintk("%s(%d)\n", __func__, serial);
val = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xbd) & ~0x100;
if (serial == 1)
val |= 0x100;
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xbd, val);
}
static int s5h1411_enable_modulation(struct dvb_frontend *fe,
enum fe_modulation m)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s(0x%08x)\n", __func__, m);
if ((state->first_tune == 0) && (m == state->current_modulation)) {
dprintk("%s() Already at desired modulation. Skipping...\n",
__func__);
return 0;
}
switch (m) {
case VSB_8:
dprintk("%s() VSB_8\n", __func__);
s5h1411_set_if_freq(fe, state->config->vsb_if);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x00, 0x71);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf6, 0x00);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xcd, 0xf1);
break;
case QAM_64:
case QAM_256:
case QAM_AUTO:
dprintk("%s() QAM_AUTO (64/256)\n", __func__);
s5h1411_set_if_freq(fe, state->config->qam_if);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0x00, 0x0171);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf6, 0x0001);
s5h1411_writereg(state, S5H1411_I2C_QAM_ADDR, 0x16, 0x1101);
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xcd, 0x00f0);
break;
default:
dprintk("%s() Invalid modulation\n", __func__);
return -EINVAL;
}
state->current_modulation = m;
state->first_tune = 0;
s5h1411_softreset(fe);
return 0;
}
static int s5h1411_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, enable);
if (enable)
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf5, 1);
else
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf5, 0);
}
static int s5h1411_set_gpio(struct dvb_frontend *fe, int enable)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 val;
dprintk("%s(%d)\n", __func__, enable);
val = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xe0) & ~0x02;
if (enable)
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xe0,
val | 0x02);
else
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xe0, val);
}
static int s5h1411_set_powerstate(struct dvb_frontend *fe, int enable)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s(%d)\n", __func__, enable);
if (enable)
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf4, 1);
else {
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf4, 0);
s5h1411_softreset(fe);
}
return 0;
}
static int s5h1411_sleep(struct dvb_frontend *fe)
{
return s5h1411_set_powerstate(fe, 1);
}
static int s5h1411_register_reset(struct dvb_frontend *fe)
{
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
return s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf3, 0);
}
static int s5h1411_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct s5h1411_state *state = fe->demodulator_priv;
dprintk("%s(frequency=%d)\n", __func__, p->frequency);
s5h1411_softreset(fe);
state->current_frequency = p->frequency;
s5h1411_enable_modulation(fe, p->modulation);
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
s5h1411_softreset(fe);
return 0;
}
static int s5h1411_init(struct dvb_frontend *fe)
{
struct s5h1411_state *state = fe->demodulator_priv;
int i;
dprintk("%s()\n", __func__);
s5h1411_set_powerstate(fe, 0);
s5h1411_register_reset(fe);
for (i = 0; i < ARRAY_SIZE(init_tab); i++)
s5h1411_writereg(state, init_tab[i].addr,
init_tab[i].reg,
init_tab[i].data);
state->current_modulation = VSB_8;
state->first_tune = 1;
if (state->config->output_mode == S5H1411_SERIAL_OUTPUT)
s5h1411_set_serialmode(fe, 1);
else
s5h1411_set_serialmode(fe, 0);
s5h1411_set_spectralinversion(fe, state->config->inversion);
s5h1411_set_if_freq(fe, state->config->vsb_if);
s5h1411_set_gpio(fe, state->config->gpio);
s5h1411_set_mpeg_timing(fe, state->config->mpeg_timing);
s5h1411_softreset(fe);
s5h1411_i2c_gate_ctrl(fe, 0);
return 0;
}
static int s5h1411_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 reg;
u32 tuner_status = 0;
*status = 0;
switch (state->current_modulation) {
case QAM_64:
case QAM_256:
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xf0);
if (reg & 0x10)
*status |= FE_HAS_SYNC | FE_HAS_LOCK;
if (reg & 0x100)
*status |= FE_HAS_VITERBI | FE_HAS_CARRIER | FE_HAS_SIGNAL;
break;
case VSB_8:
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xf2);
if (reg & 0x1000)
*status |= FE_HAS_SYNC | FE_HAS_LOCK;
if (reg & 0x2000)
*status |= FE_HAS_VITERBI | FE_HAS_CARRIER | FE_HAS_SIGNAL;
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0x53);
if (reg & 0x1)
*status |= FE_HAS_SIGNAL;
break;
default:
return -EINVAL;
}
switch (state->config->status_mode) {
case S5H1411_DEMODLOCKING:
if (*status & FE_HAS_VITERBI)
*status |= FE_HAS_CARRIER | FE_HAS_SIGNAL;
break;
case S5H1411_TUNERLOCKING:
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
static int s5h1411_qam256_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
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
static int s5h1411_qam64_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
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
static int s5h1411_vsb_lookup_snr(struct dvb_frontend *fe, u16 *snr, u16 v)
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
static int s5h1411_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct s5h1411_state *state = fe->demodulator_priv;
u16 reg;
dprintk("%s()\n", __func__);
switch (state->current_modulation) {
case QAM_64:
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xf1);
return s5h1411_qam64_lookup_snr(fe, snr, reg);
case QAM_256:
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xf1);
return s5h1411_qam256_lookup_snr(fe, snr, reg);
case VSB_8:
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR,
0xf2) & 0x3ff;
return s5h1411_vsb_lookup_snr(fe, snr, reg);
default:
break;
}
return -EINVAL;
}
static int s5h1411_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
u16 snr;
u32 tmp;
int ret = s5h1411_read_snr(fe, &snr);
*signal_strength = 0;
if (0 == ret) {
tmp = (snr * ((1 << 24) / 10));
if (tmp >= 8960 * 0x10000)
*signal_strength = 0xffff;
else
*signal_strength = tmp / 8960;
}
return ret;
}
static int s5h1411_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct s5h1411_state *state = fe->demodulator_priv;
*ucblocks = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0xc9);
return 0;
}
static int s5h1411_read_ber(struct dvb_frontend *fe, u32 *ber)
{
return s5h1411_read_ucblocks(fe, ber);
}
static int s5h1411_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *p)
{
struct s5h1411_state *state = fe->demodulator_priv;
p->frequency = state->current_frequency;
p->modulation = state->current_modulation;
return 0;
}
static int s5h1411_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void s5h1411_release(struct dvb_frontend *fe)
{
struct s5h1411_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *s5h1411_attach(const struct s5h1411_config *config,
struct i2c_adapter *i2c)
{
struct s5h1411_state *state = NULL;
u16 reg;
state = kzalloc(sizeof(struct s5h1411_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->current_modulation = VSB_8;
state->inversion = state->config->inversion;
reg = s5h1411_readreg(state, S5H1411_I2C_TOP_ADDR, 0x05);
if (reg != 0x0066)
goto error;
memcpy(&state->frontend.ops, &s5h1411_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
if (s5h1411_init(&state->frontend) != 0) {
printk(KERN_ERR "%s: Failed to initialize correctly\n",
__func__);
goto error;
}
s5h1411_writereg(state, S5H1411_I2C_TOP_ADDR, 0xf5, 1);
s5h1411_set_powerstate(&state->frontend, 1);
return &state->frontend;
error:
kfree(state);
return NULL;
}
