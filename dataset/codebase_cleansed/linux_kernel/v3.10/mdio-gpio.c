static void *mdio_gpio_of_get_data(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mdio_gpio_platform_data *pdata;
int ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
ret = of_get_gpio(np, 0);
if (ret < 0)
return NULL;
pdata->mdc = ret;
ret = of_get_gpio(np, 1);
if (ret < 0)
return NULL;
pdata->mdio = ret;
return pdata;
}
static void mdio_dir(struct mdiobb_ctrl *ctrl, int dir)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
if (dir)
gpio_direction_output(bitbang->mdio, 1);
else
gpio_direction_input(bitbang->mdio);
}
static int mdio_get(struct mdiobb_ctrl *ctrl)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
return gpio_get_value(bitbang->mdio);
}
static void mdio_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
gpio_set_value(bitbang->mdio, what);
}
static void mdc_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
gpio_set_value(bitbang->mdc, what);
}
static struct mii_bus *mdio_gpio_bus_init(struct device *dev,
struct mdio_gpio_platform_data *pdata,
int bus_id)
{
struct mii_bus *new_bus;
struct mdio_gpio_info *bitbang;
int i;
bitbang = kzalloc(sizeof(*bitbang), GFP_KERNEL);
if (!bitbang)
goto out;
bitbang->ctrl.ops = &mdio_gpio_ops;
bitbang->ctrl.reset = pdata->reset;
bitbang->mdc = pdata->mdc;
bitbang->mdio = pdata->mdio;
new_bus = alloc_mdio_bitbang(&bitbang->ctrl);
if (!new_bus)
goto out_free_bitbang;
new_bus->name = "GPIO Bitbanged MDIO",
new_bus->phy_mask = pdata->phy_mask;
new_bus->irq = pdata->irqs;
new_bus->parent = dev;
if (new_bus->phy_mask == ~0)
goto out_free_bus;
for (i = 0; i < PHY_MAX_ADDR; i++)
if (!new_bus->irq[i])
new_bus->irq[i] = PHY_POLL;
snprintf(new_bus->id, MII_BUS_ID_SIZE, "gpio-%x", bus_id);
if (gpio_request(bitbang->mdc, "mdc"))
goto out_free_bus;
if (gpio_request(bitbang->mdio, "mdio"))
goto out_free_mdc;
gpio_direction_output(bitbang->mdc, 0);
dev_set_drvdata(dev, new_bus);
return new_bus;
out_free_mdc:
gpio_free(bitbang->mdc);
out_free_bus:
free_mdio_bitbang(new_bus);
out_free_bitbang:
kfree(bitbang);
out:
return NULL;
}
static void mdio_gpio_bus_deinit(struct device *dev)
{
struct mii_bus *bus = dev_get_drvdata(dev);
struct mdio_gpio_info *bitbang = bus->priv;
dev_set_drvdata(dev, NULL);
gpio_free(bitbang->mdio);
gpio_free(bitbang->mdc);
free_mdio_bitbang(bus);
kfree(bitbang);
}
static void mdio_gpio_bus_destroy(struct device *dev)
{
struct mii_bus *bus = dev_get_drvdata(dev);
mdiobus_unregister(bus);
mdio_gpio_bus_deinit(dev);
}
static int mdio_gpio_probe(struct platform_device *pdev)
{
struct mdio_gpio_platform_data *pdata;
struct mii_bus *new_bus;
int ret, bus_id;
if (pdev->dev.of_node) {
pdata = mdio_gpio_of_get_data(pdev);
bus_id = of_alias_get_id(pdev->dev.of_node, "mdio-gpio");
} else {
pdata = pdev->dev.platform_data;
bus_id = pdev->id;
}
if (!pdata)
return -ENODEV;
new_bus = mdio_gpio_bus_init(&pdev->dev, pdata, bus_id);
if (!new_bus)
return -ENODEV;
if (pdev->dev.of_node)
ret = of_mdiobus_register(new_bus, pdev->dev.of_node);
else
ret = mdiobus_register(new_bus);
if (ret)
mdio_gpio_bus_deinit(&pdev->dev);
return ret;
}
static int mdio_gpio_remove(struct platform_device *pdev)
{
mdio_gpio_bus_destroy(&pdev->dev);
return 0;
}
