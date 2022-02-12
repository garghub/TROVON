void
ia_css_qplane_config(
struct sh_css_isp_qplane_isp_config *to,
const struct ia_css_qplane_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS;
(void)size;
ia_css_dma_configure_from_info(&to->port_b, from->info);
to->width_a_over_b = elems_a / to->port_b.elems;
assert (elems_a % to->port_b.elems == 0);
to->inout_port_config = from->pipe->inout_port_config;
to->format = from->info->format;
}
void
ia_css_qplane_configure(
const struct sh_css_sp_pipeline *pipe,
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
struct ia_css_qplane_configuration config = default_config;
config.pipe = pipe;
config.info = info;
ia_css_configure_qplane(binary, &config);
}
