static int kirkwood_enter_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv,
int index)
{
writel(0x7, ddr_operation_base);
cpu_do_idle();
return index;
}
static int kirkwood_cpuidle_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL)
return -EINVAL;
ddr_operation_base = devm_request_and_ioremap(&pdev->dev, res);
if (!ddr_operation_base)
return -EADDRNOTAVAIL;
device = &per_cpu(kirkwood_cpuidle_device, smp_processor_id());
device->state_count = KIRKWOOD_MAX_STATES;
cpuidle_register_driver(&kirkwood_idle_driver);
if (cpuidle_register_device(device)) {
pr_err("kirkwood_init_cpuidle: Failed registering\n");
return -EIO;
}
return 0;
}
int kirkwood_cpuidle_remove(struct platform_device *pdev)
{
cpuidle_unregister_device(device);
cpuidle_unregister_driver(&kirkwood_idle_driver);
return 0;
}
