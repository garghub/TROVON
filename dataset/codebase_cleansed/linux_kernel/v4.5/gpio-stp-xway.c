static void xway_stp_set(struct gpio_chip *gc, unsigned gpio, int val)
{
struct xway_stp *chip = gpiochip_get_data(gc);
if (val)
chip->shadow |= BIT(gpio);
else
chip->shadow &= ~BIT(gpio);
xway_stp_w32(chip->virt, chip->shadow, XWAY_STP_CPU0);
xway_stp_w32_mask(chip->virt, 0, XWAY_STP_CON_SWU, XWAY_STP_CON0);
}
static int xway_stp_dir_out(struct gpio_chip *gc, unsigned gpio, int val)
{
xway_stp_set(gc, gpio, val);
return 0;
}
static int xway_stp_request(struct gpio_chip *gc, unsigned gpio)
{
struct xway_stp *chip = gpiochip_get_data(gc);
if ((gpio < 8) && (chip->reserved & BIT(gpio))) {
dev_err(gc->parent, "GPIO %d is driven by hardware\n", gpio);
return -ENODEV;
}
return 0;
}
static int xway_stp_hw_init(struct xway_stp *chip)
{
xway_stp_w32(chip->virt, 0, XWAY_STP_AR);
xway_stp_w32(chip->virt, 0, XWAY_STP_CPU0);
xway_stp_w32(chip->virt, 0, XWAY_STP_CPU1);
xway_stp_w32(chip->virt, XWAY_STP_CON_SWU, XWAY_STP_CON0);
xway_stp_w32(chip->virt, 0, XWAY_STP_CON1);
xway_stp_w32_mask(chip->virt, XWAY_STP_EDGE_MASK,
chip->edge, XWAY_STP_CON0);
xway_stp_w32_mask(chip->virt, XWAY_STP_GROUP_MASK,
chip->groups, XWAY_STP_CON1);
xway_stp_w32_mask(chip->virt,
XWAY_STP_ADSL_MASK << XWAY_STP_ADSL_SHIFT,
chip->dsl << XWAY_STP_ADSL_SHIFT,
XWAY_STP_CON0);
xway_stp_w32_mask(chip->virt,
XWAY_STP_PHY_MASK << XWAY_STP_PHY1_SHIFT,
chip->phy1 << XWAY_STP_PHY1_SHIFT,
XWAY_STP_CON0);
xway_stp_w32_mask(chip->virt,
XWAY_STP_PHY_MASK << XWAY_STP_PHY2_SHIFT,
chip->phy2 << XWAY_STP_PHY2_SHIFT,
XWAY_STP_CON1);
chip->reserved = (chip->phy2 << 5) | (chip->phy1 << 2) | chip->dsl;
if (chip->reserved)
xway_stp_w32_mask(chip->virt, XWAY_STP_UPD_MASK,
XWAY_STP_UPD_FPI, XWAY_STP_CON1);
return 0;
}
static int xway_stp_probe(struct platform_device *pdev)
{
struct resource *res;
u32 shadow, groups, dsl, phy;
struct xway_stp *chip;
struct clk *clk;
int ret = 0;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
chip->virt = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(chip->virt))
return PTR_ERR(chip->virt);
chip->gc.parent = &pdev->dev;
chip->gc.label = "stp-xway";
chip->gc.direction_output = xway_stp_dir_out;
chip->gc.set = xway_stp_set;
chip->gc.request = xway_stp_request;
chip->gc.base = -1;
chip->gc.owner = THIS_MODULE;
if (!of_property_read_u32(pdev->dev.of_node, "lantiq,shadow", &shadow))
chip->shadow = shadow;
if (!of_property_read_u32(pdev->dev.of_node, "lantiq,groups", &groups))
chip->groups = groups & XWAY_STP_GROUP_MASK;
else
chip->groups = XWAY_STP_GROUP0;
chip->gc.ngpio = fls(chip->groups) * 8;
if (!of_property_read_u32(pdev->dev.of_node, "lantiq,dsl", &dsl))
chip->dsl = dsl & XWAY_STP_ADSL_MASK;
if (of_machine_is_compatible("lantiq,ar9") ||
of_machine_is_compatible("lantiq,gr9") ||
of_machine_is_compatible("lantiq,vr9")) {
if (!of_property_read_u32(pdev->dev.of_node, "lantiq,phy1", &phy))
chip->phy1 = phy & XWAY_STP_PHY_MASK;
if (!of_property_read_u32(pdev->dev.of_node, "lantiq,phy2", &phy))
chip->phy2 = phy & XWAY_STP_PHY_MASK;
}
if (!of_find_property(pdev->dev.of_node, "lantiq,rising", NULL))
chip->edge = XWAY_STP_FALLING;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "Failed to get clock\n");
return PTR_ERR(clk);
}
clk_enable(clk);
ret = xway_stp_hw_init(chip);
if (!ret)
ret = gpiochip_add_data(&chip->gc, chip);
if (!ret)
dev_info(&pdev->dev, "Init done\n");
return ret;
}
static int __init xway_stp_init(void)
{
return platform_driver_register(&xway_stp_driver);
}
