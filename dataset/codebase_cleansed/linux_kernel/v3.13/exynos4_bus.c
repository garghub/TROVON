static int exynos4210_set_busclk(struct busfreq_data *data,
struct busfreq_opp_info *oppi)
{
unsigned int index;
unsigned int tmp;
for (index = LV_0; index < EX4210_LV_NUM; index++)
if (oppi->rate == exynos4210_busclk_table[index].clk)
break;
if (index == EX4210_LV_NUM)
return -EINVAL;
tmp = data->dmc_divtable[index];
__raw_writel(tmp, EXYNOS4_CLKDIV_DMC0);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_DMC0);
} while (tmp & 0x11111111);
tmp = data->top_divtable[index];
__raw_writel(tmp, EXYNOS4_CLKDIV_TOP);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_TOP);
} while (tmp & 0x11111);
tmp = __raw_readl(EXYNOS4_CLKDIV_LEFTBUS);
tmp &= ~(EXYNOS4_CLKDIV_BUS_GDLR_MASK | EXYNOS4_CLKDIV_BUS_GPLR_MASK);
tmp |= ((exynos4210_clkdiv_lr_bus[index][0] <<
EXYNOS4_CLKDIV_BUS_GDLR_SHIFT) |
(exynos4210_clkdiv_lr_bus[index][1] <<
EXYNOS4_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_LEFTBUS);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_LEFTBUS);
} while (tmp & 0x11);
tmp = __raw_readl(EXYNOS4_CLKDIV_RIGHTBUS);
tmp &= ~(EXYNOS4_CLKDIV_BUS_GDLR_MASK | EXYNOS4_CLKDIV_BUS_GPLR_MASK);
tmp |= ((exynos4210_clkdiv_lr_bus[index][0] <<
EXYNOS4_CLKDIV_BUS_GDLR_SHIFT) |
(exynos4210_clkdiv_lr_bus[index][1] <<
EXYNOS4_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_RIGHTBUS);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_RIGHTBUS);
} while (tmp & 0x11);
return 0;
}
static int exynos4x12_set_busclk(struct busfreq_data *data,
struct busfreq_opp_info *oppi)
{
unsigned int index;
unsigned int tmp;
for (index = LV_0; index < EX4x12_LV_NUM; index++)
if (oppi->rate == exynos4x12_mifclk_table[index].clk)
break;
if (index == EX4x12_LV_NUM)
return -EINVAL;
tmp = data->dmc_divtable[index];
__raw_writel(tmp, EXYNOS4_CLKDIV_DMC0);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_DMC0);
} while (tmp & 0x11111111);
tmp = __raw_readl(EXYNOS4_CLKDIV_DMC1);
tmp &= ~(EXYNOS4_CLKDIV_DMC1_G2D_ACP_MASK |
EXYNOS4_CLKDIV_DMC1_C2C_MASK |
EXYNOS4_CLKDIV_DMC1_C2CACLK_MASK);
tmp |= ((exynos4x12_clkdiv_dmc1[index][0] <<
EXYNOS4_CLKDIV_DMC1_G2D_ACP_SHIFT) |
(exynos4x12_clkdiv_dmc1[index][1] <<
EXYNOS4_CLKDIV_DMC1_C2C_SHIFT) |
(exynos4x12_clkdiv_dmc1[index][2] <<
EXYNOS4_CLKDIV_DMC1_C2CACLK_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_DMC1);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_DMC1);
} while (tmp & 0x111111);
tmp = __raw_readl(EXYNOS4_CLKDIV_TOP);
tmp &= ~(EXYNOS4_CLKDIV_TOP_ACLK266_GPS_MASK |
EXYNOS4_CLKDIV_TOP_ACLK100_MASK |
EXYNOS4_CLKDIV_TOP_ACLK160_MASK |
EXYNOS4_CLKDIV_TOP_ACLK133_MASK |
EXYNOS4_CLKDIV_TOP_ONENAND_MASK);
tmp |= ((exynos4x12_clkdiv_top[index][0] <<
EXYNOS4_CLKDIV_TOP_ACLK266_GPS_SHIFT) |
(exynos4x12_clkdiv_top[index][1] <<
EXYNOS4_CLKDIV_TOP_ACLK100_SHIFT) |
(exynos4x12_clkdiv_top[index][2] <<
EXYNOS4_CLKDIV_TOP_ACLK160_SHIFT) |
(exynos4x12_clkdiv_top[index][3] <<
EXYNOS4_CLKDIV_TOP_ACLK133_SHIFT) |
(exynos4x12_clkdiv_top[index][4] <<
EXYNOS4_CLKDIV_TOP_ONENAND_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_TOP);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_TOP);
} while (tmp & 0x11111);
tmp = __raw_readl(EXYNOS4_CLKDIV_LEFTBUS);
tmp &= ~(EXYNOS4_CLKDIV_BUS_GDLR_MASK | EXYNOS4_CLKDIV_BUS_GPLR_MASK);
tmp |= ((exynos4x12_clkdiv_lr_bus[index][0] <<
EXYNOS4_CLKDIV_BUS_GDLR_SHIFT) |
(exynos4x12_clkdiv_lr_bus[index][1] <<
EXYNOS4_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_LEFTBUS);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_LEFTBUS);
} while (tmp & 0x11);
tmp = __raw_readl(EXYNOS4_CLKDIV_RIGHTBUS);
tmp &= ~(EXYNOS4_CLKDIV_BUS_GDLR_MASK | EXYNOS4_CLKDIV_BUS_GPLR_MASK);
tmp |= ((exynos4x12_clkdiv_lr_bus[index][0] <<
EXYNOS4_CLKDIV_BUS_GDLR_SHIFT) |
(exynos4x12_clkdiv_lr_bus[index][1] <<
EXYNOS4_CLKDIV_BUS_GPLR_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_RIGHTBUS);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_RIGHTBUS);
} while (tmp & 0x11);
tmp = __raw_readl(EXYNOS4_CLKDIV_MFC);
tmp &= ~(EXYNOS4_CLKDIV_MFC_MASK);
tmp |= ((exynos4x12_clkdiv_sclkip[index][0] <<
EXYNOS4_CLKDIV_MFC_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_MFC);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_MFC);
} while (tmp & 0x1);
tmp = __raw_readl(EXYNOS4_CLKDIV_CAM1);
tmp &= ~(EXYNOS4_CLKDIV_CAM1_JPEG_MASK);
tmp |= ((exynos4x12_clkdiv_sclkip[index][1] <<
EXYNOS4_CLKDIV_CAM1_JPEG_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_CAM1);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_CAM1);
} while (tmp & 0x1);
tmp = __raw_readl(EXYNOS4_CLKDIV_CAM);
tmp &= ~(EXYNOS4_CLKDIV_CAM_FIMC0_MASK | EXYNOS4_CLKDIV_CAM_FIMC1_MASK |
EXYNOS4_CLKDIV_CAM_FIMC2_MASK | EXYNOS4_CLKDIV_CAM_FIMC3_MASK);
tmp |= ((exynos4x12_clkdiv_sclkip[index][2] <<
EXYNOS4_CLKDIV_CAM_FIMC0_SHIFT) |
(exynos4x12_clkdiv_sclkip[index][2] <<
EXYNOS4_CLKDIV_CAM_FIMC1_SHIFT) |
(exynos4x12_clkdiv_sclkip[index][2] <<
EXYNOS4_CLKDIV_CAM_FIMC2_SHIFT) |
(exynos4x12_clkdiv_sclkip[index][2] <<
EXYNOS4_CLKDIV_CAM_FIMC3_SHIFT));
__raw_writel(tmp, EXYNOS4_CLKDIV_CAM);
do {
tmp = __raw_readl(EXYNOS4_CLKDIV_STAT_CAM1);
} while (tmp & 0x1111);
return 0;
}
static void busfreq_mon_reset(struct busfreq_data *data)
{
unsigned int i;
for (i = 0; i < 2; i++) {
void __iomem *ppmu_base = data->dmc[i].hw_base;
__raw_writel(0x8000000f, ppmu_base + 0xf010);
__raw_writel(0x8000000f, ppmu_base + 0xf050);
__raw_writel(0x6, ppmu_base + 0xf000);
__raw_writel(0x0, ppmu_base + 0xf100);
data->dmc[i].event = 0x6;
__raw_writel(((data->dmc[i].event << 12) | 0x1),
ppmu_base + 0xfc);
__raw_writel(0x1, ppmu_base + 0xf000);
}
}
static void exynos4_read_ppmu(struct busfreq_data *data)
{
int i, j;
for (i = 0; i < 2; i++) {
void __iomem *ppmu_base = data->dmc[i].hw_base;
u32 overflow;
__raw_writel(0x0, ppmu_base + 0xf000);
overflow = __raw_readl(ppmu_base + 0xf050);
data->dmc[i].ccnt = __raw_readl(ppmu_base + 0xf100);
data->dmc[i].ccnt_overflow = overflow & (1 << 31);
for (j = 0; j < PPMU_PMNCNT_MAX; j++) {
data->dmc[i].count[j] = __raw_readl(
ppmu_base + (0xf110 + (0x10 * j)));
data->dmc[i].count_overflow[j] = overflow & (1 << j);
}
}
busfreq_mon_reset(data);
}
static int exynos4x12_get_intspec(unsigned long mifclk)
{
int i = 0;
while (exynos4x12_intclk_table[i].clk) {
if (exynos4x12_intclk_table[i].clk <= mifclk)
return i;
i++;
}
return -EINVAL;
}
static int exynos4_bus_setvolt(struct busfreq_data *data,
struct busfreq_opp_info *oppi,
struct busfreq_opp_info *oldoppi)
{
int err = 0, tmp;
unsigned long volt = oppi->volt;
switch (data->type) {
case TYPE_BUSF_EXYNOS4210:
err = regulator_set_voltage(data->vdd_int, volt,
MAX_SAFEVOLT);
break;
case TYPE_BUSF_EXYNOS4x12:
err = regulator_set_voltage(data->vdd_mif, volt,
MAX_SAFEVOLT);
if (err)
break;
tmp = exynos4x12_get_intspec(oppi->rate);
if (tmp < 0) {
err = tmp;
regulator_set_voltage(data->vdd_mif,
oldoppi->volt,
MAX_SAFEVOLT);
break;
}
err = regulator_set_voltage(data->vdd_int,
exynos4x12_intclk_table[tmp].volt,
MAX_SAFEVOLT);
if (err)
regulator_set_voltage(data->vdd_mif,
oldoppi->volt,
MAX_SAFEVOLT);
break;
default:
err = -EINVAL;
}
return err;
}
static int exynos4_bus_target(struct device *dev, unsigned long *_freq,
u32 flags)
{
int err = 0;
struct platform_device *pdev = container_of(dev, struct platform_device,
dev);
struct busfreq_data *data = platform_get_drvdata(pdev);
struct dev_pm_opp *opp;
unsigned long freq;
unsigned long old_freq = data->curr_oppinfo.rate;
struct busfreq_opp_info new_oppinfo;
rcu_read_lock();
opp = devfreq_recommended_opp(dev, _freq, flags);
if (IS_ERR(opp)) {
rcu_read_unlock();
return PTR_ERR(opp);
}
new_oppinfo.rate = dev_pm_opp_get_freq(opp);
new_oppinfo.volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
freq = new_oppinfo.rate;
if (old_freq == freq)
return 0;
dev_dbg(dev, "targeting %lukHz %luuV\n", freq, new_oppinfo.volt);
mutex_lock(&data->lock);
if (data->disabled)
goto out;
if (old_freq < freq)
err = exynos4_bus_setvolt(data, &new_oppinfo,
&data->curr_oppinfo);
if (err)
goto out;
if (old_freq != freq) {
switch (data->type) {
case TYPE_BUSF_EXYNOS4210:
err = exynos4210_set_busclk(data, &new_oppinfo);
break;
case TYPE_BUSF_EXYNOS4x12:
err = exynos4x12_set_busclk(data, &new_oppinfo);
break;
default:
err = -EINVAL;
}
}
if (err)
goto out;
if (old_freq > freq)
err = exynos4_bus_setvolt(data, &new_oppinfo,
&data->curr_oppinfo);
if (err)
goto out;
data->curr_oppinfo = new_oppinfo;
out:
mutex_unlock(&data->lock);
return err;
}
static int exynos4_get_busier_dmc(struct busfreq_data *data)
{
u64 p0 = data->dmc[0].count[0];
u64 p1 = data->dmc[1].count[0];
p0 *= data->dmc[1].ccnt;
p1 *= data->dmc[0].ccnt;
if (data->dmc[1].ccnt == 0)
return 0;
if (p0 > p1)
return 0;
return 1;
}
static int exynos4_bus_get_dev_status(struct device *dev,
struct devfreq_dev_status *stat)
{
struct busfreq_data *data = dev_get_drvdata(dev);
int busier_dmc;
int cycles_x2 = 2;
void __iomem *addr;
u32 timing;
u32 memctrl;
exynos4_read_ppmu(data);
busier_dmc = exynos4_get_busier_dmc(data);
stat->current_frequency = data->curr_oppinfo.rate;
if (busier_dmc)
addr = S5P_VA_DMC1;
else
addr = S5P_VA_DMC0;
memctrl = __raw_readl(addr + 0x04);
timing = __raw_readl(addr + 0x38);
switch ((memctrl >> 8) & 0xf) {
case 0x4:
cycles_x2 = ((timing >> 16) & 0xf) * 2;
break;
case 0x5:
case 0x6:
cycles_x2 = ((timing >> 8) & 0xf) + ((timing >> 0) & 0xf);
break;
default:
pr_err("%s: Unknown Memory Type(%d).\n", __func__,
(memctrl >> 8) & 0xf);
return -EINVAL;
}
stat->busy_time = data->dmc[busier_dmc].count[0] / 2 * (cycles_x2 + 2);
stat->busy_time *= 100 / BUS_SATURATION_RATIO;
stat->total_time = data->dmc[busier_dmc].ccnt;
if (data->dmc[busier_dmc].ccnt_overflow ||
data->dmc[busier_dmc].count_overflow[0])
return -EAGAIN;
return 0;
}
static void exynos4_bus_exit(struct device *dev)
{
struct busfreq_data *data = dev_get_drvdata(dev);
devfreq_unregister_opp_notifier(dev, data->devfreq);
}
static int exynos4210_init_tables(struct busfreq_data *data)
{
u32 tmp;
int mgrp;
int i, err = 0;
tmp = __raw_readl(EXYNOS4_CLKDIV_DMC0);
for (i = LV_0; i < EX4210_LV_NUM; i++) {
tmp &= ~(EXYNOS4_CLKDIV_DMC0_ACP_MASK |
EXYNOS4_CLKDIV_DMC0_ACPPCLK_MASK |
EXYNOS4_CLKDIV_DMC0_DPHY_MASK |
EXYNOS4_CLKDIV_DMC0_DMC_MASK |
EXYNOS4_CLKDIV_DMC0_DMCD_MASK |
EXYNOS4_CLKDIV_DMC0_DMCP_MASK |
EXYNOS4_CLKDIV_DMC0_COPY2_MASK |
EXYNOS4_CLKDIV_DMC0_CORETI_MASK);
tmp |= ((exynos4210_clkdiv_dmc0[i][0] <<
EXYNOS4_CLKDIV_DMC0_ACP_SHIFT) |
(exynos4210_clkdiv_dmc0[i][1] <<
EXYNOS4_CLKDIV_DMC0_ACPPCLK_SHIFT) |
(exynos4210_clkdiv_dmc0[i][2] <<
EXYNOS4_CLKDIV_DMC0_DPHY_SHIFT) |
(exynos4210_clkdiv_dmc0[i][3] <<
EXYNOS4_CLKDIV_DMC0_DMC_SHIFT) |
(exynos4210_clkdiv_dmc0[i][4] <<
EXYNOS4_CLKDIV_DMC0_DMCD_SHIFT) |
(exynos4210_clkdiv_dmc0[i][5] <<
EXYNOS4_CLKDIV_DMC0_DMCP_SHIFT) |
(exynos4210_clkdiv_dmc0[i][6] <<
EXYNOS4_CLKDIV_DMC0_COPY2_SHIFT) |
(exynos4210_clkdiv_dmc0[i][7] <<
EXYNOS4_CLKDIV_DMC0_CORETI_SHIFT));
data->dmc_divtable[i] = tmp;
}
tmp = __raw_readl(EXYNOS4_CLKDIV_TOP);
for (i = LV_0; i < EX4210_LV_NUM; i++) {
tmp &= ~(EXYNOS4_CLKDIV_TOP_ACLK200_MASK |
EXYNOS4_CLKDIV_TOP_ACLK100_MASK |
EXYNOS4_CLKDIV_TOP_ACLK160_MASK |
EXYNOS4_CLKDIV_TOP_ACLK133_MASK |
EXYNOS4_CLKDIV_TOP_ONENAND_MASK);
tmp |= ((exynos4210_clkdiv_top[i][0] <<
EXYNOS4_CLKDIV_TOP_ACLK200_SHIFT) |
(exynos4210_clkdiv_top[i][1] <<
EXYNOS4_CLKDIV_TOP_ACLK100_SHIFT) |
(exynos4210_clkdiv_top[i][2] <<
EXYNOS4_CLKDIV_TOP_ACLK160_SHIFT) |
(exynos4210_clkdiv_top[i][3] <<
EXYNOS4_CLKDIV_TOP_ACLK133_SHIFT) |
(exynos4210_clkdiv_top[i][4] <<
EXYNOS4_CLKDIV_TOP_ONENAND_SHIFT));
data->top_divtable[i] = tmp;
}
#ifdef CONFIG_EXYNOS_ASV
tmp = exynos4_result_of_asv;
#else
tmp = 0;
#endif
pr_debug("ASV Group of Exynos4 is %d\n", tmp);
switch (tmp) {
case 0:
mgrp = 0;
break;
case 1:
case 2:
mgrp = 1;
break;
case 3:
case 4:
mgrp = 2;
break;
case 5:
case 6:
mgrp = 3;
break;
case 7:
mgrp = 4;
break;
default:
pr_warn("Unknown ASV Group. Use max voltage.\n");
mgrp = 0;
}
for (i = LV_0; i < EX4210_LV_NUM; i++)
exynos4210_busclk_table[i].volt = exynos4210_asv_volt[mgrp][i];
for (i = LV_0; i < EX4210_LV_NUM; i++) {
err = dev_pm_opp_add(data->dev, exynos4210_busclk_table[i].clk,
exynos4210_busclk_table[i].volt);
if (err) {
dev_err(data->dev, "Cannot add opp entries.\n");
return err;
}
}
return 0;
}
static int exynos4x12_init_tables(struct busfreq_data *data)
{
unsigned int i;
unsigned int tmp;
int ret;
tmp = __raw_readl(EXYNOS4_DMC_PAUSE_CTRL);
tmp |= EXYNOS4_DMC_PAUSE_ENABLE;
__raw_writel(tmp, EXYNOS4_DMC_PAUSE_CTRL);
tmp = __raw_readl(EXYNOS4_CLKDIV_DMC0);
for (i = 0; i < EX4x12_LV_NUM; i++) {
tmp &= ~(EXYNOS4_CLKDIV_DMC0_ACP_MASK |
EXYNOS4_CLKDIV_DMC0_ACPPCLK_MASK |
EXYNOS4_CLKDIV_DMC0_DPHY_MASK |
EXYNOS4_CLKDIV_DMC0_DMC_MASK |
EXYNOS4_CLKDIV_DMC0_DMCD_MASK |
EXYNOS4_CLKDIV_DMC0_DMCP_MASK);
tmp |= ((exynos4x12_clkdiv_dmc0[i][0] <<
EXYNOS4_CLKDIV_DMC0_ACP_SHIFT) |
(exynos4x12_clkdiv_dmc0[i][1] <<
EXYNOS4_CLKDIV_DMC0_ACPPCLK_SHIFT) |
(exynos4x12_clkdiv_dmc0[i][2] <<
EXYNOS4_CLKDIV_DMC0_DPHY_SHIFT) |
(exynos4x12_clkdiv_dmc0[i][3] <<
EXYNOS4_CLKDIV_DMC0_DMC_SHIFT) |
(exynos4x12_clkdiv_dmc0[i][4] <<
EXYNOS4_CLKDIV_DMC0_DMCD_SHIFT) |
(exynos4x12_clkdiv_dmc0[i][5] <<
EXYNOS4_CLKDIV_DMC0_DMCP_SHIFT));
data->dmc_divtable[i] = tmp;
}
#ifdef CONFIG_EXYNOS_ASV
tmp = exynos4_result_of_asv;
#else
tmp = 0;
#endif
if (tmp > 8)
tmp = 0;
pr_debug("ASV Group of Exynos4x12 is %d\n", tmp);
for (i = 0; i < EX4x12_LV_NUM; i++) {
exynos4x12_mifclk_table[i].volt =
exynos4x12_mif_step_50[tmp][i];
exynos4x12_intclk_table[i].volt =
exynos4x12_int_volt[tmp][i];
}
for (i = 0; i < EX4x12_LV_NUM; i++) {
ret = dev_pm_opp_add(data->dev, exynos4x12_mifclk_table[i].clk,
exynos4x12_mifclk_table[i].volt);
if (ret) {
dev_err(data->dev, "Fail to add opp entries.\n");
return ret;
}
}
return 0;
}
static int exynos4_busfreq_pm_notifier_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct busfreq_data *data = container_of(this, struct busfreq_data,
pm_notifier);
struct dev_pm_opp *opp;
struct busfreq_opp_info new_oppinfo;
unsigned long maxfreq = ULONG_MAX;
int err = 0;
switch (event) {
case PM_SUSPEND_PREPARE:
mutex_lock(&data->lock);
data->disabled = true;
rcu_read_lock();
opp = dev_pm_opp_find_freq_floor(data->dev, &maxfreq);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(data->dev, "%s: unable to find a min freq\n",
__func__);
mutex_unlock(&data->lock);
return PTR_ERR(opp);
}
new_oppinfo.rate = dev_pm_opp_get_freq(opp);
new_oppinfo.volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
err = exynos4_bus_setvolt(data, &new_oppinfo,
&data->curr_oppinfo);
if (err)
goto unlock;
switch (data->type) {
case TYPE_BUSF_EXYNOS4210:
err = exynos4210_set_busclk(data, &new_oppinfo);
break;
case TYPE_BUSF_EXYNOS4x12:
err = exynos4x12_set_busclk(data, &new_oppinfo);
break;
default:
err = -EINVAL;
}
if (err)
goto unlock;
data->curr_oppinfo = new_oppinfo;
unlock:
mutex_unlock(&data->lock);
if (err)
return err;
return NOTIFY_OK;
case PM_POST_RESTORE:
case PM_POST_SUSPEND:
mutex_lock(&data->lock);
data->disabled = false;
mutex_unlock(&data->lock);
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static int exynos4_busfreq_probe(struct platform_device *pdev)
{
struct busfreq_data *data;
struct dev_pm_opp *opp;
struct device *dev = &pdev->dev;
int err = 0;
data = devm_kzalloc(&pdev->dev, sizeof(struct busfreq_data), GFP_KERNEL);
if (data == NULL) {
dev_err(dev, "Cannot allocate memory.\n");
return -ENOMEM;
}
data->type = pdev->id_entry->driver_data;
data->dmc[0].hw_base = S5P_VA_DMC0;
data->dmc[1].hw_base = S5P_VA_DMC1;
data->pm_notifier.notifier_call = exynos4_busfreq_pm_notifier_event;
data->dev = dev;
mutex_init(&data->lock);
switch (data->type) {
case TYPE_BUSF_EXYNOS4210:
err = exynos4210_init_tables(data);
break;
case TYPE_BUSF_EXYNOS4x12:
err = exynos4x12_init_tables(data);
break;
default:
dev_err(dev, "Cannot determine the device id %d\n", data->type);
err = -EINVAL;
}
if (err)
return err;
data->vdd_int = devm_regulator_get(dev, "vdd_int");
if (IS_ERR(data->vdd_int)) {
dev_err(dev, "Cannot get the regulator \"vdd_int\"\n");
return PTR_ERR(data->vdd_int);
}
if (data->type == TYPE_BUSF_EXYNOS4x12) {
data->vdd_mif = devm_regulator_get(dev, "vdd_mif");
if (IS_ERR(data->vdd_mif)) {
dev_err(dev, "Cannot get the regulator \"vdd_mif\"\n");
return PTR_ERR(data->vdd_mif);
}
}
rcu_read_lock();
opp = dev_pm_opp_find_freq_floor(dev,
&exynos4_devfreq_profile.initial_freq);
if (IS_ERR(opp)) {
rcu_read_unlock();
dev_err(dev, "Invalid initial frequency %lu kHz.\n",
exynos4_devfreq_profile.initial_freq);
return PTR_ERR(opp);
}
data->curr_oppinfo.rate = dev_pm_opp_get_freq(opp);
data->curr_oppinfo.volt = dev_pm_opp_get_voltage(opp);
rcu_read_unlock();
platform_set_drvdata(pdev, data);
busfreq_mon_reset(data);
data->devfreq = devfreq_add_device(dev, &exynos4_devfreq_profile,
"simple_ondemand", NULL);
if (IS_ERR(data->devfreq))
return PTR_ERR(data->devfreq);
devfreq_register_opp_notifier(dev, data->devfreq);
err = register_pm_notifier(&data->pm_notifier);
if (err) {
dev_err(dev, "Failed to setup pm notifier\n");
devfreq_remove_device(data->devfreq);
return err;
}
return 0;
}
static int exynos4_busfreq_remove(struct platform_device *pdev)
{
struct busfreq_data *data = platform_get_drvdata(pdev);
unregister_pm_notifier(&data->pm_notifier);
devfreq_remove_device(data->devfreq);
return 0;
}
static int exynos4_busfreq_resume(struct device *dev)
{
struct busfreq_data *data = dev_get_drvdata(dev);
busfreq_mon_reset(data);
return 0;
}
static int __init exynos4_busfreq_init(void)
{
return platform_driver_register(&exynos4_busfreq_driver);
}
static void __exit exynos4_busfreq_exit(void)
{
platform_driver_unregister(&exynos4_busfreq_driver);
}
