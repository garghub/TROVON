static int
mwifiex_cmd_802_11_rssi_info(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd, u16 cmd_action)
{
cmd->command = cpu_to_le16(HostCmd_CMD_RSSI_INFO);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_rssi_info) +
S_DS_GEN);
cmd->params.rssi_info.action = cpu_to_le16(cmd_action);
cmd->params.rssi_info.ndata = cpu_to_le16(priv->data_avg_factor);
cmd->params.rssi_info.nbcn = cpu_to_le16(priv->bcn_avg_factor);
priv->data_rssi_last = 0;
priv->data_nf_last = 0;
priv->data_rssi_avg = 0;
priv->data_nf_avg = 0;
priv->bcn_rssi_last = 0;
priv->bcn_nf_last = 0;
priv->bcn_rssi_avg = 0;
priv->bcn_nf_avg = 0;
return 0;
}
static int mwifiex_cmd_mac_control(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action, u16 *action)
{
struct host_cmd_ds_mac_control *mac_ctrl = &cmd->params.mac_ctrl;
if (cmd_action != HostCmd_ACT_GEN_SET) {
dev_err(priv->adapter->dev,
"mac_control: only support set cmd\n");
return -1;
}
cmd->command = cpu_to_le16(HostCmd_CMD_MAC_CONTROL);
cmd->size =
cpu_to_le16(sizeof(struct host_cmd_ds_mac_control) + S_DS_GEN);
mac_ctrl->action = cpu_to_le16(*action);
return 0;
}
static int mwifiex_cmd_802_11_snmp_mib(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action, u32 cmd_oid,
u16 *ul_temp)
{
struct host_cmd_ds_802_11_snmp_mib *snmp_mib = &cmd->params.smib;
dev_dbg(priv->adapter->dev, "cmd: SNMP_CMD: cmd_oid = 0x%x\n", cmd_oid);
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_SNMP_MIB);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_snmp_mib)
- 1 + S_DS_GEN);
snmp_mib->oid = cpu_to_le16((u16)cmd_oid);
if (cmd_action == HostCmd_ACT_GEN_GET) {
snmp_mib->query_type = cpu_to_le16(HostCmd_ACT_GEN_GET);
snmp_mib->buf_size = cpu_to_le16(MAX_SNMP_BUF_SIZE);
le16_add_cpu(&cmd->size, MAX_SNMP_BUF_SIZE);
} else if (cmd_action == HostCmd_ACT_GEN_SET) {
snmp_mib->query_type = cpu_to_le16(HostCmd_ACT_GEN_SET);
snmp_mib->buf_size = cpu_to_le16(sizeof(u16));
*((__le16 *) (snmp_mib->value)) = cpu_to_le16(*ul_temp);
le16_add_cpu(&cmd->size, sizeof(u16));
}
dev_dbg(priv->adapter->dev,
"cmd: SNMP_CMD: Action=0x%x, OID=0x%x, OIDSize=0x%x,"
" Value=0x%x\n",
cmd_action, cmd_oid, le16_to_cpu(snmp_mib->buf_size),
le16_to_cpu(*(__le16 *) snmp_mib->value));
return 0;
}
static int
mwifiex_cmd_802_11_get_log(struct host_cmd_ds_command *cmd)
{
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_GET_LOG);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_get_log) +
S_DS_GEN);
return 0;
}
static int mwifiex_cmd_tx_rate_cfg(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action, u16 *pbitmap_rates)
{
struct host_cmd_ds_tx_rate_cfg *rate_cfg = &cmd->params.tx_rate_cfg;
struct mwifiex_rate_scope *rate_scope;
struct mwifiex_rate_drop_pattern *rate_drop;
u32 i;
cmd->command = cpu_to_le16(HostCmd_CMD_TX_RATE_CFG);
rate_cfg->action = cpu_to_le16(cmd_action);
rate_cfg->cfg_index = 0;
rate_scope = (struct mwifiex_rate_scope *) ((u8 *) rate_cfg +
sizeof(struct host_cmd_ds_tx_rate_cfg));
rate_scope->type = cpu_to_le16(TLV_TYPE_RATE_SCOPE);
rate_scope->length = cpu_to_le16
(sizeof(*rate_scope) - sizeof(struct mwifiex_ie_types_header));
if (pbitmap_rates != NULL) {
rate_scope->hr_dsss_rate_bitmap = cpu_to_le16(pbitmap_rates[0]);
rate_scope->ofdm_rate_bitmap = cpu_to_le16(pbitmap_rates[1]);
for (i = 0;
i < sizeof(rate_scope->ht_mcs_rate_bitmap) / sizeof(u16);
i++)
rate_scope->ht_mcs_rate_bitmap[i] =
cpu_to_le16(pbitmap_rates[2 + i]);
} else {
rate_scope->hr_dsss_rate_bitmap =
cpu_to_le16(priv->bitmap_rates[0]);
rate_scope->ofdm_rate_bitmap =
cpu_to_le16(priv->bitmap_rates[1]);
for (i = 0;
i < sizeof(rate_scope->ht_mcs_rate_bitmap) / sizeof(u16);
i++)
rate_scope->ht_mcs_rate_bitmap[i] =
cpu_to_le16(priv->bitmap_rates[2 + i]);
}
rate_drop = (struct mwifiex_rate_drop_pattern *) ((u8 *) rate_scope +
sizeof(struct mwifiex_rate_scope));
rate_drop->type = cpu_to_le16(TLV_TYPE_RATE_DROP_CONTROL);
rate_drop->length = cpu_to_le16(sizeof(rate_drop->rate_drop_mode));
rate_drop->rate_drop_mode = 0;
cmd->size =
cpu_to_le16(S_DS_GEN + sizeof(struct host_cmd_ds_tx_rate_cfg) +
sizeof(struct mwifiex_rate_scope) +
sizeof(struct mwifiex_rate_drop_pattern));
return 0;
}
static int mwifiex_cmd_tx_power_cfg(struct host_cmd_ds_command *cmd,
u16 cmd_action,
struct host_cmd_ds_txpwr_cfg *txp)
{
struct mwifiex_types_power_group *pg_tlv;
struct host_cmd_ds_txpwr_cfg *cmd_txp_cfg = &cmd->params.txp_cfg;
cmd->command = cpu_to_le16(HostCmd_CMD_TXPWR_CFG);
cmd->size =
cpu_to_le16(S_DS_GEN + sizeof(struct host_cmd_ds_txpwr_cfg));
switch (cmd_action) {
case HostCmd_ACT_GEN_SET:
if (txp->mode) {
pg_tlv = (struct mwifiex_types_power_group
*) ((unsigned long) txp +
sizeof(struct host_cmd_ds_txpwr_cfg));
memmove(cmd_txp_cfg, txp,
sizeof(struct host_cmd_ds_txpwr_cfg) +
sizeof(struct mwifiex_types_power_group) +
pg_tlv->length);
pg_tlv = (struct mwifiex_types_power_group *) ((u8 *)
cmd_txp_cfg +
sizeof(struct host_cmd_ds_txpwr_cfg));
cmd->size = cpu_to_le16(le16_to_cpu(cmd->size) +
sizeof(struct mwifiex_types_power_group) +
pg_tlv->length);
} else {
memmove(cmd_txp_cfg, txp, sizeof(*txp));
}
cmd_txp_cfg->action = cpu_to_le16(cmd_action);
break;
case HostCmd_ACT_GEN_GET:
cmd_txp_cfg->action = cpu_to_le16(cmd_action);
break;
}
return 0;
}
static int mwifiex_cmd_rf_tx_power(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action, void *data_buf)
{
struct host_cmd_ds_rf_tx_pwr *txp = &cmd->params.txp;
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_rf_tx_pwr)
+ S_DS_GEN);
cmd->command = cpu_to_le16(HostCmd_CMD_RF_TX_PWR);
txp->action = cpu_to_le16(cmd_action);
return 0;
}
static int mwifiex_cmd_rf_antenna(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action,
struct mwifiex_ds_ant_cfg *ant_cfg)
{
struct host_cmd_ds_rf_ant_mimo *ant_mimo = &cmd->params.ant_mimo;
struct host_cmd_ds_rf_ant_siso *ant_siso = &cmd->params.ant_siso;
cmd->command = cpu_to_le16(HostCmd_CMD_RF_ANTENNA);
if (cmd_action != HostCmd_ACT_GEN_SET)
return 0;
if (priv->adapter->hw_dev_mcs_support == HT_STREAM_2X2) {
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_rf_ant_mimo) +
S_DS_GEN);
ant_mimo->action_tx = cpu_to_le16(HostCmd_ACT_SET_TX);
ant_mimo->tx_ant_mode = cpu_to_le16((u16)ant_cfg->tx_ant);
ant_mimo->action_rx = cpu_to_le16(HostCmd_ACT_SET_RX);
ant_mimo->rx_ant_mode = cpu_to_le16((u16)ant_cfg->rx_ant);
} else {
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_rf_ant_siso) +
S_DS_GEN);
ant_siso->action = cpu_to_le16(HostCmd_ACT_SET_BOTH);
ant_siso->ant_mode = cpu_to_le16((u16)ant_cfg->tx_ant);
}
return 0;
}
static int
mwifiex_cmd_802_11_hs_cfg(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action,
struct mwifiex_hs_config_param *hscfg_param)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct host_cmd_ds_802_11_hs_cfg_enh *hs_cfg = &cmd->params.opt_hs_cfg;
u16 hs_activate = false;
if (!hscfg_param)
hs_activate = true;
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_HS_CFG_ENH);
if (!hs_activate &&
(hscfg_param->conditions != cpu_to_le32(HOST_SLEEP_CFG_CANCEL)) &&
((adapter->arp_filter_size > 0) &&
(adapter->arp_filter_size <= ARP_FILTER_MAX_BUF_SIZE))) {
dev_dbg(adapter->dev,
"cmd: Attach %d bytes ArpFilter to HSCfg cmd\n",
adapter->arp_filter_size);
memcpy(((u8 *) hs_cfg) +
sizeof(struct host_cmd_ds_802_11_hs_cfg_enh),
adapter->arp_filter, adapter->arp_filter_size);
cmd->size = cpu_to_le16
(adapter->arp_filter_size +
sizeof(struct host_cmd_ds_802_11_hs_cfg_enh)
+ S_DS_GEN);
} else {
cmd->size = cpu_to_le16(S_DS_GEN + sizeof(struct
host_cmd_ds_802_11_hs_cfg_enh));
}
if (hs_activate) {
hs_cfg->action = cpu_to_le16(HS_ACTIVATE);
hs_cfg->params.hs_activate.resp_ctrl = RESP_NEEDED;
} else {
hs_cfg->action = cpu_to_le16(HS_CONFIGURE);
hs_cfg->params.hs_config.conditions = hscfg_param->conditions;
hs_cfg->params.hs_config.gpio = hscfg_param->gpio;
hs_cfg->params.hs_config.gap = hscfg_param->gap;
dev_dbg(adapter->dev,
"cmd: HS_CFG_CMD: condition:0x%x gpio:0x%x gap:0x%x\n",
hs_cfg->params.hs_config.conditions,
hs_cfg->params.hs_config.gpio,
hs_cfg->params.hs_config.gap);
}
return 0;
}
static int mwifiex_cmd_802_11_mac_address(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action)
{
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_MAC_ADDRESS);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_mac_address) +
S_DS_GEN);
cmd->result = 0;
cmd->params.mac_addr.action = cpu_to_le16(cmd_action);
if (cmd_action == HostCmd_ACT_GEN_SET)
memcpy(cmd->params.mac_addr.mac_addr, priv->curr_addr,
ETH_ALEN);
return 0;
}
static int
mwifiex_cmd_mac_multicast_adr(struct host_cmd_ds_command *cmd,
u16 cmd_action,
struct mwifiex_multicast_list *mcast_list)
{
struct host_cmd_ds_mac_multicast_adr *mcast_addr = &cmd->params.mc_addr;
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_mac_multicast_adr) +
S_DS_GEN);
cmd->command = cpu_to_le16(HostCmd_CMD_MAC_MULTICAST_ADR);
mcast_addr->action = cpu_to_le16(cmd_action);
mcast_addr->num_of_adrs =
cpu_to_le16((u16) mcast_list->num_multicast_addr);
memcpy(mcast_addr->mac_list, mcast_list->mac_list,
mcast_list->num_multicast_addr * ETH_ALEN);
return 0;
}
static int mwifiex_cmd_802_11_deauthenticate(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u8 *mac)
{
struct host_cmd_ds_802_11_deauthenticate *deauth = &cmd->params.deauth;
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_DEAUTHENTICATE);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_deauthenticate)
+ S_DS_GEN);
memcpy(deauth->mac_addr, mac, ETH_ALEN);
dev_dbg(priv->adapter->dev, "cmd: Deauth: %pM\n", deauth->mac_addr);
deauth->reason_code = cpu_to_le16(WLAN_REASON_DEAUTH_LEAVING);
return 0;
}
static int mwifiex_cmd_802_11_ad_hoc_stop(struct host_cmd_ds_command *cmd)
{
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_AD_HOC_STOP);
cmd->size = cpu_to_le16(S_DS_GEN);
return 0;
}
static int
mwifiex_set_keyparamset_wep(struct mwifiex_private *priv,
struct mwifiex_ie_type_key_param_set *key_param_set,
u16 *key_param_len)
{
int cur_key_param_len;
u8 i;
for (i = 0; i < NUM_WEP_KEYS; i++) {
if ((priv->wep_key[i].key_length == WLAN_KEY_LEN_WEP40) ||
(priv->wep_key[i].key_length == WLAN_KEY_LEN_WEP104)) {
key_param_set->type =
cpu_to_le16(TLV_TYPE_KEY_MATERIAL);
#define KEYPARAMSET_WEP_FIXED_LEN 8
key_param_set->length = cpu_to_le16((u16)
(priv->wep_key[i].
key_length +
KEYPARAMSET_WEP_FIXED_LEN));
key_param_set->key_type_id =
cpu_to_le16(KEY_TYPE_ID_WEP);
key_param_set->key_info =
cpu_to_le16(KEY_ENABLED | KEY_UNICAST |
KEY_MCAST);
key_param_set->key_len =
cpu_to_le16(priv->wep_key[i].key_length);
key_param_set->key[0] = i;
if (i ==
(priv->
wep_key_curr_index & HostCmd_WEP_KEY_INDEX_MASK))
key_param_set->key[1] = 1;
else
key_param_set->key[1] = 0;
memmove(&key_param_set->key[2],
priv->wep_key[i].key_material,
priv->wep_key[i].key_length);
cur_key_param_len = priv->wep_key[i].key_length +
KEYPARAMSET_WEP_FIXED_LEN +
sizeof(struct mwifiex_ie_types_header);
*key_param_len += (u16) cur_key_param_len;
key_param_set =
(struct mwifiex_ie_type_key_param_set *)
((u8 *)key_param_set +
cur_key_param_len);
} else if (!priv->wep_key[i].key_length) {
continue;
} else {
dev_err(priv->adapter->dev,
"key%d Length = %d is incorrect\n",
(i + 1), priv->wep_key[i].key_length);
return -1;
}
}
return 0;
}
static int
mwifiex_cmd_802_11_key_material(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action, u32 cmd_oid,
struct mwifiex_ds_encrypt_key *enc_key)
{
struct host_cmd_ds_802_11_key_material *key_material =
&cmd->params.key_material;
struct host_cmd_tlv_mac_addr *tlv_mac;
u16 key_param_len = 0, cmd_size;
int ret = 0;
const u8 bc_mac[] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_KEY_MATERIAL);
key_material->action = cpu_to_le16(cmd_action);
if (cmd_action == HostCmd_ACT_GEN_GET) {
cmd->size =
cpu_to_le16(sizeof(key_material->action) + S_DS_GEN);
return ret;
}
if (!enc_key) {
memset(&key_material->key_param_set, 0,
(NUM_WEP_KEYS *
sizeof(struct mwifiex_ie_type_key_param_set)));
ret = mwifiex_set_keyparamset_wep(priv,
&key_material->key_param_set,
&key_param_len);
cmd->size = cpu_to_le16(key_param_len +
sizeof(key_material->action) + S_DS_GEN);
return ret;
} else
memset(&key_material->key_param_set, 0,
sizeof(struct mwifiex_ie_type_key_param_set));
if (enc_key->is_wapi_key) {
dev_dbg(priv->adapter->dev, "info: Set WAPI Key\n");
key_material->key_param_set.key_type_id =
cpu_to_le16(KEY_TYPE_ID_WAPI);
if (cmd_oid == KEY_INFO_ENABLED)
key_material->key_param_set.key_info =
cpu_to_le16(KEY_ENABLED);
else
key_material->key_param_set.key_info =
cpu_to_le16(!KEY_ENABLED);
key_material->key_param_set.key[0] = enc_key->key_index;
if (!priv->sec_info.wapi_key_on)
key_material->key_param_set.key[1] = 1;
else
key_material->key_param_set.key[1] = 0;
if (0 != memcmp(enc_key->mac_addr, bc_mac, sizeof(bc_mac))) {
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_UNICAST);
} else {
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_MCAST);
priv->sec_info.wapi_key_on = true;
}
key_material->key_param_set.type =
cpu_to_le16(TLV_TYPE_KEY_MATERIAL);
key_material->key_param_set.key_len =
cpu_to_le16(WAPI_KEY_LEN);
memcpy(&key_material->key_param_set.key[2],
enc_key->key_material, enc_key->key_len);
memcpy(&key_material->key_param_set.key[2 + enc_key->key_len],
enc_key->wapi_rxpn, WAPI_RXPN_LEN);
key_material->key_param_set.length =
cpu_to_le16(WAPI_KEY_LEN + KEYPARAMSET_FIXED_LEN);
key_param_len = (WAPI_KEY_LEN + KEYPARAMSET_FIXED_LEN) +
sizeof(struct mwifiex_ie_types_header);
cmd->size = cpu_to_le16(sizeof(key_material->action)
+ S_DS_GEN + key_param_len);
return ret;
}
if (enc_key->key_len == WLAN_KEY_LEN_CCMP) {
dev_dbg(priv->adapter->dev, "cmd: WPA_AES\n");
key_material->key_param_set.key_type_id =
cpu_to_le16(KEY_TYPE_ID_AES);
if (cmd_oid == KEY_INFO_ENABLED)
key_material->key_param_set.key_info =
cpu_to_le16(KEY_ENABLED);
else
key_material->key_param_set.key_info =
cpu_to_le16(!KEY_ENABLED);
if (enc_key->key_index & MWIFIEX_KEY_INDEX_UNICAST)
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_UNICAST);
else
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_MCAST);
} else if (enc_key->key_len == WLAN_KEY_LEN_TKIP) {
dev_dbg(priv->adapter->dev, "cmd: WPA_TKIP\n");
key_material->key_param_set.key_type_id =
cpu_to_le16(KEY_TYPE_ID_TKIP);
key_material->key_param_set.key_info =
cpu_to_le16(KEY_ENABLED);
if (enc_key->key_index & MWIFIEX_KEY_INDEX_UNICAST)
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_UNICAST);
else
key_material->key_param_set.key_info |=
cpu_to_le16(KEY_MCAST);
}
if (key_material->key_param_set.key_type_id) {
key_material->key_param_set.type =
cpu_to_le16(TLV_TYPE_KEY_MATERIAL);
key_material->key_param_set.key_len =
cpu_to_le16((u16) enc_key->key_len);
memcpy(key_material->key_param_set.key, enc_key->key_material,
enc_key->key_len);
key_material->key_param_set.length =
cpu_to_le16((u16) enc_key->key_len +
KEYPARAMSET_FIXED_LEN);
key_param_len = (u16)(enc_key->key_len + KEYPARAMSET_FIXED_LEN)
+ sizeof(struct mwifiex_ie_types_header);
cmd->size = cpu_to_le16(sizeof(key_material->action) + S_DS_GEN
+ key_param_len);
if (priv->bss_type == MWIFIEX_BSS_TYPE_UAP) {
tlv_mac = (void *)((u8 *)&key_material->key_param_set +
key_param_len);
tlv_mac->tlv.type = cpu_to_le16(TLV_TYPE_STA_MAC_ADDR);
tlv_mac->tlv.len = cpu_to_le16(ETH_ALEN);
memcpy(tlv_mac->mac_addr, enc_key->mac_addr, ETH_ALEN);
cmd_size = key_param_len + S_DS_GEN +
sizeof(key_material->action) +
sizeof(struct host_cmd_tlv_mac_addr);
} else {
cmd_size = key_param_len + S_DS_GEN +
sizeof(key_material->action);
}
cmd->size = cpu_to_le16(cmd_size);
}
return ret;
}
static int mwifiex_cmd_802_11d_domain_info(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
u16 cmd_action)
{
struct mwifiex_adapter *adapter = priv->adapter;
struct host_cmd_ds_802_11d_domain_info *domain_info =
&cmd->params.domain_info;
struct mwifiex_ietypes_domain_param_set *domain =
&domain_info->domain;
u8 no_of_triplet = adapter->domain_reg.no_of_triplet;
dev_dbg(adapter->dev, "info: 11D: no_of_triplet=0x%x\n", no_of_triplet);
cmd->command = cpu_to_le16(HostCmd_CMD_802_11D_DOMAIN_INFO);
domain_info->action = cpu_to_le16(cmd_action);
if (cmd_action == HostCmd_ACT_GEN_GET) {
cmd->size = cpu_to_le16(sizeof(domain_info->action) + S_DS_GEN);
return 0;
}
domain->header.type = cpu_to_le16(WLAN_EID_COUNTRY);
memcpy(domain->country_code, adapter->domain_reg.country_code,
sizeof(domain->country_code));
domain->header.len =
cpu_to_le16((no_of_triplet *
sizeof(struct ieee80211_country_ie_triplet))
+ sizeof(domain->country_code));
if (no_of_triplet) {
memcpy(domain->triplet, adapter->domain_reg.triplet,
no_of_triplet * sizeof(struct
ieee80211_country_ie_triplet));
cmd->size = cpu_to_le16(sizeof(domain_info->action) +
le16_to_cpu(domain->header.len) +
sizeof(struct mwifiex_ie_types_header)
+ S_DS_GEN);
} else {
cmd->size = cpu_to_le16(sizeof(domain_info->action) + S_DS_GEN);
}
return 0;
}
static int mwifiex_cmd_ibss_coalescing_status(struct host_cmd_ds_command *cmd,
u16 cmd_action, u16 *enable)
{
struct host_cmd_ds_802_11_ibss_status *ibss_coal =
&(cmd->params.ibss_coalescing);
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_IBSS_COALESCING_STATUS);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_ibss_status) +
S_DS_GEN);
cmd->result = 0;
ibss_coal->action = cpu_to_le16(cmd_action);
switch (cmd_action) {
case HostCmd_ACT_GEN_SET:
if (enable)
ibss_coal->enable = cpu_to_le16(*enable);
else
ibss_coal->enable = 0;
break;
case HostCmd_ACT_GEN_GET:
default:
break;
}
return 0;
}
static int mwifiex_cmd_reg_access(struct host_cmd_ds_command *cmd,
u16 cmd_action, void *data_buf)
{
struct mwifiex_ds_reg_rw *reg_rw = data_buf;
switch (le16_to_cpu(cmd->command)) {
case HostCmd_CMD_MAC_REG_ACCESS:
{
struct host_cmd_ds_mac_reg_access *mac_reg;
cmd->size = cpu_to_le16(sizeof(*mac_reg) + S_DS_GEN);
mac_reg = &cmd->params.mac_reg;
mac_reg->action = cpu_to_le16(cmd_action);
mac_reg->offset =
cpu_to_le16((u16) le32_to_cpu(reg_rw->offset));
mac_reg->value = reg_rw->value;
break;
}
case HostCmd_CMD_BBP_REG_ACCESS:
{
struct host_cmd_ds_bbp_reg_access *bbp_reg;
cmd->size = cpu_to_le16(sizeof(*bbp_reg) + S_DS_GEN);
bbp_reg = &cmd->params.bbp_reg;
bbp_reg->action = cpu_to_le16(cmd_action);
bbp_reg->offset =
cpu_to_le16((u16) le32_to_cpu(reg_rw->offset));
bbp_reg->value = (u8) le32_to_cpu(reg_rw->value);
break;
}
case HostCmd_CMD_RF_REG_ACCESS:
{
struct host_cmd_ds_rf_reg_access *rf_reg;
cmd->size = cpu_to_le16(sizeof(*rf_reg) + S_DS_GEN);
rf_reg = &cmd->params.rf_reg;
rf_reg->action = cpu_to_le16(cmd_action);
rf_reg->offset = cpu_to_le16((u16) le32_to_cpu(reg_rw->offset));
rf_reg->value = (u8) le32_to_cpu(reg_rw->value);
break;
}
case HostCmd_CMD_PMIC_REG_ACCESS:
{
struct host_cmd_ds_pmic_reg_access *pmic_reg;
cmd->size = cpu_to_le16(sizeof(*pmic_reg) + S_DS_GEN);
pmic_reg = &cmd->params.pmic_reg;
pmic_reg->action = cpu_to_le16(cmd_action);
pmic_reg->offset =
cpu_to_le16((u16) le32_to_cpu(reg_rw->offset));
pmic_reg->value = (u8) le32_to_cpu(reg_rw->value);
break;
}
case HostCmd_CMD_CAU_REG_ACCESS:
{
struct host_cmd_ds_rf_reg_access *cau_reg;
cmd->size = cpu_to_le16(sizeof(*cau_reg) + S_DS_GEN);
cau_reg = &cmd->params.rf_reg;
cau_reg->action = cpu_to_le16(cmd_action);
cau_reg->offset =
cpu_to_le16((u16) le32_to_cpu(reg_rw->offset));
cau_reg->value = (u8) le32_to_cpu(reg_rw->value);
break;
}
case HostCmd_CMD_802_11_EEPROM_ACCESS:
{
struct mwifiex_ds_read_eeprom *rd_eeprom = data_buf;
struct host_cmd_ds_802_11_eeprom_access *cmd_eeprom =
&cmd->params.eeprom;
cmd->size = cpu_to_le16(sizeof(*cmd_eeprom) + S_DS_GEN);
cmd_eeprom->action = cpu_to_le16(cmd_action);
cmd_eeprom->offset = rd_eeprom->offset;
cmd_eeprom->byte_count = rd_eeprom->byte_count;
cmd_eeprom->value = 0;
break;
}
default:
return -1;
}
return 0;
}
static int
mwifiex_cmd_pcie_host_spec(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd, u16 action)
{
struct host_cmd_ds_pcie_details *host_spec =
&cmd->params.pcie_host_spec;
struct pcie_service_card *card = priv->adapter->card;
phys_addr_t *buf_pa;
cmd->command = cpu_to_le16(HostCmd_CMD_PCIE_DESC_DETAILS);
cmd->size = cpu_to_le16(sizeof(struct
host_cmd_ds_pcie_details) + S_DS_GEN);
cmd->result = 0;
memset(host_spec, 0, sizeof(struct host_cmd_ds_pcie_details));
if (action != HostCmd_ACT_GEN_SET)
return 0;
host_spec->txbd_addr_lo = (u32)(card->txbd_ring_pbase);
host_spec->txbd_addr_hi = (u32)(((u64)card->txbd_ring_pbase)>>32);
host_spec->txbd_count = MWIFIEX_MAX_TXRX_BD;
host_spec->rxbd_addr_lo = (u32)(card->rxbd_ring_pbase);
host_spec->rxbd_addr_hi = (u32)(((u64)card->rxbd_ring_pbase)>>32);
host_spec->rxbd_count = MWIFIEX_MAX_TXRX_BD;
host_spec->evtbd_addr_lo = (u32)(card->evtbd_ring_pbase);
host_spec->evtbd_addr_hi = (u32)(((u64)card->evtbd_ring_pbase)>>32);
host_spec->evtbd_count = MWIFIEX_MAX_EVT_BD;
if (card->sleep_cookie) {
buf_pa = MWIFIEX_SKB_PACB(card->sleep_cookie);
host_spec->sleep_cookie_addr_lo = (u32) *buf_pa;
host_spec->sleep_cookie_addr_hi = (u32) (((u64)*buf_pa) >> 32);
dev_dbg(priv->adapter->dev, "sleep_cook_lo phy addr: 0x%x\n",
host_spec->sleep_cookie_addr_lo);
}
return 0;
}
static int
mwifiex_cmd_802_11_subsc_evt(struct mwifiex_private *priv,
struct host_cmd_ds_command *cmd,
struct mwifiex_ds_misc_subsc_evt *subsc_evt_cfg)
{
struct host_cmd_ds_802_11_subsc_evt *subsc_evt = &cmd->params.subsc_evt;
struct mwifiex_ie_types_rssi_threshold *rssi_tlv;
u16 event_bitmap;
u8 *pos;
cmd->command = cpu_to_le16(HostCmd_CMD_802_11_SUBSCRIBE_EVENT);
cmd->size = cpu_to_le16(sizeof(struct host_cmd_ds_802_11_subsc_evt) +
S_DS_GEN);
subsc_evt->action = cpu_to_le16(subsc_evt_cfg->action);
dev_dbg(priv->adapter->dev, "cmd: action: %d\n", subsc_evt_cfg->action);
if (subsc_evt_cfg->action == HostCmd_ACT_GEN_GET)
return 0;
subsc_evt->events = cpu_to_le16(subsc_evt_cfg->events);
event_bitmap = subsc_evt_cfg->events;
dev_dbg(priv->adapter->dev, "cmd: event bitmap : %16x\n",
event_bitmap);
if (((subsc_evt_cfg->action == HostCmd_ACT_BITWISE_CLR) ||
(subsc_evt_cfg->action == HostCmd_ACT_BITWISE_SET)) &&
(event_bitmap == 0)) {
dev_dbg(priv->adapter->dev, "Error: No event specified "
"for bitwise action type\n");
return -EINVAL;
}
if (subsc_evt_cfg->action == HostCmd_ACT_BITWISE_CLR)
return 0;
pos = ((u8 *)subsc_evt) +
sizeof(struct host_cmd_ds_802_11_subsc_evt);
if (event_bitmap & BITMASK_BCN_RSSI_LOW) {
rssi_tlv = (struct mwifiex_ie_types_rssi_threshold *) pos;
rssi_tlv->header.type = cpu_to_le16(TLV_TYPE_RSSI_LOW);
rssi_tlv->header.len =
cpu_to_le16(sizeof(struct mwifiex_ie_types_rssi_threshold) -
sizeof(struct mwifiex_ie_types_header));
rssi_tlv->abs_value = subsc_evt_cfg->bcn_l_rssi_cfg.abs_value;
rssi_tlv->evt_freq = subsc_evt_cfg->bcn_l_rssi_cfg.evt_freq;
dev_dbg(priv->adapter->dev, "Cfg Beacon Low Rssi event, "
"RSSI:-%d dBm, Freq:%d\n",
subsc_evt_cfg->bcn_l_rssi_cfg.abs_value,
subsc_evt_cfg->bcn_l_rssi_cfg.evt_freq);
pos += sizeof(struct mwifiex_ie_types_rssi_threshold);
le16_add_cpu(&cmd->size,
sizeof(struct mwifiex_ie_types_rssi_threshold));
}
if (event_bitmap & BITMASK_BCN_RSSI_HIGH) {
rssi_tlv = (struct mwifiex_ie_types_rssi_threshold *) pos;
rssi_tlv->header.type = cpu_to_le16(TLV_TYPE_RSSI_HIGH);
rssi_tlv->header.len =
cpu_to_le16(sizeof(struct mwifiex_ie_types_rssi_threshold) -
sizeof(struct mwifiex_ie_types_header));
rssi_tlv->abs_value = subsc_evt_cfg->bcn_h_rssi_cfg.abs_value;
rssi_tlv->evt_freq = subsc_evt_cfg->bcn_h_rssi_cfg.evt_freq;
dev_dbg(priv->adapter->dev, "Cfg Beacon High Rssi event, "
"RSSI:-%d dBm, Freq:%d\n",
subsc_evt_cfg->bcn_h_rssi_cfg.abs_value,
subsc_evt_cfg->bcn_h_rssi_cfg.evt_freq);
pos += sizeof(struct mwifiex_ie_types_rssi_threshold);
le16_add_cpu(&cmd->size,
sizeof(struct mwifiex_ie_types_rssi_threshold));
}
return 0;
}
int mwifiex_sta_prepare_cmd(struct mwifiex_private *priv, uint16_t cmd_no,
u16 cmd_action, u32 cmd_oid,
void *data_buf, void *cmd_buf)
{
struct host_cmd_ds_command *cmd_ptr = cmd_buf;
int ret = 0;
switch (cmd_no) {
case HostCmd_CMD_GET_HW_SPEC:
ret = mwifiex_cmd_get_hw_spec(priv, cmd_ptr);
break;
case HostCmd_CMD_MAC_CONTROL:
ret = mwifiex_cmd_mac_control(priv, cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_802_11_MAC_ADDRESS:
ret = mwifiex_cmd_802_11_mac_address(priv, cmd_ptr,
cmd_action);
break;
case HostCmd_CMD_MAC_MULTICAST_ADR:
ret = mwifiex_cmd_mac_multicast_adr(cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_TX_RATE_CFG:
ret = mwifiex_cmd_tx_rate_cfg(priv, cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_TXPWR_CFG:
ret = mwifiex_cmd_tx_power_cfg(cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_RF_TX_PWR:
ret = mwifiex_cmd_rf_tx_power(priv, cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_RF_ANTENNA:
ret = mwifiex_cmd_rf_antenna(priv, cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_802_11_PS_MODE_ENH:
ret = mwifiex_cmd_enh_power_mode(priv, cmd_ptr, cmd_action,
(uint16_t)cmd_oid, data_buf);
break;
case HostCmd_CMD_802_11_HS_CFG_ENH:
ret = mwifiex_cmd_802_11_hs_cfg(priv, cmd_ptr, cmd_action,
(struct mwifiex_hs_config_param *) data_buf);
break;
case HostCmd_CMD_802_11_SCAN:
ret = mwifiex_cmd_802_11_scan(cmd_ptr, data_buf);
break;
case HostCmd_CMD_802_11_BG_SCAN_QUERY:
ret = mwifiex_cmd_802_11_bg_scan_query(cmd_ptr);
break;
case HostCmd_CMD_802_11_ASSOCIATE:
ret = mwifiex_cmd_802_11_associate(priv, cmd_ptr, data_buf);
break;
case HostCmd_CMD_802_11_DEAUTHENTICATE:
ret = mwifiex_cmd_802_11_deauthenticate(priv, cmd_ptr,
data_buf);
break;
case HostCmd_CMD_802_11_AD_HOC_START:
ret = mwifiex_cmd_802_11_ad_hoc_start(priv, cmd_ptr,
data_buf);
break;
case HostCmd_CMD_802_11_GET_LOG:
ret = mwifiex_cmd_802_11_get_log(cmd_ptr);
break;
case HostCmd_CMD_802_11_AD_HOC_JOIN:
ret = mwifiex_cmd_802_11_ad_hoc_join(priv, cmd_ptr,
data_buf);
break;
case HostCmd_CMD_802_11_AD_HOC_STOP:
ret = mwifiex_cmd_802_11_ad_hoc_stop(cmd_ptr);
break;
case HostCmd_CMD_RSSI_INFO:
ret = mwifiex_cmd_802_11_rssi_info(priv, cmd_ptr, cmd_action);
break;
case HostCmd_CMD_802_11_SNMP_MIB:
ret = mwifiex_cmd_802_11_snmp_mib(priv, cmd_ptr, cmd_action,
cmd_oid, data_buf);
break;
case HostCmd_CMD_802_11_TX_RATE_QUERY:
cmd_ptr->command =
cpu_to_le16(HostCmd_CMD_802_11_TX_RATE_QUERY);
cmd_ptr->size =
cpu_to_le16(sizeof(struct host_cmd_ds_tx_rate_query) +
S_DS_GEN);
priv->tx_rate = 0;
ret = 0;
break;
case HostCmd_CMD_VERSION_EXT:
cmd_ptr->command = cpu_to_le16(cmd_no);
cmd_ptr->params.verext.version_str_sel =
(u8) (*((u32 *) data_buf));
memcpy(&cmd_ptr->params, data_buf,
sizeof(struct host_cmd_ds_version_ext));
cmd_ptr->size =
cpu_to_le16(sizeof(struct host_cmd_ds_version_ext) +
S_DS_GEN);
ret = 0;
break;
case HostCmd_CMD_FUNC_INIT:
if (priv->adapter->hw_status == MWIFIEX_HW_STATUS_RESET)
priv->adapter->hw_status = MWIFIEX_HW_STATUS_READY;
cmd_ptr->command = cpu_to_le16(cmd_no);
cmd_ptr->size = cpu_to_le16(S_DS_GEN);
break;
case HostCmd_CMD_FUNC_SHUTDOWN:
priv->adapter->hw_status = MWIFIEX_HW_STATUS_RESET;
cmd_ptr->command = cpu_to_le16(cmd_no);
cmd_ptr->size = cpu_to_le16(S_DS_GEN);
break;
case HostCmd_CMD_11N_ADDBA_REQ:
ret = mwifiex_cmd_11n_addba_req(cmd_ptr, data_buf);
break;
case HostCmd_CMD_11N_DELBA:
ret = mwifiex_cmd_11n_delba(cmd_ptr, data_buf);
break;
case HostCmd_CMD_11N_ADDBA_RSP:
ret = mwifiex_cmd_11n_addba_rsp_gen(priv, cmd_ptr, data_buf);
break;
case HostCmd_CMD_802_11_KEY_MATERIAL:
ret = mwifiex_cmd_802_11_key_material(priv, cmd_ptr,
cmd_action, cmd_oid,
data_buf);
break;
case HostCmd_CMD_802_11D_DOMAIN_INFO:
ret = mwifiex_cmd_802_11d_domain_info(priv, cmd_ptr,
cmd_action);
break;
case HostCmd_CMD_RECONFIGURE_TX_BUFF:
ret = mwifiex_cmd_recfg_tx_buf(priv, cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_AMSDU_AGGR_CTRL:
ret = mwifiex_cmd_amsdu_aggr_ctrl(cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_11N_CFG:
ret = mwifiex_cmd_11n_cfg(cmd_ptr, cmd_action, data_buf);
break;
case HostCmd_CMD_WMM_GET_STATUS:
dev_dbg(priv->adapter->dev,
"cmd: WMM: WMM_GET_STATUS cmd sent\n");
cmd_ptr->command = cpu_to_le16(HostCmd_CMD_WMM_GET_STATUS);
cmd_ptr->size =
cpu_to_le16(sizeof(struct host_cmd_ds_wmm_get_status) +
S_DS_GEN);
ret = 0;
break;
case HostCmd_CMD_802_11_IBSS_COALESCING_STATUS:
ret = mwifiex_cmd_ibss_coalescing_status(cmd_ptr, cmd_action,
data_buf);
break;
case HostCmd_CMD_MAC_REG_ACCESS:
case HostCmd_CMD_BBP_REG_ACCESS:
case HostCmd_CMD_RF_REG_ACCESS:
case HostCmd_CMD_PMIC_REG_ACCESS:
case HostCmd_CMD_CAU_REG_ACCESS:
case HostCmd_CMD_802_11_EEPROM_ACCESS:
ret = mwifiex_cmd_reg_access(cmd_ptr, cmd_action, data_buf);
break;
case HostCmd_CMD_SET_BSS_MODE:
cmd_ptr->command = cpu_to_le16(cmd_no);
if (priv->bss_mode == NL80211_IFTYPE_ADHOC)
cmd_ptr->params.bss_mode.con_type =
CONNECTION_TYPE_ADHOC;
else if (priv->bss_mode == NL80211_IFTYPE_STATION)
cmd_ptr->params.bss_mode.con_type =
CONNECTION_TYPE_INFRA;
cmd_ptr->size = cpu_to_le16(sizeof(struct
host_cmd_ds_set_bss_mode) + S_DS_GEN);
ret = 0;
break;
case HostCmd_CMD_PCIE_DESC_DETAILS:
ret = mwifiex_cmd_pcie_host_spec(priv, cmd_ptr, cmd_action);
break;
case HostCmd_CMD_802_11_SUBSCRIBE_EVENT:
ret = mwifiex_cmd_802_11_subsc_evt(priv, cmd_ptr, data_buf);
break;
default:
dev_err(priv->adapter->dev,
"PREP_CMD: unknown cmd- %#x\n", cmd_no);
ret = -1;
break;
}
return ret;
}
int mwifiex_sta_init_cmd(struct mwifiex_private *priv, u8 first_sta)
{
int ret;
u16 enable = true;
struct mwifiex_ds_11n_amsdu_aggr_ctrl amsdu_aggr_ctrl;
struct mwifiex_ds_auto_ds auto_ds;
enum state_11d_t state_11d;
struct mwifiex_ds_11n_tx_cfg tx_cfg;
if (first_sta) {
if (priv->adapter->iface_type == MWIFIEX_PCIE) {
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_PCIE_DESC_DETAILS,
HostCmd_ACT_GEN_SET, 0, NULL);
if (ret)
return -1;
}
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_FUNC_INIT,
HostCmd_ACT_GEN_SET, 0, NULL);
if (ret)
return -1;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_GET_HW_SPEC,
HostCmd_ACT_GEN_GET, 0, NULL);
if (ret)
return -1;
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_RECONFIGURE_TX_BUFF,
HostCmd_ACT_GEN_SET, 0,
&priv->adapter->tx_buf_size);
if (ret)
return -1;
if (priv->bss_type != MWIFIEX_BSS_TYPE_UAP) {
priv->adapter->ps_mode = MWIFIEX_802_11_POWER_MODE_PSP;
ret = mwifiex_send_cmd_async(
priv, HostCmd_CMD_802_11_PS_MODE_ENH,
EN_AUTO_PS, BITMAP_STA_PS, NULL);
if (ret)
return -1;
}
}
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_TX_RATE_CFG,
HostCmd_ACT_GEN_GET, 0, NULL);
if (ret)
return -1;
priv->data_rate = 0;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_RF_TX_PWR,
HostCmd_ACT_GEN_GET, 0, NULL);
if (ret)
return -1;
if (priv->bss_type == MWIFIEX_BSS_TYPE_STA) {
ret = mwifiex_send_cmd_async(
priv, HostCmd_CMD_802_11_IBSS_COALESCING_STATUS,
HostCmd_ACT_GEN_SET, 0, &enable);
if (ret)
return -1;
}
memset(&amsdu_aggr_ctrl, 0, sizeof(amsdu_aggr_ctrl));
amsdu_aggr_ctrl.enable = true;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_AMSDU_AGGR_CTRL,
HostCmd_ACT_GEN_SET, 0,
&amsdu_aggr_ctrl);
if (ret)
return -1;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_MAC_CONTROL,
HostCmd_ACT_GEN_SET, 0,
&priv->curr_pkt_filter);
if (ret)
return -1;
if (first_sta && priv->adapter->iface_type != MWIFIEX_USB &&
priv->bss_type != MWIFIEX_BSS_TYPE_UAP) {
auto_ds.auto_ds = DEEP_SLEEP_ON;
auto_ds.idle_time = DEEP_SLEEP_IDLE_TIME;
ret = mwifiex_send_cmd_async(priv,
HostCmd_CMD_802_11_PS_MODE_ENH,
EN_AUTO_PS, BITMAP_AUTO_DS,
&auto_ds);
if (ret)
return -1;
}
if (priv->bss_type != MWIFIEX_BSS_TYPE_UAP) {
state_11d = ENABLE_11D;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_802_11_SNMP_MIB,
HostCmd_ACT_GEN_SET, DOT11D_I,
&state_11d);
if (ret)
dev_err(priv->adapter->dev,
"11D: failed to enable 11D\n");
}
tx_cfg.tx_htcap = MWIFIEX_FW_DEF_HTTXCFG;
ret = mwifiex_send_cmd_async(priv, HostCmd_CMD_11N_CFG,
HostCmd_ACT_GEN_SET, 0, &tx_cfg);
priv->adapter->last_init_cmd = HostCmd_CMD_11N_CFG;
ret = -EINPROGRESS;
return ret;
}
