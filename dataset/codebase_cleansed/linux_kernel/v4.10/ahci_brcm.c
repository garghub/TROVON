static inline u32 brcm_sata_readreg(void __iomem *addr)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
return __raw_readl(addr);
else
return readl_relaxed(addr);
}
static inline void brcm_sata_writereg(u32 val, void __iomem *addr)
{
if (IS_ENABLED(CONFIG_MIPS) && IS_ENABLED(CONFIG_CPU_BIG_ENDIAN))
__raw_writel(val, addr);
else
writel_relaxed(val, addr);
}
static void brcm_sata_alpm_init(struct ahci_host_priv *hpriv)
{
struct brcm_ahci_priv *priv = hpriv->plat_data;
u32 bus_ctrl, port_ctrl, host_caps;
int i;
bus_ctrl = brcm_sata_readreg(priv->top_ctrl +
SATA_TOP_CTRL_BUS_CTRL);
brcm_sata_writereg(bus_ctrl | OVERRIDE_HWINIT,
priv->top_ctrl + SATA_TOP_CTRL_BUS_CTRL);
host_caps = readl(hpriv->mmio + HOST_CAP);
writel(host_caps | HOST_CAP_ALPM, hpriv->mmio);
brcm_sata_writereg(bus_ctrl, priv->top_ctrl + SATA_TOP_CTRL_BUS_CTRL);
for (i = 0, port_ctrl = SATA_FIRST_PORT_CTRL;
i < SATA_TOP_MAX_PHYS;
i++, port_ctrl += SATA_NEXT_PORT_CTRL_OFFSET) {
if (priv->port_mask & BIT(i))
writel(0xff1003fc,
hpriv->mmio + SATA_PORT_PCTRL6(port_ctrl));
}
}
static void brcm_sata_phy_enable(struct brcm_ahci_priv *priv, int port)
{
void __iomem *phyctrl = priv->top_ctrl + SATA_TOP_CTRL_PHY_CTRL +
(port * SATA_TOP_CTRL_PHY_OFFS);
void __iomem *p;
u32 reg;
if (priv->quirks & BRCM_AHCI_QUIRK_SKIP_PHY_ENABLE)
return;
p = phyctrl + SATA_TOP_CTRL_PHY_CTRL_1;
reg = brcm_sata_readreg(p);
reg &= ~SATA_TOP_CTRL_1_PHY_DEFAULT_POWER_STATE;
brcm_sata_writereg(reg, p);
p = phyctrl + SATA_TOP_CTRL_PHY_CTRL_2;
reg = brcm_sata_readreg(p);
reg &= ~(SATA_TOP_CTRL_2_SW_RST_MDIOREG | SATA_TOP_CTRL_2_SW_RST_OOB |
SATA_TOP_CTRL_2_SW_RST_RX);
reg |= SATA_TOP_CTRL_2_SW_RST_TX;
brcm_sata_writereg(reg, p);
reg = brcm_sata_readreg(p);
reg |= SATA_TOP_CTRL_2_PHY_GLOBAL_RESET;
brcm_sata_writereg(reg, p);
reg = brcm_sata_readreg(p);
reg &= ~SATA_TOP_CTRL_2_PHY_GLOBAL_RESET;
brcm_sata_writereg(reg, p);
(void)brcm_sata_readreg(p);
}
static void brcm_sata_phy_disable(struct brcm_ahci_priv *priv, int port)
{
void __iomem *phyctrl = priv->top_ctrl + SATA_TOP_CTRL_PHY_CTRL +
(port * SATA_TOP_CTRL_PHY_OFFS);
void __iomem *p;
u32 reg;
if (priv->quirks & BRCM_AHCI_QUIRK_SKIP_PHY_ENABLE)
return;
p = phyctrl + SATA_TOP_CTRL_PHY_CTRL_2;
reg = brcm_sata_readreg(p);
reg |= (SATA_TOP_CTRL_2_SW_RST_MDIOREG | SATA_TOP_CTRL_2_SW_RST_OOB |
SATA_TOP_CTRL_2_SW_RST_RX | SATA_TOP_CTRL_2_SW_RST_TX |
SATA_TOP_CTRL_2_PHY_GLOBAL_RESET);
brcm_sata_writereg(reg, p);
p = phyctrl + SATA_TOP_CTRL_PHY_CTRL_1;
reg = brcm_sata_readreg(p);
reg |= SATA_TOP_CTRL_1_PHY_DEFAULT_POWER_STATE;
brcm_sata_writereg(reg, p);
}
static void brcm_sata_phys_enable(struct brcm_ahci_priv *priv)
{
int i;
for (i = 0; i < SATA_TOP_MAX_PHYS; i++)
if (priv->port_mask & BIT(i))
brcm_sata_phy_enable(priv, i);
}
static void brcm_sata_phys_disable(struct brcm_ahci_priv *priv)
{
int i;
for (i = 0; i < SATA_TOP_MAX_PHYS; i++)
if (priv->port_mask & BIT(i))
brcm_sata_phy_disable(priv, i);
}
static u32 brcm_ahci_get_portmask(struct platform_device *pdev,
struct brcm_ahci_priv *priv)
{
void __iomem *ahci;
struct resource *res;
u32 impl;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ahci");
ahci = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ahci))
return 0;
impl = readl(ahci + HOST_PORTS_IMPL);
if (fls(impl) > SATA_TOP_MAX_PHYS)
dev_warn(priv->dev, "warning: more ports than PHYs (%#x)\n",
impl);
else if (!impl)
dev_info(priv->dev, "no ports found\n");
devm_iounmap(&pdev->dev, ahci);
devm_release_mem_region(&pdev->dev, res->start, resource_size(res));
return impl;
}
static void brcm_sata_init(struct brcm_ahci_priv *priv)
{
void __iomem *ctrl = priv->top_ctrl + SATA_TOP_CTRL_BUS_CTRL;
if (priv->version == BRCM_SATA_NSP) {
u32 data = brcm_sata_readreg(ctrl);
data &= ~((0x03 << DMADATA_ENDIAN_SHIFT) |
(0x03 << DMADESC_ENDIAN_SHIFT));
data |= (0x02 << DMADATA_ENDIAN_SHIFT) |
(0x02 << DMADESC_ENDIAN_SHIFT);
brcm_sata_writereg(data, ctrl);
} else
brcm_sata_writereg(BUS_CTRL_ENDIAN_CONF, ctrl);
}
static int brcm_ahci_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
struct brcm_ahci_priv *priv = hpriv->plat_data;
int ret;
ret = ahci_platform_suspend(dev);
brcm_sata_phys_disable(priv);
return ret;
}
static int brcm_ahci_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
struct brcm_ahci_priv *priv = hpriv->plat_data;
brcm_sata_init(priv);
brcm_sata_phys_enable(priv);
brcm_sata_alpm_init(hpriv);
return ahci_platform_resume(dev);
}
static int brcm_ahci_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct brcm_ahci_priv *priv;
struct ahci_host_priv *hpriv;
struct resource *res;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
of_id = of_match_node(ahci_of_match, pdev->dev.of_node);
if (!of_id)
return -ENODEV;
priv->version = (enum brcm_ahci_version)of_id->data;
priv->dev = dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "top-ctrl");
priv->top_ctrl = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->top_ctrl))
return PTR_ERR(priv->top_ctrl);
if ((priv->version == BRCM_SATA_BCM7425) ||
(priv->version == BRCM_SATA_NSP)) {
priv->quirks |= BRCM_AHCI_QUIRK_NO_NCQ;
priv->quirks |= BRCM_AHCI_QUIRK_SKIP_PHY_ENABLE;
}
brcm_sata_init(priv);
priv->port_mask = brcm_ahci_get_portmask(pdev, priv);
if (!priv->port_mask)
return -ENODEV;
brcm_sata_phys_enable(priv);
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
hpriv->plat_data = priv;
hpriv->flags = AHCI_HFLAG_WAKE_BEFORE_STOP;
brcm_sata_alpm_init(hpriv);
ret = ahci_platform_enable_resources(hpriv);
if (ret)
return ret;
if (priv->quirks & BRCM_AHCI_QUIRK_NO_NCQ)
hpriv->flags |= AHCI_HFLAG_NO_NCQ;
ret = ahci_platform_init_host(pdev, hpriv, &ahci_brcm_port_info,
&ahci_platform_sht);
if (ret)
return ret;
dev_info(dev, "Broadcom AHCI SATA3 registered\n");
return 0;
}
static int brcm_ahci_remove(struct platform_device *pdev)
{
struct ata_host *host = dev_get_drvdata(&pdev->dev);
struct ahci_host_priv *hpriv = host->private_data;
struct brcm_ahci_priv *priv = hpriv->plat_data;
int ret;
ret = ata_platform_remove_one(pdev);
if (ret)
return ret;
brcm_sata_phys_disable(priv);
return 0;
}
