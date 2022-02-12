void tegra20_init_speedo_data(void)
{
u32 reg;
u32 val;
int i;
BUILD_BUG_ON(ARRAY_SIZE(cpu_process_speedos) != SPEEDO_ID_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(core_process_speedos) != SPEEDO_ID_COUNT);
if (SPEEDO_ID_SELECT_0(tegra_revision))
tegra_soc_speedo_id = SPEEDO_ID_0;
else if (SPEEDO_ID_SELECT_1(tegra_sku_id))
tegra_soc_speedo_id = SPEEDO_ID_1;
else
tegra_soc_speedo_id = SPEEDO_ID_2;
val = 0;
for (i = CPU_SPEEDO_MSBIT; i >= CPU_SPEEDO_LSBIT; i--) {
reg = tegra_spare_fuse(i) |
tegra_spare_fuse(i + CPU_SPEEDO_REDUND_OFFS);
val = (val << 1) | (reg & 0x1);
}
val = val * SPEEDO_MULT;
pr_debug("%s CPU speedo value %u\n", __func__, val);
for (i = 0; i < (PROCESS_CORNERS_NUM - 1); i++) {
if (val <= cpu_process_speedos[tegra_soc_speedo_id][i])
break;
}
tegra_cpu_process_id = i;
val = 0;
for (i = CORE_SPEEDO_MSBIT; i >= CORE_SPEEDO_LSBIT; i--) {
reg = tegra_spare_fuse(i) |
tegra_spare_fuse(i + CORE_SPEEDO_REDUND_OFFS);
val = (val << 1) | (reg & 0x1);
}
val = val * SPEEDO_MULT;
pr_debug("%s Core speedo value %u\n", __func__, val);
for (i = 0; i < (PROCESS_CORNERS_NUM - 1); i++) {
if (val <= core_process_speedos[tegra_soc_speedo_id][i])
break;
}
tegra_core_process_id = i;
pr_info("Tegra20 Soc Speedo ID %d", tegra_soc_speedo_id);
}
