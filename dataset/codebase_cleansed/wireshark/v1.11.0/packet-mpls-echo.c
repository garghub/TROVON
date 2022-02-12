static void
dissect_mpls_echo_tlv_fec(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem)
{
proto_tree *ti, *tlv_fec_tree;
proto_item *hidden_item;
guint16 idx = 1, nil_idx = 1, type, saved_type;
int length, nil_length, pad;
guint32 label;
guint8 exp, bos, ttl;
while (rem >= 4) {
type = tvb_get_ntohs(tvb, offset);
saved_type = type;
if (type >= TLV_FEC_VENDOR_PRIVATE_START)
type = TLV_FEC_VENDOR_PRIVATE_START;
length = tvb_get_ntohs(tvb, offset + 2);
ti = NULL;
tlv_fec_tree = NULL;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, length + 4 + (4-(length%4)), "FEC Element %u: %s",
idx, val_to_str_ext(type, &mpls_echo_tlv_fec_names_ext,
"Unknown FEC type (0x%04X)"));
tlv_fec_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_fec);
proto_tree_add_uint_format_value(tlv_fec_tree, hf_mpls_echo_tlv_fec_type, tvb,
offset, 2, saved_type, "%s (%u)",
val_to_str_ext_const(type, &mpls_echo_tlv_fec_names_ext,
"Unknown sub-TLV type"), saved_type);
ti = proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_len, tvb, offset + 2,
2, ENC_BIG_ENDIAN);
}
if (length + 4 > rem) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length (claimed %u, found %u)",
length, rem - 4);
return;
}
switch (type) {
case TLV_FEC_STACK_LDP_IPv4:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_ldp_ipv4,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_ldp_ipv4_mask,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_LDP_IPv6:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_ldp_ipv6,
tvb, offset + 4, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_ldp_ipv6_mask,
tvb, offset + 20, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_RSVP_IPv4:
if (length != 20) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be %u)",
length, 20);
return;
}
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv4_ipv4_endpoint,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_mbz1,
tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_tunnel_id,
tvb, offset + 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv4_ext_tunnel_id,
tvb, offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv4_ipv4_sender,
tvb, offset + 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_mbz2,
tvb, offset + 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_lsp_id,
tvb, offset + 22, 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_RSVP_IPv6:
if (length != 56) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be %u)",
length, 56);
return;
}
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv6_ipv6_endpoint,
tvb, offset + 4, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_mbz1,
tvb, offset + 20, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_tunnel_id,
tvb, offset + 22, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv6_ext_tunnel_id,
tvb, offset + 24, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ipv6_ipv6_sender,
tvb, offset + 40, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_mbz2,
tvb, offset + 56, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_lsp_id,
tvb, offset + 58, 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_VPN_IPv4:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_route_dist,
tvb, offset + 4, 8, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_ipv4,
tvb, offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_len,
tvb, offset + 16, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_VPN_IPv6:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_route_dist,
tvb, offset + 4, 8, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_ipv6,
tvb, offset + 12, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_vpn_len,
tvb, offset + 28, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_L2_VPN:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2_vpn_route_dist,
tvb, offset + 4, 8, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2_vpn_send_ve_id,
tvb, offset + 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2_vpn_recv_ve_id,
tvb, offset + 14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2_vpn_encap_type,
tvb, offset + 16, 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_L2_CID_OLD:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_remote,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_vcid,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_encap,
tvb, offset + 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_mbz,
tvb, offset + 14, 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_L2_CID_NEW:
if (length < 14) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be %u)",
length, 14);
return;
}
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_sender,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_remote,
tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_vcid,
tvb, offset + 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_encap,
tvb, offset + 16, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_l2cid_mbz,
tvb, offset + 18, 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_VENDOR_PRIVATE_START:
if (length < 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be >= %u)",
length, 4);
} else {
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_vendor, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_value, tvb,
offset + 8, length - 4, ENC_NA);
}
}
break;
case TLV_FEC_STACK_BGP_LAB_v4:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_bgp_ipv4,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_bgp_len,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_BGP_LAB_v6:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_bgp_ipv6,
tvb, offset + 4, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_bgp_len,
tvb, offset + 20, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_GEN_IPv4:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_gen_ipv4,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_gen_ipv4_mask,
tvb, offset + 8, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_GEN_IPv6:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_gen_ipv6,
tvb, offset + 4, 16, ENC_NA);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_gen_ipv6_mask,
tvb, offset + 20, 1, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_NIL:
nil_length = length;
while (nil_length >= 4) {
decode_mpls_label(tvb, offset + 4, &label, &exp, &bos, &ttl);
if (label <= MPLS_LABEL_MAX_RESERVED) {
proto_tree_add_uint_format(tlv_fec_tree, hf_mpls_echo_tlv_fec_nil_label,
tvb, offset + 4, 3, label, "Label %u: %u (%s)", nil_idx, label,
val_to_str_const(label, special_labels, "Reserved - Unknown"));
} else {
proto_tree_add_uint_format(tlv_fec_tree, hf_mpls_echo_tlv_fec_nil_label,
tvb, offset + 4, 3, label, "Label %u: %u", nil_idx, label);
}
nil_length -= 4;
offset += 4;
nil_idx++;
}
break;
case TLV_FEC_STACK_P2MP_IPv4:
if (length != 20) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be %u)",
length, 20);
return;
}
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_p2mp_id,
tvb, offset + 4, 4, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_mbz1,
tvb, offset + 8, 2, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_tunnel_id,
tvb, offset + 10, 2, FALSE);
proto_tree_add_text(tlv_fec_tree, tvb, offset + 12, 4,
"Extended Tunnel ID: 0x%08X (%s)", tvb_get_ntohl(tvb, offset + 12),
tvb_ip_to_str(tvb, offset + 12));
hidden_item = proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_ext_tunnel_id,
tvb, offset + 12, 4, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_ipv4_sender,
tvb, offset + 16, 4, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_mbz2,
tvb, offset + 20, 2, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_lsp_id,
tvb, offset + 22, 2, FALSE);
}
break;
case TLV_FEC_STACK_P2MP_IPv6:
if (length != 56) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Length "
"(claimed %u, should be %u)",
length, 56);
return;
}
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_p2mp_id,
tvb, offset + 4, 16, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_mbz1,
tvb, offset + 20, 2, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_tunnel_id,
tvb, offset + 22, 2, FALSE);
proto_tree_add_text(tlv_fec_tree, tvb, offset + 24, 16, "Extended Tunnel ID: 0x%s (%s)",
tvb_bytes_to_str(tvb, offset + 24, 16),
tvb_ip6_to_str(tvb, offset + 24));
hidden_item = proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_ext_tunnel_id,
tvb, offset + 24, 16, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_ipv6_sender,
tvb, offset + 40, 16, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_ip_mbz2,
tvb, offset + 56, 2, FALSE);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_lsp_id,
tvb, offset + 58, 2, FALSE);
}
break;
case TLV_FEC_STACK_STATIC_LSP:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_src_gid,
tvb, (offset + 4), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_src_nid,
tvb, (offset + 8), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_src_tunnel_no,
tvb, (offset + 12), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_lsp_no,
tvb, (offset + 14), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_dst_gid,
tvb, (offset + 16), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_dst_nid,
tvb, (offset + 20), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_dst_tunnel_no,
tvb, (offset + 24), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_resv,
tvb, (offset + 26), 2, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_STATIC_PW:
if (tree) {
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_pw_serv_identifier,
tvb, (offset + 4), 8, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_src_gid,
tvb, (offset + 12), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_src_nid,
tvb, (offset + 16), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_pw_src_ac_id,
tvb, (offset + 20), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_dst_gid,
tvb, (offset + 24), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_dst_nid,
tvb, (offset + 28), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_lspping_tlv_pw_dst_ac_id,
tvb, (offset + 32), 4, ENC_BIG_ENDIAN);
}
break;
case TLV_FEC_STACK_RES:
default:
if (length)
proto_tree_add_item(tlv_fec_tree, hf_mpls_echo_tlv_fec_value,
tvb, offset + 4, length, ENC_NA);
break;
}
if (length % 4) {
pad = 4 - (length % 4);
if (length + 4 + pad > rem) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_fec_len,
"Invalid FEC Sub-TLV Padded Length (claimed %u, found %u)",
length + pad, rem - 4);
return;
} else {
proto_tree_add_text(tlv_fec_tree, tvb, offset + 4 + length, pad, "Padding");
}
length += pad;
}
rem -= 4 + length;
offset += 4 + length;
idx++;
}
}
static void
dissect_mpls_echo_tlv_ds_map(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem)
{
proto_tree *ti, *tlv_ds_map_tree;
proto_tree *addr_ti;
guint16 mplen, idx = 1;
guint32 label;
guint8 exp, bos, proto;
guint8 hash_type, addr_type;
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_mtu, tvb,
offset, 2, ENC_BIG_ENDIAN);
addr_ti = proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_addr_type, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_res, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
tlv_ds_map_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ds_map);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_flag_res, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_flag_i, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_flag_n, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
addr_type = tvb_get_guint8(tvb, offset + 2);
switch (addr_type) {
case TLV_ADDR_IPv4:
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_ds_ip, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_int_ip, tvb,
offset + 8, 4, ENC_BIG_ENDIAN);
break;
case TLV_ADDR_UNNUM_IPv4:
case TLV_ADDR_UNNUM_IPv6:
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_ds_ip, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_if_index, tvb,
offset + 8, 4, ENC_BIG_ENDIAN);
break;
case TLV_ADDR_IPv6:
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_ds_ipv6, tvb,
offset + 4, 16, ENC_NA);
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_int_ipv6, tvb,
offset + 20, 16, ENC_NA);
rem -= 24;
offset += 24;
break;
case TLV_ADDR_NONIP :
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_ingress_if_num, tvb,
(offset + 4), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_egress_if_num, tvb,
(offset + 8), 4, ENC_BIG_ENDIAN);
break;
default:
expert_add_info_format(pinfo, addr_ti, &ei_mpls_echo_unknown_address_type,
"Unknown Address Type (%u)", addr_type);
break;
}
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_hash_type, tvb,
offset + 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_depth, tvb,
offset + 13, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_muti_len, tvb,
offset + 14, 2, ENC_BIG_ENDIAN);
mplen = tvb_get_ntohs(tvb, offset + 14);
hash_type = tvb_get_guint8(tvb, offset + 12);
rem -= 16;
offset += 16;
if (rem < mplen) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_ds_map_muti_len,
"Invalid FEC Multipath (claimed %u, found %u)",
mplen, rem);
return;
}
rem -= mplen;
if (mplen) {
switch (hash_type) {
case TLV_DS_MAP_HASH_IP:
if (mplen != 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_ds_map_muti_len,
"Invalid FEC Multipath (claimed %u, should be 4)",
mplen);
break;
}
ti = proto_tree_add_text(tree, tvb, offset, 4,
"Multipath Information");
tlv_ds_map_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ds_map);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
break;
case TLV_DS_MAP_HASH_IP_RANGE:
if (mplen != 8) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_ds_map_muti_len,
"Invalid FEC Multipath (claimed %u, should be 8)",
mplen);
break;
}
ti = proto_tree_add_text(tree, tvb, offset, 8,
"Multipath Information");
tlv_ds_map_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ds_map);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_ip_low, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_ip_high, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
break;
case TLV_DS_MAP_HASH_NO_MP:
case TLV_DS_MAP_HASH_NO_LABEL:
case TLV_DS_MAP_HASH_ALL_IP:
case TLV_DS_MAP_HASH_NO_MATCH:
proto_tree_add_text(tree, tvb, offset, mplen,
"No Multipath Information");
break;
case TLV_DS_MAP_HASH_BITMASK_IP:
if (mplen < 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_ds_map_muti_len,
"Invalid FEC Multipath (claimed %u, should be 4)",
mplen);
break;
}
ti = proto_tree_add_text(tree, tvb, offset, mplen,
"Multipath Information");
tlv_ds_map_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ds_map);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_ip, tvb,
offset, 4, ENC_BIG_ENDIAN);
if (mplen > 4)
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_mask, tvb,
offset + 4, mplen - 4, ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_mpls_echo_tlv_ds_map_mp_value, tvb,
offset, mplen, ENC_NA);
break;
}
}
offset += mplen;
if (tree) {
while (rem >= 4) {
decode_mpls_label(tvb, offset, &label, &exp, &bos, &proto);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Downstream Label Element %u", idx);
tlv_ds_map_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ds_map);
proto_item_append_text(ti, ", Label: %u", label);
if (label <= MPLS_LABEL_MAX_RESERVED) {
proto_tree_add_uint(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_label,
tvb, offset, 3, label);
proto_item_append_text(ti, " (%s)", val_to_str_const(label, special_labels,
"Reserved - Unknown"));
} else {
proto_tree_add_uint_format_value(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_label,
tvb, offset, 3, label, "%u", label);
}
proto_item_append_text(ti, ", Exp: %u, BOS: %u", exp, bos);
proto_tree_add_uint(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_exp,
tvb, offset + 2, 1, exp);
proto_tree_add_uint(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_bos,
tvb, offset + 2, 1, bos);
proto_tree_add_item(tlv_ds_map_tree, hf_mpls_echo_tlv_ds_map_mp_proto,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Protocol: %u (%s)", proto,
val_to_str_const(proto, mpls_echo_tlv_ds_map_mp_proto, "Unknown"));
rem -= 4;
offset += 4;
idx++;
}
}
}
static void
dissect_mpls_echo_tlv_dd_map(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem)
{
proto_tree *ddti = NULL, *tlv_dd_map_tree, *tlv_ddstlv_map_tree;
proto_tree *ddsti, *ddsti2;
guint16 subtlv_length, subtlv_type, multipath_length;
guint8 addr_type, multipath_type, fec_tlv_length;
guint16 idx = 1;
guint32 label;
guint8 tc, s_bit, proto;
if (tree) {
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_mtu, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_addr_type, tvb,
offset + 2, 1, ENC_BIG_ENDIAN);
ddti = proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_res, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
tlv_dd_map_tree = proto_item_add_subtree(ddti, ett_mpls_echo_tlv_dd_map);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_flag_res, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_flag_i, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
ddti = proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_flag_n, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
}
addr_type = tvb_get_guint8(tvb, offset + 2);
switch (addr_type) {
case TLV_ADDR_IPv4:
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_ds_ip, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_int_ip, tvb,
offset + 8, 4, ENC_BIG_ENDIAN);
break;
case TLV_ADDR_IPv6:
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_ds_ipv6, tvb,
offset + 4, 16, ENC_NA);
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_int_ipv6, tvb,
offset + 20, 16, ENC_NA);
rem -= 24;
offset += 24;
break;
case TLV_ADDR_NONIP :
proto_tree_add_item (tree, hf_mpls_echo_tlv_dd_map_ingress_if_num, tvb,
(offset + 4), 4, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_mpls_echo_tlv_dd_map_egress_if_num, tvb,
(offset + 8), 4, ENC_BIG_ENDIAN);
break;
default:
expert_add_info_format(pinfo, ddti, &ei_mpls_echo_unknown_address_type,
"Unknown Address Type (%u)", addr_type);
break;
}
if (tree) {
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_return_code, tvb,
offset + 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_return_subcode, tvb,
offset + 13, 1, ENC_BIG_ENDIAN);
ddti = proto_tree_add_item(tree, hf_mpls_echo_tlv_dd_map_subtlv_len, tvb,
offset + 14, 2, ENC_BIG_ENDIAN);
}
rem -= 16;
offset += 16;
while (rem > 4) {
subtlv_type = tvb_get_ntohs(tvb, offset);
subtlv_length = tvb_get_ntohs(tvb, offset+2);
rem -= 4;
offset += 4;
if (rem<subtlv_length){
expert_add_info_format(pinfo, ddti, &ei_mpls_echo_tlv_dd_map_subtlv_len,
"Invalid Sub-tlv Length (claimed %u, found %u)",
subtlv_length, rem);
return;
}
switch (subtlv_type) {
case TLV_FEC_MULTIPATH_DATA:
multipath_type = tvb_get_guint8(tvb, offset);
multipath_length = tvb_get_ntohs(tvb, offset + 1);
ddsti = proto_tree_add_text(tree, tvb, offset - 4, multipath_length + 8,
"Multipath sub-TLV");
tlv_dd_map_tree = proto_item_add_subtree(ddsti, ett_mpls_echo_tlv_dd_map);
switch (multipath_type) {
case TLV_MULTIPATH_NO_MULTIPATH:
if (!tree)
break;
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_resv, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
ddsti2 = proto_tree_add_text(tlv_dd_map_tree, tvb, offset + 4, multipath_length,
"Empty (Multipath Length = 0)");
tlv_ddstlv_map_tree = proto_item_add_subtree(ddsti2, ett_mpls_echo_tlv_ddstlv_map);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_multipath_info,
tvb, offset + 4, multipath_length, ENC_BIG_ENDIAN);
break;
case TLV_MULTIPATH_IP_ADDRESS:
if (multipath_length != 4) {
expert_add_info_format(pinfo, ddsti, &ei_mpls_echo_tlv_dd_map_subtlv_len,
"Invalid Sub-tlv Length (claimed %u, should be 4)",
multipath_length);
break;
}
if (!tree)
break;
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_multipath_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_resv, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
ddsti2 = proto_tree_add_text(tlv_dd_map_tree, tvb, offset + 4, multipath_length,
"Multipath Information (IP addresses)");
tlv_ddstlv_map_tree = proto_item_add_subtree(ddsti2, ett_mpls_echo_tlv_ddstlv_map);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_multipath_ip, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
break;
case TLV_MULTIPATH_IP_ADDRESS_RANGE:
if (multipath_length != 8) {
expert_add_info_format(pinfo, ddsti, &ei_mpls_echo_tlv_dd_map_subtlv_len,
"Invalid Sub-tlv Length (claimed %u, should be 8)",
multipath_length);
break;
}
if (!tree)
break;
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_multipath_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_resv, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
ddsti2 = proto_tree_add_text(tlv_dd_map_tree, tvb, offset + 4, multipath_length,
"Multipath Information (low/high address pairs)");
tlv_ddstlv_map_tree = proto_item_add_subtree(ddsti2, ett_mpls_echo_tlv_ddstlv_map);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_mp_ip_low, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_mp_ip_high, tvb,
offset + 8, 4, ENC_BIG_ENDIAN);
break;
case TLV_MULTIPATH_BIT_MASKED_IP:
if (multipath_length < 4) {
expert_add_info_format(pinfo, ddsti, &ei_mpls_echo_tlv_dd_map_subtlv_len,
"Invalid Sub-tlv Length (claimed %u, should be >= 4)",
multipath_length);
break;
}
if (!tree)
break;
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_multipath_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_resv, tvb,
offset + 3, 1, ENC_BIG_ENDIAN);
ddsti2 = proto_tree_add_text(tlv_dd_map_tree, tvb, offset + 4, multipath_length,
"Multipath Information (IP address prefix and bit mask)");
tlv_ddstlv_map_tree = proto_item_add_subtree(ddsti2, ett_mpls_echo_tlv_ddstlv_map);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_multipath_ip, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
if (multipath_length > 4)
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_sub_tlv_mp_mask,
tvb, offset + 8, multipath_length - 4, ENC_NA);
break;
case TLV_MULTIPATH_BIT_MASKED_LABEL_SET:
proto_tree_add_text(tlv_dd_map_tree, tvb, offset, 1,
"Multipath Information (Label prefix and bit mask)");
break;
default:
if (!tree)
break;
proto_tree_add_text(tlv_dd_map_tree, tvb, offset, 1,
"Multipath Type not identified (%u)", multipath_type);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_multipath_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree,
hf_mpls_echo_sub_tlv_multipath_length, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_multipath_value, tvb,
offset + 3, rem, ENC_BIG_ENDIAN);
break;
}
rem -= (multipath_length + 4);
break;
case TLV_FEC_LABEL_STACK:
ddsti = proto_tree_add_text(tree, tvb, offset - 4, subtlv_length + 4, "Label stack sub-TLV");
tlv_dd_map_tree = proto_item_add_subtree(ddsti, ett_mpls_echo_tlv_dd_map);
while (rem >= 4) {
if (tree) {
decode_mpls_label(tvb, offset, &label, &tc, &s_bit, &proto);
ddsti2 = proto_tree_add_text(tlv_dd_map_tree,
tvb, offset, 4, "Downstream Label Element %u", idx);
tlv_ddstlv_map_tree = proto_item_add_subtree(ddsti2, ett_mpls_echo_tlv_ddstlv_map);
proto_item_append_text(ddsti2, ", Label: %u , Protocol: %u", label, proto);
proto_tree_add_text(tlv_ddstlv_map_tree, tvb, offset, 3, "Label: %u", label);
proto_tree_add_text(tlv_ddstlv_map_tree, tvb, offset + 2, 1, "Traffic Class: %u", tc);
proto_tree_add_text(tlv_ddstlv_map_tree, tvb, offset + 2, 1, "S bit: %u", s_bit);
proto_tree_add_item(tlv_ddstlv_map_tree, hf_mpls_echo_tlv_ddstlv_map_mp_proto,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
rem -= 4;
offset += 4;
idx++;
}
break;
case TLV_FEC_STACK_CHANGE: {
addr_type = tvb_get_guint8(tvb, offset + 1);
fec_tlv_length = tvb_get_guint8(tvb, offset + 2);
ddsti = proto_tree_add_text(tree, tvb, offset - 4, fec_tlv_length + 12, "Stack change sub-TLV");
tlv_dd_map_tree = proto_item_add_subtree(ddsti, ett_mpls_echo_tlv_dd_map);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_op_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_addr_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_fec_tlv_value, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_res, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
switch (addr_type) {
case SUB_TLV_FEC_UNSPECIFIED:
proto_tree_add_text(tlv_dd_map_tree, tvb, offset + 4, 0, "Unspecified (Address Length = 0)");
rem += 4;
offset -= 4;
break;
case SUB_TLV_FEC_IPV4:
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_remote_peer_ip, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case SUB_TLV_FEC_IPV6:
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_sub_tlv_remore_peer_ipv6, tvb, offset + 4, 16, ENC_NA);
rem -= 12;
offset += 12;
break;
}
offset -= 8;
dissect_mpls_echo_tlv_fec(tvb, pinfo, offset, tlv_dd_map_tree, fec_tlv_length);
rem -= (fec_tlv_length + 8);
break;
}
default:
ddsti = proto_tree_add_text(tree, tvb, offset, subtlv_length, "Error processing sub-TLV");
tlv_dd_map_tree = proto_item_add_subtree(ddsti, ett_mpls_echo_tlv_dd_map);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_type, tvb, offset - 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_length, tvb, offset - 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_dd_map_tree, hf_mpls_echo_tlv_dd_map_value, tvb, offset, subtlv_length, ENC_BIG_ENDIAN);
rem -= subtlv_length;
break;
}
}
}
static void
dissect_mpls_echo_tlv_ilso(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem, gboolean is_ipv6)
{
proto_tree *ti;
guint8 type;
guint16 idx = 1;
guint32 label;
guint8 exp, bos, ttl;
ti = proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, offset);
offset += 1;
rem -= 1;
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_mbz, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
rem -= 3;
if ((type == TLV_ADDR_IPv4) || (type == TLV_ADDR_UNNUM_IPv4)) {
if (is_ipv6) {
expert_add_info(pinfo, ti, &ei_mpls_echo_incorrect_address_type);
}
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_ipv4_addr, tvb,
offset, 4, ENC_BIG_ENDIAN);
if (type == TLV_ADDR_IPv4) {
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_ipv4_int_addr, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_int_index, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
}
offset += 8;
rem -= 8;
} else if ((type == TLV_ADDR_IPv6) || (type == TLV_ADDR_UNNUM_IPv6)) {
if (!is_ipv6) {
expert_add_info(pinfo, ti, &ei_mpls_echo_incorrect_address_type);
}
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_ipv6_addr, tvb,
offset, 16, ENC_NA);
if (type == TLV_ADDR_IPv6) {
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_ipv6_int_addr, tvb,
offset + 16, 16, ENC_NA);
offset += 32;
rem -= 32;
} else {
proto_tree_add_item(tree, hf_mpls_echo_tlv_ilso_int_index, tvb,
offset + 16, 4, ENC_BIG_ENDIAN);
offset += 20;
rem -= 20;
}
} else {
expert_add_info(pinfo, ti, &ei_mpls_echo_incorrect_address_type);
return;
}
if (tree) {
while (rem >= 4) {
proto_tree *tlv_ilso;
decode_mpls_label(tvb, offset, &label, &exp, &bos, &ttl);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Label Stack Element %u", idx);
tlv_ilso = proto_item_add_subtree(ti, ett_mpls_echo_tlv_ilso);
proto_item_append_text(ti, ", Label: %u", label);
if (label <= MPLS_LABEL_MAX_RESERVED) {
proto_tree_add_uint_format_value(tlv_ilso, hf_mpls_echo_tlv_ilso_label,
tvb, offset, 3, label, "%u (%s)", label,
val_to_str_const(label, special_labels, "Reserved - Unknown"));
proto_item_append_text(ti, " (%s)", val_to_str_const(label, special_labels,
"Reserved - Unknown"));
} else {
proto_tree_add_uint_format_value(tlv_ilso, hf_mpls_echo_tlv_ilso_label,
tvb, offset, 3, label, "%u", label);
}
proto_item_append_text(ti, ", Exp: %u, BOS: %u, TTL: %u",
exp, bos, ttl);
proto_tree_add_uint(tlv_ilso, hf_mpls_echo_tlv_ilso_exp,
tvb, offset + 2, 1, exp);
proto_tree_add_uint(tlv_ilso, hf_mpls_echo_tlv_ilso_bos,
tvb, offset + 2, 1, bos);
proto_tree_add_item(tlv_ilso, hf_mpls_echo_tlv_ilso_ttl,
tvb, offset + 3, 1, ENC_BIG_ENDIAN);
rem -= 4;
offset += 4;
idx++;
}
}
}
static void
dissect_mpls_echo_tlv_errored(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem)
{
int errored_tlv_length;
while (rem >= 4) {
errored_tlv_length = dissect_mpls_echo_tlv(tvb, pinfo, offset, tree, rem, TRUE);
rem -= errored_tlv_length;
offset += errored_tlv_length;
}
}
static int
dissect_mpls_echo_tlv(tvbuff_t *tvb, packet_info *pinfo, guint offset, proto_tree *tree, int rem, gboolean in_errored)
{
proto_tree *ti = NULL, *mpls_echo_tlv_tree = NULL;
guint16 type, saved_type;
int length;
length = tvb_reported_length_remaining(tvb, offset);
rem = MIN(rem, length);
if ( rem < 4 ) {
if (tree)
proto_tree_add_text(tree, tvb, offset, rem,
"Error processing TLV: length is %d, should be >= 4",
rem);
return rem;
}
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
rem -= 4;
length = MIN(length, rem);
saved_type = type;
if (type >= TLV_VENDOR_PRIVATE_START)
type = TLV_VENDOR_PRIVATE_START;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, length + 4, "%s%s",
in_errored ? "Errored TLV Type: " : "",
val_to_str_ext(type, &mpls_echo_tlv_type_names_ext, "Unknown TLV type (0x%04X)"));
mpls_echo_tlv_tree = proto_item_add_subtree(ti, ett_mpls_echo_tlv);
if (in_errored) {
proto_tree_add_uint_format_value(mpls_echo_tlv_tree, hf_mpls_echo_tlv_errored_type, tvb,
offset, 2, saved_type, "%s (%u)",
val_to_str_ext_const(type, &mpls_echo_tlv_type_names_ext,
"Unknown TLV type"), saved_type);
} else {
proto_tree_add_uint_format_value(mpls_echo_tlv_tree, hf_mpls_echo_tlv_type, tvb,
offset, 2, saved_type, "%s (%u)",
val_to_str_ext_const(type, &mpls_echo_tlv_type_names_ext,
"Unknown TLV type"), saved_type);
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_len, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
if (length == 0)
return 4;
switch (type) {
case TLV_TARGET_FEC_STACK:
dissect_mpls_echo_tlv_fec(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length);
break;
case TLV_PAD:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_padaction, tvb,
offset + 4, 1, ENC_BIG_ENDIAN);
if (length > 1)
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_padding, tvb,
offset + 5, length - 1, ENC_NA);
break;
case TLV_VENDOR_CODE:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_vendor, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
break;
case TLV_ILSO_IPv4:
if (length < 12) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be >= 12)",
length);
break;
}
dissect_mpls_echo_tlv_ilso(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length, FALSE);
break;
case TLV_ILSO_IPv6:
if (length < 24) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be >= 24)",
length);
break;
}
dissect_mpls_echo_tlv_ilso(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length, TRUE);
break;
#if 0
case TLV_RTO_IPv4:
if (length != 4) {
proto_tree_add_text(mpls_echo_tlv_tree, tvb, offset + 4, length,
"Error processing TLV: length is %d, should be 4",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_rto_ipv4,
tvb, offset + 4, 4, ENC_BIG_ENDIAN);
break;
case TLV_RTO_IPv6:
if (length != 16) {
proto_tree_add_text(mpls_echo_tlv_tree, tvb, offset + 4, length,
"Error processing TLV: length is %d, should be 16",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_rto_ipv6,
tvb, offset + 4, 16, ENC_NA);
break;
#endif
case TLV_P2MP_ECHO_JITTER:
if (length != 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be 4)",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_echo_jitter,
tvb, offset + 4, 4, FALSE);
break;
case TLV_P2MP_RESPONDER_IDENT: {
guint16 resp_ident_type, resp_ident_len;
proto_item *hidden_item;
resp_ident_type = tvb_get_ntohs(tvb, offset + 4);
resp_ident_len = tvb_get_ntohs(tvb, offset + 6);
switch (resp_ident_type) {
case TLV_P2MP_RESPONDER_IDENT_IPV4_EGRESS_ADDR:
case TLV_P2MP_RESPONDER_IDENT_IPV4_NODE_ADDR:
if (resp_ident_len != 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be 4)",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_responder_indent_type,
tvb, offset + 4, 2, FALSE);
hidden_item = proto_tree_add_item(mpls_echo_tlv_tree,
hf_mpls_echo_tlv_responder_indent_len, tvb,
offset + 6, 2, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_responder_indent_ipv4,
tvb, offset + 8, 4, FALSE);
break;
case TLV_P2MP_RESPONDER_IDENT_IPV6_EGRESS_ADDR:
case TLV_P2MP_RESPONDER_IDENT_IPV6_NODE_ADDR:
if (resp_ident_len != 16) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be 16)",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_responder_indent_type,
tvb, offset + 4, 2, FALSE);
hidden_item = proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_responder_indent_len,
tvb, offset + 6, 2, FALSE);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_responder_indent_ipv4,
tvb, offset + 8, 16, FALSE);
break;
}
break;
}
case TLV_VENDOR_PRIVATE_START:
if (length < 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be >= 4)",
length);
} else {
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_vendor, tvb,
offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_value, tvb,
offset + 8, length - 4, ENC_NA);
}
break;
case TLV_DOWNSTREAM_MAPPING:
if (length < 16) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be >= 16)",
length);
break;
}
dissect_mpls_echo_tlv_ds_map(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length);
break;
case TLV_DETAILED_DOWNSTREAM:
if (length < 16) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be >= 16)",
length);
break;
}
dissect_mpls_echo_tlv_dd_map(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length);
break;
case TLV_ERRORED_TLV:
if (in_errored)
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_value, tvb,
offset + 4, length, ENC_NA);
else
dissect_mpls_echo_tlv_errored(tvb, pinfo, offset + 4, mpls_echo_tlv_tree, length);
break;
case TLV_REPLY_TOS:
if (length != 4) {
expert_add_info_format(pinfo, ti, &ei_mpls_echo_tlv_len,
"Invalid TLV Length (claimed %u, should be 4)",
length);
break;
}
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_reply_tos, tvb,
offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_reply_tos_mbz, tvb,
offset + 5, 3, ENC_BIG_ENDIAN);
break;
case TLV_SRC_IDENTIFIER:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_lspping_tlv_src_addr_gid,
tvb, (offset + 4), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_lspping_tlv_src_addr_nid,
tvb, (offset + 8), 4, ENC_BIG_ENDIAN);
break;
case TLV_DST_IDENTIFIER:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_lspping_tlv_src_addr_gid,
tvb, (offset + 4), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_lspping_tlv_src_addr_nid,
tvb, (offset + 8), 4, ENC_BIG_ENDIAN);
break;
case TLV_BFD_DISCRIMINATOR:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_bfd,
tvb, (offset + 4), 4, ENC_BIG_ENDIAN);
break;
case TLV_REVERSE_PATH_FEC_STACK:
dissect_mpls_echo_tlv_fec (tvb, pinfo, (offset + 4), mpls_echo_tlv_tree, length);
break ;
case TLV_ERROR_CODE:
default:
proto_tree_add_item(mpls_echo_tlv_tree, hf_mpls_echo_tlv_value, tvb,
offset + 4, length, ENC_NA);
break;
}
return length + 4;
}
int
dissect_mpls_echo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int offset = 0, rem = 0, len;
proto_item *ti = NULL;
proto_tree *mpls_echo_tree = NULL;
guint8 msgtype;
if (tvb_length(tvb) < 5) {
return 0;
}
if (tvb_get_ntohs(tvb, 0) != 1) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPLS ECHO");
col_clear(pinfo->cinfo, COL_INFO);
rem = tvb_reported_length_remaining(tvb, offset);
msgtype = tvb_get_guint8(tvb, offset + 4);
if ( ((!MSGTYPE_MPLS_ECHO(msgtype)) && (rem < 16)) ||
((MSGTYPE_MPLS_ECHO(msgtype)) && (rem < 32)) ) {
col_set_str(pinfo->cinfo, COL_INFO, "Malformed Message");
if (tree) {
ti = proto_tree_add_item(tree, proto_mpls_echo, tvb, 0, -1, ENC_NA);
mpls_echo_tree = proto_item_add_subtree(ti, ett_mpls_echo);
proto_tree_add_text(mpls_echo_tree, tvb, offset, rem,
"Error processing Message: length is %d, should be >= %u",
rem, (MSGTYPE_MPLS_ECHO(msgtype)) ? 32 : 16);
}
return 0;
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msgtype, mpls_echo_msgtype, "Unknown Message Type (0x%02X)"));
if (tree) {
ti = proto_tree_add_item(tree, proto_mpls_echo, tvb, 0, -1, ENC_NA);
mpls_echo_tree = proto_item_add_subtree(ti, ett_mpls_echo);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_version, tvb, offset, 2, ENC_BIG_ENDIAN);
if (MSGTYPE_MPLS_ECHO(msgtype)) {
proto_tree *mpls_echo_gflags;
ti = proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_gflags, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
mpls_echo_gflags = proto_item_add_subtree(ti, ett_mpls_echo_gflags);
proto_tree_add_item(mpls_echo_gflags,
hf_mpls_echo_flag_sbz, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_gflags,
hf_mpls_echo_flag_v, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_gflags,
hf_mpls_echo_flag_t, tvb, (offset + 2), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_gflags,
hf_mpls_echo_flag_r, tvb, (offset + 2), 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_mbz, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_msgtype, tvb, offset + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_replymode, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_returncode, tvb, offset + 6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_returnsubcode, tvb, offset + 7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_handle, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree,
hf_mpls_echo_sequence, tvb, offset + 12, 4, ENC_BIG_ENDIAN);
if (MSGTYPE_MPLS_ECHO(msgtype)) {
proto_tree_add_item(mpls_echo_tree, hf_mpls_echo_ts_sent, tvb,
offset + 16, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_echo_tree, hf_mpls_echo_ts_rec, tvb,
offset + 24, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
}
}
if (MSGTYPE_MPLS_ECHO(msgtype)) {
offset += 32;
rem -= 32;
} else {
offset += 16;
rem -= 16;
}
while (tvb_reported_length_remaining(tvb, offset) > 0 ) {
len = dissect_mpls_echo_tlv(tvb, pinfo, offset, mpls_echo_tree, rem, FALSE);
offset += len;
rem -= len;
}
return tvb_length(tvb);
}
void
proto_register_mpls_echo(void)
{
static hf_register_info hf[] = {
{ &hf_mpls_echo_version,
{ "Version", "mpls_echo.version",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO Version Number", HFILL}
},
{ &hf_mpls_echo_mbz,
{ "MBZ", "mpls_echo.mbz",
FT_UINT16, BASE_HEX, NULL, 0x0, "MPLS ECHO Must be Zero", HFILL}
},
{ &hf_mpls_echo_gflags,
{ "Global Flags", "mpls_echo.flags",
FT_UINT16, BASE_HEX, NULL, 0x0, "MPLS ECHO Global Flags", HFILL}
},
{ &hf_mpls_echo_flag_sbz,
{ "Reserved", "mpls_echo.flag_sbz",
FT_UINT16, BASE_HEX, NULL, 0xFFF8, "MPLS ECHO Reserved Flags", HFILL}
},
{ &hf_mpls_echo_flag_v,
{ "Validate FEC Stack", "mpls_echo.flag_v",
FT_BOOLEAN, 16, NULL, 0x0001, "MPLS ECHO Validate FEC Stack Flag", HFILL}
},
{ &hf_mpls_echo_flag_t,
{ "Respond only if TTL expired", "mpls_echo.flag_t",
FT_BOOLEAN, 16, NULL, 0x0002, "MPLS ECHO Respond only if TTL expired Flag", HFILL}
},
{ &hf_mpls_echo_flag_r,
{ "Validate Reverse Path", "mpls_echo.flag_r",
FT_BOOLEAN, 16, NULL, 0x0004, "MPLS ECHO Validate Reverse Path Flag", HFILL}
},
{ &hf_mpls_echo_msgtype,
{ "Message Type", "mpls_echo.msg_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_msgtype), 0x0, "MPLS ECHO Message Type", HFILL}
},
{ &hf_mpls_echo_replymode,
{ "Reply Mode", "mpls_echo.reply_mode",
FT_UINT8, BASE_DEC, VALS(mpls_echo_replymode), 0x0, "MPLS ECHO Reply Mode", HFILL}
},
{ &hf_mpls_echo_returncode,
{ "Return Code", "mpls_echo.return_code",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mpls_echo_returncode_ext, 0x0, "MPLS ECHO Return Code", HFILL}
},
{ &hf_mpls_echo_returnsubcode,
{ "Return Subcode", "mpls_echo.return_subcode",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO Return Subcode", HFILL}
},
{ &hf_mpls_echo_handle,
{ "Sender's Handle", "mpls_echo.sender_handle",
FT_UINT32, BASE_HEX, NULL, 0x0, "MPLS ECHO Sender's Handle", HFILL}
},
{ &hf_mpls_echo_sequence,
{ "Sequence Number", "mpls_echo.sequence",
FT_UINT32, BASE_DEC, NULL, 0x0, "MPLS ECHO Sequence Number", HFILL}
},
{ &hf_mpls_echo_ts_sent,
{ "Timestamp Sent", "mpls_echo.timestamp_sent",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0, "MPLS ECHO Timestamp Sent", HFILL}
},
{ &hf_mpls_echo_ts_rec,
{ "Timestamp Received", "mpls_echo.timestamp_rec",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0, "MPLS ECHO Timestamp Received", HFILL}
},
{ &hf_mpls_echo_tlv_type,
{ "Type", "mpls_echo.tlv.type",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &mpls_echo_tlv_type_names_ext, 0x0,
"MPLS ECHO TLV Type", HFILL}
},
{ &hf_mpls_echo_tlv_len,
{ "Length", "mpls_echo.tlv.len",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Length", HFILL}
},
{ &hf_mpls_echo_tlv_value,
{ "Value", "mpls_echo.tlv.value",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Value", HFILL}
},
{ &hf_mpls_echo_tlv_fec_type,
{ "Type", "mpls_echo.tlv.fec.type",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &mpls_echo_tlv_fec_names_ext, 0x0,
"MPLS ECHO TLV FEC Stack Type", HFILL}
},
{ &hf_mpls_echo_tlv_fec_len,
{ "Length", "mpls_echo.tlv.fec.len",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_value,
{ "Value", "mpls_echo.tlv.fec.value",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack Value", HFILL}
},
{ &hf_mpls_echo_tlv_fec_ldp_ipv4,
{ "IPv4 Prefix", "mpls_echo.tlv.fec.ldp_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack LDP IPv4", HFILL}
},
{ &hf_mpls_echo_tlv_fec_ldp_ipv4_mask,
{ "Prefix Length", "mpls_echo.tlv.fec.ldp_ipv4_mask",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack LDP IPv4 Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_ldp_ipv6,
{ "IPv6 Prefix", "mpls_echo.tlv.fec.ldp_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack LDP IPv6", HFILL}
},
{ &hf_mpls_echo_tlv_fec_ldp_ipv6_mask,
{ "Prefix Length", "mpls_echo.tlv.fec.ldp_ipv6_mask",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack LDP IPv6 Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv4_ipv4_endpoint,
{ "IPv4 Tunnel endpoint address", "mpls_echo.tlv.fec.rsvp_ipv4_ep",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv4 Tunnel Endpoint Address", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv6_ipv6_endpoint,
{ "IPv6 Tunnel endpoint address", "mpls_echo.tlv.fec.rsvp_ipv6_ep",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv6 Tunnel Endpoint Address", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ip_mbz1,
{ "Must Be Zero", "mpls_echo.tlv.fec.rsvp_ip_mbz1",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ip_tunnel_id,
{ "Tunnel ID", "mpls_echo.tlv.fec.rsvp_ip_tun_id",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv4_ext_tunnel_id,
{ "Extended Tunnel ID", "mpls_echo.tlv.fec.rsvp_ipv4_ext_tun_id",
FT_UINT32, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv4 Extended Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv4_ipv4_sender,
{ "IPv4 Tunnel sender address", "mpls_echo.tlv.fec.rsvp_ipv4_sender",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv4 Sender", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv6_ext_tunnel_id,
{ "Extended Tunnel ID", "mpls_echo.tlv.fec.rsvp_ipv6_ext_tun_id",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv6 Extended Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ipv6_ipv6_sender,
{ "IPv6 Tunnel sender address", "mpls_echo.tlv.fec.rsvp_ipv6_sender",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP IPv4 Sender", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ip_mbz2,
{ "Must Be Zero", "mpls_echo.tlv.fec.rsvp_ip_mbz2",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_ip_lsp_id,
{ "LSP ID", "mpls_echo.tlv.fec.rsvp_ip_lsp_id",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP LSP ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_vpn_route_dist,
{ "Route Distinguisher", "mpls_echo.tlv.fec.vpn_route_dist",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack VPN Route Distinguisher", HFILL}
},
{ &hf_mpls_echo_tlv_fec_vpn_ipv4,
{ "IPv4 Prefix", "mpls_echo.tlv.fec.vpn_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack VPN IPv4", HFILL}
},
{ &hf_mpls_echo_tlv_fec_vpn_ipv6,
{ "IPv6 Prefix", "mpls_echo.tlv.fec.vpn_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack VPN IPv6", HFILL}
},
{ &hf_mpls_echo_tlv_fec_vpn_len,
{ "Prefix Length", "mpls_echo.tlv.fec.vpn_len",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack VPN Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2_vpn_route_dist,
{ "Route Distinguisher", "mpls_echo.tlv.fec.l2vpn_route_dist",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2VPN Route Distinguisher", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2_vpn_send_ve_id,
{ "Sender's VE ID", "mpls_echo.tlv.fec.l2vpn_send_ve_id",
FT_UINT16, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2VPN Sender's VE ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2_vpn_recv_ve_id,
{ "Receiver's VE ID", "mpls_echo.tlv.fec.l2vpn_recv_ve_id",
FT_UINT16, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2VPN Receiver's VE ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2_vpn_encap_type,
{ "Encapsulation", "mpls_echo.tlv.fec.l2vpn_encap_type",
FT_UINT16, BASE_DEC, VALS(fec_vc_types_vals), 0x0, "MPLS ECHO TLV FEC Stack L2VPN Encapsulation", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2cid_sender,
{ "Sender's PE Address", "mpls_echo.tlv.fec.l2cid_sender",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2CID Sender", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2cid_remote,
{ "Remote PE Address", "mpls_echo.tlv.fec.l2cid_remote",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2CID Remote", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2cid_vcid,
{ "VC ID", "mpls_echo.tlv.fec.l2cid_vcid",
FT_UINT32, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2CID VCID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2cid_encap,
{ "Encapsulation", "mpls_echo.tlv.fec.l2cid_encap",
FT_UINT16, BASE_DEC, VALS(fec_vc_types_vals), 0x0, "MPLS ECHO TLV FEC Stack L2CID Encapsulation", HFILL}
},
{ &hf_mpls_echo_tlv_fec_l2cid_mbz,
{ "MBZ", "mpls_echo.tlv.fec.l2cid_mbz",
FT_UINT16, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV FEC Stack L2CID MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_fec_bgp_ipv4,
{ "IPv4 Prefix", "mpls_echo.tlv.fec.bgp_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack BGP IPv4", HFILL}
},
{ &hf_mpls_echo_tlv_fec_bgp_ipv6,
{ "IPv6 Prefix", "mpls_echo.tlv.fec.bgp_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack BGP IPv6", HFILL}
},
{ &hf_mpls_echo_tlv_fec_bgp_len,
{ "Prefix Length", "mpls_echo.tlv.fec.bgp_len",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack BGP Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_gen_ipv4,
{ "IPv4 Prefix", "mpls_echo.tlv.fec.gen_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack Generic IPv4", HFILL}
},
{ &hf_mpls_echo_tlv_fec_gen_ipv4_mask,
{ "Prefix Length", "mpls_echo.tlv.fec.gen_ipv4_mask",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack Generic IPv4 Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_gen_ipv6,
{ "IPv6 Prefix", "mpls_echo.tlv.fec.gen_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack Generic IPv6", HFILL}
},
{ &hf_mpls_echo_tlv_fec_gen_ipv6_mask,
{ "Prefix Length", "mpls_echo.tlv.fec.gen_ipv6_mask",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack Generic IPv6 Prefix Length", HFILL}
},
{ &hf_mpls_echo_tlv_fec_nil_label,
{ "Label", "mpls_echo.tlv.fec.nil_label",
FT_UINT24, BASE_DEC, VALS(special_labels), 0x0, "MPLS ECHO TLV FEC Stack NIL Label", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mtu,
{ "MTU", "mpls_echo.tlv.ds_map.mtu",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map MTU", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_addr_type,
{ "Address Type", "mpls_echo.tlv.ds_map.addr_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_addr_type), 0x0,
"MPLS ECHO TLV Downstream Map Address Type", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_res,
{ "DS Flags", "mpls_echo.tlv.ds_map.res",
FT_UINT8, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV Downstream Map DS Flags", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_flag_res,
{ "MBZ", "mpls_echo.tlv.ds_map.flag_res",
FT_UINT8, BASE_HEX, NULL, 0xFC, "MPLS ECHO TLV Downstream Map Reserved Flags", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_flag_i,
{ "Interface and Label Stack Request", "mpls_echo.tlv.ds_map.flag_i",
FT_BOOLEAN, 8, NULL, 0x02, "MPLS ECHO TLV Downstream Map I-Flag", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_flag_n,
{ "Treat as Non-IP Packet", "mpls_echo.tlv.ds_map.flag_n",
FT_BOOLEAN, 8, NULL, 0x01, "MPLS ECHO TLV Downstream Map N-Flag", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_ds_ip,
{ "Downstream IP Address", "mpls_echo.tlv.ds_map.ds_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map IP Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_int_ip,
{ "Downstream Interface Address", "mpls_echo.tlv.ds_map.int_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Interface Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_if_index,
{ "Upstream Interface Index", "mpls_echo.tlv.ds_map.if_index",
FT_UINT32, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map Interface Index", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_ds_ipv6,
{ "Downstream IPv6 Address", "mpls_echo.tlv.ds_map.ds_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map IPv6 Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_int_ipv6,
{ "Downstream Interface IPv6 Address", "mpls_echo.tlv.ds_map.int_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Interface IPv6 Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_hash_type,
{ "Multipath Type", "mpls_echo.tlv.ds_map.hash_type",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &mpls_echo_tlv_ds_map_hash_type_ext, 0x0,
"MPLS ECHO TLV Downstream Map Multipath Type", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_depth,
{ "Depth Limit", "mpls_echo.tlv.ds_map.depth",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map Depth Limit", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_muti_len,
{ "Multipath Length", "mpls_echo.tlv.ds_map.multi_len",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map Multipath Length", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_ip,
{ "IP Address", "mpls_echo.tlv.ds_map_mp.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Multipath IP Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_mask,
{ "Mask", "mpls_echo.tlv.ds_map_mp.mask",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Multipath Mask", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_ip_low,
{ "IP Address Low", "mpls_echo.tlv.ds_map_mp.ip_low",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Multipath Low IP Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_ip_high,
{ "IP Address High", "mpls_echo.tlv.ds_map_mp.ip_high",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Downstream Map Multipath High IP Address", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_value,
{ "Multipath Value", "mpls_echo.tlv.ds_map_mp.value",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Multipath Value", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_label,
{ "Downstream Label", "mpls_echo.tlv.ds_map.mp_label",
FT_UINT24, BASE_DEC, VALS(special_labels), 0x0, "MPLS ECHO TLV Downstream Map Downstream Label", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_exp,
{ "Downstream Exp", "mpls_echo.tlv.ds_map.mp_exp",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map Downstream Experimental", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_bos,
{ "Downstream BOS", "mpls_echo.tlv.ds_map.mp_bos",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Downstream Map Downstream BOS", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_mp_proto,
{ "Downstream Protocol", "mpls_echo.tlv.ds_map.mp_proto",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_ds_map_mp_proto), 0x0,
"MPLS ECHO TLV Downstream Map Downstream Protocol", HFILL}
},
{ &hf_mpls_echo_tlv_padaction,
{ "Pad Action", "mpls_echo.tlv.pad_action",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_pad), 0x0, "MPLS ECHO Pad TLV Action", HFILL}
},
{ &hf_mpls_echo_tlv_padding,
{ "Padding", "mpls_echo.tlv.pad_padding",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO Pad TLV Padding", HFILL}
},
{ &hf_mpls_echo_tlv_vendor,
{ "Vendor Id", "mpls_echo.tlv.vendor_id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0x0, "MPLS ECHO Vendor Id", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_addr_type,
{ "Address Type", "mpls_echo.tlv.ilso.addr_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_addr_type), 0x0,
"MPLS ECHO TLV Interface and Label Stack Address Type", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_mbz,
{ "Must Be Zero", "mpls_echo.tlv.ilso.mbz",
FT_UINT24, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_ipv4_addr,
{ "Downstream IPv4 Address", "mpls_echo.tlv.ilso_ipv4.addr",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Address", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_ipv4_int_addr,
{ "Downstream Interface Address", "mpls_echo.tlv.ilso_ipv4.int_addr",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Interface Address", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_ipv6_addr,
{ "Downstream IPv6 Address", "mpls_echo.tlv.ilso_ipv6.addr",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Address", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_ipv6_int_addr,
{ "Downstream Interface Address", "mpls_echo.tlv.ilso_ipv6.int_addr",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Interface Address", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_int_index,
{ "Downstream Interface Index", "mpls_echo.tlv.ilso.int_index",
FT_UINT32, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Interface Index", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_label,
{ "Label", "mpls_echo.tlv.ilso_ipv4.label",
FT_UINT24, BASE_DEC, VALS(special_labels), 0x0, "MPLS ECHO TLV Interface and Label Stack Label", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_exp,
{ "Exp", "mpls_echo.tlv.ilso_ipv4.exp",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack Exp", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_bos,
{ "BOS", "mpls_echo.tlv.ilso_ipv4.bos",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack BOS", HFILL}
},
{ &hf_mpls_echo_tlv_ilso_ttl,
{ "TTL", "mpls_echo.tlv.ilso_ipv4.ttl",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Interface and Label Stack TTL", HFILL}
},
#if 0
{ &hf_mpls_echo_tlv_rto_ipv4,
{ "Reply-to IPv4 Address", "mpls_echo.tlv.rto.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV IPv4 Reply-To Object", HFILL}
},
{ &hf_mpls_echo_tlv_rto_ipv6,
{ "Reply-to IPv6 Address", "mpls_echo.tlv.rto.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV IPv6 Reply-To Object", HFILL}
},
#endif
{ &hf_mpls_echo_tlv_reply_tos,
{ "Reply-TOS Byte", "mpls_echo.tlv.reply.tos",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Reply-TOS Byte", HFILL}
},
{ &hf_mpls_echo_tlv_reply_tos_mbz,
{ "MBZ", "mpls_echo.tlv.reply.tos.mbz",
FT_UINT24, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV Reply-TOS MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_errored_type,
{ "Errored TLV Type", "mpls_echo.tlv.errored.type",
FT_UINT16, BASE_DEC | BASE_EXT_STRING, &mpls_echo_tlv_type_names_ext, 0x0,
"MPLS ECHO TLV Errored TLV Type", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_ingress_if_num,
{ "Ingress Interface Number", "mpls_echo.tlv.ds_map.ingress.if.num",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MPLS ECHO TLV DownStream Map Ingress Interface Number", HFILL}
},
{ &hf_mpls_echo_tlv_ds_map_egress_if_num,
{ "Egress Interface Number", "mpls_echo.tlv.ds_map.egress.if.num",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MPLS ECHO TLV DownStream Map Egress Interface Number", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_src_gid,
{ "SRC GLOBAL ID", "mpls_echo.lspping.tlv.src.gid",
FT_UINT32, BASE_DEC, NULL, 0x0, "LSP SRC GID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_src_nid,
{ "SRC NODE ID", "mpls_echo.lspping.tlv.src.nid",
FT_IPv4, BASE_NONE, NULL, 0x0, "LSP SRC NID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_src_tunnel_no,
{ "SRC Tunnel Number", "mpls_echo.lspping.tlv.tunnel.no",
FT_UINT16, BASE_DEC, NULL, 0x0, "LSP FEC Tunnel Number", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_lsp_no,
{ "SRC LSP Number", "mpls_echo.lspping.tlv.lsp.no",
FT_UINT16, BASE_DEC, NULL, 0x0, "LSP FEC LSP Number", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_dst_gid,
{ "DST GLOBAL ID", "mpls_echo.lspping.tlv.dst.gid",
FT_UINT32, BASE_DEC, NULL, 0x0, "LSP FEC DST GID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_dst_nid,
{ "DST NODE ID", "mpls_echo.lspping.tlv.dst.nid",
FT_IPv4, BASE_NONE, NULL, 0x0, "LSP FEC DST NID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_dst_tunnel_no,
{ "DST Tunnel Number", "mpls_echo.lspping.tlv.dst.tunnel.no",
FT_UINT16, BASE_DEC, NULL, 0x0, "LSP FEC DST Tunnel Number", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_resv,
{ "RESERVED", "mpls_echo.lspping.tlv.resv",
FT_UINT16, BASE_DEC, NULL, 0x0, "RESERVED BITS", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_src_addr_gid,
{ "Global ID", "mpls_echo.lspping.tlv.src.addr.gid",
FT_UINT32, BASE_DEC, NULL, 0x0, "SRC ADDR TLV GID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_src_addr_nid,
{ "Node ID", "mpls_echo.lspping.tlv.src.addr.nid",
FT_IPv4, BASE_NONE, NULL, 0x0, "SRC ADDR TLV NID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_pw_serv_identifier,
{ "Service identifier", "mpls_echo.lspping.tlv.pw.serv.identifier",
FT_UINT64, BASE_DEC, NULL, 0x0, "PW FEC Service identifier", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_pw_src_ac_id,
{ "SRC AC ID", "mpls_echo.lspping.tlv.pw.src.ac.id",
FT_UINT32, BASE_DEC, NULL, 0x0, "PW FEC SRC AC ID", HFILL}
},
{ &hf_mpls_echo_lspping_tlv_pw_dst_ac_id,
{ "DST AC ID", "mpls_echo.lspping.tlv.pw.dst.ac.id",
FT_UINT32, BASE_DEC, NULL, 0x0, "PW FEC DST AC ID", HFILL}
},
#if 0
{ &hf_mpls_echo_lspping_tlv_pw_agi_type,
{ "AGI TYPE", "mpls_echo.lspping.tlv.pw.agi.type",
FT_UINT8, BASE_DEC, NULL, 0x0, "PW AGI TYPE", HFILL}
},
#endif
#if 0
{ &hf_mpls_echo_lspping_tlv_pw_agi_len,
{ "AGI Length", "mpls_echo.lspping.tlv.pw.agi.len",
FT_UINT8, BASE_DEC, NULL, 0x0, "PW AGI LENGTH", HFILL}
},
#endif
#if 0
{ &hf_mpls_echo_lspping_tlv_pw_agi_val,
{ "AGI VALUE", "mpls_echo.lspping.tlv.pw.agi.val",
FT_STRING, BASE_NONE, NULL, 0x0, "PW AGI VALUE", HFILL}
},
#endif
{ &hf_mpls_echo_tlv_dd_map_mtu,
{ "MTU", "mpls_echo.lspping.tlv.dd_map.mtu",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map MTU", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_addr_type,
{ "Address Type", "mpls_echo.tlv.dd_map.addr_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_addr_type), 0x0, "MPLS ECHO TLV Detailed Downstream Map Address Type", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_res,
{ "DS Flags", "mpls_echo.tlv.dd_map.res",
FT_UINT8, BASE_HEX, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map DS Flags", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_flag_res,
{ "MBZ", "mpls_echo.tlv.dd_map.flag_res",
FT_UINT8, BASE_HEX, NULL, 0xFC, "MPLS ECHO TLV Detailed Downstream Map Reserved Flags", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_flag_i,
{ "Interface and Label Stack Request", "mpls_echo.tlv.dd_map.flag_i",
FT_BOOLEAN, 8, NULL, 0x02, "MPLS ECHO TLV Detailed Downstream Map I-Flag", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_flag_n,
{ "Treat as Non-IP Packet", "mpls_echo.tlv.dd_map.flag_n",
FT_BOOLEAN, 8, NULL, 0x01, "MPLS ECHO TLV Detailed Downstream Map N-Flag", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_ds_ip,
{ "Downstream IP Address", "mpls_echo.tlv.dd_map.ds_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map IP Address", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_int_ip,
{ "Downstream Interface Address", "mpls_echo.tlv.dd_map.int_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Interface Address", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_ds_ipv6,
{ "Downstream IPv6 Address", "mpls_echo.tlv.dd_map.ds_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map IPv6 Address", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_int_ipv6,
{ "Downstream Interface IPv6 Address", "mpls_echo.tlv.dd_map.int_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Interface IPv6 Address", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_return_code,
{ "Return Code", "mpls_echo.tlv.dd_map.return_code",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Return Code", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_return_subcode,
{ "Return Subcode", "mpls_echo.tlv.dd_map.return_subcode",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Return Subcode", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_ingress_if_num,
{ "Ingress Interface Number", "mpls_echo.tlv.dd_map.ingress.if.num",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MPLS ECHO TLV Detailed DownStream Map Ingress Interface Number", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_egress_if_num,
{ "Egress Interface Number", "mpls_echo.tlv.dd_map.egress.if.num",
FT_UINT32, BASE_DEC, NULL, 0x0,
"MPLS ECHO TLV Detailed DownStream Map Egress Interface Number", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_subtlv_len,
{ "Subtlv Length", "mpls_echo.tlv.dd_map.subtlv_len",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Subtlv Length", HFILL}
},
{ &hf_mpls_echo_sub_tlv_multipath_type,
{ "Multipath Type", "mpls_echo.subtlv.dd_map.multipath_type",
FT_UINT8, BASE_DEC, NULL, 0x0, "Detailed Downstream Mapping TLV Multipath Data Sub-TLV Multipath Type", HFILL}
},
{ &hf_mpls_echo_sub_tlv_multipath_length,
{ "Multipath Length", "mpls_echo.subtlv.dd_map.multipath_length",
FT_UINT16, BASE_DEC, NULL, 0x0, "Detailed Downstream Mapping TLV Multipath Data Sub-TLV Multipath Length", HFILL}
},
{ &hf_mpls_echo_sub_tlv_multipath_value,
{ "Multipath Value", "mpls_echo.subtlv.dd_map.multipath_value",
FT_BYTES, BASE_NONE, NULL, 0x0, "Detailed Downstream Mapping TLV Multipath Data Sub-TLV Multipath Value", HFILL}
},
{ &hf_mpls_echo_sub_tlv_resv,
{ "Reserved", "mpls_echo.subtlv.dd_map.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0, "Detailed Downstream Mapping TLV Multipath Data Sub-TLV Reserved Bits", HFILL}
},
{ &hf_mpls_echo_sub_tlv_multipath_info,
{ "Multipath Information", "mpls_echo.subtlv.dd_map.multipath_info",
FT_BYTES, BASE_NONE, NULL, 0x0, "Detailed Downstream Mapping TLV Multipath Data Sub-TLV Value", HFILL}
},
#if 0
{ &hf_mpls_echo_tlv_ddstlv_map_mp_label,
{ "Downstream Label", "mpls_echo.tlv.ddstlv_map.mp_label",
FT_UINT24, BASE_DEC, VALS(special_labels), 0x0, "MPLS ECHO TLV Detailed Downstream Map Downstream Label", HFILL}
},
#endif
{ &hf_mpls_echo_tlv_ddstlv_map_mp_proto,
{ "Downstream Protocol", "mpls_echo.tlv.ddstlv_map.mp_proto",
FT_UINT8, BASE_DEC, VALS(mpls_echo_tlv_ds_map_mp_proto), 0x0,
"MPLS ECHO TLV Detailed Downstream Map Downstream Protocol", HFILL}
},
#if 0
{ &hf_mpls_echo_tlv_ddstlv_map_mp_exp,
{ "Downstream Experimental", "mpls_echo.tlv.ddstlv_map.mp_exp",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Downstream Experimental", HFILL}
},
#endif
#if 0
{ &hf_mpls_echo_tlv_ddstlv_map_mp_bos,
{ "Downstream BOS", "mpls_echo.tlv.ddstlv_map.mp_bos",
FT_UINT8, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Downstream BOS", HFILL}
},
#endif
{ &hf_mpls_echo_sub_tlv_multipath_ip,
{ "IP Address", "mpls_echo.tlv.ddstlv_map_mp.ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Multipath IP Address", HFILL}
},
{ &hf_mpls_echo_sub_tlv_mp_ip_low,
{ "IP Address Low", "mpls_echo.tlv.ddstlv_map_mp.ip_low",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Multipath Low IP Address", HFILL}
},
{ &hf_mpls_echo_sub_tlv_mp_ip_high,
{ "IP Address High", "mpls_echo.tlv.ddstlv_map_mp.ip_high",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Multipath High IP Address", HFILL}
},
{ &hf_mpls_echo_sub_tlv_mp_mask,
{ "Mask", "mpls_echo.tlv.ddstlv_map_mp.mask",
FT_BYTES, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV Detailed Downstream Map Multipath Mask", HFILL}
},
{ &hf_mpls_echo_sub_tlv_op_type,
{ "Operation Type", "mpls_echo.tlv.ddstlv_map.op_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_subtlv_op_types), 0x0,
"MPLS ECHO TLV Detailed Downstream Map Stack Change Operation Type", HFILL}
},
{ &hf_mpls_echo_sub_tlv_addr_type,
{ "Address Type", "mpls_echo.tlv.ddstlv_map.address_type",
FT_UINT8, BASE_DEC, VALS(mpls_echo_subtlv_addr_types), 0x0,
"MPLS ECHO TLV Detailed Downstream Map Stack Change Address Type", HFILL}
},
{ &hf_mpls_echo_sub_tlv_fec_tlv_value,
{ "FEC tlv Length", "mpls_echo.subtlv.dd_map.fec_tlv_type",
FT_UINT8, BASE_DEC, NULL, 0x0, "Detailed Downstream Map FEC TLV Length", HFILL}
},
{ &hf_mpls_echo_sub_tlv_res,
{ "Reserved", "mpls_echo.subtlv.dd_map.reserved",
FT_UINT8, BASE_DEC, NULL, 0x0, "Detailed Downstream Map FEC Stack Change Reserved Bits", HFILL}
},
{ &hf_mpls_echo_sub_tlv_remote_peer_ip,
{ "Remote Peer IP Address", "mpls_echo.tlv.dd_map.remote_ip",
FT_IPv4, BASE_NONE, NULL, 0x0, "Detailed Downstream Map FEC Stack Change Remote Peer IP Address", HFILL}
},
{ &hf_mpls_echo_sub_tlv_remore_peer_ipv6,
{ "Remote Peer IPv6 Address", "mpls_echo.tlv.dd_map.remote_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "Detailed Downstream Map FEC Stack Change Remote Peer IPv6 Address", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_type,
{ "Sub-TLV Type", "mpls_echo.subtlv.dd_map.type",
FT_UINT16, BASE_DEC, NULL, 0x0, "Detailed Downstream Mapping TLV Type", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_length,
{ "Sub-TLV Length", "mpls_echo.subtlv.dd_map.length",
FT_UINT16, BASE_DEC, NULL, 0x0, "Detailed Downstream Mapping TLV Length", HFILL}
},
{ &hf_mpls_echo_tlv_dd_map_value,
{ "Sub-TLV Value", "mpls_echo.subtlv.dd_map.value",
FT_BYTES, BASE_NONE, NULL, 0x0, "Detailed Downstream Mapping TLV Value", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_p2mp_id,
{ "P2MP ID", "mpls_echo.tlv.fec.rsvp_p2mp_ipv4_id",
FT_UINT32, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_mbz1,
{ "Must Be Zero", "mpls_echo.tlv.fec.rsvp_p2mp_ip_mbz1",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_tunnel_id,
{ "Tunnel ID", "mpls_echo.tlv.fec.rsvp_p2mp_ip_tun_id",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_ext_tunnel_id,
{ "Extended Tunnel ID", "mpls_echo.tlv.fec.rsvp_p2mp_ipv4_ext_tun_id",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP IPv4 Extended Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv4_ipv4_sender,
{ "IPv4 Tunnel sender address", "mpls_echo.tlv.fec.rsvp_p2mp_ipv4_sender",
FT_IPv4, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP IPv4 Sender", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_mbz2,
{ "Must Be Zero", "mpls_echo.tlv.fec.rsvp_p2mp_ip_mbz2",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP MBZ", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ip_lsp_id,
{ "LSP ID", "mpls_echo.tlv.fec.rsvp_p2mp_ip_lsp_id",
FT_UINT16, BASE_DEC, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP LSP ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_p2mp_id,
{ "P2MP IPv6 Tunnel ID address", "mpls_echo.tlv.fec.rsvp_p2mp_ipv6_id",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP IPv6 ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_ext_tunnel_id,
{ "Extended Tunnel ID", "mpls_echo.tlv.fec.rsvp_p2mp_ipv6_ext_tun_id",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP IPv6 Extended Tunnel ID", HFILL}
},
{ &hf_mpls_echo_tlv_fec_rsvp_p2mp_ipv6_ipv6_sender,
{ "P2MP IPv6 Tunnel sender address", "mpls_echo.tlv.fec.rsvp_p2mp_ipv6_sender",
FT_IPv6, BASE_NONE, NULL, 0x0, "MPLS ECHO TLV FEC Stack RSVP P2MP IPv6 Sender", HFILL}
},
{ &hf_mpls_echo_tlv_responder_indent_type,
{ "Target Type", "mpls_echo.tlv.resp_id.type",
FT_UINT16, BASE_DEC, VALS(mpls_echo_tlv_responder_ident_sub_tlv_type), 0x0, "P2MP Responder ID TLV", HFILL}
},
{ &hf_mpls_echo_tlv_responder_indent_len,
{ "Length", "mpls_echo.tlv.resp_id.length",
FT_UINT16, BASE_DEC, NULL, 0x0, "P2MP Responder ID TLV LENGTH", HFILL}
},
{ &hf_mpls_echo_tlv_responder_indent_ipv4,
{ "Target IPv4 Address", "mpls_echo.tlv.resp_id.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0, "P2MP Responder ID TLV IPv4 Address", HFILL}
},
#if 0
{ &hf_mpls_echo_tlv_responder_indent_ipv6,
{ "Target IPv6 Address", "mpls_echo.tlv.resp_id.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "P2MP Responder ID TLV IPv6 Address", HFILL}
},
#endif
{ &hf_mpls_echo_tlv_echo_jitter,
{ "Echo Jitter time", "mpls_echo.tlv.echo_jitter",
FT_UINT32, BASE_DEC, NULL, 0x0, "MPLS ECHO Jitter time", HFILL}
},
{ &hf_mpls_echo_tlv_bfd,
{ "BFD Discriminator", "mpls_echo.bfd_discriminator",
FT_UINT32, BASE_HEX, NULL, 0x0, "MPLS ECHO BFD Discriminator", HFILL}
},
};
static gint *ett[] = {
&ett_mpls_echo,
&ett_mpls_echo_gflags,
&ett_mpls_echo_tlv,
&ett_mpls_echo_tlv_fec,
&ett_mpls_echo_tlv_ds_map,
&ett_mpls_echo_tlv_ilso,
&ett_mpls_echo_tlv_dd_map,
&ett_mpls_echo_tlv_ddstlv_map
};
static ei_register_info ei[] = {
{ &ei_mpls_echo_tlv_fec_len, { "mpls_echo.tlv.fec.len.invalid", PI_MALFORMED, PI_ERROR, "Invalid FEC TLV length", EXPFILL }},
{ &ei_mpls_echo_tlv_dd_map_subtlv_len, { "mpls_echo.tlv.dd_map.subtlv_len.invalid", PI_MALFORMED, PI_ERROR, "Invalid Sub-TLV length", EXPFILL }},
{ &ei_mpls_echo_tlv_len, { "mpls_echo.tlv.len.invalid", PI_MALFORMED, PI_ERROR, "Invalid TLV length", EXPFILL }},
{ &ei_mpls_echo_tlv_ds_map_muti_len, { "mpls_echo.tlv.ds_map.multi_len.invalid", PI_MALFORMED, PI_ERROR, "Invalid Multipath TLV length", EXPFILL }},
{ &ei_mpls_echo_unknown_address_type, { "mpls_echo.address_type.unknown", PI_UNDECODED, PI_WARN, "Unknown Address Type", EXPFILL }},
{ &ei_mpls_echo_incorrect_address_type, { "mpls_echo.address_type.incorrect", PI_PROTOCOL, PI_WARN, "Incorrect address type for TLV?", EXPFILL }},
};
module_t *mpls_echo_module;
expert_module_t* expert_mpls_echo;
proto_mpls_echo = proto_register_protocol("Multiprotocol Label Switching Echo",
"MPLS Echo", "mpls-echo");
proto_register_field_array(proto_mpls_echo, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_mpls_echo = expert_register_protocol(proto_mpls_echo);
expert_register_field_array(expert_mpls_echo, ei, array_length(ei));
mpls_echo_module = prefs_register_protocol(proto_mpls_echo, proto_reg_handoff_mpls_echo);
prefs_register_uint_preference(mpls_echo_module, "udp.port", "MPLS Echo UDP Port",
"Set the UDP port for messages (if other"
" than the default of 3503)",
10, &global_mpls_echo_udp_port);
}
void
proto_reg_handoff_mpls_echo(void)
{
static gboolean mpls_echo_prefs_initialized = FALSE;
static dissector_handle_t mpls_echo_handle;
static guint mpls_echo_udp_port;
if (!mpls_echo_prefs_initialized) {
mpls_echo_handle = new_create_dissector_handle(dissect_mpls_echo,
proto_mpls_echo);
mpls_echo_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", mpls_echo_udp_port, mpls_echo_handle);
}
mpls_echo_udp_port = global_mpls_echo_udp_port;
dissector_add_uint("udp.port", global_mpls_echo_udp_port, mpls_echo_handle);
}
