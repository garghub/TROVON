static int get_oc_core_priority(unsigned int cpu)
{
u64 value, cmd = OC_MAILBOX_FC_CONTROL_CMD;
int ret, i;
value = cmd << MSR_OC_MAILBOX_CMD_OFFSET;
value |= BIT_ULL(MSR_OC_MAILBOX_BUSY_BIT);
ret = wrmsrl_safe(MSR_OC_MAILBOX, value);
if (ret) {
pr_debug("cpu %d OC mailbox write failed\n", cpu);
return ret;
}
for (i = 0; i < OC_MAILBOX_RETRY_COUNT; ++i) {
ret = rdmsrl_safe(MSR_OC_MAILBOX, &value);
if (ret) {
pr_debug("cpu %d OC mailbox read failed\n", cpu);
break;
}
if (value & BIT_ULL(MSR_OC_MAILBOX_BUSY_BIT)) {
pr_debug("cpu %d OC mailbox still processing\n", cpu);
ret = -EBUSY;
continue;
}
if ((value >> MSR_OC_MAILBOX_RSP_OFFSET) & 0xff) {
pr_debug("cpu %d OC mailbox cmd failed\n", cpu);
ret = -ENXIO;
break;
}
ret = value & 0xff;
pr_debug("cpu %d max_ratio %d\n", cpu, ret);
break;
}
return ret;
}
static void itmt_legacy_work_fn(struct work_struct *work)
{
sched_set_itmt_support();
}
static int itmt_legacy_cpu_online(unsigned int cpu)
{
static u32 max_highest_perf = 0, min_highest_perf = U32_MAX;
int priority;
priority = get_oc_core_priority(cpu);
if (priority < 0)
return 0;
sched_set_itmt_core_prio(priority, cpu);
if (max_highest_perf <= min_highest_perf) {
if (priority > max_highest_perf)
max_highest_perf = priority;
if (priority < min_highest_perf)
min_highest_perf = priority;
if (max_highest_perf > min_highest_perf)
schedule_work(&sched_itmt_work);
}
return 0;
}
static int __init itmt_legacy_init(void)
{
const struct x86_cpu_id *id;
int ret;
id = x86_match_cpu(itmt_legacy_cpu_ids);
if (!id)
return -ENODEV;
if (boot_cpu_has(X86_FEATURE_HWP))
return -ENODEV;
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN,
"platform/x86/turbo_max_3:online",
itmt_legacy_cpu_online, NULL);
if (ret < 0)
return ret;
return 0;
}
