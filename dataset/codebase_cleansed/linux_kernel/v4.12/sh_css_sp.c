void
store_sp_group_data(void)
{
per_frame_data.sp_group_addr = sh_css_store_sp_group_to_ddr();
}
static void
copy_isp_stage_to_sp_stage(void)
{
sh_css_sp_stage.num_stripes = (uint8_t) sh_css_isp_stage.binary_info.iterator.num_stripes;
sh_css_sp_stage.row_stripes_height = (uint16_t) sh_css_isp_stage.binary_info.iterator.row_stripes_height;
sh_css_sp_stage.row_stripes_overlap_lines = (uint16_t) sh_css_isp_stage.binary_info.iterator.row_stripes_overlap_lines;
sh_css_sp_stage.top_cropping = (uint16_t) sh_css_isp_stage.binary_info.pipeline.top_cropping;
sh_css_sp_stage.enable.sdis = sh_css_isp_stage.binary_info.enable.dis;
sh_css_sp_stage.enable.s3a = sh_css_isp_stage.binary_info.enable.s3a;
#ifdef ISP2401
sh_css_sp_stage.enable.lace_stats = sh_css_isp_stage.binary_info.enable.lace_stats;
#endif
}
void
store_sp_stage_data(enum ia_css_pipe_id id, unsigned int pipe_num, unsigned stage)
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
copy_isp_stage_to_sp_stage();
if (id != IA_CSS_PIPE_ID_COPY)
sh_css_sp_stage.isp_stage_addr =
sh_css_store_isp_stage_to_ddr(pipe_num, stage);
sh_css_sp_group.pipe[thread_id].sp_stage_addr[stage] =
sh_css_store_sp_stage_to_ddr(pipe_num, stage);
sh_css_sp_stage.program_input_circuit = false;
}
static void
store_sp_per_frame_data(const struct ia_css_fw_info *fw)
{
unsigned int HIVE_ADDR_sp_per_frame_data = 0;
assert(fw != NULL);
switch (fw->type) {
case ia_css_sp_firmware:
HIVE_ADDR_sp_per_frame_data = fw->info.sp.per_frame_data;
break;
case ia_css_acc_firmware:
HIVE_ADDR_sp_per_frame_data = fw->info.acc.per_frame_data;
break;
case ia_css_isp_firmware:
return;
}
sp_dmem_store(SP0_ID,
(unsigned int)sp_address_of(sp_per_frame_data),
&per_frame_data,
sizeof(per_frame_data));
}
static void
sh_css_store_sp_per_frame_data(enum ia_css_pipe_id pipe_id,
unsigned int pipe_num,
const struct ia_css_fw_info *sp_fw)
{
if (!sp_fw)
sp_fw = &sh_css_sp_fw;
store_sp_stage_data(pipe_id, pipe_num, 0);
store_sp_group_data();
store_sp_per_frame_data(sp_fw);
}
void
sh_css_sp_get_debug_state(struct sh_css_sp_debug_state *state)
{
const struct ia_css_fw_info *fw = &sh_css_sp_fw;
unsigned int HIVE_ADDR_sp_output = fw->info.sp.output;
unsigned i;
unsigned offset = (unsigned int)offsetof(struct sh_css_sp_output, debug)/sizeof(int);
assert(state != NULL);
(void)HIVE_ADDR_sp_output;
for (i = 0; i < sizeof(*state)/sizeof(int); i++)
((unsigned *)state)[i] = load_sp_array_uint(sp_output, i+offset);
}
void
sh_css_sp_start_binary_copy(unsigned int pipe_num, struct ia_css_frame *out_frame,
unsigned two_ppc)
{
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
struct sh_css_sp_pipeline *pipe;
uint8_t stage_num = 0;
assert(out_frame != NULL);
pipe_id = IA_CSS_PIPE_ID_CAPTURE;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
pipe = &sh_css_sp_group.pipe[thread_id];
pipe->copy.bin.bytes_available = out_frame->data_bytes;
pipe->num_stages = 1;
pipe->pipe_id = pipe_id;
pipe->pipe_num = pipe_num;
pipe->thread_id = thread_id;
pipe->pipe_config = 0x0;
pipe->pipe_qos_config = QOS_INVALID;
if (pipe->inout_port_config == 0) {
SH_CSS_PIPE_PORT_CONFIG_SET(pipe->inout_port_config,
(uint8_t)SH_CSS_PORT_INPUT,
(uint8_t)SH_CSS_HOST_TYPE, 1);
SH_CSS_PIPE_PORT_CONFIG_SET(pipe->inout_port_config,
(uint8_t)SH_CSS_PORT_OUTPUT,
(uint8_t)SH_CSS_HOST_TYPE, 1);
}
IA_CSS_LOG("pipe_id %d port_config %08x",
pipe->pipe_id, pipe->inout_port_config);
#if !defined(HAS_NO_INPUT_FORMATTER)
sh_css_sp_group.config.input_formatter.isp_2ppc = (uint8_t)two_ppc;
#else
(void)two_ppc;
#endif
sh_css_sp_stage.num = stage_num;
sh_css_sp_stage.stage_type = SH_CSS_SP_STAGE_TYPE;
sh_css_sp_stage.func =
(unsigned int)IA_CSS_PIPELINE_BIN_COPY;
set_output_frame_buffer(out_frame, 0);
sh_css_store_sp_per_frame_data(pipe_id, pipe_num, &sh_css_sp_fw);
}
static void
sh_css_sp_start_raw_copy(struct ia_css_frame *out_frame,
unsigned pipe_num,
unsigned two_ppc,
unsigned max_input_width,
enum sh_css_pipe_config_override pipe_conf_override,
unsigned int if_config_index)
{
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
uint8_t stage_num = 0;
struct sh_css_sp_pipeline *pipe;
assert(out_frame != NULL);
{
uint8_t program_input_circuit;
program_input_circuit = sh_css_sp_stage.program_input_circuit;
memset(&sh_css_sp_stage, 0, sizeof(sh_css_sp_stage));
sh_css_sp_stage.program_input_circuit = program_input_circuit;
}
pipe_id = IA_CSS_PIPE_ID_COPY;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
pipe = &sh_css_sp_group.pipe[thread_id];
pipe->copy.raw.height = out_frame->info.res.height;
pipe->copy.raw.width = out_frame->info.res.width;
pipe->copy.raw.padded_width = out_frame->info.padded_width;
pipe->copy.raw.raw_bit_depth = out_frame->info.raw_bit_depth;
pipe->copy.raw.max_input_width = max_input_width;
pipe->num_stages = 1;
pipe->pipe_id = pipe_id;
if (pipe_conf_override == SH_CSS_PIPE_CONFIG_OVRD_NO_OVRD)
pipe->pipe_config =
(SH_CSS_PIPE_CONFIG_SAMPLE_PARAMS << thread_id);
else
pipe->pipe_config = pipe_conf_override;
pipe->pipe_qos_config = QOS_INVALID;
if (pipe->inout_port_config == 0) {
SH_CSS_PIPE_PORT_CONFIG_SET(pipe->inout_port_config,
(uint8_t)SH_CSS_PORT_INPUT,
(uint8_t)SH_CSS_HOST_TYPE, 1);
SH_CSS_PIPE_PORT_CONFIG_SET(pipe->inout_port_config,
(uint8_t)SH_CSS_PORT_OUTPUT,
(uint8_t)SH_CSS_HOST_TYPE, 1);
}
IA_CSS_LOG("pipe_id %d port_config %08x",
pipe->pipe_id, pipe->inout_port_config);
#if !defined(HAS_NO_INPUT_FORMATTER)
sh_css_sp_group.config.input_formatter.isp_2ppc = (uint8_t)two_ppc;
#else
(void)two_ppc;
#endif
sh_css_sp_stage.num = stage_num;
sh_css_sp_stage.xmem_bin_addr = 0x0;
sh_css_sp_stage.stage_type = SH_CSS_SP_STAGE_TYPE;
sh_css_sp_stage.func = (unsigned int)IA_CSS_PIPELINE_RAW_COPY;
sh_css_sp_stage.if_config_index = (uint8_t) if_config_index;
set_output_frame_buffer(out_frame, 0);
ia_css_debug_pipe_graph_dump_sp_raw_copy(out_frame);
}
static void
sh_css_sp_start_isys_copy(struct ia_css_frame *out_frame,
unsigned pipe_num, unsigned max_input_width, unsigned int if_config_index)
{
enum ia_css_pipe_id pipe_id;
unsigned int thread_id;
uint8_t stage_num = 0;
struct sh_css_sp_pipeline *pipe;
#if defined SH_CSS_ENABLE_METADATA
enum sh_css_queue_id queue_id;
#endif
assert(out_frame != NULL);
{
uint8_t program_input_circuit;
program_input_circuit = sh_css_sp_stage.program_input_circuit;
memset(&sh_css_sp_stage, 0, sizeof(sh_css_sp_stage));
sh_css_sp_stage.program_input_circuit = program_input_circuit;
}
pipe_id = IA_CSS_PIPE_ID_COPY;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
pipe = &sh_css_sp_group.pipe[thread_id];
pipe->copy.raw.height = out_frame->info.res.height;
pipe->copy.raw.width = out_frame->info.res.width;
pipe->copy.raw.padded_width = out_frame->info.padded_width;
pipe->copy.raw.raw_bit_depth = out_frame->info.raw_bit_depth;
pipe->copy.raw.max_input_width = max_input_width;
pipe->num_stages = 1;
pipe->pipe_id = pipe_id;
pipe->pipe_config = 0x0;
pipe->pipe_qos_config = QOS_INVALID;
initialize_stage_frames(&sh_css_sp_stage.frames);
sh_css_sp_stage.num = stage_num;
sh_css_sp_stage.xmem_bin_addr = 0x0;
sh_css_sp_stage.stage_type = SH_CSS_SP_STAGE_TYPE;
sh_css_sp_stage.func = (unsigned int)IA_CSS_PIPELINE_ISYS_COPY;
sh_css_sp_stage.if_config_index = (uint8_t) if_config_index;
set_output_frame_buffer(out_frame, 0);
#if defined SH_CSS_ENABLE_METADATA
if (pipe->metadata.height > 0) {
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_METADATA, thread_id, &queue_id);
sh_css_copy_buffer_attr_to_spbuffer(&sh_css_sp_stage.frames.metadata_buf, queue_id, mmgr_EXCEPTION, IA_CSS_BUFFER_TYPE_METADATA);
}
#endif
ia_css_debug_pipe_graph_dump_sp_raw_copy(out_frame);
}
unsigned int
sh_css_sp_get_binary_copy_size(void)
{
const struct ia_css_fw_info *fw = &sh_css_sp_fw;
unsigned int HIVE_ADDR_sp_output = fw->info.sp.output;
unsigned int offset = (unsigned int)offsetof(struct sh_css_sp_output,
bin_copy_bytes_copied) / sizeof(int);
(void)HIVE_ADDR_sp_output;
return load_sp_array_uint(sp_output, offset);
}
unsigned int
sh_css_sp_get_sw_interrupt_value(unsigned int irq)
{
const struct ia_css_fw_info *fw = &sh_css_sp_fw;
unsigned int HIVE_ADDR_sp_output = fw->info.sp.output;
unsigned int offset = (unsigned int)offsetof(struct sh_css_sp_output, sw_interrupt_value)
/ sizeof(int);
(void)HIVE_ADDR_sp_output;
return load_sp_array_uint(sp_output, offset+irq);
}
static void
sh_css_copy_buffer_attr_to_spbuffer(struct ia_css_buffer_sp *dest_buf,
const enum sh_css_queue_id queue_id,
const hrt_vaddress xmem_addr,
const enum ia_css_buffer_type buf_type)
{
assert(buf_type < IA_CSS_NUM_BUFFER_TYPE);
if (queue_id > SH_CSS_INVALID_QUEUE_ID) {
assert(queue_id < SH_CSS_MAX_NUM_QUEUES);
if ((queue_id < SH_CSS_MAX_NUM_QUEUES))
{
dest_buf->buf_src.queue_id = queue_id;
}
} else {
assert(xmem_addr != mmgr_EXCEPTION);
dest_buf->buf_src.xmem_addr = xmem_addr;
}
dest_buf->buf_type = buf_type;
}
static void
sh_css_copy_frame_to_spframe(struct ia_css_frame_sp *sp_frame_out,
const struct ia_css_frame *frame_in)
{
assert(frame_in != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE,
"sh_css_copy_frame_to_spframe():\n");
sh_css_copy_buffer_attr_to_spbuffer(&sp_frame_out->buf_attr,
frame_in->dynamic_queue_id,
frame_in->data,
frame_in->buf_type);
ia_css_frame_info_to_frame_sp_info(&sp_frame_out->info, &frame_in->info);
switch (frame_in->info.format) {
case IA_CSS_FRAME_FORMAT_RAW_PACKED:
case IA_CSS_FRAME_FORMAT_RAW:
sp_frame_out->planes.raw.offset = frame_in->planes.raw.offset;
break;
case IA_CSS_FRAME_FORMAT_RGB565:
case IA_CSS_FRAME_FORMAT_RGBA888:
sp_frame_out->planes.rgb.offset = frame_in->planes.rgb.offset;
break;
case IA_CSS_FRAME_FORMAT_PLANAR_RGB888:
sp_frame_out->planes.planar_rgb.r.offset =
frame_in->planes.planar_rgb.r.offset;
sp_frame_out->planes.planar_rgb.g.offset =
frame_in->planes.planar_rgb.g.offset;
sp_frame_out->planes.planar_rgb.b.offset =
frame_in->planes.planar_rgb.b.offset;
break;
case IA_CSS_FRAME_FORMAT_YUYV:
case IA_CSS_FRAME_FORMAT_UYVY:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8:
case IA_CSS_FRAME_FORMAT_YUV_LINE:
sp_frame_out->planes.yuyv.offset = frame_in->planes.yuyv.offset;
break;
case IA_CSS_FRAME_FORMAT_NV11:
case IA_CSS_FRAME_FORMAT_NV12:
case IA_CSS_FRAME_FORMAT_NV12_16:
case IA_CSS_FRAME_FORMAT_NV12_TILEY:
case IA_CSS_FRAME_FORMAT_NV21:
case IA_CSS_FRAME_FORMAT_NV16:
case IA_CSS_FRAME_FORMAT_NV61:
sp_frame_out->planes.nv.y.offset =
frame_in->planes.nv.y.offset;
sp_frame_out->planes.nv.uv.offset =
frame_in->planes.nv.uv.offset;
break;
case IA_CSS_FRAME_FORMAT_YUV420:
case IA_CSS_FRAME_FORMAT_YUV422:
case IA_CSS_FRAME_FORMAT_YUV444:
case IA_CSS_FRAME_FORMAT_YUV420_16:
case IA_CSS_FRAME_FORMAT_YUV422_16:
case IA_CSS_FRAME_FORMAT_YV12:
case IA_CSS_FRAME_FORMAT_YV16:
sp_frame_out->planes.yuv.y.offset =
frame_in->planes.yuv.y.offset;
sp_frame_out->planes.yuv.u.offset =
frame_in->planes.yuv.u.offset;
sp_frame_out->planes.yuv.v.offset =
frame_in->planes.yuv.v.offset;
break;
case IA_CSS_FRAME_FORMAT_QPLANE6:
sp_frame_out->planes.plane6.r.offset =
frame_in->planes.plane6.r.offset;
sp_frame_out->planes.plane6.r_at_b.offset =
frame_in->planes.plane6.r_at_b.offset;
sp_frame_out->planes.plane6.gr.offset =
frame_in->planes.plane6.gr.offset;
sp_frame_out->planes.plane6.gb.offset =
frame_in->planes.plane6.gb.offset;
sp_frame_out->planes.plane6.b.offset =
frame_in->planes.plane6.b.offset;
sp_frame_out->planes.plane6.b_at_r.offset =
frame_in->planes.plane6.b_at_r.offset;
break;
case IA_CSS_FRAME_FORMAT_BINARY_8:
sp_frame_out->planes.binary.data.offset =
frame_in->planes.binary.data.offset;
break;
default:
memset(&sp_frame_out->planes, 0, sizeof(sp_frame_out->planes));
break;
}
}
static enum ia_css_err
set_input_frame_buffer(const struct ia_css_frame *frame)
{
if (frame == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
switch (frame->info.format) {
case IA_CSS_FRAME_FORMAT_QPLANE6:
case IA_CSS_FRAME_FORMAT_YUV420_16:
case IA_CSS_FRAME_FORMAT_RAW_PACKED:
case IA_CSS_FRAME_FORMAT_RAW:
case IA_CSS_FRAME_FORMAT_YUV420:
case IA_CSS_FRAME_FORMAT_YUYV:
case IA_CSS_FRAME_FORMAT_YUV_LINE:
case IA_CSS_FRAME_FORMAT_NV12:
case IA_CSS_FRAME_FORMAT_NV12_16:
case IA_CSS_FRAME_FORMAT_NV12_TILEY:
case IA_CSS_FRAME_FORMAT_NV21:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_10:
break;
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
sh_css_copy_frame_to_spframe(&sh_css_sp_stage.frames.in, frame);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
set_output_frame_buffer(const struct ia_css_frame *frame,
unsigned idx)
{
if (frame == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
switch (frame->info.format) {
case IA_CSS_FRAME_FORMAT_YUV420:
case IA_CSS_FRAME_FORMAT_YUV422:
case IA_CSS_FRAME_FORMAT_YUV444:
case IA_CSS_FRAME_FORMAT_YV12:
case IA_CSS_FRAME_FORMAT_YV16:
case IA_CSS_FRAME_FORMAT_YUV420_16:
case IA_CSS_FRAME_FORMAT_YUV422_16:
case IA_CSS_FRAME_FORMAT_NV11:
case IA_CSS_FRAME_FORMAT_NV12:
case IA_CSS_FRAME_FORMAT_NV12_16:
case IA_CSS_FRAME_FORMAT_NV12_TILEY:
case IA_CSS_FRAME_FORMAT_NV16:
case IA_CSS_FRAME_FORMAT_NV21:
case IA_CSS_FRAME_FORMAT_NV61:
case IA_CSS_FRAME_FORMAT_YUYV:
case IA_CSS_FRAME_FORMAT_UYVY:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8:
case IA_CSS_FRAME_FORMAT_YUV_LINE:
case IA_CSS_FRAME_FORMAT_RGB565:
case IA_CSS_FRAME_FORMAT_RGBA888:
case IA_CSS_FRAME_FORMAT_PLANAR_RGB888:
case IA_CSS_FRAME_FORMAT_RAW:
case IA_CSS_FRAME_FORMAT_RAW_PACKED:
case IA_CSS_FRAME_FORMAT_QPLANE6:
case IA_CSS_FRAME_FORMAT_BINARY_8:
break;
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
sh_css_copy_frame_to_spframe(&sh_css_sp_stage.frames.out[idx], frame);
return IA_CSS_SUCCESS;
}
static enum ia_css_err
set_view_finder_buffer(const struct ia_css_frame *frame)
{
if (frame == NULL)
return IA_CSS_ERR_INVALID_ARGUMENTS;
switch (frame->info.format) {
case IA_CSS_FRAME_FORMAT_NV12:
case IA_CSS_FRAME_FORMAT_NV12_16:
case IA_CSS_FRAME_FORMAT_NV21:
case IA_CSS_FRAME_FORMAT_YUYV:
case IA_CSS_FRAME_FORMAT_UYVY:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8:
case IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8:
case IA_CSS_FRAME_FORMAT_YUV420:
case IA_CSS_FRAME_FORMAT_YV12:
case IA_CSS_FRAME_FORMAT_NV12_TILEY:
case IA_CSS_FRAME_FORMAT_YUV_LINE:
break;
default:
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
sh_css_copy_frame_to_spframe(&sh_css_sp_stage.frames.out_vf, frame);
return IA_CSS_SUCCESS;
}
void sh_css_sp_set_if_configs(
const input_formatter_cfg_t *config_a,
const input_formatter_cfg_t *config_b,
const uint8_t if_config_index
)
{
assert(if_config_index < SH_CSS_MAX_IF_CONFIGS);
assert(config_a != NULL);
sh_css_sp_group.config.input_formatter.set[if_config_index].config_a = *config_a;
sh_css_sp_group.config.input_formatter.a_changed = true;
if (config_b != NULL) {
sh_css_sp_group.config.input_formatter.set[if_config_index].config_b = *config_b;
sh_css_sp_group.config.input_formatter.b_changed = true;
}
return;
}
void
sh_css_sp_program_input_circuit(int fmt_type,
int ch_id,
enum ia_css_input_mode input_mode)
{
sh_css_sp_group.config.input_circuit.no_side_band = false;
sh_css_sp_group.config.input_circuit.fmt_type = fmt_type;
sh_css_sp_group.config.input_circuit.ch_id = ch_id;
sh_css_sp_group.config.input_circuit.input_mode = input_mode;
sh_css_sp_group.config.input_circuit_cfg_changed = true;
sh_css_sp_stage.program_input_circuit = true;
}
void
sh_css_sp_configure_sync_gen(int width, int height,
int hblank_cycles,
int vblank_cycles)
{
sh_css_sp_group.config.sync_gen.width = width;
sh_css_sp_group.config.sync_gen.height = height;
sh_css_sp_group.config.sync_gen.hblank_cycles = hblank_cycles;
sh_css_sp_group.config.sync_gen.vblank_cycles = vblank_cycles;
}
void
sh_css_sp_configure_tpg(int x_mask,
int y_mask,
int x_delta,
int y_delta,
int xy_mask)
{
sh_css_sp_group.config.tpg.x_mask = x_mask;
sh_css_sp_group.config.tpg.y_mask = y_mask;
sh_css_sp_group.config.tpg.x_delta = x_delta;
sh_css_sp_group.config.tpg.y_delta = y_delta;
sh_css_sp_group.config.tpg.xy_mask = xy_mask;
}
void
sh_css_sp_configure_prbs(int seed)
{
sh_css_sp_group.config.prbs.seed = seed;
}
void
sh_css_sp_configure_enable_raw_pool_locking(bool lock_all)
{
sh_css_sp_group.config.enable_raw_pool_locking = true;
sh_css_sp_group.config.lock_all = lock_all;
}
void
sh_css_sp_enable_isys_event_queue(bool enable)
{
#if !defined(HAS_NO_INPUT_SYSTEM)
sh_css_sp_group.config.enable_isys_event_queue = enable;
#else
(void)enable;
#endif
}
void
sh_css_sp_set_disable_continuous_viewfinder(bool flag)
{
sh_css_sp_group.config.disable_cont_vf = flag;
}
static enum ia_css_err
sh_css_sp_write_frame_pointers(const struct sh_css_binary_args *args)
{
enum ia_css_err err = IA_CSS_SUCCESS;
int i;
assert(args != NULL);
if (args->in_frame)
err = set_input_frame_buffer(args->in_frame);
if (err == IA_CSS_SUCCESS && args->out_vf_frame)
err = set_view_finder_buffer(args->out_vf_frame);
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
if (err == IA_CSS_SUCCESS && args->out_frame[i])
err = set_output_frame_buffer(args->out_frame[i], i);
}
if (err != IA_CSS_SUCCESS) assert(false);
return err;
}
static void
sh_css_sp_init_group(bool two_ppc,
enum ia_css_stream_format input_format,
bool no_isp_sync,
uint8_t if_config_index)
{
#if !defined(HAS_NO_INPUT_FORMATTER)
sh_css_sp_group.config.input_formatter.isp_2ppc = two_ppc;
#else
(void)two_ppc;
#endif
sh_css_sp_group.config.no_isp_sync = (uint8_t)no_isp_sync;
if (if_config_index == SH_CSS_IF_CONFIG_NOT_NEEDED) return;
#if !defined(HAS_NO_INPUT_FORMATTER)
assert(if_config_index < SH_CSS_MAX_IF_CONFIGS);
sh_css_sp_group.config.input_formatter.set[if_config_index].stream_format = input_format;
#else
(void)input_format;
#endif
}
void
sh_css_stage_write_binary_info(struct ia_css_binary_info *info)
{
assert(info != NULL);
sh_css_isp_stage.binary_info = *info;
}
static enum ia_css_err
copy_isp_mem_if_to_ddr(struct ia_css_binary *binary)
{
enum ia_css_err err;
err = ia_css_isp_param_copy_isp_mem_if_to_ddr(
&binary->css_params,
&binary->mem_params,
IA_CSS_PARAM_CLASS_CONFIG);
if (err != IA_CSS_SUCCESS)
return err;
err = ia_css_isp_param_copy_isp_mem_if_to_ddr(
&binary->css_params,
&binary->mem_params,
IA_CSS_PARAM_CLASS_STATE);
if (err != IA_CSS_SUCCESS)
return err;
return IA_CSS_SUCCESS;
}
static bool
is_sp_stage(struct ia_css_pipeline_stage *stage)
{
assert(stage != NULL);
return stage->sp_func != IA_CSS_PIPELINE_NO_FUNC;
}
static enum ia_css_err
configure_isp_from_args(
const struct sh_css_sp_pipeline *pipeline,
const struct ia_css_binary *binary,
const struct sh_css_binary_args *args,
bool two_ppc,
bool deinterleaved)
{
enum ia_css_err err = IA_CSS_SUCCESS;
#ifdef ISP2401
struct ia_css_pipe *pipe = find_pipe_by_num(pipeline->pipe_num);
const struct ia_css_resolution *res;
#endif
ia_css_fpn_configure(binary, &binary->in_frame_info);
ia_css_crop_configure(binary, &args->delay_frames[0]->info);
ia_css_qplane_configure(pipeline, binary, &binary->in_frame_info);
ia_css_output0_configure(binary, &args->out_frame[0]->info);
ia_css_output1_configure(binary, &args->out_vf_frame->info);
ia_css_copy_output_configure(binary, args->copy_output);
ia_css_output0_configure(binary, &args->out_frame[0]->info);
#ifdef ISP2401
ia_css_sc_configure(binary, pipeline->shading.internal_frame_origin_x_bqs_on_sctbl,
pipeline->shading.internal_frame_origin_y_bqs_on_sctbl);
#endif
ia_css_iterator_configure(binary, &args->in_frame->info);
ia_css_dvs_configure(binary, &args->out_frame[0]->info);
ia_css_output_configure(binary, &args->out_frame[0]->info);
ia_css_raw_configure(pipeline, binary, &args->in_frame->info, &binary->in_frame_info, two_ppc, deinterleaved);
ia_css_ref_configure(binary, (const struct ia_css_frame **)args->delay_frames, pipeline->dvs_frame_delay);
ia_css_tnr_configure(binary, (const struct ia_css_frame **)args->tnr_frames);
ia_css_bayer_io_config(binary, args);
return err;
}
static void
initialize_isp_states(const struct ia_css_binary *binary)
{
unsigned int i;
if (!binary->info->mem_offsets.offsets.state)
return;
for (i = 0; i < IA_CSS_NUM_STATE_IDS; i++) {
ia_css_kernel_init_state[i](binary);
}
}
static void
initialize_frame_buffer_attribute(struct ia_css_buffer_sp *buf_attr)
{
buf_attr->buf_src.queue_id = SH_CSS_INVALID_QUEUE_ID;
buf_attr->buf_type = IA_CSS_BUFFER_TYPE_INVALID;
}
static void
initialize_stage_frames(struct ia_css_frames_sp *frames)
{
unsigned int i;
initialize_frame_buffer_attribute(&frames->in.buf_attr);
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
initialize_frame_buffer_attribute(&frames->out[i].buf_attr);
}
initialize_frame_buffer_attribute(&frames->out_vf.buf_attr);
initialize_frame_buffer_attribute(&frames->s3a_buf);
initialize_frame_buffer_attribute(&frames->dvs_buf);
#if defined SH_CSS_ENABLE_METADATA
initialize_frame_buffer_attribute(&frames->metadata_buf);
#endif
}
static enum ia_css_err
sp_init_stage(struct ia_css_pipeline_stage *stage,
unsigned int pipe_num,
bool xnr,
unsigned int if_config_index,
bool two_ppc)
{
struct ia_css_binary *binary;
const struct ia_css_fw_info *firmware;
const struct sh_css_binary_args *args;
unsigned stage_num;
const char *binary_name = "";
const struct ia_css_binary_xinfo *info = NULL;
static struct ia_css_binary tmp_binary;
const struct ia_css_blob_info *blob_info = NULL;
struct ia_css_isp_param_css_segments isp_mem_if;
struct ia_css_isp_param_css_segments *mem_if = &isp_mem_if;
enum ia_css_err err = IA_CSS_SUCCESS;
assert(stage != NULL);
binary = stage->binary;
firmware = stage->firmware;
args = &stage->args;
stage_num = stage->stage_num;
if (binary) {
info = binary->info;
binary_name = (const char *)(info->blob->name);
blob_info = &info->blob->header.blob;
ia_css_init_memory_interface(mem_if, &binary->mem_params, &binary->css_params);
} else if (firmware) {
const struct ia_css_frame_info *out_infos[IA_CSS_BINARY_MAX_OUTPUT_PORTS] = {NULL};
if (args->out_frame[0])
out_infos[0] = &args->out_frame[0]->info;
info = &firmware->info.isp;
ia_css_binary_fill_info(info, false, false,
IA_CSS_STREAM_FORMAT_RAW_10,
args->in_frame ? &args->in_frame->info : NULL,
NULL,
out_infos,
args->out_vf_frame ? &args->out_vf_frame->info
: NULL,
&tmp_binary,
NULL,
-1, true);
binary = &tmp_binary;
binary->info = info;
binary_name = IA_CSS_EXT_ISP_PROG_NAME(firmware);
blob_info = &firmware->blob;
mem_if = (struct ia_css_isp_param_css_segments *)&firmware->mem_initializers;
} else {
assert(stage->sp_func != IA_CSS_PIPELINE_NO_FUNC);
return IA_CSS_ERR_INTERNAL_ERROR;
}
err = sh_css_sp_init_stage(binary,
(const char *)binary_name,
blob_info,
args,
pipe_num,
stage_num,
xnr,
mem_if,
if_config_index,
two_ppc);
return err;
}
static void
sp_init_sp_stage(struct ia_css_pipeline_stage *stage,
unsigned pipe_num,
bool two_ppc,
enum sh_css_pipe_config_override copy_ovrd,
unsigned int if_config_index)
{
const struct sh_css_binary_args *args = &stage->args;
assert(stage != NULL);
switch (stage->sp_func) {
case IA_CSS_PIPELINE_RAW_COPY:
sh_css_sp_start_raw_copy(args->out_frame[0],
pipe_num, two_ppc,
stage->max_input_width,
copy_ovrd, if_config_index);
break;
case IA_CSS_PIPELINE_BIN_COPY:
assert(false);
case IA_CSS_PIPELINE_ISYS_COPY:
sh_css_sp_start_isys_copy(args->out_frame[0],
pipe_num, stage->max_input_width, if_config_index);
break;
case IA_CSS_PIPELINE_NO_FUNC:
assert(false);
}
}
void
sh_css_sp_init_pipeline(struct ia_css_pipeline *me,
enum ia_css_pipe_id id,
uint8_t pipe_num,
bool xnr,
bool two_ppc,
bool continuous,
bool offline,
unsigned int required_bds_factor,
enum sh_css_pipe_config_override copy_ovrd,
enum ia_css_input_mode input_mode,
const struct ia_css_metadata_config *md_config,
const struct ia_css_metadata_info *md_info,
#if !defined(HAS_NO_INPUT_SYSTEM)
const mipi_port_ID_t port_id
#endif
#ifdef ISP2401
,
const struct ia_css_coordinate *internal_frame_origin_bqs_on_sctbl,
const struct ia_css_isp_parameters *params
#endif
)
{
struct ia_css_pipeline_stage *stage = NULL;
struct ia_css_binary *first_binary = NULL;
struct ia_css_pipe *pipe = NULL;
unsigned num;
enum ia_css_pipe_id pipe_id = id;
unsigned int thread_id;
uint8_t if_config_index, tmp_if_config_index;
assert(me != NULL);
#if !defined(HAS_NO_INPUT_SYSTEM)
assert(me->stages != NULL);
first_binary = me->stages->binary;
if (input_mode == IA_CSS_INPUT_MODE_SENSOR ||
input_mode == IA_CSS_INPUT_MODE_BUFFERED_SENSOR) {
assert(port_id < N_MIPI_PORT_ID);
if (port_id >= N_MIPI_PORT_ID)
return;
if_config_index = (uint8_t) (port_id - MIPI_PORT0_ID);
} else if (input_mode == IA_CSS_INPUT_MODE_MEMORY) {
if_config_index = SH_CSS_IF_CONFIG_NOT_NEEDED;
} else {
if_config_index = 0x0;
}
#else
(void)input_mode;
if_config_index = SH_CSS_IF_CONFIG_NOT_NEEDED;
#endif
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
memset(&sh_css_sp_group.pipe[thread_id], 0, sizeof(struct sh_css_sp_pipeline));
for (stage = me->stages, num = 0; stage; stage = stage->next, num++) {
stage->stage_num = num;
ia_css_debug_pipe_graph_dump_stage(stage, id);
}
me->num_stages = num;
if (first_binary != NULL) {
sh_css_sp_init_group(two_ppc, first_binary->input_format,
offline, if_config_index);
}
#if defined(USE_INPUT_SYSTEM_VERSION_2401) || defined(USE_INPUT_SYSTEM_VERSION_2)
if ((me->num_stages == 1) && me->stages &&
(me->stages->sp_func == IA_CSS_PIPELINE_ISYS_COPY))
sh_css_sp_group.config.no_isp_sync = true;
#endif
sh_css_init_host2sp_frame_data();
sh_css_sp_group.pipe[thread_id].num_stages = 0;
sh_css_sp_group.pipe[thread_id].pipe_id = pipe_id;
sh_css_sp_group.pipe[thread_id].thread_id = thread_id;
sh_css_sp_group.pipe[thread_id].pipe_num = pipe_num;
sh_css_sp_group.pipe[thread_id].num_execs = me->num_execs;
sh_css_sp_group.pipe[thread_id].pipe_qos_config = me->pipe_qos_config;
sh_css_sp_group.pipe[thread_id].required_bds_factor = required_bds_factor;
#if !defined(HAS_NO_INPUT_SYSTEM)
sh_css_sp_group.pipe[thread_id].input_system_mode
= (uint32_t)input_mode;
sh_css_sp_group.pipe[thread_id].port_id = port_id;
#endif
sh_css_sp_group.pipe[thread_id].dvs_frame_delay = (uint32_t)me->dvs_frame_delay;
if (ia_css_pipeline_uses_params(me)) {
sh_css_sp_group.pipe[thread_id].pipe_config =
SH_CSS_PIPE_CONFIG_SAMPLE_PARAMS << thread_id;
}
if (continuous)
sh_css_sp_group.pipe[thread_id].pipe_config = 0;
sh_css_sp_group.pipe[thread_id].inout_port_config = me->inout_port_config;
pipe = find_pipe_by_num(pipe_num);
assert(pipe != NULL);
if (pipe == NULL) {
return;
}
sh_css_sp_group.pipe[thread_id].scaler_pp_lut = sh_css_pipe_get_pp_gdc_lut(pipe);
#if defined(SH_CSS_ENABLE_METADATA)
if (md_info != NULL && md_info->size > 0) {
sh_css_sp_group.pipe[thread_id].metadata.width = md_info->resolution.width;
sh_css_sp_group.pipe[thread_id].metadata.height = md_info->resolution.height;
sh_css_sp_group.pipe[thread_id].metadata.stride = md_info->stride;
sh_css_sp_group.pipe[thread_id].metadata.size = md_info->size;
ia_css_isys_convert_stream_format_to_mipi_format(
md_config->data_type, MIPI_PREDICTOR_NONE,
&sh_css_sp_group.pipe[thread_id].metadata.format);
}
#else
(void)md_config;
(void)md_info;
#endif
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
sh_css_sp_group.pipe[thread_id].output_frame_queue_id = (uint32_t)SH_CSS_INVALID_QUEUE_ID;
if (IA_CSS_PIPE_ID_COPY != pipe_id) {
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_OUTPUT_FRAME, thread_id, (enum sh_css_queue_id *)(&sh_css_sp_group.pipe[thread_id].output_frame_queue_id));
}
#endif
#ifdef ISP2401
if (internal_frame_origin_bqs_on_sctbl != NULL &&
params != NULL && params->shading_settings.enable_shading_table_conversion == 0) {
sh_css_sp_group.pipe[thread_id].shading.internal_frame_origin_x_bqs_on_sctbl
= (uint32_t)internal_frame_origin_bqs_on_sctbl->x;
sh_css_sp_group.pipe[thread_id].shading.internal_frame_origin_y_bqs_on_sctbl
= (uint32_t)internal_frame_origin_bqs_on_sctbl->y;
} else {
sh_css_sp_group.pipe[thread_id].shading.internal_frame_origin_x_bqs_on_sctbl = 0;
sh_css_sp_group.pipe[thread_id].shading.internal_frame_origin_y_bqs_on_sctbl = 0;
}
#endif
IA_CSS_LOG("pipe_id %d port_config %08x",
pipe_id, sh_css_sp_group.pipe[thread_id].inout_port_config);
for (stage = me->stages, num = 0; stage; stage = stage->next, num++) {
sh_css_sp_group.pipe[thread_id].num_stages++;
if (is_sp_stage(stage)) {
sp_init_sp_stage(stage, pipe_num, two_ppc,
copy_ovrd, if_config_index);
} else {
if ((stage->stage_num != 0) || SH_CSS_PIPE_PORT_CONFIG_IS_CONTINUOUS(me->inout_port_config))
tmp_if_config_index = SH_CSS_IF_CONFIG_NOT_NEEDED;
else
tmp_if_config_index = if_config_index;
sp_init_stage(stage, pipe_num,
xnr, tmp_if_config_index, two_ppc);
}
store_sp_stage_data(pipe_id, pipe_num, num);
}
sh_css_sp_group.pipe[thread_id].pipe_config |= (uint32_t)
(me->acquire_isp_each_stage << IA_CSS_ACQUIRE_ISP_POS);
store_sp_group_data();
}
void
sh_css_sp_uninit_pipeline(unsigned int pipe_num)
{
unsigned int thread_id;
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
sh_css_sp_group.pipe[thread_id].num_stages = 0;
}
bool sh_css_write_host2sp_command(enum host2sp_commands host2sp_command)
{
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
unsigned int offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_command)
/ sizeof(int);
enum host2sp_commands last_cmd = host2sp_cmd_error;
(void)HIVE_ADDR_host_sp_com;
last_cmd = load_sp_array_uint(host_sp_com, offset);
if (last_cmd != host2sp_cmd_ready)
IA_CSS_ERROR("last host command not handled by SP(%d)", last_cmd);
store_sp_array_uint(host_sp_com, offset, host2sp_command);
return (last_cmd == host2sp_cmd_ready);
}
enum host2sp_commands
sh_css_read_host2sp_command(void)
{
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
unsigned int offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_command)
/ sizeof(int);
(void)HIVE_ADDR_host_sp_com;
return (enum host2sp_commands)load_sp_array_uint(host_sp_com, offset);
}
void
sh_css_init_host2sp_frame_data(void)
{
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
(void)HIVE_ADDR_host_sp_com;
}
void
sh_css_update_host2sp_offline_frame(
unsigned frame_num,
struct ia_css_frame *frame,
struct ia_css_metadata *metadata)
{
unsigned int HIVE_ADDR_host_sp_com;
unsigned int offset;
(void)HIVE_ADDR_host_sp_com;
assert(frame_num < NUM_CONTINUOUS_FRAMES);
HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_offline_frames)
/ sizeof(int);
offset += frame_num;
store_sp_array_uint(host_sp_com, offset, frame ? frame->data : 0);
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_offline_metadata)
/ sizeof(int);
offset += frame_num;
store_sp_array_uint(host_sp_com, offset, metadata ? metadata->address : 0);
}
void
sh_css_update_host2sp_mipi_frame(
unsigned frame_num,
struct ia_css_frame *frame)
{
unsigned int HIVE_ADDR_host_sp_com;
unsigned int offset;
(void)HIVE_ADDR_host_sp_com;
assert(frame_num < (N_CSI_PORTS * NUM_MIPI_FRAMES_PER_STREAM));
HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_mipi_frames)
/ sizeof(int);
offset += frame_num;
store_sp_array_uint(host_sp_com, offset,
frame ? frame->data : 0);
}
void
sh_css_update_host2sp_mipi_metadata(
unsigned frame_num,
struct ia_css_metadata *metadata)
{
unsigned int HIVE_ADDR_host_sp_com;
unsigned int o;
(void)HIVE_ADDR_host_sp_com;
assert(frame_num < (N_CSI_PORTS * NUM_MIPI_FRAMES_PER_STREAM));
HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
o = offsetof(struct host_sp_communication, host2sp_mipi_metadata)
/ sizeof(int);
o += frame_num;
store_sp_array_uint(host_sp_com, o,
metadata ? metadata->address : 0);
}
void
sh_css_update_host2sp_num_mipi_frames(unsigned num_frames)
{
unsigned int HIVE_ADDR_host_sp_com;
unsigned int offset;
(void)HIVE_ADDR_host_sp_com;
HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_num_mipi_frames)
/ sizeof(int);
store_sp_array_uint(host_sp_com, offset, num_frames);
}
void
sh_css_update_host2sp_cont_num_raw_frames(unsigned num_frames, bool set_avail)
{
const struct ia_css_fw_info *fw;
unsigned int HIVE_ADDR_host_sp_com;
unsigned int extra_num_frames, avail_num_frames;
unsigned int offset, offset_extra;
(void)HIVE_ADDR_host_sp_com;
fw = &sh_css_sp_fw;
HIVE_ADDR_host_sp_com = fw->info.sp.host_sp_com;
if (set_avail) {
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_cont_avail_num_raw_frames)
/ sizeof(int);
avail_num_frames = load_sp_array_uint(host_sp_com, offset);
extra_num_frames = num_frames - avail_num_frames;
offset_extra = (unsigned int)offsetof(struct host_sp_communication, host2sp_cont_extra_num_raw_frames)
/ sizeof(int);
store_sp_array_uint(host_sp_com, offset_extra, extra_num_frames);
} else
offset = (unsigned int)offsetof(struct host_sp_communication, host2sp_cont_target_num_raw_frames)
/ sizeof(int);
store_sp_array_uint(host_sp_com, offset, num_frames);
}
void
sh_css_event_init_irq_mask(void)
{
int i;
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
unsigned int offset;
struct sh_css_event_irq_mask event_irq_mask_init;
event_irq_mask_init.or_mask = IA_CSS_EVENT_TYPE_ALL;
event_irq_mask_init.and_mask = IA_CSS_EVENT_TYPE_NONE;
(void)HIVE_ADDR_host_sp_com;
assert(sizeof(event_irq_mask_init) % HRT_BUS_BYTES == 0);
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
offset = (unsigned int)offsetof(struct host_sp_communication,
host2sp_event_irq_mask[i]);
assert(offset % HRT_BUS_BYTES == 0);
sp_dmem_store(SP0_ID,
(unsigned int)sp_address_of(host_sp_com) + offset,
&event_irq_mask_init, sizeof(event_irq_mask_init));
}
}
enum ia_css_err
ia_css_pipe_set_irq_mask(struct ia_css_pipe *pipe,
unsigned int or_mask,
unsigned int and_mask)
{
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
unsigned int offset;
struct sh_css_event_irq_mask event_irq_mask;
unsigned int pipe_num;
assert(pipe != NULL);
assert(IA_CSS_PIPE_ID_NUM == NR_OF_PIPELINES);
#ifndef __KERNEL__
assert(or_mask <= UINT16_MAX);
assert(and_mask <= UINT16_MAX);
#endif
(void)HIVE_ADDR_host_sp_com;
IA_CSS_LOG("or_mask=%x, and_mask=%x", or_mask, and_mask);
event_irq_mask.or_mask = (uint16_t)or_mask;
event_irq_mask.and_mask = (uint16_t)and_mask;
pipe_num = ia_css_pipe_get_pipe_num(pipe);
if (pipe_num >= IA_CSS_PIPE_ID_NUM)
return IA_CSS_ERR_INTERNAL_ERROR;
offset = (unsigned int)offsetof(struct host_sp_communication,
host2sp_event_irq_mask[pipe_num]);
assert(offset % HRT_BUS_BYTES == 0);
sp_dmem_store(SP0_ID,
(unsigned int)sp_address_of(host_sp_com) + offset,
&event_irq_mask, sizeof(event_irq_mask));
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_event_get_irq_mask(const struct ia_css_pipe *pipe,
unsigned int *or_mask,
unsigned int *and_mask)
{
unsigned int HIVE_ADDR_host_sp_com = sh_css_sp_fw.info.sp.host_sp_com;
unsigned int offset;
struct sh_css_event_irq_mask event_irq_mask;
unsigned int pipe_num;
(void)HIVE_ADDR_host_sp_com;
IA_CSS_ENTER_LEAVE("");
assert(pipe != NULL);
assert(IA_CSS_PIPE_ID_NUM == NR_OF_PIPELINES);
pipe_num = ia_css_pipe_get_pipe_num(pipe);
if (pipe_num >= IA_CSS_PIPE_ID_NUM)
return IA_CSS_ERR_INTERNAL_ERROR;
offset = (unsigned int)offsetof(struct host_sp_communication,
host2sp_event_irq_mask[pipe_num]);
assert(offset % HRT_BUS_BYTES == 0);
sp_dmem_load(SP0_ID,
(unsigned int)sp_address_of(host_sp_com) + offset,
&event_irq_mask, sizeof(event_irq_mask));
if (or_mask)
*or_mask = event_irq_mask.or_mask;
if (and_mask)
*and_mask = event_irq_mask.and_mask;
return IA_CSS_SUCCESS;
}
void
sh_css_sp_set_sp_running(bool flag)
{
sp_running = flag;
}
bool
sh_css_sp_is_running(void)
{
return sp_running;
}
void
sh_css_sp_start_isp(void)
{
const struct ia_css_fw_info *fw;
unsigned int HIVE_ADDR_sp_sw_state;
fw = &sh_css_sp_fw;
HIVE_ADDR_sp_sw_state = fw->info.sp.sw_state;
if (sp_running)
return;
(void)HIVE_ADDR_sp_sw_state;
store_sp_group_data();
store_sp_per_frame_data(fw);
sp_dmem_store_uint32(SP0_ID,
(unsigned int)sp_address_of(sp_sw_state),
(uint32_t)(IA_CSS_SP_SW_TERMINATED));
sp_running = true;
ia_css_mmu_invalidate_cache();
mmu_invalidate_cache_all();
ia_css_spctrl_start(SP0_ID);
}
bool
ia_css_isp_has_started(void)
{
const struct ia_css_fw_info *fw = &sh_css_sp_fw;
unsigned int HIVE_ADDR_ia_css_ispctrl_sp_isp_started = fw->info.sp.isp_started;
(void)HIVE_ADDR_ia_css_ispctrl_sp_isp_started;
return (bool)load_sp_uint(ia_css_ispctrl_sp_isp_started);
}
bool
sh_css_sp_init_dma_sw_reg(int dma_id)
{
int i;
for (i = 0; i < N_DMA_CHANNEL_ID; i++) {
sh_css_sp_set_dma_sw_reg(dma_id,
i,
0,
true);
sh_css_sp_set_dma_sw_reg(dma_id,
i,
1,
true);
}
return true;
}
bool
sh_css_sp_set_dma_sw_reg(int dma_id,
int channel_id,
int request_type,
bool enable)
{
uint32_t sw_reg;
uint32_t bit_val;
uint32_t bit_offset;
uint32_t bit_mask;
(void)dma_id;
assert(channel_id >= 0 && channel_id < N_DMA_CHANNEL_ID);
assert(request_type >= 0);
sw_reg =
sh_css_sp_group.debug.dma_sw_reg;
bit_offset = (8 * request_type) + channel_id;
bit_mask = ~(1 << bit_offset);
sw_reg &= bit_mask;
bit_val = enable ? 1 : 0;
bit_val <<= bit_offset;
sw_reg |= bit_val;
sh_css_sp_group.debug.dma_sw_reg = sw_reg;
return true;
}
void
sh_css_sp_reset_global_vars(void)
{
memset(&sh_css_sp_group, 0, sizeof(struct sh_css_sp_group));
memset(&sh_css_sp_stage, 0, sizeof(struct sh_css_sp_stage));
memset(&sh_css_isp_stage, 0, sizeof(struct sh_css_isp_stage));
memset(&sh_css_sp_output, 0, sizeof(struct sh_css_sp_output));
memset(&per_frame_data, 0, sizeof(struct sh_css_sp_per_frame_data));
}
