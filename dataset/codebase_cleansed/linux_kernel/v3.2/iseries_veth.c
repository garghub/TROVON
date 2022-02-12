static inline void veth_stack_push(struct veth_lpar_connection *cnx,
struct veth_msg *msg)
{
msg->next = cnx->msg_stack_head;
cnx->msg_stack_head = msg;
}
static inline struct veth_msg *veth_stack_pop(struct veth_lpar_connection *cnx)
{
struct veth_msg *msg;
msg = cnx->msg_stack_head;
if (msg)
cnx->msg_stack_head = cnx->msg_stack_head->next;
return msg;
}
static inline int veth_stack_is_empty(struct veth_lpar_connection *cnx)
{
return cnx->msg_stack_head == NULL;
}
static inline HvLpEvent_Rc
veth_signalevent(struct veth_lpar_connection *cnx, u16 subtype,
HvLpEvent_AckInd ackind, HvLpEvent_AckType acktype,
u64 token,
u64 data1, u64 data2, u64 data3, u64 data4, u64 data5)
{
return HvCallEvent_signalLpEventFast(cnx->remote_lp,
HvLpEvent_Type_VirtualLan,
subtype, ackind, acktype,
cnx->src_inst,
cnx->dst_inst,
token, data1, data2, data3,
data4, data5);
}
static inline HvLpEvent_Rc veth_signaldata(struct veth_lpar_connection *cnx,
u16 subtype, u64 token, void *data)
{
u64 *p = (u64 *) data;
return veth_signalevent(cnx, subtype, HvLpEvent_AckInd_NoAck,
HvLpEvent_AckType_ImmediateAck,
token, p[0], p[1], p[2], p[3], p[4]);
}
static void veth_complete_allocation(void *parm, int number)
{
struct veth_allocation *vc = (struct veth_allocation *)parm;
vc->num = number;
complete(&vc->c);
}
static int veth_allocate_events(HvLpIndex rlp, int number)
{
struct veth_allocation vc =
{ COMPLETION_INITIALIZER_ONSTACK(vc.c), 0 };
mf_allocate_lp_events(rlp, HvLpEvent_Type_VirtualLan,
sizeof(struct veth_lpevent), number,
&veth_complete_allocation, &vc);
wait_for_completion(&vc.c);
return vc.num;
}
static ssize_t veth_cnx_attribute_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct veth_cnx_attribute *cnx_attr;
struct veth_lpar_connection *cnx;
cnx_attr = container_of(attr, struct veth_cnx_attribute, attr);
cnx = container_of(kobj, struct veth_lpar_connection, kobject);
if (!cnx_attr->show)
return -EIO;
return cnx_attr->show(cnx, buf);
}
static ssize_t veth_port_attribute_show(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct veth_port_attribute *port_attr;
struct veth_port *port;
port_attr = container_of(attr, struct veth_port_attribute, attr);
port = container_of(kobj, struct veth_port, kobject);
if (!port_attr->show)
return -EIO;
return port_attr->show(port, buf);
}
static inline void veth_kick_statemachine(struct veth_lpar_connection *cnx)
{
schedule_delayed_work(&cnx->statemachine_wq, 0);
}
static void veth_take_cap(struct veth_lpar_connection *cnx,
struct veth_lpevent *event)
{
unsigned long flags;
spin_lock_irqsave(&cnx->lock, flags);
cnx->dst_inst =
HvCallEvent_getTargetLpInstanceId(cnx->remote_lp,
HvLpEvent_Type_VirtualLan);
if (cnx->state & VETH_STATE_GOTCAPS) {
veth_error("Received a second capabilities from LPAR %d.\n",
cnx->remote_lp);
event->base_event.xRc = HvLpEvent_Rc_BufferNotAvailable;
HvCallEvent_ackLpEvent((struct HvLpEvent *) event);
} else {
memcpy(&cnx->cap_event, event, sizeof(cnx->cap_event));
cnx->state |= VETH_STATE_GOTCAPS;
veth_kick_statemachine(cnx);
}
spin_unlock_irqrestore(&cnx->lock, flags);
}
static void veth_take_cap_ack(struct veth_lpar_connection *cnx,
struct veth_lpevent *event)
{
unsigned long flags;
spin_lock_irqsave(&cnx->lock, flags);
if (cnx->state & VETH_STATE_GOTCAPACK) {
veth_error("Received a second capabilities ack from LPAR %d.\n",
cnx->remote_lp);
} else {
memcpy(&cnx->cap_ack_event, event,
sizeof(cnx->cap_ack_event));
cnx->state |= VETH_STATE_GOTCAPACK;
veth_kick_statemachine(cnx);
}
spin_unlock_irqrestore(&cnx->lock, flags);
}
static void veth_take_monitor_ack(struct veth_lpar_connection *cnx,
struct veth_lpevent *event)
{
unsigned long flags;
spin_lock_irqsave(&cnx->lock, flags);
veth_debug("cnx %d: lost connection.\n", cnx->remote_lp);
if (! (cnx->state & VETH_STATE_SHUTDOWN)) {
cnx->state |= VETH_STATE_RESET;
veth_kick_statemachine(cnx);
}
spin_unlock_irqrestore(&cnx->lock, flags);
}
static void veth_handle_ack(struct veth_lpevent *event)
{
HvLpIndex rlp = event->base_event.xTargetLp;
struct veth_lpar_connection *cnx = veth_cnx[rlp];
BUG_ON(! cnx);
switch (event->base_event.xSubtype) {
case VETH_EVENT_CAP:
veth_take_cap_ack(cnx, event);
break;
case VETH_EVENT_MONITOR:
veth_take_monitor_ack(cnx, event);
break;
default:
veth_error("Unknown ack type %d from LPAR %d.\n",
event->base_event.xSubtype, rlp);
}
}
static void veth_handle_int(struct veth_lpevent *event)
{
HvLpIndex rlp = event->base_event.xSourceLp;
struct veth_lpar_connection *cnx = veth_cnx[rlp];
unsigned long flags;
int i, acked = 0;
BUG_ON(! cnx);
switch (event->base_event.xSubtype) {
case VETH_EVENT_CAP:
veth_take_cap(cnx, event);
break;
case VETH_EVENT_MONITOR:
break;
case VETH_EVENT_FRAMES_ACK:
spin_lock_irqsave(&cnx->lock, flags);
for (i = 0; i < VETH_MAX_ACKS_PER_MSG; ++i) {
u16 msgnum = event->u.frames_ack_data.token[i];
if (msgnum < VETH_NUMBUFFERS) {
veth_recycle_msg(cnx, cnx->msgs + msgnum);
cnx->outstanding_tx--;
acked++;
}
}
if (acked > 0) {
cnx->last_contact = jiffies;
veth_wake_queues(cnx);
}
spin_unlock_irqrestore(&cnx->lock, flags);
break;
case VETH_EVENT_FRAMES:
veth_receive(cnx, event);
break;
default:
veth_error("Unknown interrupt type %d from LPAR %d.\n",
event->base_event.xSubtype, rlp);
}
}
static void veth_handle_event(struct HvLpEvent *event)
{
struct veth_lpevent *veth_event = (struct veth_lpevent *)event;
if (hvlpevent_is_ack(event))
veth_handle_ack(veth_event);
else
veth_handle_int(veth_event);
}
static int veth_process_caps(struct veth_lpar_connection *cnx)
{
struct veth_cap_data *remote_caps = &cnx->remote_caps;
int num_acks_needed;
cnx->ack_timeout = remote_caps->ack_timeout * HZ / 1000000;
if ( (remote_caps->num_buffers == 0) ||
(remote_caps->ack_threshold > VETH_MAX_ACKS_PER_MSG) ||
(remote_caps->ack_threshold == 0) ||
(cnx->ack_timeout == 0) ) {
veth_error("Received incompatible capabilities from LPAR %d.\n",
cnx->remote_lp);
return HvLpEvent_Rc_InvalidSubtypeData;
}
num_acks_needed = (remote_caps->num_buffers
/ remote_caps->ack_threshold) + 1;
if (cnx->num_ack_events < num_acks_needed) {
int num;
num = veth_allocate_events(cnx->remote_lp,
num_acks_needed-cnx->num_ack_events);
if (num > 0)
cnx->num_ack_events += num;
if (cnx->num_ack_events < num_acks_needed) {
veth_error("Couldn't allocate enough ack events "
"for LPAR %d.\n", cnx->remote_lp);
return HvLpEvent_Rc_BufferNotAvailable;
}
}
return HvLpEvent_Rc_Good;
}
static void veth_statemachine(struct work_struct *work)
{
struct veth_lpar_connection *cnx =
container_of(work, struct veth_lpar_connection,
statemachine_wq.work);
int rlp = cnx->remote_lp;
int rc;
spin_lock_irq(&cnx->lock);
restart:
if (cnx->state & VETH_STATE_RESET) {
if (cnx->state & VETH_STATE_OPEN)
HvCallEvent_closeLpEventPath(cnx->remote_lp,
HvLpEvent_Type_VirtualLan);
memset(&cnx->pending_acks, 0xff, sizeof (cnx->pending_acks));
cnx->num_pending_acks = 0;
cnx->state &= ~(VETH_STATE_RESET | VETH_STATE_SENTMON
| VETH_STATE_OPEN | VETH_STATE_SENTCAPS
| VETH_STATE_GOTCAPACK | VETH_STATE_GOTCAPS
| VETH_STATE_SENTCAPACK | VETH_STATE_READY);
if (cnx->msgs) {
int i;
for (i = 0; i < VETH_NUMBUFFERS; ++i)
veth_recycle_msg(cnx, cnx->msgs + i);
}
cnx->outstanding_tx = 0;
veth_wake_queues(cnx);
spin_unlock_irq(&cnx->lock);
del_timer_sync(&cnx->ack_timer);
del_timer_sync(&cnx->reset_timer);
spin_lock_irq(&cnx->lock);
if (cnx->state & VETH_STATE_RESET)
goto restart;
if (! (cnx->state & VETH_STATE_SHUTDOWN)) {
schedule_delayed_work(&cnx->statemachine_wq, 5 * HZ);
goto out;
}
}
if (cnx->state & VETH_STATE_SHUTDOWN)
goto out;
if ( !(cnx->state & VETH_STATE_OPEN) ) {
if (! cnx->msgs || (cnx->num_events < (2 + VETH_NUMBUFFERS)) )
goto cant_cope;
HvCallEvent_openLpEventPath(rlp, HvLpEvent_Type_VirtualLan);
cnx->src_inst =
HvCallEvent_getSourceLpInstanceId(rlp,
HvLpEvent_Type_VirtualLan);
cnx->dst_inst =
HvCallEvent_getTargetLpInstanceId(rlp,
HvLpEvent_Type_VirtualLan);
cnx->state |= VETH_STATE_OPEN;
}
if ( (cnx->state & VETH_STATE_OPEN) &&
!(cnx->state & VETH_STATE_SENTMON) ) {
rc = veth_signalevent(cnx, VETH_EVENT_MONITOR,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_DeferredAck,
0, 0, 0, 0, 0, 0);
if (rc == HvLpEvent_Rc_Good) {
cnx->state |= VETH_STATE_SENTMON;
} else {
if ( (rc != HvLpEvent_Rc_PartitionDead) &&
(rc != HvLpEvent_Rc_PathClosed) )
veth_error("Error sending monitor to LPAR %d, "
"rc = %d\n", rlp, rc);
goto out;
}
}
if ( (cnx->state & VETH_STATE_OPEN) &&
!(cnx->state & VETH_STATE_SENTCAPS)) {
u64 *rawcap = (u64 *)&cnx->local_caps;
rc = veth_signalevent(cnx, VETH_EVENT_CAP,
HvLpEvent_AckInd_DoAck,
HvLpEvent_AckType_ImmediateAck,
0, rawcap[0], rawcap[1], rawcap[2],
rawcap[3], rawcap[4]);
if (rc == HvLpEvent_Rc_Good) {
cnx->state |= VETH_STATE_SENTCAPS;
} else {
if ( (rc != HvLpEvent_Rc_PartitionDead) &&
(rc != HvLpEvent_Rc_PathClosed) )
veth_error("Error sending caps to LPAR %d, "
"rc = %d\n", rlp, rc);
goto out;
}
}
if ((cnx->state & VETH_STATE_GOTCAPS) &&
!(cnx->state & VETH_STATE_SENTCAPACK)) {
struct veth_cap_data *remote_caps = &cnx->remote_caps;
memcpy(remote_caps, &cnx->cap_event.u.caps_data,
sizeof(*remote_caps));
spin_unlock_irq(&cnx->lock);
rc = veth_process_caps(cnx);
spin_lock_irq(&cnx->lock);
if (cnx->state & (VETH_STATE_RESET|VETH_STATE_SHUTDOWN))
goto restart;
cnx->cap_event.base_event.xRc = rc;
HvCallEvent_ackLpEvent((struct HvLpEvent *)&cnx->cap_event);
if (rc == HvLpEvent_Rc_Good)
cnx->state |= VETH_STATE_SENTCAPACK;
else
goto cant_cope;
}
if ((cnx->state & VETH_STATE_GOTCAPACK) &&
(cnx->state & VETH_STATE_GOTCAPS) &&
!(cnx->state & VETH_STATE_READY)) {
if (cnx->cap_ack_event.base_event.xRc == HvLpEvent_Rc_Good) {
cnx->ack_timer.expires = jiffies + cnx->ack_timeout;
add_timer(&cnx->ack_timer);
cnx->state |= VETH_STATE_READY;
} else {
veth_error("Caps rejected by LPAR %d, rc = %d\n",
rlp, cnx->cap_ack_event.base_event.xRc);
goto cant_cope;
}
}
out:
spin_unlock_irq(&cnx->lock);
return;
cant_cope:
veth_error("Unrecoverable error on connection to LPAR %d, shutting down"
" (state = 0x%04lx)\n", rlp, cnx->state);
cnx->state |= VETH_STATE_SHUTDOWN;
spin_unlock_irq(&cnx->lock);
}
static int veth_init_connection(u8 rlp)
{
struct veth_lpar_connection *cnx;
struct veth_msg *msgs;
int i;
if ( (rlp == this_lp) ||
! HvLpConfig_doLpsCommunicateOnVirtualLan(this_lp, rlp) )
return 0;
cnx = kzalloc(sizeof(*cnx), GFP_KERNEL);
if (! cnx)
return -ENOMEM;
cnx->remote_lp = rlp;
spin_lock_init(&cnx->lock);
INIT_DELAYED_WORK(&cnx->statemachine_wq, veth_statemachine);
init_timer(&cnx->ack_timer);
cnx->ack_timer.function = veth_timed_ack;
cnx->ack_timer.data = (unsigned long) cnx;
init_timer(&cnx->reset_timer);
cnx->reset_timer.function = veth_timed_reset;
cnx->reset_timer.data = (unsigned long) cnx;
cnx->reset_timeout = 5 * HZ * (VETH_ACKTIMEOUT / 1000000);
memset(&cnx->pending_acks, 0xff, sizeof (cnx->pending_acks));
veth_cnx[rlp] = cnx;
kobject_init(&cnx->kobject, &veth_lpar_connection_ktype);
msgs = kcalloc(VETH_NUMBUFFERS, sizeof(struct veth_msg), GFP_KERNEL);
if (! msgs) {
veth_error("Can't allocate buffers for LPAR %d.\n", rlp);
return -ENOMEM;
}
cnx->msgs = msgs;
for (i = 0; i < VETH_NUMBUFFERS; i++) {
msgs[i].token = i;
veth_stack_push(cnx, msgs + i);
}
cnx->num_events = veth_allocate_events(rlp, 2 + VETH_NUMBUFFERS);
if (cnx->num_events < (2 + VETH_NUMBUFFERS)) {
veth_error("Can't allocate enough events for LPAR %d.\n", rlp);
return -ENOMEM;
}
cnx->local_caps.num_buffers = VETH_NUMBUFFERS;
cnx->local_caps.ack_threshold = ACK_THRESHOLD;
cnx->local_caps.ack_timeout = VETH_ACKTIMEOUT;
return 0;
}
static void veth_stop_connection(struct veth_lpar_connection *cnx)
{
if (!cnx)
return;
spin_lock_irq(&cnx->lock);
cnx->state |= VETH_STATE_RESET | VETH_STATE_SHUTDOWN;
veth_kick_statemachine(cnx);
spin_unlock_irq(&cnx->lock);
flush_delayed_work_sync(&cnx->statemachine_wq);
}
static void veth_destroy_connection(struct veth_lpar_connection *cnx)
{
if (!cnx)
return;
if (cnx->num_events > 0)
mf_deallocate_lp_events(cnx->remote_lp,
HvLpEvent_Type_VirtualLan,
cnx->num_events,
NULL, NULL);
if (cnx->num_ack_events > 0)
mf_deallocate_lp_events(cnx->remote_lp,
HvLpEvent_Type_VirtualLan,
cnx->num_ack_events,
NULL, NULL);
kfree(cnx->msgs);
veth_cnx[cnx->remote_lp] = NULL;
kfree(cnx);
}
static void veth_release_connection(struct kobject *kobj)
{
struct veth_lpar_connection *cnx;
cnx = container_of(kobj, struct veth_lpar_connection, kobject);
veth_stop_connection(cnx);
veth_destroy_connection(cnx);
}
static int veth_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int veth_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static int veth_change_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > VETH_MAX_MTU))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void veth_set_multicast_list(struct net_device *dev)
{
struct veth_port *port = netdev_priv(dev);
unsigned long flags;
write_lock_irqsave(&port->mcast_gate, flags);
if ((dev->flags & IFF_PROMISC) || (dev->flags & IFF_ALLMULTI) ||
(netdev_mc_count(dev) > VETH_MAX_MCAST)) {
port->promiscuous = 1;
} else {
struct netdev_hw_addr *ha;
port->promiscuous = 0;
port->num_mcast = 0;
netdev_for_each_mc_addr(ha, dev) {
u8 *addr = ha->addr;
u64 xaddr = 0;
memcpy(&xaddr, addr, ETH_ALEN);
port->mcast_addr[port->num_mcast] = xaddr;
port->num_mcast++;
}
}
write_unlock_irqrestore(&port->mcast_gate, flags);
}
static void veth_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strncpy(info->driver, DRV_NAME, sizeof(info->driver) - 1);
info->driver[sizeof(info->driver) - 1] = '\0';
strncpy(info->version, DRV_VERSION, sizeof(info->version) - 1);
info->version[sizeof(info->version) - 1] = '\0';
}
static int veth_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
ecmd->supported = (SUPPORTED_1000baseT_Full
| SUPPORTED_Autoneg | SUPPORTED_FIBRE);
ecmd->advertising = (SUPPORTED_1000baseT_Full
| SUPPORTED_Autoneg | SUPPORTED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->transceiver = XCVR_INTERNAL;
ecmd->phy_address = 0;
ecmd->speed = SPEED_1000;
ecmd->duplex = DUPLEX_FULL;
ecmd->autoneg = AUTONEG_ENABLE;
ecmd->maxtxpkt = 120;
ecmd->maxrxpkt = 120;
return 0;
}
static struct net_device *veth_probe_one(int vlan,
struct vio_dev *vio_dev)
{
struct net_device *dev;
struct veth_port *port;
struct device *vdev = &vio_dev->dev;
int i, rc;
const unsigned char *mac_addr;
mac_addr = vio_get_attribute(vio_dev, "local-mac-address", NULL);
if (mac_addr == NULL)
mac_addr = vio_get_attribute(vio_dev, "mac-address", NULL);
if (mac_addr == NULL) {
veth_error("Unable to fetch MAC address from device tree.\n");
return NULL;
}
dev = alloc_etherdev(sizeof (struct veth_port));
if (! dev) {
veth_error("Unable to allocate net_device structure!\n");
return NULL;
}
port = netdev_priv(dev);
spin_lock_init(&port->queue_lock);
rwlock_init(&port->mcast_gate);
port->stopped_map = 0;
for (i = 0; i < HVMAXARCHITECTEDLPS; i++) {
HvLpVirtualLanIndexMap map;
if (i == this_lp)
continue;
map = HvLpConfig_getVirtualLanIndexMapForLp(i);
if (map & (0x8000 >> vlan))
port->lpar_map |= (1 << i);
}
port->dev = vdev;
memcpy(dev->dev_addr, mac_addr, ETH_ALEN);
dev->mtu = VETH_MAX_MTU;
memcpy(&port->mac_addr, mac_addr, ETH_ALEN);
dev->netdev_ops = &veth_netdev_ops;
SET_ETHTOOL_OPS(dev, &ops);
SET_NETDEV_DEV(dev, vdev);
rc = register_netdev(dev);
if (rc != 0) {
veth_error("Failed registering net device for vlan%d.\n", vlan);
free_netdev(dev);
return NULL;
}
kobject_init(&port->kobject, &veth_port_ktype);
if (0 != kobject_add(&port->kobject, &dev->dev.kobj, "veth_port"))
veth_error("Failed adding port for %s to sysfs.\n", dev->name);
veth_info("%s attached to iSeries vlan %d (LPAR map = 0x%.4X)\n",
dev->name, vlan, port->lpar_map);
return dev;
}
static int veth_transmit_to_one(struct sk_buff *skb, HvLpIndex rlp,
struct net_device *dev)
{
struct veth_lpar_connection *cnx = veth_cnx[rlp];
struct veth_port *port = netdev_priv(dev);
HvLpEvent_Rc rc;
struct veth_msg *msg = NULL;
unsigned long flags;
if (! cnx)
return 0;
spin_lock_irqsave(&cnx->lock, flags);
if (! (cnx->state & VETH_STATE_READY))
goto no_error;
if ((skb->len - ETH_HLEN) > VETH_MAX_MTU)
goto drop;
msg = veth_stack_pop(cnx);
if (! msg)
goto drop;
msg->in_use = 1;
msg->skb = skb_get(skb);
msg->data.addr[0] = dma_map_single(port->dev, skb->data,
skb->len, DMA_TO_DEVICE);
if (dma_mapping_error(port->dev, msg->data.addr[0]))
goto recycle_and_drop;
msg->dev = port->dev;
msg->data.len[0] = skb->len;
msg->data.eofmask = 1 << VETH_EOF_SHIFT;
rc = veth_signaldata(cnx, VETH_EVENT_FRAMES, msg->token, &msg->data);
if (rc != HvLpEvent_Rc_Good)
goto recycle_and_drop;
if (0 == cnx->outstanding_tx)
mod_timer(&cnx->reset_timer, jiffies + cnx->reset_timeout);
cnx->last_contact = jiffies;
cnx->outstanding_tx++;
if (veth_stack_is_empty(cnx))
veth_stop_queues(cnx);
no_error:
spin_unlock_irqrestore(&cnx->lock, flags);
return 0;
recycle_and_drop:
veth_recycle_msg(cnx, msg);
drop:
spin_unlock_irqrestore(&cnx->lock, flags);
return 1;
}
static void veth_transmit_to_many(struct sk_buff *skb,
HvLpIndexMap lpmask,
struct net_device *dev)
{
int i, success, error;
success = error = 0;
for (i = 0; i < HVMAXARCHITECTEDLPS; i++) {
if ((lpmask & (1 << i)) == 0)
continue;
if (veth_transmit_to_one(skb, i, dev))
error = 1;
else
success = 1;
}
if (error)
dev->stats.tx_errors++;
if (success) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
}
}
static int veth_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
unsigned char *frame = skb->data;
struct veth_port *port = netdev_priv(dev);
HvLpIndexMap lpmask;
if (is_unicast_ether_addr(frame)) {
HvLpIndex rlp = frame[5];
if ( ! ((1 << rlp) & port->lpar_map) ) {
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
lpmask = 1 << rlp;
} else {
lpmask = port->lpar_map;
}
veth_transmit_to_many(skb, lpmask, dev);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void veth_recycle_msg(struct veth_lpar_connection *cnx,
struct veth_msg *msg)
{
u32 dma_address, dma_length;
if (msg->in_use) {
msg->in_use = 0;
dma_address = msg->data.addr[0];
dma_length = msg->data.len[0];
if (!dma_mapping_error(msg->dev, dma_address))
dma_unmap_single(msg->dev, dma_address, dma_length,
DMA_TO_DEVICE);
if (msg->skb) {
dev_kfree_skb_any(msg->skb);
msg->skb = NULL;
}
memset(&msg->data, 0, sizeof(msg->data));
veth_stack_push(cnx, msg);
} else if (cnx->state & VETH_STATE_OPEN) {
veth_error("Non-pending frame (# %d) acked by LPAR %d.\n",
cnx->remote_lp, msg->token);
}
}
static void veth_wake_queues(struct veth_lpar_connection *cnx)
{
int i;
for (i = 0; i < HVMAXARCHITECTEDVIRTUALLANS; i++) {
struct net_device *dev = veth_dev[i];
struct veth_port *port;
unsigned long flags;
if (! dev)
continue;
port = netdev_priv(dev);
if (! (port->lpar_map & (1<<cnx->remote_lp)))
continue;
spin_lock_irqsave(&port->queue_lock, flags);
port->stopped_map &= ~(1 << cnx->remote_lp);
if (0 == port->stopped_map && netif_queue_stopped(dev)) {
veth_debug("cnx %d: woke queue for %s.\n",
cnx->remote_lp, dev->name);
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&port->queue_lock, flags);
}
}
static void veth_stop_queues(struct veth_lpar_connection *cnx)
{
int i;
for (i = 0; i < HVMAXARCHITECTEDVIRTUALLANS; i++) {
struct net_device *dev = veth_dev[i];
struct veth_port *port;
if (! dev)
continue;
port = netdev_priv(dev);
if (! (port->lpar_map & (1 << cnx->remote_lp)))
continue;
spin_lock(&port->queue_lock);
netif_stop_queue(dev);
port->stopped_map |= (1 << cnx->remote_lp);
veth_debug("cnx %d: stopped queue for %s, map = 0x%x.\n",
cnx->remote_lp, dev->name, port->stopped_map);
spin_unlock(&port->queue_lock);
}
}
static void veth_timed_reset(unsigned long ptr)
{
struct veth_lpar_connection *cnx = (struct veth_lpar_connection *)ptr;
unsigned long trigger_time, flags;
spin_lock_irqsave(&cnx->lock, flags);
if (cnx->outstanding_tx > 0) {
trigger_time = cnx->last_contact + cnx->reset_timeout;
if (trigger_time < jiffies) {
cnx->state |= VETH_STATE_RESET;
veth_kick_statemachine(cnx);
veth_error("%d packets not acked by LPAR %d within %d "
"seconds, resetting.\n",
cnx->outstanding_tx, cnx->remote_lp,
cnx->reset_timeout / HZ);
} else {
trigger_time = jiffies + cnx->reset_timeout;
mod_timer(&cnx->reset_timer, trigger_time);
}
}
spin_unlock_irqrestore(&cnx->lock, flags);
}
static inline int veth_frame_wanted(struct veth_port *port, u64 mac_addr)
{
int wanted = 0;
int i;
unsigned long flags;
if ( (mac_addr == port->mac_addr) || (mac_addr == 0xffffffffffff0000) )
return 1;
read_lock_irqsave(&port->mcast_gate, flags);
if (port->promiscuous) {
wanted = 1;
goto out;
}
for (i = 0; i < port->num_mcast; ++i) {
if (port->mcast_addr[i] == mac_addr) {
wanted = 1;
break;
}
}
out:
read_unlock_irqrestore(&port->mcast_gate, flags);
return wanted;
}
static inline void veth_build_dma_list(struct dma_chunk *list,
unsigned char *p, unsigned long length)
{
unsigned long done;
int i = 1;
list[0].addr = iseries_hv_addr(p);
list[0].size = min(length,
PAGE_SIZE - ((unsigned long)p & ~PAGE_MASK));
done = list[0].size;
while (done < length) {
list[i].addr = iseries_hv_addr(p + done);
list[i].size = min(length-done, PAGE_SIZE);
done += list[i].size;
i++;
}
}
static void veth_flush_acks(struct veth_lpar_connection *cnx)
{
HvLpEvent_Rc rc;
rc = veth_signaldata(cnx, VETH_EVENT_FRAMES_ACK,
0, &cnx->pending_acks);
if (rc != HvLpEvent_Rc_Good)
veth_error("Failed acking frames from LPAR %d, rc = %d\n",
cnx->remote_lp, (int)rc);
cnx->num_pending_acks = 0;
memset(&cnx->pending_acks, 0xff, sizeof(cnx->pending_acks));
}
static void veth_receive(struct veth_lpar_connection *cnx,
struct veth_lpevent *event)
{
struct veth_frames_data *senddata = &event->u.frames_data;
int startchunk = 0;
int nchunks;
unsigned long flags;
HvLpDma_Rc rc;
do {
u16 length = 0;
struct sk_buff *skb;
struct dma_chunk local_list[VETH_MAX_PAGES_PER_FRAME];
struct dma_chunk remote_list[VETH_MAX_FRAMES_PER_MSG];
u64 dest;
HvLpVirtualLanIndex vlan;
struct net_device *dev;
struct veth_port *port;
memset(local_list, 0, sizeof(local_list));
memset(remote_list, 0, sizeof(remote_list));
if (senddata->addr[startchunk] == 0)
break;
if (! (senddata->eofmask >> (startchunk + VETH_EOF_SHIFT))) {
veth_error("Missing EOF fragment in event "
"eofmask = 0x%x startchunk = %d\n",
(unsigned)senddata->eofmask,
startchunk);
break;
}
nchunks = 0;
do {
remote_list[nchunks].addr =
(u64) senddata->addr[startchunk+nchunks] << 32;
remote_list[nchunks].size =
senddata->len[startchunk+nchunks];
length += remote_list[nchunks].size;
} while (! (senddata->eofmask &
(1 << (VETH_EOF_SHIFT + startchunk + nchunks++))));
if ((length - ETH_HLEN) > VETH_MAX_MTU) {
veth_error("Received oversize frame from LPAR %d "
"(length = %d)\n",
cnx->remote_lp, length);
continue;
}
skb = alloc_skb(length, GFP_ATOMIC);
if (!skb)
continue;
veth_build_dma_list(local_list, skb->data, length);
rc = HvCallEvent_dmaBufList(HvLpEvent_Type_VirtualLan,
event->base_event.xSourceLp,
HvLpDma_Direction_RemoteToLocal,
cnx->src_inst,
cnx->dst_inst,
HvLpDma_AddressType_RealAddress,
HvLpDma_AddressType_TceIndex,
iseries_hv_addr(&local_list),
iseries_hv_addr(&remote_list),
length);
if (rc != HvLpDma_Rc_Good) {
dev_kfree_skb_irq(skb);
continue;
}
vlan = skb->data[9];
dev = veth_dev[vlan];
if (! dev) {
dev_kfree_skb_irq(skb);
continue;
}
port = netdev_priv(dev);
dest = *((u64 *) skb->data) & 0xFFFFFFFFFFFF0000;
if ((vlan > HVMAXARCHITECTEDVIRTUALLANS) || !port) {
dev_kfree_skb_irq(skb);
continue;
}
if (! veth_frame_wanted(port, dest)) {
dev_kfree_skb_irq(skb);
continue;
}
skb_put(skb, length);
skb->protocol = eth_type_trans(skb, dev);
skb_checksum_none_assert(skb);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += length;
} while (startchunk += nchunks, startchunk < VETH_MAX_FRAMES_PER_MSG);
spin_lock_irqsave(&cnx->lock, flags);
BUG_ON(cnx->num_pending_acks > VETH_MAX_ACKS_PER_MSG);
cnx->pending_acks[cnx->num_pending_acks++] =
event->base_event.xCorrelationToken;
if ( (cnx->num_pending_acks >= cnx->remote_caps.ack_threshold) ||
(cnx->num_pending_acks >= VETH_MAX_ACKS_PER_MSG) )
veth_flush_acks(cnx);
spin_unlock_irqrestore(&cnx->lock, flags);
}
static void veth_timed_ack(unsigned long ptr)
{
struct veth_lpar_connection *cnx = (struct veth_lpar_connection *) ptr;
unsigned long flags;
spin_lock_irqsave(&cnx->lock, flags);
if (cnx->num_pending_acks > 0)
veth_flush_acks(cnx);
cnx->ack_timer.expires = jiffies + cnx->ack_timeout;
add_timer(&cnx->ack_timer);
spin_unlock_irqrestore(&cnx->lock, flags);
}
static int veth_remove(struct vio_dev *vdev)
{
struct veth_lpar_connection *cnx;
struct net_device *dev;
struct veth_port *port;
int i;
dev = veth_dev[vdev->unit_address];
if (! dev)
return 0;
port = netdev_priv(dev);
for (i = 0; i < HVMAXARCHITECTEDLPS; i++) {
cnx = veth_cnx[i];
if (cnx && (port->lpar_map & (1 << i))) {
kobject_put(&cnx->kobject);
}
}
veth_dev[vdev->unit_address] = NULL;
kobject_del(&port->kobject);
kobject_put(&port->kobject);
unregister_netdev(dev);
free_netdev(dev);
return 0;
}
static int veth_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
int i = vdev->unit_address;
struct net_device *dev;
struct veth_port *port;
dev = veth_probe_one(i, vdev);
if (dev == NULL) {
veth_remove(vdev);
return 1;
}
veth_dev[i] = dev;
port = netdev_priv(dev);
for (i = 0; i < HVMAXARCHITECTEDLPS; i++) {
struct veth_lpar_connection *cnx;
if (! (port->lpar_map & (1 << i)))
continue;
cnx = veth_cnx[i];
if (!cnx)
continue;
kobject_get(&cnx->kobject);
veth_kick_statemachine(cnx);
}
return 0;
}
static void __exit veth_module_cleanup(void)
{
int i;
struct veth_lpar_connection *cnx;
HvLpEvent_unregisterHandler(HvLpEvent_Type_VirtualLan);
for (i = 0; i < HVMAXARCHITECTEDLPS; ++i) {
cnx = veth_cnx[i];
if (!cnx)
continue;
cancel_delayed_work_sync(&cnx->statemachine_wq);
kobject_del(&cnx->kobject);
kobject_put(&cnx->kobject);
}
vio_unregister_driver(&veth_driver);
}
static int __init veth_module_init(void)
{
int i;
int rc;
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return -ENODEV;
this_lp = HvLpConfig_getLpIndex_outline();
for (i = 0; i < HVMAXARCHITECTEDLPS; ++i) {
rc = veth_init_connection(i);
if (rc != 0)
goto error;
}
HvLpEvent_registerHandler(HvLpEvent_Type_VirtualLan,
&veth_handle_event);
rc = vio_register_driver(&veth_driver);
if (rc != 0)
goto error;
for (i = 0; i < HVMAXARCHITECTEDLPS; ++i) {
struct kobject *kobj;
if (!veth_cnx[i])
continue;
kobj = &veth_cnx[i]->kobject;
if (0 != driver_add_kobj(&veth_driver.driver, kobj,
"cnx%.2d", veth_cnx[i]->remote_lp))
veth_error("cnx %d: Failed adding to sysfs.\n", i);
}
return 0;
error:
for (i = 0; i < HVMAXARCHITECTEDLPS; ++i) {
veth_destroy_connection(veth_cnx[i]);
}
return rc;
}
