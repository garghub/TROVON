void c8sectpfe_debugfs_init(struct c8sectpfei *fei)
{
struct dentry *root;
struct dentry *file;
root = debugfs_create_dir("c8sectpfe", NULL);
if (!root)
goto err;
fei->root = root;
fei->regset = devm_kzalloc(fei->dev, sizeof(*fei->regset), GFP_KERNEL);
if (!fei->regset)
goto err;
fei->regset->regs = fei_sys_regs;
fei->regset->nregs = ARRAY_SIZE(fei_sys_regs);
fei->regset->base = fei->io;
file = debugfs_create_regset32("registers", S_IRUGO, root,
fei->regset);
if (!file) {
dev_err(fei->dev,
"%s not able to create 'registers' debugfs\n"
, __func__);
goto err;
}
return;
err:
debugfs_remove_recursive(root);
}
void c8sectpfe_debugfs_exit(struct c8sectpfei *fei)
{
debugfs_remove_recursive(fei->root);
fei->root = NULL;
}
