void iwmct_dbgfs_register(struct iwmct_priv *priv, const char *name)
{
struct iwmct_debugfs *dbgfs;
dbgfs = kzalloc(sizeof(struct iwmct_debugfs), GFP_KERNEL);
if (!dbgfs) {
LOG_ERROR(priv, DEBUGFS, "failed to allocate %zd bytes\n",
sizeof(struct iwmct_debugfs));
return;
}
priv->dbgfs = dbgfs;
dbgfs->name = name;
dbgfs->dir_drv = debugfs_create_dir(name, NULL);
if (!dbgfs->dir_drv) {
LOG_ERROR(priv, DEBUGFS, "failed to create debugfs dir\n");
return;
}
return;
}
void iwmct_dbgfs_unregister(struct iwmct_debugfs *dbgfs)
{
if (!dbgfs)
return;
DEBUGFS_RM(dbgfs->dir_drv);
kfree(dbgfs);
dbgfs = NULL;
}
