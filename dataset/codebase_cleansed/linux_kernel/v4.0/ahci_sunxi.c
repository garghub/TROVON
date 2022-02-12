static void sunxi_clrbits(void __iomem *reg, u32 clr_val)
{
u32 reg_val;
reg_val = readl(reg);
reg_val &= ~(clr_val);
writel(reg_val, reg);
}
static void sunxi_setbits(void __iomem *reg, u32 set_val)
{
u32 reg_val;
reg_val = readl(reg);
reg_val |= set_val;
writel(reg_val, reg);
}
static void sunxi_clrsetbits(void __iomem *reg, u32 clr_val, u32 set_val)
{
u32 reg_val;
reg_val = readl(reg);
reg_val &= ~(clr_val);
reg_val |= set_val;
writel(reg_val, reg);
}
static u32 sunxi_getbits(void __iomem *reg, u8 mask, u8 shift)
{
return (readl(reg) >> shift) & mask;
}
static int ahci_sunxi_phy_init(struct device *dev, void __iomem *reg_base)
{
u32 reg_val;
int timeout;
writel(0, reg_base + AHCI_RWCR);
msleep(5);
sunxi_setbits(reg_base + AHCI_PHYCS1R, BIT(19));
sunxi_clrsetbits(reg_base + AHCI_PHYCS0R,
(0x7 << 24),
(0x5 << 24) | BIT(23) | BIT(18));
sunxi_clrsetbits(reg_base + AHCI_PHYCS1R,
(0x3 << 16) | (0x1f << 8) | (0x3 << 6),
(0x2 << 16) | (0x6 << 8) | (0x2 << 6));
sunxi_setbits(reg_base + AHCI_PHYCS1R, BIT(28) | BIT(15));
sunxi_clrbits(reg_base + AHCI_PHYCS1R, BIT(19));
sunxi_clrsetbits(reg_base + AHCI_PHYCS0R,
(0x7 << 20), (0x3 << 20));
sunxi_clrsetbits(reg_base + AHCI_PHYCS2R,
(0x1f << 5), (0x19 << 5));
msleep(5);
sunxi_setbits(reg_base + AHCI_PHYCS0R, (0x1 << 19));
timeout = 250;
do {
reg_val = sunxi_getbits(reg_base + AHCI_PHYCS0R, 0x7, 28);
if (reg_val == 0x02)
break;
if (--timeout == 0) {
dev_err(dev, "PHY power up failed.\n");
return -EIO;
}
udelay(1);
} while (1);
sunxi_setbits(reg_base + AHCI_PHYCS2R, (0x1 << 24));
timeout = 100;
do {
reg_val = sunxi_getbits(reg_base + AHCI_PHYCS2R, 0x1, 24);
if (reg_val == 0x00)
break;
if (--timeout == 0) {
dev_err(dev, "PHY calibration failed.\n");
return -EIO;
}
udelay(1);
} while (1);
msleep(15);
writel(0x7, reg_base + AHCI_RWCR);
return 0;
}
static void ahci_sunxi_start_engine(struct ata_port *ap)
{
void __iomem *port_mmio = ahci_port_base(ap);
struct ahci_host_priv *hpriv = ap->host->private_data;
sunxi_clrsetbits(hpriv->mmio + AHCI_P0DMACR, 0x0000ff00, 0x00004400);
sunxi_setbits(port_mmio + PORT_CMD, PORT_CMD_START);
}
static int ahci_sunxi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
int rc;
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
hpriv->start_engine = ahci_sunxi_start_engine;
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
rc = ahci_sunxi_phy_init(dev, hpriv->mmio);
if (rc)
goto disable_resources;
hpriv->flags = AHCI_HFLAG_32BIT_ONLY | AHCI_HFLAG_NO_MSI |
AHCI_HFLAG_YES_NCQ;
if (!enable_pmp)
hpriv->flags |= AHCI_HFLAG_NO_PMP;
rc = ahci_platform_init_host(pdev, hpriv, &ahci_sunxi_port_info,
&ahci_platform_sht);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
static int ahci_sunxi_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
rc = ahci_sunxi_phy_init(dev, hpriv->mmio);
if (rc)
goto disable_resources;
rc = ahci_platform_resume_host(dev);
if (rc)
goto disable_resources;
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
