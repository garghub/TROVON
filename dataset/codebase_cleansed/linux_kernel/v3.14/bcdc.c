static int
brcmf_proto_bcdc_msg(struct brcmf_pub *drvr, int ifidx, uint cmd, void *buf,
uint len, bool set)
{
struct brcmf_bcdc *bcdc = (struct brcmf_bcdc *)drvr->proto->pd;
struct brcmf_proto_bcdc_dcmd *msg = &bcdc->msg;
u32 flags;
brcmf_dbg(BCDC, "Enter\n");
memset(msg, 0, sizeof(struct brcmf_proto_bcdc_dcmd));
msg->cmd = cpu_to_le32(cmd);
msg->len = cpu_to_le32(len);
flags = (++bcdc->reqid << BCDC_DCMD_ID_SHIFT);
if (set)
flags |= BCDC_DCMD_SET;
flags = (flags & ~BCDC_DCMD_IF_MASK) |
(ifidx << BCDC_DCMD_IF_SHIFT);
msg->flags = cpu_to_le32(flags);
if (buf)
memcpy(bcdc->buf, buf, len);
len += sizeof(*msg);
if (len > BRCMF_TX_IOCTL_MAX_MSG_SIZE)
len = BRCMF_TX_IOCTL_MAX_MSG_SIZE;
return brcmf_bus_txctl(drvr->bus_if, (unsigned char *)&bcdc->msg, len);
}
static int brcmf_proto_bcdc_cmplt(struct brcmf_pub *drvr, u32 id, u32 len)
{
int ret;
struct brcmf_bcdc *bcdc = (struct brcmf_bcdc *)drvr->proto->pd;
brcmf_dbg(BCDC, "Enter\n");
len += sizeof(struct brcmf_proto_bcdc_dcmd);
do {
ret = brcmf_bus_rxctl(drvr->bus_if, (unsigned char *)&bcdc->msg,
len);
if (ret < 0)
break;
} while (BCDC_DCMD_ID(le32_to_cpu(bcdc->msg.flags)) != id);
return ret;
}
static int
brcmf_proto_bcdc_query_dcmd(struct brcmf_pub *drvr, int ifidx, uint cmd,
void *buf, uint len)
{
struct brcmf_bcdc *bcdc = (struct brcmf_bcdc *)drvr->proto->pd;
struct brcmf_proto_bcdc_dcmd *msg = &bcdc->msg;
void *info;
int ret = 0, retries = 0;
u32 id, flags;
brcmf_dbg(BCDC, "Enter, cmd %d len %d\n", cmd, len);
ret = brcmf_proto_bcdc_msg(drvr, ifidx, cmd, buf, len, false);
if (ret < 0) {
brcmf_err("brcmf_proto_bcdc_msg failed w/status %d\n",
ret);
goto done;
}
retry:
ret = brcmf_proto_bcdc_cmplt(drvr, bcdc->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & BCDC_DCMD_ID_MASK) >> BCDC_DCMD_ID_SHIFT;
if ((id < bcdc->reqid) && (++retries < RETRIES))
goto retry;
if (id != bcdc->reqid) {
brcmf_err("%s: unexpected request id %d (expected %d)\n",
brcmf_ifname(drvr, ifidx), id, bcdc->reqid);
ret = -EINVAL;
goto done;
}
info = (void *)&msg[1];
if (buf) {
if (ret < (int)len)
len = ret;
memcpy(buf, info, len);
}
if (flags & BCDC_DCMD_ERROR)
ret = le32_to_cpu(msg->status);
done:
return ret;
}
static int
brcmf_proto_bcdc_set_dcmd(struct brcmf_pub *drvr, int ifidx, uint cmd,
void *buf, uint len)
{
struct brcmf_bcdc *bcdc = (struct brcmf_bcdc *)drvr->proto->pd;
struct brcmf_proto_bcdc_dcmd *msg = &bcdc->msg;
int ret = 0;
u32 flags, id;
brcmf_dbg(BCDC, "Enter, cmd %d len %d\n", cmd, len);
ret = brcmf_proto_bcdc_msg(drvr, ifidx, cmd, buf, len, true);
if (ret < 0)
goto done;
ret = brcmf_proto_bcdc_cmplt(drvr, bcdc->reqid, len);
if (ret < 0)
goto done;
flags = le32_to_cpu(msg->flags);
id = (flags & BCDC_DCMD_ID_MASK) >> BCDC_DCMD_ID_SHIFT;
if (id != bcdc->reqid) {
brcmf_err("%s: unexpected request id %d (expected %d)\n",
brcmf_ifname(drvr, ifidx), id, bcdc->reqid);
ret = -EINVAL;
goto done;
}
if (flags & BCDC_DCMD_ERROR)
ret = le32_to_cpu(msg->status);
done:
return ret;
}
static void
brcmf_proto_bcdc_hdrpush(struct brcmf_pub *drvr, int ifidx, u8 offset,
struct sk_buff *pktbuf)
{
struct brcmf_proto_bcdc_header *h;
brcmf_dbg(BCDC, "Enter\n");
skb_push(pktbuf, BCDC_HEADER_LEN);
h = (struct brcmf_proto_bcdc_header *)(pktbuf->data);
h->flags = (BCDC_PROTO_VER << BCDC_FLAG_VER_SHIFT);
if (pktbuf->ip_summed == CHECKSUM_PARTIAL)
h->flags |= BCDC_FLAG_SUM_NEEDED;
h->priority = (pktbuf->priority & BCDC_PRIORITY_MASK);
h->flags2 = 0;
h->data_offset = offset;
BCDC_SET_IF_IDX(h, ifidx);
trace_brcmf_bcdchdr(pktbuf->data);
}
static int
brcmf_proto_bcdc_hdrpull(struct brcmf_pub *drvr, bool do_fws, u8 *ifidx,
struct sk_buff *pktbuf)
{
struct brcmf_proto_bcdc_header *h;
brcmf_dbg(BCDC, "Enter\n");
if (pktbuf->len <= BCDC_HEADER_LEN) {
brcmf_dbg(INFO, "rx data too short (%d <= %d)\n",
pktbuf->len, BCDC_HEADER_LEN);
return -EBADE;
}
trace_brcmf_bcdchdr(pktbuf->data);
h = (struct brcmf_proto_bcdc_header *)(pktbuf->data);
*ifidx = BCDC_GET_IF_IDX(h);
if (*ifidx >= BRCMF_MAX_IFS) {
brcmf_err("rx data ifnum out of range (%d)\n", *ifidx);
return -EBADE;
}
if (*ifidx)
(*ifidx)++;
if (((h->flags & BCDC_FLAG_VER_MASK) >> BCDC_FLAG_VER_SHIFT) !=
BCDC_PROTO_VER) {
brcmf_err("%s: non-BCDC packet received, flags 0x%x\n",
brcmf_ifname(drvr, *ifidx), h->flags);
return -EBADE;
}
if (h->flags & BCDC_FLAG_SUM_GOOD) {
brcmf_dbg(BCDC, "%s: BDC rcv, good checksum, flags 0x%x\n",
brcmf_ifname(drvr, *ifidx), h->flags);
pktbuf->ip_summed = CHECKSUM_UNNECESSARY;
}
pktbuf->priority = h->priority & BCDC_PRIORITY_MASK;
skb_pull(pktbuf, BCDC_HEADER_LEN);
if (do_fws)
brcmf_fws_hdrpull(drvr, *ifidx, h->data_offset << 2, pktbuf);
else
skb_pull(pktbuf, h->data_offset << 2);
if (pktbuf->len == 0)
return -ENODATA;
return 0;
}
static int
brcmf_proto_bcdc_txdata(struct brcmf_pub *drvr, int ifidx, u8 offset,
struct sk_buff *pktbuf)
{
brcmf_proto_bcdc_hdrpush(drvr, ifidx, offset, pktbuf);
return brcmf_bus_txdata(drvr->bus_if, pktbuf);
}
int brcmf_proto_bcdc_attach(struct brcmf_pub *drvr)
{
struct brcmf_bcdc *bcdc;
bcdc = kzalloc(sizeof(*bcdc), GFP_ATOMIC);
if (!bcdc)
goto fail;
if ((unsigned long)(&bcdc->msg + 1) != (unsigned long)bcdc->buf) {
brcmf_err("struct brcmf_proto_bcdc is not correctly defined\n");
goto fail;
}
drvr->proto->hdrpull = brcmf_proto_bcdc_hdrpull;
drvr->proto->query_dcmd = brcmf_proto_bcdc_query_dcmd;
drvr->proto->set_dcmd = brcmf_proto_bcdc_set_dcmd;
drvr->proto->txdata = brcmf_proto_bcdc_txdata;
drvr->proto->pd = bcdc;
drvr->hdrlen += BCDC_HEADER_LEN + BRCMF_PROT_FW_SIGNAL_MAX_TXBYTES;
drvr->bus_if->maxctl = BRCMF_DCMD_MAXLEN +
sizeof(struct brcmf_proto_bcdc_dcmd);
return 0;
fail:
kfree(bcdc);
return -ENOMEM;
}
void brcmf_proto_bcdc_detach(struct brcmf_pub *drvr)
{
kfree(drvr->proto->pd);
drvr->proto->pd = NULL;
}
