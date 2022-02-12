static int au8522_mse2snr_lookup(struct mse2snr_tab *tab, int sz, int mse,
u16 *snr)
{
int i, ret = -EINVAL;
dprintk("%s()\n", __func__);
for (i = 0; i < sz; i++) {
if (mse < tab[i].val) {
*snr = tab[i].data;
ret = 0;
break;
}
}
dprintk("%s() snr=%d\n", __func__, *snr);
return ret;
}
static int au8522_set_if(struct dvb_frontend *fe, enum au8522_if_freq if_freq)
{
struct au8522_state *state = fe->demodulator_priv;
u8 r0b5, r0b6, r0b7;
char *ifmhz;
switch (if_freq) {
case AU8522_IF_3_25MHZ:
ifmhz = "3.25";
r0b5 = 0x00;
r0b6 = 0x3d;
r0b7 = 0xa0;
break;
case AU8522_IF_4MHZ:
ifmhz = "4.00";
r0b5 = 0x00;
r0b6 = 0x4b;
r0b7 = 0xd9;
break;
case AU8522_IF_6MHZ:
ifmhz = "6.00";
r0b5 = 0xfb;
r0b6 = 0x8e;
r0b7 = 0x39;
break;
default:
dprintk("%s() IF Frequency not supported\n", __func__);
return -EINVAL;
}
dprintk("%s() %s MHz\n", __func__, ifmhz);
au8522_writereg(state, 0x80b5, r0b5);
au8522_writereg(state, 0x80b6, r0b6);
au8522_writereg(state, 0x80b7, r0b7);
return 0;
}
static int au8522_enable_modulation(struct dvb_frontend *fe,
fe_modulation_t m)
{
struct au8522_state *state = fe->demodulator_priv;
int i;
dprintk("%s(0x%08x)\n", __func__, m);
switch (m) {
case VSB_8:
dprintk("%s() VSB_8\n", __func__);
for (i = 0; i < ARRAY_SIZE(VSB_mod_tab); i++)
au8522_writereg(state,
VSB_mod_tab[i].reg,
VSB_mod_tab[i].data);
au8522_set_if(fe, state->config->vsb_if);
break;
case QAM_64:
dprintk("%s() QAM 64\n", __func__);
for (i = 0; i < ARRAY_SIZE(QAM64_mod_tab); i++)
au8522_writereg(state,
QAM64_mod_tab[i].reg,
QAM64_mod_tab[i].data);
au8522_set_if(fe, state->config->qam_if);
break;
case QAM_256:
dprintk("%s() QAM 256\n", __func__);
for (i = 0; i < ARRAY_SIZE(QAM256_mod_tab); i++)
au8522_writereg(state,
QAM256_mod_tab[i].reg,
QAM256_mod_tab[i].data);
au8522_set_if(fe, state->config->qam_if);
break;
default:
dprintk("%s() Invalid modulation\n", __func__);
return -EINVAL;
}
state->current_modulation = m;
return 0;
}
static int au8522_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct au8522_state *state = fe->demodulator_priv;
int ret = -EINVAL;
dprintk("%s(frequency=%d)\n", __func__, c->frequency);
if ((state->current_frequency == c->frequency) &&
(state->current_modulation == c->modulation))
return 0;
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
if (ret < 0)
return ret;
msleep(100);
au8522_enable_modulation(fe, c->modulation);
state->current_frequency = c->frequency;
return 0;
}
static int au8522_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct au8522_state *state = fe->demodulator_priv;
u8 reg;
u32 tuner_status = 0;
*status = 0;
if (state->current_modulation == VSB_8) {
dprintk("%s() Checking VSB_8\n", __func__);
reg = au8522_readreg(state, 0x4088);
if ((reg & 0x03) == 0x03)
*status |= FE_HAS_LOCK | FE_HAS_SYNC | FE_HAS_VITERBI;
} else {
dprintk("%s() Checking QAM\n", __func__);
reg = au8522_readreg(state, 0x4541);
if (reg & 0x80)
*status |= FE_HAS_VITERBI;
if (reg & 0x20)
*status |= FE_HAS_LOCK | FE_HAS_SYNC;
}
switch (state->config->status_mode) {
case AU8522_DEMODLOCKING:
dprintk("%s() DEMODLOCKING\n", __func__);
if (*status & FE_HAS_VITERBI)
*status |= FE_HAS_CARRIER | FE_HAS_SIGNAL;
break;
case AU8522_TUNERLOCKING:
dprintk("%s() TUNERLOCKING\n", __func__);
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
state->fe_status = *status;
if (*status & FE_HAS_LOCK)
au8522_led_ctrl(state, -1);
else
au8522_led_ctrl(state, 0);
dprintk("%s() status 0x%08x\n", __func__, *status);
return 0;
}
static int au8522_led_status(struct au8522_state *state, const u16 *snr)
{
struct au8522_led_config *led_config = state->config->led_cfg;
int led;
u16 strong;
if (!led_config)
return 0;
if (0 == (state->fe_status & FE_HAS_LOCK))
return au8522_led_ctrl(state, 0);
else if (state->current_modulation == QAM_256)
strong = led_config->qam256_strong;
else if (state->current_modulation == QAM_64)
strong = led_config->qam64_strong;
else
strong = led_config->vsb8_strong;
if (*snr >= strong)
led = 2;
else
led = 1;
if ((state->led_state) &&
(((strong < *snr) ? (*snr - strong) : (strong - *snr)) <= 10))
return 0;
return au8522_led_ctrl(state, led);
}
static int au8522_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct au8522_state *state = fe->demodulator_priv;
int ret = -EINVAL;
dprintk("%s()\n", __func__);
if (state->current_modulation == QAM_256)
ret = au8522_mse2snr_lookup(qam256_mse2snr_tab,
ARRAY_SIZE(qam256_mse2snr_tab),
au8522_readreg(state, 0x4522),
snr);
else if (state->current_modulation == QAM_64)
ret = au8522_mse2snr_lookup(qam64_mse2snr_tab,
ARRAY_SIZE(qam64_mse2snr_tab),
au8522_readreg(state, 0x4522),
snr);
else
ret = au8522_mse2snr_lookup(vsb_mse2snr_tab,
ARRAY_SIZE(vsb_mse2snr_tab),
au8522_readreg(state, 0x4311),
snr);
if (state->config->led_cfg)
au8522_led_status(state, snr);
return ret;
}
static int au8522_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
u16 snr;
u32 tmp;
int ret = au8522_read_snr(fe, &snr);
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
static int au8522_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct au8522_state *state = fe->demodulator_priv;
if (state->current_modulation == VSB_8)
*ucblocks = au8522_readreg(state, 0x4087);
else
*ucblocks = au8522_readreg(state, 0x4543);
return 0;
}
static int au8522_read_ber(struct dvb_frontend *fe, u32 *ber)
{
return au8522_read_ucblocks(fe, ber);
}
static int au8522_get_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct au8522_state *state = fe->demodulator_priv;
c->frequency = state->current_frequency;
c->modulation = state->current_modulation;
return 0;
}
static int au8522_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void au8522_release(struct dvb_frontend *fe)
{
struct au8522_state *state = fe->demodulator_priv;
au8522_release_state(state);
}
struct dvb_frontend *au8522_attach(const struct au8522_config *config,
struct i2c_adapter *i2c)
{
struct au8522_state *state = NULL;
int instance;
instance = au8522_get_state(&state, i2c, config->demod_address);
switch (instance) {
case 0:
dprintk("%s state allocation failed\n", __func__);
break;
case 1:
dprintk("%s using new instance\n", __func__);
break;
default:
dprintk("%s using existing instance\n", __func__);
break;
}
state->config = config;
state->i2c = i2c;
state->operational_mode = AU8522_DIGITAL_MODE;
memcpy(&state->frontend.ops, &au8522_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
state->frontend.ops.analog_ops.i2c_gate_ctrl = au8522_analog_i2c_gate_ctrl;
if (au8522_init(&state->frontend) != 0) {
printk(KERN_ERR "%s: Failed to initialize correctly\n",
__func__);
goto error;
}
au8522_i2c_gate_ctrl(&state->frontend, 1);
return &state->frontend;
error:
au8522_release_state(state);
return NULL;
}
