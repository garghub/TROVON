static int sdv_gpio_pub_set_type(struct irq_data *d, unsigned int type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct sdv_gpio_chip_data *sd = gc->private;
void __iomem *type_reg;
u32 reg;
if (d->hwirq < 8)
type_reg = sd->gpio_pub_base + GPIT1R0;
else
type_reg = sd->gpio_pub_base + GPIT1R1;
reg = readl(type_reg);
switch (type) {
case IRQ_TYPE_LEVEL_HIGH:
reg &= ~BIT(4 * (d->hwirq % 8));
break;
case IRQ_TYPE_LEVEL_LOW:
reg |= BIT(4 * (d->hwirq % 8));
break;
default:
return -EINVAL;
}
writel(reg, type_reg);
return 0;
}
static irqreturn_t sdv_gpio_pub_irq_handler(int irq, void *data)
{
struct sdv_gpio_chip_data *sd = data;
u32 irq_stat = readl(sd->gpio_pub_base + GPSTR);
irq_stat &= readl(sd->gpio_pub_base + GPIO_INT);
if (!irq_stat)
return IRQ_NONE;
while (irq_stat) {
u32 irq_bit = __fls(irq_stat);
irq_stat &= ~BIT(irq_bit);
generic_handle_irq(irq_find_mapping(sd->id, irq_bit));
}
return IRQ_HANDLED;
}
static int sdv_xlate(struct irq_domain *h, struct device_node *node,
const u32 *intspec, u32 intsize, irq_hw_number_t *out_hwirq,
u32 *out_type)
{
u32 line, type;
if (node != irq_domain_get_of_node(h))
return -EINVAL;
if (intsize < 2)
return -EINVAL;
line = *intspec;
*out_hwirq = line;
intspec++;
type = *intspec;
switch (type) {
case IRQ_TYPE_LEVEL_LOW:
case IRQ_TYPE_LEVEL_HIGH:
*out_type = type;
break;
default:
return -EINVAL;
}
return 0;
}
static int sdv_register_irqsupport(struct sdv_gpio_chip_data *sd,
struct pci_dev *pdev)
{
struct irq_chip_type *ct;
int ret;
sd->irq_base = irq_alloc_descs(-1, 0, SDV_NUM_PUB_GPIOS, -1);
if (sd->irq_base < 0)
return sd->irq_base;
writel(0, sd->gpio_pub_base + GPIO_INT);
writel((1 << 11) - 1, sd->gpio_pub_base + GPSTR);
ret = request_irq(pdev->irq, sdv_gpio_pub_irq_handler, IRQF_SHARED,
"sdv_gpio", sd);
if (ret)
goto out_free_desc;
sd->gc = irq_alloc_generic_chip("sdv-gpio", 1, sd->irq_base,
sd->gpio_pub_base, handle_fasteoi_irq);
if (!sd->gc) {
ret = -ENOMEM;
goto out_free_irq;
}
sd->gc->private = sd;
ct = sd->gc->chip_types;
ct->type = IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW;
ct->regs.eoi = GPSTR;
ct->regs.mask = GPIO_INT;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->chip.irq_eoi = irq_gc_eoi;
ct->chip.irq_set_type = sdv_gpio_pub_set_type;
irq_setup_generic_chip(sd->gc, IRQ_MSK(SDV_NUM_PUB_GPIOS),
IRQ_GC_INIT_MASK_CACHE, IRQ_NOREQUEST,
IRQ_LEVEL | IRQ_NOPROBE);
sd->id = irq_domain_add_legacy(pdev->dev.of_node, SDV_NUM_PUB_GPIOS,
sd->irq_base, 0, &irq_domain_sdv_ops, sd);
if (!sd->id) {
ret = -ENODEV;
goto out_free_irq;
}
return 0;
out_free_irq:
free_irq(pdev->irq, sd);
out_free_desc:
irq_free_descs(sd->irq_base, SDV_NUM_PUB_GPIOS);
return ret;
}
static int sdv_gpio_probe(struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
struct sdv_gpio_chip_data *sd;
unsigned long addr;
const void *prop;
int len;
int ret;
u32 mux_val;
sd = kzalloc(sizeof(struct sdv_gpio_chip_data), GFP_KERNEL);
if (!sd)
return -ENOMEM;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "can't enable device.\n");
goto done;
}
ret = pci_request_region(pdev, GPIO_BAR, DRV_NAME);
if (ret) {
dev_err(&pdev->dev, "can't alloc PCI BAR #%d\n", GPIO_BAR);
goto disable_pci;
}
addr = pci_resource_start(pdev, GPIO_BAR);
if (!addr) {
ret = -ENODEV;
goto release_reg;
}
sd->gpio_pub_base = ioremap(addr, pci_resource_len(pdev, GPIO_BAR));
prop = of_get_property(pdev->dev.of_node, "intel,muxctl", &len);
if (prop && len == 4) {
mux_val = of_read_number(prop, 1);
writel(mux_val, sd->gpio_pub_base + GPMUXCTL);
}
ret = bgpio_init(&sd->chip, &pdev->dev, 4,
sd->gpio_pub_base + GPINR, sd->gpio_pub_base + GPOUTR,
NULL, sd->gpio_pub_base + GPOER, NULL, 0);
if (ret)
goto unmap;
sd->chip.ngpio = SDV_NUM_PUB_GPIOS;
ret = gpiochip_add_data(&sd->chip, sd);
if (ret < 0) {
dev_err(&pdev->dev, "gpiochip_add() failed.\n");
goto unmap;
}
ret = sdv_register_irqsupport(sd, pdev);
if (ret)
goto unmap;
pci_set_drvdata(pdev, sd);
dev_info(&pdev->dev, "Sodaville GPIO driver registered.\n");
return 0;
unmap:
iounmap(sd->gpio_pub_base);
release_reg:
pci_release_region(pdev, GPIO_BAR);
disable_pci:
pci_disable_device(pdev);
done:
kfree(sd);
return ret;
}
static void sdv_gpio_remove(struct pci_dev *pdev)
{
struct sdv_gpio_chip_data *sd = pci_get_drvdata(pdev);
free_irq(pdev->irq, sd);
irq_free_descs(sd->irq_base, SDV_NUM_PUB_GPIOS);
gpiochip_remove(&sd->chip);
pci_release_region(pdev, GPIO_BAR);
iounmap(sd->gpio_pub_base);
pci_disable_device(pdev);
kfree(sd);
}
