static void __check_vhtcap_disable(struct ieee80211_sub_if_data *sdata,
struct ieee80211_sta_vht_cap *vht_cap,
u32 flag)
{
__le32 le_flag = cpu_to_le32(flag);
if (sdata->u.mgd.vht_capa_mask.vht_cap_info & le_flag &&
!(sdata->u.mgd.vht_capa.vht_cap_info & le_flag))
vht_cap->cap &= ~flag;
}
void ieee80211_apply_vhtcap_overrides(struct ieee80211_sub_if_data *sdata,
struct ieee80211_sta_vht_cap *vht_cap)
{
int i;
u16 rxmcs_mask, rxmcs_cap, rxmcs_n, txmcs_mask, txmcs_cap, txmcs_n;
if (!vht_cap->vht_supported)
return;
if (sdata->vif.type != NL80211_IFTYPE_STATION)
return;
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_RXLDPC);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_SHORT_GI_80);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_SHORT_GI_160);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_TXSTBC);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_RX_ANTENNA_PATTERN);
__check_vhtcap_disable(sdata, vht_cap,
IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN);
if (sdata->u.mgd.vht_capa_mask.vht_cap_info &
cpu_to_le32(IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK)) {
u32 cap, n;
n = le32_to_cpu(sdata->u.mgd.vht_capa.vht_cap_info) &
IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK;
n >>= IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;
cap = vht_cap->cap & IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK;
cap >>= IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;
if (n < cap) {
vht_cap->cap &=
~IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK;
vht_cap->cap |=
n << IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_SHIFT;
}
}
rxmcs_mask =
le16_to_cpu(sdata->u.mgd.vht_capa_mask.supp_mcs.rx_mcs_map);
rxmcs_n = le16_to_cpu(sdata->u.mgd.vht_capa.supp_mcs.rx_mcs_map);
rxmcs_n &= rxmcs_mask;
rxmcs_cap = le16_to_cpu(vht_cap->vht_mcs.rx_mcs_map);
txmcs_mask =
le16_to_cpu(sdata->u.mgd.vht_capa_mask.supp_mcs.tx_mcs_map);
txmcs_n = le16_to_cpu(sdata->u.mgd.vht_capa.supp_mcs.tx_mcs_map);
txmcs_n &= txmcs_mask;
txmcs_cap = le16_to_cpu(vht_cap->vht_mcs.tx_mcs_map);
for (i = 0; i < 8; i++) {
u8 m, n, c;
m = (rxmcs_mask >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
n = (rxmcs_n >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
c = (rxmcs_cap >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
if (m && ((c != IEEE80211_VHT_MCS_NOT_SUPPORTED && n < c) ||
n == IEEE80211_VHT_MCS_NOT_SUPPORTED)) {
rxmcs_cap &= ~(3 << 2*i);
rxmcs_cap |= (rxmcs_n & (3 << 2*i));
}
m = (txmcs_mask >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
n = (txmcs_n >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
c = (txmcs_cap >> 2*i) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
if (m && ((c != IEEE80211_VHT_MCS_NOT_SUPPORTED && n < c) ||
n == IEEE80211_VHT_MCS_NOT_SUPPORTED)) {
txmcs_cap &= ~(3 << 2*i);
txmcs_cap |= (txmcs_n & (3 << 2*i));
}
}
vht_cap->vht_mcs.rx_mcs_map = cpu_to_le16(rxmcs_cap);
vht_cap->vht_mcs.tx_mcs_map = cpu_to_le16(txmcs_cap);
}
void
ieee80211_vht_cap_ie_to_sta_vht_cap(struct ieee80211_sub_if_data *sdata,
struct ieee80211_supported_band *sband,
const struct ieee80211_vht_cap *vht_cap_ie,
struct sta_info *sta)
{
struct ieee80211_sta_vht_cap *vht_cap = &sta->sta.vht_cap;
struct ieee80211_sta_vht_cap own_cap;
u32 cap_info, i;
memset(vht_cap, 0, sizeof(*vht_cap));
if (!sta->sta.ht_cap.ht_supported)
return;
if (!vht_cap_ie || !sband->vht_cap.vht_supported)
return;
if (test_sta_flag(sta, WLAN_STA_TDLS_PEER))
return;
vht_cap->vht_supported = true;
own_cap = sband->vht_cap;
if (sdata->vif.type == NL80211_IFTYPE_STATION &&
!test_sta_flag(sta, WLAN_STA_TDLS_PEER))
ieee80211_apply_vhtcap_overrides(sdata, &own_cap);
cap_info = le32_to_cpu(vht_cap_ie->vht_cap_info);
vht_cap->cap = cap_info;
vht_cap->cap &= IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_3895 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_7991 |
IEEE80211_VHT_CAP_MAX_MPDU_LENGTH_11454 |
IEEE80211_VHT_CAP_RXLDPC |
IEEE80211_VHT_CAP_VHT_TXOP_PS |
IEEE80211_VHT_CAP_HTC_VHT |
IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK |
IEEE80211_VHT_CAP_VHT_LINK_ADAPTATION_VHT_UNSOL_MFB |
IEEE80211_VHT_CAP_VHT_LINK_ADAPTATION_VHT_MRQ_MFB |
IEEE80211_VHT_CAP_RX_ANTENNA_PATTERN |
IEEE80211_VHT_CAP_TX_ANTENNA_PATTERN;
switch (own_cap.cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK) {
case IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ:
vht_cap->cap |= cap_info &
IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ;
break;
case IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160_80PLUS80MHZ:
vht_cap->cap |= cap_info &
IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK;
break;
default:
break;
}
vht_cap->cap |= cap_info & own_cap.cap &
(IEEE80211_VHT_CAP_SHORT_GI_80 |
IEEE80211_VHT_CAP_SHORT_GI_160);
if (own_cap.cap & IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE)
vht_cap->cap |= cap_info &
(IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE |
IEEE80211_VHT_CAP_SOUNDING_DIMENSIONS_MASK);
if (own_cap.cap & IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE)
vht_cap->cap |= cap_info &
(IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
IEEE80211_VHT_CAP_BEAMFORMEE_STS_MASK);
if (own_cap.cap & IEEE80211_VHT_CAP_MU_BEAMFORMER_CAPABLE)
vht_cap->cap |= cap_info &
IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE;
if (own_cap.cap & IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE)
vht_cap->cap |= cap_info &
IEEE80211_VHT_CAP_MU_BEAMFORMER_CAPABLE;
if (own_cap.cap & IEEE80211_VHT_CAP_TXSTBC)
vht_cap->cap |= cap_info & IEEE80211_VHT_CAP_RXSTBC_MASK;
if (own_cap.cap & IEEE80211_VHT_CAP_RXSTBC_MASK)
vht_cap->cap |= cap_info & IEEE80211_VHT_CAP_TXSTBC;
memcpy(&vht_cap->vht_mcs, &vht_cap_ie->supp_mcs,
sizeof(struct ieee80211_vht_mcs_info));
for (i = 0; i < 8; i++) {
u16 own_rx, own_tx, peer_rx, peer_tx;
own_rx = le16_to_cpu(own_cap.vht_mcs.rx_mcs_map);
own_rx = (own_rx >> i * 2) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
own_tx = le16_to_cpu(own_cap.vht_mcs.tx_mcs_map);
own_tx = (own_tx >> i * 2) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
peer_rx = le16_to_cpu(vht_cap->vht_mcs.rx_mcs_map);
peer_rx = (peer_rx >> i * 2) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
peer_tx = le16_to_cpu(vht_cap->vht_mcs.tx_mcs_map);
peer_tx = (peer_tx >> i * 2) & IEEE80211_VHT_MCS_NOT_SUPPORTED;
if (peer_tx != IEEE80211_VHT_MCS_NOT_SUPPORTED) {
if (own_rx == IEEE80211_VHT_MCS_NOT_SUPPORTED)
peer_tx = IEEE80211_VHT_MCS_NOT_SUPPORTED;
else if (own_rx < peer_tx)
peer_tx = own_rx;
}
if (peer_rx != IEEE80211_VHT_MCS_NOT_SUPPORTED) {
if (own_tx == IEEE80211_VHT_MCS_NOT_SUPPORTED)
peer_rx = IEEE80211_VHT_MCS_NOT_SUPPORTED;
else if (own_tx < peer_rx)
peer_rx = own_tx;
}
vht_cap->vht_mcs.rx_mcs_map &=
~cpu_to_le16(IEEE80211_VHT_MCS_NOT_SUPPORTED << i * 2);
vht_cap->vht_mcs.rx_mcs_map |= cpu_to_le16(peer_rx << i * 2);
vht_cap->vht_mcs.tx_mcs_map &=
~cpu_to_le16(IEEE80211_VHT_MCS_NOT_SUPPORTED << i * 2);
vht_cap->vht_mcs.tx_mcs_map |= cpu_to_le16(peer_tx << i * 2);
}
switch (vht_cap->cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK) {
case IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ:
case IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160_80PLUS80MHZ:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_160;
break;
default:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_80;
}
sta->sta.bandwidth = ieee80211_sta_cur_vht_bw(sta);
}
enum ieee80211_sta_rx_bandwidth ieee80211_sta_cur_vht_bw(struct sta_info *sta)
{
struct ieee80211_sub_if_data *sdata = sta->sdata;
u32 cap = sta->sta.vht_cap.cap;
enum ieee80211_sta_rx_bandwidth bw;
if (!sta->sta.vht_cap.vht_supported) {
bw = sta->sta.ht_cap.cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40 ?
IEEE80211_STA_RX_BW_40 : IEEE80211_STA_RX_BW_20;
goto check_max;
}
switch (sdata->vif.bss_conf.chandef.width) {
default:
WARN_ON_ONCE(1);
case NL80211_CHAN_WIDTH_20_NOHT:
case NL80211_CHAN_WIDTH_20:
bw = IEEE80211_STA_RX_BW_20;
break;
case NL80211_CHAN_WIDTH_40:
bw = sta->sta.ht_cap.cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40 ?
IEEE80211_STA_RX_BW_40 : IEEE80211_STA_RX_BW_20;
break;
case NL80211_CHAN_WIDTH_160:
if ((cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK) ==
IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160MHZ) {
bw = IEEE80211_STA_RX_BW_160;
break;
}
case NL80211_CHAN_WIDTH_80P80:
if ((cap & IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_MASK) ==
IEEE80211_VHT_CAP_SUPP_CHAN_WIDTH_160_80PLUS80MHZ) {
bw = IEEE80211_STA_RX_BW_160;
break;
}
case NL80211_CHAN_WIDTH_80:
bw = IEEE80211_STA_RX_BW_80;
}
check_max:
if (bw > sta->cur_max_bandwidth)
bw = sta->cur_max_bandwidth;
return bw;
}
void ieee80211_sta_set_rx_nss(struct sta_info *sta)
{
u8 ht_rx_nss = 0, vht_rx_nss = 0;
if (sta->sta.rx_nss)
return;
if (sta->sta.ht_cap.ht_supported) {
if (sta->sta.ht_cap.mcs.rx_mask[0])
ht_rx_nss++;
if (sta->sta.ht_cap.mcs.rx_mask[1])
ht_rx_nss++;
if (sta->sta.ht_cap.mcs.rx_mask[2])
ht_rx_nss++;
if (sta->sta.ht_cap.mcs.rx_mask[3])
ht_rx_nss++;
}
if (sta->sta.vht_cap.vht_supported) {
int i;
u16 rx_mcs_map;
rx_mcs_map = le16_to_cpu(sta->sta.vht_cap.vht_mcs.rx_mcs_map);
for (i = 7; i >= 0; i--) {
u8 mcs = (rx_mcs_map >> (2 * i)) & 3;
if (mcs != IEEE80211_VHT_MCS_NOT_SUPPORTED) {
vht_rx_nss = i + 1;
break;
}
}
}
ht_rx_nss = max(ht_rx_nss, vht_rx_nss);
sta->sta.rx_nss = max_t(u8, 1, ht_rx_nss);
}
u32 __ieee80211_vht_handle_opmode(struct ieee80211_sub_if_data *sdata,
struct sta_info *sta, u8 opmode,
enum ieee80211_band band, bool nss_only)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_supported_band *sband;
enum ieee80211_sta_rx_bandwidth new_bw;
u32 changed = 0;
u8 nss;
sband = local->hw.wiphy->bands[band];
if (opmode & IEEE80211_OPMODE_NOTIF_RX_NSS_TYPE_BF)
return 0;
nss = opmode & IEEE80211_OPMODE_NOTIF_RX_NSS_MASK;
nss >>= IEEE80211_OPMODE_NOTIF_RX_NSS_SHIFT;
nss += 1;
if (sta->sta.rx_nss != nss) {
sta->sta.rx_nss = nss;
changed |= IEEE80211_RC_NSS_CHANGED;
}
if (nss_only)
return changed;
switch (opmode & IEEE80211_OPMODE_NOTIF_CHANWIDTH_MASK) {
case IEEE80211_OPMODE_NOTIF_CHANWIDTH_20MHZ:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_20;
break;
case IEEE80211_OPMODE_NOTIF_CHANWIDTH_40MHZ:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_40;
break;
case IEEE80211_OPMODE_NOTIF_CHANWIDTH_80MHZ:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_80;
break;
case IEEE80211_OPMODE_NOTIF_CHANWIDTH_160MHZ:
sta->cur_max_bandwidth = IEEE80211_STA_RX_BW_160;
break;
}
new_bw = ieee80211_sta_cur_vht_bw(sta);
if (new_bw != sta->sta.bandwidth) {
sta->sta.bandwidth = new_bw;
changed |= IEEE80211_RC_BW_CHANGED;
}
return changed;
}
void ieee80211_vht_handle_opmode(struct ieee80211_sub_if_data *sdata,
struct sta_info *sta, u8 opmode,
enum ieee80211_band band, bool nss_only)
{
struct ieee80211_local *local = sdata->local;
struct ieee80211_supported_band *sband = local->hw.wiphy->bands[band];
u32 changed = __ieee80211_vht_handle_opmode(sdata, sta, opmode,
band, nss_only);
if (changed > 0)
rate_control_rate_update(local, sband, sta, changed);
}
