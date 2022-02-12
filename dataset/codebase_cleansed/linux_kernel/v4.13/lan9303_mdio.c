static void lan9303_mdio_real_write(struct mdio_device *mdio, int reg, u16 val)
{
mdio->bus->write(mdio->bus, PHY_ADDR(reg), PHY_REG(reg), val);
}
static int lan9303_mdio_write(void *ctx, uint32_t reg, uint32_t val)
{
struct lan9303_mdio *sw_dev = (struct lan9303_mdio *)ctx;
mutex_lock(&sw_dev->device->bus->mdio_lock);
lan9303_mdio_real_write(sw_dev->device, reg, val & 0xffff);
lan9303_mdio_real_write(sw_dev->device, reg + 2, (val >> 16) & 0xffff);
mutex_unlock(&sw_dev->device->bus->mdio_lock);
return 0;
}
static u16 lan9303_mdio_real_read(struct mdio_device *mdio, int reg)
{
return mdio->bus->read(mdio->bus, PHY_ADDR(reg), PHY_REG(reg));
}
static int lan9303_mdio_read(void *ctx, uint32_t reg, uint32_t *val)
{
struct lan9303_mdio *sw_dev = (struct lan9303_mdio *)ctx;
mutex_lock(&sw_dev->device->bus->mdio_lock);
*val = lan9303_mdio_real_read(sw_dev->device, reg);
*val |= (lan9303_mdio_real_read(sw_dev->device, reg + 2) << 16);
mutex_unlock(&sw_dev->device->bus->mdio_lock);
return 0;
}
static int lan9303_mdio_probe(struct mdio_device *mdiodev)
{
struct lan9303_mdio *sw_dev;
int ret;
sw_dev = devm_kzalloc(&mdiodev->dev, sizeof(struct lan9303_mdio),
GFP_KERNEL);
if (!sw_dev)
return -ENOMEM;
sw_dev->chip.regmap = devm_regmap_init(&mdiodev->dev, NULL, sw_dev,
&lan9303_mdio_regmap_config);
if (IS_ERR(sw_dev->chip.regmap)) {
ret = PTR_ERR(sw_dev->chip.regmap);
dev_err(&mdiodev->dev, "regmap init failed: %d\n", ret);
return ret;
}
sw_dev->device = mdiodev;
dev_set_drvdata(&mdiodev->dev, sw_dev);
sw_dev->chip.dev = &mdiodev->dev;
ret = lan9303_probe(&sw_dev->chip, mdiodev->dev.of_node);
if (ret != 0)
return ret;
dev_info(&mdiodev->dev, "LAN9303 MDIO driver loaded successfully\n");
return 0;
}
static void lan9303_mdio_remove(struct mdio_device *mdiodev)
{
struct lan9303_mdio *sw_dev = dev_get_drvdata(&mdiodev->dev);
if (!sw_dev)
return;
lan9303_remove(&sw_dev->chip);
}
