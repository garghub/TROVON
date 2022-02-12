static void xgene_rng_expired_timer(unsigned long arg)
{
struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) arg;
disable_irq(ctx->irq);
ctx->failure_cnt = 0;
del_timer(&ctx->failure_timer);
enable_irq(ctx->irq);
}
static void xgene_rng_start_timer(struct xgene_rng_dev *ctx)
{
ctx->failure_timer.data = (unsigned long) ctx;
ctx->failure_timer.function = xgene_rng_expired_timer;
ctx->failure_timer.expires = jiffies + 120 * HZ;
add_timer(&ctx->failure_timer);
}
static void xgene_rng_init_fro(struct xgene_rng_dev *ctx, u32 fro_val)
{
writel(fro_val, ctx->csr_base + RNG_FRODETUNE);
writel(0x00000000, ctx->csr_base + RNG_ALARMMASK);
writel(0x00000000, ctx->csr_base + RNG_ALARMSTOP);
writel(0xFFFFFFFF, ctx->csr_base + RNG_FROENABLE);
}
static void xgene_rng_chk_overflow(struct xgene_rng_dev *ctx)
{
u32 val;
val = readl(ctx->csr_base + RNG_INTR_STS_ACK);
if (val & MONOBIT_FAIL_MASK)
dev_err(ctx->dev, "test monobit failure error 0x%08X\n", val);
if (val & POKER_FAIL_MASK)
dev_err(ctx->dev, "test poker failure error 0x%08X\n", val);
if (val & LONG_RUN_FAIL_MASK)
dev_err(ctx->dev, "test long run failure error 0x%08X\n", val);
if (val & RUN_FAIL_MASK)
dev_err(ctx->dev, "test run failure error 0x%08X\n", val);
if (val & NOISE_FAIL_MASK)
dev_err(ctx->dev, "noise failure error 0x%08X\n", val);
if (val & STUCK_OUT_MASK)
dev_err(ctx->dev, "stuck out failure error 0x%08X\n", val);
if (val & SHUTDOWN_OFLO_MASK) {
u32 frostopped;
if (++ctx->failure_cnt == 1) {
ctx->failure_ts = jiffies;
frostopped = readl(ctx->csr_base + RNG_ALARMSTOP);
xgene_rng_init_fro(ctx, frostopped);
xgene_rng_start_timer(ctx);
} else {
if (time_after(ctx->failure_ts + 60 * HZ, jiffies)) {
dev_err(ctx->dev,
"FRO shutdown failure error 0x%08X\n",
val);
} else {
ctx->failure_ts = jiffies;
ctx->failure_cnt = 1;
xgene_rng_start_timer(ctx);
}
frostopped = readl(ctx->csr_base + RNG_ALARMSTOP);
xgene_rng_init_fro(ctx, frostopped);
}
}
writel(val, ctx->csr_base + RNG_INTR_STS_ACK);
}
static irqreturn_t xgene_rng_irq_handler(int irq, void *id)
{
struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) id;
xgene_rng_chk_overflow(ctx);
return IRQ_HANDLED;
}
static int xgene_rng_data_present(struct hwrng *rng, int wait)
{
struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;
u32 i, val = 0;
for (i = 0; i < XGENE_RNG_RETRY_COUNT; i++) {
val = readl(ctx->csr_base + RNG_INTR_STS_ACK);
if ((val & READY_MASK) || !wait)
break;
udelay(XGENE_RNG_RETRY_INTERVAL);
}
return (val & READY_MASK);
}
static int xgene_rng_data_read(struct hwrng *rng, u32 *data)
{
struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;
int i;
for (i = 0; i < ctx->datum_size; i++)
data[i] = readl(ctx->csr_base + RNG_INOUT_0 + i * 4);
writel(READY_MASK, ctx->csr_base + RNG_INTR_STS_ACK);
return ctx->datum_size << 2;
}
static void xgene_rng_init_internal(struct xgene_rng_dev *ctx)
{
u32 val;
writel(0x00000000, ctx->csr_base + RNG_CONTROL);
val = MAX_REFILL_CYCLES_SET(0, 10);
val = MIN_REFILL_CYCLES_SET(val, 10);
writel(val, ctx->csr_base + RNG_CONFIG);
val = ALARM_THRESHOLD_SET(0, 0xFF);
writel(val, ctx->csr_base + RNG_ALARMCNT);
xgene_rng_init_fro(ctx, 0);
writel(MONOBIT_FAIL_MASK |
POKER_FAIL_MASK |
LONG_RUN_FAIL_MASK |
RUN_FAIL_MASK |
NOISE_FAIL_MASK |
STUCK_OUT_MASK |
SHUTDOWN_OFLO_MASK |
READY_MASK, ctx->csr_base + RNG_INTR_STS_ACK);
val = ENABLE_RNG_SET(0, 1);
val = MONOBIT_FAIL_MASK_SET(val, 1);
val = POKER_FAIL_MASK_SET(val, 1);
val = LONG_RUN_FAIL_MASK_SET(val, 1);
val = RUN_FAIL_MASK_SET(val, 1);
val = NOISE_FAIL_MASK_SET(val, 1);
val = STUCK_OUT_MASK_SET(val, 1);
val = SHUTDOWN_OFLO_MASK_SET(val, 1);
writel(val, ctx->csr_base + RNG_CONTROL);
}
static int xgene_rng_init(struct hwrng *rng)
{
struct xgene_rng_dev *ctx = (struct xgene_rng_dev *) rng->priv;
ctx->failure_cnt = 0;
init_timer(&ctx->failure_timer);
ctx->revision = readl(ctx->csr_base + RNG_EIP_REV);
dev_dbg(ctx->dev, "Rev %d.%d.%d\n",
MAJOR_HW_REV_RD(ctx->revision),
MINOR_HW_REV_RD(ctx->revision),
HW_PATCH_LEVEL_RD(ctx->revision));
dev_dbg(ctx->dev, "Options 0x%08X",
readl(ctx->csr_base + RNG_OPTIONS));
xgene_rng_init_internal(ctx);
ctx->datum_size = RNG_MAX_DATUM;
return 0;
}
static int xgene_rng_probe(struct platform_device *pdev)
{
struct resource *res;
struct xgene_rng_dev *ctx;
int rc = 0;
ctx = devm_kzalloc(&pdev->dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = &pdev->dev;
platform_set_drvdata(pdev, ctx);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->csr_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ctx->csr_base))
return PTR_ERR(ctx->csr_base);
ctx->irq = platform_get_irq(pdev, 0);
if (ctx->irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
return ctx->irq;
}
dev_dbg(&pdev->dev, "APM X-Gene RNG BASE %p ALARM IRQ %d",
ctx->csr_base, ctx->irq);
rc = devm_request_irq(&pdev->dev, ctx->irq, xgene_rng_irq_handler, 0,
dev_name(&pdev->dev), ctx);
if (rc) {
dev_err(&pdev->dev, "Could not request RNG alarm IRQ\n");
return rc;
}
ctx->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(ctx->clk)) {
dev_warn(&pdev->dev, "Couldn't get the clock for RNG\n");
} else {
rc = clk_prepare_enable(ctx->clk);
if (rc) {
dev_warn(&pdev->dev,
"clock prepare enable failed for RNG");
return rc;
}
}
xgene_rng_func.priv = (unsigned long) ctx;
rc = hwrng_register(&xgene_rng_func);
if (rc) {
dev_err(&pdev->dev, "RNG registering failed error %d\n", rc);
if (!IS_ERR(ctx->clk))
clk_disable_unprepare(ctx->clk);
return rc;
}
rc = device_init_wakeup(&pdev->dev, 1);
if (rc) {
dev_err(&pdev->dev, "RNG device_init_wakeup failed error %d\n",
rc);
if (!IS_ERR(ctx->clk))
clk_disable_unprepare(ctx->clk);
hwrng_unregister(&xgene_rng_func);
return rc;
}
return 0;
}
static int xgene_rng_remove(struct platform_device *pdev)
{
struct xgene_rng_dev *ctx = platform_get_drvdata(pdev);
int rc;
rc = device_init_wakeup(&pdev->dev, 0);
if (rc)
dev_err(&pdev->dev, "RNG init wakeup failed error %d\n", rc);
if (!IS_ERR(ctx->clk))
clk_disable_unprepare(ctx->clk);
hwrng_unregister(&xgene_rng_func);
return rc;
}
