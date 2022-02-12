static u16 dib0090_read_reg(struct dib0090_state *state, u8 reg)
{
state->i2c_write_buffer[0] = reg;
memset(state->msg, 0, 2 * sizeof(struct i2c_msg));
state->msg[0].addr = state->config->i2c_address;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 1;
state->msg[1].addr = state->config->i2c_address;
state->msg[1].flags = I2C_M_RD;
state->msg[1].buf = state->i2c_read_buffer;
state->msg[1].len = 2;
if (i2c_transfer(state->i2c, state->msg, 2) != 2) {
printk(KERN_WARNING "DiB0090 I2C read failed\n");
return 0;
}
return (state->i2c_read_buffer[0] << 8) | state->i2c_read_buffer[1];
}
static int dib0090_write_reg(struct dib0090_state *state, u32 reg, u16 val)
{
state->i2c_write_buffer[0] = reg & 0xff;
state->i2c_write_buffer[1] = val >> 8;
state->i2c_write_buffer[2] = val & 0xff;
memset(state->msg, 0, sizeof(struct i2c_msg));
state->msg[0].addr = state->config->i2c_address;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 3;
if (i2c_transfer(state->i2c, state->msg, 1) != 1) {
printk(KERN_WARNING "DiB0090 I2C write failed\n");
return -EREMOTEIO;
}
return 0;
}
static u16 dib0090_fw_read_reg(struct dib0090_fw_state *state, u8 reg)
{
state->i2c_write_buffer[0] = reg;
memset(&state->msg, 0, sizeof(struct i2c_msg));
state->msg.addr = reg;
state->msg.flags = I2C_M_RD;
state->msg.buf = state->i2c_read_buffer;
state->msg.len = 2;
if (i2c_transfer(state->i2c, &state->msg, 1) != 1) {
printk(KERN_WARNING "DiB0090 I2C read failed\n");
return 0;
}
return (state->i2c_read_buffer[0] << 8) | state->i2c_read_buffer[1];
}
static int dib0090_fw_write_reg(struct dib0090_fw_state *state, u8 reg, u16 val)
{
state->i2c_write_buffer[0] = val >> 8;
state->i2c_write_buffer[1] = val & 0xff;
memset(&state->msg, 0, sizeof(struct i2c_msg));
state->msg.addr = reg;
state->msg.flags = 0;
state->msg.buf = state->i2c_write_buffer;
state->msg.len = 2;
if (i2c_transfer(state->i2c, &state->msg, 1) != 1) {
printk(KERN_WARNING "DiB0090 I2C write failed\n");
return -EREMOTEIO;
}
return 0;
}
static void dib0090_write_regs(struct dib0090_state *state, u8 r, const u16 * b, u8 c)
{
do {
dib0090_write_reg(state, r++, *b++);
} while (--c);
}
static int dib0090_identify(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
u16 v;
struct dib0090_identity *identity = &state->identity;
v = dib0090_read_reg(state, 0x1a);
identity->p1g = 0;
identity->in_soc = 0;
dprintk("Tuner identification (Version = 0x%04x)", v);
v &= ~KROSUS_PLL_LOCKED;
identity->version = v & 0xff;
identity->product = (v >> 8) & 0xf;
if (identity->product != KROSUS)
goto identification_error;
if ((identity->version & 0x3) == SOC) {
identity->in_soc = 1;
switch (identity->version) {
case SOC_8090_P1G_11R1:
dprintk("SOC 8090 P1-G11R1 Has been detected");
identity->p1g = 1;
break;
case SOC_8090_P1G_21R1:
dprintk("SOC 8090 P1-G21R1 Has been detected");
identity->p1g = 1;
break;
case SOC_7090_P1G_11R1:
dprintk("SOC 7090 P1-G11R1 Has been detected");
identity->p1g = 1;
break;
case SOC_7090_P1G_21R1:
dprintk("SOC 7090 P1-G21R1 Has been detected");
identity->p1g = 1;
break;
default:
goto identification_error;
}
} else {
switch ((identity->version >> 5) & 0x7) {
case MP001:
dprintk("MP001 : 9090/8096");
break;
case MP005:
dprintk("MP005 : Single Sband");
break;
case MP008:
dprintk("MP008 : diversity VHF-UHF-LBAND");
break;
case MP009:
dprintk("MP009 : diversity 29098 CBAND-UHF-LBAND-SBAND");
break;
default:
goto identification_error;
}
switch (identity->version & 0x1f) {
case P1G_21R2:
dprintk("P1G_21R2 detected");
identity->p1g = 1;
break;
case P1G:
dprintk("P1G detected");
identity->p1g = 1;
break;
case P1D_E_F:
dprintk("P1D/E/F detected");
break;
case P1C:
dprintk("P1C detected");
break;
case P1A_B:
dprintk("P1-A/B detected: driver is deactivated - not available");
goto identification_error;
break;
default:
goto identification_error;
}
}
return 0;
identification_error:
return -EIO;
}
static int dib0090_fw_identify(struct dvb_frontend *fe)
{
struct dib0090_fw_state *state = fe->tuner_priv;
struct dib0090_identity *identity = &state->identity;
u16 v = dib0090_fw_read_reg(state, 0x1a);
identity->p1g = 0;
identity->in_soc = 0;
dprintk("FE: Tuner identification (Version = 0x%04x)", v);
v &= ~KROSUS_PLL_LOCKED;
identity->version = v & 0xff;
identity->product = (v >> 8) & 0xf;
if (identity->product != KROSUS)
goto identification_error;
if ((identity->version & 0x3) == SOC) {
identity->in_soc = 1;
switch (identity->version) {
case SOC_8090_P1G_11R1:
dprintk("SOC 8090 P1-G11R1 Has been detected");
identity->p1g = 1;
break;
case SOC_8090_P1G_21R1:
dprintk("SOC 8090 P1-G21R1 Has been detected");
identity->p1g = 1;
break;
case SOC_7090_P1G_11R1:
dprintk("SOC 7090 P1-G11R1 Has been detected");
identity->p1g = 1;
break;
case SOC_7090_P1G_21R1:
dprintk("SOC 7090 P1-G21R1 Has been detected");
identity->p1g = 1;
break;
default:
goto identification_error;
}
} else {
switch ((identity->version >> 5) & 0x7) {
case MP001:
dprintk("MP001 : 9090/8096");
break;
case MP005:
dprintk("MP005 : Single Sband");
break;
case MP008:
dprintk("MP008 : diversity VHF-UHF-LBAND");
break;
case MP009:
dprintk("MP009 : diversity 29098 CBAND-UHF-LBAND-SBAND");
break;
default:
goto identification_error;
}
switch (identity->version & 0x1f) {
case P1G_21R2:
dprintk("P1G_21R2 detected");
identity->p1g = 1;
break;
case P1G:
dprintk("P1G detected");
identity->p1g = 1;
break;
case P1D_E_F:
dprintk("P1D/E/F detected");
break;
case P1C:
dprintk("P1C detected");
break;
case P1A_B:
dprintk("P1-A/B detected: driver is deactivated - not available");
goto identification_error;
break;
default:
goto identification_error;
}
}
return 0;
identification_error:
return -EIO;;
}
static void dib0090_reset_digital(struct dvb_frontend *fe, const struct dib0090_config *cfg)
{
struct dib0090_state *state = fe->tuner_priv;
u16 PllCfg, i, v;
HARD_RESET(state);
dib0090_write_reg(state, 0x24, EN_PLL | EN_CRYSTAL);
dib0090_write_reg(state, 0x1b, EN_DIGCLK | EN_PLL | EN_CRYSTAL);
if (!cfg->in_soc) {
dib0090_write_reg(state, 0x20, ((cfg->io.adc_clock_ratio - 1) << 11) | (0 << 10) | (1 << 9) | (1 << 8) | (0 << 4) | 0);
if (cfg->clkoutdrive != 0)
dib0090_write_reg(state, 0x23, (0 << 15) | ((!cfg->analog_output) << 14) | (2 << 10) | (1 << 9) | (0 << 8)
| (cfg->clkoutdrive << 5) | (cfg->clkouttobamse << 4) | (0 << 2) | (0));
else
dib0090_write_reg(state, 0x23, (0 << 15) | ((!cfg->analog_output) << 14) | (2 << 10) | (1 << 9) | (0 << 8)
| (7 << 5) | (cfg->clkouttobamse << 4) | (0 << 2) | (0));
}
PllCfg = dib0090_read_reg(state, 0x21);
if ((PllCfg & 0x1FFF) != ((cfg->io.pll_range << 12) | (cfg->io.pll_loopdiv << 6) | (cfg->io.pll_prediv)) && (!cfg->in_soc)
&& !cfg->io.pll_bypass) {
PllCfg |= (1 << 15);
dib0090_write_reg(state, 0x21, PllCfg);
PllCfg &= ~(1 << 13);
dib0090_write_reg(state, 0x21, PllCfg);
PllCfg = (1 << 15) | (0 << 13) | (cfg->io.pll_range << 12) | (cfg->io.pll_loopdiv << 6) | (cfg->io.pll_prediv);
dib0090_write_reg(state, 0x21, PllCfg);
PllCfg |= (1 << 13);
dib0090_write_reg(state, 0x21, PllCfg);
i = 100;
do {
v = !!(dib0090_read_reg(state, 0x1a) & 0x800);
if (v)
break;
} while (--i);
if (i == 0) {
dprintk("Pll: Unable to lock Pll");
return;
}
PllCfg &= ~(1 << 15);
dib0090_write_reg(state, 0x21, PllCfg);
}
if (cfg->io.pll_bypass) {
PllCfg |= (cfg->io.pll_bypass << 15);
dib0090_write_reg(state, 0x21, PllCfg);
}
}
static int dib0090_fw_reset_digital(struct dvb_frontend *fe, const struct dib0090_config *cfg)
{
struct dib0090_fw_state *state = fe->tuner_priv;
u16 PllCfg;
u16 v;
int i;
dprintk("fw reset digital");
HARD_RESET(state);
dib0090_fw_write_reg(state, 0x24, EN_PLL | EN_CRYSTAL);
dib0090_fw_write_reg(state, 0x1b, EN_DIGCLK | EN_PLL | EN_CRYSTAL);
dib0090_fw_write_reg(state, 0x20,
((cfg->io.adc_clock_ratio - 1) << 11) | (0 << 10) | (1 << 9) | (1 << 8) | (cfg->data_tx_drv << 4) | cfg->ls_cfg_pad_drv);
v = (0 << 15) | ((!cfg->analog_output) << 14) | (1 << 9) | (0 << 8) | (cfg->clkouttobamse << 4) | (0 << 2) | (0);
if (cfg->clkoutdrive != 0)
v |= cfg->clkoutdrive << 5;
else
v |= 7 << 5;
v |= 2 << 10;
dib0090_fw_write_reg(state, 0x23, v);
PllCfg = dib0090_fw_read_reg(state, 0x21);
if ((PllCfg & 0x1FFF) != ((cfg->io.pll_range << 12) | (cfg->io.pll_loopdiv << 6) | (cfg->io.pll_prediv)) && !cfg->io.pll_bypass) {
PllCfg |= (1 << 15);
dib0090_fw_write_reg(state, 0x21, PllCfg);
PllCfg &= ~(1 << 13);
dib0090_fw_write_reg(state, 0x21, PllCfg);
PllCfg = (1 << 15) | (0 << 13) | (cfg->io.pll_range << 12) | (cfg->io.pll_loopdiv << 6) | (cfg->io.pll_prediv);
dib0090_fw_write_reg(state, 0x21, PllCfg);
PllCfg |= (1 << 13);
dib0090_fw_write_reg(state, 0x21, PllCfg);
i = 100;
do {
v = !!(dib0090_fw_read_reg(state, 0x1a) & 0x800);
if (v)
break;
} while (--i);
if (i == 0) {
dprintk("Pll: Unable to lock Pll");
return -EIO;
}
PllCfg &= ~(1 << 15);
dib0090_fw_write_reg(state, 0x21, PllCfg);
}
if (cfg->io.pll_bypass) {
PllCfg |= (cfg->io.pll_bypass << 15);
dib0090_fw_write_reg(state, 0x21, PllCfg);
}
return dib0090_fw_identify(fe);
}
static int dib0090_wakeup(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
if (state->config->sleep)
state->config->sleep(fe, 0);
dib0090_write_reg(state, 0x23, dib0090_read_reg(state, 0x23) | (1 << 14));
return 0;
}
static int dib0090_sleep(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
if (state->config->sleep)
state->config->sleep(fe, 1);
return 0;
}
void dib0090_dcc_freq(struct dvb_frontend *fe, u8 fast)
{
struct dib0090_state *state = fe->tuner_priv;
if (fast)
dib0090_write_reg(state, 0x04, 0);
else
dib0090_write_reg(state, 0x04, 1);
}
static u16 slopes_to_scale(const struct slope *slopes, u8 num, s16 val)
{
u8 i;
u16 rest;
u16 ret = 0;
for (i = 0; i < num; i++) {
if (val > slopes[i].range)
rest = slopes[i].range;
else
rest = val;
ret += (rest * slopes[i].slope) / slopes[i].range;
val -= rest;
}
return ret;
}
static s16 dib0090_wbd_to_db(struct dib0090_state *state, u16 wbd)
{
wbd &= 0x3ff;
if (wbd < state->wbd_offset)
wbd = 0;
else
wbd -= state->wbd_offset;
return -640 + (s16) slopes_to_scale(dib0090_wbd_slopes, ARRAY_SIZE(dib0090_wbd_slopes), wbd);
}
static void dib0090_wbd_target(struct dib0090_state *state, u32 rf)
{
u16 offset = 250;
if (state->current_band == BAND_VHF)
offset = 650;
#ifndef FIRMWARE_FIREFLY
if (state->current_band == BAND_VHF)
offset = state->config->wbd_vhf_offset;
if (state->current_band == BAND_CBAND)
offset = state->config->wbd_cband_offset;
#endif
state->wbd_target = dib0090_wbd_to_db(state, state->wbd_offset + offset);
dprintk("wbd-target: %d dB", (u32) state->wbd_target);
}
static void dib0090_gain_apply(struct dib0090_state *state, s16 gain_delta, s16 top_delta, u8 force)
{
u16 rf, bb, ref;
u16 i, v, gain_reg[4] = { 0 }, gain;
const u16 *g;
if (top_delta < -511)
top_delta = -511;
if (top_delta > 511)
top_delta = 511;
if (force) {
top_delta *= (1 << WBD_ALPHA);
gain_delta *= (1 << GAIN_ALPHA);
}
if (top_delta >= ((s16) (state->rf_ramp[0] << WBD_ALPHA) - state->rf_gain_limit))
state->rf_gain_limit = state->rf_ramp[0] << WBD_ALPHA;
else
state->rf_gain_limit += top_delta;
if (state->rf_gain_limit < 0)
state->rf_gain_limit = 0;
gain = ((state->rf_gain_limit >> WBD_ALPHA) + state->bb_ramp[0]) << GAIN_ALPHA;
if (gain_delta >= ((s16) gain - state->current_gain))
state->current_gain = gain;
else
state->current_gain += gain_delta;
if (state->current_gain < 0)
state->current_gain = 0;
gain = state->current_gain >> GAIN_ALPHA;
if (gain > (state->rf_gain_limit >> WBD_ALPHA)) {
rf = state->rf_gain_limit >> WBD_ALPHA;
bb = gain - rf;
if (bb > state->bb_ramp[0])
bb = state->bb_ramp[0];
} else {
rf = gain;
bb = 0;
}
state->gain[0] = rf;
state->gain[1] = bb;
g = state->rf_ramp + 1;
ref = rf;
for (i = 0; i < 7; i++) {
if (g[0] == 0 || ref < (g[1] - g[0]))
v = 0;
else if (ref >= g[1])
v = g[2];
else
v = ((ref - (g[1] - g[0])) * g[2]) / g[0];
if (i == 0)
gain_reg[0] = v;
else if (i == 1)
gain_reg[0] |= v << 7;
else if (i == 2)
gain_reg[1] = v;
else if (i == 3)
gain_reg[1] |= v << 7;
else if (i == 4)
gain_reg[2] = v | state->rf_lt_def;
else if (i == 5)
gain_reg[3] = v << 3;
else if (i == 6)
gain_reg[3] |= v << 8;
g += 3;
if (i == 4) {
g = state->bb_ramp + 1;
ref = bb;
}
}
gain_reg[3] |= state->bb_1_def;
gain_reg[3] |= ((bb % 10) * 100) / 125;
#ifdef DEBUG_AGC
dprintk("GA CALC: DB: %3d(rf) + %3d(bb) = %3d gain_reg[0]=%04x gain_reg[1]=%04x gain_reg[2]=%04x gain_reg[0]=%04x", rf, bb, rf + bb,
gain_reg[0], gain_reg[1], gain_reg[2], gain_reg[3]);
#endif
for (i = 0; i < 4; i++) {
v = gain_reg[i];
if (force || state->gain_reg[i] != v) {
state->gain_reg[i] = v;
dib0090_write_reg(state, gain_reg_addr[i], v);
}
}
}
static void dib0090_set_boost(struct dib0090_state *state, int onoff)
{
state->bb_1_def &= 0xdfff;
state->bb_1_def |= onoff << 13;
}
static void dib0090_set_rframp(struct dib0090_state *state, const u16 * cfg)
{
state->rf_ramp = cfg;
}
static void dib0090_set_rframp_pwm(struct dib0090_state *state, const u16 * cfg)
{
state->rf_ramp = cfg;
dib0090_write_reg(state, 0x2a, 0xffff);
dprintk("total RF gain: %ddB, step: %d", (u32) cfg[0], dib0090_read_reg(state, 0x2a));
dib0090_write_regs(state, 0x2c, cfg + 3, 6);
dib0090_write_regs(state, 0x3e, cfg + 9, 2);
}
static void dib0090_set_bbramp(struct dib0090_state *state, const u16 * cfg)
{
state->bb_ramp = cfg;
dib0090_set_boost(state, cfg[0] > 500);
}
static void dib0090_set_bbramp_pwm(struct dib0090_state *state, const u16 * cfg)
{
state->bb_ramp = cfg;
dib0090_set_boost(state, cfg[0] > 500);
dib0090_write_reg(state, 0x33, 0xffff);
dprintk("total BB gain: %ddB, step: %d", (u32) cfg[0], dib0090_read_reg(state, 0x33));
dib0090_write_regs(state, 0x35, cfg + 3, 4);
}
void dib0090_pwm_gain_reset(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
if (state->config->use_pwm_agc) {
#ifdef CONFIG_BAND_SBAND
if (state->current_band == BAND_SBAND) {
dib0090_set_rframp_pwm(state, rf_ramp_pwm_sband);
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_boost);
} else
#endif
#ifdef CONFIG_BAND_CBAND
if (state->current_band == BAND_CBAND) {
if (state->identity.in_soc) {
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal_socs);
if (state->identity.version == SOC_8090_P1G_11R1 || state->identity.version == SOC_8090_P1G_21R1)
dib0090_set_rframp_pwm(state, rf_ramp_pwm_cband_8090);
else if (state->identity.version == SOC_7090_P1G_11R1 || state->identity.version == SOC_7090_P1G_21R1)
dib0090_set_rframp_pwm(state, rf_ramp_pwm_cband_7090);
} else {
dib0090_set_rframp_pwm(state, rf_ramp_pwm_cband);
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal);
}
} else
#endif
#ifdef CONFIG_BAND_VHF
if (state->current_band == BAND_VHF) {
if (state->identity.in_soc) {
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal_socs);
} else {
dib0090_set_rframp_pwm(state, rf_ramp_pwm_vhf);
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal);
}
} else
#endif
{
if (state->identity.in_soc) {
if (state->identity.version == SOC_8090_P1G_11R1 || state->identity.version == SOC_8090_P1G_21R1)
dib0090_set_rframp_pwm(state, rf_ramp_pwm_uhf_8090);
else if (state->identity.version == SOC_7090_P1G_11R1 || state->identity.version == SOC_7090_P1G_21R1)
dib0090_set_rframp_pwm(state, rf_ramp_pwm_uhf_7090);
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal_socs);
} else {
dib0090_set_rframp_pwm(state, rf_ramp_pwm_uhf);
dib0090_set_bbramp_pwm(state, bb_ramp_pwm_normal);
}
}
if (state->rf_ramp[0] != 0)
dib0090_write_reg(state, 0x32, (3 << 11));
else
dib0090_write_reg(state, 0x32, (0 << 11));
dib0090_write_reg(state, 0x04, 0x01);
dib0090_write_reg(state, 0x39, (1 << 10));
}
}
static u32 dib0090_get_slow_adc_val(struct dib0090_state *state)
{
u16 adc_val = dib0090_read_reg(state, 0x1d);
if (state->identity.in_soc)
adc_val >>= 2;
return adc_val;
}
int dib0090_gain_control(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
enum frontend_tune_state *tune_state = &state->tune_state;
int ret = 10;
u16 wbd_val = 0;
u8 apply_gain_immediatly = 1;
s16 wbd_error = 0, adc_error = 0;
if (*tune_state == CT_AGC_START) {
state->agc_freeze = 0;
dib0090_write_reg(state, 0x04, 0x0);
#ifdef CONFIG_BAND_SBAND
if (state->current_band == BAND_SBAND) {
dib0090_set_rframp(state, rf_ramp_sband);
dib0090_set_bbramp(state, bb_ramp_boost);
} else
#endif
#ifdef CONFIG_BAND_VHF
if (state->current_band == BAND_VHF && !state->identity.p1g) {
dib0090_set_rframp(state, rf_ramp_vhf);
dib0090_set_bbramp(state, bb_ramp_boost);
} else
#endif
#ifdef CONFIG_BAND_CBAND
if (state->current_band == BAND_CBAND && !state->identity.p1g) {
dib0090_set_rframp(state, rf_ramp_cband);
dib0090_set_bbramp(state, bb_ramp_boost);
} else
#endif
if ((state->current_band == BAND_CBAND || state->current_band == BAND_VHF) && state->identity.p1g) {
dib0090_set_rframp(state, rf_ramp_cband_broadmatching);
dib0090_set_bbramp(state, bb_ramp_boost);
} else {
dib0090_set_rframp(state, rf_ramp_uhf);
dib0090_set_bbramp(state, bb_ramp_boost);
}
dib0090_write_reg(state, 0x32, 0);
dib0090_write_reg(state, 0x39, 0);
dib0090_wbd_target(state, state->current_rf);
state->rf_gain_limit = state->rf_ramp[0] << WBD_ALPHA;
state->current_gain = ((state->rf_ramp[0] + state->bb_ramp[0]) / 2) << GAIN_ALPHA;
*tune_state = CT_AGC_STEP_0;
} else if (!state->agc_freeze) {
s16 wbd = 0, i, cnt;
int adc;
wbd_val = dib0090_get_slow_adc_val(state);
if (*tune_state == CT_AGC_STEP_0)
cnt = 5;
else
cnt = 1;
for (i = 0; i < cnt; i++) {
wbd_val = dib0090_get_slow_adc_val(state);
wbd += dib0090_wbd_to_db(state, wbd_val);
}
wbd /= cnt;
wbd_error = state->wbd_target - wbd;
if (*tune_state == CT_AGC_STEP_0) {
if (wbd_error < 0 && state->rf_gain_limit > 0 && !state->identity.p1g) {
#ifdef CONFIG_BAND_CBAND
u8 ltg2 = (state->rf_lt_def >> 10) & 0x7;
if (state->current_band == BAND_CBAND && ltg2) {
ltg2 >>= 1;
state->rf_lt_def &= ltg2 << 10;
}
#endif
} else {
state->agc_step = 0;
*tune_state = CT_AGC_STEP_1;
}
} else {
adc = state->config->get_adc_power(fe);
adc = (adc * ((s32) 355774) + (((s32) 1) << 20)) >> 21;
adc_error = (s16) (((s32) ADC_TARGET) - adc);
#ifdef CONFIG_STANDARD_DAB
if (state->fe->dtv_property_cache.delivery_system == STANDARD_DAB)
adc_error -= 10;
#endif
#ifdef CONFIG_STANDARD_DVBT
if (state->fe->dtv_property_cache.delivery_system == STANDARD_DVBT &&
(state->fe->dtv_property_cache.modulation == QAM_64 || state->fe->dtv_property_cache.modulation == QAM_16))
adc_error += 60;
#endif
#ifdef CONFIG_SYS_ISDBT
if ((state->fe->dtv_property_cache.delivery_system == SYS_ISDBT) && (((state->fe->dtv_property_cache.layer[0].segment_count >
0)
&&
((state->fe->dtv_property_cache.layer[0].modulation ==
QAM_64)
|| (state->fe->dtv_property_cache.
layer[0].modulation == QAM_16)))
||
((state->fe->dtv_property_cache.layer[1].segment_count >
0)
&&
((state->fe->dtv_property_cache.layer[1].modulation ==
QAM_64)
|| (state->fe->dtv_property_cache.
layer[1].modulation == QAM_16)))
||
((state->fe->dtv_property_cache.layer[2].segment_count >
0)
&&
((state->fe->dtv_property_cache.layer[2].modulation ==
QAM_64)
|| (state->fe->dtv_property_cache.
layer[2].modulation == QAM_16)))
)
)
adc_error += 60;
#endif
if (*tune_state == CT_AGC_STEP_1) {
if (ABS(adc_error) < 50 || state->agc_step++ > 5) {
#ifdef CONFIG_STANDARD_DAB
if (state->fe->dtv_property_cache.delivery_system == STANDARD_DAB) {
dib0090_write_reg(state, 0x02, (1 << 15) | (15 << 11) | (31 << 6) | (63));
dib0090_write_reg(state, 0x04, 0x0);
} else
#endif
{
dib0090_write_reg(state, 0x02, (1 << 15) | (3 << 11) | (6 << 6) | (32));
dib0090_write_reg(state, 0x04, 0x01);
}
*tune_state = CT_AGC_STOP;
}
} else {
ret = 100;
apply_gain_immediatly = 0;
}
}
#ifdef DEBUG_AGC
dprintk
("tune state %d, ADC = %3ddB (ADC err %3d) WBD %3ddB (WBD err %3d, WBD val SADC: %4d), RFGainLimit (TOP): %3d, signal: %3ddBm",
(u32) *tune_state, (u32) adc, (u32) adc_error, (u32) wbd, (u32) wbd_error, (u32) wbd_val,
(u32) state->rf_gain_limit >> WBD_ALPHA, (s32) 200 + adc - (state->current_gain >> GAIN_ALPHA));
#endif
}
if (!state->agc_freeze)
dib0090_gain_apply(state, adc_error, wbd_error, apply_gain_immediatly);
return ret;
}
void dib0090_get_current_gain(struct dvb_frontend *fe, u16 * rf, u16 * bb, u16 * rf_gain_limit, u16 * rflt)
{
struct dib0090_state *state = fe->tuner_priv;
if (rf)
*rf = state->gain[0];
if (bb)
*bb = state->gain[1];
if (rf_gain_limit)
*rf_gain_limit = state->rf_gain_limit;
if (rflt)
*rflt = (state->rf_lt_def >> 10) & 0x7;
}
u16 dib0090_get_wbd_offset(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
u32 f_MHz = state->fe->dtv_property_cache.frequency / 1000000;
s32 current_temp = state->temperature;
s32 wbd_thot, wbd_tcold;
const struct dib0090_wbd_slope *wbd = state->current_wbd_table;
while (f_MHz > wbd->max_freq)
wbd++;
dprintk("using wbd-table-entry with max freq %d", wbd->max_freq);
if (current_temp < 0)
current_temp = 0;
if (current_temp > 128)
current_temp = 128;
state->wbdmux &= ~(7 << 13);
if (wbd->wbd_gain != 0)
state->wbdmux |= (wbd->wbd_gain << 13);
else
state->wbdmux |= (4 << 13);
dib0090_write_reg(state, 0x10, state->wbdmux);
wbd_thot = wbd->offset_hot - (((u32) wbd->slope_hot * f_MHz) >> 6);
wbd_tcold = wbd->offset_cold - (((u32) wbd->slope_cold * f_MHz) >> 6);
wbd_tcold += ((wbd_thot - wbd_tcold) * current_temp) >> 7;
state->wbd_target = dib0090_wbd_to_db(state, state->wbd_offset + wbd_tcold);
dprintk("wbd-target: %d dB", (u32) state->wbd_target);
dprintk("wbd offset applied is %d", wbd_tcold);
return state->wbd_offset + wbd_tcold;
}
static void dib0090_set_default_config(struct dib0090_state *state, const u16 * n)
{
u16 l, r;
l = pgm_read_word(n++);
while (l) {
r = pgm_read_word(n++);
do {
dib0090_write_reg(state, r, pgm_read_word(n++));
r++;
} while (--l);
l = pgm_read_word(n++);
}
}
void dib0090_set_EFUSE(struct dib0090_state *state)
{
u8 c, h, n;
u16 e2, e4;
u16 cal;
e2 = dib0090_read_reg(state, 0x26);
e4 = dib0090_read_reg(state, 0x28);
if ((state->identity.version == P1D_E_F) ||
(state->identity.version == P1G) || (e2 == 0xffff)) {
dib0090_write_reg(state, 0x22, 0x10);
cal = (dib0090_read_reg(state, 0x22) >> 6) & 0x3ff;
if ((cal < 670) || (cal == 1023))
cal = 850;
n = 165 - ((cal * 10)>>6) ;
e2 = e4 = (3<<12) | (34<<6) | (n);
}
if (e2 != e4)
e2 &= e4;
if (e2 != 0xffff) {
c = e2 & 0x3f;
n = (e2 >> 12) & 0xf;
h = (e2 >> 6) & 0x3f;
if ((c >= CAP_VALUE_MAX) || (c <= CAP_VALUE_MIN))
c = 32;
if ((h >= HR_MAX) || (h <= HR_MIN))
h = 34;
if ((n >= POLY_MAX) || (n <= POLY_MIN))
n = 3;
dib0090_write_reg(state, 0x13, (h << 10)) ;
e2 = (n<<11) | ((h>>2)<<6) | (c);
dib0090_write_reg(state, 0x2, e2) ;
}
}
static int dib0090_reset(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
dib0090_reset_digital(fe, state->config);
if (dib0090_identify(fe) < 0)
return -EIO;
#ifdef CONFIG_TUNER_DIB0090_P1B_SUPPORT
if (!(state->identity.version & 0x1))
return 0;
#endif
if (!state->identity.in_soc) {
if ((dib0090_read_reg(state, 0x1a) >> 5) & 0x2)
dib0090_write_reg(state, 0x1b, (EN_IQADC | EN_BB | EN_BIAS | EN_DIGCLK | EN_PLL | EN_CRYSTAL));
else
dib0090_write_reg(state, 0x1b, (EN_DIGCLK | EN_PLL | EN_CRYSTAL));
}
dib0090_set_default_config(state, dib0090_defaults);
if (state->identity.in_soc)
dib0090_write_reg(state, 0x18, 0x2910);
if (state->identity.p1g)
dib0090_set_default_config(state, dib0090_p1g_additionnal_defaults);
if (((state->identity.version & 0x1f) >= P1D_E_F) || (state->identity.in_soc))
dib0090_set_EFUSE(state);
if (state->config->io.clock_khz >= 24000)
dib0090_write_reg(state, 0x14, 1);
else
dib0090_write_reg(state, 0x14, 2);
dprintk("Pll lock : %d", (dib0090_read_reg(state, 0x1a) >> 11) & 0x1);
state->calibrate = DC_CAL | WBD_CAL | TEMP_CAL;
return 0;
}
static int dib0090_get_offset(struct dib0090_state *state, enum frontend_tune_state *tune_state)
{
int ret = INTERN_WAIT * 10;
switch (*tune_state) {
case CT_TUNER_STEP_2:
dib0090_write_reg(state, 0x1f, 0x7);
*tune_state = CT_TUNER_STEP_3;
break;
case CT_TUNER_STEP_3:
state->adc_diff = dib0090_read_reg(state, 0x1d);
dib0090_write_reg(state, 0x1f, 0x4);
*tune_state = CT_TUNER_STEP_4;
break;
case CT_TUNER_STEP_4:
state->adc_diff -= dib0090_read_reg(state, 0x1d);
*tune_state = CT_TUNER_STEP_5;
ret = 0;
break;
default:
break;
}
return ret;
}
static void dib0090_set_trim(struct dib0090_state *state)
{
u16 *val;
if (state->dc->addr == 0x07)
val = &state->bb7;
else
val = &state->bb6;
*val &= ~(0x1f << state->dc->offset);
*val |= state->step << state->dc->offset;
dib0090_write_reg(state, state->dc->addr, *val);
}
static int dib0090_dc_offset_calibration(struct dib0090_state *state, enum frontend_tune_state *tune_state)
{
int ret = 0;
u16 reg;
switch (*tune_state) {
case CT_TUNER_START:
dprintk("Start DC offset calibration");
state->bb6 = 0;
state->bb7 = 0x040d;
reg = dib0090_read_reg(state, 0x24) & 0x0ffb;
dib0090_write_reg(state, 0x24, reg);
state->wbdmux = dib0090_read_reg(state, 0x10);
dib0090_write_reg(state, 0x10, (state->wbdmux & ~(0xff << 3)) | (0x7 << 3) | 0x3);
dib0090_write_reg(state, 0x23, dib0090_read_reg(state, 0x23) & ~(1 << 14));
state->dc = dc_table;
if (state->identity.p1g)
state->dc = dc_p1g_table;
*tune_state = CT_TUNER_STEP_0;
case CT_TUNER_STEP_0:
dprintk("Sart/continue DC calibration for %s path", (state->dc->i == 1) ? "I" : "Q");
dib0090_write_reg(state, 0x01, state->dc->bb1);
dib0090_write_reg(state, 0x07, state->bb7 | (state->dc->i << 7));
state->step = 0;
state->min_adc_diff = 1023;
*tune_state = CT_TUNER_STEP_1;
ret = 50;
break;
case CT_TUNER_STEP_1:
dib0090_set_trim(state);
*tune_state = CT_TUNER_STEP_2;
break;
case CT_TUNER_STEP_2:
case CT_TUNER_STEP_3:
case CT_TUNER_STEP_4:
ret = dib0090_get_offset(state, tune_state);
break;
case CT_TUNER_STEP_5:
dprintk("adc_diff = %d, current step= %d", (u32) state->adc_diff, state->step);
if (state->step == 0 && state->adc_diff < 0) {
state->min_adc_diff = -1023;
dprintk("Change of sign of the minimum adc diff");
}
dprintk("adc_diff = %d, min_adc_diff = %d current_step = %d", state->adc_diff, state->min_adc_diff, state->step);
if (state->step == 0) {
if (state->dc->pga && state->adc_diff < 0)
state->step = 0x10;
if (state->dc->pga == 0 && state->adc_diff > 0)
state->step = 0x10;
}
if ((state->adc_diff & 0x8000) == (state->min_adc_diff & 0x8000) && steps(state->step) < 15) {
state->step++;
state->min_adc_diff = state->adc_diff;
*tune_state = CT_TUNER_STEP_1;
} else {
if (ABS(state->adc_diff) > ABS(state->min_adc_diff)) {
dprintk("Since adc_diff N = %d > adc_diff step N-1 = %d, Come back one step", state->adc_diff, state->min_adc_diff);
state->step--;
}
dib0090_set_trim(state);
dprintk("BB Offset Cal, BBreg=%hd,Offset=%hd,Value Set=%hd", state->dc->addr, state->adc_diff, state->step);
state->dc++;
if (state->dc->addr == 0)
*tune_state = CT_TUNER_STEP_6;
else
*tune_state = CT_TUNER_STEP_0;
}
break;
case CT_TUNER_STEP_6:
dib0090_write_reg(state, 0x07, state->bb7 & ~0x0008);
dib0090_write_reg(state, 0x1f, 0x7);
*tune_state = CT_TUNER_START;
state->calibrate &= ~DC_CAL;
default:
break;
}
return ret;
}
static int dib0090_wbd_calibration(struct dib0090_state *state, enum frontend_tune_state *tune_state)
{
u8 wbd_gain;
const struct dib0090_wbd_slope *wbd = state->current_wbd_table;
switch (*tune_state) {
case CT_TUNER_START:
while (state->current_rf / 1000 > wbd->max_freq)
wbd++;
if (wbd->wbd_gain != 0)
wbd_gain = wbd->wbd_gain;
else {
wbd_gain = 4;
#if defined(CONFIG_BAND_LBAND) || defined(CONFIG_BAND_SBAND)
if ((state->current_band == BAND_LBAND) || (state->current_band == BAND_SBAND))
wbd_gain = 2;
#endif
}
if (wbd_gain == state->wbd_calibration_gain) {
*tune_state = CT_TUNER_START;
state->calibrate &= ~WBD_CAL;
return 0;
}
dib0090_write_reg(state, 0x10, 0x1b81 | (1 << 10) | (wbd_gain << 13) | (1 << 3));
dib0090_write_reg(state, 0x24, ((EN_UHF & 0x0fff) | (1 << 1)));
*tune_state = CT_TUNER_STEP_0;
state->wbd_calibration_gain = wbd_gain;
return 90;
case CT_TUNER_STEP_0:
state->wbd_offset = dib0090_get_slow_adc_val(state);
dprintk("WBD calibration offset = %d", state->wbd_offset);
*tune_state = CT_TUNER_START;
state->calibrate &= ~WBD_CAL;
break;
default:
break;
}
return 0;
}
static void dib0090_set_bandwidth(struct dib0090_state *state)
{
u16 tmp;
if (state->fe->dtv_property_cache.bandwidth_hz / 1000 <= 5000)
tmp = (3 << 14);
else if (state->fe->dtv_property_cache.bandwidth_hz / 1000 <= 6000)
tmp = (2 << 14);
else if (state->fe->dtv_property_cache.bandwidth_hz / 1000 <= 7000)
tmp = (1 << 14);
else
tmp = (0 << 14);
state->bb_1_def &= 0x3fff;
state->bb_1_def |= tmp;
dib0090_write_reg(state, 0x01, state->bb_1_def);
dib0090_write_reg(state, 0x03, 0x6008);
dib0090_write_reg(state, 0x04, 0x1);
if (state->identity.in_soc) {
dib0090_write_reg(state, 0x05, 0x9bcf);
} else {
dib0090_write_reg(state, 0x02, (5 << 11) | (8 << 6) | (22 & 0x3f));
dib0090_write_reg(state, 0x05, 0xabcd);
}
}
static int dib0090_captrim_search(struct dib0090_state *state, enum frontend_tune_state *tune_state)
{
int ret = 0;
u16 lo4 = 0xe900;
s16 adc_target;
u16 adc;
s8 step_sign;
u8 force_soft_search = 0;
if (state->identity.version == SOC_8090_P1G_11R1 || state->identity.version == SOC_8090_P1G_21R1)
force_soft_search = 1;
if (*tune_state == CT_TUNER_START) {
dprintk("Start Captrim search : %s", (force_soft_search == 1) ? "FORCE SOFT SEARCH" : "AUTO");
dib0090_write_reg(state, 0x10, 0x2B1);
dib0090_write_reg(state, 0x1e, 0x0032);
if (!state->tuner_is_tuned) {
if (!state->identity.p1g || force_soft_search)
state->step = state->captrim = state->fcaptrim = 64;
state->current_rf = state->rf_request;
} else {
if (!state->identity.p1g || force_soft_search) {
state->step = 4;
state->captrim = state->fcaptrim = dib0090_read_reg(state, 0x18) & 0x7f;
}
}
state->adc_diff = 3000;
*tune_state = CT_TUNER_STEP_0;
} else if (*tune_state == CT_TUNER_STEP_0) {
if (state->identity.p1g && !force_soft_search) {
u8 ratio = 31;
dib0090_write_reg(state, 0x40, (3 << 7) | (ratio << 2) | (1 << 1) | 1);
dib0090_read_reg(state, 0x40);
ret = 50;
} else {
state->step /= 2;
dib0090_write_reg(state, 0x18, lo4 | state->captrim);
if (state->identity.in_soc)
ret = 25;
}
*tune_state = CT_TUNER_STEP_1;
} else if (*tune_state == CT_TUNER_STEP_1) {
if (state->identity.p1g && !force_soft_search) {
dib0090_write_reg(state, 0x40, 0x18c | (0 << 1) | 0);
dib0090_read_reg(state, 0x40);
state->fcaptrim = dib0090_read_reg(state, 0x18) & 0x7F;
dprintk("***Final Captrim= 0x%x", state->fcaptrim);
*tune_state = CT_TUNER_STEP_3;
} else {
adc = dib0090_get_slow_adc_val(state);
dprintk("CAPTRIM=%d; ADC = %d (ADC) & %dmV", (u32) state->captrim, (u32) adc, (u32) (adc) * (u32) 1800 / (u32) 1024);
if (state->rest == 0 || state->identity.in_soc) {
adc_target = 200;
} else
adc_target = 400;
if (adc >= adc_target) {
adc -= adc_target;
step_sign = -1;
} else {
adc = adc_target - adc;
step_sign = 1;
}
if (adc < state->adc_diff) {
dprintk("CAPTRIM=%d is closer to target (%d/%d)", (u32) state->captrim, (u32) adc, (u32) state->adc_diff);
state->adc_diff = adc;
state->fcaptrim = state->captrim;
}
state->captrim += step_sign * state->step;
if (state->step >= 1)
*tune_state = CT_TUNER_STEP_0;
else
*tune_state = CT_TUNER_STEP_2;
ret = 25;
}
} else if (*tune_state == CT_TUNER_STEP_2) {
dib0090_write_reg(state, 0x18, lo4 | state->fcaptrim);
*tune_state = CT_TUNER_STEP_3;
} else if (*tune_state == CT_TUNER_STEP_3) {
state->calibrate &= ~CAPTRIM_CAL;
*tune_state = CT_TUNER_STEP_0;
}
return ret;
}
static int dib0090_get_temperature(struct dib0090_state *state, enum frontend_tune_state *tune_state)
{
int ret = 15;
s16 val;
switch (*tune_state) {
case CT_TUNER_START:
state->wbdmux = dib0090_read_reg(state, 0x10);
dib0090_write_reg(state, 0x10, (state->wbdmux & ~(0xff << 3)) | (0x8 << 3));
state->bias = dib0090_read_reg(state, 0x13);
dib0090_write_reg(state, 0x13, state->bias | (0x3 << 8));
*tune_state = CT_TUNER_STEP_0;
break;
case CT_TUNER_STEP_0:
state->adc_diff = dib0090_get_slow_adc_val(state);
dib0090_write_reg(state, 0x13, (state->bias & ~(0x3 << 8)) | (0x2 << 8));
*tune_state = CT_TUNER_STEP_1;
break;
case CT_TUNER_STEP_1:
val = dib0090_get_slow_adc_val(state);
state->temperature = ((s16) ((val - state->adc_diff) * 180) >> 8) + 55;
dprintk("temperature: %d C", state->temperature - 30);
*tune_state = CT_TUNER_STEP_2;
break;
case CT_TUNER_STEP_2:
dib0090_write_reg(state, 0x13, state->bias);
dib0090_write_reg(state, 0x10, state->wbdmux);
*tune_state = CT_TUNER_START;
state->calibrate &= ~TEMP_CAL;
if (state->config->analog_output == 0)
dib0090_write_reg(state, 0x23, dib0090_read_reg(state, 0x23) | (1 << 14));
break;
default:
ret = 0;
break;
}
return ret;
}
static int dib0090_tune(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
const struct dib0090_tuning *tune = state->current_tune_table_index;
const struct dib0090_pll *pll = state->current_pll_table_index;
enum frontend_tune_state *tune_state = &state->tune_state;
u16 lo5, lo6, Den, tmp;
u32 FBDiv, Rest, FREF, VCOF_kHz = 0;
int ret = 10;
u8 c, i;
if (*tune_state == CT_TUNER_START) {
if (state->calibrate & (DC_CAL | TEMP_CAL | WBD_CAL))
dib0090_write_reg(state, 0x23, dib0090_read_reg(state, 0x23) & ~(1 << 14));
else
if (state->config->analog_output == 0)
dib0090_write_reg(state, 0x23, dib0090_read_reg(state, 0x23) | (1 << 14));
}
if (state->calibrate & DC_CAL)
return dib0090_dc_offset_calibration(state, tune_state);
else if (state->calibrate & WBD_CAL) {
if (state->current_rf == 0)
state->current_rf = state->fe->dtv_property_cache.frequency / 1000;
return dib0090_wbd_calibration(state, tune_state);
} else if (state->calibrate & TEMP_CAL)
return dib0090_get_temperature(state, tune_state);
else if (state->calibrate & CAPTRIM_CAL)
return dib0090_captrim_search(state, tune_state);
if (*tune_state == CT_TUNER_START) {
if (state->config->use_pwm_agc && state->identity.in_soc) {
tmp = dib0090_read_reg(state, 0x39);
if ((tmp >> 10) & 0x1)
dib0090_write_reg(state, 0x39, tmp & ~(1 << 10));
}
state->current_band = (u8) BAND_OF_FREQUENCY(state->fe->dtv_property_cache.frequency / 1000);
state->rf_request =
state->fe->dtv_property_cache.frequency / 1000 + (state->current_band ==
BAND_UHF ? state->config->freq_offset_khz_uhf : state->config->
freq_offset_khz_vhf);
if ((state->fe->dtv_property_cache.delivery_system == SYS_ISDBT && state->fe->dtv_property_cache.isdbt_sb_mode == 1
&& state->fe->dtv_property_cache.isdbt_partial_reception == 0)) {
const struct dib0090_low_if_offset_table *LUT_offset = state->config->low_if;
u8 found_offset = 0;
u32 margin_khz = 100;
if (LUT_offset != NULL) {
while (LUT_offset->RF_freq != 0xffff) {
if (((state->rf_request > (LUT_offset->RF_freq - margin_khz))
&& (state->rf_request < (LUT_offset->RF_freq + margin_khz)))
&& LUT_offset->std == state->fe->dtv_property_cache.delivery_system) {
state->rf_request += LUT_offset->offset_khz;
found_offset = 1;
break;
}
LUT_offset++;
}
}
if (found_offset == 0)
state->rf_request += 400;
}
if (state->current_rf != state->rf_request || (state->current_standard != state->fe->dtv_property_cache.delivery_system)) {
state->tuner_is_tuned = 0;
state->current_rf = 0;
state->current_standard = 0;
tune = dib0090_tuning_table;
if (state->identity.p1g)
tune = dib0090_p1g_tuning_table;
tmp = (state->identity.version >> 5) & 0x7;
if (state->identity.in_soc) {
if (state->config->force_cband_input) {
if (state->current_band & BAND_CBAND || state->current_band & BAND_FM || state->current_band & BAND_VHF
|| state->current_band & BAND_UHF) {
state->current_band = BAND_CBAND;
tune = dib0090_tuning_table_cband_7090;
}
} else {
if (state->current_band & BAND_CBAND || state->current_band & BAND_FM || state->current_band & BAND_VHF) {
state->current_band = BAND_CBAND;
tune = dib0090_tuning_table_cband_7090;
}
}
} else
if (tmp == 0x4 || tmp == 0x7) {
if (state->current_band == BAND_FM || state->current_band == BAND_CBAND || state->current_band == BAND_VHF) {
state->current_band = BAND_CBAND;
tune = dib0090_tuning_table_fm_vhf_on_cband;
if (state->identity.p1g)
tune = dib0090_p1g_tuning_table_fm_vhf_on_cband;
}
}
pll = dib0090_pll_table;
if (state->identity.p1g)
pll = dib0090_p1g_pll_table;
while (state->rf_request > tune->max_freq)
tune++;
while (state->rf_request > pll->max_freq)
pll++;
state->current_tune_table_index = tune;
state->current_pll_table_index = pll;
dib0090_write_reg(state, 0x0b, 0xb800 | (tune->switch_trim));
VCOF_kHz = (pll->hfdiv * state->rf_request) * 2;
FREF = state->config->io.clock_khz;
if (state->config->fref_clock_ratio != 0)
FREF /= state->config->fref_clock_ratio;
FBDiv = (VCOF_kHz / pll->topresc / FREF);
Rest = (VCOF_kHz / pll->topresc) - FBDiv * FREF;
if (Rest < LPF)
Rest = 0;
else if (Rest < 2 * LPF)
Rest = 2 * LPF;
else if (Rest > (FREF - LPF)) {
Rest = 0;
FBDiv += 1;
} else if (Rest > (FREF - 2 * LPF))
Rest = FREF - 2 * LPF;
Rest = (Rest * 6528) / (FREF / 10);
state->rest = Rest;
if (Rest == 0) {
if (pll->vco_band)
lo5 = 0x049f;
else
lo5 = 0x041f;
} else {
if (pll->vco_band)
lo5 = 0x049e;
else if (state->config->analog_output)
lo5 = 0x041d;
else
lo5 = 0x041c;
}
if (state->identity.p1g) {
if (state->identity.in_soc) {
if (state->identity.version == SOC_8090_P1G_11R1)
lo5 = 0x46f;
else
lo5 = 0x42f;
} else
lo5 = 0x42c;
}
lo5 |= (pll->hfdiv_code << 11) | (pll->vco_band << 7);
if (!state->config->io.pll_int_loop_filt) {
if (state->identity.in_soc)
lo6 = 0xff98;
else if (state->identity.p1g || (Rest == 0))
lo6 = 0xfff8;
else
lo6 = 0xff28;
} else
lo6 = (state->config->io.pll_int_loop_filt << 3);
Den = 1;
if (Rest > 0) {
if (state->config->analog_output)
lo6 |= (1 << 2) | 2;
else {
if (state->identity.in_soc)
lo6 |= (1 << 2) | 2;
else
lo6 |= (1 << 2) | 2;
}
Den = 255;
}
dib0090_write_reg(state, 0x15, (u16) FBDiv);
if (state->config->fref_clock_ratio != 0)
dib0090_write_reg(state, 0x16, (Den << 8) | state->config->fref_clock_ratio);
else
dib0090_write_reg(state, 0x16, (Den << 8) | 1);
dib0090_write_reg(state, 0x17, (u16) Rest);
dib0090_write_reg(state, 0x19, lo5);
dib0090_write_reg(state, 0x1c, lo6);
lo6 = tune->tuner_enable;
if (state->config->analog_output)
lo6 = (lo6 & 0xff9f) | 0x2;
dib0090_write_reg(state, 0x24, lo6 | EN_LO | state->config->use_pwm_agc * EN_CRYSTAL);
}
state->current_rf = state->rf_request;
state->current_standard = state->fe->dtv_property_cache.delivery_system;
ret = 20;
state->calibrate = CAPTRIM_CAL;
}
else if (*tune_state == CT_TUNER_STEP_0) {
const struct dib0090_wbd_slope *wbd = state->current_wbd_table;
while (state->current_rf / 1000 > wbd->max_freq)
wbd++;
dib0090_write_reg(state, 0x1e, 0x07ff);
dprintk("Final Captrim: %d", (u32) state->fcaptrim);
dprintk("HFDIV code: %d", (u32) pll->hfdiv_code);
dprintk("VCO = %d", (u32) pll->vco_band);
dprintk("VCOF in kHz: %d ((%d*%d) << 1))", (u32) ((pll->hfdiv * state->rf_request) * 2), (u32) pll->hfdiv, (u32) state->rf_request);
dprintk("REFDIV: %d, FREF: %d", (u32) 1, (u32) state->config->io.clock_khz);
dprintk("FBDIV: %d, Rest: %d", (u32) dib0090_read_reg(state, 0x15), (u32) dib0090_read_reg(state, 0x17));
dprintk("Num: %d, Den: %d, SD: %d", (u32) dib0090_read_reg(state, 0x17), (u32) (dib0090_read_reg(state, 0x16) >> 8),
(u32) dib0090_read_reg(state, 0x1c) & 0x3);
#define WBD 0x781
c = 4;
i = 3;
if (wbd->wbd_gain != 0)
c = wbd->wbd_gain;
state->wbdmux = (c << 13) | (i << 11) | (WBD | (state->config->use_pwm_agc << 1));
dib0090_write_reg(state, 0x10, state->wbdmux);
if ((tune->tuner_enable == EN_CAB) && state->identity.p1g) {
dprintk("P1G : The cable band is selected and lna_tune = %d", tune->lna_tune);
dib0090_write_reg(state, 0x09, tune->lna_bias);
dib0090_write_reg(state, 0x0b, 0xb800 | (tune->lna_tune << 6) | (tune->switch_trim));
} else
dib0090_write_reg(state, 0x09, (tune->lna_tune << 5) | tune->lna_bias);
dib0090_write_reg(state, 0x0c, tune->v2i);
dib0090_write_reg(state, 0x0d, tune->mix);
dib0090_write_reg(state, 0x0e, tune->load);
*tune_state = CT_TUNER_STEP_1;
} else if (*tune_state == CT_TUNER_STEP_1) {
state->rf_lt_def = 0x7c00;
dib0090_set_bandwidth(state);
state->tuner_is_tuned = 1;
state->calibrate |= WBD_CAL;
state->calibrate |= TEMP_CAL;
*tune_state = CT_TUNER_STOP;
} else
ret = FE_CALLBACK_TIME_NEVER;
return ret;
}
static int dib0090_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
enum frontend_tune_state dib0090_get_tune_state(struct dvb_frontend *fe)
{
struct dib0090_state *state = fe->tuner_priv;
return state->tune_state;
}
int dib0090_set_tune_state(struct dvb_frontend *fe, enum frontend_tune_state tune_state)
{
struct dib0090_state *state = fe->tuner_priv;
state->tune_state = tune_state;
return 0;
}
static int dib0090_get_frequency(struct dvb_frontend *fe, u32 * frequency)
{
struct dib0090_state *state = fe->tuner_priv;
*frequency = 1000 * state->current_rf;
return 0;
}
static int dib0090_set_params(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
struct dib0090_state *state = fe->tuner_priv;
u32 ret;
state->tune_state = CT_TUNER_START;
do {
ret = dib0090_tune(fe);
if (ret != FE_CALLBACK_TIME_NEVER)
msleep(ret / 10);
else
break;
} while (state->tune_state != CT_TUNER_STOP);
return 0;
}
struct dvb_frontend *dib0090_register(struct dvb_frontend *fe, struct i2c_adapter *i2c, const struct dib0090_config *config)
{
struct dib0090_state *st = kzalloc(sizeof(struct dib0090_state), GFP_KERNEL);
if (st == NULL)
return NULL;
st->config = config;
st->i2c = i2c;
st->fe = fe;
fe->tuner_priv = st;
if (config->wbd == NULL)
st->current_wbd_table = dib0090_wbd_table_default;
else
st->current_wbd_table = config->wbd;
if (dib0090_reset(fe) != 0)
goto free_mem;
printk(KERN_INFO "DiB0090: successfully identified\n");
memcpy(&fe->ops.tuner_ops, &dib0090_ops, sizeof(struct dvb_tuner_ops));
return fe;
free_mem:
kfree(st);
fe->tuner_priv = NULL;
return NULL;
}
struct dvb_frontend *dib0090_fw_register(struct dvb_frontend *fe, struct i2c_adapter *i2c, const struct dib0090_config *config)
{
struct dib0090_fw_state *st = kzalloc(sizeof(struct dib0090_fw_state), GFP_KERNEL);
if (st == NULL)
return NULL;
st->config = config;
st->i2c = i2c;
st->fe = fe;
fe->tuner_priv = st;
if (dib0090_fw_reset_digital(fe, st->config) != 0)
goto free_mem;
dprintk("DiB0090 FW: successfully identified");
memcpy(&fe->ops.tuner_ops, &dib0090_fw_ops, sizeof(struct dvb_tuner_ops));
return fe;
free_mem:
kfree(st);
fe->tuner_priv = NULL;
return NULL;
}
