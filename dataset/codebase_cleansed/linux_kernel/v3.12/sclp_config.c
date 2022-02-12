static void sclp_cpu_capability_notify(struct work_struct *work)
{
int cpu;
struct device *dev;
s390_adjust_jiffies();
pr_info("CPU capability may have changed\n");
get_online_cpus();
for_each_online_cpu(cpu) {
dev = get_cpu_device(cpu);
kobject_uevent(&dev->kobj, KOBJ_CHANGE);
}
put_online_cpus();
}
static void __ref sclp_cpu_change_notify(struct work_struct *work)
{
smp_rescan_cpus();
}
static void sclp_conf_receiver_fn(struct evbuf_header *evbuf)
{
struct conf_mgm_data *cdata;
cdata = (struct conf_mgm_data *)(evbuf + 1);
switch (cdata->ev_qualifier) {
case EV_QUAL_CPU_CHANGE:
schedule_work(&sclp_cpu_change_work);
break;
case EV_QUAL_CAP_CHANGE:
schedule_work(&sclp_cpu_capability_work);
break;
}
}
static int __init sclp_conf_init(void)
{
INIT_WORK(&sclp_cpu_capability_work, sclp_cpu_capability_notify);
INIT_WORK(&sclp_cpu_change_work, sclp_cpu_change_notify);
return sclp_register(&sclp_conf_register);
}
