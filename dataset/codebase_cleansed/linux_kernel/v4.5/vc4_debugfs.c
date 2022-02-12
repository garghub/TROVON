int
vc4_debugfs_init(struct drm_minor *minor)
{
return drm_debugfs_create_files(vc4_debugfs_list, VC4_DEBUGFS_ENTRIES,
minor->debugfs_root, minor);
}
void
vc4_debugfs_cleanup(struct drm_minor *minor)
{
drm_debugfs_remove_files(vc4_debugfs_list, VC4_DEBUGFS_ENTRIES, minor);
}
