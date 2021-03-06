void ax25_ds_setup_timer(ax25_dev *ax25_dev)
{
setup_timer(&ax25_dev->dama.slave_timer, ax25_ds_timeout,
(unsigned long)ax25_dev);
}
void ax25_ds_del_timer(ax25_dev *ax25_dev)
{
if (ax25_dev)
del_timer(&ax25_dev->dama.slave_timer);
}
void ax25_ds_set_timer(ax25_dev *ax25_dev)
{
if (ax25_dev == NULL)
return;
ax25_dev->dama.slave_timeout =
msecs_to_jiffies(ax25_dev->values[AX25_VALUES_DS_TIMEOUT]) / 10;
mod_timer(&ax25_dev->dama.slave_timer, jiffies + HZ);
}
static void ax25_ds_timeout(unsigned long arg)
{
ax25_dev *ax25_dev = (struct ax25_dev *) arg;
ax25_cb *ax25;
struct hlist_node *node;
if (ax25_dev == NULL || !ax25_dev->dama.slave)
return;
if (!ax25_dev->dama.slave_timeout || --ax25_dev->dama.slave_timeout) {
ax25_ds_set_timer(ax25_dev);
return;
}
spin_lock(&ax25_list_lock);
ax25_for_each(ax25, node, &ax25_list) {
if (ax25->ax25_dev != ax25_dev || !(ax25->condition & AX25_COND_DAMA_MODE))
continue;
ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
ax25_disconnect(ax25, ETIMEDOUT);
}
spin_unlock(&ax25_list_lock);
ax25_dev_dama_off(ax25_dev);
}
void ax25_ds_heartbeat_expiry(ax25_cb *ax25)
{
struct sock *sk=ax25->sk;
if (sk)
bh_lock_sock(sk);
switch (ax25->state) {
case AX25_STATE_0:
if (!sk || sock_flag(sk, SOCK_DESTROY) ||
(sk->sk_state == TCP_LISTEN &&
sock_flag(sk, SOCK_DEAD))) {
if (sk) {
sock_hold(sk);
ax25_destroy_socket(ax25);
bh_unlock_sock(sk);
sock_put(sk);
} else
ax25_destroy_socket(ax25);
return;
}
break;
case AX25_STATE_3:
if (sk != NULL) {
if (atomic_read(&sk->sk_rmem_alloc) <
(sk->sk_rcvbuf >> 1) &&
(ax25->condition & AX25_COND_OWN_RX_BUSY)) {
ax25->condition &= ~AX25_COND_OWN_RX_BUSY;
ax25->condition &= ~AX25_COND_ACK_PENDING;
break;
}
}
break;
}
if (sk)
bh_unlock_sock(sk);
ax25_start_heartbeat(ax25);
}
void ax25_ds_t3timer_expiry(ax25_cb *ax25)
{
ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
ax25_dama_off(ax25);
ax25_disconnect(ax25, ETIMEDOUT);
}
void ax25_ds_idletimer_expiry(ax25_cb *ax25)
{
ax25_clear_queues(ax25);
ax25->n2count = 0;
ax25->state = AX25_STATE_2;
ax25_calculate_t1(ax25);
ax25_start_t1timer(ax25);
ax25_stop_t3timer(ax25);
if (ax25->sk != NULL) {
bh_lock_sock(ax25->sk);
ax25->sk->sk_state = TCP_CLOSE;
ax25->sk->sk_err = 0;
ax25->sk->sk_shutdown |= SEND_SHUTDOWN;
if (!sock_flag(ax25->sk, SOCK_DEAD)) {
ax25->sk->sk_state_change(ax25->sk);
sock_set_flag(ax25->sk, SOCK_DEAD);
}
bh_unlock_sock(ax25->sk);
}
}
void ax25_ds_t1_timeout(ax25_cb *ax25)
{
switch (ax25->state) {
case AX25_STATE_1:
if (ax25->n2count == ax25->n2) {
if (ax25->modulus == AX25_MODULUS) {
ax25_disconnect(ax25, ETIMEDOUT);
return;
} else {
ax25->modulus = AX25_MODULUS;
ax25->window = ax25->ax25_dev->values[AX25_VALUES_WINDOW];
ax25->n2count = 0;
ax25_send_control(ax25, AX25_SABM, AX25_POLLOFF, AX25_COMMAND);
}
} else {
ax25->n2count++;
if (ax25->modulus == AX25_MODULUS)
ax25_send_control(ax25, AX25_SABM, AX25_POLLOFF, AX25_COMMAND);
else
ax25_send_control(ax25, AX25_SABME, AX25_POLLOFF, AX25_COMMAND);
}
break;
case AX25_STATE_2:
if (ax25->n2count == ax25->n2) {
ax25_send_control(ax25, AX25_DISC, AX25_POLLON, AX25_COMMAND);
ax25_disconnect(ax25, ETIMEDOUT);
return;
} else {
ax25->n2count++;
}
break;
case AX25_STATE_3:
if (ax25->n2count == ax25->n2) {
ax25_send_control(ax25, AX25_DM, AX25_POLLON, AX25_RESPONSE);
ax25_disconnect(ax25, ETIMEDOUT);
return;
} else {
ax25->n2count++;
}
break;
}
ax25_calculate_t1(ax25);
ax25_start_t1timer(ax25);
}
