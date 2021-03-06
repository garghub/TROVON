void ax25_ds_nr_error_recovery(ax25_cb *ax25)
{
ax25_ds_establish_data_link(ax25);
}
void ax25_ds_enquiry_response(ax25_cb *ax25)
{
ax25_cb *ax25o;
struct hlist_node *node;
ax25_std_enquiry_response(ax25);
if (!(ax25->condition & AX25_COND_PEER_RX_BUSY)) {
ax25_requeue_frames(ax25);
ax25_kick(ax25);
}
if (ax25->state == AX25_STATE_1 || ax25->state == AX25_STATE_2 || skb_peek(&ax25->ack_queue) != NULL)
ax25_ds_t1_timeout(ax25);
else
ax25->n2count = 0;
ax25_start_t3timer(ax25);
ax25_ds_set_timer(ax25->ax25_dev);
spin_lock(&ax25_list_lock);
ax25_for_each(ax25o, node, &ax25_list) {
if (ax25o == ax25)
continue;
if (ax25o->ax25_dev != ax25->ax25_dev)
continue;
if (ax25o->state == AX25_STATE_1 || ax25o->state == AX25_STATE_2) {
ax25_ds_t1_timeout(ax25o);
continue;
}
if (!(ax25o->condition & AX25_COND_PEER_RX_BUSY) && ax25o->state == AX25_STATE_3) {
ax25_requeue_frames(ax25o);
ax25_kick(ax25o);
}
if (ax25o->state == AX25_STATE_1 || ax25o->state == AX25_STATE_2 || skb_peek(&ax25o->ack_queue) != NULL)
ax25_ds_t1_timeout(ax25o);
if (ax25o->state != AX25_STATE_0)
ax25_start_t3timer(ax25o);
}
spin_unlock(&ax25_list_lock);
}
void ax25_ds_establish_data_link(ax25_cb *ax25)
{
ax25->condition &= AX25_COND_DAMA_MODE;
ax25->n2count = 0;
ax25_calculate_t1(ax25);
ax25_start_t1timer(ax25);
ax25_stop_t2timer(ax25);
ax25_start_t3timer(ax25);
}
static void ax25_kiss_cmd(ax25_dev *ax25_dev, unsigned char cmd, unsigned char param)
{
struct sk_buff *skb;
unsigned char *p;
if (ax25_dev->dev == NULL)
return;
if ((skb = alloc_skb(2, GFP_ATOMIC)) == NULL)
return;
skb_reset_network_header(skb);
p = skb_put(skb, 2);
*p++ = cmd;
*p++ = param;
skb->protocol = ax25_type_trans(skb, ax25_dev->dev);
dev_queue_xmit(skb);
}
static int ax25_check_dama_slave(ax25_dev *ax25_dev)
{
ax25_cb *ax25;
int res = 0;
struct hlist_node *node;
spin_lock(&ax25_list_lock);
ax25_for_each(ax25, node, &ax25_list)
if (ax25->ax25_dev == ax25_dev && (ax25->condition & AX25_COND_DAMA_MODE) && ax25->state > AX25_STATE_1) {
res = 1;
break;
}
spin_unlock(&ax25_list_lock);
return res;
}
static void ax25_dev_dama_on(ax25_dev *ax25_dev)
{
if (ax25_dev == NULL)
return;
if (ax25_dev->dama.slave == 0)
ax25_kiss_cmd(ax25_dev, 5, 1);
ax25_dev->dama.slave = 1;
ax25_ds_set_timer(ax25_dev);
}
void ax25_dev_dama_off(ax25_dev *ax25_dev)
{
if (ax25_dev == NULL)
return;
if (ax25_dev->dama.slave && !ax25_check_dama_slave(ax25_dev)) {
ax25_kiss_cmd(ax25_dev, 5, 0);
ax25_dev->dama.slave = 0;
ax25_ds_del_timer(ax25_dev);
}
}
void ax25_dama_on(ax25_cb *ax25)
{
ax25_dev_dama_on(ax25->ax25_dev);
ax25->condition |= AX25_COND_DAMA_MODE;
}
void ax25_dama_off(ax25_cb *ax25)
{
ax25->condition &= ~AX25_COND_DAMA_MODE;
ax25_dev_dama_off(ax25->ax25_dev);
}
