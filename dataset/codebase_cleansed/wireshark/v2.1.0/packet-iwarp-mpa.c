static mpa_state_t *
init_mpa_state(void)
{
mpa_state_t *state;
state = (mpa_state_t *) wmem_alloc0(wmem_file_scope(), sizeof(mpa_state_t));
state->revision = -1;
return state;
}
static mpa_state_t *
get_mpa_state(conversation_t *conversation)
{
if (conversation) {
return (mpa_state_t*) conversation_get_proto_data(conversation,
proto_iwarp_mpa);
} else {
return NULL;
}
}
static guint32
get_first_marker_offset(mpa_state_t *state, struct tcpinfo *tcpinfo,
guint8 endpoint)
{
guint32 offset = 0;
if (tcpinfo->seq > state->minfo[endpoint].seq) {
offset = (tcpinfo->seq - state->minfo[endpoint].seq)
% MPA_MARKER_INTERVAL;
}
if (tcpinfo->seq < state->minfo[endpoint].seq) {
offset = state->minfo[endpoint].seq
+ (TCP_MAX_SEQ - tcpinfo->seq) % MPA_MARKER_INTERVAL;
}
return (MPA_MARKER_INTERVAL - offset) % MPA_MARKER_INTERVAL;
}
static guint32
fpdu_total_length(struct tcpinfo *tcpinfo)
{
guint32 size = 0;
if (tcpinfo->seq < tcpinfo->nxtseq) {
size = tcpinfo->nxtseq - tcpinfo->seq;
}
if (tcpinfo->seq >= tcpinfo->nxtseq) {
size = tcpinfo->nxtseq + (TCP_MAX_SEQ - tcpinfo->seq);
}
return size;
}
static guint32
number_of_markers(mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint)
{
guint32 size;
guint32 offset;
size = fpdu_total_length(tcpinfo);
offset = get_first_marker_offset(state, tcpinfo, endpoint);
if (offset < size) {
return ((size - offset) / MPA_MARKER_INTERVAL)+1;
} else {
return 0;
}
}
static tvbuff_t *
remove_markers(tvbuff_t *tvb, packet_info *pinfo, guint32 marker_offset,
guint32 num_markers, guint32 orig_length)
{
guint8 *mfree_buff = NULL;
guint32 mfree_buff_length, tot_copy, cur_copy;
guint32 source_offset;
tvbuff_t *mfree_tvb = NULL;
DISSECTOR_ASSERT(num_markers > 0);
DISSECTOR_ASSERT(orig_length > MPA_MARKER_LEN * num_markers);
DISSECTOR_ASSERT(tvb_captured_length(tvb) == orig_length);
mfree_buff_length = orig_length - (MPA_MARKER_LEN * num_markers);
mfree_buff = (guint8 *)wmem_alloc(pinfo->pool, mfree_buff_length);
tot_copy = 0;
source_offset = 0;
cur_copy = marker_offset;
while (tot_copy < mfree_buff_length) {
tvb_memcpy(tvb, mfree_buff+tot_copy, source_offset, cur_copy);
tot_copy += cur_copy;
source_offset += cur_copy + MPA_MARKER_LEN;
cur_copy = MIN(MPA_MARKER_INTERVAL, (mfree_buff_length - tot_copy));
}
mfree_tvb = tvb_new_child_real_data(tvb, mfree_buff, mfree_buff_length,
mfree_buff_length);
add_new_data_source(pinfo, mfree_tvb, "FPDU without Markers");
return mfree_tvb;
}
static gboolean
is_mpa_req(tvbuff_t *tvb, packet_info *pinfo)
{
conversation_t *conversation = NULL;
mpa_state_t *state = NULL;
guint8 mcrres;
if (tvb_get_ntoh64(tvb, 0) != MPA_REQ_REP_FRAME
|| tvb_get_ntoh64(tvb, 8) != MPA_ID_REQ_FRAME)
return FALSE;
conversation = find_or_create_conversation(pinfo);
if (!get_mpa_state(conversation)) {
state = init_mpa_state();
mcrres = tvb_get_guint8(tvb, 16);
state->ini_exp_m_res = mcrres & MPA_MARKER_FLAG;
state->crc = mcrres & MPA_CRC_FLAG;
state->revision = tvb_get_guint8(tvb, 17);
state->req_frame_num = pinfo->num;
state->minfo[MPA_INITIATOR].port = pinfo->srcport;
state->minfo[MPA_RESPONDER].port = pinfo->destport;
conversation_add_proto_data(conversation, proto_iwarp_mpa, state);
if (mcrres & MPA_RESERVED_FLAG)
expert_add_info(pinfo, NULL, &ei_mpa_res_field_not_set0);
if (state->revision != 1)
expert_add_info(pinfo, NULL, &ei_mpa_rev_field_not_set1);
}
return TRUE;
}
static gboolean
is_mpa_rep(tvbuff_t *tvb, packet_info *pinfo)
{
conversation_t *conversation = NULL;
mpa_state_t *state = NULL;
guint8 mcrres;
if (tvb_get_ntoh64(tvb, 0) != MPA_REQ_REP_FRAME
|| tvb_get_ntoh64(tvb, 8) != MPA_ID_REP_FRAME) {
return FALSE;
}
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (!conversation) {
return FALSE;
}
state = get_mpa_state(conversation);
if (!state) {
return FALSE;
}
if (!state->full_operation) {
mcrres = tvb_get_guint8(tvb, 16);
state->res_exp_m_ini = mcrres & MPA_MARKER_FLAG;
state->crc = state->crc | (mcrres & MPA_CRC_FLAG);
state->rep_frame_num = pinfo->num;
if (!(mcrres & MPA_REJECT_FLAG))
state->full_operation = TRUE;
else
expert_add_info(pinfo, NULL, &ei_mpa_reject_bit_responder);
}
return TRUE;
}
static gboolean
is_mpa_fpdu(packet_info *pinfo)
{
conversation_t *conversation = NULL;
mpa_state_t *state = NULL;
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (!conversation) {
return FALSE;
}
state = get_mpa_state(conversation);
if (!state) {
return FALSE;
}
if (!state->full_operation) {
return FALSE;
}
if (pinfo->num == state->req_frame_num
|| pinfo->num == state->rep_frame_num) {
return FALSE;
} else {
return TRUE;
}
}
static void
mpa_packetlist(packet_info *pinfo, gint message_type)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPA");
col_add_fstr(pinfo->cinfo, COL_INFO,
"%d > %d %s", pinfo->srcport, pinfo->destport,
val_to_str(message_type, mpa_messages,
"Unknown %d"));
}
static gboolean
dissect_mpa_req_rep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint message_type)
{
proto_tree *mpa_tree = NULL;
proto_tree *mpa_header_tree = NULL;
proto_item *mpa_item = NULL;
proto_item *mpa_header_item = NULL;
guint16 pd_length;
guint32 offset = 0;
mpa_packetlist(pinfo, message_type);
if (tree) {
mpa_item = proto_tree_add_item(tree, proto_iwarp_mpa, tvb, 0,
-1, ENC_NA);
mpa_tree = proto_item_add_subtree(mpa_item, ett_mpa);
if (message_type == MPA_REQUEST_FRAME) {
mpa_header_item = proto_tree_add_item(mpa_tree,
hf_mpa_req, tvb, offset, -1, ENC_NA);
mpa_header_tree = proto_item_add_subtree(
mpa_header_item, ett_mpa);
proto_tree_add_item(mpa_header_tree, hf_mpa_key_req,
tvb, offset, MPA_REQ_REP_KEY_LEN, ENC_NA);
}
if (message_type == MPA_REPLY_FRAME) {
mpa_header_item = proto_tree_add_item(mpa_tree,
hf_mpa_rep, tvb, offset, -1, ENC_NA);
mpa_header_tree = proto_item_add_subtree(
mpa_header_item, ett_mpa);
proto_tree_add_item(mpa_header_tree, hf_mpa_key_rep,
tvb, offset, MPA_REQ_REP_KEY_LEN, ENC_NA);
}
offset += MPA_REQ_REP_KEY_LEN;
proto_tree_add_item(mpa_header_tree, hf_mpa_flag_m, tvb,
offset, MPA_REQ_REP_FLAG_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(mpa_header_tree, hf_mpa_flag_c, tvb,
offset, MPA_REQ_REP_FLAG_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(mpa_header_tree, hf_mpa_flag_r, tvb,
offset, MPA_REQ_REP_FLAG_LEN, ENC_BIG_ENDIAN);
proto_tree_add_item(mpa_header_tree, hf_mpa_flag_res, tvb,
offset, MPA_REQ_REP_FLAG_LEN, ENC_BIG_ENDIAN);
offset += MPA_REQ_REP_FLAG_LEN;
proto_tree_add_item(mpa_header_tree, hf_mpa_rev, tvb,
offset, MPA_REQ_REP_REV_LEN, ENC_BIG_ENDIAN);
offset += MPA_REQ_REP_REV_LEN;
pd_length = tvb_get_ntohs(tvb, offset);
if (pd_length > MPA_MAX_PD_LENGTH) {
proto_tree_add_expert_format(tree, pinfo, &ei_mpa_bad_length, tvb, offset, 2,
"[PD length field indicates more 512 bytes of Private Data]");
return FALSE;
}
proto_tree_add_uint_format_value(mpa_header_tree,
hf_mpa_pd_length, tvb, offset,
MPA_REQ_REP_PDLENGTH_LEN, pd_length, "%u bytes",
pd_length);
offset += MPA_REQ_REP_PDLENGTH_LEN;
if (pd_length) {
proto_tree_add_item(mpa_header_tree,
hf_mpa_private_data, tvb, offset,
pd_length, ENC_NA);
}
}
return TRUE;
}
static guint8
fpdu_pad_length(guint16 ulpdu_length)
{
guint32 length = ulpdu_length + MPA_ULPDU_LENGTH_LEN;
return (MPA_ALIGNMENT - (length % MPA_ALIGNMENT)) % MPA_ALIGNMENT;
}
static guint32
pad_offset(struct tcpinfo *tcpinfo, guint32 fpdu_total_len,
guint8 pad_len)
{
if ((tcpinfo->nxtseq - MPA_CRC_LEN - MPA_MARKER_LEN) % MPA_MARKER_INTERVAL
== 0) {
return fpdu_total_len - MPA_CRC_LEN - MPA_MARKER_LEN - pad_len;
} else {
return fpdu_total_len - MPA_CRC_LEN - pad_len;
}
}
static void
dissect_fpdu_crc(tvbuff_t *tvb, proto_tree *tree, mpa_state_t *state,
guint32 offset, guint32 length)
{
guint32 crc = 0;
guint32 sent_crc = 0;
if (state->crc) {
crc = ~crc32c_tvb_offset_calculate(tvb, 0, length, CRC32C_PRELOAD);
sent_crc = tvb_get_ntohl(tvb, offset);
if (crc == sent_crc) {
proto_tree_add_uint_format_value(tree,
hf_mpa_crc_check, tvb, offset, MPA_CRC_LEN,
sent_crc, "0x%08x (Good CRC32)",
sent_crc);
} else {
proto_tree_add_uint_format_value(tree,
hf_mpa_crc_check, tvb, offset, MPA_CRC_LEN,
sent_crc,
"0x%08x (Bad CRC32, should be 0x%08x)",
sent_crc, crc);
}
} else {
proto_tree_add_item(tree, hf_mpa_crc, tvb, offset, MPA_CRC_LEN,
ENC_BIG_ENDIAN);
}
}
static void
dissect_fpdu_markers(tvbuff_t *tvb, proto_tree *tree, mpa_state_t *state,
struct tcpinfo *tcpinfo, guint8 endpoint)
{
proto_tree *mpa_marker_tree;
proto_item *mpa_marker_item;
guint16 fpduptr;
guint32 offset, i;
mpa_marker_item = proto_tree_add_item(tree, hf_mpa_marker, tvb,
0, -1, ENC_NA);
mpa_marker_tree = proto_item_add_subtree(mpa_marker_item, ett_mpa);
offset = get_first_marker_offset(state, tcpinfo, endpoint);
for (i=0; i<number_of_markers(state, tcpinfo, endpoint); i++) {
proto_tree_add_item(mpa_marker_tree, hf_mpa_marker_res, tvb,
offset, MPA_MARKER_RSVD_LEN, ENC_BIG_ENDIAN);
fpduptr = (guint16) tvb_get_ntohs(tvb, offset+MPA_MARKER_RSVD_LEN);
proto_tree_add_uint_format_value(mpa_marker_tree,
hf_mpa_marker_fpduptr, tvb,
offset+MPA_MARKER_RSVD_LEN, MPA_MARKER_FPDUPTR_LEN,
fpduptr, "%u bytes", fpduptr);
offset += MPA_MARKER_INTERVAL;
}
}
static guint16
expected_ulpdu_length(mpa_state_t *state, struct tcpinfo *tcpinfo,
guint8 endpoint)
{
guint32 length, pad_length, markers_length;
length = fpdu_total_length(tcpinfo);
if (length <= MPA_CRC_LEN)
return 0;
length -= MPA_CRC_LEN;
pad_length = (MPA_ALIGNMENT - (length % MPA_ALIGNMENT)) % MPA_ALIGNMENT;
if (length <= pad_length)
return 0;
length -= pad_length;
if (state->minfo[endpoint].valid) {
markers_length =
number_of_markers(state, tcpinfo, endpoint) * MPA_MARKER_LEN;
if (length <= markers_length)
return 0;
length -= markers_length;
}
if (length <= MPA_ULPDU_LENGTH_LEN)
return 0;
length -= MPA_ULPDU_LENGTH_LEN;
return (guint16) length;
}
static guint16
dissect_mpa_fpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
mpa_state_t *state, struct tcpinfo *tcpinfo, guint8 endpoint)
{
proto_item *mpa_item = NULL;
proto_item *mpa_header_item = NULL;
proto_tree *mpa_tree = NULL;
proto_tree *mpa_header_tree = NULL;
guint8 pad_length;
guint16 ulpdu_length, exp_ulpdu_length;
guint32 offset, total_length;
guint32 num_of_m = 0;
if (state->minfo[endpoint].valid
&& get_first_marker_offset(state, tcpinfo, endpoint) == 0) {
offset = MPA_MARKER_LEN;
} else {
offset = 0;
}
ulpdu_length = (guint16) tvb_get_ntohs(tvb, offset);
mpa_packetlist(pinfo, MPA_FPDU);
if (state->minfo[endpoint].valid) {
num_of_m = number_of_markers(state, tcpinfo, endpoint);
}
if (tree) {
pad_length = fpdu_pad_length(ulpdu_length);
exp_ulpdu_length = expected_ulpdu_length(state, tcpinfo, endpoint);
if (!exp_ulpdu_length || exp_ulpdu_length != (ulpdu_length + pad_length)) {
proto_tree_add_expert_format(tree, pinfo, &ei_mpa_bad_length, tvb, offset,
MPA_ULPDU_LENGTH_LEN,
"[ULPDU length [%u] field does not contain the expected length[%u]]",
exp_ulpdu_length, ulpdu_length + pad_length);
}
mpa_item = proto_tree_add_item(tree, proto_iwarp_mpa, tvb, 0,
-1, ENC_NA);
mpa_tree = proto_item_add_subtree(mpa_item, ett_mpa);
mpa_header_item = proto_tree_add_item(mpa_tree, hf_mpa_fpdu,
tvb, offset, -1, ENC_NA);
mpa_header_tree = proto_item_add_subtree(mpa_header_item,
ett_mpa);
proto_tree_add_uint_format_value(mpa_header_tree,
hf_mpa_ulpdu_length, tvb, offset,
MPA_ULPDU_LENGTH_LEN, ulpdu_length, "%u bytes",
ulpdu_length);
if (state->minfo[endpoint].valid && num_of_m > 0) {
total_length = fpdu_total_length(tcpinfo);
if (pad_length > 0) {
proto_tree_add_item(mpa_header_tree, hf_mpa_pad,
tvb, pad_offset(tcpinfo,
total_length,
pad_length),
pad_length, ENC_NA);
}
dissect_fpdu_crc(tvb, mpa_header_tree, state,
total_length-MPA_CRC_LEN, num_of_m * MPA_MARKER_LEN +
ulpdu_length + pad_length + MPA_ULPDU_LENGTH_LEN);
dissect_fpdu_markers(tvb, mpa_tree, state, tcpinfo, endpoint);
} else {
offset += MPA_ULPDU_LENGTH_LEN + ulpdu_length;
if (pad_length > 0) {
proto_tree_add_item(mpa_header_tree, hf_mpa_pad, tvb, offset,
pad_length, ENC_NA);
offset += pad_length;
}
dissect_fpdu_crc(tvb, mpa_header_tree, state, offset,
ulpdu_length+pad_length+MPA_ULPDU_LENGTH_LEN);
}
}
return ulpdu_length;
}
static gboolean
dissect_iwarp_mpa(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tvbuff_t *next_tvb = NULL;
conversation_t *conversation = NULL;
mpa_state_t *state = NULL;
struct tcpinfo *tcpinfo;
guint8 endpoint = 3;
guint16 ulpdu_length = 0;
if (data == NULL)
return FALSE;
tcpinfo = (struct tcpinfo *)data;
if (tvb_captured_length(tvb) >= MPA_SMALLEST_FPDU_LEN && is_mpa_fpdu(pinfo)) {
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport, pinfo->destport, 0);
state = get_mpa_state(conversation);
if (pinfo->srcport == state->minfo[MPA_INITIATOR].port) {
endpoint = MPA_INITIATOR;
} else if (pinfo->srcport == state->minfo[MPA_RESPONDER].port) {
endpoint = MPA_RESPONDER;
} else {
REPORT_DISSECTOR_BUG("endpoint cannot be determined");
}
if ((state->ini_exp_m_res || state->res_exp_m_ini) && endpoint <= MPA_RESPONDER) {
if (!state->minfo[endpoint].valid) {
state->minfo[endpoint].seq = tcpinfo->seq;
state->minfo[endpoint].valid = TRUE;
}
}
ulpdu_length = dissect_mpa_fpdu(tvb, pinfo, tree, state, tcpinfo,
endpoint);
if (!ulpdu_length)
return FALSE;
if (endpoint <= MPA_RESPONDER && state->minfo[endpoint].valid
&& number_of_markers(state, tcpinfo, endpoint) > 0) {
next_tvb = tvb_new_subset_length(remove_markers(tvb, pinfo,
get_first_marker_offset(state, tcpinfo, endpoint),
number_of_markers(state, tcpinfo, endpoint),
fpdu_total_length(tcpinfo)), MPA_ULPDU_LENGTH_LEN,
ulpdu_length);
} else {
next_tvb = tvb_new_subset_length(tvb, MPA_ULPDU_LENGTH_LEN, ulpdu_length);
}
if (ddp_rdmap_handle) {
call_dissector(ddp_rdmap_handle, next_tvb, pinfo, tree);
} else {
REPORT_DISSECTOR_BUG("ddp_handle was null");
}
return TRUE;
}
if (tvb_captured_length(tvb) >= MPA_REQ_REP_FRAME_HEADER_LEN) {
if (is_mpa_req(tvb, pinfo))
return dissect_mpa_req_rep(tvb, pinfo, tree, MPA_REQUEST_FRAME);
else if (is_mpa_rep(tvb, pinfo))
return dissect_mpa_req_rep(tvb, pinfo, tree, MPA_REPLY_FRAME);
}
return FALSE;
}
void proto_register_mpa(void)
{
static hf_register_info hf[] = {
{ &hf_mpa_req, {
"Request frame header", "iwarp_mpa.req",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_rep, {
"Reply frame header", "iwarp_mpa.rep",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_fpdu, {
"FPDU", "iwarp_mpa.fpdu",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_marker, {
"Markers", "iwarp_mpa.markers",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_key_req, {
"ID Req frame", "iwarp_mpa.key.req",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_key_rep, {
"ID Rep frame", "iwarp_mpa.key.rep",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_flag_m, {
"Marker flag", "iwarp_mpa.marker_flag",
FT_BOOLEAN, 8, NULL, MPA_MARKER_FLAG,
NULL, HFILL } },
{ &hf_mpa_flag_c, {
"CRC flag", "iwarp_mpa.crc_flag",
FT_BOOLEAN, 8, NULL, MPA_CRC_FLAG,
NULL, HFILL } },
{ &hf_mpa_flag_r, {
"Connection rejected flag",
"iwarp_mpa.rej_flag", FT_BOOLEAN, 8, NULL, MPA_REJECT_FLAG,
NULL, HFILL } },
{ &hf_mpa_flag_res, {
"Reserved", "iwarp_mpa.res",
FT_UINT8, BASE_HEX, NULL, MPA_RESERVED_FLAG,
NULL, HFILL } },
{ &hf_mpa_rev, {
"Revision", "iwarp_mpa.rev",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_pd_length, {
"Private data length", "iwarp_mpa.pdlength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_private_data, {
"Private data", "iwarp_mpa.privatedata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_ulpdu_length, {
"ULPDU length", "iwarp_mpa.ulpdulength",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_pad, {
"Padding", "iwarp_mpa.pad",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_crc, {
"CRC", "iwarp_mpa.crc",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_crc_check, {
"CRC check", "iwarp_mpa.crc_check",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_mpa_marker_res, {
"Reserved", "iwarp_mpa.marker_res",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Marker: Reserved", HFILL } },
{ &hf_mpa_marker_fpduptr, {
"FPDU back pointer", "iwarp_mpa.marker_fpduptr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Marker: FPDU Pointer", HFILL } }
};
static gint *ett[] = {
&ett_mpa,
&ett_mpa_req,
&ett_mpa_rep,
&ett_mpa_fpdu,
&ett_mpa_marker
};
static ei_register_info ei[] = {
{ &ei_mpa_res_field_not_set0, { "iwarp_mpa.res.not_set0", PI_REQUEST_CODE, PI_WARN, "Res field is NOT set to zero as required by RFC 5044", EXPFILL }},
{ &ei_mpa_rev_field_not_set1, { "iwarp_mpa.rev.not_set1", PI_REQUEST_CODE, PI_WARN, "Rev field is NOT set to one as required by RFC 5044", EXPFILL }},
{ &ei_mpa_reject_bit_responder, { "iwarp_mpa.reject_bit_responder", PI_RESPONSE_CODE, PI_NOTE, "Reject bit set by Responder", EXPFILL }},
{ &ei_mpa_bad_length, { "iwarp_mpa.bad_length", PI_MALFORMED, PI_ERROR, "Bad length", EXPFILL }},
};
expert_module_t* expert_iwarp_mpa;
proto_iwarp_mpa = proto_register_protocol(
"iWARP Marker Protocol data unit Aligned framing",
"IWARP_MPA", "iwarp_mpa");
proto_register_field_array(proto_iwarp_mpa, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_iwarp_mpa = expert_register_protocol(proto_iwarp_mpa);
expert_register_field_array(expert_iwarp_mpa, ei, array_length(ei));
}
void
proto_reg_handoff_mpa(void)
{
heur_dissector_add("tcp", dissect_iwarp_mpa, "IWARP_MPA over TCP", "iwarp_mpa_tcp", proto_iwarp_mpa, HEURISTIC_ENABLE);
ddp_rdmap_handle = find_dissector_add_dependency("iwarp_ddp_rdmap", proto_iwarp_mpa);
}
