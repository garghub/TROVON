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
enum omap_dss_output_id dss_feat_get_supported_outputs(enum omap_channel channel)
{
return omap_current_dss_features->supported_outputs[channel];
}
const u32 *dss_feat_get_supported_color_modes(enum omap_plane_id plane)
{
return omap_current_dss_features->supported_color_modes[plane];
}
enum omap_overlay_caps dss_feat_get_overlay_caps(enum omap_plane_id plane)
{
return omap_current_dss_features->overlay_caps[plane];
}
bool dss_feat_color_mode_supported(enum omap_plane_id plane, u32 fourcc)
{
const u32 *modes;
unsigned int i;
modes = omap_current_dss_features->supported_color_modes[plane];
for (i = 0; modes[i]; ++i) {
if (modes[i] == fourcc)
return true;
}
return false;
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
void dss_features_init(enum omapdss_version version)
{
switch (version) {
case OMAPDSS_VER_OMAP24xx:
omap_current_dss_features = &omap2_dss_features;
break;
case OMAPDSS_VER_OMAP34xx_ES1:
case OMAPDSS_VER_OMAP34xx_ES3:
omap_current_dss_features = &omap3430_dss_features;
break;
case OMAPDSS_VER_OMAP3630:
omap_current_dss_features = &omap3630_dss_features;
break;
case OMAPDSS_VER_OMAP4430_ES1:
omap_current_dss_features = &omap4430_es1_0_dss_features;
break;
case OMAPDSS_VER_OMAP4430_ES2:
omap_current_dss_features = &omap4430_es2_0_1_2_dss_features;
break;
case OMAPDSS_VER_OMAP4:
omap_current_dss_features = &omap4_dss_features;
break;
case OMAPDSS_VER_OMAP5:
case OMAPDSS_VER_DRA7xx:
omap_current_dss_features = &omap5_dss_features;
break;
case OMAPDSS_VER_AM35xx:
omap_current_dss_features = &am35xx_dss_features;
break;
case OMAPDSS_VER_AM43xx:
omap_current_dss_features = &am43xx_dss_features;
break;
default:
DSSWARN("Unsupported OMAP version");
break;
}
}
