void __init mop500_pins_init(void)
{
nmk_config_pins(mop500_pins_common,
ARRAY_SIZE(mop500_pins_common));
nmk_config_pins(mop500_pins_default,
ARRAY_SIZE(mop500_pins_default));
}
void __init snowball_pins_init(void)
{
nmk_config_pins(mop500_pins_common,
ARRAY_SIZE(mop500_pins_common));
nmk_config_pins(snowball_pins,
ARRAY_SIZE(snowball_pins));
}
void __init hrefv60_pins_init(void)
{
nmk_config_pins(mop500_pins_common,
ARRAY_SIZE(mop500_pins_common));
nmk_config_pins(hrefv60_pins,
ARRAY_SIZE(hrefv60_pins));
}
