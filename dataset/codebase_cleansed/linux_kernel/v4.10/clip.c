static int to_atmarpd(enum atmarp_ctrl_type type, int itf, __be32 ip)
{
struct sock *sk;
struct atmarp_ctrl *ctrl;
struct sk_buff *skb;
pr_debug("(%d)\n", type);
if (!atmarpd)
return -EUNATCH;
skb = alloc_skb(sizeof(struct atmarp_ctrl), GFP_ATOMIC);
if (!skb)
return -ENOMEM;
ctrl = (struct atmarp_ctrl *)skb_put(skb, sizeof(struct atmarp_ctrl));
ctrl->type = type;
ctrl->itf_num = itf;
ctrl->ip = ip;
atm_force_charge(atmarpd, skb->truesize);
sk = sk_atm(atmarpd);
skb_queue_tail(&sk->sk_receive_queue, skb);
sk->sk_data_ready(sk);
return 0;
}
static void link_vcc(struct clip_vcc *clip_vcc, struct atmarp_entry *entry)
{
pr_debug("%p to entry %p (neigh %p)\n", clip_vcc, entry, entry->neigh);
clip_vcc->entry = entry;
clip_vcc->xoff = 0;
clip_vcc->next = entry->vccs;
entry->vccs = clip_vcc;
entry->neigh->used = jiffies;
}
static void unlink_clip_vcc(struct clip_vcc *clip_vcc)
{
struct atmarp_entry *entry = clip_vcc->entry;
struct clip_vcc **walk;
if (!entry) {
pr_crit("!clip_vcc->entry (clip_vcc %p)\n", clip_vcc);
return;
}
netif_tx_lock_bh(entry->neigh->dev);
entry->neigh->used = jiffies;
for (walk = &entry->vccs; *walk; walk = &(*walk)->next)
if (*walk == clip_vcc) {
int error;
*walk = clip_vcc->next;
clip_vcc->entry = NULL;
if (clip_vcc->xoff)
netif_wake_queue(entry->neigh->dev);
if (entry->vccs)
goto out;
entry->expires = jiffies - 1;
error = neigh_update(entry->neigh, NULL, NUD_NONE,
NEIGH_UPDATE_F_ADMIN);
if (error)
pr_crit("neigh_update failed with %d\n", error);
goto out;
}
pr_crit("ATMARP: failed (entry %p, vcc 0x%p)\n", entry, clip_vcc);
out:
netif_tx_unlock_bh(entry->neigh->dev);
}
static int neigh_check_cb(struct neighbour *n)
{
struct atmarp_entry *entry = neighbour_priv(n);
struct clip_vcc *cv;
if (n->ops != &clip_neigh_ops)
return 0;
for (cv = entry->vccs; cv; cv = cv->next) {
unsigned long exp = cv->last_use + cv->idle_timeout;
if (cv->idle_timeout && time_after(jiffies, exp)) {
pr_debug("releasing vcc %p->%p of entry %p\n",
cv, cv->vcc, entry);
vcc_release_async(cv->vcc, -ETIMEDOUT);
}
}
if (entry->vccs || time_before(jiffies, entry->expires))
return 0;
if (atomic_read(&n->refcnt) > 1) {
struct sk_buff *skb;
pr_debug("destruction postponed with ref %d\n",
atomic_read(&n->refcnt));
while ((skb = skb_dequeue(&n->arp_queue)) != NULL)
dev_kfree_skb(skb);
return 0;
}
pr_debug("expired neigh %p\n", n);
return 1;
}
static void idle_timer_check(unsigned long dummy)
{
write_lock(&arp_tbl.lock);
__neigh_for_each_release(&arp_tbl, neigh_check_cb);
mod_timer(&idle_timer, jiffies + CLIP_CHECK_INTERVAL * HZ);
write_unlock(&arp_tbl.lock);
}
static int clip_arp_rcv(struct sk_buff *skb)
{
struct atm_vcc *vcc;
pr_debug("\n");
vcc = ATM_SKB(skb)->vcc;
if (!vcc || !atm_charge(vcc, skb->truesize)) {
dev_kfree_skb_any(skb);
return 0;
}
pr_debug("pushing to %p\n", vcc);
pr_debug("using %p\n", CLIP_VCC(vcc)->old_push);
CLIP_VCC(vcc)->old_push(vcc, skb);
return 0;
}
static void clip_push(struct atm_vcc *vcc, struct sk_buff *skb)
{
struct clip_vcc *clip_vcc = CLIP_VCC(vcc);
pr_debug("\n");
if (!clip_devs) {
atm_return(vcc, skb->truesize);
kfree_skb(skb);
return;
}
if (!skb) {
pr_debug("removing VCC %p\n", clip_vcc);
if (clip_vcc->entry)
unlink_clip_vcc(clip_vcc);
clip_vcc->old_push(vcc, NULL);
kfree(clip_vcc);
return;
}
atm_return(vcc, skb->truesize);
skb->dev = clip_vcc->entry ? clip_vcc->entry->neigh->dev : clip_devs;
if (!skb->dev) {
dev_kfree_skb_any(skb);
return;
}
ATM_SKB(skb)->vcc = vcc;
skb_reset_mac_header(skb);
if (!clip_vcc->encap ||
skb->len < RFC1483LLC_LEN ||
memcmp(skb->data, llc_oui, sizeof(llc_oui)))
skb->protocol = htons(ETH_P_IP);
else {
skb->protocol = ((__be16 *)skb->data)[3];
skb_pull(skb, RFC1483LLC_LEN);
if (skb->protocol == htons(ETH_P_ARP)) {
skb->dev->stats.rx_packets++;
skb->dev->stats.rx_bytes += skb->len;
clip_arp_rcv(skb);
return;
}
}
clip_vcc->last_use = jiffies;
skb->dev->stats.rx_packets++;
skb->dev->stats.rx_bytes += skb->len;
memset(ATM_SKB(skb), 0, sizeof(struct atm_skb_data));
netif_rx(skb);
}
static void clip_pop(struct atm_vcc *vcc, struct sk_buff *skb)
{
struct clip_vcc *clip_vcc = CLIP_VCC(vcc);
struct net_device *dev = skb->dev;
int old;
unsigned long flags;
pr_debug("(vcc %p)\n", vcc);
clip_vcc->old_pop(vcc, skb);
if (!dev)
return;
spin_lock_irqsave(&PRIV(dev)->xoff_lock, flags);
if (atm_may_send(vcc, 0)) {
old = xchg(&clip_vcc->xoff, 0);
if (old)
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&PRIV(dev)->xoff_lock, flags);
}
static void clip_neigh_solicit(struct neighbour *neigh, struct sk_buff *skb)
{
__be32 *ip = (__be32 *) neigh->primary_key;
pr_debug("(neigh %p, skb %p)\n", neigh, skb);
to_atmarpd(act_need, PRIV(neigh->dev)->number, *ip);
}
static void clip_neigh_error(struct neighbour *neigh, struct sk_buff *skb)
{
#ifndef CONFIG_ATM_CLIP_NO_ICMP
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_HOST_UNREACH, 0);
#endif
kfree_skb(skb);
}
static int clip_constructor(struct net_device *dev, struct neighbour *neigh)
{
struct atmarp_entry *entry = neighbour_priv(neigh);
if (neigh->tbl->family != AF_INET)
return -EINVAL;
if (neigh->type != RTN_UNICAST)
return -EINVAL;
neigh->nud_state = NUD_NONE;
neigh->ops = &clip_neigh_ops;
neigh->output = neigh->ops->output;
entry->neigh = neigh;
entry->vccs = NULL;
entry->expires = jiffies - 1;
return 0;
}
static int clip_encap(struct atm_vcc *vcc, int mode)
{
if (!CLIP_VCC(vcc))
return -EBADFD;
CLIP_VCC(vcc)->encap = mode;
return 0;
}
static netdev_tx_t clip_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct clip_priv *clip_priv = PRIV(dev);
struct dst_entry *dst = skb_dst(skb);
struct atmarp_entry *entry;
struct neighbour *n;
struct atm_vcc *vcc;
struct rtable *rt;
__be32 *daddr;
int old;
unsigned long flags;
pr_debug("(skb %p)\n", skb);
if (!dst) {
pr_err("skb_dst(skb) == NULL\n");
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
rt = (struct rtable *) dst;
if (rt->rt_gateway)
daddr = &rt->rt_gateway;
else
daddr = &ip_hdr(skb)->daddr;
n = dst_neigh_lookup(dst, daddr);
if (!n) {
pr_err("NO NEIGHBOUR !\n");
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
entry = neighbour_priv(n);
if (!entry->vccs) {
if (time_after(jiffies, entry->expires)) {
entry->expires = jiffies + ATMARP_RETRY_DELAY * HZ;
to_atmarpd(act_need, PRIV(dev)->number, *((__be32 *)n->primary_key));
}
if (entry->neigh->arp_queue.qlen < ATMARP_MAX_UNRES_PACKETS)
skb_queue_tail(&entry->neigh->arp_queue, skb);
else {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
}
goto out_release_neigh;
}
pr_debug("neigh %p, vccs %p\n", entry, entry->vccs);
ATM_SKB(skb)->vcc = vcc = entry->vccs->vcc;
pr_debug("using neighbour %p, vcc %p\n", n, vcc);
if (entry->vccs->encap) {
void *here;
here = skb_push(skb, RFC1483LLC_LEN);
memcpy(here, llc_oui, sizeof(llc_oui));
((__be16 *) here)[3] = skb->protocol;
}
atomic_add(skb->truesize, &sk_atm(vcc)->sk_wmem_alloc);
ATM_SKB(skb)->atm_options = vcc->atm_options;
entry->vccs->last_use = jiffies;
pr_debug("atm_skb(%p)->vcc(%p)->dev(%p)\n", skb, vcc, vcc->dev);
old = xchg(&entry->vccs->xoff, 1);
if (old) {
pr_warn("XOFF->XOFF transition\n");
goto out_release_neigh;
}
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
vcc->send(vcc, skb);
if (atm_may_send(vcc, 0)) {
entry->vccs->xoff = 0;
goto out_release_neigh;
}
spin_lock_irqsave(&clip_priv->xoff_lock, flags);
netif_stop_queue(dev);
barrier();
if (!entry->vccs->xoff)
netif_start_queue(dev);
spin_unlock_irqrestore(&clip_priv->xoff_lock, flags);
out_release_neigh:
neigh_release(n);
return NETDEV_TX_OK;
}
static int clip_mkip(struct atm_vcc *vcc, int timeout)
{
struct clip_vcc *clip_vcc;
if (!vcc->push)
return -EBADFD;
clip_vcc = kmalloc(sizeof(struct clip_vcc), GFP_KERNEL);
if (!clip_vcc)
return -ENOMEM;
pr_debug("%p vcc %p\n", clip_vcc, vcc);
clip_vcc->vcc = vcc;
vcc->user_back = clip_vcc;
set_bit(ATM_VF_IS_CLIP, &vcc->flags);
clip_vcc->entry = NULL;
clip_vcc->xoff = 0;
clip_vcc->encap = 1;
clip_vcc->last_use = jiffies;
clip_vcc->idle_timeout = timeout * HZ;
clip_vcc->old_push = vcc->push;
clip_vcc->old_pop = vcc->pop;
vcc->push = clip_push;
vcc->pop = clip_pop;
vcc_process_recv_queue(vcc);
return 0;
}
static int clip_setentry(struct atm_vcc *vcc, __be32 ip)
{
struct neighbour *neigh;
struct atmarp_entry *entry;
int error;
struct clip_vcc *clip_vcc;
struct rtable *rt;
if (vcc->push != clip_push) {
pr_warn("non-CLIP VCC\n");
return -EBADF;
}
clip_vcc = CLIP_VCC(vcc);
if (!ip) {
if (!clip_vcc->entry) {
pr_err("hiding hidden ATMARP entry\n");
return 0;
}
pr_debug("remove\n");
unlink_clip_vcc(clip_vcc);
return 0;
}
rt = ip_route_output(&init_net, ip, 0, 1, 0);
if (IS_ERR(rt))
return PTR_ERR(rt);
neigh = __neigh_lookup(&arp_tbl, &ip, rt->dst.dev, 1);
ip_rt_put(rt);
if (!neigh)
return -ENOMEM;
entry = neighbour_priv(neigh);
if (entry != clip_vcc->entry) {
if (!clip_vcc->entry)
pr_debug("add\n");
else {
pr_debug("update\n");
unlink_clip_vcc(clip_vcc);
}
link_vcc(clip_vcc, entry);
}
error = neigh_update(neigh, llc_oui, NUD_PERMANENT,
NEIGH_UPDATE_F_OVERRIDE | NEIGH_UPDATE_F_ADMIN);
neigh_release(neigh);
return error;
}
static void clip_setup(struct net_device *dev)
{
dev->netdev_ops = &clip_netdev_ops;
dev->type = ARPHRD_ATM;
dev->neigh_priv_len = sizeof(struct atmarp_entry);
dev->hard_header_len = RFC1483LLC_LEN;
dev->mtu = RFC1626_MTU;
dev->tx_queue_len = 100;
netif_keep_dst(dev);
}
static int clip_create(int number)
{
struct net_device *dev;
struct clip_priv *clip_priv;
int error;
if (number != -1) {
for (dev = clip_devs; dev; dev = PRIV(dev)->next)
if (PRIV(dev)->number == number)
return -EEXIST;
} else {
number = 0;
for (dev = clip_devs; dev; dev = PRIV(dev)->next)
if (PRIV(dev)->number >= number)
number = PRIV(dev)->number + 1;
}
dev = alloc_netdev(sizeof(struct clip_priv), "", NET_NAME_UNKNOWN,
clip_setup);
if (!dev)
return -ENOMEM;
clip_priv = PRIV(dev);
sprintf(dev->name, "atm%d", number);
spin_lock_init(&clip_priv->xoff_lock);
clip_priv->number = number;
error = register_netdev(dev);
if (error) {
free_netdev(dev);
return error;
}
clip_priv->next = clip_devs;
clip_devs = dev;
pr_debug("registered (net:%s)\n", dev->name);
return number;
}
static int clip_device_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
if (event == NETDEV_UNREGISTER)
return NOTIFY_DONE;
if (dev->type != ARPHRD_ATM || dev->netdev_ops != &clip_netdev_ops)
return NOTIFY_DONE;
switch (event) {
case NETDEV_UP:
pr_debug("NETDEV_UP\n");
to_atmarpd(act_up, PRIV(dev)->number, 0);
break;
case NETDEV_GOING_DOWN:
pr_debug("NETDEV_DOWN\n");
to_atmarpd(act_down, PRIV(dev)->number, 0);
break;
case NETDEV_CHANGE:
case NETDEV_CHANGEMTU:
pr_debug("NETDEV_CHANGE*\n");
to_atmarpd(act_change, PRIV(dev)->number, 0);
break;
}
return NOTIFY_DONE;
}
static int clip_inet_event(struct notifier_block *this, unsigned long event,
void *ifa)
{
struct in_device *in_dev;
struct netdev_notifier_info info;
in_dev = ((struct in_ifaddr *)ifa)->ifa_dev;
if (event != NETDEV_UP)
return NOTIFY_DONE;
netdev_notifier_info_init(&info, in_dev->dev);
return clip_device_event(this, NETDEV_CHANGE, &info);
}
static void atmarpd_close(struct atm_vcc *vcc)
{
pr_debug("\n");
rtnl_lock();
atmarpd = NULL;
skb_queue_purge(&sk_atm(vcc)->sk_receive_queue);
rtnl_unlock();
pr_debug("(done)\n");
module_put(THIS_MODULE);
}
static int atm_init_atmarp(struct atm_vcc *vcc)
{
rtnl_lock();
if (atmarpd) {
rtnl_unlock();
return -EADDRINUSE;
}
mod_timer(&idle_timer, jiffies + CLIP_CHECK_INTERVAL * HZ);
atmarpd = vcc;
set_bit(ATM_VF_META, &vcc->flags);
set_bit(ATM_VF_READY, &vcc->flags);
vcc->dev = &atmarpd_dev;
vcc_insert_socket(sk_atm(vcc));
vcc->push = NULL;
vcc->pop = NULL;
vcc->push_oam = NULL;
rtnl_unlock();
return 0;
}
static int clip_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg)
{
struct atm_vcc *vcc = ATM_SD(sock);
int err = 0;
switch (cmd) {
case SIOCMKCLIP:
case ATMARPD_CTRL:
case ATMARP_MKIP:
case ATMARP_SETENTRY:
case ATMARP_ENCAP:
if (!capable(CAP_NET_ADMIN))
return -EPERM;
break;
default:
return -ENOIOCTLCMD;
}
switch (cmd) {
case SIOCMKCLIP:
err = clip_create(arg);
break;
case ATMARPD_CTRL:
err = atm_init_atmarp(vcc);
if (!err) {
sock->state = SS_CONNECTED;
__module_get(THIS_MODULE);
}
break;
case ATMARP_MKIP:
err = clip_mkip(vcc, arg);
break;
case ATMARP_SETENTRY:
err = clip_setentry(vcc, (__force __be32)arg);
break;
case ATMARP_ENCAP:
err = clip_encap(vcc, arg);
break;
}
return err;
}
static void svc_addr(struct seq_file *seq, struct sockaddr_atmsvc *addr)
{
static int code[] = { 1, 2, 10, 6, 1, 0 };
static int e164[] = { 1, 8, 4, 6, 1, 0 };
if (*addr->sas_addr.pub) {
seq_printf(seq, "%s", addr->sas_addr.pub);
if (*addr->sas_addr.prv)
seq_putc(seq, '+');
} else if (!*addr->sas_addr.prv) {
seq_printf(seq, "%s", "(none)");
return;
}
if (*addr->sas_addr.prv) {
unsigned char *prv = addr->sas_addr.prv;
int *fields;
int i, j;
fields = *prv == ATM_AFI_E164 ? e164 : code;
for (i = 0; fields[i]; i++) {
for (j = fields[i]; j; j--)
seq_printf(seq, "%02X", *prv++);
if (fields[i + 1])
seq_putc(seq, '.');
}
}
}
static void atmarp_info(struct seq_file *seq, struct neighbour *n,
struct atmarp_entry *entry, struct clip_vcc *clip_vcc)
{
struct net_device *dev = n->dev;
unsigned long exp;
char buf[17];
int svc, llc, off;
svc = ((clip_vcc == SEQ_NO_VCC_TOKEN) ||
(sk_atm(clip_vcc->vcc)->sk_family == AF_ATMSVC));
llc = ((clip_vcc == SEQ_NO_VCC_TOKEN) || clip_vcc->encap);
if (clip_vcc == SEQ_NO_VCC_TOKEN)
exp = entry->neigh->used;
else
exp = clip_vcc->last_use;
exp = (jiffies - exp) / HZ;
seq_printf(seq, "%-6s%-4s%-4s%5ld ",
dev->name, svc ? "SVC" : "PVC", llc ? "LLC" : "NULL", exp);
off = scnprintf(buf, sizeof(buf) - 1, "%pI4", n->primary_key);
while (off < 16)
buf[off++] = ' ';
buf[off] = '\0';
seq_printf(seq, "%s", buf);
if (clip_vcc == SEQ_NO_VCC_TOKEN) {
if (time_before(jiffies, entry->expires))
seq_printf(seq, "(resolving)\n");
else
seq_printf(seq, "(expired, ref %d)\n",
atomic_read(&entry->neigh->refcnt));
} else if (!svc) {
seq_printf(seq, "%d.%d.%d\n",
clip_vcc->vcc->dev->number,
clip_vcc->vcc->vpi, clip_vcc->vcc->vci);
} else {
svc_addr(seq, &clip_vcc->vcc->remote);
seq_putc(seq, '\n');
}
}
static struct clip_vcc *clip_seq_next_vcc(struct atmarp_entry *e,
struct clip_vcc *curr)
{
if (!curr) {
curr = e->vccs;
if (!curr)
return SEQ_NO_VCC_TOKEN;
return curr;
}
if (curr == SEQ_NO_VCC_TOKEN)
return NULL;
curr = curr->next;
return curr;
}
static void *clip_seq_vcc_walk(struct clip_seq_state *state,
struct atmarp_entry *e, loff_t * pos)
{
struct clip_vcc *vcc = state->vcc;
vcc = clip_seq_next_vcc(e, vcc);
if (vcc && pos != NULL) {
while (*pos) {
vcc = clip_seq_next_vcc(e, vcc);
if (!vcc)
break;
--(*pos);
}
}
state->vcc = vcc;
return vcc;
}
static void *clip_seq_sub_iter(struct neigh_seq_state *_state,
struct neighbour *n, loff_t * pos)
{
struct clip_seq_state *state = (struct clip_seq_state *)_state;
if (n->dev->type != ARPHRD_ATM)
return NULL;
return clip_seq_vcc_walk(state, neighbour_priv(n), pos);
}
static void *clip_seq_start(struct seq_file *seq, loff_t * pos)
{
struct clip_seq_state *state = seq->private;
state->ns.neigh_sub_iter = clip_seq_sub_iter;
return neigh_seq_start(seq, pos, &arp_tbl, NEIGH_SEQ_NEIGH_ONLY);
}
static int clip_seq_show(struct seq_file *seq, void *v)
{
static char atm_arp_banner[] =
"IPitf TypeEncp Idle IP address ATM address\n";
if (v == SEQ_START_TOKEN) {
seq_puts(seq, atm_arp_banner);
} else {
struct clip_seq_state *state = seq->private;
struct clip_vcc *vcc = state->vcc;
struct neighbour *n = v;
atmarp_info(seq, n, neighbour_priv(n), vcc);
}
return 0;
}
static int arp_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &arp_seq_ops,
sizeof(struct clip_seq_state));
}
static int __init atm_clip_init(void)
{
register_atm_ioctl(&clip_ioctl_ops);
register_netdevice_notifier(&clip_dev_notifier);
register_inetaddr_notifier(&clip_inet_notifier);
setup_timer(&idle_timer, idle_timer_check, 0);
#ifdef CONFIG_PROC_FS
{
struct proc_dir_entry *p;
p = proc_create("arp", S_IRUGO, atm_proc_root, &arp_seq_fops);
if (!p) {
pr_err("Unable to initialize /proc/net/atm/arp\n");
atm_clip_exit_noproc();
return -ENOMEM;
}
}
#endif
return 0;
}
static void atm_clip_exit_noproc(void)
{
struct net_device *dev, *next;
unregister_inetaddr_notifier(&clip_inet_notifier);
unregister_netdevice_notifier(&clip_dev_notifier);
deregister_atm_ioctl(&clip_ioctl_ops);
del_timer_sync(&idle_timer);
dev = clip_devs;
while (dev) {
next = PRIV(dev)->next;
unregister_netdev(dev);
free_netdev(dev);
dev = next;
}
}
static void __exit atm_clip_exit(void)
{
remove_proc_entry("arp", atm_proc_root);
atm_clip_exit_noproc();
}
