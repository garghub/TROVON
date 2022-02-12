static unsigned inputfifo_wrap_marker(
unsigned marker)
{
return marker |
(inputfifo_curr_ch_id << HIVE_STR_TO_MIPI_CH_ID_LSB) |
(inputfifo_curr_fmt_type << _HIVE_STR_TO_MIPI_FMT_TYPE_LSB);
}
STORAGE_CLASS_INLINE void
_sh_css_fifo_snd(unsigned token)
{
while (!can_event_send_token(STR2MIPI_EVENT_ID))
hrt_sleep();
event_send_token(STR2MIPI_EVENT_ID, token);
return;
}
static void inputfifo_send_data_a(
unsigned int data)
{
unsigned int token = (1 << HIVE_STR_TO_MIPI_VALID_A_BIT) |
(data << HIVE_STR_TO_MIPI_DATA_A_LSB);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_data_b(
unsigned int data)
{
unsigned int token = (1 << HIVE_STR_TO_MIPI_VALID_B_BIT) |
(data << _HIVE_STR_TO_MIPI_DATA_B_LSB);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_data(
unsigned int a,
unsigned int b)
{
unsigned int token = ((1 << HIVE_STR_TO_MIPI_VALID_A_BIT) |
(1 << HIVE_STR_TO_MIPI_VALID_B_BIT) |
(a << HIVE_STR_TO_MIPI_DATA_A_LSB) |
(b << _HIVE_STR_TO_MIPI_DATA_B_LSB));
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_sol(void)
{
hrt_data token = inputfifo_wrap_marker(
1 << HIVE_STR_TO_MIPI_SOL_BIT);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_eol(void)
{
hrt_data token = inputfifo_wrap_marker(
1 << HIVE_STR_TO_MIPI_EOL_BIT);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_sof(void)
{
hrt_data token = inputfifo_wrap_marker(
1 << HIVE_STR_TO_MIPI_SOF_BIT);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_eof(void)
{
hrt_data token = inputfifo_wrap_marker(
1 << HIVE_STR_TO_MIPI_EOF_BIT);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_ch_id(
unsigned int ch_id)
{
hrt_data token;
inputfifo_curr_ch_id = ch_id & _HIVE_ISP_CH_ID_MASK;
token = inputfifo_wrap_marker(0);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_fmt_type(
unsigned int fmt_type)
{
hrt_data token;
inputfifo_curr_fmt_type = fmt_type & _HIVE_ISP_FMT_TYPE_MASK;
token = inputfifo_wrap_marker(0);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_ch_id_and_fmt_type(
unsigned int ch_id,
unsigned int fmt_type)
{
hrt_data token;
inputfifo_curr_ch_id = ch_id & _HIVE_ISP_CH_ID_MASK;
inputfifo_curr_fmt_type = fmt_type & _HIVE_ISP_FMT_TYPE_MASK;
token = inputfifo_wrap_marker(0);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_send_empty_token(void)
{
hrt_data token = inputfifo_wrap_marker(0);
_sh_css_fifo_snd(token);
return;
}
static void inputfifo_start_frame(
unsigned int ch_id,
unsigned int fmt_type)
{
inputfifo_send_ch_id_and_fmt_type(ch_id, fmt_type);
inputfifo_send_sof();
return;
}
static void inputfifo_end_frame(
unsigned int marker_cycles)
{
unsigned int i;
for (i = 0; i < marker_cycles; i++)
inputfifo_send_empty_token();
inputfifo_send_eof();
return;
}
static void inputfifo_send_line2(
const unsigned short *data,
unsigned int width,
const unsigned short *data2,
unsigned int width2,
unsigned int hblank_cycles,
unsigned int marker_cycles,
unsigned int two_ppc,
enum inputfifo_mipi_data_type type)
{
unsigned int i, is_rgb = 0, is_legacy = 0;
assert(data != NULL);
assert((data2 != NULL) || (width2 == 0));
if (type == inputfifo_mipi_data_type_rgb)
is_rgb = 1;
if (type == inputfifo_mipi_data_type_yuv420_legacy)
is_legacy = 1;
for (i = 0; i < hblank_cycles; i++)
inputfifo_send_empty_token();
inputfifo_send_sol();
for (i = 0; i < marker_cycles; i++)
inputfifo_send_empty_token();
for (i = 0; i < width; i++, data++) {
unsigned int send_two_pixels = two_ppc;
if ((is_rgb || is_legacy) && (i % 3 == 2))
send_two_pixels = 0;
if (send_two_pixels) {
if (i + 1 == width) {
inputfifo_send_data(
data[0], 0);
} else {
inputfifo_send_data(
data[0], data[1]);
}
data++;
i++;
} else if (two_ppc && is_legacy) {
inputfifo_send_data_b(data[0]);
} else {
inputfifo_send_data_a(data[0]);
}
}
for (i = 0; i < width2; i++, data2++) {
unsigned int send_two_pixels = two_ppc;
if ((is_rgb || is_legacy) && (i % 3 == 2))
send_two_pixels = 0;
if (send_two_pixels) {
if (i + 1 == width2) {
inputfifo_send_data(
data2[0], 0);
} else {
inputfifo_send_data(
data2[0], data2[1]);
}
data2++;
i++;
} else if (two_ppc && is_legacy) {
inputfifo_send_data_b(data2[0]);
} else {
inputfifo_send_data_a(data2[0]);
}
}
for (i = 0; i < hblank_cycles; i++)
inputfifo_send_empty_token();
inputfifo_send_eol();
return;
}
static void
inputfifo_send_line(const unsigned short *data,
unsigned int width,
unsigned int hblank_cycles,
unsigned int marker_cycles,
unsigned int two_ppc,
enum inputfifo_mipi_data_type type)
{
assert(data != NULL);
inputfifo_send_line2(data, width, NULL, 0,
hblank_cycles,
marker_cycles,
two_ppc,
type);
}
static void inputfifo_send_frame(
const unsigned short *data,
unsigned int width,
unsigned int height,
unsigned int ch_id,
unsigned int fmt_type,
unsigned int hblank_cycles,
unsigned int marker_cycles,
unsigned int two_ppc,
enum inputfifo_mipi_data_type type)
{
unsigned int i;
assert(data != NULL);
inputfifo_start_frame(ch_id, fmt_type);
for (i = 0; i < height; i++) {
if ((type == inputfifo_mipi_data_type_yuv420) &&
(i & 1) == 1) {
inputfifo_send_line(data, 2 * width,
hblank_cycles,
marker_cycles,
two_ppc, type);
data += 2 * width;
} else {
inputfifo_send_line(data, width,
hblank_cycles,
marker_cycles,
two_ppc, type);
data += width;
}
}
inputfifo_end_frame(marker_cycles);
return;
}
static enum inputfifo_mipi_data_type inputfifo_determine_type(
enum ia_css_stream_format input_format)
{
enum inputfifo_mipi_data_type type;
type = inputfifo_mipi_data_type_regular;
if (input_format == IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY) {
type =
inputfifo_mipi_data_type_yuv420_legacy;
} else if (input_format == IA_CSS_STREAM_FORMAT_YUV420_8 ||
input_format == IA_CSS_STREAM_FORMAT_YUV420_10 ||
input_format == IA_CSS_STREAM_FORMAT_YUV420_16) {
type =
inputfifo_mipi_data_type_yuv420;
} else if (input_format >= IA_CSS_STREAM_FORMAT_RGB_444 &&
input_format <= IA_CSS_STREAM_FORMAT_RGB_888) {
type =
inputfifo_mipi_data_type_rgb;
}
return type;
}
static struct inputfifo_instance *inputfifo_get_inst(
unsigned int ch_id)
{
return &inputfifo_inst_admin[ch_id];
}
void ia_css_inputfifo_send_input_frame(
const unsigned short *data,
unsigned int width,
unsigned int height,
unsigned int ch_id,
enum ia_css_stream_format input_format,
bool two_ppc)
{
unsigned int fmt_type, hblank_cycles, marker_cycles;
enum inputfifo_mipi_data_type type;
assert(data != NULL);
hblank_cycles = HBLANK_CYCLES;
marker_cycles = MARKER_CYCLES;
ia_css_isys_convert_stream_format_to_mipi_format(input_format,
MIPI_PREDICTOR_NONE,
&fmt_type);
type = inputfifo_determine_type(input_format);
inputfifo_send_frame(data, width, height,
ch_id, fmt_type, hblank_cycles, marker_cycles,
two_ppc, type);
}
void ia_css_inputfifo_start_frame(
unsigned int ch_id,
enum ia_css_stream_format input_format,
bool two_ppc)
{
struct inputfifo_instance *s2mi;
s2mi = inputfifo_get_inst(ch_id);
s2mi->ch_id = ch_id;
ia_css_isys_convert_stream_format_to_mipi_format(input_format,
MIPI_PREDICTOR_NONE,
&s2mi->fmt_type);
s2mi->two_ppc = two_ppc;
s2mi->type = inputfifo_determine_type(input_format);
s2mi->hblank_cycles = HBLANK_CYCLES;
s2mi->marker_cycles = MARKER_CYCLES;
s2mi->streaming = true;
inputfifo_start_frame(ch_id, s2mi->fmt_type);
return;
}
void ia_css_inputfifo_send_line(
unsigned int ch_id,
const unsigned short *data,
unsigned int width,
const unsigned short *data2,
unsigned int width2)
{
struct inputfifo_instance *s2mi;
assert(data != NULL);
assert((data2 != NULL) || (width2 == 0));
s2mi = inputfifo_get_inst(ch_id);
inputfifo_curr_ch_id = (s2mi->ch_id) & _HIVE_ISP_CH_ID_MASK;
inputfifo_curr_fmt_type = (s2mi->fmt_type) & _HIVE_ISP_FMT_TYPE_MASK;
inputfifo_send_line2(data, width, data2, width2,
s2mi->hblank_cycles,
s2mi->marker_cycles,
s2mi->two_ppc,
s2mi->type);
}
void ia_css_inputfifo_send_embedded_line(
unsigned int ch_id,
enum ia_css_stream_format data_type,
const unsigned short *data,
unsigned int width)
{
struct inputfifo_instance *s2mi;
unsigned int fmt_type;
assert(data != NULL);
s2mi = inputfifo_get_inst(ch_id);
ia_css_isys_convert_stream_format_to_mipi_format(data_type,
MIPI_PREDICTOR_NONE, &fmt_type);
inputfifo_curr_fmt_type = fmt_type & _HIVE_ISP_FMT_TYPE_MASK;
inputfifo_send_line(data, width, s2mi->hblank_cycles, s2mi->marker_cycles,
s2mi->two_ppc, inputfifo_mipi_data_type_regular);
}
void ia_css_inputfifo_end_frame(
unsigned int ch_id)
{
struct inputfifo_instance *s2mi;
s2mi = inputfifo_get_inst(ch_id);
inputfifo_curr_ch_id = (s2mi->ch_id) & _HIVE_ISP_CH_ID_MASK;
inputfifo_curr_fmt_type = (s2mi->fmt_type) & _HIVE_ISP_FMT_TYPE_MASK;
inputfifo_end_frame(s2mi->marker_cycles);
s2mi->streaming = false;
return;
}
