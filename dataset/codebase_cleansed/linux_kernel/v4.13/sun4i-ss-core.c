static int sun4i_ss_probe(struct platform_device *pdev)
{
struct resource *res;
u32 v;
int err, i;
unsigned long cr;
const unsigned long cr_ahb = 24 * 1000 * 1000;
const unsigned long cr_mod = 150 * 1000 * 1000;
struct sun4i_ss_ctx *ss;
if (!pdev->dev.of_node)
return -ENODEV;
ss = devm_kzalloc(&pdev->dev, sizeof(*ss), GFP_KERNEL);
if (!ss)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ss->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ss->base)) {
dev_err(&pdev->dev, "Cannot request MMIO\n");
return PTR_ERR(ss->base);
}
ss->ssclk = devm_clk_get(&pdev->dev, "mod");
if (IS_ERR(ss->ssclk)) {
err = PTR_ERR(ss->ssclk);
dev_err(&pdev->dev, "Cannot get SS clock err=%d\n", err);
return err;
}
dev_dbg(&pdev->dev, "clock ss acquired\n");
ss->busclk = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(ss->busclk)) {
err = PTR_ERR(ss->busclk);
dev_err(&pdev->dev, "Cannot get AHB SS clock err=%d\n", err);
return err;
}
dev_dbg(&pdev->dev, "clock ahb_ss acquired\n");
ss->reset = devm_reset_control_get_optional(&pdev->dev, "ahb");
if (IS_ERR(ss->reset)) {
if (PTR_ERR(ss->reset) == -EPROBE_DEFER)
return PTR_ERR(ss->reset);
dev_info(&pdev->dev, "no reset control found\n");
ss->reset = NULL;
}
err = clk_prepare_enable(ss->busclk);
if (err) {
dev_err(&pdev->dev, "Cannot prepare_enable busclk\n");
return err;
}
err = clk_prepare_enable(ss->ssclk);
if (err) {
dev_err(&pdev->dev, "Cannot prepare_enable ssclk\n");
goto error_ssclk;
}
err = clk_set_rate(ss->ssclk, cr_mod);
if (err) {
dev_err(&pdev->dev, "Cannot set clock rate to ssclk\n");
goto error_clk;
}
if (ss->reset) {
err = reset_control_deassert(ss->reset);
if (err) {
dev_err(&pdev->dev, "Cannot deassert reset control\n");
goto error_clk;
}
}
cr = clk_get_rate(ss->busclk);
if (cr >= cr_ahb)
dev_dbg(&pdev->dev, "Clock bus %lu (%lu MHz) (must be >= %lu)\n",
cr, cr / 1000000, cr_ahb);
else
dev_warn(&pdev->dev, "Clock bus %lu (%lu MHz) (must be >= %lu)\n",
cr, cr / 1000000, cr_ahb);
cr = clk_get_rate(ss->ssclk);
if (cr <= cr_mod)
if (cr < cr_mod)
dev_warn(&pdev->dev, "Clock ss %lu (%lu MHz) (must be <= %lu)\n",
cr, cr / 1000000, cr_mod);
else
dev_dbg(&pdev->dev, "Clock ss %lu (%lu MHz) (must be <= %lu)\n",
cr, cr / 1000000, cr_mod);
else
dev_warn(&pdev->dev, "Clock ss is at %lu (%lu MHz) (must be <= %lu)\n",
cr, cr / 1000000, cr_mod);
writel(SS_ENABLED, ss->base + SS_CTL);
v = readl(ss->base + SS_CTL);
v >>= 16;
v &= 0x07;
dev_info(&pdev->dev, "Die ID %d\n", v);
writel(0, ss->base + SS_CTL);
ss->dev = &pdev->dev;
spin_lock_init(&ss->slock);
for (i = 0; i < ARRAY_SIZE(ss_algs); i++) {
ss_algs[i].ss = ss;
switch (ss_algs[i].type) {
case CRYPTO_ALG_TYPE_SKCIPHER:
err = crypto_register_skcipher(&ss_algs[i].alg.crypto);
if (err) {
dev_err(ss->dev, "Fail to register %s\n",
ss_algs[i].alg.crypto.base.cra_name);
goto error_alg;
}
break;
case CRYPTO_ALG_TYPE_AHASH:
err = crypto_register_ahash(&ss_algs[i].alg.hash);
if (err) {
dev_err(ss->dev, "Fail to register %s\n",
ss_algs[i].alg.hash.halg.base.cra_name);
goto error_alg;
}
break;
}
}
platform_set_drvdata(pdev, ss);
return 0;
error_alg:
i--;
for (; i >= 0; i--) {
switch (ss_algs[i].type) {
case CRYPTO_ALG_TYPE_SKCIPHER:
crypto_unregister_skcipher(&ss_algs[i].alg.crypto);
break;
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&ss_algs[i].alg.hash);
break;
}
}
if (ss->reset)
reset_control_assert(ss->reset);
error_clk:
clk_disable_unprepare(ss->ssclk);
error_ssclk:
clk_disable_unprepare(ss->busclk);
return err;
}
static int sun4i_ss_remove(struct platform_device *pdev)
{
int i;
struct sun4i_ss_ctx *ss = platform_get_drvdata(pdev);
for (i = 0; i < ARRAY_SIZE(ss_algs); i++) {
switch (ss_algs[i].type) {
case CRYPTO_ALG_TYPE_SKCIPHER:
crypto_unregister_skcipher(&ss_algs[i].alg.crypto);
break;
case CRYPTO_ALG_TYPE_AHASH:
crypto_unregister_ahash(&ss_algs[i].alg.hash);
break;
}
}
writel(0, ss->base + SS_CTL);
if (ss->reset)
reset_control_assert(ss->reset);
clk_disable_unprepare(ss->busclk);
clk_disable_unprepare(ss->ssclk);
return 0;
}
