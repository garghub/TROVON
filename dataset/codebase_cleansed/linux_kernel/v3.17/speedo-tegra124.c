static void __init rev_sku_to_speedo_ids(struct tegra_sku_info *sku_info,
int *threshold)
{
int sku = sku_info->sku_id;
sku_info->cpu_speedo_id = 0;
sku_info->soc_speedo_id = 0;
sku_info->gpu_speedo_id = 0;
*threshold = THRESHOLD_INDEX_0;
switch (sku) {
case 0x00:
case 0x0F:
case 0x23:
break;
case 0x83:
sku_info->cpu_speedo_id = 2;
break;
case 0x1F:
case 0x87:
case 0x27:
sku_info->cpu_speedo_id = 2;
sku_info->soc_speedo_id = 0;
sku_info->gpu_speedo_id = 1;
*threshold = THRESHOLD_INDEX_0;
break;
case 0x81:
case 0x21:
case 0x07:
sku_info->cpu_speedo_id = 1;
sku_info->soc_speedo_id = 1;
sku_info->gpu_speedo_id = 1;
*threshold = THRESHOLD_INDEX_1;
break;
case 0x49:
case 0x4A:
case 0x48:
sku_info->cpu_speedo_id = 4;
sku_info->soc_speedo_id = 2;
sku_info->gpu_speedo_id = 3;
*threshold = THRESHOLD_INDEX_1;
break;
default:
pr_err("Tegra Unknown SKU %d\n", sku);
break;
}
}
void __init tegra124_init_speedo_data(struct tegra_sku_info *sku_info)
{
int i, threshold, cpu_speedo_0_value, soc_speedo_0_value;
int cpu_iddq_value, gpu_iddq_value, soc_iddq_value;
BUILD_BUG_ON(ARRAY_SIZE(cpu_process_speedos) !=
THRESHOLD_INDEX_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(gpu_process_speedos) !=
THRESHOLD_INDEX_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(core_process_speedos) !=
THRESHOLD_INDEX_COUNT);
cpu_speedo_0_value = tegra30_fuse_readl(FUSE_CPU_SPEEDO_0);
sku_info->gpu_speedo_value = tegra30_fuse_readl(FUSE_CPU_SPEEDO_2);
soc_speedo_0_value = tegra30_fuse_readl(FUSE_SOC_SPEEDO_0);
cpu_iddq_value = tegra30_fuse_readl(FUSE_CPU_IDDQ);
soc_iddq_value = tegra30_fuse_readl(FUSE_SOC_IDDQ);
gpu_iddq_value = tegra30_fuse_readl(FUSE_GPU_IDDQ);
sku_info->cpu_speedo_value = cpu_speedo_0_value;
if (sku_info->cpu_speedo_value == 0) {
pr_warn("Tegra Warning: Speedo value not fused.\n");
WARN_ON(1);
return;
}
rev_sku_to_speedo_ids(sku_info, &threshold);
sku_info->cpu_iddq_value = tegra30_fuse_readl(FUSE_CPU_IDDQ);
for (i = 0; i < GPU_PROCESS_CORNERS; i++)
if (sku_info->gpu_speedo_value <
gpu_process_speedos[threshold][i])
break;
sku_info->gpu_process_id = i;
for (i = 0; i < CPU_PROCESS_CORNERS; i++)
if (sku_info->cpu_speedo_value <
cpu_process_speedos[threshold][i])
break;
sku_info->cpu_process_id = i;
for (i = 0; i < CORE_PROCESS_CORNERS; i++)
if (soc_speedo_0_value <
core_process_speedos[threshold][i])
break;
sku_info->core_process_id = i;
pr_debug("Tegra GPU Speedo ID=%d, Speedo Value=%d\n",
sku_info->gpu_speedo_id, sku_info->gpu_speedo_value);
}
