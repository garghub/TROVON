static int __init stm32f429_pinctrl_init(void)
{
return platform_driver_register(&stm32f429_pinctrl_driver);
}
