static int it913x_read_reg(struct it913x_fe_state *state,
u32 reg, u8 *data, u8 count)
{
int ret;
u8 pro = PRO_DMOD;
u8 b[4];
struct i2c_msg msg[2] = {
{ .addr = state->i2c_addr + (pro << 1), .flags = 0,
.buf = b, .len = sizeof(b) },
{ .addr = state->i2c_addr + (pro << 1), .flags = I2C_M_RD,
.buf = data, .len = count }
};
b[0] = (u8) reg >> 24;
b[1] = (u8)(reg >> 16) & 0xff;
b[2] = (u8)(reg >> 8) & 0xff;
b[3] = (u8) reg & 0xff;
ret = i2c_transfer(state->i2c_adap, msg, 2);
return ret;
}
static int it913x_read_reg_u8(struct it913x_fe_state *state, u32 reg)
{
int ret;
u8 b[1];
ret = it913x_read_reg(state, reg, &b[0], sizeof(b));
return (ret < 0) ? -ENODEV : b[0];
}
static int it913x_write(struct it913x_fe_state *state,
u8 pro, u32 reg, u8 buf[], u8 count)
{
u8 b[256];
struct i2c_msg msg[1] = {
{ .addr = state->i2c_addr + (pro << 1), .flags = 0,
.buf = b, .len = count + 4 }
};
int ret;
b[0] = (u8) reg >> 24;
b[1] = (u8)(reg >> 16) & 0xff;
b[2] = (u8)(reg >> 8) & 0xff;
b[3] = (u8) reg & 0xff;
memcpy(&b[4], buf, count);
ret = i2c_transfer(state->i2c_adap, msg, 1);
if (ret < 0)
return -EIO;
return 0;
}
static int it913x_write_reg(struct it913x_fe_state *state,
u8 pro, u32 reg, u32 data)
{
int ret;
u8 b[4];
u8 s;
b[0] = data >> 24;
b[1] = (data >> 16) & 0xff;
b[2] = (data >> 8) & 0xff;
b[3] = data & 0xff;
if (data < 0x100)
s = 3;
else if (data < 0x1000)
s = 2;
else if (data < 0x100000)
s = 1;
else
s = 0;
ret = it913x_write(state, pro, reg, &b[s], sizeof(b) - s);
return ret;
}
static int it913x_fe_script_loader(struct it913x_fe_state *state,
struct it913xset *loadscript)
{
int ret, i;
if (loadscript == NULL)
return -EINVAL;
for (i = 0; i < 1000; ++i) {
if (loadscript[i].pro == 0xff)
break;
ret = it913x_write(state, loadscript[i].pro,
loadscript[i].address,
loadscript[i].reg, loadscript[i].count);
if (ret < 0)
return -ENODEV;
}
return 0;
}
static int it913x_init_tuner(struct it913x_fe_state *state)
{
int ret, i, reg;
u8 val, nv_val;
u8 nv[] = {48, 32, 24, 16, 12, 8, 6, 4, 2};
u8 b[2];
reg = it913x_read_reg_u8(state, 0xec86);
switch (reg) {
case 0:
state->tun_clk_mode = reg;
state->tun_xtal = 2000;
state->tun_fdiv = 3;
val = 16;
break;
case -ENODEV:
return -ENODEV;
case 1:
default:
state->tun_clk_mode = reg;
state->tun_xtal = 640;
state->tun_fdiv = 1;
val = 6;
break;
}
reg = it913x_read_reg_u8(state, 0xed03);
if (reg < 0)
return -ENODEV;
else if (reg < ARRAY_SIZE(nv))
nv_val = nv[reg];
else
nv_val = 2;
for (i = 0; i < 50; i++) {
ret = it913x_read_reg(state, 0xed23, &b[0], sizeof(b));
reg = (b[1] << 8) + b[0];
if (reg > 0)
break;
if (ret < 0)
return -ENODEV;
udelay(2000);
}
state->tun_fn_min = state->tun_xtal * reg;
state->tun_fn_min /= (state->tun_fdiv * nv_val);
deb_info("Tuner fn_min %d", state->tun_fn_min);
if (state->config->chip_ver > 1)
msleep(50);
else {
for (i = 0; i < 50; i++) {
reg = it913x_read_reg_u8(state, 0xec82);
if (reg > 0)
break;
if (reg < 0)
return -ENODEV;
udelay(2000);
}
}
return it913x_write_reg(state, PRO_DMOD, 0xed81, val);
}
static int it9137_set_tuner(struct it913x_fe_state *state,
u32 bandwidth, u32 frequency_m)
{
struct it913xset *set_tuner = set_it9137_template;
int ret, reg;
u32 frequency = frequency_m / 1000;
u32 freq, temp_f, tmp;
u16 iqik_m_cal;
u16 n_div;
u8 n;
u8 l_band;
u8 lna_band;
u8 bw;
if (state->config->firmware_ver == 1)
set_tuner = set_it9135_template;
else
set_tuner = set_it9137_template;
deb_info("Tuner Frequency %d Bandwidth %d", frequency, bandwidth);
if (frequency >= 51000 && frequency <= 440000) {
l_band = 0;
lna_band = 0;
} else if (frequency > 440000 && frequency <= 484000) {
l_band = 1;
lna_band = 1;
} else if (frequency > 484000 && frequency <= 533000) {
l_band = 1;
lna_band = 2;
} else if (frequency > 533000 && frequency <= 587000) {
l_band = 1;
lna_band = 3;
} else if (frequency > 587000 && frequency <= 645000) {
l_band = 1;
lna_band = 4;
} else if (frequency > 645000 && frequency <= 710000) {
l_band = 1;
lna_band = 5;
} else if (frequency > 710000 && frequency <= 782000) {
l_band = 1;
lna_band = 6;
} else if (frequency > 782000 && frequency <= 860000) {
l_band = 1;
lna_band = 7;
} else if (frequency > 1450000 && frequency <= 1492000) {
l_band = 1;
lna_band = 0;
} else if (frequency > 1660000 && frequency <= 1685000) {
l_band = 1;
lna_band = 1;
} else
return -EINVAL;
set_tuner[0].reg[0] = lna_band;
switch (bandwidth) {
case 5000000:
bw = 0;
break;
case 6000000:
bw = 2;
break;
case 7000000:
bw = 4;
break;
default:
case 8000000:
bw = 6;
break;
}
set_tuner[1].reg[0] = bw;
set_tuner[2].reg[0] = 0xa0 | (l_band << 3);
if (frequency > 53000 && frequency <= 74000) {
n_div = 48;
n = 0;
} else if (frequency > 74000 && frequency <= 111000) {
n_div = 32;
n = 1;
} else if (frequency > 111000 && frequency <= 148000) {
n_div = 24;
n = 2;
} else if (frequency > 148000 && frequency <= 222000) {
n_div = 16;
n = 3;
} else if (frequency > 222000 && frequency <= 296000) {
n_div = 12;
n = 4;
} else if (frequency > 296000 && frequency <= 445000) {
n_div = 8;
n = 5;
} else if (frequency > 445000 && frequency <= state->tun_fn_min) {
n_div = 6;
n = 6;
} else if (frequency > state->tun_fn_min && frequency <= 950000) {
n_div = 4;
n = 7;
} else if (frequency > 1450000 && frequency <= 1680000) {
n_div = 2;
n = 0;
} else
return -EINVAL;
reg = it913x_read_reg_u8(state, 0xed81);
iqik_m_cal = (u16)reg * n_div;
if (reg < 0x20) {
if (state->tun_clk_mode == 0)
iqik_m_cal = (iqik_m_cal * 9) >> 5;
else
iqik_m_cal >>= 1;
} else {
iqik_m_cal = 0x40 - iqik_m_cal;
if (state->tun_clk_mode == 0)
iqik_m_cal = ~((iqik_m_cal * 9) >> 5);
else
iqik_m_cal = ~(iqik_m_cal >> 1);
}
temp_f = frequency * (u32)n_div * (u32)state->tun_fdiv;
freq = temp_f / state->tun_xtal;
tmp = freq * state->tun_xtal;
if ((temp_f - tmp) >= (state->tun_xtal >> 1))
freq++;
freq += (u32) n << 13;
temp_f = freq + (u32)iqik_m_cal;
set_tuner[3].reg[0] = temp_f & 0xff;
set_tuner[4].reg[0] = (temp_f >> 8) & 0xff;
deb_info("High Frequency = %04x", temp_f);
set_tuner[5].reg[0] = freq & 0xff;
set_tuner[6].reg[0] = (freq >> 8) & 0xff;
deb_info("low Frequency = %04x", freq);
ret = it913x_fe_script_loader(state, set_tuner);
return (ret < 0) ? -ENODEV : 0;
}
static int it913x_fe_select_bw(struct it913x_fe_state *state,
u32 bandwidth, u32 adcFrequency)
{
int ret, i;
u8 buffer[256];
u32 coeff[8];
u16 bfsfcw_fftinx_ratio;
u16 fftinx_bfsfcw_ratio;
u8 count;
u8 bw;
u8 adcmultiplier;
deb_info("Bandwidth %d Adc %d", bandwidth, adcFrequency);
switch (bandwidth) {
case 5000000:
bw = 3;
break;
case 6000000:
bw = 0;
break;
case 7000000:
bw = 1;
break;
default:
case 8000000:
bw = 2;
break;
}
ret = it913x_write_reg(state, PRO_DMOD, REG_BW, bw);
if (state->table == NULL)
return -EINVAL;
coeff[0] = state->table[bw].coeff_1_2048;
coeff[1] = state->table[bw].coeff_2_2k;
coeff[2] = state->table[bw].coeff_1_8191;
coeff[3] = state->table[bw].coeff_1_8192;
coeff[4] = state->table[bw].coeff_1_8193;
coeff[5] = state->table[bw].coeff_2_8k;
coeff[6] = state->table[bw].coeff_1_4096;
coeff[7] = state->table[bw].coeff_2_4k;
bfsfcw_fftinx_ratio = state->table[bw].bfsfcw_fftinx_ratio;
fftinx_bfsfcw_ratio = state->table[bw].fftinx_bfsfcw_ratio;
ret = it913x_read_reg_u8(state, ADC_X_2);
if (ret < 0)
return -EINVAL;
adcmultiplier = ret;
count = 0;
for (i = 0; i < 8; i++) {
if (adcmultiplier == 1)
coeff[i] /= 2;
buffer[count++] = (coeff[i] >> 24) & 0x3;
buffer[count++] = (coeff[i] >> 16) & 0xff;
buffer[count++] = (coeff[i] >> 8) & 0xff;
buffer[count++] = coeff[i] & 0xff;
}
buffer[count++] = bfsfcw_fftinx_ratio & 0xff;
buffer[count++] = (bfsfcw_fftinx_ratio >> 8) & 0xff;
buffer[count++] = fftinx_bfsfcw_ratio & 0xff;
buffer[count++] = (fftinx_bfsfcw_ratio >> 8) & 0xff;
ret = it913x_write(state, PRO_DMOD, COEFF_1_2048, buffer, count);
for (i = 0; i < 42; i += 8)
debug_data_snipet(0x1, "Buffer", &buffer[i]);
return ret;
}
static int it913x_fe_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct it913x_fe_state *state = fe->demodulator_priv;
int ret, i;
fe_status_t old_status = state->it913x_status;
*status = 0;
if (state->it913x_status == 0) {
ret = it913x_read_reg_u8(state, EMPTY_CHANNEL_STATUS);
if (ret == 0x1) {
*status |= FE_HAS_SIGNAL;
for (i = 0; i < 40; i++) {
ret = it913x_read_reg_u8(state, MP2IF_SYNC_LK);
if (ret == 0x1)
break;
msleep(25);
}
if (ret == 0x1)
*status |= FE_HAS_CARRIER
| FE_HAS_VITERBI
| FE_HAS_SYNC;
state->it913x_status = *status;
}
}
if (state->it913x_status & FE_HAS_SYNC) {
ret = it913x_read_reg_u8(state, TPSD_LOCK);
if (ret == 0x1)
*status |= FE_HAS_LOCK
| state->it913x_status;
else
state->it913x_status = 0;
if (old_status != state->it913x_status)
ret = it913x_write_reg(state, PRO_LINK, GPIOH3_O, ret);
}
return 0;
}
static int it913x_get_signal_strength(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct it913x_fe_state *state = fe->demodulator_priv;
u8 code_rate;
int ret, temp;
u8 lna_gain_os;
ret = it913x_read_reg_u8(state, VAR_P_INBAND);
if (ret < 0)
return ret;
if (state->frequency < 300000000)
lna_gain_os = 7;
else
lna_gain_os = 14;
temp = (ret - 100) - lna_gain_os;
if (state->priority == PRIORITY_HIGH)
code_rate = p->code_rate_HP;
else
code_rate = p->code_rate_LP;
if (code_rate >= ARRAY_SIZE(it913x_qpsk_pval))
return -EINVAL;
deb_info("Reg VAR_P_INBAND:%d Calc Offset Value:%d", ret, temp);
switch (p->modulation) {
case QPSK:
temp -= it913x_qpsk_pval[code_rate];
break;
case QAM_16:
temp -= it913x_16qam_pval[code_rate];
break;
case QAM_64:
temp -= it913x_64qam_pval[code_rate];
break;
default:
return -EINVAL;
}
if (temp < -15)
ret = 0;
else if ((-15 <= temp) && (temp < 0))
ret = (2 * (temp + 15)) / 3;
else if ((0 <= temp) && (temp < 20))
ret = 4 * temp + 10;
else if ((20 <= temp) && (temp < 35))
ret = (2 * (temp - 20)) / 3 + 90;
else if (temp >= 35)
ret = 100;
deb_info("Signal Strength :%d", ret);
return ret;
}
static int it913x_fe_read_signal_strength(struct dvb_frontend *fe,
u16 *strength)
{
struct it913x_fe_state *state = fe->demodulator_priv;
int ret = 0;
if (state->config->read_slevel) {
if (state->it913x_status & FE_HAS_SIGNAL)
ret = it913x_read_reg_u8(state, SIGNAL_LEVEL);
} else
ret = it913x_get_signal_strength(fe);
if (ret >= 0)
*strength = (u16)((u32)ret * 0xffff / 0x64);
return (ret < 0) ? -ENODEV : 0;
}
static int it913x_fe_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct it913x_fe_state *state = fe->demodulator_priv;
int ret;
u8 reg[3];
u32 snr_val, snr_min, snr_max;
u32 temp;
ret = it913x_read_reg(state, 0x2c, reg, sizeof(reg));
snr_val = (u32)(reg[2] << 16) | (reg[1] << 8) | reg[0];
ret |= it913x_read_reg(state, 0xf78b, reg, 1);
if (reg[0])
snr_val /= reg[0];
if (state->transmission_mode == TRANSMISSION_MODE_2K)
snr_val *= 4;
else if (state->transmission_mode == TRANSMISSION_MODE_4K)
snr_val *= 2;
if (state->constellation == QPSK) {
snr_min = 0xb4711;
snr_max = 0x191451;
} else if (state->constellation == QAM_16) {
snr_min = 0x4f0d5;
snr_max = 0xc7925;
} else if (state->constellation == QAM_64) {
snr_min = 0x256d0;
snr_max = 0x626be;
} else
return -EINVAL;
if (snr_val < snr_min)
*snr = 0;
else if (snr_val < snr_max) {
temp = (snr_val - snr_min) >> 5;
temp *= 0xffff;
temp /= (snr_max - snr_min) >> 5;
*snr = (u16)temp;
} else
*snr = 0xffff;
return (ret < 0) ? -ENODEV : 0;
}
static int it913x_fe_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct it913x_fe_state *state = fe->demodulator_priv;
u8 reg[5];
it913x_read_reg(state, RSD_ABORT_PKT_LSB, reg, sizeof(reg));
state->ucblocks += (u32)(reg[1] << 8) | reg[0];
*ber = (u32)(reg[4] << 16) | (reg[3] << 8) | reg[2];
return 0;
}
static int it913x_fe_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct it913x_fe_state *state = fe->demodulator_priv;
int ret;
u8 reg[2];
ret = it913x_read_reg(state, RSD_ABORT_PKT_LSB, reg, sizeof(reg));
state->ucblocks += (u32)(reg[1] << 8) | reg[0];
*ucblocks = state->ucblocks;
return ret;
}
static int it913x_fe_get_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct it913x_fe_state *state = fe->demodulator_priv;
u8 reg[8];
it913x_read_reg(state, REG_TPSD_TX_MODE, reg, sizeof(reg));
if (reg[3] < 3)
p->modulation = fe_con[reg[3]];
if (reg[0] < 3)
p->transmission_mode = fe_mode[reg[0]];
if (reg[1] < 4)
p->guard_interval = fe_gi[reg[1]];
if (reg[2] < 4)
p->hierarchy = fe_hi[reg[2]];
state->priority = reg[5];
p->code_rate_HP = (reg[6] < 6) ? fe_code[reg[6]] : FEC_NONE;
p->code_rate_LP = (reg[7] < 6) ? fe_code[reg[7]] : FEC_NONE;
state->constellation = p->modulation;
state->transmission_mode = p->transmission_mode;
return 0;
}
static int it913x_fe_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct it913x_fe_state *state = fe->demodulator_priv;
int i;
u8 empty_ch, last_ch;
state->it913x_status = 0;
it913x_fe_select_bw(state, p->bandwidth_hz,
state->adcFrequency);
it913x_write_reg(state, PRO_LINK, TRAINING_MODE, 0x0);
it913x_write_reg(state, PRO_DMOD, EMPTY_CHANNEL_STATUS, 0x0);
it913x_write_reg(state, PRO_DMOD, MP2IF_SYNC_LK, 0x0);
it913x_write_reg(state, PRO_LINK, GPIOH3_O, 0x1);
if ((p->frequency >= 51000000) && (p->frequency <= 230000000))
i = 0;
else if ((p->frequency >= 350000000) && (p->frequency <= 900000000))
i = 1;
else if ((p->frequency >= 1450000000) && (p->frequency <= 1680000000))
i = 2;
else
return -EOPNOTSUPP;
it913x_write_reg(state, PRO_DMOD, FREE_BAND, i);
deb_info("Frontend Set Tuner Type %02x", state->tuner_type);
switch (state->tuner_type) {
case IT9135_38:
case IT9135_51:
case IT9135_52:
case IT9135_60:
case IT9135_61:
case IT9135_62:
it9137_set_tuner(state,
p->bandwidth_hz, p->frequency);
break;
default:
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
break;
}
it913x_write_reg(state, PRO_LINK, GPIOH3_O, 0x0);
it913x_write_reg(state, PRO_DMOD, TRIGGER_OFSM, 0x0);
last_ch = 2;
for (i = 0; i < 40; ++i) {
empty_ch = it913x_read_reg_u8(state, EMPTY_CHANNEL_STATUS);
if (last_ch == 1 && empty_ch == 1)
break;
if (last_ch == 2 && empty_ch == 2)
return 0;
last_ch = empty_ch;
msleep(25);
}
for (i = 0; i < 40; ++i) {
if (it913x_read_reg_u8(state, D_TPSD_LOCK) == 1)
break;
msleep(25);
}
state->frequency = p->frequency;
return 0;
}
static int it913x_fe_suspend(struct it913x_fe_state *state)
{
int ret, i;
u8 b;
ret = it913x_write_reg(state, PRO_DMOD, SUSPEND_FLAG, 0x1);
ret |= it913x_write_reg(state, PRO_DMOD, TRIGGER_OFSM, 0x0);
for (i = 0; i < 128; i++) {
ret = it913x_read_reg(state, SUSPEND_FLAG, &b, 1);
if (ret < 0)
return -ENODEV;
if (b == 0)
break;
}
ret |= it913x_write_reg(state, PRO_DMOD, AFE_MEM0, 0x8);
ret |= it913x_write_reg(state, PRO_LINK, GPIOH3_O, 0x0);
ret |= it913x_fe_script_loader(state, it9137_tuner_off);
return (ret < 0) ? -ENODEV : 0;
}
static int it913x_fe_sleep(struct dvb_frontend *fe)
{
struct it913x_fe_state *state = fe->demodulator_priv;
return it913x_fe_suspend(state);
}
static u32 compute_div(u32 a, u32 b, u32 x)
{
u32 res = 0;
u32 c = 0;
u32 i = 0;
if (a > b) {
c = a / b;
a = a - c * b;
}
for (i = 0; i < x; i++) {
if (a >= b) {
res += 1;
a -= b;
}
a <<= 1;
res <<= 1;
}
res = (c << x) + res;
return res;
}
static int it913x_fe_start(struct it913x_fe_state *state)
{
struct it913xset *set_lna;
struct it913xset *set_mode;
int ret;
u8 adf = (state->config->adf & 0xf);
u32 adc, xtal;
u8 b[4];
if (state->config->chip_ver == 1)
ret = it913x_init_tuner(state);
info("ADF table value :%02x", adf);
if (adf < 10) {
state->crystalFrequency = fe_clockTable[adf].xtal ;
state->table = fe_clockTable[adf].table;
state->adcFrequency = state->table->adcFrequency;
adc = compute_div(state->adcFrequency, 1000000ul, 19ul);
xtal = compute_div(state->crystalFrequency, 1000000ul, 19ul);
} else
return -EINVAL;
ret = it913x_write_reg(state, PRO_LINK, GPIOH3_EN, 0x1);
ret |= it913x_write_reg(state, PRO_LINK, GPIOH3_ON, 0x1);
ret |= it913x_write_reg(state, PRO_LINK, GPIOH3_O, 0x1);
ret |= it913x_write_reg(state, PRO_LINK, 0xf641, state->tuner_type);
ret |= it913x_write_reg(state, PRO_DMOD, 0xf5ca, 0x01);
ret |= it913x_write_reg(state, PRO_DMOD, 0xf715, 0x01);
b[0] = xtal & 0xff;
b[1] = (xtal >> 8) & 0xff;
b[2] = (xtal >> 16) & 0xff;
b[3] = (xtal >> 24);
ret |= it913x_write(state, PRO_DMOD, XTAL_CLK, b , 4);
b[0] = adc & 0xff;
b[1] = (adc >> 8) & 0xff;
b[2] = (adc >> 16) & 0xff;
ret |= it913x_write(state, PRO_DMOD, ADC_FREQ, b, 3);
if (state->config->adc_x2)
ret |= it913x_write_reg(state, PRO_DMOD, ADC_X_2, 0x01);
b[0] = 0;
b[1] = 0;
b[2] = 0;
ret |= it913x_write(state, PRO_DMOD, 0x0029, b, 3);
info("Crystal Frequency :%d Adc Frequency :%d ADC X2: %02x",
state->crystalFrequency, state->adcFrequency,
state->config->adc_x2);
deb_info("Xtal value :%04x Adc value :%04x", xtal, adc);
if (ret < 0)
return -ENODEV;
if (state->config->chip_ver > 1)
ret = it913x_fe_script_loader(state, it9135_v2);
else
ret = it913x_fe_script_loader(state, it9135_v1);
if (ret < 0)
return ret;
switch (state->tuner_type) {
case IT9135_51:
set_lna = it9135_51;
break;
case IT9135_52:
set_lna = it9135_52;
break;
case IT9135_60:
set_lna = it9135_60;
break;
case IT9135_61:
set_lna = it9135_61;
break;
case IT9135_62:
set_lna = it9135_62;
break;
case IT9135_38:
default:
set_lna = it9135_38;
}
info("Tuner LNA type :%02x", state->tuner_type);
ret = it913x_fe_script_loader(state, set_lna);
if (ret < 0)
return ret;
if (state->config->chip_ver == 2) {
ret = it913x_write_reg(state, PRO_DMOD, TRIGGER_OFSM, 0x1);
ret |= it913x_write_reg(state, PRO_LINK, PADODPU, 0x0);
ret |= it913x_write_reg(state, PRO_LINK, AGC_O_D, 0x0);
ret |= it913x_init_tuner(state);
}
if (ret < 0)
return -ENODEV;
set_mode = set_solo_fe;
ret |= it913x_fe_script_loader(state, set_mode);
ret |= it913x_fe_suspend(state);
return (ret < 0) ? -ENODEV : 0;
}
static int it913x_fe_init(struct dvb_frontend *fe)
{
struct it913x_fe_state *state = fe->demodulator_priv;
int ret = 0;
ret = it913x_write_reg(state, PRO_DMOD, 0xec40, 0x1);
ret |= it913x_fe_script_loader(state, init_1);
ret |= it913x_write_reg(state, PRO_DMOD, AFE_MEM0, 0x0);
ret |= it913x_write_reg(state, PRO_DMOD, 0xfba8, 0x0);
return (ret < 0) ? -ENODEV : 0;
}
static void it913x_fe_release(struct dvb_frontend *fe)
{
struct it913x_fe_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend *it913x_fe_attach(struct i2c_adapter *i2c_adap,
u8 i2c_addr, struct ite_config *config)
{
struct it913x_fe_state *state = NULL;
int ret;
state = kzalloc(sizeof(struct it913x_fe_state), GFP_KERNEL);
if (state == NULL)
return NULL;
if (config == NULL)
goto error;
state->i2c_adap = i2c_adap;
state->i2c_addr = i2c_addr;
state->config = config;
switch (state->config->tuner_id_0) {
case IT9135_51:
case IT9135_52:
case IT9135_60:
case IT9135_61:
case IT9135_62:
state->tuner_type = state->config->tuner_id_0;
break;
default:
case IT9135_38:
state->tuner_type = IT9135_38;
}
ret = it913x_fe_start(state);
if (ret < 0)
goto error;
memcpy(&state->frontend.ops, &it913x_fe_ofdm_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
