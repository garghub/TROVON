static uint remainder_len(struct pkt_file *pfile)
{
return (uint)(pfile->buf_len - ((addr_t)(pfile->cur_addr) -
(addr_t)(pfile->buf_start)));
}
void _r8712_open_pktfile(_pkt *pktptr, struct pkt_file *pfile)
{
pfile->pkt = pktptr;
pfile->cur_addr = pfile->buf_start = pktptr->data;
pfile->pkt_len = pfile->buf_len = pktptr->len;
pfile->cur_buffer = pfile->buf_start ;
}
uint _r8712_pktfile_read(struct pkt_file *pfile, u8 *rmem, uint rlen)
{
uint len;
len = remainder_len(pfile);
len = (rlen > len) ? len : rlen;
if (rmem)
skb_copy_bits(pfile->pkt, pfile->buf_len - pfile->pkt_len,
rmem, len);
pfile->cur_addr += len;
pfile->pkt_len -= len;
return len;
}
sint r8712_endofpktfile(struct pkt_file *pfile)
{
if (pfile->pkt_len == 0)
return true;
else
return false;
}
void r8712_set_qos(struct pkt_file *ppktfile, struct pkt_attrib *pattrib)
{
int i;
struct ethhdr etherhdr;
struct iphdr ip_hdr;
u16 UserPriority = 0;
_r8712_open_pktfile(ppktfile->pkt, ppktfile);
_r8712_pktfile_read(ppktfile, (unsigned char *)&etherhdr, ETH_HLEN);
if (pattrib->ether_type == 0x0800) {
i = _r8712_pktfile_read(ppktfile, (u8 *)&ip_hdr,
sizeof(ip_hdr));
UserPriority = ip_hdr.tos >> 5;
} else {
if (pattrib->ether_type == 0x888e)
UserPriority = 7;
}
pattrib->priority = UserPriority;
pattrib->hdrlen = WLAN_HDR_A3_QOS_LEN;
pattrib->subtype = WIFI_QOS_DATA_TYPE;
}
void r8712_SetFilter(struct work_struct *work)
{
struct _adapter *padapter = container_of(work, struct _adapter,
wkFilterRxFF0);
u8 oldvalue = 0x00, newvalue = 0x00;
unsigned long irqL;
oldvalue = r8712_read8(padapter, 0x117);
newvalue = oldvalue & 0xfe;
r8712_write8(padapter, 0x117, newvalue);
spin_lock_irqsave(&padapter->lockRxFF0Filter, irqL);
padapter->blnEnableRxFF0Filter = 1;
spin_unlock_irqrestore(&padapter->lockRxFF0Filter, irqL);
do {
msleep(100);
} while (padapter->blnEnableRxFF0Filter == 1);
r8712_write8(padapter, 0x117, oldvalue);
}
int r8712_xmit_resource_alloc(struct _adapter *padapter,
struct xmit_buf *pxmitbuf)
{
int i;
for (i = 0; i < 8; i++) {
pxmitbuf->pxmit_urb[i] = usb_alloc_urb(0, GFP_KERNEL);
if (pxmitbuf->pxmit_urb[i] == NULL) {
netdev_err(padapter->pnetdev, "pxmitbuf->pxmit_urb[i] == NULL\n");
return _FAIL;
}
}
return _SUCCESS;
}
void r8712_xmit_resource_free(struct _adapter *padapter,
struct xmit_buf *pxmitbuf)
{
int i;
for (i = 0; i < 8; i++) {
if (pxmitbuf->pxmit_urb[i]) {
usb_kill_urb(pxmitbuf->pxmit_urb[i]);
usb_free_urb(pxmitbuf->pxmit_urb[i]);
}
}
}
void r8712_xmit_complete(struct _adapter *padapter, struct xmit_frame *pxframe)
{
if (pxframe->pkt)
dev_kfree_skb_any(pxframe->pkt);
pxframe->pkt = NULL;
}
int r8712_xmit_entry(_pkt *pkt, struct net_device *pnetdev)
{
struct xmit_frame *pxmitframe = NULL;
struct _adapter *padapter = (struct _adapter *)netdev_priv(pnetdev);
struct xmit_priv *pxmitpriv = &(padapter->xmitpriv);
int ret = 0;
if (r8712_if_up(padapter) == false) {
ret = 0;
goto _xmit_entry_drop;
}
pxmitframe = r8712_alloc_xmitframe(pxmitpriv);
if (pxmitframe == NULL) {
ret = 0;
goto _xmit_entry_drop;
}
if ((!r8712_update_attrib(padapter, pkt, &pxmitframe->attrib))) {
ret = 0;
goto _xmit_entry_drop;
}
padapter->ledpriv.LedControlHandler(padapter, LED_CTL_TX);
pxmitframe->pkt = pkt;
if (r8712_pre_xmit(padapter, pxmitframe) == true) {
dev_kfree_skb_any(pkt);
pxmitframe->pkt = NULL;
}
pxmitpriv->tx_pkts++;
pxmitpriv->tx_bytes += pxmitframe->attrib.last_txcmdsz;
return ret;
_xmit_entry_drop:
if (pxmitframe)
r8712_free_xmitframe(pxmitpriv, pxmitframe);
pxmitpriv->tx_drop++;
dev_kfree_skb_any(pkt);
return ret;
}
