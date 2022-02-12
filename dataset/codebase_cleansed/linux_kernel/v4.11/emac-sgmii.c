static void emac_sgmii_link_init(struct emac_adapter *adpt)
{
struct emac_sgmii *phy = &adpt->phy;
u32 val;
val = readl(phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
val &= ~(FORCE_AN_RX_CFG | FORCE_AN_TX_CFG);
val |= AN_ENABLE;
writel(val, phy->base + EMAC_SGMII_PHY_AUTONEG_CFG2);
}
static int emac_sgmii_irq_clear(struct emac_adapter *adpt, u32 irq_bits)
{
struct emac_sgmii *phy = &adpt->phy;
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
static irqreturn_t emac_sgmii_interrupt(int irq, void *data)
{
struct emac_adapter *adpt = data;
struct emac_sgmii *phy = &adpt->phy;
u32 status;
status = readl(phy->base + EMAC_SGMII_PHY_INTERRUPT_STATUS);
status &= SGMII_ISR_MASK;
if (!status)
return IRQ_HANDLED;
if (status & SGMII_PHY_INTERRUPT_ERR) {
int count;
count = atomic_inc_return(&phy->decode_error_count);
if (count == DECODE_ERROR_LIMIT) {
schedule_work(&adpt->work_thread);
atomic_set(&phy->decode_error_count, 0);
}
} else {
atomic_set(&phy->decode_error_count, 0);
}
if (emac_sgmii_irq_clear(adpt, status)) {
netdev_warn(adpt->netdev, "failed to clear SGMII interrupt\n");
schedule_work(&adpt->work_thread);
}
return IRQ_HANDLED;
}
static void emac_sgmii_reset_prepare(struct emac_adapter *adpt)
{
struct emac_sgmii *phy = &adpt->phy;
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
emac_sgmii_link_init(adpt);
ret = adpt->phy.initialize(adpt);
if (ret)
netdev_err(adpt->netdev,
"could not reinitialize internal PHY (error=%i)\n",
ret);
}
static int emac_sgmii_open(struct emac_adapter *adpt)
{
struct emac_sgmii *sgmii = &adpt->phy;
int ret;
if (sgmii->irq) {
ret = emac_sgmii_irq_clear(adpt, 0xff);
if (ret)
return ret;
writel(0, sgmii->base + EMAC_SGMII_PHY_INTERRUPT_MASK);
ret = request_irq(sgmii->irq, emac_sgmii_interrupt, 0,
"emac-sgmii", adpt);
if (ret) {
netdev_err(adpt->netdev,
"could not register handler for internal PHY\n");
return ret;
}
}
return 0;
}
static int emac_sgmii_close(struct emac_adapter *adpt)
{
struct emac_sgmii *sgmii = &adpt->phy;
writel(0, sgmii->base + EMAC_SGMII_PHY_INTERRUPT_MASK);
free_irq(sgmii->irq, adpt);
return 0;
}
static int emac_sgmii_link_up(struct emac_adapter *adpt)
{
struct emac_sgmii *sgmii = &adpt->phy;
int ret;
ret = emac_sgmii_irq_clear(adpt, 0xff);
if (ret)
return ret;
writel(SGMII_ISR_MASK, sgmii->base + EMAC_SGMII_PHY_INTERRUPT_MASK);
return 0;
}
static int emac_sgmii_link_down(struct emac_adapter *adpt)
{
struct emac_sgmii *sgmii = &adpt->phy;
writel(0, sgmii->base + EMAC_SGMII_PHY_INTERRUPT_MASK);
synchronize_irq(sgmii->irq);
return 0;
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
emac_sgmii_function *initialize = data;
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
struct emac_sgmii *phy = &adpt->phy;
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
phy->initialize = (emac_sgmii_function)match->data;
}
phy->open = emac_sgmii_open;
phy->close = emac_sgmii_close;
phy->link_up = emac_sgmii_link_up;
phy->link_down = emac_sgmii_link_down;
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
emac_sgmii_link_init(adpt);
ret = platform_get_irq(sgmii_pdev, 0);
if (ret > 0)
phy->irq = ret;
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
