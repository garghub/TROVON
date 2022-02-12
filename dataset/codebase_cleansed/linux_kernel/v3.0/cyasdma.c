static void
cy_as_dma_add_request_to_free_queue(cy_as_device *dev_p,
cy_as_dma_queue_entry *req_p)
{
uint32_t imask;
imask = cy_as_hal_disable_interrupts();
req_p->next_p = dev_p->dma_freelist_p;
dev_p->dma_freelist_p = req_p;
cy_as_hal_enable_interrupts(imask);
}
static cy_as_dma_queue_entry *
cy_as_dma_get_dma_queue_entry(cy_as_device *dev_p)
{
cy_as_dma_queue_entry *req_p;
uint32_t imask;
cy_as_hal_assert(dev_p->dma_freelist_p != 0);
imask = cy_as_hal_disable_interrupts();
req_p = dev_p->dma_freelist_p;
dev_p->dma_freelist_p = req_p->next_p;
cy_as_hal_enable_interrupts(imask);
return req_p;
}
cy_as_return_status_t
cy_as_dma_set_max_dma_size(cy_as_device *dev_p,
cy_as_end_point_number_t ep, uint32_t size)
{
if ((!dev_p->is_mtp_firmware) || (ep != 0x02)) {
if (size < 64 || size > 1024)
return CY_AS_ERROR_INVALID_SIZE;
}
CY_AS_NUM_EP(dev_p, ep)->maxhwdata = (uint16_t)size;
return CY_AS_ERROR_SUCCESS;
}
static void
cy_as_dma_request_callback(
cy_as_device *dev_p,
uint8_t context,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *resp_p,
cy_as_return_status_t ret)
{
uint16_t v;
uint16_t datacnt;
cy_as_end_point_number_t ep;
(void)context;
cy_as_log_debug_message(5, "cy_as_dma_request_callback called");
if (ret == CY_AS_ERROR_SUCCESS) {
if (cy_as_ll_request_response__get_code(resp_p) !=
CY_RESP_SUCCESS_FAILURE)
ret = CY_AS_ERROR_INVALID_RESPONSE;
else
ret = cy_as_ll_request_response__get_word(resp_p, 0);
}
v = cy_as_ll_request_response__get_word(req_p, 0);
ep = (cy_as_end_point_number_t)((v >> 13) & 0x01);
if (ret == CY_AS_ERROR_SUCCESS) {
datacnt = v & 0x3FF;
} else {
datacnt = 0;
}
if (ep == 0) {
dev_p->usb_ep0_dma_req = req_p;
dev_p->usb_ep0_dma_resp = resp_p;
} else {
dev_p->usb_ep1_dma_req = req_p;
dev_p->usb_ep1_dma_resp = resp_p;
}
if (ret != CY_AS_ERROR_CANCELED)
cy_as_dma_completed_callback(dev_p->tag, ep, datacnt, ret);
}
static void
cy_as_dma_set_drq(cy_as_device *dev_p,
cy_as_end_point_number_t ep, cy_bool state)
{
uint16_t mask;
uint16_t v;
uint32_t intval;
if (ep == 0 || ep == 1)
return;
intval = cy_as_hal_disable_interrupts();
mask = (1 << ep);
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_DRQ_MASK);
if (state)
v |= mask;
else
v &= ~mask;
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_P0_DRQ_MASK, v);
cy_as_hal_enable_interrupts(intval);
}
static void
cy_as_dma_send_next_dma_request(cy_as_device *dev_p, cy_as_dma_end_point *ep_p)
{
uint32_t datacnt;
void *buf_p;
cy_as_dma_queue_entry *dma_p;
cy_as_log_debug_message(6, "cy_as_dma_send_next_dma_request called");
dma_p = ep_p->queue_p;
if (dma_p == 0) {
cy_as_dma_set_drq(dev_p, ep_p->ep, cy_false);
return;
}
cy_as_dma_end_point_set_running(ep_p);
datacnt = dma_p->size - dma_p->offset;
cy_as_hal_assert(datacnt >= 0);
cy_as_hal_assert(ep_p->maxhaldata == CY_AS_DMA_MAX_SIZE_HW_SIZE
|| ep_p->maxhaldata >= ep_p->maxhwdata);
if (ep_p->maxhaldata == CY_AS_DMA_MAX_SIZE_HW_SIZE) {
if (datacnt > ep_p->maxhwdata)
datacnt = ep_p->maxhwdata;
} else {
if (datacnt > ep_p->maxhaldata)
datacnt = ep_p->maxhaldata;
}
buf_p = (((char *)dma_p->buf_p) + dma_p->offset);
cy_as_dma_end_point_set_in_transit(ep_p);
if (ep_p->ep == 0 || ep_p->ep == 1) {
if (dma_p->readreq == cy_false) {
uint16_t v;
uint16_t len;
cy_as_ll_request_response *resp_p;
cy_as_ll_request_response *req_p;
cy_as_return_status_t ret;
len = (uint16_t)(datacnt / 2);
if (datacnt % 2)
len++;
len++;
if (ep_p->ep == 0) {
req_p = dev_p->usb_ep0_dma_req;
resp_p = dev_p->usb_ep0_dma_resp;
dev_p->usb_ep0_dma_req = 0;
dev_p->usb_ep0_dma_resp = 0;
} else {
req_p = dev_p->usb_ep1_dma_req;
resp_p = dev_p->usb_ep1_dma_resp;
dev_p->usb_ep1_dma_req = 0;
dev_p->usb_ep1_dma_resp = 0;
}
cy_as_hal_assert(req_p != 0);
cy_as_hal_assert(resp_p != 0);
cy_as_hal_assert(len <= 64);
cy_as_ll_init_request(req_p, CY_RQT_USB_EP_DATA,
CY_RQT_USB_RQT_CONTEXT, len);
v = (uint16_t)(datacnt | (ep_p->ep << 13) | (1 << 14));
if (dma_p->offset == 0)
v |= (1 << 12);
if (dma_p->offset + datacnt == dma_p->size)
v |= (1 << 11);
cy_as_ll_request_response__set_word(req_p, 0, v);
cy_as_ll_request_response__pack(req_p,
1, datacnt, buf_p);
cy_as_ll_init_response(resp_p, 1);
ret = cy_as_ll_send_request(dev_p, req_p, resp_p,
cy_false, cy_as_dma_request_callback);
if (ret == CY_AS_ERROR_SUCCESS)
cy_as_log_debug_message(5,
"+++ send EP 0/1 data via mailbox registers");
else
cy_as_log_debug_message(5,
"+++ error sending EP 0/1 data via mailbox "
"registers - CY_AS_ERROR_TIMEOUT");
if (ret != CY_AS_ERROR_SUCCESS)
cy_as_dma_completed_callback(dev_p->tag,
ep_p->ep, 0, ret);
}
} else {
if (cy_as_dma_end_point_is_direction_in(ep_p))
cy_as_hal_dma_setup_write(dev_p->tag,
ep_p->ep, buf_p, datacnt, ep_p->maxhwdata);
else
cy_as_hal_dma_setup_read(dev_p->tag,
ep_p->ep, buf_p, datacnt, ep_p->maxhwdata);
cy_as_dma_set_drq(dev_p, ep_p->ep, cy_true);
}
}
void
cy_as_dma_completed_callback(cy_as_hal_device_tag tag,
cy_as_end_point_number_t ep, uint32_t cnt, cy_as_return_status_t status)
{
uint32_t mask;
cy_as_dma_queue_entry *req_p;
cy_as_dma_end_point *ep_p;
cy_as_device *dev_p = cy_as_device_find_from_tag(tag);
cy_as_hal_assert(dev_p != 0);
cy_as_hal_assert(dev_p->sig == CY_AS_DEVICE_HANDLE_SIGNATURE);
cy_as_hal_assert(ep < 16);
ep_p = CY_AS_NUM_EP(dev_p, ep);
cy_as_hal_assert(ep_p->queue_p != 0);
mask = cy_as_hal_disable_interrupts();
req_p = ep_p->queue_p;
req_p->offset += cnt;
if (((req_p->offset != req_p->size) && (req_p->packet == cy_false) &&
((cnt == ep_p->maxhaldata) || ((cnt == ep_p->maxhwdata) &&
((ep != CY_AS_MTP_READ_ENDPOINT) ||
(cnt == dev_p->usb_max_tx_size)))))
|| ((ep == 1) && (status == CY_AS_ERROR_TIMEOUT))) {
cy_as_hal_enable_interrupts(mask);
if ((ep == CY_AS_MTP_WRITE_ENDPOINT) || (
(ep == CY_AS_MTP_READ_ENDPOINT) &&
(!cy_as_dma_end_point_is_direction_in(ep_p))))
cy_as_dma_end_point_set_stopped(ep_p);
else
cy_as_dma_send_next_dma_request(dev_p, ep_p);
} else {
cy_as_dma_end_point_clear_in_transit(ep_p);
ep_p->queue_p = req_p->next_p;
if (ep_p->last_p == req_p) {
ep_p->last_p = 0;
cy_as_hal_enable_interrupts(mask);
cy_as_dma_set_drq(dev_p, ep, cy_false);
} else
cy_as_hal_enable_interrupts(mask);
if (req_p->cb) {
cy_as_device_set_in_callback(dev_p);
(*req_p->cb)(dev_p, ep, req_p->buf_p,
req_p->offset, status);
cy_as_device_clear_in_callback(dev_p);
}
cy_as_dma_add_request_to_free_queue(dev_p, req_p);
if (ep_p->queue_p == 0) {
cy_as_dma_end_point_set_stopped(ep_p);
if (cy_as_dma_end_point_is_sleeping(ep_p)) {
cy_as_dma_end_point_set_wake_state(ep_p);
cy_as_hal_wake(&ep_p->channel);
}
} else {
if ((ep == CY_AS_MTP_WRITE_ENDPOINT) ||
((ep == CY_AS_MTP_READ_ENDPOINT) &&
(!cy_as_dma_end_point_is_direction_in(ep_p))) ||
((ep == dev_p->storage_read_endpoint) &&
(!cy_as_device_is_p2s_dma_start_recvd(dev_p)))
|| ((ep == dev_p->storage_write_endpoint) &&
(!cy_as_device_is_p2s_dma_start_recvd(dev_p))))
cy_as_dma_end_point_set_stopped(ep_p);
else
cy_as_dma_send_next_dma_request(dev_p, ep_p);
}
}
}
cy_as_return_status_t
cy_as_dma_kick_start(cy_as_device *dev_p, cy_as_end_point_number_t ep)
{
cy_as_dma_end_point *ep_p;
cy_as_hal_assert(dev_p->sig == CY_AS_DEVICE_HANDLE_SIGNATURE);
ep_p = CY_AS_NUM_EP(dev_p, ep);
if (cy_as_dma_end_point_is_running(ep_p))
return CY_AS_ERROR_SUCCESS;
cy_as_dma_send_next_dma_request(dev_p, ep_p);
return CY_AS_ERROR_SUCCESS;
}
static cy_as_return_status_t
cy_as_dma_stop_end_point(cy_as_device *dev_p, cy_as_end_point_number_t ep)
{
cy_as_return_status_t ret;
cy_as_dma_end_point *ep_p = CY_AS_NUM_EP(dev_p, ep);
ret = cy_as_dma_cancel(dev_p, ep, CY_AS_ERROR_CANCELED);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (!cy_as_hal_destroy_sleep_channel(&ep_p->channel)
&& ret == CY_AS_ERROR_SUCCESS)
ret = CY_AS_ERROR_DESTROY_SLEEP_CHANNEL_FAILED;
cy_as_hal_free(ep_p);
dev_p->endp[ep] = 0;
return ret;
}
static cy_as_return_status_t
cy_as_dma_stop_internal(cy_as_device *dev_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_return_status_t lret;
cy_as_end_point_number_t i;
for (i = 0; i < sizeof(dev_p->endp)/(sizeof(dev_p->endp[0])); i++) {
lret = cy_as_dma_stop_end_point(dev_p, i);
if (lret != CY_AS_ERROR_SUCCESS && ret == CY_AS_ERROR_SUCCESS)
ret = lret;
}
while (dev_p->dma_freelist_p) {
cy_as_dma_queue_entry *req_p;
uint32_t imask = cy_as_hal_disable_interrupts();
req_p = dev_p->dma_freelist_p;
dev_p->dma_freelist_p = req_p->next_p;
cy_as_hal_enable_interrupts(imask);
cy_as_hal_free(req_p);
}
cy_as_ll_destroy_request(dev_p, dev_p->usb_ep0_dma_req);
cy_as_ll_destroy_request(dev_p, dev_p->usb_ep1_dma_req);
cy_as_ll_destroy_response(dev_p, dev_p->usb_ep0_dma_resp);
cy_as_ll_destroy_response(dev_p, dev_p->usb_ep1_dma_resp);
return ret;
}
cy_as_return_status_t
cy_as_dma_stop(cy_as_device *dev_p)
{
cy_as_return_status_t ret;
ret = cy_as_dma_stop_internal(dev_p);
cy_as_device_set_dma_stopped(dev_p);
return ret;
}
cy_as_return_status_t
cy_as_dma_start(cy_as_device *dev_p)
{
cy_as_end_point_number_t i;
uint16_t cnt;
if (cy_as_device_is_dma_running(dev_p))
return CY_AS_ERROR_ALREADY_RUNNING;
for (cnt = 0; cnt < 32; cnt++) {
cy_as_dma_queue_entry *entry_p = (cy_as_dma_queue_entry *)
cy_as_hal_alloc(sizeof(cy_as_dma_queue_entry));
if (entry_p == 0) {
cy_as_dma_stop_internal(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
cy_as_dma_add_request_to_free_queue(dev_p, entry_p);
}
dev_p->usb_ep0_dma_req = cy_as_ll_create_request(dev_p,
CY_RQT_USB_EP_DATA, CY_RQT_USB_RQT_CONTEXT, 64);
dev_p->usb_ep1_dma_req = cy_as_ll_create_request(dev_p,
CY_RQT_USB_EP_DATA, CY_RQT_USB_RQT_CONTEXT, 64);
if (dev_p->usb_ep0_dma_req == 0 || dev_p->usb_ep1_dma_req == 0) {
cy_as_dma_stop_internal(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
dev_p->usb_ep0_dma_req_save = dev_p->usb_ep0_dma_req;
dev_p->usb_ep0_dma_resp = cy_as_ll_create_response(dev_p, 1);
dev_p->usb_ep1_dma_resp = cy_as_ll_create_response(dev_p, 1);
if (dev_p->usb_ep0_dma_resp == 0 || dev_p->usb_ep1_dma_resp == 0) {
cy_as_dma_stop_internal(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
dev_p->usb_ep0_dma_resp_save = dev_p->usb_ep0_dma_resp;
cy_as_hal_mem_set(dev_p->endp, 0, sizeof(dev_p->endp));
for (i = 0; i < sizeof(dev_p->endp)/sizeof(dev_p->endp[0]); i++) {
dev_p->endp[i] = (cy_as_dma_end_point *)
cy_as_hal_alloc(sizeof(cy_as_dma_end_point));
if (dev_p->endp[i] == 0) {
cy_as_dma_stop_internal(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
cy_as_hal_mem_set(dev_p->endp[i], 0,
sizeof(cy_as_dma_end_point));
dev_p->endp[i]->ep = i;
dev_p->endp[i]->queue_p = 0;
dev_p->endp[i]->last_p = 0;
cy_as_dma_set_drq(dev_p, i, cy_false);
if (!cy_as_hal_create_sleep_channel(&dev_p->endp[i]->channel))
return CY_AS_ERROR_CREATE_SLEEP_CHANNEL_FAILED;
}
cy_as_hal_dma_register_callback(dev_p->tag,
cy_as_dma_completed_callback);
cy_as_device_set_dma_running(dev_p);
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_dma_drain_queue(cy_as_device *dev_p,
cy_as_end_point_number_t ep, cy_bool kickstart)
{
cy_as_dma_end_point *ep_p;
int loopcount = 1000;
uint32_t mask;
if (ep >= sizeof(dev_p->endp)/sizeof(dev_p->endp[0]))
return CY_AS_ERROR_INVALID_ENDPOINT;
ep_p = CY_AS_NUM_EP(dev_p, ep);
mask = cy_as_hal_disable_interrupts();
if (ep_p->queue_p == 0) {
cy_as_hal_enable_interrupts(mask);
return CY_AS_ERROR_SUCCESS;
} else {
if (ep_p->queue_p->size > 0x10000)
loopcount += ((ep_p->queue_p->size / 0x10000) * 1000);
}
cy_as_hal_enable_interrupts(mask);
if (cy_as_dma_end_point_is_sleeping(ep_p))
return CY_AS_ERROR_NESTED_SLEEP;
cy_as_dma_enable_end_point(dev_p, ep,
cy_false, cy_as_direction_dont_change);
if (kickstart) {
cy_as_dma_kick_start(dev_p, ep);
}
if (ep_p->queue_p == 0) {
cy_as_dma_enable_end_point(dev_p, ep, cy_true,
cy_as_direction_dont_change);
return CY_AS_ERROR_SUCCESS;
}
while (loopcount-- > 0) {
cy_as_dma_end_point_set_sleep_state(ep_p);
cy_as_hal_sleep_on(&ep_p->channel, 10);
cy_as_dma_end_point_set_wake_state(ep_p);
if (ep_p->queue_p == 0) {
cy_as_dma_end_point_clear_in_transit(ep_p);
cy_as_dma_end_point_set_stopped(ep_p);
cy_as_dma_enable_end_point(dev_p, ep,
cy_true, cy_as_direction_dont_change);
return CY_AS_ERROR_SUCCESS;
}
}
cy_as_dma_cancel(dev_p, ep, CY_AS_ERROR_TIMEOUT);
cy_as_dma_enable_end_point(dev_p, ep,
cy_true, cy_as_direction_dont_change);
return CY_AS_ERROR_TIMEOUT;
}
cy_as_return_status_t
cy_as_dma_queue_request(cy_as_device *dev_p,
cy_as_end_point_number_t ep, void *mem_p,
uint32_t size, cy_bool pkt, cy_bool readreq, cy_as_dma_callback cb)
{
uint32_t mask;
cy_as_dma_queue_entry *entry_p;
cy_as_dma_end_point *ep_p;
if (ep >= sizeof(dev_p->endp)/sizeof(dev_p->endp[0]))
return CY_AS_ERROR_INVALID_ENDPOINT;
ep_p = CY_AS_NUM_EP(dev_p, ep);
if (!cy_as_dma_end_point_is_enabled(ep_p))
return CY_AS_ERROR_ENDPOINT_DISABLED;
entry_p = cy_as_dma_get_dma_queue_entry(dev_p);
entry_p->buf_p = mem_p;
entry_p->cb = cb;
entry_p->size = size;
entry_p->offset = 0;
entry_p->packet = pkt;
entry_p->readreq = readreq;
mask = cy_as_hal_disable_interrupts();
entry_p->next_p = 0;
if (ep_p->last_p)
ep_p->last_p->next_p = entry_p;
ep_p->last_p = entry_p;
if (ep_p->queue_p == 0)
ep_p->queue_p = entry_p;
cy_as_hal_enable_interrupts(mask);
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_dma_enable_end_point(cy_as_device *dev_p,
cy_as_end_point_number_t ep, cy_bool enable, cy_as_dma_direction dir)
{
cy_as_dma_end_point *ep_p;
if (ep >= sizeof(dev_p->endp)/sizeof(dev_p->endp[0]))
return CY_AS_ERROR_INVALID_ENDPOINT;
ep_p = CY_AS_NUM_EP(dev_p, ep);
if (dir == cy_as_direction_out)
cy_as_dma_end_point_set_direction_out(ep_p);
else if (dir == cy_as_direction_in)
cy_as_dma_end_point_set_direction_in(ep_p);
if (ep == 0 || ep == 1)
ep_p->maxhaldata = 64;
else
ep_p->maxhaldata = cy_as_hal_dma_max_request_size(
dev_p->tag, ep);
if (enable)
cy_as_dma_end_point_enable(ep_p);
else
cy_as_dma_end_point_disable(ep_p);
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_dma_cancel(
cy_as_device *dev_p,
cy_as_end_point_number_t ep,
cy_as_return_status_t err)
{
uint32_t mask;
cy_as_dma_end_point *ep_p;
cy_as_dma_queue_entry *entry_p;
cy_bool epstate;
if (ep >= sizeof(dev_p->endp)/sizeof(dev_p->endp[0]))
return CY_AS_ERROR_INVALID_ENDPOINT;
ep_p = CY_AS_NUM_EP(dev_p, ep);
if (ep_p) {
epstate = cy_as_dma_end_point_is_enabled(ep_p);
cy_as_dma_enable_end_point(dev_p, ep,
cy_false, cy_as_direction_dont_change);
cy_as_dma_set_drq(dev_p, ep, cy_false);
if (cy_as_dma_end_point_in_transit(ep_p))
cy_as_hal_dma_cancel_request(dev_p->tag, ep_p->ep);
cy_as_dma_end_point_set_stopped(ep_p);
cy_as_dma_end_point_clear_in_transit(ep_p);
ep_p->last_p = 0;
while (ep_p->queue_p != 0) {
mask = cy_as_hal_disable_interrupts();
entry_p = ep_p->queue_p;
ep_p->queue_p = entry_p->next_p;
cy_as_hal_enable_interrupts(mask);
if (entry_p->cb)
entry_p->cb(dev_p, ep,
entry_p->buf_p, entry_p->size, err);
cy_as_dma_add_request_to_free_queue(dev_p, entry_p);
}
if (ep == 0 || ep == 1) {
cy_as_ll_remove_ep_data_requests(dev_p, ep);
}
if (epstate) {
cy_as_dma_enable_end_point(dev_p, ep,
cy_true, cy_as_direction_dont_change);
}
}
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_dma_received_data(cy_as_device *dev_p,
cy_as_end_point_number_t ep, uint32_t dsize, void *data)
{
cy_as_dma_queue_entry *dma_p;
uint8_t *src_p, *dest_p;
cy_as_dma_end_point *ep_p;
uint32_t xfersize;
if (ep != 0 && ep != 1)
return CY_AS_ERROR_INVALID_ENDPOINT;
ep_p = CY_AS_NUM_EP(dev_p, ep);
dma_p = ep_p->queue_p;
if (dma_p == 0)
return CY_AS_ERROR_SUCCESS;
if (dsize > dma_p->size - dma_p->offset)
dsize = dma_p->size - dma_p->offset;
src_p = (uint8_t *)data;
dest_p = ((uint8_t *)(dma_p->buf_p)) + dma_p->offset;
xfersize = dsize;
while (xfersize-- > 0)
*dest_p++ = *src_p++;
cy_as_dma_completed_callback(dev_p->tag,
ep, dsize, CY_AS_ERROR_SUCCESS);
return CY_AS_ERROR_SUCCESS;
}
