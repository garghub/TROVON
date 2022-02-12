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
int xb_write(const void *data, unsigned len)
{
struct xenstore_domain_interface *intf = xen_store_interface;
XENSTORE_RING_IDX cons, prod;
int rc;
while (len != 0) {
void *dst;
unsigned int avail;
rc = wait_event_interruptible(
xb_waitq,
(intf->req_prod - intf->req_cons) !=
XENSTORE_RING_SIZE);
if (rc < 0)
return rc;
cons = intf->req_cons;
prod = intf->req_prod;
if (!check_indexes(cons, prod)) {
intf->req_cons = intf->req_prod = 0;
return -EIO;
}
dst = get_output_chunk(cons, prod, intf->req, &avail);
if (avail == 0)
continue;
if (avail > len)
avail = len;
virt_mb();
memcpy(dst, data, avail);
data += avail;
len -= avail;
virt_wmb();
intf->req_prod += avail;
notify_remote_via_evtchn(xen_store_evtchn);
}
return 0;
}
int xb_data_to_read(void)
{
struct xenstore_domain_interface *intf = xen_store_interface;
return (intf->rsp_cons != intf->rsp_prod);
}
int xb_wait_for_data_to_read(void)
{
return wait_event_interruptible(xb_waitq, xb_data_to_read());
}
int xb_read(void *data, unsigned len)
{
struct xenstore_domain_interface *intf = xen_store_interface;
XENSTORE_RING_IDX cons, prod;
int rc;
while (len != 0) {
unsigned int avail;
const char *src;
rc = xb_wait_for_data_to_read();
if (rc < 0)
return rc;
cons = intf->rsp_cons;
prod = intf->rsp_prod;
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
virt_mb();
intf->rsp_cons += avail;
pr_debug("Finished read of %i bytes (%i to go)\n", avail, len);
notify_remote_via_evtchn(xen_store_evtchn);
}
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
}
return 0;
}
void xb_deinit_comms(void)
{
unbind_from_irqhandler(xenbus_irq, &xb_waitq);
xenbus_irq = 0;
}
