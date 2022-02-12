static int __init iop3xx_pmu_init(void)
{
platform_device_register(&pmu_device);
return 0;
}
