void add_detected_tcp_svc(guint16 port)
{
wmem_map_insert(detected_tcp_svc, GUINT_TO_POINTER(port), GUINT_TO_POINTER(port));
}
static void init_dcerpc_data(void)
{
wmem_map_insert(dcerpc_req_pkt_type, GUINT_TO_POINTER(0), GUINT_TO_POINTER(0));
wmem_map_insert(dcerpc_req_pkt_type, GUINT_TO_POINTER(11), GUINT_TO_POINTER(11));
wmem_map_insert(dcerpc_req_pkt_type, GUINT_TO_POINTER(14), GUINT_TO_POINTER(14));
wmem_map_insert(dcerpc_context_zero, GUINT_TO_POINTER(11), GUINT_TO_POINTER(11));
wmem_map_insert(dcerpc_context_zero, GUINT_TO_POINTER(12), GUINT_TO_POINTER(12));
wmem_map_insert(dcerpc_context_zero, GUINT_TO_POINTER(14), GUINT_TO_POINTER(14));
wmem_map_insert(dcerpc_context_zero, GUINT_TO_POINTER(15), GUINT_TO_POINTER(15));
}
static void null_output_rrpd_entries(RRPD *in_rrpd)
{
wmem_map_remove(output_rrpd, GUINT_TO_POINTER(in_rrpd->req_first_frame));
wmem_map_remove(output_rrpd, GUINT_TO_POINTER(in_rrpd->req_last_frame));
wmem_map_remove(output_rrpd, GUINT_TO_POINTER(in_rrpd->rsp_first_frame));
wmem_map_remove(output_rrpd, GUINT_TO_POINTER(in_rrpd->rsp_last_frame));
}
static void update_output_rrpd(RRPD *in_rrpd)
{
if (preferences.rte_on_first_req)
wmem_map_insert(output_rrpd, GUINT_TO_POINTER(in_rrpd->req_first_frame), in_rrpd);
if (preferences.rte_on_last_req)
wmem_map_insert(output_rrpd, GUINT_TO_POINTER(in_rrpd->req_last_frame), in_rrpd);
if (preferences.rte_on_first_rsp)
wmem_map_insert(output_rrpd, GUINT_TO_POINTER(in_rrpd->rsp_first_frame), in_rrpd);
if (preferences.rte_on_last_rsp)
wmem_map_insert(output_rrpd, GUINT_TO_POINTER(in_rrpd->rsp_last_frame), in_rrpd);
}
static RRPD* append_to_rrpd_list(RRPD *in_rrpd)
{
RRPD *next_rrpd = (RRPD*)wmem_memdup(wmem_file_scope(), in_rrpd, sizeof(RRPD));
if (preferences.reassembly)
{
if (next_rrpd->msg_id)
next_rrpd->state = RRPD_STATE_3;
else
next_rrpd->state = RRPD_STATE_1;
}
else
{
if (next_rrpd->msg_id)
next_rrpd->state = RRPD_STATE_4;
else
next_rrpd->state = RRPD_STATE_2;
}
update_output_rrpd(next_rrpd);
wmem_list_append(rrpd_list, next_rrpd);
return next_rrpd;
}
static RRPD *find_latest_rrpd(RRPD *in_rrpd, int state)
{
RRPD *rrpd_index = NULL, *rrpd;
wmem_list_frame_t* i;
for (i = wmem_list_tail(rrpd_list); i != NULL; i = wmem_list_frame_prev(i))
{
rrpd = (RRPD*)wmem_list_frame_data(i);
if (rrpd->ip_proto == in_rrpd->ip_proto && rrpd->stream_no == in_rrpd->stream_no)
{
if (in_rrpd->decode_based)
{
if (state == RRPD_STATE_1)
{
if (rrpd->session_id == 0 && rrpd->msg_id == 0 && rrpd->suffix == 1)
{
rrpd_index = rrpd;
break;
}
}
if (rrpd->session_id == in_rrpd->session_id && rrpd->msg_id == in_rrpd->msg_id && rrpd->suffix == in_rrpd->suffix)
{
if (state == RRPD_STATE_DONT_CARE || rrpd->state == state)
{
rrpd_index = rrpd;
break;
}
}
}
else
{
if (state == RRPD_STATE_DONT_CARE || rrpd->state == state)
{
rrpd_index = rrpd;
break;
}
}
}
}
return rrpd_index;
}
static void update_rrpd_list_entry(RRPD *match, RRPD *in_rrpd)
{
null_output_rrpd_entries(match);
switch (match->state)
{
case RRPD_STATE_1:
if (in_rrpd->c2s)
{
match->req_last_frame = in_rrpd->req_last_frame;
match->req_last_rtime = in_rrpd->req_last_rtime;
if (in_rrpd->msg_id)
{
match->session_id = in_rrpd->session_id;
match->msg_id = in_rrpd->msg_id;
match->suffix = in_rrpd->suffix;
match->state = RRPD_STATE_3;
}
}
else
{
match->rsp_first_frame = in_rrpd->rsp_first_frame;
match->rsp_first_rtime = in_rrpd->rsp_first_rtime;
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_7;
else
match->state = RRPD_STATE_5;
}
break;
case RRPD_STATE_2:
if (in_rrpd->c2s)
{
match->req_last_frame = in_rrpd->req_last_frame;
match->req_last_rtime = in_rrpd->req_last_rtime;
if (in_rrpd->msg_id)
{
match->session_id = in_rrpd->session_id;
match->msg_id = in_rrpd->msg_id;
match->suffix = in_rrpd->suffix;
match->state = RRPD_STATE_4;
}
}
else
{
match->rsp_first_frame = in_rrpd->rsp_first_frame;
match->rsp_first_rtime = in_rrpd->rsp_first_rtime;
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_8;
else
match->state = RRPD_STATE_6;
}
break;
case RRPD_STATE_3:
if (in_rrpd->c2s)
{
match->req_last_frame = in_rrpd->req_last_frame;
match->req_last_rtime = in_rrpd->req_last_rtime;
if (in_rrpd->msg_id)
{
match->session_id = in_rrpd->session_id;
match->msg_id = in_rrpd->msg_id;
match->suffix = in_rrpd->suffix;
match->state = RRPD_STATE_3;
}
}
else
{
match->rsp_first_frame = in_rrpd->rsp_first_frame;
match->rsp_first_rtime = in_rrpd->rsp_first_rtime;
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_7;
else
match->state = RRPD_STATE_5;
}
break;
case RRPD_STATE_4:
if (in_rrpd->c2s)
{
match->req_last_frame = in_rrpd->req_last_frame;
match->req_last_rtime = in_rrpd->req_last_rtime;
if (in_rrpd->msg_id)
{
match->session_id = in_rrpd->session_id;
match->msg_id = in_rrpd->msg_id;
match->suffix = in_rrpd->suffix;
match->state = RRPD_STATE_4;
}
}
else
{
match->rsp_first_frame = in_rrpd->rsp_first_frame;
match->rsp_first_rtime = in_rrpd->rsp_first_rtime;
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_8;
else
match->state = RRPD_STATE_6;
}
break;
case RRPD_STATE_5:
if (in_rrpd->c2s)
{
;
}
else
{
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_7;
else
match->state = RRPD_STATE_5;
}
break;
case RRPD_STATE_6:
if (in_rrpd->c2s)
{
;
}
else
{
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
if (in_rrpd->msg_id)
match->state = RRPD_STATE_8;
else
match->state = RRPD_STATE_6;
}
break;
case RRPD_STATE_7:
if (in_rrpd->c2s)
{
;
}
else
{
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
}
break;
case RRPD_STATE_8:
if (in_rrpd->c2s)
{
;
}
else
{
match->rsp_last_frame = in_rrpd->rsp_last_frame;
match->rsp_last_rtime = in_rrpd->rsp_last_rtime;
}
break;
}
update_output_rrpd(match);
}
static void update_rrpd_list_entry_req(RRPD *in_rrpd)
{
RRPD *match;
if (in_rrpd->decode_based)
{
while (TRUE)
{
match = find_latest_rrpd(in_rrpd, RRPD_STATE_1);
if (match != NULL)
{
update_rrpd_list_entry(match, in_rrpd);
break;
}
match = find_latest_rrpd(in_rrpd, RRPD_STATE_4);
if (match != NULL)
{
update_rrpd_list_entry(match, in_rrpd);
break;
}
append_to_rrpd_list(in_rrpd);
break;
}
}
else
{
match = find_latest_rrpd(in_rrpd, RRPD_STATE_DONT_CARE);
if (match != NULL)
{
if (match->state > RRPD_STATE_4 && in_rrpd->c2s)
{
append_to_rrpd_list(in_rrpd);
}
else
update_rrpd_list_entry(match, in_rrpd);
}
else
{
append_to_rrpd_list(in_rrpd);
}
}
}
static RRPD* insert_into_temp_rsp_rrpd_list(RRPD *in_rrpd)
{
RRPD *rrpd = (RRPD*)wmem_memdup(wmem_file_scope(), in_rrpd, sizeof(RRPD));
wmem_list_append(temp_rsp_rrpd_list, rrpd);
return rrpd;
}
static RRPD* find_temp_rsp_rrpd(RRPD *in_rrpd)
{
wmem_list_frame_t *i;
RRPD* rrpd;
for (i = wmem_list_head(temp_rsp_rrpd_list); i; i = wmem_list_frame_next(i))
{
rrpd = (RRPD*)wmem_list_frame_data(i);
if (rrpd->ip_proto == in_rrpd->ip_proto && rrpd->stream_no == in_rrpd->stream_no)
return rrpd;
}
return NULL;
}
static void update_temp_rsp_rrpd(RRPD *temp_list, RRPD *in_rrpd)
{
temp_list->rsp_last_frame = in_rrpd->rsp_last_frame;
temp_list->rsp_last_rtime = in_rrpd->rsp_last_rtime;
}
static void migrate_temp_rsp_rrpd(RRPD *main_list, RRPD *temp_list)
{
update_rrpd_list_entry(main_list, temp_list);
wmem_list_remove(temp_rsp_rrpd_list, temp_list);
if (preferences.reassembly)
main_list->state = RRPD_STATE_7;
else
main_list->state = RRPD_STATE_8;
}
static void update_rrpd_list_entry_rsp(RRPD *in_rrpd)
{
RRPD *match, *temp_list;
if (in_rrpd->decode_based)
{
if (preferences.reassembly)
{
if (in_rrpd->msg_id)
{
temp_list = find_temp_rsp_rrpd(in_rrpd);
if (temp_list != NULL)
{
update_temp_rsp_rrpd(temp_list, in_rrpd);
match = find_latest_rrpd(in_rrpd, RRPD_STATE_3);
if (match != NULL)
migrate_temp_rsp_rrpd(match, temp_list);
}
else
{
match = find_latest_rrpd(in_rrpd, RRPD_STATE_3);
if (match != NULL)
update_rrpd_list_entry(match, in_rrpd);
}
}
else
{
temp_list = find_temp_rsp_rrpd(in_rrpd);
if (temp_list != NULL)
update_temp_rsp_rrpd(temp_list, in_rrpd);
else
insert_into_temp_rsp_rrpd_list(in_rrpd);
}
}
else
{
match = find_latest_rrpd(in_rrpd, RRPD_STATE_8);
if (match != NULL)
update_rrpd_list_entry(match, in_rrpd);
}
}
else
{
match = find_latest_rrpd(in_rrpd, RRPD_STATE_DONT_CARE);
if (match != NULL)
update_rrpd_list_entry(match, in_rrpd);
}
return;
}
static void update_rrpd_rte_data(RRPD *in_rrpd)
{
if (in_rrpd->c2s)
update_rrpd_list_entry_req(in_rrpd);
else
update_rrpd_list_entry_rsp(in_rrpd);
}
gboolean is_dcerpc_context_zero(guint32 pkt_type)
{
return (wmem_map_lookup(dcerpc_context_zero, GUINT_TO_POINTER(pkt_type)) != NULL);
}
gboolean is_dcerpc_req_pkt_type(guint32 pkt_type)
{
return (wmem_map_lookup(dcerpc_req_pkt_type, GUINT_TO_POINTER(pkt_type)) != NULL);
}
static void init_globals(void)
{
if (!proto_is_protocol_enabled(find_protocol_by_id(proto_transum)))
return;
detected_tcp_svc = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
rrpd_list = wmem_list_new(wmem_file_scope());
temp_rsp_rrpd_list = wmem_list_new(wmem_file_scope());
wanted_fields = g_array_new(FALSE, FALSE, (guint)sizeof(int));
for (int i = 0; i < HF_INTEREST_END_OF_LIST; i++)
{
g_array_append_val(wanted_fields, hf_of_interest[i].hf);
}
set_postdissector_wanted_hfids(transum_handle, wanted_fields);
preferences.tcp_svc_ports = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
preferences.udp_svc_ports = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
for (guint i = 0; i < tcp_svc_port_range_values->nranges; i++)
{
for (guint32 j = tcp_svc_port_range_values->ranges[i].low; j <= tcp_svc_port_range_values->ranges[i].high; j++)
{
wmem_map_insert(preferences.tcp_svc_ports, GUINT_TO_POINTER(j), GUINT_TO_POINTER(RTE_CALC_GTCP));
}
}
for (guint i = 0; i < udp_svc_port_range_values->nranges; i++)
{
for (guint32 j = udp_svc_port_range_values->ranges[i].low; j <= udp_svc_port_range_values->ranges[i].high; j++)
{
wmem_map_insert(preferences.udp_svc_ports, GUINT_TO_POINTER(j), GUINT_TO_POINTER(RTE_CALC_GUDP));
}
}
dcerpc_context_zero = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
dcerpc_req_pkt_type = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
init_dcerpc_data();
wmem_map_insert(preferences.tcp_svc_ports, GUINT_TO_POINTER(445), GUINT_TO_POINTER(RTE_CALC_SMB2));
wmem_map_insert(preferences.udp_svc_ports, GUINT_TO_POINTER(53), GUINT_TO_POINTER(RTE_CALC_DNS));
output_rrpd = wmem_map_new(wmem_file_scope(), g_direct_hash, g_direct_equal);
}
static void write_rte(RRPD *in_rrpd, tvbuff_t *tvb, proto_tree *tree, char *summary)
{
nstime_t rte_art;
nstime_t rte_st;
nstime_t rte_reqspread;
nstime_t rte_rspspread;
proto_tree *rte_tree;
proto_item *pi;
wmem_strbuf_t *temp_string = wmem_strbuf_new(wmem_packet_scope(), "");
if (in_rrpd->req_first_frame)
{
pi = proto_tree_add_item(tree, proto_transum, tvb, 0, -1, ENC_NA);
rte_tree = proto_item_add_subtree(pi, ett_transum);
nstime_delta(&rte_reqspread, &(in_rrpd->req_last_rtime), &(in_rrpd->req_first_rtime));
if (in_rrpd->rsp_first_frame)
{
nstime_delta(&rte_art, &(in_rrpd->rsp_last_rtime), &(in_rrpd->req_first_rtime));
nstime_delta(&rte_st, &(in_rrpd->rsp_first_rtime), &(in_rrpd->req_last_rtime));
nstime_delta(&rte_rspspread, &(in_rrpd->rsp_last_rtime), &(in_rrpd->rsp_first_rtime));
pi = proto_tree_add_string(rte_tree, hf_tsum_status, tvb, 0, 0, "OK");
}
else
{
pi = proto_tree_add_string(rte_tree, hf_tsum_status, tvb, 0, 0, "Response missing");
}
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_uint(rte_tree, hf_tsum_req_first_seg, tvb, 0, 0, in_rrpd->req_first_frame);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_uint(rte_tree, hf_tsum_req_last_seg, tvb, 0, 0, in_rrpd->req_last_frame);
PROTO_ITEM_SET_GENERATED(pi);
if (in_rrpd->rsp_first_frame)
{
pi = proto_tree_add_uint(rte_tree, hf_tsum_rsp_first_seg, tvb, 0, 0, in_rrpd->rsp_first_frame);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_uint(rte_tree, hf_tsum_rsp_last_seg, tvb, 0, 0, in_rrpd->rsp_last_frame);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_time(rte_tree, hf_tsum_apdu_rsp_time, tvb, 0, 0, &rte_art);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_time(rte_tree, hf_tsum_service_time, tvb, 0, 0, &rte_st);
PROTO_ITEM_SET_GENERATED(pi);
}
pi = proto_tree_add_time(rte_tree, hf_tsum_req_spread, tvb, 0, 0, &rte_reqspread);
PROTO_ITEM_SET_GENERATED(pi);
if (in_rrpd->rsp_first_frame)
{
pi = proto_tree_add_time(rte_tree, hf_tsum_rsp_spread, tvb, 0, 0, &rte_rspspread);
PROTO_ITEM_SET_GENERATED(pi);
}
if (in_rrpd->ip_proto == IP_PROTO_TCP)
wmem_strbuf_append_printf(temp_string, "tcp.stream==%d", in_rrpd->stream_no);
else if (in_rrpd->ip_proto == IP_PROTO_UDP)
wmem_strbuf_append_printf(temp_string, "udp.stream==%d", in_rrpd->stream_no);
if (in_rrpd->rsp_first_frame)
wmem_strbuf_append_printf(temp_string, " && frame.number>=%d && frame.number<=%d", in_rrpd->req_first_frame, in_rrpd->rsp_last_frame);
else
wmem_strbuf_append_printf(temp_string, " && frame.number>=%d && frame.number<=%d", in_rrpd->req_first_frame, in_rrpd->req_last_frame);
if (in_rrpd->calculation == RTE_CALC_GTCP)
wmem_strbuf_append_printf(temp_string, " && tcp.len>0");
pi = proto_tree_add_string(rte_tree, hf_tsum_clip_filter, tvb, 0, 0, wmem_strbuf_get_str(temp_string));
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_string(rte_tree, hf_tsum_calculation, tvb, 0, 0, val_to_str(in_rrpd->calculation, rrdp_calculation_vals, "Unknown calculation type: %d"));
PROTO_ITEM_SET_GENERATED(pi);
if (in_rrpd->rsp_first_frame)
{
if (preferences.summarisers_enabled)
{
if (summary)
{
pi = proto_tree_add_string(tree, hf_tsum_summary, tvb, 0, 0, summary);
PROTO_ITEM_SET_GENERATED(pi);
}
}
}
}
}
static void set_proto_values(packet_info *pinfo, proto_tree *tree, PKT_INFO* pkt_info, PKT_INFO* subpackets)
{
guint32 field_uint[MAX_RETURNED_ELEMENTS];
size_t field_value_count;
pkt_info->frame_number = pinfo->fd->num;
pkt_info->relative_time = pinfo->rel_ts;
int number_sub_pkts_of_interest = 0;
if (pinfo->ptype == PT_TCP)
pkt_info->rrpd.ip_proto = IP_PROTO_TCP;
else if (pinfo->ptype == PT_UDP)
pkt_info->rrpd.ip_proto = IP_PROTO_UDP;
if (pkt_info->rrpd.ip_proto == IP_PROTO_TCP)
{
number_sub_pkts_of_interest = decode_gtcp(pinfo, tree, pkt_info);
if (pkt_info->tcp_retran)
{
if (pkt_info->rrpd.c2s && preferences.capture_position == CAPTURE_SERVICE)
{
pkt_info->pkt_of_interest = FALSE;
return;
}
else if (!pkt_info->rrpd.c2s && preferences.capture_position == CAPTURE_CLIENT)
{
pkt_info->pkt_of_interest = FALSE;
return;
}
}
if (pkt_info->tcp_keep_alive)
{
pkt_info->pkt_of_interest = FALSE;
return;
}
if (pkt_info->len == 1)
{
if (preferences.orphan_ka_discard && pkt_info->tcp_flags_ack && pkt_info->rrpd.c2s)
{
pkt_info->pkt_of_interest = FALSE;
return;
}
}
if (pkt_info->tcp_flags_syn)
number_sub_pkts_of_interest = decode_syn(pinfo, tree, pkt_info);
if (pkt_info->len > 0)
{
if (pkt_info->dstport == 445 || pkt_info->srcport == 445)
number_sub_pkts_of_interest = decode_smb(pinfo, tree, pkt_info, subpackets);
else if (!extract_uint(tree, hf_of_interest[HF_INTEREST_DCERPC_VER].hf, field_uint, &field_value_count))
{
if (field_value_count)
number_sub_pkts_of_interest = decode_dcerpc(pinfo, tree, pkt_info);
}
}
}
else if (pkt_info->rrpd.ip_proto == IP_PROTO_UDP)
{
number_sub_pkts_of_interest = decode_gudp(pinfo, tree, pkt_info);
if (pkt_info->srcport == 53 || pkt_info->dstport == 53)
number_sub_pkts_of_interest = decode_dns(pinfo, tree, pkt_info);
}
for (int i = 0; (i < number_sub_pkts_of_interest) && (i < MAX_SUBPKTS_PER_PACKET); i++)
{
if (pkt_info->rrpd.c2s)
{
subpackets[i].rrpd.req_first_frame = pkt_info->frame_number;
subpackets[i].rrpd.req_first_rtime = pkt_info->relative_time;
subpackets[i].rrpd.req_last_frame = pkt_info->frame_number;
subpackets[i].rrpd.req_last_rtime = pkt_info->relative_time;
subpackets[i].frame_number = pkt_info->frame_number;
}
else
{
subpackets[i].rrpd.rsp_first_frame = pkt_info->frame_number;
subpackets[i].rrpd.rsp_first_rtime = pkt_info->relative_time;
subpackets[i].rrpd.rsp_last_frame = pkt_info->frame_number;
subpackets[i].rrpd.rsp_last_rtime = pkt_info->relative_time;
subpackets[i].frame_number = pkt_info->frame_number;
}
}
}
static int dissect_transum(tvbuff_t *buffer, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (PINFO_FD_VISITED(pinfo))
{
RRPD *rrpd = (RRPD*)wmem_map_lookup(output_rrpd, GUINT_TO_POINTER(pinfo->num));
if (rrpd)
{
if (tree)
{
write_rte(rrpd, buffer, tree, NULL);
}
}
}
else
{
PKT_INFO *sub_packet = wmem_alloc0_array(wmem_packet_scope(), PKT_INFO, MAX_SUBPKTS_PER_PACKET);
set_proto_values(pinfo, tree, &sub_packet[0], sub_packet);
if (sub_packet[0].pkt_of_interest)
{
for (int i = 0; i < MAX_SUBPKTS_PER_PACKET; i++)
{
if (!sub_packet[i].frame_number)
break;
update_rrpd_rte_data(&(sub_packet[i].rrpd));
}
}
}
return 0;
}
void
proto_register_transum(void)
{
module_t *transum_module;
static hf_register_info hf[] = {
{ &hf_tsum_status,
{ "RTE Status", "transum.status",
FT_STRING, BASE_NONE, NULL, 0x0,
"Indication of completeness of the RTE information", HFILL } },
#if 0
{ &hf_tsum_time_units,
{ "RTE Time Units", "transum.time_units",
FT_STRING, BASE_NONE, NULL, 0x0,
"Time units used (s, ms or us) for the RTE values", HFILL }
},
#endif
{ &hf_tsum_req_first_seg,
{ "Req First Seg", "transum.firstreq",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"First Segment of an APDU Request", HFILL }
},
{ &hf_tsum_req_last_seg,
{ "Req Last Seg", "transum.lastreq",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Last Segment of an APDU Request", HFILL }
},
{ &hf_tsum_rsp_first_seg,
{ "Rsp First Seg", "transum.firstrsp",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"First Segment of an APDU Response", HFILL }
},
{ &hf_tsum_rsp_last_seg,
{ "Rsp Last Seg", "transum.lastrsp",
FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Last Segment of an APDU Response", HFILL }
},
{ &hf_tsum_apdu_rsp_time,
{ "APDU Rsp Time", "transum.art",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"RTE APDU Response Time", HFILL }
},
{ &hf_tsum_service_time,
{ "Service Time", "transum.st",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"RTE Service Time", HFILL }
},
{ &hf_tsum_req_spread,
{ "Req Spread", "transum.reqspread",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"RTE Request Spread", HFILL }
},
{ &hf_tsum_rsp_spread,
{ "Rsp Spread", "transum.rspspread",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"RTE Response Spread", HFILL }
},
{ &hf_tsum_clip_filter,
{ "Trace clip filter", "transum.clip_filter",
FT_STRING, BASE_NONE, NULL, 0x0,
"Filter expression to select the APDU Reqest-Response pair", HFILL }
},
{ &hf_tsum_calculation,
{ "Calculation", "transum.calculation",
FT_STRING, BASE_NONE, NULL, 0x0,
"Basis of the RTE calculation", HFILL }
},
{ &hf_tsum_summary,
{ "Summary", "transum.summary",
FT_STRING, BASE_NONE, NULL, 0x0,
"Summarizer information", HFILL }
}
};
static gint *ett[] = {
&ett_transum,
&ett_transum_header,
&ett_transum_data
};
proto_transum = proto_register_protocol("TRANSUM RTE Data", "TRANSUM", "transum");
proto_disable_by_default(proto_transum);
preferences.capture_position = TRACE_CAP_CLIENT;
preferences.reassembly = TRUE;
range_convert_str(wmem_epan_scope(), &tcp_svc_port_range_values, "25, 80, 443, 1433", MAX_TCP_PORT);
range_convert_str(wmem_epan_scope(), &udp_svc_port_range_values, "137-139", MAX_UDP_PORT);
preferences.orphan_ka_discard = FALSE;
preferences.time_multiplier = RTE_TIME_SEC;
preferences.rte_on_first_req = FALSE;
preferences.rte_on_last_req = TRUE;
preferences.rte_on_first_rsp = FALSE;
preferences.rte_on_last_rsp = FALSE;
proto_register_field_array(proto_transum, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
transum_module = prefs_register_protocol(proto_transum, NULL);
prefs_register_obsolete_preference(transum_module, "tsumenabled");
prefs_register_enum_preference(transum_module,
"capture_position",
"Capture position",
"Position of the capture unit that produced this trace. This setting affects the way TRANSUM handles TCP Retransmissions. See the manual for details.",
&preferences.capture_position,
capture_position_vals,
FALSE);
prefs_register_bool_preference(transum_module,
"reassembly",
"Subdissector reassembly enabled",
"Set this to match to the TCP subdissector reassembly setting",
&preferences.reassembly);
prefs_register_range_preference(transum_module,
"tcp_port_ranges",
"Output RTE data for these TCP service ports",
"Add and remove ports numbers separated by commas\nRanges are supported e.g. 25,80,2000-3000,5432",
&tcp_svc_port_range_values,
65536);
prefs_register_range_preference(transum_module,
"udp_port_ranges",
"Output RTE data for these UDP service ports",
"Add and remove ports numbers separated by commas\nRanges are supported e.g. 123,137-139,520-521,2049",
&udp_svc_port_range_values,
65536);
prefs_register_bool_preference(transum_module,
"orphan_ka_discard",
"Discard orphaned TCP Keep-Alives",
"Set this to discard any packet in the direction client to service,\nwith a 1-byte payload of 0x00 and the ACK flag set",
&preferences.orphan_ka_discard);
prefs_register_bool_preference(transum_module,
"rte_on_first_req",
"Add RTE data to the first request segment",
"RTE data will be added to the first request packet",
&preferences.rte_on_first_req);
prefs_register_bool_preference(transum_module,
"rte_on_last_req",
"Add RTE data to the last request segment",
"RTE data will be added to the last request packet",
&preferences.rte_on_last_req);
prefs_register_bool_preference(transum_module,
"rte_on_first_rsp",
"Add RTE data to the first response segment",
"RTE data will be added to the first response packet",
&preferences.rte_on_first_rsp);
prefs_register_bool_preference(transum_module,
"rte_on_last_rsp",
"Add RTE data to the last response segment",
"RTE data will be added to the last response packet",
&preferences.rte_on_last_rsp);
transum_handle = register_dissector("transum", dissect_transum, proto_transum);
register_init_routine(init_globals);
register_postdissector(transum_handle);
}
void proto_reg_handoff_transum(void)
{
for (int i = 0; i < HF_INTEREST_END_OF_LIST; i++)
{
hf_of_interest[i].hf = proto_registrar_get_id_byname(hf_of_interest[i].proto_name);
}
}
