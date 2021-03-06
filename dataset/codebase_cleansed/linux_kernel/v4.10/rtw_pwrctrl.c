static int rtw_hw_suspend(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct net_device *pnetdev = padapter->pnetdev;
if ((!padapter->bup) || (padapter->bDriverStopped) ||
(padapter->bSurpriseRemoved)) {
DBG_88E("padapter->bup=%d bDriverStopped=%d bSurpriseRemoved = %d\n",
padapter->bup, padapter->bDriverStopped,
padapter->bSurpriseRemoved);
goto error_exit;
}
LeaveAllPowerSaveMode(padapter);
DBG_88E("==> rtw_hw_suspend\n");
mutex_lock(&pwrpriv->mutex_lock);
pwrpriv->bips_processing = true;
if (pnetdev) {
netif_carrier_off(pnetdev);
netif_tx_stop_all_queues(pnetdev);
}
rtw_disassoc_cmd(padapter, 500, false);
{
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
if (check_fwstate(pmlmepriv, _FW_LINKED)) {
_clr_fwstate_(pmlmepriv, _FW_LINKED);
LedControl8188eu(padapter, LED_CTL_NO_LINK);
rtw_os_indicate_disconnect(padapter);
rtw_lps_ctrl_wk_cmd(padapter, LPS_CTRL_DISCONNECT, 0);
}
}
rtw_free_assoc_resources(padapter);
rtw_free_network_queue(padapter, true);
rtw_ips_dev_unload(padapter);
pwrpriv->rf_pwrstate = rf_off;
pwrpriv->bips_processing = false;
mutex_unlock(&pwrpriv->mutex_lock);
return 0;
error_exit:
DBG_88E("%s, failed\n", __func__);
return -1;
}
static int rtw_hw_resume(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct net_device *pnetdev = padapter->pnetdev;
DBG_88E("==> rtw_hw_resume\n");
mutex_lock(&pwrpriv->mutex_lock);
pwrpriv->bips_processing = true;
rtw_reset_drv_sw(padapter);
if (ips_netdrv_open((struct adapter *)rtw_netdev_priv(pnetdev)) != _SUCCESS) {
mutex_unlock(&pwrpriv->mutex_lock);
goto error_exit;
}
netif_device_attach(pnetdev);
netif_carrier_on(pnetdev);
if (!netif_queue_stopped(pnetdev))
netif_start_queue(pnetdev);
else
netif_wake_queue(pnetdev);
pwrpriv->bkeepfwalive = false;
pwrpriv->brfoffbyhw = false;
pwrpriv->rf_pwrstate = rf_on;
pwrpriv->bips_processing = false;
mutex_unlock(&pwrpriv->mutex_lock);
return 0;
error_exit:
DBG_88E("%s, Open net dev failed\n", __func__);
return -1;
}
void ips_enter(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct xmit_priv *pxmit_priv = &padapter->xmitpriv;
if (padapter->registrypriv.mp_mode == 1)
return;
if (pxmit_priv->free_xmitbuf_cnt != NR_XMITBUFF ||
pxmit_priv->free_xmit_extbuf_cnt != NR_XMIT_EXTBUFF) {
DBG_88E_LEVEL(_drv_info_, "There are some pkts to transmit\n");
DBG_88E_LEVEL(_drv_info_, "free_xmitbuf_cnt: %d, free_xmit_extbuf_cnt: %d\n",
pxmit_priv->free_xmitbuf_cnt, pxmit_priv->free_xmit_extbuf_cnt);
return;
}
mutex_lock(&pwrpriv->mutex_lock);
pwrpriv->bips_processing = true;
pwrpriv->ips_mode = pwrpriv->ips_mode_req;
pwrpriv->ips_enter_cnts++;
DBG_88E("==>ips_enter cnts:%d\n", pwrpriv->ips_enter_cnts);
if (rf_off == pwrpriv->change_rfpwrstate) {
pwrpriv->bpower_saving = true;
DBG_88E_LEVEL(_drv_info_, "nolinked power save enter\n");
if (pwrpriv->ips_mode == IPS_LEVEL_2)
pwrpriv->bkeepfwalive = true;
rtw_ips_pwr_down(padapter);
pwrpriv->rf_pwrstate = rf_off;
}
pwrpriv->bips_processing = false;
mutex_unlock(&pwrpriv->mutex_lock);
}
int ips_leave(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct security_priv *psecuritypriv = &(padapter->securitypriv);
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
int result = _SUCCESS;
int keyid;
mutex_lock(&pwrpriv->mutex_lock);
if ((pwrpriv->rf_pwrstate == rf_off) && (!pwrpriv->bips_processing)) {
pwrpriv->bips_processing = true;
pwrpriv->change_rfpwrstate = rf_on;
pwrpriv->ips_leave_cnts++;
DBG_88E("==>ips_leave cnts:%d\n", pwrpriv->ips_leave_cnts);
result = rtw_ips_pwr_up(padapter);
if (result == _SUCCESS) {
pwrpriv->rf_pwrstate = rf_on;
}
DBG_88E_LEVEL(_drv_info_, "nolinked power save leave\n");
if ((_WEP40_ == psecuritypriv->dot11PrivacyAlgrthm) || (_WEP104_ == psecuritypriv->dot11PrivacyAlgrthm)) {
DBG_88E("==>%s, channel(%d), processing(%x)\n", __func__, padapter->mlmeextpriv.cur_channel, pwrpriv->bips_processing);
set_channel_bwmode(padapter, padapter->mlmeextpriv.cur_channel, HAL_PRIME_CHNL_OFFSET_DONT_CARE, HT_CHANNEL_WIDTH_20);
for (keyid = 0; keyid < 4; keyid++) {
if (pmlmepriv->key_mask & BIT(keyid)) {
if (keyid == psecuritypriv->dot11PrivacyKeyIndex)
result = rtw_set_key(padapter, psecuritypriv, keyid, 1);
else
result = rtw_set_key(padapter, psecuritypriv, keyid, 0);
}
}
}
DBG_88E("==> ips_leave.....LED(0x%08x)...\n", usb_read32(padapter, 0x4c));
pwrpriv->bips_processing = false;
pwrpriv->bkeepfwalive = false;
pwrpriv->bpower_saving = false;
}
mutex_unlock(&pwrpriv->mutex_lock);
return result;
}
static bool rtw_pwr_unassociated_idle(struct adapter *adapter)
{
struct mlme_priv *pmlmepriv = &(adapter->mlmepriv);
bool ret = false;
if (time_after_eq(adapter->pwrctrlpriv.ips_deny_time, jiffies))
goto exit;
if (check_fwstate(pmlmepriv, WIFI_ASOC_STATE|WIFI_SITE_MONITOR) ||
check_fwstate(pmlmepriv, WIFI_UNDER_LINKING|WIFI_UNDER_WPS) ||
check_fwstate(pmlmepriv, WIFI_AP_STATE) ||
check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE|WIFI_ADHOC_STATE))
goto exit;
ret = true;
exit:
return ret;
}
void rtw_ps_processor(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
enum rt_rf_power_state rfpwrstate;
pwrpriv->ps_processing = true;
if (pwrpriv->bips_processing)
goto exit;
if (padapter->pwrctrlpriv.bHWPwrPindetect) {
rfpwrstate = RfOnOffDetect(padapter);
DBG_88E("@@@@- #2 %s==> rfstate:%s\n", __func__, (rfpwrstate == rf_on) ? "rf_on" : "rf_off");
if (rfpwrstate != pwrpriv->rf_pwrstate) {
if (rfpwrstate == rf_off) {
pwrpriv->change_rfpwrstate = rf_off;
pwrpriv->brfoffbyhw = true;
rtw_hw_suspend(padapter);
} else {
pwrpriv->change_rfpwrstate = rf_on;
rtw_hw_resume(padapter);
}
DBG_88E("current rf_pwrstate(%s)\n", (pwrpriv->rf_pwrstate == rf_off) ? "rf_off" : "rf_on");
}
pwrpriv->pwr_state_check_cnts++;
}
if (pwrpriv->ips_mode_req == IPS_NONE)
goto exit;
if (!rtw_pwr_unassociated_idle(padapter))
goto exit;
if ((pwrpriv->rf_pwrstate == rf_on) && ((pwrpriv->pwr_state_check_cnts%4) == 0)) {
DBG_88E("==>%s .fw_state(%x)\n", __func__, get_fwstate(pmlmepriv));
pwrpriv->change_rfpwrstate = rf_off;
ips_enter(padapter);
}
exit:
rtw_set_pwr_state_check_timer(&padapter->pwrctrlpriv);
pwrpriv->ps_processing = false;
}
static void pwr_state_check_handler(unsigned long data)
{
struct adapter *padapter = (struct adapter *)data;
rtw_ps_cmd(padapter);
}
void rtw_set_rpwm(struct adapter *padapter, u8 pslv)
{
u8 rpwm;
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
pslv = PS_STATE(pslv);
if (pwrpriv->btcoex_rfon) {
if (pslv < PS_STATE_S4)
pslv = PS_STATE_S3;
}
if ((pwrpriv->rpwm == pslv)) {
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_err_,
("%s: Already set rpwm[0x%02X], new=0x%02X!\n", __func__, pwrpriv->rpwm, pslv));
return;
}
if ((padapter->bSurpriseRemoved) ||
(!padapter->hw_init_completed)) {
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_err_,
("%s: SurpriseRemoved(%d) hw_init_completed(%d)\n",
__func__, padapter->bSurpriseRemoved, padapter->hw_init_completed));
pwrpriv->cpwm = PS_STATE_S4;
return;
}
if (padapter->bDriverStopped) {
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_err_,
("%s: change power state(0x%02X) when DriverStopped\n", __func__, pslv));
if (pslv < PS_STATE_S2) {
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_err_,
("%s: Reject to enter PS_STATE(0x%02X) lower than S2 when DriverStopped!!\n", __func__, pslv));
return;
}
}
rpwm = pslv | pwrpriv->tog;
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_notice_,
("rtw_set_rpwm: rpwm=0x%02x cpwm=0x%02x\n", rpwm, pwrpriv->cpwm));
pwrpriv->rpwm = pslv;
rtw_hal_set_hwreg(padapter, HW_VAR_SET_RPWM, (u8 *)(&rpwm));
pwrpriv->tog += 0x80;
pwrpriv->cpwm = pslv;
}
static u8 PS_RDY_CHECK(struct adapter *padapter)
{
unsigned long curr_time, delta_time;
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct mlme_priv *pmlmepriv = &(padapter->mlmepriv);
curr_time = jiffies;
delta_time = curr_time - pwrpriv->DelayLPSLastTimeStamp;
if (delta_time < LPS_DELAY_TIME)
return false;
if ((check_fwstate(pmlmepriv, _FW_LINKED) == false) ||
(check_fwstate(pmlmepriv, _FW_UNDER_SURVEY)) ||
(check_fwstate(pmlmepriv, WIFI_AP_STATE)) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE)) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_STATE)))
return false;
if (pwrpriv->bInSuspend)
return false;
if ((padapter->securitypriv.dot11AuthAlgrthm == dot11AuthAlgrthm_8021X) && (padapter->securitypriv.binstallGrpkey == false)) {
DBG_88E("Group handshake still in progress !!!\n");
return false;
}
return true;
}
void rtw_set_ps_mode(struct adapter *padapter, u8 ps_mode, u8 smart_ps, u8 bcn_ant_mode)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_notice_,
("%s: PowerMode=%d Smart_PS=%d\n",
__func__, ps_mode, smart_ps));
if (ps_mode > PM_Card_Disable) {
RT_TRACE(_module_rtl871x_pwrctrl_c_, _drv_err_, ("ps_mode:%d error\n", ps_mode));
return;
}
if (pwrpriv->pwr_mode == ps_mode) {
if (PS_MODE_ACTIVE == ps_mode)
return;
if ((pwrpriv->smart_ps == smart_ps) &&
(pwrpriv->bcn_ant_mode == bcn_ant_mode))
return;
}
if (ps_mode == PS_MODE_ACTIVE) {
if (PS_RDY_CHECK(padapter)) {
DBG_88E("%s: Enter 802.11 power save\n", __func__);
pwrpriv->bFwCurrentInPSMode = true;
pwrpriv->pwr_mode = ps_mode;
pwrpriv->smart_ps = smart_ps;
pwrpriv->bcn_ant_mode = bcn_ant_mode;
rtw_hal_set_hwreg(padapter, HW_VAR_H2C_FW_PWRMODE, (u8 *)(&ps_mode));
rtw_set_rpwm(padapter, PS_STATE_S2);
}
}
}
s32 LPS_RF_ON_check(struct adapter *padapter, u32 delay_ms)
{
unsigned long start_time;
u8 bAwake = false;
s32 err = 0;
start_time = jiffies;
while (1) {
rtw_hal_get_hwreg(padapter, HW_VAR_FWLPS_RF_ON, &bAwake);
if (bAwake)
break;
if (padapter->bSurpriseRemoved) {
err = -2;
DBG_88E("%s: device surprise removed!!\n", __func__);
break;
}
if (jiffies_to_msecs(jiffies - start_time) > delay_ms) {
err = -1;
DBG_88E("%s: Wait for FW LPS leave more than %u ms!!!\n", __func__, delay_ms);
break;
}
msleep(1);
}
return err;
}
void LPS_Enter(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
if (PS_RDY_CHECK(padapter) == false)
return;
if (pwrpriv->bLeisurePs) {
if (pwrpriv->LpsIdleCount >= 2) {
if (pwrpriv->pwr_mode == PS_MODE_ACTIVE) {
pwrpriv->bpower_saving = true;
DBG_88E("%s smart_ps:%d\n", __func__, pwrpriv->smart_ps);
rtw_set_ps_mode(padapter, pwrpriv->power_mgnt, pwrpriv->smart_ps, 0);
}
} else {
pwrpriv->LpsIdleCount++;
}
}
}
void LPS_Leave(struct adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
if (pwrpriv->bLeisurePs) {
if (pwrpriv->pwr_mode != PS_MODE_ACTIVE) {
rtw_set_ps_mode(padapter, PS_MODE_ACTIVE, 0, 0);
if (pwrpriv->pwr_mode == PS_MODE_ACTIVE)
LPS_RF_ON_check(padapter, LPS_LEAVE_TIMEOUT_MS);
}
}
pwrpriv->bpower_saving = false;
}
void LeaveAllPowerSaveMode(struct adapter *Adapter)
{
struct mlme_priv *pmlmepriv = &(Adapter->mlmepriv);
u8 enqueue = 0;
if (check_fwstate(pmlmepriv, _FW_LINKED))
rtw_lps_ctrl_wk_cmd(Adapter, LPS_CTRL_LEAVE, enqueue);
}
void rtw_init_pwrctrl_priv(struct adapter *padapter)
{
struct pwrctrl_priv *pwrctrlpriv = &padapter->pwrctrlpriv;
mutex_init(&pwrctrlpriv->mutex_lock);
pwrctrlpriv->rf_pwrstate = rf_on;
pwrctrlpriv->ips_enter_cnts = 0;
pwrctrlpriv->ips_leave_cnts = 0;
pwrctrlpriv->bips_processing = false;
pwrctrlpriv->ips_mode = padapter->registrypriv.ips_mode;
pwrctrlpriv->ips_mode_req = padapter->registrypriv.ips_mode;
pwrctrlpriv->pwr_state_check_interval = RTW_PWR_STATE_CHK_INTERVAL;
pwrctrlpriv->pwr_state_check_cnts = 0;
pwrctrlpriv->bInternalAutoSuspend = false;
pwrctrlpriv->bInSuspend = false;
pwrctrlpriv->bkeepfwalive = false;
pwrctrlpriv->LpsIdleCount = 0;
if (padapter->registrypriv.mp_mode == 1)
pwrctrlpriv->power_mgnt = PS_MODE_ACTIVE;
else
pwrctrlpriv->power_mgnt = padapter->registrypriv.power_mgnt;
pwrctrlpriv->bLeisurePs = (PS_MODE_ACTIVE != pwrctrlpriv->power_mgnt) ? true : false;
pwrctrlpriv->bFwCurrentInPSMode = false;
pwrctrlpriv->rpwm = 0;
pwrctrlpriv->cpwm = PS_STATE_S4;
pwrctrlpriv->pwr_mode = PS_MODE_ACTIVE;
pwrctrlpriv->smart_ps = padapter->registrypriv.smart_ps;
pwrctrlpriv->bcn_ant_mode = 0;
pwrctrlpriv->tog = 0x80;
pwrctrlpriv->btcoex_rfon = false;
setup_timer(&pwrctrlpriv->pwr_state_check_timer,
pwr_state_check_handler,
(unsigned long)padapter);
}
int _rtw_pwr_wakeup(struct adapter *padapter, u32 ips_deffer_ms, const char *caller)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
unsigned long expires;
unsigned long start;
int ret = _SUCCESS;
expires = jiffies + msecs_to_jiffies(ips_deffer_ms);
if (time_before(pwrpriv->ips_deny_time, expires))
pwrpriv->ips_deny_time = jiffies + msecs_to_jiffies(ips_deffer_ms);
start = jiffies;
if (pwrpriv->ps_processing) {
DBG_88E("%s wait ps_processing...\n", __func__);
while (pwrpriv->ps_processing &&
jiffies_to_msecs(jiffies - start) <= 3000)
usleep_range(1000, 3000);
if (pwrpriv->ps_processing)
DBG_88E("%s wait ps_processing timeout\n", __func__);
else
DBG_88E("%s wait ps_processing done\n", __func__);
}
if ((!pwrpriv->bInternalAutoSuspend) && (pwrpriv->bInSuspend)) {
ret = _FAIL;
goto exit;
}
if ((pwrpriv->bInternalAutoSuspend) && (padapter->net_closed)) {
ret = _FAIL;
goto exit;
}
if (check_fwstate(pmlmepriv, _FW_LINKED)) {
ret = _SUCCESS;
goto exit;
}
if (rf_off == pwrpriv->rf_pwrstate) {
DBG_88E("%s call ips_leave....\n", __func__);
if (_FAIL == ips_leave(padapter)) {
DBG_88E("======> ips_leave fail.............\n");
ret = _FAIL;
goto exit;
}
}
if (padapter->bDriverStopped || !padapter->bup ||
!padapter->hw_init_completed) {
DBG_88E("%s: bDriverStopped=%d, bup=%d, hw_init_completed =%u\n"
, caller
, padapter->bDriverStopped
, padapter->bup
, padapter->hw_init_completed);
ret = false;
goto exit;
}
exit:
expires = jiffies + msecs_to_jiffies(ips_deffer_ms);
if (time_before(pwrpriv->ips_deny_time, expires))
pwrpriv->ips_deny_time = jiffies + msecs_to_jiffies(ips_deffer_ms);
return ret;
}
int rtw_pm_set_lps(struct adapter *padapter, u8 mode)
{
int ret = 0;
struct pwrctrl_priv *pwrctrlpriv = &padapter->pwrctrlpriv;
if (mode < PS_MODE_NUM) {
if (pwrctrlpriv->power_mgnt != mode) {
if (PS_MODE_ACTIVE == mode)
LeaveAllPowerSaveMode(padapter);
else
pwrctrlpriv->LpsIdleCount = 2;
pwrctrlpriv->power_mgnt = mode;
pwrctrlpriv->bLeisurePs = (PS_MODE_ACTIVE != pwrctrlpriv->power_mgnt) ? true : false;
}
} else {
ret = -EINVAL;
}
return ret;
}
int rtw_pm_set_ips(struct adapter *padapter, u8 mode)
{
struct pwrctrl_priv *pwrctrlpriv = &padapter->pwrctrlpriv;
if (mode == IPS_NORMAL || mode == IPS_LEVEL_2) {
rtw_ips_mode_req(pwrctrlpriv, mode);
DBG_88E("%s %s\n", __func__, mode == IPS_NORMAL ? "IPS_NORMAL" : "IPS_LEVEL_2");
return 0;
} else if (mode == IPS_NONE) {
rtw_ips_mode_req(pwrctrlpriv, mode);
DBG_88E("%s %s\n", __func__, "IPS_NONE");
if ((padapter->bSurpriseRemoved == 0) && (_FAIL == rtw_pwr_wakeup(padapter)))
return -EFAULT;
} else {
return -EINVAL;
}
return 0;
}
