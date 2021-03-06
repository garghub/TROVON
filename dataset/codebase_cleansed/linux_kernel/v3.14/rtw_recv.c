void _rtw_init_sta_recv_priv(struct sta_recv_priv *psta_recvpriv)
{
_func_enter_;
_rtw_memset((u8 *)psta_recvpriv, 0, sizeof (struct sta_recv_priv));
spin_lock_init(&psta_recvpriv->lock);
_rtw_init_queue(&psta_recvpriv->defrag_q);
_func_exit_;
}
int _rtw_init_recv_priv(struct recv_priv *precvpriv, struct adapter *padapter)
{
int i;
union recv_frame *precvframe;
int res = _SUCCESS;
_func_enter_;
spin_lock_init(&precvpriv->lock);
_rtw_init_queue(&precvpriv->free_recv_queue);
_rtw_init_queue(&precvpriv->recv_pending_queue);
_rtw_init_queue(&precvpriv->uc_swdec_pending_queue);
precvpriv->adapter = padapter;
precvpriv->free_recvframe_cnt = NR_RECVFRAME;
rtw_os_recv_resource_init(precvpriv, padapter);
precvpriv->pallocated_frame_buf = rtw_zvmalloc(NR_RECVFRAME * sizeof(union recv_frame) + RXFRAME_ALIGN_SZ);
if (precvpriv->pallocated_frame_buf == NULL) {
res = _FAIL;
goto exit;
}
precvpriv->precv_frame_buf = (u8 *)N_BYTE_ALIGMENT((size_t)(precvpriv->pallocated_frame_buf), RXFRAME_ALIGN_SZ);
precvframe = (union recv_frame *)precvpriv->precv_frame_buf;
for (i = 0; i < NR_RECVFRAME; i++) {
_rtw_init_listhead(&(precvframe->u.list));
rtw_list_insert_tail(&(precvframe->u.list), &(precvpriv->free_recv_queue.queue));
res = rtw_os_recv_resource_alloc(padapter, precvframe);
precvframe->u.hdr.len = 0;
precvframe->u.hdr.adapter = padapter;
precvframe++;
}
precvpriv->rx_pending_cnt = 1;
sema_init(&precvpriv->allrxreturnevt, 0);
res = rtw_hal_init_recv_priv(padapter);
_init_timer(&precvpriv->signal_stat_timer, padapter->pnetdev, RTW_TIMER_HDL_NAME(signal_stat), padapter);
precvpriv->signal_stat_sampling_interval = 1000;
rtw_set_signal_stat_timer(precvpriv);
exit:
_func_exit_;
return res;
}
void _rtw_free_recv_priv (struct recv_priv *precvpriv)
{
struct adapter *padapter = precvpriv->adapter;
_func_enter_;
rtw_free_uc_swdec_pending_queue(padapter);
rtw_os_recv_resource_free(precvpriv);
if (precvpriv->pallocated_frame_buf) {
rtw_vmfree(precvpriv->pallocated_frame_buf, NR_RECVFRAME * sizeof(union recv_frame) + RXFRAME_ALIGN_SZ);
}
rtw_hal_free_recv_priv(padapter);
_func_exit_;
}
union recv_frame *_rtw_alloc_recvframe (struct __queue *pfree_recv_queue)
{
union recv_frame *precvframe;
struct list_head *plist, *phead;
struct adapter *padapter;
struct recv_priv *precvpriv;
_func_enter_;
if (_rtw_queue_empty(pfree_recv_queue)) {
precvframe = NULL;
} else {
phead = get_list_head(pfree_recv_queue);
plist = get_next(phead);
precvframe = LIST_CONTAINOR(plist, union recv_frame, u);
rtw_list_delete(&precvframe->u.hdr.list);
padapter = precvframe->u.hdr.adapter;
if (padapter != NULL) {
precvpriv = &padapter->recvpriv;
if (pfree_recv_queue == &precvpriv->free_recv_queue)
precvpriv->free_recvframe_cnt--;
}
}
_func_exit_;
return precvframe;
}
union recv_frame *rtw_alloc_recvframe (struct __queue *pfree_recv_queue)
{
union recv_frame *precvframe;
spin_lock_bh(&pfree_recv_queue->lock);
precvframe = _rtw_alloc_recvframe(pfree_recv_queue);
spin_unlock_bh(&pfree_recv_queue->lock);
return precvframe;
}
void rtw_init_recvframe(union recv_frame *precvframe, struct recv_priv *precvpriv)
{
_rtw_init_listhead(&precvframe->u.hdr.list);
precvframe->u.hdr.len = 0;
}
int rtw_free_recvframe(union recv_frame *precvframe, struct __queue *pfree_recv_queue)
{
struct adapter *padapter;
struct recv_priv *precvpriv;
_func_enter_;
if (!precvframe)
return _FAIL;
padapter = precvframe->u.hdr.adapter;
precvpriv = &padapter->recvpriv;
if (precvframe->u.hdr.pkt) {
dev_kfree_skb_any(precvframe->u.hdr.pkt);
precvframe->u.hdr.pkt = NULL;
}
spin_lock_bh(&pfree_recv_queue->lock);
rtw_list_delete(&(precvframe->u.hdr.list));
precvframe->u.hdr.len = 0;
rtw_list_insert_tail(&(precvframe->u.hdr.list), get_list_head(pfree_recv_queue));
if (padapter != NULL) {
if (pfree_recv_queue == &precvpriv->free_recv_queue)
precvpriv->free_recvframe_cnt++;
}
spin_unlock_bh(&pfree_recv_queue->lock);
_func_exit_;
return _SUCCESS;
}
int _rtw_enqueue_recvframe(union recv_frame *precvframe, struct __queue *queue)
{
struct adapter *padapter = precvframe->u.hdr.adapter;
struct recv_priv *precvpriv = &padapter->recvpriv;
_func_enter_;
rtw_list_delete(&(precvframe->u.hdr.list));
rtw_list_insert_tail(&(precvframe->u.hdr.list), get_list_head(queue));
if (padapter != NULL) {
if (queue == &precvpriv->free_recv_queue)
precvpriv->free_recvframe_cnt++;
}
_func_exit_;
return _SUCCESS;
}
int rtw_enqueue_recvframe(union recv_frame *precvframe, struct __queue *queue)
{
int ret;
spin_lock_bh(&queue->lock);
ret = _rtw_enqueue_recvframe(precvframe, queue);
spin_unlock_bh(&queue->lock);
return ret;
}
void rtw_free_recvframe_queue(struct __queue *pframequeue, struct __queue *pfree_recv_queue)
{
union recv_frame *precvframe;
struct list_head *plist, *phead;
_func_enter_;
spin_lock(&pframequeue->lock);
phead = get_list_head(pframequeue);
plist = get_next(phead);
while (rtw_end_of_queue_search(phead, plist) == false) {
precvframe = LIST_CONTAINOR(plist, union recv_frame, u);
plist = get_next(plist);
rtw_free_recvframe(precvframe, pfree_recv_queue);
}
spin_unlock(&pframequeue->lock);
_func_exit_;
}
u32 rtw_free_uc_swdec_pending_queue(struct adapter *adapter)
{
u32 cnt = 0;
union recv_frame *pending_frame;
while ((pending_frame = rtw_alloc_recvframe(&adapter->recvpriv.uc_swdec_pending_queue))) {
rtw_free_recvframe(pending_frame, &adapter->recvpriv.free_recv_queue);
DBG_88E("%s: dequeue uc_swdec_pending_queue\n", __func__);
cnt++;
}
return cnt;
}
int rtw_enqueue_recvbuf_to_head(struct recv_buf *precvbuf, struct __queue *queue)
{
spin_lock_bh(&queue->lock);
rtw_list_delete(&precvbuf->list);
rtw_list_insert_head(&precvbuf->list, get_list_head(queue));
spin_unlock_bh(&queue->lock);
return _SUCCESS;
}
int rtw_enqueue_recvbuf(struct recv_buf *precvbuf, struct __queue *queue)
{
unsigned long irqL;
spin_lock_irqsave(&queue->lock, irqL);
rtw_list_delete(&precvbuf->list);
rtw_list_insert_tail(&precvbuf->list, get_list_head(queue));
spin_unlock_irqrestore(&queue->lock, irqL);
return _SUCCESS;
}
struct recv_buf *rtw_dequeue_recvbuf (struct __queue *queue)
{
unsigned long irqL;
struct recv_buf *precvbuf;
struct list_head *plist, *phead;
spin_lock_irqsave(&queue->lock, irqL);
if (_rtw_queue_empty(queue)) {
precvbuf = NULL;
} else {
phead = get_list_head(queue);
plist = get_next(phead);
precvbuf = LIST_CONTAINOR(plist, struct recv_buf, list);
rtw_list_delete(&precvbuf->list);
}
spin_unlock_irqrestore(&queue->lock, irqL);
return precvbuf;
}
static int recvframe_chkmic(struct adapter *adapter, union recv_frame *precvframe)
{
int i, res = _SUCCESS;
u32 datalen;
u8 miccode[8];
u8 bmic_err = false, brpt_micerror = true;
u8 *pframe, *payload, *pframemic;
u8 *mickey;
struct sta_info *stainfo;
struct rx_pkt_attrib *prxattrib = &precvframe->u.hdr.attrib;
struct security_priv *psecuritypriv = &adapter->securitypriv;
struct mlme_ext_priv *pmlmeext = &adapter->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
_func_enter_;
stainfo = rtw_get_stainfo(&adapter->stapriv, &prxattrib->ta[0]);
if (prxattrib->encrypt == _TKIP_) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n recvframe_chkmic:prxattrib->encrypt==_TKIP_\n"));
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n recvframe_chkmic:da=0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x\n",
prxattrib->ra[0], prxattrib->ra[1], prxattrib->ra[2], prxattrib->ra[3], prxattrib->ra[4], prxattrib->ra[5]));
if (stainfo != NULL) {
if (IS_MCAST(prxattrib->ra)) {
mickey = &psecuritypriv->dot118021XGrprxmickey[prxattrib->key_index].skey[0];
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n recvframe_chkmic: bcmc key\n"));
if (!psecuritypriv) {
res = _FAIL;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("\n recvframe_chkmic:didn't install group key!!!!!!!!!!\n"));
DBG_88E("\n recvframe_chkmic:didn't install group key!!!!!!!!!!\n");
goto exit;
}
} else {
mickey = &stainfo->dot11tkiprxmickey.skey[0];
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("\n recvframe_chkmic: unicast key\n"));
}
datalen = precvframe->u.hdr.len-prxattrib->hdrlen-prxattrib->iv_len-prxattrib->icv_len-8;
pframe = precvframe->u.hdr.rx_data;
payload = pframe+prxattrib->hdrlen+prxattrib->iv_len;
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n prxattrib->iv_len=%d prxattrib->icv_len=%d\n", prxattrib->iv_len, prxattrib->icv_len));
rtw_seccalctkipmic(mickey, pframe, payload, datalen, &miccode[0],
(unsigned char)prxattrib->priority);
pframemic = payload+datalen;
bmic_err = false;
for (i = 0; i < 8; i++) {
if (miccode[i] != *(pframemic+i)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_,
("recvframe_chkmic:miccode[%d](%02x)!=*(pframemic+%d)(%02x) ",
i, miccode[i], i, *(pframemic+i)));
bmic_err = true;
}
}
if (bmic_err) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_,
("\n *(pframemic-8)-*(pframemic-1)=0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x\n",
*(pframemic-8), *(pframemic-7), *(pframemic-6),
*(pframemic-5), *(pframemic-4), *(pframemic-3),
*(pframemic-2), *(pframemic-1)));
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_,
("\n *(pframemic-16)-*(pframemic-9)=0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x\n",
*(pframemic-16), *(pframemic-15), *(pframemic-14),
*(pframemic-13), *(pframemic-12), *(pframemic-11),
*(pframemic-10), *(pframemic-9)));
{
uint i;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("\n ======demp packet (len=%d)======\n", precvframe->u.hdr.len));
for (i = 0; i < precvframe->u.hdr.len; i = i+8) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x:0x%02x",
*(precvframe->u.hdr.rx_data+i), *(precvframe->u.hdr.rx_data+i+1),
*(precvframe->u.hdr.rx_data+i+2), *(precvframe->u.hdr.rx_data+i+3),
*(precvframe->u.hdr.rx_data+i+4), *(precvframe->u.hdr.rx_data+i+5),
*(precvframe->u.hdr.rx_data+i+6), *(precvframe->u.hdr.rx_data+i+7)));
}
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("\n ====== demp packet end [len=%d]======\n", precvframe->u.hdr.len));
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("\n hrdlen=%d,\n", prxattrib->hdrlen));
}
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_,
("ra=0x%.2x 0x%.2x 0x%.2x 0x%.2x 0x%.2x 0x%.2x psecuritypriv->binstallGrpkey=%d ",
prxattrib->ra[0], prxattrib->ra[1], prxattrib->ra[2],
prxattrib->ra[3], prxattrib->ra[4], prxattrib->ra[5], psecuritypriv->binstallGrpkey));
if ((IS_MCAST(prxattrib->ra) == true) && (prxattrib->key_index != pmlmeinfo->key_index))
brpt_micerror = false;
if ((prxattrib->bdecrypted) && (brpt_micerror)) {
rtw_handle_tkip_mic_err(adapter, (u8)IS_MCAST(prxattrib->ra));
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" mic error :prxattrib->bdecrypted=%d ", prxattrib->bdecrypted));
DBG_88E(" mic error :prxattrib->bdecrypted=%d\n", prxattrib->bdecrypted);
} else {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" mic error :prxattrib->bdecrypted=%d ", prxattrib->bdecrypted));
DBG_88E(" mic error :prxattrib->bdecrypted=%d\n", prxattrib->bdecrypted);
}
res = _FAIL;
} else {
if ((!psecuritypriv->bcheck_grpkey) && (IS_MCAST(prxattrib->ra))) {
psecuritypriv->bcheck_grpkey = true;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("psecuritypriv->bcheck_grpkey = true"));
}
}
} else {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("recvframe_chkmic: rtw_get_stainfo==NULL!!!\n"));
}
recvframe_pull_tail(precvframe, 8);
}
exit:
_func_exit_;
return res;
}
static union recv_frame *decryptor(struct adapter *padapter, union recv_frame *precv_frame)
{
struct rx_pkt_attrib *prxattrib = &precv_frame->u.hdr.attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
union recv_frame *return_packet = precv_frame;
u32 res = _SUCCESS;
_func_enter_;
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("prxstat->decrypted=%x prxattrib->encrypt=0x%03x\n", prxattrib->bdecrypted, prxattrib->encrypt));
if (prxattrib->encrypt > 0) {
u8 *iv = precv_frame->u.hdr.rx_data+prxattrib->hdrlen;
prxattrib->key_index = (((iv[3])>>6)&0x3);
if (prxattrib->key_index > WEP_KEYS) {
DBG_88E("prxattrib->key_index(%d)>WEP_KEYS\n", prxattrib->key_index);
switch (prxattrib->encrypt) {
case _WEP40_:
case _WEP104_:
prxattrib->key_index = psecuritypriv->dot11PrivacyKeyIndex;
break;
case _TKIP_:
case _AES_:
default:
prxattrib->key_index = psecuritypriv->dot118021XGrpKeyid;
break;
}
}
}
if ((prxattrib->encrypt > 0) && ((prxattrib->bdecrypted == 0) || (psecuritypriv->sw_decrypt))) {
psecuritypriv->hw_decrypted = false;
switch (prxattrib->encrypt) {
case _WEP40_:
case _WEP104_:
rtw_wep_decrypt(padapter, (u8 *)precv_frame);
break;
case _TKIP_:
res = rtw_tkip_decrypt(padapter, (u8 *)precv_frame);
break;
case _AES_:
res = rtw_aes_decrypt(padapter, (u8 *)precv_frame);
break;
default:
break;
}
} else if (prxattrib->bdecrypted == 1 && prxattrib->encrypt > 0 &&
(psecuritypriv->busetkipkey == 1 || prxattrib->encrypt != _TKIP_))
psecuritypriv->hw_decrypted = true;
if (res == _FAIL) {
rtw_free_recvframe(return_packet, &padapter->recvpriv.free_recv_queue);
return_packet = NULL;
}
_func_exit_;
return return_packet;
}
static union recv_frame *portctrl(struct adapter *adapter, union recv_frame *precv_frame)
{
u8 *psta_addr = NULL, *ptr;
uint auth_alg;
struct recv_frame_hdr *pfhdr;
struct sta_info *psta;
struct sta_priv *pstapriv;
union recv_frame *prtnframe;
u16 ether_type = 0;
u16 eapol_type = 0x888e;
struct rx_pkt_attrib *pattrib;
__be16 be_tmp;
_func_enter_;
pstapriv = &adapter->stapriv;
psta = rtw_get_stainfo(pstapriv, psta_addr);
auth_alg = adapter->securitypriv.dot11AuthAlgrthm;
ptr = get_recvframe_data(precv_frame);
pfhdr = &precv_frame->u.hdr;
pattrib = &pfhdr->attrib;
psta_addr = pattrib->ta;
prtnframe = NULL;
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("########portctrl:adapter->securitypriv.dot11AuthAlgrthm=%d\n", adapter->securitypriv.dot11AuthAlgrthm));
if (auth_alg == 2) {
if ((psta != NULL) && (psta->ieee8021x_blocked)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("########portctrl:psta->ieee8021x_blocked==1\n"));
prtnframe = precv_frame;
ptr = ptr+pfhdr->attrib.hdrlen+pfhdr->attrib.iv_len+LLC_HEADER_SIZE;
memcpy(&be_tmp, ptr, 2);
ether_type = ntohs(be_tmp);
if (ether_type == eapol_type) {
prtnframe = precv_frame;
} else {
rtw_free_recvframe(precv_frame, &adapter->recvpriv.free_recv_queue);
prtnframe = NULL;
}
} else {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("########portctrl:psta->ieee8021x_blocked==0\n"));
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("portctrl:precv_frame->hdr.attrib.privacy=%x\n", precv_frame->u.hdr.attrib.privacy));
if (pattrib->bdecrypted == 0)
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("portctrl:prxstat->decrypted=%x\n", pattrib->bdecrypted));
prtnframe = precv_frame;
if (ether_type == eapol_type) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("########portctrl:ether_type==0x888e\n"));
prtnframe = precv_frame;
} else {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("########portctrl:ether_type=0x%04x\n", ether_type));
}
}
} else {
prtnframe = precv_frame;
}
_func_exit_;
return prtnframe;
}
static int recv_decache(union recv_frame *precv_frame, u8 bretry, struct stainfo_rxcache *prxcache)
{
int tid = precv_frame->u.hdr.attrib.priority;
u16 seq_ctrl = ((precv_frame->u.hdr.attrib.seq_num&0xffff) << 4) |
(precv_frame->u.hdr.attrib.frag_num & 0xf);
_func_enter_;
if (tid > 15) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("recv_decache, (tid>15)! seq_ctrl=0x%x, tid=0x%x\n", seq_ctrl, tid));
return _FAIL;
}
if (1) {
if (seq_ctrl == prxcache->tid_rxseq[tid]) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("recv_decache, seq_ctrl=0x%x, tid=0x%x, tid_rxseq=0x%x\n", seq_ctrl, tid, prxcache->tid_rxseq[tid]));
return _FAIL;
}
}
prxcache->tid_rxseq[tid] = seq_ctrl;
_func_exit_;
return _SUCCESS;
}
void process_pwrbit_data(struct adapter *padapter, union recv_frame *precv_frame)
{
#ifdef CONFIG_88EU_AP_MODE
unsigned char pwrbit;
u8 *ptr = precv_frame->u.hdr.rx_data;
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct sta_priv *pstapriv = &padapter->stapriv;
struct sta_info *psta = NULL;
psta = rtw_get_stainfo(pstapriv, pattrib->src);
pwrbit = GetPwrMgt(ptr);
if (psta) {
if (pwrbit) {
if (!(psta->state & WIFI_SLEEP_STATE))
stop_sta_xmit(padapter, psta);
} else {
if (psta->state & WIFI_SLEEP_STATE)
wakeup_sta_to_xmit(padapter, psta);
}
}
#endif
}
static void process_wmmps_data(struct adapter *padapter, union recv_frame *precv_frame)
{
#ifdef CONFIG_88EU_AP_MODE
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct sta_priv *pstapriv = &padapter->stapriv;
struct sta_info *psta = NULL;
psta = rtw_get_stainfo(pstapriv, pattrib->src);
if (!psta)
return;
if (!psta->qos_option)
return;
if (!(psta->qos_info&0xf))
return;
if (psta->state&WIFI_SLEEP_STATE) {
u8 wmmps_ac = 0;
switch (pattrib->priority) {
case 1:
case 2:
wmmps_ac = psta->uapsd_bk&BIT(1);
break;
case 4:
case 5:
wmmps_ac = psta->uapsd_vi&BIT(1);
break;
case 6:
case 7:
wmmps_ac = psta->uapsd_vo&BIT(1);
break;
case 0:
case 3:
default:
wmmps_ac = psta->uapsd_be&BIT(1);
break;
}
if (wmmps_ac) {
if (psta->sleepq_ac_len > 0) {
xmit_delivery_enabled_frames(padapter, psta);
} else {
issue_qos_nulldata(padapter, psta->hwaddr, (u16)pattrib->priority, 0, 0);
}
}
}
#endif
}
static void count_rx_stats(struct adapter *padapter, union recv_frame *prframe, struct sta_info *sta)
{
int sz;
struct sta_info *psta = NULL;
struct stainfo_stats *pstats = NULL;
struct rx_pkt_attrib *pattrib = &prframe->u.hdr.attrib;
struct recv_priv *precvpriv = &padapter->recvpriv;
sz = get_recvframe_len(prframe);
precvpriv->rx_bytes += sz;
padapter->mlmepriv.LinkDetectInfo.NumRxOkInPeriod++;
if ((!MacAddr_isBcst(pattrib->dst)) && (!IS_MCAST(pattrib->dst)))
padapter->mlmepriv.LinkDetectInfo.NumRxUnicastOkInPeriod++;
if (sta)
psta = sta;
else
psta = prframe->u.hdr.psta;
if (psta) {
pstats = &psta->sta_stats;
pstats->rx_data_pkts++;
pstats->rx_bytes += sz;
}
}
int sta2sta_data_frame(struct adapter *adapter, union recv_frame *precv_frame, struct sta_info **psta)
{
u8 *ptr = precv_frame->u.hdr.rx_data;
int ret = _SUCCESS;
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct sta_priv *pstapriv = &adapter->stapriv;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
u8 *mybssid = get_bssid(pmlmepriv);
u8 *myhwaddr = myid(&adapter->eeprompriv);
u8 *sta_addr = NULL;
int bmcast = IS_MCAST(pattrib->dst);
_func_enter_;
if ((check_fwstate(pmlmepriv, WIFI_ADHOC_STATE) == true) ||
(check_fwstate(pmlmepriv, WIFI_ADHOC_MASTER_STATE) == true)) {
if (_rtw_memcmp(myhwaddr, pattrib->src, ETH_ALEN)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" SA==myself\n"));
ret = _FAIL;
goto exit;
}
if ((!_rtw_memcmp(myhwaddr, pattrib->dst, ETH_ALEN)) && (!bmcast)) {
ret = _FAIL;
goto exit;
}
if (_rtw_memcmp(pattrib->bssid, "\x0\x0\x0\x0\x0\x0", ETH_ALEN) ||
_rtw_memcmp(mybssid, "\x0\x0\x0\x0\x0\x0", ETH_ALEN) ||
!_rtw_memcmp(pattrib->bssid, mybssid, ETH_ALEN)) {
ret = _FAIL;
goto exit;
}
sta_addr = pattrib->src;
} else if (check_fwstate(pmlmepriv, WIFI_STATION_STATE)) {
if (!_rtw_memcmp(pattrib->bssid, pattrib->src, ETH_ALEN)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("bssid!=TA under STATION_MODE; drop pkt\n"));
ret = _FAIL;
goto exit;
}
sta_addr = pattrib->bssid;
} else if (check_fwstate(pmlmepriv, WIFI_AP_STATE)) {
if (bmcast) {
if (!IS_MCAST(pattrib->bssid)) {
ret = _FAIL;
goto exit;
}
} else {
if (!_rtw_memcmp(pattrib->bssid, pattrib->dst, ETH_ALEN)) {
ret = _FAIL;
goto exit;
}
sta_addr = pattrib->src;
}
} else if (check_fwstate(pmlmepriv, WIFI_MP_STATE)) {
memcpy(pattrib->dst, GetAddr1Ptr(ptr), ETH_ALEN);
memcpy(pattrib->src, GetAddr2Ptr(ptr), ETH_ALEN);
memcpy(pattrib->bssid, GetAddr3Ptr(ptr), ETH_ALEN);
memcpy(pattrib->ra, pattrib->dst, ETH_ALEN);
memcpy(pattrib->ta, pattrib->src, ETH_ALEN);
sta_addr = mybssid;
} else {
ret = _FAIL;
}
if (bmcast)
*psta = rtw_get_bcmc_stainfo(adapter);
else
*psta = rtw_get_stainfo(pstapriv, sta_addr);
if (*psta == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("can't get psta under sta2sta_data_frame ; drop pkt\n"));
if (adapter->registrypriv.mp_mode == 1) {
if (check_fwstate(pmlmepriv, WIFI_MP_STATE) == true)
adapter->mppriv.rx_pktloss++;
}
ret = _FAIL;
goto exit;
}
exit:
_func_exit_;
return ret;
}
static int ap2sta_data_frame (
struct adapter *adapter,
union recv_frame *precv_frame,
struct sta_info **psta)
{
u8 *ptr = precv_frame->u.hdr.rx_data;
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
int ret = _SUCCESS;
struct sta_priv *pstapriv = &adapter->stapriv;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
u8 *mybssid = get_bssid(pmlmepriv);
u8 *myhwaddr = myid(&adapter->eeprompriv);
int bmcast = IS_MCAST(pattrib->dst);
_func_enter_;
if ((check_fwstate(pmlmepriv, WIFI_STATION_STATE) == true) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true ||
check_fwstate(pmlmepriv, _FW_UNDER_LINKING))) {
if (_rtw_memcmp(myhwaddr, pattrib->src, ETH_ALEN)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" SA==myself\n"));
ret = _FAIL;
goto exit;
}
if ((!_rtw_memcmp(myhwaddr, pattrib->dst, ETH_ALEN)) && (!bmcast)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_,
(" ap2sta_data_frame: compare DA fail; DA=%pM\n", (pattrib->dst)));
ret = _FAIL;
goto exit;
}
if (_rtw_memcmp(pattrib->bssid, "\x0\x0\x0\x0\x0\x0", ETH_ALEN) ||
_rtw_memcmp(mybssid, "\x0\x0\x0\x0\x0\x0", ETH_ALEN) ||
(!_rtw_memcmp(pattrib->bssid, mybssid, ETH_ALEN))) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_,
(" ap2sta_data_frame: compare BSSID fail ; BSSID=%pM\n", (pattrib->bssid)));
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("mybssid=%pM\n", (mybssid)));
if (!bmcast) {
DBG_88E("issue_deauth to the nonassociated ap=%pM for the reason(7)\n", (pattrib->bssid));
issue_deauth(adapter, pattrib->bssid, WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA);
}
ret = _FAIL;
goto exit;
}
if (bmcast)
*psta = rtw_get_bcmc_stainfo(adapter);
else
*psta = rtw_get_stainfo(pstapriv, pattrib->bssid);
if (*psta == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("ap2sta: can't get psta under STATION_MODE ; drop pkt\n"));
ret = _FAIL;
goto exit;
}
if (GetFrameSubType(ptr) & BIT(6)) {
count_rx_stats(adapter, precv_frame, *psta);
ret = RTW_RX_HANDLED;
goto exit;
}
} else if ((check_fwstate(pmlmepriv, WIFI_MP_STATE) == true) &&
(check_fwstate(pmlmepriv, _FW_LINKED) == true)) {
memcpy(pattrib->dst, GetAddr1Ptr(ptr), ETH_ALEN);
memcpy(pattrib->src, GetAddr2Ptr(ptr), ETH_ALEN);
memcpy(pattrib->bssid, GetAddr3Ptr(ptr), ETH_ALEN);
memcpy(pattrib->ra, pattrib->dst, ETH_ALEN);
memcpy(pattrib->ta, pattrib->src, ETH_ALEN);
memcpy(pattrib->bssid, mybssid, ETH_ALEN);
*psta = rtw_get_stainfo(pstapriv, pattrib->bssid);
if (*psta == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("can't get psta under MP_MODE ; drop pkt\n"));
ret = _FAIL;
goto exit;
}
} else if (check_fwstate(pmlmepriv, WIFI_AP_STATE)) {
ret = RTW_RX_HANDLED;
goto exit;
} else {
if (_rtw_memcmp(myhwaddr, pattrib->dst, ETH_ALEN) && (!bmcast)) {
*psta = rtw_get_stainfo(pstapriv, pattrib->bssid);
if (*psta == NULL) {
DBG_88E("issue_deauth to the ap =%pM for the reason(7)\n", (pattrib->bssid));
issue_deauth(adapter, pattrib->bssid, WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA);
}
}
ret = _FAIL;
}
exit:
_func_exit_;
return ret;
}
static int sta2ap_data_frame(struct adapter *adapter,
union recv_frame *precv_frame,
struct sta_info **psta)
{
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct sta_priv *pstapriv = &adapter->stapriv;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
u8 *ptr = precv_frame->u.hdr.rx_data;
unsigned char *mybssid = get_bssid(pmlmepriv);
int ret = _SUCCESS;
_func_enter_;
if (check_fwstate(pmlmepriv, WIFI_AP_STATE) == true) {
if (!_rtw_memcmp(pattrib->bssid, mybssid, ETH_ALEN)) {
ret = _FAIL;
goto exit;
}
*psta = rtw_get_stainfo(pstapriv, pattrib->src);
if (*psta == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("can't get psta under AP_MODE; drop pkt\n"));
DBG_88E("issue_deauth to sta=%pM for the reason(7)\n", (pattrib->src));
issue_deauth(adapter, pattrib->src, WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA);
ret = RTW_RX_HANDLED;
goto exit;
}
process_pwrbit_data(adapter, precv_frame);
if ((GetFrameSubType(ptr) & WIFI_QOS_DATA_TYPE) == WIFI_QOS_DATA_TYPE) {
process_wmmps_data(adapter, precv_frame);
}
if (GetFrameSubType(ptr) & BIT(6)) {
count_rx_stats(adapter, precv_frame, *psta);
ret = RTW_RX_HANDLED;
goto exit;
}
} else {
u8 *myhwaddr = myid(&adapter->eeprompriv);
if (!_rtw_memcmp(pattrib->ra, myhwaddr, ETH_ALEN)) {
ret = RTW_RX_HANDLED;
goto exit;
}
DBG_88E("issue_deauth to sta=%pM for the reason(7)\n", (pattrib->src));
issue_deauth(adapter, pattrib->src, WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA);
ret = RTW_RX_HANDLED;
goto exit;
}
exit:
_func_exit_;
return ret;
}
static int validate_recv_ctrl_frame(struct adapter *padapter,
union recv_frame *precv_frame)
{
#ifdef CONFIG_88EU_AP_MODE
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct sta_priv *pstapriv = &padapter->stapriv;
u8 *pframe = precv_frame->u.hdr.rx_data;
if (GetFrameType(pframe) != WIFI_CTRL_TYPE)
return _FAIL;
if (!_rtw_memcmp(GetAddr1Ptr(pframe), myid(&padapter->eeprompriv), ETH_ALEN))
return _FAIL;
if (GetFrameSubType(pframe) == WIFI_PSPOLL) {
u16 aid;
u8 wmmps_ac = 0;
struct sta_info *psta = NULL;
aid = GetAid(pframe);
psta = rtw_get_stainfo(pstapriv, GetAddr2Ptr(pframe));
if ((psta == NULL) || (psta->aid != aid))
return _FAIL;
psta->sta_stats.rx_ctrl_pkts++;
switch (pattrib->priority) {
case 1:
case 2:
wmmps_ac = psta->uapsd_bk&BIT(0);
break;
case 4:
case 5:
wmmps_ac = psta->uapsd_vi&BIT(0);
break;
case 6:
case 7:
wmmps_ac = psta->uapsd_vo&BIT(0);
break;
case 0:
case 3:
default:
wmmps_ac = psta->uapsd_be&BIT(0);
break;
}
if (wmmps_ac)
return _FAIL;
if (psta->state & WIFI_STA_ALIVE_CHK_STATE) {
DBG_88E("%s alive check-rx ps-poll\n", __func__);
psta->expire_to = pstapriv->expire_to;
psta->state ^= WIFI_STA_ALIVE_CHK_STATE;
}
if ((psta->state&WIFI_SLEEP_STATE) && (pstapriv->sta_dz_bitmap&BIT(psta->aid))) {
struct list_head *xmitframe_plist, *xmitframe_phead;
struct xmit_frame *pxmitframe = NULL;
spin_lock_bh(&psta->sleep_q.lock);
xmitframe_phead = get_list_head(&psta->sleep_q);
xmitframe_plist = get_next(xmitframe_phead);
if ((rtw_end_of_queue_search(xmitframe_phead, xmitframe_plist)) == false) {
pxmitframe = LIST_CONTAINOR(xmitframe_plist, struct xmit_frame, list);
xmitframe_plist = get_next(xmitframe_plist);
rtw_list_delete(&pxmitframe->list);
psta->sleepq_len--;
if (psta->sleepq_len > 0)
pxmitframe->attrib.mdata = 1;
else
pxmitframe->attrib.mdata = 0;
pxmitframe->attrib.triggered = 1;
spin_unlock_bh(&psta->sleep_q.lock);
if (rtw_hal_xmit(padapter, pxmitframe) == true)
rtw_os_xmit_complete(padapter, pxmitframe);
spin_lock_bh(&psta->sleep_q.lock);
if (psta->sleepq_len == 0) {
pstapriv->tim_bitmap &= ~BIT(psta->aid);
update_beacon(padapter, _TIM_IE_, NULL, false);
}
} else {
if (pstapriv->tim_bitmap&BIT(psta->aid)) {
if (psta->sleepq_len == 0) {
DBG_88E("no buffered packets to xmit\n");
issue_nulldata(padapter, psta->hwaddr, 0, 0, 0);
} else {
DBG_88E("error!psta->sleepq_len=%d\n", psta->sleepq_len);
psta->sleepq_len = 0;
}
pstapriv->tim_bitmap &= ~BIT(psta->aid);
update_beacon(padapter, _TIM_IE_, NULL, false);
}
}
spin_unlock_bh(&psta->sleep_q.lock);
}
}
#endif
return _FAIL;
}
static int validate_recv_mgnt_frame(struct adapter *padapter,
union recv_frame *precv_frame)
{
struct sta_info *psta;
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("+validate_recv_mgnt_frame\n"));
precv_frame = recvframe_chk_defrag(padapter, precv_frame);
if (precv_frame == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("%s: fragment packet\n", __func__));
return _SUCCESS;
}
psta = rtw_get_stainfo(&padapter->stapriv, GetAddr2Ptr(precv_frame->u.hdr.rx_data));
if (psta) {
psta->sta_stats.rx_mgnt_pkts++;
if (GetFrameSubType(precv_frame->u.hdr.rx_data) == WIFI_BEACON) {
psta->sta_stats.rx_beacon_pkts++;
} else if (GetFrameSubType(precv_frame->u.hdr.rx_data) == WIFI_PROBEREQ) {
psta->sta_stats.rx_probereq_pkts++;
} else if (GetFrameSubType(precv_frame->u.hdr.rx_data) == WIFI_PROBERSP) {
if (_rtw_memcmp(padapter->eeprompriv.mac_addr, GetAddr1Ptr(precv_frame->u.hdr.rx_data), ETH_ALEN) == true)
psta->sta_stats.rx_probersp_pkts++;
else if (is_broadcast_mac_addr(GetAddr1Ptr(precv_frame->u.hdr.rx_data)) ||
is_multicast_mac_addr(GetAddr1Ptr(precv_frame->u.hdr.rx_data)))
psta->sta_stats.rx_probersp_bm_pkts++;
else
psta->sta_stats.rx_probersp_uo_pkts++;
}
}
mgt_dispatcher(padapter, precv_frame);
return _SUCCESS;
}
static int validate_recv_data_frame(struct adapter *adapter,
union recv_frame *precv_frame)
{
u8 bretry;
u8 *psa, *pda, *pbssid;
struct sta_info *psta = NULL;
u8 *ptr = precv_frame->u.hdr.rx_data;
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
struct security_priv *psecuritypriv = &adapter->securitypriv;
int ret = _SUCCESS;
_func_enter_;
bretry = GetRetry(ptr);
pda = get_da(ptr);
psa = get_sa(ptr);
pbssid = get_hdr_bssid(ptr);
if (pbssid == NULL) {
ret = _FAIL;
goto exit;
}
memcpy(pattrib->dst, pda, ETH_ALEN);
memcpy(pattrib->src, psa, ETH_ALEN);
memcpy(pattrib->bssid, pbssid, ETH_ALEN);
switch (pattrib->to_fr_ds) {
case 0:
memcpy(pattrib->ra, pda, ETH_ALEN);
memcpy(pattrib->ta, psa, ETH_ALEN);
ret = sta2sta_data_frame(adapter, precv_frame, &psta);
break;
case 1:
memcpy(pattrib->ra, pda, ETH_ALEN);
memcpy(pattrib->ta, pbssid, ETH_ALEN);
ret = ap2sta_data_frame(adapter, precv_frame, &psta);
break;
case 2:
memcpy(pattrib->ra, pbssid, ETH_ALEN);
memcpy(pattrib->ta, psa, ETH_ALEN);
ret = sta2ap_data_frame(adapter, precv_frame, &psta);
break;
case 3:
memcpy(pattrib->ra, GetAddr1Ptr(ptr), ETH_ALEN);
memcpy(pattrib->ta, GetAddr2Ptr(ptr), ETH_ALEN);
ret = _FAIL;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" case 3\n"));
break;
default:
ret = _FAIL;
break;
}
if (ret == _FAIL) {
goto exit;
} else if (ret == RTW_RX_HANDLED) {
goto exit;
}
if (psta == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, (" after to_fr_ds_chk; psta==NULL\n"));
ret = _FAIL;
goto exit;
}
precv_frame->u.hdr.psta = psta;
pattrib->amsdu = 0;
pattrib->ack_policy = 0;
if (pattrib->qos == 1) {
pattrib->priority = GetPriority((ptr + 24));
pattrib->ack_policy = GetAckpolicy((ptr + 24));
pattrib->amsdu = GetAMsdu((ptr + 24));
pattrib->hdrlen = pattrib->to_fr_ds == 3 ? 32 : 26;
if (pattrib->priority != 0 && pattrib->priority != 3)
adapter->recvpriv.bIsAnyNonBEPkts = true;
} else {
pattrib->priority = 0;
pattrib->hdrlen = pattrib->to_fr_ds == 3 ? 30 : 24;
}
if (pattrib->order)
pattrib->hdrlen += 4;
precv_frame->u.hdr.preorder_ctrl = &psta->recvreorder_ctrl[pattrib->priority];
if (recv_decache(precv_frame, bretry, &psta->sta_recvpriv.rxcache) == _FAIL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("decache : drop pkt\n"));
ret = _FAIL;
goto exit;
}
if (pattrib->privacy) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("validate_recv_data_frame:pattrib->privacy=%x\n", pattrib->privacy));
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n ^^^^^^^^^^^IS_MCAST(pattrib->ra(0x%02x))=%d^^^^^^^^^^^^^^^6\n", pattrib->ra[0], IS_MCAST(pattrib->ra)));
GET_ENCRY_ALGO(psecuritypriv, psta, pattrib->encrypt, IS_MCAST(pattrib->ra));
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("\n pattrib->encrypt=%d\n", pattrib->encrypt));
SET_ICE_IV_LEN(pattrib->iv_len, pattrib->icv_len, pattrib->encrypt);
} else {
pattrib->encrypt = 0;
pattrib->iv_len = 0;
pattrib->icv_len = 0;
}
exit:
_func_exit_;
return ret;
}
static int validate_recv_frame(struct adapter *adapter, union recv_frame *precv_frame)
{
u8 type;
u8 subtype;
int retval = _SUCCESS;
u8 bDumpRxPkt;
struct rx_pkt_attrib *pattrib = &precv_frame->u.hdr.attrib;
u8 *ptr = precv_frame->u.hdr.rx_data;
u8 ver = (unsigned char) (*ptr)&0x3;
struct mlme_ext_priv *pmlmeext = &adapter->mlmeextpriv;
_func_enter_;
if (pmlmeext->sitesurvey_res.state == SCAN_PROCESS) {
int ch_set_idx = rtw_ch_set_search_ch(pmlmeext->channel_set, rtw_get_oper_ch(adapter));
if (ch_set_idx >= 0)
pmlmeext->channel_set[ch_set_idx].rx_count++;
}
if (ver != 0) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("validate_recv_data_frame fail! (ver!=0)\n"));
retval = _FAIL;
goto exit;
}
type = GetFrameType(ptr);
subtype = GetFrameSubType(ptr);
pattrib->to_fr_ds = get_tofr_ds(ptr);
pattrib->frag_num = GetFragNum(ptr);
pattrib->seq_num = GetSequence(ptr);
pattrib->pw_save = GetPwrMgt(ptr);
pattrib->mfrag = GetMFrag(ptr);
pattrib->mdata = GetMData(ptr);
pattrib->privacy = GetPrivacy(ptr);
pattrib->order = GetOrder(ptr);
rtw_hal_get_def_var(adapter, HAL_DEF_DBG_DUMP_RXPKT, &(bDumpRxPkt));
if (bDumpRxPkt == 1) {
int i;
DBG_88E("#############################\n");
for (i = 0; i < 64; i = i+8)
DBG_88E("%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:\n", *(ptr+i),
*(ptr+i+1), *(ptr+i+2), *(ptr+i+3), *(ptr+i+4), *(ptr+i+5), *(ptr+i+6), *(ptr+i+7));
DBG_88E("#############################\n");
} else if (bDumpRxPkt == 2) {
if (type == WIFI_MGT_TYPE) {
int i;
DBG_88E("#############################\n");
for (i = 0; i < 64; i = i+8)
DBG_88E("%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:\n", *(ptr+i),
*(ptr+i+1), *(ptr+i+2), *(ptr+i+3), *(ptr+i+4), *(ptr+i+5), *(ptr+i+6), *(ptr+i+7));
DBG_88E("#############################\n");
}
} else if (bDumpRxPkt == 3) {
if (type == WIFI_DATA_TYPE) {
int i;
DBG_88E("#############################\n");
for (i = 0; i < 64; i = i+8)
DBG_88E("%02X:%02X:%02X:%02X:%02X:%02X:%02X:%02X:\n", *(ptr+i),
*(ptr+i+1), *(ptr+i+2), *(ptr+i+3), *(ptr+i+4), *(ptr+i+5), *(ptr+i+6), *(ptr+i+7));
DBG_88E("#############################\n");
}
}
switch (type) {
case WIFI_MGT_TYPE:
retval = validate_recv_mgnt_frame(adapter, precv_frame);
if (retval == _FAIL)
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("validate_recv_mgnt_frame fail\n"));
retval = _FAIL;
break;
case WIFI_CTRL_TYPE:
retval = validate_recv_ctrl_frame(adapter, precv_frame);
if (retval == _FAIL)
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("validate_recv_ctrl_frame fail\n"));
retval = _FAIL;
break;
case WIFI_DATA_TYPE:
rtw_led_control(adapter, LED_CTL_RX);
pattrib->qos = (subtype & BIT(7)) ? 1 : 0;
retval = validate_recv_data_frame(adapter, precv_frame);
if (retval == _FAIL) {
struct recv_priv *precvpriv = &adapter->recvpriv;
precvpriv->rx_drop++;
}
break;
default:
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("validate_recv_data_frame fail! type= 0x%x\n", type));
retval = _FAIL;
break;
}
exit:
_func_exit_;
return retval;
}
static int wlanhdr_to_ethhdr (union recv_frame *precvframe)
{
int rmv_len;
u16 eth_type, len;
__be16 be_tmp;
u8 bsnaphdr;
u8 *psnap_type;
struct ieee80211_snap_hdr *psnap;
int ret = _SUCCESS;
struct adapter *adapter = precvframe->u.hdr.adapter;
struct mlme_priv *pmlmepriv = &adapter->mlmepriv;
u8 *ptr = get_recvframe_data(precvframe);
struct rx_pkt_attrib *pattrib = &precvframe->u.hdr.attrib;
_func_enter_;
if (pattrib->encrypt)
recvframe_pull_tail(precvframe, pattrib->icv_len);
psnap = (struct ieee80211_snap_hdr *)(ptr+pattrib->hdrlen + pattrib->iv_len);
psnap_type = ptr+pattrib->hdrlen + pattrib->iv_len+SNAP_SIZE;
if ((_rtw_memcmp(psnap, rtw_rfc1042_header, SNAP_SIZE) &&
(_rtw_memcmp(psnap_type, SNAP_ETH_TYPE_IPX, 2) == false) &&
(_rtw_memcmp(psnap_type, SNAP_ETH_TYPE_APPLETALK_AARP, 2) == false)) ||
_rtw_memcmp(psnap, rtw_bridge_tunnel_header, SNAP_SIZE)) {
bsnaphdr = true;
} else {
bsnaphdr = false;
}
rmv_len = pattrib->hdrlen + pattrib->iv_len + (bsnaphdr ? SNAP_SIZE : 0);
len = precvframe->u.hdr.len - rmv_len;
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_,
("\n===pattrib->hdrlen: %x, pattrib->iv_len:%x===\n\n", pattrib->hdrlen, pattrib->iv_len));
memcpy(&be_tmp, ptr+rmv_len, 2);
eth_type = ntohs(be_tmp);
pattrib->eth_type = eth_type;
if ((check_fwstate(pmlmepriv, WIFI_MP_STATE))) {
ptr += rmv_len;
*ptr = 0x87;
*(ptr+1) = 0x12;
eth_type = 0x8712;
ptr = recvframe_pull(precvframe, (rmv_len-sizeof(struct ethhdr)+2)-24);
memcpy(ptr, get_rxmem(precvframe), 24);
ptr += 24;
} else {
ptr = recvframe_pull(precvframe, (rmv_len-sizeof(struct ethhdr) + (bsnaphdr ? 2 : 0)));
}
memcpy(ptr, pattrib->dst, ETH_ALEN);
memcpy(ptr+ETH_ALEN, pattrib->src, ETH_ALEN);
if (!bsnaphdr) {
be_tmp = htons(len);
memcpy(ptr+12, &be_tmp, 2);
}
_func_exit_;
return ret;
}
static union recv_frame *recvframe_defrag(struct adapter *adapter, struct __queue *defrag_q)
{
struct list_head *plist, *phead;
u8 wlanhdr_offset;
u8 curfragnum;
struct recv_frame_hdr *pfhdr, *pnfhdr;
union recv_frame *prframe, *pnextrframe;
struct __queue *pfree_recv_queue;
_func_enter_;
curfragnum = 0;
pfree_recv_queue = &adapter->recvpriv.free_recv_queue;
phead = get_list_head(defrag_q);
plist = get_next(phead);
prframe = LIST_CONTAINOR(plist, union recv_frame, u);
pfhdr = &prframe->u.hdr;
rtw_list_delete(&(prframe->u.list));
if (curfragnum != pfhdr->attrib.frag_num) {
rtw_free_recvframe(prframe, pfree_recv_queue);
rtw_free_recvframe_queue(defrag_q, pfree_recv_queue);
return NULL;
}
curfragnum++;
plist = get_list_head(defrag_q);
plist = get_next(plist);
while (rtw_end_of_queue_search(phead, plist) == false) {
pnextrframe = LIST_CONTAINOR(plist, union recv_frame , u);
pnfhdr = &pnextrframe->u.hdr;
if (curfragnum != pnfhdr->attrib.frag_num) {
rtw_free_recvframe(prframe, pfree_recv_queue);
rtw_free_recvframe_queue(defrag_q, pfree_recv_queue);
return NULL;
}
curfragnum++;
wlanhdr_offset = pnfhdr->attrib.hdrlen + pnfhdr->attrib.iv_len;
recvframe_pull(pnextrframe, wlanhdr_offset);
recvframe_pull_tail(prframe, pfhdr->attrib.icv_len);
memcpy(pfhdr->rx_tail, pnfhdr->rx_data, pnfhdr->len);
recvframe_put(prframe, pnfhdr->len);
pfhdr->attrib.icv_len = pnfhdr->attrib.icv_len;
plist = get_next(plist);
}
rtw_free_recvframe_queue(defrag_q, pfree_recv_queue);
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("Performance defrag!!!!!\n"));
_func_exit_;
return prframe;
}
union recv_frame *recvframe_chk_defrag(struct adapter *padapter, union recv_frame *precv_frame)
{
u8 ismfrag;
u8 fragnum;
u8 *psta_addr;
struct recv_frame_hdr *pfhdr;
struct sta_info *psta;
struct sta_priv *pstapriv;
struct list_head *phead;
union recv_frame *prtnframe = NULL;
struct __queue *pfree_recv_queue, *pdefrag_q;
_func_enter_;
pstapriv = &padapter->stapriv;
pfhdr = &precv_frame->u.hdr;
pfree_recv_queue = &padapter->recvpriv.free_recv_queue;
ismfrag = pfhdr->attrib.mfrag;
fragnum = pfhdr->attrib.frag_num;
psta_addr = pfhdr->attrib.ta;
psta = rtw_get_stainfo(pstapriv, psta_addr);
if (psta == NULL) {
u8 type = GetFrameType(pfhdr->rx_data);
if (type != WIFI_DATA_TYPE) {
psta = rtw_get_bcmc_stainfo(padapter);
pdefrag_q = &psta->sta_recvpriv.defrag_q;
} else {
pdefrag_q = NULL;
}
} else {
pdefrag_q = &psta->sta_recvpriv.defrag_q;
}
if ((ismfrag == 0) && (fragnum == 0))
prtnframe = precv_frame;
if (ismfrag == 1) {
if (pdefrag_q != NULL) {
if (fragnum == 0) {
if (_rtw_queue_empty(pdefrag_q) == false) {
rtw_free_recvframe_queue(pdefrag_q, pfree_recv_queue);
}
}
phead = get_list_head(pdefrag_q);
rtw_list_insert_tail(&pfhdr->list, phead);
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("Enqueuq: ismfrag=%d, fragnum=%d\n", ismfrag, fragnum));
prtnframe = NULL;
} else {
rtw_free_recvframe(precv_frame, pfree_recv_queue);
prtnframe = NULL;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("Free because pdefrag_q==NULL: ismfrag=%d, fragnum=%d\n", ismfrag, fragnum));
}
}
if ((ismfrag == 0) && (fragnum != 0)) {
if (pdefrag_q != NULL) {
phead = get_list_head(pdefrag_q);
rtw_list_insert_tail(&pfhdr->list, phead);
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("defrag: ismfrag=%d, fragnum=%d\n", ismfrag, fragnum));
precv_frame = recvframe_defrag(padapter, pdefrag_q);
prtnframe = precv_frame;
} else {
rtw_free_recvframe(precv_frame, pfree_recv_queue);
prtnframe = NULL;
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("Free because pdefrag_q==NULL: ismfrag=%d, fragnum=%d\n", ismfrag, fragnum));
}
}
if ((prtnframe != NULL) && (prtnframe->u.hdr.attrib.privacy)) {
if (recvframe_chkmic(padapter, prtnframe) == _FAIL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("recvframe_chkmic(padapter, prtnframe)==_FAIL\n"));
rtw_free_recvframe(prtnframe, pfree_recv_queue);
prtnframe = NULL;
}
}
_func_exit_;
return prtnframe;
}
static int amsdu_to_msdu(struct adapter *padapter, union recv_frame *prframe)
{
int a_len, padding_len;
u16 eth_type, nSubframe_Length;
u8 nr_subframes, i;
unsigned char *pdata;
struct rx_pkt_attrib *pattrib;
unsigned char *data_ptr;
struct sk_buff *sub_skb, *subframes[MAX_SUBFRAME_COUNT];
struct recv_priv *precvpriv = &padapter->recvpriv;
struct __queue *pfree_recv_queue = &(precvpriv->free_recv_queue);
int ret = _SUCCESS;
nr_subframes = 0;
pattrib = &prframe->u.hdr.attrib;
recvframe_pull(prframe, prframe->u.hdr.attrib.hdrlen);
if (prframe->u.hdr.attrib.iv_len > 0)
recvframe_pull(prframe, prframe->u.hdr.attrib.iv_len);
a_len = prframe->u.hdr.len;
pdata = prframe->u.hdr.rx_data;
while (a_len > ETH_HLEN) {
nSubframe_Length = RTW_GET_BE16(pdata + 12);
if (a_len < (ETHERNET_HEADER_SIZE + nSubframe_Length)) {
DBG_88E("nRemain_Length is %d and nSubframe_Length is : %d\n", a_len, nSubframe_Length);
goto exit;
}
pdata += ETH_HLEN;
a_len -= ETH_HLEN;
sub_skb = dev_alloc_skb(nSubframe_Length + 12);
if (sub_skb) {
skb_reserve(sub_skb, 12);
data_ptr = (u8 *)skb_put(sub_skb, nSubframe_Length);
memcpy(data_ptr, pdata, nSubframe_Length);
} else {
sub_skb = skb_clone(prframe->u.hdr.pkt, GFP_ATOMIC);
if (sub_skb) {
sub_skb->data = pdata;
sub_skb->len = nSubframe_Length;
skb_set_tail_pointer(sub_skb, nSubframe_Length);
} else {
DBG_88E("skb_clone() Fail!!! , nr_subframes=%d\n", nr_subframes);
break;
}
}
subframes[nr_subframes++] = sub_skb;
if (nr_subframes >= MAX_SUBFRAME_COUNT) {
DBG_88E("ParseSubframe(): Too many Subframes! Packets dropped!\n");
break;
}
pdata += nSubframe_Length;
a_len -= nSubframe_Length;
if (a_len != 0) {
padding_len = 4 - ((nSubframe_Length + ETH_HLEN) & (4-1));
if (padding_len == 4) {
padding_len = 0;
}
if (a_len < padding_len) {
goto exit;
}
pdata += padding_len;
a_len -= padding_len;
}
}
for (i = 0; i < nr_subframes; i++) {
sub_skb = subframes[i];
eth_type = RTW_GET_BE16(&sub_skb->data[6]);
if (sub_skb->len >= 8 &&
((_rtw_memcmp(sub_skb->data, rtw_rfc1042_header, SNAP_SIZE) &&
eth_type != ETH_P_AARP && eth_type != ETH_P_IPX) ||
_rtw_memcmp(sub_skb->data, rtw_bridge_tunnel_header, SNAP_SIZE))) {
skb_pull(sub_skb, SNAP_SIZE);
memcpy(skb_push(sub_skb, ETH_ALEN), pattrib->src, ETH_ALEN);
memcpy(skb_push(sub_skb, ETH_ALEN), pattrib->dst, ETH_ALEN);
} else {
__be16 len;
len = htons(sub_skb->len);
memcpy(skb_push(sub_skb, 2), &len, 2);
memcpy(skb_push(sub_skb, ETH_ALEN), pattrib->src, ETH_ALEN);
memcpy(skb_push(sub_skb, ETH_ALEN), pattrib->dst, ETH_ALEN);
}
sub_skb->protocol = eth_type_trans(sub_skb, padapter->pnetdev);
sub_skb->dev = padapter->pnetdev;
sub_skb->ip_summed = CHECKSUM_NONE;
netif_rx(sub_skb);
}
exit:
prframe->u.hdr.len = 0;
rtw_free_recvframe(prframe, pfree_recv_queue);
return ret;
}
static int check_indicate_seq(struct recv_reorder_ctrl *preorder_ctrl, u16 seq_num)
{
u8 wsize = preorder_ctrl->wsize_b;
u16 wend = (preorder_ctrl->indicate_seq + wsize - 1) & 0xFFF;
if (preorder_ctrl->indicate_seq == 0xFFFF)
preorder_ctrl->indicate_seq = seq_num;
if (SN_LESS(seq_num, preorder_ctrl->indicate_seq))
return false;
if (SN_EQUAL(seq_num, preorder_ctrl->indicate_seq)) {
preorder_ctrl->indicate_seq = (preorder_ctrl->indicate_seq + 1) & 0xFFF;
} else if (SN_LESS(wend, seq_num)) {
if (seq_num >= (wsize - 1))
preorder_ctrl->indicate_seq = seq_num + 1 - wsize;
else
preorder_ctrl->indicate_seq = 0xFFF - (wsize - (seq_num + 1)) + 1;
}
return true;
}
int enqueue_reorder_recvframe(struct recv_reorder_ctrl *preorder_ctrl, union recv_frame *prframe)
{
struct rx_pkt_attrib *pattrib = &prframe->u.hdr.attrib;
struct __queue *ppending_recvframe_queue = &preorder_ctrl->pending_recvframe_queue;
struct list_head *phead, *plist;
union recv_frame *pnextrframe;
struct rx_pkt_attrib *pnextattrib;
phead = get_list_head(ppending_recvframe_queue);
plist = get_next(phead);
while (rtw_end_of_queue_search(phead, plist) == false) {
pnextrframe = LIST_CONTAINOR(plist, union recv_frame, u);
pnextattrib = &pnextrframe->u.hdr.attrib;
if (SN_LESS(pnextattrib->seq_num, pattrib->seq_num))
plist = get_next(plist);
else if (SN_EQUAL(pnextattrib->seq_num, pattrib->seq_num))
return false;
else
break;
}
rtw_list_delete(&(prframe->u.hdr.list));
rtw_list_insert_tail(&(prframe->u.hdr.list), plist);
return true;
}
static int recv_indicatepkts_in_order(struct adapter *padapter, struct recv_reorder_ctrl *preorder_ctrl, int bforced)
{
struct list_head *phead, *plist;
union recv_frame *prframe;
struct rx_pkt_attrib *pattrib;
int bPktInBuf = false;
struct recv_priv *precvpriv = &padapter->recvpriv;
struct __queue *ppending_recvframe_queue = &preorder_ctrl->pending_recvframe_queue;
phead = get_list_head(ppending_recvframe_queue);
plist = get_next(phead);
if (bforced) {
if (rtw_is_list_empty(phead))
return true;
prframe = LIST_CONTAINOR(plist, union recv_frame, u);
pattrib = &prframe->u.hdr.attrib;
preorder_ctrl->indicate_seq = pattrib->seq_num;
}
while (!rtw_is_list_empty(phead)) {
prframe = LIST_CONTAINOR(plist, union recv_frame, u);
pattrib = &prframe->u.hdr.attrib;
if (!SN_LESS(preorder_ctrl->indicate_seq, pattrib->seq_num)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_,
("recv_indicatepkts_in_order: indicate=%d seq=%d amsdu=%d\n",
preorder_ctrl->indicate_seq, pattrib->seq_num, pattrib->amsdu));
plist = get_next(plist);
rtw_list_delete(&(prframe->u.hdr.list));
if (SN_EQUAL(preorder_ctrl->indicate_seq, pattrib->seq_num))
preorder_ctrl->indicate_seq = (preorder_ctrl->indicate_seq + 1) & 0xFFF;
if (!pattrib->amsdu) {
if ((!padapter->bDriverStopped) &&
(!padapter->bSurpriseRemoved))
rtw_recv_indicatepkt(padapter, prframe);
} else if (pattrib->amsdu == 1) {
if (amsdu_to_msdu(padapter, prframe) != _SUCCESS)
rtw_free_recvframe(prframe, &precvpriv->free_recv_queue);
} else {
}
bPktInBuf = false;
} else {
bPktInBuf = true;
break;
}
}
return bPktInBuf;
}
static int recv_indicatepkt_reorder(struct adapter *padapter, union recv_frame *prframe)
{
int retval = _SUCCESS;
struct rx_pkt_attrib *pattrib = &prframe->u.hdr.attrib;
struct recv_reorder_ctrl *preorder_ctrl = prframe->u.hdr.preorder_ctrl;
struct __queue *ppending_recvframe_queue = &preorder_ctrl->pending_recvframe_queue;
if (!pattrib->amsdu) {
wlanhdr_to_ethhdr(prframe);
if ((pattrib->qos != 1) || (pattrib->eth_type == 0x0806) ||
(pattrib->ack_policy != 0)) {
if ((!padapter->bDriverStopped) &&
(!padapter->bSurpriseRemoved)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("@@@@ recv_indicatepkt_reorder -recv_func recv_indicatepkt\n"));
rtw_recv_indicatepkt(padapter, prframe);
return _SUCCESS;
}
return _FAIL;
}
if (!preorder_ctrl->enable) {
preorder_ctrl->indicate_seq = pattrib->seq_num;
rtw_recv_indicatepkt(padapter, prframe);
preorder_ctrl->indicate_seq = (preorder_ctrl->indicate_seq + 1)%4096;
return _SUCCESS;
}
} else if (pattrib->amsdu == 1) {
if (!preorder_ctrl->enable) {
preorder_ctrl->indicate_seq = pattrib->seq_num;
retval = amsdu_to_msdu(padapter, prframe);
preorder_ctrl->indicate_seq = (preorder_ctrl->indicate_seq + 1)%4096;
return retval;
}
}
spin_lock_bh(&ppending_recvframe_queue->lock);
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_,
("recv_indicatepkt_reorder: indicate=%d seq=%d\n",
preorder_ctrl->indicate_seq, pattrib->seq_num));
if (!check_indicate_seq(preorder_ctrl, pattrib->seq_num)) {
rtw_recv_indicatepkt(padapter, prframe);
spin_unlock_bh(&ppending_recvframe_queue->lock);
goto _success_exit;
}
if (!enqueue_reorder_recvframe(preorder_ctrl, prframe))
goto _err_exit;
if (recv_indicatepkts_in_order(padapter, preorder_ctrl, false)) {
_set_timer(&preorder_ctrl->reordering_ctrl_timer, REORDER_WAIT_TIME);
spin_unlock_bh(&ppending_recvframe_queue->lock);
} else {
spin_unlock_bh(&ppending_recvframe_queue->lock);
_cancel_timer_ex(&preorder_ctrl->reordering_ctrl_timer);
}
_success_exit:
return _SUCCESS;
_err_exit:
spin_unlock_bh(&ppending_recvframe_queue->lock);
return _FAIL;
}
void rtw_reordering_ctrl_timeout_handler(void *pcontext)
{
struct recv_reorder_ctrl *preorder_ctrl = (struct recv_reorder_ctrl *)pcontext;
struct adapter *padapter = preorder_ctrl->padapter;
struct __queue *ppending_recvframe_queue = &preorder_ctrl->pending_recvframe_queue;
if (padapter->bDriverStopped || padapter->bSurpriseRemoved)
return;
spin_lock_bh(&ppending_recvframe_queue->lock);
if (recv_indicatepkts_in_order(padapter, preorder_ctrl, true) == true)
_set_timer(&preorder_ctrl->reordering_ctrl_timer, REORDER_WAIT_TIME);
spin_unlock_bh(&ppending_recvframe_queue->lock);
}
static int process_recv_indicatepkts(struct adapter *padapter, union recv_frame *prframe)
{
int retval = _SUCCESS;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
struct ht_priv *phtpriv = &pmlmepriv->htpriv;
if (phtpriv->ht_option) {
if (recv_indicatepkt_reorder(padapter, prframe) != _SUCCESS) {
if ((!padapter->bDriverStopped) &&
(!padapter->bSurpriseRemoved)) {
retval = _FAIL;
return retval;
}
}
} else {
retval = wlanhdr_to_ethhdr (prframe);
if (retval != _SUCCESS) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("wlanhdr_to_ethhdr: drop pkt\n"));
return retval;
}
if ((!padapter->bDriverStopped) &&
(!padapter->bSurpriseRemoved)) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("@@@@ process_recv_indicatepkts- recv_func recv_indicatepkt\n"));
rtw_recv_indicatepkt(padapter, prframe);
} else {
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("@@@@ process_recv_indicatepkts- recv_func free_indicatepkt\n"));
RT_TRACE(_module_rtl871x_recv_c_, _drv_notice_, ("recv_func:bDriverStopped(%d) OR bSurpriseRemoved(%d)", padapter->bDriverStopped, padapter->bSurpriseRemoved));
retval = _FAIL;
return retval;
}
}
return retval;
}
static int recv_func_prehandle(struct adapter *padapter, union recv_frame *rframe)
{
int ret = _SUCCESS;
struct rx_pkt_attrib *pattrib = &rframe->u.hdr.attrib;
struct __queue *pfree_recv_queue = &padapter->recvpriv.free_recv_queue;
struct mlme_priv *pmlmepriv = &padapter->mlmepriv;
if (padapter->registrypriv.mp_mode == 1) {
if ((check_fwstate(pmlmepriv, WIFI_MP_STATE) == true)) {
if (pattrib->crc_err == 1)
padapter->mppriv.rx_crcerrpktcount++;
else
padapter->mppriv.rx_pktcount++;
if (check_fwstate(pmlmepriv, WIFI_MP_LPBK_STATE) == false) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_alert_, ("MP - Not in loopback mode , drop pkt\n"));
ret = _FAIL;
rtw_free_recvframe(rframe, pfree_recv_queue);
goto exit;
}
}
}
ret = validate_recv_frame(padapter, rframe);
if (ret != _SUCCESS) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("recv_func: validate_recv_frame fail! drop pkt\n"));
rtw_free_recvframe(rframe, pfree_recv_queue);
goto exit;
}
exit:
return ret;
}
static int recv_func_posthandle(struct adapter *padapter, union recv_frame *prframe)
{
int ret = _SUCCESS;
union recv_frame *orig_prframe = prframe;
struct recv_priv *precvpriv = &padapter->recvpriv;
struct __queue *pfree_recv_queue = &padapter->recvpriv.free_recv_queue;
rtw_led_control(padapter, LED_CTL_RX);
prframe = decryptor(padapter, prframe);
if (prframe == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("decryptor: drop pkt\n"));
ret = _FAIL;
goto _recv_data_drop;
}
prframe = recvframe_chk_defrag(padapter, prframe);
if (prframe == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("recvframe_chk_defrag: drop pkt\n"));
goto _recv_data_drop;
}
prframe = portctrl(padapter, prframe);
if (prframe == NULL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("portctrl: drop pkt\n"));
ret = _FAIL;
goto _recv_data_drop;
}
count_rx_stats(padapter, prframe, NULL);
ret = process_recv_indicatepkts(padapter, prframe);
if (ret != _SUCCESS) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_err_, ("recv_func: process_recv_indicatepkts fail!\n"));
rtw_free_recvframe(orig_prframe, pfree_recv_queue);
goto _recv_data_drop;
}
return ret;
_recv_data_drop:
precvpriv->rx_drop++;
return ret;
}
static int recv_func(struct adapter *padapter, union recv_frame *rframe)
{
int ret;
struct rx_pkt_attrib *prxattrib = &rframe->u.hdr.attrib;
struct security_priv *psecuritypriv = &padapter->securitypriv;
struct mlme_priv *mlmepriv = &padapter->mlmepriv;
if (check_fwstate(mlmepriv, WIFI_STATION_STATE) && psecuritypriv->busetkipkey) {
union recv_frame *pending_frame;
while ((pending_frame = rtw_alloc_recvframe(&padapter->recvpriv.uc_swdec_pending_queue))) {
if (recv_func_posthandle(padapter, pending_frame) == _SUCCESS)
DBG_88E("%s: dequeue uc_swdec_pending_queue\n", __func__);
}
}
ret = recv_func_prehandle(padapter, rframe);
if (ret == _SUCCESS) {
if (check_fwstate(mlmepriv, WIFI_STATION_STATE) &&
!IS_MCAST(prxattrib->ra) && prxattrib->encrypt > 0 &&
(prxattrib->bdecrypted == 0 || psecuritypriv->sw_decrypt) &&
!is_wep_enc(psecuritypriv->dot11PrivacyAlgrthm) &&
!psecuritypriv->busetkipkey) {
rtw_enqueue_recvframe(rframe, &padapter->recvpriv.uc_swdec_pending_queue);
DBG_88E("%s: no key, enqueue uc_swdec_pending_queue\n", __func__);
goto exit;
}
ret = recv_func_posthandle(padapter, rframe);
}
exit:
return ret;
}
s32 rtw_recv_entry(union recv_frame *precvframe)
{
struct adapter *padapter;
struct recv_priv *precvpriv;
s32 ret = _SUCCESS;
_func_enter_;
padapter = precvframe->u.hdr.adapter;
precvpriv = &padapter->recvpriv;
ret = recv_func(padapter, precvframe);
if (ret == _FAIL) {
RT_TRACE(_module_rtl871x_recv_c_, _drv_info_, ("rtw_recv_entry: recv_func return fail!!!\n"));
goto _recv_entry_drop;
}
precvpriv->rx_pkts++;
_func_exit_;
return ret;
_recv_entry_drop:
if (padapter->registrypriv.mp_mode == 1)
padapter->mppriv.rx_pktloss = precvpriv->rx_drop;
_func_exit_;
return ret;
}
void rtw_signal_stat_timer_hdl(RTW_TIMER_HDL_ARGS)
{
struct adapter *adapter = (struct adapter *)FunctionContext;
struct recv_priv *recvpriv = &adapter->recvpriv;
u32 tmp_s, tmp_q;
u8 avg_signal_strength = 0;
u8 avg_signal_qual = 0;
u8 _alpha = 3;
if (adapter->recvpriv.is_signal_dbg) {
adapter->recvpriv.signal_strength = adapter->recvpriv.signal_strength_dbg;
adapter->recvpriv.rssi = (s8)translate_percentage_to_dbm((u8)adapter->recvpriv.signal_strength_dbg);
} else {
if (recvpriv->signal_strength_data.update_req == 0) {
avg_signal_strength = recvpriv->signal_strength_data.avg_val;
recvpriv->signal_strength_data.update_req = 1;
}
if (recvpriv->signal_qual_data.update_req == 0) {
avg_signal_qual = recvpriv->signal_qual_data.avg_val;
recvpriv->signal_qual_data.update_req = 1;
}
if (check_fwstate(&adapter->mlmepriv, _FW_UNDER_SURVEY) == false) {
tmp_s = (avg_signal_strength+(_alpha-1)*recvpriv->signal_strength);
if (tmp_s % _alpha)
tmp_s = tmp_s/_alpha + 1;
else
tmp_s = tmp_s/_alpha;
if (tmp_s > 100)
tmp_s = 100;
tmp_q = (avg_signal_qual+(_alpha-1)*recvpriv->signal_qual);
if (tmp_q % _alpha)
tmp_q = tmp_q/_alpha + 1;
else
tmp_q = tmp_q/_alpha;
if (tmp_q > 100)
tmp_q = 100;
recvpriv->signal_strength = tmp_s;
recvpriv->rssi = (s8)translate_percentage_to_dbm(tmp_s);
recvpriv->signal_qual = tmp_q;
}
}
rtw_set_signal_stat_timer(recvpriv);
}
