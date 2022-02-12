void skl_tplg_d0i3_get(struct skl *skl, enum d0i3_capability caps)
{
struct skl_d0i3_data *d0i3 = &skl->skl_sst->d0i3;
switch (caps) {
case SKL_D0I3_NONE:
d0i3->non_d0i3++;
break;
case SKL_D0I3_STREAMING:
d0i3->streaming++;
break;
case SKL_D0I3_NON_STREAMING:
d0i3->non_streaming++;
break;
}
}
void skl_tplg_d0i3_put(struct skl *skl, enum d0i3_capability caps)
{
struct skl_d0i3_data *d0i3 = &skl->skl_sst->d0i3;
switch (caps) {
case SKL_D0I3_NONE:
d0i3->non_d0i3--;
break;
case SKL_D0I3_STREAMING:
d0i3->streaming--;
break;
case SKL_D0I3_NON_STREAMING:
d0i3->non_streaming--;
break;
}
}
static int is_skl_dsp_widget_type(struct snd_soc_dapm_widget *w)
{
switch (w->id) {
case snd_soc_dapm_dai_link:
case snd_soc_dapm_dai_in:
case snd_soc_dapm_aif_in:
case snd_soc_dapm_aif_out:
case snd_soc_dapm_dai_out:
case snd_soc_dapm_switch:
return false;
default:
return true;
}
}
static bool skl_is_pipe_mem_avail(struct skl *skl,
struct skl_module_cfg *mconfig)
{
struct skl_sst *ctx = skl->skl_sst;
if (skl->resource.mem + mconfig->pipe->memory_pages >
skl->resource.max_mem) {
dev_err(ctx->dev,
"%s: module_id %d instance %d\n", __func__,
mconfig->id.module_id,
mconfig->id.instance_id);
dev_err(ctx->dev,
"exceeds ppl memory available %d mem %d\n",
skl->resource.max_mem, skl->resource.mem);
return false;
} else {
return true;
}
}
static void skl_tplg_alloc_pipe_mem(struct skl *skl,
struct skl_module_cfg *mconfig)
{
skl->resource.mem += mconfig->pipe->memory_pages;
}
static bool skl_is_pipe_mcps_avail(struct skl *skl,
struct skl_module_cfg *mconfig)
{
struct skl_sst *ctx = skl->skl_sst;
if (skl->resource.mcps + mconfig->mcps > skl->resource.max_mcps) {
dev_err(ctx->dev,
"%s: module_id %d instance %d\n", __func__,
mconfig->id.module_id, mconfig->id.instance_id);
dev_err(ctx->dev,
"exceeds ppl mcps available %d > mem %d\n",
skl->resource.max_mcps, skl->resource.mcps);
return false;
} else {
return true;
}
}
static void skl_tplg_alloc_pipe_mcps(struct skl *skl,
struct skl_module_cfg *mconfig)
{
skl->resource.mcps += mconfig->mcps;
}
static void
skl_tplg_free_pipe_mcps(struct skl *skl, struct skl_module_cfg *mconfig)
{
skl->resource.mcps -= mconfig->mcps;
}
static void
skl_tplg_free_pipe_mem(struct skl *skl, struct skl_module_cfg *mconfig)
{
skl->resource.mem -= mconfig->pipe->memory_pages;
}
static void skl_dump_mconfig(struct skl_sst *ctx,
struct skl_module_cfg *mcfg)
{
dev_dbg(ctx->dev, "Dumping config\n");
dev_dbg(ctx->dev, "Input Format:\n");
dev_dbg(ctx->dev, "channels = %d\n", mcfg->in_fmt[0].channels);
dev_dbg(ctx->dev, "s_freq = %d\n", mcfg->in_fmt[0].s_freq);
dev_dbg(ctx->dev, "ch_cfg = %d\n", mcfg->in_fmt[0].ch_cfg);
dev_dbg(ctx->dev, "valid bit depth = %d\n", mcfg->in_fmt[0].valid_bit_depth);
dev_dbg(ctx->dev, "Output Format:\n");
dev_dbg(ctx->dev, "channels = %d\n", mcfg->out_fmt[0].channels);
dev_dbg(ctx->dev, "s_freq = %d\n", mcfg->out_fmt[0].s_freq);
dev_dbg(ctx->dev, "valid bit depth = %d\n", mcfg->out_fmt[0].valid_bit_depth);
dev_dbg(ctx->dev, "ch_cfg = %d\n", mcfg->out_fmt[0].ch_cfg);
}
static void skl_tplg_update_chmap(struct skl_module_fmt *fmt, int chs)
{
int slot_map = 0xFFFFFFFF;
int start_slot = 0;
int i;
for (i = 0; i < chs; i++) {
slot_map &= (~(0xF << (4 * i)) | (start_slot << (4 * i)));
start_slot++;
}
fmt->ch_map = slot_map;
}
static void skl_tplg_update_params(struct skl_module_fmt *fmt,
struct skl_pipe_params *params, int fixup)
{
if (fixup & SKL_RATE_FIXUP_MASK)
fmt->s_freq = params->s_freq;
if (fixup & SKL_CH_FIXUP_MASK) {
fmt->channels = params->ch;
skl_tplg_update_chmap(fmt, fmt->channels);
}
if (fixup & SKL_FMT_FIXUP_MASK) {
fmt->valid_bit_depth = skl_get_bit_depth(params->s_fmt);
switch (fmt->valid_bit_depth) {
case SKL_DEPTH_16BIT:
fmt->bit_depth = fmt->valid_bit_depth;
break;
default:
fmt->bit_depth = SKL_DEPTH_32BIT;
break;
}
}
}
static void skl_tplg_update_params_fixup(struct skl_module_cfg *m_cfg,
struct skl_pipe_params *params, bool is_fe)
{
int in_fixup, out_fixup;
struct skl_module_fmt *in_fmt, *out_fmt;
in_fmt = &m_cfg->in_fmt[0];
out_fmt = &m_cfg->out_fmt[0];
if (params->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (is_fe) {
in_fixup = m_cfg->params_fixup;
out_fixup = (~m_cfg->converter) &
m_cfg->params_fixup;
} else {
out_fixup = m_cfg->params_fixup;
in_fixup = (~m_cfg->converter) &
m_cfg->params_fixup;
}
} else {
if (is_fe) {
out_fixup = m_cfg->params_fixup;
in_fixup = (~m_cfg->converter) &
m_cfg->params_fixup;
} else {
in_fixup = m_cfg->params_fixup;
out_fixup = (~m_cfg->converter) &
m_cfg->params_fixup;
}
}
skl_tplg_update_params(in_fmt, params, in_fixup);
skl_tplg_update_params(out_fmt, params, out_fixup);
}
static void skl_tplg_update_buffer_size(struct skl_sst *ctx,
struct skl_module_cfg *mcfg)
{
int multiplier = 1;
struct skl_module_fmt *in_fmt, *out_fmt;
int in_rate, out_rate;
in_fmt = &mcfg->in_fmt[0];
out_fmt = &mcfg->out_fmt[0];
if (mcfg->m_type == SKL_MODULE_TYPE_SRCINT)
multiplier = 5;
if (in_fmt->s_freq % 1000)
in_rate = (in_fmt->s_freq / 1000) + 1;
else
in_rate = (in_fmt->s_freq / 1000);
mcfg->ibs = in_rate * (mcfg->in_fmt->channels) *
(mcfg->in_fmt->bit_depth >> 3) *
multiplier;
if (mcfg->out_fmt->s_freq % 1000)
out_rate = (mcfg->out_fmt->s_freq / 1000) + 1;
else
out_rate = (mcfg->out_fmt->s_freq / 1000);
mcfg->obs = out_rate * (mcfg->out_fmt->channels) *
(mcfg->out_fmt->bit_depth >> 3) *
multiplier;
}
static int skl_tplg_update_be_blob(struct snd_soc_dapm_widget *w,
struct skl_sst *ctx)
{
struct skl_module_cfg *m_cfg = w->priv;
int link_type, dir;
u32 ch, s_freq, s_fmt;
struct nhlt_specific_cfg *cfg;
struct skl *skl = get_skl_ctx(ctx->dev);
if (m_cfg->formats_config.caps_size > 0)
return 0;
dev_dbg(ctx->dev, "Applying default cfg blob\n");
switch (m_cfg->dev_type) {
case SKL_DEVICE_DMIC:
link_type = NHLT_LINK_DMIC;
dir = SNDRV_PCM_STREAM_CAPTURE;
s_freq = m_cfg->in_fmt[0].s_freq;
s_fmt = m_cfg->in_fmt[0].bit_depth;
ch = m_cfg->in_fmt[0].channels;
break;
case SKL_DEVICE_I2S:
link_type = NHLT_LINK_SSP;
if (m_cfg->hw_conn_type == SKL_CONN_SOURCE) {
dir = SNDRV_PCM_STREAM_PLAYBACK;
s_freq = m_cfg->out_fmt[0].s_freq;
s_fmt = m_cfg->out_fmt[0].bit_depth;
ch = m_cfg->out_fmt[0].channels;
} else {
dir = SNDRV_PCM_STREAM_CAPTURE;
s_freq = m_cfg->in_fmt[0].s_freq;
s_fmt = m_cfg->in_fmt[0].bit_depth;
ch = m_cfg->in_fmt[0].channels;
}
break;
default:
return -EINVAL;
}
cfg = skl_get_ep_blob(skl, m_cfg->vbus_id, link_type,
s_fmt, ch, s_freq, dir);
if (cfg) {
m_cfg->formats_config.caps_size = cfg->size;
m_cfg->formats_config.caps = (u32 *) &cfg->caps;
} else {
dev_err(ctx->dev, "Blob NULL for id %x type %d dirn %d\n",
m_cfg->vbus_id, link_type, dir);
dev_err(ctx->dev, "PCM: ch %d, freq %d, fmt %d\n",
ch, s_freq, s_fmt);
return -EIO;
}
return 0;
}
static void skl_tplg_update_module_params(struct snd_soc_dapm_widget *w,
struct skl_sst *ctx)
{
struct skl_module_cfg *m_cfg = w->priv;
struct skl_pipe_params *params = m_cfg->pipe->p_params;
int p_conn_type = m_cfg->pipe->conn_type;
bool is_fe;
if (!m_cfg->params_fixup)
return;
dev_dbg(ctx->dev, "Mconfig for widget=%s BEFORE updation\n",
w->name);
skl_dump_mconfig(ctx, m_cfg);
if (p_conn_type == SKL_PIPE_CONN_TYPE_FE)
is_fe = true;
else
is_fe = false;
skl_tplg_update_params_fixup(m_cfg, params, is_fe);
skl_tplg_update_buffer_size(ctx, m_cfg);
dev_dbg(ctx->dev, "Mconfig for widget=%s AFTER updation\n",
w->name);
skl_dump_mconfig(ctx, m_cfg);
}
static int skl_tplg_set_module_params(struct snd_soc_dapm_widget *w,
struct skl_sst *ctx)
{
int i, ret;
struct skl_module_cfg *mconfig = w->priv;
const struct snd_kcontrol_new *k;
struct soc_bytes_ext *sb;
struct skl_algo_data *bc;
struct skl_specific_cfg *sp_cfg;
if (mconfig->formats_config.caps_size > 0 &&
mconfig->formats_config.set_params == SKL_PARAM_SET) {
sp_cfg = &mconfig->formats_config;
ret = skl_set_module_params(ctx, sp_cfg->caps,
sp_cfg->caps_size,
sp_cfg->param_id, mconfig);
if (ret < 0)
return ret;
}
for (i = 0; i < w->num_kcontrols; i++) {
k = &w->kcontrol_news[i];
if (k->access & SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK) {
sb = (void *) k->private_value;
bc = (struct skl_algo_data *)sb->dobj.private;
if (bc->set_params == SKL_PARAM_SET) {
ret = skl_set_module_params(ctx,
(u32 *)bc->params, bc->size,
bc->param_id, mconfig);
if (ret < 0)
return ret;
}
}
}
return 0;
}
static int skl_tplg_set_module_init_data(struct snd_soc_dapm_widget *w)
{
const struct snd_kcontrol_new *k;
struct soc_bytes_ext *sb;
struct skl_algo_data *bc;
struct skl_module_cfg *mconfig = w->priv;
int i;
for (i = 0; i < w->num_kcontrols; i++) {
k = &w->kcontrol_news[i];
if (k->access & SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK) {
sb = (struct soc_bytes_ext *)k->private_value;
bc = (struct skl_algo_data *)sb->dobj.private;
if (bc->set_params != SKL_PARAM_INIT)
continue;
mconfig->formats_config.caps = (u32 *)&bc->params;
mconfig->formats_config.caps_size = bc->size;
break;
}
}
return 0;
}
static int
skl_tplg_init_pipe_modules(struct skl *skl, struct skl_pipe *pipe)
{
struct skl_pipe_module *w_module;
struct snd_soc_dapm_widget *w;
struct skl_module_cfg *mconfig;
struct skl_sst *ctx = skl->skl_sst;
int ret = 0;
list_for_each_entry(w_module, &pipe->w_list, node) {
w = w_module->w;
mconfig = w->priv;
if (mconfig->id.module_id < 0) {
dev_err(skl->skl_sst->dev,
"module %pUL id not populated\n",
(uuid_le *)mconfig->guid);
return -EIO;
}
if (!skl_is_pipe_mcps_avail(skl, mconfig))
return -ENOMEM;
if (mconfig->is_loadable && ctx->dsp->fw_ops.load_mod) {
ret = ctx->dsp->fw_ops.load_mod(ctx->dsp,
mconfig->id.module_id, mconfig->guid);
if (ret < 0)
return ret;
mconfig->m_state = SKL_MODULE_LOADED;
}
skl_tplg_update_be_blob(w, ctx);
skl_tplg_update_module_params(w, ctx);
mconfig->id.pvt_id = skl_get_pvt_id(ctx, mconfig);
if (mconfig->id.pvt_id < 0)
return ret;
skl_tplg_set_module_init_data(w);
ret = skl_init_module(ctx, mconfig);
if (ret < 0) {
skl_put_pvt_id(ctx, mconfig);
return ret;
}
skl_tplg_alloc_pipe_mcps(skl, mconfig);
ret = skl_tplg_set_module_params(w, ctx);
if (ret < 0)
return ret;
}
return 0;
}
static int skl_tplg_unload_pipe_modules(struct skl_sst *ctx,
struct skl_pipe *pipe)
{
int ret;
struct skl_pipe_module *w_module = NULL;
struct skl_module_cfg *mconfig = NULL;
list_for_each_entry(w_module, &pipe->w_list, node) {
mconfig = w_module->w->priv;
if (mconfig->is_loadable && ctx->dsp->fw_ops.unload_mod &&
mconfig->m_state > SKL_MODULE_UNINIT) {
ret = ctx->dsp->fw_ops.unload_mod(ctx->dsp,
mconfig->id.module_id);
if (ret < 0)
return -EIO;
}
skl_put_pvt_id(ctx, mconfig);
}
return 0;
}
static int skl_tplg_mixer_dapm_pre_pmu_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
int ret;
struct skl_module_cfg *mconfig = w->priv;
struct skl_pipe_module *w_module;
struct skl_pipe *s_pipe = mconfig->pipe;
struct skl_module_cfg *src_module = NULL, *dst_module;
struct skl_sst *ctx = skl->skl_sst;
if (!skl_is_pipe_mcps_avail(skl, mconfig))
return -EBUSY;
if (!skl_is_pipe_mem_avail(skl, mconfig))
return -ENOMEM;
ret = skl_create_pipeline(ctx, mconfig->pipe);
if (ret < 0)
return ret;
skl_tplg_alloc_pipe_mem(skl, mconfig);
skl_tplg_alloc_pipe_mcps(skl, mconfig);
ret = skl_tplg_init_pipe_modules(skl, s_pipe);
if (ret < 0)
return ret;
list_for_each_entry(w_module, &s_pipe->w_list, node) {
dst_module = w_module->w->priv;
if (src_module == NULL) {
src_module = dst_module;
continue;
}
ret = skl_bind_modules(ctx, src_module, dst_module);
if (ret < 0)
return ret;
src_module = dst_module;
}
return 0;
}
static int skl_fill_sink_instance_id(struct skl_sst *ctx,
struct skl_algo_data *alg_data)
{
struct skl_kpb_params *params = (struct skl_kpb_params *)alg_data->params;
struct skl_mod_inst_map *inst;
int i, pvt_id;
inst = params->map;
for (i = 0; i < params->num_modules; i++) {
pvt_id = skl_get_pvt_instance_id_map(ctx,
inst->mod_id, inst->inst_id);
if (pvt_id < 0)
return -EINVAL;
inst->inst_id = pvt_id;
inst++;
}
return 0;
}
static int skl_tplg_set_module_bind_params(struct snd_soc_dapm_widget *w,
struct skl_module_cfg *mcfg, struct skl_sst *ctx)
{
int i, ret;
struct skl_module_cfg *mconfig = w->priv;
const struct snd_kcontrol_new *k;
struct soc_bytes_ext *sb;
struct skl_algo_data *bc;
struct skl_specific_cfg *sp_cfg;
for (i = 0; i < mcfg->max_out_queue; i++) {
if (mcfg->m_out_pin[i].pin_state != SKL_PIN_BIND_DONE)
return 0;
}
for (i = 0; i < mcfg->max_in_queue; i++) {
if (mcfg->m_in_pin[i].pin_state != SKL_PIN_BIND_DONE)
return 0;
}
if (mconfig->formats_config.caps_size > 0 &&
mconfig->formats_config.set_params == SKL_PARAM_BIND) {
sp_cfg = &mconfig->formats_config;
ret = skl_set_module_params(ctx, sp_cfg->caps,
sp_cfg->caps_size,
sp_cfg->param_id, mconfig);
if (ret < 0)
return ret;
}
for (i = 0; i < w->num_kcontrols; i++) {
k = &w->kcontrol_news[i];
if (k->access & SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK) {
sb = (void *) k->private_value;
bc = (struct skl_algo_data *)sb->dobj.private;
if (bc->set_params == SKL_PARAM_BIND) {
if (mconfig->m_type == SKL_MODULE_TYPE_KPB)
skl_fill_sink_instance_id(ctx, bc);
ret = skl_set_module_params(ctx,
(u32 *)bc->params, bc->max,
bc->param_id, mconfig);
if (ret < 0)
return ret;
}
}
}
return 0;
}
static int skl_tplg_bind_sinks(struct snd_soc_dapm_widget *w,
struct skl *skl,
struct snd_soc_dapm_widget *src_w,
struct skl_module_cfg *src_mconfig)
{
struct snd_soc_dapm_path *p;
struct snd_soc_dapm_widget *sink = NULL, *next_sink = NULL;
struct skl_module_cfg *sink_mconfig;
struct skl_sst *ctx = skl->skl_sst;
int ret;
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if (!p->connect)
continue;
dev_dbg(ctx->dev, "%s: src widget=%s\n", __func__, w->name);
dev_dbg(ctx->dev, "%s: sink widget=%s\n", __func__, p->sink->name);
next_sink = p->sink;
if (!is_skl_dsp_widget_type(p->sink))
return skl_tplg_bind_sinks(p->sink, skl, src_w, src_mconfig);
if ((p->sink->priv != NULL) &&
is_skl_dsp_widget_type(p->sink)) {
sink = p->sink;
sink_mconfig = sink->priv;
if (src_mconfig->m_state == SKL_MODULE_UNINIT ||
sink_mconfig->m_state == SKL_MODULE_UNINIT)
continue;
ret = skl_bind_modules(ctx, src_mconfig, sink_mconfig);
if (ret)
return ret;
skl_tplg_set_module_bind_params(src_w, src_mconfig, ctx);
skl_tplg_set_module_bind_params(sink, sink_mconfig, ctx);
if (sink_mconfig->pipe->state != SKL_PIPE_STARTED) {
if (sink_mconfig->pipe->conn_type !=
SKL_PIPE_CONN_TYPE_FE)
ret = skl_run_pipe(ctx,
sink_mconfig->pipe);
if (ret)
return ret;
}
}
}
if (!sink)
return skl_tplg_bind_sinks(next_sink, skl, src_w, src_mconfig);
return 0;
}
static int skl_tplg_pga_dapm_pre_pmu_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct skl_module_cfg *src_mconfig;
struct skl_sst *ctx = skl->skl_sst;
int ret = 0;
src_mconfig = w->priv;
ret = skl_tplg_bind_sinks(w, skl, w, src_mconfig);
if (ret)
return ret;
if (src_mconfig->pipe->conn_type != SKL_PIPE_CONN_TYPE_FE)
return skl_run_pipe(ctx, src_mconfig->pipe);
return 0;
}
static struct snd_soc_dapm_widget *skl_get_src_dsp_widget(
struct snd_soc_dapm_widget *w, struct skl *skl)
{
struct snd_soc_dapm_path *p;
struct snd_soc_dapm_widget *src_w = NULL;
struct skl_sst *ctx = skl->skl_sst;
snd_soc_dapm_widget_for_each_source_path(w, p) {
src_w = p->source;
if (!p->connect)
continue;
dev_dbg(ctx->dev, "sink widget=%s\n", w->name);
dev_dbg(ctx->dev, "src widget=%s\n", p->source->name);
if ((p->source->priv != NULL) &&
is_skl_dsp_widget_type(p->source)) {
return p->source;
}
}
if (src_w != NULL)
return skl_get_src_dsp_widget(src_w, skl);
return NULL;
}
static int skl_tplg_mixer_dapm_post_pmu_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
int ret = 0;
struct snd_soc_dapm_widget *source, *sink;
struct skl_module_cfg *src_mconfig, *sink_mconfig;
struct skl_sst *ctx = skl->skl_sst;
int src_pipe_started = 0;
sink = w;
sink_mconfig = sink->priv;
source = skl_get_src_dsp_widget(w, skl);
if (source != NULL) {
src_mconfig = source->priv;
sink_mconfig = sink->priv;
src_pipe_started = 1;
if (src_mconfig->pipe->state != SKL_PIPE_STARTED)
src_pipe_started = 0;
}
if (src_pipe_started) {
ret = skl_bind_modules(ctx, src_mconfig, sink_mconfig);
if (ret)
return ret;
skl_tplg_set_module_bind_params(source, src_mconfig, ctx);
skl_tplg_set_module_bind_params(sink, sink_mconfig, ctx);
if (sink_mconfig->pipe->conn_type != SKL_PIPE_CONN_TYPE_FE)
ret = skl_run_pipe(ctx, sink_mconfig->pipe);
}
return ret;
}
static int skl_tplg_mixer_dapm_pre_pmd_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct skl_module_cfg *src_mconfig, *sink_mconfig;
int ret = 0, i;
struct skl_sst *ctx = skl->skl_sst;
sink_mconfig = w->priv;
ret = skl_stop_pipe(ctx, sink_mconfig->pipe);
if (ret)
return ret;
for (i = 0; i < sink_mconfig->max_in_queue; i++) {
if (sink_mconfig->m_in_pin[i].pin_state == SKL_PIN_BIND_DONE) {
src_mconfig = sink_mconfig->m_in_pin[i].tgt_mcfg;
if (!src_mconfig)
continue;
ret = skl_stop_pipe(ctx, src_mconfig->pipe);
if (ret < 0)
return ret;
ret = skl_unbind_modules(ctx,
src_mconfig, sink_mconfig);
}
}
return ret;
}
static int skl_tplg_mixer_dapm_post_pmd_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct skl_module_cfg *mconfig = w->priv;
struct skl_pipe_module *w_module;
struct skl_module_cfg *src_module = NULL, *dst_module;
struct skl_sst *ctx = skl->skl_sst;
struct skl_pipe *s_pipe = mconfig->pipe;
int ret = 0;
if (s_pipe->state == SKL_PIPE_INVALID)
return -EINVAL;
skl_tplg_free_pipe_mcps(skl, mconfig);
skl_tplg_free_pipe_mem(skl, mconfig);
list_for_each_entry(w_module, &s_pipe->w_list, node) {
dst_module = w_module->w->priv;
if (mconfig->m_state >= SKL_MODULE_INIT_DONE)
skl_tplg_free_pipe_mcps(skl, dst_module);
if (src_module == NULL) {
src_module = dst_module;
continue;
}
skl_unbind_modules(ctx, src_module, dst_module);
src_module = dst_module;
}
ret = skl_delete_pipe(ctx, mconfig->pipe);
return skl_tplg_unload_pipe_modules(ctx, s_pipe);
}
static int skl_tplg_pga_dapm_post_pmd_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct skl_module_cfg *src_mconfig, *sink_mconfig;
int ret = 0, i;
struct skl_sst *ctx = skl->skl_sst;
src_mconfig = w->priv;
ret = skl_stop_pipe(ctx, src_mconfig->pipe);
if (ret)
return ret;
for (i = 0; i < src_mconfig->max_out_queue; i++) {
if (src_mconfig->m_out_pin[i].pin_state == SKL_PIN_BIND_DONE) {
sink_mconfig = src_mconfig->m_out_pin[i].tgt_mcfg;
if (!sink_mconfig)
continue;
ret = skl_unbind_modules(ctx, src_mconfig,
sink_mconfig);
}
}
return ret;
}
static int skl_tplg_vmixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct skl *skl = get_skl_ctx(dapm->dev);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return skl_tplg_mixer_dapm_pre_pmu_event(w, skl);
case SND_SOC_DAPM_POST_PMU:
return skl_tplg_mixer_dapm_post_pmu_event(w, skl);
case SND_SOC_DAPM_PRE_PMD:
return skl_tplg_mixer_dapm_pre_pmd_event(w, skl);
case SND_SOC_DAPM_POST_PMD:
return skl_tplg_mixer_dapm_post_pmd_event(w, skl);
}
return 0;
}
static int skl_tplg_mixer_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct skl *skl = get_skl_ctx(dapm->dev);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return skl_tplg_mixer_dapm_pre_pmu_event(w, skl);
case SND_SOC_DAPM_POST_PMU:
return skl_tplg_mixer_dapm_post_pmu_event(w, skl);
case SND_SOC_DAPM_PRE_PMD:
return skl_tplg_mixer_dapm_pre_pmd_event(w, skl);
case SND_SOC_DAPM_POST_PMD:
return skl_tplg_mixer_dapm_post_pmd_event(w, skl);
}
return 0;
}
static int skl_tplg_pga_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct skl *skl = get_skl_ctx(dapm->dev);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
return skl_tplg_pga_dapm_pre_pmu_event(w, skl);
case SND_SOC_DAPM_POST_PMD:
return skl_tplg_pga_dapm_post_pmd_event(w, skl);
}
return 0;
}
static int skl_tplg_tlv_control_get(struct snd_kcontrol *kcontrol,
unsigned int __user *data, unsigned int size)
{
struct soc_bytes_ext *sb =
(struct soc_bytes_ext *)kcontrol->private_value;
struct skl_algo_data *bc = (struct skl_algo_data *)sb->dobj.private;
struct snd_soc_dapm_widget *w = snd_soc_dapm_kcontrol_widget(kcontrol);
struct skl_module_cfg *mconfig = w->priv;
struct skl *skl = get_skl_ctx(w->dapm->dev);
if (w->power)
skl_get_module_params(skl->skl_sst, (u32 *)bc->params,
bc->size, bc->param_id, mconfig);
size -= 2 * sizeof(u32);
if (size > bc->max)
size = bc->max;
if (bc->params) {
if (copy_to_user(data, &bc->param_id, sizeof(u32)))
return -EFAULT;
if (copy_to_user(data + 1, &size, sizeof(u32)))
return -EFAULT;
if (copy_to_user(data + 2, bc->params, size))
return -EFAULT;
}
return 0;
}
static int skl_tplg_tlv_control_set(struct snd_kcontrol *kcontrol,
const unsigned int __user *data, unsigned int size)
{
struct snd_soc_dapm_widget *w = snd_soc_dapm_kcontrol_widget(kcontrol);
struct skl_module_cfg *mconfig = w->priv;
struct soc_bytes_ext *sb =
(struct soc_bytes_ext *)kcontrol->private_value;
struct skl_algo_data *ac = (struct skl_algo_data *)sb->dobj.private;
struct skl *skl = get_skl_ctx(w->dapm->dev);
if (ac->params) {
if (size > ac->max)
return -EINVAL;
ac->size = size;
if (ac->param_id == SKL_PARAM_VENDOR_ID) {
if (copy_from_user(ac->params, data, size))
return -EFAULT;
} else {
if (copy_from_user(ac->params,
data + 2, size))
return -EFAULT;
}
if (w->power)
return skl_set_module_params(skl->skl_sst,
(u32 *)ac->params, ac->size,
ac->param_id, mconfig);
}
return 0;
}
static void skl_tplg_fill_dma_id(struct skl_module_cfg *mcfg,
struct skl_pipe_params *params)
{
struct skl_pipe *pipe = mcfg->pipe;
if (pipe->passthru) {
switch (mcfg->dev_type) {
case SKL_DEVICE_HDALINK:
pipe->p_params->link_dma_id = params->link_dma_id;
break;
case SKL_DEVICE_HDAHOST:
pipe->p_params->host_dma_id = params->host_dma_id;
break;
default:
break;
}
pipe->p_params->s_fmt = params->s_fmt;
pipe->p_params->ch = params->ch;
pipe->p_params->s_freq = params->s_freq;
pipe->p_params->stream = params->stream;
} else {
memcpy(pipe->p_params, params, sizeof(*params));
}
}
int skl_tplg_update_pipe_params(struct device *dev,
struct skl_module_cfg *mconfig,
struct skl_pipe_params *params)
{
struct skl_module_fmt *format = NULL;
skl_tplg_fill_dma_id(mconfig, params);
if (params->stream == SNDRV_PCM_STREAM_PLAYBACK)
format = &mconfig->in_fmt[0];
else
format = &mconfig->out_fmt[0];
format->s_freq = params->s_freq;
format->channels = params->ch;
format->valid_bit_depth = skl_get_bit_depth(params->s_fmt);
switch (format->valid_bit_depth) {
case SKL_DEPTH_16BIT:
format->bit_depth = format->valid_bit_depth;
break;
case SKL_DEPTH_24BIT:
case SKL_DEPTH_32BIT:
format->bit_depth = SKL_DEPTH_32BIT;
break;
default:
dev_err(dev, "Invalid bit depth %x for pipe\n",
format->valid_bit_depth);
return -EINVAL;
}
if (params->stream == SNDRV_PCM_STREAM_PLAYBACK) {
mconfig->ibs = (format->s_freq / 1000) *
(format->channels) *
(format->bit_depth >> 3);
} else {
mconfig->obs = (format->s_freq / 1000) *
(format->channels) *
(format->bit_depth >> 3);
}
return 0;
}
struct skl_module_cfg *
skl_tplg_fe_get_cpr_module(struct snd_soc_dai *dai, int stream)
{
struct snd_soc_dapm_widget *w;
struct snd_soc_dapm_path *p = NULL;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
w = dai->playback_widget;
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if (p->connect && p->sink->power &&
!is_skl_dsp_widget_type(p->sink))
continue;
if (p->sink->priv) {
dev_dbg(dai->dev, "set params for %s\n",
p->sink->name);
return p->sink->priv;
}
}
} else {
w = dai->capture_widget;
snd_soc_dapm_widget_for_each_source_path(w, p) {
if (p->connect && p->source->power &&
!is_skl_dsp_widget_type(p->source))
continue;
if (p->source->priv) {
dev_dbg(dai->dev, "set params for %s\n",
p->source->name);
return p->source->priv;
}
}
}
return NULL;
}
static struct skl_module_cfg *skl_get_mconfig_pb_cpr(
struct snd_soc_dai *dai, struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_path *p;
struct skl_module_cfg *mconfig = NULL;
snd_soc_dapm_widget_for_each_source_path(w, p) {
if (w->endpoints[SND_SOC_DAPM_DIR_OUT] > 0) {
if (p->connect &&
(p->sink->id == snd_soc_dapm_aif_out) &&
p->source->priv) {
mconfig = p->source->priv;
return mconfig;
}
mconfig = skl_get_mconfig_pb_cpr(dai, p->source);
if (mconfig)
return mconfig;
}
}
return mconfig;
}
static struct skl_module_cfg *skl_get_mconfig_cap_cpr(
struct snd_soc_dai *dai, struct snd_soc_dapm_widget *w)
{
struct snd_soc_dapm_path *p;
struct skl_module_cfg *mconfig = NULL;
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if (w->endpoints[SND_SOC_DAPM_DIR_IN] > 0) {
if (p->connect &&
(p->source->id == snd_soc_dapm_aif_in) &&
p->sink->priv) {
mconfig = p->sink->priv;
return mconfig;
}
mconfig = skl_get_mconfig_cap_cpr(dai, p->sink);
if (mconfig)
return mconfig;
}
}
return mconfig;
}
struct skl_module_cfg *
skl_tplg_be_get_cpr_module(struct snd_soc_dai *dai, int stream)
{
struct snd_soc_dapm_widget *w;
struct skl_module_cfg *mconfig;
if (stream == SNDRV_PCM_STREAM_PLAYBACK) {
w = dai->playback_widget;
mconfig = skl_get_mconfig_pb_cpr(dai, w);
} else {
w = dai->capture_widget;
mconfig = skl_get_mconfig_cap_cpr(dai, w);
}
return mconfig;
}
static u8 skl_tplg_be_link_type(int dev_type)
{
int ret;
switch (dev_type) {
case SKL_DEVICE_BT:
ret = NHLT_LINK_SSP;
break;
case SKL_DEVICE_DMIC:
ret = NHLT_LINK_DMIC;
break;
case SKL_DEVICE_I2S:
ret = NHLT_LINK_SSP;
break;
case SKL_DEVICE_HDALINK:
ret = NHLT_LINK_HDA;
break;
default:
ret = NHLT_LINK_INVALID;
break;
}
return ret;
}
static int skl_tplg_be_fill_pipe_params(struct snd_soc_dai *dai,
struct skl_module_cfg *mconfig,
struct skl_pipe_params *params)
{
struct nhlt_specific_cfg *cfg;
struct skl *skl = get_skl_ctx(dai->dev);
int link_type = skl_tplg_be_link_type(mconfig->dev_type);
skl_tplg_fill_dma_id(mconfig, params);
if (link_type == NHLT_LINK_HDA)
return 0;
cfg = skl_get_ep_blob(skl, mconfig->vbus_id, link_type,
params->s_fmt, params->ch,
params->s_freq, params->stream);
if (cfg) {
mconfig->formats_config.caps_size = cfg->size;
mconfig->formats_config.caps = (u32 *) &cfg->caps;
} else {
dev_err(dai->dev, "Blob NULL for id %x type %d dirn %d\n",
mconfig->vbus_id, link_type,
params->stream);
dev_err(dai->dev, "PCM: ch %d, freq %d, fmt %d\n",
params->ch, params->s_freq, params->s_fmt);
return -EINVAL;
}
return 0;
}
static int skl_tplg_be_set_src_pipe_params(struct snd_soc_dai *dai,
struct snd_soc_dapm_widget *w,
struct skl_pipe_params *params)
{
struct snd_soc_dapm_path *p;
int ret = -EIO;
snd_soc_dapm_widget_for_each_source_path(w, p) {
if (p->connect && is_skl_dsp_widget_type(p->source) &&
p->source->priv) {
ret = skl_tplg_be_fill_pipe_params(dai,
p->source->priv, params);
if (ret < 0)
return ret;
} else {
ret = skl_tplg_be_set_src_pipe_params(dai,
p->source, params);
if (ret < 0)
return ret;
}
}
return ret;
}
static int skl_tplg_be_set_sink_pipe_params(struct snd_soc_dai *dai,
struct snd_soc_dapm_widget *w, struct skl_pipe_params *params)
{
struct snd_soc_dapm_path *p = NULL;
int ret = -EIO;
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if (p->connect && is_skl_dsp_widget_type(p->sink) &&
p->sink->priv) {
ret = skl_tplg_be_fill_pipe_params(dai,
p->sink->priv, params);
if (ret < 0)
return ret;
} else {
ret = skl_tplg_be_set_sink_pipe_params(
dai, p->sink, params);
if (ret < 0)
return ret;
}
}
return ret;
}
int skl_tplg_be_update_params(struct snd_soc_dai *dai,
struct skl_pipe_params *params)
{
struct snd_soc_dapm_widget *w;
if (params->stream == SNDRV_PCM_STREAM_PLAYBACK) {
w = dai->playback_widget;
return skl_tplg_be_set_src_pipe_params(dai, w, params);
} else {
w = dai->capture_widget;
return skl_tplg_be_set_sink_pipe_params(dai, w, params);
}
return 0;
}
static int skl_tplg_fill_pipe_tkn(struct device *dev,
struct skl_pipe *pipe, u32 tkn,
u32 tkn_val)
{
switch (tkn) {
case SKL_TKN_U32_PIPE_CONN_TYPE:
pipe->conn_type = tkn_val;
break;
case SKL_TKN_U32_PIPE_PRIORITY:
pipe->pipe_priority = tkn_val;
break;
case SKL_TKN_U32_PIPE_MEM_PGS:
pipe->memory_pages = tkn_val;
break;
case SKL_TKN_U32_PMODE:
pipe->lp_mode = tkn_val;
break;
default:
dev_err(dev, "Token not handled %d\n", tkn);
return -EINVAL;
}
return 0;
}
static int skl_tplg_add_pipe(struct device *dev,
struct skl_module_cfg *mconfig, struct skl *skl,
struct snd_soc_tplg_vendor_value_elem *tkn_elem)
{
struct skl_pipeline *ppl;
struct skl_pipe *pipe;
struct skl_pipe_params *params;
list_for_each_entry(ppl, &skl->ppl_list, node) {
if (ppl->pipe->ppl_id == tkn_elem->value) {
mconfig->pipe = ppl->pipe;
return EEXIST;
}
}
ppl = devm_kzalloc(dev, sizeof(*ppl), GFP_KERNEL);
if (!ppl)
return -ENOMEM;
pipe = devm_kzalloc(dev, sizeof(*pipe), GFP_KERNEL);
if (!pipe)
return -ENOMEM;
params = devm_kzalloc(dev, sizeof(*params), GFP_KERNEL);
if (!params)
return -ENOMEM;
pipe->p_params = params;
pipe->ppl_id = tkn_elem->value;
INIT_LIST_HEAD(&pipe->w_list);
ppl->pipe = pipe;
list_add(&ppl->node, &skl->ppl_list);
mconfig->pipe = pipe;
mconfig->pipe->state = SKL_PIPE_INVALID;
return 0;
}
static int skl_tplg_fill_pin(struct device *dev, u32 tkn,
struct skl_module_pin *m_pin,
int pin_index, u32 value)
{
switch (tkn) {
case SKL_TKN_U32_PIN_MOD_ID:
m_pin[pin_index].id.module_id = value;
break;
case SKL_TKN_U32_PIN_INST_ID:
m_pin[pin_index].id.instance_id = value;
break;
default:
dev_err(dev, "%d Not a pin token\n", value);
return -EINVAL;
}
return 0;
}
static int skl_tplg_fill_pins_info(struct device *dev,
struct skl_module_cfg *mconfig,
struct snd_soc_tplg_vendor_value_elem *tkn_elem,
int dir, int pin_count)
{
int ret;
struct skl_module_pin *m_pin;
switch (dir) {
case SKL_DIR_IN:
m_pin = mconfig->m_in_pin;
break;
case SKL_DIR_OUT:
m_pin = mconfig->m_out_pin;
break;
default:
dev_err(dev, "Invalid direction value\n");
return -EINVAL;
}
ret = skl_tplg_fill_pin(dev, tkn_elem->token,
m_pin, pin_count, tkn_elem->value);
if (ret < 0)
return ret;
m_pin[pin_count].in_use = false;
m_pin[pin_count].pin_state = SKL_PIN_UNBIND;
return 0;
}
static int skl_tplg_fill_fmt(struct device *dev,
struct skl_module_cfg *mconfig, u32 tkn,
u32 value, u32 dir, u32 pin_count)
{
struct skl_module_fmt *dst_fmt;
switch (dir) {
case SKL_DIR_IN:
dst_fmt = mconfig->in_fmt;
dst_fmt += pin_count;
break;
case SKL_DIR_OUT:
dst_fmt = mconfig->out_fmt;
dst_fmt += pin_count;
break;
default:
dev_err(dev, "Invalid direction value\n");
return -EINVAL;
}
switch (tkn) {
case SKL_TKN_U32_FMT_CH:
dst_fmt->channels = value;
break;
case SKL_TKN_U32_FMT_FREQ:
dst_fmt->s_freq = value;
break;
case SKL_TKN_U32_FMT_BIT_DEPTH:
dst_fmt->bit_depth = value;
break;
case SKL_TKN_U32_FMT_SAMPLE_SIZE:
dst_fmt->valid_bit_depth = value;
break;
case SKL_TKN_U32_FMT_CH_CONFIG:
dst_fmt->ch_cfg = value;
break;
case SKL_TKN_U32_FMT_INTERLEAVE:
dst_fmt->interleaving_style = value;
break;
case SKL_TKN_U32_FMT_SAMPLE_TYPE:
dst_fmt->sample_type = value;
break;
case SKL_TKN_U32_FMT_CH_MAP:
dst_fmt->ch_map = value;
break;
default:
dev_err(dev, "Invalid token %d\n", tkn);
return -EINVAL;
}
return 0;
}
static int skl_tplg_get_uuid(struct device *dev, struct skl_module_cfg *mconfig,
struct snd_soc_tplg_vendor_uuid_elem *uuid_tkn)
{
if (uuid_tkn->token == SKL_TKN_UUID)
memcpy(&mconfig->guid, &uuid_tkn->uuid, 16);
else {
dev_err(dev, "Not an UUID token tkn %d\n", uuid_tkn->token);
return -EINVAL;
}
return 0;
}
static void skl_tplg_fill_pin_dynamic_val(
struct skl_module_pin *mpin, u32 pin_count, u32 value)
{
int i;
for (i = 0; i < pin_count; i++)
mpin[i].is_dynamic = value;
}
static int skl_tplg_get_token(struct device *dev,
struct snd_soc_tplg_vendor_value_elem *tkn_elem,
struct skl *skl, struct skl_module_cfg *mconfig)
{
int tkn_count = 0;
int ret;
static int is_pipe_exists;
static int pin_index, dir;
if (tkn_elem->token > SKL_TKN_MAX)
return -EINVAL;
switch (tkn_elem->token) {
case SKL_TKN_U8_IN_QUEUE_COUNT:
mconfig->max_in_queue = tkn_elem->value;
mconfig->m_in_pin = devm_kzalloc(dev, mconfig->max_in_queue *
sizeof(*mconfig->m_in_pin),
GFP_KERNEL);
if (!mconfig->m_in_pin)
return -ENOMEM;
break;
case SKL_TKN_U8_OUT_QUEUE_COUNT:
mconfig->max_out_queue = tkn_elem->value;
mconfig->m_out_pin = devm_kzalloc(dev, mconfig->max_out_queue *
sizeof(*mconfig->m_out_pin),
GFP_KERNEL);
if (!mconfig->m_out_pin)
return -ENOMEM;
break;
case SKL_TKN_U8_DYN_IN_PIN:
if (!mconfig->m_in_pin)
return -ENOMEM;
skl_tplg_fill_pin_dynamic_val(mconfig->m_in_pin,
mconfig->max_in_queue, tkn_elem->value);
break;
case SKL_TKN_U8_DYN_OUT_PIN:
if (!mconfig->m_out_pin)
return -ENOMEM;
skl_tplg_fill_pin_dynamic_val(mconfig->m_out_pin,
mconfig->max_out_queue, tkn_elem->value);
break;
case SKL_TKN_U8_TIME_SLOT:
mconfig->time_slot = tkn_elem->value;
break;
case SKL_TKN_U8_CORE_ID:
mconfig->core_id = tkn_elem->value;
case SKL_TKN_U8_MOD_TYPE:
mconfig->m_type = tkn_elem->value;
break;
case SKL_TKN_U8_DEV_TYPE:
mconfig->dev_type = tkn_elem->value;
break;
case SKL_TKN_U8_HW_CONN_TYPE:
mconfig->hw_conn_type = tkn_elem->value;
break;
case SKL_TKN_U16_MOD_INST_ID:
mconfig->id.instance_id =
tkn_elem->value;
break;
case SKL_TKN_U32_MEM_PAGES:
mconfig->mem_pages = tkn_elem->value;
break;
case SKL_TKN_U32_MAX_MCPS:
mconfig->mcps = tkn_elem->value;
break;
case SKL_TKN_U32_OBS:
mconfig->obs = tkn_elem->value;
break;
case SKL_TKN_U32_IBS:
mconfig->ibs = tkn_elem->value;
break;
case SKL_TKN_U32_VBUS_ID:
mconfig->vbus_id = tkn_elem->value;
break;
case SKL_TKN_U32_PARAMS_FIXUP:
mconfig->params_fixup = tkn_elem->value;
break;
case SKL_TKN_U32_CONVERTER:
mconfig->converter = tkn_elem->value;
break;
case SKL_TKL_U32_D0I3_CAPS:
mconfig->d0i3_caps = tkn_elem->value;
break;
case SKL_TKN_U32_PIPE_ID:
ret = skl_tplg_add_pipe(dev,
mconfig, skl, tkn_elem);
if (ret < 0)
return is_pipe_exists;
if (ret == EEXIST)
is_pipe_exists = 1;
break;
case SKL_TKN_U32_PIPE_CONN_TYPE:
case SKL_TKN_U32_PIPE_PRIORITY:
case SKL_TKN_U32_PIPE_MEM_PGS:
case SKL_TKN_U32_PMODE:
if (is_pipe_exists) {
ret = skl_tplg_fill_pipe_tkn(dev, mconfig->pipe,
tkn_elem->token, tkn_elem->value);
if (ret < 0)
return ret;
}
break;
case SKL_TKN_U32_DIR_PIN_COUNT:
dir = tkn_elem->value & SKL_IN_DIR_BIT_MASK;
pin_index = (tkn_elem->value &
SKL_PIN_COUNT_MASK) >> 4;
break;
case SKL_TKN_U32_FMT_CH:
case SKL_TKN_U32_FMT_FREQ:
case SKL_TKN_U32_FMT_BIT_DEPTH:
case SKL_TKN_U32_FMT_SAMPLE_SIZE:
case SKL_TKN_U32_FMT_CH_CONFIG:
case SKL_TKN_U32_FMT_INTERLEAVE:
case SKL_TKN_U32_FMT_SAMPLE_TYPE:
case SKL_TKN_U32_FMT_CH_MAP:
ret = skl_tplg_fill_fmt(dev, mconfig, tkn_elem->token,
tkn_elem->value, dir, pin_index);
if (ret < 0)
return ret;
break;
case SKL_TKN_U32_PIN_MOD_ID:
case SKL_TKN_U32_PIN_INST_ID:
ret = skl_tplg_fill_pins_info(dev,
mconfig, tkn_elem, dir,
pin_index);
if (ret < 0)
return ret;
break;
case SKL_TKN_U32_CAPS_SIZE:
mconfig->formats_config.caps_size =
tkn_elem->value;
break;
case SKL_TKN_U32_PROC_DOMAIN:
mconfig->domain =
tkn_elem->value;
break;
case SKL_TKN_U8_IN_PIN_TYPE:
case SKL_TKN_U8_OUT_PIN_TYPE:
case SKL_TKN_U8_CONN_TYPE:
break;
default:
dev_err(dev, "Token %d not handled\n",
tkn_elem->token);
return -EINVAL;
}
tkn_count++;
return tkn_count;
}
static int skl_tplg_get_tokens(struct device *dev,
char *pvt_data, struct skl *skl,
struct skl_module_cfg *mconfig, int block_size)
{
struct snd_soc_tplg_vendor_array *array;
struct snd_soc_tplg_vendor_value_elem *tkn_elem;
int tkn_count = 0, ret;
int off = 0, tuple_size = 0;
if (block_size <= 0)
return -EINVAL;
while (tuple_size < block_size) {
array = (struct snd_soc_tplg_vendor_array *)(pvt_data + off);
off += array->size;
switch (array->type) {
case SND_SOC_TPLG_TUPLE_TYPE_STRING:
dev_warn(dev, "no string tokens expected for skl tplg\n");
continue;
case SND_SOC_TPLG_TUPLE_TYPE_UUID:
ret = skl_tplg_get_uuid(dev, mconfig, array->uuid);
if (ret < 0)
return ret;
tuple_size += sizeof(*array->uuid);
continue;
default:
tkn_elem = array->value;
tkn_count = 0;
break;
}
while (tkn_count <= (array->num_elems - 1)) {
ret = skl_tplg_get_token(dev, tkn_elem,
skl, mconfig);
if (ret < 0)
return ret;
tkn_count = tkn_count + ret;
tkn_elem++;
}
tuple_size += tkn_count * sizeof(*tkn_elem);
}
return 0;
}
static int skl_tplg_get_desc_blocks(struct device *dev,
struct snd_soc_tplg_vendor_array *array)
{
struct snd_soc_tplg_vendor_value_elem *tkn_elem;
tkn_elem = array->value;
switch (tkn_elem->token) {
case SKL_TKN_U8_NUM_BLOCKS:
case SKL_TKN_U8_BLOCK_TYPE:
case SKL_TKN_U16_BLOCK_SIZE:
return tkn_elem->value;
default:
dev_err(dev, "Invalid descriptor token %d\n", tkn_elem->token);
break;
}
return -EINVAL;
}
static int skl_tplg_get_pvt_data(struct snd_soc_tplg_dapm_widget *tplg_w,
struct skl *skl, struct device *dev,
struct skl_module_cfg *mconfig)
{
struct snd_soc_tplg_vendor_array *array;
int num_blocks, block_size = 0, block_type, off = 0;
char *data;
int ret;
array = (struct snd_soc_tplg_vendor_array *)tplg_w->priv.data;
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
num_blocks = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)(tplg_w->priv.data + off);
while (num_blocks > 0) {
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
block_type = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)
(tplg_w->priv.data + off);
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
block_size = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)
(tplg_w->priv.data + off);
data = (tplg_w->priv.data + off);
if (block_type == SKL_TYPE_TUPLE) {
ret = skl_tplg_get_tokens(dev, data,
skl, mconfig, block_size);
if (ret < 0)
return ret;
--num_blocks;
} else {
if (mconfig->formats_config.caps_size > 0)
memcpy(mconfig->formats_config.caps, data,
mconfig->formats_config.caps_size);
--num_blocks;
}
}
return 0;
}
static void skl_clear_pin_config(struct snd_soc_platform *platform,
struct snd_soc_dapm_widget *w)
{
int i;
struct skl_module_cfg *mconfig;
struct skl_pipe *pipe;
if (!strncmp(w->dapm->component->name, platform->component.name,
strlen(platform->component.name))) {
mconfig = w->priv;
pipe = mconfig->pipe;
for (i = 0; i < mconfig->max_in_queue; i++) {
mconfig->m_in_pin[i].in_use = false;
mconfig->m_in_pin[i].pin_state = SKL_PIN_UNBIND;
}
for (i = 0; i < mconfig->max_out_queue; i++) {
mconfig->m_out_pin[i].in_use = false;
mconfig->m_out_pin[i].pin_state = SKL_PIN_UNBIND;
}
pipe->state = SKL_PIPE_INVALID;
mconfig->m_state = SKL_MODULE_UNINIT;
}
}
void skl_cleanup_resources(struct skl *skl)
{
struct skl_sst *ctx = skl->skl_sst;
struct snd_soc_platform *soc_platform = skl->platform;
struct snd_soc_dapm_widget *w;
struct snd_soc_card *card;
if (soc_platform == NULL)
return;
card = soc_platform->component.card;
if (!card || !card->instantiated)
return;
skl->resource.mem = 0;
skl->resource.mcps = 0;
list_for_each_entry(w, &card->widgets, list) {
if (is_skl_dsp_widget_type(w) && (w->priv != NULL))
skl_clear_pin_config(soc_platform, w);
}
skl_clear_module_cnt(ctx->dsp);
}
static int skl_tplg_widget_load(struct snd_soc_component *cmpnt,
struct snd_soc_dapm_widget *w,
struct snd_soc_tplg_dapm_widget *tplg_w)
{
int ret;
struct hdac_ext_bus *ebus = snd_soc_component_get_drvdata(cmpnt);
struct skl *skl = ebus_to_skl(ebus);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl_module_cfg *mconfig;
if (!tplg_w->priv.size)
goto bind_event;
mconfig = devm_kzalloc(bus->dev, sizeof(*mconfig), GFP_KERNEL);
if (!mconfig)
return -ENOMEM;
w->priv = mconfig;
mconfig->id.module_id = -1;
ret = skl_tplg_get_pvt_data(tplg_w, skl, bus->dev, mconfig);
if (ret < 0)
return ret;
bind_event:
if (tplg_w->event_type == 0) {
dev_dbg(bus->dev, "ASoC: No event handler required\n");
return 0;
}
ret = snd_soc_tplg_widget_bind_event(w, skl_tplg_widget_ops,
ARRAY_SIZE(skl_tplg_widget_ops),
tplg_w->event_type);
if (ret) {
dev_err(bus->dev, "%s: No matching event handlers found for %d\n",
__func__, tplg_w->event_type);
return -EINVAL;
}
return 0;
}
static int skl_init_algo_data(struct device *dev, struct soc_bytes_ext *be,
struct snd_soc_tplg_bytes_control *bc)
{
struct skl_algo_data *ac;
struct skl_dfw_algo_data *dfw_ac =
(struct skl_dfw_algo_data *)bc->priv.data;
ac = devm_kzalloc(dev, sizeof(*ac), GFP_KERNEL);
if (!ac)
return -ENOMEM;
ac->max = dfw_ac->max;
ac->param_id = dfw_ac->param_id;
ac->set_params = dfw_ac->set_params;
ac->size = dfw_ac->max;
if (ac->max) {
ac->params = (char *) devm_kzalloc(dev, ac->max, GFP_KERNEL);
if (!ac->params)
return -ENOMEM;
memcpy(ac->params, dfw_ac->params, ac->max);
}
be->dobj.private = ac;
return 0;
}
static int skl_tplg_control_load(struct snd_soc_component *cmpnt,
struct snd_kcontrol_new *kctl,
struct snd_soc_tplg_ctl_hdr *hdr)
{
struct soc_bytes_ext *sb;
struct snd_soc_tplg_bytes_control *tplg_bc;
struct hdac_ext_bus *ebus = snd_soc_component_get_drvdata(cmpnt);
struct hdac_bus *bus = ebus_to_hbus(ebus);
switch (hdr->ops.info) {
case SND_SOC_TPLG_CTL_BYTES:
tplg_bc = container_of(hdr,
struct snd_soc_tplg_bytes_control, hdr);
if (kctl->access & SNDRV_CTL_ELEM_ACCESS_TLV_CALLBACK) {
sb = (struct soc_bytes_ext *)kctl->private_value;
if (tplg_bc->priv.size)
return skl_init_algo_data(
bus->dev, sb, tplg_bc);
}
break;
default:
dev_warn(bus->dev, "Control load not supported %d:%d:%d\n",
hdr->ops.get, hdr->ops.put, hdr->ops.info);
break;
}
return 0;
}
static int skl_tplg_fill_str_mfest_tkn(struct device *dev,
struct snd_soc_tplg_vendor_string_elem *str_elem,
struct skl_dfw_manifest *minfo)
{
int tkn_count = 0;
static int ref_count;
switch (str_elem->token) {
case SKL_TKN_STR_LIB_NAME:
if (ref_count > minfo->lib_count - 1) {
ref_count = 0;
return -EINVAL;
}
strncpy(minfo->lib[ref_count].name, str_elem->string,
ARRAY_SIZE(minfo->lib[ref_count].name));
ref_count++;
tkn_count++;
break;
default:
dev_err(dev, "Not a string token %d\n", str_elem->token);
break;
}
return tkn_count;
}
static int skl_tplg_get_str_tkn(struct device *dev,
struct snd_soc_tplg_vendor_array *array,
struct skl_dfw_manifest *minfo)
{
int tkn_count = 0, ret;
struct snd_soc_tplg_vendor_string_elem *str_elem;
str_elem = (struct snd_soc_tplg_vendor_string_elem *)array->value;
while (tkn_count < array->num_elems) {
ret = skl_tplg_fill_str_mfest_tkn(dev, str_elem, minfo);
str_elem++;
if (ret < 0)
return ret;
tkn_count = tkn_count + ret;
}
return tkn_count;
}
static int skl_tplg_get_int_tkn(struct device *dev,
struct snd_soc_tplg_vendor_value_elem *tkn_elem,
struct skl_dfw_manifest *minfo)
{
int tkn_count = 0;
switch (tkn_elem->token) {
case SKL_TKN_U32_LIB_COUNT:
minfo->lib_count = tkn_elem->value;
tkn_count++;
break;
default:
dev_err(dev, "Not a manifest token %d\n", tkn_elem->token);
return -EINVAL;
}
return tkn_count;
}
static int skl_tplg_get_manifest_tkn(struct device *dev,
char *pvt_data, struct skl_dfw_manifest *minfo,
int block_size)
{
int tkn_count = 0, ret;
int off = 0, tuple_size = 0;
struct snd_soc_tplg_vendor_array *array;
struct snd_soc_tplg_vendor_value_elem *tkn_elem;
if (block_size <= 0)
return -EINVAL;
while (tuple_size < block_size) {
array = (struct snd_soc_tplg_vendor_array *)(pvt_data + off);
off += array->size;
switch (array->type) {
case SND_SOC_TPLG_TUPLE_TYPE_STRING:
ret = skl_tplg_get_str_tkn(dev, array, minfo);
if (ret < 0)
return ret;
tkn_count += ret;
tuple_size += tkn_count *
sizeof(struct snd_soc_tplg_vendor_string_elem);
continue;
case SND_SOC_TPLG_TUPLE_TYPE_UUID:
dev_warn(dev, "no uuid tokens for skl tplf manifest\n");
continue;
default:
tkn_elem = array->value;
tkn_count = 0;
break;
}
while (tkn_count <= array->num_elems - 1) {
ret = skl_tplg_get_int_tkn(dev,
tkn_elem, minfo);
if (ret < 0)
return ret;
tkn_count = tkn_count + ret;
tkn_elem++;
tuple_size += tkn_count *
sizeof(struct snd_soc_tplg_vendor_value_elem);
break;
}
tkn_count = 0;
}
return 0;
}
static int skl_tplg_get_manifest_data(struct snd_soc_tplg_manifest *manifest,
struct device *dev, struct skl_dfw_manifest *minfo)
{
struct snd_soc_tplg_vendor_array *array;
int num_blocks, block_size = 0, block_type, off = 0;
char *data;
int ret;
array = (struct snd_soc_tplg_vendor_array *)manifest->priv.data;
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
num_blocks = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)
(manifest->priv.data + off);
while (num_blocks > 0) {
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
block_type = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)
(manifest->priv.data + off);
ret = skl_tplg_get_desc_blocks(dev, array);
if (ret < 0)
return ret;
block_size = ret;
off += array->size;
array = (struct snd_soc_tplg_vendor_array *)
(manifest->priv.data + off);
data = (manifest->priv.data + off);
if (block_type == SKL_TYPE_TUPLE) {
ret = skl_tplg_get_manifest_tkn(dev, data, minfo,
block_size);
if (ret < 0)
return ret;
--num_blocks;
} else {
return -EINVAL;
}
}
return 0;
}
static int skl_manifest_load(struct snd_soc_component *cmpnt,
struct snd_soc_tplg_manifest *manifest)
{
struct skl_dfw_manifest *minfo;
struct hdac_ext_bus *ebus = snd_soc_component_get_drvdata(cmpnt);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl *skl = ebus_to_skl(ebus);
int ret = 0;
if (manifest->priv.size == 0)
return 0;
minfo = &skl->skl_sst->manifest;
skl_tplg_get_manifest_data(manifest, bus->dev, minfo);
if (minfo->lib_count > HDA_MAX_LIB) {
dev_err(bus->dev, "Exceeding max Library count. Got:%d\n",
minfo->lib_count);
ret = -EINVAL;
}
return ret;
}
static int skl_tplg_create_pipe_widget_list(struct snd_soc_platform *platform)
{
struct snd_soc_dapm_widget *w;
struct skl_module_cfg *mcfg = NULL;
struct skl_pipe_module *p_module = NULL;
struct skl_pipe *pipe;
list_for_each_entry(w, &platform->component.card->widgets, list) {
if (is_skl_dsp_widget_type(w) && w->priv != NULL) {
mcfg = w->priv;
pipe = mcfg->pipe;
p_module = devm_kzalloc(platform->dev,
sizeof(*p_module), GFP_KERNEL);
if (!p_module)
return -ENOMEM;
p_module->w = w;
list_add_tail(&p_module->node, &pipe->w_list);
}
}
return 0;
}
static void skl_tplg_set_pipe_type(struct skl *skl, struct skl_pipe *pipe)
{
struct skl_pipe_module *w_module;
struct snd_soc_dapm_widget *w;
struct skl_module_cfg *mconfig;
bool host_found = false, link_found = false;
list_for_each_entry(w_module, &pipe->w_list, node) {
w = w_module->w;
mconfig = w->priv;
if (mconfig->dev_type == SKL_DEVICE_HDAHOST)
host_found = true;
else if (mconfig->dev_type != SKL_DEVICE_NONE)
link_found = true;
}
if (host_found && link_found)
pipe->passthru = true;
else
pipe->passthru = false;
}
int skl_tplg_init(struct snd_soc_platform *platform, struct hdac_ext_bus *ebus)
{
int ret;
const struct firmware *fw;
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl *skl = ebus_to_skl(ebus);
struct skl_pipeline *ppl;
ret = request_firmware(&fw, skl->tplg_name, bus->dev);
if (ret < 0) {
dev_err(bus->dev, "tplg fw %s load failed with %d\n",
skl->tplg_name, ret);
ret = request_firmware(&fw, "dfw_sst.bin", bus->dev);
if (ret < 0) {
dev_err(bus->dev, "Fallback tplg fw %s load failed with %d\n",
"dfw_sst.bin", ret);
return ret;
}
}
ret = snd_soc_tplg_component_load(&platform->component,
&skl_tplg_ops, fw, 0);
if (ret < 0) {
dev_err(bus->dev, "tplg component load failed%d\n", ret);
release_firmware(fw);
return -EINVAL;
}
skl->resource.max_mcps = SKL_MAX_MCPS;
skl->resource.max_mem = SKL_FW_MAX_MEM;
skl->tplg = fw;
ret = skl_tplg_create_pipe_widget_list(platform);
if (ret < 0)
return ret;
list_for_each_entry(ppl, &skl->ppl_list, node)
skl_tplg_set_pipe_type(skl, ppl->pipe);
return 0;
}
