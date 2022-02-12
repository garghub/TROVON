void SwLedOn(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
return;
LedCfg = rtw_read8(padapter, REG_LEDCFG2);
switch (pLed->LedPin) {
case LED_PIN_LED0:
rtw_write8(padapter, REG_LEDCFG2, (LedCfg&0xf0)|BIT5|BIT6);
break;
case LED_PIN_LED1:
rtw_write8(padapter, REG_LEDCFG2, (LedCfg&0x0f)|BIT5);
break;
default:
break;
}
pLed->bLedOn = true;
}
void SwLedOff(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
struct hal_data_8188e *pHalData = GET_HAL_DATA(padapter);
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
goto exit;
LedCfg = rtw_read8(padapter, REG_LEDCFG2);
switch (pLed->LedPin) {
case LED_PIN_LED0:
if (pHalData->bLedOpenDrain) {
LedCfg &= 0x90;
rtw_write8(padapter, REG_LEDCFG2, (LedCfg|BIT3));
LedCfg = rtw_read8(padapter, REG_MAC_PINMUX_CFG);
LedCfg &= 0xFE;
rtw_write8(padapter, REG_MAC_PINMUX_CFG, LedCfg);
} else {
rtw_write8(padapter, REG_LEDCFG2, (LedCfg|BIT3|BIT5|BIT6));
}
break;
case LED_PIN_LED1:
LedCfg &= 0x0f;
rtw_write8(padapter, REG_LEDCFG2, (LedCfg|BIT3));
break;
default:
break;
}
exit:
pLed->bLedOn = false;
}
void rtl8188eu_InitSwLeds(struct adapter *padapter)
{
struct led_priv *pledpriv = &(padapter->ledpriv);
pledpriv->LedControlHandler = LedControl8188eu;
InitLed871x(padapter, &(pledpriv->SwLed0), LED_PIN_LED0);
InitLed871x(padapter, &(pledpriv->SwLed1), LED_PIN_LED1);
}
void rtl8188eu_DeInitSwLeds(struct adapter *padapter)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
DeInitLed871x(&(ledpriv->SwLed0));
DeInitLed871x(&(ledpriv->SwLed1));
}
