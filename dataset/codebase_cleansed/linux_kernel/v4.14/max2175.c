static inline struct max2175 *max2175_from_sd(struct v4l2_subdev *sd)
{
return container_of(sd, struct max2175, sd);
}
static inline struct max2175 *max2175_from_ctrl_hdl(struct v4l2_ctrl_handler *h)
{
return container_of(h, struct max2175, ctrl_hdl);
}
static inline u8 max2175_get_bitval(u8 val, u8 msb, u8 lsb)
{
return (val & GENMASK(msb, lsb)) >> lsb;
}
static int max2175_read(struct max2175 *ctx, u8 idx, u8 *val)
{
u32 regval;
int ret;
ret = regmap_read(ctx->regmap, idx, &regval);
if (ret)
mxm_err(ctx, "read ret(%d): idx 0x%02x\n", ret, idx);
else
*val = regval;
return ret;
}
static int max2175_write(struct max2175 *ctx, u8 idx, u8 val)
{
int ret;
ret = regmap_write(ctx->regmap, idx, val);
if (ret)
mxm_err(ctx, "write ret(%d): idx 0x%02x val 0x%02x\n",
ret, idx, val);
return ret;
}
static u8 max2175_read_bits(struct max2175 *ctx, u8 idx, u8 msb, u8 lsb)
{
u8 val;
if (max2175_read(ctx, idx, &val))
return 0;
return max2175_get_bitval(val, msb, lsb);
}
static int max2175_write_bits(struct max2175 *ctx, u8 idx,
u8 msb, u8 lsb, u8 newval)
{
int ret = regmap_update_bits(ctx->regmap, idx, GENMASK(msb, lsb),
newval << lsb);
if (ret)
mxm_err(ctx, "wbits ret(%d): idx 0x%02x\n", ret, idx);
return ret;
}
static int max2175_write_bit(struct max2175 *ctx, u8 idx, u8 bit, u8 newval)
{
return max2175_write_bits(ctx, idx, bit, bit, newval);
}
static int max2175_poll_timeout(struct max2175 *ctx, u8 idx, u8 msb, u8 lsb,
u8 exp_bitval, u32 timeout_us)
{
unsigned int val;
return regmap_read_poll_timeout(ctx->regmap, idx, val,
(max2175_get_bitval(val, msb, lsb) == exp_bitval),
1000, timeout_us);
}
static int max2175_poll_csm_ready(struct max2175 *ctx)
{
int ret;
ret = max2175_poll_timeout(ctx, 69, 1, 1, 0, 50000);
if (ret)
mxm_err(ctx, "csm not ready\n");
return ret;
}
static int max2175_band_from_freq(u32 freq)
{
if (freq >= 144000 && freq <= 26100000)
return MAX2175_BAND_AM;
else if (freq >= 65000000 && freq <= 108000000)
return MAX2175_BAND_FM;
return MAX2175_BAND_VHF;
}
static void max2175_i2s_enable(struct max2175 *ctx, bool enable)
{
if (enable)
max2175_write_bits(ctx, 104, 3, 0, 2);
else
max2175_write_bits(ctx, 104, 3, 0, 9);
mxm_dbg(ctx, "i2s %sabled\n", enable ? "en" : "dis");
}
static void max2175_set_filter_coeffs(struct max2175 *ctx, u8 m_sel,
u8 bank, const u16 *coeffs)
{
unsigned int i;
u8 coeff_addr, upper_address = 24;
mxm_dbg(ctx, "set_filter_coeffs: m_sel %d bank %d\n", m_sel, bank);
max2175_write_bits(ctx, 114, 5, 4, m_sel);
if (m_sel == 2)
upper_address = 12;
for (i = 0; i < upper_address; i++) {
coeff_addr = i + bank * 24;
max2175_write(ctx, 115, coeffs[i] >> 8);
max2175_write(ctx, 116, coeffs[i]);
max2175_write(ctx, 117, coeff_addr | 1 << 7);
}
max2175_write_bit(ctx, 117, 7, 0);
}
static void max2175_load_fmeu_1p2(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fmeu1p2_map); i++)
max2175_write(ctx, fmeu1p2_map[i].idx, fmeu1p2_map[i].val);
ctx->decim_ratio = 36;
max2175_set_filter_coeffs(ctx, MAX2175_CH_MSEL, 0, ch_coeff_fmeu);
max2175_set_filter_coeffs(ctx, MAX2175_EQ_MSEL, 0,
eq_coeff_fmeu1_ra02_m6db);
}
static void max2175_load_dab_1p2(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(dab12_map); i++)
max2175_write(ctx, dab12_map[i].idx, dab12_map[i].val);
ctx->decim_ratio = 1;
max2175_set_filter_coeffs(ctx, MAX2175_CH_MSEL, 2, ch_coeff_dab1);
}
static void max2175_load_fmna_1p0(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fmna1p0_map); i++)
max2175_write(ctx, fmna1p0_map[i].idx, fmna1p0_map[i].val);
}
static void max2175_load_fmna_2p0(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(fmna2p0_map); i++)
max2175_write(ctx, fmna2p0_map[i].idx, fmna2p0_map[i].val);
}
static void max2175_set_bbfilter(struct max2175 *ctx)
{
if (MAX2175_IS_BAND_AM(ctx)) {
max2175_write_bits(ctx, 12, 3, 0, ctx->rom_bbf_bw_am);
mxm_dbg(ctx, "set_bbfilter AM: rom %d\n", ctx->rom_bbf_bw_am);
} else if (MAX2175_IS_DAB_MODE(ctx)) {
max2175_write_bits(ctx, 12, 3, 0, ctx->rom_bbf_bw_dab);
mxm_dbg(ctx, "set_bbfilter DAB: rom %d\n", ctx->rom_bbf_bw_dab);
} else {
max2175_write_bits(ctx, 12, 3, 0, ctx->rom_bbf_bw_fm);
mxm_dbg(ctx, "set_bbfilter FM: rom %d\n", ctx->rom_bbf_bw_fm);
}
}
static bool max2175_set_csm_mode(struct max2175 *ctx,
enum max2175_csm_mode new_mode)
{
int ret = max2175_poll_csm_ready(ctx);
if (ret)
return ret;
max2175_write_bits(ctx, 0, 2, 0, new_mode);
mxm_dbg(ctx, "set csm new mode %d\n", new_mode);
switch (new_mode) {
case MAX2175_PRESET_TUNE:
usleep_range(51100, 51500);
break;
default:
break;
}
return max2175_poll_csm_ready(ctx);
}
static int max2175_csm_action(struct max2175 *ctx,
enum max2175_csm_mode action)
{
int ret;
mxm_dbg(ctx, "csm_action: %d\n", action);
ret = max2175_set_csm_mode(ctx, MAX2175_LOAD_TO_BUFFER);
if (ret)
return ret;
return max2175_set_csm_mode(ctx, MAX2175_PRESET_TUNE);
}
static int max2175_set_lo_freq(struct max2175 *ctx, u32 lo_freq)
{
u8 lo_mult, loband_bits = 0, vcodiv_bits = 0;
u32 int_desired, frac_desired;
enum max2175_band band;
int ret;
band = max2175_read_bits(ctx, 5, 1, 0);
switch (band) {
case MAX2175_BAND_AM:
lo_mult = 16;
break;
case MAX2175_BAND_FM:
if (lo_freq <= 74700000) {
lo_mult = 16;
} else if (lo_freq > 74700000 && lo_freq <= 110000000) {
loband_bits = 1;
lo_mult = 8;
} else {
loband_bits = 1;
vcodiv_bits = 3;
lo_mult = 8;
}
break;
case MAX2175_BAND_VHF:
if (lo_freq <= 210000000)
vcodiv_bits = 2;
else
vcodiv_bits = 1;
loband_bits = 2;
lo_mult = 4;
break;
default:
loband_bits = 3;
vcodiv_bits = 2;
lo_mult = 2;
break;
}
if (band == MAX2175_BAND_L)
lo_freq /= lo_mult;
else
lo_freq *= lo_mult;
int_desired = lo_freq / ctx->xtal_freq;
frac_desired = div_u64((u64)(lo_freq % ctx->xtal_freq) << 20,
ctx->xtal_freq);
ret = max2175_poll_csm_ready(ctx);
if (ret)
return ret;
mxm_dbg(ctx, "lo_mult %u int %u frac %u\n",
lo_mult, int_desired, frac_desired);
max2175_write(ctx, 1, int_desired);
max2175_write_bits(ctx, 2, 3, 0, (frac_desired >> 16) & 0xf);
max2175_write(ctx, 3, frac_desired >> 8);
max2175_write(ctx, 4, frac_desired);
max2175_write_bits(ctx, 5, 3, 2, loband_bits);
max2175_write_bits(ctx, 6, 7, 6, vcodiv_bits);
return ret;
}
static inline s64 max2175_round_closest(s64 dividend, s32 divisor)
{
if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
return div_s64(dividend + divisor / 2, divisor);
return div_s64(dividend - divisor / 2, divisor);
}
static int max2175_set_nco_freq(struct max2175 *ctx, s32 nco_freq)
{
s32 clock_rate = ctx->xtal_freq / ctx->decim_ratio;
u32 nco_reg, abs_nco_freq = abs(nco_freq);
s64 nco_val_desired;
int ret;
if (abs_nco_freq < clock_rate / 2) {
nco_val_desired = 2 * nco_freq;
} else {
nco_val_desired = 2 * (clock_rate - abs_nco_freq);
if (nco_freq < 0)
nco_val_desired = -nco_val_desired;
}
nco_reg = max2175_round_closest(nco_val_desired << 20, clock_rate);
if (nco_freq < 0)
nco_reg += 0x200000;
ret = max2175_poll_csm_ready(ctx);
if (ret)
return ret;
mxm_dbg(ctx, "freq %d desired %lld reg %u\n",
nco_freq, nco_val_desired, nco_reg);
max2175_write_bits(ctx, 7, 4, 0, (nco_reg >> 16) & 0x1f);
max2175_write(ctx, 8, nco_reg >> 8);
max2175_write(ctx, 9, nco_reg);
return ret;
}
static int max2175_set_rf_freq_non_am_bands(struct max2175 *ctx, u64 freq,
u32 lo_pos)
{
s64 adj_freq, low_if_freq;
int ret;
mxm_dbg(ctx, "rf_freq: non AM bands\n");
if (MAX2175_IS_FM_MODE(ctx))
low_if_freq = 128000;
else if (MAX2175_IS_FMHD_MODE(ctx))
low_if_freq = 228000;
else
return max2175_set_lo_freq(ctx, freq);
if (MAX2175_IS_BAND_VHF(ctx) == (lo_pos == MAX2175_LO_ABOVE_DESIRED))
adj_freq = freq + low_if_freq;
else
adj_freq = freq - low_if_freq;
ret = max2175_set_lo_freq(ctx, adj_freq);
if (ret)
return ret;
return max2175_set_nco_freq(ctx, -low_if_freq);
}
static int max2175_set_rf_freq(struct max2175 *ctx, u64 freq, u32 lo_pos)
{
int ret;
if (MAX2175_IS_BAND_AM(ctx))
ret = max2175_set_nco_freq(ctx, freq);
else
ret = max2175_set_rf_freq_non_am_bands(ctx, freq, lo_pos);
mxm_dbg(ctx, "set_rf_freq: ret %d freq %llu\n", ret, freq);
return ret;
}
static int max2175_tune_rf_freq(struct max2175 *ctx, u64 freq, u32 hsls)
{
int ret;
ret = max2175_set_rf_freq(ctx, freq, hsls);
if (ret)
return ret;
ret = max2175_csm_action(ctx, MAX2175_BUFFER_PLUS_PRESET_TUNE);
if (ret)
return ret;
mxm_dbg(ctx, "tune_rf_freq: old %u new %llu\n", ctx->freq, freq);
ctx->freq = freq;
return ret;
}
static void max2175_set_hsls(struct max2175 *ctx, u32 lo_pos)
{
mxm_dbg(ctx, "set_hsls: lo_pos %u\n", lo_pos);
if ((lo_pos == MAX2175_LO_BELOW_DESIRED) == MAX2175_IS_BAND_VHF(ctx))
max2175_write_bit(ctx, 5, 4, 1);
else
max2175_write_bit(ctx, 5, 4, 0);
}
static void max2175_set_eu_rx_mode(struct max2175 *ctx, u32 rx_mode)
{
switch (rx_mode) {
case MAX2175_EU_FM_1_2:
max2175_load_fmeu_1p2(ctx);
break;
case MAX2175_DAB_1_2:
max2175_load_dab_1p2(ctx);
break;
}
if (!ctx->master)
max2175_write_bit(ctx, 30, 7, 1);
}
static void max2175_set_na_rx_mode(struct max2175 *ctx, u32 rx_mode)
{
switch (rx_mode) {
case MAX2175_NA_FM_1_0:
max2175_load_fmna_1p0(ctx);
break;
case MAX2175_NA_FM_2_0:
max2175_load_fmna_2p0(ctx);
break;
}
if (!ctx->master)
max2175_write_bit(ctx, 30, 7, 1);
ctx->decim_ratio = 27;
max2175_set_filter_coeffs(ctx, MAX2175_CH_MSEL, 0, ch_coeff_fmna);
max2175_set_filter_coeffs(ctx, MAX2175_EQ_MSEL, 0,
eq_coeff_fmna1_ra02_m6db);
}
static int max2175_set_rx_mode(struct max2175 *ctx, u32 rx_mode)
{
mxm_dbg(ctx, "set_rx_mode: %u am_hiz %u\n", rx_mode, ctx->am_hiz);
if (ctx->xtal_freq == MAX2175_EU_XTAL_FREQ)
max2175_set_eu_rx_mode(ctx, rx_mode);
else
max2175_set_na_rx_mode(ctx, rx_mode);
if (ctx->am_hiz) {
mxm_dbg(ctx, "setting AM HiZ related config\n");
max2175_write_bit(ctx, 50, 5, 1);
max2175_write_bit(ctx, 90, 7, 1);
max2175_write_bits(ctx, 73, 1, 0, 2);
max2175_write_bits(ctx, 80, 5, 0, 33);
}
max2175_set_bbfilter(ctx);
max2175_set_hsls(ctx, ctx->hsls->cur.val);
max2175_i2s_enable(ctx, ctx->i2s_en->cur.val);
ctx->mode_resolved = true;
return 0;
}
static int max2175_rx_mode_from_freq(struct max2175 *ctx, u32 freq, u32 *mode)
{
unsigned int i;
int band = max2175_band_from_freq(freq);
for (i = 0; i <= ctx->rx_mode->maximum; i++) {
if (ctx->rx_modes[i].band == band) {
*mode = i;
mxm_dbg(ctx, "rx_mode_from_freq: freq %u mode %d\n",
freq, *mode);
return 0;
}
}
return -EINVAL;
}
static bool max2175_freq_rx_mode_valid(struct max2175 *ctx,
u32 mode, u32 freq)
{
int band = max2175_band_from_freq(freq);
return (ctx->rx_modes[mode].band == band);
}
static void max2175_load_adc_presets(struct max2175 *ctx)
{
unsigned int i, j;
for (i = 0; i < ARRAY_SIZE(adc_presets); i++)
for (j = 0; j < ARRAY_SIZE(adc_presets[0]); j++)
max2175_write(ctx, 146 + j + i * 55, adc_presets[i][j]);
}
static int max2175_init_power_manager(struct max2175 *ctx)
{
int ret;
max2175_write_bit(ctx, 99, 2, 0);
usleep_range(1000, 1500);
max2175_write_bit(ctx, 99, 2, 1);
ret = max2175_poll_timeout(ctx, 69, 7, 7, 1, 50000);
if (ret)
mxm_err(ctx, "init pm failed\n");
return ret;
}
static int max2175_recalibrate_adc(struct max2175 *ctx)
{
int ret;
max2175_write(ctx, 150, 0xff);
max2175_write(ctx, 205, 0xff);
max2175_write(ctx, 147, 0x20);
max2175_write(ctx, 147, 0x00);
max2175_write(ctx, 202, 0x20);
max2175_write(ctx, 202, 0x00);
ret = max2175_poll_timeout(ctx, 69, 4, 3, 3, 50000);
if (ret)
mxm_err(ctx, "adc recalibration failed\n");
return ret;
}
static u8 max2175_read_rom(struct max2175 *ctx, u8 row)
{
u8 data = 0;
max2175_write_bit(ctx, 56, 4, 0);
max2175_write_bits(ctx, 56, 3, 0, row);
usleep_range(2000, 2500);
max2175_read(ctx, 58, &data);
max2175_write_bits(ctx, 56, 3, 0, 0);
mxm_dbg(ctx, "read_rom: row %d data 0x%02x\n", row, data);
return data;
}
static void max2175_load_from_rom(struct max2175 *ctx)
{
u8 data = 0;
data = max2175_read_rom(ctx, 0);
ctx->rom_bbf_bw_am = data & 0x0f;
max2175_write_bits(ctx, 81, 3, 0, data >> 4);
data = max2175_read_rom(ctx, 1);
ctx->rom_bbf_bw_fm = data & 0x0f;
ctx->rom_bbf_bw_dab = data >> 4;
data = max2175_read_rom(ctx, 2);
max2175_write_bits(ctx, 82, 4, 0, data & 0x1f);
max2175_write_bits(ctx, 82, 7, 5, data >> 5);
data = max2175_read_rom(ctx, 3);
if (ctx->am_hiz) {
data &= 0x0f;
data |= (max2175_read_rom(ctx, 7) & 0x40) >> 2;
if (!data)
data |= 2;
} else {
data = (data & 0xf0) >> 4;
data |= (max2175_read_rom(ctx, 7) & 0x80) >> 3;
if (!data)
data |= 30;
}
max2175_write_bits(ctx, 80, 5, 0, data + 31);
data = max2175_read_rom(ctx, 6);
max2175_write_bits(ctx, 81, 7, 6, data >> 6);
}
static void max2175_load_full_fm_eu_1p0(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(full_fm_eu_1p0); i++)
max2175_write(ctx, i + 1, full_fm_eu_1p0[i]);
usleep_range(5000, 5500);
ctx->decim_ratio = 36;
}
static void max2175_load_full_fm_na_1p0(struct max2175 *ctx)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(full_fm_na_1p0); i++)
max2175_write(ctx, i + 1, full_fm_na_1p0[i]);
usleep_range(5000, 5500);
ctx->decim_ratio = 27;
}
static int max2175_core_init(struct max2175 *ctx, u32 refout_bits)
{
int ret;
if (ctx->xtal_freq == MAX2175_EU_XTAL_FREQ)
max2175_load_full_fm_eu_1p0(ctx);
else
max2175_load_full_fm_na_1p0(ctx);
if (!ctx->master)
max2175_write_bit(ctx, 30, 7, 1);
mxm_dbg(ctx, "refout_bits %u\n", refout_bits);
max2175_write_bits(ctx, 56, 7, 5, refout_bits);
max2175_write_bit(ctx, 99, 1, 0);
usleep_range(1000, 1500);
max2175_write_bit(ctx, 99, 1, 1);
max2175_load_adc_presets(ctx);
ret = max2175_init_power_manager(ctx);
if (ret)
return ret;
ret = max2175_recalibrate_adc(ctx);
if (ret)
return ret;
max2175_load_from_rom(ctx);
if (ctx->xtal_freq == MAX2175_EU_XTAL_FREQ) {
max2175_set_filter_coeffs(ctx, MAX2175_CH_MSEL, 0,
ch_coeff_fmeu);
max2175_set_filter_coeffs(ctx, MAX2175_EQ_MSEL, 0,
eq_coeff_fmeu1_ra02_m6db);
} else {
max2175_set_filter_coeffs(ctx, MAX2175_CH_MSEL, 0,
ch_coeff_fmna);
max2175_set_filter_coeffs(ctx, MAX2175_EQ_MSEL, 0,
eq_coeff_fmna1_ra02_m6db);
}
mxm_dbg(ctx, "core initialized\n");
return 0;
}
static void max2175_s_ctrl_rx_mode(struct max2175 *ctx, u32 rx_mode)
{
max2175_set_rx_mode(ctx, rx_mode);
mxm_dbg(ctx, "s_ctrl_rx_mode: %u curr freq %u\n", rx_mode, ctx->freq);
if (max2175_freq_rx_mode_valid(ctx, rx_mode, ctx->freq))
max2175_tune_rf_freq(ctx, ctx->freq, ctx->hsls->cur.val);
else
max2175_tune_rf_freq(ctx, ctx->rx_modes[rx_mode].freq,
ctx->hsls->cur.val);
}
static int max2175_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct max2175 *ctx = max2175_from_ctrl_hdl(ctrl->handler);
mxm_dbg(ctx, "s_ctrl: id 0x%x, val %u\n", ctrl->id, ctrl->val);
switch (ctrl->id) {
case V4L2_CID_MAX2175_I2S_ENABLE:
max2175_i2s_enable(ctx, ctrl->val);
break;
case V4L2_CID_MAX2175_HSLS:
max2175_set_hsls(ctx, ctrl->val);
break;
case V4L2_CID_MAX2175_RX_MODE:
max2175_s_ctrl_rx_mode(ctx, ctrl->val);
break;
}
return 0;
}
static u32 max2175_get_lna_gain(struct max2175 *ctx)
{
enum max2175_band band = max2175_read_bits(ctx, 5, 1, 0);
switch (band) {
case MAX2175_BAND_AM:
return max2175_read_bits(ctx, 51, 3, 0);
case MAX2175_BAND_FM:
return max2175_read_bits(ctx, 50, 3, 0);
case MAX2175_BAND_VHF:
return max2175_read_bits(ctx, 52, 5, 0);
default:
return 0;
}
}
static int max2175_g_volatile_ctrl(struct v4l2_ctrl *ctrl)
{
struct max2175 *ctx = max2175_from_ctrl_hdl(ctrl->handler);
switch (ctrl->id) {
case V4L2_CID_RF_TUNER_LNA_GAIN:
ctrl->val = max2175_get_lna_gain(ctx);
break;
case V4L2_CID_RF_TUNER_IF_GAIN:
ctrl->val = max2175_read_bits(ctx, 49, 4, 0);
break;
case V4L2_CID_RF_TUNER_PLL_LOCK:
ctrl->val = (max2175_read_bits(ctx, 60, 7, 6) == 3);
break;
}
return 0;
}
static int max2175_set_freq_and_mode(struct max2175 *ctx, u32 freq)
{
u32 rx_mode;
int ret;
ret = max2175_rx_mode_from_freq(ctx, freq, &rx_mode);
if (ret)
return ret;
mxm_dbg(ctx, "set_freq_and_mode: freq %u rx_mode %d\n", freq, rx_mode);
max2175_set_rx_mode(ctx, rx_mode);
ctx->rx_mode->cur.val = rx_mode;
return max2175_tune_rf_freq(ctx, freq, ctx->hsls->cur.val);
}
static int max2175_s_frequency(struct v4l2_subdev *sd,
const struct v4l2_frequency *vf)
{
struct max2175 *ctx = max2175_from_sd(sd);
u32 freq;
int ret = 0;
mxm_dbg(ctx, "s_freq: new %u curr %u, mode_resolved %d\n",
vf->frequency, ctx->freq, ctx->mode_resolved);
if (vf->tuner != 0)
return -EINVAL;
freq = clamp(vf->frequency, ctx->bands_rf->rangelow,
ctx->bands_rf->rangehigh);
if (ctx->mode_resolved &&
max2175_freq_rx_mode_valid(ctx, ctx->rx_mode->cur.val, freq))
ret = max2175_tune_rf_freq(ctx, freq, ctx->hsls->cur.val);
else
ret = max2175_set_freq_and_mode(ctx, freq);
mxm_dbg(ctx, "s_freq: ret %d curr %u mode_resolved %d mode %u\n",
ret, ctx->freq, ctx->mode_resolved, ctx->rx_mode->cur.val);
return ret;
}
static int max2175_g_frequency(struct v4l2_subdev *sd,
struct v4l2_frequency *vf)
{
struct max2175 *ctx = max2175_from_sd(sd);
int ret = 0;
if (vf->tuner != 0)
return -EINVAL;
vf->type = V4L2_TUNER_RF;
vf->frequency = ctx->freq;
return ret;
}
static int max2175_enum_freq_bands(struct v4l2_subdev *sd,
struct v4l2_frequency_band *band)
{
struct max2175 *ctx = max2175_from_sd(sd);
if (band->tuner != 0 || band->index != 0)
return -EINVAL;
*band = *ctx->bands_rf;
return 0;
}
static int max2175_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct max2175 *ctx = max2175_from_sd(sd);
if (vt->index > 0)
return -EINVAL;
strlcpy(vt->name, "RF", sizeof(vt->name));
vt->type = V4L2_TUNER_RF;
vt->capability = V4L2_TUNER_CAP_1HZ | V4L2_TUNER_CAP_FREQ_BANDS;
vt->rangelow = ctx->bands_rf->rangelow;
vt->rangehigh = ctx->bands_rf->rangehigh;
return 0;
}
static int max2175_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *vt)
{
if (vt->index > 0)
return -EINVAL;
return 0;
}
static int max2175_refout_load_to_bits(struct i2c_client *client, u32 load,
u32 *bits)
{
if (load <= 40)
*bits = load / 10;
else if (load >= 60 && load <= 70)
*bits = load / 10 - 1;
else
return -EINVAL;
return 0;
}
static int max2175_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
bool master = true, am_hiz = false;
u32 refout_load, refout_bits = 0;
struct v4l2_ctrl_handler *hdl;
struct fwnode_handle *fwnode;
struct device_node *np;
struct v4l2_subdev *sd;
struct regmap *regmap;
struct max2175 *ctx;
struct clk *clk;
int ret;
np = of_parse_phandle(client->dev.of_node, "maxim,master", 0);
if (np) {
master = false;
of_node_put(np);
}
fwnode = of_fwnode_handle(client->dev.of_node);
if (fwnode_property_present(fwnode, "maxim,am-hiz-filter"))
am_hiz = true;
if (!fwnode_property_read_u32(fwnode, "maxim,refout-load",
&refout_load)) {
ret = max2175_refout_load_to_bits(client, refout_load,
&refout_bits);
if (ret) {
dev_err(&client->dev, "invalid refout_load %u\n",
refout_load);
return -EINVAL;
}
}
clk = devm_clk_get(&client->dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
dev_err(&client->dev, "cannot get clock %d\n", ret);
return ret;
}
regmap = devm_regmap_init_i2c(client, &max2175_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&client->dev, "regmap init failed %d\n", ret);
return -ENODEV;
}
ctx = devm_kzalloc(&client->dev, sizeof(*ctx), GFP_KERNEL);
if (ctx == NULL)
return -ENOMEM;
sd = &ctx->sd;
ctx->master = master;
ctx->am_hiz = am_hiz;
ctx->mode_resolved = false;
ctx->regmap = regmap;
ctx->xtal_freq = clk_get_rate(clk);
dev_info(&client->dev, "xtal freq %luHz\n", ctx->xtal_freq);
v4l2_i2c_subdev_init(sd, client, &max2175_ops);
ctx->client = client;
sd->flags = V4L2_SUBDEV_FL_HAS_DEVNODE;
hdl = &ctx->ctrl_hdl;
ret = v4l2_ctrl_handler_init(hdl, 7);
if (ret)
return ret;
ctx->lna_gain = v4l2_ctrl_new_std(hdl, &max2175_ctrl_ops,
V4L2_CID_RF_TUNER_LNA_GAIN,
0, 63, 1, 0);
ctx->lna_gain->flags |= (V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY);
ctx->if_gain = v4l2_ctrl_new_std(hdl, &max2175_ctrl_ops,
V4L2_CID_RF_TUNER_IF_GAIN,
0, 31, 1, 0);
ctx->if_gain->flags |= (V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY);
ctx->pll_lock = v4l2_ctrl_new_std(hdl, &max2175_ctrl_ops,
V4L2_CID_RF_TUNER_PLL_LOCK,
0, 1, 1, 0);
ctx->pll_lock->flags |= (V4L2_CTRL_FLAG_VOLATILE |
V4L2_CTRL_FLAG_READ_ONLY);
ctx->i2s_en = v4l2_ctrl_new_custom(hdl, &max2175_i2s_en, NULL);
ctx->hsls = v4l2_ctrl_new_custom(hdl, &max2175_hsls, NULL);
if (ctx->xtal_freq == MAX2175_EU_XTAL_FREQ) {
ctx->rx_mode = v4l2_ctrl_new_custom(hdl,
&max2175_eu_rx_mode, NULL);
ctx->rx_modes = eu_rx_modes;
ctx->bands_rf = &eu_bands_rf;
} else {
ctx->rx_mode = v4l2_ctrl_new_custom(hdl,
&max2175_na_rx_mode, NULL);
ctx->rx_modes = na_rx_modes;
ctx->bands_rf = &na_bands_rf;
}
ctx->sd.ctrl_handler = &ctx->ctrl_hdl;
ctx->freq = ctx->bands_rf->rangelow;
ret = v4l2_async_register_subdev(sd);
if (ret) {
dev_err(&client->dev, "register subdev failed\n");
goto err_reg;
}
ret = max2175_core_init(ctx, refout_bits);
if (ret)
goto err_init;
ret = v4l2_ctrl_handler_setup(hdl);
if (ret)
goto err_init;
return 0;
err_init:
v4l2_async_unregister_subdev(sd);
err_reg:
v4l2_ctrl_handler_free(&ctx->ctrl_hdl);
return ret;
}
static int max2175_remove(struct i2c_client *client)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
struct max2175 *ctx = max2175_from_sd(sd);
v4l2_ctrl_handler_free(&ctx->ctrl_hdl);
v4l2_async_unregister_subdev(sd);
return 0;
}
