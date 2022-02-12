static void *mdio_gpio_of_get_data(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mdio_gpio_platform_data *pdata;
enum of_gpio_flags flags;
int ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
ret = of_get_gpio_flags(np, 0, &flags);
if (ret < 0)
return NULL;
pdata->mdc = ret;
pdata->mdc_active_low = flags & OF_GPIO_ACTIVE_LOW;
ret = of_get_gpio_flags(np, 1, &flags);
if (ret < 0)
return NULL;
pdata->mdio = ret;
pdata->mdio_active_low = flags & OF_GPIO_ACTIVE_LOW;
ret = of_get_gpio_flags(np, 2, &flags);
if (ret > 0) {
pdata->mdo = ret;
pdata->mdo_active_low = flags & OF_GPIO_ACTIVE_LOW;
}
return pdata;
}
static void mdio_dir(struct mdiobb_ctrl *ctrl, int dir)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
if (bitbang->mdo) {
gpio_set_value_cansleep(bitbang->mdo,
1 ^ bitbang->mdo_active_low);
return;
}
if (dir)
gpio_direction_output(bitbang->mdio,
1 ^ bitbang->mdio_active_low);
else
gpio_direction_input(bitbang->mdio);
}
static int mdio_get(struct mdiobb_ctrl *ctrl)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
return gpio_get_value_cansleep(bitbang->mdio) ^
bitbang->mdio_active_low;
}
static void mdio_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
if (bitbang->mdo)
gpio_set_value_cansleep(bitbang->mdo,
what ^ bitbang->mdo_active_low);
else
gpio_set_value_cansleep(bitbang->mdio,
what ^ bitbang->mdio_active_low);
}
static void mdc_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
gpio_set_value_cansleep(bitbang->mdc, what ^ bitbang->mdc_active_low);
}
static struct mii_bus *mdio_gpio_bus_init(struct device *dev,
struct mdio_gpio_platform_data *pdata,
int bus_id)
{
struct mii_bus *new_bus;
struct mdio_gpio_info *bitbang;
int i;
bitbang = devm_kzalloc(dev, sizeof(*bitbang), GFP_KERNEL);
if (!bitbang)
goto out;
bitbang->ctrl.ops = &mdio_gpio_ops;
bitbang->ctrl.reset = pdata->reset;
bitbang->mdc = pdata->mdc;
bitbang->mdc_active_low = pdata->mdc_active_low;
bitbang->mdio = pdata->mdio;
bitbang->mdio_active_low = pdata->mdio_active_low;
bitbang->mdo = pdata->mdo;
bitbang->mdo_active_low = pdata->mdo_active_low;
new_bus = alloc_mdio_bitbang(&bitbang->ctrl);
if (!new_bus)
goto out;
new_bus->name = "GPIO Bitbanged MDIO",
new_bus->phy_mask = pdata->phy_mask;
new_bus->irq = pdata->irqs;
new_bus->parent = dev;
if (new_bus->phy_mask == ~0)
goto out_free_bus;
for (i = 0; i < PHY_MAX_ADDR; i++)
if (!new_bus->irq[i])
new_bus->irq[i] = PHY_POLL;
if (bus_id != -1)
snprintf(new_bus->id, MII_BUS_ID_SIZE, "gpio-%x", bus_id);
else
strncpy(new_bus->id, "gpio", MII_BUS_ID_SIZE);
if (devm_gpio_request(dev, bitbang->mdc, "mdc"))
goto out_free_bus;
if (devm_gpio_request(dev, bitbang->mdio, "mdio"))
goto out_free_bus;
if (bitbang->mdo) {
if (devm_gpio_request(dev, bitbang->mdo, "mdo"))
goto out_free_bus;
gpio_direction_output(bitbang->mdo, 1);
gpio_direction_input(bitbang->mdio);
}
gpio_direction_output(bitbang->mdc, 0);
dev_set_drvdata(dev, new_bus);
return new_bus;
out_free_bus:
free_mdio_bitbang(new_bus);
out:
return NULL;
}
static void mdio_gpio_bus_deinit(struct device *dev)
{
struct mii_bus *bus = dev_get_drvdata(dev);
free_mdio_bitbang(bus);
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
if (bus_id < 0) {
dev_warn(&pdev->dev, "failed to get alias id\n");
bus_id = 0;
}
} else {
pdata = dev_get_platdata(&pdev->dev);
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
