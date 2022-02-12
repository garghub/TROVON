static int32_t
compute_alpha(int sigma)
{
int32_t alpha;
#if defined(XNR_ATE_ROUNDING_BUG)
int32_t alpha_unscaled;
#else
int offset = sigma / 2;
#endif
if (sigma < XNR_MIN_SIGMA) {
alpha = XNR_MAX_ALPHA;
} else {
#if defined(XNR_ATE_ROUNDING_BUG)
alpha_unscaled = IA_CSS_XNR3_SIGMA_SCALE / sigma;
alpha = alpha_unscaled * XNR_ALPHA_SCALE_FACTOR;
#else
alpha = ((IA_CSS_XNR3_SIGMA_SCALE * XNR_ALPHA_SCALE_FACTOR) + offset)/ sigma;
#endif
if (alpha > XNR_MAX_ALPHA)
alpha = XNR_MAX_ALPHA;
}
return alpha;
}
static int32_t
compute_coring(int coring)
{
int32_t isp_coring;
int32_t isp_scale = XNR_CORING_SCALE_FACTOR;
int32_t host_scale = IA_CSS_XNR3_CORING_SCALE;
int32_t offset = host_scale / 2;
isp_coring = ((coring * isp_scale) + offset) / host_scale;
return min(max(isp_coring, 0), isp_scale - 1);
}
static int32_t
compute_blending(int strength)
{
int32_t isp_strength;
int32_t isp_scale = XNR_BLENDING_SCALE_FACTOR;
int32_t host_scale = IA_CSS_XNR3_BLENDING_SCALE;
int32_t offset = host_scale / 2;
isp_strength = -(((strength * isp_scale) + offset) / host_scale);
return max(min(isp_strength, 0), -XNR_BLENDING_SCALE_FACTOR);
}
void
ia_css_xnr3_encode(
struct sh_css_isp_xnr3_params *to,
const struct ia_css_xnr3_config *from,
unsigned size)
{
int kernel_size = XNR_FILTER_SIZE;
int adjust_factor = ceil_pow2(kernel_size);
int32_t max_diff = (1 << (ISP_VEC_ELEMBITS - 1)) - 1;
int32_t min_diff = -(1 << (ISP_VEC_ELEMBITS - 1));
int32_t alpha_y0 = compute_alpha(from->sigma.y0);
int32_t alpha_y1 = compute_alpha(from->sigma.y1);
int32_t alpha_u0 = compute_alpha(from->sigma.u0);
int32_t alpha_u1 = compute_alpha(from->sigma.u1);
int32_t alpha_v0 = compute_alpha(from->sigma.v0);
int32_t alpha_v1 = compute_alpha(from->sigma.v1);
int32_t alpha_ydiff = (alpha_y1 - alpha_y0) * adjust_factor / kernel_size;
int32_t alpha_udiff = (alpha_u1 - alpha_u0) * adjust_factor / kernel_size;
int32_t alpha_vdiff = (alpha_v1 - alpha_v0) * adjust_factor / kernel_size;
int32_t coring_u0 = compute_coring(from->coring.u0);
int32_t coring_u1 = compute_coring(from->coring.u1);
int32_t coring_v0 = compute_coring(from->coring.v0);
int32_t coring_v1 = compute_coring(from->coring.v1);
int32_t coring_udiff = (coring_u1 - coring_u0) * adjust_factor / kernel_size;
int32_t coring_vdiff = (coring_v1 - coring_v0) * adjust_factor / kernel_size;
int32_t blending = compute_blending(from->blending.strength);
(void)size;
to->alpha.y0 = alpha_y0;
to->alpha.u0 = alpha_u0;
to->alpha.v0 = alpha_v0;
to->alpha.ydiff = min(max(alpha_ydiff, min_diff), max_diff);
to->alpha.udiff = min(max(alpha_udiff, min_diff), max_diff);
to->alpha.vdiff = min(max(alpha_vdiff, min_diff), max_diff);
to->coring.u0 = coring_u0;
to->coring.v0 = coring_v0;
to->coring.udiff = min(max(coring_udiff, min_diff), max_diff);
to->coring.vdiff = min(max(coring_vdiff, min_diff), max_diff);
to->blending.strength = blending;
}
void
ia_css_xnr3_vmem_encode(
struct sh_css_isp_xnr3_vmem_params *to,
const struct ia_css_xnr3_config *from,
unsigned size)
{
unsigned i, j, base;
const unsigned total_blocks = 4;
const unsigned shuffle_block = 16;
(void)from;
(void)size;
for (i = 0; i < ISP_VEC_NELEMS; i++) {
to->x[0][i] = 0;
to->a[0][i] = 0;
to->b[0][i] = 0;
to->c[0][i] = 0;
}
assert(x[0] >= 0);
for (j = 1; j < XNR3_LOOK_UP_TABLE_POINTS; j++) {
assert(x[j] >= 0);
assert(x[j] > x[j - 1]);
}
for (i = 0; i < total_blocks; i++) {
base = shuffle_block * i;
for (j = 0; j < XNR3_LOOK_UP_TABLE_POINTS; j++) {
to->x[0][base + j] = x[j];
to->a[0][base + j] = a[j];
to->b[0][base + j] = b[j];
to->c[0][base + j] = c[j];
}
}
}
void
ia_css_xnr3_debug_dtrace(
const struct ia_css_xnr3_config *config,
unsigned level)
{
(void)config;
(void)level;
}
