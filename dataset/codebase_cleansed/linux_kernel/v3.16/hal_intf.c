void rtw_hal_update_ra_mask23a(struct sta_info *psta, u8 rssi_level)
{
struct rtw_adapter *padapter;
struct mlme_priv *pmlmepriv;
if (!psta)
return;
padapter = psta->padapter;
pmlmepriv = &padapter->mlmepriv;
if (check_fwstate(pmlmepriv, WIFI_AP_STATE)) {
#ifdef CONFIG_8723AU_AP_MODE
add_RATid23a(padapter, psta, rssi_level);
#endif
} else
rtl8723a_update_ramask(padapter, psta->mac_id, rssi_level);
}
