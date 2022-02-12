void __init gpmc_smsc911x_init(struct omap_smsc911x_platform_data *board_data)
{
struct platform_device *pdev;
unsigned long cs_mem_base;
int ret;
gpmc_cfg = board_data;
if (gpmc_cs_request(gpmc_cfg->cs, SZ_16M, &cs_mem_base) < 0) {
pr_err("Failed to request GPMC mem region\n");
return;
}
gpmc_smsc911x_resources[0].start = cs_mem_base + 0x0;
gpmc_smsc911x_resources[0].end = cs_mem_base + 0xff;
if (gpio_request_one(gpmc_cfg->gpio_irq, GPIOF_IN, "smsc911x irq")) {
pr_err("Failed to request IRQ GPIO%d\n", gpmc_cfg->gpio_irq);
goto free1;
}
gpmc_smsc911x_resources[1].start = gpio_to_irq(gpmc_cfg->gpio_irq);
if (gpio_is_valid(gpmc_cfg->gpio_reset)) {
ret = gpio_request_one(gpmc_cfg->gpio_reset,
GPIOF_OUT_INIT_HIGH, "smsc911x reset");
if (ret) {
pr_err("Failed to request reset GPIO%d\n",
gpmc_cfg->gpio_reset);
goto free2;
}
gpio_set_value(gpmc_cfg->gpio_reset, 0);
msleep(100);
gpio_set_value(gpmc_cfg->gpio_reset, 1);
}
if (gpmc_cfg->flags)
gpmc_smsc911x_config.flags = gpmc_cfg->flags;
pdev = platform_device_register_resndata(NULL, "smsc911x", gpmc_cfg->id,
gpmc_smsc911x_resources, ARRAY_SIZE(gpmc_smsc911x_resources),
&gpmc_smsc911x_config, sizeof(gpmc_smsc911x_config));
if (!pdev) {
pr_err("Unable to register platform device\n");
gpio_free(gpmc_cfg->gpio_reset);
goto free2;
}
return;
free2:
gpio_free(gpmc_cfg->gpio_irq);
free1:
gpmc_cs_free(gpmc_cfg->cs);
pr_err("Could not initialize smsc911x device\n");
}
