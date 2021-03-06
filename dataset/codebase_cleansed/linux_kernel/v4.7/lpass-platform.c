static int lpass_platform_pcmops_open(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
int ret;
snd_soc_set_runtime_hwparams(substream, &lpass_platform_pcm_hardware);
runtime->dma_bytes = lpass_platform_pcm_hardware.buffer_bytes_max;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0) {
dev_err(soc_runtime->dev, "%s() setting constraints failed: %d\n",
__func__, ret);
return -EINVAL;
}
snd_pcm_set_runtime_buffer(substream, &substream->dma_buffer);
return 0;
}
static int lpass_platform_pcmops_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_pcm_data *pcm_data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
snd_pcm_format_t format = params_format(params);
unsigned int channels = params_channels(params);
unsigned int regval;
int ch, dir = substream->stream;
int bitwidth;
int ret, dma_port = pcm_data->i2s_port + v->dmactl_audif_start;
if (dir == SNDRV_PCM_STREAM_PLAYBACK)
ch = pcm_data->rdma_ch;
else
ch = pcm_data->wrdma_ch;
bitwidth = snd_pcm_format_width(format);
if (bitwidth < 0) {
dev_err(soc_runtime->dev, "%s() invalid bit width given: %d\n",
__func__, bitwidth);
return bitwidth;
}
regval = LPAIF_DMACTL_BURSTEN_INCR4 |
LPAIF_DMACTL_AUDINTF(dma_port) |
LPAIF_DMACTL_FIFOWM_8;
switch (bitwidth) {
case 16:
switch (channels) {
case 1:
case 2:
regval |= LPAIF_DMACTL_WPSCNT_ONE;
break;
case 4:
regval |= LPAIF_DMACTL_WPSCNT_TWO;
break;
case 6:
regval |= LPAIF_DMACTL_WPSCNT_THREE;
break;
case 8:
regval |= LPAIF_DMACTL_WPSCNT_FOUR;
break;
default:
dev_err(soc_runtime->dev, "%s() invalid PCM config given: bw=%d, ch=%u\n",
__func__, bitwidth, channels);
return -EINVAL;
}
break;
case 24:
case 32:
switch (channels) {
case 1:
regval |= LPAIF_DMACTL_WPSCNT_ONE;
break;
case 2:
regval |= LPAIF_DMACTL_WPSCNT_TWO;
break;
case 4:
regval |= LPAIF_DMACTL_WPSCNT_FOUR;
break;
case 6:
regval |= LPAIF_DMACTL_WPSCNT_SIX;
break;
case 8:
regval |= LPAIF_DMACTL_WPSCNT_EIGHT;
break;
default:
dev_err(soc_runtime->dev, "%s() invalid PCM config given: bw=%d, ch=%u\n",
__func__, bitwidth, channels);
return -EINVAL;
}
break;
default:
dev_err(soc_runtime->dev, "%s() invalid PCM config given: bw=%d, ch=%u\n",
__func__, bitwidth, channels);
return -EINVAL;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_DMACTL_REG(v, ch, dir), regval);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
return ret;
}
return 0;
}
static int lpass_platform_pcmops_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_pcm_data *pcm_data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
unsigned int reg;
int ret;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
reg = LPAIF_RDMACTL_REG(v, pcm_data->rdma_ch);
else
reg = LPAIF_WRDMACTL_REG(v, pcm_data->wrdma_ch);
ret = regmap_write(drvdata->lpaif_map, reg, 0);
if (ret)
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
return ret;
}
static int lpass_platform_pcmops_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_pcm_data *pcm_data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
int ret, ch, dir = substream->stream;
if (dir == SNDRV_PCM_STREAM_PLAYBACK)
ch = pcm_data->rdma_ch;
else
ch = pcm_data->wrdma_ch;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_DMABASE_REG(v, ch, dir),
runtime->dma_addr);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmabase reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_DMABUFF_REG(v, ch, dir),
(snd_pcm_lib_buffer_bytes(substream) >> 2) - 1);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmabuff reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_DMAPER_REG(v, ch, dir),
(snd_pcm_lib_period_bytes(substream) >> 2) - 1);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmaper reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_DMACTL_REG(v, ch, dir),
LPAIF_DMACTL_ENABLE_MASK, LPAIF_DMACTL_ENABLE_ON);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
return ret;
}
return 0;
}
static int lpass_platform_pcmops_trigger(struct snd_pcm_substream *substream,
int cmd)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_pcm_data *pcm_data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
int ret, ch, dir = substream->stream;
if (dir == SNDRV_PCM_STREAM_PLAYBACK)
ch = pcm_data->rdma_ch;
else
ch = pcm_data->wrdma_ch;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ret = regmap_write(drvdata->lpaif_map,
LPAIF_IRQCLEAR_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_ALL(ch));
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to irqclear reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_IRQEN_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_ALL(ch),
LPAIF_IRQ_ALL(ch));
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to irqen reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_DMACTL_REG(v, ch, dir),
LPAIF_DMACTL_ENABLE_MASK,
LPAIF_DMACTL_ENABLE_ON);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
return ret;
}
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_DMACTL_REG(v, ch, dir),
LPAIF_DMACTL_ENABLE_MASK,
LPAIF_DMACTL_ENABLE_OFF);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_IRQEN_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_ALL(ch), 0);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to irqen reg: %d\n",
__func__, ret);
return ret;
}
break;
}
return 0;
}
static snd_pcm_uframes_t lpass_platform_pcmops_pointer(
struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_pcm_data *pcm_data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
unsigned int base_addr, curr_addr;
int ret, ch, dir = substream->stream;
if (dir == SNDRV_PCM_STREAM_PLAYBACK)
ch = pcm_data->rdma_ch;
else
ch = pcm_data->wrdma_ch;
ret = regmap_read(drvdata->lpaif_map,
LPAIF_DMABASE_REG(v, ch, dir), &base_addr);
if (ret) {
dev_err(soc_runtime->dev, "%s() error reading from rdmabase reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_read(drvdata->lpaif_map,
LPAIF_DMACURR_REG(v, ch, dir), &curr_addr);
if (ret) {
dev_err(soc_runtime->dev, "%s() error reading from rdmacurr reg: %d\n",
__func__, ret);
return ret;
}
return bytes_to_frames(substream->runtime, curr_addr - base_addr);
}
static int lpass_platform_pcmops_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
struct snd_pcm_runtime *runtime = substream->runtime;
return dma_mmap_coherent(substream->pcm->card->dev, vma,
runtime->dma_area, runtime->dma_addr,
runtime->dma_bytes);
}
static irqreturn_t lpass_dma_interrupt_handler(
struct snd_pcm_substream *substream,
struct lpass_data *drvdata,
int chan, u32 interrupts)
{
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_variant *v = drvdata->variant;
irqreturn_t ret = IRQ_NONE;
int rv;
if (interrupts & LPAIF_IRQ_PER(chan)) {
rv = regmap_write(drvdata->lpaif_map,
LPAIF_IRQCLEAR_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_PER(chan));
if (rv) {
dev_err(soc_runtime->dev, "%s() error writing to irqclear reg: %d\n",
__func__, rv);
return IRQ_NONE;
}
snd_pcm_period_elapsed(substream);
ret = IRQ_HANDLED;
}
if (interrupts & LPAIF_IRQ_XRUN(chan)) {
rv = regmap_write(drvdata->lpaif_map,
LPAIF_IRQCLEAR_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_XRUN(chan));
if (rv) {
dev_err(soc_runtime->dev, "%s() error writing to irqclear reg: %d\n",
__func__, rv);
return IRQ_NONE;
}
dev_warn(soc_runtime->dev, "%s() xrun warning\n", __func__);
snd_pcm_stop(substream, SNDRV_PCM_STATE_XRUN);
ret = IRQ_HANDLED;
}
if (interrupts & LPAIF_IRQ_ERR(chan)) {
rv = regmap_write(drvdata->lpaif_map,
LPAIF_IRQCLEAR_REG(v, LPAIF_IRQ_PORT_HOST),
LPAIF_IRQ_ERR(chan));
if (rv) {
dev_err(soc_runtime->dev, "%s() error writing to irqclear reg: %d\n",
__func__, rv);
return IRQ_NONE;
}
dev_err(soc_runtime->dev, "%s() bus access error\n", __func__);
snd_pcm_stop(substream, SNDRV_PCM_STATE_DISCONNECTED);
ret = IRQ_HANDLED;
}
return ret;
}
static irqreturn_t lpass_platform_lpaif_irq(int irq, void *data)
{
struct lpass_data *drvdata = data;
struct lpass_variant *v = drvdata->variant;
unsigned int irqs;
int rv, chan;
rv = regmap_read(drvdata->lpaif_map,
LPAIF_IRQSTAT_REG(v, LPAIF_IRQ_PORT_HOST), &irqs);
if (rv) {
pr_err("%s() error reading from irqstat reg: %d\n",
__func__, rv);
return IRQ_NONE;
}
for (chan = 0; chan < LPASS_MAX_DMA_CHANNELS; chan++) {
if (irqs & LPAIF_IRQ_ALL(chan) && drvdata->substream[chan]) {
rv = lpass_dma_interrupt_handler(
drvdata->substream[chan],
drvdata, chan, irqs);
if (rv != IRQ_HANDLED)
return rv;
}
}
return IRQ_HANDLED;
}
static int lpass_platform_pcm_new(struct snd_soc_pcm_runtime *soc_runtime)
{
struct snd_pcm *pcm = soc_runtime->pcm;
struct snd_pcm_substream *psubstream, *csubstream;
struct snd_soc_dai *cpu_dai = soc_runtime->cpu_dai;
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
int ret = -EINVAL;
struct lpass_pcm_data *data;
size_t size = lpass_platform_pcm_hardware.buffer_bytes_max;
data = devm_kzalloc(soc_runtime->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->i2s_port = cpu_dai->driver->id;
snd_soc_pcm_set_drvdata(soc_runtime, data);
psubstream = pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
if (psubstream) {
if (v->alloc_dma_channel)
data->rdma_ch = v->alloc_dma_channel(drvdata,
SNDRV_PCM_STREAM_PLAYBACK);
if (data->rdma_ch < 0)
return data->rdma_ch;
drvdata->substream[data->rdma_ch] = psubstream;
ret = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
soc_runtime->platform->dev,
size, &psubstream->dma_buffer);
if (ret)
goto playback_alloc_err;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMACTL_REG(v, data->rdma_ch), 0);
if (ret) {
dev_err(soc_runtime->dev,
"%s() error writing to rdmactl reg: %d\n",
__func__, ret);
goto capture_alloc_err;
}
}
csubstream = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
if (csubstream) {
if (v->alloc_dma_channel)
data->wrdma_ch = v->alloc_dma_channel(drvdata,
SNDRV_PCM_STREAM_CAPTURE);
if (data->wrdma_ch < 0) {
ret = data->wrdma_ch;
goto capture_alloc_err;
}
drvdata->substream[data->wrdma_ch] = csubstream;
ret = snd_dma_alloc_pages(SNDRV_DMA_TYPE_DEV,
soc_runtime->platform->dev,
size, &csubstream->dma_buffer);
if (ret)
goto capture_alloc_err;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_WRDMACTL_REG(v, data->wrdma_ch), 0);
if (ret) {
dev_err(soc_runtime->dev,
"%s() error writing to wrdmactl reg: %d\n",
__func__, ret);
goto capture_reg_err;
}
}
return 0;
capture_reg_err:
if (csubstream)
snd_dma_free_pages(&csubstream->dma_buffer);
capture_alloc_err:
if (psubstream)
snd_dma_free_pages(&psubstream->dma_buffer);
playback_alloc_err:
dev_err(soc_runtime->dev, "Cannot allocate buffer(s)\n");
return ret;
}
static void lpass_platform_pcm_free(struct snd_pcm *pcm)
{
struct snd_soc_pcm_runtime *rt;
struct lpass_data *drvdata;
struct lpass_pcm_data *data;
struct lpass_variant *v;
struct snd_pcm_substream *substream;
int ch, i;
for (i = 0; i < ARRAY_SIZE(pcm->streams); i++) {
substream = pcm->streams[i].substream;
if (substream) {
rt = substream->private_data;
data = snd_soc_pcm_get_drvdata(rt);
drvdata = snd_soc_platform_get_drvdata(rt->platform);
ch = (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
? data->rdma_ch
: data->wrdma_ch;
v = drvdata->variant;
drvdata->substream[ch] = NULL;
if (v->free_dma_channel)
v->free_dma_channel(drvdata, ch);
snd_dma_free_pages(&substream->dma_buffer);
substream->dma_buffer.area = NULL;
substream->dma_buffer.addr = 0;
}
}
}
int asoc_qcom_lpass_platform_register(struct platform_device *pdev)
{
struct lpass_data *drvdata = platform_get_drvdata(pdev);
struct lpass_variant *v = drvdata->variant;
int ret;
drvdata->lpaif_irq = platform_get_irq_byname(pdev, "lpass-irq-lpaif");
if (drvdata->lpaif_irq < 0) {
dev_err(&pdev->dev, "%s() error getting irq handle: %d\n",
__func__, drvdata->lpaif_irq);
return -ENODEV;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_IRQEN_REG(v, LPAIF_IRQ_PORT_HOST), 0);
if (ret) {
dev_err(&pdev->dev, "%s() error writing to irqen reg: %d\n",
__func__, ret);
return ret;
}
ret = devm_request_irq(&pdev->dev, drvdata->lpaif_irq,
lpass_platform_lpaif_irq, IRQF_TRIGGER_RISING,
"lpass-irq-lpaif", drvdata);
if (ret) {
dev_err(&pdev->dev, "%s() irq request failed: %d\n",
__func__, ret);
return ret;
}
return devm_snd_soc_register_platform(&pdev->dev,
&lpass_platform_driver);
}
