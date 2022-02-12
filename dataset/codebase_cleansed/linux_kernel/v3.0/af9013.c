static int af9013_write_regs(struct af9013_state *state, u8 mbox, u16 reg,
u8 *val, u8 len)
{
u8 buf[3+len];
struct i2c_msg msg = {
.addr = state->config.demod_address,
.flags = 0,
.len = sizeof(buf),
.buf = buf };
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
buf[2] = mbox;
memcpy(&buf[3], val, len);
if (i2c_transfer(state->i2c, &msg, 1) != 1) {
warn("I2C write failed reg:%04x len:%d", reg, len);
return -EREMOTEIO;
}
return 0;
}
static int af9013_write_ofdm_regs(struct af9013_state *state, u16 reg, u8 *val,
u8 len)
{
u8 mbox = (1 << 0)|(1 << 1)|((len - 1) << 2)|(0 << 6)|(0 << 7);
return af9013_write_regs(state, mbox, reg, val, len);
}
static int af9013_write_ofsm_regs(struct af9013_state *state, u16 reg, u8 *val,
u8 len)
{
u8 mbox = (1 << 0)|(1 << 1)|((len - 1) << 2)|(1 << 6)|(1 << 7);
return af9013_write_regs(state, mbox, reg, val, len);
}
static int af9013_write_reg(struct af9013_state *state, u16 reg, u8 val)
{
return af9013_write_ofdm_regs(state, reg, &val, 1);
}
static int af9013_read_reg(struct af9013_state *state, u16 reg, u8 *val)
{
u8 obuf[3] = { reg >> 8, reg & 0xff, 0 };
u8 ibuf[1];
struct i2c_msg msg[2] = {
{
.addr = state->config.demod_address,
.flags = 0,
.len = sizeof(obuf),
.buf = obuf
}, {
.addr = state->config.demod_address,
.flags = I2C_M_RD,
.len = sizeof(ibuf),
.buf = ibuf
}
};
if (i2c_transfer(state->i2c, msg, 2) != 2) {
warn("I2C read failed reg:%04x", reg);
return -EREMOTEIO;
}
*val = ibuf[0];
return 0;
}
static int af9013_write_reg_bits(struct af9013_state *state, u16 reg, u8 pos,
u8 len, u8 val)
{
int ret;
u8 tmp, mask;
ret = af9013_read_reg(state, reg, &tmp);
if (ret)
return ret;
mask = regmask[len - 1] << pos;
tmp = (tmp & ~mask) | ((val << pos) & mask);
return af9013_write_reg(state, reg, tmp);
}
static int af9013_read_reg_bits(struct af9013_state *state, u16 reg, u8 pos,
u8 len, u8 *val)
{
int ret;
u8 tmp;
ret = af9013_read_reg(state, reg, &tmp);
if (ret)
return ret;
*val = (tmp >> pos) & regmask[len - 1];
return 0;
}
static int af9013_set_gpio(struct af9013_state *state, u8 gpio, u8 gpioval)
{
int ret;
u8 pos;
u16 addr;
deb_info("%s: gpio:%d gpioval:%02x\n", __func__, gpio, gpioval);
switch (gpio) {
case 0:
case 1:
addr = 0xd735;
break;
case 2:
case 3:
addr = 0xd736;
break;
default:
err("invalid gpio:%d\n", gpio);
ret = -EINVAL;
goto error;
};
switch (gpio) {
case 0:
case 2:
pos = 0;
break;
case 1:
case 3:
default:
pos = 4;
break;
};
ret = af9013_write_reg_bits(state, addr, pos, 4, gpioval);
error:
return ret;
}
static u32 af913_div(u32 a, u32 b, u32 x)
{
u32 r = 0, c = 0, i;
deb_info("%s: a:%d b:%d x:%d\n", __func__, a, b, x);
if (a > b) {
c = a / b;
a = a - c * b;
}
for (i = 0; i < x; i++) {
if (a >= b) {
r += 1;
a -= b;
}
a <<= 1;
r <<= 1;
}
r = (c << (u32)x) + r;
deb_info("%s: a:%d b:%d x:%d r:%d r:%x\n", __func__, a, b, x, r, r);
return r;
}
static int af9013_set_coeff(struct af9013_state *state, fe_bandwidth_t bw)
{
int ret, i, j, found;
deb_info("%s: adc_clock:%d bw:%d\n", __func__,
state->config.adc_clock, bw);
for (i = 0, found = 0; i < ARRAY_SIZE(coeff_table); i++) {
if (coeff_table[i].adc_clock == state->config.adc_clock &&
coeff_table[i].bw == bw) {
found = 1;
break;
}
}
if (!found) {
err("invalid bw or clock");
ret = -EINVAL;
goto error;
}
deb_info("%s: coeff: ", __func__);
debug_dump(coeff_table[i].val, sizeof(coeff_table[i].val), deb_info);
for (j = 0; j < sizeof(coeff_table[i].val); j++) {
ret = af9013_write_reg(state, 0xae00 + j,
coeff_table[i].val[j]);
if (ret)
break;
}
error:
return ret;
}
static int af9013_set_adc_ctrl(struct af9013_state *state)
{
int ret;
u8 buf[3], tmp, i;
u32 adc_cw;
deb_info("%s: adc_clock:%d\n", __func__, state->config.adc_clock);
switch (state->config.adc_clock) {
case 28800:
tmp = 0;
break;
case 20480:
tmp = 1;
break;
case 28000:
tmp = 2;
break;
case 25000:
tmp = 3;
break;
default:
err("invalid xtal");
return -EINVAL;
}
adc_cw = af913_div(state->config.adc_clock*1000, 1000000ul, 19ul);
buf[0] = (u8) ((adc_cw & 0x000000ff));
buf[1] = (u8) ((adc_cw & 0x0000ff00) >> 8);
buf[2] = (u8) ((adc_cw & 0x00ff0000) >> 16);
deb_info("%s: adc_cw:", __func__);
debug_dump(buf, sizeof(buf), deb_info);
for (i = 0; i < sizeof(buf); i++) {
ret = af9013_write_reg(state, 0xd180 + i, buf[i]);
if (ret)
goto error;
}
ret = af9013_write_reg_bits(state, 0x9bd2, 0, 4, tmp);
error:
return ret;
}
static int af9013_set_freq_ctrl(struct af9013_state *state, fe_bandwidth_t bw)
{
int ret;
u16 addr;
u8 buf[3], i, j;
u32 adc_freq, freq_cw;
s8 bfs_spec_inv;
int if_sample_freq;
for (j = 0; j < 3; j++) {
if (j == 0) {
addr = 0xd140;
bfs_spec_inv = state->config.rf_spec_inv ? -1 : 1;
} else if (j == 1) {
addr = 0x9be7;
bfs_spec_inv = state->config.rf_spec_inv ? -1 : 1;
} else {
addr = 0x9bea;
bfs_spec_inv = state->config.rf_spec_inv ? 1 : -1;
}
adc_freq = state->config.adc_clock * 1000;
if_sample_freq = state->config.tuner_if * 1000;
if (state->config.tuner == AF9013_TUNER_TDA18271) {
switch (bw) {
case BANDWIDTH_6_MHZ:
if_sample_freq = 3300000;
break;
case BANDWIDTH_7_MHZ:
if_sample_freq = 3500000;
break;
case BANDWIDTH_8_MHZ:
default:
if_sample_freq = 4000000;
break;
}
} else if (state->config.tuner == AF9013_TUNER_TDA18218) {
switch (bw) {
case BANDWIDTH_6_MHZ:
if_sample_freq = 3000000;
break;
case BANDWIDTH_7_MHZ:
if_sample_freq = 3500000;
break;
case BANDWIDTH_8_MHZ:
default:
if_sample_freq = 4000000;
break;
}
}
while (if_sample_freq > (adc_freq / 2))
if_sample_freq = if_sample_freq - adc_freq;
if (if_sample_freq >= 0)
bfs_spec_inv = bfs_spec_inv * (-1);
else
if_sample_freq = if_sample_freq * (-1);
freq_cw = af913_div(if_sample_freq, adc_freq, 23ul);
if (bfs_spec_inv == -1)
freq_cw = 0x00800000 - freq_cw;
buf[0] = (u8) ((freq_cw & 0x000000ff));
buf[1] = (u8) ((freq_cw & 0x0000ff00) >> 8);
buf[2] = (u8) ((freq_cw & 0x007f0000) >> 16);
deb_info("%s: freq_cw:", __func__);
debug_dump(buf, sizeof(buf), deb_info);
for (i = 0; i < sizeof(buf); i++) {
ret = af9013_write_reg(state, addr++, buf[i]);
if (ret)
goto error;
}
}
error:
return ret;
}
static int af9013_set_ofdm_params(struct af9013_state *state,
struct dvb_ofdm_parameters *params, u8 *auto_mode)
{
int ret;
u8 i, buf[3] = {0, 0, 0};
*auto_mode = 0;
switch (params->transmission_mode) {
case TRANSMISSION_MODE_AUTO:
*auto_mode = 1;
case TRANSMISSION_MODE_2K:
break;
case TRANSMISSION_MODE_8K:
buf[0] |= (1 << 0);
break;
default:
deb_info("%s: invalid transmission_mode\n", __func__);
*auto_mode = 1;
}
switch (params->guard_interval) {
case GUARD_INTERVAL_AUTO:
*auto_mode = 1;
case GUARD_INTERVAL_1_32:
break;
case GUARD_INTERVAL_1_16:
buf[0] |= (1 << 2);
break;
case GUARD_INTERVAL_1_8:
buf[0] |= (2 << 2);
break;
case GUARD_INTERVAL_1_4:
buf[0] |= (3 << 2);
break;
default:
deb_info("%s: invalid guard_interval\n", __func__);
*auto_mode = 1;
}
switch (params->hierarchy_information) {
case HIERARCHY_AUTO:
*auto_mode = 1;
case HIERARCHY_NONE:
break;
case HIERARCHY_1:
buf[0] |= (1 << 4);
break;
case HIERARCHY_2:
buf[0] |= (2 << 4);
break;
case HIERARCHY_4:
buf[0] |= (3 << 4);
break;
default:
deb_info("%s: invalid hierarchy_information\n", __func__);
*auto_mode = 1;
};
switch (params->constellation) {
case QAM_AUTO:
*auto_mode = 1;
case QPSK:
break;
case QAM_16:
buf[1] |= (1 << 6);
break;
case QAM_64:
buf[1] |= (2 << 6);
break;
default:
deb_info("%s: invalid constellation\n", __func__);
*auto_mode = 1;
}
buf[1] |= (1 << 4);
switch (params->code_rate_HP) {
case FEC_AUTO:
*auto_mode = 1;
case FEC_1_2:
break;
case FEC_2_3:
buf[2] |= (1 << 0);
break;
case FEC_3_4:
buf[2] |= (2 << 0);
break;
case FEC_5_6:
buf[2] |= (3 << 0);
break;
case FEC_7_8:
buf[2] |= (4 << 0);
break;
default:
deb_info("%s: invalid code_rate_HP\n", __func__);
*auto_mode = 1;
}
switch (params->code_rate_LP) {
case FEC_AUTO:
if (params->hierarchy_information != HIERARCHY_NONE)
*auto_mode = 1;
case FEC_1_2:
break;
case FEC_2_3:
buf[2] |= (1 << 3);
break;
case FEC_3_4:
buf[2] |= (2 << 3);
break;
case FEC_5_6:
buf[2] |= (3 << 3);
break;
case FEC_7_8:
buf[2] |= (4 << 3);
break;
case FEC_NONE:
if (params->hierarchy_information == HIERARCHY_AUTO)
break;
default:
deb_info("%s: invalid code_rate_LP\n", __func__);
*auto_mode = 1;
}
switch (params->bandwidth) {
case BANDWIDTH_6_MHZ:
break;
case BANDWIDTH_7_MHZ:
buf[1] |= (1 << 2);
break;
case BANDWIDTH_8_MHZ:
buf[1] |= (2 << 2);
break;
default:
deb_info("%s: invalid bandwidth\n", __func__);
buf[1] |= (2 << 2);
}
for (i = 0; i < sizeof(buf); i++) {
ret = af9013_write_reg(state, 0xd3c0 + i, buf[i]);
if (ret)
break;
}
return ret;
}
static int af9013_reset(struct af9013_state *state, u8 sleep)
{
int ret;
u8 tmp, i;
deb_info("%s\n", __func__);
ret = af9013_write_reg_bits(state, 0xd417, 4, 1, 1);
if (ret)
goto error;
ret = af9013_write_reg(state, 0xaeff, 1);
if (ret)
goto error;
for (i = 0; i < 150; i++) {
ret = af9013_read_reg_bits(state, 0xd417, 1, 1, &tmp);
if (ret)
goto error;
if (tmp)
break;
msleep(10);
}
if (!tmp)
return -ETIMEDOUT;
if (!sleep) {
ret = af9013_write_reg_bits(state, 0xd417, 1, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd417, 4, 1, 0);
}
error:
return ret;
}
static int af9013_power_ctrl(struct af9013_state *state, u8 onoff)
{
int ret;
deb_info("%s: onoff:%d\n", __func__, onoff);
if (onoff) {
ret = af9013_write_reg_bits(state, 0xd73a, 3, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd417, 1, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd417, 4, 1, 0);
} else {
ret = af9013_reset(state, 1);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd73a, 3, 1, 1);
}
error:
return ret;
}
static int af9013_lock_led(struct af9013_state *state, u8 onoff)
{
deb_info("%s: onoff:%d\n", __func__, onoff);
return af9013_write_reg_bits(state, 0xd730, 0, 1, onoff);
}
static int af9013_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *params)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
u8 auto_mode;
deb_info("%s: freq:%d bw:%d\n", __func__, params->frequency,
params->u.ofdm.bandwidth);
state->frequency = params->frequency;
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe, params);
ret = af9013_set_coeff(state, params->u.ofdm.bandwidth);
if (ret)
goto error;
ret = af9013_set_freq_ctrl(state, params->u.ofdm.bandwidth);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd330, 3, 1, 1);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd507, 6, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0x9bfe, 0, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0x9bc2, 0, 1, 0);
if (ret)
goto error;
ret = af9013_set_ofdm_params(state, &params->u.ofdm, &auto_mode);
if (ret)
goto error;
if (auto_mode) {
ret = af9013_write_reg(state, 0xaefd, 0);
deb_info("%s: auto TPS\n", __func__);
} else {
ret = af9013_write_reg(state, 0xaefd, 1);
if (ret)
goto error;
ret = af9013_write_reg(state, 0xaefe, 0);
deb_info("%s: manual TPS\n", __func__);
}
if (ret)
goto error;
ret = af9013_write_reg(state, 0xffff, 0);
if (ret)
goto error;
error:
return ret;
}
static int af9013_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
u8 i, buf[3];
deb_info("%s\n", __func__);
for (i = 0; i < 3; i++) {
ret = af9013_read_reg(state, 0xd3c0 + i, &buf[i]);
if (ret)
goto error;
}
switch ((buf[1] >> 6) & 3) {
case 0:
p->u.ofdm.constellation = QPSK;
break;
case 1:
p->u.ofdm.constellation = QAM_16;
break;
case 2:
p->u.ofdm.constellation = QAM_64;
break;
}
switch ((buf[0] >> 0) & 3) {
case 0:
p->u.ofdm.transmission_mode = TRANSMISSION_MODE_2K;
break;
case 1:
p->u.ofdm.transmission_mode = TRANSMISSION_MODE_8K;
}
switch ((buf[0] >> 2) & 3) {
case 0:
p->u.ofdm.guard_interval = GUARD_INTERVAL_1_32;
break;
case 1:
p->u.ofdm.guard_interval = GUARD_INTERVAL_1_16;
break;
case 2:
p->u.ofdm.guard_interval = GUARD_INTERVAL_1_8;
break;
case 3:
p->u.ofdm.guard_interval = GUARD_INTERVAL_1_4;
break;
}
switch ((buf[0] >> 4) & 7) {
case 0:
p->u.ofdm.hierarchy_information = HIERARCHY_NONE;
break;
case 1:
p->u.ofdm.hierarchy_information = HIERARCHY_1;
break;
case 2:
p->u.ofdm.hierarchy_information = HIERARCHY_2;
break;
case 3:
p->u.ofdm.hierarchy_information = HIERARCHY_4;
break;
}
switch ((buf[2] >> 0) & 7) {
case 0:
p->u.ofdm.code_rate_HP = FEC_1_2;
break;
case 1:
p->u.ofdm.code_rate_HP = FEC_2_3;
break;
case 2:
p->u.ofdm.code_rate_HP = FEC_3_4;
break;
case 3:
p->u.ofdm.code_rate_HP = FEC_5_6;
break;
case 4:
p->u.ofdm.code_rate_HP = FEC_7_8;
break;
}
switch ((buf[2] >> 3) & 7) {
case 0:
p->u.ofdm.code_rate_LP = FEC_1_2;
break;
case 1:
p->u.ofdm.code_rate_LP = FEC_2_3;
break;
case 2:
p->u.ofdm.code_rate_LP = FEC_3_4;
break;
case 3:
p->u.ofdm.code_rate_LP = FEC_5_6;
break;
case 4:
p->u.ofdm.code_rate_LP = FEC_7_8;
break;
}
switch ((buf[1] >> 2) & 3) {
case 0:
p->u.ofdm.bandwidth = BANDWIDTH_6_MHZ;
break;
case 1:
p->u.ofdm.bandwidth = BANDWIDTH_7_MHZ;
break;
case 2:
p->u.ofdm.bandwidth = BANDWIDTH_8_MHZ;
break;
}
p->inversion = INVERSION_AUTO;
p->frequency = state->frequency;
error:
return ret;
}
static int af9013_update_ber_unc(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
u8 buf[3], i;
u32 error_bit_count = 0;
u32 total_bit_count = 0;
u32 abort_packet_count = 0;
state->ber = 0;
ret = af9013_read_reg_bits(state, 0xd391, 4, 1, &buf[0]);
if (ret)
goto error;
if (!buf[0])
goto exit;
for (i = 0; i < 2; i++) {
ret = af9013_read_reg(state, 0xd38a + i, &buf[i]);
if (ret)
goto error;
}
abort_packet_count = (buf[1] << 8) + buf[0];
for (i = 0; i < 3; i++) {
ret = af9013_read_reg(state, 0xd387 + i, &buf[i]);
if (ret)
goto error;
}
error_bit_count = (buf[2] << 16) + (buf[1] << 8) + buf[0];
error_bit_count = error_bit_count - abort_packet_count * 8 * 8;
for (i = 0; i < 2; i++) {
ret = af9013_read_reg(state, 0xd385 + i, &buf[i]);
if (ret)
goto error;
}
total_bit_count = (buf[1] << 8) + buf[0];
total_bit_count = total_bit_count - abort_packet_count;
total_bit_count = total_bit_count * 204 * 8;
if (total_bit_count)
state->ber = error_bit_count * 1000000000 / total_bit_count;
state->ucblocks += abort_packet_count;
deb_info("%s: err bits:%d total bits:%d abort count:%d\n", __func__,
error_bit_count, total_bit_count, abort_packet_count);
ret = af9013_write_reg(state, 0xd385, 10000 & 0xff);
if (ret)
goto error;
ret = af9013_write_reg(state, 0xd386, 10000 >> 8);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd391, 4, 1, 1);
if (ret)
goto error;
exit:
error:
return ret;
}
static int af9013_update_snr(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
u8 buf[3], i, len;
u32 quant = 0;
struct snr_table *uninitialized_var(snr_table);
ret = af9013_read_reg_bits(state, 0xd2e1, 3, 1, &buf[0]);
if (ret)
goto error;
if (buf[0]) {
for (i = 0; i < 3; i++) {
ret = af9013_read_reg(state, 0xd2e3 + i, &buf[i]);
if (ret)
goto error;
}
quant = (buf[2] << 16) + (buf[1] << 8) + buf[0];
ret = af9013_read_reg(state, 0xd3c1, &buf[0]);
if (ret)
goto error;
switch ((buf[0] >> 6) & 3) {
case 0:
len = ARRAY_SIZE(qpsk_snr_table);
snr_table = qpsk_snr_table;
break;
case 1:
len = ARRAY_SIZE(qam16_snr_table);
snr_table = qam16_snr_table;
break;
case 2:
len = ARRAY_SIZE(qam64_snr_table);
snr_table = qam64_snr_table;
break;
default:
len = 0;
break;
}
if (len) {
for (i = 0; i < len; i++) {
if (quant < snr_table[i].val) {
state->snr = snr_table[i].snr * 10;
break;
}
}
}
ret = af9013_write_reg(state, 0xd2e2, 1);
if (ret)
goto error;
for (i = 0; i < 10; i++) {
msleep(10);
ret = af9013_read_reg_bits(state, 0xd2e6, 0, 1,
&buf[0]);
if (ret)
goto error;
if (!buf[0])
break;
}
ret = af9013_write_reg_bits(state, 0xd2e1, 3, 1, 1);
if (ret)
goto error;
}
error:
return ret;
}
static int af9013_update_signal_strength(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret = 0;
u8 rf_gain, if_gain;
int signal_strength;
deb_info("%s\n", __func__);
if (state->signal_strength_en) {
ret = af9013_read_reg(state, 0xd07c, &rf_gain);
if (ret)
goto error;
ret = af9013_read_reg(state, 0xd07d, &if_gain);
if (ret)
goto error;
signal_strength = (0xffff / \
(9 * (state->rf_50 + state->if_50) - \
11 * (state->rf_80 + state->if_80))) * \
(10 * (rf_gain + if_gain) - \
11 * (state->rf_80 + state->if_80));
if (signal_strength < 0)
signal_strength = 0;
else if (signal_strength > 0xffff)
signal_strength = 0xffff;
state->signal_strength = signal_strength;
} else {
state->signal_strength = 0;
}
error:
return ret;
}
static int af9013_update_statistics(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
if (time_before(jiffies, state->next_statistics_check))
return 0;
state->next_statistics_check = jiffies + msecs_to_jiffies(1200);
ret = af9013_update_signal_strength(fe);
if (ret)
goto error;
ret = af9013_update_snr(fe);
if (ret)
goto error;
ret = af9013_update_ber_unc(fe);
if (ret)
goto error;
error:
return ret;
}
static int af9013_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *fesettings)
{
fesettings->min_delay_ms = 800;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static int af9013_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct af9013_state *state = fe->demodulator_priv;
int ret = 0;
u8 tmp;
*status = 0;
ret = af9013_read_reg_bits(state, 0xd507, 6, 1, &tmp);
if (ret)
goto error;
if (tmp)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_LOCK;
if (!*status) {
ret = af9013_read_reg_bits(state, 0xd330, 3, 1, &tmp);
if (ret)
goto error;
if (tmp)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI;
}
if (!*status) {
ret = af9013_read_reg_bits(state, 0xd333, 7, 1, &tmp);
if (ret)
goto error;
if (tmp)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER;
}
if (!*status) {
ret = af9013_read_reg_bits(state, 0xd334, 6, 1, &tmp);
if (ret)
goto error;
if (tmp)
*status |= FE_HAS_SIGNAL | FE_HAS_CARRIER;
}
if (!*status) {
ret = af9013_read_reg_bits(state, 0xd1a0, 6, 1, &tmp);
if (ret)
goto error;
if (tmp)
*status |= FE_HAS_SIGNAL;
}
ret = af9013_update_statistics(fe);
error:
return ret;
}
static int af9013_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
ret = af9013_update_statistics(fe);
*ber = state->ber;
return ret;
}
static int af9013_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
ret = af9013_update_statistics(fe);
*strength = state->signal_strength;
return ret;
}
static int af9013_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
ret = af9013_update_statistics(fe);
*snr = state->snr;
return ret;
}
static int af9013_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
ret = af9013_update_statistics(fe);
*ucblocks = state->ucblocks;
return ret;
}
static int af9013_sleep(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret;
deb_info("%s\n", __func__);
ret = af9013_lock_led(state, 0);
if (ret)
goto error;
ret = af9013_power_ctrl(state, 0);
error:
return ret;
}
static int af9013_init(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
int ret, i, len;
u8 tmp0, tmp1;
struct regdesc *init;
deb_info("%s\n", __func__);
ret = af9013_reset(state, 0);
if (ret)
goto error;
ret = af9013_power_ctrl(state, 1);
if (ret)
goto error;
ret = af9013_write_reg(state, 0xd73a, 0xa4);
if (ret)
goto error;
for (i = 0; i < sizeof(state->config.api_version); i++) {
ret = af9013_write_reg(state, 0x9bf2 + i,
state->config.api_version[i]);
if (ret)
goto error;
}
ret = af9013_set_adc_ctrl(state);
if (ret)
goto error;
ret = af9013_write_reg(state, 0xd416, 0x14);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd700, 1, 1, 1);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd700, 2, 1, 0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd371, 1, 1, 1);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd392, 1, 1, 1);
if (ret)
goto error;
deb_info("%s: load ofsm settings\n", __func__);
len = ARRAY_SIZE(ofsm_init);
init = ofsm_init;
for (i = 0; i < len; i++) {
ret = af9013_write_reg_bits(state, init[i].addr, init[i].pos,
init[i].len, init[i].val);
if (ret)
goto error;
}
deb_info("%s: load tuner specific settings\n", __func__);
switch (state->config.tuner) {
case AF9013_TUNER_MXL5003D:
len = ARRAY_SIZE(tuner_init_mxl5003d);
init = tuner_init_mxl5003d;
break;
case AF9013_TUNER_MXL5005D:
case AF9013_TUNER_MXL5005R:
case AF9013_TUNER_MXL5007T:
len = ARRAY_SIZE(tuner_init_mxl5005);
init = tuner_init_mxl5005;
break;
case AF9013_TUNER_ENV77H11D5:
len = ARRAY_SIZE(tuner_init_env77h11d5);
init = tuner_init_env77h11d5;
break;
case AF9013_TUNER_MT2060:
len = ARRAY_SIZE(tuner_init_mt2060);
init = tuner_init_mt2060;
break;
case AF9013_TUNER_MC44S803:
len = ARRAY_SIZE(tuner_init_mc44s803);
init = tuner_init_mc44s803;
break;
case AF9013_TUNER_QT1010:
case AF9013_TUNER_QT1010A:
len = ARRAY_SIZE(tuner_init_qt1010);
init = tuner_init_qt1010;
break;
case AF9013_TUNER_MT2060_2:
len = ARRAY_SIZE(tuner_init_mt2060_2);
init = tuner_init_mt2060_2;
break;
case AF9013_TUNER_TDA18271:
case AF9013_TUNER_TDA18218:
len = ARRAY_SIZE(tuner_init_tda18271);
init = tuner_init_tda18271;
break;
case AF9013_TUNER_UNKNOWN:
default:
len = ARRAY_SIZE(tuner_init_unknown);
init = tuner_init_unknown;
break;
}
for (i = 0; i < len; i++) {
ret = af9013_write_reg_bits(state, init[i].addr, init[i].pos,
init[i].len, init[i].val);
if (ret)
goto error;
}
deb_info("%s: setting ts mode\n", __func__);
tmp0 = 0;
tmp1 = 0;
switch (state->config.output_mode) {
case AF9013_OUTPUT_MODE_PARALLEL:
tmp0 = 1;
break;
case AF9013_OUTPUT_MODE_SERIAL:
tmp1 = 1;
break;
case AF9013_OUTPUT_MODE_USB:
default:
break;
}
ret = af9013_write_reg_bits(state, 0xd500, 1, 1, tmp0);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd500, 2, 1, tmp1);
if (ret)
goto error;
ret = af9013_lock_led(state, 1);
if (ret)
goto error;
ret = af9013_read_reg_bits(state, 0x9bee, 0, 1,
&state->signal_strength_en);
if (ret)
goto error;
if (state->signal_strength_en) {
ret = af9013_read_reg(state, 0x9bbd, &state->rf_50);
if (ret)
goto error;
ret = af9013_read_reg(state, 0x9bd0, &state->rf_80);
if (ret)
goto error;
ret = af9013_read_reg(state, 0x9be2, &state->if_50);
if (ret)
goto error;
ret = af9013_read_reg(state, 0x9be4, &state->if_80);
if (ret)
goto error;
}
error:
return ret;
}
static int af9013_download_firmware(struct af9013_state *state)
{
int i, len, remaining, ret;
const struct firmware *fw;
u16 checksum = 0;
u8 val;
u8 fw_params[4];
u8 *fw_file = AF9013_DEFAULT_FIRMWARE;
msleep(100);
ret = af9013_read_reg(state, 0x98be, &val);
if (ret)
goto error;
else
deb_info("%s: firmware status:%02x\n", __func__, val);
if (val == 0x0c)
goto exit;
info("found a '%s' in cold state, will try to load a firmware",
af9013_ops.info.name);
ret = request_firmware(&fw, fw_file, state->i2c->dev.parent);
if (ret) {
err("did not find the firmware file. (%s) "
"Please see linux/Documentation/dvb/ for more details" \
" on firmware-problems. (%d)",
fw_file, ret);
goto error;
}
info("downloading firmware from file '%s'", fw_file);
for (i = 0; i < fw->size; i++)
checksum += fw->data[i];
fw_params[0] = checksum >> 8;
fw_params[1] = checksum & 0xff;
fw_params[2] = fw->size >> 8;
fw_params[3] = fw->size & 0xff;
ret = af9013_write_ofsm_regs(state, 0x50fc,
fw_params, sizeof(fw_params));
if (ret)
goto error_release;
#define FW_ADDR 0x5100
#define LEN_MAX 16
for (remaining = fw->size; remaining > 0; remaining -= LEN_MAX) {
len = remaining;
if (len > LEN_MAX)
len = LEN_MAX;
ret = af9013_write_ofsm_regs(state,
FW_ADDR + fw->size - remaining,
(u8 *) &fw->data[fw->size - remaining], len);
if (ret) {
err("firmware download failed:%d", ret);
goto error_release;
}
}
ret = af9013_write_reg(state, 0xe205, 1);
if (ret)
goto error_release;
for (i = 0; i < 15; i++) {
msleep(100);
ret = af9013_read_reg(state, 0x98be, &val);
if (ret)
goto error_release;
deb_info("%s: firmware status:%02x\n", __func__, val);
if (val == 0x0c || val == 0x04)
break;
}
if (val == 0x04) {
err("firmware did not run");
ret = -1;
} else if (val != 0x0c) {
err("firmware boot timeout");
ret = -1;
}
error_release:
release_firmware(fw);
error:
exit:
if (!ret)
info("found a '%s' in warm state.", af9013_ops.info.name);
return ret;
}
static int af9013_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
int ret;
struct af9013_state *state = fe->demodulator_priv;
deb_info("%s: enable:%d\n", __func__, enable);
if (state->config.output_mode == AF9013_OUTPUT_MODE_USB)
ret = af9013_write_reg_bits(state, 0xd417, 3, 1, enable);
else
ret = af9013_write_reg_bits(state, 0xd607, 2, 1, enable);
return ret;
}
static void af9013_release(struct dvb_frontend *fe)
{
struct af9013_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *af9013_attach(const struct af9013_config *config,
struct i2c_adapter *i2c)
{
int ret;
struct af9013_state *state = NULL;
u8 buf[4], i;
state = kzalloc(sizeof(struct af9013_state), GFP_KERNEL);
if (state == NULL)
goto error;
state->i2c = i2c;
memcpy(&state->config, config, sizeof(struct af9013_config));
if (state->config.output_mode != AF9013_OUTPUT_MODE_USB) {
ret = af9013_download_firmware(state);
if (ret)
goto error;
}
for (i = 0; i < 4; i++) {
ret = af9013_read_reg(state, 0x5103 + i, &buf[i]);
if (ret)
goto error;
}
info("firmware version:%d.%d.%d.%d", buf[0], buf[1], buf[2], buf[3]);
ret = af9013_read_reg_bits(state, 0xd733, 4, 4, &buf[2]);
if (ret)
goto error;
for (i = 0; i < 2; i++) {
ret = af9013_read_reg(state, 0x116b + i, &buf[i]);
if (ret)
goto error;
}
deb_info("%s: chip version:%d ROM version:%d.%d\n", __func__,
buf[2], buf[0], buf[1]);
if (state->config.output_mode == AF9013_OUTPUT_MODE_USB) {
ret = af9013_write_reg_bits(state, 0xd50b, 2, 1, 1);
} else {
ret = af9013_write_reg_bits(state, 0xd500, 3, 1, 1);
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd502, 4, 1, 1);
}
if (ret)
goto error;
ret = af9013_write_reg_bits(state, 0xd520, 4, 1, 1);
if (ret)
goto error;
for (i = 0; i < sizeof(state->config.gpio); i++) {
ret = af9013_set_gpio(state, i, state->config.gpio[i]);
if (ret)
goto error;
}
memcpy(&state->frontend.ops, &af9013_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
