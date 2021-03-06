void rtw_hal_sreset_init(struct adapter *padapter)
{
struct sreset_priv *psrtpriv = &padapter->HalData->srestpriv;
psrtpriv->Wifi_Error_Status = WIFI_STATUS_SUCCESS;
}
u8 sreset_get_wifi_status(struct adapter *padapter)
{
struct sreset_priv *psrtpriv = &padapter->HalData->srestpriv;
u8 status = WIFI_STATUS_SUCCESS;
u32 val32 = 0;
val32 = usb_read32(padapter, REG_TXDMA_STATUS);
if (val32 == 0xeaeaeaea) {
psrtpriv->Wifi_Error_Status = WIFI_IF_NOT_EXIST;
} else if (val32 != 0) {
DBG_88E("txdmastatu(%x)\n", val32);
psrtpriv->Wifi_Error_Status = WIFI_MAC_TXDMA_ERROR;
}
if (WIFI_STATUS_SUCCESS != psrtpriv->Wifi_Error_Status) {
DBG_88E("==>%s error_status(0x%x)\n", __func__, psrtpriv->Wifi_Error_Status);
status = psrtpriv->Wifi_Error_Status & (~(USB_READ_PORT_FAIL|USB_WRITE_PORT_FAIL));
}
DBG_88E("==> %s wifi_status(0x%x)\n", __func__, status);
psrtpriv->Wifi_Error_Status = WIFI_STATUS_SUCCESS;
return status;
}
void sreset_set_wifi_error_status(struct adapter *padapter, u32 status)
{
padapter->HalData->srestpriv.Wifi_Error_Status = status;
}
