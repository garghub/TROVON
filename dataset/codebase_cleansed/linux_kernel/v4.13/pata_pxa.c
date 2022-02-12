static void pxa_ata_dma_irq(void *d)
{
struct pata_pxa_data *pd = d;
enum dma_status status;
status = dmaengine_tx_status(pd->dma_chan, pd->dma_cookie, NULL);
if (status == DMA_ERROR || status == DMA_COMPLETE)
complete(&pd->dma_done);
}
static void pxa_qc_prep(struct ata_queued_cmd *qc)
{
struct pata_pxa_data *pd = qc->ap->private_data;
struct dma_async_tx_descriptor *tx;
enum dma_transfer_direction dir;
if (!(qc->flags & ATA_QCFLAG_DMAMAP))
return;
dir = (qc->dma_dir == DMA_TO_DEVICE ? DMA_MEM_TO_DEV : DMA_DEV_TO_MEM);
tx = dmaengine_prep_slave_sg(pd->dma_chan, qc->sg, qc->n_elem, dir,
DMA_PREP_INTERRUPT);
if (!tx) {
ata_dev_err(qc->dev, "prep_slave_sg() failed\n");
return;
}
tx->callback = pxa_ata_dma_irq;
tx->callback_param = pd;
pd->dma_cookie = dmaengine_submit(tx);
}
static void pxa_bmdma_setup(struct ata_queued_cmd *qc)
{
qc->ap->ops->sff_exec_command(qc->ap, &qc->tf);
}
static void pxa_bmdma_start(struct ata_queued_cmd *qc)
{
struct pata_pxa_data *pd = qc->ap->private_data;
init_completion(&pd->dma_done);
dma_async_issue_pending(pd->dma_chan);
}
static void pxa_bmdma_stop(struct ata_queued_cmd *qc)
{
struct pata_pxa_data *pd = qc->ap->private_data;
enum dma_status status;
status = dmaengine_tx_status(pd->dma_chan, pd->dma_cookie, NULL);
if (status != DMA_ERROR && status != DMA_COMPLETE &&
wait_for_completion_timeout(&pd->dma_done, HZ))
ata_dev_err(qc->dev, "Timeout waiting for DMA completion!");
dmaengine_terminate_all(pd->dma_chan);
}
static unsigned char pxa_bmdma_status(struct ata_port *ap)
{
struct pata_pxa_data *pd = ap->private_data;
unsigned char ret = ATA_DMA_INTR;
struct dma_tx_state state;
enum dma_status status;
status = dmaengine_tx_status(pd->dma_chan, pd->dma_cookie, &state);
if (status != DMA_COMPLETE)
ret |= ATA_DMA_ERR;
return ret;
}
static void pxa_irq_clear(struct ata_port *ap)
{
}
static int pxa_check_atapi_dma(struct ata_queued_cmd *qc)
{
return -EOPNOTSUPP;
}
static int pxa_ata_probe(struct platform_device *pdev)
{
struct ata_host *host;
struct ata_port *ap;
struct pata_pxa_data *data;
struct resource *cmd_res;
struct resource *ctl_res;
struct resource *dma_res;
struct resource *irq_res;
struct pata_pxa_pdata *pdata = dev_get_platdata(&pdev->dev);
struct dma_slave_config config;
dma_cap_mask_t mask;
struct pxad_param param;
int ret = 0;
if (pdev->num_resources != 4) {
dev_err(&pdev->dev, "invalid number of resources\n");
return -EINVAL;
}
cmd_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(cmd_res == NULL))
return -EINVAL;
ctl_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (unlikely(ctl_res == NULL))
return -EINVAL;
dma_res = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (unlikely(dma_res == NULL))
return -EINVAL;
irq_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (unlikely(irq_res == NULL))
return -EINVAL;
host = ata_host_alloc(&pdev->dev, 1);
if (!host)
return -ENOMEM;
ap = host->ports[0];
ap->ops = &pxa_ata_port_ops;
ap->pio_mask = ATA_PIO4;
ap->mwdma_mask = ATA_MWDMA2;
ap->ioaddr.cmd_addr = devm_ioremap(&pdev->dev, cmd_res->start,
resource_size(cmd_res));
ap->ioaddr.ctl_addr = devm_ioremap(&pdev->dev, ctl_res->start,
resource_size(ctl_res));
ap->ioaddr.bmdma_addr = devm_ioremap(&pdev->dev, dma_res->start,
resource_size(dma_res));
ap->ioaddr.altstatus_addr = ap->ioaddr.ctl_addr;
ap->ioaddr.data_addr = ap->ioaddr.cmd_addr +
(ATA_REG_DATA << pdata->reg_shift);
ap->ioaddr.error_addr = ap->ioaddr.cmd_addr +
(ATA_REG_ERR << pdata->reg_shift);
ap->ioaddr.feature_addr = ap->ioaddr.cmd_addr +
(ATA_REG_FEATURE << pdata->reg_shift);
ap->ioaddr.nsect_addr = ap->ioaddr.cmd_addr +
(ATA_REG_NSECT << pdata->reg_shift);
ap->ioaddr.lbal_addr = ap->ioaddr.cmd_addr +
(ATA_REG_LBAL << pdata->reg_shift);
ap->ioaddr.lbam_addr = ap->ioaddr.cmd_addr +
(ATA_REG_LBAM << pdata->reg_shift);
ap->ioaddr.lbah_addr = ap->ioaddr.cmd_addr +
(ATA_REG_LBAH << pdata->reg_shift);
ap->ioaddr.device_addr = ap->ioaddr.cmd_addr +
(ATA_REG_DEVICE << pdata->reg_shift);
ap->ioaddr.status_addr = ap->ioaddr.cmd_addr +
(ATA_REG_STATUS << pdata->reg_shift);
ap->ioaddr.command_addr = ap->ioaddr.cmd_addr +
(ATA_REG_CMD << pdata->reg_shift);
data = devm_kzalloc(&pdev->dev, sizeof(struct pata_pxa_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
ap->private_data = data;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
param.prio = PXAD_PRIO_LOWEST;
param.drcmr = pdata->dma_dreq;
memset(&config, 0, sizeof(config));
config.src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
config.dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
config.src_addr = dma_res->start;
config.dst_addr = dma_res->start;
config.src_maxburst = 32;
config.dst_maxburst = 32;
data->dma_chan =
dma_request_slave_channel_compat(mask, pxad_filter_fn,
&param, &pdev->dev, "data");
if (!data->dma_chan)
return -EBUSY;
ret = dmaengine_slave_config(data->dma_chan, &config);
if (ret < 0) {
dev_err(&pdev->dev, "dma configuration failed: %d\n", ret);
return ret;
}
ret = ata_host_activate(host, irq_res->start, ata_sff_interrupt,
pdata->irq_flags, &pxa_ata_sht);
if (ret)
dma_release_channel(data->dma_chan);
return ret;
}
static int pxa_ata_remove(struct platform_device *pdev)
{
struct ata_host *host = platform_get_drvdata(pdev);
struct pata_pxa_data *data = host->ports[0]->private_data;
dma_release_channel(data->dma_chan);
ata_host_detach(host);
return 0;
}
