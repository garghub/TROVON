void iwl_mvm_set_rekey_data(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct cfg80211_gtk_rekey_data *data)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (iwlwifi_mod_params.sw_crypto)
return;
mutex_lock(&mvm->mutex);
memcpy(mvmvif->rekey_data.kek, data->kek, NL80211_KEK_LEN);
memcpy(mvmvif->rekey_data.kck, data->kck, NL80211_KCK_LEN);
mvmvif->rekey_data.replay_ctr =
cpu_to_le64(be64_to_cpup((__be64 *)data->replay_ctr));
mvmvif->rekey_data.valid = true;
mutex_unlock(&mvm->mutex);
}
void iwl_mvm_ipv6_addr_change(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct inet6_dev *idev)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct inet6_ifaddr *ifa;
int idx = 0;
memset(mvmvif->tentative_addrs, 0, sizeof(mvmvif->tentative_addrs));
read_lock_bh(&idev->lock);
list_for_each_entry(ifa, &idev->addr_list, if_list) {
mvmvif->target_ipv6_addrs[idx] = ifa->addr;
if (ifa->flags & IFA_F_TENTATIVE)
__set_bit(idx, mvmvif->tentative_addrs);
idx++;
if (idx >= IWL_PROTO_OFFLOAD_NUM_IPV6_ADDRS_MAX)
break;
}
read_unlock_bh(&idev->lock);
mvmvif->num_target_ipv6_addrs = idx;
}
void iwl_mvm_set_default_unicast_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, int idx)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
mvmvif->tx_key_idx = idx;
}
static void iwl_mvm_convert_p1k(u16 *p1k, __le16 *out)
{
int i;
for (i = 0; i < IWL_P1K_SIZE; i++)
out[i] = cpu_to_le16(p1k[i]);
}
static const u8 *iwl_mvm_find_max_pn(struct ieee80211_key_conf *key,
struct iwl_mvm_key_pn *ptk_pn,
struct ieee80211_key_seq *seq,
int tid, int queues)
{
const u8 *ret = seq->ccmp.pn;
int i;
ieee80211_get_key_rx_seq(key, tid, seq);
for (i = 1; i < queues; i++) {
const u8 *tmp = ptk_pn->q[i].pn[tid];
if (memcmp(ret, tmp, IEEE80211_CCMP_PN_LEN) <= 0)
ret = tmp;
}
return ret;
}
static void iwl_mvm_wowlan_program_keys(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key,
void *_data)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct wowlan_key_data *data = _data;
struct aes_sc *aes_sc, *aes_tx_sc = NULL;
struct tkip_sc *tkip_sc, *tkip_tx_sc = NULL;
struct iwl_p1k_cache *rx_p1ks;
u8 *rx_mic_key;
struct ieee80211_key_seq seq;
u32 cur_rx_iv32 = 0;
u16 p1k[IWL_P1K_SIZE];
int ret, i;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104: {
struct {
struct iwl_mvm_wep_key_cmd wep_key_cmd;
struct iwl_mvm_wep_key wep_key;
} __packed wkc = {
.wep_key_cmd.mac_id_n_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color)),
.wep_key_cmd.num_keys = 1,
.wep_key_cmd.decryption_type = STA_KEY_FLG_WEP,
.wep_key.key_index = key->keyidx,
.wep_key.key_size = key->keylen,
};
if (key->flags & IEEE80211_KEY_FLAG_PAIRWISE)
break;
memcpy(&wkc.wep_key.key[3], key->key, key->keylen);
if (key->keyidx == mvmvif->tx_key_idx) {
wkc.wep_key.key_offset = 0;
} else {
data->wep_key_idx++;
wkc.wep_key.key_offset = data->wep_key_idx;
}
if (data->configure_keys) {
mutex_lock(&mvm->mutex);
ret = iwl_mvm_send_cmd_pdu(mvm, WEP_KEY, 0,
sizeof(wkc), &wkc);
data->error = ret != 0;
mvm->ptk_ivlen = key->iv_len;
mvm->ptk_icvlen = key->icv_len;
mvm->gtk_ivlen = key->iv_len;
mvm->gtk_icvlen = key->icv_len;
mutex_unlock(&mvm->mutex);
}
return;
}
default:
data->error = true;
return;
case WLAN_CIPHER_SUITE_AES_CMAC:
return;
case WLAN_CIPHER_SUITE_TKIP:
if (sta) {
u64 pn64;
tkip_sc = data->rsc_tsc->all_tsc_rsc.tkip.unicast_rsc;
tkip_tx_sc = &data->rsc_tsc->all_tsc_rsc.tkip.tsc;
rx_p1ks = data->tkip->rx_uni;
pn64 = atomic64_read(&key->tx_pn);
tkip_tx_sc->iv16 = cpu_to_le16(TKIP_PN_TO_IV16(pn64));
tkip_tx_sc->iv32 = cpu_to_le32(TKIP_PN_TO_IV32(pn64));
ieee80211_get_tkip_p1k_iv(key, TKIP_PN_TO_IV32(pn64),
p1k);
iwl_mvm_convert_p1k(p1k, data->tkip->tx.p1k);
memcpy(data->tkip->mic_keys.tx,
&key->key[NL80211_TKIP_DATA_OFFSET_TX_MIC_KEY],
IWL_MIC_KEY_SIZE);
rx_mic_key = data->tkip->mic_keys.rx_unicast;
} else {
tkip_sc =
data->rsc_tsc->all_tsc_rsc.tkip.multicast_rsc;
rx_p1ks = data->tkip->rx_multi;
rx_mic_key = data->tkip->mic_keys.rx_mcast;
}
for (i = 0; i < IWL_NUM_RSC; i++) {
ieee80211_get_key_rx_seq(key, i, &seq);
tkip_sc[i].iv16 = cpu_to_le16(seq.tkip.iv16);
tkip_sc[i].iv32 = cpu_to_le32(seq.tkip.iv32);
if (seq.tkip.iv32 > cur_rx_iv32)
cur_rx_iv32 = seq.tkip.iv32;
}
ieee80211_get_tkip_rx_p1k(key, vif->bss_conf.bssid,
cur_rx_iv32, p1k);
iwl_mvm_convert_p1k(p1k, rx_p1ks[0].p1k);
ieee80211_get_tkip_rx_p1k(key, vif->bss_conf.bssid,
cur_rx_iv32 + 1, p1k);
iwl_mvm_convert_p1k(p1k, rx_p1ks[1].p1k);
memcpy(rx_mic_key,
&key->key[NL80211_TKIP_DATA_OFFSET_RX_MIC_KEY],
IWL_MIC_KEY_SIZE);
data->use_tkip = true;
data->use_rsc_tsc = true;
break;
case WLAN_CIPHER_SUITE_CCMP:
if (sta) {
u64 pn64;
aes_sc = data->rsc_tsc->all_tsc_rsc.aes.unicast_rsc;
aes_tx_sc = &data->rsc_tsc->all_tsc_rsc.aes.tsc;
pn64 = atomic64_read(&key->tx_pn);
aes_tx_sc->pn = cpu_to_le64(pn64);
} else {
aes_sc = data->rsc_tsc->all_tsc_rsc.aes.multicast_rsc;
}
if (sta && iwl_mvm_has_new_rx_api(mvm)) {
struct iwl_mvm_sta *mvmsta;
struct iwl_mvm_key_pn *ptk_pn;
const u8 *pn;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
ptk_pn = rcu_dereference_protected(
mvmsta->ptk_pn[key->keyidx],
lockdep_is_held(&mvm->mutex));
if (WARN_ON(!ptk_pn))
break;
for (i = 0; i < IWL_MAX_TID_COUNT; i++) {
pn = iwl_mvm_find_max_pn(key, ptk_pn, &seq, i,
mvm->trans->num_rx_queues);
aes_sc[i].pn = cpu_to_le64((u64)pn[5] |
((u64)pn[4] << 8) |
((u64)pn[3] << 16) |
((u64)pn[2] << 24) |
((u64)pn[1] << 32) |
((u64)pn[0] << 40));
}
} else {
for (i = 0; i < IWL_NUM_RSC; i++) {
u8 *pn = seq.ccmp.pn;
ieee80211_get_key_rx_seq(key, i, &seq);
aes_sc[i].pn = cpu_to_le64((u64)pn[5] |
((u64)pn[4] << 8) |
((u64)pn[3] << 16) |
((u64)pn[2] << 24) |
((u64)pn[1] << 32) |
((u64)pn[0] << 40));
}
}
data->use_rsc_tsc = true;
break;
}
if (data->configure_keys) {
mutex_lock(&mvm->mutex);
if (key->flags & IEEE80211_KEY_FLAG_PAIRWISE) {
mvm->ptk_ivlen = key->iv_len;
mvm->ptk_icvlen = key->icv_len;
ret = iwl_mvm_set_sta_key(mvm, vif, sta, key, 0);
} else {
mvm->gtk_ivlen = key->iv_len;
mvm->gtk_icvlen = key->icv_len;
ret = iwl_mvm_set_sta_key(mvm, vif, sta, key, 1);
}
mutex_unlock(&mvm->mutex);
data->error = ret != 0;
}
}
static int iwl_mvm_send_patterns(struct iwl_mvm *mvm,
struct cfg80211_wowlan *wowlan)
{
struct iwl_wowlan_patterns_cmd *pattern_cmd;
struct iwl_host_cmd cmd = {
.id = WOWLAN_PATTERNS,
.dataflags[0] = IWL_HCMD_DFL_NOCOPY,
};
int i, err;
if (!wowlan->n_patterns)
return 0;
cmd.len[0] = sizeof(*pattern_cmd) +
wowlan->n_patterns * sizeof(struct iwl_wowlan_pattern);
pattern_cmd = kmalloc(cmd.len[0], GFP_KERNEL);
if (!pattern_cmd)
return -ENOMEM;
pattern_cmd->n_patterns = cpu_to_le32(wowlan->n_patterns);
for (i = 0; i < wowlan->n_patterns; i++) {
int mask_len = DIV_ROUND_UP(wowlan->patterns[i].pattern_len, 8);
memcpy(&pattern_cmd->patterns[i].mask,
wowlan->patterns[i].mask, mask_len);
memcpy(&pattern_cmd->patterns[i].pattern,
wowlan->patterns[i].pattern,
wowlan->patterns[i].pattern_len);
pattern_cmd->patterns[i].mask_size = mask_len;
pattern_cmd->patterns[i].pattern_size =
wowlan->patterns[i].pattern_len;
}
cmd.data[0] = pattern_cmd;
err = iwl_mvm_send_cmd(mvm, &cmd);
kfree(pattern_cmd);
return err;
}
static __le16 pseudo_hdr_check(int len, __be32 saddr, __be32 daddr)
{
__sum16 check = tcp_v4_check(len, saddr, daddr, 0);
return cpu_to_le16(be16_to_cpu((__force __be16)check));
}
static void iwl_mvm_build_tcp_packet(struct ieee80211_vif *vif,
struct cfg80211_wowlan_tcp *tcp,
void *_pkt, u8 *mask,
__le16 *pseudo_hdr_csum,
enum iwl_mvm_tcp_packet_type ptype)
{
struct {
struct ethhdr eth;
struct iphdr ip;
struct tcphdr tcp;
u8 data[];
} __packed *pkt = _pkt;
u16 ip_tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
int i;
pkt->eth.h_proto = cpu_to_be16(ETH_P_IP),
pkt->ip.version = 4;
pkt->ip.ihl = 5;
pkt->ip.protocol = IPPROTO_TCP;
switch (ptype) {
case MVM_TCP_TX_SYN:
case MVM_TCP_TX_DATA:
case MVM_TCP_TX_FIN:
memcpy(pkt->eth.h_dest, tcp->dst_mac, ETH_ALEN);
memcpy(pkt->eth.h_source, vif->addr, ETH_ALEN);
pkt->ip.ttl = 128;
pkt->ip.saddr = tcp->src;
pkt->ip.daddr = tcp->dst;
pkt->tcp.source = cpu_to_be16(tcp->src_port);
pkt->tcp.dest = cpu_to_be16(tcp->dst_port);
pkt->tcp.doff = sizeof(struct tcphdr) / 4;
pkt->tcp.window = cpu_to_be16(65000);
break;
case MVM_TCP_RX_SYNACK:
case MVM_TCP_RX_ACK:
case MVM_TCP_RX_WAKE:
memcpy(pkt->eth.h_dest, vif->addr, ETH_ALEN);
memcpy(pkt->eth.h_source, tcp->dst_mac, ETH_ALEN);
pkt->ip.saddr = tcp->dst;
pkt->ip.daddr = tcp->src;
pkt->tcp.source = cpu_to_be16(tcp->dst_port);
pkt->tcp.dest = cpu_to_be16(tcp->src_port);
break;
default:
WARN_ON(1);
return;
}
switch (ptype) {
case MVM_TCP_TX_SYN:
memset(pkt->data, 0x01, 8);
ip_tot_len += 8;
pkt->tcp.doff = (sizeof(struct tcphdr) + 8) / 4;
pkt->tcp.syn = 1;
break;
case MVM_TCP_TX_DATA:
ip_tot_len += tcp->payload_len;
memcpy(pkt->data, tcp->payload, tcp->payload_len);
pkt->tcp.psh = 1;
pkt->tcp.ack = 1;
break;
case MVM_TCP_TX_FIN:
pkt->tcp.fin = 1;
pkt->tcp.ack = 1;
break;
case MVM_TCP_RX_SYNACK:
pkt->tcp.syn = 1;
pkt->tcp.ack = 1;
break;
case MVM_TCP_RX_ACK:
pkt->tcp.ack = 1;
break;
case MVM_TCP_RX_WAKE:
ip_tot_len += tcp->wake_len;
pkt->tcp.psh = 1;
pkt->tcp.ack = 1;
memcpy(pkt->data, tcp->wake_data, tcp->wake_len);
break;
}
switch (ptype) {
case MVM_TCP_TX_SYN:
case MVM_TCP_TX_DATA:
case MVM_TCP_TX_FIN:
pkt->ip.tot_len = cpu_to_be16(ip_tot_len);
pkt->ip.check = ip_fast_csum(&pkt->ip, pkt->ip.ihl);
break;
case MVM_TCP_RX_WAKE:
for (i = 0; i < DIV_ROUND_UP(tcp->wake_len, 8); i++) {
u8 tmp = tcp->wake_mask[i];
mask[i + 6] |= tmp << 6;
if (i + 1 < DIV_ROUND_UP(tcp->wake_len, 8))
mask[i + 7] = tmp >> 2;
}
case MVM_TCP_RX_SYNACK:
case MVM_TCP_RX_ACK:
mask[0] = 0xff;
mask[1] = 0x7f;
mask[2] = 0x80;
mask[3] = 0xfc;
mask[4] = 0x3f;
mask[5] = 0x80;
break;
};
*pseudo_hdr_csum = pseudo_hdr_check(ip_tot_len - sizeof(struct iphdr),
pkt->ip.saddr, pkt->ip.daddr);
}
static int iwl_mvm_send_remote_wake_cfg(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct cfg80211_wowlan_tcp *tcp)
{
struct iwl_wowlan_remote_wake_config *cfg;
struct iwl_host_cmd cmd = {
.id = REMOTE_WAKE_CONFIG_CMD,
.len = { sizeof(*cfg), },
.dataflags = { IWL_HCMD_DFL_NOCOPY, },
};
int ret;
if (!tcp)
return 0;
cfg = kzalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg)
return -ENOMEM;
cmd.data[0] = cfg;
cfg->max_syn_retries = 10;
cfg->max_data_retries = 10;
cfg->tcp_syn_ack_timeout = 1;
cfg->tcp_ack_timeout = 1;
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->syn_tx.data, NULL,
&cfg->syn_tx.info.tcp_pseudo_header_checksum,
MVM_TCP_TX_SYN);
cfg->syn_tx.info.tcp_payload_length = 0;
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->synack_rx.data, cfg->synack_rx.rx_mask,
&cfg->synack_rx.info.tcp_pseudo_header_checksum,
MVM_TCP_RX_SYNACK);
cfg->synack_rx.info.tcp_payload_length = 0;
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->keepalive_tx.data, NULL,
&cfg->keepalive_tx.info.tcp_pseudo_header_checksum,
MVM_TCP_TX_DATA);
cfg->keepalive_tx.info.tcp_payload_length =
cpu_to_le16(tcp->payload_len);
cfg->sequence_number_offset = tcp->payload_seq.offset;
cfg->sequence_number_length = tcp->payload_seq.len;
cfg->initial_sequence_number = cpu_to_le32(tcp->payload_seq.start);
cfg->keepalive_interval = cpu_to_le16(tcp->data_interval);
if (tcp->payload_tok.len) {
cfg->token_offset = tcp->payload_tok.offset;
cfg->token_length = tcp->payload_tok.len;
cfg->num_tokens =
cpu_to_le16(tcp->tokens_size % tcp->payload_tok.len);
memcpy(cfg->tokens, tcp->payload_tok.token_stream,
tcp->tokens_size);
} else {
cfg->num_tokens = cpu_to_le16(65535);
}
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->keepalive_ack_rx.data,
cfg->keepalive_ack_rx.rx_mask,
&cfg->keepalive_ack_rx.info.tcp_pseudo_header_checksum,
MVM_TCP_RX_ACK);
cfg->keepalive_ack_rx.info.tcp_payload_length = 0;
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->wake_rx.data, cfg->wake_rx.rx_mask,
&cfg->wake_rx.info.tcp_pseudo_header_checksum,
MVM_TCP_RX_WAKE);
cfg->wake_rx.info.tcp_payload_length =
cpu_to_le16(tcp->wake_len);
iwl_mvm_build_tcp_packet(
vif, tcp, cfg->fin_tx.data, NULL,
&cfg->fin_tx.info.tcp_pseudo_header_checksum,
MVM_TCP_TX_FIN);
cfg->fin_tx.info.tcp_payload_length = 0;
ret = iwl_mvm_send_cmd(mvm, &cmd);
kfree(cfg);
return ret;
}
static int iwl_mvm_d3_reprogram(struct iwl_mvm *mvm, struct ieee80211_vif *vif,
struct ieee80211_sta *ap_sta)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct ieee80211_chanctx_conf *ctx;
u8 chains_static, chains_dynamic;
struct cfg80211_chan_def chandef;
int ret, i;
struct iwl_binding_cmd binding_cmd = {};
struct iwl_time_quota_cmd quota_cmd = {};
u32 status;
if (WARN_ON(!mvmvif->phy_ctxt))
return -EINVAL;
rcu_read_lock();
ctx = rcu_dereference(vif->chanctx_conf);
if (WARN_ON(!ctx)) {
rcu_read_unlock();
return -EINVAL;
}
chandef = ctx->def;
chains_static = ctx->rx_chains_static;
chains_dynamic = ctx->rx_chains_dynamic;
rcu_read_unlock();
ret = iwl_mvm_phy_ctxt_add(mvm, mvmvif->phy_ctxt, &chandef,
chains_static, chains_dynamic);
if (ret)
return ret;
mvmvif->uploaded = false;
if (WARN_ON(!vif->bss_conf.assoc))
return -EINVAL;
ret = iwl_mvm_mac_ctxt_add(mvm, vif);
if (ret)
return ret;
binding_cmd.id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->phy_ctxt->id,
mvmvif->phy_ctxt->color));
binding_cmd.action = cpu_to_le32(FW_CTXT_ACTION_ADD);
binding_cmd.phy =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->phy_ctxt->id,
mvmvif->phy_ctxt->color));
binding_cmd.macs[0] = cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color));
for (i = 1; i < MAX_MACS_IN_BINDING; i++)
binding_cmd.macs[i] = cpu_to_le32(FW_CTXT_INVALID);
status = 0;
ret = iwl_mvm_send_cmd_pdu_status(mvm, BINDING_CONTEXT_CMD,
sizeof(binding_cmd), &binding_cmd,
&status);
if (ret) {
IWL_ERR(mvm, "Failed to add binding: %d\n", ret);
return ret;
}
if (status) {
IWL_ERR(mvm, "Binding command failed: %u\n", status);
return -EIO;
}
ret = iwl_mvm_sta_send_to_fw(mvm, ap_sta, false, 0);
if (ret)
return ret;
rcu_assign_pointer(mvm->fw_id_to_mac_id[mvmvif->ap_sta_id], ap_sta);
ret = iwl_mvm_mac_ctxt_changed(mvm, vif, false, NULL);
if (ret)
return ret;
quota_cmd.quotas[0].id_and_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->phy_ctxt->id,
mvmvif->phy_ctxt->color));
quota_cmd.quotas[0].quota = cpu_to_le32(IWL_MVM_MAX_QUOTA);
quota_cmd.quotas[0].max_duration = cpu_to_le32(IWL_MVM_MAX_QUOTA);
for (i = 1; i < MAX_BINDINGS; i++)
quota_cmd.quotas[i].id_and_color = cpu_to_le32(FW_CTXT_INVALID);
ret = iwl_mvm_send_cmd_pdu(mvm, TIME_QUOTA_CMD, 0,
sizeof(quota_cmd), &quota_cmd);
if (ret)
IWL_ERR(mvm, "Failed to send quota: %d\n", ret);
if (iwl_mvm_is_lar_supported(mvm) && iwl_mvm_init_fw_regd(mvm))
IWL_ERR(mvm, "Failed to initialize D3 LAR information\n");
return 0;
}
static int iwl_mvm_get_last_nonqos_seq(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_nonqos_seq_query_cmd query_cmd = {
.get_set_flag = cpu_to_le32(IWL_NONQOS_SEQ_GET),
.mac_id_n_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color)),
};
struct iwl_host_cmd cmd = {
.id = NON_QOS_TX_COUNTER_CMD,
.flags = CMD_WANT_SKB,
};
int err;
u32 size;
cmd.data[0] = &query_cmd;
cmd.len[0] = sizeof(query_cmd);
err = iwl_mvm_send_cmd(mvm, &cmd);
if (err)
return err;
size = iwl_rx_packet_payload_len(cmd.resp_pkt);
if (size < sizeof(__le16)) {
err = -EINVAL;
} else {
err = le16_to_cpup((__le16 *)cmd.resp_pkt->data);
err = (u16) (err - 0x10);
}
iwl_free_resp(&cmd);
return err;
}
void iwl_mvm_set_last_nonqos_seq(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_nonqos_seq_query_cmd query_cmd = {
.get_set_flag = cpu_to_le32(IWL_NONQOS_SEQ_SET),
.mac_id_n_color =
cpu_to_le32(FW_CMD_ID_AND_COLOR(mvmvif->id,
mvmvif->color)),
.value = cpu_to_le16(mvmvif->seqno),
};
if (!mvmvif->seqno_valid)
return;
mvmvif->seqno_valid = false;
if (iwl_mvm_send_cmd_pdu(mvm, NON_QOS_TX_COUNTER_CMD, 0,
sizeof(query_cmd), &query_cmd))
IWL_ERR(mvm, "failed to set non-QoS seqno\n");
}
static int iwl_mvm_switch_to_d3(struct iwl_mvm *mvm)
{
iwl_mvm_scan_stop(mvm, IWL_MVM_SCAN_REGULAR, true);
iwl_mvm_stop_device(mvm);
set_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
memset(mvm->fw_key_table, 0, sizeof(mvm->fw_key_table));
mvm->ptk_ivlen = 0;
mvm->ptk_icvlen = 0;
mvm->ptk_ivlen = 0;
mvm->ptk_icvlen = 0;
return iwl_mvm_load_d3_fw(mvm);
}
static int
iwl_mvm_get_wowlan_config(struct iwl_mvm *mvm,
struct cfg80211_wowlan *wowlan,
struct iwl_wowlan_config_cmd *wowlan_config_cmd,
struct ieee80211_vif *vif, struct iwl_mvm_vif *mvmvif,
struct ieee80211_sta *ap_sta)
{
int ret;
struct iwl_mvm_sta *mvm_ap_sta = iwl_mvm_sta_from_mac80211(ap_sta);
wowlan_config_cmd->is_11n_connection =
ap_sta->ht_cap.ht_supported;
wowlan_config_cmd->flags = ENABLE_L3_FILTERING |
ENABLE_NBNS_FILTERING | ENABLE_DHCP_FILTERING;
ret = iwl_mvm_get_last_nonqos_seq(mvm, vif);
if (ret < 0)
return ret;
wowlan_config_cmd->non_qos_seq = cpu_to_le16(ret);
iwl_mvm_set_wowlan_qos_seq(mvm_ap_sta, wowlan_config_cmd);
if (wowlan->disconnect)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_BEACON_MISS |
IWL_WOWLAN_WAKEUP_LINK_CHANGE);
if (wowlan->magic_pkt)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_MAGIC_PACKET);
if (wowlan->gtk_rekey_failure)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_GTK_REKEY_FAIL);
if (wowlan->eap_identity_req)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_EAP_IDENT_REQ);
if (wowlan->four_way_handshake)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_4WAY_HANDSHAKE);
if (wowlan->n_patterns)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_PATTERN_MATCH);
if (wowlan->rfkill_release)
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_RF_KILL_DEASSERT);
if (wowlan->tcp) {
wowlan_config_cmd->wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_REMOTE_LINK_LOSS |
IWL_WOWLAN_WAKEUP_REMOTE_SIGNATURE_TABLE |
IWL_WOWLAN_WAKEUP_REMOTE_WAKEUP_PACKET |
IWL_WOWLAN_WAKEUP_LINK_CHANGE);
}
return 0;
}
static void
iwl_mvm_iter_d0i3_ap_keys(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
void (*iter)(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key,
void *data),
void *data)
{
struct ieee80211_sta *ap_sta;
rcu_read_lock();
ap_sta = rcu_dereference(mvm->fw_id_to_mac_id[mvm->d0i3_ap_sta_id]);
if (IS_ERR_OR_NULL(ap_sta))
goto out;
ieee80211_iter_keys_rcu(mvm->hw, vif, iter, data);
out:
rcu_read_unlock();
}
int iwl_mvm_wowlan_config_key_params(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
bool d0i3,
u32 cmd_flags)
{
struct iwl_wowlan_kek_kck_material_cmd kek_kck_cmd = {};
struct iwl_wowlan_tkip_params_cmd tkip_cmd = {};
struct wowlan_key_data key_data = {
.configure_keys = !d0i3,
.use_rsc_tsc = false,
.tkip = &tkip_cmd,
.use_tkip = false,
};
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
int ret;
key_data.rsc_tsc = kzalloc(sizeof(*key_data.rsc_tsc), GFP_KERNEL);
if (!key_data.rsc_tsc)
return -ENOMEM;
if (!d0i3) {
ieee80211_iter_keys(mvm->hw, vif,
iwl_mvm_wowlan_program_keys,
&key_data);
} else {
iwl_mvm_iter_d0i3_ap_keys(mvm, vif,
iwl_mvm_wowlan_program_keys,
&key_data);
}
if (key_data.error) {
ret = -EIO;
goto out;
}
if (key_data.use_rsc_tsc) {
ret = iwl_mvm_send_cmd_pdu(mvm,
WOWLAN_TSC_RSC_PARAM, cmd_flags,
sizeof(*key_data.rsc_tsc),
key_data.rsc_tsc);
if (ret)
goto out;
}
if (key_data.use_tkip) {
ret = iwl_mvm_send_cmd_pdu(mvm,
WOWLAN_TKIP_PARAM,
cmd_flags, sizeof(tkip_cmd),
&tkip_cmd);
if (ret)
goto out;
}
if (mvmvif->rekey_data.valid && !d0i3) {
memset(&kek_kck_cmd, 0, sizeof(kek_kck_cmd));
memcpy(kek_kck_cmd.kck, mvmvif->rekey_data.kck,
NL80211_KCK_LEN);
kek_kck_cmd.kck_len = cpu_to_le16(NL80211_KCK_LEN);
memcpy(kek_kck_cmd.kek, mvmvif->rekey_data.kek,
NL80211_KEK_LEN);
kek_kck_cmd.kek_len = cpu_to_le16(NL80211_KEK_LEN);
kek_kck_cmd.replay_ctr = mvmvif->rekey_data.replay_ctr;
ret = iwl_mvm_send_cmd_pdu(mvm,
WOWLAN_KEK_KCK_MATERIAL, cmd_flags,
sizeof(kek_kck_cmd),
&kek_kck_cmd);
if (ret)
goto out;
}
ret = 0;
out:
kfree(key_data.rsc_tsc);
return ret;
}
static int
iwl_mvm_wowlan_config(struct iwl_mvm *mvm,
struct cfg80211_wowlan *wowlan,
struct iwl_wowlan_config_cmd *wowlan_config_cmd,
struct ieee80211_vif *vif, struct iwl_mvm_vif *mvmvif,
struct ieee80211_sta *ap_sta)
{
int ret;
bool unified_image = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG);
if (!unified_image) {
ret = iwl_mvm_switch_to_d3(mvm);
if (ret)
return ret;
ret = iwl_mvm_d3_reprogram(mvm, vif, ap_sta);
if (ret)
return ret;
}
if (!iwlwifi_mod_params.sw_crypto) {
mutex_unlock(&mvm->mutex);
ret = iwl_mvm_wowlan_config_key_params(mvm, vif, false,
CMD_ASYNC);
mutex_lock(&mvm->mutex);
if (ret)
return ret;
}
ret = iwl_mvm_send_cmd_pdu(mvm, WOWLAN_CONFIGURATION, 0,
sizeof(*wowlan_config_cmd),
wowlan_config_cmd);
if (ret)
return ret;
ret = iwl_mvm_send_patterns(mvm, wowlan);
if (ret)
return ret;
ret = iwl_mvm_send_proto_offload(mvm, vif, false, true, 0);
if (ret)
return ret;
ret = iwl_mvm_send_remote_wake_cfg(mvm, vif, wowlan->tcp);
return ret;
}
static int
iwl_mvm_netdetect_config(struct iwl_mvm *mvm,
struct cfg80211_wowlan *wowlan,
struct cfg80211_sched_scan_request *nd_config,
struct ieee80211_vif *vif)
{
struct iwl_wowlan_config_cmd wowlan_config_cmd = {};
int ret;
bool unified_image = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG);
if (!unified_image) {
ret = iwl_mvm_switch_to_d3(mvm);
if (ret)
return ret;
} else {
ret = iwl_mvm_scan_stop(mvm, IWL_MVM_SCAN_SCHED, true);
if (ret)
return ret;
}
if (wowlan->rfkill_release)
wowlan_config_cmd.wakeup_filter |=
cpu_to_le32(IWL_WOWLAN_WAKEUP_RF_KILL_DEASSERT);
ret = iwl_mvm_send_cmd_pdu(mvm, WOWLAN_CONFIGURATION, 0,
sizeof(wowlan_config_cmd),
&wowlan_config_cmd);
if (ret)
return ret;
ret = iwl_mvm_sched_scan_start(mvm, vif, nd_config, &mvm->nd_ies,
IWL_MVM_SCAN_NETDETECT);
if (ret)
return ret;
if (WARN_ON(mvm->nd_match_sets || mvm->nd_channels))
return -EBUSY;
if (nd_config->n_match_sets) {
mvm->nd_match_sets = kmemdup(nd_config->match_sets,
sizeof(*nd_config->match_sets) *
nd_config->n_match_sets,
GFP_KERNEL);
if (mvm->nd_match_sets)
mvm->n_nd_match_sets = nd_config->n_match_sets;
}
mvm->nd_channels = kmemdup(nd_config->channels,
sizeof(*nd_config->channels) *
nd_config->n_channels,
GFP_KERNEL);
if (mvm->nd_channels)
mvm->n_nd_channels = nd_config->n_channels;
return 0;
}
static void iwl_mvm_free_nd(struct iwl_mvm *mvm)
{
kfree(mvm->nd_match_sets);
mvm->nd_match_sets = NULL;
mvm->n_nd_match_sets = 0;
kfree(mvm->nd_channels);
mvm->nd_channels = NULL;
mvm->n_nd_channels = 0;
}
static int __iwl_mvm_suspend(struct ieee80211_hw *hw,
struct cfg80211_wowlan *wowlan,
bool test)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct ieee80211_vif *vif = NULL;
struct iwl_mvm_vif *mvmvif = NULL;
struct ieee80211_sta *ap_sta = NULL;
struct iwl_d3_manager_config d3_cfg_cmd_data = {
.min_sleep_time = cpu_to_le32(10 * 1000 * 1000),
};
struct iwl_host_cmd d3_cfg_cmd = {
.id = D3_CONFIG_CMD,
.flags = CMD_WANT_SKB,
.data[0] = &d3_cfg_cmd_data,
.len[0] = sizeof(d3_cfg_cmd_data),
};
int ret;
int len __maybe_unused;
bool unified_image = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG);
if (!wowlan) {
WARN_ON(!test);
return -EINVAL;
}
mutex_lock(&mvm->mutex);
vif = iwl_mvm_get_bss_vif(mvm);
if (IS_ERR_OR_NULL(vif)) {
ret = 1;
goto out_noreset;
}
mvmvif = iwl_mvm_vif_from_mac80211(vif);
if (mvmvif->ap_sta_id == IWL_MVM_STATION_COUNT) {
if (!wowlan->nd_config) {
ret = 1;
goto out_noreset;
}
ret = iwl_mvm_netdetect_config(
mvm, wowlan, wowlan->nd_config, vif);
if (ret)
goto out;
mvm->net_detect = true;
} else {
struct iwl_wowlan_config_cmd wowlan_config_cmd = {};
ap_sta = rcu_dereference_protected(
mvm->fw_id_to_mac_id[mvmvif->ap_sta_id],
lockdep_is_held(&mvm->mutex));
if (IS_ERR_OR_NULL(ap_sta)) {
ret = -EINVAL;
goto out_noreset;
}
ret = iwl_mvm_get_wowlan_config(mvm, wowlan, &wowlan_config_cmd,
vif, mvmvif, ap_sta);
if (ret)
goto out_noreset;
ret = iwl_mvm_wowlan_config(mvm, wowlan, &wowlan_config_cmd,
vif, mvmvif, ap_sta);
if (ret)
goto out;
mvm->net_detect = false;
}
ret = iwl_mvm_power_update_device(mvm);
if (ret)
goto out;
ret = iwl_mvm_power_update_mac(mvm);
if (ret)
goto out;
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (mvm->d3_wake_sysassert)
d3_cfg_cmd_data.wakeup_flags |=
cpu_to_le32(IWL_WAKEUP_D3_CONFIG_FW_ERROR);
#endif
ret = iwl_mvm_send_cmd(mvm, &d3_cfg_cmd);
if (ret)
goto out;
#ifdef CONFIG_IWLWIFI_DEBUGFS
len = iwl_rx_packet_payload_len(d3_cfg_cmd.resp_pkt);
if (len >= sizeof(u32)) {
mvm->d3_test_pme_ptr =
le32_to_cpup((__le32 *)d3_cfg_cmd.resp_pkt->data);
}
#endif
iwl_free_resp(&d3_cfg_cmd);
clear_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
iwl_trans_d3_suspend(mvm->trans, test, !unified_image);
out:
if (ret < 0) {
iwl_mvm_free_nd(mvm);
if (!unified_image) {
iwl_mvm_ref(mvm, IWL_MVM_REF_UCODE_DOWN);
if (mvm->restart_fw > 0) {
mvm->restart_fw--;
ieee80211_restart_hw(mvm->hw);
}
}
}
out_noreset:
mutex_unlock(&mvm->mutex);
return ret;
}
static int iwl_mvm_enter_d0i3_sync(struct iwl_mvm *mvm)
{
struct iwl_notification_wait wait_d3;
static const u16 d3_notif[] = { D3_CONFIG_CMD };
int ret;
iwl_init_notification_wait(&mvm->notif_wait, &wait_d3,
d3_notif, ARRAY_SIZE(d3_notif),
NULL, NULL);
ret = iwl_mvm_enter_d0i3(mvm->hw->priv);
if (ret)
goto remove_notif;
ret = iwl_wait_notification(&mvm->notif_wait, &wait_d3, HZ);
WARN_ON_ONCE(ret);
return ret;
remove_notif:
iwl_remove_notification(&mvm->notif_wait, &wait_d3);
return ret;
}
int iwl_mvm_suspend(struct ieee80211_hw *hw, struct cfg80211_wowlan *wowlan)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
struct iwl_trans *trans = mvm->trans;
int ret;
flush_work(&mvm->d0i3_exit_work);
ret = iwl_trans_suspend(trans);
if (ret)
return ret;
if (wowlan->any) {
trans->system_pm_mode = IWL_PLAT_PM_MODE_D0I3;
if (iwl_mvm_enter_d0i3_on_suspend(mvm)) {
ret = iwl_mvm_enter_d0i3_sync(mvm);
if (ret)
return ret;
}
mutex_lock(&mvm->d0i3_suspend_mutex);
__set_bit(D0I3_DEFER_WAKEUP, &mvm->d0i3_suspend_flags);
mutex_unlock(&mvm->d0i3_suspend_mutex);
iwl_trans_d3_suspend(trans, false, false);
return 0;
}
trans->system_pm_mode = IWL_PLAT_PM_MODE_D3;
return __iwl_mvm_suspend(hw, wowlan, false);
}
static void iwl_mvm_report_wakeup_reasons(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_wowlan_status_data *status)
{
struct sk_buff *pkt = NULL;
struct cfg80211_wowlan_wakeup wakeup = {
.pattern_idx = -1,
};
struct cfg80211_wowlan_wakeup *wakeup_report = &wakeup;
u32 reasons = status->wakeup_reasons;
if (reasons == IWL_WOWLAN_WAKEUP_BY_NON_WIRELESS) {
wakeup_report = NULL;
goto report;
}
pm_wakeup_event(mvm->dev, 0);
if (reasons & IWL_WOWLAN_WAKEUP_BY_MAGIC_PACKET)
wakeup.magic_pkt = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_PATTERN)
wakeup.pattern_idx =
status->pattern_number;
if (reasons & (IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_MISSED_BEACON |
IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_DEAUTH))
wakeup.disconnect = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_GTK_REKEY_FAILURE)
wakeup.gtk_rekey_failure = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_RFKILL_DEASSERTED)
wakeup.rfkill_release = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_EAPOL_REQUEST)
wakeup.eap_identity_req = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_FOUR_WAY_HANDSHAKE)
wakeup.four_way_handshake = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_REM_WAKE_LINK_LOSS)
wakeup.tcp_connlost = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_REM_WAKE_SIGNATURE_TABLE)
wakeup.tcp_nomoretokens = true;
if (reasons & IWL_WOWLAN_WAKEUP_BY_REM_WAKE_WAKEUP_PACKET)
wakeup.tcp_match = true;
if (status->wake_packet_bufsize) {
int pktsize = status->wake_packet_bufsize;
int pktlen = status->wake_packet_length;
const u8 *pktdata = status->wake_packet;
struct ieee80211_hdr *hdr = (void *)pktdata;
int truncated = pktlen - pktsize;
if (WARN_ON_ONCE(truncated < 0))
truncated = 0;
if (ieee80211_is_data(hdr->frame_control)) {
int hdrlen = ieee80211_hdrlen(hdr->frame_control);
int ivlen = 0, icvlen = 4;
pkt = alloc_skb(pktsize, GFP_KERNEL);
if (!pkt)
goto report;
memcpy(skb_put(pkt, hdrlen), pktdata, hdrlen);
pktdata += hdrlen;
pktsize -= hdrlen;
if (ieee80211_has_protected(hdr->frame_control)) {
if (is_multicast_ether_addr(hdr->addr1)) {
ivlen = mvm->gtk_ivlen;
icvlen += mvm->gtk_icvlen;
} else {
ivlen = mvm->ptk_ivlen;
icvlen += mvm->ptk_icvlen;
}
}
if (truncated >= icvlen) {
icvlen = 0;
truncated -= icvlen;
} else {
icvlen -= truncated;
truncated = 0;
}
pktsize -= ivlen + icvlen;
pktdata += ivlen;
memcpy(skb_put(pkt, pktsize), pktdata, pktsize);
if (ieee80211_data_to_8023(pkt, vif->addr, vif->type))
goto report;
wakeup.packet = pkt->data;
wakeup.packet_present_len = pkt->len;
wakeup.packet_len = pkt->len - truncated;
wakeup.packet_80211 = false;
} else {
int fcslen = 4;
if (truncated >= 4) {
truncated -= 4;
fcslen = 0;
} else {
fcslen -= truncated;
truncated = 0;
}
pktsize -= fcslen;
wakeup.packet = status->wake_packet;
wakeup.packet_present_len = pktsize;
wakeup.packet_len = pktlen - truncated;
wakeup.packet_80211 = true;
}
}
report:
ieee80211_report_wowlan_wakeup(vif, wakeup_report, GFP_KERNEL);
kfree_skb(pkt);
}
static void iwl_mvm_aes_sc_to_seq(struct aes_sc *sc,
struct ieee80211_key_seq *seq)
{
u64 pn;
pn = le64_to_cpu(sc->pn);
seq->ccmp.pn[0] = pn >> 40;
seq->ccmp.pn[1] = pn >> 32;
seq->ccmp.pn[2] = pn >> 24;
seq->ccmp.pn[3] = pn >> 16;
seq->ccmp.pn[4] = pn >> 8;
seq->ccmp.pn[5] = pn;
}
static void iwl_mvm_tkip_sc_to_seq(struct tkip_sc *sc,
struct ieee80211_key_seq *seq)
{
seq->tkip.iv32 = le32_to_cpu(sc->iv32);
seq->tkip.iv16 = le16_to_cpu(sc->iv16);
}
static void iwl_mvm_set_aes_rx_seq(struct iwl_mvm *mvm, struct aes_sc *scs,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
int tid;
BUILD_BUG_ON(IWL_NUM_RSC != IEEE80211_NUM_TIDS);
if (sta && iwl_mvm_has_new_rx_api(mvm)) {
struct iwl_mvm_sta *mvmsta;
struct iwl_mvm_key_pn *ptk_pn;
mvmsta = iwl_mvm_sta_from_mac80211(sta);
ptk_pn = rcu_dereference_protected(mvmsta->ptk_pn[key->keyidx],
lockdep_is_held(&mvm->mutex));
if (WARN_ON(!ptk_pn))
return;
for (tid = 0; tid < IWL_MAX_TID_COUNT; tid++) {
struct ieee80211_key_seq seq = {};
int i;
iwl_mvm_aes_sc_to_seq(&scs[tid], &seq);
ieee80211_set_key_rx_seq(key, tid, &seq);
for (i = 1; i < mvm->trans->num_rx_queues; i++)
memcpy(ptk_pn->q[i].pn[tid],
seq.ccmp.pn, IEEE80211_CCMP_PN_LEN);
}
} else {
for (tid = 0; tid < IWL_NUM_RSC; tid++) {
struct ieee80211_key_seq seq = {};
iwl_mvm_aes_sc_to_seq(&scs[tid], &seq);
ieee80211_set_key_rx_seq(key, tid, &seq);
}
}
}
static void iwl_mvm_set_tkip_rx_seq(struct tkip_sc *scs,
struct ieee80211_key_conf *key)
{
int tid;
BUILD_BUG_ON(IWL_NUM_RSC != IEEE80211_NUM_TIDS);
for (tid = 0; tid < IWL_NUM_RSC; tid++) {
struct ieee80211_key_seq seq = {};
iwl_mvm_tkip_sc_to_seq(&scs[tid], &seq);
ieee80211_set_key_rx_seq(key, tid, &seq);
}
}
static void iwl_mvm_set_key_rx_seq(struct iwl_mvm *mvm,
struct ieee80211_key_conf *key,
struct iwl_wowlan_status *status)
{
union iwl_all_tsc_rsc *rsc = &status->gtk.rsc.all_tsc_rsc;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
iwl_mvm_set_aes_rx_seq(mvm, rsc->aes.multicast_rsc, NULL, key);
break;
case WLAN_CIPHER_SUITE_TKIP:
iwl_mvm_set_tkip_rx_seq(rsc->tkip.multicast_rsc, key);
break;
default:
WARN_ON(1);
}
}
static void iwl_mvm_d3_update_keys(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key,
void *_data)
{
struct iwl_mvm_d3_gtk_iter_data *data = _data;
if (data->unhandled_cipher)
return;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
return;
case WLAN_CIPHER_SUITE_CCMP:
case WLAN_CIPHER_SUITE_TKIP:
break;
default:
data->unhandled_cipher = true;
return;
}
data->num_keys++;
if (sta) {
struct ieee80211_key_seq seq = {};
union iwl_all_tsc_rsc *sc = &data->status->gtk.rsc.all_tsc_rsc;
if (data->find_phase)
return;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_CCMP:
iwl_mvm_set_aes_rx_seq(data->mvm, sc->aes.unicast_rsc,
sta, key);
atomic64_set(&key->tx_pn, le64_to_cpu(sc->aes.tsc.pn));
break;
case WLAN_CIPHER_SUITE_TKIP:
iwl_mvm_tkip_sc_to_seq(&sc->tkip.tsc, &seq);
iwl_mvm_set_tkip_rx_seq(sc->tkip.unicast_rsc, key);
atomic64_set(&key->tx_pn,
(u64)seq.tkip.iv16 |
((u64)seq.tkip.iv32 << 16));
break;
}
return;
}
if (data->find_phase) {
data->last_gtk = key;
data->cipher = key->cipher;
return;
}
if (data->status->num_of_gtk_rekeys)
ieee80211_remove_key(key);
else if (data->last_gtk == key)
iwl_mvm_set_key_rx_seq(data->mvm, key, data->status);
}
static bool iwl_mvm_setup_connection_keep(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_wowlan_status *status)
{
struct iwl_mvm_vif *mvmvif = iwl_mvm_vif_from_mac80211(vif);
struct iwl_mvm_d3_gtk_iter_data gtkdata = {
.mvm = mvm,
.status = status,
};
u32 disconnection_reasons =
IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_MISSED_BEACON |
IWL_WOWLAN_WAKEUP_BY_DISCONNECTION_ON_DEAUTH;
if (!status || !vif->bss_conf.bssid)
return false;
if (le32_to_cpu(status->wakeup_reasons) & disconnection_reasons)
return false;
gtkdata.find_phase = true;
ieee80211_iter_keys(mvm->hw, vif,
iwl_mvm_d3_update_keys, &gtkdata);
if (gtkdata.unhandled_cipher)
return false;
if (!gtkdata.num_keys)
goto out;
if (!gtkdata.last_gtk)
return false;
gtkdata.find_phase = false;
ieee80211_iter_keys(mvm->hw, vif,
iwl_mvm_d3_update_keys, &gtkdata);
if (status->num_of_gtk_rekeys) {
struct ieee80211_key_conf *key;
struct {
struct ieee80211_key_conf conf;
u8 key[32];
} conf = {
.conf.cipher = gtkdata.cipher,
.conf.keyidx = status->gtk.key_index,
};
switch (gtkdata.cipher) {
case WLAN_CIPHER_SUITE_CCMP:
conf.conf.keylen = WLAN_KEY_LEN_CCMP;
memcpy(conf.conf.key, status->gtk.decrypt_key,
WLAN_KEY_LEN_CCMP);
break;
case WLAN_CIPHER_SUITE_TKIP:
conf.conf.keylen = WLAN_KEY_LEN_TKIP;
memcpy(conf.conf.key, status->gtk.decrypt_key, 16);
memcpy(conf.conf.key +
NL80211_TKIP_DATA_OFFSET_RX_MIC_KEY,
status->gtk.tkip_mic_key, 8);
break;
}
key = ieee80211_gtk_rekey_add(vif, &conf.conf);
if (IS_ERR(key))
return false;
iwl_mvm_set_key_rx_seq(mvm, key, status);
}
if (status->num_of_gtk_rekeys) {
__be64 replay_ctr =
cpu_to_be64(le64_to_cpu(status->replay_ctr));
ieee80211_gtk_rekey_notify(vif, vif->bss_conf.bssid,
(void *)&replay_ctr, GFP_KERNEL);
}
out:
mvmvif->seqno_valid = true;
mvmvif->seqno = le16_to_cpu(status->non_qos_seq_ctr) + 0x10;
return true;
}
static struct iwl_wowlan_status *
iwl_mvm_get_wakeup_status(struct iwl_mvm *mvm, struct ieee80211_vif *vif)
{
u32 base = mvm->error_event_table[0];
struct error_table_start {
u32 valid;
u32 error_id;
} err_info;
struct iwl_host_cmd cmd = {
.id = WOWLAN_GET_STATUSES,
.flags = CMD_WANT_SKB,
};
struct iwl_wowlan_status *status, *fw_status;
int ret, len, status_size;
iwl_trans_read_mem_bytes(mvm->trans, base,
&err_info, sizeof(err_info));
if (err_info.valid) {
IWL_INFO(mvm, "error table is valid (%d) with error (%d)\n",
err_info.valid, err_info.error_id);
if (err_info.error_id == RF_KILL_INDICATOR_FOR_WOWLAN) {
struct cfg80211_wowlan_wakeup wakeup = {
.rfkill_release = true,
};
ieee80211_report_wowlan_wakeup(vif, &wakeup,
GFP_KERNEL);
}
return ERR_PTR(-EIO);
}
ret = iwl_mvm_send_cmd_pdu(mvm, OFFLOADS_QUERY_CMD, 0, 0, NULL);
if (ret)
IWL_ERR(mvm, "failed to query offload statistics (%d)\n", ret);
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret) {
IWL_ERR(mvm, "failed to query status (%d)\n", ret);
return ERR_PTR(ret);
}
if (!cmd.resp_pkt) {
fw_status = ERR_PTR(-ERFKILL);
goto out_free_resp;
}
status_size = sizeof(*fw_status);
len = iwl_rx_packet_payload_len(cmd.resp_pkt);
if (len < status_size) {
IWL_ERR(mvm, "Invalid WoWLAN status response!\n");
fw_status = ERR_PTR(-EIO);
goto out_free_resp;
}
status = (void *)cmd.resp_pkt->data;
if (len != (status_size +
ALIGN(le32_to_cpu(status->wake_packet_bufsize), 4))) {
IWL_ERR(mvm, "Invalid WoWLAN status response!\n");
fw_status = ERR_PTR(-EIO);
goto out_free_resp;
}
fw_status = kmemdup(status, len, GFP_KERNEL);
out_free_resp:
iwl_free_resp(&cmd);
return fw_status;
}
static bool iwl_mvm_query_wakeup_reasons(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct iwl_wowlan_status_data status;
struct iwl_wowlan_status *fw_status;
int i;
bool keep;
struct iwl_mvm_sta *mvm_ap_sta;
fw_status = iwl_mvm_get_wakeup_status(mvm, vif);
if (IS_ERR_OR_NULL(fw_status))
goto out_unlock;
status.pattern_number = le16_to_cpu(fw_status->pattern_number);
for (i = 0; i < 8; i++)
status.qos_seq_ctr[i] =
le16_to_cpu(fw_status->qos_seq_ctr[i]);
status.wakeup_reasons = le32_to_cpu(fw_status->wakeup_reasons);
status.wake_packet_length =
le32_to_cpu(fw_status->wake_packet_length);
status.wake_packet_bufsize =
le32_to_cpu(fw_status->wake_packet_bufsize);
status.wake_packet = fw_status->wake_packet;
mvm_ap_sta = iwl_mvm_sta_from_staid_protected(mvm, 0);
if (!mvm_ap_sta)
goto out_free;
for (i = 0; i < IWL_MAX_TID_COUNT; i++) {
u16 seq = status.qos_seq_ctr[i];
seq += 0x10;
mvm_ap_sta->tid_data[i].seq_number = seq;
}
mutex_unlock(&mvm->mutex);
iwl_mvm_report_wakeup_reasons(mvm, vif, &status);
keep = iwl_mvm_setup_connection_keep(mvm, vif, fw_status);
kfree(fw_status);
return keep;
out_free:
kfree(fw_status);
out_unlock:
mutex_unlock(&mvm->mutex);
return false;
}
void iwl_mvm_d0i3_update_keys(struct iwl_mvm *mvm,
struct ieee80211_vif *vif,
struct iwl_wowlan_status *status)
{
struct iwl_mvm_d3_gtk_iter_data gtkdata = {
.mvm = mvm,
.status = status,
};
if (WARN_ON_ONCE(status->num_of_gtk_rekeys))
return;
gtkdata.find_phase = true;
iwl_mvm_iter_d0i3_ap_keys(mvm, vif, iwl_mvm_d3_update_keys, &gtkdata);
gtkdata.find_phase = false;
iwl_mvm_iter_d0i3_ap_keys(mvm, vif, iwl_mvm_d3_update_keys, &gtkdata);
}
static int
iwl_mvm_netdetect_query_results(struct iwl_mvm *mvm,
struct iwl_mvm_nd_query_results *results)
{
struct iwl_scan_offload_profiles_query *query;
struct iwl_host_cmd cmd = {
.id = SCAN_OFFLOAD_PROFILES_QUERY_CMD,
.flags = CMD_WANT_SKB,
};
int ret, len;
ret = iwl_mvm_send_cmd(mvm, &cmd);
if (ret) {
IWL_ERR(mvm, "failed to query matched profiles (%d)\n", ret);
return ret;
}
if (!cmd.resp_pkt) {
ret = -ERFKILL;
goto out_free_resp;
}
len = iwl_rx_packet_payload_len(cmd.resp_pkt);
if (len < sizeof(*query)) {
IWL_ERR(mvm, "Invalid scan offload profiles query response!\n");
ret = -EIO;
goto out_free_resp;
}
query = (void *)cmd.resp_pkt->data;
results->matched_profiles = le32_to_cpu(query->matched_profiles);
memcpy(results->matches, query->matches, sizeof(results->matches));
#ifdef CONFIG_IWLWIFI_DEBUGFS
mvm->last_netdetect_scans = le32_to_cpu(query->n_scans_done);
#endif
out_free_resp:
iwl_free_resp(&cmd);
return ret;
}
static void iwl_mvm_query_netdetect_reasons(struct iwl_mvm *mvm,
struct ieee80211_vif *vif)
{
struct cfg80211_wowlan_nd_info *net_detect = NULL;
struct cfg80211_wowlan_wakeup wakeup = {
.pattern_idx = -1,
};
struct cfg80211_wowlan_wakeup *wakeup_report = &wakeup;
struct iwl_mvm_nd_query_results query;
struct iwl_wowlan_status *fw_status;
unsigned long matched_profiles;
u32 reasons = 0;
int i, j, n_matches, ret;
fw_status = iwl_mvm_get_wakeup_status(mvm, vif);
if (!IS_ERR_OR_NULL(fw_status)) {
reasons = le32_to_cpu(fw_status->wakeup_reasons);
kfree(fw_status);
}
if (reasons & IWL_WOWLAN_WAKEUP_BY_RFKILL_DEASSERTED)
wakeup.rfkill_release = true;
if (reasons != IWL_WOWLAN_WAKEUP_BY_NON_WIRELESS)
goto out;
ret = iwl_mvm_netdetect_query_results(mvm, &query);
if (ret || !query.matched_profiles) {
wakeup_report = NULL;
goto out;
}
matched_profiles = query.matched_profiles;
if (mvm->n_nd_match_sets) {
n_matches = hweight_long(matched_profiles);
} else {
IWL_ERR(mvm, "no net detect match information available\n");
n_matches = 0;
}
net_detect = kzalloc(sizeof(*net_detect) +
(n_matches * sizeof(net_detect->matches[0])),
GFP_KERNEL);
if (!net_detect || !n_matches)
goto out_report_nd;
for_each_set_bit(i, &matched_profiles, mvm->n_nd_match_sets) {
struct iwl_scan_offload_profile_match *fw_match;
struct cfg80211_wowlan_nd_match *match;
int idx, n_channels = 0;
fw_match = &query.matches[i];
for (j = 0; j < SCAN_OFFLOAD_MATCHING_CHANNELS_LEN; j++)
n_channels += hweight8(fw_match->matching_channels[j]);
match = kzalloc(sizeof(*match) +
(n_channels * sizeof(*match->channels)),
GFP_KERNEL);
if (!match)
goto out_report_nd;
net_detect->matches[net_detect->n_matches++] = match;
idx = mvm->n_nd_match_sets - i - 1;
match->ssid.ssid_len = mvm->nd_match_sets[idx].ssid.ssid_len;
memcpy(match->ssid.ssid, mvm->nd_match_sets[idx].ssid.ssid,
match->ssid.ssid_len);
if (mvm->n_nd_channels < n_channels)
continue;
for (j = 0; j < SCAN_OFFLOAD_MATCHING_CHANNELS_LEN * 8; j++)
if (fw_match->matching_channels[j / 8] & (BIT(j % 8)))
match->channels[match->n_channels++] =
mvm->nd_channels[j]->center_freq;
}
out_report_nd:
wakeup.net_detect = net_detect;
out:
iwl_mvm_free_nd(mvm);
mutex_unlock(&mvm->mutex);
ieee80211_report_wowlan_wakeup(vif, wakeup_report, GFP_KERNEL);
if (net_detect) {
for (i = 0; i < net_detect->n_matches; i++)
kfree(net_detect->matches[i]);
kfree(net_detect);
}
}
static void iwl_mvm_read_d3_sram(struct iwl_mvm *mvm)
{
#ifdef CONFIG_IWLWIFI_DEBUGFS
const struct fw_img *img = &mvm->fw->img[IWL_UCODE_WOWLAN];
u32 len = img->sec[IWL_UCODE_SECTION_DATA].len;
u32 offs = img->sec[IWL_UCODE_SECTION_DATA].offset;
if (!mvm->store_d3_resume_sram)
return;
if (!mvm->d3_resume_sram) {
mvm->d3_resume_sram = kzalloc(len, GFP_KERNEL);
if (!mvm->d3_resume_sram)
return;
}
iwl_trans_read_mem_bytes(mvm->trans, offs, mvm->d3_resume_sram, len);
#endif
}
static void iwl_mvm_d3_disconnect_iter(void *data, u8 *mac,
struct ieee80211_vif *vif)
{
if (data == vif)
return;
if (vif->type == NL80211_IFTYPE_STATION)
ieee80211_resume_disconnect(vif);
}
static int __iwl_mvm_resume(struct iwl_mvm *mvm, bool test)
{
struct ieee80211_vif *vif = NULL;
int ret = 1;
enum iwl_d3_status d3_status;
bool keep = false;
bool unified_image = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG);
u32 flags = CMD_ASYNC | CMD_HIGH_PRIO | CMD_SEND_IN_IDLE |
CMD_WAKE_UP_TRANS;
mutex_lock(&mvm->mutex);
vif = iwl_mvm_get_bss_vif(mvm);
if (IS_ERR_OR_NULL(vif))
goto err;
ret = iwl_trans_d3_resume(mvm->trans, &d3_status, test, !unified_image);
if (ret)
goto err;
if (d3_status != IWL_D3_STATUS_ALIVE) {
IWL_INFO(mvm, "Device was reset during suspend\n");
goto err;
}
iwl_mvm_read_d3_sram(mvm);
iwl_mvm_update_changed_regdom(mvm);
if (mvm->net_detect) {
if (unified_image)
ret = iwl_mvm_scan_stop(mvm, IWL_MVM_SCAN_NETDETECT,
false);
iwl_mvm_query_netdetect_reasons(mvm, vif);
goto out;
} else {
keep = iwl_mvm_query_wakeup_reasons(mvm, vif);
#ifdef CONFIG_IWLWIFI_DEBUGFS
if (keep)
mvm->keep_vif = vif;
#endif
goto out_iterate;
}
err:
iwl_mvm_free_nd(mvm);
mutex_unlock(&mvm->mutex);
out_iterate:
if (!test)
ieee80211_iterate_active_interfaces_rtnl(mvm->hw,
IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_d3_disconnect_iter, keep ? vif : NULL);
out:
if (unified_image && !ret) {
ret = iwl_mvm_send_cmd_pdu(mvm, D0I3_END_CMD, flags, 0, NULL);
if (!ret)
return 0;
}
set_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status);
set_bit(IWL_MVM_STATUS_D3_RECONFIG, &mvm->status);
iwl_mvm_ref(mvm, IWL_MVM_REF_UCODE_DOWN);
return 1;
}
static int iwl_mvm_resume_d3(struct iwl_mvm *mvm)
{
iwl_trans_resume(mvm->trans);
return __iwl_mvm_resume(mvm, false);
}
static int iwl_mvm_resume_d0i3(struct iwl_mvm *mvm)
{
bool exit_now;
enum iwl_d3_status d3_status;
struct iwl_trans *trans = mvm->trans;
iwl_trans_d3_resume(trans, &d3_status, false, false);
mutex_lock(&mvm->d0i3_suspend_mutex);
__clear_bit(D0I3_DEFER_WAKEUP, &mvm->d0i3_suspend_flags);
exit_now = __test_and_clear_bit(D0I3_PENDING_WAKEUP,
&mvm->d0i3_suspend_flags);
mutex_unlock(&mvm->d0i3_suspend_mutex);
if (exit_now) {
IWL_DEBUG_RPM(mvm, "Run deferred d0i3 exit\n");
_iwl_mvm_exit_d0i3(mvm);
}
iwl_trans_resume(trans);
if (iwl_mvm_enter_d0i3_on_suspend(mvm)) {
int ret = iwl_mvm_exit_d0i3(mvm->hw->priv);
if (ret)
return ret;
}
return 0;
}
int iwl_mvm_resume(struct ieee80211_hw *hw)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
int ret;
if (mvm->trans->system_pm_mode == IWL_PLAT_PM_MODE_D0I3)
ret = iwl_mvm_resume_d0i3(mvm);
else
ret = iwl_mvm_resume_d3(mvm);
mvm->trans->system_pm_mode = IWL_PLAT_PM_MODE_DISABLED;
return ret;
}
void iwl_mvm_set_wakeup(struct ieee80211_hw *hw, bool enabled)
{
struct iwl_mvm *mvm = IWL_MAC80211_GET_MVM(hw);
device_set_wakeup_enable(mvm->trans->dev, enabled);
}
static int iwl_mvm_d3_test_open(struct inode *inode, struct file *file)
{
struct iwl_mvm *mvm = inode->i_private;
int err;
if (mvm->d3_test_active)
return -EBUSY;
file->private_data = inode->i_private;
ieee80211_stop_queues(mvm->hw);
synchronize_net();
mvm->trans->system_pm_mode = IWL_PLAT_PM_MODE_D3;
rtnl_lock();
err = __iwl_mvm_suspend(mvm->hw, mvm->hw->wiphy->wowlan_config, true);
rtnl_unlock();
if (err > 0)
err = -EINVAL;
if (err) {
ieee80211_wake_queues(mvm->hw);
return err;
}
mvm->d3_test_active = true;
mvm->keep_vif = NULL;
return 0;
}
static ssize_t iwl_mvm_d3_test_read(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
struct iwl_mvm *mvm = file->private_data;
u32 pme_asserted;
while (true) {
if (mvm->d3_test_pme_ptr) {
pme_asserted = iwl_trans_read_mem32(mvm->trans,
mvm->d3_test_pme_ptr);
if (pme_asserted)
break;
}
if (msleep_interruptible(100))
break;
}
return 0;
}
static void iwl_mvm_d3_test_disconn_work_iter(void *_data, u8 *mac,
struct ieee80211_vif *vif)
{
if (_data == vif)
return;
if (vif->type == NL80211_IFTYPE_STATION)
ieee80211_connection_loss(vif);
}
static int iwl_mvm_d3_test_release(struct inode *inode, struct file *file)
{
struct iwl_mvm *mvm = inode->i_private;
bool unified_image = fw_has_capa(&mvm->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG);
mvm->d3_test_active = false;
rtnl_lock();
__iwl_mvm_resume(mvm, true);
rtnl_unlock();
mvm->trans->system_pm_mode = IWL_PLAT_PM_MODE_DISABLED;
iwl_abort_notification_waits(&mvm->notif_wait);
if (!unified_image) {
int remaining_time = 10;
ieee80211_restart_hw(mvm->hw);
while (test_bit(IWL_MVM_STATUS_IN_HW_RESTART, &mvm->status) &&
remaining_time > 0) {
remaining_time--;
msleep(1000);
}
if (remaining_time == 0)
IWL_ERR(mvm, "Timed out waiting for HW restart!\n");
}
ieee80211_iterate_active_interfaces_atomic(
mvm->hw, IEEE80211_IFACE_ITER_NORMAL,
iwl_mvm_d3_test_disconn_work_iter, mvm->keep_vif);
ieee80211_wake_queues(mvm->hw);
return 0;
}
