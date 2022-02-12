static void
udp_src_prompt(packet_info *pinfo, gchar *result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "source (%u%s)", pinfo->srcport, UTF8_RIGHTWARDS_ARROW);
}
static gpointer
udp_src_value(packet_info *pinfo)
{
return GUINT_TO_POINTER(pinfo->srcport);
}
static void
udp_dst_prompt(packet_info *pinfo, gchar *result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "destination (%s%u)", UTF8_RIGHTWARDS_ARROW, pinfo->destport);
}
static gpointer
udp_dst_value(packet_info *pinfo)
{
return GUINT_TO_POINTER(pinfo->destport);
}
static void
udp_both_prompt(packet_info *pinfo, gchar *result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Both (%u%s%u)", pinfo->srcport, UTF8_LEFT_RIGHT_ARROW, pinfo->destport);
}
static struct udp_analysis *
init_udp_conversation_data(void)
{
struct udp_analysis *udpd;
udpd = wmem_new0(wmem_file_scope(), struct udp_analysis);
udpd->stream = udp_stream_count++;
return udpd;
}
static struct udp_analysis *
get_udp_conversation_data(conversation_t *conv, packet_info *pinfo)
{
int direction;
struct udp_analysis *udpd=NULL;
if (conv == NULL)
conv = find_or_create_conversation(pinfo);
udpd=(struct udp_analysis *)conversation_get_proto_data(conv, hfi_udp->id);
if (!udpd) {
udpd = init_udp_conversation_data();
conversation_add_proto_data(conv, hfi_udp->id, udpd);
}
if (!udpd) {
return NULL;
}
direction=CMP_ADDRESS(&pinfo->src, &pinfo->dst);
if (direction == 0) {
direction= (pinfo->srcport > pinfo->destport) ? 1 : -1;
}
if (direction >= 0) {
udpd->fwd=&(udpd->flow1);
udpd->rev=&(udpd->flow2);
} else {
udpd->fwd=&(udpd->flow2);
udpd->rev=&(udpd->flow1);
}
return udpd;
}
void
add_udp_process_info(guint32 frame_num, address *local_addr, address *remote_addr, guint16 local_port, guint16 remote_port, guint32 uid, guint32 pid, gchar *username, gchar *command) {
conversation_t *conv;
struct udp_analysis *udpd;
udp_flow_t *flow = NULL;
if (!udp_process_info) {
return;
}
conv = find_conversation(frame_num, local_addr, remote_addr, PT_UDP, local_port, remote_port, 0);
if (!conv) {
return;
}
udpd = (struct udp_analysis *)conversation_get_proto_data(conv, hfi_udp->id);
if (!udpd) {
return;
}
if ((CMP_ADDRESS(local_addr, &conv->key_ptr->addr1) == 0) && (local_port == conv->key_ptr->port1)) {
flow = &udpd->flow1;
} else if ((CMP_ADDRESS(remote_addr, &conv->key_ptr->addr1) == 0) && (remote_port == conv->key_ptr->port1)) {
flow = &udpd->flow2;
}
if (!flow || flow->command) {
return;
}
flow->process_uid = uid;
flow->process_pid = pid;
flow->username = wmem_strdup(wmem_file_scope(), username);
flow->command = wmem_strdup(wmem_file_scope(), command);
}
guint32 get_udp_stream_count(void)
{
return udp_stream_count;
}
void
decode_udp_ports(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int uh_sport, int uh_dport, int uh_ulen)
{
tvbuff_t *next_tvb;
int low_port, high_port;
gint len, reported_len;
udp_p_info_t *udp_p_info = NULL;
guint8 curr_layer_num = pinfo->curr_layer_num;
heur_dtbl_entry_t *hdtbl_entry;
len = tvb_captured_length_remaining(tvb, offset);
reported_len = tvb_reported_length_remaining(tvb, offset);
if (uh_ulen != -1) {
if ((uh_ulen - offset) < reported_len)
reported_len = uh_ulen - offset;
if (len > reported_len)
len = reported_len;
}
next_tvb = tvb_new_subset(tvb, offset, len, reported_len);
if (have_tap_listener(udp_follow_tap))
tap_queue_packet(udp_follow_tap, pinfo, next_tvb);
if (pinfo->fd->flags.visited) {
udp_p_info = (udp_p_info_t*)p_get_proto_data(wmem_file_scope(), pinfo, hfi_udp->id, pinfo->curr_layer_num);
if (udp_p_info) {
call_heur_dissector_direct(udp_p_info->heur_dtbl_entry, next_tvb, pinfo, tree, NULL);
return;
}
}
if (try_conversation_dissector(&pinfo->dst, &pinfo->src, PT_UDP,
uh_dport, uh_sport, next_tvb, pinfo, tree, NULL)) {
return;
}
if (try_heuristic_first) {
if (dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
if (!udp_p_info) {
udp_p_info = wmem_new0(wmem_file_scope(), udp_p_info_t);
udp_p_info->heur_dtbl_entry = hdtbl_entry;
p_add_proto_data(wmem_file_scope(), pinfo, hfi_udp->id, curr_layer_num, udp_p_info);
}
return;
}
}
if (uh_sport > uh_dport) {
low_port = uh_dport;
high_port = uh_sport;
} else {
low_port = uh_sport;
high_port = uh_dport;
}
if ((low_port != 0) &&
dissector_try_uint(udp_dissector_table, low_port, next_tvb, pinfo, tree))
return;
if ((high_port != 0) &&
dissector_try_uint(udp_dissector_table, high_port, next_tvb, pinfo, tree))
return;
if (!try_heuristic_first) {
if (dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
if (!udp_p_info) {
udp_p_info = wmem_new0(wmem_file_scope(), udp_p_info_t);
udp_p_info->heur_dtbl_entry = hdtbl_entry;
p_add_proto_data(wmem_file_scope(), pinfo, hfi_udp->id, curr_layer_num, udp_p_info);
}
return;
}
}
call_dissector(data_handle,next_tvb, pinfo, tree);
}
static void
dissect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ip_proto)
{
proto_tree *udp_tree = NULL;
proto_item *ti, *hidden_item, *port_item;
guint len;
guint reported_len;
vec_t cksum_vec[4];
guint32 phdr[2];
guint16 computed_cksum;
guint16 expected_cksum;
int offset = 0;
e_udphdr *udph;
proto_tree *checksum_tree;
proto_item *item;
conversation_t *conv = NULL;
struct udp_analysis *udpd = NULL;
proto_tree *process_tree;
gchar *src_port_str, *dst_port_str;
udph=wmem_new(wmem_packet_scope(), e_udphdr);
SET_ADDRESS(&udph->ip_src, pinfo->src.type, pinfo->src.len, pinfo->src.data);
SET_ADDRESS(&udph->ip_dst, pinfo->dst.type, pinfo->dst.len, pinfo->dst.data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, (ip_proto == IP_PROTO_UDP) ? "UDP" : "UDPlite");
col_clear(pinfo->cinfo, COL_INFO);
udph->uh_sport=tvb_get_ntohs(tvb, offset);
udph->uh_dport=tvb_get_ntohs(tvb, offset+2);
src_port_str = ep_udp_port_to_display(udph->uh_sport);
dst_port_str = ep_udp_port_to_display(udph->uh_dport);
col_add_lstr(pinfo->cinfo, COL_INFO,
"Source port: ", src_port_str, " "
"Destination port: ", dst_port_str,
COL_ADD_LSTR_TERMINATOR);
if (tree) {
if (udp_summary_in_tree) {
if (ip_proto == IP_PROTO_UDP) {
ti = proto_tree_add_protocol_format(tree, hfi_udp->id, tvb, offset, 8,
"User Datagram Protocol, Src Port: %s (%u), Dst Port: %s (%u)",
src_port_str, udph->uh_sport, dst_port_str, udph->uh_dport);
} else {
ti = proto_tree_add_protocol_format(tree, hfi_udplite->id, tvb, offset, 8,
"Lightweight User Datagram Protocol, Src Port: %s (%u), Dst Port: %s (%u)",
src_port_str, udph->uh_sport, dst_port_str, udph->uh_dport);
}
} else {
ti = proto_tree_add_item(tree, (ip_proto == IP_PROTO_UDP) ? hfi_udp : hfi_udplite, tvb, offset, 8, ENC_NA);
}
udp_tree = proto_item_add_subtree(ti, ett_udp);
port_item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_srcport.id, tvb, offset, 2, udph->uh_sport,
"%s (%u)", src_port_str, udph->uh_sport);
if ((udph->uh_sport > (32768 + 666)) && (udph->uh_sport <= (32768 + 666 + 30)))
expert_add_info_format(pinfo, port_item, &ei_udp_possible_traceroute, "Possible traceroute: hop #%u, attempt #%u",
((udph->uh_sport - 32768 - 666 - 1) / 3) + 1,
((udph->uh_sport - 32768 - 666 - 1) % 3) + 1
);
port_item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_dstport.id, tvb, offset + 2, 2, udph->uh_dport,
"%s (%u)", dst_port_str, udph->uh_dport);
if ((udph->uh_dport > (32768 + 666)) && (udph->uh_dport <= (32768 + 666 + 30)))
expert_add_info_format(pinfo, port_item, &ei_udp_possible_traceroute, "Possible traceroute: hop #%u, attempt #%u",
((udph->uh_dport - 32768 - 666 - 1) / 3) + 1,
((udph->uh_dport - 32768 - 666 - 1) % 3) + 1
);
hidden_item = proto_tree_add_uint(udp_tree, &hfi_udp_port, tvb, offset, 2, udph->uh_sport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(udp_tree, &hfi_udp_port, tvb, offset+2, 2, udph->uh_dport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (ip_proto == IP_PROTO_UDP) {
udph->uh_ulen = udph->uh_sum_cov = tvb_get_ntohs(tvb, offset+4);
if (udph->uh_ulen < 8) {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_length.id, tvb, offset + 4, 2,
udph->uh_ulen, "%u (bogus, must be >= 8)", udph->uh_ulen);
expert_add_info_format(pinfo, item, &ei_udp_length, "Bad length value %u < 8", udph->uh_ulen);
col_append_fstr(pinfo->cinfo, COL_INFO, " [BAD UDP LENGTH %u < 8]", udph->uh_ulen);
return;
}
if ((udph->uh_ulen > tvb_reported_length(tvb)) && ! pinfo->fragmented && ! pinfo->flags.in_error_pkt) {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_length.id, tvb, offset + 4, 2,
udph->uh_ulen, "%u (bogus, payload length %u)", udph->uh_ulen, tvb_reported_length(tvb));
expert_add_info_format(pinfo, item, &ei_udp_length, "Bad length value %u > IP payload length", udph->uh_ulen);
col_append_fstr(pinfo->cinfo, COL_INFO, " [BAD UDP LENGTH %u > IP PAYLOAD LENGTH]", udph->uh_ulen);
} else {
if (tree) {
proto_tree_add_uint(udp_tree, &hfi_udp_length, tvb, offset + 4, 2, udph->uh_ulen);
hidden_item = proto_tree_add_uint(udp_tree, &hfi_udplite_checksum_coverage, tvb, offset + 4,
0, udph->uh_sum_cov);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
} else {
udph->uh_ulen = tvb_reported_length(tvb);
udph->uh_sum_cov = tvb_get_ntohs(tvb, offset+4);
if (((udph->uh_sum_cov > 0) && (udph->uh_sum_cov < 8)) || (udph->uh_sum_cov > udph->uh_ulen)) {
if (tree) {
hidden_item = proto_tree_add_boolean(udp_tree, &hfi_udplite_checksum_coverage_bad, tvb, offset + 4, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(udp_tree, &hfi_udp_length, tvb, offset + 4, 0, udph->uh_ulen);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
item = proto_tree_add_uint_format_value(udp_tree, hfi_udplite_checksum_coverage.id, tvb, offset + 4, 2,
udph->uh_sum_cov, "%u (bogus, must be >= 8 and <= %u (ip.len-ip.hdr_len))",
udph->uh_sum_cov, udph->uh_ulen);
expert_add_info_format(pinfo, item, &ei_udplite_checksum_coverage, "Bad checksum coverage length value %u < 8 or > %u",
udph->uh_sum_cov, udph->uh_ulen);
col_append_fstr(pinfo->cinfo, COL_INFO, " [BAD LIGHTWEIGHT UDP CHECKSUM COVERAGE LENGTH %u < 8 or > %u]",
udph->uh_sum_cov, udph->uh_ulen);
if (!udplite_ignore_checksum_coverage)
return;
} else {
if (tree) {
hidden_item = proto_tree_add_uint(udp_tree, &hfi_udp_length, tvb, offset + 4, 0, udph->uh_ulen);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint(udp_tree, &hfi_udplite_checksum_coverage, tvb, offset + 4, 2, udph->uh_sum_cov);
}
}
}
udph->uh_sum_cov = (udph->uh_sum_cov) ? udph->uh_sum_cov : udph->uh_ulen;
udph->uh_sum = tvb_get_ntohs(tvb, offset+6);
reported_len = tvb_reported_length(tvb);
len = tvb_captured_length(tvb);
if (udph->uh_sum == 0) {
if ((ip_proto == IP_PROTO_UDP) && (pinfo->src.type == AT_IPv4)) {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb, offset + 6, 2, 0,
"0x%04x (none)", 0);
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb, offset + 6, 2, 0,
"0x%04x (Illegal)", 0);
expert_add_info(pinfo, item, &ei_udp_checksum_zero);
col_append_str(pinfo->cinfo, COL_INFO, " [ILLEGAL CHECKSUM (0)]");
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
}
} else if (!pinfo->fragmented && (len >= reported_len) &&
(len >= udph->uh_sum_cov) && (reported_len >= udph->uh_sum_cov) &&
(udph->uh_sum_cov >= 8)) {
if (((ip_proto == IP_PROTO_UDP) && udp_check_checksum) ||
((ip_proto == IP_PROTO_UDPLITE) && udplite_check_checksum)) {
cksum_vec[0].ptr = (const guint8 *)pinfo->src.data;
cksum_vec[0].len = pinfo->src.len;
cksum_vec[1].ptr = (const guint8 *)pinfo->dst.data;
cksum_vec[1].len = pinfo->dst.len;
cksum_vec[2].ptr = (const guint8 *)&phdr;
switch (pinfo->src.type) {
case AT_IPv4:
if (ip_proto == IP_PROTO_UDP)
phdr[0] = g_htonl((ip_proto<<16) | udph->uh_ulen);
else
phdr[0] = g_htonl((ip_proto<<16) | reported_len);
cksum_vec[2].len = 4;
break;
case AT_IPv6:
if (ip_proto == IP_PROTO_UDP)
phdr[0] = g_htonl(udph->uh_ulen);
else
phdr[0] = g_htonl(reported_len);
phdr[1] = g_htonl(ip_proto);
cksum_vec[2].len = 8;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
cksum_vec[3].ptr = tvb_get_ptr(tvb, offset, udph->uh_sum_cov);
cksum_vec[3].len = udph->uh_sum_cov;
computed_cksum = in_cksum(&cksum_vec[0], 4);
if (computed_cksum == 0) {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb,
offset + 6, 2, udph->uh_sum, "0x%04x [correct]", udph->uh_sum);
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_uint(checksum_tree, &hfi_udp_checksum_calculated,
tvb, offset + 6, 2, udph->uh_sum);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
expected_cksum = in_cksum_shouldbe(udph->uh_sum, computed_cksum);
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb,
offset + 6, 2, udph->uh_sum,
"0x%04x [incorrect, should be 0x%04x (maybe caused by \"UDP checksum offload\"?)]", udph->uh_sum,
expected_cksum);
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_uint(checksum_tree, &hfi_udp_checksum_calculated,
tvb, offset + 6, 2, expected_cksum);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
expert_add_info(pinfo, item, &ei_udp_checksum_bad);
col_append_str(pinfo->cinfo, COL_INFO, " [UDP CHECKSUM INCORRECT]");
}
} else {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb,
offset + 6, 2, udph->uh_sum, "0x%04x [validation disabled]", udph->uh_sum);
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
}
} else {
item = proto_tree_add_uint_format_value(udp_tree, hfi_udp_checksum.id, tvb,
offset + 6, 2, udph->uh_sum, "0x%04x [unchecked, not all data available]", udph->uh_sum);
checksum_tree = proto_item_add_subtree(item, ett_udp_checksum);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_good, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, &hfi_udp_checksum_bad, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
}
offset += 8;
pinfo->ptype = PT_UDP;
pinfo->srcport = udph->uh_sport;
pinfo->destport = udph->uh_dport;
tap_queue_packet(udp_tap, pinfo, udph);
conv=find_or_create_conversation(pinfo);
udpd=get_udp_conversation_data(conv,pinfo);
if (udpd) {
item = proto_tree_add_uint(udp_tree, &hfi_udp_stream, tvb, offset, 0, udpd->stream);
PROTO_ITEM_SET_GENERATED(item);
udph->uh_stream = udpd->stream;
}
if (udpd && ((udpd->fwd && udpd->fwd->command) || (udpd->rev && udpd->rev->command))) {
ti = proto_tree_add_text(udp_tree, tvb, offset, 0, "Process Information");
PROTO_ITEM_SET_GENERATED(ti);
process_tree = proto_item_add_subtree(ti, ett_udp_process_info);
if (udpd->fwd && udpd->fwd->command) {
proto_tree_add_uint_format_value(process_tree, hfi_udp_proc_dst_uid.id, tvb, 0, 0,
udpd->fwd->process_uid, "%u", udpd->fwd->process_uid);
proto_tree_add_uint_format_value(process_tree, hfi_udp_proc_dst_pid.id, tvb, 0, 0,
udpd->fwd->process_pid, "%u", udpd->fwd->process_pid);
proto_tree_add_string_format_value(process_tree, hfi_udp_proc_dst_uname.id, tvb, 0, 0,
udpd->fwd->username, "%s", udpd->fwd->username);
proto_tree_add_string_format_value(process_tree, hfi_udp_proc_dst_cmd.id, tvb, 0, 0,
udpd->fwd->command, "%s", udpd->fwd->command);
}
if (udpd->rev->command) {
proto_tree_add_uint_format_value(process_tree, hfi_udp_proc_src_uid.id, tvb, 0, 0,
udpd->rev->process_uid, "%u", udpd->rev->process_uid);
proto_tree_add_uint_format_value(process_tree, hfi_udp_proc_src_pid.id, tvb, 0, 0,
udpd->rev->process_pid, "%u", udpd->rev->process_pid);
proto_tree_add_string_format_value(process_tree, hfi_udp_proc_src_uname.id, tvb, 0, 0,
udpd->rev->username, "%s", udpd->rev->username);
proto_tree_add_string_format_value(process_tree, hfi_udp_proc_src_cmd.id, tvb, 0, 0,
udpd->rev->command, "%s", udpd->rev->command);
}
}
if (!pinfo->flags.in_error_pkt || (tvb_captured_length_remaining(tvb, offset) > 0))
decode_udp_ports(tvb, offset, pinfo, tree, udph->uh_sport, udph->uh_dport,
udph->uh_ulen);
}
static void
dissect_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect(tvb, pinfo, tree, IP_PROTO_UDP);
}
static void
dissect_udplite(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect(tvb, pinfo, tree, IP_PROTO_UDPLITE);
}
static void
udp_init(void)
{
udp_stream_count = 0;
}
void
proto_register_udp(void)
{
module_t *udp_module;
module_t *udplite_module;
expert_module_t* expert_udp;
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_udp_srcport,
&hfi_udp_dstport,
&hfi_udp_port,
&hfi_udp_stream,
&hfi_udp_length,
&hfi_udp_checksum,
&hfi_udp_checksum_calculated,
&hfi_udp_checksum_good,
&hfi_udp_checksum_bad,
&hfi_udp_proc_src_uid,
&hfi_udp_proc_src_pid,
&hfi_udp_proc_src_uname,
&hfi_udp_proc_src_cmd,
&hfi_udp_proc_dst_uid,
&hfi_udp_proc_dst_pid,
&hfi_udp_proc_dst_uname,
&hfi_udp_proc_dst_cmd,
};
static header_field_info *hfi_lite[] = {
&hfi_udplite_checksum_coverage_bad,
&hfi_udplite_checksum_coverage,
};
#endif
static gint *ett[] = {
&ett_udp,
&ett_udp_checksum,
&ett_udp_process_info
};
static ei_register_info ei[] = {
{ &ei_udp_possible_traceroute, { "udp.possible_traceroute", PI_SEQUENCE, PI_CHAT, "Possible traceroute", EXPFILL }},
{ &ei_udp_length, { "udp.length.bad", PI_MALFORMED, PI_ERROR, "Bad length value", EXPFILL }},
{ &ei_udplite_checksum_coverage, { "udp.checksum_coverage.expert", PI_MALFORMED, PI_ERROR, "Bad checksum coverage length value", EXPFILL }},
{ &ei_udp_checksum_zero, { "udp.checksum.zero", PI_CHECKSUM, PI_ERROR, "Illegal Checksum value (0)", EXPFILL }},
{ &ei_udp_checksum_bad, { "udp.checksum_bad.expert", PI_CHECKSUM, PI_ERROR, "Bad checksum", EXPFILL }},
};
static build_valid_func udp_da_src_values[1] = {udp_src_value};
static build_valid_func udp_da_dst_values[1] = {udp_dst_value};
static build_valid_func udp_da_both_values[2] = {udp_src_value, udp_dst_value};
static decode_as_value_t udp_da_values[3] = {{udp_src_prompt, 1, udp_da_src_values}, {udp_dst_prompt, 1, udp_da_dst_values}, {udp_both_prompt, 2, udp_da_both_values}};
static decode_as_t udp_da = {"udp", "Transport", "udp.port", 3, 2, udp_da_values, "UDP", "port(s) as",
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
int proto_udp, proto_udplite;
proto_udp = proto_register_protocol("User Datagram Protocol",
"UDP", "udp");
hfi_udp = proto_registrar_get_nth(proto_udp);
udp_handle = register_dissector("udp", dissect_udp, proto_udp);
expert_udp = expert_register_protocol(proto_udp);
proto_register_fields(proto_udp, hfi, array_length(hfi));
proto_udplite = proto_register_protocol("Lightweight User Datagram Protocol",
"UDPlite", "udplite");
udplite_handle = create_dissector_handle(dissect_udplite, proto_udplite);
hfi_udplite = proto_registrar_get_nth(proto_udplite);
proto_register_fields(proto_udplite, hfi_lite, array_length(hfi_lite));
proto_register_subtree_array(ett, array_length(ett));
expert_register_field_array(expert_udp, ei, array_length(ei));
udp_dissector_table = register_dissector_table("udp.port",
"UDP port", FT_UINT16, BASE_DEC);
register_heur_dissector_list("udp", &heur_subdissector_list);
register_heur_dissector_list("udplite", &heur_subdissector_list);
udp_module = prefs_register_protocol(proto_udp, NULL);
prefs_register_bool_preference(udp_module, "summary_in_tree",
"Show UDP summary in protocol tree",
"Whether the UDP summary line should be shown in the protocol tree",
&udp_summary_in_tree);
prefs_register_bool_preference(udp_module, "try_heuristic_first",
"Try heuristic sub-dissectors first",
"Try to decode a packet using an heuristic sub-dissector"
" before using a sub-dissector registered to a specific port",
&try_heuristic_first);
prefs_register_bool_preference(udp_module, "check_checksum",
"Validate the UDP checksum if possible",
"Whether to validate the UDP checksum",
&udp_check_checksum);
prefs_register_bool_preference(udp_module, "process_info",
"Collect process flow information",
"Collect process flow information from IPFIX",
&udp_process_info);
udplite_module = prefs_register_protocol(proto_udplite, NULL);
prefs_register_bool_preference(udplite_module, "ignore_checksum_coverage",
"Ignore UDPlite checksum coverage",
"Ignore an invalid checksum coverage field and continue dissection",
&udplite_ignore_checksum_coverage);
prefs_register_bool_preference(udplite_module, "check_checksum",
"Validate the UDPlite checksum if possible",
"Whether to validate the UDPlite checksum",
&udplite_check_checksum);
register_decode_as(&udp_da);
register_init_routine(udp_init);
}
void
proto_reg_handoff_udp(void)
{
dissector_add_uint("ip.proto", IP_PROTO_UDP, udp_handle);
dissector_add_uint("ip.proto", IP_PROTO_UDPLITE, udplite_handle);
data_handle = find_dissector("data");
udp_tap = register_tap("udp");
udp_follow_tap = register_tap("udp_follow");
}
