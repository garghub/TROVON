int tda18271_lookup_thermometer(struct dvb_frontend *fe)
{
struct tda18271_priv *priv = fe->tuner_priv;
unsigned char *regs = priv->tda18271_regs;
int val, i = 0;
while (tda18271_thermometer[i].d < (regs[R_TM] & 0x0f)) {
if (tda18271_thermometer[i + 1].d == 0)
break;
i++;
}
if ((regs[R_TM] & 0x20) == 0x20)
val = tda18271_thermometer[i].r1;
else
val = tda18271_thermometer[i].r0;
tda_map("(%d) tm = %d\n", i, val);
return val;
}
int tda18271_lookup_cid_target(struct dvb_frontend *fe,
u32 *freq, u8 *cid_target, u16 *count_limit)
{
struct tda18271_priv *priv = fe->tuner_priv;
int i = 0;
while ((tda18271_cid_target[i].rfmax * 1000) < *freq) {
if (tda18271_cid_target[i + 1].rfmax == 0)
break;
i++;
}
*cid_target = tda18271_cid_target[i].target;
*count_limit = tda18271_cid_target[i].limit;
tda_map("(%d) cid_target = %02x, count_limit = %d\n", i,
tda18271_cid_target[i].target, tda18271_cid_target[i].limit);
return 0;
}
int tda18271_lookup_rf_band(struct dvb_frontend *fe, u32 *freq, u8 *rf_band)
{
struct tda18271_priv *priv = fe->tuner_priv;
struct tda18271_rf_tracking_filter_cal *map = priv->rf_cal_state;
int i = 0;
while ((map[i].rfmax * 1000) < *freq) {
if (tda18271_debug & DBG_ADV)
tda_map("(%d) rfmax = %d < freq = %d, "
"rf1_def = %d, rf2_def = %d, rf3_def = %d, "
"rf1 = %d, rf2 = %d, rf3 = %d, "
"rf_a1 = %d, rf_a2 = %d, "
"rf_b1 = %d, rf_b2 = %d\n",
i, map[i].rfmax * 1000, *freq,
map[i].rf1_def, map[i].rf2_def, map[i].rf3_def,
map[i].rf1, map[i].rf2, map[i].rf3,
map[i].rf_a1, map[i].rf_a2,
map[i].rf_b1, map[i].rf_b2);
if (map[i].rfmax == 0)
return -EINVAL;
i++;
}
if (rf_band)
*rf_band = map[i].rfband;
tda_map("(%d) rf_band = %02x\n", i, map[i].rfband);
return i;
}
int tda18271_lookup_pll_map(struct dvb_frontend *fe,
enum tda18271_map_type map_type,
u32 *freq, u8 *post_div, u8 *div)
{
struct tda18271_priv *priv = fe->tuner_priv;
struct tda18271_pll_map *map = NULL;
unsigned int i = 0;
char *map_name;
int ret = 0;
BUG_ON(!priv->maps);
switch (map_type) {
case MAIN_PLL:
map = priv->maps->main_pll;
map_name = "main_pll";
break;
case CAL_PLL:
map = priv->maps->cal_pll;
map_name = "cal_pll";
break;
default:
map_name = "undefined";
break;
}
if (!map) {
tda_warn("%s map is not set!\n", map_name);
ret = -EINVAL;
goto fail;
}
while ((map[i].lomax * 1000) < *freq) {
if (map[i + 1].lomax == 0) {
tda_map("%s: frequency (%d) out of range\n",
map_name, *freq);
ret = -ERANGE;
break;
}
i++;
}
*post_div = map[i].pd;
*div = map[i].d;
tda_map("(%d) %s: post div = 0x%02x, div = 0x%02x\n",
i, map_name, *post_div, *div);
fail:
return ret;
}
int tda18271_lookup_map(struct dvb_frontend *fe,
enum tda18271_map_type map_type,
u32 *freq, u8 *val)
{
struct tda18271_priv *priv = fe->tuner_priv;
struct tda18271_map *map = NULL;
unsigned int i = 0;
char *map_name;
int ret = 0;
BUG_ON(!priv->maps);
switch (map_type) {
case BP_FILTER:
map = priv->maps->bp_filter;
map_name = "bp_filter";
break;
case RF_CAL_KMCO:
map = priv->maps->rf_cal_kmco;
map_name = "km";
break;
case RF_BAND:
map = priv->maps->rf_band;
map_name = "rf_band";
break;
case GAIN_TAPER:
map = priv->maps->gain_taper;
map_name = "gain_taper";
break;
case RF_CAL:
map = priv->maps->rf_cal;
map_name = "rf_cal";
break;
case IR_MEASURE:
map = priv->maps->ir_measure;
map_name = "ir_measure";
break;
case RF_CAL_DC_OVER_DT:
map = priv->maps->rf_cal_dc_over_dt;
map_name = "rf_cal_dc_over_dt";
break;
default:
map_name = "undefined";
break;
}
if (!map) {
tda_warn("%s map is not set!\n", map_name);
ret = -EINVAL;
goto fail;
}
while ((map[i].rfmax * 1000) < *freq) {
if (map[i + 1].rfmax == 0) {
tda_map("%s: frequency (%d) out of range\n",
map_name, *freq);
ret = -ERANGE;
break;
}
i++;
}
*val = map[i].val;
tda_map("(%d) %s: 0x%02x\n", i, map_name, *val);
fail:
return ret;
}
int tda18271_assign_map_layout(struct dvb_frontend *fe)
{
struct tda18271_priv *priv = fe->tuner_priv;
int ret = 0;
switch (priv->id) {
case TDA18271HDC1:
priv->maps = &tda18271c1_map_layout;
priv->std = tda18271c1_std_map;
break;
case TDA18271HDC2:
priv->maps = &tda18271c2_map_layout;
priv->std = tda18271c2_std_map;
break;
default:
ret = -EINVAL;
break;
}
memcpy(priv->rf_cal_state, &tda18271_rf_band_template,
sizeof(tda18271_rf_band_template));
return ret;
}
