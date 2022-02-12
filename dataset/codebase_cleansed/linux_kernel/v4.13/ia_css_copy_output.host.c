void
ia_css_copy_output_config(
struct sh_css_isp_copy_output_isp_config *to,
const struct ia_css_copy_output_configuration *from,
unsigned size)
{
(void)size;
to->enable = from->enable;
}
void
ia_css_copy_output_configure(
const struct ia_css_binary *binary,
bool enable)
{
struct ia_css_copy_output_configuration config = default_config;
config.enable = enable;
ia_css_configure_copy_output(binary, &config);
}
