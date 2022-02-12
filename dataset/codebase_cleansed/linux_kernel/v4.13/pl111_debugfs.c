int pl111_debugfs_regs(struct seq_file *m, void *unused)
{
struct drm_info_node *node = (struct drm_info_node *)m->private;
struct drm_device *dev = node->minor->dev;
struct pl111_drm_dev_private *priv = dev->dev_private;
int i;
for (i = 0; i < ARRAY_SIZE(pl111_reg_defs); i++) {
seq_printf(m, "%s (0x%04x): 0x%08x\n",
pl111_reg_defs[i].name, pl111_reg_defs[i].reg,
readl(priv->regs + pl111_reg_defs[i].reg));
}
return 0;
}
int
pl111_debugfs_init(struct drm_minor *minor)
{
return drm_debugfs_create_files(pl111_debugfs_list,
ARRAY_SIZE(pl111_debugfs_list),
minor->debugfs_root, minor);
}
