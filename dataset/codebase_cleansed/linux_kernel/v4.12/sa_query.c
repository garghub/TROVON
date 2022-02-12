static inline void ib_sa_disable_local_svc(struct ib_sa_query *query)
{
query->flags &= ~IB_SA_ENABLE_LOCAL_SERVICE;
}
static inline int ib_sa_query_cancelled(struct ib_sa_query *query)
{
return (query->flags & IB_SA_CANCEL);
}
static void ib_nl_set_path_rec_attrs(struct sk_buff *skb,
struct ib_sa_query *query)
{
struct sa_path_rec *sa_rec = query->mad_buf->context[1];
struct ib_sa_mad *mad = query->mad_buf->mad;
ib_sa_comp_mask comp_mask = mad->sa_hdr.comp_mask;
u16 val16;
u64 val64;
struct rdma_ls_resolve_header *header;
query->mad_buf->context[1] = NULL;
header = (struct rdma_ls_resolve_header *)
skb_put(skb, NLMSG_ALIGN(sizeof(*header)));
memcpy(header->device_name, query->port->agent->device->name,
LS_DEVICE_NAME_MAX);
header->port_num = query->port->port_num;
if ((comp_mask & IB_SA_PATH_REC_REVERSIBLE) &&
sa_rec->reversible != 0)
query->path_use = LS_RESOLVE_PATH_USE_GMP;
else
query->path_use = LS_RESOLVE_PATH_USE_UNIDIRECTIONAL;
header->path_use = query->path_use;
if (comp_mask & IB_SA_PATH_REC_SERVICE_ID) {
val64 = be64_to_cpu(sa_rec->service_id);
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_SERVICE_ID,
sizeof(val64), &val64);
}
if (comp_mask & IB_SA_PATH_REC_DGID)
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_DGID,
sizeof(sa_rec->dgid), &sa_rec->dgid);
if (comp_mask & IB_SA_PATH_REC_SGID)
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_SGID,
sizeof(sa_rec->sgid), &sa_rec->sgid);
if (comp_mask & IB_SA_PATH_REC_TRAFFIC_CLASS)
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_TCLASS,
sizeof(sa_rec->traffic_class), &sa_rec->traffic_class);
if (comp_mask & IB_SA_PATH_REC_PKEY) {
val16 = be16_to_cpu(sa_rec->pkey);
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_PKEY,
sizeof(val16), &val16);
}
if (comp_mask & IB_SA_PATH_REC_QOS_CLASS) {
val16 = be16_to_cpu(sa_rec->qos_class);
nla_put(skb, RDMA_NLA_F_MANDATORY | LS_NLA_TYPE_QOS_CLASS,
sizeof(val16), &val16);
}
}
static int ib_nl_get_path_rec_attrs_len(ib_sa_comp_mask comp_mask)
{
int len = 0;
if (comp_mask & IB_SA_PATH_REC_SERVICE_ID)
len += nla_total_size(sizeof(u64));
if (comp_mask & IB_SA_PATH_REC_DGID)
len += nla_total_size(sizeof(struct rdma_nla_ls_gid));
if (comp_mask & IB_SA_PATH_REC_SGID)
len += nla_total_size(sizeof(struct rdma_nla_ls_gid));
if (comp_mask & IB_SA_PATH_REC_TRAFFIC_CLASS)
len += nla_total_size(sizeof(u8));
if (comp_mask & IB_SA_PATH_REC_PKEY)
len += nla_total_size(sizeof(u16));
if (comp_mask & IB_SA_PATH_REC_QOS_CLASS)
len += nla_total_size(sizeof(u16));
if (WARN_ON(len == 0))
return len;
len += NLMSG_ALIGN(sizeof(struct rdma_ls_resolve_header));
return len;
}
static int ib_nl_send_msg(struct ib_sa_query *query, gfp_t gfp_mask)
{
struct sk_buff *skb = NULL;
struct nlmsghdr *nlh;
void *data;
int ret = 0;
struct ib_sa_mad *mad;
int len;
mad = query->mad_buf->mad;
len = ib_nl_get_path_rec_attrs_len(mad->sa_hdr.comp_mask);
if (len <= 0)
return -EMSGSIZE;
skb = nlmsg_new(len, gfp_mask);
if (!skb)
return -ENOMEM;
data = ibnl_put_msg(skb, &nlh, query->seq, 0, RDMA_NL_LS,
RDMA_NL_LS_OP_RESOLVE, NLM_F_REQUEST);
if (!data) {
nlmsg_free(skb);
return -EMSGSIZE;
}
ib_nl_set_path_rec_attrs(skb, query);
nlmsg_end(skb, nlh);
ret = ibnl_multicast(skb, nlh, RDMA_NL_GROUP_LS, gfp_mask);
if (!ret)
ret = len;
else
ret = 0;
return ret;
}
static int ib_nl_make_request(struct ib_sa_query *query, gfp_t gfp_mask)
{
unsigned long flags;
unsigned long delay;
int ret;
INIT_LIST_HEAD(&query->list);
query->seq = (u32)atomic_inc_return(&ib_nl_sa_request_seq);
spin_lock_irqsave(&ib_nl_request_lock, flags);
delay = msecs_to_jiffies(sa_local_svc_timeout_ms);
query->timeout = delay + jiffies;
list_add_tail(&query->list, &ib_nl_request_list);
if (ib_nl_request_list.next == &query->list)
queue_delayed_work(ib_nl_wq, &ib_nl_timed_work, delay);
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
ret = ib_nl_send_msg(query, gfp_mask);
if (ret <= 0) {
ret = -EIO;
spin_lock_irqsave(&ib_nl_request_lock, flags);
list_del(&query->list);
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
} else {
ret = 0;
}
return ret;
}
static int ib_nl_cancel_request(struct ib_sa_query *query)
{
unsigned long flags;
struct ib_sa_query *wait_query;
int found = 0;
spin_lock_irqsave(&ib_nl_request_lock, flags);
list_for_each_entry(wait_query, &ib_nl_request_list, list) {
if (query == wait_query) {
query->flags |= IB_SA_CANCEL;
query->timeout = jiffies;
list_move(&query->list, &ib_nl_request_list);
found = 1;
mod_delayed_work(ib_nl_wq, &ib_nl_timed_work, 1);
break;
}
}
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
return found;
}
static void ib_nl_process_good_resolve_rsp(struct ib_sa_query *query,
const struct nlmsghdr *nlh)
{
struct ib_mad_send_wc mad_send_wc;
struct ib_sa_mad *mad = NULL;
const struct nlattr *head, *curr;
struct ib_path_rec_data *rec;
int len, rem;
u32 mask = 0;
int status = -EIO;
if (query->callback) {
head = (const struct nlattr *) nlmsg_data(nlh);
len = nlmsg_len(nlh);
switch (query->path_use) {
case LS_RESOLVE_PATH_USE_UNIDIRECTIONAL:
mask = IB_PATH_PRIMARY | IB_PATH_OUTBOUND;
break;
case LS_RESOLVE_PATH_USE_ALL:
case LS_RESOLVE_PATH_USE_GMP:
default:
mask = IB_PATH_PRIMARY | IB_PATH_GMP |
IB_PATH_BIDIRECTIONAL;
break;
}
nla_for_each_attr(curr, head, len, rem) {
if (curr->nla_type == LS_NLA_TYPE_PATH_RECORD) {
rec = nla_data(curr);
if ((rec->flags & mask) == mask) {
mad = query->mad_buf->mad;
mad->mad_hdr.method |=
IB_MGMT_METHOD_RESP;
memcpy(mad->data, rec->path_rec,
sizeof(rec->path_rec));
status = 0;
break;
}
}
}
query->callback(query, status, mad);
}
mad_send_wc.send_buf = query->mad_buf;
mad_send_wc.status = IB_WC_SUCCESS;
send_handler(query->mad_buf->mad_agent, &mad_send_wc);
}
static void ib_nl_request_timeout(struct work_struct *work)
{
unsigned long flags;
struct ib_sa_query *query;
unsigned long delay;
struct ib_mad_send_wc mad_send_wc;
int ret;
spin_lock_irqsave(&ib_nl_request_lock, flags);
while (!list_empty(&ib_nl_request_list)) {
query = list_entry(ib_nl_request_list.next,
struct ib_sa_query, list);
if (time_after(query->timeout, jiffies)) {
delay = query->timeout - jiffies;
if ((long)delay <= 0)
delay = 1;
queue_delayed_work(ib_nl_wq, &ib_nl_timed_work, delay);
break;
}
list_del(&query->list);
ib_sa_disable_local_svc(query);
if (ib_sa_query_cancelled(query))
ret = -1;
else
ret = ib_post_send_mad(query->mad_buf, NULL);
if (ret) {
mad_send_wc.send_buf = query->mad_buf;
mad_send_wc.status = IB_WC_WR_FLUSH_ERR;
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
send_handler(query->port->agent, &mad_send_wc);
spin_lock_irqsave(&ib_nl_request_lock, flags);
}
}
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
}
int ib_nl_handle_set_timeout(struct sk_buff *skb,
struct netlink_callback *cb)
{
const struct nlmsghdr *nlh = (struct nlmsghdr *)cb->nlh;
int timeout, delta, abs_delta;
const struct nlattr *attr;
unsigned long flags;
struct ib_sa_query *query;
long delay = 0;
struct nlattr *tb[LS_NLA_TYPE_MAX];
int ret;
if (!(nlh->nlmsg_flags & NLM_F_REQUEST) ||
!(NETLINK_CB(skb).sk) ||
!netlink_capable(skb, CAP_NET_ADMIN))
return -EPERM;
ret = nla_parse(tb, LS_NLA_TYPE_MAX - 1, nlmsg_data(nlh),
nlmsg_len(nlh), ib_nl_policy, NULL);
attr = (const struct nlattr *)tb[LS_NLA_TYPE_TIMEOUT];
if (ret || !attr)
goto settimeout_out;
timeout = *(int *) nla_data(attr);
if (timeout < IB_SA_LOCAL_SVC_TIMEOUT_MIN)
timeout = IB_SA_LOCAL_SVC_TIMEOUT_MIN;
if (timeout > IB_SA_LOCAL_SVC_TIMEOUT_MAX)
timeout = IB_SA_LOCAL_SVC_TIMEOUT_MAX;
delta = timeout - sa_local_svc_timeout_ms;
if (delta < 0)
abs_delta = -delta;
else
abs_delta = delta;
if (delta != 0) {
spin_lock_irqsave(&ib_nl_request_lock, flags);
sa_local_svc_timeout_ms = timeout;
list_for_each_entry(query, &ib_nl_request_list, list) {
if (delta < 0 && abs_delta > query->timeout)
query->timeout = 0;
else
query->timeout += delta;
if (!delay) {
delay = query->timeout - jiffies;
if (delay <= 0)
delay = 1;
}
}
if (delay)
mod_delayed_work(ib_nl_wq, &ib_nl_timed_work,
(unsigned long)delay);
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
}
settimeout_out:
return skb->len;
}
static inline int ib_nl_is_good_resolve_resp(const struct nlmsghdr *nlh)
{
struct nlattr *tb[LS_NLA_TYPE_MAX];
int ret;
if (nlh->nlmsg_flags & RDMA_NL_LS_F_ERR)
return 0;
ret = nla_parse(tb, LS_NLA_TYPE_MAX - 1, nlmsg_data(nlh),
nlmsg_len(nlh), ib_nl_policy, NULL);
if (ret)
return 0;
return 1;
}
int ib_nl_handle_resolve_resp(struct sk_buff *skb,
struct netlink_callback *cb)
{
const struct nlmsghdr *nlh = (struct nlmsghdr *)cb->nlh;
unsigned long flags;
struct ib_sa_query *query;
struct ib_mad_send_buf *send_buf;
struct ib_mad_send_wc mad_send_wc;
int found = 0;
int ret;
if ((nlh->nlmsg_flags & NLM_F_REQUEST) ||
!(NETLINK_CB(skb).sk) ||
!netlink_capable(skb, CAP_NET_ADMIN))
return -EPERM;
spin_lock_irqsave(&ib_nl_request_lock, flags);
list_for_each_entry(query, &ib_nl_request_list, list) {
if (nlh->nlmsg_seq == query->seq) {
found = !ib_sa_query_cancelled(query);
if (found)
list_del(&query->list);
break;
}
}
if (!found) {
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
goto resp_out;
}
send_buf = query->mad_buf;
if (!ib_nl_is_good_resolve_resp(nlh)) {
ib_sa_disable_local_svc(query);
ret = ib_post_send_mad(query->mad_buf, NULL);
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
if (ret) {
mad_send_wc.send_buf = send_buf;
mad_send_wc.status = IB_WC_GENERAL_ERR;
send_handler(query->port->agent, &mad_send_wc);
}
} else {
spin_unlock_irqrestore(&ib_nl_request_lock, flags);
ib_nl_process_good_resolve_rsp(query, nlh);
}
resp_out:
return skb->len;
}
static void free_sm_ah(struct kref *kref)
{
struct ib_sa_sm_ah *sm_ah = container_of(kref, struct ib_sa_sm_ah, ref);
rdma_destroy_ah(sm_ah->ah);
kfree(sm_ah);
}
void ib_sa_register_client(struct ib_sa_client *client)
{
atomic_set(&client->users, 1);
init_completion(&client->comp);
}
void ib_sa_unregister_client(struct ib_sa_client *client)
{
ib_sa_client_put(client);
wait_for_completion(&client->comp);
}
void ib_sa_cancel_query(int id, struct ib_sa_query *query)
{
unsigned long flags;
struct ib_mad_agent *agent;
struct ib_mad_send_buf *mad_buf;
spin_lock_irqsave(&idr_lock, flags);
if (idr_find(&query_idr, id) != query) {
spin_unlock_irqrestore(&idr_lock, flags);
return;
}
agent = query->port->agent;
mad_buf = query->mad_buf;
spin_unlock_irqrestore(&idr_lock, flags);
if (!ib_nl_cancel_request(query))
ib_cancel_mad(agent, mad_buf);
}
static u8 get_src_path_mask(struct ib_device *device, u8 port_num)
{
struct ib_sa_device *sa_dev;
struct ib_sa_port *port;
unsigned long flags;
u8 src_path_mask;
sa_dev = ib_get_client_data(device, &sa_client);
if (!sa_dev)
return 0x7f;
port = &sa_dev->port[port_num - sa_dev->start_port];
spin_lock_irqsave(&port->ah_lock, flags);
src_path_mask = port->sm_ah ? port->sm_ah->src_path_mask : 0x7f;
spin_unlock_irqrestore(&port->ah_lock, flags);
return src_path_mask;
}
int ib_init_ah_from_path(struct ib_device *device, u8 port_num,
struct sa_path_rec *rec,
struct rdma_ah_attr *ah_attr)
{
int ret;
u16 gid_index;
int use_roce;
struct net_device *ndev = NULL;
memset(ah_attr, 0, sizeof *ah_attr);
ah_attr->type = rdma_ah_find_type(device, port_num);
rdma_ah_set_dlid(ah_attr, be32_to_cpu(sa_path_get_dlid(rec)));
rdma_ah_set_sl(ah_attr, rec->sl);
rdma_ah_set_path_bits(ah_attr, be32_to_cpu(sa_path_get_slid(rec)) &
get_src_path_mask(device, port_num));
rdma_ah_set_port_num(ah_attr, port_num);
rdma_ah_set_static_rate(ah_attr, rec->rate);
use_roce = rdma_cap_eth_ah(device, port_num);
if (use_roce) {
struct net_device *idev;
struct net_device *resolved_dev;
struct rdma_dev_addr dev_addr = {
.bound_dev_if = ((sa_path_get_ifindex(rec) >= 0) ?
sa_path_get_ifindex(rec) : 0),
.net = sa_path_get_ndev(rec) ?
sa_path_get_ndev(rec) :
&init_net
};
union {
struct sockaddr _sockaddr;
struct sockaddr_in _sockaddr_in;
struct sockaddr_in6 _sockaddr_in6;
} sgid_addr, dgid_addr;
if (!device->get_netdev)
return -EOPNOTSUPP;
rdma_gid2ip(&sgid_addr._sockaddr, &rec->sgid);
rdma_gid2ip(&dgid_addr._sockaddr, &rec->dgid);
ret = rdma_resolve_ip_route(&sgid_addr._sockaddr,
&dgid_addr._sockaddr, &dev_addr);
if (ret)
return ret;
if ((dev_addr.network == RDMA_NETWORK_IPV4 ||
dev_addr.network == RDMA_NETWORK_IPV6) &&
rec->rec_type != SA_PATH_REC_TYPE_ROCE_V2)
return -EINVAL;
idev = device->get_netdev(device, port_num);
if (!idev)
return -ENODEV;
resolved_dev = dev_get_by_index(dev_addr.net,
dev_addr.bound_dev_if);
if (resolved_dev->flags & IFF_LOOPBACK) {
dev_put(resolved_dev);
resolved_dev = idev;
dev_hold(resolved_dev);
}
ndev = ib_get_ndev_from_path(rec);
rcu_read_lock();
if ((ndev && ndev != resolved_dev) ||
(resolved_dev != idev &&
!rdma_is_upper_dev_rcu(idev, resolved_dev)))
ret = -EHOSTUNREACH;
rcu_read_unlock();
dev_put(idev);
dev_put(resolved_dev);
if (ret) {
if (ndev)
dev_put(ndev);
return ret;
}
}
if (rec->hop_limit > 0 || use_roce) {
enum ib_gid_type type = sa_conv_pathrec_to_gid_type(rec);
ret = ib_find_cached_gid_by_port(device, &rec->sgid, type,
port_num, ndev, &gid_index);
if (ret) {
if (ndev)
dev_put(ndev);
return ret;
}
rdma_ah_set_grh(ah_attr, &rec->dgid,
be32_to_cpu(rec->flow_label),
gid_index, rec->hop_limit,
rec->traffic_class);
if (ndev)
dev_put(ndev);
}
if (use_roce) {
u8 *dmac = sa_path_get_dmac(rec);
if (!dmac)
return -EINVAL;
memcpy(ah_attr->roce.dmac, dmac, ETH_ALEN);
}
return 0;
}
static int alloc_mad(struct ib_sa_query *query, gfp_t gfp_mask)
{
unsigned long flags;
spin_lock_irqsave(&query->port->ah_lock, flags);
if (!query->port->sm_ah) {
spin_unlock_irqrestore(&query->port->ah_lock, flags);
return -EAGAIN;
}
kref_get(&query->port->sm_ah->ref);
query->sm_ah = query->port->sm_ah;
spin_unlock_irqrestore(&query->port->ah_lock, flags);
query->mad_buf = ib_create_send_mad(query->port->agent, 1,
query->sm_ah->pkey_index,
0, IB_MGMT_SA_HDR, IB_MGMT_SA_DATA,
gfp_mask,
((query->flags & IB_SA_QUERY_OPA) ?
OPA_MGMT_BASE_VERSION :
IB_MGMT_BASE_VERSION));
if (IS_ERR(query->mad_buf)) {
kref_put(&query->sm_ah->ref, free_sm_ah);
return -ENOMEM;
}
query->mad_buf->ah = query->sm_ah->ah;
return 0;
}
static void free_mad(struct ib_sa_query *query)
{
ib_free_send_mad(query->mad_buf);
kref_put(&query->sm_ah->ref, free_sm_ah);
}
static void init_mad(struct ib_sa_query *query, struct ib_mad_agent *agent)
{
struct ib_sa_mad *mad = query->mad_buf->mad;
unsigned long flags;
memset(mad, 0, sizeof *mad);
if (query->flags & IB_SA_QUERY_OPA) {
mad->mad_hdr.base_version = OPA_MGMT_BASE_VERSION;
mad->mad_hdr.class_version = OPA_SA_CLASS_VERSION;
} else {
mad->mad_hdr.base_version = IB_MGMT_BASE_VERSION;
mad->mad_hdr.class_version = IB_SA_CLASS_VERSION;
}
mad->mad_hdr.mgmt_class = IB_MGMT_CLASS_SUBN_ADM;
spin_lock_irqsave(&tid_lock, flags);
mad->mad_hdr.tid =
cpu_to_be64(((u64) agent->hi_tid) << 32 | tid++);
spin_unlock_irqrestore(&tid_lock, flags);
}
static int send_mad(struct ib_sa_query *query, int timeout_ms, gfp_t gfp_mask)
{
bool preload = gfpflags_allow_blocking(gfp_mask);
unsigned long flags;
int ret, id;
if (preload)
idr_preload(gfp_mask);
spin_lock_irqsave(&idr_lock, flags);
id = idr_alloc(&query_idr, query, 0, 0, GFP_NOWAIT);
spin_unlock_irqrestore(&idr_lock, flags);
if (preload)
idr_preload_end();
if (id < 0)
return id;
query->mad_buf->timeout_ms = timeout_ms;
query->mad_buf->context[0] = query;
query->id = id;
if ((query->flags & IB_SA_ENABLE_LOCAL_SERVICE) &&
(!(query->flags & IB_SA_QUERY_OPA))) {
if (!ibnl_chk_listeners(RDMA_NL_GROUP_LS)) {
if (!ib_nl_make_request(query, gfp_mask))
return id;
}
ib_sa_disable_local_svc(query);
}
ret = ib_post_send_mad(query->mad_buf, NULL);
if (ret) {
spin_lock_irqsave(&idr_lock, flags);
idr_remove(&query_idr, id);
spin_unlock_irqrestore(&idr_lock, flags);
}
return ret ? ret : id;
}
void ib_sa_unpack_path(void *attribute, struct sa_path_rec *rec)
{
ib_unpack(path_rec_table, ARRAY_SIZE(path_rec_table), attribute, rec);
}
void ib_sa_pack_path(struct sa_path_rec *rec, void *attribute)
{
ib_pack(path_rec_table, ARRAY_SIZE(path_rec_table), rec, attribute);
}
static bool ib_sa_opa_pathrecord_support(struct ib_sa_client *client,
struct ib_device *device,
u8 port_num)
{
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
unsigned long flags;
bool ret = false;
if (!sa_dev)
return ret;
port = &sa_dev->port[port_num - sa_dev->start_port];
spin_lock_irqsave(&port->classport_lock, flags);
if (!port->classport_info.valid)
goto ret;
if (port->classport_info.data.type == RDMA_CLASS_PORT_INFO_OPA)
ret = opa_get_cpi_capmask2(&port->classport_info.data.opa) &
OPA_CLASS_PORT_INFO_PR_SUPPORT;
ret:
spin_unlock_irqrestore(&port->classport_lock, flags);
return ret;
}
static int opa_pr_query_possible(struct ib_sa_client *client,
struct ib_device *device,
u8 port_num,
struct sa_path_rec *rec)
{
struct ib_port_attr port_attr;
if (ib_query_port(device, port_num, &port_attr))
return PR_NOT_SUPPORTED;
if (ib_sa_opa_pathrecord_support(client, device, port_num))
return PR_OPA_SUPPORTED;
if (port_attr.lid >= be16_to_cpu(IB_MULTICAST_LID_BASE))
return PR_NOT_SUPPORTED;
else
return PR_IB_SUPPORTED;
}
static void ib_sa_path_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
struct ib_sa_path_query *query =
container_of(sa_query, struct ib_sa_path_query, sa_query);
if (mad) {
struct sa_path_rec rec;
if (sa_query->flags & IB_SA_QUERY_OPA) {
ib_unpack(opa_path_rec_table,
ARRAY_SIZE(opa_path_rec_table),
mad->data, &rec);
rec.rec_type = SA_PATH_REC_TYPE_OPA;
query->callback(status, &rec, query->context);
} else {
ib_unpack(path_rec_table,
ARRAY_SIZE(path_rec_table),
mad->data, &rec);
rec.rec_type = SA_PATH_REC_TYPE_IB;
sa_path_set_ndev(&rec, NULL);
sa_path_set_ifindex(&rec, 0);
sa_path_set_dmac_zero(&rec);
if (query->conv_pr) {
struct sa_path_rec opa;
memset(&opa, 0, sizeof(struct sa_path_rec));
sa_convert_path_ib_to_opa(&opa, &rec);
query->callback(status, &opa, query->context);
} else {
query->callback(status, &rec, query->context);
}
}
} else
query->callback(status, NULL, query->context);
}
static void ib_sa_path_rec_release(struct ib_sa_query *sa_query)
{
struct ib_sa_path_query *query =
container_of(sa_query, struct ib_sa_path_query, sa_query);
kfree(query->conv_pr);
kfree(query);
}
int ib_sa_path_rec_get(struct ib_sa_client *client,
struct ib_device *device, u8 port_num,
struct sa_path_rec *rec,
ib_sa_comp_mask comp_mask,
int timeout_ms, gfp_t gfp_mask,
void (*callback)(int status,
struct sa_path_rec *resp,
void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_sa_path_query *query;
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
struct ib_mad_agent *agent;
struct ib_sa_mad *mad;
enum opa_pr_supported status;
int ret;
if (!sa_dev)
return -ENODEV;
if ((rec->rec_type != SA_PATH_REC_TYPE_IB) &&
(rec->rec_type != SA_PATH_REC_TYPE_OPA))
return -EINVAL;
port = &sa_dev->port[port_num - sa_dev->start_port];
agent = port->agent;
query = kzalloc(sizeof(*query), gfp_mask);
if (!query)
return -ENOMEM;
query->sa_query.port = port;
if (rec->rec_type == SA_PATH_REC_TYPE_OPA) {
status = opa_pr_query_possible(client, device, port_num, rec);
if (status == PR_NOT_SUPPORTED) {
ret = -EINVAL;
goto err1;
} else if (status == PR_OPA_SUPPORTED) {
query->sa_query.flags |= IB_SA_QUERY_OPA;
} else {
query->conv_pr =
kmalloc(sizeof(*query->conv_pr), gfp_mask);
if (!query->conv_pr) {
ret = -ENOMEM;
goto err1;
}
}
}
ret = alloc_mad(&query->sa_query, gfp_mask);
if (ret)
goto err2;
ib_sa_client_get(client);
query->sa_query.client = client;
query->callback = callback;
query->context = context;
mad = query->sa_query.mad_buf->mad;
init_mad(&query->sa_query, agent);
query->sa_query.callback = callback ? ib_sa_path_rec_callback : NULL;
query->sa_query.release = ib_sa_path_rec_release;
mad->mad_hdr.method = IB_MGMT_METHOD_GET;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_PATH_REC);
mad->sa_hdr.comp_mask = comp_mask;
if (query->sa_query.flags & IB_SA_QUERY_OPA) {
ib_pack(opa_path_rec_table, ARRAY_SIZE(opa_path_rec_table),
rec, mad->data);
} else if (query->conv_pr) {
sa_convert_path_opa_to_ib(query->conv_pr, rec);
ib_pack(path_rec_table, ARRAY_SIZE(path_rec_table),
query->conv_pr, mad->data);
} else {
ib_pack(path_rec_table, ARRAY_SIZE(path_rec_table),
rec, mad->data);
}
*sa_query = &query->sa_query;
query->sa_query.flags |= IB_SA_ENABLE_LOCAL_SERVICE;
query->sa_query.mad_buf->context[1] = (query->conv_pr) ?
query->conv_pr : rec;
ret = send_mad(&query->sa_query, timeout_ms, gfp_mask);
if (ret < 0)
goto err3;
return ret;
err3:
*sa_query = NULL;
ib_sa_client_put(query->sa_query.client);
free_mad(&query->sa_query);
err2:
kfree(query->conv_pr);
err1:
kfree(query);
return ret;
}
static void ib_sa_service_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
struct ib_sa_service_query *query =
container_of(sa_query, struct ib_sa_service_query, sa_query);
if (mad) {
struct ib_sa_service_rec rec;
ib_unpack(service_rec_table, ARRAY_SIZE(service_rec_table),
mad->data, &rec);
query->callback(status, &rec, query->context);
} else
query->callback(status, NULL, query->context);
}
static void ib_sa_service_rec_release(struct ib_sa_query *sa_query)
{
kfree(container_of(sa_query, struct ib_sa_service_query, sa_query));
}
int ib_sa_service_rec_query(struct ib_sa_client *client,
struct ib_device *device, u8 port_num, u8 method,
struct ib_sa_service_rec *rec,
ib_sa_comp_mask comp_mask,
int timeout_ms, gfp_t gfp_mask,
void (*callback)(int status,
struct ib_sa_service_rec *resp,
void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_sa_service_query *query;
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
struct ib_mad_agent *agent;
struct ib_sa_mad *mad;
int ret;
if (!sa_dev)
return -ENODEV;
port = &sa_dev->port[port_num - sa_dev->start_port];
agent = port->agent;
if (method != IB_MGMT_METHOD_GET &&
method != IB_MGMT_METHOD_SET &&
method != IB_SA_METHOD_DELETE)
return -EINVAL;
query = kzalloc(sizeof(*query), gfp_mask);
if (!query)
return -ENOMEM;
query->sa_query.port = port;
ret = alloc_mad(&query->sa_query, gfp_mask);
if (ret)
goto err1;
ib_sa_client_get(client);
query->sa_query.client = client;
query->callback = callback;
query->context = context;
mad = query->sa_query.mad_buf->mad;
init_mad(&query->sa_query, agent);
query->sa_query.callback = callback ? ib_sa_service_rec_callback : NULL;
query->sa_query.release = ib_sa_service_rec_release;
mad->mad_hdr.method = method;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_SERVICE_REC);
mad->sa_hdr.comp_mask = comp_mask;
ib_pack(service_rec_table, ARRAY_SIZE(service_rec_table),
rec, mad->data);
*sa_query = &query->sa_query;
ret = send_mad(&query->sa_query, timeout_ms, gfp_mask);
if (ret < 0)
goto err2;
return ret;
err2:
*sa_query = NULL;
ib_sa_client_put(query->sa_query.client);
free_mad(&query->sa_query);
err1:
kfree(query);
return ret;
}
static void ib_sa_mcmember_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
struct ib_sa_mcmember_query *query =
container_of(sa_query, struct ib_sa_mcmember_query, sa_query);
if (mad) {
struct ib_sa_mcmember_rec rec;
ib_unpack(mcmember_rec_table, ARRAY_SIZE(mcmember_rec_table),
mad->data, &rec);
query->callback(status, &rec, query->context);
} else
query->callback(status, NULL, query->context);
}
static void ib_sa_mcmember_rec_release(struct ib_sa_query *sa_query)
{
kfree(container_of(sa_query, struct ib_sa_mcmember_query, sa_query));
}
int ib_sa_mcmember_rec_query(struct ib_sa_client *client,
struct ib_device *device, u8 port_num,
u8 method,
struct ib_sa_mcmember_rec *rec,
ib_sa_comp_mask comp_mask,
int timeout_ms, gfp_t gfp_mask,
void (*callback)(int status,
struct ib_sa_mcmember_rec *resp,
void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_sa_mcmember_query *query;
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
struct ib_mad_agent *agent;
struct ib_sa_mad *mad;
int ret;
if (!sa_dev)
return -ENODEV;
port = &sa_dev->port[port_num - sa_dev->start_port];
agent = port->agent;
query = kzalloc(sizeof(*query), gfp_mask);
if (!query)
return -ENOMEM;
query->sa_query.port = port;
ret = alloc_mad(&query->sa_query, gfp_mask);
if (ret)
goto err1;
ib_sa_client_get(client);
query->sa_query.client = client;
query->callback = callback;
query->context = context;
mad = query->sa_query.mad_buf->mad;
init_mad(&query->sa_query, agent);
query->sa_query.callback = callback ? ib_sa_mcmember_rec_callback : NULL;
query->sa_query.release = ib_sa_mcmember_rec_release;
mad->mad_hdr.method = method;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_MC_MEMBER_REC);
mad->sa_hdr.comp_mask = comp_mask;
ib_pack(mcmember_rec_table, ARRAY_SIZE(mcmember_rec_table),
rec, mad->data);
*sa_query = &query->sa_query;
ret = send_mad(&query->sa_query, timeout_ms, gfp_mask);
if (ret < 0)
goto err2;
return ret;
err2:
*sa_query = NULL;
ib_sa_client_put(query->sa_query.client);
free_mad(&query->sa_query);
err1:
kfree(query);
return ret;
}
static void ib_sa_guidinfo_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
struct ib_sa_guidinfo_query *query =
container_of(sa_query, struct ib_sa_guidinfo_query, sa_query);
if (mad) {
struct ib_sa_guidinfo_rec rec;
ib_unpack(guidinfo_rec_table, ARRAY_SIZE(guidinfo_rec_table),
mad->data, &rec);
query->callback(status, &rec, query->context);
} else
query->callback(status, NULL, query->context);
}
static void ib_sa_guidinfo_rec_release(struct ib_sa_query *sa_query)
{
kfree(container_of(sa_query, struct ib_sa_guidinfo_query, sa_query));
}
int ib_sa_guid_info_rec_query(struct ib_sa_client *client,
struct ib_device *device, u8 port_num,
struct ib_sa_guidinfo_rec *rec,
ib_sa_comp_mask comp_mask, u8 method,
int timeout_ms, gfp_t gfp_mask,
void (*callback)(int status,
struct ib_sa_guidinfo_rec *resp,
void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_sa_guidinfo_query *query;
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
struct ib_mad_agent *agent;
struct ib_sa_mad *mad;
int ret;
if (!sa_dev)
return -ENODEV;
if (method != IB_MGMT_METHOD_GET &&
method != IB_MGMT_METHOD_SET &&
method != IB_SA_METHOD_DELETE) {
return -EINVAL;
}
port = &sa_dev->port[port_num - sa_dev->start_port];
agent = port->agent;
query = kzalloc(sizeof(*query), gfp_mask);
if (!query)
return -ENOMEM;
query->sa_query.port = port;
ret = alloc_mad(&query->sa_query, gfp_mask);
if (ret)
goto err1;
ib_sa_client_get(client);
query->sa_query.client = client;
query->callback = callback;
query->context = context;
mad = query->sa_query.mad_buf->mad;
init_mad(&query->sa_query, agent);
query->sa_query.callback = callback ? ib_sa_guidinfo_rec_callback : NULL;
query->sa_query.release = ib_sa_guidinfo_rec_release;
mad->mad_hdr.method = method;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_GUID_INFO_REC);
mad->sa_hdr.comp_mask = comp_mask;
ib_pack(guidinfo_rec_table, ARRAY_SIZE(guidinfo_rec_table), rec,
mad->data);
*sa_query = &query->sa_query;
ret = send_mad(&query->sa_query, timeout_ms, gfp_mask);
if (ret < 0)
goto err2;
return ret;
err2:
*sa_query = NULL;
ib_sa_client_put(query->sa_query.client);
free_mad(&query->sa_query);
err1:
kfree(query);
return ret;
}
bool ib_sa_sendonly_fullmem_support(struct ib_sa_client *client,
struct ib_device *device,
u8 port_num)
{
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
bool ret = false;
unsigned long flags;
if (!sa_dev)
return ret;
port = &sa_dev->port[port_num - sa_dev->start_port];
spin_lock_irqsave(&port->classport_lock, flags);
if ((port->classport_info.valid) &&
(port->classport_info.data.type == RDMA_CLASS_PORT_INFO_IB))
ret = ib_get_cpi_capmask2(&port->classport_info.data.ib)
& IB_SA_CAP_MASK2_SENDONLY_FULL_MEM_SUPPORT;
spin_unlock_irqrestore(&port->classport_lock, flags);
return ret;
}
static void ib_classportinfo_cb(void *context)
{
struct ib_classport_info_context *cb_ctx = context;
complete(&cb_ctx->done);
}
static void ib_sa_classport_info_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
unsigned long flags;
struct ib_sa_classport_info_query *query =
container_of(sa_query, struct ib_sa_classport_info_query, sa_query);
struct ib_sa_classport_cache *info = &sa_query->port->classport_info;
if (mad) {
if (sa_query->flags & IB_SA_QUERY_OPA) {
struct opa_class_port_info rec;
ib_unpack(opa_classport_info_rec_table,
ARRAY_SIZE(opa_classport_info_rec_table),
mad->data, &rec);
spin_lock_irqsave(&sa_query->port->classport_lock,
flags);
if (!status && !info->valid) {
memcpy(&info->data.opa, &rec,
sizeof(info->data.opa));
info->valid = true;
info->data.type = RDMA_CLASS_PORT_INFO_OPA;
}
spin_unlock_irqrestore(&sa_query->port->classport_lock,
flags);
} else {
struct ib_class_port_info rec;
ib_unpack(ib_classport_info_rec_table,
ARRAY_SIZE(ib_classport_info_rec_table),
mad->data, &rec);
spin_lock_irqsave(&sa_query->port->classport_lock,
flags);
if (!status && !info->valid) {
memcpy(&info->data.ib, &rec,
sizeof(info->data.ib));
info->valid = true;
info->data.type = RDMA_CLASS_PORT_INFO_IB;
}
spin_unlock_irqrestore(&sa_query->port->classport_lock,
flags);
}
}
query->callback(query->context);
}
static void ib_sa_classport_info_rec_release(struct ib_sa_query *sa_query)
{
kfree(container_of(sa_query, struct ib_sa_classport_info_query,
sa_query));
}
static int ib_sa_classport_info_rec_query(struct ib_sa_port *port,
int timeout_ms,
void (*callback)(void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_mad_agent *agent;
struct ib_sa_classport_info_query *query;
struct ib_sa_mad *mad;
gfp_t gfp_mask = GFP_KERNEL;
int ret;
agent = port->agent;
query = kzalloc(sizeof(*query), gfp_mask);
if (!query)
return -ENOMEM;
query->sa_query.port = port;
query->sa_query.flags |= rdma_cap_opa_ah(port->agent->device,
port->port_num) ?
IB_SA_QUERY_OPA : 0;
ret = alloc_mad(&query->sa_query, gfp_mask);
if (ret)
goto err_free;
query->callback = callback;
query->context = context;
mad = query->sa_query.mad_buf->mad;
init_mad(&query->sa_query, agent);
query->sa_query.callback = ib_sa_classport_info_rec_callback;
query->sa_query.release = ib_sa_classport_info_rec_release;
mad->mad_hdr.method = IB_MGMT_METHOD_GET;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_CLASS_PORTINFO);
mad->sa_hdr.comp_mask = 0;
*sa_query = &query->sa_query;
ret = send_mad(&query->sa_query, timeout_ms, gfp_mask);
if (ret < 0)
goto err_free_mad;
return ret;
err_free_mad:
*sa_query = NULL;
free_mad(&query->sa_query);
err_free:
kfree(query);
return ret;
}
static void update_ib_cpi(struct work_struct *work)
{
struct ib_sa_port *port =
container_of(work, struct ib_sa_port, ib_cpi_work.work);
struct ib_classport_info_context *cb_context;
unsigned long flags;
int ret;
spin_lock_irqsave(&port->classport_lock, flags);
if (port->classport_info.valid) {
spin_unlock_irqrestore(&port->classport_lock, flags);
return;
}
spin_unlock_irqrestore(&port->classport_lock, flags);
cb_context = kmalloc(sizeof(*cb_context), GFP_KERNEL);
if (!cb_context)
goto err_nomem;
init_completion(&cb_context->done);
ret = ib_sa_classport_info_rec_query(port, 3000,
ib_classportinfo_cb, cb_context,
&cb_context->sa_query);
if (ret < 0)
goto free_cb_err;
wait_for_completion(&cb_context->done);
free_cb_err:
kfree(cb_context);
spin_lock_irqsave(&port->classport_lock, flags);
if (!port->classport_info.valid) {
port->classport_info.retry_cnt++;
if (port->classport_info.retry_cnt <=
IB_SA_CPI_MAX_RETRY_CNT) {
unsigned long delay =
msecs_to_jiffies(IB_SA_CPI_RETRY_WAIT);
queue_delayed_work(ib_wq, &port->ib_cpi_work, delay);
}
}
spin_unlock_irqrestore(&port->classport_lock, flags);
err_nomem:
return;
}
static void send_handler(struct ib_mad_agent *agent,
struct ib_mad_send_wc *mad_send_wc)
{
struct ib_sa_query *query = mad_send_wc->send_buf->context[0];
unsigned long flags;
if (query->callback)
switch (mad_send_wc->status) {
case IB_WC_SUCCESS:
break;
case IB_WC_RESP_TIMEOUT_ERR:
query->callback(query, -ETIMEDOUT, NULL);
break;
case IB_WC_WR_FLUSH_ERR:
query->callback(query, -EINTR, NULL);
break;
default:
query->callback(query, -EIO, NULL);
break;
}
spin_lock_irqsave(&idr_lock, flags);
idr_remove(&query_idr, query->id);
spin_unlock_irqrestore(&idr_lock, flags);
free_mad(query);
if (query->client)
ib_sa_client_put(query->client);
query->release(query);
}
static void recv_handler(struct ib_mad_agent *mad_agent,
struct ib_mad_send_buf *send_buf,
struct ib_mad_recv_wc *mad_recv_wc)
{
struct ib_sa_query *query;
if (!send_buf)
return;
query = send_buf->context[0];
if (query->callback) {
if (mad_recv_wc->wc->status == IB_WC_SUCCESS)
query->callback(query,
mad_recv_wc->recv_buf.mad->mad_hdr.status ?
-EINVAL : 0,
(struct ib_sa_mad *) mad_recv_wc->recv_buf.mad);
else
query->callback(query, -EIO, NULL);
}
ib_free_recv_mad(mad_recv_wc);
}
static void update_sm_ah(struct work_struct *work)
{
struct ib_sa_port *port =
container_of(work, struct ib_sa_port, update_task);
struct ib_sa_sm_ah *new_ah;
struct ib_port_attr port_attr;
struct rdma_ah_attr ah_attr;
if (ib_query_port(port->agent->device, port->port_num, &port_attr)) {
pr_warn("Couldn't query port\n");
return;
}
new_ah = kmalloc(sizeof(*new_ah), GFP_KERNEL);
if (!new_ah)
return;
kref_init(&new_ah->ref);
new_ah->src_path_mask = (1 << port_attr.lmc) - 1;
new_ah->pkey_index = 0;
if (ib_find_pkey(port->agent->device, port->port_num,
IB_DEFAULT_PKEY_FULL, &new_ah->pkey_index))
pr_err("Couldn't find index for default PKey\n");
memset(&ah_attr, 0, sizeof(ah_attr));
ah_attr.type = rdma_ah_find_type(port->agent->device,
port->port_num);
rdma_ah_set_dlid(&ah_attr, port_attr.sm_lid);
rdma_ah_set_sl(&ah_attr, port_attr.sm_sl);
rdma_ah_set_port_num(&ah_attr, port->port_num);
if (port_attr.grh_required) {
rdma_ah_set_ah_flags(&ah_attr, IB_AH_GRH);
rdma_ah_set_subnet_prefix(&ah_attr,
cpu_to_be64(port_attr.subnet_prefix));
rdma_ah_set_interface_id(&ah_attr,
cpu_to_be64(IB_SA_WELL_KNOWN_GUID));
}
new_ah->ah = rdma_create_ah(port->agent->qp->pd, &ah_attr);
if (IS_ERR(new_ah->ah)) {
pr_warn("Couldn't create new SM AH\n");
kfree(new_ah);
return;
}
spin_lock_irq(&port->ah_lock);
if (port->sm_ah)
kref_put(&port->sm_ah->ref, free_sm_ah);
port->sm_ah = new_ah;
spin_unlock_irq(&port->ah_lock);
}
static void ib_sa_event(struct ib_event_handler *handler,
struct ib_event *event)
{
if (event->event == IB_EVENT_PORT_ERR ||
event->event == IB_EVENT_PORT_ACTIVE ||
event->event == IB_EVENT_LID_CHANGE ||
event->event == IB_EVENT_PKEY_CHANGE ||
event->event == IB_EVENT_SM_CHANGE ||
event->event == IB_EVENT_CLIENT_REREGISTER) {
unsigned long flags;
struct ib_sa_device *sa_dev =
container_of(handler, typeof(*sa_dev), event_handler);
u8 port_num = event->element.port_num - sa_dev->start_port;
struct ib_sa_port *port = &sa_dev->port[port_num];
if (!rdma_cap_ib_sa(handler->device, port->port_num))
return;
spin_lock_irqsave(&port->ah_lock, flags);
if (port->sm_ah)
kref_put(&port->sm_ah->ref, free_sm_ah);
port->sm_ah = NULL;
spin_unlock_irqrestore(&port->ah_lock, flags);
if (event->event == IB_EVENT_SM_CHANGE ||
event->event == IB_EVENT_CLIENT_REREGISTER ||
event->event == IB_EVENT_LID_CHANGE ||
event->event == IB_EVENT_PORT_ACTIVE) {
unsigned long delay =
msecs_to_jiffies(IB_SA_CPI_RETRY_WAIT);
spin_lock_irqsave(&port->classport_lock, flags);
port->classport_info.valid = false;
port->classport_info.retry_cnt = 0;
spin_unlock_irqrestore(&port->classport_lock, flags);
queue_delayed_work(ib_wq,
&port->ib_cpi_work, delay);
}
queue_work(ib_wq, &sa_dev->port[port_num].update_task);
}
}
static void ib_sa_add_one(struct ib_device *device)
{
struct ib_sa_device *sa_dev;
int s, e, i;
int count = 0;
s = rdma_start_port(device);
e = rdma_end_port(device);
sa_dev = kzalloc(sizeof *sa_dev +
(e - s + 1) * sizeof (struct ib_sa_port),
GFP_KERNEL);
if (!sa_dev)
return;
sa_dev->start_port = s;
sa_dev->end_port = e;
for (i = 0; i <= e - s; ++i) {
spin_lock_init(&sa_dev->port[i].ah_lock);
if (!rdma_cap_ib_sa(device, i + 1))
continue;
sa_dev->port[i].sm_ah = NULL;
sa_dev->port[i].port_num = i + s;
spin_lock_init(&sa_dev->port[i].classport_lock);
sa_dev->port[i].classport_info.valid = false;
sa_dev->port[i].agent =
ib_register_mad_agent(device, i + s, IB_QPT_GSI,
NULL, 0, send_handler,
recv_handler, sa_dev, 0);
if (IS_ERR(sa_dev->port[i].agent))
goto err;
INIT_WORK(&sa_dev->port[i].update_task, update_sm_ah);
INIT_DELAYED_WORK(&sa_dev->port[i].ib_cpi_work,
update_ib_cpi);
count++;
}
if (!count)
goto free;
ib_set_client_data(device, &sa_client, sa_dev);
INIT_IB_EVENT_HANDLER(&sa_dev->event_handler, device, ib_sa_event);
if (ib_register_event_handler(&sa_dev->event_handler))
goto err;
for (i = 0; i <= e - s; ++i) {
if (rdma_cap_ib_sa(device, i + 1))
update_sm_ah(&sa_dev->port[i].update_task);
}
return;
err:
while (--i >= 0) {
if (rdma_cap_ib_sa(device, i + 1))
ib_unregister_mad_agent(sa_dev->port[i].agent);
}
free:
kfree(sa_dev);
return;
}
static void ib_sa_remove_one(struct ib_device *device, void *client_data)
{
struct ib_sa_device *sa_dev = client_data;
int i;
if (!sa_dev)
return;
ib_unregister_event_handler(&sa_dev->event_handler);
flush_workqueue(ib_wq);
for (i = 0; i <= sa_dev->end_port - sa_dev->start_port; ++i) {
if (rdma_cap_ib_sa(device, i + 1)) {
cancel_delayed_work_sync(&sa_dev->port[i].ib_cpi_work);
ib_unregister_mad_agent(sa_dev->port[i].agent);
if (sa_dev->port[i].sm_ah)
kref_put(&sa_dev->port[i].sm_ah->ref, free_sm_ah);
}
}
kfree(sa_dev);
}
int ib_sa_init(void)
{
int ret;
get_random_bytes(&tid, sizeof tid);
atomic_set(&ib_nl_sa_request_seq, 0);
ret = ib_register_client(&sa_client);
if (ret) {
pr_err("Couldn't register ib_sa client\n");
goto err1;
}
ret = mcast_init();
if (ret) {
pr_err("Couldn't initialize multicast handling\n");
goto err2;
}
ib_nl_wq = alloc_ordered_workqueue("ib_nl_sa_wq", WQ_MEM_RECLAIM);
if (!ib_nl_wq) {
ret = -ENOMEM;
goto err3;
}
INIT_DELAYED_WORK(&ib_nl_timed_work, ib_nl_request_timeout);
return 0;
err3:
mcast_cleanup();
err2:
ib_unregister_client(&sa_client);
err1:
return ret;
}
void ib_sa_cleanup(void)
{
cancel_delayed_work(&ib_nl_timed_work);
flush_workqueue(ib_nl_wq);
destroy_workqueue(ib_nl_wq);
mcast_cleanup();
ib_unregister_client(&sa_client);
idr_destroy(&query_idr);
}
