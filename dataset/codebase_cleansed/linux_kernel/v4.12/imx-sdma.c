static inline u32 chnenbl_ofs(struct sdma_engine *sdma, unsigned int event)
{
u32 chnenbl0 = sdma->drvdata->chnenbl0;
return chnenbl0 + event * 4;
}
static int sdma_config_ownership(struct sdma_channel *sdmac,
bool event_override, bool mcu_override, bool dsp_override)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
unsigned long evt, mcu, dsp;
if (event_override && mcu_override && dsp_override)
return -EINVAL;
evt = readl_relaxed(sdma->regs + SDMA_H_EVTOVR);
mcu = readl_relaxed(sdma->regs + SDMA_H_HOSTOVR);
dsp = readl_relaxed(sdma->regs + SDMA_H_DSPOVR);
if (dsp_override)
__clear_bit(channel, &dsp);
else
__set_bit(channel, &dsp);
if (event_override)
__clear_bit(channel, &evt);
else
__set_bit(channel, &evt);
if (mcu_override)
__clear_bit(channel, &mcu);
else
__set_bit(channel, &mcu);
writel_relaxed(evt, sdma->regs + SDMA_H_EVTOVR);
writel_relaxed(mcu, sdma->regs + SDMA_H_HOSTOVR);
writel_relaxed(dsp, sdma->regs + SDMA_H_DSPOVR);
return 0;
}
static void sdma_enable_channel(struct sdma_engine *sdma, int channel)
{
writel(BIT(channel), sdma->regs + SDMA_H_START);
}
static int sdma_run_channel0(struct sdma_engine *sdma)
{
int ret;
u32 reg;
sdma_enable_channel(sdma, 0);
ret = readl_relaxed_poll_timeout_atomic(sdma->regs + SDMA_H_STATSTOP,
reg, !(reg & 1), 1, 500);
if (ret)
dev_err(sdma->dev, "Timeout waiting for CH0 ready\n");
if (readl(sdma->regs + SDMA_H_CONFIG) == 0)
writel_relaxed(SDMA_H_CONFIG_CSM, sdma->regs + SDMA_H_CONFIG);
return ret;
}
static int sdma_load_script(struct sdma_engine *sdma, void *buf, int size,
u32 address)
{
struct sdma_buffer_descriptor *bd0 = sdma->channel[0].bd;
void *buf_virt;
dma_addr_t buf_phys;
int ret;
unsigned long flags;
buf_virt = dma_alloc_coherent(NULL,
size,
&buf_phys, GFP_KERNEL);
if (!buf_virt) {
return -ENOMEM;
}
spin_lock_irqsave(&sdma->channel_0_lock, flags);
bd0->mode.command = C0_SETPM;
bd0->mode.status = BD_DONE | BD_INTR | BD_WRAP | BD_EXTD;
bd0->mode.count = size / 2;
bd0->buffer_addr = buf_phys;
bd0->ext_buffer_addr = address;
memcpy(buf_virt, buf, size);
ret = sdma_run_channel0(sdma);
spin_unlock_irqrestore(&sdma->channel_0_lock, flags);
dma_free_coherent(NULL, size, buf_virt, buf_phys);
return ret;
}
static void sdma_event_enable(struct sdma_channel *sdmac, unsigned int event)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
unsigned long val;
u32 chnenbl = chnenbl_ofs(sdma, event);
val = readl_relaxed(sdma->regs + chnenbl);
__set_bit(channel, &val);
writel_relaxed(val, sdma->regs + chnenbl);
}
static void sdma_event_disable(struct sdma_channel *sdmac, unsigned int event)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
u32 chnenbl = chnenbl_ofs(sdma, event);
unsigned long val;
val = readl_relaxed(sdma->regs + chnenbl);
__clear_bit(channel, &val);
writel_relaxed(val, sdma->regs + chnenbl);
}
static void sdma_update_channel_loop(struct sdma_channel *sdmac)
{
struct sdma_buffer_descriptor *bd;
int error = 0;
enum dma_status old_status = sdmac->status;
while (1) {
bd = &sdmac->bd[sdmac->buf_tail];
if (bd->mode.status & BD_DONE)
break;
if (bd->mode.status & BD_RROR) {
bd->mode.status &= ~BD_RROR;
sdmac->status = DMA_ERROR;
error = -EIO;
}
sdmac->chn_real_count = bd->mode.count;
bd->mode.status |= BD_DONE;
bd->mode.count = sdmac->period_len;
sdmac->buf_ptail = sdmac->buf_tail;
sdmac->buf_tail = (sdmac->buf_tail + 1) % sdmac->num_bd;
dmaengine_desc_get_callback_invoke(&sdmac->desc, NULL);
if (error)
sdmac->status = old_status;
}
}
static void mxc_sdma_handle_channel_normal(unsigned long data)
{
struct sdma_channel *sdmac = (struct sdma_channel *) data;
struct sdma_buffer_descriptor *bd;
int i, error = 0;
sdmac->chn_real_count = 0;
for (i = 0; i < sdmac->num_bd; i++) {
bd = &sdmac->bd[i];
if (bd->mode.status & (BD_DONE | BD_RROR))
error = -EIO;
sdmac->chn_real_count += bd->mode.count;
}
if (error)
sdmac->status = DMA_ERROR;
else
sdmac->status = DMA_COMPLETE;
dma_cookie_complete(&sdmac->desc);
dmaengine_desc_get_callback_invoke(&sdmac->desc, NULL);
}
static irqreturn_t sdma_int_handler(int irq, void *dev_id)
{
struct sdma_engine *sdma = dev_id;
unsigned long stat;
stat = readl_relaxed(sdma->regs + SDMA_H_INTR);
writel_relaxed(stat, sdma->regs + SDMA_H_INTR);
stat &= ~1;
while (stat) {
int channel = fls(stat) - 1;
struct sdma_channel *sdmac = &sdma->channel[channel];
if (sdmac->flags & IMX_DMA_SG_LOOP)
sdma_update_channel_loop(sdmac);
else
tasklet_schedule(&sdmac->tasklet);
__clear_bit(channel, &stat);
}
return IRQ_HANDLED;
}
static void sdma_get_pc(struct sdma_channel *sdmac,
enum sdma_peripheral_type peripheral_type)
{
struct sdma_engine *sdma = sdmac->sdma;
int per_2_emi = 0, emi_2_per = 0;
int per_2_per = 0;
sdmac->pc_from_device = 0;
sdmac->pc_to_device = 0;
sdmac->device_to_device = 0;
switch (peripheral_type) {
case IMX_DMATYPE_MEMORY:
break;
case IMX_DMATYPE_DSP:
emi_2_per = sdma->script_addrs->bp_2_ap_addr;
per_2_emi = sdma->script_addrs->ap_2_bp_addr;
break;
case IMX_DMATYPE_FIRI:
per_2_emi = sdma->script_addrs->firi_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_firi_addr;
break;
case IMX_DMATYPE_UART:
per_2_emi = sdma->script_addrs->uart_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_app_addr;
break;
case IMX_DMATYPE_UART_SP:
per_2_emi = sdma->script_addrs->uartsh_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_shp_addr;
break;
case IMX_DMATYPE_ATA:
per_2_emi = sdma->script_addrs->ata_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_ata_addr;
break;
case IMX_DMATYPE_CSPI:
case IMX_DMATYPE_EXT:
case IMX_DMATYPE_SSI:
case IMX_DMATYPE_SAI:
per_2_emi = sdma->script_addrs->app_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_app_addr;
break;
case IMX_DMATYPE_SSI_DUAL:
per_2_emi = sdma->script_addrs->ssish_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_ssish_addr;
break;
case IMX_DMATYPE_SSI_SP:
case IMX_DMATYPE_MMC:
case IMX_DMATYPE_SDHC:
case IMX_DMATYPE_CSPI_SP:
case IMX_DMATYPE_ESAI:
case IMX_DMATYPE_MSHC_SP:
per_2_emi = sdma->script_addrs->shp_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_shp_addr;
break;
case IMX_DMATYPE_ASRC:
per_2_emi = sdma->script_addrs->asrc_2_mcu_addr;
emi_2_per = sdma->script_addrs->asrc_2_mcu_addr;
per_2_per = sdma->script_addrs->per_2_per_addr;
break;
case IMX_DMATYPE_ASRC_SP:
per_2_emi = sdma->script_addrs->shp_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_shp_addr;
per_2_per = sdma->script_addrs->per_2_per_addr;
break;
case IMX_DMATYPE_MSHC:
per_2_emi = sdma->script_addrs->mshc_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_mshc_addr;
break;
case IMX_DMATYPE_CCM:
per_2_emi = sdma->script_addrs->dptc_dvfs_addr;
break;
case IMX_DMATYPE_SPDIF:
per_2_emi = sdma->script_addrs->spdif_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_spdif_addr;
break;
case IMX_DMATYPE_IPU_MEMORY:
emi_2_per = sdma->script_addrs->ext_mem_2_ipu_addr;
break;
default:
break;
}
sdmac->pc_from_device = per_2_emi;
sdmac->pc_to_device = emi_2_per;
sdmac->device_to_device = per_2_per;
}
static int sdma_load_context(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
int load_address;
struct sdma_context_data *context = sdma->context;
struct sdma_buffer_descriptor *bd0 = sdma->channel[0].bd;
int ret;
unsigned long flags;
if (sdmac->direction == DMA_DEV_TO_MEM)
load_address = sdmac->pc_from_device;
else if (sdmac->direction == DMA_DEV_TO_DEV)
load_address = sdmac->device_to_device;
else
load_address = sdmac->pc_to_device;
if (load_address < 0)
return load_address;
dev_dbg(sdma->dev, "load_address = %d\n", load_address);
dev_dbg(sdma->dev, "wml = 0x%08x\n", (u32)sdmac->watermark_level);
dev_dbg(sdma->dev, "shp_addr = 0x%08x\n", sdmac->shp_addr);
dev_dbg(sdma->dev, "per_addr = 0x%08x\n", sdmac->per_addr);
dev_dbg(sdma->dev, "event_mask0 = 0x%08x\n", (u32)sdmac->event_mask[0]);
dev_dbg(sdma->dev, "event_mask1 = 0x%08x\n", (u32)sdmac->event_mask[1]);
spin_lock_irqsave(&sdma->channel_0_lock, flags);
memset(context, 0, sizeof(*context));
context->channel_state.pc = load_address;
context->gReg[0] = sdmac->event_mask[1];
context->gReg[1] = sdmac->event_mask[0];
context->gReg[2] = sdmac->per_addr;
context->gReg[6] = sdmac->shp_addr;
context->gReg[7] = sdmac->watermark_level;
bd0->mode.command = C0_SETDM;
bd0->mode.status = BD_DONE | BD_INTR | BD_WRAP | BD_EXTD;
bd0->mode.count = sizeof(*context) / 4;
bd0->buffer_addr = sdma->context_phys;
bd0->ext_buffer_addr = 2048 + (sizeof(*context) / 4) * channel;
ret = sdma_run_channel0(sdma);
spin_unlock_irqrestore(&sdma->channel_0_lock, flags);
return ret;
}
static struct sdma_channel *to_sdma_chan(struct dma_chan *chan)
{
return container_of(chan, struct sdma_channel, chan);
}
static int sdma_disable_channel(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
writel_relaxed(BIT(channel), sdma->regs + SDMA_H_STATSTOP);
sdmac->status = DMA_ERROR;
return 0;
}
static int sdma_disable_channel_with_delay(struct dma_chan *chan)
{
sdma_disable_channel(chan);
mdelay(1);
return 0;
}
static void sdma_set_watermarklevel_for_p2p(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int lwml = sdmac->watermark_level & SDMA_WATERMARK_LEVEL_LWML;
int hwml = (sdmac->watermark_level & SDMA_WATERMARK_LEVEL_HWML) >> 16;
set_bit(sdmac->event_id0 % 32, &sdmac->event_mask[1]);
set_bit(sdmac->event_id1 % 32, &sdmac->event_mask[0]);
if (sdmac->event_id0 > 31)
sdmac->watermark_level |= SDMA_WATERMARK_LEVEL_LWE;
if (sdmac->event_id1 > 31)
sdmac->watermark_level |= SDMA_WATERMARK_LEVEL_HWE;
if (lwml > hwml) {
sdmac->watermark_level &= ~(SDMA_WATERMARK_LEVEL_LWML |
SDMA_WATERMARK_LEVEL_HWML);
sdmac->watermark_level |= hwml;
sdmac->watermark_level |= lwml << 16;
swap(sdmac->event_mask[0], sdmac->event_mask[1]);
}
if (sdmac->per_address2 >= sdma->spba_start_addr &&
sdmac->per_address2 <= sdma->spba_end_addr)
sdmac->watermark_level |= SDMA_WATERMARK_LEVEL_SP;
if (sdmac->per_address >= sdma->spba_start_addr &&
sdmac->per_address <= sdma->spba_end_addr)
sdmac->watermark_level |= SDMA_WATERMARK_LEVEL_DP;
sdmac->watermark_level |= SDMA_WATERMARK_LEVEL_CONT;
}
static int sdma_config_channel(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
int ret;
sdma_disable_channel(chan);
sdmac->event_mask[0] = 0;
sdmac->event_mask[1] = 0;
sdmac->shp_addr = 0;
sdmac->per_addr = 0;
if (sdmac->event_id0) {
if (sdmac->event_id0 >= sdmac->sdma->drvdata->num_events)
return -EINVAL;
sdma_event_enable(sdmac, sdmac->event_id0);
}
if (sdmac->event_id1) {
if (sdmac->event_id1 >= sdmac->sdma->drvdata->num_events)
return -EINVAL;
sdma_event_enable(sdmac, sdmac->event_id1);
}
switch (sdmac->peripheral_type) {
case IMX_DMATYPE_DSP:
sdma_config_ownership(sdmac, false, true, true);
break;
case IMX_DMATYPE_MEMORY:
sdma_config_ownership(sdmac, false, true, false);
break;
default:
sdma_config_ownership(sdmac, true, true, false);
break;
}
sdma_get_pc(sdmac, sdmac->peripheral_type);
if ((sdmac->peripheral_type != IMX_DMATYPE_MEMORY) &&
(sdmac->peripheral_type != IMX_DMATYPE_DSP)) {
if (sdmac->event_id1) {
if (sdmac->peripheral_type == IMX_DMATYPE_ASRC_SP ||
sdmac->peripheral_type == IMX_DMATYPE_ASRC)
sdma_set_watermarklevel_for_p2p(sdmac);
} else
__set_bit(sdmac->event_id0, sdmac->event_mask);
sdmac->shp_addr = sdmac->per_address;
sdmac->per_addr = sdmac->per_address2;
} else {
sdmac->watermark_level = 0;
}
ret = sdma_load_context(sdmac);
return ret;
}
static int sdma_set_channel_priority(struct sdma_channel *sdmac,
unsigned int priority)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
if (priority < MXC_SDMA_MIN_PRIORITY
|| priority > MXC_SDMA_MAX_PRIORITY) {
return -EINVAL;
}
writel_relaxed(priority, sdma->regs + SDMA_CHNPRI_0 + 4 * channel);
return 0;
}
static int sdma_request_channel(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
int ret = -EBUSY;
sdmac->bd = dma_zalloc_coherent(NULL, PAGE_SIZE, &sdmac->bd_phys,
GFP_KERNEL);
if (!sdmac->bd) {
ret = -ENOMEM;
goto out;
}
sdma->channel_control[channel].base_bd_ptr = sdmac->bd_phys;
sdma->channel_control[channel].current_bd_ptr = sdmac->bd_phys;
sdma_set_channel_priority(sdmac, MXC_SDMA_DEFAULT_PRIORITY);
return 0;
out:
return ret;
}
static dma_cookie_t sdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
unsigned long flags;
struct sdma_channel *sdmac = to_sdma_chan(tx->chan);
dma_cookie_t cookie;
spin_lock_irqsave(&sdmac->lock, flags);
cookie = dma_cookie_assign(tx);
spin_unlock_irqrestore(&sdmac->lock, flags);
return cookie;
}
static int sdma_alloc_chan_resources(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct imx_dma_data *data = chan->private;
int prio, ret;
if (!data)
return -EINVAL;
switch (data->priority) {
case DMA_PRIO_HIGH:
prio = 3;
break;
case DMA_PRIO_MEDIUM:
prio = 2;
break;
case DMA_PRIO_LOW:
default:
prio = 1;
break;
}
sdmac->peripheral_type = data->peripheral_type;
sdmac->event_id0 = data->dma_request;
sdmac->event_id1 = data->dma_request2;
ret = clk_enable(sdmac->sdma->clk_ipg);
if (ret)
return ret;
ret = clk_enable(sdmac->sdma->clk_ahb);
if (ret)
goto disable_clk_ipg;
ret = sdma_request_channel(sdmac);
if (ret)
goto disable_clk_ahb;
ret = sdma_set_channel_priority(sdmac, prio);
if (ret)
goto disable_clk_ahb;
dma_async_tx_descriptor_init(&sdmac->desc, chan);
sdmac->desc.tx_submit = sdma_tx_submit;
sdmac->desc.flags = DMA_CTRL_ACK;
return 0;
disable_clk_ahb:
clk_disable(sdmac->sdma->clk_ahb);
disable_clk_ipg:
clk_disable(sdmac->sdma->clk_ipg);
return ret;
}
static void sdma_free_chan_resources(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
sdma_disable_channel(chan);
if (sdmac->event_id0)
sdma_event_disable(sdmac, sdmac->event_id0);
if (sdmac->event_id1)
sdma_event_disable(sdmac, sdmac->event_id1);
sdmac->event_id0 = 0;
sdmac->event_id1 = 0;
sdma_set_channel_priority(sdmac, 0);
dma_free_coherent(NULL, PAGE_SIZE, sdmac->bd, sdmac->bd_phys);
clk_disable(sdma->clk_ipg);
clk_disable(sdma->clk_ahb);
}
static struct dma_async_tx_descriptor *sdma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_transfer_direction direction,
unsigned long flags, void *context)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
int ret, i, count;
int channel = sdmac->channel;
struct scatterlist *sg;
if (sdmac->status == DMA_IN_PROGRESS)
return NULL;
sdmac->status = DMA_IN_PROGRESS;
sdmac->flags = 0;
sdmac->buf_tail = 0;
sdmac->buf_ptail = 0;
sdmac->chn_real_count = 0;
dev_dbg(sdma->dev, "setting up %d entries for channel %d.\n",
sg_len, channel);
sdmac->direction = direction;
ret = sdma_load_context(sdmac);
if (ret)
goto err_out;
if (sg_len > NUM_BD) {
dev_err(sdma->dev, "SDMA channel %d: maximum number of sg exceeded: %d > %d\n",
channel, sg_len, NUM_BD);
ret = -EINVAL;
goto err_out;
}
sdmac->chn_count = 0;
for_each_sg(sgl, sg, sg_len, i) {
struct sdma_buffer_descriptor *bd = &sdmac->bd[i];
int param;
bd->buffer_addr = sg->dma_address;
count = sg_dma_len(sg);
if (count > 0xffff) {
dev_err(sdma->dev, "SDMA channel %d: maximum bytes for sg entry exceeded: %d > %d\n",
channel, count, 0xffff);
ret = -EINVAL;
goto err_out;
}
bd->mode.count = count;
sdmac->chn_count += count;
if (sdmac->word_size > DMA_SLAVE_BUSWIDTH_4_BYTES) {
ret = -EINVAL;
goto err_out;
}
switch (sdmac->word_size) {
case DMA_SLAVE_BUSWIDTH_4_BYTES:
bd->mode.command = 0;
if (count & 3 || sg->dma_address & 3)
return NULL;
break;
case DMA_SLAVE_BUSWIDTH_2_BYTES:
bd->mode.command = 2;
if (count & 1 || sg->dma_address & 1)
return NULL;
break;
case DMA_SLAVE_BUSWIDTH_1_BYTE:
bd->mode.command = 1;
break;
default:
return NULL;
}
param = BD_DONE | BD_EXTD | BD_CONT;
if (i + 1 == sg_len) {
param |= BD_INTR;
param |= BD_LAST;
param &= ~BD_CONT;
}
dev_dbg(sdma->dev, "entry %d: count: %d dma: %#llx %s%s\n",
i, count, (u64)sg->dma_address,
param & BD_WRAP ? "wrap" : "",
param & BD_INTR ? " intr" : "");
bd->mode.status = param;
}
sdmac->num_bd = sg_len;
sdma->channel_control[channel].current_bd_ptr = sdmac->bd_phys;
return &sdmac->desc;
err_out:
sdmac->status = DMA_ERROR;
return NULL;
}
static struct dma_async_tx_descriptor *sdma_prep_dma_cyclic(
struct dma_chan *chan, dma_addr_t dma_addr, size_t buf_len,
size_t period_len, enum dma_transfer_direction direction,
unsigned long flags)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
int num_periods = buf_len / period_len;
int channel = sdmac->channel;
int ret, i = 0, buf = 0;
dev_dbg(sdma->dev, "%s channel: %d\n", __func__, channel);
if (sdmac->status == DMA_IN_PROGRESS)
return NULL;
sdmac->status = DMA_IN_PROGRESS;
sdmac->buf_tail = 0;
sdmac->buf_ptail = 0;
sdmac->chn_real_count = 0;
sdmac->period_len = period_len;
sdmac->flags |= IMX_DMA_SG_LOOP;
sdmac->direction = direction;
ret = sdma_load_context(sdmac);
if (ret)
goto err_out;
if (num_periods > NUM_BD) {
dev_err(sdma->dev, "SDMA channel %d: maximum number of sg exceeded: %d > %d\n",
channel, num_periods, NUM_BD);
goto err_out;
}
if (period_len > 0xffff) {
dev_err(sdma->dev, "SDMA channel %d: maximum period size exceeded: %d > %d\n",
channel, period_len, 0xffff);
goto err_out;
}
while (buf < buf_len) {
struct sdma_buffer_descriptor *bd = &sdmac->bd[i];
int param;
bd->buffer_addr = dma_addr;
bd->mode.count = period_len;
if (sdmac->word_size > DMA_SLAVE_BUSWIDTH_4_BYTES)
goto err_out;
if (sdmac->word_size == DMA_SLAVE_BUSWIDTH_4_BYTES)
bd->mode.command = 0;
else
bd->mode.command = sdmac->word_size;
param = BD_DONE | BD_EXTD | BD_CONT | BD_INTR;
if (i + 1 == num_periods)
param |= BD_WRAP;
dev_dbg(sdma->dev, "entry %d: count: %d dma: %#llx %s%s\n",
i, period_len, (u64)dma_addr,
param & BD_WRAP ? "wrap" : "",
param & BD_INTR ? " intr" : "");
bd->mode.status = param;
dma_addr += period_len;
buf += period_len;
i++;
}
sdmac->num_bd = num_periods;
sdma->channel_control[channel].current_bd_ptr = sdmac->bd_phys;
return &sdmac->desc;
err_out:
sdmac->status = DMA_ERROR;
return NULL;
}
static int sdma_config(struct dma_chan *chan,
struct dma_slave_config *dmaengine_cfg)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
if (dmaengine_cfg->direction == DMA_DEV_TO_MEM) {
sdmac->per_address = dmaengine_cfg->src_addr;
sdmac->watermark_level = dmaengine_cfg->src_maxburst *
dmaengine_cfg->src_addr_width;
sdmac->word_size = dmaengine_cfg->src_addr_width;
} else if (dmaengine_cfg->direction == DMA_DEV_TO_DEV) {
sdmac->per_address2 = dmaengine_cfg->src_addr;
sdmac->per_address = dmaengine_cfg->dst_addr;
sdmac->watermark_level = dmaengine_cfg->src_maxburst &
SDMA_WATERMARK_LEVEL_LWML;
sdmac->watermark_level |= (dmaengine_cfg->dst_maxburst << 16) &
SDMA_WATERMARK_LEVEL_HWML;
sdmac->word_size = dmaengine_cfg->dst_addr_width;
} else {
sdmac->per_address = dmaengine_cfg->dst_addr;
sdmac->watermark_level = dmaengine_cfg->dst_maxburst *
dmaengine_cfg->dst_addr_width;
sdmac->word_size = dmaengine_cfg->dst_addr_width;
}
sdmac->direction = dmaengine_cfg->direction;
return sdma_config_channel(chan);
}
static enum dma_status sdma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
u32 residue;
if (sdmac->flags & IMX_DMA_SG_LOOP)
residue = (sdmac->num_bd - sdmac->buf_ptail) *
sdmac->period_len - sdmac->chn_real_count;
else
residue = sdmac->chn_count - sdmac->chn_real_count;
dma_set_tx_state(txstate, chan->completed_cookie, chan->cookie,
residue);
return sdmac->status;
}
static void sdma_issue_pending(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
if (sdmac->status == DMA_IN_PROGRESS)
sdma_enable_channel(sdma, sdmac->channel);
}
static void sdma_add_scripts(struct sdma_engine *sdma,
const struct sdma_script_start_addrs *addr)
{
s32 *addr_arr = (u32 *)addr;
s32 *saddr_arr = (u32 *)sdma->script_addrs;
int i;
if (!sdma->script_number)
sdma->script_number = SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1;
for (i = 0; i < sdma->script_number; i++)
if (addr_arr[i] > 0)
saddr_arr[i] = addr_arr[i];
}
static void sdma_load_firmware(const struct firmware *fw, void *context)
{
struct sdma_engine *sdma = context;
const struct sdma_firmware_header *header;
const struct sdma_script_start_addrs *addr;
unsigned short *ram_code;
if (!fw) {
dev_info(sdma->dev, "external firmware not found, using ROM firmware\n");
return;
}
if (fw->size < sizeof(*header))
goto err_firmware;
header = (struct sdma_firmware_header *)fw->data;
if (header->magic != SDMA_FIRMWARE_MAGIC)
goto err_firmware;
if (header->ram_code_start + header->ram_code_size > fw->size)
goto err_firmware;
switch (header->version_major) {
case 1:
sdma->script_number = SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1;
break;
case 2:
sdma->script_number = SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V2;
break;
case 3:
sdma->script_number = SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V3;
break;
case 4:
sdma->script_number = SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V4;
break;
default:
dev_err(sdma->dev, "unknown firmware version\n");
goto err_firmware;
}
addr = (void *)header + header->script_addrs_start;
ram_code = (void *)header + header->ram_code_start;
clk_enable(sdma->clk_ipg);
clk_enable(sdma->clk_ahb);
sdma_load_script(sdma, ram_code,
header->ram_code_size,
addr->ram_code_start_addr);
clk_disable(sdma->clk_ipg);
clk_disable(sdma->clk_ahb);
sdma_add_scripts(sdma, addr);
dev_info(sdma->dev, "loaded firmware %d.%d\n",
header->version_major,
header->version_minor);
err_firmware:
release_firmware(fw);
}
static int sdma_event_remap(struct sdma_engine *sdma)
{
struct device_node *np = sdma->dev->of_node;
struct device_node *gpr_np = of_parse_phandle(np, "gpr", 0);
struct property *event_remap;
struct regmap *gpr;
char propname[] = "fsl,sdma-event-remap";
u32 reg, val, shift, num_map, i;
int ret = 0;
if (IS_ERR(np) || IS_ERR(gpr_np))
goto out;
event_remap = of_find_property(np, propname, NULL);
num_map = event_remap ? (event_remap->length / sizeof(u32)) : 0;
if (!num_map) {
dev_dbg(sdma->dev, "no event needs to be remapped\n");
goto out;
} else if (num_map % EVENT_REMAP_CELLS) {
dev_err(sdma->dev, "the property %s must modulo %d\n",
propname, EVENT_REMAP_CELLS);
ret = -EINVAL;
goto out;
}
gpr = syscon_node_to_regmap(gpr_np);
if (IS_ERR(gpr)) {
dev_err(sdma->dev, "failed to get gpr regmap\n");
ret = PTR_ERR(gpr);
goto out;
}
for (i = 0; i < num_map; i += EVENT_REMAP_CELLS) {
ret = of_property_read_u32_index(np, propname, i, &reg);
if (ret) {
dev_err(sdma->dev, "failed to read property %s index %d\n",
propname, i);
goto out;
}
ret = of_property_read_u32_index(np, propname, i + 1, &shift);
if (ret) {
dev_err(sdma->dev, "failed to read property %s index %d\n",
propname, i + 1);
goto out;
}
ret = of_property_read_u32_index(np, propname, i + 2, &val);
if (ret) {
dev_err(sdma->dev, "failed to read property %s index %d\n",
propname, i + 2);
goto out;
}
regmap_update_bits(gpr, reg, BIT(shift), val << shift);
}
out:
if (!IS_ERR(gpr_np))
of_node_put(gpr_np);
return ret;
}
static int sdma_get_firmware(struct sdma_engine *sdma,
const char *fw_name)
{
int ret;
ret = request_firmware_nowait(THIS_MODULE,
FW_ACTION_HOTPLUG, fw_name, sdma->dev,
GFP_KERNEL, sdma, sdma_load_firmware);
return ret;
}
static int sdma_init(struct sdma_engine *sdma)
{
int i, ret;
dma_addr_t ccb_phys;
ret = clk_enable(sdma->clk_ipg);
if (ret)
return ret;
ret = clk_enable(sdma->clk_ahb);
if (ret)
goto disable_clk_ipg;
writel_relaxed(0, sdma->regs + SDMA_H_C0PTR);
sdma->channel_control = dma_alloc_coherent(NULL,
MAX_DMA_CHANNELS * sizeof (struct sdma_channel_control) +
sizeof(struct sdma_context_data),
&ccb_phys, GFP_KERNEL);
if (!sdma->channel_control) {
ret = -ENOMEM;
goto err_dma_alloc;
}
sdma->context = (void *)sdma->channel_control +
MAX_DMA_CHANNELS * sizeof (struct sdma_channel_control);
sdma->context_phys = ccb_phys +
MAX_DMA_CHANNELS * sizeof (struct sdma_channel_control);
memset(sdma->channel_control, 0,
MAX_DMA_CHANNELS * sizeof (struct sdma_channel_control));
for (i = 0; i < sdma->drvdata->num_events; i++)
writel_relaxed(0, sdma->regs + chnenbl_ofs(sdma, i));
for (i = 0; i < MAX_DMA_CHANNELS; i++)
writel_relaxed(0, sdma->regs + SDMA_CHNPRI_0 + i * 4);
ret = sdma_request_channel(&sdma->channel[0]);
if (ret)
goto err_dma_alloc;
sdma_config_ownership(&sdma->channel[0], false, true, false);
writel_relaxed(0x4050, sdma->regs + SDMA_CHN0ADDR);
writel_relaxed(0, sdma->regs + SDMA_H_CONFIG);
writel_relaxed(ccb_phys, sdma->regs + SDMA_H_C0PTR);
sdma_set_channel_priority(&sdma->channel[0], 7);
clk_disable(sdma->clk_ipg);
clk_disable(sdma->clk_ahb);
return 0;
err_dma_alloc:
clk_disable(sdma->clk_ahb);
disable_clk_ipg:
clk_disable(sdma->clk_ipg);
dev_err(sdma->dev, "initialisation failed with %d\n", ret);
return ret;
}
static bool sdma_filter_fn(struct dma_chan *chan, void *fn_param)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct imx_dma_data *data = fn_param;
if (!imx_dma_is_general_purpose(chan))
return false;
sdmac->data = *data;
chan->private = &sdmac->data;
return true;
}
static struct dma_chan *sdma_xlate(struct of_phandle_args *dma_spec,
struct of_dma *ofdma)
{
struct sdma_engine *sdma = ofdma->of_dma_data;
dma_cap_mask_t mask = sdma->dma_device.cap_mask;
struct imx_dma_data data;
if (dma_spec->args_count != 3)
return NULL;
data.dma_request = dma_spec->args[0];
data.peripheral_type = dma_spec->args[1];
data.priority = dma_spec->args[2];
data.dma_request2 = 0;
return dma_request_channel(mask, sdma_filter_fn, &data);
}
static int sdma_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(sdma_dt_ids, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
struct device_node *spba_bus;
const char *fw_name;
int ret;
int irq;
struct resource *iores;
struct resource spba_res;
struct sdma_platform_data *pdata = dev_get_platdata(&pdev->dev);
int i;
struct sdma_engine *sdma;
s32 *saddr_arr;
const struct sdma_driver_data *drvdata = NULL;
if (of_id)
drvdata = of_id->data;
else if (pdev->id_entry)
drvdata = (void *)pdev->id_entry->driver_data;
if (!drvdata) {
dev_err(&pdev->dev, "unable to find driver data\n");
return -EINVAL;
}
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
sdma = devm_kzalloc(&pdev->dev, sizeof(*sdma), GFP_KERNEL);
if (!sdma)
return -ENOMEM;
spin_lock_init(&sdma->channel_0_lock);
sdma->dev = &pdev->dev;
sdma->drvdata = drvdata;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sdma->regs = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(sdma->regs))
return PTR_ERR(sdma->regs);
sdma->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(sdma->clk_ipg))
return PTR_ERR(sdma->clk_ipg);
sdma->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(sdma->clk_ahb))
return PTR_ERR(sdma->clk_ahb);
clk_prepare(sdma->clk_ipg);
clk_prepare(sdma->clk_ahb);
ret = devm_request_irq(&pdev->dev, irq, sdma_int_handler, 0, "sdma",
sdma);
if (ret)
return ret;
sdma->irq = irq;
sdma->script_addrs = kzalloc(sizeof(*sdma->script_addrs), GFP_KERNEL);
if (!sdma->script_addrs)
return -ENOMEM;
saddr_arr = (s32 *)sdma->script_addrs;
for (i = 0; i < SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1; i++)
saddr_arr[i] = -EINVAL;
dma_cap_set(DMA_SLAVE, sdma->dma_device.cap_mask);
dma_cap_set(DMA_CYCLIC, sdma->dma_device.cap_mask);
INIT_LIST_HEAD(&sdma->dma_device.channels);
for (i = 0; i < MAX_DMA_CHANNELS; i++) {
struct sdma_channel *sdmac = &sdma->channel[i];
sdmac->sdma = sdma;
spin_lock_init(&sdmac->lock);
sdmac->chan.device = &sdma->dma_device;
dma_cookie_init(&sdmac->chan);
sdmac->channel = i;
tasklet_init(&sdmac->tasklet, mxc_sdma_handle_channel_normal,
(unsigned long) sdmac);
if (i)
list_add_tail(&sdmac->chan.device_node,
&sdma->dma_device.channels);
}
ret = sdma_init(sdma);
if (ret)
goto err_init;
ret = sdma_event_remap(sdma);
if (ret)
goto err_init;
if (sdma->drvdata->script_addrs)
sdma_add_scripts(sdma, sdma->drvdata->script_addrs);
if (pdata && pdata->script_addrs)
sdma_add_scripts(sdma, pdata->script_addrs);
if (pdata) {
ret = sdma_get_firmware(sdma, pdata->fw_name);
if (ret)
dev_warn(&pdev->dev, "failed to get firmware from platform data\n");
} else {
ret = of_property_read_string(np, "fsl,sdma-ram-script-name",
&fw_name);
if (ret)
dev_warn(&pdev->dev, "failed to get firmware name\n");
else {
ret = sdma_get_firmware(sdma, fw_name);
if (ret)
dev_warn(&pdev->dev, "failed to get firmware from device tree\n");
}
}
sdma->dma_device.dev = &pdev->dev;
sdma->dma_device.device_alloc_chan_resources = sdma_alloc_chan_resources;
sdma->dma_device.device_free_chan_resources = sdma_free_chan_resources;
sdma->dma_device.device_tx_status = sdma_tx_status;
sdma->dma_device.device_prep_slave_sg = sdma_prep_slave_sg;
sdma->dma_device.device_prep_dma_cyclic = sdma_prep_dma_cyclic;
sdma->dma_device.device_config = sdma_config;
sdma->dma_device.device_terminate_all = sdma_disable_channel_with_delay;
sdma->dma_device.src_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
sdma->dma_device.dst_addr_widths = BIT(DMA_SLAVE_BUSWIDTH_4_BYTES);
sdma->dma_device.directions = BIT(DMA_DEV_TO_MEM) | BIT(DMA_MEM_TO_DEV);
sdma->dma_device.residue_granularity = DMA_RESIDUE_GRANULARITY_SEGMENT;
sdma->dma_device.device_issue_pending = sdma_issue_pending;
sdma->dma_device.dev->dma_parms = &sdma->dma_parms;
dma_set_max_seg_size(sdma->dma_device.dev, 65535);
platform_set_drvdata(pdev, sdma);
ret = dma_async_device_register(&sdma->dma_device);
if (ret) {
dev_err(&pdev->dev, "unable to register\n");
goto err_init;
}
if (np) {
ret = of_dma_controller_register(np, sdma_xlate, sdma);
if (ret) {
dev_err(&pdev->dev, "failed to register controller\n");
goto err_register;
}
spba_bus = of_find_compatible_node(NULL, NULL, "fsl,spba-bus");
ret = of_address_to_resource(spba_bus, 0, &spba_res);
if (!ret) {
sdma->spba_start_addr = spba_res.start;
sdma->spba_end_addr = spba_res.end;
}
of_node_put(spba_bus);
}
return 0;
err_register:
dma_async_device_unregister(&sdma->dma_device);
err_init:
kfree(sdma->script_addrs);
return ret;
}
static int sdma_remove(struct platform_device *pdev)
{
struct sdma_engine *sdma = platform_get_drvdata(pdev);
int i;
devm_free_irq(&pdev->dev, sdma->irq, sdma);
dma_async_device_unregister(&sdma->dma_device);
kfree(sdma->script_addrs);
for (i = 0; i < MAX_DMA_CHANNELS; i++) {
struct sdma_channel *sdmac = &sdma->channel[i];
tasklet_kill(&sdmac->tasklet);
}
platform_set_drvdata(pdev, NULL);
return 0;
}
