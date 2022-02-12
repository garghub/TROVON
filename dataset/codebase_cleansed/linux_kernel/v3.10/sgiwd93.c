static irqreturn_t sgiwd93_intr(int irq, void *dev_id)
{
struct Scsi_Host * host = dev_id;
unsigned long flags;
spin_lock_irqsave(host->host_lock, flags);
wd33c93_intr(host);
spin_unlock_irqrestore(host->host_lock, flags);
return IRQ_HANDLED;
}
static inline
void fill_hpc_entries(struct ip22_hostdata *hd, struct scsi_cmnd *cmd, int din)
{
unsigned long len = cmd->SCp.this_residual;
void *addr = cmd->SCp.ptr;
dma_addr_t physaddr;
unsigned long count;
struct hpc_chunk *hcp;
physaddr = dma_map_single(hd->dev, addr, len, DMA_DIR(din));
cmd->SCp.dma_handle = physaddr;
hcp = hd->cpu;
while (len) {
count = len > 8192 ? 8192 : len;
hcp->desc.pbuf = physaddr;
hcp->desc.cntinfo = count;
hcp++;
len -= count;
physaddr += count;
}
hcp->desc.pbuf = 0;
hcp->desc.cntinfo = HPCDMA_EOX;
dma_cache_sync(hd->dev, hd->cpu,
(unsigned long)(hcp + 1) - (unsigned long)hd->cpu,
DMA_TO_DEVICE);
}
static int dma_setup(struct scsi_cmnd *cmd, int datainp)
{
struct ip22_hostdata *hdata = host_to_hostdata(cmd->device->host);
struct hpc3_scsiregs *hregs =
(struct hpc3_scsiregs *) cmd->device->host->base;
pr_debug("dma_setup: datainp<%d> hcp<%p> ", datainp, hdata->cpu);
hdata->wh.dma_dir = datainp;
if (cmd->SCp.ptr == NULL || cmd->SCp.this_residual == 0)
return 1;
fill_hpc_entries(hdata, cmd, datainp);
pr_debug(" HPCGO\n");
hregs->ndptr = hdata->dma;
if (datainp)
hregs->ctrl = HPC3_SCTRL_ACTIVE;
else
hregs->ctrl = HPC3_SCTRL_ACTIVE | HPC3_SCTRL_DIR;
return 0;
}
static void dma_stop(struct Scsi_Host *instance, struct scsi_cmnd *SCpnt,
int status)
{
struct ip22_hostdata *hdata = host_to_hostdata(instance);
struct hpc3_scsiregs *hregs;
if (!SCpnt)
return;
if (SCpnt->SCp.ptr == NULL || SCpnt->SCp.this_residual == 0)
return;
hregs = (struct hpc3_scsiregs *) SCpnt->device->host->base;
pr_debug("dma_stop: status<%d> ", status);
if (hdata->wh.dma_dir) {
hregs->ctrl |= HPC3_SCTRL_FLUSH;
while (hregs->ctrl & HPC3_SCTRL_ACTIVE)
barrier();
}
hregs->ctrl = 0;
dma_unmap_single(hdata->dev, SCpnt->SCp.dma_handle,
SCpnt->SCp.this_residual,
DMA_DIR(hdata->wh.dma_dir));
pr_debug("\n");
}
void sgiwd93_reset(unsigned long base)
{
struct hpc3_scsiregs *hregs = (struct hpc3_scsiregs *) base;
hregs->ctrl = HPC3_SCTRL_CRESET;
udelay(50);
hregs->ctrl = 0;
}
static inline void init_hpc_chain(struct ip22_hostdata *hdata)
{
struct hpc_chunk *hcp = (struct hpc_chunk *)hdata->cpu;
dma_addr_t dma = hdata->dma;
unsigned long start, end;
start = (unsigned long) hcp;
end = start + HPC_DMA_SIZE;
while (start < end) {
hcp->desc.pnext = (u32) (dma + sizeof(struct hpc_chunk));
hcp->desc.cntinfo = HPCDMA_EOX;
hcp++;
dma += sizeof(struct hpc_chunk);
start += sizeof(struct hpc_chunk);
};
hcp--;
hcp->desc.pnext = hdata->dma;
}
static int sgiwd93_bus_reset(struct scsi_cmnd *cmd)
{
spin_lock_irq(cmd->device->host->host_lock);
wd33c93_host_reset(cmd);
spin_unlock_irq(cmd->device->host->host_lock);
return SUCCESS;
}
static int sgiwd93_probe(struct platform_device *pdev)
{
struct sgiwd93_platform_data *pd = pdev->dev.platform_data;
unsigned char *wdregs = pd->wdregs;
struct hpc3_scsiregs *hregs = pd->hregs;
struct ip22_hostdata *hdata;
struct Scsi_Host *host;
wd33c93_regs regs;
unsigned int unit = pd->unit;
unsigned int irq = pd->irq;
int err;
host = scsi_host_alloc(&sgiwd93_template, sizeof(struct ip22_hostdata));
if (!host) {
err = -ENOMEM;
goto out;
}
host->base = (unsigned long) hregs;
host->irq = irq;
hdata = host_to_hostdata(host);
hdata->dev = &pdev->dev;
hdata->cpu = dma_alloc_noncoherent(&pdev->dev, HPC_DMA_SIZE,
&hdata->dma, GFP_KERNEL);
if (!hdata->cpu) {
printk(KERN_WARNING "sgiwd93: Could not allocate memory for "
"host %d buffer.\n", unit);
err = -ENOMEM;
goto out_put;
}
init_hpc_chain(hdata);
regs.SASR = wdregs + 3;
regs.SCMD = wdregs + 7;
hdata->wh.no_sync = 0;
hdata->wh.fast = 1;
hdata->wh.dma_mode = CTRL_BURST;
wd33c93_init(host, regs, dma_setup, dma_stop, WD33C93_FS_MHZ(20));
err = request_irq(irq, sgiwd93_intr, 0, "SGI WD93", host);
if (err) {
printk(KERN_WARNING "sgiwd93: Could not register irq %d "
"for host %d.\n", irq, unit);
goto out_free;
}
platform_set_drvdata(pdev, host);
err = scsi_add_host(host, NULL);
if (err)
goto out_irq;
scsi_scan_host(host);
return 0;
out_irq:
free_irq(irq, host);
out_free:
dma_free_noncoherent(&pdev->dev, HPC_DMA_SIZE, hdata->cpu, hdata->dma);
out_put:
scsi_host_put(host);
out:
return err;
}
static int __exit sgiwd93_remove(struct platform_device *pdev)
{
struct Scsi_Host *host = platform_get_drvdata(pdev);
struct ip22_hostdata *hdata = (struct ip22_hostdata *) host->hostdata;
struct sgiwd93_platform_data *pd = pdev->dev.platform_data;
scsi_remove_host(host);
free_irq(pd->irq, host);
dma_free_noncoherent(&pdev->dev, HPC_DMA_SIZE, hdata->cpu, hdata->dma);
scsi_host_put(host);
return 0;
}
static int __init sgiwd93_module_init(void)
{
return platform_driver_register(&sgiwd93_driver);
}
static void __exit sgiwd93_module_exit(void)
{
return platform_driver_unregister(&sgiwd93_driver);
}
