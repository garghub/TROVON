static inline void x25_start_t20timer(struct x25_neigh *nb)
{
mod_timer(&nb->t20timer, jiffies + nb->t20);
}
static void x25_t20timer_expiry(unsigned long param)
{
struct x25_neigh *nb = (struct x25_neigh *)param;
x25_transmit_restart_request(nb);
x25_start_t20timer(nb);
}
static inline void x25_stop_t20timer(struct x25_neigh *nb)
{
del_timer(&nb->t20timer);
}
static inline int x25_t20timer_pending(struct x25_neigh *nb)
{
return timer_pending(&nb->t20timer);
}
void x25_link_control(struct sk_buff *skb, struct x25_neigh *nb,
unsigned short frametype)
{
struct sk_buff *skbn;
int confirm;
switch (frametype) {
case X25_RESTART_REQUEST:
confirm = !x25_t20timer_pending(nb);
x25_stop_t20timer(nb);
nb->state = X25_LINK_STATE_3;
if (confirm)
x25_transmit_restart_confirmation(nb);
break;
case X25_RESTART_CONFIRMATION:
x25_stop_t20timer(nb);
nb->state = X25_LINK_STATE_3;
break;
case X25_DIAGNOSTIC:
if (!pskb_may_pull(skb, X25_STD_MIN_LEN + 4))
break;
printk(KERN_WARNING "x25: diagnostic #%d - %02X %02X %02X\n",
skb->data[3], skb->data[4],
skb->data[5], skb->data[6]);
break;
default:
printk(KERN_WARNING "x25: received unknown %02X with LCI 000\n",
frametype);
break;
}
if (nb->state == X25_LINK_STATE_3)
while ((skbn = skb_dequeue(&nb->queue)) != NULL)
x25_send_frame(skbn, nb);
}
static void x25_transmit_restart_request(struct x25_neigh *nb)
{
unsigned char *dptr;
int len = X25_MAX_L2_LEN + X25_STD_MIN_LEN + 2;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
return;
skb_reserve(skb, X25_MAX_L2_LEN);
dptr = skb_put(skb, X25_STD_MIN_LEN + 2);
*dptr++ = nb->extended ? X25_GFI_EXTSEQ : X25_GFI_STDSEQ;
*dptr++ = 0x00;
*dptr++ = X25_RESTART_REQUEST;
*dptr++ = 0x00;
*dptr++ = 0;
skb->sk = NULL;
x25_send_frame(skb, nb);
}
static void x25_transmit_restart_confirmation(struct x25_neigh *nb)
{
unsigned char *dptr;
int len = X25_MAX_L2_LEN + X25_STD_MIN_LEN;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
return;
skb_reserve(skb, X25_MAX_L2_LEN);
dptr = skb_put(skb, X25_STD_MIN_LEN);
*dptr++ = nb->extended ? X25_GFI_EXTSEQ : X25_GFI_STDSEQ;
*dptr++ = 0x00;
*dptr++ = X25_RESTART_CONFIRMATION;
skb->sk = NULL;
x25_send_frame(skb, nb);
}
void x25_transmit_clear_request(struct x25_neigh *nb, unsigned int lci,
unsigned char cause)
{
unsigned char *dptr;
int len = X25_MAX_L2_LEN + X25_STD_MIN_LEN + 2;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
return;
skb_reserve(skb, X25_MAX_L2_LEN);
dptr = skb_put(skb, X25_STD_MIN_LEN + 2);
*dptr++ = ((lci >> 8) & 0x0F) | (nb->extended ?
X25_GFI_EXTSEQ :
X25_GFI_STDSEQ);
*dptr++ = (lci >> 0) & 0xFF;
*dptr++ = X25_CLEAR_REQUEST;
*dptr++ = cause;
*dptr++ = 0x00;
skb->sk = NULL;
x25_send_frame(skb, nb);
}
void x25_transmit_link(struct sk_buff *skb, struct x25_neigh *nb)
{
switch (nb->state) {
case X25_LINK_STATE_0:
skb_queue_tail(&nb->queue, skb);
nb->state = X25_LINK_STATE_1;
x25_establish_link(nb);
break;
case X25_LINK_STATE_1:
case X25_LINK_STATE_2:
skb_queue_tail(&nb->queue, skb);
break;
case X25_LINK_STATE_3:
x25_send_frame(skb, nb);
break;
}
}
void x25_link_established(struct x25_neigh *nb)
{
switch (nb->state) {
case X25_LINK_STATE_0:
nb->state = X25_LINK_STATE_2;
break;
case X25_LINK_STATE_1:
x25_transmit_restart_request(nb);
nb->state = X25_LINK_STATE_2;
x25_start_t20timer(nb);
break;
}
}
void x25_link_terminated(struct x25_neigh *nb)
{
nb->state = X25_LINK_STATE_0;
x25_kill_by_neigh(nb);
}
void x25_link_device_up(struct net_device *dev)
{
struct x25_neigh *nb = kmalloc(sizeof(*nb), GFP_ATOMIC);
if (!nb)
return;
skb_queue_head_init(&nb->queue);
setup_timer(&nb->t20timer, x25_t20timer_expiry, (unsigned long)nb);
dev_hold(dev);
nb->dev = dev;
nb->state = X25_LINK_STATE_0;
nb->extended = 0;
nb->global_facil_mask = X25_MASK_REVERSE |
X25_MASK_THROUGHPUT |
X25_MASK_PACKET_SIZE |
X25_MASK_WINDOW_SIZE;
nb->t20 = sysctl_x25_restart_request_timeout;
atomic_set(&nb->refcnt, 1);
write_lock_bh(&x25_neigh_list_lock);
list_add(&nb->node, &x25_neigh_list);
write_unlock_bh(&x25_neigh_list_lock);
}
static void __x25_remove_neigh(struct x25_neigh *nb)
{
skb_queue_purge(&nb->queue);
x25_stop_t20timer(nb);
if (nb->node.next) {
list_del(&nb->node);
x25_neigh_put(nb);
}
}
void x25_link_device_down(struct net_device *dev)
{
struct x25_neigh *nb;
struct list_head *entry, *tmp;
write_lock_bh(&x25_neigh_list_lock);
list_for_each_safe(entry, tmp, &x25_neigh_list) {
nb = list_entry(entry, struct x25_neigh, node);
if (nb->dev == dev) {
__x25_remove_neigh(nb);
dev_put(dev);
}
}
write_unlock_bh(&x25_neigh_list_lock);
}
struct x25_neigh *x25_get_neigh(struct net_device *dev)
{
struct x25_neigh *nb, *use = NULL;
struct list_head *entry;
read_lock_bh(&x25_neigh_list_lock);
list_for_each(entry, &x25_neigh_list) {
nb = list_entry(entry, struct x25_neigh, node);
if (nb->dev == dev) {
use = nb;
break;
}
}
if (use)
x25_neigh_hold(use);
read_unlock_bh(&x25_neigh_list_lock);
return use;
}
int x25_subscr_ioctl(unsigned int cmd, void __user *arg)
{
struct x25_subscrip_struct x25_subscr;
struct x25_neigh *nb;
struct net_device *dev;
int rc = -EINVAL;
if (cmd != SIOCX25GSUBSCRIP && cmd != SIOCX25SSUBSCRIP)
goto out;
rc = -EFAULT;
if (copy_from_user(&x25_subscr, arg, sizeof(x25_subscr)))
goto out;
rc = -EINVAL;
if ((dev = x25_dev_get(x25_subscr.device)) == NULL)
goto out;
if ((nb = x25_get_neigh(dev)) == NULL)
goto out_dev_put;
dev_put(dev);
if (cmd == SIOCX25GSUBSCRIP) {
read_lock_bh(&x25_neigh_list_lock);
x25_subscr.extended = nb->extended;
x25_subscr.global_facil_mask = nb->global_facil_mask;
read_unlock_bh(&x25_neigh_list_lock);
rc = copy_to_user(arg, &x25_subscr,
sizeof(x25_subscr)) ? -EFAULT : 0;
} else {
rc = -EINVAL;
if (!(x25_subscr.extended && x25_subscr.extended != 1)) {
rc = 0;
write_lock_bh(&x25_neigh_list_lock);
nb->extended = x25_subscr.extended;
nb->global_facil_mask = x25_subscr.global_facil_mask;
write_unlock_bh(&x25_neigh_list_lock);
}
}
x25_neigh_put(nb);
out:
return rc;
out_dev_put:
dev_put(dev);
goto out;
}
void __exit x25_link_free(void)
{
struct x25_neigh *nb;
struct list_head *entry, *tmp;
write_lock_bh(&x25_neigh_list_lock);
list_for_each_safe(entry, tmp, &x25_neigh_list) {
struct net_device *dev;
nb = list_entry(entry, struct x25_neigh, node);
dev = nb->dev;
__x25_remove_neigh(nb);
dev_put(dev);
}
write_unlock_bh(&x25_neigh_list_lock);
}
