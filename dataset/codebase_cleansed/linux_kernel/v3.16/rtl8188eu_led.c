void SwLedOn(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
return;
LedCfg = rtw_read8(padapter, REG_LEDCFG2);
rtw_write8(padapter, REG_LEDCFG2, (LedCfg&0xf0)|BIT5|BIT6);
pLed->bLedOn = true;
}
void SwLedOff(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
struct hal_data_8188e *pHalData = GET_HAL_DATA(padapter);
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
goto exit;
LedCfg = rtw_read8(padapter, REG_LEDCFG2);
if (pHalData->bLedOpenDrain) {
LedCfg &= 0x90;
rtw_write8(padapter, REG_LEDCFG2, (LedCfg|BIT3));
LedCfg = rtw_read8(padapter, REG_MAC_PINMUX_CFG);
LedCfg &= 0xFE;
rtw_write8(padapter, REG_MAC_PINMUX_CFG, LedCfg);
} else {
rtw_write8(padapter, REG_LEDCFG2, (LedCfg|BIT3|BIT5|BIT6));
}
exit:
pLed->bLedOn = false;
}
void rtl8188eu_InitSwLeds(struct adapter *padapter)
{
struct led_priv *pledpriv = &(padapter->ledpriv);
struct hal_data_8188e *haldata = GET_HAL_DATA(padapter);
pledpriv->bRegUseLed = true;
pledpriv->LedControlHandler = LedControl8188eu;
haldata->bLedOpenDrain = true;
InitLed871x(padapter, &(pledpriv->SwLed0));
}
void rtl8188eu_DeInitSwLeds(struct adapter *padapter)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
DeInitLed871x(&(ledpriv->SwLed0));
}
