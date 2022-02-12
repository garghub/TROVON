static void
prism_rate_base_custom(gchar *result, guint32 rate)
{
g_snprintf(result, ITEM_LABEL_LENGTH, "%u.%u", rate /2, rate & 1 ? 5 : 0);
}
static gchar *
prism_rate_return(guint32 rate)
{
gchar *result=NULL;
result = (gchar *)wmem_alloc(wmem_packet_scope(), SHORT_STR);
result[0] = '\0';
prism_rate_base_custom(result, rate);
return result;
}
static gchar *
prism_rate_return_sig(guint32 rate_phy1, guint32 rate_phy2, struct ieee_802_11_phdr *phdr)
{
gchar *result = NULL;
unsigned int mcs, base, pream_type, disp_rate, bw, sgi, ldpc, stbc, groupid, txbf;
gboolean su_ppdu = FALSE;
unsigned int partial_aid, nsts_u1, nsts_u2, nsts_u3, nsts_u4;
unsigned int sig_a_1, sig_a_2, nss = 1, nsts_su, signal_type;
unsigned int cck_tbl[] = {22, 11, 4, 2};
static const unsigned int bw_map[] = { 0, 1, 4, 11 };
pream_type = rate_phy1 & 0xF;
switch (pream_type) {
case 0:
phdr->phy = PHDR_802_11_PHY_11A;
mcs = (rate_phy1 >> 4) & 0xF;
base = (mcs & 0x4) ? 9 : 6;
mcs &= ~0x4;
mcs = base << (11 - mcs);
mcs = (mcs > 54) ? 54 : mcs;
phdr->has_data_rate = 1;
phdr->data_rate = mcs * 2;
signal_type = rate_phy1 & (1 << 12);
bw = 20 << ((rate_phy1 >> 13) & 0x3);
result = wmem_strdup_printf(wmem_packet_scope(),
"Rate: OFDM %u.%u Mb/s Signaling:%s BW %d",
mcs, 0, signal_type ? "Dynamic" : "Static", bw
);
break;
case 1:
phdr->phy = PHDR_802_11_PHY_11B;
mcs = (rate_phy1 >> 4) & 0xF;
base = (mcs & 0x4) ? 1 : 0;
phdr->phy_info.info_11b.has_short_preamble = 1;
phdr->phy_info.info_11b.short_preamble = base;
mcs &= ~0x4;
mcs = (mcs - 8) & 0x3;
disp_rate = cck_tbl[mcs];
phdr->has_data_rate = 1;
phdr->data_rate = disp_rate;
result = wmem_strdup_printf(wmem_packet_scope(), "Rate: %u.%u Mb/s %s",
disp_rate / 2,
(disp_rate & 1) ? 5 : 0,
base ? "[SP]" : "[LP]");
break;
case 2:
phdr->phy = PHDR_802_11_PHY_11N;
sig_a_1 = (rate_phy1 >> 4) & 0xFFFF;
sig_a_2 = (rate_phy2) & 0xFFF;
mcs = sig_a_1 & 0x7f;
phdr->phy_info.info_11n.has_mcs_index = 1;
phdr->phy_info.info_11n.mcs_index = mcs;
bw = 20 << ((sig_a_1 >> 7) & 1);
phdr->phy_info.info_11n.has_bandwidth = 1;
phdr->phy_info.info_11n.bandwidth = ((sig_a_1 >> 7) & 1);
sgi = (sig_a_2 >> 7) & 1;
phdr->phy_info.info_11n.has_short_gi = 1;
phdr->phy_info.info_11n.short_gi = sgi;
ldpc = (sig_a_2 >> 6) & 1;
phdr->phy_info.info_11n.has_fec = 1;
phdr->phy_info.info_11n.fec = ldpc;
stbc = ((sig_a_2 >> 4) & 3)?1:0;
phdr->phy_info.info_11n.has_stbc_streams = 1;
phdr->phy_info.info_11n.stbc_streams = stbc;
phdr->phy_info.info_11n.has_ness = 1;
phdr->phy_info.info_11n.ness = (sig_a_2 >> 8) & 3;
nss = (mcs >> 3) + 1;
disp_rate = 0;
if ((nss <= 4) && (mcs <= 31) && ((bw == 20) || (bw==40))){
switch (bw) {
case 20:
if (sgi) {
disp_rate = ht_20_tbl[mcs][1];
} else {
disp_rate = ht_20_tbl[mcs][0];
}
break;
case 40:
if (sgi) {
disp_rate = ht_40_tbl[mcs][1];
} else {
disp_rate = ht_40_tbl[mcs][0];
}
break;
}
}
result = wmem_strdup_printf(wmem_packet_scope(),
"%u.%u Mb/s HT MCS %d NSS %d BW %d MHz %s %s %s",
disp_rate/10, disp_rate%10, mcs, nss, bw,
sgi ? "[SGI]" : "",
ldpc ? "[LDPC]" : "",
stbc ? "[STBC]" : "");
break;
case 3:
phdr->phy = PHDR_802_11_PHY_11AC;
sig_a_1 = (rate_phy1 >> 4) & 0xFFFFFF;
sig_a_2 = (rate_phy2) & 0xFFFFFF;
stbc = (sig_a_1 >> 3) & 1;
phdr->phy_info.info_11ac.has_stbc = 1;
phdr->phy_info.info_11ac.stbc = stbc;
sgi = sig_a_2 & 1;
phdr->phy_info.info_11ac.has_short_gi = 1;
phdr->phy_info.info_11ac.short_gi = sgi;
bw = 20 << (sig_a_1 & 3);
phdr->phy_info.info_11ac.has_bandwidth = 1;
phdr->phy_info.info_11ac.bandwidth = bw_map[(sig_a_1 & 3)];
ldpc = (sig_a_2 >> 2) & 1;
phdr->phy_info.info_11ac.has_fec = 1;
phdr->phy_info.info_11ac.fec = ldpc;
groupid = (sig_a_1 >> 4) & 0x3F;
phdr->phy_info.info_11ac.has_group_id = 1;
phdr->phy_info.info_11ac.group_id = groupid;
if (groupid == 0 || groupid == 63)
su_ppdu = TRUE;
disp_rate = 0;
if (su_ppdu) {
nsts_su = (sig_a_1 >> 10) & 0x7;
if (stbc)
nss = nsts_su >> 2;
else
nss = nsts_su;
++nss;
mcs = (sig_a_2 >> 4) & 0xF;
phdr->phy_info.info_11ac.mcs[0] = mcs;
phdr->phy_info.info_11ac.nss[0] = nss;
txbf = (sig_a_2 >> 8) & 1;
phdr->phy_info.info_11ac.has_beamformed = 1;
phdr->phy_info.info_11ac.beamformed = txbf;
partial_aid = (sig_a_1 >> 13) & 0x1FF;
phdr->phy_info.info_11ac.has_partial_aid = 1;
phdr->phy_info.info_11ac.partial_aid = partial_aid;
if ((nss <= 4) && (mcs <= 9) && ((bw == 20) || (bw==40) || (bw==80) || bw==160)) {
switch (bw) {
case 20:
if (sgi) {
disp_rate = vht_20_tbl[mcs][(nss * 2) - 1];
} else {
disp_rate = vht_20_tbl[mcs][(nss - 1) * 2];
}
break;
case 40:
if (sgi) {
disp_rate = vht_40_tbl[mcs][(nss * 2) - 1];
} else {
disp_rate = vht_40_tbl[mcs][(nss - 1) * 2];
}
break;
case 80:
if (sgi) {
disp_rate = vht_80_tbl[mcs][(nss * 2) - 1];
} else {
disp_rate = vht_80_tbl[mcs][(nss - 1) * 2];
}
break;
case 160:
if (sgi) {
disp_rate = vht_160_tbl[mcs][(nss * 2) - 1];
} else {
disp_rate = vht_160_tbl[mcs][(nss - 1) * 2];
}
break;
}
}
result = wmem_strdup_printf(wmem_packet_scope(),
"%u.%u Mb/s VHT MCS %d NSS %d Partial AID %d BW %d MHz %s %s %s GroupID %d %s %s",
disp_rate/10, disp_rate%10,
mcs, nss, partial_aid, bw,
sgi ? "[SGI]" : "",
ldpc ? "[LDPC]" : "",
stbc ? "[STBC]" : "",
groupid,
"[SU_PPDU]",
txbf ? "[TxBF]" : "");
} else {
nsts_u1 = (sig_a_1 >> 10) & 0x7;
nsts_u2 = (sig_a_1 >> 13) & 0x7;
nsts_u3 = (sig_a_1 >> 16) & 0x7;
nsts_u4 = (sig_a_1 >> 19) & 0x7;
result = wmem_strdup_printf(wmem_packet_scope(),
"VHT NSTS %d %d %d %d BW %d MHz %s %s %s GroupID %d %s",
nsts_u1, nsts_u2, nsts_u3, nsts_u4, bw,
sgi ? "[SGI]" : "",
ldpc ? "[LDPC]" : "",
stbc ? "[STBC]" : "",
groupid,
"[MU_PPDU]");
}
break;
}
return result;
}
static gboolean
capture_prism(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
guint32 cookie;
if (!BYTES_ARE_IN_FRAME(offset, len, 4))
return FALSE;
cookie = pntoh32(pd);
if ((cookie == WLANCAP_MAGIC_COOKIE_V1) ||
(cookie == WLANCAP_MAGIC_COOKIE_V2)) {
return call_capture_dissector(wlancap_cap_handle, pd, offset, len, cpinfo, pseudo_header);
}
if (!BYTES_ARE_IN_FRAME(offset, len, PRISM_HEADER_LENGTH))
return FALSE;
offset += PRISM_HEADER_LENGTH;
return call_capture_dissector(ieee80211_cap_handle, pd, offset, len, cpinfo, pseudo_header);
}
static int
dissect_prism(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *prism_tree, *prism_did_tree = NULL;
proto_item *ti = NULL, *ti_did = NULL;
tvbuff_t *next_tvb;
int offset;
guint32 msgcode, msglen, did, rate_phy1 = 0, rate_phy2 = 0;
guint byte_order;
guint16 status;
const guint8 *devname_p;
guint32 mactime;
guint32 channel;
guint32 signal_dbm;
guint32 rate;
struct ieee_802_11_phdr phdr;
offset = 0;
did = 0;
msgcode = tvb_get_ntohl(tvb, offset);
if ((msgcode == WLANCAP_MAGIC_COOKIE_V1) ||
(msgcode == WLANCAP_MAGIC_COOKIE_V2)) {
call_dissector(wlancap_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
if ((msgcode == PRISM_TYPE1_MSGCODE) || (msgcode == PRISM_TYPE2_MSGCODE)) {
byte_order = ENC_BIG_ENDIAN;
} else if (((msgcode = tvb_get_letohl(tvb, offset)) == PRISM_TYPE1_MSGCODE) ||
(msgcode == PRISM_TYPE2_MSGCODE)) {
byte_order = ENC_LITTLE_ENDIAN;
} else {
call_dissector(ieee80211_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
memset(&phdr, 0, sizeof(phdr));
phdr.fcs_len = -1;
phdr.decrypted = FALSE;
phdr.datapad = FALSE;
phdr.phy = PHDR_802_11_PHY_UNKNOWN;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Prism");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_prism, tvb, 0, 144, ENC_NA);
prism_tree = proto_item_add_subtree(ti, ett_prism);
proto_tree_add_item_ret_uint(prism_tree, hf_ieee80211_prism_msgcode, tvb, offset, 4, byte_order, &msgcode);
offset += 4;
proto_tree_add_item_ret_uint(prism_tree, hf_ieee80211_prism_msglen, tvb, offset, 4, byte_order, &msglen);
offset += 4;
proto_tree_add_item_ret_string(prism_tree, hf_ieee80211_prism_devname, tvb, offset, 16, ENC_ASCII|ENC_NA, wmem_packet_scope(), &devname_p);
offset += 16;
col_add_fstr(pinfo->cinfo, COL_INFO, "Device: %s, Message 0x%x, Length %d", devname_p, msgcode, msglen);
while (offset < PRISM_HEADER_LENGTH)
{
if (tree) {
ti_did = proto_tree_add_item(prism_tree, hf_ieee80211_prism_did, tvb, offset, 12, ENC_NA);
prism_did_tree = proto_item_add_subtree(ti_did, ett_prism_did);
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_type, tvb, offset, 4, byte_order);
did = tvb_get_guint32(tvb, offset, byte_order);
proto_item_append_text(ti_did, " %s", val_to_str(did, prism_did_vals, "Unknown %x") );
}
offset += 4;
status = tvb_get_guint16(tvb, offset, byte_order);
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_status, tvb, offset, 2, byte_order);
offset += 2;
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_length, tvb, offset, 2, byte_order);
offset += 2;
if (status == 0) {
switch (did) {
case PRISM_TYPE1_HOSTTIME:
case PRISM_TYPE2_HOSTTIME:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_hosttime, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_MACTIME:
case PRISM_TYPE2_MACTIME:
mactime = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_tsf_timestamp = 1;
phdr.tsf_timestamp = mactime;
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_mactime, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", mactime );
}
break;
case PRISM_TYPE1_CHANNEL:
case PRISM_TYPE2_CHANNEL:
channel = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_channel = TRUE;
phdr.channel = channel;
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_channel, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %u", channel);
}
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", channel);
break;
case PRISM_TYPE1_RSSI:
case PRISM_TYPE2_RSSI:
signal_dbm = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_signal_dbm = 1;
phdr.signal_dbm = signal_dbm;
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rssi, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", signal_dbm );
}
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d", signal_dbm);
break;
case PRISM_TYPE1_SQ:
case PRISM_TYPE2_SQ:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sq, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_SIGNAL:
case PRISM_TYPE2_SIGNAL:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_signal, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_NOISE:
case PRISM_TYPE2_NOISE:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_noise, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_RATE:
case PRISM_TYPE2_RATE:
rate = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_data_rate = TRUE;
phdr.data_rate = rate;
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rate, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %s Mb/s", prism_rate_return(rate));
}
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%s", prism_rate_return(rate));
break;
case PRISM_TYPE1_RATE_SIG_A1:
case PRISM_TYPE2_RATE_SIG_A1:
rate_phy1 = tvb_get_letohl(tvb, offset);
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sig_a1, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset));
}
break;
case PRISM_TYPE1_RATE_SIG_A2:
case PRISM_TYPE2_RATE_SIG_A2:
rate_phy2 = tvb_get_letohl(tvb, offset);
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sig_a2, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset));
}
break;
case PRISM_TYPE1_RATE_SIG_B:
case PRISM_TYPE2_RATE_SIG_B:
if (tree && rate_phy1 && rate_phy2) {
proto_item *sig_sub_item;
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sig_b, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset));
sig_sub_item = proto_tree_add_item(prism_tree, hf_ieee80211_prism_did_sig_rate_field, tvb, offset, 4, byte_order);
proto_item_append_text(sig_sub_item, " %s", prism_rate_return_sig(rate_phy1, rate_phy2, &phdr));
}
break;
case PRISM_TYPE1_ISTX:
case PRISM_TYPE2_ISTX:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_istx, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_FRMLEN:
case PRISM_TYPE2_FRMLEN:
if (tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_frmlen, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", tvb_get_guint32(tvb, offset, byte_order));
}
break;
default:
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_unknown, tvb, offset, 4, byte_order);
break;
}
}
offset += 4;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_with_data(ieee80211_radio_handle, next_tvb, pinfo, tree, (void *)&phdr);
return tvb_captured_length(tvb);
}
void proto_register_ieee80211_prism(void)
{
proto_prism = proto_register_protocol("Prism capture header", "Prism",
"prism");
proto_register_field_array(proto_prism, hf_prism, array_length(hf_prism));
proto_register_subtree_array(tree_array, array_length(tree_array));
prism_handle = register_dissector("prism", dissect_prism, proto_prism);
}
void proto_reg_handoff_ieee80211_prism(void)
{
capture_dissector_handle_t ieee80211_prism_cap_handle;
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_PRISM, prism_handle);
ieee80211_handle = find_dissector_add_dependency("wlan", proto_prism);
ieee80211_radio_handle = find_dissector_add_dependency("wlan_radio", proto_prism);
wlancap_handle = find_dissector_add_dependency("wlancap", proto_prism);
ieee80211_prism_cap_handle = create_capture_dissector_handle(capture_prism, proto_prism);
capture_dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_PRISM, ieee80211_prism_cap_handle);
ieee80211_cap_handle = find_capture_dissector("ieee80211");
wlancap_cap_handle = find_capture_dissector("wlancap");
}
