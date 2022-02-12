void
ia_css_wb_encode(
struct sh_css_isp_wb_params *to,
const struct ia_css_wb_config *from,
unsigned size)
{
(void)size;
to->gain_shift =
uISP_REG_BIT - from->integer_bits;
to->gain_gr =
uDIGIT_FITTING(from->gr, 16 - from->integer_bits,
to->gain_shift);
to->gain_r =
uDIGIT_FITTING(from->r, 16 - from->integer_bits,
to->gain_shift);
to->gain_b =
uDIGIT_FITTING(from->b, 16 - from->integer_bits,
to->gain_shift);
to->gain_gb =
uDIGIT_FITTING(from->gb, 16 - from->integer_bits,
to->gain_shift);
}
void
ia_css_wb_dump(
const struct sh_css_isp_wb_params *wb,
unsigned level)
{
if (!wb) return;
ia_css_debug_dtrace(level, "White Balance:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"wb_gain_shift", wb->gain_shift);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"wb_gain_gr", wb->gain_gr);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"wb_gain_r", wb->gain_r);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"wb_gain_b", wb->gain_b);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"wb_gain_gb", wb->gain_gb);
}
void
ia_css_wb_debug_dtrace(
const struct ia_css_wb_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.integer_bits=%d, "
"config.gr=%d, config.r=%d, "
"config.b=%d, config.gb=%d\n",
config->integer_bits,
config->gr, config->r,
config->b, config->gb);
}
