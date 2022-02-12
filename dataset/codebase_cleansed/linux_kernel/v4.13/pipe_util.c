unsigned int ia_css_pipe_util_pipe_input_format_bpp(
const struct ia_css_pipe * const pipe)
{
assert(pipe != NULL);
assert(pipe->stream != NULL);
return ia_css_util_input_format_bpp(pipe->stream->config.input_config.format,
pipe->stream->config.pixels_per_clock == 2);
}
void ia_css_pipe_util_create_output_frames(
struct ia_css_frame *frames[])
{
unsigned int i;
assert(frames != NULL);
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
frames[i] = NULL;
}
}
void ia_css_pipe_util_set_output_frames(
struct ia_css_frame *frames[],
unsigned int idx,
struct ia_css_frame *frame)
{
assert(idx < IA_CSS_BINARY_MAX_OUTPUT_PORTS);
frames[idx] = frame;
}
