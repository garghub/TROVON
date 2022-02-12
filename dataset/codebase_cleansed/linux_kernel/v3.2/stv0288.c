static int stv0288_writeregI(struct stv0288_state *state, u8 reg, u8 data)
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
dprintk("%s: writereg error (reg == 0x%02x, val == 0x%02x, "
"ret == %i)\n", __func__, reg, data, ret);
return (ret != 1) ? -EREMOTEIO : 0;
}
static int stv0288_write(struct dvb_frontend *fe, const u8 buf[], int len)
{
struct stv0288_state *state = fe->demodulator_priv;
if (len != 2)
return -EINVAL;
return stv0288_writeregI(state, buf[0], buf[1]);
}
static u8 stv0288_readreg(struct stv0288_state *state, u8 reg)
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
static int stv0288_set_symbolrate(struct dvb_frontend *fe, u32 srate)
{
struct stv0288_state *state = fe->demodulator_priv;
unsigned int temp;
unsigned char b[3];
if ((srate < 1000000) || (srate > 45000000))
return -EINVAL;
stv0288_writeregI(state, 0x22, 0);
stv0288_writeregI(state, 0x23, 0);
stv0288_writeregI(state, 0x2b, 0xff);
stv0288_writeregI(state, 0x2c, 0xf7);
temp = (unsigned int)srate / 1000;
temp = temp * 32768;
temp = temp / 25;
temp = temp / 125;
b[0] = (unsigned char)((temp >> 12) & 0xff);
b[1] = (unsigned char)((temp >> 4) & 0xff);
b[2] = (unsigned char)((temp << 4) & 0xf0);
stv0288_writeregI(state, 0x28, 0x80);
stv0288_writeregI(state, 0x29, 0);
stv0288_writeregI(state, 0x2a, 0);
stv0288_writeregI(state, 0x28, b[0]);
stv0288_writeregI(state, 0x29, b[1]);
stv0288_writeregI(state, 0x2a, b[2]);
dprintk("stv0288: stv0288_set_symbolrate\n");
return 0;
}
static int stv0288_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *m)
{
struct stv0288_state *state = fe->demodulator_priv;
int i;
dprintk("%s\n", __func__);
stv0288_writeregI(state, 0x09, 0);
msleep(30);
stv0288_writeregI(state, 0x05, 0x12);
for (i = 0; i < m->msg_len; i++) {
if (stv0288_writeregI(state, 0x06, m->msg[i]))
return -EREMOTEIO;
}
msleep(m->msg_len*12);
return 0;
}
static int stv0288_send_diseqc_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct stv0288_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
if (stv0288_writeregI(state, 0x05, 0x03))
return -EREMOTEIO;
if (stv0288_writeregI(state, 0x06, burst == SEC_MINI_A ? 0x00 : 0xff))
return -EREMOTEIO;
msleep(15);
if (stv0288_writeregI(state, 0x05, 0x12))
return -EREMOTEIO;
return 0;
}
static int stv0288_set_tone(struct dvb_frontend *fe, fe_sec_tone_mode_t tone)
{
struct stv0288_state *state = fe->demodulator_priv;
switch (tone) {
case SEC_TONE_ON:
if (stv0288_writeregI(state, 0x05, 0x10))
return -EREMOTEIO;
break;
case SEC_TONE_OFF:
if (stv0288_writeregI(state, 0x05, 0x12))
return -EREMOTEIO;
break;
default:
return -EINVAL;
}
return 0;
}
static int stv0288_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t volt)
{
dprintk("%s: %s\n", __func__,
volt == SEC_VOLTAGE_13 ? "SEC_VOLTAGE_13" :
volt == SEC_VOLTAGE_18 ? "SEC_VOLTAGE_18" : "??");
return 0;
}
static int stv0288_init(struct dvb_frontend *fe)
{
struct stv0288_state *state = fe->demodulator_priv;
int i;
u8 reg;
u8 val;
dprintk("stv0288: init chip\n");
stv0288_writeregI(state, 0x41, 0x04);
msleep(50);
if (state->config->inittab == NULL) {
for (i = 0; !(stv0288_inittab[i] == 0xff &&
stv0288_inittab[i + 1] == 0xff); i += 2)
stv0288_writeregI(state, stv0288_inittab[i],
stv0288_inittab[i + 1]);
} else {
for (i = 0; ; i += 2) {
reg = state->config->inittab[i];
val = state->config->inittab[i+1];
if (reg == 0xff && val == 0xff)
break;
stv0288_writeregI(state, reg, val);
}
}
return 0;
}
static int stv0288_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct stv0288_state *state = fe->demodulator_priv;
u8 sync = stv0288_readreg(state, 0x24);
if (sync == 255)
sync = 0;
dprintk("%s : FE_READ_STATUS : VSTATUS: 0x%02x\n", __func__, sync);
*status = 0;
if (sync & 0x80)
*status |= FE_HAS_CARRIER | FE_HAS_SIGNAL;
if (sync & 0x10)
*status |= FE_HAS_VITERBI;
if (sync & 0x08) {
*status |= FE_HAS_LOCK;
dprintk("stv0288 has locked\n");
}
return 0;
}
static int stv0288_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct stv0288_state *state = fe->demodulator_priv;
if (state->errmode != STATUS_BER)
return 0;
*ber = (stv0288_readreg(state, 0x26) << 8) |
stv0288_readreg(state, 0x27);
dprintk("stv0288_read_ber %d\n", *ber);
return 0;
}
static int stv0288_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct stv0288_state *state = fe->demodulator_priv;
s32 signal = 0xffff - ((stv0288_readreg(state, 0x10) << 8));
signal = signal * 5 / 4;
*strength = (signal > 0xffff) ? 0xffff : (signal < 0) ? 0 : signal;
dprintk("stv0288_read_signal_strength %d\n", *strength);
return 0;
}
static int stv0288_sleep(struct dvb_frontend *fe)
{
struct stv0288_state *state = fe->demodulator_priv;
stv0288_writeregI(state, 0x41, 0x84);
state->initialised = 0;
return 0;
}
static int stv0288_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct stv0288_state *state = fe->demodulator_priv;
s32 xsnr = 0xffff - ((stv0288_readreg(state, 0x2d) << 8)
| stv0288_readreg(state, 0x2e));
xsnr = 3 * (xsnr - 0xa100);
*snr = (xsnr > 0xffff) ? 0xffff : (xsnr < 0) ? 0 : xsnr;
dprintk("stv0288_read_snr %d\n", *snr);
return 0;
}
static int stv0288_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct stv0288_state *state = fe->demodulator_priv;
if (state->errmode != STATUS_BER)
return 0;
*ucblocks = (stv0288_readreg(state, 0x26) << 8) |
stv0288_readreg(state, 0x27);
dprintk("stv0288_read_ber %d\n", *ucblocks);
return 0;
}
static int stv0288_set_property(struct dvb_frontend *fe, struct dtv_property *p)
{
dprintk("%s(..)\n", __func__);
return 0;
}
static int stv0288_get_property(struct dvb_frontend *fe, struct dtv_property *p)
{
dprintk("%s(..)\n", __func__);
return 0;
}
static int stv0288_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *dfp)
{
struct stv0288_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
char tm;
unsigned char tda[3];
u8 reg, time_out = 0;
dprintk("%s : FE_SET_FRONTEND\n", __func__);
if (c->delivery_system != SYS_DVBS) {
dprintk("%s: unsupported delivery "
"system selected (%d)\n",
__func__, c->delivery_system);
return -EOPNOTSUPP;
}
if (state->config->set_ts_params)
state->config->set_ts_params(fe, 0);
dfp->frequency = c->frequency;
dfp->u.qpsk.symbol_rate = c->symbol_rate;
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe, dfp);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
udelay(10);
stv0288_set_symbolrate(fe, c->symbol_rate);
stv0288_writeregI(state, 0x15, 0xc5);
tda[2] = 0x0;
for (tm = -9; tm < 7;) {
reg = stv0288_readreg(state, 0x24);
if (reg & 0x8)
break;
if (reg & 0x80) {
time_out++;
if (time_out > 10)
break;
tda[2] += 40;
if (tda[2] < 40)
tm++;
} else {
tm++;
tda[2] = 0;
time_out = 0;
}
tda[1] = (unsigned char)tm;
stv0288_writeregI(state, 0x2b, tda[1]);
stv0288_writeregI(state, 0x2c, tda[2]);
udelay(30);
}
state->tuner_frequency = c->frequency;
state->fec_inner = FEC_AUTO;
state->symbol_rate = c->symbol_rate;
return 0;
}
static int stv0288_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct stv0288_state *state = fe->demodulator_priv;
if (enable)
stv0288_writeregI(state, 0x01, 0xb5);
else
stv0288_writeregI(state, 0x01, 0x35);
udelay(1);
return 0;
}
static void stv0288_release(struct dvb_frontend *fe)
{
struct stv0288_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *stv0288_attach(const struct stv0288_config *config,
struct i2c_adapter *i2c)
{
struct stv0288_state *state = NULL;
int id;
state = kzalloc(sizeof(struct stv0288_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->initialised = 0;
state->tuner_frequency = 0;
state->symbol_rate = 0;
state->fec_inner = 0;
state->errmode = STATUS_BER;
stv0288_writeregI(state, 0x41, 0x04);
msleep(200);
id = stv0288_readreg(state, 0x00);
dprintk("stv0288 id %x\n", id);
if (id != 0x11)
goto error;
memcpy(&state->frontend.ops, &stv0288_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
