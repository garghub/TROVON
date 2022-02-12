void __init mop500_pinmaps_init(void)
{
if (machine_is_u8520())
pinctrl_register_mappings(ab8505_pinmap,
ARRAY_SIZE(ab8505_pinmap));
else
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
void __init snowball_pinmaps_init(void)
{
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
void __init hrefv60_pinmaps_init(void)
{
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
