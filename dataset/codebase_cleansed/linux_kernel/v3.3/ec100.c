static int ec100_write_reg(struct ec100_state *state, u8 reg, u8 val)
{
u8 buf[2] = {reg, val};
struct i2c_msg msg = {
.addr = state->config.demod_address,
.flags = 0,
.len = 2,
.buf = buf};
if (i2c_transfer(state->i2c, &msg, 1) != 1) {
warn("I2C write failed reg:%02x", reg);
return -EREMOTEIO;
}
return 0;
}
static int ec100_read_reg(struct ec100_state *state, u8 reg, u8 *val)
{
struct i2c_msg msg[2] = {
{
.addr = state->config.demod_address,
.flags = 0,
.len = 1,
.buf = &reg
}, {
.addr = state->config.demod_address,
.flags = I2C_M_RD,
.len = 1,
.buf = val
}
};
if (i2c_transfer(state->i2c, msg, 2) != 2) {
warn("I2C read failed reg:%02x", reg);
return -EREMOTEIO;
}
return 0;
}
static int ec100_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct ec100_state *state = fe->demodulator_priv;
int ret;
u8 tmp, tmp2;
deb_info("%s: freq:%d bw:%d\n", __func__, c->frequency,
c->bandwidth_hz);
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
ret = ec100_write_reg(state, 0x04, 0x06);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x67, 0x58);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x05, 0x18);
if (ret)
goto error;
switch (c->bandwidth_hz) {
case 6000000:
tmp = 0xb7;
tmp2 = 0x55;
break;
case 7000000:
tmp = 0x00;
tmp2 = 0x64;
break;
case 8000000:
default:
tmp = 0x49;
tmp2 = 0x72;
}
ret = ec100_write_reg(state, 0x1b, tmp);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x1c, tmp2);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x0c, 0xbb);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x0d, 0x31);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x08, 0x24);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x00, 0x00);
if (ret)
goto error;
ret = ec100_write_reg(state, 0x00, 0x20);
if (ret)
goto error;
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec100_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *fesettings)
{
fesettings->min_delay_ms = 300;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static int ec100_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct ec100_state *state = fe->demodulator_priv;
int ret;
u8 tmp;
*status = 0;
ret = ec100_read_reg(state, 0x42, &tmp);
if (ret)
goto error;
if (tmp & 0x80) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_LOCK;
} else {
ret = ec100_read_reg(state, 0x01, &tmp);
if (ret)
goto error;
if (tmp & 0x10) {
*status |= FE_HAS_SIGNAL;
if (!(tmp & 0x01)) {
*status |= FE_HAS_CARRIER | FE_HAS_VITERBI;
}
}
}
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec100_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct ec100_state *state = fe->demodulator_priv;
int ret;
u8 tmp, tmp2;
u16 ber2;
*ber = 0;
ret = ec100_read_reg(state, 0x65, &tmp);
if (ret)
goto error;
ret = ec100_read_reg(state, 0x66, &tmp2);
if (ret)
goto error;
ber2 = (tmp2 << 8) | tmp;
if (ber2 < state->ber)
*ber = ber2;
else
*ber = ber2 - state->ber;
state->ber = ber2;
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec100_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct ec100_state *state = fe->demodulator_priv;
int ret;
u8 tmp;
ret = ec100_read_reg(state, 0x24, &tmp);
if (ret) {
*strength = 0;
goto error;
}
*strength = ((tmp << 8) | tmp);
return ret;
error:
deb_info("%s: failed:%d\n", __func__, ret);
return ret;
}
static int ec100_read_snr(struct dvb_frontend *fe, u16 *snr)
{
*snr = 0;
return 0;
}
static int ec100_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
*ucblocks = 0;
return 0;
}
static void ec100_release(struct dvb_frontend *fe)
{
struct ec100_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *ec100_attach(const struct ec100_config *config,
struct i2c_adapter *i2c)
{
int ret;
struct ec100_state *state = NULL;
u8 tmp;
state = kzalloc(sizeof(struct ec100_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->i2c = i2c;
memcpy(&state->config, config, sizeof(struct ec100_config));
ret = ec100_read_reg(state, 0x33, &tmp);
if (ret || tmp != 0x0b)
goto error;
memcpy(&state->frontend.ops, &ec100_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
