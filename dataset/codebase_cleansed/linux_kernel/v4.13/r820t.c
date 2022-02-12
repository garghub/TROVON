static void shadow_store(struct r820t_priv *priv, u8 reg, const u8 *val,
int len)
{
int r = reg - REG_SHADOW_START;
if (r < 0) {
len += r;
r = 0;
}
if (len <= 0)
return;
if (len > NUM_REGS - r)
len = NUM_REGS - r;
tuner_dbg("%s: prev reg=%02x len=%d: %*ph\n",
__func__, r + REG_SHADOW_START, len, len, val);
memcpy(&priv->regs[r], val, len);
}
static int r820t_write(struct r820t_priv *priv, u8 reg, const u8 *val,
int len)
{
int rc, size, pos = 0;
shadow_store(priv, reg, val, len);
do {
if (len > priv->cfg->max_i2c_msg_len - 1)
size = priv->cfg->max_i2c_msg_len - 1;
else
size = len;
priv->buf[0] = reg;
memcpy(&priv->buf[1], &val[pos], size);
rc = tuner_i2c_xfer_send(&priv->i2c_props, priv->buf, size + 1);
if (rc != size + 1) {
tuner_info("%s: i2c wr failed=%d reg=%02x len=%d: %*ph\n",
__func__, rc, reg, size, size, &priv->buf[1]);
if (rc < 0)
return rc;
return -EREMOTEIO;
}
tuner_dbg("%s: i2c wr reg=%02x len=%d: %*ph\n",
__func__, reg, size, size, &priv->buf[1]);
reg += size;
len -= size;
pos += size;
} while (len > 0);
return 0;
}
static int r820t_write_reg(struct r820t_priv *priv, u8 reg, u8 val)
{
return r820t_write(priv, reg, &val, 1);
}
static int r820t_read_cache_reg(struct r820t_priv *priv, int reg)
{
reg -= REG_SHADOW_START;
if (reg >= 0 && reg < NUM_REGS)
return priv->regs[reg];
else
return -EINVAL;
}
static int r820t_write_reg_mask(struct r820t_priv *priv, u8 reg, u8 val,
u8 bit_mask)
{
int rc = r820t_read_cache_reg(priv, reg);
if (rc < 0)
return rc;
val = (rc & ~bit_mask) | (val & bit_mask);
return r820t_write(priv, reg, &val, 1);
}
static int r820t_read(struct r820t_priv *priv, u8 reg, u8 *val, int len)
{
int rc, i;
u8 *p = &priv->buf[1];
priv->buf[0] = reg;
rc = tuner_i2c_xfer_send_recv(&priv->i2c_props, priv->buf, 1, p, len);
if (rc != len) {
tuner_info("%s: i2c rd failed=%d reg=%02x len=%d: %*ph\n",
__func__, rc, reg, len, len, p);
if (rc < 0)
return rc;
return -EREMOTEIO;
}
for (i = 0; i < len; i++)
val[i] = bitrev8(p[i]);
tuner_dbg("%s: i2c rd reg=%02x len=%d: %*ph\n",
__func__, reg, len, len, val);
return 0;
}
static int r820t_set_mux(struct r820t_priv *priv, u32 freq)
{
const struct r820t_freq_range *range;
int i, rc;
u8 val, reg08, reg09;
freq = freq / 1000000;
for (i = 0; i < ARRAY_SIZE(freq_ranges) - 1; i++) {
if (freq < freq_ranges[i + 1].freq)
break;
}
range = &freq_ranges[i];
tuner_dbg("set r820t range#%d for frequency %d MHz\n", i, freq);
rc = r820t_write_reg_mask(priv, 0x17, range->open_d, 0x08);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, range->rf_mux_ploy, 0xc3);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x1b, range->tf_c);
if (rc < 0)
return rc;
switch (priv->xtal_cap_sel) {
case XTAL_LOW_CAP_30P:
case XTAL_LOW_CAP_20P:
val = range->xtal_cap20p | 0x08;
break;
case XTAL_LOW_CAP_10P:
val = range->xtal_cap10p | 0x08;
break;
case XTAL_HIGH_CAP_0P:
val = range->xtal_cap0p | 0x00;
break;
default:
case XTAL_LOW_CAP_0P:
val = range->xtal_cap0p | 0x08;
break;
}
rc = r820t_write_reg_mask(priv, 0x10, val, 0x0b);
if (rc < 0)
return rc;
if (priv->imr_done) {
reg08 = priv->imr_data[range->imr_mem].gain_x;
reg09 = priv->imr_data[range->imr_mem].phase_y;
} else {
reg08 = 0;
reg09 = 0;
}
rc = r820t_write_reg_mask(priv, 0x08, reg08, 0x3f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x09, reg09, 0x3f);
return rc;
}
static int r820t_set_pll(struct r820t_priv *priv, enum v4l2_tuner_type type,
u32 freq)
{
u32 vco_freq;
int rc, i;
unsigned sleep_time = 10000;
u32 vco_fra;
u32 vco_min = 1770000;
u32 vco_max = vco_min * 2;
u32 pll_ref;
u16 n_sdm = 2;
u16 sdm = 0;
u8 mix_div = 2;
u8 div_buf = 0;
u8 div_num = 0;
u8 refdiv2 = 0;
u8 ni, si, nint, vco_fine_tune, val;
u8 data[5];
freq = freq / 1000;
pll_ref = priv->cfg->xtal / 1000;
#if 0
if ((priv->cfg->rafael_chip == CHIP_R620D) ||
(priv->cfg->rafael_chip == CHIP_R828D) ||
(priv->cfg->rafael_chip == CHIP_R828)) {
if (type != V4L2_TUNER_DIGITAL_TV) {
pll_ref /= 2;
refdiv2 = 0x10;
sleep_time = 20000;
}
} else {
if (priv->cfg->xtal > 24000000) {
pll_ref /= 2;
refdiv2 = 0x10;
}
}
#endif
rc = r820t_write_reg_mask(priv, 0x10, refdiv2, 0x10);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, 0x00, 0x0c);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x12, 0x80, 0xe0);
if (rc < 0)
return rc;
while (mix_div <= 64) {
if (((freq * mix_div) >= vco_min) &&
((freq * mix_div) < vco_max)) {
div_buf = mix_div;
while (div_buf > 2) {
div_buf = div_buf >> 1;
div_num++;
}
break;
}
mix_div = mix_div << 1;
}
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
return rc;
vco_fine_tune = (data[4] & 0x30) >> 4;
tuner_dbg("mix_div=%d div_num=%d vco_fine_tune=%d\n",
mix_div, div_num, vco_fine_tune);
if (priv->cfg->rafael_chip != CHIP_R828D) {
if (vco_fine_tune > VCO_POWER_REF)
div_num = div_num - 1;
else if (vco_fine_tune < VCO_POWER_REF)
div_num = div_num + 1;
}
rc = r820t_write_reg_mask(priv, 0x10, div_num << 5, 0xe0);
if (rc < 0)
return rc;
vco_freq = freq * mix_div;
nint = vco_freq / (2 * pll_ref);
vco_fra = vco_freq - 2 * pll_ref * nint;
if (vco_fra < pll_ref / 64) {
vco_fra = 0;
} else if (vco_fra > pll_ref * 127 / 64) {
vco_fra = 0;
nint++;
} else if ((vco_fra > pll_ref * 127 / 128) && (vco_fra < pll_ref)) {
vco_fra = pll_ref * 127 / 128;
} else if ((vco_fra > pll_ref) && (vco_fra < pll_ref * 129 / 128)) {
vco_fra = pll_ref * 129 / 128;
}
ni = (nint - 13) / 4;
si = nint - 4 * ni - 13;
rc = r820t_write_reg(priv, 0x14, ni + (si << 6));
if (rc < 0)
return rc;
if (!vco_fra)
val = 0x08;
else
val = 0x00;
rc = r820t_write_reg_mask(priv, 0x12, val, 0x08);
if (rc < 0)
return rc;
while (vco_fra > 1) {
if (vco_fra > (2 * pll_ref / n_sdm)) {
sdm = sdm + 32768 / (n_sdm / 2);
vco_fra = vco_fra - 2 * pll_ref / n_sdm;
if (n_sdm >= 0x8000)
break;
}
n_sdm = n_sdm << 1;
}
tuner_dbg("freq %d kHz, pll ref %d%s, sdm=0x%04x\n",
freq, pll_ref, refdiv2 ? " / 2" : "", sdm);
rc = r820t_write_reg(priv, 0x16, sdm >> 8);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x15, sdm & 0xff);
if (rc < 0)
return rc;
for (i = 0; i < 2; i++) {
usleep_range(sleep_time, sleep_time + 1000);
rc = r820t_read(priv, 0x00, data, 3);
if (rc < 0)
return rc;
if (data[2] & 0x40)
break;
if (!i) {
rc = r820t_write_reg_mask(priv, 0x12, 0x60, 0xe0);
if (rc < 0)
return rc;
}
}
if (!(data[2] & 0x40)) {
priv->has_lock = false;
return 0;
}
priv->has_lock = true;
tuner_dbg("tuner has lock at frequency %d kHz\n", freq);
rc = r820t_write_reg_mask(priv, 0x1a, 0x08, 0x08);
return rc;
}
static int r820t_sysfreq_sel(struct r820t_priv *priv, u32 freq,
enum v4l2_tuner_type type,
v4l2_std_id std,
u32 delsys)
{
int rc;
u8 mixer_top, lna_top, cp_cur, div_buf_cur, lna_vth_l, mixer_vth_l;
u8 air_cable1_in, cable2_in, pre_dect, lna_discharge, filter_cur;
tuner_dbg("adjusting tuner parameters for the standard\n");
switch (delsys) {
case SYS_DVBT:
if ((freq == 506000000) || (freq == 666000000) ||
(freq == 818000000)) {
mixer_top = 0x14;
lna_top = 0xe5;
cp_cur = 0x28;
div_buf_cur = 0x20;
} else {
mixer_top = 0x24;
lna_top = 0xe5;
cp_cur = 0x38;
div_buf_cur = 0x30;
}
lna_vth_l = 0x53;
mixer_vth_l = 0x75;
air_cable1_in = 0x00;
cable2_in = 0x00;
pre_dect = 0x40;
lna_discharge = 14;
filter_cur = 0x40;
break;
case SYS_DVBT2:
mixer_top = 0x24;
lna_top = 0xe5;
lna_vth_l = 0x53;
mixer_vth_l = 0x75;
air_cable1_in = 0x00;
cable2_in = 0x00;
pre_dect = 0x40;
lna_discharge = 14;
cp_cur = 0x38;
div_buf_cur = 0x30;
filter_cur = 0x40;
break;
case SYS_ISDBT:
mixer_top = 0x24;
lna_top = 0xe5;
lna_vth_l = 0x75;
mixer_vth_l = 0x75;
air_cable1_in = 0x00;
cable2_in = 0x00;
pre_dect = 0x40;
lna_discharge = 14;
cp_cur = 0x38;
div_buf_cur = 0x30;
filter_cur = 0x40;
break;
case SYS_DVBC_ANNEX_A:
mixer_top = 0x24;
lna_top = 0xe5;
lna_vth_l = 0x62;
mixer_vth_l = 0x75;
air_cable1_in = 0x60;
cable2_in = 0x00;
pre_dect = 0x40;
lna_discharge = 14;
cp_cur = 0x38;
div_buf_cur = 0x30;
filter_cur = 0x40;
break;
default:
mixer_top = 0x24;
lna_top = 0xe5;
lna_vth_l = 0x53;
mixer_vth_l = 0x75;
air_cable1_in = 0x00;
cable2_in = 0x00;
pre_dect = 0x40;
lna_discharge = 14;
cp_cur = 0x38;
div_buf_cur = 0x30;
filter_cur = 0x40;
break;
}
if (priv->cfg->use_diplexer &&
((priv->cfg->rafael_chip == CHIP_R820T) ||
(priv->cfg->rafael_chip == CHIP_R828S) ||
(priv->cfg->rafael_chip == CHIP_R820C))) {
if (freq > DIP_FREQ)
air_cable1_in = 0x00;
else
air_cable1_in = 0x60;
cable2_in = 0x00;
}
if (priv->cfg->use_predetect) {
rc = r820t_write_reg_mask(priv, 0x06, pre_dect, 0x40);
if (rc < 0)
return rc;
}
rc = r820t_write_reg_mask(priv, 0x1d, lna_top, 0xc7);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1c, mixer_top, 0xf8);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x0d, lna_vth_l);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x0e, mixer_vth_l);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x05, air_cable1_in, 0x60);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x06, cable2_in, 0x08);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x11, cp_cur, 0x38);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x17, div_buf_cur, 0x30);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0a, filter_cur, 0x60);
if (rc < 0)
return rc;
tuner_dbg("adjusting LNA parameters\n");
if (type != V4L2_TUNER_ANALOG_TV) {
rc = r820t_write_reg_mask(priv, 0x1d, 0, 0x38);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1c, 0, 0x04);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x06, 0, 0x40);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, 0x30, 0x30);
if (rc < 0)
return rc;
msleep(250);
rc = r820t_write_reg_mask(priv, 0x1d, 0x18, 0x38);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1c, mixer_top, 0x04);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1e, lna_discharge, 0x1f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, 0x20, 0x30);
if (rc < 0)
return rc;
} else {
rc = r820t_write_reg_mask(priv, 0x06, 0, 0x40);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1d, lna_top, 0x38);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1c, mixer_top, 0x04);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1e, lna_discharge, 0x1f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, 0x00, 0x30);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x10, 0x00, 0x04);
if (rc < 0)
return rc;
}
return 0;
}
static int r820t_set_tv_standard(struct r820t_priv *priv,
unsigned bw,
enum v4l2_tuner_type type,
v4l2_std_id std, u32 delsys)
{
int rc, i;
u32 if_khz, filt_cal_lo;
u8 data[5], val;
u8 filt_gain, img_r, filt_q, hp_cor, ext_enable, loop_through;
u8 lt_att, flt_ext_widest, polyfil_cur;
bool need_calibration;
tuner_dbg("selecting the delivery system\n");
if (delsys == SYS_ISDBT) {
if_khz = 4063;
filt_cal_lo = 59000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x6a;
ext_enable = 0x40;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x80;
polyfil_cur = 0x60;
} else if (delsys == SYS_DVBC_ANNEX_A) {
if_khz = 5070;
filt_cal_lo = 73500;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x0b;
ext_enable = 0x40;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
} else if (delsys == SYS_DVBC_ANNEX_C) {
if_khz = 4063;
filt_cal_lo = 55000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x6a;
ext_enable = 0x40;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x80;
polyfil_cur = 0x60;
} else {
if (bw <= 6) {
if_khz = 3570;
filt_cal_lo = 56000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x6b;
ext_enable = 0x60;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
} else if (bw == 7) {
#if 0
if_khz = 4070;
filt_cal_lo = 60000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x2b;
ext_enable = 0x60;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
#endif
if_khz = 4570;
filt_cal_lo = 63000;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x2a;
ext_enable = 0x60;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
} else {
if_khz = 4570;
filt_cal_lo = 68500;
filt_gain = 0x10;
img_r = 0x00;
filt_q = 0x10;
hp_cor = 0x0b;
ext_enable = 0x60;
loop_through = 0x00;
lt_att = 0x00;
flt_ext_widest = 0x00;
polyfil_cur = 0x60;
}
}
memcpy(priv->regs, r820t_init_array, sizeof(r820t_init_array));
if (priv->imr_done)
val = 1 | priv->xtal_cap_sel << 1;
else
val = 0;
rc = r820t_write_reg_mask(priv, 0x0c, val, 0x0f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x13, VER_NUM, 0x3f);
if (rc < 0)
return rc;
if (type != V4L2_TUNER_ANALOG_TV) {
rc = r820t_write_reg_mask(priv, 0x1d, 0x00, 0x38);
if (rc < 0)
return rc;
usleep_range(1000, 2000);
}
priv->int_freq = if_khz * 1000;
if (type != priv->type)
need_calibration = true;
else if ((type == V4L2_TUNER_ANALOG_TV) && (std != priv->std))
need_calibration = true;
else if ((type == V4L2_TUNER_DIGITAL_TV) &&
((delsys != priv->delsys) || bw != priv->bw))
need_calibration = true;
else
need_calibration = false;
if (need_calibration) {
tuner_dbg("calibrating the tuner\n");
for (i = 0; i < 2; i++) {
rc = r820t_write_reg_mask(priv, 0x0b, hp_cor, 0x60);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0f, 0x04, 0x04);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x10, 0x00, 0x03);
if (rc < 0)
return rc;
rc = r820t_set_pll(priv, type, filt_cal_lo * 1000);
if (rc < 0 || !priv->has_lock)
return rc;
rc = r820t_write_reg_mask(priv, 0x0b, 0x10, 0x10);
if (rc < 0)
return rc;
usleep_range(1000, 2000);
rc = r820t_write_reg_mask(priv, 0x0b, 0x00, 0x10);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0f, 0x00, 0x04);
if (rc < 0)
return rc;
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
return rc;
priv->fil_cal_code = data[4] & 0x0f;
if (priv->fil_cal_code && priv->fil_cal_code != 0x0f)
break;
}
if (priv->fil_cal_code == 0x0f)
priv->fil_cal_code = 0;
}
rc = r820t_write_reg_mask(priv, 0x0a,
filt_q | priv->fil_cal_code, 0x1f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0b, hp_cor, 0xef);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x07, img_r, 0x80);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x06, filt_gain, 0x30);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1e, ext_enable, 0x60);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x05, loop_through, 0x80);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1f, lt_att, 0x80);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0f, flt_ext_widest, 0x80);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x19, polyfil_cur, 0x60);
if (rc < 0)
return rc;
priv->delsys = delsys;
priv->type = type;
priv->std = std;
priv->bw = bw;
return 0;
}
static int r820t_read_gain(struct r820t_priv *priv)
{
u8 data[4];
int rc;
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
return rc;
return ((data[3] & 0x08) << 1) + ((data[3] & 0xf0) >> 4);
}
static int generic_set_freq(struct dvb_frontend *fe,
u32 freq ,
unsigned bw,
enum v4l2_tuner_type type,
v4l2_std_id std, u32 delsys)
{
struct r820t_priv *priv = fe->tuner_priv;
int rc;
u32 lo_freq;
tuner_dbg("should set frequency to %d kHz, bw %d MHz\n",
freq / 1000, bw);
rc = r820t_set_tv_standard(priv, bw, type, std, delsys);
if (rc < 0)
goto err;
if ((type == V4L2_TUNER_ANALOG_TV) && (std == V4L2_STD_SECAM_LC))
lo_freq = freq - priv->int_freq;
else
lo_freq = freq + priv->int_freq;
rc = r820t_set_mux(priv, lo_freq);
if (rc < 0)
goto err;
rc = r820t_set_pll(priv, type, lo_freq);
if (rc < 0 || !priv->has_lock)
goto err;
rc = r820t_sysfreq_sel(priv, freq, type, std, delsys);
if (rc < 0)
goto err;
tuner_dbg("%s: PLL locked on frequency %d Hz, gain=%d\n",
__func__, freq, r820t_read_gain(priv));
err:
if (rc < 0)
tuner_dbg("%s: failed=%d\n", __func__, rc);
return rc;
}
static int r820t_standby(struct r820t_priv *priv)
{
int rc;
if (!priv->init_done)
return 0;
rc = r820t_write_reg(priv, 0x06, 0xb1);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x05, 0x03);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x07, 0x3a);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x08, 0x40);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x09, 0xc0);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x0a, 0x36);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x0c, 0x35);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x0f, 0x68);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x11, 0x03);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x17, 0xf4);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x19, 0x0c);
priv->type = -1;
return rc;
}
static int r820t_xtal_check(struct r820t_priv *priv)
{
int rc, i;
u8 data[3], val;
memcpy(priv->regs, r820t_init_array, sizeof(r820t_init_array));
rc = r820t_write_reg_mask(priv, 0x10, 0x0b, 0x0b);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1a, 0x00, 0x0c);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x13, 0x7f, 0x7f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x13, 0x00, 0x40);
if (rc < 0)
return rc;
for (i = 0; i < ARRAY_SIZE(r820t_xtal_capacitor); i++) {
rc = r820t_write_reg_mask(priv, 0x10,
r820t_xtal_capacitor[i][0], 0x1b);
if (rc < 0)
return rc;
usleep_range(5000, 6000);
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
return rc;
if (!(data[2] & 0x40))
continue;
val = data[2] & 0x3f;
if (priv->cfg->xtal == 16000000 && (val > 29 || val < 23))
break;
if (val != 0x3f)
break;
}
if (i == ARRAY_SIZE(r820t_xtal_capacitor))
return -EINVAL;
return r820t_xtal_capacitor[i][1];
}
static int r820t_imr_prepare(struct r820t_priv *priv)
{
int rc;
memcpy(priv->regs, r820t_init_array, sizeof(r820t_init_array));
rc = r820t_write_reg_mask(priv, 0x05, 0x20, 0x20);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x07, 0, 0x10);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0a, 0x0f, 0x0f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0b, 0x60, 0x6f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0c, 0x0b, 0x9f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x0f, 0, 0x08);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x18, 0x10, 0x10);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1c, 0x02, 0x02);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x1e, 0x80, 0x80);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x06, 0x20, 0x20);
return rc;
}
static int r820t_multi_read(struct r820t_priv *priv)
{
int rc, i;
u16 sum = 0;
u8 data[2], min = 255, max = 0;
usleep_range(5000, 6000);
for (i = 0; i < 6; i++) {
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
return rc;
sum += data[1];
if (data[1] < min)
min = data[1];
if (data[1] > max)
max = data[1];
}
rc = sum - max - min;
return rc;
}
static int r820t_imr_cross(struct r820t_priv *priv,
struct r820t_sect_type iq_point[3],
u8 *x_direct)
{
struct r820t_sect_type cross[5];
struct r820t_sect_type tmp;
int i, rc;
u8 reg08, reg09;
reg08 = r820t_read_cache_reg(priv, 8) & 0xc0;
reg09 = r820t_read_cache_reg(priv, 9) & 0xc0;
tmp.gain_x = 0;
tmp.phase_y = 0;
tmp.value = 255;
for (i = 0; i < 5; i++) {
switch (i) {
case 0:
cross[i].gain_x = reg08;
cross[i].phase_y = reg09;
break;
case 1:
cross[i].gain_x = reg08;
cross[i].phase_y = reg09 + 1;
break;
case 2:
cross[i].gain_x = reg08;
cross[i].phase_y = (reg09 | 0x20) + 1;
break;
case 3:
cross[i].gain_x = reg08 + 1;
cross[i].phase_y = reg09;
break;
default:
cross[i].gain_x = (reg08 | 0x20) + 1;
cross[i].phase_y = reg09;
}
rc = r820t_write_reg(priv, 0x08, cross[i].gain_x);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x09, cross[i].phase_y);
if (rc < 0)
return rc;
rc = r820t_multi_read(priv);
if (rc < 0)
return rc;
cross[i].value = rc;
if (cross[i].value < tmp.value)
tmp = cross[i];
}
if ((tmp.phase_y & 0x1f) == 1) {
*x_direct = 0;
iq_point[0] = cross[0];
iq_point[1] = cross[1];
iq_point[2] = cross[2];
} else {
*x_direct = 1;
iq_point[0] = cross[0];
iq_point[1] = cross[3];
iq_point[2] = cross[4];
}
return 0;
}
static void r820t_compre_cor(struct r820t_sect_type iq[3])
{
int i;
for (i = 3; i > 0; i--) {
if (iq[0].value > iq[i - 1].value)
swap(iq[0], iq[i - 1]);
}
}
static int r820t_compre_step(struct r820t_priv *priv,
struct r820t_sect_type iq[3], u8 reg)
{
int rc;
struct r820t_sect_type tmp;
tmp.phase_y = iq[0].phase_y;
tmp.gain_x = iq[0].gain_x;
while (((tmp.gain_x & 0x1f) < IMR_TRIAL) &&
((tmp.phase_y & 0x1f) < IMR_TRIAL)) {
if (reg == 0x08)
tmp.gain_x++;
else
tmp.phase_y++;
rc = r820t_write_reg(priv, 0x08, tmp.gain_x);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x09, tmp.phase_y);
if (rc < 0)
return rc;
rc = r820t_multi_read(priv);
if (rc < 0)
return rc;
tmp.value = rc;
if (tmp.value <= iq[0].value) {
iq[0].gain_x = tmp.gain_x;
iq[0].phase_y = tmp.phase_y;
iq[0].value = tmp.value;
} else {
return 0;
}
}
return 0;
}
static int r820t_iq_tree(struct r820t_priv *priv,
struct r820t_sect_type iq[3],
u8 fix_val, u8 var_val, u8 fix_reg)
{
int rc, i;
u8 tmp, var_reg;
if (fix_reg == 0x08)
var_reg = 0x09;
else
var_reg = 0x08;
for (i = 0; i < 3; i++) {
rc = r820t_write_reg(priv, fix_reg, fix_val);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, var_reg, var_val);
if (rc < 0)
return rc;
rc = r820t_multi_read(priv);
if (rc < 0)
return rc;
iq[i].value = rc;
if (fix_reg == 0x08) {
iq[i].gain_x = fix_val;
iq[i].phase_y = var_val;
} else {
iq[i].phase_y = fix_val;
iq[i].gain_x = var_val;
}
if (i == 0) {
var_val++;
} else if (i == 1) {
if ((var_val & 0x1f) < 0x02) {
tmp = 2 - (var_val & 0x1f);
if (var_val & 0x20) {
var_val &= 0xc0;
var_val |= tmp;
} else {
var_val |= 0x20 | tmp;
}
} else {
var_val -= 2;
}
}
}
return 0;
}
static int r820t_section(struct r820t_priv *priv,
struct r820t_sect_type *iq_point)
{
int rc;
struct r820t_sect_type compare_iq[3], compare_bet[3];
if (!(iq_point->gain_x & 0x1f))
compare_iq[0].gain_x = ((iq_point->gain_x) & 0xdf) + 1;
else
compare_iq[0].gain_x = iq_point->gain_x - 1;
compare_iq[0].phase_y = iq_point->phase_y;
rc = r820t_iq_tree(priv, compare_iq, compare_iq[0].gain_x,
compare_iq[0].phase_y, 0x08);
if (rc < 0)
return rc;
r820t_compre_cor(compare_iq);
compare_bet[0] = compare_iq[0];
compare_iq[0].gain_x = iq_point->gain_x;
compare_iq[0].phase_y = iq_point->phase_y;
rc = r820t_iq_tree(priv, compare_iq, compare_iq[0].gain_x,
compare_iq[0].phase_y, 0x08);
if (rc < 0)
return rc;
r820t_compre_cor(compare_iq);
compare_bet[1] = compare_iq[0];
if ((iq_point->gain_x & 0x1f) == 0x00)
compare_iq[0].gain_x = ((iq_point->gain_x) | 0x20) + 1;
else
compare_iq[0].gain_x = iq_point->gain_x + 1;
compare_iq[0].phase_y = iq_point->phase_y;
rc = r820t_iq_tree(priv, compare_iq, compare_iq[0].gain_x,
compare_iq[0].phase_y, 0x08);
if (rc < 0)
return rc;
r820t_compre_cor(compare_iq);
compare_bet[2] = compare_iq[0];
r820t_compre_cor(compare_bet);
*iq_point = compare_bet[0];
return 0;
}
static int r820t_vga_adjust(struct r820t_priv *priv)
{
int rc;
u8 vga_count;
for (vga_count = 12; vga_count < 16; vga_count++) {
rc = r820t_write_reg_mask(priv, 0x0c, vga_count, 0x0f);
if (rc < 0)
return rc;
usleep_range(10000, 11000);
rc = r820t_multi_read(priv);
if (rc < 0)
return rc;
if (rc > 40 * 4)
break;
}
return 0;
}
static int r820t_iq(struct r820t_priv *priv, struct r820t_sect_type *iq_pont)
{
struct r820t_sect_type compare_iq[3];
int rc;
u8 x_direction = 0;
u8 dir_reg, other_reg;
r820t_vga_adjust(priv);
rc = r820t_imr_cross(priv, compare_iq, &x_direction);
if (rc < 0)
return rc;
if (x_direction == 1) {
dir_reg = 0x08;
other_reg = 0x09;
} else {
dir_reg = 0x09;
other_reg = 0x08;
}
r820t_compre_cor(compare_iq);
rc = r820t_compre_step(priv, compare_iq, dir_reg);
if (rc < 0)
return rc;
rc = r820t_iq_tree(priv, compare_iq, compare_iq[0].gain_x,
compare_iq[0].phase_y, dir_reg);
if (rc < 0)
return rc;
r820t_compre_cor(compare_iq);
rc = r820t_compre_step(priv, compare_iq, other_reg);
if (rc < 0)
return rc;
rc = r820t_iq_tree(priv, compare_iq, compare_iq[0].gain_x,
compare_iq[0].phase_y, other_reg);
if (rc < 0)
return rc;
r820t_compre_cor(compare_iq);
rc = r820t_section(priv, compare_iq);
*iq_pont = compare_iq[0];
rc = r820t_write_reg_mask(priv, 0x08, 0, 0x3f);
if (rc < 0)
return rc;
rc = r820t_write_reg_mask(priv, 0x09, 0, 0x3f);
return rc;
}
static int r820t_f_imr(struct r820t_priv *priv, struct r820t_sect_type *iq_pont)
{
int rc;
r820t_vga_adjust(priv);
rc = r820t_section(priv, iq_pont);
if (rc < 0)
return rc;
return 0;
}
static int r820t_imr(struct r820t_priv *priv, unsigned imr_mem, bool im_flag)
{
struct r820t_sect_type imr_point;
int rc;
u32 ring_vco, ring_freq, ring_ref;
u8 n_ring, n;
int reg18, reg19, reg1f;
if (priv->cfg->xtal > 24000000)
ring_ref = priv->cfg->xtal / 2000;
else
ring_ref = priv->cfg->xtal / 1000;
n_ring = 15;
for (n = 0; n < 16; n++) {
if ((16 + n) * 8 * ring_ref >= 3100000) {
n_ring = n;
break;
}
}
reg18 = r820t_read_cache_reg(priv, 0x18);
reg19 = r820t_read_cache_reg(priv, 0x19);
reg1f = r820t_read_cache_reg(priv, 0x1f);
reg18 &= 0xf0;
reg18 |= n_ring;
ring_vco = (16 + n_ring) * 8 * ring_ref;
reg18 &= 0xdf;
reg19 &= 0xfc;
reg1f &= 0xfc;
switch (imr_mem) {
case 0:
ring_freq = ring_vco / 48;
reg18 |= 0x20;
reg19 |= 0x03;
reg1f |= 0x02;
break;
case 1:
ring_freq = ring_vco / 16;
reg18 |= 0x00;
reg19 |= 0x02;
reg1f |= 0x00;
break;
case 2:
ring_freq = ring_vco / 8;
reg18 |= 0x00;
reg19 |= 0x01;
reg1f |= 0x03;
break;
case 3:
ring_freq = ring_vco / 6;
reg18 |= 0x20;
reg19 |= 0x00;
reg1f |= 0x03;
break;
case 4:
ring_freq = ring_vco / 4;
reg18 |= 0x00;
reg19 |= 0x00;
reg1f |= 0x01;
break;
default:
ring_freq = ring_vco / 4;
reg18 |= 0x00;
reg19 |= 0x00;
reg1f |= 0x01;
break;
}
rc = r820t_write_reg(priv, 0x18, reg18);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x19, reg19);
if (rc < 0)
return rc;
rc = r820t_write_reg(priv, 0x1f, reg1f);
if (rc < 0)
return rc;
rc = r820t_set_mux(priv, (ring_freq - 5300) * 1000);
if (rc < 0)
return rc;
rc = r820t_set_pll(priv, V4L2_TUNER_DIGITAL_TV,
(ring_freq - 5300) * 1000);
if (!priv->has_lock)
rc = -EINVAL;
if (rc < 0)
return rc;
if (im_flag) {
rc = r820t_iq(priv, &imr_point);
} else {
imr_point.gain_x = priv->imr_data[3].gain_x;
imr_point.phase_y = priv->imr_data[3].phase_y;
imr_point.value = priv->imr_data[3].value;
rc = r820t_f_imr(priv, &imr_point);
}
if (rc < 0)
return rc;
switch (imr_mem) {
case 0:
priv->imr_data[0].gain_x = imr_point.gain_x;
priv->imr_data[0].phase_y = imr_point.phase_y;
priv->imr_data[0].value = imr_point.value;
break;
case 1:
priv->imr_data[1].gain_x = imr_point.gain_x;
priv->imr_data[1].phase_y = imr_point.phase_y;
priv->imr_data[1].value = imr_point.value;
break;
case 2:
priv->imr_data[2].gain_x = imr_point.gain_x;
priv->imr_data[2].phase_y = imr_point.phase_y;
priv->imr_data[2].value = imr_point.value;
break;
case 3:
priv->imr_data[3].gain_x = imr_point.gain_x;
priv->imr_data[3].phase_y = imr_point.phase_y;
priv->imr_data[3].value = imr_point.value;
break;
case 4:
priv->imr_data[4].gain_x = imr_point.gain_x;
priv->imr_data[4].phase_y = imr_point.phase_y;
priv->imr_data[4].value = imr_point.value;
break;
default:
priv->imr_data[4].gain_x = imr_point.gain_x;
priv->imr_data[4].phase_y = imr_point.phase_y;
priv->imr_data[4].value = imr_point.value;
break;
}
return 0;
}
static int r820t_imr_callibrate(struct r820t_priv *priv)
{
int rc, i;
int xtal_cap = 0;
if (priv->init_done)
return 0;
if ((priv->cfg->rafael_chip == CHIP_R820T) ||
(priv->cfg->rafael_chip == CHIP_R828S) ||
(priv->cfg->rafael_chip == CHIP_R820C)) {
priv->xtal_cap_sel = XTAL_HIGH_CAP_0P;
} else {
rc = r820t_write(priv, 0x05,
r820t_init_array, sizeof(r820t_init_array));
if (rc < 0)
return rc;
for (i = 0; i < 3; i++) {
rc = r820t_xtal_check(priv);
if (rc < 0)
return rc;
if (!i || rc > xtal_cap)
xtal_cap = rc;
}
priv->xtal_cap_sel = xtal_cap;
}
if (no_imr_cal) {
priv->init_done = true;
return 0;
}
rc = r820t_write(priv, 0x05,
r820t_init_array, sizeof(r820t_init_array));
if (rc < 0)
return rc;
rc = r820t_imr_prepare(priv);
if (rc < 0)
return rc;
rc = r820t_imr(priv, 3, true);
if (rc < 0)
return rc;
rc = r820t_imr(priv, 1, false);
if (rc < 0)
return rc;
rc = r820t_imr(priv, 0, false);
if (rc < 0)
return rc;
rc = r820t_imr(priv, 2, false);
if (rc < 0)
return rc;
rc = r820t_imr(priv, 4, false);
if (rc < 0)
return rc;
priv->init_done = true;
priv->imr_done = true;
return 0;
}
static int r820t_init(struct dvb_frontend *fe)
{
struct r820t_priv *priv = fe->tuner_priv;
int rc;
tuner_dbg("%s:\n", __func__);
mutex_lock(&priv->lock);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
rc = r820t_imr_callibrate(priv);
if (rc < 0)
goto err;
rc = r820t_write(priv, 0x05,
r820t_init_array, sizeof(r820t_init_array));
err:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&priv->lock);
if (rc < 0)
tuner_dbg("%s: failed=%d\n", __func__, rc);
return rc;
}
static int r820t_sleep(struct dvb_frontend *fe)
{
struct r820t_priv *priv = fe->tuner_priv;
int rc;
tuner_dbg("%s:\n", __func__);
mutex_lock(&priv->lock);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
rc = r820t_standby(priv);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&priv->lock);
tuner_dbg("%s: failed=%d\n", __func__, rc);
return rc;
}
static int r820t_set_analog_freq(struct dvb_frontend *fe,
struct analog_parameters *p)
{
struct r820t_priv *priv = fe->tuner_priv;
unsigned bw;
int rc;
tuner_dbg("%s called\n", __func__);
if (!p->std)
p->std = V4L2_STD_MN;
if ((p->std == V4L2_STD_PAL_M) || (p->std == V4L2_STD_NTSC))
bw = 6;
else
bw = 8;
mutex_lock(&priv->lock);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
rc = generic_set_freq(fe, 62500l * p->frequency, bw,
V4L2_TUNER_ANALOG_TV, p->std, SYS_UNDEFINED);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&priv->lock);
return rc;
}
static int r820t_set_params(struct dvb_frontend *fe)
{
struct r820t_priv *priv = fe->tuner_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc;
unsigned bw;
tuner_dbg("%s: delivery_system=%d frequency=%d bandwidth_hz=%d\n",
__func__, c->delivery_system, c->frequency, c->bandwidth_hz);
mutex_lock(&priv->lock);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
bw = (c->bandwidth_hz + 500000) / 1000000;
if (!bw)
bw = 8;
rc = generic_set_freq(fe, c->frequency, bw,
V4L2_TUNER_DIGITAL_TV, 0, c->delivery_system);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&priv->lock);
if (rc)
tuner_dbg("%s: failed=%d\n", __func__, rc);
return rc;
}
static int r820t_signal(struct dvb_frontend *fe, u16 *strength)
{
struct r820t_priv *priv = fe->tuner_priv;
int rc = 0;
mutex_lock(&priv->lock);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (priv->has_lock) {
rc = r820t_read_gain(priv);
if (rc < 0)
goto err;
*strength = (45 - rc) << 4 | 0xff;
if (*strength == 0xff)
*strength = 0;
} else {
*strength = 0;
}
err:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&priv->lock);
tuner_dbg("%s: %s, gain=%d strength=%d\n",
__func__,
priv->has_lock ? "PLL locked" : "no signal",
rc, *strength);
return 0;
}
static int r820t_get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct r820t_priv *priv = fe->tuner_priv;
tuner_dbg("%s:\n", __func__);
*frequency = priv->int_freq;
return 0;
}
static void r820t_release(struct dvb_frontend *fe)
{
struct r820t_priv *priv = fe->tuner_priv;
tuner_dbg("%s:\n", __func__);
mutex_lock(&r820t_list_mutex);
if (priv)
hybrid_tuner_release_state(priv);
mutex_unlock(&r820t_list_mutex);
fe->tuner_priv = NULL;
}
struct dvb_frontend *r820t_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c,
const struct r820t_config *cfg)
{
struct r820t_priv *priv;
int rc = -ENODEV;
u8 data[5];
int instance;
mutex_lock(&r820t_list_mutex);
instance = hybrid_tuner_request_state(struct r820t_priv, priv,
hybrid_tuner_instance_list,
i2c, cfg->i2c_addr,
"r820t");
switch (instance) {
case 0:
goto err_no_gate;
case 1:
priv->cfg = cfg;
mutex_init(&priv->lock);
fe->tuner_priv = priv;
break;
case 2:
fe->tuner_priv = priv;
break;
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
rc = r820t_read(priv, 0x00, data, sizeof(data));
if (rc < 0)
goto err;
rc = r820t_sleep(fe);
if (rc < 0)
goto err;
tuner_info("Rafael Micro r820t successfully identified\n");
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
mutex_unlock(&r820t_list_mutex);
memcpy(&fe->ops.tuner_ops, &r820t_tuner_ops,
sizeof(struct dvb_tuner_ops));
return fe;
err:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
err_no_gate:
mutex_unlock(&r820t_list_mutex);
tuner_info("%s: failed=%d\n", __func__, rc);
r820t_release(fe);
return NULL;
}
