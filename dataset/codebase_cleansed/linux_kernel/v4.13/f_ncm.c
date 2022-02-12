static inline struct f_ncm *func_to_ncm(struct usb_function *f)
{
return container_of(f, struct f_ncm, port.func);
}
static inline unsigned ncm_bitrate(struct usb_gadget *g)
{
if (gadget_is_superspeed(g) && g->speed == USB_SPEED_SUPER)
return 13 * 1024 * 8 * 1000 * 8;
else if (gadget_is_dualspeed(g) && g->speed == USB_SPEED_HIGH)
return 13 * 512 * 8 * 1000 * 8;
else
return 19 * 64 * 1 * 1000 * 8;
}
static inline void put_ncm(__le16 **p, unsigned size, unsigned val)
{
switch (size) {
case 1:
put_unaligned_le16((u16)val, *p);
break;
case 2:
put_unaligned_le32((u32)val, *p);
break;
default:
BUG();
}
*p += size;
}
static inline unsigned get_ncm(__le16 **p, unsigned size)
{
unsigned tmp;
switch (size) {
case 1:
tmp = get_unaligned_le16(*p);
break;
case 2:
tmp = get_unaligned_le32(*p);
break;
default:
BUG();
}
*p += size;
return tmp;
}
static inline void ncm_reset_values(struct f_ncm *ncm)
{
ncm->parser_opts = &ndp16_opts;
ncm->is_crc = false;
ncm->port.cdc_filter = DEFAULT_FILTER;
ncm->port.header_len = 0;
ncm->port.fixed_out_len = le32_to_cpu(ntb_parameters.dwNtbOutMaxSize);
ncm->port.fixed_in_len = NTB_DEFAULT_IN_SIZE;
}
static void ncm_do_notify(struct f_ncm *ncm)
{
struct usb_request *req = ncm->notify_req;
struct usb_cdc_notification *event;
struct usb_composite_dev *cdev = ncm->port.func.config->cdev;
__le32 *data;
int status;
if (!req)
return;
event = req->buf;
switch (ncm->notify_state) {
case NCM_NOTIFY_NONE:
return;
case NCM_NOTIFY_CONNECT:
event->bNotificationType = USB_CDC_NOTIFY_NETWORK_CONNECTION;
if (ncm->is_open)
event->wValue = cpu_to_le16(1);
else
event->wValue = cpu_to_le16(0);
event->wLength = 0;
req->length = sizeof *event;
DBG(cdev, "notify connect %s\n",
ncm->is_open ? "true" : "false");
ncm->notify_state = NCM_NOTIFY_NONE;
break;
case NCM_NOTIFY_SPEED:
event->bNotificationType = USB_CDC_NOTIFY_SPEED_CHANGE;
event->wValue = cpu_to_le16(0);
event->wLength = cpu_to_le16(8);
req->length = NCM_STATUS_BYTECOUNT;
data = req->buf + sizeof *event;
data[0] = cpu_to_le32(ncm_bitrate(cdev->gadget));
data[1] = data[0];
DBG(cdev, "notify speed %d\n", ncm_bitrate(cdev->gadget));
ncm->notify_state = NCM_NOTIFY_CONNECT;
break;
}
event->bmRequestType = 0xA1;
event->wIndex = cpu_to_le16(ncm->ctrl_id);
ncm->notify_req = NULL;
spin_unlock(&ncm->lock);
status = usb_ep_queue(ncm->notify, req, GFP_ATOMIC);
spin_lock(&ncm->lock);
if (status < 0) {
ncm->notify_req = req;
DBG(cdev, "notify --> %d\n", status);
}
}
static void ncm_notify(struct f_ncm *ncm)
{
ncm->notify_state = NCM_NOTIFY_SPEED;
ncm_do_notify(ncm);
}
static void ncm_notify_complete(struct usb_ep *ep, struct usb_request *req)
{
struct f_ncm *ncm = req->context;
struct usb_composite_dev *cdev = ncm->port.func.config->cdev;
struct usb_cdc_notification *event = req->buf;
spin_lock(&ncm->lock);
switch (req->status) {
case 0:
VDBG(cdev, "Notification %02x sent\n",
event->bNotificationType);
break;
case -ECONNRESET:
case -ESHUTDOWN:
ncm->notify_state = NCM_NOTIFY_NONE;
break;
default:
DBG(cdev, "event %02x --> %d\n",
event->bNotificationType, req->status);
break;
}
ncm->notify_req = req;
ncm_do_notify(ncm);
spin_unlock(&ncm->lock);
}
static void ncm_ep0out_complete(struct usb_ep *ep, struct usb_request *req)
{
unsigned in_size;
struct usb_function *f = req->context;
struct f_ncm *ncm = func_to_ncm(f);
struct usb_composite_dev *cdev = f->config->cdev;
req->context = NULL;
if (req->status || req->actual != req->length) {
DBG(cdev, "Bad control-OUT transfer\n");
goto invalid;
}
in_size = get_unaligned_le32(req->buf);
if (in_size < USB_CDC_NCM_NTB_MIN_IN_SIZE ||
in_size > le32_to_cpu(ntb_parameters.dwNtbInMaxSize)) {
DBG(cdev, "Got wrong INPUT SIZE (%d) from host\n", in_size);
goto invalid;
}
ncm->port.fixed_in_len = in_size;
VDBG(cdev, "Set NTB INPUT SIZE %d\n", in_size);
return;
invalid:
usb_ep_set_halt(ep);
return;
}
static int ncm_setup(struct usb_function *f, const struct usb_ctrlrequest *ctrl)
{
struct f_ncm *ncm = func_to_ncm(f);
struct usb_composite_dev *cdev = f->config->cdev;
struct usb_request *req = cdev->req;
int value = -EOPNOTSUPP;
u16 w_index = le16_to_cpu(ctrl->wIndex);
u16 w_value = le16_to_cpu(ctrl->wValue);
u16 w_length = le16_to_cpu(ctrl->wLength);
switch ((ctrl->bRequestType << 8) | ctrl->bRequest) {
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_SET_ETHERNET_PACKET_FILTER:
if (w_length != 0 || w_index != ncm->ctrl_id)
goto invalid;
DBG(cdev, "packet filter %02x\n", w_value);
ncm->port.cdc_filter = w_value;
value = 0;
break;
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_GET_NTB_PARAMETERS:
if (w_length == 0 || w_value != 0 || w_index != ncm->ctrl_id)
goto invalid;
value = w_length > sizeof ntb_parameters ?
sizeof ntb_parameters : w_length;
memcpy(req->buf, &ntb_parameters, value);
VDBG(cdev, "Host asked NTB parameters\n");
break;
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_GET_NTB_INPUT_SIZE:
if (w_length < 4 || w_value != 0 || w_index != ncm->ctrl_id)
goto invalid;
put_unaligned_le32(ncm->port.fixed_in_len, req->buf);
value = 4;
VDBG(cdev, "Host asked INPUT SIZE, sending %d\n",
ncm->port.fixed_in_len);
break;
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_SET_NTB_INPUT_SIZE:
{
if (w_length != 4 || w_value != 0 || w_index != ncm->ctrl_id)
goto invalid;
req->complete = ncm_ep0out_complete;
req->length = w_length;
req->context = f;
value = req->length;
break;
}
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_GET_NTB_FORMAT:
{
uint16_t format;
if (w_length < 2 || w_value != 0 || w_index != ncm->ctrl_id)
goto invalid;
format = (ncm->parser_opts == &ndp16_opts) ? 0x0000 : 0x0001;
put_unaligned_le16(format, req->buf);
value = 2;
VDBG(cdev, "Host asked NTB FORMAT, sending %d\n", format);
break;
}
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_SET_NTB_FORMAT:
{
if (w_length != 0 || w_index != ncm->ctrl_id)
goto invalid;
switch (w_value) {
case 0x0000:
ncm->parser_opts = &ndp16_opts;
DBG(cdev, "NCM16 selected\n");
break;
case 0x0001:
ncm->parser_opts = &ndp32_opts;
DBG(cdev, "NCM32 selected\n");
break;
default:
goto invalid;
}
value = 0;
break;
}
case ((USB_DIR_IN | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_GET_CRC_MODE:
{
uint16_t is_crc;
if (w_length < 2 || w_value != 0 || w_index != ncm->ctrl_id)
goto invalid;
is_crc = ncm->is_crc ? 0x0001 : 0x0000;
put_unaligned_le16(is_crc, req->buf);
value = 2;
VDBG(cdev, "Host asked CRC MODE, sending %d\n", is_crc);
break;
}
case ((USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE) << 8)
| USB_CDC_SET_CRC_MODE:
{
int ndp_hdr_crc = 0;
if (w_length != 0 || w_index != ncm->ctrl_id)
goto invalid;
switch (w_value) {
case 0x0000:
ncm->is_crc = false;
ndp_hdr_crc = NCM_NDP_HDR_NOCRC;
DBG(cdev, "non-CRC mode selected\n");
break;
case 0x0001:
ncm->is_crc = true;
ndp_hdr_crc = NCM_NDP_HDR_CRC;
DBG(cdev, "CRC mode selected\n");
break;
default:
goto invalid;
}
ncm->ndp_sign = ncm->parser_opts->ndp_sign | ndp_hdr_crc;
value = 0;
break;
}
default:
invalid:
DBG(cdev, "invalid control req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
}
if (value >= 0) {
DBG(cdev, "ncm req%02x.%02x v%04x i%04x l%d\n",
ctrl->bRequestType, ctrl->bRequest,
w_value, w_index, w_length);
req->zero = 0;
req->length = value;
value = usb_ep_queue(cdev->gadget->ep0, req, GFP_ATOMIC);
if (value < 0)
ERROR(cdev, "ncm req %02x.%02x response err %d\n",
ctrl->bRequestType, ctrl->bRequest,
value);
}
return value;
}
static int ncm_set_alt(struct usb_function *f, unsigned intf, unsigned alt)
{
struct f_ncm *ncm = func_to_ncm(f);
struct usb_composite_dev *cdev = f->config->cdev;
if (intf == ncm->ctrl_id) {
if (alt != 0)
goto fail;
DBG(cdev, "reset ncm control %d\n", intf);
usb_ep_disable(ncm->notify);
if (!(ncm->notify->desc)) {
DBG(cdev, "init ncm ctrl %d\n", intf);
if (config_ep_by_speed(cdev->gadget, f, ncm->notify))
goto fail;
}
usb_ep_enable(ncm->notify);
} else if (intf == ncm->data_id) {
if (alt > 1)
goto fail;
if (ncm->port.in_ep->enabled) {
DBG(cdev, "reset ncm\n");
ncm->timer_stopping = true;
ncm->netdev = NULL;
gether_disconnect(&ncm->port);
ncm_reset_values(ncm);
}
if (alt == 1) {
struct net_device *net;
if (!ncm->port.in_ep->desc ||
!ncm->port.out_ep->desc) {
DBG(cdev, "init ncm\n");
if (config_ep_by_speed(cdev->gadget, f,
ncm->port.in_ep) ||
config_ep_by_speed(cdev->gadget, f,
ncm->port.out_ep)) {
ncm->port.in_ep->desc = NULL;
ncm->port.out_ep->desc = NULL;
goto fail;
}
}
ncm->port.is_zlp_ok =
gadget_is_zlp_supported(cdev->gadget);
ncm->port.no_skb_reserve =
gadget_avoids_skb_reserve(cdev->gadget);
ncm->port.cdc_filter = DEFAULT_FILTER;
DBG(cdev, "activate ncm\n");
net = gether_connect(&ncm->port);
if (IS_ERR(net))
return PTR_ERR(net);
ncm->netdev = net;
ncm->timer_stopping = false;
}
spin_lock(&ncm->lock);
ncm_notify(ncm);
spin_unlock(&ncm->lock);
} else
goto fail;
return 0;
fail:
return -EINVAL;
}
static int ncm_get_alt(struct usb_function *f, unsigned intf)
{
struct f_ncm *ncm = func_to_ncm(f);
if (intf == ncm->ctrl_id)
return 0;
return ncm->port.in_ep->enabled ? 1 : 0;
}
static struct sk_buff *package_for_tx(struct f_ncm *ncm)
{
__le16 *ntb_iter;
struct sk_buff *skb2 = NULL;
unsigned ndp_pad;
unsigned ndp_index;
unsigned new_len;
const struct ndp_parser_opts *opts = ncm->parser_opts;
const int ndp_align = le16_to_cpu(ntb_parameters.wNdpInAlignment);
const int dgram_idx_len = 2 * 2 * opts->dgram_item_len;
hrtimer_try_to_cancel(&ncm->task_timer);
ndp_pad = ALIGN(ncm->skb_tx_data->len, ndp_align) -
ncm->skb_tx_data->len;
ndp_index = ncm->skb_tx_data->len + ndp_pad;
new_len = ndp_index + dgram_idx_len + ncm->skb_tx_ndp->len;
ntb_iter = (void *) ncm->skb_tx_data->data;
ntb_iter += 2 + 1 + 1;
put_ncm(&ntb_iter, opts->block_length, new_len);
put_ncm(&ntb_iter, opts->ndp_index, ndp_index);
new_len = opts->ndp_size +
(ncm->ndp_dgram_count * dgram_idx_len);
ncm->ndp_dgram_count = 0;
ntb_iter = (void *) ncm->skb_tx_ndp->data;
ntb_iter += 2;
put_unaligned_le16(new_len, ntb_iter);
swap(skb2, ncm->skb_tx_data);
if (ncm->skb_tx_data) {
dev_consume_skb_any(ncm->skb_tx_data);
ncm->skb_tx_data = NULL;
}
skb_put_zero(skb2, ndp_pad);
skb_put_data(skb2, ncm->skb_tx_ndp->data, ncm->skb_tx_ndp->len);
dev_consume_skb_any(ncm->skb_tx_ndp);
ncm->skb_tx_ndp = NULL;
skb_put_zero(skb2, dgram_idx_len);
return skb2;
}
static struct sk_buff *ncm_wrap_ntb(struct gether *port,
struct sk_buff *skb)
{
struct f_ncm *ncm = func_to_ncm(&port->func);
struct sk_buff *skb2 = NULL;
int ncb_len = 0;
__le16 *ntb_data;
__le16 *ntb_ndp;
int dgram_pad;
unsigned max_size = ncm->port.fixed_in_len;
const struct ndp_parser_opts *opts = ncm->parser_opts;
const int ndp_align = le16_to_cpu(ntb_parameters.wNdpInAlignment);
const int div = le16_to_cpu(ntb_parameters.wNdpInDivisor);
const int rem = le16_to_cpu(ntb_parameters.wNdpInPayloadRemainder);
const int dgram_idx_len = 2 * 2 * opts->dgram_item_len;
if (!skb && !ncm->skb_tx_data)
return NULL;
if (skb) {
if (ncm->is_crc) {
uint32_t crc;
__le16 *crc_pos;
crc = ~crc32_le(~0,
skb->data,
skb->len);
crc_pos = skb_put(skb, sizeof(uint32_t));
put_unaligned_le32(crc, crc_pos);
}
if (ncm->skb_tx_data
&& (ncm->ndp_dgram_count >= TX_MAX_NUM_DPE
|| (ncm->skb_tx_data->len +
div + rem + skb->len +
ncm->skb_tx_ndp->len + ndp_align + (2 * dgram_idx_len))
> max_size)) {
skb2 = package_for_tx(ncm);
if (!skb2)
goto err;
}
if (!ncm->skb_tx_data) {
ncb_len = opts->nth_size;
dgram_pad = ALIGN(ncb_len, div) + rem - ncb_len;
ncb_len += dgram_pad;
ncm->skb_tx_data = alloc_skb(max_size, GFP_ATOMIC);
if (!ncm->skb_tx_data)
goto err;
ncm->skb_tx_data->dev = ncm->netdev;
ntb_data = skb_put_zero(ncm->skb_tx_data, ncb_len);
put_unaligned_le32(opts->nth_sign, ntb_data);
ntb_data += 2;
put_unaligned_le16(opts->nth_size, ntb_data++);
ncm->skb_tx_ndp = alloc_skb((int)(opts->ndp_size
+ opts->dpe_size
* TX_MAX_NUM_DPE),
GFP_ATOMIC);
if (!ncm->skb_tx_ndp)
goto err;
ncm->skb_tx_ndp->dev = ncm->netdev;
ntb_ndp = skb_put(ncm->skb_tx_ndp, opts->ndp_size);
memset(ntb_ndp, 0, ncb_len);
put_unaligned_le32(ncm->ndp_sign, ntb_ndp);
ntb_ndp += 2;
ncm->ndp_dgram_count = 1;
}
hrtimer_start(&ncm->task_timer, TX_TIMEOUT_NSECS,
HRTIMER_MODE_REL);
ntb_ndp = skb_put_zero(ncm->skb_tx_ndp, dgram_idx_len);
ncb_len = ncm->skb_tx_data->len;
dgram_pad = ALIGN(ncb_len, div) + rem - ncb_len;
ncb_len += dgram_pad;
put_ncm(&ntb_ndp, opts->dgram_item_len, ncb_len);
put_ncm(&ntb_ndp, opts->dgram_item_len, skb->len);
ncm->ndp_dgram_count++;
skb_put_zero(ncm->skb_tx_data, dgram_pad);
skb_put_data(ncm->skb_tx_data, skb->data, skb->len);
dev_consume_skb_any(skb);
skb = NULL;
} else if (ncm->skb_tx_data && ncm->timer_force_tx) {
skb2 = package_for_tx(ncm);
if (!skb2)
goto err;
}
return skb2;
err:
ncm->netdev->stats.tx_dropped++;
if (skb)
dev_kfree_skb_any(skb);
if (ncm->skb_tx_data)
dev_kfree_skb_any(ncm->skb_tx_data);
if (ncm->skb_tx_ndp)
dev_kfree_skb_any(ncm->skb_tx_ndp);
return NULL;
}
static void ncm_tx_tasklet(unsigned long data)
{
struct f_ncm *ncm = (void *)data;
if (ncm->timer_stopping)
return;
if (ncm->skb_tx_data) {
ncm->timer_force_tx = true;
ncm->netdev->netdev_ops->ndo_start_xmit(NULL, ncm->netdev);
ncm->timer_force_tx = false;
}
}
static enum hrtimer_restart ncm_tx_timeout(struct hrtimer *data)
{
struct f_ncm *ncm = container_of(data, struct f_ncm, task_timer);
tasklet_schedule(&ncm->tx_tasklet);
return HRTIMER_NORESTART;
}
static int ncm_unwrap_ntb(struct gether *port,
struct sk_buff *skb,
struct sk_buff_head *list)
{
struct f_ncm *ncm = func_to_ncm(&port->func);
__le16 *tmp = (void *) skb->data;
unsigned index, index2;
int ndp_index;
unsigned dg_len, dg_len2;
unsigned ndp_len;
struct sk_buff *skb2;
int ret = -EINVAL;
unsigned max_size = le32_to_cpu(ntb_parameters.dwNtbOutMaxSize);
const struct ndp_parser_opts *opts = ncm->parser_opts;
unsigned crc_len = ncm->is_crc ? sizeof(uint32_t) : 0;
int dgram_counter;
if (get_unaligned_le32(tmp) != opts->nth_sign) {
INFO(port->func.config->cdev, "Wrong NTH SIGN, skblen %d\n",
skb->len);
print_hex_dump(KERN_INFO, "HEAD:", DUMP_PREFIX_ADDRESS, 32, 1,
skb->data, 32, false);
goto err;
}
tmp += 2;
if (get_unaligned_le16(tmp++) != opts->nth_size) {
INFO(port->func.config->cdev, "Wrong NTB headersize\n");
goto err;
}
tmp++;
if (get_ncm(&tmp, opts->block_length) > max_size) {
INFO(port->func.config->cdev, "OUT size exceeded\n");
goto err;
}
ndp_index = get_ncm(&tmp, opts->ndp_index);
do {
if (((ndp_index % 4) != 0) &&
(ndp_index < opts->nth_size)) {
INFO(port->func.config->cdev, "Bad index: %#X\n",
ndp_index);
goto err;
}
tmp = (void *)(skb->data + ndp_index);
if (get_unaligned_le32(tmp) != ncm->ndp_sign) {
INFO(port->func.config->cdev, "Wrong NDP SIGN\n");
goto err;
}
tmp += 2;
ndp_len = get_unaligned_le16(tmp++);
if ((ndp_len < opts->ndp_size
+ 2 * 2 * (opts->dgram_item_len * 2))
|| (ndp_len % opts->ndplen_align != 0)) {
INFO(port->func.config->cdev, "Bad NDP length: %#X\n",
ndp_len);
goto err;
}
tmp += opts->reserved1;
ndp_index = get_ncm(&tmp, opts->next_ndp_index);
tmp += opts->reserved2;
ndp_len -= opts->ndp_size;
index2 = get_ncm(&tmp, opts->dgram_item_len);
dg_len2 = get_ncm(&tmp, opts->dgram_item_len);
dgram_counter = 0;
do {
index = index2;
dg_len = dg_len2;
if (dg_len < 14 + crc_len) {
INFO(port->func.config->cdev,
"Bad dgram length: %#X\n", dg_len);
goto err;
}
if (ncm->is_crc) {
uint32_t crc, crc2;
crc = get_unaligned_le32(skb->data +
index + dg_len -
crc_len);
crc2 = ~crc32_le(~0,
skb->data + index,
dg_len - crc_len);
if (crc != crc2) {
INFO(port->func.config->cdev,
"Bad CRC\n");
goto err;
}
}
index2 = get_ncm(&tmp, opts->dgram_item_len);
dg_len2 = get_ncm(&tmp, opts->dgram_item_len);
skb2 = netdev_alloc_skb_ip_align(ncm->netdev,
dg_len - crc_len);
if (skb2 == NULL)
goto err;
skb_put_data(skb2, skb->data + index,
dg_len - crc_len);
skb_queue_tail(list, skb2);
ndp_len -= 2 * (opts->dgram_item_len * 2);
dgram_counter++;
if (index2 == 0 || dg_len2 == 0)
break;
} while (ndp_len > 2 * (opts->dgram_item_len * 2));
} while (ndp_index);
dev_consume_skb_any(skb);
VDBG(port->func.config->cdev,
"Parsed NTB with %d frames\n", dgram_counter);
return 0;
err:
skb_queue_purge(list);
dev_kfree_skb_any(skb);
return ret;
}
static void ncm_disable(struct usb_function *f)
{
struct f_ncm *ncm = func_to_ncm(f);
struct usb_composite_dev *cdev = f->config->cdev;
DBG(cdev, "ncm deactivated\n");
if (ncm->port.in_ep->enabled) {
ncm->timer_stopping = true;
ncm->netdev = NULL;
gether_disconnect(&ncm->port);
}
if (ncm->notify->enabled) {
usb_ep_disable(ncm->notify);
ncm->notify->desc = NULL;
}
}
static void ncm_open(struct gether *geth)
{
struct f_ncm *ncm = func_to_ncm(&geth->func);
DBG(ncm->port.func.config->cdev, "%s\n", __func__);
spin_lock(&ncm->lock);
ncm->is_open = true;
ncm_notify(ncm);
spin_unlock(&ncm->lock);
}
static void ncm_close(struct gether *geth)
{
struct f_ncm *ncm = func_to_ncm(&geth->func);
DBG(ncm->port.func.config->cdev, "%s\n", __func__);
spin_lock(&ncm->lock);
ncm->is_open = false;
ncm_notify(ncm);
spin_unlock(&ncm->lock);
}
static int ncm_bind(struct usb_configuration *c, struct usb_function *f)
{
struct usb_composite_dev *cdev = c->cdev;
struct f_ncm *ncm = func_to_ncm(f);
struct usb_string *us;
int status;
struct usb_ep *ep;
struct f_ncm_opts *ncm_opts;
if (!can_support_ecm(cdev->gadget))
return -EINVAL;
ncm_opts = container_of(f->fi, struct f_ncm_opts, func_inst);
if (!ncm_opts->bound) {
mutex_lock(&ncm_opts->lock);
gether_set_gadget(ncm_opts->net, cdev->gadget);
status = gether_register_netdev(ncm_opts->net);
mutex_unlock(&ncm_opts->lock);
if (status)
return status;
ncm_opts->bound = true;
}
us = usb_gstrings_attach(cdev, ncm_strings,
ARRAY_SIZE(ncm_string_defs));
if (IS_ERR(us))
return PTR_ERR(us);
ncm_control_intf.iInterface = us[STRING_CTRL_IDX].id;
ncm_data_nop_intf.iInterface = us[STRING_DATA_IDX].id;
ncm_data_intf.iInterface = us[STRING_DATA_IDX].id;
ecm_desc.iMACAddress = us[STRING_MAC_IDX].id;
ncm_iad_desc.iFunction = us[STRING_IAD_IDX].id;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ncm->ctrl_id = status;
ncm_iad_desc.bFirstInterface = status;
ncm_control_intf.bInterfaceNumber = status;
ncm_union_desc.bMasterInterface0 = status;
status = usb_interface_id(c, f);
if (status < 0)
goto fail;
ncm->data_id = status;
ncm_data_nop_intf.bInterfaceNumber = status;
ncm_data_intf.bInterfaceNumber = status;
ncm_union_desc.bSlaveInterface0 = status;
status = -ENODEV;
ep = usb_ep_autoconfig(cdev->gadget, &fs_ncm_in_desc);
if (!ep)
goto fail;
ncm->port.in_ep = ep;
ep = usb_ep_autoconfig(cdev->gadget, &fs_ncm_out_desc);
if (!ep)
goto fail;
ncm->port.out_ep = ep;
ep = usb_ep_autoconfig(cdev->gadget, &fs_ncm_notify_desc);
if (!ep)
goto fail;
ncm->notify = ep;
status = -ENOMEM;
ncm->notify_req = usb_ep_alloc_request(ep, GFP_KERNEL);
if (!ncm->notify_req)
goto fail;
ncm->notify_req->buf = kmalloc(NCM_STATUS_BYTECOUNT, GFP_KERNEL);
if (!ncm->notify_req->buf)
goto fail;
ncm->notify_req->context = ncm;
ncm->notify_req->complete = ncm_notify_complete;
hs_ncm_in_desc.bEndpointAddress = fs_ncm_in_desc.bEndpointAddress;
hs_ncm_out_desc.bEndpointAddress = fs_ncm_out_desc.bEndpointAddress;
hs_ncm_notify_desc.bEndpointAddress =
fs_ncm_notify_desc.bEndpointAddress;
ss_ncm_in_desc.bEndpointAddress = fs_ncm_in_desc.bEndpointAddress;
ss_ncm_out_desc.bEndpointAddress = fs_ncm_out_desc.bEndpointAddress;
ss_ncm_notify_desc.bEndpointAddress =
fs_ncm_notify_desc.bEndpointAddress;
status = usb_assign_descriptors(f, ncm_fs_function, ncm_hs_function,
ncm_ss_function, NULL);
if (status)
goto fail;
ncm->port.open = ncm_open;
ncm->port.close = ncm_close;
tasklet_init(&ncm->tx_tasklet, ncm_tx_tasklet, (unsigned long) ncm);
hrtimer_init(&ncm->task_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
ncm->task_timer.function = ncm_tx_timeout;
DBG(cdev, "CDC Network: %s speed IN/%s OUT/%s NOTIFY/%s\n",
gadget_is_superspeed(c->cdev->gadget) ? "super" :
gadget_is_dualspeed(c->cdev->gadget) ? "dual" : "full",
ncm->port.in_ep->name, ncm->port.out_ep->name,
ncm->notify->name);
return 0;
fail:
if (ncm->notify_req) {
kfree(ncm->notify_req->buf);
usb_ep_free_request(ncm->notify, ncm->notify_req);
}
ERROR(cdev, "%s: can't bind, err %d\n", f->name, status);
return status;
}
static inline struct f_ncm_opts *to_f_ncm_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_ncm_opts,
func_inst.group);
}
static void ncm_free_inst(struct usb_function_instance *f)
{
struct f_ncm_opts *opts;
opts = container_of(f, struct f_ncm_opts, func_inst);
if (opts->bound)
gether_cleanup(netdev_priv(opts->net));
else
free_netdev(opts->net);
kfree(opts);
}
static struct usb_function_instance *ncm_alloc_inst(void)
{
struct f_ncm_opts *opts;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
mutex_init(&opts->lock);
opts->func_inst.free_func_inst = ncm_free_inst;
opts->net = gether_setup_default();
if (IS_ERR(opts->net)) {
struct net_device *net = opts->net;
kfree(opts);
return ERR_CAST(net);
}
config_group_init_type_name(&opts->func_inst.group, "", &ncm_func_type);
return &opts->func_inst;
}
static void ncm_free(struct usb_function *f)
{
struct f_ncm *ncm;
struct f_ncm_opts *opts;
ncm = func_to_ncm(f);
opts = container_of(f->fi, struct f_ncm_opts, func_inst);
kfree(ncm);
mutex_lock(&opts->lock);
opts->refcnt--;
mutex_unlock(&opts->lock);
}
static void ncm_unbind(struct usb_configuration *c, struct usb_function *f)
{
struct f_ncm *ncm = func_to_ncm(f);
DBG(c->cdev, "ncm unbind\n");
hrtimer_cancel(&ncm->task_timer);
tasklet_kill(&ncm->tx_tasklet);
ncm_string_defs[0].id = 0;
usb_free_all_descriptors(f);
kfree(ncm->notify_req->buf);
usb_ep_free_request(ncm->notify, ncm->notify_req);
}
static struct usb_function *ncm_alloc(struct usb_function_instance *fi)
{
struct f_ncm *ncm;
struct f_ncm_opts *opts;
int status;
ncm = kzalloc(sizeof(*ncm), GFP_KERNEL);
if (!ncm)
return ERR_PTR(-ENOMEM);
opts = container_of(fi, struct f_ncm_opts, func_inst);
mutex_lock(&opts->lock);
opts->refcnt++;
status = gether_get_host_addr_cdc(opts->net, ncm->ethaddr,
sizeof(ncm->ethaddr));
if (status < 12) {
kfree(ncm);
mutex_unlock(&opts->lock);
return ERR_PTR(-EINVAL);
}
ncm_string_defs[STRING_MAC_IDX].s = ncm->ethaddr;
spin_lock_init(&ncm->lock);
ncm_reset_values(ncm);
ncm->port.ioport = netdev_priv(opts->net);
mutex_unlock(&opts->lock);
ncm->port.is_fixed = true;
ncm->port.supports_multi_frame = true;
ncm->port.func.name = "cdc_network";
ncm->port.func.bind = ncm_bind;
ncm->port.func.unbind = ncm_unbind;
ncm->port.func.set_alt = ncm_set_alt;
ncm->port.func.get_alt = ncm_get_alt;
ncm->port.func.setup = ncm_setup;
ncm->port.func.disable = ncm_disable;
ncm->port.func.free_func = ncm_free;
ncm->port.wrap = ncm_wrap_ntb;
ncm->port.unwrap = ncm_unwrap_ntb;
return &ncm->port.func;
}
