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
