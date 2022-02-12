void
ia_css_ctc_vamem_encode(
struct sh_css_isp_ctc_vamem_params *to,
const struct ia_css_ctc_table *from,
unsigned size)
{
(void)size;
memcpy (&to->ctc, &from->data, sizeof(to->ctc));
}
void
ia_css_ctc_debug_dtrace(
const struct ia_css_ctc_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.ce_gain_exp=%d, config.y0=%d, "
"config.x1=%d, config.y1=%d, "
"config.x2=%d, config.y2=%d, "
"config.x3=%d, config.y3=%d, "
"config.x4=%d, config.y4=%d\n",
config->ce_gain_exp, config->y0,
config->x1, config->y1,
config->x2, config->y2,
config->x3, config->y3,
config->x4, config->y4);
}
