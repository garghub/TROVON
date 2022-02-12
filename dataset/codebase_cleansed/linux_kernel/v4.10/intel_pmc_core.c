static inline u8 pmc_core_reg_read_byte(struct pmc_dev *pmcdev, int offset)
{
return readb(pmcdev->regbase + offset);
}
static inline u32 pmc_core_reg_read(struct pmc_dev *pmcdev, int reg_offset)
{
return readl(pmcdev->regbase + reg_offset);
}
static inline void pmc_core_reg_write(struct pmc_dev *pmcdev, int
reg_offset, u32 val)
{
writel(val, pmcdev->regbase + reg_offset);
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
static int pmc_core_dev_state_get(void *data, u64 *val)
{
struct pmc_dev *pmcdev = data;
u32 value;
value = pmc_core_reg_read(pmcdev, SPT_PMC_SLP_S0_RES_COUNTER_OFFSET);
*val = pmc_core_adjust_slp_s0_step(value);
return 0;
}
static int pmc_core_check_read_lock_bit(void)
{
struct pmc_dev *pmcdev = &pmc;
u32 value;
value = pmc_core_reg_read(pmcdev, SPT_PMC_PM_CFG_OFFSET);
return test_bit(SPT_PMC_READ_DISABLE_BIT,
(unsigned long *)&value);
}
static void pmc_core_display_map(struct seq_file *s, int index,
u8 pf_reg, const struct pmc_bit_map *pf_map)
{
seq_printf(s, "PCH IP: %-2d - %-32s\tState: %s\n",
index, pf_map[index].name,
pf_map[index].bit_mask & pf_reg ? "Off" : "On");
}
static int pmc_core_ppfear_sts_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmcdev = s->private;
const struct pmc_bit_map *map = pmcdev->map->pfear_sts;
u8 pf_regs[NUM_ENTRIES];
int index, iter;
iter = SPT_PMC_XRAM_PPFEAR0A;
for (index = 0; index < NUM_ENTRIES; index++, iter++)
pf_regs[index] = pmc_core_reg_read_byte(pmcdev, iter);
for (index = 0; map[index].name; index++)
pmc_core_display_map(s, index, pf_regs[index / 8], map);
return 0;
}
static int pmc_core_ppfear_sts_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_core_ppfear_sts_show, inode->i_private);
}
static int pmc_core_mtpmc_link_status(void)
{
struct pmc_dev *pmcdev = &pmc;
u32 value;
value = pmc_core_reg_read(pmcdev, SPT_PMC_PM_STS_OFFSET);
return test_bit(SPT_PMC_MSG_FULL_STS_BIT,
(unsigned long *)&value);
}
static int pmc_core_send_msg(u32 *addr_xram)
{
struct pmc_dev *pmcdev = &pmc;
u32 dest;
int timeout;
for (timeout = NUM_RETRIES; timeout > 0; timeout--) {
if (pmc_core_mtpmc_link_status() == 0)
break;
msleep(5);
}
if (timeout <= 0 && pmc_core_mtpmc_link_status())
return -EBUSY;
dest = (*addr_xram & MTPMC_MASK) | (1U << 1);
pmc_core_reg_write(pmcdev, SPT_PMC_MTPMC_OFFSET, dest);
return 0;
}
static int pmc_core_mphy_pg_sts_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmcdev = s->private;
const struct pmc_bit_map *map = pmcdev->map->mphy_sts;
u32 mphy_core_reg_low, mphy_core_reg_high;
u32 val_low, val_high;
int index, err = 0;
if (pmcdev->pmc_xram_read_bit) {
seq_puts(s, "Access denied: please disable PMC_READ_DISABLE setting in BIOS.");
return 0;
}
mphy_core_reg_low = (SPT_PMC_MPHY_CORE_STS_0 << 16);
mphy_core_reg_high = (SPT_PMC_MPHY_CORE_STS_1 << 16);
mutex_lock(&pmcdev->lock);
if (pmc_core_send_msg(&mphy_core_reg_low) != 0) {
err = -EBUSY;
goto out_unlock;
}
msleep(10);
val_low = pmc_core_reg_read(pmcdev, SPT_PMC_MFPMC_OFFSET);
if (pmc_core_send_msg(&mphy_core_reg_high) != 0) {
err = -EBUSY;
goto out_unlock;
}
msleep(10);
val_high = pmc_core_reg_read(pmcdev, SPT_PMC_MFPMC_OFFSET);
for (index = 0; map[index].name && index < 8; index++) {
seq_printf(s, "%-32s\tState: %s\n",
map[index].name,
map[index].bit_mask & val_low ? "Not power gated" :
"Power gated");
}
for (index = 8; map[index].name; index++) {
seq_printf(s, "%-32s\tState: %s\n",
map[index].name,
map[index].bit_mask & val_high ? "Not power gated" :
"Power gated");
}
out_unlock:
mutex_unlock(&pmcdev->lock);
return err;
}
static int pmc_core_mphy_pg_sts_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_core_mphy_pg_sts_show, inode->i_private);
}
static int pmc_core_pll_show(struct seq_file *s, void *unused)
{
struct pmc_dev *pmcdev = s->private;
const struct pmc_bit_map *map = pmcdev->map->pll_sts;
u32 mphy_common_reg, val;
int index, err = 0;
if (pmcdev->pmc_xram_read_bit) {
seq_puts(s, "Access denied: please disable PMC_READ_DISABLE setting in BIOS.");
return 0;
}
mphy_common_reg = (SPT_PMC_MPHY_COM_STS_0 << 16);
mutex_lock(&pmcdev->lock);
if (pmc_core_send_msg(&mphy_common_reg) != 0) {
err = -EBUSY;
goto out_unlock;
}
msleep(10);
val = pmc_core_reg_read(pmcdev, SPT_PMC_MFPMC_OFFSET);
for (index = 0; map[index].name ; index++) {
seq_printf(s, "%-32s\tState: %s\n",
map[index].name,
map[index].bit_mask & val ? "Active" : "Idle");
}
out_unlock:
mutex_unlock(&pmcdev->lock);
return err;
}
static int pmc_core_pll_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_core_pll_show, inode->i_private);
}
static ssize_t pmc_core_ltr_ignore_write(struct file *file, const char __user
*userbuf, size_t count, loff_t *ppos)
{
struct pmc_dev *pmcdev = &pmc;
u32 val, buf_size, fd;
int err = 0;
buf_size = count < 64 ? count : 64;
mutex_lock(&pmcdev->lock);
if (kstrtou32_from_user(userbuf, buf_size, 10, &val)) {
err = -EFAULT;
goto out_unlock;
}
if (val > NUM_IP_IGN_ALLOWED) {
err = -EINVAL;
goto out_unlock;
}
fd = pmc_core_reg_read(pmcdev, SPT_PMC_LTR_IGNORE_OFFSET);
fd |= (1U << val);
pmc_core_reg_write(pmcdev, SPT_PMC_LTR_IGNORE_OFFSET, fd);
out_unlock:
mutex_unlock(&pmcdev->lock);
return err == 0 ? count : err;
}
static int pmc_core_ltr_ignore_show(struct seq_file *s, void *unused)
{
return 0;
}
static int pmc_core_ltr_ignore_open(struct inode *inode, struct file *file)
{
return single_open(file, pmc_core_ltr_ignore_show, inode->i_private);
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
dir, pmcdev, &pmc_core_dev_state);
if (!file)
goto err;
file = debugfs_create_file("pch_ip_power_gating_status",
S_IFREG | S_IRUGO, dir, pmcdev,
&pmc_core_ppfear_ops);
if (!file)
goto err;
file = debugfs_create_file("mphy_core_lanes_power_gating_status",
S_IFREG | S_IRUGO, dir, pmcdev,
&pmc_core_mphy_pg_ops);
if (!file)
goto err;
file = debugfs_create_file("pll_status",
S_IFREG | S_IRUGO, dir, pmcdev,
&pmc_core_pll_ops);
if (!file)
goto err;
file = debugfs_create_file("ltr_ignore",
S_IFREG | S_IRUGO, dir, pmcdev,
&pmc_core_ltr_ignore_ops);
if (!file)
goto err;
return 0;
err:
pmc_core_dbgfs_unregister(pmcdev);
return -ENODEV;
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
const struct pmc_reg_map *map = (struct pmc_reg_map *)id->driver_data;
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
pmcdev->base_addr &= PMC_BASE_ADDR_MASK;
dev_dbg(&dev->dev, "PMC Core: PWRMBASE is %#x\n", pmcdev->base_addr);
pmcdev->regbase = devm_ioremap_nocache(ptr_dev,
pmcdev->base_addr,
SPT_PMC_MMIO_REG_LEN);
if (!pmcdev->regbase) {
dev_dbg(&dev->dev, "PMC Core: ioremap failed.\n");
return -ENOMEM;
}
mutex_init(&pmcdev->lock);
pmcdev->pmc_xram_read_bit = pmc_core_check_read_lock_bit();
pmcdev->map = map;
err = pmc_core_dbgfs_register(pmcdev);
if (err < 0)
dev_warn(&dev->dev, "PMC Core: debugfs register failed.\n");
pmc.has_slp_s0_res = true;
return 0;
}
