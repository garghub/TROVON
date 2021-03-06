void nr_clear_queues(struct sock *sk)
{
struct nr_sock *nr = nr_sk(sk);
skb_queue_purge(&sk->sk_write_queue);
skb_queue_purge(&nr->ack_queue);
skb_queue_purge(&nr->reseq_queue);
skb_queue_purge(&nr->frag_queue);
}
void nr_frames_acked(struct sock *sk, unsigned short nr)
{
struct nr_sock *nrom = nr_sk(sk);
struct sk_buff *skb;
if (nrom->va != nr) {
while (skb_peek(&nrom->ack_queue) != NULL && nrom->va != nr) {
skb = skb_dequeue(&nrom->ack_queue);
kfree_skb(skb);
nrom->va = (nrom->va + 1) % NR_MODULUS;
}
}
}
void nr_requeue_frames(struct sock *sk)
{
struct sk_buff *skb, *skb_prev = NULL;
while ((skb = skb_dequeue(&nr_sk(sk)->ack_queue)) != NULL) {
if (skb_prev == NULL)
skb_queue_head(&sk->sk_write_queue, skb);
else
skb_append(skb_prev, skb, &sk->sk_write_queue);
skb_prev = skb;
}
}
int nr_validate_nr(struct sock *sk, unsigned short nr)
{
struct nr_sock *nrom = nr_sk(sk);
unsigned short vc = nrom->va;
while (vc != nrom->vs) {
if (nr == vc) return 1;
vc = (vc + 1) % NR_MODULUS;
}
return nr == nrom->vs;
}
int nr_in_rx_window(struct sock *sk, unsigned short ns)
{
struct nr_sock *nr = nr_sk(sk);
unsigned short vc = nr->vr;
unsigned short vt = (nr->vl + nr->window) % NR_MODULUS;
while (vc != vt) {
if (ns == vc) return 1;
vc = (vc + 1) % NR_MODULUS;
}
return 0;
}
void nr_write_internal(struct sock *sk, int frametype)
{
struct nr_sock *nr = nr_sk(sk);
struct sk_buff *skb;
unsigned char *dptr;
int len, timeout;
len = NR_NETWORK_LEN + NR_TRANSPORT_LEN;
switch (frametype & 0x0F) {
case NR_CONNREQ:
len += 17;
break;
case NR_CONNACK:
len += (nr->bpqext) ? 2 : 1;
break;
case NR_DISCREQ:
case NR_DISCACK:
case NR_INFOACK:
break;
default:
printk(KERN_ERR "NET/ROM: nr_write_internal - invalid frame type %d\n", frametype);
return;
}
if ((skb = alloc_skb(len, GFP_ATOMIC)) == NULL)
return;
skb_reserve(skb, NR_NETWORK_LEN);
dptr = skb_put(skb, skb_tailroom(skb));
switch (frametype & 0x0F) {
case NR_CONNREQ:
timeout = nr->t1 / HZ;
*dptr++ = nr->my_index;
*dptr++ = nr->my_id;
*dptr++ = 0;
*dptr++ = 0;
*dptr++ = frametype;
*dptr++ = nr->window;
memcpy(dptr, &nr->user_addr, AX25_ADDR_LEN);
dptr[6] &= ~AX25_CBIT;
dptr[6] &= ~AX25_EBIT;
dptr[6] |= AX25_SSSID_SPARE;
dptr += AX25_ADDR_LEN;
memcpy(dptr, &nr->source_addr, AX25_ADDR_LEN);
dptr[6] &= ~AX25_CBIT;
dptr[6] &= ~AX25_EBIT;
dptr[6] |= AX25_SSSID_SPARE;
dptr += AX25_ADDR_LEN;
*dptr++ = timeout % 256;
*dptr++ = timeout / 256;
break;
case NR_CONNACK:
*dptr++ = nr->your_index;
*dptr++ = nr->your_id;
*dptr++ = nr->my_index;
*dptr++ = nr->my_id;
*dptr++ = frametype;
*dptr++ = nr->window;
if (nr->bpqext) *dptr++ = sysctl_netrom_network_ttl_initialiser;
break;
case NR_DISCREQ:
case NR_DISCACK:
*dptr++ = nr->your_index;
*dptr++ = nr->your_id;
*dptr++ = 0;
*dptr++ = 0;
*dptr++ = frametype;
break;
case NR_INFOACK:
*dptr++ = nr->your_index;
*dptr++ = nr->your_id;
*dptr++ = 0;
*dptr++ = nr->vr;
*dptr++ = frametype;
break;
}
nr_transmit_buffer(sk, skb);
}
void __nr_transmit_reply(struct sk_buff *skb, int mine, unsigned char cmdflags)
{
struct sk_buff *skbn;
unsigned char *dptr;
int len;
len = NR_NETWORK_LEN + NR_TRANSPORT_LEN + 1;
if ((skbn = alloc_skb(len, GFP_ATOMIC)) == NULL)
return;
skb_reserve(skbn, 0);
dptr = skb_put(skbn, NR_NETWORK_LEN + NR_TRANSPORT_LEN);
skb_copy_from_linear_data_offset(skb, 7, dptr, AX25_ADDR_LEN);
dptr[6] &= ~AX25_CBIT;
dptr[6] &= ~AX25_EBIT;
dptr[6] |= AX25_SSSID_SPARE;
dptr += AX25_ADDR_LEN;
skb_copy_from_linear_data(skb, dptr, AX25_ADDR_LEN);
dptr[6] &= ~AX25_CBIT;
dptr[6] |= AX25_EBIT;
dptr[6] |= AX25_SSSID_SPARE;
dptr += AX25_ADDR_LEN;
*dptr++ = sysctl_netrom_network_ttl_initialiser;
if (mine) {
*dptr++ = 0;
*dptr++ = 0;
*dptr++ = skb->data[15];
*dptr++ = skb->data[16];
} else {
*dptr++ = skb->data[15];
*dptr++ = skb->data[16];
*dptr++ = 0;
*dptr++ = 0;
}
*dptr++ = cmdflags;
*dptr++ = 0;
if (!nr_route_frame(skbn, NULL))
kfree_skb(skbn);
}
void nr_disconnect(struct sock *sk, int reason)
{
nr_stop_t1timer(sk);
nr_stop_t2timer(sk);
nr_stop_t4timer(sk);
nr_stop_idletimer(sk);
nr_clear_queues(sk);
nr_sk(sk)->state = NR_STATE_0;
sk->sk_state = TCP_CLOSE;
sk->sk_err = reason;
sk->sk_shutdown |= SEND_SHUTDOWN;
if (!sock_flag(sk, SOCK_DEAD)) {
sk->sk_state_change(sk);
sock_set_flag(sk, SOCK_DEAD);
}
}
