card_t* unifi_alloc_card(CsrSdioFunction *sdio, void *ospriv)
{
card_t *card;
u32 i;
func_enter();
card = kzalloc(sizeof(card_t), GFP_KERNEL);
if (card == NULL)
{
return NULL;
}
card->sdio_if = sdio;
card->ospriv = ospriv;
card->unifi_interrupt_seq = 1;
card->proc_select = (u32)(-1);
card->dmem_page = (u32)(-1);
card->pmem_page = (u32)(-1);
card->bh_reason_host = 0;
card->bh_reason_unifi = 0;
for (i = 0; i < sizeof(card->tx_q_paused_flag) / sizeof(card->tx_q_paused_flag[0]); i++)
{
card->tx_q_paused_flag[i] = 0;
}
card->memory_resources_allocated = 0;
card->low_power_mode = UNIFI_LOW_POWER_DISABLED;
card->periodic_wake_mode = UNIFI_PERIODIC_WAKE_HOST_DISABLED;
card->host_state = UNIFI_HOST_STATE_AWAKE;
card->intmode = CSR_WIFI_INTMODE_DEFAULT;
card->fh_command_queue.q_body = card->fh_command_q_body;
card->fh_command_queue.q_length = UNIFI_SOFT_COMMAND_Q_LENGTH;
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->fh_traffic_queue[i].q_body = card->fh_traffic_q_body[i];
card->fh_traffic_queue[i].q_length = UNIFI_SOFT_TRAFFIC_Q_LENGTH;
}
card->request_coredump_on_reset = 0;
card->dump_next_write = NULL;
card->dump_cur_read = NULL;
card->dump_buf = NULL;
#ifdef UNIFI_DEBUG
{
u32 val = 0x01234567;
if (*((u8 *)&val) == 0x01)
{
card->lsb = sizeof(void *) - 1;
}
else
{
card->lsb = 0;
}
}
#endif
func_exit();
return card;
}
CsrResult unifi_init_card(card_t *card, s32 led_mask)
{
CsrResult r;
func_enter();
if (card == NULL)
{
func_exit_r(CSR_WIFI_HIP_RESULT_INVALID_VALUE);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_init(card);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
r = unifi_hip_init(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
func_exit_r(r);
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to start host protocol.\n");
func_exit_r(r);
return r;
}
func_exit();
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_init(card_t *card)
{
CsrResult r;
CsrResult csrResult;
func_enter();
if (card == NULL)
{
func_exit_r(CSR_WIFI_HIP_RESULT_INVALID_VALUE);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
csrResult = CsrSdioInterruptDisable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_SAFE_HZ);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
func_exit_r(r);
return r;
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_SAFE_HZ;
unifi_trace(card->ospriv, UDBG1, "Resetting UniFi\n");
r = unifi_reset_hardware(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to reset UniFi\n");
func_exit_r(r);
return r;
}
r = unifi_configure_low_power_mode(card,
UNIFI_LOW_POWER_DISABLED, UNIFI_PERIODIC_WAKE_HOST_DISABLED);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to set power save mode\n");
func_exit_r(r);
return r;
}
card->proc_select = (u32)(-1);
card->dmem_page = (u32)(-1);
card->pmem_page = (u32)(-1);
r = unifi_write_direct16(card, ChipHelper_HOST_WINDOW3_PAGE(card->helper) * 2, 0);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write SHARED_DMEM_PAGE\n");
func_exit_r(r);
return r;
}
r = unifi_write_direct16(card, ChipHelper_HOST_WINDOW2_PAGE(card->helper) * 2, 0);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write PROG_MEM2_PAGE\n");
func_exit_r(r);
return r;
}
(void)unifi_coredump_handle_request(card);
r = firmware_present_in_flash(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r == CSR_WIFI_HIP_RESULT_NOT_FOUND)
{
unifi_error(card->ospriv, "No firmware found\n");
}
else if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Probe for Flash failed\n");
}
func_exit_r(r);
return r;
}
CsrResult unifi_download(card_t *card, s32 led_mask)
{
CsrResult r;
void *dlpriv;
func_enter();
if (card == NULL)
{
func_exit_r(CSR_WIFI_HIP_RESULT_INVALID_VALUE);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
card->loader_led_mask = led_mask;
unifi_trace(card->ospriv, UDBG1, "downloading firmware...\n");
dlpriv = unifi_dl_fw_read_start(card, UNIFI_FW_STA);
if (dlpriv == NULL)
{
func_exit_r(CSR_WIFI_HIP_RESULT_NOT_FOUND);
return CSR_WIFI_HIP_RESULT_NOT_FOUND;
}
r = unifi_dl_firmware(card, dlpriv);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to download firmware\n");
func_exit_r(r);
return r;
}
unifi_fw_read_stop(card->ospriv, dlpriv);
func_exit();
return CSR_RESULT_SUCCESS;
}
static CsrResult unifi_hip_init(card_t *card)
{
CsrResult r;
CsrResult csrResult;
func_enter();
r = card_hw_init(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to establish communication with UniFi\n");
func_exit_r(r);
return r;
}
#ifdef CSR_PRE_ALLOC_NET_DATA
prealloc_netdata_free(card);
#endif
r = card_init_slots(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Init slots failed: %d\n", r);
func_exit_r(r);
return r;
}
unifi_trace(card->ospriv, UDBG2, "Sending first UniFi interrupt\n");
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
csrResult = CsrSdioInterruptEnable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
r = CardGenInt(card);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
func_exit();
return CSR_RESULT_SUCCESS;
}
static void _build_sdio_config_data(sdio_config_data_t *cfg_data,
const u8 *cfg_data_buf)
{
s16 offset = 0;
cfg_data->version = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->sdio_ctrl_offset = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->fromhost_sigbuf_handle = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->tohost_sigbuf_handle = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->num_fromhost_sig_frags = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->num_tohost_sig_frags = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->num_fromhost_data_slots = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->num_tohost_data_slots = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->data_slot_size = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->initialised = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->overlay_size = CSR_GET_UINT32_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT32;
cfg_data->data_slot_round = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->sig_frag_size = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
offset += SIZEOF_UINT16;
cfg_data->tohost_signal_padding = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cfg_data_buf + offset);
}
static CsrResult card_hw_init(card_t *card)
{
u32 slut_address;
u16 initialised;
u16 finger_print;
symbol_t slut;
sdio_config_data_t *cfg_data;
u8 cfg_data_buf[SDIO_CONFIG_DATA_SIZE];
CsrResult r;
void *dlpriv;
s16 major, minor;
s16 search_4slut_again;
CsrResult csrResult;
func_enter();
do
{
search_4slut_again = 0;
cfg_data = NULL;
r = card_wait_for_firmware_to_start(card, &slut_address);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Firmware hasn't started\n");
func_exit_r(r);
return r;
}
unifi_trace(card->ospriv, UDBG4, "SLUT addr 0x%lX\n", slut_address);
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_INIT_HZ);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
func_exit_r(r);
return r;
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_INIT_HZ;
unifi_trace(card->ospriv, UDBG4, "Looking for SLUT finger print\n");
finger_print = 0;
r = unifi_card_read16(card, slut_address, &finger_print);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read SLUT finger print\n");
func_exit_r(r);
return r;
}
if (finger_print != SLUT_FINGERPRINT)
{
unifi_error(card->ospriv, "Failed to find Symbol lookup table fingerprint\n");
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
slut_address += 2;
while (!search_4slut_again)
{
u16 s;
u32 l;
r = unifi_card_read16(card, slut_address, &s);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
slut_address += 2;
if (s == CSR_SLT_END)
{
unifi_trace(card->ospriv, UDBG3, " found CSR_SLT_END\n");
break;
}
r = unifi_read32(card, slut_address, &l);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
slut_address += 4;
slut.id = s;
slut.obj = l;
unifi_trace(card->ospriv, UDBG3, " found SLUT id %02d.%08lx\n", slut.id, slut.obj);
switch (slut.id)
{
case CSR_SLT_SDIO_SLOT_CONFIG:
cfg_data = &card->config_data;
r = unifi_card_readn(card, slut.obj, cfg_data_buf, SDIO_CONFIG_DATA_SIZE);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read config data\n");
func_exit_r(r);
return r;
}
_build_sdio_config_data(cfg_data, cfg_data_buf);
if ((cfg_data->num_fromhost_data_slots < UNIFI_RESERVED_COMMAND_SLOTS)
|| (cfg_data->num_fromhost_data_slots - UNIFI_RESERVED_COMMAND_SLOTS) / UNIFI_NO_OF_TX_QS == 0)
{
unifi_error(card->ospriv, "From host data slots %d\n", cfg_data->num_fromhost_data_slots);
unifi_error(card->ospriv, "need to be (queues * x + 2) (UNIFI_RESERVED_COMMAND_SLOTS for commands)\n");
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
if (card->sdio_io_block_pad)
{
if (cfg_data->data_slot_round < card->sdio_io_block_size)
{
unifi_error(card->ospriv,
"Configuration error: Block size of %d exceeds f/w data_slot_round of %d\n",
card->sdio_io_block_size, cfg_data->data_slot_round);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if ((card->sdio_io_block_size % cfg_data->sig_frag_size) != 0)
{
unifi_error(card->ospriv, "Configuration error: Can not pad to-host signals.\n");
func_exit_r(CSR_WIFI_HIP_RESULT_INVALID_VALUE);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
cfg_data->tohost_signal_padding = (u16) (card->sdio_io_block_size / cfg_data->sig_frag_size);
unifi_info(card->ospriv, "SDIO block size %d requires %d padding chunks\n",
card->sdio_io_block_size, cfg_data->tohost_signal_padding);
r = unifi_card_write16(card, slut.obj + SDIO_TO_HOST_SIG_PADDING_OFFSET, cfg_data->tohost_signal_padding);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write To-Host Signal Padding Fragments\n");
func_exit_r(r);
return r;
}
}
card->sdio_ctrl_addr = cfg_data->sdio_ctrl_offset | (UNIFI_SH_DMEM << 24);
card->init_flag_addr = slut.obj + SDIO_INIT_FLAG_OFFSET;
break;
case CSR_SLT_BUILD_ID_NUMBER:
{
u32 n;
r = unifi_read32(card, slut.obj, &n);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read build id\n");
func_exit_r(r);
return r;
}
card->build_id = n;
}
break;
case CSR_SLT_BUILD_ID_STRING:
r = unifi_readnz(card, slut.obj, card->build_id_string,
sizeof(card->build_id_string));
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read build string\n");
func_exit_r(r);
return r;
}
break;
case CSR_SLT_PERSISTENT_STORE_DB:
break;
case CSR_SLT_BOOT_LOADER_CONTROL:
r = unifi_do_loader_op(card, slut.obj + 6, UNIFI_BOOT_LOADER_LOAD_STA);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write loader load image command\n");
func_exit_r(r);
return r;
}
dlpriv = unifi_dl_fw_read_start(card, UNIFI_FW_STA);
if (dlpriv != NULL)
{
r = unifi_dl_patch(card, dlpriv, slut.obj);
unifi_fw_read_stop(card->ospriv, dlpriv);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to patch firmware\n");
func_exit_r(r);
return r;
}
}
r = unifi_do_loader_op(card, slut.obj + 6, UNIFI_BOOT_LOADER_RESTART);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write loader restart command\n");
func_exit_r(r);
return r;
}
search_4slut_again = 1;
break;
case CSR_SLT_PANIC_DATA_PHY:
card->panic_data_phy_addr = slut.obj;
break;
case CSR_SLT_PANIC_DATA_MAC:
card->panic_data_mac_addr = slut.obj;
break;
default:
break;
}
}
} while (search_4slut_again);
if (cfg_data == NULL)
{
unifi_error(card->ospriv, "Failed to find SDIO_SLOT_CONFIG Symbol\n");
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
r = unifi_card_read16(card, card->init_flag_addr, &initialised);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read init flag at %08lx\n",
card->init_flag_addr);
func_exit_r(r);
return r;
}
if (initialised != 0)
{
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
major = (cfg_data->version >> 8) & 0xFF;
minor = cfg_data->version & 0xFF;
unifi_info(card->ospriv, "UniFi f/w protocol version %d.%d (driver %d.%d)\n",
major, minor,
UNIFI_HIP_MAJOR_VERSION, UNIFI_HIP_MINOR_VERSION);
unifi_info(card->ospriv, "Firmware build %u: %s\n",
card->build_id, card->build_id_string);
if (major != UNIFI_HIP_MAJOR_VERSION)
{
unifi_error(card->ospriv, "UniFi f/w protocol major version (%d) is different from driver (v%d.%d)\n",
major, UNIFI_HIP_MAJOR_VERSION, UNIFI_HIP_MINOR_VERSION);
#ifndef CSR_WIFI_DISABLE_HIP_VERSION_CHECK
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
#endif
}
if (minor < UNIFI_HIP_MINOR_VERSION)
{
unifi_error(card->ospriv, "UniFi f/w protocol version (v%d.%d) is older than minimum required by driver (v%d.%d).\n",
major, minor,
UNIFI_HIP_MAJOR_VERSION, UNIFI_HIP_MINOR_VERSION);
#ifndef CSR_WIFI_DISABLE_HIP_VERSION_CHECK
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
#endif
}
unifi_read_panic(card);
func_exit();
return CSR_RESULT_SUCCESS;
}
static CsrResult card_wait_for_unifi_to_reset(card_t *card)
{
s16 i;
CsrResult r;
u8 io_enable;
CsrResult csrResult;
func_enter();
r = CSR_RESULT_SUCCESS;
for (i = 0; i < MAILBOX2_ATTEMPTS; i++)
{
unifi_trace(card->ospriv, UDBG1, "waiting for reset to complete, attempt %d\n", i);
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("m0@%02X=", SDIO_IO_READY);
#endif
csrResult = CsrSdioF0Read8(card->sdio_if, SDIO_IO_READY, &io_enable);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf("error=%X\n", csrResult);
}
else
{
unifi_debug_log_to_buf("%X\n", io_enable);
}
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
r = CSR_RESULT_SUCCESS;
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
}
}
else
{
r = sdio_read_f0(card, SDIO_IO_ENABLE, &io_enable);
}
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r == CSR_RESULT_SUCCESS)
{
u16 mbox2;
s16 enabled = io_enable & (1 << card->function);
if (!enabled)
{
unifi_trace(card->ospriv, UDBG1,
"Reset complete (function %d is disabled) in ~ %u msecs\n",
card->function, i * MAILBOX2_TIMEOUT);
csrResult = CsrSdioFunctionEnable(card->sdio_if);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
unifi_error(card->ospriv, "CsrSdioFunctionEnable failed %d\n", r);
break;
}
}
r = unifi_read_direct16(card, ChipHelper_SDIO_HIP_HANDSHAKE(card->helper) * 2, &mbox2);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "read HIP_HANDSHAKE failed %d\n", r);
break;
}
if (mbox2 != 0)
{
unifi_error(card->ospriv, "MAILBOX2 non-zero after reset (mbox2 = %04x)\n", mbox2);
r = CSR_RESULT_FAILURE;
}
break;
}
else
{
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
if (i > MAILBOX2_ATTEMPTS / 4)
{
unifi_trace(card->ospriv, UDBG1, "Failed to read CCCR IO Ready register while polling for reset\n");
}
}
else
{
unifi_trace(card->ospriv, UDBG1, "Failed to read CCCR IO Enable register while polling for reset\n");
}
}
CsrThreadSleep(MAILBOX2_TIMEOUT);
}
if (r == CSR_RESULT_SUCCESS && i == MAILBOX2_ATTEMPTS)
{
unifi_trace(card->ospriv, UDBG1, "Timeout waiting for UniFi to complete reset\n");
r = CSR_RESULT_FAILURE;
}
func_exit();
return r;
}
static CsrResult card_wait_for_unifi_to_disable(card_t *card)
{
s16 i;
CsrResult r;
u8 io_enable;
CsrResult csrResult;
func_enter();
if (card->chip_id <= SDIO_CARD_ID_UNIFI_2)
{
unifi_error(card->ospriv,
"Function reset method not supported for chip_id=%d\n",
card->chip_id);
func_exit();
return CSR_RESULT_FAILURE;
}
r = CSR_RESULT_SUCCESS;
for (i = 0; i < MAILBOX2_ATTEMPTS; i++)
{
unifi_trace(card->ospriv, UDBG1, "waiting for disable to complete, attempt %d\n", i);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("r0@%02X=", SDIO_IO_READY);
#endif
csrResult = CsrSdioF0Read8(card->sdio_if, SDIO_IO_READY, &io_enable);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf("error=%X\n", csrResult);
}
else
{
unifi_debug_log_to_buf("%X\n", io_enable);
}
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (csrResult == CSR_RESULT_SUCCESS)
{
s16 enabled = io_enable & (1 << card->function);
r = CSR_RESULT_SUCCESS;
if (!enabled)
{
unifi_trace(card->ospriv, UDBG1,
"Disable complete (function %d is disabled) in ~ %u msecs\n",
card->function, i * MAILBOX2_TIMEOUT);
break;
}
}
else
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
if (i > (MAILBOX2_ATTEMPTS / 4))
{
unifi_trace(card->ospriv, UDBG1,
"Failed to read CCCR IO Ready register while polling for disable\n");
}
}
CsrThreadSleep(MAILBOX2_TIMEOUT);
}
if ((r == CSR_RESULT_SUCCESS) && (i == MAILBOX2_ATTEMPTS))
{
unifi_trace(card->ospriv, UDBG1, "Timeout waiting for UniFi to complete disable\n");
r = CSR_RESULT_FAILURE;
}
func_exit();
return r;
}
CsrResult card_wait_for_firmware_to_start(card_t *card, u32 *paddr)
{
s32 i;
u16 mbox0, mbox1;
CsrResult r;
func_enter();
CsrThreadSleep(MAILBOX1_TIMEOUT);
mbox1 = 0;
unifi_trace(card->ospriv, UDBG1, "waiting for MAILBOX1 to be non-zero...\n");
for (i = 0; i < MAILBOX1_ATTEMPTS; i++)
{
r = unifi_read_direct16(card, ChipHelper_MAILBOX1(card->helper) * 2, &mbox1);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "Failed to read UniFi Mailbox1 register\n");
}
if ((r == CSR_RESULT_SUCCESS) && (mbox1 != 0))
{
unifi_trace(card->ospriv, UDBG1, "MAILBOX1 ready (0x%04X) in %u millisecs\n",
mbox1, i * MAILBOX1_TIMEOUT);
r = unifi_read_direct16(card, ChipHelper_MAILBOX1(card->helper) * 2, &mbox1);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read UniFi Mailbox1 register for second time\n");
func_exit_r(r);
return r;
}
unifi_trace(card->ospriv, UDBG1, "MAILBOX1 value=0x%04X\n", mbox1);
break;
}
CsrThreadSleep(MAILBOX1_TIMEOUT);
if ((i % 100) == 99)
{
unifi_trace(card->ospriv, UDBG2, "MAILBOX1 not ready (0x%X), still trying...\n", mbox1);
}
}
if ((r == CSR_RESULT_SUCCESS) && (mbox1 == 0))
{
unifi_trace(card->ospriv, UDBG1, "Timeout waiting for firmware to start, Mailbox1 still 0 after %d ms\n",
MAILBOX1_ATTEMPTS * MAILBOX1_TIMEOUT);
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
r = unifi_write_direct16(card, ChipHelper_SDIO_HIP_HANDSHAKE(card->helper) * 2, 0xFFFF);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write f/w startup handshake to MAILBOX2\n");
func_exit_r(r);
return r;
}
mbox0 = 0;
r = unifi_read_direct16(card, ChipHelper_MAILBOX0(card->helper) * 2, &mbox0);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read UniFi Mailbox0 register\n");
func_exit_r(r);
return r;
}
*paddr = (((u32)mbox1 << 16) | mbox0);
func_exit();
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_capture_panic(card_t *card)
{
func_enter();
if (!card->panic_data_phy_addr || !card->panic_data_mac_addr)
{
func_exit();
return CSR_RESULT_SUCCESS;
}
if (card_access_panic(card) == CSR_RESULT_SUCCESS)
{
unifi_read_panic(card);
}
else
{
unifi_info(card->ospriv, "Unable to read panic codes");
}
func_exit();
return CSR_RESULT_SUCCESS;
}
static CsrResult card_access_panic(card_t *card)
{
u16 data_u16 = 0;
s32 i;
CsrResult r, sr;
func_enter();
if (!card->chip_version)
{
unifi_info(card->ospriv, "Unknown chip version\n");
return CSR_RESULT_FAILURE;
}
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_set_host_state() failed %d\n", r);
return CSR_RESULT_FAILURE;
}
CsrThreadSleep(20);
for (i = 0; i < 3; i++)
{
sr = CsrSdioRead16(card->sdio_if, CHIP_HELPER_UNIFI_GBL_CHIP_VERSION * 2, &data_u16);
if (sr != CSR_RESULT_SUCCESS || data_u16 != card->chip_version)
{
unifi_info(card->ospriv, "Failed to read valid chip version sr=%d (0x%04x want 0x%04x) try %d\n",
sr, data_u16, card->chip_version, i);
sr = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_SAFE_HZ);
if (sr != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "CsrSdioMaxBusClockFrequencySet() failed1 %d\n", sr);
r = ConvertCsrSdioToCsrHipResult(card, sr);
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_SAFE_HZ;
if (i == 0)
{
unifi_info(card->ospriv, "Try function enable\n");
sr = CsrSdioFunctionEnable(card->sdio_if);
if (sr != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, sr);
unifi_error(card->ospriv, "CsrSdioFunctionEnable failed %d (HIP %d)\n", sr, r);
}
continue;
}
unifi_info(card->ospriv, "Try set awake\n");
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_set_host_state() failed2 %d\n", r);
}
sr = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_SAFE_HZ);
if (sr != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "CsrSdioMaxBusClockFrequencySet() failed2 %d\n", sr);
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_SAFE_HZ;
if (i == 1)
{
continue;
}
unifi_info(card->ospriv, "Try s/w reset\n");
r = unifi_card_hard_reset(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_card_hard_reset() failed %d\n", r);
}
}
else
{
if (i > 0)
{
unifi_info(card->ospriv, "Read chip version 0x%x after %d retries\n", data_u16, i);
}
break;
}
}
r = ConvertCsrSdioToCsrHipResult(card, sr);
func_exit_r(r);
return r;
}
void unifi_read_panic(card_t *card)
{
CsrResult r;
u16 p_code, p_arg;
func_enter();
if (!card->panic_data_phy_addr || !card->panic_data_mac_addr)
{
return;
}
r = unifi_card_read16(card, card->panic_data_phy_addr, &p_code);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "capture_panic: unifi_read16 %08x failed %d\n", card->panic_data_phy_addr, r);
p_code = 0;
}
if (p_code)
{
r = unifi_card_read16(card, card->panic_data_phy_addr + 2, &p_arg);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "capture_panic: unifi_read16 %08x failed %d\n", card->panic_data_phy_addr + 2, r);
}
unifi_error(card->ospriv, "Last UniFi PHY PANIC %04x arg %04x\n", p_code, p_arg);
card->last_phy_panic_code = p_code;
card->last_phy_panic_arg = p_arg;
}
r = unifi_card_read16(card, card->panic_data_mac_addr, &p_code);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "capture_panic: unifi_read16 %08x failed %d\n", card->panic_data_mac_addr, r);
p_code = 0;
}
if (p_code)
{
r = unifi_card_read16(card, card->panic_data_mac_addr + 2, &p_arg);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "capture_panic: unifi_read16 %08x failed %d\n", card->panic_data_mac_addr + 2, r);
}
unifi_error(card->ospriv, "Last UniFi MAC PANIC %04x arg %04x\n", p_code, p_arg);
card->last_mac_panic_code = p_code;
card->last_mac_panic_arg = p_arg;
}
func_exit();
}
static CsrResult card_allocate_memory_resources(card_t *card)
{
s16 n, i, k, r;
sdio_config_data_t *cfg_data;
func_enter();
card->fh_command_queue.q_rd_ptr = 0;
card->fh_command_queue.q_wr_ptr = 0;
(void)scnprintf(card->fh_command_queue.name, UNIFI_QUEUE_NAME_MAX_LENGTH,
"fh_cmd_q");
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->fh_traffic_queue[i].q_rd_ptr = 0;
card->fh_traffic_queue[i].q_wr_ptr = 0;
(void)scnprintf(card->fh_traffic_queue[i].name,
UNIFI_QUEUE_NAME_MAX_LENGTH, "fh_data_q%d", i);
}
#ifndef CSR_WIFI_HIP_TA_DISABLE
unifi_ta_sampling_init(card);
#endif
cfg_data = &card->config_data;
card->fh_buffer.buf = kmalloc(UNIFI_FH_BUF_SIZE, GFP_KERNEL);
if (card->fh_buffer.buf == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for F-H signals\n");
func_exit_r(CSR_WIFI_HIP_RESULT_NO_MEMORY);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
card->fh_buffer.bufsize = UNIFI_FH_BUF_SIZE;
card->fh_buffer.ptr = card->fh_buffer.buf;
card->fh_buffer.count = 0;
card->th_buffer.buf = kmalloc(UNIFI_FH_BUF_SIZE, GFP_KERNEL);
if (card->th_buffer.buf == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for T-H signals\n");
func_exit_r(CSR_WIFI_HIP_RESULT_NO_MEMORY);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
card->th_buffer.bufsize = UNIFI_FH_BUF_SIZE;
card->th_buffer.ptr = card->th_buffer.buf;
card->th_buffer.count = 0;
n = cfg_data->num_fromhost_data_slots;
unifi_trace(card->ospriv, UDBG3, "Alloc from-host resources, %d slots.\n", n);
card->from_host_data = kmalloc(n * sizeof(slot_desc_t), GFP_KERNEL);
if (card->from_host_data == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for F-H bulk data array\n");
func_exit_r(CSR_WIFI_HIP_RESULT_NO_MEMORY);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
for (i = 0; i < n; i++)
{
UNIFI_INIT_BULK_DATA(&card->from_host_data[i].bd);
}
card->fh_slot_host_tag_record = kmalloc(n * sizeof(u32), GFP_KERNEL);
if (card->fh_slot_host_tag_record == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for F-H slot host tag mapping array\n");
func_exit_r(CSR_WIFI_HIP_RESULT_NO_MEMORY);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
for (i = 0; i < n; i++)
{
card->fh_slot_host_tag_record[i] = CSR_WIFI_HIP_RESERVED_HOST_TAG;
}
n = cfg_data->num_tohost_data_slots;
unifi_trace(card->ospriv, UDBG3, "Alloc to-host resources, %d slots.\n", n);
card->to_host_data = kmalloc(n * sizeof(bulk_data_desc_t), GFP_KERNEL);
if (card->to_host_data == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for T-H bulk data array\n");
func_exit_r(CSR_WIFI_HIP_RESULT_NO_MEMORY);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
for (i = 0; i < n; i++)
{
UNIFI_INIT_BULK_DATA(&card->to_host_data[i]);
}
for (i = 0; i < UNIFI_SOFT_COMMAND_Q_LENGTH; i++)
{
for (r = 0; r < UNIFI_MAX_DATA_REFERENCES; r++)
{
UNIFI_INIT_BULK_DATA(&card->fh_command_q_body[i].bulkdata[r]);
}
}
for (k = 0; k < UNIFI_NO_OF_TX_QS; k++)
{
for (i = 0; i < UNIFI_SOFT_TRAFFIC_Q_LENGTH; i++)
{
for (r = 0; r < UNIFI_MAX_DATA_REFERENCES; r++)
{
UNIFI_INIT_BULK_DATA(&card->fh_traffic_q_body[k][i].bulkdata[r]);
}
}
}
card->memory_resources_allocated = 1;
func_exit();
return CSR_RESULT_SUCCESS;
}
static void unifi_free_bulk_data(card_t *card, bulk_data_desc_t *bulk_data_slot)
{
if (bulk_data_slot->data_length != 0)
{
unifi_net_data_free(card->ospriv, bulk_data_slot);
}
}
static void card_free_memory_resources(card_t *card)
{
func_enter();
unifi_trace(card->ospriv, UDBG1, "Freeing card memory resources.\n");
unifi_cancel_pending_signals(card);
kfree(card->to_host_data);
card->to_host_data = NULL;
kfree(card->from_host_data);
card->from_host_data = NULL;
kfree(card->fh_slot_host_tag_record);
card->fh_slot_host_tag_record = NULL;
kfree(card->fh_buffer.buf);
card->fh_buffer.ptr = card->fh_buffer.buf = NULL;
card->fh_buffer.bufsize = 0;
card->fh_buffer.count = 0;
kfree(card->th_buffer.buf);
card->th_buffer.ptr = card->th_buffer.buf = NULL;
card->th_buffer.bufsize = 0;
card->th_buffer.count = 0;
card->memory_resources_allocated = 0;
func_exit();
}
static void card_init_soft_queues(card_t *card)
{
s16 i;
func_enter();
unifi_trace(card->ospriv, UDBG1, "Initialising internal signal queues.\n");
card->fh_command_queue.q_rd_ptr = 0;
card->fh_command_queue.q_wr_ptr = 0;
(void)scnprintf(card->fh_command_queue.name, UNIFI_QUEUE_NAME_MAX_LENGTH,
"fh_cmd_q");
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->fh_traffic_queue[i].q_rd_ptr = 0;
card->fh_traffic_queue[i].q_wr_ptr = 0;
(void)scnprintf(card->fh_traffic_queue[i].name,
UNIFI_QUEUE_NAME_MAX_LENGTH, "fh_data_q%d", i);
}
#ifndef CSR_WIFI_HIP_TA_DISABLE
unifi_ta_sampling_init(card);
#endif
func_exit();
}
void unifi_cancel_pending_signals(card_t *card)
{
s16 i, n, r;
func_enter();
unifi_trace(card->ospriv, UDBG1, "Canceling pending signals.\n");
if (card->to_host_data)
{
n = card->config_data.num_tohost_data_slots;
unifi_trace(card->ospriv, UDBG3, "Freeing to-host resources, %d slots.\n", n);
for (i = 0; i < n; i++)
{
unifi_free_bulk_data(card, &card->to_host_data[i]);
}
}
if (card->from_host_data)
{
n = card->config_data.num_fromhost_data_slots;
unifi_trace(card->ospriv, UDBG3, "Freeing from-host resources, %d slots.\n", n);
for (i = 0; i < n; i++)
{
unifi_free_bulk_data(card, &card->from_host_data[i].bd);
}
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->dynamic_slot_data.from_host_used_slots[i] = 0;
card->dynamic_slot_data.from_host_max_slots[i] = 0;
card->dynamic_slot_data.from_host_reserved_slots[i] = 0;
}
}
unifi_trace(card->ospriv, UDBG3, "Freeing cmd q resources.\n");
for (i = 0; i < UNIFI_SOFT_COMMAND_Q_LENGTH; i++)
{
for (r = 0; r < UNIFI_MAX_DATA_REFERENCES; r++)
{
unifi_free_bulk_data(card, &card->fh_command_q_body[i].bulkdata[r]);
}
}
unifi_trace(card->ospriv, UDBG3, "Freeing traffic q resources.\n");
for (n = 0; n < UNIFI_NO_OF_TX_QS; n++)
{
for (i = 0; i < UNIFI_SOFT_TRAFFIC_Q_LENGTH; i++)
{
for (r = 0; r < UNIFI_MAX_DATA_REFERENCES; r++)
{
unifi_free_bulk_data(card, &card->fh_traffic_q_body[n][i].bulkdata[r]);
}
}
}
card_init_soft_queues(card);
func_exit();
}
void unifi_free_card(card_t *card)
{
func_enter();
#ifdef CSR_PRE_ALLOC_NET_DATA
prealloc_netdata_free(card);
#endif
card_free_memory_resources(card);
if (card->dump_buf)
{
unifi_error(card->ospriv, "Caller should call unifi_coredump_free()\n");
unifi_coredump_free(card);
}
kfree(card);
func_exit();
}
static CsrResult card_init_slots(card_t *card)
{
CsrResult r;
u8 i;
func_enter();
if (card->memory_resources_allocated == 1)
{
card_free_memory_resources(card);
}
else
{
card_init_soft_queues(card);
}
r = card_allocate_memory_resources(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to allocate card memory resources.\n");
card_free_memory_resources(card);
func_exit_r(r);
return r;
}
if (card->sdio_ctrl_addr == 0)
{
unifi_error(card->ospriv, "Failed to find config struct!\n");
func_exit_r(CSR_WIFI_HIP_RESULT_INVALID_VALUE);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
card->from_host_data_head = 0;
{
u16 s;
r = unifi_card_read16(card, card->sdio_ctrl_addr + 0, &s);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read from-host sig written count\n");
func_exit_r(r);
return r;
}
card->from_host_signals_w = (s16)s;
r = unifi_card_read16(card, card->sdio_ctrl_addr + 6, &s);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read to-host sig read count\n");
func_exit_r(r);
return r;
}
card->to_host_signals_r = (s16)s;
}
r = unifi_card_write16(card, card->init_flag_addr, 0x0001);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write initialised flag\n");
func_exit_r(r);
return r;
}
memset(&card->dynamic_slot_data, 0, sizeof(card_dynamic_slot_t));
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->dynamic_slot_data.from_host_max_slots[i] = card->config_data.num_fromhost_data_slots -
UNIFI_RESERVED_COMMAND_SLOTS;
card->dynamic_slot_data.queue_stable[i] = FALSE;
}
card->dynamic_slot_data.packets_interval = UNIFI_PACKETS_INTERVAL;
func_exit();
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_set_udi_hook(card_t *card, udi_func_t udi_fn)
{
if (card == NULL)
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (card->udi_hook == NULL)
{
card->udi_hook = udi_fn;
}
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_remove_udi_hook(card_t *card, udi_func_t udi_fn)
{
if (card == NULL)
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (card->udi_hook == udi_fn)
{
card->udi_hook = NULL;
}
return CSR_RESULT_SUCCESS;
}
static void CardReassignDynamicReservation(card_t *card)
{
u8 i;
func_enter();
unifi_trace(card->ospriv, UDBG5, "Packets Txed %d %d %d %d\n",
card->dynamic_slot_data.packets_txed[0],
card->dynamic_slot_data.packets_txed[1],
card->dynamic_slot_data.packets_txed[2],
card->dynamic_slot_data.packets_txed[3]);
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
card->dynamic_slot_data.queue_stable[i] = FALSE;
card->dynamic_slot_data.from_host_reserved_slots[i] = 0;
card->dynamic_slot_data.from_host_max_slots[i] = card->config_data.num_fromhost_data_slots -
UNIFI_RESERVED_COMMAND_SLOTS;
card->dynamic_slot_data.packets_txed[i] = 0;
unifi_trace(card->ospriv, UDBG5, "CardReassignDynamicReservation: queue %d reserved %d Max %d\n", i,
card->dynamic_slot_data.from_host_reserved_slots[i],
card->dynamic_slot_data.from_host_max_slots[i]);
}
card->dynamic_slot_data.total_packets_txed = 0;
func_exit();
}
static void CardCheckDynamicReservation(card_t *card, unifi_TrafficQueue queue)
{
u16 q_len, active_queues = 0, excess_queue_slots, div_extra_slots,
queue_fair_share, reserved_slots = 0, q, excess_need_queues = 0, unmovable_slots = 0;
s32 i;
q_t *sigq;
u16 num_data_slots = card->config_data.num_fromhost_data_slots - UNIFI_RESERVED_COMMAND_SLOTS;
func_enter();
sigq = &card->fh_traffic_queue[queue];
q_len = CSR_WIFI_HIP_Q_SLOTS_USED(sigq);
if (q_len <= card->dynamic_slot_data.from_host_reserved_slots[queue])
{
unifi_trace(card->ospriv, UDBG5, "queue %d q_len %d already has that many reserved slots, exiting\n", queue, q_len);
func_exit();
return;
}
if (q_len > num_data_slots)
{
q_len = num_data_slots;
}
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
if (i != (s32)queue)
{
reserved_slots += card->dynamic_slot_data.from_host_reserved_slots[i];
}
if ((i == (s32)queue) || (card->dynamic_slot_data.from_host_reserved_slots[i] > 0))
{
active_queues++;
}
}
unifi_trace(card->ospriv, UDBG5, "CardCheckDynamicReservation: queue %d q_len %d\n", queue, q_len);
unifi_trace(card->ospriv, UDBG5, "Active queues %d reserved slots on other queues %d\n",
active_queues, reserved_slots);
if (reserved_slots + q_len <= num_data_slots)
{
card->dynamic_slot_data.from_host_reserved_slots[queue] = q_len;
if (q_len == num_data_slots)
{
card->dynamic_slot_data.queue_stable[queue] = TRUE;
}
}
else
{
queue_fair_share = num_data_slots / active_queues;
unifi_trace(card->ospriv, UDBG5, "queue fair share %d\n", queue_fair_share);
card->dynamic_slot_data.from_host_reserved_slots[queue] = q_len;
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
if (card->dynamic_slot_data.from_host_reserved_slots[i] > queue_fair_share)
{
excess_need_queues++;
}
else
{
unmovable_slots += card->dynamic_slot_data.from_host_reserved_slots[i];
}
}
unifi_trace(card->ospriv, UDBG5, "Excess need queues %d\n", excess_need_queues);
excess_queue_slots = (num_data_slots - unmovable_slots) / excess_need_queues;
div_extra_slots = (num_data_slots - unmovable_slots) - excess_queue_slots * excess_need_queues;
for (i = UNIFI_NO_OF_TX_QS - 1; i >= 0; i--)
{
if (card->dynamic_slot_data.from_host_reserved_slots[i] > excess_queue_slots)
{
card->dynamic_slot_data.from_host_reserved_slots[i] = excess_queue_slots;
if (div_extra_slots > 0)
{
card->dynamic_slot_data.from_host_reserved_slots[i]++;
div_extra_slots--;
}
card->dynamic_slot_data.queue_stable[i] = TRUE;
unifi_trace(card->ospriv, UDBG5, "queue stable %d\n", i);
}
}
}
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
reserved_slots = 0;
for (q = 0; q < UNIFI_NO_OF_TX_QS; q++)
{
if (i != q)
{
reserved_slots += card->dynamic_slot_data.from_host_reserved_slots[q];
}
}
card->dynamic_slot_data.from_host_max_slots[i] = num_data_slots - reserved_slots;
unifi_trace(card->ospriv, UDBG5, "queue %d reserved %d Max %d\n", i,
card->dynamic_slot_data.from_host_reserved_slots[i],
card->dynamic_slot_data.from_host_max_slots[i]);
}
func_exit();
}
void CardClearFromHostDataSlot(card_t *card, const s16 slot)
{
u8 queue = card->from_host_data[slot].queue;
const void *os_data_ptr = card->from_host_data[slot].bd.os_data_ptr;
func_enter();
if (card->from_host_data[slot].bd.data_length == 0)
{
unifi_warning(card->ospriv,
"Surprise: request to clear an already free FH data slot: %d\n",
slot);
func_exit();
return;
}
if (os_data_ptr == NULL)
{
unifi_warning(card->ospriv,
"Clearing FH data slot %d: has null payload, len=%d\n",
slot, card->from_host_data[slot].bd.data_length);
}
unifi_free_bulk_data(card, &card->from_host_data[slot].bd);
if (queue < UNIFI_NO_OF_TX_QS)
{
if (card->dynamic_slot_data.from_host_used_slots[queue] == 0)
{
unifi_error(card->ospriv, "Goofed up used slots q = %d used slots = %d\n",
queue,
card->dynamic_slot_data.from_host_used_slots[queue]);
}
else
{
card->dynamic_slot_data.from_host_used_slots[queue]--;
}
card->dynamic_slot_data.packets_txed[queue]++;
card->dynamic_slot_data.total_packets_txed++;
if (card->dynamic_slot_data.total_packets_txed >= card->dynamic_slot_data.packets_interval)
{
CardReassignDynamicReservation(card);
}
}
unifi_trace(card->ospriv, UDBG4, "CardClearFromHostDataSlot: slot %d recycled %p\n", slot, os_data_ptr);
func_exit();
}
void CardClearFromHostDataSlotWithoutFreeingBulkData(card_t *card, const s16 slot)
{
u8 queue = card->from_host_data[slot].queue;
UNIFI_INIT_BULK_DATA(&card->from_host_data[slot].bd);
queue = card->from_host_data[slot].queue;
if (queue < UNIFI_NO_OF_TX_QS)
{
if (card->dynamic_slot_data.from_host_used_slots[queue] == 0)
{
unifi_error(card->ospriv, "Goofed up used slots q = %d used slots = %d\n",
queue,
card->dynamic_slot_data.from_host_used_slots[queue]);
}
else
{
card->dynamic_slot_data.from_host_used_slots[queue]--;
}
card->dynamic_slot_data.packets_txed[queue]++;
card->dynamic_slot_data.total_packets_txed++;
if (card->dynamic_slot_data.total_packets_txed >=
card->dynamic_slot_data.packets_interval)
{
CardReassignDynamicReservation(card);
}
}
}
u16 CardGetDataSlotSize(card_t *card)
{
return card->config_data.data_slot_size;
}
u16 CardGetFreeFromHostDataSlots(card_t *card)
{
u16 i, n = 0;
func_enter();
for (i = 0; i < card->config_data.num_fromhost_data_slots; i++)
{
if (card->from_host_data[i].bd.data_length == 0)
{
n++;
}
}
func_exit();
return n;
}
u16 CardAreAllFromHostDataSlotsEmpty(card_t *card)
{
u16 i;
for (i = 0; i < card->config_data.num_fromhost_data_slots; i++)
{
if (card->from_host_data[i].bd.data_length != 0)
{
return 0;
}
}
return 1;
}
static CsrResult unifi_identify_hw(card_t *card)
{
func_enter();
card->chip_id = card->sdio_if->sdioId.cardId;
card->function = card->sdio_if->sdioId.sdioFunction;
card->sdio_io_block_size = card->sdio_if->blockSize;
card->sdio_io_block_pad = (card->sdio_if->features & CSR_SDIO_FEATURE_BYTE_MODE)?FALSE : TRUE;
card->helper = ChipHelper_GetVersionSdio((u8)card->chip_id);
if (!card->helper)
{
unifi_error(card->ospriv, "Null ChipHelper\n");
}
unifi_info(card->ospriv, "Chip ID 0x%02X Function %u Block Size %u Name %s(%s)\n",
card->chip_id, card->function, card->sdio_io_block_size,
ChipHelper_MarketingName(card->helper),
ChipHelper_FriendlyName(card->helper));
func_exit();
return CSR_RESULT_SUCCESS;
}
static CsrResult unifi_prepare_hw(card_t *card)
{
CsrResult r;
CsrResult csrResult;
enum unifi_host_state old_state = card->host_state;
func_enter();
r = unifi_identify_hw(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to identify hw\n");
func_exit_r(r);
return r;
}
unifi_trace(card->ospriv, UDBG1,
"%s mode SDIO\n", card->sdio_io_block_pad?"Block" : "Byte");
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (old_state == UNIFI_HOST_STATE_TORPID)
{
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_INIT_HZ);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
func_exit_r(r);
return r;
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_INIT_HZ;
}
csrResult = CsrSdioFunctionEnable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
unifi_error(card->ospriv, "Failed to re-enable function %d.\n", card->function);
func_exit_r(r);
return r;
}
bootstrap_chip_hw(card);
r = unifi_read_chip_version(card);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
func_exit();
return CSR_RESULT_SUCCESS;
}
static CsrResult unifi_read_chip_version(card_t *card)
{
u32 gbl_chip_version;
CsrResult r;
u16 ver;
func_enter();
gbl_chip_version = ChipHelper_GBL_CHIP_VERSION(card->helper);
if (gbl_chip_version != 0)
{
r = unifi_read_direct16(card, gbl_chip_version * 2, &ver);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read GBL_CHIP_VERSION\n");
func_exit_r(r);
return r;
}
card->chip_version = ver;
}
else
{
unifi_info(card->ospriv, "Unknown Chip ID, cannot locate GBL_CHIP_VERSION\n");
r = CSR_RESULT_FAILURE;
}
unifi_info(card->ospriv, "Chip Version 0x%04X\n", card->chip_version);
func_exit_r(r);
return r;
}
static CsrResult unifi_reset_hardware(card_t *card)
{
CsrResult r;
u16 new_block_size = UNIFI_IO_BLOCK_SIZE;
CsrResult csrResult;
func_enter();
r = unifi_prepare_hw(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
unifi_info(card->ospriv, "Calling CsrSdioHardReset\n");
csrResult = CsrSdioHardReset(card->sdio_if);
if (csrResult == CSR_RESULT_SUCCESS)
{
unifi_info(card->ospriv, "CsrSdioHardReset succeeded on reseting UniFi\n");
r = unifi_prepare_hw(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_prepare_hw failed after hard reset\n");
func_exit_r(r);
return r;
}
}
else if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
else
{
unifi_info(card->ospriv, "Falling back to software hard reset\n");
r = unifi_card_hard_reset(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "software hard reset failed\n");
func_exit_r(r);
return r;
}
if (card->chip_version == 0)
{
r = unifi_read_chip_version(card);
if (r != CSR_RESULT_SUCCESS)
{
func_exit_r(r);
return r;
}
}
}
#ifdef CSR_WIFI_HIP_SDIO_BLOCK_SIZE
new_block_size = CSR_WIFI_HIP_SDIO_BLOCK_SIZE;
#endif
csrResult = CsrSdioBlockSizeSet(card->sdio_if, new_block_size);
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
if (card->sdio_if->blockSize != new_block_size)
{
unifi_info(card->ospriv,
"Actually got block size %d\n", card->sdio_if->blockSize);
}
if (card->sdio_if->blockSize == 0)
{
unifi_info(card->ospriv, "Block size 0, block mode not available\n");
card->sdio_io_block_size = 1;
if (!(card->sdio_if->features & CSR_SDIO_FEATURE_BYTE_MODE))
{
unifi_error(card->ospriv, "Requires byte mode\n");
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
}
else
{
card->sdio_io_block_size = card->sdio_if->blockSize;
}
func_exit_r(r);
return r;
}
static CsrResult card_reset_method_io_enable(card_t *card)
{
CsrResult r;
CsrResult csrResult;
func_enter();
unifi_trace(card->ospriv, UDBG1, "Hard reset (IO_ENABLE)\n");
csrResult = CsrSdioFunctionDisable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
unifi_warning(card->ospriv, "SDIO error writing IO_ENABLE: %d\n", r);
}
else
{
CsrThreadSleep(RESET_SETTLE_DELAY);
r = card_wait_for_unifi_to_disable(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r == CSR_RESULT_SUCCESS)
{
r = card_wait_for_unifi_to_reset(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
}
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_trace(card->ospriv, UDBG1, "Hard reset (CSR_FUNC_EN)\n");
r = sdio_write_f0(card, SDIO_CSR_FUNC_EN, 0);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "SDIO error writing SDIO_CSR_FUNC_EN: %d\n", r);
func_exit_r(r);
return r;
}
else
{
CsrThreadSleep(RESET_SETTLE_DELAY);
r = card_wait_for_unifi_to_reset(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
}
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "card_reset_method_io_enable failed to reset UniFi\n");
}
func_exit();
return r;
}
static CsrResult card_reset_method_dbg_reset(card_t *card)
{
CsrResult r;
func_enter();
if (card->host_state == UNIFI_HOST_STATE_TORPID)
{
r = unifi_set_host_state(card, UNIFI_HOST_STATE_DROWSY);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to set UNIFI_HOST_STATE_DROWSY\n");
func_exit_r(r);
return r;
}
CsrThreadSleep(5);
}
r = unifi_card_stop_processor(card, UNIFI_PROC_BOTH);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Can't stop processors\n");
func_exit();
return r;
}
unifi_trace(card->ospriv, UDBG1, "Hard reset (DBG_RESET)\n");
r = unifi_write_direct_8_or_16(card, ChipHelper_DBG_RESET(card->helper) * 2, 1);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "SDIO error writing DBG_RESET: %d\n", r);
func_exit_r(r);
return r;
}
CsrThreadSleep(RESET_SETTLE_DELAY);
r = card_wait_for_unifi_to_reset(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "card_reset_method_dbg_reset failed to reset UniFi\n");
}
func_exit();
return r;
}
CsrResult unifi_card_hard_reset(card_t *card)
{
CsrResult r;
const struct chip_helper_reset_values *init_data;
u32 chunks;
func_enter();
card->proc_select = (u32)(-1);
card->dmem_page = (u32)(-1);
card->pmem_page = (u32)(-1);
r = unifi_identify_hw(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_card_hard_reset failed to identify h/w\n");
func_exit();
return r;
}
chunks = ChipHelper_HostResetSequence(card->helper, &init_data);
if (chunks != 0)
{
unifi_error(card->ospriv,
"Hard reset (Code download) is unsupported\n");
func_exit_r(CSR_RESULT_FAILURE);
return CSR_RESULT_FAILURE;
}
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
r = card_reset_method_io_enable(card);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r == CSR_RESULT_SUCCESS)
{
func_exit();
return r;
}
}
r = card_reset_method_dbg_reset(card);
func_exit_r(r);
return r;
}
CsrResult CardGenInt(card_t *card)
{
CsrResult r;
func_enter();
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
r = sdio_write_f0(card, SDIO_CSR_FROM_HOST_SCRATCH0,
(u8)card->unifi_interrupt_seq);
}
else
{
r = unifi_write_direct_8_or_16(card,
ChipHelper_SHARED_IO_INTERRUPT(card->helper) * 2,
(u8)card->unifi_interrupt_seq);
}
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error writing UNIFI_SHARED_IO_INTERRUPT: %d\n", r);
func_exit_r(r);
return r;
}
card->unifi_interrupt_seq++;
func_exit();
return CSR_RESULT_SUCCESS;
}
CsrResult CardEnableInt(card_t *card)
{
CsrResult r;
u8 int_enable;
r = sdio_read_f0(card, SDIO_INT_ENABLE, &int_enable);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error reading SDIO_INT_ENABLE\n");
return r;
}
int_enable |= (1 << card->function) | UNIFI_SD_INT_ENABLE_IENM;
r = sdio_write_f0(card, SDIO_INT_ENABLE, int_enable);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error writing SDIO_INT_ENABLE\n");
return r;
}
return CSR_RESULT_SUCCESS;
}
CsrResult CardDisableInt(card_t *card)
{
CsrResult r;
u8 int_enable;
r = sdio_read_f0(card, SDIO_INT_ENABLE, &int_enable);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error reading SDIO_INT_ENABLE\n");
return r;
}
int_enable &= ~(1 << card->function);
r = sdio_write_f0(card, SDIO_INT_ENABLE, int_enable);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error writing SDIO_INT_ENABLE\n");
return r;
}
return CSR_RESULT_SUCCESS;
}
CsrResult CardPendingInt(card_t *card, u8 *pintr)
{
CsrResult r;
u8 pending;
*pintr = FALSE;
r = sdio_read_f0(card, SDIO_INT_PENDING, &pending);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error reading SDIO_INT_PENDING\n");
return r;
}
*pintr = (pending & (1 << card->function))?TRUE : FALSE;
return CSR_RESULT_SUCCESS;
}
CsrResult CardClearInt(card_t *card)
{
CsrResult r;
u8 intr;
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
r = CardPendingInt(card, &intr);
if (intr == FALSE)
{
return r;
}
r = sdio_write_f0(card, SDIO_CSR_HOST_INT_CLEAR, 1);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error writing SDIO_CSR_HOST_INT_CLEAR\n");
}
}
else
{
r = unifi_write_direct_8_or_16(card,
ChipHelper_SDIO_HOST_INT(card->helper) * 2,
0);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error writing UNIFI_SDIO_HOST_INT\n");
}
}
return r;
}
CsrResult CardIntEnabled(card_t *card, u8 *enabled)
{
CsrResult r;
u8 int_enable;
r = sdio_read_f0(card, SDIO_INT_ENABLE, &int_enable);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "SDIO error reading SDIO_INT_ENABLE\n");
return r;
}
*enabled = (int_enable & (1 << card->function))?TRUE : FALSE;
return CSR_RESULT_SUCCESS;
}
CsrResult CardWriteBulkData(card_t *card, card_signal_t *csptr, unifi_TrafficQueue queue)
{
u16 i, slots[UNIFI_MAX_DATA_REFERENCES], j = 0;
u8 *packed_sigptr, num_slots_required = 0;
bulk_data_desc_t *bulkdata = csptr->bulkdata;
s16 h, nslots;
func_enter();
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
if (bulkdata[i].data_length != 0)
{
num_slots_required++;
}
}
if (num_slots_required != 0)
{
if (queue == UNIFI_TRAFFIC_Q_MLME)
{
h = card->config_data.num_fromhost_data_slots - UNIFI_RESERVED_COMMAND_SLOTS;
for (i = 0; i < card->config_data.num_fromhost_data_slots; i++)
{
if (card->from_host_data[h].bd.data_length == 0)
{
slots[j++] = h;
if (j == num_slots_required)
{
break;
}
}
if (++h >= card->config_data.num_fromhost_data_slots)
{
h = 0;
}
}
}
else
{
if (card->dynamic_slot_data.from_host_used_slots[queue]
< card->dynamic_slot_data.from_host_max_slots[queue])
{
nslots = card->config_data.num_fromhost_data_slots - UNIFI_RESERVED_COMMAND_SLOTS;
h = card->from_host_data_head;
for (i = 0; i < nslots; i++)
{
if (card->from_host_data[h].bd.data_length == 0)
{
slots[j++] = h;
if (j == num_slots_required)
{
break;
}
}
if (++h >= nslots)
{
h = 0;
}
}
card->from_host_data_head = h;
}
}
if (j != num_slots_required)
{
unifi_trace(card->ospriv, UDBG5, "CardWriteBulkData: didn't find free slot/s\n");
if ((queue != UNIFI_TRAFFIC_Q_MLME) && (card->dynamic_slot_data.queue_stable[queue] == FALSE))
{
CardCheckDynamicReservation(card, queue);
}
for (i = 0; i < card->config_data.num_fromhost_data_slots; i++)
{
unifi_trace(card->ospriv, UDBG5, "fh data slot %d: %d\n", i, card->from_host_data[i].bd.data_length);
}
func_exit();
return CSR_RESULT_FAILURE;
}
}
packed_sigptr = csptr->sigbuf;
j = 0;
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
if (bulkdata[i].data_length == 0)
{
SET_PACKED_DATAREF_SLOT(packed_sigptr, i, 0);
SET_PACKED_DATAREF_LEN(packed_sigptr, i, 0);
}
else
{
SET_PACKED_DATAREF_SLOT(packed_sigptr, i, slots[j] | (((u16)packed_sigptr[SIZEOF_SIGNAL_HEADER + (i * SIZEOF_DATAREF) + 1]) << 8));
SET_PACKED_DATAREF_LEN(packed_sigptr, i, bulkdata[i].data_length);
card->from_host_data[slots[j]].bd.os_data_ptr = bulkdata[i].os_data_ptr;
card->from_host_data[slots[j]].bd.os_net_buf_ptr = bulkdata[i].os_net_buf_ptr;
card->from_host_data[slots[j]].bd.data_length = bulkdata[i].data_length;
card->from_host_data[slots[j]].bd.net_buf_length = bulkdata[i].net_buf_length;
card->from_host_data[slots[j]].queue = queue;
unifi_trace(card->ospriv, UDBG4, "CardWriteBulkData sig=0x%x, fh slot %d = %p\n",
GET_SIGNAL_ID(packed_sigptr), i, bulkdata[i].os_data_ptr);
if (!bulkdata[i].os_data_ptr)
{
unifi_error(card->ospriv, "Assign null os_data_ptr (len=%d) fh slot %d, i=%d, q=%d, sig=0x%x",
bulkdata[i].data_length, slots[j], i, queue, GET_SIGNAL_ID(packed_sigptr));
}
j++;
if (queue < UNIFI_NO_OF_TX_QS)
{
card->dynamic_slot_data.from_host_used_slots[queue]++;
}
}
}
func_exit();
return CSR_RESULT_SUCCESS;
}
bulk_data_desc_t* card_find_data_slot(card_t *card, s16 slot)
{
s16 sn;
bulk_data_desc_t *bd;
sn = slot & 0x7FFF;
if (slot & SLOT_DIR_TO_HOST)
{
bd = &card->to_host_data[sn];
}
else
{
bd = &card->from_host_data[sn].bd;
}
return bd;
}
static CsrResult firmware_present_in_flash(card_t *card)
{
CsrResult r;
u16 m1, m5;
if (ChipHelper_HasRom(card->helper))
{
return CSR_RESULT_SUCCESS;
}
if (!ChipHelper_HasFlash(card->helper))
{
return CSR_WIFI_HIP_RESULT_NOT_FOUND;
}
r = unifi_card_read16(card, UNIFI_MAKE_GP(EXT_FLASH, 2), &m1);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = unifi_card_read16(card, UNIFI_MAKE_GP(EXT_FLASH, 10), &m5);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
if ((m1 == 0x0008) || (m1 == 0xFFFF) ||
(m1 == 0x0004) || (m5 == 0x0004) ||
(m5 == 0x0008) || (m5 == 0xFFFF))
{
return CSR_WIFI_HIP_RESULT_NOT_FOUND;
}
return CSR_RESULT_SUCCESS;
}
static void bootstrap_chip_hw(card_t *card)
{
const struct chip_helper_init_values *vals;
u32 i, len;
void *sdio = card->sdio_if;
CsrResult csrResult;
len = ChipHelper_ClockStartupSequence(card->helper, &vals);
if (len != 0)
{
for (i = 0; i < len; i++)
{
csrResult = CsrSdioWrite16(sdio, vals[i].addr * 2, vals[i].value);
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_warning(card->ospriv, "Failed to write bootstrap value %d\n", i);
}
CsrThreadSleep(1);
}
}
}
CsrResult unifi_card_stop_processor(card_t *card, enum unifi_dbg_processors_select which)
{
CsrResult r = CSR_RESULT_SUCCESS;
u8 status;
s16 retry = 100;
while (retry--)
{
r = unifi_set_proc_select(card, which);
if (r != CSR_RESULT_SUCCESS)
{
break;
}
r = unifi_write_direct16(card, ChipHelper_DBG_EMU_CMD(card->helper) * 2, 2);
if (r != CSR_RESULT_SUCCESS)
{
break;
}
r = unifi_read_direct_8_or_16(card,
ChipHelper_DBG_HOST_STOP_STATUS(card->helper) * 2,
&status);
if (r != CSR_RESULT_SUCCESS)
{
break;
}
if ((status & 1) == 1)
{
return CSR_RESULT_SUCCESS;
}
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to stop processors: SDIO error\n");
}
else
{
unifi_error(card->ospriv, "Failed to stop processors: timeout waiting for stopped status\n");
r = CSR_RESULT_FAILURE;
}
return r;
}
CsrResult card_start_processor(card_t *card, enum unifi_dbg_processors_select which)
{
CsrResult r;
r = unifi_set_proc_select(card, which);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "unifi_set_proc_select failed: %d.\n", r);
return r;
}
r = unifi_write_direct_8_or_16(card,
ChipHelper_DBG_EMU_CMD(card->helper) * 2, 8);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = unifi_write_direct_8_or_16(card,
ChipHelper_DBG_EMU_CMD(card->helper) * 2, 0);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
return CSR_RESULT_SUCCESS;
}
void unifi_set_interrupt_mode(card_t *card, u32 mode)
{
if (mode == CSR_WIFI_INTMODE_RUN_BH_ONCE)
{
unifi_info(card->ospriv, "Scheduled interrupt mode");
}
card->intmode = mode;
}
CsrResult unifi_start_processors(card_t *card)
{
return card_start_processor(card, UNIFI_PROC_BOTH);
}
void unifi_request_max_sdio_clock(card_t *card)
{
card->request_max_clock = 1;
}
CsrResult unifi_set_host_state(card_t *card, enum unifi_host_state state)
{
CsrResult r = CSR_RESULT_SUCCESS;
CsrResult csrResult;
static const char *const states[] = {
"AWAKE", "DROWSY", "TORPID"
};
static const u8 state_csr_host_wakeup[] = {
1, 3, 0
};
static const u8 state_io_abort[] = {
0, 2, 3
};
unifi_trace(card->ospriv, UDBG4, "State %s to %s\n",
states[card->host_state], states[state]);
if (card->host_state == UNIFI_HOST_STATE_TORPID)
{
CsrSdioFunctionActive(card->sdio_if);
}
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
r = sdio_write_f0(card, SDIO_CSR_HOST_WAKEUP,
(u8)((card->function << 4) | state_csr_host_wakeup[state]));
}
else
{
r = sdio_write_f0(card, SDIO_IO_ABORT, state_io_abort[state]);
}
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write UniFi deep sleep state\n");
}
else
{
if (card->host_state == UNIFI_HOST_STATE_TORPID)
{
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if,
UNIFI_SDIO_CLOCK_MAX_HZ);
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
if (r != CSR_RESULT_SUCCESS && r != CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
unifi_warning(card->ospriv,
"Failed to increase the SDIO clock speed\n");
}
else
{
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_MAX_HZ;
}
}
card->host_state = state;
if (state == UNIFI_HOST_STATE_TORPID)
{
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if,
UNIFI_SDIO_CLOCK_SAFE_HZ);
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
if (r != CSR_RESULT_SUCCESS && r != CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
unifi_warning(card->ospriv,
"Failed to decrease the SDIO clock speed\n");
}
else
{
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_SAFE_HZ;
}
CsrSdioFunctionIdle(card->sdio_if);
}
}
return r;
}
void unifi_card_info(card_t *card, card_info_t *card_info)
{
card_info->chip_id = card->chip_id;
card_info->chip_version = card->chip_version;
card_info->fw_build = card->build_id;
card_info->fw_hip_version = card->config_data.version;
card_info->sdio_block_size = card->sdio_io_block_size;
}
CsrResult unifi_check_io_status(card_t *card, s32 *status)
{
u8 io_en;
CsrResult r;
u8 pending;
*status = 0;
r = sdio_read_f0(card, SDIO_IO_ENABLE, &io_en);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read SDIO_IO_ENABLE to check for spontaneous reset\n");
return r;
}
if ((io_en & (1 << card->function)) == 0)
{
s32 fw_count;
*status = 1;
unifi_error(card->ospriv, "UniFi has spontaneously reset.\n");
fw_count = unifi_read_shared_count(card, card->sdio_ctrl_addr + 4);
if (fw_count < 0)
{
unifi_error(card->ospriv, "Failed to read to-host sig written count\n");
}
else
{
unifi_error(card->ospriv, "thsw: %u (driver thinks is %u)\n",
fw_count, card->to_host_signals_w);
}
fw_count = unifi_read_shared_count(card, card->sdio_ctrl_addr + 2);
if (fw_count < 0)
{
unifi_error(card->ospriv, "Failed to read from-host sig read count\n");
}
else
{
unifi_error(card->ospriv, "fhsr: %u (driver thinks is %u)\n",
fw_count, card->from_host_signals_r);
}
return r;
}
unifi_info(card->ospriv, "UniFi function %d is enabled.\n", card->function);
r = CardPendingInt(card, &pending);
if (pending)
{
unifi_error(card->ospriv, "There is an unhandled pending interrupt.\n");
*status = 2;
return r;
}
return r;
}
void unifi_get_hip_qos_info(card_t *card, unifi_HipQosInfo *hipqosinfo)
{
s32 count_fhr;
s16 t;
u32 occupied_fh;
q_t *sigq;
u16 nslots, i;
memset(hipqosinfo, 0, sizeof(unifi_HipQosInfo));
nslots = card->config_data.num_fromhost_data_slots;
for (i = 0; i < nslots; i++)
{
if (card->from_host_data[i].bd.data_length == 0)
{
hipqosinfo->free_fh_bulkdata_slots++;
}
}
for (i = 0; i < UNIFI_NO_OF_TX_QS; i++)
{
sigq = &card->fh_traffic_queue[i];
t = sigq->q_wr_ptr - sigq->q_rd_ptr;
if (t < 0)
{
t += sigq->q_length;
}
hipqosinfo->free_fh_sig_queue_slots[i] = (sigq->q_length - t) - 1;
}
count_fhr = unifi_read_shared_count(card, card->sdio_ctrl_addr + 2);
if (count_fhr < 0)
{
unifi_error(card->ospriv, "Failed to read from-host sig read count - %d\n", count_fhr);
hipqosinfo->free_fh_fw_slots = 0xfa;
return;
}
occupied_fh = (card->from_host_signals_w - count_fhr) % 128;
hipqosinfo->free_fh_fw_slots = (u16)(card->config_data.num_fromhost_sig_frags - occupied_fh);
}
CsrResult ConvertCsrSdioToCsrHipResult(card_t *card, CsrResult csrResult)
{
CsrResult r = CSR_RESULT_FAILURE;
switch (csrResult)
{
case CSR_RESULT_SUCCESS:
r = CSR_RESULT_SUCCESS;
break;
case CSR_SDIO_RESULT_TIMEOUT:
case CSR_SDIO_RESULT_CRC_ERROR:
r = CSR_RESULT_FAILURE;
break;
case CSR_SDIO_RESULT_NO_DEVICE:
r = CSR_WIFI_HIP_RESULT_NO_DEVICE;
break;
case CSR_SDIO_RESULT_INVALID_VALUE:
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
break;
case CSR_RESULT_FAILURE:
r = CSR_RESULT_FAILURE;
break;
default:
unifi_warning(card->ospriv, "Unrecognised csrResult error code: %d\n", csrResult);
break;
}
return r;
}
