static void netvsc_set_multicast_list(struct net_device *net)
{
}
static int netvsc_open(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_device *device_obj = net_device_ctx->device_ctx;
int ret = 0;
if (netif_carrier_ok(net)) {
ret = rndis_filter_open(device_obj);
if (ret != 0) {
netdev_err(net, "unable to open device (ret %d).\n",
ret);
return ret;
}
netif_start_queue(net);
} else {
netdev_err(net, "unable to open device...link is down.\n");
}
return ret;
}
static int netvsc_close(struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_device *device_obj = net_device_ctx->device_ctx;
int ret;
netif_stop_queue(net);
ret = rndis_filter_close(device_obj);
if (ret != 0)
netdev_err(net, "unable to close device (ret %d).\n", ret);
return ret;
}
static void netvsc_xmit_completion(void *context)
{
struct hv_netvsc_packet *packet = (struct hv_netvsc_packet *)context;
struct sk_buff *skb = (struct sk_buff *)
(unsigned long)packet->completion.send.send_completion_tid;
kfree(packet);
if (skb) {
struct net_device *net = skb->dev;
struct net_device_context *net_device_ctx = netdev_priv(net);
unsigned int num_pages = skb_shinfo(skb)->nr_frags + 2;
dev_kfree_skb_any(skb);
net_device_ctx->avail += num_pages;
if (net_device_ctx->avail >= PACKET_PAGES_HIWATER)
netif_wake_queue(net);
}
}
static int netvsc_start_xmit(struct sk_buff *skb, struct net_device *net)
{
struct net_device_context *net_device_ctx = netdev_priv(net);
struct hv_netvsc_packet *packet;
int ret;
unsigned int i, num_pages;
num_pages = skb_shinfo(skb)->nr_frags + 1 + 1;
if (num_pages > net_device_ctx->avail)
return NETDEV_TX_BUSY;
packet = kzalloc(sizeof(struct hv_netvsc_packet) +
(num_pages * sizeof(struct hv_page_buffer)) +
sizeof(struct rndis_filter_packet), GFP_ATOMIC);
if (!packet) {
netdev_err(net, "unable to allocate hv_netvsc_packet\n");
dev_kfree_skb(skb);
net->stats.tx_dropped++;
return NETDEV_TX_OK;
}
packet->extension = (void *)(unsigned long)packet +
sizeof(struct hv_netvsc_packet) +
(num_pages * sizeof(struct hv_page_buffer));
packet->page_buf_cnt = num_pages;
packet->total_data_buflen = skb->len;
packet->page_buf[1].pfn = virt_to_phys(skb->data) >> PAGE_SHIFT;
packet->page_buf[1].offset
= (unsigned long)skb->data & (PAGE_SIZE - 1);
packet->page_buf[1].len = skb_headlen(skb);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *f = &skb_shinfo(skb)->frags[i];
packet->page_buf[i+2].pfn = page_to_pfn(f->page);
packet->page_buf[i+2].offset = f->page_offset;
packet->page_buf[i+2].len = f->size;
}
packet->completion.send.send_completion = netvsc_xmit_completion;
packet->completion.send.send_completion_ctx = packet;
packet->completion.send.send_completion_tid = (unsigned long)skb;
ret = rndis_filter_send(net_device_ctx->device_ctx,
packet);
if (ret == 0) {
net->stats.tx_bytes += skb->len;
net->stats.tx_packets++;
net_device_ctx->avail -= num_pages;
if (net_device_ctx->avail < PACKET_PAGES_LOWATER)
netif_stop_queue(net);
} else {
net->stats.tx_dropped++;
netvsc_xmit_completion(packet);
}
return NETDEV_TX_OK;
}
void netvsc_linkstatus_callback(struct hv_device *device_obj,
unsigned int status)
{
struct net_device *net = dev_get_drvdata(&device_obj->device);
struct net_device_context *ndev_ctx;
if (!net) {
netdev_err(net, "got link status but net device "
"not initialized yet\n");
return;
}
if (status == 1) {
netif_carrier_on(net);
netif_wake_queue(net);
netif_notify_peers(net);
ndev_ctx = netdev_priv(net);
schedule_work(&ndev_ctx->work);
} else {
netif_carrier_off(net);
netif_stop_queue(net);
}
}
int netvsc_recv_callback(struct hv_device *device_obj,
struct hv_netvsc_packet *packet)
{
struct net_device *net = dev_get_drvdata(&device_obj->device);
struct sk_buff *skb;
void *data;
int i;
unsigned long flags;
if (!net) {
netdev_err(net, "got receive callback but net device"
" not initialized yet\n");
return 0;
}
skb = netdev_alloc_skb_ip_align(net, packet->total_data_buflen);
if (unlikely(!skb)) {
++net->stats.rx_dropped;
return 0;
}
local_irq_save(flags);
for (i = 0; i < packet->page_buf_cnt; i++) {
data = kmap_atomic(pfn_to_page(packet->page_buf[i].pfn),
KM_IRQ1);
data = (void *)(unsigned long)data +
packet->page_buf[i].offset;
memcpy(skb_put(skb, packet->page_buf[i].len), data,
packet->page_buf[i].len);
kunmap_atomic((void *)((unsigned long)data -
packet->page_buf[i].offset), KM_IRQ1);
}
local_irq_restore(flags);
skb->protocol = eth_type_trans(skb, net);
skb->ip_summed = CHECKSUM_NONE;
net->stats.rx_packets++;
net->stats.rx_bytes += skb->len;
netif_rx(skb);
return 0;
}
static void netvsc_get_drvinfo(struct net_device *net,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, "hv_netvsc");
strcpy(info->version, HV_DRV_VERSION);
strcpy(info->fw_version, "N/A");
}
static void netvsc_send_garp(struct work_struct *w)
{
struct net_device_context *ndev_ctx;
struct net_device *net;
msleep(20);
ndev_ctx = container_of(w, struct net_device_context, work);
net = dev_get_drvdata(&ndev_ctx->device_ctx->device);
netif_notify_peers(net);
}
static int netvsc_probe(struct hv_device *dev)
{
struct net_device *net = NULL;
struct net_device_context *net_device_ctx;
struct netvsc_device_info device_info;
int ret;
net = alloc_etherdev(sizeof(struct net_device_context));
if (!net)
return -1;
netif_carrier_off(net);
net_device_ctx = netdev_priv(net);
net_device_ctx->device_ctx = dev;
net_device_ctx->avail = ring_size;
dev_set_drvdata(&dev->device, net);
INIT_WORK(&net_device_ctx->work, netvsc_send_garp);
device_info.ring_size = ring_size;
ret = rndis_filte_device_add(dev, &device_info);
if (ret != 0) {
free_netdev(net);
dev_set_drvdata(&dev->device, NULL);
netdev_err(net, "unable to add netvsc device (ret %d)\n", ret);
return ret;
}
if (!netif_carrier_ok(net))
if (!device_info.link_state)
netif_carrier_on(net);
memcpy(net->dev_addr, device_info.mac_adr, ETH_ALEN);
net->netdev_ops = &device_ops;
net->hw_features = NETIF_F_SG;
net->features = NETIF_F_SG;
SET_ETHTOOL_OPS(net, &ethtool_ops);
SET_NETDEV_DEV(net, &dev->device);
ret = register_netdev(net);
if (ret != 0) {
rndis_filter_device_remove(dev);
free_netdev(net);
}
return ret;
}
static int netvsc_remove(struct hv_device *dev)
{
struct net_device *net = dev_get_drvdata(&dev->device);
int ret;
if (net == NULL) {
dev_err(&dev->device, "No net device to remove\n");
return 0;
}
netif_stop_queue(net);
unregister_netdev(net);
ret = rndis_filter_device_remove(dev);
if (ret != 0) {
netdev_err(net, "unable to remove vsc device (ret %d)\n", ret);
}
free_netdev(net);
return ret;
}
static void __exit netvsc_drv_exit(void)
{
vmbus_child_driver_unregister(&netvsc_drv.driver);
}
static int __init netvsc_drv_init(void)
{
struct hv_driver *drv = &netvsc_drv;
int ret;
pr_info("initializing....");
if (!dmi_check_system(hv_netvsc_dmi_table))
return -ENODEV;
netvsc_initialize(drv);
drv->driver.name = drv->name;
ret = vmbus_child_driver_register(&drv->driver);
return ret;
}
