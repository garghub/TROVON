static int
dissect_flip_chksum_hdr(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
guint16 computed_chksum,
gboolean *ext_hdr_follows_ptr)
{
proto_tree *chksum_hdr_tree;
guint32 dw;
guint8 chksum_hdr_etype;
guint8 chksum_hdr_spare;
guint8 chksum_hdr_ext;
guint16 chksum_hdr_chksum;
gint bytes_dissected;
gint offset;
chksum_hdr_tree = NULL;
bytes_dissected = 0;
offset = 0;
dw = tvb_get_ntohl(tvb, offset);
chksum_hdr_etype = (guint8) ((dw & 0xFF000000) >> 24);
chksum_hdr_spare = (guint8) ((dw & 0x00FE0000) >> 17);
chksum_hdr_ext = (guint8) ((dw & 0x00010000) >> 16);
chksum_hdr_chksum = (guint16) (dw & 0x0000FFFF);
if (chksum_hdr_ext == 1) {
*ext_hdr_follows_ptr = TRUE;
}
else {
*ext_hdr_follows_ptr = FALSE;
}
if (tree) {
chksum_hdr_tree = proto_tree_add_subtree(tree, tvb, offset + 0, 4,
ett_flip_chksum, NULL, "Checksum Header");
proto_tree_add_uint_format_value(chksum_hdr_tree, hf_flip_chksum_etype,
tvb, offset + 0, 1, dw,
"%s", val_to_str_const(chksum_hdr_etype,
flip_etype,
"Unknown"));
proto_tree_add_uint_format_value(chksum_hdr_tree, hf_flip_chksum_spare,
tvb, offset + 1, 1, dw,
"%d (0x%02x)",
chksum_hdr_spare, chksum_hdr_spare);
proto_tree_add_uint_format_value(chksum_hdr_tree, hf_flip_chksum_e,
tvb, offset + 1, 1, dw,
"%s", val_to_str_const(chksum_hdr_ext,
flip_boolean,
"Unknown"));
proto_tree_add_uint_format_value(
chksum_hdr_tree,
hf_flip_chksum_chksum,
tvb, offset + 2, 2,
chksum_hdr_chksum,
"0x%04x [%s] (computed 0x%04x)",
chksum_hdr_chksum,
((chksum_hdr_chksum == computed_chksum) ? "Correct" : "Incorrect"),
computed_chksum);
}
if (computed_chksum != chksum_hdr_chksum) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Checksum 0x%04x [%s] (computed 0x%04x)",
chksum_hdr_chksum,
((chksum_hdr_chksum == computed_chksum) ?
"Correct" : "Incorrect"),
computed_chksum);
}
bytes_dissected += FLIP_CHKSUM_HDR_LEN;
return bytes_dissected;
}
static gboolean
is_payload_rtp(tvbuff_t *tvb)
{
guint8 octet1, octet2;
unsigned int version;
unsigned int payload_type;
unsigned int offset;
gint len_remaining;
offset = 0;
len_remaining = tvb_length_remaining(tvb, offset);
if (len_remaining < RTP_V2_HEADER_MIN_LEN) {
return FALSE;
}
octet1 = tvb_get_guint8(tvb, offset);
version = RTP_VERSION(octet1);
if (version != 2) {
return FALSE;
}
octet2 = tvb_get_guint8(tvb, offset + 1);
payload_type = RTP_PAYLOAD_TYPE(octet2);
if ((payload_type <= PT_H263)
||
((payload_type >= PT_UNDF_96) && (payload_type <= PT_UNDF_127))) {
;
}
else {
return FALSE;
}
return TRUE;
}
static gboolean
is_payload_rtcp(tvbuff_t *tvb)
{
unsigned int first_byte;
unsigned int packet_type;
unsigned int offset;
gint len_remaining;
offset = 0;
len_remaining = tvb_length_remaining(tvb, offset);
if (len_remaining < RTCP_V2_HEADER_MIN_LEN) {
return FALSE;
}
first_byte = tvb_get_guint8(tvb, offset);
if (((first_byte & 0xC0) >> 6) != 2) {
return FALSE;
}
packet_type = tvb_get_guint8(tvb, offset + 1);
if (!((packet_type == RTCP_SR) || (packet_type == RTCP_RR) ||
(packet_type == RTCP_BYE) || (packet_type == RTCP_APP))) {
return FALSE;
}
if (tvb_reported_length(tvb) % 4) {
return FALSE;
}
return TRUE;
}
static int
dissect_flip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *flip_tree;
proto_tree *basic_hdr_tree;
tvbuff_t *flip_tvb;
guint32 dw1;
guint32 dw2;
guint8 basic_hdr_ext;
guint8 basic_hdr_reserved;
guint32 basic_hdr_flow_id;
guint16 basic_hdr_seqnum;
guint16 basic_hdr_len;
gboolean ext_hdr;
gint bytes_dissected;
gint payload_len;
gint frame_len;
gint flip_len;
gint offset;
gboolean is_faulty_frame;
ti = NULL;
flip_tree = NULL;
basic_hdr_tree = NULL;
flip_tvb = NULL;
ext_hdr = FALSE;
bytes_dissected = 0;
offset = 0;
is_faulty_frame = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FLIP");
frame_len = tvb_length(tvb);
if (frame_len < FLIP_BASIC_HDR_LEN) {
goto DISSECT_FLIP_EXIT;
}
bytes_dissected += FLIP_BASIC_HDR_LEN;
dw1 = tvb_get_ntohl(tvb, offset + 0);
basic_hdr_ext = ((dw1 & 0x80000000) >> 31);
basic_hdr_reserved = ((dw1 & 0x70000000) >> 24);
basic_hdr_flow_id = (dw1 & 0x0FFFFFFF);
dw2 = tvb_get_ntohl(tvb, offset + 4);
basic_hdr_seqnum = (guint16) ((dw2 & 0xFFFF0000) >> 16);
basic_hdr_len = (guint16) (dw2 & 0x0000FFFF);
if (basic_hdr_ext == 1) {
ext_hdr = TRUE;
}
flip_len = basic_hdr_len;
if ((flip_len < FLIP_BASIC_HDR_LEN) || (flip_len > frame_len)) {
is_faulty_frame = TRUE;
}
col_add_fstr(pinfo->cinfo, COL_INFO,
"FlowID %s", val_to_str(basic_hdr_flow_id, NULL, "0x%08x"));
flip_tvb = tvb_new_subset_length(tvb, 0, frame_len);
if (tree) {
if (PTREE_DATA(tree)->visible) {
ti = proto_tree_add_protocol_format(
tree, proto_flip, flip_tvb, 0, flip_len,
"NSN FLIP, FlowID %s",
val_to_str(basic_hdr_flow_id, NULL, "0x%08x"));
}
else {
ti = proto_tree_add_item(tree, proto_flip, flip_tvb, 0,
flip_len, ENC_NA);
}
flip_tree = proto_item_add_subtree(ti, ett_flip);
basic_hdr_tree = proto_tree_add_subtree(flip_tree, flip_tvb, 0, 8, ett_flip_basic, NULL, "Basic Header");
proto_tree_add_uint_format_value(basic_hdr_tree,
hf_flip_basic_e,
flip_tvb, offset + 0, 1, dw1,
"%s", val_to_str_const(basic_hdr_ext,
flip_boolean,
"Unknown"));
proto_tree_add_uint_format_value(basic_hdr_tree,
hf_flip_basic_reserved,
flip_tvb, offset + 0, 1, dw1,
"%d", basic_hdr_reserved);
proto_tree_add_item(basic_hdr_tree, hf_flip_basic_flowid,
flip_tvb, offset + 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(basic_hdr_tree, hf_flip_basic_seqnum,
flip_tvb, offset + 4, 2, dw2,
"%d (0x%04x)",
basic_hdr_seqnum, basic_hdr_seqnum);
proto_tree_add_uint_format_value(basic_hdr_tree, hf_flip_basic_len,
flip_tvb, offset + 6, 2, dw2,
"%d (0x%04x)",
basic_hdr_len, basic_hdr_len);
}
offset += FLIP_BASIC_HDR_LEN;
if (is_faulty_frame == TRUE) {
if (flip_len > frame_len) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Length mismatch: frame %d bytes, hdr %d bytes",
frame_len, flip_len);
}
else if (flip_len < FLIP_BASIC_HDR_LEN) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Invalid length in basic header: %d bytes", flip_len);
}
goto DISSECT_FLIP_EXIT;
}
payload_len = basic_hdr_len;
payload_len -= FLIP_BASIC_HDR_LEN;
if ((ext_hdr == TRUE) && (payload_len < FLIP_EXTENSION_HDR_MIN_LEN)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Extension header indicated, but not enough data");
goto DISSECT_FLIP_EXIT;
}
while ((ext_hdr == TRUE) && (payload_len >= FLIP_EXTENSION_HDR_MIN_LEN)) {
guint8 ext_hdr_type;
gint bytes_handled;
guint16 computed_chksum;
tvbuff_t *chksum_tvb;
ext_hdr_type = tvb_get_guint8(flip_tvb, offset);
switch (ext_hdr_type) {
case FLIP_CHKSUM:
{
vec_t vec[2];
SET_CKSUM_VEC_TVB(vec[0], flip_tvb, 0, bytes_dissected + 2);
SET_CKSUM_VEC_TVB(vec[1], flip_tvb, bytes_dissected + 4,
flip_len - (bytes_dissected + 4));
computed_chksum = in_cksum(&vec[0], 2);
computed_chksum = g_htons(computed_chksum);
}
chksum_tvb = tvb_new_subset_length(flip_tvb, offset,
FLIP_CHKSUM_HDR_LEN);
bytes_handled = dissect_flip_chksum_hdr(chksum_tvb,
pinfo,
flip_tree,
computed_chksum,
&ext_hdr);
bytes_dissected += bytes_handled;
payload_len -= bytes_handled;
offset += bytes_handled;
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO,
"Invalid extension header type 0x%02x", ext_hdr_type);
goto DISSECT_FLIP_EXIT;
break;
}
}
if (payload_len > 0) {
dissector_handle_t handle;
tvbuff_t *payload_tvb;
gint data_len;
gboolean has_user_messed_up;
has_user_messed_up = FALSE;
payload_tvb = tvb_new_subset_length(flip_tvb, offset,
payload_len);
switch (global_flip_payload_decoding_mode) {
case FLIP_PAYLOAD_DECODING_MODE_NONE:
handle = data_handle;
break;
case FLIP_PAYLOAD_DECODING_MODE_HEURISTIC:
if ((is_heur_enabled_rtp == TRUE)
&&
(is_payload_rtp(payload_tvb) == TRUE)) {
handle = rtp_handle;
}
else if ((is_heur_enabled_rtcp == TRUE)
&&
(is_payload_rtcp(payload_tvb))) {
handle = rtcp_handle;
}
else {
handle = data_handle;
}
break;
case FLIP_PAYLOAD_DECODING_MODE_FORCED:
if (is_forced_handle_ok == TRUE) {
handle = forced_handle;
}
else {
handle = data_handle;
has_user_messed_up = TRUE;
}
break;
default:
DISSECTOR_ASSERT(0);
break;
}
data_len = call_dissector(handle, payload_tvb, pinfo, tree);
if (has_user_messed_up == TRUE) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Invalid user dissector \"%s\"",
global_forced_protocol);
}
bytes_dissected += data_len;
}
DISSECT_FLIP_EXIT:
return bytes_dissected;
}
void
proto_register_flip(void)
{
static hf_register_info hf[] = {
{&hf_flip_basic_e,
{"Extension Header Follows", "flip.basic.e", FT_UINT32, BASE_DEC,
VALS(flip_boolean), 0x80000000, NULL, HFILL}
},
{&hf_flip_basic_reserved,
{"Reserved", "flip.basic.reserved", FT_UINT32, BASE_DEC,
NULL, 0x70000000, "Basic Header Reserved", HFILL}
},
{&hf_flip_basic_flowid,
{"FlowID", "flip.basic.flowid", FT_UINT32, BASE_HEX,
NULL, 0x0FFFFFFF, "Basic Header Flow ID", HFILL}
},
{&hf_flip_basic_seqnum,
{"Seqnum", "flip.basic.seqnum", FT_UINT32, BASE_DEC,
NULL, 0xFFFF0000, "Basic Header Sequence Number", HFILL}
},
{&hf_flip_basic_len,
{"Len", "flip.basic.len", FT_UINT32, BASE_DEC,
NULL, 0x0000FFFF, "Basic Header Packet Length", HFILL}
},
{&hf_flip_chksum_etype,
{"Extension Type", "flip.chksum.etype", FT_UINT32, BASE_DEC,
VALS(flip_etype), 0xFF000000, "Checksum Header Extension Type", HFILL}
},
{&hf_flip_chksum_spare,
{"Spare", "flip.chksum.spare", FT_UINT32, BASE_DEC,
NULL, 0x00FE0000, "Checksum Header Spare", HFILL}
},
{&hf_flip_chksum_e,
{"Extension Header Follows", "flip.chksum.e", FT_UINT32, BASE_DEC,
VALS(flip_boolean), 0x00010000, NULL, HFILL}
},
{&hf_flip_chksum_chksum,
{"Checksum", "flip.chksum.chksum", FT_UINT32, BASE_HEX,
NULL, 0x0000FFFF, NULL, HFILL}
}
};
static gint *ett[] = {
&ett_flip,
&ett_flip_basic,
&ett_flip_chksum,
&ett_flip_payload
};
module_t *flip_module;
proto_flip = proto_register_protocol(
"NSN FLIP",
"FLIP",
"flip"
);
proto_register_field_array(proto_flip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
flip_module = prefs_register_protocol(proto_flip,
proto_reg_handoff_flip);
prefs_register_enum_preference(
flip_module,
"decoding_mode",
"FLIP payload decoding mode",
"Decode FLIP payload according to mode",
&global_flip_payload_decoding_mode,
flip_payload_decoding_modes,
TRUE);
prefs_register_static_text_preference(
flip_module,
"heur_enabled_protocols",
"Heuristic mode: enabled protocols",
"Enabled protocols for heuristic mode");
prefs_register_bool_preference(
flip_module,
"heur_decode_rtp",
"RTP",
"Decode payload as RTP if detected",
&is_heur_enabled_rtp);
prefs_register_bool_preference(
flip_module,
"heur_decode_rtcp",
"RTCP",
"Decode payload as RTCP if detected",
&is_heur_enabled_rtcp);
prefs_register_static_text_preference(
flip_module,
"forced_protocol",
"Forced mode: decode to user-specified protocol",
"Mapping of flow IDs to their decodings");
prefs_register_string_preference(
flip_module,
"forced_decode",
"Protocol name",
"Decoding to user-defined protocol",
&global_forced_protocol);
}
void
proto_reg_handoff_flip(void)
{
dissector_handle_t flip_handle;
static gboolean flip_prefs_initialized = FALSE;
if (flip_prefs_initialized == FALSE) {
flip_handle = new_create_dissector_handle(dissect_flip, proto_flip);
dissector_add_uint("ethertype", ETHERTYPE_FLIP, flip_handle);
rtp_handle = find_dissector("rtp");
rtcp_handle = find_dissector("rtcp");
data_handle = find_dissector("data");
flip_prefs_initialized = TRUE;
}
is_forced_handle_ok = FALSE;
forced_handle = find_dissector(global_forced_protocol);
if (forced_handle != NULL) {
is_forced_handle_ok = TRUE;
}
}
