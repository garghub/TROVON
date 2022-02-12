static int cx82310_cmd(struct usbnet *dev, enum cx82310_cmd cmd, bool reply,
u8 *wdata, int wlen, u8 *rdata, int rlen)
{
int actual_len, retries, ret;
struct usb_device *udev = dev->udev;
u8 *buf = kzalloc(CMD_PACKET_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
buf[0] = cmd;
if (wdata)
memcpy(buf + 4, wdata, min_t(int, wlen, CMD_PACKET_SIZE - 4));
ret = usb_bulk_msg(udev, usb_sndbulkpipe(udev, CMD_EP), buf,
CMD_PACKET_SIZE, &actual_len, CMD_TIMEOUT);
if (ret < 0) {
if (cmd != CMD_GET_LINK_STATUS)
dev_err(&dev->udev->dev, "send command %#x: error %d\n",
cmd, ret);
goto end;
}
if (reply) {
for (retries = 0; retries < CMD_REPLY_RETRY; retries++) {
ret = usb_bulk_msg(udev, usb_rcvbulkpipe(udev, CMD_EP),
buf, CMD_PACKET_SIZE, &actual_len,
CMD_TIMEOUT);
if (ret < 0) {
if (cmd != CMD_GET_LINK_STATUS)
dev_err(&dev->udev->dev,
"reply receive error %d\n",
ret);
goto end;
}
if (actual_len > 0)
break;
}
if (actual_len == 0) {
dev_err(&dev->udev->dev, "no reply to command %#x\n",
cmd);
ret = -EIO;
goto end;
}
if (buf[0] != cmd) {
dev_err(&dev->udev->dev,
"got reply to command %#x, expected: %#x\n",
buf[0], cmd);
ret = -EIO;
goto end;
}
if (buf[1] != STATUS_SUCCESS) {
dev_err(&dev->udev->dev, "command %#x failed: %#x\n",
cmd, buf[1]);
ret = -EIO;
goto end;
}
if (rdata)
memcpy(rdata, buf + 4,
min_t(int, rlen, CMD_PACKET_SIZE - 4));
}
end:
kfree(buf);
return ret;
}
static int cx82310_bind(struct usbnet *dev, struct usb_interface *intf)
{
int ret;
char buf[15];
struct usb_device *udev = dev->udev;
u8 link[3];
int timeout = 50;
if (usb_string(udev, udev->descriptor.iProduct, buf, sizeof(buf)) > 0
&& strcmp(buf, "USB NET CARD")) {
dev_info(&udev->dev, "ignoring: probably an ADSL modem\n");
return -ENODEV;
}
ret = usbnet_get_endpoints(dev, intf);
if (ret)
return ret;
dev->net->hard_header_len = 0;
dev->hard_mtu = CX82310_MTU + 2;
dev->rx_urb_size = 4096;
dev->partial_data = (unsigned long) kmalloc(dev->hard_mtu, GFP_KERNEL);
if (!dev->partial_data)
return -ENOMEM;
while (--timeout) {
ret = cx82310_cmd(dev, CMD_GET_LINK_STATUS, true, NULL, 0,
link, sizeof(link));
if (!ret && link[0] == 1 && link[2] == 1)
break;
msleep(500);
}
if (!timeout) {
dev_err(&udev->dev, "firmware not ready in time\n");
return -ETIMEDOUT;
}
ret = cx82310_cmd(dev, CMD_ETHERNET_MODE, true, "\x01", 1, NULL, 0);
if (ret) {
dev_err(&udev->dev, "unable to enable ethernet mode: %d\n",
ret);
goto err;
}
ret = cx82310_cmd(dev, CMD_GET_MAC_ADDR, true, NULL, 0,
dev->net->dev_addr, ETH_ALEN);
if (ret) {
dev_err(&udev->dev, "unable to read MAC address: %d\n", ret);
goto err;
}
ret = cx82310_cmd(dev, CMD_START, false, NULL, 0, NULL, 0);
if (ret)
goto err;
return 0;
err:
kfree((void *)dev->partial_data);
return ret;
}
static void cx82310_unbind(struct usbnet *dev, struct usb_interface *intf)
{
kfree((void *)dev->partial_data);
}
static int cx82310_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
int len;
struct sk_buff *skb2;
if (dev->partial_rem) {
len = dev->partial_len + dev->partial_rem;
skb2 = alloc_skb(len, GFP_ATOMIC);
if (!skb2)
return 0;
skb_put(skb2, len);
memcpy(skb2->data, (void *)dev->partial_data,
dev->partial_len);
memcpy(skb2->data + dev->partial_len, skb->data,
dev->partial_rem);
usbnet_skb_return(dev, skb2);
skb_pull(skb, (dev->partial_rem + 1) & ~1);
dev->partial_rem = 0;
if (skb->len < 2)
return 1;
}
while (skb->len > 1) {
len = skb->data[0] | (skb->data[1] << 8);
skb_pull(skb, 2);
if (len == skb->len || len + 1 == skb->len) {
skb_trim(skb, len);
break;
}
if (len > CX82310_MTU) {
dev_err(&dev->udev->dev, "RX packet too long: %d B\n",
len);
return 0;
}
if (len > skb->len) {
dev->partial_len = skb->len;
dev->partial_rem = len - skb->len;
memcpy((void *)dev->partial_data, skb->data,
dev->partial_len);
skb_pull(skb, skb->len);
break;
}
skb2 = alloc_skb(len, GFP_ATOMIC);
if (!skb2)
return 0;
skb_put(skb2, len);
memcpy(skb2->data, skb->data, len);
usbnet_skb_return(dev, skb2);
skb_pull(skb, (len + 1) & ~1);
}
return 1;
}
static struct sk_buff *cx82310_tx_fixup(struct usbnet *dev, struct sk_buff *skb,
gfp_t flags)
{
int len = skb->len;
if (skb_cow_head(skb, 2)) {
dev_kfree_skb_any(skb);
return NULL;
}
skb_push(skb, 2);
skb->data[0] = len;
skb->data[1] = len >> 8;
return skb;
}
