static void stm32_spdifrx_dma_complete(void *data)
{
struct stm32_spdifrx_data *spdifrx = (struct stm32_spdifrx_data *)data;
struct platform_device *pdev = spdifrx->pdev;
u32 *p_start = (u32 *)spdifrx->dmab->area;
u32 *p_end = p_start + (2 * SPDIFRX_CS_BYTES_NB) - 1;
u32 *ptr = p_start;
u16 *ub_ptr = (short *)spdifrx->ub;
int i = 0;
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_CBDMAEN,
(unsigned int)~SPDIFRX_CR_CBDMAEN);
if (!spdifrx->dmab->area)
return;
while (ptr <= p_end) {
if (*ptr & SPDIFRX_CSR_SOB)
break;
ptr++;
}
if (ptr > p_end) {
dev_err(&pdev->dev, "Start of S/PDIF block not found\n");
return;
}
while (i < SPDIFRX_CS_BYTES_NB) {
spdifrx->cs[i] = (unsigned char)SPDIFRX_CSR_CSGET(*ptr);
*ub_ptr++ = SPDIFRX_CSR_USRGET(*ptr++);
if (ptr > p_end) {
dev_err(&pdev->dev, "Failed to get channel status\n");
return;
}
i++;
}
complete(&spdifrx->cs_completion);
}
static int stm32_spdifrx_dma_ctrl_start(struct stm32_spdifrx_data *spdifrx)
{
dma_cookie_t cookie;
int err;
spdifrx->desc = dmaengine_prep_slave_single(spdifrx->ctrl_chan,
spdifrx->dmab->addr,
SPDIFRX_CSR_BUF_LENGTH,
DMA_DEV_TO_MEM,
DMA_CTRL_ACK);
if (!spdifrx->desc)
return -EINVAL;
spdifrx->desc->callback = stm32_spdifrx_dma_complete;
spdifrx->desc->callback_param = spdifrx;
cookie = dmaengine_submit(spdifrx->desc);
err = dma_submit_error(cookie);
if (err)
return -EINVAL;
dma_async_issue_pending(spdifrx->ctrl_chan);
return 0;
}
static void stm32_spdifrx_dma_ctrl_stop(struct stm32_spdifrx_data *spdifrx)
{
dmaengine_terminate_async(spdifrx->ctrl_chan);
}
static int stm32_spdifrx_start_sync(struct stm32_spdifrx_data *spdifrx)
{
int cr, cr_mask, imr, ret;
imr = SPDIFRX_IMR_IFEIE | SPDIFRX_IMR_SYNCDIE | SPDIFRX_IMR_PERRIE;
ret = regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_IMR, imr, imr);
if (ret)
return ret;
spin_lock(&spdifrx->lock);
spdifrx->refcount++;
regmap_read(spdifrx->regmap, STM32_SPDIFRX_CR, &cr);
if (!(cr & SPDIFRX_CR_SPDIFEN_MASK)) {
dev_dbg(&spdifrx->pdev->dev, "start synchronization\n");
cr = SPDIFRX_CR_WFA | SPDIFRX_CR_PMSK | SPDIFRX_CR_VMSK |
SPDIFRX_CR_CUMSK | SPDIFRX_CR_PTMSK | SPDIFRX_CR_RXSTEO;
cr_mask = cr;
cr |= SPDIFRX_CR_SPDIFENSET(SPDIFRX_SPDIFEN_SYNC);
cr_mask |= SPDIFRX_CR_SPDIFEN_MASK;
ret = regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
cr_mask, cr);
if (ret < 0)
dev_err(&spdifrx->pdev->dev,
"Failed to start synchronization\n");
}
spin_unlock(&spdifrx->lock);
return ret;
}
static void stm32_spdifrx_stop(struct stm32_spdifrx_data *spdifrx)
{
int cr, cr_mask, reg;
spin_lock(&spdifrx->lock);
if (--spdifrx->refcount) {
spin_unlock(&spdifrx->lock);
return;
}
cr = SPDIFRX_CR_SPDIFENSET(SPDIFRX_SPDIFEN_DISABLE);
cr_mask = SPDIFRX_CR_SPDIFEN_MASK | SPDIFRX_CR_RXDMAEN;
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR, cr_mask, cr);
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_IMR,
SPDIFRX_XIMR_MASK, 0);
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_IFCR,
SPDIFRX_XIFCR_MASK, SPDIFRX_XIFCR_MASK);
regmap_read(spdifrx->regmap, STM32_SPDIFRX_DR, &reg);
regmap_read(spdifrx->regmap, STM32_SPDIFRX_CSR, &reg);
spin_unlock(&spdifrx->lock);
}
static int stm32_spdifrx_dma_ctrl_register(struct device *dev,
struct stm32_spdifrx_data *spdifrx)
{
int ret;
spdifrx->dmab = devm_kzalloc(dev, sizeof(struct snd_dma_buffer),
GFP_KERNEL);
if (!spdifrx->dmab)
return -ENOMEM;
spdifrx->dmab->dev.type = SNDRV_DMA_TYPE_DEV_IRAM;
spdifrx->dmab->dev.dev = dev;
ret = snd_dma_alloc_pages(spdifrx->dmab->dev.type, dev,
SPDIFRX_CSR_BUF_LENGTH, spdifrx->dmab);
if (ret < 0) {
dev_err(dev, "snd_dma_alloc_pages returned error %d\n", ret);
return ret;
}
spdifrx->ctrl_chan = dma_request_chan(dev, "rx-ctrl");
if (!spdifrx->ctrl_chan) {
dev_err(dev, "dma_request_slave_channel failed\n");
return -EINVAL;
}
spdifrx->slave_config.direction = DMA_DEV_TO_MEM;
spdifrx->slave_config.src_addr = (dma_addr_t)(spdifrx->phys_addr +
STM32_SPDIFRX_CSR);
spdifrx->slave_config.dst_addr = spdifrx->dmab->addr;
spdifrx->slave_config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
spdifrx->slave_config.src_maxburst = 1;
ret = dmaengine_slave_config(spdifrx->ctrl_chan,
&spdifrx->slave_config);
if (ret < 0) {
dev_err(dev, "dmaengine_slave_config returned error %d\n", ret);
dma_release_channel(spdifrx->ctrl_chan);
spdifrx->ctrl_chan = NULL;
}
return ret;
}
static int stm32_spdifrx_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int stm32_spdifrx_ub_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_IEC958;
uinfo->count = 1;
return 0;
}
static int stm32_spdifrx_get_ctrl_data(struct stm32_spdifrx_data *spdifrx)
{
int ret = 0;
memset(spdifrx->cs, 0, SPDIFRX_CS_BYTES_NB);
memset(spdifrx->ub, 0, SPDIFRX_UB_BYTES_NB);
ret = stm32_spdifrx_dma_ctrl_start(spdifrx);
if (ret < 0)
return ret;
ret = clk_prepare_enable(spdifrx->kclk);
if (ret) {
dev_err(&spdifrx->pdev->dev, "Enable kclk failed: %d\n", ret);
return ret;
}
ret = regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_CBDMAEN, SPDIFRX_CR_CBDMAEN);
if (ret < 0)
goto end;
ret = stm32_spdifrx_start_sync(spdifrx);
if (ret < 0)
goto end;
if (wait_for_completion_interruptible_timeout(&spdifrx->cs_completion,
msecs_to_jiffies(100))
<= 0) {
dev_err(&spdifrx->pdev->dev, "Failed to get control data\n");
ret = -EAGAIN;
}
stm32_spdifrx_stop(spdifrx);
stm32_spdifrx_dma_ctrl_stop(spdifrx);
end:
clk_disable_unprepare(spdifrx->kclk);
return ret;
}
static int stm32_spdifrx_capture_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
stm32_spdifrx_get_ctrl_data(spdifrx);
ucontrol->value.iec958.status[0] = spdifrx->cs[0];
ucontrol->value.iec958.status[1] = spdifrx->cs[1];
ucontrol->value.iec958.status[2] = spdifrx->cs[2];
ucontrol->value.iec958.status[3] = spdifrx->cs[3];
ucontrol->value.iec958.status[4] = spdifrx->cs[4];
return 0;
}
static int stm32_spdif_user_bits_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dai *cpu_dai = snd_kcontrol_chip(kcontrol);
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
stm32_spdifrx_get_ctrl_data(spdifrx);
ucontrol->value.iec958.status[0] = spdifrx->ub[0];
ucontrol->value.iec958.status[1] = spdifrx->ub[1];
ucontrol->value.iec958.status[2] = spdifrx->ub[2];
ucontrol->value.iec958.status[3] = spdifrx->ub[3];
ucontrol->value.iec958.status[4] = spdifrx->ub[4];
return 0;
}
static int stm32_spdifrx_dai_register_ctrls(struct snd_soc_dai *cpu_dai)
{
int ret;
ret = snd_soc_add_dai_controls(cpu_dai, stm32_spdifrx_iec_ctrls,
ARRAY_SIZE(stm32_spdifrx_iec_ctrls));
if (ret < 0)
return ret;
return snd_soc_add_component_controls(cpu_dai->component,
stm32_spdifrx_ctrls,
ARRAY_SIZE(stm32_spdifrx_ctrls));
}
static int stm32_spdifrx_dai_probe(struct snd_soc_dai *cpu_dai)
{
struct stm32_spdifrx_data *spdifrx = dev_get_drvdata(cpu_dai->dev);
spdifrx->dma_params.addr = (dma_addr_t)(spdifrx->phys_addr +
STM32_SPDIFRX_DR);
spdifrx->dma_params.maxburst = 1;
snd_soc_dai_init_dma_data(cpu_dai, NULL, &spdifrx->dma_params);
return stm32_spdifrx_dai_register_ctrls(cpu_dai);
}
static bool stm32_spdifrx_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM32_SPDIFRX_CR:
case STM32_SPDIFRX_IMR:
case STM32_SPDIFRX_SR:
case STM32_SPDIFRX_IFCR:
case STM32_SPDIFRX_DR:
case STM32_SPDIFRX_CSR:
case STM32_SPDIFRX_DIR:
return true;
default:
return false;
}
}
static bool stm32_spdifrx_volatile_reg(struct device *dev, unsigned int reg)
{
if (reg == STM32_SPDIFRX_DR)
return true;
return false;
}
static bool stm32_spdifrx_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM32_SPDIFRX_CR:
case STM32_SPDIFRX_IMR:
case STM32_SPDIFRX_IFCR:
return true;
default:
return false;
}
}
static irqreturn_t stm32_spdifrx_isr(int irq, void *devid)
{
struct stm32_spdifrx_data *spdifrx = (struct stm32_spdifrx_data *)devid;
struct snd_pcm_substream *substream = spdifrx->substream;
struct platform_device *pdev = spdifrx->pdev;
unsigned int cr, mask, sr, imr;
unsigned int flags;
int err = 0, err_xrun = 0;
regmap_read(spdifrx->regmap, STM32_SPDIFRX_SR, &sr);
regmap_read(spdifrx->regmap, STM32_SPDIFRX_IMR, &imr);
mask = imr & SPDIFRX_XIMR_MASK;
if (mask & SPDIFRX_IMR_IFEIE)
mask |= (SPDIFRX_IMR_IFEIE << 1) | (SPDIFRX_IMR_IFEIE << 2);
flags = sr & mask;
if (!flags) {
dev_err(&pdev->dev, "Unexpected IRQ. rflags=%#x, imr=%#x\n",
sr, imr);
return IRQ_NONE;
}
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_IFCR,
SPDIFRX_XIFCR_MASK, flags);
if (flags & SPDIFRX_SR_PERR) {
dev_dbg(&pdev->dev, "Parity error\n");
err_xrun = 1;
}
if (flags & SPDIFRX_SR_OVR) {
dev_dbg(&pdev->dev, "Overrun error\n");
err_xrun = 1;
}
if (flags & SPDIFRX_SR_SBD)
dev_dbg(&pdev->dev, "Synchronization block detected\n");
if (flags & SPDIFRX_SR_SYNCD) {
dev_dbg(&pdev->dev, "Synchronization done\n");
cr = SPDIFRX_CR_SPDIFENSET(SPDIFRX_SPDIFEN_ENABLE);
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_SPDIFEN_MASK, cr);
}
if (flags & SPDIFRX_SR_FERR) {
dev_dbg(&pdev->dev, "Frame error\n");
err = 1;
}
if (flags & SPDIFRX_SR_SERR) {
dev_dbg(&pdev->dev, "Synchronization error\n");
err = 1;
}
if (flags & SPDIFRX_SR_TERR) {
dev_dbg(&pdev->dev, "Timeout error\n");
err = 1;
}
if (err) {
cr = SPDIFRX_CR_SPDIFENSET(SPDIFRX_SPDIFEN_DISABLE);
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_SPDIFEN_MASK, cr);
if (substream)
snd_pcm_stop(substream, SNDRV_PCM_STATE_DISCONNECTED);
return IRQ_HANDLED;
}
if (err_xrun && substream)
snd_pcm_stop_xrun(substream);
return IRQ_HANDLED;
}
static int stm32_spdifrx_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
int ret;
spdifrx->substream = substream;
ret = clk_prepare_enable(spdifrx->kclk);
if (ret)
dev_err(&spdifrx->pdev->dev, "Enable kclk failed: %d\n", ret);
return ret;
}
static int stm32_spdifrx_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
int data_size = params_width(params);
int fmt;
switch (data_size) {
case 16:
fmt = SPDIFRX_DRFMT_PACKED;
spdifrx->dma_params.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
break;
case 32:
fmt = SPDIFRX_DRFMT_LEFT;
spdifrx->dma_params.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
break;
default:
dev_err(&spdifrx->pdev->dev, "Unexpected data format\n");
return -EINVAL;
}
snd_soc_dai_init_dma_data(cpu_dai, NULL, &spdifrx->dma_params);
return regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_DRFMT_MASK,
SPDIFRX_CR_DRFMTSET(fmt));
}
static int stm32_spdifrx_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
int ret = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_IMR,
SPDIFRX_IMR_OVRIE, SPDIFRX_IMR_OVRIE);
regmap_update_bits(spdifrx->regmap, STM32_SPDIFRX_CR,
SPDIFRX_CR_RXDMAEN, SPDIFRX_CR_RXDMAEN);
ret = stm32_spdifrx_start_sync(spdifrx);
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_STOP:
stm32_spdifrx_stop(spdifrx);
break;
default:
return -EINVAL;
}
return ret;
}
static void stm32_spdifrx_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_spdifrx_data *spdifrx = snd_soc_dai_get_drvdata(cpu_dai);
spdifrx->substream = NULL;
clk_disable_unprepare(spdifrx->kclk);
}
static int stm_spdifrx_parse_of(struct platform_device *pdev,
struct stm32_spdifrx_data *spdifrx)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *of_id;
struct resource *res;
if (!np)
return -ENODEV;
of_id = of_match_device(stm32_spdifrx_ids, &pdev->dev);
if (of_id)
spdifrx->regmap_conf =
(const struct regmap_config *)of_id->data;
else
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
spdifrx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(spdifrx->base))
return PTR_ERR(spdifrx->base);
spdifrx->phys_addr = res->start;
spdifrx->kclk = devm_clk_get(&pdev->dev, "kclk");
if (IS_ERR(spdifrx->kclk)) {
dev_err(&pdev->dev, "Could not get kclk\n");
return PTR_ERR(spdifrx->kclk);
}
spdifrx->irq = platform_get_irq(pdev, 0);
if (spdifrx->irq < 0) {
dev_err(&pdev->dev, "No irq for node %s\n", pdev->name);
return spdifrx->irq;
}
return 0;
}
static int stm32_spdifrx_probe(struct platform_device *pdev)
{
struct stm32_spdifrx_data *spdifrx;
struct reset_control *rst;
const struct snd_dmaengine_pcm_config *pcm_config = NULL;
int ret;
spdifrx = devm_kzalloc(&pdev->dev, sizeof(*spdifrx), GFP_KERNEL);
if (!spdifrx)
return -ENOMEM;
spdifrx->pdev = pdev;
init_completion(&spdifrx->cs_completion);
spin_lock_init(&spdifrx->lock);
platform_set_drvdata(pdev, spdifrx);
ret = stm_spdifrx_parse_of(pdev, spdifrx);
if (ret)
return ret;
spdifrx->regmap = devm_regmap_init_mmio_clk(&pdev->dev, "kclk",
spdifrx->base,
spdifrx->regmap_conf);
if (IS_ERR(spdifrx->regmap)) {
dev_err(&pdev->dev, "Regmap init failed\n");
return PTR_ERR(spdifrx->regmap);
}
ret = devm_request_irq(&pdev->dev, spdifrx->irq, stm32_spdifrx_isr, 0,
dev_name(&pdev->dev), spdifrx);
if (ret) {
dev_err(&pdev->dev, "IRQ request returned %d\n", ret);
return ret;
}
rst = devm_reset_control_get_exclusive(&pdev->dev, NULL);
if (!IS_ERR(rst)) {
reset_control_assert(rst);
udelay(2);
reset_control_deassert(rst);
}
ret = devm_snd_soc_register_component(&pdev->dev,
&stm32_spdifrx_component,
stm32_spdifrx_dai,
ARRAY_SIZE(stm32_spdifrx_dai));
if (ret)
return ret;
ret = stm32_spdifrx_dma_ctrl_register(&pdev->dev, spdifrx);
if (ret)
goto error;
pcm_config = &stm32_spdifrx_pcm_config;
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, pcm_config, 0);
if (ret) {
dev_err(&pdev->dev, "PCM DMA register returned %d\n", ret);
goto error;
}
return 0;
error:
if (spdifrx->ctrl_chan)
dma_release_channel(spdifrx->ctrl_chan);
if (spdifrx->dmab)
snd_dma_free_pages(spdifrx->dmab);
return ret;
}
static int stm32_spdifrx_remove(struct platform_device *pdev)
{
struct stm32_spdifrx_data *spdifrx = platform_get_drvdata(pdev);
if (spdifrx->ctrl_chan)
dma_release_channel(spdifrx->ctrl_chan);
if (spdifrx->dmab)
snd_dma_free_pages(spdifrx->dmab);
return 0;
}
