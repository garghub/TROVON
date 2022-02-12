static int tosa_mci_init(struct device *dev, irq_handler_t tosa_detect_int, void *data)
{
int err;
err = gpio_request(TOSA_GPIO_nSD_INT, "SD Int");
if (err) {
printk(KERN_ERR "tosa_mci_init: can't request SD_PWR gpio\n");
goto err_gpio_int;
}
err = gpio_direction_input(TOSA_GPIO_nSD_INT);
if (err)
goto err_gpio_int_dir;
return 0;
err_gpio_int_dir:
gpio_free(TOSA_GPIO_nSD_INT);
err_gpio_int:
return err;
}
static void tosa_mci_exit(struct device *dev, void *data)
{
gpio_free(TOSA_GPIO_nSD_INT);
}
static void tosa_irda_transceiver_mode(struct device *dev, int mode)
{
if (mode & IR_OFF) {
gpio_set_value(TOSA_GPIO_IR_POWERDWN, 0);
pxa2xx_transceiver_mode(dev, mode);
gpio_direction_output(TOSA_GPIO_IRDA_TX, 0);
} else {
pxa2xx_transceiver_mode(dev, mode);
gpio_set_value(TOSA_GPIO_IR_POWERDWN, 1);
}
}
static int tosa_irda_startup(struct device *dev)
{
int ret;
ret = gpio_request(TOSA_GPIO_IRDA_TX, "IrDA TX");
if (ret)
goto err_tx;
ret = gpio_direction_output(TOSA_GPIO_IRDA_TX, 0);
if (ret)
goto err_tx_dir;
ret = gpio_request(TOSA_GPIO_IR_POWERDWN, "IrDA powerdown");
if (ret)
goto err_pwr;
ret = gpio_direction_output(TOSA_GPIO_IR_POWERDWN, 0);
if (ret)
goto err_pwr_dir;
tosa_irda_transceiver_mode(dev, IR_SIRMODE | IR_OFF);
return 0;
err_pwr_dir:
gpio_free(TOSA_GPIO_IR_POWERDWN);
err_pwr:
err_tx_dir:
gpio_free(TOSA_GPIO_IRDA_TX);
err_tx:
return ret;
}
static void tosa_irda_shutdown(struct device *dev)
{
tosa_irda_transceiver_mode(dev, IR_SIRMODE | IR_OFF);
gpio_free(TOSA_GPIO_IR_POWERDWN);
gpio_free(TOSA_GPIO_IRDA_TX);
}
static int tosa_tc6393xb_enable(struct platform_device *dev)
{
int rc;
rc = gpio_request(TOSA_GPIO_TC6393XB_REST_IN, "tc6393xb #pclr");
if (rc)
goto err_req_pclr;
rc = gpio_request(TOSA_GPIO_TC6393XB_SUSPEND, "tc6393xb #suspend");
if (rc)
goto err_req_suspend;
rc = gpio_request(TOSA_GPIO_TC6393XB_L3V_ON, "tc6393xb l3v");
if (rc)
goto err_req_l3v;
rc = gpio_direction_output(TOSA_GPIO_TC6393XB_L3V_ON, 0);
if (rc)
goto err_dir_l3v;
rc = gpio_direction_output(TOSA_GPIO_TC6393XB_SUSPEND, 0);
if (rc)
goto err_dir_suspend;
rc = gpio_direction_output(TOSA_GPIO_TC6393XB_REST_IN, 0);
if (rc)
goto err_dir_pclr;
mdelay(1);
gpio_set_value(TOSA_GPIO_TC6393XB_SUSPEND, 1);
mdelay(10);
gpio_set_value(TOSA_GPIO_TC6393XB_REST_IN, 1);
gpio_set_value(TOSA_GPIO_TC6393XB_L3V_ON, 1);
return 0;
err_dir_pclr:
err_dir_suspend:
err_dir_l3v:
gpio_free(TOSA_GPIO_TC6393XB_L3V_ON);
err_req_l3v:
gpio_free(TOSA_GPIO_TC6393XB_SUSPEND);
err_req_suspend:
gpio_free(TOSA_GPIO_TC6393XB_REST_IN);
err_req_pclr:
return rc;
}
static int tosa_tc6393xb_disable(struct platform_device *dev)
{
gpio_free(TOSA_GPIO_TC6393XB_L3V_ON);
gpio_free(TOSA_GPIO_TC6393XB_SUSPEND);
gpio_free(TOSA_GPIO_TC6393XB_REST_IN);
return 0;
}
static int tosa_tc6393xb_resume(struct platform_device *dev)
{
gpio_set_value(TOSA_GPIO_TC6393XB_SUSPEND, 1);
mdelay(10);
gpio_set_value(TOSA_GPIO_TC6393XB_L3V_ON, 1);
mdelay(10);
return 0;
}
static int tosa_tc6393xb_suspend(struct platform_device *dev)
{
gpio_set_value(TOSA_GPIO_TC6393XB_L3V_ON, 0);
gpio_set_value(TOSA_GPIO_TC6393XB_SUSPEND, 0);
return 0;
}
static int tosa_tc6393xb_setup(struct platform_device *dev)
{
int rc;
rc = gpio_request(TOSA_GPIO_CARD_VCC_ON, "CARD_VCC_ON");
if (rc)
goto err_req;
rc = gpio_direction_output(TOSA_GPIO_CARD_VCC_ON, 1);
if (rc)
goto err_dir;
return rc;
err_dir:
gpio_free(TOSA_GPIO_CARD_VCC_ON);
err_req:
return rc;
}
static void tosa_tc6393xb_teardown(struct platform_device *dev)
{
gpio_free(TOSA_GPIO_CARD_VCC_ON);
}
static void tosa_poweroff(void)
{
pxa_restart(REBOOT_GPIO, NULL);
}
static void tosa_restart(enum reboot_mode mode, const char *cmd)
{
uint32_t msc0 = __raw_readl(MSC0);
if((msc0 & 0xffff0000) == 0x7ff00000)
__raw_writel((msc0 & 0xffff) | 0x7ee00000, MSC0);
tosa_poweroff();
}
static void __init tosa_init(void)
{
pxa2xx_mfp_config(ARRAY_AND_SIZE(tosa_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
gpio_set_wake(MFP_PIN_GPIO1, 1);
init_gpio_reset(TOSA_GPIO_ON_RESET, 0, 0);
pm_power_off = tosa_poweroff;
PCFR |= PCFR_OPDE;
PMCR = 0x01;
pxa_set_mci_info(&tosa_mci_platform_data);
pxa_set_ficp_info(&tosa_ficp_platform_data);
pxa_set_i2c_info(NULL);
pxa_set_ac97_info(NULL);
platform_scoop_config = &tosa_pcmcia_config;
pxa2xx_set_spi_info(2, &pxa_ssp_master_info);
spi_register_board_info(spi_board_info, ARRAY_SIZE(spi_board_info));
clk_add_alias("CLK_CK3P6MI", tc6393xb_device.name, "GPIO11_CLK", NULL);
platform_add_devices(devices, ARRAY_SIZE(devices));
}
static void __init fixup_tosa(struct tag *tags, char **cmdline)
{
sharpsl_save_param();
memblock_add(0xa0000000, SZ_64M);
}
