void SwLedOn(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
return;
LedCfg = usb_read8(padapter, REG_LEDCFG2);
usb_write8(padapter, REG_LEDCFG2, (LedCfg&0xf0) | BIT(5) | BIT(6));
pLed->bLedOn = true;
}
void SwLedOff(struct adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if (padapter->bSurpriseRemoved || padapter->bDriverStopped)
goto exit;
LedCfg = usb_read8(padapter, REG_LEDCFG2);
LedCfg &= 0x90;
usb_write8(padapter, REG_LEDCFG2, (LedCfg | BIT(3)));
LedCfg = usb_read8(padapter, REG_MAC_PINMUX_CFG);
LedCfg &= 0xFE;
usb_write8(padapter, REG_MAC_PINMUX_CFG, LedCfg);
exit:
pLed->bLedOn = false;
}
void rtw_hal_sw_led_init(struct adapter *padapter)
{
struct led_priv *pledpriv = &(padapter->ledpriv);
InitLed871x(padapter, &(pledpriv->SwLed0));
}
void rtw_hal_sw_led_deinit(struct adapter *padapter)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
DeInitLed871x(&(ledpriv->SwLed0));
}
