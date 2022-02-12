static void
sh_css_pipe_free_shading_table(struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
if (pipe == NULL) {
IA_CSS_ERROR("NULL input parameter");
return;
}
if (pipe->shading_table)
ia_css_shading_table_free(pipe->shading_table);
pipe->shading_table = NULL;
}
static enum ia_css_err
verify_copy_out_frame_format(struct ia_css_pipe *pipe)
{
enum ia_css_frame_format out_fmt = pipe->output_info[0].format;
unsigned int i, found = 0;
assert(pipe != NULL);
assert(pipe->stream != NULL);
switch (pipe->stream->config.input_config.format) {
case IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY:
case IA_CSS_STREAM_FORMAT_YUV420_8:
for (i=0; i<array_length(yuv420_copy_formats) && !found; i++)
found = (out_fmt == yuv420_copy_formats[i]);
break;
case IA_CSS_STREAM_FORMAT_YUV420_10:
case IA_CSS_STREAM_FORMAT_YUV420_16:
found = (out_fmt == IA_CSS_FRAME_FORMAT_YUV420_16);
break;
case IA_CSS_STREAM_FORMAT_YUV422_8:
for (i=0; i<array_length(yuv422_copy_formats) && !found; i++)
found = (out_fmt == yuv422_copy_formats[i]);
break;
case IA_CSS_STREAM_FORMAT_YUV422_10:
case IA_CSS_STREAM_FORMAT_YUV422_16:
found = (out_fmt == IA_CSS_FRAME_FORMAT_YUV422_16 ||
out_fmt == IA_CSS_FRAME_FORMAT_YUV420_16);
break;
case IA_CSS_STREAM_FORMAT_RGB_444:
case IA_CSS_STREAM_FORMAT_RGB_555:
case IA_CSS_STREAM_FORMAT_RGB_565:
found = (out_fmt == IA_CSS_FRAME_FORMAT_RGBA888 ||
out_fmt == IA_CSS_FRAME_FORMAT_RGB565);
break;
case IA_CSS_STREAM_FORMAT_RGB_666:
case IA_CSS_STREAM_FORMAT_RGB_888:
found = (out_fmt == IA_CSS_FRAME_FORMAT_RGBA888 ||
out_fmt == IA_CSS_FRAME_FORMAT_YUV420);
break;
case IA_CSS_STREAM_FORMAT_RAW_6:
case IA_CSS_STREAM_FORMAT_RAW_7:
case IA_CSS_STREAM_FORMAT_RAW_8:
case IA_CSS_STREAM_FORMAT_RAW_10:
case IA_CSS_STREAM_FORMAT_RAW_12:
case IA_CSS_STREAM_FORMAT_RAW_14:
case IA_CSS_STREAM_FORMAT_RAW_16:
found = (out_fmt == IA_CSS_FRAME_FORMAT_RAW) ||
(out_fmt == IA_CSS_FRAME_FORMAT_RAW_PACKED);
break;
case IA_CSS_STREAM_FORMAT_BINARY_8:
found = (out_fmt == IA_CSS_FRAME_FORMAT_BINARY_8);
break;
default:
break;
}
if (!found)
return IA_CSS_ERR_INVALID_ARGUMENTS;
return IA_CSS_SUCCESS;
}
unsigned int
ia_css_stream_input_format_bits_per_pixel(struct ia_css_stream *stream)
{
int bpp = 0;
if (stream != NULL)
bpp = ia_css_util_input_format_bpp(stream->config.input_config.format,
stream->config.pixels_per_clock == 2);
return bpp;
}
static enum ia_css_err
sh_css_config_input_network(struct ia_css_stream *stream)
{
unsigned int fmt_type;
struct ia_css_pipe *pipe = stream->last_pipe;
struct ia_css_binary *binary = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
assert(stream != NULL);
assert(pipe != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_config_input_network() enter:\n");
if (pipe->pipeline.stages)
binary = pipe->pipeline.stages->binary;
err = ia_css_isys_convert_stream_format_to_mipi_format(
stream->config.input_config.format,
stream->csi_rx_config.comp,
&fmt_type);
if (err != IA_CSS_SUCCESS)
return err;
sh_css_sp_program_input_circuit(fmt_type,
stream->config.channel_id,
stream->config.mode);
if ((binary && (binary->online || stream->config.continuous)) ||
pipe->config.mode == IA_CSS_PIPE_MODE_COPY) {
err = ia_css_ifmtr_configure(&stream->config,
binary);
if (err != IA_CSS_SUCCESS)
return err;
}
if (stream->config.mode == IA_CSS_INPUT_MODE_TPG ||
stream->config.mode == IA_CSS_INPUT_MODE_PRBS) {
unsigned int hblank_cycles = 100,
vblank_lines = 6,
width,
height,
vblank_cycles;
width = (stream->config.input_config.input_res.width) / (1 + (stream->config.pixels_per_clock == 2));
height = stream->config.input_config.input_res.height;
vblank_cycles = vblank_lines * (width + hblank_cycles);
sh_css_sp_configure_sync_gen(width, height, hblank_cycles,
vblank_cycles);
#if defined(IS_ISP_2400_SYSTEM)
if (pipe->stream->config.mode == IA_CSS_INPUT_MODE_TPG) {
#define GP_ISEL_TPG_MODE 0x90058
ia_css_device_store_uint32(GP_ISEL_TPG_MODE, 0);
}
#endif
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_config_input_network() leave:\n");
return IA_CSS_SUCCESS;
}
static unsigned int csi2_protocol_calculate_max_subpixels_per_line(
enum ia_css_stream_format format,
unsigned int pixels_per_line)
{
unsigned int rval;
switch (format) {
case IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY:
rval = pixels_per_line * 2;
break;
case IA_CSS_STREAM_FORMAT_YUV420_8:
case IA_CSS_STREAM_FORMAT_YUV420_10:
case IA_CSS_STREAM_FORMAT_YUV420_16:
rval = pixels_per_line * 2;
break;
case IA_CSS_STREAM_FORMAT_YUV422_8:
case IA_CSS_STREAM_FORMAT_YUV422_10:
case IA_CSS_STREAM_FORMAT_YUV422_16:
rval = pixels_per_line * 2;
break;
case IA_CSS_STREAM_FORMAT_RGB_444:
case IA_CSS_STREAM_FORMAT_RGB_555:
case IA_CSS_STREAM_FORMAT_RGB_565:
case IA_CSS_STREAM_FORMAT_RGB_666:
case IA_CSS_STREAM_FORMAT_RGB_888:
rval = pixels_per_line * 4;
break;
case IA_CSS_STREAM_FORMAT_RAW_6:
case IA_CSS_STREAM_FORMAT_RAW_7:
case IA_CSS_STREAM_FORMAT_RAW_8:
case IA_CSS_STREAM_FORMAT_RAW_10:
case IA_CSS_STREAM_FORMAT_RAW_12:
case IA_CSS_STREAM_FORMAT_RAW_14:
case IA_CSS_STREAM_FORMAT_RAW_16:
case IA_CSS_STREAM_FORMAT_BINARY_8:
case IA_CSS_STREAM_FORMAT_USER_DEF1:
case IA_CSS_STREAM_FORMAT_USER_DEF2:
case IA_CSS_STREAM_FORMAT_USER_DEF3:
case IA_CSS_STREAM_FORMAT_USER_DEF4:
case IA_CSS_STREAM_FORMAT_USER_DEF5:
case IA_CSS_STREAM_FORMAT_USER_DEF6:
case IA_CSS_STREAM_FORMAT_USER_DEF7:
case IA_CSS_STREAM_FORMAT_USER_DEF8:
rval = pixels_per_line;
break;
default:
rval = 0;
break;
}
return rval;
}
static bool sh_css_translate_stream_cfg_to_input_system_input_port_id(
struct ia_css_stream_config *stream_cfg,
ia_css_isys_descr_t *isys_stream_descr)
{
bool rc;
rc = true;
switch (stream_cfg->mode) {
case IA_CSS_INPUT_MODE_TPG:
if (stream_cfg->source.tpg.id == IA_CSS_TPG_ID0) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT0_ID;
} else if (stream_cfg->source.tpg.id == IA_CSS_TPG_ID1) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT1_ID;
} else if (stream_cfg->source.tpg.id == IA_CSS_TPG_ID2) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT2_ID;
}
break;
case IA_CSS_INPUT_MODE_PRBS:
if (stream_cfg->source.prbs.id == IA_CSS_PRBS_ID0) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT0_ID;
} else if (stream_cfg->source.prbs.id == IA_CSS_PRBS_ID1) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT1_ID;
} else if (stream_cfg->source.prbs.id == IA_CSS_PRBS_ID2) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_PIXELGEN_PORT2_ID;
}
break;
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
if (stream_cfg->source.port.port == IA_CSS_CSI2_PORT0) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT0_ID;
} else if (stream_cfg->source.port.port == IA_CSS_CSI2_PORT1) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT1_ID;
} else if (stream_cfg->source.port.port == IA_CSS_CSI2_PORT2) {
isys_stream_descr->input_port_id = INPUT_SYSTEM_CSI_PORT2_ID;
}
break;
default:
rc = false;
break;
}
return rc;
}
static bool sh_css_translate_stream_cfg_to_input_system_input_port_type(
struct ia_css_stream_config *stream_cfg,
ia_css_isys_descr_t *isys_stream_descr)
{
bool rc;
rc = true;
switch (stream_cfg->mode) {
case IA_CSS_INPUT_MODE_TPG:
isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_TPG;
break;
case IA_CSS_INPUT_MODE_PRBS:
isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_PRBS;
break;
case IA_CSS_INPUT_MODE_SENSOR:
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
isys_stream_descr->mode = INPUT_SYSTEM_SOURCE_TYPE_SENSOR;
break;
default:
rc = false;
break;
}
return rc;
}
static bool sh_css_translate_stream_cfg_to_input_system_input_port_attr(
struct ia_css_stream_config *stream_cfg,
ia_css_isys_descr_t *isys_stream_descr,
int isys_stream_idx)
{
bool rc;
rc = true;
switch (stream_cfg->mode) {
case IA_CSS_INPUT_MODE_TPG:
if (stream_cfg->source.tpg.mode == IA_CSS_TPG_MODE_RAMP) {
isys_stream_descr->tpg_port_attr.mode = PIXELGEN_TPG_MODE_RAMP;
} else if (stream_cfg->source.tpg.mode == IA_CSS_TPG_MODE_CHECKERBOARD) {
isys_stream_descr->tpg_port_attr.mode = PIXELGEN_TPG_MODE_CHBO;
} else if (stream_cfg->source.tpg.mode == IA_CSS_TPG_MODE_MONO) {
isys_stream_descr->tpg_port_attr.mode = PIXELGEN_TPG_MODE_MONO;
} else {
rc = false;
}
isys_stream_descr->tpg_port_attr.color_cfg.R1 = 51;
isys_stream_descr->tpg_port_attr.color_cfg.G1 = 102;
isys_stream_descr->tpg_port_attr.color_cfg.B1 = 255;
isys_stream_descr->tpg_port_attr.color_cfg.R2 = 0;
isys_stream_descr->tpg_port_attr.color_cfg.G2 = 100;
isys_stream_descr->tpg_port_attr.color_cfg.B2 = 160;
isys_stream_descr->tpg_port_attr.mask_cfg.h_mask = stream_cfg->source.tpg.x_mask;
isys_stream_descr->tpg_port_attr.mask_cfg.v_mask = stream_cfg->source.tpg.y_mask;
isys_stream_descr->tpg_port_attr.mask_cfg.hv_mask = stream_cfg->source.tpg.xy_mask;
isys_stream_descr->tpg_port_attr.delta_cfg.h_delta = stream_cfg->source.tpg.x_delta;
isys_stream_descr->tpg_port_attr.delta_cfg.v_delta = stream_cfg->source.tpg.y_delta;
isys_stream_descr->tpg_port_attr.sync_gen_cfg.hblank_cycles = 100;
isys_stream_descr->tpg_port_attr.sync_gen_cfg.vblank_cycles = 100;
isys_stream_descr->tpg_port_attr.sync_gen_cfg.pixels_per_clock = stream_cfg->pixels_per_clock;
isys_stream_descr->tpg_port_attr.sync_gen_cfg.nr_of_frames = (uint32_t) ~(0x0);
isys_stream_descr->tpg_port_attr.sync_gen_cfg.pixels_per_line = stream_cfg->isys_config[IA_CSS_STREAM_DEFAULT_ISYS_STREAM_IDX].input_res.width;
isys_stream_descr->tpg_port_attr.sync_gen_cfg.lines_per_frame = stream_cfg->isys_config[IA_CSS_STREAM_DEFAULT_ISYS_STREAM_IDX].input_res.height;
break;
case IA_CSS_INPUT_MODE_PRBS:
isys_stream_descr->prbs_port_attr.seed0 = stream_cfg->source.prbs.seed;
isys_stream_descr->prbs_port_attr.seed1 = stream_cfg->source.prbs.seed1;
isys_stream_descr->prbs_port_attr.sync_gen_cfg.hblank_cycles = 100;
isys_stream_descr->prbs_port_attr.sync_gen_cfg.vblank_cycles = 100;
isys_stream_descr->prbs_port_attr.sync_gen_cfg.pixels_per_clock = stream_cfg->pixels_per_clock;
isys_stream_descr->prbs_port_attr.sync_gen_cfg.nr_of_frames = (uint32_t) ~(0x0);
isys_stream_descr->prbs_port_attr.sync_gen_cfg.pixels_per_line = stream_cfg->isys_config[IA_CSS_STREAM_DEFAULT_ISYS_STREAM_IDX].input_res.width;
isys_stream_descr->prbs_port_attr.sync_gen_cfg.lines_per_frame = stream_cfg->isys_config[IA_CSS_STREAM_DEFAULT_ISYS_STREAM_IDX].input_res.height;
break;
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
{
enum ia_css_err err;
unsigned int fmt_type;
err = ia_css_isys_convert_stream_format_to_mipi_format(
stream_cfg->isys_config[isys_stream_idx].format,
MIPI_PREDICTOR_NONE,
&fmt_type);
if (err != IA_CSS_SUCCESS)
rc = false;
isys_stream_descr->csi_port_attr.active_lanes = stream_cfg->source.port.num_lanes;
isys_stream_descr->csi_port_attr.fmt_type = fmt_type;
isys_stream_descr->csi_port_attr.ch_id = stream_cfg->channel_id;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
isys_stream_descr->online = stream_cfg->online;
#endif
err |= ia_css_isys_convert_compressed_format(
&stream_cfg->source.port.compression,
isys_stream_descr);
if (err != IA_CSS_SUCCESS)
rc = false;
isys_stream_descr->metadata.enable = false;
if (stream_cfg->metadata_config.resolution.height > 0) {
err = ia_css_isys_convert_stream_format_to_mipi_format(
stream_cfg->metadata_config.data_type,
MIPI_PREDICTOR_NONE,
&fmt_type);
if (err != IA_CSS_SUCCESS)
rc = false;
isys_stream_descr->metadata.fmt_type = fmt_type;
isys_stream_descr->metadata.bits_per_pixel =
ia_css_util_input_format_bpp(stream_cfg->metadata_config.data_type, true);
isys_stream_descr->metadata.pixels_per_line = stream_cfg->metadata_config.resolution.width;
isys_stream_descr->metadata.lines_per_frame = stream_cfg->metadata_config.resolution.height;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (isys_stream_descr->metadata.lines_per_frame > 0)
isys_stream_descr->metadata.lines_per_frame +=
(isys_stream_descr->metadata.lines_per_frame & 1);
#endif
isys_stream_descr->metadata.align_req_in_bytes =
ia_css_csi2_calculate_input_system_alignment(stream_cfg->metadata_config.data_type);
isys_stream_descr->metadata.enable = true;
}
break;
}
default:
rc = false;
break;
}
return rc;
}
static bool sh_css_translate_stream_cfg_to_input_system_input_port_resolution(
struct ia_css_stream_config *stream_cfg,
ia_css_isys_descr_t *isys_stream_descr,
int isys_stream_idx)
{
unsigned int bits_per_subpixel;
unsigned int max_subpixels_per_line;
unsigned int lines_per_frame;
unsigned int align_req_in_bytes;
enum ia_css_stream_format fmt_type;
fmt_type = stream_cfg->isys_config[isys_stream_idx].format;
if ((stream_cfg->mode == IA_CSS_INPUT_MODE_SENSOR ||
stream_cfg->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR) &&
stream_cfg->source.port.compression.type != IA_CSS_CSI2_COMPRESSION_TYPE_NONE) {
if (stream_cfg->source.port.compression.uncompressed_bits_per_pixel ==
UNCOMPRESSED_BITS_PER_PIXEL_10) {
fmt_type = IA_CSS_STREAM_FORMAT_RAW_10;
}
else if (stream_cfg->source.port.compression.uncompressed_bits_per_pixel ==
UNCOMPRESSED_BITS_PER_PIXEL_12) {
fmt_type = IA_CSS_STREAM_FORMAT_RAW_12;
}
else
return false;
}
bits_per_subpixel =
sh_css_stream_format_2_bits_per_subpixel(fmt_type);
if (bits_per_subpixel == 0)
return false;
max_subpixels_per_line =
csi2_protocol_calculate_max_subpixels_per_line(fmt_type,
stream_cfg->isys_config[isys_stream_idx].input_res.width);
if (max_subpixels_per_line == 0)
return false;
lines_per_frame = stream_cfg->isys_config[isys_stream_idx].input_res.height;
if (lines_per_frame == 0)
return false;
align_req_in_bytes = ia_css_csi2_calculate_input_system_alignment(fmt_type);
isys_stream_descr->input_port_resolution.bits_per_pixel = bits_per_subpixel;
isys_stream_descr->input_port_resolution.pixels_per_line = max_subpixels_per_line;
isys_stream_descr->input_port_resolution.lines_per_frame = lines_per_frame;
isys_stream_descr->input_port_resolution.align_req_in_bytes = align_req_in_bytes;
return true;
}
static bool sh_css_translate_stream_cfg_to_isys_stream_descr(
struct ia_css_stream_config *stream_cfg,
bool early_polling,
ia_css_isys_descr_t *isys_stream_descr,
int isys_stream_idx)
{
bool rc;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_translate_stream_cfg_to_isys_stream_descr() enter:\n");
rc = sh_css_translate_stream_cfg_to_input_system_input_port_id(stream_cfg, isys_stream_descr);
rc &= sh_css_translate_stream_cfg_to_input_system_input_port_type(stream_cfg, isys_stream_descr);
rc &= sh_css_translate_stream_cfg_to_input_system_input_port_attr(stream_cfg, isys_stream_descr, isys_stream_idx);
rc &= sh_css_translate_stream_cfg_to_input_system_input_port_resolution(stream_cfg, isys_stream_descr, isys_stream_idx);
isys_stream_descr->raw_packed = stream_cfg->pack_raw_pixels;
isys_stream_descr->linked_isys_stream_id = (int8_t) stream_cfg->isys_config[isys_stream_idx].linked_isys_stream_id;
isys_stream_descr->polling_mode
= early_polling ? INPUT_SYSTEM_POLL_ON_CAPTURE_REQUEST
: INPUT_SYSTEM_POLL_ON_WAIT_FOR_FRAME;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_translate_stream_cfg_to_isys_stream_descr() leave:\n");
return rc;
}
static bool sh_css_translate_binary_info_to_input_system_output_port_attr(
struct ia_css_binary *binary,
ia_css_isys_descr_t *isys_stream_descr)
{
if (!binary)
return false;
isys_stream_descr->output_port_attr.left_padding = binary->left_padding;
isys_stream_descr->output_port_attr.max_isp_input_width = binary->info->sp.input.max_width;
return true;
}
static enum ia_css_err
sh_css_config_input_network(struct ia_css_stream *stream)
{
bool rc;
ia_css_isys_descr_t isys_stream_descr;
unsigned int sp_thread_id;
struct sh_css_sp_pipeline_terminal *sp_pipeline_input_terminal;
struct ia_css_pipe *pipe = NULL;
struct ia_css_binary *binary = NULL;
int i;
uint32_t isys_stream_id;
bool early_polling = false;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_config_input_network() enter 0x%p:\n", stream);
if (stream->config.continuous == true) {
if (stream->last_pipe->config.mode == IA_CSS_PIPE_MODE_CAPTURE) {
pipe = stream->last_pipe;
} else if (stream->last_pipe->config.mode == IA_CSS_PIPE_MODE_YUVPP) {
pipe = stream->last_pipe;
} else if (stream->last_pipe->config.mode == IA_CSS_PIPE_MODE_PREVIEW) {
pipe = stream->last_pipe->pipe_settings.preview.copy_pipe;
} else if (stream->last_pipe->config.mode == IA_CSS_PIPE_MODE_VIDEO) {
pipe = stream->last_pipe->pipe_settings.video.copy_pipe;
}
} else {
pipe = stream->last_pipe;
if (stream->last_pipe->config.mode == IA_CSS_PIPE_MODE_CAPTURE) {
early_polling = true;
}
}
assert(pipe != NULL);
if (pipe == NULL)
return IA_CSS_ERR_INTERNAL_ERROR;
if (pipe->pipeline.stages != NULL)
if (pipe->pipeline.stages->binary != NULL)
binary = pipe->pipeline.stages->binary;
if (binary) {
ia_css_get_crop_offsets(pipe, &binary->in_frame_info);
}
rc = ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &sp_thread_id);
if (rc != true)
return IA_CSS_ERR_INTERNAL_ERROR;
sp_pipeline_input_terminal = &(sh_css_sp_group.pipe_io[sp_thread_id].input);
for (i = 0; i < IA_CSS_STREAM_MAX_ISYS_STREAM_PER_CH; i++) {
memset((void*)(&isys_stream_descr), 0, sizeof(ia_css_isys_descr_t));
sp_pipeline_input_terminal->context.virtual_input_system_stream[i].valid = 0;
sp_pipeline_input_terminal->ctrl.virtual_input_system_stream_cfg[i].valid = 0;
if (!stream->config.isys_config[i].valid)
continue;
rc = sh_css_translate_stream_cfg_to_isys_stream_descr(
&(stream->config),
early_polling,
&(isys_stream_descr), i);
if (stream->config.online) {
rc &= sh_css_translate_binary_info_to_input_system_output_port_attr(
binary,
&(isys_stream_descr));
}
if (rc != true)
return IA_CSS_ERR_INTERNAL_ERROR;
isys_stream_id = ia_css_isys_generate_stream_id(sp_thread_id, i);
rc = ia_css_isys_stream_create(
&(isys_stream_descr),
&(sp_pipeline_input_terminal->context.virtual_input_system_stream[i]),
isys_stream_id);
if (rc != true)
return IA_CSS_ERR_INTERNAL_ERROR;
rc = ia_css_isys_stream_calculate_cfg(
&(sp_pipeline_input_terminal->context.virtual_input_system_stream[i]),
&(isys_stream_descr),
&(sp_pipeline_input_terminal->ctrl.virtual_input_system_stream_cfg[i]));
if (rc != true) {
ia_css_isys_stream_destroy(&(sp_pipeline_input_terminal->context.virtual_input_system_stream[i]));
return IA_CSS_ERR_INTERNAL_ERROR;
}
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_config_input_network() leave:\n");
return IA_CSS_SUCCESS;
}
static inline struct ia_css_pipe *stream_get_last_pipe(
struct ia_css_stream *stream)
{
struct ia_css_pipe *last_pipe = NULL;
if (stream != NULL)
last_pipe = stream->last_pipe;
return last_pipe;
}
static inline struct ia_css_pipe *stream_get_copy_pipe(
struct ia_css_stream *stream)
{
struct ia_css_pipe *copy_pipe = NULL;
struct ia_css_pipe *last_pipe = NULL;
enum ia_css_pipe_id pipe_id;
last_pipe = stream_get_last_pipe(stream);
if ((stream != NULL) &&
(last_pipe != NULL) &&
(stream->config.continuous)) {
pipe_id = last_pipe->mode;
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
copy_pipe = last_pipe->pipe_settings.preview.copy_pipe;
break;
case IA_CSS_PIPE_ID_VIDEO:
copy_pipe = last_pipe->pipe_settings.video.copy_pipe;
break;
default:
copy_pipe = NULL;
break;
}
}
return copy_pipe;
}
static inline struct ia_css_pipe *stream_get_target_pipe(
struct ia_css_stream *stream)
{
struct ia_css_pipe *target_pipe;
if (stream->config.continuous) {
target_pipe = stream_get_copy_pipe(stream);
} else {
target_pipe = stream_get_last_pipe(stream);
}
return target_pipe;
}
static inline enum ia_css_err stream_register_with_csi_rx(
struct ia_css_stream *stream)
{
return stream_csi_rx_helper(stream, ia_css_isys_csi_rx_register_stream);
}
static inline enum ia_css_err stream_unregister_with_csi_rx(
struct ia_css_stream *stream)
{
return stream_csi_rx_helper(stream, ia_css_isys_csi_rx_unregister_stream);
}
static void print_pc_histo(char *core_name, struct sh_css_pc_histogram *hist)
{
unsigned i;
unsigned cnt_run = 0;
unsigned cnt_stall = 0;
if (hist == NULL)
return;
sh_css_print("%s histogram length = %d\n", core_name, hist->length);
sh_css_print("%s PC\trun\tstall\n", core_name);
for (i = 0; i < hist->length; i++) {
if ((hist->run[i] == 0) && (hist->run[i] == hist->stall[i]))
continue;
sh_css_print("%s %d\t%d\t%d\n",
core_name, i, hist->run[i], hist->stall[i]);
cnt_run += hist->run[i];
cnt_stall += hist->stall[i];
}
sh_css_print(" Statistics for %s, cnt_run = %d, cnt_stall = %d, "
"hist->length = %d\n",
core_name, cnt_run, cnt_stall, hist->length);
}
static void print_pc_histogram(void)
{
struct ia_css_binary_metrics *metrics;
for (metrics = sh_css_metrics.binary_metrics;
metrics;
metrics = metrics->next) {
if (metrics->mode == IA_CSS_BINARY_MODE_PREVIEW ||
metrics->mode == IA_CSS_BINARY_MODE_VF_PP) {
sh_css_print("pc_histogram for binary %d is SKIPPED\n",
metrics->id);
continue;
}
sh_css_print(" pc_histogram for binary %d\n", metrics->id);
print_pc_histo(" ISP", &metrics->isp_histogram);
print_pc_histo(" SP", &metrics->sp_histogram);
sh_css_print("print_pc_histogram() done for binay->id = %d, "
"done.\n", metrics->id);
}
sh_css_print("PC_MONITORING:print_pc_histogram() -- DONE\n");
}
static int pc_monitoring(void *data)
{
int i = 0;
(void)data;
while (true) {
if (sh_binary_running) {
sh_css_metrics_sample_pcs();
#if MULTIPLE_SAMPLES
for (i = 0; i < NOF_SAMPLES; i++)
sh_css_metrics_sample_pcs();
#endif
}
usleep_range(10, 50);
}
return 0;
}
static void spying_thread_create(void)
{
my_kthread = kthread_run(pc_monitoring, NULL, "sh_pc_monitor");
sh_css_metrics_enable_pc_histogram(1);
}
static void input_frame_info(struct ia_css_frame_info frame_info)
{
sh_css_print("SH_CSS:input_frame_info() -- frame->info.res.width = %d, "
"frame->info.res.height = %d, format = %d\n",
frame_info.res.width, frame_info.res.height, frame_info.format);
}
static void
start_binary(struct ia_css_pipe *pipe,
struct ia_css_binary *binary)
{
struct ia_css_stream *stream;
assert(pipe != NULL);
(void)binary;
#if !defined(HAS_NO_INPUT_SYSTEM)
stream = pipe->stream;
#else
(void)pipe;
(void)stream;
#endif
if (binary)
sh_css_metrics_start_binary(&binary->metrics);
#if WITH_PC_MONITORING
sh_css_print("PC_MONITORING: %s() -- binary id = %d , "
"enable_dvs_envelope = %d\n",
__func__, binary->info->sp.id,
binary->info->sp.enable.dvs_envelope);
input_frame_info(binary->in_frame_info);
if (binary && binary->info->sp.pipeline.mode == IA_CSS_BINARY_MODE_VIDEO)
sh_binary_running = true;
#endif
#if !defined(HAS_NO_INPUT_SYSTEM) && !defined(USE_INPUT_SYSTEM_VERSION_2401)
if (stream->reconfigure_css_rx) {
ia_css_isys_rx_configure(&pipe->stream->csi_rx_config,
pipe->stream->config.mode);
stream->reconfigure_css_rx = false;
}
#endif
}
static enum ia_css_err
start_copy_on_sp(struct ia_css_pipe *pipe,
struct ia_css_frame *out_frame)
{
(void)out_frame;
assert(pipe != NULL);
assert(pipe->stream != NULL);
if ((pipe == NULL) || (pipe->stream == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
#if !defined(HAS_NO_INPUT_SYSTEM) && !defined(USE_INPUT_SYSTEM_VERSION_2401)
if (pipe->stream->reconfigure_css_rx)
ia_css_isys_rx_disable();
#endif
if (pipe->stream->config.input_config.format != IA_CSS_STREAM_FORMAT_BINARY_8)
return IA_CSS_ERR_INTERNAL_ERROR;
sh_css_sp_start_binary_copy(ia_css_pipe_get_pipe_num(pipe), out_frame, pipe->stream->config.pixels_per_clock == 2);
#if !defined(HAS_NO_INPUT_SYSTEM) && !defined(USE_INPUT_SYSTEM_VERSION_2401)
if (pipe->stream->reconfigure_css_rx) {
ia_css_isys_rx_configure(&pipe->stream->csi_rx_config, pipe->stream->config.mode);
pipe->stream->reconfigure_css_rx = false;
}
#endif
return IA_CSS_SUCCESS;
}
void sh_css_binary_args_reset(struct sh_css_binary_args *args)
{
unsigned int i;
#ifndef ISP2401
for (i = 0; i < NUM_VIDEO_TNR_FRAMES; i++)
#else
for (i = 0; i < NUM_TNR_FRAMES; i++)
#endif
args->tnr_frames[i] = NULL;
for (i = 0; i < MAX_NUM_VIDEO_DELAY_FRAMES; i++)
args->delay_frames[i] = NULL;
args->in_frame = NULL;
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++)
args->out_frame[i] = NULL;
args->out_vf_frame = NULL;
args->copy_vf = false;
args->copy_output = true;
args->vf_downscale_log2 = 0;
}
static void start_pipe(
struct ia_css_pipe *me,
enum sh_css_pipe_config_override copy_ovrd,
enum ia_css_input_mode input_mode)
{
#if defined(HAS_NO_INPUT_SYSTEM)
(void)input_mode;
#endif
IA_CSS_ENTER_PRIVATE("me = %p, copy_ovrd = %d, input_mode = %d",
me, copy_ovrd, input_mode);
assert(me != NULL);
sh_css_sp_init_pipeline(&me->pipeline,
me->mode,
(uint8_t)ia_css_pipe_get_pipe_num(me),
me->config.default_capture_config.enable_xnr != 0,
me->stream->config.pixels_per_clock == 2,
me->stream->config.continuous,
false,
me->required_bds_factor,
copy_ovrd,
input_mode,
&me->stream->config.metadata_config,
&me->stream->info.metadata_info
#if !defined(HAS_NO_INPUT_SYSTEM)
,(input_mode==IA_CSS_INPUT_MODE_MEMORY) ?
(mipi_port_ID_t)0 :
me->stream->config.source.port.port
#endif
#ifdef ISP2401
,&me->config.internal_frame_origin_bqs_on_sctbl,
me->stream->isp_params_configs
#endif
);
if (me->config.mode != IA_CSS_PIPE_MODE_COPY) {
struct ia_css_pipeline_stage *stage;
stage = me->pipeline.stages;
if (stage) {
me->pipeline.current_stage = stage;
start_binary(me, stage->binary);
}
}
IA_CSS_LEAVE_PRIVATE("void");
}
void
sh_css_invalidate_shading_tables(struct ia_css_stream *stream)
{
int i;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_invalidate_shading_tables() enter:\n");
for (i=0; i<stream->num_pipes; i++) {
assert(stream->pipes[i] != NULL);
sh_css_pipe_free_shading_table(stream->pipes[i]);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_invalidate_shading_tables() leave: return_void\n");
}
static void
enable_interrupts(enum ia_css_irq_type irq_type)
{
#ifdef USE_INPUT_SYSTEM_VERSION_2
mipi_port_ID_t port;
#endif
bool enable_pulse = irq_type != IA_CSS_IRQ_TYPE_EDGE;
IA_CSS_ENTER_PRIVATE("");
cnd_sp_irq_enable(SP0_ID, true);
irq_enable_pulse(IRQ0_ID, enable_pulse);
cnd_virq_enable_channel(virq_sp, true);
cnd_virq_enable_channel(
(virq_id_t)(IRQ_SW_CHANNEL0_ID + IRQ_SW_CHANNEL_OFFSET),
true);
cnd_virq_enable_channel(
(virq_id_t)(IRQ_SW_CHANNEL1_ID + IRQ_SW_CHANNEL_OFFSET),
true);
#if !defined(HAS_IRQ_MAP_VERSION_2)
cnd_virq_enable_channel(
(virq_id_t)(IRQ_SW_CHANNEL2_ID + IRQ_SW_CHANNEL_OFFSET),
true);
virq_clear_all();
#endif
#ifdef USE_INPUT_SYSTEM_VERSION_2
for (port = 0; port < N_MIPI_PORT_ID; port++)
ia_css_isys_rx_enable_all_interrupts(port);
#endif
IA_CSS_LEAVE_PRIVATE("");
}
static bool sh_css_setup_spctrl_config(const struct ia_css_fw_info *fw,
const char * program,
ia_css_spctrl_cfg *spctrl_cfg)
{
if((fw == NULL)||(spctrl_cfg == NULL))
return false;
spctrl_cfg->sp_entry = 0;
spctrl_cfg->program_name = (char *)(program);
spctrl_cfg->ddr_data_offset = fw->blob.data_source;
spctrl_cfg->dmem_data_addr = fw->blob.data_target;
spctrl_cfg->dmem_bss_addr = fw->blob.bss_target;
spctrl_cfg->data_size = fw->blob.data_size ;
spctrl_cfg->bss_size = fw->blob.bss_size;
spctrl_cfg->spctrl_config_dmem_addr = fw->info.sp.init_dmem_data;
spctrl_cfg->spctrl_state_dmem_addr = fw->info.sp.sw_state;
spctrl_cfg->code_size = fw->blob.size;
spctrl_cfg->code = fw->blob.code;
spctrl_cfg->sp_entry = fw->info.sp.sp_entry;
return true;
}
void
ia_css_unload_firmware(void)
{
if (sh_css_num_binaries)
{
ia_css_binary_uninit();
sh_css_unload_firmware();
}
fw_explicitly_loaded = false;
}
static void
ia_css_reset_defaults(struct sh_css* css)
{
struct sh_css default_css;
memset(&default_css, 0, sizeof(default_css));
default_css.check_system_idle = true;
default_css.num_cont_raw_frames = NUM_CONTINUOUS_FRAMES;
default_css.irq_type = IA_CSS_IRQ_TYPE_EDGE;
*css = default_css;
}
bool
ia_css_check_firmware_version(const struct ia_css_fw *fw)
{
bool retval = false;
if (fw != NULL) {
retval = sh_css_check_firmware_version(fw->data);
}
return retval;
}
enum ia_css_err
ia_css_load_firmware(const struct ia_css_env *env,
const struct ia_css_fw *fw)
{
enum ia_css_err err;
if (env == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (fw == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_load_firmware() enter\n");
if (my_css.flush != env->cpu_mem_env.flush) {
ia_css_reset_defaults(&my_css);
my_css.flush = env->cpu_mem_env.flush;
}
ia_css_unload_firmware();
err = sh_css_load_firmware(fw->data, fw->bytes);
if (err == IA_CSS_SUCCESS) {
err = ia_css_binary_init_infos();
if (err == IA_CSS_SUCCESS)
fw_explicitly_loaded = true;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_load_firmware() leave \n");
return err;
}
enum ia_css_err
ia_css_init(const struct ia_css_env *env,
const struct ia_css_fw *fw,
uint32_t mmu_l1_base,
enum ia_css_irq_type irq_type)
{
enum ia_css_err err;
ia_css_spctrl_cfg spctrl_cfg;
void (*flush_func)(struct ia_css_acc_fw *fw);
hrt_data select, enable;
COMPILATION_ERROR_IF( sizeof(struct sh_css_ddr_address_map) != SIZE_OF_SH_CSS_DDR_ADDRESS_MAP_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct host_sp_queues) != SIZE_OF_HOST_SP_QUEUES_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_circbuf_desc_s) != SIZE_OF_IA_CSS_CIRCBUF_DESC_S_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_circbuf_elem_s) != SIZE_OF_IA_CSS_CIRCBUF_ELEM_S_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct host_sp_communication) != SIZE_OF_HOST_SP_COMMUNICATION_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct sh_css_event_irq_mask) != SIZE_OF_SH_CSS_EVENT_IRQ_MASK_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct sh_css_hmm_buffer) != SIZE_OF_SH_CSS_HMM_BUFFER_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_isp_3a_statistics) != SIZE_OF_IA_CSS_ISP_3A_STATISTICS_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_isp_dvs_statistics) != SIZE_OF_IA_CSS_ISP_DVS_STATISTICS_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_metadata) != SIZE_OF_IA_CSS_METADATA_STRUCT );
COMPILATION_ERROR_IF( sizeof(struct ia_css_sp_init_dmem_cfg) != SIZE_OF_IA_CSS_SP_INIT_DMEM_CFG_STRUCT );
if (fw == NULL && !fw_explicitly_loaded)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (env == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
sh_css_printf = env->print_env.debug_print;
IA_CSS_ENTER("void");
flush_func = env->cpu_mem_env.flush;
pipe_global_init();
ia_css_pipeline_init();
ia_css_queue_map_init();
ia_css_device_access_init(&env->hw_access_env);
select = gpio_reg_load(GPIO0_ID, _gpio_block_reg_do_select)
& (~GPIO_FLASH_PIN_MASK);
enable = gpio_reg_load(GPIO0_ID, _gpio_block_reg_do_e)
| GPIO_FLASH_PIN_MASK;
sh_css_mmu_set_page_table_base_index(mmu_l1_base);
#ifndef ISP2401
my_css_save.mmu_base = mmu_l1_base;
#else
ia_css_save_mmu_base_addr(mmu_l1_base);
#endif
ia_css_reset_defaults(&my_css);
my_css_save.driver_env = *env;
my_css.flush = flush_func;
err = ia_css_rmgr_init();
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
#ifndef ISP2401
IA_CSS_LOG("init: %d", my_css_save_initialized);
#else
ia_css_save_restore_data_init();
#endif
#ifndef ISP2401
if (!my_css_save_initialized)
{
my_css_save_initialized = true;
my_css_save.mode = sh_css_mode_working;
memset(my_css_save.stream_seeds, 0, sizeof(struct sh_css_stream_seed) * MAX_ACTIVE_STREAMS);
IA_CSS_LOG("init: %d mode=%d", my_css_save_initialized, my_css_save.mode);
}
#endif
mipi_init();
#ifndef ISP2401
my_css.page_table_base_index = mmu_get_page_table_base_index(MMU0_ID);
#endif
my_css.irq_type = irq_type;
#ifndef ISP2401
my_css_save.irq_type = irq_type;
#else
ia_css_save_irq_type(irq_type);
#endif
enable_interrupts(my_css.irq_type);
gpio_reg_store(GPIO0_ID, _gpio_block_reg_do_select, select);
gpio_reg_store(GPIO0_ID, _gpio_block_reg_do_e, enable);
gpio_reg_store(GPIO0_ID, _gpio_block_reg_do_0, 0);
err = ia_css_refcount_init(REFCOUNT_SIZE);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
err = sh_css_params_init();
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
if (fw)
{
ia_css_unload_firmware();
err = sh_css_load_firmware(fw->data, fw->bytes);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
err = ia_css_binary_init_infos();
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
fw_explicitly_loaded = false;
#ifndef ISP2401
my_css_save.loaded_fw = (struct ia_css_fw *)fw;
#endif
}
if(!sh_css_setup_spctrl_config(&sh_css_sp_fw,SP_PROG_NAME,&spctrl_cfg))
return IA_CSS_ERR_INTERNAL_ERROR;
err = ia_css_spctrl_load_fw(SP0_ID, &spctrl_cfg);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
#if WITH_PC_MONITORING
if (!thread_alive) {
thread_alive++;
sh_css_print("PC_MONITORING: %s() -- create thread DISABLED\n",
__func__);
spying_thread_create();
}
#endif
if (!sh_css_hrt_system_is_idle()) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_SYSTEM_NOT_IDLE);
return IA_CSS_ERR_SYSTEM_NOT_IDLE;
}
#if defined(HAS_INPUT_SYSTEM_VERSION_2) && defined(HAS_INPUT_SYSTEM_VERSION_2401)
#if defined(USE_INPUT_SYSTEM_VERSION_2)
gp_device_reg_store(GP_DEVICE0_ID, _REG_GP_SWITCH_ISYS2401_ADDR, 0);
#elif defined (USE_INPUT_SYSTEM_VERSION_2401)
gp_device_reg_store(GP_DEVICE0_ID, _REG_GP_SWITCH_ISYS2401_ADDR, 1);
#endif
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
dma_set_max_burst_size(DMA0_ID, HIVE_DMA_BUS_DDR_CONN,
ISP_DMA_MAX_BURST_LENGTH);
if(ia_css_isys_init() != INPUT_SYSTEM_ERR_NO_ERROR)
err = IA_CSS_ERR_INVALID_ARGUMENTS;
#endif
sh_css_params_map_and_store_default_gdc_lut();
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err ia_css_suspend(void)
{
int i;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_suspend() enter\n");
my_css_save.mode = sh_css_mode_suspend;
for(i=0;i<MAX_ACTIVE_STREAMS;i++)
if (my_css_save.stream_seeds[i].stream != NULL)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "==*> unloading seed %d (%p)\n", i, my_css_save.stream_seeds[i].stream);
ia_css_stream_unload(my_css_save.stream_seeds[i].stream);
}
my_css_save.mode = sh_css_mode_working;
ia_css_stop_sp();
ia_css_uninit();
for(i=0;i<MAX_ACTIVE_STREAMS;i++)
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "==*> after 1: seed %d (%p)\n", i, my_css_save.stream_seeds[i].stream);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_suspend() leave\n");
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_resume(void)
{
int i, j;
enum ia_css_err err;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_resume() enter: void\n");
err = ia_css_init(&(my_css_save.driver_env), my_css_save.loaded_fw, my_css_save.mmu_base, my_css_save.irq_type);
if (err != IA_CSS_SUCCESS)
return err;
err = ia_css_start_sp();
if (err != IA_CSS_SUCCESS)
return err;
my_css_save.mode = sh_css_mode_resume;
for(i=0;i<MAX_ACTIVE_STREAMS;i++)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "==*> seed stream %p\n", my_css_save.stream_seeds[i].stream);
if (my_css_save.stream_seeds[i].stream != NULL)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "==*> loading seed %d\n", i);
err = ia_css_stream_load(my_css_save.stream_seeds[i].stream);
if (err != IA_CSS_SUCCESS)
{
if (i)
for(j=0;j<i;j++)
ia_css_stream_unload(my_css_save.stream_seeds[j].stream);
return err;
}
err = ia_css_stream_start(my_css_save.stream_seeds[i].stream);
if (err != IA_CSS_SUCCESS)
{
for(j=0;j<=i;j++)
{
ia_css_stream_stop(my_css_save.stream_seeds[j].stream);
ia_css_stream_unload(my_css_save.stream_seeds[j].stream);
}
return err;
}
*my_css_save.stream_seeds[i].orig_stream = my_css_save.stream_seeds[i].stream;
for(j=0;j<my_css_save.stream_seeds[i].num_pipes;j++)
*(my_css_save.stream_seeds[i].orig_pipes[j]) = my_css_save.stream_seeds[i].pipes[j];
}
}
my_css_save.mode = sh_css_mode_working;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_resume() leave: return_void\n");
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_enable_isys_event_queue(bool enable)
{
if (sh_css_sp_is_running())
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
sh_css_sp_enable_isys_event_queue(enable);
return IA_CSS_SUCCESS;
}
void *sh_css_malloc(size_t size)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "sh_css_malloc() enter: size=%zu\n",size);
if (size == 0)
return NULL;
if (size > PAGE_SIZE)
return vmalloc(size);
return kmalloc(size, GFP_KERNEL);
}
void *sh_css_calloc(size_t N, size_t size)
{
void *p;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "sh_css_calloc() enter: N=%zu, size=%zu\n",N,size);
if (size > 0) {
p = sh_css_malloc(N*size);
if (p)
memset(p, 0, size);
return p;
}
return NULL;
}
void sh_css_free(void *ptr)
{
if (is_vmalloc_addr(ptr))
vfree(ptr);
else
kfree(ptr);
}
void
sh_css_flush(struct ia_css_acc_fw *fw)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "sh_css_flush() enter:\n");
if ((fw != NULL) && (my_css.flush != NULL))
my_css.flush(fw);
}
static enum ia_css_err
map_sp_threads(struct ia_css_stream *stream, bool map)
{
struct ia_css_pipe *main_pipe = NULL;
struct ia_css_pipe *copy_pipe = NULL;
struct ia_css_pipe *capture_pipe = NULL;
struct ia_css_pipe *acc_pipe = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
enum ia_css_pipe_id pipe_id;
assert(stream != NULL);
IA_CSS_ENTER_PRIVATE("stream = %p, map = %s",
stream, map ? "true" : "false");
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
main_pipe = stream->last_pipe;
pipe_id = main_pipe->mode;
ia_css_pipeline_map(main_pipe->pipe_num, map);
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
capture_pipe = main_pipe->pipe_settings.preview.capture_pipe;
acc_pipe = main_pipe->pipe_settings.preview.acc_pipe;
break;
case IA_CSS_PIPE_ID_VIDEO:
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
capture_pipe = main_pipe->pipe_settings.video.capture_pipe;
break;
case IA_CSS_PIPE_ID_CAPTURE:
case IA_CSS_PIPE_ID_ACC:
default:
break;
}
if (acc_pipe) {
ia_css_pipeline_map(acc_pipe->pipe_num, map);
}
if(capture_pipe) {
ia_css_pipeline_map(capture_pipe->pipe_num, map);
}
if(copy_pipe) {
ia_css_pipeline_map(copy_pipe->pipe_num, map);
}
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes; i++)
ia_css_pipeline_map(stream->pipes[i]->pipe_num, map);
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
create_host_pipeline_structure(struct ia_css_stream *stream)
{
struct ia_css_pipe *copy_pipe = NULL, *capture_pipe = NULL;
struct ia_css_pipe *acc_pipe = NULL;
enum ia_css_pipe_id pipe_id;
struct ia_css_pipe *main_pipe = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int copy_pipe_delay = 0,
capture_pipe_delay = 0;
assert(stream != NULL);
IA_CSS_ENTER_PRIVATE("stream = %p", stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
main_pipe = stream->last_pipe;
assert(main_pipe != NULL);
if (main_pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe_id = main_pipe->mode;
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
copy_pipe_delay = main_pipe->dvs_frame_delay;
capture_pipe = main_pipe->pipe_settings.preview.capture_pipe;
capture_pipe_delay = IA_CSS_FRAME_DELAY_0;
acc_pipe = main_pipe->pipe_settings.preview.acc_pipe;
err = ia_css_pipeline_create(&main_pipe->pipeline, main_pipe->mode, main_pipe->pipe_num, main_pipe->dvs_frame_delay);
break;
case IA_CSS_PIPE_ID_VIDEO:
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
copy_pipe_delay = main_pipe->dvs_frame_delay;
capture_pipe = main_pipe->pipe_settings.video.capture_pipe;
capture_pipe_delay = IA_CSS_FRAME_DELAY_0;
err = ia_css_pipeline_create(&main_pipe->pipeline, main_pipe->mode, main_pipe->pipe_num, main_pipe->dvs_frame_delay);
break;
case IA_CSS_PIPE_ID_CAPTURE:
capture_pipe = main_pipe;
capture_pipe_delay = main_pipe->dvs_frame_delay;
break;
case IA_CSS_PIPE_ID_YUVPP:
err = ia_css_pipeline_create(&main_pipe->pipeline, main_pipe->mode,
main_pipe->pipe_num, main_pipe->dvs_frame_delay);
break;
case IA_CSS_PIPE_ID_ACC:
err = ia_css_pipeline_create(&main_pipe->pipeline, main_pipe->mode, main_pipe->pipe_num, main_pipe->dvs_frame_delay);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((IA_CSS_SUCCESS == err) && copy_pipe) {
err = ia_css_pipeline_create(&copy_pipe->pipeline,
copy_pipe->mode,
copy_pipe->pipe_num,
copy_pipe_delay);
}
if ((IA_CSS_SUCCESS == err) && capture_pipe) {
err = ia_css_pipeline_create(&capture_pipe->pipeline,
capture_pipe->mode,
capture_pipe->pipe_num,
capture_pipe_delay);
}
if ((IA_CSS_SUCCESS == err) && acc_pipe) {
err = ia_css_pipeline_create(&acc_pipe->pipeline, acc_pipe->mode, acc_pipe->pipe_num, main_pipe->dvs_frame_delay);
}
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes && IA_CSS_SUCCESS == err; i++) {
main_pipe = stream->pipes[i];
err = ia_css_pipeline_create(&main_pipe->pipeline,
main_pipe->mode,
main_pipe->pipe_num,
main_pipe->dvs_frame_delay);
}
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
create_host_pipeline(struct ia_css_stream *stream)
{
struct ia_css_pipe *copy_pipe = NULL, *capture_pipe = NULL;
struct ia_css_pipe *acc_pipe = NULL;
enum ia_css_pipe_id pipe_id;
struct ia_css_pipe *main_pipe = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned max_input_width = 0;
IA_CSS_ENTER_PRIVATE("stream = %p", stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
main_pipe = stream->last_pipe;
pipe_id = main_pipe->mode;
if ((pipe_id == IA_CSS_PIPE_ID_PREVIEW) ||
(pipe_id == IA_CSS_PIPE_ID_VIDEO)) {
if (stream->config.continuous ||
(pipe_id == IA_CSS_PIPE_ID_PREVIEW && stream->config.mode != IA_CSS_INPUT_MODE_MEMORY)) {
err = alloc_continuous_frames(main_pipe, true);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
}
#if defined(USE_INPUT_SYSTEM_VERSION_2)
if (pipe_id != IA_CSS_PIPE_ID_ACC) {
err = allocate_mipi_frames(main_pipe, &stream->info);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
#elif defined(USE_INPUT_SYSTEM_VERSION_2401)
if ((pipe_id != IA_CSS_PIPE_ID_ACC) &&
(main_pipe->config.mode != IA_CSS_PIPE_MODE_COPY)) {
err = allocate_mipi_frames(main_pipe, &stream->info);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
#endif
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
capture_pipe = main_pipe->pipe_settings.preview.capture_pipe;
acc_pipe = main_pipe->pipe_settings.preview.acc_pipe;
max_input_width =
main_pipe->pipe_settings.preview.preview_binary.info->sp.input.max_width;
err = create_host_preview_pipeline(main_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
break;
case IA_CSS_PIPE_ID_VIDEO:
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
capture_pipe = main_pipe->pipe_settings.video.capture_pipe;
max_input_width =
main_pipe->pipe_settings.video.video_binary.info->sp.input.max_width;
err = create_host_video_pipeline(main_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
break;
case IA_CSS_PIPE_ID_CAPTURE:
capture_pipe = main_pipe;
break;
case IA_CSS_PIPE_ID_YUVPP:
err = create_host_yuvpp_pipeline(main_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
break;
case IA_CSS_PIPE_ID_ACC:
err = create_host_acc_pipeline(main_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (err != IA_CSS_SUCCESS)
goto ERR;
if(copy_pipe) {
err = create_host_copy_pipeline(copy_pipe, max_input_width,
main_pipe->continuous_frames[0]);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
if(capture_pipe) {
err = create_host_capture_pipeline(capture_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
if (acc_pipe) {
err = create_host_acc_pipeline(acc_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes && IA_CSS_SUCCESS == err; i++) {
switch (stream->pipes[i]->mode) {
case IA_CSS_PIPE_ID_PREVIEW:
err = create_host_preview_pipeline(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_VIDEO:
err = create_host_video_pipeline(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_CAPTURE:
err = create_host_capture_pipeline(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_YUVPP:
err = create_host_yuvpp_pipeline(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_ACC:
err = create_host_acc_pipeline(stream->pipes[i]);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (err != IA_CSS_SUCCESS)
goto ERR;
}
}
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
init_pipe_defaults(enum ia_css_pipe_mode mode,
struct ia_css_pipe *pipe,
bool copy_pipe)
{
static struct ia_css_pipe default_pipe = IA_CSS_DEFAULT_PIPE;
static struct ia_css_preview_settings prev = IA_CSS_DEFAULT_PREVIEW_SETTINGS;
static struct ia_css_capture_settings capt = IA_CSS_DEFAULT_CAPTURE_SETTINGS;
static struct ia_css_video_settings video = IA_CSS_DEFAULT_VIDEO_SETTINGS;
static struct ia_css_yuvpp_settings yuvpp = IA_CSS_DEFAULT_YUVPP_SETTINGS;
if (pipe == NULL) {
IA_CSS_ERROR("NULL pipe parameter");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
*pipe = default_pipe;
switch (mode) {
case IA_CSS_PIPE_MODE_PREVIEW:
pipe->mode = IA_CSS_PIPE_ID_PREVIEW;
pipe->pipe_settings.preview = prev;
break;
case IA_CSS_PIPE_MODE_CAPTURE:
if (copy_pipe) {
pipe->mode = IA_CSS_PIPE_ID_COPY;
} else {
pipe->mode = IA_CSS_PIPE_ID_CAPTURE;
}
pipe->pipe_settings.capture = capt;
break;
case IA_CSS_PIPE_MODE_VIDEO:
pipe->mode = IA_CSS_PIPE_ID_VIDEO;
pipe->pipe_settings.video = video;
break;
case IA_CSS_PIPE_MODE_ACC:
pipe->mode = IA_CSS_PIPE_ID_ACC;
break;
case IA_CSS_PIPE_MODE_COPY:
pipe->mode = IA_CSS_PIPE_ID_CAPTURE;
break;
case IA_CSS_PIPE_MODE_YUVPP:
pipe->mode = IA_CSS_PIPE_ID_YUVPP;
pipe->pipe_settings.yuvpp = yuvpp;
break;
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
return IA_CSS_SUCCESS;
}
static void
pipe_global_init(void)
{
uint8_t i;
my_css.pipe_counter = 0;
for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++) {
my_css.all_pipes[i] = NULL;
}
}
static enum ia_css_err
pipe_generate_pipe_num(const struct ia_css_pipe *pipe, unsigned int *pipe_number)
{
const uint8_t INVALID_PIPE_NUM = (uint8_t)~(0);
uint8_t pipe_num = INVALID_PIPE_NUM;
uint8_t i;
if (pipe == NULL) {
IA_CSS_ERROR("NULL pipe parameter");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++) {
if (my_css.all_pipes[i] == NULL) {
my_css.all_pipes[i] = (struct ia_css_pipe *)pipe;
pipe_num = i;
break;
}
}
if (pipe_num == INVALID_PIPE_NUM) {
IA_CSS_ERROR("Max number of pipes already created");
return IA_CSS_ERR_RESOURCE_EXHAUSTED;
}
my_css.pipe_counter++;
IA_CSS_LOG("pipe_num (%d)", pipe_num);
*pipe_number = pipe_num;
return IA_CSS_SUCCESS;
}
static void
pipe_release_pipe_num(unsigned int pipe_num)
{
my_css.all_pipes[pipe_num] = NULL;
my_css.pipe_counter--;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"pipe_release_pipe_num (%d)\n", pipe_num);
}
static enum ia_css_err
create_pipe(enum ia_css_pipe_mode mode,
struct ia_css_pipe **pipe,
bool copy_pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *me;
if (pipe == NULL) {
IA_CSS_ERROR("NULL pipe parameter");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
me = kmalloc(sizeof(*me), GFP_KERNEL);
if (!me)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
err = init_pipe_defaults(mode, me, copy_pipe);
if (err != IA_CSS_SUCCESS) {
kfree(me);
return err;
}
err = pipe_generate_pipe_num(me, &(me->pipe_num));
if (err != IA_CSS_SUCCESS) {
kfree(me);
return err;
}
*pipe = me;
return IA_CSS_SUCCESS;
}
struct ia_css_pipe *
find_pipe_by_num(uint32_t pipe_num)
{
unsigned int i;
for (i = 0; i < IA_CSS_PIPELINE_NUM_MAX; i++){
if (my_css.all_pipes[i] &&
ia_css_pipe_get_pipe_num(my_css.all_pipes[i]) == pipe_num) {
return my_css.all_pipes[i];
}
}
return NULL;
}
static void sh_css_pipe_free_acc_binaries (
struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *pipeline;
struct ia_css_pipeline_stage *stage;
assert(pipe != NULL);
if (pipe == NULL) {
IA_CSS_ERROR("NULL input pointer");
return;
}
pipeline = &pipe->pipeline;
for (stage = pipeline->stages; stage; stage = stage->next) {
struct ia_css_fw_info *firmware = (struct ia_css_fw_info *)
stage->firmware;
if (firmware)
ia_css_pipe_unload_extension(pipe, firmware);
}
}
enum ia_css_err
ia_css_pipe_destroy(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("pipe = %p", pipe);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe->stream != NULL) {
IA_CSS_LOG("ia_css_stream_destroy not called!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
switch (pipe->config.mode) {
case IA_CSS_PIPE_MODE_PREVIEW:
if (pipe->mode == IA_CSS_PIPE_ID_PREVIEW) {
ia_css_frame_free_multiple(NUM_CONTINUOUS_FRAMES,
pipe->continuous_frames);
ia_css_metadata_free_multiple(NUM_CONTINUOUS_FRAMES,
pipe->cont_md_buffers);
if (pipe->pipe_settings.preview.copy_pipe) {
err = ia_css_pipe_destroy(pipe->pipe_settings.preview.copy_pipe);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_pipe_destroy(): "
"destroyed internal copy pipe err=%d\n", err);
}
}
break;
case IA_CSS_PIPE_MODE_VIDEO:
if (pipe->mode == IA_CSS_PIPE_ID_VIDEO) {
ia_css_frame_free_multiple(NUM_CONTINUOUS_FRAMES,
pipe->continuous_frames);
ia_css_metadata_free_multiple(NUM_CONTINUOUS_FRAMES,
pipe->cont_md_buffers);
if (pipe->pipe_settings.video.copy_pipe) {
err = ia_css_pipe_destroy(pipe->pipe_settings.video.copy_pipe);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_pipe_destroy(): "
"destroyed internal copy pipe err=%d\n", err);
}
}
#ifndef ISP2401
ia_css_frame_free_multiple(NUM_VIDEO_TNR_FRAMES, pipe->pipe_settings.video.tnr_frames);
#else
ia_css_frame_free_multiple(NUM_TNR_FRAMES, pipe->pipe_settings.video.tnr_frames);
#endif
ia_css_frame_free_multiple(MAX_NUM_VIDEO_DELAY_FRAMES, pipe->pipe_settings.video.delay_frames);
break;
case IA_CSS_PIPE_MODE_CAPTURE:
ia_css_frame_free_multiple(MAX_NUM_VIDEO_DELAY_FRAMES, pipe->pipe_settings.capture.delay_frames);
break;
case IA_CSS_PIPE_MODE_ACC:
sh_css_pipe_free_acc_binaries(pipe);
break;
case IA_CSS_PIPE_MODE_COPY:
break;
case IA_CSS_PIPE_MODE_YUVPP:
break;
}
sh_css_params_free_gdc_lut(pipe->scaler_pp_lut);
pipe->scaler_pp_lut = mmgr_NULL;
my_css.active_pipes[ia_css_pipe_get_pipe_num(pipe)] = NULL;
sh_css_pipe_free_shading_table(pipe);
ia_css_pipeline_destroy(&pipe->pipeline);
pipe_release_pipe_num(ia_css_pipe_get_pipe_num(pipe));
if (pipe->config.acc_extension) {
ia_css_pipe_unload_extension(pipe, pipe->config.acc_extension);
}
kfree(pipe);
IA_CSS_LEAVE("err = %d", err);
return err;
}
void
ia_css_uninit(void)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_uninit() enter: void\n");
#if WITH_PC_MONITORING
sh_css_print("PC_MONITORING: %s() -- started\n", __func__);
print_pc_histogram();
#endif
sh_css_params_free_default_gdc_lut();
sh_css_params_uninit();
ia_css_refcount_uninit();
ia_css_rmgr_uninit();
#if !defined(HAS_NO_INPUT_FORMATTER)
ifmtr_set_if_blocking_mode_reset = true;
#endif
if (fw_explicitly_loaded == false) {
ia_css_unload_firmware();
}
ia_css_spctrl_unload_fw(SP0_ID);
sh_css_sp_set_sp_running(false);
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
free_mipi_frames(NULL);
#endif
sh_css_sp_reset_global_vars();
#if !defined(HAS_NO_INPUT_SYSTEM)
ia_css_isys_uninit();
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_uninit() leave: return_void\n");
}
enum ia_css_err ia_css_irq_translate(
unsigned int *irq_infos)
{
virq_id_t irq;
enum hrt_isp_css_irq_status status = hrt_isp_css_irq_status_more_irqs;
unsigned int infos = 0;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_irq_translate() enter: irq_infos=%p\n",irq_infos);
while (status == hrt_isp_css_irq_status_more_irqs) {
status = virq_get_channel_id(&irq);
if (status == hrt_isp_css_irq_status_error)
return IA_CSS_ERR_INTERNAL_ERROR;
#if WITH_PC_MONITORING
sh_css_print("PC_MONITORING: %s() irq = %d, "
"sh_binary_running set to 0\n", __func__, irq);
sh_binary_running = 0 ;
#endif
switch (irq) {
case virq_sp:
infos |= IA_CSS_IRQ_INFO_EVENTS_READY;
break;
case virq_isp:
break;
#if !defined(HAS_NO_INPUT_SYSTEM)
case virq_isys_sof:
infos |= IA_CSS_IRQ_INFO_CSS_RECEIVER_SOF;
break;
case virq_isys_eof:
infos |= IA_CSS_IRQ_INFO_CSS_RECEIVER_EOF;
break;
case virq_isys_csi:
infos |= IA_CSS_IRQ_INFO_INPUT_SYSTEM_ERROR;
break;
#endif
#if !defined(HAS_NO_INPUT_FORMATTER)
case virq_ifmt0_id:
infos |= IA_CSS_IRQ_INFO_IF_ERROR;
break;
#endif
case virq_dma:
infos |= IA_CSS_IRQ_INFO_DMA_ERROR;
break;
case virq_sw_pin_0:
infos |= sh_css_get_sw_interrupt_value(0);
break;
case virq_sw_pin_1:
infos |= sh_css_get_sw_interrupt_value(1);
break;
default:
break;
}
}
if (irq_infos)
*irq_infos = infos;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_irq_translate() "
"leave: irq_infos=%u\n", infos);
return IA_CSS_SUCCESS;
}
enum ia_css_err ia_css_irq_enable(
enum ia_css_irq_info info,
bool enable)
{
virq_id_t irq = N_virq_id;
IA_CSS_ENTER("info=%d, enable=%d", info, enable);
switch (info) {
#if !defined(HAS_NO_INPUT_FORMATTER)
case IA_CSS_IRQ_INFO_CSS_RECEIVER_SOF:
irq = virq_isys_sof;
break;
case IA_CSS_IRQ_INFO_CSS_RECEIVER_EOF:
irq = virq_isys_eof;
break;
case IA_CSS_IRQ_INFO_INPUT_SYSTEM_ERROR:
irq = virq_isys_csi;
break;
#endif
#if !defined(HAS_NO_INPUT_FORMATTER)
case IA_CSS_IRQ_INFO_IF_ERROR:
irq = virq_ifmt0_id;
break;
#endif
case IA_CSS_IRQ_INFO_DMA_ERROR:
irq = virq_dma;
break;
case IA_CSS_IRQ_INFO_SW_0:
irq = virq_sw_pin_0;
break;
case IA_CSS_IRQ_INFO_SW_1:
irq = virq_sw_pin_1;
break;
default:
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
cnd_virq_enable_channel(irq, enable);
IA_CSS_LEAVE_ERR(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
void
ia_css_binary_unload(struct ia_css_binary *binary)
{
ia_css_binary_destroy_isp_parameters(binary);
}
static enum ia_css_err
unload_preview_binaries(struct ia_css_pipe *pipe)
{
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_PREVIEW)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.preview.copy_binary);
ia_css_binary_unload(&pipe->pipe_settings.preview.preview_binary);
ia_css_binary_unload(&pipe->pipe_settings.preview.vf_pp_binary);
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static const struct ia_css_fw_info *last_output_firmware(
const struct ia_css_fw_info *fw)
{
const struct ia_css_fw_info *last_fw = NULL;
IA_CSS_ENTER_LEAVE_PRIVATE("");
for (; fw; fw = fw->next) {
const struct ia_css_fw_info *info = fw;
if (info->info.isp.sp.enable.output)
last_fw = fw;
}
return last_fw;
}
static enum ia_css_err add_firmwares(
struct ia_css_pipeline *me,
struct ia_css_binary *binary,
const struct ia_css_fw_info *fw,
const struct ia_css_fw_info *last_fw,
unsigned int binary_mode,
struct ia_css_frame *in_frame,
struct ia_css_frame *out_frame,
struct ia_css_frame *vf_frame,
struct ia_css_pipeline_stage **my_stage,
struct ia_css_pipeline_stage **vf_stage)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipeline_stage *extra_stage = NULL;
struct ia_css_pipeline_stage_desc stage_desc;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"add_firmwares() enter:\n");
for (; fw; fw = fw->next) {
struct ia_css_frame *out[IA_CSS_BINARY_MAX_OUTPUT_PORTS] = {NULL};
struct ia_css_frame *in = NULL;
struct ia_css_frame *vf = NULL;
if ((fw == last_fw) && (fw->info.isp.sp.enable.out_frame != 0)) {
out[0] = out_frame;
}
if (fw->info.isp.sp.enable.in_frame != 0) {
in = in_frame;
}
if (fw->info.isp.sp.enable.out_frame != 0) {
vf = vf_frame;
}
ia_css_pipe_get_firmwares_stage_desc(&stage_desc, binary,
out, in, vf, fw, binary_mode);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&extra_stage);
if (err != IA_CSS_SUCCESS)
return err;
if (fw->info.isp.sp.enable.output != 0)
in_frame = extra_stage->args.out_frame[0];
if (my_stage && !*my_stage && extra_stage)
*my_stage = extra_stage;
if (vf_stage && !*vf_stage && extra_stage &&
fw->info.isp.sp.enable.vf_veceven)
*vf_stage = extra_stage;
}
return err;
}
static enum ia_css_err add_vf_pp_stage(
struct ia_css_pipe *pipe,
struct ia_css_frame *in_frame,
struct ia_css_frame *out_frame,
struct ia_css_binary *vf_pp_binary,
struct ia_css_pipeline_stage **vf_pp_stage)
{
struct ia_css_pipeline *me = NULL;
const struct ia_css_fw_info *last_fw = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_frame *out_frames[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
struct ia_css_pipeline_stage_desc stage_desc;
if (pipe == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (in_frame == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (vf_pp_binary == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (vf_pp_stage == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_pipe_util_create_output_frames(out_frames);
me = &pipe->pipeline;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"add_vf_pp_stage() enter:\n");
*vf_pp_stage = NULL;
last_fw = last_output_firmware(pipe->vf_stage);
if (!pipe->extra_config.disable_vf_pp) {
if (last_fw) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, vf_pp_binary,
out_frames, in_frame, NULL);
} else{
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, vf_pp_binary,
out_frames, in_frame, NULL);
}
err = ia_css_pipeline_create_and_add_stage(me, &stage_desc, vf_pp_stage);
if (err != IA_CSS_SUCCESS)
return err;
in_frame = (*vf_pp_stage)->args.out_frame[0];
}
err = add_firmwares(me, vf_pp_binary, pipe->vf_stage, last_fw,
IA_CSS_BINARY_MODE_VF_PP,
in_frame, out_frame, NULL,
vf_pp_stage, NULL);
return err;
}
static enum ia_css_err add_yuv_scaler_stage(
struct ia_css_pipe *pipe,
struct ia_css_pipeline *me,
struct ia_css_frame *in_frame,
struct ia_css_frame *out_frame,
struct ia_css_frame *internal_out_frame,
struct ia_css_binary *yuv_scaler_binary,
struct ia_css_pipeline_stage **pre_vf_pp_stage)
{
const struct ia_css_fw_info *last_fw;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_frame *vf_frame = NULL;
struct ia_css_frame *out_frames[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
struct ia_css_pipeline_stage_desc stage_desc;
assert(in_frame != NULL);
assert(pipe != NULL);
assert(me != NULL);
assert(yuv_scaler_binary != NULL);
assert(pre_vf_pp_stage != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"add_yuv_scaler_stage() enter:\n");
*pre_vf_pp_stage = NULL;
ia_css_pipe_util_create_output_frames(out_frames);
last_fw = last_output_firmware(pipe->output_stage);
if(last_fw) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc,
yuv_scaler_binary, out_frames, in_frame, vf_frame);
} else {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_util_set_output_frames(out_frames, 1, internal_out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc,
yuv_scaler_binary, out_frames, in_frame, vf_frame);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
pre_vf_pp_stage);
if (err != IA_CSS_SUCCESS)
return err;
in_frame = (*pre_vf_pp_stage)->args.out_frame[0];
err = add_firmwares(me, yuv_scaler_binary, pipe->output_stage, last_fw,
IA_CSS_BINARY_MODE_CAPTURE_PP,
in_frame, out_frame, vf_frame,
NULL, pre_vf_pp_stage);
(*pre_vf_pp_stage)->args.vf_downscale_log2 = yuv_scaler_binary->vf_downscale_log2;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"add_yuv_scaler_stage() leave:\n");
return err;
}
static enum ia_css_err add_capture_pp_stage(
struct ia_css_pipe *pipe,
struct ia_css_pipeline *me,
struct ia_css_frame *in_frame,
struct ia_css_frame *out_frame,
struct ia_css_binary *capture_pp_binary,
struct ia_css_pipeline_stage **capture_pp_stage)
{
const struct ia_css_fw_info *last_fw = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_frame *vf_frame = NULL;
struct ia_css_frame *out_frames[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
struct ia_css_pipeline_stage_desc stage_desc;
assert(in_frame != NULL);
assert(pipe != NULL);
assert(me != NULL);
assert(capture_pp_binary != NULL);
assert(capture_pp_stage != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"add_capture_pp_stage() enter:\n");
*capture_pp_stage = NULL;
ia_css_pipe_util_create_output_frames(out_frames);
last_fw = last_output_firmware(pipe->output_stage);
err = ia_css_frame_allocate_from_info(&vf_frame,
&capture_pp_binary->vf_frame_info);
if (err != IA_CSS_SUCCESS)
return err;
if(last_fw) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc,
capture_pp_binary, out_frames, NULL, vf_frame);
} else {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc,
capture_pp_binary, out_frames, NULL, vf_frame);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
capture_pp_stage);
if (err != IA_CSS_SUCCESS)
return err;
err = add_firmwares(me, capture_pp_binary, pipe->output_stage, last_fw,
IA_CSS_BINARY_MODE_CAPTURE_PP,
in_frame, out_frame, vf_frame,
NULL, capture_pp_stage);
if (*capture_pp_stage) {
(*capture_pp_stage)->args.vf_downscale_log2 =
capture_pp_binary->vf_downscale_log2;
}
return err;
}
static void sh_css_setup_queues(void)
{
const struct ia_css_fw_info *fw;
unsigned int HIVE_ADDR_host_sp_queues_initialized;
sh_css_hmm_buffer_record_init();
sh_css_event_init_irq_mask();
fw = &sh_css_sp_fw;
HIVE_ADDR_host_sp_queues_initialized =
fw->info.sp.host_sp_queues_initialized;
ia_css_bufq_init();
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(host_sp_queues_initialized),
(uint32_t)(1));
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "sh_css_setup_queues() leave:\n");
}
static enum ia_css_err
init_vf_frameinfo_defaults(struct ia_css_pipe *pipe,
struct ia_css_frame *vf_frame, unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int thread_id;
enum sh_css_queue_id queue_id;
assert(vf_frame != NULL);
sh_css_pipe_get_viewfinder_frame_info(pipe, &vf_frame->info, idx);
vf_frame->contiguous = false;
vf_frame->flash_state = IA_CSS_FRAME_FLASH_STATE_NONE;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME + idx, thread_id, &queue_id);
vf_frame->dynamic_queue_id = queue_id;
vf_frame->buf_type = IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME + idx;
err = ia_css_frame_init_planes(vf_frame);
return err;
}
static unsigned int
get_crop_lines_for_bayer_order (
const struct ia_css_stream_config *config)
{
assert(config != NULL);
if ((IA_CSS_BAYER_ORDER_BGGR == config->input_config.bayer_order)
|| (IA_CSS_BAYER_ORDER_GBRG == config->input_config.bayer_order))
return 1;
return 0;
}
static unsigned int
get_crop_columns_for_bayer_order (
const struct ia_css_stream_config *config)
{
assert(config != NULL);
if ((IA_CSS_BAYER_ORDER_RGGB == config->input_config.bayer_order)
|| (IA_CSS_BAYER_ORDER_GBRG == config->input_config.bayer_order))
return 1;
return 0;
}
static void get_pipe_extra_pixel(struct ia_css_pipe *pipe,
unsigned int *extra_row, unsigned int *extra_column)
{
enum ia_css_pipe_id pipe_id = pipe->mode;
unsigned int left_cropping = 0, top_cropping = 0;
unsigned int i;
struct ia_css_resolution dvs_env = pipe->config.dvs_envelope;
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
if (pipe->pipe_settings.preview.preview_binary.info) {
left_cropping = pipe->pipe_settings.preview.preview_binary.info->sp.pipeline.left_cropping;
top_cropping = pipe->pipe_settings.preview.preview_binary.info->sp.pipeline.top_cropping;
}
dvs_env = pipe->pipe_settings.preview.preview_binary.dvs_envelope;
break;
case IA_CSS_PIPE_ID_VIDEO:
if (pipe->pipe_settings.video.video_binary.info) {
left_cropping = pipe->pipe_settings.video.video_binary.info->sp.pipeline.left_cropping;
top_cropping = pipe->pipe_settings.video.video_binary.info->sp.pipeline.top_cropping;
}
dvs_env = pipe->pipe_settings.video.video_binary.dvs_envelope;
break;
case IA_CSS_PIPE_ID_CAPTURE:
for (i = 0; i < pipe->pipe_settings.capture.num_primary_stage; i++) {
if (pipe->pipe_settings.capture.primary_binary[i].info) {
left_cropping += pipe->pipe_settings.capture.primary_binary[i].info->sp.pipeline.left_cropping;
top_cropping += pipe->pipe_settings.capture.primary_binary[i].info->sp.pipeline.top_cropping;
}
dvs_env.width += pipe->pipe_settings.capture.primary_binary[i].dvs_envelope.width;
dvs_env.height += pipe->pipe_settings.capture.primary_binary[i].dvs_envelope.height;
}
break;
default:
break;
}
*extra_row = top_cropping + dvs_env.height;
*extra_column = left_cropping + dvs_env.width;
}
void
ia_css_get_crop_offsets (
struct ia_css_pipe *pipe,
struct ia_css_frame_info *in_frame)
{
unsigned int row = 0;
unsigned int column = 0;
struct ia_css_resolution *input_res;
struct ia_css_resolution *effective_res;
unsigned int extra_row = 0, extra_col = 0;
unsigned int min_reqd_height, min_reqd_width;
assert(pipe != NULL);
assert(pipe->stream != NULL);
assert(in_frame != NULL);
IA_CSS_ENTER_PRIVATE("pipe = %p effective_wd = %u effective_ht = %u",
pipe, pipe->config.input_effective_res.width,
pipe->config.input_effective_res.height);
input_res = &pipe->stream->config.input_config.input_res;
#ifndef ISP2401
effective_res = &pipe->stream->config.input_config.effective_res;
#else
effective_res = &pipe->config.input_effective_res;
#endif
get_pipe_extra_pixel(pipe, &extra_row, &extra_col);
in_frame->raw_bayer_order = pipe->stream->config.input_config.bayer_order;
min_reqd_height = effective_res->height + extra_row;
min_reqd_width = effective_res->width + extra_col;
if (input_res->height > min_reqd_height) {
row = (input_res->height - min_reqd_height) / 2;
row &= ~0x1;
}
if (input_res->width > min_reqd_width) {
column = (input_res->width - min_reqd_width) / 2;
column &= ~0x1;
}
column += get_crop_columns_for_bayer_order(&pipe->stream->config);
row += get_crop_lines_for_bayer_order(&pipe->stream->config);
in_frame->crop_info.start_column = column;
in_frame->crop_info.start_line = row;
IA_CSS_LEAVE_PRIVATE("void start_col: %u start_row: %u", column, row);
return;
}
static enum ia_css_err
init_in_frameinfo_memory_defaults(struct ia_css_pipe *pipe,
struct ia_css_frame *frame, enum ia_css_frame_format format)
{
struct ia_css_frame *in_frame;
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int thread_id;
enum sh_css_queue_id queue_id;
assert(frame != NULL);
in_frame = frame;
in_frame->info.format = format;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (format == IA_CSS_FRAME_FORMAT_RAW)
in_frame->info.format = (pipe->stream->config.pack_raw_pixels) ?
IA_CSS_FRAME_FORMAT_RAW_PACKED : IA_CSS_FRAME_FORMAT_RAW;
#endif
in_frame->info.res.width = pipe->stream->config.input_config.input_res.width;
in_frame->info.res.height = pipe->stream->config.input_config.input_res.height;
in_frame->info.raw_bit_depth =
ia_css_pipe_util_pipe_input_format_bpp(pipe);
ia_css_frame_info_set_width(&in_frame->info, pipe->stream->config.input_config.input_res.width, 0);
in_frame->contiguous = false;
in_frame->flash_state = IA_CSS_FRAME_FLASH_STATE_NONE;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_INPUT_FRAME, thread_id, &queue_id);
in_frame->dynamic_queue_id = queue_id;
in_frame->buf_type = IA_CSS_BUFFER_TYPE_INPUT_FRAME;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
ia_css_get_crop_offsets(pipe, &in_frame->info);
#endif
err = ia_css_frame_init_planes(in_frame);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"init_in_frameinfo_memory_defaults() bayer_order = %d:\n", in_frame->info.raw_bayer_order);
return err;
}
static enum ia_css_err
init_out_frameinfo_defaults(struct ia_css_pipe *pipe,
struct ia_css_frame *out_frame, unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int thread_id;
enum sh_css_queue_id queue_id;
assert(out_frame != NULL);
sh_css_pipe_get_output_frame_info(pipe, &out_frame->info, idx);
out_frame->contiguous = false;
out_frame->flash_state = IA_CSS_FRAME_FLASH_STATE_NONE;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_OUTPUT_FRAME + idx, thread_id, &queue_id);
out_frame->dynamic_queue_id = queue_id;
out_frame->buf_type = IA_CSS_BUFFER_TYPE_OUTPUT_FRAME + idx;
err = ia_css_frame_init_planes(out_frame);
return err;
}
static enum ia_css_err
create_host_acc_pipeline(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int i;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->stream == NULL)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe->pipeline.num_execs = pipe->config.acc_num_execs;
if (pipe->config.acc_extension)
pipe->pipeline.pipe_qos_config = 0;
{
const struct ia_css_fw_info *fw = pipe->vf_stage;
for (i = 0; fw; fw = fw->next){
err = sh_css_pipeline_add_acc_stage(&pipe->pipeline, fw);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
}
for (i=0; i<pipe->config.num_acc_stages; i++) {
struct ia_css_fw_info *fw = pipe->config.acc_stages[i];
err = sh_css_pipeline_add_acc_stage(&pipe->pipeline, fw);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
create_host_preview_pipeline(struct ia_css_pipe *pipe)
{
struct ia_css_pipeline_stage *copy_stage = NULL;
struct ia_css_pipeline_stage *preview_stage = NULL;
struct ia_css_pipeline_stage *vf_pp_stage = NULL;
struct ia_css_pipeline_stage_desc stage_desc;
struct ia_css_pipeline *me = NULL;
struct ia_css_binary *copy_binary, *preview_binary, *vf_pp_binary = NULL;
struct ia_css_frame *in_frame = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_frame *out_frame;
struct ia_css_frame *out_frames[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
bool need_in_frameinfo_memory = false;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
bool sensor = false;
bool buffered_sensor = false;
bool online = false;
bool continuous = false;
#endif
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->stream == NULL) || (pipe->mode != IA_CSS_PIPE_ID_PREVIEW)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_pipe_util_create_output_frames(out_frames);
me = &pipe->pipeline;
ia_css_pipeline_clean(me);
#ifdef USE_INPUT_SYSTEM_VERSION_2401
sensor = (pipe->stream->config.mode == IA_CSS_INPUT_MODE_SENSOR);
buffered_sensor = (pipe->stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR);
online = pipe->stream->config.online;
continuous = pipe->stream->config.continuous;
need_in_frameinfo_memory =
!((sensor && (online || continuous)) || (buffered_sensor && (online || continuous)));
#else
need_in_frameinfo_memory = pipe->stream->config.mode == IA_CSS_INPUT_MODE_MEMORY;
#endif
if (need_in_frameinfo_memory) {
err = init_in_frameinfo_memory_defaults(pipe, &me->in_frame, IA_CSS_FRAME_FORMAT_RAW);
if (err != IA_CSS_SUCCESS)
goto ERR;
in_frame = &me->in_frame;
} else {
in_frame = NULL;
}
err = init_out_frameinfo_defaults(pipe, &me->out_frame[0], 0);
if (err != IA_CSS_SUCCESS)
goto ERR;
out_frame = &me->out_frame[0];
copy_binary = &pipe->pipe_settings.preview.copy_binary;
preview_binary = &pipe->pipe_settings.preview.preview_binary;
if (pipe->pipe_settings.preview.vf_pp_binary.info)
vf_pp_binary = &pipe->pipe_settings.preview.vf_pp_binary;
if (pipe->pipe_settings.preview.copy_binary.info) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
out_frames, NULL, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&copy_stage);
if (err != IA_CSS_SUCCESS)
goto ERR;
in_frame = me->stages->args.out_frame[0];
#ifndef ISP2401
} else {
#else
} else if (pipe->stream->config.continuous) {
#endif
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (continuous || !online){
in_frame = pipe->stream->last_pipe->continuous_frames[0];
}
#else
in_frame = pipe->continuous_frames[0];
#endif
}
if (vf_pp_binary) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, preview_binary,
out_frames, in_frame, NULL);
} else {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, preview_binary,
out_frames, in_frame, NULL);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&preview_stage);
if (err != IA_CSS_SUCCESS)
goto ERR;
preview_stage->args.copy_vf =
preview_binary->info->sp.pipeline.mode == IA_CSS_BINARY_MODE_COPY;
preview_stage->args.copy_output = !preview_stage->args.copy_vf;
if (preview_stage->args.copy_vf && !preview_stage->args.out_vf_frame) {
preview_stage->args.out_vf_frame =
preview_stage->args.out_frame[0];
}
if (vf_pp_binary) {
if (preview_binary->info->sp.pipeline.mode == IA_CSS_BINARY_MODE_COPY)
in_frame = preview_stage->args.out_vf_frame;
else
in_frame = preview_stage->args.out_frame[0];
err = add_vf_pp_stage(pipe, in_frame, out_frame, vf_pp_binary,
&vf_pp_stage);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
pipe->pipeline.acquire_isp_each_stage = false;
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static void send_raw_frames(struct ia_css_pipe *pipe)
{
if (pipe->stream->config.continuous) {
unsigned int i;
sh_css_update_host2sp_cont_num_raw_frames
(pipe->stream->config.init_num_cont_raw_buf, true);
sh_css_update_host2sp_cont_num_raw_frames
(pipe->stream->config.target_num_cont_raw_buf, false);
for (i = 0; i < pipe->stream->config.init_num_cont_raw_buf; i++) {
sh_css_update_host2sp_offline_frame(i,
pipe->continuous_frames[i], pipe->cont_md_buffers[i]);
}
}
return;
}
static enum ia_css_err
preview_start(struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me ;
struct ia_css_binary *copy_binary, *preview_binary, *vf_pp_binary = NULL;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *copy_pipe, *capture_pipe;
struct ia_css_pipe *acc_pipe;
enum sh_css_pipe_config_override copy_ovrd;
enum ia_css_input_mode preview_pipe_input_mode;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->stream == NULL) || (pipe->mode != IA_CSS_PIPE_ID_PREVIEW)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
me = &pipe->pipeline;
preview_pipe_input_mode = pipe->stream->config.mode;
copy_pipe = pipe->pipe_settings.preview.copy_pipe;
capture_pipe = pipe->pipe_settings.preview.capture_pipe;
acc_pipe = pipe->pipe_settings.preview.acc_pipe;
copy_binary = &pipe->pipe_settings.preview.copy_binary;
preview_binary = &pipe->pipe_settings.preview.preview_binary;
if (pipe->pipe_settings.preview.vf_pp_binary.info)
vf_pp_binary = &pipe->pipe_settings.preview.vf_pp_binary;
sh_css_metrics_start_frame();
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
#endif
send_raw_frames(pipe);
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
if (pipe->stream->cont_capt) {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(capture_pipe), &thread_id);
copy_ovrd |= 1 << thread_id;
}
}
if (pipe->stream->config.continuous) {
sh_css_sp_init_pipeline(&copy_pipe->pipeline,
IA_CSS_PIPE_ID_COPY,
(uint8_t)ia_css_pipe_get_pipe_num(copy_pipe),
false,
pipe->stream->config.pixels_per_clock == 2, false,
false, pipe->required_bds_factor,
copy_ovrd,
pipe->stream->config.mode,
&pipe->stream->config.metadata_config,
#ifndef ISP2401
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
#ifndef ISP2401
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef ISP2401
);
#else
&pipe->config.internal_frame_origin_bqs_on_sctbl,
pipe->stream->isp_params_configs);
#endif
preview_pipe_input_mode = IA_CSS_INPUT_MODE_MEMORY;
}
ia_css_err
ia_css_pipe_enqueue_buffer(struct ia_css_pipe *pipe,
const struct ia_css_buffer *buffer)
{
enum ia_css_err return_err = IA_CSS_SUCCESS;
unsigned int thread_id;
enum sh_css_queue_id queue_id;
struct ia_css_pipeline *pipeline;
struct ia_css_pipeline_stage *stage;
struct ia_css_rmgr_vbuf_handle p_vbuf;
struct ia_css_rmgr_vbuf_handle *h_vbuf;
struct sh_css_hmm_buffer ddr_buffer;
enum ia_css_buffer_type buf_type;
enum ia_css_pipe_id pipe_id;
bool ret_err;
IA_CSS_ENTER("pipe=%p, buffer=%p", pipe, buffer);
if ((pipe == NULL) || (buffer == NULL)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
buf_type = buffer->type;
#if 0
if (buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME) {
bool found_pipe = false;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if ((buffer->data.frame->info.res.width == pipe->output_info[i].res.width) &&
(buffer->data.frame->info.res.height == pipe->output_info[i].res.height)) {
buf_type += i;
found_pipe = true;
break;
}
}
if (!found_pipe)
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME) {
bool found_pipe = false;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if ((buffer->data.frame->info.res.width == pipe->vf_output_info[i].res.width) &&
(buffer->data.frame->info.res.height == pipe->vf_output_info[i].res.height)) {
buf_type += i;
found_pipe = true;
break;
}
}
if (!found_pipe)
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
#endif
pipe_id = pipe->mode;
IA_CSS_LOG("pipe_id=%d, buf_type=%d", pipe_id, buf_type);
assert(pipe_id < IA_CSS_PIPE_ID_NUM);
assert(buf_type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE);
if ((buf_type == IA_CSS_BUFFER_TYPE_INVALID) ||
(buf_type >= IA_CSS_NUM_DYNAMIC_BUFFER_TYPE) ||
(pipe_id >= IA_CSS_PIPE_ID_NUM)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
ret_err = ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ret_err = ia_css_query_internal_queue_id(buf_type, thread_id, &queue_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((queue_id <= SH_CSS_INVALID_QUEUE_ID) || (queue_id >= SH_CSS_MAX_NUM_QUEUES)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!sh_css_sp_is_running()) {
IA_CSS_LOG("SP is not running!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
pipeline = &pipe->pipeline;
assert(pipeline != NULL ||
pipe_id == IA_CSS_PIPE_ID_COPY ||
pipe_id == IA_CSS_PIPE_ID_ACC);
assert(sizeof(NULL) <= sizeof(ddr_buffer.kernel_ptr));
ddr_buffer.kernel_ptr = HOST_ADDRESS(NULL);
ddr_buffer.cookie_ptr = buffer->driver_cookie;
ddr_buffer.timing_data = buffer->timing_data;
if (buf_type == IA_CSS_BUFFER_TYPE_3A_STATISTICS) {
if (buffer->data.stats_3a == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ddr_buffer.kernel_ptr = HOST_ADDRESS(buffer->data.stats_3a);
ddr_buffer.payload.s3a = *buffer->data.stats_3a;
} else if (buf_type == IA_CSS_BUFFER_TYPE_DIS_STATISTICS) {
if (buffer->data.stats_dvs == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ddr_buffer.kernel_ptr = HOST_ADDRESS(buffer->data.stats_dvs);
ddr_buffer.payload.dis = *buffer->data.stats_dvs;
} else if (buf_type == IA_CSS_BUFFER_TYPE_METADATA) {
if (buffer->data.metadata == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ddr_buffer.kernel_ptr = HOST_ADDRESS(buffer->data.metadata);
ddr_buffer.payload.metadata = *buffer->data.metadata;
} else if ((buf_type == IA_CSS_BUFFER_TYPE_INPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_SEC_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_SEC_VF_OUTPUT_FRAME)) {
if (buffer->data.frame == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ddr_buffer.kernel_ptr = HOST_ADDRESS(buffer->data.frame);
ddr_buffer.payload.frame.frame_data = buffer->data.frame->data;
ddr_buffer.payload.frame.flashed = 0;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipe_enqueue_buffer() buf_type=%d, data(DDR address)=0x%x\n",
buf_type, buffer->data.frame->data);
#if CONFIG_ON_FRAME_ENQUEUE()
return_err = set_config_on_frame_enqueue(
&buffer->data.frame->info,
&ddr_buffer.payload.frame);
if (IA_CSS_SUCCESS != return_err) {
IA_CSS_LEAVE_ERR(return_err);
return return_err;
}
#endif
}
p_vbuf.vptr = 0;
p_vbuf.count = 0;
p_vbuf.size = sizeof(struct sh_css_hmm_buffer);
h_vbuf = &p_vbuf;
ia_css_rmgr_acq_vbuf(hmm_buffer_pool, &h_vbuf);
assert(h_vbuf != NULL);
assert(h_vbuf->vptr != 0x0);
if ((h_vbuf == NULL) || (h_vbuf->vptr == 0x0)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
mmgr_store(h_vbuf->vptr,
(void *)(&ddr_buffer),
sizeof(struct sh_css_hmm_buffer));
if ((buf_type == IA_CSS_BUFFER_TYPE_3A_STATISTICS)
|| (buf_type == IA_CSS_BUFFER_TYPE_DIS_STATISTICS)
|| (buf_type == IA_CSS_BUFFER_TYPE_LACE_STATISTICS)) {
if (pipeline == NULL) {
ia_css_rmgr_rel_vbuf(hmm_buffer_pool, &h_vbuf);
IA_CSS_LOG("pipeline is empty!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
for (stage = pipeline->stages; stage; stage = stage->next) {
if (STATS_ENABLED(stage)) {
return_err = ia_css_bufq_enqueue_buffer(thread_id,
queue_id,
(uint32_t)h_vbuf->vptr);
}
}
} else if ((buf_type == IA_CSS_BUFFER_TYPE_INPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_SEC_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_SEC_VF_OUTPUT_FRAME)
|| (buf_type == IA_CSS_BUFFER_TYPE_METADATA)) {
return_err = ia_css_bufq_enqueue_buffer(thread_id,
queue_id,
(uint32_t)h_vbuf->vptr);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
if ((return_err == IA_CSS_SUCCESS) && (IA_CSS_BUFFER_TYPE_OUTPUT_FRAME == buf_type)) {
IA_CSS_LOG("pfp: enqueued OF %d to q %d thread %d",
ddr_buffer.payload.frame.frame_data,
queue_id, thread_id);
}
#endif
}
if (return_err == IA_CSS_SUCCESS) {
if (sh_css_hmm_buffer_record_acquire(
h_vbuf, buf_type,
HOST_ADDRESS(ddr_buffer.kernel_ptr))) {
IA_CSS_LOG("send vbuf=%p", h_vbuf);
} else {
return_err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_ERROR("hmm_buffer_record[]: no available slots\n");
}
}
if (return_err == IA_CSS_SUCCESS) {
if (!sh_css_sp_is_running()) {
IA_CSS_LOG("SP is not running!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_ENQUEUED,
(uint8_t)thread_id,
queue_id,
0);
} else {
ia_css_rmgr_rel_vbuf(hmm_buffer_pool, &h_vbuf);
IA_CSS_ERROR("buffer not enqueued");
}
IA_CSS_LEAVE("return value = %d", return_err);
return return_err;
}
enum ia_css_err
ia_css_pipe_dequeue_buffer(struct ia_css_pipe *pipe,
struct ia_css_buffer *buffer)
{
enum ia_css_err return_err;
enum sh_css_queue_id queue_id;
hrt_vaddress ddr_buffer_addr = (hrt_vaddress)0;
struct sh_css_hmm_buffer ddr_buffer;
enum ia_css_buffer_type buf_type;
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
hrt_address kernel_ptr = 0;
bool ret_err;
IA_CSS_ENTER("pipe=%p, buffer=%p", pipe, buffer);
if ((pipe == NULL) || (buffer == NULL)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe_id = pipe->mode;
buf_type = buffer->type;
IA_CSS_LOG("pipe_id=%d, buf_type=%d", pipe_id, buf_type);
ddr_buffer.kernel_ptr = 0;
ret_err = ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ret_err = ia_css_query_internal_queue_id(buf_type, thread_id, &queue_id);
if (!ret_err) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((queue_id <= SH_CSS_INVALID_QUEUE_ID) || (queue_id >= SH_CSS_MAX_NUM_QUEUES)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!sh_css_sp_is_running()) {
IA_CSS_LOG("SP is not running!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_dequeue_buffer(queue_id,
(uint32_t *)&ddr_buffer_addr);
if (return_err == IA_CSS_SUCCESS) {
struct ia_css_frame *frame;
struct sh_css_hmm_buffer_record *hmm_buffer_record = NULL;
IA_CSS_LOG("receive vbuf=%x", (int)ddr_buffer_addr);
hmm_buffer_record = sh_css_hmm_buffer_record_validate(
ddr_buffer_addr, buf_type);
if (hmm_buffer_record != NULL) {
kernel_ptr = hmm_buffer_record->kernel_ptr;
ia_css_rmgr_rel_vbuf(hmm_buffer_pool, &hmm_buffer_record->h_vbuf);
sh_css_hmm_buffer_record_reset(hmm_buffer_record);
} else {
IA_CSS_ERROR("hmm_buffer_record not found (0x%u) buf_type(%d)",
ddr_buffer_addr, buf_type);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
mmgr_load(ddr_buffer_addr,
&ddr_buffer,
sizeof(struct sh_css_hmm_buffer));
if ((ddr_buffer.kernel_ptr == 0) ||
(kernel_ptr != HOST_ADDRESS(ddr_buffer.kernel_ptr))) {
IA_CSS_ERROR("kernel_ptr invalid");
IA_CSS_ERROR("expected: (0x%llx)", (u64)kernel_ptr);
IA_CSS_ERROR("actual: (0x%llx)", (u64)HOST_ADDRESS(ddr_buffer.kernel_ptr));
IA_CSS_ERROR("buf_type: %d\n", buf_type);
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
if (ddr_buffer.kernel_ptr != 0) {
buffer->exp_id = 0;
buffer->driver_cookie = ddr_buffer.cookie_ptr;
buffer->timing_data = ddr_buffer.timing_data;
if ((buf_type == IA_CSS_BUFFER_TYPE_OUTPUT_FRAME) ||
(buf_type == IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME)) {
buffer->isys_eof_clock_tick.ticks = ddr_buffer.isys_eof_clock_tick;
}
switch (buf_type) {
case IA_CSS_BUFFER_TYPE_INPUT_FRAME:
case IA_CSS_BUFFER_TYPE_OUTPUT_FRAME:
case IA_CSS_BUFFER_TYPE_SEC_OUTPUT_FRAME:
if ((pipe) && (pipe->stop_requested == true))
{
#if defined(USE_INPUT_SYSTEM_VERSION_2)
return_err = free_mipi_frames(pipe);
if (return_err != IA_CSS_SUCCESS) {
IA_CSS_LOG("free_mipi_frames() failed");
IA_CSS_LEAVE_ERR(return_err);
return return_err;
}
#endif
pipe->stop_requested = false;
}
case IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME:
case IA_CSS_BUFFER_TYPE_SEC_VF_OUTPUT_FRAME:
frame = (struct ia_css_frame*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->data.frame = frame;
buffer->exp_id = ddr_buffer.payload.frame.exp_id;
frame->exp_id = ddr_buffer.payload.frame.exp_id;
frame->isp_config_id = ddr_buffer.payload.frame.isp_parameters_id;
if (ddr_buffer.payload.frame.flashed == 1)
frame->flash_state =
IA_CSS_FRAME_FLASH_STATE_PARTIAL;
if (ddr_buffer.payload.frame.flashed == 2)
frame->flash_state =
IA_CSS_FRAME_FLASH_STATE_FULL;
frame->valid = pipe->num_invalid_frames == 0;
if (!frame->valid)
pipe->num_invalid_frames--;
if (frame->info.format == IA_CSS_FRAME_FORMAT_BINARY_8) {
#ifdef USE_INPUT_SYSTEM_VERSION_2401
frame->planes.binary.size = frame->data_bytes;
#else
frame->planes.binary.size =
sh_css_sp_get_binary_copy_size();
#endif
}
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
if (IA_CSS_BUFFER_TYPE_OUTPUT_FRAME == buf_type) {
IA_CSS_LOG("pfp: dequeued OF %d with config id %d thread %d",
frame->data, frame->isp_config_id, thread_id);
}
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipe_dequeue_buffer() buf_type=%d, data(DDR address)=0x%x\n",
buf_type, buffer->data.frame->data);
break;
case IA_CSS_BUFFER_TYPE_3A_STATISTICS:
buffer->data.stats_3a =
(struct ia_css_isp_3a_statistics*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.s3a.exp_id;
buffer->data.stats_3a->exp_id = ddr_buffer.payload.s3a.exp_id;
buffer->data.stats_3a->isp_config_id = ddr_buffer.payload.s3a.isp_config_id;
break;
case IA_CSS_BUFFER_TYPE_DIS_STATISTICS:
buffer->data.stats_dvs =
(struct ia_css_isp_dvs_statistics*)
HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.dis.exp_id;
buffer->data.stats_dvs->exp_id = ddr_buffer.payload.dis.exp_id;
break;
case IA_CSS_BUFFER_TYPE_LACE_STATISTICS:
break;
case IA_CSS_BUFFER_TYPE_METADATA:
buffer->data.metadata =
(struct ia_css_metadata*)HOST_ADDRESS(ddr_buffer.kernel_ptr);
buffer->exp_id = ddr_buffer.payload.metadata.exp_id;
buffer->data.metadata->exp_id = ddr_buffer.payload.metadata.exp_id;
break;
default:
return_err = IA_CSS_ERR_INTERNAL_ERROR;
break;
}
}
}
if (return_err == IA_CSS_SUCCESS){
if (!sh_css_sp_is_running()) {
IA_CSS_LOG("SP is not running!");
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_DEQUEUED,
0,
queue_id,
0);
}
IA_CSS_LEAVE("buffer=%p", buffer);
return return_err;
}
enum ia_css_err
ia_css_dequeue_event(struct ia_css_event *event)
{
return ia_css_dequeue_psys_event(event);
}
enum ia_css_err
ia_css_dequeue_psys_event(struct ia_css_event *event)
{
enum ia_css_pipe_id pipe_id = 0;
uint8_t payload[4] = {0,0,0,0};
enum ia_css_err ret_err;
if (event == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (!sh_css_sp_is_running()) {
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ret_err = ia_css_bufq_dequeue_psys_event(payload);
if (ret_err != IA_CSS_SUCCESS)
return ret_err;
IA_CSS_LOG("event dequeued from psys event queue");
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_EVENT_DEQUEUED, 0, 0, 0);
event->type = convert_event_sp_to_host_domain[payload[0]];
event->pipe = NULL;
event->port = IA_CSS_CSI2_PORT0;
event->exp_id = 0;
event->fw_warning = IA_CSS_FW_WARNING_NONE;
event->fw_handle = 0;
event->timer_data = 0;
event->timer_code = 0;
event->timer_subcode = 0;
if (event->type == IA_CSS_EVENT_TYPE_TIMER) {
uint32_t tmp_data;
event->timer_data = ((payload[1] & 0xFF) | ((payload[3] & 0xFF) << 8));
event->timer_code = payload[2];
payload[0] = payload[1] = payload[2] = payload[3] = 0;
ret_err = ia_css_bufq_dequeue_psys_event(payload);
if (ret_err != IA_CSS_SUCCESS) {
IA_CSS_WARNING("Timer: Error de-queuing the 2nd TIMER event!!!\n");
return ret_err;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_EVENT_DEQUEUED, 0, 0, 0);
event->type = convert_event_sp_to_host_domain[payload[0]];
if (event->type == IA_CSS_EVENT_TYPE_TIMER) {
tmp_data = ((payload[1] & 0xFF) | ((payload[3] & 0xFF) << 8));
event->timer_data |= (tmp_data << 16);
event->timer_subcode = payload[2];
}
else {
event->timer_data = 0;
event->timer_code = 0;
event->timer_subcode = 0;
IA_CSS_ERROR("Missing 2nd timer event. Timer event discarded");
}
}
if (event->type == IA_CSS_EVENT_TYPE_PORT_EOF) {
event->port = (enum ia_css_csi2_port)payload[1];
event->exp_id = payload[3];
} else if (event->type == IA_CSS_EVENT_TYPE_FW_WARNING) {
event->fw_warning = (enum ia_css_fw_warning)payload[1];
if (event->fw_warning == IA_CSS_FW_WARNING_EXP_ID_LOCKED ||
event->fw_warning == IA_CSS_FW_WARNING_TAG_EXP_ID_FAILED)
event->exp_id = payload[3];
} else if (event->type == IA_CSS_EVENT_TYPE_FW_ASSERT) {
event->fw_assert_module_id = payload[1];
event->fw_assert_line_no = (payload[2] << 8) + payload[3];
} else if (event->type != IA_CSS_EVENT_TYPE_TIMER) {
event->pipe = find_pipe_by_num(payload[1]);
pipe_id = (enum ia_css_pipe_id)payload[2];
if (!event->pipe)
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
if (event->type == IA_CSS_EVENT_TYPE_FRAME_TAGGED) {
int i, n;
n = event->pipe->stream->num_pipes;
for (i = 0; i < n; i++) {
struct ia_css_pipe *p =
event->pipe->stream->pipes[i];
if (p->config.mode == IA_CSS_PIPE_MODE_CAPTURE) {
event->pipe = p;
break;
}
}
event->exp_id = payload[3];
}
if (event->type == IA_CSS_EVENT_TYPE_ACC_STAGE_COMPLETE) {
uint32_t stage_num = (uint32_t)payload[3];
ret_err = ia_css_pipeline_get_fw_from_stage(
&(event->pipe->pipeline),
stage_num,
&(event->fw_handle));
if (ret_err != IA_CSS_SUCCESS) {
IA_CSS_ERROR("Invalid stage num received for ACC event. stage_num:%u",
stage_num);
return ret_err;
}
}
}
if (event->pipe)
IA_CSS_LEAVE("event_id=%d, pipe_id=%d", event->type, pipe_id);
else
IA_CSS_LEAVE("event_id=%d", event->type);
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_dequeue_isys_event(struct ia_css_event *event)
{
uint8_t payload[4] = {0, 0, 0, 0};
enum ia_css_err err = IA_CSS_SUCCESS;
if (event == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (!sh_css_sp_is_running()) {
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
err = ia_css_bufq_dequeue_isys_event(payload);
if (err != IA_CSS_SUCCESS)
return err;
IA_CSS_LOG("event dequeued from isys event queue");
ia_css_bufq_enqueue_isys_event(IA_CSS_ISYS_SW_EVENT_EVENT_DEQUEUED);
event->type = IA_CSS_EVENT_TYPE_PORT_EOF;
event->pipe = NULL;
event->port = payload[1];
event->exp_id = payload[3];
IA_CSS_LEAVE_ERR(err);
return err;
}
static void
acc_start(struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
assert(pipe->stream != NULL);
start_pipe(pipe, SH_CSS_PIPE_CONFIG_OVRD_NO_OVRD,
pipe->stream->config.mode);
}
static enum ia_css_err
sh_css_pipe_start(struct ia_css_stream *stream)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *pipe;
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
IA_CSS_ENTER_PRIVATE("stream = %p", stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe = stream->last_pipe;
if (pipe == NULL) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe_id = pipe->mode;
if(stream->started == true) {
IA_CSS_WARNING("Cannot start stream that is already started");
IA_CSS_LEAVE_ERR(err);
return err;
}
pipe->stop_requested = false;
switch (pipe_id) {
case IA_CSS_PIPE_ID_PREVIEW:
err = preview_start(pipe);
break;
case IA_CSS_PIPE_ID_VIDEO:
err = video_start(pipe);
break;
case IA_CSS_PIPE_ID_CAPTURE:
err = capture_start(pipe);
break;
case IA_CSS_PIPE_ID_YUVPP:
err = yuvpp_start(pipe);
break;
case IA_CSS_PIPE_ID_ACC:
acc_start(pipe);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes && IA_CSS_SUCCESS == err ; i++) {
switch (stream->pipes[i]->mode) {
case IA_CSS_PIPE_ID_PREVIEW:
stream->pipes[i]->stop_requested = false;
err = preview_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_VIDEO:
stream->pipes[i]->stop_requested = false;
err = video_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_CAPTURE:
stream->pipes[i]->stop_requested = false;
err = capture_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_YUVPP:
stream->pipes[i]->stop_requested = false;
err = yuvpp_start(stream->pipes[i]);
break;
case IA_CSS_PIPE_ID_ACC:
stream->pipes[i]->stop_requested = false;
acc_start(stream->pipes[i]);
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
}
}
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (!copy_on_sp(pipe)) {
sh_css_invalidate_params(stream);
err = sh_css_param_update_isp_params(pipe,
stream->isp_params_configs, true, NULL);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
ia_css_debug_pipe_graph_dump_epilogue();
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ia_css_bufq_enqueue_psys_event(IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
if (!stream->config.continuous) {
int i;
for (i = 1; i < stream->num_pipes; i++) {
ia_css_pipeline_get_sp_thread_id(
ia_css_pipe_get_pipe_num(stream->pipes[i]),
&thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
}
if (pipe->stream->config.continuous) {
struct ia_css_pipe *copy_pipe = NULL;
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW)
copy_pipe = pipe->pipe_settings.preview.copy_pipe;
else if (pipe_id == IA_CSS_PIPE_ID_VIDEO)
copy_pipe = pipe->pipe_settings.video.copy_pipe;
if (copy_pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(copy_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
if (pipe->stream->cont_capt) {
struct ia_css_pipe *capture_pipe = NULL;
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW)
capture_pipe = pipe->pipe_settings.preview.capture_pipe;
else if (pipe_id == IA_CSS_PIPE_ID_VIDEO)
capture_pipe = pipe->pipe_settings.video.capture_pipe;
if (capture_pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(capture_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t)thread_id, 0, 0);
}
if (pipe_id == IA_CSS_PIPE_ID_PREVIEW) {
struct ia_css_pipe *acc_pipe = NULL;
acc_pipe = pipe->pipe_settings.preview.acc_pipe;
if (acc_pipe){
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(acc_pipe), &thread_id);
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_START_STREAM,
(uint8_t) thread_id, 0, 0);
}
}
stream->started = true;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
void
sh_css_enable_cont_capt(bool enable, bool stop_copy_preview)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_enable_cont_capt() enter: enable=%d\n", enable);
my_css.stop_copy_preview = stop_copy_preview;
}
enum ia_css_err
ia_css_stream_get_max_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_get_max_buffer_depth() enter: void\n");
(void)stream;
*buffer_depth = NUM_CONTINUOUS_FRAMES;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_set_buffer_depth(struct ia_css_stream *stream, int buffer_depth)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_set_buffer_depth() enter: num_frames=%d\n",buffer_depth);
(void)stream;
if (buffer_depth > NUM_CONTINUOUS_FRAMES || buffer_depth < 1)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->config.target_num_cont_raw_buf = buffer_depth;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_get_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_get_buffer_depth() enter: void\n");
#else
if (err != IA_CSS_SUCCESS) {
goto ERR;
}
}
static bool
sh_css_pipes_have_stopped(struct ia_css_stream *stream)
{
bool rval = true;
struct ia_css_pipe *main_pipe;
enum ia_css_pipe_id main_pipe_id;
int i;
assert(stream != NULL);
if (stream == NULL) {
IA_CSS_LOG("stream does NOT exist!");
rval = false;
goto RET;
}
main_pipe = stream->last_pipe;
assert(main_pipe != NULL);
if (main_pipe == NULL) {
IA_CSS_LOG("main_pipe does NOT exist!");
rval = false;
goto RET;
}
main_pipe_id = main_pipe->mode;
IA_CSS_ENTER_PRIVATE("main_pipe_id=%d", main_pipe_id);
for (i = 0; i < stream->num_pipes; i++) {
rval = rval && ia_css_pipeline_has_stopped(&stream->pipes[i]->pipeline);
IA_CSS_LOG("Pipe has stopped: pipe_id=%d, stopped=%d",
stream->pipes[i]->pipeline.pipe_id,
rval);
}
if (main_pipe->stream->config.continuous) {
struct ia_css_pipe *copy_pipe = NULL;
if (main_pipe_id == IA_CSS_PIPE_ID_PREVIEW)
copy_pipe = main_pipe->pipe_settings.preview.copy_pipe;
else if (main_pipe_id == IA_CSS_PIPE_ID_VIDEO)
copy_pipe = main_pipe->pipe_settings.video.copy_pipe;
assert(copy_pipe != NULL);
if (copy_pipe == NULL) {
IA_CSS_LOG("Copy Pipe does NOT exist!");
rval = false;
goto RET;
}
rval = rval && ia_css_pipeline_has_stopped(&copy_pipe->pipeline);
IA_CSS_LOG("Pipe has stopped: pipe_id=%d, stopped=%d",
copy_pipe->pipeline.pipe_id,
rval);
}
RET:
IA_CSS_LEAVE_PRIVATE("rval=%d", rval);
return rval;
}
bool
sh_css_continuous_is_enabled(uint8_t pipe_num)
{
struct ia_css_pipe *pipe;
bool continuous;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "sh_css_continuous_is_enabled() enter: pipe_num=%d\n", pipe_num);
pipe = find_pipe_by_num(pipe_num);
continuous = pipe && pipe->stream->config.continuous;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_continuous_is_enabled() leave: enable=%d\n",
continuous);
return continuous;
}
enum ia_css_err
ia_css_stream_get_max_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_get_max_buffer_depth() enter: void\n");
(void)stream;
*buffer_depth = NUM_CONTINUOUS_FRAMES;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_set_buffer_depth(struct ia_css_stream *stream, int buffer_depth)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_set_buffer_depth() enter: num_frames=%d\n",buffer_depth);
(void)stream;
if (buffer_depth > NUM_CONTINUOUS_FRAMES || buffer_depth < 1)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->config.target_num_cont_raw_buf = buffer_depth;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_get_buffer_depth(struct ia_css_stream *stream, int *buffer_depth)
{
if (buffer_depth == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_get_buffer_depth() enter: void\n");
#endif
(void)stream;
*buffer_depth = stream->config.target_num_cont_raw_buf;
return IA_CSS_SUCCESS;
}
unsigned int
sh_css_get_mipi_sizes_for_check(const unsigned int port, const unsigned int idx)
{
OP___assert(port < N_CSI_PORTS);
OP___assert(idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "sh_css_get_mipi_sizes_for_check(port %d, idx %d): %d\n",
port, idx, my_css.mipi_sizes_for_check[port][idx]);
return my_css.mipi_sizes_for_check[port][idx];
}
static enum ia_css_err sh_css_pipe_configure_output(
struct ia_css_pipe *pipe,
unsigned int width,
unsigned int height,
unsigned int padded_width,
enum ia_css_frame_format format,
unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("pipe = %p, width = %d, height = %d, paddaed width = %d, format = %d, idx = %d",
pipe, width, height, padded_width, format, idx);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
err = ia_css_util_check_res(width, height);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (pipe->output_info[idx].res.width != width ||
pipe->output_info[idx].res.height != height ||
pipe->output_info[idx].format != format)
{
ia_css_frame_info_init(
&pipe->output_info[idx],
width,
height,
format,
padded_width);
}
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
enum ia_css_err
sh_css_pipe_get_grid_info(struct ia_css_pipe *pipe,
struct ia_css_grid_info *info)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_binary *binary = NULL;
assert(pipe != NULL);
assert(info != NULL);
IA_CSS_ENTER_PRIVATE("");
binary = ia_css_pipe_get_s3a_binary(pipe);
if (binary) {
err = ia_css_binary_3a_grid_info(binary, info, pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
} else
memset(&info->s3a_grid, 0, sizeof(info->s3a_grid));
binary = ia_css_pipe_get_sdis_binary(pipe);
if (binary) {
ia_css_binary_dvs_grid_info(binary, info, pipe);
ia_css_binary_dvs_stat_grid_info(binary, info, pipe);
} else {
memset(&info->dvs_grid.dvs_grid_info, 0,
sizeof(info->dvs_grid.dvs_grid_info));
memset(&info->dvs_grid.dvs_stat_grid_info, 0,
sizeof(info->dvs_grid.dvs_stat_grid_info));
}
if (binary != NULL) {
info->isp_in_width = binary->internal_frame_info.res.width;
info->isp_in_height = binary->internal_frame_info.res.height;
}
#if defined(HAS_VAMEM_VERSION_2)
info->vamem_type = IA_CSS_VAMEM_TYPE_2;
#elif defined(HAS_VAMEM_VERSION_1)
info->vamem_type = IA_CSS_VAMEM_TYPE_1;
#else
#error "Unknown VAMEM version"
#endif
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
ia_css_pipe_check_format(struct ia_css_pipe *pipe, enum ia_css_frame_format format)
{
const enum ia_css_frame_format *supported_formats;
int number_of_formats;
int found = 0;
int i;
IA_CSS_ENTER_PRIVATE("");
if (NULL == pipe || NULL == pipe->pipe_settings.video.video_binary.info) {
IA_CSS_ERROR("Pipe or binary info is not set");
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
supported_formats = pipe->pipe_settings.video.video_binary.info->output_formats;
number_of_formats = sizeof(pipe->pipe_settings.video.video_binary.info->output_formats)/sizeof(enum ia_css_frame_format);
for (i = 0; i < number_of_formats && !found; i++) {
if (supported_formats[i] == format) {
found = 1;
break;
}
}
if (!found) {
IA_CSS_ERROR("Requested format is not supported by binary");
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
} else {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
}
static enum ia_css_err load_video_binaries(struct ia_css_pipe *pipe)
{
struct ia_css_frame_info video_in_info, tnr_info,
*video_vf_info, video_bds_out_info, *pipe_out_info, *pipe_vf_out_info;
bool online;
enum ia_css_err err = IA_CSS_SUCCESS;
bool continuous = pipe->stream->config.continuous;
unsigned int i;
unsigned num_output_pins;
struct ia_css_frame_info video_bin_out_info;
bool need_scaler = false;
bool vf_res_different_than_output = false;
bool need_vf_pp = false;
int vf_ds_log2;
struct ia_css_video_settings *mycs = &pipe->pipe_settings.video;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_VIDEO);
if (mycs->video_binary.info)
return IA_CSS_SUCCESS;
online = pipe->stream->config.online;
pipe_out_info = &pipe->output_info[0];
pipe_vf_out_info = &pipe->vf_output_info[0];
assert(pipe_out_info != NULL);
err = ia_css_util_check_input(&pipe->stream->config, false, false);
if (err != IA_CSS_SUCCESS)
return err;
if (online && pipe->stream->config.mode == IA_CSS_INPUT_MODE_MEMORY)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (pipe->enable_viewfinder[IA_CSS_PIPE_OUTPUT_STAGE_0]) {
err = ia_css_util_check_vf_out_info(pipe_out_info,
pipe_vf_out_info);
if (err != IA_CSS_SUCCESS)
return err;
} else {
err = ia_css_frame_check_info(pipe_out_info);
if (err != IA_CSS_SUCCESS)
return err;
}
if (pipe->out_yuv_ds_input_info.res.width)
video_bin_out_info = pipe->out_yuv_ds_input_info;
else
video_bin_out_info = *pipe_out_info;
if (pipe->enable_viewfinder[IA_CSS_PIPE_OUTPUT_STAGE_0]){
video_vf_info = pipe_vf_out_info;
vf_res_different_than_output = (video_vf_info->res.width != video_bin_out_info.res.width) ||
(video_vf_info->res.height != video_bin_out_info.res.height);
}
else {
video_vf_info = NULL;
}
need_scaler = need_downscaling(video_bin_out_info.res, pipe_out_info->res);
if (need_scaler) {
struct ia_css_cas_binary_descr cas_scaler_descr
= IA_CSS_DEFAULT_CAS_BINARY_DESCR;
video_bin_out_info.format = IA_CSS_FRAME_FORMAT_NV12;
err = ia_css_pipe_create_cas_scaler_desc_single_output(
&video_bin_out_info,
pipe_out_info,
NULL,
&cas_scaler_descr);
if (err != IA_CSS_SUCCESS)
return err;
mycs->num_yuv_scaler = cas_scaler_descr.num_stage;
mycs->yuv_scaler_binary = kzalloc(cas_scaler_descr.num_stage *
sizeof(struct ia_css_binary), GFP_KERNEL);
if (mycs->yuv_scaler_binary == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
return err;
}
mycs->is_output_stage = kzalloc(cas_scaler_descr.num_stage
* sizeof(bool), GFP_KERNEL);
if (mycs->is_output_stage == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
return err;
}
for (i = 0; i < cas_scaler_descr.num_stage; i++) {
struct ia_css_binary_descr yuv_scaler_descr;
mycs->is_output_stage[i] = cas_scaler_descr.is_output_stage[i];
ia_css_pipe_get_yuvscaler_binarydesc(pipe,
&yuv_scaler_descr, &cas_scaler_descr.in_info[i],
&cas_scaler_descr.out_info[i],
&cas_scaler_descr.internal_out_info[i],
&cas_scaler_descr.vf_info[i]);
err = ia_css_binary_find(&yuv_scaler_descr,
&mycs->yuv_scaler_binary[i]);
if (err != IA_CSS_SUCCESS) {
kfree(mycs->is_output_stage);
mycs->is_output_stage = NULL;
return err;
}
}
ia_css_pipe_destroy_cas_scaler_desc(&cas_scaler_descr);
}
{
struct ia_css_binary_descr video_descr;
enum ia_css_frame_format vf_info_format;
err = ia_css_pipe_get_video_binarydesc(pipe,
&video_descr, &video_in_info, &video_bds_out_info, &video_bin_out_info, video_vf_info,
pipe->stream->config.left_padding);
if (err != IA_CSS_SUCCESS)
return err;
err = ia_css_binary_find(&video_descr,
&mycs->video_binary);
if (err != IA_CSS_SUCCESS) {
if (video_vf_info) {
need_vf_pp = true;
} else
return err;
} else if (video_vf_info) {
num_output_pins = mycs->video_binary.info->num_output_pins;
vf_ds_log2 = mycs->video_binary.vf_downscale_log2;
need_vf_pp |= ((num_output_pins == 2) && vf_res_different_than_output);
need_vf_pp |= ((num_output_pins == 1) &&
((video_vf_info->res.width << vf_ds_log2 != pipe_out_info->res.width) ||
(video_vf_info->res.height << vf_ds_log2 != pipe_out_info->res.height)));
}
if (need_vf_pp) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"load_video_binaries() need_vf_pp; find video binary with YUV_LINE again\n");
vf_info_format = video_vf_info->format;
if (!pipe->config.enable_vfpp_bci)
ia_css_frame_info_set_format(video_vf_info,
IA_CSS_FRAME_FORMAT_YUV_LINE);
ia_css_binary_destroy_isp_parameters(&mycs->video_binary);
err = ia_css_binary_find(&video_descr,
&mycs->video_binary);
ia_css_frame_info_set_format(video_vf_info,
vf_info_format);
if (err != IA_CSS_SUCCESS)
return err;
}
}
if (!mycs->video_binary.info->sp.enable.ref_frame)
pipe->dvs_frame_delay = 0;
pipe->num_invalid_frames = pipe->dvs_frame_delay;
pipe->info.num_invalid_frames = pipe->num_invalid_frames;
if (video_vf_info)
pipe->num_invalid_frames *= 2;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"load_video_binaries() num_invalid_frames=%d dvs_frame_delay=%d\n",
pipe->num_invalid_frames, pipe->dvs_frame_delay);
#if !defined(USE_INPUT_SYSTEM_VERSION_2401)
if (!online && !continuous) {
err = load_copy_binary(pipe,
&mycs->copy_binary,
&mycs->video_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
#else
(void)continuous;
#endif
#if !defined(HAS_OUTPUT_SYSTEM)
if (pipe->enable_viewfinder[IA_CSS_PIPE_OUTPUT_STAGE_0] && need_vf_pp) {
struct ia_css_binary_descr vf_pp_descr;
if (mycs->video_binary.vf_frame_info.format
== IA_CSS_FRAME_FORMAT_YUV_LINE) {
ia_css_pipe_get_vfpp_binarydesc(pipe, &vf_pp_descr,
&mycs->video_binary.vf_frame_info,
pipe_vf_out_info);
} else {
assert(pipe->config.enable_vfpp_bci == true);
ia_css_pipe_get_yuvscaler_binarydesc(pipe, &vf_pp_descr,
&mycs->video_binary.vf_frame_info,
pipe_vf_out_info, NULL, NULL);
}
err = ia_css_binary_find(&vf_pp_descr,
&mycs->vf_pp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
#endif
err = allocate_delay_frames(pipe);
if (err != IA_CSS_SUCCESS)
return err;
if (mycs->video_binary.info->sp.enable.block_output) {
#ifdef ISP2401
unsigned int tnr_width;
unsigned int tnr_height;
#endif
tnr_info = mycs->video_binary.out_frame_info[0];
#ifdef ISP2401
if (pipe->config.output_system_in_res.width && pipe->config.output_system_in_res.height) {
tnr_width = pipe->config.output_system_in_res.width;
tnr_height = pipe->config.output_system_in_res.height;
} else {
tnr_width = tnr_info.res.width;
tnr_height = tnr_info.res.height;
}
tnr_info.res.width =
CEIL_MUL(tnr_width,
(mycs->video_binary.info->sp.block.block_width * ISP_NWAY));
tnr_info.padded_width = tnr_info.res.width;
#endif
tnr_info.res.height =
#ifndef ISP2401
CEIL_MUL(tnr_info.res.height,
#else
CEIL_MUL(tnr_height,
#endif
mycs->video_binary.info->sp.block.output_block_height);
} else {
tnr_info = mycs->video_binary.internal_frame_info;
}
tnr_info.format = IA_CSS_FRAME_FORMAT_YUV_LINE;
tnr_info.raw_bit_depth = SH_CSS_TNR_BIT_DEPTH;
#ifndef ISP2401
for (i = 0; i < NUM_VIDEO_TNR_FRAMES; i++) {
#else
for (i = 0; i < NUM_TNR_FRAMES; i++) {
#endif
if (mycs->tnr_frames[i]) {
ia_css_frame_free(mycs->tnr_frames[i]);
mycs->tnr_frames[i] = NULL;
}
err = ia_css_frame_allocate_from_info(
&mycs->tnr_frames[i],
&tnr_info);
if (err != IA_CSS_SUCCESS)
return err;
}
IA_CSS_LEAVE_PRIVATE("");
return IA_CSS_SUCCESS;
}
static enum ia_css_err
unload_video_binaries(struct ia_css_pipe *pipe)
{
unsigned int i;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.video.copy_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.video_binary);
ia_css_binary_unload(&pipe->pipe_settings.video.vf_pp_binary);
#ifndef ISP2401
ia_css_binary_unload(&pipe->pipe_settings.video.vf_pp_binary);
#endif
for (i = 0; i < pipe->pipe_settings.video.num_yuv_scaler; i++)
ia_css_binary_unload(&pipe->pipe_settings.video.yuv_scaler_binary[i]);
kfree(pipe->pipe_settings.video.is_output_stage);
pipe->pipe_settings.video.is_output_stage = NULL;
kfree(pipe->pipe_settings.video.yuv_scaler_binary);
pipe->pipe_settings.video.yuv_scaler_binary = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err video_start(struct ia_css_pipe *pipe)
{
struct ia_css_binary *copy_binary;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *copy_pipe, *capture_pipe;
enum sh_css_pipe_config_override copy_ovrd;
enum ia_css_input_mode video_pipe_input_mode;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_VIDEO)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
video_pipe_input_mode = pipe->stream->config.mode;
copy_pipe = pipe->pipe_settings.video.copy_pipe;
capture_pipe = pipe->pipe_settings.video.capture_pipe;
copy_binary = &pipe->pipe_settings.video.copy_binary;
sh_css_metrics_start_frame();
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS)
return err;
#endif
send_raw_frames(pipe);
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
if (pipe->stream->cont_capt) {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(capture_pipe), &thread_id);
copy_ovrd |= 1 << thread_id;
}
}
if (pipe->stream->config.continuous) {
sh_css_sp_init_pipeline(&copy_pipe->pipeline,
IA_CSS_PIPE_ID_COPY,
(uint8_t)ia_css_pipe_get_pipe_num(copy_pipe),
false,
pipe->stream->config.pixels_per_clock == 2, false,
false, pipe->required_bds_factor,
copy_ovrd,
pipe->stream->config.mode,
&pipe->stream->config.metadata_config,
#ifndef ISP2401
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
#ifndef ISP2401
, pipe->stream->config.source.port.port
#else
pipe->stream->config.source.port.port,
#endif
#endif
#ifndef ISP2401
);
#else
&copy_pipe->config.internal_frame_origin_bqs_on_sctbl,
copy_pipe->stream->isp_params_configs);
#endif
video_pipe_input_mode = IA_CSS_INPUT_MODE_MEMORY;
}
if (pipe->stream->cont_capt) {
sh_css_sp_init_pipeline(&capture_pipe->pipeline,
IA_CSS_PIPE_ID_CAPTURE,
(uint8_t)ia_css_pipe_get_pipe_num(capture_pipe),
capture_pipe->config.default_capture_config.enable_xnr != 0,
capture_pipe->stream->config.pixels_per_clock == 2,
true,
false,
capture_pipe->required_bds_factor,
0,
IA_CSS_INPUT_MODE_MEMORY,
&pipe->stream->config.metadata_config,
#ifndef ISP2401
&pipe->stream->info.metadata_info
#else
&pipe->stream->info.metadata_info,
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
#ifndef ISP2401
, (mipi_port_ID_t)0
#else
(mipi_port_ID_t)0,
#endif
#endif
#ifndef ISP2401
);
#else
&capture_pipe->config.internal_frame_origin_bqs_on_sctbl,
capture_pipe->stream->isp_params_configs);
#endif
}
enum ia_css_err sh_css_pipe_get_viewfinder_frame_info(
struct ia_css_pipe *pipe,
struct ia_css_frame_info *info,
unsigned int idx)
{
assert(pipe != NULL);
assert(info != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "sh_css_pipe_get_viewfinder_frame_info() enter: void\n");
if ( pipe->mode == IA_CSS_PIPE_ID_CAPTURE &&
(pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_RAW ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER))
return IA_CSS_ERR_MODE_HAS_NO_VIEWFINDER;
*info = pipe->vf_output_info[idx];
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_pipe_get_viewfinder_frame_info() leave: \
info.res.width=%d, info.res.height=%d, \
info.padded_width=%d, info.format=%d, \
info.raw_bit_depth=%d, info.raw_bayer_order=%d\n",
info->res.width,info->res.height,
info->padded_width,info->format,
info->raw_bit_depth,info->raw_bayer_order);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
sh_css_pipe_configure_viewfinder(struct ia_css_pipe *pipe, unsigned int width,
unsigned int height, unsigned int min_width,
enum ia_css_frame_format format,
unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("pipe = %p, width = %d, height = %d, min_width = %d, format = %d, idx = %d\n",
pipe, width, height, min_width, format, idx);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
err = ia_css_util_check_res(width, height);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (pipe->vf_output_info[idx].res.width != width ||
pipe->vf_output_info[idx].res.height != height ||
pipe->vf_output_info[idx].format != format) {
ia_css_frame_info_init(&pipe->vf_output_info[idx], width, height,
format, min_width);
}
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err load_copy_binaries(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
assert(pipe != NULL);
IA_CSS_ENTER_PRIVATE("");
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
if (pipe->pipe_settings.capture.copy_binary.info)
return IA_CSS_SUCCESS;
err = ia_css_frame_check_info(&pipe->output_info[0]);
if (err != IA_CSS_SUCCESS)
goto ERR;
err = verify_copy_out_frame_format(pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
err = load_copy_binary(pipe,
&pipe->pipe_settings.capture.copy_binary,
NULL);
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static bool need_capture_pp(
const struct ia_css_pipe *pipe)
{
const struct ia_css_frame_info *out_info = &pipe->output_info[0];
IA_CSS_ENTER_LEAVE_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE);
#ifdef ISP2401
if (need_capt_ldc(pipe) == true)
return false;
#endif
if (pipe->out_yuv_ds_input_info.res.width &&
((pipe->out_yuv_ds_input_info.res.width != out_info->res.width) ||
(pipe->out_yuv_ds_input_info.res.height != out_info->res.height)))
return true;
if (pipe->config.default_capture_config.enable_xnr != 0)
return true;
if ((pipe->stream->isp_params_configs->dz_config.dx < HRT_GDC_N) ||
(pipe->stream->isp_params_configs->dz_config.dy < HRT_GDC_N) ||
pipe->config.enable_dz)
return true;
return false;
}
static bool need_capt_ldc(
const struct ia_css_pipe *pipe)
{
IA_CSS_ENTER_LEAVE_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE);
return (pipe->extra_config.enable_dvs_6axis) ? true:false;
}
static enum ia_css_err set_num_primary_stages(unsigned int *num, enum ia_css_pipe_version version)
{
enum ia_css_err err = IA_CSS_SUCCESS;
if (num == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
switch (version) {
case IA_CSS_PIPE_VERSION_2_6_1:
*num = NUM_PRIMARY_HQ_STAGES;
break;
case IA_CSS_PIPE_VERSION_2_2:
case IA_CSS_PIPE_VERSION_1:
*num = NUM_PRIMARY_STAGES;
break;
default:
err = IA_CSS_ERR_INVALID_ARGUMENTS;
break;
}
return err;
}
static enum ia_css_err
allocate_delay_frames(struct ia_css_pipe *pipe)
{
unsigned int num_delay_frames = 0, i = 0;
unsigned int dvs_frame_delay = 0;
struct ia_css_frame_info ref_info;
enum ia_css_err err = IA_CSS_SUCCESS;
enum ia_css_pipe_id mode = IA_CSS_PIPE_ID_VIDEO;
struct ia_css_frame **delay_frames = NULL;
IA_CSS_ENTER_PRIVATE("");
if (pipe == NULL) {
IA_CSS_ERROR("Invalid args - pipe %p", pipe);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
mode = pipe->mode;
dvs_frame_delay = pipe->dvs_frame_delay;
if (dvs_frame_delay > 0)
num_delay_frames = dvs_frame_delay + 1;
switch (mode) {
case IA_CSS_PIPE_ID_CAPTURE:
{
struct ia_css_capture_settings *mycs_capture = &pipe->pipe_settings.capture;
(void)mycs_capture;
return err;
}
break;
case IA_CSS_PIPE_ID_VIDEO:
{
struct ia_css_video_settings *mycs_video = &pipe->pipe_settings.video;
ref_info = mycs_video->video_binary.internal_frame_info;
ref_info.format = IA_CSS_FRAME_FORMAT_NV12;
delay_frames = mycs_video->delay_frames;
}
break;
case IA_CSS_PIPE_ID_PREVIEW:
{
struct ia_css_preview_settings *mycs_preview = &pipe->pipe_settings.preview;
ref_info = mycs_preview->preview_binary.internal_frame_info;
ref_info.format = IA_CSS_FRAME_FORMAT_NV12;
delay_frames = mycs_preview->delay_frames;
}
break;
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ref_info.raw_bit_depth = SH_CSS_REF_BIT_DEPTH;
assert(num_delay_frames <= MAX_NUM_VIDEO_DELAY_FRAMES);
for (i = 0; i < num_delay_frames; i++) {
err = ia_css_frame_allocate_from_info(&delay_frames[i], &ref_info);
if (err != IA_CSS_SUCCESS)
return err;
}
IA_CSS_LEAVE_PRIVATE("");
return IA_CSS_SUCCESS;
}
static enum ia_css_err load_advanced_binaries(
struct ia_css_pipe *pipe)
{
struct ia_css_frame_info pre_in_info, gdc_in_info,
post_in_info, post_out_info,
vf_info, *vf_pp_in_info, *pipe_out_info,
*pipe_vf_out_info;
bool need_pp;
bool need_isp_copy = true;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
if (pipe->pipe_settings.capture.pre_isp_binary.info)
return IA_CSS_SUCCESS;
pipe_out_info = &pipe->output_info[0];
pipe_vf_out_info = &pipe->vf_output_info[0];
vf_info = *pipe_vf_out_info;
err = ia_css_util_check_vf_out_info(pipe_out_info, &vf_info);
if (err != IA_CSS_SUCCESS)
return err;
need_pp = need_capture_pp(pipe);
ia_css_frame_info_set_format(&vf_info,
IA_CSS_FRAME_FORMAT_YUV_LINE);
if (need_pp) {
struct ia_css_binary_descr capture_pp_descr;
ia_css_pipe_get_capturepp_binarydesc(pipe,
&capture_pp_descr, &post_out_info, pipe_out_info, &vf_info);
err = ia_css_binary_find(&capture_pp_descr,
&pipe->pipe_settings.capture.capture_pp_binary);
if (err != IA_CSS_SUCCESS)
return err;
} else {
post_out_info = *pipe_out_info;
}
{
struct ia_css_binary_descr post_gdc_descr;
ia_css_pipe_get_post_gdc_binarydesc(pipe,
&post_gdc_descr, &post_in_info, &post_out_info, &vf_info);
err = ia_css_binary_find(&post_gdc_descr,
&pipe->pipe_settings.capture.post_isp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
{
struct ia_css_binary_descr gdc_descr;
ia_css_pipe_get_gdc_binarydesc(pipe, &gdc_descr, &gdc_in_info,
&pipe->pipe_settings.capture.post_isp_binary.in_frame_info);
err = ia_css_binary_find(&gdc_descr,
&pipe->pipe_settings.capture.anr_gdc_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
pipe->pipe_settings.capture.anr_gdc_binary.left_padding =
pipe->pipe_settings.capture.post_isp_binary.left_padding;
{
struct ia_css_binary_descr pre_gdc_descr;
ia_css_pipe_get_pre_gdc_binarydesc(pipe, &pre_gdc_descr, &pre_in_info,
&pipe->pipe_settings.capture.anr_gdc_binary.in_frame_info);
err = ia_css_binary_find(&pre_gdc_descr,
&pipe->pipe_settings.capture.pre_isp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
pipe->pipe_settings.capture.pre_isp_binary.left_padding =
pipe->pipe_settings.capture.anr_gdc_binary.left_padding;
if (need_pp) {
vf_pp_in_info =
&pipe->pipe_settings.capture.capture_pp_binary.vf_frame_info;
} else {
vf_pp_in_info =
&pipe->pipe_settings.capture.post_isp_binary.vf_frame_info;
}
{
struct ia_css_binary_descr vf_pp_descr;
ia_css_pipe_get_vfpp_binarydesc(pipe,
&vf_pp_descr, vf_pp_in_info, pipe_vf_out_info);
err = ia_css_binary_find(&vf_pp_descr,
&pipe->pipe_settings.capture.vf_pp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
#ifdef USE_INPUT_SYSTEM_VERSION_2401
need_isp_copy = pipe->stream->config.mode == IA_CSS_INPUT_MODE_SENSOR;
#endif
if (need_isp_copy)
load_copy_binary(pipe,
&pipe->pipe_settings.capture.copy_binary,
&pipe->pipe_settings.capture.pre_isp_binary);
return err;
}
static enum ia_css_err load_bayer_isp_binaries(
struct ia_css_pipe *pipe)
{
struct ia_css_frame_info pre_isp_in_info, *pipe_out_info;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_binary_descr pre_de_descr;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
pipe_out_info = &pipe->output_info[0];
if (pipe->pipe_settings.capture.pre_isp_binary.info)
return IA_CSS_SUCCESS;
err = ia_css_frame_check_info(pipe_out_info);
if (err != IA_CSS_SUCCESS)
return err;
ia_css_pipe_get_pre_de_binarydesc(pipe, &pre_de_descr,
&pre_isp_in_info,
pipe_out_info);
err = ia_css_binary_find(&pre_de_descr,
&pipe->pipe_settings.capture.pre_isp_binary);
return err;
}
static enum ia_css_err load_low_light_binaries(
struct ia_css_pipe *pipe)
{
struct ia_css_frame_info pre_in_info, anr_in_info,
post_in_info, post_out_info,
vf_info, *pipe_vf_out_info, *pipe_out_info,
*vf_pp_in_info;
bool need_pp;
bool need_isp_copy = true;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
if (pipe->pipe_settings.capture.pre_isp_binary.info)
return IA_CSS_SUCCESS;
pipe_vf_out_info = &pipe->vf_output_info[0];
pipe_out_info = &pipe->output_info[0];
vf_info = *pipe_vf_out_info;
err = ia_css_util_check_vf_out_info(pipe_out_info,
&vf_info);
if (err != IA_CSS_SUCCESS)
return err;
need_pp = need_capture_pp(pipe);
ia_css_frame_info_set_format(&vf_info,
IA_CSS_FRAME_FORMAT_YUV_LINE);
if (need_pp) {
struct ia_css_binary_descr capture_pp_descr;
ia_css_pipe_get_capturepp_binarydesc(pipe,
&capture_pp_descr, &post_out_info, pipe_out_info, &vf_info);
err = ia_css_binary_find(&capture_pp_descr,
&pipe->pipe_settings.capture.capture_pp_binary);
if (err != IA_CSS_SUCCESS)
return err;
} else {
post_out_info = *pipe_out_info;
}
{
struct ia_css_binary_descr post_anr_descr;
ia_css_pipe_get_post_anr_binarydesc(pipe,
&post_anr_descr, &post_in_info, &post_out_info, &vf_info);
err = ia_css_binary_find(&post_anr_descr,
&pipe->pipe_settings.capture.post_isp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
{
struct ia_css_binary_descr anr_descr;
ia_css_pipe_get_anr_binarydesc(pipe, &anr_descr, &anr_in_info,
&pipe->pipe_settings.capture.post_isp_binary.in_frame_info);
err = ia_css_binary_find(&anr_descr,
&pipe->pipe_settings.capture.anr_gdc_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
pipe->pipe_settings.capture.anr_gdc_binary.left_padding =
pipe->pipe_settings.capture.post_isp_binary.left_padding;
{
struct ia_css_binary_descr pre_anr_descr;
ia_css_pipe_get_pre_anr_binarydesc(pipe, &pre_anr_descr, &pre_in_info,
&pipe->pipe_settings.capture.anr_gdc_binary.in_frame_info);
err = ia_css_binary_find(&pre_anr_descr,
&pipe->pipe_settings.capture.pre_isp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
pipe->pipe_settings.capture.pre_isp_binary.left_padding =
pipe->pipe_settings.capture.anr_gdc_binary.left_padding;
if (need_pp) {
vf_pp_in_info =
&pipe->pipe_settings.capture.capture_pp_binary.vf_frame_info;
} else {
vf_pp_in_info =
&pipe->pipe_settings.capture.post_isp_binary.vf_frame_info;
}
{
struct ia_css_binary_descr vf_pp_descr;
ia_css_pipe_get_vfpp_binarydesc(pipe,
&vf_pp_descr, vf_pp_in_info, pipe_vf_out_info);
err = ia_css_binary_find(&vf_pp_descr,
&pipe->pipe_settings.capture.vf_pp_binary);
if (err != IA_CSS_SUCCESS)
return err;
}
#ifdef USE_INPUT_SYSTEM_VERSION_2401
need_isp_copy = pipe->stream->config.mode == IA_CSS_INPUT_MODE_SENSOR;
#endif
if (need_isp_copy)
err = load_copy_binary(pipe,
&pipe->pipe_settings.capture.copy_binary,
&pipe->pipe_settings.capture.pre_isp_binary);
return err;
}
static bool copy_on_sp(struct ia_css_pipe *pipe)
{
bool rval;
assert(pipe != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "copy_on_sp() enter:\n");
rval = true;
rval &= (pipe->mode == IA_CSS_PIPE_ID_CAPTURE);
rval &= (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_RAW);
rval &= ((pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8) ||
(pipe->config.mode == IA_CSS_PIPE_MODE_COPY));
return rval;
}
static enum ia_css_err load_capture_binaries(
struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
bool must_be_raw;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
if (pipe->pipe_settings.capture.primary_binary[0].info) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
must_be_raw =
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_ADVANCED ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_LOW_LIGHT;
err = ia_css_util_check_input(&pipe->stream->config, must_be_raw, false);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (copy_on_sp(pipe) &&
pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8) {
ia_css_frame_info_init(
&pipe->output_info[0],
JPEG_BYTES,
1,
IA_CSS_FRAME_FORMAT_BINARY_8,
0);
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
switch (pipe->config.default_capture_config.mode) {
case IA_CSS_CAPTURE_MODE_RAW:
err = load_copy_binaries(pipe);
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2401)
if (err == IA_CSS_SUCCESS)
pipe->pipe_settings.capture.copy_binary.online = pipe->stream->config.online;
#endif
break;
case IA_CSS_CAPTURE_MODE_BAYER:
err = load_bayer_isp_binaries(pipe);
break;
case IA_CSS_CAPTURE_MODE_PRIMARY:
err = load_primary_binaries(pipe);
break;
case IA_CSS_CAPTURE_MODE_ADVANCED:
err = load_advanced_binaries(pipe);
break;
case IA_CSS_CAPTURE_MODE_LOW_LIGHT:
err = load_low_light_binaries(pipe);
break;
}
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
unload_capture_binaries(struct ia_css_pipe *pipe)
{
unsigned int i;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || ((pipe->mode != IA_CSS_PIPE_ID_CAPTURE) && (pipe->mode != IA_CSS_PIPE_ID_COPY))) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.capture.copy_binary);
for (i = 0; i < MAX_NUM_PRIMARY_STAGES; i++)
ia_css_binary_unload(&pipe->pipe_settings.capture.primary_binary[i]);
ia_css_binary_unload(&pipe->pipe_settings.capture.pre_isp_binary);
ia_css_binary_unload(&pipe->pipe_settings.capture.anr_gdc_binary);
ia_css_binary_unload(&pipe->pipe_settings.capture.post_isp_binary);
ia_css_binary_unload(&pipe->pipe_settings.capture.capture_pp_binary);
ia_css_binary_unload(&pipe->pipe_settings.capture.capture_ldc_binary);
ia_css_binary_unload(&pipe->pipe_settings.capture.vf_pp_binary);
for (i = 0; i < pipe->pipe_settings.capture.num_yuv_scaler; i++)
ia_css_binary_unload(&pipe->pipe_settings.capture.yuv_scaler_binary[i]);
kfree(pipe->pipe_settings.capture.is_output_stage);
pipe->pipe_settings.capture.is_output_stage = NULL;
kfree(pipe->pipe_settings.capture.yuv_scaler_binary);
pipe->pipe_settings.capture.yuv_scaler_binary = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static bool
need_downscaling(const struct ia_css_resolution in_res,
const struct ia_css_resolution out_res)
{
if (in_res.width > out_res.width || in_res.height > out_res.height)
return true;
return false;
}
static bool
need_yuv_scaler_stage(const struct ia_css_pipe *pipe)
{
unsigned int i;
struct ia_css_resolution in_res, out_res;
bool need_format_conversion = false;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_YUVPP);
need_format_conversion =
((pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY) &&
(pipe->output_info[0].format != IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8));
in_res = pipe->config.input_effective_res;
if (pipe->config.enable_dz)
return true;
if ((pipe->output_info[0].res.width != 0) && need_format_conversion)
return true;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
out_res = pipe->output_info[i].res;
if ((out_res.width != 0) && need_downscaling(in_res, out_res))
return true;
}
return false;
}
static enum ia_css_err ia_css_pipe_create_cas_scaler_desc_single_output(
struct ia_css_frame_info *cas_scaler_in_info,
struct ia_css_frame_info *cas_scaler_out_info,
struct ia_css_frame_info *cas_scaler_vf_info,
struct ia_css_cas_binary_descr *descr)
{
unsigned int i;
unsigned int hor_ds_factor = 0, ver_ds_factor = 0;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_frame_info tmp_in_info = IA_CSS_BINARY_DEFAULT_FRAME_INFO;
unsigned max_scale_factor_per_stage = MAX_PREFERRED_YUV_DS_PER_STEP;
assert(cas_scaler_in_info != NULL);
assert(cas_scaler_out_info != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_create_cas_scaler_desc() enter:\n");
descr->num_output_stage = 1;
hor_ds_factor = CEIL_DIV(cas_scaler_in_info->res.width , cas_scaler_out_info->res.width);
ver_ds_factor = CEIL_DIV(cas_scaler_in_info->res.height, cas_scaler_out_info->res.height);
assert(hor_ds_factor == ver_ds_factor);
i = 1;
while (i < hor_ds_factor) {
descr->num_stage++;
i *= max_scale_factor_per_stage;
}
descr->in_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->in_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->internal_out_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->internal_out_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->out_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->out_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->vf_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->vf_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->is_output_stage = kmalloc(descr->num_stage * sizeof(bool), GFP_KERNEL);
if (descr->is_output_stage == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
tmp_in_info = *cas_scaler_in_info;
for (i = 0; i < descr->num_stage; i++) {
descr->in_info[i] = tmp_in_info;
if ((tmp_in_info.res.width / max_scale_factor_per_stage) <= cas_scaler_out_info->res.width) {
descr->is_output_stage[i] = true;
if ((descr->num_output_stage > 1) && (i != (descr->num_stage - 1))) {
descr->internal_out_info[i].res.width = cas_scaler_out_info->res.width;
descr->internal_out_info[i].res.height = cas_scaler_out_info->res.height;
descr->internal_out_info[i].padded_width = cas_scaler_out_info->padded_width;
descr->internal_out_info[i].format = IA_CSS_FRAME_FORMAT_YUV420;
} else {
assert(i == (descr->num_stage - 1));
descr->internal_out_info[i].res.width = 0;
descr->internal_out_info[i].res.height = 0;
}
descr->out_info[i].res.width = cas_scaler_out_info->res.width;
descr->out_info[i].res.height = cas_scaler_out_info->res.height;
descr->out_info[i].padded_width = cas_scaler_out_info->padded_width;
descr->out_info[i].format = cas_scaler_out_info->format;
if (cas_scaler_vf_info != NULL) {
descr->vf_info[i].res.width = cas_scaler_vf_info->res.width;
descr->vf_info[i].res.height = cas_scaler_vf_info->res.height;
descr->vf_info[i].padded_width = cas_scaler_vf_info->padded_width;
ia_css_frame_info_set_format(&descr->vf_info[i], IA_CSS_FRAME_FORMAT_YUV_LINE);
} else {
descr->vf_info[i].res.width = 0;
descr->vf_info[i].res.height = 0;
descr->vf_info[i].padded_width = 0;
}
} else {
descr->is_output_stage[i] = false;
descr->internal_out_info[i].res.width = tmp_in_info.res.width / max_scale_factor_per_stage;
descr->internal_out_info[i].res.height = tmp_in_info.res.height / max_scale_factor_per_stage;
descr->internal_out_info[i].format = IA_CSS_FRAME_FORMAT_YUV420;
ia_css_frame_info_init(&descr->internal_out_info[i],
tmp_in_info.res.width / max_scale_factor_per_stage,
tmp_in_info.res.height / max_scale_factor_per_stage,
IA_CSS_FRAME_FORMAT_YUV420, 0);
descr->out_info[i].res.width = 0;
descr->out_info[i].res.height = 0;
descr->vf_info[i].res.width = 0;
descr->vf_info[i].res.height = 0;
}
tmp_in_info = descr->internal_out_info[i];
}
ERR:
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_create_cas_scaler_desc() leave, err=%d\n",
err);
return err;
}
static enum ia_css_err ia_css_pipe_create_cas_scaler_desc(struct ia_css_pipe *pipe,
struct ia_css_cas_binary_descr *descr)
{
struct ia_css_frame_info in_info = IA_CSS_BINARY_DEFAULT_FRAME_INFO;
struct ia_css_frame_info *out_info[IA_CSS_PIPE_MAX_OUTPUT_STAGE];
struct ia_css_frame_info *vf_out_info[IA_CSS_PIPE_MAX_OUTPUT_STAGE];
struct ia_css_frame_info tmp_in_info = IA_CSS_BINARY_DEFAULT_FRAME_INFO;
unsigned int i, j;
unsigned int hor_scale_factor[IA_CSS_PIPE_MAX_OUTPUT_STAGE],
ver_scale_factor[IA_CSS_PIPE_MAX_OUTPUT_STAGE],
scale_factor = 0;
unsigned int num_stages = 0;
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned max_scale_factor_per_stage = MAX_PREFERRED_YUV_DS_PER_STEP;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_create_cas_scaler_desc() enter:\n");
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
out_info[i] = NULL;
vf_out_info[i] = NULL;
hor_scale_factor[i] = 0;
ver_scale_factor[i] = 0;
}
in_info.res = pipe->config.input_effective_res;
in_info.padded_width = in_info.res.width;
descr->num_output_stage = 0;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if (pipe->output_info[i].res.width != 0) {
out_info[i] = &pipe->output_info[i];
if (pipe->vf_output_info[i].res.width != 0)
vf_out_info[i] = &pipe->vf_output_info[i];
descr->num_output_stage += 1;
}
if (out_info[i] != NULL) {
hor_scale_factor[i] = CEIL_DIV(in_info.res.width, out_info[i]->res.width);
ver_scale_factor[i] = CEIL_DIV(in_info.res.height, out_info[i]->res.height);
assert(hor_scale_factor[i] == ver_scale_factor[i]);
scale_factor = 1;
do {
num_stages++;
scale_factor *= max_scale_factor_per_stage;
} while (scale_factor < hor_scale_factor[i]);
in_info.res = out_info[i]->res;
}
}
if (need_yuv_scaler_stage(pipe) && (num_stages == 0))
num_stages = 1;
descr->num_stage = num_stages;
descr->in_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->in_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->internal_out_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->internal_out_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->out_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->out_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->vf_info = kmalloc(descr->num_stage * sizeof(struct ia_css_frame_info), GFP_KERNEL);
if (descr->vf_info == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
descr->is_output_stage = kmalloc(descr->num_stage * sizeof(bool), GFP_KERNEL);
if (descr->is_output_stage == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if (out_info[i]) {
if (i > 0) {
assert((out_info[i-1]->res.width >= out_info[i]->res.width) &&
(out_info[i-1]->res.height >= out_info[i]->res.height));
}
}
}
tmp_in_info.res = pipe->config.input_effective_res;
tmp_in_info.format = IA_CSS_FRAME_FORMAT_YUV420;
for (i = 0, j = 0; i < descr->num_stage; i++) {
assert(j < 2);
assert(out_info[j] != NULL);
descr->in_info[i] = tmp_in_info;
if ((tmp_in_info.res.width / max_scale_factor_per_stage) <= out_info[j]->res.width) {
descr->is_output_stage[i] = true;
if ((descr->num_output_stage > 1) && (i != (descr->num_stage - 1))) {
descr->internal_out_info[i].res.width = out_info[j]->res.width;
descr->internal_out_info[i].res.height = out_info[j]->res.height;
descr->internal_out_info[i].padded_width = out_info[j]->padded_width;
descr->internal_out_info[i].format = IA_CSS_FRAME_FORMAT_YUV420;
} else {
assert(i == (descr->num_stage - 1));
descr->internal_out_info[i].res.width = 0;
descr->internal_out_info[i].res.height = 0;
}
descr->out_info[i].res.width = out_info[j]->res.width;
descr->out_info[i].res.height = out_info[j]->res.height;
descr->out_info[i].padded_width = out_info[j]->padded_width;
descr->out_info[i].format = out_info[j]->format;
if (vf_out_info[j] != NULL) {
descr->vf_info[i].res.width = vf_out_info[j]->res.width;
descr->vf_info[i].res.height = vf_out_info[j]->res.height;
descr->vf_info[i].padded_width = vf_out_info[j]->padded_width;
ia_css_frame_info_set_format(&descr->vf_info[i], IA_CSS_FRAME_FORMAT_YUV_LINE);
} else {
descr->vf_info[i].res.width = 0;
descr->vf_info[i].res.height = 0;
descr->vf_info[i].padded_width = 0;
}
j++;
} else {
descr->is_output_stage[i] = false;
descr->internal_out_info[i].res.width = tmp_in_info.res.width / max_scale_factor_per_stage;
descr->internal_out_info[i].res.height = tmp_in_info.res.height / max_scale_factor_per_stage;
descr->internal_out_info[i].format = IA_CSS_FRAME_FORMAT_YUV420;
ia_css_frame_info_init(&descr->internal_out_info[i],
tmp_in_info.res.width / max_scale_factor_per_stage,
tmp_in_info.res.height / max_scale_factor_per_stage,
IA_CSS_FRAME_FORMAT_YUV420, 0);
descr->out_info[i].res.width = 0;
descr->out_info[i].res.height = 0;
descr->vf_info[i].res.width = 0;
descr->vf_info[i].res.height = 0;
}
tmp_in_info = descr->internal_out_info[i];
}
ERR:
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_create_cas_scaler_desc() leave, err=%d\n",
err);
return err;
}
static void ia_css_pipe_destroy_cas_scaler_desc(struct ia_css_cas_binary_descr *descr)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_destroy_cas_scaler_desc() enter:\n");
kfree(descr->in_info);
descr->in_info = NULL;
kfree(descr->internal_out_info);
descr->internal_out_info = NULL;
kfree(descr->out_info);
descr->out_info = NULL;
kfree(descr->vf_info);
descr->vf_info = NULL;
kfree(descr->is_output_stage);
descr->is_output_stage = NULL;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_pipe_destroy_cas_scaler_desc() leave\n");
}
static enum ia_css_err
load_yuvpp_binaries(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
bool need_scaler = false;
struct ia_css_frame_info *vf_pp_in_info[IA_CSS_PIPE_MAX_OUTPUT_STAGE];
struct ia_css_yuvpp_settings *mycs;
struct ia_css_binary *next_binary;
struct ia_css_cas_binary_descr cas_scaler_descr = IA_CSS_DEFAULT_CAS_BINARY_DESCR;
unsigned int i, j;
bool need_isp_copy_binary = false;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->stream != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_YUVPP);
if (pipe->pipe_settings.yuvpp.copy_binary.info)
goto ERR;
err = ia_css_util_check_input(&pipe->stream->config, false, false);
if (err != IA_CSS_SUCCESS)
goto ERR;
mycs = &pipe->pipe_settings.yuvpp;
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if (pipe->vf_output_info[i].res.width != 0) {
err = ia_css_util_check_vf_out_info(&pipe->output_info[i],
&pipe->vf_output_info[i]);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
vf_pp_in_info[i] = NULL;
}
need_scaler = need_yuv_scaler_stage(pipe);
if (need_scaler) {
struct ia_css_binary_descr yuv_scaler_descr;
err = ia_css_pipe_create_cas_scaler_desc(pipe,
&cas_scaler_descr);
if (err != IA_CSS_SUCCESS)
goto ERR;
mycs->num_output = cas_scaler_descr.num_output_stage;
mycs->num_yuv_scaler = cas_scaler_descr.num_stage;
mycs->yuv_scaler_binary = kzalloc(cas_scaler_descr.num_stage *
sizeof(struct ia_css_binary), GFP_KERNEL);
if (mycs->yuv_scaler_binary == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
mycs->is_output_stage = kzalloc(cas_scaler_descr.num_stage *
sizeof(bool), GFP_KERNEL);
if (mycs->is_output_stage == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
for (i = 0; i < cas_scaler_descr.num_stage; i++) {
mycs->is_output_stage[i] = cas_scaler_descr.is_output_stage[i];
ia_css_pipe_get_yuvscaler_binarydesc(pipe,
&yuv_scaler_descr, &cas_scaler_descr.in_info[i],
&cas_scaler_descr.out_info[i],
&cas_scaler_descr.internal_out_info[i],
&cas_scaler_descr.vf_info[i]);
err = ia_css_binary_find(&yuv_scaler_descr,
&mycs->yuv_scaler_binary[i]);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
ia_css_pipe_destroy_cas_scaler_desc(&cas_scaler_descr);
} else {
mycs->num_output = 1;
}
if (need_scaler) {
next_binary = &mycs->yuv_scaler_binary[0];
} else {
next_binary = NULL;
}
#if defined(USE_INPUT_SYSTEM_VERSION_2401)
need_isp_copy_binary =
(pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_YUV422_8);
#else
need_isp_copy_binary = true;
#endif
if (need_isp_copy_binary) {
err = load_copy_binary(pipe,
&mycs->copy_binary,
next_binary);
if (err != IA_CSS_SUCCESS)
goto ERR;
pipe->pipe_settings.capture.copy_binary.online = pipe->stream->config.online;
}
if (need_scaler) {
for (i = 0, j = 0; i < mycs->num_yuv_scaler; i++) {
if (mycs->is_output_stage[i]) {
assert(j < 2);
vf_pp_in_info[j] =
&mycs->yuv_scaler_binary[i].vf_frame_info;
j++;
}
}
mycs->num_vf_pp = j;
} else {
vf_pp_in_info[0] =
&mycs->copy_binary.vf_frame_info;
for (i = 1; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
vf_pp_in_info[i] = NULL;
}
mycs->num_vf_pp = 1;
}
mycs->vf_pp_binary = kzalloc(mycs->num_vf_pp * sizeof(struct ia_css_binary),
GFP_KERNEL);
if (mycs->vf_pp_binary == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
goto ERR;
}
{
struct ia_css_binary_descr vf_pp_descr;
for (i = 0; i < mycs->num_vf_pp; i++) {
if (pipe->vf_output_info[i].res.width != 0) {
ia_css_pipe_get_vfpp_binarydesc(pipe,
&vf_pp_descr, vf_pp_in_info[i], &pipe->vf_output_info[i]);
err = ia_css_binary_find(&vf_pp_descr, &mycs->vf_pp_binary[i]);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
}
}
if (err != IA_CSS_SUCCESS)
goto ERR;
ERR:
if (need_scaler) {
ia_css_pipe_destroy_cas_scaler_desc(&cas_scaler_descr);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "load_yuvpp_binaries() leave, err=%d\n",
err);
return err;
}
static enum ia_css_err
unload_yuvpp_binaries(struct ia_css_pipe *pipe)
{
unsigned int i;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_YUVPP)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_binary_unload(&pipe->pipe_settings.yuvpp.copy_binary);
for (i = 0; i < pipe->pipe_settings.yuvpp.num_yuv_scaler; i++) {
ia_css_binary_unload(&pipe->pipe_settings.yuvpp.yuv_scaler_binary[i]);
}
for (i = 0; i < pipe->pipe_settings.yuvpp.num_vf_pp; i++) {
ia_css_binary_unload(&pipe->pipe_settings.yuvpp.vf_pp_binary[i]);
}
kfree(pipe->pipe_settings.yuvpp.is_output_stage);
pipe->pipe_settings.yuvpp.is_output_stage = NULL;
kfree(pipe->pipe_settings.yuvpp.yuv_scaler_binary);
pipe->pipe_settings.yuvpp.yuv_scaler_binary = NULL;
kfree(pipe->pipe_settings.yuvpp.vf_pp_binary);
pipe->pipe_settings.yuvpp.vf_pp_binary = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err yuvpp_start(struct ia_css_pipe *pipe)
{
struct ia_css_binary *copy_binary;
enum ia_css_err err = IA_CSS_SUCCESS;
enum sh_css_pipe_config_override copy_ovrd;
enum ia_css_input_mode yuvpp_pipe_input_mode;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->mode != IA_CSS_PIPE_ID_YUVPP)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
yuvpp_pipe_input_mode = pipe->stream->config.mode;
copy_binary = &pipe->pipe_settings.yuvpp.copy_binary;
sh_css_metrics_start_frame();
#if !defined(HAS_NO_INPUT_SYSTEM) && ( defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401) )
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#endif
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
}
start_pipe(pipe, copy_ovrd, yuvpp_pipe_input_mode);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_pipe_unload_binaries(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
switch (pipe->mode) {
case IA_CSS_PIPE_ID_PREVIEW:
err = unload_preview_binaries(pipe);
break;
case IA_CSS_PIPE_ID_VIDEO:
err = unload_video_binaries(pipe);
break;
case IA_CSS_PIPE_ID_CAPTURE:
err = unload_capture_binaries(pipe);
break;
case IA_CSS_PIPE_ID_YUVPP:
err = unload_yuvpp_binaries(pipe);
break;
default:
break;
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_pipe_load_binaries(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
assert(pipe != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "sh_css_pipe_load_binaries() enter:\n");
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY)
return err;
switch (pipe->mode) {
case IA_CSS_PIPE_ID_PREVIEW:
err = load_preview_binaries(pipe);
break;
case IA_CSS_PIPE_ID_VIDEO:
err = load_video_binaries(pipe);
break;
case IA_CSS_PIPE_ID_CAPTURE:
err = load_capture_binaries(pipe);
break;
case IA_CSS_PIPE_ID_YUVPP:
err = load_yuvpp_binaries(pipe);
break;
case IA_CSS_PIPE_ID_ACC:
break;
default:
err = IA_CSS_ERR_INTERNAL_ERROR;
break;
}
if (err != IA_CSS_SUCCESS) {
if (sh_css_pipe_unload_binaries(pipe) != IA_CSS_SUCCESS) {
err = IA_CSS_ERR_INTERNAL_ERROR;
}
}
return err;
}
static enum ia_css_err
create_host_yuvpp_pipeline(struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipeline_stage *vf_pp_stage = NULL,
*copy_stage = NULL,
*yuv_scaler_stage = NULL;
struct ia_css_binary *copy_binary,
*vf_pp_binary,
*yuv_scaler_binary;
bool need_scaler = false;
unsigned int num_stage, num_vf_pp_stage, num_output_stage;
unsigned int i, j;
struct ia_css_frame *in_frame = NULL;
struct ia_css_frame *out_frame[IA_CSS_PIPE_MAX_OUTPUT_STAGE];
struct ia_css_frame *bin_out_frame[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
struct ia_css_frame *vf_frame[IA_CSS_PIPE_MAX_OUTPUT_STAGE];
struct ia_css_pipeline_stage_desc stage_desc;
bool need_in_frameinfo_memory = false;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
bool sensor = false;
bool buffered_sensor = false;
bool online = false;
bool continuous = false;
#endif
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if ((pipe == NULL) || (pipe->stream == NULL) || (pipe->mode != IA_CSS_PIPE_ID_YUVPP)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
me = &pipe->pipeline;
ia_css_pipeline_clean(me);
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
out_frame[i] = NULL;
vf_frame[i] = NULL;
}
ia_css_pipe_util_create_output_frames(bin_out_frame);
num_stage = pipe->pipe_settings.yuvpp.num_yuv_scaler;
num_vf_pp_stage = pipe->pipe_settings.yuvpp.num_vf_pp;
num_output_stage = pipe->pipe_settings.yuvpp.num_output;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
sensor = pipe->stream->config.mode == IA_CSS_INPUT_MODE_SENSOR;
buffered_sensor = pipe->stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR;
online = pipe->stream->config.online;
continuous = pipe->stream->config.continuous;
need_in_frameinfo_memory =
!((sensor && (online || continuous)) || (buffered_sensor && continuous));
#else
need_in_frameinfo_memory = pipe->stream->config.mode == IA_CSS_INPUT_MODE_MEMORY;
#endif
if (need_in_frameinfo_memory) {
int in_frame_format;
if (pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_YUV420_8_LEGACY) {
in_frame_format = IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8;
} else if (pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_YUV422_8) {
in_frame_format = IA_CSS_FRAME_FORMAT_RAW;
} else {
in_frame_format = IA_CSS_FRAME_FORMAT_NV12;
}
err = init_in_frameinfo_memory_defaults(pipe,
&me->in_frame,
in_frame_format);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
in_frame = &me->in_frame;
} else {
in_frame = NULL;
}
for (i = 0; i < num_output_stage; i++) {
assert(i < IA_CSS_PIPE_MAX_OUTPUT_STAGE);
if (pipe->output_info[i].res.width != 0) {
err = init_out_frameinfo_defaults(pipe, &me->out_frame[i], i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
out_frame[i] = &me->out_frame[i];
}
if (pipe->vf_output_info[i].res.width != 0) {
err = init_vf_frameinfo_defaults(pipe, &me->vf_frame[i], i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
vf_frame[i] = &me->vf_frame[i];
}
}
copy_binary = &pipe->pipe_settings.yuvpp.copy_binary;
vf_pp_binary = pipe->pipe_settings.yuvpp.vf_pp_binary;
yuv_scaler_binary = pipe->pipe_settings.yuvpp.yuv_scaler_binary;
need_scaler = need_yuv_scaler_stage(pipe);
if (pipe->pipe_settings.yuvpp.copy_binary.info) {
struct ia_css_frame *in_frame_local = NULL;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (!online)
in_frame_local = in_frame;
#endif
if (need_scaler) {
ia_css_pipe_util_set_output_frames(bin_out_frame, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
bin_out_frame, in_frame_local, NULL);
} else {
ia_css_pipe_util_set_output_frames(bin_out_frame, 0, out_frame[0]);
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
bin_out_frame, in_frame_local, NULL);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&copy_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (copy_stage) {
copy_stage->args.copy_vf = !need_scaler;
copy_stage->args.copy_output = true;
in_frame = copy_stage->args.out_frame[0];
}
}
if (need_scaler) {
struct ia_css_frame *tmp_out_frame = NULL;
struct ia_css_frame *tmp_vf_frame = NULL;
struct ia_css_frame *tmp_in_frame = in_frame;
for (i = 0, j = 0; i < num_stage; i++) {
assert(j < num_output_stage);
if (pipe->pipe_settings.yuvpp.is_output_stage[i] == true) {
tmp_out_frame = out_frame[j];
tmp_vf_frame = vf_frame[j];
} else {
tmp_out_frame = NULL;
tmp_vf_frame = NULL;
}
err = add_yuv_scaler_stage(pipe, me, tmp_in_frame, tmp_out_frame,
NULL,
&yuv_scaler_binary[i],
&yuv_scaler_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
tmp_in_frame = yuv_scaler_stage->args.out_frame[1];
if (pipe->pipe_settings.yuvpp.is_output_stage[i] == true) {
if (tmp_vf_frame && (tmp_vf_frame->info.res.width != 0)) {
in_frame = yuv_scaler_stage->args.out_vf_frame;
err = add_vf_pp_stage(pipe, in_frame, tmp_vf_frame, &vf_pp_binary[j],
&vf_pp_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
j++;
}
}
} else if (copy_stage != NULL) {
if (vf_frame[0] != NULL && vf_frame[0]->info.res.width != 0) {
in_frame = copy_stage->args.out_vf_frame;
err = add_vf_pp_stage(pipe, in_frame, vf_frame[0], &vf_pp_binary[0],
&vf_pp_stage);
}
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
create_host_copy_pipeline(struct ia_css_pipe *pipe,
unsigned max_input_width,
struct ia_css_frame *out_frame)
{
struct ia_css_pipeline *me;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipeline_stage_desc stage_desc;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"create_host_copy_pipeline() enter:\n");
me = &pipe->pipeline;
ia_css_pipeline_clean(me);
out_frame->contiguous = false;
out_frame->flash_state = IA_CSS_FRAME_FLASH_STATE_NONE;
if (copy_on_sp(pipe) &&
pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8) {
ia_css_frame_info_init(
&out_frame->info,
JPEG_BYTES,
1,
IA_CSS_FRAME_FORMAT_BINARY_8,
0);
} else if (out_frame->info.format == IA_CSS_FRAME_FORMAT_RAW) {
out_frame->info.raw_bit_depth =
ia_css_pipe_util_pipe_input_format_bpp(pipe);
}
me->num_stages = 1;
me->pipe_id = IA_CSS_PIPE_ID_COPY;
pipe->mode = IA_CSS_PIPE_ID_COPY;
ia_css_pipe_get_sp_func_stage_desc(&stage_desc, out_frame,
IA_CSS_PIPELINE_RAW_COPY, max_input_width);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
NULL);
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"create_host_copy_pipeline() leave:\n");
return err;
}
static enum ia_css_err
create_host_isyscopy_capture_pipeline(struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me = &pipe->pipeline;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipeline_stage_desc stage_desc;
struct ia_css_frame *out_frame = &me->out_frame[0];
struct ia_css_pipeline_stage *out_stage = NULL;
unsigned int thread_id;
enum sh_css_queue_id queue_id;
unsigned int max_input_width = MAX_VECTORS_PER_INPUT_LINE_CONT * ISP_VEC_NELEMS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"create_host_isyscopy_capture_pipeline() enter:\n");
ia_css_pipeline_clean(me);
err = sh_css_pipe_get_output_frame_info(pipe, &out_frame->info, 0);
if (err != IA_CSS_SUCCESS)
return err;
out_frame->contiguous = false;
out_frame->flash_state = IA_CSS_FRAME_FLASH_STATE_NONE;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, thread_id, &queue_id);
out_frame->dynamic_queue_id = queue_id;
out_frame->buf_type = IA_CSS_BUFFER_TYPE_OUTPUT_FRAME;
me->num_stages = 1;
me->pipe_id = IA_CSS_PIPE_ID_CAPTURE;
pipe->mode = IA_CSS_PIPE_ID_CAPTURE;
ia_css_pipe_get_sp_func_stage_desc(&stage_desc, out_frame,
IA_CSS_PIPELINE_ISYS_COPY, max_input_width);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc, &out_stage);
if(err != IA_CSS_SUCCESS)
return err;
ia_css_pipeline_finalize_stages(me, pipe->stream->config.continuous);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"create_host_isyscopy_capture_pipeline() leave:\n");
return err;
}
static enum ia_css_err
create_host_regular_capture_pipeline(struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me;
enum ia_css_err err = IA_CSS_SUCCESS;
enum ia_css_capture_mode mode;
struct ia_css_pipeline_stage *current_stage = NULL;
struct ia_css_pipeline_stage *yuv_scaler_stage = NULL;
struct ia_css_binary *copy_binary,
*primary_binary[MAX_NUM_PRIMARY_STAGES],
*vf_pp_binary,
*pre_isp_binary,
*anr_gdc_binary,
*post_isp_binary,
*yuv_scaler_binary,
*capture_pp_binary,
*capture_ldc_binary;
bool need_pp = false;
bool raw;
struct ia_css_frame *in_frame;
struct ia_css_frame *out_frame;
struct ia_css_frame *out_frames[IA_CSS_BINARY_MAX_OUTPUT_PORTS];
struct ia_css_frame *vf_frame;
struct ia_css_pipeline_stage_desc stage_desc;
bool need_in_frameinfo_memory = false;
#ifdef USE_INPUT_SYSTEM_VERSION_2401
bool sensor = false;
bool buffered_sensor = false;
bool online = false;
bool continuous = false;
#endif
unsigned int i, num_yuv_scaler, num_primary_stage;
bool need_yuv_pp = false;
bool *is_output_stage = NULL;
bool need_ldc = false;
IA_CSS_ENTER_PRIVATE("");
assert(pipe != NULL);
assert(pipe->stream != NULL);
assert(pipe->mode == IA_CSS_PIPE_ID_CAPTURE || pipe->mode == IA_CSS_PIPE_ID_COPY);
me = &pipe->pipeline;
mode = pipe->config.default_capture_config.mode;
raw = (mode == IA_CSS_CAPTURE_MODE_RAW);
ia_css_pipeline_clean(me);
ia_css_pipe_util_create_output_frames(out_frames);
#ifdef USE_INPUT_SYSTEM_VERSION_2401
sensor = (pipe->stream->config.mode == IA_CSS_INPUT_MODE_SENSOR);
buffered_sensor = (pipe->stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR);
online = pipe->stream->config.online;
continuous = pipe->stream->config.continuous;
need_in_frameinfo_memory =
!((sensor && (online || continuous)) || (buffered_sensor && (online || continuous)));
#else
need_in_frameinfo_memory = pipe->stream->config.mode == IA_CSS_INPUT_MODE_MEMORY;
#endif
if (need_in_frameinfo_memory) {
err = init_in_frameinfo_memory_defaults(pipe, &me->in_frame, IA_CSS_FRAME_FORMAT_RAW);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
in_frame = &me->in_frame;
} else {
in_frame = NULL;
}
err = init_out_frameinfo_defaults(pipe, &me->out_frame[0], 0);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
out_frame = &me->out_frame[0];
if (pipe->enable_viewfinder[IA_CSS_PIPE_OUTPUT_STAGE_0]) {
if (mode == IA_CSS_CAPTURE_MODE_RAW || mode == IA_CSS_CAPTURE_MODE_BAYER) {
vf_frame = NULL;
} else {
init_vf_frameinfo_defaults(pipe, &me->vf_frame[0], 0);
vf_frame = &me->vf_frame[0];
}
} else {
vf_frame = NULL;
}
copy_binary = &pipe->pipe_settings.capture.copy_binary;
num_primary_stage = pipe->pipe_settings.capture.num_primary_stage;
if ((num_primary_stage == 0) && (mode == IA_CSS_CAPTURE_MODE_PRIMARY)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
for (i = 0; i < num_primary_stage; i++) {
primary_binary[i] = &pipe->pipe_settings.capture.primary_binary[i];
}
vf_pp_binary = &pipe->pipe_settings.capture.vf_pp_binary;
pre_isp_binary = &pipe->pipe_settings.capture.pre_isp_binary;
anr_gdc_binary = &pipe->pipe_settings.capture.anr_gdc_binary;
post_isp_binary = &pipe->pipe_settings.capture.post_isp_binary;
capture_pp_binary = &pipe->pipe_settings.capture.capture_pp_binary;
yuv_scaler_binary = pipe->pipe_settings.capture.yuv_scaler_binary;
num_yuv_scaler = pipe->pipe_settings.capture.num_yuv_scaler;
is_output_stage = pipe->pipe_settings.capture.is_output_stage;
capture_ldc_binary = &pipe->pipe_settings.capture.capture_ldc_binary;
need_pp = (need_capture_pp(pipe) || pipe->output_stage) &&
mode != IA_CSS_CAPTURE_MODE_RAW &&
mode != IA_CSS_CAPTURE_MODE_BAYER;
need_yuv_pp = (yuv_scaler_binary != NULL && yuv_scaler_binary->info != NULL);
need_ldc = (capture_ldc_binary != NULL && capture_ldc_binary->info != NULL);
if (pipe->pipe_settings.capture.copy_binary.info) {
if (raw) {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2401)
if (!continuous) {
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
out_frames, in_frame, NULL);
} else {
in_frame = pipe->stream->last_pipe->continuous_frames[0];
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
out_frames, in_frame, NULL);
}
#else
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
out_frames, NULL, NULL);
#endif
} else {
ia_css_pipe_util_set_output_frames(out_frames, 0, in_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, copy_binary,
out_frames, NULL, NULL);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
} else if (pipe->stream->config.continuous) {
in_frame = pipe->stream->last_pipe->continuous_frames[0];
}
if (mode == IA_CSS_CAPTURE_MODE_PRIMARY) {
unsigned int frm;
struct ia_css_frame *local_in_frame = NULL;
struct ia_css_frame *local_out_frame = NULL;
for (i = 0; i < num_primary_stage; i++) {
if (i == 0)
local_in_frame = in_frame;
else
local_in_frame = NULL;
#ifndef ISP2401
if (!need_pp && (i == num_primary_stage - 1))
#else
if (!need_pp && (i == num_primary_stage - 1) && !need_ldc)
#endif
local_out_frame = out_frame;
else
local_out_frame = NULL;
ia_css_pipe_util_set_output_frames(out_frames, 0, local_out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, primary_binary[i],
out_frames, local_in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
(void)frm;
current_stage->args.copy_vf =
primary_binary[0]->info->sp.pipeline.mode ==
IA_CSS_BINARY_MODE_COPY;
current_stage->args.copy_output = current_stage->args.copy_vf;
} else if (mode == IA_CSS_CAPTURE_MODE_ADVANCED ||
mode == IA_CSS_CAPTURE_MODE_LOW_LIGHT) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, pre_isp_binary,
out_frames, in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc, NULL);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, anr_gdc_binary,
out_frames, NULL, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc, NULL);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if(need_pp) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, post_isp_binary,
out_frames, NULL, NULL);
} else {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, post_isp_binary,
out_frames, NULL, NULL);
}
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc, &current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
} else if (mode == IA_CSS_CAPTURE_MODE_BAYER) {
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, pre_isp_binary,
out_frames, in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
NULL);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
#ifndef ISP2401
if (need_pp && current_stage) {
struct ia_css_frame *local_in_frame = NULL;
local_in_frame = current_stage->args.out_frame[0];
if(need_ldc) {
ia_css_pipe_util_set_output_frames(out_frames, 0, NULL);
ia_css_pipe_get_generic_stage_desc(&stage_desc, capture_ldc_binary,
out_frames, local_in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
&current_stage);
local_in_frame = current_stage->args.out_frame[0];
}
err = add_capture_pp_stage(pipe, me, local_in_frame, need_yuv_pp ? NULL : out_frame,
#else
if (need_ldc && current_stage) {
in_frame = current_stage->args.out_frame[0];
ia_css_pipe_util_set_output_frames(out_frames, 0, out_frame);
ia_css_pipe_get_generic_stage_desc(&stage_desc, capture_ldc_binary,
out_frames, in_frame, NULL);
err = ia_css_pipeline_create_and_add_stage(me,
&stage_desc,
NULL);
} else if (need_pp && current_stage) {
in_frame = current_stage->args.out_frame[0];
err = add_capture_pp_stage(pipe, me, in_frame, need_yuv_pp ? NULL : out_frame,
#endif
capture_pp_binary,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
if (need_yuv_pp && current_stage) {
struct ia_css_frame *tmp_in_frame = current_stage->args.out_frame[0];
struct ia_css_frame *tmp_out_frame = NULL;
for (i = 0; i < num_yuv_scaler; i++) {
if (is_output_stage[i] == true)
tmp_out_frame = out_frame;
else
tmp_out_frame = NULL;
err = add_yuv_scaler_stage(pipe, me, tmp_in_frame, tmp_out_frame,
NULL,
&yuv_scaler_binary[i],
&yuv_scaler_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
tmp_in_frame = yuv_scaler_stage->args.out_frame[1];
}
}
if (mode != IA_CSS_CAPTURE_MODE_RAW && mode != IA_CSS_CAPTURE_MODE_BAYER && current_stage && vf_frame) {
in_frame = current_stage->args.out_vf_frame;
err = add_vf_pp_stage(pipe, in_frame, vf_frame, vf_pp_binary,
&current_stage);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
ia_css_pipeline_finalize_stages(&pipe->pipeline, pipe->stream->config.continuous);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"create_host_regular_capture_pipeline() leave:\n");
return IA_CSS_SUCCESS;
}
static enum ia_css_err
create_host_capture_pipeline(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY)
err = create_host_isyscopy_capture_pipeline(pipe);
else
err = create_host_regular_capture_pipeline(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err capture_start(
struct ia_css_pipe *pipe)
{
struct ia_css_pipeline *me;
enum ia_css_err err = IA_CSS_SUCCESS;
enum sh_css_pipe_config_override copy_ovrd;
IA_CSS_ENTER_PRIVATE("pipe = %p", pipe);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
me = &pipe->pipeline;
if ((pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_RAW ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER ) &&
(pipe->config.mode != IA_CSS_PIPE_MODE_COPY)) {
if (copy_on_sp(pipe)) {
err = start_copy_on_sp(pipe, &me->out_frame[0]);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
#if defined(USE_INPUT_SYSTEM_VERSION_2)
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#elif defined(USE_INPUT_SYSTEM_VERSION_2401)
if (pipe->config.mode != IA_CSS_PIPE_MODE_COPY) {
err = send_mipi_frames(pipe);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
#endif
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
copy_ovrd = 1 << thread_id;
}
start_pipe(pipe, copy_ovrd, pipe->stream->config.mode);
#if !defined(HAS_NO_INPUT_SYSTEM) && !defined(USE_INPUT_SYSTEM_VERSION_2401)
if (pipe->config.mode == IA_CSS_PIPE_MODE_COPY && pipe->stream->reconfigure_css_rx) {
ia_css_isys_rx_configure(&pipe->stream->csi_rx_config, pipe->stream->config.mode);
pipe->stream->reconfigure_css_rx = false;
}
#endif
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_pipe_get_output_frame_info(struct ia_css_pipe *pipe,
struct ia_css_frame_info *info,
unsigned int idx)
{
enum ia_css_err err = IA_CSS_SUCCESS;
assert(pipe != NULL);
assert(info != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_pipe_get_output_frame_info() enter:\n");
*info = pipe->output_info[idx];
if (copy_on_sp(pipe) &&
pipe->stream->config.input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8) {
ia_css_frame_info_init(
info,
JPEG_BYTES,
1,
IA_CSS_FRAME_FORMAT_BINARY_8,
0);
} else if (info->format == IA_CSS_FRAME_FORMAT_RAW ||
info->format == IA_CSS_FRAME_FORMAT_RAW_PACKED) {
info->raw_bit_depth =
ia_css_pipe_util_pipe_input_format_bpp(pipe);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_pipe_get_output_frame_info() leave:\n");
return err;
}
#if !defined(HAS_NO_INPUT_SYSTEM)
void
ia_css_stream_send_input_frame(const struct ia_css_stream *stream,
const unsigned short *data,
unsigned int width,
unsigned int height)
{
assert(stream != NULL);
ia_css_inputfifo_send_input_frame(
data, width, height,
stream->config.channel_id,
stream->config.input_config.format,
stream->config.pixels_per_clock == 2);
}
void
ia_css_stream_start_input_frame(const struct ia_css_stream *stream)
{
assert(stream != NULL);
ia_css_inputfifo_start_frame(
stream->config.channel_id,
stream->config.input_config.format,
stream->config.pixels_per_clock == 2);
}
void
ia_css_stream_send_input_line(const struct ia_css_stream *stream,
const unsigned short *data,
unsigned int width,
const unsigned short *data2,
unsigned int width2)
{
assert(stream != NULL);
ia_css_inputfifo_send_line(stream->config.channel_id,
data, width, data2, width2);
}
void
ia_css_stream_send_input_embedded_line(const struct ia_css_stream *stream,
enum ia_css_stream_format format,
const unsigned short *data,
unsigned int width)
{
assert(stream != NULL);
if (data == NULL || width == 0)
return;
ia_css_inputfifo_send_embedded_line(stream->config.channel_id,
format, data, width);
}
void
ia_css_stream_end_input_frame(const struct ia_css_stream *stream)
{
assert(stream != NULL);
ia_css_inputfifo_end_frame(stream->config.channel_id);
}
#endif
static void
append_firmware(struct ia_css_fw_info **l, struct ia_css_fw_info *firmware)
{
IA_CSS_ENTER_PRIVATE("l = %p, firmware = %p", l , firmware);
if (l == NULL) {
IA_CSS_ERROR("NULL fw_info");
IA_CSS_LEAVE_PRIVATE("");
return;
}
while (*l)
l = &(*l)->next;
*l = firmware;
IA_CSS_LEAVE_PRIVATE("");
}
static void
remove_firmware(struct ia_css_fw_info **l, struct ia_css_fw_info *firmware)
{
assert(*l);
assert(firmware);
(void)l;
(void)firmware;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "remove_firmware() enter:\n");
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "remove_firmware() leave:\n");
return;
}
static enum ia_css_err upload_isp_code(struct ia_css_fw_info *firmware)
{
hrt_vaddress binary;
if (firmware == NULL) {
IA_CSS_ERROR("NULL input parameter");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
binary = firmware->info.isp.xmem_addr;
if (!binary) {
unsigned size = firmware->blob.size;
const unsigned char *blob;
const unsigned char *binary_name;
binary_name =
(const unsigned char *)(IA_CSS_EXT_ISP_PROG_NAME(
firmware));
blob = binary_name +
strlen((const char *)binary_name) +
1;
binary = sh_css_load_blob(blob, size);
firmware->info.isp.xmem_addr = binary;
}
if (!binary)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
return IA_CSS_SUCCESS;
}
static enum ia_css_err
acc_load_extension(struct ia_css_fw_info *firmware)
{
enum ia_css_err err;
struct ia_css_fw_info *hd = firmware;
while (hd){
err = upload_isp_code(hd);
if (err != IA_CSS_SUCCESS)
return err;
hd = hd->next;
}
if (firmware == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
firmware->loaded = true;
return IA_CSS_SUCCESS;
}
static void
acc_unload_extension(struct ia_css_fw_info *firmware)
{
struct ia_css_fw_info *hd = firmware;
struct ia_css_fw_info *hdn = NULL;
if (firmware == NULL)
return;
while (hd){
hdn = (hd->next) ? &(*hd->next) : NULL;
if (hd->info.isp.xmem_addr) {
hmm_free(hd->info.isp.xmem_addr);
hd->info.isp.xmem_addr = mmgr_NULL;
}
hd->isp_code = NULL;
hd->next = NULL;
hd = hdn;
}
firmware->loaded = false;
}
static enum ia_css_err
ia_css_pipe_load_extension(struct ia_css_pipe *pipe,
struct ia_css_fw_info *firmware)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("fw = %p pipe = %p", firmware, pipe);
if ((firmware == NULL) || (pipe == NULL)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (firmware->info.isp.type == IA_CSS_ACC_OUTPUT) {
if (&pipe->output_stage != NULL)
append_firmware(&pipe->output_stage, firmware);
else {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
}
else if (firmware->info.isp.type == IA_CSS_ACC_VIEWFINDER) {
if (&pipe->vf_stage != NULL)
append_firmware(&pipe->vf_stage, firmware);
else {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INTERNAL_ERROR);
return IA_CSS_ERR_INTERNAL_ERROR;
}
}
err = acc_load_extension(firmware);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static void
ia_css_pipe_unload_extension(struct ia_css_pipe *pipe,
struct ia_css_fw_info *firmware)
{
IA_CSS_ENTER_PRIVATE("fw = %p pipe = %p", firmware, pipe);
if ((firmware == NULL) || (pipe == NULL)) {
IA_CSS_ERROR("NULL input parameters");
IA_CSS_LEAVE_PRIVATE("");
return;
}
if (firmware->info.isp.type == IA_CSS_ACC_OUTPUT)
remove_firmware(&pipe->output_stage, firmware);
else if (firmware->info.isp.type == IA_CSS_ACC_VIEWFINDER)
remove_firmware(&pipe->vf_stage, firmware);
acc_unload_extension(firmware);
IA_CSS_LEAVE_PRIVATE("");
}
bool
ia_css_pipeline_uses_params(struct ia_css_pipeline *me)
{
struct ia_css_pipeline_stage *stage;
assert(me != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipeline_uses_params() enter: me=%p\n", me);
for (stage = me->stages; stage; stage = stage->next)
if (stage->binary_info && stage->binary_info->enable.params) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipeline_uses_params() leave: "
"return_bool=true\n");
return true;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipeline_uses_params() leave: return_bool=false\n");
return false;
}
static enum ia_css_err
sh_css_pipeline_add_acc_stage(struct ia_css_pipeline *pipeline,
const void *acc_fw)
{
struct ia_css_fw_info *fw = (struct ia_css_fw_info *)acc_fw;
enum ia_css_err err = IA_CSS_SUCCESS;
if (fw->loaded == false)
err = acc_load_extension(fw);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_pipeline_add_acc_stage() enter: pipeline=%p,"
" acc_fw=%p\n", pipeline, acc_fw);
if (err == IA_CSS_SUCCESS) {
struct ia_css_pipeline_stage_desc stage_desc;
ia_css_pipe_get_acc_stage_desc(&stage_desc, NULL, fw);
err = ia_css_pipeline_create_and_add_stage(pipeline,
&stage_desc,
NULL);
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"sh_css_pipeline_add_acc_stage() leave: return_err=%d\n",err);
return err;
}
enum ia_css_err ia_css_stream_capture_frame(struct ia_css_stream *stream,
unsigned int exp_id)
{
struct sh_css_tag_descr tag_descr;
uint32_t encoded_tag_descr;
enum ia_css_err err;
assert(stream != NULL);
IA_CSS_ENTER("exp_id=%d", exp_id);
if (exp_id == 0 || !stream->config.continuous) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
sh_css_create_tag_descr(0, 0, 0, exp_id, &tag_descr);
encoded_tag_descr = sh_css_encode_tag_descr(&tag_descr);
err= ia_css_bufq_enqueue_tag_cmd(encoded_tag_descr);
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err ia_css_stream_capture(
struct ia_css_stream *stream,
int num_captures,
unsigned int skip,
int offset)
{
struct sh_css_tag_descr tag_descr;
unsigned int encoded_tag_descr;
enum ia_css_err return_err;
if (stream == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_capture() enter: num_captures=%d,"
" skip=%d, offset=%d\n", num_captures, skip,offset);
if (num_captures < SH_CSS_MINIMUM_TAG_ID) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_capture() leave: return_err=%d\n",
IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
sh_css_create_tag_descr(num_captures, skip, offset, 0, &tag_descr);
encoded_tag_descr = sh_css_encode_tag_descr(&tag_descr);
if (!sh_css_sp_is_running()) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_capture() leaving:"
"queues unavailable\n");
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
return_err = ia_css_bufq_enqueue_tag_cmd((uint32_t)encoded_tag_descr);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_capture() leave: return_err=%d\n",
return_err);
return return_err;
}
void ia_css_stream_request_flash(struct ia_css_stream *stream)
{
(void)stream;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_request_flash() enter: void\n");
#ifndef ISP2401
sh_css_write_host2sp_command(host2sp_cmd_start_flash);
#else
if (sh_css_sp_is_running()) {
if (!sh_css_write_host2sp_command(host2sp_cmd_start_flash)) {
IA_CSS_ERROR("Call to 'sh-css_write_host2sp_command()' failed");
ia_css_debug_dump_sp_sw_debug_info();
ia_css_debug_dump_debug_info(NULL);
}
} else
IA_CSS_LOG("SP is not running!");
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_request_flash() leave: return_void\n");
}
static void
sh_css_init_host_sp_control_vars(void)
{
const struct ia_css_fw_info *fw;
unsigned int HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
unsigned int HIVE_ADDR_host_sp_queues_initialized;
unsigned int HIVE_ADDR_sp_sleep_mode;
unsigned int HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
#ifndef ISP2401
unsigned int HIVE_ADDR_sp_stop_copy_preview;
#endif
unsigned int HIVE_ADDR_host_sp_com;
unsigned int o = offsetof(struct host_sp_communication, host2sp_command)
/ sizeof(int);
#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
unsigned int i;
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_init_host_sp_control_vars() enter: void\n");
fw = &sh_css_sp_fw;
HIVE_ADDR_ia_css_ispctrl_sp_isp_started = fw->info.sp.isp_started;
HIVE_ADDR_host_sp_queues_initialized =
fw->info.sp.host_sp_queues_initialized;
HIVE_ADDR_sp_sleep_mode = fw->info.sp.sleep_mode;
HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb = fw->info.sp.invalidate_tlb;
#ifndef ISP2401
HIVE_ADDR_sp_stop_copy_preview = fw->info.sp.stop_copy_preview;
#endif
HIVE_ADDR_host_sp_com = fw->info.sp.host_sp_com;
(void)HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
(void)HIVE_ADDR_sp_sleep_mode;
(void)HIVE_ADDR_ia_css_dmaproxy_sp_invalidate_tlb;
#ifndef ISP2401
(void)HIVE_ADDR_sp_stop_copy_preview;
#endif
(void)HIVE_ADDR_host_sp_com;
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(ia_css_ispctrl_sp_isp_started),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(host_sp_queues_initialized),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_sleep_mode),
(uint32_t)(0));
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(ia_css_dmaproxy_sp_invalidate_tlb),
(uint32_t)(false));
#ifndef ISP2401
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_stop_copy_preview),
my_css.stop_copy_preview?(uint32_t)(1):(uint32_t)(0));
#endif
store_sp_array_uint(host_sp_com, o, host2sp_cmd_ready);
#if !defined(HAS_NO_INPUT_SYSTEM)
for (i = 0; i < N_CSI_PORTS; i++) {
sh_css_update_host2sp_num_mipi_frames
(my_css.num_mipi_frames[i]);
}
#endif
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_init_host_sp_control_vars() leave: return_void\n");
}
void ia_css_pipe_config_defaults(struct ia_css_pipe_config *pipe_config)
{
struct ia_css_pipe_config def_config = DEFAULT_PIPE_CONFIG;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_pipe_config_defaults()\n");
*pipe_config = def_config;
}
void
ia_css_pipe_extra_config_defaults(struct ia_css_pipe_extra_config *extra_config)
{
if (extra_config == NULL) {
IA_CSS_ERROR("NULL input parameter");
return;
}
extra_config->enable_raw_binning = false;
extra_config->enable_yuv_ds = false;
extra_config->enable_high_speed = false;
extra_config->enable_dvs_6axis = false;
extra_config->enable_reduced_pipe = false;
extra_config->disable_vf_pp = false;
extra_config->enable_fractional_ds = false;
}
void ia_css_stream_config_defaults(struct ia_css_stream_config *stream_config)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_config_defaults()\n");
assert(stream_config != NULL);
memset(stream_config, 0, sizeof(*stream_config));
stream_config->online = true;
stream_config->left_padding = -1;
stream_config->pixels_per_clock = 1;
stream_config->source.port.rxcount = 0x04040404;
}
static enum ia_css_err
ia_css_acc_pipe_create(struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
if (pipe == NULL) {
IA_CSS_ERROR("NULL input parameter");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe->config.acc_num_execs == 0)
pipe->config.acc_num_execs = 1;
if (pipe->config.acc_extension) {
err = ia_css_pipe_load_extension(pipe, pipe->config.acc_extension);
}
return err;
}
enum ia_css_err
ia_css_pipe_create(const struct ia_css_pipe_config *config,
struct ia_css_pipe **pipe)
{
#ifndef ISP2401
if (config == NULL)
#else
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("config = %p, pipe = %p", config, pipe);
if (config == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef ISP2401
if (pipe == NULL)
#else
}
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
#endif
return IA_CSS_ERR_INVALID_ARGUMENTS;
#ifndef ISP2401
return ia_css_pipe_create_extra(config, NULL, pipe);
#else
}
err = ia_css_pipe_create_extra(config, NULL, pipe);
if(err == IA_CSS_SUCCESS) {
IA_CSS_LOG("pipe created successfuly = %p", *pipe);
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
#endif
}
enum ia_css_err
ia_css_pipe_create_extra(const struct ia_css_pipe_config *config,
const struct ia_css_pipe_extra_config *extra_config,
struct ia_css_pipe **pipe)
{
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
struct ia_css_pipe *internal_pipe = NULL;
unsigned int i;
IA_CSS_ENTER_PRIVATE("config = %p, extra_config = %p and pipe = %p", config, extra_config, pipe);
if (my_css.pipe_counter >= IA_CSS_PIPELINE_NUM_MAX) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_RESOURCE_EXHAUSTED);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if ((pipe == NULL) || (config == NULL)) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ia_css_debug_dump_pipe_config(config);
ia_css_debug_dump_pipe_extra_config(extra_config);
err = create_pipe(config->mode, &internal_pipe, false);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
internal_pipe->config = *config;
if (extra_config)
internal_pipe->extra_config = *extra_config;
else
ia_css_pipe_extra_config_defaults(&internal_pipe->extra_config);
if (config->mode == IA_CSS_PIPE_MODE_ACC) {
*pipe = internal_pipe;
if (!internal_pipe->config.acc_extension &&
internal_pipe->config.num_acc_stages == 0){
*pipe = NULL;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
return ia_css_acc_pipe_create(internal_pipe);
}
if (internal_pipe->config.dvs_frame_delay == IA_CSS_FRAME_DELAY_2)
internal_pipe->dvs_frame_delay = 2;
else
internal_pipe->dvs_frame_delay = 1;
if (internal_pipe->extra_config.enable_raw_binning &&
internal_pipe->config.bayer_ds_out_res.width) {
}
if ((internal_pipe->config.vf_pp_in_res.width ||
internal_pipe->config.capt_pp_in_res.width)) {
enum ia_css_frame_format format;
if (internal_pipe->config.vf_pp_in_res.width) {
format = IA_CSS_FRAME_FORMAT_YUV_LINE;
ia_css_frame_info_init(
&internal_pipe->vf_yuv_ds_input_info,
internal_pipe->config.vf_pp_in_res.width,
internal_pipe->config.vf_pp_in_res.height,
format, 0);
}
if (internal_pipe->config.capt_pp_in_res.width) {
format = IA_CSS_FRAME_FORMAT_YUV420;
ia_css_frame_info_init(
&internal_pipe->out_yuv_ds_input_info,
internal_pipe->config.capt_pp_in_res.width,
internal_pipe->config.capt_pp_in_res.height,
format, 0);
}
}
if (internal_pipe->config.vf_pp_in_res.width &&
internal_pipe->config.mode == IA_CSS_PIPE_MODE_PREVIEW) {
ia_css_frame_info_init(
&internal_pipe->vf_yuv_ds_input_info,
internal_pipe->config.vf_pp_in_res.width,
internal_pipe->config.vf_pp_in_res.height,
IA_CSS_FRAME_FORMAT_YUV_LINE, 0);
}
if (internal_pipe->config.bayer_ds_out_res.width) {
ia_css_frame_info_init(
&internal_pipe->bds_output_info,
internal_pipe->config.bayer_ds_out_res.width,
internal_pipe->config.bayer_ds_out_res.height,
IA_CSS_FRAME_FORMAT_RAW, 0);
}
for (i = 0; i < IA_CSS_PIPE_MAX_OUTPUT_STAGE; i++) {
if (internal_pipe->config.output_info[i].res.width) {
err = sh_css_pipe_configure_output(
internal_pipe,
internal_pipe->config.output_info[i].res.width,
internal_pipe->config.output_info[i].res.height,
internal_pipe->config.output_info[i].padded_width,
internal_pipe->config.output_info[i].format,
i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
internal_pipe = NULL;
return err;
}
}
internal_pipe->enable_viewfinder[i] = (internal_pipe->config.vf_output_info[i].res.width != 0);
if (internal_pipe->config.vf_output_info[i].res.width) {
err = sh_css_pipe_configure_viewfinder(
internal_pipe,
internal_pipe->config.vf_output_info[i].res.width,
internal_pipe->config.vf_output_info[i].res.height,
internal_pipe->config.vf_output_info[i].padded_width,
internal_pipe->config.vf_output_info[i].format,
i);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
internal_pipe = NULL;
return err;
}
}
}
if (internal_pipe->config.acc_extension) {
err = ia_css_pipe_load_extension(internal_pipe,
internal_pipe->config.acc_extension);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
sh_css_free(internal_pipe);
return err;
}
}
memset(&internal_pipe->info, 0, sizeof(internal_pipe->info));
*pipe = internal_pipe;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_pipe_get_info(const struct ia_css_pipe *pipe,
struct ia_css_pipe_info *pipe_info)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_pipe_get_info()\n");
assert(pipe_info != NULL);
if (pipe_info == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_pipe_get_info: pipe_info cannot be NULL\n");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (pipe == NULL || pipe->stream == NULL) {
ia_css_debug_dtrace(IA_CSS_DEBUG_ERROR,
"ia_css_pipe_get_info: ia_css_stream_create needs to"
" be called before ia_css_[stream/pipe]_get_info\n");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
*pipe_info = pipe->info;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_pipe_get_info() leave\n");
return IA_CSS_SUCCESS;
}
bool ia_css_pipe_has_dvs_stats(struct ia_css_pipe_info *pipe_info)
{
unsigned int i;
if (pipe_info != NULL) {
for (i = 0; i < IA_CSS_DVS_STAT_NUM_OF_LEVELS; i++) {
if (pipe_info->grid_info.dvs_grid.dvs_stat_grid_info.grd_cfg[i].grd_start.enable)
return true;
}
}
return false;
}
#ifdef ISP2401
enum ia_css_err
ia_css_pipe_override_frame_format(struct ia_css_pipe *pipe,
int pin_index,
enum ia_css_frame_format new_format)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("pipe = %p, pin_index = %d, new_formats = %d", pipe, pin_index, new_format);
if (NULL == pipe) {
IA_CSS_ERROR("pipe is not set");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (0 != pin_index && 1 != pin_index) {
IA_CSS_ERROR("pin index is not valid");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (IA_CSS_FRAME_FORMAT_NV12_TILEY != new_format) {
IA_CSS_ERROR("new format is not valid");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
} else {
err = ia_css_pipe_check_format(pipe, new_format);
if (IA_CSS_SUCCESS == err) {
if (pin_index == 0) {
pipe->output_info[0].format = new_format;
} else {
pipe->vf_output_info[0].format = new_format;
}
}
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#endif
#if defined(USE_INPUT_SYSTEM_VERSION_2)
static enum ia_css_err
ia_css_stream_configure_rx(struct ia_css_stream *stream)
{
struct ia_css_input_port *config;
assert(stream != NULL);
config = &stream->config.source.port;
if (config->num_lanes == 1)
stream->csi_rx_config.mode = MONO_1L_1L_0L;
else if (config->num_lanes == 2)
stream->csi_rx_config.mode = MONO_2L_1L_0L;
else if (config->num_lanes == 3)
stream->csi_rx_config.mode = MONO_3L_1L_0L;
else if (config->num_lanes == 4)
stream->csi_rx_config.mode = MONO_4L_1L_0L;
else if (config->num_lanes != 0)
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (config->port > IA_CSS_CSI2_PORT2)
return IA_CSS_ERR_INVALID_ARGUMENTS;
stream->csi_rx_config.port =
ia_css_isys_port_to_mipi_port(config->port);
stream->csi_rx_config.timeout = config->timeout;
stream->csi_rx_config.initcount = 0;
stream->csi_rx_config.synccount = 0x28282828;
stream->csi_rx_config.rxcount = config->rxcount;
if (config->compression.type == IA_CSS_CSI2_COMPRESSION_TYPE_NONE)
stream->csi_rx_config.comp = MIPI_PREDICTOR_NONE;
else {
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
stream->csi_rx_config.is_two_ppc = (stream->config.pixels_per_clock == 2);
stream->reconfigure_css_rx = true;
return IA_CSS_SUCCESS;
}
#endif
static struct ia_css_pipe *
find_pipe(struct ia_css_pipe *pipes[],
unsigned int num_pipes,
enum ia_css_pipe_mode mode,
bool copy_pipe)
{
unsigned i;
assert(pipes != NULL);
for (i = 0; i < num_pipes; i++) {
assert(pipes[i] != NULL);
if (pipes[i]->config.mode != mode)
continue;
if (copy_pipe && pipes[i]->mode != IA_CSS_PIPE_ID_COPY)
continue;
return pipes[i];
}
return NULL;
}
static enum ia_css_err
ia_css_acc_stream_create(struct ia_css_stream *stream)
{
int i;
enum ia_css_err err = IA_CSS_SUCCESS;
assert(stream != NULL);
IA_CSS_ENTER_PRIVATE("stream = %p", stream);
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
for (i = 0; i < stream->num_pipes; i++) {
struct ia_css_pipe *pipe = stream->pipes[i];
assert(pipe != NULL);
if (pipe == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe->stream = stream;
}
err = map_sp_threads(stream, true);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
for (i = 0; i < stream->num_pipes; i++) {
struct ia_css_pipe *pipe = stream->pipes[i];
assert(pipe != NULL);
ia_css_pipe_map_queue(pipe, true);
}
err = create_host_pipeline_structure(stream);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
stream->started = false;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
metadata_info_init(const struct ia_css_metadata_config *mdc,
struct ia_css_metadata_info *md)
{
if ((mdc->resolution.height > 0) ^ (mdc->resolution.width > 0))
return IA_CSS_ERR_INVALID_ARGUMENTS;
md->resolution = mdc->resolution;
md->stride = CEIL_MUL(mdc->resolution.width, HIVE_ISP_DDR_WORD_BYTES);
md->size = mdc->resolution.height * md->stride;
return IA_CSS_SUCCESS;
}
#ifdef ISP2401
static enum ia_css_err check_pipe_resolutions(const struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("");
if (!pipe || !pipe->stream) {
IA_CSS_ERROR("null arguments");
err = IA_CSS_ERR_INTERNAL_ERROR;
goto EXIT;
}
if (ia_css_util_check_res(pipe->config.input_effective_res.width,
pipe->config.input_effective_res.height) != IA_CSS_SUCCESS) {
IA_CSS_ERROR("effective resolution not supported");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
if (!ia_css_util_resolution_is_zero(pipe->stream->config.input_config.input_res)) {
if (!ia_css_util_res_leq(pipe->config.input_effective_res,
pipe->stream->config.input_config.input_res)) {
IA_CSS_ERROR("effective resolution is larger than input resolution");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
}
if (!ia_css_util_resolution_is_even(pipe->config.output_info[0].res)) {
IA_CSS_ERROR("output resolution must be even");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
if (!ia_css_util_resolution_is_even(pipe->config.vf_output_info[0].res)) {
IA_CSS_ERROR("VF resolution must be even");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto EXIT;
}
EXIT:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
#endif
enum ia_css_err
ia_css_stream_create(const struct ia_css_stream_config *stream_config,
int num_pipes,
struct ia_css_pipe *pipes[],
struct ia_css_stream **stream)
{
struct ia_css_pipe *curr_pipe;
struct ia_css_stream *curr_stream = NULL;
bool spcopyonly;
bool sensor_binning_changed;
int i, j;
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
struct ia_css_metadata_info md_info;
#ifndef ISP2401
struct ia_css_resolution effective_res;
#else
#ifdef USE_INPUT_SYSTEM_VERSION_2401
bool aspect_ratio_crop_enabled = false;
#endif
#endif
IA_CSS_ENTER("num_pipes=%d", num_pipes);
ia_css_debug_dump_stream_config(stream_config, num_pipes);
if (num_pipes == 0 ||
stream == NULL ||
pipes == NULL) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#if defined(USE_INPUT_SYSTEM_VERSION_2)
if (stream_config->input_config.format == IA_CSS_STREAM_FORMAT_BINARY_8 &&
stream_config->metadata_config.resolution.height > 0) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (stream_config->online && stream_config->pack_raw_pixels) {
IA_CSS_LOG("online and pack raw is invalid on input system 2401");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
ia_css_debug_pipe_graph_dump_stream_config(stream_config);
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR)
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (!stream_config->online)
#endif
{
unsigned int port = (unsigned int) stream_config->source.port.port;
if (port >= N_MIPI_PORT_ID) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
if (my_css.size_mem_words != 0){
my_css.mipi_frame_size[port] = my_css.size_mem_words;
} else if (stream_config->mipi_buffer_config.size_mem_words != 0) {
my_css.mipi_frame_size[port] = stream_config->mipi_buffer_config.size_mem_words;
} else {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_create() exit: error, need to set mipi frame size.\n");
assert(stream_config->mipi_buffer_config.size_mem_words != 0);
err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_LEAVE_ERR(err);
return err;
}
if (my_css.size_mem_words != 0) {
my_css.num_mipi_frames[port] = 2;
} else if (stream_config->mipi_buffer_config.nof_mipi_buffers != 0) {
my_css.num_mipi_frames[port] = stream_config->mipi_buffer_config.nof_mipi_buffers;
} else {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_stream_create() exit: error, need to set number of mipi frames.\n");
assert(stream_config->mipi_buffer_config.nof_mipi_buffers != 0);
err = IA_CSS_ERR_INTERNAL_ERROR;
IA_CSS_LEAVE_ERR(err);
return err;
}
}
#endif
err = metadata_info_init(&stream_config->metadata_config, &md_info);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
curr_stream = kmalloc(sizeof(struct ia_css_stream), GFP_KERNEL);
if (curr_stream == NULL) {
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_LEAVE_ERR(err);
return err;
}
memset(curr_stream, 0, sizeof(struct ia_css_stream));
curr_stream->info.metadata_info = md_info;
curr_stream->num_pipes = num_pipes;
curr_stream->pipes = kzalloc(num_pipes * sizeof(struct ia_css_pipe *), GFP_KERNEL);
if (curr_stream->pipes == NULL) {
curr_stream->num_pipes = 0;
kfree(curr_stream);
curr_stream = NULL;
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_LEAVE_ERR(err);
return err;
}
spcopyonly = (num_pipes == 1) && (pipes[0]->config.mode == IA_CSS_PIPE_MODE_COPY);
for (i = 0; i < num_pipes; i++)
curr_stream->pipes [i] = pipes[i];
curr_stream->last_pipe = curr_stream->pipes[0];
curr_stream->config = *stream_config;
#if defined(USE_INPUT_SYSTEM_VERSION_2401) && defined(CSI2P_DISABLE_ISYS2401_ONLINE_MODE)
if (stream_config->mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR &&
stream_config->online)
curr_stream->config.online = false;
#endif
#ifdef USE_INPUT_SYSTEM_VERSION_2401
if (curr_stream->config.online) {
curr_stream->config.source.port.num_lanes = stream_config->source.port.num_lanes;
curr_stream->config.mode = IA_CSS_INPUT_MODE_BUFFERED_SENSOR;
}
#endif
if (curr_stream->config.target_num_cont_raw_buf == 0)
curr_stream->config.target_num_cont_raw_buf = NUM_CONTINUOUS_FRAMES;
if (curr_stream->config.init_num_cont_raw_buf == 0)
curr_stream->config.init_num_cont_raw_buf = curr_stream->config.target_num_cont_raw_buf;
if (curr_stream->config.ia_css_enable_raw_buffer_locking)
sh_css_sp_configure_enable_raw_pool_locking(
curr_stream->config.lock_all);
switch (curr_stream->config.mode) {
case IA_CSS_INPUT_MODE_SENSOR:
case IA_CSS_INPUT_MODE_BUFFERED_SENSOR:
#if defined(USE_INPUT_SYSTEM_VERSION_2)
ia_css_stream_configure_rx(curr_stream);
#endif
break;
case IA_CSS_INPUT_MODE_TPG:
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2)
IA_CSS_LOG("tpg_configuration: x_mask=%d, y_mask=%d, x_delta=%d, y_delta=%d, xy_mask=%d",
curr_stream->config.source.tpg.x_mask,
curr_stream->config.source.tpg.y_mask,
curr_stream->config.source.tpg.x_delta,
curr_stream->config.source.tpg.y_delta,
curr_stream->config.source.tpg.xy_mask);
sh_css_sp_configure_tpg(
curr_stream->config.source.tpg.x_mask,
curr_stream->config.source.tpg.y_mask,
curr_stream->config.source.tpg.x_delta,
curr_stream->config.source.tpg.y_delta,
curr_stream->config.source.tpg.xy_mask);
#endif
break;
case IA_CSS_INPUT_MODE_PRBS:
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2)
IA_CSS_LOG("mode prbs");
sh_css_sp_configure_prbs(curr_stream->config.source.prbs.seed);
#endif
break;
case IA_CSS_INPUT_MODE_MEMORY:
IA_CSS_LOG("mode memory");
curr_stream->reconfigure_css_rx = false;
break;
default:
IA_CSS_LOG("mode sensor/default");
}
#ifdef ISP2401
#ifdef USE_INPUT_SYSTEM_VERSION_2401
err = aspect_ratio_crop_init(curr_stream,
pipes,
&aspect_ratio_crop_enabled);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
#endif
#endif
for (i = 0; i < num_pipes; i++) {
#ifdef ISP2401
struct ia_css_resolution effective_res;
#endif
curr_pipe = pipes[i];
curr_pipe->stream = curr_stream;
effective_res = curr_pipe->config.input_effective_res;
if (effective_res.height == 0 || effective_res.width == 0) {
effective_res = curr_pipe->stream->config.input_config.effective_res;
#ifdef ISP2401
#if defined(USE_INPUT_SYSTEM_VERSION_2401)
if (aspect_ratio_crop_check(aspect_ratio_crop_enabled, curr_pipe)) {
struct ia_css_resolution crop_res;
err = aspect_ratio_crop(curr_pipe, &crop_res);
if (err == IA_CSS_SUCCESS) {
effective_res = crop_res;
} else {
IA_CSS_LOG("aspect_ratio_crop() failed with err(%d)", err);
}
}
#endif
#endif
curr_pipe->config.input_effective_res = effective_res;
}
IA_CSS_LOG("effective_res=%dx%d",
effective_res.width,
effective_res.height);
}
#ifdef ISP2401
for (i = 0; i < num_pipes; i++) {
if (pipes[i]->config.mode != IA_CSS_PIPE_MODE_ACC &&
pipes[i]->config.mode != IA_CSS_PIPE_MODE_COPY) {
err = check_pipe_resolutions(pipes[i]);
if (err != IA_CSS_SUCCESS) {
goto ERR;
}
}
}
#endif
err = ia_css_stream_isp_parameters_init(curr_stream);
if (err != IA_CSS_SUCCESS)
goto ERR;
IA_CSS_LOG("isp_params_configs: %p", curr_stream->isp_params_configs);
if (num_pipes == 1 && pipes[0]->config.mode == IA_CSS_PIPE_MODE_ACC) {
*stream = curr_stream;
err = ia_css_acc_stream_create(curr_stream);
goto ERR;
}
if (!spcopyonly){
sensor_binning_changed =
sh_css_params_set_binning_factor(curr_stream, curr_stream->config.sensor_binning_factor);
} else {
sensor_binning_changed = false;
}
IA_CSS_LOG("sensor_binning=%d, changed=%d",
curr_stream->config.sensor_binning_factor, sensor_binning_changed);
IA_CSS_LOG("num_pipes=%d", num_pipes);
curr_stream->cont_capt = false;
if (curr_stream->config.continuous) {
struct ia_css_pipe *preview_pipe;
struct ia_css_pipe *video_pipe;
struct ia_css_pipe *acc_pipe;
struct ia_css_pipe *capture_pipe = NULL;
struct ia_css_pipe *copy_pipe = NULL;
if (num_pipes >= 2) {
curr_stream->cont_capt = true;
curr_stream->disable_cont_vf = curr_stream->config.disable_cont_viewfinder;
#ifndef ISP2401
curr_stream->stop_copy_preview = my_css.stop_copy_preview;
#endif
}
preview_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_PREVIEW, false);
video_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_VIDEO, false);
acc_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_ACC, false);
if (acc_pipe && num_pipes == 2 && curr_stream->cont_capt == true)
curr_stream->cont_capt = false;
if (curr_stream->cont_capt == true) {
capture_pipe = find_pipe(pipes, num_pipes,
IA_CSS_PIPE_MODE_CAPTURE, false);
if (capture_pipe == NULL) {
err = IA_CSS_ERR_INTERNAL_ERROR;
goto ERR;
}
}
if (preview_pipe && video_pipe) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto ERR;
}
if (preview_pipe && !preview_pipe->pipe_settings.preview.copy_pipe) {
err = create_pipe(IA_CSS_PIPE_MODE_CAPTURE, &copy_pipe, true);
if (err != IA_CSS_SUCCESS)
goto ERR;
ia_css_pipe_config_defaults(&copy_pipe->config);
preview_pipe->pipe_settings.preview.copy_pipe = copy_pipe;
copy_pipe->stream = curr_stream;
}
if (preview_pipe && (curr_stream->cont_capt == true)) {
preview_pipe->pipe_settings.preview.capture_pipe = capture_pipe;
}
if (video_pipe && !video_pipe->pipe_settings.video.copy_pipe) {
err = create_pipe(IA_CSS_PIPE_MODE_CAPTURE, &copy_pipe, true);
if (err != IA_CSS_SUCCESS)
goto ERR;
ia_css_pipe_config_defaults(&copy_pipe->config);
video_pipe->pipe_settings.video.copy_pipe = copy_pipe;
copy_pipe->stream = curr_stream;
}
if (video_pipe && (curr_stream->cont_capt == true)) {
video_pipe->pipe_settings.video.capture_pipe = capture_pipe;
}
if (preview_pipe && acc_pipe) {
preview_pipe->pipe_settings.preview.acc_pipe = acc_pipe;
}
}
for (i = 0; i < num_pipes; i++) {
curr_pipe = pipes[i];
curr_pipe->stream = curr_stream;
#ifndef ISP2401
effective_res = curr_pipe->config.input_effective_res;
err = ia_css_util_check_res(
effective_res.width,
effective_res.height);
if (err != IA_CSS_SUCCESS)
goto ERR;
#endif
if (sensor_binning_changed)
sh_css_pipe_free_shading_table(curr_pipe);
}
for (i = 0; i < num_pipes; i++) {
struct ia_css_pipe_info *pipe_info = NULL;
curr_pipe = pipes[i];
err = sh_css_pipe_load_binaries(curr_pipe);
if (err != IA_CSS_SUCCESS)
goto ERR;
pipe_info = &curr_pipe->info;
for (j = 0; j < IA_CSS_PIPE_MAX_OUTPUT_STAGE; j++) {
err = sh_css_pipe_get_output_frame_info(curr_pipe,
&pipe_info->output_info[j], j);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
#ifdef ISP2401
pipe_info->output_system_in_res_info = curr_pipe->config.output_system_in_res;
#endif
if (!spcopyonly){
err = sh_css_pipe_get_shading_info(curr_pipe,
#ifndef ISP2401
&pipe_info->shading_info);
#else
&pipe_info->shading_info, &curr_pipe->config);
#endif
if (err != IA_CSS_SUCCESS)
goto ERR;
err = sh_css_pipe_get_grid_info(curr_pipe,
&pipe_info->grid_info);
if (err != IA_CSS_SUCCESS)
goto ERR;
for (j = 0; j < IA_CSS_PIPE_MAX_OUTPUT_STAGE; j++) {
sh_css_pipe_get_viewfinder_frame_info(curr_pipe,
&pipe_info->vf_output_info[j], j);
if (err != IA_CSS_SUCCESS)
goto ERR;
}
}
my_css.active_pipes[ia_css_pipe_get_pipe_num(curr_pipe)] = curr_pipe;
}
enum ia_css_err
ia_css_stream_get_info(const struct ia_css_stream *stream,
struct ia_css_stream_info *stream_info)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_get_info: enter/exit\n");
assert(stream != NULL);
assert(stream_info != NULL);
*stream_info = stream->info;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_stream_load(struct ia_css_stream *stream)
{
#ifndef ISP2401
int i;
enum ia_css_err err;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_load() enter, \n");
for(i=0;i<MAX_ACTIVE_STREAMS;i++)
if (my_css_save.stream_seeds[i].stream == stream)
{
int j;
for(j=0;j<my_css_save.stream_seeds[i].num_pipes;j++)
if ((err = ia_css_pipe_create(&(my_css_save.stream_seeds[i].pipe_config[j]), &my_css_save.stream_seeds[i].pipes[j])) != IA_CSS_SUCCESS)
{
if (j)
{
int k;
for(k=0;k<j;k++)
ia_css_pipe_destroy(my_css_save.stream_seeds[i].pipes[k]);
}
return err;
}
err = ia_css_stream_create(&(my_css_save.stream_seeds[i].stream_config), my_css_save.stream_seeds[i].num_pipes,
my_css_save.stream_seeds[i].pipes, &(my_css_save.stream_seeds[i].stream));
if (err != IA_CSS_SUCCESS)
{
ia_css_stream_destroy(stream);
for(j=0;j<my_css_save.stream_seeds[i].num_pipes;j++)
ia_css_pipe_destroy(my_css_save.stream_seeds[i].pipes[j]);
return err;
}
break;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_load() exit, \n");
return IA_CSS_SUCCESS;
#else
(void)stream;
return IA_CSS_ERR_NOT_SUPPORTED;
#endif
}
enum ia_css_err
ia_css_stream_start(struct ia_css_stream *stream)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("stream = %p", stream);
if ((stream == NULL) || (stream->last_pipe == NULL)) {
IA_CSS_LEAVE_ERR(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
IA_CSS_LOG("starting %d", stream->last_pipe->mode);
sh_css_sp_set_disable_continuous_viewfinder(stream->disable_cont_vf);
err = create_host_pipeline(stream);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR(err);
return err;
}
#if !defined(HAS_NO_INPUT_SYSTEM)
#if defined(USE_INPUT_SYSTEM_VERSION_2401)
if((stream->config.mode == IA_CSS_INPUT_MODE_SENSOR) ||
(stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR))
stream_register_with_csi_rx(stream);
#endif
#endif
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2)
if (stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR)
{
unsigned int idx;
unsigned int port = (unsigned int) (stream->config.source.port.port) ;
for (idx = 0; idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT; idx++) {
sh_css_sp_group.config.mipi_sizes_for_check[port][idx] = sh_css_get_mipi_sizes_for_check(port, idx);
}
}
#endif
#if !defined(HAS_NO_INPUT_SYSTEM)
if (stream->config.mode != IA_CSS_INPUT_MODE_MEMORY) {
err = sh_css_config_input_network(stream);
if (err != IA_CSS_SUCCESS)
return err;
}
#endif
err = sh_css_pipe_start(stream);
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err
ia_css_stream_stop(struct ia_css_stream *stream)
{
enum ia_css_err err = IA_CSS_SUCCESS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_stop() enter/exit\n");
assert(stream != NULL);
assert(stream->last_pipe != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_stop: stopping %d\n",
stream->last_pipe->mode);
#if !defined(HAS_NO_INPUT_SYSTEM) && defined(USE_INPUT_SYSTEM_VERSION_2)
if (stream->config.mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR)
{
unsigned int idx;
unsigned int port = (unsigned int) (stream->config.source.port.port) ;
for (idx = 0; idx < IA_CSS_MIPI_SIZE_CHECK_MAX_NOF_ENTRIES_PER_PORT; idx++) {
sh_css_sp_group.config.mipi_sizes_for_check[port][idx] = 0;
}
}
#endif
#ifndef ISP2401
err = ia_css_pipeline_request_stop(&stream->last_pipe->pipeline);
#else
err = sh_css_pipes_stop(stream);
#endif
if (err != IA_CSS_SUCCESS)
return err;
return err;
}
bool
ia_css_stream_has_stopped(struct ia_css_stream *stream)
{
bool stopped;
assert(stream != NULL);
#ifndef ISP2401
stopped = ia_css_pipeline_has_stopped(&stream->last_pipe->pipeline);
#else
stopped = sh_css_pipes_have_stopped(stream);
#endif
return stopped;
}
enum ia_css_err
ia_css_stream_unload(struct ia_css_stream *stream)
{
int i;
assert(stream != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_unload() enter, \n");
assert (stream != NULL);
for(i=0;i<MAX_ACTIVE_STREAMS;i++)
if (my_css_save.stream_seeds[i].stream == stream)
{
int j;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_unload(): unloading %d (%p)\n", i, my_css_save.stream_seeds[i].stream);
ia_css_stream_destroy(stream);
for(j=0;j<my_css_save.stream_seeds[i].num_pipes;j++)
ia_css_pipe_destroy(my_css_save.stream_seeds[i].pipes[j]);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_unload(): after unloading %d (%p)\n", i, my_css_save.stream_seeds[i].stream);
break;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_stream_unload() exit, \n");
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_temp_pipe_to_pipe_id(const struct ia_css_pipe *pipe, enum ia_css_pipe_id *pipe_id)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "ia_css_temp_pipe_to_pipe_id() enter/exit\n");
if (pipe != NULL)
*pipe_id = pipe->mode;
else
*pipe_id = IA_CSS_PIPE_ID_COPY;
return IA_CSS_SUCCESS;
}
enum ia_css_stream_format
ia_css_stream_get_format(const struct ia_css_stream *stream)
{
return stream->config.input_config.format;
}
bool
ia_css_stream_get_two_pixels_per_clock(const struct ia_css_stream *stream)
{
return (stream->config.pixels_per_clock == 2);
}
struct ia_css_binary *
ia_css_stream_get_shading_correction_binary(const struct ia_css_stream *stream)
{
struct ia_css_pipe *pipe;
assert(stream != NULL);
pipe = stream->pipes[0];
if (stream->num_pipes == 2) {
assert(stream->pipes[1] != NULL);
if (stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_VIDEO ||
stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_PREVIEW)
pipe = stream->pipes[1];
}
return ia_css_pipe_get_shading_correction_binary(pipe);
}
struct ia_css_binary *
ia_css_stream_get_dvs_binary(const struct ia_css_stream *stream)
{
int i;
struct ia_css_pipe *video_pipe = NULL;
for (i=0; i<stream->num_pipes; i++) {
struct ia_css_pipe *pipe = stream->pipes[i];
if (pipe->config.mode == IA_CSS_PIPE_MODE_VIDEO) {
video_pipe = pipe;
break;
}
}
if (video_pipe)
return &video_pipe->pipe_settings.video.video_binary;
return NULL;
}
struct ia_css_binary *
ia_css_stream_get_3a_binary(const struct ia_css_stream *stream)
{
struct ia_css_pipe *pipe;
struct ia_css_binary *s3a_binary = NULL;
assert(stream != NULL);
pipe = stream->pipes[0];
if (stream->num_pipes == 2) {
assert(stream->pipes[1] != NULL);
if (stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_VIDEO ||
stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_PREVIEW)
pipe = stream->pipes[1];
}
s3a_binary = ia_css_pipe_get_s3a_binary(pipe);
return s3a_binary;
}
enum ia_css_err
ia_css_stream_set_output_padded_width(struct ia_css_stream *stream, unsigned int output_padded_width)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_pipe *pipe;
assert(stream != NULL);
pipe = stream->last_pipe;
assert(pipe != NULL);
pipe->config.output_info[IA_CSS_PIPE_OUTPUT_STAGE_0].padded_width = output_padded_width;
pipe->output_info[IA_CSS_PIPE_OUTPUT_STAGE_0].padded_width = output_padded_width;
return err;
}
static struct ia_css_binary *
ia_css_pipe_get_shading_correction_binary(const struct ia_css_pipe *pipe)
{
struct ia_css_binary *binary = NULL;
assert(pipe != NULL);
switch (pipe->config.mode) {
case IA_CSS_PIPE_MODE_PREVIEW:
binary = (struct ia_css_binary *)&pipe->pipe_settings.preview.preview_binary;
break;
case IA_CSS_PIPE_MODE_VIDEO:
binary = (struct ia_css_binary *)&pipe->pipe_settings.video.video_binary;
break;
case IA_CSS_PIPE_MODE_CAPTURE:
if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_PRIMARY) {
unsigned int i;
for (i = 0; i < pipe->pipe_settings.capture.num_primary_stage; i++) {
if (pipe->pipe_settings.capture.primary_binary[i].info->sp.enable.sc) {
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.primary_binary[i];
break;
}
}
}
else if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.pre_isp_binary;
else if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_ADVANCED ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_LOW_LIGHT) {
if (pipe->config.isp_pipe_version == IA_CSS_PIPE_VERSION_1)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.pre_isp_binary;
else if (pipe->config.isp_pipe_version == IA_CSS_PIPE_VERSION_2_2)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.post_isp_binary;
}
break;
default:
break;
}
if (binary && binary->info->sp.enable.sc)
return binary;
return NULL;
}
static struct ia_css_binary *
ia_css_pipe_get_s3a_binary(const struct ia_css_pipe *pipe)
{
struct ia_css_binary *binary = NULL;
assert(pipe != NULL);
switch (pipe->config.mode) {
case IA_CSS_PIPE_MODE_PREVIEW:
binary = (struct ia_css_binary*)&pipe->pipe_settings.preview.preview_binary;
break;
case IA_CSS_PIPE_MODE_VIDEO:
binary = (struct ia_css_binary*)&pipe->pipe_settings.video.video_binary;
break;
case IA_CSS_PIPE_MODE_CAPTURE:
if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_PRIMARY) {
unsigned int i;
for (i = 0; i < pipe->pipe_settings.capture.num_primary_stage; i++) {
if (pipe->pipe_settings.capture.primary_binary[i].info->sp.enable.s3a) {
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.primary_binary[i];
break;
}
}
}
else if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.pre_isp_binary;
else if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_ADVANCED ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_LOW_LIGHT) {
if (pipe->config.isp_pipe_version == IA_CSS_PIPE_VERSION_1)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.pre_isp_binary;
else if (pipe->config.isp_pipe_version == IA_CSS_PIPE_VERSION_2_2)
binary = (struct ia_css_binary *)&pipe->pipe_settings.capture.post_isp_binary;
else
assert(0);
}
break;
default:
break;
}
if (binary && !binary->info->sp.enable.s3a)
binary = NULL;
return binary;
}
static struct ia_css_binary *
ia_css_pipe_get_sdis_binary(const struct ia_css_pipe *pipe)
{
struct ia_css_binary *binary = NULL;
assert(pipe != NULL);
switch (pipe->config.mode) {
case IA_CSS_PIPE_MODE_VIDEO:
binary = (struct ia_css_binary*)&pipe->pipe_settings.video.video_binary;
break;
default:
break;
}
if (binary && !binary->info->sp.enable.dis)
binary = NULL;
return binary;
}
struct ia_css_pipeline *
ia_css_pipe_get_pipeline(const struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
return (struct ia_css_pipeline*)&pipe->pipeline;
}
unsigned int
ia_css_pipe_get_pipe_num(const struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
assert(pipe->pipe_num < IA_CSS_PIPELINE_NUM_MAX);
if (pipe->pipe_num >= IA_CSS_PIPELINE_NUM_MAX)
return (IA_CSS_PIPELINE_NUM_MAX - 1);
return pipe->pipe_num;
}
unsigned int
ia_css_pipe_get_isp_pipe_version(const struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
return (unsigned int)pipe->config.isp_pipe_version;
}
enum ia_css_err
ia_css_start_sp(void)
{
unsigned long timeout;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("");
sh_css_sp_start_isp();
timeout = SP_START_TIMEOUT_US;
while((ia_css_spctrl_get_state(SP0_ID) != IA_CSS_SP_SW_INITIALIZED) && timeout) {
timeout--;
hrt_sleep();
}
if (timeout == 0) {
IA_CSS_ERROR("timeout during SP initialization");
return IA_CSS_ERR_INTERNAL_ERROR;
}
sh_css_init_host_sp_control_vars();
sh_css_setup_queues();
ia_css_bufq_dump_queue_info();
#ifdef ISP2401
if (ia_css_is_system_mode_suspend_or_resume() == false) {
ia_css_set_system_mode(IA_CSS_SYS_MODE_WORKING);
}
#endif
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err
ia_css_stop_sp(void)
{
unsigned long timeout;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("void");
if (!sh_css_sp_is_running()) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE("SP already stopped : return_err=%d", err);
return err;
}
#ifndef ISP2401
sh_css_write_host2sp_command(host2sp_cmd_terminate);
#else
if (!sh_css_write_host2sp_command(host2sp_cmd_terminate)) {
IA_CSS_ERROR("Call to 'sh-css_write_host2sp_command()' failed");
ia_css_debug_dump_sp_sw_debug_info();
ia_css_debug_dump_debug_info(NULL);
}
#endif
sh_css_sp_set_sp_running(false);
timeout = SP_SHUTDOWN_TIMEOUT_US;
while (!ia_css_spctrl_is_idle(SP0_ID) && timeout) {
timeout--;
hrt_sleep();
}
if ((ia_css_spctrl_get_state(SP0_ID) != IA_CSS_SP_SW_TERMINATED))
IA_CSS_WARNING("SP has not terminated (SW)");
if (timeout == 0) {
IA_CSS_WARNING("SP is not idle");
ia_css_debug_dump_sp_sw_debug_info();
}
timeout = SP_SHUTDOWN_TIMEOUT_US;
while (!isp_ctrl_getbit(ISP0_ID, ISP_SC_REG, ISP_IDLE_BIT) && timeout) {
timeout--;
hrt_sleep();
}
if (timeout == 0) {
IA_CSS_WARNING("ISP is not idle");
ia_css_debug_dump_sp_sw_debug_info();
}
sh_css_hmm_buffer_record_uninit();
#ifndef ISP2401
sh_css_param_clear_param_sets();
#else
if (ia_css_is_system_mode_suspend_or_resume() == false) {
sh_css_param_clear_param_sets();
ia_css_set_system_mode(IA_CSS_SYS_MODE_INIT);
}
#endif
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err
ia_css_update_continuous_frames(struct ia_css_stream *stream)
{
struct ia_css_pipe *pipe;
unsigned int i;
ia_css_debug_dtrace(
IA_CSS_DEBUG_TRACE,
"sh_css_update_continuous_frames() enter:\n");
if (stream == NULL) {
ia_css_debug_dtrace(
IA_CSS_DEBUG_TRACE,
"sh_css_update_continuous_frames() leave: invalid stream, return_void\n");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
pipe = stream->continuous_pipe;
for (i = stream->config.init_num_cont_raw_buf;
i < stream->config.target_num_cont_raw_buf; i++) {
sh_css_update_host2sp_offline_frame(i,
pipe->continuous_frames[i], pipe->cont_md_buffers[i]);
}
sh_css_update_host2sp_cont_num_raw_frames
(stream->config.target_num_cont_raw_buf, true);
ia_css_debug_dtrace(
IA_CSS_DEBUG_TRACE,
"sh_css_update_continuous_frames() leave: return_void\n");
return IA_CSS_SUCCESS;
}
void ia_css_pipe_map_queue(struct ia_css_pipe *pipe, bool map)
{
unsigned int thread_id;
enum ia_css_pipe_id pipe_id;
unsigned int pipe_num;
bool need_input_queue;
IA_CSS_ENTER("");
assert(pipe != NULL);
pipe_id = pipe->mode;
pipe_num = pipe->pipe_num;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
#if defined(HAS_NO_INPUT_SYSTEM) || defined(USE_INPUT_SYSTEM_VERSION_2401)
need_input_queue = true;
#else
need_input_queue = pipe->stream->config.mode == IA_CSS_INPUT_MODE_MEMORY;
#endif
if (pipe->mode == IA_CSS_PIPE_ID_PREVIEW) {
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PARAMETER_SET, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PER_FRAME_PARAMETER_SET, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
if (pipe->pipe_settings.preview.preview_binary.info &&
pipe->pipe_settings.preview.preview_binary.info->sp.enable.s3a)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_3A_STATISTICS, map);
} else if (pipe->mode == IA_CSS_PIPE_ID_CAPTURE) {
unsigned int i;
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PARAMETER_SET, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PER_FRAME_PARAMETER_SET, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_PRIMARY) {
for (i = 0; i < pipe->pipe_settings.capture.num_primary_stage; i++) {
if (pipe->pipe_settings.capture.primary_binary[i].info &&
pipe->pipe_settings.capture.primary_binary[i].info->sp.enable.s3a) {
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_3A_STATISTICS, map);
break;
}
}
} else if (pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_ADVANCED ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_LOW_LIGHT ||
pipe->config.default_capture_config.mode == IA_CSS_CAPTURE_MODE_BAYER) {
if (pipe->pipe_settings.capture.pre_isp_binary.info &&
pipe->pipe_settings.capture.pre_isp_binary.info->sp.enable.s3a)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_3A_STATISTICS, map);
}
} else if (pipe->mode == IA_CSS_PIPE_ID_VIDEO) {
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, map);
if (pipe->enable_viewfinder[IA_CSS_PIPE_OUTPUT_STAGE_0])
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PARAMETER_SET, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PER_FRAME_PARAMETER_SET, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
if (pipe->pipe_settings.video.video_binary.info &&
pipe->pipe_settings.video.video_binary.info->sp.enable.s3a)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_3A_STATISTICS, map);
if (pipe->pipe_settings.video.video_binary.info &&
(pipe->pipe_settings.video.video_binary.info->sp.enable.dis
))
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_DIS_STATISTICS, map);
} else if (pipe->mode == IA_CSS_PIPE_ID_COPY) {
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
if (!pipe->stream->config.continuous)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
} else if (pipe->mode == IA_CSS_PIPE_ID_ACC) {
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PARAMETER_SET, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PER_FRAME_PARAMETER_SET, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
} else if (pipe->mode == IA_CSS_PIPE_ID_YUVPP) {
unsigned int idx;
for (idx = 0; idx < IA_CSS_PIPE_MAX_OUTPUT_STAGE; idx++) {
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_OUTPUT_FRAME + idx, map);
if (pipe->enable_viewfinder[idx])
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_VF_OUTPUT_FRAME + idx, map);
}
if (need_input_queue)
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_INPUT_FRAME, map);
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_PARAMETER_SET, map);
#if defined SH_CSS_ENABLE_METADATA
ia_css_queue_map(thread_id, IA_CSS_BUFFER_TYPE_METADATA, map);
#endif
}
IA_CSS_LEAVE("");
}
static enum ia_css_err set_config_on_frame_enqueue(struct ia_css_frame_info *info, struct frame_data_wrapper *frame)
{
frame->config_on_frame_enqueue.padded_width = 0;
switch (info->format) {
case IA_CSS_FRAME_FORMAT_YUV420:
case IA_CSS_FRAME_FORMAT_NV12:
if (info->padded_width > info->res.width)
{
frame->config_on_frame_enqueue.padded_width = info->padded_width;
}
else if ((info->padded_width < info->res.width) && (info->padded_width > 0))
{
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
break;
default:
break;
}
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_unlock_raw_frame(struct ia_css_stream *stream, uint32_t exp_id)
{
enum ia_css_err ret;
IA_CSS_ENTER("");
if (stream == NULL || !stream->config.continuous) {
IA_CSS_ERROR("invalid stream pointer");
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
if (exp_id > IA_CSS_ISYS_MAX_EXPOSURE_ID ||
exp_id < IA_CSS_ISYS_MIN_EXPOSURE_ID) {
IA_CSS_ERROR("invalid expsure ID: %d\n", exp_id);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
ret = ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_UNLOCK_RAW_BUFFER, exp_id, 0, 0);
IA_CSS_LEAVE_ERR(ret);
return ret;
}
enum ia_css_err
ia_css_pipe_set_qos_ext_state(struct ia_css_pipe *pipe, uint32_t fw_handle, bool enable)
{
unsigned int thread_id;
struct ia_css_pipeline_stage *stage;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("");
if (pipe == NULL || pipe->stream == NULL) {
IA_CSS_ERROR("Invalid Pipe.");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!(pipe->config.acc_extension)) {
IA_CSS_ERROR("Invalid Pipe(No Extension Firmware)");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!sh_css_sp_is_running()) {
IA_CSS_ERROR("Leaving: queue unavailable.");
err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
} else {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
err = ia_css_pipeline_get_stage_from_fw(&(pipe->pipeline), fw_handle, &stage);
if (err == IA_CSS_SUCCESS) {
err = ia_css_bufq_enqueue_psys_event(
(uint8_t) IA_CSS_PSYS_SW_EVENT_STAGE_ENABLE_DISABLE,
(uint8_t) thread_id,
(uint8_t) stage->stage_num,
(enable == true) ? 1 : 0);
if (err == IA_CSS_SUCCESS) {
if(enable)
SH_CSS_QOS_STAGE_ENABLE(&(sh_css_sp_group.pipe[thread_id]),stage->stage_num);
else
SH_CSS_QOS_STAGE_DISABLE(&(sh_css_sp_group.pipe[thread_id]),stage->stage_num);
}
}
}
IA_CSS_LEAVE("err:%d handle:%u enable:%d", err, fw_handle, enable);
return err;
}
enum ia_css_err
ia_css_pipe_get_qos_ext_state(struct ia_css_pipe *pipe, uint32_t fw_handle, bool *enable)
{
struct ia_css_pipeline_stage *stage;
unsigned int thread_id;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("");
if (pipe == NULL || pipe->stream == NULL) {
IA_CSS_ERROR("Invalid Pipe.");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!(pipe->config.acc_extension)) {
IA_CSS_ERROR("Invalid Pipe (No Extension Firmware).");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!sh_css_sp_is_running()) {
IA_CSS_ERROR("Leaving: queue unavailable.");
err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
} else {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
err = ia_css_pipeline_get_stage_from_fw(&pipe->pipeline, fw_handle, &stage);
if (err == IA_CSS_SUCCESS) {
*enable = (SH_CSS_QOS_STAGE_IS_ENABLED(&(sh_css_sp_group.pipe[thread_id]),stage->stage_num)) ? true : false;
}
}
IA_CSS_LEAVE("err:%d handle:%u enable:%d", err, fw_handle, *enable);
return err;
}
enum ia_css_err
ia_css_pipe_update_qos_ext_mapped_arg(struct ia_css_pipe *pipe, uint32_t fw_handle,
struct ia_css_isp_param_css_segments *css_seg, struct ia_css_isp_param_isp_segments *isp_seg)
{
unsigned int HIVE_ADDR_sp_group;
static struct sh_css_sp_group sp_group;
static struct sh_css_sp_stage sp_stage;
static struct sh_css_isp_stage isp_stage;
const struct ia_css_fw_info *fw;
unsigned int thread_id;
struct ia_css_pipeline_stage *stage;
enum ia_css_err err = IA_CSS_SUCCESS;
int stage_num = 0;
enum ia_css_isp_memories mem;
bool enabled;
IA_CSS_ENTER("");
fw = &sh_css_sp_fw;
if (pipe == NULL || pipe->stream == NULL) {
IA_CSS_ERROR("Invalid Pipe.");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!(pipe->config.acc_extension)) {
IA_CSS_ERROR("Invalid Pipe (No Extension Firmware).");
err = IA_CSS_ERR_INVALID_ARGUMENTS;
} else if (!sh_css_sp_is_running()) {
IA_CSS_ERROR("Leaving: queue unavailable.");
err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
} else {
ia_css_pipeline_get_sp_thread_id(ia_css_pipe_get_pipe_num(pipe), &thread_id);
err = ia_css_pipeline_get_stage_from_fw(&(pipe->pipeline), fw_handle, &stage);
if (err == IA_CSS_SUCCESS) {
enabled = (SH_CSS_QOS_STAGE_IS_ENABLED(&(sh_css_sp_group.pipe[thread_id]), stage->stage_num)) ? true : false;
if (enabled) {
IA_CSS_ERROR("Leaving: cannot update when stage is enabled.");
err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
} else {
stage_num = stage->stage_num;
HIVE_ADDR_sp_group = fw->info.sp.group;
sp_dmem_load(SP0_ID,
(unsigned int)sp_address_of(sp_group),
&sp_group, sizeof(struct sh_css_sp_group));
mmgr_load(sp_group.pipe[thread_id].sp_stage_addr[stage_num],
&sp_stage, sizeof(struct sh_css_sp_stage));
mmgr_load(sp_stage.isp_stage_addr,
&isp_stage, sizeof(struct sh_css_isp_stage));
for (mem = 0; mem < N_IA_CSS_ISP_MEMORIES; mem++) {
isp_stage.mem_initializers.params[IA_CSS_PARAM_CLASS_PARAM][mem].address =
css_seg->params[IA_CSS_PARAM_CLASS_PARAM][mem].address;
isp_stage.mem_initializers.params[IA_CSS_PARAM_CLASS_PARAM][mem].size =
css_seg->params[IA_CSS_PARAM_CLASS_PARAM][mem].size;
isp_stage.binary_info.mem_initializers.params[IA_CSS_PARAM_CLASS_PARAM][mem].address =
isp_seg->params[IA_CSS_PARAM_CLASS_PARAM][mem].address;
isp_stage.binary_info.mem_initializers.params[IA_CSS_PARAM_CLASS_PARAM][mem].size =
isp_seg->params[IA_CSS_PARAM_CLASS_PARAM][mem].size;
}
mmgr_store(sp_stage.isp_stage_addr,
&isp_stage, sizeof(struct sh_css_isp_stage));
}
}
}
IA_CSS_LEAVE("err:%d handle:%u", err, fw_handle);
return err;
}
static enum ia_css_err
aspect_ratio_crop_init(struct ia_css_stream *curr_stream,
struct ia_css_pipe *pipes[],
bool *do_crop_status)
{
enum ia_css_err err = IA_CSS_SUCCESS;
int i;
struct ia_css_pipe *curr_pipe;
uint32_t pipe_mask = 0;
if ((curr_stream == NULL) ||
(curr_stream->num_pipes == 0) ||
(pipes == NULL) ||
(do_crop_status == NULL)) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
for (i = 0; i < curr_stream->num_pipes; i++) {
curr_pipe = pipes[i];
pipe_mask |= (1 << curr_pipe->config.mode);
}
*do_crop_status =
(((pipe_mask & (1 << IA_CSS_PIPE_MODE_PREVIEW)) ||
(pipe_mask & (1 << IA_CSS_PIPE_MODE_VIDEO))) &&
(pipe_mask & (1 << IA_CSS_PIPE_MODE_CAPTURE)) &&
curr_stream->config.continuous);
return IA_CSS_SUCCESS;
}
static bool
aspect_ratio_crop_check(bool enabled, struct ia_css_pipe *curr_pipe)
{
bool status = false;
if ((curr_pipe != NULL) && enabled) {
if ((curr_pipe->config.mode == IA_CSS_PIPE_MODE_PREVIEW) ||
(curr_pipe->config.mode == IA_CSS_PIPE_MODE_VIDEO) ||
(curr_pipe->config.mode == IA_CSS_PIPE_MODE_CAPTURE))
status = true;
}
return status;
}
static enum ia_css_err
aspect_ratio_crop(struct ia_css_pipe *curr_pipe,
struct ia_css_resolution *effective_res)
{
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_resolution crop_res;
struct ia_css_resolution *in_res = NULL;
struct ia_css_resolution *out_res = NULL;
bool use_bds_output_info = false;
bool use_vf_pp_in_res = false;
bool use_capt_pp_in_res = false;
if ((curr_pipe == NULL) ||
(effective_res == NULL)) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
if ((curr_pipe->config.mode != IA_CSS_PIPE_MODE_PREVIEW) &&
(curr_pipe->config.mode != IA_CSS_PIPE_MODE_VIDEO) &&
(curr_pipe->config.mode != IA_CSS_PIPE_MODE_CAPTURE)) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_LEAVE_ERR(err);
return err;
}
use_bds_output_info =
((curr_pipe->bds_output_info.res.width != 0) &&
(curr_pipe->bds_output_info.res.height != 0));
use_vf_pp_in_res =
((curr_pipe->config.vf_pp_in_res.width != 0) &&
(curr_pipe->config.vf_pp_in_res.height != 0));
use_capt_pp_in_res =
((curr_pipe->config.capt_pp_in_res.width != 0) &&
(curr_pipe->config.capt_pp_in_res.height != 0));
in_res = &curr_pipe->stream->config.input_config.effective_res;
out_res = &curr_pipe->output_info[0].res;
switch (curr_pipe->config.mode) {
case IA_CSS_PIPE_MODE_PREVIEW:
if (use_bds_output_info)
out_res = &curr_pipe->bds_output_info.res;
else if (use_vf_pp_in_res)
out_res = &curr_pipe->config.vf_pp_in_res;
break;
case IA_CSS_PIPE_MODE_VIDEO:
if (use_bds_output_info)
out_res = &curr_pipe->bds_output_info.res;
break;
case IA_CSS_PIPE_MODE_CAPTURE:
if (use_capt_pp_in_res)
out_res = &curr_pipe->config.capt_pp_in_res;
break;
case IA_CSS_PIPE_MODE_ACC:
case IA_CSS_PIPE_MODE_COPY:
case IA_CSS_PIPE_MODE_YUVPP:
default:
IA_CSS_ERROR("aspect ratio cropping invalid args: mode[%d]\n",
curr_pipe->config.mode);
assert(0);
break;
}
err = ia_css_frame_find_crop_resolution(in_res, out_res, &crop_res);
if (err == IA_CSS_SUCCESS) {
*effective_res = crop_res;
} else {
IA_CSS_LOG("ia_css_frame_find_crop_resolution() failed with err(%d)", err);
}
return err;
}
static void
sh_css_hmm_buffer_record_reset(struct sh_css_hmm_buffer_record *buffer_record)
{
assert(buffer_record != NULL);
buffer_record->in_use = false;
buffer_record->type = IA_CSS_BUFFER_TYPE_INVALID;
buffer_record->h_vbuf = NULL;
buffer_record->kernel_ptr = 0;
}
static struct sh_css_hmm_buffer_record
*sh_css_hmm_buffer_record_acquire(struct ia_css_rmgr_vbuf_handle *h_vbuf,
enum ia_css_buffer_type type,
hrt_address kernel_ptr)
{
int i;
struct sh_css_hmm_buffer_record *buffer_record = NULL;
struct sh_css_hmm_buffer_record *out_buffer_record = NULL;
assert(h_vbuf != NULL);
assert((type > IA_CSS_BUFFER_TYPE_INVALID) && (type < IA_CSS_NUM_DYNAMIC_BUFFER_TYPE));
assert(kernel_ptr != 0);
buffer_record = &hmm_buffer_record[0];
for (i = 0; i < MAX_HMM_BUFFER_NUM; i++) {
if (buffer_record->in_use == false) {
buffer_record->in_use = true;
buffer_record->type = type;
buffer_record->h_vbuf = h_vbuf;
buffer_record->kernel_ptr = kernel_ptr;
out_buffer_record = buffer_record;
break;
}
buffer_record++;
}
return out_buffer_record;
}
static struct sh_css_hmm_buffer_record
*sh_css_hmm_buffer_record_validate(hrt_vaddress ddr_buffer_addr,
enum ia_css_buffer_type type)
{
int i;
struct sh_css_hmm_buffer_record *buffer_record = NULL;
bool found_record = false;
buffer_record = &hmm_buffer_record[0];
for (i = 0; i < MAX_HMM_BUFFER_NUM; i++) {
if ((buffer_record->in_use == true) &&
(buffer_record->type == type) &&
(buffer_record->h_vbuf != NULL) &&
(buffer_record->h_vbuf->vptr == ddr_buffer_addr)) {
found_record = true;
break;
}
buffer_record++;
}
if (found_record == true)
return buffer_record;
else
return NULL;
}
