static void __init dtc_setup(char *str, int *ints)
{
static int commandline_current = 0;
int i;
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
}
static int __init dtc_detect(struct scsi_host_template * tpnt)
{
static int current_override = 0, current_base = 0;
struct Scsi_Host *instance;
unsigned int addr;
void __iomem *base;
int sig, count;
tpnt->proc_name = "dtc3x80";
tpnt->show_info = dtc_show_info;
tpnt->write_info = dtc_write_info;
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
#if (DTCDEBUG & DTCDEBUG_INIT)
printk(KERN_DEBUG "scsi-dtc : probing address %08x\n", bases[current_base].address);
#endif
if (bases[current_base].noauto)
continue;
base = ioremap(bases[current_base].address, 0x2000);
if (!base)
continue;
for (sig = 0; sig < NO_SIGNATURES; ++sig) {
if (check_signature(base + signatures[sig].offset, signatures[sig].string, strlen(signatures[sig].string))) {
addr = bases[current_base].address;
#if (DTCDEBUG & DTCDEBUG_INIT)
printk(KERN_DEBUG "scsi-dtc : detected board.\n");
#endif
goto found;
}
}
iounmap(base);
}
#if defined(DTCDEBUG) && (DTCDEBUG & DTCDEBUG_INIT)
printk(KERN_DEBUG "scsi-dtc : base = %08x\n", addr);
#endif
if (!addr)
break;
found:
instance = scsi_register(tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL)
break;
instance->base = addr;
((struct NCR5380_hostdata *)(instance)->hostdata)->base = base;
NCR5380_init(instance, 0);
NCR5380_write(DTC_CONTROL_REG, CSR_5380_INTR);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, DTC_IRQS);
#ifndef DONT_USE_INTR
if (instance->irq != SCSI_IRQ_NONE)
if (request_irq(instance->irq, dtc_intr, IRQF_DISABLED,
"dtc", instance)) {
printk(KERN_ERR "scsi%d : IRQ%d not free, interrupts disabled\n", instance->host_no, instance->irq);
instance->irq = SCSI_IRQ_NONE;
}
if (instance->irq == SCSI_IRQ_NONE) {
printk(KERN_WARNING "scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk(KERN_WARNING "scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
#else
if (instance->irq != SCSI_IRQ_NONE)
printk(KERN_WARNING "scsi%d : interrupts not used. Might as well not jumper it.\n", instance->host_no);
instance->irq = SCSI_IRQ_NONE;
#endif
#if defined(DTCDEBUG) && (DTCDEBUG & DTCDEBUG_INIT)
printk("scsi%d : irq = %d\n", instance->host_no, instance->irq);
#endif
printk(KERN_INFO "scsi%d : at 0x%05X", instance->host_no, (int) instance->base);
if (instance->irq == SCSI_IRQ_NONE)
printk(" interrupts disabled");
else
printk(" irq %d", instance->irq);
printk(" options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d", CAN_QUEUE, CMD_PER_LUN, DTC_PUBLIC_RELEASE);
NCR5380_print_options(instance);
printk("\n");
++current_override;
++count;
}
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
NCR5380_local_declare();
NCR5380_setup(instance);
i = 0;
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_write(MODE_REG, MR_ENABLE_EOP_INTR | MR_DMA_MODE);
if (instance->irq == SCSI_IRQ_NONE)
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
memcpy_fromio(d, base + DTC_DATA_BUF, 128);
d += 128;
len -= 128;
rtrc(7);
}
rtrc(4);
while (!(NCR5380_read(DTC_CONTROL_REG) & D_CR_ACCESS))
++i;
NCR5380_write(MODE_REG, 0);
rtrc(0);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
if (i > dtc_maxi)
dtc_maxi = i;
return (0);
}
static inline int NCR5380_pwrite(struct Scsi_Host *instance, unsigned char *src, int len)
{
int i;
NCR5380_local_declare();
NCR5380_setup(instance);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_write(MODE_REG, MR_ENABLE_EOP_INTR | MR_DMA_MODE);
if (instance->irq == SCSI_IRQ_NONE)
NCR5380_write(DTC_CONTROL_REG, 0);
else
NCR5380_write(DTC_CONTROL_REG, CSR_5380_INTR);
NCR5380_write(DTC_BLK_CNT, len >> 7);
for (i = 0; len > 0; ++i) {
rtrc(5);
while (NCR5380_read(DTC_CONTROL_REG) & CSR_HOST_BUF_NOT_RDY)
++i;
rtrc(3);
memcpy_toio(base + DTC_DATA_BUF, src, 128);
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
NCR5380_write(MODE_REG, 0);
rtrc(0);
if (i > dtc_wmaxi)
dtc_wmaxi = i;
return (0);
}
static int dtc_release(struct Scsi_Host *shost)
{
NCR5380_local_declare();
NCR5380_setup(shost);
if (shost->irq)
free_irq(shost->irq, shost);
NCR5380_exit(shost);
if (shost->io_port && shost->n_io_port)
release_region(shost->io_port, shost->n_io_port);
scsi_unregister(shost);
iounmap(base);
return 0;
}
