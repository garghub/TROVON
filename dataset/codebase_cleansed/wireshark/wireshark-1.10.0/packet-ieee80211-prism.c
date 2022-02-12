static void
prism_rate_base_custom(gchar *result, guint32 rate)
{
g_snprintf(result, ITEM_LABEL_LENGTH, "%u.%u", rate /2, rate & 1 ? 5 : 0);
}
static gchar *
prism_rate_return(guint32 rate)
{
gchar *result=NULL;
result = (gchar *)ep_alloc(SHORT_STR);
result[0] = '\0';
prism_rate_base_custom(result, rate);
return result;
}
void
capture_prism(const guchar *pd, int offset, int len, packet_counts *ld)
{
guint32 cookie;
if (!BYTES_ARE_IN_FRAME(offset, len, 4)) {
ld->other++;
return;
}
cookie = pntohl(pd);
if ((cookie == WLANCAP_MAGIC_COOKIE_V1) ||
(cookie == WLANCAP_MAGIC_COOKIE_V2)) {
capture_wlancap(pd, offset, len, ld);
return;
}
if (!BYTES_ARE_IN_FRAME(offset, len, PRISM_HEADER_LENGTH)) {
ld->other++;
return;
}
offset += PRISM_HEADER_LENGTH;
capture_ieee80211(pd, offset, len, ld);
}
static void
dissect_prism(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *prism_tree = NULL, *prism_did_tree = NULL;
proto_item *ti = NULL, *ti_did = NULL;
tvbuff_t *next_tvb;
int offset;
guint32 msgcode, msglen, did;
guint16 status;
guint8 *devname_p;
offset = 0;
did = 0;
msgcode = tvb_get_ntohl(tvb, offset);
if ((msgcode == WLANCAP_MAGIC_COOKIE_V1) ||
(msgcode == WLANCAP_MAGIC_COOKIE_V2)) {
call_dissector(wlancap_handle, tvb, pinfo, tree);
return;
}
msgcode = tvb_get_letohl(tvb, offset);
if ((msgcode != PRISM_TYPE1_MSGCODE) &&
(msgcode != PRISM_TYPE2_MSGCODE)) {
call_dissector(ieee80211_handle, tvb, pinfo, tree);
return;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Prism");
col_clear(pinfo->cinfo, COL_INFO);
if(tree) {
ti = proto_tree_add_item(tree, proto_prism, tvb, 0, 144, ENC_NA);
prism_tree = proto_item_add_subtree(ti, ett_prism);
}
if(tree) {
proto_tree_add_item(prism_tree, hf_ieee80211_prism_msgcode, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
msgcode = tvb_get_letohl(tvb, offset);
offset += 4;
if(tree) {
proto_tree_add_item(prism_tree, hf_ieee80211_prism_msglen, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
msglen = tvb_get_letohl(tvb, offset);
offset += 4;
if(tree) {
proto_tree_add_item(prism_tree, hf_ieee80211_prism_devname, tvb, offset, 16, ENC_ASCII|ENC_NA);
}
devname_p = tvb_get_ephemeral_string(tvb, offset, 16);
offset += 16;
col_add_fstr(pinfo->cinfo, COL_INFO, "Device: %s, Message 0x%x, Length %d", devname_p, msgcode, msglen);
while(offset < PRISM_HEADER_LENGTH)
{
if(tree) {
ti_did = proto_tree_add_item(prism_tree, hf_ieee80211_prism_did, tvb, offset, 12, ENC_NA);
prism_did_tree = proto_item_add_subtree(ti_did, ett_prism_did);
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
did = tvb_get_letohl(tvb, offset);
proto_item_append_text(ti_did, " %s", val_to_str(did, prism_did_vals, "Unknown %x") );
}
offset += 4;
status = tvb_get_letohs(tvb, offset);
if(tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_status, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
if(tree) {
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
offset += 2;
if (status == 0) {
switch(did){
case PRISM_TYPE1_HOSTTIME:
case PRISM_TYPE2_HOSTTIME:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_hosttime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " %d", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_MACTIME:
case PRISM_TYPE2_MACTIME:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_mactime, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " %d", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_CHANNEL:
case PRISM_TYPE2_CHANNEL:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_channel, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " %d", tvb_get_letohl(tvb, offset) );
}
col_add_fstr(pinfo->cinfo, COL_FREQ_CHAN, "%u", tvb_get_letohl(tvb, offset));
break;
case PRISM_TYPE1_RSSI:
case PRISM_TYPE2_RSSI:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rssi, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset) );
}
col_add_fstr(pinfo->cinfo, COL_RSSI, "%d", tvb_get_letohl(tvb, offset));
break;
case PRISM_TYPE1_SQ:
case PRISM_TYPE2_SQ:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_sq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_SIGNAL:
case PRISM_TYPE2_SIGNAL:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_signal, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_NOISE:
case PRISM_TYPE2_NOISE:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_noise, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_RATE:
case PRISM_TYPE2_RATE:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_rate, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " %s Mb/s", prism_rate_return(tvb_get_letohl(tvb, offset)) );
}
col_add_fstr(pinfo->cinfo, COL_TX_RATE, "%s", prism_rate_return(tvb_get_letohl(tvb, offset)) );
break;
case PRISM_TYPE1_ISTX:
case PRISM_TYPE2_ISTX:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_istx, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " 0x%x", tvb_get_letohl(tvb, offset) );
}
break;
case PRISM_TYPE1_FRMLEN:
case PRISM_TYPE2_FRMLEN:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_frmlen, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(ti_did, " %d", tvb_get_letohl(tvb, offset) );
}
break;
default:
if(tree){
proto_tree_add_item(prism_did_tree, hf_ieee80211_prism_did_unknown, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
break;
}
}
offset += 4;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(ieee80211_handle, next_tvb, pinfo, tree);
}
void proto_register_ieee80211_prism(void)
{
proto_prism = proto_register_protocol("Prism capture header", "Prism",
"prism");
proto_register_field_array(proto_prism, hf_prism, array_length(hf_prism));
proto_register_subtree_array(tree_array, array_length(tree_array));
}
void proto_reg_handoff_ieee80211_prism(void)
{
dissector_handle_t prism_handle;
prism_handle = create_dissector_handle(dissect_prism, proto_prism);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE_802_11_PRISM, prism_handle);
ieee80211_handle = find_dissector("wlan");
wlancap_handle = find_dissector("wlancap");
}
