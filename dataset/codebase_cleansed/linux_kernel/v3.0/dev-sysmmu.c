void sysmmu_clk_init(struct device *dev, sysmmu_ips ips)
{
sysmmu_clk[ips] = clk_get(dev, sysmmu_ips_name[ips]);
if (IS_ERR(sysmmu_clk[ips]))
sysmmu_clk[ips] = NULL;
else
clk_put(sysmmu_clk[ips]);
}
void sysmmu_clk_enable(sysmmu_ips ips)
{
if (sysmmu_clk[ips])
clk_enable(sysmmu_clk[ips]);
}
void sysmmu_clk_disable(sysmmu_ips ips)
{
if (sysmmu_clk[ips])
clk_disable(sysmmu_clk[ips]);
}
