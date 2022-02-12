int fcoe_link_speed_update(struct fc_lport *lport)
{
struct net_device *netdev = fcoe_get_netdev(lport);
struct ethtool_cmd ecmd;
if (!__ethtool_get_settings(netdev, &ecmd)) {
lport->link_supported_speeds &=
~(FC_PORTSPEED_1GBIT | FC_PORTSPEED_10GBIT);
if (ecmd.supported & (SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full))
lport->link_supported_speeds |= FC_PORTSPEED_1GBIT;
if (ecmd.supported & SUPPORTED_10000baseT_Full)
lport->link_supported_speeds |=
FC_PORTSPEED_10GBIT;
switch (ethtool_cmd_speed(&ecmd)) {
case SPEED_1000:
lport->link_speed = FC_PORTSPEED_1GBIT;
break;
case SPEED_10000:
lport->link_speed = FC_PORTSPEED_10GBIT;
break;
}
return 0;
}
return -1;
}
void __fcoe_get_lesb(struct fc_lport *lport,
struct fc_els_lesb *fc_lesb,
struct net_device *netdev)
{
unsigned int cpu;
u32 lfc, vlfc, mdac;
struct fc_stats *stats;
struct fcoe_fc_els_lesb *lesb;
struct rtnl_link_stats64 temp;
lfc = 0;
vlfc = 0;
mdac = 0;
lesb = (struct fcoe_fc_els_lesb *)fc_lesb;
memset(lesb, 0, sizeof(*lesb));
for_each_possible_cpu(cpu) {
stats = per_cpu_ptr(lport->stats, cpu);
lfc += stats->LinkFailureCount;
vlfc += stats->VLinkFailureCount;
mdac += stats->MissDiscAdvCount;
}
lesb->lesb_link_fail = htonl(lfc);
lesb->lesb_vlink_fail = htonl(vlfc);
lesb->lesb_miss_fka = htonl(mdac);
lesb->lesb_fcs_error =
htonl(dev_get_stats(netdev, &temp)->rx_crc_errors);
}
void fcoe_get_lesb(struct fc_lport *lport,
struct fc_els_lesb *fc_lesb)
{
struct net_device *netdev = fcoe_get_netdev(lport);
__fcoe_get_lesb(lport, fc_lesb, netdev);
}
void fcoe_ctlr_get_lesb(struct fcoe_ctlr_device *ctlr_dev)
{
struct fcoe_ctlr *fip = fcoe_ctlr_device_priv(ctlr_dev);
struct net_device *netdev = fcoe_get_netdev(fip->lp);
struct fcoe_fc_els_lesb *fcoe_lesb;
struct fc_els_lesb fc_lesb;
__fcoe_get_lesb(fip->lp, &fc_lesb, netdev);
fcoe_lesb = (struct fcoe_fc_els_lesb *)(&fc_lesb);
ctlr_dev->lesb.lesb_link_fail =
ntohl(fcoe_lesb->lesb_link_fail);
ctlr_dev->lesb.lesb_vlink_fail =
ntohl(fcoe_lesb->lesb_vlink_fail);
ctlr_dev->lesb.lesb_miss_fka =
ntohl(fcoe_lesb->lesb_miss_fka);
ctlr_dev->lesb.lesb_symb_err =
ntohl(fcoe_lesb->lesb_symb_err);
ctlr_dev->lesb.lesb_err_block =
ntohl(fcoe_lesb->lesb_err_block);
ctlr_dev->lesb.lesb_fcs_error =
ntohl(fcoe_lesb->lesb_fcs_error);
}
void fcoe_wwn_to_str(u64 wwn, char *buf, int len)
{
u8 wwpn[8];
u64_to_wwn(wwn, wwpn);
snprintf(buf, len, "%02x%02x%02x%02x%02x%02x%02x%02x",
wwpn[0], wwpn[1], wwpn[2], wwpn[3],
wwpn[4], wwpn[5], wwpn[6], wwpn[7]);
}
int fcoe_validate_vport_create(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port;
int rc = 0;
char buf[32];
mutex_lock(&n_port->lp_mutex);
fcoe_wwn_to_str(vport->port_name, buf, sizeof(buf));
if (!memcmp(&n_port->wwpn, &vport->port_name, sizeof(u64))) {
LIBFCOE_TRANSPORT_DBG("vport WWPN 0x%s is same as that of the "
"base port WWPN\n", buf);
rc = -EINVAL;
goto out;
}
list_for_each_entry(vn_port, &n_port->vports, list) {
if (!memcmp(&vn_port->wwpn, &vport->port_name, sizeof(u64))) {
LIBFCOE_TRANSPORT_DBG("vport with given WWPN 0x%s "
"already exists\n", buf);
rc = -EINVAL;
break;
}
}
out:
mutex_unlock(&n_port->lp_mutex);
return rc;
}
int fcoe_get_wwn(struct net_device *netdev, u64 *wwn, int type)
{
const struct net_device_ops *ops = netdev->netdev_ops;
if (ops->ndo_fcoe_get_wwn)
return ops->ndo_fcoe_get_wwn(netdev, wwn, type);
return -EINVAL;
}
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
len = skb_frag_size(frag);
while (len > 0) {
clen = min(len, PAGE_SIZE - (off & ~PAGE_MASK));
data = kmap_atomic(
skb_frag_page(frag) + (off >> PAGE_SHIFT));
crc = crc32(crc, data + (off & ~PAGE_MASK), clen);
kunmap_atomic(data);
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
static int fcoe_transport_exit(void)
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
LIBFCOE_TRANSPORT_DBG("NETDEV_UNREGISTER %s\n",
netdev->name);
fcoe_del_netdev_mapping(netdev);
break;
}
return NOTIFY_OK;
}
ssize_t fcoe_ctlr_create_store(struct bus_type *bus,
const char *buf, size_t count)
{
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
struct fcoe_ctlr_device *ctlr_dev = NULL;
int rc = 0;
int err;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buf);
if (!netdev) {
LIBFCOE_TRANSPORT_DBG("Invalid device %s.\n", buf);
rc = -ENODEV;
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
rc = -ENODEV;
goto out_putdev;
}
err = ft->alloc ? ft->alloc(netdev) : -ENODEV;
if (err) {
fcoe_del_netdev_mapping(netdev);
rc = -ENOMEM;
goto out_putdev;
}
err = fcoe_add_netdev_mapping(netdev, ft);
if (err) {
LIBFCOE_TRANSPORT_DBG("failed to add new netdev mapping "
"for FCoE transport %s for %s.\n",
ft->name, netdev->name);
rc = -ENODEV;
goto out_putdev;
}
LIBFCOE_TRANSPORT_DBG("transport %s %s to create fcoe on %s.\n",
ft->name, (ctlr_dev) ? "succeeded" : "failed",
netdev->name);
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
if (rc)
return rc;
return count;
}
ssize_t fcoe_ctlr_destroy_store(struct bus_type *bus,
const char *buf, size_t count)
{
int rc = -ENODEV;
struct net_device *netdev = NULL;
struct fcoe_transport *ft = NULL;
mutex_lock(&ft_mutex);
netdev = fcoe_if_to_netdev(buf);
if (!netdev) {
LIBFCOE_TRANSPORT_DBG("invalid device %s.\n", buf);
goto out_nodev;
}
ft = fcoe_netdev_map_lookup(netdev);
if (!ft) {
LIBFCOE_TRANSPORT_DBG("no FCoE transport found for %s.\n",
netdev->name);
goto out_putdev;
}
rc = ft->destroy(netdev);
if (rc)
goto out_putdev;
fcoe_del_netdev_mapping(netdev);
LIBFCOE_TRANSPORT_DBG("transport %s %s to destroy fcoe on %s.\n",
ft->name, (rc) ? "failed" : "succeeded",
netdev->name);
rc = count;
out_putdev:
dev_put(netdev);
out_nodev:
mutex_unlock(&ft_mutex);
return rc;
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
int rc = 0;
rc = fcoe_transport_init();
if (rc)
return rc;
rc = fcoe_sysfs_setup();
if (rc)
fcoe_transport_exit();
return rc;
}
static void __exit libfcoe_exit(void)
{
fcoe_sysfs_teardown();
fcoe_transport_exit();
}
