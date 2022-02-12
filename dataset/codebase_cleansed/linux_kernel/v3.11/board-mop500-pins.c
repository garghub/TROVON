static int __init early_pinsfor(char *p)
{
pinsfor = PINS_FOR_DEFAULT;
if (strcmp(p, "u9500-21") == 0)
pinsfor = PINS_FOR_U9500;
return 0;
}
int pins_for_u9500(void)
{
if (pinsfor == PINS_FOR_U9500)
return 1;
return 0;
}
static void __init mop500_href_family_pinmaps_init(void)
{
switch (pinsfor) {
case PINS_FOR_U9500:
pinctrl_register_mappings(u9500_pinmap,
ARRAY_SIZE(u9500_pinmap));
break;
case PINS_FOR_DEFAULT:
pinctrl_register_mappings(u8500_pinmap,
ARRAY_SIZE(u8500_pinmap));
default:
break;
}
}
void __init mop500_pinmaps_init(void)
{
pinctrl_register_mappings(mop500_family_pinmap,
ARRAY_SIZE(mop500_family_pinmap));
pinctrl_register_mappings(mop500_pinmap,
ARRAY_SIZE(mop500_pinmap));
mop500_href_family_pinmaps_init();
if (machine_is_u8520())
pinctrl_register_mappings(ab8505_pinmap,
ARRAY_SIZE(ab8505_pinmap));
else
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
void __init snowball_pinmaps_init(void)
{
pinctrl_register_mappings(mop500_family_pinmap,
ARRAY_SIZE(mop500_family_pinmap));
pinctrl_register_mappings(snowball_pinmap,
ARRAY_SIZE(snowball_pinmap));
pinctrl_register_mappings(u8500_pinmap,
ARRAY_SIZE(u8500_pinmap));
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
void __init hrefv60_pinmaps_init(void)
{
pinctrl_register_mappings(mop500_family_pinmap,
ARRAY_SIZE(mop500_family_pinmap));
pinctrl_register_mappings(hrefv60_pinmap,
ARRAY_SIZE(hrefv60_pinmap));
mop500_href_family_pinmaps_init();
pinctrl_register_mappings(ab8500_pinmap,
ARRAY_SIZE(ab8500_pinmap));
}
