static inline u32 chnenbl_ofs(struct sdma_engine *sdma, unsigned int event)
{
u32 chnenbl0 = (sdma->devtype == IMX31_SDMA ? SDMA_CHNENBL0_IMX31 :
SDMA_CHNENBL0_IMX35);
return chnenbl0 + event * 4;
}
static int sdma_config_ownership(struct sdma_channel *sdmac,
bool event_override, bool mcu_override, bool dsp_override)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
u32 evt, mcu, dsp;
if (event_override && mcu_override && dsp_override)
return -EINVAL;
evt = __raw_readl(sdma->regs + SDMA_H_EVTOVR);
mcu = __raw_readl(sdma->regs + SDMA_H_HOSTOVR);
dsp = __raw_readl(sdma->regs + SDMA_H_DSPOVR);
if (dsp_override)
dsp &= ~(1 << channel);
else
dsp |= (1 << channel);
if (event_override)
evt &= ~(1 << channel);
else
evt |= (1 << channel);
if (mcu_override)
mcu &= ~(1 << channel);
else
mcu |= (1 << channel);
__raw_writel(evt, sdma->regs + SDMA_H_EVTOVR);
__raw_writel(mcu, sdma->regs + SDMA_H_HOSTOVR);
__raw_writel(dsp, sdma->regs + SDMA_H_DSPOVR);
return 0;
}
static int sdma_run_channel(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
int ret;
init_completion(&sdmac->done);
__raw_writel(1 << channel, sdma->regs + SDMA_H_START);
ret = wait_for_completion_timeout(&sdmac->done, HZ);
return ret ? 0 : -ETIMEDOUT;
}
static int sdma_load_script(struct sdma_engine *sdma, void *buf, int size,
u32 address)
{
struct sdma_buffer_descriptor *bd0 = sdma->channel[0].bd;
void *buf_virt;
dma_addr_t buf_phys;
int ret;
buf_virt = dma_alloc_coherent(NULL,
size,
&buf_phys, GFP_KERNEL);
if (!buf_virt)
return -ENOMEM;
bd0->mode.command = C0_SETPM;
bd0->mode.status = BD_DONE | BD_INTR | BD_WRAP | BD_EXTD;
bd0->mode.count = size / 2;
bd0->buffer_addr = buf_phys;
bd0->ext_buffer_addr = address;
memcpy(buf_virt, buf, size);
ret = sdma_run_channel(&sdma->channel[0]);
dma_free_coherent(NULL, size, buf_virt, buf_phys);
return ret;
}
static void sdma_event_enable(struct sdma_channel *sdmac, unsigned int event)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
u32 val;
u32 chnenbl = chnenbl_ofs(sdma, event);
val = __raw_readl(sdma->regs + chnenbl);
val |= (1 << channel);
__raw_writel(val, sdma->regs + chnenbl);
}
static void sdma_event_disable(struct sdma_channel *sdmac, unsigned int event)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
u32 chnenbl = chnenbl_ofs(sdma, event);
u32 val;
val = __raw_readl(sdma->regs + chnenbl);
val &= ~(1 << channel);
__raw_writel(val, sdma->regs + chnenbl);
}
static void sdma_handle_channel_loop(struct sdma_channel *sdmac)
{
struct sdma_buffer_descriptor *bd;
while (1) {
bd = &sdmac->bd[sdmac->buf_tail];
if (bd->mode.status & BD_DONE)
break;
if (bd->mode.status & BD_RROR)
sdmac->status = DMA_ERROR;
else
sdmac->status = DMA_IN_PROGRESS;
bd->mode.status |= BD_DONE;
sdmac->buf_tail++;
sdmac->buf_tail %= sdmac->num_bd;
if (sdmac->desc.callback)
sdmac->desc.callback(sdmac->desc.callback_param);
}
}
static void mxc_sdma_handle_channel_normal(struct sdma_channel *sdmac)
{
struct sdma_buffer_descriptor *bd;
int i, error = 0;
for (i = 0; i < sdmac->num_bd; i++) {
bd = &sdmac->bd[i];
if (bd->mode.status & (BD_DONE | BD_RROR))
error = -EIO;
}
if (error)
sdmac->status = DMA_ERROR;
else
sdmac->status = DMA_SUCCESS;
if (sdmac->desc.callback)
sdmac->desc.callback(sdmac->desc.callback_param);
sdmac->last_completed = sdmac->desc.cookie;
}
static void mxc_sdma_handle_channel(struct sdma_channel *sdmac)
{
complete(&sdmac->done);
if (sdmac->channel == 0)
return;
if (sdmac->flags & IMX_DMA_SG_LOOP)
sdma_handle_channel_loop(sdmac);
else
mxc_sdma_handle_channel_normal(sdmac);
}
static irqreturn_t sdma_int_handler(int irq, void *dev_id)
{
struct sdma_engine *sdma = dev_id;
u32 stat;
stat = __raw_readl(sdma->regs + SDMA_H_INTR);
__raw_writel(stat, sdma->regs + SDMA_H_INTR);
while (stat) {
int channel = fls(stat) - 1;
struct sdma_channel *sdmac = &sdma->channel[channel];
mxc_sdma_handle_channel(sdmac);
stat &= ~(1 << channel);
}
return IRQ_HANDLED;
}
static void sdma_get_pc(struct sdma_channel *sdmac,
enum sdma_peripheral_type peripheral_type)
{
struct sdma_engine *sdma = sdmac->sdma;
int per_2_emi = 0, emi_2_per = 0;
int per_2_per = 0, emi_2_emi = 0;
sdmac->pc_from_device = 0;
sdmac->pc_to_device = 0;
switch (peripheral_type) {
case IMX_DMATYPE_MEMORY:
emi_2_emi = sdma->script_addrs->ap_2_ap_addr;
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
per_2_emi = sdma->script_addrs->app_2_mcu_addr;
emi_2_per = sdma->script_addrs->mcu_2_app_addr;
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
}
static int sdma_load_context(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
int load_address;
struct sdma_context_data *context = sdma->context;
struct sdma_buffer_descriptor *bd0 = sdma->channel[0].bd;
int ret;
if (sdmac->direction == DMA_FROM_DEVICE) {
load_address = sdmac->pc_from_device;
} else {
load_address = sdmac->pc_to_device;
}
if (load_address < 0)
return load_address;
dev_dbg(sdma->dev, "load_address = %d\n", load_address);
dev_dbg(sdma->dev, "wml = 0x%08x\n", sdmac->watermark_level);
dev_dbg(sdma->dev, "shp_addr = 0x%08x\n", sdmac->shp_addr);
dev_dbg(sdma->dev, "per_addr = 0x%08x\n", sdmac->per_addr);
dev_dbg(sdma->dev, "event_mask0 = 0x%08x\n", sdmac->event_mask0);
dev_dbg(sdma->dev, "event_mask1 = 0x%08x\n", sdmac->event_mask1);
memset(context, 0, sizeof(*context));
context->channel_state.pc = load_address;
context->gReg[0] = sdmac->event_mask1;
context->gReg[1] = sdmac->event_mask0;
context->gReg[2] = sdmac->per_addr;
context->gReg[6] = sdmac->shp_addr;
context->gReg[7] = sdmac->watermark_level;
bd0->mode.command = C0_SETDM;
bd0->mode.status = BD_DONE | BD_INTR | BD_WRAP | BD_EXTD;
bd0->mode.count = sizeof(*context) / 4;
bd0->buffer_addr = sdma->context_phys;
bd0->ext_buffer_addr = 2048 + (sizeof(*context) / 4) * channel;
ret = sdma_run_channel(&sdma->channel[0]);
return ret;
}
static void sdma_disable_channel(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
__raw_writel(1 << channel, sdma->regs + SDMA_H_STATSTOP);
sdmac->status = DMA_ERROR;
}
static int sdma_config_channel(struct sdma_channel *sdmac)
{
int ret;
sdma_disable_channel(sdmac);
sdmac->event_mask0 = 0;
sdmac->event_mask1 = 0;
sdmac->shp_addr = 0;
sdmac->per_addr = 0;
if (sdmac->event_id0) {
if (sdmac->event_id0 > 32)
return -EINVAL;
sdma_event_enable(sdmac, sdmac->event_id0);
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
sdmac->event_mask1 = 1 << (sdmac->event_id1 % 32);
if (sdmac->event_id1 > 31)
sdmac->watermark_level |= 1 << 31;
sdmac->event_mask0 = 1 << (sdmac->event_id0 % 32);
if (sdmac->event_id0 > 31)
sdmac->watermark_level |= 1 << 30;
} else {
sdmac->event_mask0 = 1 << sdmac->event_id0;
sdmac->event_mask1 = 1 << (sdmac->event_id0 - 32);
}
sdmac->watermark_level |= sdmac->watermark_level;
sdmac->shp_addr = sdmac->per_address;
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
__raw_writel(priority, sdma->regs + SDMA_CHNPRI_0 + 4 * channel);
return 0;
}
static int sdma_request_channel(struct sdma_channel *sdmac)
{
struct sdma_engine *sdma = sdmac->sdma;
int channel = sdmac->channel;
int ret = -EBUSY;
sdmac->bd = dma_alloc_coherent(NULL, PAGE_SIZE, &sdmac->bd_phys, GFP_KERNEL);
if (!sdmac->bd) {
ret = -ENOMEM;
goto out;
}
memset(sdmac->bd, 0, PAGE_SIZE);
sdma->channel_control[channel].base_bd_ptr = sdmac->bd_phys;
sdma->channel_control[channel].current_bd_ptr = sdmac->bd_phys;
clk_enable(sdma->clk);
sdma_set_channel_priority(sdmac, MXC_SDMA_DEFAULT_PRIORITY);
init_completion(&sdmac->done);
sdmac->buf_tail = 0;
return 0;
out:
return ret;
}
static void sdma_enable_channel(struct sdma_engine *sdma, int channel)
{
__raw_writel(1 << channel, sdma->regs + SDMA_H_START);
}
static dma_cookie_t sdma_assign_cookie(struct sdma_channel *sdmac)
{
dma_cookie_t cookie = sdmac->chan.cookie;
if (++cookie < 0)
cookie = 1;
sdmac->chan.cookie = cookie;
sdmac->desc.cookie = cookie;
return cookie;
}
static struct sdma_channel *to_sdma_chan(struct dma_chan *chan)
{
return container_of(chan, struct sdma_channel, chan);
}
static dma_cookie_t sdma_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct sdma_channel *sdmac = to_sdma_chan(tx->chan);
struct sdma_engine *sdma = sdmac->sdma;
dma_cookie_t cookie;
spin_lock_irq(&sdmac->lock);
cookie = sdma_assign_cookie(sdmac);
sdma_enable_channel(sdma, sdmac->channel);
spin_unlock_irq(&sdmac->lock);
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
ret = sdma_set_channel_priority(sdmac, prio);
if (ret)
return ret;
ret = sdma_request_channel(sdmac);
if (ret)
return ret;
dma_async_tx_descriptor_init(&sdmac->desc, chan);
sdmac->desc.tx_submit = sdma_tx_submit;
sdmac->desc.flags = DMA_CTRL_ACK;
return 0;
}
static void sdma_free_chan_resources(struct dma_chan *chan)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct sdma_engine *sdma = sdmac->sdma;
sdma_disable_channel(sdmac);
if (sdmac->event_id0)
sdma_event_disable(sdmac, sdmac->event_id0);
if (sdmac->event_id1)
sdma_event_disable(sdmac, sdmac->event_id1);
sdmac->event_id0 = 0;
sdmac->event_id1 = 0;
sdma_set_channel_priority(sdmac, 0);
dma_free_coherent(NULL, PAGE_SIZE, sdmac->bd, sdmac->bd_phys);
clk_disable(sdma->clk);
}
static struct dma_async_tx_descriptor *sdma_prep_slave_sg(
struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_data_direction direction,
unsigned long flags)
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
for_each_sg(sgl, sg, sg_len, i) {
struct sdma_buffer_descriptor *bd = &sdmac->bd[i];
int param;
bd->buffer_addr = sg->dma_address;
count = sg->length;
if (count > 0xffff) {
dev_err(sdma->dev, "SDMA channel %d: maximum bytes for sg entry exceeded: %d > %d\n",
channel, count, 0xffff);
ret = -EINVAL;
goto err_out;
}
bd->mode.count = count;
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
dev_dbg(sdma->dev, "entry %d: count: %d dma: 0x%08x %s%s\n",
i, count, sg->dma_address,
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
size_t period_len, enum dma_data_direction direction)
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
dev_dbg(sdma->dev, "entry %d: count: %d dma: 0x%08x %s%s\n",
i, period_len, dma_addr,
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
static int sdma_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd,
unsigned long arg)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
struct dma_slave_config *dmaengine_cfg = (void *)arg;
switch (cmd) {
case DMA_TERMINATE_ALL:
sdma_disable_channel(sdmac);
return 0;
case DMA_SLAVE_CONFIG:
if (dmaengine_cfg->direction == DMA_FROM_DEVICE) {
sdmac->per_address = dmaengine_cfg->src_addr;
sdmac->watermark_level = dmaengine_cfg->src_maxburst;
sdmac->word_size = dmaengine_cfg->src_addr_width;
} else {
sdmac->per_address = dmaengine_cfg->dst_addr;
sdmac->watermark_level = dmaengine_cfg->dst_maxburst;
sdmac->word_size = dmaengine_cfg->dst_addr_width;
}
return sdma_config_channel(sdmac);
default:
return -ENOSYS;
}
return -EINVAL;
}
static enum dma_status sdma_tx_status(struct dma_chan *chan,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct sdma_channel *sdmac = to_sdma_chan(chan);
dma_cookie_t last_used;
last_used = chan->cookie;
dma_set_tx_state(txstate, sdmac->last_completed, last_used, 0);
return sdmac->status;
}
static void sdma_issue_pending(struct dma_chan *chan)
{
}
static void sdma_add_scripts(struct sdma_engine *sdma,
const struct sdma_script_start_addrs *addr)
{
s32 *addr_arr = (u32 *)addr;
s32 *saddr_arr = (u32 *)sdma->script_addrs;
int i;
for (i = 0; i < SDMA_SCRIPT_ADDRS_ARRAY_SIZE_V1; i++)
if (addr_arr[i] > 0)
saddr_arr[i] = addr_arr[i];
}
static int __init sdma_get_firmware(struct sdma_engine *sdma,
const char *fw_name)
{
const struct firmware *fw;
const struct sdma_firmware_header *header;
int ret;
const struct sdma_script_start_addrs *addr;
unsigned short *ram_code;
ret = request_firmware(&fw, fw_name, sdma->dev);
if (ret)
return ret;
if (fw->size < sizeof(*header))
goto err_firmware;
header = (struct sdma_firmware_header *)fw->data;
if (header->magic != SDMA_FIRMWARE_MAGIC)
goto err_firmware;
if (header->ram_code_start + header->ram_code_size > fw->size)
goto err_firmware;
addr = (void *)header + header->script_addrs_start;
ram_code = (void *)header + header->ram_code_start;
clk_enable(sdma->clk);
sdma_load_script(sdma, ram_code,
header->ram_code_size,
addr->ram_code_start_addr);
clk_disable(sdma->clk);
sdma_add_scripts(sdma, addr);
dev_info(sdma->dev, "loaded firmware %d.%d\n",
header->version_major,
header->version_minor);
err_firmware:
release_firmware(fw);
return ret;
}
static int __init sdma_init(struct sdma_engine *sdma)
{
int i, ret;
dma_addr_t ccb_phys;
switch (sdma->devtype) {
case IMX31_SDMA:
sdma->num_events = 32;
break;
case IMX35_SDMA:
sdma->num_events = 48;
break;
default:
dev_err(sdma->dev, "Unknown sdma type %d. aborting\n",
sdma->devtype);
return -ENODEV;
}
clk_enable(sdma->clk);
__raw_writel(0, sdma->regs + SDMA_H_C0PTR);
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
for (i = 0; i < sdma->num_events; i++)
__raw_writel(0, sdma->regs + chnenbl_ofs(sdma, i));
for (i = 0; i < MAX_DMA_CHANNELS; i++)
__raw_writel(0, sdma->regs + SDMA_CHNPRI_0 + i * 4);
ret = sdma_request_channel(&sdma->channel[0]);
if (ret)
goto err_dma_alloc;
sdma_config_ownership(&sdma->channel[0], false, true, false);
__raw_writel(0x4050, sdma->regs + SDMA_CHN0ADDR);
__raw_writel(0, sdma->regs + SDMA_H_CONFIG);
__raw_writel(ccb_phys, sdma->regs + SDMA_H_C0PTR);
__raw_writel(SDMA_H_CONFIG_CSM, sdma->regs + SDMA_H_CONFIG);
sdma_set_channel_priority(&sdma->channel[0], 7);
clk_disable(sdma->clk);
return 0;
err_dma_alloc:
clk_disable(sdma->clk);
dev_err(sdma->dev, "initialisation failed with %d\n", ret);
return ret;
}
static int __init sdma_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(sdma_dt_ids, &pdev->dev);
struct device_node *np = pdev->dev.of_node;
const char *fw_name;
int ret;
int irq;
struct resource *iores;
struct sdma_platform_data *pdata = pdev->dev.platform_data;
int i;
struct sdma_engine *sdma;
sdma = kzalloc(sizeof(*sdma), GFP_KERNEL);
if (!sdma)
return -ENOMEM;
sdma->dev = &pdev->dev;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!iores || irq < 0) {
ret = -EINVAL;
goto err_irq;
}
if (!request_mem_region(iores->start, resource_size(iores), pdev->name)) {
ret = -EBUSY;
goto err_request_region;
}
sdma->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(sdma->clk)) {
ret = PTR_ERR(sdma->clk);
goto err_clk;
}
sdma->regs = ioremap(iores->start, resource_size(iores));
if (!sdma->regs) {
ret = -ENOMEM;
goto err_ioremap;
}
ret = request_irq(irq, sdma_int_handler, 0, "sdma", sdma);
if (ret)
goto err_request_irq;
sdma->script_addrs = kzalloc(sizeof(*sdma->script_addrs), GFP_KERNEL);
if (!sdma->script_addrs) {
ret = -ENOMEM;
goto err_alloc;
}
if (of_id)
pdev->id_entry = of_id->data;
sdma->devtype = pdev->id_entry->driver_data;
dma_cap_set(DMA_SLAVE, sdma->dma_device.cap_mask);
dma_cap_set(DMA_CYCLIC, sdma->dma_device.cap_mask);
INIT_LIST_HEAD(&sdma->dma_device.channels);
for (i = 0; i < MAX_DMA_CHANNELS; i++) {
struct sdma_channel *sdmac = &sdma->channel[i];
sdmac->sdma = sdma;
spin_lock_init(&sdmac->lock);
sdmac->chan.device = &sdma->dma_device;
sdmac->channel = i;
if (i)
list_add_tail(&sdmac->chan.device_node,
&sdma->dma_device.channels);
}
ret = sdma_init(sdma);
if (ret)
goto err_init;
if (pdata && pdata->script_addrs)
sdma_add_scripts(sdma, pdata->script_addrs);
if (pdata) {
sdma_get_firmware(sdma, pdata->fw_name);
} else {
ret = of_property_read_string(np, "fsl,sdma-ram-script-name",
&fw_name);
if (ret) {
dev_err(&pdev->dev, "failed to get firmware name\n");
goto err_init;
}
ret = sdma_get_firmware(sdma, fw_name);
if (ret) {
dev_err(&pdev->dev, "failed to get firmware\n");
goto err_init;
}
}
sdma->dma_device.dev = &pdev->dev;
sdma->dma_device.device_alloc_chan_resources = sdma_alloc_chan_resources;
sdma->dma_device.device_free_chan_resources = sdma_free_chan_resources;
sdma->dma_device.device_tx_status = sdma_tx_status;
sdma->dma_device.device_prep_slave_sg = sdma_prep_slave_sg;
sdma->dma_device.device_prep_dma_cyclic = sdma_prep_dma_cyclic;
sdma->dma_device.device_control = sdma_control;
sdma->dma_device.device_issue_pending = sdma_issue_pending;
sdma->dma_device.dev->dma_parms = &sdma->dma_parms;
dma_set_max_seg_size(sdma->dma_device.dev, 65535);
ret = dma_async_device_register(&sdma->dma_device);
if (ret) {
dev_err(&pdev->dev, "unable to register\n");
goto err_init;
}
dev_info(sdma->dev, "initialized\n");
return 0;
err_init:
kfree(sdma->script_addrs);
err_alloc:
free_irq(irq, sdma);
err_request_irq:
iounmap(sdma->regs);
err_ioremap:
clk_put(sdma->clk);
err_clk:
release_mem_region(iores->start, resource_size(iores));
err_request_region:
err_irq:
kfree(sdma);
return ret;
}
static int __exit sdma_remove(struct platform_device *pdev)
{
return -EBUSY;
}
static int __init sdma_module_init(void)
{
return platform_driver_probe(&sdma_driver, sdma_probe);
}
