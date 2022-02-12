void
ia_css_macc_encode(
struct sh_css_isp_macc_params *to,
const struct ia_css_macc_config *from,
unsigned size)
{
(void)size;
to->exp = from->exp;
}
void
ia_css_macc_debug_dtrace(
const struct ia_css_macc_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.exp=%d\n",
config->exp);
}
