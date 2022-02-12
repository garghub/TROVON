static inline u32 pmc_core_reg_read(struct pmc_dev *pmcdev, int reg_offset)
{
return readl(pmcdev->regbase + reg_offset);
}
static inline u32 pmc_core_adjust_slp_s0_step(u32 value)
{
return value * SPT_PMC_SLP_S0_RES_COUNTER_STEP;
}
int intel_pmc_slp_s0_counter_read(u32 *data)
{
struct pmc_dev *pmcdev = &pmc;
u32 value;
if (!pmcdev->has_slp_s0_res)
return -EACCES;
value = pmc_core_reg_read(pmcdev, SPT_PMC_SLP_S0_RES_COUNTER_OFFSET);
*data = pmc_core_adjust_slp_s0_step(value);
return 0;
}
static int pmc_core_dev_state_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmcdev = s->private;
u32 counter_val;
counter_val = pmc_core_reg_read(pmcdev,
SPT_PMC_SLP_S0_RES_COUNTER_OFFSET);
seq_printf(s, "%u\n", pmc_core_adjust_slp_s0_step(counter_val));
return 0;
}
static int pmc_core_dev_state_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_core_dev_state_show, inode->i_private);
}
static void pmc_core_dbgfs_unregister(struct pmc_dev *pmcdev)
{
debugfs_remove_recursive(pmcdev->dbgfs_dir);
}
static int pmc_core_dbgfs_register(struct pmc_dev *pmcdev)
{
struct dentry *dir, *file;
dir = debugfs_create_dir("pmc_core", NULL);
if (!dir)
return -ENOMEM;
pmcdev->dbgfs_dir = dir;
file = debugfs_create_file("slp_s0_residency_usec", S_IFREG | S_IRUGO,
dir, pmcdev, &pmc_core_dev_state_ops);
if (!file) {
pmc_core_dbgfs_unregister(pmcdev);
return -ENODEV;
}
return 0;
}
static inline int pmc_core_dbgfs_register(struct pmc_dev *pmcdev)
{
return 0;
}
static inline void pmc_core_dbgfs_unregister(struct pmc_dev *pmcdev)
{
}
static int pmc_core_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct device *ptr_dev = &dev->dev;
struct pmc_dev *pmcdev = &pmc;
const struct x86_cpu_id *cpu_id;
int err;
cpu_id = x86_match_cpu(intel_pmc_core_ids);
if (!cpu_id) {
dev_dbg(&dev->dev, "PMC Core: cpuid mismatch.\n");
return -EINVAL;
}
err = pcim_enable_device(dev);
if (err < 0) {
dev_dbg(&dev->dev, "PMC Core: failed to enable Power Management Controller.\n");
return err;
}
err = pci_read_config_dword(dev,
SPT_PMC_BASE_ADDR_OFFSET,
&pmcdev->base_addr);
if (err < 0) {
dev_dbg(&dev->dev, "PMC Core: failed to read PCI config space.\n");
return err;
}
dev_dbg(&dev->dev, "PMC Core: PWRMBASE is %#x\n", pmcdev->base_addr);
pmcdev->regbase = devm_ioremap_nocache(ptr_dev,
pmcdev->base_addr,
SPT_PMC_MMIO_REG_LEN);
if (!pmcdev->regbase) {
dev_dbg(&dev->dev, "PMC Core: ioremap failed.\n");
return -ENOMEM;
}
err = pmc_core_dbgfs_register(pmcdev);
if (err < 0) {
dev_err(&dev->dev, "PMC Core: debugfs register failed.\n");
return err;
}
pmc.has_slp_s0_res = true;
return 0;
}
