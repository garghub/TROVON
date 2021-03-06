static int ray_probe(struct pcmcia_device *p_dev)
{
ray_dev_t *local;
struct net_device *dev;
dev_dbg(&p_dev->dev, "ray_attach()\n");
dev = alloc_etherdev(sizeof(ray_dev_t));
if (!dev)
goto fail_alloc_dev;
local = netdev_priv(dev);
local->finder = p_dev;
p_dev->resource[0]->end = 0;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->config_flags |= CONF_ENABLE_IRQ;
p_dev->config_index = 1;
p_dev->priv = dev;
local->finder = p_dev;
local->card_status = CARD_INSERTED;
local->authentication_state = UNAUTHENTICATED;
local->num_multi = 0;
dev_dbg(&p_dev->dev, "ray_attach p_dev = %p, dev = %p, local = %p, intr = %p\n",
p_dev, dev, local, &ray_interrupt);
dev->netdev_ops = &ray_netdev_ops;
dev->wireless_handlers = &ray_handler_def;
#ifdef WIRELESS_SPY
local->wireless_data.spy_data = &local->spy_data;
dev->wireless_data = &local->wireless_data;
#endif
dev_dbg(&p_dev->dev, "ray_cs ray_attach calling ether_setup.)\n");
netif_stop_queue(dev);
init_timer(&local->timer);
this_device = p_dev;
return ray_config(p_dev);
fail_alloc_dev:
return -ENOMEM;
}
static void ray_detach(struct pcmcia_device *link)
{
struct net_device *dev;
ray_dev_t *local;
dev_dbg(&link->dev, "ray_detach\n");
this_device = NULL;
dev = link->priv;
ray_release(link);
local = netdev_priv(dev);
del_timer(&local->timer);
if (link->priv) {
unregister_netdev(dev);
free_netdev(dev);
}
dev_dbg(&link->dev, "ray_cs ray_detach ending\n");
}
static int ray_config(struct pcmcia_device *link)
{
int ret = 0;
int i;
struct net_device *dev = (struct net_device *)link->priv;
ray_dev_t *local = netdev_priv(dev);
dev_dbg(&link->dev, "ray_config\n");
printk(KERN_INFO "ray_cs Detected: %s%s%s%s\n",
link->prod_id[0] ? link->prod_id[0] : " ",
link->prod_id[1] ? link->prod_id[1] : " ",
link->prod_id[2] ? link->prod_id[2] : " ",
link->prod_id[3] ? link->prod_id[3] : " ");
ret = pcmcia_request_irq(link, ray_interrupt);
if (ret)
goto failed;
dev->irq = link->irq;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
link->resource[2]->flags |= WIN_DATA_WIDTH_8 | WIN_MEMORY_TYPE_CM | WIN_ENABLE | WIN_USE_WAIT;
link->resource[2]->start = 0;
link->resource[2]->end = 0x8000;
ret = pcmcia_request_window(link, link->resource[2], ray_mem_speed);
if (ret)
goto failed;
ret = pcmcia_map_mem_page(link, link->resource[2], 0);
if (ret)
goto failed;
local->sram = ioremap(link->resource[2]->start,
resource_size(link->resource[2]));
link->resource[3]->flags |=
WIN_DATA_WIDTH_8 | WIN_MEMORY_TYPE_CM | WIN_ENABLE | WIN_USE_WAIT;
link->resource[3]->start = 0;
link->resource[3]->end = 0x4000;
ret = pcmcia_request_window(link, link->resource[3], ray_mem_speed);
if (ret)
goto failed;
ret = pcmcia_map_mem_page(link, link->resource[3], 0x8000);
if (ret)
goto failed;
local->rmem = ioremap(link->resource[3]->start,
resource_size(link->resource[3]));
link->resource[4]->flags |=
WIN_DATA_WIDTH_8 | WIN_MEMORY_TYPE_AM | WIN_ENABLE | WIN_USE_WAIT;
link->resource[4]->start = 0;
link->resource[4]->end = 0x1000;
ret = pcmcia_request_window(link, link->resource[4], ray_mem_speed);
if (ret)
goto failed;
ret = pcmcia_map_mem_page(link, link->resource[4], 0);
if (ret)
goto failed;
local->amem = ioremap(link->resource[4]->start,
resource_size(link->resource[4]));
dev_dbg(&link->dev, "ray_config sram=%p\n", local->sram);
dev_dbg(&link->dev, "ray_config rmem=%p\n", local->rmem);
dev_dbg(&link->dev, "ray_config amem=%p\n", local->amem);
if (ray_init(dev) < 0) {
ray_release(link);
return -ENODEV;
}
SET_NETDEV_DEV(dev, &link->dev);
i = register_netdev(dev);
if (i != 0) {
printk("ray_config register_netdev() failed\n");
ray_release(link);
return i;
}
printk(KERN_INFO "%s: RayLink, irq %d, hw_addr %pM\n",
dev->name, dev->irq, dev->dev_addr);
return 0;
failed:
ray_release(link);
return -ENODEV;
}
static inline struct ccs __iomem *ccs_base(ray_dev_t *dev)
{
return dev->sram + CCS_BASE;
}
static inline struct rcs __iomem *rcs_base(ray_dev_t *dev)
{
return dev->sram + CCS_BASE;
}
static int ray_init(struct net_device *dev)
{
int i;
UCHAR *p;
struct ccs __iomem *pccs;
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
dev_dbg(&link->dev, "ray_init(0x%p)\n", dev);
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_init - device not present\n");
return -1;
}
local->net_type = net_type;
local->sta_type = TYPE_STA;
memcpy_fromio(&local->startup_res, local->sram + ECF_TO_HOST_BASE,
sizeof(struct startup_res_6));
if (local->startup_res.startup_word != 0x80) {
printk(KERN_INFO "ray_init ERROR card status = %2x\n",
local->startup_res.startup_word);
local->card_status = CARD_INIT_ERROR;
return -1;
}
local->fw_ver = local->startup_res.firmware_version[0];
local->fw_bld = local->startup_res.firmware_version[1];
local->fw_var = local->startup_res.firmware_version[2];
dev_dbg(&link->dev, "ray_init firmware version %d.%d\n", local->fw_ver,
local->fw_bld);
local->tib_length = 0x20;
if ((local->fw_ver == 5) && (local->fw_bld >= 30))
local->tib_length = local->startup_res.tib_length;
dev_dbg(&link->dev, "ray_init tib_length = 0x%02x\n", local->tib_length);
pccs = ccs_base(local);
for (i = 0; i < NUMBER_OF_CCS; i++) {
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
}
init_startup_params(local);
if (parse_addr(phy_addr, local->sparm.b4.a_mac_addr)) {
p = local->sparm.b4.a_mac_addr;
} else {
memcpy(&local->sparm.b4.a_mac_addr,
&local->startup_res.station_addr, ADDRLEN);
p = local->sparm.b4.a_mac_addr;
}
clear_interrupt(local);
local->card_status = CARD_AWAITING_PARAM;
dev_dbg(&link->dev, "ray_init ending\n");
return 0;
}
static int dl_startup_params(struct net_device *dev)
{
int ccsindex;
ray_dev_t *local = netdev_priv(dev);
struct ccs __iomem *pccs;
struct pcmcia_device *link = local->finder;
dev_dbg(&link->dev, "dl_startup_params entered\n");
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs dl_startup_params - device not present\n");
return -1;
}
if (local->fw_ver == 0x55)
memcpy_toio(local->sram + HOST_TO_ECF_BASE, &local->sparm.b4,
sizeof(struct b4_startup_params));
else
memcpy_toio(local->sram + HOST_TO_ECF_BASE, &local->sparm.b5,
sizeof(struct b5_startup_params));
if ((ccsindex = get_free_ccs(local)) < 0)
return -1;
local->dl_param_ccs = ccsindex;
pccs = ccs_base(local) + ccsindex;
writeb(CCS_DOWNLOAD_STARTUP_PARAMS, &pccs->cmd);
dev_dbg(&link->dev, "dl_startup_params start ccsindex = %d\n",
local->dl_param_ccs);
if (interrupt_ecf(local, ccsindex)) {
printk(KERN_INFO "ray dl_startup_params failed - "
"ECF not ready for intr\n");
local->card_status = CARD_DL_PARAM_ERROR;
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
return -2;
}
local->card_status = CARD_DL_PARAM;
local->timer.expires = jiffies + HZ / 2;
local->timer.data = (long)local;
local->timer.function = verify_dl_startup;
add_timer(&local->timer);
dev_dbg(&link->dev,
"ray_cs dl_startup_params started timer for verify_dl_startup\n");
return 0;
}
static void init_startup_params(ray_dev_t *local)
{
int i;
if (country > JAPAN_TEST)
country = USA;
else if (country < USA)
country = USA;
if (local->fw_ver == 0x55) {
memcpy((UCHAR *) &local->sparm.b4, b4_default_startup_parms,
sizeof(struct b4_startup_params));
i = (hop_dwell * 1024) & 0xffffff;
local->sparm.b4.a_hop_time[0] = (i >> 16) & 0xff;
local->sparm.b4.a_hop_time[1] = (i >> 8) & 0xff;
local->sparm.b4.a_beacon_period[0] = 0;
local->sparm.b4.a_beacon_period[1] =
((beacon_period / hop_dwell) - 1) & 0xff;
local->sparm.b4.a_curr_country_code = country;
local->sparm.b4.a_hop_pattern_length =
hop_pattern_length[(int)country] - 1;
if (bc) {
local->sparm.b4.a_ack_timeout = 0x50;
local->sparm.b4.a_sifs = 0x3f;
}
} else {
memcpy((UCHAR *) &local->sparm.b5, b5_default_startup_parms,
sizeof(struct b5_startup_params));
local->sparm.b5.a_hop_time[0] = (hop_dwell >> 8) & 0xff;
local->sparm.b5.a_hop_time[1] = hop_dwell & 0xff;
local->sparm.b5.a_beacon_period[0] =
(beacon_period >> 8) & 0xff;
local->sparm.b5.a_beacon_period[1] = beacon_period & 0xff;
if (psm)
local->sparm.b5.a_power_mgt_state = 1;
local->sparm.b5.a_curr_country_code = country;
local->sparm.b5.a_hop_pattern_length =
hop_pattern_length[(int)country];
}
local->sparm.b4.a_network_type = net_type & 0x01;
local->sparm.b4.a_acting_as_ap_status = TYPE_STA;
if (essid != NULL)
strncpy(local->sparm.b4.a_current_ess_id, essid, ESSID_SIZE);
}
static void verify_dl_startup(u_long data)
{
ray_dev_t *local = (ray_dev_t *) data;
struct ccs __iomem *pccs = ccs_base(local) + local->dl_param_ccs;
UCHAR status;
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs verify_dl_startup - device not present\n");
return;
}
#if 0
{
int i;
printk(KERN_DEBUG
"verify_dl_startup parameters sent via ccs %d:\n",
local->dl_param_ccs);
for (i = 0; i < sizeof(struct b5_startup_params); i++) {
printk(" %2x",
(unsigned int)readb(local->sram +
HOST_TO_ECF_BASE + i));
}
printk("\n");
}
#endif
status = readb(&pccs->buffer_status);
if (status != CCS_BUFFER_FREE) {
printk(KERN_INFO
"Download startup params failed. Status = %d\n",
status);
local->card_status = CARD_DL_PARAM_ERROR;
return;
}
if (local->sparm.b4.a_network_type == ADHOC)
start_net((u_long) local);
else
join_net((u_long) local);
}
static void start_net(u_long data)
{
ray_dev_t *local = (ray_dev_t *) data;
struct ccs __iomem *pccs;
int ccsindex;
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs start_net - device not present\n");
return;
}
if ((ccsindex = get_free_ccs(local)) < 0)
return;
pccs = ccs_base(local) + ccsindex;
writeb(CCS_START_NETWORK, &pccs->cmd);
writeb(0, &pccs->var.start_network.update_param);
if (interrupt_ecf(local, ccsindex)) {
dev_dbg(&link->dev, "ray start net failed - card not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
return;
}
local->card_status = CARD_DOING_ACQ;
}
static void join_net(u_long data)
{
ray_dev_t *local = (ray_dev_t *) data;
struct ccs __iomem *pccs;
int ccsindex;
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs join_net - device not present\n");
return;
}
if ((ccsindex = get_free_ccs(local)) < 0)
return;
pccs = ccs_base(local) + ccsindex;
writeb(CCS_JOIN_NETWORK, &pccs->cmd);
writeb(0, &pccs->var.join_network.update_param);
writeb(0, &pccs->var.join_network.net_initiated);
if (interrupt_ecf(local, ccsindex)) {
dev_dbg(&link->dev, "ray join net failed - card not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
return;
}
local->card_status = CARD_DOING_ACQ;
}
static void ray_release(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
ray_dev_t *local = netdev_priv(dev);
dev_dbg(&link->dev, "ray_release\n");
del_timer(&local->timer);
iounmap(local->sram);
iounmap(local->rmem);
iounmap(local->amem);
pcmcia_disable_device(link);
dev_dbg(&link->dev, "ray_release ending\n");
}
static int ray_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int ray_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
ray_reset(dev);
netif_device_attach(dev);
}
return 0;
}
static int ray_dev_init(struct net_device *dev)
{
#ifdef RAY_IMMEDIATE_INIT
int i;
#endif
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
dev_dbg(&link->dev, "ray_dev_init(dev=%p)\n", dev);
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_dev_init - device not present\n");
return -1;
}
#ifdef RAY_IMMEDIATE_INIT
if ((i = dl_startup_params(dev)) < 0) {
printk(KERN_INFO "ray_dev_init dl_startup_params failed - "
"returns 0x%x\n", i);
return -1;
}
#else
dev_dbg(&link->dev,
"ray_dev_init: postponing card init to ray_open() ; Status = %d\n",
local->card_status);
#endif
memcpy(dev->dev_addr, &local->sparm.b4.a_mac_addr, ADDRLEN);
memset(dev->broadcast, 0xff, ETH_ALEN);
dev_dbg(&link->dev, "ray_dev_init ending\n");
return 0;
}
static int ray_dev_config(struct net_device *dev, struct ifmap *map)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
dev_dbg(&link->dev, "ray_dev_config(dev=%p,ifmap=%p)\n", dev, map);
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_dev_config - device not present\n");
return -1;
}
return 0;
}
static netdev_tx_t ray_dev_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
short length = skb->len;
if (!pcmcia_dev_present(link)) {
dev_dbg(&link->dev, "ray_dev_start_xmit - device not present\n");
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
dev_dbg(&link->dev, "ray_dev_start_xmit(skb=%p, dev=%p)\n", skb, dev);
if (local->authentication_state == NEED_TO_AUTH) {
dev_dbg(&link->dev, "ray_cs Sending authentication request.\n");
if (!build_auth_frame(local, local->auth_id, OPEN_AUTH_REQUEST)) {
local->authentication_state = AUTHENTICATED;
netif_stop_queue(dev);
return NETDEV_TX_BUSY;
}
}
if (length < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
switch (ray_hw_xmit(skb->data, length, dev, DATA_TYPE)) {
case XMIT_NO_CCS:
case XMIT_NEED_AUTH:
netif_stop_queue(dev);
return NETDEV_TX_BUSY;
case XMIT_NO_INTR:
case XMIT_MSG_BAD:
case XMIT_OK:
default:
dev_kfree_skb(skb);
}
return NETDEV_TX_OK;
}
static int ray_hw_xmit(unsigned char *data, int len, struct net_device *dev,
UCHAR msg_type)
{
ray_dev_t *local = netdev_priv(dev);
struct ccs __iomem *pccs;
int ccsindex;
int offset;
struct tx_msg __iomem *ptx;
short int addr;
pr_debug("ray_hw_xmit(data=%p, len=%d, dev=%p)\n", data, len, dev);
if (len + TX_HEADER_LENGTH > TX_BUF_SIZE) {
printk(KERN_INFO "ray_hw_xmit packet too large: %d bytes\n",
len);
return XMIT_MSG_BAD;
}
switch (ccsindex = get_free_tx_ccs(local)) {
case ECCSBUSY:
pr_debug("ray_hw_xmit tx_ccs table busy\n");
case ECCSFULL:
pr_debug("ray_hw_xmit No free tx ccs\n");
case ECARDGONE:
netif_stop_queue(dev);
return XMIT_NO_CCS;
default:
break;
}
addr = TX_BUF_BASE + (ccsindex << 11);
if (msg_type == DATA_TYPE) {
local->stats.tx_bytes += len;
local->stats.tx_packets++;
}
ptx = local->sram + addr;
ray_build_header(local, ptx, msg_type, data);
if (translate) {
offset = translate_frame(local, ptx, data, len);
} else {
memcpy_toio(&ptx->var, data, len);
offset = 0;
}
pccs = ccs_base(local) + ccsindex;
len += TX_HEADER_LENGTH + offset;
writeb(CCS_TX_REQUEST, &pccs->cmd);
writeb(addr >> 8, &pccs->var.tx_request.tx_data_ptr[0]);
writeb(local->tib_length, &pccs->var.tx_request.tx_data_ptr[1]);
writeb(len >> 8, &pccs->var.tx_request.tx_data_length[0]);
writeb(len & 0xff, &pccs->var.tx_request.tx_data_length[1]);
writeb(PSM_CAM, &pccs->var.tx_request.pow_sav_mode);
writeb(local->net_default_tx_rate, &pccs->var.tx_request.tx_rate);
writeb(0, &pccs->var.tx_request.antenna);
pr_debug("ray_hw_xmit default_tx_rate = 0x%x\n",
local->net_default_tx_rate);
if (interrupt_ecf(local, ccsindex)) {
pr_debug("ray_hw_xmit failed - ECF not ready for intr\n");
writeb(CCS_BUFFER_FREE, &pccs->buffer_status);
return XMIT_NO_INTR;
}
return XMIT_OK;
}
static int translate_frame(ray_dev_t *local, struct tx_msg __iomem *ptx,
unsigned char *data, int len)
{
__be16 proto = ((struct ethhdr *)data)->h_proto;
if (ntohs(proto) >= 1536) {
pr_debug("ray_cs translate_frame DIX II\n");
memcpy_toio(&ptx->var, eth2_llc, sizeof(eth2_llc));
memcpy_toio(((void __iomem *)&ptx->var) + sizeof(eth2_llc),
(UCHAR *) &proto, 2);
if (proto == htons(ETH_P_AARP) || proto == htons(ETH_P_IPX)) {
writeb(0xf8,
&((struct snaphdr_t __iomem *)ptx->var)->org[3]);
}
memcpy_toio((void __iomem *)&ptx->var +
sizeof(struct snaphdr_t), data + ETH_HLEN,
len - ETH_HLEN);
return (int)sizeof(struct snaphdr_t) - ETH_HLEN;
} else {
pr_debug("ray_cs translate_frame 802\n");
if (proto == htons(0xffff)) {
pr_debug("ray_cs translate_frame evil IPX\n");
memcpy_toio(&ptx->var, data + ETH_HLEN, len - ETH_HLEN);
return 0 - ETH_HLEN;
}
memcpy_toio(&ptx->var, data + ETH_HLEN, len - ETH_HLEN);
return 0 - ETH_HLEN;
}
}
static void ray_build_header(ray_dev_t *local, struct tx_msg __iomem *ptx,
UCHAR msg_type, unsigned char *data)
{
writeb(PROTOCOL_VER | msg_type, &ptx->mac.frame_ctl_1);
if (local->net_type == ADHOC) {
writeb(0, &ptx->mac.frame_ctl_2);
memcpy_toio(ptx->mac.addr_1, ((struct ethhdr *)data)->h_dest,
2 * ADDRLEN);
memcpy_toio(ptx->mac.addr_3, local->bss_id, ADDRLEN);
} else {
if (local->sparm.b4.a_acting_as_ap_status) {
writeb(FC2_FROM_DS, &ptx->mac.frame_ctl_2);
memcpy_toio(ptx->mac.addr_1,
((struct ethhdr *)data)->h_dest, ADDRLEN);
memcpy_toio(ptx->mac.addr_2, local->bss_id, 6);
memcpy_toio(ptx->mac.addr_3,
((struct ethhdr *)data)->h_source, ADDRLEN);
} else {
writeb(FC2_TO_DS, &ptx->mac.frame_ctl_2);
memcpy_toio(ptx->mac.addr_1, local->bss_id, ADDRLEN);
memcpy_toio(ptx->mac.addr_2,
((struct ethhdr *)data)->h_source, ADDRLEN);
memcpy_toio(ptx->mac.addr_3,
((struct ethhdr *)data)->h_dest, ADDRLEN);
}
}
}
static int ray_get_name(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
strcpy(wrqu->name, "IEEE 802.11-FH");
return 0;
}
static int ray_set_freq(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
int err = -EINPROGRESS;
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
if ((wrqu->freq.m > USA_HOP_MOD) || (wrqu->freq.e > 0))
err = -EOPNOTSUPP;
else
local->sparm.b5.a_hop_pattern = wrqu->freq.m;
return err;
}
static int ray_get_freq(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
wrqu->freq.m = local->sparm.b5.a_hop_pattern;
wrqu->freq.e = 0;
return 0;
}
static int ray_set_essid(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
if (wrqu->essid.flags == 0)
return -EOPNOTSUPP;
if (wrqu->essid.length > IW_ESSID_MAX_SIZE)
return -E2BIG;
memset(local->sparm.b5.a_current_ess_id, 0, IW_ESSID_MAX_SIZE);
memcpy(local->sparm.b5.a_current_ess_id, extra, wrqu->essid.length);
return -EINPROGRESS;
}
static int ray_get_essid(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
memcpy(extra, local->sparm.b5.a_current_ess_id, IW_ESSID_MAX_SIZE);
wrqu->essid.length = strlen(extra);
wrqu->essid.flags = 1;
return 0;
}
static int ray_get_wap(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
memcpy(wrqu->ap_addr.sa_data, local->bss_id, ETH_ALEN);
wrqu->ap_addr.sa_family = ARPHRD_ETHER;
return 0;
}
static int ray_set_rate(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
if ((wrqu->bitrate.value != 1000000) && (wrqu->bitrate.value != 2000000))
return -EINVAL;
if ((local->fw_ver == 0x55) &&
(wrqu->bitrate.value == 2000000))
local->net_default_tx_rate = 3;
else
local->net_default_tx_rate = wrqu->bitrate.value / 500000;
return 0;
}
static int ray_get_rate(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
if (local->net_default_tx_rate == 3)
wrqu->bitrate.value = 2000000;
else
wrqu->bitrate.value = local->net_default_tx_rate * 500000;
wrqu->bitrate.fixed = 0;
return 0;
}
static int ray_set_rts(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
int rthr = wrqu->rts.value;
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
if (wrqu->rts.disabled)
rthr = 32767;
else {
if ((rthr < 0) || (rthr > 2347))
return -EINVAL;
}
local->sparm.b5.a_rts_threshold[0] = (rthr >> 8) & 0xFF;
local->sparm.b5.a_rts_threshold[1] = rthr & 0xFF;
return -EINPROGRESS;
}
static int ray_get_rts(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
wrqu->rts.value = (local->sparm.b5.a_rts_threshold[0] << 8)
+ local->sparm.b5.a_rts_threshold[1];
wrqu->rts.disabled = (wrqu->rts.value == 32767);
wrqu->rts.fixed = 1;
return 0;
}
static int ray_set_frag(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
int fthr = wrqu->frag.value;
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
if (wrqu->frag.disabled)
fthr = 32767;
else {
if ((fthr < 256) || (fthr > 2347))
return -EINVAL;
}
local->sparm.b5.a_frag_threshold[0] = (fthr >> 8) & 0xFF;
local->sparm.b5.a_frag_threshold[1] = fthr & 0xFF;
return -EINPROGRESS;
}
static int ray_get_frag(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
wrqu->frag.value = (local->sparm.b5.a_frag_threshold[0] << 8)
+ local->sparm.b5.a_frag_threshold[1];
wrqu->frag.disabled = (wrqu->frag.value == 32767);
wrqu->frag.fixed = 1;
return 0;
}
static int ray_set_mode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
int err = -EINPROGRESS;
char card_mode = 1;
if (local->card_status != CARD_AWAITING_PARAM)
return -EBUSY;
switch (wrqu->mode) {
case IW_MODE_ADHOC:
card_mode = 0;
case IW_MODE_INFRA:
local->sparm.b5.a_network_type = card_mode;
break;
default:
err = -EINVAL;
}
return err;
}
static int ray_get_mode(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
ray_dev_t *local = netdev_priv(dev);
if (local->sparm.b5.a_network_type)
wrqu->mode = IW_MODE_INFRA;
else
wrqu->mode = IW_MODE_ADHOC;
return 0;
}
static int ray_get_range(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct iw_range *range = (struct iw_range *)extra;
memset(range, 0, sizeof(struct iw_range));
wrqu->data.length = sizeof(struct iw_range);
range->we_version_compiled = WIRELESS_EXT;
range->we_version_source = 9;
range->throughput = 1.1 * 1000 * 1000;
range->num_channels = hop_pattern_length[(int)country];
range->num_frequency = 0;
range->max_qual.qual = 0;
range->max_qual.level = 255;
range->max_qual.noise = 255;
range->num_bitrates = 2;
range->bitrate[0] = 1000000;
range->bitrate[1] = 2000000;
return 0;
}
static int ray_set_framing(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
translate = *(extra);
return 0;
}
static int ray_get_framing(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
*(extra) = translate;
return 0;
}
static int ray_get_country(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
*(extra) = country;
return 0;
}
static int ray_commit(struct net_device *dev, struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
return 0;
}
static iw_stats *ray_get_wireless_stats(struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
struct status __iomem *p = local->sram + STATUS_BASE;
local->wstats.status = local->card_status;
#ifdef WIRELESS_SPY
if ((local->spy_data.spy_number > 0)
&& (local->sparm.b5.a_network_type == 0)) {
local->wstats.qual.qual = local->spy_data.spy_stat[0].qual;
local->wstats.qual.level = local->spy_data.spy_stat[0].level;
local->wstats.qual.noise = local->spy_data.spy_stat[0].noise;
local->wstats.qual.updated =
local->spy_data.spy_stat[0].updated;
}
#endif
if (pcmcia_dev_present(link)) {
local->wstats.qual.noise = readb(&p->rxnoise);
local->wstats.qual.updated |= 4;
}
return &local->wstats;
}
static int ray_open(struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link;
link = local->finder;
dev_dbg(&link->dev, "ray_open('%s')\n", dev->name);
if (link->open == 0)
local->num_multi = 0;
link->open++;
if (local->card_status == CARD_AWAITING_PARAM) {
int i;
dev_dbg(&link->dev, "ray_open: doing init now !\n");
if ((i = dl_startup_params(dev)) < 0) {
printk(KERN_INFO
"ray_dev_init dl_startup_params failed - "
"returns 0x%x\n", i);
return -1;
}
}
if (sniffer)
netif_stop_queue(dev);
else
netif_start_queue(dev);
dev_dbg(&link->dev, "ray_open ending\n");
return 0;
}
static int ray_dev_close(struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link;
link = local->finder;
dev_dbg(&link->dev, "ray_dev_close('%s')\n", dev->name);
link->open--;
netif_stop_queue(dev);
return 0;
}
static void ray_reset(struct net_device *dev)
{
pr_debug("ray_reset entered\n");
}
static int interrupt_ecf(ray_dev_t *local, int ccs)
{
int i = 50;
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs interrupt_ecf - device not present\n");
return -1;
}
dev_dbg(&link->dev, "interrupt_ecf(local=%p, ccs = 0x%x\n", local, ccs);
while (i &&
(readb(local->amem + CIS_OFFSET + ECF_INTR_OFFSET) &
ECF_INTR_SET))
i--;
if (i == 0) {
dev_dbg(&link->dev, "ray_cs interrupt_ecf card not ready for interrupt\n");
return -1;
}
writeb(ccs, local->sram + SCB_BASE);
writeb(ECF_INTR_SET, local->amem + CIS_OFFSET + ECF_INTR_OFFSET);
return 0;
}
static int get_free_tx_ccs(ray_dev_t *local)
{
int i;
struct ccs __iomem *pccs = ccs_base(local);
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs get_free_tx_ccs - device not present\n");
return ECARDGONE;
}
if (test_and_set_bit(0, &local->tx_ccs_lock)) {
dev_dbg(&link->dev, "ray_cs tx_ccs_lock busy\n");
return ECCSBUSY;
}
for (i = 0; i < NUMBER_OF_TX_CCS; i++) {
if (readb(&(pccs + i)->buffer_status) == CCS_BUFFER_FREE) {
writeb(CCS_BUFFER_BUSY, &(pccs + i)->buffer_status);
writeb(CCS_END_LIST, &(pccs + i)->link);
local->tx_ccs_lock = 0;
return i;
}
}
local->tx_ccs_lock = 0;
dev_dbg(&link->dev, "ray_cs ERROR no free tx CCS for raylink card\n");
return ECCSFULL;
}
static int get_free_ccs(ray_dev_t *local)
{
int i;
struct ccs __iomem *pccs = ccs_base(local);
struct pcmcia_device *link = local->finder;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs get_free_ccs - device not present\n");
return ECARDGONE;
}
if (test_and_set_bit(0, &local->ccs_lock)) {
dev_dbg(&link->dev, "ray_cs ccs_lock busy\n");
return ECCSBUSY;
}
for (i = NUMBER_OF_TX_CCS; i < NUMBER_OF_CCS; i++) {
if (readb(&(pccs + i)->buffer_status) == CCS_BUFFER_FREE) {
writeb(CCS_BUFFER_BUSY, &(pccs + i)->buffer_status);
writeb(CCS_END_LIST, &(pccs + i)->link);
local->ccs_lock = 0;
return i;
}
}
local->ccs_lock = 0;
dev_dbg(&link->dev, "ray_cs ERROR no free CCS for raylink card\n");
return ECCSFULL;
}
static void authenticate_timeout(u_long data)
{
ray_dev_t *local = (ray_dev_t *) data;
del_timer(&local->timer);
printk(KERN_INFO "ray_cs Authentication with access point failed"
" - timeout\n");
join_net((u_long) local);
}
static int parse_addr(char *in_str, UCHAR *out)
{
int len;
int i, j, k;
int status;
if (in_str == NULL)
return 0;
if ((len = strlen(in_str)) < 2)
return 0;
memset(out, 0, ADDRLEN);
status = 1;
j = len - 1;
if (j > 12)
j = 12;
i = 5;
while (j > 0) {
if ((k = hex_to_bin(in_str[j--])) != -1)
out[i] = k;
else
return 0;
if (j == 0)
break;
if ((k = hex_to_bin(in_str[j--])) != -1)
out[i] += k << 4;
else
return 0;
if (!i--)
break;
}
return status;
}
static struct net_device_stats *ray_get_stats(struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
struct status __iomem *p = local->sram + STATUS_BASE;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs net_device_stats - device not present\n");
return &local->stats;
}
if (readb(&p->mrx_overflow_for_host)) {
local->stats.rx_over_errors += swab16(readw(&p->mrx_overflow));
writeb(0, &p->mrx_overflow);
writeb(0, &p->mrx_overflow_for_host);
}
if (readb(&p->mrx_checksum_error_for_host)) {
local->stats.rx_crc_errors +=
swab16(readw(&p->mrx_checksum_error));
writeb(0, &p->mrx_checksum_error);
writeb(0, &p->mrx_checksum_error_for_host);
}
if (readb(&p->rx_hec_error_for_host)) {
local->stats.rx_frame_errors += swab16(readw(&p->rx_hec_error));
writeb(0, &p->rx_hec_error);
writeb(0, &p->rx_hec_error_for_host);
}
return &local->stats;
}
static void ray_update_parm(struct net_device *dev, UCHAR objid, UCHAR *value,
int len)
{
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
int ccsindex;
int i;
struct ccs __iomem *pccs;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_update_parm - device not present\n");
return;
}
if ((ccsindex = get_free_ccs(local)) < 0) {
dev_dbg(&link->dev, "ray_update_parm - No free ccs\n");
return;
}
pccs = ccs_base(local) + ccsindex;
writeb(CCS_UPDATE_PARAMS, &pccs->cmd);
writeb(objid, &pccs->var.update_param.object_id);
writeb(1, &pccs->var.update_param.number_objects);
writeb(0, &pccs->var.update_param.failure_cause);
for (i = 0; i < len; i++) {
writeb(value[i], local->sram + HOST_TO_ECF_BASE);
}
if (interrupt_ecf(local, ccsindex)) {
dev_dbg(&link->dev, "ray_cs associate failed - ECF not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
}
}
static void ray_update_multi_list(struct net_device *dev, int all)
{
int ccsindex;
struct ccs __iomem *pccs;
ray_dev_t *local = netdev_priv(dev);
struct pcmcia_device *link = local->finder;
void __iomem *p = local->sram + HOST_TO_ECF_BASE;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_update_multi_list - device not present\n");
return;
} else
dev_dbg(&link->dev, "ray_update_multi_list(%p)\n", dev);
if ((ccsindex = get_free_ccs(local)) < 0) {
dev_dbg(&link->dev, "ray_update_multi - No free ccs\n");
return;
}
pccs = ccs_base(local) + ccsindex;
writeb(CCS_UPDATE_MULTICAST_LIST, &pccs->cmd);
if (all) {
writeb(0xff, &pccs->var);
local->num_multi = 0xff;
} else {
struct netdev_hw_addr *ha;
int i = 0;
netdev_for_each_mc_addr(ha, dev) {
memcpy_toio(p, ha->addr, ETH_ALEN);
dev_dbg(&link->dev, "ray_update_multi add addr %pm\n",
ha->addr);
p += ETH_ALEN;
i++;
}
if (i > 256 / ADDRLEN)
i = 256 / ADDRLEN;
writeb((UCHAR) i, &pccs->var);
dev_dbg(&link->dev, "ray_cs update_multi %d addresses in list\n", i);
local->num_multi = i;
}
if (interrupt_ecf(local, ccsindex)) {
dev_dbg(&link->dev,
"ray_cs update_multi failed - ECF not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
}
}
static void set_multicast_list(struct net_device *dev)
{
ray_dev_t *local = netdev_priv(dev);
UCHAR promisc;
pr_debug("ray_cs set_multicast_list(%p)\n", dev);
if (dev->flags & IFF_PROMISC) {
if (local->sparm.b5.a_promiscuous_mode == 0) {
pr_debug("ray_cs set_multicast_list promisc on\n");
local->sparm.b5.a_promiscuous_mode = 1;
promisc = 1;
ray_update_parm(dev, OBJID_promiscuous_mode,
&promisc, sizeof(promisc));
}
} else {
if (local->sparm.b5.a_promiscuous_mode == 1) {
pr_debug("ray_cs set_multicast_list promisc off\n");
local->sparm.b5.a_promiscuous_mode = 0;
promisc = 0;
ray_update_parm(dev, OBJID_promiscuous_mode,
&promisc, sizeof(promisc));
}
}
if (dev->flags & IFF_ALLMULTI)
ray_update_multi_list(dev, 1);
else {
if (local->num_multi != netdev_mc_count(dev))
ray_update_multi_list(dev, 0);
}
}
static irqreturn_t ray_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct pcmcia_device *link;
ray_dev_t *local;
struct ccs __iomem *pccs;
struct rcs __iomem *prcs;
UCHAR rcsindex;
UCHAR tmp;
UCHAR cmd;
UCHAR status;
if (dev == NULL)
return IRQ_NONE;
pr_debug("ray_cs: interrupt for *dev=%p\n", dev);
local = netdev_priv(dev);
link = local->finder;
if (!pcmcia_dev_present(link)) {
pr_debug(
"ray_cs interrupt from device not present or suspended.\n");
return IRQ_NONE;
}
rcsindex = readb(&((struct scb __iomem *)(local->sram))->rcs_index);
if (rcsindex >= (NUMBER_OF_CCS + NUMBER_OF_RCS)) {
dev_dbg(&link->dev, "ray_cs interrupt bad rcsindex = 0x%x\n", rcsindex);
clear_interrupt(local);
return IRQ_HANDLED;
}
if (rcsindex < NUMBER_OF_CCS) {
pccs = ccs_base(local) + rcsindex;
cmd = readb(&pccs->cmd);
status = readb(&pccs->buffer_status);
switch (cmd) {
case CCS_DOWNLOAD_STARTUP_PARAMS:
del_timer(&local->timer);
if (status == CCS_COMMAND_COMPLETE) {
dev_dbg(&link->dev,
"ray_cs interrupt download_startup_parameters OK\n");
} else {
dev_dbg(&link->dev,
"ray_cs interrupt download_startup_parameters fail\n");
}
break;
case CCS_UPDATE_PARAMS:
dev_dbg(&link->dev, "ray_cs interrupt update params done\n");
if (status != CCS_COMMAND_COMPLETE) {
tmp =
readb(&pccs->var.update_param.
failure_cause);
dev_dbg(&link->dev,
"ray_cs interrupt update params failed - reason %d\n",
tmp);
}
break;
case CCS_REPORT_PARAMS:
dev_dbg(&link->dev, "ray_cs interrupt report params done\n");
break;
case CCS_UPDATE_MULTICAST_LIST:
dev_dbg(&link->dev,
"ray_cs interrupt CCS Update Multicast List done\n");
break;
case CCS_UPDATE_POWER_SAVINGS_MODE:
dev_dbg(&link->dev,
"ray_cs interrupt update power save mode done\n");
break;
case CCS_START_NETWORK:
case CCS_JOIN_NETWORK:
if (status == CCS_COMMAND_COMPLETE) {
if (readb
(&pccs->var.start_network.net_initiated) ==
1) {
dev_dbg(&link->dev,
"ray_cs interrupt network \"%s\" started\n",
local->sparm.b4.a_current_ess_id);
} else {
dev_dbg(&link->dev,
"ray_cs interrupt network \"%s\" joined\n",
local->sparm.b4.a_current_ess_id);
}
memcpy_fromio(&local->bss_id,
pccs->var.start_network.bssid,
ADDRLEN);
if (local->fw_ver == 0x55)
local->net_default_tx_rate = 3;
else
local->net_default_tx_rate =
readb(&pccs->var.start_network.
net_default_tx_rate);
local->encryption =
readb(&pccs->var.start_network.encryption);
if (!sniffer && (local->net_type == INFRA)
&& !(local->sparm.b4.a_acting_as_ap_status)) {
authenticate(local);
}
local->card_status = CARD_ACQ_COMPLETE;
} else {
local->card_status = CARD_ACQ_FAILED;
del_timer(&local->timer);
local->timer.expires = jiffies + HZ * 5;
local->timer.data = (long)local;
if (status == CCS_START_NETWORK) {
dev_dbg(&link->dev,
"ray_cs interrupt network \"%s\" start failed\n",
local->sparm.b4.a_current_ess_id);
local->timer.function = start_net;
} else {
dev_dbg(&link->dev,
"ray_cs interrupt network \"%s\" join failed\n",
local->sparm.b4.a_current_ess_id);
local->timer.function = join_net;
}
add_timer(&local->timer);
}
break;
case CCS_START_ASSOCIATION:
if (status == CCS_COMMAND_COMPLETE) {
local->card_status = CARD_ASSOC_COMPLETE;
dev_dbg(&link->dev, "ray_cs association successful\n");
} else {
dev_dbg(&link->dev, "ray_cs association failed,\n");
local->card_status = CARD_ASSOC_FAILED;
join_net((u_long) local);
}
break;
case CCS_TX_REQUEST:
if (status == CCS_COMMAND_COMPLETE) {
dev_dbg(&link->dev,
"ray_cs interrupt tx request complete\n");
} else {
dev_dbg(&link->dev,
"ray_cs interrupt tx request failed\n");
}
if (!sniffer)
netif_start_queue(dev);
netif_wake_queue(dev);
break;
case CCS_TEST_MEMORY:
dev_dbg(&link->dev, "ray_cs interrupt mem test done\n");
break;
case CCS_SHUTDOWN:
dev_dbg(&link->dev,
"ray_cs interrupt Unexpected CCS returned - Shutdown\n");
break;
case CCS_DUMP_MEMORY:
dev_dbg(&link->dev, "ray_cs interrupt dump memory done\n");
break;
case CCS_START_TIMER:
dev_dbg(&link->dev,
"ray_cs interrupt DING - raylink timer expired\n");
break;
default:
dev_dbg(&link->dev,
"ray_cs interrupt Unexpected CCS 0x%x returned 0x%x\n",
rcsindex, cmd);
}
writeb(CCS_BUFFER_FREE, &pccs->buffer_status);
} else {
prcs = rcs_base(local) + rcsindex;
switch (readb(&prcs->interrupt_id)) {
case PROCESS_RX_PACKET:
ray_rx(dev, local, prcs);
break;
case REJOIN_NET_COMPLETE:
dev_dbg(&link->dev, "ray_cs interrupt rejoin net complete\n");
local->card_status = CARD_ACQ_COMPLETE;
if (local->sparm.b4.a_network_type == ADHOC) {
if (!sniffer)
netif_start_queue(dev);
} else {
memcpy_fromio(&local->bss_id,
prcs->var.rejoin_net_complete.
bssid, ADDRLEN);
dev_dbg(&link->dev, "ray_cs new BSSID = %pm\n",
local->bss_id);
if (!sniffer)
authenticate(local);
}
break;
case ROAMING_INITIATED:
dev_dbg(&link->dev, "ray_cs interrupt roaming initiated\n");
netif_stop_queue(dev);
local->card_status = CARD_DOING_ACQ;
break;
case JAPAN_CALL_SIGN_RXD:
dev_dbg(&link->dev, "ray_cs interrupt japan call sign rx\n");
break;
default:
dev_dbg(&link->dev,
"ray_cs Unexpected interrupt for RCS 0x%x cmd = 0x%x\n",
rcsindex,
(unsigned int)readb(&prcs->interrupt_id));
break;
}
writeb(CCS_BUFFER_FREE, &prcs->buffer_status);
}
clear_interrupt(local);
return IRQ_HANDLED;
}
static void ray_rx(struct net_device *dev, ray_dev_t *local,
struct rcs __iomem *prcs)
{
int rx_len;
unsigned int pkt_addr;
void __iomem *pmsg;
pr_debug("ray_rx process rx packet\n");
pkt_addr = ((readb(&prcs->var.rx_packet.rx_data_ptr[0]) << 8)
+ readb(&prcs->var.rx_packet.rx_data_ptr[1])) & RX_BUFF_END;
rx_len = (readb(&prcs->var.rx_packet.rx_data_length[0]) << 8)
+ readb(&prcs->var.rx_packet.rx_data_length[1]);
local->last_rsl = readb(&prcs->var.rx_packet.rx_sig_lev);
pmsg = local->rmem + pkt_addr;
switch (readb(pmsg)) {
case DATA_TYPE:
pr_debug("ray_rx data type\n");
rx_data(dev, prcs, pkt_addr, rx_len);
break;
case AUTHENTIC_TYPE:
pr_debug("ray_rx authentic type\n");
if (sniffer)
rx_data(dev, prcs, pkt_addr, rx_len);
else
rx_authenticate(local, prcs, pkt_addr, rx_len);
break;
case DEAUTHENTIC_TYPE:
pr_debug("ray_rx deauth type\n");
if (sniffer)
rx_data(dev, prcs, pkt_addr, rx_len);
else
rx_deauthenticate(local, prcs, pkt_addr, rx_len);
break;
case NULL_MSG_TYPE:
pr_debug("ray_cs rx NULL msg\n");
break;
case BEACON_TYPE:
pr_debug("ray_rx beacon type\n");
if (sniffer)
rx_data(dev, prcs, pkt_addr, rx_len);
copy_from_rx_buff(local, (UCHAR *) &local->last_bcn, pkt_addr,
rx_len < sizeof(struct beacon_rx) ?
rx_len : sizeof(struct beacon_rx));
local->beacon_rxed = 1;
ray_get_stats(dev);
break;
default:
pr_debug("ray_cs unknown pkt type %2x\n",
(unsigned int)readb(pmsg));
break;
}
}
static void rx_data(struct net_device *dev, struct rcs __iomem *prcs,
unsigned int pkt_addr, int rx_len)
{
struct sk_buff *skb = NULL;
struct rcs __iomem *prcslink = prcs;
ray_dev_t *local = netdev_priv(dev);
UCHAR *rx_ptr;
int total_len;
int tmp;
#ifdef WIRELESS_SPY
int siglev = local->last_rsl;
u_char linksrcaddr[ETH_ALEN];
#endif
if (!sniffer) {
if (translate) {
if (rx_len < (ETH_HLEN + RX_MAC_HEADER_LENGTH) ||
rx_len >
(dev->mtu + RX_MAC_HEADER_LENGTH + ETH_HLEN +
FCS_LEN)) {
pr_debug(
"ray_cs invalid packet length %d received\n",
rx_len);
return;
}
} else {
if (rx_len < (ETH_HLEN + RX_MAC_HEADER_LENGTH) ||
rx_len >
(dev->mtu + RX_MAC_HEADER_LENGTH + ETH_HLEN +
FCS_LEN)) {
pr_debug(
"ray_cs invalid packet length %d received\n",
rx_len);
return;
}
}
}
pr_debug("ray_cs rx_data packet\n");
if (readb(&prcs->var.rx_packet.next_frag_rcs_index) != 0xFF) {
pr_debug("ray_cs rx'ed fragment\n");
tmp = (readb(&prcs->var.rx_packet.totalpacketlength[0]) << 8)
+ readb(&prcs->var.rx_packet.totalpacketlength[1]);
total_len = tmp;
prcslink = prcs;
do {
tmp -=
(readb(&prcslink->var.rx_packet.rx_data_length[0])
<< 8)
+ readb(&prcslink->var.rx_packet.rx_data_length[1]);
if (readb(&prcslink->var.rx_packet.next_frag_rcs_index)
== 0xFF || tmp < 0)
break;
prcslink = rcs_base(local)
+ readb(&prcslink->link_field);
} while (1);
if (tmp < 0) {
pr_debug(
"ray_cs rx_data fragment lengths don't add up\n");
local->stats.rx_dropped++;
release_frag_chain(local, prcs);
return;
}
} else {
total_len = rx_len;
}
skb = dev_alloc_skb(total_len + 5);
if (skb == NULL) {
pr_debug("ray_cs rx_data could not allocate skb\n");
local->stats.rx_dropped++;
if (readb(&prcs->var.rx_packet.next_frag_rcs_index) != 0xFF)
release_frag_chain(local, prcs);
return;
}
skb_reserve(skb, 2);
pr_debug("ray_cs rx_data total_len = %x, rx_len = %x\n", total_len,
rx_len);
rx_ptr = skb_put(skb, total_len);
rx_ptr +=
copy_from_rx_buff(local, rx_ptr, pkt_addr & RX_BUFF_END, rx_len);
#ifdef WIRELESS_SPY
skb_copy_from_linear_data_offset(skb,
offsetof(struct mac_header, addr_2),
linksrcaddr, ETH_ALEN);
#endif
if (!sniffer) {
if (!translate) {
skb_pull(skb, RX_MAC_HEADER_LENGTH);
} else {
untranslate(local, skb, total_len);
}
} else {
};
tmp = 17;
if (readb(&prcs->var.rx_packet.next_frag_rcs_index) != 0xFF) {
prcslink = prcs;
pr_debug("ray_cs rx_data in fragment loop\n");
do {
prcslink = rcs_base(local)
+
readb(&prcslink->var.rx_packet.next_frag_rcs_index);
rx_len =
((readb(&prcslink->var.rx_packet.rx_data_length[0])
<< 8)
+
readb(&prcslink->var.rx_packet.rx_data_length[1]))
& RX_BUFF_END;
pkt_addr =
((readb(&prcslink->var.rx_packet.rx_data_ptr[0]) <<
8)
+ readb(&prcslink->var.rx_packet.rx_data_ptr[1]))
& RX_BUFF_END;
rx_ptr +=
copy_from_rx_buff(local, rx_ptr, pkt_addr, rx_len);
} while (tmp-- &&
readb(&prcslink->var.rx_packet.next_frag_rcs_index) !=
0xFF);
release_frag_chain(local, prcs);
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
local->stats.rx_packets++;
local->stats.rx_bytes += total_len;
#ifdef WIRELESS_SPY
if (!memcmp(linksrcaddr, local->bss_id, ETH_ALEN)) {
local->wstats.qual.level = siglev;
local->wstats.qual.updated = 0x2;
}
{
struct iw_quality wstats;
wstats.level = siglev;
wstats.updated = 0x2;
wireless_spy_update(dev, linksrcaddr, &wstats);
}
#endif
}
static void untranslate(ray_dev_t *local, struct sk_buff *skb, int len)
{
snaphdr_t *psnap = (snaphdr_t *) (skb->data + RX_MAC_HEADER_LENGTH);
struct ieee80211_hdr *pmac = (struct ieee80211_hdr *)skb->data;
__be16 type = *(__be16 *) psnap->ethertype;
int delta;
struct ethhdr *peth;
UCHAR srcaddr[ADDRLEN];
UCHAR destaddr[ADDRLEN];
static const UCHAR org_bridge[3] = { 0, 0, 0xf8 };
static const UCHAR org_1042[3] = { 0, 0, 0 };
memcpy(destaddr, ieee80211_get_DA(pmac), ADDRLEN);
memcpy(srcaddr, ieee80211_get_SA(pmac), ADDRLEN);
#if 0
if {
print_hex_dump(KERN_DEBUG, "skb->data before untranslate: ",
DUMP_PREFIX_NONE, 16, 1,
skb->data, 64, true);
printk(KERN_DEBUG
"type = %08x, xsap = %02x%02x%02x, org = %02x02x02x\n",
ntohs(type), psnap->dsap, psnap->ssap, psnap->ctrl,
psnap->org[0], psnap->org[1], psnap->org[2]);
printk(KERN_DEBUG "untranslate skb->data = %p\n", skb->data);
}
#endif
if (psnap->dsap != 0xaa || psnap->ssap != 0xaa || psnap->ctrl != 3) {
pr_debug("ray_cs untranslate NOT SNAP %02x %02x %02x\n",
psnap->dsap, psnap->ssap, psnap->ctrl);
delta = RX_MAC_HEADER_LENGTH - ETH_HLEN;
peth = (struct ethhdr *)(skb->data + delta);
peth->h_proto = htons(len - RX_MAC_HEADER_LENGTH);
} else {
if (memcmp(psnap->org, org_bridge, 3) == 0) {
pr_debug("ray_cs untranslate Bridge encap\n");
delta = RX_MAC_HEADER_LENGTH
+ sizeof(struct snaphdr_t) - ETH_HLEN;
peth = (struct ethhdr *)(skb->data + delta);
peth->h_proto = type;
} else if (memcmp(psnap->org, org_1042, 3) == 0) {
switch (ntohs(type)) {
case ETH_P_IPX:
case ETH_P_AARP:
pr_debug("ray_cs untranslate RFC IPX/AARP\n");
delta = RX_MAC_HEADER_LENGTH - ETH_HLEN;
peth = (struct ethhdr *)(skb->data + delta);
peth->h_proto =
htons(len - RX_MAC_HEADER_LENGTH);
break;
default:
pr_debug("ray_cs untranslate RFC default\n");
delta = RX_MAC_HEADER_LENGTH +
sizeof(struct snaphdr_t) - ETH_HLEN;
peth = (struct ethhdr *)(skb->data + delta);
peth->h_proto = type;
break;
}
} else {
printk("ray_cs untranslate very confused by packet\n");
delta = RX_MAC_HEADER_LENGTH - ETH_HLEN;
peth = (struct ethhdr *)(skb->data + delta);
peth->h_proto = type;
}
}
skb_pull(skb, delta);
pr_debug("untranslate after skb_pull(%d), skb->data = %p\n", delta,
skb->data);
memcpy(peth->h_dest, destaddr, ADDRLEN);
memcpy(peth->h_source, srcaddr, ADDRLEN);
#if 0
{
int i;
printk(KERN_DEBUG "skb->data after untranslate:");
for (i = 0; i < 64; i++)
printk("%02x ", skb->data[i]);
printk("\n");
}
#endif
}
static int copy_from_rx_buff(ray_dev_t *local, UCHAR *dest, int pkt_addr,
int length)
{
int wrap_bytes = (pkt_addr + length) - (RX_BUFF_END + 1);
if (wrap_bytes <= 0) {
memcpy_fromio(dest, local->rmem + pkt_addr, length);
} else {
memcpy_fromio(dest, local->rmem + pkt_addr,
length - wrap_bytes);
memcpy_fromio(dest + length - wrap_bytes, local->rmem,
wrap_bytes);
}
return length;
}
static void release_frag_chain(ray_dev_t *local, struct rcs __iomem *prcs)
{
struct rcs __iomem *prcslink = prcs;
int tmp = 17;
unsigned rcsindex = readb(&prcs->var.rx_packet.next_frag_rcs_index);
while (tmp--) {
writeb(CCS_BUFFER_FREE, &prcslink->buffer_status);
if (rcsindex >= (NUMBER_OF_CCS + NUMBER_OF_RCS)) {
pr_debug("ray_cs interrupt bad rcsindex = 0x%x\n",
rcsindex);
break;
}
prcslink = rcs_base(local) + rcsindex;
rcsindex = readb(&prcslink->var.rx_packet.next_frag_rcs_index);
}
writeb(CCS_BUFFER_FREE, &prcslink->buffer_status);
}
static void authenticate(ray_dev_t *local)
{
struct pcmcia_device *link = local->finder;
dev_dbg(&link->dev, "ray_cs Starting authentication.\n");
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs authenticate - device not present\n");
return;
}
del_timer(&local->timer);
if (build_auth_frame(local, local->bss_id, OPEN_AUTH_REQUEST)) {
local->timer.function = join_net;
} else {
local->timer.function = authenticate_timeout;
}
local->timer.expires = jiffies + HZ * 2;
local->timer.data = (long)local;
add_timer(&local->timer);
local->authentication_state = AWAITING_RESPONSE;
}
static void rx_authenticate(ray_dev_t *local, struct rcs __iomem *prcs,
unsigned int pkt_addr, int rx_len)
{
UCHAR buff[256];
struct ray_rx_msg *msg = (struct ray_rx_msg *) buff;
del_timer(&local->timer);
copy_from_rx_buff(local, buff, pkt_addr, rx_len & 0xff);
if (local->sparm.b4.a_network_type == ADHOC) {
pr_debug("ray_cs rx_auth var= %02x %02x %02x %02x %02x %02x\n",
msg->var[0], msg->var[1], msg->var[2], msg->var[3],
msg->var[4], msg->var[5]);
if (msg->var[2] == 1) {
pr_debug("ray_cs Sending authentication response.\n");
if (!build_auth_frame
(local, msg->mac.addr_2, OPEN_AUTH_RESPONSE)) {
local->authentication_state = NEED_TO_AUTH;
memcpy(local->auth_id, msg->mac.addr_2,
ADDRLEN);
}
}
} else {
if (local->authentication_state == AWAITING_RESPONSE) {
if (msg->var[2] == 2) {
if ((msg->var[3] | msg->var[4]) == 0) {
pr_debug("Authentication successful\n");
local->card_status = CARD_AUTH_COMPLETE;
associate(local);
local->authentication_state =
AUTHENTICATED;
} else {
pr_debug("Authentication refused\n");
local->card_status = CARD_AUTH_REFUSED;
join_net((u_long) local);
local->authentication_state =
UNAUTHENTICATED;
}
}
}
}
}
static void associate(ray_dev_t *local)
{
struct ccs __iomem *pccs;
struct pcmcia_device *link = local->finder;
struct net_device *dev = link->priv;
int ccsindex;
if (!(pcmcia_dev_present(link))) {
dev_dbg(&link->dev, "ray_cs associate - device not present\n");
return;
}
if ((ccsindex = get_free_ccs(local)) < 0) {
dev_dbg(&link->dev, "ray_cs associate - No free ccs\n");
return;
}
dev_dbg(&link->dev, "ray_cs Starting association with access point\n");
pccs = ccs_base(local) + ccsindex;
writeb(CCS_START_ASSOCIATION, &pccs->cmd);
if (interrupt_ecf(local, ccsindex)) {
dev_dbg(&link->dev, "ray_cs associate failed - ECF not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
del_timer(&local->timer);
local->timer.expires = jiffies + HZ * 2;
local->timer.data = (long)local;
local->timer.function = join_net;
add_timer(&local->timer);
local->card_status = CARD_ASSOC_FAILED;
return;
}
if (!sniffer)
netif_start_queue(dev);
}
static void rx_deauthenticate(ray_dev_t *local, struct rcs __iomem *prcs,
unsigned int pkt_addr, int rx_len)
{
pr_debug("Deauthentication frame received\n");
local->authentication_state = UNAUTHENTICATED;
}
static void clear_interrupt(ray_dev_t *local)
{
writeb(0, local->amem + CIS_OFFSET + HCS_INTR_OFFSET);
}
static int ray_cs_proc_show(struct seq_file *m, void *v)
{
int i;
struct pcmcia_device *link;
struct net_device *dev;
ray_dev_t *local;
UCHAR *p;
struct freq_hop_element *pfh;
UCHAR c[33];
link = this_device;
if (!link)
return 0;
dev = (struct net_device *)link->priv;
if (!dev)
return 0;
local = netdev_priv(dev);
if (!local)
return 0;
seq_puts(m, "Raylink Wireless LAN driver status\n");
seq_printf(m, "%s\n", rcsid);
seq_puts(m, "Firmware version = ");
if (local->fw_ver == 0x55)
seq_puts(m, "4 - Use dump_cis for more details\n");
else
seq_printf(m, "%2d.%02d.%02d\n",
local->fw_ver, local->fw_bld, local->fw_var);
for (i = 0; i < 32; i++)
c[i] = local->sparm.b5.a_current_ess_id[i];
c[32] = 0;
seq_printf(m, "%s network ESSID = \"%s\"\n",
nettype[local->sparm.b5.a_network_type], c);
p = local->bss_id;
seq_printf(m, "BSSID = %pM\n", p);
seq_printf(m, "Country code = %d\n",
local->sparm.b5.a_curr_country_code);
i = local->card_status;
if (i < 0)
i = 10;
if (i > 16)
i = 10;
seq_printf(m, "Card status = %s\n", card_status[i]);
seq_printf(m, "Framing mode = %s\n", framing[translate]);
seq_printf(m, "Last pkt signal lvl = %d\n", local->last_rsl);
if (local->beacon_rxed) {
seq_printf(m, "Beacon Interval = %d Kus\n",
local->last_bcn.beacon_intvl[0]
+ 256 * local->last_bcn.beacon_intvl[1]);
p = local->last_bcn.elements;
if (p[0] == C_ESSID_ELEMENT_ID)
p += p[1] + 2;
else {
seq_printf(m,
"Parse beacon failed at essid element id = %d\n",
p[0]);
return 0;
}
if (p[0] == C_SUPPORTED_RATES_ELEMENT_ID) {
seq_puts(m, "Supported rate codes = ");
for (i = 2; i < p[1] + 2; i++)
seq_printf(m, "0x%02x ", p[i]);
seq_putc(m, '\n');
p += p[1] + 2;
} else {
seq_puts(m, "Parse beacon failed at rates element\n");
return 0;
}
if (p[0] == C_FH_PARAM_SET_ELEMENT_ID) {
pfh = (struct freq_hop_element *)p;
seq_printf(m, "Hop dwell = %d Kus\n",
pfh->dwell_time[0] +
256 * pfh->dwell_time[1]);
seq_printf(m, "Hop set = %d\n",
pfh->hop_set);
seq_printf(m, "Hop pattern = %d\n",
pfh->hop_pattern);
seq_printf(m, "Hop index = %d\n",
pfh->hop_index);
p += p[1] + 2;
} else {
seq_puts(m,
"Parse beacon failed at FH param element\n");
return 0;
}
} else {
seq_puts(m, "No beacons received\n");
}
return 0;
}
static int ray_cs_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ray_cs_proc_show, NULL);
}
static int build_auth_frame(ray_dev_t *local, UCHAR *dest, int auth_type)
{
int addr;
struct ccs __iomem *pccs;
struct tx_msg __iomem *ptx;
int ccsindex;
if ((ccsindex = get_free_tx_ccs(local)) < 0) {
pr_debug("ray_cs send authenticate - No free tx ccs\n");
return -1;
}
pccs = ccs_base(local) + ccsindex;
addr = TX_BUF_BASE + (ccsindex << 11);
writeb(CCS_TX_REQUEST, &pccs->cmd);
writeb(addr >> 8, pccs->var.tx_request.tx_data_ptr);
writeb(0x20, pccs->var.tx_request.tx_data_ptr + 1);
writeb(TX_AUTHENTICATE_LENGTH_MSB, pccs->var.tx_request.tx_data_length);
writeb(TX_AUTHENTICATE_LENGTH_LSB,
pccs->var.tx_request.tx_data_length + 1);
writeb(0, &pccs->var.tx_request.pow_sav_mode);
ptx = local->sram + addr;
writeb(PROTOCOL_VER | AUTHENTIC_TYPE, &ptx->mac.frame_ctl_1);
writeb(0, &ptx->mac.frame_ctl_2);
memcpy_toio(ptx->mac.addr_1, dest, ADDRLEN);
memcpy_toio(ptx->mac.addr_2, local->sparm.b4.a_mac_addr, ADDRLEN);
memcpy_toio(ptx->mac.addr_3, local->bss_id, ADDRLEN);
memset_io(ptx->var, 0, 6);
writeb(auth_type & 0xff, ptx->var + 2);
if (interrupt_ecf(local, ccsindex)) {
pr_debug(
"ray_cs send authentication request failed - ECF not ready for intr\n");
writeb(CCS_BUFFER_FREE, &(pccs++)->buffer_status);
return -1;
}
return 0;
}
static ssize_t ray_cs_essid_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
static char proc_essid[33];
unsigned int len = count;
if (len > 32)
len = 32;
memset(proc_essid, 0, 33);
if (copy_from_user(proc_essid, buffer, len))
return -EFAULT;
essid = proc_essid;
return count;
}
static ssize_t int_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
static char proc_number[10];
char *p;
int nr, len;
if (!count)
return 0;
if (count > 9)
return -EINVAL;
if (copy_from_user(proc_number, buffer, count))
return -EFAULT;
p = proc_number;
nr = 0;
len = count;
do {
unsigned int c = *p - '0';
if (c > 9)
return -EINVAL;
nr = nr * 10 + c;
p++;
} while (--len);
*(int *)PDE(file->f_path.dentry->d_inode)->data = nr;
return count;
}
static int __init init_ray_cs(void)
{
int rc;
pr_debug("%s\n", rcsid);
rc = pcmcia_register_driver(&ray_driver);
pr_debug("raylink init_module register_pcmcia_driver returns 0x%x\n",
rc);
#ifdef CONFIG_PROC_FS
proc_mkdir("driver/ray_cs", NULL);
proc_create("driver/ray_cs/ray_cs", 0, NULL, &ray_cs_proc_fops);
proc_create("driver/ray_cs/essid", S_IWUSR, NULL, &ray_cs_essid_proc_fops);
proc_create_data("driver/ray_cs/net_type", S_IWUSR, NULL, &int_proc_fops, &net_type);
proc_create_data("driver/ray_cs/translate", S_IWUSR, NULL, &int_proc_fops, &translate);
#endif
if (translate != 0)
translate = 1;
return 0;
}
static void __exit exit_ray_cs(void)
{
pr_debug("ray_cs: cleanup_module\n");
#ifdef CONFIG_PROC_FS
remove_proc_entry("driver/ray_cs/ray_cs", NULL);
remove_proc_entry("driver/ray_cs/essid", NULL);
remove_proc_entry("driver/ray_cs/net_type", NULL);
remove_proc_entry("driver/ray_cs/translate", NULL);
remove_proc_entry("driver/ray_cs", NULL);
#endif
pcmcia_unregister_driver(&ray_driver);
}
