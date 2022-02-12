static int brcmf_proto_cdc_msg(struct brcmf_pub *drvr)
{
struct brcmf_proto *prot = drvr->prot;
int len = le32_to_cpu(prot->msg.len) +
sizeof(struct brcmf_proto_cdc_dcmd);
brcmf_dbg(TRACE, "Enter\n");
if (len > CDC_MAX_MSG_SIZE)
len = CDC_MAX_MSG_SIZE;
return brcmf_bus_txctl(drvr->bus_if, (unsigned char *)&prot->msg, len);
}
static int brcmf_proto_cdc_cmplt(struct brcmf_pub *drvr, u32 id, u32 len)
{
int ret;
struct brcmf_proto *prot = drvr->prot;
brcmf_dbg(TRACE, "Enter\n");
len += sizeof(struct brcmf_proto_cdc_dcmd);
do {
ret = brcmf_bus_rxctl(drvr->bus_if, (unsigned char *)&prot->msg,
len);
if (ret < 0)
break;
} while (CDC_DCMD_ID(le32_to_cpu(prot->msg.flags)) != id);
return ret;
}
int
brcmf_proto_cdc_query_dcmd(struct brcmf_pub *drvr, int ifidx, uint cmd,
void *buf, uint len)
{
struct brcmf_proto *prot = drvr->prot;
struct brcmf_proto_cdc_dcmd *msg = &prot->msg;
void *info;
int ret = 0, retries = 0;
u32 id, flags;
brcmf_dbg(TRACE, "Enter\n");
brcmf_dbg(CTL, "cmd %d len %d\n", cmd, len);
if (cmd == BRCMF_C_GET_VAR && buf) {
if (!strcmp((char *)buf, "bcmerrorstr")) {
strncpy((char *)buf, "bcm_error",
BCME_STRLEN);
goto done;
} else if (!strcmp((char *)buf, "bcmerror")) {
*(int *)buf = drvr->dongle_error;
goto done;
}
}
memset(msg, 0, sizeof(struct brcmf_proto_cdc_dcmd));
msg->cmd = cpu_to_le32(cmd);
msg->len = cpu_to_le32(len);
flags = (++prot->reqid << CDC_DCMD_ID_SHIFT);
flags = (flags & ~CDC_DCMD_IF_MASK) |
(ifidx << CDC_DCMD_IF_SHIFT);
msg->flags = cpu_to_le32(flags);
if (buf)
memcpy(prot->buf, buf, len);
ret = brcmf_proto_cdc_msg(drvr);
if (ret < 0) {
brcmf_err("brcmf_proto_cdc_msg failed w/status %d\n",
ret);
goto done;
}
retry:
ret = brcmf_proto_cdc_cmplt(drvr, prot->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & CDC_DCMD_ID_MASK) >> CDC_DCMD_ID_SHIFT;
if ((id < prot->reqid) && (++retries < RETRIES))
goto retry;
if (id != prot->reqid) {
brcmf_err("%s: unexpected request id %d (expected %d)\n",
brcmf_ifname(drvr, ifidx), id, prot->reqid);
ret = -EINVAL;
goto done;
}
info = (void *)&msg[1];
if (buf) {
if (ret < (int)len)
len = ret;
memcpy(buf, info, len);
}
if (flags & CDC_DCMD_ERROR) {
ret = le32_to_cpu(msg->status);
drvr->dongle_error = ret;
}
done:
return ret;
}
int brcmf_proto_cdc_set_dcmd(struct brcmf_pub *drvr, int ifidx, uint cmd,
void *buf, uint len)
{
struct brcmf_proto *prot = drvr->prot;
struct brcmf_proto_cdc_dcmd *msg = &prot->msg;
int ret = 0;
u32 flags, id;
brcmf_dbg(TRACE, "Enter\n");
brcmf_dbg(CTL, "cmd %d len %d\n", cmd, len);
memset(msg, 0, sizeof(struct brcmf_proto_cdc_dcmd));
msg->cmd = cpu_to_le32(cmd);
msg->len = cpu_to_le32(len);
flags = (++prot->reqid << CDC_DCMD_ID_SHIFT) | CDC_DCMD_SET;
flags = (flags & ~CDC_DCMD_IF_MASK) |
(ifidx << CDC_DCMD_IF_SHIFT);
msg->flags = cpu_to_le32(flags);
if (buf)
memcpy(prot->buf, buf, len);
ret = brcmf_proto_cdc_msg(drvr);
if (ret < 0)
goto done;
ret = brcmf_proto_cdc_cmplt(drvr, prot->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & CDC_DCMD_ID_MASK) >> CDC_DCMD_ID_SHIFT;
if (id != prot->reqid) {
brcmf_err("%s: unexpected request id %d (expected %d)\n",
brcmf_ifname(drvr, ifidx), id, prot->reqid);
ret = -EINVAL;
goto done;
}
if (flags & CDC_DCMD_ERROR) {
ret = le32_to_cpu(msg->status);
drvr->dongle_error = ret;
}
done:
return ret;
}
static bool pkt_sum_needed(struct sk_buff *skb)
{
return skb->ip_summed == CHECKSUM_PARTIAL;
}
static void pkt_set_sum_good(struct sk_buff *skb, bool x)
{
skb->ip_summed = (x ? CHECKSUM_UNNECESSARY : CHECKSUM_NONE);
}
void brcmf_proto_hdrpush(struct brcmf_pub *drvr, int ifidx,
struct sk_buff *pktbuf)
{
struct brcmf_proto_bdc_header *h;
brcmf_dbg(TRACE, "Enter\n");
skb_push(pktbuf, BDC_HEADER_LEN);
h = (struct brcmf_proto_bdc_header *)(pktbuf->data);
h->flags = (BDC_PROTO_VER << BDC_FLAG_VER_SHIFT);
if (pkt_sum_needed(pktbuf))
h->flags |= BDC_FLAG_SUM_NEEDED;
h->priority = (pktbuf->priority & BDC_PRIORITY_MASK);
h->flags2 = 0;
h->data_offset = 0;
BDC_SET_IF_IDX(h, ifidx);
}
int brcmf_proto_hdrpull(struct device *dev, int *ifidx,
struct sk_buff *pktbuf)
{
struct brcmf_proto_bdc_header *h;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
brcmf_dbg(TRACE, "Enter\n");
if (pktbuf->len < BDC_HEADER_LEN) {
brcmf_err("rx data too short (%d < %d)\n",
pktbuf->len, BDC_HEADER_LEN);
return -EBADE;
}
h = (struct brcmf_proto_bdc_header *)(pktbuf->data);
*ifidx = BDC_GET_IF_IDX(h);
if (*ifidx >= BRCMF_MAX_IFS) {
brcmf_err("rx data ifnum out of range (%d)\n", *ifidx);
return -EBADE;
}
if (((h->flags & BDC_FLAG_VER_MASK) >> BDC_FLAG_VER_SHIFT) !=
BDC_PROTO_VER) {
brcmf_err("%s: non-BDC packet received, flags 0x%x\n",
brcmf_ifname(drvr, *ifidx), h->flags);
return -EBADE;
}
if (h->flags & BDC_FLAG_SUM_GOOD) {
brcmf_dbg(INFO, "%s: BDC packet received with good rx-csum, flags 0x%x\n",
brcmf_ifname(drvr, *ifidx), h->flags);
pkt_set_sum_good(pktbuf, true);
}
pktbuf->priority = h->priority & BDC_PRIORITY_MASK;
skb_pull(pktbuf, BDC_HEADER_LEN);
skb_pull(pktbuf, h->data_offset << 2);
return 0;
}
int brcmf_proto_attach(struct brcmf_pub *drvr)
{
struct brcmf_proto *cdc;
cdc = kzalloc(sizeof(struct brcmf_proto), GFP_ATOMIC);
if (!cdc)
goto fail;
if ((unsigned long)(&cdc->msg + 1) != (unsigned long)cdc->buf) {
brcmf_err("struct brcmf_proto is not correctly defined\n");
goto fail;
}
drvr->prot = cdc;
drvr->hdrlen += BDC_HEADER_LEN;
drvr->bus_if->maxctl = BRCMF_DCMD_MAXLEN +
sizeof(struct brcmf_proto_cdc_dcmd) + ROUND_UP_MARGIN;
return 0;
fail:
kfree(cdc);
return -ENOMEM;
}
void brcmf_proto_detach(struct brcmf_pub *drvr)
{
kfree(drvr->prot);
drvr->prot = NULL;
}
void brcmf_proto_stop(struct brcmf_pub *drvr)
{
}
