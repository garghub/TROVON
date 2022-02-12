s32 rtl8188eu_init_xmit_priv(struct adapter *adapt)
{
struct xmit_priv *pxmitpriv = &adapt->xmitpriv;
tasklet_init(&pxmitpriv->xmit_tasklet,
(void(*)(unsigned long))rtl8188eu_xmit_tasklet,
(unsigned long)adapt);
return _SUCCESS;
}
static u8 urb_zero_packet_chk(struct adapter *adapt, int sz)
{
u8 set_tx_desc_offset;
struct hal_data_8188e *haldata = GET_HAL_DATA(adapt);
set_tx_desc_offset = (((sz + TXDESC_SIZE) % haldata->UsbBulkOutSize) == 0) ? 1 : 0;
return set_tx_desc_offset;
}
static void rtl8188eu_cal_txdesc_chksum(struct tx_desc *ptxdesc)
{
u16 *usptr = (u16 *)ptxdesc;
u32 count = 16;
u32 index;
u16 checksum = 0;
ptxdesc->txdw7 &= cpu_to_le32(0xffff0000);
for (index = 0; index < count; index++)
checksum = checksum ^ le16_to_cpu(*(__le16 *)(usptr + index));
ptxdesc->txdw7 |= cpu_to_le32(0x0000ffff & checksum);
}
void rtl8188e_fill_fake_txdesc(struct adapter *adapt, u8 *desc, u32 BufferLen, u8 ispspoll, u8 is_btqosnull)
{
struct tx_desc *ptxdesc;
ptxdesc = (struct tx_desc *)desc;
memset(desc, 0, TXDESC_SIZE);
ptxdesc->txdw0 |= cpu_to_le32(OWN | FSG | LSG);
ptxdesc->txdw0 |= cpu_to_le32(((TXDESC_SIZE+OFFSET_SZ)<<OFFSET_SHT)&0x00ff0000);
ptxdesc->txdw0 |= cpu_to_le32(BufferLen&0x0000ffff);
ptxdesc->txdw1 |= cpu_to_le32((QSLT_MGNT<<QSEL_SHT)&0x00001f00);
if (ispspoll) {
ptxdesc->txdw1 |= cpu_to_le32(NAVUSEHDR);
} else {
ptxdesc->txdw4 |= cpu_to_le32(BIT(7));
ptxdesc->txdw3 |= cpu_to_le32((8 << 28));
}
if (is_btqosnull)
ptxdesc->txdw2 |= cpu_to_le32(BIT(23));
ptxdesc->txdw4 |= cpu_to_le32(BIT(8));
rtl8188eu_cal_txdesc_chksum(ptxdesc);
}
static void fill_txdesc_sectype(struct pkt_attrib *pattrib, struct tx_desc *ptxdesc)
{
if ((pattrib->encrypt > 0) && !pattrib->bswenc) {
switch (pattrib->encrypt) {
case _WEP40_:
case _WEP104_:
ptxdesc->txdw1 |= cpu_to_le32((0x01<<SEC_TYPE_SHT)&0x00c00000);
ptxdesc->txdw2 |= cpu_to_le32(0x7 << AMPDU_DENSITY_SHT);
break;
case _TKIP_:
case _TKIP_WTMIC_:
ptxdesc->txdw1 |= cpu_to_le32((0x01<<SEC_TYPE_SHT)&0x00c00000);
ptxdesc->txdw2 |= cpu_to_le32(0x7 << AMPDU_DENSITY_SHT);
break;
case _AES_:
ptxdesc->txdw1 |= cpu_to_le32((0x03<<SEC_TYPE_SHT)&0x00c00000);
ptxdesc->txdw2 |= cpu_to_le32(0x7 << AMPDU_DENSITY_SHT);
break;
case _NO_PRIVACY_:
default:
break;
}
}
}
static void fill_txdesc_vcs(struct pkt_attrib *pattrib, __le32 *pdw)
{
switch (pattrib->vcs_mode) {
case RTS_CTS:
*pdw |= cpu_to_le32(RTS_EN);
break;
case CTS_TO_SELF:
*pdw |= cpu_to_le32(CTS_2_SELF);
break;
case NONE_VCS:
default:
break;
}
if (pattrib->vcs_mode) {
*pdw |= cpu_to_le32(HW_RTS_EN);
if (pattrib->ht_en) {
*pdw |= (pattrib->bwmode&HT_CHANNEL_WIDTH_40) ? cpu_to_le32(BIT(27)) : 0;
if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_LOWER)
*pdw |= cpu_to_le32((0x01 << 28) & 0x30000000);
else if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_UPPER)
*pdw |= cpu_to_le32((0x02 << 28) & 0x30000000);
else if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_DONT_CARE)
*pdw |= 0;
else
*pdw |= cpu_to_le32((0x03 << 28) & 0x30000000);
}
}
}
static void fill_txdesc_phy(struct pkt_attrib *pattrib, __le32 *pdw)
{
if (pattrib->ht_en) {
*pdw |= (pattrib->bwmode&HT_CHANNEL_WIDTH_40) ? cpu_to_le32(BIT(25)) : 0;
if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_LOWER)
*pdw |= cpu_to_le32((0x01 << DATA_SC_SHT) & 0x003f0000);
else if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_UPPER)
*pdw |= cpu_to_le32((0x02 << DATA_SC_SHT) & 0x003f0000);
else if (pattrib->ch_offset == HAL_PRIME_CHNL_OFFSET_DONT_CARE)
*pdw |= 0;
else
*pdw |= cpu_to_le32((0x03 << DATA_SC_SHT) & 0x003f0000);
}
}
static s32 update_txdesc(struct xmit_frame *pxmitframe, u8 *pmem, s32 sz, u8 bagg_pkt)
{
int pull = 0;
uint qsel;
u8 data_rate, pwr_status, offset;
struct adapter *adapt = pxmitframe->padapter;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct hal_data_8188e *haldata = GET_HAL_DATA(adapt);
struct tx_desc *ptxdesc = (struct tx_desc *)pmem;
struct mlme_ext_priv *pmlmeext = &adapt->mlmeextpriv;
struct mlme_ext_info *pmlmeinfo = &(pmlmeext->mlmext_info);
int bmcst = IS_MCAST(pattrib->ra);
if (adapt->registrypriv.mp_mode == 0) {
if ((!bagg_pkt) && (urb_zero_packet_chk(adapt, sz) == 0)) {
ptxdesc = (struct tx_desc *)(pmem+PACKET_OFFSET_SZ);
pull = 1;
}
}
memset(ptxdesc, 0, sizeof(struct tx_desc));
ptxdesc->txdw0 |= cpu_to_le32(OWN | FSG | LSG);
ptxdesc->txdw0 |= cpu_to_le32(sz & 0x0000ffff);
offset = TXDESC_SIZE + OFFSET_SZ;
ptxdesc->txdw0 |= cpu_to_le32(((offset) << OFFSET_SHT) & 0x00ff0000);
if (bmcst)
ptxdesc->txdw0 |= cpu_to_le32(BMC);
if (adapt->registrypriv.mp_mode == 0) {
if (!bagg_pkt) {
if ((pull) && (pxmitframe->pkt_offset > 0))
pxmitframe->pkt_offset = pxmitframe->pkt_offset - 1;
}
}
if (pxmitframe->pkt_offset > 0)
ptxdesc->txdw1 |= cpu_to_le32((pxmitframe->pkt_offset << 26) & 0x7c000000);
ptxdesc->txdw4 |= cpu_to_le32(USERATE);
if ((pxmitframe->frame_tag & 0x0f) == DATA_FRAMETAG) {
ptxdesc->txdw1 |= cpu_to_le32(pattrib->mac_id & 0x3F);
qsel = (uint)(pattrib->qsel & 0x0000001f);
ptxdesc->txdw1 |= cpu_to_le32((qsel << QSEL_SHT) & 0x00001f00);
ptxdesc->txdw1 |= cpu_to_le32((pattrib->raid << RATE_ID_SHT) & 0x000F0000);
fill_txdesc_sectype(pattrib, ptxdesc);
if (pattrib->ampdu_en) {
ptxdesc->txdw2 |= cpu_to_le32(AGG_EN);
ptxdesc->txdw6 = cpu_to_le32(0x6666f800);
} else {
ptxdesc->txdw2 |= cpu_to_le32(AGG_BK);
}
ptxdesc->txdw3 |= cpu_to_le32((pattrib->seqnum << SEQ_SHT) & 0x0FFF0000);
if (pattrib->qos_en)
ptxdesc->txdw4 |= cpu_to_le32(QOS);
if (pxmitframe->agg_num > 1)
ptxdesc->txdw5 |= cpu_to_le32((pxmitframe->agg_num << USB_TXAGG_NUM_SHT) & 0xFF000000);
if ((pattrib->ether_type != 0x888e) &&
(pattrib->ether_type != 0x0806) &&
(pattrib->ether_type != 0x88b4) &&
(pattrib->dhcp_pkt != 1)) {
fill_txdesc_vcs(pattrib, &ptxdesc->txdw4);
fill_txdesc_phy(pattrib, &ptxdesc->txdw4);
ptxdesc->txdw4 |= cpu_to_le32(0x00000008);
ptxdesc->txdw5 |= cpu_to_le32(0x0001ff00);
if (pattrib->ht_en) {
if (ODM_RA_GetShortGI_8188E(&haldata->odmpriv, pattrib->mac_id))
ptxdesc->txdw5 |= cpu_to_le32(SGI);
}
data_rate = ODM_RA_GetDecisionRate_8188E(&haldata->odmpriv, pattrib->mac_id);
ptxdesc->txdw5 |= cpu_to_le32(data_rate & 0x3F);
pwr_status = ODM_RA_GetHwPwrStatus_8188E(&haldata->odmpriv, pattrib->mac_id);
ptxdesc->txdw4 |= cpu_to_le32((pwr_status & 0x7) << PWR_STATUS_SHT);
} else {
ptxdesc->txdw2 |= cpu_to_le32(AGG_BK);
if (pmlmeinfo->preamble_mode == PREAMBLE_SHORT)
ptxdesc->txdw4 |= cpu_to_le32(BIT(24));
ptxdesc->txdw5 |= cpu_to_le32(MRateToHwRate(pmlmeext->tx_rate));
}
} else if ((pxmitframe->frame_tag&0x0f) == MGNT_FRAMETAG) {
ptxdesc->txdw1 |= cpu_to_le32(pattrib->mac_id & 0x3f);
qsel = (uint)(pattrib->qsel&0x0000001f);
ptxdesc->txdw1 |= cpu_to_le32((qsel << QSEL_SHT) & 0x00001f00);
ptxdesc->txdw1 |= cpu_to_le32((pattrib->raid << RATE_ID_SHT) & 0x000f0000);
if (pxmitframe->ack_report)
ptxdesc->txdw2 |= cpu_to_le32(BIT(19));
ptxdesc->txdw3 |= cpu_to_le32((pattrib->seqnum<<SEQ_SHT)&0x0FFF0000);
ptxdesc->txdw5 |= cpu_to_le32(RTY_LMT_EN);
if (pattrib->retry_ctrl)
ptxdesc->txdw5 |= cpu_to_le32(0x00180000);
else
ptxdesc->txdw5 |= cpu_to_le32(0x00300000);
ptxdesc->txdw5 |= cpu_to_le32(MRateToHwRate(pmlmeext->tx_rate));
} else if ((pxmitframe->frame_tag&0x0f) == TXAGG_FRAMETAG) {
DBG_88E("pxmitframe->frame_tag == TXAGG_FRAMETAG\n");
} else {
DBG_88E("pxmitframe->frame_tag = %d\n", pxmitframe->frame_tag);
ptxdesc->txdw1 |= cpu_to_le32((4) & 0x3f);
ptxdesc->txdw1 |= cpu_to_le32((6 << RATE_ID_SHT) & 0x000f0000);
ptxdesc->txdw3 |= cpu_to_le32((pattrib->seqnum<<SEQ_SHT)&0x0fff0000);
ptxdesc->txdw5 |= cpu_to_le32(MRateToHwRate(pmlmeext->tx_rate));
}
if (!pattrib->qos_en) {
ptxdesc->txdw3 |= cpu_to_le32(EN_HWSEQ);
ptxdesc->txdw4 |= cpu_to_le32(HW_SSN);
}
rtl88eu_dm_set_tx_ant_by_tx_info(&haldata->odmpriv, pmem,
pattrib->mac_id);
rtl8188eu_cal_txdesc_chksum(ptxdesc);
_dbg_dump_tx_info(adapt, pxmitframe->frame_tag, ptxdesc);
return pull;
}
static s32 rtw_dump_xframe(struct adapter *adapt, struct xmit_frame *pxmitframe)
{
s32 ret = _SUCCESS;
s32 inner_ret = _SUCCESS;
int t, sz, w_sz, pull = 0;
u8 *mem_addr;
u32 ff_hwaddr;
struct xmit_buf *pxmitbuf = pxmitframe->pxmitbuf;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct xmit_priv *pxmitpriv = &adapt->xmitpriv;
struct security_priv *psecuritypriv = &adapt->securitypriv;
if ((pxmitframe->frame_tag == DATA_FRAMETAG) &&
(pxmitframe->attrib.ether_type != 0x0806) &&
(pxmitframe->attrib.ether_type != 0x888e) &&
(pxmitframe->attrib.ether_type != 0x88b4) &&
(pxmitframe->attrib.dhcp_pkt != 1))
rtw_issue_addbareq_cmd(adapt, pxmitframe);
mem_addr = pxmitframe->buf_addr;
RT_TRACE(_module_rtl871x_xmit_c_, _drv_info_, ("rtw_dump_xframe()\n"));
for (t = 0; t < pattrib->nr_frags; t++) {
if (inner_ret != _SUCCESS && ret == _SUCCESS)
ret = _FAIL;
if (t != (pattrib->nr_frags - 1)) {
RT_TRACE(_module_rtl871x_xmit_c_, _drv_err_, ("pattrib->nr_frags=%d\n", pattrib->nr_frags));
sz = pxmitpriv->frag_len;
sz = sz - 4 - (psecuritypriv->sw_encrypt ? 0 : pattrib->icv_len);
} else {
sz = pattrib->last_txcmdsz;
}
pull = update_txdesc(pxmitframe, mem_addr, sz, false);
if (pull) {
mem_addr += PACKET_OFFSET_SZ;
pxmitframe->buf_addr = mem_addr;
w_sz = sz + TXDESC_SIZE;
} else {
w_sz = sz + TXDESC_SIZE + PACKET_OFFSET_SZ;
}
ff_hwaddr = rtw_get_ff_hwaddr(pxmitframe);
inner_ret = usb_write_port(adapt, ff_hwaddr, w_sz, (unsigned char *)pxmitbuf);
rtw_count_tx_stats(adapt, pxmitframe, sz);
RT_TRACE(_module_rtl871x_xmit_c_, _drv_info_, ("rtw_write_port, w_sz=%d\n", w_sz));
mem_addr += w_sz;
mem_addr = (u8 *)round_up((size_t)mem_addr, 4);
}
rtw_free_xmitframe(pxmitpriv, pxmitframe);
if (ret != _SUCCESS)
rtw_sctx_done_err(&pxmitbuf->sctx, RTW_SCTX_DONE_UNKNOWN);
return ret;
}
static u32 xmitframe_need_length(struct xmit_frame *pxmitframe)
{
struct pkt_attrib *pattrib = &pxmitframe->attrib;
u32 len = 0;
len = pattrib->hdrlen + pattrib->iv_len +
SNAP_SIZE + sizeof(u16) +
pattrib->pktlen +
((pattrib->bswenc) ? pattrib->icv_len : 0);
if (pattrib->encrypt == _TKIP_)
len += 8;
return len;
}
s32 rtl8188eu_xmitframe_complete(struct adapter *adapt, struct xmit_priv *pxmitpriv, struct xmit_buf *pxmitbuf)
{
struct hal_data_8188e *haldata = GET_HAL_DATA(adapt);
struct xmit_frame *pxmitframe = NULL;
struct xmit_frame *pfirstframe = NULL;
struct hw_xmit *phwxmit;
struct sta_info *psta = NULL;
struct tx_servq *ptxservq = NULL;
struct list_head *xmitframe_plist = NULL, *xmitframe_phead = NULL;
u32 pbuf;
u32 pbuf_tail;
u32 len;
u32 bulksize = haldata->UsbBulkOutSize;
u8 desc_cnt;
u32 bulkptr;
u32 ff_hwaddr;
RT_TRACE(_module_rtl8192c_xmit_c_, _drv_info_, ("+xmitframe_complete\n"));
if (pxmitbuf == NULL) {
pxmitbuf = rtw_alloc_xmitbuf(pxmitpriv);
if (pxmitbuf == NULL)
return false;
}
do {
rtw_free_xmitframe(pxmitpriv, pxmitframe);
pxmitframe = rtw_dequeue_xframe(pxmitpriv, pxmitpriv->hwxmits, pxmitpriv->hwxmit_entry);
if (pxmitframe == NULL) {
rtw_free_xmitbuf(pxmitpriv, pxmitbuf);
return false;
}
pxmitframe->pxmitbuf = pxmitbuf;
pxmitframe->buf_addr = pxmitbuf->pbuf;
pxmitbuf->priv_data = pxmitframe;
pxmitframe->agg_num = 1;
pxmitframe->pkt_offset = 1;
rtw_xmitframe_coalesce(adapt, pxmitframe->pkt, pxmitframe);
rtw_os_xmit_complete(adapt, pxmitframe);
break;
} while (1);
pfirstframe = pxmitframe;
len = xmitframe_need_length(pfirstframe) + TXDESC_SIZE + (pfirstframe->pkt_offset*PACKET_OFFSET_SZ);
pbuf_tail = len;
pbuf = round_up(pbuf_tail, 8);
desc_cnt = 0;
bulkptr = bulksize;
if (pbuf < bulkptr) {
desc_cnt++;
} else {
desc_cnt = 0;
bulkptr = ((pbuf / bulksize) + 1) * bulksize;
}
psta = pfirstframe->attrib.psta;
switch (pfirstframe->attrib.priority) {
case 1:
case 2:
ptxservq = &(psta->sta_xmitpriv.bk_q);
phwxmit = pxmitpriv->hwxmits + 3;
break;
case 4:
case 5:
ptxservq = &(psta->sta_xmitpriv.vi_q);
phwxmit = pxmitpriv->hwxmits + 1;
break;
case 6:
case 7:
ptxservq = &(psta->sta_xmitpriv.vo_q);
phwxmit = pxmitpriv->hwxmits;
break;
case 0:
case 3:
default:
ptxservq = &(psta->sta_xmitpriv.be_q);
phwxmit = pxmitpriv->hwxmits + 2;
break;
}
spin_lock_bh(&pxmitpriv->lock);
xmitframe_phead = get_list_head(&ptxservq->sta_pending);
xmitframe_plist = xmitframe_phead->next;
while (xmitframe_phead != xmitframe_plist) {
pxmitframe = container_of(xmitframe_plist, struct xmit_frame, list);
xmitframe_plist = xmitframe_plist->next;
pxmitframe->agg_num = 0;
pxmitframe->pkt_offset = 0;
len = xmitframe_need_length(pxmitframe) + TXDESC_SIZE + (pxmitframe->pkt_offset*PACKET_OFFSET_SZ);
if (round_up(pbuf + len, 8) > MAX_XMITBUF_SZ) {
pxmitframe->agg_num = 1;
pxmitframe->pkt_offset = 1;
break;
}
list_del_init(&pxmitframe->list);
ptxservq->qcnt--;
phwxmit->accnt--;
pxmitframe->buf_addr = pxmitbuf->pbuf + pbuf;
rtw_xmitframe_coalesce(adapt, pxmitframe->pkt, pxmitframe);
rtw_os_xmit_complete(adapt, pxmitframe);
update_txdesc(pxmitframe, pxmitframe->buf_addr, pxmitframe->attrib.last_txcmdsz, true);
rtw_free_xmitframe(pxmitpriv, pxmitframe);
pbuf_tail = pbuf + len;
pbuf = round_up(pbuf_tail, 8);
pfirstframe->agg_num++;
if (MAX_TX_AGG_PACKET_NUMBER == pfirstframe->agg_num)
break;
if (pbuf < bulkptr) {
desc_cnt++;
if (desc_cnt == haldata->UsbTxAggDescNum)
break;
} else {
desc_cnt = 0;
bulkptr = ((pbuf / bulksize) + 1) * bulksize;
}
}
if (list_empty(&ptxservq->sta_pending.queue))
list_del_init(&ptxservq->tx_pending);
spin_unlock_bh(&pxmitpriv->lock);
if ((pfirstframe->attrib.ether_type != 0x0806) &&
(pfirstframe->attrib.ether_type != 0x888e) &&
(pfirstframe->attrib.ether_type != 0x88b4) &&
(pfirstframe->attrib.dhcp_pkt != 1))
rtw_issue_addbareq_cmd(adapt, pfirstframe);
if ((pbuf_tail % bulksize) == 0) {
pbuf_tail -= PACKET_OFFSET_SZ;
pfirstframe->buf_addr += PACKET_OFFSET_SZ;
pfirstframe->pkt_offset--;
}
update_txdesc(pfirstframe, pfirstframe->buf_addr, pfirstframe->attrib.last_txcmdsz, true);
ff_hwaddr = rtw_get_ff_hwaddr(pfirstframe);
usb_write_port(adapt, ff_hwaddr, pbuf_tail, (u8 *)pxmitbuf);
pbuf_tail -= (pfirstframe->agg_num * TXDESC_SIZE);
pbuf_tail -= (pfirstframe->pkt_offset * PACKET_OFFSET_SZ);
rtw_count_tx_stats(adapt, pfirstframe, pbuf_tail);
rtw_free_xmitframe(pxmitpriv, pfirstframe);
return true;
}
static s32 xmitframe_direct(struct adapter *adapt, struct xmit_frame *pxmitframe)
{
s32 res = _SUCCESS;
res = rtw_xmitframe_coalesce(adapt, pxmitframe->pkt, pxmitframe);
if (res == _SUCCESS)
rtw_dump_xframe(adapt, pxmitframe);
else
DBG_88E("==> %s xmitframe_coalsece failed\n", __func__);
return res;
}
static s32 pre_xmitframe(struct adapter *adapt, struct xmit_frame *pxmitframe)
{
s32 res;
struct xmit_buf *pxmitbuf = NULL;
struct xmit_priv *pxmitpriv = &adapt->xmitpriv;
struct pkt_attrib *pattrib = &pxmitframe->attrib;
struct mlme_priv *pmlmepriv = &adapt->mlmepriv;
spin_lock_bh(&pxmitpriv->lock);
if (rtw_txframes_sta_ac_pending(adapt, pattrib) > 0)
goto enqueue;
if (check_fwstate(pmlmepriv, _FW_UNDER_SURVEY|_FW_UNDER_LINKING) == true)
goto enqueue;
pxmitbuf = rtw_alloc_xmitbuf(pxmitpriv);
if (!pxmitbuf)
goto enqueue;
spin_unlock_bh(&pxmitpriv->lock);
pxmitframe->pxmitbuf = pxmitbuf;
pxmitframe->buf_addr = pxmitbuf->pbuf;
pxmitbuf->priv_data = pxmitframe;
if (xmitframe_direct(adapt, pxmitframe) != _SUCCESS) {
rtw_free_xmitbuf(pxmitpriv, pxmitbuf);
rtw_free_xmitframe(pxmitpriv, pxmitframe);
}
return true;
enqueue:
res = rtw_xmitframe_enqueue(adapt, pxmitframe);
spin_unlock_bh(&pxmitpriv->lock);
if (res != _SUCCESS) {
RT_TRACE(_module_xmit_osdep_c_, _drv_err_, ("pre_xmitframe: enqueue xmitframe fail\n"));
rtw_free_xmitframe(pxmitpriv, pxmitframe);
pxmitpriv->tx_pkts--;
pxmitpriv->tx_drop++;
return true;
}
return false;
}
s32 rtl8188eu_mgnt_xmit(struct adapter *adapt, struct xmit_frame *pmgntframe)
{
struct xmit_priv *xmitpriv = &adapt->xmitpriv;
rtl88eu_mon_xmit_hook(adapt->pmondev, pmgntframe, xmitpriv->frag_len);
return rtw_dump_xframe(adapt, pmgntframe);
}
s32 rtl8188eu_hal_xmit(struct adapter *adapt, struct xmit_frame *pxmitframe)
{
return pre_xmitframe(adapt, pxmitframe);
}
