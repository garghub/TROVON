void
ia_css_sc_encode(
struct sh_css_isp_sc_params *to,
struct ia_css_shading_table **from,
unsigned size)
{
(void)size;
to->gain_shift = (*from)->fraction_bits;
}
void
ia_css_sc_dump(
const struct sh_css_isp_sc_params *sc,
unsigned level)
{
if (!sc) return;
ia_css_debug_dtrace(level, "Shading Correction:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"sc_gain_shift", sc->gain_shift);
}
void
ia_css_sc_config(
struct sh_css_isp_sc_isp_config *to,
const struct ia_css_sc_configuration *from,
unsigned size)
{
uint32_t internal_org_x_bqs = from->internal_frame_origin_x_bqs_on_sctbl;
uint32_t internal_org_y_bqs = from->internal_frame_origin_y_bqs_on_sctbl;
uint32_t slice, rest, i;
(void)size;
rest = internal_org_x_bqs;
for (i = 0; i < SH_CSS_SC_INTERPED_GAIN_HOR_SLICE_TIMES; i++) {
slice = min(rest, ((uint32_t)ISP_SLICE_NELEMS));
rest = rest - slice;
to->interped_gain_hor_slice_bqs[i] = slice;
}
to->internal_frame_origin_y_bqs_on_sctbl = internal_org_y_bqs;
}
void
ia_css_sc_configure(
const struct ia_css_binary *binary,
uint32_t internal_frame_origin_x_bqs_on_sctbl,
uint32_t internal_frame_origin_y_bqs_on_sctbl)
{
const struct ia_css_sc_configuration config = {
internal_frame_origin_x_bqs_on_sctbl,
internal_frame_origin_y_bqs_on_sctbl };
ia_css_configure_sc(binary, &config);
}
void
sh_css_get_shading_settings(const struct ia_css_isp_parameters *params,
struct ia_css_shading_settings *settings)
{
if (settings == NULL)
return;
assert(params != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_get_shading_settings() enter: settings=%p\n", settings);
*settings = params->shading_settings;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_get_shading_settings() leave: settings.enable_shading_table_conversion=%d\n",
settings->enable_shading_table_conversion);
}
void
sh_css_set_shading_settings(struct ia_css_isp_parameters *params,
const struct ia_css_shading_settings *settings)
{
if (settings == NULL)
return;
assert(params != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_set_shading_settings() enter: settings.enable_shading_table_conversion=%d\n",
settings->enable_shading_table_conversion);
params->shading_settings = *settings;
params->shading_settings_changed = true;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_set_shading_settings() leave: return_void\n");
}
