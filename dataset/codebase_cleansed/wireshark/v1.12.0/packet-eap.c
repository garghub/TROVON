static void
dissect_exteap(proto_tree *eap_tree, tvbuff_t *tvb, int offset,
gint size, packet_info* pinfo)
{
proto_tree_add_item(eap_tree, hf_eap_ext_vendor_id, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
size -= 3;
proto_tree_add_item(eap_tree, hf_eap_ext_vendor_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
size -= 4;
dissect_exteap_wps(eap_tree, tvb, offset, size, pinfo);
}
static gboolean
test_flag(unsigned char flag, unsigned char mask)
{
return ( ( flag & mask ) != 0 );
}
static void
eap_tls_defragment_init(void)
{
reassembly_table_init(&eap_tls_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
dissect_eap_mschapv2(proto_tree *eap_tree, tvbuff_t *tvb, packet_info *pinfo, int offset,
gint size)
{
proto_item *item;
gint left = size;
gint ms_len;
guint8 value_size;
guint8 opcode;
opcode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
if (left <= 0)
return;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
if (left <= 0)
return;
item = proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_length, tvb, offset, 2, ENC_BIG_ENDIAN);
ms_len = tvb_get_ntohs(tvb, offset);
if (ms_len != size)
expert_add_info(pinfo, item, &ei_eap_ms_chap_v2_length);
offset += 2;
left -= 2;
switch (opcode) {
case MS_CHAP_V2_CHALLENGE:
if (left <= 0)
break;
value_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_value_size,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_challenge,
tvb, offset, value_size, ENC_NA);
offset += value_size;
left -= value_size;
if (left <= 0)
break;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_name,
tvb, offset, left, ENC_ASCII|ENC_NA);
break;
case MS_CHAP_V2_RESPONSE:
if (left <= 0)
break;
value_size = tvb_get_guint8(tvb, offset);
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_value_size,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
if (value_size == 49) {
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_peer_challenge,
tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_reserved,
tvb, offset, 8, ENC_NA);
offset += 8;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_nt_response,
tvb, offset, 24, ENC_NA);
offset += 24;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_flags,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= value_size;
} else {
proto_tree_add_text(eap_tree, tvb, offset, value_size,
"EAP-MS-CHAP-v2 Response (Unknown Length): %s",
tvb_bytes_to_ep_str(tvb, offset, value_size));
offset += value_size;
left -= value_size;
}
if (left <= 0)
break;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_name, tvb, offset, left, ENC_ASCII|ENC_NA);
break;
case MS_CHAP_V2_SUCCESS:
if (left <= 0)
break;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_message,
tvb, offset, left, ENC_ASCII|ENC_NA);
break;
case MS_CHAP_V2_FAILURE:
if (left <= 0)
break;
proto_tree_add_item(eap_tree, hf_eap_ms_chap_v2_failure_request,
tvb, offset, left, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_text(eap_tree, tvb, offset, left,
"EAP-MS-CHAP-v2 Data (%d byte%s): \"%s\"",
left, plurality(left, "", "s"),
tvb_bytes_to_ep_str(tvb, offset, left));
break;
}
}
static void
dissect_eap_sim(proto_tree *eap_tree, tvbuff_t *tvb, int offset, gint size)
{
gint left = size;
proto_tree_add_item(eap_tree, hf_eap_sim_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
if (left < 2)
return;
proto_tree_add_item(eap_tree, hf_eap_sim_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
left -= 2;
while (left >= 2) {
guint8 type, length;
proto_item *pi;
proto_tree *attr_tree;
int aoffset;
gint aleft;
aoffset = offset;
type = tvb_get_guint8(tvb, aoffset);
length = tvb_get_guint8(tvb, aoffset + 1);
aleft = 4 * length;
pi = proto_tree_add_none_format(eap_tree, hf_eap_sim_subtype_attribute, tvb,
aoffset, aleft, "EAP-SIM Attribute: %s (%d)",
val_to_str_ext_const(type,
&eap_sim_aka_attribute_vals_ext,
"Unknown"),
type);
attr_tree = proto_item_add_subtree(pi, ett_eap_sim_attr);
proto_tree_add_uint(attr_tree, hf_eap_sim_subtype_type, tvb, aoffset, 1, type);
aoffset += 1;
aleft -= 1;
if (aleft <= 0)
break;
proto_tree_add_item(attr_tree, hf_eap_sim_subtype_length, tvb, aoffset, 1, ENC_BIG_ENDIAN);
aoffset += 1;
aleft -= 1;
proto_tree_add_item(attr_tree, hf_eap_sim_subtype_value, tvb, aoffset, aleft, ENC_NA);
offset += 4 * length;
left -= 4 * length;
}
}
static void
dissect_eap_aka(proto_tree *eap_tree, tvbuff_t *tvb, int offset, gint size)
{
gint left = size;
proto_tree_add_item(eap_tree, hf_eap_aka_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
left -= 1;
if (left < 2)
return;
proto_tree_add_item(eap_tree, hf_eap_aka_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
left -= 2;
while (left >= 2) {
guint8 type, length;
proto_item *pi;
proto_tree *attr_tree;
int aoffset;
gint aleft;
aoffset = offset;
type = tvb_get_guint8(tvb, aoffset);
length = tvb_get_guint8(tvb, aoffset + 1);
aleft = 4 * length;
pi = proto_tree_add_none_format(eap_tree, hf_eap_aka_subtype_attribute, tvb,
aoffset, aleft, "EAP-AKA Attribute: %s (%d)",
val_to_str_ext_const(type,
&eap_sim_aka_attribute_vals_ext,
"Unknown"),
type);
attr_tree = proto_item_add_subtree(pi, ett_eap_aka_attr);
proto_tree_add_uint(attr_tree, hf_eap_aka_subtype_type, tvb, aoffset, 1, type);
aoffset += 1;
aleft -= 1;
if (aleft <= 0)
break;
proto_tree_add_item(attr_tree, hf_eap_aka_subtype_length, tvb, aoffset, 1, ENC_BIG_ENDIAN);
aoffset += 1;
aleft -= 1;
proto_tree_add_item(attr_tree, hf_eap_aka_subtype_value, tvb, aoffset, aleft, ENC_NA);
offset += 4 * length;
left -= 4 * length;
}
}
static int
dissect_eap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 eap_code;
guint16 eap_len;
guint8 eap_type;
gint len;
conversation_t *conversation;
conv_state_t *conversation_state;
frame_state_t *packet_state;
int leap_state;
proto_tree *ti;
proto_tree *eap_tree = NULL;
proto_tree *eap_tls_flags_tree = NULL;
proto_item *eap_type_item = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EAP");
col_clear(pinfo->cinfo, COL_INFO);
eap_code = tvb_get_guint8(tvb, 0);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(eap_code, eap_code_vals, "Unknown code (0x%02X)"));
if (pinfo->destport == pinfo->match_uint) {
conversation = find_conversation(pinfo->fd->num, &pinfo->dst, &pinfo->src,
pinfo->ptype, pinfo->destport,
0, NO_PORT_B);
} else {
conversation = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
0, NO_PORT_B);
}
if (conversation == NULL) {
if (pinfo->destport == pinfo->match_uint) {
conversation = conversation_new(pinfo->fd->num, &pinfo->dst, &pinfo->src,
pinfo->ptype, pinfo->destport,
0, NO_PORT2);
} else {
conversation = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
0, NO_PORT2);
}
}
conversation_state = (conv_state_t *)conversation_get_proto_data(conversation, proto_eap);
if (conversation_state == NULL) {
conversation_state = wmem_new(wmem_file_scope(), conv_state_t);
conversation_state->eap_tls_seq = -1;
conversation_state->eap_reass_cookie = 0;
conversation_state->leap_state = -1;
conversation_add_proto_data(conversation, proto_eap, conversation_state);
}
if (eap_code == EAP_FAILURE)
conversation_state->leap_state = -1;
eap_len = tvb_get_ntohs(tvb, 2);
len = eap_len;
if (tree) {
ti = proto_tree_add_item(tree, proto_eap, tvb, 0, len, ENC_NA);
eap_tree = proto_item_add_subtree(ti, ett_eap);
proto_tree_add_item(eap_tree, hf_eap_code, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eap_tree, hf_eap_identifier, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eap_tree, hf_eap_len, tvb, 2, 2, ENC_BIG_ENDIAN);
}
switch (eap_code) {
case EAP_SUCCESS:
case EAP_FAILURE:
break;
case EAP_REQUEST:
case EAP_RESPONSE:
eap_type = tvb_get_guint8(tvb, 4);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str_ext(eap_type, &eap_type_vals_ext,
"Unknown type (0x%02x)"));
if (tree)
eap_type_item = proto_tree_add_item(eap_tree, hf_eap_type, tvb, 4, 1, ENC_BIG_ENDIAN);
if ((len > 5) || ((len == 5) && (eap_type == EAP_TYPE_ID))) {
int offset = 5;
gint size = len - offset;
switch (eap_type) {
case EAP_TYPE_ID:
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_identity, tvb, offset, size, ENC_ASCII|ENC_NA);
}
if(!pinfo->fd->flags.visited) {
conversation_state->leap_state = 0;
conversation_state->eap_tls_seq = -1;
}
break;
case EAP_TYPE_NOTIFY:
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_notification, tvb,
offset, size, ENC_ASCII|ENC_NA);
}
break;
case EAP_TYPE_NAK:
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_type_nak, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
break;
case EAP_TYPE_MD5:
{
guint8 value_size = tvb_get_guint8(tvb, offset);
gint extra_len = size - 1 - value_size;
proto_item *item;
expert_add_info(pinfo, eap_type_item, &ei_eap_mitm_attacks);
item = proto_tree_add_item(eap_tree, hf_eap_md5_value_size, tvb, offset, 1, ENC_BIG_ENDIAN);
if (value_size > (size - 1))
{
expert_add_info(pinfo, item, &ei_eap_md5_value_size_overflow);
value_size = size - 1;
}
offset += 1;
proto_tree_add_item(eap_tree, hf_eap_md5_value, tvb, offset, value_size, ENC_NA);
offset += value_size;
if (extra_len > 0) {
proto_tree_add_item(eap_tree, hf_eap_md5_extra_data, tvb, offset, extra_len, ENC_NA);
}
}
break;
case EAP_TYPE_FAST:
case EAP_TYPE_PEAP:
case EAP_TYPE_TTLS:
case EAP_TYPE_TLS:
{
guint8 flags = tvb_get_guint8(tvb, offset);
gboolean more_fragments;
gboolean has_length;
gboolean is_start;
int eap_tls_seq = -1;
guint32 eap_reass_cookie = 0;
gboolean needs_reassembly = FALSE;
more_fragments = test_flag(flags,EAP_TLS_FLAG_M);
has_length = test_flag(flags,EAP_TLS_FLAG_L);
is_start = test_flag(flags,EAP_TLS_FLAG_S);
if (is_start)
conversation_state->eap_tls_seq = -1;
if (tree) {
ti = proto_tree_add_item(eap_tree, hf_eap_tls_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
eap_tls_flags_tree = proto_item_add_subtree(ti, ett_eap_tls_flags);
proto_tree_add_item(eap_tls_flags_tree, hf_eap_tls_flag_l, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eap_tls_flags_tree, hf_eap_tls_flag_m, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(eap_tls_flags_tree, hf_eap_tls_flag_s, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((eap_type == EAP_TYPE_PEAP) || (eap_type == EAP_TYPE_TTLS) ||
(eap_type == EAP_TYPE_FAST)) {
proto_tree_add_item(eap_tls_flags_tree, hf_eap_tls_flags_version, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
size -= 1;
offset += 1;
if (has_length) {
if (tree)
proto_tree_add_item(eap_tree, hf_eap_tls_len, tvb, offset, 4, ENC_BIG_ENDIAN);
size -= 4;
offset += 4;
}
if (size > 0) {
tvbuff_t *next_tvb;
gint tvb_len;
gboolean save_fragmented;
tvb_len = tvb_length_remaining(tvb, offset);
if (size < tvb_len)
tvb_len = size;
packet_state = (frame_state_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_eap, 0);
if (packet_state == NULL) {
if (!pinfo->fd->flags.visited) {
if (conversation_state->eap_tls_seq != -1) {
needs_reassembly = TRUE;
conversation_state->eap_tls_seq++;
eap_reass_cookie = conversation_state->eap_reass_cookie;
eap_tls_seq = conversation_state->eap_tls_seq;
} else if (more_fragments && has_length) {
needs_reassembly = TRUE;
conversation_state->eap_reass_cookie = pinfo->fd->num;
conversation_state->eap_tls_seq = 0;
eap_tls_seq = conversation_state->eap_tls_seq;
eap_reass_cookie = conversation_state->eap_reass_cookie;
}
if (needs_reassembly) {
packet_state = wmem_new(wmem_file_scope(), frame_state_t);
packet_state->info = eap_reass_cookie;
p_add_proto_data(wmem_file_scope(), pinfo, proto_eap, 0, packet_state);
}
}
} else {
needs_reassembly = TRUE;
eap_reass_cookie = packet_state->info;
eap_tls_seq = 0;
}
if (needs_reassembly) {
fragment_head *fd_head;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
fd_head = fragment_add_seq(&eap_tls_reassembly_table,
tvb, offset,
pinfo, eap_reass_cookie, NULL,
eap_tls_seq,
size,
more_fragments, 0);
if (fd_head != NULL)
{
proto_item *frag_tree_item;
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled EAP-TLS");
show_fragment_seq_tree(fd_head, &eap_tls_frag_items,
eap_tree, pinfo, next_tvb, &frag_tree_item);
call_dissector(ssl_handle, next_tvb, pinfo, eap_tree);
if (!pinfo->fd->flags.visited)
conversation_state->eap_tls_seq = -1;
}
pinfo->fragmented = save_fragmented;
} else {
next_tvb = tvb_new_subset(tvb, offset, tvb_len, size);
call_dissector(ssl_handle, next_tvb, pinfo, eap_tree);
}
}
}
break;
case EAP_TYPE_LEAP:
{
guint8 count, namesize;
expert_add_info(pinfo, eap_type_item, &ei_eap_dictionary_attacks);
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_leap_version, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_leap_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
count = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_leap_count, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
packet_state = (frame_state_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_eap, 0);
if (packet_state == NULL) {
leap_state = conversation_state->leap_state;
if (leap_state==0) leap_state = 1; else
if (leap_state==1) leap_state = 2; else
if (leap_state==2) leap_state = 3; else
if (leap_state==3) leap_state = 4; else
if (leap_state==4) leap_state = -1;
packet_state = wmem_new(wmem_file_scope(), frame_state_t);
packet_state->info = leap_state;
p_add_proto_data(wmem_file_scope(), pinfo, proto_eap, 0, packet_state);
conversation_state->leap_state = leap_state;
}
leap_state = packet_state->info;
if (tree) {
switch (leap_state) {
case 1:
proto_tree_add_item(eap_tree, hf_eap_leap_peer_challenge, tvb, offset, count, ENC_NA);
break;
case 2:
proto_tree_add_item(eap_tree, hf_eap_leap_peer_response, tvb, offset, count, ENC_NA);
break;
case 3:
proto_tree_add_item(eap_tree, hf_eap_leap_ap_challenge, tvb, offset, count, ENC_NA);
break;
case 4:
proto_tree_add_item(eap_tree, hf_eap_leap_ap_response, tvb, offset, count, ENC_NA);
break;
default:
proto_tree_add_text(eap_tree, tvb, offset, count,
"EAP-LEAP Data (%d byte%s): \"%s\"",
count, plurality(count, "", "s"),
tvb_bytes_to_ep_str(tvb, offset, count));
break;
}
}
offset += count;
namesize = eap_len - (8+count);
if (tree) {
proto_tree_add_item(eap_tree, hf_eap_leap_name, tvb, offset, namesize, ENC_ASCII|ENC_NA);
}
}
break;
case EAP_TYPE_MSCHAPV2:
dissect_eap_mschapv2(eap_tree, tvb, pinfo, offset, size);
break;
case EAP_TYPE_SIM:
if (tree)
dissect_eap_sim(eap_tree, tvb, offset, size);
break;
case EAP_TYPE_AKA:
case EAP_TYPE_AKA_PRIME:
if (tree)
dissect_eap_aka(eap_tree, tvb, offset, size);
break;
case EAP_TYPE_EXT:
{
proto_item *expti = NULL;
proto_tree *exptree = NULL;
expti = proto_tree_add_text(eap_tree, tvb, offset, size, "Expanded Type");
exptree = proto_item_add_subtree(expti, ett_eap_exp_attr);
dissect_exteap(exptree, tvb, offset, size, pinfo);
}
break;
default:
if (tree) {
proto_tree_add_text(eap_tree, tvb, offset, size,
"EAP Data (%d byte%s): \"%s\"",
size, plurality(size, "", "s"),
tvb_bytes_to_ep_str(tvb, offset, size));
}
break;
}
}
}
return tvb_length(tvb);
}
void
proto_register_eap(void)
{
static hf_register_info hf[] = {
{ &hf_eap_code, {
"Code", "eap.code",
FT_UINT8, BASE_DEC, VALS(eap_code_vals), 0x0,
NULL, HFILL }},
{ &hf_eap_identifier, {
"Id", "eap.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_len, {
"Length", "eap.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_type, {
"Type", "eap.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &eap_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_eap_type_nak, {
"Desired Auth Type", "eap.desired_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &eap_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_eap_identity, {
"Identity", "eap.identity",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_notification, {
"Notification", "eap.notification",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_md5_value_size, {
"EAP-MD5 Value-Size", "eap.md5.value_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_md5_value, {
"EAP-MD5 Value", "eap.md5.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_md5_extra_data, {
"EAP-MD5 Extra Data", "eap.md5.extra_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_tls_flags, {
"EAP-TLS Flags", "eap.tls.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_tls_flag_l, {
"Length Included", "eap.tls.flags.len_included",
FT_BOOLEAN, 8, NULL, EAP_TLS_FLAG_L,
NULL, HFILL }},
{ &hf_eap_tls_flag_m, {
"More Fragments", "eap.tls.flags.more_fragments",
FT_BOOLEAN, 8, NULL, EAP_TLS_FLAG_M,
NULL, HFILL }},
{ &hf_eap_tls_flag_s, {
"Start", "eap.tls.flags.start",
FT_BOOLEAN, 8, NULL, EAP_TLS_FLAG_S,
NULL, HFILL }},
{ &hf_eap_tls_flags_version, {
"Version", "eap.tls.flags.version",
FT_UINT8, BASE_DEC, NULL, EAP_TLS_FLAGS_VERSION,
NULL, HFILL }},
{ &hf_eap_tls_len, {
"EAP-TLS Length", "eap.tls.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_tls_fragment, {
"EAP-TLS Fragment", "eap.tls.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_tls_fragments, {
"EAP-TLS Fragments", "eap.tls.fragments",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_tls_fragment_overlap, {
"Fragment Overlap", "eap.tls.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_eap_tls_fragment_overlap_conflict, {
"Conflicting Data In Fragment Overlap", "eap.tls.fragment.overlap_conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_eap_tls_fragment_multiple_tails, {
"Multiple Tail Fragments Found", "eap.tls.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_eap_tls_fragment_too_long_fragment,{
"Fragment Too Long", "eap.tls.fragment.fragment.too_long",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_eap_tls_fragment_error, {
"Defragmentation Error", "eap.tls.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_eap_tls_fragment_count, {
"Fragment Count", "eap.tls.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of the reassembled payload", HFILL }},
{ &hf_eap_tls_reassembled_length, {
"Reassembled EAP-TLS Length", "eap.tls.reassembled.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total length of the reassembled payload", HFILL }},
{ &hf_eap_sim_subtype, {
"EAP-SIM Subtype", "eap.sim.subtype",
FT_UINT8, BASE_DEC, VALS(eap_sim_subtype_vals), 0x0,
NULL, HFILL }},
{ &hf_eap_sim_reserved, {
"EAP-SIM Reserved", "eap.sim.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_sim_subtype_attribute, {
"EAP-SIM Attribute", "eap.sim.subtype.attribute",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_sim_subtype_type, {
"EAP-SIM Type", "eap.sim.subtype.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &eap_sim_aka_attribute_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_eap_sim_subtype_length, {
"EAP-SIM Length", "eap.sim.subtype.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_sim_subtype_value, {
"EAP-SIM Value", "eap.sim.subtype.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_aka_subtype, {
"EAP-AKA Subtype", "eap.aka.subtype",
FT_UINT8, BASE_DEC, VALS(eap_aka_subtype_vals), 0x0,
NULL, HFILL }},
{ &hf_eap_aka_reserved, {
"EAP-AKA Reserved", "eap.aka.reserved",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_aka_subtype_attribute, {
"EAP-AKA Attribute", "eap.aka.subtype.attribute",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_aka_subtype_type, {
"EAP-AKA Type", "eap.aka.subtype.type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &eap_sim_aka_attribute_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_eap_aka_subtype_length, {
"EAP-AKA Length", "eap.aka.subtype.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_aka_subtype_value, {
"EAP-AKA Value", "eap.aka.subtype.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_version, {
"EAP-LEAP Version", "eap.leap.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_reserved, {
"EAP-LEAP Reserved", "eap.leap.reserved",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_count, {
"EAP-LEAP Count", "eap.leap.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_peer_challenge, {
"EAP-LEAP Peer-Challenge", "eap.leap.peer_challenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_peer_response, {
"EAP-LEAP Peer-Response", "eap.leap.peer_response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_ap_challenge, {
"EAP-LEAP AP-Challenge", "eap.leap.ap_challenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_ap_response, {
"EAP-LEAP AP-Response", "eap.leap.ap_response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_leap_name, {
"EAP-LEAP Name", "eap.leap.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_opcode, {
"EAP-MS-CHAP-v2 OpCode", "eap.ms_chap_v2.opcode",
FT_UINT8, BASE_DEC, VALS(eap_ms_chap_v2_opcode_vals), 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_id, {
"EAP-MS-CHAP-v2 Id", "eap.ms_chap_v2.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_length, {
"EAP-MS-CHAP-v2 Length", "eap.ms_chap_v2.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_value_size, {
"EAP-MS-CHAP-v2 Value-Size", "eap.ms_chap_v2.value_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_challenge, {
"EAP-MS-CHAP-v2 Challenge", "eap.ms_chap_v2.challenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_name, {
"EAP-MS-CHAP-v2 Name", "eap.ms_chap_v2.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_peer_challenge, {
"EAP-MS-CHAP-v2 Peer-Challenge", "eap.ms_chap_v2.peer_challenge",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_reserved, {
"EAP-MS-CHAP-v2 Reserved", "eap.ms_chap_v2.reserved",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_nt_response, {
"EAP-MS-CHAP-v2 NT-Response", "eap.ms_chap_v2.nt_response",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_flags, {
"EAP-MS-CHAP-v2 Flags", "eap.ms_chap_v2.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_message, {
"EAP-MS-CHAP-v2 Message", "eap.ms_chap_v2.message",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ms_chap_v2_failure_request, {
"EAP-MS-CHAP-v2 Failure-Request", "eap.ms_chap_v2.failure_request",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_eap_ext_vendor_id, {
"EAP-EXT Vendor Id", "eap.ext.vendor_id",
FT_UINT16, BASE_HEX, VALS(eap_ext_vendor_id_vals), 0x0,
NULL, HFILL }},
{ &hf_eap_ext_vendor_type, {
"EAP-EXT Vendor Type", "eap.ext.vendor_type",
FT_UINT8, BASE_HEX, VALS(eap_ext_vendor_type_vals), 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_eap,
&ett_eap_tls_fragment,
&ett_eap_tls_fragments,
&ett_eap_sim_attr,
&ett_eap_aka_attr,
&ett_eap_exp_attr,
&ett_eap_tls_flags
};
static ei_register_info ei[] = {
{ &ei_eap_ms_chap_v2_length, { "eap.ms_chap_v2.length.invalid", PI_PROTOCOL, PI_WARN, "Invalid Length", EXPFILL }},
{ &ei_eap_mitm_attacks, { "eap.mitm_attacks", PI_SECURITY, PI_WARN, "Vulnerable to MITM attacks. If possible, change EAP type.", EXPFILL }},
{ &ei_eap_md5_value_size_overflow, { "eap.md5.value_size.overflow", PI_PROTOCOL, PI_WARN, "Overflow", EXPFILL }},
{ &ei_eap_dictionary_attacks, { "eap.dictionary_attacks", PI_SECURITY, PI_WARN,
"Vulnerable to dictionary attacks. If possible, change EAP type."
" See http://www.cisco.com/warp/public/cc/pd/witc/ao350ap/prodlit/2331_pp.pdf", EXPFILL }},
};
expert_module_t* expert_eap;
proto_eap = proto_register_protocol("Extensible Authentication Protocol",
"EAP", "eap");
proto_register_field_array(proto_eap, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_eap = expert_register_protocol(proto_eap);
expert_register_field_array(expert_eap, ei, array_length(ei));
eap_handle = new_register_dissector("eap", dissect_eap, proto_eap);
register_init_routine(eap_tls_defragment_init);
}
void
proto_reg_handoff_eap(void)
{
ssl_handle = find_dissector("ssl");
dissector_add_uint("ppp.protocol", PPP_EAP, eap_handle);
}
