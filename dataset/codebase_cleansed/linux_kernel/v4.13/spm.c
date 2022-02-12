static inline void spm_register_write(struct spm_driver_data *drv,
enum spm_reg reg, u32 val)
{
if (drv->reg_data->reg_offset[reg])
writel_relaxed(val, drv->reg_base +
drv->reg_data->reg_offset[reg]);
}
static inline void spm_register_write_sync(struct spm_driver_data *drv,
enum spm_reg reg, u32 val)
{
u32 ret;
if (!drv->reg_data->reg_offset[reg])
return;
do {
writel_relaxed(val, drv->reg_base +
drv->reg_data->reg_offset[reg]);
ret = readl_relaxed(drv->reg_base +
drv->reg_data->reg_offset[reg]);
if (ret == val)
break;
cpu_relax();
} while (1);
}
static inline u32 spm_register_read(struct spm_driver_data *drv,
enum spm_reg reg)
{
return readl_relaxed(drv->reg_base + drv->reg_data->reg_offset[reg]);
}
static void spm_set_low_power_mode(struct spm_driver_data *drv,
enum pm_sleep_mode mode)
{
u32 start_index;
u32 ctl_val;
start_index = drv->reg_data->start_index[mode];
ctl_val = spm_register_read(drv, SPM_REG_SPM_CTL);
ctl_val &= ~(SPM_CTL_INDEX << SPM_CTL_INDEX_SHIFT);
ctl_val |= start_index << SPM_CTL_INDEX_SHIFT;
ctl_val |= SPM_CTL_EN;
spm_register_write_sync(drv, SPM_REG_SPM_CTL, ctl_val);
}
static int qcom_pm_collapse(unsigned long int unused)
{
qcom_scm_cpu_power_down(QCOM_SCM_CPU_PWR_DOWN_L2_ON);
return -1;
}
static int qcom_cpu_spc(void)
{
int ret;
struct spm_driver_data *drv = __this_cpu_read(cpu_spm_drv);
spm_set_low_power_mode(drv, PM_SLEEP_MODE_SPC);
ret = cpu_suspend(0, qcom_pm_collapse);
spm_set_low_power_mode(drv, PM_SLEEP_MODE_STBY);
return ret;
}
static int qcom_idle_enter(unsigned long index)
{
return __this_cpu_read(qcom_idle_ops)[index]();
}
static int __init qcom_cpuidle_init(struct device_node *cpu_node, int cpu)
{
const struct of_device_id *match_id;
struct device_node *state_node;
int i;
int state_count = 1;
idle_fn idle_fns[CPUIDLE_STATE_MAX];
idle_fn *fns;
cpumask_t mask;
bool use_scm_power_down = false;
for (i = 0; ; i++) {
state_node = of_parse_phandle(cpu_node, "cpu-idle-states", i);
if (!state_node)
break;
if (!of_device_is_available(state_node))
continue;
if (i == CPUIDLE_STATE_MAX) {
pr_warn("%s: cpuidle states reached max possible\n",
__func__);
break;
}
match_id = of_match_node(qcom_idle_state_match, state_node);
if (!match_id)
return -ENODEV;
idle_fns[state_count] = match_id->data;
if (match_id->data == qcom_cpu_spc)
use_scm_power_down = true;
state_count++;
}
if (state_count == 1)
goto check_spm;
fns = devm_kcalloc(get_cpu_device(cpu), state_count, sizeof(*fns),
GFP_KERNEL);
if (!fns)
return -ENOMEM;
for (i = 1; i < state_count; i++)
fns[i] = idle_fns[i];
if (use_scm_power_down) {
cpumask_clear(&mask);
cpumask_set_cpu(cpu, &mask);
qcom_scm_set_warm_boot_addr(cpu_resume_arm, &mask);
}
per_cpu(qcom_idle_ops, cpu) = fns;
check_spm:
return per_cpu(cpu_spm_drv, cpu) ? 0 : -ENXIO;
}
static struct spm_driver_data *spm_get_drv(struct platform_device *pdev,
int *spm_cpu)
{
struct spm_driver_data *drv = NULL;
struct device_node *cpu_node, *saw_node;
int cpu;
bool found = 0;
for_each_possible_cpu(cpu) {
cpu_node = of_cpu_device_node_get(cpu);
if (!cpu_node)
continue;
saw_node = of_parse_phandle(cpu_node, "qcom,saw", 0);
found = (saw_node == pdev->dev.of_node);
of_node_put(saw_node);
of_node_put(cpu_node);
if (found)
break;
}
if (found) {
drv = devm_kzalloc(&pdev->dev, sizeof(*drv), GFP_KERNEL);
if (drv)
*spm_cpu = cpu;
}
return drv;
}
static int spm_dev_probe(struct platform_device *pdev)
{
struct spm_driver_data *drv;
struct resource *res;
const struct of_device_id *match_id;
void __iomem *addr;
int cpu;
drv = spm_get_drv(pdev, &cpu);
if (!drv)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
drv->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(drv->reg_base))
return PTR_ERR(drv->reg_base);
match_id = of_match_node(spm_match_table, pdev->dev.of_node);
if (!match_id)
return -ENODEV;
drv->reg_data = match_id->data;
addr = drv->reg_base + drv->reg_data->reg_offset[SPM_REG_SEQ_ENTRY];
__iowrite32_copy(addr, drv->reg_data->seq,
ARRAY_SIZE(drv->reg_data->seq) / 4);
spm_register_write(drv, SPM_REG_CFG, drv->reg_data->spm_cfg);
spm_register_write(drv, SPM_REG_DLY, drv->reg_data->spm_dly);
spm_register_write(drv, SPM_REG_PMIC_DLY, drv->reg_data->pmic_dly);
spm_register_write(drv, SPM_REG_PMIC_DATA_0,
drv->reg_data->pmic_data[0]);
spm_register_write(drv, SPM_REG_PMIC_DATA_1,
drv->reg_data->pmic_data[1]);
spm_set_low_power_mode(drv, PM_SLEEP_MODE_STBY);
per_cpu(cpu_spm_drv, cpu) = drv;
return 0;
}
