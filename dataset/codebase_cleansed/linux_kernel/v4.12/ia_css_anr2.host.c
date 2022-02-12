void
ia_css_anr2_vmem_encode(
struct ia_css_isp_anr2_params *to,
const struct ia_css_anr_thres *from,
size_t size)
{
unsigned i;
(void)size;
for (i = 0; i < ANR_PARAM_SIZE; i++) {
unsigned j;
for (j = 0; j < ISP_VEC_NELEMS; j++) {
to->data[i][j] = from->data[i*ISP_VEC_NELEMS+j];
}
}
}
void
ia_css_anr2_debug_dtrace(
const struct ia_css_anr_thres *config,
unsigned level)
{
(void)config;
(void)level;
}
