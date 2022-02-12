void __devinit tegra30_pinmux_init(const struct tegra_pingroup_desc **pg,
int *pg_max, const struct tegra_drive_pingroup_desc **pgdrive,
int *pgdrive_max)
{
*pg = tegra_soc_pingroups;
*pg_max = TEGRA_MAX_PINGROUP;
*pgdrive = tegra_soc_drive_pingroups;
*pgdrive_max = TEGRA_MAX_DRIVE_PINGROUP;
}
