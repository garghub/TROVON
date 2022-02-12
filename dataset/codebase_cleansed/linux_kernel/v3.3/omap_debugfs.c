int omap_debugfs_init(struct drm_minor *minor)
{
return drm_debugfs_create_files(omap_debugfs_list,
ARRAY_SIZE(omap_debugfs_list),
minor->debugfs_root, minor);
}
void omap_debugfs_cleanup(struct drm_minor *minor)
{
drm_debugfs_remove_files(omap_debugfs_list,
ARRAY_SIZE(omap_debugfs_list), minor);
}
