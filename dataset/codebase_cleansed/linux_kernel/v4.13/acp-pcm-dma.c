static u32 acp_reg_read(void __iomem *acp_mmio, u32 reg)
{
return readl(acp_mmio + (reg * 4));
}
static void acp_reg_write(u32 val, void __iomem *acp_mmio, u32 reg)
{
writel(val, acp_mmio + (reg * 4));
}
static void config_acp_dma_channel(void __iomem *acp_mmio, u8 ch_num,
u16 dscr_strt_idx, u16 num_dscrs,
enum acp_dma_priority_level priority_level)
{
u32 dma_ctrl;
dma_ctrl = acp_reg_read(acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
dma_ctrl &= ~ACP_DMA_CNTL_0__DMAChRun_MASK;
acp_reg_write(dma_ctrl, acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
acp_reg_write((ACP_DMA_DSCR_STRT_IDX_0__DMAChDscrStrtIdx_MASK
& dscr_strt_idx),
acp_mmio, mmACP_DMA_DSCR_STRT_IDX_0 + ch_num);
acp_reg_write(ACP_DMA_DSCR_CNT_0__DMAChDscrCnt_MASK & num_dscrs,
acp_mmio, mmACP_DMA_DSCR_CNT_0 + ch_num);
acp_reg_write(priority_level, acp_mmio, mmACP_DMA_PRIO_0 + ch_num);
}
static void config_dma_descriptor_in_sram(void __iomem *acp_mmio,
u16 descr_idx,
acp_dma_dscr_transfer_t *descr_info)
{
u32 sram_offset;
sram_offset = (descr_idx * sizeof(acp_dma_dscr_transfer_t));
acp_reg_write(sram_offset, acp_mmio, mmACP_SRBM_Targ_Idx_Addr);
acp_reg_write(descr_info->src, acp_mmio, mmACP_SRBM_Targ_Idx_Data);
acp_reg_write(sram_offset + 4, acp_mmio, mmACP_SRBM_Targ_Idx_Addr);
acp_reg_write(descr_info->dest, acp_mmio, mmACP_SRBM_Targ_Idx_Data);
acp_reg_write(sram_offset + 8, acp_mmio, mmACP_SRBM_Targ_Idx_Addr);
acp_reg_write(descr_info->xfer_val, acp_mmio, mmACP_SRBM_Targ_Idx_Data);
}
static void set_acp_sysmem_dma_descriptors(void __iomem *acp_mmio,
u32 size, int direction,
u32 pte_offset)
{
u16 i;
u16 dma_dscr_idx = PLAYBACK_START_DMA_DESCR_CH12;
acp_dma_dscr_transfer_t dmadscr[NUM_DSCRS_PER_CHANNEL];
for (i = 0; i < NUM_DSCRS_PER_CHANNEL; i++) {
dmadscr[i].xfer_val = 0;
if (direction == SNDRV_PCM_STREAM_PLAYBACK) {
dma_dscr_idx = PLAYBACK_START_DMA_DESCR_CH12 + i;
dmadscr[i].dest = ACP_SHARED_RAM_BANK_1_ADDRESS +
(size / 2) - (i * (size/2));
dmadscr[i].src = ACP_INTERNAL_APERTURE_WINDOW_0_ADDRESS
+ (pte_offset * SZ_4K) + (i * (size/2));
dmadscr[i].xfer_val |=
(ACP_DMA_ATTRIBUTES_DAGB_ONION_TO_SHAREDMEM << 16) |
(size / 2);
} else {
dma_dscr_idx = CAPTURE_START_DMA_DESCR_CH14 + i;
dmadscr[i].src = ACP_SHARED_RAM_BANK_5_ADDRESS +
(i * (size/2));
dmadscr[i].dest = ACP_INTERNAL_APERTURE_WINDOW_0_ADDRESS
+ (pte_offset * SZ_4K) +
(i * (size/2));
dmadscr[i].xfer_val |=
BIT(22) |
(ACP_DMA_ATTRIBUTES_SHAREDMEM_TO_DAGB_ONION << 16) |
(size / 2);
}
config_dma_descriptor_in_sram(acp_mmio, dma_dscr_idx,
&dmadscr[i]);
}
if (direction == SNDRV_PCM_STREAM_PLAYBACK)
config_acp_dma_channel(acp_mmio, SYSRAM_TO_ACP_CH_NUM,
PLAYBACK_START_DMA_DESCR_CH12,
NUM_DSCRS_PER_CHANNEL,
ACP_DMA_PRIORITY_LEVEL_NORMAL);
else
config_acp_dma_channel(acp_mmio, ACP_TO_SYSRAM_CH_NUM,
CAPTURE_START_DMA_DESCR_CH14,
NUM_DSCRS_PER_CHANNEL,
ACP_DMA_PRIORITY_LEVEL_NORMAL);
}
static void set_acp_to_i2s_dma_descriptors(void __iomem *acp_mmio,
u32 size, int direction)
{
u16 i;
u16 dma_dscr_idx = PLAYBACK_START_DMA_DESCR_CH13;
acp_dma_dscr_transfer_t dmadscr[NUM_DSCRS_PER_CHANNEL];
for (i = 0; i < NUM_DSCRS_PER_CHANNEL; i++) {
dmadscr[i].xfer_val = 0;
if (direction == SNDRV_PCM_STREAM_PLAYBACK) {
dma_dscr_idx = PLAYBACK_START_DMA_DESCR_CH13 + i;
dmadscr[i].src = ACP_SHARED_RAM_BANK_1_ADDRESS +
(i * (size/2));
dmadscr[i].dest = 0;
dmadscr[i].xfer_val |= BIT(22) | (TO_ACP_I2S_1 << 16) |
(size / 2);
} else {
dma_dscr_idx = CAPTURE_START_DMA_DESCR_CH15 + i;
dmadscr[i].src = 0;
dmadscr[i].dest = ACP_SHARED_RAM_BANK_5_ADDRESS +
(i * (size / 2));
dmadscr[i].xfer_val |= BIT(22) |
(FROM_ACP_I2S_1 << 16) | (size / 2);
}
config_dma_descriptor_in_sram(acp_mmio, dma_dscr_idx,
&dmadscr[i]);
}
if (direction == SNDRV_PCM_STREAM_PLAYBACK)
config_acp_dma_channel(acp_mmio, ACP_TO_I2S_DMA_CH_NUM,
PLAYBACK_START_DMA_DESCR_CH13,
NUM_DSCRS_PER_CHANNEL,
ACP_DMA_PRIORITY_LEVEL_NORMAL);
else
config_acp_dma_channel(acp_mmio, I2S_TO_ACP_DMA_CH_NUM,
CAPTURE_START_DMA_DESCR_CH15,
NUM_DSCRS_PER_CHANNEL,
ACP_DMA_PRIORITY_LEVEL_NORMAL);
}
static void acp_pte_config(void __iomem *acp_mmio, struct page *pg,
u16 num_of_pages, u32 pte_offset)
{
u16 page_idx;
u64 addr;
u32 low;
u32 high;
u32 offset;
offset = ACP_DAGB_GRP_SRBM_SRAM_BASE_OFFSET + (pte_offset * 8);
for (page_idx = 0; page_idx < (num_of_pages); page_idx++) {
acp_reg_write((offset + (page_idx * 8)),
acp_mmio, mmACP_SRBM_Targ_Idx_Addr);
addr = page_to_phys(pg);
low = lower_32_bits(addr);
high = upper_32_bits(addr);
acp_reg_write(low, acp_mmio, mmACP_SRBM_Targ_Idx_Data);
acp_reg_write((offset + (page_idx * 8) + 4),
acp_mmio, mmACP_SRBM_Targ_Idx_Addr);
high |= BIT(31);
acp_reg_write(high, acp_mmio, mmACP_SRBM_Targ_Idx_Data);
pg++;
}
}
static void config_acp_dma(void __iomem *acp_mmio,
struct audio_substream_data *audio_config)
{
u32 pte_offset;
if (audio_config->direction == SNDRV_PCM_STREAM_PLAYBACK)
pte_offset = ACP_PLAYBACK_PTE_OFFSET;
else
pte_offset = ACP_CAPTURE_PTE_OFFSET;
acp_pte_config(acp_mmio, audio_config->pg, audio_config->num_of_pages,
pte_offset);
set_acp_sysmem_dma_descriptors(acp_mmio, audio_config->size,
audio_config->direction, pte_offset);
set_acp_to_i2s_dma_descriptors(acp_mmio, audio_config->size,
audio_config->direction);
}
static void acp_dma_start(void __iomem *acp_mmio,
u16 ch_num, bool is_circular)
{
u32 dma_ctrl;
dma_ctrl = acp_reg_read(acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
acp_reg_write(1, acp_mmio, mmACP_DAGB_ATU_CTRL);
dma_ctrl |= ACP_DMA_CNTL_0__DMAChRun_MASK;
switch (ch_num) {
case ACP_TO_I2S_DMA_CH_NUM:
case ACP_TO_SYSRAM_CH_NUM:
case I2S_TO_ACP_DMA_CH_NUM:
dma_ctrl |= ACP_DMA_CNTL_0__DMAChIOCEn_MASK;
break;
default:
dma_ctrl &= ~ACP_DMA_CNTL_0__DMAChIOCEn_MASK;
break;
}
if (is_circular == true)
dma_ctrl |= ACP_DMA_CNTL_0__Circular_DMA_En_MASK;
else
dma_ctrl &= ~ACP_DMA_CNTL_0__Circular_DMA_En_MASK;
acp_reg_write(dma_ctrl, acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
}
static int acp_dma_stop(void __iomem *acp_mmio, u8 ch_num)
{
u32 dma_ctrl;
u32 dma_ch_sts;
u32 count = ACP_DMA_RESET_TIME;
dma_ctrl = acp_reg_read(acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
dma_ctrl &= ~ACP_DMA_CNTL_0__DMAChRun_MASK;
dma_ctrl &= ~ACP_DMA_CNTL_0__DMAChIOCEn_MASK;
acp_reg_write(dma_ctrl, acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
dma_ch_sts = acp_reg_read(acp_mmio, mmACP_DMA_CH_STS);
if (dma_ch_sts & BIT(ch_num)) {
dma_ctrl |= ACP_DMA_CNTL_0__DMAChRst_MASK;
acp_reg_write(dma_ctrl, acp_mmio, mmACP_DMA_CNTL_0 + ch_num);
}
while (true) {
dma_ch_sts = acp_reg_read(acp_mmio, mmACP_DMA_CH_STS);
if (!(dma_ch_sts & BIT(ch_num))) {
dma_ctrl &= ~ACP_DMA_CNTL_0__DMAChRst_MASK;
acp_reg_write(dma_ctrl, acp_mmio, mmACP_DMA_CNTL_0
+ ch_num);
break;
}
if (--count == 0) {
pr_err("Failed to stop ACP DMA channel : %d\n", ch_num);
return -ETIMEDOUT;
}
udelay(100);
}
return 0;
}
static void acp_set_sram_bank_state(void __iomem *acp_mmio, u16 bank,
bool power_on)
{
u32 val, req_reg, sts_reg, sts_reg_mask;
u32 loops = 1000;
if (bank < 32) {
req_reg = mmACP_MEM_SHUT_DOWN_REQ_LO;
sts_reg = mmACP_MEM_SHUT_DOWN_STS_LO;
sts_reg_mask = 0xFFFFFFFF;
} else {
bank -= 32;
req_reg = mmACP_MEM_SHUT_DOWN_REQ_HI;
sts_reg = mmACP_MEM_SHUT_DOWN_STS_HI;
sts_reg_mask = 0x0000FFFF;
}
val = acp_reg_read(acp_mmio, req_reg);
if (val & (1 << bank)) {
if (power_on == true)
val &= ~(1 << bank);
else
return;
} else {
if (power_on == false)
val |= 1 << bank;
else
return;
}
acp_reg_write(val, acp_mmio, req_reg);
while (acp_reg_read(acp_mmio, sts_reg) != sts_reg_mask) {
if (!loops--) {
pr_err("ACP SRAM bank %d state change failed\n", bank);
break;
}
cpu_relax();
}
}
static int acp_init(void __iomem *acp_mmio)
{
u16 bank;
u32 val, count, sram_pte_offset;
val = acp_reg_read(acp_mmio, mmACP_SOFT_RESET);
val |= ACP_SOFT_RESET__SoftResetAud_MASK;
acp_reg_write(val, acp_mmio, mmACP_SOFT_RESET);
count = ACP_SOFT_RESET_DONE_TIME_OUT_VALUE;
while (true) {
val = acp_reg_read(acp_mmio, mmACP_SOFT_RESET);
if (ACP_SOFT_RESET__SoftResetAudDone_MASK ==
(val & ACP_SOFT_RESET__SoftResetAudDone_MASK))
break;
if (--count == 0) {
pr_err("Failed to reset ACP\n");
return -ETIMEDOUT;
}
udelay(100);
}
val = acp_reg_read(acp_mmio, mmACP_CONTROL);
val = val | ACP_CONTROL__ClkEn_MASK;
acp_reg_write(val, acp_mmio, mmACP_CONTROL);
count = ACP_CLOCK_EN_TIME_OUT_VALUE;
while (true) {
val = acp_reg_read(acp_mmio, mmACP_STATUS);
if (val & (u32) 0x1)
break;
if (--count == 0) {
pr_err("Failed to reset ACP\n");
return -ETIMEDOUT;
}
udelay(100);
}
val = acp_reg_read(acp_mmio, mmACP_SOFT_RESET);
val &= ~ACP_SOFT_RESET__SoftResetAud_MASK;
acp_reg_write(val, acp_mmio, mmACP_SOFT_RESET);
acp_reg_write(ACP_ONION_CNTL_DEFAULT, acp_mmio,
mmACP_AXI2DAGB_ONION_CNTL);
acp_reg_write(ACP_GARLIC_CNTL_DEFAULT, acp_mmio,
mmACP_AXI2DAGB_GARLIC_CNTL);
sram_pte_offset = ACP_DAGB_GRP_SRAM_BASE_ADDRESS |
ACP_DAGB_BASE_ADDR_GRP_1__AXI2DAGBSnoopSel_MASK |
ACP_DAGB_BASE_ADDR_GRP_1__AXI2DAGBTargetMemSel_MASK |
ACP_DAGB_BASE_ADDR_GRP_1__AXI2DAGBGrpEnable_MASK;
acp_reg_write(sram_pte_offset, acp_mmio, mmACP_DAGB_BASE_ADDR_GRP_1);
acp_reg_write(ACP_PAGE_SIZE_4K_ENABLE, acp_mmio,
mmACP_DAGB_PAGE_SIZE_GRP_1);
acp_reg_write(ACP_SRAM_BASE_ADDRESS, acp_mmio,
mmACP_DMA_DESC_BASE_ADDR);
acp_reg_write(0x4, acp_mmio, mmACP_DMA_DESC_MAX_NUM_DSCR);
acp_reg_write(ACP_EXTERNAL_INTR_CNTL__DMAIOCMask_MASK,
acp_mmio, mmACP_EXTERNAL_INTR_CNTL);
for (bank = 1; bank < 48; bank++)
acp_set_sram_bank_state(acp_mmio, bank, false);
return 0;
}
static int acp_deinit(void __iomem *acp_mmio)
{
u32 val;
u32 count;
val = acp_reg_read(acp_mmio, mmACP_SOFT_RESET);
val |= ACP_SOFT_RESET__SoftResetAud_MASK;
acp_reg_write(val, acp_mmio, mmACP_SOFT_RESET);
count = ACP_SOFT_RESET_DONE_TIME_OUT_VALUE;
while (true) {
val = acp_reg_read(acp_mmio, mmACP_SOFT_RESET);
if (ACP_SOFT_RESET__SoftResetAudDone_MASK ==
(val & ACP_SOFT_RESET__SoftResetAudDone_MASK))
break;
if (--count == 0) {
pr_err("Failed to reset ACP\n");
return -ETIMEDOUT;
}
udelay(100);
}
val = acp_reg_read(acp_mmio, mmACP_CONTROL);
val &= ~ACP_CONTROL__ClkEn_MASK;
acp_reg_write(val, acp_mmio, mmACP_CONTROL);
count = ACP_CLOCK_EN_TIME_OUT_VALUE;
while (true) {
val = acp_reg_read(acp_mmio, mmACP_STATUS);
if (!(val & (u32) 0x1))
break;
if (--count == 0) {
pr_err("Failed to reset ACP\n");
return -ETIMEDOUT;
}
udelay(100);
}
return 0;
}
static irqreturn_t dma_irq_handler(int irq, void *arg)
{
u16 dscr_idx;
u32 intr_flag, ext_intr_status;
struct audio_drv_data *irq_data;
void __iomem *acp_mmio;
struct device *dev = arg;
bool valid_irq = false;
irq_data = dev_get_drvdata(dev);
acp_mmio = irq_data->acp_mmio;
ext_intr_status = acp_reg_read(acp_mmio, mmACP_EXTERNAL_INTR_STAT);
intr_flag = (((ext_intr_status &
ACP_EXTERNAL_INTR_STAT__DMAIOCStat_MASK) >>
ACP_EXTERNAL_INTR_STAT__DMAIOCStat__SHIFT));
if ((intr_flag & BIT(ACP_TO_I2S_DMA_CH_NUM)) != 0) {
valid_irq = true;
if (acp_reg_read(acp_mmio, mmACP_DMA_CUR_DSCR_13) ==
PLAYBACK_START_DMA_DESCR_CH13)
dscr_idx = PLAYBACK_START_DMA_DESCR_CH12;
else
dscr_idx = PLAYBACK_END_DMA_DESCR_CH12;
config_acp_dma_channel(acp_mmio, SYSRAM_TO_ACP_CH_NUM, dscr_idx,
1, 0);
acp_dma_start(acp_mmio, SYSRAM_TO_ACP_CH_NUM, false);
snd_pcm_period_elapsed(irq_data->play_stream);
acp_reg_write((intr_flag & BIT(ACP_TO_I2S_DMA_CH_NUM)) << 16,
acp_mmio, mmACP_EXTERNAL_INTR_STAT);
}
if ((intr_flag & BIT(I2S_TO_ACP_DMA_CH_NUM)) != 0) {
valid_irq = true;
if (acp_reg_read(acp_mmio, mmACP_DMA_CUR_DSCR_15) ==
CAPTURE_START_DMA_DESCR_CH15)
dscr_idx = CAPTURE_END_DMA_DESCR_CH14;
else
dscr_idx = CAPTURE_START_DMA_DESCR_CH14;
config_acp_dma_channel(acp_mmio, ACP_TO_SYSRAM_CH_NUM, dscr_idx,
1, 0);
acp_dma_start(acp_mmio, ACP_TO_SYSRAM_CH_NUM, false);
acp_reg_write((intr_flag & BIT(I2S_TO_ACP_DMA_CH_NUM)) << 16,
acp_mmio, mmACP_EXTERNAL_INTR_STAT);
}
if ((intr_flag & BIT(ACP_TO_SYSRAM_CH_NUM)) != 0) {
valid_irq = true;
snd_pcm_period_elapsed(irq_data->capture_stream);
acp_reg_write((intr_flag & BIT(ACP_TO_SYSRAM_CH_NUM)) << 16,
acp_mmio, mmACP_EXTERNAL_INTR_STAT);
}
if (valid_irq)
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static int acp_dma_open(struct snd_pcm_substream *substream)
{
u16 bank;
int ret = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *prtd = substream->private_data;
struct audio_drv_data *intr_data = dev_get_drvdata(prtd->platform->dev);
struct audio_substream_data *adata =
kzalloc(sizeof(struct audio_substream_data), GFP_KERNEL);
if (adata == NULL)
return -ENOMEM;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
runtime->hw = acp_pcm_hardware_playback;
else
runtime->hw = acp_pcm_hardware_capture;
ret = snd_pcm_hw_constraint_integer(runtime,
SNDRV_PCM_HW_PARAM_PERIODS);
if (ret < 0) {
dev_err(prtd->platform->dev, "set integer constraint failed\n");
kfree(adata);
return ret;
}
adata->acp_mmio = intr_data->acp_mmio;
runtime->private_data = adata;
if (!intr_data->play_stream && !intr_data->capture_stream)
acp_reg_write(1, adata->acp_mmio, mmACP_EXTERNAL_INTR_ENB);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
intr_data->play_stream = substream;
for (bank = 1; bank <= 4; bank++)
acp_set_sram_bank_state(intr_data->acp_mmio, bank,
true);
} else {
intr_data->capture_stream = substream;
for (bank = 5; bank <= 8; bank++)
acp_set_sram_bank_state(intr_data->acp_mmio, bank,
true);
}
return 0;
}
static int acp_dma_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int status;
uint64_t size;
struct page *pg;
struct snd_pcm_runtime *runtime;
struct audio_substream_data *rtd;
runtime = substream->runtime;
rtd = runtime->private_data;
if (WARN_ON(!rtd))
return -EINVAL;
size = params_buffer_bytes(params);
status = snd_pcm_lib_malloc_pages(substream, size);
if (status < 0)
return status;
memset(substream->runtime->dma_area, 0, params_buffer_bytes(params));
pg = virt_to_page(substream->dma_buffer.area);
if (pg != NULL) {
acp_set_sram_bank_state(rtd->acp_mmio, 0, true);
rtd->pg = pg;
rtd->order = get_order(size);
rtd->pg = pg;
rtd->size = size;
rtd->num_of_pages = PAGE_ALIGN(size) >> PAGE_SHIFT;
rtd->direction = substream->stream;
config_acp_dma(rtd->acp_mmio, rtd);
status = 0;
} else {
status = -ENOMEM;
}
return status;
}
static int acp_dma_hw_free(struct snd_pcm_substream *substream)
{
return snd_pcm_lib_free_pages(substream);
}
static snd_pcm_uframes_t acp_dma_pointer(struct snd_pcm_substream *substream)
{
u16 dscr;
u32 mul, dma_config, period_bytes;
u32 pos = 0;
struct snd_pcm_runtime *runtime = substream->runtime;
struct audio_substream_data *rtd = runtime->private_data;
period_bytes = frames_to_bytes(runtime, runtime->period_size);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
dscr = acp_reg_read(rtd->acp_mmio, mmACP_DMA_CUR_DSCR_13);
if (dscr == PLAYBACK_START_DMA_DESCR_CH13)
mul = 0;
else
mul = 1;
pos = (mul * period_bytes);
} else {
dma_config = acp_reg_read(rtd->acp_mmio, mmACP_DMA_CNTL_14);
if (dma_config != 0) {
dscr = acp_reg_read(rtd->acp_mmio,
mmACP_DMA_CUR_DSCR_14);
if (dscr == CAPTURE_START_DMA_DESCR_CH14)
mul = 1;
else
mul = 2;
pos = (mul * period_bytes);
}
if (pos >= (2 * period_bytes))
pos = 0;
}
return bytes_to_frames(runtime, pos);
}
static int acp_dma_mmap(struct snd_pcm_substream *substream,
struct vm_area_struct *vma)
{
return snd_pcm_lib_default_mmap(substream, vma);
}
static int acp_dma_prepare(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct audio_substream_data *rtd = runtime->private_data;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
config_acp_dma_channel(rtd->acp_mmio, SYSRAM_TO_ACP_CH_NUM,
PLAYBACK_START_DMA_DESCR_CH12,
NUM_DSCRS_PER_CHANNEL, 0);
config_acp_dma_channel(rtd->acp_mmio, ACP_TO_I2S_DMA_CH_NUM,
PLAYBACK_START_DMA_DESCR_CH13,
NUM_DSCRS_PER_CHANNEL, 0);
acp_dma_start(rtd->acp_mmio, SYSRAM_TO_ACP_CH_NUM, false);
config_acp_dma_channel(rtd->acp_mmio, SYSRAM_TO_ACP_CH_NUM,
PLAYBACK_START_DMA_DESCR_CH12,
1, 0);
} else {
config_acp_dma_channel(rtd->acp_mmio, ACP_TO_SYSRAM_CH_NUM,
CAPTURE_START_DMA_DESCR_CH14,
NUM_DSCRS_PER_CHANNEL, 0);
config_acp_dma_channel(rtd->acp_mmio, I2S_TO_ACP_DMA_CH_NUM,
CAPTURE_START_DMA_DESCR_CH15,
NUM_DSCRS_PER_CHANNEL, 0);
}
return 0;
}
static int acp_dma_trigger(struct snd_pcm_substream *substream, int cmd)
{
int ret;
u32 loops = 1000;
struct snd_pcm_runtime *runtime = substream->runtime;
struct snd_soc_pcm_runtime *prtd = substream->private_data;
struct audio_substream_data *rtd = runtime->private_data;
if (!rtd)
return -EINVAL;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
case SNDRV_PCM_TRIGGER_RESUME:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
acp_dma_start(rtd->acp_mmio,
SYSRAM_TO_ACP_CH_NUM, false);
while (acp_reg_read(rtd->acp_mmio, mmACP_DMA_CH_STS) &
BIT(SYSRAM_TO_ACP_CH_NUM)) {
if (!loops--) {
dev_err(prtd->platform->dev,
"acp dma start timeout\n");
return -ETIMEDOUT;
}
cpu_relax();
}
acp_dma_start(rtd->acp_mmio,
ACP_TO_I2S_DMA_CH_NUM, true);
} else {
acp_dma_start(rtd->acp_mmio,
I2S_TO_ACP_DMA_CH_NUM, true);
}
ret = 0;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_SUSPEND:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
ret = acp_dma_stop(rtd->acp_mmio,
ACP_TO_I2S_DMA_CH_NUM);
else
ret = acp_dma_stop(rtd->acp_mmio,
I2S_TO_ACP_DMA_CH_NUM);
break;
default:
ret = -EINVAL;
}
return ret;
}
static int acp_dma_new(struct snd_soc_pcm_runtime *rtd)
{
return snd_pcm_lib_preallocate_pages_for_all(rtd->pcm,
SNDRV_DMA_TYPE_DEV,
NULL, MIN_BUFFER,
MAX_BUFFER);
}
static int acp_dma_close(struct snd_pcm_substream *substream)
{
u16 bank;
struct snd_pcm_runtime *runtime = substream->runtime;
struct audio_substream_data *rtd = runtime->private_data;
struct snd_soc_pcm_runtime *prtd = substream->private_data;
struct audio_drv_data *adata = dev_get_drvdata(prtd->platform->dev);
kfree(rtd);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
adata->play_stream = NULL;
for (bank = 1; bank <= 4; bank++)
acp_set_sram_bank_state(adata->acp_mmio, bank,
false);
} else {
adata->capture_stream = NULL;
for (bank = 5; bank <= 8; bank++)
acp_set_sram_bank_state(adata->acp_mmio, bank,
false);
}
if (!adata->play_stream && !adata->capture_stream)
acp_reg_write(0, adata->acp_mmio, mmACP_EXTERNAL_INTR_ENB);
return 0;
}
static int acp_audio_probe(struct platform_device *pdev)
{
int status;
struct audio_drv_data *audio_drv_data;
struct resource *res;
audio_drv_data = devm_kzalloc(&pdev->dev, sizeof(struct audio_drv_data),
GFP_KERNEL);
if (audio_drv_data == NULL)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
audio_drv_data->acp_mmio = devm_ioremap_resource(&pdev->dev, res);
audio_drv_data->play_stream = NULL;
audio_drv_data->capture_stream = NULL;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(&pdev->dev, "IORESOURCE_IRQ FAILED\n");
return -ENODEV;
}
status = devm_request_irq(&pdev->dev, res->start, dma_irq_handler,
0, "ACP_IRQ", &pdev->dev);
if (status) {
dev_err(&pdev->dev, "ACP IRQ request failed\n");
return status;
}
dev_set_drvdata(&pdev->dev, audio_drv_data);
acp_init(audio_drv_data->acp_mmio);
status = snd_soc_register_platform(&pdev->dev, &acp_asoc_platform);
if (status != 0) {
dev_err(&pdev->dev, "Fail to register ALSA platform device\n");
return status;
}
pm_runtime_set_autosuspend_delay(&pdev->dev, 10000);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_enable(&pdev->dev);
return status;
}
static int acp_audio_remove(struct platform_device *pdev)
{
struct audio_drv_data *adata = dev_get_drvdata(&pdev->dev);
acp_deinit(adata->acp_mmio);
snd_soc_unregister_platform(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int acp_pcm_resume(struct device *dev)
{
u16 bank;
struct audio_drv_data *adata = dev_get_drvdata(dev);
acp_init(adata->acp_mmio);
if (adata->play_stream && adata->play_stream->runtime) {
for (bank = 1; bank <= 4; bank++)
acp_set_sram_bank_state(adata->acp_mmio, bank,
true);
config_acp_dma(adata->acp_mmio,
adata->play_stream->runtime->private_data);
}
if (adata->capture_stream && adata->capture_stream->runtime) {
for (bank = 5; bank <= 8; bank++)
acp_set_sram_bank_state(adata->acp_mmio, bank,
true);
config_acp_dma(adata->acp_mmio,
adata->capture_stream->runtime->private_data);
}
acp_reg_write(1, adata->acp_mmio, mmACP_EXTERNAL_INTR_ENB);
return 0;
}
static int acp_pcm_runtime_suspend(struct device *dev)
{
struct audio_drv_data *adata = dev_get_drvdata(dev);
acp_deinit(adata->acp_mmio);
acp_reg_write(0, adata->acp_mmio, mmACP_EXTERNAL_INTR_ENB);
return 0;
}
static int acp_pcm_runtime_resume(struct device *dev)
{
struct audio_drv_data *adata = dev_get_drvdata(dev);
acp_init(adata->acp_mmio);
acp_reg_write(1, adata->acp_mmio, mmACP_EXTERNAL_INTR_ENB);
return 0;
}
