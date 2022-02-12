int\r\nvc4_debugfs_init(struct drm_minor *minor)\r\n{\r\nreturn drm_debugfs_create_files(vc4_debugfs_list, VC4_DEBUGFS_ENTRIES,\r\nminor->debugfs_root, minor);\r\n}
