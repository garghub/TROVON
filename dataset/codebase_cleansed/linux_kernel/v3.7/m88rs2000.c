static int m88rs2000_writereg(struct m88rs2000_state *state, u8 tuner,
u8 reg, u8 data)
{
int ret;
u8 addr = (tuner == 0) ? state->config->tuner_addr :
state->config->demod_addr;
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = addr,
.flags = 0,
.buf = buf,
.len = 2
};
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
deb_info("%s: writereg error (reg == 0x%02x, val == 0x%02x, "
"ret == %i)\n", __func__, reg, data, ret);
return (ret != 1) ? -EREMOTEIO : 0;
}
static int m88rs2000_demod_write(struct m88rs2000_state *state, u8 reg, u8 data)
{
return m88rs2000_writereg(state, 1, reg, data);
}
static int m88rs2000_tuner_write(struct m88rs2000_state *state, u8 reg, u8 data)
{
m88rs2000_demod_write(state, 0x81, 0x84);
udelay(10);
return m88rs2000_writereg(state, 0, reg, data);
}
static int m88rs2000_write(struct dvb_frontend *fe, const u8 buf[], int len)
{
struct m88rs2000_state *state = fe->demodulator_priv;
if (len != 2)
return -EINVAL;
return m88rs2000_writereg(state, 1, buf[0], buf[1]);
}
static u8 m88rs2000_readreg(struct m88rs2000_state *state, u8 tuner, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
u8 addr = (tuner == 0) ? state->config->tuner_addr :
state->config->demod_addr;
struct i2c_msg msg[] = {
{
.addr = addr,
.flags = 0,
.buf = b0,
.len = 1
}, {
.addr = addr,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
deb_info("%s: readreg error (reg == 0x%02x, ret == %i)\n",
__func__, reg, ret);
return b1[0];
}
static u8 m88rs2000_demod_read(struct m88rs2000_state *state, u8 reg)
{
return m88rs2000_readreg(state, 1, reg);
}
static u8 m88rs2000_tuner_read(struct m88rs2000_state *state, u8 reg)
{
m88rs2000_demod_write(state, 0x81, 0x85);
udelay(10);
return m88rs2000_readreg(state, 0, reg);
}
static int m88rs2000_set_symbolrate(struct dvb_frontend *fe, u32 srate)
{
struct m88rs2000_state *state = fe->demodulator_priv;
int ret;
u32 temp;
u8 b[3];
if ((srate < 1000000) || (srate > 45000000))
return -EINVAL;
temp = srate / 1000;
temp *= 11831;
temp /= 68;
temp -= 3;
b[0] = (u8) (temp >> 16) & 0xff;
b[1] = (u8) (temp >> 8) & 0xff;
b[2] = (u8) temp & 0xff;
ret = m88rs2000_demod_write(state, 0x93, b[2]);
ret |= m88rs2000_demod_write(state, 0x94, b[1]);
ret |= m88rs2000_demod_write(state, 0x95, b[0]);
deb_info("m88rs2000: m88rs2000_set_symbolrate\n");
return ret;
}
static int m88rs2000_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *m)
{
struct m88rs2000_state *state = fe->demodulator_priv;
int i;
u8 reg;
deb_info("%s\n", __func__);
m88rs2000_demod_write(state, 0x9a, 0x30);
reg = m88rs2000_demod_read(state, 0xb2);
reg &= 0x3f;
m88rs2000_demod_write(state, 0xb2, reg);
for (i = 0; i < m->msg_len; i++)
m88rs2000_demod_write(state, 0xb3 + i, m->msg[i]);
reg = m88rs2000_demod_read(state, 0xb1);
reg &= 0x87;
reg |= ((m->msg_len - 1) << 3) | 0x07;
reg &= 0x7f;
m88rs2000_demod_write(state, 0xb1, reg);
for (i = 0; i < 15; i++) {
if ((m88rs2000_demod_read(state, 0xb1) & 0x40) == 0x0)
break;
msleep(20);
}
reg = m88rs2000_demod_read(state, 0xb1);
if ((reg & 0x40) > 0x0) {
reg &= 0x7f;
reg |= 0x40;
m88rs2000_demod_write(state, 0xb1, reg);
}
reg = m88rs2000_demod_read(state, 0xb2);
reg &= 0x3f;
reg |= 0x80;
m88rs2000_demod_write(state, 0xb2, reg);
m88rs2000_demod_write(state, 0x9a, 0xb0);
return 0;
}
static int m88rs2000_send_diseqc_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct m88rs2000_state *state = fe->demodulator_priv;
u8 reg0, reg1;
deb_info("%s\n", __func__);
m88rs2000_demod_write(state, 0x9a, 0x30);
msleep(50);
reg0 = m88rs2000_demod_read(state, 0xb1);
reg1 = m88rs2000_demod_read(state, 0xb2);
m88rs2000_demod_write(state, 0xb2, reg1);
m88rs2000_demod_write(state, 0xb1, reg0);
m88rs2000_demod_write(state, 0x9a, 0xb0);
return 0;
}
static int m88rs2000_set_tone(struct dvb_frontend *fe, fe_sec_tone_mode_t tone)
{
struct m88rs2000_state *state = fe->demodulator_priv;
u8 reg0, reg1;
m88rs2000_demod_write(state, 0x9a, 0x30);
reg0 = m88rs2000_demod_read(state, 0xb1);
reg1 = m88rs2000_demod_read(state, 0xb2);
reg1 &= 0x3f;
switch (tone) {
case SEC_TONE_ON:
reg0 |= 0x4;
reg0 &= 0xbc;
break;
case SEC_TONE_OFF:
reg1 |= 0x80;
break;
default:
break;
}
m88rs2000_demod_write(state, 0xb2, reg1);
m88rs2000_demod_write(state, 0xb1, reg0);
m88rs2000_demod_write(state, 0x9a, 0xb0);
return 0;
}
static int m88rs2000_tab_set(struct m88rs2000_state *state,
struct inittab *tab)
{
int ret = 0;
u8 i;
if (tab == NULL)
return -EINVAL;
for (i = 0; i < 255; i++) {
switch (tab[i].cmd) {
case 0x01:
ret = m88rs2000_demod_write(state, tab[i].reg,
tab[i].val);
break;
case 0x02:
ret = m88rs2000_tuner_write(state, tab[i].reg,
tab[i].val);
break;
case 0x10:
if (tab[i].reg > 0)
mdelay(tab[i].reg);
break;
case 0xff:
if (tab[i].reg == 0xaa && tab[i].val == 0xff)
return 0;
case 0x00:
break;
default:
return -EINVAL;
}
if (ret < 0)
return -ENODEV;
}
return 0;
}
static int m88rs2000_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t volt)
{
struct m88rs2000_state *state = fe->demodulator_priv;
u8 data;
data = m88rs2000_demod_read(state, 0xb2);
data |= 0x03;
switch (volt) {
case SEC_VOLTAGE_18:
data &= ~0x03;
break;
case SEC_VOLTAGE_13:
data &= ~0x03;
data |= 0x01;
break;
case SEC_VOLTAGE_OFF:
break;
}
m88rs2000_demod_write(state, 0xb2, data);
return 0;
}
static int m88rs2000_startup(struct m88rs2000_state *state)
{
int ret = 0;
u8 reg;
reg = m88rs2000_tuner_read(state, 0x00);
if ((reg & 0x40) == 0)
ret = -ENODEV;
return ret;
}
static int m88rs2000_init(struct dvb_frontend *fe)
{
struct m88rs2000_state *state = fe->demodulator_priv;
int ret;
deb_info("m88rs2000: init chip\n");
ret = m88rs2000_tab_set(state, m88rs2000_setup);
return ret;
}
static int m88rs2000_sleep(struct dvb_frontend *fe)
{
struct m88rs2000_state *state = fe->demodulator_priv;
int ret;
ret = m88rs2000_tab_set(state, m88rs2000_shutdown);
return ret;
}
static int m88rs2000_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct m88rs2000_state *state = fe->demodulator_priv;
u8 reg = m88rs2000_demod_read(state, 0x8c);
*status = 0;
if ((reg & 0x7) == 0x7) {
*status = FE_HAS_CARRIER | FE_HAS_SIGNAL | FE_HAS_VITERBI
| FE_HAS_SYNC | FE_HAS_LOCK;
if (state->config->set_ts_params)
state->config->set_ts_params(fe, CALL_IS_READ);
}
return 0;
}
static int m88rs2000_read_ber(struct dvb_frontend *fe, u32 *ber)
{
deb_info("m88rs2000_read_ber %d\n", *ber);
*ber = 0;
return 0;
}
static int m88rs2000_read_signal_strength(struct dvb_frontend *fe,
u16 *strength)
{
*strength = 0;
return 0;
}
static int m88rs2000_read_snr(struct dvb_frontend *fe, u16 *snr)
{
deb_info("m88rs2000_read_snr %d\n", *snr);
*snr = 0;
return 0;
}
static int m88rs2000_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
deb_info("m88rs2000_read_ber %d\n", *ucblocks);
*ucblocks = 0;
return 0;
}
static int m88rs2000_tuner_gate_ctrl(struct m88rs2000_state *state, u8 offset)
{
int ret;
ret = m88rs2000_tuner_write(state, 0x51, 0x1f - offset);
ret |= m88rs2000_tuner_write(state, 0x51, 0x1f);
ret |= m88rs2000_tuner_write(state, 0x50, offset);
ret |= m88rs2000_tuner_write(state, 0x50, 0x00);
msleep(20);
return ret;
}
static int m88rs2000_set_tuner_rf(struct dvb_frontend *fe)
{
struct m88rs2000_state *state = fe->demodulator_priv;
int reg;
reg = m88rs2000_tuner_read(state, 0x3d);
reg &= 0x7f;
if (reg < 0x16)
reg = 0xa1;
else if (reg == 0x16)
reg = 0x99;
else
reg = 0xf9;
m88rs2000_tuner_write(state, 0x60, reg);
reg = m88rs2000_tuner_gate_ctrl(state, 0x08);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return reg;
}
static int m88rs2000_set_tuner(struct dvb_frontend *fe, u16 *offset)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct m88rs2000_state *state = fe->demodulator_priv;
int ret;
u32 frequency = c->frequency;
s32 offset_khz;
s32 tmp;
u32 symbol_rate = (c->symbol_rate / 1000);
u32 f3db, gdiv28;
u16 value, ndiv, lpf_coeff;
u8 lpf_mxdiv, mlpf_max, mlpf_min, nlpf;
u8 lo = 0x01, div4 = 0x0;
ret = m88rs2000_tab_set(state, tuner_reset);
if (frequency < 1060000) {
lo |= 0x10;
div4 = 0x1;
ndiv = (frequency * 14 * 4) / FE_CRYSTAL_KHZ;
} else
ndiv = (frequency * 14 * 2) / FE_CRYSTAL_KHZ;
ndiv = ndiv + ndiv % 2;
ndiv = ndiv - 1024;
ret = m88rs2000_tuner_write(state, 0x10, 0x80 | lo);
ret |= m88rs2000_tuner_write(state, 0x01, (ndiv >> 8) & 0xf);
ret |= m88rs2000_tuner_write(state, 0x02, ndiv & 0xff);
ret |= m88rs2000_tuner_write(state, 0x03, 0x06);
ret |= m88rs2000_tuner_gate_ctrl(state, 0x10);
if (ret < 0)
return -ENODEV;
ret = m88rs2000_tuner_write(state, 0x10, lo);
ret |= m88rs2000_tuner_gate_ctrl(state, 0x08);
ret |= m88rs2000_set_tuner_rf(fe);
gdiv28 = (FE_CRYSTAL_KHZ / 1000 * 1694 + 500) / 1000;
ret |= m88rs2000_tuner_write(state, 0x04, gdiv28 & 0xff);
ret |= m88rs2000_tuner_gate_ctrl(state, 0x04);
if (ret < 0)
return -ENODEV;
value = m88rs2000_tuner_read(state, 0x26);
f3db = (symbol_rate * 135) / 200 + 2000;
f3db += FREQ_OFFSET_LOW_SYM_RATE;
if (f3db < 7000)
f3db = 7000;
if (f3db > 40000)
f3db = 40000;
gdiv28 = gdiv28 * 207 / (value * 2 + 151);
mlpf_max = gdiv28 * 135 / 100;
mlpf_min = gdiv28 * 78 / 100;
if (mlpf_max > 63)
mlpf_max = 63;
lpf_coeff = 2766;
nlpf = (f3db * gdiv28 * 2 / lpf_coeff /
(FE_CRYSTAL_KHZ / 1000) + 1) / 2;
if (nlpf > 23)
nlpf = 23;
if (nlpf < 1)
nlpf = 1;
lpf_mxdiv = (nlpf * (FE_CRYSTAL_KHZ / 1000)
* lpf_coeff * 2 / f3db + 1) / 2;
if (lpf_mxdiv < mlpf_min) {
nlpf++;
lpf_mxdiv = (nlpf * (FE_CRYSTAL_KHZ / 1000)
* lpf_coeff * 2 / f3db + 1) / 2;
}
if (lpf_mxdiv > mlpf_max)
lpf_mxdiv = mlpf_max;
ret = m88rs2000_tuner_write(state, 0x04, lpf_mxdiv);
ret |= m88rs2000_tuner_write(state, 0x06, nlpf);
ret |= m88rs2000_tuner_gate_ctrl(state, 0x04);
ret |= m88rs2000_tuner_gate_ctrl(state, 0x01);
msleep(80);
offset_khz = (ndiv - ndiv % 2 + 1024) * FE_CRYSTAL_KHZ
/ 14 / (div4 + 1) / 2;
offset_khz -= frequency;
tmp = offset_khz;
tmp *= 65536;
tmp = (2 * tmp + 96000) / (2 * 96000);
if (tmp < 0)
tmp += 65536;
*offset = tmp & 0xffff;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return (ret < 0) ? -EINVAL : 0;
}
static int m88rs2000_set_fec(struct m88rs2000_state *state,
fe_code_rate_t fec)
{
u16 fec_set;
switch (fec) {
case FEC_AUTO:
default:
fec_set = 0x08;
}
m88rs2000_demod_write(state, 0x76, fec_set);
return 0;
}
static fe_code_rate_t m88rs2000_get_fec(struct m88rs2000_state *state)
{
u8 reg;
m88rs2000_demod_write(state, 0x9a, 0x30);
reg = m88rs2000_demod_read(state, 0x76);
m88rs2000_demod_write(state, 0x9a, 0xb0);
switch (reg) {
case 0x88:
return FEC_1_2;
case 0x68:
return FEC_2_3;
case 0x48:
return FEC_3_4;
case 0x28:
return FEC_5_6;
case 0x18:
return FEC_7_8;
case 0x08:
default:
break;
}
return FEC_AUTO;
}
static int m88rs2000_set_frontend(struct dvb_frontend *fe)
{
struct m88rs2000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
fe_status_t status;
int i, ret;
u16 offset = 0;
u8 reg;
state->no_lock_count = 0;
if (c->delivery_system != SYS_DVBS) {
deb_info("%s: unsupported delivery "
"system selected (%d)\n",
__func__, c->delivery_system);
return -EOPNOTSUPP;
}
ret = m88rs2000_set_tuner(fe, &offset);
if (ret < 0)
return -ENODEV;
ret = m88rs2000_demod_write(state, 0x9a, 0x30);
reg = m88rs2000_demod_read(state, 0x86);
ret |= m88rs2000_demod_write(state, 0x86, reg);
ret |= m88rs2000_demod_write(state, 0x9c, (offset >> 8));
ret |= m88rs2000_demod_write(state, 0x9d, offset & 0xf0);
ret = m88rs2000_tab_set(state, fe_reset);
if (ret < 0)
return -ENODEV;
reg = m88rs2000_demod_read(state, 0x70);
ret = m88rs2000_demod_write(state, 0x70, reg);
ret |= m88rs2000_set_fec(state, c->fec_inner);
ret |= m88rs2000_demod_write(state, 0x85, 0x1);
ret |= m88rs2000_demod_write(state, 0x8a, 0xbf);
ret |= m88rs2000_demod_write(state, 0x8d, 0x1e);
ret |= m88rs2000_demod_write(state, 0x90, 0xf1);
ret |= m88rs2000_demod_write(state, 0x91, 0x08);
if (ret < 0)
return -ENODEV;
ret = m88rs2000_set_symbolrate(fe, c->symbol_rate);
if (ret < 0)
return -ENODEV;
ret = m88rs2000_tab_set(state, fe_trigger);
if (ret < 0)
return -ENODEV;
for (i = 0; i < 25; i++) {
reg = m88rs2000_demod_read(state, 0x8c);
if ((reg & 0x7) == 0x7) {
status = FE_HAS_LOCK;
break;
}
state->no_lock_count++;
if (state->no_lock_count == 15) {
reg = m88rs2000_demod_read(state, 0x70);
reg ^= 0x4;
m88rs2000_demod_write(state, 0x70, reg);
state->no_lock_count = 0;
}
if (state->no_lock_count == 20)
m88rs2000_set_tuner_rf(fe);
msleep(20);
}
if (status & FE_HAS_LOCK) {
state->fec_inner = m88rs2000_get_fec(state);
reg = m88rs2000_demod_read(state, 0x65);
}
state->tuner_frequency = c->frequency;
state->symbol_rate = c->symbol_rate;
return 0;
}
static int m88rs2000_get_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct m88rs2000_state *state = fe->demodulator_priv;
c->fec_inner = state->fec_inner;
c->frequency = state->tuner_frequency;
c->symbol_rate = state->symbol_rate;
return 0;
}
static int m88rs2000_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct m88rs2000_state *state = fe->demodulator_priv;
if (enable)
m88rs2000_demod_write(state, 0x81, 0x84);
else
m88rs2000_demod_write(state, 0x81, 0x81);
udelay(10);
return 0;
}
static void m88rs2000_release(struct dvb_frontend *fe)
{
struct m88rs2000_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *m88rs2000_attach(const struct m88rs2000_config *config,
struct i2c_adapter *i2c)
{
struct m88rs2000_state *state = NULL;
state = kzalloc(sizeof(struct m88rs2000_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
state->tuner_frequency = 0;
state->symbol_rate = 0;
state->fec_inner = 0;
if (m88rs2000_startup(state) < 0)
goto error;
memcpy(&state->frontend.ops, &m88rs2000_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
