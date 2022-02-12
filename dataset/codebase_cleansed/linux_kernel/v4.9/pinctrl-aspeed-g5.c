static int aspeed_g5_pinctrl_probe(struct platform_device *pdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(aspeed_g5_pins); i++)
aspeed_g5_pins[i].number = i;
return aspeed_pinctrl_probe(pdev, &aspeed_g5_pinctrl_desc,
&aspeed_g5_pinctrl_data);
}
static int aspeed_g5_pinctrl_init(void)
{
return platform_driver_register(&aspeed_g5_pinctrl_driver);
}
