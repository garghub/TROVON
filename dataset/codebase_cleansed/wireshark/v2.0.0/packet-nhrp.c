static guint16 nhrp_checksum(tvbuff_t *tvb, int len)
{
vec_t cksum_vec[1];
SET_CKSUM_VEC_TVB(cksum_vec[0], tvb, 0, len);
return in_cksum(&cksum_vec[0], 1);
}
static void dissect_nhrp_hdr(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
gint *pOffset,
gint *pMandLen,
gint *pExtLen,
oui_info_t **pOuiInfo,
e_nhrp_hdr *hdr)
{
gint offset = *pOffset;
const gchar *pro_type_str;
guint total_len = tvb_reported_length(tvb);
guint16 ipcsum, rx_chksum;
proto_tree *nhrp_tree;
proto_item *shtl_tree_item;
proto_tree *shtl_tree;
proto_item *sstl_tree_item;
proto_tree *sstl_tree;
proto_item *ti;
nhrp_tree = proto_tree_add_subtree(tree, tvb, offset, 20, ett_nhrp_hdr, NULL, "NHRP Fixed Header");
hdr->ar_pktsz = tvb_get_ntohs(tvb, 10);
if (total_len > hdr->ar_pktsz) {
total_len = hdr->ar_pktsz;
}
hdr->ar_afn = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(nhrp_tree, hf_nhrp_hdr_afn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hdr->ar_pro_type = tvb_get_ntohs(tvb, offset);
if (hdr->ar_pro_type <= 0xFF) {
pro_type_str = val_to_str_const(hdr->ar_pro_type, nlpid_vals,
"Unknown NLPID");
} else if (hdr->ar_pro_type <= 0x3FF) {
pro_type_str = "Reserved for future use by the IETF";
} else if (hdr->ar_pro_type <= 0x04FF) {
pro_type_str = "Allocated for use by the ATM Forum";
} else if (hdr->ar_pro_type <= 0x05FF) {
pro_type_str = "Experimental/Local use";
} else {
pro_type_str = val_to_str_const(hdr->ar_pro_type, etype_vals,
"Unknown Ethertype");
}
proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_pro_type, tvb, offset, 2,
hdr->ar_pro_type, "%s (0x%04x)",
pro_type_str, hdr->ar_pro_type);
offset += 2;
if (hdr->ar_pro_type == NLPID_SNAP) {
hdr->ar_pro_type_oui = tvb_get_ntoh24(tvb, offset);
proto_tree_add_uint(nhrp_tree, hf_nhrp_hdr_pro_snap_oui,
tvb, offset, 3, hdr->ar_pro_type_oui);
offset += 3;
hdr->ar_pro_type_pid = tvb_get_ntohs(tvb, offset);
*pOuiInfo = get_snap_oui_info(hdr->ar_pro_type_oui);
if (*pOuiInfo != NULL) {
proto_tree_add_uint(nhrp_tree,
*(*pOuiInfo)->field_info->p_id,
tvb, offset, 2, hdr->ar_pro_type_pid);
} else {
proto_tree_add_uint(nhrp_tree, hf_nhrp_hdr_pro_snap_pid,
tvb, offset, 2, hdr->ar_pro_type_pid);
}
} else {
proto_tree_add_item(nhrp_tree, hf_nhrp_protocol_type, tvb, offset, 5, ENC_NA);
offset += 5;
}
proto_tree_add_item(nhrp_tree, hf_nhrp_hdr_hopcnt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nhrp_tree, hf_nhrp_hdr_pktsz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
rx_chksum = tvb_get_ntohs(tvb, offset);
if (tvb_bytes_exist(tvb, 0, total_len)) {
ipcsum = nhrp_checksum(tvb, total_len);
if (ipcsum == 0) {
proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_chksum, tvb, offset, 2, rx_chksum,
"0x%04x [correct]", rx_chksum);
} else {
proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_chksum, tvb, offset, 2, rx_chksum,
"0x%04x [incorrect, should be 0x%04x]", rx_chksum,
in_cksum_shouldbe(rx_chksum, ipcsum));
}
} else {
proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_chksum, tvb, offset, 2, rx_chksum,
"0x%04x [not all data available]", rx_chksum);
}
offset += 2;
hdr->ar_extoff = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(nhrp_tree, hf_nhrp_hdr_extoff, tvb, offset, 2, ENC_BIG_ENDIAN);
if (hdr->ar_extoff != 0 && hdr->ar_extoff < 20) {
expert_add_info(pinfo, ti, &ei_nhrp_hdr_extoff);
}
offset += 2;
hdr->ar_op_version = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_version, tvb, offset, 1,
hdr->ar_op_version, "%u (%s)", hdr->ar_op_version,
(hdr->ar_op_version == 1) ? "NHRP - rfc2332" : "Unknown");
offset += 1;
proto_tree_add_item(nhrp_tree, hf_nhrp_hdr_op_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
hdr->ar_shtl = tvb_get_guint8(tvb, offset);
shtl_tree_item = proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_shtl,
tvb, offset, 1, hdr->ar_shtl, "%s/%u",
val_to_str_const(NHRP_SHTL_TYPE(hdr->ar_shtl), nhrp_shtl_type_vals, "Unknown Type"),
NHRP_SHTL_LEN(hdr->ar_shtl));
shtl_tree = proto_item_add_subtree(shtl_tree_item, ett_nhrp_hdr_shtl);
proto_tree_add_item(shtl_tree, hf_nhrp_hdr_shtl_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(shtl_tree, hf_nhrp_hdr_shtl_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
hdr->ar_sstl = tvb_get_guint8(tvb, offset);
sstl_tree_item = proto_tree_add_uint_format_value(nhrp_tree, hf_nhrp_hdr_sstl,
tvb, offset, 1, hdr->ar_sstl, "%s/%u",
val_to_str_const(NHRP_SHTL_TYPE(hdr->ar_sstl), nhrp_shtl_type_vals, "Unknown Type"),
NHRP_SHTL_LEN(hdr->ar_sstl));
sstl_tree = proto_item_add_subtree(sstl_tree_item, ett_nhrp_hdr_sstl);
proto_tree_add_item(sstl_tree, hf_nhrp_hdr_sstl_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sstl_tree, hf_nhrp_hdr_sstl_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
*pOffset = offset;
if (hdr->ar_extoff != 0) {
if (hdr->ar_extoff >= 20) {
*pMandLen = hdr->ar_extoff - 20;
*pExtLen = total_len - hdr->ar_extoff;
} else {
*pMandLen = 0;
*pExtLen = 0;
}
}
else {
if (total_len >= 20)
*pMandLen = total_len - 20;
else {
*pMandLen = 0;
}
*pExtLen = 0;
}
}
static void dissect_cie_list(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
gint offset,
gint cieEnd,
e_nhrp_hdr *hdr,
gint isReq,
gboolean codeinfo)
{
proto_item *cli_addr_tree_item;
proto_tree *cli_addr_tree;
proto_item *cli_saddr_tree_item;
proto_tree *cli_saddr_tree;
guint8 val;
while ((offset + 12) <= cieEnd) {
guint cli_addr_len = tvb_get_guint8(tvb, offset + 8);
guint cli_saddr_len = tvb_get_guint8(tvb, offset + 9);
guint cli_prot_len = tvb_get_guint8(tvb, offset + 10);
guint cie_len = 12 + cli_addr_len + cli_saddr_len + cli_prot_len;
proto_tree *cie_tree = proto_tree_add_subtree(tree, tvb, offset, cie_len, ett_nhrp_cie, NULL, "Client Information Entry");
if (isReq) {
proto_tree_add_item(cie_tree, hf_nhrp_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else {
guint8 code = tvb_get_guint8(tvb, offset);
if ( codeinfo ) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Code=%s",
val_to_str(code, nhrp_cie_code_vals, "Unknown (%u)"));
}
proto_tree_add_item(cie_tree, hf_nhrp_code, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
proto_tree_add_item(cie_tree, hf_nhrp_prefix_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cie_tree, hf_nhrp_unused, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cie_tree, hf_nhrp_mtu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(cie_tree, hf_nhrp_holding_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
val = tvb_get_guint8(tvb, offset);
cli_addr_tree_item = proto_tree_add_uint_format_value(cie_tree,
hf_nhrp_cli_addr_tl, tvb, offset, 1, val, "%s/%u",
val_to_str_const(NHRP_SHTL_TYPE(val), nhrp_shtl_type_vals, "Unknown Type"),
NHRP_SHTL_LEN(val));
cli_addr_tree = proto_item_add_subtree(cli_addr_tree_item, ett_nhrp_cie_cli_addr_tl);
proto_tree_add_item(cli_addr_tree, hf_nhrp_cli_addr_tl_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cli_addr_tree, hf_nhrp_cli_addr_tl_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
val = tvb_get_guint8(tvb, offset);
cli_saddr_tree_item = proto_tree_add_uint_format_value(cie_tree,
hf_nhrp_cli_saddr_tl, tvb, offset, 1, val, "%s/%u",
val_to_str_const(NHRP_SHTL_TYPE(val), nhrp_shtl_type_vals, "Unknown Type"),
NHRP_SHTL_LEN(val));
cli_saddr_tree = proto_item_add_subtree(cli_saddr_tree_item, ett_nhrp_cie_cli_saddr_tl);
proto_tree_add_item(cli_saddr_tree, hf_nhrp_cli_saddr_tl_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(cli_saddr_tree, hf_nhrp_cli_saddr_tl_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cie_tree, hf_nhrp_cli_prot_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(cie_tree, hf_nhrp_pref, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (cli_addr_len) {
switch (hdr->ar_afn) {
case AFNUM_INET:
if (cli_addr_len == 4)
proto_tree_add_item(cie_tree, hf_nhrp_client_nbma_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
else {
proto_tree_add_item(cie_tree, hf_nhrp_client_nbma_address_bytes, tvb, offset, cli_addr_len, ENC_NA);
}
break;
default:
proto_tree_add_item(cie_tree, hf_nhrp_client_nbma_address_bytes, tvb, offset, cli_addr_len, ENC_NA);
break;
}
offset += cli_addr_len;
}
if (cli_saddr_len) {
proto_tree_add_item(cie_tree, hf_nhrp_client_nbma_saddr, tvb, offset, cli_saddr_len, ENC_NA);
}
if (cli_prot_len) {
if (cli_prot_len == 4)
proto_tree_add_item(cie_tree, hf_nhrp_client_prot_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
else {
proto_tree_add_item(cie_tree, hf_nhrp_client_prot_addr_bytes, tvb, offset, cli_prot_len, ENC_NA);
}
offset += cli_prot_len;
}
}
}
static void dissect_nhrp_mand(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
gint *pOffset,
gint mandLen,
oui_info_t *oui_info,
e_nhrp_hdr *hdr,
guint *srcLen,
gboolean codeinfo)
{
gint offset = *pOffset;
gint mandEnd = offset + mandLen;
guint8 ssl, shl;
guint dstLen;
gboolean isReq = FALSE;
gboolean isErr = FALSE;
gboolean isInd = FALSE;
proto_tree *nhrp_tree;
switch (hdr->ar_op_type)
{
case NHRP_RESOLUTION_REPLY:
case NHRP_REGISTRATION_REPLY:
case NHRP_PURGE_REPLY:
break;
case NHRP_RESOLUTION_REQ:
case NHRP_REGISTRATION_REQ:
case NHRP_PURGE_REQ:
isReq = TRUE;
break;
case NHRP_ERROR_INDICATION:
isErr = TRUE;
isInd = TRUE;
break;
case NHRP_TRAFFIC_INDICATION:
isInd = TRUE;
break;
}
nhrp_tree = proto_tree_add_subtree(tree, tvb, offset, mandLen, ett_nhrp_mand, NULL, "NHRP Mandatory Part");
*srcLen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(nhrp_tree, hf_nhrp_src_proto_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
dstLen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(nhrp_tree, hf_nhrp_dst_proto_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (!isInd) {
switch (hdr->ar_op_type)
{
case NHRP_RESOLUTION_REQ:
case NHRP_RESOLUTION_REPLY:
{
static const int * flags[] = {
&hf_nhrp_flag_Q,
&hf_nhrp_flag_A,
&hf_nhrp_flag_D,
&hf_nhrp_flag_U1,
&hf_nhrp_flag_S,
&hf_nhrp_flag_NAT,
NULL
};
proto_tree_add_bitmask(nhrp_tree, tvb, offset, hf_nhrp_flags, ett_nhrp_mand_flag, flags, ENC_BIG_ENDIAN);
}
break;
case NHRP_REGISTRATION_REQ:
case NHRP_REGISTRATION_REPLY:
{
static const int * flags[] = {
&hf_nhrp_flag_U2,
&hf_nhrp_flag_NAT,
NULL
};
proto_tree_add_bitmask(nhrp_tree, tvb, offset, hf_nhrp_flags, ett_nhrp_mand_flag, flags, ENC_BIG_ENDIAN);
}
break;
case NHRP_PURGE_REQ:
case NHRP_PURGE_REPLY:
{
static const int * flags[] = {
&hf_nhrp_flag_N,
&hf_nhrp_flag_NAT,
NULL
};
proto_tree_add_bitmask(nhrp_tree, tvb, offset, hf_nhrp_flags, ett_nhrp_mand_flag, flags, ENC_BIG_ENDIAN);
}
break;
default:
{
static const int * flags[] = {
&hf_nhrp_flag_NAT,
NULL
};
proto_tree_add_bitmask(nhrp_tree, tvb, offset, hf_nhrp_flags, ett_nhrp_mand_flag, flags, ENC_BIG_ENDIAN);
}
break;
}
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", ID=%u", tvb_get_ntohl(tvb, offset));
proto_tree_add_item(nhrp_tree, hf_nhrp_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (isErr) {
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(tvb_get_ntohs(tvb, offset), nhrp_error_code_vals, "Unknown Error (%u)"));
proto_tree_add_item(nhrp_tree, hf_nhrp_error_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nhrp_tree, hf_nhrp_error_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
else {
offset += 6;
}
shl = NHRP_SHTL_LEN(hdr->ar_shtl);
if (shl) {
switch (hdr->ar_afn) {
case AFNUM_INET:
if (shl == 4)
proto_tree_add_item(nhrp_tree, hf_nhrp_src_nbma_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
else {
proto_tree_add_item(nhrp_tree, hf_nhrp_src_nbma_addr_bytes, tvb, offset, shl, ENC_NA);
}
break;
default:
proto_tree_add_item(nhrp_tree, hf_nhrp_src_nbma_addr_bytes, tvb, offset, shl, ENC_NA);
break;
}
offset += shl;
}
ssl = NHRP_SHTL_LEN(hdr->ar_sstl);
if (ssl) {
proto_tree_add_item(nhrp_tree, hf_nhrp_src_nbma_saddr, tvb, offset, ssl, ENC_NA);
offset += ssl;
}
if (*srcLen == 4) {
proto_tree_add_item(nhrp_tree, hf_nhrp_src_prot_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (*srcLen) {
proto_tree_add_item(nhrp_tree, hf_nhrp_src_prot_addr_bytes, tvb, offset, *srcLen, ENC_NA);
offset += *srcLen;
}
if (dstLen == 4) {
proto_tree_add_item(nhrp_tree, hf_nhrp_dst_prot_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
else if (dstLen) {
proto_tree_add_item(nhrp_tree, hf_nhrp_dst_prot_addr_bytes, tvb, offset, dstLen, ENC_NA);
offset += dstLen;
}
if (isInd) {
gboolean save_in_error_pkt;
gint pkt_len = mandEnd - offset;
proto_tree *ind_tree = proto_tree_add_subtree(tree, tvb, offset, pkt_len, ett_nhrp_indication, NULL, "Packet Causing Indication");
int dissected;
tvbuff_t *sub_tvb;
save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
sub_tvb = tvb_new_subset_remaining(tvb, offset);
if (isErr) {
_dissect_nhrp(sub_tvb, pinfo, ind_tree, TRUE, FALSE);
}
else {
if (hdr->ar_pro_type <= 0xFF) {
if (hdr->ar_pro_type == NLPID_SNAP) {
if (hdr->ar_pro_type_oui == 0x000000) {
dissected = dissector_try_uint(
ethertype_subdissector_table,
hdr->ar_pro_type_pid,
sub_tvb, pinfo, ind_tree);
} else {
if (oui_info != NULL) {
dissected = dissector_try_uint(
oui_info->table,
hdr->ar_pro_type_pid,
sub_tvb, pinfo,
ind_tree);
} else
dissected = 0;
}
} else {
dissected = dissector_try_uint(
osinl_incl_subdissector_table,
hdr->ar_pro_type, sub_tvb, pinfo,
ind_tree) ||
dissector_try_uint(
osinl_excl_subdissector_table,
hdr->ar_pro_type, sub_tvb, pinfo,
ind_tree);
}
} else if (hdr->ar_pro_type <= 0x3FF) {
dissected = 0;
} else if (hdr->ar_pro_type <= 0x04FF) {
dissected = 0;
} else if (hdr->ar_pro_type <= 0x05FF) {
dissected = 0;
} else {
dissected = dissector_try_uint(
ethertype_subdissector_table,
hdr->ar_pro_type, sub_tvb, pinfo, ind_tree);
}
if (!dissected) {
call_dissector(data_handle, sub_tvb, pinfo,
ind_tree);
}
}
pinfo->flags.in_error_pkt = save_in_error_pkt;
offset = mandEnd;
}
if (isErr && tvb_reported_length_remaining(tvb, offset)) {
expert_add_info(pinfo, tree, &ei_nhrp_ext_not_allowed);
}
dissect_cie_list(tvb, pinfo, nhrp_tree, offset, mandEnd, hdr, isReq, codeinfo);
*pOffset = mandEnd;
}
static void dissect_nhrp_ext(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
gint *pOffset,
gint extLen,
e_nhrp_hdr *hdr,
guint srcLen,
gboolean nested)
{
gint offset = *pOffset;
gint extEnd = offset + extLen;
while ((offset + 4) <= extEnd)
{
proto_tree *nhrp_tree;
gint extTypeC = tvb_get_ntohs(tvb, offset);
gint extType = extTypeC & 0x3FFF;
guint len = tvb_get_ntohs(tvb, offset+2);
if ((extType == NHRP_EXT_NAT_ADDRESS) && (len == 8)) {
nhrp_tree = proto_tree_add_subtree(tree, tvb, offset,
len + 4, ett_nhrp_ext, NULL, "Device Capabilities Extension");
}
else {
nhrp_tree = proto_tree_add_subtree(tree, tvb, offset,
len + 4, ett_nhrp_ext, NULL,
val_to_str(extType, ext_type_vals, "Unknown (%u)"));
}
proto_tree_add_boolean(nhrp_tree, hf_nhrp_ext_C, tvb, offset, 2, extTypeC);
proto_tree_add_item(nhrp_tree, hf_nhrp_ext_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nhrp_tree, hf_nhrp_ext_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (len && (extType != NHRP_EXT_NULL)) {
if ((extType == NHRP_EXT_NAT_ADDRESS) && (len == 8)) {
proto_tree *devcap_tree;
proto_item *cap_item;
proto_tree *cap_tree;
devcap_tree = proto_tree_add_subtree_format(nhrp_tree, tvb, offset, len,
ett_nhrp_devcap_ext, NULL, "Extension Data: Src is %sVPN-aware; Dst is %sVPN-aware",
tvb_get_ntohl(tvb, offset) & 1 ? "" : "non-",
tvb_get_ntohl(tvb, offset + 4) & 1 ? "" : "non-");
cap_item = proto_tree_add_item(devcap_tree, hf_nhrp_devcap_ext_srccap, tvb, offset, 4, ENC_BIG_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_nhrp_devcap_ext_srccap);
proto_tree_add_item(cap_tree, hf_nhrp_devcap_ext_srccap_V, tvb, offset, 4, ENC_BIG_ENDIAN);
cap_item = proto_tree_add_item(devcap_tree, hf_nhrp_devcap_ext_dstcap, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
cap_tree = proto_item_add_subtree(cap_item, ett_nhrp_devcap_ext_dstcap);
proto_tree_add_item(cap_tree, hf_nhrp_devcap_ext_dstcap_V, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
goto skip_switch;
}
switch (extType) {
case NHRP_EXT_RESP_ADDR:
case NHRP_EXT_FWD_RECORD:
case NHRP_EXT_REV_RECORD:
case NHRP_EXT_NAT_ADDRESS:
dissect_cie_list(tvb, pinfo, nhrp_tree,
offset, offset + len, hdr, 0, FALSE);
break;
case NHRP_EXT_AUTH:
case NHRP_EXT_MOBILE_AUTH:
if (len < (4 + srcLen)) {
proto_tree_add_expert_format(nhrp_tree, pinfo, &ei_nhrp_ext_malformed, tvb, offset, len,
"Incomplete Authentication Extension");
}
else {
proto_tree *auth_tree;
auth_tree = proto_tree_add_subtree_format(nhrp_tree, tvb, offset, len,
ett_nhrp_auth_ext, NULL, "Extension Data: SPI=%u: Data=%s", tvb_get_ntohs(tvb, offset + 2),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset + 4, len - 4));
proto_tree_add_item(auth_tree, hf_nhrp_auth_ext_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(auth_tree, hf_nhrp_auth_ext_spi, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (srcLen == 4)
proto_tree_add_item(auth_tree, hf_nhrp_auth_ext_src_addr, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
else if (srcLen) {
proto_tree_add_item(auth_tree, hf_nhrp_auth_ext_src_addr_bytes, tvb, offset + 4, srcLen, ENC_NA);
}
if (len > (4 + srcLen)) {
proto_tree_add_item(auth_tree, hf_nhrp_auth_data, tvb, offset + 4 + srcLen, len - (4 + srcLen), ENC_NA);
}
}
break;
case NHRP_EXT_VENDOR_PRIV:
if (len < 3) {
proto_tree_add_expert_format(nhrp_tree, pinfo, &ei_nhrp_ext_malformed, tvb, offset, len,
"Incomplete Vendor-Private Extension");
}
else {
proto_tree *vendor_tree;
gchar manuf[3];
tvb_memcpy(tvb, manuf, offset, 3);
vendor_tree = proto_tree_add_subtree_format(nhrp_tree, tvb, offset, len,
ett_nhrp_vendor_ext, NULL, "Extension Data: Vendor ID=%s, Data=%s", get_manuf_name(manuf),
tvb_bytes_to_str(wmem_packet_scope(), tvb, offset + 3, len - 3));
proto_tree_add_bytes_format_value(vendor_tree, hf_nhrp_vendor_ext_id, tvb,
offset, 3, manuf, "%s", get_manuf_name(manuf));
if (len > 3) {
proto_tree_add_item(vendor_tree, hf_nhrp_vendor_ext_data, tvb, offset + 3, len - 3, ENC_NA);
}
}
break;
default:
proto_tree_add_item(nhrp_tree, hf_nhrp_unknown_ext_value, tvb,
offset, len, ENC_NA);
break;
}
skip_switch:
offset += len;
}
if (!nested) {
len = tvb_reported_length_remaining(tvb, offset);
if ((extType == NHRP_EXT_NULL) && len) {
proto_tree_add_expert_format(tree, pinfo, &ei_nhrp_ext_extra, tvb, offset, len,
"Unknown Data (%d bytes)", len);
break;
}
}
}
*pOffset = extEnd;
}
static void dissect_nhrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
_dissect_nhrp(tvb, pinfo, tree, FALSE, TRUE);
}
static void _dissect_nhrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean nested, gboolean codeinfo)
{
e_nhrp_hdr hdr;
gint mandLen = 0;
gint extLen = 0;
gint offset = 0;
proto_item *ti;
proto_tree *nhrp_tree;
oui_info_t *oui_info = NULL;
guint srcLen = 0;
if (!nested) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NHRP");
col_clear(pinfo->cinfo, COL_INFO);
}
memset(&hdr, 0, sizeof(e_nhrp_hdr));
hdr.ar_op_type = tvb_get_guint8(tvb, 17);
if (!nested) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(hdr.ar_op_type, nhrp_op_type_vals,
"0x%02X - unknown"));
}
ti = proto_tree_add_protocol_format(tree, proto_nhrp, tvb, 0, -1,
"Next Hop Resolution Protocol (%s)",
val_to_str(hdr.ar_op_type, nhrp_op_type_vals, "0x%02X - unknown"));
nhrp_tree = proto_item_add_subtree(ti, ett_nhrp);
dissect_nhrp_hdr(tvb, pinfo, nhrp_tree, &offset, &mandLen, &extLen,
&oui_info, &hdr);
if (mandLen) {
dissect_nhrp_mand(tvb, pinfo, nhrp_tree, &offset, mandLen,
oui_info, &hdr, &srcLen, codeinfo);
}
if (extLen) {
dissect_nhrp_ext(tvb, pinfo, nhrp_tree, &offset, extLen, &hdr, srcLen, nested);
}
}
void
proto_register_nhrp(void)
{
static hf_register_info hf[] = {
{ &hf_nhrp_hdr_afn,
{ "Address Family Number", "nhrp.hdr.afn",
FT_UINT16, BASE_HEX_DEC, VALS(afn_vals), 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_pro_type,
{ "Protocol Type (short form)", "nhrp.hdr.pro.type",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_pro_snap_oui,
{ "Protocol Type (long form) - OUI", "nhrp.hdr.pro.snap.oui",
FT_UINT24, BASE_HEX, VALS(oui_vals), 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_pro_snap_pid,
{ "Protocol Type (long form) - PID", "nhrp.hdr.pro.snap.pid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_hopcnt,
{ "Hop Count", "nhrp.hdr.hopcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_pktsz,
{ "Packet Length", "nhrp.hdr.pktsz",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_chksum,
{ "NHRP Packet Checksum", "nhrp.hdr.chksum",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_extoff,
{ "Extension Offset", "nhrp.hdr.extoff",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_version,
{ "Version", "nhrp.hdr.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_op_type,
{ "NHRP Packet Type", "nhrp.hdr.op.type",
FT_UINT8, BASE_DEC, VALS(nhrp_op_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_shtl,
{ "Source Address Type/Len", "nhrp.hdr.shtl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_shtl_type,
{ "Type", "nhrp.hdr.shtl.type",
FT_UINT8, BASE_DEC, VALS(nhrp_shtl_type_vals), NHRP_SHTL_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nhrp_hdr_shtl_len,
{ "Length", "nhrp.hdr.shtl.len",
FT_UINT8, BASE_DEC, NULL, NHRP_SHTL_LEN_MASK,
NULL, HFILL }
},
{ &hf_nhrp_hdr_sstl,
{ "Source SubAddress Type/Len", "nhrp.hdr.sstl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_hdr_sstl_type,
{ "Type", "nhrp.hdr.sstl.type",
FT_UINT8, BASE_DEC, VALS(nhrp_shtl_type_vals), NHRP_SHTL_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nhrp_hdr_sstl_len,
{ "Length", "nhrp.hdr.sstl.len",
FT_UINT8, BASE_DEC, NULL, NHRP_SHTL_LEN_MASK,
NULL, HFILL }
},
{ &hf_nhrp_src_proto_len,
{ "Source Protocol Len", "nhrp.src.prot.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_dst_proto_len,
{ "Destination Protocol Len", "nhrp.dst.prot.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_flags,
{ "Flags", "nhrp.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_flag_Q,
{ "Is Router", "nhrp.flag.q",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_nhrp_flag_N,
{ "Expected Purge Reply", "nhrp.flag.n",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_nhrp_flag_A,
{ "Authoritative", "nhrp.flag.a",
FT_BOOLEAN, 16, NULL, 0x4000,
"A bit", HFILL }
},
{ &hf_nhrp_flag_D,
{ "Stable Association", "nhrp.flag.d",
FT_BOOLEAN, 16, NULL, 0x2000,
"D bit", HFILL }
},
{ &hf_nhrp_flag_U1,
{ "Uniqueness Bit", "nhrp.flag.u",
FT_BOOLEAN, 16, NULL, 0x1000,
"U bit", HFILL }
},
{ &hf_nhrp_flag_U2,
{ "Uniqueness Bit", "nhrp.flag.u",
FT_BOOLEAN, 16, NULL, 0x8000,
"U bit", HFILL }
},
{ &hf_nhrp_flag_S,
{ "Stable Binding", "nhrp.flag.s",
FT_BOOLEAN, 16, NULL, 0x0800,
"S bit", HFILL }
},
{ &hf_nhrp_flag_NAT,
{ "Cisco NAT Supported", "nhrp.flag.nat",
FT_BOOLEAN, 16, NULL, 0x0002,
"NAT bit", HFILL }
},
{ &hf_nhrp_request_id,
{ "Request ID", "nhrp.reqid",
FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_src_nbma_addr,
{ "Source NBMA Address", "nhrp.src.nbma.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_src_nbma_saddr,
{ "Source NBMA Sub Address", "nhrp.src.nbma.saddr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_src_prot_addr,
{ "Source Protocol Address", "nhrp.src.prot.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_dst_prot_addr,
{ "Destination Protocol Address", "nhrp.dst.prot.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_code,
{ "Code", "nhrp.code",
FT_UINT8, BASE_DEC, VALS(nhrp_cie_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_nhrp_prefix_len,
{ "Prefix Length", "nhrp.prefix",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_unused,
{ "Unused", "nhrp.unused",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_mtu,
{ "Max Transmission Unit", "nhrp.mtu",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_holding_time,
{ "Holding Time (s)", "nhrp.htime",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_cli_addr_tl,
{ "Client Address Type/Len", "nhrp.cli.addr_tl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_cli_addr_tl_type,
{ "Type", "nhrp.cli.addr_tl.type",
FT_UINT8, BASE_DEC, VALS(nhrp_shtl_type_vals), NHRP_SHTL_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nhrp_cli_addr_tl_len,
{ "Length", "nhrp.cli.addr_tl.len",
FT_UINT8, BASE_DEC, NULL, NHRP_SHTL_LEN_MASK,
NULL, HFILL }
},
{ &hf_nhrp_cli_saddr_tl,
{ "Client Sub Address Type/Len", "nhrp.cli.saddr_tl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_cli_saddr_tl_type,
{ "Type", "nhrp.cli.saddr_tl.type",
FT_UINT8, BASE_DEC, VALS(nhrp_shtl_type_vals), NHRP_SHTL_TYPE_MASK,
NULL, HFILL }
},
{ &hf_nhrp_cli_saddr_tl_len,
{ "Length", "nhrp.cli.saddr_tl.len",
FT_UINT8, BASE_DEC, NULL, NHRP_SHTL_LEN_MASK,
NULL, HFILL }
},
{ &hf_nhrp_cli_prot_len,
{ "Client Protocol Length", "nhrp.prot.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_pref,
{ "CIE Preference Value", "nhrp.pref",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_client_nbma_addr,
{ "Client NBMA Address", "nhrp.client.nbma.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_client_nbma_saddr,
{ "Client NBMA Sub Address", "nhrp.client.nbma.saddr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_client_prot_addr,
{ "Client Protocol Address", "nhrp.client.prot.addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_ext_C,
{ "Compulsory Flag", "nhrp.ext.c",
FT_BOOLEAN, 16, NULL, 0x8000,
NULL, HFILL }
},
{ &hf_nhrp_ext_type,
{ "Extension Type", "nhrp.ext.type",
FT_UINT16, BASE_HEX, NULL, 0x3FFF,
NULL, HFILL }
},
{ &hf_nhrp_ext_len,
{ "Extension length", "nhrp.ext.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_nhrp_ext_value,
{ "Extension Value", "nhrp.ext.val",
FT_UINT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_nhrp_error_code,
{ "Error Code", "nhrp.err.code",
FT_UINT16, BASE_DEC, VALS(nhrp_error_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_nhrp_error_offset,
{ "Error Offset", "nhrp.err.offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_nhrp_error_packet,
{ "Errored Packet", "nhrp.err.pkt",
FT_UINT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_nhrp_auth_ext_reserved,
{ "Reserved", "nhrp.auth_ext.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_auth_ext_spi,
{ "SPI", "nhrp.auth_ext.spi",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Security Parameter Index", HFILL }
},
{ &hf_nhrp_auth_ext_src_addr,
{ "Source Address", "nhrp.auth_ext.src_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_vendor_ext_id ,
{ "Vendor ID", "nhrp.vendor_ext.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_devcap_ext_srccap,
{ "Source Capabilities", "nhrp.devcap_ext.srccap",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_devcap_ext_srccap_V,
{ "VPN-aware", "nhrp.devcap_ext.srccap.V",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_nhrp_devcap_ext_dstcap,
{ "Destination Capabilities", "nhrp.devcap_ext.dstcap",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_devcap_ext_dstcap_V,
{ "VPN-aware", "nhrp.devcap_ext.dstcap.V",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_nhrp_unknown_ext_value,
{ "Extension Value", "nhrp.unknown_ext.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_nhrp_protocol_type, { "Protocol Type (long form)", "nhrp.protocol_type", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_client_nbma_address_bytes, { "Client NBMA Address", "nhrp.client.nbma.addr_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_client_prot_addr_bytes, { "Client Protocol Address", "nhrp.client.prot.addr_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_src_nbma_addr_bytes, { "Source NBMA Address", "nhrp.src.nbma.addr_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_src_prot_addr_bytes, { "Source Protocol Address", "nhrp.src.prot.addr_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_dst_prot_addr_bytes, { "Destination Protocol Address", "nhrp.dst.prot.addr_byets", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_auth_ext_src_addr_bytes, { "Source Address", "nhrp.auth_ext.src_addr_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_auth_data, { "Data", "nhrp.auth_ext.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nhrp_vendor_ext_data, { "Data", "nhrp.vendor_ext.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_nhrp,
&ett_nhrp_hdr,
&ett_nhrp_hdr_shtl,
&ett_nhrp_hdr_sstl,
&ett_nhrp_mand,
&ett_nhrp_ext,
&ett_nhrp_mand_flag,
&ett_nhrp_cie,
&ett_nhrp_cie_cli_addr_tl,
&ett_nhrp_cie_cli_saddr_tl,
&ett_nhrp_indication,
&ett_nhrp_auth_ext,
&ett_nhrp_vendor_ext,
&ett_nhrp_devcap_ext,
&ett_nhrp_devcap_ext_srccap,
&ett_nhrp_devcap_ext_dstcap
};
static ei_register_info ei[] = {
{ &ei_nhrp_hdr_extoff, { "nhrp.hdr.extoff.invalid", PI_MALFORMED, PI_ERROR, "Extension offset is less than the fixed header length", EXPFILL }},
{ &ei_nhrp_ext_not_allowed, { "nhrp.ext.not_allowed", PI_MALFORMED, PI_ERROR, "Extensions not allowed per RFC2332 section 5.2.7", EXPFILL }},
{ &ei_nhrp_ext_malformed, { "nhrp.ext.malformed", PI_MALFORMED, PI_ERROR, "Incomplete Authentication Extension", EXPFILL }},
{ &ei_nhrp_ext_extra, { "nhrp.ext.extra", PI_MALFORMED, PI_ERROR, "Superfluous data follows End Extension", EXPFILL }},
};
expert_module_t* expert_nhrp;
proto_nhrp = proto_register_protocol("NBMA Next Hop Resolution Protocol", "NHRP", "nhrp");
proto_register_field_array(proto_nhrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_nhrp = expert_register_protocol(proto_nhrp);
expert_register_field_array(expert_nhrp, ei, array_length(ei));
}
void
proto_reg_handoff_nhrp(void)
{
dissector_handle_t nhrp_handle;
data_handle = find_dissector("data");
osinl_incl_subdissector_table = find_dissector_table("osinl.incl");
osinl_excl_subdissector_table = find_dissector_table("osinl.excl");
ethertype_subdissector_table = find_dissector_table("ethertype");
nhrp_handle = create_dissector_handle(dissect_nhrp, proto_nhrp);
dissector_add_uint("ip.proto", IP_PROTO_NARP, nhrp_handle);
dissector_add_uint("gre.proto", GRE_NHRP, nhrp_handle);
dissector_add_uint("llc.iana_pid", IANA_PID_MARS_NHRP_CONTROL, nhrp_handle);
}
