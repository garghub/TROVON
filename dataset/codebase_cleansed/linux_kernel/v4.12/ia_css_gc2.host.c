void
ia_css_yuv2rgb_encode(
struct sh_css_isp_csc_params *to,
const struct ia_css_cc_config *from,
unsigned size)
{
ia_css_encode_cc(to, from, size);
}
void
ia_css_rgb2yuv_encode(
struct sh_css_isp_csc_params *to,
const struct ia_css_cc_config *from,
unsigned size)
{
ia_css_encode_cc(to, from, size);
}
void
ia_css_r_gamma_vamem_encode(
struct sh_css_isp_rgb_gamma_vamem_params *to,
const struct ia_css_rgb_gamma_table *from,
unsigned size)
{
(void)size;
memcpy (&to->gc, &from->data, sizeof(to->gc));
}
void
ia_css_g_gamma_vamem_encode(
struct sh_css_isp_rgb_gamma_vamem_params *to,
const struct ia_css_rgb_gamma_table *from,
unsigned size)
{
(void)size;
memcpy (&to->gc, &from->data, sizeof(to->gc));
}
void
ia_css_b_gamma_vamem_encode(
struct sh_css_isp_rgb_gamma_vamem_params *to,
const struct ia_css_rgb_gamma_table *from,
unsigned size)
{
(void)size;
memcpy (&to->gc, &from->data, sizeof(to->gc));
}
void
ia_css_yuv2rgb_dump(
const struct sh_css_isp_csc_params *yuv2rgb,
unsigned level)
{
ia_css_cc_dump(yuv2rgb, level, "YUV to RGB Conversion");
}
void
ia_css_rgb2yuv_dump(
const struct sh_css_isp_csc_params *rgb2yuv,
unsigned level)
{
ia_css_cc_dump(rgb2yuv, level, "RGB to YUV Conversion");
}
void
ia_css_rgb_gamma_table_debug_dtrace(
const struct ia_css_rgb_gamma_table *config,
unsigned level)
{
(void)config;
(void)level;
}
