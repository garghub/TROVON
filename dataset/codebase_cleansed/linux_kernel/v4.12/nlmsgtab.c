static int nlmsg_perm(u16 nlmsg_type, u32 *perm, const struct nlmsg_perm *tab, size_t tabsize)
{
int i, err = -EINVAL;
for (i = 0; i < tabsize/sizeof(struct nlmsg_perm); i++)
if (nlmsg_type == tab[i].nlmsg_type) {
*perm = tab[i].perm;
err = 0;
break;
}
return err;
}
int selinux_nlmsg_lookup(u16 sclass, u16 nlmsg_type, u32 *perm)
{
int err = 0;
switch (sclass) {
case SECCLASS_NETLINK_ROUTE_SOCKET:
BUILD_BUG_ON(RTM_MAX != (RTM_NEWSTATS + 3));
err = nlmsg_perm(nlmsg_type, perm, nlmsg_route_perms,
sizeof(nlmsg_route_perms));
break;
case SECCLASS_NETLINK_TCPDIAG_SOCKET:
err = nlmsg_perm(nlmsg_type, perm, nlmsg_tcpdiag_perms,
sizeof(nlmsg_tcpdiag_perms));
break;
case SECCLASS_NETLINK_XFRM_SOCKET:
BUILD_BUG_ON(XFRM_MSG_MAX != XFRM_MSG_MAPPING);
err = nlmsg_perm(nlmsg_type, perm, nlmsg_xfrm_perms,
sizeof(nlmsg_xfrm_perms));
break;
case SECCLASS_NETLINK_AUDIT_SOCKET:
if ((nlmsg_type >= AUDIT_FIRST_USER_MSG &&
nlmsg_type <= AUDIT_LAST_USER_MSG) ||
(nlmsg_type >= AUDIT_FIRST_USER_MSG2 &&
nlmsg_type <= AUDIT_LAST_USER_MSG2)) {
*perm = NETLINK_AUDIT_SOCKET__NLMSG_RELAY;
} else {
err = nlmsg_perm(nlmsg_type, perm, nlmsg_audit_perms,
sizeof(nlmsg_audit_perms));
}
break;
default:
err = -ENOENT;
break;
}
return err;
}
