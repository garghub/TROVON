int fsl_pq_local_mdio_write(struct fsl_pq_mdio __iomem *regs, int mii_id,
int regnum, u16 value)
{
out_be32(&regs->miimadd, (mii_id << 8) | regnum);
out_be32(&regs->miimcon, value);
while (in_be32(&regs->miimind) & MIIMIND_BUSY)
cpu_relax();
return 0;
}
int fsl_pq_local_mdio_read(struct fsl_pq_mdio __iomem *regs,
int mii_id, int regnum)
{
u16 value;
out_be32(&regs->miimadd, (mii_id << 8) | regnum);
out_be32(&regs->miimcom, 0);
out_be32(&regs->miimcom, MII_READ_COMMAND);
while (in_be32(&regs->miimind) & (MIIMIND_NOTVALID | MIIMIND_BUSY))
cpu_relax();
value = in_be32(&regs->miimstat);
return value;
}
static struct fsl_pq_mdio __iomem *fsl_pq_mdio_get_regs(struct mii_bus *bus)
{
struct fsl_pq_mdio_priv *priv = bus->priv;
return priv->regs;
}
int fsl_pq_mdio_write(struct mii_bus *bus, int mii_id, int regnum, u16 value)
{
struct fsl_pq_mdio __iomem *regs = fsl_pq_mdio_get_regs(bus);
return fsl_pq_local_mdio_write(regs, mii_id, regnum, value);
}
int fsl_pq_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct fsl_pq_mdio __iomem *regs = fsl_pq_mdio_get_regs(bus);
return fsl_pq_local_mdio_read(regs, mii_id, regnum);
}
static int fsl_pq_mdio_reset(struct mii_bus *bus)
{
struct fsl_pq_mdio __iomem *regs = fsl_pq_mdio_get_regs(bus);
int timeout = PHY_INIT_TIMEOUT;
mutex_lock(&bus->mdio_lock);
out_be32(&regs->miimcfg, MIIMCFG_RESET);
out_be32(&regs->miimcfg, MIIMCFG_INIT_VALUE);
while ((in_be32(&regs->miimind) & MIIMIND_BUSY) && timeout--)
cpu_relax();
mutex_unlock(&bus->mdio_lock);
if (timeout < 0) {
printk(KERN_ERR "%s: The MII Bus is stuck!\n",
bus->name);
return -EBUSY;
}
return 0;
}
void fsl_pq_mdio_bus_name(char *name, struct device_node *np)
{
const u32 *addr;
u64 taddr = OF_BAD_ADDR;
addr = of_get_address(np, 0, NULL, NULL);
if (addr)
taddr = of_translate_address(np, addr);
snprintf(name, MII_BUS_ID_SIZE, "%s@%llx", np->name,
(unsigned long long)taddr);
}
static int fsl_pq_mdio_find_free(struct mii_bus *new_bus)
{
int i;
for (i = PHY_MAX_ADDR; i > 0; i--) {
u32 phy_id;
if (get_phy_id(new_bus, i, &phy_id))
return -1;
if (phy_id == 0xffffffff)
break;
}
return i;
}
static u32 __iomem *get_gfar_tbipa(struct fsl_pq_mdio __iomem *regs, struct device_node *np)
{
struct gfar __iomem *enet_regs;
if(of_device_is_compatible(np, "fsl,gianfar-mdio") ||
of_device_is_compatible(np, "fsl,gianfar-tbi") ||
of_device_is_compatible(np, "gianfar")) {
enet_regs = (struct gfar __iomem *)regs;
return &enet_regs->tbipa;
} else if (of_device_is_compatible(np, "fsl,etsec2-mdio") ||
of_device_is_compatible(np, "fsl,etsec2-tbi")) {
return of_iomap(np, 1);
} else
return NULL;
}
static int get_ucc_id_for_range(u64 start, u64 end, u32 *ucc_id)
{
struct device_node *np = NULL;
int err = 0;
for_each_compatible_node(np, NULL, "ucc_geth") {
struct resource tempres;
err = of_address_to_resource(np, 0, &tempres);
if (err)
continue;
if ((start >= tempres.start) && (end <= tempres.end)) {
const u32 *id;
id = of_get_property(np, "cell-index", NULL);
if (!id) {
id = of_get_property(np, "device-id", NULL);
if (!id)
continue;
}
*ucc_id = *id;
return 0;
}
}
if (err)
return err;
else
return -EINVAL;
}
static int fsl_pq_mdio_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct device_node *tbi;
struct fsl_pq_mdio_priv *priv;
struct fsl_pq_mdio __iomem *regs = NULL;
void __iomem *map;
u32 __iomem *tbipa;
struct mii_bus *new_bus;
int tbiaddr = -1;
const u32 *addrp;
u64 addr = 0, size = 0;
int err;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
new_bus = mdiobus_alloc();
if (!new_bus) {
err = -ENOMEM;
goto err_free_priv;
}
new_bus->name = "Freescale PowerQUICC MII Bus",
new_bus->read = &fsl_pq_mdio_read,
new_bus->write = &fsl_pq_mdio_write,
new_bus->reset = &fsl_pq_mdio_reset,
new_bus->priv = priv;
fsl_pq_mdio_bus_name(new_bus->id, np);
addrp = of_get_address(np, 0, &size, NULL);
if (!addrp) {
err = -EINVAL;
goto err_free_bus;
}
addr = of_translate_address(np, addrp);
if (addr == OF_BAD_ADDR) {
err = -EINVAL;
goto err_free_bus;
}
map = ioremap(addr, size);
if (!map) {
err = -ENOMEM;
goto err_free_bus;
}
priv->map = map;
if (of_device_is_compatible(np, "fsl,gianfar-mdio") ||
of_device_is_compatible(np, "fsl,gianfar-tbi") ||
of_device_is_compatible(np, "fsl,ucc-mdio") ||
of_device_is_compatible(np, "ucc_geth_phy"))
map -= offsetof(struct fsl_pq_mdio, miimcfg);
regs = map;
priv->regs = regs;
new_bus->irq = kcalloc(PHY_MAX_ADDR, sizeof(int), GFP_KERNEL);
if (NULL == new_bus->irq) {
err = -ENOMEM;
goto err_unmap_regs;
}
new_bus->parent = &ofdev->dev;
dev_set_drvdata(&ofdev->dev, new_bus);
if (of_device_is_compatible(np, "fsl,gianfar-mdio") ||
of_device_is_compatible(np, "fsl,gianfar-tbi") ||
of_device_is_compatible(np, "fsl,etsec2-mdio") ||
of_device_is_compatible(np, "fsl,etsec2-tbi") ||
of_device_is_compatible(np, "gianfar")) {
#if defined(CONFIG_GIANFAR) || defined(CONFIG_GIANFAR_MODULE)
tbipa = get_gfar_tbipa(regs, np);
if (!tbipa) {
err = -EINVAL;
goto err_free_irqs;
}
#else
err = -ENODEV;
goto err_free_irqs;
#endif
} else if (of_device_is_compatible(np, "fsl,ucc-mdio") ||
of_device_is_compatible(np, "ucc_geth_phy")) {
#if defined(CONFIG_UCC_GETH) || defined(CONFIG_UCC_GETH_MODULE)
u32 id;
static u32 mii_mng_master;
tbipa = &regs->utbipar;
if ((err = get_ucc_id_for_range(addr, addr + size, &id)))
goto err_free_irqs;
if (!mii_mng_master) {
mii_mng_master = id;
ucc_set_qe_mux_mii_mng(id - 1);
}
#else
err = -ENODEV;
goto err_free_irqs;
#endif
} else {
err = -ENODEV;
goto err_free_irqs;
}
for_each_child_of_node(np, tbi) {
if (!strncmp(tbi->type, "tbi-phy", 8))
break;
}
if (tbi) {
const u32 *prop = of_get_property(tbi, "reg", NULL);
if (prop)
tbiaddr = *prop;
}
if (tbiaddr == -1) {
out_be32(tbipa, 0);
tbiaddr = fsl_pq_mdio_find_free(new_bus);
}
if (tbiaddr == 0) {
err = -EBUSY;
goto err_free_irqs;
}
out_be32(tbipa, tbiaddr);
err = of_mdiobus_register(new_bus, np);
if (err) {
printk (KERN_ERR "%s: Cannot register as MDIO bus\n",
new_bus->name);
goto err_free_irqs;
}
return 0;
err_free_irqs:
kfree(new_bus->irq);
err_unmap_regs:
iounmap(priv->map);
err_free_bus:
kfree(new_bus);
err_free_priv:
kfree(priv);
return err;
}
static int fsl_pq_mdio_remove(struct platform_device *ofdev)
{
struct device *device = &ofdev->dev;
struct mii_bus *bus = dev_get_drvdata(device);
struct fsl_pq_mdio_priv *priv = bus->priv;
mdiobus_unregister(bus);
dev_set_drvdata(device, NULL);
iounmap(priv->map);
bus->priv = NULL;
mdiobus_free(bus);
kfree(priv);
return 0;
}
int __init fsl_pq_mdio_init(void)
{
return platform_driver_register(&fsl_pq_mdio_driver);
}
void fsl_pq_mdio_exit(void)
{
platform_driver_unregister(&fsl_pq_mdio_driver);
}
