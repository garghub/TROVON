static inline void get_seq(__u32 *ts, int *cpu)
{
preempt_disable();
*ts = __this_cpu_inc_return(proc_event_counts) -1;
*cpu = smp_processor_id();
preempt_enable();
}
void proc_fork_connector(struct task_struct *task)
{
struct cn_msg *msg;
struct proc_event *ev;
__u8 buffer[CN_PROC_MSG_SIZE];
struct timespec ts;
struct task_struct *parent;
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg*)buffer;
ev = (struct proc_event*)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_FORK;
rcu_read_lock();
parent = rcu_dereference(task->real_parent);
ev->event_data.fork.parent_pid = parent->pid;
ev->event_data.fork.parent_tgid = parent->tgid;
rcu_read_unlock();
ev->event_data.fork.child_pid = task->pid;
ev->event_data.fork.child_tgid = task->tgid;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_exec_connector(struct task_struct *task)
{
struct cn_msg *msg;
struct proc_event *ev;
struct timespec ts;
__u8 buffer[CN_PROC_MSG_SIZE];
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg*)buffer;
ev = (struct proc_event*)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_EXEC;
ev->event_data.exec.process_pid = task->pid;
ev->event_data.exec.process_tgid = task->tgid;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_id_connector(struct task_struct *task, int which_id)
{
struct cn_msg *msg;
struct proc_event *ev;
__u8 buffer[CN_PROC_MSG_SIZE];
struct timespec ts;
const struct cred *cred;
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg*)buffer;
ev = (struct proc_event*)msg->data;
ev->what = which_id;
ev->event_data.id.process_pid = task->pid;
ev->event_data.id.process_tgid = task->tgid;
rcu_read_lock();
cred = __task_cred(task);
if (which_id == PROC_EVENT_UID) {
ev->event_data.id.r.ruid = cred->uid;
ev->event_data.id.e.euid = cred->euid;
} else if (which_id == PROC_EVENT_GID) {
ev->event_data.id.r.rgid = cred->gid;
ev->event_data.id.e.egid = cred->egid;
} else {
rcu_read_unlock();
return;
}
rcu_read_unlock();
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_sid_connector(struct task_struct *task)
{
struct cn_msg *msg;
struct proc_event *ev;
struct timespec ts;
__u8 buffer[CN_PROC_MSG_SIZE];
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg *)buffer;
ev = (struct proc_event *)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_SID;
ev->event_data.sid.process_pid = task->pid;
ev->event_data.sid.process_tgid = task->tgid;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_ptrace_connector(struct task_struct *task, int ptrace_id)
{
struct cn_msg *msg;
struct proc_event *ev;
struct timespec ts;
__u8 buffer[CN_PROC_MSG_SIZE];
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg *)buffer;
ev = (struct proc_event *)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_PTRACE;
ev->event_data.ptrace.process_pid = task->pid;
ev->event_data.ptrace.process_tgid = task->tgid;
if (ptrace_id == PTRACE_ATTACH) {
ev->event_data.ptrace.tracer_pid = current->pid;
ev->event_data.ptrace.tracer_tgid = current->tgid;
} else if (ptrace_id == PTRACE_DETACH) {
ev->event_data.ptrace.tracer_pid = 0;
ev->event_data.ptrace.tracer_tgid = 0;
} else
return;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_comm_connector(struct task_struct *task)
{
struct cn_msg *msg;
struct proc_event *ev;
struct timespec ts;
__u8 buffer[CN_PROC_MSG_SIZE];
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg *)buffer;
ev = (struct proc_event *)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_COMM;
ev->event_data.comm.process_pid = task->pid;
ev->event_data.comm.process_tgid = task->tgid;
get_task_comm(ev->event_data.comm.comm, task);
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
void proc_exit_connector(struct task_struct *task)
{
struct cn_msg *msg;
struct proc_event *ev;
__u8 buffer[CN_PROC_MSG_SIZE];
struct timespec ts;
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg*)buffer;
ev = (struct proc_event*)msg->data;
get_seq(&msg->seq, &ev->cpu);
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->what = PROC_EVENT_EXIT;
ev->event_data.exit.process_pid = task->pid;
ev->event_data.exit.process_tgid = task->tgid;
ev->event_data.exit.exit_code = task->exit_code;
ev->event_data.exit.exit_signal = task->exit_signal;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = 0;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
static void cn_proc_ack(int err, int rcvd_seq, int rcvd_ack)
{
struct cn_msg *msg;
struct proc_event *ev;
__u8 buffer[CN_PROC_MSG_SIZE];
struct timespec ts;
if (atomic_read(&proc_event_num_listeners) < 1)
return;
msg = (struct cn_msg*)buffer;
ev = (struct proc_event*)msg->data;
msg->seq = rcvd_seq;
ktime_get_ts(&ts);
put_unaligned(timespec_to_ns(&ts), (__u64 *)&ev->timestamp_ns);
ev->cpu = -1;
ev->what = PROC_EVENT_NONE;
ev->event_data.ack.err = err;
memcpy(&msg->id, &cn_proc_event_id, sizeof(msg->id));
msg->ack = rcvd_ack + 1;
msg->len = sizeof(*ev);
cn_netlink_send(msg, CN_IDX_PROC, GFP_KERNEL);
}
static void cn_proc_mcast_ctl(struct cn_msg *msg,
struct netlink_skb_parms *nsp)
{
enum proc_cn_mcast_op *mc_op = NULL;
int err = 0;
if (msg->len != sizeof(*mc_op))
return;
mc_op = (enum proc_cn_mcast_op*)msg->data;
switch (*mc_op) {
case PROC_CN_MCAST_LISTEN:
atomic_inc(&proc_event_num_listeners);
break;
case PROC_CN_MCAST_IGNORE:
atomic_dec(&proc_event_num_listeners);
break;
default:
err = EINVAL;
break;
}
cn_proc_ack(err, msg->seq, msg->ack);
}
static int __init cn_proc_init(void)
{
int err;
if ((err = cn_add_callback(&cn_proc_event_id, "cn_proc",
&cn_proc_mcast_ctl))) {
printk(KERN_WARNING "cn_proc failed to register\n");
return err;
}
return 0;
}
