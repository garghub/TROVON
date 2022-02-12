static int __init t128_setup(char *str)
{
static int commandline_current;
int i;
int ints[10];
get_options(str, ARRAY_SIZE(ints), ints);
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
return 1;
}
static int __init t128_detect(struct scsi_host_template *tpnt)
{
static int current_override, current_base;
struct Scsi_Host *instance;
unsigned long base;
void __iomem *p;
int sig, count;
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
dprintk(NDEBUG_INIT, "t128: probing address 0x%08x\n",
bases[current_base].address);
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
dprintk(NDEBUG_INIT, "t128: detected board\n");
goto found;
}
iounmap(p);
}
dprintk(NDEBUG_INIT, "t128: base = 0x%08x\n", (unsigned int)base);
if (!base)
break;
found:
instance = scsi_register (tpnt, sizeof(struct NCR5380_hostdata));
if(instance == NULL)
goto out_unmap;
instance->base = base;
((struct NCR5380_hostdata *)instance->hostdata)->base = p;
if (NCR5380_init(instance, FLAG_DMA_FIXUP | FLAG_LATE_DMA_SETUP))
goto out_unregister;
NCR5380_maybe_reset_bus(instance);
if (overrides[current_override].irq != IRQ_AUTO)
instance->irq = overrides[current_override].irq;
else
instance->irq = NCR5380_probe_irq(instance, T128_IRQS);
if (instance->irq == 255)
instance->irq = NO_IRQ;
if (instance->irq != NO_IRQ)
if (request_irq(instance->irq, t128_intr, 0, "t128",
instance)) {
printk("scsi%d : IRQ%d not free, interrupts disabled\n",
instance->host_no, instance->irq);
instance->irq = NO_IRQ;
}
if (instance->irq == NO_IRQ) {
printk("scsi%d : interrupts not enabled. for better interactive performance,\n", instance->host_no);
printk("scsi%d : please jumper the board for a free IRQ.\n", instance->host_no);
}
dprintk(NDEBUG_INIT, "scsi%d: irq = %d\n",
instance->host_no, instance->irq);
++current_override;
++count;
}
return count;
out_unregister:
scsi_unregister(instance);
out_unmap:
iounmap(p);
return count;
}
static int t128_release(struct Scsi_Host *shost)
{
struct NCR5380_hostdata *hostdata = shost_priv(shost);
if (shost->irq != NO_IRQ)
free_irq(shost->irq, shost);
NCR5380_exit(shost);
scsi_unregister(shost);
iounmap(hostdata->base);
return 0;
}
static int t128_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int *ip)
{
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
return 0;
}
static inline int t128_pread(struct Scsi_Host *instance,
unsigned char *dst, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
void __iomem *reg, *base = hostdata->base;
unsigned char *d = dst;
register int i = len;
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
static inline int t128_pwrite(struct Scsi_Host *instance,
unsigned char *src, int len)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
void __iomem *reg, *base = hostdata->base;
unsigned char *s = src;
register int i = len;
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
