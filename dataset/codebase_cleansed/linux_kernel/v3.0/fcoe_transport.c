u32 fcoe_fc_crc(struct fc_frame *fp)
{
struct sk_buff *skb = fp_skb(fp);
struct skb_frag_struct *frag;
unsigned char *data;
unsigned long off, len, clen;
u32 crc;
unsigned i;
crc = crc32(~0, skb->data, skb_headlen(skb));
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
frag = &skb_shinfo(skb)->frags[i];
off = frag->page_offset;
len = frag->size;
while (len > 0) {
clen = min(len, PAGE_SIZE - (off & ~PAGE_MASK));
data = kmap_atomic(frag->page + (off >> PAGE_SHIFT),
KM_SKB_DATA_SOFTIRQ);
crc = crc32(crc, data + (off & ~PAGE_MASK), clen);
kunmap_atomic(data, KM_SKB_DATA_SOFTIRQ);
off += clen;
len -= clen;
}
}
return crc;
}
int fcoe_start_io(struct sk_buff *skb)
{
struct sk_buff *nskb;
int rc;
nskb = skb_clone(skb, GFP_ATOMIC);
if (!nskb)
return -ENOMEM;
rc = dev_queue_xmit(nskb);
if (rc != 0)
return rc;
kfree_skb(skb);
return 0;
}
void fcoe_clean_pending_queue(struct fc_lport *lport)
{
struct fcoe_port *port = lport_priv(lport);
struct sk_buff *skb;
spin_lock_bh(&port->fcoe_pending_queue.lock);
while ((skb = __skb_dequeue(&port->fcoe_pending_queue)) != NULL) {
spin_unlock_bh(&port->fcoe_pending_queue.lock);
kfree_skb(skb);
spin_lock_bh(&port->fcoe_pending_queue.lock);
}
spin_unlock_bh(&port->fcoe_pending_queue.lock);
}
void fcoe_check_wait_queue(struct fc_lport *lport, struct sk_buff *skb)
{
struct fcoe_port *port = lport_priv(lport);
int rc;
spin_lock_bh(&port->fcoe_pending_queue.lock);
if (skb)
__skb_queue_tail(&port->fcoe_pending_queue, skb);
if (port->fcoe_pending_queue_active)
goto out;
port->fcoe_pending_queue_active = 1;
while (port->fcoe_pending_queue.qlen) {
port->fcoe_pending_queue.qlen++;
skb = __skb_dequeue(&port->fcoe_pending_queue);
spin_unlock_bh(&port->fcoe_pending_queue.lock);
rc = fcoe_start_io(skb);
spin_lock_bh(&port->fcoe_pending_queue.lock);
if (rc) {
__skb_queue_head(&port->fcoe_pending_queue, skb);
port->fcoe_pending_queue.qlen--;
break;
}
port->fcoe_pending_queue.qlen--;
}
if (port->fcoe_pending_queue.qlen < port->min_queue_depth)
lport->qfull = 0;
if (port->fcoe_pending_queue.qlen && !timer_pending(&port->timer))
mod_timer(&port->timer, jiffies + 2);
port->fcoe_pending_queue_active = 0;
out:
if (port->fcoe_pending_queue.qlen > port->max_queue_depth)
lport->qfull = 1;
spin_unlock_bh(&port->fcoe_pending_queue.lock);
}
void fcoe_queue_timer(ulong lport)
{
fcoe_check_wait_queue((struct fc_lport *)lport, NULL);
}
int fcoe_get_paged_crc_eof(struct sk_buff *skb, int tlen,
struct fcoe_percpu_s *fps)
{
struct page *page;
page = fps->crc_eof_page;
if (!page) {
page = alloc_page(GFP_ATOMIC);
if (!page)
return -ENOMEM;
fps->crc_eof_page = page;
fps->crc_eof_offset = 0;
}
get_page(page);
skb_fill_page_desc(skb, skb_shinfo(skb)->nr_frags, page,
fps->crc_eof_offset, tlen);
skb->len += tlen;
skb->data_len += tlen;
skb->truesize += tlen;
fps->crc_eof_offset += sizeof(struct fcoe_crc_eof);
if (fps->crc_eof_offset >= PAGE_SIZE) {
fps->crc_eof_page = NULL;
fps->crc_eof_offset = 0;
put_page(page);
}
return 0;
}
static struct fcoe_transport *fcoe_transport_lookup(struct net_device *netdev)
{
struct fcoe_transport *ft = NULL;
list_for_each_entry(ft, &fcoe_transports, list)
if (ft->match && ft->match(netdev))
return ft;
return NULL;
}
int fcoe_transport_attach(struct fcoe_transport *ft)
{
int rc = 0;
mutex_lock(&ft_mutex);
if (ft->attached) {
LIBFCOE_TRANSPORT_DBG("transport %s already attached\n",
ft->name);
rc = -EEXIST;
goto out_attach;
}
if (strcmp(ft->name, FCOE_TRANSPORT_DEFAULT))
list_add(&ft->list, &fcoe_transports);
else
list_add_tail(&ft->list, &fcoe_transports);
ft->attached = true;
LIBFCOE_TRANSPORT_DBG("attaching transport %s\n", ft->name);
out_attach:
mutex_unlock(&ft_mutex);
return rc;
}
int fcoe_transport_detach(struct fcoe_transport *ft)
{
int rc = 0;
struct fcoe_netdev_mapping *nm = NULL, *tmp;
mutex_lock(&ft_mutex);
if (!ft->attached) {
LIBFCOE_TRANSPORT_DBG("transport %s already detached\n",
ft->name);
rc = -ENODEV;
goto out_attach;
}
mutex_lock(&fn_mutex);
list_for_each_entry_safe(nm, tmp, &fcoe_netdevs, list) {
if (nm->ft == ft) {
LIBFCOE_TRANSPORT_DBG("transport %s going away, "
"remove its netdev mapping for %s\n",
ft->name, nm->netdev->name);
list_del(&nm->list);
kfree(nm);
}
}
mutex_unlock(&fn_mutex);
list_del(&ft->list);
ft->attached = false;
LIBFCOE_TRANSPORT_DBG("detaching transport %s\n", ft->name);
out_attach:
mutex_unlock(&ft_mutex);
return rc;
}
static int fcoe_transport_show(char *buffer, const struct kernel_param *kp)
{
int i, j;
struct fcoe_transport *ft = NULL;
i = j = sprintf(buffer, "Attached FCoE transports:");
mutex_lock(&ft_mutex);
list_for_each_entry(ft, &fcoe_transports, list) {
if (i >= PAGE_SIZE - IFNAMSIZ)
break;
i += snprintf(&buffer[i], IFNAMSIZ, "%s ", ft->name);
}
mutex_unlock(&ft_mutex);
if (i == j)
i += snprintf(&buffer[i], IFNAMSIZ, "none");
return i;
}
static int __init fcoe_transport_init(void)
{
register_netdevice_notifier(&libfcoe_notifier);
return 0;
}
static int __exit fcoe_transport_exit(void)
{
struct fcoe_transport *ft;
unregister_netdevice_notifier(&libfcoe_notifier);
mutex_lock(&ft_mutex);
list_for_each_entry(ft, &fcoe_transports, list)
printk(KERN_ERR "FCoE transport %s is still attached!\n",
ft->name);
mutex_unlock(&ft_mutex);
return 0;
}
static int fcoe_add_netdev_mapping(struct net_device *netdev,
struct fcoe_transport *ft)
{
struct fcoe_netdev_mapping *nm;
nm = kmalloc(sizeof(*nm), GFP_KERNEL);
if (!nm) {
printk(KERN_ERR "Unable to allocate netdev_mapping");
return -ENOMEM;
}
nm->netdev = netdev;
nm->ft = ft;
mutex_lock(&fn_mutex);
list_add(&nm->list, &fcoe_netdevs);
mutex_unlock(&fn_mutex);
return 0;
}
static void fcoe_del_netdev_mapping(struct net_device *netdev)
{
struct fcoe_netdev_mapping *nm = NULL, *tmp;
mutex_lock(&fn_mutex);
list_for_each_entry_safe(nm, tmp, &fcoe_netdevs, list) {
if (nm->netdev == netdev) {
list_del(&nm->list);
kfree(nm);
mutex_unlock(&fn_mutex);
return;
}
}
mutex_unlock(&fn_mutex);
}
static struct fcoe_transport *fcoe_netdev_map_lookup(struct net_device *netdev)
{
struct fcoe_transport *ft = NULL;
struct fcoe_netdev_mapping *nm;
mutex_lock(&fn_mutex);
list_for_each_entry(nm, &fcoe_netdevs, list) {
if (netdev == nm->netdev) {
ft = nm->ft;
mutex_unlock(&fn_mutex);
return ft;
}
}
mutex_unlock(&fn_mutex);
return NULL;
}
static struct net_device *fcoe_if_to_netdev(const char *buffer)
{
char *cp;
char ifname[IFNAMSIZ + 2];
if (buffer) {
strlcpy(ifname, buffer, IFNAMSIZ);
cp = ifname + strlen(ifname);
while (--cp >= ifname && *cp == '\n')
*cp = '\0';
return dev_get_by_name(&init_net, ifname);
}
return NULL;
}
static int libfcoe_device_notification(struct notifier_block *notifier,
ulong event, void *ptr)
{
struct net_device *netdev = ptr;
switch (event) {
case NETDEV_UNREGISTER:
printk(KERN_ERR "libfcoe_device_notification: NETDEV_UNREGISTER %s\n",
netdev->name);
fcoe_del_netdev_mapping(netdev);
break;
}
return NOTIFY_OK;
}
static int fcoe_transport_create(const char *buffer, struct kernel_param *kp)
{
int rc = -ENODEV;
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
enum fip_state fip_mode = (enum fip_state)(long)kp->arg;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buffer);
if (!netdev) {
LIBFCOE_TRANSPORT_DBG("Invalid device %s.\n", buffer);
goto out_nodev;
}
ft = fcoe_netdev_map_lookup(netdev);
if (ft) {
LIBFCOE_TRANSPORT_DBG("transport %s already has existing "
"FCoE instance on %s.\n",
ft->name, netdev->name);
rc = -EEXIST;
goto out_putdev;
}
ft = fcoe_transport_lookup(netdev);
if (!ft) {
LIBFCOE_TRANSPORT_DBG("no FCoE transport found for %s.\n",
netdev->name);
goto out_putdev;
}
rc = fcoe_add_netdev_mapping(netdev, ft);
if (rc) {
LIBFCOE_TRANSPORT_DBG("failed to add new netdev mapping "
"for FCoE transport %s for %s.\n",
ft->name, netdev->name);
goto out_putdev;
}
rc = ft->create ? ft->create(netdev, fip_mode) : -ENODEV;
if (rc)
fcoe_del_netdev_mapping(netdev);
LIBFCOE_TRANSPORT_DBG("transport %s %s to create fcoe on %s.\n",
ft->name, (rc) ? "failed" : "succeeded",
netdev->name);
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
return rc;
}
static int fcoe_transport_destroy(const char *buffer, struct kernel_param *kp)
{
int rc = -ENODEV;
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buffer);
if (!netdev) {
LIBFCOE_TRANSPORT_DBG("invalid device %s.\n", buffer);
goto out_nodev;
}
ft = fcoe_netdev_map_lookup(netdev);
if (!ft) {
LIBFCOE_TRANSPORT_DBG("no FCoE transport found for %s.\n",
netdev->name);
goto out_putdev;
}
rc = ft->destroy ? ft->destroy(netdev) : -ENODEV;
fcoe_del_netdev_mapping(netdev);
LIBFCOE_TRANSPORT_DBG("transport %s %s to destroy fcoe on %s.\n",
ft->name, (rc) ? "failed" : "succeeded",
netdev->name);
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
return rc;
}
static int fcoe_transport_disable(const char *buffer, struct kernel_param *kp)
{
int rc = -ENODEV;
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buffer);
if (!netdev)
goto out_nodev;
ft = fcoe_netdev_map_lookup(netdev);
if (!ft)
goto out_putdev;
rc = ft->disable ? ft->disable(netdev) : -ENODEV;
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
if (rc == -ERESTARTSYS)
return restart_syscall();
else
return rc;
}
static int fcoe_transport_enable(const char *buffer, struct kernel_param *kp)
{
int rc = -ENODEV;
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buffer);
if (!netdev)
goto out_nodev;
ft = fcoe_netdev_map_lookup(netdev);
if (!ft)
goto out_putdev;
rc = ft->enable ? ft->enable(netdev) : -ENODEV;
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
return rc;
}
static int __init libfcoe_init(void)
{
fcoe_transport_init();
return 0;
}
static void __exit libfcoe_exit(void)
{
fcoe_transport_exit();
}
