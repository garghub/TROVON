static uint loadparam(struct _adapter *padapter, struct net_device *pnetdev)
{
uint status = _SUCCESS;
struct registry_priv *registry_par = &padapter->registrypriv;
registry_par->chip_version = (u8)chip_version;
registry_par->rfintfs = (u8)rfintfs;
registry_par->lbkmode = (u8)lbkmode;
registry_par->hci = (u8)hci;
registry_par->network_mode = (u8)network_mode;
memcpy(registry_par->ssid.Ssid, "ANY", 3);
registry_par->ssid.SsidLength = 3;
registry_par->channel = (u8)channel;
registry_par->wireless_mode = (u8)wireless_mode;
registry_par->vrtl_carrier_sense = (u8)vrtl_carrier_sense ;
registry_par->vcs_type = (u8)vcs_type;
registry_par->frag_thresh = (u16)frag_thresh;
registry_par->preamble = (u8)preamble;
registry_par->scan_mode = (u8)scan_mode;
registry_par->adhoc_tx_pwr = (u8)adhoc_tx_pwr;
registry_par->soft_ap = (u8)soft_ap;
registry_par->smart_ps = (u8)smart_ps;
registry_par->power_mgnt = (u8)power_mgnt;
registry_par->radio_enable = (u8)radio_enable;
registry_par->long_retry_lmt = (u8)long_retry_lmt;
registry_par->short_retry_lmt = (u8)short_retry_lmt;
registry_par->busy_thresh = (u16)busy_thresh;
registry_par->ack_policy = (u8)ack_policy;
registry_par->mp_mode = (u8)mp_mode;
registry_par->software_encrypt = (u8)software_encrypt;
registry_par->software_decrypt = (u8)software_decrypt;
registry_par->wmm_enable = (u8)wmm_enable;
registry_par->uapsd_enable = (u8)uapsd_enable;
registry_par->uapsd_max_sp = (u8)uapsd_max_sp;
registry_par->uapsd_acbk_en = (u8)uapsd_acbk_en;
registry_par->uapsd_acbe_en = (u8)uapsd_acbe_en;
registry_par->uapsd_acvi_en = (u8)uapsd_acvi_en;
registry_par->uapsd_acvo_en = (u8)uapsd_acvo_en;
registry_par->ht_enable = (u8)ht_enable;
registry_par->cbw40_enable = (u8)cbw40_enable;
registry_par->ampdu_enable = (u8)ampdu_enable;
registry_par->rf_config = (u8)rf_config;
registry_par->low_power = (u8)low_power;
registry_par->wifi_test = (u8) wifi_test;
r8712_initmac = initmac;
return status;
}
static int r871x_net_set_mac_address(struct net_device *pnetdev, void *p)
{
struct _adapter *padapter = (struct _adapter *)netdev_priv(pnetdev);
struct sockaddr *addr = p;
if (padapter->bup == false)
memcpy(pnetdev->dev_addr, addr->sa_data, ETH_ALEN);
return 0;
}
static struct net_device_stats *r871x_net_get_stats(struct net_device *pnetdev)
{
struct _adapter *padapter = (struct _adapter *) netdev_priv(pnetdev);
struct xmit_priv *pxmitpriv = &(padapter->xmitpriv);
struct recv_priv *precvpriv = &(padapter->recvpriv);
padapter->stats.tx_packets = pxmitpriv->tx_pkts;
padapter->stats.rx_packets = precvpriv->rx_pkts;
padapter->stats.tx_dropped = pxmitpriv->tx_drop;
padapter->stats.rx_dropped = precvpriv->rx_drop;
padapter->stats.tx_bytes = pxmitpriv->tx_bytes;
padapter->stats.rx_bytes = precvpriv->rx_bytes;
return &padapter->stats;
}
struct net_device *r8712_init_netdev(void)
{
struct _adapter *padapter;
struct net_device *pnetdev;
pnetdev = alloc_etherdev(sizeof(struct _adapter));
if (!pnetdev)
return NULL;
if (dev_alloc_name(pnetdev, ifname) < 0) {
strcpy(ifname, "wlan%d");
dev_alloc_name(pnetdev, ifname);
}
padapter = (struct _adapter *) netdev_priv(pnetdev);
padapter->pnetdev = pnetdev;
printk(KERN_INFO "r8712u: register rtl8712_netdev_ops to"
" netdev_ops\n");
pnetdev->netdev_ops = &rtl8712_netdev_ops;
pnetdev->watchdog_timeo = HZ;
pnetdev->wireless_handlers = (struct iw_handler_def *)
&r871x_handlers_def;
loadparam(padapter, pnetdev);
netif_carrier_off(pnetdev);
padapter->pid = 0;
return pnetdev;
}
static u32 start_drv_threads(struct _adapter *padapter)
{
padapter->cmdThread = kthread_run(r8712_cmd_thread, padapter,
padapter->pnetdev->name);
if (IS_ERR(padapter->cmdThread) < 0)
return _FAIL;
return _SUCCESS;
}
void r8712_stop_drv_threads(struct _adapter *padapter)
{
up(&padapter->cmdpriv.cmd_queue_sema);
if (padapter->cmdThread)
_down_sema(&padapter->cmdpriv.terminate_cmdthread_sema);
padapter->cmdpriv.cmd_seq = 1;
}
static void start_drv_timers(struct _adapter *padapter)
{
_set_timer(&padapter->mlmepriv.sitesurveyctrl.sitesurvey_ctrl_timer,
5000);
_set_timer(&padapter->mlmepriv.wdg_timer, 2000);
}
void r8712_stop_drv_timers(struct _adapter *padapter)
{
_cancel_timer_ex(&padapter->mlmepriv.assoc_timer);
_cancel_timer_ex(&padapter->securitypriv.tkip_timer);
_cancel_timer_ex(&padapter->mlmepriv.scan_to_timer);
_cancel_timer_ex(&padapter->mlmepriv.dhcp_timer);
_cancel_timer_ex(&padapter->mlmepriv.wdg_timer);
_cancel_timer_ex(&padapter->mlmepriv.sitesurveyctrl.
sitesurvey_ctrl_timer);
}
static u8 init_default_value(struct _adapter *padapter)
{
u8 ret = _SUCCESS;
struct registry_priv *pregistrypriv = &padapter->registrypriv;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct security_priv *psecuritypriv = &padapter->securitypriv;
pxmitpriv->vcs_setting = pregistrypriv->vrtl_carrier_sense;
pxmitpriv->vcs = pregistrypriv->vcs_type;
pxmitpriv->vcs_type = pregistrypriv->vcs_type;
pxmitpriv->rts_thresh = pregistrypriv->rts_thresh;
pxmitpriv->frag_len = pregistrypriv->frag_thresh;
pmlmepriv->passive_mode = 1;
{
int i;
struct ht_priv *phtpriv = &pmlmepriv->htpriv;
phtpriv->ampdu_enable = false;
for (i = 0; i < 16; i++)
phtpriv->baddbareq_issued[i] = false;
}
psecuritypriv->sw_encrypt = pregistrypriv->software_encrypt;
psecuritypriv->sw_decrypt = pregistrypriv->software_decrypt;
psecuritypriv->binstallGrpkey = _FAIL;
r8712_init_registrypriv_dev_network(padapter);
r8712_update_registrypriv_dev_network(padapter);
return ret;
}
u8 r8712_init_drv_sw(struct _adapter *padapter)
{
if ((r8712_init_cmd_priv(&padapter->cmdpriv)) == _FAIL)
return _FAIL;
padapter->cmdpriv.padapter = padapter;
if ((r8712_init_evt_priv(&padapter->evtpriv)) == _FAIL)
return _FAIL;
if (r8712_init_mlme_priv(padapter) == _FAIL)
return _FAIL;
_r8712_init_xmit_priv(&padapter->xmitpriv, padapter);
_r8712_init_recv_priv(&padapter->recvpriv, padapter);
memset((unsigned char *)&padapter->securitypriv, 0,
sizeof(struct security_priv));
_init_timer(&(padapter->securitypriv.tkip_timer), padapter->pnetdev,
r8712_use_tkipkey_handler, padapter);
_r8712_init_sta_priv(&padapter->stapriv);
padapter->stapriv.padapter = padapter;
r8712_init_bcmc_stainfo(padapter);
r8712_init_pwrctrl_priv(padapter);
sema_init(&(padapter->pwrctrlpriv.pnp_pwr_mgnt_sema), 0);
mp871xinit(padapter);
if (init_default_value(padapter) != _SUCCESS)
return _FAIL;
r8712_InitSwLeds(padapter);
return _SUCCESS;
}
u8 r8712_free_drv_sw(struct _adapter *padapter)
{
struct net_device *pnetdev = (struct net_device *)padapter->pnetdev;
r8712_free_cmd_priv(&padapter->cmdpriv);
r8712_free_evt_priv(&padapter->evtpriv);
r8712_DeInitSwLeds(padapter);
r8712_free_mlme_priv(&padapter->mlmepriv);
r8712_free_io_queue(padapter);
_free_xmit_priv(&padapter->xmitpriv);
if (padapter->fw_found)
_r8712_free_sta_priv(&padapter->stapriv);
_r8712_free_recv_priv(&padapter->recvpriv);
mp871xdeinit(padapter);
if (pnetdev)
free_netdev(pnetdev);
return _SUCCESS;
}
static void enable_video_mode(struct _adapter *padapter, int cbw40_value)
{
u32 intcmd = 0xf4000500;
if (cbw40_value) {
intcmd |= 0x200;
}
r8712_fw_cmd(padapter, intcmd);
}
static int netdev_open(struct net_device *pnetdev)
{
struct _adapter *padapter = (struct _adapter *)netdev_priv(pnetdev);
mutex_lock(&padapter->mutex_start);
if (padapter->bup == false) {
padapter->bDriverStopped = false;
padapter->bSurpriseRemoved = false;
padapter->bup = true;
if (rtl871x_hal_init(padapter) != _SUCCESS)
goto netdev_open_error;
if (r8712_initmac == NULL)
memcpy(pnetdev->dev_addr,
padapter->eeprompriv.mac_addr, ETH_ALEN);
else {
msleep(200);
r8712_setMacAddr_cmd(padapter, (u8 *)pnetdev->dev_addr);
memcpy(padapter->eeprompriv.mac_addr,
pnetdev->dev_addr, ETH_ALEN);
}
if (start_drv_threads(padapter) != _SUCCESS)
goto netdev_open_error;
if (padapter->dvobjpriv.inirp_init == NULL)
goto netdev_open_error;
else
padapter->dvobjpriv.inirp_init(padapter);
r8712_set_ps_mode(padapter, padapter->registrypriv.power_mgnt,
padapter->registrypriv.smart_ps);
}
if (!netif_queue_stopped(pnetdev))
netif_start_queue(pnetdev);
else
netif_wake_queue(pnetdev);
if (video_mode)
enable_video_mode(padapter, cbw40_enable);
start_drv_timers(padapter);
padapter->ledpriv.LedControlHandler(padapter, LED_CTL_NO_LINK);
mutex_unlock(&padapter->mutex_start);
return 0;
netdev_open_error:
padapter->bup = false;
netif_carrier_off(pnetdev);
netif_stop_queue(pnetdev);
mutex_unlock(&padapter->mutex_start);
return -1;
}
static int netdev_close(struct net_device *pnetdev)
{
struct _adapter *padapter = (struct _adapter *) netdev_priv(pnetdev);
padapter->ledpriv.LedControlHandler(padapter, LED_CTL_POWER_OFF);
msleep(200);
if (pnetdev) {
if (!netif_queue_stopped(pnetdev))
netif_stop_queue(pnetdev);
}
r8712_disassoc_cmd(padapter);
r8712_ind_disconnect(padapter);
r8712_free_assoc_resources(padapter);
r8712_free_network_queue(padapter);
padapter->bup = false;
release_firmware(padapter->fw);
wait_for_completion(&padapter->rtl8712_fw_ready);
return 0;
}
