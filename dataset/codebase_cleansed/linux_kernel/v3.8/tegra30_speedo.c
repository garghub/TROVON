static void fuse_speedo_calib(u32 *speedo_g, u32 *speedo_lp)
{
u32 reg;
int ate_ver;
int bit_minus1;
int bit_minus2;
reg = tegra_fuse_readl(FUSE_SPEEDO_CALIB_0);
*speedo_lp = (reg & 0xFFFF) * 4;
*speedo_g = ((reg >> 16) & 0xFFFF) * 4;
ate_ver = tegra_fuse_readl(FUSE_TEST_PROG_VER);
pr_info("%s: ATE prog ver %d.%d\n", __func__, ate_ver/10, ate_ver%10);
if (ate_ver >= 26) {
bit_minus1 = tegra_spare_fuse(LP_SPEEDO_BIT_MINUS1);
bit_minus1 |= tegra_spare_fuse(LP_SPEEDO_BIT_MINUS1_R);
bit_minus2 = tegra_spare_fuse(LP_SPEEDO_BIT_MINUS2);
bit_minus2 |= tegra_spare_fuse(LP_SPEEDO_BIT_MINUS2_R);
*speedo_lp |= (bit_minus1 << 1) | bit_minus2;
bit_minus1 = tegra_spare_fuse(G_SPEEDO_BIT_MINUS1);
bit_minus1 |= tegra_spare_fuse(G_SPEEDO_BIT_MINUS1_R);
bit_minus2 = tegra_spare_fuse(G_SPEEDO_BIT_MINUS2);
bit_minus2 |= tegra_spare_fuse(G_SPEEDO_BIT_MINUS2_R);
*speedo_g |= (bit_minus1 << 1) | bit_minus2;
} else {
*speedo_lp |= 0x3;
*speedo_g |= 0x3;
}
}
static void rev_sku_to_speedo_ids(int rev, int sku)
{
switch (rev) {
case TEGRA_REVISION_A01:
tegra_cpu_speedo_id = 0;
tegra_soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
case TEGRA_REVISION_A02:
case TEGRA_REVISION_A03:
switch (sku) {
case 0x87:
case 0x82:
tegra_cpu_speedo_id = 1;
tegra_soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_1;
break;
case 0x81:
switch (package_id) {
case 1:
tegra_cpu_speedo_id = 2;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_2;
break;
case 2:
tegra_cpu_speedo_id = 4;
tegra_soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_7;
break;
default:
pr_err("Tegra30: Unknown pkg %d\n", package_id);
BUG();
break;
}
break;
case 0x80:
switch (package_id) {
case 1:
tegra_cpu_speedo_id = 5;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_8;
break;
case 2:
tegra_cpu_speedo_id = 6;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_9;
break;
default:
pr_err("Tegra30: Unknown pkg %d\n", package_id);
BUG();
break;
}
break;
case 0x83:
switch (package_id) {
case 1:
tegra_cpu_speedo_id = 7;
tegra_soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_10;
break;
case 2:
tegra_cpu_speedo_id = 3;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_3;
break;
default:
pr_err("Tegra30: Unknown pkg %d\n", package_id);
BUG();
break;
}
break;
case 0x8F:
tegra_cpu_speedo_id = 8;
tegra_soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_11;
break;
case 0x08:
tegra_cpu_speedo_id = 1;
tegra_soc_speedo_id = 1;
threshold_index = THRESHOLD_INDEX_4;
break;
case 0x02:
tegra_cpu_speedo_id = 2;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_5;
break;
case 0x04:
tegra_cpu_speedo_id = 3;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_6;
break;
case 0:
switch (package_id) {
case 1:
tegra_cpu_speedo_id = 2;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_2;
break;
case 2:
tegra_cpu_speedo_id = 3;
tegra_soc_speedo_id = 2;
threshold_index = THRESHOLD_INDEX_3;
break;
default:
pr_err("Tegra30: Unknown pkg %d\n", package_id);
BUG();
break;
}
break;
default:
pr_warn("Tegra30: Unknown SKU %d\n", sku);
tegra_cpu_speedo_id = 0;
tegra_soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
}
break;
default:
pr_warn("Tegra30: Unknown chip rev %d\n", rev);
tegra_cpu_speedo_id = 0;
tegra_soc_speedo_id = 0;
threshold_index = THRESHOLD_INDEX_0;
break;
}
}
void tegra30_init_speedo_data(void)
{
u32 cpu_speedo_val;
u32 core_speedo_val;
int i;
BUILD_BUG_ON(ARRAY_SIZE(cpu_process_speedos) !=
THRESHOLD_INDEX_COUNT);
BUILD_BUG_ON(ARRAY_SIZE(core_process_speedos) !=
THRESHOLD_INDEX_COUNT);
package_id = tegra_fuse_readl(FUSE_PACKAGE_INFO) & 0x0F;
rev_sku_to_speedo_ids(tegra_revision, tegra_sku_id);
fuse_speedo_calib(&cpu_speedo_val, &core_speedo_val);
pr_debug("%s CPU speedo value %u\n", __func__, cpu_speedo_val);
pr_debug("%s Core speedo value %u\n", __func__, core_speedo_val);
for (i = 0; i < CPU_PROCESS_CORNERS_NUM; i++) {
if (cpu_speedo_val < cpu_process_speedos[threshold_index][i])
break;
}
tegra_cpu_process_id = i - 1;
if (tegra_cpu_process_id == -1) {
pr_warn("Tegra30: CPU speedo value %3d out of range",
cpu_speedo_val);
tegra_cpu_process_id = 0;
tegra_cpu_speedo_id = 1;
}
for (i = 0; i < CORE_PROCESS_CORNERS_NUM; i++) {
if (core_speedo_val < core_process_speedos[threshold_index][i])
break;
}
tegra_core_process_id = i - 1;
if (tegra_core_process_id == -1) {
pr_warn("Tegra30: CORE speedo value %3d out of range",
core_speedo_val);
tegra_core_process_id = 0;
tegra_soc_speedo_id = 1;
}
pr_info("Tegra30: CPU Speedo ID %d, Soc Speedo ID %d",
tegra_cpu_speedo_id, tegra_soc_speedo_id);
}
