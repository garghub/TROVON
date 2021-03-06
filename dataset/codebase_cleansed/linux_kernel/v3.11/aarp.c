static void __aarp_expire(struct aarp_entry *a)
{
skb_queue_purge(&a->packet_queue);
kfree(a);
}
static void __aarp_send_query(struct aarp_entry *a)
{
static unsigned char aarp_eth_multicast[ETH_ALEN] =
{ 0x09, 0x00, 0x07, 0xFF, 0xFF, 0xFF };
struct net_device *dev = a->dev;
struct elapaarp *eah;
int len = dev->hard_header_len + sizeof(*eah) + aarp_dl->header_length;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
struct atalk_addr *sat = atalk_find_dev_addr(dev);
if (!skb)
return;
if (!sat) {
kfree_skb(skb);
return;
}
skb_reserve(skb, dev->hard_header_len + aarp_dl->header_length);
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
skb_put(skb, sizeof(*eah));
skb->protocol = htons(ETH_P_ATALK);
skb->dev = dev;
eah = aarp_hdr(skb);
eah->hw_type = htons(AARP_HW_TYPE_ETHERNET);
eah->pa_type = htons(ETH_P_ATALK);
eah->hw_len = ETH_ALEN;
eah->pa_len = AARP_PA_ALEN;
eah->function = htons(AARP_REQUEST);
memcpy(eah->hw_src, dev->dev_addr, ETH_ALEN);
eah->pa_src_zero = 0;
eah->pa_src_net = sat->s_net;
eah->pa_src_node = sat->s_node;
memset(eah->hw_dst, '\0', ETH_ALEN);
eah->pa_dst_zero = 0;
eah->pa_dst_net = a->target_addr.s_net;
eah->pa_dst_node = a->target_addr.s_node;
aarp_dl->request(aarp_dl, skb, aarp_eth_multicast);
a->xmit_count++;
a->last_sent = jiffies;
}
static void aarp_send_reply(struct net_device *dev, struct atalk_addr *us,
struct atalk_addr *them, unsigned char *sha)
{
struct elapaarp *eah;
int len = dev->hard_header_len + sizeof(*eah) + aarp_dl->header_length;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
if (!skb)
return;
skb_reserve(skb, dev->hard_header_len + aarp_dl->header_length);
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
skb_put(skb, sizeof(*eah));
skb->protocol = htons(ETH_P_ATALK);
skb->dev = dev;
eah = aarp_hdr(skb);
eah->hw_type = htons(AARP_HW_TYPE_ETHERNET);
eah->pa_type = htons(ETH_P_ATALK);
eah->hw_len = ETH_ALEN;
eah->pa_len = AARP_PA_ALEN;
eah->function = htons(AARP_REPLY);
memcpy(eah->hw_src, dev->dev_addr, ETH_ALEN);
eah->pa_src_zero = 0;
eah->pa_src_net = us->s_net;
eah->pa_src_node = us->s_node;
if (!sha)
memset(eah->hw_dst, '\0', ETH_ALEN);
else
memcpy(eah->hw_dst, sha, ETH_ALEN);
eah->pa_dst_zero = 0;
eah->pa_dst_net = them->s_net;
eah->pa_dst_node = them->s_node;
aarp_dl->request(aarp_dl, skb, sha);
}
static void aarp_send_probe(struct net_device *dev, struct atalk_addr *us)
{
struct elapaarp *eah;
int len = dev->hard_header_len + sizeof(*eah) + aarp_dl->header_length;
struct sk_buff *skb = alloc_skb(len, GFP_ATOMIC);
static unsigned char aarp_eth_multicast[ETH_ALEN] =
{ 0x09, 0x00, 0x07, 0xFF, 0xFF, 0xFF };
if (!skb)
return;
skb_reserve(skb, dev->hard_header_len + aarp_dl->header_length);
skb_reset_network_header(skb);
skb_reset_transport_header(skb);
skb_put(skb, sizeof(*eah));
skb->protocol = htons(ETH_P_ATALK);
skb->dev = dev;
eah = aarp_hdr(skb);
eah->hw_type = htons(AARP_HW_TYPE_ETHERNET);
eah->pa_type = htons(ETH_P_ATALK);
eah->hw_len = ETH_ALEN;
eah->pa_len = AARP_PA_ALEN;
eah->function = htons(AARP_PROBE);
memcpy(eah->hw_src, dev->dev_addr, ETH_ALEN);
eah->pa_src_zero = 0;
eah->pa_src_net = us->s_net;
eah->pa_src_node = us->s_node;
memset(eah->hw_dst, '\0', ETH_ALEN);
eah->pa_dst_zero = 0;
eah->pa_dst_net = us->s_net;
eah->pa_dst_node = us->s_node;
aarp_dl->request(aarp_dl, skb, aarp_eth_multicast);
}
static void __aarp_expire_timer(struct aarp_entry **n)
{
struct aarp_entry *t;
while (*n)
if (time_after(jiffies, (*n)->expires_at)) {
t = *n;
*n = (*n)->next;
__aarp_expire(t);
} else
n = &((*n)->next);
}
static void __aarp_kick(struct aarp_entry **n)
{
struct aarp_entry *t;
while (*n)
if ((*n)->xmit_count >= sysctl_aarp_retransmit_limit) {
t = *n;
*n = (*n)->next;
__aarp_expire(t);
} else {
__aarp_send_query(*n);
n = &((*n)->next);
}
}
static void __aarp_expire_device(struct aarp_entry **n, struct net_device *dev)
{
struct aarp_entry *t;
while (*n)
if ((*n)->dev == dev) {
t = *n;
*n = (*n)->next;
__aarp_expire(t);
} else
n = &((*n)->next);
}
static void aarp_expire_timeout(unsigned long unused)
{
int ct;
write_lock_bh(&aarp_lock);
for (ct = 0; ct < AARP_HASH_SIZE; ct++) {
__aarp_expire_timer(&resolved[ct]);
__aarp_kick(&unresolved[ct]);
__aarp_expire_timer(&unresolved[ct]);
__aarp_expire_timer(&proxies[ct]);
}
write_unlock_bh(&aarp_lock);
mod_timer(&aarp_timer, jiffies +
(unresolved_count ? sysctl_aarp_tick_time :
sysctl_aarp_expiry_time));
}
static int aarp_device_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
int ct;
if (!net_eq(dev_net(dev), &init_net))
return NOTIFY_DONE;
if (event == NETDEV_DOWN) {
write_lock_bh(&aarp_lock);
for (ct = 0; ct < AARP_HASH_SIZE; ct++) {
__aarp_expire_device(&resolved[ct], dev);
__aarp_expire_device(&unresolved[ct], dev);
__aarp_expire_device(&proxies[ct], dev);
}
write_unlock_bh(&aarp_lock);
}
return NOTIFY_DONE;
}
static void __aarp_expire_all(struct aarp_entry **n)
{
struct aarp_entry *t;
while (*n) {
t = *n;
*n = (*n)->next;
__aarp_expire(t);
}
}
static void aarp_purge(void)
{
int ct;
write_lock_bh(&aarp_lock);
for (ct = 0; ct < AARP_HASH_SIZE; ct++) {
__aarp_expire_all(&resolved[ct]);
__aarp_expire_all(&unresolved[ct]);
__aarp_expire_all(&proxies[ct]);
}
write_unlock_bh(&aarp_lock);
}
static struct aarp_entry *aarp_alloc(void)
{
struct aarp_entry *a = kmalloc(sizeof(*a), GFP_ATOMIC);
if (a)
skb_queue_head_init(&a->packet_queue);
return a;
}
static struct aarp_entry *__aarp_find_entry(struct aarp_entry *list,
struct net_device *dev,
struct atalk_addr *sat)
{
while (list) {
if (list->target_addr.s_net == sat->s_net &&
list->target_addr.s_node == sat->s_node &&
list->dev == dev)
break;
list = list->next;
}
return list;
}
void aarp_proxy_remove(struct net_device *dev, struct atalk_addr *sa)
{
int hash = sa->s_node % (AARP_HASH_SIZE - 1);
struct aarp_entry *a;
write_lock_bh(&aarp_lock);
a = __aarp_find_entry(proxies[hash], dev, sa);
if (a)
a->expires_at = jiffies - 1;
write_unlock_bh(&aarp_lock);
}
static struct atalk_addr *__aarp_proxy_find(struct net_device *dev,
struct atalk_addr *sa)
{
int hash = sa->s_node % (AARP_HASH_SIZE - 1);
struct aarp_entry *a = __aarp_find_entry(proxies[hash], dev, sa);
return a ? sa : NULL;
}
static void aarp_send_probe_phase1(struct atalk_iface *iface)
{
struct ifreq atreq;
struct sockaddr_at *sa = (struct sockaddr_at *)&atreq.ifr_addr;
const struct net_device_ops *ops = iface->dev->netdev_ops;
sa->sat_addr.s_node = iface->address.s_node;
sa->sat_addr.s_net = ntohs(iface->address.s_net);
if (!(ops->ndo_do_ioctl(iface->dev, &atreq, SIOCSIFADDR))) {
ops->ndo_do_ioctl(iface->dev, &atreq, SIOCGIFADDR);
if (iface->address.s_net != htons(sa->sat_addr.s_net) ||
iface->address.s_node != sa->sat_addr.s_node)
iface->status |= ATIF_PROBE_FAIL;
iface->address.s_net = htons(sa->sat_addr.s_net);
iface->address.s_node = sa->sat_addr.s_node;
}
}
void aarp_probe_network(struct atalk_iface *atif)
{
if (atif->dev->type == ARPHRD_LOCALTLK ||
atif->dev->type == ARPHRD_PPP)
aarp_send_probe_phase1(atif);
else {
unsigned int count;
for (count = 0; count < AARP_RETRANSMIT_LIMIT; count++) {
aarp_send_probe(atif->dev, &atif->address);
msleep(100);
if (atif->status & ATIF_PROBE_FAIL)
break;
}
}
}
int aarp_proxy_probe_network(struct atalk_iface *atif, struct atalk_addr *sa)
{
int hash, retval = -EPROTONOSUPPORT;
struct aarp_entry *entry;
unsigned int count;
if (atif->dev->type == ARPHRD_LOCALTLK ||
atif->dev->type == ARPHRD_PPP)
goto out;
entry = aarp_alloc();
retval = -ENOMEM;
if (!entry)
goto out;
entry->expires_at = -1;
entry->status = ATIF_PROBE;
entry->target_addr.s_node = sa->s_node;
entry->target_addr.s_net = sa->s_net;
entry->dev = atif->dev;
write_lock_bh(&aarp_lock);
hash = sa->s_node % (AARP_HASH_SIZE - 1);
entry->next = proxies[hash];
proxies[hash] = entry;
for (count = 0; count < AARP_RETRANSMIT_LIMIT; count++) {
aarp_send_probe(atif->dev, sa);
write_unlock_bh(&aarp_lock);
msleep(100);
write_lock_bh(&aarp_lock);
if (entry->status & ATIF_PROBE_FAIL)
break;
}
if (entry->status & ATIF_PROBE_FAIL) {
entry->expires_at = jiffies - 1;
retval = -EADDRINUSE;
} else {
entry->status &= ~ATIF_PROBE;
retval = 1;
}
write_unlock_bh(&aarp_lock);
out:
return retval;
}
int aarp_send_ddp(struct net_device *dev, struct sk_buff *skb,
struct atalk_addr *sa, void *hwaddr)
{
static char ddp_eth_multicast[ETH_ALEN] =
{ 0x09, 0x00, 0x07, 0xFF, 0xFF, 0xFF };
int hash;
struct aarp_entry *a;
skb_reset_network_header(skb);
if (dev->type == ARPHRD_LOCALTLK) {
struct atalk_addr *at = atalk_find_dev_addr(dev);
struct ddpehdr *ddp = (struct ddpehdr *)skb->data;
int ft = 2;
if ((!ddp->deh_snet || at->s_net == ddp->deh_snet) &&
(!ddp->deh_dnet || at->s_net == ddp->deh_dnet)) {
skb_pull(skb, sizeof(*ddp) - 4);
*((__be16 *)skb->data) = htons(skb->len);
ft = 1;
}
skb_push(skb, 3);
skb->data[0] = sa->s_node;
skb->data[1] = at->s_node;
skb->data[2] = ft;
skb->dev = dev;
goto sendit;
}
if (dev->type == ARPHRD_PPP) {
skb->protocol = htons(ETH_P_PPPTALK);
skb->dev = dev;
goto sendit;
}
if (dev->type != ARPHRD_ETHER)
goto free_it;
skb->dev = dev;
skb->protocol = htons(ETH_P_ATALK);
hash = sa->s_node % (AARP_HASH_SIZE - 1);
if (sa->s_node == ATADDR_BCAST) {
ddp_dl->request(ddp_dl, skb, ddp_eth_multicast);
goto sent;
}
write_lock_bh(&aarp_lock);
a = __aarp_find_entry(resolved[hash], dev, sa);
if (a) {
a->expires_at = jiffies + (sysctl_aarp_expiry_time * 10);
ddp_dl->request(ddp_dl, skb, a->hwaddr);
write_unlock_bh(&aarp_lock);
goto sent;
}
a = __aarp_find_entry(unresolved[hash], dev, sa);
if (a) {
skb_queue_tail(&a->packet_queue, skb);
goto out_unlock;
}
a = aarp_alloc();
if (!a) {
write_unlock_bh(&aarp_lock);
goto free_it;
}
skb_queue_tail(&a->packet_queue, skb);
a->expires_at = jiffies + sysctl_aarp_resolve_time;
a->dev = dev;
a->next = unresolved[hash];
a->target_addr = *sa;
a->xmit_count = 0;
unresolved[hash] = a;
unresolved_count++;
__aarp_send_query(a);
if (unresolved_count == 1)
mod_timer(&aarp_timer, jiffies + sysctl_aarp_tick_time);
out_unlock:
write_unlock_bh(&aarp_lock);
goto sent;
sendit:
if (skb->sk)
skb->priority = skb->sk->sk_priority;
if (dev_queue_xmit(skb))
goto drop;
sent:
return NET_XMIT_SUCCESS;
free_it:
kfree_skb(skb);
drop:
return NET_XMIT_DROP;
}
static void __aarp_resolved(struct aarp_entry **list, struct aarp_entry *a,
int hash)
{
struct sk_buff *skb;
while (*list)
if (*list == a) {
unresolved_count--;
*list = a->next;
a->next = resolved[hash];
resolved[hash] = a;
while ((skb = skb_dequeue(&a->packet_queue)) != NULL) {
a->expires_at = jiffies +
sysctl_aarp_expiry_time * 10;
ddp_dl->request(ddp_dl, skb, a->hwaddr);
}
} else
list = &((*list)->next);
}
static int aarp_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct elapaarp *ea = aarp_hdr(skb);
int hash, ret = 0;
__u16 function;
struct aarp_entry *a;
struct atalk_addr sa, *ma, da;
struct atalk_iface *ifa;
if (!net_eq(dev_net(dev), &init_net))
goto out0;
if (dev->type != ARPHRD_ETHER)
goto out0;
if (!skb_pull(skb, sizeof(*ea)))
goto out0;
function = ntohs(ea->function);
if (function < AARP_REQUEST || function > AARP_PROBE ||
ea->hw_len != ETH_ALEN || ea->pa_len != AARP_PA_ALEN ||
ea->pa_src_zero || ea->pa_dst_zero)
goto out0;
hash = ea->pa_src_node % (AARP_HASH_SIZE - 1);
sa.s_node = ea->pa_src_node;
sa.s_net = ea->pa_src_net;
ifa = atalk_find_dev(dev);
if (!ifa)
goto out1;
if (ifa->status & ATIF_PROBE &&
ifa->address.s_node == ea->pa_dst_node &&
ifa->address.s_net == ea->pa_dst_net) {
ifa->status |= ATIF_PROBE_FAIL;
goto out1;
}
da.s_node = ea->pa_dst_node;
da.s_net = ea->pa_dst_net;
write_lock_bh(&aarp_lock);
a = __aarp_find_entry(proxies[hash], dev, &da);
if (a && a->status & ATIF_PROBE) {
a->status |= ATIF_PROBE_FAIL;
goto unlock;
}
switch (function) {
case AARP_REPLY:
if (!unresolved_count)
break;
a = __aarp_find_entry(unresolved[hash], dev, &sa);
if (!a || dev != a->dev)
break;
memcpy(a->hwaddr, ea->hw_src, ETH_ALEN);
__aarp_resolved(&unresolved[hash], a, hash);
if (!unresolved_count)
mod_timer(&aarp_timer,
jiffies + sysctl_aarp_expiry_time);
break;
case AARP_REQUEST:
case AARP_PROBE:
sa.s_node = ea->pa_dst_node;
sa.s_net = ea->pa_dst_net;
ma = __aarp_proxy_find(dev, &sa);
if (!ma)
ma = &ifa->address;
else {
da.s_node = sa.s_node;
da.s_net = sa.s_net;
ma = &da;
}
if (function == AARP_PROBE) {
a = __aarp_find_entry(resolved[sa.s_node %
(AARP_HASH_SIZE - 1)],
skb->dev, &sa);
if (a) {
a->expires_at = jiffies - 1;
mod_timer(&aarp_timer, jiffies +
sysctl_aarp_tick_time);
}
}
if (sa.s_node != ma->s_node)
break;
if (sa.s_net && ma->s_net && sa.s_net != ma->s_net)
break;
sa.s_node = ea->pa_src_node;
sa.s_net = ea->pa_src_net;
aarp_send_reply(dev, ma, &sa, ea->hw_src);
break;
}
unlock:
write_unlock_bh(&aarp_lock);
out1:
ret = 1;
out0:
kfree_skb(skb);
return ret;
}
void __init aarp_proto_init(void)
{
aarp_dl = register_snap_client(aarp_snap_id, aarp_rcv);
if (!aarp_dl)
printk(KERN_CRIT "Unable to register AARP with SNAP.\n");
setup_timer(&aarp_timer, aarp_expire_timeout, 0);
aarp_timer.expires = jiffies + sysctl_aarp_expiry_time;
add_timer(&aarp_timer);
register_netdevice_notifier(&aarp_notifier);
}
void aarp_device_down(struct net_device *dev)
{
int ct;
write_lock_bh(&aarp_lock);
for (ct = 0; ct < AARP_HASH_SIZE; ct++) {
__aarp_expire_device(&resolved[ct], dev);
__aarp_expire_device(&unresolved[ct], dev);
__aarp_expire_device(&proxies[ct], dev);
}
write_unlock_bh(&aarp_lock);
}
static struct aarp_entry *iter_next(struct aarp_iter_state *iter, loff_t *pos)
{
int ct = iter->bucket;
struct aarp_entry **table = iter->table;
loff_t off = 0;
struct aarp_entry *entry;
rescan:
while(ct < AARP_HASH_SIZE) {
for (entry = table[ct]; entry; entry = entry->next) {
if (!pos || ++off == *pos) {
iter->table = table;
iter->bucket = ct;
return entry;
}
}
++ct;
}
if (table == resolved) {
ct = 0;
table = unresolved;
goto rescan;
}
if (table == unresolved) {
ct = 0;
table = proxies;
goto rescan;
}
return NULL;
}
static void *aarp_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(aarp_lock)
{
struct aarp_iter_state *iter = seq->private;
read_lock_bh(&aarp_lock);
iter->table = resolved;
iter->bucket = 0;
return *pos ? iter_next(iter, pos) : SEQ_START_TOKEN;
}
static void *aarp_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct aarp_entry *entry = v;
struct aarp_iter_state *iter = seq->private;
++*pos;
if (v == SEQ_START_TOKEN)
entry = iter_next(iter, NULL);
else if (entry->next)
entry = entry->next;
else {
++iter->bucket;
entry = iter_next(iter, NULL);
}
return entry;
}
static void aarp_seq_stop(struct seq_file *seq, void *v)
__releases(aarp_lock)
{
read_unlock_bh(&aarp_lock);
}
static const char *dt2str(unsigned long ticks)
{
static char buf[32];
sprintf(buf, "%ld.%02ld", ticks / HZ, ((ticks % HZ) * 100 ) / HZ);
return buf;
}
static int aarp_seq_show(struct seq_file *seq, void *v)
{
struct aarp_iter_state *iter = seq->private;
struct aarp_entry *entry = v;
unsigned long now = jiffies;
if (v == SEQ_START_TOKEN)
seq_puts(seq,
"Address Interface Hardware Address"
" Expires LastSend Retry Status\n");
else {
seq_printf(seq, "%04X:%02X %-12s",
ntohs(entry->target_addr.s_net),
(unsigned int) entry->target_addr.s_node,
entry->dev ? entry->dev->name : "????");
seq_printf(seq, "%pM", entry->hwaddr);
seq_printf(seq, " %8s",
dt2str((long)entry->expires_at - (long)now));
if (iter->table == unresolved)
seq_printf(seq, " %8s %6hu",
dt2str(now - entry->last_sent),
entry->xmit_count);
else
seq_puts(seq, " ");
seq_printf(seq, " %s\n",
(iter->table == resolved) ? "resolved"
: (iter->table == unresolved) ? "unresolved"
: (iter->table == proxies) ? "proxies"
: "unknown");
}
return 0;
}
static int aarp_seq_open(struct inode *inode, struct file *file)
{
return seq_open_private(file, &aarp_seq_ops,
sizeof(struct aarp_iter_state));
}
void aarp_cleanup_module(void)
{
del_timer_sync(&aarp_timer);
unregister_netdevice_notifier(&aarp_notifier);
unregister_snap_client(aarp_dl);
aarp_purge();
}
