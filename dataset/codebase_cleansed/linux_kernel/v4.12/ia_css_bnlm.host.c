static inline void
bnlm_lut_encode(struct bnlm_lut *lut, const int32_t *lut_thr, const int32_t *lut_val, const uint32_t lut_size)
{
u32 blk, i;
const u32 block_size = 16;
const u32 total_blocks = ISP_VEC_NELEMS / block_size;
assert((lut_size >= 2) && (lut_size <= block_size));
for (i = 0; i < lut_size-2; i++) {
assert(lut_thr[i] <= lut_thr[i+1]);
}
for (i = 0; i < total_blocks * block_size; i++) {
lut->thr[0][i] = 0;
lut->val[0][i] = 0;
}
for (i = 0; i < lut_size - 1; i++) {
lut->thr[0][i] = lut_thr[i];
lut->val[0][i] = lut_val[i];
}
lut->val[0][i] = lut_val[i];
for (blk = 1; blk < total_blocks; blk++) {
u32 blk_offset = blk * block_size;
for (i = 1; i < lut_size; i++) {
lut->thr[0][blk_offset + i] = lut->thr[0][i];
lut->val[0][blk_offset + i] = lut->val[0][i];
}
}
}
void
ia_css_bnlm_vmem_encode(
struct bnlm_vmem_params *to,
const struct ia_css_bnlm_config *from,
size_t size)
{
int i;
(void)size;
bnlm_lut_encode(&to->mu_root_lut, from->mu_root_lut_thr, from->mu_root_lut_val, 16);
bnlm_lut_encode(&to->sad_norm_lut, from->sad_norm_lut_thr, from->sad_norm_lut_val, 16);
bnlm_lut_encode(&to->sig_detail_lut, from->sig_detail_lut_thr, from->sig_detail_lut_val, 16);
bnlm_lut_encode(&to->sig_rad_lut, from->sig_rad_lut_thr, from->sig_rad_lut_val, 16);
bnlm_lut_encode(&to->rad_pow_lut, from->rad_pow_lut_thr, from->rad_pow_lut_val, 16);
bnlm_lut_encode(&to->nl_0_lut, from->nl_0_lut_thr, from->nl_0_lut_val, 16);
bnlm_lut_encode(&to->nl_1_lut, from->nl_1_lut_thr, from->nl_1_lut_val, 16);
bnlm_lut_encode(&to->nl_2_lut, from->nl_2_lut_thr, from->nl_2_lut_val, 16);
bnlm_lut_encode(&to->nl_3_lut, from->nl_3_lut_thr, from->nl_3_lut_val, 16);
memset(to->nl_th, 0, sizeof(to->nl_th));
to->nl_th[0][0] = from->nl_th[0];
to->nl_th[0][1] = from->nl_th[1];
to->nl_th[0][2] = from->nl_th[2];
memset(to->match_quality_max_idx, 0, sizeof(to->match_quality_max_idx));
to->match_quality_max_idx[0][0] = from->match_quality_max_idx[0];
to->match_quality_max_idx[0][1] = from->match_quality_max_idx[1];
to->match_quality_max_idx[0][2] = from->match_quality_max_idx[2];
to->match_quality_max_idx[0][3] = from->match_quality_max_idx[3];
bnlm_lut_encode(&to->div_lut, div_lut_nearests, div_lut_slopes, BNLM_DIV_LUT_SIZE);
memset(to->div_lut_intercepts, 0, sizeof(to->div_lut_intercepts));
for(i = 0; i < BNLM_DIV_LUT_SIZE; i++) {
to->div_lut_intercepts[0][i] = div_lut_intercepts[i];
}
memset(to->power_of_2, 0, sizeof(to->power_of_2));
for (i = 0; i < (ISP_VEC_ELEMBITS-1); i++) {
to->power_of_2[0][i] = 1 << i;
}
}
void
ia_css_bnlm_encode(
struct bnlm_dmem_params *to,
const struct ia_css_bnlm_config *from,
size_t size)
{
(void)size;
to->rad_enable = from->rad_enable;
to->rad_x_origin = from->rad_x_origin;
to->rad_y_origin = from->rad_y_origin;
to->avg_min_th = from->avg_min_th;
to->max_min_th = from->max_min_th;
to->exp_coeff_a = from->exp_coeff_a;
to->exp_coeff_b = from->exp_coeff_b;
to->exp_coeff_c = from->exp_coeff_c;
to->exp_exponent = from->exp_exponent;
}
void
ia_css_bnlm_debug_trace(
const struct ia_css_bnlm_config *config,
unsigned level)
{
if (!config)
return;
#ifndef IA_CSS_NO_DEBUG
ia_css_debug_dtrace(level, "BNLM:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "rad_enable", config->rad_enable);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "rad_x_origin", config->rad_x_origin);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "rad_y_origin", config->rad_y_origin);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "avg_min_th", config->avg_min_th);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "max_min_th", config->max_min_th);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "exp_coeff_a", config->exp_coeff_a);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "exp_coeff_b", config->exp_coeff_b);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "exp_coeff_c", config->exp_coeff_c);
ia_css_debug_dtrace(level, "\t%-32s = %d\n", "exp_exponent", config->exp_exponent);
#endif
}
