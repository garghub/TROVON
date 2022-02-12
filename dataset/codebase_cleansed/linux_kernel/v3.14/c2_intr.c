void c2_rnic_interrupt(struct c2_dev *c2dev)
{
unsigned int mq_index;
while (c2dev->hints_read != be16_to_cpu(*c2dev->hint_count)) {
mq_index = readl(c2dev->regs + PCI_BAR0_HOST_HINT);
if (mq_index & 0x80000000) {
break;
}
c2dev->hints_read++;
handle_mq(c2dev, mq_index);
}
}
static void handle_mq(struct c2_dev *c2dev, u32 mq_index)
{
if (c2dev->qptr_array[mq_index] == NULL) {
pr_debug("handle_mq: stray activity for mq_index=%d\n",
mq_index);
return;
}
switch (mq_index) {
case (0):
wake_up(&c2dev->req_vq_wo);
break;
case (1):
handle_vq(c2dev, mq_index);
break;
case (2):
handle_vq(c2dev, 1);
c2_ae_event(c2dev, mq_index);
break;
default:
c2_cq_event(c2dev, mq_index);
break;
}
return;
}
static void handle_vq(struct c2_dev *c2dev, u32 mq_index)
{
void *adapter_msg, *reply_msg;
struct c2wr_hdr *host_msg;
struct c2wr_hdr tmp;
struct c2_mq *reply_vq;
struct c2_vq_req *req;
struct iw_cm_event cm_event;
int err;
reply_vq = (struct c2_mq *) c2dev->qptr_array[mq_index];
adapter_msg = c2_mq_consume(reply_vq);
if (adapter_msg == NULL) {
return;
}
host_msg = vq_repbuf_alloc(c2dev);
if (!host_msg) {
pr_debug("handle_vq: no repbufs!\n");
host_msg = &tmp;
memcpy(host_msg, adapter_msg, sizeof(tmp));
reply_msg = NULL;
} else {
memcpy(host_msg, adapter_msg, reply_vq->msg_size);
reply_msg = host_msg;
}
c2_mq_free(reply_vq);
req = (struct c2_vq_req *) (unsigned long) host_msg->context;
if (req == NULL) {
if (reply_msg != NULL)
vq_repbuf_free(c2dev, host_msg);
pr_debug("handle_vq: UNEXPECTEDLY got NULL req\n");
return;
}
if (reply_msg)
err = c2_errno(reply_msg);
else
err = -ENOMEM;
if (!err) switch (req->event) {
case IW_CM_EVENT_ESTABLISHED:
c2_set_qp_state(req->qp,
C2_QP_STATE_RTS);
cm_event.ird = cm_event.ord = 128;
case IW_CM_EVENT_CLOSE:
cm_event.event = req->event;
cm_event.status = 0;
cm_event.local_addr = req->cm_id->local_addr;
cm_event.remote_addr = req->cm_id->remote_addr;
cm_event.private_data = NULL;
cm_event.private_data_len = 0;
req->cm_id->event_handler(req->cm_id, &cm_event);
break;
default:
break;
}
req->reply_msg = (u64) (unsigned long) (reply_msg);
atomic_set(&req->reply_ready, 1);
wake_up(&req->wait_object);
vq_req_put(c2dev, req);
}
