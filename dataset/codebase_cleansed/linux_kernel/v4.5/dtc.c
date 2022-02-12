static int __init dtc_setup(char *str)
{
static int commandline_current;
int i;
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
if (ints[0] != 2)
printk("dtc_setup: usage dtc=address,irq\n");
else if (commandline_current < NO_OVERRIDES) {
overrides[commandline_current].address = ints[1];
overrides[commandline_current].irq = ints[2];
for (i = 0; i < NO_BASES; ++i)
if (bases[i].address == ints[1]) {
bases[i].noauto = 1;
break;
}
++commandline_current;
}
return 1;
}
static int __init dtc_detect(struct scsi_host_template * tpnt)
{
static int current_override, current_base;
struct Scsi_Host *instance;
unsigned int addr;
void __iomem *base;
int sig, count;
for (count = 0; current_override < NO_OVERRIDES; ++current_override) {
addr = 0;
base = NULL;
if (overrides[current_override].address) {
addr = overrides[current_override].address;
base = ioremap(addr, 0x2000);
if (!base)
addr = 0;
} else
for (; !addr && (current_base < NO_BASES); ++current_base) {
dprintk(NDEBUG_INIT, "dtc: probing address 0x%08x\n",
(unsigned int)bases[current_base].address);
if (bases[current_base].noauto)
continue;
base = ioremap(bases[current_base].address, 0x2000);
if (!base)
continue;
for (sig = 0; sig < NO_SIGNATURES; ++sig) {
if (check_signature(base + signatures[sig].offset, signatures[sig].string, strlen(signatures[sig].string))) {
addr = bases[current_base].address;
dprintk(NDEBUG_INIT, "dtc: detected board\n");
goto found;
}
}
iounmap(base);
}
dprintk(NDEBUG_INIT, "dtc: addr = 0x%08x\n", addr);
if (!addr)
break;
found:
instance = scsi_register(tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL)
goto out_unmap;
instance->base = addr;
((struct NCR5380_hostdata *)(instance)->hostdata)->base = base;
if (NCR5380_init(instance, FLAG_NO_DMA_FIXUP))
goto out_unregister;
NCR5380_maybe_reset_bus(instance);
NCR5380_write(DTC_CONTROL_REG, CSR_5380_INTR);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, DTC_IRQS);
if (instance->irq == 255)
instance->irq = NO_IRQ;
#ifndef DONT_USE_INTR
if (instance->irq != NO_IRQ)
if (request_irq(instance->irq, dtc_intr, 0,
"dtc", instance)) {
printk(KERN_ERR "scsi%d : IRQ%d not free, interrupts disabled\n", instance->host_no, instance->irq);
instance->irq = NO_IRQ;
}
if (instance->irq == NO_IRQ) {
printk(KERN_WARNING "scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk(KERN_WARNING "scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
#else
if (instance->irq != NO_IRQ)
printk(KERN_WARNING "scsi%d : interrupts not used. Might as well not jumper it.\n", instance->host_no);
instance->irq = NO_IRQ;
#endif
dprintk(NDEBUG_INIT, "scsi%d : irq = %d\n",
instance->host_no, instance->irq);
++current_override;
++count;
}
return count;
out_unregister:
scsi_unregister(instance);
out_unmap:
iounmap(base);
return count;
}
static int dtc_biosparam(struct scsi_device *sdev, struct block_device *dev,
sector_t capacity, int *ip)
{
int size = capacity;
ip[0] = 64;
ip[1] = 32;
ip[2] = size >> 11;
return 0;
}
static inline int NCR5380_pread(struct Scsi_Host *instance, unsigned char *dst, int len)
{
unsigned char *d = dst;
int i;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
i = 0;
if (instance->irq == NO_IRQ)
NCR5380_write(DTC_CONTROL_REG, CSR_DIR_READ);
else
NCR5380_write(DTC_CONTROL_REG, CSR_DIR_READ | CSR_INT_BASE);
NCR5380_write(DTC_BLK_CNT, len >> 7);
rtrc(1);
while (len > 0) {
rtrc(2);
while (NCR5380_read(DTC_CONTROL_REG) & CSR_HOST_BUF_NOT_RDY)
++i;
rtrc(3);
memcpy_fromio(d, hostdata->base + DTC_DATA_BUF, 128);
d += 128;
len -= 128;
rtrc(7);
}
rtrc(4);
while (!(NCR5380_read(DTC_CONTROL_REG) & D_CR_ACCESS))
++i;
rtrc(0);
if (i > hostdata->spin_max_r)
hostdata->spin_max_r = i;
return (0);
}
static inline int NCR5380_pwrite(struct Scsi_Host *instance, unsigned char *src, int len)
{
int i;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
if (instance->irq == NO_IRQ)
NCR5380_write(DTC_CONTROL_REG, 0);
else
NCR5380_write(DTC_CONTROL_REG, CSR_5380_INTR);
NCR5380_write(DTC_BLK_CNT, len >> 7);
for (i = 0; len > 0; ++i) {
rtrc(5);
while (NCR5380_read(DTC_CONTROL_REG) & CSR_HOST_BUF_NOT_RDY)
++i;
rtrc(3);
memcpy_toio(hostdata->base + DTC_DATA_BUF, src, 128);
src += 128;
len -= 128;
}
rtrc(4);
while (!(NCR5380_read(DTC_CONTROL_REG) & D_CR_ACCESS))
++i;
rtrc(6);
while (!(NCR5380_read(TARGET_COMMAND_REG) & TCR_LAST_BYTE_SENT))
++i;
rtrc(7);
rtrc(0);
if (i > hostdata->spin_max_w)
hostdata->spin_max_w = i;
return (0);
}
static int dtc_dma_xfer_len(struct scsi_cmnd *cmd)
{
int transfersize = cmd->transfersize;
if (transfersize > 32 * 1024 && cmd->SCp.this_residual &&
!(cmd->SCp.this_residual % transfersize))
transfersize = 32 * 1024;
return transfersize;
}
static int dtc_release(struct Scsi_Host *shost)
{
struct NCR5380_hostdata *hostdata = shost_priv(shost);
if (shost->irq != NO_IRQ)
free_irq(shost->irq, shost);
NCR5380_exit(shost);
scsi_unregister(shost);
iounmap(hostdata->base);
return 0;
}
