void __init t128_setup(char *str, int *ints){
static int commandline_current = 0;
int i;
if (ints[0] != 2)
printk("t128_setup : usage t128=address,irq\n");
else
if (commandline_current < NO_OVERRIDES) {
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
int __init t128_detect(struct scsi_host_template * tpnt){
static int current_override = 0, current_base = 0;
struct Scsi_Host *instance;
unsigned long base;
void __iomem *p;
int sig, count;
tpnt->proc_name = "t128";
tpnt->proc_info = &t128_proc_info;
for (count = 0; current_override < NO_OVERRIDES; ++current_override) {
base = 0;
p = NULL;
if (overrides[current_override].address) {
base = overrides[current_override].address;
p = ioremap(bases[current_base].address, 0x2000);
if (!p)
base = 0;
} else
for (; !base && (current_base < NO_BASES); ++current_base) {
#if (TDEBUG & TDEBUG_INIT)
printk("scsi-t128 : probing address %08x\n", bases[current_base].address);
#endif
if (bases[current_base].noauto)
continue;
p = ioremap(bases[current_base].address, 0x2000);
if (!p)
continue;
for (sig = 0; sig < NO_SIGNATURES; ++sig)
if (check_signature(p + signatures[sig].offset,
signatures[sig].string,
strlen(signatures[sig].string))) {
base = bases[current_base].address;
#if (TDEBUG & TDEBUG_INIT)
printk("scsi-t128 : detected board.\n");
#endif
goto found;
}
iounmap(p);
}
#if defined(TDEBUG) && (TDEBUG & TDEBUG_INIT)
printk("scsi-t128 : base = %08x\n", (unsigned int) base);
#endif
if (!base)
break;
found:
instance = scsi_register (tpnt, sizeof(struct NCR5380_hostdata));
if(instance == NULL)
break;
instance->base = base;
((struct NCR5380_hostdata *)instance->hostdata)->base = p;
NCR5380_init(instance, 0);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, T128_IRQS);
if (instance->irq != SCSI_IRQ_NONE)
if (request_irq(instance->irq, t128_intr, IRQF_DISABLED, "t128",
instance)) {
printk("scsi%d : IRQ%d not free, interrupts disabled\n",
instance->host_no, instance->irq);
instance->irq = SCSI_IRQ_NONE;
}
if (instance->irq == SCSI_IRQ_NONE) {
printk("scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk("scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
#if defined(TDEBUG) && (TDEBUG & TDEBUG_INIT)
printk("scsi%d : irq = %d\n", instance->host_no, instance->irq);
#endif
printk("scsi%d : at 0x%08lx", instance->host_no, instance->base);
if (instance->irq == SCSI_IRQ_NONE)
printk (" interrupts disabled");
else
printk (" irq %d", instance->irq);
printk(" options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d",
CAN_QUEUE, CMD_PER_LUN, T128_PUBLIC_RELEASE);
NCR5380_print_options(instance);
printk("\n");
++current_override;
++count;
}
return count;
}
static int t128_release(struct Scsi_Host *shost)
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
int t128_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int * ip)
{
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
return 0;
}
static inline int NCR5380_pread (struct Scsi_Host *instance, unsigned char *dst,
int len) {
NCR5380_local_declare();
void __iomem *reg;
unsigned char *d = dst;
register int i = len;
NCR5380_setup(instance);
reg = base + T_DATA_REG_OFFSET;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
for (; i; --i) {
#endif
*d++ = readb(reg);
}
if (readb(base + T_STATUS_REG_OFFSET) & T_ST_TIM) {
unsigned char tmp;
void __iomem *foo = base + T_CONTROL_REG_OFFSET;
tmp = readb(foo);
writeb(tmp | T_CR_CT, foo);
writeb(tmp, foo);
printk("scsi%d : watchdog timer fired in NCR5380_pread()\n",
instance->host_no);
return -1;
} else
return 0;
}
static inline int NCR5380_pwrite (struct Scsi_Host *instance, unsigned char *src,
int len) {
NCR5380_local_declare();
void __iomem *reg;
unsigned char *s = src;
register int i = len;
NCR5380_setup(instance);
reg = base + T_DATA_REG_OFFSET;
#if 0
for (; i; --i) {
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
#else
while (!(readb(base+T_STATUS_REG_OFFSET) & T_ST_RDY)) barrier();
for (; i; --i) {
#endif
writeb(*s++, reg);
}
if (readb(base + T_STATUS_REG_OFFSET) & T_ST_TIM) {
unsigned char tmp;
void __iomem *foo = base + T_CONTROL_REG_OFFSET;
tmp = readb(foo);
writeb(tmp | T_CR_CT, foo);
writeb(tmp, foo);
printk("scsi%d : watchdog timer fired in NCR5380_pwrite()\n",
instance->host_no);
return -1;
} else
return 0;
}
