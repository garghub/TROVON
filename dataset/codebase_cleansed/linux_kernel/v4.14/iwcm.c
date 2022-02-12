const char *__attribute_const__ iwcm_reject_msg(int reason)
{
size_t index;
index = -reason;
if (index < ARRAY_SIZE(iwcm_rej_reason_strs) &&
iwcm_rej_reason_strs[index])
return iwcm_rej_reason_strs[index];
else
return "unrecognized reason";
}
static struct iwcm_work *get_work(struct iwcm_id_private *cm_id_priv)
{
struct iwcm_work *work;
if (list_empty(&cm_id_priv->work_free_list))
return NULL;
work = list_entry(cm_id_priv->work_free_list.next, struct iwcm_work,
free_list);
list_del_init(&work->free_list);
return work;
}
static void put_work(struct iwcm_work *work)
{
list_add(&work->free_list, &work->cm_id->work_free_list);
}
static void dealloc_work_entries(struct iwcm_id_private *cm_id_priv)
{
struct list_head *e, *tmp;
list_for_each_safe(e, tmp, &cm_id_priv->work_free_list)
kfree(list_entry(e, struct iwcm_work, free_list));
}
static int alloc_work_entries(struct iwcm_id_private *cm_id_priv, int count)
{
struct iwcm_work *work;
BUG_ON(!list_empty(&cm_id_priv->work_free_list));
while (count--) {
work = kmalloc(sizeof(struct iwcm_work), GFP_KERNEL);
if (!work) {
dealloc_work_entries(cm_id_priv);
return -ENOMEM;
}
work->cm_id = cm_id_priv;
INIT_LIST_HEAD(&work->list);
put_work(work);
}
return 0;
}
static int copy_private_data(struct iw_cm_event *event)
{
void *p;
p = kmemdup(event->private_data, event->private_data_len, GFP_ATOMIC);
if (!p)
return -ENOMEM;
event->private_data = p;
return 0;
}
static void free_cm_id(struct iwcm_id_private *cm_id_priv)
{
dealloc_work_entries(cm_id_priv);
kfree(cm_id_priv);
}
static int iwcm_deref_id(struct iwcm_id_private *cm_id_priv)
{
BUG_ON(atomic_read(&cm_id_priv->refcount)==0);
if (atomic_dec_and_test(&cm_id_priv->refcount)) {
BUG_ON(!list_empty(&cm_id_priv->work_list));
free_cm_id(cm_id_priv);
return 1;
}
return 0;
}
static void add_ref(struct iw_cm_id *cm_id)
{
struct iwcm_id_private *cm_id_priv;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
atomic_inc(&cm_id_priv->refcount);
}
static void rem_ref(struct iw_cm_id *cm_id)
{
struct iwcm_id_private *cm_id_priv;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
(void)iwcm_deref_id(cm_id_priv);
}
struct iw_cm_id *iw_create_cm_id(struct ib_device *device,
iw_cm_handler cm_handler,
void *context)
{
struct iwcm_id_private *cm_id_priv;
cm_id_priv = kzalloc(sizeof(*cm_id_priv), GFP_KERNEL);
if (!cm_id_priv)
return ERR_PTR(-ENOMEM);
cm_id_priv->state = IW_CM_STATE_IDLE;
cm_id_priv->id.device = device;
cm_id_priv->id.cm_handler = cm_handler;
cm_id_priv->id.context = context;
cm_id_priv->id.event_handler = cm_event_handler;
cm_id_priv->id.add_ref = add_ref;
cm_id_priv->id.rem_ref = rem_ref;
spin_lock_init(&cm_id_priv->lock);
atomic_set(&cm_id_priv->refcount, 1);
init_waitqueue_head(&cm_id_priv->connect_wait);
init_completion(&cm_id_priv->destroy_comp);
INIT_LIST_HEAD(&cm_id_priv->work_list);
INIT_LIST_HEAD(&cm_id_priv->work_free_list);
return &cm_id_priv->id;
}
static int iwcm_modify_qp_err(struct ib_qp *qp)
{
struct ib_qp_attr qp_attr;
if (!qp)
return -EINVAL;
qp_attr.qp_state = IB_QPS_ERR;
return ib_modify_qp(qp, &qp_attr, IB_QP_STATE);
}
static int iwcm_modify_qp_sqd(struct ib_qp *qp)
{
struct ib_qp_attr qp_attr;
BUG_ON(qp == NULL);
qp_attr.qp_state = IB_QPS_SQD;
return ib_modify_qp(qp, &qp_attr, IB_QP_STATE);
}
int iw_cm_disconnect(struct iw_cm_id *cm_id, int abrupt)
{
struct iwcm_id_private *cm_id_priv;
unsigned long flags;
int ret = 0;
struct ib_qp *qp = NULL;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
wait_event(cm_id_priv->connect_wait,
!test_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags));
spin_lock_irqsave(&cm_id_priv->lock, flags);
switch (cm_id_priv->state) {
case IW_CM_STATE_ESTABLISHED:
cm_id_priv->state = IW_CM_STATE_CLOSING;
if (cm_id_priv->qp)
qp = cm_id_priv->qp;
else
ret = -EINVAL;
break;
case IW_CM_STATE_LISTEN:
ret = -EINVAL;
break;
case IW_CM_STATE_CLOSING:
case IW_CM_STATE_IDLE:
break;
case IW_CM_STATE_CONN_RECV:
break;
case IW_CM_STATE_CONN_SENT:
default:
BUG();
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
if (qp) {
if (abrupt)
ret = iwcm_modify_qp_err(qp);
else
ret = iwcm_modify_qp_sqd(qp);
ret = 0;
}
return ret;
}
static void destroy_cm_id(struct iw_cm_id *cm_id)
{
struct iwcm_id_private *cm_id_priv;
unsigned long flags;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
wait_event(cm_id_priv->connect_wait,
!test_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags));
set_bit(IWCM_F_DROP_EVENTS, &cm_id_priv->flags);
spin_lock_irqsave(&cm_id_priv->lock, flags);
switch (cm_id_priv->state) {
case IW_CM_STATE_LISTEN:
cm_id_priv->state = IW_CM_STATE_DESTROYING;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
cm_id->device->iwcm->destroy_listen(cm_id);
spin_lock_irqsave(&cm_id_priv->lock, flags);
break;
case IW_CM_STATE_ESTABLISHED:
cm_id_priv->state = IW_CM_STATE_DESTROYING;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
(void)iwcm_modify_qp_err(cm_id_priv->qp);
spin_lock_irqsave(&cm_id_priv->lock, flags);
break;
case IW_CM_STATE_IDLE:
case IW_CM_STATE_CLOSING:
cm_id_priv->state = IW_CM_STATE_DESTROYING;
break;
case IW_CM_STATE_CONN_RECV:
cm_id_priv->state = IW_CM_STATE_DESTROYING;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
cm_id->device->iwcm->reject(cm_id, NULL, 0);
spin_lock_irqsave(&cm_id_priv->lock, flags);
break;
case IW_CM_STATE_CONN_SENT:
case IW_CM_STATE_DESTROYING:
default:
BUG();
break;
}
if (cm_id_priv->qp) {
cm_id_priv->id.device->iwcm->rem_ref(cm_id_priv->qp);
cm_id_priv->qp = NULL;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
if (cm_id->mapped) {
iwpm_remove_mapinfo(&cm_id->local_addr, &cm_id->m_local_addr);
iwpm_remove_mapping(&cm_id->local_addr, RDMA_NL_IWCM);
}
(void)iwcm_deref_id(cm_id_priv);
}
void iw_destroy_cm_id(struct iw_cm_id *cm_id)
{
struct iwcm_id_private *cm_id_priv;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
destroy_cm_id(cm_id);
}
static void iw_cm_check_wildcard(struct sockaddr_storage *pm_addr,
struct sockaddr_storage *cm_addr,
struct sockaddr_storage *cm_outaddr)
{
if (pm_addr->ss_family == AF_INET) {
struct sockaddr_in *pm4_addr = (struct sockaddr_in *)pm_addr;
if (pm4_addr->sin_addr.s_addr == htonl(INADDR_ANY)) {
struct sockaddr_in *cm4_addr =
(struct sockaddr_in *)cm_addr;
struct sockaddr_in *cm4_outaddr =
(struct sockaddr_in *)cm_outaddr;
cm4_outaddr->sin_addr = cm4_addr->sin_addr;
}
} else {
struct sockaddr_in6 *pm6_addr = (struct sockaddr_in6 *)pm_addr;
if (ipv6_addr_type(&pm6_addr->sin6_addr) == IPV6_ADDR_ANY) {
struct sockaddr_in6 *cm6_addr =
(struct sockaddr_in6 *)cm_addr;
struct sockaddr_in6 *cm6_outaddr =
(struct sockaddr_in6 *)cm_outaddr;
cm6_outaddr->sin6_addr = cm6_addr->sin6_addr;
}
}
}
static int iw_cm_map(struct iw_cm_id *cm_id, bool active)
{
struct iwpm_dev_data pm_reg_msg;
struct iwpm_sa_data pm_msg;
int status;
cm_id->m_local_addr = cm_id->local_addr;
cm_id->m_remote_addr = cm_id->remote_addr;
memcpy(pm_reg_msg.dev_name, cm_id->device->name,
sizeof(pm_reg_msg.dev_name));
memcpy(pm_reg_msg.if_name, cm_id->device->iwcm->ifname,
sizeof(pm_reg_msg.if_name));
if (iwpm_register_pid(&pm_reg_msg, RDMA_NL_IWCM) ||
!iwpm_valid_pid())
return 0;
cm_id->mapped = true;
pm_msg.loc_addr = cm_id->local_addr;
pm_msg.rem_addr = cm_id->remote_addr;
if (active)
status = iwpm_add_and_query_mapping(&pm_msg,
RDMA_NL_IWCM);
else
status = iwpm_add_mapping(&pm_msg, RDMA_NL_IWCM);
if (!status) {
cm_id->m_local_addr = pm_msg.mapped_loc_addr;
if (active) {
cm_id->m_remote_addr = pm_msg.mapped_rem_addr;
iw_cm_check_wildcard(&pm_msg.mapped_rem_addr,
&cm_id->remote_addr,
&cm_id->m_remote_addr);
}
}
return iwpm_create_mapinfo(&cm_id->local_addr,
&cm_id->m_local_addr,
RDMA_NL_IWCM);
}
int iw_cm_listen(struct iw_cm_id *cm_id, int backlog)
{
struct iwcm_id_private *cm_id_priv;
unsigned long flags;
int ret;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
if (!backlog)
backlog = default_backlog;
ret = alloc_work_entries(cm_id_priv, backlog);
if (ret)
return ret;
spin_lock_irqsave(&cm_id_priv->lock, flags);
switch (cm_id_priv->state) {
case IW_CM_STATE_IDLE:
cm_id_priv->state = IW_CM_STATE_LISTEN;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = iw_cm_map(cm_id, false);
if (!ret)
ret = cm_id->device->iwcm->create_listen(cm_id, backlog);
if (ret)
cm_id_priv->state = IW_CM_STATE_IDLE;
spin_lock_irqsave(&cm_id_priv->lock, flags);
break;
default:
ret = -EINVAL;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
return ret;
}
int iw_cm_reject(struct iw_cm_id *cm_id,
const void *private_data,
u8 private_data_len)
{
struct iwcm_id_private *cm_id_priv;
unsigned long flags;
int ret;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
set_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->state != IW_CM_STATE_CONN_RECV) {
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
return -EINVAL;
}
cm_id_priv->state = IW_CM_STATE_IDLE;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = cm_id->device->iwcm->reject(cm_id, private_data,
private_data_len);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
return ret;
}
int iw_cm_accept(struct iw_cm_id *cm_id,
struct iw_cm_conn_param *iw_param)
{
struct iwcm_id_private *cm_id_priv;
struct ib_qp *qp;
unsigned long flags;
int ret;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
set_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->state != IW_CM_STATE_CONN_RECV) {
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
return -EINVAL;
}
qp = cm_id->device->iwcm->get_qp(cm_id->device, iw_param->qpn);
if (!qp) {
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
return -EINVAL;
}
cm_id->device->iwcm->add_ref(qp);
cm_id_priv->qp = qp;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = cm_id->device->iwcm->accept(cm_id, iw_param);
if (ret) {
BUG_ON(cm_id_priv->state != IW_CM_STATE_CONN_RECV);
cm_id_priv->state = IW_CM_STATE_IDLE;
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->qp) {
cm_id->device->iwcm->rem_ref(qp);
cm_id_priv->qp = NULL;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
}
return ret;
}
int iw_cm_connect(struct iw_cm_id *cm_id, struct iw_cm_conn_param *iw_param)
{
struct iwcm_id_private *cm_id_priv;
int ret;
unsigned long flags;
struct ib_qp *qp;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
ret = alloc_work_entries(cm_id_priv, 4);
if (ret)
return ret;
set_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->state != IW_CM_STATE_IDLE) {
ret = -EINVAL;
goto err;
}
qp = cm_id->device->iwcm->get_qp(cm_id->device, iw_param->qpn);
if (!qp) {
ret = -EINVAL;
goto err;
}
cm_id->device->iwcm->add_ref(qp);
cm_id_priv->qp = qp;
cm_id_priv->state = IW_CM_STATE_CONN_SENT;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = iw_cm_map(cm_id, true);
if (!ret)
ret = cm_id->device->iwcm->connect(cm_id, iw_param);
if (!ret)
return 0;
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->qp) {
cm_id->device->iwcm->rem_ref(qp);
cm_id_priv->qp = NULL;
}
cm_id_priv->state = IW_CM_STATE_IDLE;
err:
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
wake_up_all(&cm_id_priv->connect_wait);
return ret;
}
static void cm_conn_req_handler(struct iwcm_id_private *listen_id_priv,
struct iw_cm_event *iw_event)
{
unsigned long flags;
struct iw_cm_id *cm_id;
struct iwcm_id_private *cm_id_priv;
int ret;
BUG_ON(iw_event->status);
cm_id = iw_create_cm_id(listen_id_priv->id.device,
listen_id_priv->id.cm_handler,
listen_id_priv->id.context);
if (IS_ERR(cm_id))
goto out;
cm_id->provider_data = iw_event->provider_data;
cm_id->m_local_addr = iw_event->local_addr;
cm_id->m_remote_addr = iw_event->remote_addr;
cm_id->local_addr = listen_id_priv->id.local_addr;
ret = iwpm_get_remote_info(&listen_id_priv->id.m_local_addr,
&iw_event->remote_addr,
&cm_id->remote_addr,
RDMA_NL_IWCM);
if (ret) {
cm_id->remote_addr = iw_event->remote_addr;
} else {
iw_cm_check_wildcard(&listen_id_priv->id.m_local_addr,
&iw_event->local_addr,
&cm_id->local_addr);
iw_event->local_addr = cm_id->local_addr;
iw_event->remote_addr = cm_id->remote_addr;
}
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
cm_id_priv->state = IW_CM_STATE_CONN_RECV;
spin_lock_irqsave(&listen_id_priv->lock, flags);
if (listen_id_priv->state != IW_CM_STATE_LISTEN) {
spin_unlock_irqrestore(&listen_id_priv->lock, flags);
iw_cm_reject(cm_id, NULL, 0);
iw_destroy_cm_id(cm_id);
goto out;
}
spin_unlock_irqrestore(&listen_id_priv->lock, flags);
ret = alloc_work_entries(cm_id_priv, 3);
if (ret) {
iw_cm_reject(cm_id, NULL, 0);
iw_destroy_cm_id(cm_id);
goto out;
}
ret = cm_id->cm_handler(cm_id, iw_event);
if (ret) {
iw_cm_reject(cm_id, NULL, 0);
iw_destroy_cm_id(cm_id);
}
out:
if (iw_event->private_data_len)
kfree(iw_event->private_data);
}
static int cm_conn_est_handler(struct iwcm_id_private *cm_id_priv,
struct iw_cm_event *iw_event)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
BUG_ON(cm_id_priv->state != IW_CM_STATE_CONN_RECV);
cm_id_priv->state = IW_CM_STATE_ESTABLISHED;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = cm_id_priv->id.cm_handler(&cm_id_priv->id, iw_event);
wake_up_all(&cm_id_priv->connect_wait);
return ret;
}
static int cm_conn_rep_handler(struct iwcm_id_private *cm_id_priv,
struct iw_cm_event *iw_event)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&cm_id_priv->lock, flags);
clear_bit(IWCM_F_CONNECT_WAIT, &cm_id_priv->flags);
BUG_ON(cm_id_priv->state != IW_CM_STATE_CONN_SENT);
if (iw_event->status == 0) {
cm_id_priv->id.m_local_addr = iw_event->local_addr;
cm_id_priv->id.m_remote_addr = iw_event->remote_addr;
iw_event->local_addr = cm_id_priv->id.local_addr;
iw_event->remote_addr = cm_id_priv->id.remote_addr;
cm_id_priv->state = IW_CM_STATE_ESTABLISHED;
} else {
cm_id_priv->id.device->iwcm->rem_ref(cm_id_priv->qp);
cm_id_priv->qp = NULL;
cm_id_priv->state = IW_CM_STATE_IDLE;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = cm_id_priv->id.cm_handler(&cm_id_priv->id, iw_event);
if (iw_event->private_data_len)
kfree(iw_event->private_data);
wake_up_all(&cm_id_priv->connect_wait);
return ret;
}
static void cm_disconnect_handler(struct iwcm_id_private *cm_id_priv,
struct iw_cm_event *iw_event)
{
unsigned long flags;
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->state == IW_CM_STATE_ESTABLISHED)
cm_id_priv->state = IW_CM_STATE_CLOSING;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
}
static int cm_close_handler(struct iwcm_id_private *cm_id_priv,
struct iw_cm_event *iw_event)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&cm_id_priv->lock, flags);
if (cm_id_priv->qp) {
cm_id_priv->id.device->iwcm->rem_ref(cm_id_priv->qp);
cm_id_priv->qp = NULL;
}
switch (cm_id_priv->state) {
case IW_CM_STATE_ESTABLISHED:
case IW_CM_STATE_CLOSING:
cm_id_priv->state = IW_CM_STATE_IDLE;
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
ret = cm_id_priv->id.cm_handler(&cm_id_priv->id, iw_event);
spin_lock_irqsave(&cm_id_priv->lock, flags);
break;
case IW_CM_STATE_DESTROYING:
break;
default:
BUG();
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
return ret;
}
static int process_event(struct iwcm_id_private *cm_id_priv,
struct iw_cm_event *iw_event)
{
int ret = 0;
switch (iw_event->event) {
case IW_CM_EVENT_CONNECT_REQUEST:
cm_conn_req_handler(cm_id_priv, iw_event);
break;
case IW_CM_EVENT_CONNECT_REPLY:
ret = cm_conn_rep_handler(cm_id_priv, iw_event);
break;
case IW_CM_EVENT_ESTABLISHED:
ret = cm_conn_est_handler(cm_id_priv, iw_event);
break;
case IW_CM_EVENT_DISCONNECT:
cm_disconnect_handler(cm_id_priv, iw_event);
break;
case IW_CM_EVENT_CLOSE:
ret = cm_close_handler(cm_id_priv, iw_event);
break;
default:
BUG();
}
return ret;
}
static void cm_work_handler(struct work_struct *_work)
{
struct iwcm_work *work = container_of(_work, struct iwcm_work, work);
struct iw_cm_event levent;
struct iwcm_id_private *cm_id_priv = work->cm_id;
unsigned long flags;
int empty;
int ret = 0;
spin_lock_irqsave(&cm_id_priv->lock, flags);
empty = list_empty(&cm_id_priv->work_list);
while (!empty) {
work = list_entry(cm_id_priv->work_list.next,
struct iwcm_work, list);
list_del_init(&work->list);
empty = list_empty(&cm_id_priv->work_list);
levent = work->event;
put_work(work);
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
if (!test_bit(IWCM_F_DROP_EVENTS, &cm_id_priv->flags)) {
ret = process_event(cm_id_priv, &levent);
if (ret)
destroy_cm_id(&cm_id_priv->id);
} else
pr_debug("dropping event %d\n", levent.event);
if (iwcm_deref_id(cm_id_priv))
return;
if (empty)
return;
spin_lock_irqsave(&cm_id_priv->lock, flags);
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
}
static int cm_event_handler(struct iw_cm_id *cm_id,
struct iw_cm_event *iw_event)
{
struct iwcm_work *work;
struct iwcm_id_private *cm_id_priv;
unsigned long flags;
int ret = 0;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
spin_lock_irqsave(&cm_id_priv->lock, flags);
work = get_work(cm_id_priv);
if (!work) {
ret = -ENOMEM;
goto out;
}
INIT_WORK(&work->work, cm_work_handler);
work->cm_id = cm_id_priv;
work->event = *iw_event;
if ((work->event.event == IW_CM_EVENT_CONNECT_REQUEST ||
work->event.event == IW_CM_EVENT_CONNECT_REPLY) &&
work->event.private_data_len) {
ret = copy_private_data(&work->event);
if (ret) {
put_work(work);
goto out;
}
}
atomic_inc(&cm_id_priv->refcount);
if (list_empty(&cm_id_priv->work_list)) {
list_add_tail(&work->list, &cm_id_priv->work_list);
queue_work(iwcm_wq, &work->work);
} else
list_add_tail(&work->list, &cm_id_priv->work_list);
out:
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
return ret;
}
static int iwcm_init_qp_init_attr(struct iwcm_id_private *cm_id_priv,
struct ib_qp_attr *qp_attr,
int *qp_attr_mask)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&cm_id_priv->lock, flags);
switch (cm_id_priv->state) {
case IW_CM_STATE_IDLE:
case IW_CM_STATE_CONN_SENT:
case IW_CM_STATE_CONN_RECV:
case IW_CM_STATE_ESTABLISHED:
*qp_attr_mask = IB_QP_STATE | IB_QP_ACCESS_FLAGS;
qp_attr->qp_access_flags = IB_ACCESS_REMOTE_WRITE|
IB_ACCESS_REMOTE_READ;
ret = 0;
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
return ret;
}
static int iwcm_init_qp_rts_attr(struct iwcm_id_private *cm_id_priv,
struct ib_qp_attr *qp_attr,
int *qp_attr_mask)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&cm_id_priv->lock, flags);
switch (cm_id_priv->state) {
case IW_CM_STATE_IDLE:
case IW_CM_STATE_CONN_SENT:
case IW_CM_STATE_CONN_RECV:
case IW_CM_STATE_ESTABLISHED:
*qp_attr_mask = 0;
ret = 0;
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&cm_id_priv->lock, flags);
return ret;
}
int iw_cm_init_qp_attr(struct iw_cm_id *cm_id,
struct ib_qp_attr *qp_attr,
int *qp_attr_mask)
{
struct iwcm_id_private *cm_id_priv;
int ret;
cm_id_priv = container_of(cm_id, struct iwcm_id_private, id);
switch (qp_attr->qp_state) {
case IB_QPS_INIT:
case IB_QPS_RTR:
ret = iwcm_init_qp_init_attr(cm_id_priv,
qp_attr, qp_attr_mask);
break;
case IB_QPS_RTS:
ret = iwcm_init_qp_rts_attr(cm_id_priv,
qp_attr, qp_attr_mask);
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int __init iw_cm_init(void)
{
int ret;
ret = iwpm_init(RDMA_NL_IWCM);
if (ret)
pr_err("iw_cm: couldn't init iwpm\n");
else
rdma_nl_register(RDMA_NL_IWCM, iwcm_nl_cb_table);
iwcm_wq = alloc_ordered_workqueue("iw_cm_wq", 0);
if (!iwcm_wq)
return -ENOMEM;
iwcm_ctl_table_hdr = register_net_sysctl(&init_net, "net/iw_cm",
iwcm_ctl_table);
if (!iwcm_ctl_table_hdr) {
pr_err("iw_cm: couldn't register sysctl paths\n");
destroy_workqueue(iwcm_wq);
return -ENOMEM;
}
return 0;
}
static void __exit iw_cm_cleanup(void)
{
unregister_net_sysctl_table(iwcm_ctl_table_hdr);
destroy_workqueue(iwcm_wq);
rdma_nl_unregister(RDMA_NL_IWCM);
iwpm_exit(RDMA_NL_IWCM);
}
