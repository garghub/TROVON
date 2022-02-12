static int __init stm32f469_pinctrl_init(void)
{
return platform_driver_register(&stm32f469_pinctrl_driver);
}
