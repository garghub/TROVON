static int p80211knetdev_init(netdevice_t *netdev)
{
return 0;
}
static int p80211knetdev_open(netdevice_t *netdev)
{
int result = 0;
wlandevice_t *wlandev = netdev->ml_priv;
if (wlandev->msdstate != WLAN_MSD_RUNNING)
return -ENODEV;
if (wlandev->open) {
result = wlandev->open(wlandev);
if (result == 0) {
netif_start_queue(wlandev->netdev);
wlandev->state = WLAN_DEVICE_OPEN;
}
} else {
result = -EAGAIN;
}
return result;
}
static int p80211knetdev_stop(netdevice_t *netdev)
{
int result = 0;
wlandevice_t *wlandev = netdev->ml_priv;
if (wlandev->close)
result = wlandev->close(wlandev);
netif_stop_queue(wlandev->netdev);
wlandev->state = WLAN_DEVICE_CLOSED;
return result;
}
void p80211netdev_rx(wlandevice_t *wlandev, struct sk_buff *skb)
{
skb_queue_tail(&wlandev->nsd_rxq, skb);
tasklet_schedule(&wlandev->rx_bh);
}
static int p80211_convert_to_ether(wlandevice_t *wlandev, struct sk_buff *skb)
{
struct p80211_hdr_a3 *hdr;
hdr = (struct p80211_hdr_a3 *) skb->data;
if (p80211_rx_typedrop(wlandev, hdr->fc))
return CONV_TO_ETHER_SKIPPED;
if (wlandev->netdev->flags & IFF_ALLMULTI) {
if (!ether_addr_equal_unaligned(wlandev->netdev->dev_addr,
hdr->a1)) {
if (!is_multicast_ether_addr(hdr->a1))
return CONV_TO_ETHER_SKIPPED;
}
}
if (skb_p80211_to_ether(wlandev, wlandev->ethconv, skb) == 0) {
skb->dev->last_rx = jiffies;
wlandev->netdev->stats.rx_packets++;
wlandev->netdev->stats.rx_bytes += skb->len;
netif_rx_ni(skb);
return 0;
}
netdev_dbg(wlandev->netdev, "p80211_convert_to_ether failed.\n");
return CONV_TO_ETHER_FAILED;
}
static void p80211netdev_rx_bh(unsigned long arg)
{
wlandevice_t *wlandev = (wlandevice_t *) arg;
struct sk_buff *skb = NULL;
netdevice_t *dev = wlandev->netdev;
while ((skb = skb_dequeue(&wlandev->nsd_rxq))) {
if (wlandev->state == WLAN_DEVICE_OPEN) {
if (dev->type != ARPHRD_ETHER) {
skb->dev = dev;
skb_reset_mac_header(skb);
skb->ip_summed = CHECKSUM_NONE;
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = htons(ETH_P_80211_RAW);
dev->last_rx = jiffies;
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
netif_rx_ni(skb);
continue;
} else {
if (!p80211_convert_to_ether(wlandev, skb))
continue;
}
}
dev_kfree_skb(skb);
}
}
static int p80211knetdev_hard_start_xmit(struct sk_buff *skb,
netdevice_t *netdev)
{
int result = 0;
int txresult = -1;
wlandevice_t *wlandev = netdev->ml_priv;
union p80211_hdr p80211_hdr;
struct p80211_metawep p80211_wep;
p80211_wep.data = NULL;
if (!skb)
return NETDEV_TX_OK;
if (wlandev->state != WLAN_DEVICE_OPEN) {
result = 1;
goto failed;
}
memset(&p80211_hdr, 0, sizeof(union p80211_hdr));
memset(&p80211_wep, 0, sizeof(struct p80211_metawep));
if (netif_queue_stopped(netdev)) {
netdev_dbg(netdev, "called when queue stopped.\n");
result = 1;
goto failed;
}
netif_stop_queue(netdev);
switch (wlandev->macmode) {
case WLAN_MACMODE_IBSS_STA:
case WLAN_MACMODE_ESS_STA:
case WLAN_MACMODE_ESS_AP:
break;
default:
if (be16_to_cpu(skb->protocol) != ETH_P_80211_RAW) {
netif_start_queue(wlandev->netdev);
netdev_notice(netdev, "Tx attempt prior to association, frame dropped.\n");
netdev->stats.tx_dropped++;
result = 0;
goto failed;
}
break;
}
if (be16_to_cpu(skb->protocol) == ETH_P_80211_RAW) {
if (!capable(CAP_NET_ADMIN)) {
result = 1;
goto failed;
}
memcpy(&p80211_hdr, skb->data, sizeof(union p80211_hdr));
skb_pull(skb, sizeof(union p80211_hdr));
} else {
if (skb_ether_to_p80211
(wlandev, wlandev->ethconv, skb, &p80211_hdr,
&p80211_wep) != 0) {
netdev_dbg(netdev, "ether_to_80211(%d) failed.\n",
wlandev->ethconv);
result = 1;
goto failed;
}
}
if (!wlandev->txframe) {
result = 1;
goto failed;
}
netif_trans_update(netdev);
netdev->stats.tx_packets++;
netdev->stats.tx_bytes += skb->len;
txresult = wlandev->txframe(wlandev, skb, &p80211_hdr, &p80211_wep);
if (txresult == 0) {
netif_wake_queue(wlandev->netdev);
result = NETDEV_TX_OK;
} else if (txresult == 1) {
netdev_dbg(netdev, "txframe success, no more bufs\n");
result = NETDEV_TX_OK;
} else if (txresult == 2) {
netdev_dbg(netdev, "txframe returned alloc_fail\n");
result = NETDEV_TX_BUSY;
} else {
netdev_dbg(netdev, "txframe returned full or busy\n");
result = NETDEV_TX_BUSY;
}
failed:
if ((p80211_wep.data) && (p80211_wep.data != skb->data))
kzfree(p80211_wep.data);
if (!result)
dev_kfree_skb(skb);
return result;
}
static void p80211knetdev_set_multicast_list(netdevice_t *dev)
{
wlandevice_t *wlandev = dev->ml_priv;
if (wlandev->set_multicast_list)
wlandev->set_multicast_list(wlandev, dev);
}
static int p80211netdev_ethtool(wlandevice_t *wlandev, void __user *useraddr)
{
u32 ethcmd;
struct ethtool_drvinfo info;
struct ethtool_value edata;
memset(&info, 0, sizeof(info));
memset(&edata, 0, sizeof(edata));
if (copy_from_user(&ethcmd, useraddr, sizeof(ethcmd)))
return -EFAULT;
switch (ethcmd) {
case ETHTOOL_GDRVINFO:
info.cmd = ethcmd;
snprintf(info.driver, sizeof(info.driver), "p80211_%s",
wlandev->nsdname);
snprintf(info.version, sizeof(info.version), "%s",
WLAN_RELEASE);
if (copy_to_user(useraddr, &info, sizeof(info)))
return -EFAULT;
return 0;
#ifdef ETHTOOL_GLINK
case ETHTOOL_GLINK:
edata.cmd = ethcmd;
if (wlandev->linkstatus &&
(wlandev->macmode != WLAN_MACMODE_NONE)) {
edata.data = 1;
} else {
edata.data = 0;
}
if (copy_to_user(useraddr, &edata, sizeof(edata)))
return -EFAULT;
return 0;
#endif
}
return -EOPNOTSUPP;
}
static int p80211knetdev_do_ioctl(netdevice_t *dev, struct ifreq *ifr, int cmd)
{
int result = 0;
struct p80211ioctl_req *req = (struct p80211ioctl_req *) ifr;
wlandevice_t *wlandev = dev->ml_priv;
u8 *msgbuf;
netdev_dbg(dev, "rx'd ioctl, cmd=%d, len=%d\n", cmd, req->len);
#ifdef SIOCETHTOOL
if (cmd == SIOCETHTOOL) {
result =
p80211netdev_ethtool(wlandev, (void __user *)ifr->ifr_data);
goto bail;
}
#endif
if (req->magic != P80211_IOCTL_MAGIC) {
result = -ENOSYS;
goto bail;
}
if (cmd == P80211_IFTEST) {
result = 0;
goto bail;
} else if (cmd != P80211_IFREQ) {
result = -ENOSYS;
goto bail;
}
msgbuf = kmalloc(req->len, GFP_KERNEL);
if (msgbuf) {
if (copy_from_user(msgbuf, (void __user *)req->data, req->len))
result = -EFAULT;
else
result = p80211req_dorequest(wlandev, msgbuf);
if (result == 0) {
if (copy_to_user
((void __user *)req->data, msgbuf, req->len)) {
result = -EFAULT;
}
}
kfree(msgbuf);
} else {
result = -ENOMEM;
}
bail:
return result;
}
static int p80211knetdev_set_mac_address(netdevice_t *dev, void *addr)
{
struct sockaddr *new_addr = addr;
struct p80211msg_dot11req_mibset dot11req;
p80211item_unk392_t *mibattr;
p80211item_pstr6_t *macaddr;
p80211item_uint32_t *resultcode;
int result;
if (netif_running(dev))
return -EBUSY;
mibattr = &dot11req.mibattribute;
macaddr = (p80211item_pstr6_t *) &mibattr->data;
resultcode = &dot11req.resultcode;
memset(&dot11req, 0, sizeof(struct p80211msg_dot11req_mibset));
dot11req.msgcode = DIDmsg_dot11req_mibset;
dot11req.msglen = sizeof(struct p80211msg_dot11req_mibset);
memcpy(dot11req.devname,
((wlandevice_t *) dev->ml_priv)->name, WLAN_DEVNAMELEN_MAX - 1);
mibattr->did = DIDmsg_dot11req_mibset_mibattribute;
mibattr->status = P80211ENUM_msgitem_status_data_ok;
mibattr->len = sizeof(mibattr->data);
macaddr->did = DIDmib_dot11mac_dot11OperationTable_dot11MACAddress;
macaddr->status = P80211ENUM_msgitem_status_data_ok;
macaddr->len = sizeof(macaddr->data);
macaddr->data.len = ETH_ALEN;
memcpy(&macaddr->data.data, new_addr->sa_data, ETH_ALEN);
resultcode->did = DIDmsg_dot11req_mibset_resultcode;
resultcode->status = P80211ENUM_msgitem_status_no_value;
resultcode->len = sizeof(resultcode->data);
resultcode->data = 0;
result = p80211req_dorequest(dev->ml_priv, (u8 *) &dot11req);
if (result != 0 || resultcode->data != P80211ENUM_resultcode_success) {
netdev_err(dev, "Low-level driver failed dot11req_mibset(dot11MACAddress).\n");
result = -EADDRNOTAVAIL;
} else {
memcpy(dev->dev_addr, new_addr->sa_data, dev->addr_len);
}
return result;
}
static int wlan_change_mtu(netdevice_t *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > (2312 - 20 - 8)))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
int wlan_setup(wlandevice_t *wlandev, struct device *physdev)
{
int result = 0;
netdevice_t *netdev;
struct wiphy *wiphy;
struct wireless_dev *wdev;
wlandev->state = WLAN_DEVICE_CLOSED;
wlandev->ethconv = WLAN_ETHCONV_8021h;
wlandev->macmode = WLAN_MACMODE_NONE;
skb_queue_head_init(&wlandev->nsd_rxq);
tasklet_init(&wlandev->rx_bh,
p80211netdev_rx_bh, (unsigned long)wlandev);
wiphy = wlan_create_wiphy(physdev, wlandev);
if (!wiphy) {
dev_err(physdev, "Failed to alloc wiphy.\n");
return 1;
}
netdev = alloc_netdev(sizeof(struct wireless_dev), "wlan%d",
NET_NAME_UNKNOWN, ether_setup);
if (!netdev) {
dev_err(physdev, "Failed to alloc netdev.\n");
wlan_free_wiphy(wiphy);
result = 1;
} else {
wlandev->netdev = netdev;
netdev->ml_priv = wlandev;
netdev->netdev_ops = &p80211_netdev_ops;
wdev = netdev_priv(netdev);
wdev->wiphy = wiphy;
wdev->iftype = NL80211_IFTYPE_STATION;
netdev->ieee80211_ptr = wdev;
netif_stop_queue(netdev);
netif_carrier_off(netdev);
}
return result;
}
void wlan_unsetup(wlandevice_t *wlandev)
{
struct wireless_dev *wdev;
tasklet_kill(&wlandev->rx_bh);
if (wlandev->netdev) {
wdev = netdev_priv(wlandev->netdev);
if (wdev->wiphy)
wlan_free_wiphy(wdev->wiphy);
free_netdev(wlandev->netdev);
wlandev->netdev = NULL;
}
}
int register_wlandev(wlandevice_t *wlandev)
{
return register_netdev(wlandev->netdev);
}
int unregister_wlandev(wlandevice_t *wlandev)
{
struct sk_buff *skb;
unregister_netdev(wlandev->netdev);
while ((skb = skb_dequeue(&wlandev->nsd_rxq)))
dev_kfree_skb(skb);
return 0;
}
void p80211netdev_hwremoved(wlandevice_t *wlandev)
{
wlandev->hwremoved = 1;
if (wlandev->state == WLAN_DEVICE_OPEN)
netif_stop_queue(wlandev->netdev);
netif_device_detach(wlandev->netdev);
}
static int p80211_rx_typedrop(wlandevice_t *wlandev, u16 fc)
{
u16 ftype;
u16 fstype;
int drop = 0;
ftype = WLAN_GET_FC_FTYPE(fc);
fstype = WLAN_GET_FC_FSTYPE(fc);
#if 0
netdev_dbg(wlandev->netdev, "rx_typedrop : ftype=%d fstype=%d.\n",
ftype, fstype);
#endif
switch (ftype) {
case WLAN_FTYPE_MGMT:
if ((wlandev->netdev->flags & IFF_PROMISC) ||
(wlandev->netdev->flags & IFF_ALLMULTI)) {
drop = 1;
break;
}
netdev_dbg(wlandev->netdev, "rx'd mgmt:\n");
wlandev->rx.mgmt++;
switch (fstype) {
case WLAN_FSTYPE_ASSOCREQ:
wlandev->rx.assocreq++;
break;
case WLAN_FSTYPE_ASSOCRESP:
wlandev->rx.assocresp++;
break;
case WLAN_FSTYPE_REASSOCREQ:
wlandev->rx.reassocreq++;
break;
case WLAN_FSTYPE_REASSOCRESP:
wlandev->rx.reassocresp++;
break;
case WLAN_FSTYPE_PROBEREQ:
wlandev->rx.probereq++;
break;
case WLAN_FSTYPE_PROBERESP:
wlandev->rx.proberesp++;
break;
case WLAN_FSTYPE_BEACON:
wlandev->rx.beacon++;
break;
case WLAN_FSTYPE_ATIM:
wlandev->rx.atim++;
break;
case WLAN_FSTYPE_DISASSOC:
wlandev->rx.disassoc++;
break;
case WLAN_FSTYPE_AUTHEN:
wlandev->rx.authen++;
break;
case WLAN_FSTYPE_DEAUTHEN:
wlandev->rx.deauthen++;
break;
default:
wlandev->rx.mgmt_unknown++;
break;
}
drop = 2;
break;
case WLAN_FTYPE_CTL:
if ((wlandev->netdev->flags & IFF_PROMISC) ||
(wlandev->netdev->flags & IFF_ALLMULTI)) {
drop = 1;
break;
}
netdev_dbg(wlandev->netdev, "rx'd ctl:\n");
wlandev->rx.ctl++;
switch (fstype) {
case WLAN_FSTYPE_PSPOLL:
wlandev->rx.pspoll++;
break;
case WLAN_FSTYPE_RTS:
wlandev->rx.rts++;
break;
case WLAN_FSTYPE_CTS:
wlandev->rx.cts++;
break;
case WLAN_FSTYPE_ACK:
wlandev->rx.ack++;
break;
case WLAN_FSTYPE_CFEND:
wlandev->rx.cfend++;
break;
case WLAN_FSTYPE_CFENDCFACK:
wlandev->rx.cfendcfack++;
break;
default:
wlandev->rx.ctl_unknown++;
break;
}
drop = 2;
break;
case WLAN_FTYPE_DATA:
wlandev->rx.data++;
switch (fstype) {
case WLAN_FSTYPE_DATAONLY:
wlandev->rx.dataonly++;
break;
case WLAN_FSTYPE_DATA_CFACK:
wlandev->rx.data_cfack++;
break;
case WLAN_FSTYPE_DATA_CFPOLL:
wlandev->rx.data_cfpoll++;
break;
case WLAN_FSTYPE_DATA_CFACK_CFPOLL:
wlandev->rx.data__cfack_cfpoll++;
break;
case WLAN_FSTYPE_NULL:
netdev_dbg(wlandev->netdev, "rx'd data:null\n");
wlandev->rx.null++;
break;
case WLAN_FSTYPE_CFACK:
netdev_dbg(wlandev->netdev, "rx'd data:cfack\n");
wlandev->rx.cfack++;
break;
case WLAN_FSTYPE_CFPOLL:
netdev_dbg(wlandev->netdev, "rx'd data:cfpoll\n");
wlandev->rx.cfpoll++;
break;
case WLAN_FSTYPE_CFACK_CFPOLL:
netdev_dbg(wlandev->netdev, "rx'd data:cfack_cfpoll\n");
wlandev->rx.cfack_cfpoll++;
break;
default:
wlandev->rx.data_unknown++;
break;
}
break;
}
return drop;
}
static void p80211knetdev_tx_timeout(netdevice_t *netdev)
{
wlandevice_t *wlandev = netdev->ml_priv;
if (wlandev->tx_timeout) {
wlandev->tx_timeout(wlandev);
} else {
netdev_warn(netdev, "Implement tx_timeout for %s\n",
wlandev->nsdname);
netif_wake_queue(wlandev->netdev);
}
}
