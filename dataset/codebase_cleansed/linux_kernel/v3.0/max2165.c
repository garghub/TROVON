static int max2165_write_reg(struct max2165_priv *priv, u8 reg, u8 data)
{
int ret;
u8 buf[] = { reg, data };
struct i2c_msg msg = { .flags = 0, .buf = buf, .len = 2 };
msg.addr = priv->config->i2c_address;
if (debug >= 2)
dprintk("%s: reg=0x%02X, data=0x%02X\n", __func__, reg, data);
ret = i2c_transfer(priv->i2c, &msg, 1);
if (ret != 1)
dprintk("%s: error reg=0x%x, data=0x%x, ret=%i\n",
__func__, reg, data, ret);
return (ret != 1) ? -EIO : 0;
}
static int max2165_read_reg(struct max2165_priv *priv, u8 reg, u8 *p_data)
{
int ret;
u8 dev_addr = priv->config->i2c_address;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{ .addr = dev_addr, .flags = 0, .buf = b0, .len = 1 },
{ .addr = dev_addr, .flags = I2C_M_RD, .buf = b1, .len = 1 },
};
ret = i2c_transfer(priv->i2c, msg, 2);
if (ret != 2) {
dprintk("%s: error reg=0x%x, ret=%i\n", __func__, reg, ret);
return -EIO;
}
*p_data = b1[0];
if (debug >= 2)
dprintk("%s: reg=0x%02X, data=0x%02X\n",
__func__, reg, b1[0]);
return 0;
}
static int max2165_mask_write_reg(struct max2165_priv *priv, u8 reg,
u8 mask, u8 data)
{
int ret;
u8 v;
data &= mask;
ret = max2165_read_reg(priv, reg, &v);
if (ret != 0)
return ret;
v &= ~mask;
v |= data;
ret = max2165_write_reg(priv, reg, v);
return ret;
}
static int max2165_read_rom_table(struct max2165_priv *priv)
{
u8 dat[3];
int i;
for (i = 0; i < 3; i++) {
max2165_write_reg(priv, REG_ROM_TABLE_ADDR, i + 1);
max2165_read_reg(priv, REG_ROM_TABLE_DATA, &dat[i]);
}
priv->tf_ntch_low_cfg = dat[0] >> 4;
priv->tf_ntch_hi_cfg = dat[0] & 0x0F;
priv->tf_balun_low_ref = dat[1] & 0x0F;
priv->tf_balun_hi_ref = dat[1] >> 4;
priv->bb_filter_7mhz_cfg = dat[2] & 0x0F;
priv->bb_filter_8mhz_cfg = dat[2] >> 4;
dprintk("tf_ntch_low_cfg = 0x%X\n", priv->tf_ntch_low_cfg);
dprintk("tf_ntch_hi_cfg = 0x%X\n", priv->tf_ntch_hi_cfg);
dprintk("tf_balun_low_ref = 0x%X\n", priv->tf_balun_low_ref);
dprintk("tf_balun_hi_ref = 0x%X\n", priv->tf_balun_hi_ref);
dprintk("bb_filter_7mhz_cfg = 0x%X\n", priv->bb_filter_7mhz_cfg);
dprintk("bb_filter_8mhz_cfg = 0x%X\n", priv->bb_filter_8mhz_cfg);
return 0;
}
static int max2165_set_osc(struct max2165_priv *priv, u8 osc )
{
u8 v;
v = (osc / 2);
if (v == 2)
v = 0x7;
else
v -= 8;
max2165_mask_write_reg(priv, REG_PLL_CFG, 0x07, v);
return 0;
}
static int max2165_set_bandwidth(struct max2165_priv *priv, u32 bw)
{
u8 val;
if (bw == BANDWIDTH_8_MHZ)
val = priv->bb_filter_8mhz_cfg;
else
val = priv->bb_filter_7mhz_cfg;
max2165_mask_write_reg(priv, REG_BASEBAND_CTRL, 0xF0, val << 4);
return 0;
}
int fixpt_div32(u32 dividend, u32 divisor, u32 *quotient, u32 *fraction)
{
u32 remainder;
u32 q, f = 0;
int i;
if (0 == divisor)
return -1;
q = dividend / divisor;
remainder = dividend - q * divisor;
for (i = 0; i < 31; i++) {
remainder <<= 1;
if (remainder >= divisor) {
f += 1;
remainder -= divisor;
}
f <<= 1;
}
*quotient = q;
*fraction = f;
return 0;
}
static int max2165_set_rf(struct max2165_priv *priv, u32 freq)
{
u8 tf;
u8 tf_ntch;
u32 t;
u32 quotient, fraction;
fixpt_div32(freq / 1000, priv->config->osc_clk * 1000,
&quotient, &fraction);
fraction >>= 12;
max2165_write_reg(priv, REG_NDIV_INT, quotient);
max2165_mask_write_reg(priv, REG_NDIV_FRAC2, 0x0F, fraction >> 16);
max2165_write_reg(priv, REG_NDIV_FRAC1, fraction >> 8);
max2165_write_reg(priv, REG_NDIV_FRAC0, fraction);
tf_ntch = (freq < 725000000) ?
priv->tf_ntch_low_cfg : priv->tf_ntch_hi_cfg;
t = priv->tf_balun_low_ref;
t += (priv->tf_balun_hi_ref - priv->tf_balun_low_ref)
* (freq / 1000 - 470000) / (780000 - 470000);
tf = t;
dprintk("tf = %X\n", tf);
tf |= tf_ntch << 4;
max2165_write_reg(priv, REG_TRACK_FILTER, tf);
return 0;
}
static void max2165_debug_status(struct max2165_priv *priv)
{
u8 status, autotune;
u8 auto_vco_success, auto_vco_active;
u8 pll_locked;
u8 dc_offset_low, dc_offset_hi;
u8 signal_lv_over_threshold;
u8 vco, vco_sub_band, adc;
max2165_read_reg(priv, REG_STATUS, &status);
max2165_read_reg(priv, REG_AUTOTUNE, &autotune);
auto_vco_success = (status >> 6) & 0x01;
auto_vco_active = (status >> 5) & 0x01;
pll_locked = (status >> 4) & 0x01;
dc_offset_low = (status >> 3) & 0x01;
dc_offset_hi = (status >> 2) & 0x01;
signal_lv_over_threshold = status & 0x01;
vco = autotune >> 6;
vco_sub_band = (autotune >> 3) & 0x7;
adc = autotune & 0x7;
dprintk("auto VCO active: %d, auto VCO success: %d\n",
auto_vco_active, auto_vco_success);
dprintk("PLL locked: %d\n", pll_locked);
dprintk("DC offset low: %d, DC offset high: %d\n",
dc_offset_low, dc_offset_hi);
dprintk("Signal lvl over threshold: %d\n", signal_lv_over_threshold);
dprintk("VCO: %d, VCO Sub-band: %d, ADC: %d\n", vco, vco_sub_band, adc);
}
static int max2165_set_params(struct dvb_frontend *fe,
struct dvb_frontend_parameters *params)
{
struct max2165_priv *priv = fe->tuner_priv;
int ret;
dprintk("%s() frequency=%d (Hz)\n", __func__, params->frequency);
if (fe->ops.info.type == FE_ATSC) {
return -EINVAL;
} else if (fe->ops.info.type == FE_OFDM) {
dprintk("%s() OFDM\n", __func__);
switch (params->u.ofdm.bandwidth) {
case BANDWIDTH_6_MHZ:
return -EINVAL;
case BANDWIDTH_7_MHZ:
case BANDWIDTH_8_MHZ:
priv->frequency = params->frequency;
priv->bandwidth = params->u.ofdm.bandwidth;
break;
default:
printk(KERN_ERR "MAX2165 bandwidth not set!\n");
return -EINVAL;
}
} else {
printk(KERN_ERR "MAX2165 modulation type not supported!\n");
return -EINVAL;
}
dprintk("%s() frequency=%d\n", __func__, priv->frequency);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
max2165_set_bandwidth(priv, priv->bandwidth);
ret = max2165_set_rf(priv, priv->frequency);
mdelay(50);
max2165_debug_status(priv);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (ret != 0)
return -EREMOTEIO;
return 0;
}
static int max2165_get_frequency(struct dvb_frontend *fe, u32 *freq)
{
struct max2165_priv *priv = fe->tuner_priv;
dprintk("%s()\n", __func__);
*freq = priv->frequency;
return 0;
}
static int max2165_get_bandwidth(struct dvb_frontend *fe, u32 *bw)
{
struct max2165_priv *priv = fe->tuner_priv;
dprintk("%s()\n", __func__);
*bw = priv->bandwidth;
return 0;
}
static int max2165_get_status(struct dvb_frontend *fe, u32 *status)
{
struct max2165_priv *priv = fe->tuner_priv;
u16 lock_status = 0;
dprintk("%s()\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
max2165_debug_status(priv);
*status = lock_status;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static int max2165_sleep(struct dvb_frontend *fe)
{
dprintk("%s()\n", __func__);
return 0;
}
static int max2165_init(struct dvb_frontend *fe)
{
struct max2165_priv *priv = fe->tuner_priv;
dprintk("%s()\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
max2165_write_reg(priv, REG_NDIV_FRAC2, 0x18);
max2165_write_reg(priv, REG_LNA, 0x01);
max2165_write_reg(priv, REG_PLL_CFG, 0x7A);
max2165_write_reg(priv, REG_TEST, 0x08);
max2165_write_reg(priv, REG_SHUTDOWN, 0x40);
max2165_write_reg(priv, REG_VCO_CTRL, 0x84);
max2165_write_reg(priv, REG_BASEBAND_CTRL, 0xC3);
max2165_write_reg(priv, REG_DC_OFFSET_CTRL, 0x75);
max2165_write_reg(priv, REG_DC_OFFSET_DAC, 0x00);
max2165_write_reg(priv, REG_ROM_TABLE_ADDR, 0x00);
max2165_set_osc(priv, priv->config->osc_clk);
max2165_read_rom_table(priv);
max2165_set_bandwidth(priv, BANDWIDTH_8_MHZ);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static int max2165_release(struct dvb_frontend *fe)
{
struct max2165_priv *priv = fe->tuner_priv;
dprintk("%s()\n", __func__);
kfree(priv);
fe->tuner_priv = NULL;
return 0;
}
struct dvb_frontend *max2165_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c,
struct max2165_config *cfg)
{
struct max2165_priv *priv = NULL;
dprintk("%s(%d-%04x)\n", __func__,
i2c ? i2c_adapter_id(i2c) : -1,
cfg ? cfg->i2c_address : -1);
priv = kzalloc(sizeof(struct max2165_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
memcpy(&fe->ops.tuner_ops, &max2165_tuner_ops,
sizeof(struct dvb_tuner_ops));
priv->config = cfg;
priv->i2c = i2c;
fe->tuner_priv = priv;
max2165_init(fe);
max2165_debug_status(priv);
return fe;
}
