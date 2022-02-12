void
ia_css_output_encode(
struct sh_css_isp_output_params *to,
const struct ia_css_output_config *from,
unsigned size)
{
(void)size;
to->enable_hflip = from->enable_hflip;
to->enable_vflip = from->enable_vflip;
}
void
ia_css_output_config(
struct sh_css_isp_output_isp_config *to,
const struct ia_css_output_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS;
(void)size;
ia_css_dma_configure_from_info(&to->port_b, from->info);
to->width_a_over_b = elems_a / to->port_b.elems;
to->height = from->info->res.height;
to->enable = from->info != NULL;
ia_css_frame_info_to_frame_sp_info(&to->info, from->info);
assert (elems_a % to->port_b.elems == 0);
}
void
ia_css_output0_config(
struct sh_css_isp_output_isp_config *to,
const struct ia_css_output0_configuration *from,
unsigned size)
{
ia_css_output_config (
to, (const struct ia_css_output_configuration *)from, size);
}
void
ia_css_output1_config(
struct sh_css_isp_output_isp_config *to,
const struct ia_css_output1_configuration *from,
unsigned size)
{
ia_css_output_config (
to, (const struct ia_css_output_configuration *)from, size);
}
void
ia_css_output_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
if (NULL != info) {
struct ia_css_output_configuration config =
default_output_configuration;
config.info = info;
ia_css_configure_output(binary, &config);
}
}
void
ia_css_output0_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
if (NULL != info) {
struct ia_css_output0_configuration config =
default_output0_configuration;
config.info = info;
ia_css_configure_output0(binary, &config);
}
}
void
ia_css_output1_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *info)
{
if (NULL != info) {
struct ia_css_output1_configuration config =
default_output1_configuration;
config.info = info;
ia_css_configure_output1(binary, &config);
}
}
void
ia_css_output_dump(
const struct sh_css_isp_output_params *output,
unsigned level)
{
if (!output) return;
ia_css_debug_dtrace(level, "Horizontal Output Flip:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"enable", output->enable_hflip);
ia_css_debug_dtrace(level, "Vertical Output Flip:\n");
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"enable", output->enable_vflip);
}
void
ia_css_output_debug_dtrace(
const struct ia_css_output_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.enable_hflip=%d",
config->enable_hflip);
ia_css_debug_dtrace(level,
"config.enable_vflip=%d",
config->enable_vflip);
}
