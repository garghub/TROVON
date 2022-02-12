static void HalSdioGetCmdAddr8723BSdio(
struct adapter *padapter,
u8 DeviceID,
u32 Addr,
u32 *pCmdAddr
)
{
switch (DeviceID) {
case SDIO_LOCAL_DEVICE_ID:
*pCmdAddr = ((SDIO_LOCAL_DEVICE_ID << 13) | (Addr & SDIO_LOCAL_MSK));
break;
case WLAN_IOREG_DEVICE_ID:
*pCmdAddr = ((WLAN_IOREG_DEVICE_ID << 13) | (Addr & WLAN_IOREG_MSK));
break;
case WLAN_TX_HIQ_DEVICE_ID:
*pCmdAddr = ((WLAN_TX_HIQ_DEVICE_ID << 13) | (Addr & WLAN_FIFO_MSK));
break;
case WLAN_TX_MIQ_DEVICE_ID:
*pCmdAddr = ((WLAN_TX_MIQ_DEVICE_ID << 13) | (Addr & WLAN_FIFO_MSK));
break;
case WLAN_TX_LOQ_DEVICE_ID:
*pCmdAddr = ((WLAN_TX_LOQ_DEVICE_ID << 13) | (Addr & WLAN_FIFO_MSK));
break;
case WLAN_RX0FF_DEVICE_ID:
*pCmdAddr = ((WLAN_RX0FF_DEVICE_ID << 13) | (Addr & WLAN_RX0FF_MSK));
break;
default:
break;
}
}
static u8 get_deviceid(u32 addr)
{
u8 devideId;
u16 pseudoId;
pseudoId = (u16)(addr >> 16);
switch (pseudoId) {
case 0x1025:
devideId = SDIO_LOCAL_DEVICE_ID;
break;
case 0x1026:
devideId = WLAN_IOREG_DEVICE_ID;
break;
case 0x1031:
devideId = WLAN_TX_HIQ_DEVICE_ID;
break;
case 0x1032:
devideId = WLAN_TX_MIQ_DEVICE_ID;
break;
case 0x1033:
devideId = WLAN_TX_LOQ_DEVICE_ID;
break;
case 0x1034:
devideId = WLAN_RX0FF_DEVICE_ID;
break;
default:
devideId = WLAN_IOREG_DEVICE_ID;
break;
}
return devideId;
}
static u32 _cvrt2ftaddr(const u32 addr, u8 *pdeviceId, u16 *poffset)
{
u8 deviceId;
u16 offset;
u32 ftaddr;
deviceId = get_deviceid(addr);
offset = 0;
switch (deviceId) {
case SDIO_LOCAL_DEVICE_ID:
offset = addr & SDIO_LOCAL_MSK;
break;
case WLAN_TX_HIQ_DEVICE_ID:
case WLAN_TX_MIQ_DEVICE_ID:
case WLAN_TX_LOQ_DEVICE_ID:
offset = addr & WLAN_FIFO_MSK;
break;
case WLAN_RX0FF_DEVICE_ID:
offset = addr & WLAN_RX0FF_MSK;
break;
case WLAN_IOREG_DEVICE_ID:
default:
deviceId = WLAN_IOREG_DEVICE_ID;
offset = addr & WLAN_IOREG_MSK;
break;
}
ftaddr = (deviceId << 13) | offset;
if (pdeviceId)
*pdeviceId = deviceId;
if (poffset)
*poffset = offset;
return ftaddr;
}
static u8 sdio_read8(struct intf_hdl *pintfhdl, u32 addr)
{
u32 ftaddr;
u8 val;
ftaddr = _cvrt2ftaddr(addr, NULL, NULL);
val = sd_read8(pintfhdl, ftaddr, NULL);
return val;
}
static u16 sdio_read16(struct intf_hdl *pintfhdl, u32 addr)
{
u32 ftaddr;
u16 val;
__le16 le_tmp;
ftaddr = _cvrt2ftaddr(addr, NULL, NULL);
sd_cmd52_read(pintfhdl, ftaddr, 2, (u8 *)&le_tmp);
val = le16_to_cpu(le_tmp);
return val;
}
static u32 sdio_read32(struct intf_hdl *pintfhdl, u32 addr)
{
struct adapter *padapter;
u8 bMacPwrCtrlOn;
u8 deviceId;
u16 offset;
u32 ftaddr;
u8 shift;
u32 val;
s32 err;
__le32 le_tmp;
padapter = pintfhdl->padapter;
ftaddr = _cvrt2ftaddr(addr, &deviceId, &offset);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
((deviceId == WLAN_IOREG_DEVICE_ID) && (offset < 0x100)) ||
(false == bMacPwrCtrlOn) ||
(true == adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
err = sd_cmd52_read(pintfhdl, ftaddr, 4, (u8 *)&le_tmp);
#ifdef SDIO_DEBUG_IO
if (!err) {
#endif
val = le32_to_cpu(le_tmp);
return val;
#ifdef SDIO_DEBUG_IO
}
DBG_8192C(KERN_ERR "%s: Mac Power off, Read FAIL(%d)! addr = 0x%x\n", __func__, err, addr);
return SDIO_ERR_VAL32;
#endif
}
shift = ftaddr & 0x3;
if (shift == 0) {
val = sd_read32(pintfhdl, ftaddr, NULL);
} else {
u8 *ptmpbuf;
ptmpbuf = (u8 *)rtw_malloc(8);
if (NULL == ptmpbuf) {
DBG_8192C(KERN_ERR "%s: Allocate memory FAIL!(size =8) addr = 0x%x\n", __func__, addr);
return SDIO_ERR_VAL32;
}
ftaddr &= ~(u16)0x3;
sd_read(pintfhdl, ftaddr, 8, ptmpbuf);
memcpy(&le_tmp, ptmpbuf+shift, 4);
val = le32_to_cpu(le_tmp);
kfree(ptmpbuf);
}
return val;
}
static s32 sdio_readN(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *pbuf)
{
struct adapter *padapter;
u8 bMacPwrCtrlOn;
u8 deviceId;
u16 offset;
u32 ftaddr;
u8 shift;
s32 err;
padapter = pintfhdl->padapter;
err = 0;
ftaddr = _cvrt2ftaddr(addr, &deviceId, &offset);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
((deviceId == WLAN_IOREG_DEVICE_ID) && (offset < 0x100)) ||
(false == bMacPwrCtrlOn) ||
(true == adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
err = sd_cmd52_read(pintfhdl, ftaddr, cnt, pbuf);
return err;
}
shift = ftaddr & 0x3;
if (shift == 0) {
err = sd_read(pintfhdl, ftaddr, cnt, pbuf);
} else {
u8 *ptmpbuf;
u32 n;
ftaddr &= ~(u16)0x3;
n = cnt + shift;
ptmpbuf = rtw_malloc(n);
if (NULL == ptmpbuf)
return -1;
err = sd_read(pintfhdl, ftaddr, n, ptmpbuf);
if (!err)
memcpy(pbuf, ptmpbuf+shift, cnt);
kfree(ptmpbuf);
}
return err;
}
static s32 sdio_write8(struct intf_hdl *pintfhdl, u32 addr, u8 val)
{
u32 ftaddr;
s32 err;
ftaddr = _cvrt2ftaddr(addr, NULL, NULL);
sd_write8(pintfhdl, ftaddr, val, &err);
return err;
}
static s32 sdio_write16(struct intf_hdl *pintfhdl, u32 addr, u16 val)
{
u32 ftaddr;
s32 err;
__le16 le_tmp;
ftaddr = _cvrt2ftaddr(addr, NULL, NULL);
le_tmp = cpu_to_le16(val);
err = sd_cmd52_write(pintfhdl, ftaddr, 2, (u8 *)&le_tmp);
return err;
}
static s32 sdio_write32(struct intf_hdl *pintfhdl, u32 addr, u32 val)
{
struct adapter *padapter;
u8 bMacPwrCtrlOn;
u8 deviceId;
u16 offset;
u32 ftaddr;
u8 shift;
s32 err;
__le32 le_tmp;
padapter = pintfhdl->padapter;
err = 0;
ftaddr = _cvrt2ftaddr(addr, &deviceId, &offset);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
((deviceId == WLAN_IOREG_DEVICE_ID) && (offset < 0x100)) ||
(!bMacPwrCtrlOn) ||
(adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
le_tmp = cpu_to_le32(val);
err = sd_cmd52_write(pintfhdl, ftaddr, 4, (u8 *)&le_tmp);
return err;
}
shift = ftaddr & 0x3;
if (shift == 0) {
sd_write32(pintfhdl, ftaddr, val, &err);
} else {
le_tmp = cpu_to_le32(val);
err = sd_cmd52_write(pintfhdl, ftaddr, 4, (u8 *)&le_tmp);
}
return err;
}
static s32 sdio_writeN(struct intf_hdl *pintfhdl, u32 addr, u32 cnt, u8 *pbuf)
{
struct adapter *padapter;
u8 bMacPwrCtrlOn;
u8 deviceId;
u16 offset;
u32 ftaddr;
u8 shift;
s32 err;
padapter = pintfhdl->padapter;
err = 0;
ftaddr = _cvrt2ftaddr(addr, &deviceId, &offset);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
((deviceId == WLAN_IOREG_DEVICE_ID) && (offset < 0x100)) ||
(false == bMacPwrCtrlOn) ||
(true == adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
err = sd_cmd52_write(pintfhdl, ftaddr, cnt, pbuf);
return err;
}
shift = ftaddr & 0x3;
if (shift == 0) {
err = sd_write(pintfhdl, ftaddr, cnt, pbuf);
} else {
u8 *ptmpbuf;
u32 n;
ftaddr &= ~(u16)0x3;
n = cnt + shift;
ptmpbuf = rtw_malloc(n);
if (NULL == ptmpbuf)
return -1;
err = sd_read(pintfhdl, ftaddr, 4, ptmpbuf);
if (err) {
kfree(ptmpbuf);
return err;
}
memcpy(ptmpbuf+shift, pbuf, cnt);
err = sd_write(pintfhdl, ftaddr, n, ptmpbuf);
kfree(ptmpbuf);
}
return err;
}
static u8 sdio_f0_read8(struct intf_hdl *pintfhdl, u32 addr)
{
return sd_f0_read8(pintfhdl, addr, NULL);
}
static void sdio_read_mem(
struct intf_hdl *pintfhdl,
u32 addr,
u32 cnt,
u8 *rmem
)
{
s32 err;
err = sdio_readN(pintfhdl, addr, cnt, rmem);
}
static void sdio_write_mem(
struct intf_hdl *pintfhdl,
u32 addr,
u32 cnt,
u8 *wmem
)
{
sdio_writeN(pintfhdl, addr, cnt, wmem);
}
static u32 sdio_read_port(
struct intf_hdl *pintfhdl,
u32 addr,
u32 cnt,
u8 *mem
)
{
struct adapter *padapter;
PSDIO_DATA psdio;
struct hal_com_data *phal;
u32 oldcnt;
#ifdef SDIO_DYNAMIC_ALLOC_MEM
u8 *oldmem;
#endif
s32 err;
padapter = pintfhdl->padapter;
psdio = &adapter_to_dvobj(padapter)->intf_data;
phal = GET_HAL_DATA(padapter);
HalSdioGetCmdAddr8723BSdio(padapter, addr, phal->SdioRxFIFOCnt++, &addr);
oldcnt = cnt;
if (cnt > psdio->block_transfer_len)
cnt = _RND(cnt, psdio->block_transfer_len);
if (oldcnt != cnt) {
#ifdef SDIO_DYNAMIC_ALLOC_MEM
oldmem = mem;
mem = rtw_malloc(cnt);
if (mem == NULL) {
DBG_8192C(KERN_WARNING "%s: allocate memory %d bytes fail!\n", __func__, cnt);
mem = oldmem;
oldmem == NULL;
}
#else
#endif
}
err = _sd_read(pintfhdl, addr, cnt, mem);
#ifdef SDIO_DYNAMIC_ALLOC_MEM
if ((oldcnt != cnt) && (oldmem)) {
memcpy(oldmem, mem, oldcnt);
kfree(mem);
}
#endif
if (err)
return _FAIL;
return _SUCCESS;
}
static u32 sdio_write_port(
struct intf_hdl *pintfhdl,
u32 addr,
u32 cnt,
u8 *mem
)
{
struct adapter *padapter;
PSDIO_DATA psdio;
s32 err;
struct xmit_buf *xmitbuf = (struct xmit_buf *)mem;
padapter = pintfhdl->padapter;
psdio = &adapter_to_dvobj(padapter)->intf_data;
if (padapter->hw_init_completed == false) {
DBG_871X("%s [addr = 0x%x cnt =%d] padapter->hw_init_completed == false\n", __func__, addr, cnt);
return _FAIL;
}
cnt = _RND4(cnt);
HalSdioGetCmdAddr8723BSdio(padapter, addr, cnt >> 2, &addr);
if (cnt > psdio->block_transfer_len)
cnt = _RND(cnt, psdio->block_transfer_len);
err = sd_write(pintfhdl, addr, cnt, xmitbuf->pdata);
rtw_sctx_done_err(
&xmitbuf->sctx,
err ? RTW_SCTX_DONE_WRITE_PORT_ERR : RTW_SCTX_DONE_SUCCESS
);
if (err)
return _FAIL;
return _SUCCESS;
}
void sdio_set_intf_ops(struct adapter *padapter, struct _io_ops *pops)
{
pops->_read8 = &sdio_read8;
pops->_read16 = &sdio_read16;
pops->_read32 = &sdio_read32;
pops->_read_mem = &sdio_read_mem;
pops->_read_port = &sdio_read_port;
pops->_write8 = &sdio_write8;
pops->_write16 = &sdio_write16;
pops->_write32 = &sdio_write32;
pops->_writeN = &sdio_writeN;
pops->_write_mem = &sdio_write_mem;
pops->_write_port = &sdio_write_port;
pops->_sd_f0_read8 = sdio_f0_read8;
}
static s32 _sdio_local_read(
struct adapter *padapter,
u32 addr,
u32 cnt,
u8 *pbuf
)
{
struct intf_hdl *pintfhdl;
u8 bMacPwrCtrlOn;
s32 err;
u8 *ptmpbuf;
u32 n;
pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (false == bMacPwrCtrlOn) {
err = _sd_cmd52_read(pintfhdl, addr, cnt, pbuf);
return err;
}
n = RND4(cnt);
ptmpbuf = (u8 *)rtw_malloc(n);
if (!ptmpbuf)
return (-1);
err = _sd_read(pintfhdl, addr, n, ptmpbuf);
if (!err)
memcpy(pbuf, ptmpbuf, cnt);
kfree(ptmpbuf);
return err;
}
s32 sdio_local_read(
struct adapter *padapter,
u32 addr,
u32 cnt,
u8 *pbuf
)
{
struct intf_hdl *pintfhdl;
u8 bMacPwrCtrlOn;
s32 err;
u8 *ptmpbuf;
u32 n;
pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
(false == bMacPwrCtrlOn) ||
(true == adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
err = sd_cmd52_read(pintfhdl, addr, cnt, pbuf);
return err;
}
n = RND4(cnt);
ptmpbuf = (u8 *)rtw_malloc(n);
if (!ptmpbuf)
return (-1);
err = sd_read(pintfhdl, addr, n, ptmpbuf);
if (!err)
memcpy(pbuf, ptmpbuf, cnt);
kfree(ptmpbuf);
return err;
}
s32 sdio_local_write(
struct adapter *padapter,
u32 addr,
u32 cnt,
u8 *pbuf
)
{
struct intf_hdl *pintfhdl;
u8 bMacPwrCtrlOn;
s32 err;
u8 *ptmpbuf;
if (addr & 0x3)
DBG_8192C("%s, address must be 4 bytes alignment\n", __func__);
if (cnt & 0x3)
DBG_8192C("%s, size must be the multiple of 4\n", __func__);
pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (
(false == bMacPwrCtrlOn) ||
(true == adapter_to_pwrctl(padapter)->bFwCurrentInPSMode)
) {
err = sd_cmd52_write(pintfhdl, addr, cnt, pbuf);
return err;
}
ptmpbuf = (u8 *)rtw_malloc(cnt);
if (!ptmpbuf)
return (-1);
memcpy(ptmpbuf, pbuf, cnt);
err = sd_write(pintfhdl, addr, cnt, ptmpbuf);
kfree(ptmpbuf);
return err;
}
u8 SdioLocalCmd52Read1Byte(struct adapter *padapter, u32 addr)
{
u8 val = 0;
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
sd_cmd52_read(pintfhdl, addr, 1, &val);
return val;
}
static u16 SdioLocalCmd52Read2Byte(struct adapter *padapter, u32 addr)
{
__le16 val = 0;
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
sd_cmd52_read(pintfhdl, addr, 2, (u8 *)&val);
return le16_to_cpu(val);
}
static u32 SdioLocalCmd53Read4Byte(struct adapter *padapter, u32 addr)
{
u8 bMacPwrCtrlOn;
u32 val = 0;
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
__le32 le_tmp;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
rtw_hal_get_hwreg(padapter, HW_VAR_APFM_ON_MAC, &bMacPwrCtrlOn);
if (!bMacPwrCtrlOn || adapter_to_pwrctl(padapter)->bFwCurrentInPSMode) {
sd_cmd52_read(pintfhdl, addr, 4, (u8 *)&le_tmp);
val = le32_to_cpu(le_tmp);
} else {
val = sd_read32(pintfhdl, addr, NULL);
}
return val;
}
void SdioLocalCmd52Write1Byte(struct adapter *padapter, u32 addr, u8 v)
{
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
sd_cmd52_write(pintfhdl, addr, 1, &v);
}
static void SdioLocalCmd52Write4Byte(struct adapter *padapter, u32 addr, u32 v)
{
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
__le32 le_tmp;
HalSdioGetCmdAddr8723BSdio(padapter, SDIO_LOCAL_DEVICE_ID, addr, &addr);
le_tmp = cpu_to_le32(v);
sd_cmd52_write(pintfhdl, addr, 4, (u8 *)&le_tmp);
}
static s32 ReadInterrupt8723BSdio(struct adapter *padapter, u32 *phisr)
{
u32 hisr, himr;
u8 val8, hisr_len;
if (phisr == NULL)
return false;
himr = GET_HAL_DATA(padapter)->sdio_himr;
hisr_len = 0;
while (himr) {
hisr_len++;
himr >>= 8;
}
hisr = 0;
while (hisr_len != 0) {
hisr_len--;
val8 = SdioLocalCmd52Read1Byte(padapter, SDIO_REG_HISR+hisr_len);
hisr |= (val8 << (8*hisr_len));
}
*phisr = hisr;
return true;
}
void InitInterrupt8723BSdio(struct adapter *padapter)
{
struct hal_com_data *pHalData;
pHalData = GET_HAL_DATA(padapter);
pHalData->sdio_himr = (u32)( \
SDIO_HIMR_RX_REQUEST_MSK |
SDIO_HIMR_AVAL_MSK |
0);
}
void InitSysInterrupt8723BSdio(struct adapter *padapter)
{
struct hal_com_data *pHalData;
pHalData = GET_HAL_DATA(padapter);
pHalData->SysIntrMask = ( \
0);
}
void ClearInterrupt8723BSdio(struct adapter *padapter)
{
struct hal_com_data *pHalData;
u8 *clear;
if (true == padapter->bSurpriseRemoved)
return;
pHalData = GET_HAL_DATA(padapter);
clear = rtw_zmalloc(4);
*(__le32 *)clear = cpu_to_le32(pHalData->sdio_hisr & MASK_SDIO_HISR_CLEAR);
if (*(__le32 *)clear) {
sdio_local_write(padapter, SDIO_REG_HISR, 4, clear);
}
kfree(clear);
}
void EnableInterrupt8723BSdio(struct adapter *padapter)
{
struct hal_com_data *pHalData;
__le32 himr;
u32 tmp;
pHalData = GET_HAL_DATA(padapter);
himr = cpu_to_le32(pHalData->sdio_himr);
sdio_local_write(padapter, SDIO_REG_HIMR, 4, (u8 *)&himr);
RT_TRACE(
_module_hci_ops_c_,
_drv_notice_,
(
"%s: enable SDIO HIMR = 0x%08X\n",
__func__,
pHalData->sdio_himr
)
);
tmp = rtw_read32(padapter, REG_HSIMR);
rtw_write32(padapter, REG_HSIMR, tmp | pHalData->SysIntrMask);
RT_TRACE(
_module_hci_ops_c_,
_drv_notice_,
(
"%s: enable HSIMR = 0x%08X\n",
__func__,
pHalData->SysIntrMask
)
);
rtw_write8(padapter, REG_C2HEVT_CLEAR, C2H_EVT_HOST_CLOSE);
}
void DisableInterrupt8723BSdio(struct adapter *padapter)
{
__le32 himr;
himr = cpu_to_le32(SDIO_HIMR_DISABLED);
sdio_local_write(padapter, SDIO_REG_HIMR, 4, (u8 *)&himr);
}
u8 CheckIPSStatus(struct adapter *padapter)
{
DBG_871X(
"%s(): Read 0x100 = 0x%02x 0x86 = 0x%02x\n",
__func__,
rtw_read8(padapter, 0x100),
rtw_read8(padapter, 0x86)
);
if (rtw_read8(padapter, 0x100) == 0xEA)
return true;
else
return false;
}
static struct recv_buf *sd_recv_rxfifo(struct adapter *padapter, u32 size)
{
u32 readsize, ret;
u8 *preadbuf;
struct recv_priv *precvpriv;
struct recv_buf *precvbuf;
readsize = RND4(size);
precvpriv = &padapter->recvpriv;
precvbuf = rtw_dequeue_recvbuf(&precvpriv->free_recv_buf_queue);
if (precvbuf == NULL) {
DBG_871X_LEVEL(_drv_err_, "%s: alloc recvbuf FAIL!\n", __func__);
return NULL;
}
if (precvbuf->pskb == NULL) {
SIZE_PTR tmpaddr = 0;
SIZE_PTR alignment = 0;
precvbuf->pskb = rtw_skb_alloc(MAX_RECVBUF_SZ + RECVBUFF_ALIGN_SZ);
if (precvbuf->pskb) {
precvbuf->pskb->dev = padapter->pnetdev;
tmpaddr = (SIZE_PTR)precvbuf->pskb->data;
alignment = tmpaddr & (RECVBUFF_ALIGN_SZ-1);
skb_reserve(precvbuf->pskb, (RECVBUFF_ALIGN_SZ - alignment));
}
if (precvbuf->pskb == NULL) {
DBG_871X("%s: alloc_skb fail! read =%d\n", __func__, readsize);
return NULL;
}
}
preadbuf = precvbuf->pskb->data;
ret = sdio_read_port(&padapter->iopriv.intf, WLAN_RX0FF_DEVICE_ID, readsize, preadbuf);
if (ret == _FAIL) {
RT_TRACE(_module_hci_ops_os_c_, _drv_err_, ("%s: read port FAIL!\n", __func__));
return NULL;
}
precvbuf->len = size;
precvbuf->phead = precvbuf->pskb->head;
precvbuf->pdata = precvbuf->pskb->data;
skb_set_tail_pointer(precvbuf->pskb, size);
precvbuf->ptail = skb_tail_pointer(precvbuf->pskb);
precvbuf->pend = skb_end_pointer(precvbuf->pskb);
return precvbuf;
}
static void sd_rxhandler(struct adapter *padapter, struct recv_buf *precvbuf)
{
struct recv_priv *precvpriv;
struct __queue *ppending_queue;
precvpriv = &padapter->recvpriv;
ppending_queue = &precvpriv->recv_buf_pending_queue;
rtw_enqueue_recvbuf(precvbuf, ppending_queue);
tasklet_schedule(&precvpriv->recv_tasklet);
}
void sd_int_dpc(struct adapter *padapter)
{
struct hal_com_data *phal;
struct dvobj_priv *dvobj;
struct intf_hdl *pintfhdl = &padapter->iopriv.intf;
struct pwrctrl_priv *pwrctl;
phal = GET_HAL_DATA(padapter);
dvobj = adapter_to_dvobj(padapter);
pwrctl = dvobj_to_pwrctl(dvobj);
if (phal->sdio_hisr & SDIO_HISR_AVAL) {
u8 freepage[4];
_sdio_local_read(padapter, SDIO_REG_FREE_TXPG, 4, freepage);
up(&(padapter->xmitpriv.xmit_sema));
}
if (phal->sdio_hisr & SDIO_HISR_CPWM1) {
struct reportpwrstate_parm report;
u8 bcancelled;
_cancel_timer(&(pwrctl->pwr_rpwm_timer), &bcancelled);
report.state = SdioLocalCmd52Read1Byte(padapter, SDIO_REG_HCPWM1_8723B);
_set_workitem(&(pwrctl->cpwm_event));
}
if (phal->sdio_hisr & SDIO_HISR_TXERR) {
u8 *status;
u32 addr;
status = rtw_malloc(4);
if (status) {
addr = REG_TXDMA_STATUS;
HalSdioGetCmdAddr8723BSdio(padapter, WLAN_IOREG_DEVICE_ID, addr, &addr);
_sd_read(pintfhdl, addr, 4, status);
_sd_write(pintfhdl, addr, 4, status);
DBG_8192C("%s: SDIO_HISR_TXERR (0x%08x)\n", __func__, le32_to_cpu(*(u32 *)status));
kfree(status);
} else {
DBG_8192C("%s: SDIO_HISR_TXERR, but can't allocate memory to read status!\n", __func__);
}
}
if (phal->sdio_hisr & SDIO_HISR_TXBCNOK) {
DBG_8192C("%s: SDIO_HISR_TXBCNOK\n", __func__);
}
if (phal->sdio_hisr & SDIO_HISR_TXBCNERR) {
DBG_8192C("%s: SDIO_HISR_TXBCNERR\n", __func__);
}
#ifndef CONFIG_C2H_PACKET_EN
if (phal->sdio_hisr & SDIO_HISR_C2HCMD) {
struct c2h_evt_hdr_88xx *c2h_evt;
DBG_8192C("%s: C2H Command\n", __func__);
c2h_evt = (struct c2h_evt_hdr_88xx *)rtw_zmalloc(16);
if (c2h_evt != NULL) {
if (rtw_hal_c2h_evt_read(padapter, (u8 *)c2h_evt) == _SUCCESS) {
if (c2h_id_filter_ccx_8723b((u8 *)c2h_evt)) {
rtw_hal_c2h_handler(padapter, (u8 *)c2h_evt);
kfree((u8 *)c2h_evt);
} else {
rtw_c2h_wk_cmd(padapter, (u8 *)c2h_evt);
}
}
} else {
if (rtw_cbuf_push(padapter->evtpriv.c2h_queue, (void *)NULL) != _SUCCESS)
DBG_871X("%s rtw_cbuf_push fail\n", __func__);
_set_workitem(&padapter->evtpriv.c2h_wk);
}
}
#endif
if (phal->sdio_hisr & SDIO_HISR_RXFOVW) {
DBG_8192C("%s: Rx Overflow\n", __func__);
}
if (phal->sdio_hisr & SDIO_HISR_RXERR) {
DBG_8192C("%s: Rx Error\n", __func__);
}
if (phal->sdio_hisr & SDIO_HISR_RX_REQUEST) {
struct recv_buf *precvbuf;
int alloc_fail_time = 0;
u32 hisr;
phal->sdio_hisr ^= SDIO_HISR_RX_REQUEST;
do {
phal->SdioRxFIFOSize = SdioLocalCmd52Read2Byte(padapter, SDIO_REG_RX0_REQ_LEN);
if (phal->SdioRxFIFOSize != 0) {
precvbuf = sd_recv_rxfifo(padapter, phal->SdioRxFIFOSize);
if (precvbuf)
sd_rxhandler(padapter, precvbuf);
else {
alloc_fail_time++;
DBG_871X("precvbuf is Null for %d times because alloc memory failed\n", alloc_fail_time);
if (alloc_fail_time >= 10)
break;
}
phal->SdioRxFIFOSize = 0;
} else
break;
hisr = 0;
ReadInterrupt8723BSdio(padapter, &hisr);
hisr &= SDIO_HISR_RX_REQUEST;
if (!hisr)
break;
} while (1);
if (alloc_fail_time == 10)
DBG_871X("exit because alloc memory failed more than 10 times\n");
}
}
void sd_int_hdl(struct adapter *padapter)
{
struct hal_com_data *phal;
if (
(padapter->bDriverStopped == true) ||
(padapter->bSurpriseRemoved == true)
)
return;
phal = GET_HAL_DATA(padapter);
phal->sdio_hisr = 0;
ReadInterrupt8723BSdio(padapter, &phal->sdio_hisr);
if (phal->sdio_hisr & phal->sdio_himr) {
u32 v32;
phal->sdio_hisr &= phal->sdio_himr;
v32 = phal->sdio_hisr & MASK_SDIO_HISR_CLEAR;
if (v32) {
SdioLocalCmd52Write4Byte(padapter, SDIO_REG_HISR, v32);
}
sd_int_dpc(padapter);
} else {
RT_TRACE(_module_hci_ops_c_, _drv_err_,
("%s: HISR(0x%08x) and HIMR(0x%08x) not match!\n",
__func__, phal->sdio_hisr, phal->sdio_himr));
}
}
u8 HalQueryTxBufferStatus8723BSdio(struct adapter *padapter)
{
struct hal_com_data *phal;
u32 NumOfFreePage;
phal = GET_HAL_DATA(padapter);
NumOfFreePage = SdioLocalCmd53Read4Byte(padapter, SDIO_REG_FREE_TXPG);
memcpy(phal->SdioTxFIFOFreePage, &NumOfFreePage, 4);
RT_TRACE(_module_hci_ops_c_, _drv_notice_,
("%s: Free page for HIQ(%#x), MIDQ(%#x), LOWQ(%#x), PUBQ(%#x)\n",
__func__,
phal->SdioTxFIFOFreePage[HI_QUEUE_IDX],
phal->SdioTxFIFOFreePage[MID_QUEUE_IDX],
phal->SdioTxFIFOFreePage[LOW_QUEUE_IDX],
phal->SdioTxFIFOFreePage[PUBLIC_QUEUE_IDX]));
return true;
}
u8 HalQueryTxOQTBufferStatus8723BSdio(struct adapter *padapter)
{
struct hal_com_data *pHalData = GET_HAL_DATA(padapter);
pHalData->SdioTxOQTFreeSpace = SdioLocalCmd52Read1Byte(padapter, SDIO_REG_OQT_FREE_PG);
return true;
}
u8 RecvOnePkt(struct adapter *padapter, u32 size)
{
struct recv_buf *precvbuf;
struct dvobj_priv *psddev;
PSDIO_DATA psdio_data;
struct sdio_func *func;
u8 res = false;
DBG_871X("+%s: size: %d+\n", __func__, size);
if (padapter == NULL) {
DBG_871X(KERN_ERR "%s: padapter is NULL!\n", __func__);
return false;
}
psddev = adapter_to_dvobj(padapter);
psdio_data = &psddev->intf_data;
func = psdio_data->func;
if (size) {
sdio_claim_host(func);
precvbuf = sd_recv_rxfifo(padapter, size);
if (precvbuf) {
sd_rxhandler(padapter, precvbuf);
res = true;
} else {
res = false;
}
sdio_release_host(func);
}
DBG_871X("-%s-\n", __func__);
return res;
}
