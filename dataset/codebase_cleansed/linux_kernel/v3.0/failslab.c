bool should_failslab(size_t size, gfp_t gfpflags, unsigned long cache_flags)
{
if (gfpflags & __GFP_NOFAIL)
return false;
if (failslab.ignore_gfp_wait && (gfpflags & __GFP_WAIT))
return false;
if (failslab.cache_filter && !(cache_flags & SLAB_FAILSLAB))
return false;
return should_fail(&failslab.attr, size);
}
static int __init setup_failslab(char *str)
{
return setup_fault_attr(&failslab.attr, str);
}
static int __init failslab_debugfs_init(void)
{
mode_t mode = S_IFREG | S_IRUSR | S_IWUSR;
struct dentry *dir;
int err;
err = init_fault_attr_dentries(&failslab.attr, "failslab");
if (err)
return err;
dir = failslab.attr.dentries.dir;
failslab.ignore_gfp_wait_file =
debugfs_create_bool("ignore-gfp-wait", mode, dir,
&failslab.ignore_gfp_wait);
failslab.cache_filter_file =
debugfs_create_bool("cache-filter", mode, dir,
&failslab.cache_filter);
if (!failslab.ignore_gfp_wait_file ||
!failslab.cache_filter_file) {
err = -ENOMEM;
debugfs_remove(failslab.cache_filter_file);
debugfs_remove(failslab.ignore_gfp_wait_file);
cleanup_fault_attr_dentries(&failslab.attr);
}
return err;
}
