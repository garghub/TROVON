void
ia_css_tnr_encode(
struct sh_css_isp_tnr_params *to,
const struct ia_css_tnr_config *from,
unsigned size)
{
(void)size;
to->coef =
uDIGIT_FITTING(from->gain, 16, SH_CSS_TNR_COEF_SHIFT);
to->threshold_Y =
uDIGIT_FITTING(from->threshold_y, 16, SH_CSS_ISP_YUV_BITS);
to->threshold_C =
uDIGIT_FITTING(from->threshold_uv, 16, SH_CSS_ISP_YUV_BITS);
}
void
ia_css_tnr_dump(
const struct sh_css_isp_tnr_params *tnr,
unsigned level)
{
if (!tnr) return;
ia_css_debug_dtrace(level, "Temporal Noise Reduction:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"tnr_coef", tnr->coef);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"tnr_threshold_Y", tnr->threshold_Y);
ia_css_debug_dtrace(level, "\t%-32s = %d\n"
"tnr_threshold_C", tnr->threshold_C);
}
void
ia_css_tnr_debug_dtrace(
const struct ia_css_tnr_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.gain=%d, "
"config.threshold_y=%d, config.threshold_uv=%d\n",
config->gain,
config->threshold_y, config->threshold_uv);
}
void
ia_css_tnr_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame **frames)
{
struct ia_css_tnr_configuration config;
unsigned i;
#ifndef ISP2401
for (i = 0; i < NUM_VIDEO_TNR_FRAMES; i++)
#else
for (i = 0; i < NUM_TNR_FRAMES; i++)
#endif
config.tnr_frames[i] = frames[i];
ia_css_configure_tnr(binary, &config);
}
void
ia_css_init_tnr_state(
struct sh_css_isp_tnr_dmem_state *state,
size_t size)
{
(void)size;
#ifndef ISP2401
assert(NUM_VIDEO_TNR_FRAMES >= 2);
#endif
assert(sizeof(*state) == size);
state->tnr_in_buf_idx = 0;
state->tnr_out_buf_idx = 1;
}
