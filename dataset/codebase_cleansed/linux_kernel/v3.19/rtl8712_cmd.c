static void check_hw_pbc(struct _adapter *padapter)
{
u8 tmp1byte;
r8712_write8(padapter, MAC_PINMUX_CTRL, (GPIOMUX_EN | GPIOSEL_GPIO));
tmp1byte = r8712_read8(padapter, GPIO_IO_SEL);
tmp1byte &= ~(HAL_8192S_HW_GPIO_WPS_BIT);
r8712_write8(padapter, GPIO_IO_SEL, tmp1byte);
tmp1byte = r8712_read8(padapter, GPIO_CTRL);
if (tmp1byte == 0xff)
return;
if (tmp1byte&HAL_8192S_HW_GPIO_WPS_BIT) {
DBG_8712("CheckPbcGPIO - PBC is pressed !!!!\n");
if (padapter->pid == 0)
return;
kill_pid(find_vpid(padapter->pid), SIGUSR1, 1);
}
}
static void query_fw_rx_phy_status(struct _adapter *padapter)
{
u32 val32 = 0;
int pollingcnts = 50;
if (check_fwstate(&padapter->mlmepriv, _FW_LINKED) == true) {
r8712_write32(padapter, IOCMD_CTRL_REG, 0xf4000001);
msleep(100);
while ((r8712_read32(padapter, IOCMD_CTRL_REG)) &&
(pollingcnts > 0)) {
pollingcnts--;
msleep(20);
}
if (pollingcnts != 0)
val32 = r8712_read32(padapter, IOCMD_DATA_REG);
else
val32 = 0;
val32 = val32 >> 4;
padapter->recvpriv.fw_rssi =
(u8)r8712_signal_scale_mapping(val32);
}
}
static void StatusWatchdogCallback(struct _adapter *padapter)
{
check_hw_pbc(padapter);
query_fw_rx_phy_status(padapter);
}
static void r871x_internal_cmd_hdl(struct _adapter *padapter, u8 *pbuf)
{
struct drvint_cmd_parm *pdrvcmd;
if (!pbuf)
return;
pdrvcmd = (struct drvint_cmd_parm *)pbuf;
switch (pdrvcmd->i_cid) {
case WDG_WK_CID:
StatusWatchdogCallback(padapter);
break;
default:
break;
}
kfree(pdrvcmd->pbuf);
}
static u8 read_macreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 write_macreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 read_bbreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
u32 val;
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
if (pcmd->rsp && pcmd->rspsz > 0)
memcpy(pcmd->rsp, (u8 *)&val, pcmd->rspsz);
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 write_bbreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 read_rfreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
u32 val;
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
if (pcmd->rsp && pcmd->rspsz > 0)
memcpy(pcmd->rsp, (u8 *)&val, pcmd->rspsz);
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 write_rfreg_hdl(struct _adapter *padapter, u8 *pbuf)
{
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
pcmd_callback = cmd_callback[pcmd->cmdcode].callback;
if (pcmd_callback == NULL)
r8712_free_cmd_obj(pcmd);
else
pcmd_callback(padapter, pcmd);
return H2C_SUCCESS;
}
static u8 sys_suspend_hdl(struct _adapter *padapter, u8 *pbuf)
{
struct cmd_obj *pcmd = (struct cmd_obj *)pbuf;
r8712_free_cmd_obj(pcmd);
return H2C_SUCCESS;
}
static struct cmd_obj *cmd_hdl_filter(struct _adapter *padapter,
struct cmd_obj *pcmd)
{
struct cmd_obj *pcmd_r;
if (pcmd == NULL)
return pcmd;
pcmd_r = NULL;
switch (pcmd->cmdcode) {
case GEN_CMD_CODE(_Read_MACREG):
read_macreg_hdl(padapter, (u8 *)pcmd);
pcmd_r = pcmd;
break;
case GEN_CMD_CODE(_Write_MACREG):
write_macreg_hdl(padapter, (u8 *)pcmd);
pcmd_r = pcmd;
break;
case GEN_CMD_CODE(_Read_BBREG):
read_bbreg_hdl(padapter, (u8 *)pcmd);
break;
case GEN_CMD_CODE(_Write_BBREG):
write_bbreg_hdl(padapter, (u8 *)pcmd);
break;
case GEN_CMD_CODE(_Read_RFREG):
read_rfreg_hdl(padapter, (u8 *)pcmd);
break;
case GEN_CMD_CODE(_Write_RFREG):
write_rfreg_hdl(padapter, (u8 *)pcmd);
break;
case GEN_CMD_CODE(_SetUsbSuspend):
sys_suspend_hdl(padapter, (u8 *)pcmd);
break;
case GEN_CMD_CODE(_JoinBss):
r8712_joinbss_reset(padapter);
if (padapter->pwrctrlpriv.pwr_mode > PS_MODE_ACTIVE) {
padapter->pwrctrlpriv.pwr_mode = PS_MODE_ACTIVE;
_enter_pwrlock(&(padapter->pwrctrlpriv.lock));
r8712_set_rpwm(padapter, PS_STATE_S4);
up(&(padapter->pwrctrlpriv.lock));
}
pcmd_r = pcmd;
break;
case _DRV_INT_CMD_:
r871x_internal_cmd_hdl(padapter, pcmd->parmbuf);
r8712_free_cmd_obj(pcmd);
pcmd_r = NULL;
break;
default:
pcmd_r = pcmd;
break;
}
return pcmd_r;
}
static u8 check_cmd_fifo(struct _adapter *padapter, uint sz)
{
return _SUCCESS;
}
u8 r8712_fw_cmd(struct _adapter *pAdapter, u32 cmd)
{
int pollingcnts = 50;
r8712_write32(pAdapter, IOCMD_CTRL_REG, cmd);
msleep(100);
while ((0 != r8712_read32(pAdapter, IOCMD_CTRL_REG)) &&
(pollingcnts > 0)) {
pollingcnts--;
msleep(20);
}
if (pollingcnts == 0)
return false;
return true;
}
void r8712_fw_cmd_data(struct _adapter *pAdapter, u32 *value, u8 flag)
{
if (flag == 0)
r8712_write32(pAdapter, IOCMD_DATA_REG, *value);
else
*value = r8712_read32(pAdapter, IOCMD_DATA_REG);
}
int r8712_cmd_thread(void *context)
{
struct cmd_obj *pcmd;
unsigned int cmdsz, wr_sz, *pcmdbuf;
struct tx_desc *pdesc;
void (*pcmd_callback)(struct _adapter *dev, struct cmd_obj *pcmd);
struct _adapter *padapter = (struct _adapter *)context;
struct cmd_priv *pcmdpriv = &(padapter->cmdpriv);
allow_signal(SIGTERM);
while (1) {
if ((_down_sema(&(pcmdpriv->cmd_queue_sema))) == _FAIL)
break;
if ((padapter->bDriverStopped == true) ||
(padapter->bSurpriseRemoved == true))
break;
if (r8712_register_cmd_alive(padapter) != _SUCCESS)
continue;
_next:
pcmd = r8712_dequeue_cmd(&(pcmdpriv->cmd_queue));
if (!(pcmd)) {
r8712_unregister_cmd_alive(padapter);
continue;
}
pcmdbuf = (unsigned int *)pcmdpriv->cmd_buf;
pdesc = (struct tx_desc *)pcmdbuf;
memset(pdesc, 0, TXDESC_SIZE);
pcmd = cmd_hdl_filter(padapter, pcmd);
if (pcmd) {
struct dvobj_priv *pdvobj = (struct dvobj_priv *)
&padapter->dvobjpriv;
u8 blnPending = 0;
pcmdpriv->cmd_issued_cnt++;
cmdsz = round_up(pcmd->cmdsz, 8);
wr_sz = TXDESC_SIZE + 8 + cmdsz;
pdesc->txdw0 |= cpu_to_le32((wr_sz-TXDESC_SIZE) &
0x0000ffff);
if (pdvobj->ishighspeed) {
if ((wr_sz % 512) == 0)
blnPending = 1;
} else {
if ((wr_sz % 64) == 0)
blnPending = 1;
}
if (blnPending)
pdesc->txdw0 |= cpu_to_le32(((TXDESC_SIZE +
OFFSET_SZ + 8) << OFFSET_SHT) &
0x00ff0000);
else {
pdesc->txdw0 |= cpu_to_le32(((TXDESC_SIZE +
OFFSET_SZ) <<
OFFSET_SHT) &
0x00ff0000);
}
pdesc->txdw0 |= cpu_to_le32(OWN | FSG | LSG);
pdesc->txdw1 |= cpu_to_le32((0x13 << QSEL_SHT) &
0x00001f00);
pcmdbuf += (TXDESC_SIZE >> 2);
*pcmdbuf = cpu_to_le32((cmdsz & 0x0000ffff) |
(pcmd->cmdcode << 16) |
(pcmdpriv->cmd_seq << 24));
pcmdbuf += 2;
memcpy((u8 *)pcmdbuf, pcmd->parmbuf, pcmd->cmdsz);
while (check_cmd_fifo(padapter, wr_sz) == _FAIL) {
if ((padapter->bDriverStopped == true) ||
(padapter->bSurpriseRemoved == true))
break;
msleep(100);
continue;
}
if (blnPending)
wr_sz += 8;
r8712_write_mem(padapter, RTL8712_DMA_H2CCMD, wr_sz,
(u8 *)pdesc);
pcmdpriv->cmd_seq++;
if (pcmd->cmdcode == GEN_CMD_CODE(_CreateBss)) {
pcmd->res = H2C_SUCCESS;
pcmd_callback = cmd_callback[pcmd->
cmdcode].callback;
if (pcmd_callback)
pcmd_callback(padapter, pcmd);
continue;
}
if (pcmd->cmdcode == GEN_CMD_CODE(_SetPwrMode)) {
if (padapter->pwrctrlpriv.bSleep) {
_enter_pwrlock(&(padapter->
pwrctrlpriv.lock));
r8712_set_rpwm(padapter, PS_STATE_S2);
up(&padapter->pwrctrlpriv.lock);
}
}
r8712_free_cmd_obj(pcmd);
if (list_empty(&pcmdpriv->cmd_queue.queue)) {
r8712_unregister_cmd_alive(padapter);
continue;
} else
goto _next;
} else
goto _next;
flush_signals_thread();
}
do {
pcmd = r8712_dequeue_cmd(&(pcmdpriv->cmd_queue));
if (pcmd == NULL)
break;
r8712_free_cmd_obj(pcmd);
} while (1);
up(&pcmdpriv->terminate_cmdthread_sema);
thread_exit();
}
void r8712_event_handle(struct _adapter *padapter, uint *peventbuf)
{
u8 evt_code, evt_seq;
u16 evt_sz;
void (*event_callback)(struct _adapter *dev, u8 *pbuf);
struct evt_priv *pevt_priv = &(padapter->evtpriv);
if (peventbuf == NULL)
goto _abort_event_;
evt_sz = (u16)(le32_to_cpu(*peventbuf) & 0xffff);
evt_seq = (u8)((le32_to_cpu(*peventbuf) >> 24) & 0x7f);
evt_code = (u8)((le32_to_cpu(*peventbuf) >> 16) & 0xff);
if ((evt_seq & 0x7f) != pevt_priv->event_seq) {
pevt_priv->event_seq = ((evt_seq + 1) & 0x7f);
goto _abort_event_;
}
if (evt_code >= MAX_C2HEVT) {
pevt_priv->event_seq = ((evt_seq+1) & 0x7f);
goto _abort_event_;
} else if ((evt_code == GEN_EVT_CODE(_Survey)) &&
(evt_sz > sizeof(struct wlan_bssid_ex))) {
pevt_priv->event_seq = ((evt_seq+1)&0x7f);
goto _abort_event_;
}
if ((wlanevents[evt_code].parmsize) &&
(wlanevents[evt_code].parmsize != evt_sz)) {
pevt_priv->event_seq = ((evt_seq+1)&0x7f);
goto _abort_event_;
} else if ((evt_sz == 0) && (evt_code != GEN_EVT_CODE(_WPS_PBC))) {
pevt_priv->event_seq = ((evt_seq+1)&0x7f);
goto _abort_event_;
}
pevt_priv->event_seq++;
if (pevt_priv->event_seq > 127)
pevt_priv->event_seq = 0;
peventbuf = peventbuf + 2;
event_callback = wlanevents[evt_code].event_callback;
if (event_callback)
event_callback(padapter, (u8 *)peventbuf);
pevt_priv->evt_done_cnt++;
_abort_event_:
return;
}
