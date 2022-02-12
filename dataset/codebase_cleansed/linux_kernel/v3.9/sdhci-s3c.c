static inline struct sdhci_s3c *to_s3c(struct sdhci_host *host)
{
return sdhci_priv(host);
}
static u32 get_curclk(u32 ctrl2)
{
ctrl2 &= S3C_SDHCI_CTRL2_SELBASECLK_MASK;
ctrl2 >>= S3C_SDHCI_CTRL2_SELBASECLK_SHIFT;
return ctrl2;
}
static void sdhci_s3c_check_sclk(struct sdhci_host *host)
{
struct sdhci_s3c *ourhost = to_s3c(host);
u32 tmp = readl(host->ioaddr + S3C_SDHCI_CONTROL2);
if (get_curclk(tmp) != ourhost->cur_clk) {
dev_dbg(&ourhost->pdev->dev, "restored ctrl2 clock setting\n");
tmp &= ~S3C_SDHCI_CTRL2_SELBASECLK_MASK;
tmp |= ourhost->cur_clk << S3C_SDHCI_CTRL2_SELBASECLK_SHIFT;
writel(tmp, host->ioaddr + S3C_SDHCI_CONTROL2);
}
}
static unsigned int sdhci_s3c_get_max_clk(struct sdhci_host *host)
{
struct sdhci_s3c *ourhost = to_s3c(host);
struct clk *busclk;
unsigned int rate, max;
int clk;
sdhci_s3c_check_sclk(host);
for (max = 0, clk = 0; clk < MAX_BUS_CLK; clk++) {
busclk = ourhost->clk_bus[clk];
if (!busclk)
continue;
rate = clk_get_rate(busclk);
if (rate > max)
max = rate;
}
return max;
}
static unsigned int sdhci_s3c_consider_clock(struct sdhci_s3c *ourhost,
unsigned int src,
unsigned int wanted)
{
unsigned long rate;
struct clk *clksrc = ourhost->clk_bus[src];
int div;
if (!clksrc)
return UINT_MAX;
if (ourhost->host->quirks & SDHCI_QUIRK_NONSTANDARD_CLOCK) {
rate = clk_round_rate(clksrc, wanted);
return wanted - rate;
}
rate = clk_get_rate(clksrc);
for (div = 1; div < 256; div *= 2) {
if ((rate / div) <= wanted)
break;
}
dev_dbg(&ourhost->pdev->dev, "clk %d: rate %ld, want %d, got %ld\n",
src, rate, wanted, rate / div);
return wanted - (rate / div);
}
static void sdhci_s3c_set_clock(struct sdhci_host *host, unsigned int clock)
{
struct sdhci_s3c *ourhost = to_s3c(host);
unsigned int best = UINT_MAX;
unsigned int delta;
int best_src = 0;
int src;
u32 ctrl;
if (clock == 0)
return;
for (src = 0; src < MAX_BUS_CLK; src++) {
delta = sdhci_s3c_consider_clock(ourhost, src, clock);
if (delta < best) {
best = delta;
best_src = src;
}
}
dev_dbg(&ourhost->pdev->dev,
"selected source %d, clock %d, delta %d\n",
best_src, clock, best);
if (ourhost->cur_clk != best_src) {
struct clk *clk = ourhost->clk_bus[best_src];
clk_prepare_enable(clk);
clk_disable_unprepare(ourhost->clk_bus[ourhost->cur_clk]);
writew(0, host->ioaddr + SDHCI_CLOCK_CONTROL);
ourhost->cur_clk = best_src;
host->max_clk = clk_get_rate(clk);
ctrl = readl(host->ioaddr + S3C_SDHCI_CONTROL2);
ctrl &= ~S3C_SDHCI_CTRL2_SELBASECLK_MASK;
ctrl |= best_src << S3C_SDHCI_CTRL2_SELBASECLK_SHIFT;
writel(ctrl, host->ioaddr + S3C_SDHCI_CONTROL2);
}
writel(S3C64XX_SDHCI_CONTROL4_DRIVE_9mA,
host->ioaddr + S3C64XX_SDHCI_CONTROL4);
ctrl = readl(host->ioaddr + S3C_SDHCI_CONTROL2);
ctrl |= (S3C64XX_SDHCI_CTRL2_ENSTAASYNCCLR |
S3C64XX_SDHCI_CTRL2_ENCMDCNFMSK |
S3C_SDHCI_CTRL2_ENFBCLKRX |
S3C_SDHCI_CTRL2_DFCNT_NONE |
S3C_SDHCI_CTRL2_ENCLKOUTHOLD);
writel(ctrl, host->ioaddr + S3C_SDHCI_CONTROL2);
ctrl = (S3C_SDHCI_CTRL3_FCSEL1 | S3C_SDHCI_CTRL3_FCSEL0);
if (clock < 25 * 1000000)
ctrl |= (S3C_SDHCI_CTRL3_FCSEL3 | S3C_SDHCI_CTRL3_FCSEL2);
writel(ctrl, host->ioaddr + S3C_SDHCI_CONTROL3);
}
static unsigned int sdhci_s3c_get_min_clock(struct sdhci_host *host)
{
struct sdhci_s3c *ourhost = to_s3c(host);
unsigned int delta, min = UINT_MAX;
int src;
for (src = 0; src < MAX_BUS_CLK; src++) {
delta = sdhci_s3c_consider_clock(ourhost, src, 0);
if (delta == UINT_MAX)
continue;
if (-delta < min)
min = -delta;
}
return min;
}
static unsigned int sdhci_cmu_get_max_clock(struct sdhci_host *host)
{
struct sdhci_s3c *ourhost = to_s3c(host);
return clk_round_rate(ourhost->clk_bus[ourhost->cur_clk], UINT_MAX);
}
static unsigned int sdhci_cmu_get_min_clock(struct sdhci_host *host)
{
struct sdhci_s3c *ourhost = to_s3c(host);
return clk_round_rate(ourhost->clk_bus[ourhost->cur_clk], 400000);
}
static void sdhci_cmu_set_clock(struct sdhci_host *host, unsigned int clock)
{
struct sdhci_s3c *ourhost = to_s3c(host);
struct device *dev = &ourhost->pdev->dev;
unsigned long timeout;
u16 clk = 0;
if (clock == 0)
return;
sdhci_s3c_set_clock(host, clock);
clk_set_rate(ourhost->clk_bus[ourhost->cur_clk], clock);
host->clock = clock;
clk = SDHCI_CLOCK_INT_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
timeout = 20;
while (!((clk = sdhci_readw(host, SDHCI_CLOCK_CONTROL))
& SDHCI_CLOCK_INT_STABLE)) {
if (timeout == 0) {
dev_err(dev, "%s: Internal clock never stabilised.\n",
mmc_hostname(host->mmc));
return;
}
timeout--;
mdelay(1);
}
clk |= SDHCI_CLOCK_CARD_EN;
sdhci_writew(host, clk, SDHCI_CLOCK_CONTROL);
}
static int sdhci_s3c_platform_bus_width(struct sdhci_host *host, int width)
{
u8 ctrl;
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
switch (width) {
case MMC_BUS_WIDTH_8:
ctrl |= SDHCI_CTRL_8BITBUS;
ctrl &= ~SDHCI_CTRL_4BITBUS;
break;
case MMC_BUS_WIDTH_4:
ctrl |= SDHCI_CTRL_4BITBUS;
ctrl &= ~SDHCI_CTRL_8BITBUS;
break;
default:
ctrl &= ~SDHCI_CTRL_4BITBUS;
ctrl &= ~SDHCI_CTRL_8BITBUS;
break;
}
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
return 0;
}
static void sdhci_s3c_notify_change(struct platform_device *dev, int state)
{
struct sdhci_host *host = platform_get_drvdata(dev);
#ifdef CONFIG_PM_RUNTIME
struct sdhci_s3c *sc = sdhci_priv(host);
#endif
unsigned long flags;
if (host) {
spin_lock_irqsave(&host->lock, flags);
if (state) {
dev_dbg(&dev->dev, "card inserted.\n");
#ifdef CONFIG_PM_RUNTIME
clk_prepare_enable(sc->clk_io);
#endif
host->flags &= ~SDHCI_DEVICE_DEAD;
host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;
} else {
dev_dbg(&dev->dev, "card removed.\n");
host->flags |= SDHCI_DEVICE_DEAD;
host->quirks &= ~SDHCI_QUIRK_BROKEN_CARD_DETECTION;
#ifdef CONFIG_PM_RUNTIME
clk_disable_unprepare(sc->clk_io);
#endif
}
tasklet_schedule(&host->card_tasklet);
spin_unlock_irqrestore(&host->lock, flags);
}
}
static irqreturn_t sdhci_s3c_gpio_card_detect_thread(int irq, void *dev_id)
{
struct sdhci_s3c *sc = dev_id;
int status = gpio_get_value(sc->ext_cd_gpio);
if (sc->pdata->ext_cd_gpio_invert)
status = !status;
sdhci_s3c_notify_change(sc->pdev, status);
return IRQ_HANDLED;
}
static void sdhci_s3c_setup_card_detect_gpio(struct sdhci_s3c *sc)
{
struct s3c_sdhci_platdata *pdata = sc->pdata;
struct device *dev = &sc->pdev->dev;
if (devm_gpio_request(dev, pdata->ext_cd_gpio, "SDHCI EXT CD") == 0) {
sc->ext_cd_gpio = pdata->ext_cd_gpio;
sc->ext_cd_irq = gpio_to_irq(pdata->ext_cd_gpio);
if (sc->ext_cd_irq &&
request_threaded_irq(sc->ext_cd_irq, NULL,
sdhci_s3c_gpio_card_detect_thread,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING |
IRQF_ONESHOT,
dev_name(dev), sc) == 0) {
int status = gpio_get_value(sc->ext_cd_gpio);
if (pdata->ext_cd_gpio_invert)
status = !status;
sdhci_s3c_notify_change(sc->pdev, status);
} else {
dev_warn(dev, "cannot request irq for card detect\n");
sc->ext_cd_irq = 0;
}
} else {
dev_err(dev, "cannot request gpio for card detect\n");
}
}
static int sdhci_s3c_parse_dt(struct device *dev,
struct sdhci_host *host, struct s3c_sdhci_platdata *pdata)
{
struct device_node *node = dev->of_node;
struct sdhci_s3c *ourhost = to_s3c(host);
u32 max_width;
int gpio, cnt, ret;
if (of_property_read_u32(node, "bus-width", &max_width))
max_width = 1;
pdata->max_width = max_width;
ourhost->gpios = devm_kzalloc(dev, NUM_GPIOS(pdata->max_width) *
sizeof(int), GFP_KERNEL);
if (!ourhost->gpios)
return -ENOMEM;
if (of_get_property(node, "broken-cd", NULL)) {
pdata->cd_type = S3C_SDHCI_CD_NONE;
goto setup_bus;
}
if (of_get_property(node, "non-removable", NULL)) {
pdata->cd_type = S3C_SDHCI_CD_PERMANENT;
goto setup_bus;
}
gpio = of_get_named_gpio(node, "cd-gpios", 0);
if (gpio_is_valid(gpio)) {
pdata->cd_type = S3C_SDHCI_CD_GPIO;
goto found_cd;
} else if (gpio != -ENOENT) {
dev_err(dev, "invalid card detect gpio specified\n");
return -EINVAL;
}
gpio = of_get_named_gpio(node, "samsung,cd-pinmux-gpio", 0);
if (gpio_is_valid(gpio)) {
pdata->cd_type = S3C_SDHCI_CD_INTERNAL;
goto found_cd;
} else if (gpio != -ENOENT) {
dev_err(dev, "invalid card detect gpio specified\n");
return -EINVAL;
}
pdata->cd_type = S3C_SDHCI_CD_INTERNAL;
goto setup_bus;
found_cd:
if (pdata->cd_type == S3C_SDHCI_CD_GPIO) {
pdata->ext_cd_gpio = gpio;
ourhost->ext_cd_gpio = -1;
if (of_get_property(node, "cd-inverted", NULL))
pdata->ext_cd_gpio_invert = 1;
} else if (pdata->cd_type == S3C_SDHCI_CD_INTERNAL) {
ret = devm_gpio_request(dev, gpio, "sdhci-cd");
if (ret) {
dev_err(dev, "card detect gpio request failed\n");
return -EINVAL;
}
ourhost->ext_cd_gpio = gpio;
}
setup_bus:
if (!IS_ERR(ourhost->pctrl))
return 0;
for (cnt = 0; cnt < NUM_GPIOS(pdata->max_width); cnt++) {
gpio = of_get_gpio(node, cnt);
if (!gpio_is_valid(gpio)) {
dev_err(dev, "invalid gpio[%d]\n", cnt);
return -EINVAL;
}
ourhost->gpios[cnt] = gpio;
}
for (cnt = 0; cnt < NUM_GPIOS(pdata->max_width); cnt++) {
ret = devm_gpio_request(dev, ourhost->gpios[cnt], "sdhci-gpio");
if (ret) {
dev_err(dev, "gpio[%d] request failed\n", cnt);
return -EINVAL;
}
}
return 0;
}
static int sdhci_s3c_parse_dt(struct device *dev,
struct sdhci_host *host, struct s3c_sdhci_platdata *pdata)
{
return -EINVAL;
}
static inline struct sdhci_s3c_drv_data *sdhci_s3c_get_driver_data(
struct platform_device *pdev)
{
#ifdef CONFIG_OF
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(sdhci_s3c_dt_match, pdev->dev.of_node);
return (struct sdhci_s3c_drv_data *)match->data;
}
#endif
return (struct sdhci_s3c_drv_data *)
platform_get_device_id(pdev)->driver_data;
}
static int sdhci_s3c_probe(struct platform_device *pdev)
{
struct s3c_sdhci_platdata *pdata;
struct sdhci_s3c_drv_data *drv_data;
struct device *dev = &pdev->dev;
struct sdhci_host *host;
struct sdhci_s3c *sc;
struct resource *res;
int ret, irq, ptr, clks;
if (!pdev->dev.platform_data && !pdev->dev.of_node) {
dev_err(dev, "no device data specified\n");
return -ENOENT;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "no irq specified\n");
return irq;
}
host = sdhci_alloc_host(dev, sizeof(struct sdhci_s3c));
if (IS_ERR(host)) {
dev_err(dev, "sdhci_alloc_host() failed\n");
return PTR_ERR(host);
}
sc = sdhci_priv(host);
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
ret = -ENOMEM;
goto err_pdata_io_clk;
}
sc->pctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (pdev->dev.of_node) {
ret = sdhci_s3c_parse_dt(&pdev->dev, host, pdata);
if (ret)
goto err_pdata_io_clk;
} else {
memcpy(pdata, pdev->dev.platform_data, sizeof(*pdata));
sc->ext_cd_gpio = -1;
}
drv_data = sdhci_s3c_get_driver_data(pdev);
sc->host = host;
sc->pdev = pdev;
sc->pdata = pdata;
platform_set_drvdata(pdev, host);
sc->clk_io = clk_get(dev, "hsmmc");
if (IS_ERR(sc->clk_io)) {
dev_err(dev, "failed to get io clock\n");
ret = PTR_ERR(sc->clk_io);
goto err_pdata_io_clk;
}
clk_prepare_enable(sc->clk_io);
for (clks = 0, ptr = 0; ptr < MAX_BUS_CLK; ptr++) {
struct clk *clk;
char name[14];
snprintf(name, 14, "mmc_busclk.%d", ptr);
clk = clk_get(dev, name);
if (IS_ERR(clk))
continue;
clks++;
sc->clk_bus[ptr] = clk;
sc->cur_clk = ptr;
dev_info(dev, "clock source %d: %s (%ld Hz)\n",
ptr, name, clk_get_rate(clk));
}
if (clks == 0) {
dev_err(dev, "failed to find any bus clocks\n");
ret = -ENOENT;
goto err_no_busclks;
}
#ifndef CONFIG_PM_RUNTIME
clk_prepare_enable(sc->clk_bus[sc->cur_clk]);
#endif
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
host->ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(host->ioaddr)) {
ret = PTR_ERR(host->ioaddr);
goto err_req_regs;
}
if (pdata->cfg_gpio)
pdata->cfg_gpio(pdev, pdata->max_width);
host->hw_name = "samsung-hsmmc";
host->ops = &sdhci_s3c_ops;
host->quirks = 0;
host->irq = irq;
host->quirks |= SDHCI_QUIRK_NO_ENDATTR_IN_NOPDESC;
host->quirks |= SDHCI_QUIRK_NO_HISPD_BIT;
if (drv_data)
host->quirks |= drv_data->sdhci_quirks;
#ifndef CONFIG_MMC_SDHCI_S3C_DMA
host->quirks |= SDHCI_QUIRK_BROKEN_DMA;
#endif
host->quirks |= SDHCI_QUIRK_NO_BUSY_IRQ;
host->quirks |= SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;
host->quirks |= SDHCI_QUIRK_BROKEN_ADMA_ZEROLEN_DESC;
if (pdata->cd_type == S3C_SDHCI_CD_NONE ||
pdata->cd_type == S3C_SDHCI_CD_PERMANENT)
host->quirks |= SDHCI_QUIRK_BROKEN_CARD_DETECTION;
if (pdata->cd_type == S3C_SDHCI_CD_PERMANENT)
host->mmc->caps = MMC_CAP_NONREMOVABLE;
switch (pdata->max_width) {
case 8:
host->mmc->caps |= MMC_CAP_8_BIT_DATA;
case 4:
host->mmc->caps |= MMC_CAP_4_BIT_DATA;
break;
}
if (pdata->pm_caps)
host->mmc->pm_caps |= pdata->pm_caps;
host->quirks |= (SDHCI_QUIRK_32BIT_DMA_ADDR |
SDHCI_QUIRK_32BIT_DMA_SIZE);
host->quirks |= SDHCI_QUIRK_DATA_TIMEOUT_USES_SDCLK;
if (host->quirks & SDHCI_QUIRK_NONSTANDARD_CLOCK) {
sdhci_s3c_ops.set_clock = sdhci_cmu_set_clock;
sdhci_s3c_ops.get_min_clock = sdhci_cmu_get_min_clock;
sdhci_s3c_ops.get_max_clock = sdhci_cmu_get_max_clock;
}
if (pdata->host_caps)
host->mmc->caps |= pdata->host_caps;
if (pdata->host_caps2)
host->mmc->caps2 |= pdata->host_caps2;
pm_runtime_enable(&pdev->dev);
pm_runtime_set_autosuspend_delay(&pdev->dev, 50);
pm_runtime_use_autosuspend(&pdev->dev);
pm_suspend_ignore_children(&pdev->dev, 1);
ret = sdhci_add_host(host);
if (ret) {
dev_err(dev, "sdhci_add_host() failed\n");
pm_runtime_forbid(&pdev->dev);
pm_runtime_get_noresume(&pdev->dev);
goto err_req_regs;
}
if (pdata->cd_type == S3C_SDHCI_CD_EXTERNAL && pdata->ext_cd_init)
pdata->ext_cd_init(&sdhci_s3c_notify_change);
if (pdata->cd_type == S3C_SDHCI_CD_GPIO &&
gpio_is_valid(pdata->ext_cd_gpio))
sdhci_s3c_setup_card_detect_gpio(sc);
#ifdef CONFIG_PM_RUNTIME
if (pdata->cd_type != S3C_SDHCI_CD_INTERNAL)
clk_disable_unprepare(sc->clk_io);
#endif
return 0;
err_req_regs:
#ifndef CONFIG_PM_RUNTIME
clk_disable_unprepare(sc->clk_bus[sc->cur_clk]);
#endif
for (ptr = 0; ptr < MAX_BUS_CLK; ptr++) {
if (sc->clk_bus[ptr]) {
clk_put(sc->clk_bus[ptr]);
}
}
err_no_busclks:
clk_disable_unprepare(sc->clk_io);
clk_put(sc->clk_io);
err_pdata_io_clk:
sdhci_free_host(host);
return ret;
}
static int sdhci_s3c_remove(struct platform_device *pdev)
{
struct sdhci_host *host = platform_get_drvdata(pdev);
struct sdhci_s3c *sc = sdhci_priv(host);
struct s3c_sdhci_platdata *pdata = sc->pdata;
int ptr;
if (pdata->cd_type == S3C_SDHCI_CD_EXTERNAL && pdata->ext_cd_cleanup)
pdata->ext_cd_cleanup(&sdhci_s3c_notify_change);
if (sc->ext_cd_irq)
free_irq(sc->ext_cd_irq, sc);
#ifdef CONFIG_PM_RUNTIME
if (pdata->cd_type != S3C_SDHCI_CD_INTERNAL)
clk_prepare_enable(sc->clk_io);
#endif
sdhci_remove_host(host, 1);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_disable(&pdev->dev);
#ifndef CONFIG_PM_RUNTIME
clk_disable_unprepare(sc->clk_bus[sc->cur_clk]);
#endif
for (ptr = 0; ptr < MAX_BUS_CLK; ptr++) {
if (sc->clk_bus[ptr]) {
clk_put(sc->clk_bus[ptr]);
}
}
clk_disable_unprepare(sc->clk_io);
clk_put(sc->clk_io);
sdhci_free_host(host);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int sdhci_s3c_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
return sdhci_suspend_host(host);
}
static int sdhci_s3c_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
return sdhci_resume_host(host);
}
static int sdhci_s3c_runtime_suspend(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_s3c *ourhost = to_s3c(host);
struct clk *busclk = ourhost->clk_io;
int ret;
ret = sdhci_runtime_suspend_host(host);
clk_disable_unprepare(ourhost->clk_bus[ourhost->cur_clk]);
clk_disable_unprepare(busclk);
return ret;
}
static int sdhci_s3c_runtime_resume(struct device *dev)
{
struct sdhci_host *host = dev_get_drvdata(dev);
struct sdhci_s3c *ourhost = to_s3c(host);
struct clk *busclk = ourhost->clk_io;
int ret;
clk_prepare_enable(busclk);
clk_prepare_enable(ourhost->clk_bus[ourhost->cur_clk]);
ret = sdhci_runtime_resume_host(host);
return ret;
}
