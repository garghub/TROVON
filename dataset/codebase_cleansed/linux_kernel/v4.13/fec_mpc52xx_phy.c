static int mpc52xx_fec_mdio_transfer(struct mii_bus *bus, int phy_id,
int reg, u32 value)
{
struct mpc52xx_fec_mdio_priv *priv = bus->priv;
struct mpc52xx_fec __iomem *fec = priv->regs;
int tries = 3;
value |= (phy_id << FEC_MII_DATA_PA_SHIFT) & FEC_MII_DATA_PA_MSK;
value |= (reg << FEC_MII_DATA_RA_SHIFT) & FEC_MII_DATA_RA_MSK;
out_be32(&fec->ievent, FEC_IEVENT_MII);
out_be32(&fec->mii_data, value);
while (!(in_be32(&fec->ievent) & FEC_IEVENT_MII) && --tries)
msleep(1);
if (!tries)
return -ETIMEDOUT;
return value & FEC_MII_DATA_OP_RD ?
in_be32(&fec->mii_data) & FEC_MII_DATA_DATAMSK : 0;
}
static int mpc52xx_fec_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
return mpc52xx_fec_mdio_transfer(bus, phy_id, reg, FEC_MII_READ_FRAME);
}
static int mpc52xx_fec_mdio_write(struct mii_bus *bus, int phy_id, int reg,
u16 data)
{
return mpc52xx_fec_mdio_transfer(bus, phy_id, reg,
data | FEC_MII_WRITE_FRAME);
}
static int mpc52xx_fec_mdio_probe(struct platform_device *of)
{
struct device *dev = &of->dev;
struct device_node *np = of->dev.of_node;
struct mii_bus *bus;
struct mpc52xx_fec_mdio_priv *priv;
struct resource res;
int err;
bus = mdiobus_alloc();
if (bus == NULL)
return -ENOMEM;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (priv == NULL) {
err = -ENOMEM;
goto out_free;
}
bus->name = "mpc52xx MII bus";
bus->read = mpc52xx_fec_mdio_read;
bus->write = mpc52xx_fec_mdio_write;
err = of_address_to_resource(np, 0, &res);
if (err)
goto out_free;
priv->regs = ioremap(res.start, resource_size(&res));
if (priv->regs == NULL) {
err = -ENOMEM;
goto out_free;
}
snprintf(bus->id, MII_BUS_ID_SIZE, "%x", res.start);
bus->priv = priv;
bus->parent = dev;
dev_set_drvdata(dev, bus);
out_be32(&priv->regs->mii_speed,
((mpc5xxx_get_bus_frequency(of->dev.of_node) >> 20) / 5) << 1);
err = of_mdiobus_register(bus, np);
if (err)
goto out_unmap;
return 0;
out_unmap:
iounmap(priv->regs);
out_free:
kfree(priv);
mdiobus_free(bus);
return err;
}
static int mpc52xx_fec_mdio_remove(struct platform_device *of)
{
struct mii_bus *bus = platform_get_drvdata(of);
struct mpc52xx_fec_mdio_priv *priv = bus->priv;
mdiobus_unregister(bus);
iounmap(priv->regs);
kfree(priv);
mdiobus_free(bus);
return 0;
}
