void rtl8723a_sreset_xmit_status_check(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct sreset_priv *psrtpriv = &pHalData->srestpriv;
unsigned long current_time;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
unsigned int diff_time;
u32 txdma_status;
txdma_status = rtw_read32(padapter, REG_TXDMA_STATUS);
if (txdma_status != 0) {
DBG_8723A("%s REG_TXDMA_STATUS:0x%08x\n", __func__, txdma_status);
rtw_hal_sreset_reset23a(padapter);
}
current_time = jiffies;
if (0 == pxmitpriv->free_xmitbuf_cnt || 0 == pxmitpriv->free_xmit_extbuf_cnt) {
diff_time = jiffies_to_msecs(jiffies - psrtpriv->last_tx_time);
if (diff_time > 2000) {
if (psrtpriv->last_tx_complete_time == 0) {
psrtpriv->last_tx_complete_time = current_time;
} else {
diff_time = jiffies_to_msecs(jiffies - psrtpriv->last_tx_complete_time);
if (diff_time > 4000) {
DBG_8723A("%s tx hang\n", __func__);
rtw_hal_sreset_reset23a(padapter);
}
}
}
}
if (psrtpriv->dbg_trigger_point == SRESET_TGP_XMIT_STATUS) {
psrtpriv->dbg_trigger_point = SRESET_TGP_NULL;
rtw_hal_sreset_reset23a(padapter);
return;
}
}
void rtl8723a_sreset_linked_status_check(struct rtw_adapter *padapter)
{
struct hal_data_8723a *pHalData = GET_HAL_DATA(padapter);
struct sreset_priv *psrtpriv = &pHalData->srestpriv;
if (psrtpriv->dbg_trigger_point == SRESET_TGP_LINK_STATUS) {
psrtpriv->dbg_trigger_point = SRESET_TGP_NULL;
rtw_hal_sreset_reset23a(padapter);
return;
}
}
