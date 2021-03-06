void r8712_set_rpwm(struct _adapter *padapter, u8 val8)
{
u8 rpwm;
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
if (pwrpriv->rpwm == val8) {
if (pwrpriv->rpwm_retry == 0)
return;
}
if ((padapter->bDriverStopped == true) ||
(padapter->bSurpriseRemoved == true))
return;
rpwm = val8 | pwrpriv->tog;
switch (val8) {
case PS_STATE_S1:
pwrpriv->cpwm = val8;
break;
case PS_STATE_S2:
case PS_STATE_S3:
case PS_STATE_S4:
pwrpriv->cpwm = val8;
break;
default:
break;
}
pwrpriv->rpwm_retry = 0;
pwrpriv->rpwm = val8;
r8712_write8(padapter, 0x1025FE58, rpwm);
pwrpriv->tog += 0x80;
}
void r8712_set_ps_mode(struct _adapter *padapter, uint ps_mode, uint smart_ps)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
if (ps_mode > PM_Card_Disable)
return;
if (ps_mode == PS_MODE_ACTIVE)
smart_ps = 0;
if ((pwrpriv->pwr_mode != ps_mode) || (pwrpriv->smart_ps != smart_ps)) {
if (pwrpriv->pwr_mode == PS_MODE_ACTIVE)
pwrpriv->bSleep = true;
else
pwrpriv->bSleep = false;
pwrpriv->pwr_mode = ps_mode;
pwrpriv->smart_ps = smart_ps;
schedule_work(&pwrpriv->SetPSModeWorkItem);
}
}
void r8712_cpwm_int_hdl(struct _adapter *padapter,
struct reportpwrstate_parm *preportpwrstate)
{
struct pwrctrl_priv *pwrpriv = &(padapter->pwrctrlpriv);
struct cmd_priv *pcmdpriv = &(padapter->cmdpriv);
if (pwrpriv->cpwm_tog == ((preportpwrstate->state) & 0x80))
return;
_cancel_timer_ex(&padapter->pwrctrlpriv. rpwm_check_timer);
_enter_pwrlock(&pwrpriv->lock);
pwrpriv->cpwm = (preportpwrstate->state) & 0xf;
if (pwrpriv->cpwm >= PS_STATE_S2) {
if (pwrpriv->alives & CMD_ALIVE)
up(&(pcmdpriv->cmd_queue_sema));
}
pwrpriv->cpwm_tog = (preportpwrstate->state) & 0x80;
up(&pwrpriv->lock);
}
static inline void register_task_alive(struct pwrctrl_priv *pwrctrl, uint tag)
{
pwrctrl->alives |= tag;
}
static inline void unregister_task_alive(struct pwrctrl_priv *pwrctrl, uint tag)
{
if (pwrctrl->alives & tag)
pwrctrl->alives ^= tag;
}
static void _rpwm_check_handler (struct _adapter *padapter)
{
struct pwrctrl_priv *pwrpriv = &padapter->pwrctrlpriv;
if (padapter->bDriverStopped == true ||
padapter->bSurpriseRemoved == true)
return;
if (pwrpriv->cpwm != pwrpriv->rpwm)
schedule_work(&pwrpriv->rpwm_workitem);
}
static void SetPSModeWorkItemCallback(struct work_struct *work)
{
struct pwrctrl_priv *pwrpriv = container_of(work,
struct pwrctrl_priv, SetPSModeWorkItem);
struct _adapter *padapter = container_of(pwrpriv,
struct _adapter, pwrctrlpriv);
if (!pwrpriv->bSleep) {
_enter_pwrlock(&pwrpriv->lock);
if (pwrpriv->pwr_mode == PS_MODE_ACTIVE)
r8712_set_rpwm(padapter, PS_STATE_S4);
up(&pwrpriv->lock);
}
}
static void rpwm_workitem_callback(struct work_struct *work)
{
struct pwrctrl_priv *pwrpriv = container_of(work,
struct pwrctrl_priv, rpwm_workitem);
struct _adapter *padapter = container_of(pwrpriv,
struct _adapter, pwrctrlpriv);
u8 cpwm = pwrpriv->cpwm;
if (pwrpriv->cpwm != pwrpriv->rpwm) {
_enter_pwrlock(&pwrpriv->lock);
cpwm = r8712_read8(padapter, SDIO_HCPWM);
pwrpriv->rpwm_retry = 1;
r8712_set_rpwm(padapter, pwrpriv->rpwm);
up(&pwrpriv->lock);
}
}
static void rpwm_check_handler (void *FunctionContext)
{
struct _adapter *adapter = (struct _adapter *)FunctionContext;
_rpwm_check_handler(adapter);
}
void r8712_init_pwrctrl_priv(struct _adapter *padapter)
{
struct pwrctrl_priv *pwrctrlpriv = &padapter->pwrctrlpriv;
memset((unsigned char *)pwrctrlpriv, 0, sizeof(struct pwrctrl_priv));
sema_init(&pwrctrlpriv->lock, 1);
pwrctrlpriv->cpwm = PS_STATE_S4;
pwrctrlpriv->pwr_mode = PS_MODE_ACTIVE;
pwrctrlpriv->smart_ps = 0;
pwrctrlpriv->tog = 0x80;
r8712_write8(padapter, 0x1025FE58, 0);
INIT_WORK(&pwrctrlpriv->SetPSModeWorkItem, SetPSModeWorkItemCallback);
INIT_WORK(&pwrctrlpriv->rpwm_workitem, rpwm_workitem_callback);
_init_timer(&(pwrctrlpriv->rpwm_check_timer),
padapter->pnetdev, rpwm_check_handler, (u8 *)padapter);
}
sint r8712_register_cmd_alive(struct _adapter *padapter)
{
uint res = _SUCCESS;
struct pwrctrl_priv *pwrctrl = &padapter->pwrctrlpriv;
_enter_pwrlock(&pwrctrl->lock);
register_task_alive(pwrctrl, CMD_ALIVE);
if (pwrctrl->cpwm < PS_STATE_S2) {
r8712_set_rpwm(padapter, PS_STATE_S3);
res = _FAIL;
}
up(&pwrctrl->lock);
return res;
}
void r8712_unregister_cmd_alive(struct _adapter *padapter)
{
struct pwrctrl_priv *pwrctrl = &padapter->pwrctrlpriv;
_enter_pwrlock(&pwrctrl->lock);
unregister_task_alive(pwrctrl, CMD_ALIVE);
if ((pwrctrl->cpwm > PS_STATE_S2) &&
(pwrctrl->pwr_mode > PS_MODE_ACTIVE)) {
if ((pwrctrl->alives == 0) &&
(check_fwstate(&padapter->mlmepriv,
_FW_UNDER_LINKING) != true)) {
r8712_set_rpwm(padapter, PS_STATE_S0);
}
}
up(&pwrctrl->lock);
}
