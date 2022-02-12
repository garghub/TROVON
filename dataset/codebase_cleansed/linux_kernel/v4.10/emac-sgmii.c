static int emac_sgmii_link_init(struct emac_adapter *adpt)
{
struct phy_device *phydev = adpt->phydev;
struct emac_phy *phy = &adpt->phy;
u32 val;
val = readl(phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
if (phydev->autoneg == AUTONEG_ENABLE) {
val &= ~(FORCE_AN_RX_CFG | FORCE_AN_TX_CFG);
val |= AN_ENABLE;
writel(val, phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
} else {
u32 speed_cfg;
switch (phydev->speed) {
case SPEED_10:
speed_cfg = SPDMODE_10;
break;
case SPEED_100:
speed_cfg = SPDMODE_100;
break;
case SPEED_1000:
speed_cfg = SPDMODE_1000;
break;
default:
return -EINVAL;
}
if (phydev->duplex == DUPLEX_FULL)
speed_cfg |= DUPLEX_MODE;
val &= ~AN_ENABLE;
writel(speed_cfg, phy->base + EMAC_SGMII_PHY_SPEED_CFG1);
writel(val, phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
}
return 0;
}
static int emac_sgmii_irq_clear(struct emac_adapter *adpt, u32 irq_bits)
{
struct emac_phy *phy = &adpt->phy;
u32 status;
writel_relaxed(irq_bits, phy->base + EMAC_SGMII_PHY_INTERRUPT_CLEAR);
writel_relaxed(IRQ_GLOBAL_CLEAR, phy->base + EMAC_SGMII_PHY_IRQ_CMD);
wmb();
if (readl_poll_timeout_atomic(phy->base +
EMAC_SGMII_PHY_INTERRUPT_STATUS,
status, !(status & irq_bits), 1,
SGMII_PHY_IRQ_CLR_WAIT_TIME)) {
netdev_err(adpt->netdev,
"error: failed clear SGMII irq: status:0x%x bits:0x%x\n",
status, irq_bits);
return -EIO;
}
writel_relaxed(0, phy->base + EMAC_SGMII_PHY_IRQ_CMD);
writel_relaxed(0, phy->base + EMAC_SGMII_PHY_INTERRUPT_CLEAR);
wmb();
return 0;
}
static void emac_sgmii_reset_prepare(struct emac_adapter *adpt)
{
struct emac_phy *phy = &adpt->phy;
u32 val;
val = readl(phy->base + EMAC_EMAC_WRAPPER_CSR2);
writel(((val & ~PHY_RESET) | PHY_RESET), phy->base +
EMAC_EMAC_WRAPPER_CSR2);
msleep(50);
val = readl(phy->base + EMAC_EMAC_WRAPPER_CSR2);
writel((val & ~PHY_RESET), phy->base + EMAC_EMAC_WRAPPER_CSR2);
msleep(50);
}
void emac_sgmii_reset(struct emac_adapter *adpt)
{
int ret;
emac_sgmii_reset_prepare(adpt);
ret = emac_sgmii_link_init(adpt);
if (ret) {
netdev_err(adpt->netdev, "unsupported link speed\n");
return;
}
ret = adpt->phy.initialize(adpt);
if (ret)
netdev_err(adpt->netdev,
"could not reinitialize internal PHY (error=%i)\n",
ret);
}
static int emac_sgmii_acpi_match(struct device *dev, void *data)
{
#ifdef CONFIG_ACPI
static const struct acpi_device_id match_table[] = {
{
.id = "QCOM8071",
},
{}
};
const struct acpi_device_id *id = acpi_match_device(match_table, dev);
emac_sgmii_initialize *initialize = data;
if (id) {
acpi_handle handle = ACPI_HANDLE(dev);
unsigned long long hrv;
acpi_status status;
status = acpi_evaluate_integer(handle, "_HRV", NULL, &hrv);
if (status) {
if (status == AE_NOT_FOUND)
hrv = 1;
else
return 0;
}
switch (hrv) {
case 1:
*initialize = emac_sgmii_init_qdf2432;
return 1;
case 2:
*initialize = emac_sgmii_init_qdf2400;
return 1;
}
}
#endif
return 0;
}
int emac_sgmii_config(struct platform_device *pdev, struct emac_adapter *adpt)
{
struct platform_device *sgmii_pdev = NULL;
struct emac_phy *phy = &adpt->phy;
struct resource *res;
int ret;
if (has_acpi_companion(&pdev->dev)) {
struct device *dev;
dev = device_find_child(&pdev->dev, &phy->initialize,
emac_sgmii_acpi_match);
if (!dev) {
dev_err(&pdev->dev, "cannot find internal phy node\n");
return -ENODEV;
}
sgmii_pdev = to_platform_device(dev);
} else {
const struct of_device_id *match;
struct device_node *np;
np = of_parse_phandle(pdev->dev.of_node, "internal-phy", 0);
if (!np) {
dev_err(&pdev->dev, "missing internal-phy property\n");
return -ENODEV;
}
sgmii_pdev = of_find_device_by_node(np);
if (!sgmii_pdev) {
dev_err(&pdev->dev, "invalid internal-phy property\n");
return -ENODEV;
}
match = of_match_device(emac_sgmii_dt_match, &sgmii_pdev->dev);
if (!match) {
dev_err(&pdev->dev, "unrecognized internal phy node\n");
ret = -ENODEV;
goto error_put_device;
}
phy->initialize = (emac_sgmii_initialize)match->data;
}
res = platform_get_resource(sgmii_pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -EINVAL;
goto error_put_device;
}
phy->base = ioremap(res->start, resource_size(res));
if (!phy->base) {
ret = -ENOMEM;
goto error_put_device;
}
res = platform_get_resource(sgmii_pdev, IORESOURCE_MEM, 1);
if (res) {
phy->digital = ioremap(res->start, resource_size(res));
if (!phy->digital) {
ret = -ENOMEM;
goto error_unmap_base;
}
}
ret = phy->initialize(adpt);
if (ret)
goto error;
emac_sgmii_irq_clear(adpt, SGMII_PHY_INTERRUPT_ERR);
put_device(&sgmii_pdev->dev);
return 0;
error:
if (phy->digital)
iounmap(phy->digital);
error_unmap_base:
iounmap(phy->base);
error_put_device:
put_device(&sgmii_pdev->dev);
return ret;
}
