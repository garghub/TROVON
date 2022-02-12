void brcmf_debugfs_init(void)
{
root_folder = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (IS_ERR(root_folder))
root_folder = NULL;
}
void brcmf_debugfs_exit(void)
{
if (!root_folder)
return;
debugfs_remove_recursive(root_folder);
root_folder = NULL;
}
static int brcmf_debugfs_chipinfo_read(struct seq_file *seq, void *data)
{
struct brcmf_bus *bus = dev_get_drvdata(seq->private);
seq_printf(seq, "chip: %x(%u) rev %u\n",
bus->chip, bus->chip, bus->chiprev);
return 0;
}
int brcmf_debugfs_attach(struct brcmf_pub *drvr)
{
struct device *dev = drvr->bus_if->dev;
if (!root_folder)
return -ENODEV;
drvr->dbgfs_dir = debugfs_create_dir(dev_name(dev), root_folder);
brcmf_debugfs_add_entry(drvr, "chipinfo", brcmf_debugfs_chipinfo_read);
return PTR_ERR_OR_ZERO(drvr->dbgfs_dir);
}
void brcmf_debugfs_detach(struct brcmf_pub *drvr)
{
if (!IS_ERR_OR_NULL(drvr->dbgfs_dir))
debugfs_remove_recursive(drvr->dbgfs_dir);
}
struct dentry *brcmf_debugfs_get_devdir(struct brcmf_pub *drvr)
{
return drvr->dbgfs_dir;
}
static int brcmf_debugfs_entry_open(struct inode *inode, struct file *f)
{
struct brcmf_debugfs_entry *entry = inode->i_private;
return single_open(f, entry->read, entry->drvr->bus_if->dev);
}
int brcmf_debugfs_add_entry(struct brcmf_pub *drvr, const char *fn,
int (*read_fn)(struct seq_file *seq, void *data))
{
struct dentry *dentry = drvr->dbgfs_dir;
struct brcmf_debugfs_entry *entry;
if (IS_ERR_OR_NULL(dentry))
return -ENOENT;
entry = devm_kzalloc(drvr->bus_if->dev, sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->read = read_fn;
entry->drvr = drvr;
dentry = debugfs_create_file(fn, S_IRUGO, dentry, entry,
&brcmf_debugfs_def_ops);
return PTR_ERR_OR_ZERO(dentry);
}
