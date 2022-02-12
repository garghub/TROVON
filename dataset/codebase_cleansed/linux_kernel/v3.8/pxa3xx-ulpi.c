static inline u32 u2d_readl(u32 reg)
{
return __raw_readl(u2d->mmio_base + reg);
}
static inline void u2d_writel(u32 reg, u32 val)
{
__raw_writel(val, u2d->mmio_base + reg);
}
static inline enum u2d_ulpi_phy_mode pxa310_ulpi_get_phymode(void)
{
return (u2d_readl(U2DOTGUSR) >> 28) & 0xF;
}
static int pxa310_ulpi_poll(void)
{
int timeout = 50000;
while (timeout--) {
if (!(u2d_readl(U2DOTGUCR) & U2DOTGUCR_RUN))
return 0;
cpu_relax();
}
pr_warning("%s: ULPI access timed out!\n", __func__);
return -ETIMEDOUT;
}
static int pxa310_ulpi_read(struct usb_phy *otg, u32 reg)
{
int err;
if (pxa310_ulpi_get_phymode() != SYNCH) {
pr_warning("%s: PHY is not in SYNCH mode!\n", __func__);
return -EBUSY;
}
u2d_writel(U2DOTGUCR, U2DOTGUCR_RUN | U2DOTGUCR_RNW | (reg << 16));
msleep(5);
err = pxa310_ulpi_poll();
if (err)
return err;
return u2d_readl(U2DOTGUCR) & U2DOTGUCR_RDATA;
}
static int pxa310_ulpi_write(struct usb_phy *otg, u32 val, u32 reg)
{
if (pxa310_ulpi_get_phymode() != SYNCH) {
pr_warning("%s: PHY is not in SYNCH mode!\n", __func__);
return -EBUSY;
}
u2d_writel(U2DOTGUCR, U2DOTGUCR_RUN | (reg << 16) | (val << 8));
msleep(5);
return pxa310_ulpi_poll();
}
static void pxa310_otg_transceiver_rtsm(void)
{
u32 u2dotgcr;
u2dotgcr = u2d_readl(U2DOTGCR);
u2dotgcr |= U2DOTGCR_RTSM | U2DOTGCR_UTMID;
u2d_writel(U2DOTGCR, u2dotgcr);
msleep(10);
u2dotgcr = u2d_readl(U2DOTGCR);
u2dotgcr |= U2DOTGCR_ULAF;
u2dotgcr &= ~(U2DOTGCR_SMAF | U2DOTGCR_CKAF);
u2d_writel(U2DOTGCR, u2dotgcr);
}
static int pxa310_start_otg_host_transcvr(struct usb_bus *host)
{
int err;
pxa310_otg_transceiver_rtsm();
err = usb_phy_init(u2d->otg);
if (err) {
pr_err("OTG transceiver init failed");
return err;
}
err = otg_set_vbus(u2d->otg->otg, 1);
if (err) {
pr_err("OTG transceiver VBUS set failed");
return err;
}
err = otg_set_host(u2d->otg->otg, host);
if (err)
pr_err("OTG transceiver Host mode set failed");
return err;
}
static int pxa310_start_otg_hc(struct usb_bus *host)
{
u32 u2dotgcr;
int err;
u2d_writel(U2DCR, u2d_readl(U2DCR) & ~U2DCR_UDE);
u2d_writel(U2DOTGCR, u2d_readl(U2DOTGCR) | U2DOTGCR_UTMID);
u2d_writel(U2DOTGICR, u2d_readl(U2DOTGICR) & ~0x37F7F);
err = pxa310_start_otg_host_transcvr(host);
if (err)
return err;
if (u2d->ulpi_mode & ULPI_IC_6PIN_SERIAL)
u2d_writel(U2DP3CR, u2d_readl(U2DP3CR) & ~U2DP3CR_P2SS);
else if (u2d->ulpi_mode & ULPI_IC_3PIN_SERIAL)
u2d_writel(U2DP3CR, u2d_readl(U2DP3CR) | U2DP3CR_P2SS);
u2dotgcr = u2d_readl(U2DOTGCR) | U2DOTGCR_SMAF;
u2d_writel(U2DOTGCR, u2dotgcr & ~(U2DOTGCR_ULAF | U2DOTGCR_CKAF));
return 0;
}
static void pxa310_stop_otg_hc(void)
{
pxa310_otg_transceiver_rtsm();
otg_set_host(u2d->otg->otg, NULL);
otg_set_vbus(u2d->otg->otg, 0);
usb_phy_shutdown(u2d->otg);
}
static void pxa310_u2d_setup_otg_hc(void)
{
u32 u2dotgcr;
u2dotgcr = u2d_readl(U2DOTGCR);
u2dotgcr |= U2DOTGCR_ULAF | U2DOTGCR_UTMID;
u2dotgcr &= ~(U2DOTGCR_SMAF | U2DOTGCR_CKAF);
u2d_writel(U2DOTGCR, u2dotgcr);
msleep(5);
u2d_writel(U2DOTGCR, u2dotgcr | U2DOTGCR_ULE);
msleep(5);
u2d_writel(U2DOTGICR, u2d_readl(U2DOTGICR) & ~0x37F7F);
}
static int pxa310_otg_init(struct pxa3xx_u2d_platform_data *pdata)
{
unsigned int ulpi_mode = ULPI_OTG_DRVVBUS;
if (pdata) {
if (pdata->ulpi_mode & ULPI_SER_6PIN)
ulpi_mode |= ULPI_IC_6PIN_SERIAL;
else if (pdata->ulpi_mode & ULPI_SER_3PIN)
ulpi_mode |= ULPI_IC_3PIN_SERIAL;
}
u2d->ulpi_mode = ulpi_mode;
u2d->otg = otg_ulpi_create(&pxa310_ulpi_access_ops, ulpi_mode);
if (!u2d->otg)
return -ENOMEM;
u2d->otg->io_priv = u2d->mmio_base;
return 0;
}
static void pxa310_otg_exit(void)
{
kfree(u2d->otg);
}
static inline void pxa310_u2d_setup_otg_hc(void) {}
static inline int pxa310_start_otg_hc(struct usb_bus *host)
{
return 0;
}
static inline void pxa310_stop_otg_hc(void) {}
static inline int pxa310_otg_init(struct pxa3xx_u2d_platform_data *pdata)
{
return 0;
}
static inline void pxa310_otg_exit(void) {}
int pxa3xx_u2d_start_hc(struct usb_bus *host)
{
int err = 0;
if (!u2d)
return 0;
clk_enable(u2d->clk);
if (cpu_is_pxa310()) {
pxa310_u2d_setup_otg_hc();
err = pxa310_start_otg_hc(host);
}
return err;
}
void pxa3xx_u2d_stop_hc(struct usb_bus *host)
{
if (!u2d)
return;
if (cpu_is_pxa310())
pxa310_stop_otg_hc();
clk_disable(u2d->clk);
}
static int pxa3xx_u2d_probe(struct platform_device *pdev)
{
struct pxa3xx_u2d_platform_data *pdata = pdev->dev.platform_data;
struct resource *r;
int err;
u2d = kzalloc(sizeof(struct pxa3xx_u2d_ulpi), GFP_KERNEL);
if (!u2d) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
u2d->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(u2d->clk)) {
dev_err(&pdev->dev, "failed to get u2d clock\n");
err = PTR_ERR(u2d->clk);
goto err_free_mem;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "no IO memory resource defined\n");
err = -ENODEV;
goto err_put_clk;
}
r = request_mem_region(r->start, resource_size(r), pdev->name);
if (!r) {
dev_err(&pdev->dev, "failed to request memory resource\n");
err = -EBUSY;
goto err_put_clk;
}
u2d->mmio_base = ioremap(r->start, resource_size(r));
if (!u2d->mmio_base) {
dev_err(&pdev->dev, "ioremap() failed\n");
err = -ENODEV;
goto err_free_res;
}
if (pdata->init) {
err = pdata->init(&pdev->dev);
if (err)
goto err_free_io;
}
if (cpu_is_pxa310()) {
err = pxa310_otg_init(pdata);
if (err)
goto err_free_plat;
}
platform_set_drvdata(pdev, &u2d);
return 0;
err_free_plat:
if (pdata->exit)
pdata->exit(&pdev->dev);
err_free_io:
iounmap(u2d->mmio_base);
err_free_res:
release_mem_region(r->start, resource_size(r));
err_put_clk:
clk_put(u2d->clk);
err_free_mem:
kfree(u2d);
return err;
}
static int pxa3xx_u2d_remove(struct platform_device *pdev)
{
struct pxa3xx_u2d_platform_data *pdata = pdev->dev.platform_data;
struct resource *r;
if (cpu_is_pxa310()) {
pxa310_stop_otg_hc();
pxa310_otg_exit();
}
if (pdata->exit)
pdata->exit(&pdev->dev);
platform_set_drvdata(pdev, NULL);
iounmap(u2d->mmio_base);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(r->start, resource_size(r));
clk_put(u2d->clk);
kfree(u2d);
return 0;
}
