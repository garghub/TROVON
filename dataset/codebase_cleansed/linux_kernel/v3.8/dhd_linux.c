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
brcmf_dbg(TRACE, "enter\n");
ifp = container_of(work, struct brcmf_if, multicast_work);
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
brcmf_dbg(TRACE, "enter\n");
ifp = container_of(work, struct brcmf_if, setmacaddr_work);
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
static int brcmf_netdev_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
int ret;
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
brcmf_dbg(TRACE, "Enter\n");
if (!drvr->bus_if->drvr_up ||
(drvr->bus_if->state != BRCMF_BUS_DATA)) {
brcmf_err("xmit rejected drvup=%d state=%d\n",
drvr->bus_if->drvr_up,
drvr->bus_if->state);
netif_stop_queue(ndev);
return -ENODEV;
}
if (!drvr->iflist[ifp->idx]) {
brcmf_err("bad ifidx %d\n", ifp->idx);
netif_stop_queue(ndev);
return -ENODEV;
}
if (skb_headroom(skb) < drvr->hdrlen) {
struct sk_buff *skb2;
brcmf_dbg(INFO, "%s: insufficient headroom\n",
brcmf_ifname(drvr, ifp->idx));
drvr->bus_if->tx_realloc++;
skb2 = skb_realloc_headroom(skb, drvr->hdrlen);
dev_kfree_skb(skb);
skb = skb2;
if (skb == NULL) {
brcmf_err("%s: skb_realloc_headroom failed\n",
brcmf_ifname(drvr, ifp->idx));
ret = -ENOMEM;
goto done;
}
}
if (skb->len >= ETH_ALEN) {
u8 *pktdata = (u8 *)(skb->data);
struct ethhdr *eh = (struct ethhdr *)pktdata;
if (is_multicast_ether_addr(eh->h_dest))
drvr->tx_multicast++;
if (ntohs(eh->h_proto) == ETH_P_PAE)
atomic_inc(&drvr->pend_8021x_cnt);
}
brcmf_proto_hdrpush(drvr, ifp->idx, skb);
ret = brcmf_bus_txdata(drvr->bus_if, skb);
done:
if (ret)
drvr->bus_if->dstats.tx_dropped++;
else
drvr->bus_if->dstats.tx_packets++;
return 0;
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
void brcmf_rx_frame(struct device *dev, u8 ifidx,
struct sk_buff_head *skb_list)
{
unsigned char *eth;
uint len;
struct sk_buff *skb, *pnext;
struct brcmf_if *ifp;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
brcmf_dbg(TRACE, "Enter\n");
skb_queue_walk_safe(skb_list, skb, pnext) {
skb_unlink(skb, skb_list);
eth = skb->data;
len = skb->len;
ifp = drvr->iflist[ifidx];
if (ifp == NULL)
ifp = drvr->iflist[0];
if (!ifp || !ifp->ndev ||
ifp->ndev->reg_state != NETREG_REGISTERED) {
brcmu_pkt_buf_free_skb(skb);
continue;
}
skb->dev = ifp->ndev;
skb->protocol = eth_type_trans(skb, skb->dev);
if (skb->pkt_type == PACKET_MULTICAST)
bus_if->dstats.multicast++;
skb->data = eth;
skb->len = len;
skb_pull(skb, ETH_HLEN);
brcmf_fweh_process_skb(drvr, skb, &ifidx);
if (drvr->iflist[ifidx]) {
ifp = drvr->iflist[ifidx];
ifp->ndev->last_rx = jiffies;
}
bus_if->dstats.rx_bytes += skb->len;
bus_if->dstats.rx_packets++;
if (in_interrupt())
netif_rx(skb);
else
netif_rx_ni(skb);
}
}
void brcmf_txcomplete(struct device *dev, struct sk_buff *txp, bool success)
{
uint ifidx;
struct ethhdr *eh;
u16 type;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
brcmf_proto_hdrpull(dev, &ifidx, txp);
eh = (struct ethhdr *)(txp->data);
type = ntohs(eh->h_proto);
if (type == ETH_P_PAE) {
atomic_dec(&drvr->pend_8021x_cnt);
if (waitqueue_active(&drvr->pend_8021x_wait))
wake_up(&drvr->pend_8021x_wait);
}
}
static struct net_device_stats *brcmf_netdev_get_stats(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_bus *bus_if = ifp->drvr->bus_if;
brcmf_dbg(TRACE, "Enter\n");
ifp->stats.rx_packets = bus_if->dstats.rx_packets;
ifp->stats.tx_packets = bus_if->dstats.tx_packets;
ifp->stats.rx_bytes = bus_if->dstats.rx_bytes;
ifp->stats.tx_bytes = bus_if->dstats.tx_bytes;
ifp->stats.rx_errors = bus_if->dstats.rx_errors;
ifp->stats.tx_errors = bus_if->dstats.tx_errors;
ifp->stats.rx_dropped = bus_if->dstats.rx_dropped;
ifp->stats.tx_dropped = bus_if->dstats.tx_dropped;
ifp->stats.multicast = bus_if->dstats.multicast;
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
sprintf(info->driver, KBUILD_MODNAME);
sprintf(info->version, "%lu", drvr->drv_version);
sprintf(info->bus_info, "%s", dev_name(drvr->bus_if->dev));
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
brcmf_dbg(TRACE, "Enter\n");
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
else if (!drvr->bus_if->drvr_up) {
brcmf_err("dongle is not up\n");
return -ENODEV;
}
else
sprintf(info.driver, "wl");
sprintf(info.version, "%lu", drvr->drv_version);
if (copy_to_user(uaddr, &info, sizeof(info)))
return -EFAULT;
brcmf_dbg(CTL, "given %*s, returning %s\n",
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
brcmf_dbg(TRACE, "ifidx %d, cmd 0x%04x\n", ifp->idx, cmd);
if (!drvr->iflist[ifp->idx])
return -1;
if (cmd == SIOCETHTOOL)
return brcmf_ethtool(ifp, ifr->ifr_data);
return -EOPNOTSUPP;
}
static int brcmf_netdev_stop(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
brcmf_dbg(TRACE, "Enter\n");
if (drvr->bus_if->drvr_up == 0)
return 0;
brcmf_cfg80211_down(ndev);
drvr->bus_if->drvr_up = false;
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
brcmf_dbg(TRACE, "ifidx %d\n", ifp->idx);
if (bus_if->state != BRCMF_BUS_DATA) {
brcmf_err("failed bus is not ready\n");
return -EAGAIN;
}
atomic_set(&drvr->pend_8021x_cnt, 0);
memcpy(ndev->dev_addr, drvr->mac, ETH_ALEN);
if (brcmf_fil_iovar_int_get(ifp, "toe_ol", &toe_ol) >= 0
&& (toe_ol & TOE_TX_CSUM_OL) != 0)
drvr->iflist[ifp->idx]->ndev->features |=
NETIF_F_IP_CSUM;
else
drvr->iflist[ifp->idx]->ndev->features &=
~NETIF_F_IP_CSUM;
brcmf_fil_cmd_int_set(ifp, BRCMF_C_UP, 0);
netif_start_queue(ndev);
drvr->bus_if->drvr_up = true;
if (brcmf_cfg80211_up(ndev)) {
brcmf_err("failed to bring up cfg80211\n");
return -1;
}
return ret;
}
int brcmf_net_attach(struct brcmf_if *ifp)
{
struct brcmf_pub *drvr = ifp->drvr;
struct net_device *ndev;
brcmf_dbg(TRACE, "ifidx %d mac %pM\n", ifp->idx, ifp->mac_addr);
ndev = ifp->ndev;
if (!ifp->idx)
ndev->netdev_ops = &brcmf_netdev_ops_pri;
else
ndev->netdev_ops = &brcmf_netdev_ops_virt;
ndev->hard_header_len = ETH_HLEN + drvr->hdrlen;
ndev->ethtool_ops = &brcmf_ethtool_ops;
drvr->rxsz = ndev->mtu + ndev->hard_header_len +
drvr->hdrlen;
memcpy(ndev->dev_addr, ifp->mac_addr, ETH_ALEN);
if (register_netdev(ndev) != 0) {
brcmf_err("couldn't register the net device\n");
goto fail;
}
brcmf_dbg(INFO, "%s: Broadcom Dongle Host Driver\n", ndev->name);
return 0;
fail:
ndev->netdev_ops = NULL;
return -EBADE;
}
struct brcmf_if *brcmf_add_if(struct brcmf_pub *drvr, int ifidx, s32 bssidx,
char *name, u8 *addr_mask)
{
struct brcmf_if *ifp;
struct net_device *ndev;
int i;
brcmf_dbg(TRACE, "idx %d\n", ifidx);
ifp = drvr->iflist[ifidx];
if (ifp) {
brcmf_err("ERROR: netdev:%s already exists\n",
ifp->ndev->name);
if (ifidx) {
netif_stop_queue(ifp->ndev);
unregister_netdev(ifp->ndev);
free_netdev(ifp->ndev);
drvr->iflist[ifidx] = NULL;
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
drvr->iflist[ifidx] = ifp;
ifp->idx = ifidx;
ifp->bssidx = bssidx;
INIT_WORK(&ifp->setmacaddr_work, _brcmf_set_mac_address);
INIT_WORK(&ifp->multicast_work, _brcmf_set_multicast_list);
if (addr_mask != NULL)
for (i = 0; i < ETH_ALEN; i++)
ifp->mac_addr[i] = drvr->mac[i] ^ addr_mask[i];
brcmf_dbg(TRACE, " ==== pid:%x, if:%s (%pM) created ===\n",
current->pid, ifp->ndev->name, ifp->mac_addr);
return ifp;
}
void brcmf_del_if(struct brcmf_pub *drvr, int ifidx)
{
struct brcmf_if *ifp;
brcmf_dbg(TRACE, "idx %d\n", ifidx);
ifp = drvr->iflist[ifidx];
if (!ifp) {
brcmf_err("Null interface\n");
return;
}
if (ifp->ndev) {
if (ifidx == 0) {
if (ifp->ndev->netdev_ops == &brcmf_netdev_ops_pri) {
rtnl_lock();
brcmf_netdev_stop(ifp->ndev);
rtnl_unlock();
}
} else {
netif_stop_queue(ifp->ndev);
}
cancel_work_sync(&ifp->setmacaddr_work);
cancel_work_sync(&ifp->multicast_work);
unregister_netdev(ifp->ndev);
drvr->iflist[ifidx] = NULL;
if (ifidx == 0)
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
init_waitqueue_head(&drvr->pend_8021x_wait);
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
brcmf_dbg(TRACE, "\n");
ret = brcmf_bus_init(bus_if);
if (ret != 0) {
brcmf_err("brcmf_sdbrcm_bus_init failed %d\n", ret);
return ret;
}
ifp = brcmf_add_if(drvr, 0, 0, "wlan%d", NULL);
if (IS_ERR(ifp))
return PTR_ERR(ifp);
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
ret = brcmf_net_attach(ifp);
fail:
if (ret < 0) {
brcmf_err("failed: %d\n", ret);
if (drvr->config)
brcmf_cfg80211_detach(drvr->config);
free_netdev(drvr->iflist[0]->ndev);
drvr->iflist[0] = NULL;
return ret;
}
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
void brcmf_detach(struct device *dev)
{
int i;
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
if (drvr->prot) {
brcmf_proto_detach(drvr);
}
brcmf_debugfs_detach(drvr);
bus_if->drvr = NULL;
kfree(drvr);
}
static int brcmf_get_pend_8021x_cnt(struct brcmf_pub *drvr)
{
return atomic_read(&drvr->pend_8021x_cnt);
}
int brcmf_netdev_wait_pend8021x(struct net_device *ndev)
{
struct brcmf_if *ifp = netdev_priv(ndev);
struct brcmf_pub *drvr = ifp->drvr;
int err;
err = wait_event_timeout(drvr->pend_8021x_wait,
!brcmf_get_pend_8021x_cnt(drvr),
msecs_to_jiffies(MAX_WAIT_FOR_8021X_TX));
WARN_ON(!err);
return !err;
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
