static int ax25_rx_fragment(ax25_cb *ax25, struct sk_buff *skb)
{
struct sk_buff *skbn, *skbo;
if (ax25->fragno != 0) {
if (!(*skb->data & AX25_SEG_FIRST)) {
if ((ax25->fragno - 1) == (*skb->data & AX25_SEG_REM)) {
ax25->fragno = *skb->data & AX25_SEG_REM;
skb_pull(skb, 1);
ax25->fraglen += skb->len;
skb_queue_tail(&ax25->frag_queue, skb);
if (ax25->fragno == 0) {
skbn = alloc_skb(AX25_MAX_HEADER_LEN +
ax25->fraglen,
GFP_ATOMIC);
if (!skbn) {
skb_queue_purge(&ax25->frag_queue);
return 1;
}
skb_reserve(skbn, AX25_MAX_HEADER_LEN);
skbn->dev = ax25->ax25_dev->dev;
skb_reset_network_header(skbn);
skb_reset_transport_header(skbn);
while ((skbo = skb_dequeue(&ax25->frag_queue)) != NULL) {
skb_copy_from_linear_data(skbo,
skb_put(skbn, skbo->len),
skbo->len);
kfree_skb(skbo);
}
ax25->fraglen = 0;
if (ax25_rx_iframe(ax25, skbn) == 0)
kfree_skb(skbn);
}
return 1;
}
}
} else {
if (*skb->data & AX25_SEG_FIRST) {
skb_queue_purge(&ax25->frag_queue);
ax25->fragno = *skb->data & AX25_SEG_REM;
skb_pull(skb, 1);
ax25->fraglen = skb->len;
skb_queue_tail(&ax25->frag_queue, skb);
return 1;
}
}
return 0;
}
int ax25_rx_iframe(ax25_cb *ax25, struct sk_buff *skb)
{
int (*func)(struct sk_buff *, ax25_cb *);
unsigned char pid;
int queued = 0;
if (skb == NULL) return 0;
ax25_start_idletimer(ax25);
pid = *skb->data;
if (pid == AX25_P_IP) {
struct sk_buff *skbn = skb_copy(skb, GFP_ATOMIC);
if (skbn != NULL) {
kfree_skb(skb);
skb = skbn;
}
skb_pull(skb, 1);
skb->mac_header = skb->network_header;
skb_reset_network_header(skb);
skb->dev = ax25->ax25_dev->dev;
skb->pkt_type = PACKET_HOST;
skb->protocol = htons(ETH_P_IP);
netif_rx(skb);
return 1;
}
if (pid == AX25_P_SEGMENT) {
skb_pull(skb, 1);
return ax25_rx_fragment(ax25, skb);
}
if ((func = ax25_protocol_function(pid)) != NULL) {
skb_pull(skb, 1);
return (*func)(skb, ax25);
}
if (ax25->sk != NULL && ax25->ax25_dev->values[AX25_VALUES_CONMODE] == 2) {
if ((!ax25->pidincl && ax25->sk->sk_protocol == pid) ||
ax25->pidincl) {
if (sock_queue_rcv_skb(ax25->sk, skb) == 0)
queued = 1;
else
ax25->condition |= AX25_COND_OWN_RX_BUSY;
}
}
return queued;
}
static int ax25_process_rx_frame(ax25_cb *ax25, struct sk_buff *skb, int type, int dama)
{
int queued = 0;
if (ax25->state == AX25_STATE_0)
return 0;
switch (ax25->ax25_dev->values[AX25_VALUES_PROTOCOL]) {
case AX25_PROTO_STD_SIMPLEX:
case AX25_PROTO_STD_DUPLEX:
queued = ax25_std_frame_in(ax25, skb, type);
break;
#ifdef CONFIG_AX25_DAMA_SLAVE
case AX25_PROTO_DAMA_SLAVE:
if (dama || ax25->ax25_dev->dama.slave)
queued = ax25_ds_frame_in(ax25, skb, type);
else
queued = ax25_std_frame_in(ax25, skb, type);
break;
#endif
}
return queued;
}
static int ax25_rcv(struct sk_buff *skb, struct net_device *dev,
ax25_address *dev_addr, struct packet_type *ptype)
{
ax25_address src, dest, *next_digi = NULL;
int type = 0, mine = 0, dama;
struct sock *make, *sk;
ax25_digi dp, reverse_dp;
ax25_cb *ax25;
ax25_dev *ax25_dev;
skb_reset_transport_header(skb);
if ((ax25_dev = ax25_dev_ax25dev(dev)) == NULL)
goto free;
if (ax25_addr_parse(skb->data, skb->len, &src, &dest, &dp, &type, &dama) == NULL)
goto free;
if (dp.lastrepeat + 1 < dp.ndigi)
next_digi = &dp.calls[dp.lastrepeat + 1];
skb_pull(skb, ax25_addr_size(&dp));
if (ax25cmp(&dest, dev_addr) == 0 && dp.lastrepeat + 1 == dp.ndigi)
mine = 1;
if (!mine && ax25_listen_mine(&dest, dev) && dp.lastrepeat + 1 == dp.ndigi)
mine = 1;
if ((*skb->data & ~0x10) == AX25_UI && dp.lastrepeat + 1 == dp.ndigi) {
skb_set_transport_header(skb, 2);
ax25_send_to_raw(&dest, skb, skb->data[1]);
if (!mine && ax25cmp(&dest, (ax25_address *)dev->broadcast) != 0)
goto free;
switch (skb->data[1]) {
case AX25_P_IP:
skb_pull(skb,2);
skb_reset_transport_header(skb);
skb_reset_network_header(skb);
skb->dev = dev;
skb->pkt_type = PACKET_HOST;
skb->protocol = htons(ETH_P_IP);
netif_rx(skb);
break;
case AX25_P_ARP:
skb_pull(skb,2);
skb_reset_transport_header(skb);
skb_reset_network_header(skb);
skb->dev = dev;
skb->pkt_type = PACKET_HOST;
skb->protocol = htons(ETH_P_ARP);
netif_rx(skb);
break;
case AX25_P_TEXT:
sk = ax25_get_socket(&dest, &src, SOCK_DGRAM);
if (sk != NULL) {
bh_lock_sock(sk);
if (atomic_read(&sk->sk_rmem_alloc) >=
sk->sk_rcvbuf) {
kfree_skb(skb);
} else {
skb_pull(skb, 2);
if (sock_queue_rcv_skb(sk, skb) != 0)
kfree_skb(skb);
}
bh_unlock_sock(sk);
sock_put(sk);
} else {
kfree_skb(skb);
}
break;
default:
kfree_skb(skb);
break;
}
return 0;
}
if (ax25_dev->values[AX25_VALUES_CONMODE] == 0)
goto free;
ax25_digi_invert(&dp, &reverse_dp);
if ((ax25 = ax25_find_cb(&dest, &src, &reverse_dp, dev)) != NULL) {
if (ax25_process_rx_frame(ax25, skb, type, dama) == 0)
kfree_skb(skb);
ax25_cb_put(ax25);
return 0;
}
if ((*skb->data & ~AX25_PF) != AX25_SABM &&
(*skb->data & ~AX25_PF) != AX25_SABME) {
if ((*skb->data & ~AX25_PF) != AX25_DM && mine)
ax25_return_dm(dev, &src, &dest, &dp);
goto free;
}
if (dp.lastrepeat + 1 == dp.ndigi)
sk = ax25_find_listener(&dest, 0, dev, SOCK_SEQPACKET);
else
sk = ax25_find_listener(next_digi, 1, dev, SOCK_SEQPACKET);
if (sk != NULL) {
bh_lock_sock(sk);
if (sk_acceptq_is_full(sk) ||
(make = ax25_make_new(sk, ax25_dev)) == NULL) {
if (mine)
ax25_return_dm(dev, &src, &dest, &dp);
kfree_skb(skb);
bh_unlock_sock(sk);
sock_put(sk);
return 0;
}
ax25 = sk_to_ax25(make);
skb_set_owner_r(skb, make);
skb_queue_head(&sk->sk_receive_queue, skb);
make->sk_state = TCP_ESTABLISHED;
sk->sk_ack_backlog++;
bh_unlock_sock(sk);
} else {
if (!mine)
goto free;
if ((ax25 = ax25_create_cb()) == NULL) {
ax25_return_dm(dev, &src, &dest, &dp);
goto free;
}
ax25_fillin_cb(ax25, ax25_dev);
}
ax25->source_addr = dest;
ax25->dest_addr = src;
if (dp.ndigi && !ax25->digipeat &&
(ax25->digipeat = kmalloc(sizeof(ax25_digi), GFP_ATOMIC)) == NULL) {
kfree_skb(skb);
ax25_destroy_socket(ax25);
if (sk)
sock_put(sk);
return 0;
}
if (dp.ndigi == 0) {
kfree(ax25->digipeat);
ax25->digipeat = NULL;
} else {
memcpy(ax25->digipeat, &reverse_dp, sizeof(ax25_digi));
}
if ((*skb->data & ~AX25_PF) == AX25_SABME) {
ax25->modulus = AX25_EMODULUS;
ax25->window = ax25_dev->values[AX25_VALUES_EWINDOW];
} else {
ax25->modulus = AX25_MODULUS;
ax25->window = ax25_dev->values[AX25_VALUES_WINDOW];
}
ax25_send_control(ax25, AX25_UA, AX25_POLLON, AX25_RESPONSE);
#ifdef CONFIG_AX25_DAMA_SLAVE
if (dama && ax25->ax25_dev->values[AX25_VALUES_PROTOCOL] == AX25_PROTO_DAMA_SLAVE)
ax25_dama_on(ax25);
#endif
ax25->state = AX25_STATE_3;
ax25_cb_add(ax25);
ax25_start_heartbeat(ax25);
ax25_start_t3timer(ax25);
ax25_start_idletimer(ax25);
if (sk) {
if (!sock_flag(sk, SOCK_DEAD))
sk->sk_data_ready(sk);
sock_put(sk);
} else {
free:
kfree_skb(skb);
}
return 0;
}
int ax25_kiss_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *ptype, struct net_device *orig_dev)
{
skb_orphan(skb);
if (!net_eq(dev_net(dev), &init_net)) {
kfree_skb(skb);
return 0;
}
if ((*skb->data & 0x0F) != 0) {
kfree_skb(skb);
return 0;
}
skb_pull(skb, AX25_KISS_HEADER_LEN);
return ax25_rcv(skb, dev, (ax25_address *)dev->dev_addr, ptype);
}
