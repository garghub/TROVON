static int octeon_mdiobus_read(struct mii_bus *bus, int phy_id, int regnum)
{
struct octeon_mdiobus *p = bus->priv;
union cvmx_smix_cmd smi_cmd;
union cvmx_smix_rd_dat smi_rd;
int timeout = 1000;
smi_cmd.u64 = 0;
smi_cmd.s.phy_op = 1;
smi_cmd.s.phy_adr = phy_id;
smi_cmd.s.reg_adr = regnum;
cvmx_write_csr(p->register_base + SMI_CMD, smi_cmd.u64);
do {
__delay(1000);
smi_rd.u64 = cvmx_read_csr(p->register_base + SMI_RD_DAT);
} while (smi_rd.s.pending && --timeout);
if (smi_rd.s.val)
return smi_rd.s.dat;
else
return -EIO;
}
static int octeon_mdiobus_write(struct mii_bus *bus, int phy_id,
int regnum, u16 val)
{
struct octeon_mdiobus *p = bus->priv;
union cvmx_smix_cmd smi_cmd;
union cvmx_smix_wr_dat smi_wr;
int timeout = 1000;
smi_wr.u64 = 0;
smi_wr.s.dat = val;
cvmx_write_csr(p->register_base + SMI_WR_DAT, smi_wr.u64);
smi_cmd.u64 = 0;
smi_cmd.s.phy_op = 0;
smi_cmd.s.phy_adr = phy_id;
smi_cmd.s.reg_adr = regnum;
cvmx_write_csr(p->register_base + SMI_CMD, smi_cmd.u64);
do {
__delay(1000);
smi_wr.u64 = cvmx_read_csr(p->register_base + SMI_WR_DAT);
} while (smi_wr.s.pending && --timeout);
if (timeout <= 0)
return -EIO;
return 0;
}
static int octeon_mdiobus_probe(struct platform_device *pdev)
{
struct octeon_mdiobus *bus;
struct resource *res_mem;
union cvmx_smix_en smi_en;
int err = -ENOENT;
bus = devm_kzalloc(&pdev->dev, sizeof(*bus), GFP_KERNEL);
if (!bus)
return -ENOMEM;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_mem == NULL) {
dev_err(&pdev->dev, "found no memory resource\n");
err = -ENXIO;
goto fail;
}
bus->mdio_phys = res_mem->start;
bus->regsize = resource_size(res_mem);
if (!devm_request_mem_region(&pdev->dev, bus->mdio_phys, bus->regsize,
res_mem->name)) {
dev_err(&pdev->dev, "request_mem_region failed\n");
goto fail;
}
bus->register_base =
(u64)devm_ioremap(&pdev->dev, bus->mdio_phys, bus->regsize);
bus->mii_bus = mdiobus_alloc();
if (!bus->mii_bus)
goto fail;
smi_en.u64 = 0;
smi_en.s.en = 1;
cvmx_write_csr(bus->register_base + SMI_EN, smi_en.u64);
bus->mii_bus->priv = bus;
bus->mii_bus->irq = bus->phy_irq;
bus->mii_bus->name = "mdio-octeon";
snprintf(bus->mii_bus->id, MII_BUS_ID_SIZE, "%llx", bus->register_base);
bus->mii_bus->parent = &pdev->dev;
bus->mii_bus->read = octeon_mdiobus_read;
bus->mii_bus->write = octeon_mdiobus_write;
dev_set_drvdata(&pdev->dev, bus);
err = of_mdiobus_register(bus->mii_bus, pdev->dev.of_node);
if (err)
goto fail_register;
dev_info(&pdev->dev, "Version " DRV_VERSION "\n");
return 0;
fail_register:
mdiobus_free(bus->mii_bus);
fail:
smi_en.u64 = 0;
cvmx_write_csr(bus->register_base + SMI_EN, smi_en.u64);
return err;
}
static int octeon_mdiobus_remove(struct platform_device *pdev)
{
struct octeon_mdiobus *bus;
union cvmx_smix_en smi_en;
bus = dev_get_drvdata(&pdev->dev);
mdiobus_unregister(bus->mii_bus);
mdiobus_free(bus->mii_bus);
smi_en.u64 = 0;
cvmx_write_csr(bus->register_base + SMI_EN, smi_en.u64);
return 0;
}
void octeon_mdiobus_force_mod_depencency(void)
{
}
static int __init octeon_mdiobus_mod_init(void)
{
return platform_driver_register(&octeon_mdiobus_driver);
}
static void __exit octeon_mdiobus_mod_exit(void)
{
platform_driver_unregister(&octeon_mdiobus_driver);
}
