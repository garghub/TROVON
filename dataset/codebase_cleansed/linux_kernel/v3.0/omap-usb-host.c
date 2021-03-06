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
child->dev.coherent_dma_mask = 0xffffffff;
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
static int __devinit usbhs_omap_probe(struct platform_device *pdev)
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
omap->usbhost_ick = clk_get(dev, "usbhost_ick");
if (IS_ERR(omap->usbhost_ick)) {
ret = PTR_ERR(omap->usbhost_ick);
dev_err(dev, "usbhost_ick failed error:%d\n", ret);
goto err_end;
}
omap->usbhost_hs_fck = clk_get(dev, "hs_fck");
if (IS_ERR(omap->usbhost_hs_fck)) {
ret = PTR_ERR(omap->usbhost_hs_fck);
dev_err(dev, "usbhost_hs_fck failed error:%d\n", ret);
goto err_usbhost_ick;
}
omap->usbhost_fs_fck = clk_get(dev, "fs_fck");
if (IS_ERR(omap->usbhost_fs_fck)) {
ret = PTR_ERR(omap->usbhost_fs_fck);
dev_err(dev, "usbhost_fs_fck failed error:%d\n", ret);
goto err_usbhost_hs_fck;
}
omap->usbtll_fck = clk_get(dev, "usbtll_fck");
if (IS_ERR(omap->usbtll_fck)) {
ret = PTR_ERR(omap->usbtll_fck);
dev_err(dev, "usbtll_fck failed error:%d\n", ret);
goto err_usbhost_fs_fck;
}
omap->usbtll_ick = clk_get(dev, "usbtll_ick");
if (IS_ERR(omap->usbtll_ick)) {
ret = PTR_ERR(omap->usbtll_ick);
dev_err(dev, "usbtll_ick failed error:%d\n", ret);
goto err_usbtll_fck;
}
omap->utmi_p1_fck = clk_get(dev, "utmi_p1_gfclk");
if (IS_ERR(omap->utmi_p1_fck)) {
ret = PTR_ERR(omap->utmi_p1_fck);
dev_err(dev, "utmi_p1_gfclk failed error:%d\n", ret);
goto err_usbtll_ick;
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
omap->usbtll_p1_fck = clk_get(dev, "usb_tll_hs_usb_ch0_clk");
if (IS_ERR(omap->usbtll_p1_fck)) {
ret = PTR_ERR(omap->usbtll_p1_fck);
dev_err(dev, "usbtll_p1_fck failed error:%d\n", ret);
goto err_usbhost_p1_fck;
}
omap->usbhost_p2_fck = clk_get(dev, "usb_host_hs_utmi_p2_clk");
if (IS_ERR(omap->usbhost_p2_fck)) {
ret = PTR_ERR(omap->usbhost_p2_fck);
dev_err(dev, "usbhost_p2_fck failed error:%d\n", ret);
goto err_usbtll_p1_fck;
}
omap->usbtll_p2_fck = clk_get(dev, "usb_tll_hs_usb_ch1_clk");
if (IS_ERR(omap->usbtll_p2_fck)) {
ret = PTR_ERR(omap->usbtll_p2_fck);
dev_err(dev, "usbtll_p2_fck failed error:%d\n", ret);
goto err_usbhost_p2_fck;
}
omap->init_60m_fclk = clk_get(dev, "init_60m_fclk");
if (IS_ERR(omap->init_60m_fclk)) {
ret = PTR_ERR(omap->init_60m_fclk);
dev_err(dev, "init_60m_fclk failed error:%d\n", ret);
goto err_usbtll_p2_fck;
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
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "tll");
if (!res) {
dev_err(dev, "UHH EHCI get resource failed\n");
ret = -ENODEV;
goto err_tll;
}
omap->tll_base = ioremap(res->start, resource_size(res));
if (!omap->tll_base) {
dev_err(dev, "TLL ioremap failed\n");
ret = -ENOMEM;
goto err_tll;
}
platform_set_drvdata(pdev, omap);
ret = omap_usbhs_alloc_children(pdev);
if (ret) {
dev_err(dev, "omap_usbhs_alloc_children failed\n");
goto err_alloc;
}
goto end_probe;
err_alloc:
iounmap(omap->tll_base);
err_tll:
iounmap(omap->uhh_base);
err_init_60m_fclk:
clk_put(omap->init_60m_fclk);
err_usbtll_p2_fck:
clk_put(omap->usbtll_p2_fck);
err_usbhost_p2_fck:
clk_put(omap->usbhost_p2_fck);
err_usbtll_p1_fck:
clk_put(omap->usbtll_p1_fck);
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
err_usbtll_ick:
clk_put(omap->usbtll_ick);
err_usbtll_fck:
clk_put(omap->usbtll_fck);
err_usbhost_fs_fck:
clk_put(omap->usbhost_fs_fck);
err_usbhost_hs_fck:
clk_put(omap->usbhost_hs_fck);
err_usbhost_ick:
clk_put(omap->usbhost_ick);
err_end:
kfree(omap);
end_probe:
return ret;
}
static int __devexit usbhs_omap_remove(struct platform_device *pdev)
{
struct usbhs_hcd_omap *omap = platform_get_drvdata(pdev);
if (omap->count != 0) {
dev_err(&pdev->dev,
"Either EHCI or OHCI is still using usbhs core\n");
return -EBUSY;
}
iounmap(omap->tll_base);
iounmap(omap->uhh_base);
clk_put(omap->init_60m_fclk);
clk_put(omap->usbtll_p2_fck);
clk_put(omap->usbhost_p2_fck);
clk_put(omap->usbtll_p1_fck);
clk_put(omap->usbhost_p1_fck);
clk_put(omap->xclk60mhsp2_ck);
clk_put(omap->utmi_p2_fck);
clk_put(omap->xclk60mhsp1_ck);
clk_put(omap->utmi_p1_fck);
clk_put(omap->usbtll_ick);
clk_put(omap->usbtll_fck);
clk_put(omap->usbhost_fs_fck);
clk_put(omap->usbhost_hs_fck);
clk_put(omap->usbhost_ick);
kfree(omap);
return 0;
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
static unsigned ohci_omap3_fslsmode(enum usbhs_omap_port_mode mode)
{
switch (mode) {
case OMAP_USBHS_PORT_MODE_UNUSED:
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DATSE0:
return OMAP_TLL_FSLSMODE_6PIN_PHY_DAT_SE0;
case OMAP_OHCI_PORT_MODE_PHY_6PIN_DPDM:
return OMAP_TLL_FSLSMODE_6PIN_PHY_DP_DM;
case OMAP_OHCI_PORT_MODE_PHY_3PIN_DATSE0:
return OMAP_TLL_FSLSMODE_3PIN_PHY;
case OMAP_OHCI_PORT_MODE_PHY_4PIN_DPDM:
return OMAP_TLL_FSLSMODE_4PIN_PHY;
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DATSE0:
return OMAP_TLL_FSLSMODE_6PIN_TLL_DAT_SE0;
case OMAP_OHCI_PORT_MODE_TLL_6PIN_DPDM:
return OMAP_TLL_FSLSMODE_6PIN_TLL_DP_DM;
case OMAP_OHCI_PORT_MODE_TLL_3PIN_DATSE0:
return OMAP_TLL_FSLSMODE_3PIN_TLL;
case OMAP_OHCI_PORT_MODE_TLL_4PIN_DPDM:
return OMAP_TLL_FSLSMODE_4PIN_TLL;
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DATSE0:
return OMAP_TLL_FSLSMODE_2PIN_TLL_DAT_SE0;
case OMAP_OHCI_PORT_MODE_TLL_2PIN_DPDM:
return OMAP_TLL_FSLSMODE_2PIN_DAT_DP_DM;
default:
pr_warning("Invalid port mode, using default\n");
return OMAP_TLL_FSLSMODE_6PIN_PHY_DAT_SE0;
}
}
static void usbhs_omap_tll_init(struct device *dev, u8 tll_channel_count)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = dev->platform_data;
unsigned reg;
int i;
reg = usbhs_read(omap->tll_base, OMAP_TLL_SHARED_CONF);
reg |= (OMAP_TLL_SHARED_CONF_FCLK_IS_ON
| OMAP_TLL_SHARED_CONF_USB_DIVRATION);
reg &= ~OMAP_TLL_SHARED_CONF_USB_90D_DDR_EN;
reg &= ~OMAP_TLL_SHARED_CONF_USB_180D_SDR_EN;
usbhs_write(omap->tll_base, OMAP_TLL_SHARED_CONF, reg);
for (i = 0; i < tll_channel_count; i++) {
reg = usbhs_read(omap->tll_base,
OMAP_TLL_CHANNEL_CONF(i));
if (is_ohci_port(pdata->port_mode[i])) {
reg |= ohci_omap3_fslsmode(pdata->port_mode[i])
<< OMAP_TLL_CHANNEL_CONF_FSLSMODE_SHIFT;
reg |= OMAP_TLL_CHANNEL_CONF_CHANMODE_FSLS;
} else if (pdata->port_mode[i] == OMAP_EHCI_PORT_MODE_TLL) {
reg &= ~(OMAP_TLL_CHANNEL_CONF_UTMIAUTOIDLE
| OMAP_TLL_CHANNEL_CONF_ULPINOBITSTUFF
| OMAP_TLL_CHANNEL_CONF_ULPIDDRMODE);
reg |= (1 << (i + 1));
} else
continue;
reg |= OMAP_TLL_CHANNEL_CONF_CHANEN;
usbhs_write(omap->tll_base,
OMAP_TLL_CHANNEL_CONF(i), reg);
usbhs_writeb(omap->tll_base,
OMAP_TLL_ULPI_SCRATCH_REGISTER(i), 0xbe);
}
}
static int usbhs_enable(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
unsigned long flags = 0;
int ret = 0;
unsigned long timeout;
unsigned reg;
dev_dbg(dev, "starting TI HSUSB Controller\n");
if (!pdata) {
dev_dbg(dev, "missing platform_data\n");
return -ENODEV;
}
spin_lock_irqsave(&omap->lock, flags);
if (omap->count > 0)
goto end_count;
clk_enable(omap->usbhost_ick);
clk_enable(omap->usbhost_hs_fck);
clk_enable(omap->usbhost_fs_fck);
clk_enable(omap->usbtll_fck);
clk_enable(omap->usbtll_ick);
if (pdata->ehci_data->phy_reset) {
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0])) {
gpio_request(pdata->ehci_data->reset_gpio_port[0],
"USB1 PHY reset");
gpio_direction_output
(pdata->ehci_data->reset_gpio_port[0], 0);
}
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1])) {
gpio_request(pdata->ehci_data->reset_gpio_port[1],
"USB2 PHY reset");
gpio_direction_output
(pdata->ehci_data->reset_gpio_port[1], 0);
}
udelay(10);
}
omap->usbhs_rev = usbhs_read(omap->uhh_base, OMAP_UHH_REVISION);
dev_dbg(dev, "OMAP UHH_REVISION 0x%x\n", omap->usbhs_rev);
usbhs_write(omap->tll_base, OMAP_USBTLL_SYSCONFIG,
OMAP_USBTLL_SYSCONFIG_SOFTRESET);
timeout = jiffies + msecs_to_jiffies(1000);
while (!(usbhs_read(omap->tll_base, OMAP_USBTLL_SYSSTATUS)
& OMAP_USBTLL_SYSSTATUS_RESETDONE)) {
cpu_relax();
if (time_after(jiffies, timeout)) {
dev_dbg(dev, "operation timed out\n");
ret = -EINVAL;
goto err_tll;
}
}
dev_dbg(dev, "TLL RESET DONE\n");
usbhs_write(omap->tll_base, OMAP_USBTLL_SYSCONFIG,
OMAP_USBTLL_SYSCONFIG_ENAWAKEUP |
OMAP_USBTLL_SYSCONFIG_SIDLEMODE |
OMAP_USBTLL_SYSCONFIG_AUTOIDLE);
reg = usbhs_read(omap->uhh_base, OMAP_UHH_SYSCONFIG);
if (is_omap_usbhs_rev1(omap)) {
reg |= (OMAP_UHH_SYSCONFIG_ENAWAKEUP
| OMAP_UHH_SYSCONFIG_SIDLEMODE
| OMAP_UHH_SYSCONFIG_CACTIVITY
| OMAP_UHH_SYSCONFIG_MIDLEMODE);
reg &= ~OMAP_UHH_SYSCONFIG_AUTOIDLE;
} else if (is_omap_usbhs_rev2(omap)) {
reg &= ~OMAP4_UHH_SYSCONFIG_IDLEMODE_CLEAR;
reg |= OMAP4_UHH_SYSCONFIG_NOIDLE;
reg &= ~OMAP4_UHH_SYSCONFIG_STDBYMODE_CLEAR;
reg |= OMAP4_UHH_SYSCONFIG_NOSTDBY;
}
usbhs_write(omap->uhh_base, OMAP_UHH_SYSCONFIG, reg);
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
if (cpu_is_omap3430() && (omap_rev() <= OMAP3430_REV_ES2_1)) {
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
if (is_ehci_phy_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_fck,
omap->xclk60mhsp1_ck);
if (ret != 0) {
dev_err(dev, "xclk60mhsp1_ck set parent"
"failed error:%d\n", ret);
goto err_tll;
}
} else if (is_ehci_tll_mode(pdata->port_mode[0])) {
ret = clk_set_parent(omap->utmi_p1_fck,
omap->init_60m_fclk);
if (ret != 0) {
dev_err(dev, "init_60m_fclk set parent"
"failed error:%d\n", ret);
goto err_tll;
}
clk_enable(omap->usbhost_p1_fck);
clk_enable(omap->usbtll_p1_fck);
}
if (is_ehci_phy_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_fck,
omap->xclk60mhsp2_ck);
if (ret != 0) {
dev_err(dev, "xclk60mhsp1_ck set parent"
"failed error:%d\n", ret);
goto err_tll;
}
} else if (is_ehci_tll_mode(pdata->port_mode[1])) {
ret = clk_set_parent(omap->utmi_p2_fck,
omap->init_60m_fclk);
if (ret != 0) {
dev_err(dev, "init_60m_fclk set parent"
"failed error:%d\n", ret);
goto err_tll;
}
clk_enable(omap->usbhost_p2_fck);
clk_enable(omap->usbtll_p2_fck);
}
clk_enable(omap->utmi_p1_fck);
clk_enable(omap->utmi_p2_fck);
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
if (is_ehci_tll_mode(pdata->port_mode[0]) ||
is_ehci_tll_mode(pdata->port_mode[1]) ||
is_ehci_tll_mode(pdata->port_mode[2]) ||
(is_ohci_port(pdata->port_mode[0])) ||
(is_ohci_port(pdata->port_mode[1])) ||
(is_ohci_port(pdata->port_mode[2]))) {
if (is_omap_usbhs_rev2(omap))
usbhs_omap_tll_init(dev, OMAP_REV2_TLL_CHANNEL_COUNT);
else
usbhs_omap_tll_init(dev, OMAP_TLL_CHANNEL_COUNT);
}
if (pdata->ehci_data->phy_reset) {
udelay(10);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_set_value
(pdata->ehci_data->reset_gpio_port[0], 1);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_set_value
(pdata->ehci_data->reset_gpio_port[1], 1);
}
end_count:
omap->count++;
spin_unlock_irqrestore(&omap->lock, flags);
return 0;
err_tll:
if (pdata->ehci_data->phy_reset) {
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_free(pdata->ehci_data->reset_gpio_port[0]);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_free(pdata->ehci_data->reset_gpio_port[1]);
}
clk_disable(omap->usbtll_ick);
clk_disable(omap->usbtll_fck);
clk_disable(omap->usbhost_fs_fck);
clk_disable(omap->usbhost_hs_fck);
clk_disable(omap->usbhost_ick);
spin_unlock_irqrestore(&omap->lock, flags);
return ret;
}
static void usbhs_disable(struct device *dev)
{
struct usbhs_hcd_omap *omap = dev_get_drvdata(dev);
struct usbhs_omap_platform_data *pdata = &omap->platdata;
unsigned long flags = 0;
unsigned long timeout;
dev_dbg(dev, "stopping TI HSUSB Controller\n");
spin_lock_irqsave(&omap->lock, flags);
if (omap->count == 0)
goto end_disble;
omap->count--;
if (omap->count != 0)
goto end_disble;
usbhs_write(omap->uhh_base, OMAP_UHH_SYSCONFIG,
is_omap_usbhs_rev2(omap) ?
OMAP4_UHH_SYSCONFIG_SOFTRESET :
OMAP_UHH_SYSCONFIG_SOFTRESET);
timeout = jiffies + msecs_to_jiffies(100);
while (!(usbhs_read(omap->uhh_base, OMAP_UHH_SYSSTATUS)
& (1 << 0))) {
cpu_relax();
if (time_after(jiffies, timeout))
dev_dbg(dev, "operation timed out\n");
}
while (!(usbhs_read(omap->uhh_base, OMAP_UHH_SYSSTATUS)
& (1 << 1))) {
cpu_relax();
if (time_after(jiffies, timeout))
dev_dbg(dev, "operation timed out\n");
}
while (!(usbhs_read(omap->uhh_base, OMAP_UHH_SYSSTATUS)
& (1 << 2))) {
cpu_relax();
if (time_after(jiffies, timeout))
dev_dbg(dev, "operation timed out\n");
}
usbhs_write(omap->tll_base, OMAP_USBTLL_SYSCONFIG, (1 << 1));
while (!(usbhs_read(omap->tll_base, OMAP_USBTLL_SYSSTATUS)
& (1 << 0))) {
cpu_relax();
if (time_after(jiffies, timeout))
dev_dbg(dev, "operation timed out\n");
}
if (is_omap_usbhs_rev2(omap)) {
if (is_ehci_tll_mode(pdata->port_mode[0]))
clk_enable(omap->usbtll_p1_fck);
if (is_ehci_tll_mode(pdata->port_mode[1]))
clk_enable(omap->usbtll_p2_fck);
clk_disable(omap->utmi_p2_fck);
clk_disable(omap->utmi_p1_fck);
}
clk_disable(omap->usbtll_ick);
clk_disable(omap->usbtll_fck);
clk_disable(omap->usbhost_fs_fck);
clk_disable(omap->usbhost_hs_fck);
clk_disable(omap->usbhost_ick);
spin_unlock_irqrestore(&omap->lock, flags);
if (pdata->ehci_data->phy_reset) {
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[0]))
gpio_free(pdata->ehci_data->reset_gpio_port[0]);
if (gpio_is_valid(pdata->ehci_data->reset_gpio_port[1]))
gpio_free(pdata->ehci_data->reset_gpio_port[1]);
}
return;
end_disble:
spin_unlock_irqrestore(&omap->lock, flags);
}
int omap_usbhs_enable(struct device *dev)
{
return usbhs_enable(dev->parent);
}
void omap_usbhs_disable(struct device *dev)
{
usbhs_disable(dev->parent);
}
static int __init omap_usbhs_drvinit(void)
{
return platform_driver_probe(&usbhs_omap_driver, usbhs_omap_probe);
}
static void __exit omap_usbhs_drvexit(void)
{
platform_driver_unregister(&usbhs_omap_driver);
}
