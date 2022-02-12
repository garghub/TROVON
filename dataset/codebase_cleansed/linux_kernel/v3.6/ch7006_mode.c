struct ch7006_mode *ch7006_lookup_mode(struct drm_encoder *encoder,
const struct drm_display_mode *drm_mode)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_mode *mode;
for (mode = ch7006_modes; mode->mode.clock; mode++) {
if (~mode->valid_norms & 1<<priv->norm)
continue;
if (mode->mode.hdisplay != drm_mode->hdisplay ||
mode->mode.vdisplay != drm_mode->vdisplay ||
mode->mode.vtotal != drm_mode->vtotal ||
mode->mode.htotal != drm_mode->htotal ||
mode->mode.clock != drm_mode->clock)
continue;
return mode;
}
return NULL;
}
void ch7006_setup_levels(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
uint8_t *regs = priv->state.regs;
struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
int gain;
int black_level;
if (norm->black_level < 339*fixed1/1000) {
gain = 76;
regs[CH7006_INPUT_FORMAT] |= CH7006_INPUT_FORMAT_DAC_GAIN;
} else {
gain = 71;
regs[CH7006_INPUT_FORMAT] &= ~CH7006_INPUT_FORMAT_DAC_GAIN;
}
black_level = round_fixed(norm->black_level*26625)/gain;
black_level = interpolate(90, black_level, 208, priv->brightness);
regs[CH7006_BLACK_LEVEL] = bitf(CH7006_BLACK_LEVEL_0, black_level);
ch7006_dbg(client, "black level: %d\n", black_level);
}
void ch7006_setup_subcarrier(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_state *state = &priv->state;
struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
struct ch7006_mode *mode = priv->mode;
uint32_t subc_inc;
subc_inc = round_fixed((mode->subc_coeff >> 8)
* (norm->subc_freq >> 24));
setbitf(state, CH7006_SUBC_INC0, 28, subc_inc);
setbitf(state, CH7006_SUBC_INC1, 24, subc_inc);
setbitf(state, CH7006_SUBC_INC2, 20, subc_inc);
setbitf(state, CH7006_SUBC_INC3, 16, subc_inc);
setbitf(state, CH7006_SUBC_INC4, 12, subc_inc);
setbitf(state, CH7006_SUBC_INC5, 8, subc_inc);
setbitf(state, CH7006_SUBC_INC6, 4, subc_inc);
setbitf(state, CH7006_SUBC_INC7, 0, subc_inc);
ch7006_dbg(client, "subcarrier inc: %u\n", subc_inc);
}
void ch7006_setup_pll(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
uint8_t *regs = priv->state.regs;
struct ch7006_mode *mode = priv->mode;
int n, best_n = 0;
int m, best_m = 0;
int freq, best_freq = 0;
for (n = 0; n < CH7006_MAXN; n++) {
for (m = 0; m < CH7006_MAXM; m++) {
freq = CH7006_FREQ0*(n+2)/(m+2);
if (abs(freq - mode->mode.clock) <
abs(best_freq - mode->mode.clock)) {
best_freq = freq;
best_n = n;
best_m = m;
}
}
}
regs[CH7006_PLLOV] = bitf(CH7006_PLLOV_N_8, best_n) |
bitf(CH7006_PLLOV_M_8, best_m);
regs[CH7006_PLLM] = bitf(CH7006_PLLM_0, best_m);
regs[CH7006_PLLN] = bitf(CH7006_PLLN_0, best_n);
if (best_n < 108)
regs[CH7006_PLL_CONTROL] |= CH7006_PLL_CONTROL_CAPACITOR;
else
regs[CH7006_PLL_CONTROL] &= ~CH7006_PLL_CONTROL_CAPACITOR;
ch7006_dbg(client, "n=%d m=%d f=%d c=%d\n",
best_n, best_m, best_freq, best_n < 108);
}
void ch7006_setup_power_state(struct drm_encoder *encoder)
{
struct ch7006_priv *priv = to_ch7006_priv(encoder);
uint8_t *power = &priv->state.regs[CH7006_POWER];
int subconnector;
subconnector = priv->select_subconnector ? priv->select_subconnector :
priv->subconnector;
*power = CH7006_POWER_RESET;
if (priv->last_dpms == DRM_MODE_DPMS_ON) {
switch (subconnector) {
case DRM_MODE_SUBCONNECTOR_SVIDEO:
*power |= bitfs(CH7006_POWER_LEVEL, CVBS_OFF);
break;
case DRM_MODE_SUBCONNECTOR_Composite:
*power |= bitfs(CH7006_POWER_LEVEL, SVIDEO_OFF);
break;
case DRM_MODE_SUBCONNECTOR_SCART:
*power |= bitfs(CH7006_POWER_LEVEL, NORMAL) |
CH7006_POWER_SCART;
break;
}
} else {
if (priv->chip_version >= 0x20)
*power |= bitfs(CH7006_POWER_LEVEL, FULL_POWER_OFF);
else
*power |= bitfs(CH7006_POWER_LEVEL, POWER_OFF);
}
}
void ch7006_setup_properties(struct drm_encoder *encoder)
{
struct i2c_client *client = drm_i2c_encoder_get_client(encoder);
struct ch7006_priv *priv = to_ch7006_priv(encoder);
struct ch7006_state *state = &priv->state;
struct ch7006_tv_norm_info *norm = &ch7006_tv_norms[priv->norm];
struct ch7006_mode *ch_mode = priv->mode;
struct drm_display_mode *mode = &ch_mode->mode;
uint8_t *regs = state->regs;
int flicker, contrast, hpos, vpos;
uint64_t scale, aspect;
flicker = interpolate(0, 2, 3, priv->flicker);
regs[CH7006_FFILTER] = bitf(CH7006_FFILTER_TEXT, flicker) |
bitf(CH7006_FFILTER_LUMA, flicker) |
bitf(CH7006_FFILTER_CHROMA, 1);
contrast = interpolate(0, 5, 7, priv->contrast);
regs[CH7006_CONTRAST] = bitf(CH7006_CONTRAST_0, contrast);
scale = norm->vtotal*fixed1;
do_div(scale, mode->vtotal);
aspect = ch_mode->enc_hdisp*fixed1;
do_div(aspect, ch_mode->enc_vdisp);
hpos = round_fixed((norm->hvirtual * aspect - mode->hdisplay * scale)
* priv->hmargin * mode->vtotal) / norm->vtotal / 100 / 4;
setbitf(state, CH7006_POV, HPOS_8, hpos);
setbitf(state, CH7006_HPOS, 0, hpos);
vpos = max(0, norm->vdisplay - round_fixed(mode->vdisplay*scale)
+ norm->voffset) * priv->vmargin / 100 / 2;
setbitf(state, CH7006_POV, VPOS_8, vpos);
setbitf(state, CH7006_VPOS, 0, vpos);
ch7006_dbg(client, "hpos: %d, vpos: %d\n", hpos, vpos);
}
void ch7006_write(struct i2c_client *client, uint8_t addr, uint8_t val)
{
uint8_t buf[] = {addr, val};
int ret;
ret = i2c_master_send(client, buf, ARRAY_SIZE(buf));
if (ret < 0)
ch7006_err(client, "Error %d writing to subaddress 0x%x\n",
ret, addr);
}
uint8_t ch7006_read(struct i2c_client *client, uint8_t addr)
{
uint8_t val;
int ret;
ret = i2c_master_send(client, &addr, sizeof(addr));
if (ret < 0)
goto fail;
ret = i2c_master_recv(client, &val, sizeof(val));
if (ret < 0)
goto fail;
return val;
fail:
ch7006_err(client, "Error %d reading from subaddress 0x%x\n",
ret, addr);
return 0;
}
void ch7006_state_load(struct i2c_client *client,
struct ch7006_state *state)
{
ch7006_load_reg(client, state, CH7006_POWER);
ch7006_load_reg(client, state, CH7006_DISPMODE);
ch7006_load_reg(client, state, CH7006_FFILTER);
ch7006_load_reg(client, state, CH7006_BWIDTH);
ch7006_load_reg(client, state, CH7006_INPUT_FORMAT);
ch7006_load_reg(client, state, CH7006_CLKMODE);
ch7006_load_reg(client, state, CH7006_START_ACTIVE);
ch7006_load_reg(client, state, CH7006_POV);
ch7006_load_reg(client, state, CH7006_BLACK_LEVEL);
ch7006_load_reg(client, state, CH7006_HPOS);
ch7006_load_reg(client, state, CH7006_VPOS);
ch7006_load_reg(client, state, CH7006_INPUT_SYNC);
ch7006_load_reg(client, state, CH7006_DETECT);
ch7006_load_reg(client, state, CH7006_CONTRAST);
ch7006_load_reg(client, state, CH7006_PLLOV);
ch7006_load_reg(client, state, CH7006_PLLM);
ch7006_load_reg(client, state, CH7006_PLLN);
ch7006_load_reg(client, state, CH7006_BCLKOUT);
ch7006_load_reg(client, state, CH7006_SUBC_INC0);
ch7006_load_reg(client, state, CH7006_SUBC_INC1);
ch7006_load_reg(client, state, CH7006_SUBC_INC2);
ch7006_load_reg(client, state, CH7006_SUBC_INC3);
ch7006_load_reg(client, state, CH7006_SUBC_INC4);
ch7006_load_reg(client, state, CH7006_SUBC_INC5);
ch7006_load_reg(client, state, CH7006_SUBC_INC6);
ch7006_load_reg(client, state, CH7006_SUBC_INC7);
ch7006_load_reg(client, state, CH7006_PLL_CONTROL);
ch7006_load_reg(client, state, CH7006_CALC_SUBC_INC0);
}
void ch7006_state_save(struct i2c_client *client,
struct ch7006_state *state)
{
ch7006_save_reg(client, state, CH7006_POWER);
ch7006_save_reg(client, state, CH7006_DISPMODE);
ch7006_save_reg(client, state, CH7006_FFILTER);
ch7006_save_reg(client, state, CH7006_BWIDTH);
ch7006_save_reg(client, state, CH7006_INPUT_FORMAT);
ch7006_save_reg(client, state, CH7006_CLKMODE);
ch7006_save_reg(client, state, CH7006_START_ACTIVE);
ch7006_save_reg(client, state, CH7006_POV);
ch7006_save_reg(client, state, CH7006_BLACK_LEVEL);
ch7006_save_reg(client, state, CH7006_HPOS);
ch7006_save_reg(client, state, CH7006_VPOS);
ch7006_save_reg(client, state, CH7006_INPUT_SYNC);
ch7006_save_reg(client, state, CH7006_DETECT);
ch7006_save_reg(client, state, CH7006_CONTRAST);
ch7006_save_reg(client, state, CH7006_PLLOV);
ch7006_save_reg(client, state, CH7006_PLLM);
ch7006_save_reg(client, state, CH7006_PLLN);
ch7006_save_reg(client, state, CH7006_BCLKOUT);
ch7006_save_reg(client, state, CH7006_SUBC_INC0);
ch7006_save_reg(client, state, CH7006_SUBC_INC1);
ch7006_save_reg(client, state, CH7006_SUBC_INC2);
ch7006_save_reg(client, state, CH7006_SUBC_INC3);
ch7006_save_reg(client, state, CH7006_SUBC_INC4);
ch7006_save_reg(client, state, CH7006_SUBC_INC5);
ch7006_save_reg(client, state, CH7006_SUBC_INC6);
ch7006_save_reg(client, state, CH7006_SUBC_INC7);
ch7006_save_reg(client, state, CH7006_PLL_CONTROL);
ch7006_save_reg(client, state, CH7006_CALC_SUBC_INC0);
state->regs[CH7006_FFILTER] = (state->regs[CH7006_FFILTER] & 0xf0) |
(state->regs[CH7006_FFILTER] & 0x0c) >> 2 |
(state->regs[CH7006_FFILTER] & 0x03) << 2;
}
