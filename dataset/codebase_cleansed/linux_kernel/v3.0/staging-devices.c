static int msm_fb_detect_panel(const char *name)
{
int ret = -EPERM;
if (machine_is_qsd8x50_ffa() || machine_is_qsd8x50a_ffa()) {
if (!strncmp(name, "mddi_toshiba_wvga_pt", 20))
ret = 0;
else
ret = -ENODEV;
} else if ((machine_is_qsd8x50_surf() || machine_is_qsd8x50a_surf())
&& !strcmp(name, "lcdc_external"))
ret = 0;
else if (machine_is_qsd8x50a_st1_5()) {
if (!strcmp(name, "lcdc_st15") ||
!strcmp(name, "hdmi_sii9022"))
ret = 0;
else
ret = -ENODEV;
}
return ret;
}
static int msm_fb_allow_set_offset(void)
{
return (machine_is_qsd8x50_st1() ||
machine_is_qsd8x50a_st1_5()) ? 1 : 0;
}
static void __init qsd8x50_allocate_memory_regions(void)
{
void *addr;
unsigned long size;
if (machine_is_qsd8x50a_st1_5())
size = MSM_FB_SIZE_ST15;
else
size = MSM_FB_SIZE;
addr = alloc_bootmem(size);
if (!addr)
printk("Failed to allocate bootmem for framebuffer\n");
msm_fb_resources[0].start = __pa(addr);
msm_fb_resources[0].end = msm_fb_resources[0].start + size - 1;
pr_info("using %lu bytes of SMI at %lx physical for fb\n",
size, (unsigned long)addr);
}
static int msm_fb_lcdc_gpio_config(int on)
{
if (machine_is_qsd8x50_st1()) {
if (on) {
gpio_set_value(32, 1);
mdelay(100);
gpio_set_value(20, 1);
gpio_set_value(17, 1);
gpio_set_value(19, 1);
} else {
gpio_set_value(17, 0);
gpio_set_value(19, 0);
gpio_set_value(20, 0);
mdelay(100);
gpio_set_value(32, 0);
}
} else if (machine_is_qsd8x50a_st1_5()) {
if (on) {
gpio_set_value(17, 1);
gpio_set_value(19, 1);
gpio_set_value(20, 1);
gpio_set_value(22, 0);
gpio_set_value(32, 1);
gpio_set_value(155, 1);
gpio_set_value(22, 1);
} else {
gpio_set_value(17, 0);
gpio_set_value(19, 0);
gpio_set_value(22, 0);
gpio_set_value(32, 0);
gpio_set_value(155, 0);
}
}
return 0;
}
static void __init msm_register_device(struct platform_device *pdev, void *data)
{
int ret;
pdev->dev.platform_data = data;
ret = platform_device_register(pdev);
if (ret)
dev_err(&pdev->dev,
"%s: platform_device_register() failed = %d\n",
__func__, ret);
}
void __init msm_fb_register_device(char *name, void *data)
{
if (!strncmp(name, "mdp", 3))
msm_register_device(&msm_mdp_device, data);
if (!strncmp(name, "lcdc", 4))
msm_register_device(&msm_lcdc_device, data);
}
static void __init msm_fb_add_devices(void)
{
int rc;
msm_fb_register_device("mdp", &mdp_pdata);
if (machine_is_qsd8x50a_st1_5()) {
rc = msm_gpios_request_enable(
msm_fb_st15_gpio_config_data,
ARRAY_SIZE(msm_fb_st15_gpio_config_data));
if (rc) {
printk(KERN_ERR "%s: unable to init lcdc gpios\n",
__func__);
return;
}
msm_fb_register_device("lcdc", &lcdc_pdata);
} else
msm_fb_register_device("lcdc", 0);
}
int __init staging_init_pmem(void)
{
qsd8x50_allocate_memory_regions();
return 0;
}
int __init staging_init_devices(void)
{
platform_add_devices(devices, ARRAY_SIZE(devices));
msm_fb_add_devices();
return 0;
}
