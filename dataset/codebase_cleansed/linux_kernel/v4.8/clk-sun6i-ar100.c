static void sun6i_get_ar100_factors(struct factors_request *req)
{
unsigned long div;
int shift;
if (req->rate > req->parent_rate)
req->rate = req->parent_rate;
div = DIV_ROUND_UP(req->parent_rate, req->rate);
if (div < 32)
shift = 0;
else if (div >> 1 < 32)
shift = 1;
else if (div >> 2 < 32)
shift = 2;
else
shift = 3;
div >>= shift;
if (div > 32)
div = 32;
req->rate = (req->parent_rate >> shift) / div;
req->m = div - 1;
req->p = shift;
}
static int sun6i_a31_ar100_clk_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *r;
void __iomem *reg;
struct clk *clk;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(reg))
return PTR_ERR(reg);
clk = sunxi_factors_register(np, &sun6i_ar100_data, &sun6i_ar100_lock,
reg);
if (!clk)
return -ENOMEM;
platform_set_drvdata(pdev, clk);
return 0;
}
