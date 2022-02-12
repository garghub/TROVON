static inline u32 vnet_tx_dring_avail(struct vio_dring_state *dr)
{
return vio_dring_avail(dr, VNET_TX_RING_SIZE);
}
static int vnet_handle_unknown(struct vnet_port *port, void *arg)
{
struct vio_msg_tag *pkt = arg;
pr_err("Received unknown msg [%02x:%02x:%04x:%08x]\n",
pkt->type, pkt->stype, pkt->stype_env, pkt->sid);
pr_err("Resetting connection\n");
ldc_disconnect(port->vio.lp);
return -ECONNRESET;
}
int sunvnet_send_attr_common(struct vio_driver_state *vio)
{
struct vnet_port *port = to_vnet_port(vio);
struct net_device *dev = VNET_PORT_TO_NET_DEVICE(port);
struct vio_net_attr_info pkt;
int framelen = ETH_FRAME_LEN;
int i, err;
err = vnet_port_alloc_tx_ring(to_vnet_port(vio));
if (err)
return err;
memset(&pkt, 0, sizeof(pkt));
pkt.tag.type = VIO_TYPE_CTRL;
pkt.tag.stype = VIO_SUBTYPE_INFO;
pkt.tag.stype_env = VIO_ATTR_INFO;
pkt.tag.sid = vio_send_sid(vio);
if (vio_version_before(vio, 1, 2))
pkt.xfer_mode = VIO_DRING_MODE;
else
pkt.xfer_mode = VIO_NEW_DRING_MODE;
pkt.addr_type = VNET_ADDR_ETHERMAC;
pkt.ack_freq = 0;
for (i = 0; i < 6; i++)
pkt.addr |= (u64)dev->dev_addr[i] << ((5 - i) * 8);
if (vio_version_after(vio, 1, 3)) {
if (port->rmtu) {
port->rmtu = min(VNET_MAXPACKET, port->rmtu);
pkt.mtu = port->rmtu;
} else {
port->rmtu = VNET_MAXPACKET;
pkt.mtu = port->rmtu;
}
if (vio_version_after_eq(vio, 1, 6))
pkt.options = VIO_TX_DRING;
} else if (vio_version_before(vio, 1, 3)) {
pkt.mtu = framelen;
} else {
pkt.mtu = framelen + VLAN_HLEN;
}
pkt.cflags = 0;
if (vio_version_after_eq(vio, 1, 7) && port->tso) {
pkt.cflags |= VNET_LSO_IPV4_CAPAB;
if (!port->tsolen)
port->tsolen = VNET_MAXTSO;
pkt.ipv4_lso_maxlen = port->tsolen;
}
pkt.plnk_updt = PHYSLINK_UPDATE_NONE;
viodbg(HS, "SEND NET ATTR xmode[0x%x] atype[0x%x] addr[%llx] "
"ackfreq[%u] plnk_updt[0x%02x] opts[0x%02x] mtu[%llu] "
"cflags[0x%04x] lso_max[%u]\n",
pkt.xfer_mode, pkt.addr_type,
(unsigned long long)pkt.addr,
pkt.ack_freq, pkt.plnk_updt, pkt.options,
(unsigned long long)pkt.mtu, pkt.cflags, pkt.ipv4_lso_maxlen);
return vio_ldc_send(vio, &pkt, sizeof(pkt));
}
static int handle_attr_info(struct vio_driver_state *vio,
struct vio_net_attr_info *pkt)
{
struct vnet_port *port = to_vnet_port(vio);
u64 localmtu;
u8 xfer_mode;
viodbg(HS, "GOT NET ATTR xmode[0x%x] atype[0x%x] addr[%llx] "
"ackfreq[%u] plnk_updt[0x%02x] opts[0x%02x] mtu[%llu] "
" (rmtu[%llu]) cflags[0x%04x] lso_max[%u]\n",
pkt->xfer_mode, pkt->addr_type,
(unsigned long long)pkt->addr,
pkt->ack_freq, pkt->plnk_updt, pkt->options,
(unsigned long long)pkt->mtu, port->rmtu, pkt->cflags,
pkt->ipv4_lso_maxlen);
pkt->tag.sid = vio_send_sid(vio);
xfer_mode = pkt->xfer_mode;
if (vio_version_before(vio, 1, 2) && xfer_mode == VIO_DRING_MODE)
xfer_mode = VIO_NEW_DRING_MODE;
if (vio_version_before(vio, 1, 3)) {
localmtu = ETH_FRAME_LEN;
} else if (vio_version_after(vio, 1, 3)) {
localmtu = port->rmtu ? port->rmtu : VNET_MAXPACKET;
localmtu = min(pkt->mtu, localmtu);
pkt->mtu = localmtu;
} else {
localmtu = ETH_FRAME_LEN + VLAN_HLEN;
}
port->rmtu = localmtu;
if (vio_version_after_eq(vio, 1, 7))
port->tso &= !!(pkt->cflags & VNET_LSO_IPV4_CAPAB);
else
port->tso = false;
if (port->tso) {
if (!port->tsolen)
port->tsolen = VNET_MAXTSO;
port->tsolen = min(port->tsolen, pkt->ipv4_lso_maxlen);
if (port->tsolen < VNET_MINTSO) {
port->tso = false;
port->tsolen = 0;
pkt->cflags &= ~VNET_LSO_IPV4_CAPAB;
}
pkt->ipv4_lso_maxlen = port->tsolen;
} else {
pkt->cflags &= ~VNET_LSO_IPV4_CAPAB;
pkt->ipv4_lso_maxlen = 0;
port->tsolen = 0;
}
if (vio_version_after_eq(vio, 1, 6)) {
pkt->xfer_mode = VIO_NEW_DRING_MODE;
pkt->options = VIO_TX_DRING;
}
if (!(xfer_mode | VIO_NEW_DRING_MODE) ||
pkt->addr_type != VNET_ADDR_ETHERMAC ||
pkt->mtu != localmtu) {
viodbg(HS, "SEND NET ATTR NACK\n");
pkt->tag.stype = VIO_SUBTYPE_NACK;
(void)vio_ldc_send(vio, pkt, sizeof(*pkt));
return -ECONNRESET;
}
viodbg(HS, "SEND NET ATTR ACK xmode[0x%x] atype[0x%x] "
"addr[%llx] ackfreq[%u] plnk_updt[0x%02x] opts[0x%02x] "
"mtu[%llu] (rmtu[%llu]) cflags[0x%04x] lso_max[%u]\n",
pkt->xfer_mode, pkt->addr_type,
(unsigned long long)pkt->addr,
pkt->ack_freq, pkt->plnk_updt, pkt->options,
(unsigned long long)pkt->mtu, port->rmtu, pkt->cflags,
pkt->ipv4_lso_maxlen);
pkt->tag.stype = VIO_SUBTYPE_ACK;
return vio_ldc_send(vio, pkt, sizeof(*pkt));
}
static int handle_attr_ack(struct vio_driver_state *vio,
struct vio_net_attr_info *pkt)
{
viodbg(HS, "GOT NET ATTR ACK\n");
return 0;
}
static int handle_attr_nack(struct vio_driver_state *vio,
struct vio_net_attr_info *pkt)
{
viodbg(HS, "GOT NET ATTR NACK\n");
return -ECONNRESET;
}
int sunvnet_handle_attr_common(struct vio_driver_state *vio, void *arg)
{
struct vio_net_attr_info *pkt = arg;
switch (pkt->tag.stype) {
case VIO_SUBTYPE_INFO:
return handle_attr_info(vio, pkt);
case VIO_SUBTYPE_ACK:
return handle_attr_ack(vio, pkt);
case VIO_SUBTYPE_NACK:
return handle_attr_nack(vio, pkt);
default:
return -ECONNRESET;
}
}
void sunvnet_handshake_complete_common(struct vio_driver_state *vio)
{
struct vio_dring_state *dr;
dr = &vio->drings[VIO_DRIVER_RX_RING];
dr->rcv_nxt = 1;
dr->snd_nxt = 1;
dr = &vio->drings[VIO_DRIVER_TX_RING];
dr->rcv_nxt = 1;
dr->snd_nxt = 1;
}
static struct sk_buff *alloc_and_align_skb(struct net_device *dev,
unsigned int len)
{
struct sk_buff *skb;
unsigned long addr, off;
skb = netdev_alloc_skb(dev, len + VNET_PACKET_SKIP + 8 + 8);
if (unlikely(!skb))
return NULL;
addr = (unsigned long)skb->data;
off = ((addr + 7UL) & ~7UL) - addr;
if (off)
skb_reserve(skb, off);
return skb;
}
static inline void vnet_fullcsum(struct sk_buff *skb)
{
struct iphdr *iph = ip_hdr(skb);
int offset = skb_transport_offset(skb);
if (skb->protocol != htons(ETH_P_IP))
return;
if (iph->protocol != IPPROTO_TCP &&
iph->protocol != IPPROTO_UDP)
return;
skb->ip_summed = CHECKSUM_NONE;
skb->csum_level = 1;
skb->csum = 0;
if (iph->protocol == IPPROTO_TCP) {
struct tcphdr *ptcp = tcp_hdr(skb);
ptcp->check = 0;
skb->csum = skb_checksum(skb, offset, skb->len - offset, 0);
ptcp->check = csum_tcpudp_magic(iph->saddr, iph->daddr,
skb->len - offset, IPPROTO_TCP,
skb->csum);
} else if (iph->protocol == IPPROTO_UDP) {
struct udphdr *pudp = udp_hdr(skb);
pudp->check = 0;
skb->csum = skb_checksum(skb, offset, skb->len - offset, 0);
pudp->check = csum_tcpudp_magic(iph->saddr, iph->daddr,
skb->len - offset, IPPROTO_UDP,
skb->csum);
}
}
static int vnet_rx_one(struct vnet_port *port, struct vio_net_desc *desc)
{
struct net_device *dev = VNET_PORT_TO_NET_DEVICE(port);
unsigned int len = desc->size;
unsigned int copy_len;
struct sk_buff *skb;
int maxlen;
int err;
err = -EMSGSIZE;
if (port->tso && port->tsolen > port->rmtu)
maxlen = port->tsolen;
else
maxlen = port->rmtu;
if (unlikely(len < ETH_ZLEN || len > maxlen)) {
dev->stats.rx_length_errors++;
goto out_dropped;
}
skb = alloc_and_align_skb(dev, len);
err = -ENOMEM;
if (unlikely(!skb)) {
dev->stats.rx_missed_errors++;
goto out_dropped;
}
copy_len = (len + VNET_PACKET_SKIP + 7U) & ~7U;
skb_put(skb, copy_len);
err = ldc_copy(port->vio.lp, LDC_COPY_IN,
skb->data, copy_len, 0,
desc->cookies, desc->ncookies);
if (unlikely(err < 0)) {
dev->stats.rx_frame_errors++;
goto out_free_skb;
}
skb_pull(skb, VNET_PACKET_SKIP);
skb_trim(skb, len);
skb->protocol = eth_type_trans(skb, dev);
if (vio_version_after_eq(&port->vio, 1, 8)) {
struct vio_net_dext *dext = vio_net_ext(desc);
skb_reset_network_header(skb);
if (dext->flags & VNET_PKT_HCK_IPV4_HDRCKSUM) {
if (skb->protocol == ETH_P_IP) {
struct iphdr *iph = ip_hdr(skb);
iph->check = 0;
ip_send_check(iph);
}
}
if ((dext->flags & VNET_PKT_HCK_FULLCKSUM) &&
skb->ip_summed == CHECKSUM_NONE) {
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
int ihl = iph->ihl * 4;
skb_reset_transport_header(skb);
skb_set_transport_header(skb, ihl);
vnet_fullcsum(skb);
}
}
if (dext->flags & VNET_PKT_HCK_IPV4_HDRCKSUM_OK) {
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_level = 0;
if (dext->flags & VNET_PKT_HCK_FULLCKSUM_OK)
skb->csum_level = 1;
}
}
skb->ip_summed = port->switch_port ? CHECKSUM_NONE : CHECKSUM_PARTIAL;
if (unlikely(is_multicast_ether_addr(eth_hdr(skb)->h_dest)))
dev->stats.multicast++;
dev->stats.rx_packets++;
dev->stats.rx_bytes += len;
port->stats.rx_packets++;
port->stats.rx_bytes += len;
napi_gro_receive(&port->napi, skb);
return 0;
out_free_skb:
kfree_skb(skb);
out_dropped:
dev->stats.rx_dropped++;
return err;
}
static int vnet_send_ack(struct vnet_port *port, struct vio_dring_state *dr,
u32 start, u32 end, u8 vio_dring_state)
{
struct vio_dring_data hdr = {
.tag = {
.type = VIO_TYPE_DATA,
.stype = VIO_SUBTYPE_ACK,
.stype_env = VIO_DRING_DATA,
.sid = vio_send_sid(&port->vio),
},
.dring_ident = dr->ident,
.start_idx = start,
.end_idx = end,
.state = vio_dring_state,
};
int err, delay;
int retries = 0;
hdr.seq = dr->snd_nxt;
delay = 1;
do {
err = vio_ldc_send(&port->vio, &hdr, sizeof(hdr));
if (err > 0) {
dr->snd_nxt++;
break;
}
udelay(delay);
if ((delay <<= 1) > 128)
delay = 128;
if (retries++ > VNET_MAX_RETRIES) {
pr_info("ECONNRESET %x:%x:%x:%x:%x:%x\n",
port->raddr[0], port->raddr[1],
port->raddr[2], port->raddr[3],
port->raddr[4], port->raddr[5]);
break;
}
} while (err == -EAGAIN);
if (err <= 0 && vio_dring_state == VIO_DRING_STOPPED) {
port->stop_rx_idx = end;
port->stop_rx = true;
} else {
port->stop_rx_idx = 0;
port->stop_rx = false;
}
return err;
}
static struct vio_net_desc *get_rx_desc(struct vnet_port *port,
struct vio_dring_state *dr,
u32 index)
{
struct vio_net_desc *desc = port->vio.desc_buf;
int err;
err = ldc_get_dring_entry(port->vio.lp, desc, dr->entry_size,
(index * dr->entry_size),
dr->cookies, dr->ncookies);
if (err < 0)
return ERR_PTR(err);
return desc;
}
static int put_rx_desc(struct vnet_port *port,
struct vio_dring_state *dr,
struct vio_net_desc *desc,
u32 index)
{
int err;
err = ldc_put_dring_entry(port->vio.lp, desc, dr->entry_size,
(index * dr->entry_size),
dr->cookies, dr->ncookies);
if (err < 0)
return err;
return 0;
}
static int vnet_walk_rx_one(struct vnet_port *port,
struct vio_dring_state *dr,
u32 index, int *needs_ack)
{
struct vio_net_desc *desc = get_rx_desc(port, dr, index);
struct vio_driver_state *vio = &port->vio;
int err;
BUG_ON(!desc);
if (IS_ERR(desc))
return PTR_ERR(desc);
if (desc->hdr.state != VIO_DESC_READY)
return 1;
dma_rmb();
viodbg(DATA, "vio_walk_rx_one desc[%02x:%02x:%08x:%08x:%llx:%llx]\n",
desc->hdr.state, desc->hdr.ack,
desc->size, desc->ncookies,
desc->cookies[0].cookie_addr,
desc->cookies[0].cookie_size);
err = vnet_rx_one(port, desc);
if (err == -ECONNRESET)
return err;
trace_vnet_rx_one(port->vio._local_sid, port->vio._peer_sid,
index, desc->hdr.ack);
desc->hdr.state = VIO_DESC_DONE;
err = put_rx_desc(port, dr, desc, index);
if (err < 0)
return err;
*needs_ack = desc->hdr.ack;
return 0;
}
static int vnet_walk_rx(struct vnet_port *port, struct vio_dring_state *dr,
u32 start, u32 end, int *npkts, int budget)
{
struct vio_driver_state *vio = &port->vio;
int ack_start = -1, ack_end = -1;
bool send_ack = true;
end = (end == (u32)-1) ? vio_dring_prev(dr, start)
: vio_dring_next(dr, end);
viodbg(DATA, "vnet_walk_rx start[%08x] end[%08x]\n", start, end);
while (start != end) {
int ack = 0, err = vnet_walk_rx_one(port, dr, start, &ack);
if (err == -ECONNRESET)
return err;
if (err != 0)
break;
(*npkts)++;
if (ack_start == -1)
ack_start = start;
ack_end = start;
start = vio_dring_next(dr, start);
if (ack && start != end) {
err = vnet_send_ack(port, dr, ack_start, ack_end,
VIO_DRING_ACTIVE);
if (err == -ECONNRESET)
return err;
ack_start = -1;
}
if ((*npkts) >= budget) {
send_ack = false;
break;
}
}
if (unlikely(ack_start == -1)) {
ack_end = vio_dring_prev(dr, start);
ack_start = ack_end;
}
if (send_ack) {
port->napi_resume = false;
trace_vnet_tx_send_stopped_ack(port->vio._local_sid,
port->vio._peer_sid,
ack_end, *npkts);
return vnet_send_ack(port, dr, ack_start, ack_end,
VIO_DRING_STOPPED);
} else {
trace_vnet_tx_defer_stopped_ack(port->vio._local_sid,
port->vio._peer_sid,
ack_end, *npkts);
port->napi_resume = true;
port->napi_stop_idx = ack_end;
return 1;
}
}
static int vnet_rx(struct vnet_port *port, void *msgbuf, int *npkts,
int budget)
{
struct vio_dring_data *pkt = msgbuf;
struct vio_dring_state *dr = &port->vio.drings[VIO_DRIVER_RX_RING];
struct vio_driver_state *vio = &port->vio;
viodbg(DATA, "vnet_rx stype_env[%04x] seq[%016llx] rcv_nxt[%016llx]\n",
pkt->tag.stype_env, pkt->seq, dr->rcv_nxt);
if (unlikely(pkt->tag.stype_env != VIO_DRING_DATA))
return 0;
if (unlikely(pkt->seq != dr->rcv_nxt)) {
pr_err("RX out of sequence seq[0x%llx] rcv_nxt[0x%llx]\n",
pkt->seq, dr->rcv_nxt);
return 0;
}
if (!port->napi_resume)
dr->rcv_nxt++;
return vnet_walk_rx(port, dr, pkt->start_idx, pkt->end_idx,
npkts, budget);
}
static int idx_is_pending(struct vio_dring_state *dr, u32 end)
{
u32 idx = dr->cons;
int found = 0;
while (idx != dr->prod) {
if (idx == end) {
found = 1;
break;
}
idx = vio_dring_next(dr, idx);
}
return found;
}
static int vnet_ack(struct vnet_port *port, void *msgbuf)
{
struct vio_dring_state *dr = &port->vio.drings[VIO_DRIVER_TX_RING];
struct vio_dring_data *pkt = msgbuf;
struct net_device *dev;
u32 end;
struct vio_net_desc *desc;
struct netdev_queue *txq;
if (unlikely(pkt->tag.stype_env != VIO_DRING_DATA))
return 0;
end = pkt->end_idx;
dev = VNET_PORT_TO_NET_DEVICE(port);
netif_tx_lock(dev);
if (unlikely(!idx_is_pending(dr, end))) {
netif_tx_unlock(dev);
return 0;
}
trace_vnet_rx_stopped_ack(port->vio._local_sid,
port->vio._peer_sid, end);
dr->cons = vio_dring_next(dr, end);
desc = vio_dring_entry(dr, dr->cons);
if (desc->hdr.state == VIO_DESC_READY && !port->start_cons) {
if (__vnet_tx_trigger(port, dr->cons) > 0)
port->start_cons = false;
else
port->start_cons = true;
} else {
port->start_cons = true;
}
netif_tx_unlock(dev);
txq = netdev_get_tx_queue(dev, port->q_index);
if (unlikely(netif_tx_queue_stopped(txq) &&
vnet_tx_dring_avail(dr) >= VNET_TX_WAKEUP_THRESH(dr)))
return 1;
return 0;
}
static int vnet_nack(struct vnet_port *port, void *msgbuf)
{
return 0;
}
static int handle_mcast(struct vnet_port *port, void *msgbuf)
{
struct vio_net_mcast_info *pkt = msgbuf;
struct net_device *dev = VNET_PORT_TO_NET_DEVICE(port);
if (pkt->tag.stype != VIO_SUBTYPE_ACK)
pr_err("%s: Got unexpected MCAST reply [%02x:%02x:%04x:%08x]\n",
dev->name,
pkt->tag.type,
pkt->tag.stype,
pkt->tag.stype_env,
pkt->tag.sid);
return 0;
}
static void maybe_tx_wakeup(struct vnet_port *port)
{
struct netdev_queue *txq;
txq = netdev_get_tx_queue(VNET_PORT_TO_NET_DEVICE(port),
port->q_index);
__netif_tx_lock(txq, smp_processor_id());
if (likely(netif_tx_queue_stopped(txq)))
netif_tx_wake_queue(txq);
__netif_tx_unlock(txq);
}
bool sunvnet_port_is_up_common(struct vnet_port *vnet)
{
struct vio_driver_state *vio = &vnet->vio;
return !!(vio->hs_state & VIO_HS_COMPLETE);
}
static int vnet_event_napi(struct vnet_port *port, int budget)
{
struct net_device *dev = VNET_PORT_TO_NET_DEVICE(port);
struct vio_driver_state *vio = &port->vio;
int tx_wakeup, err;
int npkts = 0;
BUG_ON(port->rx_event & ~(LDC_EVENT_DATA_READY |
LDC_EVENT_RESET |
LDC_EVENT_UP));
if (port->rx_event & LDC_EVENT_RESET) {
if (port->vsw == 1) {
netif_tx_stop_all_queues(dev);
netif_carrier_off(dev);
}
vio_link_state_change(vio, LDC_EVENT_RESET);
vnet_port_reset(port);
vio_port_up(vio);
if (netif_running(dev))
maybe_tx_wakeup(port);
port->rx_event = 0;
port->stats.event_reset++;
return 0;
}
if (port->rx_event & LDC_EVENT_UP) {
if (port->vsw == 1) {
netif_carrier_on(port->dev);
netif_tx_start_all_queues(port->dev);
}
vio_link_state_change(vio, LDC_EVENT_UP);
port->rx_event = 0;
port->stats.event_up++;
return 0;
}
err = 0;
tx_wakeup = 0;
while (1) {
union {
struct vio_msg_tag tag;
u64 raw[8];
} msgbuf;
if (port->napi_resume) {
struct vio_dring_data *pkt =
(struct vio_dring_data *)&msgbuf;
struct vio_dring_state *dr =
&port->vio.drings[VIO_DRIVER_RX_RING];
pkt->tag.type = VIO_TYPE_DATA;
pkt->tag.stype = VIO_SUBTYPE_INFO;
pkt->tag.stype_env = VIO_DRING_DATA;
pkt->seq = dr->rcv_nxt;
pkt->start_idx = vio_dring_next(dr,
port->napi_stop_idx);
pkt->end_idx = -1;
} else {
err = ldc_read(vio->lp, &msgbuf, sizeof(msgbuf));
if (unlikely(err < 0)) {
if (err == -ECONNRESET)
vio_conn_reset(vio);
break;
}
if (err == 0)
break;
viodbg(DATA, "TAG [%02x:%02x:%04x:%08x]\n",
msgbuf.tag.type,
msgbuf.tag.stype,
msgbuf.tag.stype_env,
msgbuf.tag.sid);
err = vio_validate_sid(vio, &msgbuf.tag);
if (err < 0)
break;
}
if (likely(msgbuf.tag.type == VIO_TYPE_DATA)) {
if (msgbuf.tag.stype == VIO_SUBTYPE_INFO) {
if (!sunvnet_port_is_up_common(port)) {
err = -ECONNRESET;
break;
}
err = vnet_rx(port, &msgbuf, &npkts, budget);
if (npkts >= budget)
break;
if (npkts == 0)
break;
} else if (msgbuf.tag.stype == VIO_SUBTYPE_ACK) {
err = vnet_ack(port, &msgbuf);
if (err > 0)
tx_wakeup |= err;
} else if (msgbuf.tag.stype == VIO_SUBTYPE_NACK) {
err = vnet_nack(port, &msgbuf);
}
} else if (msgbuf.tag.type == VIO_TYPE_CTRL) {
if (msgbuf.tag.stype_env == VNET_MCAST_INFO)
err = handle_mcast(port, &msgbuf);
else
err = vio_control_pkt_engine(vio, &msgbuf);
if (err)
break;
} else {
err = vnet_handle_unknown(port, &msgbuf);
}
if (err == -ECONNRESET)
break;
}
if (unlikely(tx_wakeup && err != -ECONNRESET))
maybe_tx_wakeup(port);
return npkts;
}
int sunvnet_poll_common(struct napi_struct *napi, int budget)
{
struct vnet_port *port = container_of(napi, struct vnet_port, napi);
struct vio_driver_state *vio = &port->vio;
int processed = vnet_event_napi(port, budget);
if (processed < budget) {
napi_complete_done(napi, processed);
port->rx_event &= ~LDC_EVENT_DATA_READY;
vio_set_intr(vio->vdev->rx_ino, HV_INTR_ENABLED);
}
return processed;
}
void sunvnet_event_common(void *arg, int event)
{
struct vnet_port *port = arg;
struct vio_driver_state *vio = &port->vio;
port->rx_event |= event;
vio_set_intr(vio->vdev->rx_ino, HV_INTR_DISABLED);
napi_schedule(&port->napi);
}
static int __vnet_tx_trigger(struct vnet_port *port, u32 start)
{
struct vio_dring_state *dr = &port->vio.drings[VIO_DRIVER_TX_RING];
struct vio_dring_data hdr = {
.tag = {
.type = VIO_TYPE_DATA,
.stype = VIO_SUBTYPE_INFO,
.stype_env = VIO_DRING_DATA,
.sid = vio_send_sid(&port->vio),
},
.dring_ident = dr->ident,
.start_idx = start,
.end_idx = (u32)-1,
};
int err, delay;
int retries = 0;
if (port->stop_rx) {
trace_vnet_tx_pending_stopped_ack(port->vio._local_sid,
port->vio._peer_sid,
port->stop_rx_idx, -1);
err = vnet_send_ack(port,
&port->vio.drings[VIO_DRIVER_RX_RING],
port->stop_rx_idx, -1,
VIO_DRING_STOPPED);
if (err <= 0)
return err;
}
hdr.seq = dr->snd_nxt;
delay = 1;
do {
err = vio_ldc_send(&port->vio, &hdr, sizeof(hdr));
if (err > 0) {
dr->snd_nxt++;
break;
}
udelay(delay);
if ((delay <<= 1) > 128)
delay = 128;
if (retries++ > VNET_MAX_RETRIES)
break;
} while (err == -EAGAIN);
trace_vnet_tx_trigger(port->vio._local_sid,
port->vio._peer_sid, start, err);
return err;
}
static struct sk_buff *vnet_clean_tx_ring(struct vnet_port *port,
unsigned *pending)
{
struct vio_dring_state *dr = &port->vio.drings[VIO_DRIVER_TX_RING];
struct sk_buff *skb = NULL;
int i, txi;
*pending = 0;
txi = dr->prod;
for (i = 0; i < VNET_TX_RING_SIZE; ++i) {
struct vio_net_desc *d;
--txi;
if (txi < 0)
txi = VNET_TX_RING_SIZE - 1;
d = vio_dring_entry(dr, txi);
if (d->hdr.state == VIO_DESC_READY) {
(*pending)++;
continue;
}
if (port->tx_bufs[txi].skb) {
if (d->hdr.state != VIO_DESC_DONE)
pr_notice("invalid ring buffer state %d\n",
d->hdr.state);
BUG_ON(port->tx_bufs[txi].skb->next);
port->tx_bufs[txi].skb->next = skb;
skb = port->tx_bufs[txi].skb;
port->tx_bufs[txi].skb = NULL;
ldc_unmap(port->vio.lp,
port->tx_bufs[txi].cookies,
port->tx_bufs[txi].ncookies);
} else if (d->hdr.state == VIO_DESC_FREE) {
break;
}
d->hdr.state = VIO_DESC_FREE;
}
return skb;
}
static inline void vnet_free_skbs(struct sk_buff *skb)
{
struct sk_buff *next;
while (skb) {
next = skb->next;
skb->next = NULL;
dev_kfree_skb(skb);
skb = next;
}
}
void sunvnet_clean_timer_expire_common(unsigned long port0)
{
struct vnet_port *port = (struct vnet_port *)port0;
struct sk_buff *freeskbs;
unsigned pending;
netif_tx_lock(VNET_PORT_TO_NET_DEVICE(port));
freeskbs = vnet_clean_tx_ring(port, &pending);
netif_tx_unlock(VNET_PORT_TO_NET_DEVICE(port));
vnet_free_skbs(freeskbs);
if (pending)
(void)mod_timer(&port->clean_timer,
jiffies + VNET_CLEAN_TIMEOUT);
else
del_timer(&port->clean_timer);
}
static inline int vnet_skb_map(struct ldc_channel *lp, struct sk_buff *skb,
struct ldc_trans_cookie *cookies, int ncookies,
unsigned int map_perm)
{
int i, nc, err, blen;
blen = skb_headlen(skb);
if (blen < ETH_ZLEN)
blen = ETH_ZLEN;
blen += VNET_PACKET_SKIP;
blen += 8 - (blen & 7);
err = ldc_map_single(lp, skb->data - VNET_PACKET_SKIP, blen, cookies,
ncookies, map_perm);
if (err < 0)
return err;
nc = err;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *f = &skb_shinfo(skb)->frags[i];
u8 *vaddr;
if (nc < ncookies) {
vaddr = kmap_atomic(skb_frag_page(f));
blen = skb_frag_size(f);
blen += 8 - (blen & 7);
err = ldc_map_single(lp, vaddr + f->page_offset,
blen, cookies + nc, ncookies - nc,
map_perm);
kunmap_atomic(vaddr);
} else {
err = -EMSGSIZE;
}
if (err < 0) {
ldc_unmap(lp, cookies, nc);
return err;
}
nc += err;
}
return nc;
}
static inline struct sk_buff *vnet_skb_shape(struct sk_buff *skb, int ncookies)
{
struct sk_buff *nskb;
int i, len, pad, docopy;
len = skb->len;
pad = 0;
if (len < ETH_ZLEN) {
pad += ETH_ZLEN - skb->len;
len += pad;
}
len += VNET_PACKET_SKIP;
pad += 8 - (len & 7);
docopy = skb_shinfo(skb)->nr_frags >= ncookies;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *f = &skb_shinfo(skb)->frags[i];
docopy |= f->page_offset & 7;
}
if (((unsigned long)skb->data & 7) != VNET_PACKET_SKIP ||
skb_tailroom(skb) < pad ||
skb_headroom(skb) < VNET_PACKET_SKIP || docopy) {
int start = 0, offset;
__wsum csum;
len = skb->len > ETH_ZLEN ? skb->len : ETH_ZLEN;
nskb = alloc_and_align_skb(skb->dev, len);
if (!nskb) {
dev_kfree_skb(skb);
return NULL;
}
skb_reserve(nskb, VNET_PACKET_SKIP);
nskb->protocol = skb->protocol;
offset = skb_mac_header(skb) - skb->data;
skb_set_mac_header(nskb, offset);
offset = skb_network_header(skb) - skb->data;
skb_set_network_header(nskb, offset);
offset = skb_transport_header(skb) - skb->data;
skb_set_transport_header(nskb, offset);
offset = 0;
nskb->csum_offset = skb->csum_offset;
nskb->ip_summed = skb->ip_summed;
if (skb->ip_summed == CHECKSUM_PARTIAL)
start = skb_checksum_start_offset(skb);
if (start) {
struct iphdr *iph = ip_hdr(nskb);
int offset = start + nskb->csum_offset;
if (skb_copy_bits(skb, 0, nskb->data, start)) {
dev_kfree_skb(nskb);
dev_kfree_skb(skb);
return NULL;
}
*(__sum16 *)(skb->data + offset) = 0;
csum = skb_copy_and_csum_bits(skb, start,
nskb->data + start,
skb->len - start, 0);
if (iph->protocol == IPPROTO_TCP ||
iph->protocol == IPPROTO_UDP) {
csum = csum_tcpudp_magic(iph->saddr, iph->daddr,
skb->len - start,
iph->protocol, csum);
}
*(__sum16 *)(nskb->data + offset) = csum;
nskb->ip_summed = CHECKSUM_NONE;
} else if (skb_copy_bits(skb, 0, nskb->data, skb->len)) {
dev_kfree_skb(nskb);
dev_kfree_skb(skb);
return NULL;
}
(void)skb_put(nskb, skb->len);
if (skb_is_gso(skb)) {
skb_shinfo(nskb)->gso_size = skb_shinfo(skb)->gso_size;
skb_shinfo(nskb)->gso_type = skb_shinfo(skb)->gso_type;
}
nskb->queue_mapping = skb->queue_mapping;
dev_kfree_skb(skb);
skb = nskb;
}
return skb;
}
void sunvnet_tx_timeout_common(struct net_device *dev)
{
}
int sunvnet_open_common(struct net_device *dev)
{
netif_carrier_on(dev);
netif_tx_start_all_queues(dev);
return 0;
}
int sunvnet_close_common(struct net_device *dev)
{
netif_tx_stop_all_queues(dev);
netif_carrier_off(dev);
return 0;
}
static struct vnet_mcast_entry *__vnet_mc_find(struct vnet *vp, u8 *addr)
{
struct vnet_mcast_entry *m;
for (m = vp->mcast_list; m; m = m->next) {
if (ether_addr_equal(m->addr, addr))
return m;
}
return NULL;
}
static void __update_mc_list(struct vnet *vp, struct net_device *dev)
{
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev) {
struct vnet_mcast_entry *m;
m = __vnet_mc_find(vp, ha->addr);
if (m) {
m->hit = 1;
continue;
}
if (!m) {
m = kzalloc(sizeof(*m), GFP_ATOMIC);
if (!m)
continue;
memcpy(m->addr, ha->addr, ETH_ALEN);
m->hit = 1;
m->next = vp->mcast_list;
vp->mcast_list = m;
}
}
}
static void __send_mc_list(struct vnet *vp, struct vnet_port *port)
{
struct vio_net_mcast_info info;
struct vnet_mcast_entry *m, **pp;
int n_addrs;
memset(&info, 0, sizeof(info));
info.tag.type = VIO_TYPE_CTRL;
info.tag.stype = VIO_SUBTYPE_INFO;
info.tag.stype_env = VNET_MCAST_INFO;
info.tag.sid = vio_send_sid(&port->vio);
info.set = 1;
n_addrs = 0;
for (m = vp->mcast_list; m; m = m->next) {
if (m->sent)
continue;
m->sent = 1;
memcpy(&info.mcast_addr[n_addrs * ETH_ALEN],
m->addr, ETH_ALEN);
if (++n_addrs == VNET_NUM_MCAST) {
info.count = n_addrs;
(void)vio_ldc_send(&port->vio, &info,
sizeof(info));
n_addrs = 0;
}
}
if (n_addrs) {
info.count = n_addrs;
(void)vio_ldc_send(&port->vio, &info, sizeof(info));
}
info.set = 0;
n_addrs = 0;
pp = &vp->mcast_list;
while ((m = *pp) != NULL) {
if (m->hit) {
m->hit = 0;
pp = &m->next;
continue;
}
memcpy(&info.mcast_addr[n_addrs * ETH_ALEN],
m->addr, ETH_ALEN);
if (++n_addrs == VNET_NUM_MCAST) {
info.count = n_addrs;
(void)vio_ldc_send(&port->vio, &info,
sizeof(info));
n_addrs = 0;
}
*pp = m->next;
kfree(m);
}
if (n_addrs) {
info.count = n_addrs;
(void)vio_ldc_send(&port->vio, &info, sizeof(info));
}
}
void sunvnet_set_rx_mode_common(struct net_device *dev, struct vnet *vp)
{
struct vnet_port *port;
rcu_read_lock();
list_for_each_entry_rcu(port, &vp->port_list, list) {
if (port->switch_port) {
__update_mc_list(vp, dev);
__send_mc_list(vp, port);
break;
}
}
rcu_read_unlock();
}
int sunvnet_set_mac_addr_common(struct net_device *dev, void *p)
{
return -EINVAL;
}
void sunvnet_port_free_tx_bufs_common(struct vnet_port *port)
{
struct vio_dring_state *dr;
int i;
dr = &port->vio.drings[VIO_DRIVER_TX_RING];
if (!dr->base)
return;
for (i = 0; i < VNET_TX_RING_SIZE; i++) {
struct vio_net_desc *d;
void *skb = port->tx_bufs[i].skb;
if (!skb)
continue;
d = vio_dring_entry(dr, i);
ldc_unmap(port->vio.lp,
port->tx_bufs[i].cookies,
port->tx_bufs[i].ncookies);
dev_kfree_skb(skb);
port->tx_bufs[i].skb = NULL;
d->hdr.state = VIO_DESC_FREE;
}
ldc_free_exp_dring(port->vio.lp, dr->base,
(dr->entry_size * dr->num_entries),
dr->cookies, dr->ncookies);
dr->base = NULL;
dr->entry_size = 0;
dr->num_entries = 0;
dr->pending = 0;
dr->ncookies = 0;
}
void vnet_port_reset(struct vnet_port *port)
{
del_timer(&port->clean_timer);
sunvnet_port_free_tx_bufs_common(port);
port->rmtu = 0;
port->tso = (port->vsw == 0);
port->tsolen = 0;
}
static int vnet_port_alloc_tx_ring(struct vnet_port *port)
{
struct vio_dring_state *dr;
unsigned long len, elen;
int i, err, ncookies;
void *dring;
dr = &port->vio.drings[VIO_DRIVER_TX_RING];
elen = sizeof(struct vio_net_desc) +
sizeof(struct ldc_trans_cookie) * 2;
if (vio_version_after_eq(&port->vio, 1, 7))
elen += sizeof(struct vio_net_dext);
len = VNET_TX_RING_SIZE * elen;
ncookies = VIO_MAX_RING_COOKIES;
dring = ldc_alloc_exp_dring(port->vio.lp, len,
dr->cookies, &ncookies,
(LDC_MAP_SHADOW |
LDC_MAP_DIRECT |
LDC_MAP_RW));
if (IS_ERR(dring)) {
err = PTR_ERR(dring);
goto err_out;
}
dr->base = dring;
dr->entry_size = elen;
dr->num_entries = VNET_TX_RING_SIZE;
dr->prod = 0;
dr->cons = 0;
port->start_cons = true;
dr->pending = VNET_TX_RING_SIZE;
dr->ncookies = ncookies;
for (i = 0; i < VNET_TX_RING_SIZE; ++i) {
struct vio_net_desc *d;
d = vio_dring_entry(dr, i);
d->hdr.state = VIO_DESC_FREE;
}
return 0;
err_out:
sunvnet_port_free_tx_bufs_common(port);
return err;
}
void sunvnet_poll_controller_common(struct net_device *dev, struct vnet *vp)
{
struct vnet_port *port;
unsigned long flags;
spin_lock_irqsave(&vp->lock, flags);
if (!list_empty(&vp->port_list)) {
port = list_entry(vp->port_list.next, struct vnet_port, list);
napi_schedule(&port->napi);
}
spin_unlock_irqrestore(&vp->lock, flags);
}
void sunvnet_port_add_txq_common(struct vnet_port *port)
{
struct vnet *vp = port->vp;
int smallest = 0;
int i;
for (i = 0; i < VNET_MAX_TXQS; i++) {
if (vp->q_used[i] == 0) {
smallest = i;
break;
}
if (vp->q_used[i] < vp->q_used[smallest])
smallest = i;
}
vp->nports++;
vp->q_used[smallest]++;
port->q_index = smallest;
}
void sunvnet_port_rm_txq_common(struct vnet_port *port)
{
port->vp->nports--;
port->vp->q_used[port->q_index]--;
port->q_index = 0;
}
