static int rtl2832_wr(struct rtl2832_priv *priv, u8 reg, u8 *val, int len)
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
static int rtl2832_rd(struct rtl2832_priv *priv, u8 reg, u8 *val, int len)
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
static int rtl2832_wr_regs(struct rtl2832_priv *priv, u8 reg, u8 page, u8 *val,
int len)
{
int ret;
if (page != priv->page) {
ret = rtl2832_wr(priv, 0x00, &page, 1);
if (ret)
return ret;
priv->page = page;
}
return rtl2832_wr(priv, reg, val, len);
}
static int rtl2832_rd_regs(struct rtl2832_priv *priv, u8 reg, u8 page, u8 *val,
int len)
{
int ret;
if (page != priv->page) {
ret = rtl2832_wr(priv, 0x00, &page, 1);
if (ret)
return ret;
priv->page = page;
}
return rtl2832_rd(priv, reg, val, len);
}
static int rtl2832_rd_reg(struct rtl2832_priv *priv, u8 reg, u8 page, u8 *val)
{
return rtl2832_rd_regs(priv, reg, page, val, 1);
}
static int rtl2832_rd_demod_reg(struct rtl2832_priv *priv, int reg, u32 *val)
{
int ret;
u8 reg_start_addr;
u8 msb, lsb;
u8 page;
u8 reading[4];
u32 reading_tmp;
int i;
u8 len;
u32 mask;
reg_start_addr = registers[reg].start_address;
msb = registers[reg].msb;
lsb = registers[reg].lsb;
page = registers[reg].page;
len = (msb >> 3) + 1;
mask = REG_MASK(msb - lsb);
ret = rtl2832_rd_regs(priv, reg_start_addr, page, &reading[0], len);
if (ret)
goto err;
reading_tmp = 0;
for (i = 0; i < len; i++)
reading_tmp |= reading[i] << ((len - 1 - i) * 8);
*val = (reading_tmp >> lsb) & mask;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_wr_demod_reg(struct rtl2832_priv *priv, int reg, u32 val)
{
int ret, i;
u8 len;
u8 reg_start_addr;
u8 msb, lsb;
u8 page;
u32 mask;
u8 reading[4];
u8 writing[4];
u32 reading_tmp;
u32 writing_tmp;
reg_start_addr = registers[reg].start_address;
msb = registers[reg].msb;
lsb = registers[reg].lsb;
page = registers[reg].page;
len = (msb >> 3) + 1;
mask = REG_MASK(msb - lsb);
ret = rtl2832_rd_regs(priv, reg_start_addr, page, &reading[0], len);
if (ret)
goto err;
reading_tmp = 0;
for (i = 0; i < len; i++)
reading_tmp |= reading[i] << ((len - 1 - i) * 8);
writing_tmp = reading_tmp & ~(mask << lsb);
writing_tmp |= ((val & mask) << lsb);
for (i = 0; i < len; i++)
writing[i] = (writing_tmp >> ((len - 1 - i) * 8)) & 0xff;
ret = rtl2832_wr_regs(priv, reg_start_addr, page, &writing[0], len);
if (ret)
goto err;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
int ret;
struct rtl2832_priv *priv = fe->demodulator_priv;
dev_dbg(&priv->i2c->dev, "%s: enable=%d\n", __func__, enable);
if (priv->i2c_gate_state == enable)
return 0;
ret = rtl2832_wr_demod_reg(priv, DVBT_IIC_REPEAT, (enable ? 0x1 : 0x0));
if (ret)
goto err;
priv->i2c_gate_state = enable;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_set_if(struct dvb_frontend *fe, u32 if_freq)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
int ret;
u64 pset_iffreq;
u8 en_bbin = (if_freq == 0 ? 0x1 : 0x0);
pset_iffreq = if_freq % priv->cfg.xtal;
pset_iffreq *= 0x400000;
pset_iffreq = div_u64(pset_iffreq, priv->cfg.xtal);
pset_iffreq = -pset_iffreq;
pset_iffreq = pset_iffreq & 0x3fffff;
dev_dbg(&priv->i2c->dev, "%s: if_frequency=%d pset_iffreq=%08x\n",
__func__, if_freq, (unsigned)pset_iffreq);
ret = rtl2832_wr_demod_reg(priv, DVBT_EN_BBIN, en_bbin);
if (ret)
return ret;
ret = rtl2832_wr_demod_reg(priv, DVBT_PSET_IFFREQ, pset_iffreq);
return (ret);
}
static int rtl2832_init(struct dvb_frontend *fe)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
const struct rtl2832_reg_value *init;
int i, ret, len;
struct rtl2832_reg_value rtl2832_initial_regs[] = {
{DVBT_AD_EN_REG, 0x1},
{DVBT_AD_EN_REG1, 0x1},
{DVBT_RSD_BER_FAIL_VAL, 0x2800},
{DVBT_MGD_THD0, 0x10},
{DVBT_MGD_THD1, 0x20},
{DVBT_MGD_THD2, 0x20},
{DVBT_MGD_THD3, 0x40},
{DVBT_MGD_THD4, 0x22},
{DVBT_MGD_THD5, 0x32},
{DVBT_MGD_THD6, 0x37},
{DVBT_MGD_THD7, 0x39},
{DVBT_EN_BK_TRK, 0x0},
{DVBT_EN_CACQ_NOTCH, 0x0},
{DVBT_AD_AV_REF, 0x2a},
{DVBT_REG_PI, 0x6},
{DVBT_PIP_ON, 0x0},
{DVBT_CDIV_PH0, 0x8},
{DVBT_CDIV_PH1, 0x8},
{DVBT_SCALE1_B92, 0x4},
{DVBT_SCALE1_B93, 0xb0},
{DVBT_SCALE1_BA7, 0x78},
{DVBT_SCALE1_BA9, 0x28},
{DVBT_SCALE1_BAA, 0x59},
{DVBT_SCALE1_BAB, 0x83},
{DVBT_SCALE1_BAC, 0xd4},
{DVBT_SCALE1_BB0, 0x65},
{DVBT_SCALE1_BB1, 0x43},
{DVBT_KB_P1, 0x1},
{DVBT_KB_P2, 0x4},
{DVBT_KB_P3, 0x7},
{DVBT_K1_CR_STEP12, 0xa},
{DVBT_REG_GPE, 0x1},
{DVBT_SERIAL, 0x0},
{DVBT_CDIV_PH0, 0x9},
{DVBT_CDIV_PH1, 0x9},
{DVBT_MPEG_IO_OPT_2_2, 0x0},
{DVBT_MPEG_IO_OPT_1_0, 0x0},
{DVBT_TRK_KS_P2, 0x4},
{DVBT_TRK_KS_I2, 0x7},
{DVBT_TR_THD_SET2, 0x6},
{DVBT_TRK_KC_I2, 0x5},
{DVBT_CR_THD_SET2, 0x1},
};
dev_dbg(&priv->i2c->dev, "%s:\n", __func__);
for (i = 0; i < ARRAY_SIZE(rtl2832_initial_regs); i++) {
ret = rtl2832_wr_demod_reg(priv, rtl2832_initial_regs[i].reg,
rtl2832_initial_regs[i].value);
if (ret)
goto err;
}
dev_dbg(&priv->i2c->dev, "%s: load settings for tuner=%02x\n",
__func__, priv->cfg.tuner);
switch (priv->cfg.tuner) {
case RTL2832_TUNER_FC0012:
case RTL2832_TUNER_FC0013:
len = ARRAY_SIZE(rtl2832_tuner_init_fc0012);
init = rtl2832_tuner_init_fc0012;
break;
case RTL2832_TUNER_TUA9001:
len = ARRAY_SIZE(rtl2832_tuner_init_tua9001);
init = rtl2832_tuner_init_tua9001;
break;
case RTL2832_TUNER_E4000:
len = ARRAY_SIZE(rtl2832_tuner_init_e4000);
init = rtl2832_tuner_init_e4000;
break;
case RTL2832_TUNER_R820T:
len = ARRAY_SIZE(rtl2832_tuner_init_r820t);
init = rtl2832_tuner_init_r820t;
break;
default:
ret = -EINVAL;
goto err;
}
for (i = 0; i < len; i++) {
ret = rtl2832_wr_demod_reg(priv, init[i].reg, init[i].value);
if (ret)
goto err;
}
if (!fe->ops.tuner_ops.get_if_frequency) {
ret = rtl2832_set_if(fe, priv->cfg.if_dvbt);
if (ret)
goto err;
}
#if 1
ret = rtl2832_wr_demod_reg(priv, DVBT_SOFT_RST, 0x1);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(priv, DVBT_SOFT_RST, 0x0);
if (ret)
goto err;
#endif
priv->sleeping = false;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_sleep(struct dvb_frontend *fe)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
dev_dbg(&priv->i2c->dev, "%s:\n", __func__);
priv->sleeping = true;
return 0;
}
static int rtl2832_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *s)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
dev_dbg(&priv->i2c->dev, "%s:\n", __func__);
s->min_delay_ms = 1000;
s->step_size = fe->ops.info.frequency_stepsize * 2;
s->max_drift = (fe->ops.info.frequency_stepsize * 2) + 1;
return 0;
}
static int rtl2832_set_frontend(struct dvb_frontend *fe)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i, j;
u64 bw_mode, num, num2;
u32 resamp_ratio, cfreq_off_ratio;
static u8 bw_params[3][32] = {
{
0xf5, 0xff, 0x15, 0x38, 0x5d, 0x6d, 0x52, 0x07, 0xfa, 0x2f,
0x53, 0xf5, 0x3f, 0xca, 0x0b, 0x91, 0xea, 0x30, 0x63, 0xb2,
0x13, 0xda, 0x0b, 0xc4, 0x18, 0x7e, 0x16, 0x66, 0x08, 0x67,
0x19, 0xe0,
},
{
0xe7, 0xcc, 0xb5, 0xba, 0xe8, 0x2f, 0x67, 0x61, 0x00, 0xaf,
0x86, 0xf2, 0xbf, 0x59, 0x04, 0x11, 0xb6, 0x33, 0xa4, 0x30,
0x15, 0x10, 0x0a, 0x42, 0x18, 0xf8, 0x17, 0xd9, 0x07, 0x22,
0x19, 0x10,
},
{
0x09, 0xf6, 0xd2, 0xa7, 0x9a, 0xc9, 0x27, 0x77, 0x06, 0xbf,
0xec, 0xf4, 0x4f, 0x0b, 0xfc, 0x01, 0x63, 0x35, 0x54, 0xa7,
0x16, 0x66, 0x08, 0xb4, 0x19, 0x6e, 0x19, 0x65, 0x05, 0xc8,
0x19, 0xe0,
},
};
dev_dbg(&priv->i2c->dev, "%s: frequency=%d bandwidth_hz=%d " \
"inversion=%d\n", __func__, c->frequency,
c->bandwidth_hz, c->inversion);
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.tuner_ops.get_if_frequency) {
u32 if_freq;
ret = fe->ops.tuner_ops.get_if_frequency(fe, &if_freq);
if (ret)
goto err;
ret = rtl2832_set_if(fe, if_freq);
if (ret)
goto err;
}
switch (c->bandwidth_hz) {
case 6000000:
i = 0;
bw_mode = 48000000;
break;
case 7000000:
i = 1;
bw_mode = 56000000;
break;
case 8000000:
i = 2;
bw_mode = 64000000;
break;
default:
dev_dbg(&priv->i2c->dev, "%s: invalid bandwidth\n", __func__);
return -EINVAL;
}
for (j = 0; j < sizeof(bw_params[0]); j++) {
ret = rtl2832_wr_regs(priv, 0x1c+j, 1, &bw_params[i][j], 1);
if (ret)
goto err;
}
num = priv->cfg.xtal * 7;
num *= 0x400000;
num = div_u64(num, bw_mode);
resamp_ratio = num & 0x3ffffff;
ret = rtl2832_wr_demod_reg(priv, DVBT_RSAMP_RATIO, resamp_ratio);
if (ret)
goto err;
num = bw_mode << 20;
num2 = priv->cfg.xtal * 7;
num = div_u64(num, num2);
num = -num;
cfreq_off_ratio = num & 0xfffff;
ret = rtl2832_wr_demod_reg(priv, DVBT_CFREQ_OFF_RATIO, cfreq_off_ratio);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(priv, DVBT_SOFT_RST, 0x1);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(priv, DVBT_SOFT_RST, 0x0);
if (ret)
goto err;
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_get_frontend(struct dvb_frontend *fe)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
u8 buf[3];
if (priv->sleeping)
return 0;
ret = rtl2832_rd_regs(priv, 0x3c, 3, buf, 2);
if (ret)
goto err;
ret = rtl2832_rd_reg(priv, 0x51, 3, &buf[2]);
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
static int rtl2832_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
int ret;
u32 tmp;
*status = 0;
dev_dbg(&priv->i2c->dev, "%s:\n", __func__);
if (priv->sleeping)
return 0;
ret = rtl2832_rd_demod_reg(priv, DVBT_FSM_STAGE, &tmp);
if (ret)
goto err;
if (tmp == 11) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
}
return ret;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static int rtl2832_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
int ret, hierarchy, constellation;
u8 buf[2], tmp;
u16 tmp16;
#define CONSTELLATION_NUM 3
#define HIERARCHY_NUM 4
static const u32 snr_constant[CONSTELLATION_NUM][HIERARCHY_NUM] = {
{ 85387325, 85387325, 85387325, 85387325 },
{ 86676178, 86676178, 87167949, 87795660 },
{ 87659938, 87659938, 87885178, 88241743 },
};
ret = rtl2832_rd_reg(priv, 0x3c, 3, &tmp);
if (ret)
goto err;
constellation = (tmp >> 2) & 0x03;
if (constellation > CONSTELLATION_NUM - 1)
goto err;
hierarchy = (tmp >> 4) & 0x07;
if (hierarchy > HIERARCHY_NUM - 1)
goto err;
ret = rtl2832_rd_regs(priv, 0x0c, 4, buf, 2);
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
static int rtl2832_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
int ret;
u8 buf[2];
ret = rtl2832_rd_regs(priv, 0x4e, 3, buf, 2);
if (ret)
goto err;
*ber = buf[0] << 8 | buf[1];
return 0;
err:
dev_dbg(&priv->i2c->dev, "%s: failed=%d\n", __func__, ret);
return ret;
}
static void rtl2832_release(struct dvb_frontend *fe)
{
struct rtl2832_priv *priv = fe->demodulator_priv;
dev_dbg(&priv->i2c->dev, "%s:\n", __func__);
kfree(priv);
}
struct dvb_frontend *rtl2832_attach(const struct rtl2832_config *cfg,
struct i2c_adapter *i2c)
{
struct rtl2832_priv *priv = NULL;
int ret = 0;
u8 tmp;
dev_dbg(&i2c->dev, "%s:\n", __func__);
priv = kzalloc(sizeof(struct rtl2832_priv), GFP_KERNEL);
if (priv == NULL)
goto err;
priv->i2c = i2c;
priv->tuner = cfg->tuner;
memcpy(&priv->cfg, cfg, sizeof(struct rtl2832_config));
ret = rtl2832_rd_reg(priv, 0x00, 0x0, &tmp);
if (ret)
goto err;
memcpy(&priv->fe.ops, &rtl2832_ops, sizeof(struct dvb_frontend_ops));
priv->fe.demodulator_priv = priv;
priv->sleeping = true;
return &priv->fe;
err:
dev_dbg(&i2c->dev, "%s: failed=%d\n", __func__, ret);
kfree(priv);
return NULL;
}
