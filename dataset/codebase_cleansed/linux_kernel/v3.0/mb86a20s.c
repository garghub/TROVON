static int mb86a20s_i2c_writereg(struct mb86a20s_state *state,
u8 i2c_addr, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = i2c_addr, .flags = 0, .buf = buf, .len = 2
};
int rc;
rc = i2c_transfer(state->i2c, &msg, 1);
if (rc != 1) {
printk("%s: writereg error (rc == %i, reg == 0x%02x,"
" data == 0x%02x)\n", __func__, rc, reg, data);
return rc;
}
return 0;
}
static int mb86a20s_i2c_writeregdata(struct mb86a20s_state *state,
u8 i2c_addr, struct regdata *rd, int size)
{
int i, rc;
for (i = 0; i < size; i++) {
rc = mb86a20s_i2c_writereg(state, i2c_addr, rd[i].reg,
rd[i].data);
if (rc < 0)
return rc;
}
return 0;
}
static int mb86a20s_i2c_readreg(struct mb86a20s_state *state,
u8 i2c_addr, u8 reg)
{
u8 val;
int rc;
struct i2c_msg msg[] = {
{ .addr = i2c_addr, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = i2c_addr, .flags = I2C_M_RD, .buf = &val, .len = 1 }
};
rc = i2c_transfer(state->i2c, msg, 2);
if (rc != 2) {
rc("%s: reg=0x%x (error=%d)\n", __func__, reg, rc);
return rc;
}
return val;
}
static int mb86a20s_initfe(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc;
u8 regD5 = 1;
dprintk("\n");
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
rc = mb86a20s_writeregdata(state, mb86a20s_init);
if (rc < 0)
goto err;
if (!state->config->is_serial) {
regD5 &= ~1;
rc = mb86a20s_writereg(state, 0x50, 0xd5);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x51, regD5);
if (rc < 0)
goto err;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
err:
if (rc < 0) {
state->need_init = true;
printk(KERN_INFO "mb86a20s: Init failed. Will try again later\n");
} else {
state->need_init = false;
dprintk("Initialization succeeded.\n");
}
return rc;
}
static int mb86a20s_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct mb86a20s_state *state = fe->demodulator_priv;
unsigned rf_max, rf_min, rf;
u8 val;
dprintk("\n");
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
rf_max = 0xfff;
rf_min = 0;
do {
rf = (rf_max + rf_min) / 2;
mb86a20s_writereg(state, 0x04, 0x1f);
mb86a20s_writereg(state, 0x05, rf >> 8);
mb86a20s_writereg(state, 0x04, 0x20);
mb86a20s_writereg(state, 0x04, rf);
val = mb86a20s_readreg(state, 0x02);
if (val & 0x08)
rf_min = (rf_max + rf_min) / 2;
else
rf_max = (rf_max + rf_min) / 2;
if (rf_max - rf_min < 4) {
*strength = (((rf_max + rf_min) / 2) * 65535) / 4095;
break;
}
} while (1);
dprintk("signal strength = %d\n", *strength);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
return 0;
}
static int mb86a20s_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct mb86a20s_state *state = fe->demodulator_priv;
u8 val;
dprintk("\n");
*status = 0;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
val = mb86a20s_readreg(state, 0x0a) & 0xf;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (val >= 2)
*status |= FE_HAS_SIGNAL;
if (val >= 4)
*status |= FE_HAS_CARRIER;
if (val >= 5)
*status |= FE_HAS_VITERBI;
if (val >= 7)
*status |= FE_HAS_SYNC;
if (val >= 8)
*status |= FE_HAS_LOCK;
dprintk("val = %d, status = 0x%02x\n", val, *status);
return 0;
}
static int mb86a20s_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc;
dprintk("\n");
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
dprintk("Calling tuner set parameters\n");
fe->ops.tuner_ops.set_params(fe, p);
if (state->need_init)
mb86a20s_initfe(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
rc = mb86a20s_writeregdata(state, mb86a20s_reset_reception);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
return rc;
}
static int mb86a20s_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
fe->dtv_property_cache.bandwidth_hz = 6000000;
fe->dtv_property_cache.transmission_mode = TRANSMISSION_MODE_AUTO;
fe->dtv_property_cache.guard_interval = GUARD_INTERVAL_AUTO;
fe->dtv_property_cache.isdbt_partial_reception = 0;
return 0;
}
static int mb86a20s_tune(struct dvb_frontend *fe,
struct dvb_frontend_parameters *params,
unsigned int mode_flags,
unsigned int *delay,
fe_status_t *status)
{
int rc = 0;
dprintk("\n");
if (params != NULL)
rc = mb86a20s_set_frontend(fe, params);
if (!(mode_flags & FE_TUNE_MODE_ONESHOT))
mb86a20s_read_status(fe, status);
return rc;
}
static void mb86a20s_release(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
dprintk("\n");
kfree(state);
}
struct dvb_frontend *mb86a20s_attach(const struct mb86a20s_config *config,
struct i2c_adapter *i2c)
{
u8 rev;
struct mb86a20s_state *state =
kzalloc(sizeof(struct mb86a20s_state), GFP_KERNEL);
dprintk("\n");
if (state == NULL) {
rc("Unable to kzalloc\n");
goto error;
}
state->config = config;
state->i2c = i2c;
memcpy(&state->frontend.ops, &mb86a20s_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
rev = mb86a20s_readreg(state, 0);
if (rev == 0x13) {
printk(KERN_INFO "Detected a Fujitsu mb86a20s frontend\n");
} else {
printk(KERN_ERR "Frontend revision %d is unknown - aborting.\n",
rev);
goto error;
}
return &state->frontend;
error:
kfree(state);
return NULL;
}
