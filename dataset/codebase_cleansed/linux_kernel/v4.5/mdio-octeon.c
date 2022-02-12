static void oct_mdio_writeq(u64 val, u64 addr)
{
cvmx_write_csr(addr, val);
}
static u64 oct_mdio_readq(u64 addr)
{
return cvmx_read_csr(addr);
}
static void octeon_mdiobus_set_mode(struct octeon_mdiobus *p,
enum octeon_mdiobus_mode m)
{
union cvmx_smix_clk smi_clk;
if (m == p->mode)
return;
smi_clk.u64 = oct_mdio_readq(p->register_base + SMI_CLK);
smi_clk.s.mode = (m == C45) ? 1 : 0;
smi_clk.s.preamble = 1;
oct_mdio_writeq(smi_clk.u64, p->register_base + SMI_CLK);
p->mode = m;
}
static int octeon_mdiobus_c45_addr(struct octeon_mdiobus *p,
int phy_id, int regnum)
{
union cvmx_smix_cmd smi_cmd;
union cvmx_smix_wr_dat smi_wr;
int timeout = 1000;
octeon_mdiobus_set_mode(p, C45);
smi_wr.u64 = 0;
smi_wr.s.dat = regnum & 0xffff;
oct_mdio_writeq(smi_wr.u64, p->register_base + SMI_WR_DAT);
regnum = (regnum >> 16) & 0x1f;
smi_cmd.u64 = 0;
smi_cmd.s.phy_op = 0;
smi_cmd.s.phy_adr = phy_id;
smi_cmd.s.reg_adr = regnum;
oct_mdio_writeq(smi_cmd.u64, p->register_base + SMI_CMD);
do {
__delay(1000);
smi_wr.u64 = oct_mdio_readq(p->register_base + SMI_WR_DAT);
} while (smi_wr.s.pending && --timeout);
if (timeout <= 0)
return -EIO;
return 0;
}
static int octeon_mdiobus_read(struct mii_bus *bus, int phy_id, int regnum)
{
struct octeon_mdiobus *p = bus->priv;
union cvmx_smix_cmd smi_cmd;
union cvmx_smix_rd_dat smi_rd;
unsigned int op = 1;
int timeout = 1000;
if (regnum & MII_ADDR_C45) {
int r = octeon_mdiobus_c45_addr(p, phy_id, regnum);
if (r < 0)
return r;
regnum = (regnum >> 16) & 0x1f;
op = 3;
} else {
octeon_mdiobus_set_mode(p, C22);
}
smi_cmd.u64 = 0;
smi_cmd.s.phy_op = op;
smi_cmd.s.phy_adr = phy_id;
smi_cmd.s.reg_adr = regnum;
oct_mdio_writeq(smi_cmd.u64, p->register_base + SMI_CMD);
do {
__delay(1000);
smi_rd.u64 = oct_mdio_readq(p->register_base + SMI_RD_DAT);
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
unsigned int op = 0;
int timeout = 1000;
if (regnum & MII_ADDR_C45) {
int r = octeon_mdiobus_c45_addr(p, phy_id, regnum);
if (r < 0)
return r;
regnum = (regnum >> 16) & 0x1f;
op = 1;
} else {
octeon_mdiobus_set_mode(p, C22);
}
smi_wr.u64 = 0;
smi_wr.s.dat = val;
oct_mdio_writeq(smi_wr.u64, p->register_base + SMI_WR_DAT);
smi_cmd.u64 = 0;
smi_cmd.s.phy_op = op;
smi_cmd.s.phy_adr = phy_id;
smi_cmd.s.reg_adr = regnum;
oct_mdio_writeq(smi_cmd.u64, p->register_base + SMI_CMD);
do {
__delay(1000);
smi_wr.u64 = oct_mdio_readq(p->register_base + SMI_WR_DAT);
} while (smi_wr.s.pending && --timeout);
if (timeout <= 0)
return -EIO;
return 0;
}
static int octeon_mdiobus_probe(struct platform_device *pdev)
{
struct octeon_mdiobus *bus;
struct mii_bus *mii_bus;
struct resource *res_mem;
union cvmx_smix_en smi_en;
int err = -ENOENT;
mii_bus = devm_mdiobus_alloc_size(&pdev->dev, sizeof(*bus));
if (!mii_bus)
return -ENOMEM;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res_mem == NULL) {
dev_err(&pdev->dev, "found no memory resource\n");
return -ENXIO;
}
bus = mii_bus->priv;
bus->mii_bus = mii_bus;
bus->mdio_phys = res_mem->start;
bus->regsize = resource_size(res_mem);
if (!devm_request_mem_region(&pdev->dev, bus->mdio_phys, bus->regsize,
res_mem->name)) {
dev_err(&pdev->dev, "request_mem_region failed\n");
return -ENXIO;
}
bus->register_base =
(u64)devm_ioremap(&pdev->dev, bus->mdio_phys, bus->regsize);
if (!bus->register_base) {
dev_err(&pdev->dev, "dev_ioremap failed\n");
return -ENOMEM;
}
smi_en.u64 = 0;
smi_en.s.en = 1;
oct_mdio_writeq(smi_en.u64, bus->register_base + SMI_EN);
bus->mii_bus->priv = bus;
bus->mii_bus->name = "mdio-octeon";
snprintf(bus->mii_bus->id, MII_BUS_ID_SIZE, "%llx", bus->register_base);
bus->mii_bus->parent = &pdev->dev;
bus->mii_bus->read = octeon_mdiobus_read;
bus->mii_bus->write = octeon_mdiobus_write;
platform_set_drvdata(pdev, bus);
err = of_mdiobus_register(bus->mii_bus, pdev->dev.of_node);
if (err)
goto fail_register;
dev_info(&pdev->dev, "Version " DRV_VERSION "\n");
return 0;
fail_register:
mdiobus_free(bus->mii_bus);
smi_en.u64 = 0;
oct_mdio_writeq(smi_en.u64, bus->register_base + SMI_EN);
return err;
}
static int octeon_mdiobus_remove(struct platform_device *pdev)
{
struct octeon_mdiobus *bus;
union cvmx_smix_en smi_en;
bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus->mii_bus);
mdiobus_free(bus->mii_bus);
smi_en.u64 = 0;
oct_mdio_writeq(smi_en.u64, bus->register_base + SMI_EN);
return 0;
}
void octeon_mdiobus_force_mod_depencency(void)
{
}
