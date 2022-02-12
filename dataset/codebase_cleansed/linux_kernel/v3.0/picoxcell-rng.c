static inline u32 picoxcell_trng_read_csr(void)
{
return __raw_readl(rng_base + CSR_REG_OFFSET);
}
static inline bool picoxcell_trng_is_empty(void)
{
return picoxcell_trng_read_csr() & CSR_OUT_EMPTY_MASK;
}
static void picoxcell_trng_start(void)
{
__raw_writel(0, rng_base + TAI_REG_OFFSET);
__raw_writel(0, rng_base + CSR_REG_OFFSET);
}
static void picoxcell_trng_reset(void)
{
__raw_writel(TRNG_BLOCK_RESET_MASK, rng_base + CSR_REG_OFFSET);
__raw_writel(TRNG_BLOCK_RESET_MASK, rng_base + TAI_REG_OFFSET);
picoxcell_trng_start();
}
static int picoxcell_trng_read(struct hwrng *rng, void *buf, size_t max,
bool wait)
{
int i;
for (i = 0; i < PICO_TRNG_TIMEOUT && picoxcell_trng_is_empty(); ++i) {
if (!wait)
return 0;
udelay(1);
}
if (picoxcell_trng_read_csr() & CSR_FAULT_MASK) {
dev_err(rng_dev, "fault detected, resetting TRNG\n");
picoxcell_trng_reset();
return -EIO;
}
if (i == PICO_TRNG_TIMEOUT)
return 0;
*(u32 *)buf = __raw_readl(rng_base + DATA_REG_OFFSET);
return sizeof(u32);
}
static int picoxcell_trng_probe(struct platform_device *pdev)
{
int ret;
struct resource *mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_warn(&pdev->dev, "no memory resource\n");
return -ENOMEM;
}
if (!devm_request_mem_region(&pdev->dev, mem->start, resource_size(mem),
"picoxcell_trng")) {
dev_warn(&pdev->dev, "unable to request io mem\n");
return -EBUSY;
}
rng_base = devm_ioremap(&pdev->dev, mem->start, resource_size(mem));
if (!rng_base) {
dev_warn(&pdev->dev, "unable to remap io mem\n");
return -ENOMEM;
}
rng_clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(rng_clk)) {
dev_warn(&pdev->dev, "no clk\n");
return PTR_ERR(rng_clk);
}
ret = clk_enable(rng_clk);
if (ret) {
dev_warn(&pdev->dev, "unable to enable clk\n");
goto err_enable;
}
picoxcell_trng_start();
ret = hwrng_register(&picoxcell_trng);
if (ret)
goto err_register;
rng_dev = &pdev->dev;
dev_info(&pdev->dev, "pixoxcell random number generator active\n");
return 0;
err_register:
clk_disable(rng_clk);
err_enable:
clk_put(rng_clk);
return ret;
}
static int __devexit picoxcell_trng_remove(struct platform_device *pdev)
{
hwrng_unregister(&picoxcell_trng);
clk_disable(rng_clk);
clk_put(rng_clk);
return 0;
}
static int picoxcell_trng_suspend(struct device *dev)
{
clk_disable(rng_clk);
return 0;
}
static int picoxcell_trng_resume(struct device *dev)
{
return clk_enable(rng_clk);
}
static int __init picoxcell_trng_init(void)
{
return platform_driver_register(&picoxcell_trng_driver);
}
static void __exit picoxcell_trng_exit(void)
{
platform_driver_unregister(&picoxcell_trng_driver);
}
