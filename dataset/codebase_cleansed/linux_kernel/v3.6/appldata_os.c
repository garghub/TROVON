static void appldata_get_os_data(void *data)
{
int i, j, rc;
struct appldata_os_data *os_data;
unsigned int new_size;
os_data = data;
os_data->sync_count_1++;
os_data->nr_threads = nr_threads;
os_data->nr_running = nr_running();
os_data->nr_iowait = nr_iowait();
os_data->avenrun[0] = avenrun[0] + (FIXED_1/200);
os_data->avenrun[1] = avenrun[1] + (FIXED_1/200);
os_data->avenrun[2] = avenrun[2] + (FIXED_1/200);
j = 0;
for_each_online_cpu(i) {
os_data->os_cpu[j].per_cpu_user =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_USER]);
os_data->os_cpu[j].per_cpu_nice =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_NICE]);
os_data->os_cpu[j].per_cpu_system =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_SYSTEM]);
os_data->os_cpu[j].per_cpu_idle =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_IDLE]);
os_data->os_cpu[j].per_cpu_irq =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_IRQ]);
os_data->os_cpu[j].per_cpu_softirq =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_SOFTIRQ]);
os_data->os_cpu[j].per_cpu_iowait =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_IOWAIT]);
os_data->os_cpu[j].per_cpu_steal =
cputime_to_jiffies(kcpustat_cpu(i).cpustat[CPUTIME_STEAL]);
os_data->os_cpu[j].cpu_id = i;
j++;
}
os_data->nr_cpus = j;
new_size = sizeof(struct appldata_os_data) +
(os_data->nr_cpus * sizeof(struct appldata_os_per_cpu));
if (ops.size != new_size) {
if (ops.active) {
rc = appldata_diag(APPLDATA_RECORD_OS_ID,
APPLDATA_START_INTERVAL_REC,
(unsigned long) ops.data, new_size,
ops.mod_lvl);
if (rc != 0)
pr_err("Starting a new OS data collection "
"failed with rc=%d\n", rc);
rc = appldata_diag(APPLDATA_RECORD_OS_ID,
APPLDATA_STOP_REC,
(unsigned long) ops.data, ops.size,
ops.mod_lvl);
if (rc != 0)
pr_err("Stopping a faulty OS data "
"collection failed with rc=%d\n", rc);
}
ops.size = new_size;
}
os_data->timestamp = get_clock();
os_data->sync_count_2++;
}
static int __init appldata_os_init(void)
{
int rc, max_size;
max_size = sizeof(struct appldata_os_data) +
(NR_CPUS * sizeof(struct appldata_os_per_cpu));
if (max_size > APPLDATA_MAX_REC_SIZE) {
pr_err("Maximum OS record size %i exceeds the maximum "
"record size %i\n", max_size, APPLDATA_MAX_REC_SIZE);
rc = -ENOMEM;
goto out;
}
appldata_os_data = kzalloc(max_size, GFP_KERNEL | GFP_DMA);
if (appldata_os_data == NULL) {
rc = -ENOMEM;
goto out;
}
appldata_os_data->per_cpu_size = sizeof(struct appldata_os_per_cpu);
appldata_os_data->cpu_offset = offsetof(struct appldata_os_data,
os_cpu);
ops.data = appldata_os_data;
ops.callback = &appldata_get_os_data;
rc = appldata_register_ops(&ops);
if (rc != 0)
kfree(appldata_os_data);
out:
return rc;
}
static void __exit appldata_os_exit(void)
{
appldata_unregister_ops(&ops);
kfree(appldata_os_data);
}
