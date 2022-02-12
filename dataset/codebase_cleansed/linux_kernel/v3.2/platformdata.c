void __init *s3c_set_platdata(void *pd, size_t pdsize,
struct platform_device *pdev)
{
void *npd;
if (!pd) {
printk(KERN_ERR "%s: no platform data supplied\n", pdev->name);
return NULL;
}
npd = kmemdup(pd, pdsize, GFP_KERNEL);
if (!npd) {
printk(KERN_ERR "%s: cannot clone platform data\n", pdev->name);
return NULL;
}
pdev->dev.platform_data = npd;
return npd;
}
void s3c_sdhci_set_platdata(struct s3c_sdhci_platdata *pd,
struct s3c_sdhci_platdata *set)
{
set->cd_type = pd->cd_type;
set->ext_cd_init = pd->ext_cd_init;
set->ext_cd_cleanup = pd->ext_cd_cleanup;
set->ext_cd_gpio = pd->ext_cd_gpio;
set->ext_cd_gpio_invert = pd->ext_cd_gpio_invert;
if (pd->max_width)
set->max_width = pd->max_width;
if (pd->cfg_gpio)
set->cfg_gpio = pd->cfg_gpio;
if (pd->host_caps)
set->host_caps |= pd->host_caps;
if (pd->clk_type)
set->clk_type = pd->clk_type;
}
