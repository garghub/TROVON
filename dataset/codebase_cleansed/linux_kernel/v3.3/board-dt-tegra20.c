static void __init tegra_dt_init(void)
{
int i;
tegra_clk_init_from_table(tegra_dt_clk_init_table);
for (i = 0; i < ARRAY_SIZE(pinmux_configs); i++) {
if (of_machine_is_compatible(pinmux_configs[i].machine)) {
pinmux_configs[i].init();
break;
}
}
WARN(i == ARRAY_SIZE(pinmux_configs),
"Unknown platform! Pinmuxing not initialized\n");
of_platform_populate(NULL, tegra_dt_match_table,
tegra20_auxdata_lookup, NULL);
}
