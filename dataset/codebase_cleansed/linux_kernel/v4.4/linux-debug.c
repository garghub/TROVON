void libcfs_run_debug_log_upcall(char *file)
{
char *argv[3];
int rc;
char *envp[] = {
"HOME=/",
"PATH=/sbin:/bin:/usr/sbin:/usr/bin",
NULL};
argv[0] = lnet_debug_log_upcall;
LASSERTF(file != NULL, "called on a null filename\n");
argv[1] = file;
argv[2] = NULL;
rc = call_usermodehelper(argv[0], argv, envp, 1);
if (rc < 0 && rc != -ENOENT) {
CERROR("Error %d invoking LNET debug log upcall %s %s; check /proc/sys/lnet/debug_log_upcall\n",
rc, argv[0], argv[1]);
} else {
CDEBUG(D_HA, "Invoked LNET debug log upcall %s %s\n",
argv[0], argv[1]);
}
}
void libcfs_run_upcall(char **argv)
{
int rc;
int argc;
char *envp[] = {
"HOME=/",
"PATH=/sbin:/bin:/usr/sbin:/usr/bin",
NULL};
argv[0] = lnet_upcall;
argc = 1;
while (argv[argc] != NULL)
argc++;
LASSERT(argc >= 2);
rc = call_usermodehelper(argv[0], argv, envp, 1);
if (rc < 0 && rc != -ENOENT) {
CERROR("Error %d invoking LNET upcall %s %s%s%s%s%s%s%s%s; check /proc/sys/lnet/upcall\n",
rc, argv[0], argv[1],
argc < 3 ? "" : ",", argc < 3 ? "" : argv[2],
argc < 4 ? "" : ",", argc < 4 ? "" : argv[3],
argc < 5 ? "" : ",", argc < 5 ? "" : argv[4],
argc < 6 ? "" : ",...");
} else {
CDEBUG(D_HA, "Invoked LNET upcall %s %s%s%s%s%s%s%s%s\n",
argv[0], argv[1],
argc < 3 ? "" : ",", argc < 3 ? "" : argv[2],
argc < 4 ? "" : ",", argc < 4 ? "" : argv[3],
argc < 5 ? "" : ",", argc < 5 ? "" : argv[4],
argc < 6 ? "" : ",...");
}
}
void libcfs_run_lbug_upcall(struct libcfs_debug_msg_data *msgdata)
{
char *argv[6];
char buf[32];
snprintf(buf, sizeof(buf), "%d", msgdata->msg_line);
argv[1] = "LBUG";
argv[2] = (char *)msgdata->msg_file;
argv[3] = (char *)msgdata->msg_fn;
argv[4] = buf;
argv[5] = NULL;
libcfs_run_upcall (argv);
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
libcfs_run_lbug_upcall(msgdata);
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
atomic_notifier_chain_register(&panic_notifier_list, &libcfs_panic_notifier);
}
void libcfs_unregister_panic_notifier(void)
{
atomic_notifier_chain_unregister(&panic_notifier_list, &libcfs_panic_notifier);
}
