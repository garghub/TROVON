static int rtl2830_wr(struct rtl2830_priv *priv, u8 reg, const u8 *val, int len)
{
int ret;
u8 buf[1+len];
struct i2c_msg msg[1] = {
{
.addr = priv->cfg.i2c_addr,
.flags = 0,
.len = 1+len,
.buf = buf,
}
};
buf[0] = reg;
memcpy(&buf[1], val, len);
ret = i2c_transfer(priv->i2c, msg, 1);
if (ret == 1) {
ret = 0;
} else {
dev_warn(&priv->i2c->dev, "%s: i2c wr failed=%d reg=%02x " \
"len=%d\n", KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int rtl2830_rd(struct rtl2830_priv *priv, u8 reg, u8 *val, int len)
{
int ret;
struct i2c_msg msg[2] = {
{
.addr = priv->cfg.i2c_addr,
.flags = 0,
.len = 1,
.buf = &reg,
}, {
.addr = priv->cfg.i2c_addr,
.flags = I2C_M_RD,
.len = len,
.buf = val,
}
};
ret = i2c_transfer(priv->i2c, msg, 2);
if (ret == 2) {
ret = 0;
} else {
dev_warn(&priv->i2c->dev, "%s: i2c rd failed=%d reg=%02x " \
"len=%d\n", KBUILD_MODNAME, ret, reg, len);
ret = -EREMOTEIO;
}
return ret;
}
static int rtl2830_wr_regs(struct rtl2830_priv *priv, u16 reg, const u8 *val,
int len)
{
int ret;
u8 reg2 = (reg >> 0) & 0xff;
u8 page = (reg >> 8) & 0xff;
if (page != priv->page) {
ret = rtl2830_wr(priv, 0x00, &page, 1);
if (ret)
return ret;
priv->page = page;
}
return rtl2830_wr(priv, reg2, val, len);
}
static int rtl2830_rd_regs(struct rtl2830_priv *priv, u16 reg, u8 *val, int len)
{
int ret;
u8 reg2 = (reg >> 0) & 0xff;
u8 page = (reg >> 8) & 0xff;
if (page != priv->page) {
ret = rtl2830_wr(priv, 0x00, &page, 1);
if (ret)
return ret;
priv->page = page;
}
return rtl2830_rd(priv, reg2, val, len);
}
static int rtl2830_rd_reg(struct rtl2830_priv *priv, u16 reg, u8 *val)
{
return rtl2830_rd_regs(priv, reg, val, 1);
}
int rtl2830_wr_reg_mask(struct rtl2830_priv *priv, u16 reg, u8 val, u8 mask)
{
int ret;
u8 tmp;
if (mask != 0xff) {
ret = rtl2830_rd_regs(priv, reg, &tmp, 1);
if (ret)
return ret;
val &= mask;
tmp &= ~mask;
val |= tmp;
}
return rtl2830_wr_regs(priv, reg, &val, 1);
}
int rtl2830_rd_reg_mask(struct rtl2830_priv *priv, u16 reg, u8 *val, u8 mask)
{
int ret, i;
u8 tmp;
ret = rtl2830_rd_regs(priv, reg, &tmp, 1);
if (ret)
return ret;
tmp &= mask;
for (i = 0; i < 8; i++) {
if ((mask >> i) & 0x01)
break;
}
*val = tmp >> i;
return 0;
}
static int rtl2830_init(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
int ret, i;
struct rtl2830_reg_val_mask tab[] = {
{ 0x00d, 0x01, 0x03 },
{ 0x00d, 0x10, 0x10 },
{ 0x104, 0x00, 0x1e },
{ 0x105, 0x80, 0x80 },
{ 0x110, 0x02, 0x03 },
{ 0x110, 0x08, 0x0c },
{ 0x17b, 0x00, 0x40 },
{ 0x17d, 0x05, 0x0f },
{ 0x17d, 0x50, 0xf0 },
{ 0x18c, 0x08, 0x0f },
{ 0x18d, 0x00, 0xc0 },
{ 0x188, 0x05, 0x0f },
{ 0x189, 0x00, 0xfc },
{ 0x2d5, 0x02, 0x02 },
{ 0x2f1, 0x02, 0x06 },
{ 0x2f1, 0x20, 0xf8 },
{ 0x16d, 0x00, 0x01 },
{ 0x1a6, 0x00, 0x80 },
{ 0x106, priv->cfg.vtop, 0x3f },
{ 0x107, priv->cfg.krf, 0x3f },
{ 0x112, 0x28, 0xff },
{ 0x103, priv->cfg.agc_targ_val, 0xff },
{ 0x00a, 0x02, 0x07 },
{ 0x140, 0x0c, 0x3c },
{ 0x140, 0x40, 0xc0 },
{ 0x15b, 0x05, 0x07 },
{ 0x15b, 0x28, 0x38 },
{ 0x15c, 0x05, 0x07 },
{ 0x15c, 0x28, 0x38 },
{ 0x115, priv->cfg.spec_inv, 0x01 },
{ 0x16f, 0x01, 0x07 },
{ 0x170, 0x18, 0x38 },
{ 0x172, 0x0f, 0x0f },
{ 0x173, 0x08, 0x38 },
{ 0x175, 0x01, 0x07 },
{ 0x176, 0x00, 0xc0 },
};
for (i = 0; i < ARRAY_SIZE(tab); i++) {
ret = rtl2830_wr_reg_mask(priv, tab[i].reg, tab[i].val,
tab[i].mask);
if (ret)
goto err;
}
ret = rtl2830_wr_regs(priv, 0x18f, "\x28\x00", 2);
if (ret)
goto err;
ret = rtl2830_wr_regs(priv, 0x195,
"\x04\x06\x0a\x12\x0a\x12\x1e\x28", 8);
if (ret)
goto err;
ret = rtl2830_wr_reg_mask(priv, 0x101, 0x04, 0x04);
if (ret)
goto err;
ret = rtl2830_wr_reg_mask(priv, 0x101, 0x00, 0x04);
if (ret)
goto err;
priv->sleeping = false;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_sleep(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
priv->sleeping = true;
return 0;
}
int rtl2830_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *s)
{
s->min_delay_ms = 500;
s->step_size = fe->ops.info.frequency_stepsize * 2;
s->max_drift = (fe->ops.info.frequency_stepsize * 2) + 1;
return 0;
}
static int rtl2830_set_frontend(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
u64 num;
u8 buf[3], tmp;
u32 if_ctl, if_frequency;
static const u8 bw_params1[3][34] = {
{
0x1f, 0xf0, 0x1f, 0xf0, 0x1f, 0xfa, 0x00, 0x17, 0x00, 0x41,
0x00, 0x64, 0x00, 0x67, 0x00, 0x38, 0x1f, 0xde, 0x1f, 0x7a,
0x1f, 0x47, 0x1f, 0x7c, 0x00, 0x30, 0x01, 0x4b, 0x02, 0x82,
0x03, 0x73, 0x03, 0xcf,
}, {
0x1f, 0xfa, 0x1f, 0xda, 0x1f, 0xc1, 0x1f, 0xb3, 0x1f, 0xca,
0x00, 0x07, 0x00, 0x4d, 0x00, 0x6d, 0x00, 0x40, 0x1f, 0xca,
0x1f, 0x4d, 0x1f, 0x2a, 0x1f, 0xb2, 0x00, 0xec, 0x02, 0x7e,
0x03, 0xd0, 0x04, 0x53,
}, {
0x00, 0x10, 0x00, 0x0e, 0x1f, 0xf7, 0x1f, 0xc9, 0x1f, 0xa0,
0x1f, 0xa6, 0x1f, 0xec, 0x00, 0x4e, 0x00, 0x7d, 0x00, 0x3a,
0x1f, 0x98, 0x1f, 0x10, 0x1f, 0x40, 0x00, 0x75, 0x02, 0x5f,
0x04, 0x24, 0x04, 0xdb,
},
};
static const u8 bw_params2[3][6] = {
{0xc3, 0x0c, 0x44, 0x33, 0x33, 0x30},
{0xb8, 0xe3, 0x93, 0x99, 0x99, 0x98},
{0xae, 0xba, 0xf3, 0x26, 0x66, 0x64},
};
dev_dbg(&priv->i2c->dev,
"%s: frequency=%d bandwidth_hz=%d inversion=%d\n",
__func__, c->frequency, c->bandwidth_hz, c->inversion);
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
switch (c->bandwidth_hz) {
case 6000000:
i = 0;
break;
case 7000000:
i = 1;
break;
case 8000000:
i = 2;
break;
default:
dev_dbg(&priv->i2c->dev, "%s: invalid bandwidth\n", __func__);
return -EINVAL;
}
ret = rtl2830_wr_reg_mask(priv, 0x008, i << 1, 0x06);
if (ret)
goto err;
if (fe->ops.tuner_ops.get_if_frequency)
ret = fe->ops.tuner_ops.get_if_frequency(fe, &if_frequency);
else
ret = -EINVAL;
if (ret < 0)
goto err;
num = if_frequency % priv->cfg.xtal;
num *= 0x400000;
num = div_u64(num, priv->cfg.xtal);
num = -num;
if_ctl = num & 0x3fffff;
dev_dbg(&priv->i2c->dev, "%s: if_frequency=%d if_ctl=%08x\n",
__func__, if_frequency, if_ctl);
ret = rtl2830_rd_reg_mask(priv, 0x119, &tmp, 0xc0);
if (ret)
goto err;
buf[0] = tmp << 6;
buf[0] |= (if_ctl >> 16) & 0x3f;
buf[1] = (if_ctl >> 8) & 0xff;
buf[2] = (if_ctl >> 0) & 0xff;
ret = rtl2830_wr_regs(priv, 0x119, buf, 3);
if (ret)
goto err;
ret = rtl2830_wr_regs(priv, 0x11c, &bw_params1[i][0], 17);
if (ret)
goto err;
ret = rtl2830_wr_regs(priv, 0x12d, &bw_params1[i][17], 17);
if (ret)
goto err;
ret = rtl2830_wr_regs(priv, 0x19d, bw_params2[i], 6);
if (ret)
goto err;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_get_frontend(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
u8 buf[3];
if (priv->sleeping)
return 0;
ret = rtl2830_rd_regs(priv, 0x33c, buf, 2);
if (ret)
goto err;
ret = rtl2830_rd_reg(priv, 0x351, &buf[2]);
if (ret)
goto err;
dev_dbg(&priv->i2c->dev, "%s: TPS=%*ph\n", __func__, 3, buf);
switch ((buf[0] >> 2) & 3) {
case 0:
c->modulation = QPSK;
break;
case 1:
c->modulation = QAM_16;
break;
case 2:
c->modulation = QAM_64;
break;
}
switch ((buf[2] >> 2) & 1) {
case 0:
c->transmission_mode = TRANSMISSION_MODE_2K;
break;
case 1:
c->transmission_mode = TRANSMISSION_MODE_8K;
}
switch ((buf[2] >> 0) & 3) {
case 0:
c->guard_interval = GUARD_INTERVAL_1_32;
break;
case 1:
c->guard_interval = GUARD_INTERVAL_1_16;
break;
case 2:
c->guard_interval = GUARD_INTERVAL_1_8;
break;
case 3:
c->guard_interval = GUARD_INTERVAL_1_4;
break;
}
switch ((buf[0] >> 4) & 7) {
case 0:
c->hierarchy = HIERARCHY_NONE;
break;
case 1:
c->hierarchy = HIERARCHY_1;
break;
case 2:
c->hierarchy = HIERARCHY_2;
break;
case 3:
c->hierarchy = HIERARCHY_4;
break;
}
switch ((buf[1] >> 3) & 7) {
case 0:
c->code_rate_HP = FEC_1_2;
break;
case 1:
c->code_rate_HP = FEC_2_3;
break;
case 2:
c->code_rate_HP = FEC_3_4;
break;
case 3:
c->code_rate_HP = FEC_5_6;
break;
case 4:
c->code_rate_HP = FEC_7_8;
break;
}
switch ((buf[1] >> 0) & 7) {
case 0:
c->code_rate_LP = FEC_1_2;
break;
case 1:
c->code_rate_LP = FEC_2_3;
break;
case 2:
c->code_rate_LP = FEC_3_4;
break;
case 3:
c->code_rate_LP = FEC_5_6;
break;
case 4:
c->code_rate_LP = FEC_7_8;
break;
}
return 0;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
int ret;
u8 tmp;
*status = 0;
if (priv->sleeping)
return 0;
ret = rtl2830_rd_reg_mask(priv, 0x351, &tmp, 0x78);
if (ret)
goto err;
if (tmp == 11) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
} else if (tmp == 10) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI;
}
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
int ret, hierarchy, constellation;
u8 buf[2], tmp;
u16 tmp16;
#define CONSTELLATION_NUM 3
#define HIERARCHY_NUM 4
static const u32 snr_constant[CONSTELLATION_NUM][HIERARCHY_NUM] = {
{ 70705899, 70705899, 70705899, 70705899 },
{ 82433173, 82433173, 87483115, 94445660 },
{ 92888734, 92888734, 95487525, 99770748 },
};
if (priv->sleeping)
return 0;
ret = rtl2830_rd_reg(priv, 0x33c, &tmp);
if (ret)
goto err;
constellation = (tmp >> 2) & 0x03;
if (constellation > CONSTELLATION_NUM - 1)
goto err;
hierarchy = (tmp >> 4) & 0x07;
if (hierarchy > HIERARCHY_NUM - 1)
goto err;
ret = rtl2830_rd_regs(priv, 0x40c, buf, 2);
if (ret)
goto err;
tmp16 = buf[0] << 8 | buf[1];
if (tmp16)
*snr = (snr_constant[constellation][hierarchy] -
intlog10(tmp16)) / ((1 << 24) / 100);
else
*snr = 0;
return 0;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
int ret;
u8 buf[2];
if (priv->sleeping)
return 0;
ret = rtl2830_rd_regs(priv, 0x34e, buf, 2);
if (ret)
goto err;
*ber = buf[0] << 8 | buf[1];
return 0;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2830_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
*ucblocks = 0;
return 0;
}
static int rtl2830_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
int ret;
u8 buf[2];
u16 if_agc_raw, if_agc;
if (priv->sleeping)
return 0;
ret = rtl2830_rd_regs(priv, 0x359, buf, 2);
if (ret)
goto err;
if_agc_raw = (buf[0] << 8 | buf[1]) & 0x3fff;
if (if_agc_raw & (1 << 9))
if_agc = -(~(if_agc_raw - 1) & 0x1ff);
else
if_agc = if_agc_raw;
*strength = (u8) (55 - if_agc / 182);
*strength |= *strength << 8;
return 0;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static u32 rtl2830_tuner_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int rtl2830_tuner_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
struct rtl2830_priv *priv = i2c_get_adapdata(i2c_adap);
int ret;
ret = rtl2830_wr_reg_mask(priv, 0x101, 0x08, 0x08);
if (ret)
goto err;
ret = i2c_transfer(priv->i2c, msg, num);
if (ret < 0)
dev_warn(&priv->i2c->dev, "%s: tuner i2c failed=%d\n",
KBUILD_MODNAME, ret);
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
struct i2c_adapter *rtl2830_get_tuner_i2c_adapter(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
return &priv->tuner_i2c_adapter;
}
static void rtl2830_release(struct dvb_frontend *fe)
{
struct rtl2830_priv *priv = fe->demodulator_priv;
i2c_del_adapter(&priv->tuner_i2c_adapter);
kfree(priv);
}
struct dvb_frontend *rtl2830_attach(const struct rtl2830_config *cfg,
struct i2c_adapter *i2c)
{
struct rtl2830_priv *priv = NULL;
int ret = 0;
u8 tmp;
priv = kzalloc(sizeof(struct rtl2830_priv), GFP_KERNEL);
if (priv == NULL)
goto err;
priv->i2c = i2c;
memcpy(&priv->cfg, cfg, sizeof(struct rtl2830_config));
ret = rtl2830_rd_reg(priv, 0x000, &tmp);
if (ret)
goto err;
memcpy(&priv->fe.ops, &rtl2830_ops, sizeof(struct dvb_frontend_ops));
priv->fe.demodulator_priv = priv;
strlcpy(priv->tuner_i2c_adapter.name, "RTL2830 tuner I2C adapter",
sizeof(priv->tuner_i2c_adapter.name));
priv->tuner_i2c_adapter.algo = &rtl2830_tuner_i2c_algo;
priv->tuner_i2c_adapter.algo_data = NULL;
i2c_set_adapdata(&priv->tuner_i2c_adapter, priv);
if (i2c_add_adapter(&priv->tuner_i2c_adapter) < 0) {
dev_err(&i2c->dev,
"%s: tuner i2c bus could not be initialized\n",
KBUILD_MODNAME);
goto err;
}
priv->sleeping = true;
return &priv->fe;
err:
dev_dbg(&i2c->dev, "%s: failed=%d\n", __func__, ret);
kfree(priv);
return NULL;
}
