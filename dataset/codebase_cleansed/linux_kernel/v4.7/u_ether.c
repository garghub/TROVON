static inline int qlen(struct usb_gadget *gadget, unsigned qmult)
{
if (gadget_is_dualspeed(gadget) && (gadget->speed == USB_SPEED_HIGH ||
gadget->speed == USB_SPEED_SUPER))
return qmult * DEFAULT_QLEN;
else
return DEFAULT_QLEN;
}
static int ueth_change_mtu(struct net_device *net, int new_mtu)
{
if (new_mtu <= ETH_HLEN || new_mtu > GETHER_MAX_ETH_FRAME_LEN)
return -ERANGE;
net->mtu = new_mtu;
return 0;
}
static void eth_get_drvinfo(struct net_device *net, struct ethtool_drvinfo *p)
{
struct eth_dev *dev = netdev_priv(net);
strlcpy(p->driver, "g_ether", sizeof(p->driver));
strlcpy(p->version, UETH__VERSION, sizeof(p->version));
strlcpy(p->fw_version, dev->gadget->name, sizeof(p->fw_version));
strlcpy(p->bus_info, dev_name(&dev->gadget->dev), sizeof(p->bus_info));
}
static void defer_kevent(struct eth_dev *dev, int flag)
{
if (test_and_set_bit(flag, &dev->todo))
return;
if (!schedule_work(&dev->work))
ERROR(dev, "kevent %d may have been dropped\n", flag);
else
DBG(dev, "kevent %d scheduled\n", flag);
}
static int
rx_submit(struct eth_dev *dev, struct usb_request *req, gfp_t gfp_flags)
{
struct sk_buff *skb;
int retval = -ENOMEM;
size_t size = 0;
struct usb_ep *out;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
if (dev->port_usb)
out = dev->port_usb->out_ep;
else
out = NULL;
spin_unlock_irqrestore(&dev->lock, flags);
if (!out)
return -ENOTCONN;
size += sizeof(struct ethhdr) + dev->net->mtu + RX_EXTRA;
size += dev->port_usb->header_len;
size += out->maxpacket - 1;
size -= size % out->maxpacket;
if (dev->port_usb->is_fixed)
size = max_t(size_t, size, dev->port_usb->fixed_out_len);
skb = alloc_skb(size + NET_IP_ALIGN, gfp_flags);
if (skb == NULL) {
DBG(dev, "no rx skb\n");
goto enomem;
}
skb_reserve(skb, NET_IP_ALIGN);
req->buf = skb->data;
req->length = size;
req->complete = rx_complete;
req->context = skb;
retval = usb_ep_queue(out, req, gfp_flags);
if (retval == -ENOMEM)
enomem:
defer_kevent(dev, WORK_RX_MEMORY);
if (retval) {
DBG(dev, "rx submit --> %d\n", retval);
if (skb)
dev_kfree_skb_any(skb);
spin_lock_irqsave(&dev->req_lock, flags);
list_add(&req->list, &dev->rx_reqs);
spin_unlock_irqrestore(&dev->req_lock, flags);
}
return retval;
}
static void rx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct sk_buff *skb = req->context, *skb2;
struct eth_dev *dev = ep->driver_data;
int status = req->status;
switch (status) {
case 0:
skb_put(skb, req->actual);
if (dev->unwrap) {
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
if (dev->port_usb) {
status = dev->unwrap(dev->port_usb,
skb,
&dev->rx_frames);
} else {
dev_kfree_skb_any(skb);
status = -ENOTCONN;
}
spin_unlock_irqrestore(&dev->lock, flags);
} else {
skb_queue_tail(&dev->rx_frames, skb);
}
skb = NULL;
skb2 = skb_dequeue(&dev->rx_frames);
while (skb2) {
if (status < 0
|| ETH_HLEN > skb2->len
|| skb2->len > GETHER_MAX_ETH_FRAME_LEN) {
dev->net->stats.rx_errors++;
dev->net->stats.rx_length_errors++;
DBG(dev, "rx length %d\n", skb2->len);
dev_kfree_skb_any(skb2);
goto next_frame;
}
skb2->protocol = eth_type_trans(skb2, dev->net);
dev->net->stats.rx_packets++;
dev->net->stats.rx_bytes += skb2->len;
status = netif_rx(skb2);
next_frame:
skb2 = skb_dequeue(&dev->rx_frames);
}
break;
case -ECONNRESET:
case -ESHUTDOWN:
VDBG(dev, "rx shutdown, code %d\n", status);
goto quiesce;
case -ECONNABORTED:
DBG(dev, "rx %s reset\n", ep->name);
defer_kevent(dev, WORK_RX_MEMORY);
quiesce:
dev_kfree_skb_any(skb);
goto clean;
case -EOVERFLOW:
dev->net->stats.rx_over_errors++;
default:
dev->net->stats.rx_errors++;
DBG(dev, "rx status %d\n", status);
break;
}
if (skb)
dev_kfree_skb_any(skb);
if (!netif_running(dev->net)) {
clean:
spin_lock(&dev->req_lock);
list_add(&req->list, &dev->rx_reqs);
spin_unlock(&dev->req_lock);
req = NULL;
}
if (req)
rx_submit(dev, req, GFP_ATOMIC);
}
static int prealloc(struct list_head *list, struct usb_ep *ep, unsigned n)
{
unsigned i;
struct usb_request *req;
if (!n)
return -ENOMEM;
i = n;
list_for_each_entry(req, list, list) {
if (i-- == 0)
goto extra;
}
while (i--) {
req = usb_ep_alloc_request(ep, GFP_ATOMIC);
if (!req)
return list_empty(list) ? -ENOMEM : 0;
list_add(&req->list, list);
}
return 0;
extra:
for (;;) {
struct list_head *next;
next = req->list.next;
list_del(&req->list);
usb_ep_free_request(ep, req);
if (next == list)
break;
req = container_of(next, struct usb_request, list);
}
return 0;
}
static int alloc_requests(struct eth_dev *dev, struct gether *link, unsigned n)
{
int status;
spin_lock(&dev->req_lock);
status = prealloc(&dev->tx_reqs, link->in_ep, n);
if (status < 0)
goto fail;
status = prealloc(&dev->rx_reqs, link->out_ep, n);
if (status < 0)
goto fail;
goto done;
fail:
DBG(dev, "can't alloc requests\n");
done:
spin_unlock(&dev->req_lock);
return status;
}
static void rx_fill(struct eth_dev *dev, gfp_t gfp_flags)
{
struct usb_request *req;
unsigned long flags;
spin_lock_irqsave(&dev->req_lock, flags);
while (!list_empty(&dev->rx_reqs)) {
req = container_of(dev->rx_reqs.next,
struct usb_request, list);
list_del_init(&req->list);
spin_unlock_irqrestore(&dev->req_lock, flags);
if (rx_submit(dev, req, gfp_flags) < 0) {
defer_kevent(dev, WORK_RX_MEMORY);
return;
}
spin_lock_irqsave(&dev->req_lock, flags);
}
spin_unlock_irqrestore(&dev->req_lock, flags);
}
static void eth_work(struct work_struct *work)
{
struct eth_dev *dev = container_of(work, struct eth_dev, work);
if (test_and_clear_bit(WORK_RX_MEMORY, &dev->todo)) {
if (netif_running(dev->net))
rx_fill(dev, GFP_KERNEL);
}
if (dev->todo)
DBG(dev, "work done, flags = 0x%lx\n", dev->todo);
}
static void tx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct sk_buff *skb = req->context;
struct eth_dev *dev = ep->driver_data;
switch (req->status) {
default:
dev->net->stats.tx_errors++;
VDBG(dev, "tx err %d\n", req->status);
case -ECONNRESET:
case -ESHUTDOWN:
break;
case 0:
dev->net->stats.tx_bytes += skb->len;
}
dev->net->stats.tx_packets++;
spin_lock(&dev->req_lock);
list_add(&req->list, &dev->tx_reqs);
spin_unlock(&dev->req_lock);
dev_kfree_skb_any(skb);
atomic_dec(&dev->tx_qlen);
if (netif_carrier_ok(dev->net))
netif_wake_queue(dev->net);
}
static inline int is_promisc(u16 cdc_filter)
{
return cdc_filter & USB_CDC_PACKET_TYPE_PROMISCUOUS;
}
static netdev_tx_t eth_start_xmit(struct sk_buff *skb,
struct net_device *net)
{
struct eth_dev *dev = netdev_priv(net);
int length = 0;
int retval;
struct usb_request *req = NULL;
unsigned long flags;
struct usb_ep *in;
u16 cdc_filter;
spin_lock_irqsave(&dev->lock, flags);
if (dev->port_usb) {
in = dev->port_usb->in_ep;
cdc_filter = dev->port_usb->cdc_filter;
} else {
in = NULL;
cdc_filter = 0;
}
spin_unlock_irqrestore(&dev->lock, flags);
if (skb && !in) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (skb && !is_promisc(cdc_filter)) {
u8 *dest = skb->data;
if (is_multicast_ether_addr(dest)) {
u16 type;
if (is_broadcast_ether_addr(dest))
type = USB_CDC_PACKET_TYPE_BROADCAST;
else
type = USB_CDC_PACKET_TYPE_ALL_MULTICAST;
if (!(cdc_filter & type)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
}
}
spin_lock_irqsave(&dev->req_lock, flags);
if (list_empty(&dev->tx_reqs)) {
spin_unlock_irqrestore(&dev->req_lock, flags);
return NETDEV_TX_BUSY;
}
req = container_of(dev->tx_reqs.next, struct usb_request, list);
list_del(&req->list);
if (list_empty(&dev->tx_reqs))
netif_stop_queue(net);
spin_unlock_irqrestore(&dev->req_lock, flags);
if (dev->wrap) {
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
if (dev->port_usb)
skb = dev->wrap(dev->port_usb, skb);
spin_unlock_irqrestore(&dev->lock, flags);
if (!skb) {
if (dev->port_usb->supports_multi_frame)
goto multiframe;
goto drop;
}
}
length = skb->len;
req->buf = skb->data;
req->context = skb;
req->complete = tx_complete;
if (dev->port_usb->is_fixed &&
length == dev->port_usb->fixed_in_len &&
(length % in->maxpacket) == 0)
req->zero = 0;
else
req->zero = 1;
if (req->zero && !dev->zlp && (length % in->maxpacket) == 0)
length++;
req->length = length;
if (gadget_is_dualspeed(dev->gadget))
req->no_interrupt = (dev->gadget->speed == USB_SPEED_HIGH ||
dev->gadget->speed == USB_SPEED_SUPER)
? ((atomic_read(&dev->tx_qlen) % dev->qmult) != 0)
: 0;
retval = usb_ep_queue(in, req, GFP_ATOMIC);
switch (retval) {
default:
DBG(dev, "tx queue err %d\n", retval);
break;
case 0:
netif_trans_update(net);
atomic_inc(&dev->tx_qlen);
}
if (retval) {
dev_kfree_skb_any(skb);
drop:
dev->net->stats.tx_dropped++;
multiframe:
spin_lock_irqsave(&dev->req_lock, flags);
if (list_empty(&dev->tx_reqs))
netif_start_queue(net);
list_add(&req->list, &dev->tx_reqs);
spin_unlock_irqrestore(&dev->req_lock, flags);
}
return NETDEV_TX_OK;
}
static void eth_start(struct eth_dev *dev, gfp_t gfp_flags)
{
DBG(dev, "%s\n", __func__);
rx_fill(dev, gfp_flags);
atomic_set(&dev->tx_qlen, 0);
netif_wake_queue(dev->net);
}
static int eth_open(struct net_device *net)
{
struct eth_dev *dev = netdev_priv(net);
struct gether *link;
DBG(dev, "%s\n", __func__);
if (netif_carrier_ok(dev->net))
eth_start(dev, GFP_KERNEL);
spin_lock_irq(&dev->lock);
link = dev->port_usb;
if (link && link->open)
link->open(link);
spin_unlock_irq(&dev->lock);
return 0;
}
static int eth_stop(struct net_device *net)
{
struct eth_dev *dev = netdev_priv(net);
unsigned long flags;
VDBG(dev, "%s\n", __func__);
netif_stop_queue(net);
DBG(dev, "stop stats: rx/tx %ld/%ld, errs %ld/%ld\n",
dev->net->stats.rx_packets, dev->net->stats.tx_packets,
dev->net->stats.rx_errors, dev->net->stats.tx_errors
);
spin_lock_irqsave(&dev->lock, flags);
if (dev->port_usb) {
struct gether *link = dev->port_usb;
const struct usb_endpoint_descriptor *in;
const struct usb_endpoint_descriptor *out;
if (link->close)
link->close(link);
in = link->in_ep->desc;
out = link->out_ep->desc;
usb_ep_disable(link->in_ep);
usb_ep_disable(link->out_ep);
if (netif_carrier_ok(net)) {
DBG(dev, "host still using in/out endpoints\n");
link->in_ep->desc = in;
link->out_ep->desc = out;
usb_ep_enable(link->in_ep);
usb_ep_enable(link->out_ep);
}
}
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
static int get_ether_addr(const char *str, u8 *dev_addr)
{
if (str) {
unsigned i;
for (i = 0; i < 6; i++) {
unsigned char num;
if ((*str == '.') || (*str == ':'))
str++;
num = hex_to_bin(*str++) << 4;
num |= hex_to_bin(*str++);
dev_addr [i] = num;
}
if (is_valid_ether_addr(dev_addr))
return 0;
}
eth_random_addr(dev_addr);
return 1;
}
static int get_ether_addr_str(u8 dev_addr[ETH_ALEN], char *str, int len)
{
if (len < 18)
return -EINVAL;
snprintf(str, len, "%pM", dev_addr);
return 18;
}
struct eth_dev *gether_setup_name(struct usb_gadget *g,
const char *dev_addr, const char *host_addr,
u8 ethaddr[ETH_ALEN], unsigned qmult, const char *netname)
{
struct eth_dev *dev;
struct net_device *net;
int status;
net = alloc_etherdev(sizeof *dev);
if (!net)
return ERR_PTR(-ENOMEM);
dev = netdev_priv(net);
spin_lock_init(&dev->lock);
spin_lock_init(&dev->req_lock);
INIT_WORK(&dev->work, eth_work);
INIT_LIST_HEAD(&dev->tx_reqs);
INIT_LIST_HEAD(&dev->rx_reqs);
skb_queue_head_init(&dev->rx_frames);
dev->net = net;
dev->qmult = qmult;
snprintf(net->name, sizeof(net->name), "%s%%d", netname);
if (get_ether_addr(dev_addr, net->dev_addr))
dev_warn(&g->dev,
"using random %s ethernet address\n", "self");
if (get_ether_addr(host_addr, dev->host_mac))
dev_warn(&g->dev,
"using random %s ethernet address\n", "host");
if (ethaddr)
memcpy(ethaddr, dev->host_mac, ETH_ALEN);
net->netdev_ops = &eth_netdev_ops;
net->ethtool_ops = &ops;
dev->gadget = g;
SET_NETDEV_DEV(net, &g->dev);
SET_NETDEV_DEVTYPE(net, &gadget_type);
status = register_netdev(net);
if (status < 0) {
dev_dbg(&g->dev, "register_netdev failed, %d\n", status);
free_netdev(net);
dev = ERR_PTR(status);
} else {
INFO(dev, "MAC %pM\n", net->dev_addr);
INFO(dev, "HOST MAC %pM\n", dev->host_mac);
netif_carrier_off(net);
}
return dev;
}
struct net_device *gether_setup_name_default(const char *netname)
{
struct net_device *net;
struct eth_dev *dev;
net = alloc_etherdev(sizeof(*dev));
if (!net)
return ERR_PTR(-ENOMEM);
dev = netdev_priv(net);
spin_lock_init(&dev->lock);
spin_lock_init(&dev->req_lock);
INIT_WORK(&dev->work, eth_work);
INIT_LIST_HEAD(&dev->tx_reqs);
INIT_LIST_HEAD(&dev->rx_reqs);
skb_queue_head_init(&dev->rx_frames);
dev->net = net;
dev->qmult = QMULT_DEFAULT;
snprintf(net->name, sizeof(net->name), "%s%%d", netname);
eth_random_addr(dev->dev_mac);
pr_warn("using random %s ethernet address\n", "self");
eth_random_addr(dev->host_mac);
pr_warn("using random %s ethernet address\n", "host");
net->netdev_ops = &eth_netdev_ops;
net->ethtool_ops = &ops;
SET_NETDEV_DEVTYPE(net, &gadget_type);
return net;
}
int gether_register_netdev(struct net_device *net)
{
struct eth_dev *dev;
struct usb_gadget *g;
struct sockaddr sa;
int status;
if (!net->dev.parent)
return -EINVAL;
dev = netdev_priv(net);
g = dev->gadget;
status = register_netdev(net);
if (status < 0) {
dev_dbg(&g->dev, "register_netdev failed, %d\n", status);
return status;
} else {
INFO(dev, "HOST MAC %pM\n", dev->host_mac);
netif_carrier_off(net);
}
sa.sa_family = net->type;
memcpy(sa.sa_data, dev->dev_mac, ETH_ALEN);
rtnl_lock();
status = dev_set_mac_address(net, &sa);
rtnl_unlock();
if (status)
pr_warn("cannot set self ethernet address: %d\n", status);
else
INFO(dev, "MAC %pM\n", dev->dev_mac);
return status;
}
void gether_set_gadget(struct net_device *net, struct usb_gadget *g)
{
struct eth_dev *dev;
dev = netdev_priv(net);
dev->gadget = g;
SET_NETDEV_DEV(net, &g->dev);
}
int gether_set_dev_addr(struct net_device *net, const char *dev_addr)
{
struct eth_dev *dev;
u8 new_addr[ETH_ALEN];
dev = netdev_priv(net);
if (get_ether_addr(dev_addr, new_addr))
return -EINVAL;
memcpy(dev->dev_mac, new_addr, ETH_ALEN);
return 0;
}
int gether_get_dev_addr(struct net_device *net, char *dev_addr, int len)
{
struct eth_dev *dev;
dev = netdev_priv(net);
return get_ether_addr_str(dev->dev_mac, dev_addr, len);
}
int gether_set_host_addr(struct net_device *net, const char *host_addr)
{
struct eth_dev *dev;
u8 new_addr[ETH_ALEN];
dev = netdev_priv(net);
if (get_ether_addr(host_addr, new_addr))
return -EINVAL;
memcpy(dev->host_mac, new_addr, ETH_ALEN);
return 0;
}
int gether_get_host_addr(struct net_device *net, char *host_addr, int len)
{
struct eth_dev *dev;
dev = netdev_priv(net);
return get_ether_addr_str(dev->host_mac, host_addr, len);
}
int gether_get_host_addr_cdc(struct net_device *net, char *host_addr, int len)
{
struct eth_dev *dev;
if (len < 13)
return -EINVAL;
dev = netdev_priv(net);
snprintf(host_addr, len, "%pm", dev->host_mac);
return strlen(host_addr);
}
void gether_get_host_addr_u8(struct net_device *net, u8 host_mac[ETH_ALEN])
{
struct eth_dev *dev;
dev = netdev_priv(net);
memcpy(host_mac, dev->host_mac, ETH_ALEN);
}
void gether_set_qmult(struct net_device *net, unsigned qmult)
{
struct eth_dev *dev;
dev = netdev_priv(net);
dev->qmult = qmult;
}
unsigned gether_get_qmult(struct net_device *net)
{
struct eth_dev *dev;
dev = netdev_priv(net);
return dev->qmult;
}
int gether_get_ifname(struct net_device *net, char *name, int len)
{
rtnl_lock();
strlcpy(name, netdev_name(net), len);
rtnl_unlock();
return strlen(name);
}
void gether_cleanup(struct eth_dev *dev)
{
if (!dev)
return;
unregister_netdev(dev->net);
flush_work(&dev->work);
free_netdev(dev->net);
}
struct net_device *gether_connect(struct gether *link)
{
struct eth_dev *dev = link->ioport;
int result = 0;
if (!dev)
return ERR_PTR(-EINVAL);
link->in_ep->driver_data = dev;
result = usb_ep_enable(link->in_ep);
if (result != 0) {
DBG(dev, "enable %s --> %d\n",
link->in_ep->name, result);
goto fail0;
}
link->out_ep->driver_data = dev;
result = usb_ep_enable(link->out_ep);
if (result != 0) {
DBG(dev, "enable %s --> %d\n",
link->out_ep->name, result);
goto fail1;
}
if (result == 0)
result = alloc_requests(dev, link, qlen(dev->gadget,
dev->qmult));
if (result == 0) {
dev->zlp = link->is_zlp_ok;
DBG(dev, "qlen %d\n", qlen(dev->gadget, dev->qmult));
dev->header_len = link->header_len;
dev->unwrap = link->unwrap;
dev->wrap = link->wrap;
spin_lock(&dev->lock);
dev->port_usb = link;
if (netif_running(dev->net)) {
if (link->open)
link->open(link);
} else {
if (link->close)
link->close(link);
}
spin_unlock(&dev->lock);
netif_carrier_on(dev->net);
if (netif_running(dev->net))
eth_start(dev, GFP_ATOMIC);
} else {
(void) usb_ep_disable(link->out_ep);
fail1:
(void) usb_ep_disable(link->in_ep);
}
fail0:
if (result < 0)
return ERR_PTR(result);
return dev->net;
}
void gether_disconnect(struct gether *link)
{
struct eth_dev *dev = link->ioport;
struct usb_request *req;
WARN_ON(!dev);
if (!dev)
return;
DBG(dev, "%s\n", __func__);
netif_stop_queue(dev->net);
netif_carrier_off(dev->net);
usb_ep_disable(link->in_ep);
spin_lock(&dev->req_lock);
while (!list_empty(&dev->tx_reqs)) {
req = container_of(dev->tx_reqs.next,
struct usb_request, list);
list_del(&req->list);
spin_unlock(&dev->req_lock);
usb_ep_free_request(link->in_ep, req);
spin_lock(&dev->req_lock);
}
spin_unlock(&dev->req_lock);
link->in_ep->desc = NULL;
usb_ep_disable(link->out_ep);
spin_lock(&dev->req_lock);
while (!list_empty(&dev->rx_reqs)) {
req = container_of(dev->rx_reqs.next,
struct usb_request, list);
list_del(&req->list);
spin_unlock(&dev->req_lock);
usb_ep_free_request(link->out_ep, req);
spin_lock(&dev->req_lock);
}
spin_unlock(&dev->req_lock);
link->out_ep->desc = NULL;
dev->header_len = 0;
dev->unwrap = NULL;
dev->wrap = NULL;
spin_lock(&dev->lock);
dev->port_usb = NULL;
spin_unlock(&dev->lock);
}
