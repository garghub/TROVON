void
ia_css_bnr_encode(
struct sh_css_isp_bnr_params *to,
const struct ia_css_nr_config *from,
unsigned size)
{
(void)size;
to->threshold_low =
uDIGIT_FITTING(from->direction, 16, SH_CSS_BAYER_BITS);
to->threshold_width_log2 = uFRACTION_BITS_FITTING(8);
to->threshold_width =
1 << to->threshold_width_log2;
to->gain_all =
uDIGIT_FITTING(from->bnr_gain, 16, SH_CSS_BNR_GAIN_SHIFT);
to->gain_dir =
uDIGIT_FITTING(from->bnr_gain, 16, SH_CSS_BNR_GAIN_SHIFT);
to->clip = uDIGIT_FITTING((unsigned)16384, 16, SH_CSS_BAYER_BITS);
}
void
ia_css_bnr_dump(
const struct sh_css_isp_bnr_params *bnr,
unsigned level)
{
if (!bnr) return;
ia_css_debug_dtrace(level, "Bayer Noise Reduction:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_gain_all", bnr->gain_all);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_gain_dir", bnr->gain_dir);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_threshold_low",
bnr->threshold_low);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_threshold_width_log2",
bnr->threshold_width_log2);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_threshold_width",
bnr->threshold_width);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"bnr_clip", bnr->clip);
}
