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
int bitwidth;
int ret, rdma_port = pcm_data->i2s_port + v->rdmactl_audif_start;
bitwidth = snd_pcm_format_width(format);
if (bitwidth < 0) {
dev_err(soc_runtime->dev, "%s() invalid bit width given: %d\n",
__func__, bitwidth);
return bitwidth;
}
regval = LPAIF_RDMACTL_BURSTEN_INCR4 |
LPAIF_RDMACTL_AUDINTF(rdma_port) |
LPAIF_RDMACTL_FIFOWM_8;
switch (bitwidth) {
case 16:
switch (channels) {
case 1:
case 2:
regval |= LPAIF_RDMACTL_WPSCNT_ONE;
break;
case 4:
regval |= LPAIF_RDMACTL_WPSCNT_TWO;
break;
case 6:
regval |= LPAIF_RDMACTL_WPSCNT_THREE;
break;
case 8:
regval |= LPAIF_RDMACTL_WPSCNT_FOUR;
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
regval |= LPAIF_RDMACTL_WPSCNT_ONE;
break;
case 2:
regval |= LPAIF_RDMACTL_WPSCNT_TWO;
break;
case 4:
regval |= LPAIF_RDMACTL_WPSCNT_FOUR;
break;
case 6:
regval |= LPAIF_RDMACTL_WPSCNT_SIX;
break;
case 8:
regval |= LPAIF_RDMACTL_WPSCNT_EIGHT;
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
LPAIF_RDMACTL_REG(v, pcm_data->rdma_ch), regval);
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
int ret;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMACTL_REG(v, pcm_data->rdma_ch), 0);
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
int ret, ch = pcm_data->rdma_ch;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMABASE_REG(v, ch),
runtime->dma_addr);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmabase reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMABUFF_REG(v, ch),
(snd_pcm_lib_buffer_bytes(substream) >> 2) - 1);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmabuff reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMAPER_REG(v, ch),
(snd_pcm_lib_period_bytes(substream) >> 2) - 1);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmaper reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_RDMACTL_REG(v, ch),
LPAIF_RDMACTL_ENABLE_MASK, LPAIF_RDMACTL_ENABLE_ON);
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
int ret, ch = pcm_data->rdma_ch;
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
LPAIF_RDMACTL_REG(v, ch),
LPAIF_RDMACTL_ENABLE_MASK,
LPAIF_RDMACTL_ENABLE_ON);
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
LPAIF_RDMACTL_REG(v, ch),
LPAIF_RDMACTL_ENABLE_MASK,
LPAIF_RDMACTL_ENABLE_OFF);
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
int ret, ch = pcm_data->rdma_ch;
ret = regmap_read(drvdata->lpaif_map,
LPAIF_RDMABASE_REG(v, ch), &base_addr);
if (ret) {
dev_err(soc_runtime->dev, "%s() error reading from rdmabase reg: %d\n",
__func__, ret);
return ret;
}
ret = regmap_read(drvdata->lpaif_map,
LPAIF_RDMACURR_REG(v, ch), &curr_addr);
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
static int lpass_platform_alloc_buffer(struct snd_pcm_substream *substream,
struct snd_soc_pcm_runtime *soc_runtime)
{
struct snd_dma_buffer *buf = &substream->dma_buffer;
size_t size = lpass_platform_pcm_hardware.buffer_bytes_max;
buf->dev.type = SNDRV_DMA_TYPE_DEV;
buf->dev.dev = soc_runtime->dev;
buf->private_data = NULL;
buf->area = dma_alloc_coherent(soc_runtime->dev, size, &buf->addr,
GFP_KERNEL);
if (!buf->area) {
dev_err(soc_runtime->dev, "%s: Could not allocate DMA buffer\n",
__func__);
return -ENOMEM;
}
buf->bytes = size;
return 0;
}
static void lpass_platform_free_buffer(struct snd_pcm_substream *substream,
struct snd_soc_pcm_runtime *soc_runtime)
{
struct snd_dma_buffer *buf = &substream->dma_buffer;
if (buf->area) {
dma_free_coherent(soc_runtime->dev, buf->bytes, buf->area,
buf->addr);
}
buf->area = NULL;
}
static int lpass_platform_pcm_new(struct snd_soc_pcm_runtime *soc_runtime)
{
struct snd_pcm *pcm = soc_runtime->pcm;
struct snd_pcm_substream *substream =
pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
struct snd_soc_dai *cpu_dai = soc_runtime->cpu_dai;
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_variant *v = drvdata->variant;
int ret;
struct lpass_pcm_data *data;
data = devm_kzalloc(soc_runtime->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (v->alloc_dma_channel)
data->rdma_ch = v->alloc_dma_channel(drvdata);
if (IS_ERR_VALUE(data->rdma_ch))
return data->rdma_ch;
drvdata->substream[data->rdma_ch] = substream;
data->i2s_port = cpu_dai->driver->id;
snd_soc_pcm_set_drvdata(soc_runtime, data);
soc_runtime->dev->coherent_dma_mask = DMA_BIT_MASK(32);
soc_runtime->dev->dma_mask = &soc_runtime->dev->coherent_dma_mask;
ret = lpass_platform_alloc_buffer(substream, soc_runtime);
if (ret)
return ret;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_RDMACTL_REG(v, data->rdma_ch), 0);
if (ret) {
dev_err(soc_runtime->dev, "%s() error writing to rdmactl reg: %d\n",
__func__, ret);
goto err_buf;
}
return 0;
err_buf:
lpass_platform_free_buffer(substream, soc_runtime);
return ret;
}
static void lpass_platform_pcm_free(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream =
pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream;
struct snd_soc_pcm_runtime *soc_runtime = substream->private_data;
struct lpass_data *drvdata =
snd_soc_platform_get_drvdata(soc_runtime->platform);
struct lpass_pcm_data *data = snd_soc_pcm_get_drvdata(soc_runtime);
struct lpass_variant *v = drvdata->variant;
drvdata->substream[data->rdma_ch] = NULL;
if (v->free_dma_channel)
v->free_dma_channel(drvdata, data->rdma_ch);
lpass_platform_free_buffer(substream, soc_runtime);
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
