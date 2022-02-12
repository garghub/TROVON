void libcfs_run_debug_log_upcall(char *file)
{
char *argv[3];
int rc;
static const char * const envp[] = {
"HOME=/",
"PATH=/sbin:/bin:/usr/sbin:/usr/bin",
NULL
};
argv[0] = lnet_debug_log_upcall;
LASSERTF(file, "called on a null filename\n");
argv[1] = file;
argv[2] = NULL;
rc = call_usermodehelper(argv[0], argv, (char **)envp, 1);
if (rc < 0 && rc != -ENOENT) {
CERROR("Error %d invoking LNET debug log upcall %s %s; check /sys/kernel/debug/lnet/debug_log_upcall\n",
rc, argv[0], argv[1]);
} else {
CDEBUG(D_HA, "Invoked LNET debug log upcall %s %s\n",
argv[0], argv[1]);
}
}
void __noreturn lbug_with_loc(struct libcfs_debug_msg_data *msgdata)
{
libcfs_catastrophe = 1;
libcfs_debug_msg(msgdata, "LBUG\n");
if (in_interrupt()) {
panic("LBUG in interrupt.\n");
}
dump_stack();
if (!libcfs_panic_on_lbug)
libcfs_debug_dumplog();
if (libcfs_panic_on_lbug)
panic("LBUG");
set_task_state(current, TASK_UNINTERRUPTIBLE);
while (1)
schedule();
}
static int panic_notifier(struct notifier_block *self, unsigned long unused1,
void *unused2)
{
if (libcfs_panic_in_progress)
return 0;
libcfs_panic_in_progress = 1;
mb();
return 0;
}
void libcfs_register_panic_notifier(void)
{
atomic_notifier_chain_register(&panic_notifier_list,
&libcfs_panic_notifier);
}
void libcfs_unregister_panic_notifier(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list,
&libcfs_panic_notifier);
}
