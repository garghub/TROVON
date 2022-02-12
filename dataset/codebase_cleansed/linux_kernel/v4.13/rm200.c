static int __init snirm_setup_devinit(void)
{
if (sni_brd_type == SNI_BRD_RM200) {
platform_device_register(&rm200_serial8250_device);
platform_device_register(&rm200_ds1216_device);
platform_device_register(&snirm_82596_rm200_pdev);
platform_device_register(&snirm_53c710_rm200_pdev);
sni_eisa_root_init();
}
return 0;
}
static void sni_rm200_disable_8259A_irq(struct irq_data *d)
{
unsigned int mask, irq = d->irq - RM200_I8259A_IRQ_BASE;
unsigned long flags;
mask = 1 << irq;
raw_spin_lock_irqsave(&sni_rm200_i8259A_lock, flags);
rm200_cached_irq_mask |= mask;
if (irq & 8)
writeb(cached_slave_mask, rm200_pic_slave + PIC_IMR);
else
writeb(cached_master_mask, rm200_pic_master + PIC_IMR);
raw_spin_unlock_irqrestore(&sni_rm200_i8259A_lock, flags);
}
static void sni_rm200_enable_8259A_irq(struct irq_data *d)
{
unsigned int mask, irq = d->irq - RM200_I8259A_IRQ_BASE;
unsigned long flags;
mask = ~(1 << irq);
raw_spin_lock_irqsave(&sni_rm200_i8259A_lock, flags);
rm200_cached_irq_mask &= mask;
if (irq & 8)
writeb(cached_slave_mask, rm200_pic_slave + PIC_IMR);
else
writeb(cached_master_mask, rm200_pic_master + PIC_IMR);
raw_spin_unlock_irqrestore(&sni_rm200_i8259A_lock, flags);
}
static inline int sni_rm200_i8259A_irq_real(unsigned int irq)
{
int value;
int irqmask = 1 << irq;
if (irq < 8) {
writeb(0x0B, rm200_pic_master + PIC_CMD);
value = readb(rm200_pic_master + PIC_CMD) & irqmask;
writeb(0x0A, rm200_pic_master + PIC_CMD);
return value;
}
writeb(0x0B, rm200_pic_slave + PIC_CMD);
value = readb(rm200_pic_slave + PIC_CMD) & (irqmask >> 8);
writeb(0x0A, rm200_pic_slave + PIC_CMD);
return value;
}
void sni_rm200_mask_and_ack_8259A(struct irq_data *d)
{
unsigned int irqmask, irq = d->irq - RM200_I8259A_IRQ_BASE;
unsigned long flags;
irqmask = 1 << irq;
raw_spin_lock_irqsave(&sni_rm200_i8259A_lock, flags);
if (rm200_cached_irq_mask & irqmask)
goto spurious_8259A_irq;
rm200_cached_irq_mask |= irqmask;
handle_real_irq:
if (irq & 8) {
readb(rm200_pic_slave + PIC_IMR);
writeb(cached_slave_mask, rm200_pic_slave + PIC_IMR);
writeb(0x60+(irq & 7), rm200_pic_slave + PIC_CMD);
writeb(0x60+PIC_CASCADE_IR, rm200_pic_master + PIC_CMD);
} else {
readb(rm200_pic_master + PIC_IMR);
writeb(cached_master_mask, rm200_pic_master + PIC_IMR);
writeb(0x60+irq, rm200_pic_master + PIC_CMD);
}
raw_spin_unlock_irqrestore(&sni_rm200_i8259A_lock, flags);
return;
spurious_8259A_irq:
if (sni_rm200_i8259A_irq_real(irq))
goto handle_real_irq;
{
static int spurious_irq_mask;
if (!(spurious_irq_mask & irqmask)) {
printk(KERN_DEBUG
"spurious RM200 8259A interrupt: IRQ%d.\n", irq);
spurious_irq_mask |= irqmask;
}
atomic_inc(&irq_err_count);
goto handle_real_irq;
}
}
static inline int sni_rm200_i8259_irq(void)
{
int irq;
raw_spin_lock(&sni_rm200_i8259A_lock);
writeb(0x0C, rm200_pic_master + PIC_CMD);
irq = readb(rm200_pic_master + PIC_CMD) & 7;
if (irq == PIC_CASCADE_IR) {
writeb(0x0C, rm200_pic_slave + PIC_CMD);
irq = (readb(rm200_pic_slave + PIC_CMD) & 7) + 8;
}
if (unlikely(irq == 7)) {
writeb(0x0B, rm200_pic_master + PIC_ISR);
if (~readb(rm200_pic_master + PIC_ISR) & 0x80)
irq = -1;
}
raw_spin_unlock(&sni_rm200_i8259A_lock);
return likely(irq >= 0) ? irq + RM200_I8259A_IRQ_BASE : irq;
}
void sni_rm200_init_8259A(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&sni_rm200_i8259A_lock, flags);
writeb(0xff, rm200_pic_master + PIC_IMR);
writeb(0xff, rm200_pic_slave + PIC_IMR);
writeb(0x11, rm200_pic_master + PIC_CMD);
writeb(0, rm200_pic_master + PIC_IMR);
writeb(1U << PIC_CASCADE_IR, rm200_pic_master + PIC_IMR);
writeb(MASTER_ICW4_DEFAULT, rm200_pic_master + PIC_IMR);
writeb(0x11, rm200_pic_slave + PIC_CMD);
writeb(8, rm200_pic_slave + PIC_IMR);
writeb(PIC_CASCADE_IR, rm200_pic_slave + PIC_IMR);
writeb(SLAVE_ICW4_DEFAULT, rm200_pic_slave + PIC_IMR);
udelay(100);
writeb(cached_master_mask, rm200_pic_master + PIC_IMR);
writeb(cached_slave_mask, rm200_pic_slave + PIC_IMR);
raw_spin_unlock_irqrestore(&sni_rm200_i8259A_lock, flags);
}
static irqreturn_t sni_rm200_i8259A_irq_handler(int dummy, void *p)
{
int irq;
irq = sni_rm200_i8259_irq();
if (unlikely(irq < 0))
return IRQ_NONE;
do_IRQ(irq);
return IRQ_HANDLED;
}
void __init sni_rm200_i8259_irqs(void)
{
int i;
rm200_pic_master = ioremap_nocache(0x16000020, 4);
if (!rm200_pic_master)
return;
rm200_pic_slave = ioremap_nocache(0x160000a0, 4);
if (!rm200_pic_slave) {
iounmap(rm200_pic_master);
return;
}
insert_resource(&iomem_resource, &sni_rm200_pic1_resource);
insert_resource(&iomem_resource, &sni_rm200_pic2_resource);
sni_rm200_init_8259A();
for (i = RM200_I8259A_IRQ_BASE; i < RM200_I8259A_IRQ_BASE + 16; i++)
irq_set_chip_and_handler(i, &sni_rm200_i8259A_chip,
handle_level_irq);
setup_irq(RM200_I8259A_IRQ_BASE + PIC_CASCADE_IR, &sni_rm200_irq2);
}
static void enable_rm200_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq - SNI_RM200_INT_START);
*(volatile u8 *)SNI_RM200_INT_ENA_REG &= ~mask;
}
void disable_rm200_irq(struct irq_data *d)
{
unsigned int mask = 1 << (d->irq - SNI_RM200_INT_START);
*(volatile u8 *)SNI_RM200_INT_ENA_REG |= mask;
}
static void sni_rm200_hwint(void)
{
u32 pending = read_c0_cause() & read_c0_status();
u8 mask;
u8 stat;
int irq;
if (pending & C_IRQ5)
do_IRQ(MIPS_CPU_IRQ_BASE + 7);
else if (pending & C_IRQ0) {
clear_c0_status(IE_IRQ0);
mask = *(volatile u8 *)SNI_RM200_INT_ENA_REG ^ 0x1f;
stat = *(volatile u8 *)SNI_RM200_INT_STAT_REG ^ 0x14;
irq = ffs(stat & mask & 0x1f);
if (likely(irq > 0))
do_IRQ(irq + SNI_RM200_INT_START - 1);
set_c0_status(IE_IRQ0);
}
}
void __init sni_rm200_irq_init(void)
{
int i;
* (volatile u8 *)SNI_RM200_INT_ENA_REG = 0x1f;
sni_rm200_i8259_irqs();
mips_cpu_irq_init();
for (i = SNI_RM200_INT_START; i <= SNI_RM200_INT_END; i++)
irq_set_chip_and_handler(i, &rm200_irq_type, handle_level_irq);
sni_hwint = sni_rm200_hwint;
change_c0_status(ST0_IM, IE_IRQ0);
setup_irq(SNI_RM200_INT_START + 0, &sni_rm200_i8259A_irq);
setup_irq(SNI_RM200_INT_START + 1, &sni_isa_irq);
}
void __init sni_rm200_init(void)
{
}
