static inline unsigned int get_mbigen_vec_reg(irq_hw_number_t hwirq)
{
unsigned int nid, pin;
hwirq -= RESERVED_IRQ_PER_MBIGEN_CHIP;
nid = hwirq / IRQS_PER_MBIGEN_NODE + 1;
pin = hwirq % IRQS_PER_MBIGEN_NODE;
return pin * 4 + nid * MBIGEN_NODE_OFFSET
+ REG_MBIGEN_VEC_OFFSET;
}
static inline void get_mbigen_type_reg(irq_hw_number_t hwirq,
u32 *mask, u32 *addr)
{
unsigned int nid, irq_ofst, ofst;
hwirq -= RESERVED_IRQ_PER_MBIGEN_CHIP;
nid = hwirq / IRQS_PER_MBIGEN_NODE + 1;
irq_ofst = hwirq % IRQS_PER_MBIGEN_NODE;
*mask = 1 << (irq_ofst % 32);
ofst = irq_ofst / 32 * 4;
*addr = ofst + nid * MBIGEN_NODE_OFFSET
+ REG_MBIGEN_TYPE_OFFSET;
}
static inline void get_mbigen_clear_reg(irq_hw_number_t hwirq,
u32 *mask, u32 *addr)
{
unsigned int ofst;
hwirq -= RESERVED_IRQ_PER_MBIGEN_CHIP;
ofst = hwirq / 32 * 4;
*mask = 1 << (hwirq % 32);
*addr = ofst + REG_MBIGEN_CLEAR_OFFSET;
}
static void mbigen_eoi_irq(struct irq_data *data)
{
void __iomem *base = data->chip_data;
u32 mask, addr;
get_mbigen_clear_reg(data->hwirq, &mask, &addr);
writel_relaxed(mask, base + addr);
irq_chip_eoi_parent(data);
}
static int mbigen_set_type(struct irq_data *data, unsigned int type)
{
void __iomem *base = data->chip_data;
u32 mask, addr, val;
if (type != IRQ_TYPE_LEVEL_HIGH && type != IRQ_TYPE_EDGE_RISING)
return -EINVAL;
get_mbigen_type_reg(data->hwirq, &mask, &addr);
val = readl_relaxed(base + addr);
if (type == IRQ_TYPE_LEVEL_HIGH)
val |= mask;
else
val &= ~mask;
writel_relaxed(val, base + addr);
return 0;
}
static void mbigen_write_msg(struct msi_desc *desc, struct msi_msg *msg)
{
struct irq_data *d = irq_get_irq_data(desc->irq);
void __iomem *base = d->chip_data;
u32 val;
base += get_mbigen_vec_reg(d->hwirq);
val = readl_relaxed(base);
val &= ~(IRQ_EVENT_ID_MASK << IRQ_EVENT_ID_SHIFT);
val |= (msg->data << IRQ_EVENT_ID_SHIFT);
writel_relaxed(val, base);
}
static int mbigen_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
if (is_of_node(fwspec->fwnode)) {
if (fwspec->param_count != 2)
return -EINVAL;
if ((fwspec->param[0] > MAXIMUM_IRQ_PIN_NUM) ||
(fwspec->param[0] < RESERVED_IRQ_PER_MBIGEN_CHIP))
return -EINVAL;
else
*hwirq = fwspec->param[0];
if ((fwspec->param[1] == IRQ_TYPE_EDGE_RISING) ||
(fwspec->param[1] == IRQ_TYPE_LEVEL_HIGH))
*type = fwspec->param[1];
else
return -EINVAL;
return 0;
}
return -EINVAL;
}
static int mbigen_irq_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs,
void *args)
{
struct irq_fwspec *fwspec = args;
irq_hw_number_t hwirq;
unsigned int type;
struct mbigen_device *mgn_chip;
int i, err;
err = mbigen_domain_translate(domain, fwspec, &hwirq, &type);
if (err)
return err;
err = platform_msi_domain_alloc(domain, virq, nr_irqs);
if (err)
return err;
mgn_chip = platform_msi_get_host_data(domain);
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&mbigen_irq_chip, mgn_chip->base);
return 0;
}
static int mbigen_device_probe(struct platform_device *pdev)
{
struct mbigen_device *mgn_chip;
struct resource *res;
struct irq_domain *domain;
u32 num_pins;
mgn_chip = devm_kzalloc(&pdev->dev, sizeof(*mgn_chip), GFP_KERNEL);
if (!mgn_chip)
return -ENOMEM;
mgn_chip->pdev = pdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mgn_chip->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mgn_chip->base))
return PTR_ERR(mgn_chip->base);
if (of_property_read_u32(pdev->dev.of_node, "num-pins", &num_pins) < 0) {
dev_err(&pdev->dev, "No num-pins property\n");
return -EINVAL;
}
domain = platform_msi_create_device_domain(&pdev->dev, num_pins,
mbigen_write_msg,
&mbigen_domain_ops,
mgn_chip);
if (!domain)
return -ENOMEM;
platform_set_drvdata(pdev, mgn_chip);
dev_info(&pdev->dev, "Allocated %d MSIs\n", num_pins);
return 0;
}
