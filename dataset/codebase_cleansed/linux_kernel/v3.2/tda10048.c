static int tda10048_writereg(struct tda10048_state *state, u8 reg, u8 data)
{
struct tda10048_config *config = &state->config;
int ret;
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = config->demod_address,
.flags = 0, .buf = buf, .len = 2 };
dprintk(2, "%s(reg = 0x%02x, data = 0x%02x)\n", __func__, reg, data);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
printk("%s: writereg error (ret == %i)\n", __func__, ret);
return (ret != 1) ? -1 : 0;
}
static u8 tda10048_readreg(struct tda10048_state *state, u8 reg)
{
struct tda10048_config *config = &state->config;
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{ .addr = config->demod_address,
.flags = 0, .buf = b0, .len = 1 },
{ .addr = config->demod_address,
.flags = I2C_M_RD, .buf = b1, .len = 1 } };
dprintk(2, "%s(reg = 0x%02x)\n", __func__, reg);
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
printk(KERN_ERR "%s: readreg error (ret == %i)\n",
__func__, ret);
return b1[0];
}
static int tda10048_writeregbulk(struct tda10048_state *state, u8 reg,
const u8 *data, u16 len)
{
struct tda10048_config *config = &state->config;
int ret = -EREMOTEIO;
struct i2c_msg msg;
u8 *buf;
dprintk(2, "%s(%d, ?, len = %d)\n", __func__, reg, len);
buf = kmalloc(len + 1, GFP_KERNEL);
if (buf == NULL) {
ret = -ENOMEM;
goto error;
}
*buf = reg;
memcpy(buf + 1, data, len);
msg.addr = config->demod_address;
msg.flags = 0;
msg.buf = buf;
msg.len = len + 1;
dprintk(2, "%s(): write len = %d\n",
__func__, msg.len);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1) {
printk(KERN_ERR "%s(): writereg error err %i\n",
__func__, ret);
ret = -EREMOTEIO;
}
error:
kfree(buf);
return ret;
}
static int tda10048_set_phy2(struct dvb_frontend *fe, u32 sample_freq_hz,
u32 if_hz)
{
struct tda10048_state *state = fe->demodulator_priv;
u64 t;
dprintk(1, "%s()\n", __func__);
if (sample_freq_hz == 0)
return -EINVAL;
if (if_hz < (sample_freq_hz / 2)) {
t = if_hz;
t *= 10;
t *= 32768;
do_div(t, sample_freq_hz);
t += 5;
do_div(t, 10);
} else {
t = sample_freq_hz - if_hz;
t *= 10;
t *= 32768;
do_div(t, sample_freq_hz);
t += 5;
do_div(t, 10);
t = ~t + 1;
}
tda10048_writereg(state, TDA10048_FREQ_PHY2_LSB, (u8)t);
tda10048_writereg(state, TDA10048_FREQ_PHY2_MSB, (u8)(t >> 8));
return 0;
}
static int tda10048_set_wref(struct dvb_frontend *fe, u32 sample_freq_hz,
u32 bw)
{
struct tda10048_state *state = fe->demodulator_priv;
u64 t, z;
u32 b = 8000000;
dprintk(1, "%s()\n", __func__);
if (sample_freq_hz == 0)
return -EINVAL;
if (bw == BANDWIDTH_6_MHZ)
b = 6000000;
else
if (bw == BANDWIDTH_7_MHZ)
b = 7000000;
t = b * 10;
t *= (2048 * 1024);
t *= 1024;
z = 7 * sample_freq_hz;
do_div(t, z);
t += 5;
do_div(t, 10);
tda10048_writereg(state, TDA10048_TIME_WREF_LSB, (u8)t);
tda10048_writereg(state, TDA10048_TIME_WREF_MID1, (u8)(t >> 8));
tda10048_writereg(state, TDA10048_TIME_WREF_MID2, (u8)(t >> 16));
tda10048_writereg(state, TDA10048_TIME_WREF_MSB, (u8)(t >> 24));
return 0;
}
static int tda10048_set_invwref(struct dvb_frontend *fe, u32 sample_freq_hz,
u32 bw)
{
struct tda10048_state *state = fe->demodulator_priv;
u64 t;
u32 b = 8000000;
dprintk(1, "%s()\n", __func__);
if (sample_freq_hz == 0)
return -EINVAL;
if (bw == BANDWIDTH_6_MHZ)
b = 6000000;
else
if (bw == BANDWIDTH_7_MHZ)
b = 7000000;
t = sample_freq_hz;
t *= 7;
t *= 32;
t *= 10;
do_div(t, b);
t += 5;
do_div(t, 10);
tda10048_writereg(state, TDA10048_TIME_INVWREF_LSB, (u8)t);
tda10048_writereg(state, TDA10048_TIME_INVWREF_MSB, (u8)(t >> 8));
return 0;
}
static int tda10048_set_bandwidth(struct dvb_frontend *fe,
enum fe_bandwidth bw)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s(bw=%d)\n", __func__, bw);
switch (bw) {
case BANDWIDTH_6_MHZ:
case BANDWIDTH_7_MHZ:
case BANDWIDTH_8_MHZ:
tda10048_set_wref(fe, state->sample_freq, bw);
tda10048_set_invwref(fe, state->sample_freq, bw);
break;
default:
printk(KERN_ERR "%s() invalid bandwidth\n", __func__);
return -EINVAL;
}
state->bandwidth = bw;
return 0;
}
static int tda10048_set_if(struct dvb_frontend *fe, enum fe_bandwidth bw)
{
struct tda10048_state *state = fe->demodulator_priv;
struct tda10048_config *config = &state->config;
int i;
u32 if_freq_khz;
dprintk(1, "%s(bw = %d)\n", __func__, bw);
switch (bw) {
case BANDWIDTH_6_MHZ:
if_freq_khz = config->dtv6_if_freq_khz;
break;
case BANDWIDTH_7_MHZ:
if_freq_khz = config->dtv7_if_freq_khz;
break;
case BANDWIDTH_8_MHZ:
if_freq_khz = config->dtv8_if_freq_khz;
break;
default:
printk(KERN_ERR "%s() no default\n", __func__);
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(pll_tab); i++) {
if ((pll_tab[i].clk_freq_khz == config->clk_freq_khz) &&
(pll_tab[i].if_freq_khz == if_freq_khz)) {
state->freq_if_hz = pll_tab[i].if_freq_khz * 1000;
state->xtal_hz = pll_tab[i].clk_freq_khz * 1000;
break;
}
}
if (i == ARRAY_SIZE(pll_tab)) {
printk(KERN_ERR "%s() Incorrect attach settings\n",
__func__);
return -EINVAL;
}
dprintk(1, "- freq_if_hz = %d\n", state->freq_if_hz);
dprintk(1, "- xtal_hz = %d\n", state->xtal_hz);
dprintk(1, "- pll_mfactor = %d\n", state->pll_mfactor);
dprintk(1, "- pll_nfactor = %d\n", state->pll_nfactor);
dprintk(1, "- pll_pfactor = %d\n", state->pll_pfactor);
state->sample_freq = state->xtal_hz * (state->pll_mfactor + 45);
state->sample_freq /= (state->pll_nfactor + 1);
state->sample_freq /= (state->pll_pfactor + 4);
dprintk(1, "- sample_freq = %d\n", state->sample_freq);
tda10048_set_phy2(fe, state->sample_freq, state->freq_if_hz);
return 0;
}
static int tda10048_firmware_upload(struct dvb_frontend *fe)
{
struct tda10048_state *state = fe->demodulator_priv;
struct tda10048_config *config = &state->config;
const struct firmware *fw;
int ret;
int pos = 0;
int cnt;
u8 wlen = config->fwbulkwritelen;
if ((wlen != TDA10048_BULKWRITE_200) && (wlen != TDA10048_BULKWRITE_50))
wlen = TDA10048_BULKWRITE_200;
printk(KERN_INFO "%s: waiting for firmware upload (%s)...\n",
__func__,
TDA10048_DEFAULT_FIRMWARE);
ret = request_firmware(&fw, TDA10048_DEFAULT_FIRMWARE,
state->i2c->dev.parent);
if (ret) {
printk(KERN_ERR "%s: Upload failed. (file not found?)\n",
__func__);
return -EIO;
} else {
printk(KERN_INFO "%s: firmware read %Zu bytes.\n",
__func__,
fw->size);
ret = 0;
}
if (fw->size != TDA10048_DEFAULT_FIRMWARE_SIZE) {
printk(KERN_ERR "%s: firmware incorrect size\n", __func__);
ret = -EIO;
} else {
printk(KERN_INFO "%s: firmware uploading\n", __func__);
tda10048_writereg(state, TDA10048_CONF_TRISTATE1,
tda10048_readreg(state, TDA10048_CONF_TRISTATE1)
& 0xfe);
tda10048_writereg(state, TDA10048_CONF_TRISTATE1,
tda10048_readreg(state, TDA10048_CONF_TRISTATE1)
| 0x01);
tda10048_writereg(state, TDA10048_CONF_C4_1,
tda10048_readreg(state, TDA10048_CONF_C4_1) & 0xf9);
tda10048_writereg(state, TDA10048_CONF_C4_1,
tda10048_readreg(state, TDA10048_CONF_C4_1) | 0x08);
tda10048_writereg(state, TDA10048_DSP_CODE_CPT, 0);
while (pos < fw->size) {
if ((fw->size - pos) > wlen)
cnt = wlen;
else
cnt = fw->size - pos;
tda10048_writeregbulk(state, TDA10048_DSP_CODE_IN,
&fw->data[pos], cnt);
pos += cnt;
}
ret = -EIO;
for (cnt = 0; cnt < 250 ; cnt += 10) {
msleep(10);
if (tda10048_readreg(state, TDA10048_SYNC_STATUS)
& 0x40) {
ret = 0;
break;
}
}
}
release_firmware(fw);
if (ret == 0) {
printk(KERN_INFO "%s: firmware uploaded\n", __func__);
state->fwloaded = 1;
} else
printk(KERN_ERR "%s: firmware upload failed\n", __func__);
return ret;
}
static int tda10048_set_inversion(struct dvb_frontend *fe, int inversion)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s(%d)\n", __func__, inversion);
if (inversion == TDA10048_INVERSION_ON)
tda10048_writereg(state, TDA10048_CONF_C1_1,
tda10048_readreg(state, TDA10048_CONF_C1_1) | 0x20);
else
tda10048_writereg(state, TDA10048_CONF_C1_1,
tda10048_readreg(state, TDA10048_CONF_C1_1) & 0xdf);
return 0;
}
static int tda10048_get_tps(struct tda10048_state *state,
struct dvb_ofdm_parameters *p)
{
u8 val;
if (!(tda10048_readreg(state, TDA10048_AUTO) & 0x01))
return -EAGAIN;
val = tda10048_readreg(state, TDA10048_OUT_CONF2);
switch ((val & 0x60) >> 5) {
case 0:
p->constellation = QPSK;
break;
case 1:
p->constellation = QAM_16;
break;
case 2:
p->constellation = QAM_64;
break;
}
switch ((val & 0x18) >> 3) {
case 0:
p->hierarchy_information = HIERARCHY_NONE;
break;
case 1:
p->hierarchy_information = HIERARCHY_1;
break;
case 2:
p->hierarchy_information = HIERARCHY_2;
break;
case 3:
p->hierarchy_information = HIERARCHY_4;
break;
}
switch (val & 0x07) {
case 0:
p->code_rate_HP = FEC_1_2;
break;
case 1:
p->code_rate_HP = FEC_2_3;
break;
case 2:
p->code_rate_HP = FEC_3_4;
break;
case 3:
p->code_rate_HP = FEC_5_6;
break;
case 4:
p->code_rate_HP = FEC_7_8;
break;
}
val = tda10048_readreg(state, TDA10048_OUT_CONF3);
switch (val & 0x07) {
case 0:
p->code_rate_LP = FEC_1_2;
break;
case 1:
p->code_rate_LP = FEC_2_3;
break;
case 2:
p->code_rate_LP = FEC_3_4;
break;
case 3:
p->code_rate_LP = FEC_5_6;
break;
case 4:
p->code_rate_LP = FEC_7_8;
break;
}
val = tda10048_readreg(state, TDA10048_OUT_CONF1);
switch ((val & 0x0c) >> 2) {
case 0:
p->guard_interval = GUARD_INTERVAL_1_32;
break;
case 1:
p->guard_interval = GUARD_INTERVAL_1_16;
break;
case 2:
p->guard_interval = GUARD_INTERVAL_1_8;
break;
case 3:
p->guard_interval = GUARD_INTERVAL_1_4;
break;
}
switch (val & 0x03) {
case 0:
p->transmission_mode = TRANSMISSION_MODE_2K;
break;
case 1:
p->transmission_mode = TRANSMISSION_MODE_8K;
break;
}
return 0;
}
static int tda10048_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct tda10048_state *state = fe->demodulator_priv;
struct tda10048_config *config = &state->config;
dprintk(1, "%s(%d)\n", __func__, enable);
if (config->disable_gate_access)
return 0;
if (enable)
return tda10048_writereg(state, TDA10048_CONF_C4_1,
tda10048_readreg(state, TDA10048_CONF_C4_1) | 0x02);
else
return tda10048_writereg(state, TDA10048_CONF_C4_1,
tda10048_readreg(state, TDA10048_CONF_C4_1) & 0xfd);
}
static int tda10048_output_mode(struct dvb_frontend *fe, int serial)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s(%d)\n", __func__, serial);
tda10048_writereg(state, TDA10048_CONF_TRISTATE1, 0x21);
tda10048_writereg(state, TDA10048_CONF_TRISTATE2, 0x00);
if (serial) {
tda10048_writereg(state, TDA10048_IC_MODE, 0x80 | 0x20);
tda10048_writereg(state, TDA10048_CONF_TS2, 0xc0);
} else {
tda10048_writereg(state, TDA10048_IC_MODE, 0x00);
tda10048_writereg(state, TDA10048_CONF_TS2, 0x01);
}
return 0;
}
static int tda10048_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s(frequency=%d)\n", __func__, p->frequency);
if (p->u.ofdm.bandwidth != state->bandwidth) {
tda10048_set_if(fe, p->u.ofdm.bandwidth);
tda10048_set_bandwidth(fe, p->u.ofdm.bandwidth);
}
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe, p);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
tda10048_writereg(state, TDA10048_AUTO, 0x57);
tda10048_writereg(state, TDA10048_CVBER_CTRL, 0x3B);
return 0;
}
static int tda10048_init(struct dvb_frontend *fe)
{
struct tda10048_state *state = fe->demodulator_priv;
struct tda10048_config *config = &state->config;
int ret = 0, i;
dprintk(1, "%s()\n", __func__);
init_tab[4].data = (u8)(state->pll_mfactor);
init_tab[5].data = (u8)(state->pll_nfactor) | 0x40;
for (i = 0; i < ARRAY_SIZE(init_tab); i++)
tda10048_writereg(state, init_tab[i].reg, init_tab[i].data);
if (state->fwloaded == 0)
ret = tda10048_firmware_upload(fe);
tda10048_output_mode(fe, config->output_mode);
tda10048_set_inversion(fe, config->inversion);
tda10048_set_if(fe, BANDWIDTH_8_MHZ);
tda10048_set_bandwidth(fe, BANDWIDTH_8_MHZ);
tda10048_i2c_gate_ctrl(fe, 0);
return ret;
}
static int tda10048_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct tda10048_state *state = fe->demodulator_priv;
u8 reg;
*status = 0;
reg = tda10048_readreg(state, TDA10048_SYNC_STATUS);
dprintk(1, "%s() status =0x%02x\n", __func__, reg);
if (reg & 0x02)
*status |= FE_HAS_CARRIER;
if (reg & 0x04)
*status |= FE_HAS_SIGNAL;
if (reg & 0x08) {
*status |= FE_HAS_LOCK;
*status |= FE_HAS_VITERBI;
*status |= FE_HAS_SYNC;
}
return 0;
}
static int tda10048_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct tda10048_state *state = fe->demodulator_priv;
static u32 cber_current;
u32 cber_nmax;
u64 cber_tmp;
dprintk(1, "%s()\n", __func__);
if (tda10048_readreg(state, TDA10048_SOFT_IT_C3) & 0x01) {
cber_tmp = tda10048_readreg(state, TDA10048_CBER_MSB) << 8 |
tda10048_readreg(state, TDA10048_CBER_LSB);
cber_nmax = tda10048_readreg(state, TDA10048_CBER_NMAX_MSB) << 8 |
tda10048_readreg(state, TDA10048_CBER_NMAX_LSB);
cber_tmp *= 100000000;
cber_tmp *= 2;
cber_tmp = div_u64(cber_tmp, (cber_nmax * 32) + 1);
cber_current = (u32)cber_tmp;
tda10048_writereg(state, TDA10048_CVBER_CTRL, 0x39);
}
*ber = cber_current;
return 0;
}
static int tda10048_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct tda10048_state *state = fe->demodulator_priv;
u8 v;
dprintk(1, "%s()\n", __func__);
*signal_strength = 65535;
v = tda10048_readreg(state, TDA10048_NP_OUT);
if (v > 0)
*signal_strength -= (v << 8) | v;
return 0;
}
static int tda10048_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct tda10048_state *state = fe->demodulator_priv;
u8 v;
int i, ret = -EINVAL;
dprintk(1, "%s()\n", __func__);
v = tda10048_readreg(state, TDA10048_NP_OUT);
for (i = 0; i < ARRAY_SIZE(snr_tab); i++) {
if (v <= snr_tab[i].val) {
*snr = snr_tab[i].data;
ret = 0;
break;
}
}
return ret;
}
static int tda10048_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s()\n", __func__);
*ucblocks = tda10048_readreg(state, TDA10048_UNCOR_CPT_MSB) << 8 |
tda10048_readreg(state, TDA10048_UNCOR_CPT_LSB);
if (*ucblocks == 0xFFFF)
tda10048_writereg(state, TDA10048_UNCOR_CTRL, 0x80);
return 0;
}
static int tda10048_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s()\n", __func__);
p->inversion = tda10048_readreg(state, TDA10048_CONF_C1_1)
& 0x20 ? INVERSION_ON : INVERSION_OFF;
return tda10048_get_tps(state, &p->u.ofdm);
}
static int tda10048_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void tda10048_release(struct dvb_frontend *fe)
{
struct tda10048_state *state = fe->demodulator_priv;
dprintk(1, "%s()\n", __func__);
kfree(state);
}
static void tda10048_establish_defaults(struct dvb_frontend *fe)
{
struct tda10048_state *state = fe->demodulator_priv;
struct tda10048_config *config = &state->config;
if (config->dtv6_if_freq_khz == 0) {
config->dtv6_if_freq_khz = TDA10048_IF_4300;
printk(KERN_WARNING "%s() tda10048_config.dtv6_if_freq_khz "
"is not set (defaulting to %d)\n",
__func__,
config->dtv6_if_freq_khz);
}
if (config->dtv7_if_freq_khz == 0) {
config->dtv7_if_freq_khz = TDA10048_IF_4300;
printk(KERN_WARNING "%s() tda10048_config.dtv7_if_freq_khz "
"is not set (defaulting to %d)\n",
__func__,
config->dtv7_if_freq_khz);
}
if (config->dtv8_if_freq_khz == 0) {
config->dtv8_if_freq_khz = TDA10048_IF_4300;
printk(KERN_WARNING "%s() tda10048_config.dtv8_if_freq_khz "
"is not set (defaulting to %d)\n",
__func__,
config->dtv8_if_freq_khz);
}
if (config->clk_freq_khz == 0) {
config->clk_freq_khz = TDA10048_CLK_16000;
printk(KERN_WARNING "%s() tda10048_config.clk_freq_khz "
"is not set (defaulting to %d)\n",
__func__,
config->clk_freq_khz);
}
}
struct dvb_frontend *tda10048_attach(const struct tda10048_config *config,
struct i2c_adapter *i2c)
{
struct tda10048_state *state = NULL;
dprintk(1, "%s()\n", __func__);
state = kzalloc(sizeof(struct tda10048_state), GFP_KERNEL);
if (state == NULL)
goto error;
memcpy(&state->config, config, sizeof(*config));
state->i2c = i2c;
state->fwloaded = config->no_firmware;
state->bandwidth = BANDWIDTH_8_MHZ;
if (tda10048_readreg(state, TDA10048_IDENTITY) != 0x048)
goto error;
memcpy(&state->frontend.ops, &tda10048_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
if (config->set_pll) {
state->pll_mfactor = config->pll_m;
state->pll_nfactor = config->pll_n;
state->pll_pfactor = config->pll_p;
} else {
state->pll_mfactor = 10;
state->pll_nfactor = 3;
state->pll_pfactor = 0;
}
tda10048_establish_defaults(&state->frontend);
if (tda10048_set_if(&state->frontend, BANDWIDTH_8_MHZ) != 0)
goto error;
if (tda10048_set_bandwidth(&state->frontend, BANDWIDTH_8_MHZ) != 0)
goto error;
tda10048_i2c_gate_ctrl(&state->frontend, 0);
return &state->frontend;
error:
kfree(state);
return NULL;
}
