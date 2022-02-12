void
ia_css_crop_encode(
struct sh_css_isp_crop_isp_params *to,
const struct ia_css_crop_config *from,
unsigned size)
{
(void)size;
to->crop_pos = from->crop_pos;
}
void
ia_css_crop_config(
struct sh_css_isp_crop_isp_config *to,
const struct ia_css_crop_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS;
(void)size;
ia_css_dma_configure_from_info(&to->port_b, from->info);
to->width_a_over_b = elems_a / to->port_b.elems;
assert (elems_a % to->port_b.elems == 0);
}
void
ia_css_crop_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
struct ia_css_crop_configuration config = default_config;
config.info = info;
ia_css_configure_crop(binary, &config);
}
