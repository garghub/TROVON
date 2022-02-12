static mp2t_analysis_data_t *
init_mp2t_conversation_data(void)
{
mp2t_analysis_data_t *mp2t_data;
mp2t_data = wmem_new0(wmem_file_scope(), struct mp2t_analysis_data);
mp2t_data->pid_table = wmem_tree_new(wmem_file_scope());
mp2t_data->frame_table = wmem_tree_new(wmem_file_scope());
mp2t_data->total_skips = 0;
mp2t_data->total_discontinuity = 0;
return mp2t_data;
}
static mp2t_analysis_data_t *
get_mp2t_conversation_data(conversation_t *conv)
{
mp2t_analysis_data_t *mp2t_data;
mp2t_data = (mp2t_analysis_data_t *)conversation_get_proto_data(conv, proto_mp2t);
if (!mp2t_data) {
mp2t_data = init_mp2t_conversation_data();
conversation_add_proto_data(conv, proto_mp2t, mp2t_data);
}
return mp2t_data;
}
static frame_analysis_data_t *
init_frame_analysis_data(mp2t_analysis_data_t *mp2t_data, packet_info *pinfo)
{
frame_analysis_data_t *frame_analysis_data_p;
frame_analysis_data_p = wmem_new0(wmem_file_scope(), struct frame_analysis_data);
frame_analysis_data_p->ts_table = wmem_tree_new(wmem_file_scope());
wmem_tree_insert32(mp2t_data->frame_table, pinfo->fd->num,
(void *)frame_analysis_data_p);
return frame_analysis_data_p;
}
static frame_analysis_data_t *
get_frame_analysis_data(mp2t_analysis_data_t *mp2t_data, packet_info *pinfo)
{
frame_analysis_data_t *frame_analysis_data_p;
frame_analysis_data_p = (frame_analysis_data_t *)wmem_tree_lookup32(mp2t_data->frame_table, pinfo->fd->num);
return frame_analysis_data_p;
}
static pid_analysis_data_t *
get_pid_analysis(mp2t_analysis_data_t *mp2t_data, guint32 pid)
{
pid_analysis_data_t *pid_data;
pid_data = (pid_analysis_data_t *)wmem_tree_lookup32(mp2t_data->pid_table, pid);
if (!pid_data) {
pid_data = wmem_new0(wmem_file_scope(), struct pid_analysis_data);
pid_data->cc_prev = -1;
pid_data->pid = pid;
pid_data->frag_id = (pid << (32 - 13)) | 0x1;
wmem_tree_insert32(mp2t_data->pid_table, pid, (void *)pid_data);
}
return pid_data;
}
static void
mp2t_dissect_packet(tvbuff_t *tvb, enum pid_payload_type pload_type,
packet_info *pinfo, proto_tree *tree)
{
dissector_handle_t handle = NULL;
switch (pload_type) {
case pid_pload_docsis:
handle = docsis_handle;
break;
case pid_pload_pes:
handle = mpeg_pes_handle;
break;
case pid_pload_sect:
handle = mpeg_sect_handle;
break;
default:
break;
}
if (handle)
call_dissector(handle, tvb, pinfo, tree);
else
call_dissector(data_handle, tvb, pinfo, tree);
}
static guint
mp2t_get_packet_length(tvbuff_t *tvb, guint offset, packet_info *pinfo,
guint32 frag_id, enum pid_payload_type pload_type)
{
fragment_head *frag;
tvbuff_t *len_tvb = NULL, *frag_tvb = NULL, *data_tvb = NULL;
gint pkt_len = 0;
guint remaining_len;
frag = fragment_get(&mp2t_reassembly_table, pinfo, frag_id, NULL);
if (frag)
frag = frag->next;
if (!frag) {
remaining_len = tvb_reported_length_remaining(tvb, offset);
if ( (pload_type == pid_pload_docsis && remaining_len < 4) ||
(pload_type == pid_pload_sect && remaining_len < 3) ||
(pload_type == pid_pload_pes && remaining_len < 5) ) {
return -1;
}
len_tvb = tvb;
} else {
frag_tvb = tvb_new_proxy(frag->tvb_data);
len_tvb = tvb_new_composite();
tvb_composite_append(len_tvb, frag_tvb);
data_tvb = tvb_new_subset_remaining(tvb, offset);
tvb_composite_append(len_tvb, data_tvb);
tvb_composite_finalize(len_tvb);
offset = frag->offset;
}
switch (pload_type) {
case pid_pload_docsis:
pkt_len = tvb_get_ntohs(len_tvb, offset + 2) + 6;
break;
case pid_pload_pes:
pkt_len = tvb_get_ntohs(len_tvb, offset + 4);
if (pkt_len)
pkt_len += 6;
break;
case pid_pload_sect:
pkt_len = (tvb_get_ntohs(len_tvb, offset + 1) & 0xFFF) + 3;
break;
default:
break;
}
if (frag_tvb)
tvb_free(frag_tvb);
return pkt_len;
}
static void
mp2t_fragment_handle(tvbuff_t *tvb, guint offset, packet_info *pinfo,
proto_tree *tree, guint32 frag_id,
guint frag_offset, guint frag_len,
gboolean fragment_last, enum pid_payload_type pload_type)
{
fragment_head *frag_msg;
tvbuff_t *new_tvb;
gboolean save_fragmented;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
SET_ADDRESS_HF(&pinfo->src, AT_NONE, 0, NULL, 0);
SET_ADDRESS_HF(&pinfo->dst, AT_NONE, 0, NULL, 0);
frag_msg = fragment_add_check(&mp2t_reassembly_table,
tvb, offset, pinfo, frag_id, NULL,
frag_offset,
frag_len,
!fragment_last);
new_tvb = process_reassembled_data(tvb, offset, pinfo,
"Reassembled MP2T",
frag_msg, &mp2t_msg_frag_items,
NULL, tree);
if (new_tvb) {
proto_tree_add_item(tree, hf_msg_ts_packet_reassembled, tvb, 0, 0, ENC_NA);
mp2t_dissect_packet(new_tvb, pload_type, pinfo, tree);
}
pinfo->fragmented = save_fragmented;
}
static void
mp2t_process_fragmented_payload(tvbuff_t *tvb, gint offset, guint remaining_len, packet_info *pinfo,
proto_tree *tree, proto_tree *header_tree, guint32 pusi_flag,
pid_analysis_data_t *pid_analysis)
{
tvbuff_t *next_tvb;
guint8 pointer = 0;
proto_item *pi;
guint stuff_len = 0;
proto_tree *stuff_tree;
packet_analysis_data_t *pdata = NULL;
subpacket_analysis_data_t *spdata = NULL;
guint32 frag_cur_pos = 0, frag_tot_len = 0;
gboolean fragmentation = FALSE;
guint32 frag_id = 0;
if (pusi_flag && pid_analysis->pload_type == pid_pload_unknown
&& remaining_len > 3) {
if (tvb_get_ntoh24(tvb, offset) == 0x000001) {
pid_analysis->pload_type = pid_pload_pes;
} else {
pid_analysis->pload_type = pid_pload_sect;
}
}
if (pid_analysis->pload_type == pid_pload_unknown)
return;
if (pusi_flag && pid_analysis->pload_type != pid_pload_pes) {
pointer = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(header_tree, hf_mp2t_pointer, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
remaining_len--;
if (pointer > remaining_len) {
expert_add_info_format(pinfo, pi, &ei_mp2t_pointer,
"Pointer value is too large (> remaining data length %u)",
remaining_len);
}
}
if (!pinfo->fd->flags.visited) {
frag_cur_pos = pid_analysis->frag_cur_pos;
frag_tot_len = pid_analysis->frag_tot_len;
fragmentation = pid_analysis->fragmentation;
frag_id = pid_analysis->frag_id;
pdata = (packet_analysis_data_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_mp2t, 0);
if (!pdata) {
pdata = wmem_new0(wmem_file_scope(), packet_analysis_data_t);
pdata->subpacket_table = wmem_tree_new(wmem_file_scope());
p_add_proto_data(wmem_file_scope(), pinfo, proto_mp2t, 0, pdata);
} else {
spdata = (subpacket_analysis_data_t *)wmem_tree_lookup32(pdata->subpacket_table, offset);
}
if (!spdata) {
spdata = wmem_new0(wmem_file_scope(), subpacket_analysis_data_t);
spdata->frag_cur_pos = frag_cur_pos;
spdata->frag_tot_len = frag_tot_len;
spdata->fragmentation = fragmentation;
spdata->frag_id = frag_id;
wmem_tree_insert32(pdata->subpacket_table, offset, (void *)spdata);
}
} else {
pdata = (packet_analysis_data_t *)p_get_proto_data(wmem_file_scope(), pinfo, proto_mp2t, 0);
if (!pdata) {
return;
}
spdata = (subpacket_analysis_data_t *)wmem_tree_lookup32(pdata->subpacket_table, offset);
if (!spdata) {
return;
}
frag_cur_pos = spdata->frag_cur_pos;
frag_tot_len = spdata->frag_tot_len;
fragmentation = spdata->fragmentation;
frag_id = spdata->frag_id;
}
if (frag_tot_len == (guint)-1) {
frag_tot_len = mp2t_get_packet_length(tvb, offset, pinfo, frag_id, pid_analysis->pload_type);
if (frag_tot_len == (guint)-1) {
return;
}
}
if (pusi_flag) {
if (pointer > remaining_len) {
return;
}
if (fragmentation) {
mp2t_fragment_handle(tvb, offset, pinfo, tree, frag_id, frag_cur_pos,
pointer, TRUE, pid_analysis->pload_type);
frag_id++;
}
offset += pointer;
remaining_len -= pointer;
fragmentation = FALSE;
frag_cur_pos = 0;
frag_tot_len = 0;
if (!remaining_len) {
goto save_state;
}
while (remaining_len > 0) {
stuff_len = 0;
while ((tvb_get_guint8(tvb, offset + stuff_len) == 0xFF)) {
stuff_len++;
if (stuff_len >= remaining_len) {
remaining_len = 0;
break;
}
}
if (stuff_len) {
stuff_tree = proto_tree_add_subtree_format(tree, tvb, offset, stuff_len, ett_stuff, NULL, "Stuffing");
proto_tree_add_item(stuff_tree, hf_mp2t_stuff_bytes, tvb, offset, stuff_len, ENC_NA);
offset += stuff_len;
if (stuff_len >= remaining_len) {
goto save_state;
}
remaining_len -= stuff_len;
}
frag_tot_len = mp2t_get_packet_length(tvb, offset, pinfo, frag_id, pid_analysis->pload_type);
if (frag_tot_len == (guint)-1 || !frag_tot_len) {
mp2t_fragment_handle(tvb, offset, pinfo, tree, frag_id, 0, remaining_len, FALSE, pid_analysis->pload_type);
fragmentation = TRUE;
frag_cur_pos += remaining_len;
goto save_state;
}
if (frag_tot_len &&
frag_tot_len <= remaining_len) {
next_tvb = tvb_new_subset_length(tvb, offset, frag_tot_len);
mp2t_dissect_packet(next_tvb, pid_analysis->pload_type, pinfo, tree);
remaining_len -= frag_tot_len;
offset += frag_tot_len;
frag_tot_len = 0;
frag_id++;
} else {
break;
}
}
if (remaining_len == 0) {
pid_analysis->frag_cur_pos = 0;
pid_analysis->frag_tot_len = 0;
goto save_state;
}
}
if ((frag_tot_len && frag_cur_pos + remaining_len >= frag_tot_len) || (!frag_tot_len && pusi_flag)) {
mp2t_fragment_handle(tvb, offset, pinfo, tree, frag_id, frag_cur_pos, remaining_len, TRUE, pid_analysis->pload_type);
frag_id++;
fragmentation = FALSE;
frag_cur_pos = 0;
frag_tot_len = 0;
} else {
mp2t_fragment_handle(tvb, offset, pinfo, tree, frag_id, frag_cur_pos, remaining_len, FALSE, pid_analysis->pload_type);
fragmentation = TRUE;
frag_cur_pos += remaining_len;
}
save_state:
pid_analysis->fragmentation = fragmentation;
pid_analysis->frag_cur_pos = frag_cur_pos;
pid_analysis->frag_tot_len = frag_tot_len;
pid_analysis->frag_id = frag_id;
}
static guint32
calc_skips(gint32 curr, gint32 prev)
{
int res;
prev += 1;
res = curr - prev;
if (res < 0)
res += 16;
return res;
}
static guint32
detect_cc_drops(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint32 pid, gint32 cc_curr, mp2t_analysis_data_t *mp2t_data)
{
gint32 cc_prev = -1;
pid_analysis_data_t *pid_data = NULL;
ts_analysis_data_t *ts_data = NULL;
frame_analysis_data_t *frame_analysis_data_p = NULL;
proto_item *flags_item;
gboolean detected_drop = FALSE;
guint32 skips = 0;
if (!pinfo->fd->flags.visited) {
pid_data = get_pid_analysis(mp2t_data, pid);
cc_prev = pid_data->cc_prev;
pid_data->cc_prev = cc_curr;
if (pid == 0x1fff)
return 0;
if (cc_prev == cc_curr)
return 0;
if (cc_prev == -1)
return 0;
if (cc_curr != ((cc_prev+1) & MP2T_CC_MASK)) {
detected_drop = TRUE;
skips = calc_skips(cc_curr, cc_prev);
mp2t_data->total_skips += skips;
mp2t_data->total_discontinuity++;
}
}
if (detected_drop && !pinfo->fd->flags.visited) {
frame_analysis_data_p = get_frame_analysis_data(mp2t_data, pinfo);
if (!frame_analysis_data_p)
frame_analysis_data_p = init_frame_analysis_data(mp2t_data, pinfo);
ts_data = wmem_new0(wmem_file_scope(), struct ts_analysis_data);
ts_data->cc_prev = cc_prev;
ts_data->pid = pid;
ts_data->skips = skips;
wmem_tree_insert32(frame_analysis_data_p->ts_table, KEY(pid, cc_curr),
(void *)ts_data);
}
if (pinfo->fd->flags.visited) {
frame_analysis_data_p = get_frame_analysis_data(mp2t_data, pinfo);
if (!frame_analysis_data_p)
return 0;
else {
ts_data = (struct ts_analysis_data *)wmem_tree_lookup32(frame_analysis_data_p->ts_table,
KEY(pid, cc_curr));
if (ts_data) {
if (ts_data->skips > 0) {
detected_drop = TRUE;
cc_prev = ts_data->cc_prev;
skips = ts_data->skips;
}
}
}
}
if (detected_drop) {
expert_add_info_format(pinfo, tree, &ei_mp2t_cc_drop,
"Detected %d missing TS frames before this (last_cc:%d total skips:%d discontinuity:%d)",
skips, cc_prev,
mp2t_data->total_skips,
mp2t_data->total_discontinuity
);
flags_item = proto_tree_add_uint(tree, hf_mp2t_analysis_skips,
tvb, 0, 0, skips);
PROTO_ITEM_SET_GENERATED(flags_item);
flags_item = proto_tree_add_uint(tree, hf_mp2t_analysis_drops,
tvb, 0, 0, 1);
PROTO_ITEM_SET_GENERATED(flags_item);
}
return skips;
}
static gint
dissect_mp2t_adaptation_field(tvbuff_t *tvb, gint offset, proto_tree *tree)
{
gint af_start_offset;
proto_item *hi;
proto_tree *mp2t_af_tree;
guint8 af_length;
guint8 af_flags;
gint stuffing_len;
af_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_mp2t_af_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (af_length == 0)
return offset;
af_start_offset = offset;
hi = proto_tree_add_item( tree, hf_mp2t_af, tvb, offset, af_length, ENC_NA);
mp2t_af_tree = proto_item_add_subtree( hi, ett_mp2t_af );
af_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_di, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_rai, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_espi, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_pcr_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_opcr_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_sp_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_tpd_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_afe_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (af_flags & MP2T_AF_PCR_MASK) {
guint64 pcr_base;
guint16 pcr_ext;
pcr_base = tvb_get_ntoh48(tvb, offset) >> (48-33);
pcr_ext = (guint16)(tvb_get_ntoh48(tvb, offset) & 0x1FF);
proto_tree_add_uint64(mp2t_af_tree, hf_mp2t_af_pcr, tvb, offset, 6,
pcr_base*300 + pcr_ext);
offset += 6;
}
if (af_flags & MP2T_AF_OPCR_MASK) {
guint64 opcr_base;
guint16 opcr_ext;
opcr_base = tvb_get_ntoh48(tvb, offset) >> (48-33);
opcr_ext = (guint16)(tvb_get_ntoh48(tvb, offset) & 0x1FF);
proto_tree_add_uint64(mp2t_af_tree, hf_mp2t_af_opcr, tvb, offset, 6,
opcr_base*300 + opcr_ext);
offset += 6;
}
if (af_flags & MP2T_AF_SP_MASK) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_sc, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (af_flags & MP2T_AF_TPD_MASK) {
guint8 tpd_len;
tpd_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_tpd_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_tpd, tvb, offset, tpd_len, ENC_NA);
offset += tpd_len;
}
if (af_flags & MP2T_AF_AFE_MASK) {
guint8 e_len;
guint8 e_flags;
gint e_start_offset = offset;
gint reserved_len = 0;
e_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
e_flags = tvb_get_guint8(tvb, offset);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_ltw_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_pr_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_ss_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (e_flags & MP2T_AF_E_LTW_FLAG_MASK) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_ltwv_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_ltwo, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (e_flags & MP2T_AF_E_PR_FLAG_MASK) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_pr_reserved, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_pr, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
}
if (e_flags & MP2T_AF_E_SS_FLAG_MASK) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_st, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_dnau_32_30, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_m_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_dnau_29_15, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_m_2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_dnau_14_0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_m_3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
reserved_len = (e_len + 1) - (offset - e_start_offset);
if (reserved_len > 0) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_e_reserved_bytes, tvb, offset, reserved_len, ENC_NA);
offset += reserved_len;
}
}
stuffing_len = af_length - (offset - af_start_offset);
if (stuffing_len > 0) {
proto_tree_add_item( mp2t_af_tree, hf_mp2t_af_stuffing_bytes, tvb, offset, stuffing_len, ENC_NA);
offset += stuffing_len;
}
return offset;
}
static void
dissect_tsp(tvbuff_t *tvb, volatile gint offset, packet_info *pinfo,
proto_tree *tree, conversation_t *conv)
{
guint32 header;
guint afc;
gint start_offset = offset;
volatile gint payload_len;
mp2t_analysis_data_t *mp2t_data;
pid_analysis_data_t *pid_analysis;
guint32 skips;
guint32 pid;
guint32 cc;
guint32 pusi_flag;
guint32 tsc;
proto_item *ti;
proto_item *hi;
proto_item *item = NULL;
proto_tree *mp2t_tree;
proto_tree *mp2t_header_tree;
proto_tree *mp2t_analysis_tree;
proto_item *afci;
ti = proto_tree_add_item( tree, proto_mp2t, tvb, offset, MP2T_PACKET_SIZE, ENC_NA );
mp2t_tree = proto_item_add_subtree( ti, ett_mp2t );
header = tvb_get_ntohl(tvb, offset);
pid = (header & MP2T_PID_MASK) >> MP2T_PID_SHIFT;
cc = (header & MP2T_CC_MASK) >> MP2T_CC_SHIFT;
tsc = (header & MP2T_TSC_MASK);
pusi_flag = (header & 0x00400000);
proto_item_append_text(ti, " PID=0x%x CC=%d", pid, cc);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPEG TS");
hi = proto_tree_add_item( mp2t_tree, hf_mp2t_header, tvb, offset, 4, ENC_BIG_ENDIAN);
mp2t_header_tree = proto_item_add_subtree( hi, ett_mp2t_header );
proto_tree_add_item( mp2t_header_tree, hf_mp2t_sync_byte, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_tei, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_pusi, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_tp, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_tsc, tvb, offset, 4, ENC_BIG_ENDIAN);
afci = proto_tree_add_item( mp2t_header_tree, hf_mp2t_afc, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item( mp2t_header_tree, hf_mp2t_cc, tvb, offset, 4, ENC_BIG_ENDIAN);
afc = (header & MP2T_AFC_MASK) >> MP2T_AFC_SHIFT;
mp2t_data = get_mp2t_conversation_data(conv);
pid_analysis = get_pid_analysis(mp2t_data, pid);
if (pid_analysis->pload_type == pid_pload_unknown) {
if (pid == MP2T_PID_NULL) {
pid_analysis->pload_type = pid_pload_null;
} else if (pid == MP2T_PID_DOCSIS) {
pid_analysis->pload_type = pid_pload_docsis;
}
}
if (pid_analysis->pload_type == pid_pload_docsis && (afc != 1)) {
proto_item_append_text(afci, " (Invalid for DOCSIS packets, should be 1)");
}
if (pid_analysis->pload_type == pid_pload_null) {
col_set_str(pinfo->cinfo, COL_INFO, "NULL packet");
proto_item_append_text(afci, " (Should be 0 for NULL packets)");
return;
}
offset += 4;
mp2t_analysis_tree = proto_tree_add_subtree_format(mp2t_tree, tvb, offset, 0, ett_mp2t_analysis, &item, "MPEG2 PCR Analysis");
PROTO_ITEM_SET_GENERATED(item);
skips = detect_cc_drops(tvb, mp2t_analysis_tree, pinfo, pid, cc, mp2t_data);
if (skips > 0)
proto_item_append_text(ti, " skips=%d", skips);
if (afc == 2 || afc == 3)
offset = dissect_mp2t_adaptation_field(tvb, offset, mp2t_tree);
if ((offset - start_offset) < MP2T_PACKET_SIZE)
payload_len = MP2T_PACKET_SIZE - (offset - start_offset);
else
payload_len = 0;
if (!payload_len)
return;
if (afc == 2) {
col_set_str(pinfo->cinfo, COL_INFO, "Adaptation field only");
proto_tree_add_item( mp2t_tree, hf_mp2t_stuff_bytes, tvb, offset, payload_len, ENC_NA);
offset += payload_len;
}
if (!tsc) {
mp2t_process_fragmented_payload(tvb, offset, payload_len, pinfo, tree, mp2t_tree, pusi_flag, pid_analysis);
} else {
col_set_str(pinfo->cinfo, COL_INFO, "Scrambled TS payload");
}
}
static void
dissect_mp2t( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
guint offset = 0;
conversation_t *conv;
conv = find_or_create_conversation(pinfo);
for (; tvb_reported_length_remaining(tvb, offset) >= MP2T_PACKET_SIZE; offset += MP2T_PACKET_SIZE) {
dissect_tsp(tvb, offset, pinfo, tree, conv);
}
}
static gboolean
heur_dissect_mp2t( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ )
{
gint length;
guint offset = 0;
length = tvb_reported_length_remaining(tvb, offset);
if (length == 0) {
return FALSE;
}
if ((length % MP2T_PACKET_SIZE) != 0) {
return FALSE;
} else {
while (tvb_offset_exists(tvb, offset)) {
if (tvb_get_guint8(tvb, offset) != MP2T_SYNC_BYTE) {
return FALSE;
}
offset += MP2T_PACKET_SIZE;
}
}
dissect_mp2t(tvb, pinfo, tree);
return TRUE;
}
static void
mp2t_init(void) {
reassembly_table_init(&mp2t_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_mp2t(void)
{
static hf_register_info hf[] = {
{ &hf_mp2t_header, {
"Header", "mp2t.header",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_sync_byte, {
"Sync Byte", "mp2t.sync_byte",
FT_UINT32, BASE_HEX, VALS(mp2t_sync_byte_vals), MP2T_SYNC_BYTE_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_tei, {
"Transport Error Indicator", "mp2t.tei",
FT_UINT32, BASE_DEC, NULL, MP2T_TEI_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_pusi, {
"Payload Unit Start Indicator", "mp2t.pusi",
FT_UINT32, BASE_DEC, NULL, MP2T_PUSI_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_tp, {
"Transport Priority", "mp2t.tp",
FT_UINT32, BASE_DEC, NULL, MP2T_TP_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_pid, {
"PID", "mp2t.pid",
FT_UINT32, BASE_HEX, VALS(mp2t_pid_vals), MP2T_PID_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_tsc, {
"Transport Scrambling Control", "mp2t.tsc",
FT_UINT32, BASE_HEX, VALS(mp2t_tsc_vals), MP2T_TSC_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_afc, {
"Adaptation Field Control", "mp2t.afc",
FT_UINT32, BASE_HEX, VALS(mp2t_afc_vals) , MP2T_AFC_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_cc, {
"Continuity Counter", "mp2t.cc",
FT_UINT32, BASE_DEC, NULL, MP2T_CC_MASK, NULL, HFILL
} } ,
#if 0
{ &hf_mp2t_analysis_flags, {
"MPEG2-TS Analysis Flags", "mp2t.analysis.flags",
FT_NONE, BASE_NONE, NULL, 0x0,
"This frame has some of the MPEG2 analysis flags set", HFILL
} } ,
#endif
{ &hf_mp2t_analysis_skips, {
"TS Continuity Counter Skips", "mp2t.analysis.skips",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Missing TS frames according to CC counter values", HFILL
} } ,
{ &hf_mp2t_analysis_drops, {
"Some frames dropped", "mp2t.analysis.drops",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Discontinuity: A number of TS frames were dropped", HFILL
} } ,
{ &hf_mp2t_af, {
"Adaptation Field", "mp2t.af",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_length, {
"Adaptation Field Length", "mp2t.af.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
} } ,
{ &hf_mp2t_af_di, {
"Discontinuity Indicator", "mp2t.af.di",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_DI_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_rai, {
"Random Access Indicator", "mp2t.af.rai",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_RAI_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_espi, {
"Elementary Stream Priority Indicator", "mp2t.af.espi",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_ESPI_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_pcr_flag, {
"PCR Flag", "mp2t.af.pcr_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_PCR_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_opcr_flag, {
"OPCR Flag", "mp2t.af.opcr_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_OPCR_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_sp_flag, {
"Splicing Point Flag", "mp2t.af.sp_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_SP_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_tpd_flag, {
"Transport Private Data Flag", "mp2t.af.tpd_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_TPD_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_afe_flag, {
"Adaptation Field Extension Flag", "mp2t.af.afe_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_AFE_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_pcr, {
"Program Clock Reference", "mp2t.af.pcr",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_opcr, {
"Original Program Clock Reference", "mp2t.af.opcr",
FT_UINT64, BASE_HEX, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_sc, {
"Splice Countdown", "mp2t.af.sc",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_tpd_length, {
"Transport Private Data Length", "mp2t.af.tpd_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_tpd, {
"Transport Private Data", "mp2t.af.tpd",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_length, {
"Adaptation Field Extension Length", "mp2t.af.e_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_ltw_flag, {
"LTW Flag", "mp2t.af.e.ltw_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_E_LTW_FLAG_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_pr_flag, {
"Piecewise Rate Flag", "mp2t.af.e.pr_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_E_PR_FLAG_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_ss_flag, {
"Seamless Splice Flag", "mp2t.af.e.ss_flag",
FT_UINT8, BASE_DEC, NULL, MP2T_AF_E_SS_FLAG_MASK, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_reserved, {
"Reserved", "mp2t.af.e.reserved",
FT_UINT8, BASE_DEC, NULL, 0x1F, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_reserved_bytes, {
"Reserved", "mp2t.af.e.reserved_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
} } ,
{ &hf_mp2t_af_stuffing_bytes, {
"Stuffing", "mp2t.af.stuffing_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_ltwv_flag, {
"LTW Valid Flag", "mp2t.af.e.ltwv_flag",
FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_ltwo, {
"LTW Offset", "mp2t.af.e.ltwo",
FT_UINT16, BASE_DEC, NULL, 0x7FFF, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_pr_reserved, {
"Reserved", "mp2t.af.e.pr_reserved",
FT_UINT24, BASE_DEC, NULL, 0xC00000, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_pr, {
"Piecewise Rate", "mp2t.af.e.pr",
FT_UINT24, BASE_DEC, NULL, 0x3FFFFF, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_st, {
"Splice Type", "mp2t.af.e.st",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_dnau_32_30, {
"DTS Next AU[32...30]", "mp2t.af.e.dnau_32_30",
FT_UINT8, BASE_DEC, NULL, 0x0E, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_m_1, {
"Marker Bit", "mp2t.af.e.m_1",
FT_UINT8, BASE_DEC, NULL, 0x01, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_dnau_29_15, {
"DTS Next AU[29...15]", "mp2t.af.e.dnau_29_15",
FT_UINT16, BASE_DEC, NULL, 0xFFFE, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_m_2, {
"Marker Bit", "mp2t.af.e.m_2",
FT_UINT16, BASE_DEC, NULL, 0x0001, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_dnau_14_0, {
"DTS Next AU[14...0]", "mp2t.af.e.dnau_14_0",
FT_UINT16, BASE_DEC, NULL, 0xFFFE, NULL, HFILL
} } ,
{ &hf_mp2t_af_e_m_3, {
"Marker Bit", "mp2t.af.e.m_3",
FT_UINT16, BASE_DEC, NULL, 0x0001, NULL, HFILL
} } ,
#if 0
{ &hf_mp2t_payload, {
"Payload", "mp2t.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
} } ,
#endif
{ &hf_mp2t_stuff_bytes, {
"Stuffing", "mp2t.stuff_bytes",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL
} },
{ &hf_mp2t_pointer, {
"Pointer", "mp2t.pointer",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL
} },
{ &hf_msg_fragments, {
"Message fragments", "mp2t.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment, {
"Message fragment", "mp2t.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_overlap, {
"Message fragment overlap", "mp2t.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_overlap_conflicts, {
"Message fragment overlapping with conflicting data",
"mp2t.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_multiple_tails, {
"Message has multiple tail fragments",
"mp2t.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_too_long_fragment, {
"Message fragment too long", "mp2t.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_error, {
"Message defragmentation error", "mp2t.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_fragment_count, {
"Message fragment count", "mp2t.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_reassembled_in, {
"Reassembled in", "mp2t.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_reassembled_length, {
"Reassembled MP2T length", "mp2t.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00, NULL, HFILL
} },
{ &hf_msg_ts_packet_reassembled, {
"MPEG TS Packet (reassembled)", "mp2t.ts_packet_reassembled",
FT_NONE, BASE_NONE, NULL, 0x00, NULL, HFILL
} },
};
static gint *ett[] =
{
&ett_mp2t,
&ett_mp2t_header,
&ett_mp2t_af,
&ett_mp2t_analysis,
&ett_stuff,
&ett_msg_fragment,
&ett_msg_fragments
};
static ei_register_info ei[] = {
{ &ei_mp2t_pointer, { "mp2t.pointer", PI_MALFORMED, PI_ERROR, "Pointer value is too large", EXPFILL }},
{ &ei_mp2t_cc_drop, { "mp2t.cc.drop", PI_MALFORMED, PI_ERROR, "Detected missing TS frames", EXPFILL }},
};
expert_module_t* expert_mp2t;
proto_mp2t = proto_register_protocol("ISO/IEC 13818-1", "MP2T", "mp2t");
mp2t_handle = register_dissector("mp2t", dissect_mp2t, proto_mp2t);
proto_register_field_array(proto_mp2t, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mp2t = expert_register_protocol(proto_mp2t);
expert_register_field_array(expert_mp2t, ei, array_length(ei));
register_heur_dissector_list("mp2t.pid", &heur_subdissector_list);
register_init_routine(mp2t_init);
}
void
proto_reg_handoff_mp2t(void)
{
heur_dissector_add("udp", heur_dissect_mp2t, proto_mp2t);
dissector_add_uint("rtp.pt", PT_MP2T, mp2t_handle);
dissector_add_for_decode_as("udp.port", mp2t_handle);
heur_dissector_add("usb.bulk", heur_dissect_mp2t, proto_mp2t);
dissector_add_uint("wtap_encap", WTAP_ENCAP_MPEG_2_TS, mp2t_handle);
docsis_handle = find_dissector("docsis");
mpeg_pes_handle = find_dissector("mpeg-pes");
mpeg_sect_handle = find_dissector("mpeg_sect");
data_handle = find_dissector("data");
}
