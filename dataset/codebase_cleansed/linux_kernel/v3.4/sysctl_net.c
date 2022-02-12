static struct ctl_table_set *
net_ctl_header_lookup(struct ctl_table_root *root, struct nsproxy *namespaces)
{
return &namespaces->net_ns->sysctls;
}
static int is_seen(struct ctl_table_set *set)
{
return &current->nsproxy->net_ns->sysctls == set;
}
static int net_ctl_permissions(struct ctl_table_root *root,
struct nsproxy *nsproxy,
struct ctl_table *table)
{
if (capable(CAP_NET_ADMIN)) {
int mode = (table->mode >> 6) & 7;
return (mode << 6) | (mode << 3) | mode;
}
return table->mode;
}
static int net_ctl_ro_header_perms(struct ctl_table_root *root,
struct nsproxy *namespaces, struct ctl_table *table)
{
if (net_eq(namespaces->net_ns, &init_net))
return table->mode;
else
return table->mode & ~0222;
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
static __init int net_sysctl_init(void)
{
int ret;
ret = register_pernet_subsys(&sysctl_pernet_ops);
if (ret)
goto out;
setup_sysctl_set(&net_sysctl_ro_root.default_set, &net_sysctl_ro_root, NULL);
register_sysctl_root(&net_sysctl_ro_root);
register_sysctl_root(&net_sysctl_root);
out:
return ret;
}
struct ctl_table_header *register_net_sysctl_table(struct net *net,
const struct ctl_path *path, struct ctl_table *table)
{
return __register_sysctl_paths(&net->sysctls, path, table);
}
struct ctl_table_header *register_net_sysctl_rotable(const
struct ctl_path *path, struct ctl_table *table)
{
return __register_sysctl_paths(&net_sysctl_ro_root.default_set,
path, table);
}
void unregister_net_sysctl_table(struct ctl_table_header *header)
{
unregister_sysctl_table(header);
}
