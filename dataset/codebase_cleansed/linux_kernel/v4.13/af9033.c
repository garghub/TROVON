static int af9033_wr_reg_val_tab(struct af9033_dev *dev,
const struct reg_val *tab, int tab_len)
{
struct i2c_client *client = dev->client;
#define MAX_TAB_LEN 212
int ret, i, j;
u8 buf[1 + MAX_TAB_LEN];
dev_dbg(&client->dev, "tab_len=%d\n", tab_len);
if (tab_len > sizeof(buf)) {
dev_warn(&client->dev, "tab len %d is too big\n", tab_len);
return -EINVAL;
}
for (i = 0, j = 0; i < tab_len; i++) {
buf[j] = tab[i].val;
if (i == tab_len - 1 || tab[i].reg != tab[i + 1].reg - 1) {
ret = regmap_bulk_write(dev->regmap, tab[i].reg - j,
buf, j + 1);
if (ret)
goto err;
j = 0;
} else {
j++;
}
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_init(struct dvb_frontend *fe)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i, len;
unsigned int utmp;
const struct reg_val *init;
u8 buf[4];
struct reg_val_mask tab[] = {
{ 0x80fb24, 0x00, 0x08 },
{ 0x80004c, 0x00, 0xff },
{ 0x00f641, dev->cfg.tuner, 0xff },
{ 0x80f5ca, 0x01, 0x01 },
{ 0x80f715, 0x01, 0x01 },
{ 0x00f41f, 0x04, 0x04 },
{ 0x00f41a, 0x01, 0x01 },
{ 0x80f731, 0x00, 0x01 },
{ 0x00d91e, 0x00, 0x01 },
{ 0x00d919, 0x00, 0x01 },
{ 0x80f732, 0x00, 0x01 },
{ 0x00d91f, 0x00, 0x01 },
{ 0x00d91a, 0x00, 0x01 },
{ 0x80f730, 0x00, 0x01 },
{ 0x80f778, 0x00, 0xff },
{ 0x80f73c, 0x01, 0x01 },
{ 0x80f776, 0x00, 0x01 },
{ 0x00d8fd, 0x01, 0xff },
{ 0x00d830, 0x01, 0xff },
{ 0x00d831, 0x00, 0xff },
{ 0x00d832, 0x00, 0xff },
{ 0x80f985, dev->ts_mode_serial, 0x01 },
{ 0x80f986, dev->ts_mode_parallel, 0x01 },
{ 0x00d827, 0x00, 0xff },
{ 0x00d829, 0x00, 0xff },
{ 0x800045, dev->cfg.adc_multiplier, 0xff },
};
dev_dbg(&client->dev, "\n");
utmp = div_u64((u64)dev->cfg.clock * 0x80000, 1000000);
buf[0] = (utmp >> 0) & 0xff;
buf[1] = (utmp >> 8) & 0xff;
buf[2] = (utmp >> 16) & 0xff;
buf[3] = (utmp >> 24) & 0xff;
ret = regmap_bulk_write(dev->regmap, 0x800025, buf, 4);
if (ret)
goto err;
dev_dbg(&client->dev, "clk=%u clk_cw=%08x\n", dev->cfg.clock, utmp);
for (i = 0; i < ARRAY_SIZE(clock_adc_lut); i++) {
if (clock_adc_lut[i].clock == dev->cfg.clock)
break;
}
if (i == ARRAY_SIZE(clock_adc_lut)) {
dev_err(&client->dev, "Couldn't find ADC config for clock %d\n",
dev->cfg.clock);
goto err;
}
utmp = div_u64((u64)clock_adc_lut[i].adc * 0x80000, 1000000);
buf[0] = (utmp >> 0) & 0xff;
buf[1] = (utmp >> 8) & 0xff;
buf[2] = (utmp >> 16) & 0xff;
ret = regmap_bulk_write(dev->regmap, 0x80f1cd, buf, 3);
if (ret)
goto err;
dev_dbg(&client->dev, "adc=%u adc_cw=%06x\n",
clock_adc_lut[i].adc, utmp);
for (i = 0; i < ARRAY_SIZE(tab); i++) {
ret = regmap_update_bits(dev->regmap, tab[i].reg, tab[i].mask,
tab[i].val);
if (ret)
goto err;
}
if (dev->cfg.dyn0_clk) {
ret = regmap_write(dev->regmap, 0x80fba8, 0x00);
if (ret)
goto err;
}
if (dev->cfg.ts_mode == AF9033_TS_MODE_USB) {
ret = regmap_update_bits(dev->regmap, 0x80f9a5, 0x01, 0x00);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x80f9b5, 0x01, 0x01);
if (ret)
goto err;
} else {
ret = regmap_update_bits(dev->regmap, 0x80f990, 0x01, 0x00);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x80f9b5, 0x01, 0x00);
if (ret)
goto err;
}
dev_dbg(&client->dev, "load ofsm settings\n");
switch (dev->cfg.tuner) {
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
len = ARRAY_SIZE(ofsm_init_it9135_v1);
init = ofsm_init_it9135_v1;
break;
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
len = ARRAY_SIZE(ofsm_init_it9135_v2);
init = ofsm_init_it9135_v2;
break;
default:
len = ARRAY_SIZE(ofsm_init);
init = ofsm_init;
break;
}
ret = af9033_wr_reg_val_tab(dev, init, len);
if (ret)
goto err;
dev_dbg(&client->dev, "load tuner specific settings\n");
switch (dev->cfg.tuner) {
case AF9033_TUNER_TUA9001:
len = ARRAY_SIZE(tuner_init_tua9001);
init = tuner_init_tua9001;
break;
case AF9033_TUNER_FC0011:
len = ARRAY_SIZE(tuner_init_fc0011);
init = tuner_init_fc0011;
break;
case AF9033_TUNER_MXL5007T:
len = ARRAY_SIZE(tuner_init_mxl5007t);
init = tuner_init_mxl5007t;
break;
case AF9033_TUNER_TDA18218:
len = ARRAY_SIZE(tuner_init_tda18218);
init = tuner_init_tda18218;
break;
case AF9033_TUNER_FC2580:
len = ARRAY_SIZE(tuner_init_fc2580);
init = tuner_init_fc2580;
break;
case AF9033_TUNER_FC0012:
len = ARRAY_SIZE(tuner_init_fc0012);
init = tuner_init_fc0012;
break;
case AF9033_TUNER_IT9135_38:
len = ARRAY_SIZE(tuner_init_it9135_38);
init = tuner_init_it9135_38;
break;
case AF9033_TUNER_IT9135_51:
len = ARRAY_SIZE(tuner_init_it9135_51);
init = tuner_init_it9135_51;
break;
case AF9033_TUNER_IT9135_52:
len = ARRAY_SIZE(tuner_init_it9135_52);
init = tuner_init_it9135_52;
break;
case AF9033_TUNER_IT9135_60:
len = ARRAY_SIZE(tuner_init_it9135_60);
init = tuner_init_it9135_60;
break;
case AF9033_TUNER_IT9135_61:
len = ARRAY_SIZE(tuner_init_it9135_61);
init = tuner_init_it9135_61;
break;
case AF9033_TUNER_IT9135_62:
len = ARRAY_SIZE(tuner_init_it9135_62);
init = tuner_init_it9135_62;
break;
default:
dev_dbg(&client->dev, "unsupported tuner ID=%d\n",
dev->cfg.tuner);
ret = -ENODEV;
goto err;
}
ret = af9033_wr_reg_val_tab(dev, init, len);
if (ret)
goto err;
if (dev->cfg.ts_mode == AF9033_TS_MODE_SERIAL) {
ret = regmap_update_bits(dev->regmap, 0x00d91c, 0x01, 0x01);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x00d917, 0x01, 0x00);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x00d916, 0x01, 0x00);
if (ret)
goto err;
}
switch (dev->cfg.tuner) {
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
ret = regmap_write(dev->regmap, 0x800000, 0x01);
if (ret)
goto err;
}
dev->bandwidth_hz = 0;
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->cnr.len = 1;
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.len = 1;
c->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_error.len = 1;
c->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.len = 1;
c->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_error.len = 1;
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_sleep(struct dvb_frontend *fe)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
unsigned int utmp;
dev_dbg(&client->dev, "\n");
ret = regmap_write(dev->regmap, 0x80004c, 0x01);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x800000, 0x00);
if (ret)
goto err;
ret = regmap_read_poll_timeout(dev->regmap, 0x80004c, utmp, utmp == 0,
5000, 1000000);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x80fb24, 0x08, 0x08);
if (ret)
goto err;
if (dev->cfg.ts_mode == AF9033_TS_MODE_SERIAL) {
ret = regmap_update_bits(dev->regmap, 0x00d917, 0x01, 0x00);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x00d916, 0x01, 0x01);
if (ret)
goto err;
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *fesettings)
{
fesettings->min_delay_ms = 2000;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static int af9033_set_frontend(struct dvb_frontend *fe)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, i;
unsigned int utmp, adc_freq;
u8 tmp, buf[3], bandwidth_reg_val;
u32 if_frequency;
dev_dbg(&client->dev, "frequency=%u bandwidth_hz=%u\n",
c->frequency, c->bandwidth_hz);
switch (c->bandwidth_hz) {
case 6000000:
bandwidth_reg_val = 0x00;
break;
case 7000000:
bandwidth_reg_val = 0x01;
break;
case 8000000:
bandwidth_reg_val = 0x02;
break;
default:
dev_dbg(&client->dev, "invalid bandwidth_hz\n");
ret = -EINVAL;
goto err;
}
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
if (c->bandwidth_hz != dev->bandwidth_hz) {
for (i = 0; i < ARRAY_SIZE(coeff_lut); i++) {
if (coeff_lut[i].clock == dev->cfg.clock &&
coeff_lut[i].bandwidth_hz == c->bandwidth_hz) {
break;
}
}
if (i == ARRAY_SIZE(coeff_lut)) {
dev_err(&client->dev,
"Couldn't find config for clock %u\n",
dev->cfg.clock);
ret = -EINVAL;
goto err;
}
ret = regmap_bulk_write(dev->regmap, 0x800001, coeff_lut[i].val,
sizeof(coeff_lut[i].val));
if (ret)
goto err;
}
if (c->bandwidth_hz != dev->bandwidth_hz) {
for (i = 0; i < ARRAY_SIZE(clock_adc_lut); i++) {
if (clock_adc_lut[i].clock == dev->cfg.clock)
break;
}
if (i == ARRAY_SIZE(clock_adc_lut)) {
dev_err(&client->dev,
"Couldn't find ADC clock for clock %u\n",
dev->cfg.clock);
ret = -EINVAL;
goto err;
}
adc_freq = clock_adc_lut[i].adc;
if (dev->cfg.adc_multiplier == AF9033_ADC_MULTIPLIER_2X)
adc_freq = 2 * adc_freq;
if (fe->ops.tuner_ops.get_if_frequency)
fe->ops.tuner_ops.get_if_frequency(fe, &if_frequency);
else
if_frequency = 0;
utmp = DIV_ROUND_CLOSEST_ULL((u64)if_frequency * 0x800000,
adc_freq);
if (!dev->cfg.spec_inv && if_frequency)
utmp = 0x800000 - utmp;
buf[0] = (utmp >> 0) & 0xff;
buf[1] = (utmp >> 8) & 0xff;
buf[2] = (utmp >> 16) & 0xff;
ret = regmap_bulk_write(dev->regmap, 0x800029, buf, 3);
if (ret)
goto err;
dev_dbg(&client->dev, "if_frequency_cw=%06x\n", utmp);
dev->bandwidth_hz = c->bandwidth_hz;
}
ret = regmap_update_bits(dev->regmap, 0x80f904, 0x03,
bandwidth_reg_val);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x800040, 0x00);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x800047, 0x00);
if (ret)
goto err;
ret = regmap_update_bits(dev->regmap, 0x80f999, 0x01, 0x00);
if (ret)
goto err;
if (c->frequency <= 230000000)
tmp = 0x00;
else
tmp = 0x01;
ret = regmap_write(dev->regmap, 0x80004b, tmp);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x800000, 0x00);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *c)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u8 buf[8];
dev_dbg(&client->dev, "\n");
ret = regmap_bulk_read(dev->regmap, 0x80f900, buf, 8);
if (ret)
goto err;
switch ((buf[0] >> 0) & 3) {
case 0:
c->transmission_mode = TRANSMISSION_MODE_2K;
break;
case 1:
c->transmission_mode = TRANSMISSION_MODE_8K;
break;
}
switch ((buf[1] >> 0) & 3) {
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
switch ((buf[2] >> 0) & 7) {
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
switch ((buf[3] >> 0) & 3) {
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
switch ((buf[4] >> 0) & 3) {
case 0:
c->bandwidth_hz = 6000000;
break;
case 1:
c->bandwidth_hz = 7000000;
break;
case 2:
c->bandwidth_hz = 8000000;
break;
}
switch ((buf[6] >> 0) & 7) {
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
case 5:
c->code_rate_HP = FEC_NONE;
break;
}
switch ((buf[7] >> 0) & 7) {
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
case 5:
c->code_rate_LP = FEC_NONE;
break;
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int ret, tmp = 0;
u8 buf[7];
unsigned int utmp, utmp1;
dev_dbg(&client->dev, "\n");
*status = 0;
ret = regmap_read(dev->regmap, 0x800047, &utmp);
if (ret)
goto err;
if (utmp == 0x01)
*status |= FE_HAS_SIGNAL;
if (utmp != 0x02) {
ret = regmap_read(dev->regmap, 0x80f5a9, &utmp);
if (ret)
goto err;
if ((utmp >> 0) & 0x01)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI;
ret = regmap_read(dev->regmap, 0x80f999, &utmp);
if (ret)
goto err;
if ((utmp >> 0) & 0x01)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC |
FE_HAS_LOCK;
}
dev->fe_status = *status;
if (dev->fe_status & FE_HAS_SIGNAL) {
if (dev->is_af9035) {
ret = regmap_read(dev->regmap, 0x80004a, &utmp);
if (ret)
goto err;
tmp = -utmp * 1000;
} else {
ret = regmap_read(dev->regmap, 0x8000f7, &utmp);
if (ret)
goto err;
tmp = (utmp - 100) * 1000;
}
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_DECIBEL;
c->strength.stat[0].svalue = tmp;
} else {
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (dev->fe_status & FE_HAS_VITERBI) {
ret = regmap_bulk_read(dev->regmap, 0x80002c, buf, 3);
if (ret)
goto err;
utmp1 = buf[2] << 16 | buf[1] << 8 | buf[0] << 0;
ret = regmap_read(dev->regmap, 0x80f78b, &utmp);
if (ret)
goto err;
if (utmp)
utmp1 /= utmp;
ret = regmap_read(dev->regmap, 0x80f900, &utmp);
if (ret)
goto err;
switch ((utmp >> 0) & 3) {
case 0:
utmp1 *= 4;
break;
case 1:
utmp1 *= 1;
break;
case 2:
utmp1 *= 2;
break;
default:
utmp1 *= 0;
break;
}
ret = regmap_read(dev->regmap, 0x80f903, &utmp);
if (ret)
goto err;
switch ((utmp >> 0) & 3) {
case 0:
utmp1 = clamp(utmp1, 653799U, 1689999U);
utmp1 = ((u64)(intlog10(utmp1)
- intlog10(1690000 - utmp1)
+ 3355443) * 13 * 1000) >> 24;
break;
case 1:
utmp1 = clamp(utmp1, 371105U, 827999U);
utmp1 = ((u64)(intlog10(utmp1 - 370000)
- intlog10(828000 - utmp1)
+ 43900382) * 6 * 1000) >> 24;
break;
case 2:
utmp1 = clamp(utmp1, 193246U, 424999U);
utmp1 = ((u64)(intlog10(utmp1 - 193000)
- intlog10(425000 - utmp1)
+ 49912218) * 8 * 1000) >> 24;
break;
default:
utmp1 = 0;
break;
}
dev_dbg(&client->dev, "cnr=%u\n", utmp1);
c->cnr.stat[0].scale = FE_SCALE_DECIBEL;
c->cnr.stat[0].svalue = utmp1;
} else {
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (dev->fe_status & FE_HAS_LOCK) {
u16 abort_packet_count, rsd_packet_count;
u32 rsd_bit_err_count;
ret = regmap_bulk_read(dev->regmap, 0x800032, buf, 7);
if (ret)
goto err;
abort_packet_count = (buf[1] << 8) | (buf[0] << 0);
rsd_bit_err_count = (buf[4] << 16) | (buf[3] << 8) | buf[2];
rsd_packet_count = (buf[6] << 8) | (buf[5] << 0);
dev->error_block_count += abort_packet_count;
dev->total_block_count += rsd_packet_count;
dev->post_bit_error += rsd_bit_err_count;
dev->post_bit_count += rsd_packet_count * 204 * 8;
c->block_count.len = 1;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].uvalue = dev->total_block_count;
c->block_error.len = 1;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_error.stat[0].uvalue = dev->error_block_count;
c->post_bit_count.len = 1;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].uvalue = dev->post_bit_count;
c->post_bit_error.len = 1;
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue = dev->post_bit_error;
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &dev->fe.dtv_property_cache;
int ret;
unsigned int utmp;
dev_dbg(&client->dev, "\n");
if (c->cnr.stat[0].scale == FE_SCALE_DECIBEL) {
if (dev->is_af9035) {
*snr = div_s64(c->cnr.stat[0].svalue, 100);
} else {
*snr = div_s64(c->cnr.stat[0].svalue, 1000);
ret = regmap_read(dev->regmap, 0x80f903, &utmp);
if (ret)
goto err;
switch ((utmp >> 0) & 3) {
case 0:
*snr = *snr * 0xffff / 23;
break;
case 1:
*snr = *snr * 0xffff / 26;
break;
case 2:
*snr = *snr * 0xffff / 32;
break;
default:
goto err;
}
}
} else {
*snr = 0;
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
struct dtv_frontend_properties *c = &dev->fe.dtv_property_cache;
int ret, tmp, power_real;
unsigned int utmp;
u8 gain_offset, buf[7];
dev_dbg(&client->dev, "\n");
if (dev->is_af9035) {
ret = regmap_read(dev->regmap, 0x800048, &utmp);
if (ret)
goto err;
*strength = utmp * 0xffff / 100;
} else {
ret = regmap_read(dev->regmap, 0x8000f7, &utmp);
if (ret)
goto err;
ret = regmap_bulk_read(dev->regmap, 0x80f900, buf, 7);
if (ret)
goto err;
if (c->frequency <= 300000000)
gain_offset = 7;
else
gain_offset = 4;
power_real = (utmp - 100 - gain_offset) -
power_reference[((buf[3] >> 0) & 3)][((buf[6] >> 0) & 7)];
if (power_real < -15)
tmp = 0;
else if ((power_real >= -15) && (power_real < 0))
tmp = (2 * (power_real + 15)) / 3;
else if ((power_real >= 0) && (power_real < 20))
tmp = 4 * power_real + 10;
else if ((power_real >= 20) && (power_real < 35))
tmp = (2 * (power_real - 20)) / 3 + 90;
else
tmp = 100;
*strength = tmp * 0xffff / 100;
}
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct af9033_dev *dev = fe->demodulator_priv;
*ber = (dev->post_bit_error - dev->post_bit_error_prev);
dev->post_bit_error_prev = dev->post_bit_error;
return 0;
}
static int af9033_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct af9033_dev *dev = fe->demodulator_priv;
*ucblocks = dev->error_block_count;
return 0;
}
static int af9033_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
dev_dbg(&client->dev, "enable=%d\n", enable);
ret = regmap_update_bits(dev->regmap, 0x00fa04, 0x01, enable);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_pid_filter_ctrl(struct dvb_frontend *fe, int onoff)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
dev_dbg(&client->dev, "onoff=%d\n", onoff);
ret = regmap_update_bits(dev->regmap, 0x80f993, 0x01, onoff);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_pid_filter(struct dvb_frontend *fe, int index, u16 pid,
int onoff)
{
struct af9033_dev *dev = fe->demodulator_priv;
struct i2c_client *client = dev->client;
int ret;
u8 wbuf[2] = {(pid >> 0) & 0xff, (pid >> 8) & 0xff};
dev_dbg(&client->dev, "index=%d pid=%04x onoff=%d\n",
index, pid, onoff);
if (pid > 0x1fff)
return 0;
ret = regmap_bulk_write(dev->regmap, 0x80f996, wbuf, 2);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x80f994, onoff);
if (ret)
goto err;
ret = regmap_write(dev->regmap, 0x80f995, index);
if (ret)
goto err;
return 0;
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct af9033_config *cfg = client->dev.platform_data;
struct af9033_dev *dev;
int ret;
u8 buf[8];
u32 reg;
static const struct regmap_config regmap_config = {
.reg_bits = 24,
.val_bits = 8,
};
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err;
}
dev->client = client;
memcpy(&dev->cfg, cfg, sizeof(dev->cfg));
switch (dev->cfg.ts_mode) {
case AF9033_TS_MODE_PARALLEL:
dev->ts_mode_parallel = true;
break;
case AF9033_TS_MODE_SERIAL:
dev->ts_mode_serial = true;
break;
case AF9033_TS_MODE_USB:
default:
break;
}
if (dev->cfg.clock != 12000000) {
ret = -ENODEV;
dev_err(&client->dev,
"Unsupported clock %u Hz. Only 12000000 Hz is supported currently\n",
dev->cfg.clock);
goto err_kfree;
}
dev->regmap = regmap_init_i2c(client, &regmap_config);
if (IS_ERR(dev->regmap)) {
ret = PTR_ERR(dev->regmap);
goto err_kfree;
}
switch (dev->cfg.tuner) {
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
dev->is_it9135 = true;
reg = 0x004bfc;
break;
default:
dev->is_af9035 = true;
reg = 0x0083e9;
break;
}
ret = regmap_bulk_read(dev->regmap, reg, &buf[0], 4);
if (ret)
goto err_regmap_exit;
ret = regmap_bulk_read(dev->regmap, 0x804191, &buf[4], 4);
if (ret)
goto err_regmap_exit;
dev_info(&client->dev,
"firmware version: LINK %d.%d.%d.%d - OFDM %d.%d.%d.%d\n",
buf[0], buf[1], buf[2], buf[3],
buf[4], buf[5], buf[6], buf[7]);
switch (dev->cfg.tuner) {
case AF9033_TUNER_IT9135_38:
case AF9033_TUNER_IT9135_51:
case AF9033_TUNER_IT9135_52:
case AF9033_TUNER_IT9135_60:
case AF9033_TUNER_IT9135_61:
case AF9033_TUNER_IT9135_62:
break;
default:
ret = regmap_write(dev->regmap, 0x80004c, 0x01);
if (ret)
goto err_regmap_exit;
ret = regmap_write(dev->regmap, 0x800000, 0x00);
if (ret)
goto err_regmap_exit;
}
memcpy(&dev->fe.ops, &af9033_ops, sizeof(dev->fe.ops));
dev->fe.demodulator_priv = dev;
*cfg->fe = &dev->fe;
if (cfg->ops) {
cfg->ops->pid_filter = af9033_pid_filter;
cfg->ops->pid_filter_ctrl = af9033_pid_filter_ctrl;
}
cfg->regmap = dev->regmap;
i2c_set_clientdata(client, dev);
dev_info(&client->dev, "Afatech AF9033 successfully attached\n");
return 0;
err_regmap_exit:
regmap_exit(dev->regmap);
err_kfree:
kfree(dev);
err:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int af9033_remove(struct i2c_client *client)
{
struct af9033_dev *dev = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
regmap_exit(dev->regmap);
kfree(dev);
return 0;
}
