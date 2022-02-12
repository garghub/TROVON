static cycle_t nps_clksrc_read(struct clocksource *clksrc)
{
int cluster = raw_smp_processor_id() >> NPS_CLUSTER_OFFSET;
return (cycle_t)ioread32be(nps_msu_reg_low_addr[cluster]);
}
static int __init nps_setup_clocksource(struct device_node *node,
struct clk *clk)
{
int ret, cluster;
for (cluster = 0; cluster < NPS_CLUSTER_NUM; cluster++)
nps_msu_reg_low_addr[cluster] =
nps_host_reg((cluster << NPS_CLUSTER_OFFSET),
NPS_MSU_BLKID, NPS_MSU_TICK_LOW);
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("Couldn't enable parent clock\n");
return ret;
}
nps_timer_rate = clk_get_rate(clk);
ret = clocksource_mmio_init(nps_msu_reg_low_addr, "EZnps-tick",
nps_timer_rate, 301, 32, nps_clksrc_read);
if (ret) {
pr_err("Couldn't register clock source.\n");
clk_disable_unprepare(clk);
}
return ret;
}
static int __init nps_timer_init(struct device_node *node)
{
struct clk *clk;
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("Can't get timer clock.\n");
return PTR_ERR(clk);
}
return nps_setup_clocksource(node, clk);
}
