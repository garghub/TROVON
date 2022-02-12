static void append_char(char c)
{
*unifi_dbgbuf_ptr++ = c;
if ((unifi_dbgbuf_ptr - unifi_debug_output) >= UNIFI_DEBUG_GBUFFER_SIZE)
{
unifi_dbgbuf_ptr = unifi_debug_output;
}
}
void unifi_debug_string_to_buf(const char *str)
{
const char *p = str;
while (*p)
{
append_char(*p);
p++;
}
unifi_dbgbuf_start = unifi_dbgbuf_ptr + 1;
if ((unifi_dbgbuf_start - unifi_debug_output) >= UNIFI_DEBUG_GBUFFER_SIZE)
{
unifi_dbgbuf_start = unifi_debug_output;
}
}
void unifi_debug_log_to_buf(const char *fmt, ...)
{
#define DEBUG_BUFFER_SIZE 80
static char s[DEBUG_BUFFER_SIZE];
va_list args;
va_start(args, fmt);
vsnprintf(s, DEBUG_BUFFER_SIZE, fmt, args);
va_end(args);
unifi_debug_string_to_buf(s);
}
static void CsrUInt16ToHex(u16 number, char *str)
{
u16 index;
u16 currentValue;
for (index = 0; index < 4; index++)
{
currentValue = (u16) (number & 0x000F);
number >>= 4;
str[3 - index] = (char) (currentValue > 9 ? currentValue + 55 : currentValue + '0');
}
str[4] = '\0';
}
void unifi_debug_hex_to_buf(const char *buff, u16 length)
{
char s[5];
u16 i;
for (i = 0; i < length; i = i + 2)
{
CsrUInt16ToHex(*((u16 *)(buff + i)), s);
unifi_debug_string_to_buf(s);
}
}
void unifi_debug_buf_dump(void)
{
s32 offset = unifi_dbgbuf_ptr - unifi_debug_output;
unifi_error(NULL, "HIP debug buffer offset=%d\n", offset);
dump_str(unifi_debug_output + offset, UNIFI_DEBUG_GBUFFER_SIZE - offset);
dump_str(unifi_debug_output, offset);
}
void prealloc_netdata_free(card_t *card)
{
unifi_warning(card->ospriv, "prealloc_netdata_free: IN: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
while (card->bulk_data_desc_list[card->prealloc_netdata_r].data_length != 0)
{
unifi_warning(card->ospriv, "prealloc_netdata_free: r=%d\n", card->prealloc_netdata_r);
unifi_net_data_free(card->ospriv, &card->bulk_data_desc_list[card->prealloc_netdata_r]);
card->prealloc_netdata_r++;
card->prealloc_netdata_r %= BULK_DATA_PRE_ALLOC_NUM;
}
card->prealloc_netdata_r = card->prealloc_netdata_w = 0;
unifi_warning(card->ospriv, "prealloc_netdata_free: OUT: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
}
CsrResult prealloc_netdata_alloc(card_t *card)
{
CsrResult r;
unifi_trace(card->ospriv, UDBG5, "prealloc_netdata_alloc: IN: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
while (card->bulk_data_desc_list[card->prealloc_netdata_w].data_length == 0)
{
r = unifi_net_data_malloc(card->ospriv, &card->bulk_data_desc_list[card->prealloc_netdata_w], NETDATA_PRE_ALLOC_BUF_SIZE);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "prealloc_netdata_alloc: Failed to allocate t-h bulk data\n");
return CSR_RESULT_FAILURE;
}
card->prealloc_netdata_w++;
card->prealloc_netdata_w %= BULK_DATA_PRE_ALLOC_NUM;
}
unifi_trace(card->ospriv, UDBG5, "prealloc_netdata_alloc: OUT: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
return CSR_RESULT_SUCCESS;
}
static CsrResult prealloc_netdata_get(card_t *card, bulk_data_desc_t *bulk_data_slot, u32 size)
{
CsrResult r;
unifi_trace(card->ospriv, UDBG5, "prealloc_netdata_get: IN: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
if (card->bulk_data_desc_list[card->prealloc_netdata_r].data_length == 0)
{
unifi_error(card->ospriv, "prealloc_netdata_get: data_length = 0\n");
}
if ((size > NETDATA_PRE_ALLOC_BUF_SIZE) || (card->bulk_data_desc_list[card->prealloc_netdata_r].data_length == 0))
{
unifi_warning(card->ospriv, "prealloc_netdata_get: Calling net_data_malloc\n");
r = unifi_net_data_malloc(card->ospriv, bulk_data_slot, size);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "prealloc_netdata_get: Failed to allocate t-h bulk data\n");
return CSR_RESULT_FAILURE;
}
return CSR_RESULT_SUCCESS;
}
*bulk_data_slot = card->bulk_data_desc_list[card->prealloc_netdata_r];
card->bulk_data_desc_list[card->prealloc_netdata_r].os_data_ptr = NULL;
card->bulk_data_desc_list[card->prealloc_netdata_r].os_net_buf_ptr = NULL;
card->bulk_data_desc_list[card->prealloc_netdata_r].net_buf_length = 0;
card->bulk_data_desc_list[card->prealloc_netdata_r].data_length = 0;
card->prealloc_netdata_r++;
card->prealloc_netdata_r %= BULK_DATA_PRE_ALLOC_NUM;
unifi_trace(card->ospriv, UDBG5, "prealloc_netdata_get: OUT: w=%d r=%d\n", card->prealloc_netdata_w, card->prealloc_netdata_r);
return CSR_RESULT_SUCCESS;
}
void unifi_sdio_interrupt_handler(card_t *card)
{
card->bh_reason_unifi = 1;
(void)unifi_run_bh(card->ospriv);
}
CsrResult unifi_configure_low_power_mode(card_t *card,
enum unifi_low_power_mode low_power_mode,
enum unifi_periodic_wake_mode periodic_wake_mode)
{
card->low_power_mode = low_power_mode;
card->periodic_wake_mode = periodic_wake_mode;
unifi_trace(card->ospriv, UDBG1,
"unifi_configure_low_power_mode: new mode = %s, wake_host = %s\n",
(low_power_mode == UNIFI_LOW_POWER_DISABLED)?"disabled" : "enabled",
(periodic_wake_mode == UNIFI_PERIODIC_WAKE_HOST_DISABLED)?"FALSE" : "TRUE");
(void)unifi_run_bh(card->ospriv);
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_force_low_power_mode(card_t *card)
{
if (card->low_power_mode == UNIFI_LOW_POWER_DISABLED)
{
unifi_error(card->ospriv, "Attempt to set mode to TORPID when lower power mode is disabled\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
return unifi_set_host_state(card, UNIFI_HOST_STATE_TORPID);
}
CsrResult unifi_bh(card_t *card, u32 *remaining)
{
CsrResult r;
CsrResult csrResult;
u8 pending;
s32 iostate, j;
const enum unifi_low_power_mode low_power_mode = card->low_power_mode;
u16 data_slots_used = 0;
r = process_clock_request(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Error setting maximum SDIO clock\n");
goto exit;
}
do
{
if (card->host_state == UNIFI_HOST_STATE_DROWSY || card->host_state == UNIFI_HOST_STATE_TORPID)
{
u8 reason_unifi;
reason_unifi = card->bh_reason_unifi;
r = CardPendingInt(card, &pending);
if (r != CSR_RESULT_SUCCESS)
{
goto exit;
}
if (pending)
{
unifi_trace(card->ospriv, UDBG5,
"UNIFI_HOST_STATE_%s: Set state to AWAKE.\n",
(card->host_state == UNIFI_HOST_STATE_TORPID)?"TORPID" : "DROWSY");
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r == CSR_RESULT_SUCCESS)
{
(*remaining) = 0;
break;
}
}
else if (reason_unifi)
{
CsrSdioInterruptAcknowledge(card->sdio_if);
}
if ((card->host_state == UNIFI_HOST_STATE_TORPID) && card->bh_reason_host)
{
r = unifi_set_host_state(card, UNIFI_HOST_STATE_DROWSY);
if (r == CSR_RESULT_SUCCESS)
{
card->bh_reason_host = 0;
(*remaining) = UNIFI_DEFAULT_WAKE_TIMEOUT;
return CSR_RESULT_SUCCESS;
}
goto exit;
}
if ((card->host_state == UNIFI_HOST_STATE_DROWSY) && ((*remaining) == 0))
{
unifi_error(card->ospriv, "UniFi did not wake up on time...\n");
r = unifi_check_io_status(card, &iostate);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
goto exit;
}
return CSR_RESULT_FAILURE;
}
}
else
{
if (card->bh_reason_unifi || card->bh_reason_host)
{
break;
}
if (((*remaining) == 0) && (low_power_mode == UNIFI_LOW_POWER_ENABLED))
{
r = unifi_set_host_state(card, UNIFI_HOST_STATE_TORPID);
if (r == CSR_RESULT_SUCCESS)
{
(*remaining) = 0;
return CSR_RESULT_SUCCESS;
}
goto exit;
}
}
return CSR_RESULT_SUCCESS;
} while (0);
csrResult = CsrSdioInterruptDisable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
r = CSR_WIFI_HIP_RESULT_NO_DEVICE;
goto exit;
}
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
unifi_error(card->ospriv, "Failed to disable SDIO interrupts. unifi_bh queues error.\n");
goto exit;
}
CsrSdioInterruptAcknowledge(card->sdio_if);
r = process_bh(card);
if (r != CSR_RESULT_SUCCESS)
{
goto exit;
}
for (j = 0; j < UNIFI_NO_OF_TX_QS; j++)
{
data_slots_used += CSR_WIFI_HIP_Q_SLOTS_USED(&card->fh_traffic_queue[j]);
}
if ((low_power_mode == UNIFI_LOW_POWER_ENABLED) && (data_slots_used == 0))
{
#ifndef CSR_WIFI_HIP_TA_DISABLE
if (card->ta_sampling.traffic_type != CSR_WIFI_ROUTER_CTRL_TRAFFIC_TYPE_PERIODIC)
{
#endif
unifi_trace(card->ospriv, UDBG5,
"Traffic is not periodic, set timer for TORPID.\n");
(*remaining) = UNIFI_DEFAULT_HOST_IDLE_TIMEOUT;
#ifndef CSR_WIFI_HIP_TA_DISABLE
}
else
{
unifi_trace(card->ospriv, UDBG5,
"Traffic is periodic, set unifi to TORPID immediately.\n");
if (CardAreAllFromHostDataSlotsEmpty(card) == 1)
{
r = unifi_set_host_state(card, UNIFI_HOST_STATE_TORPID);
if (r != CSR_RESULT_SUCCESS)
{
goto exit;
}
}
}
#endif
}
csrResult = CsrSdioInterruptEnable(card->sdio_if);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
r = CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
unifi_error(card->ospriv, "Failed to enable SDIO interrupt\n");
}
exit:
unifi_trace(card->ospriv, UDBG4, "New state=%d\n", card->host_state);
if (r != CSR_RESULT_SUCCESS)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_buf_dump();
#endif
if (card->bh_reason_unifi)
{
CsrSdioInterruptAcknowledge(card->sdio_if);
}
unifi_error(card->ospriv,
"unifi_bh: state=%d %c, clock=%dkHz, interrupt=%d host=%d, power_save=%s\n",
card->host_state,
(card->host_state == UNIFI_HOST_STATE_AWAKE)?'A' : (card->host_state == UNIFI_HOST_STATE_DROWSY)?'D' : 'T',
card->sdio_clock_speed / 1000,
card->bh_reason_unifi, card->bh_reason_host,
(low_power_mode == UNIFI_LOW_POWER_DISABLED)?"disabled" : "enabled");
(void)unifi_capture_panic(card);
(void)unifi_coredump_request_at_next_reset(card, 1);
}
return r;
}
static CsrResult process_clock_request(card_t *card)
{
CsrResult r = CSR_RESULT_SUCCESS;
CsrResult csrResult;
if (!card->request_max_clock)
{
return CSR_RESULT_SUCCESS;
}
if (card->host_state == UNIFI_HOST_STATE_AWAKE)
{
unifi_trace(card->ospriv, UDBG1, "Set SDIO max clock\n");
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_MAX_HZ);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
}
else
{
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_MAX_HZ;
}
}
else
{
unifi_trace(card->ospriv, UDBG1, "Will set SDIO max clock after wakeup\n");
}
card->request_max_clock = 0;
return r;
}
static CsrResult process_bh(card_t *card)
{
CsrResult r;
u8 more;
more = FALSE;
do
{
do
{
if (card->intmode & CSR_WIFI_INTMODE_RUN_BH_ONCE)
{
break;
}
r = handle_host_protocol(card, &more);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("c52=%d c53=%d tx=%d txc=%d rx=%d s=%d t=%d fc=%d\n",
card->cmd_prof.cmd52_count,
card->cmd_prof.cmd53_count,
card->cmd_prof.tx_count,
card->cmd_prof.tx_cfm_count,
card->cmd_prof.rx_count,
card->cmd_prof.sdio_cmd_signal,
card->cmd_prof.sdio_cmd_to_host,
card->cmd_prof.sdio_cmd_from_host_and_clear
);
card->cmd_prof.cmd52_count = card->cmd_prof.cmd53_count = 0;
card->cmd_prof.tx_count = card->cmd_prof.tx_cfm_count = card->cmd_prof.rx_count = 0;
card->cmd_prof.cmd52_f0_r_count = 0;
card->cmd_prof.cmd52_f0_w_count = 0;
card->cmd_prof.cmd52_r8or16_count = 0;
card->cmd_prof.cmd52_w8or16_count = 0;
card->cmd_prof.cmd52_r16_count = 0;
card->cmd_prof.cmd52_w16_count = 0;
card->cmd_prof.cmd52_r32_count = 0;
card->cmd_prof.sdio_cmd_signal = 0;
card->cmd_prof.sdio_cmd_clear_slot = 0;
card->cmd_prof.sdio_cmd_to_host = 0;
card->cmd_prof.sdio_cmd_from_host = 0;
card->cmd_prof.sdio_cmd_from_host_and_clear = 0;
#endif
} while (more || card->bh_reason_unifi || card->bh_reason_host);
r = CardClearInt(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to acknowledge interrupt.\n");
return r;
}
r = handle_host_protocol(card, &more);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("c52=%d c53=%d tx=%d txc=%d rx=%d s=%d t=%d fc=%d\n",
card->cmd_prof.cmd52_count,
card->cmd_prof.cmd53_count,
card->cmd_prof.tx_count,
card->cmd_prof.tx_cfm_count,
card->cmd_prof.rx_count,
card->cmd_prof.sdio_cmd_signal,
card->cmd_prof.sdio_cmd_to_host,
card->cmd_prof.sdio_cmd_from_host_and_clear
);
card->cmd_prof.cmd52_count = card->cmd_prof.cmd53_count = 0;
card->cmd_prof.tx_count = card->cmd_prof.tx_cfm_count = card->cmd_prof.rx_count = 0;
card->cmd_prof.cmd52_f0_r_count = 0;
card->cmd_prof.cmd52_f0_w_count = 0;
card->cmd_prof.cmd52_r8or16_count = 0;
card->cmd_prof.cmd52_w8or16_count = 0;
card->cmd_prof.cmd52_r16_count = 0;
card->cmd_prof.cmd52_w16_count = 0;
card->cmd_prof.cmd52_r32_count = 0;
card->cmd_prof.sdio_cmd_signal = 0;
card->cmd_prof.sdio_cmd_clear_slot = 0;
card->cmd_prof.sdio_cmd_to_host = 0;
card->cmd_prof.sdio_cmd_from_host = 0;
card->cmd_prof.sdio_cmd_from_host_and_clear = 0;
#endif
if (card->intmode & CSR_WIFI_INTMODE_RUN_BH_ONCE)
{
break;
}
} while (more || card->bh_reason_unifi || card->bh_reason_host);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
if ((card->intmode & CSR_WIFI_INTMODE_RUN_BH_ONCE) == 0)
{
unifi_debug_log_to_buf("proc=%d\n",
card->cmd_prof.process_count);
}
#endif
return CSR_RESULT_SUCCESS;
}
static CsrResult handle_host_protocol(card_t *card, u8 *processed_something)
{
CsrResult r;
s32 done;
*processed_something = FALSE;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, " ======================== \n");
#endif
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.process_count++;
#endif
card->bh_reason_unifi = card->bh_reason_host = 0;
card->generate_interrupt = 0;
r = read_to_host_signals(card, &done);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Error occured reading to-host signals\n");
return r;
}
if (done > 0)
{
*processed_something = TRUE;
}
r = process_to_host_signals(card, &done);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Error occured processing to-host signals\n");
return r;
}
r = process_fh_cmd_queue(card, &done);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Error occured processing from-host signals\n");
return r;
}
if (done > 0)
{
*processed_something = TRUE;
}
r = process_fh_traffic_queue(card, &done);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Error occured processing from-host data signals\n");
return r;
}
if (done > 0)
{
*processed_something = TRUE;
}
r = flush_fh_buffer(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to copy from-host signals to UniFi\n");
return r;
}
if (card->generate_interrupt)
{
r = CardGenInt(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to notify UniFi that queues have been modified.\n");
return r;
}
}
#ifdef CSR_WIFI_RX_PATH_SPLIT
#ifdef CSR_WIFI_RX_PATH_SPLIT_DONT_USE_WQ
unifi_rx_queue_flush(card->ospriv);
#endif
#endif
restart_packet_flow(card);
#ifdef CSR_PRE_ALLOC_NET_DATA
r = prealloc_netdata_alloc(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "prealloc_netdata failed\n");
return r;
}
#endif
return r;
}
static CsrResult read_to_host_signals(card_t *card, s32 *processed)
{
s32 count_thw, count_thr;
s32 unread_chunks, unread_bytes;
CsrResult r;
*processed = 0;
count_thw = unifi_read_shared_count(card, card->sdio_ctrl_addr + 4);
if (count_thw < 0)
{
unifi_error(card->ospriv, "Failed to read to-host sig written count\n");
return CSR_RESULT_FAILURE;
}
card->to_host_signals_w = count_thw;
count_thr = card->to_host_signals_r;
if (count_thw == count_thr)
{
return CSR_RESULT_SUCCESS;
}
unread_chunks =
(((count_thw - count_thr) + 128) % 128) - card->th_buffer.count;
if (unread_chunks == 0)
{
return CSR_RESULT_SUCCESS;
}
unread_bytes = card->config_data.sig_frag_size * unread_chunks;
r = unifi_bulk_rw(card,
card->config_data.tohost_sigbuf_handle,
card->th_buffer.ptr,
unread_bytes,
UNIFI_SDIO_READ);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read ToHost signal\n");
return r;
}
card->th_buffer.ptr += unread_bytes;
card->th_buffer.count += (u16)unread_chunks;
*processed = 1;
return CSR_RESULT_SUCCESS;
}
static CsrResult update_to_host_signals_r(card_t *card, s16 pending)
{
CsrResult r;
card->to_host_signals_r =
(card->to_host_signals_r + (card->th_buffer.count - pending)) % 128;
card->th_buffer.count = pending;
r = unifi_write_8_or_16(card, card->sdio_ctrl_addr + 6,
(u8)card->to_host_signals_r);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to update to-host signals read\n");
return r;
}
r = CardGenInt(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to notify UniFi that we processed to-host signals.\n");
return r;
}
card->generate_interrupt = 0;
return CSR_RESULT_SUCCESS;
}
static void read_unpack_cmd(const u8 *ptr, bulk_data_cmd_t *bulk_data_cmd)
{
s16 index = 0;
bulk_data_cmd->cmd_and_len = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(ptr + index);
index += SIZEOF_UINT16;
bulk_data_cmd->data_slot = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(ptr + index);
index += SIZEOF_UINT16;
bulk_data_cmd->offset = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(ptr + index);
index += SIZEOF_UINT16;
bulk_data_cmd->buffer_handle = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(ptr + index);
index += SIZEOF_UINT16;
}
static CsrResult process_to_host_signals(card_t *card, s32 *processed)
{
s16 pending;
s16 remaining;
u8 *bufptr;
bulk_data_param_t data_ptrs;
s16 cmd;
u16 sig_len;
s16 i;
u16 chunks_in_buf;
u16 bytes_transferred = 0;
CsrResult r = CSR_RESULT_SUCCESS;
*processed = 0;
pending = card->th_buffer.count;
unifi_trace(card->ospriv, UDBG4, "handling %d to-host chunks\n", pending);
if (!pending)
{
return CSR_RESULT_SUCCESS;
}
bufptr = card->th_buffer.buf;
while (pending > 0)
{
s16 f_flush_count = 0;
cmd = bufptr[1] >> 4;
sig_len = bufptr[0] + ((bufptr[1] & 0x0F) << 8);
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Received UniFi msg cmd=%d, len=%d\n",
cmd, sig_len);
#endif
if ((sig_len == 0) &&
((cmd != SDIO_CMD_CLEAR_SLOT) && (cmd != SDIO_CMD_PADDING)))
{
unifi_error(card->ospriv, "incomplete signal or command: has size zero\n");
return CSR_RESULT_FAILURE;
}
if (cmd == SDIO_CMD_SIGNAL)
{
chunks_in_buf = GET_CHUNKS_FOR(card->config_data.sig_frag_size, (u16)(sig_len + 2));
}
else
{
chunks_in_buf = 1;
}
if (chunks_in_buf > (u16)pending)
{
unifi_error(card->ospriv, "incomplete signal (0x%x?): need %d chunks, got %d\n",
GET_SIGNAL_ID(bufptr + 2),
chunks_in_buf, pending);
unifi_error(card->ospriv, " thsw=%d, thsr=%d\n",
card->to_host_signals_w,
card->to_host_signals_r);
return CSR_RESULT_FAILURE;
}
switch (cmd)
{
case SDIO_CMD_SIGNAL:
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.sdio_cmd_signal++;
#endif
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
u16 data_len = GET_PACKED_DATAREF_LEN(bufptr + 2, i);
if (data_len > card->config_data.data_slot_size)
{
unifi_error(card->ospriv,
"Bulk Data length (%d) exceeds Maximum Bulk Data length (%d)\n",
data_len, card->config_data.data_slot_size);
return CSR_RESULT_FAILURE;
}
if (data_len != 0)
{
s16 slot = GET_PACKED_DATAREF_SLOT(bufptr + 2, i);
if (slot >= card->config_data.num_tohost_data_slots)
{
unifi_error(card->ospriv, "!!!bad slot number in to-host signal: %d, sig 0x%X\n",
slot, cmd);
return CSR_RESULT_FAILURE;
}
data_ptrs.d[i].os_data_ptr = card->to_host_data[slot].os_data_ptr;
data_ptrs.d[i].os_net_buf_ptr = card->to_host_data[slot].os_net_buf_ptr;
data_ptrs.d[i].net_buf_length = card->to_host_data[slot].net_buf_length;
data_ptrs.d[i].data_length = data_len;
}
else
{
UNIFI_INIT_BULK_DATA(&data_ptrs.d[i]);
}
}
if (card->udi_hook)
{
(*card->udi_hook)(card->ospriv, bufptr + 2, sig_len,
&data_ptrs, UDI_LOG_TO_HOST);
}
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
if (GET_SIGNAL_ID(bufptr + 2) == CSR_MA_PACKET_CONFIRM_ID)
{
card->cmd_prof.tx_cfm_count++;
}
else if (GET_SIGNAL_ID(bufptr + 2) == CSR_MA_PACKET_INDICATION_ID)
{
if (data_ptrs.d[0].os_data_ptr)
{
if ((*data_ptrs.d[0].os_data_ptr) & 0x08)
{
card->cmd_prof.rx_count++;
}
}
}
#endif
if (GET_SIGNAL_ID(bufptr + 2) == CSR_MA_PACKET_CONFIRM_ID)
{
u32 host_tag = GET_PACKED_MA_PACKET_CONFIRM_HOST_TAG(bufptr + 2);
u16 status = GET_PACKED_MA_PACKET_CONFIRM_TRANSMISSION_STATUS(bufptr + 2);
unifi_trace(card->ospriv, UDBG4, "process_to_host_signals signal ID=%x host Tag=%x status=%x\n",
GET_SIGNAL_ID(bufptr + 2), host_tag, status);
if (status && (card->fh_slot_host_tag_record))
{
u16 num_fh_slots = card->config_data.num_fromhost_data_slots;
for (i = 0; i < num_fh_slots; i++)
{
if (card->fh_slot_host_tag_record[i] == host_tag)
{
#ifdef CSR_WIFI_REQUEUE_PACKET_TO_HAL
r = unifi_reque_ma_packet_request(card->ospriv, host_tag, status, &card->from_host_data[i].bd);
card->fh_slot_host_tag_record[i] = CSR_WIFI_HIP_RESERVED_HOST_TAG;
if (CSR_RESULT_SUCCESS != r)
{
unifi_trace(card->ospriv, UDBG5, "process_to_host_signals: Failed to requeue Packet(hTag:%x) back to HAL \n", host_tag);
CardClearFromHostDataSlot(card, i);
}
else
{
CardClearFromHostDataSlotWithoutFreeingBulkData(card, i);
}
#else
unifi_trace(card->ospriv, UDBG4, "process_to_host_signals Clear slot=%x host tag=%x\n", i, host_tag);
card->fh_slot_host_tag_record[i] = CSR_WIFI_HIP_RESERVED_HOST_TAG;
CardClearFromHostDataSlot(card, i);
#endif
break;
}
}
}
}
unifi_receive_event(card->ospriv, bufptr + 2, sig_len, &data_ptrs);
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
if (GET_PACKED_DATAREF_LEN(bufptr + 2, i) != 0)
{
s16 slot = GET_PACKED_DATAREF_SLOT(bufptr + 2, i);
if (slot < card->config_data.num_tohost_data_slots)
{
UNIFI_INIT_BULK_DATA(&card->to_host_data[slot]);
}
}
}
#ifndef CSR_WIFI_DEFER_TH_FLUSH
if (bytes_transferred >= TO_HOST_FLUSH_THRESHOLD)
{
f_flush_count = 1;
}
#endif
break;
case SDIO_CMD_CLEAR_SLOT:
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.sdio_cmd_clear_slot++;
#endif
if (sig_len != 0)
{
unifi_error(card->ospriv, "process_to_host_signals: clear slot, bad data len: 0x%X at offset %d\n",
sig_len, bufptr - card->th_buffer.buf);
return CSR_RESULT_FAILURE;
}
r = process_clear_slot_command(card, bufptr);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to process clear slot\n");
return r;
}
break;
case SDIO_CMD_TO_HOST_TRANSFER:
case SDIO_CMD_FROM_HOST_TRANSFER:
case SDIO_CMD_FROM_HOST_AND_CLEAR:
case SDIO_CMD_OVERLAY_TRANSFER:
if (sig_len & 1)
{
unifi_error(card->ospriv, "process_to_host_signals: bulk data, bad data len: 0x%X at offset %d\n",
sig_len, bufptr - card->th_buffer.buf);
return CSR_RESULT_FAILURE;
}
r = process_bulk_data_command(card, bufptr, cmd, sig_len);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to process bulk cmd\n");
return r;
}
bytes_transferred += sig_len;
if (cmd == SDIO_CMD_FROM_HOST_AND_CLEAR)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.sdio_cmd_from_host_and_clear++;
#endif
#ifndef CSR_WIFI_DEFER_TH_FLUSH
f_flush_count = 1;
#endif
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
else if (cmd == SDIO_CMD_FROM_HOST_TRANSFER)
{
card->cmd_prof.sdio_cmd_from_host++;
}
else if (cmd == SDIO_CMD_TO_HOST_TRANSFER)
{
card->cmd_prof.sdio_cmd_to_host++;
}
#endif
break;
case SDIO_CMD_PADDING:
break;
default:
unifi_error(card->ospriv, "Unrecognised to-host command: %d\n", cmd);
break;
}
bufptr += chunks_in_buf * card->config_data.sig_frag_size;
pending -= chunks_in_buf;
if (f_flush_count)
{
r = update_to_host_signals_r(card, pending);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
bytes_transferred = 0;
}
}
if (pending)
{
unifi_warning(card->ospriv, "proc_th_sigs: %d unprocessed\n", pending);
}
if (card->th_buffer.count != pending)
{
r = update_to_host_signals_r(card, pending);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
}
remaining = card->th_buffer.ptr - bufptr;
if (remaining < 0)
{
unifi_error(card->ospriv, "Processing TH signals overran the buffer\n");
return CSR_RESULT_FAILURE;
}
if (remaining > 0)
{
u8 *d = card->th_buffer.buf;
u8 *s = bufptr;
s32 n = remaining;
while (n--)
{
*d++ = *s++;
}
}
card->th_buffer.ptr = card->th_buffer.buf + remaining;
*processed = 1;
return CSR_RESULT_SUCCESS;
}
static CsrResult process_clear_slot_command(card_t *card, const u8 *cmdptr)
{
u16 data_slot;
s16 slot;
data_slot = CSR_GET_UINT16_FROM_LITTLE_ENDIAN(cmdptr + SIZEOF_UINT16);
unifi_trace(card->ospriv, UDBG4, "Processing clear slot cmd, slot=0x%X\n",
data_slot);
slot = data_slot & 0x7FFF;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "CMD clear data slot 0x%04x\n", data_slot);
#endif
if (data_slot & SLOT_DIR_TO_HOST)
{
if (slot >= card->config_data.num_tohost_data_slots)
{
unifi_error(card->ospriv,
"Invalid to-host data slot in SDIO_CMD_CLEAR_SLOT: %d\n",
slot);
return CSR_RESULT_FAILURE;
}
unifi_warning(card->ospriv, "Unexpected clear to-host data slot cmd: 0x%04x\n",
data_slot);
}
else
{
if (slot >= card->config_data.num_fromhost_data_slots)
{
unifi_error(card->ospriv,
"Invalid from-host data slot in SDIO_CMD_CLEAR_SLOT: %d\n",
slot);
return CSR_RESULT_FAILURE;
}
return CSR_RESULT_SUCCESS;
}
return CSR_RESULT_SUCCESS;
}
static CsrResult process_bulk_data_command(card_t *card, const u8 *cmdptr,
s16 cmd, u16 len)
{
bulk_data_desc_t *bdslot;
#ifdef CSR_WIFI_ALIGNMENT_WORKAROUND
u8 *host_bulk_data_slot;
#endif
bulk_data_cmd_t bdcmd;
s16 offset;
s16 slot;
s16 dir;
CsrResult r;
read_unpack_cmd(cmdptr, &bdcmd);
unifi_trace(card->ospriv, UDBG4, "Processing bulk data cmd %d %s, len=%d, slot=0x%X\n",
cmd, lookup_bulkcmd_name(cmd), len, bdcmd.data_slot);
if (card->sdio_io_block_pad)
{
len = (len + card->sdio_io_block_size - 1) & ~(card->sdio_io_block_size - 1);
unifi_trace(card->ospriv, UDBG4, "Rounded bulk data length up to %d\n", len);
}
slot = bdcmd.data_slot & 0x7FFF;
if (cmd == SDIO_CMD_OVERLAY_TRANSFER)
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
else
{
if (bdcmd.data_slot & SLOT_DIR_TO_HOST)
{
if (slot >= card->config_data.num_tohost_data_slots)
{
unifi_error(card->ospriv,
"Invalid to-host data slot in SDIO bulk xfr req: %d\n",
slot);
return CSR_RESULT_FAILURE;
}
#ifdef CSR_PRE_ALLOC_NET_DATA
r = prealloc_netdata_get(card, &card->to_host_data[slot], len);
#else
r = unifi_net_data_malloc(card->ospriv, &card->to_host_data[slot], len);
#endif
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to allocate t-h bulk data\n");
return CSR_RESULT_FAILURE;
}
bdslot = &card->to_host_data[slot];
r = unifi_net_dma_align(card->ospriv, bdslot);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to align t-h bulk data buffer for DMA\n");
return CSR_RESULT_FAILURE;
}
}
else
{
if (slot >= card->config_data.num_fromhost_data_slots)
{
unifi_error(card->ospriv,
"Invalid from-host data slot in SDIO bulk xfr req: %d\n",
slot);
return CSR_RESULT_FAILURE;
}
bdslot = &card->from_host_data[slot].bd;
}
offset = bdcmd.offset;
}
dir = (cmd == SDIO_CMD_TO_HOST_TRANSFER)?
UNIFI_SDIO_READ : UNIFI_SDIO_WRITE;
unifi_trace(card->ospriv, UDBG4,
"Bulk %c %s len=%d, handle %d - slot=%d %p+(%d)\n",
(dir == UNIFI_SDIO_READ)?'R' : 'W',
lookup_bulkcmd_name(cmd),
len,
bdcmd.buffer_handle,
slot, bdslot->os_data_ptr, offset);
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Bulk %s len=%d, handle %d - slot=%d %p+(%d)\n",
lookup_bulkcmd_name(cmd),
len,
bdcmd.buffer_handle,
slot, bdslot->os_data_ptr, offset);
#endif
if (bdslot->os_data_ptr == NULL)
{
unifi_error(card->ospriv, "Null os_data_ptr - Bulk %s handle %d - slot=%d o=(%d)\n",
lookup_bulkcmd_name(cmd),
bdcmd.buffer_handle,
slot,
offset);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
#ifdef CSR_WIFI_ALIGNMENT_WORKAROUND
if (len != 0 && (dir == UNIFI_SDIO_WRITE) && (((ptrdiff_t)bdslot->os_data_ptr + offset) & 3))
{
host_bulk_data_slot = kmalloc(len, GFP_KERNEL);
if (!host_bulk_data_slot)
{
unifi_error(card->ospriv, " failed to allocate request_data before unifi_bulk_rw\n");
return -1;
}
memcpy((void *)host_bulk_data_slot,
(void *)(bdslot->os_data_ptr + offset), len);
r = unifi_bulk_rw(card,
bdcmd.buffer_handle,
(void *)host_bulk_data_slot,
len,
dir);
}
else
#endif
{
r = unifi_bulk_rw(card,
bdcmd.buffer_handle,
(void *)(bdslot->os_data_ptr + offset),
len,
dir);
}
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv,
"Failed: %s hlen=%d, slen=%d, handle %d - slot=%d %p+0x%X\n",
lookup_bulkcmd_name(cmd),
len,
bdslot->data_length,
bdcmd.buffer_handle,
slot, bdslot->os_data_ptr, offset);
return r;
}
bdslot->data_length = len;
if (cmd == SDIO_CMD_FROM_HOST_AND_CLEAR)
{
if (slot >= card->config_data.num_fromhost_data_slots)
{
unifi_error(card->ospriv,
"Invalid from-host data slot in SDIO_CMD_FROM_HOST_AND_CLEAR: %d\n",
slot);
return CSR_RESULT_FAILURE;
}
#ifdef CSR_WIFI_ALIGNMENT_WORKAROUND
if ((len != 0) && (dir == UNIFI_SDIO_WRITE) && (((ptrdiff_t)bdslot->os_data_ptr + offset) & 3))
{
kfree(host_bulk_data_slot);
}
#endif
if (card->fh_slot_host_tag_record)
{
unifi_trace(card->ospriv, UDBG5, "CopyFromHostAndClearSlot Reset entry for slot=%d\n", slot);
card->fh_slot_host_tag_record[slot] = CSR_WIFI_HIP_RESERVED_HOST_TAG;
}
CardClearFromHostDataSlot(card, slot);
}
return CSR_RESULT_SUCCESS;
}
static CsrResult check_fh_sig_slots(card_t *card, u16 needed, s32 *space_fh)
{
u32 count_fhw;
u32 occupied_fh, slots_fh;
s32 count_fhr;
count_fhw = card->from_host_signals_w;
count_fhr = card->from_host_signals_r;
slots_fh = card->config_data.num_fromhost_sig_frags;
occupied_fh = (count_fhw - count_fhr) % 128;
if (slots_fh < occupied_fh)
{
*space_fh = 0;
}
else
{
*space_fh = slots_fh - occupied_fh;
}
if ((occupied_fh != 0) && (*space_fh < needed))
{
count_fhr = unifi_read_shared_count(card, card->sdio_ctrl_addr + 2);
if (count_fhr < 0)
{
unifi_error(card->ospriv, "Failed to read from-host sig read count\n");
return CSR_RESULT_FAILURE;
}
card->from_host_signals_r = count_fhr;
occupied_fh = (count_fhw - count_fhr) % 128;
*space_fh = slots_fh - occupied_fh;
}
return CSR_RESULT_SUCCESS;
}
static CsrResult process_fh_cmd_queue(card_t *card, s32 *processed)
{
q_t *sigq = &card->fh_command_queue;
CsrResult r;
u16 pending_sigs;
u16 pending_chunks;
u16 needed_chunks;
s32 space_chunks;
u16 q_index;
*processed = 0;
pending_sigs = CSR_WIFI_HIP_Q_SLOTS_USED(sigq);
unifi_trace(card->ospriv, UDBG5, "proc_fh: %d pending\n", pending_sigs);
if (pending_sigs == 0)
{
return CSR_RESULT_SUCCESS;
}
for (pending_chunks = 0, q_index = CSR_WIFI_HIP_Q_NEXT_R_SLOT(sigq);
q_index != CSR_WIFI_HIP_Q_NEXT_W_SLOT(sigq);
q_index = CSR_WIFI_HIP_Q_WRAP(sigq, q_index + 1))
{
card_signal_t *csptr = CSR_WIFI_HIP_Q_SLOT_DATA(sigq, q_index);
pending_chunks += GET_CHUNKS_FOR(card->config_data.sig_frag_size, (u16)(csptr->signal_length + 2));
}
needed_chunks = pending_chunks + card->fh_buffer.count;
ROUND_UP_NEEDED_CHUNKS(card, needed_chunks);
r = check_fh_sig_slots(card, needed_chunks, &space_chunks);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read fh sig count\n");
return r;
}
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "proc_fh: %d chunks free, need %d\n",
space_chunks, needed_chunks);
#endif
if (needed_chunks > (u16)space_chunks)
{
ROUND_UP_SPACE_CHUNKS(card, space_chunks);
if ((u16)space_chunks <= card->fh_buffer.count)
{
unifi_error(card->ospriv, "not enough room to send signals, need %d chunks, %d free\n",
card->fh_buffer.count, space_chunks);
card->generate_interrupt = 1;
return CSR_RESULT_SUCCESS;
}
pending_chunks = (u16)(space_chunks - card->fh_buffer.count);
}
while (pending_sigs-- && pending_chunks > 0)
{
card_signal_t *csptr;
s16 i;
u16 sig_chunks, total_length, free_chunks_in_fh_buffer;
bulk_data_param_t bulkdata;
u8 *packed_sigptr;
u16 signal_length = 0;
q_index = CSR_WIFI_HIP_Q_NEXT_R_SLOT(sigq);
csptr = CSR_WIFI_HIP_Q_SLOT_DATA(sigq, q_index);
signal_length = csptr->signal_length;
if ((signal_length & 1) || (signal_length > UNIFI_PACKED_SIGBUF_SIZE))
{
unifi_error(card->ospriv, "process_fh_queue: Bad len: %d\n", signal_length);
return CSR_RESULT_FAILURE;
}
sig_chunks = GET_CHUNKS_FOR(card->config_data.sig_frag_size, (u16)(signal_length + 2));
free_chunks_in_fh_buffer = GET_CHUNKS_FOR(card->config_data.sig_frag_size,
(u16)((card->fh_buffer.buf + UNIFI_FH_BUF_SIZE) - card->fh_buffer.ptr));
if (free_chunks_in_fh_buffer < sig_chunks)
{
unifi_notice(card->ospriv, "proc_fh_cmd_q: no room in fh buffer for 0x%.4X, deferring\n",
(u16)(GET_SIGNAL_ID(csptr->sigbuf)));
break;
}
packed_sigptr = csptr->sigbuf;
if (CSR_RESULT_FAILURE == CardWriteBulkData(card, csptr, UNIFI_TRAFFIC_Q_MLME))
{
unifi_notice(card->ospriv, "proc_fh_cmd_q: no fh data slots for 0x%.4X, deferring\n",
(u16)(GET_SIGNAL_ID(csptr->sigbuf)));
break;
}
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; i++)
{
if (csptr->bulkdata[i].data_length == 0)
{
UNIFI_INIT_BULK_DATA(&bulkdata.d[i]);
}
else
{
bulkdata.d[i].os_data_ptr = csptr->bulkdata[i].os_data_ptr;
bulkdata.d[i].data_length = csptr->bulkdata[i].data_length;
}
UNIFI_INIT_BULK_DATA(&csptr->bulkdata[i]);
}
unifi_trace(card->ospriv, UDBG2, "Sending signal 0x%.4X\n",
GET_SIGNAL_ID(packed_sigptr));
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Sending signal 0x%.4X\n",
GET_SIGNAL_ID(packed_sigptr));
#endif
total_length = sig_chunks * card->config_data.sig_frag_size;
card->fh_buffer.ptr[0] = (u8)(signal_length & 0xff);
card->fh_buffer.ptr[1] =
(u8)(((signal_length >> 8) & 0xf) | (SDIO_CMD_SIGNAL << 4));
memcpy(card->fh_buffer.ptr + 2, packed_sigptr, signal_length);
memset(card->fh_buffer.ptr + 2 + signal_length, 0,
total_length - (2 + signal_length));
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "proc_fh: fh_buffer %d bytes \n",
signal_length + 2);
dump(card->fh_buffer.ptr, signal_length + 2);
unifi_trace(card->ospriv, UDBG1, " \n");
#endif
card->fh_buffer.ptr += total_length;
card->fh_buffer.count += sig_chunks;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Added %d to fh buf, len now %d, count %d\n",
signal_length,
card->fh_buffer.ptr - card->fh_buffer.buf,
card->fh_buffer.count);
#endif
(*processed)++;
pending_chunks -= sig_chunks;
if (card->udi_hook)
{
(*card->udi_hook)(card->ospriv, packed_sigptr, signal_length,
&bulkdata, UDI_LOG_FROM_HOST);
}
csptr->signal_length = 0;
CSR_WIFI_HIP_Q_INC_R(sigq);
}
return CSR_RESULT_SUCCESS;
}
static CsrResult process_fh_traffic_queue(card_t *card, s32 *processed)
{
q_t *sigq = card->fh_traffic_queue;
CsrResult r;
s16 n = 0;
s32 q_no;
u16 pending_sigs = 0;
u16 pending_chunks = 0;
u16 needed_chunks;
s32 space_chunks;
u16 q_index;
u32 host_tag = 0;
u16 slot_num = 0;
*processed = 0;
for (n = UNIFI_NO_OF_TX_QS - 1; n >= 0; n--)
{
pending_sigs += CSR_WIFI_HIP_Q_SLOTS_USED(&sigq[n]);
unifi_trace(card->ospriv, UDBG5, "proc_fh%d: %d pending\n", n, pending_sigs);
for (q_index = CSR_WIFI_HIP_Q_NEXT_R_SLOT(&sigq[n]);
q_index != CSR_WIFI_HIP_Q_NEXT_W_SLOT(&sigq[n]);
q_index = CSR_WIFI_HIP_Q_WRAP(&sigq[n], q_index + 1))
{
card_signal_t *csptr = CSR_WIFI_HIP_Q_SLOT_DATA(&sigq[n], q_index);
pending_chunks += GET_CHUNKS_FOR(card->config_data.sig_frag_size, (u16)(csptr->signal_length + 2));
}
}
if (pending_sigs == 0)
{
return CSR_RESULT_SUCCESS;
}
needed_chunks = pending_chunks + card->fh_buffer.count;
ROUND_UP_NEEDED_CHUNKS(card, needed_chunks);
r = check_fh_sig_slots(card, needed_chunks, &space_chunks);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read fh sig count\n");
return r;
}
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv,
"process_fh_traffic_queue: %d chunks free, need %d\n",
space_chunks, needed_chunks);
read_fhsr(card);
#endif
if (needed_chunks > (u16)space_chunks)
{
ROUND_UP_SPACE_CHUNKS(card, space_chunks);
if ((u16)space_chunks <= card->fh_buffer.count)
{
unifi_error(card->ospriv, "not enough room to send signals, need %d chunks, %d free\n",
card->fh_buffer.count, space_chunks);
card->generate_interrupt = 1;
return 0;
}
pending_chunks = (u16)space_chunks - card->fh_buffer.count;
}
q_no = UNIFI_NO_OF_TX_QS - 1;
do
{
card_signal_t *csptr;
u16 sig_chunks, total_length, free_chunks_in_fh_buffer;
bulk_data_param_t bulkdata;
u8 *packed_sigptr;
u16 signal_length = 0;
if (CSR_WIFI_HIP_Q_SLOTS_USED(&sigq[q_no]) == 0)
{
q_no--;
continue;
}
q_index = CSR_WIFI_HIP_Q_NEXT_R_SLOT(&sigq[q_no]);
csptr = CSR_WIFI_HIP_Q_SLOT_DATA(&sigq[q_no], q_index);
signal_length = csptr->signal_length;
if ((signal_length & 1) || (signal_length > UNIFI_PACKED_SIGBUF_SIZE))
{
unifi_error(card->ospriv, "process_fh_traffic_queue: Bad len: %d\n", signal_length);
return CSR_RESULT_FAILURE;
}
sig_chunks = GET_CHUNKS_FOR(card->config_data.sig_frag_size, (u16)(signal_length + 2));
free_chunks_in_fh_buffer = GET_CHUNKS_FOR(card->config_data.sig_frag_size,
(u16)((card->fh_buffer.buf + UNIFI_FH_BUF_SIZE) - card->fh_buffer.ptr));
if (free_chunks_in_fh_buffer < sig_chunks)
{
unifi_notice(card->ospriv, "process_fh_traffic_queue: no more chunks.\n");
break;
}
packed_sigptr = csptr->sigbuf;
if (CSR_RESULT_FAILURE == CardWriteBulkData(card, csptr, (unifi_TrafficQueue)q_no))
{
q_no--;
continue;
}
if ((csptr->bulkdata[0].data_length == 0) || (csptr->bulkdata[0].os_data_ptr == NULL))
{
unifi_error(card->ospriv, "MA-PACKET.req with empty bulk data (%d bytes in %p)\n",
csptr->bulkdata[0].data_length, csptr->bulkdata[0].os_data_ptr);
dump(packed_sigptr, signal_length);
return CSR_RESULT_FAILURE;
}
bulkdata.d[0].os_data_ptr = csptr->bulkdata[0].os_data_ptr;
bulkdata.d[0].data_length = csptr->bulkdata[0].data_length;
bulkdata.d[0].os_net_buf_ptr = csptr->bulkdata[0].os_net_buf_ptr;
bulkdata.d[0].net_buf_length = csptr->bulkdata[0].net_buf_length;
if (card->fh_slot_host_tag_record)
{
host_tag = GET_PACKED_MA_PACKET_REQUEST_HOST_TAG(packed_sigptr);
slot_num = GET_PACKED_DATAREF_SLOT(packed_sigptr, 0) & 0x00FF;
unifi_trace(card->ospriv, UDBG5,
"process_fh_traffic_queue signal ID =%x fh slot=%x Host tag =%x\n",
GET_SIGNAL_ID(packed_sigptr), slot_num, host_tag);
card->fh_slot_host_tag_record[slot_num] = host_tag;
}
UNIFI_INIT_BULK_DATA(&bulkdata.d[1]);
UNIFI_INIT_BULK_DATA(&csptr->bulkdata[0]);
UNIFI_INIT_BULK_DATA(&csptr->bulkdata[1]);
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
if (bulkdata.d[0].os_data_ptr)
{
if ((*bulkdata.d[0].os_data_ptr) & 0x08)
{
card->cmd_prof.tx_count++;
}
}
#endif
unifi_trace(card->ospriv, UDBG3, "Sending signal 0x%.4X\n",
GET_SIGNAL_ID(packed_sigptr));
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Sending signal 0x%.4X\n",
GET_SIGNAL_ID(packed_sigptr));
#endif
total_length = sig_chunks * card->config_data.sig_frag_size;
card->fh_buffer.ptr[0] = (u8)(signal_length & 0xff);
card->fh_buffer.ptr[1] =
(u8)(((signal_length >> 8) & 0xf) | (SDIO_CMD_SIGNAL << 4));
memcpy(card->fh_buffer.ptr + 2, packed_sigptr, signal_length);
memset(card->fh_buffer.ptr + 2 + signal_length, 0,
total_length - (2 + signal_length));
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "proc_fh: fh_buffer %d bytes \n",
signal_length + 2);
dump(card->fh_buffer.ptr, signal_length + 2);
unifi_trace(card->ospriv, UDBG1, " \n");
#endif
card->fh_buffer.ptr += total_length;
card->fh_buffer.count += sig_chunks;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "Added %d to fh buf, len now %d, count %d\n",
signal_length,
card->fh_buffer.ptr - card->fh_buffer.buf,
card->fh_buffer.count);
#endif
(*processed)++;
pending_sigs--;
pending_chunks -= sig_chunks;
if (card->udi_hook)
{
(*card->udi_hook)(card->ospriv, packed_sigptr, signal_length,
&bulkdata, UDI_LOG_FROM_HOST);
}
csptr->signal_length = 0;
csptr->bulkdata[0].data_length = 0;
CSR_WIFI_HIP_Q_INC_R(&sigq[q_no]);
} while ((pending_sigs > 0) && (pending_chunks > 0) && (q_no >= 0));
return CSR_RESULT_SUCCESS;
}
static CsrResult flush_fh_buffer(card_t *card)
{
CsrResult r;
u16 len;
u16 sig_units;
u16 data_round;
u16 chunks_in_last_block;
u16 padding_chunks;
u16 i;
len = card->fh_buffer.ptr - card->fh_buffer.buf;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "fh_buffer is at %p, ptr= %p\n",
card->fh_buffer.buf, card->fh_buffer.ptr);
#endif
if (len == 0)
{
return CSR_RESULT_SUCCESS;
}
#ifdef CSR_WIFI_HIP_NOISY
if (dump_fh_buf)
{
dump(card->fh_buffer.buf, len);
dump_fh_buf = 0;
}
#endif
if (card->sdio_io_block_pad)
{
sig_units = card->config_data.sig_frag_size;
data_round = card->sdio_io_block_size;
if (data_round > sig_units)
{
chunks_in_last_block = (len % data_round) / sig_units;
if (chunks_in_last_block != 0)
{
padding_chunks = (data_round / sig_units) - chunks_in_last_block;
memset(card->fh_buffer.ptr, 0, padding_chunks * sig_units);
for (i = 0; i < padding_chunks; i++)
{
card->fh_buffer.ptr[1] = SDIO_CMD_PADDING << 4;
card->fh_buffer.ptr += sig_units;
}
card->fh_buffer.count += padding_chunks;
len += padding_chunks * sig_units;
}
}
}
r = unifi_bulk_rw(card,
card->config_data.fromhost_sigbuf_handle,
card->fh_buffer.buf,
len, UNIFI_SDIO_WRITE);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write fh signals: %u bytes, error %d\n", len, r);
return r;
}
card->from_host_signals_w =
(card->from_host_signals_w + card->fh_buffer.count) % 128u;
r = unifi_write_8_or_16(card, card->sdio_ctrl_addr + 0,
(u8)card->from_host_signals_w);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write fh signal count %u with error %d\n",
card->from_host_signals_w, r);
return r;
}
card->generate_interrupt = 1;
card->fh_buffer.ptr = card->fh_buffer.buf;
card->fh_buffer.count = 0;
#ifdef CSR_WIFI_HIP_NOISY
unifi_error(card->ospriv, "END flush: fh len %d, count %d\n",
card->fh_buffer.ptr - card->fh_buffer.buf,
card->fh_buffer.count);
#endif
return CSR_RESULT_SUCCESS;
}
static void restart_packet_flow(card_t *card)
{
u8 q;
for (q = 0; q <= UNIFI_TRAFFIC_Q_VO; q++)
{
if (card_is_tx_q_paused(card, q) &&
CSR_WIFI_HIP_Q_SLOTS_FREE(&card->fh_traffic_queue[q]) >= RESUME_XMIT_THRESHOLD)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("U");
#endif
card_tx_q_unpause(card, q);
unifi_restart_xmit(card->ospriv, (unifi_TrafficQueue)q);
}
}
}
