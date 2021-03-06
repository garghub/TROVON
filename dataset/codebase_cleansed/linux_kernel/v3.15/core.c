char *rsnd_mod_name(struct rsnd_mod *mod)
{
if (!mod || !mod->ops)
return "unknown";
return mod->ops->name;
}
void rsnd_mod_init(struct rsnd_priv *priv,
struct rsnd_mod *mod,
struct rsnd_mod_ops *ops,
enum rsnd_mod_type type,
int id)
{
mod->priv = priv;
mod->id = id;
mod->ops = ops;
mod->type = type;
}
static void rsnd_dma_continue(struct rsnd_dma *dma)
{
dma->submit_loop = 1;
schedule_work(&dma->work);
}
void rsnd_dma_start(struct rsnd_dma *dma)
{
dma->offset = 0;
dma->submit_loop = 2;
__rsnd_dma_start(dma);
}
void rsnd_dma_stop(struct rsnd_dma *dma)
{
dma->submit_loop = 0;
cancel_work_sync(&dma->work);
dmaengine_terminate_all(dma->chan);
}
static void rsnd_dma_complete(void *data)
{
struct rsnd_dma *dma = (struct rsnd_dma *)data;
struct rsnd_mod *mod = rsnd_dma_to_mod(dma);
struct rsnd_priv *priv = rsnd_mod_to_priv(rsnd_dma_to_mod(dma));
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
unsigned long flags;
rsnd_lock(priv, flags);
if (dma->submit_loop)
rsnd_dma_continue(dma);
rsnd_unlock(priv, flags);
rsnd_dai_pointer_update(io, io->byte_per_period);
}
static void __rsnd_dma_start(struct rsnd_dma *dma)
{
struct rsnd_mod *mod = rsnd_dma_to_mod(dma);
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct rsnd_dai_stream *io = rsnd_mod_to_io(mod);
struct snd_pcm_runtime *runtime = rsnd_io_to_runtime(io);
struct device *dev = rsnd_priv_to_dev(priv);
struct dma_async_tx_descriptor *desc;
dma_addr_t buf;
size_t len = io->byte_per_period;
int i;
for (i = 0; i < dma->submit_loop; i++) {
buf = runtime->dma_addr +
rsnd_dai_pointer_offset(io, dma->offset + len);
dma->offset = len;
desc = dmaengine_prep_slave_single(
dma->chan, buf, len, dma->dir,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
if (!desc) {
dev_err(dev, "dmaengine_prep_slave_sg() fail\n");
return;
}
desc->callback = rsnd_dma_complete;
desc->callback_param = dma;
if (dmaengine_submit(desc) < 0) {
dev_err(dev, "dmaengine_submit() fail\n");
return;
}
dma_async_issue_pending(dma->chan);
}
}
static void rsnd_dma_do_work(struct work_struct *work)
{
struct rsnd_dma *dma = container_of(work, struct rsnd_dma, work);
__rsnd_dma_start(dma);
}
int rsnd_dma_available(struct rsnd_dma *dma)
{
return !!dma->chan;
}
int rsnd_dma_init(struct rsnd_priv *priv, struct rsnd_dma *dma,
int is_play, int id)
{
struct device *dev = rsnd_priv_to_dev(priv);
struct dma_slave_config cfg;
dma_cap_mask_t mask;
int ret;
if (dma->chan) {
dev_err(dev, "it already has dma channel\n");
return -EIO;
}
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma->chan = dma_request_slave_channel_compat(mask, shdma_chan_filter,
(void *)id, dev,
is_play ? "tx" : "rx");
if (!dma->chan) {
dev_err(dev, "can't get dma channel\n");
return -EIO;
}
cfg.slave_id = id;
cfg.dst_addr = 0;
cfg.src_addr = 0;
cfg.direction = is_play ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM;
ret = dmaengine_slave_config(dma->chan, &cfg);
if (ret < 0)
goto rsnd_dma_init_err;
dma->dir = is_play ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
INIT_WORK(&dma->work, rsnd_dma_do_work);
return 0;
rsnd_dma_init_err:
rsnd_dma_quit(priv, dma);
return ret;
}
void rsnd_dma_quit(struct rsnd_priv *priv,
struct rsnd_dma *dma)
{
if (dma->chan)
dma_release_channel(dma->chan);
dma->chan = NULL;
}
static int rsnd_dai_connect(struct rsnd_mod *mod,
struct rsnd_dai_stream *io)
{
if (!mod)
return -EIO;
if (io->mod[mod->type]) {
struct rsnd_priv *priv = rsnd_mod_to_priv(mod);
struct device *dev = rsnd_priv_to_dev(priv);
dev_err(dev, "%s%d is not empty\n",
rsnd_mod_name(mod),
rsnd_mod_id(mod));
return -EIO;
}
io->mod[mod->type] = mod;
mod->io = io;
return 0;
}
int rsnd_dai_id(struct rsnd_priv *priv, struct rsnd_dai *rdai)
{
int id = rdai - priv->rdai;
if ((id < 0) || (id >= rsnd_rdai_nr(priv)))
return -EINVAL;
return id;
}
struct rsnd_dai *rsnd_dai_get(struct rsnd_priv *priv, int id)
{
if ((id < 0) || (id >= rsnd_rdai_nr(priv)))
return NULL;
return priv->rdai + id;
}
static struct rsnd_dai *rsnd_dai_to_rdai(struct snd_soc_dai *dai)
{
struct rsnd_priv *priv = snd_soc_dai_get_drvdata(dai);
return rsnd_dai_get(priv, dai->id);
}
int rsnd_dai_is_play(struct rsnd_dai *rdai, struct rsnd_dai_stream *io)
{
return &rdai->playback == io;
}
int rsnd_dai_pointer_offset(struct rsnd_dai_stream *io, int additional)
{
struct snd_pcm_substream *substream = io->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
int pos = io->byte_pos + additional;
pos %= (runtime->periods * io->byte_per_period);
return pos;
}
void rsnd_dai_pointer_update(struct rsnd_dai_stream *io, int byte)
{
io->byte_pos += byte;
if (io->byte_pos >= io->next_period_byte) {
struct snd_pcm_substream *substream = io->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
io->period_pos++;
io->next_period_byte += io->byte_per_period;
if (io->period_pos >= runtime->periods) {
io->byte_pos = 0;
io->period_pos = 0;
io->next_period_byte = io->byte_per_period;
}
snd_pcm_period_elapsed(substream);
}
}
static int rsnd_dai_stream_init(struct rsnd_dai_stream *io,
struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
io->substream = substream;
io->byte_pos = 0;
io->period_pos = 0;
io->byte_per_period = runtime->period_size *
runtime->channels *
samples_to_bytes(runtime, 1);
io->next_period_byte = io->byte_per_period;
return 0;
}
static
struct snd_soc_dai *rsnd_substream_to_dai(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
return rtd->cpu_dai;
}
static
struct rsnd_dai_stream *rsnd_rdai_to_io(struct rsnd_dai *rdai,
struct snd_pcm_substream *substream)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return &rdai->playback;
else
return &rdai->capture;
}
static int rsnd_soc_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct rsnd_priv *priv = snd_soc_dai_get_drvdata(dai);
struct rsnd_dai *rdai = rsnd_dai_to_rdai(dai);
struct rsnd_dai_stream *io = rsnd_rdai_to_io(rdai, substream);
struct rsnd_mod *mod = rsnd_ssi_mod_get_frm_dai(priv,
rsnd_dai_id(priv, rdai),
rsnd_dai_is_play(rdai, io));
int ssi_id = rsnd_mod_id(mod);
int ret;
unsigned long flags;
rsnd_lock(priv, flags);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
ret = rsnd_dai_stream_init(io, substream);
if (ret < 0)
goto dai_trigger_end;
ret = rsnd_platform_call(priv, dai, start, ssi_id);
if (ret < 0)
goto dai_trigger_end;
ret = rsnd_dai_call(rdai, io, init);
if (ret < 0)
goto dai_trigger_end;
ret = rsnd_dai_call(rdai, io, start);
if (ret < 0)
goto dai_trigger_end;
break;
case SNDRV_PCM_TRIGGER_STOP:
ret = rsnd_dai_call(rdai, io, stop);
if (ret < 0)
goto dai_trigger_end;
ret = rsnd_dai_call(rdai, io, quit);
if (ret < 0)
goto dai_trigger_end;
ret = rsnd_platform_call(priv, dai, stop, ssi_id);
if (ret < 0)
goto dai_trigger_end;
break;
default:
ret = -EINVAL;
}
dai_trigger_end:
rsnd_unlock(priv, flags);
return ret;
}
static int rsnd_soc_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct rsnd_dai *rdai = rsnd_dai_to_rdai(dai);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
rdai->clk_master = 0;
break;
case SND_SOC_DAIFMT_CBS_CFS:
rdai->clk_master = 1;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_IF:
rdai->bit_clk_inv = 0;
rdai->frm_clk_inv = 1;
break;
case SND_SOC_DAIFMT_IB_NF:
rdai->bit_clk_inv = 1;
rdai->frm_clk_inv = 0;
break;
case SND_SOC_DAIFMT_IB_IF:
rdai->bit_clk_inv = 1;
rdai->frm_clk_inv = 1;
break;
case SND_SOC_DAIFMT_NB_NF:
default:
rdai->bit_clk_inv = 0;
rdai->frm_clk_inv = 0;
break;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
rdai->sys_delay = 0;
rdai->data_alignment = 0;
break;
case SND_SOC_DAIFMT_LEFT_J:
rdai->sys_delay = 1;
rdai->data_alignment = 0;
break;
case SND_SOC_DAIFMT_RIGHT_J:
rdai->sys_delay = 1;
rdai->data_alignment = 1;
break;
}
return 0;
}
static int rsnd_path_init(struct rsnd_priv *priv,
struct rsnd_dai *rdai,
struct rsnd_dai_stream *io)
{
struct rsnd_mod *mod;
struct rsnd_dai_platform_info *dai_info = rdai->info;
int ret;
int ssi_id = -1;
int src_id = -1;
if (dai_info) {
if (rsnd_is_enable_path(io, ssi))
ssi_id = rsnd_info_id(priv, io, ssi);
if (rsnd_is_enable_path(io, src))
src_id = rsnd_info_id(priv, io, src);
} else {
mod = rsnd_ssi_mod_get_frm_dai(priv,
rsnd_dai_id(priv, rdai),
rsnd_dai_is_play(rdai, io));
if (!mod)
return 0;
ssi_id = src_id = rsnd_mod_id(mod);
}
ret = 0;
if (src_id >= 0) {
mod = rsnd_src_mod_get(priv, src_id);
ret = rsnd_dai_connect(mod, io);
if (ret < 0)
return ret;
}
if (ssi_id >= 0) {
mod = rsnd_ssi_mod_get(priv, ssi_id);
ret = rsnd_dai_connect(mod, io);
if (ret < 0)
return ret;
}
return ret;
}
static void rsnd_of_parse_dai(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct device_node *dai_node, *dai_np;
struct device_node *ssi_node, *ssi_np;
struct device_node *src_node, *src_np;
struct device_node *playback, *capture;
struct rsnd_dai_platform_info *dai_info;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct device *dev = &pdev->dev;
int nr, i;
int dai_i, ssi_i, src_i;
if (!of_data)
return;
dai_node = of_get_child_by_name(dev->of_node, "rcar_sound,dai");
if (!dai_node)
return;
nr = of_get_child_count(dai_node);
if (!nr)
return;
dai_info = devm_kzalloc(dev,
sizeof(struct rsnd_dai_platform_info) * nr,
GFP_KERNEL);
if (!dai_info) {
dev_err(dev, "dai info allocation error\n");
return;
}
info->dai_info_nr = nr;
info->dai_info = dai_info;
ssi_node = of_get_child_by_name(dev->of_node, "rcar_sound,ssi");
src_node = of_get_child_by_name(dev->of_node, "rcar_sound,src");
#define mod_parse(name) \
if (name##_node) { \
struct rsnd_##name##_platform_info *name##_info; \
\
name##_i = 0; \
for_each_child_of_node(name##_node, name##_np) { \
name##_info = info->name##_info + name##_i; \
\
if (name##_np == playback) \
dai_info->playback.name = name##_info; \
if (name##_np == capture) \
dai_info->capture.name = name##_info; \
\
name##_i++; \
} \
}
dai_i = 0;
for_each_child_of_node(dai_node, dai_np) {
dai_info = info->dai_info + dai_i;
for (i = 0;; i++) {
playback = of_parse_phandle(dai_np, "playback", i);
capture = of_parse_phandle(dai_np, "capture", i);
if (!playback && !capture)
break;
mod_parse(ssi);
mod_parse(src);
if (playback)
of_node_put(playback);
if (capture)
of_node_put(capture);
}
dai_i++;
}
}
static int rsnd_dai_probe(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv)
{
struct snd_soc_dai_driver *drv;
struct rcar_snd_info *info = rsnd_priv_to_info(priv);
struct rsnd_dai *rdai;
struct rsnd_mod *pmod, *cmod;
struct device *dev = rsnd_priv_to_dev(priv);
int dai_nr;
int i;
rsnd_of_parse_dai(pdev, of_data, priv);
dai_nr = info->dai_info_nr;
if (!dai_nr) {
for (dai_nr = 0; dai_nr < 32; dai_nr++) {
pmod = rsnd_ssi_mod_get_frm_dai(priv, dai_nr, 1);
cmod = rsnd_ssi_mod_get_frm_dai(priv, dai_nr, 0);
if (!pmod && !cmod)
break;
}
}
if (!dai_nr) {
dev_err(dev, "no dai\n");
return -EIO;
}
drv = devm_kzalloc(dev, sizeof(*drv) * dai_nr, GFP_KERNEL);
rdai = devm_kzalloc(dev, sizeof(*rdai) * dai_nr, GFP_KERNEL);
if (!drv || !rdai) {
dev_err(dev, "dai allocate failed\n");
return -ENOMEM;
}
priv->rdai_nr = dai_nr;
priv->daidrv = drv;
priv->rdai = rdai;
for (i = 0; i < dai_nr; i++) {
if (info->dai_info)
rdai[i].info = &info->dai_info[i];
pmod = rsnd_ssi_mod_get_frm_dai(priv, i, 1);
cmod = rsnd_ssi_mod_get_frm_dai(priv, i, 0);
snprintf(rdai[i].name, RSND_DAI_NAME_SIZE, "rsnd-dai.%d", i);
drv[i].name = rdai[i].name;
drv[i].ops = &rsnd_soc_dai_ops;
if (pmod) {
drv[i].playback.rates = RSND_RATES;
drv[i].playback.formats = RSND_FMTS;
drv[i].playback.channels_min = 2;
drv[i].playback.channels_max = 2;
if (info->dai_info)
rdai[i].playback.info = &info->dai_info[i].playback;
rsnd_path_init(priv, &rdai[i], &rdai[i].playback);
}
if (cmod) {
drv[i].capture.rates = RSND_RATES;
drv[i].capture.formats = RSND_FMTS;
drv[i].capture.channels_min = 2;
drv[i].capture.channels_max = 2;
if (info->dai_info)
rdai[i].capture.info = &info->dai_info[i].capture;
rsnd_path_init(priv, &rdai[i], &rdai[i].capture);
}
dev_dbg(dev, "%s (%s/%s)\n", rdai[i].name,
pmod ? "play" : " -- ",
cmod ? "capture" : " -- ");
}
return 0;
}
static int rsnd_pcm_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
int ret = 0;
snd_soc_set_runtime_hwparams(substream, &rsnd_pcm_hardware);
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
return ret;
}
static int rsnd_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params)
{
return snd_pcm_lib_malloc_pages(substream,
params_buffer_bytes(hw_params));
}
static snd_pcm_uframes_t rsnd_pointer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_dai *dai = rsnd_substream_to_dai(substream);
struct rsnd_dai *rdai = rsnd_dai_to_rdai(dai);
struct rsnd_dai_stream *io = rsnd_rdai_to_io(rdai, substream);
return bytes_to_frames(runtime, io->byte_pos);
}
static int rsnd_pcm_new(struct snd_soc_pcm_runtime *rtd)
{
return snd_pcm_lib_preallocate_pages_for_all(
rtd->pcm,
SNDRV_DMA_TYPE_DEV,
rtd->card->snd_card->dev,
PREALLOC_BUFFER, PREALLOC_BUFFER_MAX);
}
static void rsnd_pcm_free(struct snd_pcm *pcm)
{
snd_pcm_lib_preallocate_free_for_all(pcm);
}
static int rsnd_probe(struct platform_device *pdev)
{
struct rcar_snd_info *info;
struct rsnd_priv *priv;
struct device *dev = &pdev->dev;
struct rsnd_dai *rdai;
const struct of_device_id *of_id = of_match_device(rsnd_of_match, dev);
const struct rsnd_of_data *of_data;
int (*probe_func[])(struct platform_device *pdev,
const struct rsnd_of_data *of_data,
struct rsnd_priv *priv) = {
rsnd_gen_probe,
rsnd_ssi_probe,
rsnd_src_probe,
rsnd_adg_probe,
rsnd_dai_probe,
}
int rsnd_remove(struct platform_device *pdev)
{
struct rsnd_priv *priv = dev_get_drvdata(&pdev->dev);
struct rsnd_dai *rdai;
int ret, i;
pm_runtime_disable(&pdev->dev);
for_each_rsnd_dai(rdai, priv, i) {
ret = rsnd_dai_call(rdai, &rdai->playback, remove);
if (ret)
return ret;
ret = rsnd_dai_call(rdai, &rdai->capture, remove);
if (ret)
return ret;
}
return 0;
}
