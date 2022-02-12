static int skl_alloc_dma_buf(struct device *dev,
struct snd_dma_buffer *dmab, size_t size)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_bus *bus = ebus_to_hbus(ebus);
if (!bus)
return -ENODEV;
return bus->io_ops->dma_alloc_pages(bus, SNDRV_DMA_TYPE_DEV, size, dmab);
}
static int skl_free_dma_buf(struct device *dev, struct snd_dma_buffer *dmab)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_bus *bus = ebus_to_hbus(ebus);
if (!bus)
return -ENODEV;
bus->io_ops->dma_free_pages(bus, dmab);
return 0;
}
static void skl_dsp_enable_notification(struct skl_sst *ctx, bool enable)
{
struct notification_mask mask;
struct skl_ipc_large_config_msg msg = {0};
mask.notify = NOTIFICATION_MASK;
mask.enable = enable;
msg.large_param_id = NOTIFICATION_PARAM_ID;
msg.param_data_size = sizeof(mask);
skl_ipc_set_large_config(&ctx->ipc, &msg, (u32 *)&mask);
}
static int skl_dsp_setup_spib(struct device *dev, unsigned int size,
int stream_tag, int enable)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct hdac_stream *stream = snd_hdac_get_stream(bus,
SNDRV_PCM_STREAM_PLAYBACK, stream_tag);
struct hdac_ext_stream *estream;
if (!stream)
return -EINVAL;
estream = stream_to_hdac_ext_stream(stream);
snd_hdac_ext_stream_spbcap_enable(ebus, enable, stream->index);
snd_hdac_ext_stream_set_spib(ebus, estream, size);
return 0;
}
static int skl_dsp_prepare(struct device *dev, unsigned int format,
unsigned int size, struct snd_dma_buffer *dmab)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct hdac_ext_stream *estream;
struct hdac_stream *stream;
struct snd_pcm_substream substream;
int ret;
if (!bus)
return -ENODEV;
memset(&substream, 0, sizeof(substream));
substream.stream = SNDRV_PCM_STREAM_PLAYBACK;
estream = snd_hdac_ext_stream_assign(ebus, &substream,
HDAC_EXT_STREAM_TYPE_HOST);
if (!estream)
return -ENODEV;
stream = hdac_stream(estream);
ret = snd_hdac_dsp_prepare(stream, format, size, dmab);
if (ret < 0)
return ret;
skl_dsp_setup_spib(dev, size, stream->stream_tag, true);
return stream->stream_tag;
}
static int skl_dsp_trigger(struct device *dev, bool start, int stream_tag)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_stream *stream;
struct hdac_bus *bus = ebus_to_hbus(ebus);
if (!bus)
return -ENODEV;
stream = snd_hdac_get_stream(bus,
SNDRV_PCM_STREAM_PLAYBACK, stream_tag);
if (!stream)
return -EINVAL;
snd_hdac_dsp_trigger(stream, start);
return 0;
}
static int skl_dsp_cleanup(struct device *dev,
struct snd_dma_buffer *dmab, int stream_tag)
{
struct hdac_ext_bus *ebus = dev_get_drvdata(dev);
struct hdac_stream *stream;
struct hdac_ext_stream *estream;
struct hdac_bus *bus = ebus_to_hbus(ebus);
if (!bus)
return -ENODEV;
stream = snd_hdac_get_stream(bus,
SNDRV_PCM_STREAM_PLAYBACK, stream_tag);
if (!stream)
return -EINVAL;
estream = stream_to_hdac_ext_stream(stream);
skl_dsp_setup_spib(dev, 0, stream_tag, false);
snd_hdac_ext_stream_release(estream, HDAC_EXT_STREAM_TYPE_HOST);
snd_hdac_dsp_cleanup(stream, dmab);
return 0;
}
static struct skl_dsp_loader_ops skl_get_loader_ops(void)
{
struct skl_dsp_loader_ops loader_ops;
memset(&loader_ops, 0, sizeof(struct skl_dsp_loader_ops));
loader_ops.alloc_dma_buf = skl_alloc_dma_buf;
loader_ops.free_dma_buf = skl_free_dma_buf;
return loader_ops;
}
static struct skl_dsp_loader_ops bxt_get_loader_ops(void)
{
struct skl_dsp_loader_ops loader_ops;
memset(&loader_ops, 0, sizeof(loader_ops));
loader_ops.alloc_dma_buf = skl_alloc_dma_buf;
loader_ops.free_dma_buf = skl_free_dma_buf;
loader_ops.prepare = skl_dsp_prepare;
loader_ops.trigger = skl_dsp_trigger;
loader_ops.cleanup = skl_dsp_cleanup;
return loader_ops;
}
const struct skl_dsp_ops *skl_get_dsp_ops(int pci_id)
{
int i;
for (i = 0; i < ARRAY_SIZE(dsp_ops); i++) {
if (dsp_ops[i].id == pci_id)
return &dsp_ops[i];
}
return NULL;
}
int skl_init_dsp(struct skl *skl)
{
void __iomem *mmio_base;
struct hdac_ext_bus *ebus = &skl->ebus;
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl_dsp_loader_ops loader_ops;
int irq = bus->irq;
const struct skl_dsp_ops *ops;
int ret;
snd_hdac_ext_bus_ppcap_enable(&skl->ebus, true);
snd_hdac_ext_bus_ppcap_int_enable(&skl->ebus, true);
mmio_base = pci_ioremap_bar(skl->pci, 4);
if (mmio_base == NULL) {
dev_err(bus->dev, "ioremap error\n");
return -ENXIO;
}
ops = skl_get_dsp_ops(skl->pci->device);
if (!ops)
return -EIO;
loader_ops = ops->loader_ops();
ret = ops->init(bus->dev, mmio_base, irq,
skl->fw_name, loader_ops,
&skl->skl_sst);
if (ret < 0)
return ret;
dev_dbg(bus->dev, "dsp registration status=%d\n", ret);
return ret;
}
int skl_free_dsp(struct skl *skl)
{
struct hdac_ext_bus *ebus = &skl->ebus;
struct hdac_bus *bus = ebus_to_hbus(ebus);
struct skl_sst *ctx = skl->skl_sst;
const struct skl_dsp_ops *ops;
snd_hdac_ext_bus_ppcap_int_enable(&skl->ebus, false);
ops = skl_get_dsp_ops(skl->pci->device);
if (!ops)
return -EIO;
ops->cleanup(bus->dev, ctx);
if (ctx->dsp->addr.lpe)
iounmap(ctx->dsp->addr.lpe);
return 0;
}
int skl_suspend_dsp(struct skl *skl)
{
struct skl_sst *ctx = skl->skl_sst;
int ret;
if (!skl->ebus.bus.ppcap)
return 0;
ret = skl_dsp_sleep(ctx->dsp);
if (ret < 0)
return ret;
snd_hdac_ext_bus_ppcap_int_enable(&skl->ebus, false);
snd_hdac_ext_bus_ppcap_enable(&skl->ebus, false);
return 0;
}
int skl_resume_dsp(struct skl *skl)
{
struct skl_sst *ctx = skl->skl_sst;
int ret;
if (!skl->ebus.bus.ppcap)
return 0;
snd_hdac_ext_bus_ppcap_enable(&skl->ebus, true);
snd_hdac_ext_bus_ppcap_int_enable(&skl->ebus, true);
if (skl->skl_sst->is_first_boot == true)
return 0;
ret = skl_dsp_wake(ctx->dsp);
if (ret < 0)
return ret;
skl_dsp_enable_notification(skl->skl_sst, false);
return ret;
}
enum skl_bitdepth skl_get_bit_depth(int params)
{
switch (params) {
case 8:
return SKL_DEPTH_8BIT;
case 16:
return SKL_DEPTH_16BIT;
case 24:
return SKL_DEPTH_24BIT;
case 32:
return SKL_DEPTH_32BIT;
default:
return SKL_DEPTH_INVALID;
}
}
static void skl_set_base_module_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_base_cfg *base_cfg)
{
struct skl_module_fmt *format = &mconfig->in_fmt[0];
base_cfg->audio_fmt.number_of_channels = (u8)format->channels;
base_cfg->audio_fmt.s_freq = format->s_freq;
base_cfg->audio_fmt.bit_depth = format->bit_depth;
base_cfg->audio_fmt.valid_bit_depth = format->valid_bit_depth;
base_cfg->audio_fmt.ch_cfg = format->ch_cfg;
dev_dbg(ctx->dev, "bit_depth=%x valid_bd=%x ch_config=%x\n",
format->bit_depth, format->valid_bit_depth,
format->ch_cfg);
base_cfg->audio_fmt.channel_map = format->ch_map;
base_cfg->audio_fmt.interleaving = format->interleaving_style;
base_cfg->cps = mconfig->mcps;
base_cfg->ibs = mconfig->ibs;
base_cfg->obs = mconfig->obs;
base_cfg->is_pages = mconfig->mem_pages;
}
static void skl_copy_copier_caps(struct skl_module_cfg *mconfig,
struct skl_cpr_cfg *cpr_mconfig)
{
if (mconfig->formats_config.caps_size == 0)
return;
memcpy(cpr_mconfig->gtw_cfg.config_data,
mconfig->formats_config.caps,
mconfig->formats_config.caps_size);
cpr_mconfig->gtw_cfg.config_length =
(mconfig->formats_config.caps_size) / 4;
}
static u32 skl_get_node_id(struct skl_sst *ctx,
struct skl_module_cfg *mconfig)
{
union skl_connector_node_id node_id = {0};
union skl_ssp_dma_node ssp_node = {0};
struct skl_pipe_params *params = mconfig->pipe->p_params;
switch (mconfig->dev_type) {
case SKL_DEVICE_BT:
node_id.node.dma_type =
(SKL_CONN_SOURCE == mconfig->hw_conn_type) ?
SKL_DMA_I2S_LINK_OUTPUT_CLASS :
SKL_DMA_I2S_LINK_INPUT_CLASS;
node_id.node.vindex = params->host_dma_id +
(mconfig->vbus_id << 3);
break;
case SKL_DEVICE_I2S:
node_id.node.dma_type =
(SKL_CONN_SOURCE == mconfig->hw_conn_type) ?
SKL_DMA_I2S_LINK_OUTPUT_CLASS :
SKL_DMA_I2S_LINK_INPUT_CLASS;
ssp_node.dma_node.time_slot_index = mconfig->time_slot;
ssp_node.dma_node.i2s_instance = mconfig->vbus_id;
node_id.node.vindex = ssp_node.val;
break;
case SKL_DEVICE_DMIC:
node_id.node.dma_type = SKL_DMA_DMIC_LINK_INPUT_CLASS;
node_id.node.vindex = mconfig->vbus_id +
(mconfig->time_slot);
break;
case SKL_DEVICE_HDALINK:
node_id.node.dma_type =
(SKL_CONN_SOURCE == mconfig->hw_conn_type) ?
SKL_DMA_HDA_LINK_OUTPUT_CLASS :
SKL_DMA_HDA_LINK_INPUT_CLASS;
node_id.node.vindex = params->link_dma_id;
break;
case SKL_DEVICE_HDAHOST:
node_id.node.dma_type =
(SKL_CONN_SOURCE == mconfig->hw_conn_type) ?
SKL_DMA_HDA_HOST_OUTPUT_CLASS :
SKL_DMA_HDA_HOST_INPUT_CLASS;
node_id.node.vindex = params->host_dma_id;
break;
default:
node_id.val = 0xFFFFFFFF;
break;
}
return node_id.val;
}
static void skl_setup_cpr_gateway_cfg(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_cpr_cfg *cpr_mconfig)
{
cpr_mconfig->gtw_cfg.node_id = skl_get_node_id(ctx, mconfig);
if (cpr_mconfig->gtw_cfg.node_id == SKL_NON_GATEWAY_CPR_NODE_ID) {
cpr_mconfig->cpr_feature_mask = 0;
return;
}
if (SKL_CONN_SOURCE == mconfig->hw_conn_type)
cpr_mconfig->gtw_cfg.dma_buffer_size = 2 * mconfig->obs;
else
cpr_mconfig->gtw_cfg.dma_buffer_size = 2 * mconfig->ibs;
cpr_mconfig->cpr_feature_mask = 0;
cpr_mconfig->gtw_cfg.config_length = 0;
skl_copy_copier_caps(mconfig, cpr_mconfig);
}
int skl_dsp_set_dma_control(struct skl_sst *ctx, struct skl_module_cfg *mconfig)
{
struct skl_dma_control *dma_ctrl;
struct skl_i2s_config_blob config_blob;
struct skl_ipc_large_config_msg msg = {0};
int err = 0;
if (mconfig->formats_config.caps_size == sizeof(config_blob))
return 0;
msg.large_param_id = DMA_CONTROL_ID;
msg.param_data_size = sizeof(struct skl_dma_control) +
mconfig->formats_config.caps_size;
dma_ctrl = kzalloc(msg.param_data_size, GFP_KERNEL);
if (dma_ctrl == NULL)
return -ENOMEM;
dma_ctrl->node_id = skl_get_node_id(ctx, mconfig);
dma_ctrl->config_length = sizeof(config_blob) / 4;
memcpy(dma_ctrl->config_data, mconfig->formats_config.caps,
mconfig->formats_config.caps_size);
err = skl_ipc_set_large_config(&ctx->ipc, &msg, (u32 *)dma_ctrl);
kfree(dma_ctrl);
return err;
}
static void skl_setup_out_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_audio_data_format *out_fmt)
{
struct skl_module_fmt *format = &mconfig->out_fmt[0];
out_fmt->number_of_channels = (u8)format->channels;
out_fmt->s_freq = format->s_freq;
out_fmt->bit_depth = format->bit_depth;
out_fmt->valid_bit_depth = format->valid_bit_depth;
out_fmt->ch_cfg = format->ch_cfg;
out_fmt->channel_map = format->ch_map;
out_fmt->interleaving = format->interleaving_style;
out_fmt->sample_type = format->sample_type;
dev_dbg(ctx->dev, "copier out format chan=%d fre=%d bitdepth=%d\n",
out_fmt->number_of_channels, format->s_freq, format->bit_depth);
}
static void skl_set_src_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_src_module_cfg *src_mconfig)
{
struct skl_module_fmt *fmt = &mconfig->out_fmt[0];
skl_set_base_module_format(ctx, mconfig,
(struct skl_base_cfg *)src_mconfig);
src_mconfig->src_cfg = fmt->s_freq;
}
static void skl_set_updown_mixer_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_up_down_mixer_cfg *mixer_mconfig)
{
struct skl_module_fmt *fmt = &mconfig->out_fmt[0];
int i = 0;
skl_set_base_module_format(ctx, mconfig,
(struct skl_base_cfg *)mixer_mconfig);
mixer_mconfig->out_ch_cfg = fmt->ch_cfg;
mixer_mconfig->coeff_sel = 0x0;
for (i = 0; i < UP_DOWN_MIXER_MAX_COEFF; i++)
mixer_mconfig->coeff[i] = 0xDEADBEEF;
}
static void skl_set_copier_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_cpr_cfg *cpr_mconfig)
{
struct skl_audio_data_format *out_fmt = &cpr_mconfig->out_fmt;
struct skl_base_cfg *base_cfg = (struct skl_base_cfg *)cpr_mconfig;
skl_set_base_module_format(ctx, mconfig, base_cfg);
skl_setup_out_format(ctx, mconfig, out_fmt);
skl_setup_cpr_gateway_cfg(ctx, mconfig, cpr_mconfig);
}
static void skl_set_algo_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_algo_cfg *algo_mcfg)
{
struct skl_base_cfg *base_cfg = (struct skl_base_cfg *)algo_mcfg;
skl_set_base_module_format(ctx, mconfig, base_cfg);
if (mconfig->formats_config.caps_size == 0)
return;
memcpy(algo_mcfg->params,
mconfig->formats_config.caps,
mconfig->formats_config.caps_size);
}
static void skl_set_base_outfmt_format(struct skl_sst *ctx,
struct skl_module_cfg *mconfig,
struct skl_base_outfmt_cfg *base_outfmt_mcfg)
{
struct skl_audio_data_format *out_fmt = &base_outfmt_mcfg->out_fmt;
struct skl_base_cfg *base_cfg =
(struct skl_base_cfg *)base_outfmt_mcfg;
skl_set_base_module_format(ctx, mconfig, base_cfg);
skl_setup_out_format(ctx, mconfig, out_fmt);
}
static u16 skl_get_module_param_size(struct skl_sst *ctx,
struct skl_module_cfg *mconfig)
{
u16 param_size;
switch (mconfig->m_type) {
case SKL_MODULE_TYPE_COPIER:
param_size = sizeof(struct skl_cpr_cfg);
param_size += mconfig->formats_config.caps_size;
return param_size;
case SKL_MODULE_TYPE_SRCINT:
return sizeof(struct skl_src_module_cfg);
case SKL_MODULE_TYPE_UPDWMIX:
return sizeof(struct skl_up_down_mixer_cfg);
case SKL_MODULE_TYPE_ALGO:
param_size = sizeof(struct skl_base_cfg);
param_size += mconfig->formats_config.caps_size;
return param_size;
case SKL_MODULE_TYPE_BASE_OUTFMT:
case SKL_MODULE_TYPE_KPB:
return sizeof(struct skl_base_outfmt_cfg);
default:
return sizeof(struct skl_base_cfg);
}
return 0;
}
static int skl_set_module_format(struct skl_sst *ctx,
struct skl_module_cfg *module_config,
u16 *module_config_size,
void **param_data)
{
u16 param_size;
param_size = skl_get_module_param_size(ctx, module_config);
*param_data = kzalloc(param_size, GFP_KERNEL);
if (NULL == *param_data)
return -ENOMEM;
*module_config_size = param_size;
switch (module_config->m_type) {
case SKL_MODULE_TYPE_COPIER:
skl_set_copier_format(ctx, module_config, *param_data);
break;
case SKL_MODULE_TYPE_SRCINT:
skl_set_src_format(ctx, module_config, *param_data);
break;
case SKL_MODULE_TYPE_UPDWMIX:
skl_set_updown_mixer_format(ctx, module_config, *param_data);
break;
case SKL_MODULE_TYPE_ALGO:
skl_set_algo_format(ctx, module_config, *param_data);
break;
case SKL_MODULE_TYPE_BASE_OUTFMT:
case SKL_MODULE_TYPE_KPB:
skl_set_base_outfmt_format(ctx, module_config, *param_data);
break;
default:
skl_set_base_module_format(ctx, module_config, *param_data);
break;
}
dev_dbg(ctx->dev, "Module type=%d config size: %d bytes\n",
module_config->id.module_id, param_size);
print_hex_dump_debug("Module params:", DUMP_PREFIX_OFFSET, 8, 4,
*param_data, param_size, false);
return 0;
}
static int skl_get_queue_index(struct skl_module_pin *mpin,
struct skl_module_inst_id id, int max)
{
int i;
for (i = 0; i < max; i++) {
if (mpin[i].id.module_id == id.module_id &&
mpin[i].id.instance_id == id.instance_id)
return i;
}
return -EINVAL;
}
static int skl_alloc_queue(struct skl_module_pin *mpin,
struct skl_module_cfg *tgt_cfg, int max)
{
int i;
struct skl_module_inst_id id = tgt_cfg->id;
for (i = 0; i < max; i++) {
if (mpin[i].is_dynamic) {
if (!mpin[i].in_use &&
mpin[i].pin_state == SKL_PIN_UNBIND) {
mpin[i].in_use = true;
mpin[i].id.module_id = id.module_id;
mpin[i].id.instance_id = id.instance_id;
mpin[i].id.pvt_id = id.pvt_id;
mpin[i].tgt_mcfg = tgt_cfg;
return i;
}
} else {
if (mpin[i].id.module_id == id.module_id &&
mpin[i].id.instance_id == id.instance_id &&
mpin[i].pin_state == SKL_PIN_UNBIND) {
mpin[i].tgt_mcfg = tgt_cfg;
return i;
}
}
}
return -EINVAL;
}
static void skl_free_queue(struct skl_module_pin *mpin, int q_index)
{
if (mpin[q_index].is_dynamic) {
mpin[q_index].in_use = false;
mpin[q_index].id.module_id = 0;
mpin[q_index].id.instance_id = 0;
mpin[q_index].id.pvt_id = 0;
}
mpin[q_index].pin_state = SKL_PIN_UNBIND;
mpin[q_index].tgt_mcfg = NULL;
}
static void skl_clear_module_state(struct skl_module_pin *mpin, int max,
struct skl_module_cfg *mcfg)
{
int i;
bool found = false;
for (i = 0; i < max; i++) {
if (mpin[i].pin_state == SKL_PIN_UNBIND)
continue;
found = true;
break;
}
if (!found)
mcfg->m_state = SKL_MODULE_UNINIT;
return;
}
int skl_init_module(struct skl_sst *ctx,
struct skl_module_cfg *mconfig)
{
u16 module_config_size = 0;
void *param_data = NULL;
int ret;
struct skl_ipc_init_instance_msg msg;
dev_dbg(ctx->dev, "%s: module_id = %d instance=%d\n", __func__,
mconfig->id.module_id, mconfig->id.pvt_id);
if (mconfig->pipe->state != SKL_PIPE_CREATED) {
dev_err(ctx->dev, "Pipe not created state= %d pipe_id= %d\n",
mconfig->pipe->state, mconfig->pipe->ppl_id);
return -EIO;
}
ret = skl_set_module_format(ctx, mconfig,
&module_config_size, &param_data);
if (ret < 0) {
dev_err(ctx->dev, "Failed to set module format ret=%d\n", ret);
return ret;
}
msg.module_id = mconfig->id.module_id;
msg.instance_id = mconfig->id.pvt_id;
msg.ppl_instance_id = mconfig->pipe->ppl_id;
msg.param_data_size = module_config_size;
msg.core_id = mconfig->core_id;
msg.domain = mconfig->domain;
ret = skl_ipc_init_instance(&ctx->ipc, &msg, param_data);
if (ret < 0) {
dev_err(ctx->dev, "Failed to init instance ret=%d\n", ret);
kfree(param_data);
return ret;
}
mconfig->m_state = SKL_MODULE_INIT_DONE;
kfree(param_data);
return ret;
}
static void skl_dump_bind_info(struct skl_sst *ctx, struct skl_module_cfg
*src_module, struct skl_module_cfg *dst_module)
{
dev_dbg(ctx->dev, "%s: src module_id = %d src_instance=%d\n",
__func__, src_module->id.module_id, src_module->id.pvt_id);
dev_dbg(ctx->dev, "%s: dst_module=%d dst_instacne=%d\n", __func__,
dst_module->id.module_id, dst_module->id.pvt_id);
dev_dbg(ctx->dev, "src_module state = %d dst module state = %d\n",
src_module->m_state, dst_module->m_state);
}
int skl_unbind_modules(struct skl_sst *ctx,
struct skl_module_cfg *src_mcfg,
struct skl_module_cfg *dst_mcfg)
{
int ret;
struct skl_ipc_bind_unbind_msg msg;
struct skl_module_inst_id src_id = src_mcfg->id;
struct skl_module_inst_id dst_id = dst_mcfg->id;
int in_max = dst_mcfg->max_in_queue;
int out_max = src_mcfg->max_out_queue;
int src_index, dst_index, src_pin_state, dst_pin_state;
skl_dump_bind_info(ctx, src_mcfg, dst_mcfg);
src_index = skl_get_queue_index(src_mcfg->m_out_pin, dst_id, out_max);
if (src_index < 0)
return 0;
msg.src_queue = src_index;
dst_index = skl_get_queue_index(dst_mcfg->m_in_pin, src_id, in_max);
if (dst_index < 0)
return 0;
msg.dst_queue = dst_index;
src_pin_state = src_mcfg->m_out_pin[src_index].pin_state;
dst_pin_state = dst_mcfg->m_in_pin[dst_index].pin_state;
if (src_pin_state != SKL_PIN_BIND_DONE ||
dst_pin_state != SKL_PIN_BIND_DONE)
return 0;
msg.module_id = src_mcfg->id.module_id;
msg.instance_id = src_mcfg->id.pvt_id;
msg.dst_module_id = dst_mcfg->id.module_id;
msg.dst_instance_id = dst_mcfg->id.pvt_id;
msg.bind = false;
ret = skl_ipc_bind_unbind(&ctx->ipc, &msg);
if (!ret) {
skl_free_queue(src_mcfg->m_out_pin, src_index);
skl_free_queue(dst_mcfg->m_in_pin, dst_index);
skl_clear_module_state(src_mcfg->m_out_pin, out_max, src_mcfg);
}
return ret;
}
int skl_bind_modules(struct skl_sst *ctx,
struct skl_module_cfg *src_mcfg,
struct skl_module_cfg *dst_mcfg)
{
int ret;
struct skl_ipc_bind_unbind_msg msg;
int in_max = dst_mcfg->max_in_queue;
int out_max = src_mcfg->max_out_queue;
int src_index, dst_index;
skl_dump_bind_info(ctx, src_mcfg, dst_mcfg);
if (src_mcfg->m_state < SKL_MODULE_INIT_DONE ||
dst_mcfg->m_state < SKL_MODULE_INIT_DONE)
return 0;
src_index = skl_alloc_queue(src_mcfg->m_out_pin, dst_mcfg, out_max);
if (src_index < 0)
return -EINVAL;
msg.src_queue = src_index;
dst_index = skl_alloc_queue(dst_mcfg->m_in_pin, src_mcfg, in_max);
if (dst_index < 0) {
skl_free_queue(src_mcfg->m_out_pin, src_index);
return -EINVAL;
}
msg.dst_queue = dst_index;
dev_dbg(ctx->dev, "src queue = %d dst queue =%d\n",
msg.src_queue, msg.dst_queue);
msg.module_id = src_mcfg->id.module_id;
msg.instance_id = src_mcfg->id.pvt_id;
msg.dst_module_id = dst_mcfg->id.module_id;
msg.dst_instance_id = dst_mcfg->id.pvt_id;
msg.bind = true;
ret = skl_ipc_bind_unbind(&ctx->ipc, &msg);
if (!ret) {
src_mcfg->m_state = SKL_MODULE_BIND_DONE;
src_mcfg->m_out_pin[src_index].pin_state = SKL_PIN_BIND_DONE;
dst_mcfg->m_in_pin[dst_index].pin_state = SKL_PIN_BIND_DONE;
} else {
skl_free_queue(src_mcfg->m_out_pin, src_index);
skl_free_queue(dst_mcfg->m_in_pin, dst_index);
}
return ret;
}
static int skl_set_pipe_state(struct skl_sst *ctx, struct skl_pipe *pipe,
enum skl_ipc_pipeline_state state)
{
dev_dbg(ctx->dev, "%s: pipe_satate = %d\n", __func__, state);
return skl_ipc_set_pipeline_state(&ctx->ipc, pipe->ppl_id, state);
}
int skl_create_pipeline(struct skl_sst *ctx, struct skl_pipe *pipe)
{
int ret;
dev_dbg(ctx->dev, "%s: pipe_id = %d\n", __func__, pipe->ppl_id);
ret = skl_ipc_create_pipeline(&ctx->ipc, pipe->memory_pages,
pipe->pipe_priority, pipe->ppl_id);
if (ret < 0) {
dev_err(ctx->dev, "Failed to create pipeline\n");
return ret;
}
pipe->state = SKL_PIPE_CREATED;
return 0;
}
int skl_delete_pipe(struct skl_sst *ctx, struct skl_pipe *pipe)
{
int ret;
dev_dbg(ctx->dev, "%s: pipe = %d\n", __func__, pipe->ppl_id);
if (pipe->state > SKL_PIPE_STARTED) {
ret = skl_set_pipe_state(ctx, pipe, PPL_PAUSED);
if (ret < 0) {
dev_err(ctx->dev, "Failed to stop pipeline\n");
return ret;
}
pipe->state = SKL_PIPE_PAUSED;
}
if (pipe->state < SKL_PIPE_CREATED)
return 0;
ret = skl_ipc_delete_pipeline(&ctx->ipc, pipe->ppl_id);
if (ret < 0) {
dev_err(ctx->dev, "Failed to delete pipeline\n");
return ret;
}
pipe->state = SKL_PIPE_INVALID;
return ret;
}
int skl_run_pipe(struct skl_sst *ctx, struct skl_pipe *pipe)
{
int ret;
dev_dbg(ctx->dev, "%s: pipe = %d\n", __func__, pipe->ppl_id);
if (pipe->state < SKL_PIPE_CREATED)
return 0;
ret = skl_set_pipe_state(ctx, pipe, PPL_PAUSED);
if (ret < 0) {
dev_err(ctx->dev, "Failed to pause pipe\n");
return ret;
}
pipe->state = SKL_PIPE_PAUSED;
ret = skl_set_pipe_state(ctx, pipe, PPL_RUNNING);
if (ret < 0) {
dev_err(ctx->dev, "Failed to start pipe\n");
return ret;
}
pipe->state = SKL_PIPE_STARTED;
return 0;
}
int skl_stop_pipe(struct skl_sst *ctx, struct skl_pipe *pipe)
{
int ret;
dev_dbg(ctx->dev, "In %s pipe=%d\n", __func__, pipe->ppl_id);
if (pipe->state < SKL_PIPE_PAUSED)
return 0;
ret = skl_set_pipe_state(ctx, pipe, PPL_PAUSED);
if (ret < 0) {
dev_dbg(ctx->dev, "Failed to stop pipe\n");
return ret;
}
pipe->state = SKL_PIPE_PAUSED;
return 0;
}
int skl_reset_pipe(struct skl_sst *ctx, struct skl_pipe *pipe)
{
int ret;
if (pipe->state < SKL_PIPE_PAUSED)
return 0;
ret = skl_set_pipe_state(ctx, pipe, PPL_RESET);
if (ret < 0) {
dev_dbg(ctx->dev, "Failed to reset pipe ret=%d\n", ret);
return ret;
}
pipe->state = SKL_PIPE_RESET;
return 0;
}
int skl_set_module_params(struct skl_sst *ctx, u32 *params, int size,
u32 param_id, struct skl_module_cfg *mcfg)
{
struct skl_ipc_large_config_msg msg;
msg.module_id = mcfg->id.module_id;
msg.instance_id = mcfg->id.pvt_id;
msg.param_data_size = size;
msg.large_param_id = param_id;
return skl_ipc_set_large_config(&ctx->ipc, &msg, params);
}
int skl_get_module_params(struct skl_sst *ctx, u32 *params, int size,
u32 param_id, struct skl_module_cfg *mcfg)
{
struct skl_ipc_large_config_msg msg;
msg.module_id = mcfg->id.module_id;
msg.instance_id = mcfg->id.pvt_id;
msg.param_data_size = size;
msg.large_param_id = param_id;
return skl_ipc_get_large_config(&ctx->ipc, &msg, params);
}
