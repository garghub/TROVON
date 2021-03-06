static inline void usbhs_write(void __iomem *base, u32 reg, u32 val)
{
__raw_writel(val, base + reg);
}
static inline u32 usbhs_read(void __iomem *base, u32 reg)
{
return __raw_readl(base + reg);
}
static inline void usbhs_writeb(void __iomem *base, u8 reg, u8 val)
{
__raw_writeb(val, base + reg);
}
static inline u8 usbhs_readb(void __iomem *base, u8 reg)
{
return __raw_readb(base + reg);
}
static struct platform_device *omap_usbhs_alloc_child(const char *name,
struct resource *res, int num_resources, void *pdata,
size_t pdata_size, struct device *dev)
{
struct platform_device *child;
int ret;
child = platform_device_alloc(name, 0);
if (!child) {
dev_err(dev, "platform_device_alloc %s failed\n", name);
goto err_end;
}
ret = platform_device_add_resources(child, res, num_resources);
if (ret) {
dev_err(dev, "platform_device_add_resources failed\n");
goto err_alloc;
}
ret = platform_device_add_data(child, pdata, pdata_size);
if (ret) {
dev_err(dev, "platform_device_add_data failed\n");
goto err_alloc;
}
child->dev.dma_mask = &usbhs_dmamask;
dma_set_coherent_mask(&child->dev, DMA_BIT_MASK(32));
child->dev.parent = dev;
ret = platform_device_add(child);
if (ret) {
dev_err(dev, "platform_device_add failed\n");
goto err_alloc;
}
return child;
err_alloc:
platform_device_put(child);
err_end:
return NULL;
}
static int omap_usbhs_alloc_children(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usbhs_hcd_omap *omap;
struct ehci_hcd_omap_platform_data *ehci_data;
struct ohci_hcd_omap_platform_data *ohci_data;
struct platform_device *ehci;
struct platform_device *ohci;
struct resource *res;
struct resource resources[2];
int ret;
omap = platform_get_drvdata(pdev);
ehci_data = omap->platdata.ehci_data;
ohci_data = omap->platdata.ohci_data;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ehci");
if (!res) {
dev_err(dev, "EHCI get resource IORESOURCE_MEM failed\n");
ret = -ENODEV;
goto err_end;
}
resources[0] = *res;
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ, "ehci-irq");
if (!res) {
dev_err(dev, " EHCI get resource IORESOURCE_IRQ failed\n");
ret = -ENODEV;
goto err_end;
}
resources[1] = *res;
ehci = omap_usbhs_alloc_child(OMAP_EHCI_DEVICE, resources, 2, ehci_data,
sizeof(*ehci_data), dev);
if (!ehci) {
dev_err(dev, "omap_usbhs_alloc_child failed\n");
ret = -ENOMEM;
goto err_end;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ohci");
if (!res) {
dev_err(dev, "OHCI get resource IORESOURCE_MEM failed\n");
ret = -ENODEV;
goto err_ehci;
}
resources[0] = *res;
res = platform_get_resource_byname(pdev, IORESOURCE_IRQ, "ohci-irq");
if (!res) {
dev_err(dev, "OHCI get resource IORESOURCE_IRQ failed\n");
ret = -ENODEV;
goto err_ehci;
}
resources[1] = *res;
ohci = omap_usbhs_alloc_child(OMAP_OHCI_DEVICE, resources, 2, ohci_data,
sizeof(*ohci_data), dev);
if (!ohci) {
dev_err(dev, "omap_usbhs_alloc_child failed\n");
ret = -ENOMEM;
goto err_ehci;
}
return 0;
err_ehci:
platform_device_unregister(ehci);
err_end:
return ret;
}
static bool is_ohci_port(enum usbhs_omap_port_mode pmode)
{
switch (pmode) {
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DPDM:
case OMAP_OHCI_PORT_MODE_PHY_3PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_PHY_4PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_3PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_4PIN_DPDM:
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DATSE0:
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DPDM:
return true;
default:
return false;
}
}
static int usbhs_runtime_resume(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
unsigned long flags;
dev_dbg(dev, "usbhs_runtime_resume\n");
if (!pdata) {
dev_dbg(dev, "missing platform_data\n");
return -ENODEV;
}
omap_tll_enable();
spin_lock_irqsave(&omap->lock, flags);
if (omap->ehci_logic_fck && !IS_ERR(omap->ehci_logic_fck))
clk_enable(omap->ehci_logic_fck);
if (is_ehci_tll_mode(pdata->port_mode[0]))
clk_enable(omap->usbhost_p1_fck);
if (is_ehci_tll_mode(pdata->port_mode[1]))
clk_enable(omap->usbhost_p2_fck);
clk_enable(omap->utmi_p1_fck);
clk_enable(omap->utmi_p2_fck);
spin_unlock_irqrestore(&omap->lock, flags);
return 0;
}
static int usbhs_runtime_suspend(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
unsigned long flags;
dev_dbg(dev, "usbhs_runtime_suspend\n");
if (!pdata) {
dev_dbg(dev, "missing platform_data\n");
return -ENODEV;
}
spin_lock_irqsave(&omap->lock, flags);
if (is_ehci_tll_mode(pdata->port_mode[0]))
clk_disable(omap->usbhost_p1_fck);
if (is_ehci_tll_mode(pdata->port_mode[1]))
clk_disable(omap->usbhost_p2_fck);
clk_disable(omap->utmi_p2_fck);
clk_disable(omap->utmi_p1_fck);
if (omap->ehci_logic_fck && !IS_ERR(omap->ehci_logic_fck))
clk_disable(omap->ehci_logic_fck);
spin_unlock_irqrestore(&omap->lock, flags);
omap_tll_disable();
return 0;
}
static void omap_usbhs_init(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
unsigned long flags;
unsigned reg;
dev_dbg(dev, "starting TI HSUSB Controller\n");
if (pdata->ehci_data->phy_reset) {
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_request_one(pdata->ehci_data->reset_gpio_port[0],
GPIOF_OUT_INIT_LOW, "USB1 PHY reset");
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_request_one(pdata->ehci_data->reset_gpio_port[1],
GPIOF_OUT_INIT_LOW, "USB2 PHY reset");
udelay(10);
}
pm_runtime_get_sync(dev);
spin_lock_irqsave(&omap->lock, flags);
omap->usbhs_rev = usbhs_read(omap->uhh_base, OMAP_UHH_REVISION);
dev_dbg(dev, "OMAP UHH_REVISION 0x%x\n", omap->usbhs_rev);
reg = usbhs_read(omap->uhh_base, OMAP_UHH_HOSTCONFIG);
reg |= (OMAP_UHH_HOSTCONFIG_INCR4_BURST_EN
| OMAP_UHH_HOSTCONFIG_INCR8_BURST_EN
| OMAP_UHH_HOSTCONFIG_INCR16_BURST_EN);
reg |= OMAP4_UHH_HOSTCONFIG_APP_START_CLK;
reg &= ~OMAP_UHH_HOSTCONFIG_INCRX_ALIGN_EN;
if (is_omap_usbhs_rev1(omap)) {
if (pdata->port_mode[0] == OMAP_USBHS_PORT_MODE_UNUSED)
reg &= ~OMAP_UHH_HOSTCONFIG_P1_CONNECT_STATUS;
if (pdata->port_mode[1] == OMAP_USBHS_PORT_MODE_UNUSED)
reg &= ~OMAP_UHH_HOSTCONFIG_P2_CONNECT_STATUS;
if (pdata->port_mode[2] == OMAP_USBHS_PORT_MODE_UNUSED)
reg &= ~OMAP_UHH_HOSTCONFIG_P3_CONNECT_STATUS;
if (pdata->single_ulpi_bypass) {
dev_dbg(dev, "OMAP3 ES version <= ES2.1\n");
if (is_ehci_phy_mode(pdata->port_mode[0]) ||
is_ehci_phy_mode(pdata->port_mode[1]) ||
is_ehci_phy_mode(pdata->port_mode[2]))
reg &= ~OMAP_UHH_HOSTCONFIG_ULPI_BYPASS;
else
reg |= OMAP_UHH_HOSTCONFIG_ULPI_BYPASS;
} else {
dev_dbg(dev, "OMAP3 ES version > ES2.1\n");
if (is_ehci_phy_mode(pdata->port_mode[0]))
reg &= ~OMAP_UHH_HOSTCONFIG_ULPI_P1_BYPASS;
else
reg |= OMAP_UHH_HOSTCONFIG_ULPI_P1_BYPASS;
if (is_ehci_phy_mode(pdata->port_mode[1]))
reg &= ~OMAP_UHH_HOSTCONFIG_ULPI_P2_BYPASS;
else
reg |= OMAP_UHH_HOSTCONFIG_ULPI_P2_BYPASS;
if (is_ehci_phy_mode(pdata->port_mode[2]))
reg &= ~OMAP_UHH_HOSTCONFIG_ULPI_P3_BYPASS;
else
reg |= OMAP_UHH_HOSTCONFIG_ULPI_P3_BYPASS;
}
} else if (is_omap_usbhs_rev2(omap)) {
reg &= ~OMAP4_P1_MODE_CLEAR;
reg &= ~OMAP4_P2_MODE_CLEAR;
if (is_ehci_tll_mode(pdata->port_mode[0]) ||
(is_ohci_port(pdata->port_mode[0])))
reg |= OMAP4_P1_MODE_TLL;
else if (is_ehci_hsic_mode(pdata->port_mode[0]))
reg |= OMAP4_P1_MODE_HSIC;
if (is_ehci_tll_mode(pdata->port_mode[1]) ||
(is_ohci_port(pdata->port_mode[1])))
reg |= OMAP4_P2_MODE_TLL;
else if (is_ehci_hsic_mode(pdata->port_mode[1]))
reg |= OMAP4_P2_MODE_HSIC;
}
usbhs_write(omap->uhh_base, OMAP_UHH_HOSTCONFIG, reg);
dev_dbg(dev, "UHH setup done, uhh_hostconfig=%x\n", reg);
spin_unlock_irqrestore(&omap->lock, flags);
pm_runtime_put_sync(dev);
if (pdata->ehci_data->phy_reset) {
udelay(10);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_set_value_cansleep
(pdata->ehci_data->reset_gpio_port[0], 1);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_set_value_cansleep
(pdata->ehci_data->reset_gpio_port[1], 1);
}
}
static void omap_usbhs_deinit(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
if (pdata->ehci_data->phy_reset) {
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_free(pdata->ehci_data->reset_gpio_port[0]);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_free(pdata->ehci_data->reset_gpio_port[1]);
}
}
static int usbhs_omap_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct usbhs_omap_platform_data *pdata = dev->platform_data;
struct usbhs_hcd_omap *omap;
struct resource *res;
int ret = 0;
int i;
if (!pdata) {
dev_err(dev, "Missing platform data\n");
ret = -ENOMEM;
goto end_probe;
}
omap = kzalloc(sizeof(*omap), GFP_KERNEL);
if (!omap) {
dev_err(dev, "Memory allocation failed\n");
ret = -ENOMEM;
goto end_probe;
}
spin_lock_init(&omap->lock);
for (i = 0; i < OMAP3_HS_USB_PORTS; i++)
omap->platdata.port_mode[i] = pdata->port_mode[i];
omap->platdata.ehci_data = pdata->ehci_data;
omap->platdata.ohci_data = pdata->ohci_data;
pm_runtime_enable(dev);
for (i = 0; i < OMAP3_HS_USB_PORTS; i++)
if (is_ehci_phy_mode(i) || is_ehci_tll_mode(i) ||
is_ehci_hsic_mode(i)) {
omap->ehci_logic_fck = clk_get(dev, "ehci_logic_fck");
if (IS_ERR(omap->ehci_logic_fck)) {
ret = PTR_ERR(omap->ehci_logic_fck);
dev_warn(dev, "ehci_logic_fck failed:%d\n",
ret);
}
break;
}
omap->utmi_p1_fck = clk_get(dev, "utmi_p1_gfclk");
if (IS_ERR(omap->utmi_p1_fck)) {
ret = PTR_ERR(omap->utmi_p1_fck);
dev_err(dev, "utmi_p1_gfclk failed error:%d\n", ret);
goto err_end;
}
omap->xclk60mhsp1_ck = clk_get(dev, "xclk60mhsp1_ck");
if (IS_ERR(omap->xclk60mhsp1_ck)) {
ret = PTR_ERR(omap->xclk60mhsp1_ck);
dev_err(dev, "xclk60mhsp1_ck failed error:%d\n", ret);
goto err_utmi_p1_fck;
}
omap->utmi_p2_fck = clk_get(dev, "utmi_p2_gfclk");
if (IS_ERR(omap->utmi_p2_fck)) {
ret = PTR_ERR(omap->utmi_p2_fck);
dev_err(dev, "utmi_p2_gfclk failed error:%d\n", ret);
goto err_xclk60mhsp1_ck;
}
omap->xclk60mhsp2_ck = clk_get(dev, "xclk60mhsp2_ck");
if (IS_ERR(omap->xclk60mhsp2_ck)) {
ret = PTR_ERR(omap->xclk60mhsp2_ck);
dev_err(dev, "xclk60mhsp2_ck failed error:%d\n", ret);
goto err_utmi_p2_fck;
}
omap->usbhost_p1_fck = clk_get(dev, "usb_host_hs_utmi_p1_clk");
if (IS_ERR(omap->usbhost_p1_fck)) {
ret = PTR_ERR(omap->usbhost_p1_fck);
dev_err(dev, "usbhost_p1_fck failed error:%d\n", ret);
goto err_xclk60mhsp2_ck;
}
omap->usbhost_p2_fck = clk_get(dev, "usb_host_hs_utmi_p2_clk");
if (IS_ERR(omap->usbhost_p2_fck)) {
ret = PTR_ERR(omap->usbhost_p2_fck);
dev_err(dev, "usbhost_p2_fck failed error:%d\n", ret);
goto err_usbhost_p1_fck;
}
omap->init_60m_fclk = clk_get(dev, "init_60m_fclk");
if (IS_ERR(omap->init_60m_fclk)) {
ret = PTR_ERR(omap->init_60m_fclk);
dev_err(dev, "init_60m_fclk failed error:%d\n", ret);
goto err_usbhost_p2_fck;
}
if (is_ehci_phy_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_fck,
omap->xclk60mhsp1_ck);
if (ret != 0)
dev_err(dev, "xclk60mhsp1_ck set parent"
"failed error:%d\n", ret);
} else if (is_ehci_tll_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_fck,
omap->init_60m_fclk);
if (ret != 0)
dev_err(dev, "init_60m_fclk set parent"
"failed error:%d\n", ret);
}
if (is_ehci_phy_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_fck,
omap->xclk60mhsp2_ck);
if (ret != 0)
dev_err(dev, "xclk60mhsp2_ck set parent"
"failed error:%d\n", ret);
} else if (is_ehci_tll_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_fck,
omap->init_60m_fclk);
if (ret != 0)
dev_err(dev, "init_60m_fclk set parent"
"failed error:%d\n", ret);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "uhh");
if (!res) {
dev_err(dev, "UHH EHCI get resource failed\n");
ret = -ENODEV;
goto err_init_60m_fclk;
}
omap->uhh_base = ioremap(res->start, resource_size(res));
if (!omap->uhh_base) {
dev_err(dev, "UHH ioremap failed\n");
ret = -ENOMEM;
goto err_init_60m_fclk;
}
platform_set_drvdata(pdev, omap);
omap_usbhs_init(dev);
ret = omap_usbhs_alloc_children(pdev);
if (ret) {
dev_err(dev, "omap_usbhs_alloc_children failed\n");
goto err_alloc;
}
goto end_probe;
err_alloc:
omap_usbhs_deinit(&pdev->dev);
iounmap(omap->uhh_base);
err_init_60m_fclk:
clk_put(omap->init_60m_fclk);
err_usbhost_p2_fck:
clk_put(omap->usbhost_p2_fck);
err_usbhost_p1_fck:
clk_put(omap->usbhost_p1_fck);
err_xclk60mhsp2_ck:
clk_put(omap->xclk60mhsp2_ck);
err_utmi_p2_fck:
clk_put(omap->utmi_p2_fck);
err_xclk60mhsp1_ck:
clk_put(omap->xclk60mhsp1_ck);
err_utmi_p1_fck:
clk_put(omap->utmi_p1_fck);
err_end:
clk_put(omap->ehci_logic_fck);
pm_runtime_disable(dev);
kfree(omap);
end_probe:
return ret;
}
static int usbhs_omap_remove(struct platform_device *pdev)
{
struct usbhs_hcd_omap *omap = platform_get_drvdata(pdev);
omap_usbhs_deinit(&pdev->dev);
iounmap(omap->uhh_base);
clk_put(omap->init_60m_fclk);
clk_put(omap->usbhost_p2_fck);
clk_put(omap->usbhost_p1_fck);
clk_put(omap->xclk60mhsp2_ck);
clk_put(omap->utmi_p2_fck);
clk_put(omap->xclk60mhsp1_ck);
clk_put(omap->utmi_p1_fck);
clk_put(omap->ehci_logic_fck);
pm_runtime_disable(&pdev->dev);
kfree(omap);
return 0;
}
static int __init omap_usbhs_drvinit(void)
{
return platform_driver_probe(&usbhs_omap_driver, usbhs_omap_probe);
}
static void __exit omap_usbhs_drvexit(void)
{
platform_driver_unregister(&usbhs_omap_driver);
}
