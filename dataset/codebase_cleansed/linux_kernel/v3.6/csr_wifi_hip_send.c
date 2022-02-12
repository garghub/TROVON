unifi_TrafficQueue unifi_frame_priority_to_queue(CSR_PRIORITY priority)
{
switch (priority)
{
case CSR_QOS_UP0:
case CSR_QOS_UP3:
return UNIFI_TRAFFIC_Q_BE;
case CSR_QOS_UP1:
case CSR_QOS_UP2:
return UNIFI_TRAFFIC_Q_BK;
case CSR_QOS_UP4:
case CSR_QOS_UP5:
return UNIFI_TRAFFIC_Q_VI;
case CSR_QOS_UP6:
case CSR_QOS_UP7:
case CSR_MANAGEMENT:
return UNIFI_TRAFFIC_Q_VO;
default:
return UNIFI_TRAFFIC_Q_BE;
}
}
CSR_PRIORITY unifi_get_default_downgrade_priority(unifi_TrafficQueue queue)
{
switch (queue)
{
case UNIFI_TRAFFIC_Q_BE:
return CSR_QOS_UP0;
case UNIFI_TRAFFIC_Q_BK:
return CSR_QOS_UP1;
case UNIFI_TRAFFIC_Q_VI:
return CSR_QOS_UP5;
case UNIFI_TRAFFIC_Q_VO:
return CSR_QOS_UP6;
default:
return CSR_QOS_UP0;
}
}
static CsrResult send_signal(card_t *card, const u8 *sigptr, u32 siglen,
const bulk_data_param_t *bulkdata,
q_t *sigq, u32 priority_q, u32 run_bh)
{
u16 i, data_slot_size;
card_signal_t *csptr;
s16 qe;
CsrResult r;
s16 debug_print = 0;
data_slot_size = CardGetDataSlotSize(card);
if (!CSR_WIFI_HIP_Q_SLOTS_FREE(sigq))
{
unifi_trace(card->ospriv, UDBG3, "send_signal: %s full\n", sigq->name);
return CSR_WIFI_HIP_RESULT_NO_SPACE;
}
qe = CSR_WIFI_HIP_Q_NEXT_W_SLOT(sigq);
csptr = CSR_WIFI_HIP_Q_SLOT_DATA(sigq, qe);
csptr->signal_length = (u16)siglen;
memcpy((void *)csptr->sigbuf, (void *)sigptr, siglen);
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; ++i)
{
if ((bulkdata != NULL) && (bulkdata->d[i].data_length != 0))
{
u32 datalen = bulkdata->d[i].data_length;
if (bulkdata->d[i].os_data_ptr == NULL)
{
unifi_error(card->ospriv, "send_signal - NULL bulkdata[%d]\n", i);
debug_print++;
csptr->bulkdata[i].data_length = 0;
}
else
{
if (datalen > data_slot_size)
{
unifi_error(card->ospriv,
"send_signal - Invalid data length %u (@%p), "
"truncating\n",
datalen, bulkdata->d[i].os_data_ptr);
datalen = data_slot_size;
debug_print++;
}
csptr->bulkdata[i].os_data_ptr = (u8 *)bulkdata->d[i].os_data_ptr;
csptr->bulkdata[i].os_net_buf_ptr = (u8 *)bulkdata->d[i].os_net_buf_ptr;
csptr->bulkdata[i].net_buf_length = bulkdata->d[i].net_buf_length;
csptr->bulkdata[i].data_length = datalen;
}
}
else
{
UNIFI_INIT_BULK_DATA(&csptr->bulkdata[i]);
}
}
if (debug_print)
{
const u8 *sig = sigptr;
unifi_error(card->ospriv, "Signal(%d): %02x %02x %02x %02x %02x %02x %02x %02x"
" %02x %02x %02x %02x %02x %02x %02x %02x\n",
siglen,
sig[0], sig[1], sig[2], sig[3],
sig[4], sig[5], sig[6], sig[7],
sig[8], sig[9], sig[10], sig[11],
sig[12], sig[13], sig[14], sig[15]);
unifi_error(card->ospriv, "Bulkdata pointer %p(%d), %p(%d)\n",
bulkdata != NULL?bulkdata->d[0].os_data_ptr : NULL,
bulkdata != NULL?bulkdata->d[0].data_length : 0,
bulkdata != NULL?bulkdata->d[1].os_data_ptr : NULL,
bulkdata != NULL?bulkdata->d[1].data_length : 0);
}
CSR_WIFI_HIP_Q_INC_W(sigq);
if (run_bh == 1)
{
card->bh_reason_host = 1;
r = unifi_run_bh(card->ospriv);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "failed to run bh.\n");
card->bh_reason_host = 0;
for (i = 0; i < UNIFI_MAX_DATA_REFERENCES; ++i)
{
if (csptr->bulkdata[i].data_length != 0)
{
csptr->bulkdata[i].os_data_ptr = csptr->bulkdata[i].os_net_buf_ptr = NULL;
csptr->bulkdata[i].net_buf_length = csptr->bulkdata[i].data_length = 0;
}
}
return r;
}
}
else
{
unifi_error(card->ospriv, "run_bh=%d, bh not called.\n", run_bh);
}
if (CSR_WIFI_HIP_Q_SLOTS_FREE(sigq) == 0)
{
if (sigq != &card->fh_command_queue)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("P");
#endif
unifi_pause_xmit(card->ospriv, (unifi_TrafficQueue)priority_q);
card_tx_q_pause(card, priority_q);
if (CSR_WIFI_HIP_Q_SLOTS_USED(sigq) == 0)
{
card_tx_q_unpause(card, priority_q);
unifi_restart_xmit(card->ospriv, (unifi_TrafficQueue) priority_q);
}
}
else
{
unifi_warning(card->ospriv,
"send_signal: fh_cmd_q full, not pausing (run_bh=%d)\n",
run_bh);
}
}
func_exit();
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_send_signal(card_t *card, const u8 *sigptr, u32 siglen,
const bulk_data_param_t *bulkdata)
{
q_t *sig_soft_q;
u16 signal_id;
CsrResult r;
u32 run_bh;
u32 priority_q;
if (sigptr == NULL)
{
card->bh_reason_host = 1;
return unifi_run_bh(card->ospriv);
}
priority_q = 0;
run_bh = 1;
signal_id = GET_SIGNAL_ID(sigptr);
if (signal_id == CSR_MA_PACKET_REQUEST_ID)
{
u16 frame_priority;
if (card->periodic_wake_mode == UNIFI_PERIODIC_WAKE_HOST_ENABLED)
{
run_bh = 0;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("D");
#endif
if ((bulkdata->d[0].data_length == 0) || (bulkdata->d[0].os_data_ptr == NULL))
{
unifi_error(card->ospriv, "MA-PACKET.req with empty bulk data (%d bytes in %p)\n",
bulkdata->d[0].data_length, bulkdata->d[0].os_data_ptr);
dump((void *)sigptr, siglen);
return CSR_RESULT_FAILURE;
}
frame_priority = GET_PACKED_MA_PACKET_REQUEST_FRAME_PRIORITY(sigptr);
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY)frame_priority);
sig_soft_q = &card->fh_traffic_queue[priority_q];
}
else
{
sig_soft_q = &card->fh_command_queue;
}
r = send_signal(card, sigptr, siglen, bulkdata, sig_soft_q, priority_q, run_bh);
return r;
}
CsrResult unifi_send_resources_available(card_t *card, const u8 *sigptr)
{
q_t *sig_soft_q;
u16 signal_id = GET_SIGNAL_ID(sigptr);
if (signal_id == CSR_MA_PACKET_REQUEST_ID)
{
u16 frame_priority;
u32 priority_q;
frame_priority = GET_PACKED_MA_PACKET_REQUEST_FRAME_PRIORITY(sigptr);
priority_q = unifi_frame_priority_to_queue((CSR_PRIORITY)frame_priority);
sig_soft_q = &card->fh_traffic_queue[priority_q];
}
else
{
sig_soft_q = &card->fh_command_queue;
}
if (!CSR_WIFI_HIP_Q_SLOTS_FREE(sig_soft_q))
{
unifi_notice(card->ospriv, "unifi_send_resources_available: %s full\n",
sig_soft_q->name);
return CSR_WIFI_HIP_RESULT_NO_SPACE;
}
return CSR_RESULT_SUCCESS;
}
