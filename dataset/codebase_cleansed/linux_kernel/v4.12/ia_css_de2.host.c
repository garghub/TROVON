void
ia_css_ecd_encode(
struct sh_css_isp_ecd_params *to,
const struct ia_css_ecd_config *from,
unsigned size)
{
(void)size;
to->zip_strength = from->zip_strength;
to->fc_strength = from->fc_strength;
to->fc_debias = from->fc_debias;
}
void
ia_css_ecd_debug_dtrace(
const struct ia_css_ecd_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.zip_strength=%d, "
"config.fc_strength=%d, config.fc_debias=%d\n",
config->zip_strength,
config->fc_strength, config->fc_debias);
}
