static inline struct nl_handle *nl_socket_alloc(void)
{
return nl_handle_alloc();
}
static inline void nl_socket_free(struct nl_sock *h)
{
nl_handle_destroy(h);
}
static void
iface_mon_handler2(struct nl_object *obj, void *arg)
{
struct rtnl_link *filter;
struct rtnl_link *link_obj;
int flags, up;
char *ifname;
iface_mon_cb cb = (iface_mon_cb)arg;
filter = rtnl_link_alloc();
if (!filter) {
fprintf(stderr, "error allocating filter\n");
return;
}
if (nl_object_match_filter (obj, OBJ_CAST (filter)) == 0) {
rtnl_link_put(filter);
return;
}
link_obj = (struct rtnl_link *) obj;
flags = rtnl_link_get_flags (link_obj);
ifname = rtnl_link_get_name(link_obj);
up = (flags & IFF_UP) ? 1 : 0;
cb(ifname, up);
rtnl_link_put(filter);
return;
}
static int
iface_mon_handler(struct nl_msg *msg, void *arg)
{
nl_msg_parse (msg, &iface_mon_handler2, arg);
return 0;
}
void
iface_mon_event(void)
{
nl_recvmsgs_default(iface_mon_sock);
}
int
iface_mon_get_sock(void)
{
return nl_socket_get_fd(iface_mon_sock);
}
int
iface_mon_start(iface_mon_cb cb)
{
int err;
iface_mon_sock = nl_socket_alloc();
if (!iface_mon_sock) {
fprintf(stderr, "Failed to allocate netlink socket.\n");
return -ENOMEM;
}
nl_socket_disable_seq_check(iface_mon_sock);
nl_socket_modify_cb(iface_mon_sock, NL_CB_VALID, NL_CB_CUSTOM, iface_mon_handler, cb);
if (nl_connect(iface_mon_sock, NETLINK_ROUTE)) {
fprintf(stderr, "Failed to connect to generic netlink.\n");
err = -ENOLINK;
goto out_handle_destroy;
}
nl_socket_add_membership(iface_mon_sock, RTNLGRP_LINK);
return 0;
out_handle_destroy:
nl_socket_free(iface_mon_sock);
return err;
}
void
iface_mon_stop(void)
{
if(iface_mon_sock)
nl_socket_free(iface_mon_sock);
iface_mon_sock = NULL;
}
int
iface_mon_start(iface_mon_cb cb)
{
int ret;
struct kev_request key;
s = socket(PF_SYSTEM, SOCK_RAW, SYSPROTO_EVENT);
if (s == -1)
return -errno;
key.vendor_code = KEV_VENDOR_APPLE;
key.kev_class = KEV_NETWORK_CLASS;
key.kev_subclass = KEV_DL_SUBCLASS;
if (ioctl(s, SIOCSKEVFILT, &key) == -1) {
ret = -errno;
close(s);
return ret;
}
callback = cb;
return 0;
}
void
iface_mon_stop(void)
{
close(s);
}
int
iface_mon_get_sock(void)
{
return s;
}
void
iface_mon_event(void)
{
char msg[NET_EVENT_DATA_SIZE];
ssize_t received;
struct kern_event_msg *kem;
struct net_event_data *evd;
size_t evd_len;
char ifr_name[IFNAMSIZ];
received = recv(s, msg, sizeof msg, 0);
if (received < 0) {
return;
}
if ((size_t)received < sizeof msg) {
return;
}
kem = (struct kern_event_msg *)msg;
evd_len = kem->total_size - KEV_MSG_HEADER_SIZE;
if (evd_len != sizeof (struct net_event_data)) {
return;
}
evd = (struct net_event_data *)&kem->event_data[0];
g_snprintf(ifr_name, IFNAMSIZ, "%s%u", evd->if_name, evd->if_unit);
switch (kem->event_code) {
case KEV_DL_IF_ATTACHED:
callback(ifr_name, 1);
break;
case KEV_DL_IF_DETACHED:
callback(ifr_name, 0);
break;
default:
break;
}
}
int
iface_mon_start(iface_mon_cb cb _U_)
{
return -1;
}
void
iface_mon_stop(void)
{
}
int
iface_mon_get_sock(void)
{
return -1;
}
void
iface_mon_event(void)
{
}
