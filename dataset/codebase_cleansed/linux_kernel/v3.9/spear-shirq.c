static void shirq_irq_mask_unmask(struct irq_data *d, bool mask)
{
struct spear_shirq *shirq = irq_data_get_irq_chip_data(d);
u32 val, offset = d->irq - shirq->irq_base;
unsigned long flags;
if (shirq->regs.enb_reg == -1)
return;
spin_lock_irqsave(&lock, flags);
val = readl(shirq->base + shirq->regs.enb_reg);
if (mask ^ shirq->regs.reset_to_enb)
val &= ~(0x1 << shirq->irq_bit_off << offset);
else
val |= 0x1 << shirq->irq_bit_off << offset;
writel(val, shirq->base + shirq->regs.enb_reg);
spin_unlock_irqrestore(&lock, flags);
}
static void shirq_irq_mask(struct irq_data *d)
{
shirq_irq_mask_unmask(d, 1);
}
static void shirq_irq_unmask(struct irq_data *d)
{
shirq_irq_mask_unmask(d, 0);
}
static void shirq_handler(unsigned irq, struct irq_desc *desc)
{
u32 i, j, val, mask, tmp;
struct irq_chip *chip;
struct spear_shirq *shirq = irq_get_handler_data(irq);
chip = irq_get_chip(irq);
chip->irq_ack(&desc->irq_data);
mask = ((0x1 << shirq->irq_nr) - 1) << shirq->irq_bit_off;
while ((val = readl(shirq->base + shirq->regs.status_reg) &
mask)) {
val >>= shirq->irq_bit_off;
for (i = 0, j = 1; i < shirq->irq_nr; i++, j <<= 1) {
if (!(j & val))
continue;
generic_handle_irq(shirq->irq_base + i);
if (shirq->regs.clear_reg == -1)
continue;
tmp = readl(shirq->base + shirq->regs.clear_reg);
if (shirq->regs.reset_to_clear)
tmp &= ~(j << shirq->irq_bit_off);
else
tmp |= (j << shirq->irq_bit_off);
writel(tmp, shirq->base + shirq->regs.clear_reg);
}
}
chip->irq_unmask(&desc->irq_data);
}
static void __init spear_shirq_register(struct spear_shirq *shirq)
{
int i;
if (shirq->invalid_irq)
return;
irq_set_chained_handler(shirq->irq, shirq_handler);
for (i = 0; i < shirq->irq_nr; i++) {
irq_set_chip_and_handler(shirq->irq_base + i,
&shirq_chip, handle_simple_irq);
set_irq_flags(shirq->irq_base + i, IRQF_VALID);
irq_set_chip_data(shirq->irq_base + i, shirq);
}
irq_set_handler_data(shirq->irq, shirq);
}
static int __init shirq_init(struct spear_shirq **shirq_blocks, int block_nr,
struct device_node *np)
{
int i, irq_base, hwirq = 0, irq_nr = 0;
static struct irq_domain *shirq_domain;
void __iomem *base;
base = of_iomap(np, 0);
if (!base) {
pr_err("%s: failed to map shirq registers\n", __func__);
return -ENXIO;
}
for (i = 0; i < block_nr; i++)
irq_nr += shirq_blocks[i]->irq_nr;
irq_base = irq_alloc_descs(-1, 0, irq_nr, 0);
if (IS_ERR_VALUE(irq_base)) {
pr_err("%s: irq desc alloc failed\n", __func__);
goto err_unmap;
}
shirq_domain = irq_domain_add_legacy(np, irq_nr, irq_base, 0,
&irq_domain_simple_ops, NULL);
if (WARN_ON(!shirq_domain)) {
pr_warn("%s: irq domain init failed\n", __func__);
goto err_free_desc;
}
for (i = 0; i < block_nr; i++) {
shirq_blocks[i]->base = base;
shirq_blocks[i]->irq_base = irq_find_mapping(shirq_domain,
hwirq);
shirq_blocks[i]->irq = irq_of_parse_and_map(np, i);
spear_shirq_register(shirq_blocks[i]);
hwirq += shirq_blocks[i]->irq_nr;
}
return 0;
err_free_desc:
irq_free_descs(irq_base, irq_nr);
err_unmap:
iounmap(base);
return -ENXIO;
}
int __init spear300_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear300_shirq_blocks,
ARRAY_SIZE(spear300_shirq_blocks), np);
}
int __init spear310_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear310_shirq_blocks,
ARRAY_SIZE(spear310_shirq_blocks), np);
}
int __init spear320_shirq_of_init(struct device_node *np,
struct device_node *parent)
{
return shirq_init(spear320_shirq_blocks,
ARRAY_SIZE(spear320_shirq_blocks), np);
}
