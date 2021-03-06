static u16 dib7000m_read_word(struct dib7000m_state *state, u16 reg)
{
u16 ret;
if (mutex_lock_interruptible(&state->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return 0;
}
state->i2c_write_buffer[0] = (reg >> 8) | 0x80;
state->i2c_write_buffer[1] = reg & 0xff;
memset(state->msg, 0, 2 * sizeof(struct i2c_msg));
state->msg[0].addr = state->i2c_addr >> 1;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 2;
state->msg[1].addr = state->i2c_addr >> 1;
state->msg[1].flags = I2C_M_RD;
state->msg[1].buf = state->i2c_read_buffer;
state->msg[1].len = 2;
if (i2c_transfer(state->i2c_adap, state->msg, 2) != 2)
dprintk("i2c read error on %d",reg);
ret = (state->i2c_read_buffer[0] << 8) | state->i2c_read_buffer[1];
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static int dib7000m_write_word(struct dib7000m_state *state, u16 reg, u16 val)
{
int ret;
if (mutex_lock_interruptible(&state->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return -EINVAL;
}
state->i2c_write_buffer[0] = (reg >> 8) & 0xff;
state->i2c_write_buffer[1] = reg & 0xff;
state->i2c_write_buffer[2] = (val >> 8) & 0xff;
state->i2c_write_buffer[3] = val & 0xff;
memset(&state->msg[0], 0, sizeof(struct i2c_msg));
state->msg[0].addr = state->i2c_addr >> 1;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 4;
ret = (i2c_transfer(state->i2c_adap, state->msg, 1) != 1 ?
-EREMOTEIO : 0);
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static void dib7000m_write_tab(struct dib7000m_state *state, u16 *buf)
{
u16 l = 0, r, *n;
n = buf;
l = *n++;
while (l) {
r = *n++;
if (state->reg_offs && (r >= 112 && r <= 331))
r++;
do {
dib7000m_write_word(state, r, *n++);
r++;
} while (--l);
l = *n++;
}
}
static int dib7000m_set_output_mode(struct dib7000m_state *state, int mode)
{
int ret = 0;
u16 outreg, fifo_threshold, smo_mode,
sram = 0x0005;
outreg = 0;
fifo_threshold = 1792;
smo_mode = (dib7000m_read_word(state, 294 + state->reg_offs) & 0x0010) | (1 << 1);
dprintk( "setting output mode for demod %p to %d", &state->demod, mode);
switch (mode) {
case OUTMODE_MPEG2_PAR_GATED_CLK:
outreg = (1 << 10);
break;
case OUTMODE_MPEG2_PAR_CONT_CLK:
outreg = (1 << 10) | (1 << 6);
break;
case OUTMODE_MPEG2_SERIAL:
outreg = (1 << 10) | (2 << 6) | (0 << 1);
break;
case OUTMODE_DIVERSITY:
if (state->cfg.hostbus_diversity)
outreg = (1 << 10) | (4 << 6);
else
sram |= 0x0c00;
break;
case OUTMODE_MPEG2_FIFO:
smo_mode |= (3 << 1);
fifo_threshold = 512;
outreg = (1 << 10) | (5 << 6);
break;
case OUTMODE_HIGH_Z:
outreg = 0;
break;
default:
dprintk( "Unhandled output_mode passed to be set for demod %p",&state->demod);
break;
}
if (state->cfg.output_mpeg2_in_188_bytes)
smo_mode |= (1 << 5) ;
ret |= dib7000m_write_word(state, 294 + state->reg_offs, smo_mode);
ret |= dib7000m_write_word(state, 295 + state->reg_offs, fifo_threshold);
ret |= dib7000m_write_word(state, 1795, outreg);
ret |= dib7000m_write_word(state, 1805, sram);
if (state->revision == 0x4003) {
u16 clk_cfg1 = dib7000m_read_word(state, 909) & 0xfffd;
if (mode == OUTMODE_DIVERSITY)
clk_cfg1 |= (1 << 1);
dib7000m_write_word(state, 909, clk_cfg1);
}
return ret;
}
static void dib7000m_set_power_mode(struct dib7000m_state *state, enum dib7000m_power_mode mode)
{
u16 reg_903 = 0xffff, reg_904 = 0xffff, reg_905 = 0xffff, reg_906 = 0x3fff;
u8 offset = 0;
switch (mode) {
case DIB7000M_POWER_ALL:
reg_903 = 0x0000; reg_904 = 0x0000; reg_905 = 0x0000; reg_906 = 0x0000;
break;
case DIB7000M_POWER_INTERFACE_ONLY:
reg_905 &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 2));
break;
case DIB7000M_POWER_INTERF_ANALOG_AGC:
reg_903 &= ~((1 << 15) | (1 << 14) | (1 << 11) | (1 << 10));
reg_905 &= ~((1 << 7) | (1 << 6) | (1 << 5) | (1 << 4) | (1 << 2));
reg_906 &= ~((1 << 0));
break;
case DIB7000M_POWER_COR4_DINTLV_ICIRM_EQUAL_CFROD:
reg_903 = 0x0000; reg_904 = 0x801f; reg_905 = 0x0000; reg_906 = 0x0000;
break;
case DIB7000M_POWER_COR4_CRY_ESRAM_MOUT_NUD:
reg_903 = 0x0000; reg_904 = 0x8000; reg_905 = 0x010b; reg_906 = 0x0000;
break;
case DIB7000M_POWER_NO:
break;
}
if (!state->cfg.mobile_mode)
reg_904 |= (1 << 7) | (1 << 6) | (1 << 4) | (1 << 2) | (1 << 1);
if (state->revision != 0x4000)
reg_906 <<= 1;
if (state->revision == 0x4003)
offset = 1;
dib7000m_write_word(state, 903 + offset, reg_903);
dib7000m_write_word(state, 904 + offset, reg_904);
dib7000m_write_word(state, 905 + offset, reg_905);
dib7000m_write_word(state, 906 + offset, reg_906);
}
static int dib7000m_set_adc_state(struct dib7000m_state *state, enum dibx000_adc_states no)
{
int ret = 0;
u16 reg_913 = dib7000m_read_word(state, 913),
reg_914 = dib7000m_read_word(state, 914);
switch (no) {
case DIBX000_SLOW_ADC_ON:
reg_914 |= (1 << 1) | (1 << 0);
ret |= dib7000m_write_word(state, 914, reg_914);
reg_914 &= ~(1 << 1);
break;
case DIBX000_SLOW_ADC_OFF:
reg_914 |= (1 << 1) | (1 << 0);
break;
case DIBX000_ADC_ON:
if (state->revision == 0x4000) {
dib7000m_write_word(state, 913, 0);
dib7000m_write_word(state, 914, reg_914 & 0x3);
dib7000m_write_word(state, 913, (1 << 15));
dib7000m_write_word(state, 914, reg_914 & 0x3);
}
reg_913 &= 0x0fff;
reg_914 &= 0x0003;
break;
case DIBX000_ADC_OFF:
reg_913 |= (1 << 14) | (1 << 13) | (1 << 12);
reg_914 |= (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);
break;
case DIBX000_VBG_ENABLE:
reg_913 &= ~(1 << 15);
break;
case DIBX000_VBG_DISABLE:
reg_913 |= (1 << 15);
break;
default:
break;
}
ret |= dib7000m_write_word(state, 913, reg_913);
ret |= dib7000m_write_word(state, 914, reg_914);
return ret;
}
static int dib7000m_set_bandwidth(struct dib7000m_state *state, u32 bw)
{
u32 timf;
if (!bw)
bw = 8000;
state->current_bandwidth = bw;
if (state->timf == 0) {
dprintk( "using default timf");
timf = state->timf_default;
} else {
dprintk( "using updated timf");
timf = state->timf;
}
timf = timf * (bw / 50) / 160;
dib7000m_write_word(state, 23, (u16) ((timf >> 16) & 0xffff));
dib7000m_write_word(state, 24, (u16) ((timf ) & 0xffff));
return 0;
}
static int dib7000m_set_diversity_in(struct dvb_frontend *demod, int onoff)
{
struct dib7000m_state *state = demod->demodulator_priv;
if (state->div_force_off) {
dprintk( "diversity combination deactivated - forced by COFDM parameters");
onoff = 0;
}
state->div_state = (u8)onoff;
if (onoff) {
dib7000m_write_word(state, 263 + state->reg_offs, 6);
dib7000m_write_word(state, 264 + state->reg_offs, 6);
dib7000m_write_word(state, 266 + state->reg_offs, (state->div_sync_wait << 4) | (1 << 2) | (2 << 0));
} else {
dib7000m_write_word(state, 263 + state->reg_offs, 1);
dib7000m_write_word(state, 264 + state->reg_offs, 0);
dib7000m_write_word(state, 266 + state->reg_offs, 0);
}
return 0;
}
static int dib7000m_sad_calib(struct dib7000m_state *state)
{
dib7000m_write_word(state, 929, (0 << 1) | (0 << 0));
dib7000m_write_word(state, 930, 776);
dib7000m_write_word(state, 929, (1 << 0));
dib7000m_write_word(state, 929, (0 << 0));
msleep(1);
return 0;
}
static void dib7000m_reset_pll_common(struct dib7000m_state *state, const struct dibx000_bandwidth_config *bw)
{
dib7000m_write_word(state, 18, (u16) (((bw->internal*1000) >> 16) & 0xffff));
dib7000m_write_word(state, 19, (u16) ( (bw->internal*1000) & 0xffff));
dib7000m_write_word(state, 21, (u16) ( (bw->ifreq >> 16) & 0xffff));
dib7000m_write_word(state, 22, (u16) ( bw->ifreq & 0xffff));
dib7000m_write_word(state, 928, bw->sad_cfg);
}
static void dib7000m_reset_pll(struct dib7000m_state *state)
{
const struct dibx000_bandwidth_config *bw = state->cfg.bw;
u16 reg_907,reg_910;
reg_907 = (bw->pll_bypass << 15) | (bw->modulo << 7) |
(bw->ADClkSrc << 6) | (bw->IO_CLK_en_core << 5) | (bw->bypclk_div << 2) |
(bw->enable_refdiv << 1) | (0 << 0);
reg_910 = (((bw->pll_ratio >> 6) & 0x3) << 3) | (bw->pll_range << 1) | bw->pll_reset;
if (!state->cfg.quartz_direct) {
reg_910 |= (1 << 5);
if(state->cfg.input_clk_is_div_2)
reg_907 |= (16 << 9);
else
reg_907 |= (8 << 9);
} else {
reg_907 |= (bw->pll_ratio & 0x3f) << 9;
reg_910 |= (bw->pll_prediv << 5);
}
dib7000m_write_word(state, 910, reg_910);
dib7000m_write_word(state, 907, reg_907);
dib7000m_write_word(state, 908, 0x0006);
dib7000m_reset_pll_common(state, bw);
}
static void dib7000mc_reset_pll(struct dib7000m_state *state)
{
const struct dibx000_bandwidth_config *bw = state->cfg.bw;
u16 clk_cfg1;
dib7000m_write_word(state, 907, (bw->pll_prediv << 8) | (bw->pll_ratio << 0));
clk_cfg1 = (0 << 14) | (3 << 12) |(0 << 11) |
(bw->IO_CLK_en_core << 10) | (bw->bypclk_div << 5) | (bw->enable_refdiv << 4) |
(1 << 3) | (bw->pll_range << 1) | (bw->pll_reset << 0);
dib7000m_write_word(state, 908, clk_cfg1);
clk_cfg1 = (clk_cfg1 & 0xfff7) | (bw->pll_bypass << 3);
dib7000m_write_word(state, 908, clk_cfg1);
dib7000m_write_word(state, 910, (1 << 12) | (2 << 10) | (bw->modulo << 8) | (bw->ADClkSrc << 7));
dib7000m_reset_pll_common(state, bw);
}
static int dib7000m_reset_gpio(struct dib7000m_state *st)
{
dib7000m_write_word(st, 773, st->cfg.gpio_dir);
dib7000m_write_word(st, 774, st->cfg.gpio_val);
dib7000m_write_word(st, 775, st->cfg.gpio_pwm_pos);
dib7000m_write_word(st, 780, st->cfg.pwm_freq_div);
return 0;
}
static int dib7000m_demod_reset(struct dib7000m_state *state)
{
dib7000m_set_power_mode(state, DIB7000M_POWER_ALL);
dib7000m_set_adc_state(state, DIBX000_VBG_ENABLE);
dib7000m_write_word(state, 898, 0xffff);
dib7000m_write_word(state, 899, 0xffff);
dib7000m_write_word(state, 900, 0xff0f);
dib7000m_write_word(state, 901, 0xfffc);
dib7000m_write_word(state, 898, 0);
dib7000m_write_word(state, 899, 0);
dib7000m_write_word(state, 900, 0);
dib7000m_write_word(state, 901, 0);
if (state->revision == 0x4000)
dib7000m_reset_pll(state);
else
dib7000mc_reset_pll(state);
if (dib7000m_reset_gpio(state) != 0)
dprintk( "GPIO reset was not successful.");
if (dib7000m_set_output_mode(state, OUTMODE_HIGH_Z) != 0)
dprintk( "OUTPUT_MODE could not be reset.");
dib7000m_write_word(state, 1794, dib7000m_read_word(state, 1794) & ~(1 << 1) );
dib7000m_set_bandwidth(state, 8000);
dib7000m_set_adc_state(state, DIBX000_SLOW_ADC_ON);
dib7000m_sad_calib(state);
dib7000m_set_adc_state(state, DIBX000_SLOW_ADC_OFF);
if (state->cfg.dvbt_mode)
dib7000m_write_word(state, 1796, 0x0);
if (state->cfg.mobile_mode)
dib7000m_write_word(state, 261 + state->reg_offs, 2);
else
dib7000m_write_word(state, 224 + state->reg_offs, 1);
if(state->cfg.tuner_is_baseband)
dib7000m_write_word(state, 36, 0x0755);
else
dib7000m_write_word(state, 36, 0x1f55);
if (state->revision == 0x4000)
dib7000m_write_word(state, 909, (3 << 10) | (1 << 6));
else
dib7000m_write_word(state, 909, (3 << 4) | 1);
dib7000m_write_tab(state, dib7000m_defaults_common);
dib7000m_write_tab(state, dib7000m_defaults);
dib7000m_set_power_mode(state, DIB7000M_POWER_INTERFACE_ONLY);
state->internal_clk = state->cfg.bw->internal;
return 0;
}
static void dib7000m_restart_agc(struct dib7000m_state *state)
{
dib7000m_write_word(state, 898, 0x0c00);
dib7000m_write_word(state, 898, 0x0000);
}
static int dib7000m_agc_soft_split(struct dib7000m_state *state)
{
u16 agc,split_offset;
if(!state->current_agc || !state->current_agc->perform_agc_softsplit || state->current_agc->split.max == 0)
return 0;
agc = dib7000m_read_word(state, 390);
if (agc > state->current_agc->split.min_thres)
split_offset = state->current_agc->split.min;
else if (agc < state->current_agc->split.max_thres)
split_offset = state->current_agc->split.max;
else
split_offset = state->current_agc->split.max *
(agc - state->current_agc->split.min_thres) /
(state->current_agc->split.max_thres - state->current_agc->split.min_thres);
dprintk( "AGC split_offset: %d",split_offset);
return dib7000m_write_word(state, 103, (dib7000m_read_word(state, 103) & 0xff00) | split_offset);
}
static int dib7000m_update_lna(struct dib7000m_state *state)
{
u16 dyn_gain;
if (state->cfg.update_lna) {
dyn_gain = dib7000m_read_word(state, 390);
if (state->cfg.update_lna(&state->demod,dyn_gain)) {
dib7000m_restart_agc(state);
return 1;
}
}
return 0;
}
static int dib7000m_set_agc_config(struct dib7000m_state *state, u8 band)
{
struct dibx000_agc_config *agc = NULL;
int i;
if (state->current_band == band && state->current_agc != NULL)
return 0;
state->current_band = band;
for (i = 0; i < state->cfg.agc_config_count; i++)
if (state->cfg.agc[i].band_caps & band) {
agc = &state->cfg.agc[i];
break;
}
if (agc == NULL) {
dprintk( "no valid AGC configuration found for band 0x%02x",band);
return -EINVAL;
}
state->current_agc = agc;
dib7000m_write_word(state, 72 , agc->setup);
dib7000m_write_word(state, 73 , agc->inv_gain);
dib7000m_write_word(state, 74 , agc->time_stabiliz);
dib7000m_write_word(state, 97 , (agc->alpha_level << 12) | agc->thlock);
dib7000m_write_word(state, 98, (agc->alpha_mant << 5) | agc->alpha_exp);
dib7000m_write_word(state, 99, (agc->beta_mant << 6) | agc->beta_exp);
dprintk( "WBD: ref: %d, sel: %d, active: %d, alpha: %d",
state->wbd_ref != 0 ? state->wbd_ref : agc->wbd_ref, agc->wbd_sel, !agc->perform_agc_softsplit, agc->wbd_sel);
if (state->wbd_ref != 0)
dib7000m_write_word(state, 102, state->wbd_ref);
else
dib7000m_write_word(state, 102, agc->wbd_ref);
dib7000m_write_word(state, 103, (agc->wbd_alpha << 9) | (agc->perform_agc_softsplit << 8) );
dib7000m_write_word(state, 104, agc->agc1_max);
dib7000m_write_word(state, 105, agc->agc1_min);
dib7000m_write_word(state, 106, agc->agc2_max);
dib7000m_write_word(state, 107, agc->agc2_min);
dib7000m_write_word(state, 108, (agc->agc1_pt1 << 8) | agc->agc1_pt2 );
dib7000m_write_word(state, 109, (agc->agc1_slope1 << 8) | agc->agc1_slope2);
dib7000m_write_word(state, 110, (agc->agc2_pt1 << 8) | agc->agc2_pt2);
dib7000m_write_word(state, 111, (agc->agc2_slope1 << 8) | agc->agc2_slope2);
if (state->revision > 0x4000) {
dib7000m_write_word(state, 71, agc->agc1_pt3);
dib7000m_write_word(state, 929, (dib7000m_read_word(state, 929) & 0xffe3) | (agc->wbd_inv << 4) | (agc->wbd_sel << 2));
} else {
u16 b[9] = { 676, 696, 717, 737, 758, 778, 799, 819, 840 };
for (i = 0; i < 9; i++)
dib7000m_write_word(state, 88 + i, b[i]);
}
return 0;
}
static void dib7000m_update_timf(struct dib7000m_state *state)
{
u32 timf = (dib7000m_read_word(state, 436) << 16) | dib7000m_read_word(state, 437);
state->timf = timf * 160 / (state->current_bandwidth / 50);
dib7000m_write_word(state, 23, (u16) (timf >> 16));
dib7000m_write_word(state, 24, (u16) (timf & 0xffff));
dprintk( "updated timf_frequency: %d (default: %d)",state->timf, state->timf_default);
}
static int dib7000m_agc_startup(struct dvb_frontend *demod)
{
struct dtv_frontend_properties *ch = &demod->dtv_property_cache;
struct dib7000m_state *state = demod->demodulator_priv;
u16 cfg_72 = dib7000m_read_word(state, 72);
int ret = -1;
u8 *agc_state = &state->agc_state;
u8 agc_split;
switch (state->agc_state) {
case 0:
dib7000m_set_power_mode(state, DIB7000M_POWER_INTERF_ANALOG_AGC);
dib7000m_set_adc_state(state, DIBX000_ADC_ON);
if (dib7000m_set_agc_config(state, BAND_OF_FREQUENCY(ch->frequency/1000)) != 0)
return -1;
ret = 7;
(*agc_state)++;
break;
case 1:
if (state->cfg.agc_control)
state->cfg.agc_control(&state->demod, 1);
dib7000m_write_word(state, 75, 32768);
if (!state->current_agc->perform_agc_softsplit) {
dib7000m_write_word(state, 103, 1 << 8);
(*agc_state)++;
ret = 5;
} else {
(*agc_state) = 4;
ret = 7;
}
dib7000m_restart_agc(state);
break;
case 2:
dib7000m_write_word(state, 72, cfg_72 | (1 << 4));
dib7000m_write_word(state, 103, 2 << 9);
(*agc_state)++;
ret = 14;
break;
case 3:
agc_split = (u8)dib7000m_read_word(state, 392);
dib7000m_write_word(state, 75, dib7000m_read_word(state, 390));
dib7000m_write_word(state, 72, cfg_72 & ~(1 << 4));
dib7000m_write_word(state, 103, (state->current_agc->wbd_alpha << 9) | agc_split);
dib7000m_restart_agc(state);
dprintk( "SPLIT %p: %hd", demod, agc_split);
(*agc_state)++;
ret = 5;
break;
case 4:
ret = 7;
if (dib7000m_update_lna(state))
ret = 5;
else
(*agc_state)++;
break;
case 5:
dib7000m_agc_soft_split(state);
if (state->cfg.agc_control)
state->cfg.agc_control(&state->demod, 0);
(*agc_state)++;
break;
default:
break;
}
return ret;
}
static void dib7000m_set_channel(struct dib7000m_state *state, struct dtv_frontend_properties *ch,
u8 seq)
{
u16 value, est[4];
dib7000m_set_bandwidth(state, BANDWIDTH_TO_KHZ(ch->bandwidth_hz));
value = 0;
switch (ch->transmission_mode) {
case TRANSMISSION_MODE_2K: value |= (0 << 7); break;
case TRANSMISSION_MODE_4K: value |= (2 << 7); break;
default:
case TRANSMISSION_MODE_8K: value |= (1 << 7); break;
}
switch (ch->guard_interval) {
case GUARD_INTERVAL_1_32: value |= (0 << 5); break;
case GUARD_INTERVAL_1_16: value |= (1 << 5); break;
case GUARD_INTERVAL_1_4: value |= (3 << 5); break;
default:
case GUARD_INTERVAL_1_8: value |= (2 << 5); break;
}
switch (ch->modulation) {
case QPSK: value |= (0 << 3); break;
case QAM_16: value |= (1 << 3); break;
default:
case QAM_64: value |= (2 << 3); break;
}
switch (HIERARCHY_1) {
case HIERARCHY_2: value |= 2; break;
case HIERARCHY_4: value |= 4; break;
default:
case HIERARCHY_1: value |= 1; break;
}
dib7000m_write_word(state, 0, value);
dib7000m_write_word(state, 5, (seq << 4));
value = 0;
if (1 != 0)
value |= (1 << 6);
if (ch->hierarchy == 1)
value |= (1 << 4);
if (1 == 1)
value |= 1;
switch ((ch->hierarchy == 0 || 1 == 1) ? ch->code_rate_HP : ch->code_rate_LP) {
case FEC_2_3: value |= (2 << 1); break;
case FEC_3_4: value |= (3 << 1); break;
case FEC_5_6: value |= (5 << 1); break;
case FEC_7_8: value |= (7 << 1); break;
default:
case FEC_1_2: value |= (1 << 1); break;
}
dib7000m_write_word(state, 267 + state->reg_offs, value);
dib7000m_write_word(state, 26, (6 << 12) | (6 << 8) | 0x80);
dib7000m_write_word(state, 29, (0 << 14) | (4 << 10) | (1 << 9) | (3 << 5) | (1 << 4) | (0x3));
dib7000m_write_word(state, 32, (0 << 4) | 0x3);
dib7000m_write_word(state, 33, (0 << 4) | 0x5);
switch (ch->transmission_mode) {
case TRANSMISSION_MODE_8K: value = 256; break;
case TRANSMISSION_MODE_4K: value = 128; break;
case TRANSMISSION_MODE_2K:
default: value = 64; break;
}
switch (ch->guard_interval) {
case GUARD_INTERVAL_1_16: value *= 2; break;
case GUARD_INTERVAL_1_8: value *= 4; break;
case GUARD_INTERVAL_1_4: value *= 8; break;
default:
case GUARD_INTERVAL_1_32: value *= 1; break;
}
state->div_sync_wait = (value * 3) / 2 + 32;
if (1 == 1 || state->revision > 0x4000)
state->div_force_off = 0;
else
state->div_force_off = 1;
dib7000m_set_diversity_in(&state->demod, state->div_state);
switch (ch->modulation) {
case QAM_64:
est[0] = 0x0148;
est[1] = 0xfff0;
est[2] = 0x00a4;
est[3] = 0xfff8;
break;
case QAM_16:
est[0] = 0x023d;
est[1] = 0xffdf;
est[2] = 0x00a4;
est[3] = 0xfff0;
break;
default:
est[0] = 0x099a;
est[1] = 0xffae;
est[2] = 0x0333;
est[3] = 0xfff8;
break;
}
for (value = 0; value < 4; value++)
dib7000m_write_word(state, 214 + value + state->reg_offs, est[value]);
dib7000m_set_power_mode(state, DIB7000M_POWER_COR4_DINTLV_ICIRM_EQUAL_CFROD);
}
static int dib7000m_autosearch_start(struct dvb_frontend *demod)
{
struct dtv_frontend_properties *ch = &demod->dtv_property_cache;
struct dib7000m_state *state = demod->demodulator_priv;
struct dtv_frontend_properties schan;
int ret = 0;
u32 value, factor;
schan = *ch;
schan.modulation = QAM_64;
schan.guard_interval = GUARD_INTERVAL_1_32;
schan.transmission_mode = TRANSMISSION_MODE_8K;
schan.code_rate_HP = FEC_2_3;
schan.code_rate_LP = FEC_3_4;
schan.hierarchy = 0;
dib7000m_set_channel(state, &schan, 7);
factor = BANDWIDTH_TO_KHZ(schan.bandwidth_hz);
if (factor >= 5000)
factor = 1;
else
factor = 6;
value = 30 * state->internal_clk * factor;
ret |= dib7000m_write_word(state, 6, (u16) ((value >> 16) & 0xffff));
ret |= dib7000m_write_word(state, 7, (u16) (value & 0xffff));
value = 100 * state->internal_clk * factor;
ret |= dib7000m_write_word(state, 8, (u16) ((value >> 16) & 0xffff));
ret |= dib7000m_write_word(state, 9, (u16) (value & 0xffff));
value = 500 * state->internal_clk * factor;
ret |= dib7000m_write_word(state, 10, (u16) ((value >> 16) & 0xffff));
ret |= dib7000m_write_word(state, 11, (u16) (value & 0xffff));
value = dib7000m_read_word(state, 0);
ret |= dib7000m_write_word(state, 0, (u16) (value | (1 << 9)));
if (state->revision == 0x4000)
dib7000m_write_word(state, 1793, 0);
else
dib7000m_read_word(state, 537);
ret |= dib7000m_write_word(state, 0, (u16) value);
return ret;
}
static int dib7000m_autosearch_irq(struct dib7000m_state *state, u16 reg)
{
u16 irq_pending = dib7000m_read_word(state, reg);
if (irq_pending & 0x1) {
dprintk( "autosearch failed");
return 1;
}
if (irq_pending & 0x2) {
dprintk( "autosearch succeeded");
return 2;
}
return 0;
}
static int dib7000m_autosearch_is_irq(struct dvb_frontend *demod)
{
struct dib7000m_state *state = demod->demodulator_priv;
if (state->revision == 0x4000)
return dib7000m_autosearch_irq(state, 1793);
else
return dib7000m_autosearch_irq(state, 537);
}
static int dib7000m_tune(struct dvb_frontend *demod)
{
struct dtv_frontend_properties *ch = &demod->dtv_property_cache;
struct dib7000m_state *state = demod->demodulator_priv;
int ret = 0;
u16 value;
dib7000m_set_channel(state, ch, 0);
ret |= dib7000m_write_word(state, 898, 0x4000);
ret |= dib7000m_write_word(state, 898, 0x0000);
msleep(45);
dib7000m_set_power_mode(state, DIB7000M_POWER_COR4_CRY_ESRAM_MOUT_NUD);
ret |= dib7000m_write_word(state, 29, (0 << 14) | (4 << 10) | (0 << 9) | (3 << 5) | (1 << 4) | (0x3));
if (state->timf == 0)
msleep(200);
value = (6 << 8) | 0x80;
switch (ch->transmission_mode) {
case TRANSMISSION_MODE_2K: value |= (7 << 12); break;
case TRANSMISSION_MODE_4K: value |= (8 << 12); break;
default:
case TRANSMISSION_MODE_8K: value |= (9 << 12); break;
}
ret |= dib7000m_write_word(state, 26, value);
value = (0 << 4);
switch (ch->transmission_mode) {
case TRANSMISSION_MODE_2K: value |= 0x6; break;
case TRANSMISSION_MODE_4K: value |= 0x7; break;
default:
case TRANSMISSION_MODE_8K: value |= 0x8; break;
}
ret |= dib7000m_write_word(state, 32, value);
value = (0 << 4);
switch (ch->transmission_mode) {
case TRANSMISSION_MODE_2K: value |= 0x6; break;
case TRANSMISSION_MODE_4K: value |= 0x7; break;
default:
case TRANSMISSION_MODE_8K: value |= 0x8; break;
}
ret |= dib7000m_write_word(state, 33, value);
if ((dib7000m_read_word(state, 535) >> 6) & 0x1)
dib7000m_update_timf(state);
dib7000m_set_bandwidth(state, BANDWIDTH_TO_KHZ(ch->bandwidth_hz));
return ret;
}
static int dib7000m_wakeup(struct dvb_frontend *demod)
{
struct dib7000m_state *state = demod->demodulator_priv;
dib7000m_set_power_mode(state, DIB7000M_POWER_ALL);
if (dib7000m_set_adc_state(state, DIBX000_SLOW_ADC_ON) != 0)
dprintk( "could not start Slow ADC");
return 0;
}
static int dib7000m_sleep(struct dvb_frontend *demod)
{
struct dib7000m_state *st = demod->demodulator_priv;
dib7000m_set_output_mode(st, OUTMODE_HIGH_Z);
dib7000m_set_power_mode(st, DIB7000M_POWER_INTERFACE_ONLY);
return dib7000m_set_adc_state(st, DIBX000_SLOW_ADC_OFF) |
dib7000m_set_adc_state(st, DIBX000_ADC_OFF);
}
static int dib7000m_identify(struct dib7000m_state *state)
{
u16 value;
if ((value = dib7000m_read_word(state, 896)) != 0x01b3) {
dprintk( "wrong Vendor ID (0x%x)",value);
return -EREMOTEIO;
}
state->revision = dib7000m_read_word(state, 897);
if (state->revision != 0x4000 &&
state->revision != 0x4001 &&
state->revision != 0x4002 &&
state->revision != 0x4003) {
dprintk( "wrong Device ID (0x%x)",value);
return -EREMOTEIO;
}
if (state->revision == 0x4000 && dib7000m_read_word(state, 769) == 0x4000) {
dprintk( "this driver does not work with DiB7000PC");
return -EREMOTEIO;
}
switch (state->revision) {
case 0x4000: dprintk( "found DiB7000MA/PA/MB/PB"); break;
case 0x4001: state->reg_offs = 1; dprintk( "found DiB7000HC"); break;
case 0x4002: state->reg_offs = 1; dprintk( "found DiB7000MC"); break;
case 0x4003: state->reg_offs = 1; dprintk( "found DiB9000"); break;
}
return 0;
}
static int dib7000m_get_frontend(struct dvb_frontend* fe)
{
struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
struct dib7000m_state *state = fe->demodulator_priv;
u16 tps = dib7000m_read_word(state,480);
fep->inversion = INVERSION_AUTO;
fep->bandwidth_hz = BANDWIDTH_TO_HZ(state->current_bandwidth);
switch ((tps >> 8) & 0x3) {
case 0: fep->transmission_mode = TRANSMISSION_MODE_2K; break;
case 1: fep->transmission_mode = TRANSMISSION_MODE_8K; break;
}
switch (tps & 0x3) {
case 0: fep->guard_interval = GUARD_INTERVAL_1_32; break;
case 1: fep->guard_interval = GUARD_INTERVAL_1_16; break;
case 2: fep->guard_interval = GUARD_INTERVAL_1_8; break;
case 3: fep->guard_interval = GUARD_INTERVAL_1_4; break;
}
switch ((tps >> 14) & 0x3) {
case 0: fep->modulation = QPSK; break;
case 1: fep->modulation = QAM_16; break;
case 2:
default: fep->modulation = QAM_64; break;
}
fep->hierarchy = HIERARCHY_NONE;
switch ((tps >> 5) & 0x7) {
case 1: fep->code_rate_HP = FEC_1_2; break;
case 2: fep->code_rate_HP = FEC_2_3; break;
case 3: fep->code_rate_HP = FEC_3_4; break;
case 5: fep->code_rate_HP = FEC_5_6; break;
case 7:
default: fep->code_rate_HP = FEC_7_8; break;
}
switch ((tps >> 2) & 0x7) {
case 1: fep->code_rate_LP = FEC_1_2; break;
case 2: fep->code_rate_LP = FEC_2_3; break;
case 3: fep->code_rate_LP = FEC_3_4; break;
case 5: fep->code_rate_LP = FEC_5_6; break;
case 7:
default: fep->code_rate_LP = FEC_7_8; break;
}
return 0;
}
static int dib7000m_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
struct dib7000m_state *state = fe->demodulator_priv;
int time, ret;
dib7000m_set_output_mode(state, OUTMODE_HIGH_Z);
dib7000m_set_bandwidth(state, BANDWIDTH_TO_KHZ(fep->bandwidth_hz));
if (fe->ops.tuner_ops.set_params)
fe->ops.tuner_ops.set_params(fe);
state->agc_state = 0;
do {
time = dib7000m_agc_startup(fe);
if (time != -1)
msleep(time);
} while (time != -1);
if (fep->transmission_mode == TRANSMISSION_MODE_AUTO ||
fep->guard_interval == GUARD_INTERVAL_AUTO ||
fep->modulation == QAM_AUTO ||
fep->code_rate_HP == FEC_AUTO) {
int i = 800, found;
dib7000m_autosearch_start(fe);
do {
msleep(1);
found = dib7000m_autosearch_is_irq(fe);
} while (found == 0 && i--);
dprintk("autosearch returns: %d",found);
if (found == 0 || found == 1)
return 0;
dib7000m_get_frontend(fe);
}
ret = dib7000m_tune(fe);
dib7000m_set_output_mode(state, OUTMODE_MPEG2_FIFO);
return ret;
}
static int dib7000m_read_status(struct dvb_frontend *fe, fe_status_t *stat)
{
struct dib7000m_state *state = fe->demodulator_priv;
u16 lock = dib7000m_read_word(state, 535);
*stat = 0;
if (lock & 0x8000)
*stat |= FE_HAS_SIGNAL;
if (lock & 0x3000)
*stat |= FE_HAS_CARRIER;
if (lock & 0x0100)
*stat |= FE_HAS_VITERBI;
if (lock & 0x0010)
*stat |= FE_HAS_SYNC;
if (lock & 0x0008)
*stat |= FE_HAS_LOCK;
return 0;
}
static int dib7000m_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct dib7000m_state *state = fe->demodulator_priv;
*ber = (dib7000m_read_word(state, 526) << 16) | dib7000m_read_word(state, 527);
return 0;
}
static int dib7000m_read_unc_blocks(struct dvb_frontend *fe, u32 *unc)
{
struct dib7000m_state *state = fe->demodulator_priv;
*unc = dib7000m_read_word(state, 534);
return 0;
}
static int dib7000m_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct dib7000m_state *state = fe->demodulator_priv;
u16 val = dib7000m_read_word(state, 390);
*strength = 65535 - val;
return 0;
}
static int dib7000m_read_snr(struct dvb_frontend* fe, u16 *snr)
{
*snr = 0x0000;
return 0;
}
static int dib7000m_fe_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void dib7000m_release(struct dvb_frontend *demod)
{
struct dib7000m_state *st = demod->demodulator_priv;
dibx000_exit_i2c_master(&st->i2c_master);
kfree(st);
}
struct i2c_adapter * dib7000m_get_i2c_master(struct dvb_frontend *demod, enum dibx000_i2c_interface intf, int gating)
{
struct dib7000m_state *st = demod->demodulator_priv;
return dibx000_get_i2c_adapter(&st->i2c_master, intf, gating);
}
int dib7000m_pid_filter_ctrl(struct dvb_frontend *fe, u8 onoff)
{
struct dib7000m_state *state = fe->demodulator_priv;
u16 val = dib7000m_read_word(state, 294 + state->reg_offs) & 0xffef;
val |= (onoff & 0x1) << 4;
dprintk("PID filter enabled %d", onoff);
return dib7000m_write_word(state, 294 + state->reg_offs, val);
}
int dib7000m_pid_filter(struct dvb_frontend *fe, u8 id, u16 pid, u8 onoff)
{
struct dib7000m_state *state = fe->demodulator_priv;
dprintk("PID filter: index %x, PID %d, OnOff %d", id, pid, onoff);
return dib7000m_write_word(state, 300 + state->reg_offs + id,
onoff ? (1 << 13) | pid : 0);
}
struct dvb_frontend * dib7000m_attach(struct i2c_adapter *i2c_adap, u8 i2c_addr, struct dib7000m_config *cfg)
{
struct dvb_frontend *demod;
struct dib7000m_state *st;
st = kzalloc(sizeof(struct dib7000m_state), GFP_KERNEL);
if (st == NULL)
return NULL;
memcpy(&st->cfg, cfg, sizeof(struct dib7000m_config));
st->i2c_adap = i2c_adap;
st->i2c_addr = i2c_addr;
demod = &st->demod;
demod->demodulator_priv = st;
memcpy(&st->demod.ops, &dib7000m_ops, sizeof(struct dvb_frontend_ops));
mutex_init(&st->i2c_buffer_lock);
st->timf_default = cfg->bw->timf;
if (dib7000m_identify(st) != 0)
goto error;
if (st->revision == 0x4000)
dibx000_init_i2c_master(&st->i2c_master, DIB7000, st->i2c_adap, st->i2c_addr);
else
dibx000_init_i2c_master(&st->i2c_master, DIB7000MC, st->i2c_adap, st->i2c_addr);
dib7000m_demod_reset(st);
return demod;
error:
kfree(st);
return NULL;
}
