static int livepatch_cmdline_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%s\n", "this has been live patched");
return 0;
}
static int livepatch_init(void)
{
int ret;
ret = klp_register_patch(&patch);
if (ret)
return ret;
ret = klp_enable_patch(&patch);
if (ret) {
WARN_ON(klp_unregister_patch(&patch));
return ret;
}
return 0;
}
static void livepatch_exit(void)
{
WARN_ON(klp_disable_patch(&patch));
WARN_ON(klp_unregister_patch(&patch));
}
