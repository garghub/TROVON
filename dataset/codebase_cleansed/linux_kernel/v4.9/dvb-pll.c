static void thomson_dtt759x_bw(struct dvb_frontend *fe, u8 *buf)
{
u32 bw = fe->dtv_property_cache.bandwidth_hz;
if (bw == 7000000)
buf[3] |= 0x10;
}
static void thomson_dtt7520x_bw(struct dvb_frontend *fe, u8 *buf)
{
u32 bw = fe->dtv_property_cache.bandwidth_hz;
if (bw == 8000000)
buf[3] ^= 0x10;
}
static void tda665x_bw(struct dvb_frontend *fe, u8 *buf)
{
u32 bw = fe->dtv_property_cache.bandwidth_hz;
if (bw == 8000000)
buf[3] |= 0x08;
}
static void tua6034_bw(struct dvb_frontend *fe, u8 *buf)
{
u32 bw = fe->dtv_property_cache.bandwidth_hz;
if (bw == 7000000)
buf[3] |= 0x08;
}
static void tded4_bw(struct dvb_frontend *fe, u8 *buf)
{
u32 bw = fe->dtv_property_cache.bandwidth_hz;
if (bw == 8000000)
buf[3] |= 0x04;
}
static void opera1_bw(struct dvb_frontend *fe, u8 *buf)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_pll_priv *priv = fe->tuner_priv;
u32 b_w = (c->symbol_rate * 27) / 32000;
struct i2c_msg msg = {
.addr = priv->pll_i2c_address,
.flags = 0,
.buf = buf,
.len = 4
};
int result;
u8 lpf;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
result = i2c_transfer(priv->i2c, &msg, 1);
if (result != 1)
printk(KERN_ERR "%s: i2c_transfer failed:%d",
__func__, result);
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
buf[2] ^= 0x1c;
buf[2] |= ((lpf >> 2) & 0x3) << 3;
buf[3] |= (lpf & 0x3) << 2;
return;
}
static void samsung_dtos403ih102a_set(struct dvb_frontend *fe, u8 *buf)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
struct i2c_msg msg = {
.addr = priv->pll_i2c_address,
.flags = 0,
.buf = buf,
.len = 4
};
int result;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
result = i2c_transfer(priv->i2c, &msg, 1);
if (result != 1)
printk(KERN_ERR "%s: i2c_transfer failed:%d",
__func__, result);
buf[2] = 0x9e;
buf[3] = 0x90;
return;
}
static int dvb_pll_configure(struct dvb_frontend *fe, u8 *buf,
const u32 frequency)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
const struct dvb_pll_desc *desc = priv->pll_desc;
u32 div;
int i;
if (frequency && (frequency < desc->min || frequency > desc->max))
return -EINVAL;
for (i = 0; i < desc->count; i++) {
if (frequency > desc->entries[i].limit)
continue;
break;
}
if (debug)
printk("pll: %s: freq=%d | i=%d/%d\n", desc->name,
frequency, i, desc->count);
if (i == desc->count)
return -EINVAL;
div = (frequency + desc->iffreq +
desc->entries[i].stepsize/2) / desc->entries[i].stepsize;
buf[0] = div >> 8;
buf[1] = div & 0xff;
buf[2] = desc->entries[i].config;
buf[3] = desc->entries[i].cb;
if (desc->set)
desc->set(fe, buf);
if (debug)
printk("pll: %s: div=%d | buf=0x%02x,0x%02x,0x%02x,0x%02x\n",
desc->name, div, buf[0], buf[1], buf[2], buf[3]);
return (div * desc->entries[i].stepsize) - desc->iffreq;
}
static int dvb_pll_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int dvb_pll_sleep(struct dvb_frontend *fe)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
if (priv->i2c == NULL)
return -EINVAL;
if (priv->pll_desc->sleepdata) {
struct i2c_msg msg = { .flags = 0,
.addr = priv->pll_i2c_address,
.buf = priv->pll_desc->sleepdata + 1,
.len = priv->pll_desc->sleepdata[0] };
int result;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if ((result = i2c_transfer(priv->i2c, &msg, 1)) != 1) {
return result;
}
return 0;
}
return -EINVAL;
}
static int dvb_pll_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_pll_priv *priv = fe->tuner_priv;
u8 buf[4];
struct i2c_msg msg =
{ .addr = priv->pll_i2c_address, .flags = 0,
.buf = buf, .len = sizeof(buf) };
int result;
u32 frequency = 0;
if (priv->i2c == NULL)
return -EINVAL;
result = dvb_pll_configure(fe, buf, c->frequency);
if (result < 0)
return result;
else
frequency = result;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if ((result = i2c_transfer(priv->i2c, &msg, 1)) != 1) {
return result;
}
priv->frequency = frequency;
priv->bandwidth = c->bandwidth_hz;
return 0;
}
static int dvb_pll_calc_regs(struct dvb_frontend *fe,
u8 *buf, int buf_len)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct dvb_pll_priv *priv = fe->tuner_priv;
int result;
u32 frequency = 0;
if (buf_len < 5)
return -EINVAL;
result = dvb_pll_configure(fe, buf + 1, c->frequency);
if (result < 0)
return result;
else
frequency = result;
buf[0] = priv->pll_i2c_address;
priv->frequency = frequency;
priv->bandwidth = c->bandwidth_hz;
return 5;
}
static int dvb_pll_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
static int dvb_pll_get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
*bandwidth = priv->bandwidth;
return 0;
}
static int dvb_pll_init(struct dvb_frontend *fe)
{
struct dvb_pll_priv *priv = fe->tuner_priv;
if (priv->i2c == NULL)
return -EINVAL;
if (priv->pll_desc->initdata) {
struct i2c_msg msg = { .flags = 0,
.addr = priv->pll_i2c_address,
.buf = priv->pll_desc->initdata + 1,
.len = priv->pll_desc->initdata[0] };
int result;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
result = i2c_transfer(priv->i2c, &msg, 1);
if (result != 1)
return result;
if (priv->pll_desc->initdata2) {
msg.buf = priv->pll_desc->initdata2 + 1;
msg.len = priv->pll_desc->initdata2[0];
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
result = i2c_transfer(priv->i2c, &msg, 1);
if (result != 1)
return result;
}
return 0;
}
return -EINVAL;
}
struct dvb_frontend *dvb_pll_attach(struct dvb_frontend *fe, int pll_addr,
struct i2c_adapter *i2c,
unsigned int pll_desc_id)
{
u8 b1 [] = { 0 };
struct i2c_msg msg = { .addr = pll_addr, .flags = I2C_M_RD,
.buf = b1, .len = 1 };
struct dvb_pll_priv *priv = NULL;
int ret;
const struct dvb_pll_desc *desc;
if ((id[dvb_pll_devcount] > DVB_PLL_UNDEFINED) &&
(id[dvb_pll_devcount] < ARRAY_SIZE(pll_list)))
pll_desc_id = id[dvb_pll_devcount];
BUG_ON(pll_desc_id < 1 || pll_desc_id >= ARRAY_SIZE(pll_list));
desc = pll_list[pll_desc_id];
if (i2c != NULL) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
ret = i2c_transfer (i2c, &msg, 1);
if (ret != 1)
return NULL;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
priv = kzalloc(sizeof(struct dvb_pll_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
priv->pll_i2c_address = pll_addr;
priv->i2c = i2c;
priv->pll_desc = desc;
priv->nr = dvb_pll_devcount++;
memcpy(&fe->ops.tuner_ops, &dvb_pll_tuner_ops,
sizeof(struct dvb_tuner_ops));
strncpy(fe->ops.tuner_ops.info.name, desc->name,
sizeof(fe->ops.tuner_ops.info.name));
fe->ops.tuner_ops.info.frequency_min = desc->min;
fe->ops.tuner_ops.info.frequency_max = desc->max;
if (!desc->initdata)
fe->ops.tuner_ops.init = NULL;
if (!desc->sleepdata)
fe->ops.tuner_ops.sleep = NULL;
fe->tuner_priv = priv;
if ((debug) || (id[priv->nr] == pll_desc_id)) {
printk("dvb-pll[%d]", priv->nr);
if (i2c != NULL)
printk(" %d-%04x", i2c_adapter_id(i2c), pll_addr);
printk(": id# %d (%s) attached, %s\n", pll_desc_id, desc->name,
id[priv->nr] == pll_desc_id ?
"insmod option" : "autodetected");
}
return fe;
}
