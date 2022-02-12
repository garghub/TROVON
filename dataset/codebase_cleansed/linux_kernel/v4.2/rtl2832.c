static int rtl2832_bulk_write(struct i2c_client *client, unsigned int reg,
const void *val, size_t val_count)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
int ret;
i2c_lock_adapter(client->adapter);
ret = regmap_bulk_write(dev->regmap, reg, val, val_count);
i2c_unlock_adapter(client->adapter);
return ret;
}
static int rtl2832_update_bits(struct i2c_client *client, unsigned int reg,
unsigned int mask, unsigned int val)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
int ret;
i2c_lock_adapter(client->adapter);
ret = regmap_update_bits(dev->regmap, reg, mask, val);
i2c_unlock_adapter(client->adapter);
return ret;
}
static int rtl2832_bulk_read(struct i2c_client *client, unsigned int reg,
void *val, size_t val_count)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
int ret;
i2c_lock_adapter(client->adapter);
ret = regmap_bulk_read(dev->regmap, reg, val, val_count);
i2c_unlock_adapter(client->adapter);
return ret;
}
static int rtl2832_rd_demod_reg(struct rtl2832_dev *dev, int reg, u32 *val)
{
struct i2c_client *client = dev->client;
int ret, i;
u16 reg_start_addr;
u8 msb, lsb, reading[4], len;
u32 reading_tmp, mask;
reg_start_addr = registers[reg].start_address;
msb = registers[reg].msb;
lsb = registers[reg].lsb;
len = (msb >> 3) + 1;
mask = REG_MASK(msb - lsb);
ret = rtl2832_bulk_read(client, reg_start_addr, reading, len);
if (ret)
goto err;
reading_tmp = 0;
for (i = 0; i < len; i++)
reading_tmp |= reading[i] << ((len - 1 - i) * 8);
*val = (reading_tmp >> lsb) & mask;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_wr_demod_reg(struct rtl2832_dev *dev, int reg, u32 val)
{
struct i2c_client *client = dev->client;
int ret, i;
u16 reg_start_addr;
u8 msb, lsb, reading[4], writing[4], len;
u32 reading_tmp, writing_tmp, mask;
reg_start_addr = registers[reg].start_address;
msb = registers[reg].msb;
lsb = registers[reg].lsb;
len = (msb >> 3) + 1;
mask = REG_MASK(msb - lsb);
ret = rtl2832_bulk_read(client, reg_start_addr, reading, len);
if (ret)
goto err;
reading_tmp = 0;
for (i = 0; i < len; i++)
reading_tmp |= reading[i] << ((len - 1 - i) * 8);
writing_tmp = reading_tmp & ~(mask << lsb);
writing_tmp |= ((val & mask) << lsb);
for (i = 0; i < len; i++)
writing[i] = (writing_tmp >> ((len - 1 - i) * 8)) & 0xff;
ret = rtl2832_bulk_write(client, reg_start_addr, writing, len);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_set_if(struct dvb_frontend *fe, u32 if_freq)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u64 pset_iffreq;
u8 en_bbin = (if_freq == 0 ? 0x1 : 0x0);
pset_iffreq = if_freq % dev->pdata->clk;
pset_iffreq *= 0x400000;
pset_iffreq = div_u64(pset_iffreq, dev->pdata->clk);
pset_iffreq = -pset_iffreq;
pset_iffreq = pset_iffreq & 0x3fffff;
dev_dbg(&client->dev, "if_frequency=%d pset_iffreq=%08x\n",
if_freq, (unsigned)pset_iffreq);
ret = rtl2832_wr_demod_reg(dev, DVBT_EN_BBIN, en_bbin);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_PSET_IFFREQ, pset_iffreq);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_init(struct dvb_frontend *fe)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &dev->fe.dtv_property_cache;
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
dev_dbg(&client->dev, "\n");
for (i = 0; i < ARRAY_SIZE(rtl2832_initial_regs); i++) {
ret = rtl2832_wr_demod_reg(dev, rtl2832_initial_regs[i].reg,
rtl2832_initial_regs[i].value);
if (ret)
goto err;
}
dev_dbg(&client->dev, "load settings for tuner=%02x\n",
dev->pdata->tuner);
switch (dev->pdata->tuner) {
case RTL2832_TUNER_FC2580:
len = ARRAY_SIZE(rtl2832_tuner_init_fc2580);
init = rtl2832_tuner_init_fc2580;
break;
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
case RTL2832_TUNER_R828D:
len = ARRAY_SIZE(rtl2832_tuner_init_r820t);
init = rtl2832_tuner_init_r820t;
break;
case RTL2832_TUNER_SI2157:
len = ARRAY_SIZE(rtl2832_tuner_init_si2157);
init = rtl2832_tuner_init_si2157;
break;
default:
ret = -EINVAL;
goto err;
}
for (i = 0; i < len; i++) {
ret = rtl2832_wr_demod_reg(dev, init[i].reg, init[i].value);
if (ret)
goto err;
}
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->cnr.len = 1;
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_error.len = 1;
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.len = 1;
c->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
schedule_delayed_work(&dev->stat_work, msecs_to_jiffies(2000));
dev->sleeping = false;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_sleep(struct dvb_frontend *fe)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
dev_dbg(&client->dev, "\n");
dev->sleeping = true;
cancel_delayed_work_sync(&dev->stat_work);
dev->fe_status = 0;
ret = rtl2832_wr_demod_reg(dev, DVBT_SOFT_RST, 0x1);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *s)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
dev_dbg(&client->dev, "\n");
s->min_delay_ms = 1000;
s->step_size = fe->ops.info.frequency_stepsize * 2;
s->max_drift = (fe->ops.info.frequency_stepsize * 2) + 1;
return 0;
}
static int rtl2832_set_frontend(struct dvb_frontend *fe)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
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
dev_dbg(&client->dev, "frequency=%u bandwidth_hz=%u inversion=%u\n",
c->frequency, c->bandwidth_hz, c->inversion);
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
ret = rtl2832_bulk_write(client, 0x192, "\x00\x0f\xff", 3);
if (ret)
goto err;
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
dev_err(&client->dev, "invalid bandwidth_hz %u\n",
c->bandwidth_hz);
ret = -EINVAL;
goto err;
}
for (j = 0; j < sizeof(bw_params[0]); j++) {
ret = rtl2832_bulk_write(client, 0x11c + j, &bw_params[i][j], 1);
if (ret)
goto err;
}
num = dev->pdata->clk * 7;
num *= 0x400000;
num = div_u64(num, bw_mode);
resamp_ratio = num & 0x3ffffff;
ret = rtl2832_wr_demod_reg(dev, DVBT_RSAMP_RATIO, resamp_ratio);
if (ret)
goto err;
num = bw_mode << 20;
num2 = dev->pdata->clk * 7;
num = div_u64(num, num2);
num = -num;
cfreq_off_ratio = num & 0xfffff;
ret = rtl2832_wr_demod_reg(dev, DVBT_CFREQ_OFF_RATIO, cfreq_off_ratio);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_SOFT_RST, 0x1);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_SOFT_RST, 0x0);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_get_frontend(struct dvb_frontend *fe)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret;
u8 buf[3];
if (dev->sleeping)
return 0;
ret = rtl2832_bulk_read(client, 0x33c, buf, 2);
if (ret)
goto err;
ret = rtl2832_bulk_read(client, 0x351, &buf[2], 1);
if (ret)
goto err;
dev_dbg(&client->dev, "TPS=%*ph\n", 3, buf);
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
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u32 uninitialized_var(tmp);
dev_dbg(&client->dev, "\n");
*status = 0;
if (dev->sleeping)
return 0;
ret = rtl2832_rd_demod_reg(dev, DVBT_FSM_STAGE, &tmp);
if (ret)
goto err;
if (tmp == 11) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
} else if (tmp == 10) {
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI;
}
dev->fe_status = *status;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->cnr.stat[0].scale == FE_SCALE_DECIBEL)
*snr = div_s64(c->cnr.stat[0].svalue, 100);
else
*snr = 0;
return 0;
}
static int rtl2832_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
*ber = (dev->post_bit_error - dev->post_bit_error_prev);
dev->post_bit_error_prev = dev->post_bit_error;
return 0;
}
static void rtl2832_stat_work(struct work_struct *work)
{
struct rtl2832_dev *dev = container_of(work, struct rtl2832_dev, stat_work.work);
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &dev->fe.dtv_property_cache;
int ret, tmp;
u8 u8tmp, buf[2];
u16 u16tmp;
dev_dbg(&client->dev, "\n");
if (dev->fe_status & FE_HAS_SIGNAL) {
ret = rtl2832_bulk_read(client, 0x305, &u8tmp, 1);
if (ret)
goto err;
dev_dbg(&client->dev, "digital agc=%02x", u8tmp);
u8tmp = ~u8tmp;
u16tmp = u8tmp << 8 | u8tmp << 0;
c->strength.stat[0].scale = FE_SCALE_RELATIVE;
c->strength.stat[0].uvalue = u16tmp;
} else {
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (dev->fe_status & FE_HAS_VITERBI) {
unsigned hierarchy, constellation;
#define CONSTELLATION_NUM 3
#define HIERARCHY_NUM 4
static const u32 constant[CONSTELLATION_NUM][HIERARCHY_NUM] = {
{85387325, 85387325, 85387325, 85387325},
{86676178, 86676178, 87167949, 87795660},
{87659938, 87659938, 87885178, 88241743},
};
ret = rtl2832_bulk_read(client, 0x33c, &u8tmp, 1);
if (ret)
goto err;
constellation = (u8tmp >> 2) & 0x03;
if (constellation > CONSTELLATION_NUM - 1)
goto err_schedule_delayed_work;
hierarchy = (u8tmp >> 4) & 0x07;
if (hierarchy > HIERARCHY_NUM - 1)
goto err_schedule_delayed_work;
ret = rtl2832_bulk_read(client, 0x40c, buf, 2);
if (ret)
goto err;
u16tmp = buf[0] << 8 | buf[1] << 0;
if (u16tmp)
tmp = (constant[constellation][hierarchy] -
intlog10(u16tmp)) / ((1 << 24) / 10000);
else
tmp = 0;
dev_dbg(&client->dev, "cnr raw=%u\n", u16tmp);
c->cnr.stat[0].scale = FE_SCALE_DECIBEL;
c->cnr.stat[0].svalue = tmp;
} else {
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (dev->fe_status & FE_HAS_LOCK) {
ret = rtl2832_bulk_read(client, 0x34e, buf, 2);
if (ret)
goto err;
u16tmp = buf[0] << 8 | buf[1] << 0;
dev->post_bit_error += u16tmp;
dev->post_bit_count += 1000000;
dev_dbg(&client->dev, "ber errors=%u total=1000000\n", u16tmp);
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue = dev->post_bit_error;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].uvalue = dev->post_bit_count;
} else {
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
err_schedule_delayed_work:
schedule_delayed_work(&dev->stat_work, msecs_to_jiffies(2000));
return;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
}
static void rtl2832_i2c_gate_work(struct work_struct *work)
{
struct rtl2832_dev *dev = container_of(work, struct rtl2832_dev, i2c_gate_work.work);
struct i2c_client *client = dev->client;
int ret;
ret = rtl2832_update_bits(dev->client, 0x101, 0x08, 0x00);
if (ret)
goto err;
return;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
}
static int rtl2832_select(struct i2c_adapter *adap, void *mux_priv, u32 chan_id)
{
struct rtl2832_dev *dev = mux_priv;
struct i2c_client *client = dev->client;
int ret;
cancel_delayed_work(&dev->i2c_gate_work);
ret = regmap_update_bits(dev->regmap, 0x101, 0x08, 0x08);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_deselect(struct i2c_adapter *adap, void *mux_priv,
u32 chan_id)
{
struct rtl2832_dev *dev = mux_priv;
schedule_delayed_work(&dev->i2c_gate_work, usecs_to_jiffies(100));
return 0;
}
static bool rtl2832_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case 0x305:
case 0x33c:
case 0x34e:
case 0x351:
case 0x40c ... 0x40d:
return true;
default:
break;
}
return false;
}
static int rtl2832_regmap_read(void *context, const void *reg_buf,
size_t reg_size, void *val_buf, size_t val_size)
{
struct i2c_client *client = context;
int ret;
struct i2c_msg msg[2] = {
{
.addr = client->addr,
.flags = 0,
.len = reg_size,
.buf = (u8 *)reg_buf,
}, {
.addr = client->addr,
.flags = I2C_M_RD,
.len = val_size,
.buf = val_buf,
}
};
ret = __i2c_transfer(client->adapter, msg, 2);
if (ret != 2) {
dev_warn(&client->dev, "i2c reg read failed %d\n", ret);
if (ret >= 0)
ret = -EREMOTEIO;
return ret;
}
return 0;
}
static int rtl2832_regmap_write(void *context, const void *data, size_t count)
{
struct i2c_client *client = context;
int ret;
struct i2c_msg msg[1] = {
{
.addr = client->addr,
.flags = 0,
.len = count,
.buf = (u8 *)data,
}
};
ret = __i2c_transfer(client->adapter, msg, 1);
if (ret != 1) {
dev_warn(&client->dev, "i2c reg write failed %d\n", ret);
if (ret >= 0)
ret = -EREMOTEIO;
return ret;
}
return 0;
}
static int rtl2832_regmap_gather_write(void *context, const void *reg,
size_t reg_len, const void *val,
size_t val_len)
{
struct i2c_client *client = context;
int ret;
u8 buf[256];
struct i2c_msg msg[1] = {
{
.addr = client->addr,
.flags = 0,
.len = 1 + val_len,
.buf = buf,
}
};
buf[0] = *(u8 const *)reg;
memcpy(&buf[1], val, val_len);
ret = __i2c_transfer(client->adapter, msg, 1);
if (ret != 1) {
dev_warn(&client->dev, "i2c reg write failed %d\n", ret);
if (ret >= 0)
ret = -EREMOTEIO;
return ret;
}
return 0;
}
static void rtl2832_regmap_lock(void *__dev)
{
struct rtl2832_dev *dev = __dev;
struct i2c_client *client = dev->client;
dev_dbg(&client->dev, "\n");
mutex_lock(&dev->regmap_mutex);
}
static void rtl2832_regmap_unlock(void *__dev)
{
struct rtl2832_dev *dev = __dev;
struct i2c_client *client = dev->client;
dev_dbg(&client->dev, "\n");
mutex_unlock(&dev->regmap_mutex);
}
static struct dvb_frontend *rtl2832_get_dvb_frontend(struct i2c_client *client)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
return &dev->fe;
}
static struct i2c_adapter *rtl2832_get_i2c_adapter(struct i2c_client *client)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
return dev->i2c_adapter_tuner;
}
static int rtl2832_enable_slave_ts(struct i2c_client *client)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
int ret;
dev_dbg(&client->dev, "\n");
ret = rtl2832_bulk_write(client, 0x10c, "\x5f\xff", 2);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_PIP_ON, 0x1);
if (ret)
goto err;
ret = rtl2832_bulk_write(client, 0x0bc, "\x18", 1);
if (ret)
goto err;
ret = rtl2832_bulk_write(client, 0x022, "\x01", 1);
if (ret)
goto err;
ret = rtl2832_bulk_write(client, 0x026, "\x1f", 1);
if (ret)
goto err;
ret = rtl2832_bulk_write(client, 0x027, "\xff", 1);
if (ret)
goto err;
ret = rtl2832_bulk_write(client, 0x192, "\x7f\xf7\xff", 3);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_SOFT_RST, 0x1);
if (ret)
goto err;
ret = rtl2832_wr_demod_reg(dev, DVBT_SOFT_RST, 0x0);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_pid_filter_ctrl(struct dvb_frontend *fe, int onoff)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u8 u8tmp;
dev_dbg(&client->dev, "onoff=%d\n", onoff);
if (onoff)
u8tmp = 0x80;
else
u8tmp = 0x00;
ret = rtl2832_update_bits(client, 0x061, 0xc0, u8tmp);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_pid_filter(struct dvb_frontend *fe, u8 index, u16 pid,
int onoff)
{
struct rtl2832_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u8 buf[4];
dev_dbg(&client->dev, "index=%d pid=%04x onoff=%d\n",
index, pid, onoff);
if (pid > 0x1fff || index > 32)
return 0;
if (onoff)
set_bit(index, &dev->filters);
else
clear_bit(index, &dev->filters);
buf[0] = (dev->filters >> 0) & 0xff;
buf[1] = (dev->filters >> 8) & 0xff;
buf[2] = (dev->filters >> 16) & 0xff;
buf[3] = (dev->filters >> 24) & 0xff;
ret = rtl2832_bulk_write(client, 0x062, buf, 4);
if (ret)
goto err;
buf[0] = (pid >> 8) & 0xff;
buf[1] = (pid >> 0) & 0xff;
ret = rtl2832_bulk_write(client, 0x066 + 2 * index, buf, 2);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rtl2832_platform_data *pdata = client->dev.platform_data;
struct i2c_adapter *i2c = client->adapter;
struct rtl2832_dev *dev;
int ret;
u8 tmp;
static const struct regmap_bus regmap_bus = {
.read = rtl2832_regmap_read,
.write = rtl2832_regmap_write,
.gather_write = rtl2832_regmap_gather_write,
.val_format_endian_default = REGMAP_ENDIAN_NATIVE,
};
static const struct regmap_range_cfg regmap_range_cfg[] = {
{
.selector_reg = 0x00,
.selector_mask = 0xff,
.selector_shift = 0,
.window_start = 0,
.window_len = 0x100,
.range_min = 0 * 0x100,
.range_max = 5 * 0x100,
},
};
dev_dbg(&client->dev, "\n");
dev = kzalloc(sizeof(struct rtl2832_dev), GFP_KERNEL);
if (dev == NULL) {
ret = -ENOMEM;
goto err;
}
i2c_set_clientdata(client, dev);
dev->client = client;
dev->pdata = client->dev.platform_data;
dev->sleeping = true;
INIT_DELAYED_WORK(&dev->i2c_gate_work, rtl2832_i2c_gate_work);
INIT_DELAYED_WORK(&dev->stat_work, rtl2832_stat_work);
mutex_init(&dev->regmap_mutex);
dev->regmap_config.reg_bits = 8,
dev->regmap_config.val_bits = 8,
dev->regmap_config.lock = rtl2832_regmap_lock,
dev->regmap_config.unlock = rtl2832_regmap_unlock,
dev->regmap_config.lock_arg = dev,
dev->regmap_config.volatile_reg = rtl2832_volatile_reg,
dev->regmap_config.max_register = 5 * 0x100,
dev->regmap_config.ranges = regmap_range_cfg,
dev->regmap_config.num_ranges = ARRAY_SIZE(regmap_range_cfg),
dev->regmap_config.cache_type = REGCACHE_NONE,
dev->regmap = regmap_init(&client->dev, &regmap_bus, client,
&dev->regmap_config);
if (IS_ERR(dev->regmap)) {
ret = PTR_ERR(dev->regmap);
goto err_kfree;
}
ret = rtl2832_bulk_read(client, 0x000, &tmp, 1);
if (ret)
goto err_regmap_exit;
dev->i2c_adapter_tuner = i2c_add_mux_adapter(i2c, &i2c->dev, dev,
0, 0, 0, rtl2832_select, rtl2832_deselect);
if (dev->i2c_adapter_tuner == NULL) {
ret = -ENODEV;
goto err_regmap_exit;
}
memcpy(&dev->fe.ops, &rtl2832_ops, sizeof(struct dvb_frontend_ops));
dev->fe.demodulator_priv = dev;
pdata->get_dvb_frontend = rtl2832_get_dvb_frontend;
pdata->get_i2c_adapter = rtl2832_get_i2c_adapter;
pdata->enable_slave_ts = rtl2832_enable_slave_ts;
pdata->pid_filter = rtl2832_pid_filter;
pdata->pid_filter_ctrl = rtl2832_pid_filter_ctrl;
pdata->bulk_read = rtl2832_bulk_read;
pdata->bulk_write = rtl2832_bulk_write;
pdata->update_bits = rtl2832_update_bits;
dev_info(&client->dev, "Realtek RTL2832 successfully attached\n");
return 0;
err_regmap_exit:
regmap_exit(dev->regmap);
err_kfree:
kfree(dev);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int rtl2832_remove(struct i2c_client *client)
{
struct rtl2832_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
cancel_delayed_work_sync(&dev->i2c_gate_work);
i2c_del_mux_adapter(dev->i2c_adapter_tuner);
regmap_exit(dev->regmap);
kfree(dev);
return 0;
}
