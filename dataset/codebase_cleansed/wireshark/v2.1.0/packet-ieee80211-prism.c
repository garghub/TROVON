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
static gboolean
capture_prism(const guchar *pd, int offset, int len, capture_packet_info_t *cpinfo, const union wtap_pseudo_header *pseudo_header _U_)
{
guint32 cookie;
if (!BYTES_ARE_IN_FRAME(offset, len, 4))
return FALSE;
cookie = pntoh32(pd);
if ((cookie == WLANCAP_MAGIC_COOKIE_V1) ||
(cookie == WLANCAP_MAGIC_COOKIE_V2)) {
return capture_wlancap(pd, offset, len, cpinfo, pseudo_header);
}
if (!BYTES_ARE_IN_FRAME(offset, len, PRISM_HEADER_LENGTH))
return FALSE;
offset += PRISM_HEADER_LENGTH;
return capture_ieee80211(pd, offset, len, cpinfo, pseudo_header);
}
static int
dissect_prism(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *prism_tree, *prism_did_tree = NULL;
proto_item *ti = NULL, *ti_did = NULL;
tvbuff_t *next_tvb;
int offset;
guint32 msgcode, msglen, did;
guint byte_order;
guint16 status;
guint8 *devname_p;
guint32 channel;
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
proto_tree_add_item(prism_tree, hf_ieee80211_prism_devname, tvb, offset, 16, ENC_ASCII|ENC_NA);
devname_p = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 16, ENC_ASCII);
offset += 16;
col_add_fstr(pinfo->cinfo, COL_INFO, "Device: %s, Message 0x%x, Length %d", devname_p, msgcode, msglen);
while(offset < PRISM_HEADER_LENGTH)
{
if(tree) {
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
switch(did){
case PRISM_TYPE1_HOSTTIME:
case PRISM_TYPE2_HOSTTIME:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_hosttime, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_MACTIME:
case PRISM_TYPE2_MACTIME:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_mactime, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %d", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_CHANNEL:
case PRISM_TYPE2_CHANNEL:
channel = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_channel = TRUE;
phdr.channel = channel;
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_channel, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %u", channel);
}
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", channel);
break;
case PRISM_TYPE1_RSSI:
case PRISM_TYPE2_RSSI:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rssi, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d", tvb_get_guint32(tvb, offset, byte_order));
break;
case PRISM_TYPE1_SQ:
case PRISM_TYPE2_SQ:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sq, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_SIGNAL:
case PRISM_TYPE2_SIGNAL:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_signal, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_NOISE:
case PRISM_TYPE2_NOISE:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_noise, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_RATE:
case PRISM_TYPE2_RATE:
rate = tvb_get_guint32(tvb, offset, byte_order);
phdr.has_data_rate = TRUE;
phdr.data_rate = rate;
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rate, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " %s Mb/s", prism_rate_return(rate));
}
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%s", prism_rate_return(rate));
break;
case PRISM_TYPE1_ISTX:
case PRISM_TYPE2_ISTX:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_istx, tvb, offset, 4, byte_order);
proto_item_append_text(ti_did, " 0x%x", tvb_get_guint32(tvb, offset, byte_order) );
}
break;
case PRISM_TYPE1_FRMLEN:
case PRISM_TYPE2_FRMLEN:
if(tree){
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
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_PRISM, prism_handle);
ieee80211_handle = find_dissector_add_dependency("wlan", proto_prism);
ieee80211_radio_handle = find_dissector_add_dependency("wlan_radio", proto_prism);
wlancap_handle = find_dissector_add_dependency("wlancap", proto_prism);
register_capture_dissector("wtap_encap", WTAP_ENCAP_IEEE_802_11_PRISM, capture_prism, proto_prism);
}
