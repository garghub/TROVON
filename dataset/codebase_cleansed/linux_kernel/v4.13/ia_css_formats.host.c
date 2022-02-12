void
ia_css_formats_encode(
struct sh_css_isp_formats_params *to,
const struct ia_css_formats_config *from,
unsigned size)
{
(void)size;
to->video_full_range_flag = from->video_full_range_flag;
}
void
ia_css_formats_dump(
const struct sh_css_isp_formats_params *formats,
unsigned level)
{
if (!formats) return;
ia_css_debug_dtrace(level, "\t%-32s = %d\n",
"video_full_range_flag", formats->video_full_range_flag);
}
void
ia_css_formats_debug_dtrace(
const struct ia_css_formats_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.video_full_range_flag=%d\n",
config->video_full_range_flag);
}
