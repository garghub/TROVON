static gboolean
addr_uat_update_cb(void *r, char **err)
{
static_addr_t *map = (static_addr_t *)r;
if (map->addr16 >= IEEE802154_NO_ADDR16) {
*err = g_strdup("Invalid short address");
return FALSE;
}
if (map->pan >= IEEE802154_BCAST_PAN) {
*err = g_strdup("Invalid PAN identifier");
return FALSE;
}
if (map->eui64_len != sizeof(guint64)) {
*err = g_strdup("Invalid EUI-64 length");
return FALSE;
}
return TRUE;
}
static int ieee802_15_4_short_address_to_str(const address* addr, gchar *buf, int buf_len)
{
guint16 ieee_802_15_4_short_addr = pletoh16(addr->data);
if (ieee_802_15_4_short_addr == 0xffff)
{
g_strlcpy(buf, "Broadcast", buf_len);
return 10;
}
*buf++ = '0';
*buf++ = 'x';
buf = word_to_hex(buf, ieee_802_15_4_short_addr);
*buf = '\0';
return 7;
}
static int ieee802_15_4_short_address_str_len(const address* addr _U_)
{
return 11;
}
static int ieee802_15_4_short_address_len(void)
{
return 2;
}
static void
dissect_ieee802154_fcf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet, guint *offset)
{
guint16 fcf;
static const int * fields[] = {
&hf_ieee802154_frame_type,
&hf_ieee802154_security,
&hf_ieee802154_pending,
&hf_ieee802154_ack_request,
&hf_ieee802154_pan_id_compression,
&hf_ieee802154_seqno_suppression,
&hf_ieee802154_ie_present,
&hf_ieee802154_dst_addr_mode,
&hf_ieee802154_version,
&hf_ieee802154_src_addr_mode,
NULL
};
fcf = tvb_get_letohs(tvb, *offset);
packet->frame_type = (fcf & IEEE802154_FCF_TYPE_MASK);
packet->security_enable = (fcf & IEEE802154_FCF_SEC_EN) >> 3;
packet->frame_pending = (fcf & IEEE802154_FCF_FRAME_PND) >> 4;
packet->ack_request = (fcf & IEEE802154_FCF_ACK_REQ) >> 5;
packet->pan_id_compression = (fcf & IEEE802154_FCF_PAN_ID_COMPRESSION) >> 6;
packet->seqno_suppression = (fcf & IEEE802154_FCF_SEQNO_SUPPRESSION) >> 8;
packet->ie_present = (fcf & IEEE802154_FCF_IE_PRESENT) >> 9;
packet->dst_addr_mode = (fcf & IEEE802154_FCF_DADDR_MASK) >> 10;
packet->version = (fcf & IEEE802154_FCF_VERSION) >> 12;
packet->src_addr_mode = (fcf & IEEE802154_FCF_SADDR_MASK) >> 14;
if ((packet->version == IEEE802154_VERSION_2012e) && (packet->frame_type == IEEE802154_FCF_BEACON)) {
proto_item_append_text(tree, " Enhanced Beacon");
col_set_str(pinfo->cinfo, COL_INFO, "Enhanced Beacon");
}
else {
proto_item_append_text(tree, " %s", val_to_str_const(packet->frame_type, ieee802154_frame_types, "Reserved"));
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet->frame_type, ieee802154_frame_types, "Reserved"));
}
proto_tree_add_bitmask(tree, tvb, *offset, hf_ieee802154_fcf,
ett_ieee802154_fcf, fields, ENC_LITTLE_ENDIAN);
*offset += 2;
}
static int
dissect_ieee802154_nonask_phy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *ieee802154_tree = NULL;
proto_item *proto_root = NULL;
guint offset = 0;
guint8 phr;
tvbuff_t* mac;
if (tree) {
proto_root = proto_tree_add_protocol_format(tree, proto_ieee802154_nonask_phy, tvb, 0, tvb_captured_length(tvb), "IEEE 802.15.4 non-ASK PHY");
ieee802154_tree = proto_item_add_subtree(proto_root, ett_ieee802154_nonask_phy);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE 802.15.4 non-ASK PHY");
col_add_fstr(pinfo->cinfo, COL_PACKET_LENGTH, "%i", tvb_captured_length(tvb));
phr=tvb_get_guint8(tvb,offset+4+1);
if(tree) {
guint loffset=offset;
static const int * phr_fields[] = {
&hf_ieee802154_nonask_phy_length,
NULL
};
proto_tree_add_item(ieee802154_tree, hf_ieee802154_nonask_phy_preamble, tvb, loffset, 4, ENC_LITTLE_ENDIAN);
loffset+=4;
proto_tree_add_item(ieee802154_tree, hf_ieee802154_nonask_phy_sfd, tvb, loffset, 1, ENC_LITTLE_ENDIAN);
loffset+=1;
proto_tree_add_bitmask(ieee802154_tree, tvb, loffset, hf_ieee802154_nonask_phr, ett_ieee802154_nonask_phy_phr,
phr_fields, ENC_NA);
}
offset+=4+2*1;
mac=tvb_new_subset(tvb,offset,-1, phr & IEEE802154_PHY_LENGTH_MASK);
dissect_ieee802154(mac, pinfo, ieee802154_tree, NULL);
return tvb_captured_length(tvb);
}
static int
dissect_ieee802154(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
tvbuff_t *new_tvb = dissect_zboss_specific(tvb, pinfo, tree);
dissect_ieee802154_common(new_tvb, pinfo, tree,
((ieee802154_cc24xx || new_tvb != tvb) ? DISSECT_IEEE802154_OPTION_CC24xx : 0));
return tvb_captured_length(tvb);
}
static int
dissect_ieee802154_nofcs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void * data _U_)
{
tvbuff_t *new_tvb;
new_tvb = tvb_new_subset(tvb, 0, -1, tvb_reported_length(tvb)+IEEE802154_FCS_LEN);
dissect_ieee802154_common(new_tvb, pinfo, tree, 0);
return tvb_captured_length(tvb);
}
static tvbuff_t *
dissect_zboss_specific(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
if (tvb_captured_length(tvb) > 5)
{
guint off = 0;
if (tvb_get_guint8(tvb, off++) == 'Z'
&& tvb_get_guint8(tvb, off++) == 'B'
&& tvb_get_guint8(tvb, off++) == 'O'
&& tvb_get_guint8(tvb, off++) == 'S'
&& tvb_get_guint8(tvb, off++) == 'S')
{
proto_tree *zboss_tree = NULL;
proto_item *proto_root = NULL;
if (tree) {
proto_root = proto_tree_add_protocol_format(tree, proto_zboss, tvb, 0, tvb_captured_length(tvb), "ZBOSS dump");
zboss_tree = proto_item_add_subtree(proto_root, ett_ieee802154_zboss);
}
proto_tree_add_item(zboss_tree, zboss_direction, tvb, off, 1, ENC_NA);
proto_item_append_text(proto_root, ", %s", tvb_get_guint8(tvb, off) ? "OUT" : "IN");
off++;
proto_tree_add_item(zboss_tree, zboss_channel, tvb, off, 1, ENC_NA);
proto_item_append_text(proto_root, ", channel %u", tvb_get_guint8(tvb, off));
off++;
proto_tree_add_item(zboss_tree, zboss_trace_number, tvb, off, 4, ENC_LITTLE_ENDIAN);
off += 4;
return tvb_new_subset(tvb, off, tvb_captured_length(tvb) - off, tvb_captured_length(tvb) - off);
}
}
return tvb;
}
static int
dissect_ieee802154_cc24xx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void * data _U_)
{
dissect_ieee802154_common(tvb, pinfo, tree, DISSECT_IEEE802154_OPTION_CC24xx);
return tvb_captured_length(tvb);
}
static void
dissect_ieee802154_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint options)
{
tvbuff_t *volatile payload_tvb;
proto_tree *volatile ieee802154_tree = NULL;
proto_item *volatile proto_root = NULL;
proto_item *hidden_item;
proto_item *ti;
guint offset = 0;
volatile gboolean fcs_ok = TRUE;
const char *saved_proto;
ws_decrypt_status status;
gboolean dstPanPresent = FALSE;
gboolean srcPanPresent = FALSE;
ieee802154_packet *packet = wmem_new0(wmem_packet_scope(), ieee802154_packet);
ieee802154_short_addr addr16;
ieee802154_hints_t *ieee_hints;
heur_dtbl_entry_t *hdtbl_entry;
packet->short_table = ieee802154_map.short_table;
if(!pinfo->fd->flags.visited){
ieee_hints = wmem_new0(wmem_file_scope(), ieee802154_hints_t);
p_add_proto_data(wmem_file_scope(), pinfo, proto_ieee802154, 0, ieee_hints);
} else {
ieee_hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ieee802154, 0);
}
if (tree) {
proto_root = proto_tree_add_protocol_format(tree, proto_ieee802154, tvb, 0, tvb_captured_length(tvb), "IEEE 802.15.4");
ieee802154_tree = proto_item_add_subtree(proto_root, ett_ieee802154);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IEEE 802.15.4");
col_add_fstr(pinfo->cinfo, COL_PACKET_LENGTH, "%i", tvb_captured_length(tvb));
hidden_item = proto_tree_add_uint(ieee802154_tree, hf_ieee802154_frame_length, NULL, 0, 0, tvb_reported_length(tvb));
PROTO_ITEM_SET_HIDDEN(hidden_item);
dissect_ieee802154_fcf(tvb, pinfo, ieee802154_tree, packet, &offset);
if (packet->seqno_suppression) {
if (packet->version != IEEE802154_VERSION_2012e) {
expert_add_info(pinfo, proto_root, &ei_ieee802154_seqno_suppression);
}
} else {
packet->seqno = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_seqno, tvb, offset, 1, packet->seqno);
if (packet->frame_type == IEEE802154_FCF_ACK) {
proto_item_append_text(proto_root, ", Sequence Number: %u", packet->seqno);
}
}
offset += 1;
}
clear_address(&pinfo->net_dst);
clear_address(&pinfo->dl_dst);
clear_address(&pinfo->dst);
clear_address(&pinfo->net_src);
clear_address(&pinfo->dl_src);
clear_address(&pinfo->src);
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_RESERVED) {
expert_add_info(pinfo, proto_root, &ei_ieee802154_dst);
return;
}
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_RESERVED) {
expert_add_info(pinfo, proto_root, &ei_ieee802154_src);
return;
}
if (packet->version == IEEE802154_VERSION_RESERVED) {
expert_add_info(pinfo, proto_root, &ei_ieee802154_frame_ver);
return;
}
else if ((packet->version == IEEE802154_VERSION_2003) ||
(packet->version == IEEE802154_VERSION_2006)) {
if ((packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode != IEEE802154_FCF_ADDR_NONE)) {
if (packet->pan_id_compression == 1) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else {
dstPanPresent = TRUE;
srcPanPresent = TRUE;
}
}
else {
if (packet->pan_id_compression == 1) {
expert_add_info(pinfo, proto_root, &ei_ieee802154_invalid_addressing);
return;
}
else {
if ((packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode != IEEE802154_FCF_ADDR_NONE)) {
dstPanPresent = FALSE;
srcPanPresent = TRUE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE)) {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
else {
expert_add_info(pinfo, proto_root, &ei_ieee802154_invalid_addressing);
return;
}
}
}
}
else if (packet->version == IEEE802154_VERSION_2012e) {
if ((packet->frame_type == IEEE802154_FCF_BEACON) ||
(packet->frame_type == IEEE802154_FCF_DATA) ||
(packet->frame_type == IEEE802154_FCF_ACK) ||
(packet->frame_type == IEEE802154_FCF_CMD) ) {
if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = FALSE;
srcPanPresent = TRUE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src_addr_mode != IEEE802154_FCF_ADDR_NONE) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = TRUE;
srcPanPresent = TRUE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = TRUE;
srcPanPresent = TRUE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->pan_id_compression == 0)) {
dstPanPresent = TRUE;
srcPanPresent = TRUE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->pan_id_compression == 1)) {
dstPanPresent = TRUE;
srcPanPresent = FALSE;
}
else {
expert_add_info(pinfo, proto_root, &ei_ieee802154_invalid_panid_compression2);
return;
}
}
else {
dstPanPresent = FALSE;
srcPanPresent = FALSE;
}
}
else {
expert_add_info(pinfo, proto_root, &ei_ieee802154_frame_ver);
return;
}
if (dstPanPresent) {
packet->dst_pan = tvb_get_letohs(tvb, offset);
if (ieee802154_tree) {
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_dst_panID, tvb, offset, 2, packet->dst_pan);
}
offset += 2;
}
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) {
gchar* dst_addr;
packet->dst16 = tvb_get_letohs(tvb, offset);
if (ieee_hints) {
ieee_hints->dst16 = packet->dst16;
}
set_address_tvb(&pinfo->dl_dst, ieee802_15_4_short_address_type, 2, tvb, offset);
copy_address_shallow(&pinfo->dst, &pinfo->dl_dst);
dst_addr = address_to_str(wmem_packet_scope(), &pinfo->dst);
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_dst16, tvb, offset, 2, packet->dst16);
proto_item_append_text(proto_root, ", Dst: %s", dst_addr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: %s", dst_addr);
offset += 2;
}
else if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) {
guint64 *p_addr = (guint64 *)wmem_new(pinfo->pool, guint64);
packet->dst64 = tvb_get_letoh64(tvb, offset);
*p_addr = pntoh64(&(packet->dst64));
set_address(&pinfo->dl_dst, AT_EUI64, 8, p_addr);
copy_address_shallow(&pinfo->dst, &pinfo->dl_dst);
if (tree) {
proto_tree_add_item(ieee802154_tree, hf_ieee802154_dst64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(proto_root, ", Dst: %s", eui64_to_display(wmem_packet_scope(), packet->dst64));
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Dst: %s", eui64_to_display(wmem_packet_scope(), packet->dst64));
offset += 8;
}
if (srcPanPresent) {
packet->src_pan = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_src_panID, tvb, offset, 2, packet->src_pan);
offset += 2;
}
else {
if (dstPanPresent) {
packet->src_pan = packet->dst_pan;
}
else {
packet->src_pan = IEEE802154_BCAST_PAN;
}
}
if (ieee_hints) {
ieee_hints->src_pan = packet->src_pan;
}
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) {
gchar* src_addr;
packet->src16 = tvb_get_letohs(tvb, offset);
if (!pinfo->fd->flags.visited) {
addr16.addr = packet->src16;
addr16.pan = packet->src_pan;
if (ieee_hints) {
ieee_hints->src16 = packet->src16;
ieee_hints->map_rec = (ieee802154_map_rec *)
g_hash_table_lookup(ieee802154_map.short_table, &addr16);
}
}
set_address_tvb(&pinfo->dl_src, ieee802_15_4_short_address_type, 2, tvb, offset);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
src_addr = address_to_str(wmem_packet_scope(), &pinfo->src);
if (tree) {
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_src16, tvb, offset, 2, packet->src16);
proto_item_append_text(proto_root, ", Src: %s", src_addr);
if (ieee_hints && ieee_hints->map_rec) {
ti = proto_tree_add_eui64(ieee802154_tree, hf_ieee802154_src64, tvb, offset, 0,
ieee_hints->map_rec->addr64);
PROTO_ITEM_SET_GENERATED(ti);
if ( ieee_hints->map_rec->start_fnum ) {
ti = proto_tree_add_uint(ieee802154_tree, hf_ieee802154_src64_origin, tvb, 0, 0,
ieee_hints->map_rec->start_fnum);
}
else {
ti = proto_tree_add_uint_format_value(ieee802154_tree, hf_ieee802154_src64_origin, tvb, 0, 0,
ieee_hints->map_rec->start_fnum, "Pre-configured");
}
PROTO_ITEM_SET_GENERATED(ti);
}
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src: %s", src_addr);
offset += 2;
}
else if (packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) {
guint64 *p_addr = (guint64 *)wmem_new(pinfo->pool, guint64);
packet->src64 = tvb_get_letoh64(tvb, offset);
*p_addr = pntoh64(&(packet->src64));
set_address(&pinfo->dl_src, AT_EUI64, 8, p_addr);
copy_address_shallow(&pinfo->src, &pinfo->dl_src);
if (tree) {
proto_tree_add_item(ieee802154_tree, hf_ieee802154_src64, tvb, offset, 8, ENC_LITTLE_ENDIAN);
proto_item_append_text(proto_root, ", Src: %s", eui64_to_display(wmem_packet_scope(), packet->src64));
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", Src: %s", eui64_to_display(wmem_packet_scope(), packet->src64));
offset += 8;
}
if (tvb_bytes_exist(tvb, tvb_reported_length(tvb)-IEEE802154_FCS_LEN, IEEE802154_FCS_LEN)) {
guint16 fcs = tvb_get_letohs(tvb, tvb_reported_length(tvb)-IEEE802154_FCS_LEN);
if (options & DISSECT_IEEE802154_OPTION_CC24xx) {
fcs_ok = (fcs & IEEE802154_CC24xx_CRC_OK);
}
else {
guint16 fcs_calc = ieee802154_crc_tvb(tvb, tvb_reported_length(tvb)-IEEE802154_FCS_LEN);
fcs_ok = (fcs == fcs_calc);
}
}
if (packet->security_enable) {
proto_tree *header_tree, *field_tree;
guint8 security_control;
guint aux_length = 5;
static const int * security_fields[] = {
&hf_ieee802154_security_level,
&hf_ieee802154_key_id_mode,
&hf_ieee802154_aux_sec_reserved,
NULL
};
security_control = tvb_get_guint8(tvb, offset);
packet->security_level = (ieee802154_security_level)(security_control & IEEE802154_AUX_SEC_LEVEL_MASK);
packet->key_id_mode = (ieee802154_key_id_mode)((security_control & IEEE802154_AUX_KEY_ID_MODE_MASK) >> IEEE802154_AUX_KEY_ID_MODE_SHIFT);
if (packet->key_id_mode != KEY_ID_MODE_IMPLICIT) aux_length++;
if (packet->key_id_mode == KEY_ID_MODE_KEY_EXPLICIT_4) aux_length += 4;
if (packet->key_id_mode == KEY_ID_MODE_KEY_EXPLICIT_8) aux_length += 8;
header_tree = proto_tree_add_subtree(ieee802154_tree, tvb, offset, aux_length,
ett_ieee802154_auxiliary_security, NULL, "Auxiliary Security Header");
proto_tree_add_bitmask(header_tree, tvb, offset, hf_ieee802154_security_control_field, ett_ieee802154_aux_sec_control, security_fields, ENC_NA);
offset++;
packet->frame_counter = tvb_get_letohl (tvb, offset);
proto_tree_add_uint(header_tree, hf_ieee802154_aux_sec_frame_counter, tvb, offset,4, packet->frame_counter);
offset +=4;
if (packet->key_id_mode != KEY_ID_MODE_IMPLICIT) {
field_tree = proto_tree_add_subtree(header_tree, tvb, offset, 1,
ett_ieee802154_aux_sec_key_id, &ti, "Key Identifier Field");
if (packet->key_id_mode == KEY_ID_MODE_KEY_EXPLICIT_4) {
packet->key_source.addr32 = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint64(field_tree, hf_ieee802154_aux_sec_key_source, tvb, offset, 4, packet->key_source.addr32);
proto_item_set_len(ti, 1 + 4);
offset += (int)sizeof (guint32);
}
if (packet->key_id_mode == KEY_ID_MODE_KEY_EXPLICIT_8) {
packet->key_source.addr64 = tvb_get_ntoh64(tvb, offset);
proto_tree_add_uint64(field_tree, hf_ieee802154_aux_sec_key_source, tvb, offset, 8, packet->key_source.addr64);
proto_item_set_len(ti, 1 + 8);
offset += 8;
}
packet->key_index = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(field_tree, hf_ieee802154_aux_sec_key_index, tvb, offset,1, packet->key_index);
offset++;
}
}
if ((packet->version == IEEE802154_VERSION_2003) || (packet->version == IEEE802154_VERSION_2006)) {
if (packet->frame_type == IEEE802154_FCF_BEACON) {
dissect_ieee802154_superframe(tvb, pinfo, ieee802154_tree, &offset);
dissect_ieee802154_gtsinfo(tvb, pinfo, ieee802154_tree, &offset);
dissect_ieee802154_pendaddr(tvb, pinfo, ieee802154_tree, &offset);
}
if (packet->frame_type == IEEE802154_FCF_CMD) {
packet->command_id = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_cmd_id, tvb, offset, 1, packet->command_id);
}
offset++;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
}
}
else {
if (packet->ie_present) {
dissect_ieee802154_header_ie(tvb, pinfo, ieee802154_tree, &offset, packet);
}
}
if (packet->security_enable && (packet->version == IEEE802154_VERSION_2003)) {
packet->security_level = (ieee802154_security_level)ieee802154_sec_suite;
if (IEEE802154_IS_ENCRYPTED(packet->security_level)) {
packet->frame_counter = tvb_get_letohl (tvb, offset);
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_sec_frame_counter, tvb, offset, (int)sizeof(guint32), packet->frame_counter);
offset += (int)sizeof(guint32);
packet->key_sequence_counter = tvb_get_guint8 (tvb, offset);
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_sec_key_sequence_counter, tvb, offset, (int)sizeof(guint8), packet->key_sequence_counter);
offset += (int)sizeof(guint8);
}
}
if (packet->security_enable) {
payload_tvb = dissect_ieee802154_decrypt(tvb, offset, pinfo, packet, &status);
if (!payload_tvb) {
gint reported_len = tvb_reported_length(tvb)-offset-IEEE802154_FCS_LEN;
gint captured_len = tvb_captured_length(tvb)-offset;
if (reported_len < captured_len) captured_len = reported_len;
payload_tvb = tvb_new_subset(tvb, offset, captured_len, reported_len);
}
switch (status) {
case DECRYPT_PACKET_SUCCEEDED:
case DECRYPT_NOT_ENCRYPTED:
break;
case DECRYPT_VERSION_UNSUPPORTED:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "We don't support decryption with protocol version %u", packet->version);
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
case DECRYPT_PACKET_TOO_SMALL:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "Packet was too small to include the CRC and MIC");
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
case DECRYPT_PACKET_NO_EXT_SRC_ADDR:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "No extended source address - can't decrypt");
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
case DECRYPT_PACKET_NO_KEY:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "No encryption key set - can't decrypt");
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
case DECRYPT_PACKET_DECRYPT_FAILED:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "Decrypt failed");
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
case DECRYPT_PACKET_MIC_CHECK_FAILED:
expert_add_info_format(pinfo, proto_root, &ei_ieee802154_decrypt_error, "MIC check failed");
if (IEEE802154_IS_ENCRYPTED(packet->security_level)) {
call_data_dissector(payload_tvb, pinfo, tree);
goto dissect_ieee802154_fcs;
}
break;
}
}
else {
gint reported_len = tvb_reported_length(tvb)-offset-IEEE802154_FCS_LEN;
gint captured_len = tvb_captured_length(tvb)-offset;
if (reported_len < captured_len) captured_len = reported_len;
payload_tvb = tvb_new_subset(tvb, offset, captured_len, reported_len);
}
if (packet->payload_ie_present) {
offset += dissect_ieee802154_payload_ie(tvb, pinfo, ieee802154_tree, offset);
}
if ((packet->version == IEEE802154_VERSION_2012e) && (packet->frame_type == IEEE802154_FCF_CMD)) {
packet->command_id = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_uint(ieee802154_tree, hf_ieee802154_cmd_id, tvb, offset, 1, packet->command_id);
}
offset++;
if ((packet->version == IEEE802154_VERSION_2012e) && (packet->command_id == IEEE802154_CMD_BEACON_REQ)) {
col_set_str(pinfo->cinfo, COL_INFO, "Enhanced Beacon Request");
}
else {
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
}
}
if (tvb_captured_length_remaining(tvb, offset) > IEEE802154_FCS_LEN) {
saved_proto = pinfo->current_proto;
TRY {
switch (packet->frame_type) {
case IEEE802154_FCF_BEACON:
if (!dissector_try_heuristic(ieee802154_beacon_subdissector_list, payload_tvb, pinfo, tree, &hdtbl_entry, packet)) {
call_data_dissector(payload_tvb, pinfo, tree);
}
break;
case IEEE802154_FCF_CMD:
dissect_ieee802154_command(payload_tvb, pinfo, ieee802154_tree, packet);
break;
case IEEE802154_FCF_DATA:
if ((!fcs_ok && ieee802154_fcs_ok) || !tvb_reported_length(payload_tvb)) {
call_data_dissector(payload_tvb, pinfo, tree);
break;
}
if (dissector_try_uint_new(panid_dissector_table, packet->src_pan, payload_tvb, pinfo, tree, TRUE, packet)) {
break;
}
if (((packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) ||
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT)) &&
(packet->dst_pan != packet->src_pan) &&
dissector_try_uint_new(panid_dissector_table, packet->src_pan, payload_tvb, pinfo, tree, TRUE, packet)) {
break;
}
if (dissector_try_heuristic(ieee802154_heur_subdissector_list, payload_tvb, pinfo, tree, &hdtbl_entry, packet)) break;
default:
call_data_dissector(payload_tvb, pinfo, tree);
}
}
CATCH_ALL {
show_exception(payload_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->current_proto = saved_proto;
}
ENDTRY;
}
dissect_ieee802154_fcs:
offset = tvb_reported_length(tvb)-IEEE802154_FCS_LEN;
if (tvb_bytes_exist(tvb, offset, IEEE802154_FCS_LEN) && (tree)) {
proto_tree *field_tree;
guint16 fcs = tvb_get_letohs(tvb, offset);
if ((options & DISSECT_IEEE802154_OPTION_CC24xx)) {
field_tree = proto_tree_add_subtree_format(ieee802154_tree, tvb, offset, 2, ett_ieee802154_fcs, NULL,
"Frame Check Sequence (TI CC24xx format): FCS %s", (fcs_ok) ? "OK" : "Bad");
ti = proto_tree_add_int(field_tree, hf_ieee802154_rssi, tvb, offset++, 1, (gint8) (fcs & IEEE802154_CC24xx_RSSI));
proto_item_append_text(ti, " dB");
proto_tree_add_boolean(field_tree, hf_ieee802154_fcs_ok, tvb, offset, 1, (gboolean) (fcs & IEEE802154_CC24xx_CRC_OK));
proto_tree_add_uint(field_tree, hf_ieee802154_correlation, tvb, offset, 1, (guint8) ((fcs & IEEE802154_CC24xx_CORRELATION) >> 8));
}
else {
ti = proto_tree_add_uint(ieee802154_tree, hf_ieee802154_fcs, tvb, offset, 2, fcs);
if (fcs_ok) {
proto_item_append_text(ti, " (Correct)");
}
else {
proto_item_append_text(ti, " (Incorrect, expected FCS=0x%04x", ieee802154_crc_tvb(tvb, offset));
}
ti = proto_tree_add_boolean(ieee802154_tree, hf_ieee802154_fcs_ok, tvb, offset, 2, fcs_ok);
PROTO_ITEM_SET_HIDDEN(ti);
}
}
else if (tree) {
ti = proto_tree_add_boolean_format_value(ieee802154_tree, hf_ieee802154_fcs_ok, tvb, offset, 2, fcs_ok, "Unknown");
PROTO_ITEM_SET_HIDDEN(ti);
}
if (!fcs_ok) {
col_append_str(pinfo->cinfo, COL_INFO, ", Bad FCS");
if (tree) proto_item_append_text(proto_root, ", Bad FCS");
expert_add_info(pinfo, proto_root, &ei_ieee802154_fcs);
}
}
void
dissect_ieee802154_superframe(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
static const int * superframe[] = {
&hf_ieee802154_beacon_order,
&hf_ieee802154_superframe_order,
&hf_ieee802154_cap,
&hf_ieee802154_superframe_battery_ext,
&hf_ieee802154_superframe_coord,
&hf_ieee802154_assoc_permit,
NULL
};
proto_tree_add_bitmask_text(tree, tvb, *offset, 2, "Superframe Specification: ", NULL , ett_ieee802154_superframe, superframe, ENC_LITTLE_ENDIAN, BMT_NO_INT|BMT_NO_TFS);
(*offset) += 2;
}
void
dissect_ieee802154_gtsinfo(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_tree *field_tree = NULL;
proto_tree *subtree = NULL;
proto_item *ti;
guint8 gts_spec;
guint8 gts_count;
gts_spec = tvb_get_guint8(tvb, *offset);
gts_count = gts_spec & IEEE802154_GTS_COUNT_MASK;
if (tree) {
if (gts_count) {
field_tree = proto_tree_add_subtree(tree, tvb, *offset, 2 + (gts_count * 3), ett_ieee802154_gts, NULL, "GTS");
}
else {
field_tree = proto_tree_add_subtree(tree, tvb, *offset, 1, ett_ieee802154_gts, NULL, "GTS");
}
proto_tree_add_uint(field_tree, hf_ieee802154_gts_count, tvb, *offset, 1, gts_count);
proto_tree_add_boolean(field_tree, hf_ieee802154_gts_permit, tvb, *offset, 1, gts_spec & IEEE802154_GTS_PERMIT_MASK);
}
(*offset) += 1;
if (gts_count) {
guint8 gts_directions = tvb_get_guint8(tvb, *offset);
guint gts_rx = 0;
int i;
if (tree) {
proto_tree *dir_tree;
dir_tree = proto_tree_add_subtree(field_tree, tvb, *offset, 1, ett_ieee802154_gts_direction, &ti, "GTS Directions");
for (i=0; i<gts_count; i++) {
gboolean dir = gts_directions & IEEE802154_GTS_DIRECTION_SLOT(i);
proto_tree_add_boolean_format(dir_tree, hf_ieee802154_gts_direction, tvb, *offset, 1, dir, "GTS Slot %i: %s", i+1, dir?"Receive Only":"Transmit Only");
if (dir) gts_rx++;
}
proto_item_append_text(ti, ": %i Receive & %i Transmit", gts_rx, gts_count - gts_rx);
}
(*offset) += 1;
subtree = proto_tree_add_subtree(field_tree, tvb, *offset, gts_count * 3, ett_ieee802154_gts_descriptors, NULL, "GTS Descriptors");
for (i=0; i<gts_count; i++) {
guint16 gts_addr = tvb_get_letohs(tvb, (*offset));
guint8 gts_slot = tvb_get_guint8(tvb, (*offset)+2);
guint8 gts_length = (gts_slot & IEEE802154_GTS_LENGTH_MASK) >> IEEE802154_GTS_LENGTH_SHIFT;
gts_slot = (gts_slot & IEEE802154_GTS_SLOT_MASK);
if (tree) {
ti = proto_tree_add_uint(subtree, hf_ieee802154_gts_address, tvb, (*offset), 3, gts_addr);
proto_item_append_text(ti, ", Slot: %i", gts_slot);
proto_item_append_text(ti, ", Length: %i", gts_length);
}
(*offset) += 3;
}
}
}
void
dissect_ieee802154_pendaddr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset)
{
proto_tree *subtree;
guint8 pend_spec;
guint8 pend_num16;
guint8 pend_num64;
int i;
pend_spec = tvb_get_guint8(tvb, *offset);
pend_num16 = pend_spec & IEEE802154_PENDADDR_SHORT_MASK;
pend_num64 = (pend_spec & IEEE802154_PENDADDR_LONG_MASK) >> IEEE802154_PENDADDR_LONG_SHIFT;
subtree = proto_tree_add_subtree_format(tree, tvb, *offset, 1 + 2*pend_num16 + 8*pend_num64,
ett_ieee802154_pendaddr, NULL, "Pending Addresses: %i Short and %i Long", pend_num16, pend_num64);
(*offset) += 1;
for (i=0; i<pend_num16; i++) {
guint16 addr = tvb_get_letohs(tvb, *offset);
proto_tree_add_uint(subtree, hf_ieee802154_pending16, tvb, *offset, 2, addr);
(*offset) += 2;
}
for (i=0; i<pend_num64; i++) {
proto_tree_add_item(subtree, hf_ieee802154_pending64, tvb, *offset, 8, ENC_LITTLE_ENDIAN);
(*offset) += 8;
}
}
static void
dissect_ieee802154_header_ie(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint *offset, ieee802154_packet *packet)
{
proto_tree *subtree;
guint16 header_ie;
guint16 id;
guint16 length;
GByteArray *gba = g_byte_array_new();
static const int * fields[] = {
&hf_ieee802154_header_ie_type,
&hf_ieee802154_header_ie_id,
&hf_ieee802154_header_ie_length,
NULL
};
do {
header_ie = tvb_get_letohs(tvb, *offset);
id = (header_ie & IEEE802154_HEADER_IE_ID_MASK) >> 7;
length = header_ie & IEEE802154_HEADER_IE_LENGTH_MASK;
subtree = proto_tree_add_subtree(tree, tvb, *offset, 2+length, ett_ieee802154_header, NULL, "Header IE");
proto_item_append_text(subtree, ", Element ID: %s, Length: %d", val_to_str_const(id, ieee802154_header_ie_names, "Unknown IE"), length);
proto_tree_add_bitmask(subtree, tvb, *offset, hf_ieee802154_header_ie,
ett_ieee802154_header_ie, fields, ENC_LITTLE_ENDIAN);
*offset += 2;
if (length > 0) {
proto_tree_add_bytes_item(subtree, hf_ieee802154_header_ie_data, tvb, *offset, length, ENC_NA, gba, NULL, NULL);
*offset += length;
}
} while ((tvb_reported_length(tvb) > 1) &&
(id != IEEE802154_HEADER_IE_EID_TERM1) &&
(id != IEEE802154_HEADER_IE_EID_TERM2));
if ((tvb_reported_length(tvb) > 1) && (id == IEEE802154_HEADER_IE_EID_TERM1)) {
packet->payload_ie_present = TRUE;
}
else {
packet->payload_ie_present = FALSE;
}
}
static int
dissect_ieee802154_payload_mlme_sub_ie(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *subtree;
guint16 psie_ie;
guint16 psie_id;
guint psie_remaining = 0;
int orig_offset = offset;
static const int * fields_short[] = {
&hf_ieee802154_psie_type_short,
&hf_ieee802154_psie_id_short,
&hf_ieee802154_psie_length_short,
NULL
};
static const int * fields_long[] = {
&hf_ieee802154_psie_type_long,
&hf_ieee802154_psie_id_long,
&hf_ieee802154_psie_length_long,
NULL
};
static const int * fields_eb_filter[] = {
&hf_ieee802154_psie_eb_filter_pjoin,
&hf_ieee802154_psie_eb_filter_lqi,
&hf_ieee802154_psie_eb_filter_percent,
&hf_ieee802154_psie_eb_filter_attr_id,
NULL
};
psie_ie = tvb_get_letohs(tvb, offset);
if (psie_ie & IEEE802154_PSIE_TYPE_MASK) {
psie_id = (psie_ie & IEEE802154_PSIE_ID_MASK_LONG) >> 11;
psie_remaining = psie_ie & IEEE802154_PSIE_LENGTH_MASK_LONG;
subtree = proto_tree_add_subtree(tree, tvb, offset, 2+psie_remaining, ett_ieee802154_psie_long, NULL, "Nested Sub IE (long)");
proto_tree_add_bitmask(subtree, tvb, offset, hf_ieee802154_psie_long,
ett_ieee802154_psie_long_bitmap, fields_long, ENC_LITTLE_ENDIAN);
}
else {
psie_id = (psie_ie & IEEE802154_PSIE_ID_MASK_SHORT) >> 8;
psie_remaining = psie_ie & IEEE802154_PSIE_LENGTH_MASK_SHORT;
subtree = proto_tree_add_subtree(tree, tvb, offset, 2+psie_remaining, ett_ieee802154_psie_short, NULL, "Nested Sub IE (short)");
proto_tree_add_bitmask(subtree, tvb, offset, hf_ieee802154_psie_short,
ett_ieee802154_psie_short_bitmap, fields_short, ENC_LITTLE_ENDIAN);
}
proto_item_append_text(subtree, ", Sub IE: %s, Length: %d", val_to_str_const(psie_id, ieee802154_psie_names, "Unknown IE"), psie_remaining);
offset += 2;
switch (psie_id) {
case IEEE802154_MLME_SUBIE_ENHANCED_BEACON_FILTER:
{
guint8 filter;
guint8 attr_len;
guint32 attr_bitmap = 0;
filter = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(subtree, tvb, offset, hf_ieee802154_psie_eb_filter,
ett_ieee802154_psie_enh_beacon_flt_bitmap, fields_eb_filter,
ENC_NA);
offset += 1;
if (filter & IEEE802154_MLME_PSIE_EB_FLT_LQI) {
proto_tree_add_item(subtree, hf_ieee802154_psie_eb_filter_lqi_min, tvb, offset, 1, ENC_NA);
offset += 1;
}
if (filter & IEEE802154_MLME_PSIE_EB_FLT_PERCENT) {
proto_tree_add_item(subtree, hf_ieee802154_psie_eb_filter_percent_prob, tvb, offset, 1, ENC_NA);
offset += 1;
}
attr_len = (filter & IEEE802154_MLME_PSIE_EB_FLT_ATTR_LEN) >> 3;
if (attr_len) {
switch(attr_len) {
case 1:
attr_bitmap = (guint32)tvb_get_guint8(tvb, offset);
break;
case 2:
attr_bitmap = (guint32)tvb_get_ntohs(tvb, offset);
break;
case 3:
attr_bitmap = tvb_get_ntoh24(tvb, offset);
break;
}
proto_tree_add_uint(subtree, hf_ieee802154_psie_eb_filter_attr_id_bitmap, tvb, offset,
attr_len, attr_bitmap);
offset += attr_len;
}
}
break;
case IEEE802154_MLME_SUBIE_TSCH_SYNCH:
case IEEE802154_MLME_SUBIE_TSCH_SLOTFR_LINK:
case IEEE802154_MLME_SUBIE_TSCH_TIMESLOT:
case IEEE802154_MLME_SUBIE_HOPPING_TIMING:
case IEEE802154_MLME_SUBIE_MAC_METRICS:
case IEEE802154_MLME_SUBIE_ALL_MAC_METRICS:
case IEEE802154_MLME_SUBIE_COEXISTENCE_SPEC:
case IEEE802154_MLME_SUBIE_SUN_DEVICE_CAPABILITIES:
case IEEE802154_MLME_SUBIE_SUN_FSK_GEN_PHY:
case IEEE802154_MLME_SUBIE_MODE_SWITCH_PARAMETER:
case IEEE802154_MLME_SUBIE_PHY_PARAMETER_CHANGE:
case IEEE802154_MLME_SUBIE_O_QPSK_PHY_MODE:
case IEEE802154_MLME_SUBIE_PCA_ALLOCATION:
case IEEE802154_MLME_SUBIE_DSSS_OPER_MODE:
case IEEE802154_MLME_SUBIE_FSK_OPER_MODE:
case IEEE802154_MLME_SUBIE_TVWS_PHY_OPE_MODE:
case IEEE802154_MLME_SUBIE_TVWS_DEVICE_CAPAB:
case IEEE802154_MLME_SUBIE_TVWS_DEVICE_CATEG:
case IEEE802154_MLME_SUBIE_TVWS_DEVICE_IDENTIF:
case IEEE802154_MLME_SUBIE_TVWS_DEVICE_LOCATION:
case IEEE802154_MLME_SUBIE_TVWS_CH_INFOR_QUERY:
case IEEE802154_MLME_SUBIE_TVWS_CH_INFOR_SOURCE:
case IEEE802154_MLME_SUBIE_CTM:
case IEEE802154_MLME_SUBIE_TIMESTAMP:
case IEEE802154_MLME_SUBIE_TIMESTAMP_DIFF:
case IEEE802154_MLME_SUBIE_TMCP_SPECIFICATION:
case IEEE802154_MLME_SUBIE_RCC_PHY_OPER_MODE:
default:
if (psie_remaining) {
proto_tree_add_item(subtree, hf_ieee802154_mlme_ie_data, tvb, offset, psie_remaining, ENC_NA);
offset += psie_remaining;
}
break;
}
return (offset - orig_offset);
}
static int
dissect_ieee802154_vendor_ie(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset, gint pie_length)
{
tvbuff_t *next_tvb;
guint32 vendor_oui;
vendor_oui = tvb_get_letoh24(tvb, offset);
proto_item_append_text(tree, ", Vendor OUI: %06X (%s)", vendor_oui,
val_to_str_const(vendor_oui, ieee802154_vendor_oui_names, "unknown"));
proto_tree_add_uint_format_value(tree, hf_ieee802154_payload_ie_vendor_oui, tvb, offset, 3,
vendor_oui, "%06X (%s)", vendor_oui, val_to_str_const(vendor_oui, ieee802154_vendor_oui_names, "unknown"));
offset += 3;
pie_length -= 3;
next_tvb = tvb_new_subset_length(tvb, offset, pie_length);
switch (vendor_oui) {
case IEEE802154_VENDOR_OUI_ZIGBEE:
call_dissector_with_data(zigbee_ie_handle, next_tvb, pinfo, tree, &pie_length);
break;
default:
call_data_dissector(next_tvb, pinfo, tree);
break;
}
return pie_length + 3;
}
static int
dissect_ieee802154_payload_ie(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree *subtree;
guint16 payload_ie;
guint16 pie_id;
int pie_length;
int orig_offset;
static const int * fields[] = {
&hf_ieee802154_payload_ie_type,
&hf_ieee802154_payload_ie_id,
&hf_ieee802154_payload_ie_length,
NULL
};
orig_offset = offset;
do {
payload_ie = tvb_get_letohs(tvb, offset);
pie_id = (payload_ie & IEEE802154_PAYLOAD_IE_ID_MASK) >> 11;
pie_length = payload_ie & IEEE802154_PAYLOAD_IE_LENGTH_MASK;
subtree = proto_tree_add_subtree(tree, tvb, offset, pie_length + 2, ett_ieee802154_payload, NULL, "Payload IE");
proto_item_append_text(subtree, ", %s, Length: %d", val_to_str_const(pie_id, ieee802154_payload_ie_names, "Unknown IE"), pie_length);
proto_tree_add_bitmask(subtree, tvb, offset, hf_ieee802154_payload_ie,
ett_ieee802154_payload_ie, fields, ENC_LITTLE_ENDIAN);
offset += 2;
switch (pie_id) {
case IEEE802154_PAYLOAD_IE_MLME:
while (offset < (orig_offset + pie_length)) {
offset += dissect_ieee802154_payload_mlme_sub_ie(tvb, pinfo, subtree, offset);
}
break;
case IEEE802154_PAYLOAD_IE_VENDOR:
offset += dissect_ieee802154_vendor_ie(tvb, pinfo, subtree, offset, pie_length);
break;
default:
if (pie_length > 0) {
proto_tree_add_item(subtree, hf_ieee802154_payload_ie_data, tvb, offset, pie_length, ENC_NA);
}
}
} while ((tvb_reported_length(tvb) > 1) && (pie_id != IEEE802154_PAYLOAD_IE_GID_TERM));
return (offset - orig_offset);
}
static void
dissect_ieee802154_assoc_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
proto_tree *subtree;
static const int * capability[] = {
&hf_ieee802154_cinfo_alt_coord,
&hf_ieee802154_cinfo_device_type,
&hf_ieee802154_cinfo_power_src,
&hf_ieee802154_cinfo_idle_rx,
&hf_ieee802154_cinfo_sec_capable,
&hf_ieee802154_cinfo_alloc_addr,
NULL
};
subtree = proto_tree_add_subtree(tree, tvb, 0, 1, ett_ieee802154_cmd, NULL,
val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
proto_tree_add_bitmask_list(subtree, tvb, 0, 1, capability, ENC_NA);
if (tvb_reported_length(tvb) > 1) {
call_data_dissector(tvb_new_subset_remaining(tvb, 1), pinfo, tree);
}
}
static void
dissect_ieee802154_assoc_rsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
proto_tree *subtree;
proto_item *ti;
guint16 short_addr;
guint8 status;
guint offset = 0;
subtree = proto_tree_add_subtree(tree, tvb, offset, 3, ett_ieee802154_cmd, NULL,
val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
short_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_ieee802154_assoc_addr, tvb, offset, 2, short_addr);
offset += 2;
status = tvb_get_guint8(tvb, offset);
if (tree) {
ti = proto_tree_add_uint(subtree, hf_ieee802154_assoc_status, tvb, offset, 1, status);
if (status == IEEE802154_CMD_ASRSP_AS_SUCCESS) proto_item_append_text(ti, " (Association Successful)");
else if (status == IEEE802154_CMD_ASRSP_PAN_FULL) proto_item_append_text(ti, " (PAN Full)");
else if (status == IEEE802154_CMD_ASRSP_PAN_DENIED) proto_item_append_text(ti, " (Association Denied)");
else proto_item_append_text(ti, " (Reserved)");
}
offset += 1;
if (status == IEEE802154_CMD_ASRSP_AS_SUCCESS) {
if (packet->src_addr_mode != IEEE802154_FCF_ADDR_SHORT) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", PAN: 0x%04x", packet->dst_pan);
}
if (short_addr != IEEE802154_NO_ADDR16) {
col_append_fstr(pinfo->cinfo, COL_INFO, " Addr: 0x%04x", short_addr);
}
}
else {
col_append_str(pinfo->cinfo, COL_INFO, ", Unsuccessful");
}
if ((status == IEEE802154_CMD_ASRSP_AS_SUCCESS) && (short_addr != IEEE802154_NO_ADDR16)) {
ieee802154_addr_update(&ieee802154_map, short_addr, packet->dst_pan, packet->dst64,
pinfo->current_proto, pinfo->num);
}
if (tvb_captured_length(tvb) > offset) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
}
static void
dissect_ieee802154_disassoc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
proto_tree *subtree;
proto_item *ti;
guint8 reason;
subtree = proto_tree_add_subtree(tree, tvb, 0, 1, ett_ieee802154_cmd, NULL,
val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
reason = tvb_get_guint8(tvb, 0);
if (tree) {
ti = proto_tree_add_uint(subtree, hf_ieee802154_disassoc_reason, tvb, 0, 1, reason);
switch(reason) {
case 0x01:
proto_item_append_text(ti, " (Coordinator requests device to leave)");
break;
case 0x02:
proto_item_append_text(ti, " (Device wishes to leave)");
break;
default:
proto_item_append_text(ti, " (Reserved)");
break;
}
}
if (!pinfo->fd->flags.visited) {
if ( packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT ) {
ieee802154_long_addr_invalidate(packet->dst64, pinfo->num);
} else if ( packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT ) {
ieee802154_short_addr_invalidate(packet->dst16, packet->dst_pan, pinfo->num);
}
}
if (tvb_captured_length(tvb) > 1) {
call_data_dissector(tvb_new_subset_remaining(tvb, 1), pinfo, tree);
}
}
static void
dissect_ieee802154_realign(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
proto_tree *subtree;
proto_item *subitem;
guint16 pan_id;
guint16 coord_addr;
guint8 channel;
guint16 short_addr;
guint offset = 0;
subtree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_ieee802154_cmd, &subitem,
val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
pan_id = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_ieee802154_realign_pan, tvb, offset, 2, pan_id);
col_append_fstr(pinfo->cinfo, COL_INFO, ", PAN: 0x%04x", pan_id);
offset += 2;
coord_addr = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(subtree, hf_ieee802154_realign_caddr, tvb, offset, 2, coord_addr);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Coordinator: 0x%04x", coord_addr);
offset += 2;
channel = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(subtree, hf_ieee802154_realign_channel, tvb, offset, 1, channel);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Channel: %u", channel);
offset += 1;
short_addr = tvb_get_letohs(tvb, offset);
if (tree) proto_tree_add_uint(subtree, hf_ieee802154_realign_addr, tvb, offset, 2, short_addr);
if ((packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT)
&& (short_addr != IEEE802154_NO_ADDR16)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Addr: 0x%04x", short_addr);
}
offset += 2;
if ((short_addr != IEEE802154_NO_ADDR16) && (packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT)) {
ieee802154_addr_update(&ieee802154_map, short_addr, packet->dst_pan, packet->dst64,
pinfo->current_proto, pinfo->num);
}
if (tvb_bytes_exist(tvb, offset, 1)) {
guint8 channel_page = tvb_get_guint8(tvb, offset);
if (tree) proto_tree_add_uint(subtree, hf_ieee802154_realign_channel_page, tvb, offset, 1, channel_page);
offset += 1;
}
if (tree) {
proto_item_set_len(subitem, offset);
}
if (tvb_captured_length(tvb) > offset) {
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, tree);
}
}
static void
dissect_ieee802154_gtsreq(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
proto_tree *subtree;
static const int * characteristics[] = {
&hf_ieee802154_gtsreq_len,
&hf_ieee802154_gtsreq_dir,
&hf_ieee802154_gtsreq_type,
NULL
};
subtree = proto_tree_add_subtree(tree, tvb, 0, 1, ett_ieee802154_cmd, NULL,
val_to_str_const(packet->command_id, ieee802154_cmd_names, "Unknown Command"));
proto_tree_add_bitmask_list(subtree, tvb, 0, 1, characteristics, ENC_NA);
if (tvb_reported_length(tvb) > 1) {
call_data_dissector(tvb_new_subset_remaining(tvb, 1), pinfo, tree);
}
}
static void
dissect_ieee802154_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, ieee802154_packet *packet)
{
switch (packet->command_id) {
case IEEE802154_CMD_ASSOC_REQ:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE));
dissect_ieee802154_assoc_req(tvb, pinfo, tree, packet);
break;
case IEEE802154_CMD_ASSOC_RSP:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT));
dissect_ieee802154_assoc_rsp(tvb, pinfo, tree, packet);
break;
case IEEE802154_CMD_DISASSOC_NOTIFY:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT));
dissect_ieee802154_disassoc(tvb, pinfo, tree, packet);
return;
case IEEE802154_CMD_DATA_RQ:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id, packet->src_addr_mode != IEEE802154_FCF_ADDR_NONE);
break;
case IEEE802154_CMD_PANID_CONFLICT:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT));
break;
case IEEE802154_CMD_ORPHAN_NOTIFY:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->dst16 == IEEE802154_BCAST_ADDR) &&
(packet->src_pan == IEEE802154_BCAST_PAN) &&
(packet->dst_pan == IEEE802154_BCAST_PAN));
break;
case IEEE802154_CMD_BEACON_REQ:
if ((packet->version == IEEE802154_VERSION_2003) || (packet->version == IEEE802154_VERSION_2006)) {
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->src_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->dst16 == IEEE802154_BCAST_ADDR) &&
(packet->dst_pan == IEEE802154_BCAST_PAN));
}
break;
case IEEE802154_CMD_COORD_REALIGN:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) &&
(packet->dst_pan == IEEE802154_BCAST_PAN) &&
(packet->dst_addr_mode != IEEE802154_FCF_ADDR_NONE));
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT) {
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id, packet->dst16 == IEEE802154_BCAST_ADDR);
}
dissect_ieee802154_realign(tvb, pinfo, tree, packet);
return;
case IEEE802154_CMD_GTS_REQ:
IEEE802154_CMD_ADDR_CHECK(pinfo, tree, packet->command_id,
(packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) &&
(packet->dst_addr_mode == IEEE802154_FCF_ADDR_NONE) &&
(packet->src16 != IEEE802154_BCAST_ADDR) &&
(packet->src16 != IEEE802154_NO_ADDR16));
dissect_ieee802154_gtsreq(tvb, pinfo, tree, packet);
return;
case IEEE802154_CMD_TRLE_MGMT_REQ:
case IEEE802154_CMD_TRLE_MGMT_RSP:
case IEEE802154_CMD_DSME_ASSOC_REQ:
case IEEE802154_CMD_DSME_ASSOC_RSP:
case IEEE802154_CMD_DSME_GTS_REQ:
case IEEE802154_CMD_DSME_GTS_RSP:
case IEEE802154_CMD_DSME_GTS_NOTIFY:
case IEEE802154_CMD_DSME_INFO_REQ:
case IEEE802154_CMD_DSME_INFO_RSP:
case IEEE802154_CMD_DSME_BEACON_ALLOC_NOTIFY:
case IEEE802154_CMD_DSME_BEACON_COLL_NOTIFY:
case IEEE802154_CMD_DSME_LINK_REPORT:
case IEEE802154_CMD_RIT_DATA_REQ:
case IEEE802154_CMD_DBS_REQ:
case IEEE802154_CMD_DBS_RSP:
if (tvb_captured_length_remaining(tvb, 0) > 2) {
call_data_dissector(tvb, pinfo, tree);
}
return;
}
}
static tvbuff_t *
dissect_ieee802154_decrypt(tvbuff_t *tvb, guint offset, packet_info *pinfo, ieee802154_packet *packet, ws_decrypt_status *status)
{
tvbuff_t *ptext_tvb;
gboolean have_mic = FALSE;
guint64 srcAddr;
unsigned char key[16];
unsigned char tmp[16];
unsigned char rx_mic[16];
guint M;
gint captured_len;
gint reported_len;
ieee802154_hints_t *ieee_hints;
if ((packet->version != IEEE802154_VERSION_2006) && (packet->version != IEEE802154_VERSION_2003)) {
*status = DECRYPT_VERSION_UNSUPPORTED;
return NULL;
}
ieee_hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ieee802154, 0);
M = IEEE802154_MIC_LENGTH(packet->security_level);
reported_len = tvb_reported_length_remaining(tvb, offset) - IEEE802154_FCS_LEN - M;
if (reported_len < 0) {
*status = DECRYPT_PACKET_TOO_SMALL;
return NULL;
}
if (tvb_bytes_exist(tvb, offset, reported_len)) {
captured_len = reported_len;
}
else {
captured_len = tvb_captured_length_remaining(tvb, offset);
}
have_mic = tvb_bytes_exist(tvb, offset + reported_len, M);
if (have_mic) {
tvb_memcpy(tvb, rx_mic, offset + reported_len, M);
}
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_EXT) {
srcAddr = packet->src64;
}
else if (ieee_hints && ieee_hints->map_rec && ieee_hints->map_rec->addr64) {
srcAddr = ieee_hints->map_rec->addr64;
}
else {
*status = DECRYPT_PACKET_NO_EXT_SRC_ADDR;
return NULL;
}
if (!ieee802154_key_valid) {
*status = DECRYPT_PACKET_NO_KEY;
return NULL;
}
memcpy(key, ieee802154_key, IEEE802154_CIPHER_SIZE);
ccm_init_block(tmp, FALSE, 0, srcAddr, packet, 0);
if (IEEE802154_IS_ENCRYPTED(packet->security_level) && captured_len) {
guint8 *text;
text = (guint8 *)tvb_memdup(pinfo->pool, tvb, offset, captured_len);
if (!ccm_ctr_encrypt(key, tmp, rx_mic, text, captured_len)) {
g_free(text);
*status = DECRYPT_PACKET_DECRYPT_FAILED;
return NULL;
}
ptext_tvb = tvb_new_child_real_data(tvb, text, captured_len, reported_len);
add_new_data_source(pinfo, ptext_tvb, "Decrypted IEEE 802.15.4 payload");
*status = DECRYPT_PACKET_SUCCEEDED;
}
else {
if ((have_mic) && (!ccm_ctr_encrypt(key, tmp, rx_mic, NULL, 0))) {
*status = DECRYPT_PACKET_DECRYPT_FAILED;
return NULL;
}
ptext_tvb = tvb_new_subset(tvb, offset, captured_len, reported_len);
*status = DECRYPT_PACKET_SUCCEEDED;
}
if (have_mic) {
unsigned char dec_mic[16];
guint l_m = captured_len;
guint l_a = offset;
if (!IEEE802154_IS_ENCRYPTED(packet->security_level)) {
l_a += l_m;
l_m = 0;
}
else if ((packet->version == IEEE802154_VERSION_2003) && !ieee802154_extend_auth)
l_a -= 5;
ccm_init_block(tmp, TRUE, M, srcAddr, packet, l_m);
if (!ccm_cbc_mac(key, tmp, (const gchar *)tvb_memdup(wmem_packet_scope(), tvb, 0, l_a), l_a, tvb_get_ptr(ptext_tvb, 0, l_m), l_m, dec_mic)) {
*status = DECRYPT_PACKET_MIC_CHECK_FAILED;
}
else if (memcmp(rx_mic, dec_mic, M) != 0) {
*status = DECRYPT_PACKET_MIC_CHECK_FAILED;
}
}
return ptext_tvb;
}
static void
ccm_init_block(gchar *block, gboolean adata, gint M, guint64 addr, ieee802154_packet *packet, gint ctr_val)
{
gint i = 0;
block[i] = (0x2 - 1);
if (M > 0) block[i] |= (((M-2)/2) << 3);
if (adata) block[i] |= (1 << 6);
i++;
block[i++] = (guint8)((addr >> 56) & 0xff);
block[i++] = (guint8)((addr >> 48) & 0xff);
block[i++] = (guint8)((addr >> 40) & 0xff);
block[i++] = (guint8)((addr >> 32) & 0xff);
block[i++] = (guint8)((addr >> 24) & 0xff);
block[i++] = (guint8)((addr >> 16) & 0xff);
block[i++] = (guint8)((addr >> 8) & 0xff);
block[i++] = (guint8)((addr >> 0) & 0xff);
block[i++] = (guint8)((packet->frame_counter >> 24) & 0xff);
block[i++] = (guint8)((packet->frame_counter >> 16) & 0xff);
block[i++] = (guint8)((packet->frame_counter >> 8) & 0xff);
block[i++] = (guint8)((packet->frame_counter >> 0) & 0xff);
if (packet->version == IEEE802154_VERSION_2003)
block[i++] = packet->key_sequence_counter;
else
block[i++] = packet->security_level;
block[i++] = (guint8)((ctr_val >> 8) & 0xff);
block[i] = (guint8)((ctr_val >> 0) & 0xff);
}
static gboolean
ccm_ctr_encrypt(const gchar *key, const gchar *iv, gchar *mic, gchar *data, gint length)
{
gcry_cipher_hd_t cipher_hd;
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CTR, 0)) {
return FALSE;
}
if (gcry_cipher_setkey(cipher_hd, key, 16)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_setctr(cipher_hd, iv, 16)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_encrypt(cipher_hd, mic, 16, NULL, 0)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_encrypt(cipher_hd, data, length, NULL, 0)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
gcry_cipher_close(cipher_hd);
return TRUE;
}
static gboolean
ccm_ctr_encrypt(const gchar *key _U_, const gchar *iv _U_, gchar *mic _U_, gchar *data _U_, gint length _U_)
{
return FALSE;
}
static gboolean
ccm_cbc_mac(const gchar *key, const gchar *iv, const gchar *a, gint a_len, const gchar *m, gint m_len, gchar *mic)
{
gcry_cipher_hd_t cipher_hd;
guint i = 0;
unsigned char block[16];
if (gcry_cipher_open(&cipher_hd, GCRY_CIPHER_AES128, GCRY_CIPHER_MODE_CBC, GCRY_CIPHER_CBC_MAC)) return FALSE;
if (gcry_cipher_setkey(cipher_hd, key, 16)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
if (gcry_cipher_encrypt(cipher_hd, mic, 16, iv, 16)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
i = 0;
#if (GINT_MAX >= (1LL << 32))
if (a_len >= (1LL << 32)) {
block[i++] = 0xff;
block[i++] = 0xff;
block[i++] = (a_len >> 56) & 0xff;
block[i++] = (a_len >> 48) & 0xff;
block[i++] = (a_len >> 40) & 0xff;
block[i++] = (a_len >> 32) & 0xff;
block[i++] = (a_len >> 24) & 0xff;
block[i++] = (a_len >> 16) & 0xff;
block[i++] = (a_len >> 8) & 0xff;
block[i++] = (a_len >> 0) & 0xff;
}
else
#endif
if (a_len >= ((1 << 16) - (1 << 8))) {
block[i++] = 0xff;
block[i++] = 0xfe;
block[i++] = (a_len >> 24) & 0xff;
block[i++] = (a_len >> 16) & 0xff;
block[i++] = (a_len >> 8) & 0xff;
block[i++] = (a_len >> 0) & 0xff;
}
else {
block[i++] = (a_len >> 8) & 0xff;
block[i++] = (a_len >> 0) & 0xff;
}
while ((i < sizeof(block)) && (a_len-- > 0)) block[i++] = *a++;
while (i < sizeof(block)) block[i++] = 0;
if (gcry_cipher_encrypt(cipher_hd, mic, 16, block, 16)) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
while (a_len > 0) {
if ((guint)a_len >= sizeof(block)) memcpy(block, a, sizeof(block));
else {memcpy(block, a, a_len); memset(block+a_len, 0, sizeof(block)-a_len);}
a += sizeof(block);
a_len -= (int)sizeof(block);
if (gcry_cipher_encrypt(cipher_hd, mic, 16, block, sizeof(block))) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
}
while (m_len > 0) {
if ((guint)m_len >= sizeof(block)) memcpy(block, m, sizeof(block));
else {memcpy(block, m, m_len); memset(block+m_len, 0, sizeof(block)-m_len);}
m += sizeof(block);
m_len -= (int)sizeof(block);
if (gcry_cipher_encrypt(cipher_hd, mic, 16, block, sizeof(block))) {
gcry_cipher_close(cipher_hd);
return FALSE;
}
}
gcry_cipher_close(cipher_hd);
return TRUE;
}
static gboolean
ccm_cbc_mac(const gchar *key _U_, const gchar *iv _U_,
const gchar *a _U_, gint a_len _U_, const gchar *m _U_, gint m_len _U_, gchar *mic _U_)
{
return FALSE;
}
guint ieee802154_short_addr_hash(gconstpointer key)
{
return (((const ieee802154_short_addr *)key)->addr) | (((const ieee802154_short_addr *)key)->pan << 16);
}
gboolean ieee802154_short_addr_equal(gconstpointer a, gconstpointer b)
{
return (((const ieee802154_short_addr *)a)->pan == ((const ieee802154_short_addr *)b)->pan) &&
(((const ieee802154_short_addr *)a)->addr == ((const ieee802154_short_addr *)b)->addr);
}
guint ieee802154_long_addr_hash(gconstpointer key)
{
return (guint)(((const ieee802154_long_addr *)key)->addr) & 0xFFFFFFFF;
}
gboolean ieee802154_long_addr_equal(gconstpointer a, gconstpointer b)
{
return (((const ieee802154_long_addr *)a)->addr == ((const ieee802154_long_addr *)b)->addr);
}
ieee802154_map_rec *ieee802154_addr_update(ieee802154_map_tab_t *au_ieee802154_map,
guint16 short_addr, guint16 pan, guint64 long_addr, const char *proto, guint fnum)
{
ieee802154_short_addr addr16;
ieee802154_map_rec *p_map_rec;
gpointer old_key;
addr16.pan = pan;
addr16.addr = short_addr;
p_map_rec = (ieee802154_map_rec *)g_hash_table_lookup(au_ieee802154_map->short_table, &addr16);
if (p_map_rec) {
if ( p_map_rec->addr64 == long_addr ) {
return p_map_rec;
}
else {
p_map_rec->end_fnum = fnum;
}
}
p_map_rec = wmem_new(wmem_file_scope(), ieee802154_map_rec);
p_map_rec->proto = proto;
p_map_rec->start_fnum = fnum;
p_map_rec->end_fnum = 0;
p_map_rec->addr64 = long_addr;
if ( g_hash_table_lookup_extended(au_ieee802154_map->short_table, &addr16, &old_key, NULL) ) {
g_hash_table_insert(au_ieee802154_map->short_table, old_key, p_map_rec);
} else {
g_hash_table_insert(au_ieee802154_map->short_table, wmem_memdup(wmem_file_scope(), &addr16, sizeof(addr16)), p_map_rec);
}
if ( g_hash_table_lookup_extended(au_ieee802154_map->long_table, &long_addr, &old_key, NULL) ) {
g_hash_table_insert(au_ieee802154_map->long_table, old_key, p_map_rec);
} else {
g_hash_table_insert(au_ieee802154_map->long_table, wmem_memdup(wmem_file_scope(), &long_addr, sizeof(long_addr)), p_map_rec);
}
return p_map_rec;
}
gboolean ieee802154_short_addr_invalidate(guint16 short_addr, guint16 pan, guint fnum)
{
ieee802154_short_addr addr16;
ieee802154_map_rec *map_rec;
addr16.pan = pan;
addr16.addr = short_addr;
map_rec = (ieee802154_map_rec *)g_hash_table_lookup(ieee802154_map.short_table, &addr16);
if ( map_rec ) {
map_rec->end_fnum = fnum;
return TRUE;
}
return FALSE;
}
gboolean ieee802154_long_addr_invalidate(guint64 long_addr, guint fnum)
{
ieee802154_map_rec *map_rec;
map_rec = (ieee802154_map_rec *)g_hash_table_lookup(ieee802154_map.long_table, &long_addr);
if ( map_rec ) {
map_rec->end_fnum = fnum;
return TRUE;
}
return FALSE;
}
static void
proto_init_ieee802154(void)
{
guint i;
ieee802154_map.short_table = g_hash_table_new(ieee802154_short_addr_hash, ieee802154_short_addr_equal);
ieee802154_map.long_table = g_hash_table_new(ieee802154_long_addr_hash, ieee802154_long_addr_equal);
for (i=0; (i<num_static_addrs) && (static_addrs); i++) {
ieee802154_addr_update(&ieee802154_map,(guint16)static_addrs[i].addr16, (guint16)static_addrs[i].pan,
pntoh64(static_addrs[i].eui64), ieee802154_user, IEEE802154_USER_MAPPING);
}
}
static void
proto_cleanup_ieee802154(void)
{
g_hash_table_destroy(ieee802154_map.short_table);
g_hash_table_destroy(ieee802154_map.long_table);
}
static void ieee802154_da_prompt(packet_info *pinfo _U_, gchar* result)
{
ieee802154_hints_t *hints;
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints)
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "IEEE 802.15.4 PAN 0x%04x as", hints->src_pan);
else
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "IEEE 802.15.4 PAN Unknown");
}
static gpointer ieee802154_da_value(packet_info *pinfo _U_)
{
ieee802154_hints_t *hints;
hints = (ieee802154_hints_t *)p_get_proto_data(wmem_file_scope(), pinfo,
proto_get_id_by_filter_name(IEEE802154_PROTOABBREV_WPAN), 0);
if (hints)
return GUINT_TO_POINTER((guint)(hints->src_pan));
else
return NULL;
}
void proto_register_ieee802154(void)
{
static hf_register_info hf_phy[] = {
{ &hf_ieee802154_nonask_phy_preamble,
{ "Preamble", "wpan-nonask-phy.preamble", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_nonask_phy_sfd,
{ "Start of Frame Delimiter", "wpan-nonask-phy.sfd", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_nonask_phy_length,
{ "Frame Length", "wpan-nonask-phy.frame_length", FT_UINT8, BASE_HEX, NULL,
IEEE802154_PHY_LENGTH_MASK, NULL, HFILL }},
{ &hf_ieee802154_nonask_phr,
{ "PHR", "wpan-nonask-phy.phr", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
};
static hf_register_info hf[] = {
{ &hf_ieee802154_frame_length,
{ "Frame Length", "wpan.frame_length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Frame Length as reported from lower layer", HFILL }},
{ &hf_ieee802154_fcf,
{ "Frame Control Field", "wpan.fcf", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_frame_type,
{ "Frame Type", "wpan.frame_type", FT_UINT16, BASE_HEX, VALS(ieee802154_frame_types),
IEEE802154_FCF_TYPE_MASK, NULL, HFILL }},
{ &hf_ieee802154_security,
{ "Security Enabled", "wpan.security", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_SEC_EN,
"Whether security operations are performed at the MAC layer or not.", HFILL }},
{ &hf_ieee802154_pending,
{ "Frame Pending", "wpan.pending", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_FRAME_PND,
"Indication of additional packets waiting to be transferred from the source device.", HFILL }},
{ &hf_ieee802154_ack_request,
{ "Acknowledge Request", "wpan.ack_request", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_ACK_REQ,
"Whether the sender of this packet requests acknowledgment or not.", HFILL }},
{ &hf_ieee802154_pan_id_compression,
{ "PAN ID Compression", "wpan.pan_id_compression", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_PAN_ID_COMPRESSION,
"Whether this packet contains the PAN ID or not.", HFILL }},
{ &hf_ieee802154_seqno_suppression,
{ "Sequence Number Suppression", "wpan.seqno_suppression", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_SEQNO_SUPPRESSION,
"Whether this packet contains the Sequence Number or not.", HFILL }},
{ &hf_ieee802154_ie_present,
{ "Information Elements Present", "wpan.ie_present", FT_BOOLEAN, 16, NULL, IEEE802154_FCF_IE_PRESENT,
"Whether this packet contains the Information Elements or not.", HFILL }},
{ &hf_ieee802154_seqno,
{ "Sequence Number", "wpan.seq_no", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_dst_addr_mode,
{ "Destination Addressing Mode", "wpan.dst_addr_mode", FT_UINT16, BASE_HEX, VALS(ieee802154_addr_modes),
IEEE802154_FCF_DADDR_MASK, NULL, HFILL }},
{ &hf_ieee802154_src_addr_mode,
{ "Source Addressing Mode", "wpan.src_addr_mode", FT_UINT16, BASE_HEX, VALS(ieee802154_addr_modes),
IEEE802154_FCF_SADDR_MASK, NULL, HFILL }},
{ &hf_ieee802154_version,
{ "Frame Version", "wpan.version", FT_UINT16, BASE_DEC, VALS(ieee802154_frame_versions),
IEEE802154_FCF_VERSION, NULL, HFILL }},
{ &hf_ieee802154_dst_panID,
{ "Destination PAN", "wpan.dst_pan", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_dst16,
{ "Destination", "wpan.dst16", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_dst64,
{ "Destination", "wpan.dst64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_src_panID,
{ "Source PAN", "wpan.src_pan", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_src16,
{ "Source", "wpan.src16", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_src64,
{ "Extended Source", "wpan.src64", FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_src64_origin,
{ "Origin", "wpan.src64.origin", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_fcs,
{ "FCS", "wpan.fcs", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_rssi,
{ "RSSI", "wpan.rssi", FT_INT8, BASE_DEC, NULL, 0x0,
"Received Signal Strength", HFILL }},
{ &hf_ieee802154_fcs_ok,
{ "FCS Valid", "wpan.fcs_ok", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_correlation,
{ "LQI Correlation Value", "wpan.correlation", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_header_ie,
{ "Header IE", "wpan.header_ie", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_header_ie_type,
{ "Type", "wpan.header_ie.type", FT_UINT16, BASE_DEC, VALS(ieee802154_ie_types),
IEEE802154_HEADER_IE_TYPE_MASK, NULL, HFILL }},
{ &hf_ieee802154_header_ie_id,
{ "Id", "wpan.header_ie.id", FT_UINT16, BASE_HEX, VALS(ieee802154_header_ie_names),
IEEE802154_HEADER_IE_ID_MASK, NULL, HFILL }},
{ &hf_ieee802154_header_ie_length,
{ "Length", "wpan.header_ie.length", FT_UINT16, BASE_DEC, NULL,
IEEE802154_HEADER_IE_LENGTH_MASK, NULL, HFILL }},
{ &hf_ieee802154_header_ie_data,
{ "Data", "wpan.header_ie.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_payload_ie,
{ "Header", "wpan.payload_ie", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_payload_ie_type,
{ "Type", "wpan.payload_ie.type", FT_UINT16, BASE_DEC, VALS(ieee802154_ie_types),
IEEE802154_PAYLOAD_IE_TYPE_MASK, NULL, HFILL }},
{ &hf_ieee802154_payload_ie_id,
{ "Id", "wpan.payload_ie.id", FT_UINT16, BASE_HEX, VALS(ieee802154_payload_ie_names),
IEEE802154_PAYLOAD_IE_ID_MASK, NULL, HFILL }},
{ &hf_ieee802154_payload_ie_length,
{ "Length", "wpan.payload_ie.length", FT_UINT16, BASE_DEC, NULL,
IEEE802154_PAYLOAD_IE_LENGTH_MASK, NULL, HFILL }},
{ &hf_ieee802154_psie_short,
{ "Payload Sub IE (short)", "wpan.payload_sub_ie.short", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_psie_type_short,
{ "Type", "wpan.payload_sub_ie.type_short", FT_UINT16, BASE_DEC, VALS(ieee802154_psie_types),
IEEE802154_PSIE_TYPE_MASK, NULL, HFILL }},
{ &hf_ieee802154_psie_id_short,
{ "Sub Id (Short)", "wpan.payload_sub_ie.id_short", FT_UINT16, BASE_HEX, VALS(ieee802154_psie_names),
IEEE802154_PSIE_ID_MASK_SHORT, NULL, HFILL }},
{ &hf_ieee802154_psie_length_short,
{ "Length", "wpan.payload_sub_ie.length_short", FT_UINT16, BASE_DEC, NULL,
IEEE802154_PSIE_LENGTH_MASK_SHORT, NULL, HFILL }},
{ &hf_ieee802154_psie_long,
{ "Payload Sub IE (long)", "wpan.payload_sub_ie.long", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_psie_type_long,
{ "Type", "wpan.payload_sub_ie.type_long", FT_UINT16, BASE_DEC, VALS(ieee802154_psie_types),
IEEE802154_PSIE_TYPE_MASK, NULL, HFILL }},
{ &hf_ieee802154_psie_id_long,
{ "Sub Id (Long)", "wpan.payload_sub_ie.id_long", FT_UINT16, BASE_HEX, NULL,
IEEE802154_PSIE_ID_MASK_LONG, NULL, HFILL }},
{ &hf_ieee802154_psie_length_long,
{ "Length", "wpan.payload_sub_ie.length_long", FT_UINT16, BASE_DEC, NULL,
IEEE802154_PSIE_LENGTH_MASK_LONG, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter,
{ "Enhanced Beacon Filter", "wpan.payload_sub_ie.eb_filter", FT_UINT8, BASE_HEX, NULL,
0, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_pjoin,
{ "Permit Join Filter", "wpan.payload_sub_ie.eb_filter.pjoin", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled),
IEEE802154_MLME_PSIE_EB_FLT_PJOIN, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_lqi,
{ "LQI Filter", "wpan.payload_sub_ie.eb_filter.lqi", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled),
IEEE802154_MLME_PSIE_EB_FLT_LQI, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_lqi_min,
{ "Minimum LQI", "wpan.payload_sub_ie.eb_filter.lqi_minimum", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_percent,
{ "Probability to Respond", "wpan.payload_sub_ie.eb_filter.contains_prob", FT_BOOLEAN, 8, TFS(&tfs_enabled_disabled),
IEEE802154_MLME_PSIE_EB_FLT_PERCENT, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_percent_prob,
{ "Response Probability Percentage", "wpan.payload_sub_ie.eb_filter.prob", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_attr_id,
{ "Requested Attribute Length", "wpan.payload_sub_ie.eb_filter.attr_id", FT_UINT8, BASE_DEC, NULL,
IEEE802154_MLME_PSIE_EB_FLT_ATTR_LEN, NULL, HFILL }},
{ &hf_ieee802154_psie_eb_filter_attr_id_bitmap,
{ "Attribute ID Bitmap", "wpan.payload_sub_ie.eb_filter.attr_id_bits", FT_UINT24, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_payload_ie_data,
{ "Data", "wpan.payload_ie.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_payload_ie_vendor_oui,
{ "Vendor OUI", "wpan.payload_ie.vendor_oui", FT_UINT24, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_mlme_ie_data,
{ "Data", "wpan.mlme_sub_ie.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_ieee802154_cmd_id,
{ "Command Identifier", "wpan.cmd", FT_UINT8, BASE_HEX, VALS(ieee802154_cmd_names), 0x0,
NULL, HFILL }},
{ &hf_ieee802154_cinfo_alt_coord,
{ "Alternate PAN Coordinator", "wpan.cinfo.alt_coord", FT_BOOLEAN, 8, NULL, IEEE802154_CMD_CINFO_ALT_PAN_COORD,
"Whether this device can act as a PAN coordinator or not.", HFILL }},
{ &hf_ieee802154_cinfo_device_type,
{ "Device Type", "wpan.cinfo.device_type", FT_BOOLEAN, 8, TFS(&tfs_cinfo_device_type), IEEE802154_CMD_CINFO_DEVICE_TYPE,
"Whether this device is RFD (reduced-function device) or FFD (full-function device).", HFILL }},
{ &hf_ieee802154_cinfo_power_src,
{ "Power Source", "wpan.cinfo.power_src", FT_BOOLEAN, 8, TFS(&tfs_cinfo_power_src), IEEE802154_CMD_CINFO_POWER_SRC,
"Whether this device is operating on AC/mains or battery power.", HFILL }},
{ &hf_ieee802154_cinfo_idle_rx,
{ "Receive On When Idle", "wpan.cinfo.idle_rx", FT_BOOLEAN, 8, NULL, IEEE802154_CMD_CINFO_IDLE_RX,
"Whether this device can receive packets while idle or not.", HFILL }},
{ &hf_ieee802154_cinfo_sec_capable,
{ "Security Capability", "wpan.cinfo.sec_capable", FT_BOOLEAN, 8, NULL, IEEE802154_CMD_CINFO_SEC_CAPABLE,
"Whether this device is capable of receiving encrypted packets.", HFILL }},
{ &hf_ieee802154_cinfo_alloc_addr,
{ "Allocate Address", "wpan.cinfo.alloc_addr", FT_BOOLEAN, 8, NULL, IEEE802154_CMD_CINFO_ALLOC_ADDR,
"Whether this device wishes to use a 16-bit short address instead of its IEEE 802.15.4 64-bit long address.", HFILL }},
{ &hf_ieee802154_assoc_addr,
{ "Short Address", "wpan.asoc.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"The short address that the device should assume. An address of 0xfffe indicates that the device should use its IEEE 64-bit long address.", HFILL }},
{ &hf_ieee802154_assoc_status,
{ "Association Status", "wpan.assoc.status", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_disassoc_reason,
{ "Disassociation Reason", "wpan.disassoc.reason", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_realign_pan,
{ "PAN ID", "wpan.realign.pan", FT_UINT16, BASE_HEX, NULL, 0x0,
"The PAN identifier the coordinator wishes to use for future communication.", HFILL }},
{ &hf_ieee802154_realign_caddr,
{ "Coordinator Short Address", "wpan.realign.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"The 16-bit address the coordinator wishes to use for future communication.", HFILL }},
{ &hf_ieee802154_realign_channel,
{ "Logical Channel", "wpan.realign.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
"The logical channel the coordinator wishes to use for future communication.", HFILL }},
{ &hf_ieee802154_realign_addr,
{ "Short Address", "wpan.realign.addr", FT_UINT16, BASE_HEX, NULL, 0x0,
"A short-address that the orphaned device shall assume if applicable.", HFILL }},
{ &hf_ieee802154_realign_channel_page,
{ "Channel Page", "wpan.realign.channel_page", FT_UINT8, BASE_DEC, NULL, 0x0,
"The logical channel page the coordinator wishes to use for future communication.", HFILL }},
{ &hf_ieee802154_gtsreq_len,
{ "GTS Length", "wpan.gtsreq.length", FT_UINT8, BASE_DEC, NULL, IEEE802154_CMD_GTS_REQ_LEN,
"Number of superframe slots the device is requesting.", HFILL }},
{ &hf_ieee802154_gtsreq_dir,
{ "GTS Direction", "wpan.gtsreq.direction", FT_BOOLEAN, 8, TFS(&tfs_gtsreq_dir), IEEE802154_CMD_GTS_REQ_DIR,
"The direction of traffic in the guaranteed timeslot.", HFILL }},
{ &hf_ieee802154_gtsreq_type,
{ "Characteristic Type", "wpan.gtsreq.type", FT_BOOLEAN, 8, TFS(&tfs_gtsreq_type), IEEE802154_CMD_GTS_REQ_TYPE,
"Whether this request is to allocate or deallocate a timeslot.", HFILL }},
{ &hf_ieee802154_beacon_order,
{ "Beacon Interval", "wpan.beacon_order", FT_UINT16, BASE_DEC, NULL, IEEE802154_BEACON_ORDER_MASK,
"Specifies the transmission interval of the beacons.", HFILL }},
{ &hf_ieee802154_superframe_order,
{ "Superframe Interval", "wpan.superframe_order", FT_UINT16, BASE_DEC, NULL,
IEEE802154_SUPERFRAME_ORDER_MASK,
"Specifies the length of time the coordinator will interact with the PAN.", HFILL }},
{ &hf_ieee802154_cap,
{ "Final CAP Slot", "wpan.cap", FT_UINT16, BASE_DEC, NULL, IEEE802154_SUPERFRAME_CAP_MASK,
"Specifies the final superframe slot used by the CAP.", HFILL }},
{ &hf_ieee802154_superframe_battery_ext,
{ "Battery Extension", "wpan.battery_ext", FT_BOOLEAN, 16, NULL, IEEE802154_BATT_EXTENSION_MASK,
"Whether transmissions may not extend past the length of the beacon frame.", HFILL }},
{ &hf_ieee802154_superframe_coord,
{ "PAN Coordinator", "wpan.bcn_coord", FT_BOOLEAN, 16, NULL, IEEE802154_SUPERFRAME_COORD_MASK,
"Whether this beacon frame is being transmitted by the PAN coordinator or not.", HFILL }},
{ &hf_ieee802154_assoc_permit,
{ "Association Permit", "wpan.assoc_permit", FT_BOOLEAN, 16, NULL, IEEE802154_ASSOC_PERMIT_MASK,
"Whether this PAN is accepting association requests or not.", HFILL }},
{ &hf_ieee802154_gts_count,
{ "GTS Descriptor Count", "wpan.gts.count", FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of GTS descriptors present in this beacon frame.", HFILL }},
{ &hf_ieee802154_gts_permit,
{ "GTS Permit", "wpan.gts.permit", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Whether the PAN coordinator is accepting GTS requests or not.", HFILL }},
{ &hf_ieee802154_gts_direction,
{ "Direction", "wpan.gts.direction", FT_BOOLEAN, BASE_NONE, TFS(&ieee802154_gts_direction_tfs), 0x0,
"A flag defining the direction of the GTS Slot.", HFILL }},
{ &hf_ieee802154_gts_address,
{ "Address", "wpan.gts.address", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_ieee802154_pending16,
{ "Address", "wpan.pending16", FT_UINT16, BASE_HEX, NULL, 0x0,
"Device with pending data to receive.", HFILL }},
{ &hf_ieee802154_pending64,
{ "Address", "wpan.pending64", FT_EUI64, BASE_NONE, NULL, 0x0,
"Device with pending data to receive.", HFILL }},
{ &hf_ieee802154_security_level,
{ "Security Level", "wpan.aux_sec.sec_level", FT_UINT8, BASE_HEX, VALS(ieee802154_sec_level_names),
IEEE802154_AUX_SEC_LEVEL_MASK, "The Security Level of the frame", HFILL }},
{ &hf_ieee802154_security_control_field,
{ "Security Control Field", "wpan.aux_sec.security_control_field", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_ieee802154_key_id_mode,
{ "Key Identifier Mode", "wpan.aux_sec.key_id_mode", FT_UINT8, BASE_HEX, VALS(ieee802154_key_id_mode_names),
IEEE802154_AUX_KEY_ID_MODE_MASK,
"The scheme to use by the recipient to lookup the key in its key table", HFILL }},
{ &hf_ieee802154_aux_sec_reserved,
{ "Reserved", "wpan.aux_sec.reserved", FT_UINT8, BASE_HEX, NULL, IEEE802154_AUX_KEY_RESERVED_MASK,
NULL, HFILL }},
{ &hf_ieee802154_aux_sec_frame_counter,
{ "Frame Counter", "wpan.aux_sec.frame_counter", FT_UINT32, BASE_DEC, NULL, 0x0,
"Frame counter of the originator of the protected frame", HFILL }},
{ &hf_ieee802154_aux_sec_key_source,
{ "Key Source", "wpan.aux_sec.key_source", FT_UINT64, BASE_HEX, NULL, 0x0,
"Key Source for processing of the protected frame", HFILL }},
{ &hf_ieee802154_aux_sec_key_index,
{ "Key Index", "wpan.aux_sec.key_index", FT_UINT8, BASE_HEX, NULL, 0x0,
"Key Index for processing of the protected frame", HFILL }},
{ &hf_ieee802154_sec_frame_counter,
{ "Frame Counter", "wpan.sec_frame_counter", FT_UINT32, BASE_HEX, NULL, 0x0,
"Frame counter of the originator of the protected frame (802.15.4-2003)", HFILL }},
{ &hf_ieee802154_sec_key_sequence_counter,
{ "Key Sequence Counter", "wpan.sec_key_sequence_counter", FT_UINT8, BASE_HEX, NULL, 0x0,
"Key Sequence counter of the originator of the protected frame (802.15.4-2003)", HFILL }},
{ &zboss_channel,
{ "Channel", "wpan.zboss.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
"Channel number", HFILL }},
{ &zboss_direction,
{ "ZBOSS Direction", "wpan.zboss.direction", FT_UINT8, BASE_HEX, VALS(zboss_direction_names), 0x0,
"ZBOSS Packet Direction", HFILL }},
{ &zboss_trace_number,
{ "Trace number", "wpan.zboss.trace", FT_UINT32, BASE_DEC, NULL, 0x0,
"Trace item number", HFILL }},
};
static gint *ett[] = {
&ett_ieee802154_nonask_phy,
&ett_ieee802154_nonask_phy_phr,
&ett_ieee802154,
&ett_ieee802154_fcf,
&ett_ieee802154_auxiliary_security,
&ett_ieee802154_aux_sec_control,
&ett_ieee802154_aux_sec_key_id,
&ett_ieee802154_fcs,
&ett_ieee802154_cmd,
&ett_ieee802154_superframe,
&ett_ieee802154_gts,
&ett_ieee802154_gts_direction,
&ett_ieee802154_gts_descriptors,
&ett_ieee802154_pendaddr,
&ett_ieee802154_header,
&ett_ieee802154_header_ie,
&ett_ieee802154_payload,
&ett_ieee802154_payload_ie,
&ett_ieee802154_psie_short,
&ett_ieee802154_psie_short_bitmap,
&ett_ieee802154_psie_long,
&ett_ieee802154_psie_long_bitmap,
&ett_ieee802154_psie_enh_beacon_flt,
&ett_ieee802154_psie_enh_beacon_flt_bitmap,
&ett_ieee802154_zigbee,
&ett_ieee802154_zboss,
};
static ei_register_info ei[] = {
{ &ei_ieee802154_invalid_addressing, { "wpan.invalid_addressing", PI_MALFORMED, PI_WARN,
"Invalid Addressing", EXPFILL }},
#if 0
{ &ei_ieee802154_invalid_panid_compression, { "wpan.invalid_panid_compression", PI_MALFORMED, PI_ERROR,
"Invalid Setting for PAN ID Compression", EXPFILL }},
#endif
{ &ei_ieee802154_invalid_panid_compression2, { "wpan.seqno_supression_fv2_invalid", PI_MALFORMED, PI_WARN,
"Invalid Pan ID Compression and addressing combination for Frame Version 2", EXPFILL }},
{ &ei_ieee802154_dst, { "wpan.dst_invalid", PI_MALFORMED, PI_ERROR,
"Invalid Destination Address Mode", EXPFILL }},
{ &ei_ieee802154_src, { "wpan.src_invalid", PI_MALFORMED, PI_ERROR,
"Invalid Source Address Mode", EXPFILL }},
{ &ei_ieee802154_frame_ver, { "wpan.frame_version_unknown", PI_MALFORMED, PI_ERROR,
"Frame Version Unknown Cannot Dissect", EXPFILL }},
#if 0
{ &ei_ieee802154_frame_type, { "wpan.frame_type_unknown", PI_MALFORMED, PI_ERROR,
"Frame Type Unknown Cannot Dissect", EXPFILL }},
#endif
{ &ei_ieee802154_decrypt_error, { "wpan.decrypt_error", PI_UNDECODED, PI_WARN,
"Decryption error", EXPFILL }},
{ &ei_ieee802154_fcs, { "wpan.fcs.bad", PI_CHECKSUM, PI_WARN,
"Bad FCS", EXPFILL }},
{ &ei_ieee802154_seqno_suppression, { "wpan.seqno_supression_invalid", PI_MALFORMED, PI_WARN,
"Sequence Number Suppression invalid for 802.15.4-2003 and 2006", EXPFILL }},
};
module_t *ieee802154_module;
expert_module_t* expert_ieee802154;
static uat_field_t addr_uat_flds[] = {
UAT_FLD_HEX(addr_uat,addr16,"Short Address",
"16-bit short address in hexadecimal."),
UAT_FLD_HEX(addr_uat,pan,"PAN Identifier",
"16-bit PAN identifier in hexadecimal."),
UAT_FLD_BUFFER(addr_uat,eui64,"EUI-64",
"64-bit extended unique identifier."),
UAT_END_FIELDS
};
static build_valid_func ieee802154_da_build_value[1] = {ieee802154_da_value};
static decode_as_value_t ieee802154_da_values = {ieee802154_da_prompt, 1, ieee802154_da_build_value};
static decode_as_t ieee802154_da = {
IEEE802154_PROTOABBREV_WPAN, "PAN", IEEE802154_PROTOABBREV_WPAN_PANID,
1, 0, &ieee802154_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL
};
register_init_routine(proto_init_ieee802154);
register_cleanup_routine(proto_cleanup_ieee802154);
proto_ieee802154 = proto_register_protocol("IEEE 802.15.4 Low-Rate Wireless PAN", "IEEE 802.15.4",
IEEE802154_PROTOABBREV_WPAN);
proto_ieee802154_nonask_phy = proto_register_protocol("IEEE 802.15.4 Low-Rate Wireless PAN non-ASK PHY",
"IEEE 802.15.4 non-ASK PHY", "wpan-nonask-phy");
proto_zboss = proto_register_protocol("ZBOSS IEEE 802.15.4 dump",
"ZBOSS dump", "wpan-zboss");
proto_register_field_array(proto_ieee802154, hf, array_length(hf));
proto_register_field_array(proto_ieee802154, hf_phy, array_length(hf_phy));
proto_register_subtree_array(ett, array_length(ett));
expert_ieee802154 = expert_register_protocol(proto_ieee802154);
expert_register_field_array(expert_ieee802154, ei, array_length(ei));
ieee802_15_4_short_address_type = address_type_dissector_register("AT_IEEE_802_15_4_SHORT", "IEEE 802.15.4 16-bit short address",
ieee802_15_4_short_address_to_str, ieee802_15_4_short_address_str_len, NULL, ieee802_15_4_short_address_len, NULL, NULL);
ieee802154_module = prefs_register_protocol(proto_ieee802154,
proto_reg_handoff_ieee802154);
prefs_register_uint_preference(ieee802154_module, "802154_ethertype",
"802.15.4 Ethertype (in hex)",
"(Hexadecimal) Ethertype used to indicate IEEE 802.15.4 frame.",
16, &ieee802154_ethertype);
prefs_register_bool_preference(ieee802154_module, "802154_cc24xx",
"TI CC24xx FCS format",
"Set if the FCS field is in TI CC24xx format.",
&ieee802154_cc24xx);
prefs_register_bool_preference(ieee802154_module, "802154_fcs_ok",
"Dissect only good FCS",
"Dissect payload only if FCS is valid.",
&ieee802154_fcs_ok);
static_addr_uat = uat_new("Static Addresses",
sizeof(static_addr_t),
"802154_addresses",
TRUE,
&static_addrs,
&num_static_addrs,
UAT_AFFECTS_DISSECTION,
NULL,
NULL,
addr_uat_update_cb,
NULL,
NULL,
addr_uat_flds);
prefs_register_uat_preference(ieee802154_module, "static_addr",
"Static Addresses",
"A table of static address mappings between 16-bit short addressing and EUI-64 addresses",
static_addr_uat);
prefs_register_string_preference(ieee802154_module, "802154_key", "Decryption key",
"128-bit decryption key in hexadecimal format", (const char **)&ieee802154_key_str);
prefs_register_enum_preference(ieee802154_module, "802154_sec_suite",
"Security Suite (802.15.4-2003)",
"Specifies the security suite to use for 802.15.4-2003 secured frames"
" (only supported suites are listed). Option ignored for 802.15.4-2006"
" and unsecured frames.",
&ieee802154_sec_suite, ieee802154_2003_sec_suite_enums, FALSE);
prefs_register_bool_preference(ieee802154_module, "802154_extend_auth",
"Extend authentication data (802.15.4-2003)",
"Set if the manufacturer extends the authentication data with the"
" security header. Option ignored for 802.15.4-2006 and unsecured frames.",
&ieee802154_extend_auth);
panid_dissector_table = register_dissector_table(IEEE802154_PROTOABBREV_WPAN_PANID, "IEEE 802.15.4 PANID", proto_ieee802154, FT_UINT16, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
ieee802154_heur_subdissector_list = register_heur_dissector_list(IEEE802154_PROTOABBREV_WPAN, proto_ieee802154);
ieee802154_beacon_subdissector_list = register_heur_dissector_list(IEEE802154_PROTOABBREV_WPAN_BEACON, proto_ieee802154);
register_dissector(IEEE802154_PROTOABBREV_WPAN, dissect_ieee802154, proto_ieee802154);
register_dissector("wpan_nofcs", dissect_ieee802154_nofcs, proto_ieee802154);
register_dissector("wpan_cc24xx", dissect_ieee802154_cc24xx, proto_ieee802154);
register_dissector("wpan-nonask-phy", dissect_ieee802154_nonask_phy, proto_ieee802154_nonask_phy);
register_decode_as(&ieee802154_da);
}
void proto_reg_handoff_ieee802154(void)
{
static gboolean prefs_initialized = FALSE;
static dissector_handle_t ieee802154_handle;
static dissector_handle_t ieee802154_nonask_phy_handle;
static dissector_handle_t ieee802154_nofcs_handle;
static unsigned int old_ieee802154_ethertype;
GByteArray *bytes;
gboolean res;
if (!prefs_initialized){
ieee802154_handle = find_dissector(IEEE802154_PROTOABBREV_WPAN);
ieee802154_nonask_phy_handle = find_dissector("wpan-nonask-phy");
ieee802154_nofcs_handle = find_dissector("wpan_nofcs");
zigbee_beacon_handle = find_dissector_add_dependency("zbee_beacon", proto_ieee802154);
zigbee_ie_handle = find_dissector_add_dependency("zbee_ie", proto_ieee802154);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE802_15_4, ieee802154_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE802_15_4_NONASK_PHY, ieee802154_nonask_phy_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_IEEE802_15_4_NOFCS, ieee802154_nofcs_handle);
dissector_add_uint("sll.ltype", LINUX_SLL_P_IEEE802154, ieee802154_handle);
prefs_initialized = TRUE;
} else {
dissector_delete_uint("ethertype", old_ieee802154_ethertype, ieee802154_handle);
}
old_ieee802154_ethertype = ieee802154_ethertype;
bytes = g_byte_array_new();
res = hex_str_to_bytes(ieee802154_key_str, bytes, FALSE);
ieee802154_key_valid = (res && bytes->len >= IEEE802154_CIPHER_SIZE);
if (ieee802154_key_valid) {
memcpy(ieee802154_key, bytes->data, IEEE802154_CIPHER_SIZE);
}
g_byte_array_free(bytes, TRUE);
dissector_add_uint("ethertype", ieee802154_ethertype, ieee802154_handle);
}
