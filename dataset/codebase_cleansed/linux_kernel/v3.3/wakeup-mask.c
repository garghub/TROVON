void samsung_sync_wakemask(void __iomem *reg,
struct samsung_wakeup_mask *mask, int nr_mask)
{
struct irq_data *data;
u32 val;
val = __raw_readl(reg);
for (; nr_mask > 0; nr_mask--, mask++) {
if (mask->irq == NO_WAKEUP_IRQ) {
val |= mask->bit;
continue;
}
data = irq_get_irq_data(mask->irq);
if (irqd_is_wakeup_set(data))
val &= ~mask->bit;
else
val |= mask->bit;
}
printk(KERN_INFO "wakemask %08x => %08x\n", __raw_readl(reg), val);
__raw_writel(val, reg);
}
