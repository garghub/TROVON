static void InitLed871x(struct _adapter *padapter, struct LED_871x *pLed,
enum LED_PIN_871x LedPin)
{
struct net_device *nic;
nic = padapter->pnetdev;
pLed->padapter = padapter;
pLed->LedPin = LedPin;
pLed->CurrLedState = LED_OFF;
pLed->bLedOn = false;
pLed->bLedBlinkInProgress = false;
pLed->BlinkTimes = 0;
pLed->BlinkingLedState = LED_UNKNOWN;
_init_timer(&(pLed->BlinkTimer), nic, BlinkTimerCallback, pLed);
_init_workitem(&(pLed->BlinkWorkItem), BlinkWorkItemCallback, pLed);
}
static void DeInitLed871x(struct LED_871x *pLed)
{
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
static void SwLedOn(struct _adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if ((padapter->bSurpriseRemoved == true) ||
(padapter->bDriverStopped == true))
return;
LedCfg = r8712_read8(padapter, LEDCFG);
switch (pLed->LedPin) {
case LED_PIN_GPIO0:
break;
case LED_PIN_LED0:
r8712_write8(padapter, LEDCFG, LedCfg&0xf0);
break;
case LED_PIN_LED1:
r8712_write8(padapter, LEDCFG, LedCfg&0x0f);
break;
default:
break;
}
pLed->bLedOn = true;
}
static void SwLedOff(struct _adapter *padapter, struct LED_871x *pLed)
{
u8 LedCfg;
if ((padapter->bSurpriseRemoved == true) ||
(padapter->bDriverStopped == true))
return;
LedCfg = r8712_read8(padapter, LEDCFG);
switch (pLed->LedPin) {
case LED_PIN_GPIO0:
break;
case LED_PIN_LED0:
LedCfg &= 0xf0;
r8712_write8(padapter, LEDCFG, (LedCfg|BIT(3)));
break;
case LED_PIN_LED1:
LedCfg &= 0x0f;
r8712_write8(padapter, LEDCFG, (LedCfg|BIT(7)));
break;
default:
break;
}
pLed->bLedOn = false;
}
void r8712_InitSwLeds(struct _adapter *padapter)
{
struct led_priv *pledpriv = &(padapter->ledpriv);
pledpriv->LedControlHandler = LedControl871x;
InitLed871x(padapter, &(pledpriv->SwLed0), LED_PIN_LED0);
InitLed871x(padapter, &(pledpriv->SwLed1), LED_PIN_LED1);
}
void r8712_DeInitSwLeds(struct _adapter *padapter)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
DeInitLed871x(&(ledpriv->SwLed0));
DeInitLed871x(&(ledpriv->SwLed1));
}
static void SwLedBlink(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
pLed->BlinkTimes--;
switch (pLed->CurrLedState) {
case LED_BLINK_NORMAL:
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
break;
case LED_BLINK_StartToBlink:
if ((check_fwstate(pmlmepriv, _FW_LINKED) == true) &&
(pmlmepriv->fw_state & WIFI_STATION_STATE))
bStopBlinking = true;
if ((check_fwstate(pmlmepriv, _FW_LINKED) == true) &&
((pmlmepriv->fw_state & WIFI_ADHOC_STATE) ||
(pmlmepriv->fw_state & WIFI_ADHOC_MASTER_STATE)))
bStopBlinking = true;
else if (pLed->BlinkTimes == 0)
bStopBlinking = true;
break;
case LED_BLINK_WPS:
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
break;
default:
bStopBlinking = true;
break;
}
if (bStopBlinking) {
if ((check_fwstate(pmlmepriv, _FW_LINKED) == true) &&
(pLed->bLedOn == false))
SwLedOn(padapter, pLed);
else if ((check_fwstate(pmlmepriv, _FW_LINKED) ==
true) && pLed->bLedOn == true)
SwLedOff(padapter, pLed);
pLed->BlinkTimes = 0;
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->BlinkingLedState == LED_ON)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
switch (pLed->CurrLedState) {
case LED_BLINK_NORMAL:
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
break;
case LED_BLINK_SLOWLY:
case LED_BLINK_StartToBlink:
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
break;
case LED_BLINK_WPS:
if (pLed->BlinkingLedState == LED_ON)
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LONG_INTERVAL);
else
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LONG_INTERVAL);
break;
default:
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
break;
}
}
}
static void SwLedBlink1(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
struct eeprom_priv *peeprompriv = &(padapter->eeprompriv);
struct LED_871x *pLed1 = &(ledpriv->SwLed1);
u8 bStopBlinking = false;
if (peeprompriv->CustomerID == RT_CID_819x_CAMEO)
pLed = &(ledpriv->SwLed1);
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
if (peeprompriv->CustomerID == RT_CID_DEFAULT) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
if (!pLed1->bSWLedCtrl) {
SwLedOn(padapter, pLed1);
pLed1->bSWLedCtrl = true;
} else if (!pLed1->bLedOn)
SwLedOn(padapter, pLed1);
} else {
if (!pLed1->bSWLedCtrl) {
SwLedOff(padapter, pLed1);
pLed1->bSWLedCtrl = true;
} else if (pLed1->bLedOn)
SwLedOff(padapter, pLed1);
}
}
switch (pLed->CurrLedState) {
case LED_BLINK_SLOWLY:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
break;
case LED_BLINK_NORMAL:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
break;
case LED_SCAN_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->bLedLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_NORMAL;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
}
pLed->bLedScanBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->bLedLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_NORMAL;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
}
pLed->BlinkTimes = 0;
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_BLINK_WPS:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
break;
case LED_BLINK_WPS_STOP:
if (pLed->BlinkingLedState == LED_ON) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_WPS_SUCESS_INTERVAL_ALPHA);
bStopBlinking = false;
} else
bStopBlinking = true;
if (bStopBlinking) {
pLed->bLedLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_NORMAL;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
}
pLed->bLedWPSBlinkInProgress = false;
break;
default:
break;
}
}
static void SwLedBlink2(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
switch (pLed->CurrLedState) {
case LED_SCAN_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
SwLedOn(padapter, pLed);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
SwLedOff(padapter, pLed);
}
pLed->bLedScanBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
SwLedOn(padapter, pLed);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
SwLedOff(padapter, pLed);
}
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
default:
break;
}
}
static void SwLedBlink3(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
if (pLed->CurrLedState != LED_BLINK_WPS_STOP)
SwLedOff(padapter, pLed);
switch (pLed->CurrLedState) {
case LED_SCAN_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (!pLed->bLedOn)
SwLedOn(padapter, pLed);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedOn)
SwLedOff(padapter, pLed);
}
pLed->bLedScanBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
if (check_fwstate(pmlmepriv, _FW_LINKED) == true) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (!pLed->bLedOn)
SwLedOn(padapter, pLed);
} else if (!check_fwstate(pmlmepriv, _FW_LINKED)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedOn)
SwLedOff(padapter, pLed);
}
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_BLINK_WPS:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
break;
case LED_BLINK_WPS_STOP:
if (pLed->BlinkingLedState == LED_ON) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_WPS_SUCESS_INTERVAL_ALPHA);
bStopBlinking = false;
} else
bStopBlinking = true;
if (bStopBlinking) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
SwLedOn(padapter, pLed);
pLed->bLedWPSBlinkInProgress = false;
}
break;
default:
break;
}
}
static void SwLedBlink4(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
struct led_priv *ledpriv = &(padapter->ledpriv);
struct LED_871x *pLed1 = &(ledpriv->SwLed1);
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
if (!pLed1->bLedWPSBlinkInProgress &&
pLed1->BlinkingLedState == LED_UNKNOWN) {
pLed1->BlinkingLedState = LED_OFF;
pLed1->CurrLedState = LED_OFF;
SwLedOff(padapter, pLed1);
}
switch (pLed->CurrLedState) {
case LED_BLINK_SLOWLY:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
break;
case LED_BLINK_StartToBlink:
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
}
break;
case LED_SCAN_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
pLed->bLedScanBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_BLINK_WPS:
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
}
break;
case LED_BLINK_WPS_STOP:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), LED_BLINK_NORMAL_INTERVAL);
break;
case LED_BLINK_WPS_STOP_OVERLAP:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0) {
if (pLed->bLedOn)
pLed->BlinkTimes = 1;
else
bStopBlinking = true;
}
if (bStopBlinking) {
pLed->BlinkTimes = 10;
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
}
break;
default:
break;
}
}
static void SwLedBlink5(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
switch (pLed->CurrLedState) {
case LED_SCAN_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (!pLed->bLedOn)
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
pLed->bLedScanBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (!pLed->bLedOn)
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
default:
break;
}
}
static void SwLedBlink6(struct LED_871x *pLed)
{
struct _adapter *padapter = pLed->padapter;
u8 bStopBlinking = false;
if (pLed->BlinkingLedState == LED_ON)
SwLedOn(padapter, pLed);
else
SwLedOff(padapter, pLed);
switch (pLed->CurrLedState) {
case LED_TXRX_BLINK:
pLed->BlinkTimes--;
if (pLed->BlinkTimes == 0)
bStopBlinking = true;
if (bStopBlinking) {
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (!pLed->bLedOn)
SwLedOn(padapter, pLed);
pLed->bLedBlinkInProgress = false;
} else {
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_BLINK_WPS:
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), LED_BLINK_SCAN_INTERVAL_ALPHA);
break;
default:
break;
}
}
static void BlinkTimerCallback(unsigned long data)
{
struct LED_871x *pLed = (struct LED_871x *)data;
if ((pLed->padapter->bSurpriseRemoved == true) ||
(pLed->padapter->bDriverStopped == true))
return;
_set_workitem(&(pLed->BlinkWorkItem));
}
static void BlinkWorkItemCallback(struct work_struct *work)
{
struct LED_871x *pLed = container_of(work, struct LED_871x,
BlinkWorkItem);
struct led_priv *ledpriv = &(pLed->padapter->ledpriv);
switch (ledpriv->LedStrategy) {
case SW_LED_MODE0:
SwLedBlink(pLed);
break;
case SW_LED_MODE1:
SwLedBlink1(pLed);
break;
case SW_LED_MODE2:
SwLedBlink2(pLed);
break;
case SW_LED_MODE3:
SwLedBlink3(pLed);
break;
case SW_LED_MODE4:
SwLedBlink4(pLed);
break;
case SW_LED_MODE5:
SwLedBlink5(pLed);
break;
case SW_LED_MODE6:
SwLedBlink6(pLed);
break;
default:
SwLedBlink(pLed);
break;
}
}
static void SwLedControlMode1(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct LED_871x *pLed = &(ledpriv->SwLed0);
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
struct sitesurvey_ctrl *psitesurveyctrl = &(pmlmepriv->sitesurveyctrl);
if (padapter->eeprompriv.CustomerID == RT_CID_819x_CAMEO)
pLed = &(ledpriv->SwLed1);
switch (LedAction) {
case LED_CTL_START_TO_LINK:
case LED_CTL_NO_LINK:
if (pLed->bLedNoLinkBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
}
break;
case LED_CTL_LINK:
if (pLed->bLedLinkBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_NORMAL;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_LINK_INTERVAL_ALPHA);
}
break;
case LED_CTL_SITE_SURVEY:
if ((psitesurveyctrl->traffic_busy) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true))
;
else if (pLed->bLedScanBlinkInProgress == false) {
if (IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedScanBlinkInProgress = true;
pLed->CurrLedState = LED_SCAN_BLINK;
pLed->BlinkTimes = 24;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_TX:
case LED_CTL_RX:
if (pLed->bLedBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_START_WPS:
case LED_CTL_START_WPS_BOTTON:
if (pLed->bLedWPSBlinkInProgress == false) {
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_STOP_WPS:
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress)
_cancel_timer_ex(&(pLed->BlinkTimer));
else
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS_STOP;
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_WPS_SUCESS_INTERVAL_ALPHA);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), 0);
}
break;
case LED_CTL_STOP_WPS_FAIL:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedNoLinkBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
_set_timer(&(pLed->BlinkTimer), 0);
break;
default:
break;
}
}
static void SwLedControlMode2(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct LED_871x *pLed = &(ledpriv->SwLed0);
switch (LedAction) {
case LED_CTL_SITE_SURVEY:
if (pmlmepriv->sitesurveyctrl.traffic_busy)
;
else if (pLed->bLedScanBlinkInProgress == false) {
if (IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedScanBlinkInProgress = true;
pLed->CurrLedState = LED_SCAN_BLINK;
pLed->BlinkTimes = 24;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_TX:
case LED_CTL_RX:
if ((pLed->bLedBlinkInProgress == false) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true)) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_LINK:
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_START_WPS:
case LED_CTL_START_WPS_BOTTON:
if (pLed->bLedWPSBlinkInProgress == false) {
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), 0);
}
break;
case LED_CTL_STOP_WPS:
pLed->bLedWPSBlinkInProgress = false;
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_STOP_WPS_FAIL:
pLed->bLedWPSBlinkInProgress = false;
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_START_TO_LINK:
case LED_CTL_NO_LINK:
if (!IS_LED_BLINKING(pLed)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer), 0);
}
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
_set_timer(&(pLed->BlinkTimer), 0);
break;
default:
break;
}
}
static void SwLedControlMode3(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct LED_871x *pLed = &(ledpriv->SwLed0);
switch (LedAction) {
case LED_CTL_SITE_SURVEY:
if (pmlmepriv->sitesurveyctrl.traffic_busy)
;
else if (pLed->bLedScanBlinkInProgress == false) {
if (IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedScanBlinkInProgress = true;
pLed->CurrLedState = LED_SCAN_BLINK;
pLed->BlinkTimes = 24;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_TX:
case LED_CTL_RX:
if ((pLed->bLedBlinkInProgress == false) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true)) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_LINK:
if (IS_LED_WPS_BLINKING(pLed))
return;
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_START_WPS:
case LED_CTL_START_WPS_BOTTON:
if (pLed->bLedWPSBlinkInProgress == false) {
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_STOP_WPS:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
} else
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS_STOP;
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_WPS_SUCESS_INTERVAL_ALPHA);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), 0);
}
break;
case LED_CTL_STOP_WPS_FAIL:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_START_TO_LINK:
case LED_CTL_NO_LINK:
if (!IS_LED_BLINKING(pLed)) {
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer), 0);
}
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
_set_timer(&(pLed->BlinkTimer), 0);
break;
default:
break;
}
}
static void SwLedControlMode4(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct LED_871x *pLed = &(ledpriv->SwLed0);
struct LED_871x *pLed1 = &(ledpriv->SwLed1);
switch (LedAction) {
case LED_CTL_START_TO_LINK:
if (pLed1->bLedWPSBlinkInProgress) {
pLed1->bLedWPSBlinkInProgress = false;
_cancel_timer_ex(&(pLed1->BlinkTimer));
pLed1->BlinkingLedState = LED_OFF;
pLed1->CurrLedState = LED_OFF;
if (pLed1->bLedOn)
_set_timer(&(pLed->BlinkTimer), 0);
}
if (pLed->bLedStartToLinkBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
pLed->bLedStartToLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_StartToBlink;
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
}
}
break;
case LED_CTL_LINK:
case LED_CTL_NO_LINK:
if (LedAction == LED_CTL_LINK) {
if (pLed1->bLedWPSBlinkInProgress) {
pLed1->bLedWPSBlinkInProgress = false;
_cancel_timer_ex(&(pLed1->BlinkTimer));
pLed1->BlinkingLedState = LED_OFF;
pLed1->CurrLedState = LED_OFF;
if (pLed1->bLedOn)
_set_timer(&(pLed->BlinkTimer), 0);
}
}
if (pLed->bLedNoLinkBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
}
break;
case LED_CTL_SITE_SURVEY:
if ((pmlmepriv->sitesurveyctrl.traffic_busy) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true))
;
else if (pLed->bLedScanBlinkInProgress == false) {
if (IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedScanBlinkInProgress = true;
pLed->CurrLedState = LED_SCAN_BLINK;
pLed->BlinkTimes = 24;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_TX:
case LED_CTL_RX:
if (pLed->bLedBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK ||
IS_LED_WPS_BLINKING(pLed))
return;
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_START_WPS:
case LED_CTL_START_WPS_BOTTON:
if (pLed1->bLedWPSBlinkInProgress) {
pLed1->bLedWPSBlinkInProgress = false;
_cancel_timer_ex(&(pLed1->BlinkTimer));
pLed1->BlinkingLedState = LED_OFF;
pLed1->CurrLedState = LED_OFF;
if (pLed1->bLedOn)
_set_timer(&(pLed->BlinkTimer), 0);
}
if (pLed->bLedWPSBlinkInProgress == false) {
if (pLed->bLedNoLinkBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS;
if (pLed->bLedOn) {
pLed->BlinkingLedState = LED_OFF;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SLOWLY_INTERVAL);
} else {
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NORMAL_INTERVAL);
}
}
break;
case LED_CTL_STOP_WPS:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
break;
case LED_CTL_STOP_WPS_FAIL:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
if (pLed1->bLedWPSBlinkInProgress)
_cancel_timer_ex(&(pLed1->BlinkTimer));
else
pLed1->bLedWPSBlinkInProgress = true;
pLed1->CurrLedState = LED_BLINK_WPS_STOP;
if (pLed1->bLedOn)
pLed1->BlinkingLedState = LED_OFF;
else
pLed1->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), LED_BLINK_NORMAL_INTERVAL);
break;
case LED_CTL_STOP_WPS_FAIL_OVERLAP:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->bLedNoLinkBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_SLOWLY;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_NO_LINK_INTERVAL_ALPHA);
if (pLed1->bLedWPSBlinkInProgress)
_cancel_timer_ex(&(pLed1->BlinkTimer));
else
pLed1->bLedWPSBlinkInProgress = true;
pLed1->CurrLedState = LED_BLINK_WPS_STOP_OVERLAP;
pLed1->BlinkTimes = 10;
if (pLed1->bLedOn)
pLed1->BlinkingLedState = LED_OFF;
else
pLed1->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), LED_BLINK_NORMAL_INTERVAL);
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedNoLinkBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedNoLinkBlinkInProgress = false;
}
if (pLed->bLedLinkBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedLinkBlinkInProgress = false;
}
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
if (pLed->bLedScanBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedScanBlinkInProgress = false;
}
if (pLed->bLedStartToLinkBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedStartToLinkBlinkInProgress = false;
}
if (pLed1->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed1->BlinkTimer));
pLed1->bLedWPSBlinkInProgress = false;
}
pLed1->BlinkingLedState = LED_UNKNOWN;
SwLedOff(padapter, pLed);
SwLedOff(padapter, pLed1);
break;
default:
break;
}
}
static void SwLedControlMode5(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct LED_871x *pLed = &(ledpriv->SwLed0);
if (padapter->eeprompriv.CustomerID == RT_CID_819x_CAMEO)
pLed = &(ledpriv->SwLed1);
switch (LedAction) {
case LED_CTL_POWER_ON:
case LED_CTL_NO_LINK:
case LED_CTL_LINK:
if (pLed->CurrLedState == LED_SCAN_BLINK)
return;
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
pLed->bLedBlinkInProgress = false;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_SITE_SURVEY:
if ((pmlmepriv->sitesurveyctrl.traffic_busy) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true))
;
else if (pLed->bLedScanBlinkInProgress == false) {
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedScanBlinkInProgress = true;
pLed->CurrLedState = LED_SCAN_BLINK;
pLed->BlinkTimes = 24;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_TX:
case LED_CTL_RX:
if (pLed->bLedBlinkInProgress == false) {
if (pLed->CurrLedState == LED_SCAN_BLINK)
return;
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
SwLedOff(padapter, pLed);
break;
default:
break;
}
}
static void SwLedControlMode6(struct _adapter *padapter,
enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct LED_871x *pLed = &(ledpriv->SwLed0);
switch (LedAction) {
case LED_CTL_POWER_ON:
case LED_CTL_NO_LINK:
case LED_CTL_LINK:
case LED_CTL_SITE_SURVEY:
if (IS_LED_WPS_BLINKING(pLed))
return;
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
pLed->bLedBlinkInProgress = false;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_TX:
case LED_CTL_RX:
if (pLed->bLedBlinkInProgress == false &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true)) {
if (IS_LED_WPS_BLINKING(pLed))
return;
pLed->bLedBlinkInProgress = true;
pLed->CurrLedState = LED_TXRX_BLINK;
pLed->BlinkTimes = 2;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_FASTER_INTERVAL_ALPHA);
}
break;
case LED_CTL_START_WPS:
case LED_CTL_START_WPS_BOTTON:
if (pLed->bLedWPSBlinkInProgress == false) {
if (pLed->bLedBlinkInProgress == true) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
pLed->bLedWPSBlinkInProgress = true;
pLed->CurrLedState = LED_BLINK_WPS;
if (pLed->bLedOn)
pLed->BlinkingLedState = LED_OFF;
else
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer),
LED_BLINK_SCAN_INTERVAL_ALPHA);
}
break;
case LED_CTL_STOP_WPS_FAIL:
case LED_CTL_STOP_WPS:
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
pLed->CurrLedState = LED_ON;
pLed->BlinkingLedState = LED_ON;
_set_timer(&(pLed->BlinkTimer), 0);
break;
case LED_CTL_POWER_OFF:
pLed->CurrLedState = LED_OFF;
pLed->BlinkingLedState = LED_OFF;
if (pLed->bLedBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedBlinkInProgress = false;
}
if (pLed->bLedWPSBlinkInProgress) {
_cancel_timer_ex(&(pLed->BlinkTimer));
pLed->bLedWPSBlinkInProgress = false;
}
SwLedOff(padapter, pLed);
break;
default:
break;
}
}
void LedControl871x(struct _adapter *padapter, enum LED_CTL_MODE LedAction)
{
struct led_priv *ledpriv = &(padapter->ledpriv);
if (ledpriv->bRegUseLed == false)
return;
switch (ledpriv->LedStrategy) {
case SW_LED_MODE0:
break;
case SW_LED_MODE1:
SwLedControlMode1(padapter, LedAction);
break;
case SW_LED_MODE2:
SwLedControlMode2(padapter, LedAction);
break;
case SW_LED_MODE3:
SwLedControlMode3(padapter, LedAction);
break;
case SW_LED_MODE4:
SwLedControlMode4(padapter, LedAction);
break;
case SW_LED_MODE5:
SwLedControlMode5(padapter, LedAction);
break;
case SW_LED_MODE6:
SwLedControlMode6(padapter, LedAction);
break;
default:
break;
}
}
