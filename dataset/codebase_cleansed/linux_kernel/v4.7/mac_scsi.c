static inline char macscsi_read(struct Scsi_Host *instance, int reg)
{
return in_8(instance->base + (reg << 4));
}
static inline void macscsi_write(struct Scsi_Host *instance, int reg, int value)
{
out_8(instance->base + (reg << 4), value);
}
static int __init mac_scsi_setup(char *str)
{
int ints[8];
(void)get_options(str, ARRAY_SIZE(ints), ints);
if (ints[0] < 1) {
pr_err("Usage: mac5380=<can_queue>[,<cmd_per_lun>[,<sg_tablesize>[,<hostid>[,<use_tags>[,<use_pdma>[,<toshiba_delay>]]]]]]\n");
return 0;
}
if (ints[0] >= 1)
setup_can_queue = ints[1];
if (ints[0] >= 2)
setup_cmd_per_lun = ints[2];
if (ints[0] >= 3)
setup_sg_tablesize = ints[3];
if (ints[0] >= 4)
setup_hostid = ints[4];
if (ints[0] >= 6)
setup_use_pdma = ints[6];
if (ints[0] >= 7)
setup_toshiba_delay = ints[7];
return 1;
}
static int macscsi_pread(struct Scsi_Host *instance,
unsigned char *dst, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned char *s = hostdata->pdma_base + (INPUT_DATA_REG << 4);
unsigned char *d = dst;
int n = len;
int transferred;
while (!NCR5380_poll_politely(instance, BUS_AND_STATUS_REG,
BASR_DRQ | BASR_PHASE_MATCH,
BASR_DRQ | BASR_PHASE_MATCH, HZ / 64)) {
CP_IO_TO_MEM(s, d, n);
transferred = d - dst - n;
hostdata->pdma_residual = len - transferred;
if (n == 0)
return 0;
if (NCR5380_poll_politely2(instance, STATUS_REG, SR_REQ, SR_REQ,
BUS_AND_STATUS_REG, BASR_ACK, BASR_ACK, HZ / 64) < 0)
scmd_printk(KERN_ERR, hostdata->connected,
"%s: !REQ and !ACK\n", __func__);
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_PHASE_MATCH))
return 0;
dsprintk(NDEBUG_PSEUDO_DMA, instance,
"%s: bus error (%d/%d)\n", __func__, transferred, len);
NCR5380_dprint(NDEBUG_PSEUDO_DMA, instance);
d = dst + transferred;
n = len - transferred;
}
scmd_printk(KERN_ERR, hostdata->connected,
"%s: phase mismatch or !DRQ\n", __func__);
NCR5380_dprint(NDEBUG_PSEUDO_DMA, instance);
return -1;
}
static int macscsi_pwrite(struct Scsi_Host *instance,
unsigned char *src, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned char *s = src;
unsigned char *d = hostdata->pdma_base + (OUTPUT_DATA_REG << 4);
int n = len;
int transferred;
while (!NCR5380_poll_politely(instance, BUS_AND_STATUS_REG,
BASR_DRQ | BASR_PHASE_MATCH,
BASR_DRQ | BASR_PHASE_MATCH, HZ / 64)) {
CP_MEM_TO_IO(s, d, n);
transferred = s - src - n;
hostdata->pdma_residual = len - transferred;
if (NCR5380_poll_politely2(instance, STATUS_REG, SR_REQ, SR_REQ,
BUS_AND_STATUS_REG, BASR_ACK, BASR_ACK, HZ / 64) < 0)
scmd_printk(KERN_ERR, hostdata->connected,
"%s: !REQ and !ACK\n", __func__);
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_PHASE_MATCH))
return 0;
if (n == 0) {
if (NCR5380_poll_politely(instance, TARGET_COMMAND_REG,
TCR_LAST_BYTE_SENT,
TCR_LAST_BYTE_SENT, HZ / 64) < 0)
scmd_printk(KERN_ERR, hostdata->connected,
"%s: Last Byte Sent timeout\n", __func__);
return 0;
}
dsprintk(NDEBUG_PSEUDO_DMA, instance,
"%s: bus error (%d/%d)\n", __func__, transferred, len);
NCR5380_dprint(NDEBUG_PSEUDO_DMA, instance);
s = src + transferred;
n = len - transferred;
}
scmd_printk(KERN_ERR, hostdata->connected,
"%s: phase mismatch or !DRQ\n", __func__);
NCR5380_dprint(NDEBUG_PSEUDO_DMA, instance);
return -1;
}
static int macscsi_dma_xfer_len(struct Scsi_Host *instance,
struct scsi_cmnd *cmd)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
if (hostdata->flags & FLAG_NO_PSEUDO_DMA ||
cmd->SCp.this_residual < 16)
return 0;
return cmd->SCp.this_residual;
}
static int __init mac_scsi_probe(struct platform_device *pdev)
{
struct Scsi_Host *instance;
int error;
int host_flags = 0;
struct resource *irq, *pio_mem, *pdma_mem = NULL;
pio_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!pio_mem)
return -ENODEV;
pdma_mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!hwreg_present((unsigned char *)pio_mem->start +
(STATUS_REG << 4))) {
pr_info(PFX "no device detected at %pap\n", &pio_mem->start);
return -ENODEV;
}
if (setup_can_queue > 0)
mac_scsi_template.can_queue = setup_can_queue;
if (setup_cmd_per_lun > 0)
mac_scsi_template.cmd_per_lun = setup_cmd_per_lun;
if (setup_sg_tablesize >= 0)
mac_scsi_template.sg_tablesize = setup_sg_tablesize;
if (setup_hostid >= 0)
mac_scsi_template.this_id = setup_hostid & 7;
instance = scsi_host_alloc(&mac_scsi_template,
sizeof(struct NCR5380_hostdata));
if (!instance)
return -ENOMEM;
instance->base = pio_mem->start;
if (irq)
instance->irq = irq->start;
else
instance->irq = NO_IRQ;
if (pdma_mem && setup_use_pdma) {
struct NCR5380_hostdata *hostdata = shost_priv(instance);
hostdata->pdma_base = (unsigned char *)pdma_mem->start;
} else
host_flags |= FLAG_NO_PSEUDO_DMA;
host_flags |= setup_toshiba_delay > 0 ? FLAG_TOSHIBA_DELAY : 0;
error = NCR5380_init(instance, host_flags | FLAG_LATE_DMA_SETUP);
if (error)
goto fail_init;
if (instance->irq != NO_IRQ) {
error = request_irq(instance->irq, macscsi_intr, IRQF_SHARED,
"NCR5380", instance);
if (error)
goto fail_irq;
}
NCR5380_maybe_reset_bus(instance);
error = scsi_add_host(instance, NULL);
if (error)
goto fail_host;
platform_set_drvdata(pdev, instance);
scsi_scan_host(instance);
return 0;
fail_host:
if (instance->irq != NO_IRQ)
free_irq(instance->irq, instance);
fail_irq:
NCR5380_exit(instance);
fail_init:
scsi_host_put(instance);
return error;
}
static int __exit mac_scsi_remove(struct platform_device *pdev)
{
struct Scsi_Host *instance = platform_get_drvdata(pdev);
scsi_remove_host(instance);
if (instance->irq != NO_IRQ)
free_irq(instance->irq, instance);
NCR5380_exit(instance);
scsi_host_put(instance);
return 0;
}
