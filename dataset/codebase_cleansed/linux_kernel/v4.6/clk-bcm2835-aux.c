static int bcm2835_aux_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct clk_onecell_data *onecell;
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
onecell = devm_kmalloc(dev, sizeof(*onecell), GFP_KERNEL);
if (!onecell)
return -ENOMEM;
onecell->clk_num = BCM2835_AUX_CLOCK_COUNT;
onecell->clks = devm_kcalloc(dev, BCM2835_AUX_CLOCK_COUNT,
sizeof(*onecell->clks), GFP_KERNEL);
if (!onecell->clks)
return -ENOMEM;
gate = reg + BCM2835_AUXENB;
onecell->clks[BCM2835_AUX_CLOCK_UART] =
clk_register_gate(dev, "aux_uart", parent, 0, gate, 0, 0, NULL);
onecell->clks[BCM2835_AUX_CLOCK_SPI1] =
clk_register_gate(dev, "aux_spi1", parent, 0, gate, 1, 0, NULL);
onecell->clks[BCM2835_AUX_CLOCK_SPI2] =
clk_register_gate(dev, "aux_spi2", parent, 0, gate, 2, 0, NULL);
of_clk_add_provider(pdev->dev.of_node, of_clk_src_onecell_get, onecell);
return 0;
}
