static void free_sm_ah(struct kref *kref)
{
struct ib_sa_sm_ah *sm_ah = container_of(kref, struct ib_sa_sm_ah, ref);
ib_destroy_ah(sm_ah->ah);
kfree(sm_ah);
}
static void update_sm_ah(struct work_struct *work)
{
struct ib_sa_port *port =
container_of(work, struct ib_sa_port, update_task);
struct ib_sa_sm_ah *new_ah;
struct ib_port_attr port_attr;
struct ib_ah_attr ah_attr;
if (ib_query_port(port->agent->device, port->port_num, &port_attr)) {
printk(KERN_WARNING "Couldn't query port\n");
return;
}
new_ah = kmalloc(sizeof *new_ah, GFP_KERNEL);
if (!new_ah) {
printk(KERN_WARNING "Couldn't allocate new SM AH\n");
return;
}
kref_init(&new_ah->ref);
new_ah->src_path_mask = (1 << port_attr.lmc) - 1;
new_ah->pkey_index = 0;
if (ib_find_pkey(port->agent->device, port->port_num,
IB_DEFAULT_PKEY_FULL, &new_ah->pkey_index))
printk(KERN_ERR "Couldn't find index for default PKey\n");
memset(&ah_attr, 0, sizeof ah_attr);
ah_attr.dlid = port_attr.sm_lid;
ah_attr.sl = port_attr.sm_sl;
ah_attr.port_num = port->port_num;
new_ah->ah = ib_create_ah(port->agent->qp->pd, &ah_attr);
if (IS_ERR(new_ah->ah)) {
printk(KERN_WARNING "Couldn't create new SM AH\n");
kfree(new_ah);
return;
}
spin_lock_irq(&port->ah_lock);
if (port->sm_ah)
kref_put(&port->sm_ah->ref, free_sm_ah);
port->sm_ah = new_ah;
spin_unlock_irq(&port->ah_lock);
}
static void ib_sa_event(struct ib_event_handler *handler, struct ib_event *event)
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
struct ib_sa_port *port =
&sa_dev->port[event->element.port_num - sa_dev->start_port];
if (!rdma_cap_ib_sa(handler->device, port->port_num))
return;
spin_lock_irqsave(&port->ah_lock, flags);
if (port->sm_ah)
kref_put(&port->sm_ah->ref, free_sm_ah);
port->sm_ah = NULL;
spin_unlock_irqrestore(&port->ah_lock, flags);
queue_work(ib_wq, &sa_dev->port[event->element.port_num -
sa_dev->start_port].update_task);
}
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
struct ib_sa_path_rec *rec, struct ib_ah_attr *ah_attr)
{
int ret;
u16 gid_index;
int force_grh;
memset(ah_attr, 0, sizeof *ah_attr);
ah_attr->dlid = be16_to_cpu(rec->dlid);
ah_attr->sl = rec->sl;
ah_attr->src_path_bits = be16_to_cpu(rec->slid) &
get_src_path_mask(device, port_num);
ah_attr->port_num = port_num;
ah_attr->static_rate = rec->rate;
force_grh = rdma_cap_eth_ah(device, port_num);
if (rec->hop_limit > 1 || force_grh) {
ah_attr->ah_flags = IB_AH_GRH;
ah_attr->grh.dgid = rec->dgid;
ret = ib_find_cached_gid(device, &rec->sgid, &port_num,
&gid_index);
if (ret)
return ret;
ah_attr->grh.sgid_index = gid_index;
ah_attr->grh.flow_label = be32_to_cpu(rec->flow_label);
ah_attr->grh.hop_limit = rec->hop_limit;
ah_attr->grh.traffic_class = rec->traffic_class;
}
if (force_grh) {
memcpy(ah_attr->dmac, rec->dmac, ETH_ALEN);
ah_attr->vlan_id = rec->vlan_id;
} else {
ah_attr->vlan_id = 0xffff;
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
IB_MGMT_BASE_VERSION);
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
static void init_mad(struct ib_sa_mad *mad, struct ib_mad_agent *agent)
{
unsigned long flags;
memset(mad, 0, sizeof *mad);
mad->mad_hdr.base_version = IB_MGMT_BASE_VERSION;
mad->mad_hdr.mgmt_class = IB_MGMT_CLASS_SUBN_ADM;
mad->mad_hdr.class_version = IB_SA_CLASS_VERSION;
spin_lock_irqsave(&tid_lock, flags);
mad->mad_hdr.tid =
cpu_to_be64(((u64) agent->hi_tid) << 32 | tid++);
spin_unlock_irqrestore(&tid_lock, flags);
}
static int send_mad(struct ib_sa_query *query, int timeout_ms, gfp_t gfp_mask)
{
bool preload = !!(gfp_mask & __GFP_WAIT);
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
ret = ib_post_send_mad(query->mad_buf, NULL);
if (ret) {
spin_lock_irqsave(&idr_lock, flags);
idr_remove(&query_idr, id);
spin_unlock_irqrestore(&idr_lock, flags);
}
return ret ? ret : id;
}
void ib_sa_unpack_path(void *attribute, struct ib_sa_path_rec *rec)
{
ib_unpack(path_rec_table, ARRAY_SIZE(path_rec_table), attribute, rec);
}
void ib_sa_pack_path(struct ib_sa_path_rec *rec, void *attribute)
{
ib_pack(path_rec_table, ARRAY_SIZE(path_rec_table), rec, attribute);
}
static void ib_sa_path_rec_callback(struct ib_sa_query *sa_query,
int status,
struct ib_sa_mad *mad)
{
struct ib_sa_path_query *query =
container_of(sa_query, struct ib_sa_path_query, sa_query);
if (mad) {
struct ib_sa_path_rec rec;
ib_unpack(path_rec_table, ARRAY_SIZE(path_rec_table),
mad->data, &rec);
rec.vlan_id = 0xffff;
memset(rec.dmac, 0, ETH_ALEN);
memset(rec.smac, 0, ETH_ALEN);
query->callback(status, &rec, query->context);
} else
query->callback(status, NULL, query->context);
}
static void ib_sa_path_rec_release(struct ib_sa_query *sa_query)
{
kfree(container_of(sa_query, struct ib_sa_path_query, sa_query));
}
int ib_sa_path_rec_get(struct ib_sa_client *client,
struct ib_device *device, u8 port_num,
struct ib_sa_path_rec *rec,
ib_sa_comp_mask comp_mask,
int timeout_ms, gfp_t gfp_mask,
void (*callback)(int status,
struct ib_sa_path_rec *resp,
void *context),
void *context,
struct ib_sa_query **sa_query)
{
struct ib_sa_path_query *query;
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
struct ib_sa_port *port;
struct ib_mad_agent *agent;
struct ib_sa_mad *mad;
int ret;
if (!sa_dev)
return -ENODEV;
port = &sa_dev->port[port_num - sa_dev->start_port];
agent = port->agent;
query = kmalloc(sizeof *query, gfp_mask);
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
init_mad(mad, agent);
query->sa_query.callback = callback ? ib_sa_path_rec_callback : NULL;
query->sa_query.release = ib_sa_path_rec_release;
mad->mad_hdr.method = IB_MGMT_METHOD_GET;
mad->mad_hdr.attr_id = cpu_to_be16(IB_SA_ATTR_PATH_REC);
mad->sa_hdr.comp_mask = comp_mask;
ib_pack(path_rec_table, ARRAY_SIZE(path_rec_table), rec, mad->data);
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
query = kmalloc(sizeof *query, gfp_mask);
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
init_mad(mad, agent);
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
query = kmalloc(sizeof *query, gfp_mask);
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
init_mad(mad, agent);
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
query = kmalloc(sizeof *query, gfp_mask);
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
init_mad(mad, agent);
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
ib_sa_client_put(query->client);
query->release(query);
}
static void recv_handler(struct ib_mad_agent *mad_agent,
struct ib_mad_recv_wc *mad_recv_wc)
{
struct ib_sa_query *query;
struct ib_mad_send_buf *mad_buf;
mad_buf = (void *) (unsigned long) mad_recv_wc->wc->wr_id;
query = mad_buf->context[0];
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
sa_dev->port[i].agent =
ib_register_mad_agent(device, i + s, IB_QPT_GSI,
NULL, 0, send_handler,
recv_handler, sa_dev, 0);
if (IS_ERR(sa_dev->port[i].agent))
goto err;
INIT_WORK(&sa_dev->port[i].update_task, update_sm_ah);
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
static void ib_sa_remove_one(struct ib_device *device)
{
struct ib_sa_device *sa_dev = ib_get_client_data(device, &sa_client);
int i;
if (!sa_dev)
return;
ib_unregister_event_handler(&sa_dev->event_handler);
flush_workqueue(ib_wq);
for (i = 0; i <= sa_dev->end_port - sa_dev->start_port; ++i) {
if (rdma_cap_ib_sa(device, i + 1)) {
ib_unregister_mad_agent(sa_dev->port[i].agent);
if (sa_dev->port[i].sm_ah)
kref_put(&sa_dev->port[i].sm_ah->ref, free_sm_ah);
}
}
kfree(sa_dev);
}
static int __init ib_sa_init(void)
{
int ret;
get_random_bytes(&tid, sizeof tid);
ret = ib_register_client(&sa_client);
if (ret) {
printk(KERN_ERR "Couldn't register ib_sa client\n");
goto err1;
}
ret = mcast_init();
if (ret) {
printk(KERN_ERR "Couldn't initialize multicast handling\n");
goto err2;
}
return 0;
err2:
ib_unregister_client(&sa_client);
err1:
return ret;
}
static void __exit ib_sa_cleanup(void)
{
mcast_cleanup();
ib_unregister_client(&sa_client);
idr_destroy(&query_idr);
}
