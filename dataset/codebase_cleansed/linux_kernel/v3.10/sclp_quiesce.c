static void do_machine_quiesce(void)
{
psw_t quiesce_psw;
smp_send_stop();
quiesce_psw.mask =
PSW_MASK_BASE | PSW_MASK_EA | PSW_MASK_BA | PSW_MASK_WAIT;
quiesce_psw.addr = 0xfff;
__load_psw(quiesce_psw);
}
static void sclp_quiesce_handler(struct evbuf_header *evbuf)
{
if (_machine_restart != (void *) do_machine_quiesce) {
old_machine_restart = _machine_restart;
old_machine_halt = _machine_halt;
old_machine_power_off = _machine_power_off;
_machine_restart = (void *) do_machine_quiesce;
_machine_halt = do_machine_quiesce;
_machine_power_off = do_machine_quiesce;
}
ctrl_alt_del();
}
static void sclp_quiesce_pm_event(struct sclp_register *reg,
enum sclp_pm_event sclp_pm_event)
{
switch (sclp_pm_event) {
case SCLP_PM_EVENT_RESTORE:
if (old_machine_restart) {
_machine_restart = old_machine_restart;
_machine_halt = old_machine_halt;
_machine_power_off = old_machine_power_off;
old_machine_restart = NULL;
old_machine_halt = NULL;
old_machine_power_off = NULL;
}
break;
case SCLP_PM_EVENT_FREEZE:
case SCLP_PM_EVENT_THAW:
break;
}
}
static int __init sclp_quiesce_init(void)
{
return sclp_register(&sclp_quiesce_event);
}
