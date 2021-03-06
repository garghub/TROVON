static int i2c_writebytes (struct sp887x_state* state, u8 *buf, u8 len)
{
struct i2c_msg msg = { .addr = state->config->demod_address, .flags = 0, .buf = buf, .len = len };
int err;
if ((err = i2c_transfer (state->i2c, &msg, 1)) != 1) {
printk ("%s: i2c write error (addr %02x, err == %i)\n",
__func__, state->config->demod_address, err);
return -EREMOTEIO;
}
return 0;
}
static int sp887x_writereg (struct sp887x_state* state, u16 reg, u16 data)
{
u8 b0 [] = { reg >> 8 , reg & 0xff, data >> 8, data & 0xff };
struct i2c_msg msg = { .addr = state->config->demod_address, .flags = 0, .buf = b0, .len = 4 };
int ret;
if ((ret = i2c_transfer(state->i2c, &msg, 1)) != 1) {
if (!(reg == 0xf1a && data == 0x000 &&
(ret == -EREMOTEIO || ret == -EFAULT)))
{
printk("%s: writereg error "
"(reg %03x, data %03x, ret == %i)\n",
__func__, reg & 0xffff, data & 0xffff, ret);
return ret;
}
}
return 0;
}
static int sp887x_readreg (struct sp887x_state* state, u16 reg)
{
u8 b0 [] = { reg >> 8 , reg & 0xff };
u8 b1 [2];
int ret;
struct i2c_msg msg[] = {{ .addr = state->config->demod_address, .flags = 0, .buf = b0, .len = 2 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD, .buf = b1, .len = 2 }};
if ((ret = i2c_transfer(state->i2c, msg, 2)) != 2) {
printk("%s: readreg error (ret == %i)\n", __func__, ret);
return -1;
}
return (((b1[0] << 8) | b1[1]) & 0xfff);
}
static void sp887x_microcontroller_stop (struct sp887x_state* state)
{
dprintk("%s\n", __func__);
sp887x_writereg(state, 0xf08, 0x000);
sp887x_writereg(state, 0xf09, 0x000);
sp887x_writereg(state, 0xf00, 0x000);
}
static void sp887x_microcontroller_start (struct sp887x_state* state)
{
dprintk("%s\n", __func__);
sp887x_writereg(state, 0xf08, 0x000);
sp887x_writereg(state, 0xf09, 0x000);
sp887x_writereg(state, 0xf00, 0x001);
}
static void sp887x_setup_agc (struct sp887x_state* state)
{
dprintk("%s\n", __func__);
sp887x_writereg(state, 0x33c, 0x054);
sp887x_writereg(state, 0x33b, 0x04c);
sp887x_writereg(state, 0x328, 0x000);
sp887x_writereg(state, 0x327, 0x005);
sp887x_writereg(state, 0x326, 0x001);
sp887x_writereg(state, 0x325, 0x001);
sp887x_writereg(state, 0x324, 0x001);
sp887x_writereg(state, 0x318, 0x050);
sp887x_writereg(state, 0x317, 0x3fe);
sp887x_writereg(state, 0x316, 0x001);
sp887x_writereg(state, 0x313, 0x005);
sp887x_writereg(state, 0x312, 0x002);
sp887x_writereg(state, 0x306, 0x000);
sp887x_writereg(state, 0x303, 0x000);
}
static int sp887x_initial_setup (struct dvb_frontend* fe, const struct firmware *fw)
{
struct sp887x_state* state = fe->demodulator_priv;
u8 buf [BLOCKSIZE+2];
int i;
int fw_size = fw->size;
const unsigned char *mem = fw->data;
dprintk("%s\n", __func__);
if (fw_size < FW_SIZE+10)
return -ENODEV;
mem = fw->data + 10;
sp887x_writereg(state, 0xf1a, 0x000);
sp887x_microcontroller_stop (state);
printk ("%s: firmware upload... ", __func__);
sp887x_writereg(state, 0x8f08, 0x1fff);
sp887x_writereg(state, 0x8f0a, 0x0000);
for (i = 0; i < FW_SIZE; i += BLOCKSIZE) {
int c = BLOCKSIZE;
int err;
if (i+c > FW_SIZE)
c = FW_SIZE - i;
buf[0] = 0xcf;
buf[1] = 0x0a;
memcpy(&buf[2], mem + i, c);
if ((err = i2c_writebytes (state, buf, c+2)) < 0) {
printk ("failed.\n");
printk ("%s: i2c error (err == %i)\n", __func__, err);
return err;
}
}
sp887x_writereg(state, 0xc13, 0x001);
sp887x_writereg(state, 0xc14, 0x000);
sp887x_writereg(state, 0xc1a, 0x872);
sp887x_writereg(state, 0xc1b, 0x001);
sp887x_writereg(state, 0xc1c, 0x000);
sp887x_writereg(state, 0xc1a, 0x871);
sp887x_writereg(state, 0x301, 0x002);
sp887x_setup_agc(state);
sp887x_writereg(state, 0xd00, 0x010);
sp887x_writereg(state, 0x0d1, 0x000);
return 0;
}
static int configure_reg0xc05(struct dtv_frontend_properties *p, u16 *reg0xc05)
{
int known_parameters = 1;
*reg0xc05 = 0x000;
switch (p->modulation) {
case QPSK:
break;
case QAM_16:
*reg0xc05 |= (1 << 10);
break;
case QAM_64:
*reg0xc05 |= (2 << 10);
break;
case QAM_AUTO:
known_parameters = 0;
break;
default:
return -EINVAL;
}
switch (p->hierarchy) {
case HIERARCHY_NONE:
break;
case HIERARCHY_1:
*reg0xc05 |= (1 << 7);
break;
case HIERARCHY_2:
*reg0xc05 |= (2 << 7);
break;
case HIERARCHY_4:
*reg0xc05 |= (3 << 7);
break;
case HIERARCHY_AUTO:
known_parameters = 0;
break;
default:
return -EINVAL;
}
switch (p->code_rate_HP) {
case FEC_1_2:
break;
case FEC_2_3:
*reg0xc05 |= (1 << 3);
break;
case FEC_3_4:
*reg0xc05 |= (2 << 3);
break;
case FEC_5_6:
*reg0xc05 |= (3 << 3);
break;
case FEC_7_8:
*reg0xc05 |= (4 << 3);
break;
case FEC_AUTO:
known_parameters = 0;
break;
default:
return -EINVAL;
}
if (known_parameters)
*reg0xc05 |= (2 << 1);
else
*reg0xc05 |= (1 << 1);
return 0;
}
static void divide (int n, int d, int *quotient_i, int *quotient_f)
{
unsigned int q, r;
r = (n % d) << 8;
q = (r / d);
if (quotient_i)
*quotient_i = q;
if (quotient_f) {
r = (r % d) << 8;
q = (q << 8) | (r / d);
r = (r % d) << 8;
*quotient_f = (q << 8) | (r / d);
}
}
static void sp887x_correct_offsets (struct sp887x_state* state,
struct dtv_frontend_properties *p,
int actual_freq)
{
static const u32 srate_correction [] = { 1879617, 4544878, 8098561 };
int bw_index;
int freq_offset = actual_freq - p->frequency;
int sysclock = 61003;
int ifreq = 36000000;
int freq;
int frequency_shift;
switch (p->bandwidth_hz) {
default:
case 8000000:
bw_index = 0;
break;
case 7000000:
bw_index = 1;
break;
case 6000000:
bw_index = 2;
break;
}
if (p->inversion == INVERSION_ON)
freq = ifreq - freq_offset;
else
freq = ifreq + freq_offset;
divide(freq / 333, sysclock, NULL, &frequency_shift);
if (p->inversion == INVERSION_ON)
frequency_shift = -frequency_shift;
sp887x_writereg(state, 0x319, srate_correction[bw_index] >> 12);
sp887x_writereg(state, 0x31a, srate_correction[bw_index] & 0xfff);
sp887x_writereg(state, 0x309, frequency_shift >> 12);
sp887x_writereg(state, 0x30a, frequency_shift & 0xfff);
}
static int sp887x_setup_frontend_parameters(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct sp887x_state* state = fe->demodulator_priv;
unsigned actual_freq;
int err;
u16 val, reg0xc05;
if (p->bandwidth_hz != 8000000 &&
p->bandwidth_hz != 7000000 &&
p->bandwidth_hz != 6000000)
return -EINVAL;
if ((err = configure_reg0xc05(p, &reg0xc05)))
return err;
sp887x_microcontroller_stop(state);
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
if (fe->ops.tuner_ops.get_frequency) {
fe->ops.tuner_ops.get_frequency(fe, &actual_freq);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
} else {
actual_freq = p->frequency;
}
sp887x_readreg(state, 0x200);
sp887x_correct_offsets(state, p, actual_freq);
if (p->bandwidth_hz == 6000000)
val = 2;
else if (p->bandwidth_hz == 7000000)
val = 1;
else
val = 0;
sp887x_writereg(state, 0x311, val);
if (p->transmission_mode == TRANSMISSION_MODE_2K)
sp887x_writereg(state, 0x338, 0x000);
else
sp887x_writereg(state, 0x338, 0x001);
sp887x_writereg(state, 0xc05, reg0xc05);
if (p->bandwidth_hz == 6000000)
val = 2 << 3;
else if (p->bandwidth_hz == 7000000)
val = 3 << 3;
else
val = 0 << 3;
sp887x_writereg(state, 0xf14, 0x160 | val);
sp887x_writereg(state, 0xf15, 0x000);
sp887x_microcontroller_start(state);
return 0;
}
static int sp887x_read_status(struct dvb_frontend* fe, fe_status_t* status)
{
struct sp887x_state* state = fe->demodulator_priv;
u16 snr12 = sp887x_readreg(state, 0xf16);
u16 sync0x200 = sp887x_readreg(state, 0x200);
u16 sync0xf17 = sp887x_readreg(state, 0xf17);
*status = 0;
if (snr12 > 0x00f)
*status |= FE_HAS_SIGNAL;
if ((sync0xf17 & 0x00f) == 0x002) {
*status |= FE_HAS_LOCK;
*status |= FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_CARRIER;
}
if (sync0x200 & 0x001) {
int steps = (sync0x200 >> 4) & 0x00f;
if (steps & 0x008)
steps = -steps;
dprintk("sp887x: implement tuner adjustment (%+i steps)!!\n",
steps);
}
return 0;
}
static int sp887x_read_ber(struct dvb_frontend* fe, u32* ber)
{
struct sp887x_state* state = fe->demodulator_priv;
*ber = (sp887x_readreg(state, 0xc08) & 0x3f) |
(sp887x_readreg(state, 0xc07) << 6);
sp887x_writereg(state, 0xc08, 0x000);
sp887x_writereg(state, 0xc07, 0x000);
if (*ber >= 0x3fff0)
*ber = ~0;
return 0;
}
static int sp887x_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
struct sp887x_state* state = fe->demodulator_priv;
u16 snr12 = sp887x_readreg(state, 0xf16);
u32 signal = 3 * (snr12 << 4);
*strength = (signal < 0xffff) ? signal : 0xffff;
return 0;
}
static int sp887x_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct sp887x_state* state = fe->demodulator_priv;
u16 snr12 = sp887x_readreg(state, 0xf16);
*snr = (snr12 << 4) | (snr12 >> 8);
return 0;
}
static int sp887x_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
struct sp887x_state* state = fe->demodulator_priv;
*ucblocks = sp887x_readreg(state, 0xc0c);
if (*ucblocks == 0xfff)
*ucblocks = ~0;
return 0;
}
static int sp887x_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
struct sp887x_state* state = fe->demodulator_priv;
if (enable) {
return sp887x_writereg(state, 0x206, 0x001);
} else {
return sp887x_writereg(state, 0x206, 0x000);
}
}
static int sp887x_sleep(struct dvb_frontend* fe)
{
struct sp887x_state* state = fe->demodulator_priv;
sp887x_writereg(state, 0xc18, 0x000);
return 0;
}
static int sp887x_init(struct dvb_frontend* fe)
{
struct sp887x_state* state = fe->demodulator_priv;
const struct firmware *fw = NULL;
int ret;
if (!state->initialised) {
printk("sp887x: waiting for firmware upload (%s)...\n", SP887X_DEFAULT_FIRMWARE);
ret = state->config->request_firmware(fe, &fw, SP887X_DEFAULT_FIRMWARE);
if (ret) {
printk("sp887x: no firmware upload (timeout or file not found?)\n");
return ret;
}
ret = sp887x_initial_setup(fe, fw);
release_firmware(fw);
if (ret) {
printk("sp887x: writing firmware to device failed\n");
return ret;
}
printk("sp887x: firmware upload complete\n");
state->initialised = 1;
}
sp887x_writereg(state, 0xc18, 0x00d);
return 0;
}
static int sp887x_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings* fesettings)
{
fesettings->min_delay_ms = 350;
fesettings->step_size = 166666*2;
fesettings->max_drift = (166666*2)+1;
return 0;
}
static void sp887x_release(struct dvb_frontend* fe)
{
struct sp887x_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* sp887x_attach(const struct sp887x_config* config,
struct i2c_adapter* i2c)
{
struct sp887x_state* state = NULL;
state = kzalloc(sizeof(struct sp887x_state), GFP_KERNEL);
if (state == NULL) goto error;
state->config = config;
state->i2c = i2c;
state->initialised = 0;
if (sp887x_readreg(state, 0x0200) < 0) goto error;
memcpy(&state->frontend.ops, &sp887x_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
