static cy_as_return_status_t
is_mtp_active(cy_as_device *dev_p)
{
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
if (!cy_as_device_is_firmware_loaded(dev_p))
return CY_AS_ERROR_NO_FIRMWARE;
if (dev_p->mtp_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
return CY_AS_ERROR_SUCCESS;
}
static void
my_mtp_request_callback(cy_as_device *dev_p,
uint8_t context,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *resp_p,
cy_as_return_status_t ret)
{
uint16_t val, ev, status;
uint16_t mtp_datalen = 0;
uint32_t bytecount_l, bytecount_h;
cy_as_mtp_send_object_complete_data send_obj_data;
cy_as_mtp_get_object_complete_data get_obj_data;
cy_as_dma_end_point *ep_p;
uint8_t code = cy_as_ll_request_response__get_code(req_p);
(void)resp_p;
(void)context;
(void)ret;
switch (code) {
case CY_RQT_MTP_EVENT:
val = cy_as_ll_request_response__get_word(req_p, 0);
status = (val >> 8) & 0xFF;
ev = val & 0xFF;
switch (ev) {
case 0:
{
bytecount_l =
cy_as_ll_request_response__get_word
(req_p, 1);
bytecount_h =
cy_as_ll_request_response__get_word
(req_p, 2);
send_obj_data.byte_count =
(bytecount_h << 16) | bytecount_l;
send_obj_data.status = status;
bytecount_l =
cy_as_ll_request_response__get_word
(req_p, 3);
bytecount_h =
cy_as_ll_request_response__get_word
(req_p, 4);
send_obj_data.transaction_id =
(bytecount_h << 16) | bytecount_l;
dev_p->mtp_turbo_active = cy_false;
if (dev_p->mtp_event_cb)
dev_p->mtp_event_cb(
(cy_as_device_handle) dev_p,
cy_as_mtp_send_object_complete,
&send_obj_data);
}
break;
case 1:
{
bytecount_l =
cy_as_ll_request_response__get_word
(req_p, 1);
bytecount_h =
cy_as_ll_request_response__get_word
(req_p, 2);
get_obj_data.byte_count =
(bytecount_h << 16) | bytecount_l;
get_obj_data.status = status;
dev_p->mtp_turbo_active = cy_false;
if (dev_p->mtp_event_cb)
dev_p->mtp_event_cb(
(cy_as_device_handle) dev_p,
cy_as_mtp_get_object_complete,
&get_obj_data);
}
break;
case 2:
{
if (dev_p->mtp_event_cb)
dev_p->mtp_event_cb(
(cy_as_device_handle) dev_p,
cy_as_mtp_block_table_needed, 0);
}
break;
default:
cy_as_hal_print_message("invalid event type\n");
cy_as_ll_send_data_response(dev_p,
CY_RQT_TUR_RQT_CONTEXT,
CY_RESP_MTP_INVALID_EVENT,
sizeof(ev), &ev);
break;
}
break;
case CY_RQT_TURBO_CMD_FROM_HOST:
{
mtp_datalen =
cy_as_ll_request_response__get_word(req_p, 1);
ep_p = CY_AS_NUM_EP(dev_p, CY_AS_MTP_READ_ENDPOINT);
cy_as_hal_assert(ep_p->queue_p != 0);
cy_as_hal_assert(ep_p->queue_p->size >= mtp_datalen);
if (mtp_datalen == 0) {
cy_as_dma_completed_callback(dev_p->tag,
CY_AS_MTP_READ_ENDPOINT, 0,
CY_AS_ERROR_SUCCESS);
} else {
ep_p->maxhwdata = mtp_datalen;
cy_as_dma_end_point_set_stopped(ep_p);
cy_as_dma_kick_start(dev_p,
CY_AS_MTP_READ_ENDPOINT);
}
}
break;
case CY_RQT_TURBO_START_WRITE_DMA:
{
cy_as_ll_send_status_response(dev_p,
CY_RQT_TUR_RQT_CONTEXT,
CY_AS_ERROR_SUCCESS, 0);
ep_p = CY_AS_NUM_EP(dev_p, CY_AS_MTP_WRITE_ENDPOINT);
cy_as_hal_assert(ep_p->queue_p != 0);
cy_as_dma_end_point_set_stopped(ep_p);
cy_as_dma_kick_start(dev_p, CY_AS_MTP_WRITE_ENDPOINT);
}
break;
default:
cy_as_hal_print_message("invalid request received "
"on TUR context\n");
val = req_p->box0;
cy_as_ll_send_data_response(dev_p, CY_RQT_TUR_RQT_CONTEXT,
CY_RESP_INVALID_REQUEST, sizeof(val), &val);
break;
}
}
static cy_as_return_status_t
my_handle_response_no_data(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
static cy_as_return_status_t
my_handle_response_mtp_start(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_return_status_t ret)
{
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
dev_p->mtp_count++;
cy_as_dma_enable_end_point(dev_p, CY_AS_MTP_READ_ENDPOINT,
cy_true, cy_as_direction_out);
dev_p->usb_config[CY_AS_MTP_READ_ENDPOINT].enabled = cy_true;
dev_p->usb_config[CY_AS_MTP_READ_ENDPOINT].dir = cy_as_usb_out;
dev_p->usb_config[CY_AS_MTP_READ_ENDPOINT].type = cy_as_usb_bulk;
cy_as_dma_enable_end_point(dev_p, CY_AS_MTP_WRITE_ENDPOINT,
cy_true, cy_as_direction_in);
dev_p->usb_config[CY_AS_MTP_WRITE_ENDPOINT].enabled = cy_true;
dev_p->usb_config[CY_AS_MTP_WRITE_ENDPOINT].dir = cy_as_usb_in;
dev_p->usb_config[CY_AS_MTP_WRITE_ENDPOINT].type = cy_as_usb_bulk;
cy_as_dma_set_max_dma_size(dev_p, 0x02, 0x0200);
cy_as_dma_set_max_dma_size(dev_p, 0x06, 0x40);
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
cy_as_ll_register_request_callback(dev_p,
CY_RQT_TUR_RQT_CONTEXT, 0);
cy_as_device_clear_m_s_s_pending(dev_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_start(cy_as_device_handle handle,
cy_as_mtp_event_callback event_c_b,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
if (!cy_as_device_is_firmware_loaded(dev_p))
return CY_AS_ERROR_NO_FIRMWARE;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if (cy_as_device_is_in_callback(dev_p))
return CY_AS_ERROR_INVALID_IN_CALLBACK;
if (cy_as_device_is_m_s_s_pending(dev_p))
return CY_AS_ERROR_STARTSTOP_PENDING;
if (dev_p->storage_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
if (dev_p->usb_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
if (dev_p->is_mtp_firmware == 0)
return CY_AS_ERROR_NOT_SUPPORTED;
cy_as_device_set_m_s_s_pending(dev_p);
if (dev_p->mtp_count == 0) {
dev_p->mtp_event_cb = event_c_b;
cy_as_ll_register_request_callback(dev_p,
CY_RQT_TUR_RQT_CONTEXT, my_mtp_request_callback);
req_p = cy_as_ll_create_request(dev_p,
CY_RQT_START_MTP, CY_RQT_TUR_RQT_CONTEXT, 0);
if (req_p == 0) {
cy_as_device_clear_m_s_s_pending(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_device_clear_m_s_s_pending(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return my_handle_response_mtp_start(dev_p, req_p,
reply_p, ret);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_START, 0, dev_p->func_cbs_mtp,
CY_AS_REQUEST_RESPONSE_EX, req_p, reply_p,
cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
} else {
dev_p->mtp_count++;
if (cb)
cb(handle, ret, client, CY_FUNCT_CB_MTP_START, 0);
}
cy_as_device_clear_m_s_s_pending(dev_p);
return ret;
}
static cy_as_return_status_t
my_handle_response_mtp_stop(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_return_status_t ret)
{
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
dev_p->mtp_count--;
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
cy_as_ll_register_request_callback(dev_p,
CY_RQT_TUR_RQT_CONTEXT, 0);
cy_as_device_clear_m_s_s_pending(dev_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_stop(cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_ll_request_response *req_p = 0, *reply_p = 0;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_mtp_stop called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
ret = is_mtp_active(dev_p);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (cy_as_device_is_in_callback(dev_p))
return CY_AS_ERROR_INVALID_IN_CALLBACK;
if (cy_as_device_is_m_s_s_pending(dev_p))
return CY_AS_ERROR_STARTSTOP_PENDING;
cy_as_device_set_m_s_s_pending(dev_p);
if (dev_p->mtp_count == 1) {
req_p = cy_as_ll_create_request(dev_p, CY_RQT_STOP_MTP,
CY_RQT_TUR_RQT_CONTEXT, 0);
if (req_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return my_handle_response_mtp_stop(dev_p, req_p,
reply_p, ret);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_STOP, 0, dev_p->func_cbs_mtp,
CY_AS_REQUEST_RESPONSE_EX, req_p, reply_p,
cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
} else if (dev_p->mtp_count > 1) {
dev_p->mtp_count--;
if (cb)
cb(handle, ret, client, CY_FUNCT_CB_MTP_STOP, 0);
}
cy_as_device_clear_m_s_s_pending(dev_p);
return ret;
}
static void
mtp_write_callback(
cy_as_device *dev_p,
uint8_t context,
cy_as_ll_request_response *rqt,
cy_as_ll_request_response *resp,
cy_as_return_status_t ret)
{
cy_as_hal_assert(context == CY_RQT_TUR_RQT_CONTEXT);
if (ret == CY_AS_ERROR_SUCCESS) {
if (cy_as_ll_request_response__get_code(resp) !=
CY_RESP_SUCCESS_FAILURE)
ret = CY_AS_ERROR_INVALID_RESPONSE;
else
ret = cy_as_ll_request_response__get_word(resp, 0);
}
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_dma_cancel(dev_p, 0x04, CY_AS_ERROR_CANCELED);
cy_as_device_clear_storage_async_pending(dev_p);
}
cy_as_ll_destroy_response(dev_p, resp);
cy_as_ll_destroy_request(dev_p, rqt);
}
static void
async_write_request_callback(cy_as_device *dev_p,
cy_as_end_point_number_t ep, void *buf_p, uint32_t size,
cy_as_return_status_t err)
{
cy_as_device_handle h;
cy_as_function_callback cb;
(void)size;
(void)buf_p;
(void)ep;
cy_as_log_debug_message(6, "async_write_request_callback called");
h = (cy_as_device_handle)dev_p;
cb = dev_p->mtp_cb;
dev_p->mtp_cb = 0;
cy_as_device_clear_storage_async_pending(dev_p);
if (cb)
cb(h, err, dev_p->mtp_client, dev_p->mtp_op, 0);
}
static void
sync_mtp_callback(cy_as_device *dev_p, cy_as_end_point_number_t ep,
void *buf_p, uint32_t size, cy_as_return_status_t err)
{
(void)ep;
(void)buf_p;
(void)size;
dev_p->mtp_error = err;
}
static cy_as_return_status_t
cy_as_mtp_operation(cy_as_device *dev_p,
cy_as_mtp_block_table *blk_table,
uint32_t num_bytes,
uint32_t transaction_id,
cy_as_function_callback cb,
uint32_t client,
uint8_t rqttype
)
{
cy_as_ll_request_response *req_p = 0, *reply_p = 0;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint32_t mask = 0;
cy_as_funct_c_b_type mtp_cb_op = 0;
uint16_t size = 2;
if (dev_p->mtp_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
if (rqttype == CY_RQT_INIT_SEND_OBJECT) {
mtp_cb_op = CY_FUNCT_CB_MTP_INIT_SEND_OBJECT;
dev_p->mtp_turbo_active = cy_true;
} else if (rqttype == CY_RQT_INIT_GET_OBJECT) {
mtp_cb_op = CY_FUNCT_CB_MTP_INIT_GET_OBJECT;
dev_p->mtp_turbo_active = cy_true;
} else
mtp_cb_op = CY_FUNCT_CB_MTP_SEND_BLOCK_TABLE;
ret = is_mtp_active(dev_p);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (CY_RQT_INIT_GET_OBJECT == rqttype)
size = 4;
req_p = cy_as_ll_create_request(dev_p, rqttype,
CY_RQT_TUR_RQT_CONTEXT, size);
if (req_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
cy_as_ll_request_response__set_word(req_p, 0,
(uint16_t)(num_bytes & 0xFFFF));
cy_as_ll_request_response__set_word(req_p, 1,
(uint16_t)((num_bytes >> 16) & 0xFFFF));
if (CY_RQT_INIT_GET_OBJECT == rqttype) {
cy_as_ll_request_response__set_word(req_p, 2,
(uint16_t)(transaction_id & 0xFFFF));
cy_as_ll_request_response__set_word(req_p, 3,
(uint16_t)((transaction_id >> 16) & 0xFFFF));
}
if (cb == 0) {
ret = cy_as_dma_queue_request(dev_p, 4, blk_table,
sizeof(cy_as_mtp_block_table), cy_false,
cy_false, sync_mtp_callback);
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_dma_cancel(dev_p, 4, CY_AS_ERROR_CANCELED);
cy_as_device_clear_storage_async_pending(dev_p);
goto destroy;
}
ret = cy_as_dma_drain_queue(dev_p, 4, cy_true);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
ret = dev_p->mtp_error;
goto destroy;
} else {
#if 0
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_INIT_SEND_OBJECT,
0, dev_p->func_cbs_mtp, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
#endif
mask = cy_as_hal_disable_interrupts();
if ((cy_as_device_is_storage_async_pending(dev_p)) ||
(dev_p->storage_wait)) {
cy_as_hal_enable_interrupts(mask);
return CY_AS_ERROR_ASYNC_PENDING;
}
cy_as_device_set_storage_async_pending(dev_p);
cy_as_hal_enable_interrupts(mask);
dev_p->mtp_cb = cb;
dev_p->mtp_client = client;
dev_p->mtp_op = mtp_cb_op;
ret = cy_as_ll_send_request(dev_p, req_p, reply_p,
cy_false, mtp_write_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
ret = cy_as_dma_queue_request(dev_p, 4, blk_table,
sizeof(cy_as_mtp_block_table), cy_false, cy_false,
async_write_request_callback);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
cy_as_dma_kick_start(dev_p, 4);
return CY_AS_ERROR_SUCCESS;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_init_send_object(cy_as_device_handle handle,
cy_as_mtp_block_table *blk_table,
uint32_t num_bytes,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
return cy_as_mtp_operation(dev_p, blk_table, num_bytes, 0, cb,
client, CY_RQT_INIT_SEND_OBJECT);
}
cy_as_return_status_t
cy_as_mtp_init_get_object(cy_as_device_handle handle,
cy_as_mtp_block_table *blk_table,
uint32_t num_bytes,
uint32_t transaction_id,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
return cy_as_mtp_operation(dev_p, blk_table, num_bytes,
transaction_id, cb, client, CY_RQT_INIT_GET_OBJECT);
}
static cy_as_return_status_t
my_handle_response_cancel_send_object(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_return_status_t ret)
{
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_cancel_send_object(cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_ll_request_response *req_p = 0, *reply_p = 0;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (dev_p->mtp_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
req_p = cy_as_ll_create_request(dev_p,
CY_RQT_CANCEL_SEND_OBJECT, CY_RQT_TUR_RQT_CONTEXT, 0);
if (req_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return my_handle_response_cancel_send_object(dev_p,
req_p, reply_p, ret);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_CANCEL_SEND_OBJECT, 0,
dev_p->func_cbs_mtp, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
static cy_as_return_status_t
my_handle_response_cancel_get_object(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_return_status_t ret)
{
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_cancel_get_object(cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client
)
{
cy_as_ll_request_response *req_p = 0, *reply_p = 0;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (dev_p->mtp_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_CANCEL_GET_OBJECT,
CY_RQT_TUR_RQT_CONTEXT, 0);
if (req_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
ret = CY_AS_ERROR_OUT_OF_MEMORY;
goto destroy;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return my_handle_response_cancel_get_object(dev_p,
req_p, reply_p, ret);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_CANCEL_GET_OBJECT, 0,
dev_p->func_cbs_mtp, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_mtp_send_block_table(cy_as_device_handle handle,
cy_as_mtp_block_table *blk_table,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
return cy_as_mtp_operation(dev_p, blk_table, 0, 0, cb,
client, CY_RQT_SEND_BLOCK_TABLE);
}
static void
cy_as_mtp_func_callback(cy_as_device *dev_p,
uint8_t context,
cy_as_ll_request_response *rqt,
cy_as_ll_request_response *resp,
cy_as_return_status_t stat)
{
cy_as_func_c_b_node* node = (cy_as_func_c_b_node *)
dev_p->func_cbs_mtp->head_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint8_t code;
cy_bool delay_callback = cy_false;
cy_as_hal_assert(dev_p->func_cbs_mtp->count != 0);
cy_as_hal_assert(dev_p->func_cbs_mtp->type == CYAS_FUNC_CB);
(void)context;
code = cy_as_ll_request_response__get_code(rqt);
switch (code) {
case CY_RQT_START_MTP:
ret = my_handle_response_mtp_start(dev_p, rqt,
resp, stat);
break;
case CY_RQT_STOP_MTP:
ret = my_handle_response_mtp_stop(dev_p, rqt,
resp, stat);
break;
#if 0
case CY_RQT_INIT_SEND_OBJECT:
ret = my_handle_response_init_send_object(dev_p,
rqt, resp, stat, cy_true);
delay_callback = cy_true;
break;
#endif
case CY_RQT_CANCEL_SEND_OBJECT:
ret = my_handle_response_cancel_send_object(dev_p,
rqt, resp, stat);
break;
#if 0
case CY_RQT_INIT_GET_OBJECT:
ret = my_handle_response_init_get_object(dev_p,
rqt, resp, stat, cy_true);
delay_callback = cy_true;
break;
#endif
case CY_RQT_CANCEL_GET_OBJECT:
ret = my_handle_response_cancel_get_object(dev_p,
rqt, resp, stat);
break;
#if 0
case CY_RQT_SEND_BLOCK_TABLE:
ret = my_handle_response_send_block_table(dev_p, rqt,
resp, stat, cy_true);
delay_callback = cy_true;
break;
#endif
case CY_RQT_ENABLE_USB_PATH:
ret = my_handle_response_no_data(dev_p, rqt, resp);
if (ret == CY_AS_ERROR_SUCCESS)
dev_p->is_storage_only_mode = cy_false;
break;
default:
ret = CY_AS_ERROR_INVALID_RESPONSE;
cy_as_hal_assert(cy_false);
break;
}
if (stat == CY_AS_ERROR_SUCCESS)
stat = ret;
if (!delay_callback) {
node->cb_p((cy_as_device_handle)dev_p, stat, node->client_data,
node->data_type, node->data);
cy_as_remove_c_b_node(dev_p->func_cbs_mtp);
}
}
cy_as_return_status_t
cy_as_mtp_storage_only_start(cy_as_device_handle handle)
{
cy_as_device *dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
if (!cy_as_device_is_firmware_loaded(dev_p))
return CY_AS_ERROR_NO_FIRMWARE;
if (dev_p->storage_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
dev_p->is_storage_only_mode = cy_true;
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_mtp_storage_only_stop(cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p = (cy_as_device *)handle;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
if (!cy_as_device_is_firmware_loaded(dev_p))
return CY_AS_ERROR_NO_FIRMWARE;
if (dev_p->storage_count == 0)
return CY_AS_ERROR_NOT_RUNNING;
if (dev_p->is_storage_only_mode == cy_false)
return CY_AS_ERROR_SUCCESS;
if (cy_as_device_is_in_callback(dev_p))
return CY_AS_ERROR_INVALID_IN_CALLBACK;
req_p = cy_as_ll_create_request(dev_p,
CY_RQT_ENABLE_USB_PATH, CY_RQT_TUR_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
ret = my_handle_response_no_data(dev_p, req_p,
reply_p);
if (ret == CY_AS_ERROR_SUCCESS)
dev_p->is_storage_only_mode = cy_false;
return ret;
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MTP_STOP_STORAGE_ONLY, 0,
dev_p->func_cbs_mtp, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_mtp_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
