static void ip27_machine_restart(char *command)
{
#if 0
int i;
#endif
printk("Reboot started from CPU %d\n", smp_processor_id());
#ifdef CONFIG_SMP
smp_send_stop();
#endif
#if 0
for_each_online_node(i)
REMOTE_HUB_S(COMPACT_TO_NASID_NODEID(i), PROMOP_REG,
PROMOP_REBOOT);
#else
LOCAL_HUB_S(NI_PORT_RESET, NPR_PORTRESET | NPR_LOCALRESET);
#endif
noreturn;
}
static void ip27_machine_halt(void)
{
int i;
#ifdef CONFIG_SMP
smp_send_stop();
#endif
for_each_online_node(i)
REMOTE_HUB_S(COMPACT_TO_NASID_NODEID(i), PROMOP_REG,
PROMOP_RESTART);
LOCAL_HUB_S(NI_PORT_RESET, NPR_PORTRESET | NPR_LOCALRESET);
noreturn;
}
static void ip27_machine_power_off(void)
{
noreturn;
}
void ip27_reboot_setup(void)
{
_machine_restart = ip27_machine_restart;
_machine_halt = ip27_machine_halt;
pm_power_off = ip27_machine_power_off;
}
