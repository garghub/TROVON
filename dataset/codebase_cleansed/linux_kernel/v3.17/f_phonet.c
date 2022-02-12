static inline struct f_phonet *func_to_pn(struct usb_function *f)
{
return container_of(f, struct f_phonet, function);
}
static int pn_net_open(struct net_device *dev)
{
netif_wake_queue(dev);
return 0;
}
static int pn_net_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static void pn_tx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_phonet *fp = ep->driver_data;
struct net_device *dev = fp->dev;
struct sk_buff *skb = req->context;
switch (req->status) {
case 0:
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
break;
case -ESHUTDOWN:
case -ECONNRESET:
dev->stats.tx_aborted_errors++;
default:
dev->stats.tx_errors++;
}
dev_kfree_skb_any(skb);
netif_wake_queue(dev);
}
static int pn_net_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct phonet_port *port = netdev_priv(dev);
struct f_phonet *fp;
struct usb_request *req;
unsigned long flags;
if (skb->protocol != htons(ETH_P_PHONET))
goto out;
spin_lock_irqsave(&port->lock, flags);
fp = port->usb;
if (unlikely(!fp))
goto out_unlock;
req = fp->in_req;
req->buf = skb->data;
req->length = skb->len;
req->complete = pn_tx_complete;
req->zero = 1;
req->context = skb;
if (unlikely(usb_ep_queue(fp->in_ep, req, GFP_ATOMIC)))
goto out_unlock;
netif_stop_queue(dev);
skb = NULL;
out_unlock:
spin_unlock_irqrestore(&port->lock, flags);
out:
if (unlikely(skb)) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
}
return NETDEV_TX_OK;
}
static int pn_net_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < PHONET_MIN_MTU) || (new_mtu > PHONET_MAX_MTU))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void pn_net_setup(struct net_device *dev)
{
dev->features = 0;
dev->type = ARPHRD_PHONET;
dev->flags = IFF_POINTOPOINT | IFF_NOARP;
dev->mtu = PHONET_DEV_MTU;
dev->hard_header_len = 1;
dev->dev_addr[0] = PN_MEDIA_USB;
dev->addr_len = 1;
dev->tx_queue_len = 1;
dev->netdev_ops = &pn_netdev_ops;
dev->destructor = free_netdev;
dev->header_ops = &phonet_header_ops;
}
static int
pn_rx_submit(struct f_phonet *fp, struct usb_request *req, gfp_t gfp_flags)
{
struct page *page;
int err;
page = __skb_alloc_page(gfp_flags | __GFP_NOMEMALLOC, NULL);
if (!page)
return -ENOMEM;
req->buf = page_address(page);
req->length = PAGE_SIZE;
req->context = page;
err = usb_ep_queue(fp->out_ep, req, gfp_flags);
if (unlikely(err))
put_page(page);
return err;
}
static void pn_rx_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_phonet *fp = ep->driver_data;
struct net_device *dev = fp->dev;
struct page *page = req->context;
struct sk_buff *skb;
unsigned long flags;
int status = req->status;
switch (status) {
case 0:
spin_lock_irqsave(&fp->rx.lock, flags);
skb = fp->rx.skb;
if (!skb)
skb = fp->rx.skb = netdev_alloc_skb(dev, 12);
if (req->actual < req->length)
fp->rx.skb = NULL;
spin_unlock_irqrestore(&fp->rx.lock, flags);
if (unlikely(!skb))
break;
if (skb->len == 0) {
skb->protocol = htons(ETH_P_PHONET);
skb_reset_mac_header(skb);
memcpy(skb_put(skb, 1), page_address(page), 1);
}
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
skb->len <= 1, req->actual, PAGE_SIZE);
page = NULL;
if (req->actual < req->length) {
skb->dev = dev;
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
netif_rx(skb);
}
break;
case -ESHUTDOWN:
case -ECONNABORTED:
case -ECONNRESET:
req = NULL;
break;
case -EOVERFLOW:
dev->stats.rx_over_errors++;
default:
dev->stats.rx_errors++;
break;
}
if (page)
put_page(page);
if (req)
pn_rx_submit(fp, req, GFP_ATOMIC | __GFP_COLD);
}
static void __pn_reset(struct usb_function *f)
{
struct f_phonet *fp = func_to_pn(f);
struct net_device *dev = fp->dev;
struct phonet_port *port = netdev_priv(dev);
netif_carrier_off(dev);
port->usb = NULL;
usb_ep_disable(fp->out_ep);
usb_ep_disable(fp->in_ep);
if (fp->rx.skb) {
dev_kfree_skb_irq(fp->rx.skb);
fp->rx.skb = NULL;
}
}
static int pn_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_phonet *fp = func_to_pn(f);
struct usb_gadget *gadget = fp->function.config->cdev->gadget;
if (intf == pn_control_intf_desc.bInterfaceNumber)
return (alt > 0) ? -EINVAL : 0;
if (intf == pn_data_intf_desc.bInterfaceNumber) {
struct net_device *dev = fp->dev;
struct phonet_port *port = netdev_priv(dev);
if (alt > 1)
return -EINVAL;
spin_lock(&port->lock);
__pn_reset(f);
if (alt == 1) {
int i;
if (config_ep_by_speed(gadget, f, fp->in_ep) ||
config_ep_by_speed(gadget, f, fp->out_ep)) {
fp->in_ep->desc = NULL;
fp->out_ep->desc = NULL;
spin_unlock(&port->lock);
return -EINVAL;
}
usb_ep_enable(fp->out_ep);
usb_ep_enable(fp->in_ep);
port->usb = fp;
fp->out_ep->driver_data = fp;
fp->in_ep->driver_data = fp;
netif_carrier_on(dev);
for (i = 0; i < phonet_rxq_size; i++)
pn_rx_submit(fp, fp->out_reqv[i], GFP_ATOMIC | __GFP_COLD);
}
spin_unlock(&port->lock);
return 0;
}
return -EINVAL;
}
static int pn_get_alt(struct usb_function *f, unsigned intf)
{
struct f_phonet *fp = func_to_pn(f);
if (intf == pn_control_intf_desc.bInterfaceNumber)
return 0;
if (intf == pn_data_intf_desc.bInterfaceNumber) {
struct phonet_port *port = netdev_priv(fp->dev);
u8 alt;
spin_lock(&port->lock);
alt = port->usb != NULL;
spin_unlock(&port->lock);
return alt;
}
return -EINVAL;
}
static void pn_disconnect(struct usb_function *f)
{
struct f_phonet *fp = func_to_pn(f);
struct phonet_port *port = netdev_priv(fp->dev);
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
__pn_reset(f);
spin_unlock_irqrestore(&port->lock, flags);
}
static int pn_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct usb_gadget *gadget = cdev->gadget;
struct f_phonet *fp = func_to_pn(f);
struct usb_ep *ep;
int status, i;
struct f_phonet_opts *phonet_opts;
phonet_opts = container_of(f->fi, struct f_phonet_opts, func_inst);
if (!phonet_opts->bound) {
gphonet_set_gadget(phonet_opts->net, gadget);
status = gphonet_register_netdev(phonet_opts->net);
if (status)
return status;
phonet_opts->bound = true;
}
status = usb_interface_id(c, f);
if (status < 0)
goto err;
pn_control_intf_desc.bInterfaceNumber = status;
pn_union_desc.bMasterInterface0 = status;
status = usb_interface_id(c, f);
if (status < 0)
goto err;
pn_data_nop_intf_desc.bInterfaceNumber = status;
pn_data_intf_desc.bInterfaceNumber = status;
pn_union_desc.bSlaveInterface0 = status;
status = -ENODEV;
ep = usb_ep_autoconfig(gadget, &pn_fs_sink_desc);
if (!ep)
goto err;
fp->out_ep = ep;
ep->driver_data = fp;
ep = usb_ep_autoconfig(gadget, &pn_fs_source_desc);
if (!ep)
goto err;
fp->in_ep = ep;
ep->driver_data = fp;
pn_hs_sink_desc.bEndpointAddress = pn_fs_sink_desc.bEndpointAddress;
pn_hs_source_desc.bEndpointAddress = pn_fs_source_desc.bEndpointAddress;
status = usb_assign_descriptors(f, fs_pn_function, hs_pn_function,
NULL);
if (status)
goto err;
status = -ENOMEM;
for (i = 0; i < phonet_rxq_size; i++) {
struct usb_request *req;
req = usb_ep_alloc_request(fp->out_ep, GFP_KERNEL);
if (!req)
goto err_req;
req->complete = pn_rx_complete;
fp->out_reqv[i] = req;
}
fp->in_req = usb_ep_alloc_request(fp->in_ep, GFP_KERNEL);
if (!fp->in_req)
goto err_req;
INFO(cdev, "USB CDC Phonet function\n");
INFO(cdev, "using %s, OUT %s, IN %s\n", cdev->gadget->name,
fp->out_ep->name, fp->in_ep->name);
return 0;
err_req:
for (i = 0; i < phonet_rxq_size && fp->out_reqv[i]; i++)
usb_ep_free_request(fp->out_ep, fp->out_reqv[i]);
err:
usb_free_all_descriptors(f);
if (fp->out_ep)
fp->out_ep->driver_data = NULL;
if (fp->in_ep)
fp->in_ep->driver_data = NULL;
ERROR(cdev, "USB CDC Phonet: cannot autoconfigure\n");
return status;
}
static inline struct f_phonet_opts *to_f_phonet_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_phonet_opts,
func_inst.group);
}
static ssize_t f_phonet_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
struct f_phonet_opts *opts = to_f_phonet_opts(item);
struct f_phonet_opts_attribute *f_phonet_opts_attr =
container_of(attr, struct f_phonet_opts_attribute, attr);
ssize_t ret = 0;
if (f_phonet_opts_attr->show)
ret = f_phonet_opts_attr->show(opts, page);
return ret;
}
static void phonet_attr_release(struct config_item *item)
{
struct f_phonet_opts *opts = to_f_phonet_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static ssize_t f_phonet_ifname_show(struct f_phonet_opts *opts, char *page)
{
return gether_get_ifname(opts->net, page, PAGE_SIZE);
}
static void phonet_free_inst(struct usb_function_instance *f)
{
struct f_phonet_opts *opts;
opts = container_of(f, struct f_phonet_opts, func_inst);
if (opts->bound)
gphonet_cleanup(opts->net);
else
free_netdev(opts->net);
kfree(opts);
}
static struct usb_function_instance *phonet_alloc_inst(void)
{
struct f_phonet_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.free_func_inst = phonet_free_inst;
opts->net = gphonet_setup_default();
if (IS_ERR(opts->net)) {
struct net_device *net = opts->net;
kfree(opts);
return ERR_CAST(net);
}
config_group_init_type_name(&opts->func_inst.group, "",
&phonet_func_type);
return &opts->func_inst;
}
static void phonet_free(struct usb_function *f)
{
struct f_phonet *phonet;
phonet = func_to_pn(f);
kfree(phonet);
}
static void pn_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_phonet *fp = func_to_pn(f);
int i;
if (fp->in_req)
usb_ep_free_request(fp->in_ep, fp->in_req);
for (i = 0; i < phonet_rxq_size; i++)
if (fp->out_reqv[i])
usb_ep_free_request(fp->out_ep, fp->out_reqv[i]);
usb_free_all_descriptors(f);
}
static struct usb_function *phonet_alloc(struct usb_function_instance *fi)
{
struct f_phonet *fp;
struct f_phonet_opts *opts;
int size;
size = sizeof(*fp) + (phonet_rxq_size * sizeof(struct usb_request *));
fp = kzalloc(size, GFP_KERNEL);
if (!fp)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_phonet_opts, func_inst);
fp->dev = opts->net;
fp->function.name = "phonet";
fp->function.bind = pn_bind;
fp->function.unbind = pn_unbind;
fp->function.set_alt = pn_set_alt;
fp->function.get_alt = pn_get_alt;
fp->function.disable = pn_disconnect;
fp->function.free_func = phonet_free;
spin_lock_init(&fp->rx.lock);
return &fp->function;
}
struct net_device *gphonet_setup_default(void)
{
struct net_device *dev;
struct phonet_port *port;
dev = alloc_netdev(sizeof(*port), "upnlink%d", NET_NAME_UNKNOWN,
pn_net_setup);
if (!dev)
return ERR_PTR(-ENOMEM);
port = netdev_priv(dev);
spin_lock_init(&port->lock);
netif_carrier_off(dev);
return dev;
}
void gphonet_set_gadget(struct net_device *net, struct usb_gadget *g)
{
SET_NETDEV_DEV(net, &g->dev);
}
int gphonet_register_netdev(struct net_device *net)
{
int status;
status = register_netdev(net);
if (status)
free_netdev(net);
return status;
}
void gphonet_cleanup(struct net_device *dev)
{
unregister_netdev(dev);
}
