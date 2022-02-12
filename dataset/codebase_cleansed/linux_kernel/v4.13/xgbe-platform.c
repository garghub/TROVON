static struct xgbe_version_data *xgbe_acpi_vdata(struct xgbe_prv_data *pdata)
{
const struct acpi_device_id *id;
id = acpi_match_device(xgbe_acpi_match, pdata->dev);
return id ? (struct xgbe_version_data *)id->driver_data : NULL;
}
static int xgbe_acpi_support(struct xgbe_prv_data *pdata)
{
struct device *dev = pdata->dev;
u32 property;
int ret;
ret = device_property_read_u32(dev, XGBE_ACPI_DMA_FREQ, &property);
if (ret) {
dev_err(dev, "unable to obtain %s property\n",
XGBE_ACPI_DMA_FREQ);
return ret;
}
pdata->sysclk_rate = property;
ret = device_property_read_u32(dev, XGBE_ACPI_PTP_FREQ, &property);
if (ret) {
dev_err(dev, "unable to obtain %s property\n",
XGBE_ACPI_PTP_FREQ);
return ret;
}
pdata->ptpclk_rate = property;
return 0;
}
static struct xgbe_version_data *xgbe_acpi_vdata(struct xgbe_prv_data *pdata)
{
return NULL;
}
static int xgbe_acpi_support(struct xgbe_prv_data *pdata)
{
return -EINVAL;
}
static struct xgbe_version_data *xgbe_of_vdata(struct xgbe_prv_data *pdata)
{
const struct of_device_id *id;
id = of_match_device(xgbe_of_match, pdata->dev);
return id ? (struct xgbe_version_data *)id->data : NULL;
}
static int xgbe_of_support(struct xgbe_prv_data *pdata)
{
struct device *dev = pdata->dev;
pdata->sysclk = devm_clk_get(dev, XGBE_DMA_CLOCK);
if (IS_ERR(pdata->sysclk)) {
dev_err(dev, "dma devm_clk_get failed\n");
return PTR_ERR(pdata->sysclk);
}
pdata->sysclk_rate = clk_get_rate(pdata->sysclk);
pdata->ptpclk = devm_clk_get(dev, XGBE_PTP_CLOCK);
if (IS_ERR(pdata->ptpclk)) {
dev_err(dev, "ptp devm_clk_get failed\n");
return PTR_ERR(pdata->ptpclk);
}
pdata->ptpclk_rate = clk_get_rate(pdata->ptpclk);
return 0;
}
static struct platform_device *xgbe_of_get_phy_pdev(struct xgbe_prv_data *pdata)
{
struct device *dev = pdata->dev;
struct device_node *phy_node;
struct platform_device *phy_pdev;
phy_node = of_parse_phandle(dev->of_node, "phy-handle", 0);
if (phy_node) {
phy_pdev = of_find_device_by_node(phy_node);
of_node_put(phy_node);
} else {
get_device(dev);
phy_pdev = pdata->platdev;
}
return phy_pdev;
}
static struct xgbe_version_data *xgbe_of_vdata(struct xgbe_prv_data *pdata)
{
return NULL;
}
static int xgbe_of_support(struct xgbe_prv_data *pdata)
{
return -EINVAL;
}
static struct platform_device *xgbe_of_get_phy_pdev(struct xgbe_prv_data *pdata)
{
return NULL;
}
static unsigned int xgbe_resource_count(struct platform_device *pdev,
unsigned int type)
{
unsigned int count;
int i;
for (i = 0, count = 0; i < pdev->num_resources; i++) {
struct resource *res = &pdev->resource[i];
if (type == resource_type(res))
count++;
}
return count;
}
static struct platform_device *xgbe_get_phy_pdev(struct xgbe_prv_data *pdata)
{
struct platform_device *phy_pdev;
if (pdata->use_acpi) {
get_device(pdata->dev);
phy_pdev = pdata->platdev;
} else {
phy_pdev = xgbe_of_get_phy_pdev(pdata);
}
return phy_pdev;
}
static struct xgbe_version_data *xgbe_get_vdata(struct xgbe_prv_data *pdata)
{
return pdata->use_acpi ? xgbe_acpi_vdata(pdata)
: xgbe_of_vdata(pdata);
}
static int xgbe_platform_probe(struct platform_device *pdev)
{
struct xgbe_prv_data *pdata;
struct device *dev = &pdev->dev;
struct platform_device *phy_pdev;
struct resource *res;
const char *phy_mode;
unsigned int phy_memnum, phy_irqnum;
unsigned int dma_irqnum, dma_irqend;
enum dev_dma_attr attr;
int ret;
pdata = xgbe_alloc_pdata(dev);
if (IS_ERR(pdata)) {
ret = PTR_ERR(pdata);
goto err_alloc;
}
pdata->platdev = pdev;
pdata->adev = ACPI_COMPANION(dev);
platform_set_drvdata(pdev, pdata);
pdata->use_acpi = dev->of_node ? 0 : 1;
pdata->vdata = xgbe_get_vdata(pdata);
phy_pdev = xgbe_get_phy_pdev(pdata);
if (!phy_pdev) {
dev_err(dev, "unable to obtain phy device\n");
ret = -EINVAL;
goto err_phydev;
}
pdata->phy_platdev = phy_pdev;
pdata->phy_dev = &phy_pdev->dev;
if (pdev == phy_pdev) {
phy_memnum = xgbe_resource_count(pdev, IORESOURCE_MEM) - 3;
phy_irqnum = xgbe_resource_count(pdev, IORESOURCE_IRQ) - 1;
dma_irqnum = 1;
dma_irqend = phy_irqnum;
} else {
phy_memnum = 0;
phy_irqnum = 0;
dma_irqnum = 1;
dma_irqend = xgbe_resource_count(pdev, IORESOURCE_IRQ);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdata->xgmac_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->xgmac_regs)) {
dev_err(dev, "xgmac ioremap failed\n");
ret = PTR_ERR(pdata->xgmac_regs);
goto err_io;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "xgmac_regs = %p\n", pdata->xgmac_regs);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pdata->xpcs_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->xpcs_regs)) {
dev_err(dev, "xpcs ioremap failed\n");
ret = PTR_ERR(pdata->xpcs_regs);
goto err_io;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "xpcs_regs = %p\n", pdata->xpcs_regs);
res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
pdata->rxtx_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->rxtx_regs)) {
dev_err(dev, "rxtx ioremap failed\n");
ret = PTR_ERR(pdata->rxtx_regs);
goto err_io;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "rxtx_regs = %p\n", pdata->rxtx_regs);
res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
pdata->sir0_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->sir0_regs)) {
dev_err(dev, "sir0 ioremap failed\n");
ret = PTR_ERR(pdata->sir0_regs);
goto err_io;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "sir0_regs = %p\n", pdata->sir0_regs);
res = platform_get_resource(phy_pdev, IORESOURCE_MEM, phy_memnum++);
pdata->sir1_regs = devm_ioremap_resource(dev, res);
if (IS_ERR(pdata->sir1_regs)) {
dev_err(dev, "sir1 ioremap failed\n");
ret = PTR_ERR(pdata->sir1_regs);
goto err_io;
}
if (netif_msg_probe(pdata))
dev_dbg(dev, "sir1_regs = %p\n", pdata->sir1_regs);
ret = device_property_read_u8_array(dev, XGBE_MAC_ADDR_PROPERTY,
pdata->mac_addr,
sizeof(pdata->mac_addr));
if (ret || !is_valid_ether_addr(pdata->mac_addr)) {
dev_err(dev, "invalid %s property\n", XGBE_MAC_ADDR_PROPERTY);
if (!ret)
ret = -EINVAL;
goto err_io;
}
ret = device_property_read_string(dev, XGBE_PHY_MODE_PROPERTY,
&phy_mode);
if (ret || strcmp(phy_mode, phy_modes(PHY_INTERFACE_MODE_XGMII))) {
dev_err(dev, "invalid %s property\n", XGBE_PHY_MODE_PROPERTY);
if (!ret)
ret = -EINVAL;
goto err_io;
}
pdata->phy_mode = PHY_INTERFACE_MODE_XGMII;
if (device_property_present(dev, XGBE_DMA_IRQS_PROPERTY)) {
pdata->per_channel_irq = 1;
pdata->channel_irq_mode = XGBE_IRQ_MODE_EDGE;
}
if (pdata->use_acpi)
ret = xgbe_acpi_support(pdata);
else
ret = xgbe_of_support(pdata);
if (ret)
goto err_io;
attr = device_get_dma_attr(dev);
if (attr == DEV_DMA_NOT_SUPPORTED) {
dev_err(dev, "DMA is not supported");
ret = -ENODEV;
goto err_io;
}
pdata->coherent = (attr == DEV_DMA_COHERENT);
if (pdata->coherent) {
pdata->arcr = XGBE_DMA_OS_ARCR;
pdata->awcr = XGBE_DMA_OS_AWCR;
} else {
pdata->arcr = XGBE_DMA_SYS_ARCR;
pdata->awcr = XGBE_DMA_SYS_AWCR;
}
pdata->tx_max_fifo_size = pdata->vdata->tx_max_fifo_size;
pdata->rx_max_fifo_size = pdata->vdata->rx_max_fifo_size;
xgbe_set_counts(pdata);
pdata->irq_count = 2;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "platform_get_irq 0 failed\n");
goto err_io;
}
pdata->dev_irq = ret;
if (pdata->per_channel_irq) {
unsigned int i, max = ARRAY_SIZE(pdata->channel_irq);
for (i = 0; (i < max) && (dma_irqnum < dma_irqend); i++) {
ret = platform_get_irq(pdata->platdev, dma_irqnum++);
if (ret < 0) {
netdev_err(pdata->netdev,
"platform_get_irq %u failed\n",
dma_irqnum - 1);
goto err_io;
}
pdata->channel_irq[i] = ret;
}
pdata->channel_irq_count = max;
pdata->irq_count += max;
}
ret = platform_get_irq(phy_pdev, phy_irqnum++);
if (ret < 0) {
dev_err(dev, "platform_get_irq phy 0 failed\n");
goto err_io;
}
pdata->an_irq = ret;
ret = xgbe_config_netdev(pdata);
if (ret)
goto err_io;
netdev_notice(pdata->netdev, "net device enabled\n");
return 0;
err_io:
platform_device_put(phy_pdev);
err_phydev:
xgbe_free_pdata(pdata);
err_alloc:
dev_notice(dev, "net device not enabled\n");
return ret;
}
static int xgbe_platform_remove(struct platform_device *pdev)
{
struct xgbe_prv_data *pdata = platform_get_drvdata(pdev);
xgbe_deconfig_netdev(pdata);
platform_device_put(pdata->phy_platdev);
xgbe_free_pdata(pdata);
return 0;
}
static int xgbe_platform_suspend(struct device *dev)
{
struct xgbe_prv_data *pdata = dev_get_drvdata(dev);
struct net_device *netdev = pdata->netdev;
int ret = 0;
DBGPR("-->xgbe_suspend\n");
if (netif_running(netdev))
ret = xgbe_powerdown(netdev, XGMAC_DRIVER_CONTEXT);
pdata->lpm_ctrl = XMDIO_READ(pdata, MDIO_MMD_PCS, MDIO_CTRL1);
pdata->lpm_ctrl |= MDIO_CTRL1_LPOWER;
XMDIO_WRITE(pdata, MDIO_MMD_PCS, MDIO_CTRL1, pdata->lpm_ctrl);
DBGPR("<--xgbe_suspend\n");
return ret;
}
static int xgbe_platform_resume(struct device *dev)
{
struct xgbe_prv_data *pdata = dev_get_drvdata(dev);
struct net_device *netdev = pdata->netdev;
int ret = 0;
DBGPR("-->xgbe_resume\n");
pdata->lpm_ctrl &= ~MDIO_CTRL1_LPOWER;
XMDIO_WRITE(pdata, MDIO_MMD_PCS, MDIO_CTRL1, pdata->lpm_ctrl);
if (netif_running(netdev)) {
ret = xgbe_powerup(netdev, XGMAC_DRIVER_CONTEXT);
schedule_work(&pdata->restart_work);
}
DBGPR("<--xgbe_resume\n");
return ret;
}
int xgbe_platform_init(void)
{
return platform_driver_register(&xgbe_driver);
}
void xgbe_platform_exit(void)
{
platform_driver_unregister(&xgbe_driver);
}
