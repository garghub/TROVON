static int etraxfs_gpio_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec,
u32 *flags)
{
if (gc->label[0] - 'A' + 0xA != gpiospec->args[2])
return -EINVAL;
return of_gpio_simple_xlate(gc, gpiospec, flags);
}
static int etraxfs_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct etraxfs_gpio_info *info;
const struct of_device_id *match;
struct bgpio_chip *chips;
struct resource *res;
void __iomem *regs;
int ret;
int i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (!regs)
return -ENOMEM;
match = of_match_node(etraxfs_gpio_of_table, dev->of_node);
if (!match)
return -EINVAL;
info = match->data;
chips = devm_kzalloc(dev, sizeof(*chips) * info->num_ports, GFP_KERNEL);
if (!chips)
return -ENOMEM;
for (i = 0; i < info->num_ports; i++) {
struct bgpio_chip *bgc = &chips[i];
const struct etraxfs_gpio_port *port = &info->ports[i];
ret = bgpio_init(bgc, dev, 4,
regs + port->din,
regs + port->dout,
NULL,
regs + port->oe,
NULL,
BGPIOF_UNREADABLE_REG_SET);
if (ret)
return ret;
bgc->gc.ngpio = port->ngpio;
bgc->gc.label = port->label;
bgc->gc.of_node = dev->of_node;
bgc->gc.of_gpio_n_cells = 3;
bgc->gc.of_xlate = etraxfs_gpio_of_xlate;
ret = gpiochip_add(&bgc->gc);
if (ret)
dev_err(dev, "Unable to register port %s\n",
bgc->gc.label);
}
return 0;
}
static int __init etraxfs_gpio_init(void)
{
return platform_driver_register(&etraxfs_gpio_driver);
}
