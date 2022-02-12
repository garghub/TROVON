static int ix2505v_read_status_reg(struct ix2505v_state *state)
{
u8 addr = state->config->tuner_address;
u8 b2[] = {0};
int ret;
struct i2c_msg msg[1] = {
{ .addr = addr, .flags = I2C_M_RD, .buf = b2, .len = 1 }
};
ret = i2c_transfer(state->i2c, msg, 1);
deb_i2c("Read %s ", __func__);
return (ret == 1) ? (int) b2[0] : -1;
}
static int ix2505v_write(struct ix2505v_state *state, u8 buf[], u8 count)
{
struct i2c_msg msg[1] = {
{ .addr = state->config->tuner_address, .flags = 0,
.buf = buf, .len = count },
};
int ret;
ret = i2c_transfer(state->i2c, msg, 1);
if (ret != 1) {
deb_i2c("%s: i2c error, ret=%d\n", __func__, ret);
return -EIO;
}
return 0;
}
static int ix2505v_release(struct dvb_frontend *fe)
{
struct ix2505v_state *state = fe->tuner_priv;
fe->tuner_priv = NULL;
kfree(state);
return 0;
}
static int ix2505v_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct ix2505v_state *state = fe->tuner_priv;
u32 frequency = c->frequency;
u32 b_w = (c->symbol_rate * 27) / 32000;
u32 div_factor, N , A, x;
int ret = 0, len;
u8 gain, cc, ref, psc, local_osc, lpf;
u8 data[4] = {0};
if ((frequency < fe->ops.info.frequency_min)
|| (frequency > fe->ops.info.frequency_max))
return -EINVAL;
if (state->config->tuner_gain)
gain = (state->config->tuner_gain < 4)
? state->config->tuner_gain : 0;
else
gain = 0x0;
if (state->config->tuner_chargepump)
cc = state->config->tuner_chargepump;
else
cc = 0x3;
ref = 8;
psc = 32;
div_factor = (frequency * ref) / 40;
x = div_factor / psc;
N = x/100;
A = ((x - (N * 100)) * psc) / 100;
data[0] = ((gain & 0x3) << 5) | (N >> 3);
data[1] = (N << 5) | (A & 0x1f);
data[2] = 0x81 | ((cc & 0x3) << 5) ;
deb_info("Frq=%d x=%d N=%d A=%d\n", frequency, x, N, A);
if (frequency <= 1065000)
local_osc = (6 << 5) | 2;
else if (frequency <= 1170000)
local_osc = (7 << 5) | 2;
else if (frequency <= 1300000)
local_osc = (1 << 5);
else if (frequency <= 1445000)
local_osc = (2 << 5);
else if (frequency <= 1607000)
local_osc = (3 << 5);
else if (frequency <= 1778000)
local_osc = (4 << 5);
else if (frequency <= 1942000)
local_osc = (5 << 5);
else
local_osc = (6 << 5);
data[3] = local_osc;
if (b_w <= 10000)
lpf = 0xc;
else if (b_w <= 12000)
lpf = 0x2;
else if (b_w <= 14000)
lpf = 0xa;
else if (b_w <= 16000)
lpf = 0x6;
else if (b_w <= 18000)
lpf = 0xe;
else if (b_w <= 20000)
lpf = 0x1;
else if (b_w <= 22000)
lpf = 0x9;
else if (b_w <= 24000)
lpf = 0x5;
else if (b_w <= 26000)
lpf = 0xd;
else if (b_w <= 28000)
lpf = 0x3;
else
lpf = 0xb;
deb_info("Osc=%x b_w=%x lpf=%x\n", local_osc, b_w, lpf);
deb_info("Data 0=[%x%x%x%x]\n", data[0], data[1], data[2], data[3]);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
len = sizeof(data);
ret |= ix2505v_write(state, data, len);
data[2] |= 0x4;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
len = 1;
ret |= ix2505v_write(state, &data[2], len);
msleep(10);
data[2] |= ((lpf >> 2) & 0x3) << 3;
data[3] |= (lpf & 0x3) << 2;
deb_info("Data 2=[%x%x]\n", data[2], data[3]);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
len = 2;
ret |= ix2505v_write(state, &data[2], len);
if (state->config->min_delay_ms)
msleep(state->config->min_delay_ms);
state->frequency = frequency;
return ret;
}
static int ix2505v_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct ix2505v_state *state = fe->tuner_priv;
*frequency = state->frequency;
return 0;
}
struct dvb_frontend *ix2505v_attach(struct dvb_frontend *fe,
const struct ix2505v_config *config,
struct i2c_adapter *i2c)
{
struct ix2505v_state *state = NULL;
int ret;
if (NULL == config) {
deb_i2c("%s: no config ", __func__);
goto error;
}
state = kzalloc(sizeof(struct ix2505v_state), GFP_KERNEL);
if (NULL == state)
return NULL;
state->config = config;
state->i2c = i2c;
if (state->config->tuner_write_only) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = ix2505v_read_status_reg(state);
if (ret & 0x80) {
deb_i2c("%s: No IX2505V found\n", __func__);
goto error;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
fe->tuner_priv = state;
memcpy(&fe->ops.tuner_ops, &ix2505v_tuner_ops,
sizeof(struct dvb_tuner_ops));
deb_i2c("%s: initialization (%s addr=0x%02x) ok\n",
__func__, fe->ops.tuner_ops.info.name, config->tuner_address);
return fe;
error:
kfree(state);
return NULL;
}
