static unsigned long kimage_addr_to_ra(const char *p)
{
unsigned long val = (unsigned long) p;
return kern_base + (val - KERNBASE);
}
static void do_set_sstate(unsigned long state, const char *msg)
{
unsigned long err;
if (!hv_supports_soft_state)
return;
err = sun4v_mach_set_soft_state(state, kimage_addr_to_ra(msg));
if (err) {
printk(KERN_WARNING "SSTATE: Failed to set soft-state to "
"state[%lx] msg[%s], err=%lu\n",
state, msg, err);
}
}
static int sstate_reboot_call(struct notifier_block *np, unsigned long type, void *_unused)
{
const char *msg;
switch (type) {
case SYS_DOWN:
default:
msg = rebooting_msg;
break;
case SYS_HALT:
msg = halting_msg;
break;
case SYS_POWER_OFF:
msg = poweroff_msg;
break;
}
do_set_sstate(HV_SOFT_STATE_TRANSITION, msg);
return NOTIFY_OK;
}
static int sstate_panic_event(struct notifier_block *n, unsigned long event, void *ptr)
{
do_set_sstate(HV_SOFT_STATE_TRANSITION, panicing_msg);
return NOTIFY_DONE;
}
static int __init sstate_init(void)
{
unsigned long major, minor;
if (tlb_type != hypervisor)
return 0;
major = 1;
minor = 0;
if (sun4v_hvapi_register(HV_GRP_SOFT_STATE, major, &minor))
return 0;
hv_supports_soft_state = 1;
prom_sun4v_guest_soft_state();
do_set_sstate(HV_SOFT_STATE_TRANSITION, booting_msg);
atomic_notifier_chain_register(&panic_notifier_list,
&sstate_panic_block);
register_reboot_notifier(&sstate_reboot_notifier);
return 0;
}
static int __init sstate_running(void)
{
do_set_sstate(HV_SOFT_STATE_NORMAL, running_msg);
return 0;
}
