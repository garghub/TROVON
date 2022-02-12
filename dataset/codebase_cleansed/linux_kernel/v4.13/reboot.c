void emergency_restart(void)
{
kmsg_dump(KMSG_DUMP_EMERG);
machine_emergency_restart();
}
void kernel_restart_prepare(char *cmd)
{
blocking_notifier_call_chain(&reboot_notifier_list, SYS_RESTART, cmd);
system_state = SYSTEM_RESTART;
usermodehelper_disable();
device_shutdown();
}
int register_reboot_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&reboot_notifier_list, nb);
}
int unregister_reboot_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&reboot_notifier_list, nb);
}
int register_restart_handler(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&restart_handler_list, nb);
}
int unregister_restart_handler(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&restart_handler_list, nb);
}
void do_kernel_restart(char *cmd)
{
atomic_notifier_call_chain(&restart_handler_list, reboot_mode, cmd);
}
void migrate_to_reboot_cpu(void)
{
int cpu = reboot_cpu;
cpu_hotplug_disable();
if (!cpu_online(cpu))
cpu = cpumask_first(cpu_online_mask);
current->flags |= PF_NO_SETAFFINITY;
set_cpus_allowed_ptr(current, cpumask_of(cpu));
}
void kernel_restart(char *cmd)
{
kernel_restart_prepare(cmd);
migrate_to_reboot_cpu();
syscore_shutdown();
if (!cmd)
pr_emerg("Restarting system\n");
else
pr_emerg("Restarting system with command '%s'\n", cmd);
kmsg_dump(KMSG_DUMP_RESTART);
machine_restart(cmd);
}
static void kernel_shutdown_prepare(enum system_states state)
{
blocking_notifier_call_chain(&reboot_notifier_list,
(state == SYSTEM_HALT) ? SYS_HALT : SYS_POWER_OFF, NULL);
system_state = state;
usermodehelper_disable();
device_shutdown();
}
void kernel_halt(void)
{
kernel_shutdown_prepare(SYSTEM_HALT);
migrate_to_reboot_cpu();
syscore_shutdown();
pr_emerg("System halted\n");
kmsg_dump(KMSG_DUMP_HALT);
machine_halt();
}
void kernel_power_off(void)
{
kernel_shutdown_prepare(SYSTEM_POWER_OFF);
if (pm_power_off_prepare)
pm_power_off_prepare();
migrate_to_reboot_cpu();
syscore_shutdown();
pr_emerg("Power down\n");
kmsg_dump(KMSG_DUMP_POWEROFF);
machine_power_off();
}
static void deferred_cad(struct work_struct *dummy)
{
kernel_restart(NULL);
}
void ctrl_alt_del(void)
{
static DECLARE_WORK(cad_work, deferred_cad);
if (C_A_D)
schedule_work(&cad_work);
else
kill_cad_pid(SIGINT, 1);
}
static int run_cmd(const char *cmd)
{
char **argv;
static char *envp[] = {
"HOME=/",
"PATH=/sbin:/bin:/usr/sbin:/usr/bin",
NULL
};
int ret;
argv = argv_split(GFP_KERNEL, cmd, NULL);
if (argv) {
ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
argv_free(argv);
} else {
ret = -ENOMEM;
}
return ret;
}
static int __orderly_reboot(void)
{
int ret;
ret = run_cmd(reboot_cmd);
if (ret) {
pr_warn("Failed to start orderly reboot: forcing the issue\n");
emergency_sync();
kernel_restart(NULL);
}
return ret;
}
static int __orderly_poweroff(bool force)
{
int ret;
ret = run_cmd(poweroff_cmd);
if (ret && force) {
pr_warn("Failed to start orderly shutdown: forcing the issue\n");
emergency_sync();
kernel_power_off();
}
return ret;
}
static void poweroff_work_func(struct work_struct *work)
{
__orderly_poweroff(poweroff_force);
}
void orderly_poweroff(bool force)
{
if (force)
poweroff_force = true;
schedule_work(&poweroff_work);
}
static void reboot_work_func(struct work_struct *work)
{
__orderly_reboot();
}
void orderly_reboot(void)
{
schedule_work(&reboot_work);
}
static int __init reboot_setup(char *str)
{
for (;;) {
reboot_default = 0;
switch (*str) {
case 'w':
reboot_mode = REBOOT_WARM;
break;
case 'c':
reboot_mode = REBOOT_COLD;
break;
case 'h':
reboot_mode = REBOOT_HARD;
break;
case 's':
{
int rc;
if (isdigit(*(str+1))) {
rc = kstrtoint(str+1, 0, &reboot_cpu);
if (rc)
return rc;
} else if (str[1] == 'm' && str[2] == 'p' &&
isdigit(*(str+3))) {
rc = kstrtoint(str+3, 0, &reboot_cpu);
if (rc)
return rc;
} else
reboot_mode = REBOOT_SOFT;
break;
}
case 'g':
reboot_mode = REBOOT_GPIO;
break;
case 'b':
case 'a':
case 'k':
case 't':
case 'e':
case 'p':
reboot_type = *str;
break;
case 'f':
reboot_force = 1;
break;
}
str = strchr(str, ',');
if (str)
str++;
else
break;
}
return 1;
}
