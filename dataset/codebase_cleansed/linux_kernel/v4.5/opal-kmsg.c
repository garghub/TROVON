static void force_opal_console_flush(struct kmsg_dumper *dumper,
enum kmsg_dump_reason reason)
{
int i;
int64_t ret;
if (reason != KMSG_DUMP_PANIC)
return;
if (opal_check_token(OPAL_CONSOLE_FLUSH)) {
ret = opal_console_flush(0);
if (ret == OPAL_UNSUPPORTED || ret == OPAL_PARAMETER)
return;
while (opal_console_flush(0) != OPAL_SUCCESS);
} else {
printk(KERN_NOTICE "opal: OPAL_CONSOLE_FLUSH missing.\n");
for (i = 0; i < 1024; i++) {
opal_poll_events(NULL);
}
}
}
void __init opal_kmsg_init(void)
{
int rc;
rc = kmsg_dump_register(&opal_kmsg_dumper);
if (rc != 0)
pr_err("opal: kmsg_dump_register failed; returned %d\n", rc);
}
