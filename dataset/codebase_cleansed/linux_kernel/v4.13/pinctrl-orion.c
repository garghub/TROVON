static int orion_mpp_ctrl_get(struct mvebu_mpp_ctrl_data *data,
unsigned pid, unsigned long *config)
{
unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
if (pid < 16) {
unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
*config = (readl(mpp_base + off) >> shift) & MVEBU_MPP_MASK;
}
else {
*config = (readl(high_mpp_base) >> shift) & MVEBU_MPP_MASK;
}
return 0;
}
static int orion_mpp_ctrl_set(struct mvebu_mpp_ctrl_data *data,
unsigned pid, unsigned long config)
{
unsigned shift = (pid % MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
if (pid < 16) {
unsigned off = (pid / MVEBU_MPPS_PER_REG) * MVEBU_MPP_BITS;
u32 reg = readl(mpp_base + off) & ~(MVEBU_MPP_MASK << shift);
writel(reg | (config << shift), mpp_base + off);
}
else {
u32 reg = readl(high_mpp_base) & ~(MVEBU_MPP_MASK << shift);
writel(reg | (config << shift), high_mpp_base);
}
return 0;
}
static int orion_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match =
of_match_device(orion_pinctrl_of_match, &pdev->dev);
struct resource *res;
pdev->dev.platform_data = (void*)match->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mpp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mpp_base))
return PTR_ERR(mpp_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
high_mpp_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(high_mpp_base))
return PTR_ERR(high_mpp_base);
return mvebu_pinctrl_probe(pdev);
}
