static struct ctl_table_set *
net_ctl_header_lookup(struct ctl_table_root *root, struct nsproxy *namespaces)
{
return &namespaces->net_ns->sysctls;
}
static int is_seen(struct ctl_table_set *set)
{
return &current->nsproxy->net_ns->sysctls == set;
}
static int net_ctl_permissions(struct ctl_table_header *head,
struct ctl_table *table)
{
struct net *net = container_of(head->set, struct net, sysctls);
kuid_t root_uid = make_kuid(net->user_ns, 0);
kgid_t root_gid = make_kgid(net->user_ns, 0);
if (ns_capable_noaudit(net->user_ns, CAP_NET_ADMIN) ||
uid_eq(root_uid, current_euid())) {
int mode = (table->mode >> 6) & 7;
return (mode << 6) | (mode << 3) | mode;
}
if (in_egroup_p(root_gid)) {
int mode = (table->mode >> 3) & 7;
return (mode << 3) | mode;
}
return table->mode;
}
static int __net_init sysctl_net_init(struct net *net)
{
setup_sysctl_set(&net->sysctls, &net_sysctl_root, is_seen);
return 0;
}
static void __net_exit sysctl_net_exit(struct net *net)
{
retire_sysctl_set(&net->sysctls);
}
__init int net_sysctl_init(void)
{
static struct ctl_table empty[1];
int ret = -ENOMEM;
net_header = register_sysctl("net", empty);
if (!net_header)
goto out;
ret = register_pernet_subsys(&sysctl_pernet_ops);
if (ret)
goto out1;
register_sysctl_root(&net_sysctl_root);
out:
return ret;
out1:
unregister_sysctl_table(net_header);
net_header = NULL;
goto out;
}
struct ctl_table_header *register_net_sysctl(struct net *net,
const char *path, struct ctl_table *table)
{
return __register_sysctl_table(&net->sysctls, path, table);
}
void unregister_net_sysctl_table(struct ctl_table_header *header)
{
unregister_sysctl_table(header);
}
