unsigned int trace_call_bpf(struct bpf_prog *prog, void *ctx)
{
unsigned int ret;
if (in_nmi())
return 1;
preempt_disable();
if (unlikely(__this_cpu_inc_return(bpf_prog_active) != 1)) {
ret = 0;
goto out;
}
rcu_read_lock();
ret = BPF_PROG_RUN(prog, ctx);
rcu_read_unlock();
out:
__this_cpu_dec(bpf_prog_active);
preempt_enable();
return ret;
}
static u64 bpf_probe_read(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
void *dst = (void *) (long) r1;
int size = (int) r2;
void *unsafe_ptr = (void *) (long) r3;
return probe_kernel_read(dst, unsafe_ptr, size);
}
static u64 bpf_trace_printk(u64 r1, u64 fmt_size, u64 r3, u64 r4, u64 r5)
{
char *fmt = (char *) (long) r1;
bool str_seen = false;
int mod[3] = {};
int fmt_cnt = 0;
u64 unsafe_addr;
char buf[64];
int i;
if (fmt[--fmt_size] != 0)
return -EINVAL;
for (i = 0; i < fmt_size; i++) {
if ((!isprint(fmt[i]) && !isspace(fmt[i])) || !isascii(fmt[i]))
return -EINVAL;
if (fmt[i] != '%')
continue;
if (fmt_cnt >= 3)
return -EINVAL;
i++;
if (fmt[i] == 'l') {
mod[fmt_cnt]++;
i++;
} else if (fmt[i] == 'p' || fmt[i] == 's') {
mod[fmt_cnt]++;
i++;
if (!isspace(fmt[i]) && !ispunct(fmt[i]) && fmt[i] != 0)
return -EINVAL;
fmt_cnt++;
if (fmt[i - 1] == 's') {
if (str_seen)
return -EINVAL;
str_seen = true;
switch (fmt_cnt) {
case 1:
unsafe_addr = r3;
r3 = (long) buf;
break;
case 2:
unsafe_addr = r4;
r4 = (long) buf;
break;
case 3:
unsafe_addr = r5;
r5 = (long) buf;
break;
}
buf[0] = 0;
strncpy_from_unsafe(buf,
(void *) (long) unsafe_addr,
sizeof(buf));
}
continue;
}
if (fmt[i] == 'l') {
mod[fmt_cnt]++;
i++;
}
if (fmt[i] != 'd' && fmt[i] != 'u' && fmt[i] != 'x')
return -EINVAL;
fmt_cnt++;
}
return __trace_printk(1, fmt,
mod[0] == 2 ? r3 : mod[0] == 1 ? (long) r3 : (u32) r3,
mod[1] == 2 ? r4 : mod[1] == 1 ? (long) r4 : (u32) r4,
mod[2] == 2 ? r5 : mod[2] == 1 ? (long) r5 : (u32) r5);
}
const struct bpf_func_proto *bpf_get_trace_printk_proto(void)
{
trace_printk_init_buffers();
return &bpf_trace_printk_proto;
}
static u64 bpf_perf_event_read(u64 r1, u64 index, u64 r3, u64 r4, u64 r5)
{
struct bpf_map *map = (struct bpf_map *) (unsigned long) r1;
struct bpf_array *array = container_of(map, struct bpf_array, map);
struct perf_event *event;
struct file *file;
if (unlikely(index >= array->map.max_entries))
return -E2BIG;
file = (struct file *)array->ptrs[index];
if (unlikely(!file))
return -ENOENT;
event = file->private_data;
if (event->oncpu != smp_processor_id() ||
event->pmu->count)
return -EINVAL;
return perf_event_read_local(event);
}
static u64 bpf_perf_event_output(u64 r1, u64 r2, u64 index, u64 r4, u64 size)
{
struct pt_regs *regs = (struct pt_regs *) (long) r1;
struct bpf_map *map = (struct bpf_map *) (long) r2;
struct bpf_array *array = container_of(map, struct bpf_array, map);
void *data = (void *) (long) r4;
struct perf_sample_data sample_data;
struct perf_event *event;
struct file *file;
struct perf_raw_record raw = {
.size = size,
.data = data,
};
if (unlikely(index >= array->map.max_entries))
return -E2BIG;
file = (struct file *)array->ptrs[index];
if (unlikely(!file))
return -ENOENT;
event = file->private_data;
if (unlikely(event->attr.type != PERF_TYPE_SOFTWARE ||
event->attr.config != PERF_COUNT_SW_BPF_OUTPUT))
return -EINVAL;
if (unlikely(event->oncpu != smp_processor_id()))
return -EOPNOTSUPP;
perf_sample_data_init(&sample_data, 0, 0);
sample_data.raw = &raw;
perf_event_output(event, &sample_data, regs);
return 0;
}
static const struct bpf_func_proto *kprobe_prog_func_proto(enum bpf_func_id func_id)
{
switch (func_id) {
case BPF_FUNC_map_lookup_elem:
return &bpf_map_lookup_elem_proto;
case BPF_FUNC_map_update_elem:
return &bpf_map_update_elem_proto;
case BPF_FUNC_map_delete_elem:
return &bpf_map_delete_elem_proto;
case BPF_FUNC_probe_read:
return &bpf_probe_read_proto;
case BPF_FUNC_ktime_get_ns:
return &bpf_ktime_get_ns_proto;
case BPF_FUNC_tail_call:
return &bpf_tail_call_proto;
case BPF_FUNC_get_current_pid_tgid:
return &bpf_get_current_pid_tgid_proto;
case BPF_FUNC_get_current_uid_gid:
return &bpf_get_current_uid_gid_proto;
case BPF_FUNC_get_current_comm:
return &bpf_get_current_comm_proto;
case BPF_FUNC_trace_printk:
return bpf_get_trace_printk_proto();
case BPF_FUNC_get_smp_processor_id:
return &bpf_get_smp_processor_id_proto;
case BPF_FUNC_perf_event_read:
return &bpf_perf_event_read_proto;
case BPF_FUNC_perf_event_output:
return &bpf_perf_event_output_proto;
case BPF_FUNC_get_stackid:
return &bpf_get_stackid_proto;
default:
return NULL;
}
}
static bool kprobe_prog_is_valid_access(int off, int size, enum bpf_access_type type)
{
if (off < 0 || off >= sizeof(struct pt_regs))
return false;
if (type != BPF_READ)
return false;
if (off % size != 0)
return false;
return true;
}
static int __init register_kprobe_prog_ops(void)
{
bpf_register_prog_type(&kprobe_tl);
return 0;
}
