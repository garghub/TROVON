static int __init hangcheck_parse_tick(char *str)
{
int par;
if (get_option(&str,&par))
hangcheck_tick = par;
return 1;
}
static int __init hangcheck_parse_margin(char *str)
{
int par;
if (get_option(&str,&par))
hangcheck_margin = par;
return 1;
}
static int __init hangcheck_parse_reboot(char *str)
{
int par;
if (get_option(&str,&par))
hangcheck_reboot = par;
return 1;
}
static int __init hangcheck_parse_dump_tasks(char *str)
{
int par;
if (get_option(&str,&par))
hangcheck_dump_tasks = par;
return 1;
}
static inline unsigned long long monotonic_clock(void)
{
struct timespec ts;
getrawmonotonic(&ts);
return timespec_to_ns(&ts);
}
static void hangcheck_fire(unsigned long data)
{
unsigned long long cur_tsc, tsc_diff;
cur_tsc = monotonic_clock();
if (cur_tsc > hangcheck_tsc)
tsc_diff = cur_tsc - hangcheck_tsc;
else
tsc_diff = (cur_tsc + (~0ULL - hangcheck_tsc));
if (tsc_diff > hangcheck_tsc_margin) {
if (hangcheck_dump_tasks) {
printk(KERN_CRIT "Hangcheck: Task state:\n");
#ifdef CONFIG_MAGIC_SYSRQ
handle_sysrq('t');
#endif
}
if (hangcheck_reboot) {
printk(KERN_CRIT "Hangcheck: hangcheck is restarting the machine.\n");
emergency_restart();
} else {
printk(KERN_CRIT "Hangcheck: hangcheck value past margin!\n");
}
}
#if 0
printk("Hangcheck: called %Ld ns since last time (%Ld ns overshoot)\n",
tsc_diff, tsc_diff - hangcheck_tick*TIMER_FREQ);
#endif
mod_timer(&hangcheck_ticktock, jiffies + (hangcheck_tick*HZ));
hangcheck_tsc = monotonic_clock();
}
static int __init hangcheck_init(void)
{
printk("Hangcheck: starting hangcheck timer %s (tick is %d seconds, margin is %d seconds).\n",
VERSION_STR, hangcheck_tick, hangcheck_margin);
#if defined (HAVE_MONOTONIC)
printk("Hangcheck: Using monotonic_clock().\n");
#else
printk("Hangcheck: Using getrawmonotonic().\n");
#endif
hangcheck_tsc_margin =
(unsigned long long)(hangcheck_margin + hangcheck_tick);
hangcheck_tsc_margin *= (unsigned long long)TIMER_FREQ;
hangcheck_tsc = monotonic_clock();
mod_timer(&hangcheck_ticktock, jiffies + (hangcheck_tick*HZ));
return 0;
}
static void __exit hangcheck_exit(void)
{
del_timer_sync(&hangcheck_ticktock);
printk("Hangcheck: Stopped hangcheck timer.\n");
}
