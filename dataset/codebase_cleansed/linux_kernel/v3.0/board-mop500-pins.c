void __init mop500_pins_init(void)
{
nmk_config_pins(mop500_pins_common,
ARRAY_SIZE(mop500_pins_common));
if (machine_is_hrefv60())
nmk_config_pins(mop500_pins_hrefv60,
ARRAY_SIZE(mop500_pins_hrefv60));
else
nmk_config_pins(mop500_pins_default,
ARRAY_SIZE(mop500_pins_default));
}
