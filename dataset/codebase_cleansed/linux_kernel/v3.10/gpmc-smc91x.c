static int smc91c96_gpmc_retime(void)
{
struct gpmc_timings t;
struct gpmc_device_timings dev_t;
const int t3 = 10;
const int t4_r = 20;
const int t4_w = 5;
const int t5 = 25;
const int t6 = 15;
const int t7 = 5;
const int t8 = 5;
const int t20 = 185;
if (gpmc_cfg->flags & GPMC_MUX_ADD_DATA)
return 0;
memset(&dev_t, 0, sizeof(dev_t));
dev_t.t_oeasu = t3 * 1000;
dev_t.t_oe = t5 * 1000;
dev_t.t_cez_r = t4_r * 1000;
dev_t.t_oez = t6 * 1000;
dev_t.t_rd_cycle = (t20 - t3) * 1000;
dev_t.t_weasu = t3 * 1000;
dev_t.t_wpl = t7 * 1000;
dev_t.t_wph = t8 * 1000;
dev_t.t_cez_w = t4_w * 1000;
dev_t.t_wr_cycle = (t20 - t3) * 1000;
gpmc_calc_timings(&t, &smc91x_settings, &dev_t);
return gpmc_cs_set_timings(gpmc_cfg->cs, &t);
}
void __init gpmc_smc91x_init(struct omap_smc91x_platform_data *board_data)
{
unsigned long cs_mem_base;
int ret;
gpmc_cfg = board_data;
if (gpmc_cfg->flags & GPMC_TIMINGS_SMC91C96)
gpmc_cfg->retime = smc91c96_gpmc_retime;
if (gpmc_cs_request(gpmc_cfg->cs, SZ_16M, &cs_mem_base) < 0) {
printk(KERN_ERR "Failed to request GPMC mem for smc91x\n");
return;
}
gpmc_smc91x_resources[0].start = cs_mem_base + 0x300;
gpmc_smc91x_resources[0].end = cs_mem_base + 0x30f;
gpmc_smc91x_resources[1].flags |= (gpmc_cfg->flags & IRQF_TRIGGER_MASK);
if (gpmc_cfg->flags & GPMC_MUX_ADD_DATA)
smc91x_settings.mux_add_data = GPMC_MUX_AD;
if (gpmc_cfg->flags & GPMC_READ_MON)
smc91x_settings.wait_on_read = true;
if (gpmc_cfg->flags & GPMC_WRITE_MON)
smc91x_settings.wait_on_write = true;
if (gpmc_cfg->wait_pin)
smc91x_settings.wait_pin = gpmc_cfg->wait_pin;
ret = gpmc_cs_program_settings(gpmc_cfg->cs, &smc91x_settings);
if (ret < 0)
goto free1;
if (gpmc_cfg->retime) {
ret = gpmc_cfg->retime();
if (ret != 0)
goto free1;
}
if (gpio_request_one(gpmc_cfg->gpio_irq, GPIOF_IN, "SMC91X irq") < 0)
goto free1;
gpmc_smc91x_resources[1].start = gpio_to_irq(gpmc_cfg->gpio_irq);
if (gpmc_cfg->gpio_pwrdwn) {
ret = gpio_request_one(gpmc_cfg->gpio_pwrdwn,
GPIOF_OUT_INIT_LOW, "SMC91X powerdown");
if (ret)
goto free2;
}
if (gpmc_cfg->gpio_reset) {
ret = gpio_request_one(gpmc_cfg->gpio_reset,
GPIOF_OUT_INIT_LOW, "SMC91X reset");
if (ret)
goto free3;
gpio_set_value(gpmc_cfg->gpio_reset, 1);
msleep(100);
gpio_set_value(gpmc_cfg->gpio_reset, 0);
}
if (platform_device_register(&gpmc_smc91x_device) < 0) {
printk(KERN_ERR "Unable to register smc91x device\n");
gpio_free(gpmc_cfg->gpio_reset);
goto free3;
}
return;
free3:
if (gpmc_cfg->gpio_pwrdwn)
gpio_free(gpmc_cfg->gpio_pwrdwn);
free2:
gpio_free(gpmc_cfg->gpio_irq);
free1:
gpmc_cs_free(gpmc_cfg->cs);
printk(KERN_ERR "Could not initialize smc91x\n");
}
