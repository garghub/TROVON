static void
renesas_sdhi_internal_dmac_dm_write(struct tmio_mmc_host *host,
int addr, u64 val)
{
writeq(val, host->ctl + addr);
}
static void
renesas_sdhi_internal_dmac_enable_dma(struct tmio_mmc_host *host, bool enable)
{
if (!host->chan_tx || !host->chan_rx)
return;
if (!enable)
renesas_sdhi_internal_dmac_dm_write(host, DM_CM_INFO1,
INFO1_CLEAR);
if (host->dma->enable)
host->dma->enable(host, enable);
}
static void
renesas_sdhi_internal_dmac_abort_dma(struct tmio_mmc_host *host) {
u64 val = RST_DTRANRST1 | RST_DTRANRST0;
renesas_sdhi_internal_dmac_enable_dma(host, false);
renesas_sdhi_internal_dmac_dm_write(host, DM_CM_RST,
RST_RESERVED_BITS & ~val);
renesas_sdhi_internal_dmac_dm_write(host, DM_CM_RST,
RST_RESERVED_BITS | val);
renesas_sdhi_internal_dmac_enable_dma(host, true);
}
static void
renesas_sdhi_internal_dmac_dataend_dma(struct tmio_mmc_host *host) {
tasklet_schedule(&host->dma_complete);
}
static void
renesas_sdhi_internal_dmac_start_dma(struct tmio_mmc_host *host,
struct mmc_data *data)
{
struct scatterlist *sg = host->sg_ptr;
u32 dtran_mode = DTRAN_MODE_BUS_WID_TH | DTRAN_MODE_ADDR_MODE;
enum dma_data_direction dir;
int ret;
u32 irq_mask;
WARN_ON(host->sg_len > 1);
if (!IS_ALIGNED(sg->offset, 8))
goto force_pio;
if (data->flags & MMC_DATA_READ) {
dtran_mode |= DTRAN_MODE_CH_NUM_CH1;
dir = DMA_FROM_DEVICE;
irq_mask = TMIO_STAT_RXRDY;
} else {
dtran_mode |= DTRAN_MODE_CH_NUM_CH0;
dir = DMA_TO_DEVICE;
irq_mask = TMIO_STAT_TXRQ;
}
ret = dma_map_sg(&host->pdev->dev, sg, host->sg_len, dir);
if (ret == 0)
goto force_pio;
renesas_sdhi_internal_dmac_enable_dma(host, true);
tmio_mmc_disable_mmc_irqs(host, irq_mask);
renesas_sdhi_internal_dmac_dm_write(host, DM_CM_DTRAN_MODE,
dtran_mode);
renesas_sdhi_internal_dmac_dm_write(host, DM_DTRAN_ADDR,
sg->dma_address);
return;
force_pio:
host->force_pio = true;
renesas_sdhi_internal_dmac_enable_dma(host, false);
}
static void renesas_sdhi_internal_dmac_issue_tasklet_fn(unsigned long arg)
{
struct tmio_mmc_host *host = (struct tmio_mmc_host *)arg;
tmio_mmc_enable_mmc_irqs(host, TMIO_STAT_DATAEND);
renesas_sdhi_internal_dmac_dm_write(host, DM_CM_DTRAN_CTRL,
DTRAN_CTRL_DM_START);
}
static void renesas_sdhi_internal_dmac_complete_tasklet_fn(unsigned long arg)
{
struct tmio_mmc_host *host = (struct tmio_mmc_host *)arg;
enum dma_data_direction dir;
spin_lock_irq(&host->lock);
if (!host->data)
goto out;
if (host->data->flags & MMC_DATA_READ)
dir = DMA_FROM_DEVICE;
else
dir = DMA_TO_DEVICE;
renesas_sdhi_internal_dmac_enable_dma(host, false);
dma_unmap_sg(&host->pdev->dev, host->sg_ptr, host->sg_len, dir);
tmio_mmc_do_data_irq(host);
out:
spin_unlock_irq(&host->lock);
}
static void
renesas_sdhi_internal_dmac_request_dma(struct tmio_mmc_host *host,
struct tmio_mmc_data *pdata)
{
host->chan_rx = host->chan_tx = (void *)0xdeadbeaf;
tasklet_init(&host->dma_complete,
renesas_sdhi_internal_dmac_complete_tasklet_fn,
(unsigned long)host);
tasklet_init(&host->dma_issue,
renesas_sdhi_internal_dmac_issue_tasklet_fn,
(unsigned long)host);
}
static void
renesas_sdhi_internal_dmac_release_dma(struct tmio_mmc_host *host)
{
host->chan_rx = host->chan_tx = NULL;
}
static int renesas_sdhi_internal_dmac_probe(struct platform_device *pdev)
{
if (!soc_device_match(gen3_soc_whitelist))
return -ENODEV;
return renesas_sdhi_probe(pdev, &renesas_sdhi_internal_dmac_dma_ops);
}
