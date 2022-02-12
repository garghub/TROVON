static irqreturn_t wake_waiting(int irq, void *unused)
{
if (unlikely(xenstored_ready == 0)) {
xenstored_ready = 1;
schedule_work(&probe_work);
}
wake_up(&xb_waitq);
return IRQ_HANDLED;
}
static int check_indexes(XENSTORE_RING_IDX cons, XENSTORE_RING_IDX prod)
{
return ((prod - cons) <= XENSTORE_RING_SIZE);
}
static void *get_output_chunk(XENSTORE_RING_IDX cons,
XENSTORE_RING_IDX prod,
char *buf, uint32_t *len)
{
*len = XENSTORE_RING_SIZE - MASK_XENSTORE_IDX(prod);
if ((XENSTORE_RING_SIZE - (prod - cons)) < *len)
*len = XENSTORE_RING_SIZE - (prod - cons);
return buf + MASK_XENSTORE_IDX(prod);
}
static const void *get_input_chunk(XENSTORE_RING_IDX cons,
XENSTORE_RING_IDX prod,
const char *buf, uint32_t *len)
{
*len = XENSTORE_RING_SIZE - MASK_XENSTORE_IDX(cons);
if ((prod - cons) < *len)
*len = prod - cons;
return buf + MASK_XENSTORE_IDX(cons);
}
static int xb_data_to_write(void)
{
struct xenstore_domain_interface *intf = xen_store_interface;
return (intf->req_prod - intf->req_cons) != XENSTORE_RING_SIZE &&
!list_empty(&xb_write_list);
}
static int xb_write(const void *data, unsigned int len)
{
struct xenstore_domain_interface *intf = xen_store_interface;
XENSTORE_RING_IDX cons, prod;
unsigned int bytes = 0;
while (len != 0) {
void *dst;
unsigned int avail;
cons = intf->req_cons;
prod = intf->req_prod;
if (!check_indexes(cons, prod)) {
intf->req_cons = intf->req_prod = 0;
return -EIO;
}
if (!xb_data_to_write())
return bytes;
virt_mb();
dst = get_output_chunk(cons, prod, intf->req, &avail);
if (avail == 0)
continue;
if (avail > len)
avail = len;
memcpy(dst, data, avail);
data += avail;
len -= avail;
bytes += avail;
virt_wmb();
intf->req_prod += avail;
if (prod <= intf->req_cons)
notify_remote_via_evtchn(xen_store_evtchn);
}
return bytes;
}
static int xb_data_to_read(void)
{
struct xenstore_domain_interface *intf = xen_store_interface;
return (intf->rsp_cons != intf->rsp_prod);
}
static int xb_read(void *data, unsigned int len)
{
struct xenstore_domain_interface *intf = xen_store_interface;
XENSTORE_RING_IDX cons, prod;
unsigned int bytes = 0;
while (len != 0) {
unsigned int avail;
const char *src;
cons = intf->rsp_cons;
prod = intf->rsp_prod;
if (cons == prod)
return bytes;
if (!check_indexes(cons, prod)) {
intf->rsp_cons = intf->rsp_prod = 0;
return -EIO;
}
src = get_input_chunk(cons, prod, intf->rsp, &avail);
if (avail == 0)
continue;
if (avail > len)
avail = len;
virt_rmb();
memcpy(data, src, avail);
data += avail;
len -= avail;
bytes += avail;
virt_mb();
intf->rsp_cons += avail;
if (intf->rsp_prod - cons >= XENSTORE_RING_SIZE)
notify_remote_via_evtchn(xen_store_evtchn);
}
return bytes;
}
static int process_msg(void)
{
static struct {
struct xsd_sockmsg msg;
char *body;
union {
void *alloc;
struct xs_watch_event *watch;
};
bool in_msg;
bool in_hdr;
unsigned int read;
} state;
struct xb_req_data *req;
int err;
unsigned int len;
if (!state.in_msg) {
state.in_msg = true;
state.in_hdr = true;
state.read = 0;
mutex_lock(&xs_response_mutex);
if (!xb_data_to_read()) {
mutex_unlock(&xs_response_mutex);
state.in_msg = false;
return 0;
}
}
if (state.in_hdr) {
if (state.read != sizeof(state.msg)) {
err = xb_read((void *)&state.msg + state.read,
sizeof(state.msg) - state.read);
if (err < 0)
goto out;
state.read += err;
if (state.read != sizeof(state.msg))
return 0;
if (state.msg.len > XENSTORE_PAYLOAD_MAX) {
err = -EINVAL;
goto out;
}
}
len = state.msg.len + 1;
if (state.msg.type == XS_WATCH_EVENT)
len += sizeof(*state.watch);
state.alloc = kmalloc(len, GFP_NOIO | __GFP_HIGH);
if (!state.alloc)
return -ENOMEM;
if (state.msg.type == XS_WATCH_EVENT)
state.body = state.watch->body;
else
state.body = state.alloc;
state.in_hdr = false;
state.read = 0;
}
err = xb_read(state.body + state.read, state.msg.len - state.read);
if (err < 0)
goto out;
state.read += err;
if (state.read != state.msg.len)
return 0;
state.body[state.msg.len] = '\0';
if (state.msg.type == XS_WATCH_EVENT) {
state.watch->len = state.msg.len;
err = xs_watch_msg(state.watch);
} else {
err = -ENOENT;
mutex_lock(&xb_write_mutex);
list_for_each_entry(req, &xs_reply_list, list) {
if (req->msg.req_id == state.msg.req_id) {
if (req->state == xb_req_state_wait_reply) {
req->msg.type = state.msg.type;
req->msg.len = state.msg.len;
req->body = state.body;
req->state = xb_req_state_got_reply;
list_del(&req->list);
req->cb(req);
} else {
list_del(&req->list);
kfree(req);
}
err = 0;
break;
}
}
mutex_unlock(&xb_write_mutex);
if (err)
goto out;
}
mutex_unlock(&xs_response_mutex);
state.in_msg = false;
state.alloc = NULL;
return err;
out:
mutex_unlock(&xs_response_mutex);
state.in_msg = false;
kfree(state.alloc);
state.alloc = NULL;
return err;
}
static int process_writes(void)
{
static struct {
struct xb_req_data *req;
int idx;
unsigned int written;
} state;
void *base;
unsigned int len;
int err = 0;
if (!xb_data_to_write())
return 0;
mutex_lock(&xb_write_mutex);
if (!state.req) {
state.req = list_first_entry(&xb_write_list,
struct xb_req_data, list);
state.idx = -1;
state.written = 0;
}
if (state.req->state == xb_req_state_aborted)
goto out_err;
while (state.idx < state.req->num_vecs) {
if (state.idx < 0) {
base = &state.req->msg;
len = sizeof(state.req->msg);
} else {
base = state.req->vec[state.idx].iov_base;
len = state.req->vec[state.idx].iov_len;
}
err = xb_write(base + state.written, len - state.written);
if (err < 0)
goto out_err;
state.written += err;
if (state.written != len)
goto out;
state.idx++;
state.written = 0;
}
list_del(&state.req->list);
state.req->state = xb_req_state_wait_reply;
list_add_tail(&state.req->list, &xs_reply_list);
state.req = NULL;
out:
mutex_unlock(&xb_write_mutex);
return 0;
out_err:
state.req->msg.type = XS_ERROR;
state.req->err = err;
list_del(&state.req->list);
if (state.req->state == xb_req_state_aborted)
kfree(state.req);
else {
state.req->state = xb_req_state_got_reply;
wake_up(&state.req->wq);
}
mutex_unlock(&xb_write_mutex);
state.req = NULL;
return err;
}
static int xb_thread_work(void)
{
return xb_data_to_read() || xb_data_to_write();
}
static int xenbus_thread(void *unused)
{
int err;
while (!kthread_should_stop()) {
if (wait_event_interruptible(xb_waitq, xb_thread_work()))
continue;
err = process_msg();
if (err == -ENOMEM)
schedule();
else if (err)
pr_warn_ratelimited("error %d while reading message\n",
err);
err = process_writes();
if (err)
pr_warn_ratelimited("error %d while writing message\n",
err);
}
xenbus_task = NULL;
return 0;
}
int xb_init_comms(void)
{
struct xenstore_domain_interface *intf = xen_store_interface;
if (intf->req_prod != intf->req_cons)
pr_err("request ring is not quiescent (%08x:%08x)!\n",
intf->req_cons, intf->req_prod);
if (intf->rsp_prod != intf->rsp_cons) {
pr_warn("response ring is not quiescent (%08x:%08x): fixing up\n",
intf->rsp_cons, intf->rsp_prod);
if (!reset_devices)
intf->rsp_cons = intf->rsp_prod;
}
if (xenbus_irq) {
rebind_evtchn_irq(xen_store_evtchn, xenbus_irq);
} else {
int err;
err = bind_evtchn_to_irqhandler(xen_store_evtchn, wake_waiting,
0, "xenbus", &xb_waitq);
if (err < 0) {
pr_err("request irq failed %i\n", err);
return err;
}
xenbus_irq = err;
if (!xenbus_task) {
xenbus_task = kthread_run(xenbus_thread, NULL,
"xenbus");
if (IS_ERR(xenbus_task))
return PTR_ERR(xenbus_task);
}
}
return 0;
}
void xb_deinit_comms(void)
{
unbind_from_irqhandler(xenbus_irq, &xb_waitq);
xenbus_irq = 0;
}
