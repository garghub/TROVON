static inline void dmt_enable(struct pic32_dmt *dmt)
{
writel(DMT_ON, PIC32_SET(dmt->regs + DMTCON_REG));
}
static inline void dmt_disable(struct pic32_dmt *dmt)
{
writel(DMT_ON, PIC32_CLR(dmt->regs + DMTCON_REG));
nop();
}
static inline int dmt_bad_status(struct pic32_dmt *dmt)
{
u32 val;
val = readl(dmt->regs + DMTSTAT_REG);
val &= (DMTSTAT_BAD1 | DMTSTAT_BAD2 | DMTSTAT_EVENT);
if (val)
return -EAGAIN;
return 0;
}
static inline int dmt_keepalive(struct pic32_dmt *dmt)
{
u32 v;
u32 timeout = 500;
writel(DMT_STEP1_KEY << 8, dmt->regs + DMTPRECLR_REG);
while (--timeout) {
v = readl(dmt->regs + DMTSTAT_REG) & DMTSTAT_WINOPN;
if (v == DMTSTAT_WINOPN)
break;
}
writel(DMT_STEP2_KEY, dmt->regs + DMTCLR_REG);
return dmt_bad_status(dmt);
}
static inline u32 pic32_dmt_get_timeout_secs(struct pic32_dmt *dmt)
{
unsigned long rate;
rate = clk_get_rate(dmt->clk);
if (rate)
return readl(dmt->regs + DMTPSCNT_REG) / rate;
return 0;
}
static inline u32 pic32_dmt_bootstatus(struct pic32_dmt *dmt)
{
u32 v;
void __iomem *rst_base;
rst_base = ioremap(PIC32_BASE_RESET, 0x10);
if (!rst_base)
return 0;
v = readl(rst_base);
writel(RESETCON_DMT_TIMEOUT, PIC32_CLR(rst_base));
iounmap(rst_base);
return v & RESETCON_DMT_TIMEOUT;
}
static int pic32_dmt_start(struct watchdog_device *wdd)
{
struct pic32_dmt *dmt = watchdog_get_drvdata(wdd);
dmt_enable(dmt);
return dmt_keepalive(dmt);
}
static int pic32_dmt_stop(struct watchdog_device *wdd)
{
struct pic32_dmt *dmt = watchdog_get_drvdata(wdd);
dmt_disable(dmt);
return 0;
}
static int pic32_dmt_ping(struct watchdog_device *wdd)
{
struct pic32_dmt *dmt = watchdog_get_drvdata(wdd);
return dmt_keepalive(dmt);
}
static int pic32_dmt_probe(struct platform_device *pdev)
{
int ret;
struct pic32_dmt *dmt;
struct resource *mem;
struct watchdog_device *wdd = &pic32_dmt_wdd;
dmt = devm_kzalloc(&pdev->dev, sizeof(*dmt), GFP_KERNEL);
if (IS_ERR(dmt))
return PTR_ERR(dmt);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dmt->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(dmt->regs))
return PTR_ERR(dmt->regs);
dmt->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(dmt->clk)) {
dev_err(&pdev->dev, "clk not found\n");
return PTR_ERR(dmt->clk);
}
ret = clk_prepare_enable(dmt->clk);
if (ret)
return ret;
wdd->timeout = pic32_dmt_get_timeout_secs(dmt);
if (!wdd->timeout) {
dev_err(&pdev->dev,
"failed to read watchdog register timeout\n");
ret = -EINVAL;
goto out_disable_clk;
}
dev_info(&pdev->dev, "timeout %d\n", wdd->timeout);
wdd->bootstatus = pic32_dmt_bootstatus(dmt) ? WDIOF_CARDRESET : 0;
watchdog_set_nowayout(wdd, WATCHDOG_NOWAYOUT);
watchdog_set_drvdata(wdd, dmt);
ret = watchdog_register_device(wdd);
if (ret) {
dev_err(&pdev->dev, "watchdog register failed, err %d\n", ret);
goto out_disable_clk;
}
platform_set_drvdata(pdev, wdd);
return 0;
out_disable_clk:
clk_disable_unprepare(dmt->clk);
return ret;
}
static int pic32_dmt_remove(struct platform_device *pdev)
{
struct watchdog_device *wdd = platform_get_drvdata(pdev);
struct pic32_dmt *dmt = watchdog_get_drvdata(wdd);
watchdog_unregister_device(wdd);
clk_disable_unprepare(dmt->clk);
return 0;
}
