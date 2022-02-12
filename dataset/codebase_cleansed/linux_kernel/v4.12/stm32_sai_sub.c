static bool stm32_sai_sub_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM_SAI_CR1_REGX:
case STM_SAI_CR2_REGX:
case STM_SAI_FRCR_REGX:
case STM_SAI_SLOTR_REGX:
case STM_SAI_IMR_REGX:
case STM_SAI_SR_REGX:
case STM_SAI_CLRFR_REGX:
case STM_SAI_DR_REGX:
return true;
default:
return false;
}
}
static bool stm32_sai_sub_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM_SAI_DR_REGX:
return true;
default:
return false;
}
}
static bool stm32_sai_sub_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case STM_SAI_CR1_REGX:
case STM_SAI_CR2_REGX:
case STM_SAI_FRCR_REGX:
case STM_SAI_SLOTR_REGX:
case STM_SAI_IMR_REGX:
case STM_SAI_SR_REGX:
case STM_SAI_CLRFR_REGX:
case STM_SAI_DR_REGX:
return true;
default:
return false;
}
}
static irqreturn_t stm32_sai_isr(int irq, void *devid)
{
struct stm32_sai_sub_data *sai = (struct stm32_sai_sub_data *)devid;
struct snd_pcm_substream *substream = sai->substream;
struct platform_device *pdev = sai->pdev;
unsigned int sr, imr, flags;
snd_pcm_state_t status = SNDRV_PCM_STATE_RUNNING;
regmap_read(sai->regmap, STM_SAI_IMR_REGX, &imr);
regmap_read(sai->regmap, STM_SAI_SR_REGX, &sr);
flags = sr & imr;
if (!flags)
return IRQ_NONE;
regmap_update_bits(sai->regmap, STM_SAI_CLRFR_REGX, SAI_XCLRFR_MASK,
SAI_XCLRFR_MASK);
if (flags & SAI_XIMR_OVRUDRIE) {
dev_err(&pdev->dev, "IT %s\n",
STM_SAI_IS_PLAYBACK(sai) ? "underrun" : "overrun");
status = SNDRV_PCM_STATE_XRUN;
}
if (flags & SAI_XIMR_MUTEDETIE)
dev_dbg(&pdev->dev, "IT mute detected\n");
if (flags & SAI_XIMR_WCKCFGIE) {
dev_err(&pdev->dev, "IT wrong clock configuration\n");
status = SNDRV_PCM_STATE_DISCONNECTED;
}
if (flags & SAI_XIMR_CNRDYIE)
dev_warn(&pdev->dev, "IT Codec not ready\n");
if (flags & SAI_XIMR_AFSDETIE) {
dev_warn(&pdev->dev, "IT Anticipated frame synchro\n");
status = SNDRV_PCM_STATE_XRUN;
}
if (flags & SAI_XIMR_LFSDETIE) {
dev_warn(&pdev->dev, "IT Late frame synchro\n");
status = SNDRV_PCM_STATE_XRUN;
}
if (status != SNDRV_PCM_STATE_RUNNING) {
snd_pcm_stream_lock(substream);
snd_pcm_stop(substream, SNDRV_PCM_STATE_XRUN);
snd_pcm_stream_unlock(substream);
}
return IRQ_HANDLED;
}
static int stm32_sai_set_sysclk(struct snd_soc_dai *cpu_dai,
int clk_id, unsigned int freq, int dir)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
if ((dir == SND_SOC_CLOCK_OUT) && sai->master) {
sai->mclk_rate = freq;
dev_dbg(cpu_dai->dev, "SAI MCLK frequency is %uHz\n", freq);
}
return 0;
}
static int stm32_sai_set_dai_tdm_slot(struct snd_soc_dai *cpu_dai, u32 tx_mask,
u32 rx_mask, int slots, int slot_width)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int slotr, slotr_mask, slot_size;
dev_dbg(cpu_dai->dev, "masks tx/rx:%#x/%#x, slots:%d, width:%d\n",
tx_mask, rx_mask, slots, slot_width);
switch (slot_width) {
case 16:
slot_size = SAI_SLOT_SIZE_16;
break;
case 32:
slot_size = SAI_SLOT_SIZE_32;
break;
default:
slot_size = SAI_SLOT_SIZE_AUTO;
break;
}
slotr = SAI_XSLOTR_SLOTSZ_SET(slot_size) |
SAI_XSLOTR_NBSLOT_SET(slots - 1);
slotr_mask = SAI_XSLOTR_SLOTSZ_MASK | SAI_XSLOTR_NBSLOT_MASK;
if (STM_SAI_IS_PLAYBACK(sai)) {
sai->slot_mask = tx_mask;
slotr |= SAI_XSLOTR_SLOTEN_SET(tx_mask);
}
if (STM_SAI_IS_CAPTURE(sai)) {
sai->slot_mask = rx_mask;
slotr |= SAI_XSLOTR_SLOTEN_SET(rx_mask);
}
slotr_mask |= SAI_XSLOTR_SLOTEN_MASK;
regmap_update_bits(sai->regmap, STM_SAI_SLOTR_REGX, slotr_mask, slotr);
sai->slot_width = slot_width;
sai->slots = slots;
return 0;
}
static int stm32_sai_set_dai_fmt(struct snd_soc_dai *cpu_dai, unsigned int fmt)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int cr1 = 0, frcr = 0;
int cr1_mask = 0, frcr_mask = 0;
int ret;
dev_dbg(cpu_dai->dev, "fmt %x\n", fmt);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
cr1 |= SAI_XCR1_CKSTR;
frcr |= SAI_XFRCR_FSOFF | SAI_XFRCR_FSDEF;
break;
case SND_SOC_DAIFMT_MSB:
frcr |= SAI_XFRCR_FSPOL | SAI_XFRCR_FSDEF;
break;
case SND_SOC_DAIFMT_LSB:
frcr |= SAI_XFRCR_FSPOL | SAI_XFRCR_FSDEF;
break;
case SND_SOC_DAIFMT_DSP_A:
frcr |= SAI_XFRCR_FSPOL | SAI_XFRCR_FSOFF;
break;
case SND_SOC_DAIFMT_DSP_B:
frcr |= SAI_XFRCR_FSPOL;
break;
default:
dev_err(cpu_dai->dev, "Unsupported protocol %#x\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
cr1_mask |= SAI_XCR1_PRTCFG_MASK | SAI_XCR1_CKSTR;
frcr_mask |= SAI_XFRCR_FSPOL | SAI_XFRCR_FSOFF |
SAI_XFRCR_FSDEF;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_NF:
cr1 ^= SAI_XCR1_CKSTR;
break;
case SND_SOC_DAIFMT_NB_IF:
frcr ^= SAI_XFRCR_FSPOL;
break;
case SND_SOC_DAIFMT_IB_IF:
cr1 ^= SAI_XCR1_CKSTR;
frcr ^= SAI_XFRCR_FSPOL;
break;
default:
dev_err(cpu_dai->dev, "Unsupported strobing %#x\n",
fmt & SND_SOC_DAIFMT_INV_MASK);
return -EINVAL;
}
cr1_mask |= SAI_XCR1_CKSTR;
frcr_mask |= SAI_XFRCR_FSPOL;
regmap_update_bits(sai->regmap, STM_SAI_FRCR_REGX, frcr_mask, frcr);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
cr1 |= SAI_XCR1_SLAVE;
sai->master = false;
break;
case SND_SOC_DAIFMT_CBS_CFS:
sai->master = true;
break;
default:
dev_err(cpu_dai->dev, "Unsupported mode %#x\n",
fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
cr1_mask |= SAI_XCR1_SLAVE;
ret = regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX, cr1_mask, cr1);
if (ret < 0) {
dev_err(cpu_dai->dev, "Failed to update CR1 register\n");
return ret;
}
sai->fmt = fmt;
return 0;
}
static int stm32_sai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int imr, cr2, ret;
sai->substream = substream;
ret = clk_prepare_enable(sai->sai_ck);
if (ret < 0) {
dev_err(cpu_dai->dev, "failed to enable clock: %d\n", ret);
return ret;
}
regmap_update_bits(sai->regmap, STM_SAI_SR_REGX,
SAI_XSR_MASK, (unsigned int)~SAI_XSR_MASK);
regmap_update_bits(sai->regmap, STM_SAI_CLRFR_REGX,
SAI_XCLRFR_MASK, SAI_XCLRFR_MASK);
imr = SAI_XIMR_OVRUDRIE;
if (STM_SAI_IS_CAPTURE(sai)) {
regmap_read(sai->regmap, STM_SAI_CR2_REGX, &cr2);
if (cr2 & SAI_XCR2_MUTECNT_MASK)
imr |= SAI_XIMR_MUTEDETIE;
}
if (sai->master)
imr |= SAI_XIMR_WCKCFGIE;
else
imr |= SAI_XIMR_AFSDETIE | SAI_XIMR_LFSDETIE;
regmap_update_bits(sai->regmap, STM_SAI_IMR_REGX,
SAI_XIMR_MASK, imr);
return 0;
}
static int stm32_sai_set_config(struct snd_soc_dai *cpu_dai,
struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int cr1, cr1_mask, ret;
int fth = STM_SAI_FIFO_TH_HALF;
regmap_update_bits(sai->regmap, STM_SAI_CR2_REGX,
SAI_XCR2_FFLUSH | SAI_XCR2_FTH_MASK,
SAI_XCR2_FFLUSH | SAI_XCR2_FTH_SET(fth));
cr1 = SAI_XCR1_PRTCFG_SET(SAI_FREE_PROTOCOL);
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S8:
cr1 |= SAI_XCR1_DS_SET(SAI_DATASIZE_8);
break;
case SNDRV_PCM_FORMAT_S16_LE:
cr1 |= SAI_XCR1_DS_SET(SAI_DATASIZE_16);
break;
case SNDRV_PCM_FORMAT_S32_LE:
cr1 |= SAI_XCR1_DS_SET(SAI_DATASIZE_32);
break;
default:
dev_err(cpu_dai->dev, "Data format not supported");
return -EINVAL;
}
cr1_mask = SAI_XCR1_DS_MASK | SAI_XCR1_PRTCFG_MASK;
cr1_mask |= SAI_XCR1_RX_TX;
if (STM_SAI_IS_CAPTURE(sai))
cr1 |= SAI_XCR1_RX_TX;
cr1_mask |= SAI_XCR1_MONO;
if ((sai->slots == 2) && (params_channels(params) == 1))
cr1 |= SAI_XCR1_MONO;
ret = regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX, cr1_mask, cr1);
if (ret < 0) {
dev_err(cpu_dai->dev, "Failed to update CR1 register\n");
return ret;
}
sai->dma_params.maxburst = STM_SAI_FIFO_SIZE * fth / sizeof(u32);
snd_soc_dai_set_dma_data(cpu_dai, substream, (void *)&sai->dma_params);
return 0;
}
static int stm32_sai_set_slots(struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int slotr, slot_sz;
regmap_read(sai->regmap, STM_SAI_SLOTR_REGX, &slotr);
slot_sz = slotr & SAI_XSLOTR_SLOTSZ_MASK;
if (slot_sz == SAI_XSLOTR_SLOTSZ_SET(SAI_SLOT_SIZE_AUTO))
sai->slot_width = sai->data_size;
if (sai->slot_width < sai->data_size) {
dev_err(cpu_dai->dev,
"Data size %d larger than slot width\n",
sai->data_size);
return -EINVAL;
}
if (!sai->slots)
sai->slots = 2;
regmap_update_bits(sai->regmap, STM_SAI_SLOTR_REGX,
SAI_XSLOTR_NBSLOT_MASK,
SAI_XSLOTR_NBSLOT_SET((sai->slots - 1)));
if (!(slotr & SAI_XSLOTR_SLOTEN_MASK)) {
sai->slot_mask = (1 << sai->slots) - 1;
regmap_update_bits(sai->regmap,
STM_SAI_SLOTR_REGX, SAI_XSLOTR_SLOTEN_MASK,
SAI_XSLOTR_SLOTEN_SET(sai->slot_mask));
}
dev_dbg(cpu_dai->dev, "slots %d, slot width %d\n",
sai->slots, sai->slot_width);
return 0;
}
static void stm32_sai_set_frame(struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int fs_active, offset, format;
int frcr, frcr_mask;
format = sai->fmt & SND_SOC_DAIFMT_FORMAT_MASK;
sai->fs_length = sai->slot_width * sai->slots;
fs_active = sai->fs_length / 2;
if ((format == SND_SOC_DAIFMT_DSP_A) ||
(format == SND_SOC_DAIFMT_DSP_B))
fs_active = 1;
frcr = SAI_XFRCR_FRL_SET((sai->fs_length - 1));
frcr |= SAI_XFRCR_FSALL_SET((fs_active - 1));
frcr_mask = SAI_XFRCR_FRL_MASK | SAI_XFRCR_FSALL_MASK;
dev_dbg(cpu_dai->dev, "frame length %d, frame active %d\n",
sai->fs_length, fs_active);
regmap_update_bits(sai->regmap, STM_SAI_FRCR_REGX, frcr_mask, frcr);
if ((sai->fmt & SND_SOC_DAIFMT_FORMAT_MASK) == SND_SOC_DAIFMT_LSB) {
offset = sai->slot_width - sai->data_size;
regmap_update_bits(sai->regmap, STM_SAI_SLOTR_REGX,
SAI_XSLOTR_FBOFF_MASK,
SAI_XSLOTR_FBOFF_SET(offset));
}
}
static int stm32_sai_configure_clock(struct snd_soc_dai *cpu_dai,
struct snd_pcm_hw_params *params)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int cr1, mask, div = 0;
int sai_clk_rate, ret;
if (!sai->mclk_rate) {
dev_err(cpu_dai->dev, "Mclk rate is null\n");
return -EINVAL;
}
if (!(params_rate(params) % 11025))
clk_set_parent(sai->sai_ck, sai->pdata->clk_x11k);
else
clk_set_parent(sai->sai_ck, sai->pdata->clk_x8k);
sai_clk_rate = clk_get_rate(sai->sai_ck);
if (2 * sai_clk_rate >= 3 * sai->mclk_rate)
div = DIV_ROUND_CLOSEST(sai_clk_rate, 2 * sai->mclk_rate);
if (div > SAI_XCR1_MCKDIV_MAX) {
dev_err(cpu_dai->dev, "Divider %d out of range\n", div);
return -EINVAL;
}
dev_dbg(cpu_dai->dev, "SAI clock %d, divider %d\n", sai_clk_rate, div);
mask = SAI_XCR1_MCKDIV_MASK;
cr1 = SAI_XCR1_MCKDIV_SET(div);
ret = regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX, mask, cr1);
if (ret < 0) {
dev_err(cpu_dai->dev, "Failed to update CR1 register\n");
return ret;
}
return 0;
}
static int stm32_sai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int ret;
sai->data_size = params_width(params);
ret = stm32_sai_set_slots(cpu_dai);
if (ret < 0)
return ret;
stm32_sai_set_frame(cpu_dai);
ret = stm32_sai_set_config(cpu_dai, substream, params);
if (ret)
return ret;
if (sai->master)
ret = stm32_sai_configure_clock(cpu_dai, params);
return ret;
}
static int stm32_sai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
int ret;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
dev_dbg(cpu_dai->dev, "Enable DMA and SAI\n");
regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX,
SAI_XCR1_DMAEN, SAI_XCR1_DMAEN);
ret = regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX,
SAI_XCR1_SAIEN, SAI_XCR1_SAIEN);
if (ret < 0)
dev_err(cpu_dai->dev, "Failed to update CR1 register\n");
break;
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_STOP:
dev_dbg(cpu_dai->dev, "Disable DMA and SAI\n");
regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX,
SAI_XCR1_DMAEN,
(unsigned int)~SAI_XCR1_DMAEN);
ret = regmap_update_bits(sai->regmap, STM_SAI_CR1_REGX,
SAI_XCR1_SAIEN,
(unsigned int)~SAI_XCR1_SAIEN);
if (ret < 0)
dev_err(cpu_dai->dev, "Failed to update CR1 register\n");
break;
default:
return -EINVAL;
}
return ret;
}
static void stm32_sai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = snd_soc_dai_get_drvdata(cpu_dai);
regmap_update_bits(sai->regmap, STM_SAI_IMR_REGX, SAI_XIMR_MASK, 0);
clk_disable_unprepare(sai->sai_ck);
sai->substream = NULL;
}
static int stm32_sai_dai_probe(struct snd_soc_dai *cpu_dai)
{
struct stm32_sai_sub_data *sai = dev_get_drvdata(cpu_dai->dev);
sai->dma_params.addr = (dma_addr_t)(sai->phys_addr + STM_SAI_DR_REGX);
sai->dma_params.maxburst = 1;
sai->dma_params.addr_width = DMA_SLAVE_BUSWIDTH_UNDEFINED;
if (STM_SAI_IS_PLAYBACK(sai))
snd_soc_dai_init_dma_data(cpu_dai, &sai->dma_params, NULL);
else
snd_soc_dai_init_dma_data(cpu_dai, NULL, &sai->dma_params);
return 0;
}
static int stm32_sai_sub_parse_of(struct platform_device *pdev,
struct stm32_sai_sub_data *sai)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res;
void __iomem *base;
if (!np)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev_err(&pdev->dev, "res %pr\n", res);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
sai->phys_addr = res->start;
sai->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&stm32_sai_sub_regmap_config);
if (of_property_match_string(np, "dma-names", "tx") >= 0) {
sai->dir = SNDRV_PCM_STREAM_PLAYBACK;
} else if (of_property_match_string(np, "dma-names", "rx") >= 0) {
sai->dir = SNDRV_PCM_STREAM_CAPTURE;
} else {
dev_err(&pdev->dev, "Unsupported direction\n");
return -EINVAL;
}
sai->sai_ck = devm_clk_get(&pdev->dev, "sai_ck");
if (IS_ERR(sai->sai_ck)) {
dev_err(&pdev->dev, "missing kernel clock sai_ck\n");
return PTR_ERR(sai->sai_ck);
}
return 0;
}
static int stm32_sai_sub_dais_init(struct platform_device *pdev,
struct stm32_sai_sub_data *sai)
{
sai->cpu_dai_drv = devm_kzalloc(&pdev->dev,
sizeof(struct snd_soc_dai_driver),
GFP_KERNEL);
if (!sai->cpu_dai_drv)
return -ENOMEM;
sai->cpu_dai_drv->name = dev_name(&pdev->dev);
if (STM_SAI_IS_PLAYBACK(sai)) {
memcpy(sai->cpu_dai_drv, &stm32_sai_playback_dai,
sizeof(stm32_sai_playback_dai));
sai->cpu_dai_drv->playback.stream_name = sai->cpu_dai_drv->name;
} else {
memcpy(sai->cpu_dai_drv, &stm32_sai_capture_dai,
sizeof(stm32_sai_capture_dai));
sai->cpu_dai_drv->capture.stream_name = sai->cpu_dai_drv->name;
}
return 0;
}
static int stm32_sai_sub_probe(struct platform_device *pdev)
{
struct stm32_sai_sub_data *sai;
const struct of_device_id *of_id;
int ret;
sai = devm_kzalloc(&pdev->dev, sizeof(*sai), GFP_KERNEL);
if (!sai)
return -ENOMEM;
of_id = of_match_device(stm32_sai_sub_ids, &pdev->dev);
if (!of_id)
return -EINVAL;
sai->id = (uintptr_t)of_id->data;
sai->pdev = pdev;
platform_set_drvdata(pdev, sai);
sai->pdata = dev_get_drvdata(pdev->dev.parent);
if (!sai->pdata) {
dev_err(&pdev->dev, "Parent device data not available\n");
return -EINVAL;
}
ret = stm32_sai_sub_parse_of(pdev, sai);
if (ret)
return ret;
ret = stm32_sai_sub_dais_init(pdev, sai);
if (ret)
return ret;
ret = devm_request_irq(&pdev->dev, sai->pdata->irq, stm32_sai_isr,
IRQF_SHARED, dev_name(&pdev->dev), sai);
if (ret) {
dev_err(&pdev->dev, "irq request returned %d\n", ret);
return ret;
}
ret = devm_snd_soc_register_component(&pdev->dev, &stm32_component,
sai->cpu_dai_drv, 1);
if (ret)
return ret;
ret = devm_snd_dmaengine_pcm_register(&pdev->dev,
&stm32_sai_pcm_config, 0);
if (ret) {
dev_err(&pdev->dev, "could not register pcm dma\n");
return ret;
}
return 0;
}
