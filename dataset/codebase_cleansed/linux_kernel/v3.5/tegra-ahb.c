static inline u32 gizmo_readl(struct tegra_ahb *ahb, u32 offset)
{
return readl(ahb->regs + offset);
}
static inline void gizmo_writel(struct tegra_ahb *ahb, u32 value, u32 offset)
{
writel(value, ahb->regs + offset);
}
static int tegra_ahb_match_by_smmu(struct device *dev, void *data)
{
struct tegra_ahb *ahb = dev_get_drvdata(dev);
struct device_node *dn = data;
return (ahb->dev->of_node == dn) ? 1 : 0;
}
int tegra_ahb_enable_smmu(struct device_node *dn)
{
struct device *dev;
u32 val;
struct tegra_ahb *ahb;
dev = driver_find_device(&tegra_ahb_driver.driver, NULL, dn,
tegra_ahb_match_by_smmu);
if (!dev)
return -EPROBE_DEFER;
ahb = dev_get_drvdata(dev);
val = gizmo_readl(ahb, AHB_ARBITRATION_XBAR_CTRL);
val |= AHB_ARBITRATION_XBAR_CTRL_SMMU_INIT_DONE;
gizmo_writel(ahb, val, AHB_ARBITRATION_XBAR_CTRL);
return 0;
}
static int tegra_ahb_suspend(struct device *dev)
{
int i;
struct tegra_ahb *ahb = dev_get_drvdata(dev);
for (i = 0; i < ARRAY_SIZE(tegra_ahb_gizmo); i++)
ahb->ctx[i] = gizmo_readl(ahb, tegra_ahb_gizmo[i]);
return 0;
}
static int tegra_ahb_resume(struct device *dev)
{
int i;
struct tegra_ahb *ahb = dev_get_drvdata(dev);
for (i = 0; i < ARRAY_SIZE(tegra_ahb_gizmo); i++)
gizmo_writel(ahb, ahb->ctx[i], tegra_ahb_gizmo[i]);
return 0;
}
static void tegra_ahb_gizmo_init(struct tegra_ahb *ahb)
{
u32 val;
val = gizmo_readl(ahb, AHB_GIZMO_AHB_MEM);
val |= ENB_FAST_REARBITRATE | IMMEDIATE | DONT_SPLIT_AHB_WR;
gizmo_writel(ahb, val, AHB_GIZMO_AHB_MEM);
val = gizmo_readl(ahb, AHB_GIZMO_USB);
val |= IMMEDIATE;
gizmo_writel(ahb, val, AHB_GIZMO_USB);
val = gizmo_readl(ahb, AHB_GIZMO_USB2);
val |= IMMEDIATE;
gizmo_writel(ahb, val, AHB_GIZMO_USB2);
val = gizmo_readl(ahb, AHB_GIZMO_USB3);
val |= IMMEDIATE;
gizmo_writel(ahb, val, AHB_GIZMO_USB3);
val = gizmo_readl(ahb, AHB_ARBITRATION_PRIORITY_CTRL);
val |= PRIORITY_SELECT_USB |
PRIORITY_SELECT_USB2 |
PRIORITY_SELECT_USB3 |
AHB_PRIORITY_WEIGHT(7);
gizmo_writel(ahb, val, AHB_ARBITRATION_PRIORITY_CTRL);
val = gizmo_readl(ahb, AHB_MEM_PREFETCH_CFG1);
val &= ~MST_ID(~0);
val |= PREFETCH_ENB |
AHBDMA_MST_ID |
ADDR_BNDRY(0xc) |
INACTIVITY_TIMEOUT(0x1000);
gizmo_writel(ahb, val, AHB_MEM_PREFETCH_CFG1);
val = gizmo_readl(ahb, AHB_MEM_PREFETCH_CFG2);
val &= ~MST_ID(~0);
val |= PREFETCH_ENB |
USB_MST_ID |
ADDR_BNDRY(0xc) |
INACTIVITY_TIMEOUT(0x1000);
gizmo_writel(ahb, val, AHB_MEM_PREFETCH_CFG2);
val = gizmo_readl(ahb, AHB_MEM_PREFETCH_CFG3);
val &= ~MST_ID(~0);
val |= PREFETCH_ENB |
USB3_MST_ID |
ADDR_BNDRY(0xc) |
INACTIVITY_TIMEOUT(0x1000);
gizmo_writel(ahb, val, AHB_MEM_PREFETCH_CFG3);
val = gizmo_readl(ahb, AHB_MEM_PREFETCH_CFG4);
val &= ~MST_ID(~0);
val |= PREFETCH_ENB |
USB2_MST_ID |
ADDR_BNDRY(0xc) |
INACTIVITY_TIMEOUT(0x1000);
gizmo_writel(ahb, val, AHB_MEM_PREFETCH_CFG4);
}
static int __devinit tegra_ahb_probe(struct platform_device *pdev)
{
struct resource *res;
struct tegra_ahb *ahb;
size_t bytes;
bytes = sizeof(*ahb) + sizeof(u32) * ARRAY_SIZE(tegra_ahb_gizmo);
ahb = devm_kzalloc(&pdev->dev, bytes, GFP_KERNEL);
if (!ahb)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
ahb->regs = devm_request_and_ioremap(&pdev->dev, res);
if (!ahb->regs)
return -EBUSY;
ahb->dev = &pdev->dev;
platform_set_drvdata(pdev, ahb);
tegra_ahb_gizmo_init(ahb);
return 0;
}
static int __devexit tegra_ahb_remove(struct platform_device *pdev)
{
return 0;
}
