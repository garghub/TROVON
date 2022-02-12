void __init tegra20_init_speedo_data(struct tegra_sku_info *sku_info)
{
u32 reg;
u32 val;
int i;
BUILD_BUG_ON(ARRAY_SIZE(cpu_process_speedos) != SPEEDO_ID_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(soc_process_speedos) != SPEEDO_ID_COUNT);
if (SPEEDO_ID_SELECT_0(sku_info->revision))
sku_info->soc_speedo_id = SPEEDO_ID_0;
else if (SPEEDO_ID_SELECT_1(sku_info->sku_id))
sku_info->soc_speedo_id = SPEEDO_ID_1;
else
sku_info->soc_speedo_id = SPEEDO_ID_2;
val = 0;
for (i = CPU_SPEEDO_MSBIT; i >= CPU_SPEEDO_LSBIT; i--) {
reg = tegra_fuse_read_spare(i) |
tegra_fuse_read_spare(i + CPU_SPEEDO_REDUND_OFFS);
val = (val << 1) | (reg & 0x1);
}
val = val * SPEEDO_MULT;
pr_debug("Tegra CPU speedo value %u\n", val);
for (i = 0; i < (PROCESS_CORNERS_NUM - 1); i++) {
if (val <= cpu_process_speedos[sku_info->soc_speedo_id][i])
break;
}
sku_info->cpu_process_id = i;
val = 0;
for (i = SOC_SPEEDO_MSBIT; i >= SOC_SPEEDO_LSBIT; i--) {
reg = tegra_fuse_read_spare(i) |
tegra_fuse_read_spare(i + SOC_SPEEDO_REDUND_OFFS);
val = (val << 1) | (reg & 0x1);
}
val = val * SPEEDO_MULT;
pr_debug("Core speedo value %u\n", val);
for (i = 0; i < (PROCESS_CORNERS_NUM - 1); i++) {
if (val <= soc_process_speedos[sku_info->soc_speedo_id][i])
break;
}
sku_info->soc_process_id = i;
}
