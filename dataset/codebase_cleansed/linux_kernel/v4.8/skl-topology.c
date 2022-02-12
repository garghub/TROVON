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
skl_tplg_set_module_init_data(w);
ret = skl_init_module(ctx, mconfig);
if (ret < 0)
return ret;
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
struct skl_pipe_module *w_module = NULL;
struct skl_module_cfg *mconfig = NULL;
list_for_each_entry(w_module, &pipe->w_list, node) {
mconfig = w_module->w->priv;
if (mconfig->is_loadable && ctx->dsp->fw_ops.unload_mod &&
mconfig->m_state > SKL_MODULE_UNINIT)
return ctx->dsp->fw_ops.unload_mod(ctx->dsp,
mconfig->id.module_id);
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
static void skl_fill_module_pin_info(struct skl_dfw_module_pin *dfw_pin,
struct skl_module_pin *m_pin,
bool is_dynamic, int max_pin)
{
int i;
for (i = 0; i < max_pin; i++) {
m_pin[i].id.module_id = dfw_pin[i].module_id;
m_pin[i].id.instance_id = dfw_pin[i].instance_id;
m_pin[i].in_use = false;
m_pin[i].is_dynamic = is_dynamic;
m_pin[i].pin_state = SKL_PIN_UNBIND;
}
}
static struct skl_pipe *skl_tplg_add_pipe(struct device *dev,
struct skl *skl, struct skl_dfw_pipe *dfw_pipe)
{
struct skl_pipeline *ppl;
struct skl_pipe *pipe;
struct skl_pipe_params *params;
list_for_each_entry(ppl, &skl->ppl_list, node) {
if (ppl->pipe->ppl_id == dfw_pipe->pipe_id)
return ppl->pipe;
}
ppl = devm_kzalloc(dev, sizeof(*ppl), GFP_KERNEL);
if (!ppl)
return NULL;
pipe = devm_kzalloc(dev, sizeof(*pipe), GFP_KERNEL);
if (!pipe)
return NULL;
params = devm_kzalloc(dev, sizeof(*params), GFP_KERNEL);
if (!params)
return NULL;
pipe->ppl_id = dfw_pipe->pipe_id;
pipe->memory_pages = dfw_pipe->memory_pages;
pipe->pipe_priority = dfw_pipe->pipe_priority;
pipe->conn_type = dfw_pipe->conn_type;
pipe->state = SKL_PIPE_INVALID;
pipe->p_params = params;
INIT_LIST_HEAD(&pipe->w_list);
ppl->pipe = pipe;
list_add(&ppl->node, &skl->ppl_list);
return ppl->pipe;
}
static void skl_tplg_fill_fmt(struct skl_module_fmt *dst_fmt,
struct skl_dfw_module_fmt *src_fmt,
int pins)
{
int i;
for (i = 0; i < pins; i++) {
dst_fmt[i].channels = src_fmt[i].channels;
dst_fmt[i].s_freq = src_fmt[i].freq;
dst_fmt[i].bit_depth = src_fmt[i].bit_depth;
dst_fmt[i].valid_bit_depth = src_fmt[i].valid_bit_depth;
dst_fmt[i].ch_cfg = src_fmt[i].ch_cfg;
dst_fmt[i].ch_map = src_fmt[i].ch_map;
dst_fmt[i].interleaving_style = src_fmt[i].interleaving_style;
dst_fmt[i].sample_type = src_fmt[i].sample_type;
}
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
struct skl_pipe *pipe;
struct skl_dfw_module *dfw_config =
(struct skl_dfw_module *)tplg_w->priv.data;
if (!tplg_w->priv.size)
goto bind_event;
mconfig = devm_kzalloc(bus->dev, sizeof(*mconfig), GFP_KERNEL);
if (!mconfig)
return -ENOMEM;
w->priv = mconfig;
memcpy(&mconfig->guid, &dfw_config->uuid, 16);
ret = snd_skl_get_module_info(skl->skl_sst, mconfig->guid, dfw_config);
if (ret < 0)
return ret;
mconfig->id.module_id = dfw_config->module_id;
mconfig->id.instance_id = dfw_config->instance_id;
mconfig->mcps = dfw_config->max_mcps;
mconfig->ibs = dfw_config->ibs;
mconfig->obs = dfw_config->obs;
mconfig->core_id = dfw_config->core_id;
mconfig->max_in_queue = dfw_config->max_in_queue;
mconfig->max_out_queue = dfw_config->max_out_queue;
mconfig->is_loadable = dfw_config->is_loadable;
skl_tplg_fill_fmt(mconfig->in_fmt, dfw_config->in_fmt,
MODULE_MAX_IN_PINS);
skl_tplg_fill_fmt(mconfig->out_fmt, dfw_config->out_fmt,
MODULE_MAX_OUT_PINS);
mconfig->params_fixup = dfw_config->params_fixup;
mconfig->converter = dfw_config->converter;
mconfig->m_type = dfw_config->module_type;
mconfig->vbus_id = dfw_config->vbus_id;
mconfig->mem_pages = dfw_config->mem_pages;
pipe = skl_tplg_add_pipe(bus->dev, skl, &dfw_config->pipe);
if (pipe)
mconfig->pipe = pipe;
mconfig->dev_type = dfw_config->dev_type;
mconfig->hw_conn_type = dfw_config->hw_conn_type;
mconfig->time_slot = dfw_config->time_slot;
mconfig->formats_config.caps_size = dfw_config->caps.caps_size;
mconfig->m_in_pin = devm_kzalloc(bus->dev, (mconfig->max_in_queue) *
sizeof(*mconfig->m_in_pin),
GFP_KERNEL);
if (!mconfig->m_in_pin)
return -ENOMEM;
mconfig->m_out_pin = devm_kzalloc(bus->dev, (mconfig->max_out_queue) *
sizeof(*mconfig->m_out_pin),
GFP_KERNEL);
if (!mconfig->m_out_pin)
return -ENOMEM;
skl_fill_module_pin_info(dfw_config->in_pin, mconfig->m_in_pin,
dfw_config->is_dynamic_in_pin,
mconfig->max_in_queue);
skl_fill_module_pin_info(dfw_config->out_pin, mconfig->m_out_pin,
dfw_config->is_dynamic_out_pin,
mconfig->max_out_queue);
if (mconfig->formats_config.caps_size == 0)
goto bind_event;
mconfig->formats_config.caps = (u32 *)devm_kzalloc(bus->dev,
mconfig->formats_config.caps_size, GFP_KERNEL);
if (mconfig->formats_config.caps == NULL)
return -ENOMEM;
memcpy(mconfig->formats_config.caps, dfw_config->caps.caps,
dfw_config->caps.caps_size);
mconfig->formats_config.param_id = dfw_config->caps.param_id;
mconfig->formats_config.set_params = dfw_config->caps.set_params;
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
