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
struct usbhs_omap_platform_data *pdata = dev->platform_data;
struct platform_device *ehci;
struct platform_device *ohci;
struct resource *res;
struct resource resources[2];
int ret;
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
ehci = omap_usbhs_alloc_child(OMAP_EHCI_DEVICE, resources, 2, pdata,
sizeof(*pdata), dev);
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
ohci = omap_usbhs_alloc_child(OMAP_OHCI_DEVICE, resources, 2, pdata,
sizeof(*pdata), dev);
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
struct usbhs_omap_platform_data *pdata = omap->pdata;
int i, r;
dev_dbg(dev, "usbhs_runtime_resume\n");
omap_tll_enable();
if (!IS_ERR(omap->ehci_logic_fck))
clk_enable(omap->ehci_logic_fck);
for (i = 0; i < omap->nports; i++) {
switch (pdata->port_mode[i]) {
case OMAP_EHCI_PORT_MODE_HSIC:
if (!IS_ERR(omap->hsic60m_clk[i])) {
r = clk_enable(omap->hsic60m_clk[i]);
if (r) {
dev_err(dev,
"Can't enable port %d hsic60m clk:%d\n",
i, r);
}
}
if (!IS_ERR(omap->hsic480m_clk[i])) {
r = clk_enable(omap->hsic480m_clk[i]);
if (r) {
dev_err(dev,
"Can't enable port %d hsic480m clk:%d\n",
i, r);
}
}
case OMAP_EHCI_PORT_MODE_TLL:
if (!IS_ERR(omap->utmi_clk[i])) {
r = clk_enable(omap->utmi_clk[i]);
if (r) {
dev_err(dev,
"Can't enable port %d clk : %d\n",
i, r);
}
}
break;
default:
break;
}
}
return 0;
}
static int usbhs_runtime_suspend(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = omap->pdata;
int i;
dev_dbg(dev, "usbhs_runtime_suspend\n");
for (i = 0; i < omap->nports; i++) {
switch (pdata->port_mode[i]) {
case OMAP_EHCI_PORT_MODE_HSIC:
if (!IS_ERR(omap->hsic60m_clk[i]))
clk_disable(omap->hsic60m_clk[i]);
if (!IS_ERR(omap->hsic480m_clk[i]))
clk_disable(omap->hsic480m_clk[i]);
case OMAP_EHCI_PORT_MODE_TLL:
if (!IS_ERR(omap->utmi_clk[i]))
clk_disable(omap->utmi_clk[i]);
break;
default:
break;
}
}
if (!IS_ERR(omap->ehci_logic_fck))
clk_disable(omap->ehci_logic_fck);
omap_tll_disable();
return 0;
}
static unsigned omap_usbhs_rev1_hostconfig(struct usbhs_hcd_omap *omap,
unsigned reg)
{
struct usbhs_omap_platform_data *pdata = omap->pdata;
int i;
for (i = 0; i < omap->nports; i++) {
switch (pdata->port_mode[i]) {
case OMAP_USBHS_PORT_MODE_UNUSED:
reg &= ~(OMAP_UHH_HOSTCONFIG_P1_CONNECT_STATUS << i);
break;
case OMAP_EHCI_PORT_MODE_PHY:
if (pdata->single_ulpi_bypass)
break;
if (i == 0)
reg &= ~OMAP_UHH_HOSTCONFIG_ULPI_P1_BYPASS;
else
reg &= ~(OMAP_UHH_HOSTCONFIG_ULPI_P2_BYPASS
<< (i-1));
break;
default:
if (pdata->single_ulpi_bypass)
break;
if (i == 0)
reg |= OMAP_UHH_HOSTCONFIG_ULPI_P1_BYPASS;
else
reg |= OMAP_UHH_HOSTCONFIG_ULPI_P2_BYPASS
<< (i-1);
break;
}
}
if (pdata->single_ulpi_bypass) {
reg |= OMAP_UHH_HOSTCONFIG_ULPI_BYPASS;
for (i = 0; i < omap->nports; i++) {
if (is_ehci_phy_mode(pdata->port_mode[i])) {
reg &= OMAP_UHH_HOSTCONFIG_ULPI_BYPASS;
break;
}
}
}
return reg;
}
static unsigned omap_usbhs_rev2_hostconfig(struct usbhs_hcd_omap *omap,
unsigned reg)
{
struct usbhs_omap_platform_data *pdata = omap->pdata;
int i;
for (i = 0; i < omap->nports; i++) {
reg &= ~(OMAP4_P1_MODE_CLEAR << 2 * i);
if (is_ehci_tll_mode(pdata->port_mode[i]) ||
(is_ohci_port(pdata->port_mode[i])))
reg |= OMAP4_P1_MODE_TLL << 2 * i;
else if (is_ehci_hsic_mode(pdata->port_mode[i]))
reg |= OMAP4_P1_MODE_HSIC << 2 * i;
}
return reg;
}
static void omap_usbhs_init(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = omap->pdata;
unsigned reg;
dev_dbg(dev, "starting TI HSUSB Controller\n");
if (pdata->phy_reset) {
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_request_one(pdata->reset_gpio_port[0],
GPIOF_OUT_INIT_LOW, "USB1 PHY reset");
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_request_one(pdata->reset_gpio_port[1],
GPIOF_OUT_INIT_LOW, "USB2 PHY reset");
udelay(10);
}
pm_runtime_get_sync(dev);
reg = usbhs_read(omap->uhh_base, OMAP_UHH_HOSTCONFIG);
reg |= (OMAP_UHH_HOSTCONFIG_INCR4_BURST_EN
| OMAP_UHH_HOSTCONFIG_INCR8_BURST_EN
| OMAP_UHH_HOSTCONFIG_INCR16_BURST_EN);
reg |= OMAP4_UHH_HOSTCONFIG_APP_START_CLK;
reg &= ~OMAP_UHH_HOSTCONFIG_INCRX_ALIGN_EN;
switch (omap->usbhs_rev) {
case OMAP_USBHS_REV1:
reg = omap_usbhs_rev1_hostconfig(omap, reg);
break;
case OMAP_USBHS_REV2:
reg = omap_usbhs_rev2_hostconfig(omap, reg);
break;
default:
reg = omap_usbhs_rev2_hostconfig(omap, reg);
break;
}
usbhs_write(omap->uhh_base, OMAP_UHH_HOSTCONFIG, reg);
dev_dbg(dev, "UHH setup done, uhh_hostconfig=%x\n", reg);
pm_runtime_put_sync(dev);
if (pdata->phy_reset) {
udelay(10);
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_set_value_cansleep
(pdata->reset_gpio_port[0], 1);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_set_value_cansleep
(pdata->reset_gpio_port[1], 1);
}
}
static void omap_usbhs_deinit(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = omap->pdata;
if (pdata->phy_reset) {
if (gpio_is_valid(pdata->reset_gpio_port[0]))
gpio_free(pdata->reset_gpio_port[0]);
if (gpio_is_valid(pdata->reset_gpio_port[1]))
gpio_free(pdata->reset_gpio_port[1]);
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
bool need_logic_fck;
if (!pdata) {
dev_err(dev, "Missing platform data\n");
return -ENODEV;
}
omap = devm_kzalloc(dev, sizeof(*omap), GFP_KERNEL);
if (!omap) {
dev_err(dev, "Memory allocation failed\n");
return -ENOMEM;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "uhh");
omap->uhh_base = devm_request_and_ioremap(dev, res);
if (!omap->uhh_base) {
dev_err(dev, "Resource request/ioremap failed\n");
return -EADDRNOTAVAIL;
}
omap->pdata = pdata;
pm_runtime_enable(dev);
platform_set_drvdata(pdev, omap);
pm_runtime_get_sync(dev);
omap->usbhs_rev = usbhs_read(omap->uhh_base, OMAP_UHH_REVISION);
pm_runtime_put_sync(dev);
if (pdata->nports) {
omap->nports = pdata->nports;
} else {
switch (omap->usbhs_rev) {
case OMAP_USBHS_REV1:
omap->nports = 3;
break;
case OMAP_USBHS_REV2:
omap->nports = 2;
break;
default:
omap->nports = OMAP3_HS_USB_PORTS;
dev_dbg(dev,
"USB HOST Rev:0x%d not recognized, assuming %d ports\n",
omap->usbhs_rev, omap->nports);
break;
}
}
i = sizeof(struct clk *) * omap->nports;
omap->utmi_clk = devm_kzalloc(dev, i, GFP_KERNEL);
omap->hsic480m_clk = devm_kzalloc(dev, i, GFP_KERNEL);
omap->hsic60m_clk = devm_kzalloc(dev, i, GFP_KERNEL);
if (!omap->utmi_clk || !omap->hsic480m_clk || !omap->hsic60m_clk) {
dev_err(dev, "Memory allocation failed\n");
ret = -ENOMEM;
goto err_mem;
}
need_logic_fck = false;
for (i = 0; i < omap->nports; i++) {
if (is_ehci_phy_mode(i) || is_ehci_tll_mode(i) ||
is_ehci_hsic_mode(i))
need_logic_fck |= true;
}
omap->ehci_logic_fck = ERR_PTR(-EINVAL);
if (need_logic_fck) {
omap->ehci_logic_fck = clk_get(dev, "ehci_logic_fck");
if (IS_ERR(omap->ehci_logic_fck)) {
ret = PTR_ERR(omap->ehci_logic_fck);
dev_dbg(dev, "ehci_logic_fck failed:%d\n", ret);
}
}
omap->utmi_p1_gfclk = clk_get(dev, "utmi_p1_gfclk");
if (IS_ERR(omap->utmi_p1_gfclk)) {
ret = PTR_ERR(omap->utmi_p1_gfclk);
dev_err(dev, "utmi_p1_gfclk failed error:%d\n", ret);
goto err_p1_gfclk;
}
omap->utmi_p2_gfclk = clk_get(dev, "utmi_p2_gfclk");
if (IS_ERR(omap->utmi_p2_gfclk)) {
ret = PTR_ERR(omap->utmi_p2_gfclk);
dev_err(dev, "utmi_p2_gfclk failed error:%d\n", ret);
goto err_p2_gfclk;
}
omap->xclk60mhsp1_ck = clk_get(dev, "xclk60mhsp1_ck");
if (IS_ERR(omap->xclk60mhsp1_ck)) {
ret = PTR_ERR(omap->xclk60mhsp1_ck);
dev_err(dev, "xclk60mhsp1_ck failed error:%d\n", ret);
goto err_xclk60mhsp1;
}
omap->xclk60mhsp2_ck = clk_get(dev, "xclk60mhsp2_ck");
if (IS_ERR(omap->xclk60mhsp2_ck)) {
ret = PTR_ERR(omap->xclk60mhsp2_ck);
dev_err(dev, "xclk60mhsp2_ck failed error:%d\n", ret);
goto err_xclk60mhsp2;
}
omap->init_60m_fclk = clk_get(dev, "init_60m_fclk");
if (IS_ERR(omap->init_60m_fclk)) {
ret = PTR_ERR(omap->init_60m_fclk);
dev_err(dev, "init_60m_fclk failed error:%d\n", ret);
goto err_init60m;
}
for (i = 0; i < omap->nports; i++) {
char clkname[30];
snprintf(clkname, sizeof(clkname),
"usb_host_hs_utmi_p%d_clk", i + 1);
omap->utmi_clk[i] = clk_get(dev, clkname);
if (IS_ERR(omap->utmi_clk[i]))
dev_dbg(dev, "Failed to get clock : %s : %ld\n",
clkname, PTR_ERR(omap->utmi_clk[i]));
snprintf(clkname, sizeof(clkname),
"usb_host_hs_hsic480m_p%d_clk", i + 1);
omap->hsic480m_clk[i] = clk_get(dev, clkname);
if (IS_ERR(omap->hsic480m_clk[i]))
dev_dbg(dev, "Failed to get clock : %s : %ld\n",
clkname, PTR_ERR(omap->hsic480m_clk[i]));
snprintf(clkname, sizeof(clkname),
"usb_host_hs_hsic60m_p%d_clk", i + 1);
omap->hsic60m_clk[i] = clk_get(dev, clkname);
if (IS_ERR(omap->hsic60m_clk[i]))
dev_dbg(dev, "Failed to get clock : %s : %ld\n",
clkname, PTR_ERR(omap->hsic60m_clk[i]));
}
if (is_ehci_phy_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_gfclk,
omap->xclk60mhsp1_ck);
if (ret != 0)
dev_dbg(dev, "xclk60mhsp1_ck set parent failed: %d\n",
ret);
} else if (is_ehci_tll_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_gfclk,
omap->init_60m_fclk);
if (ret != 0)
dev_dbg(dev, "P0 init_60m_fclk set parent failed: %d\n",
ret);
}
if (is_ehci_phy_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_gfclk,
omap->xclk60mhsp2_ck);
if (ret != 0)
dev_dbg(dev, "xclk60mhsp2_ck set parent failed: %d\n",
ret);
} else if (is_ehci_tll_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_gfclk,
omap->init_60m_fclk);
if (ret != 0)
dev_dbg(dev, "P1 init_60m_fclk set parent failed: %d\n",
ret);
}
omap_usbhs_init(dev);
ret = omap_usbhs_alloc_children(pdev);
if (ret) {
dev_err(dev, "omap_usbhs_alloc_children failed\n");
goto err_alloc;
}
return 0;
err_alloc:
omap_usbhs_deinit(&pdev->dev);
for (i = 0; i < omap->nports; i++) {
if (!IS_ERR(omap->utmi_clk[i]))
clk_put(omap->utmi_clk[i]);
if (!IS_ERR(omap->hsic60m_clk[i]))
clk_put(omap->hsic60m_clk[i]);
if (!IS_ERR(omap->hsic480m_clk[i]))
clk_put(omap->hsic480m_clk[i]);
}
clk_put(omap->init_60m_fclk);
err_init60m:
clk_put(omap->xclk60mhsp2_ck);
err_xclk60mhsp2:
clk_put(omap->xclk60mhsp1_ck);
err_xclk60mhsp1:
clk_put(omap->utmi_p2_gfclk);
err_p2_gfclk:
clk_put(omap->utmi_p1_gfclk);
err_p1_gfclk:
if (!IS_ERR(omap->ehci_logic_fck))
clk_put(omap->ehci_logic_fck);
err_mem:
pm_runtime_disable(dev);
return ret;
}
static int usbhs_omap_remove(struct platform_device *pdev)
{
struct usbhs_hcd_omap *omap = platform_get_drvdata(pdev);
int i;
omap_usbhs_deinit(&pdev->dev);
for (i = 0; i < omap->nports; i++) {
if (!IS_ERR(omap->utmi_clk[i]))
clk_put(omap->utmi_clk[i]);
if (!IS_ERR(omap->hsic60m_clk[i]))
clk_put(omap->hsic60m_clk[i]);
if (!IS_ERR(omap->hsic480m_clk[i]))
clk_put(omap->hsic480m_clk[i]);
}
clk_put(omap->init_60m_fclk);
clk_put(omap->utmi_p1_gfclk);
clk_put(omap->utmi_p2_gfclk);
clk_put(omap->xclk60mhsp2_ck);
clk_put(omap->xclk60mhsp1_ck);
if (!IS_ERR(omap->ehci_logic_fck))
clk_put(omap->ehci_logic_fck);
pm_runtime_disable(&pdev->dev);
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
