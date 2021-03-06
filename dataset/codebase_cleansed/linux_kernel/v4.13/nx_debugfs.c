int nx_debugfs_init(struct nx_crypto_driver *drv)
{
struct nx_debugfs *dfs = &drv->dfs;
dfs->dfs_root = debugfs_create_dir(NX_NAME, NULL);
dfs->dfs_aes_ops =
debugfs_create_u32("aes_ops",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root, (u32 *)&drv->stats.aes_ops);
dfs->dfs_sha256_ops =
debugfs_create_u32("sha256_ops",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u32 *)&drv->stats.sha256_ops);
dfs->dfs_sha512_ops =
debugfs_create_u32("sha512_ops",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u32 *)&drv->stats.sha512_ops);
dfs->dfs_aes_bytes =
debugfs_create_u64("aes_bytes",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u64 *)&drv->stats.aes_bytes);
dfs->dfs_sha256_bytes =
debugfs_create_u64("sha256_bytes",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u64 *)&drv->stats.sha256_bytes);
dfs->dfs_sha512_bytes =
debugfs_create_u64("sha512_bytes",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u64 *)&drv->stats.sha512_bytes);
dfs->dfs_errors =
debugfs_create_u32("errors",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root, (u32 *)&drv->stats.errors);
dfs->dfs_last_error =
debugfs_create_u32("last_error",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u32 *)&drv->stats.last_error);
dfs->dfs_last_error_pid =
debugfs_create_u32("last_error_pid",
S_IRUSR | S_IRGRP | S_IROTH,
dfs->dfs_root,
(u32 *)&drv->stats.last_error_pid);
return 0;
}
void
nx_debugfs_fini(struct nx_crypto_driver *drv)
{
debugfs_remove_recursive(drv->dfs.dfs_root);
}
