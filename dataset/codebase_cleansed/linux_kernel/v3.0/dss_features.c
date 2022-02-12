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
bool dss_has_feature(enum dss_feat_id id)
{
return omap_current_dss_features->has_feature & id;
}
void dss_feat_get_reg_field(enum dss_feat_reg_field id, u8 *start, u8 *end)
{
if (id >= omap_current_dss_features->num_reg_fields)
BUG();
*start = omap_current_dss_features->reg_fields[id].start;
*end = omap_current_dss_features->reg_fields[id].end;
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
else if (cpu_is_omap44xx())
omap_current_dss_features = &omap4_dss_features;
else
DSSWARN("Unsupported OMAP version");
}
