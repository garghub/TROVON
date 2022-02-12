static int zynq_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
cpu_do_idle();
return index;
}
static int zynq_cpuidle_probe(struct platform_device *pdev)
{
pr_info("Xilinx Zynq CpuIdle Driver started\n");
return cpuidle_register(&zynq_idle_driver, NULL);
}
