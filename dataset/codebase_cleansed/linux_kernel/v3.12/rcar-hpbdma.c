static void ch_reg_write(struct hpb_dmae_chan *hpb_dc, u32 data, u32 reg)
{
iowrite32(data, hpb_dc->base + reg);
}
static u32 ch_reg_read(struct hpb_dmae_chan *hpb_dc, u32 reg)
{
return ioread32(hpb_dc->base + reg);
}
static void dcmdr_write(struct hpb_dmae_device *hpbdev, u32 data)
{
iowrite32(data, hpbdev->chan_reg + HPB_DMAE_DCMDR);
}
static void hsrstr_write(struct hpb_dmae_device *hpbdev, u32 ch)
{
iowrite32(0x1, hpbdev->comm_reg + HPB_DMAE_HSRSTR(ch));
}
static u32 dintsr_read(struct hpb_dmae_device *hpbdev, u32 ch)
{
u32 v;
if (ch < 32)
v = ioread32(hpbdev->comm_reg + HPB_DMAE_DINTSR0) >> ch;
else
v = ioread32(hpbdev->comm_reg + HPB_DMAE_DINTSR1) >> (ch - 32);
return v & 0x1;
}
static void dintcr_write(struct hpb_dmae_device *hpbdev, u32 ch)
{
if (ch < 32)
iowrite32((0x1 << ch), hpbdev->comm_reg + HPB_DMAE_DINTCR0);
else
iowrite32((0x1 << (ch - 32)),
hpbdev->comm_reg + HPB_DMAE_DINTCR1);
}
static void asyncmdr_write(struct hpb_dmae_device *hpbdev, u32 data)
{
iowrite32(data, hpbdev->mode_reg);
}
static u32 asyncmdr_read(struct hpb_dmae_device *hpbdev)
{
return ioread32(hpbdev->mode_reg);
}
static void hpb_dmae_enable_int(struct hpb_dmae_device *hpbdev, u32 ch)
{
u32 intreg;
spin_lock_irq(&hpbdev->reg_lock);
if (ch < 32) {
intreg = ioread32(hpbdev->comm_reg + HPB_DMAE_DINTMR0);
iowrite32(BIT(ch) | intreg,
hpbdev->comm_reg + HPB_DMAE_DINTMR0);
} else {
intreg = ioread32(hpbdev->comm_reg + HPB_DMAE_DINTMR1);
iowrite32(BIT(ch - 32) | intreg,
hpbdev->comm_reg + HPB_DMAE_DINTMR1);
}
spin_unlock_irq(&hpbdev->reg_lock);
}
static void hpb_dmae_async_reset(struct hpb_dmae_device *hpbdev, u32 data)
{
u32 rstr;
int timeout = 10000;
spin_lock(&hpbdev->reg_lock);
rstr = ioread32(hpbdev->reset_reg);
rstr |= data;
iowrite32(rstr, hpbdev->reset_reg);
do {
rstr = ioread32(hpbdev->reset_reg);
if ((rstr & data) == data)
break;
udelay(10);
} while (timeout--);
if (timeout < 0)
dev_err(hpbdev->shdma_dev.dma_dev.dev,
"%s timeout\n", __func__);
rstr &= ~data;
iowrite32(rstr, hpbdev->reset_reg);
spin_unlock(&hpbdev->reg_lock);
}
static void hpb_dmae_set_async_mode(struct hpb_dmae_device *hpbdev,
u32 mask, u32 data)
{
u32 mode;
spin_lock_irq(&hpbdev->reg_lock);
mode = asyncmdr_read(hpbdev);
mode &= ~mask;
mode |= data;
asyncmdr_write(hpbdev, mode);
spin_unlock_irq(&hpbdev->reg_lock);
}
static void hpb_dmae_ctl_stop(struct hpb_dmae_device *hpbdev)
{
dcmdr_write(hpbdev, HPB_DMAE_DCMDR_DQSPD);
}
static void hpb_dmae_reset(struct hpb_dmae_device *hpbdev)
{
u32 ch;
for (ch = 0; ch < hpbdev->pdata->num_hw_channels; ch++)
hsrstr_write(hpbdev, ch);
}
static unsigned int calc_xmit_shift(struct hpb_dmae_chan *hpb_chan)
{
struct hpb_dmae_device *hpbdev = to_dev(hpb_chan);
struct hpb_dmae_pdata *pdata = hpbdev->pdata;
int width = ch_reg_read(hpb_chan, HPB_DMAE_DCR);
int i;
switch (width & (HPB_DMAE_DCR_SPDS_MASK | HPB_DMAE_DCR_DPDS_MASK)) {
case HPB_DMAE_DCR_SPDS_8BIT | HPB_DMAE_DCR_DPDS_8BIT:
default:
i = XMIT_SZ_8BIT;
break;
case HPB_DMAE_DCR_SPDS_16BIT | HPB_DMAE_DCR_DPDS_16BIT:
i = XMIT_SZ_16BIT;
break;
case HPB_DMAE_DCR_SPDS_32BIT | HPB_DMAE_DCR_DPDS_32BIT:
i = XMIT_SZ_32BIT;
break;
}
return pdata->ts_shift[i];
}
static void hpb_dmae_set_reg(struct hpb_dmae_chan *hpb_chan,
struct hpb_dmae_regs *hw, unsigned plane)
{
ch_reg_write(hpb_chan, hw->sar,
plane ? HPB_DMAE_DSAR1 : HPB_DMAE_DSAR0);
ch_reg_write(hpb_chan, hw->dar,
plane ? HPB_DMAE_DDAR1 : HPB_DMAE_DDAR0);
ch_reg_write(hpb_chan, hw->tcr >> hpb_chan->xmit_shift,
plane ? HPB_DMAE_DTCR1 : HPB_DMAE_DTCR0);
}
static void hpb_dmae_start(struct hpb_dmae_chan *hpb_chan, bool next)
{
ch_reg_write(hpb_chan, (next ? HPB_DMAE_DCMDR_DNXT : 0) |
HPB_DMAE_DCMDR_DMEN, HPB_DMAE_DCMDR);
}
static void hpb_dmae_halt(struct shdma_chan *schan)
{
struct hpb_dmae_chan *chan = to_chan(schan);
ch_reg_write(chan, HPB_DMAE_DCMDR_DQEND, HPB_DMAE_DCMDR);
ch_reg_write(chan, HPB_DMAE_DSTPR_DMSTP, HPB_DMAE_DSTPR);
}
static const struct hpb_dmae_slave_config *
hpb_dmae_find_slave(struct hpb_dmae_chan *hpb_chan, int slave_id)
{
struct hpb_dmae_device *hpbdev = to_dev(hpb_chan);
struct hpb_dmae_pdata *pdata = hpbdev->pdata;
int i;
if (slave_id >= HPB_DMA_SLAVE_NUMBER)
return NULL;
for (i = 0; i < pdata->num_slaves; i++)
if (pdata->slaves[i].id == slave_id)
return pdata->slaves + i;
return NULL;
}
static void hpb_dmae_start_xfer(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
struct hpb_dmae_chan *chan = to_chan(schan);
struct hpb_dmae_device *hpbdev = to_dev(chan);
struct hpb_desc *desc = to_desc(sdesc);
if (chan->cfg->flags & HPB_DMAE_SET_ASYNC_RESET)
hpb_dmae_async_reset(hpbdev, chan->cfg->rstr);
desc->plane_idx = chan->plane_idx;
hpb_dmae_set_reg(chan, &desc->hw, chan->plane_idx);
hpb_dmae_start(chan, !chan->first_desc);
if (chan->xfer_mode == XFER_DOUBLE) {
chan->plane_idx ^= 1;
chan->first_desc = false;
}
}
static bool hpb_dmae_desc_completed(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
return true;
}
static bool hpb_dmae_chan_irq(struct shdma_chan *schan, int irq)
{
struct hpb_dmae_chan *chan = to_chan(schan);
struct hpb_dmae_device *hpbdev = to_dev(chan);
int ch = chan->cfg->dma_ch;
if (dintsr_read(hpbdev, ch)) {
dintcr_write(hpbdev, ch);
return true;
}
return false;
}
static int hpb_dmae_desc_setup(struct shdma_chan *schan,
struct shdma_desc *sdesc,
dma_addr_t src, dma_addr_t dst, size_t *len)
{
struct hpb_desc *desc = to_desc(sdesc);
if (*len > (size_t)HPB_DMA_TCR_MAX)
*len = (size_t)HPB_DMA_TCR_MAX;
desc->hw.sar = src;
desc->hw.dar = dst;
desc->hw.tcr = *len;
return 0;
}
static size_t hpb_dmae_get_partial(struct shdma_chan *schan,
struct shdma_desc *sdesc)
{
struct hpb_desc *desc = to_desc(sdesc);
struct hpb_dmae_chan *chan = to_chan(schan);
u32 tcr = ch_reg_read(chan, desc->plane_idx ?
HPB_DMAE_DTCR1 : HPB_DMAE_DTCR0);
return (desc->hw.tcr - tcr) << chan->xmit_shift;
}
static bool hpb_dmae_channel_busy(struct shdma_chan *schan)
{
struct hpb_dmae_chan *chan = to_chan(schan);
u32 dstsr = ch_reg_read(chan, HPB_DMAE_DSTSR);
return (dstsr & HPB_DMAE_DSTSR_DMSTS) == HPB_DMAE_DSTSR_DMSTS;
}
static int
hpb_dmae_alloc_chan_resources(struct hpb_dmae_chan *hpb_chan,
const struct hpb_dmae_slave_config *cfg)
{
struct hpb_dmae_device *hpbdev = to_dev(hpb_chan);
struct hpb_dmae_pdata *pdata = hpbdev->pdata;
const struct hpb_dmae_channel *channel = pdata->channels;
int slave_id = cfg->id;
int i, err;
for (i = 0; i < pdata->num_channels; i++, channel++) {
if (channel->s_id == slave_id) {
struct device *dev = hpb_chan->shdma_chan.dev;
hpb_chan->base = hpbdev->chan_reg +
HPB_DMAE_CHAN(cfg->dma_ch);
dev_dbg(dev, "Detected Slave device\n");
dev_dbg(dev, " -- slave_id : 0x%x\n", slave_id);
dev_dbg(dev, " -- cfg->dma_ch : %d\n", cfg->dma_ch);
dev_dbg(dev, " -- channel->ch_irq: %d\n",
channel->ch_irq);
break;
}
}
err = shdma_request_irq(&hpb_chan->shdma_chan, channel->ch_irq,
IRQF_SHARED, hpb_chan->dev_id);
if (err) {
dev_err(hpb_chan->shdma_chan.dev,
"DMA channel request_irq %d failed with error %d\n",
channel->ch_irq, err);
return err;
}
hpb_chan->plane_idx = 0;
hpb_chan->first_desc = true;
if ((cfg->dcr & (HPB_DMAE_DCR_CT | HPB_DMAE_DCR_DIP)) == 0) {
hpb_chan->xfer_mode = XFER_SINGLE;
} else if ((cfg->dcr & (HPB_DMAE_DCR_CT | HPB_DMAE_DCR_DIP)) ==
(HPB_DMAE_DCR_CT | HPB_DMAE_DCR_DIP)) {
hpb_chan->xfer_mode = XFER_DOUBLE;
} else {
dev_err(hpb_chan->shdma_chan.dev, "DCR setting error");
return -EINVAL;
}
if (cfg->flags & HPB_DMAE_SET_ASYNC_MODE)
hpb_dmae_set_async_mode(hpbdev, cfg->mdm, cfg->mdr);
ch_reg_write(hpb_chan, cfg->dcr, HPB_DMAE_DCR);
ch_reg_write(hpb_chan, cfg->port, HPB_DMAE_DPTR);
hpb_chan->xmit_shift = calc_xmit_shift(hpb_chan);
hpb_dmae_enable_int(hpbdev, cfg->dma_ch);
return 0;
}
static int hpb_dmae_set_slave(struct shdma_chan *schan, int slave_id,
dma_addr_t slave_addr, bool try)
{
struct hpb_dmae_chan *chan = to_chan(schan);
const struct hpb_dmae_slave_config *sc =
hpb_dmae_find_slave(chan, slave_id);
if (!sc)
return -ENODEV;
if (try)
return 0;
chan->cfg = sc;
chan->slave_addr = slave_addr ? : sc->addr;
return hpb_dmae_alloc_chan_resources(chan, sc);
}
static void hpb_dmae_setup_xfer(struct shdma_chan *schan, int slave_id)
{
}
static dma_addr_t hpb_dmae_slave_addr(struct shdma_chan *schan)
{
struct hpb_dmae_chan *chan = to_chan(schan);
return chan->slave_addr;
}
static struct shdma_desc *hpb_dmae_embedded_desc(void *buf, int i)
{
return &((struct hpb_desc *)buf)[i].shdma_desc;
}
static int hpb_dmae_chan_probe(struct hpb_dmae_device *hpbdev, int id)
{
struct shdma_dev *sdev = &hpbdev->shdma_dev;
struct platform_device *pdev =
to_platform_device(hpbdev->shdma_dev.dma_dev.dev);
struct hpb_dmae_chan *new_hpb_chan;
struct shdma_chan *schan;
new_hpb_chan = devm_kzalloc(&pdev->dev,
sizeof(struct hpb_dmae_chan), GFP_KERNEL);
if (!new_hpb_chan) {
dev_err(hpbdev->shdma_dev.dma_dev.dev,
"No free memory for allocating DMA channels!\n");
return -ENOMEM;
}
schan = &new_hpb_chan->shdma_chan;
shdma_chan_probe(sdev, schan, id);
if (pdev->id >= 0)
snprintf(new_hpb_chan->dev_id, sizeof(new_hpb_chan->dev_id),
"hpb-dmae%d.%d", pdev->id, id);
else
snprintf(new_hpb_chan->dev_id, sizeof(new_hpb_chan->dev_id),
"hpb-dma.%d", id);
return 0;
}
static int hpb_dmae_probe(struct platform_device *pdev)
{
struct hpb_dmae_pdata *pdata = pdev->dev.platform_data;
struct hpb_dmae_device *hpbdev;
struct dma_device *dma_dev;
struct resource *chan, *comm, *rest, *mode, *irq_res;
int err, i;
if (!pdata || !pdata->num_channels)
return -ENODEV;
chan = platform_get_resource(pdev, IORESOURCE_MEM, 0);
comm = platform_get_resource(pdev, IORESOURCE_MEM, 1);
rest = platform_get_resource(pdev, IORESOURCE_MEM, 2);
mode = platform_get_resource(pdev, IORESOURCE_MEM, 3);
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq_res)
return -ENODEV;
hpbdev = devm_kzalloc(&pdev->dev, sizeof(struct hpb_dmae_device),
GFP_KERNEL);
if (!hpbdev) {
dev_err(&pdev->dev, "Not enough memory\n");
return -ENOMEM;
}
hpbdev->chan_reg = devm_ioremap_resource(&pdev->dev, chan);
if (IS_ERR(hpbdev->chan_reg))
return PTR_ERR(hpbdev->chan_reg);
hpbdev->comm_reg = devm_ioremap_resource(&pdev->dev, comm);
if (IS_ERR(hpbdev->comm_reg))
return PTR_ERR(hpbdev->comm_reg);
hpbdev->reset_reg = devm_ioremap_resource(&pdev->dev, rest);
if (IS_ERR(hpbdev->reset_reg))
return PTR_ERR(hpbdev->reset_reg);
hpbdev->mode_reg = devm_ioremap_resource(&pdev->dev, mode);
if (IS_ERR(hpbdev->mode_reg))
return PTR_ERR(hpbdev->mode_reg);
dma_dev = &hpbdev->shdma_dev.dma_dev;
spin_lock_init(&hpbdev->reg_lock);
hpbdev->pdata = pdata;
pm_runtime_enable(&pdev->dev);
err = pm_runtime_get_sync(&pdev->dev);
if (err < 0)
dev_err(&pdev->dev, "%s(): GET = %d\n", __func__, err);
hpb_dmae_reset(hpbdev);
pm_runtime_put(&pdev->dev);
dma_cap_set(DMA_MEMCPY, dma_dev->cap_mask);
dma_cap_set(DMA_SLAVE, dma_dev->cap_mask);
hpbdev->shdma_dev.ops = &hpb_dmae_ops;
hpbdev->shdma_dev.desc_size = sizeof(struct hpb_desc);
err = shdma_init(&pdev->dev, &hpbdev->shdma_dev, pdata->num_channels);
if (err < 0)
goto error;
for (i = 0; i < pdata->num_channels; i++)
hpb_dmae_chan_probe(hpbdev, i);
platform_set_drvdata(pdev, hpbdev);
err = dma_async_device_register(dma_dev);
if (!err)
return 0;
shdma_cleanup(&hpbdev->shdma_dev);
error:
pm_runtime_disable(&pdev->dev);
return err;
}
static void hpb_dmae_chan_remove(struct hpb_dmae_device *hpbdev)
{
struct dma_device *dma_dev = &hpbdev->shdma_dev.dma_dev;
struct shdma_chan *schan;
int i;
shdma_for_each_chan(schan, &hpbdev->shdma_dev, i) {
BUG_ON(!schan);
shdma_chan_remove(schan);
}
dma_dev->chancnt = 0;
}
static int hpb_dmae_remove(struct platform_device *pdev)
{
struct hpb_dmae_device *hpbdev = platform_get_drvdata(pdev);
dma_async_device_unregister(&hpbdev->shdma_dev.dma_dev);
pm_runtime_disable(&pdev->dev);
hpb_dmae_chan_remove(hpbdev);
return 0;
}
static void hpb_dmae_shutdown(struct platform_device *pdev)
{
struct hpb_dmae_device *hpbdev = platform_get_drvdata(pdev);
hpb_dmae_ctl_stop(hpbdev);
}
