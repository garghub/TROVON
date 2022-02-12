static unsigned int
visor_copy_fragsinfo_from_skb(struct sk_buff *skb, unsigned int firstfraglen,
unsigned int frags_max,
struct phys_info frags[])
{
unsigned int count = 0, ii, size, offset = 0, numfrags;
numfrags = skb_shinfo(skb)->nr_frags;
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
for (ii = 0; ii < numfrags; ii++) {
count = add_physinfo_entries(page_to_pfn(
skb_frag_page(&skb_shinfo(skb)->frags[ii])),
skb_shinfo(skb)->frags[ii].
page_offset,
skb_shinfo(skb)->frags[ii].
size, count, frags_max, frags);
if (!count)
return -EIO;
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
static int visor_thread_start(struct visor_thread_info *thrinfo,
int (*threadfn)(void *),
void *thrcontext, char *name)
{
init_completion(&thrinfo->has_stopped);
thrinfo->task = kthread_run(threadfn, thrcontext, name);
if (IS_ERR(thrinfo->task)) {
thrinfo->id = 0;
return -EINVAL;
}
thrinfo->id = thrinfo->task->pid;
return 0;
}
static void visor_thread_stop(struct visor_thread_info *thrinfo)
{
if (!thrinfo->id)
return;
kthread_stop(thrinfo->task);
if (wait_for_completion_timeout(&thrinfo->has_stopped, 60 * HZ))
thrinfo->id = 0;
}
static ssize_t info_debugfs_read(struct file *file, char __user *buf,
size_t len, loff_t *offset)
{
int i;
ssize_t bytes_read = 0;
int str_pos = 0;
struct visornic_devdata *devdata;
char *vbuf;
if (len > MAX_BUF)
len = MAX_BUF;
vbuf = kzalloc(len, GFP_KERNEL);
if (!vbuf)
return -ENOMEM;
for (i = 0; i < VISORNICSOPENMAX; i++) {
if (!num_visornic_open[i])
continue;
devdata = netdev_priv(num_visornic_open[i]);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"Vnic i = %d\n", i);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"netdev = %s (0x%p), MAC Addr %pM\n",
num_visornic_open[i]->name,
num_visornic_open[i],
num_visornic_open[i]->dev_addr);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
"VisorNic Dev Info = 0x%p\n", devdata);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" num_rcv_bufs = %d\n",
devdata->num_rcv_bufs);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" max_oustanding_next_xmits = %d\n",
devdata->max_outstanding_net_xmits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" upper_threshold_net_xmits = %d\n",
devdata->upper_threshold_net_xmits);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" lower_threshold_net_xmits = %d\n",
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
" thread_wait_ms = %d\n",
devdata->thread_wait_ms);
str_pos += scnprintf(vbuf + str_pos, len - str_pos,
" netif_queue = %s\n",
netif_queue_stopped(devdata->netdev) ?
"stopped" : "running");
}
bytes_read = simple_read_from_buffer(buf, len, offset, vbuf, str_pos);
kfree(vbuf);
return bytes_read;
}
static ssize_t enable_ints_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *ppos)
{
char buf[4];
int i, new_value;
struct visornic_devdata *devdata;
if (count >= ARRAY_SIZE(buf))
return -EINVAL;
buf[count] = '\0';
if (copy_from_user(buf, buffer, count))
return -EFAULT;
i = kstrtoint(buf, 10, &new_value);
if (i != 0)
return -EFAULT;
for (i = 0; i < VISORNICSOPENMAX; i++) {
if (num_visornic_open[i]) {
devdata = netdev_priv(num_visornic_open[i]);
}
}
return count;
}
static void
visornic_serverdown_complete(struct work_struct *work)
{
struct visornic_devdata *devdata;
struct net_device *netdev;
unsigned long flags;
int i = 0, count = 0;
devdata = container_of(work, struct visornic_devdata,
serverdown_completion);
netdev = devdata->netdev;
visor_thread_stop(&devdata->threadinfo);
netif_carrier_off(netdev);
netif_stop_queue(netdev);
skb_queue_purge(&devdata->xmitbufhead);
spin_lock_irqsave(&devdata->priv_lock, flags);
for (i = 0; i < devdata->num_rcv_bufs; i++) {
if (devdata->rcvbuf[i]) {
kfree_skb(devdata->rcvbuf[i]);
devdata->rcvbuf[i] = NULL;
count++;
}
}
atomic_set(&devdata->num_rcvbuf_in_iovm, 0);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->server_down = true;
devdata->server_change_state = false;
}
static int
visornic_serverdown(struct visornic_devdata *devdata)
{
if (!devdata->server_down && !devdata->server_change_state) {
devdata->server_change_state = true;
queue_work(visornic_serverdown_workqueue,
&devdata->serverdown_completion);
} else if (devdata->server_change_state) {
return -EINVAL;
}
return 0;
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
cmdrsp->net.rcvpost.unique_num = devdata->uniquenum;
if ((cmdrsp->net.rcvpost.frag.pi_off + skb->len) <= PI_PAGE_SIZE) {
cmdrsp->net.type = NET_RCV_POST;
cmdrsp->cmdtype = CMD_NET_TYPE;
visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
cmdrsp);
atomic_inc(&devdata->num_rcvbuf_in_iovm);
devdata->chstat.sent_post++;
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
visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART,
devdata->cmdrsp_rcv);
devdata->chstat.sent_enbdis++;
}
static int
visornic_disable_with_timeout(struct net_device *netdev, const int timeout)
{
struct visornic_devdata *devdata = netdev_priv(netdev);
int i;
unsigned long flags;
int wait = 0;
netif_stop_queue(netdev);
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = 0;
devdata->enab_dis_acked = 0;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
send_enbdis(netdev, 0, devdata);
spin_lock_irqsave(&devdata->priv_lock, flags);
while ((timeout == VISORNIC_INFINITE_RESPONSE_WAIT) ||
(wait < timeout)) {
if (devdata->enab_dis_acked)
break;
if (devdata->server_down || devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
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
for (i = 0; i < devdata->num_rcv_bufs; i++) {
if (devdata->rcvbuf[i]) {
kfree_skb(devdata->rcvbuf[i]);
devdata->rcvbuf[i] = NULL;
}
}
for (i = 0; i < VISORNICSOPENMAX; i++)
if (num_visornic_open[i] == netdev) {
num_visornic_open[i] = NULL;
break;
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
if (i < 0)
return i;
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = 1;
devdata->n_rcv_packets_not_accepted = 0;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
send_enbdis(netdev, 1, devdata);
spin_lock_irqsave(&devdata->priv_lock, flags);
while ((timeout == VISORNIC_INFINITE_RESPONSE_WAIT) ||
(wait < timeout)) {
if (devdata->enab_dis_acked)
break;
if (devdata->server_down || devdata->server_change_state) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
return -EIO;
}
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
wait += schedule_timeout(msecs_to_jiffies(10));
spin_lock_irqsave(&devdata->priv_lock, flags);
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
if (!devdata->enab_dis_acked)
return -EIO;
for (i = 0; i < VISORNICSOPENMAX; i++) {
if (!num_visornic_open[i]) {
num_visornic_open[i] = netdev;
break;
}
}
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
netif_stop_queue(netdev);
response = visornic_disable_with_timeout(netdev, 100);
if (response)
goto call_serverdown;
response = visornic_enable_with_timeout(netdev, 100);
if (response)
goto call_serverdown;
netif_wake_queue(netdev);
return;
call_serverdown:
visornic_serverdown(devdata);
}
static int
visornic_open(struct net_device *netdev)
{
visornic_enable_with_timeout(netdev, VISORNIC_INFINITE_RESPONSE_WAIT);
netif_start_queue(netdev);
return 0;
}
static int
visornic_close(struct net_device *netdev)
{
netif_stop_queue(netdev);
visornic_disable_with_timeout(netdev, VISORNIC_INFINITE_RESPONSE_WAIT);
return 0;
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
return NETDEV_TX_BUSY;
}
len = skb->len;
firstfraglen = skb->len - skb->data_len;
if (firstfraglen < ETH_HEADER_SIZE) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
return NETDEV_TX_BUSY;
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
if (((devdata->chstat.sent_xmit >= devdata->chstat.got_xmit_done) &&
(devdata->chstat.sent_xmit - devdata->chstat.got_xmit_done >=
devdata->max_outstanding_net_xmits)) ||
((devdata->chstat.sent_xmit < devdata->chstat.got_xmit_done) &&
(ULONG_MAX - devdata->chstat.got_xmit_done +
devdata->chstat.sent_xmit >=
devdata->max_outstanding_net_xmits))) {
devdata->chstat.reject_count++;
if (!devdata->queuefullmsg_logged &&
((devdata->chstat.reject_count & 0x3ff) == 1))
devdata->queuefullmsg_logged = 1;
netif_stop_queue(netdev);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
return NETDEV_TX_BUSY;
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
if (cmdrsp->net.xmt.num_frags == -1) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
return NETDEV_TX_BUSY;
}
if (!visorchannel_signalinsert(devdata->dev->visorchannel,
IOCHAN_TO_IOPART, cmdrsp)) {
netif_stop_queue(netdev);
spin_unlock_irqrestore(&devdata->priv_lock, flags);
devdata->busy_cnt++;
return NETDEV_TX_BUSY;
}
skb_queue_head(&devdata->xmitbufhead, skb);
netdev->trans_start = jiffies;
devdata->net_stats.tx_packets++;
devdata->net_stats.tx_bytes += skb->len;
devdata->chstat.sent_xmit++;
if (((devdata->chstat.sent_xmit >= devdata->chstat.got_xmit_done) &&
(devdata->chstat.sent_xmit - devdata->chstat.got_xmit_done >=
devdata->upper_threshold_net_xmits)) ||
((devdata->chstat.sent_xmit < devdata->chstat.got_xmit_done) &&
(ULONG_MAX - devdata->chstat.got_xmit_done +
devdata->chstat.sent_xmit >=
devdata->upper_threshold_net_xmits))) {
netif_stop_queue(netdev);
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
visornic_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
return -EOPNOTSUPP;
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
(netdev->flags & IFF_PROMISC);
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
if (!devdata->enabled ||
(devdata->server_down && !devdata->server_change_state)) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
return;
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
queue_work(visornic_timeout_reset_workqueue, &devdata->timeout_reset);
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
atomic_dec(&devdata->usage);
return status;
}
static void
visornic_rx(struct uiscmdrsp *cmdrsp)
{
struct visornic_devdata *devdata;
struct sk_buff *skb, *prev, *curr;
struct net_device *netdev;
int cc, currsize, off, status;
struct ethhdr *eth;
unsigned long flags;
#ifdef DEBUG
struct phys_info testfrags[MAX_PHYS_INFO];
#endif
skb = cmdrsp->net.buf;
netdev = skb->dev;
if (!netdev) {
kfree_skb(skb);
return;
}
devdata = netdev_priv(netdev);
spin_lock_irqsave(&devdata->priv_lock, flags);
atomic_dec(&devdata->num_rcvbuf_in_iovm);
devdata->net_stats.rx_packets++;
devdata->net_stats.rx_bytes = skb->len;
atomic_inc(&devdata->usage);
skb->len = cmdrsp->net.rcv.rcv_done_len;
if (!(devdata->enabled && devdata->enab_dis_acked)) {
spin_unlock_irqrestore(&devdata->priv_lock, flags);
repost_return(cmdrsp, devdata, skb, netdev);
return;
}
spin_unlock_irqrestore(&devdata->priv_lock, flags);
if (skb->len > RCVPOST_BUF_SIZE) {
if (cmdrsp->net.rcv.numrcvbufs < 2) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev,
"repost_return failed");
return;
}
skb->tail += RCVPOST_BUF_SIZE;
skb->data_len = skb->len - RCVPOST_BUF_SIZE;
} else {
if (cmdrsp->net.rcv.numrcvbufs != 1) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev,
"repost_return failed");
return;
}
skb->tail += skb->len;
skb->data_len = 0;
}
off = skb_tail_pointer(skb) - skb->data;
if (cmdrsp->net.rcv.rcvbuf[0] != skb) {
if (repost_return(cmdrsp, devdata, skb, netdev) < 0)
dev_err(&devdata->netdev->dev, "repost_return failed");
return;
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
#ifdef DEBUG
if (skb->len != off) {
dev_err(&devdata->netdev->dev,
"%s something wrong; skb->len:%d != off:%d\n",
netdev->name, skb->len, off);
}
cc = util_copy_fragsinfo_from_skb("rcvchaintest", skb,
RCVPOST_BUF_SIZE,
MAX_PHYS_INFO, testfrags);
if (cc != cmdrsp->net.rcv.numrcvbufs) {
dev_err(&devdata->netdev->dev,
"**** %s Something wrong; rcvd chain length %d different from one we calculated %d\n",
netdev->name, cmdrsp->net.rcv.numrcvbufs, cc);
}
for (i = 0; i < cc; i++) {
dev_inf(&devdata->netdev->dev,
"test:RCVPOST_BUF_SIZE:%d[%d] pfn:%llu off:0x%x len:%d\n",
RCVPOST_BUF_SIZE, i, testfrags[i].pi_pfn,
testfrags[i].pi_off, testfrags[i].pi_len);
}
#endif
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
return;
} while (0);
status = netif_rx(skb);
skb = NULL;
repost_return(cmdrsp, devdata, skb, netdev);
}
static struct visornic_devdata *
devdata_initialize(struct visornic_devdata *devdata, struct visor_device *dev)
{
int devnum = -1;
if (!devdata)
return NULL;
memset(devdata, '\0', sizeof(struct visornic_devdata));
spin_lock(&dev_num_pool_lock);
devnum = find_first_zero_bit(dev_num_pool, MAXDEVICES);
set_bit(devnum, dev_num_pool);
spin_unlock(&dev_num_pool_lock);
if (devnum == MAXDEVICES)
devnum = -1;
if (devnum < 0) {
kfree(devdata);
return NULL;
}
devdata->devnum = devnum;
devdata->dev = dev;
strncpy(devdata->name, dev_name(&dev->device), sizeof(devdata->name));
kref_init(&devdata->kref);
spin_lock(&lock_all_devices);
list_add_tail(&devdata->list_all, &list_all_devices);
spin_unlock(&lock_all_devices);
return devdata;
}
static void devdata_release(struct kref *mykref)
{
struct visornic_devdata *devdata =
container_of(mykref, struct visornic_devdata, kref);
spin_lock(&dev_num_pool_lock);
clear_bit(devdata->devnum, dev_num_pool);
spin_unlock(&dev_num_pool_lock);
spin_lock(&lock_all_devices);
list_del(&devdata->list_all);
spin_unlock(&lock_all_devices);
kfree(devdata);
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
drain_queue(struct uiscmdrsp *cmdrsp, struct visornic_devdata *devdata)
{
unsigned long flags;
struct net_device *netdev;
while (1) {
if (!visorchannel_signalremove(devdata->dev->visorchannel,
IOCHAN_FROM_IOPART,
cmdrsp))
break;
switch (cmdrsp->net.type) {
case NET_RCV:
devdata->chstat.got_rcv++;
visornic_rx(cmdrsp);
break;
case NET_XMIT_DONE:
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->chstat.got_xmit_done++;
if (cmdrsp->net.xmtdone.xmt_done_result)
devdata->chstat.xmit_fail++;
netdev = ((struct sk_buff *)cmdrsp->net.buf)->dev;
if ((netdev == devdata->netdev) &&
netif_queue_stopped(netdev)) {
if (((devdata->chstat.sent_xmit >=
devdata->chstat.got_xmit_done) &&
(devdata->chstat.sent_xmit -
devdata->chstat.got_xmit_done <=
devdata->lower_threshold_net_xmits)) ||
((devdata->chstat.sent_xmit <
devdata->chstat.got_xmit_done) &&
(ULONG_MAX - devdata->chstat.got_xmit_done
+ devdata->chstat.sent_xmit <=
devdata->lower_threshold_net_xmits))) {
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
if (kthread_should_stop())
break;
}
}
static int
process_incoming_rsps(void *v)
{
struct visornic_devdata *devdata = v;
struct uiscmdrsp *cmdrsp = NULL;
const int SZ = SIZEOF_CMDRSP;
cmdrsp = kmalloc(SZ, GFP_ATOMIC);
if (!cmdrsp)
complete_and_exit(&devdata->threadinfo.has_stopped, 0);
while (1) {
wait_event_interruptible_timeout(
devdata->rsp_queue, (atomic_read(
&devdata->interrupt_rcvd) == 1),
msecs_to_jiffies(devdata->thread_wait_ms));
atomic_set(&devdata->interrupt_rcvd, 0);
send_rcv_posts_if_needed(devdata);
drain_queue(cmdrsp, devdata);
if (kthread_should_stop())
break;
}
kfree(cmdrsp);
complete_and_exit(&devdata->threadinfo.has_stopped, 0);
}
static int visornic_probe(struct visor_device *dev)
{
struct visornic_devdata *devdata = NULL;
struct net_device *netdev = NULL;
int err;
int channel_offset = 0;
u64 features;
netdev = alloc_etherdev(sizeof(struct visornic_devdata));
if (!netdev)
return -ENOMEM;
netdev->netdev_ops = &visornic_dev_ops;
netdev->watchdog_timeo = (5 * HZ);
netdev->dev.parent = &dev->device;
netdev->addr_len = ETH_ALEN;
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.macaddr);
err = visorbus_read_channel(dev, channel_offset, netdev->dev_addr,
ETH_ALEN);
if (err < 0)
goto cleanup_netdev;
devdata = devdata_initialize(netdev_priv(netdev), dev);
if (!devdata) {
err = -ENOMEM;
goto cleanup_netdev;
}
devdata->netdev = netdev;
init_waitqueue_head(&devdata->rsp_queue);
spin_lock_init(&devdata->priv_lock);
devdata->enabled = 0;
atomic_set(&devdata->usage, 1);
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.num_rcv_bufs);
err = visorbus_read_channel(dev, channel_offset,
&devdata->num_rcv_bufs, 4);
if (err)
goto cleanup_netdev;
devdata->rcvbuf = kmalloc(sizeof(struct sk_buff *) *
devdata->num_rcv_bufs, GFP_KERNEL);
if (!devdata->rcvbuf) {
err = -ENOMEM;
goto cleanup_rcvbuf;
}
devdata->max_outstanding_net_xmits =
max(3, ((devdata->num_rcv_bufs / 3) - 2));
devdata->upper_threshold_net_xmits =
max(2, devdata->max_outstanding_net_xmits - 1);
devdata->lower_threshold_net_xmits =
max(1, devdata->max_outstanding_net_xmits / 2);
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
INIT_WORK(&devdata->serverdown_completion,
visornic_serverdown_complete);
INIT_WORK(&devdata->timeout_reset, visornic_timeout_reset);
devdata->server_down = false;
devdata->server_change_state = false;
channel_offset = offsetof(struct spar_io_channel_protocol,
vnic.mtu);
err = visorbus_read_channel(dev, channel_offset, &netdev->mtu, 4);
if (err)
goto cleanup_xmit_cmdrsp;
channel_offset = offsetof(struct spar_io_channel_protocol,
channel_header.features);
err = visorbus_read_channel(dev, channel_offset, &features, 8);
if (err)
goto cleanup_xmit_cmdrsp;
features |= ULTRA_IO_CHANNEL_IS_POLLING;
err = visorbus_write_channel(dev, channel_offset, &features, 8);
if (err)
goto cleanup_xmit_cmdrsp;
devdata->thread_wait_ms = 2;
visor_thread_start(&devdata->threadinfo, process_incoming_rsps,
devdata, "vnic_incoming");
err = register_netdev(netdev);
if (err)
goto cleanup_thread_stop;
devdata->eth_debugfs_dir = debugfs_create_dir(netdev->name,
visornic_debugfs_dir);
if (!devdata->eth_debugfs_dir) {
err = -ENOMEM;
goto cleanup_thread_stop;
}
return 0;
cleanup_thread_stop:
visor_thread_stop(&devdata->threadinfo);
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
sprintf(devdata->name, "<dev#%d-history>", devdata->devnum);
devdata->dev = NULL;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
}
static void visornic_remove(struct visor_device *dev)
{
struct visornic_devdata *devdata = dev_get_drvdata(&dev->device);
if (!devdata)
return;
dev_set_drvdata(&dev->device, NULL);
host_side_disappeared(devdata);
kref_put(&devdata->kref, devdata_release);
}
static int visornic_pause(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visornic_devdata *devdata = dev_get_drvdata(&dev->device);
visornic_serverdown(devdata);
complete_func(dev, 0);
return 0;
}
static int visornic_resume(struct visor_device *dev,
visorbus_state_complete_func complete_func)
{
struct visornic_devdata *devdata;
struct net_device *netdev;
unsigned long flags;
devdata = dev_get_drvdata(&dev->device);
if (!devdata)
return -EINVAL;
netdev = devdata->netdev;
if (devdata->server_down && !devdata->server_change_state) {
devdata->server_change_state = true;
visor_thread_start(&devdata->threadinfo, process_incoming_rsps,
devdata, "vnic_incoming");
init_rcv_bufs(netdev, devdata);
spin_lock_irqsave(&devdata->priv_lock, flags);
devdata->enabled = 1;
devdata->enab_dis_acked = 0;
spin_unlock_irqrestore(&devdata->priv_lock, flags);
send_enbdis(netdev, 1, devdata);
} else if (devdata->server_change_state) {
return -EIO;
}
complete_func(dev, 0);
return 0;
}
static int visornic_init(void)
{
struct dentry *ret;
int err = -ENOMEM;
visornic_serverdown_workqueue =
create_singlethread_workqueue("visornic_serverdown");
if (!visornic_serverdown_workqueue)
return -ENOMEM;
visornic_timeout_reset_workqueue =
create_singlethread_workqueue("visornic_timeout_reset");
if (!visornic_timeout_reset_workqueue)
return -ENOMEM;
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
visornic_serverdown_workqueue =
create_singlethread_workqueue("visornic_serverdown");
if (!visornic_serverdown_workqueue)
goto cleanup_debugfs;
visornic_timeout_reset_workqueue =
create_singlethread_workqueue("visornic_timeout_reset");
if (!visornic_timeout_reset_workqueue)
goto cleanup_workqueue;
spin_lock_init(&dev_num_pool_lock);
dev_num_pool = kzalloc(BITS_TO_LONGS(MAXDEVICES), GFP_KERNEL);
if (!dev_num_pool)
goto cleanup_workqueue;
visorbus_register_visor_driver(&visornic_driver);
return 0;
cleanup_workqueue:
flush_workqueue(visornic_serverdown_workqueue);
destroy_workqueue(visornic_serverdown_workqueue);
if (visornic_timeout_reset_workqueue) {
flush_workqueue(visornic_timeout_reset_workqueue);
destroy_workqueue(visornic_timeout_reset_workqueue);
}
cleanup_debugfs:
debugfs_remove_recursive(visornic_debugfs_dir);
return err;
}
static void visornic_cleanup(void)
{
if (visornic_serverdown_workqueue) {
flush_workqueue(visornic_serverdown_workqueue);
destroy_workqueue(visornic_serverdown_workqueue);
}
if (visornic_timeout_reset_workqueue) {
flush_workqueue(visornic_timeout_reset_workqueue);
destroy_workqueue(visornic_timeout_reset_workqueue);
}
debugfs_remove_recursive(visornic_debugfs_dir);
visorbus_unregister_visor_driver(&visornic_driver);
kfree(dev_num_pool);
dev_num_pool = NULL;
}
