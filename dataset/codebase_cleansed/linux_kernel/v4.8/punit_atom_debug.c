static int punit_dev_state_show(struct seq_file *seq_file, void *unused)
{
u32 punit_pwr_status;
struct punit_device *punit_devp = seq_file->private;
int index;
int status;
seq_puts(seq_file, "\n\nPUNIT NORTH COMPLEX DEVICES :\n");
while (punit_devp->name) {
status = iosf_mbi_read(BT_MBI_UNIT_PMC, MBI_REG_READ,
punit_devp->reg, &punit_pwr_status);
if (status) {
seq_printf(seq_file, "%9s : Read Failed\n",
punit_devp->name);
} else {
index = (punit_pwr_status >> punit_devp->sss_pos) & 3;
seq_printf(seq_file, "%9s : %s\n", punit_devp->name,
dstates[index]);
}
punit_devp++;
}
return 0;
}
static int punit_dev_state_open(struct inode *inode, struct file *file)
{
return single_open(file, punit_dev_state_show, inode->i_private);
}
static int punit_dbgfs_register(struct punit_device *punit_device)
{
static struct dentry *dev_state;
punit_dbg_file = debugfs_create_dir("punit_atom", NULL);
if (!punit_dbg_file)
return -ENXIO;
dev_state = debugfs_create_file("dev_power_state", S_IFREG | S_IRUGO,
punit_dbg_file, punit_device,
&punit_dev_state_ops);
if (!dev_state) {
pr_err("punit_dev_state register failed\n");
debugfs_remove(punit_dbg_file);
return -ENXIO;
}
return 0;
}
static void punit_dbgfs_unregister(void)
{
debugfs_remove_recursive(punit_dbg_file);
}
static int __init punit_atom_debug_init(void)
{
const struct x86_cpu_id *id;
int ret;
id = x86_match_cpu(intel_punit_cpu_ids);
if (!id)
return -ENODEV;
ret = punit_dbgfs_register((struct punit_device *)id->driver_data);
if (ret < 0)
return ret;
return 0;
}
static void __exit punit_atom_debug_exit(void)
{
punit_dbgfs_unregister();
}
