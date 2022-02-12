static int __init harmony_pcie_init(void)
{
struct regulator *regulator = NULL;
int err;
if (!machine_is_harmony())
return 0;
err = gpio_request(EN_VDD_1V05_GPIO, "EN_VDD_1V05");
if (err)
return err;
gpio_direction_output(EN_VDD_1V05_GPIO, 1);
regulator = regulator_get(NULL, "pex_clk");
if (IS_ERR_OR_NULL(regulator))
goto err_reg;
regulator_enable(regulator);
tegra_pinmux_set_tristate(TEGRA_PINGROUP_GPV, TEGRA_TRI_NORMAL);
tegra_pinmux_set_tristate(TEGRA_PINGROUP_SLXA, TEGRA_TRI_NORMAL);
tegra_pinmux_set_tristate(TEGRA_PINGROUP_SLXK, TEGRA_TRI_NORMAL);
err = tegra_pcie_init(true, true);
if (err)
goto err_pcie;
return 0;
err_pcie:
tegra_pinmux_set_tristate(TEGRA_PINGROUP_GPV, TEGRA_TRI_TRISTATE);
tegra_pinmux_set_tristate(TEGRA_PINGROUP_SLXA, TEGRA_TRI_TRISTATE);
tegra_pinmux_set_tristate(TEGRA_PINGROUP_SLXK, TEGRA_TRI_TRISTATE);
regulator_disable(regulator);
regulator_put(regulator);
err_reg:
gpio_free(EN_VDD_1V05_GPIO);
return err;
}
