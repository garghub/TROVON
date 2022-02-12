struct brcmf_fws_info *drvr_to_fws(struct brcmf_pub *drvr)
{
struct brcmf_bcdc *bcdc = drvr->proto->pd;
return bcdc->fws;
}
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
brcmf_ifname(brcmf_get_ifp(drvr, ifidx)), id,
bcdc->reqid);
ret = -EINVAL;
goto done;
}
info = (void *)&bcdc->buf[0];
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
brcmf_ifname(brcmf_get_ifp(drvr, ifidx)), id,
bcdc->reqid);
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
brcmf_proto_bcdc_hdrpull(struct brcmf_pub *drvr, bool do_fws,
struct sk_buff *pktbuf, struct brcmf_if **ifp)
{
struct brcmf_proto_bcdc_header *h;
struct brcmf_if *tmp_if;
brcmf_dbg(BCDC, "Enter\n");
if (pktbuf->len <= BCDC_HEADER_LEN) {
brcmf_dbg(INFO, "rx data too short (%d <= %d)\n",
pktbuf->len, BCDC_HEADER_LEN);
return -EBADE;
}
trace_brcmf_bcdchdr(pktbuf->data);
h = (struct brcmf_proto_bcdc_header *)(pktbuf->data);
tmp_if = brcmf_get_ifp(drvr, BCDC_GET_IF_IDX(h));
if (!tmp_if) {
brcmf_dbg(INFO, "no matching ifp found\n");
return -EBADE;
}
if (((h->flags & BCDC_FLAG_VER_MASK) >> BCDC_FLAG_VER_SHIFT) !=
BCDC_PROTO_VER) {
brcmf_err("%s: non-BCDC packet received, flags 0x%x\n",
brcmf_ifname(tmp_if), h->flags);
return -EBADE;
}
if (h->flags & BCDC_FLAG_SUM_GOOD) {
brcmf_dbg(BCDC, "%s: BDC rcv, good checksum, flags 0x%x\n",
brcmf_ifname(tmp_if), h->flags);
pktbuf->ip_summed = CHECKSUM_UNNECESSARY;
}
pktbuf->priority = h->priority & BCDC_PRIORITY_MASK;
skb_pull(pktbuf, BCDC_HEADER_LEN);
if (do_fws)
brcmf_fws_hdrpull(tmp_if, h->data_offset << 2, pktbuf);
else
skb_pull(pktbuf, h->data_offset << 2);
if (pktbuf->len == 0)
return -ENODATA;
if (ifp != NULL)
*ifp = tmp_if;
return 0;
}
static int brcmf_proto_bcdc_tx_queue_data(struct brcmf_pub *drvr, int ifidx,
struct sk_buff *skb)
{
struct brcmf_if *ifp = brcmf_get_ifp(drvr, ifidx);
struct brcmf_bcdc *bcdc = drvr->proto->pd;
if (!brcmf_fws_queue_skbs(bcdc->fws))
return brcmf_proto_txdata(drvr, ifidx, 0, skb);
return brcmf_fws_process_skb(ifp, skb);
}
static int
brcmf_proto_bcdc_txdata(struct brcmf_pub *drvr, int ifidx, u8 offset,
struct sk_buff *pktbuf)
{
brcmf_proto_bcdc_hdrpush(drvr, ifidx, offset, pktbuf);
return brcmf_bus_txdata(drvr->bus_if, pktbuf);
}
void brcmf_proto_bcdc_txflowblock(struct device *dev, bool state)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_pub *drvr = bus_if->drvr;
brcmf_dbg(TRACE, "Enter\n");
brcmf_fws_bus_blocked(drvr, state);
}
void
brcmf_proto_bcdc_txcomplete(struct device *dev, struct sk_buff *txp,
bool success)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_bcdc *bcdc = bus_if->drvr->proto->pd;
struct brcmf_if *ifp;
if (brcmf_fws_fc_active(bcdc->fws)) {
if (!success)
brcmf_fws_bustxfail(bcdc->fws, txp);
} else {
if (brcmf_proto_bcdc_hdrpull(bus_if->drvr, false, txp, &ifp))
brcmu_pkt_buf_free_skb(txp);
else
brcmf_txfinalize(ifp, txp, success);
}
}
static void
brcmf_proto_bcdc_configure_addr_mode(struct brcmf_pub *drvr, int ifidx,
enum proto_addr_mode addr_mode)
{
}
static void
brcmf_proto_bcdc_delete_peer(struct brcmf_pub *drvr, int ifidx,
u8 peer[ETH_ALEN])
{
}
static void
brcmf_proto_bcdc_add_tdls_peer(struct brcmf_pub *drvr, int ifidx,
u8 peer[ETH_ALEN])
{
}
static void brcmf_proto_bcdc_rxreorder(struct brcmf_if *ifp,
struct sk_buff *skb)
{
brcmf_fws_rxreorder(ifp, skb);
}
static void
brcmf_proto_bcdc_add_if(struct brcmf_if *ifp)
{
brcmf_fws_add_interface(ifp);
}
static void
brcmf_proto_bcdc_del_if(struct brcmf_if *ifp)
{
brcmf_fws_del_interface(ifp);
}
static void
brcmf_proto_bcdc_reset_if(struct brcmf_if *ifp)
{
brcmf_fws_reset_interface(ifp);
}
static int
brcmf_proto_bcdc_init_done(struct brcmf_pub *drvr)
{
struct brcmf_bcdc *bcdc = drvr->proto->pd;
struct brcmf_fws_info *fws;
fws = brcmf_fws_attach(drvr);
if (IS_ERR(fws))
return PTR_ERR(fws);
bcdc->fws = fws;
return 0;
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
drvr->proto->tx_queue_data = brcmf_proto_bcdc_tx_queue_data;
drvr->proto->txdata = brcmf_proto_bcdc_txdata;
drvr->proto->configure_addr_mode = brcmf_proto_bcdc_configure_addr_mode;
drvr->proto->delete_peer = brcmf_proto_bcdc_delete_peer;
drvr->proto->add_tdls_peer = brcmf_proto_bcdc_add_tdls_peer;
drvr->proto->rxreorder = brcmf_proto_bcdc_rxreorder;
drvr->proto->add_if = brcmf_proto_bcdc_add_if;
drvr->proto->del_if = brcmf_proto_bcdc_del_if;
drvr->proto->reset_if = brcmf_proto_bcdc_reset_if;
drvr->proto->init_done = brcmf_proto_bcdc_init_done;
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
struct brcmf_bcdc *bcdc = drvr->proto->pd;
drvr->proto->pd = NULL;
brcmf_fws_detach(bcdc->fws);
kfree(bcdc);
}
