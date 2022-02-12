static void
decode_dccp_ports(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *tree, int sport, int dport)
{
tvbuff_t *next_tvb;
int low_port, high_port;
heur_dtbl_entry_t *hdtbl_entry;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (try_conversation_dissector(&pinfo->src, &pinfo->dst, PT_DCCP, sport,
dport, next_tvb, pinfo, tree, NULL)) {
return;
}
if (try_heuristic_first) {
if (dissector_try_heuristic(heur_subdissector_list, next_tvb, pinfo,
tree, &hdtbl_entry, NULL)) {
return;
}
}
if (sport > dport) {
low_port = dport;
high_port = sport;
} else {
low_port = sport;
high_port = dport;
}
if (low_port != 0 &&
dissector_try_uint(dccp_subdissector_table, low_port,
next_tvb, pinfo, tree)) {
return;
}
if (high_port != 0 &&
dissector_try_uint(dccp_subdissector_table, high_port,
next_tvb, pinfo, tree)) {
return;
}
if (!try_heuristic_first) {
if (dissector_try_heuristic(heur_subdissector_list, next_tvb,
pinfo, tree, &hdtbl_entry, NULL)) {
return;
}
}
call_data_dissector(next_tvb, pinfo, tree);
}
static guint64
tvb_get_ntoh_var(tvbuff_t *tvb, gint offset, guint nbytes)
{
const guint8 *ptr;
guint64 value = 0;
ptr = tvb_get_ptr(tvb, offset, nbytes);
if (nbytes > 5)
value += ((guint64) * ptr++) << 40;
if (nbytes > 4)
value += ((guint64) * ptr++) << 32;
if (nbytes > 3)
value += ((guint64) * ptr++) << 24;
if (nbytes > 2)
value += ((guint64) * ptr++) << 16;
if (nbytes > 1)
value += ((guint64) * ptr++) << 8;
if (nbytes > 0)
value += *ptr;
return value;
}
static void
dissect_feature_options(proto_tree *dccp_options_tree, tvbuff_t *tvb,
int offset, guint8 option_len,
guint8 option_type)
{
guint8 feature_number = tvb_get_guint8(tvb, offset);
proto_item *dccp_item;
proto_tree *feature_tree;
int i;
feature_tree =
proto_tree_add_subtree_format(dccp_options_tree, tvb, offset, option_len,
ett_dccp_feature, &dccp_item, "%s(",
rval_to_str_const(option_type, dccp_feature_numbers_rvals, "Unknown feature number"));
proto_tree_add_uint(feature_tree, hf_dccp_feature_number, tvb,
offset, 1, feature_number);
offset++;
option_len--;
switch (feature_number) {
case 1:
case 2:
case 4:
case 6:
case 7:
case 8:
case 9:
case 192:
for (i = 0; i < option_len; i++)
proto_item_append_text(dccp_item, "%s %d", i ? "," : "",
tvb_get_guint8(tvb,
offset + i));
break;
case 3:
case 5:
if (option_len > 0)
proto_item_append_text(dccp_item, " %" G_GINT64_MODIFIER "u",
tvb_get_ntoh_var(tvb, offset, option_len));
break;
default:
proto_item_append_text(dccp_item, "%d", feature_number);
break;
}
proto_item_append_text(dccp_item, ")");
}
static void
dissect_options(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *dccp_options_tree, proto_tree *tree _U_,
e_dccphdr *dccph _U_,
int offset_start,
int offset_end)
{
int offset = offset_start;
guint8 option_type = 0;
guint8 option_len = 0;
guint32 p;
proto_item *option_item;
proto_tree *option_tree;
while (offset < offset_end) {
option_type = tvb_get_guint8(tvb, offset);
option_item =
proto_tree_add_uint(dccp_options_tree, hf_dccp_option_type, tvb,
offset,
1,
option_type);
if (option_type >= 32) {
option_len = tvb_get_guint8(tvb, offset+1);
if (option_len < 2) {
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Option length incorrect, must be >= 2");
return;
}
proto_item_set_len(option_item, option_len);
offset += 2;
option_len -= 2;
} else {
option_len = 1;
}
option_tree = proto_item_add_subtree(option_item, ett_dccp_options_item);
switch (option_type) {
case 0:
proto_tree_add_item(option_tree, hf_dccp_padding, tvb, offset, option_len, ENC_NA);
break;
case 1:
proto_tree_add_item(option_tree, hf_dccp_mandatory, tvb, offset, option_len, ENC_NA);
break;
case 2:
proto_tree_add_item(option_tree, hf_dccp_slow_receiver, tvb, offset, option_len, ENC_NA);
break;
case 32:
case 33:
case 34:
case 35:
dissect_feature_options(option_tree, tvb, offset, option_len,
option_type);
break;
case 36:
proto_tree_add_item(option_tree, hf_dccp_init_cookie, tvb, offset, option_len, ENC_NA);
break;
case 37:
if (option_len > 6)
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"NDP Count too long (max 6 bytes)");
else
proto_tree_add_uint64(option_tree, hf_dccp_ndp_count, tvb, offset, option_len,
tvb_get_ntoh_var(tvb, offset, option_len));
break;
case 38:
proto_tree_add_item(option_tree, hf_dccp_ack_vector_nonce_0, tvb, offset, option_len, ENC_NA);
break;
case 39:
proto_tree_add_item(option_tree, hf_dccp_ack_vector_nonce_1, tvb, offset, option_len, ENC_NA);
break;
case 40:
proto_tree_add_item(option_tree, hf_dccp_data_dropped, tvb, offset, option_len, ENC_NA);
break;
case 41:
if (option_len == 4)
proto_tree_add_item(option_tree, hf_dccp_timestamp, tvb,
offset, 4, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Timestamp too long [%u != 4]", option_len);
break;
case 42:
if (option_len == 4)
proto_tree_add_item(option_tree, hf_dccp_timestamp_echo,
tvb, offset, 4, ENC_BIG_ENDIAN);
else if (option_len == 6) {
proto_tree_add_item(option_tree, hf_dccp_timestamp_echo,
tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(option_tree, hf_dccp_elapsed_time,
tvb, offset + 4, 2, ENC_BIG_ENDIAN);
} else if (option_len == 8) {
proto_tree_add_item(option_tree, hf_dccp_timestamp_echo,
tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(option_tree, hf_dccp_elapsed_time,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
} else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Wrong Timestamp Echo length");
break;
case 43:
if (option_len == 2)
proto_tree_add_item(option_tree, hf_dccp_elapsed_time,
tvb, offset, 2, ENC_BIG_ENDIAN);
else if (option_len == 4)
proto_tree_add_item(option_tree, hf_dccp_elapsed_time,
tvb, offset, 4, ENC_BIG_ENDIAN);
else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Wrong Elapsed Time length");
break;
case 44:
if (option_len == 4) {
proto_tree_add_item(option_tree, hf_dccp_data_checksum,
tvb, offset, 4, ENC_BIG_ENDIAN);
} else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Wrong Data checksum length");
break;
case 192:
if (option_len == 4) {
p = tvb_get_ntohl(tvb, offset);
if (p == 0xFFFFFFFF)
proto_tree_add_uint_format_value(option_tree, hf_dccp_ccid3_loss_event_rate, tvb, offset,
option_len, p, "0 (or max)");
else
proto_tree_add_uint(option_tree, hf_dccp_ccid3_loss_event_rate, tvb, offset, option_len, p);
} else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Wrong CCID3 Loss Event Rate length");
break;
case 193:
proto_tree_add_item(dccp_options_tree, hf_dccp_ccid3_loss_intervals, tvb, offset, option_len, ENC_NA);
break;
case 194:
if (option_len == 4)
proto_tree_add_uint_format_value(option_tree, hf_dccp_ccid3_receive_rate, tvb, offset, option_len,
tvb_get_ntohl(tvb, offset), "%u bytes/sec",
tvb_get_ntohl(tvb, offset));
else
expert_add_info_format(pinfo, option_item, &ei_dccp_option_len_bad,
"Wrong CCID3 Receive Rate length");
break;
default:
if (((option_type >= 45) && (option_type <= 127)) ||
((option_type >= 3) && (option_type <= 31))) {
proto_tree_add_item(option_tree, hf_dccp_option_reserved, tvb, offset, option_len, ENC_NA);
break;
}
if (option_type >= 128) {
proto_tree_add_bytes_format(option_tree, hf_dccp_ccid_option_data, tvb, offset, option_len,
NULL, "CCID option %d", option_type);
break;
}
proto_tree_add_item(option_tree, hf_dccp_option_unknown, tvb, offset, option_len, ENC_NA);
break;
}
offset += option_len;
}
}
static inline guint
dccp_csum_coverage(const e_dccphdr *dccph, guint len)
{
guint cov;
if (dccph->cscov == 0)
return len;
cov = (dccph->data_offset + dccph->cscov - 1) * (guint)sizeof (guint32);
return (cov > len) ? len : cov;
}
static int
dissect_dccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *dccp_tree;
proto_tree *dccp_options_tree = NULL;
proto_item *dccp_item = NULL;
proto_item *hidden_item, *offset_item;
vec_t cksum_vec[4];
guint32 phdr[2];
guint16 computed_cksum;
guint offset = 0;
guint len = 0;
guint reported_len = 0;
guint csum_coverage_len;
guint advertised_dccp_header_len = 0;
guint options_len = 0;
e_dccphdr *dccph;
dccph = wmem_new0(wmem_packet_scope(), e_dccphdr);
dccph->sport = tvb_get_ntohs(tvb, offset);
dccph->dport = tvb_get_ntohs(tvb, offset + 2);
copy_address_shallow(&dccph->ip_src, &pinfo->src);
copy_address_shallow(&dccph->ip_dst, &pinfo->dst);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCCP");
col_clear(pinfo->cinfo, COL_INFO);
col_append_ports(pinfo->cinfo, COL_INFO, PT_DCCP, dccph->sport, dccph->dport);
dccp_item = proto_tree_add_item(tree, proto_dccp, tvb, offset, -1, ENC_NA);
if (dccp_summary_in_tree) {
proto_item_append_text(dccp_item, ", Src Port: %s, Dst Port: %s",
port_with_resolution_to_str(wmem_packet_scope(), PT_DCCP, dccph->sport),
port_with_resolution_to_str(wmem_packet_scope(), PT_DCCP, dccph->dport));
}
dccp_tree = proto_item_add_subtree(dccp_item, ett_dccp);
proto_tree_add_item(dccp_tree, hf_dccp_srcport, tvb, offset, 2, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(dccp_tree, hf_dccp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 2;
proto_tree_add_item(dccp_tree, hf_dccp_dstport, tvb, offset, 2, ENC_BIG_ENDIAN);
hidden_item = proto_tree_add_item(dccp_tree, hf_dccp_port, tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 2;
pinfo->ptype = PT_DCCP;
pinfo->srcport = dccph->sport;
pinfo->destport = dccph->dport;
dccph->data_offset = tvb_get_guint8(tvb, offset);
advertised_dccp_header_len = dccph->data_offset * 4;
offset_item = proto_tree_add_uint(dccp_tree, hf_dccp_data_offset, tvb, offset, 1,
dccph->data_offset);
offset += 1;
dccph->cscov = tvb_get_guint8(tvb, offset) & 0x0F;
dccph->ccval = tvb_get_guint8(tvb, offset) & 0xF0;
dccph->ccval >>= 4;
proto_tree_add_uint(dccp_tree, hf_dccp_ccval, tvb, offset, 1,
dccph->ccval);
proto_tree_add_uint(dccp_tree, hf_dccp_cscov, tvb, offset, 1,
dccph->cscov);
offset += 1;
dccph->checksum = tvb_get_ntohs(tvb, offset);
reported_len = tvb_reported_length(tvb);
len = tvb_captured_length(tvb);
csum_coverage_len = dccp_csum_coverage(dccph, reported_len);
if (dccp_check_checksum && !pinfo->fragmented && len >= csum_coverage_len) {
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
switch (pinfo->src.type) {
case AT_IPv4:
phdr[0] = g_htonl((IP_PROTO_DCCP << 16) + reported_len);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *) &phdr, 4);
break;
case AT_IPv6:
phdr[0] = g_htonl(reported_len);
phdr[1] = g_htonl(IP_PROTO_DCCP);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *) &phdr, 8);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, csum_coverage_len);
computed_cksum = in_cksum(&cksum_vec[0], 4);
if (computed_cksum == 0) {
proto_tree_add_uint_format_value(dccp_tree,
hf_dccp_checksum, tvb,
offset, 2,
dccph->checksum,
"0x%04x [correct]",
dccph->checksum);
} else {
hidden_item =
proto_tree_add_boolean(dccp_tree, hf_dccp_checksum_bad,
tvb, offset, 2, TRUE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_uint_format_value(
dccp_tree, hf_dccp_checksum, tvb, offset, 2,
dccph->checksum,
"0x%04x [incorrect, should be 0x%04x]",
dccph->checksum,
in_cksum_shouldbe(dccph->checksum, computed_cksum));
}
} else {
proto_tree_add_uint_format_value(dccp_tree, hf_dccp_checksum, tvb,
offset, 2, dccph->checksum,
"0x%04x", dccph->checksum);
}
offset += 2;
dccph->reserved1 = tvb_get_guint8(tvb, offset) & 0xE0;
dccph->reserved1 >>= 5;
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_res1, tvb, offset, 1,
dccph->reserved1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
dccph->type = tvb_get_guint8(tvb, offset) & 0x1E;
dccph->type >>= 1;
proto_tree_add_uint(dccp_tree, hf_dccp_type, tvb, offset, 1,
dccph->type);
if (dccp_summary_in_tree) {
proto_item_append_text(dccp_item, " [%s]",
val_to_str_const(dccph->type, dccp_packet_type_vals,
"Unknown Type"));
}
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]",
val_to_str_const(dccph->type, dccp_packet_type_vals,
"Unknown Type"));
dccph->x = tvb_get_guint8(tvb, offset) & 0x01;
proto_tree_add_boolean(dccp_tree, hf_dccp_x, tvb, offset, 1,
dccph->x);
offset += 1;
if (dccph->x) {
if (advertised_dccp_header_len < DCCP_GEN_HDR_LEN_X) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u)",
advertised_dccp_header_len, DCCP_GEN_HDR_LEN_X);
return tvb_reported_length(tvb);
}
dccph->reserved2 = tvb_get_guint8(tvb, offset);
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_res2, tvb, offset, 1,
dccph->reserved2);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += 1;
dccph->seq = tvb_get_ntoh48(tvb, offset);
proto_tree_add_uint64(dccp_tree, hf_dccp_seq, tvb, offset, 6,
dccph->seq);
offset += 6;
} else {
if (advertised_dccp_header_len < DCCP_GEN_HDR_LEN_NO_X) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u)",
advertised_dccp_header_len, DCCP_GEN_HDR_LEN_NO_X);
return tvb_reported_length(tvb);
}
dccph->seq = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint64(dccp_tree, hf_dccp_seq, tvb, offset, 3,
dccph->seq);
offset += 3;
}
if (dccp_summary_in_tree) {
proto_item_append_text(dccp_item, " Seq=%" G_GINT64_MODIFIER "u",
dccph->seq);
}
col_append_fstr(pinfo->cinfo, COL_INFO,
" Seq=%" G_GINT64_MODIFIER "u",
dccph->seq);
switch (dccph->type) {
case 0x0:
case 0xA:
if (advertised_dccp_header_len < offset + 4) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for %s",
advertised_dccp_header_len, offset + 4,
val_to_str(dccph->type, dccp_packet_type_vals, "Unknown (%u)"));
return tvb_reported_length(tvb);
}
dccph->service_code = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(dccp_tree, hf_dccp_service_code, tvb, offset, 4,
dccph->service_code);
col_append_fstr(pinfo->cinfo, COL_INFO, " (service=%u)",
dccph->service_code);
offset += 4;
break;
case 0x1:
if (advertised_dccp_header_len < offset + 12) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for Response",
advertised_dccp_header_len, offset + 12);
return tvb_reported_length(tvb);
}
dccph->ack_reserved = tvb_get_ntohs(tvb, offset);
if (tree) {
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_ack_res, tvb, offset, 2,
dccph->ack_reserved);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
dccph->ack = tvb_get_ntohs(tvb, offset + 2);
dccph->ack <<= 32;
dccph->ack += tvb_get_ntohl(tvb, offset + 4);
if (tree)
proto_tree_add_uint64(dccp_tree, hf_dccp_ack, tvb, offset + 2, 6,
dccph->ack);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Ack=%" G_GINT64_MODIFIER "u)",
dccph->ack);
offset += 8;
dccph->service_code = tvb_get_ntohl(tvb, offset);
if (tree)
proto_tree_add_uint(dccp_tree, hf_dccp_service_code, tvb, offset, 4,
dccph->service_code);
col_append_fstr(pinfo->cinfo, COL_INFO, " (service=%u)",
dccph->service_code);
offset += 4;
break;
case 0x2:
break;
case 0x3:
case 0x4:
if (dccph->x) {
if (advertised_dccp_header_len < offset + 8) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for %s",
advertised_dccp_header_len, offset + 8,
val_to_str(dccph->type, dccp_packet_type_vals, "Unknown (%u)"));
return tvb_reported_length(tvb);
}
dccph->ack_reserved = tvb_get_ntohs(tvb, offset);
if (tree) {
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_ack_res, tvb, offset,
2, dccph->ack_reserved);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
dccph->ack = tvb_get_ntohs(tvb, offset + 2);
dccph->ack <<= 32;
dccph->ack += tvb_get_ntohl(tvb, offset + 4);
if (tree)
proto_tree_add_uint64(dccp_tree, hf_dccp_ack, tvb, offset + 2,
6, dccph->ack);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Ack=%" G_GINT64_MODIFIER "u)",
dccph->ack);
offset += 8;
} else {
if (advertised_dccp_header_len < offset + 4) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for %s",
advertised_dccp_header_len, offset + 4,
val_to_str(dccph->type, dccp_packet_type_vals, "Unknown (%u)"));
return tvb_reported_length(tvb);
}
dccph->ack_reserved = tvb_get_guint8(tvb, offset);
if (tree) {
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_ack_res, tvb, offset,
1, dccph->ack_reserved);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
dccph->ack = tvb_get_guint8(tvb, offset + 1);
dccph->ack <<= 16;
dccph->ack += tvb_get_ntohs(tvb, offset + 2);
if (tree)
proto_tree_add_uint64(dccp_tree, hf_dccp_ack, tvb, offset + 1,
3, dccph->ack);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Ack=%" G_GINT64_MODIFIER "u)", dccph->ack);
offset += 4;
}
break;
case 0x7:
if (advertised_dccp_header_len < offset + 4) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for Reset",
advertised_dccp_header_len, offset + 4);
return tvb_reported_length(tvb);
}
dccph->ack_reserved = tvb_get_ntohs(tvb, offset);
if (tree) {
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_ack_res, tvb, offset, 2,
dccph->ack_reserved);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
dccph->ack = tvb_get_ntohs(tvb, offset + 2);
dccph->ack <<= 32;
dccph->ack += tvb_get_ntohl(tvb, offset + 4);
if (tree)
proto_tree_add_uint64(dccp_tree, hf_dccp_ack, tvb, offset + 2, 6,
dccph->ack);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Ack=%" G_GINT64_MODIFIER "u)", dccph->ack);
offset += 8;
dccph->reset_code = tvb_get_guint8(tvb, offset);
dccph->data1 = tvb_get_guint8(tvb, offset + 1);
dccph->data2 = tvb_get_guint8(tvb, offset + 2);
dccph->data3 = tvb_get_guint8(tvb, offset + 3);
if (tree) {
proto_tree_add_uint(dccp_tree, hf_dccp_reset_code, tvb, offset, 1,
dccph->reset_code);
proto_tree_add_uint(dccp_tree, hf_dccp_data1, tvb, offset + 1, 1,
dccph->data1);
proto_tree_add_uint(dccp_tree, hf_dccp_data2, tvb, offset + 2, 1,
dccph->data2);
proto_tree_add_uint(dccp_tree, hf_dccp_data3, tvb, offset + 3, 1,
dccph->data3);
}
col_append_fstr(pinfo->cinfo, COL_INFO, " (code=%s)",
val_to_str_const(dccph->reset_code, dccp_reset_code_vals,
"Unknown"));
offset += 4;
break;
case 0x5:
case 0x6:
case 0x8:
case 0x9:
if (advertised_dccp_header_len < offset + 8) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is smaller than the minimum (%u) for %s",
advertised_dccp_header_len, offset + 8,
val_to_str(dccph->type, dccp_packet_type_vals, "Unknown (%u)"));
return tvb_reported_length(tvb);
}
dccph->ack_reserved = tvb_get_ntohs(tvb, offset);
if (tree) {
hidden_item =
proto_tree_add_uint(dccp_tree, hf_dccp_ack_res, tvb, offset, 2,
dccph->ack_reserved);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
dccph->ack = tvb_get_ntohs(tvb, offset + 2);
dccph->ack <<= 32;
dccph->ack += tvb_get_ntohl(tvb, offset + 4);
if (tree)
proto_tree_add_uint64(dccp_tree, hf_dccp_ack, tvb, offset + 2, 6,
dccph->ack);
col_append_fstr(pinfo->cinfo, COL_INFO,
" (Ack=%" G_GINT64_MODIFIER "u)", dccph->ack);
offset += 8;
break;
default:
expert_add_info(pinfo, dccp_item, &ei_dccp_packet_type_reserved);
return tvb_reported_length(tvb);
}
if (advertised_dccp_header_len > DCCP_HDR_LEN_MAX) {
expert_add_info_format(pinfo, offset_item, &ei_dccp_advertised_header_length_bad,
"Advertised header length (%u) is larger than the maximum (%u)",
advertised_dccp_header_len, DCCP_HDR_LEN_MAX);
return tvb_reported_length(tvb);
}
if (advertised_dccp_header_len > offset) {
options_len = advertised_dccp_header_len - offset;
if (dccp_tree) {
dccp_item =
proto_tree_add_none_format(dccp_tree, hf_dccp_options, tvb,
offset,
options_len, "Options: (%u byte%s)",
options_len,
plurality(options_len, "", "s"));
dccp_options_tree = proto_item_add_subtree(dccp_item,
ett_dccp_options);
}
dissect_options(tvb, pinfo, dccp_options_tree, tree, dccph, offset,
offset + options_len);
}
offset += options_len;
proto_item_set_end(dccp_item, tvb, offset);
tap_queue_packet(dccp_tap, pinfo, dccph);
if (!pinfo->flags.in_error_pkt || tvb_reported_length_remaining(tvb, offset) > 0)
decode_dccp_ports(tvb, offset, pinfo, tree, dccph->sport, dccph->dport);
return tvb_reported_length(tvb);
}
void
proto_register_dccp(void)
{
module_t *dccp_module;
static hf_register_info hf[] = {
{
&hf_dccp_srcport,
{
"Source Port", "dccp.srcport",
FT_UINT16, BASE_PT_DCCP, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_dstport,
{
"Destination Port", "dccp.dstport",
FT_UINT16, BASE_PT_DCCP, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_port,
{
"Source or Destination Port", "dccp.port",
FT_UINT16, BASE_PT_DCCP, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_data_offset,
{
"Data Offset", "dccp.data_offset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_ccval,
{
"CCVal", "dccp.ccval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_cscov,
{
"Checksum Coverage", "dccp.cscov",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_checksum_bad,
{
"Bad Checksum", "dccp.checksum_bad",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_checksum,
{
"Checksum", "dccp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_res1,
{
"Reserved", "dccp.res1",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_res2,
{
"Reserved", "dccp.res2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_type,
{
"Type", "dccp.type",
FT_UINT8, BASE_DEC, VALS(dccp_packet_type_vals), 0x0,
NULL, HFILL
}
},
{
&hf_dccp_x,
{
"Extended Sequence Numbers", "dccp.x",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_seq,
{
"Sequence Number", "dccp.seq",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_ack_res,
{
"Reserved", "dccp.ack_res",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_ack,
{
"Acknowledgement Number", "dccp.ack",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_service_code,
{
"Service Code", "dccp.service_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_reset_code,
{
"Reset Code", "dccp.reset_code",
FT_UINT8, BASE_DEC, VALS(dccp_reset_code_vals), 0x0,
NULL, HFILL
}
},
{
&hf_dccp_data1,
{
"Data 1", "dccp.data1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_data2,
{
"Data 2", "dccp.data2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_data3,
{
"Data 3", "dccp.data3",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_option_type,
{
"Option Type", "dccp.option_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(dccp_options_rvals), 0x0,
NULL, HFILL
}
},
{
&hf_dccp_feature_number,
{
"Feature Number", "dccp.feature_number",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(dccp_feature_numbers_rvals), 0x0,
NULL, HFILL
}
},
{
&hf_dccp_ndp_count,
{
"NDP Count", "dccp.ndp_count",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_timestamp,
{
"Timestamp", "dccp.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_timestamp_echo,
{
"Timestamp Echo", "dccp.timestamp_echo",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_elapsed_time,
{
"Elapsed Time", "dccp.elapsed_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_data_checksum,
{
"Data Checksum", "dccp.checksum_data",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_dccp_options,
{
"Options", "dccp.options",
FT_NONE, BASE_NONE, NULL, 0x0,
"DCCP Options fields", HFILL
}
},
{ &hf_dccp_padding, { "Padding", "dccp.padding", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_mandatory, { "Mandatory", "dccp.mandatory", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_slow_receiver, { "Slow Receiver", "dccp.slow_receiver", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_init_cookie, { "Init Cookie", "dccp.init_cookie", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ack_vector_nonce_0, { "Ack Vector [Nonce 0]", "dccp.ack_vector.nonce_0", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ack_vector_nonce_1, { "Ack Vector [Nonce 1]", "dccp.ack_vector.nonce_1", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_data_dropped, { "Data Dropped", "dccp.data_dropped", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ccid3_loss_event_rate, { "CCID3 Loss Event Rate", "dccp.ccid3_loss_event_rate", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ccid3_loss_intervals, { "CCID3 Loss Intervals", "dccp.ccid3_loss_intervals", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ccid3_receive_rate, { "CCID3 Receive Rate", "dccp.ccid3_receive_rate", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_option_reserved, { "Reserved", "dccp.option_reserved", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_ccid_option_data, { "CCID option", "dccp.ccid_option_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_dccp_option_unknown, { "Unknown", "dccp.option_unknown", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_dccp,
&ett_dccp_options,
&ett_dccp_options_item,
&ett_dccp_feature
};
static ei_register_info ei[] = {
{ &ei_dccp_option_len_bad, { "dccp.option.len.bad", PI_PROTOCOL, PI_WARN, "Bad option length", EXPFILL }},
{ &ei_dccp_advertised_header_length_bad, { "dccp.advertised_header_length.bad", PI_MALFORMED, PI_ERROR, "Advertised header length bad", EXPFILL }},
{ &ei_dccp_packet_type_reserved, { "dccp.packet_type.reserved", PI_PROTOCOL, PI_WARN, "Reserved packet type: unable to dissect further", EXPFILL }},
};
expert_module_t* expert_dccp;
proto_dccp =
proto_register_protocol("Datagram Congestion Control Protocol", "DCCP",
"dccp");
proto_register_field_array(proto_dccp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dccp = expert_register_protocol(proto_dccp);
expert_register_field_array(expert_dccp, ei, array_length(ei));
dccp_subdissector_table =
register_dissector_table("dccp.port", "DCCP port", proto_dccp, FT_UINT16,
BASE_DEC, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
heur_subdissector_list = register_heur_dissector_list("dccp", proto_dccp);
dccp_module = prefs_register_protocol(proto_dccp, NULL);
prefs_register_bool_preference(
dccp_module, "summary_in_tree",
"Show DCCP summary in protocol tree",
"Whether the DCCP summary line should be shown in the protocol tree",
&dccp_summary_in_tree);
prefs_register_bool_preference(
dccp_module, "try_heuristic_first",
"Try heuristic sub-dissectors first",
"Try to decode a packet using an heuristic sub-dissector before "
"using a sub-dissector "
"registered to a specific port",
&try_heuristic_first);
prefs_register_bool_preference(
dccp_module, "check_checksum",
"Check the validity of the DCCP checksum when possible",
"Whether to check the validity of the DCCP checksum",
&dccp_check_checksum);
}
void
proto_reg_handoff_dccp(void)
{
dissector_handle_t dccp_handle;
dccp_handle = create_dissector_handle(dissect_dccp, proto_dccp);
dissector_add_uint("ip.proto", IP_PROTO_DCCP, dccp_handle);
dccp_tap = register_tap("dccp");
}
