static void *msic_audio_platform_data(void *info)
{
struct platform_device *pdev;
pdev = platform_device_register_simple("sst-platform", -1, NULL, 0);
if (IS_ERR(pdev)) {
pr_err("failed to create audio platform device\n");
return NULL;
}
return msic_generic_platform_data(info, INTEL_MSIC_BLOCK_AUDIO);
}
