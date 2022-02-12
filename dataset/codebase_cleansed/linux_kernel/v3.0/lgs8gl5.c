static int
lgs8gl5_write_reg(struct lgs8gl5_state *state, u8 reg, u8 data)
{
int ret;
u8 buf[] = {reg, data};
struct i2c_msg msg = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf,
.len = 2
};
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: error (reg=0x%02x, val=0x%02x, ret=%i)\n",
__func__, reg, data, ret);
return (ret != 1) ? -1 : 0;
}
static int
lgs8gl5_read_reg(struct lgs8gl5_state *state, u8 reg)
{
int ret;
u8 b0[] = {reg};
u8 b1[] = {0};
struct i2c_msg msg[2] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 1
},
{
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
return -EIO;
return b1[0];
}
static int
lgs8gl5_update_reg(struct lgs8gl5_state *state, u8 reg, u8 data)
{
lgs8gl5_read_reg(state, reg);
lgs8gl5_write_reg(state, reg, data);
return 0;
}
static int
lgs8gl5_update_alt_reg(struct lgs8gl5_state *state, u8 reg, u8 data)
{
int ret;
u8 b0[] = {reg};
u8 b1[] = {0};
u8 b2[] = {reg, data};
struct i2c_msg msg[3] = {
{
.addr = state->config->demod_address + 2,
.flags = 0,
.buf = b0,
.len = 1
},
{
.addr = state->config->demod_address + 2,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
},
{
.addr = state->config->demod_address + 2,
.flags = 0,
.buf = b2,
.len = 2
},
};
ret = i2c_transfer(state->i2c, msg, 3);
return (ret != 3) ? -1 : 0;
}
static void
lgs8gl5_soft_reset(struct lgs8gl5_state *state)
{
u8 val;
dprintk("%s\n", __func__);
val = lgs8gl5_read_reg(state, REG_RESET);
lgs8gl5_write_reg(state, REG_RESET, val & ~REG_RESET_OFF);
lgs8gl5_write_reg(state, REG_RESET, val | REG_RESET_OFF);
msleep(5);
}
static void
lgs8gl5_start_demod(struct lgs8gl5_state *state)
{
u8 val;
int n;
dprintk("%s\n", __func__);
lgs8gl5_update_alt_reg(state, 0xc2, 0x28);
lgs8gl5_soft_reset(state);
lgs8gl5_update_reg(state, REG_07, 0x10);
lgs8gl5_update_reg(state, REG_07, 0x10);
lgs8gl5_write_reg(state, REG_09, 0x0e);
lgs8gl5_write_reg(state, REG_0A, 0xe5);
lgs8gl5_write_reg(state, REG_0B, 0x35);
lgs8gl5_write_reg(state, REG_0C, 0x30);
lgs8gl5_update_reg(state, REG_03, 0x00);
lgs8gl5_update_reg(state, REG_7E, 0x01);
lgs8gl5_update_alt_reg(state, 0xc5, 0x00);
lgs8gl5_update_reg(state, REG_04, 0x02);
lgs8gl5_update_reg(state, REG_37, 0x01);
lgs8gl5_soft_reset(state);
for (n = 0; n < 10; n++) {
val = lgs8gl5_read_reg(state, REG_STRENGTH);
dprintk("Wait for carrier[%d] 0x%02X\n", n, val);
if (val & REG_STRENGTH_CARRIER)
break;
msleep(4);
}
if (!(val & REG_STRENGTH_CARRIER))
return;
for (n = 0; n < 20; n++) {
val = lgs8gl5_read_reg(state, REG_STATUS);
dprintk("Wait for lock[%d] 0x%02X\n", n, val);
if (val & REG_STATUS_LOCK)
break;
msleep(12);
}
if (!(val & REG_STATUS_LOCK))
return;
lgs8gl5_write_reg(state, REG_7D, lgs8gl5_read_reg(state, REG_A2));
lgs8gl5_soft_reset(state);
}
static int
lgs8gl5_init(struct dvb_frontend *fe)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
lgs8gl5_update_alt_reg(state, 0xc2, 0x28);
lgs8gl5_soft_reset(state);
lgs8gl5_update_reg(state, REG_07, 0x10);
lgs8gl5_update_reg(state, REG_07, 0x10);
lgs8gl5_write_reg(state, REG_09, 0x0e);
lgs8gl5_write_reg(state, REG_0A, 0xe5);
lgs8gl5_write_reg(state, REG_0B, 0x35);
lgs8gl5_write_reg(state, REG_0C, 0x30);
return 0;
}
static int
lgs8gl5_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
u8 level = lgs8gl5_read_reg(state, REG_STRENGTH);
u8 flags = lgs8gl5_read_reg(state, REG_STATUS);
*status = 0;
if ((level & REG_STRENGTH_MASK) > 0)
*status |= FE_HAS_SIGNAL;
if (level & REG_STRENGTH_CARRIER)
*status |= FE_HAS_CARRIER;
if (flags & REG_STATUS_SYNC)
*status |= FE_HAS_SYNC;
if (flags & REG_STATUS_LOCK)
*status |= FE_HAS_LOCK;
return 0;
}
static int
lgs8gl5_read_ber(struct dvb_frontend *fe, u32 *ber)
{
*ber = 0;
return 0;
}
static int
lgs8gl5_read_signal_strength(struct dvb_frontend *fe, u16 *signal_strength)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
u8 level = lgs8gl5_read_reg(state, REG_STRENGTH);
*signal_strength = (level & REG_STRENGTH_MASK) << 8;
return 0;
}
static int
lgs8gl5_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
u8 level = lgs8gl5_read_reg(state, REG_STRENGTH);
*snr = (level & REG_STRENGTH_MASK) << 8;
return 0;
}
static int
lgs8gl5_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
*ucblocks = 0;
return 0;
}
static int
lgs8gl5_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
if (p->u.ofdm.bandwidth != BANDWIDTH_8_MHZ)
return -EINVAL;
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe, p);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
lgs8gl5_start_demod(state);
return 0;
}
static int
lgs8gl5_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
u8 inv = lgs8gl5_read_reg(state, REG_INVERSION);
struct dvb_ofdm_parameters *o = &p->u.ofdm;
p->inversion = (inv & REG_INVERSION_ON) ? INVERSION_ON : INVERSION_OFF;
o->code_rate_HP = FEC_1_2;
o->code_rate_LP = FEC_7_8;
o->guard_interval = GUARD_INTERVAL_1_32;
o->transmission_mode = TRANSMISSION_MODE_2K;
o->constellation = QAM_64;
o->hierarchy_information = HIERARCHY_NONE;
o->bandwidth = BANDWIDTH_8_MHZ;
return 0;
}
static int
lgs8gl5_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *fesettings)
{
fesettings->min_delay_ms = 240;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static void
lgs8gl5_release(struct dvb_frontend *fe)
{
struct lgs8gl5_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend*
lgs8gl5_attach(const struct lgs8gl5_config *config, struct i2c_adapter *i2c)
{
struct lgs8gl5_state *state = NULL;
dprintk("%s\n", __func__);
state = kzalloc(sizeof(struct lgs8gl5_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->config = config;
state->i2c = i2c;
if (lgs8gl5_read_reg(state, REG_RESET) < 0)
goto error;
memcpy(&state->frontend.ops, &lgs8gl5_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
