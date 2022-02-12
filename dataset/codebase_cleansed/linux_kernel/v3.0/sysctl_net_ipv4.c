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
void inet_get_ping_group_range_table(struct ctl_table *table, gid_t *low, gid_t *high)
{
gid_t *data = table->data;
unsigned seq;
do {
seq = read_seqbegin(&sysctl_local_ports.lock);
*low = data[0];
*high = data[1];
} while (read_seqretry(&sysctl_local_ports.lock, seq));
}
static void set_ping_group_range(struct ctl_table *table, int range[2])
{
gid_t *data = table->data;
write_seqlock(&sysctl_local_ports.lock);
data[0] = range[0];
data[1] = range[1];
write_sequnlock(&sysctl_local_ports.lock);
}
static int ipv4_ping_group_range(ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret;
gid_t range[2];
ctl_table tmp = {
.data = &range,
.maxlen = sizeof(range),
.mode = table->mode,
.extra1 = &ip_ping_group_range_min,
.extra2 = &ip_ping_group_range_max,
};
inet_get_ping_group_range_table(table, range, range + 1);
ret = proc_dointvec_minmax(&tmp, write, buffer, lenp, ppos);
if (write && ret == 0)
set_ping_group_range(table, range);
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
&net->ipv4.sysctl_rt_cache_rebuild_count;
table[7].data =
&net->ipv4.sysctl_ping_group_range;
}
net->ipv4.sysctl_ping_group_range[0] = 1;
net->ipv4.sysctl_ping_group_range[1] = 0;
net->ipv4.sysctl_rt_cache_rebuild_count = 4;
net->ipv4.ipv4_hdr = register_net_sysctl_table(net,
net_ipv4_ctl_path, table);
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
hdr = register_sysctl_paths(net_ipv4_ctl_path, ipv4_table);
if (hdr == NULL)
return -ENOMEM;
if (register_pernet_subsys(&ipv4_sysctl_ops)) {
unregister_sysctl_table(hdr);
return -ENOMEM;
}
return 0;
}
