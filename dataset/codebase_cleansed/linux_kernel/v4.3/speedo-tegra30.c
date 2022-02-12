static void __init fuse_speedo_calib(u32 *speedo_g, u32 *speedo_lp)
{
u32 reg;
int ate_ver;
int bit_minus1;
int bit_minus2;
reg = tegra_fuse_read_early(FUSE_SPEEDO_CALIB_0);
*speedo_lp = (reg & 0xFFFF) * 4;
*speedo_g = ((reg >> 16) & 0xFFFF) * 4;
ate_ver = tegra_fuse_read_early(FUSE_TEST_PROG_VER);
pr_debug("Tegra ATE prog ver %d.%d\n", ate_ver/10, ate_ver%10);
if (ate_ver >= 26) {
bit_minus1 = tegra_fuse_read_spare(LP_SPEEDO_BIT_MINUS1);
bit_minus1 |= tegra_fuse_read_spare(LP_SPEEDO_BIT_MINUS1_R);
bit_minus2 = tegra_fuse_read_spare(LP_SPEEDO_BIT_MINUS2);
bit_minus2 |= tegra_fuse_read_spare(LP_SPEEDO_BIT_MINUS2_R);
*speedo_lp |= (bit_minus1 << 1) | bit_minus2;
bit_minus1 = tegra_fuse_read_spare(G_SPEEDO_BIT_MINUS1);
bit_minus1 |= tegra_fuse_read_spare(G_SPEEDO_BIT_MINUS1_R);
bit_minus2 = tegra_fuse_read_spare(G_SPEEDO_BIT_MINUS2);
bit_minus2 |= tegra_fuse_read_spare(G_SPEEDO_BIT_MINUS2_R);
*speedo_g |= (bit_minus1 << 1) | bit_minus2;
} else {
*speedo_lp |= 0x3;
*speedo_g |= 0x3;
}
}
static void __init rev_sku_to_speedo_ids(struct tegra_sku_info *sku_info)
{
int package_id = tegra_fuse_read_early(FUSE_PACKAGE_INFO) & 0x0F;
switch (sku_info->revision) {
case TEGRA_REVISION_A01:
sku_info->cpu_speedo_id = 0;
sku_info->soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
case TEGRA_REVISION_A02:
case TEGRA_REVISION_A03:
switch (sku_info->sku_id) {
case 0x87:
case 0x82:
sku_info->cpu_speedo_id = 1;
sku_info->soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_1;
break;
case 0x81:
switch (package_id) {
case 1:
sku_info->cpu_speedo_id = 2;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_2;
break;
case 2:
sku_info->cpu_speedo_id = 4;
sku_info->soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_7;
break;
default:
pr_err("Tegra Unknown pkg %d\n", package_id);
break;
}
break;
case 0x80:
switch (package_id) {
case 1:
sku_info->cpu_speedo_id = 5;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_8;
break;
case 2:
sku_info->cpu_speedo_id = 6;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_9;
break;
default:
pr_err("Tegra Unknown pkg %d\n", package_id);
break;
}
break;
case 0x83:
switch (package_id) {
case 1:
sku_info->cpu_speedo_id = 7;
sku_info->soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_10;
break;
case 2:
sku_info->cpu_speedo_id = 3;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_3;
break;
default:
pr_err("Tegra Unknown pkg %d\n", package_id);
break;
}
break;
case 0x8F:
sku_info->cpu_speedo_id = 8;
sku_info->soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_11;
break;
case 0x08:
sku_info->cpu_speedo_id = 1;
sku_info->soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_4;
break;
case 0x02:
sku_info->cpu_speedo_id = 2;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_5;
break;
case 0x04:
sku_info->cpu_speedo_id = 3;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_6;
break;
case 0:
switch (package_id) {
case 1:
sku_info->cpu_speedo_id = 2;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_2;
break;
case 2:
sku_info->cpu_speedo_id = 3;
sku_info->soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_3;
break;
default:
pr_err("Tegra Unknown pkg %d\n", package_id);
break;
}
break;
default:
pr_warn("Tegra Unknown SKU %d\n", sku_info->sku_id);
sku_info->cpu_speedo_id = 0;
sku_info->soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
}
break;
default:
pr_warn("Tegra Unknown chip rev %d\n", sku_info->revision);
sku_info->cpu_speedo_id = 0;
sku_info->soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
}
}
void __init tegra30_init_speedo_data(struct tegra_sku_info *sku_info)
{
u32 cpu_speedo_val;
u32 soc_speedo_val;
int i;
BUILD_BUG_ON(ARRAY_SIZE(cpu_process_speedos) !=
THRESHOLD_INDEX_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(soc_process_speedos) !=
THRESHOLD_INDEX_COUNT);
rev_sku_to_speedo_ids(sku_info);
fuse_speedo_calib(&cpu_speedo_val, &soc_speedo_val);
pr_debug("Tegra CPU speedo value %u\n", cpu_speedo_val);
pr_debug("Tegra Core speedo value %u\n", soc_speedo_val);
for (i = 0; i < CPU_PROCESS_CORNERS; i++) {
if (cpu_speedo_val < cpu_process_speedos[threshold_index][i])
break;
}
sku_info->cpu_process_id = i - 1;
if (sku_info->cpu_process_id == -1) {
pr_warn("Tegra CPU speedo value %3d out of range",
cpu_speedo_val);
sku_info->cpu_process_id = 0;
sku_info->cpu_speedo_id = 1;
}
for (i = 0; i < SOC_PROCESS_CORNERS; i++) {
if (soc_speedo_val < soc_process_speedos[threshold_index][i])
break;
}
sku_info->soc_process_id = i - 1;
if (sku_info->soc_process_id == -1) {
pr_warn("Tegra SoC speedo value %3d out of range",
soc_speedo_val);
sku_info->soc_process_id = 0;
sku_info->soc_speedo_id = 1;
}
}
