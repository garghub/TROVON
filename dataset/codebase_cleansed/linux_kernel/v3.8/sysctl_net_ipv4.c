static void set_local_port_range(int range[2])
{
write_seqlock(&sysctl_local_ports.lock);
sysctl_local_ports.range[0] = range[0];
sysctl_local_ports.range[1] = range[1];
write_sequnlock(&sysctl_local_ports.lock);
}
static int ipv4_local_port_range(ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret;
int range[2];
ctl_table tmp = {
.data = &range,
.maxlen = sizeof(range),
.mode = table->mode,
.extra1 = &ip_local_port_range_min,
.extra2 = &ip_local_port_range_max,
};
inet_get_local_port_range(range, range + 1);
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
if (write && ret == 0) {
if (range[1] < range[0])
ret = -EINVAL;
else
set_local_port_range(range);
}
return ret;
}
static void inet_get_ping_group_range_table(struct ctl_table *table, kgid_t *low, kgid_t *high)
{
kgid_t *data = table->data;
unsigned int seq;
do {
seq = read_seqbegin(&sysctl_local_ports.lock);
*low = data[0];
*high = data[1];
} while (read_seqretry(&sysctl_local_ports.lock, seq));
}
static void set_ping_group_range(struct ctl_table *table, kgid_t low, kgid_t high)
{
kgid_t *data = table->data;
write_seqlock(&sysctl_local_ports.lock);
data[0] = low;
data[1] = high;
write_sequnlock(&sysctl_local_ports.lock);
}
static int ipv4_ping_group_range(ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
struct user_namespace *user_ns = current_user_ns();
int ret;
gid_t urange[2];
kgid_t low, high;
ctl_table tmp = {
.data = &urange,
.maxlen = sizeof(urange),
.mode = table->mode,
.extra1 = &ip_ping_group_range_min,
.extra2 = &ip_ping_group_range_max,
};
inet_get_ping_group_range_table(table, &low, &high);
urange[0] = from_kgid_munged(user_ns, low);
urange[1] = from_kgid_munged(user_ns, high);
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
if (write && ret == 0) {
low = make_kgid(user_ns, urange[0]);
high = make_kgid(user_ns, urange[1]);
if (!gid_valid(low) || !gid_valid(high) ||
(urange[1] < urange[0]) || gid_lt(high, low)) {
low = make_kgid(&init_user_ns, 1);
high = make_kgid(&init_user_ns, 0);
}
set_ping_group_range(table, low, high);
}
return ret;
}
static int proc_tcp_congestion_control(ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
char val[TCP_CA_NAME_MAX];
ctl_table tbl = {
.data = val,
.maxlen = TCP_CA_NAME_MAX,
};
int ret;
tcp_get_default_congestion_control(val);
ret = proc_dostring(&tbl, write, buffer, lenp, ppos);
if (write && ret == 0)
ret = tcp_set_default_congestion_control(val);
return ret;
}
static int proc_tcp_available_congestion_control(ctl_table *ctl,
int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
ctl_table tbl = { .maxlen = TCP_CA_BUF_MAX, };
int ret;
tbl.data = kmalloc(tbl.maxlen, GFP_USER);
if (!tbl.data)
return -ENOMEM;
tcp_get_available_congestion_control(tbl.data, TCP_CA_BUF_MAX);
ret = proc_dostring(&tbl, write, buffer, lenp, ppos);
kfree(tbl.data);
return ret;
}
static int proc_allowed_congestion_control(ctl_table *ctl,
int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
ctl_table tbl = { .maxlen = TCP_CA_BUF_MAX };
int ret;
tbl.data = kmalloc(tbl.maxlen, GFP_USER);
if (!tbl.data)
return -ENOMEM;
tcp_get_allowed_congestion_control(tbl.data, tbl.maxlen);
ret = proc_dostring(&tbl, write, buffer, lenp, ppos);
if (write && ret == 0)
ret = tcp_set_allowed_congestion_control(tbl.data);
kfree(tbl.data);
return ret;
}
static int ipv4_tcp_mem(ctl_table *ctl, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret;
unsigned long vec[3];
struct net *net = current->nsproxy->net_ns;
#ifdef CONFIG_MEMCG_KMEM
struct mem_cgroup *memcg;
#endif
ctl_table tmp = {
.data = &vec,
.maxlen = sizeof(vec),
.mode = ctl->mode,
};
if (!write) {
ctl->data = &net->ipv4.sysctl_tcp_mem;
return proc_doulongvec_minmax(ctl, write, buffer, lenp, ppos);
}
ret = proc_doulongvec_minmax(&tmp, write, buffer, lenp, ppos);
if (ret)
return ret;
#ifdef CONFIG_MEMCG_KMEM
rcu_read_lock();
memcg = mem_cgroup_from_task(current);
tcp_prot_mem(memcg, vec[0], 0);
tcp_prot_mem(memcg, vec[1], 1);
tcp_prot_mem(memcg, vec[2], 2);
rcu_read_unlock();
#endif
net->ipv4.sysctl_tcp_mem[0] = vec[0];
net->ipv4.sysctl_tcp_mem[1] = vec[1];
net->ipv4.sysctl_tcp_mem[2] = vec[2];
return 0;
}
int proc_tcp_fastopen_key(ctl_table *ctl, int write, void __user *buffer,
size_t *lenp, loff_t *ppos)
{
ctl_table tbl = { .maxlen = (TCP_FASTOPEN_KEY_LENGTH * 2 + 10) };
struct tcp_fastopen_context *ctxt;
int ret;
u32 user_key[4];
tbl.data = kmalloc(tbl.maxlen, GFP_KERNEL);
if (!tbl.data)
return -ENOMEM;
rcu_read_lock();
ctxt = rcu_dereference(tcp_fastopen_ctx);
if (ctxt)
memcpy(user_key, ctxt->key, TCP_FASTOPEN_KEY_LENGTH);
else
memset(user_key, 0, sizeof(user_key));
rcu_read_unlock();
snprintf(tbl.data, tbl.maxlen, "%08x-%08x-%08x-%08x",
user_key[0], user_key[1], user_key[2], user_key[3]);
ret = proc_dostring(&tbl, write, buffer, lenp, ppos);
if (write && ret == 0) {
if (sscanf(tbl.data, "%x-%x-%x-%x", user_key, user_key + 1,
user_key + 2, user_key + 3) != 4) {
ret = -EINVAL;
goto bad_key;
}
tcp_fastopen_reset_cipher(user_key, TCP_FASTOPEN_KEY_LENGTH);
}
bad_key:
pr_debug("proc FO key set 0x%x-%x-%x-%x <- 0x%s: %u\n",
user_key[0], user_key[1], user_key[2], user_key[3],
(char *)tbl.data, ret);
kfree(tbl.data);
return ret;
}
static __net_init int ipv4_sysctl_init_net(struct net *net)
{
struct ctl_table *table;
table = ipv4_net_table;
if (!net_eq(net, &init_net)) {
table = kmemdup(table, sizeof(ipv4_net_table), GFP_KERNEL);
if (table == NULL)
goto err_alloc;
table[0].data =
&net->ipv4.sysctl_icmp_echo_ignore_all;
table[1].data =
&net->ipv4.sysctl_icmp_echo_ignore_broadcasts;
table[2].data =
&net->ipv4.sysctl_icmp_ignore_bogus_error_responses;
table[3].data =
&net->ipv4.sysctl_icmp_errors_use_inbound_ifaddr;
table[4].data =
&net->ipv4.sysctl_icmp_ratelimit;
table[5].data =
&net->ipv4.sysctl_icmp_ratemask;
table[6].data =
&net->ipv4.sysctl_ping_group_range;
if (net->user_ns != &init_user_ns)
table[0].procname = NULL;
}
net->ipv4.sysctl_ping_group_range[0] = make_kgid(&init_user_ns, 1);
net->ipv4.sysctl_ping_group_range[1] = make_kgid(&init_user_ns, 0);
tcp_init_mem(net);
net->ipv4.ipv4_hdr = register_net_sysctl(net, "net/ipv4", table);
if (net->ipv4.ipv4_hdr == NULL)
goto err_reg;
return 0;
err_reg:
if (!net_eq(net, &init_net))
kfree(table);
err_alloc:
return -ENOMEM;
}
static __net_exit void ipv4_sysctl_exit_net(struct net *net)
{
struct ctl_table *table;
table = net->ipv4.ipv4_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->ipv4.ipv4_hdr);
kfree(table);
}
static __init int sysctl_ipv4_init(void)
{
struct ctl_table_header *hdr;
struct ctl_table *i;
for (i = ipv4_table; i->procname; i++) {
if (strcmp(i->procname, "ip_local_reserved_ports") == 0) {
i->data = sysctl_local_reserved_ports;
break;
}
}
if (!i->procname)
return -EINVAL;
hdr = register_net_sysctl(&init_net, "net/ipv4", ipv4_table);
if (hdr == NULL)
return -ENOMEM;
if (register_pernet_subsys(&ipv4_sysctl_ops)) {
unregister_net_sysctl_table(hdr);
return -ENOMEM;
}
return 0;
}
