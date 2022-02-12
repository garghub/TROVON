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
rng_base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(rng_base))
return PTR_ERR(rng_base);
rng_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(rng_clk)) {
dev_warn(&pdev->dev, "no clk\n");
return PTR_ERR(rng_clk);
}
ret = clk_enable(rng_clk);
if (ret) {
dev_warn(&pdev->dev, "unable to enable clk\n");
return ret;
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
return ret;
}
static int picoxcell_trng_remove(struct platform_device *pdev)
{
hwrng_unregister(&picoxcell_trng);
clk_disable(rng_clk);
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
