static int bcm2835_aux_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct clk_hw_onecell_data *onecell;
const char *parent;
struct clk *parent_clk;
struct resource *res;
void __iomem *reg, *gate;
parent_clk = devm_clk_get(dev, NULL);
if (IS_ERR(parent_clk))
return PTR_ERR(parent_clk);
parent = __clk_get_name(parent_clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
onecell = devm_kmalloc(dev, sizeof(*onecell) + sizeof(*onecell->hws) *
BCM2835_AUX_CLOCK_COUNT, GFP_KERNEL);
if (!onecell)
return -ENOMEM;
onecell->num = BCM2835_AUX_CLOCK_COUNT;
gate = reg + BCM2835_AUXENB;
onecell->hws[BCM2835_AUX_CLOCK_UART] =
clk_hw_register_gate(dev, "aux_uart", parent, 0, gate, 0, 0, NULL);
onecell->hws[BCM2835_AUX_CLOCK_SPI1] =
clk_hw_register_gate(dev, "aux_spi1", parent, 0, gate, 1, 0, NULL);
onecell->hws[BCM2835_AUX_CLOCK_SPI2] =
clk_hw_register_gate(dev, "aux_spi2", parent, 0, gate, 2, 0, NULL);
return of_clk_add_hw_provider(pdev->dev.of_node, of_clk_hw_onecell_get,
onecell);
}
