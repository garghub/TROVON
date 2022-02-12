void SwLedOn23a(struct rtw_adapter *padapter, struct led_8723a *pLed)
{
u8 LedCfg = 0;
if ((padapter->bSurpriseRemoved == true) || (padapter->bDriverStopped == true))
return;
switch (pLed->LedPin) {
case LED_PIN_GPIO0:
break;
case LED_PIN_LED0:
rtl8723au_write8(padapter, REG_LEDCFG0,
(LedCfg&0xf0)|BIT(5)|BIT(6));
break;
case LED_PIN_LED1:
rtl8723au_write8(padapter, REG_LEDCFG1, (LedCfg&0x00)|BIT(6));
break;
case LED_PIN_LED2:
LedCfg = rtl8723au_read8(padapter, REG_LEDCFG2);
rtl8723au_write8(padapter, REG_LEDCFG2, (LedCfg&0x80)|BIT(5));
break;
default:
break;
}
pLed->bLedOn = true;
}
void SwLedOff23a(struct rtw_adapter *padapter, struct led_8723a *pLed)
{
u8 LedCfg = 0;
if ((padapter->bSurpriseRemoved) || (padapter->bDriverStopped))
goto exit;
switch (pLed->LedPin) {
case LED_PIN_GPIO0:
break;
case LED_PIN_LED0:
rtl8723au_write8(padapter, REG_LEDCFG0,
(LedCfg&0xf0)|BIT(5)|BIT(6));
break;
case LED_PIN_LED1:
rtl8723au_write8(padapter, REG_LEDCFG1,
(LedCfg&0x00)|BIT(5)|BIT(6));
break;
case LED_PIN_LED2:
LedCfg = rtl8723au_read8(padapter, REG_LEDCFG2);
rtl8723au_write8(padapter, REG_LEDCFG2,
(LedCfg&0x80)|BIT(3)|BIT(5));
break;
default:
break;
}
exit:
pLed->bLedOn = false;
}
void
rtl8723au_InitSwLeds(struct rtw_adapter *padapter)
{
struct led_priv *pledpriv = &padapter->ledpriv;
pledpriv->LedControlHandler = LedControl871x23a;
InitLed871x23a(padapter, &pledpriv->SwLed0, LED_PIN_LED2);
}
void
rtl8723au_DeInitSwLeds(struct rtw_adapter *padapter)
{
struct led_priv *ledpriv = &padapter->ledpriv;
DeInitLed871x23a(&ledpriv->SwLed0);
}
