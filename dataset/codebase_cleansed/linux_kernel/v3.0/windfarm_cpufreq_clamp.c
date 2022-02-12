static int clamp_notifier_call(struct notifier_block *self,
unsigned long event, void *data)
{
struct cpufreq_policy *p = data;
unsigned long max_freq;
if (event != CPUFREQ_ADJUST)
return 0;
max_freq = clamped ? (p->cpuinfo.min_freq) : (p->cpuinfo.max_freq);
cpufreq_verify_within_limits(p, 0, max_freq);
return 0;
}
static int clamp_set(struct wf_control *ct, s32 value)
{
if (value)
printk(KERN_INFO "windfarm: Clamping CPU frequency to "
"minimum !\n");
else
printk(KERN_INFO "windfarm: CPU frequency unclamped !\n");
clamped = value;
cpufreq_update_policy(0);
return 0;
}
static int clamp_get(struct wf_control *ct, s32 *value)
{
*value = clamped;
return 0;
}
static s32 clamp_min(struct wf_control *ct)
{
return 0;
}
static s32 clamp_max(struct wf_control *ct)
{
return 1;
}
static int __init wf_cpufreq_clamp_init(void)
{
struct wf_control *clamp;
if (of_machine_is_compatible("PowerMac7,2") ||
of_machine_is_compatible("PowerMac7,3") ||
of_machine_is_compatible("RackMac3,1"))
return -ENODEV;
clamp = kmalloc(sizeof(struct wf_control), GFP_KERNEL);
if (clamp == NULL)
return -ENOMEM;
cpufreq_register_notifier(&clamp_notifier, CPUFREQ_POLICY_NOTIFIER);
clamp->ops = &clamp_ops;
clamp->name = "cpufreq-clamp";
if (wf_register_control(clamp))
goto fail;
clamp_control = clamp;
return 0;
fail:
kfree(clamp);
return -ENODEV;
}
static void __exit wf_cpufreq_clamp_exit(void)
{
if (clamp_control)
wf_unregister_control(clamp_control);
}
