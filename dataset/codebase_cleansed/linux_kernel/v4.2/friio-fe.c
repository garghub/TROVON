static int jdvbt90502_reg_read(struct jdvbt90502_state *state,
const u16 reg, u8 *buf, const size_t count)
{
int ret;
u8 wbuf[3];
struct i2c_msg msg[2];
wbuf[0] = reg & 0xFF;
wbuf[1] = 0;
wbuf[2] = reg >> 8;
msg[0].addr = state->config.demod_address;
msg[0].flags = 0;
msg[0].buf = wbuf;
msg[0].len = sizeof(wbuf);
msg[1].addr = msg[0].addr;
msg[1].flags = I2C_M_RD;
msg[1].buf = buf;
msg[1].len = count;
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
deb_fe(" reg read failed.\n");
return -EREMOTEIO;
}
return 0;
}
static int jdvbt90502_single_reg_write(struct jdvbt90502_state *state,
const u8 reg, const u8 val)
{
struct i2c_msg msg;
u8 wbuf[2];
wbuf[0] = reg;
wbuf[1] = val;
msg.addr = state->config.demod_address;
msg.flags = 0;
msg.buf = wbuf;
msg.len = sizeof(wbuf);
if (i2c_transfer(state->i2c, &msg, 1) != 1) {
deb_fe(" reg write failed.");
return -EREMOTEIO;
}
return 0;
}
static int _jdvbt90502_write(struct dvb_frontend *fe, const u8 buf[], int len)
{
struct jdvbt90502_state *state = fe->demodulator_priv;
int err, i;
for (i = 0; i < len - 1; i++) {
err = jdvbt90502_single_reg_write(state,
buf[0] + i, buf[i + 1]);
if (err)
return err;
}
return 0;
}
static int jdvbt90502_pll_read(struct jdvbt90502_state *state, u8 *result)
{
int ret;
u8 pll_addr_byte = (state->config.pll_address << 1) + 1;
*result = 0;
ret = jdvbt90502_single_reg_write(state, JDVBT90502_2ND_I2C_REG,
pll_addr_byte);
if (ret)
goto error;
ret = jdvbt90502_reg_read(state, 0x0100, result, 1);
if (ret)
goto error;
deb_fe("PLL read val:%02x\n", *result);
return 0;
error:
deb_fe("%s:ret == %d\n", __func__, ret);
return -EREMOTEIO;
}
static int jdvbt90502_pll_set_freq(struct jdvbt90502_state *state, u32 freq)
{
int ret;
int retry;
u8 res1;
u8 res2[9];
u8 pll_freq_cmd[PLL_CMD_LEN];
u8 pll_agc_cmd[PLL_CMD_LEN];
struct i2c_msg msg[2];
u32 f;
deb_fe("%s: freq=%d, step=%d\n", __func__, freq,
state->frontend.ops.info.frequency_stepsize);
f = freq / state->frontend.ops.info.frequency_stepsize;
f += 399;
if (f % 7 == 0)
f++;
pll_freq_cmd[DEMOD_REDIRECT_REG] = JDVBT90502_2ND_I2C_REG;
pll_freq_cmd[ADDRESS_BYTE] = state->config.pll_address << 1;
pll_freq_cmd[DIVIDER_BYTE1] = (f >> 8) & 0x7F;
pll_freq_cmd[DIVIDER_BYTE2] = f & 0xFF;
pll_freq_cmd[CONTROL_BYTE] = 0xB2;
pll_freq_cmd[BANDSWITCH_BYTE] = 0x08;
msg[0].addr = state->config.demod_address;
msg[0].flags = 0;
msg[0].buf = pll_freq_cmd;
msg[0].len = sizeof(pll_freq_cmd);
ret = i2c_transfer(state->i2c, &msg[0], 1);
if (ret != 1)
goto error;
udelay(50);
pll_agc_cmd[DEMOD_REDIRECT_REG] = pll_freq_cmd[DEMOD_REDIRECT_REG];
pll_agc_cmd[ADDRESS_BYTE] = pll_freq_cmd[ADDRESS_BYTE];
pll_agc_cmd[DIVIDER_BYTE1] = pll_freq_cmd[DIVIDER_BYTE1];
pll_agc_cmd[DIVIDER_BYTE2] = pll_freq_cmd[DIVIDER_BYTE2];
pll_agc_cmd[CONTROL_BYTE] = 0x9A;
pll_agc_cmd[AGC_CTRL_BYTE] = 0x50;
msg[1].addr = msg[0].addr;
msg[1].flags = 0;
msg[1].buf = pll_agc_cmd;
msg[1].len = sizeof(pll_agc_cmd);
ret = i2c_transfer(state->i2c, &msg[1], 1);
if (ret != 1)
goto error;
ret = jdvbt90502_single_reg_write(state, 0x01, 0x40);
ret |= jdvbt90502_single_reg_write(state, 0x01, 0x00);
if (ret)
goto error;
udelay(100);
#define RETRY_COUNT 5
for (retry = 0; retry < RETRY_COUNT; retry++) {
ret = jdvbt90502_reg_read(state, 0x0096, &res1, 1);
if (ret)
goto error;
ret = jdvbt90502_reg_read(state, 0x00B0, res2, sizeof(res2));
if (ret)
goto error;
if (res2[0] >= 0xA7)
break;
msleep(100);
}
if (retry >= RETRY_COUNT) {
deb_fe("%s: FE does not get ready after freq setting.\n",
__func__);
return -EREMOTEIO;
}
return 0;
error:
deb_fe("%s:ret == %d\n", __func__, ret);
return -EREMOTEIO;
}
static int jdvbt90502_read_status(struct dvb_frontend *fe,
enum fe_status *state)
{
u8 result;
int ret;
*state = FE_HAS_SIGNAL;
ret = jdvbt90502_pll_read(fe->demodulator_priv, &result);
if (ret) {
deb_fe("%s:ret == %d\n", __func__, ret);
return -EREMOTEIO;
}
*state = FE_HAS_SIGNAL
| FE_HAS_CARRIER
| FE_HAS_VITERBI
| FE_HAS_SYNC;
if (result & PLL_STATUS_LOCKED)
*state |= FE_HAS_LOCK;
return 0;
}
static int jdvbt90502_read_signal_strength(struct dvb_frontend *fe,
u16 *strength)
{
int ret;
u8 rbuf[37];
*strength = 0;
ret = jdvbt90502_reg_read(fe->demodulator_priv, 0x0089,
rbuf, sizeof(rbuf));
if (ret) {
deb_fe("%s:ret == %d\n", __func__, ret);
return -EREMOTEIO;
}
*strength = (rbuf[3] << 8) + rbuf[4];
if (rbuf[2])
*strength = 0xffff;
return 0;
}
static int jdvbt90502_set_property(struct dvb_frontend *fe,
struct dtv_property *tvp)
{
int r = 0;
switch (tvp->cmd) {
case DTV_DELIVERY_SYSTEM:
if (tvp->u.data != SYS_ISDBT)
r = -EINVAL;
break;
case DTV_CLEAR:
case DTV_TUNE:
case DTV_FREQUENCY:
break;
default:
r = -EINVAL;
}
return r;
}
static int jdvbt90502_get_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
p->inversion = INVERSION_AUTO;
p->bandwidth_hz = 6000000;
p->code_rate_HP = FEC_AUTO;
p->code_rate_LP = FEC_AUTO;
p->modulation = QAM_64;
p->transmission_mode = TRANSMISSION_MODE_AUTO;
p->guard_interval = GUARD_INTERVAL_AUTO;
p->hierarchy = HIERARCHY_AUTO;
return 0;
}
static int jdvbt90502_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct jdvbt90502_state *state = fe->demodulator_priv;
int ret;
deb_fe("%s: Freq:%d\n", __func__, p->frequency);
fe->dtv_property_cache.delivery_system = SYS_ISDBT;
ret = jdvbt90502_pll_set_freq(state, p->frequency);
if (ret) {
deb_fe("%s:ret == %d\n", __func__, ret);
return -EREMOTEIO;
}
return 0;
}
static int jdvbt90502_init(struct dvb_frontend *fe)
{
int i = -1;
int ret;
struct i2c_msg msg;
struct jdvbt90502_state *state = fe->demodulator_priv;
deb_fe("%s called.\n", __func__);
msg.addr = state->config.demod_address;
msg.flags = 0;
msg.len = 2;
for (i = 0; i < init_code_len; i++) {
msg.buf = init_code[i];
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
goto error;
}
fe->dtv_property_cache.delivery_system = SYS_ISDBT;
msleep(100);
return 0;
error:
deb_fe("%s: init_code[%d] failed. ret==%d\n", __func__, i, ret);
return -EREMOTEIO;
}
static void jdvbt90502_release(struct dvb_frontend *fe)
{
struct jdvbt90502_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *jdvbt90502_attach(struct dvb_usb_device *d)
{
struct jdvbt90502_state *state = NULL;
deb_info("%s called.\n", __func__);
state = kzalloc(sizeof(struct jdvbt90502_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->i2c = &d->i2c_adap;
state->config = friio_fe_config;
state->frontend.ops = jdvbt90502_ops;
state->frontend.demodulator_priv = state;
if (jdvbt90502_init(&state->frontend) < 0)
goto error;
return &state->frontend;
error:
kfree(state);
return NULL;
}
