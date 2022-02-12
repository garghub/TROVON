static int fsl_pq_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct fsl_pq_mdio_priv *priv = bus->priv;
struct fsl_pq_mii __iomem *regs = priv->regs;
u32 status;
out_be32(&regs->miimadd, (mii_id << 8) | regnum);
out_be32(&regs->miimcon, value);
status = spin_event_timeout(!(in_be32(&regs->miimind) & MIIMIND_BUSY),
MII_TIMEOUT, 0);
return status ? 0 : -ETIMEDOUT;
}
static int fsl_pq_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct fsl_pq_mdio_priv *priv = bus->priv;
struct fsl_pq_mii __iomem *regs = priv->regs;
u32 status;
u16 value;
out_be32(&regs->miimadd, (mii_id << 8) | regnum);
out_be32(&regs->miimcom, 0);
out_be32(&regs->miimcom, MII_READ_COMMAND);
status = spin_event_timeout(!(in_be32(&regs->miimind) &
(MIIMIND_NOTVALID | MIIMIND_BUSY)),
MII_TIMEOUT, 0);
if (!status)
return -ETIMEDOUT;
value = in_be32(&regs->miimstat);
dev_dbg(&bus->dev, "read %04x from address %x/%x\n", value, mii_id, regnum);
return value;
}
static int fsl_pq_mdio_reset(struct mii_bus *bus)
{
struct fsl_pq_mdio_priv *priv = bus->priv;
struct fsl_pq_mii __iomem *regs = priv->regs;
u32 status;
mutex_lock(&bus->mdio_lock);
out_be32(&regs->miimcfg, MIIMCFG_RESET);
out_be32(&regs->miimcfg, MIIMCFG_INIT_VALUE);
status = spin_event_timeout(!(in_be32(&regs->miimind) & MIIMIND_BUSY),
MII_TIMEOUT, 0);
mutex_unlock(&bus->mdio_lock);
if (!status) {
dev_err(&bus->dev, "timeout waiting for MII bus\n");
return -EBUSY;
}
return 0;
}
static uint32_t __iomem *get_gfar_tbipa(void __iomem *p)
{
struct gfar __iomem *enet_regs = p;
return &enet_regs->tbipa;
}
static uint32_t __iomem *get_etsec_tbipa(void __iomem *p)
{
return p;
}
static uint32_t __iomem *get_ucc_tbipa(void __iomem *p)
{
struct fsl_pq_mdio __iomem *mdio = p;
return &mdio->utbipar;
}
static void ucc_configure(phys_addr_t start, phys_addr_t end)
{
static bool found_mii_master;
struct device_node *np = NULL;
if (found_mii_master)
return;
for_each_compatible_node(np, NULL, "ucc_geth") {
struct resource res;
const uint32_t *iprop;
uint32_t id;
int ret;
ret = of_address_to_resource(np, 0, &res);
if (ret < 0) {
pr_debug("fsl-pq-mdio: no address range in node %s\n",
np->full_name);
continue;
}
if ((start < res.start) || (end > res.end))
continue;
iprop = of_get_property(np, "cell-index", NULL);
if (!iprop) {
iprop = of_get_property(np, "device-id", NULL);
if (!iprop) {
pr_debug("fsl-pq-mdio: no UCC ID in node %s\n",
np->full_name);
continue;
}
}
id = be32_to_cpup(iprop);
if (ucc_set_qe_mux_mii_mng(id - 1) < 0) {
pr_debug("fsl-pq-mdio: invalid UCC ID in node %s\n",
np->full_name);
continue;
}
pr_debug("fsl-pq-mdio: setting node UCC%u to MII master\n", id);
found_mii_master = true;
}
}
static int fsl_pq_mdio_probe(struct platform_device *pdev)
{
const struct of_device_id *id =
of_match_device(fsl_pq_mdio_match, &pdev->dev);
const struct fsl_pq_mdio_data *data = id->data;
struct device_node *np = pdev->dev.of_node;
struct resource res;
struct device_node *tbi;
struct fsl_pq_mdio_priv *priv;
struct mii_bus *new_bus;
int err;
dev_dbg(&pdev->dev, "found %s compatible node\n", id->compatible);
new_bus = mdiobus_alloc_size(sizeof(*priv));
if (!new_bus)
return -ENOMEM;
priv = new_bus->priv;
new_bus->name = "Freescale PowerQUICC MII Bus",
new_bus->read = &fsl_pq_mdio_read;
new_bus->write = &fsl_pq_mdio_write;
new_bus->reset = &fsl_pq_mdio_reset;
new_bus->irq = priv->irqs;
err = of_address_to_resource(np, 0, &res);
if (err < 0) {
dev_err(&pdev->dev, "could not obtain address information\n");
goto error;
}
snprintf(new_bus->id, MII_BUS_ID_SIZE, "%s@%llx", np->name,
(unsigned long long)res.start);
priv->map = of_iomap(np, 0);
if (!priv->map) {
err = -ENOMEM;
goto error;
}
if (data->mii_offset > resource_size(&res)) {
dev_err(&pdev->dev, "invalid register map\n");
err = -EINVAL;
goto error;
}
priv->regs = priv->map + data->mii_offset;
new_bus->parent = &pdev->dev;
platform_set_drvdata(pdev, new_bus);
if (data->get_tbipa) {
for_each_child_of_node(np, tbi) {
if (strcmp(tbi->type, "tbi-phy") == 0) {
dev_dbg(&pdev->dev, "found TBI PHY node %s\n",
strrchr(tbi->full_name, '/') + 1);
break;
}
}
if (tbi) {
const u32 *prop = of_get_property(tbi, "reg", NULL);
uint32_t __iomem *tbipa;
if (!prop) {
dev_err(&pdev->dev,
"missing 'reg' property in node %s\n",
tbi->full_name);
err = -EBUSY;
goto error;
}
tbipa = data->get_tbipa(priv->map);
out_be32(tbipa, be32_to_cpup(prop));
}
}
if (data->ucc_configure)
data->ucc_configure(res.start, res.end);
err = of_mdiobus_register(new_bus, np);
if (err) {
dev_err(&pdev->dev, "cannot register %s as MDIO bus\n",
new_bus->name);
goto error;
}
return 0;
error:
if (priv->map)
iounmap(priv->map);
kfree(new_bus);
return err;
}
static int fsl_pq_mdio_remove(struct platform_device *pdev)
{
struct device *device = &pdev->dev;
struct mii_bus *bus = dev_get_drvdata(device);
struct fsl_pq_mdio_priv *priv = bus->priv;
mdiobus_unregister(bus);
iounmap(priv->map);
mdiobus_free(bus);
return 0;
}
