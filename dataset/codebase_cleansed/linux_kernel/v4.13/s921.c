static int s921_i2c_writereg(struct s921_state *state,
u8 i2c_addr, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = i2c_addr, .flags = 0, .buf = buf, .len = 2
};
int rc;
rc = i2c_transfer(state->i2c, &msg, 1);
if (rc != 1) {
printk("%s: writereg rcor(rc == %i, reg == 0x%02x, data == 0x%02x)\n",
__func__, rc, reg, data);
return rc;
}
return 0;
}
static int s921_i2c_writeregdata(struct s921_state *state, u8 i2c_addr,
struct regdata *rd, int size)
{
int i, rc;
for (i = 0; i < size; i++) {
rc = s921_i2c_writereg(state, i2c_addr, rd[i].reg, rd[i].data);
if (rc < 0)
return rc;
}
return 0;
}
static int s921_i2c_readreg(struct s921_state *state, u8 i2c_addr, u8 reg)
{
u8 val;
int rc;
struct i2c_msg msg[] = {
{ .addr = i2c_addr, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = i2c_addr, .flags = I2C_M_RD, .buf = &val, .len = 1 }
};
rc = i2c_transfer(state->i2c, msg, 2);
if (rc != 2) {
rc("%s: reg=0x%x (rcor=%d)\n", __func__, reg, rc);
return rc;
}
return val;
}
static int s921_pll_tune(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct s921_state *state = fe->demodulator_priv;
int band, rc, i;
unsigned long f_offset;
u8 f_switch;
u64 offset;
dprintk("frequency=%i\n", p->frequency);
for (band = 0; band < ARRAY_SIZE(s921_bandselect); band++)
if (p->frequency < s921_bandselect[band].freq_low)
break;
band--;
if (band < 0) {
rc("%s: frequency out of range\n", __func__);
return -EINVAL;
}
f_switch = s921_bandselect[band].band_reg;
offset = ((u64)p->frequency) * 258;
do_div(offset, 6000000);
f_offset = ((unsigned long)offset) + 2321;
rc = s921_writeregdata(state, s921_prefreq);
if (rc < 0)
return rc;
rc = s921_writereg(state, 0xf2, (f_offset >> 8) & 0xff);
if (rc < 0)
return rc;
rc = s921_writereg(state, 0xf3, f_offset & 0xff);
if (rc < 0)
return rc;
rc = s921_writereg(state, 0xf4, f_switch);
if (rc < 0)
return rc;
rc = s921_writeregdata(state, s921_postfreq);
if (rc < 0)
return rc;
for (i = 0 ; i < 6; i++) {
rc = s921_readreg(state, 0x80);
dprintk("status 0x80: %02x\n", rc);
}
rc = s921_writereg(state, 0x01, 0x40);
if (rc < 0)
return rc;
rc = s921_readreg(state, 0x01);
dprintk("status 0x01: %02x\n", rc);
rc = s921_readreg(state, 0x80);
dprintk("status 0x80: %02x\n", rc);
rc = s921_readreg(state, 0x80);
dprintk("status 0x80: %02x\n", rc);
rc = s921_readreg(state, 0x32);
dprintk("status 0x32: %02x\n", rc);
dprintk("pll tune band=%d, pll=%d\n", f_switch, (int)f_offset);
return 0;
}
static int s921_initfe(struct dvb_frontend *fe)
{
struct s921_state *state = fe->demodulator_priv;
int rc;
dprintk("\n");
rc = s921_writeregdata(state, s921_init);
if (rc < 0)
return rc;
return 0;
}
static int s921_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct s921_state *state = fe->demodulator_priv;
int regstatus, rc;
*status = 0;
rc = s921_readreg(state, 0x81);
if (rc < 0)
return rc;
regstatus = rc << 8;
rc = s921_readreg(state, 0x82);
if (rc < 0)
return rc;
regstatus |= rc;
dprintk("status = %04x\n", regstatus);
if ((regstatus & 0xff) == 0x40) {
*status = FE_HAS_SIGNAL |
FE_HAS_CARRIER |
FE_HAS_VITERBI |
FE_HAS_SYNC |
FE_HAS_LOCK;
} else if (regstatus & 0x40) {
*status = FE_HAS_SIGNAL |
FE_HAS_CARRIER |
FE_HAS_VITERBI |
FE_HAS_SYNC;
}
return 0;
}
static int s921_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
enum fe_status status;
struct s921_state *state = fe->demodulator_priv;
int rc;
rc = s921_read_status(fe, &status);
if (rc < 0)
return rc;
*strength = (status & FE_HAS_LOCK) ? 0xffff : 0;
dprintk("strength = 0x%04x\n", *strength);
rc = s921_readreg(state, 0x01);
dprintk("status 0x01: %02x\n", rc);
rc = s921_readreg(state, 0x80);
dprintk("status 0x80: %02x\n", rc);
rc = s921_readreg(state, 0x32);
dprintk("status 0x32: %02x\n", rc);
return 0;
}
static int s921_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct s921_state *state = fe->demodulator_priv;
int rc;
dprintk("\n");
rc = s921_pll_tune(fe);
if (rc < 0)
return rc;
state->currentfreq = p->frequency;
return 0;
}
static int s921_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *p)
{
struct s921_state *state = fe->demodulator_priv;
p->frequency = state->currentfreq;
p->delivery_system = SYS_ISDBT;
return 0;
}
static int s921_tune(struct dvb_frontend *fe,
bool re_tune,
unsigned int mode_flags,
unsigned int *delay,
enum fe_status *status)
{
int rc = 0;
dprintk("\n");
if (re_tune)
rc = s921_set_frontend(fe);
if (!(mode_flags & FE_TUNE_MODE_ONESHOT))
s921_read_status(fe, status);
return rc;
}
static int s921_get_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
static void s921_release(struct dvb_frontend *fe)
{
struct s921_state *state = fe->demodulator_priv;
dprintk("\n");
kfree(state);
}
struct dvb_frontend *s921_attach(const struct s921_config *config,
struct i2c_adapter *i2c)
{
struct s921_state *state =
kzalloc(sizeof(struct s921_state), GFP_KERNEL);
dprintk("\n");
if (!state) {
rc("Unable to kzalloc\n");
return NULL;
}
state->config = config;
state->i2c = i2c;
memcpy(&state->frontend.ops, &s921_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
