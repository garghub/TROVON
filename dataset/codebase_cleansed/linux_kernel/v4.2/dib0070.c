static u16 dib0070_read_reg(struct dib0070_state *state, u8 reg)
{
u16 ret;
if (mutex_lock_interruptible(&state->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return 0;
}
state->i2c_write_buffer[0] = reg;
memset(state->msg, 0, 2 * sizeof(struct i2c_msg));
state->msg[0].addr = state->cfg->i2c_address;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 1;
state->msg[1].addr = state->cfg->i2c_address;
state->msg[1].flags = I2C_M_RD;
state->msg[1].buf = state->i2c_read_buffer;
state->msg[1].len = 2;
if (i2c_transfer(state->i2c, state->msg, 2) != 2) {
printk(KERN_WARNING "DiB0070 I2C read failed\n");
ret = 0;
} else
ret = (state->i2c_read_buffer[0] << 8)
| state->i2c_read_buffer[1];
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static int dib0070_write_reg(struct dib0070_state *state, u8 reg, u16 val)
{
int ret;
if (mutex_lock_interruptible(&state->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return -EINVAL;
}
state->i2c_write_buffer[0] = reg;
state->i2c_write_buffer[1] = val >> 8;
state->i2c_write_buffer[2] = val & 0xff;
memset(state->msg, 0, sizeof(struct i2c_msg));
state->msg[0].addr = state->cfg->i2c_address;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 3;
if (i2c_transfer(state->i2c, state->msg, 1) != 1) {
printk(KERN_WARNING "DiB0070 I2C write failed\n");
ret = -EREMOTEIO;
} else
ret = 0;
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static int dib0070_set_bandwidth(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
u16 tmp = dib0070_read_reg(state, 0x02) & 0x3fff;
if (state->fe->dtv_property_cache.bandwidth_hz/1000 > 7000)
tmp |= (0 << 14);
else if (state->fe->dtv_property_cache.bandwidth_hz/1000 > 6000)
tmp |= (1 << 14);
else if (state->fe->dtv_property_cache.bandwidth_hz/1000 > 5000)
tmp |= (2 << 14);
else
tmp |= (3 << 14);
dib0070_write_reg(state, 0x02, tmp);
if (state->fe->dtv_property_cache.delivery_system == SYS_ISDBT) {
u16 value = dib0070_read_reg(state, 0x17);
dib0070_write_reg(state, 0x17, value & 0xfffc);
tmp = dib0070_read_reg(state, 0x01) & 0x01ff;
dib0070_write_reg(state, 0x01, tmp | (60 << 9));
dib0070_write_reg(state, 0x17, value);
}
return 0;
}
static int dib0070_captrim(struct dib0070_state *state, enum frontend_tune_state *tune_state)
{
int8_t step_sign;
u16 adc;
int ret = 0;
if (*tune_state == CT_TUNER_STEP_0) {
dib0070_write_reg(state, 0x0f, 0xed10);
dib0070_write_reg(state, 0x17, 0x0034);
dib0070_write_reg(state, 0x18, 0x0032);
state->step = state->captrim = state->fcaptrim = 64;
state->adc_diff = 3000;
ret = 20;
*tune_state = CT_TUNER_STEP_1;
} else if (*tune_state == CT_TUNER_STEP_1) {
state->step /= 2;
dib0070_write_reg(state, 0x14, state->lo4 | state->captrim);
ret = 15;
*tune_state = CT_TUNER_STEP_2;
} else if (*tune_state == CT_TUNER_STEP_2) {
adc = dib0070_read_reg(state, 0x19);
dprintk("CAPTRIM=%hd; ADC = %hd (ADC) & %dmV", state->captrim, adc, (u32) adc*(u32)1800/(u32)1024);
if (adc >= 400) {
adc -= 400;
step_sign = -1;
} else {
adc = 400 - adc;
step_sign = 1;
}
if (adc < state->adc_diff) {
dprintk("CAPTRIM=%hd is closer to target (%hd/%hd)", state->captrim, adc, state->adc_diff);
state->adc_diff = adc;
state->fcaptrim = state->captrim;
}
state->captrim += (step_sign * state->step);
if (state->step >= 1)
*tune_state = CT_TUNER_STEP_1;
else
*tune_state = CT_TUNER_STEP_3;
} else if (*tune_state == CT_TUNER_STEP_3) {
dib0070_write_reg(state, 0x14, state->lo4 | state->fcaptrim);
dib0070_write_reg(state, 0x18, 0x07ff);
*tune_state = CT_TUNER_STEP_4;
}
return ret;
}
static int dib0070_set_ctrl_lo5(struct dvb_frontend *fe, u8 vco_bias_trim, u8 hf_div_trim, u8 cp_current, u8 third_order_filt)
{
struct dib0070_state *state = fe->tuner_priv;
u16 lo5 = (third_order_filt << 14) | (0 << 13) | (1 << 12) | (3 << 9) | (cp_current << 6) | (hf_div_trim << 3) | (vco_bias_trim << 0);
dprintk("CTRL_LO5: 0x%x", lo5);
return dib0070_write_reg(state, 0x15, lo5);
}
void dib0070_ctrl_agc_filter(struct dvb_frontend *fe, u8 open)
{
struct dib0070_state *state = fe->tuner_priv;
if (open) {
dib0070_write_reg(state, 0x1b, 0xff00);
dib0070_write_reg(state, 0x1a, 0x0000);
} else {
dib0070_write_reg(state, 0x1b, 0x4112);
if (state->cfg->vga_filter != 0) {
dib0070_write_reg(state, 0x1a, state->cfg->vga_filter);
dprintk("vga filter register is set to %x", state->cfg->vga_filter);
} else
dib0070_write_reg(state, 0x1a, 0x0009);
}
}
static int dib0070_tune_digital(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
const struct dib0070_tuning *tune;
const struct dib0070_lna_match *lna_match;
enum frontend_tune_state *tune_state = &state->tune_state;
int ret = 10;
u8 band = (u8)BAND_OF_FREQUENCY(fe->dtv_property_cache.frequency/1000);
u32 freq = fe->dtv_property_cache.frequency/1000 + (band == BAND_VHF ? state->cfg->freq_offset_khz_vhf : state->cfg->freq_offset_khz_uhf);
#ifdef CONFIG_SYS_ISDBT
if (state->fe->dtv_property_cache.delivery_system == SYS_ISDBT && state->fe->dtv_property_cache.isdbt_sb_mode == 1)
if (((state->fe->dtv_property_cache.isdbt_sb_segment_count % 2)
&& (state->fe->dtv_property_cache.isdbt_sb_segment_idx == ((state->fe->dtv_property_cache.isdbt_sb_segment_count / 2) + 1)))
|| (((state->fe->dtv_property_cache.isdbt_sb_segment_count % 2) == 0)
&& (state->fe->dtv_property_cache.isdbt_sb_segment_idx == (state->fe->dtv_property_cache.isdbt_sb_segment_count / 2)))
|| (((state->fe->dtv_property_cache.isdbt_sb_segment_count % 2) == 0)
&& (state->fe->dtv_property_cache.isdbt_sb_segment_idx == ((state->fe->dtv_property_cache.isdbt_sb_segment_count / 2) + 1))))
freq += 850;
#endif
if (state->current_rf != freq) {
switch (state->revision) {
case DIB0070S_P1A:
tune = dib0070s_tuning_table;
lna_match = dib0070_lna;
break;
default:
tune = dib0070_tuning_table;
if (state->cfg->flip_chip)
lna_match = dib0070_lna_flip_chip;
else
lna_match = dib0070_lna;
break;
}
while (freq > tune->max_freq)
tune++;
while (freq > lna_match->max_freq)
lna_match++;
state->current_tune_table_index = tune;
state->lna_match = lna_match;
}
if (*tune_state == CT_TUNER_START) {
dprintk("Tuning for Band: %hd (%d kHz)", band, freq);
if (state->current_rf != freq) {
u8 REFDIV;
u32 FBDiv, Rest, FREF, VCOF_kHz;
u8 Den;
state->current_rf = freq;
state->lo4 = (state->current_tune_table_index->vco_band << 11) | (state->current_tune_table_index->hfdiv << 7);
dib0070_write_reg(state, 0x17, 0x30);
VCOF_kHz = state->current_tune_table_index->vco_multi * freq * 2;
switch (band) {
case BAND_VHF:
REFDIV = (u8) ((state->cfg->clock_khz + 9999) / 10000);
break;
case BAND_FM:
REFDIV = (u8) ((state->cfg->clock_khz) / 1000);
break;
default:
REFDIV = (u8) (state->cfg->clock_khz / 10000);
break;
}
FREF = state->cfg->clock_khz / REFDIV;
switch (state->revision) {
case DIB0070S_P1A:
FBDiv = (VCOF_kHz / state->current_tune_table_index->presc / FREF);
Rest = (VCOF_kHz / state->current_tune_table_index->presc) - FBDiv * FREF;
break;
case DIB0070_P1G:
case DIB0070_P1F:
default:
FBDiv = (freq / (FREF / 2));
Rest = 2 * freq - FBDiv * FREF;
break;
}
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
Den = 1;
if (Rest > 0) {
state->lo4 |= (1 << 14) | (1 << 12);
Den = 255;
}
dib0070_write_reg(state, 0x11, (u16)FBDiv);
dib0070_write_reg(state, 0x12, (Den << 8) | REFDIV);
dib0070_write_reg(state, 0x13, (u16) Rest);
if (state->revision == DIB0070S_P1A) {
if (band == BAND_SBAND) {
dib0070_set_ctrl_lo5(fe, 2, 4, 3, 0);
dib0070_write_reg(state, 0x1d, 0xFFFF);
} else
dib0070_set_ctrl_lo5(fe, 5, 4, 3, 1);
}
dib0070_write_reg(state, 0x20,
0x0040 | 0x0020 | 0x0010 | 0x0008 | 0x0002 | 0x0001 | state->current_tune_table_index->tuner_enable);
dprintk("REFDIV: %hd, FREF: %d", REFDIV, FREF);
dprintk("FBDIV: %d, Rest: %d", FBDiv, Rest);
dprintk("Num: %hd, Den: %hd, SD: %hd", (u16) Rest, Den, (state->lo4 >> 12) & 0x1);
dprintk("HFDIV code: %hd", state->current_tune_table_index->hfdiv);
dprintk("VCO = %hd", state->current_tune_table_index->vco_band);
dprintk("VCOF: ((%hd*%d) << 1))", state->current_tune_table_index->vco_multi, freq);
*tune_state = CT_TUNER_STEP_0;
} else {
ret = 50;
*tune_state = CT_TUNER_STEP_5;
}
} else if ((*tune_state > CT_TUNER_START) && (*tune_state < CT_TUNER_STEP_4)) {
ret = dib0070_captrim(state, tune_state);
} else if (*tune_state == CT_TUNER_STEP_4) {
const struct dib0070_wbd_gain_cfg *tmp = state->cfg->wbd_gain;
if (tmp != NULL) {
while (freq/1000 > tmp->freq)
tmp++;
dib0070_write_reg(state, 0x0f,
(0 << 15) | (1 << 14) | (3 << 12)
| (tmp->wbd_gain_val << 9) | (0 << 8) | (1 << 7)
| (state->current_tune_table_index->wbdmux << 0));
state->wbd_gain_current = tmp->wbd_gain_val;
} else {
dib0070_write_reg(state, 0x0f,
(0 << 15) | (1 << 14) | (3 << 12)
| (6 << 9) | (0 << 8) | (1 << 7)
| (state->current_tune_table_index->wbdmux << 0));
state->wbd_gain_current = 6;
}
dib0070_write_reg(state, 0x06, 0x3fff);
dib0070_write_reg(state, 0x07,
(state->current_tune_table_index->switch_trim << 11) | (7 << 8) | (state->lna_match->lna_band << 3) | (3 << 0));
dib0070_write_reg(state, 0x08, (state->lna_match->lna_band << 10) | (3 << 7) | (127));
dib0070_write_reg(state, 0x0d, 0x0d80);
dib0070_write_reg(state, 0x18, 0x07ff);
dib0070_write_reg(state, 0x17, 0x0033);
*tune_state = CT_TUNER_STEP_5;
} else if (*tune_state == CT_TUNER_STEP_5) {
dib0070_set_bandwidth(fe);
*tune_state = CT_TUNER_STOP;
} else {
ret = FE_CALLBACK_TIME_NEVER;
}
return ret;
}
static int dib0070_tune(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
uint32_t ret;
state->tune_state = CT_TUNER_START;
do {
ret = dib0070_tune_digital(fe);
if (ret != FE_CALLBACK_TIME_NEVER)
msleep(ret/10);
else
break;
} while (state->tune_state != CT_TUNER_STOP);
return 0;
}
static int dib0070_wakeup(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
if (state->cfg->sleep)
state->cfg->sleep(fe, 0);
return 0;
}
static int dib0070_sleep(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
if (state->cfg->sleep)
state->cfg->sleep(fe, 1);
return 0;
}
u8 dib0070_get_rf_output(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
return (dib0070_read_reg(state, 0x07) >> 11) & 0x3;
}
int dib0070_set_rf_output(struct dvb_frontend *fe, u8 no)
{
struct dib0070_state *state = fe->tuner_priv;
u16 rxrf2 = dib0070_read_reg(state, 0x07) & 0xfe7ff;
if (no > 3)
no = 3;
if (no < 1)
no = 1;
return dib0070_write_reg(state, 0x07, rxrf2 | (no << 11));
}
static u16 dib0070_read_wbd_offset(struct dib0070_state *state, u8 gain)
{
u16 tuner_en = dib0070_read_reg(state, 0x20);
u16 offset;
dib0070_write_reg(state, 0x18, 0x07ff);
dib0070_write_reg(state, 0x20, 0x0800 | 0x4000 | 0x0040 | 0x0020 | 0x0010 | 0x0008 | 0x0002 | 0x0001);
dib0070_write_reg(state, 0x0f, (1 << 14) | (2 << 12) | (gain << 9) | (1 << 8) | (1 << 7) | (0 << 0));
msleep(9);
offset = dib0070_read_reg(state, 0x19);
dib0070_write_reg(state, 0x20, tuner_en);
return offset;
}
static void dib0070_wbd_offset_calibration(struct dib0070_state *state)
{
u8 gain;
for (gain = 6; gain < 8; gain++) {
state->wbd_offset_3_3[gain - 6] = ((dib0070_read_wbd_offset(state, gain) * 8 * 18 / 33 + 1) / 2);
dprintk("Gain: %d, WBDOffset (3.3V) = %hd", gain, state->wbd_offset_3_3[gain-6]);
}
}
u16 dib0070_wbd_offset(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
const struct dib0070_wbd_gain_cfg *tmp = state->cfg->wbd_gain;
u32 freq = fe->dtv_property_cache.frequency/1000;
if (tmp != NULL) {
while (freq/1000 > tmp->freq)
tmp++;
state->wbd_gain_current = tmp->wbd_gain_val;
} else
state->wbd_gain_current = 6;
return state->wbd_offset_3_3[state->wbd_gain_current - 6];
}
static int dib0070_reset(struct dvb_frontend *fe)
{
struct dib0070_state *state = fe->tuner_priv;
u16 l, r, *n;
HARD_RESET(state);
#ifndef FORCE_SBAND_TUNER
if ((dib0070_read_reg(state, 0x22) >> 9) & 0x1)
state->revision = (dib0070_read_reg(state, 0x1f) >> 8) & 0xff;
else
#else
#warning forcing SBAND
#endif
state->revision = DIB0070S_P1A;
dprintk("Revision: %x", state->revision);
if (state->revision == DIB0070_P1D) {
dprintk("Error: this driver is not to be used meant for P1D or earlier");
return -EINVAL;
}
n = (u16 *) dib0070_p1f_defaults;
l = pgm_read_word(n++);
while (l) {
r = pgm_read_word(n++);
do {
dib0070_write_reg(state, (u8)r, pgm_read_word(n++));
r++;
} while (--l);
l = pgm_read_word(n++);
}
if (state->cfg->force_crystal_mode != 0)
r = state->cfg->force_crystal_mode;
else if (state->cfg->clock_khz >= 24000)
r = 1;
else
r = 2;
r |= state->cfg->osc_buffer_state << 3;
dib0070_write_reg(state, 0x10, r);
dib0070_write_reg(state, 0x1f, (1 << 8) | ((state->cfg->clock_pad_drive & 0xf) << 5));
if (state->cfg->invert_iq) {
r = dib0070_read_reg(state, 0x02) & 0xffdf;
dib0070_write_reg(state, 0x02, r | (1 << 5));
}
if (state->revision == DIB0070S_P1A)
dib0070_set_ctrl_lo5(fe, 2, 4, 3, 0);
else
dib0070_set_ctrl_lo5(fe, 5, 4, state->cfg->charge_pump,
state->cfg->enable_third_order_filter);
dib0070_write_reg(state, 0x01, (54 << 9) | 0xc8);
dib0070_wbd_offset_calibration(state);
return 0;
}
static int dib0070_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct dib0070_state *state = fe->tuner_priv;
*frequency = 1000 * state->current_rf;
return 0;
}
static int dib0070_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
struct dvb_frontend *dib0070_attach(struct dvb_frontend *fe, struct i2c_adapter *i2c, struct dib0070_config *cfg)
{
struct dib0070_state *state = kzalloc(sizeof(struct dib0070_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->cfg = cfg;
state->i2c = i2c;
state->fe = fe;
mutex_init(&state->i2c_buffer_lock);
fe->tuner_priv = state;
if (dib0070_reset(fe) != 0)
goto free_mem;
printk(KERN_INFO "DiB0070: successfully identified\n");
memcpy(&fe->ops.tuner_ops, &dib0070_ops, sizeof(struct dvb_tuner_ops));
fe->tuner_priv = state;
return fe;
free_mem:
kfree(state);
fe->tuner_priv = NULL;
return NULL;
}
