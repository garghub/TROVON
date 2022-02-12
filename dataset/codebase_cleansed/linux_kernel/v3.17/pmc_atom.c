static inline u32 pmc_reg_read(struct pmc_dev *pmc, int reg_offset)
{
return readl(pmc->regmap + reg_offset);
}
static inline void pmc_reg_write(struct pmc_dev *pmc, int reg_offset, u32 val)
{
writel(val, pmc->regmap + reg_offset);
}
static void pmc_power_off(void)
{
u16 pm1_cnt_port;
u32 pm1_cnt_value;
pr_info("Preparing to enter system sleep state S5\n");
pm1_cnt_port = acpi_base_addr + PM1_CNT;
pm1_cnt_value = inl(pm1_cnt_port);
pm1_cnt_value &= SLEEP_TYPE_MASK;
pm1_cnt_value |= SLEEP_TYPE_S5;
pm1_cnt_value |= SLEEP_ENABLE;
outl(pm1_cnt_value, pm1_cnt_port);
}
static void pmc_hw_reg_setup(struct pmc_dev *pmc)
{
pmc_reg_write(pmc, PMC_S0IX_WAKE_EN, (u32)PMC_WAKE_EN_SETTING);
}
static int pmc_dev_state_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmc = s->private;
u32 func_dis, func_dis_2, func_dis_index;
u32 d3_sts_0, d3_sts_1, d3_sts_index;
int dev_num, dev_index, reg_index;
func_dis = pmc_reg_read(pmc, PMC_FUNC_DIS);
func_dis_2 = pmc_reg_read(pmc, PMC_FUNC_DIS_2);
d3_sts_0 = pmc_reg_read(pmc, PMC_D3_STS_0);
d3_sts_1 = pmc_reg_read(pmc, PMC_D3_STS_1);
dev_num = ARRAY_SIZE(dev_map);
for (dev_index = 0; dev_index < dev_num; dev_index++) {
reg_index = dev_index / PMC_REG_BIT_WIDTH;
if (reg_index) {
func_dis_index = func_dis_2;
d3_sts_index = d3_sts_1;
} else {
func_dis_index = func_dis;
d3_sts_index = d3_sts_0;
}
seq_printf(s, "Dev: %-32s\tState: %s [%s]\n",
dev_map[dev_index].name,
dev_map[dev_index].bit_mask & func_dis_index ?
"Disabled" : "Enabled ",
dev_map[dev_index].bit_mask & d3_sts_index ?
"D3" : "D0");
}
return 0;
}
static int pmc_dev_state_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_dev_state_show, inode->i_private);
}
static int pmc_sleep_tmr_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmc = s->private;
u64 s0ir_tmr, s0i1_tmr, s0i2_tmr, s0i3_tmr, s0_tmr;
s0ir_tmr = (u64)pmc_reg_read(pmc, PMC_S0IR_TMR) << PMC_TMR_SHIFT;
s0i1_tmr = (u64)pmc_reg_read(pmc, PMC_S0I1_TMR) << PMC_TMR_SHIFT;
s0i2_tmr = (u64)pmc_reg_read(pmc, PMC_S0I2_TMR) << PMC_TMR_SHIFT;
s0i3_tmr = (u64)pmc_reg_read(pmc, PMC_S0I3_TMR) << PMC_TMR_SHIFT;
s0_tmr = (u64)pmc_reg_read(pmc, PMC_S0_TMR) << PMC_TMR_SHIFT;
seq_printf(s, "S0IR Residency:\t%lldus\n", s0ir_tmr);
seq_printf(s, "S0I1 Residency:\t%lldus\n", s0i1_tmr);
seq_printf(s, "S0I2 Residency:\t%lldus\n", s0i2_tmr);
seq_printf(s, "S0I3 Residency:\t%lldus\n", s0i3_tmr);
seq_printf(s, "S0 Residency:\t%lldus\n", s0_tmr);
return 0;
}
static int pmc_sleep_tmr_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_sleep_tmr_show, inode->i_private);
}
static void pmc_dbgfs_unregister(struct pmc_dev *pmc)
{
if (!pmc->dbgfs_dir)
return;
debugfs_remove_recursive(pmc->dbgfs_dir);
pmc->dbgfs_dir = NULL;
}
static int pmc_dbgfs_register(struct pmc_dev *pmc, struct pci_dev *pdev)
{
struct dentry *dir, *f;
dir = debugfs_create_dir("pmc_atom", NULL);
if (!dir)
return -ENOMEM;
f = debugfs_create_file("dev_state", S_IFREG | S_IRUGO,
dir, pmc, &pmc_dev_state_ops);
if (!f) {
dev_err(&pdev->dev, "dev_states register failed\n");
goto err;
}
f = debugfs_create_file("sleep_state", S_IFREG | S_IRUGO,
dir, pmc, &pmc_sleep_tmr_ops);
if (!f) {
dev_err(&pdev->dev, "sleep_state register failed\n");
goto err;
}
pmc->dbgfs_dir = dir;
return 0;
err:
pmc_dbgfs_unregister(pmc);
return -ENODEV;
}
static int pmc_setup_dev(struct pci_dev *pdev)
{
struct pmc_dev *pmc = &pmc_device;
int ret;
pci_read_config_dword(pdev, ACPI_BASE_ADDR_OFFSET, &acpi_base_addr);
acpi_base_addr &= ACPI_BASE_ADDR_MASK;
if (acpi_base_addr != 0 && pm_power_off == NULL)
pm_power_off = pmc_power_off;
pci_read_config_dword(pdev, PMC_BASE_ADDR_OFFSET, &pmc->base_addr);
pmc->base_addr &= PMC_BASE_ADDR_MASK;
pmc->regmap = ioremap_nocache(pmc->base_addr, PMC_MMIO_REG_LEN);
if (!pmc->regmap) {
dev_err(&pdev->dev, "error: ioremap failed\n");
return -ENOMEM;
}
pmc_hw_reg_setup(pmc);
#ifdef CONFIG_DEBUG_FS
ret = pmc_dbgfs_register(pmc, pdev);
if (ret) {
iounmap(pmc->regmap);
return ret;
}
#endif
return 0;
}
static int __init pmc_atom_init(void)
{
int err = -ENODEV;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
for_each_pci_dev(pdev) {
ent = pci_match_id(pmc_pci_ids, pdev);
if (ent) {
err = pmc_setup_dev(pdev);
goto out;
}
}
out:
return err;
}
