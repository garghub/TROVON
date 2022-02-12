static int st_rng_read(struct hwrng *rng, void *data, size_t max, bool wait)
{
struct st_rng_data *ddata = (struct st_rng_data *)rng->priv;
u32 status;
int i;
if (max < sizeof(u16))
return -EINVAL;
for (i = 0; i < ST_RNG_FILL_FIFO_TIMEOUT; i++) {
status = readl_relaxed(ddata->base + ST_RNG_STATUS_REG);
if (status & ST_RNG_STATUS_FIFO_FULL)
break;
udelay(1);
}
if (i == ST_RNG_FILL_FIFO_TIMEOUT)
return 0;
for (i = 0; i < ST_RNG_FIFO_SIZE && i < max; i += 2)
*(u16 *)(data + i) =
readl_relaxed(ddata->base + ST_RNG_DATA_REG);
return i;
}
static int st_rng_probe(struct platform_device *pdev)
{
struct st_rng_data *ddata;
struct resource *res;
struct clk *clk;
void __iomem *base;
int ret;
ddata = devm_kzalloc(&pdev->dev, sizeof(*ddata), GFP_KERNEL);
if (!ddata)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(clk);
if (ret)
return ret;
ddata->ops.priv = (unsigned long)ddata;
ddata->ops.read = st_rng_read;
ddata->ops.name = pdev->name;
ddata->base = base;
ddata->clk = clk;
dev_set_drvdata(&pdev->dev, ddata);
ret = hwrng_register(&ddata->ops);
if (ret) {
dev_err(&pdev->dev, "Failed to register HW RNG\n");
return ret;
}
dev_info(&pdev->dev, "Successfully registered HW RNG\n");
return 0;
}
static int st_rng_remove(struct platform_device *pdev)
{
struct st_rng_data *ddata = dev_get_drvdata(&pdev->dev);
hwrng_unregister(&ddata->ops);
clk_disable_unprepare(ddata->clk);
return 0;
}
