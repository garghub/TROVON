static int prepare_reply(struct genl_info *info, u8 cmd, struct sk_buff **skbp,
size_t size)
{
struct sk_buff *skb;
void *reply;
skb = genlmsg_new(size, GFP_KERNEL);
if (!skb)
return -ENOMEM;
if (!info) {
int seq = this_cpu_inc_return(taskstats_seqnum) - 1;
reply = genlmsg_put(skb, 0, seq, &family, 0, cmd);
} else
reply = genlmsg_put_reply(skb, info, &family, 0, cmd);
if (reply == NULL) {
nlmsg_free(skb);
return -EINVAL;
}
*skbp = skb;
return 0;
}
static int send_reply(struct sk_buff *skb, struct genl_info *info)
{
struct genlmsghdr *genlhdr = nlmsg_data(nlmsg_hdr(skb));
void *reply = genlmsg_data(genlhdr);
int rc;
rc = genlmsg_end(skb, reply);
if (rc < 0) {
nlmsg_free(skb);
return rc;
}
return genlmsg_reply(skb, info);
}
static void send_cpu_listeners(struct sk_buff *skb,
struct listener_list *listeners)
{
struct genlmsghdr *genlhdr = nlmsg_data(nlmsg_hdr(skb));
struct listener *s, *tmp;
struct sk_buff *skb_next, *skb_cur = skb;
void *reply = genlmsg_data(genlhdr);
int rc, delcount = 0;
rc = genlmsg_end(skb, reply);
if (rc < 0) {
nlmsg_free(skb);
return;
}
rc = 0;
down_read(&listeners->sem);
list_for_each_entry(s, &listeners->list, list) {
skb_next = NULL;
if (!list_is_last(&s->list, &listeners->list)) {
skb_next = skb_clone(skb_cur, GFP_KERNEL);
if (!skb_next)
break;
}
rc = genlmsg_unicast(&init_net, skb_cur, s->pid);
if (rc == -ECONNREFUSED) {
s->valid = 0;
delcount++;
}
skb_cur = skb_next;
}
up_read(&listeners->sem);
if (skb_cur)
nlmsg_free(skb_cur);
if (!delcount)
return;
down_write(&listeners->sem);
list_for_each_entry_safe(s, tmp, &listeners->list, list) {
if (!s->valid) {
list_del(&s->list);
kfree(s);
}
}
up_write(&listeners->sem);
}
static void fill_stats(struct user_namespace *user_ns,
struct pid_namespace *pid_ns,
struct task_struct *tsk, struct taskstats *stats)
{
memset(stats, 0, sizeof(*stats));
delayacct_add_tsk(stats, tsk);
stats->version = TASKSTATS_VERSION;
stats->nvcsw = tsk->nvcsw;
stats->nivcsw = tsk->nivcsw;
bacct_add_tsk(user_ns, pid_ns, stats, tsk);
xacct_add_tsk(stats, tsk);
}
static int fill_stats_for_pid(pid_t pid, struct taskstats *stats)
{
struct task_struct *tsk;
rcu_read_lock();
tsk = find_task_by_vpid(pid);
if (tsk)
get_task_struct(tsk);
rcu_read_unlock();
if (!tsk)
return -ESRCH;
fill_stats(current_user_ns(), task_active_pid_ns(current), tsk, stats);
put_task_struct(tsk);
return 0;
}
static int fill_stats_for_tgid(pid_t tgid, struct taskstats *stats)
{
struct task_struct *tsk, *first;
unsigned long flags;
int rc = -ESRCH;
rcu_read_lock();
first = find_task_by_vpid(tgid);
if (!first || !lock_task_sighand(first, &flags))
goto out;
if (first->signal->stats)
memcpy(stats, first->signal->stats, sizeof(*stats));
else
memset(stats, 0, sizeof(*stats));
tsk = first;
do {
if (tsk->exit_state)
continue;
delayacct_add_tsk(stats, tsk);
stats->nvcsw += tsk->nvcsw;
stats->nivcsw += tsk->nivcsw;
} while_each_thread(first, tsk);
void fill_tgid_exit(struct task_struct *tsk)
{
unsigned long flags;
spin_lock_irqsave(&tsk->sighand->siglock, flags);
if (!tsk->signal->stats)
goto ret;
delayacct_add_tsk(tsk->signal->stats, tsk);
ret:
spin_unlock_irqrestore(&tsk->sighand->siglock, flags);
return;
}
static int add_del_listener(pid_t pid, const struct cpumask *mask, int isadd)
{
struct listener_list *listeners;
struct listener *s, *tmp, *s2;
unsigned int cpu;
if (!cpumask_subset(mask, cpu_possible_mask))
return -EINVAL;
if (current_user_ns() != &init_user_ns)
return -EINVAL;
if (task_active_pid_ns(current) != &init_pid_ns)
return -EINVAL;
if (isadd == REGISTER) {
for_each_cpu(cpu, mask) {
s = kmalloc_node(sizeof(struct listener),
GFP_KERNEL, cpu_to_node(cpu));
if (!s)
goto cleanup;
s->pid = pid;
s->valid = 1;
listeners = &per_cpu(listener_array, cpu);
down_write(&listeners->sem);
list_for_each_entry(s2, &listeners->list, list) {
if (s2->pid == pid && s2->valid)
goto exists;
}
list_add(&s->list, &listeners->list);
s = NULL;
exists:
up_write(&listeners->sem);
kfree(s);
}
return 0;
}
cleanup:
for_each_cpu(cpu, mask) {
listeners = &per_cpu(listener_array, cpu);
down_write(&listeners->sem);
list_for_each_entry_safe(s, tmp, &listeners->list, list) {
if (s->pid == pid) {
list_del(&s->list);
kfree(s);
break;
}
}
up_write(&listeners->sem);
}
return 0;
}
static int parse(struct nlattr *na, struct cpumask *mask)
{
char *data;
int len;
int ret;
if (na == NULL)
return 1;
len = nla_len(na);
if (len > TASKSTATS_CPUMASK_MAXLEN)
return -E2BIG;
if (len < 1)
return -EINVAL;
data = kmalloc(len, GFP_KERNEL);
if (!data)
return -ENOMEM;
nla_strlcpy(data, na, len);
ret = cpulist_parse(data, mask);
kfree(data);
return ret;
}
static struct taskstats *mk_reply(struct sk_buff *skb, int type, u32 pid)
{
struct nlattr *na, *ret;
int aggr;
aggr = (type == TASKSTATS_TYPE_PID)
? TASKSTATS_TYPE_AGGR_PID
: TASKSTATS_TYPE_AGGR_TGID;
#ifdef TASKSTATS_NEEDS_PADDING
if (nla_put(skb, TASKSTATS_TYPE_NULL, 0, NULL) < 0)
goto err;
#endif
na = nla_nest_start(skb, aggr);
if (!na)
goto err;
if (nla_put(skb, type, sizeof(pid), &pid) < 0)
goto err;
ret = nla_reserve(skb, TASKSTATS_TYPE_STATS, sizeof(struct taskstats));
if (!ret)
goto err;
nla_nest_end(skb, na);
return nla_data(ret);
err:
return NULL;
}
static int cgroupstats_user_cmd(struct sk_buff *skb, struct genl_info *info)
{
int rc = 0;
struct sk_buff *rep_skb;
struct cgroupstats *stats;
struct nlattr *na;
size_t size;
u32 fd;
struct fd f;
na = info->attrs[CGROUPSTATS_CMD_ATTR_FD];
if (!na)
return -EINVAL;
fd = nla_get_u32(info->attrs[CGROUPSTATS_CMD_ATTR_FD]);
f = fdget(fd);
if (!f.file)
return 0;
size = nla_total_size(sizeof(struct cgroupstats));
rc = prepare_reply(info, CGROUPSTATS_CMD_NEW, &rep_skb,
size);
if (rc < 0)
goto err;
na = nla_reserve(rep_skb, CGROUPSTATS_TYPE_CGROUP_STATS,
sizeof(struct cgroupstats));
if (na == NULL) {
nlmsg_free(rep_skb);
rc = -EMSGSIZE;
goto err;
}
stats = nla_data(na);
memset(stats, 0, sizeof(*stats));
rc = cgroupstats_build(stats, f.file->f_dentry);
if (rc < 0) {
nlmsg_free(rep_skb);
goto err;
}
rc = send_reply(rep_skb, info);
err:
fdput(f);
return rc;
}
static int cmd_attr_register_cpumask(struct genl_info *info)
{
cpumask_var_t mask;
int rc;
if (!alloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
rc = parse(info->attrs[TASKSTATS_CMD_ATTR_REGISTER_CPUMASK], mask);
if (rc < 0)
goto out;
rc = add_del_listener(info->snd_portid, mask, REGISTER);
out:
free_cpumask_var(mask);
return rc;
}
static int cmd_attr_deregister_cpumask(struct genl_info *info)
{
cpumask_var_t mask;
int rc;
if (!alloc_cpumask_var(&mask, GFP_KERNEL))
return -ENOMEM;
rc = parse(info->attrs[TASKSTATS_CMD_ATTR_DEREGISTER_CPUMASK], mask);
if (rc < 0)
goto out;
rc = add_del_listener(info->snd_portid, mask, DEREGISTER);
out:
free_cpumask_var(mask);
return rc;
}
static size_t taskstats_packet_size(void)
{
size_t size;
size = nla_total_size(sizeof(u32)) +
nla_total_size(sizeof(struct taskstats)) + nla_total_size(0);
#ifdef TASKSTATS_NEEDS_PADDING
size += nla_total_size(0);
#endif
return size;
}
static int cmd_attr_pid(struct genl_info *info)
{
struct taskstats *stats;
struct sk_buff *rep_skb;
size_t size;
u32 pid;
int rc;
size = taskstats_packet_size();
rc = prepare_reply(info, TASKSTATS_CMD_NEW, &rep_skb, size);
if (rc < 0)
return rc;
rc = -EINVAL;
pid = nla_get_u32(info->attrs[TASKSTATS_CMD_ATTR_PID]);
stats = mk_reply(rep_skb, TASKSTATS_TYPE_PID, pid);
if (!stats)
goto err;
rc = fill_stats_for_pid(pid, stats);
if (rc < 0)
goto err;
return send_reply(rep_skb, info);
err:
nlmsg_free(rep_skb);
return rc;
}
static int cmd_attr_tgid(struct genl_info *info)
{
struct taskstats *stats;
struct sk_buff *rep_skb;
size_t size;
u32 tgid;
int rc;
size = taskstats_packet_size();
rc = prepare_reply(info, TASKSTATS_CMD_NEW, &rep_skb, size);
if (rc < 0)
return rc;
rc = -EINVAL;
tgid = nla_get_u32(info->attrs[TASKSTATS_CMD_ATTR_TGID]);
stats = mk_reply(rep_skb, TASKSTATS_TYPE_TGID, tgid);
if (!stats)
goto err;
rc = fill_stats_for_tgid(tgid, stats);
if (rc < 0)
goto err;
return send_reply(rep_skb, info);
err:
nlmsg_free(rep_skb);
return rc;
}
static int taskstats_user_cmd(struct sk_buff *skb, struct genl_info *info)
{
if (info->attrs[TASKSTATS_CMD_ATTR_REGISTER_CPUMASK])
return cmd_attr_register_cpumask(info);
else if (info->attrs[TASKSTATS_CMD_ATTR_DEREGISTER_CPUMASK])
return cmd_attr_deregister_cpumask(info);
else if (info->attrs[TASKSTATS_CMD_ATTR_PID])
return cmd_attr_pid(info);
else if (info->attrs[TASKSTATS_CMD_ATTR_TGID])
return cmd_attr_tgid(info);
else
return -EINVAL;
}
static struct taskstats *taskstats_tgid_alloc(struct task_struct *tsk)
{
struct signal_struct *sig = tsk->signal;
struct taskstats *stats;
if (sig->stats || thread_group_empty(tsk))
goto ret;
stats = kmem_cache_zalloc(taskstats_cache, GFP_KERNEL);
spin_lock_irq(&tsk->sighand->siglock);
if (!sig->stats) {
sig->stats = stats;
stats = NULL;
}
spin_unlock_irq(&tsk->sighand->siglock);
if (stats)
kmem_cache_free(taskstats_cache, stats);
ret:
return sig->stats;
}
void taskstats_exit(struct task_struct *tsk, int group_dead)
{
int rc;
struct listener_list *listeners;
struct taskstats *stats;
struct sk_buff *rep_skb;
size_t size;
int is_thread_group;
if (!family_registered)
return;
size = taskstats_packet_size();
is_thread_group = !!taskstats_tgid_alloc(tsk);
if (is_thread_group) {
size = 2 * size;
fill_tgid_exit(tsk);
}
listeners = __this_cpu_ptr(&listener_array);
if (list_empty(&listeners->list))
return;
rc = prepare_reply(NULL, TASKSTATS_CMD_NEW, &rep_skb, size);
if (rc < 0)
return;
stats = mk_reply(rep_skb, TASKSTATS_TYPE_PID,
task_pid_nr_ns(tsk, &init_pid_ns));
if (!stats)
goto err;
fill_stats(&init_user_ns, &init_pid_ns, tsk, stats);
if (!is_thread_group || !group_dead)
goto send;
stats = mk_reply(rep_skb, TASKSTATS_TYPE_TGID,
task_tgid_nr_ns(tsk, &init_pid_ns));
if (!stats)
goto err;
memcpy(stats, tsk->signal->stats, sizeof(*stats));
send:
send_cpu_listeners(rep_skb, listeners);
return;
err:
nlmsg_free(rep_skb);
}
void __init taskstats_init_early(void)
{
unsigned int i;
taskstats_cache = KMEM_CACHE(taskstats, SLAB_PANIC);
for_each_possible_cpu(i) {
INIT_LIST_HEAD(&(per_cpu(listener_array, i).list));
init_rwsem(&(per_cpu(listener_array, i).sem));
}
}
static int __init taskstats_init(void)
{
int rc;
rc = genl_register_family(&family);
if (rc)
return rc;
rc = genl_register_ops(&family, &taskstats_ops);
if (rc < 0)
goto err;
rc = genl_register_ops(&family, &cgroupstats_ops);
if (rc < 0)
goto err_cgroup_ops;
family_registered = 1;
pr_info("registered taskstats version %d\n", TASKSTATS_GENL_VERSION);
return 0;
err_cgroup_ops:
genl_unregister_ops(&family, &taskstats_ops);
err:
genl_unregister_family(&family);
return rc;
}
