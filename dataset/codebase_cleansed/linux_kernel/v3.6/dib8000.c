static u16 dib8000_i2c_read16(struct i2c_device *i2c, u16 reg)
{
u16 ret;
struct i2c_msg msg[2] = {
{.addr = i2c->addr >> 1, .flags = 0, .len = 2},
{.addr = i2c->addr >> 1, .flags = I2C_M_RD, .len = 2},
};
if (mutex_lock_interruptible(i2c->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return 0;
}
msg[0].buf = i2c->i2c_write_buffer;
msg[0].buf[0] = reg >> 8;
msg[0].buf[1] = reg & 0xff;
msg[1].buf = i2c->i2c_read_buffer;
if (i2c_transfer(i2c->adap, msg, 2) != 2)
dprintk("i2c read error on %d", reg);
ret = (msg[1].buf[0] << 8) | msg[1].buf[1];
mutex_unlock(i2c->i2c_buffer_lock);
return ret;
}
static u16 dib8000_read_word(struct dib8000_state *state, u16 reg)
{
u16 ret;
if (mutex_lock_interruptible(&state->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return 0;
}
state->i2c_write_buffer[0] = reg >> 8;
state->i2c_write_buffer[1] = reg & 0xff;
memset(state->msg, 0, 2 * sizeof(struct i2c_msg));
state->msg[0].addr = state->i2c.addr >> 1;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 2;
state->msg[1].addr = state->i2c.addr >> 1;
state->msg[1].flags = I2C_M_RD;
state->msg[1].buf = state->i2c_read_buffer;
state->msg[1].len = 2;
if (i2c_transfer(state->i2c.adap, state->msg, 2) != 2)
dprintk("i2c read error on %d", reg);
ret = (state->i2c_read_buffer[0] << 8) | state->i2c_read_buffer[1];
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static u32 dib8000_read32(struct dib8000_state *state, u16 reg)
{
u16 rw[2];
rw[0] = dib8000_read_word(state, reg + 0);
rw[1] = dib8000_read_word(state, reg + 1);
return ((rw[0] << 16) | (rw[1]));
}
static int dib8000_i2c_write16(struct i2c_device *i2c, u16 reg, u16 val)
{
struct i2c_msg msg = {.addr = i2c->addr >> 1, .flags = 0, .len = 4};
int ret = 0;
if (mutex_lock_interruptible(i2c->i2c_buffer_lock) < 0) {
dprintk("could not acquire lock");
return -EINVAL;
}
msg.buf = i2c->i2c_write_buffer;
msg.buf[0] = (reg >> 8) & 0xff;
msg.buf[1] = reg & 0xff;
msg.buf[2] = (val >> 8) & 0xff;
msg.buf[3] = val & 0xff;
ret = i2c_transfer(i2c->adap, &msg, 1) != 1 ? -EREMOTEIO : 0;
mutex_unlock(i2c->i2c_buffer_lock);
return ret;
}
static int dib8000_write_word(struct dib8000_state *state, u16 reg, u16 val)
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
state->msg[0].addr = state->i2c.addr >> 1;
state->msg[0].flags = 0;
state->msg[0].buf = state->i2c_write_buffer;
state->msg[0].len = 4;
ret = (i2c_transfer(state->i2c.adap, state->msg, 1) != 1 ?
-EREMOTEIO : 0);
mutex_unlock(&state->i2c_buffer_lock);
return ret;
}
static u16 fft_to_mode(struct dib8000_state *state)
{
u16 mode;
switch (state->fe[0]->dtv_property_cache.transmission_mode) {
case TRANSMISSION_MODE_2K:
mode = 1;
break;
case TRANSMISSION_MODE_4K:
mode = 2;
break;
default:
case TRANSMISSION_MODE_AUTO:
case TRANSMISSION_MODE_8K:
mode = 3;
break;
}
return mode;
}
static void dib8000_set_acquisition_mode(struct dib8000_state *state)
{
u16 nud = dib8000_read_word(state, 298);
nud |= (1 << 3) | (1 << 0);
dprintk("acquisition mode activated");
dib8000_write_word(state, 298, nud);
}
static int dib8000_set_output_mode(struct dvb_frontend *fe, int mode)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 outreg, fifo_threshold, smo_mode, sram = 0x0205;
outreg = 0;
fifo_threshold = 1792;
smo_mode = (dib8000_read_word(state, 299) & 0x0050) | (1 << 1);
dprintk("-I- Setting output mode for demod %p to %d",
&state->fe[0], mode);
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
if (state->cfg.hostbus_diversity) {
outreg = (1 << 10) | (4 << 6);
sram &= 0xfdff;
} else
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
case OUTMODE_ANALOG_ADC:
outreg = (1 << 10) | (3 << 6);
dib8000_set_acquisition_mode(state);
break;
default:
dprintk("Unhandled output_mode passed to be set for demod %p",
&state->fe[0]);
return -EINVAL;
}
if (state->cfg.output_mpeg2_in_188_bytes)
smo_mode |= (1 << 5);
dib8000_write_word(state, 299, smo_mode);
dib8000_write_word(state, 300, fifo_threshold);
dib8000_write_word(state, 1286, outreg);
dib8000_write_word(state, 1291, sram);
return 0;
}
static int dib8000_set_diversity_in(struct dvb_frontend *fe, int onoff)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 sync_wait = dib8000_read_word(state, 273) & 0xfff0;
if (!state->differential_constellation) {
dib8000_write_word(state, 272, 1 << 9);
dib8000_write_word(state, 273, sync_wait | (1 << 2) | 2);
} else {
dib8000_write_word(state, 272, 0);
dib8000_write_word(state, 273, sync_wait);
}
state->diversity_onoff = onoff;
switch (onoff) {
case 0:
dib8000_write_word(state, 270, 1);
dib8000_write_word(state, 271, 0);
break;
case 1:
dib8000_write_word(state, 270, 6);
dib8000_write_word(state, 271, 6);
break;
case 2:
dib8000_write_word(state, 270, 0);
dib8000_write_word(state, 271, 1);
break;
}
return 0;
}
static void dib8000_set_power_mode(struct dib8000_state *state, enum dib8000_power_mode mode)
{
u16 reg_774 = 0x3fff, reg_775 = 0xffff, reg_776 = 0xffff,
reg_900 = (dib8000_read_word(state, 900) & 0xfffc) | 0x3,
reg_1280;
if (state->revision != 0x8090)
reg_1280 = (dib8000_read_word(state, 1280) & 0x00ff) | 0xff00;
else
reg_1280 = (dib8000_read_word(state, 1280) & 0x707f) | 0x8f80;
switch (mode) {
case DIB8000_POWER_ALL:
reg_774 = 0x0000;
reg_775 = 0x0000;
reg_776 = 0x0000;
reg_900 &= 0xfffc;
if (state->revision != 0x8090)
reg_1280 &= 0x00ff;
else
reg_1280 &= 0x707f;
break;
case DIB8000_POWER_INTERFACE_ONLY:
if (state->revision != 0x8090)
reg_1280 &= 0x00ff;
else
reg_1280 &= 0xfa7b;
break;
}
dprintk("powermode : 774 : %x ; 775 : %x; 776 : %x ; 900 : %x; 1280 : %x", reg_774, reg_775, reg_776, reg_900, reg_1280);
dib8000_write_word(state, 774, reg_774);
dib8000_write_word(state, 775, reg_775);
dib8000_write_word(state, 776, reg_776);
dib8000_write_word(state, 900, reg_900);
dib8000_write_word(state, 1280, reg_1280);
}
static int dib8000_init_sdram(struct dib8000_state *state)
{
u16 reg = 0;
dprintk("Init sdram");
reg = dib8000_read_word(state, 274)&0xfff0;
dib8000_write_word(state, 274, reg | 0x7);
dib8000_write_word(state, 1803, (7<<2));
reg = dib8000_read_word(state, 1280);
dib8000_write_word(state, 1280, reg | (1<<2));
dib8000_write_word(state, 1280, reg);
return 0;
}
static int dib8000_set_adc_state(struct dib8000_state *state, enum dibx000_adc_states no)
{
int ret = 0;
u16 reg, reg_907 = dib8000_read_word(state, 907);
u16 reg_908 = dib8000_read_word(state, 908);
switch (no) {
case DIBX000_SLOW_ADC_ON:
if (state->revision != 0x8090) {
reg_908 |= (1 << 1) | (1 << 0);
ret |= dib8000_write_word(state, 908, reg_908);
reg_908 &= ~(1 << 1);
} else {
reg = dib8000_read_word(state, 1925);
dib8000_write_word(state, 1925, reg |
(1<<4) | (1<<2));
reg = dib8000_read_word(state, 1925);
msleep(20);
dib8000_write_word(state, 1925, reg & ~(1<<4));
reg = dib8000_read_word(state, 921) & ~((0x3 << 14)
| (0x3 << 12));
dib8000_write_word(state, 921, reg | (1 << 14)
| (3 << 12));
}
break;
case DIBX000_SLOW_ADC_OFF:
if (state->revision == 0x8090) {
reg = dib8000_read_word(state, 1925);
dib8000_write_word(state, 1925,
(reg & ~(1<<2)) | (1<<4));
}
reg_908 |= (1 << 1) | (1 << 0);
break;
case DIBX000_ADC_ON:
reg_907 &= 0x0fff;
reg_908 &= 0x0003;
break;
case DIBX000_ADC_OFF:
reg_907 |= (1 << 14) | (1 << 13) | (1 << 12);
reg_908 |= (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);
break;
case DIBX000_VBG_ENABLE:
reg_907 &= ~(1 << 15);
break;
case DIBX000_VBG_DISABLE:
reg_907 |= (1 << 15);
break;
default:
break;
}
ret |= dib8000_write_word(state, 907, reg_907);
ret |= dib8000_write_word(state, 908, reg_908);
return ret;
}
static int dib8000_set_bandwidth(struct dvb_frontend *fe, u32 bw)
{
struct dib8000_state *state = fe->demodulator_priv;
u32 timf;
if (bw == 0)
bw = 6000;
if (state->timf == 0) {
dprintk("using default timf");
timf = state->timf_default;
} else {
dprintk("using updated timf");
timf = state->timf;
}
dib8000_write_word(state, 29, (u16) ((timf >> 16) & 0xffff));
dib8000_write_word(state, 30, (u16) ((timf) & 0xffff));
return 0;
}
static int dib8000_sad_calib(struct dib8000_state *state)
{
if (state->revision == 0x8090) {
dprintk("%s: the sad calibration is not needed for the dib8096P",
__func__);
return 0;
}
dib8000_write_word(state, 923, (0 << 1) | (0 << 0));
dib8000_write_word(state, 924, 776);
dib8000_write_word(state, 923, (1 << 0));
dib8000_write_word(state, 923, (0 << 0));
msleep(1);
return 0;
}
int dib8000_set_wbd_ref(struct dvb_frontend *fe, u16 value)
{
struct dib8000_state *state = fe->demodulator_priv;
if (value > 4095)
value = 4095;
state->wbd_ref = value;
return dib8000_write_word(state, 106, value);
}
static void dib8000_reset_pll_common(struct dib8000_state *state, const struct dibx000_bandwidth_config *bw)
{
dprintk("ifreq: %d %x, inversion: %d", bw->ifreq, bw->ifreq, bw->ifreq >> 25);
if (state->revision != 0x8090) {
dib8000_write_word(state, 23,
(u16) (((bw->internal * 1000) >> 16) & 0xffff));
dib8000_write_word(state, 24,
(u16) ((bw->internal * 1000) & 0xffff));
} else {
dib8000_write_word(state, 23, (u16) (((bw->internal / 2 * 1000) >> 16) & 0xffff));
dib8000_write_word(state, 24,
(u16) ((bw->internal / 2 * 1000) & 0xffff));
}
dib8000_write_word(state, 27, (u16) ((bw->ifreq >> 16) & 0x01ff));
dib8000_write_word(state, 28, (u16) (bw->ifreq & 0xffff));
dib8000_write_word(state, 26, (u16) ((bw->ifreq >> 25) & 0x0003));
if (state->revision != 0x8090)
dib8000_write_word(state, 922, bw->sad_cfg);
}
static void dib8000_reset_pll(struct dib8000_state *state)
{
const struct dibx000_bandwidth_config *pll = state->cfg.pll;
u16 clk_cfg1, reg;
if (state->revision != 0x8090) {
dib8000_write_word(state, 901,
(pll->pll_prediv << 8) | (pll->pll_ratio << 0));
clk_cfg1 = (1 << 10) | (0 << 9) | (pll->IO_CLK_en_core << 8) |
(pll->bypclk_div << 5) | (pll->enable_refdiv << 4) |
(1 << 3) | (pll->pll_range << 1) |
(pll->pll_reset << 0);
dib8000_write_word(state, 902, clk_cfg1);
clk_cfg1 = (clk_cfg1 & 0xfff7) | (pll->pll_bypass << 3);
dib8000_write_word(state, 902, clk_cfg1);
dprintk("clk_cfg1: 0x%04x", clk_cfg1);
if (state->cfg.pll->ADClkSrc == 0)
dib8000_write_word(state, 904,
(0 << 15) | (0 << 12) | (0 << 10) |
(pll->modulo << 8) |
(pll->ADClkSrc << 7) | (0 << 1));
else if (state->cfg.refclksel != 0)
dib8000_write_word(state, 904, (0 << 15) | (1 << 12) |
((state->cfg.refclksel & 0x3) << 10) |
(pll->modulo << 8) |
(pll->ADClkSrc << 7) | (0 << 1));
else
dib8000_write_word(state, 904, (0 << 15) | (1 << 12) |
(3 << 10) | (pll->modulo << 8) |
(pll->ADClkSrc << 7) | (0 << 1));
} else {
dib8000_write_word(state, 1856, (!pll->pll_reset<<13) |
(pll->pll_range<<12) | (pll->pll_ratio<<6) |
(pll->pll_prediv));
reg = dib8000_read_word(state, 1857);
dib8000_write_word(state, 1857, reg|(!pll->pll_bypass<<15));
reg = dib8000_read_word(state, 1858);
dib8000_write_word(state, 1858, reg | 1);
dib8000_write_word(state, 904, (pll->modulo << 8));
}
dib8000_reset_pll_common(state, pll);
}
int dib8000_update_pll(struct dvb_frontend *fe,
struct dibx000_bandwidth_config *pll)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 reg_1857, reg_1856 = dib8000_read_word(state, 1856);
u8 loopdiv, prediv;
u32 internal, xtal;
prediv = reg_1856 & 0x3f;
loopdiv = (reg_1856 >> 6) & 0x3f;
if ((pll != NULL) && (pll->pll_prediv != prediv ||
pll->pll_ratio != loopdiv)) {
dprintk("Updating pll (prediv: old = %d new = %d ; loopdiv : old = %d new = %d)", prediv, pll->pll_prediv, loopdiv, pll->pll_ratio);
reg_1856 &= 0xf000;
reg_1857 = dib8000_read_word(state, 1857);
dib8000_write_word(state, 1857, reg_1857 & ~(1 << 15));
dib8000_write_word(state, 1856, reg_1856 |
((pll->pll_ratio & 0x3f) << 6) |
(pll->pll_prediv & 0x3f));
internal = dib8000_read32(state, 23) / 1000;
dprintk("Old Internal = %d", internal);
xtal = 2 * (internal / loopdiv) * prediv;
internal = 1000 * (xtal/pll->pll_prediv) * pll->pll_ratio;
dprintk("Xtal = %d , New Fmem = %d New Fdemod = %d, New Fsampling = %d", xtal, internal/1000, internal/2000, internal/8000);
dprintk("New Internal = %d", internal);
dib8000_write_word(state, 23,
(u16) (((internal / 2) >> 16) & 0xffff));
dib8000_write_word(state, 24, (u16) ((internal / 2) & 0xffff));
dib8000_write_word(state, 1857, reg_1857 | (1 << 15));
while (((dib8000_read_word(state, 1856)>>15)&0x1) != 1)
dprintk("Waiting for PLL to lock");
reg_1856 = dib8000_read_word(state, 1856);
dprintk("PLL Updated with prediv = %d and loopdiv = %d",
reg_1856&0x3f, (reg_1856>>6)&0x3f);
return 0;
}
return -EINVAL;
}
static int dib8000_reset_gpio(struct dib8000_state *st)
{
dib8000_write_word(st, 1029, st->cfg.gpio_dir);
dib8000_write_word(st, 1030, st->cfg.gpio_val);
dib8000_write_word(st, 1032, st->cfg.gpio_pwm_pos);
dib8000_write_word(st, 1037, st->cfg.pwm_freq_div);
return 0;
}
static int dib8000_cfg_gpio(struct dib8000_state *st, u8 num, u8 dir, u8 val)
{
st->cfg.gpio_dir = dib8000_read_word(st, 1029);
st->cfg.gpio_dir &= ~(1 << num);
st->cfg.gpio_dir |= (dir & 0x1) << num;
dib8000_write_word(st, 1029, st->cfg.gpio_dir);
st->cfg.gpio_val = dib8000_read_word(st, 1030);
st->cfg.gpio_val &= ~(1 << num);
st->cfg.gpio_val |= (val & 0x01) << num;
dib8000_write_word(st, 1030, st->cfg.gpio_val);
dprintk("gpio dir: %x: gpio val: %x", st->cfg.gpio_dir, st->cfg.gpio_val);
return 0;
}
int dib8000_set_gpio(struct dvb_frontend *fe, u8 num, u8 dir, u8 val)
{
struct dib8000_state *state = fe->demodulator_priv;
return dib8000_cfg_gpio(state, num, dir, val);
}
static u16 dib8000_identify(struct i2c_device *client)
{
u16 value;
value = dib8000_i2c_read16(client, 896);
if ((value = dib8000_i2c_read16(client, 896)) != 0x01b3) {
dprintk("wrong Vendor ID (read=0x%x)", value);
return 0;
}
value = dib8000_i2c_read16(client, 897);
if (value != 0x8000 && value != 0x8001 &&
value != 0x8002 && value != 0x8090) {
dprintk("wrong Device ID (%x)", value);
return 0;
}
switch (value) {
case 0x8000:
dprintk("found DiB8000A");
break;
case 0x8001:
dprintk("found DiB8000B");
break;
case 0x8002:
dprintk("found DiB8000C");
break;
case 0x8090:
dprintk("found DiB8096P");
break;
}
return value;
}
static int dib8000_reset(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
if ((state->revision = dib8000_identify(&state->i2c)) == 0)
return -EINVAL;
if (state->revision != 0x8090)
dib8000_write_word(state, 1287, 0x0003);
if (state->revision == 0x8000)
dprintk("error : dib8000 MA not supported");
dibx000_reset_i2c_master(&state->i2c_master);
dib8000_set_power_mode(state, DIB8000_POWER_ALL);
dib8000_set_adc_state(state, DIBX000_VBG_ENABLE);
dib8000_write_word(state, 770, 0xffff);
dib8000_write_word(state, 771, 0xffff);
dib8000_write_word(state, 772, 0xfffc);
if (state->revision == 0x8090)
dib8000_write_word(state, 1280, 0x0045);
else
dib8000_write_word(state, 1280, 0x004d);
dib8000_write_word(state, 1281, 0x000c);
dib8000_write_word(state, 770, 0x0000);
dib8000_write_word(state, 771, 0x0000);
dib8000_write_word(state, 772, 0x0000);
dib8000_write_word(state, 898, 0x0004);
dib8000_write_word(state, 1280, 0x0000);
dib8000_write_word(state, 1281, 0x0000);
if (state->revision != 0x8090) {
if (state->cfg.drives)
dib8000_write_word(state, 906, state->cfg.drives);
else {
dprintk("using standard PAD-drive-settings, please adjust settings in config-struct to be optimal.");
dib8000_write_word(state, 906, 0x2d98);
}
}
dib8000_reset_pll(state);
if (state->revision != 0x8090)
dib8000_write_word(state, 898, 0x0004);
if (dib8000_reset_gpio(state) != 0)
dprintk("GPIO reset was not successful.");
if ((state->revision != 0x8090) &&
(dib8000_set_output_mode(fe, OUTMODE_HIGH_Z) != 0))
dprintk("OUTPUT_MODE could not be resetted.");
state->current_agc = NULL;
if (state->cfg.pll->ifreq == 0)
dib8000_write_word(state, 40, 0x0755);
else
dib8000_write_word(state, 40, 0x1f55);
{
u16 l = 0, r;
const u16 *n;
n = dib8000_defaults;
l = *n++;
while (l) {
r = *n++;
do {
dib8000_write_word(state, r, *n++);
r++;
} while (--l);
l = *n++;
}
}
if (state->revision != 0x8090)
dib8000_write_word(state, 903, (0 << 4) | 2);
state->isdbt_cfg_loaded = 0;
if (state->cfg.div_cfg != 0)
dib8000_write_word(state, 903, state->cfg.div_cfg);
dib8000_write_word(state, 1285, dib8000_read_word(state, 1285) & ~(1 << 1));
dib8000_set_bandwidth(fe, 6000);
dib8000_set_adc_state(state, DIBX000_SLOW_ADC_ON);
if (state->revision != 0x8090) {
dib8000_sad_calib(state);
dib8000_set_adc_state(state, DIBX000_SLOW_ADC_OFF);
}
dib8000_set_power_mode(state, DIB8000_POWER_INTERFACE_ONLY);
return 0;
}
static void dib8000_restart_agc(struct dib8000_state *state)
{
dib8000_write_word(state, 770, 0x0a00);
dib8000_write_word(state, 770, 0x0000);
}
static int dib8000_update_lna(struct dib8000_state *state)
{
u16 dyn_gain;
if (state->cfg.update_lna) {
dyn_gain = dib8000_read_word(state, 390);
if (state->cfg.update_lna(state->fe[0], dyn_gain)) {
dib8000_restart_agc(state);
return 1;
}
}
return 0;
}
static int dib8000_set_agc_config(struct dib8000_state *state, u8 band)
{
struct dibx000_agc_config *agc = NULL;
int i;
u16 reg;
if (state->current_band == band && state->current_agc != NULL)
return 0;
state->current_band = band;
for (i = 0; i < state->cfg.agc_config_count; i++)
if (state->cfg.agc[i].band_caps & band) {
agc = &state->cfg.agc[i];
break;
}
if (agc == NULL) {
dprintk("no valid AGC configuration found for band 0x%02x", band);
return -EINVAL;
}
state->current_agc = agc;
dib8000_write_word(state, 76, agc->setup);
dib8000_write_word(state, 77, agc->inv_gain);
dib8000_write_word(state, 78, agc->time_stabiliz);
dib8000_write_word(state, 101, (agc->alpha_level << 12) | agc->thlock);
dib8000_write_word(state, 102, (agc->alpha_mant << 5) | agc->alpha_exp);
dib8000_write_word(state, 103, (agc->beta_mant << 6) | agc->beta_exp);
dprintk("WBD: ref: %d, sel: %d, active: %d, alpha: %d",
state->wbd_ref != 0 ? state->wbd_ref : agc->wbd_ref, agc->wbd_sel, !agc->perform_agc_softsplit, agc->wbd_sel);
if (state->wbd_ref != 0)
dib8000_write_word(state, 106, state->wbd_ref);
else
dib8000_write_word(state, 106, agc->wbd_ref);
if (state->revision == 0x8090) {
reg = dib8000_read_word(state, 922) & (0x3 << 2);
dib8000_write_word(state, 922, reg | (agc->wbd_sel << 2));
}
dib8000_write_word(state, 107, (agc->wbd_alpha << 9) | (agc->perform_agc_softsplit << 8));
dib8000_write_word(state, 108, agc->agc1_max);
dib8000_write_word(state, 109, agc->agc1_min);
dib8000_write_word(state, 110, agc->agc2_max);
dib8000_write_word(state, 111, agc->agc2_min);
dib8000_write_word(state, 112, (agc->agc1_pt1 << 8) | agc->agc1_pt2);
dib8000_write_word(state, 113, (agc->agc1_slope1 << 8) | agc->agc1_slope2);
dib8000_write_word(state, 114, (agc->agc2_pt1 << 8) | agc->agc2_pt2);
dib8000_write_word(state, 115, (agc->agc2_slope1 << 8) | agc->agc2_slope2);
dib8000_write_word(state, 75, agc->agc1_pt3);
if (state->revision != 0x8090)
dib8000_write_word(state, 923,
(dib8000_read_word(state, 923) & 0xffe3) |
(agc->wbd_inv << 4) | (agc->wbd_sel << 2));
return 0;
}
void dib8000_pwm_agc_reset(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
dib8000_set_adc_state(state, DIBX000_ADC_ON);
dib8000_set_agc_config(state, (unsigned char)(BAND_OF_FREQUENCY(fe->dtv_property_cache.frequency / 1000)));
}
static int dib8000_agc_soft_split(struct dib8000_state *state)
{
u16 agc, split_offset;
if (!state->current_agc || !state->current_agc->perform_agc_softsplit || state->current_agc->split.max == 0)
return FE_CALLBACK_TIME_NEVER;
agc = dib8000_read_word(state, 390);
if (agc > state->current_agc->split.min_thres)
split_offset = state->current_agc->split.min;
else if (agc < state->current_agc->split.max_thres)
split_offset = state->current_agc->split.max;
else
split_offset = state->current_agc->split.max *
(agc - state->current_agc->split.min_thres) /
(state->current_agc->split.max_thres - state->current_agc->split.min_thres);
dprintk("AGC split_offset: %d", split_offset);
dib8000_write_word(state, 107, (dib8000_read_word(state, 107) & 0xff00) | split_offset);
return 5000;
}
static int dib8000_agc_startup(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
enum frontend_tune_state *tune_state = &state->tune_state;
int ret = 0;
u16 reg, upd_demod_gain_period = 0x8000;
switch (*tune_state) {
case CT_AGC_START:
if (state->revision != 0x8090)
dib8000_set_adc_state(state, DIBX000_ADC_ON);
else {
dib8000_set_power_mode(state, DIB8000_POWER_ALL);
reg = dib8000_read_word(state, 1947)&0xff00;
dib8000_write_word(state, 1946,
upd_demod_gain_period & 0xFFFF);
dib8000_write_word(state, 1947, reg | (1<<14) |
((upd_demod_gain_period >> 16) & 0xFF));
reg = dib8000_read_word(state, 1920);
dib8000_write_word(state, 1920, (reg | 0x3) &
(~(1 << 7)));
}
if (dib8000_set_agc_config(state, (unsigned char)(BAND_OF_FREQUENCY(fe->dtv_property_cache.frequency / 1000))) != 0) {
*tune_state = CT_AGC_STOP;
state->status = FE_STATUS_TUNE_FAILED;
break;
}
ret = 70;
*tune_state = CT_AGC_STEP_0;
break;
case CT_AGC_STEP_0:
if (state->cfg.agc_control)
state->cfg.agc_control(fe, 1);
dib8000_restart_agc(state);
ret = 50;
*tune_state = CT_AGC_STEP_1;
break;
case CT_AGC_STEP_1:
ret = 70;
if (dib8000_update_lna(state))
ret = 50;
else
*tune_state = CT_AGC_STEP_2;
break;
case CT_AGC_STEP_2:
dib8000_agc_soft_split(state);
if (state->cfg.agc_control)
state->cfg.agc_control(fe, 0);
*tune_state = CT_AGC_STOP;
break;
default:
ret = dib8000_agc_soft_split(state);
break;
}
return ret;
}
static void dib8096p_host_bus_drive(struct dib8000_state *state, u8 drive)
{
u16 reg;
drive &= 0x7;
reg = dib8000_read_word(state, 1798) &
~(0x7 | (0x7 << 6) | (0x7 << 12));
reg |= (drive<<12) | (drive<<6) | drive;
dib8000_write_word(state, 1798, reg);
reg = dib8000_read_word(state, 1799) & ~((0x7 << 2) | (0x7 << 8));
reg |= (drive<<8) | (drive<<2);
dib8000_write_word(state, 1799, reg);
reg = dib8000_read_word(state, 1800) &
~(0x7 | (0x7 << 6) | (0x7 << 12));
reg |= (drive<<12) | (drive<<6) | drive;
dib8000_write_word(state, 1800, reg);
reg = dib8000_read_word(state, 1801) & ~((0x7 << 2) | (0x7 << 8));
reg |= (drive<<8) | (drive<<2);
dib8000_write_word(state, 1801, reg);
reg = dib8000_read_word(state, 1802) &
~(0x7 | (0x7 << 6) | (0x7 << 12));
reg |= (drive<<12) | (drive<<6) | drive;
dib8000_write_word(state, 1802, reg);
}
static u32 dib8096p_calcSyncFreq(u32 P_Kin, u32 P_Kout,
u32 insertExtSynchro, u32 syncSize)
{
u32 quantif = 3;
u32 nom = (insertExtSynchro * P_Kin+syncSize);
u32 denom = P_Kout;
u32 syncFreq = ((nom << quantif) / denom);
if ((syncFreq & ((1 << quantif) - 1)) != 0)
syncFreq = (syncFreq >> quantif) + 1;
else
syncFreq = (syncFreq >> quantif);
if (syncFreq != 0)
syncFreq = syncFreq - 1;
return syncFreq;
}
static void dib8096p_cfg_DibTx(struct dib8000_state *state, u32 P_Kin,
u32 P_Kout, u32 insertExtSynchro, u32 synchroMode,
u32 syncWord, u32 syncSize)
{
dprintk("Configure DibStream Tx");
dib8000_write_word(state, 1615, 1);
dib8000_write_word(state, 1603, P_Kin);
dib8000_write_word(state, 1605, P_Kout);
dib8000_write_word(state, 1606, insertExtSynchro);
dib8000_write_word(state, 1608, synchroMode);
dib8000_write_word(state, 1609, (syncWord >> 16) & 0xffff);
dib8000_write_word(state, 1610, syncWord & 0xffff);
dib8000_write_word(state, 1612, syncSize);
dib8000_write_word(state, 1615, 0);
}
static void dib8096p_cfg_DibRx(struct dib8000_state *state, u32 P_Kin,
u32 P_Kout, u32 synchroMode, u32 insertExtSynchro,
u32 syncWord, u32 syncSize, u32 dataOutRate)
{
u32 syncFreq;
dprintk("Configure DibStream Rx synchroMode = %d", synchroMode);
if ((P_Kin != 0) && (P_Kout != 0)) {
syncFreq = dib8096p_calcSyncFreq(P_Kin, P_Kout,
insertExtSynchro, syncSize);
dib8000_write_word(state, 1542, syncFreq);
}
dib8000_write_word(state, 1554, 1);
dib8000_write_word(state, 1536, P_Kin);
dib8000_write_word(state, 1537, P_Kout);
dib8000_write_word(state, 1539, synchroMode);
dib8000_write_word(state, 1540, (syncWord >> 16) & 0xffff);
dib8000_write_word(state, 1541, syncWord & 0xffff);
dib8000_write_word(state, 1543, syncSize);
dib8000_write_word(state, 1544, dataOutRate);
dib8000_write_word(state, 1554, 0);
}
static void dib8096p_enMpegMux(struct dib8000_state *state, int onoff)
{
u16 reg_1287;
reg_1287 = dib8000_read_word(state, 1287);
switch (onoff) {
case 1:
reg_1287 &= ~(1 << 8);
break;
case 0:
reg_1287 |= (1 << 8);
break;
}
dib8000_write_word(state, 1287, reg_1287);
}
static void dib8096p_configMpegMux(struct dib8000_state *state,
u16 pulseWidth, u16 enSerialMode, u16 enSerialClkDiv2)
{
u16 reg_1287;
dprintk("Enable Mpeg mux");
dib8096p_enMpegMux(state, 0);
if ((enSerialMode == 1) && (state->input_mode_mpeg == 1))
enSerialClkDiv2 = 0;
reg_1287 = ((pulseWidth & 0x1f) << 3) |
((enSerialMode & 0x1) << 2) | (enSerialClkDiv2 & 0x1);
dib8000_write_word(state, 1287, reg_1287);
dib8096p_enMpegMux(state, 1);
}
static void dib8096p_setDibTxMux(struct dib8000_state *state, int mode)
{
u16 reg_1288 = dib8000_read_word(state, 1288) & ~(0x7 << 7);
switch (mode) {
case MPEG_ON_DIBTX:
dprintk("SET MPEG ON DIBSTREAM TX");
dib8096p_cfg_DibTx(state, 8, 5, 0, 0, 0, 0);
reg_1288 |= (1 << 9); break;
case DIV_ON_DIBTX:
dprintk("SET DIV_OUT ON DIBSTREAM TX");
dib8096p_cfg_DibTx(state, 5, 5, 0, 0, 0, 0);
reg_1288 |= (1 << 8); break;
case ADC_ON_DIBTX:
dprintk("SET ADC_OUT ON DIBSTREAM TX");
dib8096p_cfg_DibTx(state, 20, 5, 10, 0, 0, 0);
reg_1288 |= (1 << 7); break;
default:
break;
}
dib8000_write_word(state, 1288, reg_1288);
}
static void dib8096p_setHostBusMux(struct dib8000_state *state, int mode)
{
u16 reg_1288 = dib8000_read_word(state, 1288) & ~(0x7 << 4);
switch (mode) {
case DEMOUT_ON_HOSTBUS:
dprintk("SET DEM OUT OLD INTERF ON HOST BUS");
dib8096p_enMpegMux(state, 0);
reg_1288 |= (1 << 6);
break;
case DIBTX_ON_HOSTBUS:
dprintk("SET DIBSTREAM TX ON HOST BUS");
dib8096p_enMpegMux(state, 0);
reg_1288 |= (1 << 5);
break;
case MPEG_ON_HOSTBUS:
dprintk("SET MPEG MUX ON HOST BUS");
reg_1288 |= (1 << 4);
break;
default:
break;
}
dib8000_write_word(state, 1288, reg_1288);
}
static int dib8096p_set_diversity_in(struct dvb_frontend *fe, int onoff)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 reg_1287;
switch (onoff) {
case 0:
dprintk("%s mode OFF : by default Enable Mpeg INPUT",
__func__);
dib8096p_cfg_DibRx(state, 8, 5, 0, 0, 0, 8, 0);
reg_1287 = dib8000_read_word(state, 1287);
if ((reg_1287 & 0x1) == 1) {
reg_1287 &= ~0x1;
dib8000_write_word(state, 1287, reg_1287);
}
state->input_mode_mpeg = 1;
break;
case 1:
case 2:
dprintk("%s ON : Enable diversity INPUT", __func__);
dib8096p_cfg_DibRx(state, 5, 5, 0, 0, 0, 0, 0);
state->input_mode_mpeg = 0;
break;
}
dib8000_set_diversity_in(state->fe[0], onoff);
return 0;
}
static int dib8096p_set_output_mode(struct dvb_frontend *fe, int mode)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 outreg, smo_mode, fifo_threshold;
u8 prefer_mpeg_mux_use = 1;
int ret = 0;
dib8096p_host_bus_drive(state, 1);
fifo_threshold = 1792;
smo_mode = (dib8000_read_word(state, 299) & 0x0050) | (1 << 1);
outreg = dib8000_read_word(state, 1286) &
~((1 << 10) | (0x7 << 6) | (1 << 1));
switch (mode) {
case OUTMODE_HIGH_Z:
outreg = 0;
break;
case OUTMODE_MPEG2_SERIAL:
if (prefer_mpeg_mux_use) {
dprintk("dib8096P setting output mode TS_SERIAL using Mpeg Mux");
dib8096p_configMpegMux(state, 3, 1, 1);
dib8096p_setHostBusMux(state, MPEG_ON_HOSTBUS);
} else {
dprintk("dib8096P setting output mode TS_SERIAL using Smooth bloc");
dib8096p_setHostBusMux(state,
DEMOUT_ON_HOSTBUS);
outreg |= (2 << 6) | (0 << 1);
}
break;
case OUTMODE_MPEG2_PAR_GATED_CLK:
if (prefer_mpeg_mux_use) {
dprintk("dib8096P setting output mode TS_PARALLEL_GATED using Mpeg Mux");
dib8096p_configMpegMux(state, 2, 0, 0);
dib8096p_setHostBusMux(state, MPEG_ON_HOSTBUS);
} else {
dprintk("dib8096P setting output mode TS_PARALLEL_GATED using Smooth block");
dib8096p_setHostBusMux(state,
DEMOUT_ON_HOSTBUS);
outreg |= (0 << 6);
}
break;
case OUTMODE_MPEG2_PAR_CONT_CLK:
dprintk("dib8096P setting output mode TS_PARALLEL_CONT using Smooth block");
dib8096p_setHostBusMux(state, DEMOUT_ON_HOSTBUS);
outreg |= (1 << 6);
break;
case OUTMODE_MPEG2_FIFO:
dprintk("dib8096P setting output mode TS_FIFO using Smooth block");
dib8096p_setHostBusMux(state, DEMOUT_ON_HOSTBUS);
outreg |= (5 << 6);
smo_mode |= (3 << 1);
fifo_threshold = 512;
break;
case OUTMODE_DIVERSITY:
dprintk("dib8096P setting output mode MODE_DIVERSITY");
dib8096p_setDibTxMux(state, DIV_ON_DIBTX);
dib8096p_setHostBusMux(state, DIBTX_ON_HOSTBUS);
break;
case OUTMODE_ANALOG_ADC:
dprintk("dib8096P setting output mode MODE_ANALOG_ADC");
dib8096p_setDibTxMux(state, ADC_ON_DIBTX);
dib8096p_setHostBusMux(state, DIBTX_ON_HOSTBUS);
break;
}
if (mode != OUTMODE_HIGH_Z)
outreg |= (1<<10);
dprintk("output_mpeg2_in_188_bytes = %d",
state->cfg.output_mpeg2_in_188_bytes);
if (state->cfg.output_mpeg2_in_188_bytes)
smo_mode |= (1 << 5);
ret |= dib8000_write_word(state, 299, smo_mode);
ret |= dib8000_write_word(state, 299 + 1, fifo_threshold);
ret |= dib8000_write_word(state, 1286, outreg);
return ret;
}
static int map_addr_to_serpar_number(struct i2c_msg *msg)
{
if (msg->buf[0] <= 15)
msg->buf[0] -= 1;
else if (msg->buf[0] == 17)
msg->buf[0] = 15;
else if (msg->buf[0] == 16)
msg->buf[0] = 17;
else if (msg->buf[0] == 19)
msg->buf[0] = 16;
else if (msg->buf[0] >= 21 && msg->buf[0] <= 25)
msg->buf[0] -= 3;
else if (msg->buf[0] == 28)
msg->buf[0] = 23;
else if (msg->buf[0] == 99)
msg->buf[0] = 99;
else
return -EINVAL;
return 0;
}
static int dib8096p_tuner_write_serpar(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
struct dib8000_state *state = i2c_get_adapdata(i2c_adap);
u8 n_overflow = 1;
u16 i = 1000;
u16 serpar_num = msg[0].buf[0];
while (n_overflow == 1 && i) {
n_overflow = (dib8000_read_word(state, 1984) >> 1) & 0x1;
i--;
if (i == 0)
dprintk("Tuner ITF: write busy (overflow)");
}
dib8000_write_word(state, 1985, (1 << 6) | (serpar_num & 0x3f));
dib8000_write_word(state, 1986, (msg[0].buf[1] << 8) | msg[0].buf[2]);
return num;
}
static int dib8096p_tuner_read_serpar(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
struct dib8000_state *state = i2c_get_adapdata(i2c_adap);
u8 n_overflow = 1, n_empty = 1;
u16 i = 1000;
u16 serpar_num = msg[0].buf[0];
u16 read_word;
while (n_overflow == 1 && i) {
n_overflow = (dib8000_read_word(state, 1984) >> 1) & 0x1;
i--;
if (i == 0)
dprintk("TunerITF: read busy (overflow)");
}
dib8000_write_word(state, 1985, (0<<6) | (serpar_num&0x3f));
i = 1000;
while (n_empty == 1 && i) {
n_empty = dib8000_read_word(state, 1984)&0x1;
i--;
if (i == 0)
dprintk("TunerITF: read busy (empty)");
}
read_word = dib8000_read_word(state, 1987);
msg[1].buf[0] = (read_word >> 8) & 0xff;
msg[1].buf[1] = (read_word) & 0xff;
return num;
}
static int dib8096p_tuner_rw_serpar(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
if (map_addr_to_serpar_number(&msg[0]) == 0) {
if (num == 1)
return dib8096p_tuner_write_serpar(i2c_adap, msg, 1);
else
return dib8096p_tuner_read_serpar(i2c_adap, msg, 2);
}
return num;
}
static int dib8096p_rw_on_apb(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num, u16 apb_address)
{
struct dib8000_state *state = i2c_get_adapdata(i2c_adap);
u16 word;
if (num == 1) {
dib8000_write_word(state, apb_address,
((msg[0].buf[1] << 8) | (msg[0].buf[2])));
} else {
word = dib8000_read_word(state, apb_address);
msg[1].buf[0] = (word >> 8) & 0xff;
msg[1].buf[1] = (word) & 0xff;
}
return num;
}
static int dib8096p_tuner_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg msg[], int num)
{
struct dib8000_state *state = i2c_get_adapdata(i2c_adap);
u16 apb_address = 0, word;
int i = 0;
switch (msg[0].buf[0]) {
case 0x12:
apb_address = 1920;
break;
case 0x14:
apb_address = 1921;
break;
case 0x24:
apb_address = 1922;
break;
case 0x1a:
apb_address = 1923;
break;
case 0x22:
apb_address = 1924;
break;
case 0x33:
apb_address = 1926;
break;
case 0x34:
apb_address = 1927;
break;
case 0x35:
apb_address = 1928;
break;
case 0x36:
apb_address = 1929;
break;
case 0x37:
apb_address = 1930;
break;
case 0x38:
apb_address = 1931;
break;
case 0x39:
apb_address = 1932;
break;
case 0x2a:
apb_address = 1935;
break;
case 0x2b:
apb_address = 1936;
break;
case 0x2c:
apb_address = 1937;
break;
case 0x2d:
apb_address = 1938;
break;
case 0x2e:
apb_address = 1939;
break;
case 0x2f:
apb_address = 1940;
break;
case 0x30:
apb_address = 1941;
break;
case 0x31:
apb_address = 1942;
break;
case 0x32:
apb_address = 1943;
break;
case 0x3e:
apb_address = 1944;
break;
case 0x3f:
apb_address = 1945;
break;
case 0x40:
apb_address = 1948;
break;
case 0x25:
apb_address = 936;
break;
case 0x26:
apb_address = 937;
break;
case 0x27:
apb_address = 938;
break;
case 0x28:
apb_address = 939;
break;
case 0x1d:
i = ((dib8000_read_word(state, 921) >> 12)&0x3);
word = dib8000_read_word(state, 924+i);
msg[1].buf[0] = (word >> 8) & 0xff;
msg[1].buf[1] = (word) & 0xff;
return num;
case 0x1f:
if (num == 1) {
word = (u16) ((msg[0].buf[1] << 8) |
msg[0].buf[2]);
word &= 0x3;
word = (dib8000_read_word(state, 921) &
~(3<<12)) | (word<<12);
dib8000_write_word(state, 921, word);
return num;
}
}
if (apb_address != 0)
return dib8096p_rw_on_apb(i2c_adap, msg, num, apb_address);
else
return dib8096p_tuner_rw_serpar(i2c_adap, msg, num);
return 0;
}
static u32 dib8096p_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
struct i2c_adapter *dib8096p_get_i2c_tuner(struct dvb_frontend *fe)
{
struct dib8000_state *st = fe->demodulator_priv;
return &st->dib8096p_tuner_adap;
}
int dib8096p_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 en_cur_state;
dprintk("sleep dib8096p: %d", onoff);
en_cur_state = dib8000_read_word(state, 1922);
if (en_cur_state > 0xff)
state->tuner_enable = en_cur_state ;
if (onoff)
en_cur_state &= 0x00ff;
else {
if (state->tuner_enable != 0)
en_cur_state = state->tuner_enable;
}
dib8000_write_word(state, 1922, en_cur_state);
return 0;
}
s32 dib8000_get_adc_power(struct dvb_frontend *fe, u8 mode)
{
struct dib8000_state *state = fe->demodulator_priv;
u32 ix = 0, tmp_val = 0, exp = 0, mant = 0;
s32 val;
val = dib8000_read32(state, 384);
if (mode) {
tmp_val = val;
while (tmp_val >>= 1)
exp++;
mant = (val * 1000 / (1<<exp));
ix = (u8)((mant-1000)/100);
val = (lut_1000ln_mant[ix] + 693*(exp-20) - 6908);
val = (val*256)/1000;
}
return val;
}
int dib8090p_get_dc_power(struct dvb_frontend *fe, u8 IQ)
{
struct dib8000_state *state = fe->demodulator_priv;
int val = 0;
switch (IQ) {
case 1:
val = dib8000_read_word(state, 403);
break;
case 0:
val = dib8000_read_word(state, 404);
break;
}
if (val & 0x200)
val -= 1024;
return val;
}
static void dib8000_update_timf(struct dib8000_state *state)
{
u32 timf = state->timf = dib8000_read32(state, 435);
dib8000_write_word(state, 29, (u16) (timf >> 16));
dib8000_write_word(state, 30, (u16) (timf & 0xffff));
dprintk("Updated timing frequency: %d (default: %d)", state->timf, state->timf_default);
}
u32 dib8000_ctrl_timf(struct dvb_frontend *fe, uint8_t op, uint32_t timf)
{
struct dib8000_state *state = fe->demodulator_priv;
switch (op) {
case DEMOD_TIMF_SET:
state->timf = timf;
break;
case DEMOD_TIMF_UPDATE:
dib8000_update_timf(state);
break;
case DEMOD_TIMF_GET:
break;
}
dib8000_set_bandwidth(state->fe[0], 6000);
return state->timf;
}
static void dib8000_set_channel(struct dib8000_state *state, u8 seq, u8 autosearching)
{
u16 mode, max_constellation, seg_diff_mask = 0, nbseg_diff = 0;
u8 guard, crate, constellation, timeI;
u16 i, coeff[4], P_cfr_left_edge = 0, P_cfr_right_edge = 0, seg_mask13 = 0x1fff;
const s16 *ncoeff = NULL, *ana_fe;
u16 tmcc_pow = 0;
u16 coff_pow = 0x2800;
u16 init_prbs = 0xfff;
u16 ana_gain = 0;
if (state->revision == 0x8090)
dib8000_init_sdram(state);
if (state->ber_monitored_layer != LAYER_ALL)
dib8000_write_word(state, 285, (dib8000_read_word(state, 285) & 0x60) | state->ber_monitored_layer);
else
dib8000_write_word(state, 285, dib8000_read_word(state, 285) & 0x60);
i = dib8000_read_word(state, 26) & 1;
dib8000_write_word(state, 26, state->fe[0]->dtv_property_cache.inversion^i);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode) {
int seg_offset =
state->fe[0]->dtv_property_cache.isdbt_sb_segment_idx -
(state->fe[0]->dtv_property_cache.isdbt_sb_segment_count / 2) -
(state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2);
int clk = state->cfg.pll->internal;
u32 segtodds = ((u32) (430 << 23) / clk) << 3;
int dds_offset = seg_offset * segtodds;
int new_dds, sub_channel;
if ((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2) == 0)
dds_offset -= (int)(segtodds / 2);
if (state->cfg.pll->ifreq == 0) {
if ((state->fe[0]->dtv_property_cache.inversion ^ i) == 0) {
dib8000_write_word(state, 26, dib8000_read_word(state, 26) | 1);
new_dds = dds_offset;
} else
new_dds = dds_offset;
if ((state->fe[0]->dtv_property_cache.delivery_system == SYS_ISDBT)
&& (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1)
&& (((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2)
&& (state->fe[0]->dtv_property_cache.isdbt_sb_segment_idx ==
((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count / 2) + 1)))
|| (((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2) == 0)
&& (state->fe[0]->dtv_property_cache.isdbt_sb_segment_idx == (state->fe[0]->dtv_property_cache.isdbt_sb_segment_count / 2)))
|| (((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2) == 0)
&& (state->fe[0]->dtv_property_cache.isdbt_sb_segment_idx ==
((state->fe[0]->dtv_property_cache.isdbt_sb_segment_count / 2) + 1)))
)) {
new_dds -= ((u32) (850 << 22) / clk) << 4;
}
} else {
if ((state->fe[0]->dtv_property_cache.inversion ^ i) == 0)
new_dds = state->cfg.pll->ifreq - dds_offset;
else
new_dds = state->cfg.pll->ifreq + dds_offset;
}
dib8000_write_word(state, 27, (u16) ((new_dds >> 16) & 0x01ff));
dib8000_write_word(state, 28, (u16) (new_dds & 0xffff));
if (state->fe[0]->dtv_property_cache.isdbt_sb_segment_count % 2)
sub_channel = ((state->fe[0]->dtv_property_cache.isdbt_sb_subchannel + (3 * seg_offset) + 1) % 41) / 3;
else
sub_channel = ((state->fe[0]->dtv_property_cache.isdbt_sb_subchannel + (3 * seg_offset)) % 41) / 3;
sub_channel -= 6;
if (state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_2K
|| state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_4K) {
dib8000_write_word(state, 219, dib8000_read_word(state, 219) | 0x1);
dib8000_write_word(state, 190, dib8000_read_word(state, 190) | (0x1 << 14));
} else {
dib8000_write_word(state, 219, dib8000_read_word(state, 219) & 0xfffe);
dib8000_write_word(state, 190, dib8000_read_word(state, 190) & 0xbfff);
}
switch (state->fe[0]->dtv_property_cache.transmission_mode) {
case TRANSMISSION_MODE_2K:
switch (sub_channel) {
case -6:
init_prbs = 0x0;
break;
case -5:
init_prbs = 0x423;
break;
case -4:
init_prbs = 0x9;
break;
case -3:
init_prbs = 0x5C7;
break;
case -2:
init_prbs = 0x7A6;
break;
case -1:
init_prbs = 0x3D8;
break;
case 0:
init_prbs = 0x527;
break;
case 1:
init_prbs = 0x7FF;
break;
case 2:
init_prbs = 0x79B;
break;
case 3:
init_prbs = 0x3D6;
break;
case 4:
init_prbs = 0x3A2;
break;
case 5:
init_prbs = 0x53B;
break;
case 6:
init_prbs = 0x2F4;
break;
default:
case 7:
init_prbs = 0x213;
break;
}
break;
case TRANSMISSION_MODE_4K:
switch (sub_channel) {
case -6:
init_prbs = 0x0;
break;
case -5:
init_prbs = 0x208;
break;
case -4:
init_prbs = 0xC3;
break;
case -3:
init_prbs = 0x7B9;
break;
case -2:
init_prbs = 0x423;
break;
case -1:
init_prbs = 0x5C7;
break;
case 0:
init_prbs = 0x3D8;
break;
case 1:
init_prbs = 0x7FF;
break;
case 2:
init_prbs = 0x3D6;
break;
case 3:
init_prbs = 0x53B;
break;
case 4:
init_prbs = 0x213;
break;
case 5:
init_prbs = 0x29;
break;
case 6:
init_prbs = 0xD0;
break;
default:
case 7:
init_prbs = 0x48E;
break;
}
break;
default:
case TRANSMISSION_MODE_8K:
switch (sub_channel) {
case -6:
init_prbs = 0x0;
break;
case -5:
init_prbs = 0x740;
break;
case -4:
init_prbs = 0x069;
break;
case -3:
init_prbs = 0x7DD;
break;
case -2:
init_prbs = 0x208;
break;
case -1:
init_prbs = 0x7B9;
break;
case 0:
init_prbs = 0x5C7;
break;
case 1:
init_prbs = 0x7FF;
break;
case 2:
init_prbs = 0x53B;
break;
case 3:
init_prbs = 0x29;
break;
case 4:
init_prbs = 0x48E;
break;
case 5:
init_prbs = 0x4C4;
break;
case 6:
init_prbs = 0x367;
break;
default:
case 7:
init_prbs = 0x684;
break;
}
break;
}
} else {
dib8000_write_word(state, 27, (u16) ((state->cfg.pll->ifreq >> 16) & 0x01ff));
dib8000_write_word(state, 28, (u16) (state->cfg.pll->ifreq & 0xffff));
dib8000_write_word(state, 26, (u16) ((state->cfg.pll->ifreq >> 25) & 0x0003));
}
dib8000_write_word(state, 10, (seq << 4));
switch (state->fe[0]->dtv_property_cache.guard_interval) {
case GUARD_INTERVAL_1_32:
guard = 0;
break;
case GUARD_INTERVAL_1_16:
guard = 1;
break;
case GUARD_INTERVAL_1_8:
guard = 2;
break;
case GUARD_INTERVAL_1_4:
default:
guard = 3;
break;
}
dib8000_write_word(state, 1, (init_prbs << 2) | (guard & 0x3));
max_constellation = DQPSK;
for (i = 0; i < 3; i++) {
switch (state->fe[0]->dtv_property_cache.layer[i].modulation) {
case DQPSK:
constellation = 0;
break;
case QPSK:
constellation = 1;
break;
case QAM_16:
constellation = 2;
break;
case QAM_64:
default:
constellation = 3;
break;
}
switch (state->fe[0]->dtv_property_cache.layer[i].fec) {
case FEC_1_2:
crate = 1;
break;
case FEC_2_3:
crate = 2;
break;
case FEC_3_4:
crate = 3;
break;
case FEC_5_6:
crate = 5;
break;
case FEC_7_8:
default:
crate = 7;
break;
}
if ((state->fe[0]->dtv_property_cache.layer[i].interleaving > 0) &&
((state->fe[0]->dtv_property_cache.layer[i].interleaving <= 3) ||
(state->fe[0]->dtv_property_cache.layer[i].interleaving == 4 && state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1))
)
timeI = state->fe[0]->dtv_property_cache.layer[i].interleaving;
else
timeI = 0;
dib8000_write_word(state, 2 + i, (constellation << 10) | ((state->fe[0]->dtv_property_cache.layer[i].segment_count & 0xf) << 6) |
(crate << 3) | timeI);
if (state->fe[0]->dtv_property_cache.layer[i].segment_count > 0) {
switch (max_constellation) {
case DQPSK:
case QPSK:
if (state->fe[0]->dtv_property_cache.layer[i].modulation == QAM_16 ||
state->fe[0]->dtv_property_cache.layer[i].modulation == QAM_64)
max_constellation = state->fe[0]->dtv_property_cache.layer[i].modulation;
break;
case QAM_16:
if (state->fe[0]->dtv_property_cache.layer[i].modulation == QAM_64)
max_constellation = state->fe[0]->dtv_property_cache.layer[i].modulation;
break;
}
}
}
mode = fft_to_mode(state);
dib8000_write_word(state, 274, (dib8000_read_word(state, 274) & 0xffcf) |
((state->fe[0]->dtv_property_cache.isdbt_partial_reception & 1) << 5) | ((state->fe[0]->dtv_property_cache.
isdbt_sb_mode & 1) << 4));
dprintk("mode = %d ; guard = %d", mode, state->fe[0]->dtv_property_cache.guard_interval);
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception) {
seg_diff_mask = (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK) << permu_seg[0];
for (i = 1; i < 3; i++)
nbseg_diff +=
(state->fe[0]->dtv_property_cache.layer[i].modulation == DQPSK) * state->fe[0]->dtv_property_cache.layer[i].segment_count;
for (i = 0; i < nbseg_diff; i++)
seg_diff_mask |= 1 << permu_seg[i + 1];
} else {
for (i = 0; i < 3; i++)
nbseg_diff +=
(state->fe[0]->dtv_property_cache.layer[i].modulation == DQPSK) * state->fe[0]->dtv_property_cache.layer[i].segment_count;
for (i = 0; i < nbseg_diff; i++)
seg_diff_mask |= 1 << permu_seg[i];
}
dprintk("nbseg_diff = %X (%d)", seg_diff_mask, seg_diff_mask);
state->differential_constellation = (seg_diff_mask != 0);
if (state->revision != 0x8090)
dib8000_set_diversity_in(state->fe[0], state->diversity_onoff);
else
dib8096p_set_diversity_in(state->fe[0], state->diversity_onoff);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 1)
seg_mask13 = 0x00E0;
else
seg_mask13 = 0x0040;
} else
seg_mask13 = 0x1fff;
dib8000_write_word(state, 0, (mode << 13) | seg_diff_mask);
if ((seg_diff_mask) || (state->fe[0]->dtv_property_cache.isdbt_sb_mode))
dib8000_write_word(state, 268, (dib8000_read_word(state, 268) & 0xF9FF) | 0x0200);
else
dib8000_write_word(state, 268, (2 << 9) | 39);
dib8000_write_word(state, 352, seg_diff_mask);
dib8000_write_word(state, 353, seg_mask13);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
switch (state->fe[0]->dtv_property_cache.transmission_mode) {
case TRANSMISSION_MODE_2K:
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0) {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK)
ncoeff = coeff_2k_sb_1seg_dqpsk;
else
ncoeff = coeff_2k_sb_1seg;
} else {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK) {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK)
ncoeff = coeff_2k_sb_3seg_0dqpsk_1dqpsk;
else
ncoeff = coeff_2k_sb_3seg_0dqpsk;
} else {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK)
ncoeff = coeff_2k_sb_3seg_1dqpsk;
else
ncoeff = coeff_2k_sb_3seg;
}
}
break;
case TRANSMISSION_MODE_4K:
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0) {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK)
ncoeff = coeff_4k_sb_1seg_dqpsk;
else
ncoeff = coeff_4k_sb_1seg;
} else {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK) {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK) {
ncoeff = coeff_4k_sb_3seg_0dqpsk_1dqpsk;
} else {
ncoeff = coeff_4k_sb_3seg_0dqpsk;
}
} else {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK) {
ncoeff = coeff_4k_sb_3seg_1dqpsk;
} else
ncoeff = coeff_4k_sb_3seg;
}
}
break;
case TRANSMISSION_MODE_AUTO:
case TRANSMISSION_MODE_8K:
default:
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0) {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK)
ncoeff = coeff_8k_sb_1seg_dqpsk;
else
ncoeff = coeff_8k_sb_1seg;
} else {
if (state->fe[0]->dtv_property_cache.layer[0].modulation == DQPSK) {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK) {
ncoeff = coeff_8k_sb_3seg_0dqpsk_1dqpsk;
} else {
ncoeff = coeff_8k_sb_3seg_0dqpsk;
}
} else {
if (state->fe[0]->dtv_property_cache.layer[1].modulation == DQPSK) {
ncoeff = coeff_8k_sb_3seg_1dqpsk;
} else
ncoeff = coeff_8k_sb_3seg;
}
}
break;
}
for (i = 0; i < 8; i++)
dib8000_write_word(state, 343 + i, ncoeff[i]);
}
dib8000_write_word(state, 351,
(state->fe[0]->dtv_property_cache.isdbt_sb_mode << 9) | (state->fe[0]->dtv_property_cache.isdbt_sb_mode << 8) | (13 << 4) | 5);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
dib8000_write_word(state, 187,
(4 << 12) | (0 << 11) | (63 << 5) | (0x3 << 3) | ((~state->fe[0]->dtv_property_cache.isdbt_partial_reception & 1) << 2)
| 0x3);
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0) {
if (mode == 3)
dib8000_write_word(state, 180, 0x1fcf | ((mode - 1) << 14));
else
dib8000_write_word(state, 180, 0x0fcf | ((mode - 1) << 14));
dib8000_write_word(state, 338, (1 << 12) | (1 << 10) | (0 << 9) | (5 << 5) | 4);
dib8000_write_word(state, 340, (16 << 6) | (8 << 0));
dib8000_write_word(state, 341, (6 << 3) | (1 << 2) | (1 << 1) | (1 << 0));
dib8000_write_word(state, 181, 300);
dib8000_write_word(state, 182, 150);
dib8000_write_word(state, 183, 80);
dib8000_write_word(state, 184, 300);
dib8000_write_word(state, 185, 150);
dib8000_write_word(state, 186, 80);
} else {
dib8000_write_word(state, 180, 0x1fcf | (1 << 14));
dib8000_write_word(state, 338, (1 << 12) | (1 << 10) | (0 << 9) | (4 << 5) | 4);
dib8000_write_word(state, 340, (16 << 6) | (8 << 0));
dib8000_write_word(state, 341, (6 << 3) | (1 << 2) | (1 << 1) | (1 << 0));
dib8000_write_word(state, 181, 350);
dib8000_write_word(state, 182, 300);
dib8000_write_word(state, 183, 250);
dib8000_write_word(state, 184, 350);
dib8000_write_word(state, 185, 300);
dib8000_write_word(state, 186, 250);
}
} else if (state->isdbt_cfg_loaded == 0) {
dib8000_write_word(state, 180, (16 << 6) | 9);
dib8000_write_word(state, 187, (4 << 12) | (8 << 5) | 0x2);
coff_pow = 0x2800;
for (i = 0; i < 6; i++)
dib8000_write_word(state, 181 + i, coff_pow);
dib8000_write_word(state, 338, (1 << 12) | (1 << 10) | (0 << 9) | (3 << 5) | 1);
dib8000_write_word(state, 340, (8 << 6) | (6 << 0));
dib8000_write_word(state, 341, (4 << 3) | (1 << 2) | (1 << 1) | (1 << 0));
}
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1 && state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0)
dib8000_write_word(state, 178, 64);
else
dib8000_write_word(state, 178, 32);
dib8000_write_word(state, 189, ~seg_mask13 | seg_diff_mask);
dib8000_write_word(state, 192, ~seg_mask13 | seg_diff_mask);
dib8000_write_word(state, 225, ~seg_mask13 | seg_diff_mask);
if ((!state->fe[0]->dtv_property_cache.isdbt_sb_mode) && (state->cfg.pll->ifreq == 0))
dib8000_write_word(state, 266, ~seg_mask13 | seg_diff_mask | 0x40);
else
dib8000_write_word(state, 266, ~seg_mask13 | seg_diff_mask);
dib8000_write_word(state, 287, ~seg_mask13 | 0x1000);
if (!autosearching)
dib8000_write_word(state, 288, (~seg_mask13 | seg_diff_mask) & 0x1fff);
else
dib8000_write_word(state, 288, 0x1fff);
dprintk("287 = %X (%d)", ~seg_mask13 | 0x1000, ~seg_mask13 | 0x1000);
dib8000_write_word(state, 211, seg_mask13 & (~seg_diff_mask));
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0)
dib8000_write_word(state, 32, ((11 - mode) << 12) | (6 << 8) | 0x40);
else
dib8000_write_word(state, 32, ((10 - mode) << 12) | (6 << 8) | 0x60);
} else
dib8000_write_word(state, 32, ((9 - mode) << 12) | (6 << 8) | 0x80);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0)
dib8000_write_word(state, 37, (3 << 5) | (0 << 4) | (10 - mode));
else
dib8000_write_word(state, 37, (3 << 5) | (0 << 4) | (9 - mode));
} else
dib8000_write_word(state, 37, (3 << 5) | (0 << 4) | (8 - mode));
switch (state->fe[0]->dtv_property_cache.transmission_mode) {
case TRANSMISSION_MODE_8K:
mode = 256;
break;
case TRANSMISSION_MODE_4K:
mode = 128;
break;
default:
case TRANSMISSION_MODE_2K:
mode = 64;
break;
}
if (state->cfg.diversity_delay == 0)
mode = (mode * (1 << (guard)) * 3) / 2 + 48;
else
mode = (mode * (1 << (guard)) * 3) / 2 + state->cfg.diversity_delay;
mode <<= 4;
dib8000_write_word(state, 273, (dib8000_read_word(state, 273) & 0x000f) | mode);
switch (max_constellation) {
case QAM_64:
ana_gain = 0x7;
coeff[0] = 0x0148;
coeff[1] = 0xfff0;
coeff[2] = 0x00a4;
coeff[3] = 0xfff8;
break;
case QAM_16:
ana_gain = 0x7;
coeff[0] = 0x023d;
coeff[1] = 0xffdf;
coeff[2] = 0x00a4;
coeff[3] = 0xfff0;
break;
default:
ana_gain = 0;
coeff[0] = 0x099a;
coeff[1] = 0xffae;
coeff[2] = 0x0333;
coeff[3] = 0xfff8;
break;
}
for (mode = 0; mode < 4; mode++)
dib8000_write_word(state, 215 + mode, coeff[mode]);
dib8000_write_word(state, 116, ana_gain);
if (ana_gain) {
for (i = 0; i < 10; i++)
dib8000_write_word(state, 80 + i, adc_target_16dB[i]);
} else {
for (i = 0; i < 10; i++)
dib8000_write_word(state, 80 + i, adc_target_16dB[i] - 355);
}
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 1)
ana_fe = ana_fe_coeff_3seg;
else
ana_fe = ana_fe_coeff_1seg;
} else
ana_fe = ana_fe_coeff_13seg;
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1 || state->isdbt_cfg_loaded == 0)
for (mode = 0; mode < 24; mode++)
dib8000_write_word(state, 117 + mode, ana_fe[mode]);
for (i = 0; i < 13; i++) {
if ((((~seg_diff_mask) >> i) & 1) == 1) {
P_cfr_left_edge += (1 << i) * ((i == 0) || ((((seg_mask13 & (~seg_diff_mask)) >> (i - 1)) & 1) == 0));
P_cfr_right_edge += (1 << i) * ((i == 12) || ((((seg_mask13 & (~seg_diff_mask)) >> (i + 1)) & 1) == 0));
}
}
dib8000_write_word(state, 222, P_cfr_left_edge);
dib8000_write_word(state, 223, P_cfr_right_edge);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
dib8000_write_word(state, 228, 1);
dib8000_write_word(state, 205, dib8000_read_word(state, 205) & 0xfff0);
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0
&& state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_2K) {
dib8000_write_word(state, 265, 15);
}
} else if (state->isdbt_cfg_loaded == 0) {
dib8000_write_word(state, 228, 0);
dib8000_write_word(state, 265, 31);
dib8000_write_word(state, 205, 0x200f);
}
for (i = 0; i < 3; i++)
tmcc_pow +=
(((state->fe[0]->dtv_property_cache.layer[i].modulation == DQPSK) * 4 + 1) * state->fe[0]->dtv_property_cache.layer[i].segment_count);
tmcc_pow *= (1 << (9 - 2));
dib8000_write_word(state, 290, tmcc_pow);
dib8000_write_word(state, 291, tmcc_pow);
dib8000_write_word(state, 292, tmcc_pow);
if (state->isdbt_cfg_loaded == 0)
dib8000_write_word(state, 250, 3285);
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1)
state->isdbt_cfg_loaded = 0;
else
state->isdbt_cfg_loaded = 1;
}
static int dib8000_autosearch_start(struct dvb_frontend *fe)
{
u8 factor;
u32 value;
struct dib8000_state *state = fe->demodulator_priv;
int slist = 0;
state->fe[0]->dtv_property_cache.inversion = 0;
if (!state->fe[0]->dtv_property_cache.isdbt_sb_mode)
state->fe[0]->dtv_property_cache.layer[0].segment_count = 13;
state->fe[0]->dtv_property_cache.layer[0].modulation = QAM_64;
state->fe[0]->dtv_property_cache.layer[0].fec = FEC_2_3;
state->fe[0]->dtv_property_cache.layer[0].interleaving = 0;
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode) {
state->fe[0]->dtv_property_cache.transmission_mode = TRANSMISSION_MODE_8K;
state->fe[0]->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_8;
slist = 7;
dib8000_write_word(state, 0, (dib8000_read_word(state, 0) & 0x9fff) | (1 << 13));
} else {
if (state->fe[0]->dtv_property_cache.guard_interval == GUARD_INTERVAL_AUTO) {
if (state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_AUTO) {
slist = 7;
dib8000_write_word(state, 0, (dib8000_read_word(state, 0) & 0x9fff) | (1 << 13));
} else
slist = 3;
} else {
if (state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_AUTO) {
slist = 2;
dib8000_write_word(state, 0, (dib8000_read_word(state, 0) & 0x9fff) | (1 << 13));
} else
slist = 0;
}
if (state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_AUTO)
state->fe[0]->dtv_property_cache.transmission_mode = TRANSMISSION_MODE_8K;
if (state->fe[0]->dtv_property_cache.guard_interval == GUARD_INTERVAL_AUTO)
state->fe[0]->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_8;
dprintk("using list for autosearch : %d", slist);
dib8000_set_channel(state, (unsigned char)slist, 1);
factor = 1;
dib8000_write_word(state, 6, 0x4);
dib8000_write_word(state, 7, 0x8);
dib8000_write_word(state, 8, 0x1000);
value = 50 * state->cfg.pll->internal * factor;
dib8000_write_word(state, 11, (u16) ((value >> 16) & 0xffff));
dib8000_write_word(state, 12, (u16) (value & 0xffff));
value = 100 * state->cfg.pll->internal * factor;
dib8000_write_word(state, 13, (u16) ((value >> 16) & 0xffff));
dib8000_write_word(state, 14, (u16) (value & 0xffff));
value = 1000 * state->cfg.pll->internal * factor;
dib8000_write_word(state, 15, (u16) ((value >> 16) & 0xffff));
dib8000_write_word(state, 16, (u16) (value & 0xffff));
value = dib8000_read_word(state, 0);
dib8000_write_word(state, 0, (u16) ((1 << 15) | value));
dib8000_read_word(state, 1284);
dib8000_write_word(state, 0, (u16) value);
}
return 0;
}
static int dib8000_autosearch_irq(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 irq_pending = dib8000_read_word(state, 1284);
if (irq_pending & 0x1) {
dprintk("dib8000_autosearch_irq failed");
return 1;
}
if (irq_pending & 0x2) {
dprintk("dib8000_autosearch_irq succeeded");
return 2;
}
return 0;
}
static int dib8000_tune(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
int ret = 0;
u16 lock, value, mode;
if (state == NULL)
return -EINVAL;
mode = fft_to_mode(state);
dib8000_set_bandwidth(fe, state->fe[0]->dtv_property_cache.bandwidth_hz / 1000);
dib8000_set_channel(state, 0, 0);
ret |= dib8000_write_word(state, 770, 0x4000);
ret |= dib8000_write_word(state, 770, 0x0000);
msleep(45);
if (state->timf == 0) {
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0)
msleep(300);
else
msleep(500);
} else
msleep(200);
}
if (state->fe[0]->dtv_property_cache.isdbt_sb_mode == 1) {
if (state->fe[0]->dtv_property_cache.isdbt_partial_reception == 0) {
dib8000_write_word(state, 32, ((13 - mode) << 12) | (6 << 8) | 0x40);
ret |= dib8000_write_word(state, 37, (12 - mode) | ((5 + mode) << 5));
} else {
dib8000_write_word(state, 32, ((12 - mode) << 12) | (6 << 8) | 0x60);
ret |= dib8000_write_word(state, 37, (11 - mode) | ((5 + mode) << 5));
}
} else {
dib8000_write_word(state, 32, ((11 - mode) << 12) | (6 << 8) | 0x80);
ret |= dib8000_write_word(state, 37, (10 - mode) | ((5 + mode) << 5));
}
if (state->revision != 0x8090)
lock = dib8000_read_word(state, 568);
else
lock = dib8000_read_word(state, 570);
if ((lock >> 11) & 0x1)
dib8000_update_timf(state);
dib8000_write_word(state, 6, 0x200);
if (state->revision == 0x8002) {
value = dib8000_read_word(state, 903);
dib8000_write_word(state, 903, value & ~(1 << 3));
msleep(1);
dib8000_write_word(state, 903, value | (1 << 3));
}
return ret;
}
static int dib8000_wakeup(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend;
int ret;
dib8000_set_power_mode(state, DIB8000_POWER_ALL);
dib8000_set_adc_state(state, DIBX000_ADC_ON);
if (dib8000_set_adc_state(state, DIBX000_SLOW_ADC_ON) != 0)
dprintk("could not start Slow ADC");
if (state->revision != 0x8090)
dib8000_sad_calib(state);
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
ret = state->fe[index_frontend]->ops.init(state->fe[index_frontend]);
if (ret < 0)
return ret;
}
return 0;
}
static int dib8000_sleep(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend;
int ret;
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
ret = state->fe[index_frontend]->ops.sleep(state->fe[index_frontend]);
if (ret < 0)
return ret;
}
if (state->revision != 0x8090)
dib8000_set_output_mode(fe, OUTMODE_HIGH_Z);
dib8000_set_power_mode(state, DIB8000_POWER_INTERFACE_ONLY);
return dib8000_set_adc_state(state, DIBX000_SLOW_ADC_OFF) | dib8000_set_adc_state(state, DIBX000_ADC_OFF);
}
enum frontend_tune_state dib8000_get_tune_state(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
return state->tune_state;
}
int dib8000_set_tune_state(struct dvb_frontend *fe, enum frontend_tune_state tune_state)
{
struct dib8000_state *state = fe->demodulator_priv;
state->tune_state = tune_state;
return 0;
}
static int dib8000_get_frontend(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 i, val = 0;
fe_status_t stat;
u8 index_frontend, sub_index_frontend;
fe->dtv_property_cache.bandwidth_hz = 6000000;
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
state->fe[index_frontend]->ops.read_status(state->fe[index_frontend], &stat);
if (stat&FE_HAS_SYNC) {
dprintk("TMCC lock on the slave%i", index_frontend);
state->fe[index_frontend]->ops.get_frontend(state->fe[index_frontend]);
for (sub_index_frontend = 0; (sub_index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[sub_index_frontend] != NULL); sub_index_frontend++) {
if (sub_index_frontend != index_frontend) {
state->fe[sub_index_frontend]->dtv_property_cache.isdbt_sb_mode = state->fe[index_frontend]->dtv_property_cache.isdbt_sb_mode;
state->fe[sub_index_frontend]->dtv_property_cache.inversion = state->fe[index_frontend]->dtv_property_cache.inversion;
state->fe[sub_index_frontend]->dtv_property_cache.transmission_mode = state->fe[index_frontend]->dtv_property_cache.transmission_mode;
state->fe[sub_index_frontend]->dtv_property_cache.guard_interval = state->fe[index_frontend]->dtv_property_cache.guard_interval;
state->fe[sub_index_frontend]->dtv_property_cache.isdbt_partial_reception = state->fe[index_frontend]->dtv_property_cache.isdbt_partial_reception;
for (i = 0; i < 3; i++) {
state->fe[sub_index_frontend]->dtv_property_cache.layer[i].segment_count = state->fe[index_frontend]->dtv_property_cache.layer[i].segment_count;
state->fe[sub_index_frontend]->dtv_property_cache.layer[i].interleaving = state->fe[index_frontend]->dtv_property_cache.layer[i].interleaving;
state->fe[sub_index_frontend]->dtv_property_cache.layer[i].fec = state->fe[index_frontend]->dtv_property_cache.layer[i].fec;
state->fe[sub_index_frontend]->dtv_property_cache.layer[i].modulation = state->fe[index_frontend]->dtv_property_cache.layer[i].modulation;
}
}
}
return 0;
}
}
fe->dtv_property_cache.isdbt_sb_mode = dib8000_read_word(state, 508) & 0x1;
if (state->revision == 0x8090)
val = dib8000_read_word(state, 572);
else
val = dib8000_read_word(state, 570);
fe->dtv_property_cache.inversion = (val & 0x40) >> 6;
switch ((val & 0x30) >> 4) {
case 1:
fe->dtv_property_cache.transmission_mode = TRANSMISSION_MODE_2K;
break;
case 3:
default:
fe->dtv_property_cache.transmission_mode = TRANSMISSION_MODE_8K;
break;
}
switch (val & 0x3) {
case 0:
fe->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_32;
dprintk("dib8000_get_frontend GI = 1/32 ");
break;
case 1:
fe->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_16;
dprintk("dib8000_get_frontend GI = 1/16 ");
break;
case 2:
dprintk("dib8000_get_frontend GI = 1/8 ");
fe->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_8;
break;
case 3:
dprintk("dib8000_get_frontend GI = 1/4 ");
fe->dtv_property_cache.guard_interval = GUARD_INTERVAL_1_4;
break;
}
val = dib8000_read_word(state, 505);
fe->dtv_property_cache.isdbt_partial_reception = val & 1;
dprintk("dib8000_get_frontend : partial_reception = %d ", fe->dtv_property_cache.isdbt_partial_reception);
for (i = 0; i < 3; i++) {
val = dib8000_read_word(state, 493 + i);
fe->dtv_property_cache.layer[i].segment_count = val & 0x0F;
dprintk("dib8000_get_frontend : Layer %d segments = %d ", i, fe->dtv_property_cache.layer[i].segment_count);
val = dib8000_read_word(state, 499 + i);
fe->dtv_property_cache.layer[i].interleaving = val & 0x3;
dprintk("dib8000_get_frontend : Layer %d time_intlv = %d ", i, fe->dtv_property_cache.layer[i].interleaving);
val = dib8000_read_word(state, 481 + i);
switch (val & 0x7) {
case 1:
fe->dtv_property_cache.layer[i].fec = FEC_1_2;
dprintk("dib8000_get_frontend : Layer %d Code Rate = 1/2 ", i);
break;
case 2:
fe->dtv_property_cache.layer[i].fec = FEC_2_3;
dprintk("dib8000_get_frontend : Layer %d Code Rate = 2/3 ", i);
break;
case 3:
fe->dtv_property_cache.layer[i].fec = FEC_3_4;
dprintk("dib8000_get_frontend : Layer %d Code Rate = 3/4 ", i);
break;
case 5:
fe->dtv_property_cache.layer[i].fec = FEC_5_6;
dprintk("dib8000_get_frontend : Layer %d Code Rate = 5/6 ", i);
break;
default:
fe->dtv_property_cache.layer[i].fec = FEC_7_8;
dprintk("dib8000_get_frontend : Layer %d Code Rate = 7/8 ", i);
break;
}
val = dib8000_read_word(state, 487 + i);
switch (val & 0x3) {
case 0:
dprintk("dib8000_get_frontend : Layer %d DQPSK ", i);
fe->dtv_property_cache.layer[i].modulation = DQPSK;
break;
case 1:
fe->dtv_property_cache.layer[i].modulation = QPSK;
dprintk("dib8000_get_frontend : Layer %d QPSK ", i);
break;
case 2:
fe->dtv_property_cache.layer[i].modulation = QAM_16;
dprintk("dib8000_get_frontend : Layer %d QAM16 ", i);
break;
case 3:
default:
dprintk("dib8000_get_frontend : Layer %d QAM64 ", i);
fe->dtv_property_cache.layer[i].modulation = QAM_64;
break;
}
}
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
state->fe[index_frontend]->dtv_property_cache.isdbt_sb_mode = fe->dtv_property_cache.isdbt_sb_mode;
state->fe[index_frontend]->dtv_property_cache.inversion = fe->dtv_property_cache.inversion;
state->fe[index_frontend]->dtv_property_cache.transmission_mode = fe->dtv_property_cache.transmission_mode;
state->fe[index_frontend]->dtv_property_cache.guard_interval = fe->dtv_property_cache.guard_interval;
state->fe[index_frontend]->dtv_property_cache.isdbt_partial_reception = fe->dtv_property_cache.isdbt_partial_reception;
for (i = 0; i < 3; i++) {
state->fe[index_frontend]->dtv_property_cache.layer[i].segment_count = fe->dtv_property_cache.layer[i].segment_count;
state->fe[index_frontend]->dtv_property_cache.layer[i].interleaving = fe->dtv_property_cache.layer[i].interleaving;
state->fe[index_frontend]->dtv_property_cache.layer[i].fec = fe->dtv_property_cache.layer[i].fec;
state->fe[index_frontend]->dtv_property_cache.layer[i].modulation = fe->dtv_property_cache.layer[i].modulation;
}
}
return 0;
}
static int dib8000_set_frontend(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 nbr_pending, exit_condition, index_frontend;
s8 index_frontend_success = -1;
int time, ret;
int time_slave = FE_CALLBACK_TIME_NEVER;
if (state->fe[0]->dtv_property_cache.frequency == 0) {
dprintk("dib8000: must at least specify frequency ");
return 0;
}
if (state->fe[0]->dtv_property_cache.bandwidth_hz == 0) {
dprintk("dib8000: no bandwidth specified, set to default ");
state->fe[0]->dtv_property_cache.bandwidth_hz = 6000000;
}
for (index_frontend = 0; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
state->fe[index_frontend]->dtv_property_cache.delivery_system = SYS_ISDBT;
memcpy(&state->fe[index_frontend]->dtv_property_cache, &fe->dtv_property_cache, sizeof(struct dtv_frontend_properties));
if (state->revision != 0x8090)
dib8000_set_output_mode(state->fe[index_frontend],
OUTMODE_HIGH_Z);
else
dib8096p_set_output_mode(state->fe[index_frontend],
OUTMODE_HIGH_Z);
if (state->fe[index_frontend]->ops.tuner_ops.set_params)
state->fe[index_frontend]->ops.tuner_ops.set_params(state->fe[index_frontend]);
dib8000_set_tune_state(state->fe[index_frontend], CT_AGC_START);
}
do {
time = dib8000_agc_startup(state->fe[0]);
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
time_slave = dib8000_agc_startup(state->fe[index_frontend]);
if (time == FE_CALLBACK_TIME_NEVER)
time = time_slave;
else if ((time_slave != FE_CALLBACK_TIME_NEVER) && (time_slave > time))
time = time_slave;
}
if (time != FE_CALLBACK_TIME_NEVER)
msleep(time / 10);
else
break;
exit_condition = 1;
for (index_frontend = 0; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
if (dib8000_get_tune_state(state->fe[index_frontend]) != CT_AGC_STOP) {
exit_condition = 0;
break;
}
}
} while (exit_condition == 0);
for (index_frontend = 0; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++)
dib8000_set_tune_state(state->fe[index_frontend], CT_DEMOD_START);
if ((state->fe[0]->dtv_property_cache.delivery_system != SYS_ISDBT) ||
(state->fe[0]->dtv_property_cache.inversion == INVERSION_AUTO) ||
(state->fe[0]->dtv_property_cache.transmission_mode == TRANSMISSION_MODE_AUTO) ||
(state->fe[0]->dtv_property_cache.guard_interval == GUARD_INTERVAL_AUTO) ||
(((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (1 << 0)) != 0) &&
(state->fe[0]->dtv_property_cache.layer[0].segment_count != 0xff) &&
(state->fe[0]->dtv_property_cache.layer[0].segment_count != 0) &&
((state->fe[0]->dtv_property_cache.layer[0].modulation == QAM_AUTO) ||
(state->fe[0]->dtv_property_cache.layer[0].fec == FEC_AUTO))) ||
(((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (1 << 1)) != 0) &&
(state->fe[0]->dtv_property_cache.layer[1].segment_count != 0xff) &&
(state->fe[0]->dtv_property_cache.layer[1].segment_count != 0) &&
((state->fe[0]->dtv_property_cache.layer[1].modulation == QAM_AUTO) ||
(state->fe[0]->dtv_property_cache.layer[1].fec == FEC_AUTO))) ||
(((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (1 << 2)) != 0) &&
(state->fe[0]->dtv_property_cache.layer[2].segment_count != 0xff) &&
(state->fe[0]->dtv_property_cache.layer[2].segment_count != 0) &&
((state->fe[0]->dtv_property_cache.layer[2].modulation == QAM_AUTO) ||
(state->fe[0]->dtv_property_cache.layer[2].fec == FEC_AUTO))) ||
(((state->fe[0]->dtv_property_cache.layer[0].segment_count == 0) ||
((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (1 << 0)) == 0)) &&
((state->fe[0]->dtv_property_cache.layer[1].segment_count == 0) ||
((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (2 << 0)) == 0)) &&
((state->fe[0]->dtv_property_cache.layer[2].segment_count == 0) || ((state->fe[0]->dtv_property_cache.isdbt_layer_enabled & (3 << 0)) == 0)))) {
int i = 100;
u8 found = 0;
u8 tune_failed = 0;
for (index_frontend = 0; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
dib8000_set_bandwidth(state->fe[index_frontend], fe->dtv_property_cache.bandwidth_hz / 1000);
dib8000_autosearch_start(state->fe[index_frontend]);
}
do {
msleep(20);
nbr_pending = 0;
exit_condition = 0;
for (index_frontend = 0; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
if (((tune_failed >> index_frontend) & 0x1) == 0) {
found = dib8000_autosearch_irq(state->fe[index_frontend]);
switch (found) {
case 0:
nbr_pending++;
break;
case 2:
dprintk("autosearch succeed on the frontend%i", index_frontend);
exit_condition = 2;
index_frontend_success = index_frontend;
break;
default:
dprintk("unhandled autosearch result");
case 1:
tune_failed |= (1 << index_frontend);
dprintk("autosearch failed for the frontend%i", index_frontend);
break;
}
}
}
if ((nbr_pending == 0) && (exit_condition == 0))
exit_condition = 1;
} while ((exit_condition == 0) && i--);
if (exit_condition == 1) {
dprintk("tune failed");
return 0;
}
dprintk("tune success on frontend%i", index_frontend_success);
dib8000_get_frontend(fe);
}
for (index_frontend = 0, ret = 0; (ret >= 0) && (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++)
ret = dib8000_tune(state->fe[index_frontend]);
if (state->revision != 0x8090) {
dib8000_set_output_mode(state->fe[0], state->cfg.output_mode);
for (index_frontend = 1;
(index_frontend < MAX_NUMBER_OF_FRONTENDS) &&
(state->fe[index_frontend] != NULL);
index_frontend++) {
dib8000_set_output_mode(state->fe[index_frontend],
OUTMODE_DIVERSITY);
dib8000_set_diversity_in(state->fe[index_frontend-1], 1);
}
dib8000_set_diversity_in(state->fe[index_frontend-1], 0);
} else {
dib8096p_set_output_mode(state->fe[0], state->cfg.output_mode);
if (state->cfg.enMpegOutput == 0) {
dib8096p_setDibTxMux(state, MPEG_ON_DIBTX);
dib8096p_setHostBusMux(state, DIBTX_ON_HOSTBUS);
}
for (index_frontend = 1;
(index_frontend < MAX_NUMBER_OF_FRONTENDS) &&
(state->fe[index_frontend] != NULL);
index_frontend++) {
dib8096p_set_output_mode(state->fe[index_frontend],
OUTMODE_DIVERSITY);
dib8096p_set_diversity_in(state->fe[index_frontend-1], 1);
}
dib8096p_set_diversity_in(state->fe[index_frontend-1], 0);
}
return ret;
}
static u16 dib8000_read_lock(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
if (state->revision == 0x8090)
return dib8000_read_word(state, 570);
return dib8000_read_word(state, 568);
}
static int dib8000_read_status(struct dvb_frontend *fe, fe_status_t * stat)
{
struct dib8000_state *state = fe->demodulator_priv;
u16 lock_slave = 0, lock;
u8 index_frontend;
if (state->revision == 0x8090)
lock = dib8000_read_word(state, 570);
else
lock = dib8000_read_word(state, 568);
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++)
lock_slave |= dib8000_read_lock(state->fe[index_frontend]);
*stat = 0;
if (((lock >> 13) & 1) || ((lock_slave >> 13) & 1))
*stat |= FE_HAS_SIGNAL;
if (((lock >> 8) & 1) || ((lock_slave >> 8) & 1))
*stat |= FE_HAS_CARRIER;
if ((((lock >> 1) & 0xf) == 0xf) || (((lock_slave >> 1) & 0xf) == 0xf))
*stat |= FE_HAS_SYNC;
if ((((lock >> 12) & 1) || ((lock_slave >> 12) & 1)) && ((lock >> 5) & 7))
*stat |= FE_HAS_LOCK;
if (((lock >> 12) & 1) || ((lock_slave >> 12) & 1)) {
lock = dib8000_read_word(state, 554);
if (lock & 0x01)
*stat |= FE_HAS_VITERBI;
lock = dib8000_read_word(state, 555);
if (lock & 0x01)
*stat |= FE_HAS_VITERBI;
lock = dib8000_read_word(state, 556);
if (lock & 0x01)
*stat |= FE_HAS_VITERBI;
}
return 0;
}
static int dib8000_read_ber(struct dvb_frontend *fe, u32 * ber)
{
struct dib8000_state *state = fe->demodulator_priv;
if (state->revision == 0x8090)
*ber = (dib8000_read_word(state, 562) << 16) |
dib8000_read_word(state, 563);
else
*ber = (dib8000_read_word(state, 560) << 16) |
dib8000_read_word(state, 561);
return 0;
}
static int dib8000_read_unc_blocks(struct dvb_frontend *fe, u32 * unc)
{
struct dib8000_state *state = fe->demodulator_priv;
if (state->revision == 0x8090)
*unc = dib8000_read_word(state, 567);
else
*unc = dib8000_read_word(state, 565);
return 0;
}
static int dib8000_read_signal_strength(struct dvb_frontend *fe, u16 * strength)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend;
u16 val;
*strength = 0;
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++) {
state->fe[index_frontend]->ops.read_signal_strength(state->fe[index_frontend], &val);
if (val > 65535 - *strength)
*strength = 65535;
else
*strength += val;
}
val = 65535 - dib8000_read_word(state, 390);
if (val > 65535 - *strength)
*strength = 65535;
else
*strength += val;
return 0;
}
static u32 dib8000_get_snr(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u32 n, s, exp;
u16 val;
if (state->revision != 0x8090)
val = dib8000_read_word(state, 542);
else
val = dib8000_read_word(state, 544);
n = (val >> 6) & 0xff;
exp = (val & 0x3f);
if ((exp & 0x20) != 0)
exp -= 0x40;
n <<= exp+16;
if (state->revision != 0x8090)
val = dib8000_read_word(state, 543);
else
val = dib8000_read_word(state, 545);
s = (val >> 6) & 0xff;
exp = (val & 0x3f);
if ((exp & 0x20) != 0)
exp -= 0x40;
s <<= exp+16;
if (n > 0) {
u32 t = (s/n) << 16;
return t + ((s << 16) - n*t) / n;
}
return 0xffffffff;
}
static int dib8000_read_snr(struct dvb_frontend *fe, u16 * snr)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend;
u32 snr_master;
snr_master = dib8000_get_snr(fe);
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL); index_frontend++)
snr_master += dib8000_get_snr(state->fe[index_frontend]);
if ((snr_master >> 16) != 0) {
snr_master = 10*intlog10(snr_master>>16);
*snr = snr_master / ((1 << 24) / 10);
}
else
*snr = 0;
return 0;
}
int dib8000_set_slave_frontend(struct dvb_frontend *fe, struct dvb_frontend *fe_slave)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend = 1;
while ((index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL))
index_frontend++;
if (index_frontend < MAX_NUMBER_OF_FRONTENDS) {
dprintk("set slave fe %p to index %i", fe_slave, index_frontend);
state->fe[index_frontend] = fe_slave;
return 0;
}
dprintk("too many slave frontend");
return -ENOMEM;
}
int dib8000_remove_slave_frontend(struct dvb_frontend *fe)
{
struct dib8000_state *state = fe->demodulator_priv;
u8 index_frontend = 1;
while ((index_frontend < MAX_NUMBER_OF_FRONTENDS) && (state->fe[index_frontend] != NULL))
index_frontend++;
if (index_frontend != 1) {
dprintk("remove slave fe %p (index %i)", state->fe[index_frontend-1], index_frontend-1);
state->fe[index_frontend] = NULL;
return 0;
}
dprintk("no frontend to be removed");
return -ENODEV;
}
struct dvb_frontend *dib8000_get_slave_frontend(struct dvb_frontend *fe, int slave_index)
{
struct dib8000_state *state = fe->demodulator_priv;
if (slave_index >= MAX_NUMBER_OF_FRONTENDS)
return NULL;
return state->fe[slave_index];
}
int dib8000_i2c_enumeration(struct i2c_adapter *host, int no_of_demods,
u8 default_addr, u8 first_addr, u8 is_dib8096p)
{
int k = 0, ret = 0;
u8 new_addr = 0;
struct i2c_device client = {.adap = host };
client.i2c_write_buffer = kzalloc(4 * sizeof(u8), GFP_KERNEL);
if (!client.i2c_write_buffer) {
dprintk("%s: not enough memory", __func__);
return -ENOMEM;
}
client.i2c_read_buffer = kzalloc(4 * sizeof(u8), GFP_KERNEL);
if (!client.i2c_read_buffer) {
dprintk("%s: not enough memory", __func__);
ret = -ENOMEM;
goto error_memory_read;
}
client.i2c_buffer_lock = kzalloc(sizeof(struct mutex), GFP_KERNEL);
if (!client.i2c_buffer_lock) {
dprintk("%s: not enough memory", __func__);
ret = -ENOMEM;
goto error_memory_lock;
}
mutex_init(client.i2c_buffer_lock);
for (k = no_of_demods - 1; k >= 0; k--) {
new_addr = first_addr + (k << 1);
client.addr = new_addr;
if (!is_dib8096p)
dib8000_i2c_write16(&client, 1287, 0x0003);
if (dib8000_identify(&client) == 0) {
if (!is_dib8096p)
dib8000_i2c_write16(&client, 1287, 0x0003);
client.addr = default_addr;
if (dib8000_identify(&client) == 0) {
dprintk("#%d: not identified", k);
ret = -EINVAL;
goto error;
}
}
dib8000_i2c_write16(&client, 1286, (1 << 10) | (4 << 6));
dib8000_i2c_write16(&client, 1285, (new_addr << 2) | 0x2);
client.addr = new_addr;
dib8000_identify(&client);
dprintk("IC %d initialized (to i2c_address 0x%x)", k, new_addr);
}
for (k = 0; k < no_of_demods; k++) {
new_addr = first_addr | (k << 1);
client.addr = new_addr;
dib8000_i2c_write16(&client, 1285, new_addr << 2);
dib8000_i2c_write16(&client, 1286, 0);
}
error:
kfree(client.i2c_buffer_lock);
error_memory_lock:
kfree(client.i2c_read_buffer);
error_memory_read:
kfree(client.i2c_write_buffer);
return ret;
}
static int dib8000_fe_get_tune_settings(struct dvb_frontend *fe, struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
tune->step_size = 0;
tune->max_drift = 0;
return 0;
}
static void dib8000_release(struct dvb_frontend *fe)
{
struct dib8000_state *st = fe->demodulator_priv;
u8 index_frontend;
for (index_frontend = 1; (index_frontend < MAX_NUMBER_OF_FRONTENDS) && (st->fe[index_frontend] != NULL); index_frontend++)
dvb_frontend_detach(st->fe[index_frontend]);
dibx000_exit_i2c_master(&st->i2c_master);
i2c_del_adapter(&st->dib8096p_tuner_adap);
kfree(st->fe[0]);
kfree(st);
}
struct i2c_adapter *dib8000_get_i2c_master(struct dvb_frontend *fe, enum dibx000_i2c_interface intf, int gating)
{
struct dib8000_state *st = fe->demodulator_priv;
return dibx000_get_i2c_adapter(&st->i2c_master, intf, gating);
}
int dib8000_pid_filter_ctrl(struct dvb_frontend *fe, u8 onoff)
{
struct dib8000_state *st = fe->demodulator_priv;
u16 val = dib8000_read_word(st, 299) & 0xffef;
val |= (onoff & 0x1) << 4;
dprintk("pid filter enabled %d", onoff);
return dib8000_write_word(st, 299, val);
}
int dib8000_pid_filter(struct dvb_frontend *fe, u8 id, u16 pid, u8 onoff)
{
struct dib8000_state *st = fe->demodulator_priv;
dprintk("Index %x, PID %d, OnOff %d", id, pid, onoff);
return dib8000_write_word(st, 305 + id, onoff ? (1 << 13) | pid : 0);
}
struct dvb_frontend *dib8000_attach(struct i2c_adapter *i2c_adap, u8 i2c_addr, struct dib8000_config *cfg)
{
struct dvb_frontend *fe;
struct dib8000_state *state;
dprintk("dib8000_attach");
state = kzalloc(sizeof(struct dib8000_state), GFP_KERNEL);
if (state == NULL)
return NULL;
fe = kzalloc(sizeof(struct dvb_frontend), GFP_KERNEL);
if (fe == NULL)
goto error;
memcpy(&state->cfg, cfg, sizeof(struct dib8000_config));
state->i2c.adap = i2c_adap;
state->i2c.addr = i2c_addr;
state->i2c.i2c_write_buffer = state->i2c_write_buffer;
state->i2c.i2c_read_buffer = state->i2c_read_buffer;
mutex_init(&state->i2c_buffer_lock);
state->i2c.i2c_buffer_lock = &state->i2c_buffer_lock;
state->gpio_val = cfg->gpio_val;
state->gpio_dir = cfg->gpio_dir;
if ((state->cfg.output_mode != OUTMODE_MPEG2_SERIAL) && (state->cfg.output_mode != OUTMODE_MPEG2_PAR_GATED_CLK))
state->cfg.output_mode = OUTMODE_MPEG2_FIFO;
state->fe[0] = fe;
fe->demodulator_priv = state;
memcpy(&state->fe[0]->ops, &dib8000_ops, sizeof(struct dvb_frontend_ops));
state->timf_default = cfg->pll->timf;
if (dib8000_identify(&state->i2c) == 0)
goto error;
dibx000_init_i2c_master(&state->i2c_master, DIB8000, state->i2c.adap, state->i2c.addr);
strncpy(state->dib8096p_tuner_adap.name, "DiB8096P tuner interface",
sizeof(state->dib8096p_tuner_adap.name));
state->dib8096p_tuner_adap.algo = &dib8096p_tuner_xfer_algo;
state->dib8096p_tuner_adap.algo_data = NULL;
state->dib8096p_tuner_adap.dev.parent = state->i2c.adap->dev.parent;
i2c_set_adapdata(&state->dib8096p_tuner_adap, state);
i2c_add_adapter(&state->dib8096p_tuner_adap);
dib8000_reset(fe);
dib8000_write_word(state, 285, (dib8000_read_word(state, 285) & ~0x60) | (3 << 5));
return fe;
error:
kfree(state);
return NULL;
}
