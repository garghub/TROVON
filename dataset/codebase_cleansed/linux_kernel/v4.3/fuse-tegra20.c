static u32 tegra20_fuse_read_early(struct tegra_fuse *fuse, unsigned int offset)
{
return readl_relaxed(fuse->base + FUSE_BEGIN + offset);
}
static void apb_dma_complete(void *args)
{
struct tegra_fuse *fuse = args;
complete(&fuse->apbdma.wait);
}
static u32 tegra20_fuse_read(struct tegra_fuse *fuse, unsigned int offset)
{
unsigned long flags = DMA_PREP_INTERRUPT | DMA_CTRL_ACK;
struct dma_async_tx_descriptor *dma_desc;
unsigned long time_left;
u32 value = 0;
int err;
mutex_lock(&fuse->apbdma.lock);
fuse->apbdma.config.src_addr = fuse->apbdma.phys + FUSE_BEGIN + offset;
err = dmaengine_slave_config(fuse->apbdma.chan, &fuse->apbdma.config);
if (err)
goto out;
dma_desc = dmaengine_prep_slave_single(fuse->apbdma.chan,
fuse->apbdma.phys,
sizeof(u32), DMA_DEV_TO_MEM,
flags);
if (!dma_desc)
goto out;
dma_desc->callback = apb_dma_complete;
dma_desc->callback_param = fuse;
reinit_completion(&fuse->apbdma.wait);
clk_prepare_enable(fuse->clk);
dmaengine_submit(dma_desc);
dma_async_issue_pending(fuse->apbdma.chan);
time_left = wait_for_completion_timeout(&fuse->apbdma.wait,
msecs_to_jiffies(50));
if (WARN(time_left == 0, "apb read dma timed out"))
dmaengine_terminate_all(fuse->apbdma.chan);
else
value = *fuse->apbdma.virt;
clk_disable_unprepare(fuse->clk);
out:
mutex_unlock(&fuse->apbdma.lock);
return value;
}
static int tegra20_fuse_probe(struct tegra_fuse *fuse)
{
dma_cap_mask_t mask;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
fuse->apbdma.chan = dma_request_channel(mask, NULL, NULL);
if (!fuse->apbdma.chan)
return -EPROBE_DEFER;
fuse->apbdma.virt = dma_alloc_coherent(fuse->dev, sizeof(u32),
&fuse->apbdma.phys,
GFP_KERNEL);
if (!fuse->apbdma.virt) {
dma_release_channel(fuse->apbdma.chan);
return -ENOMEM;
}
fuse->apbdma.config.src_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
fuse->apbdma.config.dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
fuse->apbdma.config.src_maxburst = 1;
fuse->apbdma.config.dst_maxburst = 1;
init_completion(&fuse->apbdma.wait);
mutex_init(&fuse->apbdma.lock);
fuse->read = tegra20_fuse_read;
return 0;
}
static void __init tegra20_fuse_add_randomness(void)
{
u32 randomness[7];
randomness[0] = tegra_sku_info.sku_id;
randomness[1] = tegra_read_straps();
randomness[2] = tegra_read_chipid();
randomness[3] = tegra_sku_info.cpu_process_id << 16;
randomness[3] |= tegra_sku_info.soc_process_id;
randomness[4] = tegra_sku_info.cpu_speedo_id << 16;
randomness[4] |= tegra_sku_info.soc_speedo_id;
randomness[5] = tegra_fuse_read_early(FUSE_UID_LOW);
randomness[6] = tegra_fuse_read_early(FUSE_UID_HIGH);
add_device_randomness(randomness, sizeof(randomness));
}
static void __init tegra20_fuse_init(struct tegra_fuse *fuse)
{
fuse->read_early = tegra20_fuse_read_early;
tegra_init_revision();
fuse->soc->speedo_init(&tegra_sku_info);
tegra20_fuse_add_randomness();
}
