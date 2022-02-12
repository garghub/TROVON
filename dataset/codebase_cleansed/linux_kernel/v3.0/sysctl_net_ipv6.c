static int __net_init ipv6_sysctl_net_init(struct net *net)
{
struct ctl_table *ipv6_table;
struct ctl_table *ipv6_route_table;
struct ctl_table *ipv6_icmp_table;
int err;
err = -ENOMEM;
ipv6_table = kmemdup(ipv6_table_template, sizeof(ipv6_table_template),
GFP_KERNEL);
if (!ipv6_table)
goto out;
ipv6_route_table = ipv6_route_sysctl_init(net);
if (!ipv6_route_table)
goto out_ipv6_table;
ipv6_table[0].child = ipv6_route_table;
ipv6_icmp_table = ipv6_icmp_sysctl_init(net);
if (!ipv6_icmp_table)
goto out_ipv6_route_table;
ipv6_table[1].child = ipv6_icmp_table;
ipv6_table[2].data = &net->ipv6.sysctl.bindv6only;
net->ipv6.sysctl.table = register_net_sysctl_table(net, net_ipv6_ctl_path,
ipv6_table);
if (!net->ipv6.sysctl.table)
goto out_ipv6_icmp_table;
err = 0;
out:
return err;
out_ipv6_icmp_table:
kfree(ipv6_icmp_table);
out_ipv6_route_table:
kfree(ipv6_route_table);
out_ipv6_table:
kfree(ipv6_table);
goto out;
}
static void __net_exit ipv6_sysctl_net_exit(struct net *net)
{
struct ctl_table *ipv6_table;
struct ctl_table *ipv6_route_table;
struct ctl_table *ipv6_icmp_table;
ipv6_table = net->ipv6.sysctl.table->ctl_table_arg;
ipv6_route_table = ipv6_table[0].child;
ipv6_icmp_table = ipv6_table[1].child;
unregister_net_sysctl_table(net->ipv6.sysctl.table);
kfree(ipv6_table);
kfree(ipv6_route_table);
kfree(ipv6_icmp_table);
}
int ipv6_sysctl_register(void)
{
int err = -ENOMEM;
ip6_header = register_net_sysctl_rotable(net_ipv6_ctl_path, ipv6_rotable);
if (ip6_header == NULL)
goto out;
err = register_pernet_subsys(&ipv6_sysctl_net_ops);
if (err)
goto err_pernet;
out:
return err;
err_pernet:
unregister_net_sysctl_table(ip6_header);
goto out;
}
void ipv6_sysctl_unregister(void)
{
unregister_net_sysctl_table(ip6_header);
unregister_pernet_subsys(&ipv6_sysctl_net_ops);
}
int ipv6_static_sysctl_register(void)
{
ip6_base = register_sysctl_paths(net_ipv6_ctl_path, ipv6_static_skeleton);
if (ip6_base == NULL)
return -ENOMEM;
return 0;
}
void ipv6_static_sysctl_unregister(void)
{
unregister_net_sysctl_table(ip6_base);
}
