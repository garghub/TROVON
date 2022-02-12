void dss_init_hdmi_ip_ops(struct hdmi_ip_data *ip_data)
{
if (cpu_is_omap44xx())
ip_data->ops = &omap4_hdmi_functions;
}
int dss_feat_get_num_mgrs(void)
{
return omap_current_dss_features->num_mgrs;
}
int dss_feat_get_num_ovls(void)
{
return omap_current_dss_features->num_ovls;
}
unsigned long dss_feat_get_param_min(enum dss_range_param param)
{
return omap_current_dss_features->dss_params[param].min;
}
unsigned long dss_feat_get_param_max(enum dss_range_param param)
{
return omap_current_dss_features->dss_params[param].max;
}
enum omap_display_type dss_feat_get_supported_displays(enum omap_channel channel)
{
return omap_current_dss_features->supported_displays[channel];
}
enum omap_color_mode dss_feat_get_supported_color_modes(enum omap_plane plane)
{
return omap_current_dss_features->supported_color_modes[plane];
}
enum omap_overlay_caps dss_feat_get_overlay_caps(enum omap_plane plane)
{
return omap_current_dss_features->overlay_caps[plane];
}
bool dss_feat_color_mode_supported(enum omap_plane plane,
enum omap_color_mode color_mode)
{
return omap_current_dss_features->supported_color_modes[plane] &
color_mode;
}
const char *dss_feat_get_clk_source_name(enum omap_dss_clk_source id)
{
return omap_current_dss_features->clksrc_names[id];
}
u32 dss_feat_get_buffer_size_unit(void)
{
return omap_current_dss_features->buffer_size_unit;
}
u32 dss_feat_get_burst_size_unit(void)
{
return omap_current_dss_features->burst_size_unit;
}
bool dss_has_feature(enum dss_feat_id id)
{
int i;
const enum dss_feat_id *features = omap_current_dss_features->features;
const int num_features = omap_current_dss_features->num_features;
for (i = 0; i < num_features; i++) {
if (features[i] == id)
return true;
}
return false;
}
void dss_feat_get_reg_field(enum dss_feat_reg_field id, u8 *start, u8 *end)
{
if (id >= omap_current_dss_features->num_reg_fields)
BUG();
*start = omap_current_dss_features->reg_fields[id].start;
*end = omap_current_dss_features->reg_fields[id].end;
}
bool dss_feat_rotation_type_supported(enum omap_dss_rotation_type rot_type)
{
return omap_current_dss_features->supported_rotation_types & rot_type;
}
void dss_features_init(void)
{
if (cpu_is_omap24xx())
omap_current_dss_features = &omap2_dss_features;
else if (cpu_is_omap3630())
omap_current_dss_features = &omap3630_dss_features;
else if (cpu_is_omap34xx())
omap_current_dss_features = &omap3430_dss_features;
else if (omap_rev() == OMAP4430_REV_ES1_0)
omap_current_dss_features = &omap4430_es1_0_dss_features;
else if (omap_rev() == OMAP4430_REV_ES2_0 ||
omap_rev() == OMAP4430_REV_ES2_1 ||
omap_rev() == OMAP4430_REV_ES2_2)
omap_current_dss_features = &omap4430_es2_0_1_2_dss_features;
else if (cpu_is_omap44xx())
omap_current_dss_features = &omap4_dss_features;
else
DSSWARN("Unsupported OMAP version");
}
