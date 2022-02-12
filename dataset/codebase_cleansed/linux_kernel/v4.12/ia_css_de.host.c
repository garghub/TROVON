void
ia_css_de_encode(
struct sh_css_isp_de_params *to,
const struct ia_css_de_config *from,
unsigned size)
{
(void)size;
to->pixelnoise =
uDIGIT_FITTING(from->pixelnoise, 16, SH_CSS_BAYER_BITS);
to->c1_coring_threshold =
uDIGIT_FITTING(from->c1_coring_threshold, 16,
SH_CSS_BAYER_BITS);
to->c2_coring_threshold =
uDIGIT_FITTING(from->c2_coring_threshold, 16,
SH_CSS_BAYER_BITS);
}
void
ia_css_de_dump(
const struct sh_css_isp_de_params *de,
unsigned level)
{
if (!de) return;
ia_css_debug_dtrace(level, "Demosaic:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"de_pixelnoise", de->pixelnoise);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"de_c1_coring_threshold",
de->c1_coring_threshold);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"de_c2_coring_threshold",
de->c2_coring_threshold);
}
void
ia_css_de_debug_dtrace(
const struct ia_css_de_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.pixelnoise=%d, "
"config.c1_coring_threshold=%d, config.c2_coring_threshold=%d\n",
config->pixelnoise,
config->c1_coring_threshold, config->c2_coring_threshold);
}
void
ia_css_init_de_state(
void *state,
size_t size)
{
memset(state, 0, size);
}
