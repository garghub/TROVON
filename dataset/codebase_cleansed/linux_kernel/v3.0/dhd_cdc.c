static int dhdcdc_msg(dhd_pub_t *dhd)
{
dhd_prot_t *prot = dhd->prot;
int len = le32_to_cpu(prot->msg.len) + sizeof(cdc_ioctl_t);
DHD_TRACE(("%s: Enter\n", __func__));
if (len > CDC_MAX_MSG_SIZE)
len = CDC_MAX_MSG_SIZE;
return dhd_bus_txctl(dhd->bus, (unsigned char *)&prot->msg, len);
}
static int dhdcdc_cmplt(dhd_pub_t *dhd, u32 id, u32 len)
{
int ret;
dhd_prot_t *prot = dhd->prot;
DHD_TRACE(("%s: Enter\n", __func__));
do {
ret =
dhd_bus_rxctl(dhd->bus, (unsigned char *)&prot->msg,
len + sizeof(cdc_ioctl_t));
if (ret < 0)
break;
} while (CDC_IOC_ID(le32_to_cpu(prot->msg.flags)) != id);
return ret;
}
int
dhdcdc_query_ioctl(dhd_pub_t *dhd, int ifidx, uint cmd, void *buf, uint len)
{
dhd_prot_t *prot = dhd->prot;
cdc_ioctl_t *msg = &prot->msg;
void *info;
int ret = 0, retries = 0;
u32 id, flags = 0;
DHD_TRACE(("%s: Enter\n", __func__));
DHD_CTL(("%s: cmd %d len %d\n", __func__, cmd, len));
if (cmd == WLC_GET_VAR && buf) {
if (!strcmp((char *)buf, "bcmerrorstr")) {
strncpy((char *)buf, "bcm_error",
BCME_STRLEN);
goto done;
} else if (!strcmp((char *)buf, "bcmerror")) {
*(int *)buf = dhd->dongle_error;
goto done;
}
}
memset(msg, 0, sizeof(cdc_ioctl_t));
msg->cmd = cpu_to_le32(cmd);
msg->len = cpu_to_le32(len);
msg->flags = (++prot->reqid << CDCF_IOC_ID_SHIFT);
CDC_SET_IF_IDX(msg, ifidx);
msg->flags = cpu_to_le32(msg->flags);
if (buf)
memcpy(prot->buf, buf, len);
ret = dhdcdc_msg(dhd);
if (ret < 0) {
DHD_ERROR(("dhdcdc_query_ioctl: dhdcdc_msg failed w/status "
"%d\n", ret));
goto done;
}
retry:
ret = dhdcdc_cmplt(dhd, prot->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & CDCF_IOC_ID_MASK) >> CDCF_IOC_ID_SHIFT;
if ((id < prot->reqid) && (++retries < RETRIES))
goto retry;
if (id != prot->reqid) {
DHD_ERROR(("%s: %s: unexpected request id %d (expected %d)\n",
dhd_ifname(dhd, ifidx), __func__, id, prot->reqid));
ret = -EINVAL;
goto done;
}
info = (void *)&msg[1];
if (buf) {
if (ret < (int)len)
len = ret;
memcpy(buf, info, len);
}
if (flags & CDCF_IOC_ERROR) {
ret = le32_to_cpu(msg->status);
dhd->dongle_error = ret;
}
done:
return ret;
}
int dhdcdc_set_ioctl(dhd_pub_t *dhd, int ifidx, uint cmd, void *buf, uint len)
{
dhd_prot_t *prot = dhd->prot;
cdc_ioctl_t *msg = &prot->msg;
int ret = 0;
u32 flags, id;
DHD_TRACE(("%s: Enter\n", __func__));
DHD_CTL(("%s: cmd %d len %d\n", __func__, cmd, len));
memset(msg, 0, sizeof(cdc_ioctl_t));
msg->cmd = cpu_to_le32(cmd);
msg->len = cpu_to_le32(len);
msg->flags = (++prot->reqid << CDCF_IOC_ID_SHIFT) | CDCF_IOC_SET;
CDC_SET_IF_IDX(msg, ifidx);
msg->flags = cpu_to_le32(msg->flags);
if (buf)
memcpy(prot->buf, buf, len);
ret = dhdcdc_msg(dhd);
if (ret < 0)
goto done;
ret = dhdcdc_cmplt(dhd, prot->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & CDCF_IOC_ID_MASK) >> CDCF_IOC_ID_SHIFT;
if (id != prot->reqid) {
DHD_ERROR(("%s: %s: unexpected request id %d (expected %d)\n",
dhd_ifname(dhd, ifidx), __func__, id, prot->reqid));
ret = -EINVAL;
goto done;
}
if (flags & CDCF_IOC_ERROR) {
ret = le32_to_cpu(msg->status);
dhd->dongle_error = ret;
}
done:
return ret;
}
int
dhd_prot_ioctl(dhd_pub_t *dhd, int ifidx, wl_ioctl_t *ioc, void *buf, int len)
{
dhd_prot_t *prot = dhd->prot;
int ret = -1;
if (dhd->busstate == DHD_BUS_DOWN) {
DHD_ERROR(("%s : bus is down. we have nothing to do\n",
__func__));
return ret;
}
dhd_os_proto_block(dhd);
DHD_TRACE(("%s: Enter\n", __func__));
ASSERT(len <= WLC_IOCTL_MAXLEN);
if (len > WLC_IOCTL_MAXLEN)
goto done;
if (prot->pending == true) {
DHD_TRACE(("CDC packet is pending!!!! cmd=0x%x (%lu) "
"lastcmd=0x%x (%lu)\n",
ioc->cmd, (unsigned long)ioc->cmd, prot->lastcmd,
(unsigned long)prot->lastcmd));
if ((ioc->cmd == WLC_SET_VAR) || (ioc->cmd == WLC_GET_VAR))
DHD_TRACE(("iovar cmd=%s\n", (char *)buf));
goto done;
}
prot->pending = true;
prot->lastcmd = ioc->cmd;
if (ioc->set)
ret = dhdcdc_set_ioctl(dhd, ifidx, ioc->cmd, buf, len);
else {
ret = dhdcdc_query_ioctl(dhd, ifidx, ioc->cmd, buf, len);
if (ret > 0)
ioc->used = ret - sizeof(cdc_ioctl_t);
}
if (ret >= 0)
ret = 0;
else {
cdc_ioctl_t *msg = &prot->msg;
ioc->needed = le32_to_cpu(msg->len);
}
if ((!ret) && (ioc->cmd == WLC_SET_VAR) && (!strcmp(buf, "wme_dp"))) {
int slen, val = 0;
slen = strlen("wme_dp") + 1;
if (len >= (int)(slen + sizeof(int)))
memcpy(&val, (char *)buf + slen, sizeof(int));
dhd->wme_dp = (u8) le32_to_cpu(val);
}
prot->pending = false;
done:
dhd_os_proto_unblock(dhd);
return ret;
}
int
dhd_prot_iovar_op(dhd_pub_t *dhdp, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
return -ENOTSUPP;
}
void dhd_prot_dump(dhd_pub_t *dhdp, struct bcmstrbuf *strbuf)
{
bcm_bprintf(strbuf, "Protocol CDC: reqid %d\n", dhdp->prot->reqid);
}
void dhd_prot_hdrpush(dhd_pub_t *dhd, int ifidx, struct sk_buff *pktbuf)
{
#ifdef BDC
struct bdc_header *h;
#endif
DHD_TRACE(("%s: Enter\n", __func__));
#ifdef BDC
skb_push(pktbuf, BDC_HEADER_LEN);
h = (struct bdc_header *)(pktbuf->data);
h->flags = (BDC_PROTO_VER << BDC_FLAG_VER_SHIFT);
if (PKTSUMNEEDED(pktbuf))
h->flags |= BDC_FLAG_SUM_NEEDED;
h->priority = (pktbuf->priority & BDC_PRIORITY_MASK);
h->flags2 = 0;
h->rssi = 0;
#endif
BDC_SET_IF_IDX(h, ifidx);
}
int dhd_prot_hdrpull(dhd_pub_t *dhd, int *ifidx, struct sk_buff *pktbuf)
{
#ifdef BDC
struct bdc_header *h;
#endif
DHD_TRACE(("%s: Enter\n", __func__));
#ifdef BDC
if (pktbuf->len < BDC_HEADER_LEN) {
DHD_ERROR(("%s: rx data too short (%d < %d)\n", __func__,
pktbuf->len, BDC_HEADER_LEN));
return -EBADE;
}
h = (struct bdc_header *)(pktbuf->data);
*ifidx = BDC_GET_IF_IDX(h);
if (*ifidx >= DHD_MAX_IFS) {
DHD_ERROR(("%s: rx data ifnum out of range (%d)\n",
__func__, *ifidx));
return -EBADE;
}
if (((h->flags & BDC_FLAG_VER_MASK) >> BDC_FLAG_VER_SHIFT) !=
BDC_PROTO_VER) {
DHD_ERROR(("%s: non-BDC packet received, flags 0x%x\n",
dhd_ifname(dhd, *ifidx), h->flags));
return -EBADE;
}
if (h->flags & BDC_FLAG_SUM_GOOD) {
DHD_INFO(("%s: BDC packet received with good rx-csum, "
"flags 0x%x\n",
dhd_ifname(dhd, *ifidx), h->flags));
PKTSETSUMGOOD(pktbuf, true);
}
pktbuf->priority = h->priority & BDC_PRIORITY_MASK;
skb_pull(pktbuf, BDC_HEADER_LEN);
#endif
return 0;
}
int dhd_prot_attach(dhd_pub_t *dhd)
{
dhd_prot_t *cdc;
cdc = kzalloc(sizeof(dhd_prot_t), GFP_ATOMIC);
if (!cdc) {
DHD_ERROR(("%s: kmalloc failed\n", __func__));
goto fail;
}
if ((unsigned long)(&cdc->msg + 1) != (unsigned long)cdc->buf) {
DHD_ERROR(("dhd_prot_t is not correctly defined\n"));
goto fail;
}
dhd->prot = cdc;
#ifdef BDC
dhd->hdrlen += BDC_HEADER_LEN;
#endif
dhd->maxctl = WLC_IOCTL_MAXLEN + sizeof(cdc_ioctl_t) + ROUND_UP_MARGIN;
return 0;
fail:
kfree(cdc);
return -ENOMEM;
}
void dhd_prot_detach(dhd_pub_t *dhd)
{
kfree(dhd->prot);
dhd->prot = NULL;
}
void dhd_prot_dstats(dhd_pub_t *dhd)
{
dhd->dstats.tx_packets = dhd->tx_packets;
dhd->dstats.tx_errors = dhd->tx_errors;
dhd->dstats.rx_packets = dhd->rx_packets;
dhd->dstats.rx_errors = dhd->rx_errors;
dhd->dstats.rx_dropped = dhd->rx_dropped;
dhd->dstats.multicast = dhd->rx_multicast;
return;
}
int dhd_prot_init(dhd_pub_t *dhd)
{
int ret = 0;
char buf[128];
DHD_TRACE(("%s: Enter\n", __func__));
dhd_os_proto_block(dhd);
strcpy(buf, "cur_etheraddr");
ret = dhdcdc_query_ioctl(dhd, 0, WLC_GET_VAR, buf, sizeof(buf));
if (ret < 0) {
dhd_os_proto_unblock(dhd);
return ret;
}
memcpy(dhd->mac, buf, ETH_ALEN);
dhd_os_proto_unblock(dhd);
#ifdef EMBEDDED_PLATFORM
ret = dhd_preinit_ioctls(dhd);
#endif
dhd->iswl = true;
return ret;
}
void dhd_prot_stop(dhd_pub_t *dhd)
{
}
