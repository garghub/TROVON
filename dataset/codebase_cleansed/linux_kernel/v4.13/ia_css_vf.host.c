void
ia_css_vf_config(
struct sh_css_isp_vf_isp_config *to,
const struct ia_css_vf_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS;
(void)size;
to->vf_downscale_bits = from->vf_downscale_bits;
to->enable = from->info != NULL;
if (from->info) {
ia_css_frame_info_to_frame_sp_info(&to->info, from->info);
ia_css_dma_configure_from_info(&to->dma.port_b, from->info);
to->dma.width_a_over_b = elems_a / to->dma.port_b.elems;
assert (elems_a % to->dma.port_b.elems == 0);
}
}
enum ia_css_err
sh_css_vf_downscale_log2(
const struct ia_css_frame_info *out_info,
const struct ia_css_frame_info *vf_info,
unsigned int *downscale_log2)
{
unsigned int ds_log2 = 0;
unsigned int out_width;
if ((out_info == NULL) | (vf_info == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
out_width = out_info->res.width;
if (out_width == 0)
return IA_CSS_ERR_INVALID_ARGUMENTS;
while (out_width >= vf_info->res.width) {
ds_log2++;
out_width /= 2;
}
if ((ds_log2 > 0) && (out_width < ia_css_binary_max_vf_width()))
ds_log2--;
if ((out_info->res.width >> ds_log2) >= 2 * ia_css_binary_max_vf_width())
return IA_CSS_ERR_INVALID_ARGUMENTS;
*downscale_log2 = ds_log2;
return IA_CSS_SUCCESS;
}
static enum ia_css_err
configure_kernel(
const struct ia_css_binary_info *info,
const struct ia_css_frame_info *out_info,
const struct ia_css_frame_info *vf_info,
unsigned int *downscale_log2,
struct ia_css_vf_configuration *config)
{
enum ia_css_err err;
unsigned vf_log_ds = 0;
if (vf_info) {
err = sh_css_vf_downscale_log2(out_info, vf_info, &vf_log_ds);
if (err != IA_CSS_SUCCESS)
return err;
}
vf_log_ds = min(vf_log_ds, info->vf_dec.max_log_downscale);
*downscale_log2 = vf_log_ds;
config->vf_downscale_bits = vf_log_ds;
return IA_CSS_SUCCESS;
}
static void
configure_dma(
struct ia_css_vf_configuration *config,
const struct ia_css_frame_info *vf_info)
{
config->info = vf_info;
}
enum ia_css_err
ia_css_vf_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *out_info,
struct ia_css_frame_info *vf_info,
unsigned int *downscale_log2)
{
enum ia_css_err err;
struct ia_css_vf_configuration config;
const struct ia_css_binary_info *info = &binary->info->sp;
err = configure_kernel(info, out_info, vf_info, downscale_log2, &config);
configure_dma(&config, vf_info);
if (binary) {
if (vf_info)
vf_info->raw_bit_depth = info->dma.vfdec_bits_per_pixel;
ia_css_configure_vf (binary, &config);
}
return IA_CSS_SUCCESS;
}
