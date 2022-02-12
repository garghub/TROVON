static int _tda10021_writereg (struct tda10021_state* state, u8 reg, u8 data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = state->config->demod_address, .flags = 0, .buf = buf, .len = 2 };
int ret;
ret = i2c_transfer (state->i2c, &msg, 1);
if (ret != 1)
printk("DVB: TDA10021(%d): %s, writereg error "
"(reg == 0x%02x, val == 0x%02x, ret == %i)\n",
state->frontend.dvb->num, __func__, reg, data, ret);
msleep(10);
return (ret != 1) ? -EREMOTEIO : 0;
}
static u8 tda10021_readreg (struct tda10021_state* state, u8 reg)
{
u8 b0 [] = { reg };
u8 b1 [] = { 0 };
struct i2c_msg msg [] = { { .addr = state->config->demod_address, .flags = 0, .buf = b0, .len = 1 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD, .buf = b1, .len = 1 } };
int ret;
ret = i2c_transfer (state->i2c, msg, 2);
if (ret != 2 && reg != 0x1a)
printk("DVB: TDA10021: %s: readreg error (ret == %i)\n",
__func__, ret);
return b1[0];
}
static int lock_tuner(struct tda10021_state* state)
{
u8 buf[2] = { 0x0f, tda10021_inittab[0x0f] | 0x80 };
struct i2c_msg msg = {.addr=state->config->demod_address, .flags=0, .buf=buf, .len=2};
if(i2c_transfer(state->i2c, &msg, 1) != 1)
{
printk("tda10021: lock tuner fails\n");
return -EREMOTEIO;
}
return 0;
}
static int unlock_tuner(struct tda10021_state* state)
{
u8 buf[2] = { 0x0f, tda10021_inittab[0x0f] & 0x7f };
struct i2c_msg msg_post={.addr=state->config->demod_address, .flags=0, .buf=buf, .len=2};
if(i2c_transfer(state->i2c, &msg_post, 1) != 1)
{
printk("tda10021: unlock tuner fails\n");
return -EREMOTEIO;
}
return 0;
}
static int tda10021_setup_reg0(struct tda10021_state *state, u8 reg0,
enum fe_spectral_inversion inversion)
{
reg0 |= state->reg0 & 0x63;
if ((INVERSION_ON == inversion) ^ (state->config->invert == 0))
reg0 &= ~0x20;
else
reg0 |= 0x20;
_tda10021_writereg (state, 0x00, reg0 & 0xfe);
_tda10021_writereg (state, 0x00, reg0 | 0x01);
state->reg0 = reg0;
return 0;
}
static int tda10021_set_symbolrate (struct tda10021_state* state, u32 symbolrate)
{
s32 BDR;
s32 BDRI;
s16 SFIL=0;
u16 NDEC = 0;
u32 tmp, ratio;
if (symbolrate > XIN/2)
symbolrate = XIN/2;
if (symbolrate < 500000)
symbolrate = 500000;
if (symbolrate < XIN/16) NDEC = 1;
if (symbolrate < XIN/32) NDEC = 2;
if (symbolrate < XIN/64) NDEC = 3;
if (symbolrate < (u32)(XIN/12.3)) SFIL = 1;
if (symbolrate < (u32)(XIN/16)) SFIL = 0;
if (symbolrate < (u32)(XIN/24.6)) SFIL = 1;
if (symbolrate < (u32)(XIN/32)) SFIL = 0;
if (symbolrate < (u32)(XIN/49.2)) SFIL = 1;
if (symbolrate < (u32)(XIN/64)) SFIL = 0;
if (symbolrate < (u32)(XIN/98.4)) SFIL = 1;
symbolrate <<= NDEC;
ratio = (symbolrate << 4) / FIN;
tmp = ((symbolrate << 4) % FIN) << 8;
ratio = (ratio << 8) + tmp / FIN;
tmp = (tmp % FIN) << 8;
ratio = (ratio << 8) + DIV_ROUND_CLOSEST(tmp, FIN);
BDR = ratio;
BDRI = (((XIN << 5) / symbolrate) + 1) / 2;
if (BDRI > 0xFF)
BDRI = 0xFF;
SFIL = (SFIL << 4) | tda10021_inittab[0x0E];
NDEC = (NDEC << 6) | tda10021_inittab[0x03];
_tda10021_writereg (state, 0x03, NDEC);
_tda10021_writereg (state, 0x0a, BDR&0xff);
_tda10021_writereg (state, 0x0b, (BDR>> 8)&0xff);
_tda10021_writereg (state, 0x0c, (BDR>>16)&0x3f);
_tda10021_writereg (state, 0x0d, BDRI);
_tda10021_writereg (state, 0x0e, SFIL);
return 0;
}
static int tda10021_init (struct dvb_frontend *fe)
{
struct tda10021_state* state = fe->demodulator_priv;
int i;
dprintk("DVB: TDA10021(%d): init chip\n", fe->adapter->num);
for (i=0; i<tda10021_inittab_size; i++)
_tda10021_writereg (state, i, tda10021_inittab[i]);
_tda10021_writereg (state, 0x34, state->pwm);
_tda10021_writereg(state, 0x2a, tda10021_inittab[0x2a] & 0xef);
return 0;
}
static int tda10021_set_parameters(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 delsys = c->delivery_system;
unsigned qam = c->modulation;
bool is_annex_c;
u32 reg0x3d;
struct tda10021_state* state = fe->demodulator_priv;
static const struct qam_params qam_params[] = {
[QPSK] = { 0x14, 0x78, 0x78, 0x8c, 0x96 },
[QAM_16] = { 0x00, 0x8c, 0x87, 0xa2, 0x91 },
[QAM_32] = { 0x04, 0x8c, 0x64, 0x74, 0x96 },
[QAM_64] = { 0x08, 0x6a, 0x46, 0x43, 0x6a },
[QAM_128] = { 0x0c, 0x78, 0x36, 0x34, 0x7e },
[QAM_256] = { 0x10, 0x5c, 0x26, 0x23, 0x6b },
};
switch (delsys) {
case SYS_DVBC_ANNEX_A:
is_annex_c = false;
break;
case SYS_DVBC_ANNEX_C:
is_annex_c = true;
break;
default:
return -EINVAL;
}
switch (qam) {
case QPSK:
case QAM_16:
case QAM_32:
case QAM_64:
case QAM_128:
case QAM_256:
break;
default:
return -EINVAL;
}
if (c->inversion != INVERSION_ON && c->inversion != INVERSION_OFF)
return -EINVAL;
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
tda10021_set_symbolrate(state, c->symbol_rate);
_tda10021_writereg(state, 0x34, state->pwm);
_tda10021_writereg(state, 0x01, qam_params[qam].agcref);
_tda10021_writereg(state, 0x05, qam_params[qam].lthr);
_tda10021_writereg(state, 0x08, qam_params[qam].mseth);
_tda10021_writereg(state, 0x09, qam_params[qam].aref);
reg0x3d = tda10021_readreg (state, 0x3d);
if (is_annex_c)
_tda10021_writereg (state, 0x3d, 0x01 | reg0x3d);
else
_tda10021_writereg (state, 0x3d, 0xfe & reg0x3d);
tda10021_setup_reg0(state, qam_params[qam].conf, c->inversion);
return 0;
}
static int tda10021_read_status(struct dvb_frontend *fe,
enum fe_status *status)
{
struct tda10021_state* state = fe->demodulator_priv;
int sync;
*status = 0;
sync = tda10021_readreg (state, 0x11);
if (sync & 2)
*status |= FE_HAS_SIGNAL|FE_HAS_CARRIER;
if (sync & 4)
*status |= FE_HAS_SYNC|FE_HAS_VITERBI;
if (sync & 8)
*status |= FE_HAS_LOCK;
return 0;
}
static int tda10021_read_ber(struct dvb_frontend* fe, u32* ber)
{
struct tda10021_state* state = fe->demodulator_priv;
u32 _ber = tda10021_readreg(state, 0x14) |
(tda10021_readreg(state, 0x15) << 8) |
((tda10021_readreg(state, 0x16) & 0x0f) << 16);
_tda10021_writereg(state, 0x10, (tda10021_readreg(state, 0x10) & ~0xc0)
| (tda10021_inittab[0x10] & 0xc0));
*ber = 10 * _ber;
return 0;
}
static int tda10021_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
struct tda10021_state* state = fe->demodulator_priv;
u8 config = tda10021_readreg(state, 0x02);
u8 gain = tda10021_readreg(state, 0x17);
if (config & 0x02)
gain = ~gain;
*strength = (gain << 8) | gain;
return 0;
}
static int tda10021_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct tda10021_state* state = fe->demodulator_priv;
u8 quality = ~tda10021_readreg(state, 0x18);
*snr = (quality << 8) | quality;
return 0;
}
static int tda10021_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
struct tda10021_state* state = fe->demodulator_priv;
*ucblocks = tda10021_readreg (state, 0x13) & 0x7f;
if (*ucblocks == 0x7f)
*ucblocks = 0xffffffff;
_tda10021_writereg (state, 0x10, tda10021_inittab[0x10] & 0xdf);
_tda10021_writereg (state, 0x10, tda10021_inittab[0x10]);
return 0;
}
static int tda10021_get_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct tda10021_state* state = fe->demodulator_priv;
int sync;
s8 afc = 0;
sync = tda10021_readreg(state, 0x11);
afc = tda10021_readreg(state, 0x19);
if (verbose) {
printk(sync & 2 ? "DVB: TDA10021(%d): AFC (%d) %dHz\n" :
"DVB: TDA10021(%d): [AFC (%d) %dHz]\n",
state->frontend.dvb->num, afc,
-((s32)p->symbol_rate * afc) >> 10);
}
p->inversion = ((state->reg0 & 0x20) == 0x20) ^ (state->config->invert != 0) ? INVERSION_ON : INVERSION_OFF;
p->modulation = ((state->reg0 >> 2) & 7) + QAM_16;
p->fec_inner = FEC_NONE;
p->frequency = ((p->frequency + 31250) / 62500) * 62500;
if (sync & 2)
p->frequency -= ((s32)p->symbol_rate * afc) >> 10;
return 0;
}
static int tda10021_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
struct tda10021_state* state = fe->demodulator_priv;
if (enable) {
lock_tuner(state);
} else {
unlock_tuner(state);
}
return 0;
}
static int tda10021_sleep(struct dvb_frontend* fe)
{
struct tda10021_state* state = fe->demodulator_priv;
_tda10021_writereg (state, 0x1b, 0x02);
_tda10021_writereg (state, 0x00, 0x80);
return 0;
}
static void tda10021_release(struct dvb_frontend* fe)
{
struct tda10021_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* tda10021_attach(const struct tda1002x_config* config,
struct i2c_adapter* i2c,
u8 pwm)
{
struct tda10021_state* state = NULL;
u8 id;
state = kzalloc(sizeof(struct tda10021_state), GFP_KERNEL);
if (state == NULL) goto error;
state->config = config;
state->i2c = i2c;
state->pwm = pwm;
state->reg0 = tda10021_inittab[0];
id = tda10021_readreg(state, 0x1a);
if ((id & 0xf0) != 0x70) goto error;
if (id == 0x7d)
goto error;
printk("TDA10021: i2c-addr = 0x%02x, id = 0x%02x\n",
state->config->demod_address, id);
memcpy(&state->frontend.ops, &tda10021_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
