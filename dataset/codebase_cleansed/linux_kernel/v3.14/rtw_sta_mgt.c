static void _rtw_init_stainfo(struct sta_info *psta)
{
_func_enter_;
_rtw_memset((u8 *)psta, 0, sizeof (struct sta_info));
spin_lock_init(&psta->lock);
_rtw_init_listhead(&psta->list);
_rtw_init_listhead(&psta->hash_list);
_rtw_init_queue(&psta->sleep_q);
psta->sleepq_len = 0;
_rtw_init_sta_xmit_priv(&psta->sta_xmitpriv);
_rtw_init_sta_recv_priv(&psta->sta_recvpriv);
#ifdef CONFIG_88EU_AP_MODE
_rtw_init_listhead(&psta->asoc_list);
_rtw_init_listhead(&psta->auth_list);
psta->expire_to = 0;
psta->flags = 0;
psta->capability = 0;
psta->bpairwise_key_installed = false;
#ifdef CONFIG_88EU_AP_MODE
psta->nonerp_set = 0;
psta->no_short_slot_time_set = 0;
psta->no_short_preamble_set = 0;
psta->no_ht_gf_set = 0;
psta->no_ht_set = 0;
psta->ht_20mhz_set = 0;
#endif
psta->under_exist_checking = 0;
psta->keep_alive_trycnt = 0;
#endif
_func_exit_;
}
u32 _rtw_init_sta_priv(struct sta_priv *pstapriv)
{
struct sta_info *psta;
s32 i;
_func_enter_;
pstapriv->pallocated_stainfo_buf = rtw_zvmalloc(sizeof(struct sta_info) * NUM_STA + 4);
if (!pstapriv->pallocated_stainfo_buf)
return _FAIL;
pstapriv->pstainfo_buf = pstapriv->pallocated_stainfo_buf + 4 -
((size_t)(pstapriv->pallocated_stainfo_buf) & 3);
_rtw_init_queue(&pstapriv->free_sta_queue);
spin_lock_init(&pstapriv->sta_hash_lock);
pstapriv->asoc_sta_count = 0;
_rtw_init_queue(&pstapriv->sleep_q);
_rtw_init_queue(&pstapriv->wakeup_q);
psta = (struct sta_info *)(pstapriv->pstainfo_buf);
for (i = 0; i < NUM_STA; i++) {
_rtw_init_stainfo(psta);
_rtw_init_listhead(&(pstapriv->sta_hash[i]));
rtw_list_insert_tail(&psta->list, get_list_head(&pstapriv->free_sta_queue));
psta++;
}
#ifdef CONFIG_88EU_AP_MODE
pstapriv->sta_dz_bitmap = 0;
pstapriv->tim_bitmap = 0;
_rtw_init_listhead(&pstapriv->asoc_list);
_rtw_init_listhead(&pstapriv->auth_list);
spin_lock_init(&pstapriv->asoc_list_lock);
spin_lock_init(&pstapriv->auth_list_lock);
pstapriv->asoc_list_cnt = 0;
pstapriv->auth_list_cnt = 0;
pstapriv->auth_to = 3;
pstapriv->assoc_to = 3;
pstapriv->expire_to = 3;
pstapriv->max_num_sta = NUM_STA;
#endif
_func_exit_;
return _SUCCESS;
}
inline int rtw_stainfo_offset(struct sta_priv *stapriv, struct sta_info *sta)
{
int offset = (((u8 *)sta) - stapriv->pstainfo_buf)/sizeof(struct sta_info);
if (!stainfo_offset_valid(offset))
DBG_88E("%s invalid offset(%d), out of range!!!", __func__, offset);
return offset;
}
inline struct sta_info *rtw_get_stainfo_by_offset(struct sta_priv *stapriv, int offset)
{
if (!stainfo_offset_valid(offset))
DBG_88E("%s invalid offset(%d), out of range!!!", __func__, offset);
return (struct sta_info *)(stapriv->pstainfo_buf + offset * sizeof(struct sta_info));
}
static void rtw_mfree_all_stainfo(struct sta_priv *pstapriv)
{
struct list_head *plist, *phead;
struct sta_info *psta = NULL;
_func_enter_;
spin_lock_bh(&pstapriv->sta_hash_lock);
phead = get_list_head(&pstapriv->free_sta_queue);
plist = get_next(phead);
while ((rtw_end_of_queue_search(phead, plist)) == false) {
psta = LIST_CONTAINOR(plist, struct sta_info , list);
plist = get_next(plist);
}
spin_unlock_bh(&pstapriv->sta_hash_lock);
_func_exit_;
}
static void rtw_mfree_sta_priv_lock(struct sta_priv *pstapriv)
{
rtw_mfree_all_stainfo(pstapriv);
}
u32 _rtw_free_sta_priv(struct sta_priv *pstapriv)
{
struct list_head *phead, *plist;
struct sta_info *psta = NULL;
struct recv_reorder_ctrl *preorder_ctrl;
int index;
_func_enter_;
if (pstapriv) {
spin_lock_bh(&pstapriv->sta_hash_lock);
for (index = 0; index < NUM_STA; index++) {
phead = &(pstapriv->sta_hash[index]);
plist = get_next(phead);
while ((rtw_end_of_queue_search(phead, plist)) == false) {
int i;
psta = LIST_CONTAINOR(plist, struct sta_info , hash_list);
plist = get_next(plist);
for (i = 0; i < 16; i++) {
preorder_ctrl = &psta->recvreorder_ctrl[i];
_cancel_timer_ex(&preorder_ctrl->reordering_ctrl_timer);
}
}
}
spin_unlock_bh(&pstapriv->sta_hash_lock);
rtw_mfree_sta_priv_lock(pstapriv);
if (pstapriv->pallocated_stainfo_buf)
rtw_vmfree(pstapriv->pallocated_stainfo_buf, sizeof(struct sta_info)*NUM_STA+4);
}
_func_exit_;
return _SUCCESS;
}
struct sta_info *rtw_alloc_stainfo(struct sta_priv *pstapriv, u8 *hwaddr)
{
s32 index;
struct list_head *phash_list;
struct sta_info *psta;
struct __queue *pfree_sta_queue;
struct recv_reorder_ctrl *preorder_ctrl;
int i = 0;
u16 wRxSeqInitialValue = 0xffff;
_func_enter_;
pfree_sta_queue = &pstapriv->free_sta_queue;
spin_lock_bh(&(pfree_sta_queue->lock));
if (_rtw_queue_empty(pfree_sta_queue) == true) {
spin_unlock_bh(&pfree_sta_queue->lock);
psta = NULL;
} else {
psta = LIST_CONTAINOR(get_next(&pfree_sta_queue->queue), struct sta_info, list);
rtw_list_delete(&(psta->list));
spin_unlock_bh(&pfree_sta_queue->lock);
_rtw_init_stainfo(psta);
memcpy(psta->hwaddr, hwaddr, ETH_ALEN);
index = wifi_mac_hash(hwaddr);
RT_TRACE(_module_rtl871x_sta_mgt_c_, _drv_info_, ("rtw_alloc_stainfo: index=%x", index));
if (index >= NUM_STA) {
RT_TRACE(_module_rtl871x_sta_mgt_c_, _drv_err_, ("ERROR => rtw_alloc_stainfo: index >= NUM_STA"));
psta = NULL;
goto exit;
}
phash_list = &(pstapriv->sta_hash[index]);
spin_lock_bh(&(pstapriv->sta_hash_lock));
rtw_list_insert_tail(&psta->hash_list, phash_list);
pstapriv->asoc_sta_count++;
spin_unlock_bh(&pstapriv->sta_hash_lock);
for (i = 0; i < 16; i++)
memcpy(&psta->sta_recvpriv.rxcache.tid_rxseq[i], &wRxSeqInitialValue, 2);
RT_TRACE(_module_rtl871x_sta_mgt_c_, _drv_info_,
("alloc number_%d stainfo with hwaddr = %pM\n",
pstapriv->asoc_sta_count , hwaddr));
init_addba_retry_timer(pstapriv->padapter, psta);
for (i = 0; i < 16; i++) {
preorder_ctrl = &psta->recvreorder_ctrl[i];
preorder_ctrl->padapter = pstapriv->padapter;
preorder_ctrl->enable = false;
preorder_ctrl->indicate_seq = 0xffff;
preorder_ctrl->wend_b = 0xffff;
preorder_ctrl->wsize_b = 64;
_rtw_init_queue(&preorder_ctrl->pending_recvframe_queue);
rtw_init_recv_timer(preorder_ctrl);
}
psta->rssi_stat.UndecoratedSmoothedPWDB = (-1);
psta->rssi_stat.UndecoratedSmoothedCCK = (-1);
psta->RxMgmtFrameSeqNum = 0xffff;
}
exit:
_func_exit_;
return psta;
}
u32 rtw_free_stainfo(struct adapter *padapter , struct sta_info *psta)
{
int i;
struct __queue *pfree_sta_queue;
struct recv_reorder_ctrl *preorder_ctrl;
struct sta_xmit_priv *pstaxmitpriv;
struct xmit_priv *pxmitpriv = &padapter->xmitpriv;
struct sta_priv *pstapriv = &padapter->stapriv;
_func_enter_;
if (psta == NULL)
goto exit;
pfree_sta_queue = &pstapriv->free_sta_queue;
pstaxmitpriv = &psta->sta_xmitpriv;
spin_lock_bh(&pxmitpriv->lock);
rtw_free_xmitframe_queue(pxmitpriv, &psta->sleep_q);
psta->sleepq_len = 0;
rtw_free_xmitframe_queue(pxmitpriv, &pstaxmitpriv->vo_q.sta_pending);
rtw_list_delete(&(pstaxmitpriv->vo_q.tx_pending));
rtw_free_xmitframe_queue(pxmitpriv, &pstaxmitpriv->vi_q.sta_pending);
rtw_list_delete(&(pstaxmitpriv->vi_q.tx_pending));
rtw_free_xmitframe_queue(pxmitpriv, &pstaxmitpriv->bk_q.sta_pending);
rtw_list_delete(&(pstaxmitpriv->bk_q.tx_pending));
rtw_free_xmitframe_queue(pxmitpriv, &pstaxmitpriv->be_q.sta_pending);
rtw_list_delete(&(pstaxmitpriv->be_q.tx_pending));
spin_unlock_bh(&pxmitpriv->lock);
rtw_list_delete(&psta->hash_list);
RT_TRACE(_module_rtl871x_sta_mgt_c_, _drv_err_, ("\n free number_%d stainfo with hwaddr=0x%.2x 0x%.2x 0x%.2x 0x%.2x 0x%.2x 0x%.2x\n", pstapriv->asoc_sta_count , psta->hwaddr[0], psta->hwaddr[1], psta->hwaddr[2], psta->hwaddr[3], psta->hwaddr[4], psta->hwaddr[5]));
pstapriv->asoc_sta_count--;
_rtw_init_sta_xmit_priv(&psta->sta_xmitpriv);
_rtw_init_sta_recv_priv(&psta->sta_recvpriv);
_cancel_timer_ex(&psta->addba_retry_timer);
for (i = 0; i < 16; i++) {
struct list_head *phead, *plist;
union recv_frame *prframe;
struct __queue *ppending_recvframe_queue;
struct __queue *pfree_recv_queue = &padapter->recvpriv.free_recv_queue;
preorder_ctrl = &psta->recvreorder_ctrl[i];
_cancel_timer_ex(&preorder_ctrl->reordering_ctrl_timer);
ppending_recvframe_queue = &preorder_ctrl->pending_recvframe_queue;
spin_lock_bh(&ppending_recvframe_queue->lock);
phead = get_list_head(ppending_recvframe_queue);
plist = get_next(phead);
while (!rtw_is_list_empty(phead)) {
prframe = LIST_CONTAINOR(plist, union recv_frame, u);
plist = get_next(plist);
rtw_list_delete(&(prframe->u.hdr.list));
rtw_free_recvframe(prframe, pfree_recv_queue);
}
spin_unlock_bh(&ppending_recvframe_queue->lock);
}
if (!(psta->state & WIFI_AP_STATE))
rtw_hal_set_odm_var(padapter, HAL_ODM_STA_INFO, psta, false);
#ifdef CONFIG_88EU_AP_MODE
spin_lock_bh(&pstapriv->auth_list_lock);
if (!rtw_is_list_empty(&psta->auth_list)) {
rtw_list_delete(&psta->auth_list);
pstapriv->auth_list_cnt--;
}
spin_unlock_bh(&pstapriv->auth_list_lock);
psta->expire_to = 0;
psta->sleepq_ac_len = 0;
psta->qos_info = 0;
psta->max_sp_len = 0;
psta->uapsd_bk = 0;
psta->uapsd_be = 0;
psta->uapsd_vi = 0;
psta->uapsd_vo = 0;
psta->has_legacy_ac = 0;
pstapriv->sta_dz_bitmap &= ~BIT(psta->aid);
pstapriv->tim_bitmap &= ~BIT(psta->aid);
if ((psta->aid > 0) && (pstapriv->sta_aid[psta->aid - 1] == psta)) {
pstapriv->sta_aid[psta->aid - 1] = NULL;
psta->aid = 0;
}
psta->under_exist_checking = 0;
#endif
spin_lock_bh(&(pfree_sta_queue->lock));
rtw_list_insert_tail(&psta->list, get_list_head(pfree_sta_queue));
spin_unlock_bh(&pfree_sta_queue->lock);
exit:
_func_exit_;
return _SUCCESS;
}
void rtw_free_all_stainfo(struct adapter *padapter)
{
struct list_head *plist, *phead;
s32 index;
struct sta_info *psta = NULL;
struct sta_priv *pstapriv = &padapter->stapriv;
struct sta_info *pbcmc_stainfo = rtw_get_bcmc_stainfo(padapter);
_func_enter_;
if (pstapriv->asoc_sta_count == 1)
goto exit;
spin_lock_bh(&pstapriv->sta_hash_lock);
for (index = 0; index < NUM_STA; index++) {
phead = &(pstapriv->sta_hash[index]);
plist = get_next(phead);
while ((!rtw_end_of_queue_search(phead, plist))) {
psta = LIST_CONTAINOR(plist, struct sta_info , hash_list);
plist = get_next(plist);
if (pbcmc_stainfo != psta)
rtw_free_stainfo(padapter , psta);
}
}
spin_unlock_bh(&pstapriv->sta_hash_lock);
exit:
_func_exit_;
}
struct sta_info *rtw_get_stainfo(struct sta_priv *pstapriv, u8 *hwaddr)
{
struct list_head *plist, *phead;
struct sta_info *psta = NULL;
u32 index;
u8 *addr;
u8 bc_addr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
_func_enter_;
if (hwaddr == NULL)
return NULL;
if (IS_MCAST(hwaddr))
addr = bc_addr;
else
addr = hwaddr;
index = wifi_mac_hash(addr);
spin_lock_bh(&pstapriv->sta_hash_lock);
phead = &(pstapriv->sta_hash[index]);
plist = get_next(phead);
while ((!rtw_end_of_queue_search(phead, plist))) {
psta = LIST_CONTAINOR(plist, struct sta_info, hash_list);
if ((_rtw_memcmp(psta->hwaddr, addr, ETH_ALEN)) == true) {
break;
}
psta = NULL;
plist = get_next(plist);
}
spin_unlock_bh(&pstapriv->sta_hash_lock);
_func_exit_;
return psta;
}
u32 rtw_init_bcmc_stainfo(struct adapter *padapter)
{
struct sta_info *psta;
u32 res = _SUCCESS;
unsigned char bcast_addr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
struct sta_priv *pstapriv = &padapter->stapriv;
_func_enter_;
psta = rtw_alloc_stainfo(pstapriv, bcast_addr);
if (psta == NULL) {
res = _FAIL;
RT_TRACE(_module_rtl871x_sta_mgt_c_, _drv_err_, ("rtw_alloc_stainfo fail"));
goto exit;
}
psta->mac_id = 1;
exit:
_func_exit_;
return res;
}
struct sta_info *rtw_get_bcmc_stainfo(struct adapter *padapter)
{
struct sta_info *psta;
struct sta_priv *pstapriv = &padapter->stapriv;
u8 bc_addr[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
_func_enter_;
psta = rtw_get_stainfo(pstapriv, bc_addr);
_func_exit_;
return psta;
}
u8 rtw_access_ctrl(struct adapter *padapter, u8 *mac_addr)
{
u8 res = true;
#ifdef CONFIG_88EU_AP_MODE
struct list_head *plist, *phead;
struct rtw_wlan_acl_node *paclnode;
u8 match = false;
struct sta_priv *pstapriv = &padapter->stapriv;
struct wlan_acl_pool *pacl_list = &pstapriv->acl_list;
struct __queue *pacl_node_q = &pacl_list->acl_node_q;
spin_lock_bh(&(pacl_node_q->lock));
phead = get_list_head(pacl_node_q);
plist = get_next(phead);
while ((!rtw_end_of_queue_search(phead, plist))) {
paclnode = LIST_CONTAINOR(plist, struct rtw_wlan_acl_node, list);
plist = get_next(plist);
if (_rtw_memcmp(paclnode->addr, mac_addr, ETH_ALEN)) {
if (paclnode->valid) {
match = true;
break;
}
}
}
spin_unlock_bh(&pacl_node_q->lock);
if (pacl_list->mode == 1)
res = (match) ? false : true;
else if (pacl_list->mode == 2)
res = (match) ? true : false;
else
res = true;
#endif
return res;
}
