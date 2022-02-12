enum ia_css_err
ia_css_mipi_frame_specify(const unsigned int size_mem_words,
const bool contiguous)
{
enum ia_css_err err = IA_CSS_SUCCESS;
my_css.size_mem_words = size_mem_words;
(void)contiguous;
return err;
}
static bool ia_css_mipi_is_source_port_valid(struct ia_css_pipe *pipe,
unsigned int *pport)
{
bool ret = true;
unsigned int port = 0;
unsigned int max_ports = 0;
switch (pipe->stream->config.mode) {
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
port = (unsigned int) pipe->stream->config.source.port.port;
max_ports = N_CSI_PORTS;
break;
case IA_CSS_INPUT_MODE_TPG:
port = (unsigned int) pipe->stream->config.source.tpg.id;
max_ports = N_CSS_TPG_IDS;
break;
case IA_CSS_INPUT_MODE_PRBS:
port = (unsigned int) pipe->stream->config.source.prbs.id;
max_ports = N_CSS_PRBS_IDS;
break;
default:
assert(false);
ret = false;
break;
}
if (ret) {
assert(port < max_ports);
if (port >= max_ports)
ret = false;
}
*pport = port;
return ret;
}
enum ia_css_err
ia_css_mipi_frame_calculate_size(const unsigned int width,
const unsigned int height,
const enum ia_css_stream_format format,
const bool hasSOLandEOL,
const unsigned int embedded_data_size_words,
unsigned int *size_mem_words)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int bits_per_pixel = 0;
unsigned int even_line_bytes = 0;
unsigned int odd_line_bytes = 0;
unsigned int words_per_odd_line = 0;
unsigned int words_for_first_line = 0;
unsigned int words_per_even_line = 0;
unsigned int mem_words_per_even_line = 0;
unsigned int mem_words_per_odd_line = 0;
unsigned int mem_words_for_first_line = 0;
unsigned int mem_words_for_EOF = 0;
unsigned int mem_words = 0;
unsigned int width_padded = width;
#if defined(USE_INPUT_SYSTEM_VERSION_2401)
width_padded += (2 * ISP_VEC_NELEMS);
#endif
IA_CSS_ENTER("padded_width=%d, height=%d, format=%d, hasSOLandEOL=%d, embedded_data_size_words=%d\n",
width_padded, height, format, hasSOLandEOL, embedded_data_size_words);
switch (format) {
case IA_CSS_STREAM_FORMAT_RAW_6:
bits_per_pixel = 6; break;
case IA_CSS_STREAM_FORMAT_RAW_7:
bits_per_pixel = 7; break;
case IA_CSS_STREAM_FORMAT_RAW_8:
case IA_CSS_STREAM_FORMAT_BINARY_8:
case IA_CSS_STREAM_FORMAT_YUV420_8:
bits_per_pixel = 8; break;
case IA_CSS_STREAM_FORMAT_YUV420_10:
case IA_CSS_STREAM_FORMAT_RAW_10:
#if !defined(HAS_NO_PACKED_RAW_PIXELS)
bits_per_pixel = 10;
#else
bits_per_pixel = 16;
#endif
break;
case IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY:
case IA_CSS_STREAM_FORMAT_RAW_12:
bits_per_pixel = 12; break;
case IA_CSS_STREAM_FORMAT_RAW_14:
bits_per_pixel = 14; break;
case IA_CSS_STREAM_FORMAT_RGB_444:
case IA_CSS_STREAM_FORMAT_RGB_555:
case IA_CSS_STREAM_FORMAT_RGB_565:
case IA_CSS_STREAM_FORMAT_YUV422_8:
bits_per_pixel = 16; break;
case IA_CSS_STREAM_FORMAT_RGB_666:
bits_per_pixel = 18; break;
case IA_CSS_STREAM_FORMAT_YUV422_10:
bits_per_pixel = 20; break;
case IA_CSS_STREAM_FORMAT_RGB_888:
bits_per_pixel = 24; break;
case IA_CSS_STREAM_FORMAT_YUV420_16:
case IA_CSS_STREAM_FORMAT_YUV422_16:
case IA_CSS_STREAM_FORMAT_RAW_16:
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
odd_line_bytes = (width_padded * bits_per_pixel + 7) >> 3;
if (format == IA_CSS_STREAM_FORMAT_YUV420_8
|| format == IA_CSS_STREAM_FORMAT_YUV420_10
|| format == IA_CSS_STREAM_FORMAT_YUV420_16) {
even_line_bytes = (width_padded * 2 * bits_per_pixel + 7) >> 3;
} else {
even_line_bytes = odd_line_bytes;
}
words_per_odd_line = (odd_line_bytes + 3) >> 2;
words_per_even_line = (even_line_bytes + 3) >> 2;
words_for_first_line = words_per_odd_line + 2 + (hasSOLandEOL ? 1 : 0);
words_per_odd_line += (1 + (hasSOLandEOL ? 2 : 0));
words_per_even_line += (1 + (hasSOLandEOL ? 2 : 0));
mem_words_per_odd_line = (words_per_odd_line + 7) >> 3;
mem_words_for_first_line = (words_for_first_line + 7) >> 3;
mem_words_per_even_line = (words_per_even_line + 7) >> 3;
mem_words_for_EOF = 1;
mem_words = ((embedded_data_size_words + 7) >> 3) +
mem_words_for_first_line +
(((height + 1) >> 1) - 1) * mem_words_per_odd_line +
(height >> 1) * mem_words_per_even_line +
mem_words_for_EOF;
*size_mem_words = mem_words;
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err
ia_css_mipi_frame_enable_check_on_size(const enum ia_css_csi2_port port,
const unsigned int size_mem_words)
{
uint32_t idx;
enum ia_css_err err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
OP___assert(port < N_CSI_PORTS);
OP___assert(size_mem_words != 0);
for (idx = 0; idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT &&
my_css.mipi_sizes_for_check[port][idx] != 0;
idx++) {
}
if (idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT) {
my_css.mipi_sizes_for_check[port][idx] = size_mem_words;
err = IA_CSS_SUCCESS;
}
return err;
}
void
mipi_init(void)
{
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
unsigned int i;
for (i = 0; i < N_CSI_PORTS; i++)
ref_count_mipi_allocation[i] = 0;
#endif
}
enum ia_css_err
calculate_mipi_buff_size(
struct ia_css_stream_config *stream_cfg,
unsigned int *size_mem_words)
{
#if !defined(USE_INPUT_SYSTEM_VERSION_2401)
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
(void)stream_cfg;
(void)size_mem_words;
#else
unsigned int width;
unsigned int height;
enum ia_css_stream_format format;
bool pack_raw_pixels;
unsigned int width_padded;
unsigned int bits_per_pixel = 0;
unsigned int even_line_bytes = 0;
unsigned int odd_line_bytes = 0;
unsigned int words_per_odd_line = 0;
unsigned int words_per_even_line = 0;
unsigned int mem_words_per_even_line = 0;
unsigned int mem_words_per_odd_line = 0;
unsigned int mem_words_per_buff_line = 0;
unsigned int mem_words_per_buff = 0;
enum ia_css_err err = IA_CSS_SUCCESS;
width = stream_cfg->input_config.input_res.width;
height = stream_cfg->input_config.input_res.height;
format = stream_cfg->input_config.format;
pack_raw_pixels = stream_cfg->pack_raw_pixels;
width_padded = width + (2 * ISP_VEC_NELEMS);
IA_CSS_ENTER("padded_width=%d, height=%d, format=%d\n",
width_padded, height, format);
bits_per_pixel = sh_css_stream_format_2_bits_per_subpixel(format);
bits_per_pixel =
(format == IA_CSS_STREAM_FORMAT_RAW_10 && pack_raw_pixels) ? bits_per_pixel : 16;
if (bits_per_pixel == 0)
return IA_CSS_ERR_INTERNAL_ERROR;
odd_line_bytes = (width_padded * bits_per_pixel + 7) >> 3;
if (format == IA_CSS_STREAM_FORMAT_YUV420_8
|| format == IA_CSS_STREAM_FORMAT_YUV420_10) {
even_line_bytes = (width_padded * 2 * bits_per_pixel + 7) >> 3;
} else {
even_line_bytes = odd_line_bytes;
}
words_per_odd_line = (odd_line_bytes + 3) >> 2;
words_per_even_line = (even_line_bytes + 3) >> 2;
mem_words_per_odd_line = (words_per_odd_line + 7) >> 3;
mem_words_per_even_line = (words_per_even_line + 7) >> 3;
mem_words_per_buff_line =
(mem_words_per_odd_line > mem_words_per_even_line) ? mem_words_per_odd_line : mem_words_per_even_line;
mem_words_per_buff = mem_words_per_buff_line * height;
*size_mem_words = mem_words_per_buff;
IA_CSS_LEAVE_ERR(err);
#endif
return err;
}
enum ia_css_err
send_mipi_frames(struct ia_css_pipe *pipe)
{
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
unsigned int i;
#ifndef ISP2401
unsigned int port;
#else
unsigned int port = 0;
#endif
IA_CSS_ENTER_PRIVATE("pipe=%d", pipe);
assert(pipe != NULL);
assert(pipe->stream != NULL);
if (pipe == NULL || pipe->stream == NULL) {
IA_CSS_ERROR("pipe or stream is null");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
#ifndef ISP2401
if (pipe->stream->config.mode != IA_CSS_INPUT_MODE_BUFFERED_SENSOR) {
#else
if (!(pipe->stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR ||
pipe->stream->config.mode == IA_CSS_INPUT_MODE_TPG ||
pipe->stream->config.mode == IA_CSS_INPUT_MODE_PRBS)) {
#endif
IA_CSS_LOG("nothing to be done for this mode");
return IA_CSS_SUCCESS;
}
#ifndef ISP2401
port = (unsigned int) pipe->stream->config.source.port.port;
assert(port < N_CSI_PORTS);
if (port >= N_CSI_PORTS) {
IA_CSS_ERROR("invalid port specified (%d)", port);
#else
if (!ia_css_mipi_is_source_port_valid(pipe, &port)) {
IA_CSS_ERROR("send_mipi_frames(%p) exit: invalid port specified (port=%d).\n", pipe, port);
#endif
return err;
}
for (i = 0; i < my_css.num_mipi_frames[port]; i++) {
sh_css_update_host2sp_mipi_frame(port * NUM_MIPI_FRAMES_PER_STREAM + i,
my_css.mipi_frames[port][i]);
sh_css_update_host2sp_mipi_metadata(port * NUM_MIPI_FRAMES_PER_STREAM + i,
my_css.mipi_metadata[port][i]);
}
sh_css_update_host2sp_num_mipi_frames(my_css.num_mipi_frames[port]);
if (!sh_css_sp_is_running()) {
IA_CSS_ERROR("sp is not running");
return err;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_MIPI_BUFFERS_READY,
(uint8_t)port,
(uint8_t)my_css.num_mipi_frames[port],
0 );
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
#else
(void)pipe;
#endif
return IA_CSS_SUCCESS;
}
