static void
ia_css_binary_dvs_env(const struct ia_css_binary_info *info,
const struct ia_css_resolution *dvs_env,
struct ia_css_resolution *binary_dvs_env)
{
if (info->enable.dvs_envelope) {
assert(dvs_env != NULL);
binary_dvs_env->width = max(dvs_env->width, SH_CSS_MIN_DVS_ENVELOPE);
binary_dvs_env->height = max(dvs_env->height, SH_CSS_MIN_DVS_ENVELOPE);
}
}
static void
ia_css_binary_internal_res(const struct ia_css_frame_info *in_info,
const struct ia_css_frame_info *bds_out_info,
const struct ia_css_frame_info *out_info,
const struct ia_css_resolution *dvs_env,
const struct ia_css_binary_info *info,
struct ia_css_resolution *internal_res)
{
unsigned int isp_tmp_internal_width = 0,
isp_tmp_internal_height = 0;
bool binary_supports_yuv_ds = info->enable.ds & 2;
struct ia_css_resolution binary_dvs_env;
binary_dvs_env.width = 0;
binary_dvs_env.height = 0;
ia_css_binary_dvs_env(info, dvs_env, &binary_dvs_env);
if (binary_supports_yuv_ds) {
if (in_info != NULL) {
isp_tmp_internal_width = in_info->res.width
+ info->pipeline.left_cropping + binary_dvs_env.width;
isp_tmp_internal_height = in_info->res.height
+ info->pipeline.top_cropping + binary_dvs_env.height;
}
} else if ((bds_out_info != NULL) && (out_info != NULL) &&
(bds_out_info->res.width >= out_info->res.width)) {
isp_tmp_internal_width = bds_out_info->padded_width;
isp_tmp_internal_height = bds_out_info->res.height;
} else {
if (out_info != NULL) {
isp_tmp_internal_width = out_info->padded_width;
isp_tmp_internal_height = out_info->res.height;
}
}
internal_res->width = __ISP_INTERNAL_WIDTH(isp_tmp_internal_width,
(int)binary_dvs_env.width,
info->pipeline.left_cropping, info->pipeline.mode,
info->pipeline.c_subsampling,
info->output.num_chunks, info->pipeline.pipelining);
internal_res->height = __ISP_INTERNAL_HEIGHT(isp_tmp_internal_height,
info->pipeline.top_cropping,
binary_dvs_env.height);
#if defined(HAS_RES_MGR)
internal_res->height = (bds_out_info == NULL) ? internal_res->height : bds_out_info->res.height;
internal_res->width = (bds_out_info == NULL) ? internal_res->width: bds_out_info->res.width;
#endif
}
static enum ia_css_err
#ifndef ISP2401
ia_css_binary_compute_shading_table_bayer_origin(
const struct ia_css_binary *binary,
unsigned int required_bds_factor,
const struct ia_css_stream_config *stream_config,
struct sh_css_shading_table_bayer_origin_compute_results *res)
#else
sh_css_binary_get_sc_requirements(
const struct ia_css_binary *binary,
unsigned int required_bds_factor,
const struct ia_css_stream_config *stream_config,
struct sh_css_binary_sc_requirements *scr)
#endif
{
enum ia_css_err err;
#ifndef ISP2401
#else
#endif
unsigned int bds_num, bds_den;
#ifndef ISP2401
unsigned int bs_hor_ratio_in;
unsigned int bs_hor_ratio_out;
unsigned int bs_ver_ratio_in;
unsigned int bs_ver_ratio_out;
#else
unsigned int bs_hor_ratio_in, bs_hor_ratio_out, bs_ver_ratio_in, bs_ver_ratio_out;
#endif
#ifndef ISP2401
unsigned int left_padding_bqs;
#else
unsigned int left_padding_bqs;
#endif
#ifndef ISP2401
unsigned int need_bds_factor_2_00;
unsigned int left_padding_adjusted_bqs;
unsigned int bad_bqs_on_left_before_bs;
unsigned int bad_bqs_on_left_after_bs;
unsigned int bad_bqs_on_top_before_bs;
unsigned int bad_bqs_on_top_after_bs;
err = sh_css_bds_factor_get_numerator_denominator
(required_bds_factor, &bds_num, &bds_den);
if (err != IA_CSS_SUCCESS)
#else
unsigned int need_bds_factor_2_00, need_bds_factor_1_50, need_bds_factor_1_25;
unsigned int left_padding_adjusted_bqs;
unsigned int top_padding_bqs;
int bds_frac_acc = FRAC_ACC;
unsigned int right_shift_bqs_before_bs;
unsigned int right_shift_bqs_after_bs;
unsigned int down_shift_bqs_before_bs;
unsigned int down_shift_bqs_after_bs;
unsigned int sensor_data_origin_x_bqs_on_internal;
unsigned int sensor_data_origin_y_bqs_on_internal;
IA_CSS_ENTER_PRIVATE("binary=%p, required_bds_factor=%d, stream_config=%p",
binary, required_bds_factor, stream_config);
err = sh_css_bds_factor_get_numerator_denominator(required_bds_factor, &bds_num, &bds_den);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
#endif
return err;
#ifdef ISP2401
}
#endif
#ifndef ISP2401
#else
IA_CSS_LOG("bds_num=%d, bds_den=%d", bds_num, bds_den);
#endif
bs_hor_ratio_in = bds_num;
bs_hor_ratio_out = bds_den;
bs_ver_ratio_in = bds_num;
bs_ver_ratio_out = bds_den;
#ifndef ISP2401
#else
#endif
if (stream_config->left_padding == -1)
left_padding_bqs = _ISP_BQS(binary->left_padding);
else
#ifndef ISP2401
left_padding_bqs = (unsigned int)((int)ISP_VEC_NELEMS
- _ISP_BQS(stream_config->left_padding));
#else
left_padding_bqs = (unsigned int)((int)ISP_VEC_NELEMS - _ISP_BQS(stream_config->left_padding));
#endif
#ifndef ISP2401
#else
IA_CSS_LOG("stream.left_padding=%d, binary.left_padding=%d, left_padding_bqs=%d",
stream_config->left_padding, binary->left_padding, left_padding_bqs);
#endif
need_bds_factor_2_00 = ((binary->info->sp.bds.supported_bds_factors &
(PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_2_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_2_50) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_3_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_4_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_4_50) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_5_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_6_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_8_00))) != 0);
#ifndef ISP2401
if (need_bds_factor_2_00 && binary->info->sp.pipeline.left_cropping > 0)
left_padding_adjusted_bqs = left_padding_bqs + ISP_VEC_NELEMS;
else
#else
need_bds_factor_1_50 = ((binary->info->sp.bds.supported_bds_factors &
(PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_1_50) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_2_25) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_3_00) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_4_50) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_6_00))) != 0);
need_bds_factor_1_25 = ((binary->info->sp.bds.supported_bds_factors &
(PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_1_25) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_2_50) |
PACK_BDS_FACTOR(SH_CSS_BDS_FACTOR_5_00))) != 0);
if (binary->info->sp.pipeline.left_cropping > 0 &&
(need_bds_factor_2_00 || need_bds_factor_1_50 || need_bds_factor_1_25)) {
unsigned int first_vec_adjusted_bqs
= ISP_VEC_NELEMS * bs_hor_ratio_in / bs_hor_ratio_out;
left_padding_adjusted_bqs = first_vec_adjusted_bqs
- _ISP_BQS(binary->info->sp.pipeline.left_cropping);
} else
#endif
left_padding_adjusted_bqs = left_padding_bqs;
#ifndef ISP2401
bad_bqs_on_left_before_bs = 0;
bad_bqs_on_top_before_bs = 0;
#else
IA_CSS_LOG("supported_bds_factors=%d, need_bds_factor:2_00=%d, 1_50=%d, 1_25=%d",
binary->info->sp.bds.supported_bds_factors,
need_bds_factor_2_00, need_bds_factor_1_50, need_bds_factor_1_25);
IA_CSS_LOG("left_cropping=%d, left_padding_adjusted_bqs=%d",
binary->info->sp.pipeline.left_cropping, left_padding_adjusted_bqs);
top_padding_bqs = 0;
if (binary->info->sp.pipeline.top_cropping > 0 &&
(required_bds_factor == SH_CSS_BDS_FACTOR_1_25 ||
required_bds_factor == SH_CSS_BDS_FACTOR_1_50 ||
required_bds_factor == SH_CSS_BDS_FACTOR_2_00)) {
int top_cropping_bqs = _ISP_BQS(binary->info->sp.pipeline.top_cropping);
int factor = bds_num * bds_frac_acc / bds_den;
int top_padding_bqsxfrac_acc = (top_cropping_bqs * factor - top_cropping_bqs * bds_frac_acc)
+ (2 * bds_frac_acc - factor);
top_padding_bqs = (unsigned int)((top_padding_bqsxfrac_acc + bds_frac_acc/2 - 1) / bds_frac_acc);
}
IA_CSS_LOG("top_cropping=%d, top_padding_bqs=%d", binary->info->sp.pipeline.top_cropping, top_padding_bqs);
right_shift_bqs_before_bs = 0;
down_shift_bqs_before_bs = 0;
#endif
#ifndef ISP2401
bad_bqs_on_left_after_bs = 0;
bad_bqs_on_top_after_bs = 0;
#else
if (need_bds_factor_2_00 || need_bds_factor_1_50 || need_bds_factor_1_25) {
right_shift_bqs_before_bs = 1;
down_shift_bqs_before_bs = 1;
}
IA_CSS_LOG("right_shift_bqs_before_bs=%d, down_shift_bqs_before_bs=%d",
right_shift_bqs_before_bs, down_shift_bqs_before_bs);
right_shift_bqs_after_bs = 0;
down_shift_bqs_after_bs = 0;
#endif
#ifndef ISP2401
res->sc_bayer_origin_x_bqs_on_shading_table
= ((left_padding_adjusted_bqs + bad_bqs_on_left_before_bs)
* bs_hor_ratio_out + bs_hor_ratio_in/2) / bs_hor_ratio_in
+ bad_bqs_on_left_after_bs;
res->sc_bayer_origin_y_bqs_on_shading_table
= (bad_bqs_on_top_before_bs
* bs_ver_ratio_out + bs_ver_ratio_in/2) / bs_ver_ratio_in
+ bad_bqs_on_top_after_bs;
res->bayer_scale_hor_ratio_in = (uint32_t)bs_hor_ratio_in;
res->bayer_scale_hor_ratio_out = (uint32_t)bs_hor_ratio_out;
res->bayer_scale_ver_ratio_in = (uint32_t)bs_ver_ratio_in;
res->bayer_scale_ver_ratio_out = (uint32_t)bs_ver_ratio_out;
#else
if (binary->info->mem_offsets.offsets.param->dmem.dp.size != 0) {
right_shift_bqs_after_bs = 1;
down_shift_bqs_after_bs = 1;
}
IA_CSS_LOG("right_shift_bqs_after_bs=%d, down_shift_bqs_after_bs=%d",
right_shift_bqs_after_bs, down_shift_bqs_after_bs);
{
unsigned int bs_frac = bds_frac_acc;
unsigned int bs_out, bs_in;
bs_out = bs_hor_ratio_out * bs_frac;
bs_in = bs_hor_ratio_in * bs_frac;
sensor_data_origin_x_bqs_on_internal
= ((left_padding_adjusted_bqs + right_shift_bqs_before_bs) * bs_out + bs_in/2) / bs_in
+ right_shift_bqs_after_bs;
bs_out = bs_ver_ratio_out * bs_frac;
bs_in = bs_ver_ratio_in * bs_frac;
sensor_data_origin_y_bqs_on_internal
= ((top_padding_bqs + down_shift_bqs_before_bs) * bs_out + bs_in/2) / bs_in
+ down_shift_bqs_after_bs;
}
scr->bayer_scale_hor_ratio_in = (uint32_t)bs_hor_ratio_in;
scr->bayer_scale_hor_ratio_out = (uint32_t)bs_hor_ratio_out;
scr->bayer_scale_ver_ratio_in = (uint32_t)bs_ver_ratio_in;
scr->bayer_scale_ver_ratio_out = (uint32_t)bs_ver_ratio_out;
scr->sensor_data_origin_x_bqs_on_internal = (uint32_t)sensor_data_origin_x_bqs_on_internal;
scr->sensor_data_origin_y_bqs_on_internal = (uint32_t)sensor_data_origin_y_bqs_on_internal;
IA_CSS_LOG("sc_requirements: %d, %d, %d, %d, %d, %d",
scr->bayer_scale_hor_ratio_in, scr->bayer_scale_hor_ratio_out,
scr->bayer_scale_ver_ratio_in, scr->bayer_scale_ver_ratio_out,
scr->sensor_data_origin_x_bqs_on_internal, scr->sensor_data_origin_y_bqs_on_internal);
#endif
#ifdef ISP2401
IA_CSS_LEAVE_ERR_PRIVATE(err);
#endif
return err;
}
static void sh_css_binary_common_grid_info(const struct ia_css_binary *binary,
struct ia_css_grid_info *info)
{
assert(binary != NULL);
assert(info != NULL);
info->isp_in_width = binary->internal_frame_info.res.width;
info->isp_in_height = binary->internal_frame_info.res.height;
info->vamem_type = IA_CSS_VAMEM_TYPE_2;
}
void
ia_css_binary_dvs_grid_info(const struct ia_css_binary *binary,
struct ia_css_grid_info *info,
struct ia_css_pipe *pipe)
{
struct ia_css_dvs_grid_info *dvs_info;
(void)pipe;
assert(binary != NULL);
assert(info != NULL);
dvs_info = &info->dvs_grid.dvs_grid_info;
dvs_info->enable = binary->info->sp.enable.dis;
dvs_info->width = binary->dis.grid.dim.width;
dvs_info->height = binary->dis.grid.dim.height;
dvs_info->aligned_width = binary->dis.grid.pad.width;
dvs_info->aligned_height = binary->dis.grid.pad.height;
dvs_info->bqs_per_grid_cell = 1 << binary->dis.deci_factor_log2;
dvs_info->num_hor_coefs = binary->dis.coef.dim.width;
dvs_info->num_ver_coefs = binary->dis.coef.dim.height;
sh_css_binary_common_grid_info(binary, info);
}
void
ia_css_binary_dvs_stat_grid_info(
const struct ia_css_binary *binary,
struct ia_css_grid_info *info,
struct ia_css_pipe *pipe)
{
#if defined(HAS_RES_MGR)
struct ia_css_dvs_stat_grid_info *dvs_stat_info;
unsigned int i;
assert(binary != NULL);
assert(info != NULL);
dvs_stat_info = &info->dvs_grid.dvs_stat_grid_info;
if (binary->info->sp.enable.dvs_stats) {
for (i = 0; i < IA_CSS_SKC_DVS_STAT_NUM_OF_LEVELS; i++) {
dvs_stat_info->grd_cfg[i].grd_start.enable = 1;
}
ia_css_dvs_stat_grid_calculate(pipe, dvs_stat_info);
}
else {
memset(dvs_stat_info, 0, sizeof(struct ia_css_dvs_stat_grid_info));
}
#endif
(void)pipe;
sh_css_binary_common_grid_info(binary, info);
return;
}
enum ia_css_err
ia_css_binary_3a_grid_info(const struct ia_css_binary *binary,
struct ia_css_grid_info *info,
struct ia_css_pipe *pipe)
{
struct ia_css_3a_grid_info *s3a_info;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("binary=%p, info=%p, pipe=%p",
binary, info, pipe);
assert(binary != NULL);
assert(info != NULL);
s3a_info = &info->s3a_grid;
s3a_info->enable = binary->info->sp.enable.s3a;
s3a_info->width = binary->s3atbl_width;
s3a_info->height = binary->s3atbl_height;
s3a_info->aligned_width = binary->s3atbl_isp_width;
s3a_info->aligned_height = binary->s3atbl_isp_height;
s3a_info->bqs_per_grid_cell = (1 << binary->deci_factor_log2);
s3a_info->deci_factor_log2 = binary->deci_factor_log2;
s3a_info->elem_bit_depth = SH_CSS_BAYER_BITS;
s3a_info->use_dmem = binary->info->sp.s3a.s3atbl_use_dmem;
#if defined(HAS_NO_HMEM)
s3a_info->has_histogram = 1;
#else
s3a_info->has_histogram = 0;
#endif
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static void
binary_init_pc_histogram(struct sh_css_pc_histogram *histo)
{
assert(histo != NULL);
histo->length = 0;
histo->run = NULL;
histo->stall = NULL;
}
static void
binary_init_metrics(struct sh_css_binary_metrics *metrics,
const struct ia_css_binary_info *info)
{
assert(metrics != NULL);
assert(info != NULL);
metrics->mode = info->pipeline.mode;
metrics->id = info->id;
metrics->next = NULL;
binary_init_pc_histogram(&metrics->isp_histogram);
binary_init_pc_histogram(&metrics->sp_histogram);
}
static bool
binary_supports_output_format(const struct ia_css_binary_xinfo *info,
enum ia_css_frame_format format)
{
int i;
assert(info != NULL);
for (i = 0; i < info->num_output_formats; i++) {
if (info->output_formats[i] == format)
return true;
}
return false;
}
static bool
binary_supports_input_format(const struct ia_css_binary_xinfo *info,
enum ia_css_stream_format format)
{
assert(info != NULL);
(void)format;
return true;
}
static bool
binary_supports_vf_format(const struct ia_css_binary_xinfo *info,
enum ia_css_frame_format format)
{
int i;
assert(info != NULL);
for (i = 0; i < info->num_vf_formats; i++) {
if (info->vf_formats[i] == format)
return true;
}
return false;
}
static bool
supports_bds_factor(uint32_t supported_factors,
uint32_t bds_factor)
{
return ((supported_factors & PACK_BDS_FACTOR(bds_factor)) != 0);
}
static enum ia_css_err
binary_init_info(struct ia_css_binary_xinfo *info, unsigned int i,
bool *binary_found)
{
const unsigned char *blob = sh_css_blob_info[i].blob;
unsigned size = sh_css_blob_info[i].header.blob.size;
if ((info == NULL) || (binary_found == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
*info = sh_css_blob_info[i].header.info.isp;
*binary_found = blob != NULL;
info->blob_index = i;
if (!size)
return IA_CSS_SUCCESS;
info->xmem_addr = sh_css_load_blob(blob, size);
if (!info->xmem_addr)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_binary_init_infos(void)
{
unsigned int i;
unsigned int num_of_isp_binaries = sh_css_num_binaries - NUM_OF_SPS - NUM_OF_BLS;
if (num_of_isp_binaries == 0)
return IA_CSS_SUCCESS;
all_binaries = sh_css_malloc(num_of_isp_binaries *
sizeof(*all_binaries));
if (all_binaries == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
for (i = 0; i < num_of_isp_binaries; i++) {
enum ia_css_err ret;
struct ia_css_binary_xinfo *binary = &all_binaries[i];
bool binary_found;
ret = binary_init_info(binary, i, &binary_found);
if (ret != IA_CSS_SUCCESS)
return ret;
if (!binary_found)
continue;
binary->next = binary_infos[binary->sp.pipeline.mode];
binary_infos[binary->sp.pipeline.mode] = binary;
binary->blob = &sh_css_blob_info[i];
binary->mem_offsets = sh_css_blob_info[i].mem_offsets;
}
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_binary_uninit(void)
{
unsigned int i;
struct ia_css_binary_xinfo *b;
for (i = 0; i < IA_CSS_BINARY_NUM_MODES; i++) {
for (b = binary_infos[i]; b; b = b->next) {
if (b->xmem_addr)
hmm_free(b->xmem_addr);
b->xmem_addr = mmgr_NULL;
}
binary_infos[i] = NULL;
}
sh_css_free(all_binaries);
return IA_CSS_SUCCESS;
}
static int
binary_grid_deci_factor_log2(int width, int height)
{
#define MAX_SPEC_DECI_FACT_LOG2 5
#define MIN_SPEC_DECI_FACT_LOG2 3
#define DECI_FACT_LOG2_5_SMALLEST_FRAME_WIDTH_BQ 1280
#define DECI_FACT_LOG2_4_SMALLEST_FRAME_WIDTH_BQ 640
int smallest_factor;
int spec_factor;
assert(ISP_BQ_GRID_WIDTH(width, MAX_SPEC_DECI_FACT_LOG2) <= SH_CSS_MAX_BQ_GRID_WIDTH);
assert(ISP_BQ_GRID_HEIGHT(height, MAX_SPEC_DECI_FACT_LOG2) <= SH_CSS_MAX_BQ_GRID_HEIGHT);
smallest_factor = MAX_SPEC_DECI_FACT_LOG2;
while (ISP_BQ_GRID_WIDTH(width, smallest_factor - 1) <= SH_CSS_MAX_BQ_GRID_WIDTH &&
ISP_BQ_GRID_HEIGHT(height, smallest_factor - 1) <= SH_CSS_MAX_BQ_GRID_HEIGHT
&& smallest_factor > MIN_SPEC_DECI_FACT_LOG2)
smallest_factor--;
if (_ISP_BQS(width) >= DECI_FACT_LOG2_5_SMALLEST_FRAME_WIDTH_BQ)
spec_factor = 5;
else if (_ISP_BQS(width) >= DECI_FACT_LOG2_4_SMALLEST_FRAME_WIDTH_BQ)
spec_factor = 4;
else
spec_factor = 3;
return max(smallest_factor, spec_factor);
#undef MAX_SPEC_DECI_FACT_LOG2
#undef MIN_SPEC_DECI_FACT_LOG2
#undef DECI_FACT_LOG2_5_SMALLEST_FRAME_WIDTH_BQ
#undef DECI_FACT_LOG2_4_SMALLEST_FRAME_WIDTH_BQ
}
static int
binary_in_frame_padded_width(int in_frame_width,
int isp_internal_width,
int dvs_env_width,
int stream_config_left_padding,
int left_cropping,
bool need_scaling)
{
int rval;
int nr_of_left_paddings;
#if defined(USE_INPUT_SYSTEM_VERSION_2401)
nr_of_left_paddings = 0;
#else
nr_of_left_paddings = 2*ISP_VEC_NELEMS;
#endif
#if defined(HAS_RES_MGR)
(void)dvs_env_width;
#endif
if (need_scaling) {
if (stream_config_left_padding != -1) {
rval =
CEIL_MUL(in_frame_width + nr_of_left_paddings,
2*ISP_VEC_NELEMS);
} else {
#if !defined(HAS_RES_MGR)
in_frame_width += dvs_env_width;
#endif
rval =
CEIL_MUL(in_frame_width +
(left_cropping ? nr_of_left_paddings : 0),
2*ISP_VEC_NELEMS);
}
} else {
rval = isp_internal_width;
}
return rval;
}
enum ia_css_err
ia_css_binary_fill_info(const struct ia_css_binary_xinfo *xinfo,
bool online,
bool two_ppc,
enum ia_css_stream_format stream_format,
const struct ia_css_frame_info *in_info,
const struct ia_css_frame_info *bds_out_info,
const struct ia_css_frame_info *out_info[],
const struct ia_css_frame_info *vf_info,
struct ia_css_binary *binary,
struct ia_css_resolution *dvs_env,
int stream_config_left_padding,
bool accelerator)
{
const struct ia_css_binary_info *info = &xinfo->sp;
unsigned int dvs_env_width = 0,
dvs_env_height = 0,
vf_log_ds = 0,
s3a_log_deci = 0,
bits_per_pixel = 0,
sc_3a_dis_width = 0,
sc_3a_dis_padded_width = 0,
sc_3a_dis_height = 0,
isp_internal_width = 0,
isp_internal_height = 0,
s3a_isp_width = 0;
bool need_scaling = false;
struct ia_css_resolution binary_dvs_env, internal_res;
enum ia_css_err err;
unsigned int i;
const struct ia_css_frame_info *bin_out_info = NULL;
assert(info != NULL);
assert(binary != NULL);
binary->info = xinfo;
if (!accelerator) {
err = ia_css_isp_param_allocate_isp_parameters(
&binary->mem_params, &binary->css_params,
&info->mem_initializers);
if (err != IA_CSS_SUCCESS) {
return err;
}
}
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
if (out_info[i] && (out_info[i]->res.width != 0)) {
bin_out_info = out_info[i];
break;
}
}
if (in_info != NULL && bin_out_info != NULL) {
need_scaling = (in_info->res.width != bin_out_info->res.width) ||
(in_info->res.height != bin_out_info->res.height);
}
binary_dvs_env.width = 0;
binary_dvs_env.height = 0;
ia_css_binary_dvs_env(info, dvs_env, &binary_dvs_env);
dvs_env_width = binary_dvs_env.width;
dvs_env_height = binary_dvs_env.height;
binary->dvs_envelope.width = dvs_env_width;
binary->dvs_envelope.height = dvs_env_height;
internal_res.width = 0;
internal_res.height = 0;
ia_css_binary_internal_res(in_info, bds_out_info, bin_out_info, dvs_env,
info, &internal_res);
isp_internal_width = internal_res.width;
isp_internal_height = internal_res.height;
if (bin_out_info != NULL)
binary->internal_frame_info.format = bin_out_info->format;
binary->internal_frame_info.res.width = isp_internal_width;
binary->internal_frame_info.padded_width = CEIL_MUL(isp_internal_width, 2*ISP_VEC_NELEMS);
binary->internal_frame_info.res.height = isp_internal_height;
binary->internal_frame_info.raw_bit_depth = bits_per_pixel;
if (in_info != NULL) {
binary->effective_in_frame_res.width = in_info->res.width;
binary->effective_in_frame_res.height = in_info->res.height;
bits_per_pixel = in_info->raw_bit_depth;
binary->in_frame_info.res.width = in_info->res.width + info->pipeline.left_cropping;
binary->in_frame_info.res.height = in_info->res.height + info->pipeline.top_cropping;
#if !defined(HAS_RES_MGR)
binary->in_frame_info.res.width += dvs_env_width;
binary->in_frame_info.res.height += dvs_env_height;
#endif
binary->in_frame_info.padded_width =
binary_in_frame_padded_width(in_info->res.width,
isp_internal_width,
dvs_env_width,
stream_config_left_padding,
info->pipeline.left_cropping,
need_scaling);
binary->in_frame_info.format = in_info->format;
binary->in_frame_info.raw_bayer_order = in_info->raw_bayer_order;
binary->in_frame_info.crop_info = in_info->crop_info;
}
if (online) {
bits_per_pixel = ia_css_util_input_format_bpp(
stream_format, two_ppc);
}
binary->in_frame_info.raw_bit_depth = bits_per_pixel;
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
if (out_info[i] != NULL) {
binary->out_frame_info[i].res.width = out_info[i]->res.width;
binary->out_frame_info[i].res.height = out_info[i]->res.height;
binary->out_frame_info[i].padded_width = out_info[i]->padded_width;
if (info->pipeline.mode == IA_CSS_BINARY_MODE_COPY) {
binary->out_frame_info[i].raw_bit_depth = bits_per_pixel;
} else {
binary->out_frame_info[i].raw_bit_depth = 16;
}
binary->out_frame_info[i].format = out_info[i]->format;
}
}
if (vf_info && (vf_info->res.width != 0)) {
err = ia_css_vf_configure(binary, bin_out_info, (struct ia_css_frame_info *)vf_info, &vf_log_ds);
if (err != IA_CSS_SUCCESS) {
if (!accelerator) {
ia_css_isp_param_destroy_isp_parameters(
&binary->mem_params,
&binary->css_params);
}
return err;
}
}
binary->vf_downscale_log2 = vf_log_ds;
binary->online = online;
binary->input_format = stream_format;
if ((vf_info != NULL) && (vf_info->res.width != 0)) {
unsigned int vf_out_vecs, vf_out_width, vf_out_height;
binary->vf_frame_info.format = vf_info->format;
if (bin_out_info == NULL)
return IA_CSS_ERR_INTERNAL_ERROR;
vf_out_vecs = __ISP_VF_OUTPUT_WIDTH_VECS(bin_out_info->padded_width,
vf_log_ds);
vf_out_width = _ISP_VF_OUTPUT_WIDTH(vf_out_vecs);
vf_out_height = _ISP_VF_OUTPUT_HEIGHT(bin_out_info->res.height,
vf_log_ds);
if (info->pipeline.mode == IA_CSS_BINARY_MODE_PREVIEW) {
binary->out_frame_info[0].res.width =
(bin_out_info->res.width >> vf_log_ds);
binary->out_frame_info[0].padded_width = vf_out_width;
binary->out_frame_info[0].res.height = vf_out_height;
binary->vf_frame_info.res.width = 0;
binary->vf_frame_info.padded_width = 0;
binary->vf_frame_info.res.height = 0;
} else {
binary->vf_frame_info.res.width =
(bin_out_info->res.width >> vf_log_ds);
binary->vf_frame_info.padded_width = vf_out_width;
binary->vf_frame_info.res.height = vf_out_height;
}
} else {
binary->vf_frame_info.res.width = 0;
binary->vf_frame_info.padded_width = 0;
binary->vf_frame_info.res.height = 0;
}
if (info->enable.ca_gdc) {
binary->morph_tbl_width =
_ISP_MORPH_TABLE_WIDTH(isp_internal_width);
binary->morph_tbl_aligned_width =
_ISP_MORPH_TABLE_ALIGNED_WIDTH(isp_internal_width);
binary->morph_tbl_height =
_ISP_MORPH_TABLE_HEIGHT(isp_internal_height);
} else {
binary->morph_tbl_width = 0;
binary->morph_tbl_aligned_width = 0;
binary->morph_tbl_height = 0;
}
sc_3a_dis_width = binary->in_frame_info.res.width;
sc_3a_dis_padded_width = binary->in_frame_info.padded_width;
sc_3a_dis_height = binary->in_frame_info.res.height;
if (bds_out_info != NULL && in_info != NULL &&
bds_out_info->res.width != in_info->res.width) {
sc_3a_dis_width = bds_out_info->res.width + info->pipeline.left_cropping;
sc_3a_dis_padded_width = isp_internal_width;
sc_3a_dis_height = isp_internal_height;
}
s3a_isp_width = _ISP_S3A_ELEMS_ISP_WIDTH(sc_3a_dis_padded_width,
info->pipeline.left_cropping);
if (info->s3a.fixed_s3a_deci_log) {
s3a_log_deci = info->s3a.fixed_s3a_deci_log;
} else {
s3a_log_deci = binary_grid_deci_factor_log2(s3a_isp_width,
sc_3a_dis_height);
}
binary->deci_factor_log2 = s3a_log_deci;
if (info->enable.s3a) {
binary->s3atbl_width =
_ISP_S3ATBL_WIDTH(sc_3a_dis_width,
s3a_log_deci);
binary->s3atbl_height =
_ISP_S3ATBL_HEIGHT(sc_3a_dis_height,
s3a_log_deci);
binary->s3atbl_isp_width =
_ISP_S3ATBL_ISP_WIDTH(s3a_isp_width,
s3a_log_deci);
binary->s3atbl_isp_height =
_ISP_S3ATBL_ISP_HEIGHT(sc_3a_dis_height,
s3a_log_deci);
} else {
binary->s3atbl_width = 0;
binary->s3atbl_height = 0;
binary->s3atbl_isp_width = 0;
binary->s3atbl_isp_height = 0;
}
if (info->enable.sc) {
binary->sctbl_width_per_color =
#ifndef ISP2401
_ISP_SCTBL_WIDTH_PER_COLOR(sc_3a_dis_padded_width,
s3a_log_deci);
#else
_ISP_SCTBL_WIDTH_PER_COLOR(isp_internal_width, s3a_log_deci);
#endif
binary->sctbl_aligned_width_per_color =
SH_CSS_MAX_SCTBL_ALIGNED_WIDTH_PER_COLOR;
binary->sctbl_height =
#ifndef ISP2401
_ISP_SCTBL_HEIGHT(sc_3a_dis_height, s3a_log_deci);
#else
_ISP_SCTBL_HEIGHT(isp_internal_height, s3a_log_deci);
binary->sctbl_legacy_width_per_color =
_ISP_SCTBL_LEGACY_WIDTH_PER_COLOR(sc_3a_dis_padded_width, s3a_log_deci);
binary->sctbl_legacy_height =
_ISP_SCTBL_LEGACY_HEIGHT(sc_3a_dis_height, s3a_log_deci);
#endif
} else {
binary->sctbl_width_per_color = 0;
binary->sctbl_aligned_width_per_color = 0;
binary->sctbl_height = 0;
#ifdef ISP2401
binary->sctbl_legacy_width_per_color = 0;
binary->sctbl_legacy_height = 0;
#endif
}
ia_css_sdis_init_info(&binary->dis,
sc_3a_dis_width,
sc_3a_dis_padded_width,
sc_3a_dis_height,
info->pipeline.isp_pipe_version,
info->enable.dis);
if (info->pipeline.left_cropping)
binary->left_padding = 2 * ISP_VEC_NELEMS - info->pipeline.left_cropping;
else
binary->left_padding = 0;
return IA_CSS_SUCCESS;
}
enum ia_css_err
ia_css_binary_find(struct ia_css_binary_descr *descr,
struct ia_css_binary *binary)
{
int mode;
bool online;
bool two_ppc;
enum ia_css_stream_format stream_format;
const struct ia_css_frame_info *req_in_info,
*req_bds_out_info,
*req_out_info[IA_CSS_BINARY_MAX_OUTPUT_PORTS],
*req_bin_out_info = NULL,
*req_vf_info;
struct ia_css_binary_xinfo *xcandidate;
#ifndef ISP2401
bool need_ds, need_dz, need_dvs, need_xnr, need_dpc;
#else
bool need_ds, need_dz, need_dvs, need_xnr, need_dpc, need_tnr;
#endif
bool striped;
bool enable_yuv_ds;
bool enable_high_speed;
bool enable_dvs_6axis;
bool enable_reduced_pipe;
bool enable_capture_pp_bli;
#ifdef ISP2401
bool enable_luma_only;
#endif
enum ia_css_err err = IA_CSS_ERR_INTERNAL_ERROR;
bool continuous;
unsigned int isp_pipe_version;
struct ia_css_resolution dvs_env, internal_res;
unsigned int i;
assert(descr != NULL);
assert(binary != NULL);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() enter: descr=%p, (mode=%d), binary=%p\n",
descr, descr->mode,
binary);
mode = descr->mode;
online = descr->online;
two_ppc = descr->two_ppc;
stream_format = descr->stream_format;
req_in_info = descr->in_info;
req_bds_out_info = descr->bds_out_info;
for (i = 0; i < IA_CSS_BINARY_MAX_OUTPUT_PORTS; i++) {
req_out_info[i] = descr->out_info[i];
if (req_out_info[i] && (req_out_info[i]->res.width != 0))
req_bin_out_info = req_out_info[i];
}
if (req_bin_out_info == NULL)
return IA_CSS_ERR_INTERNAL_ERROR;
#ifndef ISP2401
req_vf_info = descr->vf_info;
#else
if ((descr->vf_info != NULL) && (descr->vf_info->res.width == 0))
req_vf_info = NULL;
else
req_vf_info = descr->vf_info;
#endif
need_xnr = descr->enable_xnr;
need_ds = descr->enable_fractional_ds;
need_dz = false;
need_dvs = false;
need_dpc = descr->enable_dpc;
#ifdef ISP2401
need_tnr = descr->enable_tnr;
#endif
enable_yuv_ds = descr->enable_yuv_ds;
enable_high_speed = descr->enable_high_speed;
enable_dvs_6axis = descr->enable_dvs_6axis;
enable_reduced_pipe = descr->enable_reduced_pipe;
enable_capture_pp_bli = descr->enable_capture_pp_bli;
#ifdef ISP2401
enable_luma_only = descr->enable_luma_only;
#endif
continuous = descr->continuous;
striped = descr->striped;
isp_pipe_version = descr->isp_pipe_version;
dvs_env.width = 0;
dvs_env.height = 0;
internal_res.width = 0;
internal_res.height = 0;
if (mode == IA_CSS_BINARY_MODE_VIDEO) {
dvs_env = descr->dvs_env;
need_dz = descr->enable_dz;
need_dvs = dvs_env.width || dvs_env.height;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "BINARY INFO:\n");
for (i = 0; i < IA_CSS_BINARY_NUM_MODES; i++) {
xcandidate = binary_infos[i];
if (xcandidate) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "%d:\n", i);
while (xcandidate) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, " Name:%s Type:%d Cont:%d\n",
xcandidate->blob->name, xcandidate->type,
xcandidate->sp.enable.continuous);
xcandidate = xcandidate->next;
}
}
}
for (xcandidate = binary_infos[mode]; xcandidate;
xcandidate = xcandidate->next) {
struct ia_css_binary_info *candidate = &xcandidate->sp;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() candidate = %p, mode = %d ID = %d\n",
candidate, candidate->pipeline.mode, candidate->id);
if (!candidate->enable.continuous &&
continuous && (mode != IA_CSS_BINARY_MODE_COPY)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d && (%d != %d)\n",
__LINE__, candidate->enable.continuous,
continuous, mode,
IA_CSS_BINARY_MODE_COPY);
continue;
}
if (striped && candidate->iterator.num_stripes == 1) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: binary is not striped\n",
__LINE__);
continue;
}
if (candidate->pipeline.isp_pipe_version != isp_pipe_version &&
(mode != IA_CSS_BINARY_MODE_COPY) &&
(mode != IA_CSS_BINARY_MODE_CAPTURE_PP) &&
(mode != IA_CSS_BINARY_MODE_VF_PP)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d != %d)\n",
__LINE__,
candidate->pipeline.isp_pipe_version, isp_pipe_version);
continue;
}
if (!candidate->enable.reduced_pipe && enable_reduced_pipe) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__,
candidate->enable.reduced_pipe,
enable_reduced_pipe);
continue;
}
if (!candidate->enable.dvs_6axis && enable_dvs_6axis) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__,
candidate->enable.dvs_6axis,
enable_dvs_6axis);
continue;
}
if (candidate->enable.high_speed && !enable_high_speed) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: %d && !%d\n",
__LINE__,
candidate->enable.high_speed,
enable_high_speed);
continue;
}
if (!candidate->enable.xnr && need_xnr) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: %d && !%d\n",
__LINE__,
candidate->enable.xnr,
need_xnr);
continue;
}
if (!(candidate->enable.ds & 2) && enable_yuv_ds) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__,
((candidate->enable.ds & 2) != 0),
enable_yuv_ds);
continue;
}
if ((candidate->enable.ds & 2) && !enable_yuv_ds) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: %d && !%d\n",
__LINE__,
((candidate->enable.ds & 2) != 0),
enable_yuv_ds);
continue;
}
if (mode == IA_CSS_BINARY_MODE_VIDEO &&
candidate->enable.ds && need_ds)
need_dz = false;
if ((req_vf_info != NULL) && !(candidate->enable.vf_veceven ||
candidate->vf_dec.is_variable ||
xcandidate->num_output_pins > 1)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%p != NULL) && !(%d || %d || (%d >%d))\n",
__LINE__, req_vf_info,
candidate->enable.vf_veceven,
candidate->vf_dec.is_variable,
xcandidate->num_output_pins, 1);
continue;
}
if (!candidate->enable.dvs_envelope && need_dvs) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__,
candidate->enable.dvs_envelope, (int)need_dvs);
continue;
}
ia_css_binary_internal_res(req_in_info, req_bds_out_info,
req_bin_out_info, &dvs_env, candidate, &internal_res);
if (internal_res.width > candidate->internal.max_width) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d > %d)\n",
__LINE__, internal_res.width,
candidate->internal.max_width);
continue;
}
if (internal_res.height > candidate->internal.max_height) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d > %d)\n",
__LINE__, internal_res.height,
candidate->internal.max_height);
continue;
}
if (!candidate->enable.ds && need_ds & !(xcandidate->num_output_pins > 1)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__, candidate->enable.ds, (int)need_ds);
continue;
}
if (!candidate->enable.uds && !candidate->enable.dvs_6axis && need_dz) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && !%d && %d\n",
__LINE__, candidate->enable.uds,
candidate->enable.dvs_6axis, (int)need_dz);
continue;
}
if (online && candidate->input.source == IA_CSS_BINARY_INPUT_MEMORY) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: %d && (%d == %d)\n",
__LINE__, online, candidate->input.source,
IA_CSS_BINARY_INPUT_MEMORY);
continue;
}
if (!online && candidate->input.source == IA_CSS_BINARY_INPUT_SENSOR) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && (%d == %d)\n",
__LINE__, online, candidate->input.source,
IA_CSS_BINARY_INPUT_SENSOR);
continue;
}
if (req_bin_out_info->res.width < candidate->output.min_width ||
req_bin_out_info->res.width > candidate->output.max_width) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d > %d) || (%d < %d)\n",
__LINE__,
req_bin_out_info->padded_width,
candidate->output.min_width,
req_bin_out_info->padded_width,
candidate->output.max_width);
continue;
}
if (xcandidate->num_output_pins > 1 &&
req_vf_info) {
if (req_vf_info->res.width > candidate->output.max_width) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d < %d)\n",
__LINE__,
req_vf_info->res.width,
candidate->output.max_width);
continue;
}
}
if (req_in_info->padded_width > candidate->input.max_width) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d > %d)\n",
__LINE__, req_in_info->padded_width,
candidate->input.max_width);
continue;
}
if (!binary_supports_output_format(xcandidate, req_bin_out_info->format)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d\n",
__LINE__,
binary_supports_output_format(xcandidate, req_bin_out_info->format));
continue;
}
#ifdef ISP2401
if (!binary_supports_input_format(xcandidate, descr->stream_format)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d\n",
__LINE__,
binary_supports_input_format(xcandidate, req_in_info->format));
continue;
}
#endif
if (xcandidate->num_output_pins > 1 &&
req_vf_info &&
!binary_supports_output_format(xcandidate, req_vf_info->format)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d > %d) && (%p != NULL) && !%d\n",
__LINE__, xcandidate->num_output_pins, 1,
req_vf_info,
binary_supports_output_format(xcandidate, req_vf_info->format));
continue;
}
if (xcandidate->num_output_pins == 1 &&
req_vf_info && candidate->enable.vf_veceven &&
!binary_supports_vf_format(xcandidate, req_vf_info->format)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d == %d) && (%p != NULL) && %d && !%d\n",
__LINE__, xcandidate->num_output_pins, 1,
req_vf_info, candidate->enable.vf_veceven,
binary_supports_vf_format(xcandidate, req_vf_info->format));
continue;
}
if (xcandidate->num_output_pins == 1 &&
req_vf_info && candidate->enable.vf_veceven) {
if (req_vf_info->res.width > candidate->output.max_width) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: (%d < %d)\n",
__LINE__,
req_vf_info->res.width,
candidate->output.max_width);
continue;
}
}
if (!supports_bds_factor(candidate->bds.supported_bds_factors,
descr->required_bds_factor)) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: 0x%x & 0x%x)\n",
__LINE__, candidate->bds.supported_bds_factors,
descr->required_bds_factor);
continue;
}
if (!candidate->enable.dpc && need_dpc) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: 0x%x & 0x%x)\n",
__LINE__, candidate->enable.dpc,
descr->enable_dpc);
continue;
}
if (candidate->uds.use_bci && enable_capture_pp_bli) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: 0x%x & 0x%x)\n",
__LINE__, candidate->uds.use_bci,
descr->enable_capture_pp_bli);
continue;
}
#ifdef ISP2401
if (candidate->enable.luma_only != enable_luma_only) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: %d != %d\n",
__LINE__, candidate->enable.luma_only,
descr->enable_luma_only);
continue;
}
if(!candidate->enable.tnr && need_tnr) {
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() [%d] continue: !%d && %d\n",
__LINE__, candidate->enable.tnr,
descr->enable_tnr);
continue;
}
#endif
err = ia_css_binary_fill_info(xcandidate, online, two_ppc,
stream_format, req_in_info,
req_bds_out_info,
req_out_info, req_vf_info,
binary, &dvs_env,
descr->stream_config_left_padding,
false);
if (err != IA_CSS_SUCCESS)
break;
binary_init_metrics(&binary->metrics, &binary->info->sp);
break;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() selected = %p, mode = %d ID = %d\n",
xcandidate, xcandidate ? xcandidate->sp.pipeline.mode : 0, xcandidate ? xcandidate->sp.id : 0);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE,
"ia_css_binary_find() leave: return_err=%d\n", err);
return err;
}
unsigned
ia_css_binary_max_vf_width(void)
{
if (binary_infos[IA_CSS_BINARY_MODE_VF_PP])
return binary_infos[IA_CSS_BINARY_MODE_VF_PP]->sp.output.max_width;
return 0;
}
void
ia_css_binary_destroy_isp_parameters(struct ia_css_binary *binary)
{
if (binary) {
ia_css_isp_param_destroy_isp_parameters(&binary->mem_params,
&binary->css_params);
}
}
void
ia_css_binary_get_isp_binaries(struct ia_css_binary_xinfo **binaries,
uint32_t *num_isp_binaries)
{
assert(binaries != NULL);
if (num_isp_binaries)
*num_isp_binaries = 0;
*binaries = all_binaries;
if (all_binaries && num_isp_binaries) {
if (sh_css_num_binaries > 0)
*num_isp_binaries = sh_css_num_binaries - 1;
}
}
