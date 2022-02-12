void
ia_css_xnr_table_vamem_encode(
struct sh_css_isp_xnr_vamem_params *to,
const struct ia_css_xnr_table *from,
unsigned size)
{
(void)size;
memcpy (&to->xnr, &from->data, sizeof(to->xnr));
}
void
ia_css_xnr_encode(
struct sh_css_isp_xnr_params *to,
const struct ia_css_xnr_config *from,
unsigned size)
{
(void)size;
to->threshold =
(uint16_t)uDIGIT_FITTING(from->threshold, 16, SH_CSS_ISP_YUV_BITS);
}
void
ia_css_xnr_table_debug_dtrace(
const struct ia_css_xnr_table *config,
unsigned level)
{
(void)config;
(void)level;
}
void
ia_css_xnr_debug_dtrace(
const struct ia_css_xnr_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.threshold=%d\n", config->threshold);
}
