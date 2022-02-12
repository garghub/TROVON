struct ia_css_host_data *
ia_css_params_alloc_convert_sctbl(
const struct ia_css_pipeline_stage *stage,
const struct ia_css_shading_table *shading_table)
{
const struct ia_css_binary *binary = stage->binary;
struct ia_css_host_data *sctbl;
unsigned int i, j, aligned_width, row_padding;
unsigned int sctbl_size;
short int *ptr;
assert(binary != NULL);
assert(shading_table != NULL);
IA_CSS_ENTER_PRIVATE("");
if (shading_table == NULL) {
IA_CSS_LEAVE_PRIVATE("void");
return NULL;
}
aligned_width = binary->sctbl_aligned_width_per_color;
row_padding = aligned_width - shading_table->width;
sctbl_size = shading_table->height * IA_CSS_SC_NUM_COLORS * aligned_width * sizeof(short);
sctbl = ia_css_host_data_allocate((size_t)sctbl_size);
if (!sctbl)
return NULL;
ptr = (short int*)sctbl->address;
memset(ptr,
0,
sctbl_size);
for (i = 0; i < shading_table->height; i++) {
for (j = 0; j < IA_CSS_SC_NUM_COLORS; j++) {
memcpy(ptr,
&shading_table->data[j]
[i*shading_table->width],
shading_table->width * sizeof(short));
ptr += aligned_width;
}
}
IA_CSS_LEAVE_PRIVATE("void");
return sctbl;
}
enum ia_css_err ia_css_params_store_sctbl(
const struct ia_css_pipeline_stage *stage,
hrt_vaddress sc_tbl,
const struct ia_css_shading_table *sc_config)
{
struct ia_css_host_data *isp_sc_tbl;
IA_CSS_ENTER_PRIVATE("");
if (sc_config == NULL) {
IA_CSS_LEAVE_PRIVATE("void");
return IA_CSS_SUCCESS;
}
isp_sc_tbl = ia_css_params_alloc_convert_sctbl(stage, sc_config);
if (!isp_sc_tbl) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
ia_css_params_store_ia_css_host_data(sc_tbl, isp_sc_tbl);
ia_css_host_data_free(isp_sc_tbl);
IA_CSS_LEAVE_PRIVATE("void");
return IA_CSS_SUCCESS;
}
static void
sh_css_enable_pipeline(const struct ia_css_binary *binary)
{
if (!binary)
return;
IA_CSS_ENTER_PRIVATE("");
ia_css_isp_param_enable_pipeline(&binary->mem_params);
IA_CSS_LEAVE_PRIVATE("void");
}
static enum ia_css_err
ia_css_process_zoom_and_motion(
struct ia_css_isp_parameters *params,
const struct ia_css_pipeline_stage *first_stage)
{
const struct ia_css_pipeline_stage *stage;
enum ia_css_err err = IA_CSS_SUCCESS;
struct ia_css_resolution pipe_in_res;
pipe_in_res.width = 0;
pipe_in_res.height = 0;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("");
for (stage = first_stage; stage; stage = stage->next) {
struct ia_css_binary *binary;
static struct ia_css_binary tmp_binary;
const struct ia_css_binary_xinfo *info = NULL;
binary = stage->binary;
if (binary) {
info = binary->info;
} else {
const struct sh_css_binary_args *args = &stage->args;
const struct ia_css_frame_info *out_infos[IA_CSS_BINARY_MAX_OUTPUT_PORTS] = {NULL};
if (args->out_frame[0])
out_infos[0] = &args->out_frame[0]->info;
info = &stage->firmware->info.isp;
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
}
if (stage == first_stage) {
pipe_in_res = binary->effective_in_frame_res;
}
assert(stage->stage_num < SH_CSS_MAX_STAGES);
if (params->dz_config.zoom_region.resolution.width == 0 &&
params->dz_config.zoom_region.resolution.height == 0) {
sh_css_update_uds_and_crop_info(
&info->sp,
&binary->in_frame_info,
&binary->out_frame_info[0],
&binary->dvs_envelope,
&params->dz_config,
&params->motion_config,
&params->uds[stage->stage_num].uds,
&params->uds[stage->stage_num].crop_pos,
stage->enable_zoom);
} else {
err = sh_css_update_uds_and_crop_info_based_on_zoom_region(
&info->sp,
&binary->in_frame_info,
&binary->out_frame_info[0],
&binary->dvs_envelope,
&params->dz_config,
&params->motion_config,
&params->uds[stage->stage_num].uds,
&params->uds[stage->stage_num].crop_pos,
pipe_in_res,
stage->enable_zoom);
if (err != IA_CSS_SUCCESS)
return err;
}
}
params->isp_params_changed = true;
IA_CSS_LEAVE_PRIVATE("void");
return err;
}
static void
sh_css_set_gamma_table(struct ia_css_isp_parameters *params,
const struct ia_css_gamma_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
params->gc_table = *table;
params->config_changed[IA_CSS_GC_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_gamma_table(const struct ia_css_isp_parameters *params,
struct ia_css_gamma_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
*table = params->gc_table;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_ctc_table(struct ia_css_isp_parameters *params,
const struct ia_css_ctc_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
params->ctc_table = *table;
params->config_changed[IA_CSS_CTC_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_ctc_table(const struct ia_css_isp_parameters *params,
struct ia_css_ctc_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
*table = params->ctc_table;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_macc_table(struct ia_css_isp_parameters *params,
const struct ia_css_macc_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
params->macc_table = *table;
params->config_changed[IA_CSS_MACC_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_macc_table(const struct ia_css_isp_parameters *params,
struct ia_css_macc_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
*table = params->macc_table;
IA_CSS_LEAVE_PRIVATE("void");
}
void ia_css_morph_table_free(
struct ia_css_morph_table *me)
{
unsigned int i;
if (me == NULL)
return;
IA_CSS_ENTER("");
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
if (me->coordinates_x[i]) {
sh_css_free(me->coordinates_x[i]);
me->coordinates_x[i] = NULL;
}
if (me->coordinates_y[i]) {
sh_css_free(me->coordinates_y[i]);
me->coordinates_y[i] = NULL;
}
}
sh_css_free(me);
IA_CSS_LEAVE("void");
}
struct ia_css_morph_table *ia_css_morph_table_allocate(
unsigned int width,
unsigned int height)
{
unsigned int i;
struct ia_css_morph_table *me;
IA_CSS_ENTER("");
me = sh_css_malloc(sizeof(*me));
if (me == NULL) {
IA_CSS_ERROR("out of memory");
return me;
}
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
me->coordinates_x[i] = NULL;
me->coordinates_y[i] = NULL;
}
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
me->coordinates_x[i] =
sh_css_malloc(height * width *
sizeof(*me->coordinates_x[i]));
me->coordinates_y[i] =
sh_css_malloc(height * width *
sizeof(*me->coordinates_y[i]));
if ((me->coordinates_x[i] == NULL) ||
(me->coordinates_y[i] == NULL)) {
ia_css_morph_table_free(me);
me = NULL;
return me;
}
}
me->width = width;
me->height = height;
IA_CSS_LEAVE("");
return me;
}
static enum ia_css_err sh_css_params_default_morph_table(
struct ia_css_morph_table **table,
const struct ia_css_binary *binary)
{
unsigned int i, j, k, step, width, height;
short start_x[IA_CSS_MORPH_TABLE_NUM_PLANES] = { -8, 0, -8, 0, 0, -8 },
start_y[IA_CSS_MORPH_TABLE_NUM_PLANES] = { 0, 0, -8, -8, -8, 0 };
struct ia_css_morph_table *tab;
assert(table != NULL);
assert(binary != NULL);
IA_CSS_ENTER_PRIVATE("");
step = (ISP_VEC_NELEMS / 16) * 128,
width = binary->morph_tbl_width,
height = binary->morph_tbl_height;
tab = ia_css_morph_table_allocate(width, height);
if (tab == NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
short val_y = start_y[i];
for (j = 0; j < height; j++) {
short val_x = start_x[i];
unsigned short *x_ptr, *y_ptr;
x_ptr = &tab->coordinates_x[i][j * width];
y_ptr = &tab->coordinates_y[i][j * width];
for (k = 0; k < width;
k++, x_ptr++, y_ptr++, val_x += (short)step) {
if (k == 0)
*x_ptr = 0;
else if (k == width - 1)
*x_ptr = val_x + 2 * start_x[i];
else
*x_ptr = val_x;
if (j == 0)
*y_ptr = 0;
else
*y_ptr = val_y;
}
val_y += (short)step;
}
}
*table = tab;
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static void
sh_css_set_morph_table(struct ia_css_isp_parameters *params,
const struct ia_css_morph_table *table)
{
if (table == NULL)
return;
IA_CSS_ENTER_PRIVATE("table=%p", table);
assert(params != NULL);
if (table->enable == false)
table = NULL;
params->morph_table = table;
params->morph_table_changed = true;
IA_CSS_LEAVE_PRIVATE("void");
}
void
ia_css_translate_3a_statistics(
struct ia_css_3a_statistics *host_stats,
const struct ia_css_isp_3a_statistics_map *isp_stats)
{
IA_CSS_ENTER("");
if (host_stats->grid.use_dmem) {
IA_CSS_LOG("3A: DMEM");
ia_css_s3a_dmem_decode(host_stats, isp_stats->dmem_stats);
} else {
IA_CSS_LOG("3A: VMEM");
ia_css_s3a_vmem_decode(host_stats, isp_stats->vmem_stats_hi,
isp_stats->vmem_stats_lo);
}
#if !defined(HAS_NO_HMEM)
IA_CSS_LOG("3A: HMEM");
ia_css_s3a_hmem_decode(host_stats, isp_stats->hmem_stats);
#endif
IA_CSS_LEAVE("void");
}
void
ia_css_isp_3a_statistics_map_free(struct ia_css_isp_3a_statistics_map *me)
{
if (me) {
if (me->data_allocated) {
sh_css_free(me->data_ptr);
me->data_ptr = NULL;
me->data_allocated = false;
}
sh_css_free(me);
}
}
struct ia_css_isp_3a_statistics_map *
ia_css_isp_3a_statistics_map_allocate(
const struct ia_css_isp_3a_statistics *isp_stats,
void *data_ptr)
{
struct ia_css_isp_3a_statistics_map *me;
char *base_ptr;
me = sh_css_malloc(sizeof(*me));
if (!me) {
IA_CSS_LEAVE("cannot allocate memory");
goto err;
}
me->data_ptr = data_ptr;
me->data_allocated = data_ptr == NULL;
if (!data_ptr) {
me->data_ptr = sh_css_malloc(isp_stats->size);
if (!me->data_ptr) {
IA_CSS_LEAVE("cannot allocate memory");
goto err;
}
}
base_ptr = me->data_ptr;
me->size = isp_stats->size;
me->dmem_stats = (void *)base_ptr;
me->vmem_stats_hi = (void *)(base_ptr + isp_stats->dmem_size);
me->vmem_stats_lo = (void *)(base_ptr + isp_stats->dmem_size +
isp_stats->vmem_size);
me->hmem_stats = (void *)(base_ptr + isp_stats->dmem_size +
2 * isp_stats->vmem_size);
IA_CSS_LEAVE("map=%p", me);
return me;
err:
if (me)
sh_css_free(me);
return NULL;
}
enum ia_css_err
ia_css_get_3a_statistics(struct ia_css_3a_statistics *host_stats,
const struct ia_css_isp_3a_statistics *isp_stats)
{
struct ia_css_isp_3a_statistics_map *map;
enum ia_css_err ret = IA_CSS_SUCCESS;
IA_CSS_ENTER("host_stats=%p, isp_stats=%p", host_stats, isp_stats);
assert(host_stats != NULL);
assert(isp_stats != NULL);
map = ia_css_isp_3a_statistics_map_allocate(isp_stats, NULL);
if (map) {
mmgr_load(isp_stats->data_ptr, map->data_ptr, isp_stats->size);
ia_css_translate_3a_statistics(host_stats, map);
ia_css_isp_3a_statistics_map_free(map);
} else {
IA_CSS_ERROR("out of memory");
ret = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
IA_CSS_LEAVE_ERR(ret);
return ret;
}
static void
ia_css_set_param_exceptions(const struct ia_css_pipe *pipe,
struct ia_css_isp_parameters *params)
{
assert(params != NULL);
params->dp_config.gr = params->wb_config.gr;
params->dp_config.r = params->wb_config.r;
params->dp_config.b = params->wb_config.b;
params->dp_config.gb = params->wb_config.gb;
#ifdef ISP2401
assert(pipe != NULL);
assert(pipe->mode < IA_CSS_PIPE_ID_NUM);
if (pipe->mode < IA_CSS_PIPE_ID_NUM) {
params->pipe_dp_config[pipe->mode].gr = params->wb_config.gr;
params->pipe_dp_config[pipe->mode].r = params->wb_config.r;
params->pipe_dp_config[pipe->mode].b = params->wb_config.b;
params->pipe_dp_config[pipe->mode].gb = params->wb_config.gb;
}
#endif
}
static void
sh_css_set_dp_config(const struct ia_css_pipe *pipe,
struct ia_css_isp_parameters *params,
const struct ia_css_dp_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
assert(pipe != NULL);
assert(pipe->mode < IA_CSS_PIPE_ID_NUM);
IA_CSS_ENTER_PRIVATE("config=%p", config);
ia_css_dp_debug_dtrace(config, IA_CSS_DEBUG_TRACE_PRIVATE);
if (pipe->mode < IA_CSS_PIPE_ID_NUM) {
params->pipe_dp_config[pipe->mode] = *config;
params->pipe_dpc_config_changed[pipe->mode] = true;
}
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_dp_config(const struct ia_css_pipe *pipe,
const struct ia_css_isp_parameters *params,
struct ia_css_dp_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
assert(pipe != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
*config = params->pipe_dp_config[pipe->mode];
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_nr_config(struct ia_css_isp_parameters *params,
const struct ia_css_nr_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
ia_css_nr_debug_dtrace(config, IA_CSS_DEBUG_TRACE_PRIVATE);
params->nr_config = *config;
params->yee_config.nr = *config;
params->config_changed[IA_CSS_NR_ID] = true;
params->config_changed[IA_CSS_YEE_ID] = true;
params->config_changed[IA_CSS_BNR_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_ee_config(struct ia_css_isp_parameters *params,
const struct ia_css_ee_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
ia_css_ee_debug_dtrace(config, IA_CSS_DEBUG_TRACE_PRIVATE);
params->ee_config = *config;
params->yee_config.ee = *config;
params->config_changed[IA_CSS_YEE_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_ee_config(const struct ia_css_isp_parameters *params,
struct ia_css_ee_config *config)
{
if (config == NULL)
return;
IA_CSS_ENTER_PRIVATE("config=%p", config);
assert(params != NULL);
*config = params->ee_config;
ia_css_ee_debug_dtrace(config, IA_CSS_DEBUG_TRACE_PRIVATE);
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_pipe_dvs_6axis_config(const struct ia_css_pipe *pipe,
struct ia_css_isp_parameters *params,
const struct ia_css_dvs_6axis_config *dvs_config)
{
if (dvs_config == NULL)
return;
assert(params != NULL);
assert(pipe != NULL);
assert(dvs_config->height_y == dvs_config->height_uv);
assert((dvs_config->width_y - 1) == 2 * (dvs_config->width_uv - 1));
assert(pipe->mode < IA_CSS_PIPE_ID_NUM);
IA_CSS_ENTER_PRIVATE("dvs_config=%p", dvs_config);
copy_dvs_6axis_table(params->pipe_dvs_6axis_config[pipe->mode], dvs_config);
#if !defined(HAS_NO_DVS_6AXIS_CONFIG_UPDATE)
params->pipe_dvs_6axis_config_changed[pipe->mode] = true;
#endif
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_pipe_dvs_6axis_config(const struct ia_css_pipe *pipe,
const struct ia_css_isp_parameters *params,
struct ia_css_dvs_6axis_config *dvs_config)
{
if (dvs_config == NULL)
return;
assert(params != NULL);
assert(pipe != NULL);
assert(dvs_config->height_y == dvs_config->height_uv);
assert((dvs_config->width_y - 1) == 2 * dvs_config->width_uv - 1);
IA_CSS_ENTER_PRIVATE("dvs_config=%p", dvs_config);
if ((pipe->mode < IA_CSS_PIPE_ID_NUM) &&
(dvs_config->width_y == params->pipe_dvs_6axis_config[pipe->mode]->width_y) &&
(dvs_config->height_y == params->pipe_dvs_6axis_config[pipe->mode]->height_y) &&
(dvs_config->width_uv == params->pipe_dvs_6axis_config[pipe->mode]->width_uv) &&
(dvs_config->height_uv == params->pipe_dvs_6axis_config[pipe->mode]->height_uv) &&
dvs_config->xcoords_y &&
dvs_config->ycoords_y &&
dvs_config->xcoords_uv &&
dvs_config->ycoords_uv)
{
copy_dvs_6axis_table(dvs_config, params->pipe_dvs_6axis_config[pipe->mode]);
}
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_baa_config(struct ia_css_isp_parameters *params,
const struct ia_css_aa_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
params->bds_config = *config;
params->config_changed[IA_CSS_BDS_ID] = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_baa_config(const struct ia_css_isp_parameters *params,
struct ia_css_aa_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
*config = params->bds_config;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_set_dz_config(struct ia_css_isp_parameters *params,
const struct ia_css_dz_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("dx=%d, dy=%d", config->dx, config->dy);
assert(config->dx <= HRT_GDC_N);
assert(config->dy <= HRT_GDC_N);
params->dz_config = *config;
params->dz_config_changed = true;
params->isp_params_changed = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_dz_config(const struct ia_css_isp_parameters *params,
struct ia_css_dz_config *config)
{
if (config == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("config=%p", config);
*config = params->dz_config;
IA_CSS_LEAVE_PRIVATE("dx=%d, dy=%d", config->dx, config->dy);
}
static void
sh_css_set_motion_vector(struct ia_css_isp_parameters *params,
const struct ia_css_vector *motion)
{
if (motion == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("x=%d, y=%d", motion->x, motion->y);
params->motion_config = *motion;
params->motion_config_changed = true;
params->isp_params_changed = true;
IA_CSS_LEAVE_PRIVATE("void");
}
static void
sh_css_get_motion_vector(const struct ia_css_isp_parameters *params,
struct ia_css_vector *motion)
{
if (motion == NULL)
return;
assert(params != NULL);
IA_CSS_ENTER_PRIVATE("motion=%p", motion);
*motion = params->motion_config;
IA_CSS_LEAVE_PRIVATE("x=%d, y=%d", motion->x, motion->y);
}
struct ia_css_isp_config *
sh_css_pipe_isp_config_get(struct ia_css_pipe *pipe)
{
if (pipe == NULL)
{
IA_CSS_ERROR("pipe=%p", NULL);
return NULL;
}
return pipe->config.p_isp_config;
}
enum ia_css_err
ia_css_stream_set_isp_config(
struct ia_css_stream *stream,
const struct ia_css_isp_config *config)
{
return ia_css_stream_set_isp_config_on_pipe(stream, config, NULL);
}
enum ia_css_err
ia_css_stream_set_isp_config_on_pipe(
struct ia_css_stream *stream,
const struct ia_css_isp_config *config,
struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
if ((stream == NULL) || (config == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
IA_CSS_ENTER("stream=%p, config=%p, pipe=%p", stream, config, pipe);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
if (config->output_frame)
err = sh_css_set_per_frame_isp_config_on_pipe(stream, config, pipe);
else
#endif
err = sh_css_set_global_isp_config_on_pipe(stream->pipes[0], config, pipe);
IA_CSS_LEAVE_ERR(err);
return err;
}
enum ia_css_err
ia_css_pipe_set_isp_config(struct ia_css_pipe *pipe,
struct ia_css_isp_config *config)
{
struct ia_css_pipe *pipe_in = pipe;
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER("pipe=%p", pipe);
if ((pipe == NULL) || (pipe->stream == NULL))
return IA_CSS_ERR_INVALID_ARGUMENTS;
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "config=%p\n", config);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
if (config->output_frame)
err = sh_css_set_per_frame_isp_config_on_pipe(pipe->stream, config, pipe);
else
#endif
err = sh_css_set_global_isp_config_on_pipe(pipe, config, pipe_in);
IA_CSS_LEAVE_ERR(err);
return err;
}
static enum ia_css_err
sh_css_set_global_isp_config_on_pipe(
struct ia_css_pipe *curr_pipe,
const struct ia_css_isp_config *config,
struct ia_css_pipe *pipe)
{
enum ia_css_err err = IA_CSS_SUCCESS;
enum ia_css_err err1 = IA_CSS_SUCCESS;
enum ia_css_err err2 = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("stream=%p, config=%p, pipe=%p", curr_pipe, config, pipe);
err1 = sh_css_init_isp_params_from_config(curr_pipe, curr_pipe->stream->isp_params_configs, config, pipe);
err2 = sh_css_param_update_isp_params(curr_pipe, curr_pipe->stream->isp_params_configs, sh_css_sp_is_running(), pipe);
err = (err1 != IA_CSS_SUCCESS ) ? err1 : ((err2 != IA_CSS_SUCCESS) ? err2 : err);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_set_per_frame_isp_config_on_pipe(
struct ia_css_stream *stream,
const struct ia_css_isp_config *config,
struct ia_css_pipe *pipe)
{
unsigned i;
bool per_frame_config_created = false;
enum ia_css_err err = IA_CSS_SUCCESS;
enum ia_css_err err1 = IA_CSS_SUCCESS;
enum ia_css_err err2 = IA_CSS_SUCCESS;
enum ia_css_err err3 = IA_CSS_SUCCESS;
struct sh_css_ddr_address_map *ddr_ptrs;
struct sh_css_ddr_address_map_size *ddr_ptrs_size;
struct ia_css_isp_parameters *params;
IA_CSS_ENTER_PRIVATE("stream=%p, config=%p, pipe=%p", stream, config, pipe);
if (!pipe) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
goto exit;
}
if (!stream->per_frame_isp_params_configs)
{
err = sh_css_create_isp_params(stream,
&stream->per_frame_isp_params_configs);
if(err != IA_CSS_SUCCESS)
goto exit;
per_frame_config_created = true;
}
params = stream->per_frame_isp_params_configs;
if (!sh_css_init_isp_params_from_global(stream, params, false, pipe)) {
err1 = IA_CSS_ERR_INVALID_ARGUMENTS;
}
err2 = sh_css_init_isp_params_from_config(stream->pipes[0], params, config, pipe);
if (per_frame_config_created)
{
ddr_ptrs = &params->ddr_ptrs;
ddr_ptrs_size = &params->ddr_ptrs_size;
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
ref_sh_css_ddr_address_map(ddr_ptrs, &params->pipe_ddr_ptrs[i]);
params->pipe_ddr_ptrs_size[i] = *ddr_ptrs_size;
}
}
err3 = sh_css_param_update_isp_params(stream->pipes[0], params, sh_css_sp_is_running(), pipe);
err = (err1 != IA_CSS_SUCCESS) ? err1 :
(err2 != IA_CSS_SUCCESS) ? err2 :
(err3 != IA_CSS_SUCCESS) ? err3 : err;
exit:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_init_isp_params_from_config(struct ia_css_pipe *pipe,
struct ia_css_isp_parameters *params,
const struct ia_css_isp_config *config,
struct ia_css_pipe *pipe_in)
{
enum ia_css_err err = IA_CSS_SUCCESS;
bool is_dp_10bpp = true;
assert(pipe != NULL);
IA_CSS_ENTER_PRIVATE("pipe=%p, config=%p, params=%p", pipe, config, params);
ia_css_set_configs(params, config);
sh_css_set_nr_config(params, config->nr_config);
sh_css_set_ee_config(params, config->ee_config);
sh_css_set_baa_config(params, config->baa_config);
if ((pipe->mode < IA_CSS_PIPE_ID_NUM) &&
(params->pipe_dvs_6axis_config[pipe->mode]))
sh_css_set_pipe_dvs_6axis_config(pipe, params, config->dvs_6axis_config);
sh_css_set_dz_config(params, config->dz_config);
sh_css_set_motion_vector(params, config->motion_vector);
sh_css_update_shading_table_status(pipe_in, params);
sh_css_set_shading_table(pipe->stream, params, config->shading_table);
sh_css_set_morph_table(params, config->morph_table);
sh_css_set_macc_table(params, config->macc_table);
sh_css_set_gamma_table(params, config->gamma_table);
sh_css_set_ctc_table(params, config->ctc_table);
sh_css_set_shading_settings(params, config->shading_settings);
params->dis_coef_table_changed = (config->dvs_coefs != NULL);
params->dvs2_coef_table_changed = (config->dvs2_coefs != NULL);
params->output_frame = config->output_frame;
params->isp_parameters_id = config->isp_config_id;
#ifdef ISP2401
sh_css_set_dp_config(pipe, params, config->dp_config);
ia_css_set_param_exceptions(pipe, params);
#endif
if (IA_CSS_SUCCESS ==
sh_css_select_dp_10bpp_config(pipe, &is_dp_10bpp)) {
if(is_dp_10bpp) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
} else {
err = IA_CSS_ERR_INTERNAL_ERROR;
goto exit;
}
#ifndef ISP2401
ia_css_set_param_exceptions(pipe, params);
#endif
exit:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
void
ia_css_stream_get_isp_config(
const struct ia_css_stream *stream,
struct ia_css_isp_config *config)
{
IA_CSS_ENTER("void");
ia_css_pipe_get_isp_config(stream->pipes[0], config);
IA_CSS_LEAVE("void");
}
void
ia_css_pipe_get_isp_config(struct ia_css_pipe *pipe,
struct ia_css_isp_config *config)
{
struct ia_css_isp_parameters *params = NULL;
assert(config != NULL);
IA_CSS_ENTER("config=%p", config);
params = pipe->stream->isp_params_configs;
assert(params != NULL);
ia_css_get_configs(params, config);
sh_css_get_ee_config(params, config->ee_config);
sh_css_get_baa_config(params, config->baa_config);
sh_css_get_pipe_dvs_6axis_config(pipe, params, config->dvs_6axis_config);
sh_css_get_dp_config(pipe, params, config->dp_config);
sh_css_get_macc_table(params, config->macc_table);
sh_css_get_gamma_table(params, config->gamma_table);
sh_css_get_ctc_table(params, config->ctc_table);
sh_css_get_dz_config(params, config->dz_config);
sh_css_get_motion_vector(params, config->motion_vector);
sh_css_get_shading_settings(params, config->shading_settings);
config->output_frame = params->output_frame;
config->isp_config_id = params->isp_parameters_id;
IA_CSS_LEAVE("void");
}
static bool realloc_isp_css_mm_buf(
hrt_vaddress *curr_buf,
size_t *curr_size,
size_t needed_size,
bool force,
enum ia_css_err *err,
uint16_t mmgr_attribute)
{
int32_t id;
*err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("void");
if (!force && *curr_size >= needed_size) {
IA_CSS_LEAVE_PRIVATE("false");
return false;
}
if (*curr_size == needed_size && ia_css_refcount_is_single(*curr_buf)) {
IA_CSS_LEAVE_PRIVATE("false");
return false;
}
id = IA_CSS_REFCOUNT_PARAM_BUFFER;
ia_css_refcount_decrement(id, *curr_buf);
*curr_buf = ia_css_refcount_increment(id, mmgr_alloc_attr(needed_size,
mmgr_attribute));
if (!*curr_buf) {
*err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
*curr_size = 0;
} else {
*curr_size = needed_size;
}
IA_CSS_LEAVE_PRIVATE("true");
return true;
}
static bool reallocate_buffer(
hrt_vaddress *curr_buf,
size_t *curr_size,
size_t needed_size,
bool force,
enum ia_css_err *err)
{
bool ret;
uint16_t mmgr_attribute = MMGR_ATTRIBUTE_DEFAULT;
IA_CSS_ENTER_PRIVATE("void");
ret = realloc_isp_css_mm_buf(curr_buf,
curr_size, needed_size, force, err, mmgr_attribute);
IA_CSS_LEAVE_PRIVATE("ret=%d", ret);
return ret;
}
struct ia_css_isp_3a_statistics *
ia_css_isp_3a_statistics_allocate(const struct ia_css_3a_grid_info *grid)
{
struct ia_css_isp_3a_statistics *me;
IA_CSS_ENTER("grid=%p", grid);
assert(grid != NULL);
if (!grid->enable)
return NULL;
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
if (grid->use_dmem) {
me->dmem_size = sizeof(struct ia_css_3a_output) *
grid->aligned_width *
grid->aligned_height;
} else {
me->vmem_size = ISP_S3ATBL_HI_LO_STRIDE_BYTES *
grid->aligned_height;
}
#if !defined(HAS_NO_HMEM)
me->hmem_size = sizeof_hmem(HMEM0_ID);
#endif
me->dmem_size = CEIL_MUL(me->dmem_size, HIVE_ISP_DDR_WORD_BYTES);
me->vmem_size = CEIL_MUL(me->vmem_size, HIVE_ISP_DDR_WORD_BYTES);
me->hmem_size = CEIL_MUL(me->hmem_size, HIVE_ISP_DDR_WORD_BYTES);
me->size = me->dmem_size + me->vmem_size * 2 + me->hmem_size;
me->data_ptr = mmgr_malloc(me->size);
if (me->data_ptr == mmgr_NULL) {
sh_css_free(me);
me = NULL;
goto err;
}
if (me->dmem_size)
me->data.dmem.s3a_tbl = me->data_ptr;
if (me->vmem_size) {
me->data.vmem.s3a_tbl_hi = me->data_ptr + me->dmem_size;
me->data.vmem.s3a_tbl_lo = me->data_ptr + me->dmem_size + me->vmem_size;
}
if (me->hmem_size)
me->data_hmem.rgby_tbl = me->data_ptr + me->dmem_size + 2 * me->vmem_size;
err:
IA_CSS_LEAVE("return=%p", me);
return me;
}
void
ia_css_isp_3a_statistics_free(struct ia_css_isp_3a_statistics *me)
{
if (me != NULL) {
hmm_free(me->data_ptr);
sh_css_free(me);
}
}
struct ia_css_isp_skc_dvs_statistics *ia_css_skc_dvs_statistics_allocate(void)
{
return NULL;
}
struct ia_css_metadata *
ia_css_metadata_allocate(const struct ia_css_metadata_info *metadata_info)
{
struct ia_css_metadata *md = NULL;
IA_CSS_ENTER("");
if (metadata_info->size == 0)
return NULL;
md = sh_css_malloc(sizeof(*md));
if (md == NULL)
goto error;
md->info = *metadata_info;
md->exp_id = 0;
md->address = mmgr_malloc(metadata_info->size);
if (md->address == mmgr_NULL)
goto error;
IA_CSS_LEAVE("return=%p", md);
return md;
error:
ia_css_metadata_free(md);
IA_CSS_LEAVE("return=%p", NULL);
return NULL;
}
void
ia_css_metadata_free(struct ia_css_metadata *me)
{
if (me != NULL) {
IA_CSS_ENTER("me=%p", me);
hmm_free(me->address);
sh_css_free(me);
IA_CSS_LEAVE("void");
}
}
void
ia_css_metadata_free_multiple(unsigned int num_bufs, struct ia_css_metadata **bufs)
{
unsigned int i;
if (bufs != NULL) {
for (i = 0; i < num_bufs; i++)
ia_css_metadata_free(bufs[i]);
}
}
enum ia_css_err
ia_css_stream_isp_parameters_init(struct ia_css_stream *stream)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned i;
struct sh_css_ddr_address_map *ddr_ptrs;
struct sh_css_ddr_address_map_size *ddr_ptrs_size;
struct ia_css_isp_parameters *params;
assert(stream != NULL);
IA_CSS_ENTER_PRIVATE("void");
if (stream == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_INVALID_ARGUMENTS);
return IA_CSS_ERR_INVALID_ARGUMENTS;
}
g_param_buffer_dequeue_count = 0;
g_param_buffer_enqueue_count = 0;
stream->per_frame_isp_params_configs = NULL;
err = sh_css_create_isp_params(stream,
&stream->isp_params_configs);
if(err != IA_CSS_SUCCESS)
goto ERR;
params = stream->isp_params_configs;
if (!sh_css_init_isp_params_from_global(stream, params, true, NULL)) {
err = IA_CSS_ERR_INVALID_ARGUMENTS;
}
ddr_ptrs = &params->ddr_ptrs;
ddr_ptrs_size = &params->ddr_ptrs_size;
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
ref_sh_css_ddr_address_map(ddr_ptrs, &params->pipe_ddr_ptrs[i]);
params->pipe_ddr_ptrs_size[i] = *ddr_ptrs_size;
}
ERR:
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static void
ia_css_set_sdis_config(
struct ia_css_isp_parameters *params,
const struct ia_css_dvs_coefficients *dvs_coefs)
{
ia_css_set_sdis_horicoef_config(params, dvs_coefs);
ia_css_set_sdis_vertcoef_config(params, dvs_coefs);
ia_css_set_sdis_horiproj_config(params, dvs_coefs);
ia_css_set_sdis_vertproj_config(params, dvs_coefs);
}
static void
ia_css_set_sdis2_config(
struct ia_css_isp_parameters *params,
const struct ia_css_dvs2_coefficients *dvs2_coefs)
{
ia_css_set_sdis2_horicoef_config(params, dvs2_coefs);
ia_css_set_sdis2_vertcoef_config(params, dvs2_coefs);
ia_css_set_sdis2_horiproj_config(params, dvs2_coefs);
ia_css_set_sdis2_vertproj_config(params, dvs2_coefs);
}
static enum ia_css_err
sh_css_create_isp_params(struct ia_css_stream *stream,
struct ia_css_isp_parameters **isp_params_out)
{
bool succ = true;
unsigned i;
struct sh_css_ddr_address_map *ddr_ptrs;
struct sh_css_ddr_address_map_size *ddr_ptrs_size;
enum ia_css_err err = IA_CSS_SUCCESS;
size_t params_size;
struct ia_css_isp_parameters *params =
sh_css_malloc(sizeof(struct ia_css_isp_parameters));
if (!params)
{
*isp_params_out = NULL;
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_ERROR("%s:%d error: cannot allocate memory", __FILE__, __LINE__);
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
} else {
memset(params, 0, sizeof(struct ia_css_isp_parameters));
}
ddr_ptrs = &params->ddr_ptrs;
ddr_ptrs_size = &params->ddr_ptrs_size;
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
memset(&params->pipe_ddr_ptrs[i], 0,
sizeof(params->pipe_ddr_ptrs[i]));
memset(&params->pipe_ddr_ptrs_size[i], 0,
sizeof(params->pipe_ddr_ptrs_size[i]));
}
memset(ddr_ptrs, 0, sizeof(*ddr_ptrs));
memset(ddr_ptrs_size, 0, sizeof(*ddr_ptrs_size));
params_size = sizeof(params->uds);
ddr_ptrs_size->isp_param = params_size;
ddr_ptrs->isp_param =
ia_css_refcount_increment(IA_CSS_REFCOUNT_PARAM_BUFFER,
mmgr_malloc(params_size));
succ &= (ddr_ptrs->isp_param != mmgr_NULL);
ddr_ptrs_size->macc_tbl = sizeof(struct ia_css_macc_table);
ddr_ptrs->macc_tbl =
ia_css_refcount_increment(IA_CSS_REFCOUNT_PARAM_BUFFER,
mmgr_malloc(sizeof(struct ia_css_macc_table)));
succ &= (ddr_ptrs->macc_tbl != mmgr_NULL);
*isp_params_out = params;
return err;
}
static bool
sh_css_init_isp_params_from_global(struct ia_css_stream *stream,
struct ia_css_isp_parameters *params,
bool use_default_config,
struct ia_css_pipe *pipe_in)
{
bool retval = true;
int i = 0;
bool is_dp_10bpp = true;
unsigned isp_pipe_version = ia_css_pipe_get_isp_pipe_version(stream->pipes[0]);
struct ia_css_isp_parameters *stream_params = stream->isp_params_configs;
if (!use_default_config && !stream_params) {
retval = false;
goto exit;
}
params->output_frame = NULL;
params->isp_parameters_id = 0;
if (use_default_config)
{
ia_css_set_xnr3_config(params, &default_xnr3_config);
sh_css_set_nr_config(params, &default_nr_config);
sh_css_set_ee_config(params, &default_ee_config);
if (isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_1)
sh_css_set_macc_table(params, &default_macc_table);
else if (isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_2_2)
sh_css_set_macc_table(params, &default_macc2_table);
sh_css_set_gamma_table(params, &default_gamma_table);
sh_css_set_ctc_table(params, &default_ctc_table);
sh_css_set_baa_config(params, &default_baa_config);
sh_css_set_dz_config(params, &default_dz_config);
sh_css_set_shading_settings(params, &default_shading_settings);
ia_css_set_s3a_config(params, &default_3a_config);
ia_css_set_wb_config(params, &default_wb_config);
ia_css_set_csc_config(params, &default_cc_config);
ia_css_set_tnr_config(params, &default_tnr_config);
ia_css_set_ob_config(params, &default_ob_config);
ia_css_set_dp_config(params, &default_dp_config);
#ifndef ISP2401
ia_css_set_param_exceptions(pipe_in, params);
#else
for (i = 0; i < stream->num_pipes; i++) {
if (IA_CSS_SUCCESS == sh_css_select_dp_10bpp_config(stream->pipes[i], &is_dp_10bpp)) {
if(is_dp_10bpp) {
sh_css_set_dp_config(stream->pipes[i], params, &default_dp_10bpp_config);
} else {
sh_css_set_dp_config(stream->pipes[i], params, &default_dp_config);
}
} else {
retval = false;
goto exit;
}
ia_css_set_param_exceptions(stream->pipes[i], params);
}
#endif
ia_css_set_de_config(params, &default_de_config);
ia_css_set_gc_config(params, &default_gc_config);
ia_css_set_anr_config(params, &default_anr_config);
ia_css_set_anr2_config(params, &default_anr_thres);
ia_css_set_ce_config(params, &default_ce_config);
ia_css_set_xnr_table_config(params, &default_xnr_table);
ia_css_set_ecd_config(params, &default_ecd_config);
ia_css_set_ynr_config(params, &default_ynr_config);
ia_css_set_fc_config(params, &default_fc_config);
ia_css_set_cnr_config(params, &default_cnr_config);
ia_css_set_macc_config(params, &default_macc_config);
ia_css_set_ctc_config(params, &default_ctc_config);
ia_css_set_aa_config(params, &default_aa_config);
ia_css_set_r_gamma_config(params, &default_r_gamma_table);
ia_css_set_g_gamma_config(params, &default_g_gamma_table);
ia_css_set_b_gamma_config(params, &default_b_gamma_table);
ia_css_set_yuv2rgb_config(params, &default_yuv2rgb_cc_config);
ia_css_set_rgb2yuv_config(params, &default_rgb2yuv_cc_config);
ia_css_set_xnr_config(params, &default_xnr_config);
ia_css_set_sdis_config(params, &default_sdis_config);
ia_css_set_sdis2_config(params, &default_sdis2_config);
ia_css_set_formats_config(params, &default_formats_config);
params->fpn_config.data = NULL;
params->config_changed[IA_CSS_FPN_ID] = true;
params->fpn_config.enabled = 0;
params->motion_config = default_motion_config;
params->motion_config_changed = true;
params->morph_table = NULL;
params->morph_table_changed = true;
params->sc_table = NULL;
params->sc_table_changed = true;
params->sc_table_dirty = false;
params->sc_table_last_pipe_num = 0;
ia_css_sdis2_clear_coefficients(&params->dvs2_coefs);
params->dvs2_coef_table_changed = true;
ia_css_sdis_clear_coefficients(&params->dvs_coefs);
params->dis_coef_table_changed = true;
#ifdef ISP2401
ia_css_tnr3_set_default_config(&params->tnr3_config);
#endif
}
else
{
ia_css_set_xnr3_config(params, &stream_params->xnr3_config);
sh_css_set_nr_config(params, &stream_params->nr_config);
sh_css_set_ee_config(params, &stream_params->ee_config);
if (isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_1)
sh_css_set_macc_table(params, &stream_params->macc_table);
else if (isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_2_2)
sh_css_set_macc_table(params, &stream_params->macc_table);
sh_css_set_gamma_table(params, &stream_params->gc_table);
sh_css_set_ctc_table(params, &stream_params->ctc_table);
sh_css_set_baa_config(params, &stream_params->bds_config);
sh_css_set_dz_config(params, &stream_params->dz_config);
sh_css_set_shading_settings(params, &stream_params->shading_settings);
ia_css_set_s3a_config(params, &stream_params->s3a_config);
ia_css_set_wb_config(params, &stream_params->wb_config);
ia_css_set_csc_config(params, &stream_params->cc_config);
ia_css_set_tnr_config(params, &stream_params->tnr_config);
ia_css_set_ob_config(params, &stream_params->ob_config);
ia_css_set_dp_config(params, &stream_params->dp_config);
ia_css_set_de_config(params, &stream_params->de_config);
ia_css_set_gc_config(params, &stream_params->gc_config);
ia_css_set_anr_config(params, &stream_params->anr_config);
ia_css_set_anr2_config(params, &stream_params->anr_thres);
ia_css_set_ce_config(params, &stream_params->ce_config);
ia_css_set_xnr_table_config(params, &stream_params->xnr_table);
ia_css_set_ecd_config(params, &stream_params->ecd_config);
ia_css_set_ynr_config(params, &stream_params->ynr_config);
ia_css_set_fc_config(params, &stream_params->fc_config);
ia_css_set_cnr_config(params, &stream_params->cnr_config);
ia_css_set_macc_config(params, &stream_params->macc_config);
ia_css_set_ctc_config(params, &stream_params->ctc_config);
ia_css_set_aa_config(params, &stream_params->aa_config);
ia_css_set_r_gamma_config(params, &stream_params->r_gamma_table);
ia_css_set_g_gamma_config(params, &stream_params->g_gamma_table);
ia_css_set_b_gamma_config(params, &stream_params->b_gamma_table);
ia_css_set_yuv2rgb_config(params, &stream_params->yuv2rgb_cc_config);
ia_css_set_rgb2yuv_config(params, &stream_params->rgb2yuv_cc_config);
ia_css_set_xnr_config(params, &stream_params->xnr_config);
ia_css_set_formats_config(params, &stream_params->formats_config);
for (i = 0; i < stream->num_pipes; i++) {
if (IA_CSS_SUCCESS ==
sh_css_select_dp_10bpp_config(stream->pipes[i], &is_dp_10bpp)) {
#ifndef ISP2401
retval = !is_dp_10bpp;
#else
if (is_dp_10bpp) {
retval = false;
}
} else {
retval = false;
goto exit;
}
if (stream->pipes[i]->mode < IA_CSS_PIPE_ID_NUM) {
sh_css_set_dp_config(stream->pipes[i], params,
&stream_params->pipe_dp_config[stream->pipes[i]->mode]);
ia_css_set_param_exceptions(stream->pipes[i], params);
#endif
} else {
retval = false;
goto exit;
}
}
#ifndef ISP2401
ia_css_set_param_exceptions(pipe_in, params);
#endif
params->fpn_config.data = stream_params->fpn_config.data;
params->config_changed[IA_CSS_FPN_ID] = stream_params->config_changed[IA_CSS_FPN_ID];
params->fpn_config.enabled = stream_params->fpn_config.enabled;
sh_css_set_motion_vector(params, &stream_params->motion_config);
sh_css_set_morph_table(params, stream_params->morph_table);
if (stream_params->sc_table) {
sh_css_update_shading_table_status(pipe_in, params);
sh_css_set_shading_table(stream, params, stream_params->sc_table);
}
else {
params->sc_table = NULL;
params->sc_table_changed = true;
params->sc_table_dirty = false;
params->sc_table_last_pipe_num = 0;
}
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
if (stream_params->pipe_dvs_6axis_config[i]) {
if (params->pipe_dvs_6axis_config[i]) {
copy_dvs_6axis_table(params->pipe_dvs_6axis_config[i],
stream_params->pipe_dvs_6axis_config[i]);
} else {
params->pipe_dvs_6axis_config[i] =
generate_dvs_6axis_table_from_config(stream_params->pipe_dvs_6axis_config[i]);
}
}
}
ia_css_set_sdis_config(params, &stream_params->dvs_coefs);
params->dis_coef_table_changed = stream_params->dis_coef_table_changed;
ia_css_set_sdis2_config(params, &stream_params->dvs2_coefs);
params->dvs2_coef_table_changed = stream_params->dvs2_coef_table_changed;
params->sensor_binning = stream_params->sensor_binning;
}
exit:
return retval;
}
enum ia_css_err
sh_css_params_init(void)
{
int i, p;
IA_CSS_ENTER_PRIVATE("void");
g_param_buffer_dequeue_count = 0;
g_param_buffer_enqueue_count = 0;
for (p = 0; p < IA_CSS_PIPE_ID_NUM; p++) {
for (i = 0; i < SH_CSS_MAX_STAGES; i++) {
xmem_sp_stage_ptrs[p][i] =
ia_css_refcount_increment(-1,
mmgr_calloc(1,
sizeof(struct sh_css_sp_stage)));
xmem_isp_stage_ptrs[p][i] =
ia_css_refcount_increment(-1,
mmgr_calloc(1,
sizeof(struct sh_css_isp_stage)));
if ((xmem_sp_stage_ptrs[p][i] == mmgr_NULL) ||
(xmem_isp_stage_ptrs[p][i] == mmgr_NULL)) {
sh_css_params_uninit();
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
}
}
ia_css_config_gamma_table();
ia_css_config_ctc_table();
ia_css_config_rgb_gamma_tables();
ia_css_config_xnr_table();
sp_ddr_ptrs = ia_css_refcount_increment(-1, mmgr_calloc(1,
CEIL_MUL(sizeof(struct sh_css_ddr_address_map),
HIVE_ISP_DDR_WORD_BYTES)));
xmem_sp_group_ptrs = ia_css_refcount_increment(-1, mmgr_calloc(1,
sizeof(struct sh_css_sp_group)));
if ((sp_ddr_ptrs == mmgr_NULL) ||
(xmem_sp_group_ptrs == mmgr_NULL)) {
ia_css_uninit();
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
static void host_lut_store(const void *lut)
{
unsigned i;
for (i = 0; i < N_GDC_ID; i++)
gdc_lut_store((gdc_ID_t)i, (const int (*)[HRT_GDC_N]) lut);
}
inline hrt_vaddress sh_css_params_alloc_gdc_lut(void)
{
return mmgr_malloc(sizeof(zoom_table));
}
inline void sh_css_params_free_gdc_lut(hrt_vaddress addr)
{
if (addr != mmgr_NULL)
hmm_free(addr);
}
hrt_vaddress sh_css_pipe_get_pp_gdc_lut(const struct ia_css_pipe *pipe)
{
assert(pipe != NULL);
if (pipe->scaler_pp_lut != mmgr_NULL)
return pipe->scaler_pp_lut;
else
return sh_css_params_get_default_gdc_lut();
}
enum ia_css_err sh_css_params_map_and_store_default_gdc_lut(void)
{
enum ia_css_err err = IA_CSS_SUCCESS;
IA_CSS_ENTER_PRIVATE("void");
if (default_gdc_lut != mmgr_NULL)
return err;
host_lut_store((void *)zoom_table);
#ifndef ISP2401
default_gdc_lut = mmgr_malloc(sizeof(zoom_table));
#else
default_gdc_lut = sh_css_params_alloc_gdc_lut();
#endif
if (default_gdc_lut == mmgr_NULL)
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
gdc_lut_convert_to_isp_format((const int(*)[HRT_GDC_N])zoom_table,
interleaved_lut_temp);
mmgr_store(default_gdc_lut, (int *)interleaved_lut_temp,
sizeof(zoom_table));
IA_CSS_LEAVE_PRIVATE("lut(%p) err=%d", default_gdc_lut, err);
return err;
}
void sh_css_params_free_default_gdc_lut(void)
{
IA_CSS_ENTER_PRIVATE("void");
#ifndef ISP2401
if (default_gdc_lut != mmgr_NULL) {
hmm_free(default_gdc_lut);
default_gdc_lut = mmgr_NULL;
}
#else
sh_css_params_free_gdc_lut(default_gdc_lut);
default_gdc_lut = mmgr_NULL;
#endif
IA_CSS_LEAVE_PRIVATE("void");
}
hrt_vaddress sh_css_params_get_default_gdc_lut(void)
{
return default_gdc_lut;
}
static void free_param_set_callback(
hrt_vaddress ptr)
{
IA_CSS_ENTER_PRIVATE("void");
free_ia_css_isp_parameter_set_info(ptr);
IA_CSS_LEAVE_PRIVATE("void");
}
static void free_buffer_callback(
hrt_vaddress ptr)
{
IA_CSS_ENTER_PRIVATE("void");
hmm_free(ptr);
IA_CSS_LEAVE_PRIVATE("void");
}
void
sh_css_param_clear_param_sets(void)
{
IA_CSS_ENTER_PRIVATE("void");
ia_css_refcount_clear(IA_CSS_REFCOUNT_PARAM_SET_POOL, &free_param_set_callback);
IA_CSS_LEAVE_PRIVATE("void");
}
static void free_map(struct sh_css_ddr_address_map *map)
{
unsigned int i;
hrt_vaddress *addrs = (hrt_vaddress *)map;
IA_CSS_ENTER_PRIVATE("void");
for (i = 0; i < (sizeof(struct sh_css_ddr_address_map_size)/
sizeof(size_t)); i++) {
if (addrs[i] == mmgr_NULL)
continue;
safe_free(IA_CSS_REFCOUNT_PARAM_BUFFER, addrs[i]);
}
IA_CSS_LEAVE_PRIVATE("void");
}
void
ia_css_stream_isp_parameters_uninit(struct ia_css_stream *stream)
{
int i;
struct ia_css_isp_parameters *params = stream->isp_params_configs;
struct ia_css_isp_parameters *per_frame_params =
stream->per_frame_isp_params_configs;
IA_CSS_ENTER_PRIVATE("void");
if (params == NULL) {
IA_CSS_LEAVE_PRIVATE("isp_param_configs is NULL");
return;
}
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++)
{
free_map(&params->pipe_ddr_ptrs[i]);
if (per_frame_params)
free_map(&per_frame_params->pipe_ddr_ptrs[i]);
if (params->pipe_dvs_6axis_config[i])
free_dvs_6axis_table(&(params->pipe_dvs_6axis_config[i]));
if (per_frame_params && per_frame_params->pipe_dvs_6axis_config[i])
free_dvs_6axis_table(&(per_frame_params->pipe_dvs_6axis_config[i]));
}
free_map(&params->ddr_ptrs);
if (per_frame_params)
free_map(&per_frame_params->ddr_ptrs);
if (params->fpn_config.data) {
sh_css_free(params->fpn_config.data);
params->fpn_config.data = NULL;
}
if (params->sc_config) {
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
if (per_frame_params) {
if (per_frame_params->sc_config) {
ia_css_shading_table_free(per_frame_params->sc_config);
per_frame_params->sc_config = NULL;
}
}
sh_css_free(params);
if (per_frame_params)
sh_css_free(per_frame_params);
stream->isp_params_configs = NULL;
stream->per_frame_isp_params_configs = NULL;
IA_CSS_LEAVE_PRIVATE("void");
}
void
sh_css_params_uninit(void)
{
unsigned p, i;
IA_CSS_ENTER_PRIVATE("void");
ia_css_refcount_decrement(-1, sp_ddr_ptrs);
sp_ddr_ptrs = mmgr_NULL;
ia_css_refcount_decrement(-1, xmem_sp_group_ptrs);
xmem_sp_group_ptrs = mmgr_NULL;
for (p = 0; p < IA_CSS_PIPE_ID_NUM; p++)
for (i = 0; i < SH_CSS_MAX_STAGES; i++) {
ia_css_refcount_decrement(-1, xmem_sp_stage_ptrs[p][i]);
xmem_sp_stage_ptrs[p][i] = mmgr_NULL;
ia_css_refcount_decrement(-1, xmem_isp_stage_ptrs[p][i]);
xmem_isp_stage_ptrs[p][i] = mmgr_NULL;
}
ia_css_refcount_clear(IA_CSS_REFCOUNT_PARAM_SET_POOL, &free_param_set_callback);
ia_css_refcount_clear(IA_CSS_REFCOUNT_PARAM_BUFFER, &free_buffer_callback);
ia_css_refcount_clear(-1, &free_buffer_callback);
IA_CSS_LEAVE_PRIVATE("void");
}
static struct ia_css_host_data *
convert_allocate_morph_plane(
unsigned short *data,
unsigned int width,
unsigned int height,
unsigned int aligned_width)
{
unsigned int i, j, padding, w;
struct ia_css_host_data *me;
unsigned int isp_data_size;
uint16_t *isp_data_ptr;
IA_CSS_ENTER_PRIVATE("void");
if (width > aligned_width) {
padding = 0;
w = aligned_width;
} else {
padding = aligned_width - width;
w = width;
}
isp_data_size = height * (w + padding) * sizeof(uint16_t);
me = ia_css_host_data_allocate((size_t) isp_data_size);
if (!me) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return NULL;
}
isp_data_ptr = (uint16_t *)me->address;
memset(isp_data_ptr, 0, (size_t)isp_data_size);
for (i = 0; i < height; i++) {
for (j = 0; j < w; j++)
*isp_data_ptr++ = (uint16_t)data[j];
isp_data_ptr += padding;
data += width;
}
IA_CSS_LEAVE_PRIVATE("void");
return me;
}
static enum ia_css_err
store_morph_plane(
unsigned short *data,
unsigned int width,
unsigned int height,
hrt_vaddress dest,
unsigned int aligned_width)
{
struct ia_css_host_data *isp_data;
assert(dest != mmgr_NULL);
isp_data = convert_allocate_morph_plane(data, width, height, aligned_width);
if (!isp_data) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
ia_css_params_store_ia_css_host_data(dest, isp_data);
ia_css_host_data_free(isp_data);
return IA_CSS_SUCCESS;
}
static void sh_css_update_isp_params_to_ddr(
struct ia_css_isp_parameters *params,
hrt_vaddress ddr_ptr)
{
size_t size = sizeof(params->uds);
IA_CSS_ENTER_PRIVATE("void");
assert(params != NULL);
mmgr_store(ddr_ptr, &(params->uds), size);
IA_CSS_LEAVE_PRIVATE("void");
}
static void sh_css_update_isp_mem_params_to_ddr(
const struct ia_css_binary *binary,
hrt_vaddress ddr_mem_ptr,
size_t size,
enum ia_css_isp_memories mem)
{
const struct ia_css_host_data *params;
IA_CSS_ENTER_PRIVATE("void");
params = ia_css_isp_param_get_mem_init(&binary->mem_params, IA_CSS_PARAM_CLASS_PARAM, mem);
mmgr_store(ddr_mem_ptr, params->address, size);
IA_CSS_LEAVE_PRIVATE("void");
}
void ia_css_dequeue_param_buffers( void)
{
unsigned int i;
hrt_vaddress cpy;
enum sh_css_queue_id param_queue_ids[3] = { IA_CSS_PARAMETER_SET_QUEUE_ID,
IA_CSS_PER_FRAME_PARAMETER_SET_QUEUE_ID,
SH_CSS_INVALID_QUEUE_ID};
IA_CSS_ENTER_PRIVATE("void");
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_PRIVATE("sp is not running");
return;
}
for (i = 0; SH_CSS_INVALID_QUEUE_ID != param_queue_ids[i]; i++) {
cpy = (hrt_vaddress)0;
while (IA_CSS_SUCCESS == ia_css_bufq_dequeue_buffer(param_queue_ids[i], (uint32_t *)&cpy)) {
g_param_buffer_dequeue_count++;
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_DEQUEUED,
0,
param_queue_ids[i],
0);
IA_CSS_LOG("dequeued param set %x from %d, release ref", cpy, 0);
free_ia_css_isp_parameter_set_info(cpy);
cpy = (hrt_vaddress)0;
}
}
IA_CSS_LEAVE_PRIVATE("void");
}
static void
process_kernel_parameters(unsigned int pipe_id,
struct ia_css_pipeline_stage *stage,
struct ia_css_isp_parameters *params,
unsigned int isp_pipe_version,
unsigned int raw_bit_depth)
{
unsigned param_id;
(void)isp_pipe_version;
(void)raw_bit_depth;
sh_css_enable_pipeline(stage->binary);
if (params->config_changed[IA_CSS_OB_ID]) {
ia_css_ob_configure(&params->stream_configs.ob,
isp_pipe_version, raw_bit_depth);
}
if (params->config_changed[IA_CSS_S3A_ID]) {
ia_css_s3a_configure(raw_bit_depth);
}
params->crop_config.crop_pos = params->uds[stage->stage_num].crop_pos;
params->uds_config.crop_pos = params->uds[stage->stage_num].crop_pos;
params->uds_config.uds = params->uds[stage->stage_num].uds;
for (param_id = 0; param_id < IA_CSS_NUM_PARAMETER_IDS; param_id++) {
if (param_id == IA_CSS_SC_ID) continue;
if (params->config_changed[param_id])
ia_css_kernel_process_param[param_id](pipe_id, stage, params);
}
}
enum ia_css_err
sh_css_param_update_isp_params(struct ia_css_pipe *curr_pipe,
struct ia_css_isp_parameters *params,
bool commit,
struct ia_css_pipe *pipe_in)
{
enum ia_css_err err = IA_CSS_SUCCESS;
hrt_vaddress cpy;
int i;
unsigned int raw_bit_depth = 10;
unsigned int isp_pipe_version = SH_CSS_ISP_PIPE_VERSION_1;
bool acc_cluster_params_changed = false;
unsigned int thread_id, pipe_num;
(void)acc_cluster_params_changed;
assert(curr_pipe != NULL);
IA_CSS_ENTER_PRIVATE("pipe=%p, isp_parameters_id=%d", pipe_in, params->isp_parameters_id);
raw_bit_depth = ia_css_stream_input_format_bits_per_pixel(curr_pipe->stream);
if (!commit) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
for (i = 0; i < curr_pipe->stream->num_pipes; i++) {
struct ia_css_pipe *pipe;
struct sh_css_ddr_address_map *cur_map;
struct sh_css_ddr_address_map_size *cur_map_size;
struct ia_css_isp_parameter_set_info isp_params_info;
struct ia_css_pipeline *pipeline;
struct ia_css_pipeline_stage *stage;
enum sh_css_queue_id queue_id;
(void)stage;
pipe = curr_pipe->stream->pipes[i];
pipeline = ia_css_pipe_get_pipeline(pipe);
pipe_num = ia_css_pipe_get_pipe_num(pipe);
isp_pipe_version = ia_css_pipe_get_isp_pipe_version(pipe);
ia_css_pipeline_get_sp_thread_id(pipe_num, &thread_id);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
ia_css_query_internal_queue_id(params->output_frame
? IA_CSS_BUFFER_TYPE_PER_FRAME_PARAMETER_SET
: IA_CSS_BUFFER_TYPE_PARAMETER_SET,
thread_id, &queue_id);
#else
ia_css_query_internal_queue_id(IA_CSS_BUFFER_TYPE_PARAMETER_SET, thread_id, &queue_id);
#endif
if (!sh_css_sp_is_running()) {
err = IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
break;
}
cur_map = &params->pipe_ddr_ptrs[pipeline->pipe_id];
cur_map_size = &params->pipe_ddr_ptrs_size[pipeline->pipe_id];
{
err = ia_css_process_zoom_and_motion(params,
pipeline->stages);
if (err != IA_CSS_SUCCESS)
return err;
}
if (pipe_in && (pipe != pipe_in)) {
IA_CSS_LOG("skipping pipe %x", pipe);
continue;
}
for (stage = pipeline->stages; stage; stage = stage->next) {
unsigned mem;
if (!stage || !stage->binary)
continue;
process_kernel_parameters(pipeline->pipe_id,
stage, params,
isp_pipe_version, raw_bit_depth);
err = sh_css_params_write_to_ddr_internal(
pipe,
pipeline->pipe_id,
params,
stage,
cur_map,
cur_map_size);
if (err != IA_CSS_SUCCESS)
break;
for (mem = 0; mem < IA_CSS_NUM_MEMORIES; mem++) {
params->isp_mem_params_changed
[pipeline->pipe_id][stage->stage_num][mem] = false;
}
}
if (err != IA_CSS_SUCCESS)
break;
if (params->isp_params_changed) {
reallocate_buffer(&cur_map->isp_param,
&cur_map_size->isp_param,
cur_map_size->isp_param,
true,
&err);
if (err != IA_CSS_SUCCESS)
break;
sh_css_update_isp_params_to_ddr(params, cur_map->isp_param);
}
err = ref_sh_css_ddr_address_map(
cur_map,
&isp_params_info.mem_map);
if (err != IA_CSS_SUCCESS)
break;
isp_params_info.isp_parameters_id = params->isp_parameters_id;
isp_params_info.output_frame_ptr =
(params->output_frame) ? params->output_frame->data : mmgr_NULL;
err = write_ia_css_isp_parameter_set_info_to_ddr(&isp_params_info, &cpy);
if (err != IA_CSS_SUCCESS)
break;
IA_CSS_LOG("queue param set %x to %d", cpy, thread_id);
err = ia_css_bufq_enqueue_buffer(thread_id, queue_id, (uint32_t)cpy);
if (IA_CSS_SUCCESS != err) {
free_ia_css_isp_parameter_set_info(cpy);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
IA_CSS_LOG("pfp: FAILED to add config id %d for OF %d to q %d on thread %d",
isp_params_info.isp_parameters_id,
isp_params_info.output_frame_ptr,
queue_id, thread_id);
#endif
break;
}
else {
g_param_buffer_enqueue_count++;
assert(g_param_buffer_enqueue_count < g_param_buffer_dequeue_count+50);
#ifdef ISP2401
ia_css_save_latest_paramset_ptr(pipe, cpy);
#endif
if (!sh_css_sp_is_running()) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_RESOURCE_NOT_AVAILABLE);
return IA_CSS_ERR_RESOURCE_NOT_AVAILABLE;
}
ia_css_bufq_enqueue_psys_event(
IA_CSS_PSYS_SW_EVENT_BUFFER_ENQUEUED,
(uint8_t)thread_id,
(uint8_t)queue_id,
0);
#if defined(SH_CSS_ENABLE_PER_FRAME_PARAMS)
IA_CSS_LOG("pfp: added config id %d for OF %d to q %d on thread %d",
isp_params_info.isp_parameters_id,
isp_params_info.output_frame_ptr,
queue_id, thread_id);
#endif
}
ia_css_dequeue_param_buffers();
params->pipe_dvs_6axis_config_changed[pipeline->pipe_id] = false;
}
params->isp_params_changed = false;
params->sc_table_changed = false;
params->dis_coef_table_changed = false;
params->dvs2_coef_table_changed = false;
params->morph_table_changed = false;
params->dz_config_changed = false;
params->motion_config_changed = false;
params->shading_settings_changed = false;
memset(&params->config_changed[0], 0, sizeof(params->config_changed));
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err
sh_css_params_write_to_ddr_internal(
struct ia_css_pipe *pipe,
unsigned pipe_id,
struct ia_css_isp_parameters *params,
const struct ia_css_pipeline_stage *stage,
struct sh_css_ddr_address_map *ddr_map,
struct sh_css_ddr_address_map_size *ddr_map_size)
{
enum ia_css_err err;
const struct ia_css_binary *binary;
unsigned stage_num;
unsigned mem;
bool buff_realloced;
static struct ia_css_macc_table converted_macc_table;
IA_CSS_ENTER_PRIVATE("void");
assert(params != NULL);
assert(ddr_map != NULL);
assert(ddr_map_size != NULL);
assert(stage != NULL);
binary = stage->binary;
assert(binary != NULL);
stage_num = stage->stage_num;
if (binary->info->sp.enable.fpnr) {
buff_realloced = reallocate_buffer(&ddr_map->fpn_tbl,
&ddr_map_size->fpn_tbl,
(size_t)(FPNTBL_BYTES(binary)),
params->config_changed[IA_CSS_FPN_ID],
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (params->config_changed[IA_CSS_FPN_ID] || buff_realloced) {
if (params->fpn_config.enabled) {
err = store_fpntbl(params, ddr_map->fpn_tbl);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
}
}
if (binary->info->sp.enable.sc) {
uint32_t enable_conv = params->
shading_settings.enable_shading_table_conversion;
buff_realloced = reallocate_buffer(&ddr_map->sc_tbl,
&ddr_map_size->sc_tbl,
(size_t)(SCTBL_BYTES(binary)),
params->sc_table_changed,
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (params->shading_settings_changed ||
params->sc_table_changed || buff_realloced) {
if (enable_conv == 0) {
if (params->sc_table) {
err = ia_css_params_store_sctbl(stage, ddr_map->sc_tbl, params->sc_table);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
params->sc_config = (struct ia_css_shading_table *)params->sc_table;
ia_css_kernel_process_param[IA_CSS_SC_ID](pipe_id, stage, params);
params->sc_config = NULL;
} else {
if (params->sc_config) {
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
#ifndef ISP2401
sh_css_params_shading_id_table_generate(&params->sc_config, binary);
#else
sh_css_params_shading_id_table_generate(&params->sc_config,
binary->sctbl_width_per_color, binary->sctbl_height);
#endif
if (params->sc_config == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
err = ia_css_params_store_sctbl(stage, ddr_map->sc_tbl, params->sc_config);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
ia_css_kernel_process_param[IA_CSS_SC_ID](pipe_id, stage, params);
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
} else {
if (params->sc_config) {
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
prepare_shading_table(
(const struct ia_css_shading_table *)params->sc_table,
params->sensor_binning,
&params->sc_config,
binary, pipe->required_bds_factor);
if (params->sc_config == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
err = ia_css_params_store_sctbl(stage, ddr_map->sc_tbl, params->sc_config);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
ia_css_kernel_process_param[IA_CSS_SC_ID](pipe_id, stage, params);
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
}
}
#ifdef ISP2401
if (params->pipe_dpc_config_changed[pipe_id] && binary->info->sp.enable.dpc) {
unsigned size = stage->binary->info->mem_offsets.offsets.param->dmem.dp.size;
unsigned offset = stage->binary->info->mem_offsets.offsets.param->dmem.dp.offset;
if (size) {
ia_css_dp_encode((struct sh_css_isp_dp_params *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_PARAM][IA_CSS_ISP_DMEM].address[offset],
&params->pipe_dp_config[pipe_id], size);
#endif
#ifdef ISP2401
params->isp_params_changed = true;
params->isp_mem_params_changed[pipe_id][stage->stage_num][IA_CSS_ISP_DMEM] = true;
}
}
#endif
if (params->config_changed[IA_CSS_MACC_ID] && binary->info->sp.enable.macc) {
unsigned int i, j, idx;
unsigned int idx_map[] = {
0, 1, 3, 2, 6, 7, 5, 4, 12, 13, 15, 14, 10, 11, 9, 8};
for (i = 0; i < IA_CSS_MACC_NUM_AXES; i++) {
idx = 4*idx_map[i];
j = 4*i;
if (binary->info->sp.pipeline.isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_1) {
converted_macc_table.data[idx] =
(int16_t)sDIGIT_FITTING(params->macc_table.data[j],
13, SH_CSS_MACC_COEF_SHIFT);
converted_macc_table.data[idx+1] =
(int16_t)sDIGIT_FITTING(params->macc_table.data[j+1],
13, SH_CSS_MACC_COEF_SHIFT);
converted_macc_table.data[idx+2] =
(int16_t)sDIGIT_FITTING(params->macc_table.data[j+2],
13, SH_CSS_MACC_COEF_SHIFT);
converted_macc_table.data[idx+3] =
(int16_t)sDIGIT_FITTING(params->macc_table.data[j+3],
13, SH_CSS_MACC_COEF_SHIFT);
} else if (binary->info->sp.pipeline.isp_pipe_version == SH_CSS_ISP_PIPE_VERSION_2_2) {
converted_macc_table.data[idx] =
params->macc_table.data[j];
converted_macc_table.data[idx+1] =
params->macc_table.data[j+1];
converted_macc_table.data[idx+2] =
params->macc_table.data[j+2];
converted_macc_table.data[idx+3] =
params->macc_table.data[j+3];
}
}
reallocate_buffer(&ddr_map->macc_tbl,
&ddr_map_size->macc_tbl,
ddr_map_size->macc_tbl,
true,
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
mmgr_store(ddr_map->macc_tbl,
converted_macc_table.data,
sizeof(converted_macc_table.data));
}
if (binary->info->sp.enable.dvs_6axis) {
buff_realloced = reallocate_buffer(
&ddr_map->dvs_6axis_params_y,
&ddr_map_size->dvs_6axis_params_y,
(size_t)((DVS_6AXIS_BYTES(binary) / 2) * 3),
params->pipe_dvs_6axis_config_changed[pipe_id],
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (params->pipe_dvs_6axis_config_changed[pipe_id] || buff_realloced) {
const struct ia_css_frame_info *dvs_in_frame_info;
if ( stage->args.delay_frames[0] ) {
dvs_in_frame_info = &stage->args.delay_frames[0]->info;
} else {
dvs_in_frame_info = &stage->args.in_frame->info;
}
if (params->pipe_dvs_6axis_config[pipe_id] == NULL) {
#ifndef ISP2401
struct ia_css_resolution dvs_offset;
dvs_offset.width =
#else
struct ia_css_resolution dvs_offset = {0, 0};
if (binary->dvs_envelope.width || binary->dvs_envelope.height) {
dvs_offset.width =
#endif
(PIX_SHIFT_FILTER_RUN_IN_X + binary->dvs_envelope.width) / 2;
#ifndef ISP2401
dvs_offset.height =
#else
dvs_offset.height =
#endif
(PIX_SHIFT_FILTER_RUN_IN_Y + binary->dvs_envelope.height) / 2;
#ifdef ISP2401
}
#endif
params->pipe_dvs_6axis_config[pipe_id] =
generate_dvs_6axis_table(&binary->out_frame_info[0].res, &dvs_offset);
if (params->pipe_dvs_6axis_config[pipe_id] == NULL) {
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY);
return IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
}
params->pipe_dvs_6axis_config_changed[pipe_id] = true;
}
store_dvs_6axis_config(params->pipe_dvs_6axis_config[pipe_id],
binary,
dvs_in_frame_info,
ddr_map->dvs_6axis_params_y);
params->isp_params_changed = true;
}
}
if (binary->info->sp.enable.ca_gdc) {
unsigned int i;
hrt_vaddress *virt_addr_tetra_x[
IA_CSS_MORPH_TABLE_NUM_PLANES];
size_t *virt_size_tetra_x[
IA_CSS_MORPH_TABLE_NUM_PLANES];
hrt_vaddress *virt_addr_tetra_y[
IA_CSS_MORPH_TABLE_NUM_PLANES];
size_t *virt_size_tetra_y[
IA_CSS_MORPH_TABLE_NUM_PLANES];
virt_addr_tetra_x[0] = &ddr_map->tetra_r_x;
virt_addr_tetra_x[1] = &ddr_map->tetra_gr_x;
virt_addr_tetra_x[2] = &ddr_map->tetra_gb_x;
virt_addr_tetra_x[3] = &ddr_map->tetra_b_x;
virt_addr_tetra_x[4] = &ddr_map->tetra_ratb_x;
virt_addr_tetra_x[5] = &ddr_map->tetra_batr_x;
virt_size_tetra_x[0] = &ddr_map_size->tetra_r_x;
virt_size_tetra_x[1] = &ddr_map_size->tetra_gr_x;
virt_size_tetra_x[2] = &ddr_map_size->tetra_gb_x;
virt_size_tetra_x[3] = &ddr_map_size->tetra_b_x;
virt_size_tetra_x[4] = &ddr_map_size->tetra_ratb_x;
virt_size_tetra_x[5] = &ddr_map_size->tetra_batr_x;
virt_addr_tetra_y[0] = &ddr_map->tetra_r_y;
virt_addr_tetra_y[1] = &ddr_map->tetra_gr_y;
virt_addr_tetra_y[2] = &ddr_map->tetra_gb_y;
virt_addr_tetra_y[3] = &ddr_map->tetra_b_y;
virt_addr_tetra_y[4] = &ddr_map->tetra_ratb_y;
virt_addr_tetra_y[5] = &ddr_map->tetra_batr_y;
virt_size_tetra_y[0] = &ddr_map_size->tetra_r_y;
virt_size_tetra_y[1] = &ddr_map_size->tetra_gr_y;
virt_size_tetra_y[2] = &ddr_map_size->tetra_gb_y;
virt_size_tetra_y[3] = &ddr_map_size->tetra_b_y;
virt_size_tetra_y[4] = &ddr_map_size->tetra_ratb_y;
virt_size_tetra_y[5] = &ddr_map_size->tetra_batr_y;
buff_realloced = false;
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
buff_realloced |=
reallocate_buffer(virt_addr_tetra_x[i],
virt_size_tetra_x[i],
(size_t)
(MORPH_PLANE_BYTES(binary)),
params->morph_table_changed,
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
buff_realloced |=
reallocate_buffer(virt_addr_tetra_y[i],
virt_size_tetra_y[i],
(size_t)
(MORPH_PLANE_BYTES(binary)),
params->morph_table_changed,
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
}
if (params->morph_table_changed || buff_realloced) {
const struct ia_css_morph_table *table = params->morph_table;
struct ia_css_morph_table *id_table = NULL;
if ((table != NULL) &&
(table->width < binary->morph_tbl_width ||
table->height < binary->morph_tbl_height)) {
table = NULL;
}
if (table == NULL) {
err = sh_css_params_default_morph_table(&id_table,
binary);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
table = id_table;
}
for (i = 0; i < IA_CSS_MORPH_TABLE_NUM_PLANES; i++) {
store_morph_plane(table->coordinates_x[i],
table->width,
table->height,
*virt_addr_tetra_x[i],
binary->morph_tbl_aligned_width);
store_morph_plane(table->coordinates_y[i],
table->width,
table->height,
*virt_addr_tetra_y[i],
binary->morph_tbl_aligned_width);
}
if (id_table != NULL)
ia_css_morph_table_free(id_table);
}
}
for (mem = 0; mem < N_IA_CSS_MEMORIES; mem++) {
const struct ia_css_isp_data *isp_data =
ia_css_isp_param_get_isp_mem_init(&binary->info->sp.mem_initializers, IA_CSS_PARAM_CLASS_PARAM, mem);
size_t size = isp_data->size;
if (!size) continue;
buff_realloced = reallocate_buffer(&ddr_map->isp_mem_param[stage_num][mem],
&ddr_map_size->isp_mem_param[stage_num][mem],
size,
params->isp_mem_params_changed[pipe_id][stage_num][mem],
&err);
if (err != IA_CSS_SUCCESS) {
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
if (params->isp_mem_params_changed[pipe_id][stage_num][mem] || buff_realloced) {
sh_css_update_isp_mem_params_to_ddr(binary,
ddr_map->isp_mem_param[stage_num][mem],
ddr_map_size->isp_mem_param[stage_num][mem], mem);
}
}
IA_CSS_LEAVE_ERR_PRIVATE(IA_CSS_SUCCESS);
return IA_CSS_SUCCESS;
}
const struct ia_css_fpn_table *ia_css_get_fpn_table(struct ia_css_stream *stream)
{
struct ia_css_isp_parameters *params;
IA_CSS_ENTER_LEAVE("void");
assert(stream != NULL);
params = stream->isp_params_configs;
return &(params->fpn_config);
}
struct ia_css_shading_table *ia_css_get_shading_table(struct ia_css_stream *stream)
{
struct ia_css_shading_table *table = NULL;
struct ia_css_isp_parameters *params;
IA_CSS_ENTER("void");
assert(stream != NULL);
params = stream->isp_params_configs;
if (!params)
return NULL;
if (params->shading_settings.enable_shading_table_conversion == 0) {
if (params->sc_table) {
table = (struct ia_css_shading_table *)params->sc_table;
} else {
const struct ia_css_binary *binary
= ia_css_stream_get_shading_correction_binary(stream);
if (binary) {
if (params->sc_config) {
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
#ifndef ISP2401
sh_css_params_shading_id_table_generate(&params->sc_config, binary);
#else
sh_css_params_shading_id_table_generate(&params->sc_config,
binary->sctbl_width_per_color, binary->sctbl_height);
#endif
table = params->sc_config;
}
}
} else {
const struct ia_css_binary *binary
= ia_css_stream_get_shading_correction_binary(stream);
struct ia_css_pipe *pipe;
pipe = stream->pipes[0];
if (stream->num_pipes == 2) {
assert(stream->pipes[1] != NULL);
if (stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_VIDEO ||
stream->pipes[1]->config.mode == IA_CSS_PIPE_MODE_PREVIEW)
pipe = stream->pipes[1];
}
if (binary) {
if (params->sc_config) {
ia_css_shading_table_free(params->sc_config);
params->sc_config = NULL;
}
prepare_shading_table(
(const struct ia_css_shading_table *)params->sc_table,
params->sensor_binning,
&params->sc_config,
binary, pipe->required_bds_factor);
table = params->sc_config;
}
}
IA_CSS_LEAVE("table=%p", table);
return table;
}
hrt_vaddress sh_css_store_sp_group_to_ddr(void)
{
IA_CSS_ENTER_LEAVE_PRIVATE("void");
mmgr_store(xmem_sp_group_ptrs,
&sh_css_sp_group,
sizeof(struct sh_css_sp_group));
return xmem_sp_group_ptrs;
}
hrt_vaddress sh_css_store_sp_stage_to_ddr(
unsigned pipe,
unsigned stage)
{
IA_CSS_ENTER_LEAVE_PRIVATE("void");
mmgr_store(xmem_sp_stage_ptrs[pipe][stage],
&sh_css_sp_stage,
sizeof(struct sh_css_sp_stage));
return xmem_sp_stage_ptrs[pipe][stage];
}
hrt_vaddress sh_css_store_isp_stage_to_ddr(
unsigned pipe,
unsigned stage)
{
IA_CSS_ENTER_LEAVE_PRIVATE("void");
mmgr_store(xmem_isp_stage_ptrs[pipe][stage],
&sh_css_isp_stage,
sizeof(struct sh_css_isp_stage));
return xmem_isp_stage_ptrs[pipe][stage];
}
static enum ia_css_err ref_sh_css_ddr_address_map(
struct sh_css_ddr_address_map *map,
struct sh_css_ddr_address_map *out)
{
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int i;
union {
struct sh_css_ddr_address_map *map;
hrt_vaddress *addrs;
} in_addrs, to_addrs;
IA_CSS_ENTER_PRIVATE("void");
assert(map != NULL);
assert(out != NULL);
in_addrs.map = map;
to_addrs.map = out;
assert(sizeof(struct sh_css_ddr_address_map_size)/sizeof(size_t) ==
sizeof(struct sh_css_ddr_address_map)/sizeof(hrt_vaddress));
for (i = 0; i < (sizeof(struct sh_css_ddr_address_map_size)/
sizeof(size_t)); i++) {
if (in_addrs.addrs[i] == mmgr_NULL)
to_addrs.addrs[i] = mmgr_NULL;
else
to_addrs.addrs[i] = ia_css_refcount_increment(IA_CSS_REFCOUNT_PARAM_BUFFER, in_addrs.addrs[i]);
}
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
static enum ia_css_err write_ia_css_isp_parameter_set_info_to_ddr(
struct ia_css_isp_parameter_set_info *me,
hrt_vaddress *out)
{
enum ia_css_err err = IA_CSS_SUCCESS;
bool succ;
IA_CSS_ENTER_PRIVATE("void");
assert(me != NULL);
assert(out != NULL);
*out = ia_css_refcount_increment(IA_CSS_REFCOUNT_PARAM_SET_POOL, mmgr_malloc(
sizeof(struct ia_css_isp_parameter_set_info)));
succ = (*out != mmgr_NULL);
if (succ)
mmgr_store(*out,
me, sizeof(struct ia_css_isp_parameter_set_info));
else
err = IA_CSS_ERR_CANNOT_ALLOCATE_MEMORY;
IA_CSS_LEAVE_ERR_PRIVATE(err);
return err;
}
void
sh_css_invalidate_params(struct ia_css_stream *stream)
{
struct ia_css_isp_parameters *params;
unsigned i, j, mem;
IA_CSS_ENTER_PRIVATE("void");
assert(stream != NULL);
params = stream->isp_params_configs;
params->isp_params_changed = true;
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
for (j = 0; j < SH_CSS_MAX_STAGES; j++) {
for (mem = 0; mem < N_IA_CSS_MEMORIES; mem++) {
params->isp_mem_params_changed[i][j][mem] = true;
}
}
}
memset(&params->config_changed[0], 1, sizeof(params->config_changed));
params->dis_coef_table_changed = true;
params->dvs2_coef_table_changed = true;
params->morph_table_changed = true;
params->sc_table_changed = true;
params->dz_config_changed = true;
params->motion_config_changed = true;
for (i = 0; i < IA_CSS_PIPE_ID_NUM; i++) {
if (params->pipe_dvs_6axis_config[i]) {
free_dvs_6axis_table(&(params->pipe_dvs_6axis_config[i]));
params->pipe_dvs_6axis_config_changed[i] = true;
}
}
IA_CSS_LEAVE_PRIVATE("void");
}
void
sh_css_update_uds_and_crop_info(
const struct ia_css_binary_info *info,
const struct ia_css_frame_info *in_frame_info,
const struct ia_css_frame_info *out_frame_info,
const struct ia_css_resolution *dvs_env,
const struct ia_css_dz_config *zoom,
const struct ia_css_vector *motion_vector,
struct sh_css_uds_info *uds,
struct sh_css_crop_pos *sp_out_crop_pos,
bool enable_zoom)
{
IA_CSS_ENTER_PRIVATE("void");
assert(info != NULL);
assert(in_frame_info != NULL);
assert(out_frame_info != NULL);
assert(dvs_env != NULL);
assert(zoom != NULL);
assert(motion_vector != NULL);
assert(uds != NULL);
assert(sp_out_crop_pos != NULL);
uds->curr_dx = enable_zoom ? (uint16_t)zoom->dx : HRT_GDC_N;
uds->curr_dy = enable_zoom ? (uint16_t)zoom->dy : HRT_GDC_N;
if (info->enable.dvs_envelope) {
unsigned int crop_x = 0,
crop_y = 0,
uds_xc = 0,
uds_yc = 0,
env_width, env_height;
int half_env_x, half_env_y;
int motion_x = motion_vector->x;
int motion_y = motion_vector->y;
bool upscale_x = in_frame_info->res.width < out_frame_info->res.width;
bool upscale_y = in_frame_info->res.height < out_frame_info->res.height;
if (info->enable.uds && !info->enable.ds) {
env_width = dvs_env->width -
SH_CSS_MIN_DVS_ENVELOPE;
env_height = dvs_env->height -
SH_CSS_MIN_DVS_ENVELOPE;
half_env_x = env_width / 2;
half_env_y = env_height / 2;
if (upscale_x) {
uds_xc = (in_frame_info->res.width
+ env_width
+ SH_CSS_MIN_DVS_ENVELOPE) / 2;
} else {
uds_xc = (out_frame_info->res.width
+ env_width) / 2
+ SH_CSS_MIN_DVS_ENVELOPE;
}
if (upscale_y) {
uds_yc = (in_frame_info->res.height
+ env_height
+ SH_CSS_MIN_DVS_ENVELOPE) / 2;
} else {
uds_yc = (out_frame_info->res.height
+ env_height) / 2
+ SH_CSS_MIN_DVS_ENVELOPE;
}
motion_x = clamp(motion_x, -half_env_x, half_env_x);
motion_y = clamp(motion_y, -half_env_y, half_env_y);
uds_xc += motion_x;
uds_yc += motion_y;
crop_y = 2;
} else if (info->enable.ds) {
env_width = dvs_env->width;
env_height = dvs_env->height;
half_env_x = env_width / 2;
half_env_y = env_height / 2;
motion_x = clamp(motion_x, -half_env_x, half_env_x);
motion_y = clamp(motion_y, -half_env_y, half_env_y);
uds_xc = in_frame_info->res.width/2 + motion_x;
uds_yc = in_frame_info->res.height/2 + motion_y;
crop_x = info->pipeline.left_cropping;
if (info->enable.ds & 1)
crop_y = info->pipeline.top_cropping;
else
crop_y = 2;
} else {
env_width = dvs_env->width -
SH_CSS_MIN_DVS_ENVELOPE;
env_height = dvs_env->height -
SH_CSS_MIN_DVS_ENVELOPE;
half_env_x = env_width / 2;
half_env_y = env_height / 2;
motion_x = clamp(motion_x, -half_env_x, half_env_x);
motion_y = clamp(motion_y, -half_env_y, half_env_y);
crop_x = SH_CSS_MIN_DVS_ENVELOPE
+ half_env_x + motion_x;
crop_y = SH_CSS_MIN_DVS_ENVELOPE
+ half_env_y + motion_y;
}
crop_x = EVEN_FLOOR(crop_x);
crop_y = EVEN_FLOOR(crop_y);
uds_xc = EVEN_FLOOR(uds_xc);
uds_yc = EVEN_FLOOR(uds_yc);
uds->xc = (uint16_t)uds_xc;
uds->yc = (uint16_t)uds_yc;
sp_out_crop_pos->x = (uint16_t)crop_x;
sp_out_crop_pos->y = (uint16_t)crop_y;
}
else {
uds->xc = (uint16_t)in_frame_info->res.width / 2;
uds->yc = (uint16_t)in_frame_info->res.height / 2;
sp_out_crop_pos->x = (uint16_t)info->pipeline.left_cropping;
sp_out_crop_pos->y = (uint16_t)info->pipeline.top_cropping;
}
IA_CSS_LEAVE_PRIVATE("void");
}
static enum ia_css_err
sh_css_update_uds_and_crop_info_based_on_zoom_region(
const struct ia_css_binary_info *info,
const struct ia_css_frame_info *in_frame_info,
const struct ia_css_frame_info *out_frame_info,
const struct ia_css_resolution *dvs_env,
const struct ia_css_dz_config *zoom,
const struct ia_css_vector *motion_vector,
struct sh_css_uds_info *uds,
struct sh_css_crop_pos *sp_out_crop_pos,
struct ia_css_resolution pipe_in_res,
bool enable_zoom)
{
unsigned int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
enum ia_css_err err = IA_CSS_SUCCESS;
unsigned int filter_envelope = 0;
IA_CSS_ENTER_PRIVATE("void");
assert(info != NULL);
assert(in_frame_info != NULL);
assert(out_frame_info != NULL);
assert(dvs_env != NULL);
assert(zoom != NULL);
assert(motion_vector != NULL);
assert(uds != NULL);
assert(sp_out_crop_pos != NULL);
x0 = zoom->zoom_region.origin.x;
y0 = zoom->zoom_region.origin.y;
x1 = zoom->zoom_region.resolution.width + x0;
y1 = zoom->zoom_region.resolution.height + y0;
if ((x0 > x1) || (y0 > y1) || (x1 > pipe_in_res.width) || (y1 > pipe_in_res.height))
return IA_CSS_ERR_INVALID_ARGUMENTS;
if (!enable_zoom) {
uds->curr_dx = HRT_GDC_N;
uds->curr_dy = HRT_GDC_N;
}
if (info->enable.dvs_envelope) {
return IA_CSS_ERR_INVALID_ARGUMENTS;
} else {
if (enable_zoom) {
if (in_frame_info->res.width != pipe_in_res.width ||
in_frame_info->res.height != pipe_in_res.height) {
x0 = (x0 * in_frame_info->res.width) / (pipe_in_res.width);
y0 = (y0 * in_frame_info->res.height) / (pipe_in_res.height);
x1 = (x1 * in_frame_info->res.width) / (pipe_in_res.width);
y1 = (y1 * in_frame_info->res.height) / (pipe_in_res.height);
}
uds->curr_dx =
((x1 - x0 - filter_envelope) * HRT_GDC_N) / in_frame_info->res.width;
uds->curr_dy =
((y1 - y0 - filter_envelope) * HRT_GDC_N) / in_frame_info->res.height;
uds->xc = (uint16_t) x0 + (((x1)-(x0)) / 2);
uds->yc = (uint16_t) y0 + (((y1)-(y0)) / 2);
} else {
uds->xc = (uint16_t)in_frame_info->res.width / 2;
uds->yc = (uint16_t)in_frame_info->res.height / 2;
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "uds->curr_dx=%d, uds->xc=%d, uds->yc=%d\n",
uds->curr_dx, uds->xc, uds->yc);
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE, "x0=%d, y0=%d, x1=%d, y1=%d\n",
x0, y0, x1, y1);
sp_out_crop_pos->x = (uint16_t)info->pipeline.left_cropping;
sp_out_crop_pos->y = (uint16_t)info->pipeline.top_cropping;
}
IA_CSS_LEAVE_PRIVATE("void");
return err;
}
struct ia_css_3a_statistics *
ia_css_3a_statistics_allocate(const struct ia_css_3a_grid_info *grid)
{
struct ia_css_3a_statistics *me;
int grid_size;
IA_CSS_ENTER("grid=%p", grid);
assert(grid != NULL);
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
me->grid = *grid;
grid_size = grid->width * grid->height;
me->data = sh_css_malloc(grid_size * sizeof(*me->data));
if (!me->data)
goto err;
#if !defined(HAS_NO_HMEM)
me->rgby_data = (struct ia_css_3a_rgby_output *)sh_css_malloc(sizeof_hmem(HMEM0_ID));
#else
me->rgby_data = NULL;
#endif
IA_CSS_LEAVE("return=%p", me);
return me;
err:
ia_css_3a_statistics_free(me);
IA_CSS_LEAVE("return=%p", NULL);
return NULL;
}
void
ia_css_3a_statistics_free(struct ia_css_3a_statistics *me)
{
if (me) {
sh_css_free(me->rgby_data);
sh_css_free(me->data);
memset(me, 0, sizeof(struct ia_css_3a_statistics));
sh_css_free(me);
}
}
struct ia_css_dvs_statistics *
ia_css_dvs_statistics_allocate(const struct ia_css_dvs_grid_info *grid)
{
struct ia_css_dvs_statistics *me;
assert(grid != NULL);
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
me->grid = *grid;
me->hor_proj = sh_css_malloc(grid->height * IA_CSS_DVS_NUM_COEF_TYPES *
sizeof(*me->hor_proj));
if (!me->hor_proj)
goto err;
me->ver_proj = sh_css_malloc(grid->width * IA_CSS_DVS_NUM_COEF_TYPES *
sizeof(*me->ver_proj));
if (!me->ver_proj)
goto err;
return me;
err:
ia_css_dvs_statistics_free(me);
return NULL;
}
void
ia_css_dvs_statistics_free(struct ia_css_dvs_statistics *me)
{
if (me) {
sh_css_free(me->hor_proj);
sh_css_free(me->ver_proj);
memset(me, 0, sizeof(struct ia_css_dvs_statistics));
sh_css_free(me);
}
}
struct ia_css_dvs_coefficients *
ia_css_dvs_coefficients_allocate(const struct ia_css_dvs_grid_info *grid)
{
struct ia_css_dvs_coefficients *me;
assert(grid != NULL);
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
me->grid = *grid;
me->hor_coefs = sh_css_malloc(grid->num_hor_coefs *
IA_CSS_DVS_NUM_COEF_TYPES *
sizeof(*me->hor_coefs));
if (!me->hor_coefs)
goto err;
me->ver_coefs = sh_css_malloc(grid->num_ver_coefs *
IA_CSS_DVS_NUM_COEF_TYPES *
sizeof(*me->ver_coefs));
if (!me->ver_coefs)
goto err;
return me;
err:
ia_css_dvs_coefficients_free(me);
return NULL;
}
void
ia_css_dvs_coefficients_free(struct ia_css_dvs_coefficients *me)
{
if (me) {
sh_css_free(me->hor_coefs);
sh_css_free(me->ver_coefs);
memset(me, 0, sizeof(struct ia_css_dvs_coefficients));
sh_css_free(me);
}
}
struct ia_css_dvs2_statistics *
ia_css_dvs2_statistics_allocate(const struct ia_css_dvs_grid_info *grid)
{
struct ia_css_dvs2_statistics *me;
assert(grid != NULL);
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
me->grid = *grid;
me->hor_prod.odd_real = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->hor_prod.odd_real));
if (!me->hor_prod.odd_real)
goto err;
me->hor_prod.odd_imag = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->hor_prod.odd_imag));
if (!me->hor_prod.odd_imag)
goto err;
me->hor_prod.even_real = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->hor_prod.even_real));
if (!me->hor_prod.even_real)
goto err;
me->hor_prod.even_imag = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->hor_prod.even_imag));
if (!me->hor_prod.even_imag)
goto err;
me->ver_prod.odd_real = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->ver_prod.odd_real));
if (!me->ver_prod.odd_real)
goto err;
me->ver_prod.odd_imag = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->ver_prod.odd_imag));
if (!me->ver_prod.odd_imag)
goto err;
me->ver_prod.even_real = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->ver_prod.even_real));
if (!me->ver_prod.even_real)
goto err;
me->ver_prod.even_imag = sh_css_malloc(grid->aligned_width *
grid->aligned_height * sizeof(*me->ver_prod.even_imag));
if (!me->ver_prod.even_imag)
goto err;
return me;
err:
ia_css_dvs2_statistics_free(me);
return NULL;
}
void
ia_css_dvs2_statistics_free(struct ia_css_dvs2_statistics *me)
{
if (me) {
sh_css_free(me->hor_prod.odd_real);
sh_css_free(me->hor_prod.odd_imag);
sh_css_free(me->hor_prod.even_real);
sh_css_free(me->hor_prod.even_imag);
sh_css_free(me->ver_prod.odd_real);
sh_css_free(me->ver_prod.odd_imag);
sh_css_free(me->ver_prod.even_real);
sh_css_free(me->ver_prod.even_imag);
memset(me, 0, sizeof(struct ia_css_dvs2_statistics));
sh_css_free(me);
}
}
struct ia_css_dvs2_coefficients *
ia_css_dvs2_coefficients_allocate(const struct ia_css_dvs_grid_info *grid)
{
struct ia_css_dvs2_coefficients *me;
assert(grid != NULL);
me = sh_css_calloc(1, sizeof(*me));
if (!me)
goto err;
me->grid = *grid;
me->hor_coefs.odd_real = sh_css_malloc(grid->num_hor_coefs *
sizeof(*me->hor_coefs.odd_real));
if (!me->hor_coefs.odd_real)
goto err;
me->hor_coefs.odd_imag = sh_css_malloc(grid->num_hor_coefs *
sizeof(*me->hor_coefs.odd_imag));
if (!me->hor_coefs.odd_imag)
goto err;
me->hor_coefs.even_real = sh_css_malloc(grid->num_hor_coefs *
sizeof(*me->hor_coefs.even_real));
if (!me->hor_coefs.even_real)
goto err;
me->hor_coefs.even_imag = sh_css_malloc(grid->num_hor_coefs *
sizeof(*me->hor_coefs.even_imag));
if (!me->hor_coefs.even_imag)
goto err;
me->ver_coefs.odd_real = sh_css_malloc(grid->num_ver_coefs *
sizeof(*me->ver_coefs.odd_real));
if (!me->ver_coefs.odd_real)
goto err;
me->ver_coefs.odd_imag = sh_css_malloc(grid->num_ver_coefs *
sizeof(*me->ver_coefs.odd_imag));
if (!me->ver_coefs.odd_imag)
goto err;
me->ver_coefs.even_real = sh_css_malloc(grid->num_ver_coefs *
sizeof(*me->ver_coefs.even_real));
if (!me->ver_coefs.even_real)
goto err;
me->ver_coefs.even_imag = sh_css_malloc(grid->num_ver_coefs *
sizeof(*me->ver_coefs.even_imag));
if (!me->ver_coefs.even_imag)
goto err;
return me;
err:
ia_css_dvs2_coefficients_free(me);
return NULL;
}
void
ia_css_dvs2_coefficients_free(struct ia_css_dvs2_coefficients *me)
{
if (me) {
sh_css_free(me->hor_coefs.odd_real);
sh_css_free(me->hor_coefs.odd_imag);
sh_css_free(me->hor_coefs.even_real);
sh_css_free(me->hor_coefs.even_imag);
sh_css_free(me->ver_coefs.odd_real);
sh_css_free(me->ver_coefs.odd_imag);
sh_css_free(me->ver_coefs.even_real);
sh_css_free(me->ver_coefs.even_imag);
memset(me, 0, sizeof(struct ia_css_dvs2_coefficients));
sh_css_free(me);
}
}
struct ia_css_dvs_6axis_config *
ia_css_dvs2_6axis_config_allocate(const struct ia_css_stream *stream)
{
struct ia_css_dvs_6axis_config *dvs_config = NULL;
struct ia_css_isp_parameters *params = NULL;
unsigned int width_y;
unsigned int height_y;
unsigned int width_uv;
unsigned int height_uv;
assert(stream != NULL);
params = stream->isp_params_configs;
if (!params || (params && !params->pipe_dvs_6axis_config[IA_CSS_PIPE_ID_VIDEO])) {
goto err;
}
dvs_config = (struct ia_css_dvs_6axis_config *)sh_css_calloc(1, sizeof(struct ia_css_dvs_6axis_config));
if (!dvs_config)
goto err;
dvs_config->width_y = width_y = params->pipe_dvs_6axis_config[IA_CSS_PIPE_ID_VIDEO]->width_y;
dvs_config->height_y = height_y = params->pipe_dvs_6axis_config[IA_CSS_PIPE_ID_VIDEO]->height_y;
dvs_config->width_uv = width_uv = params->pipe_dvs_6axis_config[IA_CSS_PIPE_ID_VIDEO]->width_uv;
dvs_config->height_uv = height_uv = params->pipe_dvs_6axis_config[IA_CSS_PIPE_ID_VIDEO]->height_uv;
IA_CSS_LOG("table Y: W %d H %d", width_y, height_y);
IA_CSS_LOG("table UV: W %d H %d", width_uv, height_uv);
dvs_config->xcoords_y = (uint32_t *)sh_css_malloc(width_y * height_y * sizeof(uint32_t));
if (!dvs_config->xcoords_y)
goto err;
dvs_config->ycoords_y = (uint32_t *)sh_css_malloc(width_y * height_y * sizeof(uint32_t));
if (!dvs_config->ycoords_y)
goto err;
dvs_config->xcoords_uv = (uint32_t *)sh_css_malloc(width_uv * height_uv * sizeof(uint32_t));
if (!dvs_config->xcoords_uv)
goto err;
dvs_config->ycoords_uv = (uint32_t *)sh_css_malloc(width_uv * height_uv * sizeof(uint32_t));
if (!dvs_config->ycoords_uv)
goto err;
return dvs_config;
err:
ia_css_dvs2_6axis_config_free(dvs_config);
return NULL;
}
void
ia_css_dvs2_6axis_config_free(struct ia_css_dvs_6axis_config *dvs_6axis_config)
{
if (dvs_6axis_config) {
sh_css_free(dvs_6axis_config->xcoords_y);
sh_css_free(dvs_6axis_config->ycoords_y);
sh_css_free(dvs_6axis_config->xcoords_uv);
sh_css_free(dvs_6axis_config->ycoords_uv);
memset(dvs_6axis_config, 0, sizeof(struct ia_css_dvs_6axis_config));
sh_css_free(dvs_6axis_config);
}
}
void
ia_css_en_dz_capt_pipe(struct ia_css_stream *stream, bool enable)
{
struct ia_css_pipe *pipe;
struct ia_css_pipeline *pipeline;
struct ia_css_pipeline_stage *stage;
enum ia_css_pipe_id pipe_id;
enum ia_css_err err;
int i;
if (stream == NULL)
return;
for (i = 0; i < stream->num_pipes; i++) {
pipe = stream->pipes[i];
pipeline = ia_css_pipe_get_pipeline(pipe);
pipe_id = pipeline->pipe_id;
if (pipe_id == IA_CSS_PIPE_ID_CAPTURE) {
err = ia_css_pipeline_get_stage(pipeline, IA_CSS_BINARY_MODE_CAPTURE_PP, &stage);
if (err == IA_CSS_SUCCESS)
stage->enable_zoom = enable;
break;
}
}
}
