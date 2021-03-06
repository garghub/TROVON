static irqreturn_t a2091_intr(int irq, void *data)
{
struct Scsi_Host *instance = data;
struct a2091_hostdata *hdata = shost_priv(instance);
unsigned int status = hdata->regs->ISTR;
unsigned long flags;
if (!(status & (ISTR_INT_F | ISTR_INT_P)) || !(status & ISTR_INTS))
return IRQ_NONE;
spin_lock_irqsave(instance->host_lock, flags);
wd33c93_intr(instance);
spin_unlock_irqrestore(instance->host_lock, flags);
return IRQ_HANDLED;
}
static int dma_setup(struct scsi_cmnd *cmd, int dir_in)
{
struct Scsi_Host *instance = cmd->device->host;
struct a2091_hostdata *hdata = shost_priv(instance);
struct WD33C93_hostdata *wh = &hdata->wh;
struct a2091_scsiregs *regs = hdata->regs;
unsigned short cntr = CNTR_PDMD | CNTR_INTEN;
unsigned long addr = virt_to_bus(cmd->SCp.ptr);
if (addr & A2091_XFER_MASK) {
wh->dma_bounce_len = (cmd->SCp.this_residual + 511) & ~0x1ff;
wh->dma_bounce_buffer = kmalloc(wh->dma_bounce_len,
GFP_KERNEL);
if (!wh->dma_bounce_buffer) {
wh->dma_bounce_len = 0;
return 1;
}
addr = virt_to_bus(wh->dma_bounce_buffer);
if (addr & A2091_XFER_MASK) {
kfree(wh->dma_bounce_buffer);
wh->dma_bounce_buffer = NULL;
wh->dma_bounce_len = 0;
return 1;
}
if (!dir_in) {
memcpy(wh->dma_bounce_buffer, cmd->SCp.ptr,
cmd->SCp.this_residual);
}
}
if (!dir_in)
cntr |= CNTR_DDIR;
wh->dma_dir = dir_in;
regs->CNTR = cntr;
regs->ACR = addr;
if (dir_in) {
cache_clear(addr, cmd->SCp.this_residual);
} else {
cache_push(addr, cmd->SCp.this_residual);
}
regs->ST_DMA = 1;
return 0;
}
static void dma_stop(struct Scsi_Host *instance, struct scsi_cmnd *SCpnt,
int status)
{
struct a2091_hostdata *hdata = shost_priv(instance);
struct WD33C93_hostdata *wh = &hdata->wh;
struct a2091_scsiregs *regs = hdata->regs;
unsigned short cntr = CNTR_PDMD;
if (!wh->dma_dir)
cntr |= CNTR_DDIR;
regs->CNTR = cntr;
if (wh->dma_dir) {
regs->FLUSH = 1;
while (!(regs->ISTR & ISTR_FE_FLG))
;
}
regs->CINT = 1;
regs->SP_DMA = 1;
regs->CNTR = CNTR_PDMD | CNTR_INTEN;
if (status && wh->dma_bounce_buffer) {
if (wh->dma_dir)
memcpy(SCpnt->SCp.ptr, wh->dma_bounce_buffer,
SCpnt->SCp.this_residual);
kfree(wh->dma_bounce_buffer);
wh->dma_bounce_buffer = NULL;
wh->dma_bounce_len = 0;
}
}
static int a2091_bus_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *instance = cmd->device->host;
spin_lock_irq(instance->host_lock);
wd33c93_host_reset(cmd);
spin_unlock_irq(instance->host_lock);
return SUCCESS;
}
static int a2091_probe(struct zorro_dev *z, const struct zorro_device_id *ent)
{
struct Scsi_Host *instance;
int error;
struct a2091_scsiregs *regs;
wd33c93_regs wdregs;
struct a2091_hostdata *hdata;
if (!request_mem_region(z->resource.start, 256, "wd33c93"))
return -EBUSY;
instance = scsi_host_alloc(&a2091_scsi_template,
sizeof(struct a2091_hostdata));
if (!instance) {
error = -ENOMEM;
goto fail_alloc;
}
instance->irq = IRQ_AMIGA_PORTS;
instance->unique_id = z->slotaddr;
regs = ZTWO_VADDR(z->resource.start);
regs->DAWR = DAWR_A2091;
wdregs.SASR = &regs->SASR;
wdregs.SCMD = &regs->SCMD;
hdata = shost_priv(instance);
hdata->wh.no_sync = 0xff;
hdata->wh.fast = 0;
hdata->wh.dma_mode = CTRL_DMA;
hdata->regs = regs;
wd33c93_init(instance, wdregs, dma_setup, dma_stop, WD33C93_FS_8_10);
error = request_irq(IRQ_AMIGA_PORTS, a2091_intr, IRQF_SHARED,
"A2091 SCSI", instance);
if (error)
goto fail_irq;
regs->CNTR = CNTR_PDMD | CNTR_INTEN;
error = scsi_add_host(instance, NULL);
if (error)
goto fail_host;
zorro_set_drvdata(z, instance);
scsi_scan_host(instance);
return 0;
fail_host:
free_irq(IRQ_AMIGA_PORTS, instance);
fail_irq:
scsi_host_put(instance);
fail_alloc:
release_mem_region(z->resource.start, 256);
return error;
}
static void a2091_remove(struct zorro_dev *z)
{
struct Scsi_Host *instance = zorro_get_drvdata(z);
struct a2091_hostdata *hdata = shost_priv(instance);
hdata->regs->CNTR = 0;
scsi_remove_host(instance);
free_irq(IRQ_AMIGA_PORTS, instance);
scsi_host_put(instance);
release_mem_region(z->resource.start, 256);
}
static int __init a2091_init(void)
{
return zorro_register_driver(&a2091_driver);
}
static void __exit a2091_exit(void)
{
zorro_unregister_driver(&a2091_driver);
}
