static int temac_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
struct temac_local *lp = bus->priv;
u32 rc;
mutex_lock(&lp->indirect_mutex);
temac_iow(lp, XTE_LSW0_OFFSET, (phy_id << 5) | reg);
rc = temac_indirect_in32(lp, XTE_MIIMAI_OFFSET);
mutex_unlock(&lp->indirect_mutex);
dev_dbg(lp->dev, "temac_mdio_read(phy_id=%i, reg=%x) == %x\n",
phy_id, reg, rc);
return rc;
}
static int temac_mdio_write(struct mii_bus *bus, int phy_id, int reg, u16 val)
{
struct temac_local *lp = bus->priv;
dev_dbg(lp->dev, "temac_mdio_write(phy_id=%i, reg=%x, val=%x)\n",
phy_id, reg, val);
mutex_lock(&lp->indirect_mutex);
temac_indirect_out32(lp, XTE_MGTDR_OFFSET, val);
temac_indirect_out32(lp, XTE_MIIMAI_OFFSET, (phy_id << 5) | reg);
mutex_unlock(&lp->indirect_mutex);
return 0;
}
int temac_mdio_setup(struct temac_local *lp, struct device_node *np)
{
struct mii_bus *bus;
u32 bus_hz;
int clk_div;
int rc;
struct resource res;
clk_div = 0x3f;
if (of_property_read_u32(np, "clock-frequency", &bus_hz) == 0) {
clk_div = bus_hz / (2500 * 1000 * 2) - 1;
if (clk_div < 1)
clk_div = 1;
if (clk_div > 0x3f)
clk_div = 0x3f;
}
mutex_lock(&lp->indirect_mutex);
temac_indirect_out32(lp, XTE_MC_OFFSET, 1 << 6 | clk_div);
mutex_unlock(&lp->indirect_mutex);
bus = mdiobus_alloc();
if (!bus)
return -ENOMEM;
of_address_to_resource(np, 0, &res);
snprintf(bus->id, MII_BUS_ID_SIZE, "%.8llx",
(unsigned long long)res.start);
bus->priv = lp;
bus->name = "Xilinx TEMAC MDIO";
bus->read = temac_mdio_read;
bus->write = temac_mdio_write;
bus->parent = lp->dev;
lp->mii_bus = bus;
rc = of_mdiobus_register(bus, np);
if (rc)
goto err_register;
mutex_lock(&lp->indirect_mutex);
dev_dbg(lp->dev, "MDIO bus registered; MC:%x\n",
temac_indirect_in32(lp, XTE_MC_OFFSET));
mutex_unlock(&lp->indirect_mutex);
return 0;
err_register:
mdiobus_free(bus);
return rc;
}
void temac_mdio_teardown(struct temac_local *lp)
{
mdiobus_unregister(lp->mii_bus);
mdiobus_free(lp->mii_bus);
lp->mii_bus = NULL;
}
