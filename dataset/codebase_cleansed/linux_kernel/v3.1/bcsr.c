void __init bcsr_init(unsigned long bcsr1_phys, unsigned long bcsr2_phys)
{
int i;
bcsr1_phys = KSEG1ADDR(CPHYSADDR(bcsr1_phys));
bcsr2_phys = KSEG1ADDR(CPHYSADDR(bcsr2_phys));
bcsr_virt = (void __iomem *)bcsr1_phys;
for (i = 0; i < BCSR_CNT; i++) {
if (i >= BCSR_HEXLEDS)
bcsr_regs[i].raddr = (void __iomem *)bcsr2_phys +
(0x04 * (i - BCSR_HEXLEDS));
else
bcsr_regs[i].raddr = (void __iomem *)bcsr1_phys +
(0x04 * i);
spin_lock_init(&bcsr_regs[i].lock);
}
}
unsigned short bcsr_read(enum bcsr_id reg)
{
unsigned short r;
unsigned long flags;
spin_lock_irqsave(&bcsr_regs[reg].lock, flags);
r = __raw_readw(bcsr_regs[reg].raddr);
spin_unlock_irqrestore(&bcsr_regs[reg].lock, flags);
return r;
}
void bcsr_write(enum bcsr_id reg, unsigned short val)
{
unsigned long flags;
spin_lock_irqsave(&bcsr_regs[reg].lock, flags);
__raw_writew(val, bcsr_regs[reg].raddr);
wmb();
spin_unlock_irqrestore(&bcsr_regs[reg].lock, flags);
}
void bcsr_mod(enum bcsr_id reg, unsigned short clr, unsigned short set)
{
unsigned short r;
unsigned long flags;
spin_lock_irqsave(&bcsr_regs[reg].lock, flags);
r = __raw_readw(bcsr_regs[reg].raddr);
r &= ~clr;
r |= set;
__raw_writew(r, bcsr_regs[reg].raddr);
wmb();
spin_unlock_irqrestore(&bcsr_regs[reg].lock, flags);
}
static void bcsr_csc_handler(unsigned int irq, struct irq_desc *d)
{
unsigned short bisr = __raw_readw(bcsr_virt + BCSR_REG_INTSTAT);
disable_irq_nosync(irq);
for ( ; bisr; bisr &= bisr - 1)
generic_handle_irq(bcsr_csc_base + __ffs(bisr));
enable_irq(irq);
}
static void bcsr_irq_mask(struct irq_data *d)
{
unsigned short v = 1 << (d->irq - bcsr_csc_base);
__raw_writew(v, bcsr_virt + BCSR_REG_INTCLR);
__raw_writew(v, bcsr_virt + BCSR_REG_MASKCLR);
wmb();
}
static void bcsr_irq_maskack(struct irq_data *d)
{
unsigned short v = 1 << (d->irq - bcsr_csc_base);
__raw_writew(v, bcsr_virt + BCSR_REG_INTCLR);
__raw_writew(v, bcsr_virt + BCSR_REG_MASKCLR);
__raw_writew(v, bcsr_virt + BCSR_REG_INTSTAT);
wmb();
}
static void bcsr_irq_unmask(struct irq_data *d)
{
unsigned short v = 1 << (d->irq - bcsr_csc_base);
__raw_writew(v, bcsr_virt + BCSR_REG_INTSET);
__raw_writew(v, bcsr_virt + BCSR_REG_MASKSET);
wmb();
}
void __init bcsr_init_irq(int csc_start, int csc_end, int hook_irq)
{
unsigned int irq;
__raw_writew(0xffff, bcsr_virt + BCSR_REG_INTCLR);
__raw_writew(0xffff, bcsr_virt + BCSR_REG_MASKCLR);
__raw_writew(0xffff, bcsr_virt + BCSR_REG_INTSTAT);
wmb();
bcsr_csc_base = csc_start;
for (irq = csc_start; irq <= csc_end; irq++)
irq_set_chip_and_handler_name(irq, &bcsr_irq_type,
handle_level_irq, "level");
irq_set_chained_handler(hook_irq, bcsr_csc_handler);
}
