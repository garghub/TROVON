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
gpiod_set_value(bitbang->mdo, 1);
return;
}
if (dir)
gpiod_direction_output(bitbang->mdio, 1);
else
gpiod_direction_input(bitbang->mdio);
}
static int mdio_get(struct mdiobb_ctrl *ctrl)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
return gpiod_get_value(bitbang->mdio);
}
static void mdio_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
if (bitbang->mdo)
gpiod_set_value(bitbang->mdo, what);
else
gpiod_set_value(bitbang->mdio, what);
}
static void mdc_set(struct mdiobb_ctrl *ctrl, int what)
{
struct mdio_gpio_info *bitbang =
container_of(ctrl, struct mdio_gpio_info, ctrl);
gpiod_set_value(bitbang->mdc, what);
}
static struct mii_bus *mdio_gpio_bus_init(struct device *dev,
struct mdio_gpio_platform_data *pdata,
int bus_id)
{
struct mii_bus *new_bus;
struct mdio_gpio_info *bitbang;
int i;
int mdc, mdio, mdo;
unsigned long mdc_flags = GPIOF_OUT_INIT_LOW;
unsigned long mdio_flags = GPIOF_DIR_IN;
unsigned long mdo_flags = GPIOF_OUT_INIT_HIGH;
bitbang = devm_kzalloc(dev, sizeof(*bitbang), GFP_KERNEL);
if (!bitbang)
goto out;
bitbang->ctrl.ops = &mdio_gpio_ops;
bitbang->ctrl.reset = pdata->reset;
mdc = pdata->mdc;
bitbang->mdc = gpio_to_desc(mdc);
if (pdata->mdc_active_low)
mdc_flags = GPIOF_OUT_INIT_HIGH | GPIOF_ACTIVE_LOW;
mdio = pdata->mdio;
bitbang->mdio = gpio_to_desc(mdio);
if (pdata->mdio_active_low)
mdio_flags |= GPIOF_ACTIVE_LOW;
mdo = pdata->mdo;
if (mdo) {
bitbang->mdo = gpio_to_desc(mdo);
if (pdata->mdo_active_low)
mdo_flags = GPIOF_OUT_INIT_LOW | GPIOF_ACTIVE_LOW;
}
new_bus = alloc_mdio_bitbang(&bitbang->ctrl);
if (!new_bus)
goto out;
new_bus->name = "GPIO Bitbanged MDIO",
new_bus->phy_mask = pdata->phy_mask;
new_bus->phy_ignore_ta_mask = pdata->phy_ignore_ta_mask;
memcpy(new_bus->irq, pdata->irqs, sizeof(new_bus->irq));
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
if (devm_gpio_request_one(dev, mdc, mdc_flags, "mdc"))
goto out_free_bus;
if (devm_gpio_request_one(dev, mdio, mdio_flags, "mdio"))
goto out_free_bus;
if (mdo && devm_gpio_request_one(dev, mdo, mdo_flags, "mdo"))
goto out_free_bus;
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
