static inline struct ppp_net *ppp_pernet(struct net *net)
{
BUG_ON(!net);
return net_generic(net, ppp_net_id);
}
static inline int proto_to_npindex(int proto)
{
switch (proto) {
case PPP_IP:
return NP_IP;
case PPP_IPV6:
return NP_IPV6;
case PPP_IPX:
return NP_IPX;
case PPP_AT:
return NP_AT;
case PPP_MPLS_UC:
return NP_MPLS_UC;
case PPP_MPLS_MC:
return NP_MPLS_MC;
}
return -EINVAL;
}
static inline int ethertype_to_npindex(int ethertype)
{
switch (ethertype) {
case ETH_P_IP:
return NP_IP;
case ETH_P_IPV6:
return NP_IPV6;
case ETH_P_IPX:
return NP_IPX;
case ETH_P_PPPTALK:
case ETH_P_ATALK:
return NP_AT;
case ETH_P_MPLS_UC:
return NP_MPLS_UC;
case ETH_P_MPLS_MC:
return NP_MPLS_MC;
}
return -1;
}
static int ppp_open(struct inode *inode, struct file *file)
{
if (!capable(CAP_NET_ADMIN))
return -EPERM;
return 0;
}
static int ppp_release(struct inode *unused, struct file *file)
{
struct ppp_file *pf = file->private_data;
struct ppp *ppp;
if (pf) {
file->private_data = NULL;
if (pf->kind == INTERFACE) {
ppp = PF_TO_PPP(pf);
rtnl_lock();
if (file == ppp->owner)
unregister_netdevice(ppp->dev);
rtnl_unlock();
}
if (atomic_dec_and_test(&pf->refcnt)) {
switch (pf->kind) {
case INTERFACE:
ppp_destroy_interface(PF_TO_PPP(pf));
break;
case CHANNEL:
ppp_destroy_channel(PF_TO_CHANNEL(pf));
break;
}
}
}
return 0;
}
static ssize_t ppp_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct ppp_file *pf = file->private_data;
DECLARE_WAITQUEUE(wait, current);
ssize_t ret;
struct sk_buff *skb = NULL;
struct iovec iov;
struct iov_iter to;
ret = count;
if (!pf)
return -ENXIO;
add_wait_queue(&pf->rwait, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
skb = skb_dequeue(&pf->rq);
if (skb)
break;
ret = 0;
if (pf->dead)
break;
if (pf->kind == INTERFACE) {
struct ppp *ppp = PF_TO_PPP(pf);
ppp_recv_lock(ppp);
if (ppp->n_channels == 0 &&
(ppp->flags & SC_LOOP_TRAFFIC) == 0) {
ppp_recv_unlock(ppp);
break;
}
ppp_recv_unlock(ppp);
}
ret = -EAGAIN;
if (file->f_flags & O_NONBLOCK)
break;
ret = -ERESTARTSYS;
if (signal_pending(current))
break;
schedule();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&pf->rwait, &wait);
if (!skb)
goto out;
ret = -EOVERFLOW;
if (skb->len > count)
goto outf;
ret = -EFAULT;
iov.iov_base = buf;
iov.iov_len = count;
iov_iter_init(&to, READ, &iov, 1, count);
if (skb_copy_datagram_iter(skb, 0, &to, skb->len))
goto outf;
ret = skb->len;
outf:
kfree_skb(skb);
out:
return ret;
}
static ssize_t ppp_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct ppp_file *pf = file->private_data;
struct sk_buff *skb;
ssize_t ret;
if (!pf)
return -ENXIO;
ret = -ENOMEM;
skb = alloc_skb(count + pf->hdrlen, GFP_KERNEL);
if (!skb)
goto out;
skb_reserve(skb, pf->hdrlen);
ret = -EFAULT;
if (copy_from_user(skb_put(skb, count), buf, count)) {
kfree_skb(skb);
goto out;
}
skb_queue_tail(&pf->xq, skb);
switch (pf->kind) {
case INTERFACE:
ppp_xmit_process(PF_TO_PPP(pf));
break;
case CHANNEL:
ppp_channel_push(PF_TO_CHANNEL(pf));
break;
}
ret = count;
out:
return ret;
}
static unsigned int ppp_poll(struct file *file, poll_table *wait)
{
struct ppp_file *pf = file->private_data;
unsigned int mask;
if (!pf)
return 0;
poll_wait(file, &pf->rwait, wait);
mask = POLLOUT | POLLWRNORM;
if (skb_peek(&pf->rq))
mask |= POLLIN | POLLRDNORM;
if (pf->dead)
mask |= POLLHUP;
else if (pf->kind == INTERFACE) {
struct ppp *ppp = PF_TO_PPP(pf);
ppp_recv_lock(ppp);
if (ppp->n_channels == 0 &&
(ppp->flags & SC_LOOP_TRAFFIC) == 0)
mask |= POLLIN | POLLRDNORM;
ppp_recv_unlock(ppp);
}
return mask;
}
static int get_filter(void __user *arg, struct sock_filter **p)
{
struct sock_fprog uprog;
struct sock_filter *code = NULL;
int len;
if (copy_from_user(&uprog, arg, sizeof(uprog)))
return -EFAULT;
if (!uprog.len) {
*p = NULL;
return 0;
}
len = uprog.len * sizeof(struct sock_filter);
code = memdup_user(uprog.filter, len);
if (IS_ERR(code))
return PTR_ERR(code);
*p = code;
return uprog.len;
}
static long ppp_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct ppp_file *pf;
struct ppp *ppp;
int err = -EFAULT, val, val2, i;
struct ppp_idle idle;
struct npioctl npi;
int unit, cflags;
struct slcompress *vj;
void __user *argp = (void __user *)arg;
int __user *p = argp;
mutex_lock(&ppp_mutex);
pf = file->private_data;
if (!pf) {
err = ppp_unattached_ioctl(current->nsproxy->net_ns,
pf, file, cmd, arg);
goto out;
}
if (cmd == PPPIOCDETACH) {
err = -EINVAL;
if (pf->kind == INTERFACE) {
ppp = PF_TO_PPP(pf);
rtnl_lock();
if (file == ppp->owner)
unregister_netdevice(ppp->dev);
rtnl_unlock();
}
if (atomic_long_read(&file->f_count) < 2) {
ppp_release(NULL, file);
err = 0;
} else
pr_warn("PPPIOCDETACH file->f_count=%ld\n",
atomic_long_read(&file->f_count));
goto out;
}
if (pf->kind == CHANNEL) {
struct channel *pch;
struct ppp_channel *chan;
pch = PF_TO_CHANNEL(pf);
switch (cmd) {
case PPPIOCCONNECT:
if (get_user(unit, p))
break;
err = ppp_connect_channel(pch, unit);
break;
case PPPIOCDISCONN:
err = ppp_disconnect_channel(pch);
break;
default:
down_read(&pch->chan_sem);
chan = pch->chan;
err = -ENOTTY;
if (chan && chan->ops->ioctl)
err = chan->ops->ioctl(chan, cmd, arg);
up_read(&pch->chan_sem);
}
goto out;
}
if (pf->kind != INTERFACE) {
pr_err("PPP: not interface or channel??\n");
err = -EINVAL;
goto out;
}
ppp = PF_TO_PPP(pf);
switch (cmd) {
case PPPIOCSMRU:
if (get_user(val, p))
break;
ppp->mru = val;
err = 0;
break;
case PPPIOCSFLAGS:
if (get_user(val, p))
break;
ppp_lock(ppp);
cflags = ppp->flags & ~val;
#ifdef CONFIG_PPP_MULTILINK
if (!(ppp->flags & SC_MULTILINK) && (val & SC_MULTILINK))
ppp->nextseq = 0;
#endif
ppp->flags = val & SC_FLAG_BITS;
ppp_unlock(ppp);
if (cflags & SC_CCP_OPEN)
ppp_ccp_closed(ppp);
err = 0;
break;
case PPPIOCGFLAGS:
val = ppp->flags | ppp->xstate | ppp->rstate;
if (put_user(val, p))
break;
err = 0;
break;
case PPPIOCSCOMPRESS:
err = ppp_set_compress(ppp, arg);
break;
case PPPIOCGUNIT:
if (put_user(ppp->file.index, p))
break;
err = 0;
break;
case PPPIOCSDEBUG:
if (get_user(val, p))
break;
ppp->debug = val;
err = 0;
break;
case PPPIOCGDEBUG:
if (put_user(ppp->debug, p))
break;
err = 0;
break;
case PPPIOCGIDLE:
idle.xmit_idle = (jiffies - ppp->last_xmit) / HZ;
idle.recv_idle = (jiffies - ppp->last_recv) / HZ;
if (copy_to_user(argp, &idle, sizeof(idle)))
break;
err = 0;
break;
case PPPIOCSMAXCID:
if (get_user(val, p))
break;
val2 = 15;
if ((val >> 16) != 0) {
val2 = val >> 16;
val &= 0xffff;
}
vj = slhc_init(val2+1, val+1);
if (IS_ERR(vj)) {
err = PTR_ERR(vj);
break;
}
ppp_lock(ppp);
if (ppp->vj)
slhc_free(ppp->vj);
ppp->vj = vj;
ppp_unlock(ppp);
err = 0;
break;
case PPPIOCGNPMODE:
case PPPIOCSNPMODE:
if (copy_from_user(&npi, argp, sizeof(npi)))
break;
err = proto_to_npindex(npi.protocol);
if (err < 0)
break;
i = err;
if (cmd == PPPIOCGNPMODE) {
err = -EFAULT;
npi.mode = ppp->npmode[i];
if (copy_to_user(argp, &npi, sizeof(npi)))
break;
} else {
ppp->npmode[i] = npi.mode;
netif_wake_queue(ppp->dev);
}
err = 0;
break;
#ifdef CONFIG_PPP_FILTER
case PPPIOCSPASS:
{
struct sock_filter *code;
err = get_filter(argp, &code);
if (err >= 0) {
struct bpf_prog *pass_filter = NULL;
struct sock_fprog_kern fprog = {
.len = err,
.filter = code,
};
err = 0;
if (fprog.filter)
err = bpf_prog_create(&pass_filter, &fprog);
if (!err) {
ppp_lock(ppp);
if (ppp->pass_filter)
bpf_prog_destroy(ppp->pass_filter);
ppp->pass_filter = pass_filter;
ppp_unlock(ppp);
}
kfree(code);
}
break;
}
case PPPIOCSACTIVE:
{
struct sock_filter *code;
err = get_filter(argp, &code);
if (err >= 0) {
struct bpf_prog *active_filter = NULL;
struct sock_fprog_kern fprog = {
.len = err,
.filter = code,
};
err = 0;
if (fprog.filter)
err = bpf_prog_create(&active_filter, &fprog);
if (!err) {
ppp_lock(ppp);
if (ppp->active_filter)
bpf_prog_destroy(ppp->active_filter);
ppp->active_filter = active_filter;
ppp_unlock(ppp);
}
kfree(code);
}
break;
}
#endif
#ifdef CONFIG_PPP_MULTILINK
case PPPIOCSMRRU:
if (get_user(val, p))
break;
ppp_recv_lock(ppp);
ppp->mrru = val;
ppp_recv_unlock(ppp);
err = 0;
break;
#endif
default:
err = -ENOTTY;
}
out:
mutex_unlock(&ppp_mutex);
return err;
}
static int ppp_unattached_ioctl(struct net *net, struct ppp_file *pf,
struct file *file, unsigned int cmd, unsigned long arg)
{
int unit, err = -EFAULT;
struct ppp *ppp;
struct channel *chan;
struct ppp_net *pn;
int __user *p = (int __user *)arg;
switch (cmd) {
case PPPIOCNEWUNIT:
if (get_user(unit, p))
break;
ppp = ppp_create_interface(net, unit, file, &err);
if (!ppp)
break;
file->private_data = &ppp->file;
err = -EFAULT;
if (put_user(ppp->file.index, p))
break;
err = 0;
break;
case PPPIOCATTACH:
if (get_user(unit, p))
break;
err = -ENXIO;
pn = ppp_pernet(net);
mutex_lock(&pn->all_ppp_mutex);
ppp = ppp_find_unit(pn, unit);
if (ppp) {
atomic_inc(&ppp->file.refcnt);
file->private_data = &ppp->file;
err = 0;
}
mutex_unlock(&pn->all_ppp_mutex);
break;
case PPPIOCATTCHAN:
if (get_user(unit, p))
break;
err = -ENXIO;
pn = ppp_pernet(net);
spin_lock_bh(&pn->all_channels_lock);
chan = ppp_find_channel(pn, unit);
if (chan) {
atomic_inc(&chan->file.refcnt);
file->private_data = &chan->file;
err = 0;
}
spin_unlock_bh(&pn->all_channels_lock);
break;
default:
err = -ENOTTY;
}
return err;
}
static __net_init int ppp_init_net(struct net *net)
{
struct ppp_net *pn = net_generic(net, ppp_net_id);
idr_init(&pn->units_idr);
mutex_init(&pn->all_ppp_mutex);
INIT_LIST_HEAD(&pn->all_channels);
INIT_LIST_HEAD(&pn->new_channels);
spin_lock_init(&pn->all_channels_lock);
return 0;
}
static __net_exit void ppp_exit_net(struct net *net)
{
struct ppp_net *pn = net_generic(net, ppp_net_id);
struct net_device *dev;
struct net_device *aux;
struct ppp *ppp;
LIST_HEAD(list);
int id;
rtnl_lock();
for_each_netdev_safe(net, dev, aux) {
if (dev->netdev_ops == &ppp_netdev_ops)
unregister_netdevice_queue(dev, &list);
}
idr_for_each_entry(&pn->units_idr, ppp, id)
if (!net_eq(dev_net(ppp->dev), net))
unregister_netdevice_queue(ppp->dev, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
idr_destroy(&pn->units_idr);
}
static int __init ppp_init(void)
{
int err;
pr_info("PPP generic driver version " PPP_VERSION "\n");
err = register_pernet_device(&ppp_net_ops);
if (err) {
pr_err("failed to register PPP pernet device (%d)\n", err);
goto out;
}
err = register_chrdev(PPP_MAJOR, "ppp", &ppp_device_fops);
if (err) {
pr_err("failed to register PPP device (%d)\n", err);
goto out_net;
}
ppp_class = class_create(THIS_MODULE, "ppp");
if (IS_ERR(ppp_class)) {
err = PTR_ERR(ppp_class);
goto out_chrdev;
}
device_create(ppp_class, NULL, MKDEV(PPP_MAJOR, 0), NULL, "ppp");
return 0;
out_chrdev:
unregister_chrdev(PPP_MAJOR, "ppp");
out_net:
unregister_pernet_device(&ppp_net_ops);
out:
return err;
}
static netdev_tx_t
ppp_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ppp *ppp = netdev_priv(dev);
int npi, proto;
unsigned char *pp;
npi = ethertype_to_npindex(ntohs(skb->protocol));
if (npi < 0)
goto outf;
switch (ppp->npmode[npi]) {
case NPMODE_PASS:
break;
case NPMODE_QUEUE:
goto outf;
case NPMODE_DROP:
case NPMODE_ERROR:
goto outf;
}
if (skb_cow_head(skb, PPP_HDRLEN))
goto outf;
pp = skb_push(skb, 2);
proto = npindex_to_proto[npi];
put_unaligned_be16(proto, pp);
skb_scrub_packet(skb, !net_eq(ppp->ppp_net, dev_net(dev)));
skb_queue_tail(&ppp->file.xq, skb);
ppp_xmit_process(ppp);
return NETDEV_TX_OK;
outf:
kfree_skb(skb);
++dev->stats.tx_dropped;
return NETDEV_TX_OK;
}
static int
ppp_net_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct ppp *ppp = netdev_priv(dev);
int err = -EFAULT;
void __user *addr = (void __user *) ifr->ifr_ifru.ifru_data;
struct ppp_stats stats;
struct ppp_comp_stats cstats;
char *vers;
switch (cmd) {
case SIOCGPPPSTATS:
ppp_get_stats(ppp, &stats);
if (copy_to_user(addr, &stats, sizeof(stats)))
break;
err = 0;
break;
case SIOCGPPPCSTATS:
memset(&cstats, 0, sizeof(cstats));
if (ppp->xc_state)
ppp->xcomp->comp_stat(ppp->xc_state, &cstats.c);
if (ppp->rc_state)
ppp->rcomp->decomp_stat(ppp->rc_state, &cstats.d);
if (copy_to_user(addr, &cstats, sizeof(cstats)))
break;
err = 0;
break;
case SIOCGPPPVER:
vers = PPP_VERSION;
if (copy_to_user(addr, vers, strlen(vers) + 1))
break;
err = 0;
break;
default:
err = -EINVAL;
}
return err;
}
static struct rtnl_link_stats64*
ppp_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats64)
{
struct ppp *ppp = netdev_priv(dev);
ppp_recv_lock(ppp);
stats64->rx_packets = ppp->stats64.rx_packets;
stats64->rx_bytes = ppp->stats64.rx_bytes;
ppp_recv_unlock(ppp);
ppp_xmit_lock(ppp);
stats64->tx_packets = ppp->stats64.tx_packets;
stats64->tx_bytes = ppp->stats64.tx_bytes;
ppp_xmit_unlock(ppp);
stats64->rx_errors = dev->stats.rx_errors;
stats64->tx_errors = dev->stats.tx_errors;
stats64->rx_dropped = dev->stats.rx_dropped;
stats64->tx_dropped = dev->stats.tx_dropped;
stats64->rx_length_errors = dev->stats.rx_length_errors;
return stats64;
}
static int ppp_dev_init(struct net_device *dev)
{
dev->qdisc_tx_busylock = &ppp_tx_busylock;
return 0;
}
static void ppp_dev_uninit(struct net_device *dev)
{
struct ppp *ppp = netdev_priv(dev);
struct ppp_net *pn = ppp_pernet(ppp->ppp_net);
ppp_lock(ppp);
ppp->closing = 1;
ppp_unlock(ppp);
mutex_lock(&pn->all_ppp_mutex);
unit_put(&pn->units_idr, ppp->file.index);
mutex_unlock(&pn->all_ppp_mutex);
ppp->owner = NULL;
ppp->file.dead = 1;
wake_up_interruptible(&ppp->file.rwait);
}
static void ppp_setup(struct net_device *dev)
{
dev->netdev_ops = &ppp_netdev_ops;
SET_NETDEV_DEVTYPE(dev, &ppp_type);
dev->hard_header_len = PPP_HDRLEN;
dev->mtu = PPP_MRU;
dev->addr_len = 0;
dev->tx_queue_len = 3;
dev->type = ARPHRD_PPP;
dev->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
netif_keep_dst(dev);
}
static void
ppp_xmit_process(struct ppp *ppp)
{
struct sk_buff *skb;
ppp_xmit_lock(ppp);
if (!ppp->closing) {
ppp_push(ppp);
while (!ppp->xmit_pending &&
(skb = skb_dequeue(&ppp->file.xq)))
ppp_send_frame(ppp, skb);
if (!ppp->xmit_pending && !skb_peek(&ppp->file.xq))
netif_wake_queue(ppp->dev);
else
netif_stop_queue(ppp->dev);
}
ppp_xmit_unlock(ppp);
}
static inline struct sk_buff *
pad_compress_skb(struct ppp *ppp, struct sk_buff *skb)
{
struct sk_buff *new_skb;
int len;
int new_skb_size = ppp->dev->mtu +
ppp->xcomp->comp_extra + ppp->dev->hard_header_len;
int compressor_skb_size = ppp->dev->mtu +
ppp->xcomp->comp_extra + PPP_HDRLEN;
new_skb = alloc_skb(new_skb_size, GFP_ATOMIC);
if (!new_skb) {
if (net_ratelimit())
netdev_err(ppp->dev, "PPP: no memory (comp pkt)\n");
return NULL;
}
if (ppp->dev->hard_header_len > PPP_HDRLEN)
skb_reserve(new_skb,
ppp->dev->hard_header_len - PPP_HDRLEN);
len = ppp->xcomp->compress(ppp->xc_state, skb->data - 2,
new_skb->data, skb->len + 2,
compressor_skb_size);
if (len > 0 && (ppp->flags & SC_CCP_UP)) {
consume_skb(skb);
skb = new_skb;
skb_put(skb, len);
skb_pull(skb, 2);
} else if (len == 0) {
consume_skb(new_skb);
new_skb = skb;
} else {
if (net_ratelimit())
netdev_err(ppp->dev, "ppp: compressor dropped pkt\n");
kfree_skb(skb);
consume_skb(new_skb);
new_skb = NULL;
}
return new_skb;
}
static void
ppp_send_frame(struct ppp *ppp, struct sk_buff *skb)
{
int proto = PPP_PROTO(skb);
struct sk_buff *new_skb;
int len;
unsigned char *cp;
if (proto < 0x8000) {
#ifdef CONFIG_PPP_FILTER
*skb_push(skb, 2) = 1;
if (ppp->pass_filter &&
BPF_PROG_RUN(ppp->pass_filter, skb) == 0) {
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
"PPP: outbound frame "
"not passed\n");
kfree_skb(skb);
return;
}
if (!(ppp->active_filter &&
BPF_PROG_RUN(ppp->active_filter, skb) == 0))
ppp->last_xmit = jiffies;
skb_pull(skb, 2);
#else
ppp->last_xmit = jiffies;
#endif
}
++ppp->stats64.tx_packets;
ppp->stats64.tx_bytes += skb->len - 2;
switch (proto) {
case PPP_IP:
if (!ppp->vj || (ppp->flags & SC_COMP_TCP) == 0)
break;
new_skb = alloc_skb(skb->len + ppp->dev->hard_header_len - 2,
GFP_ATOMIC);
if (!new_skb) {
netdev_err(ppp->dev, "PPP: no memory (VJ comp pkt)\n");
goto drop;
}
skb_reserve(new_skb, ppp->dev->hard_header_len - 2);
cp = skb->data + 2;
len = slhc_compress(ppp->vj, cp, skb->len - 2,
new_skb->data + 2, &cp,
!(ppp->flags & SC_NO_TCP_CCID));
if (cp == skb->data + 2) {
consume_skb(new_skb);
} else {
if (cp[0] & SL_TYPE_COMPRESSED_TCP) {
proto = PPP_VJC_COMP;
cp[0] &= ~SL_TYPE_COMPRESSED_TCP;
} else {
proto = PPP_VJC_UNCOMP;
cp[0] = skb->data[2];
}
consume_skb(skb);
skb = new_skb;
cp = skb_put(skb, len + 2);
cp[0] = 0;
cp[1] = proto;
}
break;
case PPP_CCP:
ppp_ccp_peek(ppp, skb, 0);
break;
}
if ((ppp->xstate & SC_COMP_RUN) && ppp->xc_state &&
proto != PPP_LCP && proto != PPP_CCP) {
if (!(ppp->flags & SC_CCP_UP) && (ppp->flags & SC_MUST_COMP)) {
if (net_ratelimit())
netdev_err(ppp->dev,
"ppp: compression required but "
"down - pkt dropped.\n");
goto drop;
}
skb = pad_compress_skb(ppp, skb);
if (!skb)
goto drop;
}
if (ppp->flags & SC_LOOP_TRAFFIC) {
if (ppp->file.rq.qlen > PPP_MAX_RQLEN)
goto drop;
skb_queue_tail(&ppp->file.rq, skb);
wake_up_interruptible(&ppp->file.rwait);
return;
}
ppp->xmit_pending = skb;
ppp_push(ppp);
return;
drop:
kfree_skb(skb);
++ppp->dev->stats.tx_errors;
}
static void
ppp_push(struct ppp *ppp)
{
struct list_head *list;
struct channel *pch;
struct sk_buff *skb = ppp->xmit_pending;
if (!skb)
return;
list = &ppp->channels;
if (list_empty(list)) {
ppp->xmit_pending = NULL;
kfree_skb(skb);
return;
}
if ((ppp->flags & SC_MULTILINK) == 0) {
list = list->next;
pch = list_entry(list, struct channel, clist);
spin_lock_bh(&pch->downl);
if (pch->chan) {
if (pch->chan->ops->start_xmit(pch->chan, skb))
ppp->xmit_pending = NULL;
} else {
kfree_skb(skb);
ppp->xmit_pending = NULL;
}
spin_unlock_bh(&pch->downl);
return;
}
#ifdef CONFIG_PPP_MULTILINK
if (!ppp_mp_explode(ppp, skb))
return;
#endif
ppp->xmit_pending = NULL;
kfree_skb(skb);
}
static int ppp_mp_explode(struct ppp *ppp, struct sk_buff *skb)
{
int len, totlen;
int i, bits, hdrlen, mtu;
int flen;
int navail, nfree, nzero;
int nbigger;
int totspeed;
int totfree;
unsigned char *p, *q;
struct list_head *list;
struct channel *pch;
struct sk_buff *frag;
struct ppp_channel *chan;
totspeed = 0;
nfree = 0;
navail = 0;
nzero = 0;
totfree = 0;
hdrlen = (ppp->flags & SC_MP_XSHORTSEQ)? MPHDRLEN_SSN: MPHDRLEN;
i = 0;
list_for_each_entry(pch, &ppp->channels, clist) {
if (pch->chan) {
pch->avail = 1;
navail++;
pch->speed = pch->chan->speed;
} else {
pch->avail = 0;
}
if (pch->avail) {
if (skb_queue_empty(&pch->file.xq) ||
!pch->had_frag) {
if (pch->speed == 0)
nzero++;
else
totspeed += pch->speed;
pch->avail = 2;
++nfree;
++totfree;
}
if (!pch->had_frag && i < ppp->nxchan)
ppp->nxchan = i;
}
++i;
}
if (nfree == 0 || nfree < navail / 2)
return 0;
p = skb->data;
len = skb->len;
if (*p == 0 && mp_protocol_compress) {
++p;
--len;
}
totlen = len;
nbigger = len % nfree;
list = &ppp->channels;
for (i = 0; i < ppp->nxchan; ++i) {
list = list->next;
if (list == &ppp->channels) {
i = 0;
break;
}
}
bits = B;
while (len > 0) {
list = list->next;
if (list == &ppp->channels) {
i = 0;
continue;
}
pch = list_entry(list, struct channel, clist);
++i;
if (!pch->avail)
continue;
if (pch->avail == 1) {
if (nfree > 0)
continue;
} else {
pch->avail = 1;
}
spin_lock_bh(&pch->downl);
if (pch->chan == NULL) {
if (pch->speed == 0)
nzero--;
else
totspeed -= pch->speed;
spin_unlock_bh(&pch->downl);
pch->avail = 0;
totlen = len;
totfree--;
nfree--;
if (--navail == 0)
break;
continue;
}
flen = len;
if (nfree > 0) {
if (pch->speed == 0) {
flen = len/nfree;
if (nbigger > 0) {
flen++;
nbigger--;
}
} else {
flen = (((totfree - nzero)*(totlen + hdrlen*totfree)) /
((totspeed*totfree)/pch->speed)) - hdrlen;
if (nbigger > 0) {
flen += ((totfree - nzero)*pch->speed)/totspeed;
nbigger -= ((totfree - nzero)*pch->speed)/
totspeed;
}
}
nfree--;
}
if ((nfree <= 0) || (flen > len))
flen = len;
if (flen <= 0) {
pch->avail = 2;
spin_unlock_bh(&pch->downl);
continue;
}
mtu = pch->chan->mtu - (hdrlen - 2);
if (mtu < 4)
mtu = 4;
if (flen > mtu)
flen = mtu;
if (flen == len)
bits |= E;
frag = alloc_skb(flen + hdrlen + (flen == 0), GFP_ATOMIC);
if (!frag)
goto noskb;
q = skb_put(frag, flen + hdrlen);
put_unaligned_be16(PPP_MP, q);
if (ppp->flags & SC_MP_XSHORTSEQ) {
q[2] = bits + ((ppp->nxseq >> 8) & 0xf);
q[3] = ppp->nxseq;
} else {
q[2] = bits;
q[3] = ppp->nxseq >> 16;
q[4] = ppp->nxseq >> 8;
q[5] = ppp->nxseq;
}
memcpy(q + hdrlen, p, flen);
chan = pch->chan;
if (!skb_queue_empty(&pch->file.xq) ||
!chan->ops->start_xmit(chan, frag))
skb_queue_tail(&pch->file.xq, frag);
pch->had_frag = 1;
p += flen;
len -= flen;
++ppp->nxseq;
bits = 0;
spin_unlock_bh(&pch->downl);
}
ppp->nxchan = i;
return 1;
noskb:
spin_unlock_bh(&pch->downl);
if (ppp->debug & 1)
netdev_err(ppp->dev, "PPP: no memory (fragment)\n");
++ppp->dev->stats.tx_errors;
++ppp->nxseq;
return 1;
}
static void
ppp_channel_push(struct channel *pch)
{
struct sk_buff *skb;
struct ppp *ppp;
spin_lock_bh(&pch->downl);
if (pch->chan) {
while (!skb_queue_empty(&pch->file.xq)) {
skb = skb_dequeue(&pch->file.xq);
if (!pch->chan->ops->start_xmit(pch->chan, skb)) {
skb_queue_head(&pch->file.xq, skb);
break;
}
}
} else {
skb_queue_purge(&pch->file.xq);
}
spin_unlock_bh(&pch->downl);
if (skb_queue_empty(&pch->file.xq)) {
read_lock_bh(&pch->upl);
ppp = pch->ppp;
if (ppp)
ppp_xmit_process(ppp);
read_unlock_bh(&pch->upl);
}
}
static inline void
ppp_do_recv(struct ppp *ppp, struct sk_buff *skb, struct channel *pch)
{
ppp_recv_lock(ppp);
if (!ppp->closing)
ppp_receive_frame(ppp, skb, pch);
else
kfree_skb(skb);
ppp_recv_unlock(ppp);
}
void
ppp_input(struct ppp_channel *chan, struct sk_buff *skb)
{
struct channel *pch = chan->ppp;
int proto;
if (!pch) {
kfree_skb(skb);
return;
}
read_lock_bh(&pch->upl);
if (!pskb_may_pull(skb, 2)) {
kfree_skb(skb);
if (pch->ppp) {
++pch->ppp->dev->stats.rx_length_errors;
ppp_receive_error(pch->ppp);
}
goto done;
}
proto = PPP_PROTO(skb);
if (!pch->ppp || proto >= 0xc000 || proto == PPP_CCPFRAG) {
skb_queue_tail(&pch->file.rq, skb);
while (pch->file.rq.qlen > PPP_MAX_RQLEN &&
(skb = skb_dequeue(&pch->file.rq)))
kfree_skb(skb);
wake_up_interruptible(&pch->file.rwait);
} else {
ppp_do_recv(pch->ppp, skb, pch);
}
done:
read_unlock_bh(&pch->upl);
}
void
ppp_input_error(struct ppp_channel *chan, int code)
{
struct channel *pch = chan->ppp;
struct sk_buff *skb;
if (!pch)
return;
read_lock_bh(&pch->upl);
if (pch->ppp) {
skb = alloc_skb(0, GFP_ATOMIC);
if (skb) {
skb->len = 0;
skb->cb[0] = code;
ppp_do_recv(pch->ppp, skb, pch);
}
}
read_unlock_bh(&pch->upl);
}
static void
ppp_receive_frame(struct ppp *ppp, struct sk_buff *skb, struct channel *pch)
{
if (skb->len > 0) {
skb_checksum_complete_unset(skb);
#ifdef CONFIG_PPP_MULTILINK
if (PPP_PROTO(skb) == PPP_MP)
ppp_receive_mp_frame(ppp, skb, pch);
else
#endif
ppp_receive_nonmp_frame(ppp, skb);
} else {
kfree_skb(skb);
ppp_receive_error(ppp);
}
}
static void
ppp_receive_error(struct ppp *ppp)
{
++ppp->dev->stats.rx_errors;
if (ppp->vj)
slhc_toss(ppp->vj);
}
static void
ppp_receive_nonmp_frame(struct ppp *ppp, struct sk_buff *skb)
{
struct sk_buff *ns;
int proto, len, npi;
if (ppp->rc_state && (ppp->rstate & SC_DECOMP_RUN) &&
(ppp->rstate & (SC_DC_FERROR | SC_DC_ERROR)) == 0)
skb = ppp_decompress_frame(ppp, skb);
if (ppp->flags & SC_MUST_COMP && ppp->rstate & SC_DC_FERROR)
goto err;
proto = PPP_PROTO(skb);
switch (proto) {
case PPP_VJC_COMP:
if (!ppp->vj || (ppp->flags & SC_REJ_COMP_TCP))
goto err;
if (skb_tailroom(skb) < 124 || skb_cloned(skb)) {
ns = dev_alloc_skb(skb->len + 128);
if (!ns) {
netdev_err(ppp->dev, "PPP: no memory "
"(VJ decomp)\n");
goto err;
}
skb_reserve(ns, 2);
skb_copy_bits(skb, 0, skb_put(ns, skb->len), skb->len);
consume_skb(skb);
skb = ns;
}
else
skb->ip_summed = CHECKSUM_NONE;
len = slhc_uncompress(ppp->vj, skb->data + 2, skb->len - 2);
if (len <= 0) {
netdev_printk(KERN_DEBUG, ppp->dev,
"PPP: VJ decompression error\n");
goto err;
}
len += 2;
if (len > skb->len)
skb_put(skb, len - skb->len);
else if (len < skb->len)
skb_trim(skb, len);
proto = PPP_IP;
break;
case PPP_VJC_UNCOMP:
if (!ppp->vj || (ppp->flags & SC_REJ_COMP_TCP))
goto err;
if (!pskb_may_pull(skb, skb->len))
goto err;
if (slhc_remember(ppp->vj, skb->data + 2, skb->len - 2) <= 0) {
netdev_err(ppp->dev, "PPP: VJ uncompressed error\n");
goto err;
}
proto = PPP_IP;
break;
case PPP_CCP:
ppp_ccp_peek(ppp, skb, 1);
break;
}
++ppp->stats64.rx_packets;
ppp->stats64.rx_bytes += skb->len - 2;
npi = proto_to_npindex(proto);
if (npi < 0) {
skb_queue_tail(&ppp->file.rq, skb);
while (ppp->file.rq.qlen > PPP_MAX_RQLEN &&
(skb = skb_dequeue(&ppp->file.rq)))
kfree_skb(skb);
wake_up_interruptible(&ppp->file.rwait);
} else {
#ifdef CONFIG_PPP_FILTER
if (ppp->pass_filter || ppp->active_filter) {
if (skb_unclone(skb, GFP_ATOMIC))
goto err;
*skb_push(skb, 2) = 0;
if (ppp->pass_filter &&
BPF_PROG_RUN(ppp->pass_filter, skb) == 0) {
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
"PPP: inbound frame "
"not passed\n");
kfree_skb(skb);
return;
}
if (!(ppp->active_filter &&
BPF_PROG_RUN(ppp->active_filter, skb) == 0))
ppp->last_recv = jiffies;
__skb_pull(skb, 2);
} else
#endif
ppp->last_recv = jiffies;
if ((ppp->dev->flags & IFF_UP) == 0 ||
ppp->npmode[npi] != NPMODE_PASS) {
kfree_skb(skb);
} else {
skb_pull_rcsum(skb, 2);
skb->dev = ppp->dev;
skb->protocol = htons(npindex_to_ethertype[npi]);
skb_reset_mac_header(skb);
skb_scrub_packet(skb, !net_eq(ppp->ppp_net,
dev_net(ppp->dev)));
netif_rx(skb);
}
}
return;
err:
kfree_skb(skb);
ppp_receive_error(ppp);
}
static struct sk_buff *
ppp_decompress_frame(struct ppp *ppp, struct sk_buff *skb)
{
int proto = PPP_PROTO(skb);
struct sk_buff *ns;
int len;
if (!pskb_may_pull(skb, skb->len))
goto err;
if (proto == PPP_COMP) {
int obuff_size;
switch(ppp->rcomp->compress_proto) {
case CI_MPPE:
obuff_size = ppp->mru + PPP_HDRLEN + 1;
break;
default:
obuff_size = ppp->mru + PPP_HDRLEN;
break;
}
ns = dev_alloc_skb(obuff_size);
if (!ns) {
netdev_err(ppp->dev, "ppp_decompress_frame: "
"no memory\n");
goto err;
}
len = ppp->rcomp->decompress(ppp->rc_state, skb->data - 2,
skb->len + 2, ns->data, obuff_size);
if (len < 0) {
if (len == DECOMP_FATALERROR)
ppp->rstate |= SC_DC_FERROR;
kfree_skb(ns);
goto err;
}
consume_skb(skb);
skb = ns;
skb_put(skb, len);
skb_pull(skb, 2);
} else {
if (ppp->rcomp->incomp)
ppp->rcomp->incomp(ppp->rc_state, skb->data - 2,
skb->len + 2);
}
return skb;
err:
ppp->rstate |= SC_DC_ERROR;
ppp_receive_error(ppp);
return skb;
}
static void
ppp_receive_mp_frame(struct ppp *ppp, struct sk_buff *skb, struct channel *pch)
{
u32 mask, seq;
struct channel *ch;
int mphdrlen = (ppp->flags & SC_MP_SHORTSEQ)? MPHDRLEN_SSN: MPHDRLEN;
if (!pskb_may_pull(skb, mphdrlen + 1) || ppp->mrru == 0)
goto err;
if (ppp->flags & SC_MP_SHORTSEQ) {
seq = ((skb->data[2] & 0x0f) << 8) | skb->data[3];
mask = 0xfff;
} else {
seq = (skb->data[3] << 16) | (skb->data[4] << 8)| skb->data[5];
mask = 0xffffff;
}
PPP_MP_CB(skb)->BEbits = skb->data[2];
skb_pull(skb, mphdrlen);
if ((PPP_MP_CB(skb)->BEbits & B) && (skb->data[0] & 1))
*skb_push(skb, 1) = 0;
seq |= ppp->minseq & ~mask;
if ((int)(ppp->minseq - seq) > (int)(mask >> 1))
seq += mask + 1;
else if ((int)(seq - ppp->minseq) > (int)(mask >> 1))
seq -= mask + 1;
PPP_MP_CB(skb)->sequence = seq;
pch->lastseq = seq;
if (seq_before(seq, ppp->nextseq)) {
kfree_skb(skb);
++ppp->dev->stats.rx_dropped;
ppp_receive_error(ppp);
return;
}
list_for_each_entry(ch, &ppp->channels, clist) {
if (seq_before(ch->lastseq, seq))
seq = ch->lastseq;
}
if (seq_before(ppp->minseq, seq))
ppp->minseq = seq;
ppp_mp_insert(ppp, skb);
if (skb_queue_len(&ppp->mrq) >= PPP_MP_MAX_QLEN) {
struct sk_buff *mskb = skb_peek(&ppp->mrq);
if (seq_before(ppp->minseq, PPP_MP_CB(mskb)->sequence))
ppp->minseq = PPP_MP_CB(mskb)->sequence;
}
while ((skb = ppp_mp_reconstruct(ppp))) {
if (pskb_may_pull(skb, 2))
ppp_receive_nonmp_frame(ppp, skb);
else {
++ppp->dev->stats.rx_length_errors;
kfree_skb(skb);
ppp_receive_error(ppp);
}
}
return;
err:
kfree_skb(skb);
ppp_receive_error(ppp);
}
static void
ppp_mp_insert(struct ppp *ppp, struct sk_buff *skb)
{
struct sk_buff *p;
struct sk_buff_head *list = &ppp->mrq;
u32 seq = PPP_MP_CB(skb)->sequence;
skb_queue_walk(list, p) {
if (seq_before(seq, PPP_MP_CB(p)->sequence))
break;
}
__skb_queue_before(list, p, skb);
}
static struct sk_buff *
ppp_mp_reconstruct(struct ppp *ppp)
{
u32 seq = ppp->nextseq;
u32 minseq = ppp->minseq;
struct sk_buff_head *list = &ppp->mrq;
struct sk_buff *p, *tmp;
struct sk_buff *head, *tail;
struct sk_buff *skb = NULL;
int lost = 0, len = 0;
if (ppp->mrru == 0)
return NULL;
head = list->next;
tail = NULL;
skb_queue_walk_safe(list, p, tmp) {
again:
if (seq_before(PPP_MP_CB(p)->sequence, seq)) {
netdev_err(ppp->dev, "ppp_mp_reconstruct bad "
"seq %u < %u\n",
PPP_MP_CB(p)->sequence, seq);
__skb_unlink(p, list);
kfree_skb(p);
continue;
}
if (PPP_MP_CB(p)->sequence != seq) {
u32 oldseq;
if (seq_after(seq, minseq))
break;
lost = 1;
oldseq = seq;
seq = seq_before(minseq, PPP_MP_CB(p)->sequence)?
minseq + 1: PPP_MP_CB(p)->sequence;
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
"lost frag %u..%u\n",
oldseq, seq-1);
goto again;
}
if (PPP_MP_CB(p)->BEbits & B) {
head = p;
lost = 0;
len = 0;
}
len += p->len;
if (lost == 0 && (PPP_MP_CB(p)->BEbits & E) &&
(PPP_MP_CB(head)->BEbits & B)) {
if (len > ppp->mrru + 2) {
++ppp->dev->stats.rx_length_errors;
netdev_printk(KERN_DEBUG, ppp->dev,
"PPP: reconstructed packet"
" is too long (%d)\n", len);
} else {
tail = p;
break;
}
ppp->nextseq = seq + 1;
}
if (PPP_MP_CB(p)->BEbits & E) {
struct sk_buff *tmp2;
skb_queue_reverse_walk_from_safe(list, p, tmp2) {
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
"discarding frag %u\n",
PPP_MP_CB(p)->sequence);
__skb_unlink(p, list);
kfree_skb(p);
}
head = skb_peek(list);
if (!head)
break;
}
++seq;
}
if (tail != NULL) {
if (PPP_MP_CB(head)->sequence != ppp->nextseq) {
skb_queue_walk_safe(list, p, tmp) {
if (p == head)
break;
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
"discarding frag %u\n",
PPP_MP_CB(p)->sequence);
__skb_unlink(p, list);
kfree_skb(p);
}
if (ppp->debug & 1)
netdev_printk(KERN_DEBUG, ppp->dev,
" missed pkts %u..%u\n",
ppp->nextseq,
PPP_MP_CB(head)->sequence-1);
++ppp->dev->stats.rx_dropped;
ppp_receive_error(ppp);
}
skb = head;
if (head != tail) {
struct sk_buff **fragpp = &skb_shinfo(skb)->frag_list;
p = skb_queue_next(list, head);
__skb_unlink(skb, list);
skb_queue_walk_from_safe(list, p, tmp) {
__skb_unlink(p, list);
*fragpp = p;
p->next = NULL;
fragpp = &p->next;
skb->len += p->len;
skb->data_len += p->len;
skb->truesize += p->truesize;
if (p == tail)
break;
}
} else {
__skb_unlink(skb, list);
}
ppp->nextseq = PPP_MP_CB(tail)->sequence + 1;
}
return skb;
}
int ppp_register_channel(struct ppp_channel *chan)
{
return ppp_register_net_channel(current->nsproxy->net_ns, chan);
}
int ppp_register_net_channel(struct net *net, struct ppp_channel *chan)
{
struct channel *pch;
struct ppp_net *pn;
pch = kzalloc(sizeof(struct channel), GFP_KERNEL);
if (!pch)
return -ENOMEM;
pn = ppp_pernet(net);
pch->ppp = NULL;
pch->chan = chan;
pch->chan_net = get_net(net);
chan->ppp = pch;
init_ppp_file(&pch->file, CHANNEL);
pch->file.hdrlen = chan->hdrlen;
#ifdef CONFIG_PPP_MULTILINK
pch->lastseq = -1;
#endif
init_rwsem(&pch->chan_sem);
spin_lock_init(&pch->downl);
rwlock_init(&pch->upl);
spin_lock_bh(&pn->all_channels_lock);
pch->file.index = ++pn->last_channel_index;
list_add(&pch->list, &pn->new_channels);
atomic_inc(&channel_count);
spin_unlock_bh(&pn->all_channels_lock);
return 0;
}
int ppp_channel_index(struct ppp_channel *chan)
{
struct channel *pch = chan->ppp;
if (pch)
return pch->file.index;
return -1;
}
int ppp_unit_number(struct ppp_channel *chan)
{
struct channel *pch = chan->ppp;
int unit = -1;
if (pch) {
read_lock_bh(&pch->upl);
if (pch->ppp)
unit = pch->ppp->file.index;
read_unlock_bh(&pch->upl);
}
return unit;
}
char *ppp_dev_name(struct ppp_channel *chan)
{
struct channel *pch = chan->ppp;
char *name = NULL;
if (pch) {
read_lock_bh(&pch->upl);
if (pch->ppp && pch->ppp->dev)
name = pch->ppp->dev->name;
read_unlock_bh(&pch->upl);
}
return name;
}
void
ppp_unregister_channel(struct ppp_channel *chan)
{
struct channel *pch = chan->ppp;
struct ppp_net *pn;
if (!pch)
return;
chan->ppp = NULL;
down_write(&pch->chan_sem);
spin_lock_bh(&pch->downl);
pch->chan = NULL;
spin_unlock_bh(&pch->downl);
up_write(&pch->chan_sem);
ppp_disconnect_channel(pch);
pn = ppp_pernet(pch->chan_net);
spin_lock_bh(&pn->all_channels_lock);
list_del(&pch->list);
spin_unlock_bh(&pn->all_channels_lock);
put_net(pch->chan_net);
pch->chan_net = NULL;
pch->file.dead = 1;
wake_up_interruptible(&pch->file.rwait);
if (atomic_dec_and_test(&pch->file.refcnt))
ppp_destroy_channel(pch);
}
void
ppp_output_wakeup(struct ppp_channel *chan)
{
struct channel *pch = chan->ppp;
if (!pch)
return;
ppp_channel_push(pch);
}
static int
ppp_set_compress(struct ppp *ppp, unsigned long arg)
{
int err;
struct compressor *cp, *ocomp;
struct ppp_option_data data;
void *state, *ostate;
unsigned char ccp_option[CCP_MAX_OPTION_LENGTH];
err = -EFAULT;
if (copy_from_user(&data, (void __user *) arg, sizeof(data)))
goto out;
if (data.length > CCP_MAX_OPTION_LENGTH)
goto out;
if (copy_from_user(ccp_option, (void __user *) data.ptr, data.length))
goto out;
err = -EINVAL;
if (data.length < 2 || ccp_option[1] < 2 || ccp_option[1] > data.length)
goto out;
cp = try_then_request_module(
find_compressor(ccp_option[0]),
"ppp-compress-%d", ccp_option[0]);
if (!cp)
goto out;
err = -ENOBUFS;
if (data.transmit) {
state = cp->comp_alloc(ccp_option, data.length);
if (state) {
ppp_xmit_lock(ppp);
ppp->xstate &= ~SC_COMP_RUN;
ocomp = ppp->xcomp;
ostate = ppp->xc_state;
ppp->xcomp = cp;
ppp->xc_state = state;
ppp_xmit_unlock(ppp);
if (ostate) {
ocomp->comp_free(ostate);
module_put(ocomp->owner);
}
err = 0;
} else
module_put(cp->owner);
} else {
state = cp->decomp_alloc(ccp_option, data.length);
if (state) {
ppp_recv_lock(ppp);
ppp->rstate &= ~SC_DECOMP_RUN;
ocomp = ppp->rcomp;
ostate = ppp->rc_state;
ppp->rcomp = cp;
ppp->rc_state = state;
ppp_recv_unlock(ppp);
if (ostate) {
ocomp->decomp_free(ostate);
module_put(ocomp->owner);
}
err = 0;
} else
module_put(cp->owner);
}
out:
return err;
}
static void
ppp_ccp_peek(struct ppp *ppp, struct sk_buff *skb, int inbound)
{
unsigned char *dp;
int len;
if (!pskb_may_pull(skb, CCP_HDRLEN + 2))
return;
dp = skb->data + 2;
switch (CCP_CODE(dp)) {
case CCP_CONFREQ:
if(inbound)
ppp->xstate &= ~SC_COMP_RUN;
else
ppp->rstate &= ~SC_DECOMP_RUN;
break;
case CCP_TERMREQ:
case CCP_TERMACK:
ppp->rstate &= ~SC_DECOMP_RUN;
ppp->xstate &= ~SC_COMP_RUN;
break;
case CCP_CONFACK:
if ((ppp->flags & (SC_CCP_OPEN | SC_CCP_UP)) != SC_CCP_OPEN)
break;
len = CCP_LENGTH(dp);
if (!pskb_may_pull(skb, len + 2))
return;
dp += CCP_HDRLEN;
len -= CCP_HDRLEN;
if (len < CCP_OPT_MINLEN || len < CCP_OPT_LENGTH(dp))
break;
if (inbound) {
if (!ppp->rc_state)
break;
if (ppp->rcomp->decomp_init(ppp->rc_state, dp, len,
ppp->file.index, 0, ppp->mru, ppp->debug)) {
ppp->rstate |= SC_DECOMP_RUN;
ppp->rstate &= ~(SC_DC_ERROR | SC_DC_FERROR);
}
} else {
if (!ppp->xc_state)
break;
if (ppp->xcomp->comp_init(ppp->xc_state, dp, len,
ppp->file.index, 0, ppp->debug))
ppp->xstate |= SC_COMP_RUN;
}
break;
case CCP_RESETACK:
if ((ppp->flags & SC_CCP_UP) == 0)
break;
if (inbound) {
if (ppp->rc_state && (ppp->rstate & SC_DECOMP_RUN)) {
ppp->rcomp->decomp_reset(ppp->rc_state);
ppp->rstate &= ~SC_DC_ERROR;
}
} else {
if (ppp->xc_state && (ppp->xstate & SC_COMP_RUN))
ppp->xcomp->comp_reset(ppp->xc_state);
}
break;
}
}
static void
ppp_ccp_closed(struct ppp *ppp)
{
void *xstate, *rstate;
struct compressor *xcomp, *rcomp;
ppp_lock(ppp);
ppp->flags &= ~(SC_CCP_OPEN | SC_CCP_UP);
ppp->xstate = 0;
xcomp = ppp->xcomp;
xstate = ppp->xc_state;
ppp->xc_state = NULL;
ppp->rstate = 0;
rcomp = ppp->rcomp;
rstate = ppp->rc_state;
ppp->rc_state = NULL;
ppp_unlock(ppp);
if (xstate) {
xcomp->comp_free(xstate);
module_put(xcomp->owner);
}
if (rstate) {
rcomp->decomp_free(rstate);
module_put(rcomp->owner);
}
}
static struct compressor_entry *
find_comp_entry(int proto)
{
struct compressor_entry *ce;
list_for_each_entry(ce, &compressor_list, list) {
if (ce->comp->compress_proto == proto)
return ce;
}
return NULL;
}
int
ppp_register_compressor(struct compressor *cp)
{
struct compressor_entry *ce;
int ret;
spin_lock(&compressor_list_lock);
ret = -EEXIST;
if (find_comp_entry(cp->compress_proto))
goto out;
ret = -ENOMEM;
ce = kmalloc(sizeof(struct compressor_entry), GFP_ATOMIC);
if (!ce)
goto out;
ret = 0;
ce->comp = cp;
list_add(&ce->list, &compressor_list);
out:
spin_unlock(&compressor_list_lock);
return ret;
}
void
ppp_unregister_compressor(struct compressor *cp)
{
struct compressor_entry *ce;
spin_lock(&compressor_list_lock);
ce = find_comp_entry(cp->compress_proto);
if (ce && ce->comp == cp) {
list_del(&ce->list);
kfree(ce);
}
spin_unlock(&compressor_list_lock);
}
static struct compressor *
find_compressor(int type)
{
struct compressor_entry *ce;
struct compressor *cp = NULL;
spin_lock(&compressor_list_lock);
ce = find_comp_entry(type);
if (ce) {
cp = ce->comp;
if (!try_module_get(cp->owner))
cp = NULL;
}
spin_unlock(&compressor_list_lock);
return cp;
}
static void
ppp_get_stats(struct ppp *ppp, struct ppp_stats *st)
{
struct slcompress *vj = ppp->vj;
memset(st, 0, sizeof(*st));
st->p.ppp_ipackets = ppp->stats64.rx_packets;
st->p.ppp_ierrors = ppp->dev->stats.rx_errors;
st->p.ppp_ibytes = ppp->stats64.rx_bytes;
st->p.ppp_opackets = ppp->stats64.tx_packets;
st->p.ppp_oerrors = ppp->dev->stats.tx_errors;
st->p.ppp_obytes = ppp->stats64.tx_bytes;
if (!vj)
return;
st->vj.vjs_packets = vj->sls_o_compressed + vj->sls_o_uncompressed;
st->vj.vjs_compressed = vj->sls_o_compressed;
st->vj.vjs_searches = vj->sls_o_searches;
st->vj.vjs_misses = vj->sls_o_misses;
st->vj.vjs_errorin = vj->sls_i_error;
st->vj.vjs_tossed = vj->sls_i_tossed;
st->vj.vjs_uncompressedin = vj->sls_i_uncompressed;
st->vj.vjs_compressedin = vj->sls_i_compressed;
}
static struct ppp *ppp_create_interface(struct net *net, int unit,
struct file *file, int *retp)
{
struct ppp *ppp;
struct ppp_net *pn;
struct net_device *dev = NULL;
int ret = -ENOMEM;
int i;
dev = alloc_netdev(sizeof(struct ppp), "", NET_NAME_ENUM, ppp_setup);
if (!dev)
goto out1;
pn = ppp_pernet(net);
ppp = netdev_priv(dev);
ppp->dev = dev;
ppp->mru = PPP_MRU;
init_ppp_file(&ppp->file, INTERFACE);
ppp->file.hdrlen = PPP_HDRLEN - 2;
ppp->owner = file;
for (i = 0; i < NUM_NP; ++i)
ppp->npmode[i] = NPMODE_PASS;
INIT_LIST_HEAD(&ppp->channels);
spin_lock_init(&ppp->rlock);
spin_lock_init(&ppp->wlock);
#ifdef CONFIG_PPP_MULTILINK
ppp->minseq = -1;
skb_queue_head_init(&ppp->mrq);
#endif
#ifdef CONFIG_PPP_FILTER
ppp->pass_filter = NULL;
ppp->active_filter = NULL;
#endif
dev_net_set(dev, net);
rtnl_lock();
mutex_lock(&pn->all_ppp_mutex);
if (unit < 0) {
unit = unit_get(&pn->units_idr, ppp);
if (unit < 0) {
ret = unit;
goto out2;
}
} else {
ret = -EEXIST;
if (unit_find(&pn->units_idr, unit))
goto out2;
unit = unit_set(&pn->units_idr, ppp, unit);
if (unit < 0)
goto out2;
}
ppp->file.index = unit;
sprintf(dev->name, "ppp%d", unit);
ret = register_netdevice(dev);
if (ret != 0) {
unit_put(&pn->units_idr, unit);
netdev_err(ppp->dev, "PPP: couldn't register device %s (%d)\n",
dev->name, ret);
goto out2;
}
ppp->ppp_net = net;
atomic_inc(&ppp_unit_count);
mutex_unlock(&pn->all_ppp_mutex);
rtnl_unlock();
*retp = 0;
return ppp;
out2:
mutex_unlock(&pn->all_ppp_mutex);
rtnl_unlock();
free_netdev(dev);
out1:
*retp = ret;
return NULL;
}
static void
init_ppp_file(struct ppp_file *pf, int kind)
{
pf->kind = kind;
skb_queue_head_init(&pf->xq);
skb_queue_head_init(&pf->rq);
atomic_set(&pf->refcnt, 1);
init_waitqueue_head(&pf->rwait);
}
static void ppp_destroy_interface(struct ppp *ppp)
{
atomic_dec(&ppp_unit_count);
if (!ppp->file.dead || ppp->n_channels) {
netdev_err(ppp->dev, "ppp: destroying ppp struct %p "
"but dead=%d n_channels=%d !\n",
ppp, ppp->file.dead, ppp->n_channels);
return;
}
ppp_ccp_closed(ppp);
if (ppp->vj) {
slhc_free(ppp->vj);
ppp->vj = NULL;
}
skb_queue_purge(&ppp->file.xq);
skb_queue_purge(&ppp->file.rq);
#ifdef CONFIG_PPP_MULTILINK
skb_queue_purge(&ppp->mrq);
#endif
#ifdef CONFIG_PPP_FILTER
if (ppp->pass_filter) {
bpf_prog_destroy(ppp->pass_filter);
ppp->pass_filter = NULL;
}
if (ppp->active_filter) {
bpf_prog_destroy(ppp->active_filter);
ppp->active_filter = NULL;
}
#endif
kfree_skb(ppp->xmit_pending);
free_netdev(ppp->dev);
}
static struct ppp *
ppp_find_unit(struct ppp_net *pn, int unit)
{
return unit_find(&pn->units_idr, unit);
}
static struct channel *
ppp_find_channel(struct ppp_net *pn, int unit)
{
struct channel *pch;
list_for_each_entry(pch, &pn->new_channels, list) {
if (pch->file.index == unit) {
list_move(&pch->list, &pn->all_channels);
return pch;
}
}
list_for_each_entry(pch, &pn->all_channels, list) {
if (pch->file.index == unit)
return pch;
}
return NULL;
}
static int
ppp_connect_channel(struct channel *pch, int unit)
{
struct ppp *ppp;
struct ppp_net *pn;
int ret = -ENXIO;
int hdrlen;
pn = ppp_pernet(pch->chan_net);
mutex_lock(&pn->all_ppp_mutex);
ppp = ppp_find_unit(pn, unit);
if (!ppp)
goto out;
write_lock_bh(&pch->upl);
ret = -EINVAL;
if (pch->ppp)
goto outl;
ppp_lock(ppp);
if (pch->file.hdrlen > ppp->file.hdrlen)
ppp->file.hdrlen = pch->file.hdrlen;
hdrlen = pch->file.hdrlen + 2;
if (hdrlen > ppp->dev->hard_header_len)
ppp->dev->hard_header_len = hdrlen;
list_add_tail(&pch->clist, &ppp->channels);
++ppp->n_channels;
pch->ppp = ppp;
atomic_inc(&ppp->file.refcnt);
ppp_unlock(ppp);
ret = 0;
outl:
write_unlock_bh(&pch->upl);
out:
mutex_unlock(&pn->all_ppp_mutex);
return ret;
}
static int
ppp_disconnect_channel(struct channel *pch)
{
struct ppp *ppp;
int err = -EINVAL;
write_lock_bh(&pch->upl);
ppp = pch->ppp;
pch->ppp = NULL;
write_unlock_bh(&pch->upl);
if (ppp) {
ppp_lock(ppp);
list_del(&pch->clist);
if (--ppp->n_channels == 0)
wake_up_interruptible(&ppp->file.rwait);
ppp_unlock(ppp);
if (atomic_dec_and_test(&ppp->file.refcnt))
ppp_destroy_interface(ppp);
err = 0;
}
return err;
}
static void ppp_destroy_channel(struct channel *pch)
{
atomic_dec(&channel_count);
if (!pch->file.dead) {
pr_err("ppp: destroying undead channel %p !\n", pch);
return;
}
skb_queue_purge(&pch->file.xq);
skb_queue_purge(&pch->file.rq);
kfree(pch);
}
static void __exit ppp_cleanup(void)
{
if (atomic_read(&ppp_unit_count) || atomic_read(&channel_count))
pr_err("PPP: removing module but units remain!\n");
unregister_chrdev(PPP_MAJOR, "ppp");
device_destroy(ppp_class, MKDEV(PPP_MAJOR, 0));
class_destroy(ppp_class);
unregister_pernet_device(&ppp_net_ops);
}
static int unit_set(struct idr *p, void *ptr, int n)
{
int unit;
unit = idr_alloc(p, ptr, n, n + 1, GFP_KERNEL);
if (unit == -ENOSPC)
unit = -EINVAL;
return unit;
}
static int unit_get(struct idr *p, void *ptr)
{
return idr_alloc(p, ptr, 0, 0, GFP_KERNEL);
}
static void unit_put(struct idr *p, int n)
{
idr_remove(p, n);
}
static void *unit_find(struct idr *p, int n)
{
return idr_find(p, n);
}
