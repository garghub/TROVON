void __init mx23_map_io(void)
{
iotable_init(mx23_io_desc, ARRAY_SIZE(mx23_io_desc));
}
void __init mx23_init_irq(void)
{
icoll_init_irq();
}
void __init mx28_map_io(void)
{
iotable_init(mx28_io_desc, ARRAY_SIZE(mx28_io_desc));
}
void __init mx28_init_irq(void)
{
icoll_init_irq();
}
void __init mx23_soc_init(void)
{
pinctrl_provide_dummies();
mxs_add_dma("imx23-dma-apbh", MX23_APBH_DMA_BASE_ADDR);
mxs_add_dma("imx23-dma-apbx", MX23_APBX_DMA_BASE_ADDR);
mxs_add_gpio("imx23-gpio", 0, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO0);
mxs_add_gpio("imx23-gpio", 1, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO1);
mxs_add_gpio("imx23-gpio", 2, MX23_PINCTRL_BASE_ADDR, MX23_INT_GPIO2);
}
void __init mx28_soc_init(void)
{
pinctrl_provide_dummies();
mxs_add_dma("imx28-dma-apbh", MX23_APBH_DMA_BASE_ADDR);
mxs_add_dma("imx28-dma-apbx", MX23_APBX_DMA_BASE_ADDR);
mxs_add_gpio("imx28-gpio", 0, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO0);
mxs_add_gpio("imx28-gpio", 1, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO1);
mxs_add_gpio("imx28-gpio", 2, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO2);
mxs_add_gpio("imx28-gpio", 3, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO3);
mxs_add_gpio("imx28-gpio", 4, MX28_PINCTRL_BASE_ADDR, MX28_INT_GPIO4);
}
