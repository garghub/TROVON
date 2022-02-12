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
static const struct bpf_func_proto *bpf_get_probe_write_proto(void)
{
pr_warn_ratelimited("%s[%d] is installing a program with bpf_probe_write_user helper that may corrupt user memory!",
current->comm, task_pid_nr(current));
return &bpf_probe_write_user_proto;
}
const struct bpf_func_proto *bpf_get_trace_printk_proto(void)
{
trace_printk_init_buffers();
return &bpf_trace_printk_proto;
}
static __always_inline u64
__bpf_perf_event_output(struct pt_regs *regs, struct bpf_map *map,
u64 flags, struct perf_raw_record *raw)
{
struct bpf_array *array = container_of(map, struct bpf_array, map);
struct perf_sample_data *sd = this_cpu_ptr(&bpf_sd);
unsigned int cpu = smp_processor_id();
u64 index = flags & BPF_F_INDEX_MASK;
struct bpf_event_entry *ee;
struct perf_event *event;
if (index == BPF_F_CURRENT_CPU)
index = cpu;
if (unlikely(index >= array->map.max_entries))
return -E2BIG;
ee = READ_ONCE(array->ptrs[index]);
if (!ee)
return -ENOENT;
event = ee->event;
if (unlikely(event->attr.type != PERF_TYPE_SOFTWARE ||
event->attr.config != PERF_COUNT_SW_BPF_OUTPUT))
return -EINVAL;
if (unlikely(event->oncpu != cpu))
return -EOPNOTSUPP;
perf_sample_data_init(sd, 0, 0);
sd->raw = raw;
perf_event_output(event, sd, regs);
return 0;
}
u64 bpf_event_output(struct bpf_map *map, u64 flags, void *meta, u64 meta_size,
void *ctx, u64 ctx_size, bpf_ctx_copy_t ctx_copy)
{
struct pt_regs *regs = this_cpu_ptr(&bpf_pt_regs);
struct perf_raw_frag frag = {
.copy = ctx_copy,
.size = ctx_size,
.data = ctx,
};
struct perf_raw_record raw = {
.frag = {
{
.next = ctx_size ? &frag : NULL,
},
.size = meta_size,
.data = meta,
},
};
perf_fetch_caller_regs(regs);
return __bpf_perf_event_output(regs, map, flags, &raw);
}
static const struct bpf_func_proto *tracing_func_proto(enum bpf_func_id func_id)
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
case BPF_FUNC_get_current_task:
return &bpf_get_current_task_proto;
case BPF_FUNC_get_current_uid_gid:
return &bpf_get_current_uid_gid_proto;
case BPF_FUNC_get_current_comm:
return &bpf_get_current_comm_proto;
case BPF_FUNC_trace_printk:
return bpf_get_trace_printk_proto();
case BPF_FUNC_get_smp_processor_id:
return &bpf_get_smp_processor_id_proto;
case BPF_FUNC_get_numa_node_id:
return &bpf_get_numa_node_id_proto;
case BPF_FUNC_perf_event_read:
return &bpf_perf_event_read_proto;
case BPF_FUNC_probe_write_user:
return bpf_get_probe_write_proto();
case BPF_FUNC_current_task_under_cgroup:
return &bpf_current_task_under_cgroup_proto;
case BPF_FUNC_get_prandom_u32:
return &bpf_get_prandom_u32_proto;
case BPF_FUNC_probe_read_str:
return &bpf_probe_read_str_proto;
default:
return NULL;
}
}
static const struct bpf_func_proto *kprobe_prog_func_proto(enum bpf_func_id func_id)
{
switch (func_id) {
case BPF_FUNC_perf_event_output:
return &bpf_perf_event_output_proto;
case BPF_FUNC_get_stackid:
return &bpf_get_stackid_proto;
default:
return tracing_func_proto(func_id);
}
}
static bool kprobe_prog_is_valid_access(int off, int size, enum bpf_access_type type,
struct bpf_insn_access_aux *info)
{
if (off < 0 || off >= sizeof(struct pt_regs))
return false;
if (type != BPF_READ)
return false;
if (off % size != 0)
return false;
if (off + size > sizeof(struct pt_regs))
return false;
return true;
}
static const struct bpf_func_proto *tp_prog_func_proto(enum bpf_func_id func_id)
{
switch (func_id) {
case BPF_FUNC_perf_event_output:
return &bpf_perf_event_output_proto_tp;
case BPF_FUNC_get_stackid:
return &bpf_get_stackid_proto_tp;
default:
return tracing_func_proto(func_id);
}
}
static bool tp_prog_is_valid_access(int off, int size, enum bpf_access_type type,
struct bpf_insn_access_aux *info)
{
if (off < sizeof(void *) || off >= PERF_MAX_TRACE_SIZE)
return false;
if (type != BPF_READ)
return false;
if (off % size != 0)
return false;
BUILD_BUG_ON(PERF_MAX_TRACE_SIZE % sizeof(__u64));
return true;
}
static bool pe_prog_is_valid_access(int off, int size, enum bpf_access_type type,
struct bpf_insn_access_aux *info)
{
const int size_sp = FIELD_SIZEOF(struct bpf_perf_event_data,
sample_period);
if (off < 0 || off >= sizeof(struct bpf_perf_event_data))
return false;
if (type != BPF_READ)
return false;
if (off % size != 0)
return false;
switch (off) {
case bpf_ctx_range(struct bpf_perf_event_data, sample_period):
bpf_ctx_record_field_size(info, size_sp);
if (!bpf_ctx_narrow_access_ok(off, size, size_sp))
return false;
break;
default:
if (size != sizeof(long))
return false;
}
return true;
}
static u32 pe_prog_convert_ctx_access(enum bpf_access_type type,
const struct bpf_insn *si,
struct bpf_insn *insn_buf,
struct bpf_prog *prog, u32 *target_size)
{
struct bpf_insn *insn = insn_buf;
switch (si->off) {
case offsetof(struct bpf_perf_event_data, sample_period):
*insn++ = BPF_LDX_MEM(BPF_FIELD_SIZEOF(struct bpf_perf_event_data_kern,
data), si->dst_reg, si->src_reg,
offsetof(struct bpf_perf_event_data_kern, data));
*insn++ = BPF_LDX_MEM(BPF_DW, si->dst_reg, si->dst_reg,
bpf_target_off(struct perf_sample_data, period, 8,
target_size));
break;
default:
*insn++ = BPF_LDX_MEM(BPF_FIELD_SIZEOF(struct bpf_perf_event_data_kern,
regs), si->dst_reg, si->src_reg,
offsetof(struct bpf_perf_event_data_kern, regs));
*insn++ = BPF_LDX_MEM(BPF_SIZEOF(long), si->dst_reg, si->dst_reg,
si->off);
break;
}
return insn - insn_buf;
}
