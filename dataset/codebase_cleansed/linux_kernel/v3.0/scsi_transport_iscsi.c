static void iscsi_transport_release(struct device *dev)
{
struct iscsi_internal *priv = dev_to_iscsi_internal(dev);
kfree(priv);
}
static ssize_t
show_transport_handle(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_internal *priv = dev_to_iscsi_internal(dev);
return sprintf(buf, "%llu\n", (unsigned long long)iscsi_handle(priv->iscsi_transport));
}
static void iscsi_endpoint_release(struct device *dev)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
kfree(ep);
}
static ssize_t
show_ep_handle(struct device *dev, struct device_attribute *attr, char *buf)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
return sprintf(buf, "%llu\n", (unsigned long long) ep->id);
}
static int iscsi_match_epid(struct device *dev, void *data)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
uint64_t *epid = (uint64_t *) data;
return *epid == ep->id;
}
struct iscsi_endpoint *
iscsi_create_endpoint(int dd_size)
{
struct device *dev;
struct iscsi_endpoint *ep;
uint64_t id;
int err;
for (id = 1; id < ISCSI_MAX_EPID; id++) {
dev = class_find_device(&iscsi_endpoint_class, NULL, &id,
iscsi_match_epid);
if (!dev)
break;
}
if (id == ISCSI_MAX_EPID) {
printk(KERN_ERR "Too many connections. Max supported %u\n",
ISCSI_MAX_EPID - 1);
return NULL;
}
ep = kzalloc(sizeof(*ep) + dd_size, GFP_KERNEL);
if (!ep)
return NULL;
ep->id = id;
ep->dev.class = &iscsi_endpoint_class;
dev_set_name(&ep->dev, "ep-%llu", (unsigned long long) id);
err = device_register(&ep->dev);
if (err)
goto free_ep;
err = sysfs_create_group(&ep->dev.kobj, &iscsi_endpoint_group);
if (err)
goto unregister_dev;
if (dd_size)
ep->dd_data = &ep[1];
return ep;
unregister_dev:
device_unregister(&ep->dev);
return NULL;
free_ep:
kfree(ep);
return NULL;
}
void iscsi_destroy_endpoint(struct iscsi_endpoint *ep)
{
sysfs_remove_group(&ep->dev.kobj, &iscsi_endpoint_group);
device_unregister(&ep->dev);
}
struct iscsi_endpoint *iscsi_lookup_endpoint(u64 handle)
{
struct iscsi_endpoint *ep;
struct device *dev;
dev = class_find_device(&iscsi_endpoint_class, NULL, &handle,
iscsi_match_epid);
if (!dev)
return NULL;
ep = iscsi_dev_to_endpoint(dev);
put_device(dev);
return ep;
}
static int iscsi_setup_host(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct iscsi_cls_host *ihost = shost->shost_data;
memset(ihost, 0, sizeof(*ihost));
atomic_set(&ihost->nr_scans, 0);
mutex_init(&ihost->mutex);
return 0;
}
static uint32_t iscsi_conn_get_sid(struct iscsi_cls_conn *conn)
{
struct iscsi_cls_session *sess = iscsi_dev_to_session(conn->dev.parent);
return sess->sid;
}
static struct iscsi_cls_session *iscsi_session_lookup(uint32_t sid)
{
unsigned long flags;
struct iscsi_cls_session *sess;
spin_lock_irqsave(&sesslock, flags);
list_for_each_entry(sess, &sesslist, sess_list) {
if (sess->sid == sid) {
spin_unlock_irqrestore(&sesslock, flags);
return sess;
}
}
spin_unlock_irqrestore(&sesslock, flags);
return NULL;
}
static struct iscsi_cls_conn *iscsi_conn_lookup(uint32_t sid, uint32_t cid)
{
unsigned long flags;
struct iscsi_cls_conn *conn;
spin_lock_irqsave(&connlock, flags);
list_for_each_entry(conn, &connlist, conn_list) {
if ((conn->cid == cid) && (iscsi_conn_get_sid(conn) == sid)) {
spin_unlock_irqrestore(&connlock, flags);
return conn;
}
}
spin_unlock_irqrestore(&connlock, flags);
return NULL;
}
static const char *iscsi_session_state_name(int state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(iscsi_session_state_names); i++) {
if (iscsi_session_state_names[i].value == state) {
name = iscsi_session_state_names[i].name;
break;
}
}
return name;
}
int iscsi_session_chkready(struct iscsi_cls_session *session)
{
unsigned long flags;
int err;
spin_lock_irqsave(&session->lock, flags);
switch (session->state) {
case ISCSI_SESSION_LOGGED_IN:
err = 0;
break;
case ISCSI_SESSION_FAILED:
err = DID_IMM_RETRY << 16;
break;
case ISCSI_SESSION_FREE:
err = DID_TRANSPORT_FAILFAST << 16;
break;
default:
err = DID_NO_CONNECT << 16;
break;
}
spin_unlock_irqrestore(&session->lock, flags);
return err;
}
static void iscsi_session_release(struct device *dev)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev);
struct Scsi_Host *shost;
shost = iscsi_session_to_shost(session);
scsi_host_put(shost);
ISCSI_DBG_TRANS_SESSION(session, "Completing session release\n");
kfree(session);
}
static int iscsi_is_session_dev(const struct device *dev)
{
return dev->release == iscsi_session_release;
}
static int iscsi_iter_session_fn(struct device *dev, void *data)
{
void (* fn) (struct iscsi_cls_session *) = data;
if (!iscsi_is_session_dev(dev))
return 0;
fn(iscsi_dev_to_session(dev));
return 0;
}
void iscsi_host_for_each_session(struct Scsi_Host *shost,
void (*fn)(struct iscsi_cls_session *))
{
device_for_each_child(&shost->shost_gendev, fn,
iscsi_iter_session_fn);
}
int iscsi_scan_finished(struct Scsi_Host *shost, unsigned long time)
{
struct iscsi_cls_host *ihost = shost->shost_data;
return !atomic_read(&ihost->nr_scans);
}
static int iscsi_user_scan_session(struct device *dev, void *data)
{
struct iscsi_scan_data *scan_data = data;
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
struct iscsi_cls_host *ihost;
unsigned long flags;
unsigned int id;
if (!iscsi_is_session_dev(dev))
return 0;
session = iscsi_dev_to_session(dev);
ISCSI_DBG_TRANS_SESSION(session, "Scanning session\n");
shost = iscsi_session_to_shost(session);
ihost = shost->shost_data;
mutex_lock(&ihost->mutex);
spin_lock_irqsave(&session->lock, flags);
if (session->state != ISCSI_SESSION_LOGGED_IN) {
spin_unlock_irqrestore(&session->lock, flags);
goto user_scan_exit;
}
id = session->target_id;
spin_unlock_irqrestore(&session->lock, flags);
if (id != ISCSI_MAX_TARGET) {
if ((scan_data->channel == SCAN_WILD_CARD ||
scan_data->channel == 0) &&
(scan_data->id == SCAN_WILD_CARD ||
scan_data->id == id))
scsi_scan_target(&session->dev, 0, id,
scan_data->lun, 1);
}
user_scan_exit:
mutex_unlock(&ihost->mutex);
ISCSI_DBG_TRANS_SESSION(session, "Completed session scan\n");
return 0;
}
static int iscsi_user_scan(struct Scsi_Host *shost, uint channel,
uint id, uint lun)
{
struct iscsi_scan_data scan_data;
scan_data.channel = channel;
scan_data.id = id;
scan_data.lun = lun;
return device_for_each_child(&shost->shost_gendev, &scan_data,
iscsi_user_scan_session);
}
static void iscsi_scan_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session, scan_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
struct iscsi_scan_data scan_data;
scan_data.channel = 0;
scan_data.id = SCAN_WILD_CARD;
scan_data.lun = SCAN_WILD_CARD;
iscsi_user_scan_session(&session->dev, &scan_data);
atomic_dec(&ihost->nr_scans);
}
int iscsi_block_scsi_eh(struct scsi_cmnd *cmd)
{
struct iscsi_cls_session *session =
starget_to_session(scsi_target(cmd->device));
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&session->lock, flags);
while (session->state != ISCSI_SESSION_LOGGED_IN) {
if (session->state == ISCSI_SESSION_FREE) {
ret = FAST_IO_FAIL;
break;
}
spin_unlock_irqrestore(&session->lock, flags);
msleep(1000);
spin_lock_irqsave(&session->lock, flags);
}
spin_unlock_irqrestore(&session->lock, flags);
return ret;
}
static void session_recovery_timedout(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
recovery_work.work);
unsigned long flags;
iscsi_cls_session_printk(KERN_INFO, session,
"session recovery timed out after %d secs\n",
session->recovery_tmo);
spin_lock_irqsave(&session->lock, flags);
switch (session->state) {
case ISCSI_SESSION_FAILED:
session->state = ISCSI_SESSION_FREE;
break;
case ISCSI_SESSION_LOGGED_IN:
case ISCSI_SESSION_FREE:
spin_unlock_irqrestore(&session->lock, flags);
return;
}
spin_unlock_irqrestore(&session->lock, flags);
if (session->transport->session_recovery_timedout)
session->transport->session_recovery_timedout(session);
ISCSI_DBG_TRANS_SESSION(session, "Unblocking SCSI target\n");
scsi_target_unblock(&session->dev);
ISCSI_DBG_TRANS_SESSION(session, "Completed unblocking SCSI target\n");
}
static void __iscsi_unblock_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
unblock_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
unsigned long flags;
ISCSI_DBG_TRANS_SESSION(session, "Unblocking session\n");
cancel_delayed_work(&session->recovery_work);
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_LOGGED_IN;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_unblock(&session->dev);
if (shost->hostt->scan_finished) {
if (scsi_queue_work(shost, &session->scan_work))
atomic_inc(&ihost->nr_scans);
}
ISCSI_DBG_TRANS_SESSION(session, "Completed unblocking session\n");
}
void iscsi_unblock_session(struct iscsi_cls_session *session)
{
queue_work(iscsi_eh_timer_workq, &session->unblock_work);
flush_workqueue(iscsi_eh_timer_workq);
}
static void __iscsi_block_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
block_work);
unsigned long flags;
ISCSI_DBG_TRANS_SESSION(session, "Blocking session\n");
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_FAILED;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_block(&session->dev);
ISCSI_DBG_TRANS_SESSION(session, "Completed SCSI target blocking\n");
if (session->recovery_tmo >= 0)
queue_delayed_work(iscsi_eh_timer_workq,
&session->recovery_work,
session->recovery_tmo * HZ);
}
void iscsi_block_session(struct iscsi_cls_session *session)
{
queue_work(iscsi_eh_timer_workq, &session->block_work);
}
static void __iscsi_unbind_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
unbind_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
unsigned long flags;
ISCSI_DBG_TRANS_SESSION(session, "Unbinding session\n");
mutex_lock(&ihost->mutex);
spin_lock_irqsave(&session->lock, flags);
if (session->target_id == ISCSI_MAX_TARGET) {
spin_unlock_irqrestore(&session->lock, flags);
mutex_unlock(&ihost->mutex);
return;
}
session->target_id = ISCSI_MAX_TARGET;
spin_unlock_irqrestore(&session->lock, flags);
mutex_unlock(&ihost->mutex);
scsi_remove_target(&session->dev);
iscsi_session_event(session, ISCSI_KEVENT_UNBIND_SESSION);
ISCSI_DBG_TRANS_SESSION(session, "Completed target removal\n");
}
struct iscsi_cls_session *
iscsi_alloc_session(struct Scsi_Host *shost, struct iscsi_transport *transport,
int dd_size)
{
struct iscsi_cls_session *session;
session = kzalloc(sizeof(*session) + dd_size,
GFP_KERNEL);
if (!session)
return NULL;
session->transport = transport;
session->recovery_tmo = 120;
session->state = ISCSI_SESSION_FREE;
INIT_DELAYED_WORK(&session->recovery_work, session_recovery_timedout);
INIT_LIST_HEAD(&session->sess_list);
INIT_WORK(&session->unblock_work, __iscsi_unblock_session);
INIT_WORK(&session->block_work, __iscsi_block_session);
INIT_WORK(&session->unbind_work, __iscsi_unbind_session);
INIT_WORK(&session->scan_work, iscsi_scan_session);
spin_lock_init(&session->lock);
scsi_host_get(shost);
session->dev.parent = &shost->shost_gendev;
session->dev.release = iscsi_session_release;
device_initialize(&session->dev);
if (dd_size)
session->dd_data = &session[1];
ISCSI_DBG_TRANS_SESSION(session, "Completed session allocation\n");
return session;
}
static int iscsi_get_next_target_id(struct device *dev, void *data)
{
struct iscsi_cls_session *session;
unsigned long flags;
int err = 0;
if (!iscsi_is_session_dev(dev))
return 0;
session = iscsi_dev_to_session(dev);
spin_lock_irqsave(&session->lock, flags);
if (*((unsigned int *) data) == session->target_id)
err = -EEXIST;
spin_unlock_irqrestore(&session->lock, flags);
return err;
}
int iscsi_add_session(struct iscsi_cls_session *session, unsigned int target_id)
{
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost;
unsigned long flags;
unsigned int id = target_id;
int err;
ihost = shost->shost_data;
session->sid = atomic_add_return(1, &iscsi_session_nr);
if (id == ISCSI_MAX_TARGET) {
for (id = 0; id < ISCSI_MAX_TARGET; id++) {
err = device_for_each_child(&shost->shost_gendev, &id,
iscsi_get_next_target_id);
if (!err)
break;
}
if (id == ISCSI_MAX_TARGET) {
iscsi_cls_session_printk(KERN_ERR, session,
"Too many iscsi targets. Max "
"number of targets is %d.\n",
ISCSI_MAX_TARGET - 1);
err = -EOVERFLOW;
goto release_host;
}
}
session->target_id = id;
dev_set_name(&session->dev, "session%u", session->sid);
err = device_add(&session->dev);
if (err) {
iscsi_cls_session_printk(KERN_ERR, session,
"could not register session's dev\n");
goto release_host;
}
transport_register_device(&session->dev);
spin_lock_irqsave(&sesslock, flags);
list_add(&session->sess_list, &sesslist);
spin_unlock_irqrestore(&sesslock, flags);
iscsi_session_event(session, ISCSI_KEVENT_CREATE_SESSION);
ISCSI_DBG_TRANS_SESSION(session, "Completed session adding\n");
return 0;
release_host:
scsi_host_put(shost);
return err;
}
struct iscsi_cls_session *
iscsi_create_session(struct Scsi_Host *shost, struct iscsi_transport *transport,
int dd_size, unsigned int target_id)
{
struct iscsi_cls_session *session;
session = iscsi_alloc_session(shost, transport, dd_size);
if (!session)
return NULL;
if (iscsi_add_session(session, target_id)) {
iscsi_free_session(session);
return NULL;
}
return session;
}
static void iscsi_conn_release(struct device *dev)
{
struct iscsi_cls_conn *conn = iscsi_dev_to_conn(dev);
struct device *parent = conn->dev.parent;
ISCSI_DBG_TRANS_CONN(conn, "Releasing conn\n");
kfree(conn);
put_device(parent);
}
static int iscsi_is_conn_dev(const struct device *dev)
{
return dev->release == iscsi_conn_release;
}
static int iscsi_iter_destroy_conn_fn(struct device *dev, void *data)
{
if (!iscsi_is_conn_dev(dev))
return 0;
return iscsi_destroy_conn(iscsi_dev_to_conn(dev));
}
void iscsi_remove_session(struct iscsi_cls_session *session)
{
struct Scsi_Host *shost = iscsi_session_to_shost(session);
unsigned long flags;
int err;
ISCSI_DBG_TRANS_SESSION(session, "Removing session\n");
spin_lock_irqsave(&sesslock, flags);
list_del(&session->sess_list);
spin_unlock_irqrestore(&sesslock, flags);
flush_workqueue(iscsi_eh_timer_workq);
if (!cancel_delayed_work(&session->recovery_work))
flush_workqueue(iscsi_eh_timer_workq);
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_FREE;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_unblock(&session->dev);
scsi_flush_work(shost);
__iscsi_unbind_session(&session->unbind_work);
err = device_for_each_child(&session->dev, NULL,
iscsi_iter_destroy_conn_fn);
if (err)
iscsi_cls_session_printk(KERN_ERR, session,
"Could not delete all connections "
"for session. Error %d.\n", err);
transport_unregister_device(&session->dev);
ISCSI_DBG_TRANS_SESSION(session, "Completing session removal\n");
device_del(&session->dev);
}
void iscsi_free_session(struct iscsi_cls_session *session)
{
ISCSI_DBG_TRANS_SESSION(session, "Freeing session\n");
iscsi_session_event(session, ISCSI_KEVENT_DESTROY_SESSION);
put_device(&session->dev);
}
int iscsi_destroy_session(struct iscsi_cls_session *session)
{
iscsi_remove_session(session);
ISCSI_DBG_TRANS_SESSION(session, "Completing session destruction\n");
iscsi_free_session(session);
return 0;
}
struct iscsi_cls_conn *
iscsi_create_conn(struct iscsi_cls_session *session, int dd_size, uint32_t cid)
{
struct iscsi_transport *transport = session->transport;
struct iscsi_cls_conn *conn;
unsigned long flags;
int err;
conn = kzalloc(sizeof(*conn) + dd_size, GFP_KERNEL);
if (!conn)
return NULL;
if (dd_size)
conn->dd_data = &conn[1];
mutex_init(&conn->ep_mutex);
INIT_LIST_HEAD(&conn->conn_list);
conn->transport = transport;
conn->cid = cid;
if (!get_device(&session->dev))
goto free_conn;
dev_set_name(&conn->dev, "connection%d:%u", session->sid, cid);
conn->dev.parent = &session->dev;
conn->dev.release = iscsi_conn_release;
err = device_register(&conn->dev);
if (err) {
iscsi_cls_session_printk(KERN_ERR, session, "could not "
"register connection's dev\n");
goto release_parent_ref;
}
transport_register_device(&conn->dev);
spin_lock_irqsave(&connlock, flags);
list_add(&conn->conn_list, &connlist);
spin_unlock_irqrestore(&connlock, flags);
ISCSI_DBG_TRANS_CONN(conn, "Completed conn creation\n");
return conn;
release_parent_ref:
put_device(&session->dev);
free_conn:
kfree(conn);
return NULL;
}
int iscsi_destroy_conn(struct iscsi_cls_conn *conn)
{
unsigned long flags;
spin_lock_irqsave(&connlock, flags);
list_del(&conn->conn_list);
spin_unlock_irqrestore(&connlock, flags);
transport_unregister_device(&conn->dev);
ISCSI_DBG_TRANS_CONN(conn, "Completing conn destruction\n");
device_unregister(&conn->dev);
return 0;
}
static struct iscsi_internal *
iscsi_if_transport_lookup(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_for_each_entry(priv, &iscsi_transports, list) {
if (tt == priv->iscsi_transport) {
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
return priv;
}
}
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
return NULL;
}
static int
iscsi_multicast_skb(struct sk_buff *skb, uint32_t group, gfp_t gfp)
{
return nlmsg_multicast(nls, skb, 0, group, gfp);
}
int iscsi_recv_pdu(struct iscsi_cls_conn *conn, struct iscsi_hdr *hdr,
char *data, uint32_t data_size)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
char *pdu;
struct iscsi_internal *priv;
int len = NLMSG_SPACE(sizeof(*ev) + sizeof(struct iscsi_hdr) +
data_size);
priv = iscsi_if_transport_lookup(conn->transport);
if (!priv)
return -EINVAL;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
iscsi_conn_error_event(conn, ISCSI_ERR_CONN_FAILED);
iscsi_cls_conn_printk(KERN_ERR, conn, "can not deliver "
"control PDU: OOM\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = NLMSG_DATA(nlh);
memset(ev, 0, sizeof(*ev));
ev->transport_handle = iscsi_handle(conn->transport);
ev->type = ISCSI_KEVENT_RECV_PDU;
ev->r.recv_req.cid = conn->cid;
ev->r.recv_req.sid = iscsi_conn_get_sid(conn);
pdu = (char*)ev + sizeof(*ev);
memcpy(pdu, hdr, sizeof(struct iscsi_hdr));
memcpy(pdu + sizeof(struct iscsi_hdr), data, data_size);
return iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_ATOMIC);
}
int iscsi_offload_mesg(struct Scsi_Host *shost,
struct iscsi_transport *transport, uint32_t type,
char *data, uint16_t data_size)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
int len = NLMSG_SPACE(sizeof(*ev) + data_size);
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "can not deliver iscsi offload message:OOM\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = NLMSG_DATA(nlh);
memset(ev, 0, sizeof(*ev));
ev->type = type;
ev->transport_handle = iscsi_handle(transport);
switch (type) {
case ISCSI_KEVENT_PATH_REQ:
ev->r.req_path.host_no = shost->host_no;
break;
case ISCSI_KEVENT_IF_DOWN:
ev->r.notify_if_down.host_no = shost->host_no;
break;
}
memcpy((char *)ev + sizeof(*ev), data, data_size);
return iscsi_multicast_skb(skb, ISCSI_NL_GRP_UIP, GFP_ATOMIC);
}
void iscsi_conn_error_event(struct iscsi_cls_conn *conn, enum iscsi_err error)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
struct iscsi_internal *priv;
int len = NLMSG_SPACE(sizeof(*ev));
priv = iscsi_if_transport_lookup(conn->transport);
if (!priv)
return;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
iscsi_cls_conn_printk(KERN_ERR, conn, "gracefully ignored "
"conn error (%d)\n", error);
return;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = NLMSG_DATA(nlh);
ev->transport_handle = iscsi_handle(conn->transport);
ev->type = ISCSI_KEVENT_CONN_ERROR;
ev->r.connerror.error = error;
ev->r.connerror.cid = conn->cid;
ev->r.connerror.sid = iscsi_conn_get_sid(conn);
iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_ATOMIC);
iscsi_cls_conn_printk(KERN_INFO, conn, "detected conn error (%d)\n",
error);
}
static int
iscsi_if_send_reply(uint32_t group, int seq, int type, int done, int multi,
void *payload, int size)
{
struct sk_buff *skb;
struct nlmsghdr *nlh;
int len = NLMSG_SPACE(size);
int flags = multi ? NLM_F_MULTI : 0;
int t = done ? NLMSG_DONE : type;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "Could not allocate skb to send reply.\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, t, (len - sizeof(*nlh)), 0);
nlh->nlmsg_flags = flags;
memcpy(NLMSG_DATA(nlh), payload, size);
return iscsi_multicast_skb(skb, group, GFP_ATOMIC);
}
static int
iscsi_if_get_stats(struct iscsi_transport *transport, struct nlmsghdr *nlh)
{
struct iscsi_uevent *ev = NLMSG_DATA(nlh);
struct iscsi_stats *stats;
struct sk_buff *skbstat;
struct iscsi_cls_conn *conn;
struct nlmsghdr *nlhstat;
struct iscsi_uevent *evstat;
struct iscsi_internal *priv;
int len = NLMSG_SPACE(sizeof(*ev) +
sizeof(struct iscsi_stats) +
sizeof(struct iscsi_stats_custom) *
ISCSI_STATS_CUSTOM_MAX);
int err = 0;
priv = iscsi_if_transport_lookup(transport);
if (!priv)
return -EINVAL;
conn = iscsi_conn_lookup(ev->u.get_stats.sid, ev->u.get_stats.cid);
if (!conn)
return -EEXIST;
do {
int actual_size;
skbstat = alloc_skb(len, GFP_ATOMIC);
if (!skbstat) {
iscsi_cls_conn_printk(KERN_ERR, conn, "can not "
"deliver stats: OOM\n");
return -ENOMEM;
}
nlhstat = __nlmsg_put(skbstat, 0, 0, 0,
(len - sizeof(*nlhstat)), 0);
evstat = NLMSG_DATA(nlhstat);
memset(evstat, 0, sizeof(*evstat));
evstat->transport_handle = iscsi_handle(conn->transport);
evstat->type = nlh->nlmsg_type;
evstat->u.get_stats.cid =
ev->u.get_stats.cid;
evstat->u.get_stats.sid =
ev->u.get_stats.sid;
stats = (struct iscsi_stats *)
((char*)evstat + sizeof(*evstat));
memset(stats, 0, sizeof(*stats));
transport->get_stats(conn, stats);
actual_size = NLMSG_SPACE(sizeof(struct iscsi_uevent) +
sizeof(struct iscsi_stats) +
sizeof(struct iscsi_stats_custom) *
stats->custom_length);
actual_size -= sizeof(*nlhstat);
actual_size = NLMSG_LENGTH(actual_size);
skb_trim(skbstat, NLMSG_ALIGN(actual_size));
nlhstat->nlmsg_len = actual_size;
err = iscsi_multicast_skb(skbstat, ISCSI_NL_GRP_ISCSID,
GFP_ATOMIC);
} while (err < 0 && err != -ECONNREFUSED);
return err;
}
int iscsi_session_event(struct iscsi_cls_session *session,
enum iscsi_uevent_e event)
{
struct iscsi_internal *priv;
struct Scsi_Host *shost;
struct iscsi_uevent *ev;
struct sk_buff *skb;
struct nlmsghdr *nlh;
int rc, len = NLMSG_SPACE(sizeof(*ev));
priv = iscsi_if_transport_lookup(session->transport);
if (!priv)
return -EINVAL;
shost = iscsi_session_to_shost(session);
skb = alloc_skb(len, GFP_KERNEL);
if (!skb) {
iscsi_cls_session_printk(KERN_ERR, session,
"Cannot notify userspace of session "
"event %u\n", event);
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = NLMSG_DATA(nlh);
ev->transport_handle = iscsi_handle(session->transport);
ev->type = event;
switch (event) {
case ISCSI_KEVENT_DESTROY_SESSION:
ev->r.d_session.host_no = shost->host_no;
ev->r.d_session.sid = session->sid;
break;
case ISCSI_KEVENT_CREATE_SESSION:
ev->r.c_session_ret.host_no = shost->host_no;
ev->r.c_session_ret.sid = session->sid;
break;
case ISCSI_KEVENT_UNBIND_SESSION:
ev->r.unbind_session.host_no = shost->host_no;
ev->r.unbind_session.sid = session->sid;
break;
default:
iscsi_cls_session_printk(KERN_ERR, session, "Invalid event "
"%u.\n", event);
kfree_skb(skb);
return -EINVAL;
}
rc = iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_KERNEL);
if (rc == -ESRCH)
iscsi_cls_session_printk(KERN_ERR, session,
"Cannot notify userspace of session "
"event %u. Check iscsi daemon\n",
event);
ISCSI_DBG_TRANS_SESSION(session, "Completed handling event %d rc %d\n",
event, rc);
return rc;
}
static int
iscsi_if_create_session(struct iscsi_internal *priv, struct iscsi_endpoint *ep,
struct iscsi_uevent *ev, uint32_t initial_cmdsn,
uint16_t cmds_max, uint16_t queue_depth)
{
struct iscsi_transport *transport = priv->iscsi_transport;
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
session = transport->create_session(ep, cmds_max, queue_depth,
initial_cmdsn);
if (!session)
return -ENOMEM;
shost = iscsi_session_to_shost(session);
ev->r.c_session_ret.host_no = shost->host_no;
ev->r.c_session_ret.sid = session->sid;
ISCSI_DBG_TRANS_SESSION(session,
"Completed creating transport session\n");
return 0;
}
static int
iscsi_if_create_conn(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct iscsi_cls_conn *conn;
struct iscsi_cls_session *session;
session = iscsi_session_lookup(ev->u.c_conn.sid);
if (!session) {
printk(KERN_ERR "iscsi: invalid session %d.\n",
ev->u.c_conn.sid);
return -EINVAL;
}
conn = transport->create_conn(session, ev->u.c_conn.cid);
if (!conn) {
iscsi_cls_session_printk(KERN_ERR, session,
"couldn't create a new connection.");
return -ENOMEM;
}
ev->r.c_conn_ret.sid = session->sid;
ev->r.c_conn_ret.cid = conn->cid;
ISCSI_DBG_TRANS_CONN(conn, "Completed creating transport conn\n");
return 0;
}
static int
iscsi_if_destroy_conn(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct iscsi_cls_conn *conn;
conn = iscsi_conn_lookup(ev->u.d_conn.sid, ev->u.d_conn.cid);
if (!conn)
return -EINVAL;
ISCSI_DBG_TRANS_CONN(conn, "Destroying transport conn\n");
if (transport->destroy_conn)
transport->destroy_conn(conn);
return 0;
}
static int
iscsi_set_param(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
char *data = (char*)ev + sizeof(*ev);
struct iscsi_cls_conn *conn;
struct iscsi_cls_session *session;
int err = 0, value = 0;
session = iscsi_session_lookup(ev->u.set_param.sid);
conn = iscsi_conn_lookup(ev->u.set_param.sid, ev->u.set_param.cid);
if (!conn || !session)
return -EINVAL;
switch (ev->u.set_param.param) {
case ISCSI_PARAM_SESS_RECOVERY_TMO:
sscanf(data, "%d", &value);
session->recovery_tmo = value;
break;
default:
err = transport->set_param(conn, ev->u.set_param.param,
data, ev->u.set_param.len);
}
return err;
}
static int iscsi_if_ep_connect(struct iscsi_transport *transport,
struct iscsi_uevent *ev, int msg_type)
{
struct iscsi_endpoint *ep;
struct sockaddr *dst_addr;
struct Scsi_Host *shost = NULL;
int non_blocking, err = 0;
if (!transport->ep_connect)
return -EINVAL;
if (msg_type == ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST) {
shost = scsi_host_lookup(ev->u.ep_connect_through_host.host_no);
if (!shost) {
printk(KERN_ERR "ep connect failed. Could not find "
"host no %u\n",
ev->u.ep_connect_through_host.host_no);
return -ENODEV;
}
non_blocking = ev->u.ep_connect_through_host.non_blocking;
} else
non_blocking = ev->u.ep_connect.non_blocking;
dst_addr = (struct sockaddr *)((char*)ev + sizeof(*ev));
ep = transport->ep_connect(shost, dst_addr, non_blocking);
if (IS_ERR(ep)) {
err = PTR_ERR(ep);
goto release_host;
}
ev->r.ep_connect_ret.handle = ep->id;
release_host:
if (shost)
scsi_host_put(shost);
return err;
}
static int iscsi_if_ep_disconnect(struct iscsi_transport *transport,
u64 ep_handle)
{
struct iscsi_cls_conn *conn;
struct iscsi_endpoint *ep;
if (!transport->ep_disconnect)
return -EINVAL;
ep = iscsi_lookup_endpoint(ep_handle);
if (!ep)
return -EINVAL;
conn = ep->conn;
if (conn) {
mutex_lock(&conn->ep_mutex);
conn->ep = NULL;
mutex_unlock(&conn->ep_mutex);
}
transport->ep_disconnect(ep);
return 0;
}
static int
iscsi_if_transport_ep(struct iscsi_transport *transport,
struct iscsi_uevent *ev, int msg_type)
{
struct iscsi_endpoint *ep;
int rc = 0;
switch (msg_type) {
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST:
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT:
rc = iscsi_if_ep_connect(transport, ev, msg_type);
break;
case ISCSI_UEVENT_TRANSPORT_EP_POLL:
if (!transport->ep_poll)
return -EINVAL;
ep = iscsi_lookup_endpoint(ev->u.ep_poll.ep_handle);
if (!ep)
return -EINVAL;
ev->r.retcode = transport->ep_poll(ep,
ev->u.ep_poll.timeout_ms);
break;
case ISCSI_UEVENT_TRANSPORT_EP_DISCONNECT:
rc = iscsi_if_ep_disconnect(transport,
ev->u.ep_disconnect.ep_handle);
break;
}
return rc;
}
static int
iscsi_tgt_dscvr(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct sockaddr *dst_addr;
int err;
if (!transport->tgt_dscvr)
return -EINVAL;
shost = scsi_host_lookup(ev->u.tgt_dscvr.host_no);
if (!shost) {
printk(KERN_ERR "target discovery could not find host no %u\n",
ev->u.tgt_dscvr.host_no);
return -ENODEV;
}
dst_addr = (struct sockaddr *)((char*)ev + sizeof(*ev));
err = transport->tgt_dscvr(shost, ev->u.tgt_dscvr.type,
ev->u.tgt_dscvr.enable, dst_addr);
scsi_host_put(shost);
return err;
}
static int
iscsi_set_host_param(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
char *data = (char*)ev + sizeof(*ev);
struct Scsi_Host *shost;
int err;
if (!transport->set_host_param)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_host_param.host_no);
if (!shost) {
printk(KERN_ERR "set_host_param could not find host no %u\n",
ev->u.set_host_param.host_no);
return -ENODEV;
}
err = transport->set_host_param(shost, ev->u.set_host_param.param,
data, ev->u.set_host_param.len);
scsi_host_put(shost);
return err;
}
static int
iscsi_set_path(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_path *params;
int err;
if (!transport->set_path)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_path.host_no);
if (!shost) {
printk(KERN_ERR "set path could not find host no %u\n",
ev->u.set_path.host_no);
return -ENODEV;
}
params = (struct iscsi_path *)((char *)ev + sizeof(*ev));
err = transport->set_path(shost, params);
scsi_host_put(shost);
return err;
}
static int
iscsi_if_recv_msg(struct sk_buff *skb, struct nlmsghdr *nlh, uint32_t *group)
{
int err = 0;
struct iscsi_uevent *ev = NLMSG_DATA(nlh);
struct iscsi_transport *transport = NULL;
struct iscsi_internal *priv;
struct iscsi_cls_session *session;
struct iscsi_cls_conn *conn;
struct iscsi_endpoint *ep = NULL;
if (nlh->nlmsg_type == ISCSI_UEVENT_PATH_UPDATE)
*group = ISCSI_NL_GRP_UIP;
else
*group = ISCSI_NL_GRP_ISCSID;
priv = iscsi_if_transport_lookup(iscsi_ptr(ev->transport_handle));
if (!priv)
return -EINVAL;
transport = priv->iscsi_transport;
if (!try_module_get(transport->owner))
return -EINVAL;
switch (nlh->nlmsg_type) {
case ISCSI_UEVENT_CREATE_SESSION:
err = iscsi_if_create_session(priv, ep, ev,
ev->u.c_session.initial_cmdsn,
ev->u.c_session.cmds_max,
ev->u.c_session.queue_depth);
break;
case ISCSI_UEVENT_CREATE_BOUND_SESSION:
ep = iscsi_lookup_endpoint(ev->u.c_bound_session.ep_handle);
if (!ep) {
err = -EINVAL;
break;
}
err = iscsi_if_create_session(priv, ep, ev,
ev->u.c_bound_session.initial_cmdsn,
ev->u.c_bound_session.cmds_max,
ev->u.c_bound_session.queue_depth);
break;
case ISCSI_UEVENT_DESTROY_SESSION:
session = iscsi_session_lookup(ev->u.d_session.sid);
if (session)
transport->destroy_session(session);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_UNBIND_SESSION:
session = iscsi_session_lookup(ev->u.d_session.sid);
if (session)
scsi_queue_work(iscsi_session_to_shost(session),
&session->unbind_work);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_CREATE_CONN:
err = iscsi_if_create_conn(transport, ev);
break;
case ISCSI_UEVENT_DESTROY_CONN:
err = iscsi_if_destroy_conn(transport, ev);
break;
case ISCSI_UEVENT_BIND_CONN:
session = iscsi_session_lookup(ev->u.b_conn.sid);
conn = iscsi_conn_lookup(ev->u.b_conn.sid, ev->u.b_conn.cid);
if (conn && conn->ep)
iscsi_if_ep_disconnect(transport, conn->ep->id);
if (!session || !conn) {
err = -EINVAL;
break;
}
ev->r.retcode = transport->bind_conn(session, conn,
ev->u.b_conn.transport_eph,
ev->u.b_conn.is_leading);
if (ev->r.retcode || !transport->ep_connect)
break;
ep = iscsi_lookup_endpoint(ev->u.b_conn.transport_eph);
if (ep) {
ep->conn = conn;
mutex_lock(&conn->ep_mutex);
conn->ep = ep;
mutex_unlock(&conn->ep_mutex);
} else
iscsi_cls_conn_printk(KERN_ERR, conn,
"Could not set ep conn "
"binding\n");
break;
case ISCSI_UEVENT_SET_PARAM:
err = iscsi_set_param(transport, ev);
break;
case ISCSI_UEVENT_START_CONN:
conn = iscsi_conn_lookup(ev->u.start_conn.sid, ev->u.start_conn.cid);
if (conn)
ev->r.retcode = transport->start_conn(conn);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_STOP_CONN:
conn = iscsi_conn_lookup(ev->u.stop_conn.sid, ev->u.stop_conn.cid);
if (conn)
transport->stop_conn(conn, ev->u.stop_conn.flag);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_SEND_PDU:
conn = iscsi_conn_lookup(ev->u.send_pdu.sid, ev->u.send_pdu.cid);
if (conn)
ev->r.retcode = transport->send_pdu(conn,
(struct iscsi_hdr*)((char*)ev + sizeof(*ev)),
(char*)ev + sizeof(*ev) + ev->u.send_pdu.hdr_size,
ev->u.send_pdu.data_size);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_GET_STATS:
err = iscsi_if_get_stats(transport, nlh);
break;
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT:
case ISCSI_UEVENT_TRANSPORT_EP_POLL:
case ISCSI_UEVENT_TRANSPORT_EP_DISCONNECT:
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST:
err = iscsi_if_transport_ep(transport, ev, nlh->nlmsg_type);
break;
case ISCSI_UEVENT_TGT_DSCVR:
err = iscsi_tgt_dscvr(transport, ev);
break;
case ISCSI_UEVENT_SET_HOST_PARAM:
err = iscsi_set_host_param(transport, ev);
break;
case ISCSI_UEVENT_PATH_UPDATE:
err = iscsi_set_path(transport, ev);
break;
default:
err = -ENOSYS;
break;
}
module_put(transport->owner);
return err;
}
static void
iscsi_if_rx(struct sk_buff *skb)
{
mutex_lock(&rx_queue_mutex);
while (skb->len >= NLMSG_SPACE(0)) {
int err;
uint32_t rlen;
struct nlmsghdr *nlh;
struct iscsi_uevent *ev;
uint32_t group;
nlh = nlmsg_hdr(skb);
if (nlh->nlmsg_len < sizeof(*nlh) ||
skb->len < nlh->nlmsg_len) {
break;
}
ev = NLMSG_DATA(nlh);
rlen = NLMSG_ALIGN(nlh->nlmsg_len);
if (rlen > skb->len)
rlen = skb->len;
err = iscsi_if_recv_msg(skb, nlh, &group);
if (err) {
ev->type = ISCSI_KEVENT_IF_ERROR;
ev->iferror = err;
}
do {
if (ev->type == ISCSI_UEVENT_GET_STATS && !err)
break;
err = iscsi_if_send_reply(group, nlh->nlmsg_seq,
nlh->nlmsg_type, 0, 0, ev, sizeof(*ev));
} while (err < 0 && err != -ECONNREFUSED);
skb_pull(skb, rlen);
}
mutex_unlock(&rx_queue_mutex);
}
static ssize_t
show_priv_session_state(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev->parent);
return sprintf(buf, "%s\n", iscsi_session_state_name(session->state));
}
static int iscsi_session_match(struct attribute_container *cont,
struct device *dev)
{
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!iscsi_is_session_dev(dev))
return 0;
session = iscsi_dev_to_session(dev);
shost = iscsi_session_to_shost(session);
if (!shost->transportt)
return 0;
priv = to_iscsi_internal(shost->transportt);
if (priv->session_cont.ac.class != &iscsi_session_class.class)
return 0;
return &priv->session_cont.ac == cont;
}
static int iscsi_conn_match(struct attribute_container *cont,
struct device *dev)
{
struct iscsi_cls_session *session;
struct iscsi_cls_conn *conn;
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!iscsi_is_conn_dev(dev))
return 0;
conn = iscsi_dev_to_conn(dev);
session = iscsi_dev_to_session(conn->dev.parent);
shost = iscsi_session_to_shost(session);
if (!shost->transportt)
return 0;
priv = to_iscsi_internal(shost->transportt);
if (priv->conn_cont.ac.class != &iscsi_connection_class.class)
return 0;
return &priv->conn_cont.ac == cont;
}
static int iscsi_host_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt ||
shost->transportt->host_attrs.ac.class != &iscsi_host_class.class)
return 0;
priv = to_iscsi_internal(shost->transportt);
return &priv->t.host_attrs.ac == cont;
}
struct scsi_transport_template *
iscsi_register_transport(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
int count = 0, err;
BUG_ON(!tt);
priv = iscsi_if_transport_lookup(tt);
if (priv)
return NULL;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return NULL;
INIT_LIST_HEAD(&priv->list);
priv->iscsi_transport = tt;
priv->t.user_scan = iscsi_user_scan;
priv->t.create_work_queue = 1;
priv->dev.class = &iscsi_transport_class;
dev_set_name(&priv->dev, "%s", tt->name);
err = device_register(&priv->dev);
if (err)
goto free_priv;
err = sysfs_create_group(&priv->dev.kobj, &iscsi_transport_group);
if (err)
goto unregister_dev;
priv->t.host_attrs.ac.attrs = &priv->host_attrs[0];
priv->t.host_attrs.ac.class = &iscsi_host_class.class;
priv->t.host_attrs.ac.match = iscsi_host_match;
priv->t.host_size = sizeof(struct iscsi_cls_host);
transport_container_register(&priv->t.host_attrs);
SETUP_HOST_RD_ATTR(netdev, ISCSI_HOST_NETDEV_NAME);
SETUP_HOST_RD_ATTR(ipaddress, ISCSI_HOST_IPADDRESS);
SETUP_HOST_RD_ATTR(hwaddress, ISCSI_HOST_HWADDRESS);
SETUP_HOST_RD_ATTR(initiatorname, ISCSI_HOST_INITIATOR_NAME);
BUG_ON(count > ISCSI_HOST_ATTRS);
priv->host_attrs[count] = NULL;
count = 0;
priv->conn_cont.ac.attrs = &priv->conn_attrs[0];
priv->conn_cont.ac.class = &iscsi_connection_class.class;
priv->conn_cont.ac.match = iscsi_conn_match;
transport_container_register(&priv->conn_cont);
SETUP_CONN_RD_ATTR(max_recv_dlength, ISCSI_MAX_RECV_DLENGTH);
SETUP_CONN_RD_ATTR(max_xmit_dlength, ISCSI_MAX_XMIT_DLENGTH);
SETUP_CONN_RD_ATTR(header_digest, ISCSI_HDRDGST_EN);
SETUP_CONN_RD_ATTR(data_digest, ISCSI_DATADGST_EN);
SETUP_CONN_RD_ATTR(ifmarker, ISCSI_IFMARKER_EN);
SETUP_CONN_RD_ATTR(ofmarker, ISCSI_OFMARKER_EN);
SETUP_CONN_RD_ATTR(address, ISCSI_CONN_ADDRESS);
SETUP_CONN_RD_ATTR(port, ISCSI_CONN_PORT);
SETUP_CONN_RD_ATTR(exp_statsn, ISCSI_EXP_STATSN);
SETUP_CONN_RD_ATTR(persistent_address, ISCSI_PERSISTENT_ADDRESS);
SETUP_CONN_RD_ATTR(persistent_port, ISCSI_PERSISTENT_PORT);
SETUP_CONN_RD_ATTR(ping_tmo, ISCSI_PING_TMO);
SETUP_CONN_RD_ATTR(recv_tmo, ISCSI_RECV_TMO);
BUG_ON(count > ISCSI_CONN_ATTRS);
priv->conn_attrs[count] = NULL;
count = 0;
priv->session_cont.ac.attrs = &priv->session_attrs[0];
priv->session_cont.ac.class = &iscsi_session_class.class;
priv->session_cont.ac.match = iscsi_session_match;
transport_container_register(&priv->session_cont);
SETUP_SESSION_RD_ATTR(initial_r2t, ISCSI_INITIAL_R2T_EN);
SETUP_SESSION_RD_ATTR(max_outstanding_r2t, ISCSI_MAX_R2T);
SETUP_SESSION_RD_ATTR(immediate_data, ISCSI_IMM_DATA_EN);
SETUP_SESSION_RD_ATTR(first_burst_len, ISCSI_FIRST_BURST);
SETUP_SESSION_RD_ATTR(max_burst_len, ISCSI_MAX_BURST);
SETUP_SESSION_RD_ATTR(data_pdu_in_order, ISCSI_PDU_INORDER_EN);
SETUP_SESSION_RD_ATTR(data_seq_in_order, ISCSI_DATASEQ_INORDER_EN);
SETUP_SESSION_RD_ATTR(erl, ISCSI_ERL);
SETUP_SESSION_RD_ATTR(targetname, ISCSI_TARGET_NAME);
SETUP_SESSION_RD_ATTR(tpgt, ISCSI_TPGT);
SETUP_SESSION_RD_ATTR(password, ISCSI_USERNAME);
SETUP_SESSION_RD_ATTR(password_in, ISCSI_USERNAME_IN);
SETUP_SESSION_RD_ATTR(username, ISCSI_PASSWORD);
SETUP_SESSION_RD_ATTR(username_in, ISCSI_PASSWORD_IN);
SETUP_SESSION_RD_ATTR(fast_abort, ISCSI_FAST_ABORT);
SETUP_SESSION_RD_ATTR(abort_tmo, ISCSI_ABORT_TMO);
SETUP_SESSION_RD_ATTR(lu_reset_tmo,ISCSI_LU_RESET_TMO);
SETUP_SESSION_RD_ATTR(tgt_reset_tmo,ISCSI_TGT_RESET_TMO);
SETUP_SESSION_RD_ATTR(ifacename, ISCSI_IFACE_NAME);
SETUP_SESSION_RD_ATTR(initiatorname, ISCSI_INITIATOR_NAME);
SETUP_SESSION_RD_ATTR(targetalias, ISCSI_TARGET_ALIAS);
SETUP_PRIV_SESSION_RW_ATTR(recovery_tmo);
SETUP_PRIV_SESSION_RD_ATTR(state);
BUG_ON(count > ISCSI_SESSION_ATTRS);
priv->session_attrs[count] = NULL;
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_add(&priv->list, &iscsi_transports);
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
printk(KERN_NOTICE "iscsi: registered transport (%s)\n", tt->name);
return &priv->t;
unregister_dev:
device_unregister(&priv->dev);
return NULL;
free_priv:
kfree(priv);
return NULL;
}
int iscsi_unregister_transport(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
BUG_ON(!tt);
mutex_lock(&rx_queue_mutex);
priv = iscsi_if_transport_lookup(tt);
BUG_ON (!priv);
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_del(&priv->list);
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
transport_container_unregister(&priv->conn_cont);
transport_container_unregister(&priv->session_cont);
transport_container_unregister(&priv->t.host_attrs);
sysfs_remove_group(&priv->dev.kobj, &iscsi_transport_group);
device_unregister(&priv->dev);
mutex_unlock(&rx_queue_mutex);
return 0;
}
static __init int iscsi_transport_init(void)
{
int err;
printk(KERN_INFO "Loading iSCSI transport class v%s.\n",
ISCSI_TRANSPORT_VERSION);
atomic_set(&iscsi_session_nr, 0);
err = class_register(&iscsi_transport_class);
if (err)
return err;
err = class_register(&iscsi_endpoint_class);
if (err)
goto unregister_transport_class;
err = transport_class_register(&iscsi_host_class);
if (err)
goto unregister_endpoint_class;
err = transport_class_register(&iscsi_connection_class);
if (err)
goto unregister_host_class;
err = transport_class_register(&iscsi_session_class);
if (err)
goto unregister_conn_class;
nls = netlink_kernel_create(&init_net, NETLINK_ISCSI, 1, iscsi_if_rx,
NULL, THIS_MODULE);
if (!nls) {
err = -ENOBUFS;
goto unregister_session_class;
}
iscsi_eh_timer_workq = create_singlethread_workqueue("iscsi_eh");
if (!iscsi_eh_timer_workq)
goto release_nls;
return 0;
release_nls:
netlink_kernel_release(nls);
unregister_session_class:
transport_class_unregister(&iscsi_session_class);
unregister_conn_class:
transport_class_unregister(&iscsi_connection_class);
unregister_host_class:
transport_class_unregister(&iscsi_host_class);
unregister_endpoint_class:
class_unregister(&iscsi_endpoint_class);
unregister_transport_class:
class_unregister(&iscsi_transport_class);
return err;
}
static void __exit iscsi_transport_exit(void)
{
destroy_workqueue(iscsi_eh_timer_workq);
netlink_kernel_release(nls);
transport_class_unregister(&iscsi_connection_class);
transport_class_unregister(&iscsi_session_class);
transport_class_unregister(&iscsi_host_class);
class_unregister(&iscsi_endpoint_class);
class_unregister(&iscsi_transport_class);
}
