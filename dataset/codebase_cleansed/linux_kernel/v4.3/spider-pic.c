static struct spider_pic *spider_irq_data_to_pic(struct irq_data *d)
{
return irq_data_get_irq_chip_data(d);
}
static void __iomem *spider_get_irq_config(struct spider_pic *pic,
unsigned int src)
{
return pic->regs + TIR_CFGA + 8 * src;
}
static void spider_unmask_irq(struct irq_data *d)
{
struct spider_pic *pic = spider_irq_data_to_pic(d);
void __iomem *cfg = spider_get_irq_config(pic, irqd_to_hwirq(d));
out_be32(cfg, in_be32(cfg) | 0x30000000u);
}
static void spider_mask_irq(struct irq_data *d)
{
struct spider_pic *pic = spider_irq_data_to_pic(d);
void __iomem *cfg = spider_get_irq_config(pic, irqd_to_hwirq(d));
out_be32(cfg, in_be32(cfg) & ~0x30000000u);
}
static void spider_ack_irq(struct irq_data *d)
{
struct spider_pic *pic = spider_irq_data_to_pic(d);
unsigned int src = irqd_to_hwirq(d);
if (irqd_is_level_type(d))
return;
if (src < 47 || src > 50)
return;
out_be32(pic->regs + TIR_EDC, 0x100 | (src & 0xf));
}
static int spider_set_irq_type(struct irq_data *d, unsigned int type)
{
unsigned int sense = type & IRQ_TYPE_SENSE_MASK;
struct spider_pic *pic = spider_irq_data_to_pic(d);
unsigned int hw = irqd_to_hwirq(d);
void __iomem *cfg = spider_get_irq_config(pic, hw);
u32 old_mask;
u32 ic;
if (sense != IRQ_TYPE_NONE && sense != IRQ_TYPE_LEVEL_HIGH &&
(hw < 47 || hw > 50))
return -EINVAL;
switch(sense) {
case IRQ_TYPE_EDGE_RISING:
ic = 0x3;
break;
case IRQ_TYPE_EDGE_FALLING:
ic = 0x2;
break;
case IRQ_TYPE_LEVEL_LOW:
ic = 0x0;
break;
case IRQ_TYPE_LEVEL_HIGH:
case IRQ_TYPE_NONE:
ic = 0x1;
break;
default:
return -EINVAL;
}
old_mask = in_be32(cfg) & 0x30000000u;
out_be32(cfg, old_mask | (ic << 24) | (0x7 << 16) |
(pic->node_id << 4) | 0xe);
out_be32(cfg + 4, (0x2 << 16) | (hw & 0xff));
return 0;
}
static int spider_host_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_data(virq, h->host_data);
irq_set_chip_and_handler(virq, &spider_pic, handle_level_irq);
irq_set_irq_type(virq, IRQ_TYPE_NONE);
return 0;
}
static int spider_host_xlate(struct irq_domain *h, struct device_node *ct,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_flags)
{
*out_hwirq = intspec[0] & 0x3f;
*out_flags = IRQ_TYPE_LEVEL_HIGH;
return 0;
}
static void spider_irq_cascade(struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct spider_pic *pic = irq_desc_get_handler_data(desc);
unsigned int cs, virq;
cs = in_be32(pic->regs + TIR_CS) >> 24;
if (cs == SPIDER_IRQ_INVALID)
virq = NO_IRQ;
else
virq = irq_linear_revmap(pic->host, cs);
if (virq != NO_IRQ)
generic_handle_irq(virq);
chip->irq_eoi(&desc->irq_data);
}
static unsigned int __init spider_find_cascade_and_node(struct spider_pic *pic)
{
unsigned int virq;
const u32 *imap, *tmp;
int imaplen, intsize, unit;
struct device_node *iic;
virq = irq_of_parse_and_map(pic->host->of_node, 0);
if (virq)
return virq;
tmp = of_get_property(pic->host->of_node, "#interrupt-cells", NULL);
if (tmp == NULL)
return NO_IRQ;
intsize = *tmp;
imap = of_get_property(pic->host->of_node, "interrupt-map", &imaplen);
if (imap == NULL || imaplen < (intsize + 1))
return NO_IRQ;
iic = of_find_node_by_phandle(imap[intsize]);
if (iic == NULL)
return NO_IRQ;
imap += intsize + 1;
tmp = of_get_property(iic, "#interrupt-cells", NULL);
if (tmp == NULL) {
of_node_put(iic);
return NO_IRQ;
}
intsize = *tmp;
unit = imap[intsize - 1];
tmp = of_get_property(iic, "ibm,interrupt-server-ranges", NULL);
if (tmp == NULL) {
of_node_put(iic);
return NO_IRQ;
}
pic->node_id = (*tmp) >> 1;
of_node_put(iic);
virq = irq_create_mapping(NULL,
(pic->node_id << IIC_IRQ_NODE_SHIFT) |
(2 << IIC_IRQ_CLASS_SHIFT) |
unit);
if (virq == NO_IRQ)
printk(KERN_ERR "spider_pic: failed to map cascade !");
return virq;
}
static void __init spider_init_one(struct device_node *of_node, int chip,
unsigned long addr)
{
struct spider_pic *pic = &spider_pics[chip];
int i, virq;
pic->regs = ioremap(addr, 0x1000);
if (pic->regs == NULL)
panic("spider_pic: can't map registers !");
pic->host = irq_domain_add_linear(of_node, SPIDER_SRC_COUNT,
&spider_host_ops, pic);
if (pic->host == NULL)
panic("spider_pic: can't allocate irq host !");
for (i = 0; i < SPIDER_SRC_COUNT; i++) {
void __iomem *cfg = pic->regs + TIR_CFGA + 8 * i;
out_be32(cfg, in_be32(cfg) & ~0x30000000u);
}
out_be32(pic->regs + TIR_MSK, 0x0);
out_be32(pic->regs + TIR_PIEN, in_be32(pic->regs + TIR_PIEN) | 0x1);
virq = spider_find_cascade_and_node(pic);
if (virq == NO_IRQ)
return;
irq_set_handler_data(virq, pic);
irq_set_chained_handler(virq, spider_irq_cascade);
printk(KERN_INFO "spider_pic: node %d, addr: 0x%lx %s\n",
pic->node_id, addr, of_node->full_name);
out_be32(pic->regs + TIR_DEN, in_be32(pic->regs + TIR_DEN) | 0x1);
}
void __init spider_init_IRQ(void)
{
struct resource r;
struct device_node *dn;
int chip = 0;
for (dn = NULL;
(dn = of_find_node_by_name(dn, "interrupt-controller"));) {
if (of_device_is_compatible(dn, "CBEA,platform-spider-pic")) {
if (of_address_to_resource(dn, 0, &r)) {
printk(KERN_WARNING "spider-pic: Failed\n");
continue;
}
} else if (of_device_is_compatible(dn, "sti,platform-spider-pic")
&& (chip < 2)) {
static long hard_coded_pics[] =
{ 0x24000008000ul, 0x34000008000ul};
r.start = hard_coded_pics[chip];
} else
continue;
spider_init_one(dn, chip++, r.start);
}
}
