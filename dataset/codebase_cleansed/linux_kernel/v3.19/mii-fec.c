static int fs_enet_fec_mii_read(struct mii_bus *bus , int phy_id, int location)
{
struct fec_info* fec = bus->priv;
struct fec __iomem *fecp = fec->fecp;
int i, ret = -1;
BUG_ON((in_be32(&fecp->fec_r_cntrl) & FEC_RCNTRL_MII_MODE) == 0);
out_be32(&fecp->fec_mii_data, (phy_id << 23) | mk_mii_read(location));
for (i = 0; i < FEC_MII_LOOPS; i++)
if ((in_be32(&fecp->fec_ievent) & FEC_ENET_MII) != 0)
break;
if (i < FEC_MII_LOOPS) {
out_be32(&fecp->fec_ievent, FEC_ENET_MII);
ret = in_be32(&fecp->fec_mii_data) & 0xffff;
}
return ret;
}
static int fs_enet_fec_mii_write(struct mii_bus *bus, int phy_id, int location, u16 val)
{
struct fec_info* fec = bus->priv;
struct fec __iomem *fecp = fec->fecp;
int i;
BUG_ON((in_be32(&fecp->fec_r_cntrl) & FEC_RCNTRL_MII_MODE) == 0);
out_be32(&fecp->fec_mii_data, (phy_id << 23) | mk_mii_write(location, val));
for (i = 0; i < FEC_MII_LOOPS; i++)
if ((in_be32(&fecp->fec_ievent) & FEC_ENET_MII) != 0)
break;
if (i < FEC_MII_LOOPS)
out_be32(&fecp->fec_ievent, FEC_ENET_MII);
return 0;
}
static int fs_enet_mdio_probe(struct platform_device *ofdev)
{
const struct of_device_id *match;
struct resource res;
struct mii_bus *new_bus;
struct fec_info *fec;
int (*get_bus_freq)(struct device_node *);
int ret = -ENOMEM, clock, speed;
match = of_match_device(fs_enet_mdio_fec_match, &ofdev->dev);
if (!match)
return -EINVAL;
get_bus_freq = match->data;
new_bus = mdiobus_alloc();
if (!new_bus)
goto out;
fec = kzalloc(sizeof(struct fec_info), GFP_KERNEL);
if (!fec)
goto out_mii;
new_bus->priv = fec;
new_bus->name = "FEC MII Bus";
new_bus->read = &fs_enet_fec_mii_read;
new_bus->write = &fs_enet_fec_mii_write;
ret = of_address_to_resource(ofdev->dev.of_node, 0, &res);
if (ret)
goto out_res;
snprintf(new_bus->id, MII_BUS_ID_SIZE, "%x", res.start);
fec->fecp = ioremap(res.start, resource_size(&res));
if (!fec->fecp) {
ret = -ENOMEM;
goto out_fec;
}
if (get_bus_freq) {
clock = get_bus_freq(ofdev->dev.of_node);
if (!clock) {
dev_warn(&ofdev->dev, "could not determine IPS clock\n");
clock = 0x3F * 5000000;
}
} else
clock = ppc_proc_freq;
speed = (clock + 4999999) / 5000000;
if (speed > 0x3F) {
speed = 0x3F;
dev_err(&ofdev->dev,
"MII clock (%d Hz) exceeds max (2.5 MHz)\n",
clock / speed);
}
fec->mii_speed = speed << 1;
setbits32(&fec->fecp->fec_r_cntrl, FEC_RCNTRL_MII_MODE);
setbits32(&fec->fecp->fec_ecntrl, FEC_ECNTRL_PINMUX |
FEC_ECNTRL_ETHER_EN);
out_be32(&fec->fecp->fec_ievent, FEC_ENET_MII);
clrsetbits_be32(&fec->fecp->fec_mii_speed, 0x7E, fec->mii_speed);
new_bus->phy_mask = ~0;
new_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!new_bus->irq) {
ret = -ENOMEM;
goto out_unmap_regs;
}
new_bus->parent = &ofdev->dev;
platform_set_drvdata(ofdev, new_bus);
ret = of_mdiobus_register(new_bus, ofdev->dev.of_node);
if (ret)
goto out_free_irqs;
return 0;
out_free_irqs:
kfree(new_bus->irq);
out_unmap_regs:
iounmap(fec->fecp);
out_res:
out_fec:
kfree(fec);
out_mii:
mdiobus_free(new_bus);
out:
return ret;
}
static int fs_enet_mdio_remove(struct platform_device *ofdev)
{
struct mii_bus *bus = platform_get_drvdata(ofdev);
struct fec_info *fec = bus->priv;
mdiobus_unregister(bus);
kfree(bus->irq);
iounmap(fec->fecp);
kfree(fec);
mdiobus_free(bus);
return 0;
}
