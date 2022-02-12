static void
dissect_hip_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean udp)
{
proto_tree *hip_tree, *hip_tlv_tree=NULL;
proto_item *ti, *ti_tlv;
int length, offset = 0, newoffset = 0;
guint16 control_h, checksum_h, computed_checksum;
guint16 tlv_type_h, tlv_length_h;
guint len;
guint reported_len;
vec_t cksum_vec[4];
guint32 phdr[2];
guint8 hiph_hdr_len;
guint8 hiph_shim6_fixed_bit_s;
guint8 hiph_packet_type;
guint8 hiph_res_ver, hiph_version, hiph_reserved;
guint8 hiph_shim6_fixed_bit_p;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HIP");
col_clear(pinfo->cinfo, COL_INFO);
newoffset = offset;
newoffset++;
hiph_hdr_len = tvb_get_guint8(tvb, newoffset);
newoffset++;
hiph_packet_type = tvb_get_guint8(tvb, newoffset);
hiph_shim6_fixed_bit_p = (hiph_packet_type & HIP_SHIM6_FIXED_BIT_P_MASK) >> 7;
hiph_packet_type = hiph_packet_type & HIP_PACKET_TYPE_MASK;
newoffset++;
hiph_res_ver = tvb_get_guint8(tvb, newoffset);
hiph_version = (hiph_res_ver & HIP_VERSION_MASK) >> 4;
hiph_reserved = hiph_res_ver & HIP_RESERVED_MASK;
hiph_shim6_fixed_bit_s = hiph_res_ver & HIP_SHIM6_FIXED_BIT_S_MASK;
newoffset++;
checksum_h = tvb_get_ntohs(tvb, newoffset);
newoffset += 2;
control_h = tvb_get_ntohs(tvb, newoffset);
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(hiph_packet_type, pinfo_vals, "Unknown"));
ti = proto_tree_add_item(tree, proto_hip, tvb, 0, -1, ENC_NA);
hip_tree = proto_item_add_subtree(ti, ett_hip);
proto_tree_add_item(hip_tree, hf_hip_proto, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(hip_tree, hf_hip_hdr_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format(hip_tree, hf_hip_shim6_fixed_bit_p, tvb, offset+2, 1,
hiph_shim6_fixed_bit_p,
"Fixed P-bit: %u (Always zero)",
hiph_shim6_fixed_bit_p);
proto_tree_add_uint(hip_tree, hf_hip_packet_type, tvb, offset+2, 1,
hiph_packet_type);
proto_tree_add_uint_format_value(hip_tree, hf_hip_version, tvb, offset+3, 1,
hiph_version, "%u, Reserved: %u",
hiph_version, hiph_reserved);
proto_tree_add_uint_format(hip_tree, hf_hip_shim6_fixed_bit_s, tvb, offset+3, 1,
hiph_shim6_fixed_bit_s,
"Fixed S-bit: %u (%s)",
hiph_shim6_fixed_bit_s,
((hiph_shim6_fixed_bit_s) ? "HIP" : "SHIM6"));
reported_len = tvb_reported_length(tvb);
len = tvb_captured_length(tvb);
if (!pinfo->fragmented && len >= reported_len) {
SET_CKSUM_VEC_PTR(cksum_vec[0], (const guint8 *)pinfo->src.data, pinfo->src.len);
SET_CKSUM_VEC_PTR(cksum_vec[1], (const guint8 *)pinfo->dst.data, pinfo->dst.len);
if (pinfo->src.type == AT_IPv6) {
phdr[0] = reported_len;
phdr[0] = g_htonl(phdr[0]);
phdr[1] = g_htonl(IP_PROTO_HIP);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 8);
} else {
phdr[0] = (IP_PROTO_HIP<<16)+reported_len;
phdr[0] = g_htonl(phdr[0]);
SET_CKSUM_VEC_PTR(cksum_vec[2], (const guint8 *)&phdr, 4);
}
SET_CKSUM_VEC_TVB(cksum_vec[3], tvb, 0, reported_len);
computed_checksum = in_cksum(cksum_vec, 4);
if (computed_checksum == 0) {
proto_tree_add_uint_format_value(hip_tree, hf_hip_checksum, tvb,
offset+4, 2, checksum_h,
"0x%04x (correct)",
checksum_h);
} else {
if (checksum_h == 0 && udp) {
proto_tree_add_uint_format_value(hip_tree, hf_hip_checksum, tvb,
offset+4, 2, checksum_h,
"0x%04x (correct)",
checksum_h);
} else {
proto_tree_add_uint_format_value(hip_tree, hf_hip_checksum, tvb,
offset+4, 2, checksum_h,
"0x%04x (incorrect, should be 0x%04x)",
checksum_h,
in_cksum_shouldbe(checksum_h,
computed_checksum));
}
}
} else {
proto_tree_add_uint_format_value(hip_tree, hf_hip_checksum, tvb,
offset+4, 2, checksum_h,
"0x%04x (unverified)",
checksum_h);
}
ti = proto_tree_add_item(hip_tree, hf_hip_controls, tvb, offset+6, 2, ENC_BIG_ENDIAN);
if (ti) {
ti = proto_item_add_subtree(ti, ett_hip_controls);
proto_tree_add_boolean(ti, hf_hip_controls_anon, tvb,
offset+7,1, control_h);
}
offset += 8;
proto_tree_add_item(hip_tree, hf_hip_hit_sndr, tvb, offset,
16, ENC_NA);
offset += 16;
proto_tree_add_item(hip_tree, hf_hip_hit_rcvr, tvb, offset,
16, ENC_NA);
offset += 16;
length = (hiph_hdr_len + 1) * 8;
if (offset < length) {
hip_tlv_tree = proto_tree_add_subtree(hip_tree, tvb, offset,
-1, ett_hip_tlv, NULL, "HIP Parameters");
}
while (offset < length)
{
tlv_type_h = tvb_get_ntohs(tvb, offset);
tlv_length_h = tvb_get_ntohs(tvb, offset + 2);
ti_tlv = proto_tree_add_uint_format(hip_tlv_tree, hf_hip_type, tvb,
offset, 4 + tlv_length_h, tlv_type_h,
"%s (type=%u, length=%u)",
val_to_str_const(tlv_type_h, hip_param_vals, "Unknown"),
tlv_type_h, tlv_length_h);
dissect_hip_tlv(tvb, pinfo, offset, ti_tlv, tlv_type_h, tlv_length_h);
offset += 11 + tlv_length_h - (tlv_length_h + 3) % 8;
}
}
static int
dissect_hip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_hip_common(tvb, pinfo, tree, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_hip_in_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint32 nullbytes;
tvbuff_t *newtvb;
if (tvb_captured_length(tvb) < 4)
return 0;
nullbytes = tvb_get_ntohl(tvb, 0);
if (nullbytes != 0)
return 0;
newtvb = tvb_new_subset_remaining(tvb, 4);
dissect_hip_common(newtvb, pinfo, tree, TRUE);
return tvb_captured_length(tvb);
}
static int
dissect_hip_tlv(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_item *ti, int type, int tlv_len)
{
proto_tree *t=NULL;
proto_item *ti_tlv, *ti_loc, *hi_len_item, *e_len_item, *arg_item;
guint8 n, algorithm, reg_type;
guint16 trans, hi_len, di_len, di_type, e_len, pv_len;
guint32 reserved, hi_hdr;
guint8 transport_proto;
guint8 locator_type;
int newoffset, newlen, hi_t;
newoffset = offset + 4;
t = proto_item_add_subtree(ti, ett_hip_tlv_data);
switch (type)
{
case PARAM_ESP_INFO:
proto_tree_add_item(t, hf_hip_tlv_ei_res, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_ei_keyidx, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_ei_oldspi, tvb, newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(t, hf_hip_tlv_ei_newspi, tvb, newoffset, 4, ENC_BIG_ENDIAN);
break;
case PARAM_R1_COUNTER:
proto_tree_add_item(t, hf_hip_tlv_r1_res, tvb, newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(t, hf_hip_tlv_r1count, tvb, newoffset, 8, ENC_NA);
break;
case PARAM_LOCATOR:
tlv_len -= 4;
while (tlv_len > 0) {
locator_type = tvb_get_guint8(tvb, newoffset + 1);
if (locator_type == 0) {
ti_loc = proto_tree_add_item(t, hf_hip_tlv_locator_address,
tvb, newoffset + 8, 16, ENC_NA);
} else if (locator_type == 1) {
ti_loc = proto_tree_add_item(t, hf_hip_tlv_locator_address,
tvb, newoffset + 12, 16, ENC_NA);
} else if (locator_type == 2) {
ti_loc = proto_tree_add_item(t, hf_hip_tlv_locator_address,
tvb, newoffset + 20, 16, ENC_NA);
} else {
ti_loc = NULL;
newoffset += (1 + tvb_get_guint8(tvb, newoffset + 2));
tlv_len -= (1 + tvb_get_guint8(tvb, newoffset + 2));
}
if (locator_type <= 2) {
ti_loc = proto_item_add_subtree(ti_loc, ett_hip_locator_data);
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_traffic_type, tvb,
newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
#if 0
locator_type = tvb_get_guint8(tvb, newoffset);
#endif
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_type, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_len, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
reserved = tvb_get_guint8(tvb, newoffset);
proto_tree_add_uint_format_value(ti_loc, hf_hip_tlv_locator_reserved, tvb,
newoffset, 1, reserved,
"0x%x %s", reserved,
(reserved >> 31) ? "(Preferred)" : "");
newoffset++;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_lifetime, tvb,
newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
if (locator_type == 0) {
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_address,
tvb, newoffset, 16, ENC_NA);
newoffset += 16;
tlv_len -= 24;
} else if (locator_type == 1) {
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_spi, tvb,
newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_address,
tvb, newoffset, 16, ENC_NA);
newoffset += 16;
tlv_len -= 28;
} else if (locator_type == 2) {
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_port, tvb,
newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
transport_proto = tvb_get_guint8(tvb, newoffset);
proto_tree_add_uint_format(ti_loc, hf_hip_tlv_locator_transport_protocol,
tvb, newoffset, 1, transport_proto,
"Transport protocol: %d %s",
transport_proto,
(transport_proto == 17) ?
"(UDP)" : "");
newoffset++;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_kind, tvb,
newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_priority, tvb,
newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_spi, tvb,
newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(ti_loc, hf_hip_tlv_locator_address,
tvb, newoffset, 16, ENC_NA);
newoffset += 16;
tlv_len -= 36;
}
}
}
break;
case PARAM_PUZZLE:
proto_tree_add_item(t, hf_hip_tlv_puzzle_k, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_puzzle_life, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_puzzle_o, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_puzzle_i, tvb,newoffset, tlv_len - 4, ENC_NA);
break;
case PARAM_SOLUTION:
proto_tree_add_item(t, hf_hip_tlv_solution_k, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_solution_reserved, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_solution_o, tvb,newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_solution_i, tvb, newoffset, (tlv_len - 4)/2, ENC_NA);
newoffset += (tlv_len - 4) /2;
proto_tree_add_item(t, hf_hip_tlv_solution_j, tvb, newoffset, (tlv_len -4)/2, ENC_NA);
break;
case PARAM_SEQ:
proto_tree_add_item(t, hf_hip_tlv_seq_updid, tvb, newoffset, 4, ENC_BIG_ENDIAN);
break;
case PARAM_ACK:
while (tlv_len > 0) {
proto_tree_add_item(t, hf_hip_tlv_ack_updid, tvb, newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
tlv_len -= 4;
}
break;
case PARAM_DIFFIE_HELLMAN:
n = tvb_get_guint8(tvb, newoffset);
proto_tree_add_uint_format(t, hf_hip_tlv_dh_group_id, tvb, newoffset,
1, n, "%u (%s)", n,
val_to_str_const(n, dh_group_id_vals, "Unknown"));
newoffset++;
pv_len = tvb_get_ntohs(tvb, newoffset);
proto_tree_add_item(t, hf_hip_tlv_dh_pv_length, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_dh_pub, tvb, newoffset, pv_len, ENC_NA);
if ((pv_len + newoffset) < tlv_len) {
newoffset += pv_len;
proto_tree_add_uint_format(t, hf_hip_tlv_dh_group_id, tvb, newoffset,
1, n, "%u (%s)", n,
val_to_str_const(n, dh_group_id_vals, "Unknown"));
newoffset += 1;
pv_len = tvb_get_ntohs(tvb, newoffset);
proto_tree_add_item(t, hf_hip_tlv_dh_pv_length, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_dh_pub, tvb, newoffset,
pv_len, ENC_NA);
}
break;
case PARAM_ESP_TRANSFORM:
proto_tree_add_item(t, hf_hip_tlv_esp_reserved, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset +=2;
tlv_len -= 2;
while (tlv_len > 0) {
trans = tvb_get_ntohs(tvb, newoffset);
proto_tree_add_uint_format(t, hf_hip_tlv_trans_id, tvb,
newoffset, 2, trans, "%u (%s)", trans,
val_to_str_const(trans, transform_id_vals, "Unknown"));
tlv_len -= 2;
newoffset += 2;
}
break;
case PARAM_HIP_TRANSFORM:
while (tlv_len > 0) {
trans = tvb_get_ntohs(tvb, newoffset);
proto_tree_add_uint_format(t, hf_hip_tlv_trans_id, tvb,
newoffset, 2, trans, "%u (%s)", trans,
val_to_str_const(trans, transform_id_vals, "Unknown"));
tlv_len -= 2;
newoffset += 2;
}
break;
case PARAM_NAT_TRAVERSAL_MODE:
proto_tree_add_item(t, hf_hip_tlv_esp_reserved, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
tlv_len -= 2;
while (tlv_len > 0) {
trans = tvb_get_ntohs(tvb, newoffset);
proto_tree_add_uint_format(t, hf_hip_tlv_nat_traversal_mode_id, tvb,
newoffset, 2, trans, "%u (%s)", trans,
val_to_str_const(trans, mode_id_vals, "Unknown"));
tlv_len -= 2;
newoffset += 2;
}
break;
case PARAM_TRANSACTION_PACING:
proto_tree_add_item(t, hf_hip_tlv_transaction_minta, tvb, newoffset, 4, ENC_BIG_ENDIAN);
break;
case PARAM_ENCRYPTED:
proto_tree_add_item(t, hf_hip_tlv_enc_reserved, tvb, newoffset, 4, ENC_BIG_ENDIAN);
newoffset += 4;
proto_tree_add_item(t, hf_hip_encrypted_parameter_data, tvb, newoffset, tlv_len - 4, ENC_NA);
break;
case PARAM_HIP_CIPHER:
while (tlv_len > 0) {
proto_tree_add_item(t, hf_hip_tlv_cipher_id, tvb, newoffset, 2, ENC_BIG_ENDIAN);
tlv_len -= 2;
newoffset += 2;
}
break;
case PARAM_HIT_SUITE_LIST:
while (tlv_len > 0) {
proto_tree_add_item(t, hf_hip_tlv_hit_suite_id, tvb, newoffset, 1, ENC_BIG_ENDIAN);
tlv_len -= 1;
newoffset += 1;
}
break;
case PARAM_HOST_ID:
hi_len = tvb_get_ntohs(tvb, newoffset);
hi_len_item = proto_tree_add_item(t, hf_hip_tlv_host_id_len, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
di_len = tvb_get_ntohs(tvb, newoffset);
di_type = (di_len >> 12) & 0x000F;
di_len = di_len & 0x0FFF;
proto_tree_add_item(t, hf_hip_tlv_host_di_type, tvb, newoffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(t, hf_hip_tlv_host_di_len, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
hi_hdr = tvb_get_ntohl(tvb, newoffset);
ti_tlv = proto_tree_add_item(t, hf_hip_tlv_host_id_hdr,
tvb, newoffset, 4, ENC_BIG_ENDIAN);
ti_tlv = proto_item_add_subtree(ti_tlv, ett_hip_tlv_host_id_hdr);
proto_tree_add_uint(ti_tlv, hf_hip_tlv_host_id_hdr_flags, tvb,
newoffset, 2, hi_hdr);
newoffset += 2;
proto_tree_add_uint(ti_tlv, hf_hip_tlv_host_id_hdr_proto, tvb,
newoffset, 1, hi_hdr);
newoffset += 1;
algorithm = tvb_get_guint8(tvb, newoffset);
arg_item = proto_tree_add_uint(ti_tlv, hf_hip_tlv_host_id_hdr_alg, tvb,
newoffset, 1, hi_hdr);
switch (algorithm) {
case HI_ALG_DSA:
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_host_id_t, tvb, newoffset, 1, ENC_BIG_ENDIAN);
hi_t = tvb_get_guint8(tvb, newoffset);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_host_id_q, tvb, newoffset,
20, ENC_NA);
newoffset += 20;
if (hi_t > 56)
break;
newlen = 64 + (hi_t * 8);
proto_tree_add_item(t, hf_hip_tlv_host_id_p, tvb, newoffset,
newlen, ENC_NA);
newoffset += newlen;
proto_tree_add_item(t, hf_hip_tlv_host_id_g, tvb, newoffset,
newlen, ENC_NA);
newoffset += newlen;
proto_tree_add_item(t, hf_hip_tlv_host_id_y, tvb, newoffset,
newlen, ENC_NA);
break;
case HI_ALG_RSA:
newoffset++;
e_len = tvb_get_guint8(tvb, newoffset);
e_len_item = proto_tree_add_item(t, hf_hip_tlv_host_id_e_len, tvb, newoffset,
(e_len > 255) ? 3 : 1, ENC_BIG_ENDIAN);
newoffset++;
hi_len -= 5;
if (e_len == 0) {
e_len = tvb_get_ntohs(tvb, newoffset);
newoffset += 2;
hi_len -= 2;
}
if (e_len > 512) {
expert_add_info(pinfo, e_len_item, &ei_hip_tlv_host_id_len);
break;
}
proto_tree_add_item(t, hf_hip_tlv_host_id_e, tvb, newoffset,
e_len, ENC_NA);
newoffset += e_len;
hi_len -= e_len;
if (hi_len > 512) {
expert_add_info(pinfo, hi_len_item, &ei_hip_tlv_host_id_len);
break;
}
proto_tree_add_item(t, hf_hip_tlv_host_id_n, tvb, newoffset,
hi_len, ENC_NA);
break;
default:
expert_add_info(pinfo, arg_item, &ei_hip_tlv_host_id_hdr_alg);
break;
}
if (di_type == 0)
break;
if (di_type == 1) {
proto_tree_add_item(t, hf_hip_fqdn, tvb, offset+16+hi_len, di_len, ENC_ASCII|ENC_NA);
} else if (di_type == 2) {
proto_tree_add_item(t, hf_hip_nai, tvb, offset+16+hi_len, di_len, ENC_ASCII|ENC_NA);
}
break;
case PARAM_CERT:
proto_tree_add_item(t, hf_hip_tlv_cert_group, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_cert_count, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_cert_id, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_cert_type, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_certificate, tvb, newoffset,
tlv_len-4, ENC_NA);
break;
case PARAM_NOTIFICATION:
proto_tree_add_item(t, hf_hip_tlv_notification_res, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_notification_type, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_notification_data, tvb, newoffset,
tlv_len-4, ENC_NA);
break;
case PARAM_ECHO_REQUEST_SIGNED:
case PARAM_ECHO_RESPONSE_SIGNED:
case PARAM_ECHO_REQUEST_UNSIGNED:
case PARAM_ECHO_RESPONSE_UNSIGNED:
proto_tree_add_item(t, hf_hip_tlv_opaque_data, tvb, newoffset,
tlv_len, ENC_NA);
break;
case PARAM_REG_INFO:
case PARAM_REG_REQUEST:
case PARAM_REG_RESPONSE:
case PARAM_REG_FAILED:
if (type == PARAM_REG_INFO) {
proto_tree_add_item(t, hf_hip_tlv_reg_ltmin, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_reg_ltmax, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
tlv_len -= 2;
} else if (type == PARAM_REG_FAILED) {
proto_tree_add_item(t, hf_hip_tlv_reg_failtype, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
tlv_len--;
} else {
proto_tree_add_item(t, hf_hip_tlv_reg_lt, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset++;
tlv_len--;
}
while (tlv_len > 0) {
reg_type = tvb_get_guint8(tvb, newoffset);
proto_tree_add_uint_format(t, hf_hip_tlv_reg_type, tvb,
newoffset, 1, reg_type, "%u (%s)", reg_type,
val_to_str_const(reg_type, reg_type_vals, "Unknown"));
tlv_len--;
newoffset++;
}
break;
case PARAM_HMAC:
case PARAM_HMAC_2:
case PARAM_RVS_HMAC:
case PARAM_RELAY_HMAC:
proto_tree_add_item(t, hf_hip_tlv_hmac, tvb, offset+4,
tlv_len, ENC_NA);
break;
case PARAM_HIP_SIGNATURE:
case PARAM_HIP_SIGNATURE_2:
n = tvb_get_guint8(tvb, offset+4);
proto_tree_add_uint_format(t, hf_hip_tlv_sig_alg, tvb, newoffset, 1,
n, "%u (%s)", n,
val_to_str_const(n, sig_alg_vals, "Unknown"));
newoffset++;
proto_tree_add_item(t, hf_hip_tlv_sig, tvb, newoffset, tlv_len-1,
ENC_NA);
break;
case PARAM_FROM:
proto_tree_add_item(t, hf_hip_tlv_from_address, tvb, newoffset, 16, ENC_NA);
break;
case PARAM_VIA_RVS:
while (tlv_len > 0) {
proto_tree_add_item(t, hf_hip_tlv_rvs_address, tvb, newoffset, 16, ENC_NA);
tlv_len -= 16;
newoffset += 16;
}
break;
case PARAM_RELAY_FROM:
proto_tree_add_item(t, hf_hip_tlv_relay_from_port, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_relay_from_protocol, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_relay_from_reserved, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_relay_from_address, tvb, newoffset, 16, ENC_NA);
break;
case PARAM_RELAY_TO:
proto_tree_add_item(t, hf_hip_tlv_relay_to_port, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_relay_to_protocol, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_relay_to_reserved, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_relay_to_address, tvb, newoffset, 16, ENC_NA);
break;
case PARAM_REG_FROM:
proto_tree_add_item(t, hf_hip_tlv_reg_from_port, tvb, newoffset, 2, ENC_BIG_ENDIAN);
newoffset += 2;
proto_tree_add_item(t, hf_hip_tlv_reg_from_protocol, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_reg_from_reserved, tvb, newoffset, 1, ENC_BIG_ENDIAN);
newoffset += 1;
proto_tree_add_item(t, hf_hip_tlv_reg_from_address, tvb, newoffset, 16, ENC_NA);
break;
default:
break;
}
return (0);
}
void
proto_register_hip(void)
{
static hf_register_info hf[] = {
{ &hf_hip_proto,
{ "Payload Protocol", "hip.proto",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_hdr_len,
{ "Header Length", "hip.hdr_len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_packet_type,
{ "Packet Type", "hip.packet_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_shim6_fixed_bit_p,
{ "Header fixed bit P", "hip.shim6_fixed_p",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_version,
{ "Version", "hip.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_shim6_fixed_bit_s,
{ "Header fixed bit S", "hip.shim6_fixed_s",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_controls,
{ "HIP Controls", "hip.controls",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_controls_anon,
{ "Anonymous (Sender's HI is anonymous)", "hip.controls.a",
FT_BOOLEAN, 16, NULL, HIP_CONTROL_A_MASK, NULL, HFILL }},
{ &hf_hip_checksum,
{ "Checksum", "hip.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_hit_sndr,
{ "Sender's HIT", "hip.hit_sndr",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_hit_rcvr,
{ "Receiver's HIT", "hip.hit_rcvr",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_type,
{ "Type", "hip.type",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_r1_res,
{ "Reserved", "hip.tlv.r1_reserved",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_r1count,
{ "R1 Counter", "hip.tlv.r1_counter",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_puzzle_k,
{ "Difficulty (K)", "hip.tlv_puzzle_k",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_puzzle_life,
{ "Lifetime", "hip.tlv_puzzle_lifetime",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_puzzle_o,
{ "Opaque Data", "hip.tlv_puzzle_opaque",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_puzzle_i,
{ "Random number (I)", "hip.tlv.puzzle_random_i",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_solution_k,
{ "Difficulty (K)", "hip.tlv_solution_k",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_solution_reserved,
{ "Reserved", "hip.tlv_solution_reserved",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_solution_o,
{ "Opaque Data", "hip.tlv_solution_opaque",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_solution_i,
{ "Random number (I)", "hip.tlv.solution_random_i",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_solution_j,
{ "Solution (J)", "hip.tlv_solution_j",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_ei_res,
{ "Reserved", "hip.tlv_esp_info_reserved",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_ei_keyidx,
{ "Keymaterial Index", "hip.tlv_esp_info_key_index",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_ei_oldspi,
{ "Old SPI", "hip.tlv_esp_info_old_spi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_ei_newspi,
{ "New SPI", "hip.tlv_esp_info_new_spi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_seq_updid,
{ "Seq Update ID", "hip.tlv_seq_update_id",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_ack_updid,
{ "ACKed Peer Update ID", "hip.tlv_ack_updid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_dh_group_id,
{ "Group ID", "hip.tlv.dh_group_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_dh_pv_length,
{ "Public Value Length", "hip.tlv.dh_pv_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_dh_pub,
{ "Public Value", "hip.tlv.dh_public_value",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_trans_id,
{ "Transform ID", "hip.tlv.trans_id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_esp_reserved,
{ "Reserved", "hip.tlv.esp_trans_res",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_cipher_id,
{ "Cipher ID", "hip.tlv.cipher_id",
FT_UINT16, BASE_DEC, VALS(cipher_vals), 0x0, NULL, HFILL }},
{ &hf_hip_tlv_hit_suite_id,
{ "HIT Suite ID", "hip.tlv.hit_suite_id",
FT_UINT8, BASE_DEC, VALS(hit_suite_vals), 0xF0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_len,
{ "Host Identity Length", "hip.tlv.host_id_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_di_type,
{ "Domain Identifier Type", "hip.tlv.host_domain_id_type",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL }},
{ &hf_hip_tlv_host_di_len,
{ "Domain Identifier Length", "hip.tlv.host_domain_id_length",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_hip_tlv_host_id_hdr,
{ "Host Identity flags", "hip.tlv.host_id_hdr",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_hdr_flags,
{ "Host Identity Header Flags", "hip.tlv.host_id_header_flags",
FT_UINT32, BASE_HEX, VALS(hi_hdr_flags_vals),
HI_HDR_FLAGS_MASK, NULL, HFILL }},
{ &hf_hip_tlv_host_id_hdr_proto,
{ "Host Identity Header Protocol", "hip.tlv.host_id_header_proto",
FT_UINT32, BASE_HEX, VALS(hi_hdr_proto_vals),
HI_HDR_PROTO_MASK, NULL, HFILL }},
{ &hf_hip_tlv_host_id_hdr_alg,
{ "Host Identity Header Algorithm", "hip.tlv.host_id_header_algo",
FT_UINT32, BASE_HEX, VALS(hi_hdr_alg_vals),
HI_HDR_ALG_MASK, NULL, HFILL }},
{ &hf_hip_tlv_host_id_t,
{ "Host Identity T", "hip.tlv.host_identity_t",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_q,
{ "Host Identity Q", "hip.tlv.host_identity_q",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_p,
{ "Host Identity P", "hip.tlv.host_id_p",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_g,
{ "Host Identity G", "hip.tlv.host_id_g",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_y,
{ "Host Identity Y (public value)", "hip.tlv.host_id_y",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_e_len,
{ "RSA Host Identity exponent length (e_len)", "hip.tlv.host_id_e_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_e,
{ "RSA Host Identity exponent (e)", "hip.tlv.host_id_e",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_host_id_n,
{ "RSA Host Identity public modulus (n)", "hip.tlv.host_id_n",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_notification_res,
{ "Notification Reserved", "hip.tlv.notification_res",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_notification_type,
{ "Notification Message Type", "hip.tlv.notification_type",
FT_UINT16, BASE_DEC, VALS(notification_vals), 0xFFFF, NULL, HFILL }},
{ &hf_hip_tlv_notification_data,
{ "Notification Data", "hip.tlv.notification_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_opaque_data,
{ "Opaque Data", "hip.tlv.opaque_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_ltmin,
{ "Minimum Registration Lifetime", "hip.tlv.reg_ltmin",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_ltmax,
{ "Maximum Registration Lifetime", "hip.tlv.reg_ltmax",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_lt,
{ "Registration Lifetime", "hip.tlv.reg_lt",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_type,
{ "Registration Type", "hip.tlv.reg_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_failtype,
{ "Registration Failure Type", "hip.tlv.reg_failtype",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_hmac,
{ "HMAC", "hip.tlv.hmac",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_sig_alg,
{ "Signature Algorithm", "hip.tlv.sig_alg",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_sig,
{ "Signature", "hip.tlv.sig",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_enc_reserved,
{ "Reserved", "hip.tlv.enc_reserved",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_traffic_type,
{ "Traffic Type", "hip.tlv.locator_traffic_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_type,
{ "Locator Type", "hip.tlv.locator_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_len,
{ "Locator Length", "hip.tlv.locator_len",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_reserved,
{ "Reserved", "hip.tlv.locator_reserved",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_lifetime,
{ "Locator Lifetime", "hip.tlv.locator_lifetime",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_port,
{ "Locator port", "hip.tlv.locator_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_transport_protocol,
{ "Locator transport protocol", "hip.tlv.locator_transport_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_kind,
{ "Locator kind", "hip.tlv.locator_kind",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_priority,
{ "Locator priority", "hip.tlv.locator_priority",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_spi,
{ "Locator SPI", "hip.tlv.locator_spi",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_locator_address,
{ "Locator" , "hip.tlv.locator_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_cert_group,
{ "Cert group", "hip.tlv.cert_group",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_cert_count,
{ "Cert count", "hip.tlv.cert_count",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_cert_id,
{ "Cert ID", "hip.tlv.cert_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_cert_type,
{ "Cert type", "hip.tlv.cert_type",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_certificate,
{ "Certificate", "hip.tlv.certificate",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_nat_traversal_mode_id,
{ "NAT Traversal Mode ID", "hip.tlv.nat_traversal_mode_id",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_from_port,
{ "Relay From Port", "hip.tlv.relay_from_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_to_port,
{ "Relay To Port", "hip.tlv.relay_to_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_from_port,
{ "Port", "hip.tlv.reg_from_port",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_transaction_minta,
{ "Min Ta" , "hip.tlv_transaction_minta",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_from_address,
{ "Address" , "hip.tlv_from_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_rvs_address,
{ "RVS Address" , "hip.tlv_rvs_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_from_protocol,
{ "Protocol" , "hip.tlv_relay_from_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_from_reserved,
{ "Reserved" , "hip.tlv_relay_from_reserved",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_from_address,
{ "Address" , "hip.tlv_relay_from_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_to_protocol,
{ "Protocol" , "hip.tlv_relay_to_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_to_reserved,
{ "Reserved" , "hip.tlv_relay_to_reserved",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_relay_to_address,
{ "Address" , "hip.tlv_relay_to_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_from_protocol,
{ "Protocol" , "hip.tlv_reg_from_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_from_reserved,
{ "Reserved" , "hip.tlv_reg_from_reserved",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_tlv_reg_from_address,
{ "Address" , "hip.tlv_reg_from_address",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_encrypted_parameter_data,
{ "Encrypted Parameter Data" , "hip.encrypted_parameter_data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_fqdn,
{ "FQDN" , "hip.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_hip_nai,
{ "NAI" , "hip.nai",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_hip,
&ett_hip_controls,
&ett_hip_tlv,
&ett_hip_tlv_data,
&ett_hip_tlv_host_id_hdr,
&ett_hip_locator_data,
};
static ei_register_info ei[] = {
{ &ei_hip_tlv_host_id_len, { "hip.tlv.host_id_length.invalid", PI_PROTOCOL, PI_WARN, "Invalid HI length", EXPFILL }},
#if 0
{ &ei_hip_tlv_host_id_e_len, { "hip.tlv.host_id_e_length.invalid", PI_PROTOCOL, PI_WARN, "e_len too large", EXPFILL }},
#endif
{ &ei_hip_tlv_host_id_hdr_alg, { "hip.tlv.host_id_header_algo.invalid", PI_PROTOCOL, PI_WARN, "Unknown algorithm type", EXPFILL }},
};
expert_module_t* expert_hip;
proto_hip = proto_register_protocol("Host Identity Protocol", "HIP", "hip");
proto_register_field_array(proto_hip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_hip = expert_register_protocol(proto_hip);
expert_register_field_array(expert_hip, ei, array_length(ei));
}
void
proto_reg_handoff_hip(void)
{
dissector_handle_t hip_handle;
dissector_handle_t hip_handle2;
hip_handle = create_dissector_handle(dissect_hip, proto_hip);
dissector_add_uint("ip.proto", IP_PROTO_HIP, hip_handle);
hip_handle2 = create_dissector_handle(dissect_hip_in_udp, proto_hip);
dissector_add_uint("udp.port", 10500, hip_handle2);
}
