void
ia_css_iterator_config(
struct sh_css_isp_iterator_isp_config *to,
const struct ia_css_iterator_configuration *from,
unsigned size)
{
(void)size;
ia_css_frame_info_to_frame_sp_info(&to->input_info, from->input_info);
ia_css_frame_info_to_frame_sp_info(&to->internal_info, from->internal_info);
ia_css_frame_info_to_frame_sp_info(&to->output_info, from->output_info);
ia_css_frame_info_to_frame_sp_info(&to->vf_info, from->vf_info);
ia_css_resolution_to_sp_resolution(&to->dvs_envelope, from->dvs_envelope);
}
enum ia_css_err
ia_css_iterator_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame_info *in_info)
{
struct ia_css_frame_info my_info = IA_CSS_BINARY_DEFAULT_FRAME_INFO;
struct ia_css_iterator_configuration config = default_config;
config.input_info = &binary->in_frame_info;
config.internal_info = &binary->internal_frame_info;
config.output_info = &binary->out_frame_info[0];
config.vf_info = &binary->vf_frame_info;
config.dvs_envelope = &binary->dvs_envelope;
if (in_info)
config.input_info = in_info;
if (binary->out_frame_info[0].res.width == 0)
config.output_info = &binary->out_frame_info[1];
my_info = *config.output_info;
config.output_info = &my_info;
if (binary->info->sp.pipeline.mode == IA_CSS_BINARY_MODE_PREVIEW &&
binary->vf_downscale_log2 > 0) {
my_info.padded_width <<= binary->vf_downscale_log2;
my_info.res.width <<= binary->vf_downscale_log2;
my_info.res.height <<= binary->vf_downscale_log2;
}
ia_css_configure_iterator(binary, &config);
return IA_CSS_SUCCESS;
}
