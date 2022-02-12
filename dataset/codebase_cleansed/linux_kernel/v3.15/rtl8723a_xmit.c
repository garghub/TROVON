void dump_txrpt_ccx_8723a(void *buf)
{
struct txrpt_ccx_8723a *txrpt_ccx = buf;
DBG_8723A("%s:\n"
"tag1:%u, rsvd:%u, int_bt:%u, int_tri:%u, int_ccx:%u\n"
"mac_id:%u, pkt_drop:%u, pkt_ok:%u, bmc:%u\n"
"retry_cnt:%u, lifetime_over:%u, retry_over:%u\n"
"ccx_qtime:%u\n"
"final_data_rate:0x%02x\n"
"qsel:%u, sw:0x%03x\n"
, __func__
, txrpt_ccx->tag1, txrpt_ccx->rsvd, txrpt_ccx->int_bt, txrpt_ccx->int_tri, txrpt_ccx->int_ccx
, txrpt_ccx->mac_id, txrpt_ccx->pkt_drop, txrpt_ccx->pkt_ok, txrpt_ccx->bmc
, txrpt_ccx->retry_cnt, txrpt_ccx->lifetime_over, txrpt_ccx->retry_over
, txrpt_ccx_qtime_8723a(txrpt_ccx)
, txrpt_ccx->final_data_rate
, txrpt_ccx->qsel, txrpt_ccx_sw_8723a(txrpt_ccx)
);
}
void handle_txrpt_ccx_8723a(struct rtw_adapter *adapter, void *buf)
{
struct txrpt_ccx_8723a *txrpt_ccx = buf;
if (txrpt_ccx->int_ccx) {
if (txrpt_ccx->pkt_ok)
rtw_ack_tx_done23a(&adapter->xmitpriv, RTW_SCTX_DONE_SUCCESS);
else
rtw_ack_tx_done23a(&adapter->xmitpriv, RTW_SCTX_DONE_CCX_PKT_FAIL);
}
}
