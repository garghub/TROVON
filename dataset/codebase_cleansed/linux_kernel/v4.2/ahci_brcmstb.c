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
static void brcm_sata_phy_enable(struct brcm_ahci_priv *priv, int port)
{
void __iomem *phyctrl = priv->top_ctrl + SATA_TOP_CTRL_PHY_CTRL +
(port * SATA_TOP_CTRL_PHY_OFFS);
void __iomem *p;
u32 reg;
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
brcm_sata_writereg(BUS_CTRL_ENDIAN_CONF,
priv->top_ctrl + SATA_TOP_CTRL_BUS_CTRL);
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
return ahci_platform_resume(dev);
}
static int brcm_ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct brcm_ahci_priv *priv;
struct ahci_host_priv *hpriv;
struct resource *res;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "top-ctrl");
priv->top_ctrl = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->top_ctrl))
return PTR_ERR(priv->top_ctrl);
brcm_sata_init(priv);
priv->port_mask = brcm_ahci_get_portmask(pdev, priv);
if (!priv->port_mask)
return -ENODEV;
brcm_sata_phys_enable(priv);
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
hpriv->plat_data = priv;
ret = ahci_platform_enable_resources(hpriv);
if (ret)
return ret;
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
