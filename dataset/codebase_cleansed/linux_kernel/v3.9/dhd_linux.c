char *brcmf_ifname(struct brcmf_pub *drvr, int ifidx)
{
if (ifidx < 0 || ifidx >= BRCMF_MAX_IFS) {
brcmf_err("ifidx %d out of range\n", ifidx);
return "<if_bad>";
}
if (drvr->iflist[ifidx] == NULL) {
brcmf_err("null i/f %d\n", ifidx);
return "<if_null>";
}
if (drvr->iflist[ifidx]->ndev)
return drvr->iflist[ifidx]->ndev->name;
return "<if_none>";
}
static void _brcmf_set_multicast_list(struct work_struct *work)
{
struct brcmf_if *ifp;
struct net_device *ndev;
struct netdev_hw_addr *ha;
u32 cmd_value, cnt;
__le32 cnt_le;
char *buf, *bufp;
u32 buflen;
s32 err;
ifp = container_of(work, struct brcmf_if, multicast_work);
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
ndev = ifp->ndev;
cmd_value = (ndev->flags & IFF_ALLMULTI) ? true : false;
cnt = netdev_mc_count(ndev);
buflen = sizeof(cnt) + (cnt * ETH_ALEN);
buf = kmalloc(buflen, GFP_ATOMIC);
if (!buf)
return;
bufp = buf;
cnt_le = cpu_to_le32(cnt);
memcpy(bufp, &cnt_le, sizeof(cnt_le));
bufp += sizeof(cnt_le);
netdev_for_each_mc_addr(ha, ndev) {
if (!cnt)
break;
memcpy(bufp, ha->addr, ETH_ALEN);
bufp += ETH_ALEN;
cnt--;
}
err = brcmf_fil_iovar_data_set(ifp, "mcast_list", buf, buflen);
if (err < 0) {
brcmf_err("Setting mcast_list failed, %d\n", err);
cmd_value = cnt ? true : cmd_value;
}
kfree(buf);
err = brcmf_fil_iovar_int_set(ifp, "allmulti", cmd_value);
if (err < 0)
brcmf_err("Setting allmulti failed, %d\n", err);
cmd_value = (ndev->flags & IFF_PROMISC) ? true : false;
err = brcmf_fil_cmd_int_set(ifp, BRCMF_C_SET_PROMISC, cmd_value);
if (err < 0)
brcmf_err("Setting BRCMF_C_SET_PROMISC failed, %d\n",
err);
}
static void
_brcmf_set_mac_address(struct work_struct *work)
{
struct brcmf_if *ifp;
s32 err;
ifp = container_of(work, struct brcmf_if, setmacaddr_work);
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
err = brcmf_fil_iovar_data_set(ifp, "cur_etheraddr", ifp->mac_addr,
ETH_ALEN);
if (err < 0) {
brcmf_err("Setting cur_etheraddr failed, %d\n", err);
} else {
brcmf_dbg(TRACE, "MAC address updated to %pM\n",
ifp->mac_addr);
memcpy(ifp->ndev->dev_addr, ifp->mac_addr, ETH_ALEN);
}
}
static int brcmf_netdev_set_mac_address(struct net_device *ndev, void *addr)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct sockaddr *sa = (struct sockaddr *)addr;
memcpy(&ifp->mac_addr, sa->sa_data, ETH_ALEN);
schedule_work(&ifp->setmacaddr_work);
return 0;
}
static void brcmf_netdev_set_multicast_list(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
schedule_work(&ifp->multicast_work);
}
static netdev_tx_t brcmf_netdev_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
int ret;
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
struct ethhdr *eh;
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
if (drvr->bus_if->state != BRCMF_BUS_DATA) {
brcmf_err("xmit rejected state=%d\n", drvr->bus_if->state);
netif_stop_queue(ndev);
dev_kfree_skb(skb);
ret = -ENODEV;
goto done;
}
if (!drvr->iflist[ifp->bssidx]) {
brcmf_err("bad ifidx %d\n", ifp->bssidx);
netif_stop_queue(ndev);
dev_kfree_skb(skb);
ret = -ENODEV;
goto done;
}
if (skb_headroom(skb) < drvr->hdrlen) {
struct sk_buff *skb2;
brcmf_dbg(INFO, "%s: insufficient headroom\n",
brcmf_ifname(drvr, ifp->bssidx));
drvr->bus_if->tx_realloc++;
skb2 = skb_realloc_headroom(skb, drvr->hdrlen);
dev_kfree_skb(skb);
skb = skb2;
if (skb == NULL) {
brcmf_err("%s: skb_realloc_headroom failed\n",
brcmf_ifname(drvr, ifp->bssidx));
ret = -ENOMEM;
goto done;
}
}
if (skb->len < sizeof(*eh)) {
ret = -EINVAL;
dev_kfree_skb(skb);
goto done;
}
eh = (struct ethhdr *)(skb->data);
if (is_multicast_ether_addr(eh->h_dest))
drvr->tx_multicast++;
if (ntohs(eh->h_proto) == ETH_P_PAE)
atomic_inc(&ifp->pend_8021x_cnt);
brcmf_proto_hdrpush(drvr, ifp->ifidx, skb);
ret = brcmf_bus_txdata(drvr->bus_if, skb);
done:
if (ret) {
ifp->stats.tx_dropped++;
} else {
ifp->stats.tx_packets++;
ifp->stats.tx_bytes += skb->len;
}
return NETDEV_TX_OK;
}
void brcmf_txflowblock(struct device *dev, bool state)
{
struct net_device *ndev;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
int i;
brcmf_dbg(TRACE, "Enter\n");
for (i = 0; i < BRCMF_MAX_IFS; i++)
if (drvr->iflist[i]) {
ndev = drvr->iflist[i]->ndev;
if (state)
netif_stop_queue(ndev);
else
netif_wake_queue(ndev);
}
}
void brcmf_rx_frames(struct device *dev, struct sk_buff_head *skb_list)
{
unsigned char *eth;
uint len;
struct sk_buff *skb, *pnext;
struct brcmf_if *ifp;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
u8 ifidx;
int ret;
brcmf_dbg(TRACE, "Enter\n");
skb_queue_walk_safe(skb_list, skb, pnext) {
skb_unlink(skb, skb_list);
ret = brcmf_proto_hdrpull(drvr, &ifidx, skb);
ifp = drvr->iflist[ifidx];
if (ret || !ifp || !ifp->ndev) {
if ((ret != -ENODATA) && ifp)
ifp->stats.rx_errors++;
brcmu_pkt_buf_free_skb(skb);
continue;
}
eth = skb->data;
len = skb->len;
skb->dev = ifp->ndev;
skb->protocol = eth_type_trans(skb, skb->dev);
if (skb->pkt_type == PACKET_MULTICAST)
ifp->stats.multicast++;
skb->data = eth;
skb->len = len;
skb_pull(skb, ETH_HLEN);
brcmf_fweh_process_skb(drvr, skb, &ifidx);
if (drvr->iflist[ifidx]) {
ifp = drvr->iflist[ifidx];
ifp->ndev->last_rx = jiffies;
}
if (!(ifp->ndev->flags & IFF_UP)) {
brcmu_pkt_buf_free_skb(skb);
continue;
}
ifp->stats.rx_bytes += skb->len;
ifp->stats.rx_packets++;
if (in_interrupt())
netif_rx(skb);
else
netif_rx_ni(skb);
}
}
void brcmf_txcomplete(struct device *dev, struct sk_buff *txp, bool success)
{
u8 ifidx;
struct ethhdr *eh;
u16 type;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
struct brcmf_if *ifp;
brcmf_proto_hdrpull(drvr, &ifidx, txp);
ifp = drvr->iflist[ifidx];
if (!ifp)
return;
eh = (struct ethhdr *)(txp->data);
type = ntohs(eh->h_proto);
if (type == ETH_P_PAE) {
atomic_dec(&ifp->pend_8021x_cnt);
if (waitqueue_active(&ifp->pend_8021x_wait))
wake_up(&ifp->pend_8021x_wait);
}
if (!success)
ifp->stats.tx_errors++;
}
static struct net_device_stats *brcmf_netdev_get_stats(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
return &ifp->stats;
}
static int brcmf_toe_set(struct brcmf_if *ifp, u32 toe_ol)
{
s32 err;
err = brcmf_fil_iovar_int_set(ifp, "toe_ol", toe_ol);
if (err < 0) {
brcmf_err("Setting toe_ol failed, %d\n", err);
return err;
}
err = brcmf_fil_iovar_int_set(ifp, "toe", (toe_ol != 0));
if (err < 0)
brcmf_err("Setting toe failed, %d\n", err);
return err;
}
static void brcmf_ethtool_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
snprintf(info->version, sizeof(info->version), "%lu",
drvr->drv_version);
strlcpy(info->bus_info, dev_name(drvr->bus_if->dev),
sizeof(info->bus_info));
}
static int brcmf_ethtool(struct brcmf_if *ifp, void __user *uaddr)
{
struct brcmf_pub *drvr = ifp->drvr;
struct ethtool_drvinfo info;
char drvname[sizeof(info.driver)];
u32 cmd;
struct ethtool_value edata;
u32 toe_cmpnt, csum_dir;
int ret;
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
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
strcpy(info.version, BRCMF_VERSION_STR);
}
else
sprintf(info.driver, "wl");
sprintf(info.version, "%lu", drvr->drv_version);
if (copy_to_user(uaddr, &info, sizeof(info)))
return -EFAULT;
brcmf_dbg(TRACE, "given %*s, returning %s\n",
(int)sizeof(drvname), drvname, info.driver);
break;
case ETHTOOL_GRXCSUM:
case ETHTOOL_GTXCSUM:
ret = brcmf_fil_iovar_int_get(ifp, "toe_ol", &toe_cmpnt);
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
ret = brcmf_fil_iovar_int_get(ifp, "toe_ol", &toe_cmpnt);
if (ret < 0)
return ret;
csum_dir =
(cmd == ETHTOOL_STXCSUM) ? TOE_TX_CSUM_OL : TOE_RX_CSUM_OL;
if (edata.data != 0)
toe_cmpnt |= csum_dir;
else
toe_cmpnt &= ~csum_dir;
ret = brcmf_toe_set(ifp, toe_cmpnt);
if (ret < 0)
return ret;
if (cmd == ETHTOOL_STXCSUM) {
if (edata.data)
ifp->ndev->features |= NETIF_F_IP_CSUM;
else
ifp->ndev->features &= ~NETIF_F_IP_CSUM;
}
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int brcmf_netdev_ioctl_entry(struct net_device *ndev, struct ifreq *ifr,
int cmd)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
brcmf_dbg(TRACE, "Enter, idx=%d, cmd=0x%04x\n", ifp->bssidx, cmd);
if (!drvr->iflist[ifp->bssidx])
return -1;
if (cmd == SIOCETHTOOL)
return brcmf_ethtool(ifp, ifr->ifr_data);
return -EOPNOTSUPP;
}
static int brcmf_netdev_stop(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
brcmf_cfg80211_down(ndev);
netif_stop_queue(ndev);
return 0;
}
static int brcmf_netdev_open(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
struct brcmf_bus *bus_if = drvr->bus_if;
u32 toe_ol;
s32 ret = 0;
brcmf_dbg(TRACE, "Enter, idx=%d\n", ifp->bssidx);
if (bus_if->state != BRCMF_BUS_DATA) {
brcmf_err("failed bus is not ready\n");
return -EAGAIN;
}
atomic_set(&ifp->pend_8021x_cnt, 0);
if (brcmf_fil_iovar_int_get(ifp, "toe_ol", &toe_ol) >= 0
&& (toe_ol & TOE_TX_CSUM_OL) != 0)
ndev->features |= NETIF_F_IP_CSUM;
else
ndev->features &= ~NETIF_F_IP_CSUM;
netif_start_queue(ndev);
if (brcmf_cfg80211_up(ndev)) {
brcmf_err("failed to bring up cfg80211\n");
return -1;
}
return ret;
}
int brcmf_net_attach(struct brcmf_if *ifp, bool rtnl_locked)
{
struct brcmf_pub *drvr = ifp->drvr;
struct net_device *ndev;
s32 err;
brcmf_dbg(TRACE, "Enter, idx=%d mac=%pM\n", ifp->bssidx,
ifp->mac_addr);
ndev = ifp->ndev;
ndev->netdev_ops = &brcmf_netdev_ops_pri;
ndev->hard_header_len = ETH_HLEN + drvr->hdrlen;
ndev->ethtool_ops = &brcmf_ethtool_ops;
drvr->rxsz = ndev->mtu + ndev->hard_header_len +
drvr->hdrlen;
memcpy(ndev->dev_addr, ifp->mac_addr, ETH_ALEN);
INIT_WORK(&ifp->setmacaddr_work, _brcmf_set_mac_address);
INIT_WORK(&ifp->multicast_work, _brcmf_set_multicast_list);
if (rtnl_locked)
err = register_netdevice(ndev);
else
err = register_netdev(ndev);
if (err != 0) {
brcmf_err("couldn't register the net device\n");
goto fail;
}
brcmf_dbg(INFO, "%s: Broadcom Dongle Host Driver\n", ndev->name);
return 0;
fail:
ndev->netdev_ops = NULL;
return -EBADE;
}
static int brcmf_net_p2p_open(struct net_device *ndev)
{
brcmf_dbg(TRACE, "Enter\n");
return brcmf_cfg80211_up(ndev);
}
static int brcmf_net_p2p_stop(struct net_device *ndev)
{
brcmf_dbg(TRACE, "Enter\n");
return brcmf_cfg80211_down(ndev);
}
static int brcmf_net_p2p_do_ioctl(struct net_device *ndev,
struct ifreq *ifr, int cmd)
{
brcmf_dbg(TRACE, "Enter\n");
return 0;
}
static netdev_tx_t brcmf_net_p2p_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
if (skb)
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
static int brcmf_net_p2p_attach(struct brcmf_if *ifp)
{
struct net_device *ndev;
brcmf_dbg(TRACE, "Enter, idx=%d mac=%pM\n", ifp->bssidx,
ifp->mac_addr);
ndev = ifp->ndev;
ndev->netdev_ops = &brcmf_netdev_ops_p2p;
memcpy(ndev->dev_addr, ifp->mac_addr, ETH_ALEN);
if (register_netdev(ndev) != 0) {
brcmf_err("couldn't register the p2p net device\n");
goto fail;
}
brcmf_dbg(INFO, "%s: Broadcom Dongle Host Driver\n", ndev->name);
return 0;
fail:
return -EBADE;
}
struct brcmf_if *brcmf_add_if(struct brcmf_pub *drvr, s32 bssidx, s32 ifidx,
char *name, u8 *mac_addr)
{
struct brcmf_if *ifp;
struct net_device *ndev;
brcmf_dbg(TRACE, "Enter, idx=%d, ifidx=%d\n", bssidx, ifidx);
ifp = drvr->iflist[bssidx];
if (ifp) {
brcmf_err("ERROR: netdev:%s already exists\n",
ifp->ndev->name);
if (ifidx) {
netif_stop_queue(ifp->ndev);
unregister_netdev(ifp->ndev);
free_netdev(ifp->ndev);
drvr->iflist[bssidx] = NULL;
} else {
brcmf_err("ignore IF event\n");
return ERR_PTR(-EINVAL);
}
}
ndev = alloc_netdev(sizeof(struct brcmf_if), name, ether_setup);
if (!ndev) {
brcmf_err("OOM - alloc_netdev\n");
return ERR_PTR(-ENOMEM);
}
ifp = netdev_priv(ndev);
ifp->ndev = ndev;
ifp->drvr = drvr;
drvr->iflist[bssidx] = ifp;
ifp->ifidx = ifidx;
ifp->bssidx = bssidx;
init_waitqueue_head(&ifp->pend_8021x_wait);
if (mac_addr != NULL)
memcpy(ifp->mac_addr, mac_addr, ETH_ALEN);
brcmf_dbg(TRACE, " ==== pid:%x, if:%s (%pM) created ===\n",
current->pid, ifp->ndev->name, ifp->mac_addr);
return ifp;
}
void brcmf_del_if(struct brcmf_pub *drvr, s32 bssidx)
{
struct brcmf_if *ifp;
ifp = drvr->iflist[bssidx];
if (!ifp) {
brcmf_err("Null interface, idx=%d\n", bssidx);
return;
}
brcmf_dbg(TRACE, "Enter, idx=%d, ifidx=%d\n", bssidx, ifp->ifidx);
if (ifp->ndev) {
if (bssidx == 0) {
if (ifp->ndev->netdev_ops == &brcmf_netdev_ops_pri) {
rtnl_lock();
brcmf_netdev_stop(ifp->ndev);
rtnl_unlock();
}
} else {
netif_stop_queue(ifp->ndev);
}
if (ifp->ndev->netdev_ops == &brcmf_netdev_ops_pri) {
cancel_work_sync(&ifp->setmacaddr_work);
cancel_work_sync(&ifp->multicast_work);
}
unregister_netdev(ifp->ndev);
drvr->iflist[bssidx] = NULL;
if (bssidx == 0)
brcmf_cfg80211_detach(drvr->config);
free_netdev(ifp->ndev);
}
}
int brcmf_attach(uint bus_hdrlen, struct device *dev)
{
struct brcmf_pub *drvr = NULL;
int ret = 0;
brcmf_dbg(TRACE, "Enter\n");
drvr = kzalloc(sizeof(struct brcmf_pub), GFP_ATOMIC);
if (!drvr)
return -ENOMEM;
mutex_init(&drvr->proto_block);
drvr->hdrlen = bus_hdrlen;
drvr->bus_if = dev_get_drvdata(dev);
drvr->bus_if->drvr = drvr;
brcmf_debugfs_attach(drvr);
ret = brcmf_proto_attach(drvr);
if (ret != 0) {
brcmf_err("brcmf_prot_attach failed\n");
goto fail;
}
brcmf_fweh_attach(drvr);
INIT_LIST_HEAD(&drvr->bus_if->dcmd_list);
return ret;
fail:
brcmf_detach(dev);
return ret;
}
int brcmf_bus_start(struct device *dev)
{
int ret = -1;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
struct brcmf_if *ifp;
struct brcmf_if *p2p_ifp;
brcmf_dbg(TRACE, "\n");
ret = brcmf_bus_init(bus_if);
if (ret != 0) {
brcmf_err("brcmf_sdbrcm_bus_init failed %d\n", ret);
return ret;
}
ifp = brcmf_add_if(drvr, 0, 0, "wlan%d", NULL);
if (IS_ERR(ifp))
return PTR_ERR(ifp);
if (brcmf_p2p_enable)
p2p_ifp = brcmf_add_if(drvr, 1, 0, "p2p%d", NULL);
else
p2p_ifp = NULL;
if (IS_ERR(p2p_ifp))
p2p_ifp = NULL;
bus_if->state = BRCMF_BUS_DATA;
ret = brcmf_c_preinit_dcmds(ifp);
if (ret < 0)
goto fail;
drvr->config = brcmf_cfg80211_attach(drvr, bus_if->dev);
if (drvr->config == NULL) {
ret = -ENOMEM;
goto fail;
}
ret = brcmf_fweh_activate_events(ifp);
if (ret < 0)
goto fail;
ret = brcmf_net_attach(ifp, false);
fail:
if (ret < 0) {
brcmf_err("failed: %d\n", ret);
if (drvr->config)
brcmf_cfg80211_detach(drvr->config);
free_netdev(ifp->ndev);
drvr->iflist[0] = NULL;
if (p2p_ifp) {
free_netdev(p2p_ifp->ndev);
drvr->iflist[1] = NULL;
}
return ret;
}
if ((brcmf_p2p_enable) && (p2p_ifp))
brcmf_net_p2p_attach(p2p_ifp);
return 0;
}
static void brcmf_bus_detach(struct brcmf_pub *drvr)
{
brcmf_dbg(TRACE, "Enter\n");
if (drvr) {
brcmf_proto_stop(drvr);
brcmf_bus_stop(drvr->bus_if);
}
}
void brcmf_dev_reset(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
if (drvr == NULL)
return;
if (drvr->iflist[0])
brcmf_fil_cmd_int_set(drvr->iflist[0], BRCMF_C_TERMINATED, 1);
}
void brcmf_detach(struct device *dev)
{
s32 i;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
brcmf_dbg(TRACE, "Enter\n");
if (drvr == NULL)
return;
brcmf_fweh_detach(drvr);
for (i = BRCMF_MAX_IFS-1; i > -1; i--)
if (drvr->iflist[i])
brcmf_del_if(drvr, i);
brcmf_bus_detach(drvr);
if (drvr->prot)
brcmf_proto_detach(drvr);
brcmf_debugfs_detach(drvr);
bus_if->drvr = NULL;
kfree(drvr);
}
static int brcmf_get_pend_8021x_cnt(struct brcmf_if *ifp)
{
return atomic_read(&ifp->pend_8021x_cnt);
}
int brcmf_netdev_wait_pend8021x(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
int err;
err = wait_event_timeout(ifp->pend_8021x_wait,
!brcmf_get_pend_8021x_cnt(ifp),
msecs_to_jiffies(MAX_WAIT_FOR_8021X_TX));
WARN_ON(!err);
return !err;
}
u32 brcmf_get_chip_info(struct brcmf_if *ifp)
{
struct brcmf_bus *bus = ifp->drvr->bus_if;
return bus->chip << 4 | bus->chiprev;
}
static void brcmf_driver_init(struct work_struct *work)
{
brcmf_debugfs_init();
#ifdef CONFIG_BRCMFMAC_SDIO
brcmf_sdio_init();
#endif
#ifdef CONFIG_BRCMFMAC_USB
brcmf_usb_init();
#endif
}
static int __init brcmfmac_module_init(void)
{
if (!schedule_work(&brcmf_driver_work))
return -EBUSY;
return 0;
}
static void __exit brcmfmac_module_exit(void)
{
cancel_work_sync(&brcmf_driver_work);
#ifdef CONFIG_BRCMFMAC_SDIO
brcmf_sdio_exit();
#endif
#ifdef CONFIG_BRCMFMAC_USB
brcmf_usb_exit();
#endif
brcmf_debugfs_exit();
}
