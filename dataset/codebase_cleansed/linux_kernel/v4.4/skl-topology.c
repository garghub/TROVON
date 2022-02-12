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
static bool skl_tplg_alloc_pipe_mem(struct skl *skl,
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
}
skl->resource.mem += mconfig->pipe->memory_pages;
return true;
}
static bool skl_tplg_alloc_pipe_mcps(struct skl *skl,
struct skl_module_cfg *mconfig)
{
struct skl_sst *ctx = skl->skl_sst;
if (skl->resource.mcps + mconfig->mcps > skl->resource.max_mcps) {
dev_err(ctx->dev,
"%s: module_id %d instance %d\n", __func__,
mconfig->id.module_id, mconfig->id.instance_id);
dev_err(ctx->dev,
"exceeds ppl memory available %d > mem %d\n",
skl->resource.max_mcps, skl->resource.mcps);
return false;
}
skl->resource.mcps += mconfig->mcps;
return true;
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
dev_dbg(ctx->dev, "channels = %d\n", mcfg->in_fmt.channels);
dev_dbg(ctx->dev, "s_freq = %d\n", mcfg->in_fmt.s_freq);
dev_dbg(ctx->dev, "ch_cfg = %d\n", mcfg->in_fmt.ch_cfg);
dev_dbg(ctx->dev, "valid bit depth = %d\n",
mcfg->in_fmt.valid_bit_depth);
dev_dbg(ctx->dev, "Output Format:\n");
dev_dbg(ctx->dev, "channels = %d\n", mcfg->out_fmt.channels);
dev_dbg(ctx->dev, "s_freq = %d\n", mcfg->out_fmt.s_freq);
dev_dbg(ctx->dev, "valid bit depth = %d\n",
mcfg->out_fmt.valid_bit_depth);
dev_dbg(ctx->dev, "ch_cfg = %d\n", mcfg->out_fmt.ch_cfg);
}
static void skl_tplg_update_params(struct skl_module_fmt *fmt,
struct skl_pipe_params *params, int fixup)
{
if (fixup & SKL_RATE_FIXUP_MASK)
fmt->s_freq = params->s_freq;
if (fixup & SKL_CH_FIXUP_MASK)
fmt->channels = params->ch;
if (fixup & SKL_FMT_FIXUP_MASK)
fmt->valid_bit_depth = params->s_fmt;
}
static void skl_tplg_update_params_fixup(struct skl_module_cfg *m_cfg,
struct skl_pipe_params *params, bool is_fe)
{
int in_fixup, out_fixup;
struct skl_module_fmt *in_fmt, *out_fmt;
in_fmt = &m_cfg->in_fmt;
out_fmt = &m_cfg->out_fmt;
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
if (mcfg->m_type == SKL_MODULE_TYPE_SRCINT)
multiplier = 5;
mcfg->ibs = (mcfg->in_fmt.s_freq / 1000) *
(mcfg->in_fmt.channels) *
(mcfg->in_fmt.bit_depth >> 3) *
multiplier;
mcfg->obs = (mcfg->out_fmt.s_freq / 1000) *
(mcfg->out_fmt.channels) *
(mcfg->out_fmt.bit_depth >> 3) *
multiplier;
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
static int skl_tplg_alloc_pipe_widget(struct device *dev,
struct snd_soc_dapm_widget *w, struct skl_pipe *pipe)
{
struct skl_module_cfg *src_module = NULL;
struct snd_soc_dapm_path *p = NULL;
struct skl_pipe_module *p_module = NULL;
p_module = devm_kzalloc(dev, sizeof(*p_module), GFP_KERNEL);
if (!p_module)
return -ENOMEM;
p_module->w = w;
list_add_tail(&p_module->node, &pipe->w_list);
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if ((p->sink->priv == NULL)
&& (!is_skl_dsp_widget_type(w)))
continue;
if ((p->sink->priv != NULL) && p->connect
&& is_skl_dsp_widget_type(p->sink)) {
src_module = p->sink->priv;
if (pipe->ppl_id == src_module->pipe->ppl_id)
skl_tplg_alloc_pipe_widget(dev,
p->sink, pipe);
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
if (!skl_tplg_alloc_pipe_mcps(skl, mconfig))
return -ENOMEM;
skl_tplg_update_module_params(w, ctx);
ret = skl_init_module(ctx, mconfig, NULL);
if (ret < 0)
return ret;
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
if (!skl_tplg_alloc_pipe_mcps(skl, mconfig))
return -EBUSY;
if (!skl_tplg_alloc_pipe_mem(skl, mconfig))
return -ENOMEM;
ret = skl_create_pipeline(ctx, mconfig->pipe);
if (ret < 0)
return ret;
if (list_empty(&s_pipe->w_list)) {
ret = skl_tplg_alloc_pipe_widget(ctx->dev, w, s_pipe);
if (ret < 0)
return ret;
}
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
static int skl_tplg_pga_dapm_pre_pmu_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct snd_soc_dapm_path *p;
struct skl_dapm_path_list *path_list;
struct snd_soc_dapm_widget *source, *sink;
struct skl_module_cfg *src_mconfig, *sink_mconfig;
struct skl_sst *ctx = skl->skl_sst;
int ret = 0;
source = w;
src_mconfig = source->priv;
snd_soc_dapm_widget_for_each_source_path(w, p) {
if (!p->connect)
continue;
dev_dbg(ctx->dev, "%s: src widget=%s\n", __func__, w->name);
dev_dbg(ctx->dev, "%s: sink widget=%s\n", __func__, p->sink->name);
if ((p->sink->priv != NULL) &&
is_skl_dsp_widget_type(p->sink)) {
sink = p->sink;
src_mconfig = source->priv;
sink_mconfig = sink->priv;
ret = skl_bind_modules(ctx, src_mconfig, sink_mconfig);
if (ret)
return ret;
if (sink_mconfig->pipe->state != SKL_PIPE_STARTED) {
ret = skl_run_pipe(ctx, sink_mconfig->pipe);
if (ret)
return ret;
}
path_list = kzalloc(
sizeof(struct skl_dapm_path_list),
GFP_KERNEL);
if (path_list == NULL)
return -ENOMEM;
path_list->dapm_path = p;
list_add_tail(&path_list->node, &skl->dapm_path_list);
break;
}
}
ret = skl_run_pipe(ctx, src_mconfig->pipe);
if (ret)
return ret;
return 0;
}
static int skl_tplg_mixer_dapm_post_pmu_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
int ret = 0;
struct snd_soc_dapm_path *p;
struct snd_soc_dapm_widget *source, *sink;
struct skl_module_cfg *src_mconfig, *sink_mconfig;
struct skl_sst *ctx = skl->skl_sst;
int src_pipe_started = 0;
sink = w;
sink_mconfig = sink->priv;
snd_soc_dapm_widget_for_each_sink_path(w, p) {
if (!p->connect)
continue;
dev_dbg(ctx->dev, "sink widget=%s\n", w->name);
dev_dbg(ctx->dev, "src widget=%s\n", p->source->name);
if ((p->source->priv != NULL) &&
is_skl_dsp_widget_type(p->source)) {
source = p->source;
src_mconfig = source->priv;
sink_mconfig = sink->priv;
src_pipe_started = 1;
if (src_mconfig->pipe->state != SKL_PIPE_STARTED)
src_pipe_started = 0;
}
}
if (src_pipe_started) {
ret = skl_bind_modules(ctx, src_mconfig, sink_mconfig);
if (ret)
return ret;
ret = skl_run_pipe(ctx, sink_mconfig->pipe);
}
return ret;
}
static int skl_tplg_mixer_dapm_pre_pmd_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct snd_soc_dapm_widget *source, *sink;
struct skl_module_cfg *src_mconfig, *sink_mconfig;
int ret = 0, path_found = 0;
struct skl_dapm_path_list *path_list, *tmp_list;
struct skl_sst *ctx = skl->skl_sst;
sink = w;
sink_mconfig = sink->priv;
ret = skl_stop_pipe(ctx, sink_mconfig->pipe);
if (ret)
return ret;
list_for_each_entry_safe(path_list, tmp_list,
&skl->dapm_path_list, node) {
if (path_list->dapm_path->sink == sink) {
dev_dbg(ctx->dev, "Path found = %s\n",
path_list->dapm_path->name);
source = path_list->dapm_path->source;
src_mconfig = source->priv;
path_found = 1;
list_del(&path_list->node);
kfree(path_list);
break;
}
}
if (path_found) {
ret = skl_stop_pipe(ctx, src_mconfig->pipe);
if (ret < 0)
return ret;
ret = skl_unbind_modules(ctx, src_mconfig, sink_mconfig);
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
skl_tplg_free_pipe_mcps(skl, mconfig);
list_for_each_entry(w_module, &s_pipe->w_list, node) {
dst_module = w_module->w->priv;
if (src_module == NULL) {
src_module = dst_module;
continue;
}
ret = skl_unbind_modules(ctx, src_module, dst_module);
if (ret < 0)
return ret;
src_module = dst_module;
}
ret = skl_delete_pipe(ctx, mconfig->pipe);
skl_tplg_free_pipe_mem(skl, mconfig);
return ret;
}
static int skl_tplg_pga_dapm_post_pmd_event(struct snd_soc_dapm_widget *w,
struct skl *skl)
{
struct snd_soc_dapm_widget *source, *sink;
struct skl_module_cfg *src_mconfig, *sink_mconfig;
int ret = 0, path_found = 0;
struct skl_dapm_path_list *path_list, *tmp_path_list;
struct skl_sst *ctx = skl->skl_sst;
source = w;
src_mconfig = source->priv;
skl_tplg_free_pipe_mcps(skl, src_mconfig);
ret = skl_stop_pipe(ctx, src_mconfig->pipe);
if (ret)
return ret;
list_for_each_entry_safe(path_list, tmp_path_list, &skl->dapm_path_list, node) {
if (path_list->dapm_path->source == source) {
dev_dbg(ctx->dev, "Path found = %s\n",
path_list->dapm_path->name);
sink = path_list->dapm_path->sink;
sink_mconfig = sink->priv;
path_found = 1;
list_del(&path_list->node);
kfree(path_list);
break;
}
}
if (path_found) {
ret = skl_stop_pipe(ctx, src_mconfig->pipe);
if (ret < 0)
return ret;
ret = skl_unbind_modules(ctx, src_mconfig, sink_mconfig);
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
int skl_tplg_update_pipe_params(struct device *dev,
struct skl_module_cfg *mconfig,
struct skl_pipe_params *params)
{
struct skl_pipe *pipe = mconfig->pipe;
struct skl_module_fmt *format = NULL;
memcpy(pipe->p_params, params, sizeof(*params));
if (params->stream == SNDRV_PCM_STREAM_PLAYBACK)
format = &mconfig->in_fmt;
else
format = &mconfig->out_fmt;
format->s_freq = params->s_freq;
format->channels = params->ch;
format->valid_bit_depth = skl_get_bit_depth(params->s_fmt);
switch (format->valid_bit_depth) {
case SKL_DEPTH_16BIT:
format->bit_depth = format->valid_bit_depth;
break;
case SKL_DEPTH_24BIT:
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
is_skl_dsp_widget_type(p->sink))
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
is_skl_dsp_widget_type(p->source))
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
struct skl_pipe *pipe = mconfig->pipe;
struct nhlt_specific_cfg *cfg;
struct skl *skl = get_skl_ctx(dai->dev);
int link_type = skl_tplg_be_link_type(mconfig->dev_type);
memcpy(pipe->p_params, params, sizeof(*params));
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
if (!p->source->power) {
ret = skl_tplg_be_fill_pipe_params(
dai, p->source->priv,
params);
if (ret < 0)
return ret;
} else {
return -EBUSY;
}
} else {
ret = skl_tplg_be_set_src_pipe_params(
dai, p->source, params);
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
if (!p->sink->power) {
ret = skl_tplg_be_fill_pipe_params(
dai, p->sink->priv, params);
if (ret < 0)
return ret;
} else {
return -EBUSY;
}
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
mconfig->id.module_id = dfw_config->module_id;
mconfig->id.instance_id = dfw_config->instance_id;
mconfig->mcps = dfw_config->max_mcps;
mconfig->ibs = dfw_config->ibs;
mconfig->obs = dfw_config->obs;
mconfig->core_id = dfw_config->core_id;
mconfig->max_in_queue = dfw_config->max_in_queue;
mconfig->max_out_queue = dfw_config->max_out_queue;
mconfig->is_loadable = dfw_config->is_loadable;
mconfig->in_fmt.channels = dfw_config->in_fmt.channels;
mconfig->in_fmt.s_freq = dfw_config->in_fmt.freq;
mconfig->in_fmt.bit_depth = dfw_config->in_fmt.bit_depth;
mconfig->in_fmt.valid_bit_depth =
dfw_config->in_fmt.valid_bit_depth;
mconfig->in_fmt.ch_cfg = dfw_config->in_fmt.ch_cfg;
mconfig->out_fmt.channels = dfw_config->out_fmt.channels;
mconfig->out_fmt.s_freq = dfw_config->out_fmt.freq;
mconfig->out_fmt.bit_depth = dfw_config->out_fmt.bit_depth;
mconfig->out_fmt.valid_bit_depth =
dfw_config->out_fmt.valid_bit_depth;
mconfig->out_fmt.ch_cfg = dfw_config->out_fmt.ch_cfg;
mconfig->params_fixup = dfw_config->params_fixup;
mconfig->converter = dfw_config->converter;
mconfig->m_type = dfw_config->module_type;
mconfig->vbus_id = dfw_config->vbus_id;
pipe = skl_tplg_add_pipe(bus->dev, skl, &dfw_config->pipe);
if (pipe)
mconfig->pipe = pipe;
mconfig->dev_type = dfw_config->dev_type;
mconfig->hw_conn_type = dfw_config->hw_conn_type;
mconfig->time_slot = dfw_config->time_slot;
mconfig->formats_config.caps_size = dfw_config->caps.caps_size;
mconfig->m_in_pin = devm_kzalloc(bus->dev,
(mconfig->max_in_queue) *
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
int skl_tplg_init(struct snd_soc_platform *platform, struct hdac_ext_bus *ebus)
{
int ret;
const struct firmware *fw;
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl *skl = ebus_to_skl(ebus);
ret = request_firmware(&fw, "dfw_sst.bin", bus->dev);
if (ret < 0) {
dev_err(bus->dev, "tplg fw %s load failed with %d\n",
"dfw_sst.bin", ret);
return ret;
}
ret = snd_soc_tplg_component_load(&platform->component,
&skl_tplg_ops, fw, 0);
if (ret < 0) {
dev_err(bus->dev, "tplg component load failed%d\n", ret);
return -EINVAL;
}
skl->resource.max_mcps = SKL_MAX_MCPS;
skl->resource.max_mem = SKL_FW_MAX_MEM;
skl->tplg = fw;
return 0;
}
