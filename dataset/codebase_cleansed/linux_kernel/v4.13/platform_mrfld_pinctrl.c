static int __init mrfld_pinctrl_init(void)
{
if (intel_mid_identify_cpu() == INTEL_MID_CPU_CHIP_TANGIER)
return platform_device_register(&mrfld_pinctrl_device);
return -ENODEV;
}
