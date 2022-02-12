static int aspeed_g4_pinctrl_probe(struct platform_device *pdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(aspeed_g4_pins); i++)
aspeed_g4_pins[i].number = i;
return aspeed_pinctrl_probe(pdev, &aspeed_g4_pinctrl_desc,
&aspeed_g4_pinctrl_data);
}
static int aspeed_g4_pinctrl_init(void)
{
return platform_driver_register(&aspeed_g4_pinctrl_driver);
}
