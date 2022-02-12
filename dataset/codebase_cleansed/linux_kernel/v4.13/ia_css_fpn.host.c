void
ia_css_fpn_encode(
struct sh_css_isp_fpn_params *to,
const struct ia_css_fpn_table *from,
unsigned size)
{
(void)size;
to->shift = from->shift;
to->enabled = from->data != NULL;
}
void
ia_css_fpn_dump(
const struct sh_css_isp_fpn_params *fpn,
unsigned level)
{
if (!fpn) return;
ia_css_debug_dtrace(level, "Fixed Pattern Noise Reduction:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"fpn_shift", fpn->shift);
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"fpn_enabled", fpn->enabled);
}
void
ia_css_fpn_config(
struct sh_css_isp_fpn_isp_config *to,
const struct ia_css_fpn_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS;
(void)size;
ia_css_dma_configure_from_info(&to->port_b, from->info);
to->width_a_over_b = elems_a / to->port_b.elems;
assert (elems_a % to->port_b.elems == 0);
}
void
ia_css_fpn_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
struct ia_css_frame_info my_info = IA_CSS_BINARY_DEFAULT_FRAME_INFO;
const struct ia_css_fpn_configuration config = {
&my_info
};
my_info.res.width = CEIL_DIV(info->res.width, 2);
my_info.res.height = info->res.height;
my_info.padded_width = CEIL_DIV(info->padded_width, 2);
my_info.format = info->format;
my_info.raw_bit_depth = FPN_BITS_PER_PIXEL;
my_info.raw_bayer_order = info->raw_bayer_order;
my_info.crop_info = info->crop_info;
ia_css_configure_fpn(binary, &config);
}
