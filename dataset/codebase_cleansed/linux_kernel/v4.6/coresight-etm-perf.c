static void etm_event_read(struct perf_event *event) {}
static int etm_event_init(struct perf_event *event)
{
if (event->attr.type != etm_pmu.type)
return -ENOENT;
return 0;
}
static void free_event_data(struct work_struct *work)
{
int cpu;
cpumask_t *mask;
struct etm_event_data *event_data;
struct coresight_device *sink;
event_data = container_of(work, struct etm_event_data, work);
mask = &event_data->mask;
if (event_data->snk_config) {
cpu = cpumask_first(mask);
sink = coresight_get_sink(event_data->path[cpu]);
if (sink_ops(sink)->free_buffer)
sink_ops(sink)->free_buffer(event_data->snk_config);
}
for_each_cpu(cpu, mask) {
if (event_data->path[cpu])
coresight_release_path(event_data->path[cpu]);
}
kfree(event_data->path);
kfree(event_data);
}
static void *alloc_event_data(int cpu)
{
int size;
cpumask_t *mask;
struct etm_event_data *event_data;
event_data = kzalloc(sizeof(struct etm_event_data), GFP_KERNEL);
if (!event_data)
return NULL;
get_online_cpus();
size = num_online_cpus();
mask = &event_data->mask;
if (cpu != -1)
cpumask_set_cpu(cpu, mask);
else
cpumask_copy(mask, cpu_online_mask);
put_online_cpus();
event_data->path = kcalloc(size,
sizeof(struct list_head *), GFP_KERNEL);
if (!event_data->path) {
kfree(event_data);
return NULL;
}
return event_data;
}
static void etm_free_aux(void *data)
{
struct etm_event_data *event_data = data;
schedule_work(&event_data->work);
}
static void *etm_setup_aux(int event_cpu, void **pages,
int nr_pages, bool overwrite)
{
int cpu;
cpumask_t *mask;
struct coresight_device *sink;
struct etm_event_data *event_data = NULL;
event_data = alloc_event_data(event_cpu);
if (!event_data)
return NULL;
INIT_WORK(&event_data->work, free_event_data);
mask = &event_data->mask;
for_each_cpu(cpu, mask) {
struct coresight_device *csdev;
csdev = per_cpu(csdev_src, cpu);
if (!csdev)
goto err;
event_data->path[cpu] = coresight_build_path(csdev);
if (!event_data->path[cpu])
goto err;
}
cpu = cpumask_first(mask);
sink = coresight_get_sink(event_data->path[cpu]);
if (!sink)
goto err;
if (!sink_ops(sink)->alloc_buffer)
goto err;
event_data->snk_config =
sink_ops(sink)->alloc_buffer(sink, cpu, pages,
nr_pages, overwrite);
if (!event_data->snk_config)
goto err;
out:
return event_data;
err:
etm_free_aux(event_data);
event_data = NULL;
goto out;
}
static void etm_event_start(struct perf_event *event, int flags)
{
int cpu = smp_processor_id();
struct etm_event_data *event_data;
struct perf_output_handle *handle = this_cpu_ptr(&ctx_handle);
struct coresight_device *sink, *csdev = per_cpu(csdev_src, cpu);
if (!csdev)
goto fail;
event_data = perf_aux_output_begin(handle, event);
if (!event_data)
goto fail;
sink = coresight_get_sink(event_data->path[cpu]);
if (WARN_ON_ONCE(!sink || !sink_ops(sink)->set_buffer))
goto fail_end_stop;
if (sink_ops(sink)->set_buffer(sink, handle,
event_data->snk_config))
goto fail_end_stop;
if (coresight_enable_path(event_data->path[cpu], CS_MODE_PERF))
goto fail_end_stop;
event->hw.state = 0;
if (source_ops(csdev)->enable(csdev, &event->attr, CS_MODE_PERF))
goto fail_end_stop;
out:
return;
fail_end_stop:
perf_aux_output_end(handle, 0, true);
fail:
event->hw.state = PERF_HES_STOPPED;
goto out;
}
static void etm_event_stop(struct perf_event *event, int mode)
{
bool lost;
int cpu = smp_processor_id();
unsigned long size;
struct coresight_device *sink, *csdev = per_cpu(csdev_src, cpu);
struct perf_output_handle *handle = this_cpu_ptr(&ctx_handle);
struct etm_event_data *event_data = perf_get_aux(handle);
if (event->hw.state == PERF_HES_STOPPED)
return;
if (!csdev)
return;
sink = coresight_get_sink(event_data->path[cpu]);
if (!sink)
return;
source_ops(csdev)->disable(csdev);
event->hw.state = PERF_HES_STOPPED;
if (mode & PERF_EF_UPDATE) {
if (WARN_ON_ONCE(handle->event != event))
return;
if (!sink_ops(sink)->update_buffer)
return;
sink_ops(sink)->update_buffer(sink, handle,
event_data->snk_config);
if (!sink_ops(sink)->reset_buffer)
return;
size = sink_ops(sink)->reset_buffer(sink, handle,
event_data->snk_config,
&lost);
perf_aux_output_end(handle, size, lost);
}
coresight_disable_path(event_data->path[cpu]);
}
static int etm_event_add(struct perf_event *event, int mode)
{
int ret = 0;
struct hw_perf_event *hwc = &event->hw;
if (mode & PERF_EF_START) {
etm_event_start(event, 0);
if (hwc->state & PERF_HES_STOPPED)
ret = -EINVAL;
} else {
hwc->state = PERF_HES_STOPPED;
}
return ret;
}
static void etm_event_del(struct perf_event *event, int mode)
{
etm_event_stop(event, PERF_EF_UPDATE);
}
int etm_perf_symlink(struct coresight_device *csdev, bool link)
{
char entry[sizeof("cpu9999999")];
int ret = 0, cpu = source_ops(csdev)->cpu_id(csdev);
struct device *pmu_dev = etm_pmu.dev;
struct device *cs_dev = &csdev->dev;
sprintf(entry, "cpu%d", cpu);
if (!etm_perf_up)
return -EPROBE_DEFER;
if (link) {
ret = sysfs_create_link(&pmu_dev->kobj, &cs_dev->kobj, entry);
if (ret)
return ret;
per_cpu(csdev_src, cpu) = csdev;
} else {
sysfs_remove_link(&pmu_dev->kobj, entry);
per_cpu(csdev_src, cpu) = NULL;
}
return 0;
}
static int __init etm_perf_init(void)
{
int ret;
etm_pmu.capabilities = PERF_PMU_CAP_EXCLUSIVE;
etm_pmu.attr_groups = etm_pmu_attr_groups;
etm_pmu.task_ctx_nr = perf_sw_context;
etm_pmu.read = etm_event_read;
etm_pmu.event_init = etm_event_init;
etm_pmu.setup_aux = etm_setup_aux;
etm_pmu.free_aux = etm_free_aux;
etm_pmu.start = etm_event_start;
etm_pmu.stop = etm_event_stop;
etm_pmu.add = etm_event_add;
etm_pmu.del = etm_event_del;
ret = perf_pmu_register(&etm_pmu, CORESIGHT_ETM_PMU_NAME, -1);
if (ret == 0)
etm_perf_up = true;
return ret;
}
