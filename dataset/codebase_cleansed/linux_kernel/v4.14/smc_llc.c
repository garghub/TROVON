static void smc_llc_tx_handler(struct smc_wr_tx_pend_priv *pend,
struct smc_link *link,
enum ib_wc_status wc_status)
{
}
static int smc_llc_add_pending_send(struct smc_link *link,
struct smc_wr_buf **wr_buf,
struct smc_wr_tx_pend_priv **pend)
{
int rc;
rc = smc_wr_tx_get_free_slot(link, smc_llc_tx_handler, wr_buf, pend);
if (rc < 0)
return rc;
BUILD_BUG_ON_MSG(
sizeof(union smc_llc_msg) > SMC_WR_BUF_SIZE,
"must increase SMC_WR_BUF_SIZE to at least sizeof(struct smc_llc_msg)");
BUILD_BUG_ON_MSG(
sizeof(union smc_llc_msg) != SMC_WR_TX_SIZE,
"must adapt SMC_WR_TX_SIZE to sizeof(struct smc_llc_msg); if not all smc_wr upper layer protocols use the same message size any more, must start to set link->wr_tx_sges[i].length on each individual smc_wr_tx_send()");
BUILD_BUG_ON_MSG(
sizeof(struct smc_llc_tx_pend) > SMC_WR_TX_PEND_PRIV_SIZE,
"must increase SMC_WR_TX_PEND_PRIV_SIZE to at least sizeof(struct smc_llc_tx_pend)");
return 0;
}
int smc_llc_send_confirm_link(struct smc_link *link, u8 mac[],
union ib_gid *gid,
enum smc_llc_reqresp reqresp)
{
struct smc_link_group *lgr = container_of(link, struct smc_link_group,
lnk[SMC_SINGLE_LINK]);
struct smc_llc_msg_confirm_link *confllc;
struct smc_wr_tx_pend_priv *pend;
struct smc_wr_buf *wr_buf;
int rc;
rc = smc_llc_add_pending_send(link, &wr_buf, &pend);
if (rc)
return rc;
confllc = (struct smc_llc_msg_confirm_link *)wr_buf;
memset(confllc, 0, sizeof(*confllc));
confllc->hd.common.type = SMC_LLC_CONFIRM_LINK;
confllc->hd.length = sizeof(struct smc_llc_msg_confirm_link);
if (reqresp == SMC_LLC_RESP)
confllc->hd.flags |= SMC_LLC_FLAG_RESP;
memcpy(confllc->sender_mac, mac, ETH_ALEN);
memcpy(confllc->sender_gid, gid, SMC_GID_SIZE);
hton24(confllc->sender_qp_num, link->roce_qp->qp_num);
memcpy(confllc->link_uid, lgr->id, SMC_LGR_ID_SIZE);
confllc->max_links = SMC_LINKS_PER_LGR_MAX;
rc = smc_wr_tx_send(link, pend);
return rc;
}
static void smc_llc_rx_confirm_link(struct smc_link *link,
struct smc_llc_msg_confirm_link *llc)
{
struct smc_link_group *lgr;
lgr = container_of(link, struct smc_link_group, lnk[SMC_SINGLE_LINK]);
if (llc->hd.flags & SMC_LLC_FLAG_RESP) {
if (lgr->role == SMC_SERV)
complete(&link->llc_confirm_resp);
} else {
if (lgr->role == SMC_CLNT) {
link->link_id = llc->link_num;
complete(&link->llc_confirm);
}
}
}
static void smc_llc_rx_handler(struct ib_wc *wc, void *buf)
{
struct smc_link *link = (struct smc_link *)wc->qp->qp_context;
union smc_llc_msg *llc = buf;
if (wc->byte_len < sizeof(*llc))
return;
if (llc->raw.hdr.length != sizeof(*llc))
return;
if (llc->raw.hdr.common.type == SMC_LLC_CONFIRM_LINK)
smc_llc_rx_confirm_link(link, &llc->confirm_link);
}
int __init smc_llc_init(void)
{
struct smc_wr_rx_handler *handler;
int rc = 0;
for (handler = smc_llc_rx_handlers; handler->handler; handler++) {
INIT_HLIST_NODE(&handler->list);
rc = smc_wr_rx_register_handler(handler);
if (rc)
break;
}
return rc;
}
