static u16
mwifiex_convert_mcsmap_to_maxrate(struct mwifiex_private *priv,
u8 bands, u16 mcs_map)
{
u8 i, nss, mcs;
u16 max_rate = 0;
u32 usr_vht_cap_info = 0;
struct mwifiex_adapter *adapter = priv->adapter;
if (bands & BAND_AAC)
usr_vht_cap_info = adapter->usr_dot_11ac_dev_cap_a;
else
usr_vht_cap_info = adapter->usr_dot_11ac_dev_cap_bg;
nss = 1;
for (i = 1; i <= 8; i++) {
mcs = GET_VHTNSSMCS(mcs_map, i);
if (mcs < IEEE80211_VHT_MCS_NOT_SUPPORTED)
nss = i;
}
mcs = GET_VHTNSSMCS(mcs_map, nss);
if (mcs == IEEE80211_VHT_MCS_NOT_SUPPORTED)
mcs = IEEE80211_VHT_MCS_SUPPORT_0_9;
if (GET_VHTCAP_CHWDSET(usr_vht_cap_info)) {
max_rate = max_rate_lgi_160MHZ[nss - 1][mcs];
if (!max_rate)
max_rate = max_rate_lgi_160MHZ[nss - 1][mcs - 1];
} else {
max_rate = max_rate_lgi_80MHZ[nss - 1][mcs];
if (!max_rate)
max_rate = max_rate_lgi_80MHZ[nss - 1][mcs - 1];
}
return max_rate;
}
static void
mwifiex_fill_vht_cap_info(struct mwifiex_private *priv,
struct ieee80211_vht_cap *vht_cap, u8 bands)
{
struct mwifiex_adapter *adapter = priv->adapter;
if (bands & BAND_A)
vht_cap->vht_cap_info =
cpu_to_le32(adapter->usr_dot_11ac_dev_cap_a);
else
vht_cap->vht_cap_info =
cpu_to_le32(adapter->usr_dot_11ac_dev_cap_bg);
}
void mwifiex_fill_vht_cap_tlv(struct mwifiex_private *priv,
struct ieee80211_vht_cap *vht_cap, u8 bands)
{
struct mwifiex_adapter *adapter = priv->adapter;
u16 mcs_map_user, mcs_map_resp, mcs_map_result;
u16 mcs_user, mcs_resp, nss, tmp;
mwifiex_fill_vht_cap_info(priv, vht_cap, bands);
mcs_map_user = GET_DEVRXMCSMAP(adapter->usr_dot_11ac_mcs_support);
mcs_map_resp = le16_to_cpu(vht_cap->supp_mcs.rx_mcs_map);
mcs_map_result = 0;
for (nss = 1; nss <= 8; nss++) {
mcs_user = GET_VHTNSSMCS(mcs_map_user, nss);
mcs_resp = GET_VHTNSSMCS(mcs_map_resp, nss);
if ((mcs_user == IEEE80211_VHT_MCS_NOT_SUPPORTED) ||
(mcs_resp == IEEE80211_VHT_MCS_NOT_SUPPORTED))
SET_VHTNSSMCS(mcs_map_result, nss,
IEEE80211_VHT_MCS_NOT_SUPPORTED);
else
SET_VHTNSSMCS(mcs_map_result, nss,
min(mcs_user, mcs_resp));
}
vht_cap->supp_mcs.rx_mcs_map = cpu_to_le16(mcs_map_result);
tmp = mwifiex_convert_mcsmap_to_maxrate(priv, bands, mcs_map_result);
vht_cap->supp_mcs.rx_highest = cpu_to_le16(tmp);
mcs_map_user = GET_DEVTXMCSMAP(adapter->usr_dot_11ac_mcs_support);
mcs_map_resp = le16_to_cpu(vht_cap->supp_mcs.tx_mcs_map);
mcs_map_result = 0;
for (nss = 1; nss <= 8; nss++) {
mcs_user = GET_VHTNSSMCS(mcs_map_user, nss);
mcs_resp = GET_VHTNSSMCS(mcs_map_resp, nss);
if ((mcs_user == IEEE80211_VHT_MCS_NOT_SUPPORTED) ||
(mcs_resp == IEEE80211_VHT_MCS_NOT_SUPPORTED))
SET_VHTNSSMCS(mcs_map_result, nss,
IEEE80211_VHT_MCS_NOT_SUPPORTED);
else
SET_VHTNSSMCS(mcs_map_result, nss,
min(mcs_user, mcs_resp));
}
vht_cap->supp_mcs.tx_mcs_map = cpu_to_le16(mcs_map_result);
tmp = mwifiex_convert_mcsmap_to_maxrate(priv, bands, mcs_map_result);
vht_cap->supp_mcs.tx_highest = cpu_to_le16(tmp);
return;
}
int mwifiex_cmd_append_11ac_tlv(struct mwifiex_private *priv,
struct mwifiex_bssdescriptor *bss_desc,
u8 **buffer)
{
struct mwifiex_ie_types_vhtcap *vht_cap;
struct mwifiex_ie_types_oper_mode_ntf *oper_ntf;
struct ieee_types_oper_mode_ntf *ieee_oper_ntf;
struct mwifiex_ie_types_vht_oper *vht_op;
struct mwifiex_adapter *adapter = priv->adapter;
u8 supp_chwd_set;
u32 usr_vht_cap_info;
int ret_len = 0;
if (bss_desc->bss_band & BAND_A)
usr_vht_cap_info = adapter->usr_dot_11ac_dev_cap_a;
else
usr_vht_cap_info = adapter->usr_dot_11ac_dev_cap_bg;
if (bss_desc->bcn_vht_cap) {
vht_cap = (struct mwifiex_ie_types_vhtcap *)*buffer;
memset(vht_cap, 0, sizeof(*vht_cap));
vht_cap->header.type = cpu_to_le16(WLAN_EID_VHT_CAPABILITY);
vht_cap->header.len =
cpu_to_le16(sizeof(struct ieee80211_vht_cap));
memcpy((u8 *)vht_cap + sizeof(struct mwifiex_ie_types_header),
(u8 *)bss_desc->bcn_vht_cap,
le16_to_cpu(vht_cap->header.len));
mwifiex_fill_vht_cap_tlv(priv, &vht_cap->vht_cap,
bss_desc->bss_band);
*buffer += sizeof(*vht_cap);
ret_len += sizeof(*vht_cap);
}
if (bss_desc->bcn_vht_oper) {
if (priv->bss_mode == NL80211_IFTYPE_STATION) {
vht_op = (struct mwifiex_ie_types_vht_oper *)*buffer;
memset(vht_op, 0, sizeof(*vht_op));
vht_op->header.type =
cpu_to_le16(WLAN_EID_VHT_OPERATION);
vht_op->header.len = cpu_to_le16(sizeof(*vht_op) -
sizeof(struct mwifiex_ie_types_header));
memcpy((u8 *)vht_op +
sizeof(struct mwifiex_ie_types_header),
(u8 *)bss_desc->bcn_vht_oper +
sizeof(struct ieee_types_header),
le16_to_cpu(vht_op->header.len));
supp_chwd_set = GET_VHTCAP_CHWDSET(usr_vht_cap_info);
switch (supp_chwd_set) {
case 0:
vht_op->chan_width =
min_t(u8, IEEE80211_VHT_CHANWIDTH_80MHZ,
bss_desc->bcn_vht_oper->chan_width);
break;
case 1:
vht_op->chan_width =
min_t(u8, IEEE80211_VHT_CHANWIDTH_160MHZ,
bss_desc->bcn_vht_oper->chan_width);
break;
case 2:
vht_op->chan_width =
min_t(u8, IEEE80211_VHT_CHANWIDTH_80P80MHZ,
bss_desc->bcn_vht_oper->chan_width);
break;
default:
vht_op->chan_width =
IEEE80211_VHT_CHANWIDTH_USE_HT;
break;
}
*buffer += sizeof(*vht_op);
ret_len += sizeof(*vht_op);
}
}
if (bss_desc->oper_mode) {
ieee_oper_ntf = bss_desc->oper_mode;
oper_ntf = (void *)*buffer;
memset(oper_ntf, 0, sizeof(*oper_ntf));
oper_ntf->header.type = cpu_to_le16(WLAN_EID_OPMODE_NOTIF);
oper_ntf->header.len = cpu_to_le16(sizeof(u8));
oper_ntf->oper_mode = ieee_oper_ntf->oper_mode;
*buffer += sizeof(*oper_ntf);
ret_len += sizeof(*oper_ntf);
}
return ret_len;
}
int mwifiex_cmd_11ac_cfg(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd, u16 cmd_action,
struct mwifiex_11ac_vht_cfg *cfg)
{
struct host_cmd_11ac_vht_cfg *vhtcfg = &cmd->params.vht_cfg;
cmd->command = cpu_to_le16(HostCmd_CMD_11AC_CFG);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_11ac_vht_cfg) +
S_DS_GEN);
vhtcfg->action = cpu_to_le16(cmd_action);
vhtcfg->band_config = cfg->band_config;
vhtcfg->misc_config = cfg->misc_config;
vhtcfg->cap_info = cpu_to_le32(cfg->cap_info);
vhtcfg->mcs_tx_set = cpu_to_le32(cfg->mcs_tx_set);
vhtcfg->mcs_rx_set = cpu_to_le32(cfg->mcs_rx_set);
return 0;
}
void mwifiex_set_11ac_ba_params(struct mwifiex_private *priv)
{
priv->add_ba_param.timeout = MWIFIEX_DEFAULT_BLOCK_ACK_TIMEOUT;
if (GET_BSS_ROLE(priv) == MWIFIEX_BSS_ROLE_UAP) {
priv->add_ba_param.tx_win_size =
MWIFIEX_11AC_UAP_AMPDU_DEF_TXWINSIZE;
priv->add_ba_param.rx_win_size =
MWIFIEX_11AC_UAP_AMPDU_DEF_RXWINSIZE;
} else {
priv->add_ba_param.tx_win_size =
MWIFIEX_11AC_STA_AMPDU_DEF_TXWINSIZE;
priv->add_ba_param.rx_win_size =
MWIFIEX_11AC_STA_AMPDU_DEF_RXWINSIZE;
}
return;
}
bool mwifiex_is_bss_in_11ac_mode(struct mwifiex_private *priv)
{
struct mwifiex_bssdescriptor *bss_desc;
struct ieee80211_vht_operation *vht_oper;
bss_desc = &priv->curr_bss_params.bss_descriptor;
vht_oper = bss_desc->bcn_vht_oper;
if (!bss_desc->bcn_vht_cap || !vht_oper)
return false;
if (vht_oper->chan_width == IEEE80211_VHT_CHANWIDTH_USE_HT)
return false;
return true;
}
u8 mwifiex_get_center_freq_index(struct mwifiex_private *priv, u8 band,
u32 pri_chan, u8 chan_bw)
{
u8 center_freq_idx = 0;
if (band & BAND_AAC) {
switch (pri_chan) {
case 36:
case 40:
case 44:
case 48:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 42;
break;
case 52:
case 56:
case 60:
case 64:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 58;
else if (chan_bw == IEEE80211_VHT_CHANWIDTH_160MHZ)
center_freq_idx = 50;
break;
case 100:
case 104:
case 108:
case 112:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 106;
break;
case 116:
case 120:
case 124:
case 128:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 122;
else if (chan_bw == IEEE80211_VHT_CHANWIDTH_160MHZ)
center_freq_idx = 114;
break;
case 132:
case 136:
case 140:
case 144:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 138;
break;
case 149:
case 153:
case 157:
case 161:
if (chan_bw == IEEE80211_VHT_CHANWIDTH_80MHZ)
center_freq_idx = 155;
break;
default:
center_freq_idx = 42;
}
}
return center_freq_idx;
}
