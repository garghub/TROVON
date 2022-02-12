int wifi_get_irq_number(unsigned long *irq_flags_ptr)
{
if (wifi_irqres) {
*irq_flags_ptr = wifi_irqres->flags & IRQF_TRIGGER_MASK;
return (int)wifi_irqres->start;
}
#ifdef CUSTOM_OOB_GPIO_NUM
return CUSTOM_OOB_GPIO_NUM;
#else
return -1;
#endif
}
int wifi_set_carddetect(int on)
{
printk(KERN_ERR "%s = %d\n", __func__, on);
if (wifi_control_data && wifi_control_data->set_carddetect)
wifi_control_data->set_carddetect(on);
return 0;
}
int wifi_set_power(int on, unsigned long msec)
{
printk(KERN_ERR "%s = %d\n", __func__, on);
if (wifi_control_data && wifi_control_data->set_power)
wifi_control_data->set_power(on);
if (msec)
mdelay(msec);
return 0;
}
int wifi_set_reset(int on, unsigned long msec)
{
printk(KERN_ERR "%s = %d\n", __func__, on);
if (wifi_control_data && wifi_control_data->set_reset)
wifi_control_data->set_reset(on);
if (msec)
mdelay(msec);
return 0;
}
static int wifi_probe(struct platform_device *pdev)
{
struct wifi_platform_data *wifi_ctrl =
(struct wifi_platform_data *)(pdev->dev.platform_data);
printk(KERN_ERR "## %s\n", __func__);
wifi_irqres =
platform_get_resource_byname(pdev, IORESOURCE_IRQ,
"bcm4329_wlan_irq");
wifi_control_data = wifi_ctrl;
wifi_set_power(1, 0);
wifi_set_carddetect(1);
up(&wifi_control_sem);
return 0;
}
static int wifi_remove(struct platform_device *pdev)
{
struct wifi_platform_data *wifi_ctrl =
(struct wifi_platform_data *)(pdev->dev.platform_data);
printk(KERN_ERR "## %s\n", __func__);
wifi_control_data = wifi_ctrl;
wifi_set_carddetect(0);
wifi_set_power(0, 0);
up(&wifi_control_sem);
return 0;
}
static int wifi_suspend(struct platform_device *pdev, pm_message_t state)
{
DHD_TRACE(("##> %s\n", __func__));
return 0;
}
static int wifi_resume(struct platform_device *pdev)
{
DHD_TRACE(("##> %s\n", __func__));
return 0;
}
int wifi_add_dev(void)
{
DHD_TRACE(("## Calling platform_driver_register\n"));
return platform_driver_register(&wifi_device);
}
void wifi_del_dev(void)
{
DHD_TRACE(("## Unregister platform_driver_register\n"));
platform_driver_unregister(&wifi_device);
}
static int dhd_sleep_pm_callback(struct notifier_block *nfb,
unsigned long action, void *ignored)
{
switch (action) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
atomic_set(&dhd_mmc_suspend, true);
return NOTIFY_OK;
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
atomic_set(&dhd_mmc_suspend, false);
return NOTIFY_OK;
}
return 0;
}
static void dhd_set_packet_filter(int value, dhd_pub_t *dhd)
{
#ifdef PKT_FILTER_SUPPORT
DHD_TRACE(("%s: %d\n", __func__, value));
if (dhd_pkt_filter_enable) {
int i;
for (i = 0; i < dhd->pktfilter_count; i++) {
dhd_pktfilter_offload_set(dhd, dhd->pktfilter[i]);
dhd_pktfilter_offload_enable(dhd, dhd->pktfilter[i],
value, dhd_master_mode);
}
}
#endif
}
static int dhd_set_suspend(int value, dhd_pub_t *dhd)
{
int power_mode = PM_MAX;
char iovbuf[32];
int bcn_li_dtim = 3;
#ifdef CUSTOMER_HW2
uint roamvar = 1;
#endif
DHD_TRACE(("%s: enter, value = %d in_suspend=%d\n",
__func__, value, dhd->in_suspend));
if (dhd && dhd->up) {
if (value && dhd->in_suspend) {
DHD_TRACE(("%s: force extra Suspend setting\n",
__func__));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_PM,
(char *)&power_mode,
sizeof(power_mode));
dhd_set_packet_filter(1, dhd);
if ((dhd->dtim_skip == 0) || (dhd->dtim_skip == 1))
bcn_li_dtim = 3;
else
bcn_li_dtim = dhd->dtim_skip;
bcm_mkiovar("bcn_li_dtim", (char *)&bcn_li_dtim,
4, iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
#ifdef CUSTOMER_HW2
bcm_mkiovar("roam_off", (char *)&roamvar, 4,
iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
#endif
} else {
DHD_TRACE(("%s: Remove extra suspend setting\n",
__func__));
power_mode = PM_FAST;
dhdcdc_set_ioctl(dhd, 0, WLC_SET_PM,
(char *)&power_mode,
sizeof(power_mode));
dhd_set_packet_filter(0, dhd);
bcm_mkiovar("bcn_li_dtim", (char *)&dhd->dtim_skip,
4, iovbuf, sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
#ifdef CUSTOMER_HW2
roamvar = 0;
bcm_mkiovar("roam_off", (char *)&roamvar, 4, iovbuf,
sizeof(iovbuf));
dhdcdc_set_ioctl(dhd, 0, WLC_SET_VAR, iovbuf,
sizeof(iovbuf));
#endif
}
}
return 0;
}
static void dhd_suspend_resume_helper(struct dhd_info *dhd, int val)
{
dhd_pub_t *dhdp = &dhd->pub;
dhd_os_proto_block(dhdp);
dhdp->in_suspend = val;
if (!dhdp->suspend_disable_flag)
dhd_set_suspend(val, dhdp);
dhd_os_proto_unblock(dhdp);
}
static void dhd_early_suspend(struct early_suspend *h)
{
struct dhd_info *dhd = container_of(h, struct dhd_info, early_suspend);
DHD_TRACE(("%s: enter\n", __func__));
if (dhd)
dhd_suspend_resume_helper(dhd, 1);
}
static void dhd_late_resume(struct early_suspend *h)
{
struct dhd_info *dhd = container_of(h, struct dhd_info, early_suspend);
DHD_TRACE(("%s: enter\n", __func__));
if (dhd)
dhd_suspend_resume_helper(dhd, 0);
}
void dhd_timeout_start(dhd_timeout_t *tmo, uint usec)
{
tmo->limit = usec;
tmo->increment = 0;
tmo->elapsed = 0;
tmo->tick = 1000000 / HZ;
}
int dhd_timeout_expired(dhd_timeout_t *tmo)
{
if (tmo->increment == 0) {
tmo->increment = 1;
return 0;
}
if (tmo->elapsed >= tmo->limit)
return 1;
tmo->elapsed += tmo->increment;
if (tmo->increment < tmo->tick) {
udelay(tmo->increment);
tmo->increment *= 2;
if (tmo->increment > tmo->tick)
tmo->increment = tmo->tick;
} else {
wait_queue_head_t delay_wait;
DECLARE_WAITQUEUE(wait, current);
int pending;
init_waitqueue_head(&delay_wait);
add_wait_queue(&delay_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(1);
pending = signal_pending(current);
remove_wait_queue(&delay_wait, &wait);
set_current_state(TASK_RUNNING);
if (pending)
return 1;
}
return 0;
}
static int dhd_net2idx(dhd_info_t *dhd, struct net_device *net)
{
int i = 0;
ASSERT(dhd);
while (i < DHD_MAX_IFS) {
if (dhd->iflist[i] && (dhd->iflist[i]->net == net))
return i;
i++;
}
return DHD_BAD_IF;
}
int dhd_ifname2idx(dhd_info_t *dhd, char *name)
{
int i = DHD_MAX_IFS;
ASSERT(dhd);
if (name == NULL || *name == '\0')
return 0;
while (--i > 0)
if (dhd->iflist[i]
&& !strncmp(dhd->iflist[i]->name, name, IFNAMSIZ))
break;
DHD_TRACE(("%s: return idx %d for \"%s\"\n", __func__, i, name));
return i;
}
char *dhd_ifname(dhd_pub_t *dhdp, int ifidx)
{
dhd_info_t *dhd = (dhd_info_t *) dhdp->info;
ASSERT(dhd);
if (ifidx < 0 || ifidx >= DHD_MAX_IFS) {
DHD_ERROR(("%s: ifidx %d out of range\n", __func__, ifidx));
return "<if_bad>";
}
if (dhd->iflist[ifidx] == NULL) {
DHD_ERROR(("%s: null i/f %d\n", __func__, ifidx));
return "<if_null>";
}
if (dhd->iflist[ifidx]->net)
return dhd->iflist[ifidx]->net->name;
return "<if_none>";
}
static void _dhd_set_multicast_list(dhd_info_t *dhd, int ifidx)
{
struct net_device *dev;
struct netdev_hw_addr *ha;
u32 allmulti, cnt;
wl_ioctl_t ioc;
char *buf, *bufp;
uint buflen;
int ret;
ASSERT(dhd && dhd->iflist[ifidx]);
dev = dhd->iflist[ifidx]->net;
cnt = netdev_mc_count(dev);
allmulti = (dev->flags & IFF_ALLMULTI) ? true : false;
buflen = sizeof("mcast_list") + sizeof(cnt) + (cnt * ETH_ALEN);
bufp = buf = kmalloc(buflen, GFP_ATOMIC);
if (!bufp) {
DHD_ERROR(("%s: out of memory for mcast_list, cnt %d\n",
dhd_ifname(&dhd->pub, ifidx), cnt));
return;
}
strcpy(bufp, "mcast_list");
bufp += strlen("mcast_list") + 1;
cnt = cpu_to_le32(cnt);
memcpy(bufp, &cnt, sizeof(cnt));
bufp += sizeof(cnt);
netdev_for_each_mc_addr(ha, dev) {
if (!cnt)
break;
memcpy(bufp, ha->addr, ETH_ALEN);
bufp += ETH_ALEN;
cnt--;
}
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_SET_VAR;
ioc.buf = buf;
ioc.len = buflen;
ioc.set = true;
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: set mcast_list failed, cnt %d\n",
dhd_ifname(&dhd->pub, ifidx), cnt));
allmulti = cnt ? true : allmulti;
}
kfree(buf);
buflen = sizeof("allmulti") + sizeof(allmulti);
buf = kmalloc(buflen, GFP_ATOMIC);
if (!buf) {
DHD_ERROR(("%s: out of memory for allmulti\n",
dhd_ifname(&dhd->pub, ifidx)));
return;
}
allmulti = cpu_to_le32(allmulti);
if (!bcm_mkiovar
("allmulti", (void *)&allmulti, sizeof(allmulti), buf, buflen)) {
DHD_ERROR(("%s: mkiovar failed for allmulti, datalen %d "
"buflen %u\n", dhd_ifname(&dhd->pub, ifidx),
(int)sizeof(allmulti), buflen));
kfree(buf);
return;
}
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_SET_VAR;
ioc.buf = buf;
ioc.len = buflen;
ioc.set = true;
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: set allmulti %d failed\n",
dhd_ifname(&dhd->pub, ifidx),
le32_to_cpu(allmulti)));
}
kfree(buf);
allmulti = (dev->flags & IFF_PROMISC) ? true : false;
allmulti = cpu_to_le32(allmulti);
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_SET_PROMISC;
ioc.buf = &allmulti;
ioc.len = sizeof(allmulti);
ioc.set = true;
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: set promisc %d failed\n",
dhd_ifname(&dhd->pub, ifidx),
le32_to_cpu(allmulti)));
}
}
static int
_dhd_set_mac_address(dhd_info_t *dhd, int ifidx, u8 *addr)
{
char buf[32];
wl_ioctl_t ioc;
int ret;
DHD_TRACE(("%s enter\n", __func__));
if (!bcm_mkiovar
("cur_etheraddr", (char *)addr, ETH_ALEN, buf, 32)) {
DHD_ERROR(("%s: mkiovar failed for cur_etheraddr\n",
dhd_ifname(&dhd->pub, ifidx)));
return -1;
}
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_SET_VAR;
ioc.buf = buf;
ioc.len = 32;
ioc.set = true;
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: set cur_etheraddr failed\n",
dhd_ifname(&dhd->pub, ifidx)));
} else {
memcpy(dhd->iflist[ifidx]->net->dev_addr, addr, ETH_ALEN);
}
return ret;
}
static void dhd_op_if(dhd_if_t *ifp)
{
dhd_info_t *dhd;
int ret = 0, err = 0;
ASSERT(ifp && ifp->info && ifp->idx);
dhd = ifp->info;
DHD_TRACE(("%s: idx %d, state %d\n", __func__, ifp->idx, ifp->state));
switch (ifp->state) {
case WLC_E_IF_ADD:
if (ifp->net != NULL) {
DHD_ERROR(("%s: ERROR: netdev:%s already exists, "
"try free & unregister\n",
__func__, ifp->net->name));
netif_stop_queue(ifp->net);
unregister_netdev(ifp->net);
free_netdev(ifp->net);
}
ifp->net = alloc_etherdev(sizeof(dhd));
if (!ifp->net) {
DHD_ERROR(("%s: OOM - alloc_etherdev\n", __func__));
ret = -ENOMEM;
}
if (ret == 0) {
strcpy(ifp->net->name, ifp->name);
memcpy(netdev_priv(ifp->net), &dhd, sizeof(dhd));
err = dhd_net_attach(&dhd->pub, ifp->idx);
if (err != 0) {
DHD_ERROR(("%s: dhd_net_attach failed, "
"err %d\n",
__func__, err));
ret = -EOPNOTSUPP;
} else {
#ifdef SOFTAP
extern struct semaphore ap_eth_sema;
ap_net_dev = ifp->net;
up(&ap_eth_sema);
#endif
DHD_TRACE(("\n ==== pid:%x, net_device for "
"if:%s created ===\n\n",
current->pid, ifp->net->name));
ifp->state = 0;
}
}
break;
case WLC_E_IF_DEL:
if (ifp->net != NULL) {
DHD_TRACE(("\n%s: got 'WLC_E_IF_DEL' state\n",
__func__));
netif_stop_queue(ifp->net);
unregister_netdev(ifp->net);
ret = DHD_DEL_IF;
}
break;
default:
DHD_ERROR(("%s: bad op %d\n", __func__, ifp->state));
ASSERT(!ifp->state);
break;
}
if (ret < 0) {
if (ifp->net)
free_netdev(ifp->net);
dhd->iflist[ifp->idx] = NULL;
kfree(ifp);
#ifdef SOFTAP
if (ifp->net == ap_net_dev)
ap_net_dev = NULL;
#endif
}
}
static int _dhd_sysioc_thread(void *data)
{
dhd_info_t *dhd = (dhd_info_t *) data;
int i;
#ifdef SOFTAP
bool in_ap = false;
#endif
allow_signal(SIGTERM);
while (down_interruptible(&dhd->sysioc_sem) == 0) {
if (kthread_should_stop())
break;
for (i = 0; i < DHD_MAX_IFS; i++) {
if (dhd->iflist[i]) {
#ifdef SOFTAP
in_ap = (ap_net_dev != NULL);
#endif
if (dhd->iflist[i]->state)
dhd_op_if(dhd->iflist[i]);
#ifdef SOFTAP
if (dhd->iflist[i] == NULL) {
DHD_TRACE(("\n\n %s: interface %d "
"removed!\n", __func__, i));
continue;
}
if (in_ap && dhd->set_macaddress) {
DHD_TRACE(("attempt to set MAC for %s "
"in AP Mode," "blocked. \n",
dhd->iflist[i]->net->name));
dhd->set_macaddress = false;
continue;
}
if (in_ap && dhd->set_multicast) {
DHD_TRACE(("attempt to set MULTICAST list for %s" "in AP Mode, blocked. \n",
dhd->iflist[i]->net->name));
dhd->set_multicast = false;
continue;
}
#endif
if (dhd->set_multicast) {
dhd->set_multicast = false;
_dhd_set_multicast_list(dhd, i);
}
if (dhd->set_macaddress) {
dhd->set_macaddress = false;
_dhd_set_mac_address(dhd, i,
dhd->macvalue);
}
}
}
}
return 0;
}
static int dhd_set_mac_address(struct net_device *dev, void *addr)
{
int ret = 0;
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(dev);
struct sockaddr *sa = (struct sockaddr *)addr;
int ifidx;
ifidx = dhd_net2idx(dhd, dev);
if (ifidx == DHD_BAD_IF)
return -1;
ASSERT(dhd->sysioc_tsk);
memcpy(&dhd->macvalue, sa->sa_data, ETH_ALEN);
dhd->set_macaddress = true;
up(&dhd->sysioc_sem);
return ret;
}
static void dhd_set_multicast_list(struct net_device *dev)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(dev);
int ifidx;
ifidx = dhd_net2idx(dhd, dev);
if (ifidx == DHD_BAD_IF)
return;
ASSERT(dhd->sysioc_tsk);
dhd->set_multicast = true;
up(&dhd->sysioc_sem);
}
int dhd_sendpkt(dhd_pub_t *dhdp, int ifidx, struct sk_buff *pktbuf)
{
int ret;
dhd_info_t *dhd = (dhd_info_t *) (dhdp->info);
if (!dhdp->up || (dhdp->busstate == DHD_BUS_DOWN))
return -ENODEV;
if (pktbuf->len >= ETH_ALEN) {
u8 *pktdata = (u8 *) (pktbuf->data);
struct ethhdr *eh = (struct ethhdr *)pktdata;
if (is_multicast_ether_addr(eh->h_dest))
dhdp->tx_multicast++;
if (ntohs(eh->h_proto) == ETH_P_PAE)
atomic_inc(&dhd->pend_8021x_cnt);
}
dhd_prot_hdrpush(dhdp, ifidx, pktbuf);
#ifdef BCMDBUS
ret = dbus_send_pkt(dhdp->dbus, pktbuf, NULL );
#else
ret = dhd_bus_txdata(dhdp->bus, pktbuf);
#endif
return ret;
}
static inline void *
osl_pkt_frmnative(struct sk_buff *skb)
{
return (void *)skb;
}
static inline struct sk_buff *
osl_pkt_tonative(void *pkt)
{
return (struct sk_buff *)pkt;
}
static int dhd_start_xmit(struct sk_buff *skb, struct net_device *net)
{
int ret;
void *pktbuf;
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
int ifidx;
DHD_TRACE(("%s: Enter\n", __func__));
if (!dhd->pub.up || (dhd->pub.busstate == DHD_BUS_DOWN)) {
DHD_ERROR(("%s: xmit rejected pub.up=%d busstate=%d\n",
__func__, dhd->pub.up, dhd->pub.busstate));
netif_stop_queue(net);
return -ENODEV;
}
ifidx = dhd_net2idx(dhd, net);
if (ifidx == DHD_BAD_IF) {
DHD_ERROR(("%s: bad ifidx %d\n", __func__, ifidx));
netif_stop_queue(net);
return -ENODEV;
}
if (skb_headroom(skb) < dhd->pub.hdrlen) {
struct sk_buff *skb2;
DHD_INFO(("%s: insufficient headroom\n",
dhd_ifname(&dhd->pub, ifidx)));
dhd->pub.tx_realloc++;
skb2 = skb_realloc_headroom(skb, dhd->pub.hdrlen);
dev_kfree_skb(skb);
skb = skb2;
if (skb == NULL) {
DHD_ERROR(("%s: skb_realloc_headroom failed\n",
dhd_ifname(&dhd->pub, ifidx)));
ret = -ENOMEM;
goto done;
}
}
pktbuf = PKTFRMNATIVE(dhd->pub.osh, skb);
if (!pktbuf) {
DHD_ERROR(("%s: PKTFRMNATIVE failed\n",
dhd_ifname(&dhd->pub, ifidx)));
dev_kfree_skb_any(skb);
ret = -ENOMEM;
goto done;
}
ret = dhd_sendpkt(&dhd->pub, ifidx, pktbuf);
done:
if (ret)
dhd->pub.dstats.tx_dropped++;
else
dhd->pub.tx_packets++;
return 0;
}
void dhd_txflowcontrol(dhd_pub_t *dhdp, int ifidx, bool state)
{
struct net_device *net;
dhd_info_t *dhd = dhdp->info;
DHD_TRACE(("%s: Enter\n", __func__));
dhdp->txoff = state;
ASSERT(dhd && dhd->iflist[ifidx]);
net = dhd->iflist[ifidx]->net;
if (state == ON)
netif_stop_queue(net);
else
netif_wake_queue(net);
}
void dhd_rx_frame(dhd_pub_t *dhdp, int ifidx, struct sk_buff *pktbuf,
int numpkt)
{
dhd_info_t *dhd = (dhd_info_t *) dhdp->info;
struct sk_buff *skb;
unsigned char *eth;
uint len;
void *data;
struct sk_buff *pnext, *save_pktbuf;
int i;
dhd_if_t *ifp;
wl_event_msg_t event;
DHD_TRACE(("%s: Enter\n", __func__));
save_pktbuf = pktbuf;
for (i = 0; pktbuf && i < numpkt; i++, pktbuf = pnext) {
pnext = pktbuf->next;
pktbuf->next = NULL;
skb = PKTTONATIVE(dhdp->osh, pktbuf);
eth = skb->data;
len = skb->len;
ifp = dhd->iflist[ifidx];
if (ifp == NULL)
ifp = dhd->iflist[0];
ASSERT(ifp);
skb->dev = ifp->net;
skb->protocol = eth_type_trans(skb, skb->dev);
if (skb->pkt_type == PACKET_MULTICAST)
dhd->pub.rx_multicast++;
skb->data = eth;
skb->len = len;
skb_pull(skb, ETH_HLEN);
if (ntohs(skb->protocol) == ETH_P_BRCM)
dhd_wl_host_event(dhd, &ifidx,
skb_mac_header(skb),
&event, &data);
ASSERT(ifidx < DHD_MAX_IFS && dhd->iflist[ifidx]);
if (dhd->iflist[ifidx] && !dhd->iflist[ifidx]->state)
ifp = dhd->iflist[ifidx];
if (ifp->net)
ifp->net->last_rx = jiffies;
dhdp->dstats.rx_bytes += skb->len;
dhdp->rx_packets++;
if (in_interrupt()) {
netif_rx(skb);
} else {
netif_rx_ni(skb);
}
}
}
void dhd_event(struct dhd_info *dhd, char *evpkt, int evlen, int ifidx)
{
return;
}
void dhd_txcomplete(dhd_pub_t *dhdp, struct sk_buff *txp, bool success)
{
uint ifidx;
dhd_info_t *dhd = (dhd_info_t *) (dhdp->info);
struct ethhdr *eh;
u16 type;
dhd_prot_hdrpull(dhdp, &ifidx, txp);
eh = (struct ethhdr *)(txp->data);
type = ntohs(eh->h_proto);
if (type == ETH_P_PAE)
atomic_dec(&dhd->pend_8021x_cnt);
}
static struct net_device_stats *dhd_get_stats(struct net_device *net)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
dhd_if_t *ifp;
int ifidx;
DHD_TRACE(("%s: Enter\n", __func__));
ifidx = dhd_net2idx(dhd, net);
if (ifidx == DHD_BAD_IF)
return NULL;
ifp = dhd->iflist[ifidx];
ASSERT(dhd && ifp);
if (dhd->pub.up) {
dhd_prot_dstats(&dhd->pub);
}
ifp->stats.rx_packets = dhd->pub.dstats.rx_packets;
ifp->stats.tx_packets = dhd->pub.dstats.tx_packets;
ifp->stats.rx_bytes = dhd->pub.dstats.rx_bytes;
ifp->stats.tx_bytes = dhd->pub.dstats.tx_bytes;
ifp->stats.rx_errors = dhd->pub.dstats.rx_errors;
ifp->stats.tx_errors = dhd->pub.dstats.tx_errors;
ifp->stats.rx_dropped = dhd->pub.dstats.rx_dropped;
ifp->stats.tx_dropped = dhd->pub.dstats.tx_dropped;
ifp->stats.multicast = dhd->pub.dstats.multicast;
return &ifp->stats;
}
static int dhd_watchdog_thread(void *data)
{
dhd_info_t *dhd = (dhd_info_t *) data;
#ifdef DHD_SCHED
if (dhd_watchdog_prio > 0) {
struct sched_param param;
param.sched_priority = (dhd_watchdog_prio < MAX_RT_PRIO) ?
dhd_watchdog_prio : (MAX_RT_PRIO - 1);
setScheduler(current, SCHED_FIFO, &param);
}
#endif
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (down_interruptible(&dhd->watchdog_sem) == 0) {
if (dhd->pub.dongle_reset == false) {
dhd_bus_watchdog(&dhd->pub);
}
dhd->pub.tickcnt++;
} else
break;
}
return 0;
}
static void dhd_watchdog(unsigned long data)
{
dhd_info_t *dhd = (dhd_info_t *) data;
if (dhd->watchdog_tsk) {
up(&dhd->watchdog_sem);
if (dhd->wd_timer_valid) {
mod_timer(&dhd->timer,
jiffies + dhd_watchdog_ms * HZ / 1000);
}
return;
}
dhd_bus_watchdog(&dhd->pub);
dhd->pub.tickcnt++;
if (dhd->wd_timer_valid)
mod_timer(&dhd->timer, jiffies + dhd_watchdog_ms * HZ / 1000);
}
static int dhd_dpc_thread(void *data)
{
dhd_info_t *dhd = (dhd_info_t *) data;
#ifdef DHD_SCHED
if (dhd_dpc_prio > 0) {
struct sched_param param;
param.sched_priority =
(dhd_dpc_prio <
MAX_RT_PRIO) ? dhd_dpc_prio : (MAX_RT_PRIO - 1);
setScheduler(current, SCHED_FIFO, &param);
}
#endif
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (down_interruptible(&dhd->dpc_sem) == 0) {
if (dhd->pub.busstate != DHD_BUS_DOWN) {
if (dhd_bus_dpc(dhd->pub.bus)) {
up(&dhd->dpc_sem);
}
} else {
dhd_bus_stop(dhd->pub.bus, true);
}
} else
break;
}
return 0;
}
static void dhd_dpc(unsigned long data)
{
dhd_info_t *dhd;
dhd = (dhd_info_t *) data;
if (dhd->pub.busstate != DHD_BUS_DOWN) {
if (dhd_bus_dpc(dhd->pub.bus))
tasklet_schedule(&dhd->tasklet);
} else {
dhd_bus_stop(dhd->pub.bus, true);
}
}
void dhd_sched_dpc(dhd_pub_t *dhdp)
{
dhd_info_t *dhd = (dhd_info_t *) dhdp->info;
if (dhd->dpc_tsk) {
up(&dhd->dpc_sem);
return;
}
tasklet_schedule(&dhd->tasklet);
}
static int dhd_toe_get(dhd_info_t *dhd, int ifidx, u32 *toe_ol)
{
wl_ioctl_t ioc;
char buf[32];
int ret;
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_GET_VAR;
ioc.buf = buf;
ioc.len = (uint) sizeof(buf);
ioc.set = false;
strcpy(buf, "toe_ol");
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
if (ret == -EIO) {
DHD_ERROR(("%s: toe not supported by device\n",
dhd_ifname(&dhd->pub, ifidx)));
return -EOPNOTSUPP;
}
DHD_INFO(("%s: could not get toe_ol: ret=%d\n",
dhd_ifname(&dhd->pub, ifidx), ret));
return ret;
}
memcpy(toe_ol, buf, sizeof(u32));
return 0;
}
static int dhd_toe_set(dhd_info_t *dhd, int ifidx, u32 toe_ol)
{
wl_ioctl_t ioc;
char buf[32];
int toe, ret;
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = WLC_SET_VAR;
ioc.buf = buf;
ioc.len = (uint) sizeof(buf);
ioc.set = true;
strcpy(buf, "toe_ol");
memcpy(&buf[sizeof("toe_ol")], &toe_ol, sizeof(u32));
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: could not set toe_ol: ret=%d\n",
dhd_ifname(&dhd->pub, ifidx), ret));
return ret;
}
toe = (toe_ol != 0);
strcpy(buf, "toe");
memcpy(&buf[sizeof("toe")], &toe, sizeof(u32));
ret = dhd_prot_ioctl(&dhd->pub, ifidx, &ioc, ioc.buf, ioc.len);
if (ret < 0) {
DHD_ERROR(("%s: could not set toe: ret=%d\n",
dhd_ifname(&dhd->pub, ifidx), ret));
return ret;
}
return 0;
}
static void dhd_ethtool_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
sprintf(info->driver, DRV_MODULE_NAME);
sprintf(info->version, "%lu", dhd->pub.drv_version);
sprintf(info->fw_version, "%s", wl_cfg80211_get_fwname());
sprintf(info->bus_info, "%s", dev_name(&wl_cfg80211_get_sdio_func()->dev));
}
static int dhd_ethtool(dhd_info_t *dhd, void *uaddr)
{
struct ethtool_drvinfo info;
char drvname[sizeof(info.driver)];
u32 cmd;
#ifdef TOE
struct ethtool_value edata;
u32 toe_cmpnt, csum_dir;
int ret;
#endif
DHD_TRACE(("%s: Enter\n", __func__));
if (copy_from_user(&cmd, uaddr, sizeof(u32)))
return -EFAULT;
switch (cmd) {
case ETHTOOL_GDRVINFO:
if (copy_from_user(&info, uaddr, sizeof(info)))
return -EFAULT;
strncpy(drvname, info.driver, sizeof(info.driver));
drvname[sizeof(info.driver) - 1] = '\0';
memset(&info, 0, sizeof(info));
info.cmd = cmd;
if (strcmp(drvname, "?dhd") == 0) {
sprintf(info.driver, "dhd");
strcpy(info.version, EPI_VERSION_STR);
}
else if (!dhd->pub.up) {
DHD_ERROR(("%s: dongle is not up\n", __func__));
return -ENODEV;
}
else if (dhd->pub.iswl)
sprintf(info.driver, "wl");
else
sprintf(info.driver, "xx");
sprintf(info.version, "%lu", dhd->pub.drv_version);
if (copy_to_user(uaddr, &info, sizeof(info)))
return -EFAULT;
DHD_CTL(("%s: given %*s, returning %s\n", __func__,
(int)sizeof(drvname), drvname, info.driver));
break;
#ifdef TOE
case ETHTOOL_GRXCSUM:
case ETHTOOL_GTXCSUM:
ret = dhd_toe_get(dhd, 0, &toe_cmpnt);
if (ret < 0)
return ret;
csum_dir =
(cmd == ETHTOOL_GTXCSUM) ? TOE_TX_CSUM_OL : TOE_RX_CSUM_OL;
edata.cmd = cmd;
edata.data = (toe_cmpnt & csum_dir) ? 1 : 0;
if (copy_to_user(uaddr, &edata, sizeof(edata)))
return -EFAULT;
break;
case ETHTOOL_SRXCSUM:
case ETHTOOL_STXCSUM:
if (copy_from_user(&edata, uaddr, sizeof(edata)))
return -EFAULT;
ret = dhd_toe_get(dhd, 0, &toe_cmpnt);
if (ret < 0)
return ret;
csum_dir =
(cmd == ETHTOOL_STXCSUM) ? TOE_TX_CSUM_OL : TOE_RX_CSUM_OL;
if (edata.data != 0)
toe_cmpnt |= csum_dir;
else
toe_cmpnt &= ~csum_dir;
ret = dhd_toe_set(dhd, 0, toe_cmpnt);
if (ret < 0)
return ret;
if (cmd == ETHTOOL_STXCSUM) {
if (edata.data)
dhd->iflist[0]->net->features |=
NETIF_F_IP_CSUM;
else
dhd->iflist[0]->net->features &=
~NETIF_F_IP_CSUM;
}
break;
#endif
default:
return -EOPNOTSUPP;
}
return 0;
}
static int dhd_ioctl_entry(struct net_device *net, struct ifreq *ifr, int cmd)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
dhd_ioctl_t ioc;
int bcmerror = 0;
int buflen = 0;
void *buf = NULL;
uint driver = 0;
int ifidx;
bool is_set_key_cmd;
ifidx = dhd_net2idx(dhd, net);
DHD_TRACE(("%s: ifidx %d, cmd 0x%04x\n", __func__, ifidx, cmd));
if (ifidx == DHD_BAD_IF)
return -1;
#if defined(CONFIG_WIRELESS_EXT)
if ((cmd >= SIOCIWFIRST) && (cmd <= SIOCIWLAST)) {
return wl_iw_ioctl(net, ifr, cmd);
}
#endif
if (cmd == SIOCETHTOOL)
return dhd_ethtool(dhd, (void *)ifr->ifr_data);
if (cmd != SIOCDEVPRIVATE)
return -EOPNOTSUPP;
memset(&ioc, 0, sizeof(ioc));
if (copy_from_user(&ioc, ifr->ifr_data, sizeof(wl_ioctl_t))) {
bcmerror = -EINVAL;
goto done;
}
if (ioc.buf) {
buflen = min_t(int, ioc.len, DHD_IOCTL_MAXLEN);
{
buf = kmalloc(buflen, GFP_ATOMIC);
if (!buf) {
bcmerror = -ENOMEM;
goto done;
}
if (copy_from_user(buf, ioc.buf, buflen)) {
bcmerror = -EINVAL;
goto done;
}
}
}
if ((copy_from_user(&driver, (char *)ifr->ifr_data + sizeof(wl_ioctl_t),
sizeof(uint)) != 0)) {
bcmerror = -EINVAL;
goto done;
}
if (!capable(CAP_NET_ADMIN)) {
bcmerror = -EPERM;
goto done;
}
if (driver == DHD_IOCTL_MAGIC) {
bcmerror = dhd_ioctl((void *)&dhd->pub, &ioc, buf, buflen);
if (bcmerror)
dhd->pub.bcmerror = bcmerror;
goto done;
}
if ((dhd->pub.busstate != DHD_BUS_DATA)) {
DHD_ERROR(("%s DONGLE_DOWN,__func__\n", __func__));
bcmerror = -EIO;
goto done;
}
if (!dhd->pub.iswl) {
bcmerror = -EIO;
goto done;
}
is_set_key_cmd = ((ioc.cmd == WLC_SET_KEY) ||
((ioc.cmd == WLC_SET_VAR) &&
!(strncmp("wsec_key", ioc.buf, 9))) ||
((ioc.cmd == WLC_SET_VAR) &&
!(strncmp("bsscfg:wsec_key", ioc.buf, 15))));
if (is_set_key_cmd)
dhd_wait_pend8021x(net);
bcmerror =
dhd_prot_ioctl(&dhd->pub, ifidx, (wl_ioctl_t *)&ioc, buf, buflen);
done:
if (!bcmerror && buf && ioc.buf) {
if (copy_to_user(ioc.buf, buf, buflen))
bcmerror = -EFAULT;
}
kfree(buf);
if (bcmerror > 0)
bcmerror = 0;
return bcmerror;
}
static int dhd_stop(struct net_device *net)
{
#if !defined(IGNORE_ETH0_DOWN)
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
DHD_TRACE(("%s: Enter\n", __func__));
if (IS_CFG80211_FAVORITE()) {
wl_cfg80211_down();
}
if (dhd->pub.up == 0)
return 0;
dhd->pub.up = 0;
netif_stop_queue(net);
#else
DHD_ERROR(("BYPASS %s:due to BRCM compilation : under investigation\n",
__func__));
#endif
return 0;
}
static int dhd_open(struct net_device *net)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(net);
#ifdef TOE
u32 toe_ol;
#endif
int ifidx = dhd_net2idx(dhd, net);
s32 ret = 0;
DHD_TRACE(("%s: ifidx %d\n", __func__, ifidx));
if (ifidx == 0) {
ret = dhd_bus_start(&dhd->pub);
if (ret != 0) {
DHD_ERROR(("%s: failed with code %d\n", __func__, ret));
return -1;
}
atomic_set(&dhd->pend_8021x_cnt, 0);
memcpy(net->dev_addr, dhd->pub.mac, ETH_ALEN);
#ifdef TOE
if (dhd_toe_get(dhd, ifidx, &toe_ol) >= 0
&& (toe_ol & TOE_TX_CSUM_OL) != 0)
dhd->iflist[ifidx]->net->features |= NETIF_F_IP_CSUM;
else
dhd->iflist[ifidx]->net->features &= ~NETIF_F_IP_CSUM;
#endif
}
netif_start_queue(net);
dhd->pub.up = 1;
if (IS_CFG80211_FAVORITE()) {
if (unlikely(wl_cfg80211_up())) {
DHD_ERROR(("%s: failed to bring up cfg80211\n",
__func__));
return -1;
}
}
return ret;
}
int
dhd_add_if(dhd_info_t *dhd, int ifidx, void *handle, char *name,
u8 *mac_addr, u32 flags, u8 bssidx)
{
dhd_if_t *ifp;
DHD_TRACE(("%s: idx %d, handle->%p\n", __func__, ifidx, handle));
ASSERT(dhd && (ifidx < DHD_MAX_IFS));
ifp = dhd->iflist[ifidx];
if (!ifp && !(ifp = kmalloc(sizeof(dhd_if_t), GFP_ATOMIC))) {
DHD_ERROR(("%s: OOM - dhd_if_t\n", __func__));
return -ENOMEM;
}
memset(ifp, 0, sizeof(dhd_if_t));
ifp->info = dhd;
dhd->iflist[ifidx] = ifp;
strlcpy(ifp->name, name, IFNAMSIZ);
if (mac_addr != NULL)
memcpy(&ifp->mac_addr, mac_addr, ETH_ALEN);
if (handle == NULL) {
ifp->state = WLC_E_IF_ADD;
ifp->idx = ifidx;
ASSERT(dhd->sysioc_tsk);
up(&dhd->sysioc_sem);
} else
ifp->net = (struct net_device *)handle;
return 0;
}
void dhd_del_if(dhd_info_t *dhd, int ifidx)
{
dhd_if_t *ifp;
DHD_TRACE(("%s: idx %d\n", __func__, ifidx));
ASSERT(dhd && ifidx && (ifidx < DHD_MAX_IFS));
ifp = dhd->iflist[ifidx];
if (!ifp) {
DHD_ERROR(("%s: Null interface\n", __func__));
return;
}
ifp->state = WLC_E_IF_DEL;
ifp->idx = ifidx;
ASSERT(dhd->sysioc_tsk);
up(&dhd->sysioc_sem);
}
dhd_pub_t *dhd_attach(struct dhd_bus *bus, uint bus_hdrlen)
{
dhd_info_t *dhd = NULL;
struct net_device *net;
DHD_TRACE(("%s: Enter\n", __func__));
if ((firmware_path != NULL) && (firmware_path[0] != '\0'))
strcpy(fw_path, firmware_path);
if ((nvram_path != NULL) && (nvram_path[0] != '\0'))
strcpy(nv_path, nvram_path);
net = alloc_etherdev(sizeof(dhd));
if (!net) {
DHD_ERROR(("%s: OOM - alloc_etherdev\n", __func__));
goto fail;
}
dhd = kzalloc(sizeof(dhd_info_t), GFP_ATOMIC);
if (!dhd) {
DHD_ERROR(("%s: OOM - alloc dhd_info\n", __func__));
goto fail;
}
memcpy(netdev_priv(net), &dhd, sizeof(dhd));
if (iface_name[0]) {
int len;
char ch;
strncpy(net->name, iface_name, IFNAMSIZ);
net->name[IFNAMSIZ - 1] = 0;
len = strlen(net->name);
ch = net->name[len - 1];
if ((ch > '9' || ch < '0') && (len < IFNAMSIZ - 2))
strcat(net->name, "%d");
}
if (dhd_add_if(dhd, 0, (void *)net, net->name, NULL, 0, 0) ==
DHD_BAD_IF)
goto fail;
net->netdev_ops = NULL;
sema_init(&dhd->proto_sem, 1);
init_waitqueue_head(&dhd->ioctl_resp_wait);
init_waitqueue_head(&dhd->ctrl_wait);
spin_lock_init(&dhd->sdlock);
spin_lock_init(&dhd->txqlock);
dhd->pub.info = dhd;
dhd->pub.bus = bus;
dhd->pub.hdrlen = bus_hdrlen;
if (dhd_prot_attach(&dhd->pub) != 0) {
DHD_ERROR(("dhd_prot_attach failed\n"));
goto fail;
}
#if defined(CONFIG_WIRELESS_EXT)
if (wl_iw_attach(net, (void *)&dhd->pub) != 0) {
DHD_ERROR(("wl_iw_attach failed\n"));
goto fail;
}
#endif
if (IS_CFG80211_FAVORITE()) {
if (unlikely(wl_cfg80211_attach(net, &dhd->pub))) {
DHD_ERROR(("wl_cfg80211_attach failed\n"));
goto fail;
}
if (!NO_FW_REQ()) {
strcpy(fw_path, wl_cfg80211_get_fwname());
strcpy(nv_path, wl_cfg80211_get_nvramname());
}
}
init_timer(&dhd->timer);
dhd->timer.data = (unsigned long) dhd;
dhd->timer.function = dhd_watchdog;
sema_init(&dhd->sdsem, 1);
if ((dhd_watchdog_prio >= 0) && (dhd_dpc_prio >= 0))
dhd->threads_only = true;
else
dhd->threads_only = false;
if (dhd_dpc_prio >= 0) {
sema_init(&dhd->watchdog_sem, 0);
dhd->watchdog_tsk = kthread_run(dhd_watchdog_thread, dhd,
"dhd_watchdog");
if (IS_ERR(dhd->watchdog_tsk)) {
printk(KERN_WARNING
"dhd_watchdog thread failed to start\n");
dhd->watchdog_tsk = NULL;
}
} else {
dhd->watchdog_tsk = NULL;
}
if (dhd_dpc_prio >= 0) {
sema_init(&dhd->dpc_sem, 0);
dhd->dpc_tsk = kthread_run(dhd_dpc_thread, dhd, "dhd_dpc");
if (IS_ERR(dhd->dpc_tsk)) {
printk(KERN_WARNING
"dhd_dpc thread failed to start\n");
dhd->dpc_tsk = NULL;
}
} else {
tasklet_init(&dhd->tasklet, dhd_dpc, (unsigned long) dhd);
dhd->dpc_tsk = NULL;
}
if (dhd_sysioc) {
sema_init(&dhd->sysioc_sem, 0);
dhd->sysioc_tsk = kthread_run(_dhd_sysioc_thread, dhd,
"_dhd_sysioc");
if (IS_ERR(dhd->sysioc_tsk)) {
printk(KERN_WARNING
"_dhd_sysioc thread failed to start\n");
dhd->sysioc_tsk = NULL;
}
} else
dhd->sysioc_tsk = NULL;
memcpy(netdev_priv(net), &dhd, sizeof(dhd));
#if defined(CUSTOMER_HW2) && defined(CONFIG_WIFI_CONTROL_FUNC)
g_bus = bus;
#endif
#if defined(CONFIG_PM_SLEEP)
atomic_set(&dhd_mmc_suspend, false);
if (!IS_CFG80211_FAVORITE())
register_pm_notifier(&dhd_sleep_pm_notifier);
#endif
#ifdef CONFIG_HAS_EARLYSUSPEND
dhd->early_suspend.level = EARLY_SUSPEND_LEVEL_BLANK_SCREEN + 20;
dhd->early_suspend.suspend = dhd_early_suspend;
dhd->early_suspend.resume = dhd_late_resume;
register_early_suspend(&dhd->early_suspend);
#endif
return &dhd->pub;
fail:
if (net)
free_netdev(net);
if (dhd)
dhd_detach(&dhd->pub);
return NULL;
}
int dhd_bus_start(dhd_pub_t *dhdp)
{
int ret = -1;
dhd_info_t *dhd = (dhd_info_t *) dhdp->info;
#ifdef EMBEDDED_PLATFORM
char iovbuf[WL_EVENTING_MASK_LEN + 12];
#endif
ASSERT(dhd);
DHD_TRACE(("%s:\n", __func__));
if (dhd->pub.busstate == DHD_BUS_DOWN) {
if (!(dhd_bus_download_firmware(dhd->pub.bus,
fw_path, nv_path))) {
DHD_ERROR(("%s: dhdsdio_probe_download failed. "
"firmware = %s nvram = %s\n",
__func__, fw_path, nv_path));
return -1;
}
}
dhd->pub.tickcnt = 0;
dhd_os_wd_timer(&dhd->pub, dhd_watchdog_ms);
ret = dhd_bus_init(&dhd->pub, true);
if (ret != 0) {
DHD_ERROR(("%s, dhd_bus_init failed %d\n", __func__, ret));
return ret;
}
#if defined(OOB_INTR_ONLY)
if (bcmsdh_register_oob_intr(dhdp)) {
del_timer_sync(&dhd->timer);
dhd->wd_timer_valid = false;
DHD_ERROR(("%s Host failed to resgister for OOB\n", __func__));
return -ENODEV;
}
dhd_enable_oob_intr(dhd->pub.bus, true);
#endif
if (dhd->pub.busstate != DHD_BUS_DATA) {
del_timer_sync(&dhd->timer);
dhd->wd_timer_valid = false;
DHD_ERROR(("%s failed bus is not ready\n", __func__));
return -ENODEV;
}
#ifdef EMBEDDED_PLATFORM
bcm_mkiovar("event_msgs", dhdp->eventmask, WL_EVENTING_MASK_LEN, iovbuf,
sizeof(iovbuf));
dhdcdc_query_ioctl(dhdp, 0, WLC_GET_VAR, iovbuf, sizeof(iovbuf));
memcpy(dhdp->eventmask, iovbuf, WL_EVENTING_MASK_LEN);
setbit(dhdp->eventmask, WLC_E_SET_SSID);
setbit(dhdp->eventmask, WLC_E_PRUNE);
setbit(dhdp->eventmask, WLC_E_AUTH);
setbit(dhdp->eventmask, WLC_E_REASSOC);
setbit(dhdp->eventmask, WLC_E_REASSOC_IND);
setbit(dhdp->eventmask, WLC_E_DEAUTH_IND);
setbit(dhdp->eventmask, WLC_E_DISASSOC_IND);
setbit(dhdp->eventmask, WLC_E_DISASSOC);
setbit(dhdp->eventmask, WLC_E_JOIN);
setbit(dhdp->eventmask, WLC_E_ASSOC_IND);
setbit(dhdp->eventmask, WLC_E_PSK_SUP);
setbit(dhdp->eventmask, WLC_E_LINK);
setbit(dhdp->eventmask, WLC_E_NDIS_LINK);
setbit(dhdp->eventmask, WLC_E_MIC_ERROR);
setbit(dhdp->eventmask, WLC_E_PMKID_CACHE);
setbit(dhdp->eventmask, WLC_E_TXFAIL);
setbit(dhdp->eventmask, WLC_E_JOIN_START);
setbit(dhdp->eventmask, WLC_E_SCAN_COMPLETE);
#ifdef PNO_SUPPORT
setbit(dhdp->eventmask, WLC_E_PFN_NET_FOUND);
#endif
dhdp->pktfilter_count = 1;
dhdp->pktfilter[0] = "100 0 0 0 0x01 0x00";
#endif
ret = dhd_prot_init(&dhd->pub);
if (ret < 0)
return ret;
return 0;
}
int
dhd_iovar(dhd_pub_t *pub, int ifidx, char *name, char *cmd_buf, uint cmd_len,
int set)
{
char buf[strlen(name) + 1 + cmd_len];
int len = sizeof(buf);
wl_ioctl_t ioc;
int ret;
len = bcm_mkiovar(name, cmd_buf, cmd_len, buf, len);
memset(&ioc, 0, sizeof(ioc));
ioc.cmd = set ? WLC_SET_VAR : WLC_GET_VAR;
ioc.buf = buf;
ioc.len = len;
ioc.set = set;
ret = dhd_prot_ioctl(pub, ifidx, &ioc, ioc.buf, ioc.len);
if (!set && ret >= 0)
memcpy(cmd_buf, buf, cmd_len);
return ret;
}
int dhd_net_attach(dhd_pub_t *dhdp, int ifidx)
{
dhd_info_t *dhd = (dhd_info_t *) dhdp->info;
struct net_device *net;
u8 temp_addr[ETH_ALEN] = {
0x00, 0x90, 0x4c, 0x11, 0x22, 0x33};
DHD_TRACE(("%s: ifidx %d\n", __func__, ifidx));
ASSERT(dhd && dhd->iflist[ifidx]);
net = dhd->iflist[ifidx]->net;
ASSERT(net);
ASSERT(!net->netdev_ops);
net->netdev_ops = &dhd_ops_pri;
if (ifidx != 0) {
memcpy(temp_addr, dhd->pub.mac, ETH_ALEN);
}
if (ifidx == 1) {
DHD_TRACE(("%s ACCESS POINT MAC: \n", __func__));
temp_addr[0] |= 0X02;
}
net->hard_header_len = ETH_HLEN + dhd->pub.hdrlen;
net->ethtool_ops = &dhd_ethtool_ops;
dhd->pub.rxsz = net->mtu + net->hard_header_len + dhd->pub.hdrlen;
memcpy(net->dev_addr, temp_addr, ETH_ALEN);
if (register_netdev(net) != 0) {
DHD_ERROR(("%s: couldn't register the net device\n",
__func__));
goto fail;
}
DHD_INFO(("%s: Broadcom Dongle Host Driver\n", net->name));
return 0;
fail:
net->netdev_ops = NULL;
return -EBADE;
}
void dhd_bus_detach(dhd_pub_t *dhdp)
{
dhd_info_t *dhd;
DHD_TRACE(("%s: Enter\n", __func__));
if (dhdp) {
dhd = (dhd_info_t *) dhdp->info;
if (dhd) {
dhd_prot_stop(&dhd->pub);
dhd_bus_stop(dhd->pub.bus, true);
#if defined(OOB_INTR_ONLY)
bcmsdh_unregister_oob_intr();
#endif
del_timer_sync(&dhd->timer);
dhd->wd_timer_valid = false;
}
}
}
void dhd_detach(dhd_pub_t *dhdp)
{
dhd_info_t *dhd;
DHD_TRACE(("%s: Enter\n", __func__));
if (dhdp) {
dhd = (dhd_info_t *) dhdp->info;
if (dhd) {
dhd_if_t *ifp;
int i;
#if defined(CONFIG_HAS_EARLYSUSPEND)
if (dhd->early_suspend.suspend)
unregister_early_suspend(&dhd->early_suspend);
#endif
for (i = 1; i < DHD_MAX_IFS; i++)
if (dhd->iflist[i])
dhd_del_if(dhd, i);
ifp = dhd->iflist[0];
ASSERT(ifp);
if (ifp->net->netdev_ops == &dhd_ops_pri) {
dhd_stop(ifp->net);
unregister_netdev(ifp->net);
}
if (dhd->watchdog_tsk) {
send_sig(SIGTERM, dhd->watchdog_tsk, 1);
kthread_stop(dhd->watchdog_tsk);
dhd->watchdog_tsk = NULL;
}
if (dhd->dpc_tsk) {
send_sig(SIGTERM, dhd->dpc_tsk, 1);
kthread_stop(dhd->dpc_tsk);
dhd->dpc_tsk = NULL;
} else
tasklet_kill(&dhd->tasklet);
if (dhd->sysioc_tsk) {
send_sig(SIGTERM, dhd->sysioc_tsk, 1);
kthread_stop(dhd->sysioc_tsk);
dhd->sysioc_tsk = NULL;
}
dhd_bus_detach(dhdp);
if (dhdp->prot)
dhd_prot_detach(dhdp);
#if defined(CONFIG_WIRELESS_EXT)
wl_iw_detach();
#endif
if (IS_CFG80211_FAVORITE())
wl_cfg80211_detach();
#if defined(CONFIG_PM_SLEEP)
if (!IS_CFG80211_FAVORITE())
unregister_pm_notifier(&dhd_sleep_pm_notifier);
#endif
free_netdev(ifp->net);
kfree(ifp);
kfree(dhd);
}
}
}
static void __exit dhd_module_cleanup(void)
{
DHD_TRACE(("%s: Enter\n", __func__));
dhd_bus_unregister();
#if defined(CUSTOMER_HW2) && defined(CONFIG_WIFI_CONTROL_FUNC)
wifi_del_dev();
#endif
dhd_customer_gpio_wlan_ctrl(WLAN_POWER_OFF);
}
static int __init dhd_module_init(void)
{
int error;
DHD_TRACE(("%s: Enter\n", __func__));
do {
if ((dhd_watchdog_prio < 0) && (dhd_dpc_prio < 0))
break;
if ((dhd_watchdog_prio >= 0) && (dhd_dpc_prio >= 0)
&& dhd_deferred_tx)
break;
DHD_ERROR(("Invalid module parameters.\n"));
return -EINVAL;
} while (0);
dhd_customer_gpio_wlan_ctrl(WLAN_POWER_ON);
#if defined(CUSTOMER_HW2) && defined(CONFIG_WIFI_CONTROL_FUNC)
sema_init(&wifi_control_sem, 0);
error = wifi_add_dev();
if (error) {
DHD_ERROR(("%s: platform_driver_register failed\n", __func__));
goto failed;
}
if (down_timeout(&wifi_control_sem, msecs_to_jiffies(1000)) != 0) {
printk(KERN_ERR "%s: platform_driver_register timeout\n",
__func__);
wifi_del_dev();
goto failed;
}
#endif
error = dhd_bus_register();
if (error) {
DHD_ERROR(("%s: sdio_register_driver failed\n", __func__));
goto failed;
}
return error;
failed:
dhd_customer_gpio_wlan_ctrl(WLAN_POWER_OFF);
return -EINVAL;
}
int dhd_os_proto_block(dhd_pub_t *pub)
{
dhd_info_t *dhd = (dhd_info_t *) (pub->info);
if (dhd) {
down(&dhd->proto_sem);
return 1;
}
return 0;
}
int dhd_os_proto_unblock(dhd_pub_t *pub)
{
dhd_info_t *dhd = (dhd_info_t *) (pub->info);
if (dhd) {
up(&dhd->proto_sem);
return 1;
}
return 0;
}
unsigned int dhd_os_get_ioctl_resp_timeout(void)
{
return (unsigned int)dhd_ioctl_timeout_msec;
}
void dhd_os_set_ioctl_resp_timeout(unsigned int timeout_msec)
{
dhd_ioctl_timeout_msec = (int)timeout_msec;
}
int dhd_os_ioctl_resp_wait(dhd_pub_t *pub, uint *condition, bool *pending)
{
dhd_info_t *dhd = (dhd_info_t *) (pub->info);
DECLARE_WAITQUEUE(wait, current);
int timeout = dhd_ioctl_timeout_msec;
timeout = timeout * HZ / 1000;
add_wait_queue(&dhd->ioctl_resp_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (!(*condition) && (!signal_pending(current) && timeout))
timeout = schedule_timeout(timeout);
if (signal_pending(current))
*pending = true;
set_current_state(TASK_RUNNING);
remove_wait_queue(&dhd->ioctl_resp_wait, &wait);
return timeout;
}
int dhd_os_ioctl_resp_wake(dhd_pub_t *pub)
{
dhd_info_t *dhd = (dhd_info_t *) (pub->info);
if (waitqueue_active(&dhd->ioctl_resp_wait))
wake_up_interruptible(&dhd->ioctl_resp_wait);
return 0;
}
void dhd_os_wd_timer(void *bus, uint wdtick)
{
dhd_pub_t *pub = bus;
static uint save_dhd_watchdog_ms;
dhd_info_t *dhd = (dhd_info_t *) pub->info;
if (pub->busstate == DHD_BUS_DOWN)
return;
if (!wdtick && dhd->wd_timer_valid == true) {
del_timer_sync(&dhd->timer);
dhd->wd_timer_valid = false;
save_dhd_watchdog_ms = wdtick;
return;
}
if (wdtick) {
dhd_watchdog_ms = (uint) wdtick;
if (save_dhd_watchdog_ms != dhd_watchdog_ms) {
if (dhd->wd_timer_valid == true)
del_timer_sync(&dhd->timer);
dhd->timer.expires =
jiffies + dhd_watchdog_ms * HZ / 1000;
add_timer(&dhd->timer);
} else {
mod_timer(&dhd->timer,
jiffies + dhd_watchdog_ms * HZ / 1000);
}
dhd->wd_timer_valid = true;
save_dhd_watchdog_ms = wdtick;
}
}
void *dhd_os_open_image(char *filename)
{
struct file *fp;
if (IS_CFG80211_FAVORITE() && !NO_FW_REQ())
return wl_cfg80211_request_fw(filename);
fp = filp_open(filename, O_RDONLY, 0);
if (IS_ERR(fp))
fp = NULL;
return fp;
}
int dhd_os_get_image_block(char *buf, int len, void *image)
{
struct file *fp = (struct file *)image;
int rdlen;
if (IS_CFG80211_FAVORITE() && !NO_FW_REQ())
return wl_cfg80211_read_fw(buf, len);
if (!image)
return 0;
rdlen = kernel_read(fp, fp->f_pos, buf, len);
if (rdlen > 0)
fp->f_pos += rdlen;
return rdlen;
}
void dhd_os_close_image(void *image)
{
if (IS_CFG80211_FAVORITE() && !NO_FW_REQ())
return wl_cfg80211_release_fw();
if (image)
filp_close((struct file *)image, NULL);
}
void dhd_os_sdlock(dhd_pub_t *pub)
{
dhd_info_t *dhd;
dhd = (dhd_info_t *) (pub->info);
if (dhd->threads_only)
down(&dhd->sdsem);
else
spin_lock_bh(&dhd->sdlock);
}
void dhd_os_sdunlock(dhd_pub_t *pub)
{
dhd_info_t *dhd;
dhd = (dhd_info_t *) (pub->info);
if (dhd->threads_only)
up(&dhd->sdsem);
else
spin_unlock_bh(&dhd->sdlock);
}
void dhd_os_sdlock_txq(dhd_pub_t *pub)
{
dhd_info_t *dhd;
dhd = (dhd_info_t *) (pub->info);
spin_lock_bh(&dhd->txqlock);
}
void dhd_os_sdunlock_txq(dhd_pub_t *pub)
{
dhd_info_t *dhd;
dhd = (dhd_info_t *) (pub->info);
spin_unlock_bh(&dhd->txqlock);
}
void dhd_os_sdlock_rxq(dhd_pub_t *pub)
{
}
void dhd_os_sdunlock_rxq(dhd_pub_t *pub)
{
}
void dhd_os_sdtxlock(dhd_pub_t *pub)
{
dhd_os_sdlock(pub);
}
void dhd_os_sdtxunlock(dhd_pub_t *pub)
{
dhd_os_sdunlock(pub);
}
static int
dhd_wl_host_event(dhd_info_t *dhd, int *ifidx, void *pktdata,
wl_event_msg_t *event, void **data)
{
int bcmerror = 0;
ASSERT(dhd != NULL);
bcmerror = wl_host_event(dhd, ifidx, pktdata, event, data);
if (bcmerror != 0)
return bcmerror;
#if defined(CONFIG_WIRELESS_EXT)
if (!IS_CFG80211_FAVORITE()) {
if ((dhd->iflist[*ifidx] == NULL)
|| (dhd->iflist[*ifidx]->net == NULL)) {
DHD_ERROR(("%s Exit null pointer\n", __func__));
return bcmerror;
}
if (dhd->iflist[*ifidx]->net)
wl_iw_event(dhd->iflist[*ifidx]->net, event, *data);
}
#endif
if (IS_CFG80211_FAVORITE()) {
ASSERT(dhd->iflist[*ifidx] != NULL);
ASSERT(dhd->iflist[*ifidx]->net != NULL);
if (dhd->iflist[*ifidx]->net)
wl_cfg80211_event(dhd->iflist[*ifidx]->net, event,
*data);
}
return bcmerror;
}
void dhd_sendup_event(dhd_pub_t *dhdp, wl_event_msg_t *event, void *data)
{
switch (be32_to_cpu(event->event_type)) {
default:
break;
}
}
void dhd_wait_for_event(dhd_pub_t *dhd, bool *lockvar)
{
struct dhd_info *dhdinfo = dhd->info;
dhd_os_sdunlock(dhd);
wait_event_interruptible_timeout(dhdinfo->ctrl_wait,
(*lockvar == false), HZ * 2);
dhd_os_sdlock(dhd);
return;
}
void dhd_wait_event_wakeup(dhd_pub_t *dhd)
{
struct dhd_info *dhdinfo = dhd->info;
if (waitqueue_active(&dhdinfo->ctrl_wait))
wake_up_interruptible(&dhdinfo->ctrl_wait);
return;
}
int dhd_dev_reset(struct net_device *dev, u8 flag)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
if (flag)
dhd_os_wd_timer(&dhd->pub, 0);
dhd_bus_devreset(&dhd->pub, flag);
if (!flag)
dhd_os_wd_timer(&dhd->pub, dhd_watchdog_ms);
DHD_ERROR(("%s: WLAN OFF DONE\n", __func__));
return 1;
}
int net_os_set_suspend_disable(struct net_device *dev, int val)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
int ret = 0;
if (dhd) {
ret = dhd->pub.suspend_disable_flag;
dhd->pub.suspend_disable_flag = val;
}
return ret;
}
int net_os_set_suspend(struct net_device *dev, int val)
{
int ret = 0;
#if defined(CONFIG_HAS_EARLYSUSPEND)
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
if (dhd) {
dhd_os_proto_block(&dhd->pub);
ret = dhd_set_suspend(val, &dhd->pub);
dhd_os_proto_unblock(&dhd->pub);
}
#endif
return ret;
}
int net_os_set_dtim_skip(struct net_device *dev, int val)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(dev);
if (dhd)
dhd->pub.dtim_skip = val;
return 0;
}
int net_os_set_packet_filter(struct net_device *dev, int val)
{
dhd_info_t *dhd = *(dhd_info_t **) netdev_priv(dev);
int ret = 0;
if (dhd && dhd->pub.up) {
dhd_os_proto_block(&dhd->pub);
if (dhd->pub.in_suspend) {
if (!val || (val && !dhd->pub.suspend_disable_flag))
dhd_set_packet_filter(val, &dhd->pub);
}
dhd_os_proto_unblock(&dhd->pub);
}
return ret;
}
void dhd_dev_init_ioctl(struct net_device *dev)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
dhd_preinit_ioctls(&dhd->pub);
}
int dhd_dev_pno_reset(struct net_device *dev)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
return dhd_pno_clean(&dhd->pub);
}
int dhd_dev_pno_enable(struct net_device *dev, int pfn_enabled)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
return dhd_pno_enable(&dhd->pub, pfn_enabled);
}
int
dhd_dev_pno_set(struct net_device *dev, wlc_ssid_t *ssids_local, int nssid,
unsigned char scan_fr)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
return dhd_pno_set(&dhd->pub, ssids_local, nssid, scan_fr);
}
int dhd_dev_get_pno_status(struct net_device *dev)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
return dhd_pno_get_status(&dhd->pub);
}
static int dhd_get_pend_8021x_cnt(dhd_info_t *dhd)
{
return atomic_read(&dhd->pend_8021x_cnt);
}
int dhd_wait_pend8021x(struct net_device *dev)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(dev);
int timeout = 10 * HZ / 1000;
int ntimes = MAX_WAIT_FOR_8021X_TX;
int pend = dhd_get_pend_8021x_cnt(dhd);
while (ntimes && pend) {
if (pend) {
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(timeout);
set_current_state(TASK_RUNNING);
ntimes--;
}
pend = dhd_get_pend_8021x_cnt(dhd);
}
return pend;
}
void wl_os_wd_timer(struct net_device *ndev, uint wdtick)
{
dhd_info_t *dhd = *(dhd_info_t **)netdev_priv(ndev);
dhd_os_wd_timer(&dhd->pub, wdtick);
}
int write_to_file(dhd_pub_t *dhd, u8 *buf, int size)
{
int ret = 0;
struct file *fp;
mm_segment_t old_fs;
loff_t pos = 0;
old_fs = get_fs();
set_fs(KERNEL_DS);
fp = filp_open("/tmp/mem_dump", O_WRONLY | O_CREAT, 0640);
if (!fp) {
DHD_ERROR(("%s: open file error\n", __func__));
ret = -1;
goto exit;
}
fp->f_op->write(fp, buf, size, &pos);
exit:
kfree(buf);
if (fp)
filp_close(fp, current->files);
set_fs(old_fs);
return ret;
}
