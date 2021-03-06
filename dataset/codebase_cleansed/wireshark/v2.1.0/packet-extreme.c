static int
dissect_tlv_header(tvbuff_t *tvb, packet_info *pinfo _U_, int offset, int length _U_, proto_tree *tree)
{
proto_tree *tlv_tree;
guint8 tlv_marker;
guint8 tlv_type;
guint16 tlv_length;
tlv_marker = tvb_get_guint8(tvb, offset),
tlv_type = tvb_get_guint8(tvb, offset + 1);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4,
ett_edp_tlv_header, NULL, "Marker 0x%02x, length %d, type %d = %s",
tlv_marker, tlv_length, tlv_type,
val_to_str(tlv_type, edp_type_vals, "Unknown (0x%02x)"));
proto_tree_add_item(tlv_tree, hf_edp_tlv_marker, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_uint(tlv_tree, hf_edp_tlv_type, tvb, offset, 1,
tlv_type);
offset += 1;
proto_tree_add_uint(tlv_tree, hf_edp_tlv_length, tvb, offset, 2,
tlv_length);
offset += 2;
return offset;
}
static void
dissect_display_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *display_item;
proto_tree *display_tree;
guint8 *display_name;
display_item = proto_tree_add_item(tree, hf_edp_display,
tvb, offset, length, ENC_BIG_ENDIAN);
display_tree = proto_item_add_subtree(display_item, ett_edp_display);
dissect_tlv_header(tvb, pinfo, offset, 4, display_tree);
offset += 4;
length -= 4;
display_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
proto_item_append_text(display_item, ": \"%s\"",
format_text(display_name, strlen(display_name)));
proto_tree_add_string(display_tree, hf_edp_display_string, tvb, offset, length,
display_name);
}
static int
dissect_null_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *null_item;
proto_tree *null_tree;
null_item = proto_tree_add_protocol_format(tree, hf_edp_null,
tvb, offset, length, "Null");
null_tree = proto_item_add_subtree(null_item, ett_edp_null);
dissect_tlv_header(tvb, pinfo, offset, 4, null_tree);
offset += 4;
return offset;
}
static int
dissect_info_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_tree *ver_tree;
guint8 major1, major2, sustaining, internal;
guint16 port, slot;
proto_item *info_item;
proto_tree *info_tree;
slot = tvb_get_ntohs(tvb, offset + 0 + 4) + 1;
port = tvb_get_ntohs(tvb, offset + 2 + 4) + 1;
major1 = tvb_get_guint8(tvb, offset + 12 + 4);
major2 = tvb_get_guint8(tvb, offset + 13 + 4);
sustaining = tvb_get_guint8(tvb, offset + 14 + 4);
internal = tvb_get_guint8(tvb, offset + 15 + 4);
info_item = proto_tree_add_protocol_format(tree, hf_edp_info,
tvb, offset, length,
"Info: Slot/Port: %d/%d, Version: %d.%d.%d.%d",
slot, port, major1, major2, sustaining, internal);
info_tree = proto_item_add_subtree(info_item, ett_edp_info);
dissect_tlv_header(tvb, pinfo, offset, 4, info_tree);
offset += 4;
proto_tree_add_uint(info_tree, hf_edp_info_slot, tvb, offset, 2,
slot);
offset += 2;
proto_tree_add_uint(info_tree, hf_edp_info_port, tvb, offset, 2,
port);
offset += 2;
proto_tree_add_item(info_tree, hf_edp_info_vchassid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(info_tree, hf_edp_info_reserved, tvb, offset, 6,
ENC_NA);
offset += 6;
ver_tree = proto_tree_add_subtree_format(info_tree, tvb, offset, 4,
ett_edp_info_version, NULL, "Version: %u.%u.%u Internal: %u", major1, major2,
sustaining, internal);
proto_tree_add_item(ver_tree, hf_edp_info_version, tvb, offset, 4,
ENC_BIG_ENDIAN);
proto_tree_add_uint(ver_tree, hf_edp_info_version_major1, tvb, offset, 1,
major1);
offset += 1;
proto_tree_add_uint(ver_tree, hf_edp_info_version_major2, tvb, offset, 1,
major2);
offset += 1;
proto_tree_add_uint(ver_tree, hf_edp_info_version_sustaining, tvb, offset, 1,
sustaining);
offset += 1;
proto_tree_add_uint(ver_tree, hf_edp_info_version_internal, tvb, offset, 1,
internal);
offset += 1;
proto_tree_add_item(info_tree, hf_edp_info_vchassconn, tvb, offset, 16,
ENC_NA);
offset += 16;
return offset;
}
static int
dissect_vlan_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *flags_item;
proto_tree *flags_tree;
proto_item *vlan_item;
proto_tree *vlan_tree;
guint16 vlan_id;
guint8 *vlan_name;
vlan_item = proto_tree_add_item(tree, hf_edp_vlan, tvb,
offset, length, ENC_BIG_ENDIAN);
vlan_tree = proto_item_add_subtree(vlan_item, ett_edp_vlan);
dissect_tlv_header(tvb, pinfo, offset, 4, vlan_tree);
offset += 4;
length -= 4;
if (length < 1) {
expert_add_info(pinfo, vlan_item, &ei_edp_short_tlv);
return offset;
}
flags_item = proto_tree_add_item(vlan_tree, hf_edp_vlan_flags, tvb, offset, 1,
ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_edp_vlan_flags);
proto_tree_add_item(flags_tree, hf_edp_vlan_flags_ip, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_edp_vlan_flags_reserved, tvb, offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_edp_vlan_flags_unknown, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
if (length < 1) {
expert_add_info(pinfo, vlan_item, &ei_edp_short_tlv);
return offset;
}
proto_tree_add_item(vlan_tree, hf_edp_vlan_reserved1, tvb, offset, 1,
ENC_NA);
offset += 1;
length -= 1;
if (length < 2) {
expert_add_info(pinfo, vlan_item, &ei_edp_short_tlv);
return offset;
}
vlan_id = tvb_get_ntohs(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%d", vlan_id);
proto_item_append_text(vlan_item, ": ID %d", vlan_id);
proto_tree_add_uint(vlan_tree, hf_edp_vlan_id, tvb, offset, 2,
vlan_id);
offset += 2;
length -= 2;
if (length < 4) {
expert_add_info(pinfo, vlan_item, &ei_edp_short_tlv);
return offset;
}
proto_tree_add_item(vlan_tree, hf_edp_vlan_reserved2, tvb, offset, 4,
ENC_NA);
offset += 4;
length -= 4;
if (length < 4) {
expert_add_info(pinfo, vlan_item, &ei_edp_short_tlv);
return offset;
}
proto_tree_add_item(vlan_tree, hf_edp_vlan_ip, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
length -= 4;
vlan_name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
proto_item_append_text(vlan_item, ", Name \"%s\"",
format_text(vlan_name, strlen(vlan_name)));
proto_tree_add_string(vlan_tree, hf_edp_vlan_name, tvb, offset, length,
vlan_name);
offset += length;
return offset;
}
static int
dissect_esrp_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *esrp_item;
proto_tree *esrp_tree;
guint16 group;
group = tvb_get_guint8(tvb, offset + 1 + 4);
esrp_item = proto_tree_add_protocol_format(tree, hf_edp_esrp,
tvb, offset, length, "ESRP: Group %d", group);
esrp_tree = proto_item_add_subtree(esrp_item, ett_edp_esrp);
dissect_tlv_header(tvb, pinfo, offset, 4, esrp_tree);
offset += 4;
proto_tree_add_item(esrp_tree, hf_edp_esrp_proto, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(esrp_tree, hf_edp_esrp_group, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(esrp_tree, hf_edp_esrp_prio, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esrp_tree, hf_edp_esrp_state, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esrp_tree, hf_edp_esrp_ports, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esrp_tree, hf_edp_esrp_virtip, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(esrp_tree, hf_edp_esrp_sysmac, tvb, offset, 6,
ENC_NA);
offset += 6;
proto_tree_add_item(esrp_tree, hf_edp_esrp_hello, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(esrp_tree, hf_edp_esrp_reserved, tvb, offset, 2,
ENC_NA);
offset += 2;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESRP");
return offset;
}
static int
dissect_eaps_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *eaps_item;
proto_tree *eaps_tree;
guint16 ctrlvlanid;
const gchar *sysmac_str;
ctrlvlanid = tvb_get_ntohs(tvb, offset + 1 + 1 + 4);
sysmac_str = tvb_ether_to_str(tvb, offset + 12);
eaps_item = proto_tree_add_protocol_format(tree, hf_edp_eaps,
tvb, offset, length, "EAPS: Ctrlvlan %d, Sysmac %s",
ctrlvlanid, sysmac_str);
eaps_tree = proto_item_add_subtree(eaps_item, ett_edp_eaps);
dissect_tlv_header(tvb, pinfo, offset, 4, eaps_tree);
offset += 4;
proto_tree_add_item(eaps_tree, hf_edp_eaps_ver, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(eaps_tree, hf_edp_eaps_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(eaps_tree, hf_edp_eaps_ctrlvlanid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eaps_tree, hf_edp_eaps_reserved0, tvb, offset, 4,
ENC_NA);
offset += 4;
proto_tree_add_item(eaps_tree, hf_edp_eaps_sysmac, tvb, offset, 6,
ENC_NA);
offset += 6;
proto_tree_add_item(eaps_tree, hf_edp_eaps_hello, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eaps_tree, hf_edp_eaps_fail, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eaps_tree, hf_edp_eaps_state, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(eaps_tree, hf_edp_eaps_reserved1, tvb, offset, 1,
ENC_NA);
offset += 1;
proto_tree_add_item(eaps_tree, hf_edp_eaps_helloseq, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(eaps_tree, hf_edp_eaps_reserved2, tvb, offset, 38,
ENC_NA);
offset += 38;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EAPS");
col_append_fstr(pinfo->cinfo, COL_INFO, " ID: %d, MAC: %s",
ctrlvlanid, sysmac_str);
return offset;
}
static int
dissect_esl_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *esl_item;
proto_tree *esl_tree;
guint16 ctrlvlanid;
guint16 numlinks;
const gchar *sysmac_str;
ctrlvlanid = tvb_get_ntohs(tvb, offset + 2 + 4);
sysmac_str = tvb_ether_to_str(tvb, offset + 12);
esl_item = proto_tree_add_protocol_format(tree, hf_edp_esl,
tvb, offset, length, "ESL: Ctrlvlan %d, Sysmac %s",
ctrlvlanid, sysmac_str);
esl_tree = proto_item_add_subtree(esl_item, ett_edp_esl);
dissect_tlv_header(tvb, pinfo, offset, 4, esl_tree);
offset += 4;
length -= 4;
proto_tree_add_item(esl_tree, hf_edp_esl_ver, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(esl_tree, hf_edp_esl_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(esl_tree, hf_edp_esl_ctrlvlanid, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_reserved0, tvb, offset, 4,
ENC_NA);
offset += 4;
length -= 4;
proto_tree_add_item(esl_tree, hf_edp_esl_sysmac, tvb, offset, 6,
ENC_NA);
offset += 6;
length -= 6;
proto_tree_add_item(esl_tree, hf_edp_esl_reserved1, tvb, offset, 4,
ENC_NA);
offset += 4;
length -= 4;
proto_tree_add_item(esl_tree, hf_edp_esl_state, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(esl_tree, hf_edp_esl_linkrole, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
length -= 1;
proto_tree_add_item(esl_tree, hf_edp_esl_linkid1, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_failed1, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_failed2, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_reserved4, tvb, offset, 2,
ENC_NA);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_linkid2, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
proto_tree_add_item(esl_tree, hf_edp_esl_reserved5, tvb, offset, 2,
ENC_NA);
offset += 2;
length -= 2;
numlinks = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(esl_tree, hf_edp_esl_numlinks, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
for (; numlinks > 0 && length >= 2; numlinks--) {
proto_tree_add_item(esl_tree, hf_edp_esl_linklist, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
length -= 2;
}
proto_tree_add_item(esl_tree, hf_edp_esl_rest, tvb, offset, length,
ENC_NA);
offset += length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESL");
col_append_fstr(pinfo->cinfo, COL_INFO, " ID: %d, MAC: %s",
ctrlvlanid, sysmac_str);
return offset;
}
static int
dissect_elsm_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length,
proto_tree *tree, guint16 seqno)
{
proto_item *elsm_item;
proto_tree *elsm_tree;
guint8 type, subtype;
type = tvb_get_guint8(tvb, offset + 4);
subtype = tvb_get_guint8(tvb, offset + 4 + 1);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s%s (#%d)",
val_to_str(type, elsm_type_vals, "Unknown (0x%02x)"),
val_to_str(subtype, elsm_subtype_vals, " Unknown (0x%02x)"),
seqno);
elsm_item = proto_tree_add_protocol_format(tree, hf_edp_elsm,
tvb, offset, length, "ELSM %s%s(#%d)",
val_to_str(type, elsm_type_vals, "Unknown (0x%02x)"),
val_to_str(subtype, elsm_subtype_vals, " Unknown (0x%02x)"),
seqno);
elsm_tree = proto_item_add_subtree(elsm_item, ett_edp_elsm);
dissect_tlv_header(tvb, pinfo, offset, 4, elsm_tree);
offset += 4;
proto_tree_add_item(elsm_tree, hf_edp_elsm_type, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(elsm_tree, hf_edp_elsm_subtype, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(elsm_tree, hf_edp_elsm_magic, tvb, offset, 2,
ENC_NA);
offset += 2;
return offset;
}
static void
dissect_elrp_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *elrp_item;
proto_tree *elrp_tree;
elrp_item = proto_tree_add_protocol_format(tree, hf_edp_elrp,
tvb, offset, length, "ELRP");
elrp_tree = proto_item_add_subtree(elrp_item, ett_edp_elrp);
dissect_tlv_header(tvb, pinfo, offset, 4, elrp_tree);
offset += 4;
length -= 4;
proto_tree_add_item(elrp_tree, hf_edp_elrp_unknown, tvb, offset, length,
ENC_NA);
}
static void
dissect_unknown_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree)
{
proto_item *unknown_item;
proto_tree *unknown_tree;
guint8 tlv_type;
tlv_type = tvb_get_guint8(tvb, offset + 1);
unknown_item = proto_tree_add_protocol_format(tree, hf_edp_unknown,
tvb, offset, length, "Unknown element [0x%02x]", tlv_type);
unknown_tree = proto_item_add_subtree(unknown_item, ett_edp_unknown);
dissect_tlv_header(tvb, pinfo, offset, 4, unknown_tree);
offset += 4;
length -= 4;
proto_tree_add_item(unknown_tree, hf_edp_unknown_data, tvb, offset, length,
ENC_NA);
}
static int
dissect_edp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *edp_tree;
proto_item *checksum_item;
proto_tree *checksum_tree;
guint32 offset = 0;
guint16 packet_checksum, computed_checksum;
gboolean checksum_good, checksum_bad;
gboolean last = FALSE;
guint8 tlv_type;
guint16 tlv_length;
guint16 data_length;
guint16 seqno;
vec_t cksum_vec[1];
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_set_str(pinfo->cinfo, COL_INFO, PROTO_SHORT_NAME ":");
ti = proto_tree_add_item(tree, proto_edp, tvb, offset, -1,
ENC_NA);
edp_tree = proto_item_add_subtree(ti, ett_edp);
proto_tree_add_item(edp_tree, hf_edp_version, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(edp_tree, hf_edp_reserved, tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
data_length = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(edp_tree, hf_edp_length, tvb, offset, 2,
data_length);
offset += 2;
packet_checksum = tvb_get_ntohs(tvb, offset);
if (tvb_captured_length(tvb) >= data_length) {
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, data_length);
computed_checksum = in_cksum(&cksum_vec[0], 1);
checksum_good = (computed_checksum == 0);
checksum_bad = !checksum_good;
if (checksum_good) {
checksum_item = proto_tree_add_uint_format(edp_tree,
hf_edp_checksum, tvb, offset, 2, packet_checksum,
"Checksum: 0x%04x [correct]",
packet_checksum);
} else {
checksum_item = proto_tree_add_uint_format(edp_tree,
hf_edp_checksum, tvb, offset, 2, packet_checksum,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
packet_checksum,
in_cksum_shouldbe(packet_checksum, computed_checksum));
}
} else {
checksum_good = checksum_bad = FALSE;
checksum_item = proto_tree_add_uint(edp_tree, hf_edp_checksum,
tvb, offset, 2, packet_checksum);
}
checksum_tree = proto_item_add_subtree(checksum_item, ett_edp_checksum);
checksum_item = proto_tree_add_boolean(checksum_tree, hf_edp_checksum_good,
tvb, offset, 2, checksum_good);
PROTO_ITEM_SET_GENERATED(checksum_item);
checksum_item = proto_tree_add_boolean(checksum_tree, hf_edp_checksum_bad,
tvb, offset, 2, checksum_bad);
PROTO_ITEM_SET_GENERATED(checksum_item);
offset += 2;
seqno = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(edp_tree, hf_edp_seqno, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(edp_tree, hf_edp_midtype, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(edp_tree, hf_edp_midmac, tvb, offset, 6,
ENC_NA);
offset += 6;
while (offset < data_length && !last) {
if (data_length - offset < 4) {
proto_tree_add_expert_format(edp_tree, pinfo, &ei_edp_short_tlv, tvb, offset, 4,
"Too few bytes left for TLV: %u (< 4)",
data_length - offset);
break;
}
tlv_type = tvb_get_guint8(tvb, offset + 1);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
if ((tlv_length < 4) || (tlv_length > (data_length - offset))) {
proto_tree_add_expert_format(edp_tree, pinfo, &ei_edp_short_tlv, tvb, offset, 0,
"TLV with invalid length: %u", tlv_length);
break;
}
if (tlv_type != EDP_TYPE_NULL)
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(tlv_type, edp_type_vals, "[0x%02x]"));
switch (tlv_type) {
case EDP_TYPE_NULL:
dissect_null_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
last = TRUE;
break;
case EDP_TYPE_DISPLAY:
dissect_display_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_INFO:
dissect_info_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_VLAN:
dissect_vlan_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_ESRP:
dissect_esrp_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_EAPS:
dissect_eaps_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_ESL:
dissect_esl_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
case EDP_TYPE_ELSM:
dissect_elsm_tlv(tvb, pinfo, offset, tlv_length, edp_tree, seqno);
break;
case EDP_TYPE_ELRP:
dissect_elrp_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
default:
dissect_unknown_tlv(tvb, pinfo, offset, tlv_length, edp_tree);
break;
}
offset += tlv_length;
}
return tvb_captured_length(tvb);
}
void
proto_register_edp(void)
{
static hf_register_info hf[] = {
{ &hf_edp_version,
{ "Version", "edp.version", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_reserved,
{ "Reserved", "edp.reserved", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_length,
{ "Data length", "edp.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_checksum,
{ "EDP checksum", "edp.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_edp_checksum_good,
{ "Good", "edp.checksum_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_edp_checksum_bad,
{ "Bad", "edp.checksum_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
{ &hf_edp_seqno,
{ "Sequence number", "edp.seqno", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_midtype,
{ "Machine ID type", "edp.midtype", FT_UINT16, BASE_DEC, VALS(edp_midtype_vals),
0x0, NULL, HFILL }},
{ &hf_edp_midmac,
{ "Machine MAC", "edp.midmac", FT_ETHER, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_tlv_marker,
{ "TLV Marker", "edp.tlv.marker", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_tlv_type,
{ "TLV type", "edp.tlv.type", FT_UINT8, BASE_DEC, VALS(edp_type_vals),
0x0, NULL, HFILL }},
{ &hf_edp_tlv_length,
{ "TLV length", "edp.tlv.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_display,
{ "Display", "edp.display", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Display element", HFILL }},
{ &hf_edp_display_string,
{ "Name", "edp.display.string", FT_STRING, BASE_NONE, NULL,
0x0, "MIB II display string", HFILL }},
{ &hf_edp_info,
{ "Info", "edp.info", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Info element", HFILL }},
{ &hf_edp_info_slot,
{ "Slot", "edp.info.slot", FT_UINT16, BASE_DEC, NULL,
0x0, "Originating slot #", HFILL }},
{ &hf_edp_info_port,
{ "Port", "edp.info.port", FT_UINT16, BASE_DEC, NULL,
0x0, "Originating port #", HFILL }},
{ &hf_edp_info_vchassid,
{ "Virt chassis", "edp.info.vchassid", FT_UINT16, BASE_DEC, NULL,
0x0, "Virtual chassis ID", HFILL }},
{ &hf_edp_info_reserved,
{ "Reserved", "edp.info.reserved", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_info_version,
{ "Version", "edp.info.version", FT_UINT32, BASE_HEX, NULL,
0x0, "Software version", HFILL }},
{ &hf_edp_info_version_major1,
{ "Version (major1)", "edp.info.version.major1", FT_UINT8, BASE_DEC, NULL,
0x0, "Software version (major1)", HFILL }},
{ &hf_edp_info_version_major2,
{ "Version (major2)", "edp.info.version.major2", FT_UINT8, BASE_DEC, NULL,
0x0, "Software version (major2)", HFILL }},
{ &hf_edp_info_version_sustaining,
{ "Version (sustaining)", "edp.info.version.sustaining", FT_UINT8, BASE_DEC, NULL,
0x0, "Software version (sustaining)", HFILL }},
{ &hf_edp_info_version_internal,
{ "Version (internal)", "edp.info.version.internal", FT_UINT8, BASE_DEC, NULL,
0x0, "Software version (internal)", HFILL }},
{ &hf_edp_info_vchassconn,
{ "Connections", "edp.info.vchassconn", FT_BYTES, BASE_NONE, NULL,
0x0, "Virtual chassis connections", HFILL }},
{ &hf_edp_vlan,
{ "Vlan", "edp.vlan", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Vlan element", HFILL }},
{ &hf_edp_vlan_flags,
{ "Flags", "edp.vlan.flags", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_vlan_flags_ip,
{ "Flags-IP", "edp.vlan.flags.ip", FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x80, "Vlan has IP address configured", HFILL }},
{ &hf_edp_vlan_flags_reserved,
{ "Flags-reserved", "edp.vlan.flags.reserved", FT_UINT8, BASE_HEX, NULL,
0x7e, NULL, HFILL }},
{ &hf_edp_vlan_flags_unknown,
{ "Flags-Unknown", "edp.vlan.flags.unknown", FT_BOOLEAN, 8, TFS(&tfs_set_notset),
0x01, NULL, HFILL }},
{ &hf_edp_vlan_reserved1,
{ "Reserved1", "edp.vlan.reserved1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_vlan_id,
{ "Vlan ID", "edp.vlan.id", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_vlan_reserved2,
{ "Reserved2", "edp.vlan.reserved2", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_vlan_ip,
{ "IP addr", "edp.vlan.ip", FT_IPv4, BASE_NONE, NULL,
0x0, "VLAN IP address", HFILL }},
{ &hf_edp_vlan_name,
{ "Name", "edp.vlan.name", FT_STRING, BASE_NONE, NULL,
0x0, "VLAN name", HFILL }},
{ &hf_edp_esrp,
{ "ESRP", "edp.esrp", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Extreme Standby Router Protocol element", HFILL }},
{ &hf_edp_esrp_proto,
{ "Protocol", "edp.esrp.proto", FT_UINT8, BASE_DEC, VALS(esrp_proto_vals),
0x0, NULL, HFILL }},
{ &hf_edp_esrp_group,
{ "Group", "edp.esrp.group", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esrp_prio,
{ "Prio", "edp.esrp.prio", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esrp_state,
{ "State", "edp.esrp.state", FT_UINT16, BASE_DEC, VALS(esrp_state_vals),
0x0, NULL, HFILL }},
{ &hf_edp_esrp_ports,
{ "Ports", "edp.esrp.ports", FT_UINT16, BASE_DEC, NULL,
0x0, "Number of active ports", HFILL }},
{ &hf_edp_esrp_virtip,
{ "VirtIP", "edp.esrp.virtip", FT_IPv4, BASE_NONE, NULL,
0x0, "Virtual IP address", HFILL }},
{ &hf_edp_esrp_sysmac,
{ "Sys MAC", "edp.esrp.sysmac", FT_ETHER, BASE_NONE, NULL,
0x0, "System MAC address", HFILL }},
{ &hf_edp_esrp_hello,
{ "Hello", "edp.esrp.hello", FT_UINT16, BASE_DEC, NULL,
0x0, "Hello timer", HFILL }},
{ &hf_edp_esrp_reserved,
{ "Reserved", "edp.esrp.reserved", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_eaps,
{ "EAPS", "edp.eaps", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Ethernet Automatic Protection Switching element", HFILL }},
{ &hf_edp_eaps_ver,
{ "Version", "edp.eaps.ver", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_eaps_type,
{ "Type", "edp.eaps.type", FT_UINT8, BASE_DEC, VALS(eaps_type_vals),
0x0, NULL, HFILL }},
{ &hf_edp_eaps_ctrlvlanid,
{ "Vlan ID", "edp.eaps.vlanid", FT_UINT16, BASE_DEC, NULL,
0x0, "Control Vlan ID", HFILL }},
{ &hf_edp_eaps_reserved0,
{ "Reserved0", "edp.eaps.reserved0", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_eaps_sysmac,
{ "Sys MAC", "edp.eaps.sysmac", FT_ETHER, BASE_NONE, NULL,
0x0, "System MAC address", HFILL }},
{ &hf_edp_eaps_hello,
{ "Hello", "edp.eaps.hello", FT_UINT16, BASE_DEC, NULL,
0x0, "Hello timer", HFILL }},
{ &hf_edp_eaps_fail,
{ "Fail", "edp.eaps.fail", FT_UINT16, BASE_DEC, NULL,
0x0, "Fail timer", HFILL }},
{ &hf_edp_eaps_state,
{ "State", "edp.eaps.state", FT_UINT8, BASE_DEC, VALS(eaps_state_vals),
0x0, NULL, HFILL }},
{ &hf_edp_eaps_reserved1,
{ "Reserved1", "edp.eaps.reserved1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_eaps_helloseq,
{ "Helloseq", "edp.eaps.helloseq", FT_UINT16, BASE_DEC, NULL,
0x0, "Hello sequence", HFILL }},
{ &hf_edp_eaps_reserved2,
{ "Reserved2", "edp.eaps.reserved2", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl,
{ "ESL", "edp.esl", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "EAPS shared link", HFILL }},
{ &hf_edp_esl_ver,
{ "Version", "edp.esl.ver", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl_type,
{ "Type", "edp.esl.type", FT_UINT8, BASE_DEC, VALS(esl_type_vals),
0x0, NULL, HFILL }},
{ &hf_edp_esl_ctrlvlanid,
{ "Vlan ID", "edp.esl.vlanid", FT_UINT16, BASE_DEC, NULL,
0x0, "Control Vlan ID", HFILL }},
{ &hf_edp_esl_reserved0,
{ "Reserved0", "edp.esl.reserved0", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl_sysmac,
{ "Sys MAC", "edp.esl.sysmac", FT_ETHER, BASE_NONE, NULL,
0x0, "System MAC address", HFILL }},
{ &hf_edp_esl_reserved1,
{ "Reserved1", "edp.esl.reserved1", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl_state,
{ "State", "edp.esl.state", FT_UINT8, BASE_DEC, VALS(esl_state_vals),
0x0, NULL, HFILL }},
{ &hf_edp_esl_linkrole,
{ "Role", "edp.esl.role", FT_UINT8, BASE_DEC, VALS(esl_role_vals),
0x0, NULL, HFILL }},
{ &hf_edp_esl_linkid1,
{ "Link ID 1", "edp.esl.linkid1", FT_UINT16, BASE_DEC, NULL,
0x0, "Shared link ID 1", HFILL }},
{ &hf_edp_esl_failed1,
{ "Failed ID 1", "edp.esl.failed1", FT_UINT16, BASE_DEC, NULL,
0x0, "Failed link ID 1", HFILL }},
{ &hf_edp_esl_failed2,
{ "Failed ID 2", "edp.esl.failed2", FT_UINT16, BASE_DEC, NULL,
0x0, "Failed link ID 2", HFILL }},
{ &hf_edp_esl_reserved4,
{ "Reserved4", "edp.esl.reserved4", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl_linkid2,
{ "Link ID 2", "edp.esl.linkid2", FT_UINT16, BASE_DEC, NULL,
0x0, "Shared link ID 2", HFILL }},
{ &hf_edp_esl_reserved5,
{ "Reserved5", "edp.esl.reserved5", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_esl_numlinks,
{ "Num Shared Links", "edp.esl.numlinks", FT_UINT16, BASE_DEC, NULL,
0x0, "Number of shared links in the network", HFILL }},
{ &hf_edp_esl_linklist,
{ "Link List", "edp.esl.linklist", FT_UINT16, BASE_DEC, NULL,
0x0, "List of Shared Link IDs", HFILL }},
{ &hf_edp_esl_rest,
{ "Rest", "edp.esl.rest", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_elsm,
{ "ELSM", "edp.elsm", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Extreme Link Status Monitoring element", HFILL }},
{ &hf_edp_elsm_type,
{ "Type", "edp.elsm.type", FT_UINT8, BASE_DEC, VALS(elsm_type_vals),
0x0, NULL, HFILL }},
{ &hf_edp_elsm_subtype,
{ "Subtype", "edp.elsm.subtype", FT_UINT8, BASE_DEC, VALS(elsm_subtype_vals),
0x0, NULL, HFILL }},
{ &hf_edp_elsm_magic,
{ "Magic", "edp.elsm.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_elrp,
{ "ELRP", "edp.elrp", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Extreme Loop Recognition Protocol element", HFILL }},
{ &hf_edp_elrp_unknown,
{ "Unknown", "edp.elrp.unknown", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_unknown,
{ "Unknown", "edp.unknown", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Element unknown to Wireshark", HFILL }},
{ &hf_edp_unknown_data,
{ "Unknown", "edp.unknown.data", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL }},
{ &hf_edp_null,
{ "End", "edp.null", FT_PROTOCOL, BASE_NONE, NULL,
0x0, "Last element", HFILL }},
};
static hf_register_info extreme_hf[] = {
{ &hf_llc_extreme_pid,
{ "PID", "llc.extreme_pid", FT_UINT16, BASE_HEX,
VALS(extreme_pid_vals), 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_edp,
&ett_edp_checksum,
&ett_edp_tlv_header,
&ett_edp_vlan_flags,
&ett_edp_display,
&ett_edp_info,
&ett_edp_info_version,
&ett_edp_vlan,
&ett_edp_esrp,
&ett_edp_eaps,
&ett_edp_esl,
&ett_edp_elrp,
&ett_edp_elsm,
&ett_edp_unknown,
&ett_edp_null,
};
static ei_register_info ei[] = {
{ &ei_edp_short_tlv, { "edp.short_tlv", PI_MALFORMED, PI_ERROR, "TLV is too short", EXPFILL }},
};
expert_module_t* expert_edp;
proto_edp = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "edp");
proto_register_field_array(proto_edp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_edp = expert_register_protocol(proto_edp);
expert_register_field_array(expert_edp, ei, array_length(ei));
llc_add_oui(OUI_EXTREME, "llc.extreme_pid", "LLC Extreme OUI PID", extreme_hf, proto_edp);
}
void
proto_reg_handoff_edp(void)
{
dissector_handle_t edp_handle;
edp_handle = create_dissector_handle(dissect_edp, proto_edp);
dissector_add_uint("llc.extreme_pid", 0x00bb, edp_handle);
}
