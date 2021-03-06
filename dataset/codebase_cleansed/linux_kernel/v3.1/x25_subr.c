void x25_clear_queues(struct sock *sk)
{
struct x25_sock *x25 = x25_sk(sk);
skb_queue_purge(&sk->sk_write_queue);
skb_queue_purge(&x25->ack_queue);
skb_queue_purge(&x25->interrupt_in_queue);
skb_queue_purge(&x25->interrupt_out_queue);
skb_queue_purge(&x25->fragment_queue);
}
void x25_frames_acked(struct sock *sk, unsigned short nr)
{
struct sk_buff *skb;
struct x25_sock *x25 = x25_sk(sk);
int modulus = x25->neighbour->extended ? X25_EMODULUS : X25_SMODULUS;
if (x25->va != nr)
while (skb_peek(&x25->ack_queue) && x25->va != nr) {
skb = skb_dequeue(&x25->ack_queue);
kfree_skb(skb);
x25->va = (x25->va + 1) % modulus;
}
}
void x25_requeue_frames(struct sock *sk)
{
struct sk_buff *skb, *skb_prev = NULL;
while ((skb = skb_dequeue(&x25_sk(sk)->ack_queue)) != NULL) {
if (!skb_prev)
skb_queue_head(&sk->sk_write_queue, skb);
else
skb_append(skb_prev, skb, &sk->sk_write_queue);
skb_prev = skb;
}
}
int x25_validate_nr(struct sock *sk, unsigned short nr)
{
struct x25_sock *x25 = x25_sk(sk);
unsigned short vc = x25->va;
int modulus = x25->neighbour->extended ? X25_EMODULUS : X25_SMODULUS;
while (vc != x25->vs) {
if (nr == vc)
return 1;
vc = (vc + 1) % modulus;
}
return nr == x25->vs ? 1 : 0;
}
void x25_write_internal(struct sock *sk, int frametype)
{
struct x25_sock *x25 = x25_sk(sk);
struct sk_buff *skb;
unsigned char *dptr;
unsigned char facilities[X25_MAX_FAC_LEN];
unsigned char addresses[1 + X25_ADDR_LEN];
unsigned char lci1, lci2;
int len = X25_MAX_L2_LEN + X25_EXT_MIN_LEN;
switch (frametype) {
case X25_CALL_REQUEST:
len += 1 + X25_ADDR_LEN + X25_MAX_FAC_LEN + X25_MAX_CUD_LEN;
break;
case X25_CALL_ACCEPTED:
if (x25->facilities.reverse & 0x80) {
len += 1 + X25_MAX_FAC_LEN + X25_MAX_CUD_LEN;
} else {
len += 1 + X25_MAX_FAC_LEN;
}
break;
case X25_CLEAR_REQUEST:
case X25_RESET_REQUEST:
len += 2;
break;
case X25_RR:
case X25_RNR:
case X25_REJ:
case X25_CLEAR_CONFIRMATION:
case X25_INTERRUPT_CONFIRMATION:
case X25_RESET_CONFIRMATION:
break;
default:
printk(KERN_ERR "X.25: invalid frame type %02X\n", frametype);
return;
}
if ((skb = alloc_skb(len, GFP_ATOMIC)) == NULL)
return;
skb_reserve(skb, X25_MAX_L2_LEN);
dptr = skb_put(skb, 2);
lci1 = (x25->lci >> 8) & 0x0F;
lci2 = (x25->lci >> 0) & 0xFF;
if (x25->neighbour->extended) {
*dptr++ = lci1 | X25_GFI_EXTSEQ;
*dptr++ = lci2;
} else {
*dptr++ = lci1 | X25_GFI_STDSEQ;
*dptr++ = lci2;
}
switch (frametype) {
case X25_CALL_REQUEST:
dptr = skb_put(skb, 1);
*dptr++ = X25_CALL_REQUEST;
len = x25_addr_aton(addresses, &x25->dest_addr,
&x25->source_addr);
dptr = skb_put(skb, len);
memcpy(dptr, addresses, len);
len = x25_create_facilities(facilities,
&x25->facilities,
&x25->dte_facilities,
x25->neighbour->global_facil_mask);
dptr = skb_put(skb, len);
memcpy(dptr, facilities, len);
dptr = skb_put(skb, x25->calluserdata.cudlength);
memcpy(dptr, x25->calluserdata.cuddata,
x25->calluserdata.cudlength);
x25->calluserdata.cudlength = 0;
break;
case X25_CALL_ACCEPTED:
dptr = skb_put(skb, 2);
*dptr++ = X25_CALL_ACCEPTED;
*dptr++ = 0x00;
len = x25_create_facilities(facilities,
&x25->facilities,
&x25->dte_facilities,
x25->vc_facil_mask);
dptr = skb_put(skb, len);
memcpy(dptr, facilities, len);
if(x25->facilities.reverse & 0x80) {
dptr = skb_put(skb,
x25->calluserdata.cudlength);
memcpy(dptr, x25->calluserdata.cuddata,
x25->calluserdata.cudlength);
}
x25->calluserdata.cudlength = 0;
break;
case X25_CLEAR_REQUEST:
dptr = skb_put(skb, 3);
*dptr++ = frametype;
*dptr++ = x25->causediag.cause;
*dptr++ = x25->causediag.diagnostic;
break;
case X25_RESET_REQUEST:
dptr = skb_put(skb, 3);
*dptr++ = frametype;
*dptr++ = 0x00;
*dptr++ = 0x00;
break;
case X25_RR:
case X25_RNR:
case X25_REJ:
if (x25->neighbour->extended) {
dptr = skb_put(skb, 2);
*dptr++ = frametype;
*dptr++ = (x25->vr << 1) & 0xFE;
} else {
dptr = skb_put(skb, 1);
*dptr = frametype;
*dptr++ |= (x25->vr << 5) & 0xE0;
}
break;
case X25_CLEAR_CONFIRMATION:
case X25_INTERRUPT_CONFIRMATION:
case X25_RESET_CONFIRMATION:
dptr = skb_put(skb, 1);
*dptr = frametype;
break;
}
x25_transmit_link(skb, x25->neighbour);
}
int x25_decode(struct sock *sk, struct sk_buff *skb, int *ns, int *nr, int *q,
int *d, int *m)
{
struct x25_sock *x25 = x25_sk(sk);
unsigned char *frame;
if (!pskb_may_pull(skb, X25_STD_MIN_LEN))
return X25_ILLEGAL;
frame = skb->data;
*ns = *nr = *q = *d = *m = 0;
switch (frame[2]) {
case X25_CALL_REQUEST:
case X25_CALL_ACCEPTED:
case X25_CLEAR_REQUEST:
case X25_CLEAR_CONFIRMATION:
case X25_INTERRUPT:
case X25_INTERRUPT_CONFIRMATION:
case X25_RESET_REQUEST:
case X25_RESET_CONFIRMATION:
case X25_RESTART_REQUEST:
case X25_RESTART_CONFIRMATION:
case X25_REGISTRATION_REQUEST:
case X25_REGISTRATION_CONFIRMATION:
case X25_DIAGNOSTIC:
return frame[2];
}
if (x25->neighbour->extended) {
if (frame[2] == X25_RR ||
frame[2] == X25_RNR ||
frame[2] == X25_REJ) {
if (!pskb_may_pull(skb, X25_EXT_MIN_LEN))
return X25_ILLEGAL;
frame = skb->data;
*nr = (frame[3] >> 1) & 0x7F;
return frame[2];
}
} else {
if ((frame[2] & 0x1F) == X25_RR ||
(frame[2] & 0x1F) == X25_RNR ||
(frame[2] & 0x1F) == X25_REJ) {
*nr = (frame[2] >> 5) & 0x07;
return frame[2] & 0x1F;
}
}
if (x25->neighbour->extended) {
if ((frame[2] & 0x01) == X25_DATA) {
if (!pskb_may_pull(skb, X25_EXT_MIN_LEN))
return X25_ILLEGAL;
frame = skb->data;
*q = (frame[0] & X25_Q_BIT) == X25_Q_BIT;
*d = (frame[0] & X25_D_BIT) == X25_D_BIT;
*m = (frame[3] & X25_EXT_M_BIT) == X25_EXT_M_BIT;
*nr = (frame[3] >> 1) & 0x7F;
*ns = (frame[2] >> 1) & 0x7F;
return X25_DATA;
}
} else {
if ((frame[2] & 0x01) == X25_DATA) {
*q = (frame[0] & X25_Q_BIT) == X25_Q_BIT;
*d = (frame[0] & X25_D_BIT) == X25_D_BIT;
*m = (frame[2] & X25_STD_M_BIT) == X25_STD_M_BIT;
*nr = (frame[2] >> 5) & 0x07;
*ns = (frame[2] >> 1) & 0x07;
return X25_DATA;
}
}
printk(KERN_DEBUG "X.25: invalid PLP frame %02X %02X %02X\n",
frame[0], frame[1], frame[2]);
return X25_ILLEGAL;
}
void x25_disconnect(struct sock *sk, int reason, unsigned char cause,
unsigned char diagnostic)
{
struct x25_sock *x25 = x25_sk(sk);
x25_clear_queues(sk);
x25_stop_timer(sk);
x25->lci = 0;
x25->state = X25_STATE_0;
x25->causediag.cause = cause;
x25->causediag.diagnostic = diagnostic;
sk->sk_state = TCP_CLOSE;
sk->sk_err = reason;
sk->sk_shutdown |= SEND_SHUTDOWN;
if (!sock_flag(sk, SOCK_DEAD)) {
sk->sk_state_change(sk);
sock_set_flag(sk, SOCK_DEAD);
}
}
void x25_check_rbuf(struct sock *sk)
{
struct x25_sock *x25 = x25_sk(sk);
if (atomic_read(&sk->sk_rmem_alloc) < (sk->sk_rcvbuf >> 1) &&
(x25->condition & X25_COND_OWN_RX_BUSY)) {
x25->condition &= ~X25_COND_OWN_RX_BUSY;
x25->condition &= ~X25_COND_ACK_PENDING;
x25->vl = x25->vr;
x25_write_internal(sk, X25_RR);
x25_stop_timer(sk);
}
}
