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
int brcmf_debugfs_attach(struct brcmf_pub *drvr)
{
struct device *dev = drvr->bus_if->dev;
if (!root_folder)
return -ENODEV;
drvr->dbgfs_dir = debugfs_create_dir(dev_name(dev), root_folder);
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
int brcmf_debugfs_add_entry(struct brcmf_pub *drvr, const char *fn,
int (*read_fn)(struct seq_file *seq, void *data))
{
struct dentry *e;
e = debugfs_create_devm_seqfile(drvr->bus_if->dev, fn,
drvr->dbgfs_dir, read_fn);
return PTR_ERR_OR_ZERO(e);
}
