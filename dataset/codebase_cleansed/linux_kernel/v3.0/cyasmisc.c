void
cy_as_misc_set_log_level(uint8_t level)
{
debug_level = level;
}
void
cy_as_log_debug_message(int level, const char *str)
{
if (level <= debug_level)
cy_as_hal_print_message("log %d: %s\n", level, str);
}
cy_as_device *
cy_as_device_find_from_tag(cy_as_hal_device_tag tag)
{
cy_as_device *dev_p;
for (dev_p = g_device_list; dev_p != 0; dev_p = dev_p->next_p) {
if (dev_p->tag == tag)
return dev_p;
}
return 0;
}
static void
cy_as_bus_from_media_type(cy_as_media_type type,
cy_as_bus_number_t *bus)
{
if (type == cy_as_media_nand)
*bus = 0;
else
*bus = 1;
}
static cy_as_return_status_t
my_handle_response_no_data(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE)
ret = CY_AS_ERROR_INVALID_RESPONSE;
else
ret = cy_as_ll_request_response__get_word(reply_p, 0);
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_misc_create_device(cy_as_device_handle *handle_p,
cy_as_hal_device_tag tag)
{
cy_as_device *dev_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_log_debug_message(6, "cy_as_misc_create_device called");
dev_p = (cy_as_device *)cy_as_hal_alloc(sizeof(cy_as_device));
if (dev_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_hal_mem_set(dev_p, 0, sizeof(cy_as_device));
dev_p->usb_ep_data = (uint8_t *)cy_as_hal_alloc(64 * sizeof(uint8_t));
if (dev_p->usb_ep_data == 0) {
cy_as_hal_free(dev_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
dev_p->sig = CY_AS_DEVICE_HANDLE_SIGNATURE;
dev_p->tag = tag;
dev_p->usb_max_tx_size = 0x40;
dev_p->storage_write_endpoint = CY_AS_P2S_WRITE_ENDPOINT;
dev_p->storage_read_endpoint = CY_AS_P2S_READ_ENDPOINT;
dev_p->func_cbs_misc = cy_as_create_c_b_queue(CYAS_FUNC_CB);
if (dev_p->func_cbs_misc == 0)
goto destroy;
dev_p->func_cbs_res = cy_as_create_c_b_queue(CYAS_FUNC_CB);
if (dev_p->func_cbs_res == 0)
goto destroy;
dev_p->func_cbs_stor = cy_as_create_c_b_queue(CYAS_FUNC_CB);
if (dev_p->func_cbs_stor == 0)
goto destroy;
dev_p->func_cbs_usb = cy_as_create_c_b_queue(CYAS_FUNC_CB);
if (dev_p->func_cbs_usb == 0)
goto destroy;
dev_p->func_cbs_mtp = cy_as_create_c_b_queue(CYAS_FUNC_CB);
if (dev_p->func_cbs_mtp == 0)
goto destroy;
ret = cy_as_dma_start(dev_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
cy_as_device_set_dma_stopped(dev_p);
ret = cy_as_ll_start(dev_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
cy_as_device_set_low_level_stopped(dev_p);
dev_p->next_p = g_device_list;
g_device_list = dev_p;
*handle_p = dev_p;
cy_as_hal_init_dev_registers(tag, cy_false);
return CY_AS_ERROR_SUCCESS;
destroy:
if (dev_p->func_cbs_misc)
cy_as_destroy_c_b_queue(dev_p->func_cbs_misc);
if (dev_p->func_cbs_res)
cy_as_destroy_c_b_queue(dev_p->func_cbs_res);
if (dev_p->func_cbs_stor)
cy_as_destroy_c_b_queue(dev_p->func_cbs_stor);
if (dev_p->func_cbs_usb)
cy_as_destroy_c_b_queue(dev_p->func_cbs_usb);
if (dev_p->func_cbs_mtp)
cy_as_destroy_c_b_queue(dev_p->func_cbs_mtp);
cy_as_hal_free(dev_p->usb_ep_data);
cy_as_hal_free(dev_p);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
else
return CY_AS_ERROR_OUT_OF_MEMORY;
}
cy_as_return_status_t
cy_as_misc_destroy_device(cy_as_device_handle handle)
{
cy_as_return_status_t ret;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_destroy_device called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (dev_p->usb_count > 0)
return CY_AS_ERROR_STILL_RUNNING;
if (dev_p->storage_count > 0)
return CY_AS_ERROR_STILL_RUNNING;
if (cy_as_device_is_intr_running(dev_p))
ret = cy_as_intr_stop(dev_p);
ret = cy_as_ll_stop(dev_p);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_intr_start(dev_p, dev_p->use_int_drq);
return ret;
}
ret = cy_as_dma_stop(dev_p);
if (ret != CY_AS_ERROR_SUCCESS) {
cy_as_intr_start(dev_p, dev_p->use_int_drq);
return ret;
}
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_RST_CTRL_REG,
CY_AS_MEM_RST_CTRL_REG_HARD);
if (g_device_list == dev_p) {
g_device_list = dev_p->next_p;
} else {
cy_as_device *tmp_p = g_device_list;
while (tmp_p && tmp_p->next_p != dev_p)
tmp_p = tmp_p->next_p;
cy_as_hal_assert(tmp_p != 0);
tmp_p->next_p = dev_p->next_p;
}
dev_p->sig = 0;
cy_as_destroy_c_b_queue(dev_p->func_cbs_misc);
cy_as_destroy_c_b_queue(dev_p->func_cbs_res);
cy_as_destroy_c_b_queue(dev_p->func_cbs_stor);
cy_as_destroy_c_b_queue(dev_p->func_cbs_usb);
cy_as_destroy_c_b_queue(dev_p->func_cbs_mtp);
cy_as_hal_free(dev_p->usb_ep_data);
cy_as_hal_free(dev_p);
return CY_AS_ERROR_SUCCESS;
}
static void
cy_as_setup_endian_mode(cy_as_device *dev_p)
{
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_P0_ENDIAN,
CY_AS_LITTLE_ENDIAN);
}
cy_as_return_status_t
cy_as_misc_in_standby(cy_as_device_handle handle, cy_bool *standby)
{
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_in_standby called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (cy_as_device_is_pin_standby(dev_p) ||
cy_as_device_is_register_standby(dev_p)) {
*standby = cy_true;
} else
*standby = cy_false;
return CY_AS_ERROR_SUCCESS;
}
static void
my_misc_callback(cy_as_device *dev_p, uint8_t context,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *resp_p,
cy_as_return_status_t ret)
{
(void)resp_p;
(void)context;
(void)ret;
switch (cy_as_ll_request_response__get_code(req_p)) {
case CY_RQT_INITIALIZATION_COMPLETE:
{
uint16_t v;
cy_as_ll_send_status_response(dev_p,
CY_RQT_GENERAL_RQT_CONTEXT,
CY_AS_ERROR_SUCCESS, 0);
cy_as_device_set_firmware_loaded(dev_p);
if (cy_as_device_is_waking(dev_p)) {
if (dev_p->misc_event_cb)
dev_p->misc_event_cb(
(cy_as_device_handle)dev_p,
cy_as_event_misc_awake, 0);
cy_as_device_clear_waking(dev_p);
} else {
v = cy_as_ll_request_response__get_word
(req_p, 3);
dev_p->media_supported[0] =
(uint8_t)(v & 0xFF);
dev_p->media_supported[1] =
(uint8_t)((v >> 8) & 0xFF);
v = cy_as_ll_request_response__get_word
(req_p, 4);
dev_p->is_mtp_firmware =
(cy_bool)((v >> 8) & 0xFF);
if (dev_p->misc_event_cb)
dev_p->misc_event_cb(
(cy_as_device_handle)dev_p,
cy_as_event_misc_initialized, 0);
}
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_P0_VM_SET);
if (v & CY_AS_MEM_P0_VM_SET_CFGMODE)
cy_as_hal_print_message(
"initialization message "
"received, but config bit "
"still set\n");
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG);
if ((v & CY_AS_MEM_RST_RSTCMPT) == 0)
cy_as_hal_print_message(
"initialization message "
"received, but reset complete "
"bit still not set\n");
}
break;
case CY_RQT_OUT_OF_SUSPEND:
cy_as_ll_send_status_response(dev_p, CY_RQT_GENERAL_RQT_CONTEXT,
CY_AS_ERROR_SUCCESS, 0);
cy_as_device_clear_suspend_mode(dev_p);
if (dev_p->func_cbs_misc->count > 0) {
cy_as_func_c_b_node *node = (cy_as_func_c_b_node *)
dev_p->func_cbs_misc->head_p;
cy_as_hal_assert(node);
if (cy_as_funct_c_b_type_get_type(node->data_type) ==
CY_FUNCT_CB_MISC_LEAVESUSPEND) {
cy_as_hal_assert(node->cb_p != 0);
node->cb_p((cy_as_device_handle)dev_p,
CY_AS_ERROR_SUCCESS, node->client_data,
CY_FUNCT_CB_MISC_LEAVESUSPEND, 0);
cy_as_remove_c_b_node(dev_p->func_cbs_misc);
}
}
if (dev_p->misc_event_cb)
dev_p->misc_event_cb((cy_as_device_handle)dev_p,
cy_as_event_misc_wakeup, 0);
break;
case CY_RQT_DEBUG_MESSAGE:
if ((req_p->data[0] == 0) && (req_p->data[1] == 0) &&
(req_p->data[2] == 0)) {
if (dev_p->misc_event_cb)
dev_p->misc_event_cb((cy_as_device_handle)dev_p,
cy_as_event_misc_heart_beat, 0);
} else {
cy_as_hal_print_message(
"**** debug message: %02x "
"%02x %02x %02x %02x %02x\n",
req_p->data[0] & 0xff,
(req_p->data[0] >> 8) & 0xff,
req_p->data[1] & 0xff,
(req_p->data[1] >> 8) & 0xff,
req_p->data[2] & 0xff,
(req_p->data[2] >> 8) & 0xff);
}
break;
case CY_RQT_WB_DEVICE_MISMATCH:
{
if (dev_p->misc_event_cb)
dev_p->misc_event_cb((cy_as_device_handle)dev_p,
cy_as_event_misc_device_mismatch, 0);
}
break;
case CY_RQT_BOOTLOAD_NO_FIRMWARE:
{
cy_as_hal_print_message("no firmware image found "
"during bootload. device not started\n");
}
break;
default:
cy_as_hal_assert(0);
}
}
static cy_bool
is_valid_silicon_id(uint16_t v)
{
cy_bool idok = cy_false;
v = v & CY_AS_MEM_CM_WB_CFG_ID_HDID_MASK;
if (v == CY_AS_MEM_CM_WB_CFG_ID_HDID_ANTIOCH_VALUE ||
v == CY_AS_MEM_CM_WB_CFG_ID_HDID_ASTORIA_FPGA_VALUE ||
v == CY_AS_MEM_CM_WB_CFG_ID_HDID_ASTORIA_VALUE)
idok = cy_true;
return idok;
}
cy_as_return_status_t
cy_as_misc_configure_device(cy_as_device_handle handle,
cy_as_device_config *config_p)
{
cy_as_return_status_t ret;
cy_bool standby;
cy_as_device *dev_p;
uint16_t v;
uint16_t fw_present;
cy_as_log_debug_message(6, "cy_as_misc_configure_device called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
cy_as_setup_endian_mode(dev_p);
dev_p->silicon_id = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
fw_present = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG);
if (!(fw_present & CY_AS_MEM_RST_RSTCMPT)) {
if (!is_valid_silicon_id(dev_p->silicon_id))
return CY_AS_ERROR_NO_ANTIOCH;
}
ret = cy_as_misc_in_standby(handle, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (ret)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_astoria_dev(dev_p)) {
if (config_p->srammode)
v = CY_AS_MEM_P0_VM_SET_VMTYPE_SRAM;
else
v = CY_AS_MEM_P0_VM_SET_VMTYPE_RAM;
} else
v = CY_AS_MEM_P0_VM_SET_VMTYPE_RAM;
if (config_p->sync)
v |= CY_AS_MEM_P0_VM_SET_IFMODE;
if (config_p->dackmode == cy_as_device_dack_ack)
v |= CY_AS_MEM_P0_VM_SET_DACKEOB;
if (config_p->drqpol)
v |= CY_AS_MEM_P0_VM_SET_DRQPOL;
if (config_p->dackpol)
v |= CY_AS_MEM_P0_VM_SET_DACKPOL;
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_P0_VM_SET, v);
if (config_p->crystal)
cy_as_device_set_crystal(dev_p);
else
cy_as_device_set_external_clock(dev_p);
cy_as_ll_register_request_callback(dev_p,
CY_RQT_GENERAL_RQT_CONTEXT, my_misc_callback);
cy_as_device_set_dma_running(dev_p);
cy_as_device_set_low_level_running(dev_p);
dev_p->use_int_drq = config_p->dmaintr;
ret = cy_as_intr_start(dev_p, config_p->dmaintr);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
cy_as_device_set_configured(dev_p);
return CY_AS_ERROR_SUCCESS;
}
static void
my_dma_callback(cy_as_device *dev_p,
cy_as_end_point_number_t ep,
void *mem_p,
uint32_t size,
cy_as_return_status_t ret
)
{
cy_as_dma_end_point *ep_p;
(void)size;
ep_p = CY_AS_NUM_EP(dev_p, ep);
if (ep_p->queue_p == 0) {
cy_as_func_c_b_node *node =
(cy_as_func_c_b_node *)dev_p->func_cbs_misc->head_p;
cy_as_hal_assert(node);
if (ret == CY_AS_ERROR_SUCCESS) {
cy_as_dma_enable_end_point(dev_p,
CY_AS_FIRMWARE_ENDPOINT,
cy_false, cy_as_direction_in);
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG, 0x00);
}
node->cb_p((cy_as_device_handle)dev_p, ret, node->client_data,
node->data_type, node->data);
cy_as_remove_c_b_node(dev_p->func_cbs_misc);
} else {
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(mem_p);
cy_as_hal_enable_interrupts(state);
}
}
cy_as_return_status_t
cy_as_misc_download_firmware(cy_as_device_handle handle,
const void *mem_p,
uint16_t size,
cy_as_function_callback cb,
uint32_t client)
{
uint8_t *header;
cy_as_return_status_t ret;
cy_bool standby;
cy_as_device *dev_p;
cy_as_dma_callback dmacb = 0;
uint32_t state;
cy_as_log_debug_message(6, "cy_as_misc_download_firmware called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
ret = cy_as_misc_in_standby(dev_p, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (standby)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_VM_SET) &
CY_AS_MEM_P0_VM_SET_CFGMODE) == 0)
return CY_AS_ERROR_NOT_IN_CONFIG_MODE;
if (size > CY_AS_MAXIMUM_FIRMWARE_SIZE)
return CY_AS_ERROR_INVALID_SIZE;
if (size & 0x01)
return CY_AS_ERROR_ALIGNMENT_ERROR;
state = cy_as_hal_disable_interrupts();
header = (uint8_t *)cy_as_hal_c_b_alloc(4);
cy_as_hal_enable_interrupts(state);
if (header == NULL)
return CY_AS_ERROR_OUT_OF_MEMORY;
header[0] = 0x00;
header[1] = 0x00;
header[2] = (uint8_t)(size & 0xff);
header[3] = (uint8_t)((size >> 8) & 0xff);
ret = cy_as_dma_enable_end_point(dev_p, CY_AS_FIRMWARE_ENDPOINT,
cy_true, cy_as_direction_in);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
cy_as_dma_set_max_dma_size(dev_p, CY_AS_FIRMWARE_ENDPOINT, 64);
if (cb)
dmacb = my_dma_callback;
ret = cy_as_dma_queue_request(dev_p, CY_AS_FIRMWARE_ENDPOINT, header,
4, cy_false, cy_false, dmacb);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
ret = cy_as_dma_queue_request(dev_p, CY_AS_FIRMWARE_ENDPOINT,
(void *)mem_p, size, cy_false, cy_false, dmacb);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (cb) {
cy_as_func_c_b_node *cbnode = cy_as_create_func_c_b_node_data(
cb, client, CY_FUNCT_CB_MISC_DOWNLOADFIRMWARE, 0);
if (cbnode == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
else
cy_as_insert_c_b_node(dev_p->func_cbs_misc, cbnode);
ret = cy_as_dma_kick_start(dev_p, CY_AS_FIRMWARE_ENDPOINT);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
} else {
ret = cy_as_dma_drain_queue(dev_p,
CY_AS_FIRMWARE_ENDPOINT, cy_true);
cy_as_hal_c_b_free(header);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
cy_as_dma_enable_end_point(dev_p, CY_AS_FIRMWARE_ENDPOINT,
cy_false, cy_as_direction_in);
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG, 0x00);
}
return CY_AS_ERROR_SUCCESS;
}
static cy_as_return_status_t
my_handle_response_get_firmware_version(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_get_firmware_version_data *data_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint16_t val;
if (cy_as_ll_request_response__get_code(reply_p)
!= CY_RESP_FIRMWARE_VERSION) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
data_p->major = cy_as_ll_request_response__get_word(reply_p, 0);
data_p->minor = cy_as_ll_request_response__get_word(reply_p, 1);
data_p->build = cy_as_ll_request_response__get_word(reply_p, 2);
val = cy_as_ll_request_response__get_word(reply_p, 3);
data_p->media_type = (uint8_t)(((val >> 8) & 0xFF) | (val & 0xFF));
val = cy_as_ll_request_response__get_word(reply_p, 4);
data_p->is_debug_mode = (cy_bool)(val & 0xFF);
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_misc_get_firmware_version(cy_as_device_handle handle,
cy_as_get_firmware_version_data *data,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_bool standby;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
(void)client;
cy_as_log_debug_message(6, "cy_as_misc_get_firmware_version called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
ret = cy_as_misc_in_standby(dev_p, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (standby)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_GET_FIRMWARE_VERSION,
CY_RQT_GENERAL_RQT_CONTEXT, 0);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
reply_p = cy_as_ll_create_response(dev_p, 5);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
ret = my_handle_response_get_firmware_version(dev_p,
req_p, reply_p, data);
return ret;
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_GETFIRMWAREVERSION, data,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
my_handle_response_read_m_c_u_register(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
uint8_t *data_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (cy_as_ll_request_response__get_code(reply_p)
!= CY_RESP_MCU_REGISTER_DATA) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
*data_p = (uint8_t)
(cy_as_ll_request_response__get_word(reply_p, 0));
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
static cy_as_return_status_t
my_handle_response_get_gpio_value(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
uint8_t *data_p)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (cy_as_ll_request_response__get_code(reply_p)
!= CY_RESP_GPIO_STATE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
} else
*data_p = (uint8_t)
(cy_as_ll_request_response__get_word(reply_p, 0));
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t cy_as_misc_set_sd_power_polarity(
cy_as_device_handle handle,
cy_as_misc_signal_polarity polarity,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_device *dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (!cy_as_device_is_configured(dev_p))
return CY_AS_ERROR_NOT_CONFIGURED;
if (!cy_as_device_is_firmware_loaded(dev_p))
return CY_AS_ERROR_NO_FIRMWARE;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_SDPOLARITY,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0,
(uint16_t)polarity);
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return (my_handle_response_no_data(dev_p, req_p, reply_p));
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_SETSDPOLARITY, 0, dev_p->func_cbs_misc,
CY_AS_REQUEST_RESPONSE_EX, req_p, reply_p,
cy_as_misc_func_callback);
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
cy_as_misc_read_m_c_u_register(cy_as_device_handle handle,
uint16_t address,
uint8_t *value,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_read_m_c_u_register called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_nand_storage_supported(dev_p))
return CY_AS_ERROR_NOT_SUPPORTED;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_READ_MCU_REGISTER,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0, (uint16_t)address);
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_MCU_REGISTER_DATA) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
*value = (uint8_t)(cy_as_ll_request_response__get_word
(reply_p, 0));
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_READMCUREGISTER, value,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
cy_as_misc_write_m_c_u_register(cy_as_device_handle handle,
uint16_t address,
uint8_t mask,
uint8_t value,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_write_m_c_u_register called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_nand_storage_supported(dev_p))
return CY_AS_ERROR_NOT_SUPPORTED;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_WRITE_MCU_REGISTER,
CY_RQT_GENERAL_RQT_CONTEXT, 2);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0, (uint16_t)address);
cy_as_ll_request_response__set_word(req_p, 1,
(uint16_t)((mask << 8) | value));
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_WRITEMCUREGISTER, 0,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
my_handle_response_reset(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_reset_type type)
{
uint16_t v;
(void)req_p;
(void)reply_p;
if (cy_as_device_is_in_suspend_mode(dev_p)) {
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
cy_as_hal_sleep(1);
}
if (type == cy_as_reset_hard) {
cy_as_misc_cancel_ex_requests(dev_p);
cy_as_hal_write_register(dev_p->tag, CY_AS_MEM_RST_CTRL_REG,
CY_AS_MEM_RST_CTRL_REG_HARD);
cy_as_device_set_unconfigured(dev_p);
cy_as_device_set_firmware_not_loaded(dev_p);
cy_as_device_set_dma_stopped(dev_p);
cy_as_device_set_low_level_stopped(dev_p);
cy_as_device_set_intr_stopped(dev_p);
cy_as_device_clear_suspend_mode(dev_p);
cy_as_usb_cleanup(dev_p);
cy_as_storage_cleanup(dev_p);
cy_as_hal_sleep(100);
}
cy_as_device_clear_reset_pending(dev_p);
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_misc_reset(cy_as_device_handle handle,
cy_as_reset_type type,
cy_bool flush,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_end_point_number_t i;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
(void)client;
(void)cb;
cy_as_log_debug_message(6, "cy_as_misc_reset_e_x called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (type == cy_as_reset_soft)
return CY_AS_ERROR_NOT_YET_SUPPORTED;
cy_as_device_set_reset_pending(dev_p);
if (flush) {
if ((dev_p->storage_cb || dev_p->storage_cb_ms) &&
cy_as_hal_is_polling())
return CY_AS_ERROR_ASYNC_PENDING;
for (i = 0; i < 15; i++)
cy_as_dma_enable_end_point(dev_p, i, cy_false,
cy_as_direction_dont_change);
if (cy_as_device_is_in_suspend_mode(dev_p)) {
for (i = 0; i < 15; i++)
cy_as_dma_cancel(dev_p, i,
CY_AS_ERROR_CANCELED);
} else {
for (i = 0; i < 15; i++) {
if ((i == CY_AS_P2S_WRITE_ENDPOINT) ||
(i == CY_AS_P2S_READ_ENDPOINT))
cy_as_dma_drain_queue(dev_p, i,
cy_false);
else
cy_as_dma_drain_queue(dev_p, i,
cy_true);
}
}
} else {
if (cy_as_device_is_storage_async_pending(dev_p)) {
for (i = 0; i < 15; i++)
cy_as_dma_cancel(dev_p, i,
CY_AS_ERROR_CANCELED);
}
}
ret = my_handle_response_reset(dev_p, 0, 0, type);
if (cb)
cb((cy_as_device_handle)dev_p, ret, client,
CY_FUNCT_CB_MISC_RESET, 0);
cy_as_hal_init_dev_registers(dev_p->tag, cy_false);
return ret;
}
static cy_as_return_status_t
get_unallocated_resource(cy_as_device *dev_p, cy_as_resource_type resource)
{
uint8_t shift = 0;
uint16_t v;
cy_as_return_status_t ret = CY_AS_ERROR_NOT_ACQUIRED;
switch (resource) {
case cy_as_bus_u_s_b:
shift = 4;
break;
case cy_as_bus_1:
shift = 0;
break;
case cy_as_bus_0:
shift = 2;
break;
default:
cy_as_hal_assert(cy_false);
break;
}
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_RSE_ALLOCATE);
v = (v >> shift) & 0x03;
if (v == 0x03) {
ret = CY_AS_ERROR_RESOURCE_ALREADY_OWNED;
} else if ((v & 0x01) == 0) {
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_P0_RSE_MASK, (0x03 << shift));
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_RSE_MASK);
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_P0_RSE_ALLOCATE, (0x01 << shift));
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_P0_RSE_MASK);
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_P0_RSE_ALLOCATE);
v = (v >> shift) & 0x03;
if (v == 0x03)
ret = CY_AS_ERROR_SUCCESS;
}
return ret;
}
static cy_as_return_status_t
my_handle_response_acquire_resource(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_resource_type *resource)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
if (ret == CY_AS_ERROR_SUCCESS) {
ret = get_unallocated_resource(dev_p, *resource);
if (ret != CY_AS_ERROR_NOT_ACQUIRED)
ret = CY_AS_ERROR_SUCCESS;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_misc_acquire_resource(cy_as_device_handle handle,
cy_as_resource_type *resource,
cy_bool force,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret;
cy_as_device *dev_p;
(void)client;
cy_as_log_debug_message(6, "cy_as_misc_acquire_resource called");
if (*resource != cy_as_bus_u_s_b && *resource !=
cy_as_bus_0 && *resource != cy_as_bus_1)
return CY_AS_ERROR_INVALID_RESOURCE;
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
ret = get_unallocated_resource(dev_p, *resource);
if ((ret == CY_AS_ERROR_SUCCESS) && (cb != 0))
cb(handle, ret, client,
CY_FUNCT_CB_MISC_ACQUIRERESOURCE, resource);
if (ret != CY_AS_ERROR_NOT_ACQUIRED)
return ret;
if (!force)
return CY_AS_ERROR_NOT_ACQUIRED;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_ACQUIRE_RESOURCE,
CY_RQT_RESOURCE_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0, (uint16_t)(*resource));
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_ACQUIRERESOURCE, resource,
dev_p->func_cbs_res, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
if (ret == CY_AS_ERROR_SUCCESS) {
ret = get_unallocated_resource(dev_p, *resource);
if (ret != CY_AS_ERROR_NOT_ACQUIRED)
ret = CY_AS_ERROR_SUCCESS;
}
return ret;
}
cy_as_return_status_t
cy_as_misc_release_resource(cy_as_device_handle handle,
cy_as_resource_type resource)
{
uint8_t shift = 0;
uint16_t v;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_release_resource called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if (resource != cy_as_bus_u_s_b && resource !=
cy_as_bus_0 && resource != cy_as_bus_1)
return CY_AS_ERROR_INVALID_RESOURCE;
switch (resource) {
case cy_as_bus_u_s_b:
shift = 4;
break;
case cy_as_bus_1:
shift = 0;
break;
case cy_as_bus_0:
shift = 2;
break;
default:
cy_as_hal_assert(cy_false);
break;
}
v = (cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_P0_RSE_ALLOCATE) >> shift) & 0x03;
if (v == 0 || v == 1 || v == 2)
return CY_AS_ERROR_RESOURCE_NOT_OWNED;
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_P0_RSE_MASK, (0x03 << shift));
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_P0_RSE_ALLOCATE, (0x02 << shift));
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_P0_RSE_MASK, 0);
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_misc_set_trace_level(cy_as_device_handle handle,
uint8_t level,
cy_as_bus_number_t bus,
uint32_t device,
uint32_t unit,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_set_trace_level called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if (bus < 0 || bus >= CY_AS_MAX_BUSES)
return CY_AS_ERROR_NO_SUCH_BUS;
if (device >= CY_AS_MAX_STORAGE_DEVICES)
return CY_AS_ERROR_NO_SUCH_DEVICE;
if (unit > 255)
return CY_AS_ERROR_NO_SUCH_UNIT;
if (level >= CYAS_FW_TRACE_MAX_LEVEL)
return CY_AS_ERROR_INVALID_TRACE_LEVEL;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_SET_TRACE_LEVEL,
CY_RQT_GENERAL_RQT_CONTEXT, 2);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0,
(uint16_t)level);
cy_as_ll_request_response__set_word(req_p, 1,
(uint16_t)((bus << 12) | (device << 8) | (unit)));
reply_p = cy_as_ll_create_response(dev_p, 2);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_NOT_SUPPORTED;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_SETTRACELEVEL, 0, dev_p->func_cbs_misc,
CY_AS_REQUEST_RESPONSE_EX, req_p, reply_p,
cy_as_misc_func_callback);
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
cy_as_misc_heart_beat_control(cy_as_device_handle handle,
cy_bool enable,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_ll_request_response *req_p, *reply_p;
cy_as_return_status_t ret;
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_heart_beat_control called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_CONTROL_ANTIOCH_HEARTBEAT,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0, (uint16_t)enable);
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_HEARTBEATCONTROL, 0,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
my_set_sd_clock_freq(
cy_as_device *dev_p,
uint8_t card_type,
uint8_t setting,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
if (cy_as_device_is_in_callback(dev_p) && (cb == 0))
return CY_AS_ERROR_INVALID_IN_CALLBACK;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_SET_SD_CLOCK_FREQ,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0,
(uint16_t)((card_type << 8) | setting));
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_SETSDFREQ, 0, dev_p->func_cbs_misc,
CY_AS_REQUEST_RESPONSE_EX, req_p, reply_p,
cy_as_misc_func_callback);
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
cy_as_misc_set_low_speed_sd_freq(
cy_as_device_handle handle,
cy_as_low_speed_sd_freq setting,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_set_low_speed_sd_freq called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((setting != CY_AS_SD_DEFAULT_FREQ) &&
(setting != CY_AS_SD_RATED_FREQ))
return CY_AS_ERROR_INVALID_PARAMETER;
return my_set_sd_clock_freq(dev_p, 0, (uint8_t)setting, cb, client);
}
cy_as_return_status_t
cy_as_misc_set_high_speed_sd_freq(
cy_as_device_handle handle,
cy_as_high_speed_sd_freq setting,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_set_high_speed_sd_freq called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((setting != CY_AS_HS_SD_FREQ_24) &&
(setting != CY_AS_HS_SD_FREQ_48))
return CY_AS_ERROR_INVALID_PARAMETER;
return my_set_sd_clock_freq(dev_p, 1, (uint8_t)setting, cb, client);
}
cy_as_return_status_t
cy_as_misc_get_gpio_value(cy_as_device_handle handle,
cy_as_misc_gpio pin,
uint8_t *value,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
uint16_t v;
cy_as_log_debug_message(6, "cy_as_misc_get_gpio_value called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (pin == cy_as_misc_gpio_U_valid) {
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_PMU_UPDATE);
*value = (uint8_t)(v & CY_AS_MEM_PMU_UPDATE_UVALID);
if (cb != 0)
cb(dev_p, ret, client,
CY_FUNCT_CB_MISC_GETGPIOVALUE, value);
return ret;
}
if (cy_as_device_is_nand_storage_supported(dev_p))
return CY_AS_ERROR_NOT_SUPPORTED;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((pin != cy_as_misc_gpio_1) && (pin != cy_as_misc_gpio_0))
return CY_AS_ERROR_INVALID_PARAMETER;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_GET_GPIO_STATE,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p, 0, ((uint8_t)pin << 8));
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_GPIO_STATE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
*value = (uint8_t)
cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_GETGPIOVALUE, value,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
cy_as_misc_set_gpio_value(cy_as_device_handle handle,
cy_as_misc_gpio pin,
uint8_t value,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
uint16_t v;
cy_as_log_debug_message(6, "cy_as_misc_set_gpio_value called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (pin == cy_as_misc_gpio_U_valid) {
v = cy_as_hal_read_register(dev_p->tag, CY_AS_MEM_PMU_UPDATE);
if (value)
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_PMU_UPDATE,
(v | CY_AS_MEM_PMU_UPDATE_UVALID));
else
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_PMU_UPDATE,
(v & ~CY_AS_MEM_PMU_UPDATE_UVALID));
if (cb != 0)
cb(dev_p, ret, client,
CY_FUNCT_CB_MISC_SETGPIOVALUE, 0);
return ret;
}
if (cy_as_device_is_nand_storage_supported(dev_p))
return CY_AS_ERROR_NOT_SUPPORTED;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((pin < cy_as_misc_gpio_0) || (pin > cy_as_misc_gpio_U_valid))
return CY_AS_ERROR_INVALID_PARAMETER;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_SET_GPIO_STATE,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
v = (uint16_t)(((uint8_t)pin << 8) | (value > 0));
cy_as_ll_request_response__set_word(req_p, 0, v);
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_SETGPIOVALUE, 0,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
my_enter_standby(cy_as_device *dev_p, cy_bool pin)
{
cy_as_misc_cancel_ex_requests(dev_p);
cy_as_hal_read_regs_before_standby(dev_p->tag);
if (pin) {
if (cy_as_hal_set_wakeup_pin(dev_p->tag, cy_false))
cy_as_device_set_pin_standby(dev_p);
else
return CY_AS_ERROR_SETTING_WAKEUP_PIN;
} else {
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_PWR_MAGT_STAT, 0x02);
cy_as_device_set_register_standby(dev_p);
}
cy_as_device_set_firmware_not_loaded(dev_p);
dev_p->stby_int_mask = cy_as_hal_disable_interrupts();
return CY_AS_ERROR_SUCCESS;
}
static cy_as_return_status_t
my_handle_response_enter_standby(cy_as_device *dev_p,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_bool pin)
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
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
ret = my_enter_standby(dev_p, pin);
return ret;
}
cy_as_return_status_t
cy_as_misc_enter_standby(cy_as_device_handle handle,
cy_bool pin,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_ll_request_response *req_p, *reply_p;
cy_bool standby;
cy_as_log_debug_message(6, "cy_as_misc_enter_standby called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
ret = cy_as_misc_in_standby(handle, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (standby == cy_true)
return CY_AS_ERROR_ALREADY_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
cy_as_misc_leave_suspend(dev_p, 0, 0);
if (dev_p->usb_count) {
return CY_AS_ERROR_USB_RUNNING;
}
if (dev_p->storage_count) {
if (cy_as_device_is_storage_async_pending(dev_p)) {
if (cy_as_hal_is_polling())
return CY_AS_ERROR_ASYNC_PENDING;
cy_as_dma_drain_queue(dev_p,
CY_AS_P2S_READ_ENDPOINT, cy_false);
cy_as_dma_drain_queue(dev_p,
CY_AS_P2S_WRITE_ENDPOINT, cy_false);
if (cy_as_device_is_storage_async_pending(dev_p))
return CY_AS_ERROR_ASYNC_PENDING;
}
req_p = cy_as_ll_create_request(dev_p,
CY_RQT_PREPARE_FOR_STANDBY,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (!cb) {
ret = cy_as_ll_send_request_wait_reply(dev_p,
req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return my_handle_response_enter_standby(dev_p,
req_p, reply_p, pin);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_ENTERSTANDBY, (void *)pin,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
} else {
ret = my_enter_standby(dev_p, pin);
if (cb)
cb((cy_as_device_handle)dev_p, ret, client,
CY_FUNCT_CB_MISC_ENTERSTANDBY, 0);
}
return ret;
}
cy_as_return_status_t
cy_as_misc_enter_standby_e_x_u(cy_as_device_handle handle,
cy_bool pin,
cy_bool uvalid_special,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
dev_p = (cy_as_device *)handle;
if (uvalid_special)
cy_as_hal_write_register(dev_p->tag, 0xc5, 0x4);
return cy_as_misc_enter_standby(handle, pin, cb, client);
}
cy_as_return_status_t
cy_as_misc_leave_standby(cy_as_device_handle handle,
cy_as_resource_type resource)
{
cy_as_device *dev_p;
uint16_t v;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
uint32_t count = 8;
uint8_t retry = 1;
cy_as_log_debug_message(6, "cy_as_misc_leave_standby called");
(void)resource;
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
if (cy_as_device_is_register_standby(dev_p)) {
cy_as_device_set_waking(dev_p);
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
do {
if (cy_as_device_is_crystal(dev_p))
cy_as_hal_sleep(
CY_AS_LEAVE_STANDBY_DELAY_CRYSTAL);
else
cy_as_hal_sleep(
CY_AS_LEAVE_STANDBY_DELAY_CLOCK);
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
if (!is_valid_silicon_id(v)) {
if (cy_as_hal_sync_device_clocks(dev_p->tag) !=
cy_true) {
cy_as_hal_enable_interrupts(
dev_p->stby_int_mask);
return CY_AS_ERROR_TIMEOUT;
}
}
} while (!is_valid_silicon_id(v) && count-- > 0);
if (count == 0) {
cy_as_hal_enable_interrupts(
dev_p->stby_int_mask);
return CY_AS_ERROR_TIMEOUT;
}
cy_as_device_clear_register_standby(dev_p);
cy_as_hal_init_dev_registers(dev_p->tag, cy_true);
} else if (cy_as_device_is_pin_standby(dev_p)) {
cy_as_device_set_waking(dev_p);
try_wakeup_again:
if (!cy_as_hal_set_wakeup_pin(dev_p->tag, cy_true)) {
cy_as_hal_enable_interrupts(dev_p->stby_int_mask);
return CY_AS_ERROR_SETTING_WAKEUP_PIN;
}
if (cy_as_device_is_crystal(dev_p))
cy_as_hal_sleep(CY_AS_LEAVE_STANDBY_DELAY_CRYSTAL);
else
cy_as_hal_sleep(CY_AS_LEAVE_STANDBY_DELAY_CLOCK);
cy_as_hal_init_dev_registers(dev_p->tag, cy_true);
cy_as_device_clear_pin_standby(dev_p);
} else {
return CY_AS_ERROR_NOT_IN_STANDBY;
}
cy_as_hal_enable_interrupts(dev_p->stby_int_mask);
v = 0x03;
count = 0x08;
while ((v & 0x03) && (count)) {
cy_as_hal_write_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG, 0x00);
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_RST_CTRL_REG);
count--;
}
if (v & 0x03) {
cy_as_hal_print_message("failed to clear antioch reset\n");
return CY_AS_ERROR_TIMEOUT;
}
if (retry) {
count = 10;
while (count) {
if (cy_as_device_is_firmware_loaded(dev_p))
break;
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_P0_INTR_REG);
if (v & CY_AS_MEM_P0_INTR_REG_MBINT)
break;
cy_as_hal_sleep(10);
count--;
}
if (!count) {
retry = 0;
dev_p->stby_int_mask = cy_as_hal_disable_interrupts();
cy_as_hal_set_wakeup_pin(dev_p->tag, cy_false);
cy_as_hal_sleep(10);
goto try_wakeup_again;
}
}
return ret;
}
cy_as_return_status_t
cy_as_misc_register_callback(
cy_as_device_handle handle,
cy_as_misc_event_callback callback
)
{
cy_as_device *dev_p;
cy_as_log_debug_message(6, "cy_as_misc_register_callback called");
dev_p = (cy_as_device *)handle;
if (!dev_p || (dev_p->sig != CY_AS_DEVICE_HANDLE_SIGNATURE))
return CY_AS_ERROR_INVALID_HANDLE;
dev_p->misc_event_cb = callback;
return CY_AS_ERROR_SUCCESS;
}
cy_as_return_status_t
cy_as_misc_storage_changed(cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_bool standby;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_log_debug_message(6, "cy_as_misc_storage_changed called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
ret = cy_as_misc_in_standby(dev_p, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (standby)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p, CY_RQT_STORAGE_MEDIA_CHANGED,
CY_RQT_GENERAL_RQT_CONTEXT, 0);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
if (cb == 0) {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_STORAGECHANGED, 0,
dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
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
cy_as_misc_enter_suspend(
cy_as_device_handle handle,
cy_bool usb_wakeup_en,
cy_bool gpio_wakeup_en,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_bool standby;
cy_as_ll_request_response *req_p, *reply_p;
uint16_t value;
uint32_t int_state;
cy_as_log_debug_message(6, "cy_as_misc_enter_suspend called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
cy_as_misc_in_standby(dev_p, &standby);
if (standby)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
if ((cy_as_device_is_usb_connected(dev_p)) && (dev_p->usb_last_event
!= cy_as_event_usb_suspend))
return CY_AS_ERROR_USB_CONNECTED;
int_state = cy_as_hal_disable_interrupts();
if ((dev_p->func_cbs_misc->count) || (dev_p->func_cbs_res->count) ||
(dev_p->func_cbs_stor->count) || (dev_p->func_cbs_usb->count)) {
cy_as_hal_enable_interrupts(int_state);
return CY_AS_ERROR_ASYNC_PENDING;
}
cy_as_hal_enable_interrupts(int_state);
req_p = cy_as_ll_create_request(dev_p, CY_RQT_ENTER_SUSPEND_MODE,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
reply_p = cy_as_ll_create_response(dev_p, 1);
if (reply_p == 0) {
cy_as_ll_destroy_request(dev_p, req_p);
return CY_AS_ERROR_OUT_OF_MEMORY;
}
value = 0x0001;
if (usb_wakeup_en)
value |= 0x04;
if (gpio_wakeup_en)
value |= 0x02;
cy_as_ll_request_response__set_word(req_p, 0, value);
if (cb != 0) {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_ENTERSUSPEND,
0, dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p,
cy_as_misc_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return CY_AS_ERROR_SUCCESS;
} else {
ret = cy_as_ll_send_request_wait_reply(dev_p, req_p, reply_p);
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE)
ret = CY_AS_ERROR_INVALID_RESPONSE;
else
ret = cy_as_ll_request_response__get_word(reply_p, 0);
}
destroy:
if (ret == CY_AS_ERROR_SUCCESS)
cy_as_device_set_suspend_mode(dev_p);
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_return_status_t
cy_as_misc_leave_suspend(
cy_as_device_handle handle,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_device *dev_p;
uint16_t v, count;
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_as_log_debug_message(6, "cy_as_misc_leave_suspend called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
if (cy_as_device_is_in_suspend_mode(dev_p)) {
if (cb) {
cy_as_func_c_b_node *cbnode =
cy_as_create_func_c_b_node_data(cb, client,
CY_FUNCT_CB_MISC_LEAVESUSPEND, 0);
if (cbnode == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_insert_c_b_node(dev_p->func_cbs_misc, cbnode);
}
count = 8;
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
while (!is_valid_silicon_id(v) && count-- > 0) {
cy_as_hal_sleep(CY_AS_LEAVE_STANDBY_DELAY_CLOCK);
v = cy_as_hal_read_register(dev_p->tag,
CY_AS_MEM_CM_WB_CFG_ID);
}
if (count == 0)
return CY_AS_ERROR_TIMEOUT;
} else
return CY_AS_ERROR_NOT_IN_SUSPEND;
if (cb == 0) {
count = 20;
while ((cy_as_device_is_in_suspend_mode(dev_p))
&& (count--)) {
cy_as_hal_sleep(CY_AS_LEAVE_STANDBY_DELAY_CLOCK);
}
if (cy_as_device_is_in_suspend_mode(dev_p))
ret = CY_AS_ERROR_TIMEOUT;
}
return ret;
}
cy_as_return_status_t
cy_as_misc_reserve_l_n_a_boot_area(cy_as_device_handle handle,
uint8_t numzones,
cy_as_function_callback cb,
uint32_t client)
{
cy_as_return_status_t ret = CY_AS_ERROR_SUCCESS;
cy_bool standby;
cy_as_ll_request_response *req_p, *reply_p;
cy_as_device *dev_p;
(void)client;
cy_as_log_debug_message(6, "cy_as_misc_switch_pnand_mode called");
dev_p = (cy_as_device *)handle;
cy_as_check_device_ready(dev_p);
ret = cy_as_misc_in_standby(dev_p, &standby);
if (ret != CY_AS_ERROR_SUCCESS)
return ret;
if (standby)
return CY_AS_ERROR_IN_STANDBY;
if (cy_as_device_is_in_suspend_mode(dev_p))
return CY_AS_ERROR_IN_SUSPEND;
req_p = cy_as_ll_create_request(dev_p,
CY_RQT_RESERVE_LNA_BOOT_AREA,
CY_RQT_GENERAL_RQT_CONTEXT, 1);
if (req_p == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
cy_as_ll_request_response__set_word(req_p,
0, (uint16_t)numzones);
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
if (cy_as_ll_request_response__get_code(reply_p) !=
CY_RESP_SUCCESS_FAILURE) {
ret = CY_AS_ERROR_INVALID_RESPONSE;
goto destroy;
}
ret = cy_as_ll_request_response__get_word(reply_p, 0);
} else {
ret = cy_as_misc_send_request(dev_p, cb, client,
CY_FUNCT_CB_MISC_RESERVELNABOOTAREA,
0, dev_p->func_cbs_misc, CY_AS_REQUEST_RESPONSE_EX,
req_p, reply_p, cy_as_misc_func_callback);
if (ret != CY_AS_ERROR_SUCCESS)
goto destroy;
return ret;
}
destroy:
cy_as_ll_destroy_request(dev_p, req_p);
cy_as_ll_destroy_response(dev_p, reply_p);
return ret;
}
cy_as_func_c_b_node*
cy_as_create_func_c_b_node_data(cy_as_function_callback cb,
uint32_t client,
cy_as_funct_c_b_type type,
void *data)
{
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_func_c_b_node *node = cy_as_hal_c_b_alloc(
sizeof(cy_as_func_c_b_node));
cy_as_hal_enable_interrupts(state);
if (node != 0) {
node->node_type = CYAS_FUNC_CB;
node->cb_p = cb;
node->client_data = client;
node->data_type = type;
if (data != 0)
node->data_type |= CY_FUNCT_CB_DATA;
else
node->data_type |= CY_FUNCT_CB_NODATA;
node->data = data;
node->next_p = 0;
}
return node;
}
cy_as_func_c_b_node*
cy_as_create_func_c_b_node(cy_as_function_callback cb,
uint32_t client)
{
return cy_as_create_func_c_b_node_data(cb, client,
CY_FUNCT_CB_NODATA, 0);
}
void
cy_as_destroy_func_c_b_node(cy_as_func_c_b_node *node)
{
uint32_t state;
node->node_type = CYAS_INVALID;
state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(node);
cy_as_hal_enable_interrupts(state);
}
cy_as_usb_func_c_b_node*
cy_as_create_usb_func_c_b_node(
cy_as_usb_function_callback cb, uint32_t client)
{
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_usb_func_c_b_node *node = cy_as_hal_c_b_alloc(
sizeof(cy_as_usb_func_c_b_node));
cy_as_hal_enable_interrupts(state);
if (node != 0) {
node->type = CYAS_USB_FUNC_CB;
node->cb_p = cb;
node->client_data = client;
node->next_p = 0;
}
return node;
}
void
cy_as_destroy_usb_func_c_b_node(cy_as_usb_func_c_b_node *node)
{
uint32_t state;
node->type = CYAS_INVALID;
state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(node);
cy_as_hal_enable_interrupts(state);
}
cy_as_usb_io_c_b_node*
cy_as_create_usb_io_c_b_node(cy_as_usb_io_callback cb)
{
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_usb_io_c_b_node *node = cy_as_hal_c_b_alloc(
sizeof(cy_as_usb_io_c_b_node));
cy_as_hal_enable_interrupts(state);
if (node != 0) {
node->type = CYAS_USB_IO_CB;
node->cb_p = cb;
node->next_p = 0;
}
return node;
}
void
cy_as_destroy_usb_io_c_b_node(cy_as_usb_io_c_b_node *node)
{
uint32_t state;
node->type = CYAS_INVALID;
state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(node);
cy_as_hal_enable_interrupts(state);
}
cy_as_storage_io_c_b_node*
cy_as_create_storage_io_c_b_node(cy_as_storage_callback cb,
cy_as_media_type media, uint32_t device_index,
uint32_t unit, uint32_t block_addr, cy_as_oper_type oper,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p)
{
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_storage_io_c_b_node *node = cy_as_hal_c_b_alloc(
sizeof(cy_as_storage_io_c_b_node));
cy_as_hal_enable_interrupts(state);
if (node != 0) {
node->type = CYAS_STORAGE_IO_CB;
node->cb_p = cb;
node->media = media;
node->device_index = device_index;
node->unit = unit;
node->block_addr = block_addr;
node->oper = oper;
node->req_p = req_p;
node->reply_p = reply_p;
node->next_p = 0;
}
return node;
}
void
cy_as_destroy_storage_io_c_b_node(cy_as_storage_io_c_b_node *node)
{
uint32_t state;
node->type = CYAS_INVALID;
state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(node);
cy_as_hal_enable_interrupts(state);
}
cy_as_c_b_queue *
cy_as_create_c_b_queue(cy_as_c_b_node_type type)
{
uint32_t state = cy_as_hal_disable_interrupts();
cy_as_c_b_queue *queue = cy_as_hal_c_b_alloc(
sizeof(cy_as_c_b_queue));
cy_as_hal_enable_interrupts(state);
if (queue) {
queue->type = type;
queue->head_p = 0;
queue->tail_p = 0;
queue->count = 0;
}
return queue;
}
void
cy_as_destroy_c_b_queue(cy_as_c_b_queue *queue)
{
uint32_t state;
queue->type = CYAS_INVALID;
queue->head_p = 0;
queue->tail_p = 0;
queue->count = 0;
state = cy_as_hal_disable_interrupts();
cy_as_hal_c_b_free(queue);
cy_as_hal_enable_interrupts(state);
}
void
cy_as_insert_c_b_node(cy_as_c_b_queue *queue_p, void*cbnode)
{
uint32_t int_state;
int_state = cy_as_hal_disable_interrupts();
cy_as_hal_assert(queue_p != 0);
switch (queue_p->type) {
case CYAS_USB_FUNC_CB:
{
cy_as_usb_func_c_b_node *node =
(cy_as_usb_func_c_b_node *)cbnode;
cy_as_usb_func_c_b_node *tail =
(cy_as_usb_func_c_b_node *)queue_p->tail_p;
cy_as_hal_assert(node->type == CYAS_USB_FUNC_CB);
cy_as_hal_assert(tail == 0 ||
tail->type == CYAS_USB_FUNC_CB);
if (queue_p->head_p == 0)
queue_p->head_p = node;
else
tail->next_p = node;
queue_p->tail_p = node;
}
break;
case CYAS_USB_IO_CB:
{
cy_as_usb_io_c_b_node *node =
(cy_as_usb_io_c_b_node *)cbnode;
cy_as_usb_io_c_b_node *tail =
(cy_as_usb_io_c_b_node *)queue_p->tail_p;
cy_as_hal_assert(node->type == CYAS_USB_IO_CB);
cy_as_hal_assert(tail == 0 ||
tail->type == CYAS_USB_IO_CB);
if (queue_p->head_p == 0)
queue_p->head_p = node;
else
tail->next_p = node;
queue_p->tail_p = node;
}
break;
case CYAS_STORAGE_IO_CB:
{
cy_as_storage_io_c_b_node *node =
(cy_as_storage_io_c_b_node *)cbnode;
cy_as_storage_io_c_b_node *tail =
(cy_as_storage_io_c_b_node *)queue_p->tail_p;
cy_as_hal_assert(node->type == CYAS_STORAGE_IO_CB);
cy_as_hal_assert(tail == 0 ||
tail->type == CYAS_STORAGE_IO_CB);
if (queue_p->head_p == 0)
queue_p->head_p = node;
else
tail->next_p = node;
queue_p->tail_p = node;
}
break;
case CYAS_FUNC_CB:
{
cy_as_func_c_b_node *node =
(cy_as_func_c_b_node *)cbnode;
cy_as_func_c_b_node *tail =
(cy_as_func_c_b_node *)queue_p->tail_p;
cy_as_hal_assert(node->node_type == CYAS_FUNC_CB);
cy_as_hal_assert(tail == 0 ||
tail->node_type == CYAS_FUNC_CB);
if (queue_p->head_p == 0)
queue_p->head_p = node;
else
tail->next_p = node;
queue_p->tail_p = node;
}
break;
default:
cy_as_hal_assert(cy_false);
break;
}
queue_p->count++;
cy_as_hal_enable_interrupts(int_state);
}
void
cy_as_remove_c_b_tail_node(cy_as_c_b_queue *queue_p)
{
uint32_t int_state;
int_state = cy_as_hal_disable_interrupts();
if (queue_p->count > 0) {
switch (queue_p->type) {
case CYAS_FUNC_CB:
{
cy_as_func_c_b_node *node =
(cy_as_func_c_b_node *)
queue_p->head_p;
cy_as_func_c_b_node *tail =
(cy_as_func_c_b_node *)
queue_p->tail_p;
if (node != tail) {
while (node->next_p != tail)
node = node->next_p;
node->next_p = 0;
queue_p->tail_p = node;
}
cy_as_destroy_func_c_b_node(tail);
}
break;
case CYAS_USB_FUNC_CB:
{
cy_as_usb_func_c_b_node *node =
(cy_as_usb_func_c_b_node *)
queue_p->head_p;
cy_as_usb_func_c_b_node *tail =
(cy_as_usb_func_c_b_node *)
queue_p->tail_p;
if (node != tail) {
while (node->next_p != tail)
node = node->next_p;
node->next_p = 0;
queue_p->tail_p = node;
}
cy_as_destroy_usb_func_c_b_node(tail);
}
break;
case CYAS_USB_IO_CB:
{
cy_as_usb_io_c_b_node *node =
(cy_as_usb_io_c_b_node *)
queue_p->head_p;
cy_as_usb_io_c_b_node *tail =
(cy_as_usb_io_c_b_node *)
queue_p->tail_p;
if (node != tail) {
while (node->next_p != tail)
node = node->next_p;
node->next_p = 0;
queue_p->tail_p = node;
}
cy_as_destroy_usb_io_c_b_node(tail);
}
break;
case CYAS_STORAGE_IO_CB:
{
cy_as_storage_io_c_b_node *node =
(cy_as_storage_io_c_b_node *)
queue_p->head_p;
cy_as_storage_io_c_b_node *tail =
(cy_as_storage_io_c_b_node *)
queue_p->tail_p;
if (node != tail) {
while (node->next_p != tail)
node = node->next_p;
node->next_p = 0;
queue_p->tail_p = node;
}
cy_as_destroy_storage_io_c_b_node(tail);
}
break;
default:
cy_as_hal_assert(cy_false);
}
queue_p->count--;
if (queue_p->count == 0) {
queue_p->head_p = 0;
queue_p->tail_p = 0;
}
}
cy_as_hal_enable_interrupts(int_state);
}
void
cy_as_remove_c_b_node(cy_as_c_b_queue *queue_p)
{
uint32_t int_state;
int_state = cy_as_hal_disable_interrupts();
cy_as_hal_assert(queue_p->count >= 0);
if (queue_p->count > 0) {
if (queue_p->type == CYAS_USB_FUNC_CB) {
cy_as_usb_func_c_b_node *node =
(cy_as_usb_func_c_b_node *)
queue_p->head_p;
queue_p->head_p = node->next_p;
cy_as_destroy_usb_func_c_b_node(node);
} else if (queue_p->type == CYAS_USB_IO_CB) {
cy_as_usb_io_c_b_node *node =
(cy_as_usb_io_c_b_node *)
queue_p->head_p;
queue_p->head_p = node->next_p;
cy_as_destroy_usb_io_c_b_node(node);
} else if (queue_p->type == CYAS_STORAGE_IO_CB) {
cy_as_storage_io_c_b_node *node =
(cy_as_storage_io_c_b_node *)
queue_p->head_p;
queue_p->head_p = node->next_p;
cy_as_destroy_storage_io_c_b_node(node);
} else if (queue_p->type == CYAS_FUNC_CB) {
cy_as_func_c_b_node *node =
(cy_as_func_c_b_node *)
queue_p->head_p;
queue_p->head_p = node->next_p;
cy_as_destroy_func_c_b_node(node);
} else {
cy_as_hal_assert(cy_false);
}
queue_p->count--;
if (queue_p->count == 0) {
queue_p->head_p = 0;
queue_p->tail_p = 0;
}
}
cy_as_hal_enable_interrupts(int_state);
}
void my_print_func_c_b_node(cy_as_func_c_b_node *node)
{
cy_as_funct_c_b_type type =
cy_as_funct_c_b_type_get_type(node->data_type);
cy_as_hal_print_message("[cd:%2u dt:%2u cb:0x%08x "
"d:0x%08x nt:%1i]", node->client_data, type,
(uint32_t)node->cb_p, (uint32_t)node->data,
node->node_type);
}
void my_print_c_b_queue(cy_as_c_b_queue *queue_p)
{
uint32_t i = 0;
cy_as_hal_print_message("| count: %u type: ", queue_p->count);
if (queue_p->type == CYAS_USB_FUNC_CB) {
cy_as_hal_print_message("USB_FUNC_CB\n");
} else if (queue_p->type == CYAS_USB_IO_CB) {
cy_as_hal_print_message("USB_IO_CB\n");
} else if (queue_p->type == CYAS_STORAGE_IO_CB) {
cy_as_hal_print_message("STORAGE_IO_CB\n");
} else if (queue_p->type == CYAS_FUNC_CB) {
cy_as_func_c_b_node *node = queue_p->head_p;
cy_as_hal_print_message("FUNC_CB\n");
if (queue_p->count > 0) {
cy_as_hal_print_message("| head->");
for (i = 0; i < queue_p->count; i++) {
if (node) {
cy_as_hal_print_message("->");
my_print_func_c_b_node(node);
node = node->next_p;
} else
cy_as_hal_print_message("->[NULL]\n");
}
cy_as_hal_print_message("\n| tail->");
my_print_func_c_b_node(queue_p->tail_p);
cy_as_hal_print_message("\n");
}
} else {
cy_as_hal_print_message("INVALID\n");
}
cy_as_hal_print_message("|----------\n");
}
void
cy_as_clear_c_b_queue(cy_as_c_b_queue *queue_p)
{
uint32_t int_state = cy_as_hal_disable_interrupts();
while (queue_p->count != 0)
cy_as_remove_c_b_node(queue_p);
cy_as_hal_enable_interrupts(int_state);
}
cy_as_return_status_t
cy_as_misc_send_request(cy_as_device *dev_p,
cy_as_function_callback cb,
uint32_t client,
cy_as_funct_c_b_type type,
void *data,
cy_as_c_b_queue *queue,
uint16_t req_type,
cy_as_ll_request_response *req_p,
cy_as_ll_request_response *reply_p,
cy_as_response_callback rcb)
{
cy_as_func_c_b_node *cbnode = cy_as_create_func_c_b_node_data(cb,
client, type, data);
cy_as_return_status_t ret;
if (cbnode == 0)
return CY_AS_ERROR_OUT_OF_MEMORY;
else
cy_as_insert_c_b_node(queue, cbnode);
req_p->flags |= req_type;
ret = cy_as_ll_send_request(dev_p, req_p, reply_p, cy_false, rcb);
if (ret != CY_AS_ERROR_SUCCESS)
cy_as_remove_c_b_tail_node(queue);
return ret;
}
void
cy_as_misc_cancel_ex_requests(cy_as_device *dev_p)
{
int i;
for (i = 0; i < CY_RQT_CONTEXT_COUNT; i++)
cy_as_ll_remove_all_requests(dev_p, dev_p->context[i]);
}
static void
cy_as_misc_func_callback(cy_as_device *dev_p,
uint8_t context,
cy_as_ll_request_response *rqt,
cy_as_ll_request_response *resp,
cy_as_return_status_t stat)
{
cy_as_func_c_b_node *node = NULL;
cy_as_return_status_t ret;
cy_bool ex_request = (rqt->flags & CY_AS_REQUEST_RESPONSE_EX)
== CY_AS_REQUEST_RESPONSE_EX;
cy_bool ms_request = (rqt->flags & CY_AS_REQUEST_RESPONSE_MS)
== CY_AS_REQUEST_RESPONSE_MS;
uint8_t code;
uint32_t type;
uint8_t cntxt;
cy_as_hal_assert(ex_request || ms_request);
(void) ex_request;
(void) ms_request;
(void)context;
cntxt = cy_as_ll_request_response__get_context(rqt);
code = cy_as_ll_request_response__get_code(rqt);
switch (cntxt) {
case CY_RQT_GENERAL_RQT_CONTEXT:
cy_as_hal_assert(dev_p->func_cbs_misc->count != 0);
cy_as_hal_assert(dev_p->func_cbs_misc->type == CYAS_FUNC_CB);
node = (cy_as_func_c_b_node *)dev_p->func_cbs_misc->head_p;
type = cy_as_funct_c_b_type_get_type(node->data_type);
switch (code) {
case CY_RQT_GET_FIRMWARE_VERSION:
cy_as_hal_assert(node->data != 0);
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_GETFIRMWAREVERSION);
ret = my_handle_response_get_firmware_version(dev_p,
rqt, resp,
(cy_as_get_firmware_version_data *)node->data);
break;
case CY_RQT_READ_MCU_REGISTER:
cy_as_hal_assert(node->data != 0);
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_READMCUREGISTER);
ret = my_handle_response_read_m_c_u_register(dev_p, rqt,
resp, (uint8_t *)node->data);
break;
case CY_RQT_GET_GPIO_STATE:
cy_as_hal_assert(node->data != 0);
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_GETGPIOVALUE);
ret = my_handle_response_get_gpio_value(dev_p, rqt,
resp, (uint8_t *)node->data);
break;
case CY_RQT_SET_SD_CLOCK_FREQ:
cy_as_hal_assert(type == CY_FUNCT_CB_MISC_SETSDFREQ);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_CONTROL_ANTIOCH_HEARTBEAT:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_HEARTBEATCONTROL);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_WRITE_MCU_REGISTER:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_WRITEMCUREGISTER);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_STORAGE_MEDIA_CHANGED:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_STORAGECHANGED);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_SET_GPIO_STATE:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_SETGPIOVALUE);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_SET_TRACE_LEVEL:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_SETTRACELEVEL);
ret = my_handle_response_no_data(dev_p, rqt, resp);
if (ret == CY_AS_ERROR_INVALID_RESPONSE)
ret = CY_AS_ERROR_NOT_SUPPORTED;
break;
case CY_RQT_PREPARE_FOR_STANDBY:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_ENTERSTANDBY);
ret = my_handle_response_enter_standby(dev_p, rqt, resp,
(cy_bool)node->data);
break;
case CY_RQT_ENTER_SUSPEND_MODE:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_ENTERSUSPEND);
ret = my_handle_response_no_data(dev_p, rqt, resp);
if (ret == CY_AS_ERROR_SUCCESS)
cy_as_device_set_suspend_mode(dev_p);
break;
case CY_RQT_RESERVE_LNA_BOOT_AREA:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_RESERVELNABOOTAREA);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
case CY_RQT_SDPOLARITY:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_SETSDPOLARITY);
ret = my_handle_response_no_data(dev_p, rqt, resp);
break;
default:
ret = CY_AS_ERROR_INVALID_RESPONSE;
cy_as_hal_assert(cy_false);
break;
}
break;
case CY_RQT_RESOURCE_RQT_CONTEXT:
cy_as_hal_assert(dev_p->func_cbs_res->count != 0);
cy_as_hal_assert(dev_p->func_cbs_res->type == CYAS_FUNC_CB);
node = (cy_as_func_c_b_node *)dev_p->func_cbs_res->head_p;
type = cy_as_funct_c_b_type_get_type(node->data_type);
switch (code) {
case CY_RQT_ACQUIRE_RESOURCE:
cy_as_hal_assert(type ==
CY_FUNCT_CB_MISC_ACQUIRERESOURCE);
ret = my_handle_response_acquire_resource(dev_p, rqt,
resp, (cy_as_resource_type *)node->data);
break;
default:
ret = CY_AS_ERROR_INVALID_RESPONSE;
cy_as_hal_assert(cy_false);
break;
}
break;
default:
ret = CY_AS_ERROR_INVALID_RESPONSE;
cy_as_hal_assert(cy_false);
break;
}
if (stat == CY_AS_ERROR_SUCCESS)
stat = ret;
node->cb_p((cy_as_device_handle)dev_p, stat, node->client_data,
node->data_type, node->data);
if (cntxt == CY_RQT_GENERAL_RQT_CONTEXT)
cy_as_remove_c_b_node(dev_p->func_cbs_misc);
else
cy_as_remove_c_b_node(dev_p->func_cbs_res);
}
