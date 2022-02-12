static int kaweth_control(struct kaweth_device *kaweth,
unsigned int pipe,
__u8 request,
__u8 requesttype,
__u16 value,
__u16 index,
void *data,
__u16 size,
int timeout)
{
struct usb_ctrlrequest *dr;
int retval;
dbg("kaweth_control()");
if(in_interrupt()) {
dbg("in_interrupt()");
return -EBUSY;
}
dr = kmalloc(sizeof(struct usb_ctrlrequest), GFP_ATOMIC);
if (!dr) {
dbg("kmalloc() failed");
return -ENOMEM;
}
dr->bRequestType = requesttype;
dr->bRequest = request;
dr->wValue = cpu_to_le16(value);
dr->wIndex = cpu_to_le16(index);
dr->wLength = cpu_to_le16(size);
retval = kaweth_internal_control_msg(kaweth->dev,
pipe,
dr,
data,
size,
timeout);
kfree(dr);
return retval;
}
static int kaweth_read_configuration(struct kaweth_device *kaweth)
{
int retval;
dbg("Reading kaweth configuration");
retval = kaweth_control(kaweth,
usb_rcvctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_GET_ETHERNET_DESC,
USB_TYPE_VENDOR | USB_DIR_IN | USB_RECIP_DEVICE,
0,
0,
(void *)&kaweth->configuration,
sizeof(kaweth->configuration),
KAWETH_CONTROL_TIMEOUT);
return retval;
}
static int kaweth_set_urb_size(struct kaweth_device *kaweth, __u16 urb_size)
{
int retval;
dbg("Setting URB size to %d", (unsigned)urb_size);
retval = kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SET_URB_SIZE,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
urb_size,
0,
(void *)&kaweth->scratch,
0,
KAWETH_CONTROL_TIMEOUT);
return retval;
}
static int kaweth_set_sofs_wait(struct kaweth_device *kaweth, __u16 sofs_wait)
{
int retval;
dbg("Set SOFS wait to %d", (unsigned)sofs_wait);
retval = kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SET_SOFS_WAIT,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
sofs_wait,
0,
(void *)&kaweth->scratch,
0,
KAWETH_CONTROL_TIMEOUT);
return retval;
}
static int kaweth_set_receive_filter(struct kaweth_device *kaweth,
__u16 receive_filter)
{
int retval;
dbg("Set receive filter to %d", (unsigned)receive_filter);
retval = kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SET_PACKET_FILTER,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
receive_filter,
0,
(void *)&kaweth->scratch,
0,
KAWETH_CONTROL_TIMEOUT);
return retval;
}
static int kaweth_download_firmware(struct kaweth_device *kaweth,
const char *fwname,
__u8 interrupt,
__u8 type)
{
const struct firmware *fw;
int data_len;
int ret;
ret = request_firmware(&fw, fwname, &kaweth->dev->dev);
if (ret) {
err("Firmware request failed\n");
return ret;
}
if (fw->size > KAWETH_FIRMWARE_BUF_SIZE) {
err("Firmware too big: %zu", fw->size);
release_firmware(fw);
return -ENOSPC;
}
data_len = fw->size;
memcpy(kaweth->firmware_buf, fw->data, fw->size);
release_firmware(fw);
kaweth->firmware_buf[2] = (data_len & 0xFF) - 7;
kaweth->firmware_buf[3] = data_len >> 8;
kaweth->firmware_buf[4] = type;
kaweth->firmware_buf[5] = interrupt;
dbg("High: %i, Low:%i", kaweth->firmware_buf[3],
kaweth->firmware_buf[2]);
dbg("Downloading firmware at %p to kaweth device at %p",
fw->data, kaweth);
dbg("Firmware length: %d", data_len);
return kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SCAN,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
0,
0,
(void *)kaweth->firmware_buf,
data_len,
KAWETH_CONTROL_TIMEOUT);
}
static int kaweth_trigger_firmware(struct kaweth_device *kaweth,
__u8 interrupt)
{
kaweth->firmware_buf[0] = 0xB6;
kaweth->firmware_buf[1] = 0xC3;
kaweth->firmware_buf[2] = 0x01;
kaweth->firmware_buf[3] = 0x00;
kaweth->firmware_buf[4] = 0x06;
kaweth->firmware_buf[5] = interrupt;
kaweth->firmware_buf[6] = 0x00;
kaweth->firmware_buf[7] = 0x00;
dbg("Triggering firmware");
return kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SCAN,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
0,
0,
(void *)kaweth->firmware_buf,
8,
KAWETH_CONTROL_TIMEOUT);
}
static int kaweth_reset(struct kaweth_device *kaweth)
{
int result;
dbg("kaweth_reset(%p)", kaweth);
result = usb_reset_configuration(kaweth->dev);
mdelay(10);
dbg("kaweth_reset() returns %d.",result);
return result;
}
static void kaweth_resubmit_int_urb(struct kaweth_device *kaweth, gfp_t mf)
{
int status;
status = usb_submit_urb (kaweth->irq_urb, mf);
if (unlikely(status == -ENOMEM)) {
kaweth->suspend_lowmem_ctrl = 1;
schedule_delayed_work(&kaweth->lowmem_work, HZ/4);
} else {
kaweth->suspend_lowmem_ctrl = 0;
}
if (status)
err ("can't resubmit intr, %s-%s, status %d",
kaweth->dev->bus->bus_name,
kaweth->dev->devpath, status);
}
static void int_callback(struct urb *u)
{
struct kaweth_device *kaweth = u->context;
int act_state;
int status = u->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
return;
default:
goto resubmit;
}
if (kaweth->linkstate != (act_state = ( kaweth->intbuffer[STATE_OFFSET] | STATE_MASK) >> STATE_SHIFT)) {
if (act_state)
netif_carrier_on(kaweth->net);
else
netif_carrier_off(kaweth->net);
kaweth->linkstate = act_state;
}
resubmit:
kaweth_resubmit_int_urb(kaweth, GFP_ATOMIC);
}
static void kaweth_resubmit_tl(struct work_struct *work)
{
struct kaweth_device *kaweth =
container_of(work, struct kaweth_device, lowmem_work.work);
if (IS_BLOCKED(kaweth->status))
return;
if (kaweth->suspend_lowmem_rx)
kaweth_resubmit_rx_urb(kaweth, GFP_NOIO);
if (kaweth->suspend_lowmem_ctrl)
kaweth_resubmit_int_urb(kaweth, GFP_NOIO);
}
static int kaweth_resubmit_rx_urb(struct kaweth_device *kaweth,
gfp_t mem_flags)
{
int result;
usb_fill_bulk_urb(kaweth->rx_urb,
kaweth->dev,
usb_rcvbulkpipe(kaweth->dev, 1),
kaweth->rx_buf,
KAWETH_BUF_SIZE,
kaweth_usb_receive,
kaweth);
kaweth->rx_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
kaweth->rx_urb->transfer_dma = kaweth->rxbufferhandle;
if((result = usb_submit_urb(kaweth->rx_urb, mem_flags))) {
if (result == -ENOMEM) {
kaweth->suspend_lowmem_rx = 1;
schedule_delayed_work(&kaweth->lowmem_work, HZ/4);
}
err("resubmitting rx_urb %d failed", result);
} else {
kaweth->suspend_lowmem_rx = 0;
}
return result;
}
static void kaweth_usb_receive(struct urb *urb)
{
struct kaweth_device *kaweth = urb->context;
struct net_device *net = kaweth->net;
int status = urb->status;
int count = urb->actual_length;
int count2 = urb->transfer_buffer_length;
__u16 pkt_len = le16_to_cpup((__le16 *)kaweth->rx_buf);
struct sk_buff *skb;
if (unlikely(status == -EPIPE)) {
kaweth->stats.rx_errors++;
kaweth->end = 1;
wake_up(&kaweth->term_wait);
dbg("Status was -EPIPE.");
return;
}
if (unlikely(status == -ECONNRESET || status == -ESHUTDOWN)) {
kaweth->end = 1;
wake_up(&kaweth->term_wait);
dbg("Status was -ECONNRESET or -ESHUTDOWN.");
return;
}
if (unlikely(status == -EPROTO || status == -ETIME ||
status == -EILSEQ)) {
kaweth->stats.rx_errors++;
dbg("Status was -EPROTO, -ETIME, or -EILSEQ.");
return;
}
if (unlikely(status == -EOVERFLOW)) {
kaweth->stats.rx_errors++;
dbg("Status was -EOVERFLOW.");
}
spin_lock(&kaweth->device_lock);
if (IS_BLOCKED(kaweth->status)) {
spin_unlock(&kaweth->device_lock);
return;
}
spin_unlock(&kaweth->device_lock);
if(status && status != -EREMOTEIO && count != 1) {
err("%s RX status: %d count: %d packet_len: %d",
net->name,
status,
count,
(int)pkt_len);
kaweth_resubmit_rx_urb(kaweth, GFP_ATOMIC);
return;
}
if(kaweth->net && (count > 2)) {
if(pkt_len > (count - 2)) {
err("Packet length too long for USB frame (pkt_len: %x, count: %x)",pkt_len, count);
err("Packet len & 2047: %x", pkt_len & 2047);
err("Count 2: %x", count2);
kaweth_resubmit_rx_urb(kaweth, GFP_ATOMIC);
return;
}
if(!(skb = dev_alloc_skb(pkt_len+2))) {
kaweth_resubmit_rx_urb(kaweth, GFP_ATOMIC);
return;
}
skb_reserve(skb, 2);
skb_copy_to_linear_data(skb, kaweth->rx_buf + 2, pkt_len);
skb_put(skb, pkt_len);
skb->protocol = eth_type_trans(skb, net);
netif_rx(skb);
kaweth->stats.rx_packets++;
kaweth->stats.rx_bytes += pkt_len;
}
kaweth_resubmit_rx_urb(kaweth, GFP_ATOMIC);
}
static int kaweth_open(struct net_device *net)
{
struct kaweth_device *kaweth = netdev_priv(net);
int res;
dbg("Opening network device.");
res = usb_autopm_get_interface(kaweth->intf);
if (res) {
err("Interface cannot be resumed.");
return -EIO;
}
res = kaweth_resubmit_rx_urb(kaweth, GFP_KERNEL);
if (res)
goto err_out;
usb_fill_int_urb(
kaweth->irq_urb,
kaweth->dev,
usb_rcvintpipe(kaweth->dev, 3),
kaweth->intbuffer,
INTBUFFERSIZE,
int_callback,
kaweth,
250);
kaweth->irq_urb->transfer_dma = kaweth->intbufferhandle;
kaweth->irq_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
res = usb_submit_urb(kaweth->irq_urb, GFP_KERNEL);
if (res) {
usb_kill_urb(kaweth->rx_urb);
goto err_out;
}
kaweth->opened = 1;
netif_start_queue(net);
kaweth_async_set_rx_mode(kaweth);
return 0;
err_out:
usb_autopm_put_interface(kaweth->intf);
return -EIO;
}
static void kaweth_kill_urbs(struct kaweth_device *kaweth)
{
usb_kill_urb(kaweth->irq_urb);
usb_kill_urb(kaweth->rx_urb);
usb_kill_urb(kaweth->tx_urb);
cancel_delayed_work_sync(&kaweth->lowmem_work);
usb_kill_urb(kaweth->irq_urb);
usb_kill_urb(kaweth->rx_urb);
}
static int kaweth_close(struct net_device *net)
{
struct kaweth_device *kaweth = netdev_priv(net);
netif_stop_queue(net);
kaweth->opened = 0;
kaweth->status |= KAWETH_STATUS_CLOSING;
kaweth_kill_urbs(kaweth);
kaweth->status &= ~KAWETH_STATUS_CLOSING;
usb_autopm_put_interface(kaweth->intf);
return 0;
}
static u32 kaweth_get_link(struct net_device *dev)
{
struct kaweth_device *kaweth = netdev_priv(dev);
return kaweth->linkstate;
}
static void kaweth_usb_transmit_complete(struct urb *urb)
{
struct kaweth_device *kaweth = urb->context;
struct sk_buff *skb = kaweth->tx_skb;
int status = urb->status;
if (unlikely(status != 0))
if (status != -ENOENT)
dbg("%s: TX status %d.", kaweth->net->name, status);
netif_wake_queue(kaweth->net);
dev_kfree_skb_irq(skb);
}
static netdev_tx_t kaweth_start_xmit(struct sk_buff *skb,
struct net_device *net)
{
struct kaweth_device *kaweth = netdev_priv(net);
__le16 *private_header;
int res;
spin_lock_irq(&kaweth->device_lock);
kaweth_async_set_rx_mode(kaweth);
netif_stop_queue(net);
if (IS_BLOCKED(kaweth->status)) {
goto skip;
}
if (skb_cloned(skb) || skb_headroom(skb) < 2) {
struct sk_buff *copied_skb;
copied_skb = skb_copy_expand(skb, 2, 0, GFP_ATOMIC);
dev_kfree_skb_irq(skb);
skb = copied_skb;
if (!copied_skb) {
kaweth->stats.tx_errors++;
netif_start_queue(net);
spin_unlock_irq(&kaweth->device_lock);
return NETDEV_TX_OK;
}
}
private_header = (__le16 *)__skb_push(skb, 2);
*private_header = cpu_to_le16(skb->len-2);
kaweth->tx_skb = skb;
usb_fill_bulk_urb(kaweth->tx_urb,
kaweth->dev,
usb_sndbulkpipe(kaweth->dev, 2),
private_header,
skb->len,
kaweth_usb_transmit_complete,
kaweth);
kaweth->end = 0;
if((res = usb_submit_urb(kaweth->tx_urb, GFP_ATOMIC)))
{
dev_warn(&net->dev, "kaweth failed tx_urb %d\n", res);
skip:
kaweth->stats.tx_errors++;
netif_start_queue(net);
dev_kfree_skb_irq(skb);
}
else
{
kaweth->stats.tx_packets++;
kaweth->stats.tx_bytes += skb->len;
}
spin_unlock_irq(&kaweth->device_lock);
return NETDEV_TX_OK;
}
static void kaweth_set_rx_mode(struct net_device *net)
{
struct kaweth_device *kaweth = netdev_priv(net);
__u16 packet_filter_bitmap = KAWETH_PACKET_FILTER_DIRECTED |
KAWETH_PACKET_FILTER_BROADCAST |
KAWETH_PACKET_FILTER_MULTICAST;
dbg("Setting Rx mode to %d", packet_filter_bitmap);
netif_stop_queue(net);
if (net->flags & IFF_PROMISC) {
packet_filter_bitmap |= KAWETH_PACKET_FILTER_PROMISCUOUS;
}
else if (!netdev_mc_empty(net) || (net->flags & IFF_ALLMULTI)) {
packet_filter_bitmap |= KAWETH_PACKET_FILTER_ALL_MULTICAST;
}
kaweth->packet_filter_bitmap = packet_filter_bitmap;
netif_wake_queue(net);
}
static void kaweth_async_set_rx_mode(struct kaweth_device *kaweth)
{
int result;
__u16 packet_filter_bitmap = kaweth->packet_filter_bitmap;
kaweth->packet_filter_bitmap = 0;
if (packet_filter_bitmap == 0)
return;
if (in_interrupt())
return;
result = kaweth_control(kaweth,
usb_sndctrlpipe(kaweth->dev, 0),
KAWETH_COMMAND_SET_PACKET_FILTER,
USB_TYPE_VENDOR | USB_DIR_OUT | USB_RECIP_DEVICE,
packet_filter_bitmap,
0,
(void *)&kaweth->scratch,
0,
KAWETH_CONTROL_TIMEOUT);
if(result < 0) {
err("Failed to set Rx mode: %d", result);
}
else {
dbg("Set Rx mode to %d", packet_filter_bitmap);
}
}
static struct net_device_stats *kaweth_netdev_stats(struct net_device *dev)
{
struct kaweth_device *kaweth = netdev_priv(dev);
return &kaweth->stats;
}
static void kaweth_tx_timeout(struct net_device *net)
{
struct kaweth_device *kaweth = netdev_priv(net);
dev_warn(&net->dev, "%s: Tx timed out. Resetting.\n", net->name);
kaweth->stats.tx_errors++;
net->trans_start = jiffies;
usb_unlink_urb(kaweth->tx_urb);
}
static int kaweth_suspend(struct usb_interface *intf, pm_message_t message)
{
struct kaweth_device *kaweth = usb_get_intfdata(intf);
unsigned long flags;
dbg("Suspending device");
spin_lock_irqsave(&kaweth->device_lock, flags);
kaweth->status |= KAWETH_STATUS_SUSPENDING;
spin_unlock_irqrestore(&kaweth->device_lock, flags);
kaweth_kill_urbs(kaweth);
return 0;
}
static int kaweth_resume(struct usb_interface *intf)
{
struct kaweth_device *kaweth = usb_get_intfdata(intf);
unsigned long flags;
dbg("Resuming device");
spin_lock_irqsave(&kaweth->device_lock, flags);
kaweth->status &= ~KAWETH_STATUS_SUSPENDING;
spin_unlock_irqrestore(&kaweth->device_lock, flags);
if (!kaweth->opened)
return 0;
kaweth_resubmit_rx_urb(kaweth, GFP_NOIO);
kaweth_resubmit_int_urb(kaweth, GFP_NOIO);
return 0;
}
static int kaweth_probe(
struct usb_interface *intf,
const struct usb_device_id *id
)
{
struct usb_device *dev = interface_to_usbdev(intf);
struct kaweth_device *kaweth;
struct net_device *netdev;
const eth_addr_t bcast_addr = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
int result = 0;
dbg("Kawasaki Device Probe (Device number:%d): 0x%4.4x:0x%4.4x:0x%4.4x",
dev->devnum,
le16_to_cpu(dev->descriptor.idVendor),
le16_to_cpu(dev->descriptor.idProduct),
le16_to_cpu(dev->descriptor.bcdDevice));
dbg("Device at %p", dev);
dbg("Descriptor length: %x type: %x",
(int)dev->descriptor.bLength,
(int)dev->descriptor.bDescriptorType);
netdev = alloc_etherdev(sizeof(*kaweth));
if (!netdev)
return -ENOMEM;
kaweth = netdev_priv(netdev);
kaweth->dev = dev;
kaweth->net = netdev;
spin_lock_init(&kaweth->device_lock);
init_waitqueue_head(&kaweth->term_wait);
dbg("Resetting.");
kaweth_reset(kaweth);
if (le16_to_cpu(dev->descriptor.bcdDevice) >> 8) {
dev_info(&intf->dev, "Firmware present in device.\n");
} else {
dev_info(&intf->dev, "Downloading firmware...\n");
kaweth->firmware_buf = (__u8 *)__get_free_page(GFP_KERNEL);
if ((result = kaweth_download_firmware(kaweth,
"kaweth/new_code.bin",
100,
2)) < 0) {
err("Error downloading firmware (%d)", result);
goto err_fw;
}
if ((result = kaweth_download_firmware(kaweth,
"kaweth/new_code_fix.bin",
100,
3)) < 0) {
err("Error downloading firmware fix (%d)", result);
goto err_fw;
}
if ((result = kaweth_download_firmware(kaweth,
"kaweth/trigger_code.bin",
126,
2)) < 0) {
err("Error downloading trigger code (%d)", result);
goto err_fw;
}
if ((result = kaweth_download_firmware(kaweth,
"kaweth/trigger_code_fix.bin",
126,
3)) < 0) {
err("Error downloading trigger code fix (%d)", result);
goto err_fw;
}
if ((result = kaweth_trigger_firmware(kaweth, 126)) < 0) {
err("Error triggering firmware (%d)", result);
goto err_fw;
}
dev_info(&intf->dev, "Firmware loaded. I'll be back...\n");
err_fw:
free_page((unsigned long)kaweth->firmware_buf);
free_netdev(netdev);
return -EIO;
}
result = kaweth_read_configuration(kaweth);
if(result < 0) {
err("Error reading configuration (%d), no net device created", result);
goto err_free_netdev;
}
dev_info(&intf->dev, "Statistics collection: %x\n", kaweth->configuration.statistics_mask);
dev_info(&intf->dev, "Multicast filter limit: %x\n", kaweth->configuration.max_multicast_filters & ((1 << 15) - 1));
dev_info(&intf->dev, "MTU: %d\n", le16_to_cpu(kaweth->configuration.segment_size));
dev_info(&intf->dev, "Read MAC address %pM\n", kaweth->configuration.hw_addr);
if(!memcmp(&kaweth->configuration.hw_addr,
&bcast_addr,
sizeof(bcast_addr))) {
err("Firmware not functioning properly, no net device created");
goto err_free_netdev;
}
if(kaweth_set_urb_size(kaweth, KAWETH_BUF_SIZE) < 0) {
dbg("Error setting URB size");
goto err_free_netdev;
}
if(kaweth_set_sofs_wait(kaweth, KAWETH_SOFS_TO_WAIT) < 0) {
err("Error setting SOFS wait");
goto err_free_netdev;
}
result = kaweth_set_receive_filter(kaweth,
KAWETH_PACKET_FILTER_DIRECTED |
KAWETH_PACKET_FILTER_BROADCAST |
KAWETH_PACKET_FILTER_MULTICAST);
if(result < 0) {
err("Error setting receive filter");
goto err_free_netdev;
}
dbg("Initializing net device.");
kaweth->intf = intf;
kaweth->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!kaweth->tx_urb)
goto err_free_netdev;
kaweth->rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!kaweth->rx_urb)
goto err_only_tx;
kaweth->irq_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!kaweth->irq_urb)
goto err_tx_and_rx;
kaweth->intbuffer = usb_alloc_coherent( kaweth->dev,
INTBUFFERSIZE,
GFP_KERNEL,
&kaweth->intbufferhandle);
if (!kaweth->intbuffer)
goto err_tx_and_rx_and_irq;
kaweth->rx_buf = usb_alloc_coherent( kaweth->dev,
KAWETH_BUF_SIZE,
GFP_KERNEL,
&kaweth->rxbufferhandle);
if (!kaweth->rx_buf)
goto err_all_but_rxbuf;
memcpy(netdev->broadcast, &bcast_addr, sizeof(bcast_addr));
memcpy(netdev->dev_addr, &kaweth->configuration.hw_addr,
sizeof(kaweth->configuration.hw_addr));
netdev->netdev_ops = &kaweth_netdev_ops;
netdev->watchdog_timeo = KAWETH_TX_TIMEOUT;
netdev->mtu = le16_to_cpu(kaweth->configuration.segment_size);
SET_ETHTOOL_OPS(netdev, &ops);
INIT_DELAYED_WORK(&kaweth->lowmem_work, kaweth_resubmit_tl);
usb_set_intfdata(intf, kaweth);
#if 0
if (dma_supported (&intf->dev, 0xffffffffffffffffULL))
kaweth->net->features |= NETIF_F_HIGHDMA;
#endif
SET_NETDEV_DEV(netdev, &intf->dev);
if (register_netdev(netdev) != 0) {
err("Error registering netdev.");
goto err_intfdata;
}
dev_info(&intf->dev, "kaweth interface created at %s\n",
kaweth->net->name);
dbg("Kaweth probe returning.");
return 0;
err_intfdata:
usb_set_intfdata(intf, NULL);
usb_free_coherent(kaweth->dev, KAWETH_BUF_SIZE, (void *)kaweth->rx_buf, kaweth->rxbufferhandle);
err_all_but_rxbuf:
usb_free_coherent(kaweth->dev, INTBUFFERSIZE, (void *)kaweth->intbuffer, kaweth->intbufferhandle);
err_tx_and_rx_and_irq:
usb_free_urb(kaweth->irq_urb);
err_tx_and_rx:
usb_free_urb(kaweth->rx_urb);
err_only_tx:
usb_free_urb(kaweth->tx_urb);
err_free_netdev:
free_netdev(netdev);
return -EIO;
}
static void kaweth_disconnect(struct usb_interface *intf)
{
struct kaweth_device *kaweth = usb_get_intfdata(intf);
struct net_device *netdev;
dev_info(&intf->dev, "Unregistering\n");
usb_set_intfdata(intf, NULL);
if (!kaweth) {
dev_warn(&intf->dev, "unregistering non-existent device\n");
return;
}
netdev = kaweth->net;
dbg("Unregistering net device");
unregister_netdev(netdev);
usb_free_urb(kaweth->rx_urb);
usb_free_urb(kaweth->tx_urb);
usb_free_urb(kaweth->irq_urb);
usb_free_coherent(kaweth->dev, KAWETH_BUF_SIZE, (void *)kaweth->rx_buf, kaweth->rxbufferhandle);
usb_free_coherent(kaweth->dev, INTBUFFERSIZE, (void *)kaweth->intbuffer, kaweth->intbufferhandle);
free_netdev(netdev);
}
static void usb_api_blocking_completion(struct urb *urb)
{
struct usb_api_data *awd = (struct usb_api_data *)urb->context;
awd->done=1;
wake_up(&awd->wqh);
}
static int usb_start_wait_urb(struct urb *urb, int timeout, int* actual_length)
{
struct usb_api_data awd;
int status;
init_waitqueue_head(&awd.wqh);
awd.done = 0;
urb->context = &awd;
status = usb_submit_urb(urb, GFP_NOIO);
if (status) {
usb_free_urb(urb);
return status;
}
if (!wait_event_timeout(awd.wqh, awd.done, timeout)) {
dev_warn(&urb->dev->dev, "usb_control/bulk_msg: timeout\n");
usb_kill_urb(urb);
status = -ETIMEDOUT;
}
else {
status = urb->status;
}
if (actual_length) {
*actual_length = urb->actual_length;
}
usb_free_urb(urb);
return status;
}
static int kaweth_internal_control_msg(struct usb_device *usb_dev,
unsigned int pipe,
struct usb_ctrlrequest *cmd, void *data,
int len, int timeout)
{
struct urb *urb;
int retv;
int length = 0;
urb = usb_alloc_urb(0, GFP_NOIO);
if (!urb)
return -ENOMEM;
usb_fill_control_urb(urb, usb_dev, pipe, (unsigned char*)cmd, data,
len, usb_api_blocking_completion, NULL);
retv = usb_start_wait_urb(urb, timeout, &length);
if (retv < 0) {
return retv;
}
else {
return length;
}
}
