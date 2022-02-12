static int __init s5p_pmu_init(void)
{
platform_device_register(&s5p_device_pmu);
return 0;
}
