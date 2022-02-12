static void set_local_port_range(struct net *net, int range[2])
{
bool same_parity = !((range[0] ^ range[1]) & 1);
write_seqlock(&net->ipv4.ip_local_ports.lock);
if (same_parity && !net->ipv4.ip_local_ports.warned) {
net->ipv4.ip_local_ports.warned = true;
pr_err_ratelimited("ip_local_port_range: prefer different parity for start/end values.\n");
}
net->ipv4.ip_local_ports.range[0] = range[0];
net->ipv4.ip_local_ports.range[1] = range[1];
write_sequnlock(&net->ipv4.ip_local_ports.lock);
}
static int ipv4_local_port_range(struct ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
struct net *net =
container_of(table->data, struct net, ipv4.ip_local_ports.range);
int ret;
int range[2];
struct ctl_table tmp = {
.data = &range,
.maxlen = sizeof(range),
.mode = table->mode,
.extra1 = &ip_local_port_range_min,
.extra2 = &ip_local_port_range_max,
};
inet_get_local_port_range(net, &range[0], &range[1]);
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
if (write && ret == 0) {
if (range[1] < range[0])
ret = -EINVAL;
else
set_local_port_range(net, range);
}
return ret;
}
static void inet_get_ping_group_range_table(struct ctl_table *table, kgid_t *low, kgid_t *high)
{
kgid_t *data = table->data;
struct net *net =
container_of(table->data, struct net, ipv4.ping_group_range.range);
unsigned int seq;
do {
seq = read_seqbegin(&net->ipv4.ip_local_ports.lock);
*low = data[0];
*high = data[1];
} while (read_seqretry(&net->ipv4.ip_local_ports.lock, seq));
}
static void set_ping_group_range(struct ctl_table *table, kgid_t low, kgid_t high)
{
kgid_t *data = table->data;
struct net *net =
container_of(table->data, struct net, ipv4.ping_group_range.range);
write_seqlock(&net->ipv4.ip_local_ports.lock);
data[0] = low;
data[1] = high;
write_sequnlock(&net->ipv4.ip_local_ports.lock);
}
static int ipv4_ping_group_range(struct ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
struct user_namespace *user_ns = current_user_ns();
int ret;
gid_t urange[2];
kgid_t low, high;
struct ctl_table tmp = {
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
static int proc_tcp_congestion_control(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
char val[TCP_CA_NAME_MAX];
struct ctl_table tbl = {
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
static int proc_tcp_available_congestion_control(struct ctl_table *ctl,
int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
struct ctl_table tbl = { .maxlen = TCP_CA_BUF_MAX, };
int ret;
tbl.data = kmalloc(tbl.maxlen, GFP_USER);
if (!tbl.data)
return -ENOMEM;
tcp_get_available_congestion_control(tbl.data, TCP_CA_BUF_MAX);
ret = proc_dostring(&tbl, write, buffer, lenp, ppos);
kfree(tbl.data);
return ret;
}
static int proc_allowed_congestion_control(struct ctl_table *ctl,
int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
struct ctl_table tbl = { .maxlen = TCP_CA_BUF_MAX };
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
static int proc_tcp_fastopen_key(struct ctl_table *ctl, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
struct ctl_table tbl = { .maxlen = (TCP_FASTOPEN_KEY_LENGTH * 2 + 10) };
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
tcp_fastopen_init_key_once(false);
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
int i;
table = kmemdup(table, sizeof(ipv4_net_table), GFP_KERNEL);
if (!table)
goto err_alloc;
for (i = 0; i < ARRAY_SIZE(ipv4_net_table) - 1; i++)
table[i].data += (void *)net - (void *)&init_net;
}
net->ipv4.ipv4_hdr = register_net_sysctl(net, "net/ipv4", table);
if (!net->ipv4.ipv4_hdr)
goto err_reg;
net->ipv4.sysctl_local_reserved_ports = kzalloc(65536 / 8, GFP_KERNEL);
if (!net->ipv4.sysctl_local_reserved_ports)
goto err_ports;
return 0;
err_ports:
unregister_net_sysctl_table(net->ipv4.ipv4_hdr);
err_reg:
if (!net_eq(net, &init_net))
kfree(table);
err_alloc:
return -ENOMEM;
}
static __net_exit void ipv4_sysctl_exit_net(struct net *net)
{
struct ctl_table *table;
kfree(net->ipv4.sysctl_local_reserved_ports);
table = net->ipv4.ipv4_hdr->ctl_table_arg;
unregister_net_sysctl_table(net->ipv4.ipv4_hdr);
kfree(table);
}
static __init int sysctl_ipv4_init(void)
{
struct ctl_table_header *hdr;
hdr = register_net_sysctl(&init_net, "net/ipv4", ipv4_table);
if (!hdr)
return -ENOMEM;
if (register_pernet_subsys(&ipv4_sysctl_ops)) {
unregister_net_sysctl_table(hdr);
return -ENOMEM;
}
return 0;
}
