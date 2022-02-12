void
ia_css_anr_encode(
struct sh_css_isp_anr_params *to,
const struct ia_css_anr_config *from,
unsigned size)
{
(void)size;
to->threshold = from->threshold;
}
void
ia_css_anr_dump(
const struct sh_css_isp_anr_params *anr,
unsigned level)
{
if (!anr) return;
ia_css_debug_dtrace(level, "Advance Noise Reduction:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"anr_threshold", anr->threshold);
}
void
ia_css_anr_debug_dtrace(
const struct ia_css_anr_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.threshold=%d\n",
config->threshold);
}
