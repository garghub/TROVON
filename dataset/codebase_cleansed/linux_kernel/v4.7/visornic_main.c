static int
visor_copy_fragsinfo_from_skb(struct sk_buff *skb, unsigned int firstfraglen,
unsigned int frags_max,
struct phys_info frags[])
{
unsigned int count = 0, frag, size, offset = 0, numfrags;
unsigned int total_count;
numfrags = skb_shinfo(skb)->nr_frags;
total_count = numfrags + (firstfraglen / PI_PAGE_SIZE);
if (firstfraglen % PI_PAGE_SIZE)
total_count++;
if (total_count > frags_max) {
if (skb_linearize(skb))
return -EINVAL;
numfrags = skb_shinfo(skb)->nr_frags;
firstfraglen = 0;
}
while (firstfraglen) {
if (count == frags_max)
return -EINVAL;
frags[count].pi_pfn =
page_to_pfn(virt_to_page(skb->data + offset));
frags[count].pi_off =
(unsigned long)(skb->data + offset) & PI_PAGE_MASK;
size = min_t(unsigned int, firstfraglen,
PI_PAGE_SIZE - frags[count].pi_off);
frags[count].pi_len = size;
firstfraglen -= size;
offset += size;
count++;
}
if (numfrags) {
if ((count + numfrags) > frags_max)
return -EINVAL;
for (frag = 0; frag < numfrags; frag++) {
count = add_physinfo_entries(page_to_pfn(
skb_frag_page(&skb_shinfo(skb)->frags[frag])),
skb_shinfo(skb)->frags[frag].
page_offset,
skb_shinfo(skb)->frags[frag].
size, count, frags_max, frags);
if (!count)
return -EINVAL;
}
}
if (skb_shinfo(skb)->frag_list) {
struct sk_buff *skbinlist;
int c;
for (skbinlist = skb_shinfo(skb)->frag_list; skbinlist;
skbinlist = skbinlist->next) {
c = visor_copy_fragsinfo_from_skb(skbinlist,
skbinlist->len -
skbinlist->data_len,
frags_max - count,
&frags[count]);
if (c < 0)
return c;
count += c;
}
}
return count;
}
static ssize_t enable_ints_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *ppos)
{
return count;
}
static void
visornic_serverdown_complete(struct visornic_devdata *devdata)
{
struct net_device *netdev;
netdev = devdata->netdev;
del_timer_sync(&devdata->irq_poll_timer);
rtnl_lock();
dev_close(netdev);
rtnl_unlock();
atomic_set(&devdata->num_rcvbuf_in_iovm, 0);
devdata->chstat.sent_xmit = 0;
devdata->chstat.got_xmit_done = 0;
if (devdata->server_down_complete_func)
(*devdata->server_down_complete_func)(devdata->dev, 0);
devdata->server_down = true;
devdata->server_change_state = false;
devdata->server_down_complete_func = NULL;
}
static int
visornic_serverdown(struct visornic_devdata *devdata,
visorbus_state_complete_func complete_func)
{
unsigned long flags;
int err;
spin_lock_irqsave(&devdata->priv_lock, flags);
if (devdata->server_change_state) {
dev_dbg(&devdata->dev->device, "%s changing state\n",
__func__);
err = -EINVAL;
goto err_unlock;
}
if (devdata->server_down) {
dev_dbg(&devdata->dev->device, "%s already down\n",
__func__);
err = -EINVAL;
goto err_unlock;
}
if (devdata->going_away) {
dev_dbg(&devdata->dev->device,
"%s aborting because device removal pending\n",
__func__);
err = -ENODEV;
goto err_unlock;
}
devdata->server_change_state = true;
devdata->server_down_complete_func = complete_func;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
visornic_serverdown_complete(devdata);
return 0;
err_unlock:
spin_unlock_irqrestore(&devdata->priv_lock, flags);
return err;
}
static struct sk_buff *
alloc_rcv_buf(struct net_device *netdev)
{
struct sk_buff *skb;
skb = alloc_skb(RCVPOST_BUF_SIZE, GFP_ATOMIC);
if (!skb)
return NULL;
skb->dev = netdev;
skb->len = RCVPOST_BUF_SIZE;
skb->data_len = 0;
return skb;
}
static inline void
post_skb(struct uiscmdrsp *cmdrsp,
struct visornic_devdata *devdata, struct sk_buff *skb)
{
cmdrsp->net.buf = skb;
cmdrsp->net.rcvpost.frag.pi_pfn = page_to_pfn(virt_to_page(skb->data));
cmdrsp->net.rcvpost.frag.pi_off =
(unsigned long)skb->data & PI_PAGE_MASK;
cmdrsp->net.rcvpost.frag.pi_len = skb->len;
cmdrsp->net.rcvpost.unique_num = devdata->incarnation_id;
if ((cmdrsp->net.rcvpost.frag.pi_off + skb->len) <= PI_PAGE_SIZE) {
cmdrsp->net.type = NET_RCV_POST;
cmdrsp->cmdtype = CMD_NET_TYPE;
if (visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
cmdrsp)) {
atomic_inc(&devdata->num_rcvbuf_in_iovm);
devdata->chstat.sent_post++;
} else {
devdata->chstat.sent_post_failed++;
}
}
}
static void
send_enbdis(struct net_device *netdev, int state,
struct visornic_devdata *devdata)
{
devdata->cmdrsp_rcv->net.enbdis.enable = state;
devdata->cmdrsp_rcv->net.enbdis.context = netdev;
devdata->cmdrsp_rcv->net.type = NET_RCV_ENBDIS;
devdata->cmdrsp_rcv->cmdtype = CMD_NET_TYPE;
if (visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
devdata->cmdrsp_rcv))
devdata->chstat.sent_enbdis++;
}
static int
visornic_disable_with_timeout(struct net_device *netdev, const int timeout)
{
struct visornic_devdata *devdata = netdev_priv(netdev);
int i;
unsigned long flags;
int wait = 0;
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = 0;
devdata->enab_dis_acked = 0;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
send_enbdis(netdev, 0, devdata);
spin_lock_irqsave(&devdata->priv_lock, flags);
while ((timeout == VISORNIC_INFINITE_RSP_WAIT) ||
(wait < timeout)) {
if (devdata->enab_dis_acked)
break;
if (devdata->server_down || devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_dbg(&netdev->dev, "%s server went away\n",
__func__);
return -EIO;
}
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
wait += schedule_timeout(msecs_to_jiffies(10));
spin_lock_irqsave(&devdata->priv_lock, flags);
}
if (atomic_read(&devdata->usage) > 1) {
while (1) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
schedule_timeout(msecs_to_jiffies(10));
spin_lock_irqsave(&devdata->priv_lock, flags);
if (atomic_read(&devdata->usage))
break;
}
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
netif_stop_queue(netdev);
napi_disable(&devdata->napi);
skb_queue_purge(&devdata->xmitbufhead);
for (i = 0; i < devdata->num_rcv_bufs; i++) {
if (devdata->rcvbuf[i]) {
kfree_skb(devdata->rcvbuf[i]);
devdata->rcvbuf[i] = NULL;
}
}
return 0;
}
static int
init_rcv_bufs(struct net_device *netdev, struct visornic_devdata *devdata)
{
int i, count;
for (i = 0; i < devdata->num_rcv_bufs; i++) {
devdata->rcvbuf[i] = alloc_rcv_buf(netdev);
if (!devdata->rcvbuf[i])
break;
}
if (i == 0)
return -ENOMEM;
count = i;
if (count < ((2 * devdata->num_rcv_bufs) / 3)) {
for (i = 0; i < count; i++) {
kfree_skb(devdata->rcvbuf[i]);
devdata->rcvbuf[i] = NULL;
}
return -ENOMEM;
}
for (i = 0; i < count; i++)
post_skb(devdata->cmdrsp_rcv, devdata, devdata->rcvbuf[i]);
return 0;
}
static int
visornic_enable_with_timeout(struct net_device *netdev, const int timeout)
{
int i;
struct visornic_devdata *devdata = netdev_priv(netdev);
unsigned long flags;
int wait = 0;
i = init_rcv_bufs(netdev, devdata);
if (i < 0) {
dev_err(&netdev->dev,
"%s failed to init rcv bufs (%d)\n", __func__, i);
return i;
}
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = 1;
devdata->enab_dis_acked = 0;
devdata->n_rcv_packets_not_accepted = 0;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
napi_enable(&devdata->napi);
send_enbdis(netdev, 1, devdata);
spin_lock_irqsave(&devdata->priv_lock, flags);
while ((timeout == VISORNIC_INFINITE_RSP_WAIT) ||
(wait < timeout)) {
if (devdata->enab_dis_acked)
break;
if (devdata->server_down || devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_dbg(&netdev->dev, "%s server went away\n",
__func__);
return -EIO;
}
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
wait += schedule_timeout(msecs_to_jiffies(10));
spin_lock_irqsave(&devdata->priv_lock, flags);
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
if (!devdata->enab_dis_acked) {
dev_err(&netdev->dev, "%s missing ACK\n", __func__);
return -EIO;
}
netif_start_queue(netdev);
return 0;
}
static void
visornic_timeout_reset(struct work_struct *work)
{
struct visornic_devdata *devdata;
struct net_device *netdev;
int response = 0;
devdata = container_of(work, struct visornic_devdata, timeout_reset);
netdev = devdata->netdev;
rtnl_lock();
if (!netif_running(netdev)) {
rtnl_unlock();
return;
}
response = visornic_disable_with_timeout(netdev,
VISORNIC_INFINITE_RSP_WAIT);
if (response)
goto call_serverdown;
response = visornic_enable_with_timeout(netdev,
VISORNIC_INFINITE_RSP_WAIT);
if (response)
goto call_serverdown;
rtnl_unlock();
return;
call_serverdown:
visornic_serverdown(devdata, NULL);
rtnl_unlock();
}
static int
visornic_open(struct net_device *netdev)
{
visornic_enable_with_timeout(netdev, VISORNIC_INFINITE_RSP_WAIT);
return 0;
}
static int
visornic_close(struct net_device *netdev)
{
visornic_disable_with_timeout(netdev, VISORNIC_INFINITE_RSP_WAIT);
return 0;
}
static unsigned long devdata_xmits_outstanding(struct visornic_devdata *devdata)
{
if (devdata->chstat.sent_xmit >= devdata->chstat.got_xmit_done)
return devdata->chstat.sent_xmit -
devdata->chstat.got_xmit_done;
return (ULONG_MAX - devdata->chstat.got_xmit_done
+ devdata->chstat.sent_xmit + 1);
}
static inline bool vnic_hit_high_watermark(struct visornic_devdata *devdata,
ulong high_watermark)
{
return (devdata_xmits_outstanding(devdata) >= high_watermark);
}
static inline bool vnic_hit_low_watermark(struct visornic_devdata *devdata,
ulong low_watermark)
{
return (devdata_xmits_outstanding(devdata) <= low_watermark);
}
static int
visornic_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct visornic_devdata *devdata;
int len, firstfraglen, padlen;
struct uiscmdrsp *cmdrsp = NULL;
unsigned long flags;
devdata = netdev_priv(netdev);
spin_lock_irqsave(&devdata->priv_lock, flags);
if (netif_queue_stopped(netdev) || devdata->server_down ||
devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
dev_dbg(&netdev->dev,
"%s busy - queue stopped\n", __func__);
kfree_skb(skb);
return NETDEV_TX_OK;
}
len = skb->len;
firstfraglen = skb->len - skb->data_len;
if (firstfraglen < ETH_HEADER_SIZE) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
dev_err(&netdev->dev,
"%s busy - first frag too small (%d)\n",
__func__, firstfraglen);
kfree_skb(skb);
return NETDEV_TX_OK;
}
if ((len < ETH_MIN_PACKET_SIZE) &&
((skb_end_pointer(skb) - skb->data) >= ETH_MIN_PACKET_SIZE)) {
padlen = ETH_MIN_PACKET_SIZE - len;
memset(&skb->data[len], 0, padlen);
skb->tail += padlen;
skb->len += padlen;
len += padlen;
firstfraglen += padlen;
}
cmdrsp = devdata->xmit_cmdrsp;
memset(cmdrsp, 0, SIZEOF_CMDRSP);
cmdrsp->net.type = NET_XMIT;
cmdrsp->cmdtype = CMD_NET_TYPE;
cmdrsp->net.buf = skb;
if (vnic_hit_high_watermark(devdata,
devdata->max_outstanding_net_xmits)) {
devdata->chstat.reject_count++;
if (!devdata->queuefullmsg_logged &&
((devdata->chstat.reject_count & 0x3ff) == 1))
devdata->queuefullmsg_logged = 1;
netif_stop_queue(netdev);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
dev_dbg(&netdev->dev,
"%s busy - waiting for iovm to catch up\n",
__func__);
kfree_skb(skb);
return NETDEV_TX_OK;
}
if (devdata->queuefullmsg_logged)
devdata->queuefullmsg_logged = 0;
if (skb->ip_summed == CHECKSUM_UNNECESSARY) {
cmdrsp->net.xmt.lincsum.valid = 1;
cmdrsp->net.xmt.lincsum.protocol = skb->protocol;
if (skb_transport_header(skb) > skb->data) {
cmdrsp->net.xmt.lincsum.hrawoff =
skb_transport_header(skb) - skb->data;
cmdrsp->net.xmt.lincsum.hrawoff = 1;
}
if (skb_network_header(skb) > skb->data) {
cmdrsp->net.xmt.lincsum.nhrawoff =
skb_network_header(skb) - skb->data;
cmdrsp->net.xmt.lincsum.nhrawoffv = 1;
}
cmdrsp->net.xmt.lincsum.csum = skb->csum;
} else {
cmdrsp->net.xmt.lincsum.valid = 0;
}
cmdrsp->net.xmt.len = len;
memcpy(cmdrsp->net.xmt.ethhdr, skb->data, ETH_HEADER_SIZE);
cmdrsp->net.xmt.num_frags =
visor_copy_fragsinfo_from_skb(skb, firstfraglen,
MAX_PHYS_INFO,
cmdrsp->net.xmt.frags);
if (cmdrsp->net.xmt.num_frags < 0) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
dev_err(&netdev->dev,
"%s busy - copy frags failed\n", __func__);
kfree_skb(skb);
return NETDEV_TX_OK;
}
if (!visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART, cmdrsp)) {
netif_stop_queue(netdev);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
dev_dbg(&netdev->dev,
"%s busy - signalinsert failed\n", __func__);
kfree_skb(skb);
return NETDEV_TX_OK;
}
skb_queue_head(&devdata->xmitbufhead, skb);
devdata->net_stats.tx_packets++;
devdata->net_stats.tx_bytes += skb->len;
devdata->chstat.sent_xmit++;
if (vnic_hit_high_watermark(devdata,
devdata->upper_threshold_net_xmits)) {
netif_stop_queue(netdev);
dev_dbg(&netdev->dev,
"%s busy - invoking iovm flow control\n",
__func__);
devdata->flow_control_upper_hits++;
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
return NETDEV_TX_OK;
}
static struct net_device_stats *
visornic_get_stats(struct net_device *netdev)
{
struct visornic_devdata *devdata = netdev_priv(netdev);
return &devdata->net_stats;
}
static int
visornic_change_mtu(struct net_device *netdev, int new_mtu)
{
return -EINVAL;
}
static void
visornic_set_multi(struct net_device *netdev)
{
struct uiscmdrsp *cmdrsp;
struct visornic_devdata *devdata = netdev_priv(netdev);
if (devdata->old_flags != netdev->flags) {
if ((netdev->flags & IFF_PROMISC) !=
(devdata->old_flags & IFF_PROMISC)) {
cmdrsp = kmalloc(SIZEOF_CMDRSP, GFP_ATOMIC);
if (!cmdrsp)
return;
cmdrsp->cmdtype = CMD_NET_TYPE;
cmdrsp->net.type = NET_RCV_PROMISC;
cmdrsp->net.enbdis.context = netdev;
cmdrsp->net.enbdis.enable =
netdev->flags & IFF_PROMISC;
visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
cmdrsp);
kfree(cmdrsp);
}
devdata->old_flags = netdev->flags;
}
}
static void
visornic_xmit_timeout(struct net_device *netdev)
{
struct visornic_devdata *devdata = netdev_priv(netdev);
unsigned long flags;
spin_lock_irqsave(&devdata->priv_lock, flags);
if (devdata->going_away) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_dbg(&devdata->dev->device,
"%s aborting because device removal pending\n",
__func__);
return;
}
if (!devdata->enabled ||
(devdata->server_down && !devdata->server_change_state)) {
dev_dbg(&netdev->dev, "%s no processing\n",
__func__);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
return;
}
schedule_work(&devdata->timeout_reset);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
}
static inline int
repost_return(struct uiscmdrsp *cmdrsp, struct visornic_devdata *devdata,
struct sk_buff *skb, struct net_device *netdev)
{
struct net_pkt_rcv copy;
int i = 0, cc, numreposted;
int found_skb = 0;
int status = 0;
copy = cmdrsp->net.rcv;
switch (copy.numrcvbufs) {
case 0:
devdata->n_rcv0++;
break;
case 1:
devdata->n_rcv1++;
break;
case 2:
devdata->n_rcv2++;
break;
default:
devdata->n_rcvx++;
break;
}
for (cc = 0, numreposted = 0; cc < copy.numrcvbufs; cc++) {
for (i = 0; i < devdata->num_rcv_bufs; i++) {
if (devdata->rcvbuf[i] != copy.rcvbuf[cc])
continue;
if ((skb) && devdata->rcvbuf[i] == skb) {
devdata->found_repost_rcvbuf_cnt++;
found_skb = 1;
devdata->repost_found_skb_cnt++;
}
devdata->rcvbuf[i] = alloc_rcv_buf(netdev);
if (!devdata->rcvbuf[i]) {
devdata->num_rcv_bufs_could_not_alloc++;
devdata->alloc_failed_in_repost_rtn_cnt++;
status = -ENOMEM;
break;
}
post_skb(cmdrsp, devdata, devdata->rcvbuf[i]);
numreposted++;
break;
}
}
if (numreposted != copy.numrcvbufs) {
devdata->n_repost_deficit++;
status = -EINVAL;
}
if (skb) {
if (found_skb) {
kfree_skb(skb);
} else {
status = -EINVAL;
devdata->bad_rcv_buf++;
}
}
return status;
}
static int
visornic_rx(struct uiscmdrsp *cmdrsp)
{
struct visornic_devdata *devdata;
struct sk_buff *skb, *prev, *curr;
struct net_device *netdev;
int cc, currsize, off;
struct ethhdr *eth;
unsigned long flags;
int rx_count = 0;
skb = cmdrsp->net.buf;
netdev = skb->dev;
devdata = netdev_priv(netdev);
spin_lock_irqsave(&devdata->priv_lock, flags);
atomic_dec(&devdata->num_rcvbuf_in_iovm);
skb->len = cmdrsp->net.rcv.rcv_done_len;
devdata->net_stats.rx_packets++;
devdata->net_stats.rx_bytes += skb->len;
if (!(devdata->enabled && devdata->enab_dis_acked)) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
repost_return(cmdrsp, devdata, skb, netdev);
return rx_count;
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
if (skb->len > RCVPOST_BUF_SIZE) {
if (cmdrsp->net.rcv.numrcvbufs < 2) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev,
"repost_return failed");
return rx_count;
}
skb->tail += RCVPOST_BUF_SIZE;
skb->data_len = skb->len - RCVPOST_BUF_SIZE;
} else {
if (cmdrsp->net.rcv.numrcvbufs != 1) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev,
"repost_return failed");
return rx_count;
}
skb->tail += skb->len;
skb->data_len = 0;
}
off = skb_tail_pointer(skb) - skb->data;
if (cmdrsp->net.rcv.rcvbuf[0] != skb) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev, "repost_return failed");
return rx_count;
}
if (cmdrsp->net.rcv.numrcvbufs > 1) {
for (cc = 1, prev = NULL;
cc < cmdrsp->net.rcv.numrcvbufs; cc++) {
curr = (struct sk_buff *)cmdrsp->net.rcv.rcvbuf[cc];
curr->next = NULL;
if (!prev)
skb_shinfo(skb)->frag_list = curr;
else
prev->next = curr;
prev = curr;
currsize = min(skb->len - off,
(unsigned int)RCVPOST_BUF_SIZE);
curr->len = currsize;
curr->tail += currsize;
curr->data_len = 0;
off += currsize;
}
if (skb->len != off) {
netdev_err(devdata->netdev,
"something wrong; skb->len:%d != off:%d\n",
skb->len, off);
}
}
skb->protocol = eth_type_trans(skb, netdev);
eth = eth_hdr(skb);
skb->csum = 0;
skb->ip_summed = CHECKSUM_NONE;
do {
if (netdev->flags & IFF_PROMISC)
break;
if (skb->pkt_type == PACKET_BROADCAST) {
if (netdev->flags & IFF_BROADCAST)
break;
} else if (skb->pkt_type == PACKET_MULTICAST) {
if ((netdev->flags & IFF_MULTICAST) &&
(netdev_mc_count(netdev))) {
struct netdev_hw_addr *ha;
int found_mc = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (ether_addr_equal(eth->h_dest,
ha->addr)) {
found_mc = 1;
break;
}
}
if (found_mc)
break;
}
} else if (skb->pkt_type == PACKET_HOST) {
break;
} else if (skb->pkt_type == PACKET_OTHERHOST) {
dev_err(&devdata->netdev->dev,
"**** FAILED to deliver rcv packet to OS; name:%s Dest:%pM VNIC:%pM\n",
netdev->name, eth->h_dest, netdev->dev_addr);
}
devdata->n_rcv_packets_not_accepted++;
repost_return(cmdrsp, devdata, skb, netdev);
return rx_count;
} while (0);
rx_count++;
netif_receive_skb(skb);
skb = NULL;
repost_return(cmdrsp, devdata, skb, netdev);
return rx_count;
}
static struct visornic_devdata *
devdata_initialize(struct visornic_devdata *devdata, struct visor_device *dev)
{
if (!devdata)
return NULL;
devdata->dev = dev;
devdata->incarnation_id = get_jiffies_64();
return devdata;
}
static void devdata_release(struct visornic_devdata *devdata)
{
kfree(devdata->rcvbuf);
kfree(devdata->cmdrsp_rcv);
kfree(devdata->xmit_cmdrsp);
}
static ssize_t info_debugfs_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
ssize_t bytes_read = 0;
int str_pos = 0;
struct visornic_devdata *devdata;
struct net_device *dev;
char *vbuf;
if (len > MAX_BUF)
len = MAX_BUF;
vbuf = kzalloc(len, GFP_KERNEL);
if (!vbuf)
return -ENOMEM;
rcu_read_lock();
for_each_netdev_rcu(current->nsproxy->net_ns, dev) {
if ((dev->netdev_ops != &visornic_dev_ops) ||
(!netif_queue_stopped(dev)))
continue;
devdata = netdev_priv(dev);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"netdev = %s (0x%p), MAC Addr %pM\n",
dev->name,
dev,
dev->dev_addr);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"VisorNic Dev Info = 0x%p\n", devdata);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" num_rcv_bufs = %d\n",
devdata->num_rcv_bufs);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" max_oustanding_next_xmits = %lu\n",
devdata->max_outstanding_net_xmits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" upper_threshold_net_xmits = %lu\n",
devdata->upper_threshold_net_xmits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" lower_threshold_net_xmits = %lu\n",
devdata->lower_threshold_net_xmits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" queuefullmsg_logged = %d\n",
devdata->queuefullmsg_logged);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.got_rcv = %lu\n",
devdata->chstat.got_rcv);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.got_enbdisack = %lu\n",
devdata->chstat.got_enbdisack);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.got_xmit_done = %lu\n",
devdata->chstat.got_xmit_done);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.xmit_fail = %lu\n",
devdata->chstat.xmit_fail);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.sent_enbdis = %lu\n",
devdata->chstat.sent_enbdis);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.sent_promisc = %lu\n",
devdata->chstat.sent_promisc);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.sent_post = %lu\n",
devdata->chstat.sent_post);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.sent_post_failed = %lu\n",
devdata->chstat.sent_post_failed);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.sent_xmit = %lu\n",
devdata->chstat.sent_xmit);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.reject_count = %lu\n",
devdata->chstat.reject_count);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" chstat.extra_rcvbufs_sent = %lu\n",
devdata->chstat.extra_rcvbufs_sent);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_rcv0 = %lu\n", devdata->n_rcv0);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_rcv1 = %lu\n", devdata->n_rcv1);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_rcv2 = %lu\n", devdata->n_rcv2);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_rcvx = %lu\n", devdata->n_rcvx);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" num_rcvbuf_in_iovm = %d\n",
atomic_read(&devdata->num_rcvbuf_in_iovm));
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" alloc_failed_in_if_needed_cnt = %lu\n",
devdata->alloc_failed_in_if_needed_cnt);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" alloc_failed_in_repost_rtn_cnt = %lu\n",
devdata->alloc_failed_in_repost_rtn_cnt);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" found_repost_rcvbuf_cnt = %lu\n",
devdata->found_repost_rcvbuf_cnt);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" repost_found_skb_cnt = %lu\n",
devdata->repost_found_skb_cnt);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_repost_deficit = %lu\n",
devdata->n_repost_deficit);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" bad_rcv_buf = %lu\n",
devdata->bad_rcv_buf);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" n_rcv_packets_not_accepted = %lu\n",
devdata->n_rcv_packets_not_accepted);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" interrupts_rcvd = %llu\n",
devdata->interrupts_rcvd);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" interrupts_notme = %llu\n",
devdata->interrupts_notme);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" interrupts_disabled = %llu\n",
devdata->interrupts_disabled);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" busy_cnt = %llu\n",
devdata->busy_cnt);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" flow_control_upper_hits = %llu\n",
devdata->flow_control_upper_hits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" flow_control_lower_hits = %llu\n",
devdata->flow_control_lower_hits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" netif_queue = %s\n",
netif_queue_stopped(devdata->netdev) ?
"stopped" : "running");
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" xmits_outstanding = %lu\n",
devdata_xmits_outstanding(devdata));
}
rcu_read_unlock();
bytes_read = simple_read_from_buffer(buf, len, offset, vbuf, str_pos);
kfree(vbuf);
return bytes_read;
}
static void
send_rcv_posts_if_needed(struct visornic_devdata *devdata)
{
int i;
struct net_device *netdev;
struct uiscmdrsp *cmdrsp = devdata->cmdrsp_rcv;
int cur_num_rcv_bufs_to_alloc, rcv_bufs_allocated;
if (!(devdata->enabled && devdata->enab_dis_acked))
return;
netdev = devdata->netdev;
rcv_bufs_allocated = 0;
cur_num_rcv_bufs_to_alloc = devdata->num_rcv_bufs_could_not_alloc;
while (cur_num_rcv_bufs_to_alloc > 0) {
cur_num_rcv_bufs_to_alloc--;
for (i = 0; i < devdata->num_rcv_bufs; i++) {
if (devdata->rcvbuf[i])
continue;
devdata->rcvbuf[i] = alloc_rcv_buf(netdev);
if (!devdata->rcvbuf[i]) {
devdata->alloc_failed_in_if_needed_cnt++;
break;
}
rcv_bufs_allocated++;
post_skb(cmdrsp, devdata, devdata->rcvbuf[i]);
devdata->chstat.extra_rcvbufs_sent++;
}
}
devdata->num_rcv_bufs_could_not_alloc -= rcv_bufs_allocated;
}
static void
drain_resp_queue(struct uiscmdrsp *cmdrsp, struct visornic_devdata *devdata)
{
while (visorchannel_signalremove(devdata->dev->visorchannel,
IOCHAN_FROM_IOPART,
cmdrsp))
;
}
static void
service_resp_queue(struct uiscmdrsp *cmdrsp, struct visornic_devdata *devdata,
int *rx_work_done, int budget)
{
unsigned long flags;
struct net_device *netdev;
while (*rx_work_done < budget) {
if (!visorchannel_signalremove(devdata->dev->visorchannel,
IOCHAN_FROM_IOPART,
cmdrsp))
break;
switch (cmdrsp->net.type) {
case NET_RCV:
devdata->chstat.got_rcv++;
*rx_work_done += visornic_rx(cmdrsp);
break;
case NET_XMIT_DONE:
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->chstat.got_xmit_done++;
if (cmdrsp->net.xmtdone.xmt_done_result)
devdata->chstat.xmit_fail++;
netdev = ((struct sk_buff *)cmdrsp->net.buf)->dev;
if ((netdev == devdata->netdev) &&
netif_queue_stopped(netdev)) {
if (vnic_hit_low_watermark
(devdata,
devdata->lower_threshold_net_xmits)) {
netif_wake_queue(netdev);
devdata->flow_control_lower_hits++;
}
}
skb_unlink(cmdrsp->net.buf, &devdata->xmitbufhead);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
kfree_skb(cmdrsp->net.buf);
break;
case NET_RCV_ENBDIS_ACK:
devdata->chstat.got_enbdisack++;
netdev = (struct net_device *)
cmdrsp->net.enbdis.context;
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enab_dis_acked = 1;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
if (devdata->server_down &&
devdata->server_change_state) {
devdata->server_down = false;
devdata->server_change_state = false;
netif_wake_queue(netdev);
netif_carrier_on(netdev);
}
break;
case NET_CONNECT_STATUS:
netdev = devdata->netdev;
if (cmdrsp->net.enbdis.enable == 1) {
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = cmdrsp->net.enbdis.enable;
spin_unlock_irqrestore(&devdata->priv_lock,
flags);
netif_wake_queue(netdev);
netif_carrier_on(netdev);
} else {
netif_stop_queue(netdev);
netif_carrier_off(netdev);
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = cmdrsp->net.enbdis.enable;
spin_unlock_irqrestore(&devdata->priv_lock,
flags);
}
break;
default:
break;
}
}
}
static int visornic_poll(struct napi_struct *napi, int budget)
{
struct visornic_devdata *devdata = container_of(napi,
struct visornic_devdata,
napi);
int rx_count = 0;
send_rcv_posts_if_needed(devdata);
service_resp_queue(devdata->cmdrsp, devdata, &rx_count, budget);
if (rx_count < budget)
napi_complete(napi);
return rx_count;
}
static void
poll_for_irq(unsigned long v)
{
struct visornic_devdata *devdata = (struct visornic_devdata *)v;
if (!visorchannel_signalempty(
devdata->dev->visorchannel,
IOCHAN_FROM_IOPART))
napi_schedule(&devdata->napi);
atomic_set(&devdata->interrupt_rcvd, 0);
mod_timer(&devdata->irq_poll_timer, msecs_to_jiffies(2));
}
static int visornic_probe(struct visor_device *dev)
{
struct visornic_devdata *devdata = NULL;
struct net_device *netdev = NULL;
int err;
int channel_offset = 0;
u64 features;
netdev = alloc_etherdev(sizeof(struct visornic_devdata));
if (!netdev) {
dev_err(&dev->device,
"%s alloc_etherdev failed\n", __func__);
return -ENOMEM;
}
netdev->netdev_ops = &visornic_dev_ops;
netdev->watchdog_timeo = 5 * HZ;
SET_NETDEV_DEV(netdev, &dev->device);
netdev->addr_len = ETH_ALEN;
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.macaddr);
err = visorbus_read_channel(dev, channel_offset, netdev->dev_addr,
ETH_ALEN);
if (err < 0) {
dev_err(&dev->device,
"%s failed to get mac addr from chan (%d)\n",
__func__, err);
goto cleanup_netdev;
}
devdata = devdata_initialize(netdev_priv(netdev), dev);
if (!devdata) {
dev_err(&dev->device,
"%s devdata_initialize failed\n", __func__);
err = -ENOMEM;
goto cleanup_netdev;
}
drain_resp_queue(devdata->cmdrsp, devdata);
devdata->netdev = netdev;
dev_set_drvdata(&dev->device, devdata);
init_waitqueue_head(&devdata->rsp_queue);
spin_lock_init(&devdata->priv_lock);
devdata->enabled = 0;
atomic_set(&devdata->usage, 1);
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.num_rcv_bufs);
err = visorbus_read_channel(dev, channel_offset,
&devdata->num_rcv_bufs, 4);
if (err) {
dev_err(&dev->device,
"%s failed to get #rcv bufs from chan (%d)\n",
__func__, err);
goto cleanup_netdev;
}
devdata->rcvbuf = kcalloc(devdata->num_rcv_bufs,
sizeof(struct sk_buff *), GFP_KERNEL);
if (!devdata->rcvbuf) {
err = -ENOMEM;
goto cleanup_rcvbuf;
}
devdata->max_outstanding_net_xmits =
max_t(unsigned long, 3, ((devdata->num_rcv_bufs / 3) - 2));
devdata->upper_threshold_net_xmits =
max_t(unsigned long,
2, (devdata->max_outstanding_net_xmits - 1));
devdata->lower_threshold_net_xmits =
max_t(unsigned long,
1, (devdata->max_outstanding_net_xmits / 2));
skb_queue_head_init(&devdata->xmitbufhead);
devdata->cmdrsp_rcv = kmalloc(SIZEOF_CMDRSP, GFP_ATOMIC);
if (!devdata->cmdrsp_rcv) {
err = -ENOMEM;
goto cleanup_cmdrsp_rcv;
}
devdata->xmit_cmdrsp = kmalloc(SIZEOF_CMDRSP, GFP_ATOMIC);
if (!devdata->xmit_cmdrsp) {
err = -ENOMEM;
goto cleanup_xmit_cmdrsp;
}
INIT_WORK(&devdata->timeout_reset, visornic_timeout_reset);
devdata->server_down = false;
devdata->server_change_state = false;
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.mtu);
err = visorbus_read_channel(dev, channel_offset, &netdev->mtu, 4);
if (err) {
dev_err(&dev->device,
"%s failed to get mtu from chan (%d)\n",
__func__, err);
goto cleanup_xmit_cmdrsp;
}
netif_napi_add(netdev, &devdata->napi, visornic_poll, 64);
setup_timer(&devdata->irq_poll_timer, poll_for_irq,
(unsigned long)devdata);
mod_timer(&devdata->irq_poll_timer, msecs_to_jiffies(2));
channel_offset = offsetof(struct spar_io_channel_protocol,
channel_header.features);
err = visorbus_read_channel(dev, channel_offset, &features, 8);
if (err) {
dev_err(&dev->device,
"%s failed to get features from chan (%d)\n",
__func__, err);
goto cleanup_napi_add;
}
features |= ULTRA_IO_CHANNEL_IS_POLLING;
features |= ULTRA_IO_DRIVER_SUPPORTS_ENHANCED_RCVBUF_CHECKING;
err = visorbus_write_channel(dev, channel_offset, &features, 8);
if (err) {
dev_err(&dev->device,
"%s failed to set features in chan (%d)\n",
__func__, err);
goto cleanup_napi_add;
}
netif_napi_add(netdev, &devdata->napi, visornic_poll, NAPI_WEIGHT);
visorbus_enable_channel_interrupts(dev);
err = register_netdev(netdev);
if (err) {
dev_err(&dev->device,
"%s register_netdev failed (%d)\n", __func__, err);
goto cleanup_napi_add;
}
devdata->eth_debugfs_dir = debugfs_create_dir(netdev->name,
visornic_debugfs_dir);
if (!devdata->eth_debugfs_dir) {
dev_err(&dev->device,
"%s debugfs_create_dir %s failed\n",
__func__, netdev->name);
err = -ENOMEM;
goto cleanup_register_netdev;
}
dev_info(&dev->device, "%s success netdev=%s\n",
__func__, netdev->name);
return 0;
cleanup_register_netdev:
unregister_netdev(netdev);
cleanup_napi_add:
del_timer_sync(&devdata->irq_poll_timer);
netif_napi_del(&devdata->napi);
cleanup_xmit_cmdrsp:
kfree(devdata->xmit_cmdrsp);
cleanup_cmdrsp_rcv:
kfree(devdata->cmdrsp_rcv);
cleanup_rcvbuf:
kfree(devdata->rcvbuf);
cleanup_netdev:
free_netdev(netdev);
return err;
}
static void host_side_disappeared(struct visornic_devdata *devdata)
{
unsigned long flags;
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->dev = NULL;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
}
static void visornic_remove(struct visor_device *dev)
{
struct visornic_devdata *devdata = dev_get_drvdata(&dev->device);
struct net_device *netdev;
unsigned long flags;
if (!devdata) {
dev_err(&dev->device, "%s no devdata\n", __func__);
return;
}
spin_lock_irqsave(&devdata->priv_lock, flags);
if (devdata->going_away) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_err(&dev->device, "%s already being removed\n", __func__);
return;
}
devdata->going_away = true;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
netdev = devdata->netdev;
if (!netdev) {
dev_err(&dev->device, "%s not net device\n", __func__);
return;
}
cancel_work_sync(&devdata->timeout_reset);
debugfs_remove_recursive(devdata->eth_debugfs_dir);
unregister_netdev(netdev);
del_timer_sync(&devdata->irq_poll_timer);
netif_napi_del(&devdata->napi);
dev_set_drvdata(&dev->device, NULL);
host_side_disappeared(devdata);
devdata_release(devdata);
free_netdev(netdev);
}
static int visornic_pause(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visornic_devdata *devdata = dev_get_drvdata(&dev->device);
visornic_serverdown(devdata, complete_func);
return 0;
}
static int visornic_resume(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visornic_devdata *devdata;
struct net_device *netdev;
unsigned long flags;
devdata = dev_get_drvdata(&dev->device);
if (!devdata) {
dev_err(&dev->device, "%s no devdata\n", __func__);
return -EINVAL;
}
netdev = devdata->netdev;
spin_lock_irqsave(&devdata->priv_lock, flags);
if (devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_err(&dev->device, "%s server already changing state\n",
__func__);
return -EINVAL;
}
if (!devdata->server_down) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
dev_err(&dev->device, "%s server not down\n", __func__);
complete_func(dev, 0);
return 0;
}
devdata->server_change_state = true;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
mod_timer(&devdata->irq_poll_timer, msecs_to_jiffies(2));
init_rcv_bufs(netdev, devdata);
rtnl_lock();
dev_open(netdev);
rtnl_unlock();
complete_func(dev, 0);
return 0;
}
static int visornic_init(void)
{
struct dentry *ret;
int err = -ENOMEM;
visornic_debugfs_dir = debugfs_create_dir("visornic", NULL);
if (!visornic_debugfs_dir)
return err;
ret = debugfs_create_file("info", S_IRUSR, visornic_debugfs_dir, NULL,
&debugfs_info_fops);
if (!ret)
goto cleanup_debugfs;
ret = debugfs_create_file("enable_ints", S_IWUSR, visornic_debugfs_dir,
NULL, &debugfs_enable_ints_fops);
if (!ret)
goto cleanup_debugfs;
err = visorbus_register_visor_driver(&visornic_driver);
if (!err)
return 0;
cleanup_debugfs:
debugfs_remove_recursive(visornic_debugfs_dir);
return err;
}
static void visornic_cleanup(void)
{
visorbus_unregister_visor_driver(&visornic_driver);
debugfs_remove_recursive(visornic_debugfs_dir);
}
