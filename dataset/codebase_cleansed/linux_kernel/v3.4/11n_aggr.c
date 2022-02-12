static int
mwifiex_11n_form_amsdu_pkt(struct sk_buff *skb_aggr,
struct sk_buff *skb_src, int *pad)
{
int dt_offset;
struct rfc_1042_hdr snap = {
0xaa,
0xaa,
0x03,
{0x00, 0x00, 0x00},
0x0000
};
struct tx_packet_hdr *tx_header;
skb_put(skb_aggr, sizeof(*tx_header));
tx_header = (struct tx_packet_hdr *) skb_aggr->data;
dt_offset = 2 * ETH_ALEN;
memcpy(&tx_header->eth803_hdr, skb_src->data, dt_offset);
snap.snap_type = *(u16 *) ((u8 *)skb_src->data + dt_offset);
dt_offset += sizeof(u16);
memcpy(&tx_header->rfc1042_hdr, &snap, sizeof(struct rfc_1042_hdr));
skb_pull(skb_src, dt_offset);
tx_header->eth803_hdr.h_proto = htons(skb_src->len + LLC_SNAP_LEN);
skb_put(skb_aggr, skb_src->len);
memcpy(skb_aggr->data + sizeof(*tx_header), skb_src->data,
skb_src->len);
*pad = (((skb_src->len + LLC_SNAP_LEN) & 3)) ? (4 - (((skb_src->len +
LLC_SNAP_LEN)) & 3)) : 0;
skb_put(skb_aggr, *pad);
return skb_aggr->len + *pad;
}
static void
mwifiex_11n_form_amsdu_txpd(struct mwifiex_private *priv,
struct sk_buff *skb)
{
struct txpd *local_tx_pd;
skb_push(skb, sizeof(*local_tx_pd));
local_tx_pd = (struct txpd *) skb->data;
memset(local_tx_pd, 0, sizeof(struct txpd));
local_tx_pd->priority = (u8) skb->priority;
local_tx_pd->pkt_delay_2ms =
mwifiex_wmm_compute_drv_pkt_delay(priv, skb);
local_tx_pd->bss_num = priv->bss_num;
local_tx_pd->bss_type = priv->bss_type;
local_tx_pd->tx_pkt_offset = cpu_to_le16(sizeof(struct txpd));
local_tx_pd->tx_pkt_type = cpu_to_le16(PKT_TYPE_AMSDU);
local_tx_pd->tx_pkt_length = cpu_to_le16(skb->len -
sizeof(*local_tx_pd));
if (local_tx_pd->tx_control == 0)
local_tx_pd->tx_control = cpu_to_le32(priv->pkt_tx_ctrl);
if (GET_BSS_ROLE(priv) == MWIFIEX_BSS_ROLE_STA &&
priv->adapter->pps_uapsd_mode) {
if (true == mwifiex_check_last_packet_indication(priv)) {
priv->adapter->tx_lock_flag = true;
local_tx_pd->flags =
MWIFIEX_TxPD_POWER_MGMT_LAST_PACKET;
}
}
}
int
mwifiex_11n_aggregate_pkt(struct mwifiex_private *priv,
struct mwifiex_ra_list_tbl *pra_list, int headroom,
int ptrindex, unsigned long ra_list_flags)
__releases(&priv->wmm.ra_list_spinlock
