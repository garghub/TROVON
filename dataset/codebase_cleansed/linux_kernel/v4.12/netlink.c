int tipc_nlmsg_parse(const struct nlmsghdr *nlh, struct nlattr ***attr)
{
u32 maxattr = tipc_genl_family.maxattr;
*attr = genl_family_attrbuf(&tipc_genl_family);
if (!*attr)
return -EOPNOTSUPP;
return nlmsg_parse(nlh, GENL_HDRLEN, *attr, maxattr, tipc_nl_policy,
NULL);
}
int __init tipc_netlink_start(void)
{
int res;
res = genl_register_family(&tipc_genl_family);
if (res) {
pr_err("Failed to register netlink interface\n");
return res;
}
return 0;
}
void tipc_netlink_stop(void)
{
genl_unregister_family(&tipc_genl_family);
}
