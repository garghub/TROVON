static void mask_8259A_irq(unsigned int irq)
{
unsigned int mask = 1 << irq;
unsigned long flags;
raw_spin_lock_irqsave(&i8259A_lock, flags);
cached_irq_mask |= mask;
if (irq & 8)
outb(cached_slave_mask, PIC_SLAVE_IMR);
else
outb(cached_master_mask, PIC_MASTER_IMR);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
}
static void disable_8259A_irq(struct irq_data *data)
{
mask_8259A_irq(data->irq);
}
static void unmask_8259A_irq(unsigned int irq)
{
unsigned int mask = ~(1 << irq);
unsigned long flags;
raw_spin_lock_irqsave(&i8259A_lock, flags);
cached_irq_mask &= mask;
if (irq & 8)
outb(cached_slave_mask, PIC_SLAVE_IMR);
else
outb(cached_master_mask, PIC_MASTER_IMR);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
}
static void enable_8259A_irq(struct irq_data *data)
{
unmask_8259A_irq(data->irq);
}
static int i8259A_irq_pending(unsigned int irq)
{
unsigned int mask = 1<<irq;
unsigned long flags;
int ret;
raw_spin_lock_irqsave(&i8259A_lock, flags);
if (irq < 8)
ret = inb(PIC_MASTER_CMD) & mask;
else
ret = inb(PIC_SLAVE_CMD) & (mask >> 8);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
return ret;
}
static void make_8259A_irq(unsigned int irq)
{
disable_irq_nosync(irq);
io_apic_irqs &= ~(1<<irq);
irq_set_chip_and_handler(irq, &i8259A_chip, handle_level_irq);
enable_irq(irq);
}
static inline int i8259A_irq_real(unsigned int irq)
{
int value;
int irqmask = 1<<irq;
if (irq < 8) {
outb(0x0B, PIC_MASTER_CMD);
value = inb(PIC_MASTER_CMD) & irqmask;
outb(0x0A, PIC_MASTER_CMD);
return value;
}
outb(0x0B, PIC_SLAVE_CMD);
value = inb(PIC_SLAVE_CMD) & (irqmask >> 8);
outb(0x0A, PIC_SLAVE_CMD);
return value;
}
static void mask_and_ack_8259A(struct irq_data *data)
{
unsigned int irq = data->irq;
unsigned int irqmask = 1 << irq;
unsigned long flags;
raw_spin_lock_irqsave(&i8259A_lock, flags);
if (cached_irq_mask & irqmask)
goto spurious_8259A_irq;
cached_irq_mask |= irqmask;
handle_real_irq:
if (irq & 8) {
inb(PIC_SLAVE_IMR);
outb(cached_slave_mask, PIC_SLAVE_IMR);
outb(0x60+(irq&7), PIC_SLAVE_CMD);
outb(0x60+PIC_CASCADE_IR, PIC_MASTER_CMD);
} else {
inb(PIC_MASTER_IMR);
outb(cached_master_mask, PIC_MASTER_IMR);
outb(0x60+irq, PIC_MASTER_CMD);
}
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
return;
spurious_8259A_irq:
if (i8259A_irq_real(irq))
goto handle_real_irq;
{
static int spurious_irq_mask;
if (!(spurious_irq_mask & irqmask)) {
printk(KERN_DEBUG
"spurious 8259A interrupt: IRQ%d.\n", irq);
spurious_irq_mask |= irqmask;
}
atomic_inc(&irq_err_count);
goto handle_real_irq;
}
}
static void restore_ELCR(char *trigger)
{
outb(trigger[0], 0x4d0);
outb(trigger[1], 0x4d1);
}
static void save_ELCR(char *trigger)
{
trigger[0] = inb(0x4d0) & 0xF8;
trigger[1] = inb(0x4d1) & 0xDE;
}
static void i8259A_resume(void)
{
init_8259A(i8259A_auto_eoi);
restore_ELCR(irq_trigger);
}
static int i8259A_suspend(void)
{
save_ELCR(irq_trigger);
return 0;
}
static void i8259A_shutdown(void)
{
outb(0xff, PIC_MASTER_IMR);
outb(0xff, PIC_SLAVE_IMR);
}
static void mask_8259A(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&i8259A_lock, flags);
outb(0xff, PIC_MASTER_IMR);
outb(0xff, PIC_SLAVE_IMR);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
}
static void unmask_8259A(void)
{
unsigned long flags;
raw_spin_lock_irqsave(&i8259A_lock, flags);
outb(cached_master_mask, PIC_MASTER_IMR);
outb(cached_slave_mask, PIC_SLAVE_IMR);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
}
static void init_8259A(int auto_eoi)
{
unsigned long flags;
unsigned char probe_val = ~(1 << PIC_CASCADE_IR);
unsigned char new_val;
i8259A_auto_eoi = auto_eoi;
raw_spin_lock_irqsave(&i8259A_lock, flags);
outb(0xff, PIC_SLAVE_IMR);
outb(probe_val, PIC_MASTER_IMR);
new_val = inb(PIC_MASTER_IMR);
if (new_val != probe_val) {
printk(KERN_INFO "Using NULL legacy PIC\n");
legacy_pic = &null_legacy_pic;
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
return;
}
outb(0xff, PIC_MASTER_IMR);
outb_pic(0x11, PIC_MASTER_CMD);
outb_pic(ISA_IRQ_VECTOR(0), PIC_MASTER_IMR);
outb_pic(1U << PIC_CASCADE_IR, PIC_MASTER_IMR);
if (auto_eoi)
outb_pic(MASTER_ICW4_DEFAULT | PIC_ICW4_AEOI, PIC_MASTER_IMR);
else
outb_pic(MASTER_ICW4_DEFAULT, PIC_MASTER_IMR);
outb_pic(0x11, PIC_SLAVE_CMD);
outb_pic(ISA_IRQ_VECTOR(8), PIC_SLAVE_IMR);
outb_pic(PIC_CASCADE_IR, PIC_SLAVE_IMR);
outb_pic(SLAVE_ICW4_DEFAULT, PIC_SLAVE_IMR);
if (auto_eoi)
i8259A_chip.irq_mask_ack = disable_8259A_irq;
else
i8259A_chip.irq_mask_ack = mask_and_ack_8259A;
udelay(100);
outb(cached_master_mask, PIC_MASTER_IMR);
outb(cached_slave_mask, PIC_SLAVE_IMR);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
}
static void legacy_pic_noop(void) { }
static void legacy_pic_uint_noop(unsigned int unused) { }
static void legacy_pic_int_noop(int unused) { }
static int legacy_pic_irq_pending_noop(unsigned int irq)
{
return 0;
}
static int __init i8259A_init_ops(void)
{
if (legacy_pic == &default_legacy_pic)
register_syscore_ops(&i8259_syscore_ops);
return 0;
}
