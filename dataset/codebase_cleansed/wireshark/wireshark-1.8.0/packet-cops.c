static int cops_tag_cls2syntax ( guint tag, guint cls ) {
COPS_CNV *cnv;
cnv = CopsCnv;
while (cnv->syntax != -1)
{
if (cnv->tag == tag && cnv->class == cls)
{
return *(cnv->hfidp);
}
cnv++;
}
return hf_cops_epd_unknown;
}
static void
dissect_cops(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, cops_desegment, 8,
get_cops_pdu_len, dissect_cops_pdu);
}
static guint
get_cops_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset + 4);
}
static void
dissect_cops_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 op_code;
guint16 client_type;
int object_len;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "COPS");
col_clear(pinfo->cinfo, COL_INFO);
op_code = tvb_get_guint8(tvb, 1);
col_add_fstr(pinfo->cinfo, COL_INFO, "COPS %s",
val_to_str(op_code, cops_op_code_vals, "Unknown Op Code"));
client_type = tvb_get_ntohs(tvb, 2);
if (tree) {
proto_item *ti, *tv;
proto_tree *cops_tree, *ver_flags_tree;
guint32 msg_len;
guint32 offset = 0;
guint8 ver_flags;
gint garbage;
ti = proto_tree_add_item(tree, proto_cops, tvb, offset, -1, ENC_NA);
cops_tree = proto_item_add_subtree(ti, ett_cops);
ver_flags = tvb_get_guint8(tvb, offset);
tv = proto_tree_add_uint_format(cops_tree, hf_cops_ver_flags, tvb, offset, 1,
ver_flags, "Version: %u, Flags: %s",
hi_nibble(ver_flags),
val_to_str(lo_nibble(ver_flags), cops_flags_vals, "Unknown"));
ver_flags_tree = proto_item_add_subtree(tv, ett_cops_ver_flags);
proto_tree_add_uint(ver_flags_tree, hf_cops_version, tvb, offset, 1, ver_flags);
proto_tree_add_uint(ver_flags_tree, hf_cops_flags, tvb, offset, 1, ver_flags);
offset++;
proto_tree_add_item(cops_tree, hf_cops_op_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset ++;
proto_tree_add_item(cops_tree, hf_cops_client_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
msg_len = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(cops_tree, hf_cops_msg_len, tvb, offset, 4, msg_len);
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) >= COPS_OBJECT_HDR_SIZE) {
object_len = dissect_cops_object(tvb, pinfo, op_code, offset, cops_tree, client_type);
if (object_len < 0)
return;
offset += object_len;
}
garbage = tvb_length_remaining(tvb, offset);
if (garbage > 0)
proto_tree_add_text(cops_tree, tvb, offset, garbage,
"Trailing garbage: %d byte%s", garbage,
plurality(garbage, "", "s"));
}
}
static const char *cops_c_type_to_str(guint8 c_num, guint8 c_type)
{
switch (c_num) {
case COPS_OBJ_HANDLE:
if (c_type == 1)
return "Client Handle";
break;
case COPS_OBJ_IN_INT:
case COPS_OBJ_OUT_INT:
if (c_type == 1)
return "IPv4 Address + Interface";
else if (c_type == 2)
return "IPv6 Address + Interface";
break;
case COPS_OBJ_DECISION:
case COPS_OBJ_LPDPDECISION:
if (c_type == 1)
return "Decision Flags (Mandatory)";
else if (c_type == 2)
return "Stateless Data";
else if (c_type == 3)
return "Replacement Data";
else if (c_type == 4)
return "Client Specific Decision Data";
else if (c_type == 5)
return "Named Decision Data";
break;
case COPS_OBJ_CLIENTSI:
if (c_type == 1)
return "Signaled ClientSI";
else if (c_type == 2)
return "Named ClientSI";
break;
case COPS_OBJ_KATIMER:
if (c_type == 1)
return "Keep-alive timer value";
break;
case COPS_OBJ_PDPREDIRADDR:
case COPS_OBJ_LASTPDPADDR:
if (c_type == 1)
return "IPv4 Address + TCP Port";
else if (c_type == 2)
return "IPv6 Address + TCP Port";
break;
case COPS_OBJ_ACCTTIMER:
if (c_type == 1)
return "Accounting timer value";
break;
case COPS_OBJ_INTEGRITY:
if (c_type == 1)
return "HMAC digest";
break;
}
return "";
}
static int dissect_cops_object(tvbuff_t *tvb, packet_info *pinfo, guint8 op_code, guint32 offset, proto_tree *tree, guint16 client_type)
{
int object_len, contents_len;
guint8 c_num, c_type;
proto_item *ti;
proto_tree *obj_tree;
const char *type_str;
object_len = tvb_get_ntohs(tvb, offset);
if (object_len < COPS_OBJECT_HDR_SIZE) {
proto_tree_add_text(tree, tvb, offset, 2,
"Bad COPS object length: %u, should be at least %u",
object_len, COPS_OBJECT_HDR_SIZE);
return -1;
}
c_num = tvb_get_guint8(tvb, offset + 2);
c_type = tvb_get_guint8(tvb, offset + 3);
ti = proto_tree_add_uint_format(tree, hf_cops_obj_c_num, tvb, offset, object_len, c_num,
"%s: %s", val_to_str(c_num, cops_c_num_vals, "Unknown"),
cops_c_type_to_str(c_num, c_type));
obj_tree = proto_item_add_subtree(ti, ett_cops_obj);
proto_tree_add_uint(obj_tree, hf_cops_obj_len, tvb, offset, 2, object_len);
offset += 2;
proto_tree_add_uint(obj_tree, hf_cops_obj_c_num, tvb, offset, 1, c_num);
offset++;
type_str = cops_c_type_to_str(c_num, c_type);
proto_tree_add_uint_format_value(obj_tree, hf_cops_obj_c_type, tvb, offset, 1, c_type,
"%s%s%u%s",
type_str,
strlen(type_str) ? " (" : "",
c_type,
strlen(type_str) ? ")" : "");
offset++;
contents_len = object_len - COPS_OBJECT_HDR_SIZE;
dissect_cops_object_data(tvb, pinfo, offset, obj_tree, op_code, client_type, c_num, c_type, contents_len);
if (object_len % sizeof (guint32))
object_len += (sizeof (guint32) - object_len % sizeof (guint32));
return object_len;
}
static void dissect_cops_pr_objects(tvbuff_t *tvb, packet_info *pinfo, guint32 offset, proto_tree *tree, int pr_len,
oid_info_t** oid_info_p, guint32** pprid_subids_p, guint* pprid_subids_len_p)
{
int object_len, contents_len;
guint8 s_num, s_type;
const char *type_str;
int ret;
proto_tree *cops_pr_tree, *obj_tree;
proto_item *ti;
cops_pr_tree = proto_item_add_subtree(tree, ett_cops_pr_obj);
while (pr_len >= COPS_OBJECT_HDR_SIZE) {
object_len = tvb_get_ntohs(tvb, offset);
if (object_len < COPS_OBJECT_HDR_SIZE) {
proto_tree_add_text(tree, tvb, offset, 2,
"Bad COPS PR object length: %u, should be at least %u",
object_len, COPS_OBJECT_HDR_SIZE);
return;
}
s_num = tvb_get_guint8(tvb, offset + 2);
ti = proto_tree_add_uint_format(cops_pr_tree, hf_cops_obj_s_num, tvb, offset, object_len, s_num,
"%s", val_to_str(s_num, cops_s_num_vals, "Unknown"));
obj_tree = proto_item_add_subtree(ti, ett_cops_pr_obj);
proto_tree_add_uint(obj_tree, hf_cops_obj_len, tvb, offset, 2, object_len);
offset += 2;
pr_len -= 2;
proto_tree_add_uint(obj_tree, hf_cops_obj_s_num, tvb, offset, 1, s_num);
offset++;
pr_len--;
s_type = tvb_get_guint8(tvb, offset);
type_str = val_to_str(s_type, cops_s_type_vals, "Unknown");
proto_tree_add_text(obj_tree, tvb, offset, 1, "S-Type: %s%s%u%s",
type_str,
strlen(type_str) ? " (" : "",
s_type,
strlen(type_str) ? ")" : "");
offset++;
pr_len--;
contents_len = object_len - COPS_OBJECT_HDR_SIZE;
ret = dissect_cops_pr_object_data(tvb, pinfo, offset, obj_tree, s_num, s_type, contents_len,
oid_info_p, pprid_subids_p, pprid_subids_len_p);
if (ret < 0)
break;
if (object_len % sizeof (guint32))
object_len += (sizeof (guint32) - object_len % sizeof (guint32));
pr_len -= object_len - COPS_OBJECT_HDR_SIZE;
offset += object_len - COPS_OBJECT_HDR_SIZE;
}
}
static void dissect_cops_object_data(tvbuff_t *tvb, packet_info *pinfo, guint32 offset, proto_tree *tree,
guint8 op_code, guint16 client_type, guint8 c_num, guint8 c_type, int len)
{
proto_item *ti;
proto_tree *r_type_tree, *itf_tree, *reason_tree, *dec_tree, *error_tree, *clientsi_tree, *pdp_tree;
guint16 r_type, m_type, reason, reason_sub, cmd_code, cmd_flags, error, error_sub, tcp_port;
guint32 ipv4addr, ifindex;
struct e_in6_addr ipv6addr;
oid_info_t* oid_info = NULL;
guint32* pprid_subids = NULL;
guint pprid_subids_len = 0;
switch (c_num) {
case COPS_OBJ_CONTEXT:
r_type = tvb_get_ntohs(tvb, offset);
m_type = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: R-Type: %s, M-Type: %u",
val_to_str(r_type, cops_r_type_vals, "Unknown"),
m_type);
r_type_tree = proto_item_add_subtree(ti, ett_cops_r_type_flags);
proto_tree_add_uint(r_type_tree, hf_cops_r_type_flags, tvb, offset, 2, r_type);
offset += 2;
proto_tree_add_uint(r_type_tree, hf_cops_m_type_flags, tvb, offset, 2, m_type);
break;
case COPS_OBJ_IN_INT:
case COPS_OBJ_OUT_INT:
if (c_type == 1) {
ipv4addr = tvb_get_ipv4(tvb, offset);
ifindex = tvb_get_ntohl(tvb, offset + 4);
ti = proto_tree_add_text(tree, tvb, offset, 8, "Contents: IPv4 address %s, ifIndex: %u",
ip_to_str((guint8 *)&ipv4addr), ifindex);
itf_tree = proto_item_add_subtree(ti, ett_cops_itf);
proto_tree_add_ipv4(itf_tree,
(c_num == COPS_OBJ_IN_INT) ? hf_cops_in_int_ipv4 : hf_cops_out_int_ipv4,
tvb, offset, 4, ipv4addr);
offset += 4;
} else if (c_type == 2) {
tvb_get_ipv6(tvb, offset, &ipv6addr);
ifindex = tvb_get_ntohl(tvb, offset + sizeof ipv6addr);
ti = proto_tree_add_text(tree, tvb, offset, 20, "Contents: IPv6 address %s, ifIndex: %u",
ip6_to_str(&ipv6addr), ifindex);
itf_tree = proto_item_add_subtree(ti, ett_cops_itf);
proto_tree_add_ipv6(itf_tree,
(c_num == COPS_OBJ_IN_INT) ? hf_cops_in_int_ipv6 : hf_cops_out_int_ipv6,
tvb, offset, 16, (guint8 *)&ipv6addr);
offset += 16;
} else {
break;
}
proto_tree_add_uint(itf_tree, hf_cops_int_ifindex, tvb, offset, 4, ifindex);
break;
case COPS_OBJ_REASON:
reason = tvb_get_ntohs(tvb, offset);
reason_sub = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: Reason-Code: %s, Reason Sub-code: 0x%04x",
val_to_str(reason, cops_reason_vals, "<Unknown value>"), reason_sub);
reason_tree = proto_item_add_subtree(ti, ett_cops_reason);
proto_tree_add_uint(reason_tree, hf_cops_reason, tvb, offset, 2, reason);
offset += 2;
if (reason == 13) {
proto_tree_add_text(reason_tree, tvb, offset, 2, "Reason Sub-code: "
"Unknown object's C-Num %u, C-Type %u",
tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset + 1));
} else
proto_tree_add_uint(reason_tree, hf_cops_reason_sub, tvb, offset, 2, reason_sub);
break;
case COPS_OBJ_DECISION:
case COPS_OBJ_LPDPDECISION:
if (c_type == 1) {
cmd_code = tvb_get_ntohs(tvb, offset);
cmd_flags = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: Command-Code: %s, Flags: %s",
val_to_str(cmd_code, cops_dec_cmd_code_vals, "<Unknown value>"),
val_to_str(cmd_flags, cops_dec_cmd_flag_vals, "<Unknown flag>"));
dec_tree = proto_item_add_subtree(ti, ett_cops_decision);
proto_tree_add_uint(dec_tree, hf_cops_dec_cmd_code, tvb, offset, 2, cmd_code);
offset += 2;
proto_tree_add_uint(dec_tree, hf_cops_dec_flags, tvb, offset, 2, cmd_flags);
} else if (c_type == 5) {
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: %d bytes", len);
dec_tree = proto_item_add_subtree(ti, ett_cops_decision);
dissect_cops_pr_objects(tvb, pinfo, offset, dec_tree, len, &oid_info, &pprid_subids, &pprid_subids_len);
}
if (client_type == COPS_CLIENT_PC_DQOS && c_type == 4) {
cops_analyze_packetcable_dqos_obj(tvb, pinfo, tree, op_code, offset);
} else if (client_type == COPS_CLIENT_PC_MM && c_type == 4) {
cops_analyze_packetcable_mm_obj(tvb, pinfo, tree, op_code, offset);
}
break;
case COPS_OBJ_ERROR:
if (c_type != 1)
break;
error = tvb_get_ntohs(tvb, offset);
error_sub = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: Error-Code: %s, Error Sub-code: 0x%04x",
val_to_str(error, cops_error_vals, "<Unknown value>"), error_sub);
error_tree = proto_item_add_subtree(ti, ett_cops_error);
proto_tree_add_uint(error_tree, hf_cops_error, tvb, offset, 2, error);
offset += 2;
if (error == 13) {
proto_tree_add_text(error_tree, tvb, offset, 2, "Error Sub-code: "
"Unknown object's C-Num %u, C-Type %u",
tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset + 1));
} else
proto_tree_add_uint(error_tree, hf_cops_error_sub, tvb, offset, 2, error_sub);
break;
case COPS_OBJ_CLIENTSI:
if (client_type == COPS_CLIENT_PC_DQOS && c_type == 1) {
cops_analyze_packetcable_dqos_obj(tvb, pinfo, tree, op_code, offset);
break;
} else if (client_type == COPS_CLIENT_PC_MM && c_type == 1) {
cops_analyze_packetcable_mm_obj(tvb, pinfo, tree, op_code, offset);
break;
}
if (c_type != 2)
break;
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: %d bytes", len);
clientsi_tree = proto_item_add_subtree(ti, ett_cops_clientsi);
dissect_cops_pr_objects(tvb, pinfo, offset, clientsi_tree, len, &oid_info, &pprid_subids, &pprid_subids_len);
break;
case COPS_OBJ_KATIMER:
if (c_type != 1)
break;
proto_tree_add_item(tree, hf_cops_katimer, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (tvb_get_ntohs(tvb, offset + 2) == 0)
proto_tree_add_text(tree, tvb, offset, 0, "Value of zero implies infinity.");
break;
case COPS_OBJ_PEPID:
if (c_type != 1)
break;
if (tvb_strnlen(tvb, offset, len) == -1) {
proto_item *pep_ti;
pep_ti = proto_tree_add_text(tree, tvb, offset, len, "PEP Id is not a NULL terminated ASCII string");
expert_add_info_format(pinfo, pep_ti, PI_MALFORMED, PI_NOTE,
"PEP Id is not a NULL terminated ASCII string");
PROTO_ITEM_SET_GENERATED(pep_ti);
}
else
proto_tree_add_item(tree, hf_cops_pepid, tvb, offset,
tvb_strnlen(tvb, offset, len) + 1, ENC_ASCII|ENC_NA);
break;
case COPS_OBJ_REPORT_TYPE:
if (c_type != 1)
break;
proto_tree_add_item(tree, hf_cops_report_type, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case COPS_OBJ_PDPREDIRADDR:
case COPS_OBJ_LASTPDPADDR:
if (c_type == 1) {
ipv4addr = tvb_get_ipv4(tvb, offset);
tcp_port = tvb_get_ntohs(tvb, offset + 4 + 2);
ti = proto_tree_add_text(tree, tvb, offset, 8, "Contents: IPv4 address %s, TCP Port Number: %u",
ip_to_str((guint8 *)&ipv4addr), tcp_port);
pdp_tree = proto_item_add_subtree(ti, ett_cops_pdp);
proto_tree_add_ipv4(pdp_tree,
(c_num == COPS_OBJ_PDPREDIRADDR) ? hf_cops_pdprediraddr_ipv4 : hf_cops_lastpdpaddr_ipv4,
tvb, offset, 4, ipv4addr);
offset += 4;
} else if (c_type == 2) {
tvb_get_ipv6(tvb, offset, &ipv6addr);
tcp_port = tvb_get_ntohs(tvb, offset + sizeof ipv6addr + 2);
ti = proto_tree_add_text(tree, tvb, offset, 20, "Contents: IPv6 address %s, TCP Port Number: %u",
ip6_to_str(&ipv6addr), tcp_port);
pdp_tree = proto_item_add_subtree(ti, ett_cops_pdp);
proto_tree_add_ipv6(pdp_tree,
(c_num == COPS_OBJ_PDPREDIRADDR) ? hf_cops_pdprediraddr_ipv6 : hf_cops_lastpdpaddr_ipv6,
tvb, offset, 16, (guint8 *)&ipv6addr);
offset += 16;
} else {
break;
}
offset += 2;
proto_tree_add_uint(pdp_tree, hf_cops_pdp_tcp_port, tvb, offset, 2, tcp_port);
break;
case COPS_OBJ_ACCTTIMER:
if (c_type != 1)
break;
proto_tree_add_item(tree, hf_cops_accttimer, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (tvb_get_ntohs(tvb, offset + 2) == 0)
proto_tree_add_text(tree, tvb, offset, 0, "Value of zero means "
"there SHOULD be no unsolicited accounting updates.");
break;
case COPS_OBJ_INTEGRITY:
if (c_type != 1)
break;
proto_tree_add_item(tree, hf_cops_key_id, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cops_seq_num, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, offset + 8 , len - 8, "Contents: Keyed Message Digest");
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "Contents: %d bytes", len);
break;
}
}
static guint redecode_oid(guint32* pprid_subids, guint pprid_subids_len, guint8* encoded_subids, guint encoded_len, guint32** subids_p) {
guint i;
guint n = 0;
guint32 subid = 0;
guint32* subids;
guint32* subid_overflow;
for (i=0; i<encoded_len; i++) { if (! (encoded_subids[i] & 0x80 )) n++; }
*subids_p = subids = ep_alloc(sizeof(guint32)*(n+pprid_subids_len));
subid_overflow = subids+n+pprid_subids_len;
for (i=0;i<pprid_subids_len;i++) subids[i] = pprid_subids[i];
subids += pprid_subids_len;
for (i=0; i<encoded_len; i++){
guint8 byte = encoded_subids[i];
subid <<= 7;
subid |= byte & 0x7F;
if (byte & 0x80) {
continue;
}
DISSECTOR_ASSERT(subids < subid_overflow);
*subids++ = subid;
subid = 0;
}
return pprid_subids_len+n;
}
static int dissect_cops_pr_object_data(tvbuff_t *tvb, packet_info *pinfo, guint32 offset, proto_tree *tree,
guint8 s_num, guint8 s_type, int len,
oid_info_t** oid_info_p, guint32** pprid_subids, guint* pprid_subids_len) {
proto_item *ti;
proto_tree *asn_tree, *gperror_tree, *cperror_tree;
guint16 gperror=0, gperror_sub=0, cperror=0, cperror_sub=0;
asn1_ctx_t actx;
memset(&actx,0,sizeof(actx));
actx.pinfo = pinfo;
switch (s_num){
case COPS_OBJ_PPRID: {
tvbuff_t* oid_tvb = NULL;
if (s_type != 1)
break;
ti = proto_tree_add_text(tree, tvb, offset, len, "Contents:");
asn_tree = proto_item_add_subtree(ti, ett_cops_asn1);
dissect_ber_object_identifier(FALSE, &actx, asn_tree, tvb, offset, hf_cops_pprid_oid, &oid_tvb);
if (oid_tvb) {
guint encoid_len = tvb_length_remaining(oid_tvb,0);
guint8* encoid = ep_tvb_memdup(oid_tvb,0,encoid_len);
(*pprid_subids_len) = oid_encoded2subid(encoid, encoid_len, pprid_subids);
}
break;
}
case COPS_OBJ_PRID: {
guint32* subids;
guint subids_len;
guint matched;
guint left;
gint8 ber_class;
gboolean ber_pc;
gint32 ber_tag;
guint encoid_len;
guint8* encoid;
oid_info_t* oid_info;
if (s_type != 1) break;
ti=proto_tree_add_text(tree, tvb, offset, len, "Contents:");
asn_tree = proto_item_add_subtree(ti, ett_cops_asn1);
offset = get_ber_identifier(tvb, offset, &ber_class, &ber_pc, &ber_tag);
offset = get_ber_length(tvb, offset, &encoid_len, NULL);
encoid = ep_tvb_memdup(tvb,offset,encoid_len);
if (*pprid_subids) {
subids_len = redecode_oid(*pprid_subids, *pprid_subids_len, encoid, encoid_len, &subids);
encoid_len = oid_subid2encoded(subids_len, subids, &encoid);
} else {
subids_len = oid_encoded2subid(encoid, encoid_len, &subids);
}
proto_tree_add_oid(asn_tree,hf_cops_prid_oid,tvb,offset,encoid_len,encoid);
oid_info = oid_get(subids_len, subids, &matched, &left);
if (left <= 1 && oid_info->kind == OID_KIND_ROW) {
*oid_info_p = oid_info;
} else {
*oid_info_p = NULL;
}
break;
}
case COPS_OBJ_EPD: {
oid_info_t* oid_info;
guint end_offset = offset + len;
if (s_type != 1) break;
ti = proto_tree_add_text(tree, tvb, offset, len, "Contents:");
asn_tree = proto_item_add_subtree(ti, ett_cops_asn1);
if(*oid_info_p) {
if ((*oid_info_p)->kind == OID_KIND_ROW) {
oid_info = emem_tree_lookup32((*oid_info_p)->children,1);
} else {
oid_info = NULL;
}
} else {
oid_info = NULL;
}
while(offset < end_offset) {
gint8 ber_class;
gboolean ber_pc;
gint32 ber_tag;
guint32 ber_length;
gboolean ber_ind;
int hfid;
offset = get_ber_identifier(tvb, offset, &ber_class, &ber_pc, &ber_tag);
offset = get_ber_length(tvb, offset, &ber_length, &ber_ind);
if (oid_info) {
hfid = oid_info->value_hfid;
oid_info = emem_tree_lookup32((*oid_info_p)->children,oid_info->subid+1);
} else
hfid = cops_tag_cls2syntax( ber_tag, ber_class );
switch (proto_registrar_get_ftype(hfid)) {
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
case FT_INT64:
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
case FT_UINT64:
case FT_BOOLEAN:
case FT_FLOAT:
case FT_DOUBLE:
case FT_IPv4:
proto_tree_add_item(asn_tree,hfid,tvb,offset,ber_length,ENC_BIG_ENDIAN);
break;
case FT_STRING:
proto_tree_add_item(asn_tree,hfid,tvb,offset,ber_length,ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_item(asn_tree,hfid,tvb,offset,ber_length,ENC_NA);
break;
}
offset += ber_length;
}
(*oid_info_p) = NULL;
break;
}
case COPS_OBJ_ERRPRID: {
if (s_type != 1) break;
ti = proto_tree_add_text(tree, tvb, offset, len, "Contents:");
asn_tree = proto_item_add_subtree(ti, ett_cops_asn1);
dissect_ber_object_identifier(FALSE, &actx, asn_tree, tvb, offset, hf_cops_errprid_oid, NULL);
break;
}
case COPS_OBJ_GPERR:
if (s_type != 1)
break;
gperror = tvb_get_ntohs(tvb, offset);
gperror_sub = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: Error-Code: %s, Error Sub-code: 0x%04x",
val_to_str(gperror, cops_gperror_vals, "<Unknown value>"), gperror_sub);
gperror_tree = proto_item_add_subtree(ti, ett_cops_gperror);
proto_tree_add_uint(gperror_tree, hf_cops_gperror, tvb, offset, 2, gperror);
offset += 2;
if (gperror == 13) {
proto_tree_add_text(gperror_tree, tvb, offset, 2, "Error Sub-code: "
"Unknown object's C-Num %u, C-Type %u",
tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset + 1));
} else
proto_tree_add_uint(gperror_tree, hf_cops_gperror_sub, tvb, offset, 2, gperror_sub);
break;
case COPS_OBJ_CPERR:
if (s_type != 1)
break;
cperror = tvb_get_ntohs(tvb, offset);
cperror_sub = tvb_get_ntohs(tvb, offset + 2);
ti = proto_tree_add_text(tree, tvb, offset, 4, "Contents: Error-Code: %s, Error Sub-code: 0x%04x",
val_to_str(cperror, cops_cperror_vals, "<Unknown value>"), cperror_sub);
cperror_tree = proto_item_add_subtree(ti, ett_cops_cperror);
proto_tree_add_uint(cperror_tree, hf_cops_cperror, tvb, offset, 2, cperror);
offset += 2;
if (cperror == 13) {
proto_tree_add_text(cperror_tree, tvb, offset, 2, "Error Sub-code: "
"Unknown object's S-Num %u, C-Type %u",
tvb_get_guint8(tvb, offset), tvb_get_guint8(tvb, offset + 1));
} else
proto_tree_add_uint(cperror_tree, hf_cops_cperror_sub, tvb, offset, 2, cperror_sub);
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "Contents: %d bytes", len);
break;
}
return 0;
}
void proto_register_cops(void)
{
static hf_register_info hf[] = {
{ &hf_cops_ver_flags,
{ "Version and Flags", "cops.ver_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Version and Flags in COPS Common Header", HFILL }
},
{ &hf_cops_version,
{ "Version", "cops.version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Version in COPS Common Header", HFILL }
},
{ &hf_cops_flags,
{ "Flags", "cops.flags",
FT_UINT8, BASE_HEX, VALS(cops_flags_vals), 0x0F,
"Flags in COPS Common Header", HFILL }
},
{ &hf_cops_op_code,
{ "Op Code", "cops.op_code",
FT_UINT8, BASE_DEC, VALS(cops_op_code_vals), 0x0,
"Op Code in COPS Common Header", HFILL }
},
{ &hf_cops_client_type,
{ "Client Type", "cops.client_type",
FT_UINT16, BASE_DEC, VALS(cops_client_type_vals), 0x0,
"Client Type in COPS Common Header", HFILL }
},
{ &hf_cops_msg_len,
{ "Message Length", "cops.msg_len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Message Length in COPS Common Header", HFILL }
},
{ &hf_cops_obj_len,
{ "Object Length", "cops.obj.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Object Length in COPS Object Header", HFILL }
},
{ &hf_cops_obj_c_num,
{ "C-Num", "cops.c_num",
FT_UINT8, BASE_DEC, VALS(cops_c_num_vals), 0x0,
"C-Num in COPS Object Header", HFILL }
},
{ &hf_cops_obj_c_type,
{ "C-Type", "cops.c_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
"C-Type in COPS Object Header", HFILL }
},
{ &hf_cops_obj_s_num,
{ "S-Num", "cops.s_num",
FT_UINT8, BASE_DEC, VALS(cops_s_num_vals), 0x0,
"S-Num in COPS-PR Object Header", HFILL }
},
{ &hf_cops_obj_s_type,
{ "S-Type", "cops.s_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
"S-Type in COPS-PR Object Header", HFILL }
},
{ &hf_cops_r_type_flags,
{ "R-Type", "cops.context.r_type",
FT_UINT16, BASE_HEX, VALS(cops_r_type_vals), 0xFFFF,
"R-Type in COPS Context Object", HFILL }
},
{ &hf_cops_m_type_flags,
{ "M-Type", "cops.context.m_type",
FT_UINT16, BASE_HEX, NULL, 0xFFFF,
"M-Type in COPS Context Object", HFILL }
},
{ &hf_cops_in_int_ipv4,
{ "IPv4 address", "cops.in-int.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPv4 address in COPS IN-Int object", HFILL }
},
{ &hf_cops_in_int_ipv6,
{ "IPv6 address", "cops.in-int.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPv6 address in COPS IN-Int object", HFILL }
},
{ &hf_cops_out_int_ipv4,
{ "IPv4 address", "cops.out-int.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPv4 address in COPS OUT-Int object", HFILL }
},
{ &hf_cops_out_int_ipv6,
{ "IPv6 address", "cops.out-int.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPv6 address in COPS OUT-Int", HFILL }
},
{ &hf_cops_int_ifindex,
{ "ifIndex", "cops.in-out-int.ifindex",
FT_UINT32, BASE_DEC, NULL, 0x0,
"If SNMP is supported, corresponds to MIB-II ifIndex", HFILL }
},
{ &hf_cops_reason,
{ "Reason", "cops.reason",
FT_UINT16, BASE_DEC, VALS(cops_reason_vals), 0,
"Reason in Reason object", HFILL }
},
{ &hf_cops_reason_sub,
{ "Reason Sub-code", "cops.reason_sub",
FT_UINT16, BASE_HEX, NULL, 0,
"Reason Sub-code in Reason object", HFILL }
},
{ &hf_cops_dec_cmd_code,
{ "Command-Code", "cops.decision.cmd",
FT_UINT16, BASE_DEC, VALS(cops_dec_cmd_code_vals), 0,
"Command-Code in Decision/LPDP Decision object", HFILL }
},
{ &hf_cops_dec_flags,
{ "Flags", "cops.decision.flags",
FT_UINT16, BASE_HEX, VALS(cops_dec_cmd_flag_vals), 0xffff,
"Flags in Decision/LPDP Decision object", HFILL }
},
{ &hf_cops_error,
{ "Error", "cops.error",
FT_UINT16, BASE_DEC, VALS(cops_error_vals), 0,
"Error in Error object", HFILL }
},
{ &hf_cops_error_sub,
{ "Error Sub-code", "cops.error_sub",
FT_UINT16, BASE_HEX, NULL, 0,
"Error Sub-code in Error object", HFILL }
},
{ &hf_cops_katimer,
{ "Contents: KA Timer Value", "cops.katimer.value",
FT_UINT16, BASE_DEC, NULL, 0,
"Keep-Alive Timer Value in KATimer object", HFILL }
},
{ &hf_cops_pepid,
{ "Contents: PEP Id", "cops.pepid.id",
FT_STRING, BASE_NONE, NULL, 0,
"PEP Id in PEPID object", HFILL }
},
{ &hf_cops_report_type,
{ "Contents: Report-Type", "cops.report_type",
FT_UINT16, BASE_DEC, VALS(cops_report_type_vals), 0,
"Report-Type in Report-Type object", HFILL }
},
{ &hf_cops_pdprediraddr_ipv4,
{ "IPv4 address", "cops.pdprediraddr.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPv4 address in COPS PDPRedirAddr object", HFILL }
},
{ &hf_cops_pdprediraddr_ipv6,
{ "IPv6 address", "cops.pdprediraddr.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPv6 address in COPS PDPRedirAddr object", HFILL }
},
{ &hf_cops_lastpdpaddr_ipv4,
{ "IPv4 address", "cops.lastpdpaddr.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
"IPv4 address in COPS LastPDPAddr object", HFILL }
},
{ &hf_cops_lastpdpaddr_ipv6,
{ "IPv6 address", "cops.lastpdpaddr.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
"IPv6 address in COPS LastPDPAddr object", HFILL }
},
{ &hf_cops_pdp_tcp_port,
{ "TCP Port Number", "cops.pdp.tcp_port",
FT_UINT32, BASE_DEC, NULL, 0x0,
"TCP Port Number of PDP in PDPRedirAddr/LastPDPAddr object", HFILL }
},
{ &hf_cops_accttimer,
{ "Contents: ACCT Timer Value", "cops.accttimer.value",
FT_UINT16, BASE_DEC, NULL, 0,
"Accounting Timer Value in AcctTimer object", HFILL }
},
{ &hf_cops_key_id,
{ "Contents: Key ID", "cops.integrity.key_id",
FT_UINT32, BASE_DEC, NULL, 0,
"Key ID in Integrity object", HFILL }
},
{ &hf_cops_seq_num,
{ "Contents: Sequence Number", "cops.integrity.seq_num",
FT_UINT32, BASE_DEC, NULL, 0,
"Sequence Number in Integrity object", HFILL }
},
{ &hf_cops_gperror,
{ "Error", "cops.gperror",
FT_UINT16, BASE_DEC, VALS(cops_gperror_vals), 0,
"Error in Error object", HFILL }
},
{ &hf_cops_gperror_sub,
{ "Error Sub-code", "cops.gperror_sub",
FT_UINT16, BASE_HEX, NULL, 0,
"Error Sub-code in Error object", HFILL }
},
{ &hf_cops_cperror,
{ "Error", "cops.cperror",
FT_UINT16, BASE_DEC, VALS(cops_cperror_vals), 0,
"Error in Error object", HFILL }
},
{ &hf_cops_cperror_sub,
{ "Error Sub-code", "cops.cperror_sub",
FT_UINT16, BASE_HEX, NULL, 0,
"Error Sub-code in Error object", HFILL }
},
{ &hf_cops_prid_oid, { "PRID Instance Identifier", "cops.prid.instance_id", FT_OID, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_pprid_oid, { "Prefix Identifier", "cops.pprid.prefix_id", FT_OID, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_errprid_oid, { "ErrorPRID Instance Identifier", "cops.errprid.instance_id", FT_OID, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_unknown, { "EPD Unknown Data", "cops.epd.unknown", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_null, { "EPD Null Data", "cops.epd.null", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_int, { "EPD Integer Data", "cops.epd.int", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_octets, { "EPD Octet String Data", "cops.epd.octets", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_oid, { "EPD OID Data", "cops.epd.oid", FT_OID, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_ipv4, { "EPD IPAddress Data", "cops.epd.ipv4", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_u32, { "EPD Unsigned32 Data", "cops.epd.unsigned32", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_ticks, { "EPD TimeTicks Data", "cops.epd.timeticks", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_opaque, { "EPD Opaque Data", "cops.epd.opaque", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_i64, { "EPD Inetger64 Data", "cops.epd.integer64", FT_INT64, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_cops_epd_u64, { "EPD Unsigned64 Data", "cops.epd.unsigned64", FT_UINT64, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_cops_subtree,
{ "Object Subtree", "cops.pc_subtree",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_cops_pc_ds_field,
{ "DS Field (DSCP or TOS)", "cops.pc_ds_field",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_direction,
{ "Direction", "cops.pc_direction",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_gate_spec_flags,
{ "Flags", "cops.pc_gate_spec_flags",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_protocol_id,
{ "Protocol ID", "cops.pc_protocol_id",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_session_class,
{ "Session Class", "cops.pc_session_class",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_algorithm,
{ "Algorithm", "cops.pc_algorithm",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_cmts_ip_port,
{ "CMTS IP Port", "cops.pc_cmts_ip_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_prks_ip_port,
{ "PRKS IP Port", "cops.pc_prks_ip_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_srks_ip_port,
{ "SRKS IP Port", "cops.pc_srks_ip_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dest_port,
{ "Destination IP Port", "cops.pc_dest_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_packetcable_err_code,
{ "Error Code", "cops.pc_packetcable_err_code",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_packetcable_sub_code,
{ "Error Sub Code", "cops.pc_packetcable_sub_code",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_remote_flags,
{ "Flags", "cops.pc_remote_flags",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_close_subcode,
{ "Reason Sub Code", "cops.pc_close_subcode",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_gate_command_type,
{ "Gate Command Type", "cops.pc_gate_command_type",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_reason_code,
{ "Reason Code", "cops.pc_reason_code",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_delete_subcode,
{ "Reason Sub Code", "cops.pc_delete_subcode",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_src_port,
{ "Source IP Port", "cops.pc_src_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_t1_value,
{ "Timer T1 Value (sec)", "cops.pc_t1_value",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_t7_value,
{ "Timer T7 Value (sec)", "cops.pc_t7_value",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_t8_value,
{ "Timer T8 Value (sec)", "cops.pc_t8_value",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_transaction_id,
{ "Transaction Identifier", "cops.pc_transaction_id",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_cmts_ip,
{ "CMTS IP Address", "cops.pc_cmts_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_prks_ip,
{ "PRKS IP Address", "cops.pc_prks_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_srks_ip,
{ "SRKS IP Address", "cops.pc_srks_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dfcdc_ip,
{ "DF IP Address CDC", "cops.pc_dfcdc_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dfccc_ip,
{ "DF IP Address CCC", "cops.pc_dfccc_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dfcdc_ip_port,
{ "DF IP Port CDC", "cops.pc_dfcdc_ip_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dfccc_ip_port,
{ "DF IP Port CCC", "cops.pc_dfccc_ip_port",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dfccc_id,
{ "CCC ID", "cops.pc_dfccc_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_activity_count,
{ "Count", "cops.pc_activity_count",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_dest_ip,
{ "Destination IP Address", "cops.pc_dest_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_gate_id,
{ "Gate Identifier", "cops.pc_gate_id",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_max_packet_size,
{ "Maximum Packet Size", "cops.pc_max_packet_size",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_min_policed_unit,
{ "Minimum Policed Unit", "cops.pc_min_policed_unit",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_peak_data_rate,
{ "Peak Data Rate", "cops.pc_peak_data_rate",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_spec_rate,
{ "Rate", "cops.pc_spec_rate",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_remote_gate_id,
{ "Remote Gate ID", "cops.pc_remote_gate_id",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_reserved,
{ "Reserved", "cops.pc_reserved",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_key,
{ "Security Key", "cops.pc_key",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_slack_term,
{ "Slack Term", "cops.pc_slack_term",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_src_ip,
{ "Source IP Address", "cops.pc_src_ip",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_subscriber_id_ipv4,
{ "Subscriber Identifier (IPv4)", "cops.pc_subscriber_id4",
FT_IPv4, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_subscriber_id_ipv6,
{ "Subscriber Identifier (IPv6)", "cops.pc_subscriber_id6",
FT_IPv6, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_token_bucket_rate,
{ "Token Bucket Rate", "cops.pc_token_bucket_rate",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_token_bucket_size,
{ "Token Bucket Size", "cops.pc_token_bucket_size",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_bcid,
{ "Billing Correlation ID", "cops.pc_bcid",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cops_pc_bcid_ts,
{ "BDID Timestamp", "cops.pc_bcid_ts",
FT_UINT32, BASE_HEX, NULL, 0x00,
"BCID Timestamp", HFILL }
},
{ &hf_cops_pc_bcid_ev,
{ "BDID Event Counter", "cops.pc_bcid_ev",
FT_UINT32, BASE_HEX, NULL, 0x00,
"BCID Event Counter", HFILL }
},
{ &hf_cops_pcmm_amid_app_type,
{ "AMID Application Type", "cops.pc_mm_amid_application_type",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia AMID Application Type", HFILL }
},
{ &hf_cops_pcmm_amid_am_tag,
{ "AMID Application Manager Tag", "cops.pc_mm_amid_am_tag",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia AMID Application Manager Tag", HFILL }
},
{ &hf_cops_pcmm_gate_spec_flags,
{ "Flags", "cops.pc_mm_gs_flags",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia GateSpec Flags", HFILL }
},
{ &hf_cops_pcmm_gate_spec_dscp_tos_field,
{ "DSCP/TOS Field", "cops.pc_mm_gs_dscp",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia GateSpec DSCP/TOS Field", HFILL }
},
{ &hf_cops_pcmm_gate_spec_dscp_tos_mask,
{ "DSCP/TOS Mask", "cops.pc_mm_gs_dscp_mask",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia GateSpec DSCP/TOS Mask", HFILL }
},
{ &hf_cops_pcmm_gate_spec_session_class_id,
{ "SessionClassID", "cops.pc_mm_gs_scid",
FT_UINT8, BASE_DEC, NULL, 0,
"PacketCable Multimedia GateSpec SessionClassID", HFILL }
},
{ &hf_cops_pcmm_gate_spec_session_class_id_priority,
{ "SessionClassID Priority", "cops.pc_mm_gs_scid_prio",
FT_UINT8, BASE_DEC, NULL, 0x07,
"PacketCable Multimedia GateSpec SessionClassID Priority", HFILL }
},
{ &hf_cops_pcmm_gate_spec_session_class_id_preemption,
{ "SessionClassID Preemption", "cops.pc_mm_gs_scid_preempt",
FT_UINT8, BASE_DEC, NULL, 0x08,
"PacketCable Multimedia GateSpec SessionClassID Preemption", HFILL }
},
{ &hf_cops_pcmm_gate_spec_session_class_id_configurable,
{ "SessionClassID Configurable", "cops.pc_mm_gs_scid_conf",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"PacketCable Multimedia GateSpec SessionClassID Configurable", HFILL }
},
{ &hf_cops_pcmm_gate_spec_timer_t1,
{ "Timer T1", "cops.pc_mm_gs_timer_t1",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia GateSpec Timer T1", HFILL }
},
{ &hf_cops_pcmm_gate_spec_timer_t2,
{ "Timer T2", "cops.pc_mm_gs_timer_t2",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia GateSpec Timer T2", HFILL }
},
{ &hf_cops_pcmm_gate_spec_timer_t3,
{ "Timer T3", "cops.pc_mm_gs_timer_t3",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia GateSpec Timer T3", HFILL }
},
{ &hf_cops_pcmm_gate_spec_timer_t4,
{ "Timer T4", "cops.pc_mm_gs_timer_t4",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia GateSpec Timer T4", HFILL }
},
{ &hf_cops_pcmm_classifier_protocol_id,
{ "Protocol ID", "cops.pc_mm_classifier_proto_id",
FT_UINT16, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Protocol ID", HFILL }
},
{ &hf_cops_pcmm_classifier_dscp_tos_field,
{ "DSCP/TOS Field", "cops.pc_mm_classifier_dscp",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier DSCP/TOS Field", HFILL }
},
{ &hf_cops_pcmm_classifier_dscp_tos_mask,
{ "DSCP/TOS Mask", "cops.pc_mm_classifier_dscp_mask",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier DSCP/TOS Mask", HFILL }
},
{ &hf_cops_pcmm_classifier_src_addr,
{ "Source address", "cops.pc_mm_classifier_src_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier Source IP Address", HFILL }
},
{ &hf_cops_pcmm_classifier_src_mask,
{ "Source mask", "cops.pc_mm_classifier_src_mask",
FT_IPv4, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier Source Mask", HFILL }
},
{ &hf_cops_pcmm_classifier_dst_addr,
{ "Destination address", "cops.pc_mm_classifier_dst_addr",
FT_IPv4, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier Destination IP Address", HFILL }
},
{ &hf_cops_pcmm_classifier_dst_mask,
{ "Destination mask", "cops.pc_mm_classifier_dst_mask",
FT_IPv4, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier Destination Mask", HFILL }
},
{ &hf_cops_pcmm_classifier_src_port,
{ "Source Port", "cops.pc_mm_classifier_src_port",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Classifier Source Port", HFILL }
},
{ &hf_cops_pcmm_classifier_src_port_end,
{ "Source Port End", "cops.pc_mm_classifier_src_port_end",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Classifier Source Port End", HFILL }
},
{ &hf_cops_pcmm_classifier_dst_port,
{ "Destination Port", "cops.pc_mm_classifier_dst_port",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Classifier Source Port", HFILL }
},
{ &hf_cops_pcmm_classifier_dst_port_end,
{ "Destination Port End", "cops.pc_mm_classifier_dst_port_end",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Classifier Source Port End", HFILL }
},
{ &hf_cops_pcmm_classifier_priority,
{ "Priority", "cops.pc_mm_classifier_priority",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Priority", HFILL }
},
{ &hf_cops_pcmm_classifier_classifier_id,
{ "Classifier Id", "cops.pc_mm_classifier_id",
FT_UINT16, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier ID", HFILL }
},
{ &hf_cops_pcmm_classifier_activation_state,
{ "Activation State", "cops.pc_mm_classifier_activation_state",
FT_UINT8, BASE_HEX, pcmm_activation_state_vals, 0,
"PacketCable Multimedia Classifier Activation State", HFILL }
},
{ &hf_cops_pcmm_classifier_action,
{ "Action", "cops.pc_mm_classifier_action",
FT_UINT8, BASE_HEX, pcmm_action_vals, 0,
"PacketCable Multimedia Classifier Action", HFILL }
},
{ &hf_cops_pcmm_classifier_flags,
{ "Flags", "cops.pc_mm_classifier_flags",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Flags", HFILL }
},
{ &hf_cops_pcmm_classifier_tc_low,
{ "tc-low", "cops.pc_mm_classifier_tc_low",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier tc-low", HFILL }
},
{ &hf_cops_pcmm_classifier_tc_high,
{ "tc-high", "cops.pc_mm_classifier_tc_high",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier tc-high", HFILL }
},
{ &hf_cops_pcmm_classifier_tc_mask,
{ "tc-mask", "cops.pc_mm_classifier_tc_mask",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier tc-mask", HFILL }
},
{ &hf_cops_pcmm_classifier_flow_label,
{ "Flow Label", "cops.pc_mm_classifier_flow_label",
FT_UINT32, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Flow Label", HFILL }
},
{ &hf_cops_pcmm_classifier_next_header_type,
{ "Next Header Type", "cops.pc_mm_classifier_next_header_type",
FT_UINT16, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Next Header Type", HFILL }
},
{ &hf_cops_pcmm_classifier_source_prefix_length,
{ "Source Prefix Length", "cops.pc_mm_classifier_source_prefix_length",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Source Prefix Length", HFILL }
},
{ &hf_cops_pcmm_classifier_destination_prefix_length,
{ "Destination Prefix Length", "cops.pc_mm_classifier_destination_prefix_length",
FT_UINT8, BASE_HEX, NULL, 0,
"PacketCable Multimedia Classifier Destination Prefix Length", HFILL }
},
{ &hf_cops_pcmm_classifier_src_addr_v6,
{ "IPv6 Source Address", "cops.pc_mm_classifier_src_addr_v6",
FT_IPv6, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier IPv6 Source Address", HFILL }
},
{ &hf_cops_pcmm_classifier_dst_addr_v6,
{ "IPv6 Destination Address", "cops.pc_mm_classifier_dst_addr_v6",
FT_IPv6, BASE_NONE, NULL, 0,
"PacketCable Multimedia Classifier IPv6 Destination Address", HFILL }
},
{ &hf_cops_pcmm_flow_spec_envelope,
{ "Envelope", "cops.pc_mm_fs_envelope",
FT_UINT8, BASE_DEC, NULL, 0,
"PacketCable Multimedia Flow Spec Envelope", HFILL }
},
{ &hf_cops_pcmm_flow_spec_service_number,
{ "Service Number", "cops.pc_mm_fs_svc_num",
FT_UINT8, BASE_DEC, pcmm_flow_spec_service_vals, 0,
"PacketCable Multimedia Flow Spec Service Number", HFILL }
},
{ &hf_cops_pcmm_docsis_scn,
{ "Service Class Name", "cops.pc_mm_docsis_scn",
FT_STRINGZ, BASE_NONE, NULL, 0,
"PacketCable Multimedia DOCSIS Service Class Name", HFILL }
},
{ &hf_cops_pcmm_envelope,
{ "Envelope", "cops.pc_mm_envelope",
FT_UINT8, BASE_DEC, NULL, 0,
"PacketCable Multimedia Envelope", HFILL }
},
{ &hf_cops_pcmm_traffic_priority,
{ "Traffic Priority", "cops.pc_mm_tp",
FT_UINT8, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Traffic Priority", HFILL }
},
{ &hf_cops_pcmm_request_transmission_policy,
{ "Request Transmission Policy", "cops.pc_mm_rtp",
FT_UINT32, BASE_HEX, NULL, 0,
"PacketCable Multimedia Committed Envelope Traffic Priority", HFILL }
},
{ &hf_cops_pcmm_max_sustained_traffic_rate,
{ "Maximum Sustained Traffic Rate", "cops.pc_mm_mstr",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Maximum Sustained Traffic Rate", HFILL }
},
{ &hf_cops_pcmm_max_traffic_burst,
{ "Maximum Traffic Burst", "cops.pc_mm_mtb",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Maximum Traffic Burst", HFILL }
},
{ &hf_cops_pcmm_min_reserved_traffic_rate,
{ "Minimum Reserved Traffic Rate", "cops.pc_mm_mrtr",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Minimum Reserved Traffic Rate", HFILL }
},
{ &hf_cops_pcmm_ass_min_rtr_packet_size,
{ "Assumed Minimum Reserved Traffic Rate Packet Size", "cops.pc_mm_amrtrps",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Assumed Minimum Reserved Traffic Rate Packet Size", HFILL }
},
{ &hf_cops_pcmm_max_concat_burst,
{ "Maximum Concatenated Burst", "cops.pc_mm_mcburst",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Maximum Concatenated Burst", HFILL }
},
{ &hf_cops_pcmm_req_att_mask,
{ "Required Attribute Mask", "cops.pc_mm_ramask",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Required Attribute Mask", HFILL }
},
{ &hf_cops_pcmm_forbid_att_mask,
{ "Forbidden Attribute Mask", "cops.pc_mm_famask",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Forbidden Attribute Mask", HFILL }
},
{ &hf_cops_pcmm_att_aggr_rule_mask,
{ "Attribute Aggregation Rule Mask", "cops.pc_mm_aarmask",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Committed Envelope Attribute Aggregation Rule Mask", HFILL }
},
{ &hf_cops_pcmm_nominal_polling_interval,
{ "Nominal Polling Interval", "cops.pc_mm_npi",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Nominal Polling Interval", HFILL }
},
{ &hf_cops_pcmm_tolerated_poll_jitter,
{ "Tolerated Poll Jitter", "cops.pc_mm_tpj",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Tolerated Poll Jitter", HFILL }
},
{ &hf_cops_pcmm_unsolicited_grant_size,
{ "Unsolicited Grant Size", "cops.pc_mm_ugs",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Unsolicited Grant Size", HFILL }
},
{ &hf_cops_pcmm_grants_per_interval,
{ "Grants Per Interval", "cops.pc_mm_gpi",
FT_UINT8, BASE_DEC, NULL, 0,
"PacketCable Multimedia Grants Per Interval", HFILL }
},
{ &hf_cops_pcmm_nominal_grant_interval,
{ "Nominal Grant Interval", "cops.pc_mm_ngi",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Nominal Grant Interval", HFILL }
},
{ &hf_cops_pcmm_tolerated_grant_jitter,
{ "Tolerated Grant Jitter", "cops.pc_mm_tgj",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Tolerated Grant Jitter", HFILL }
},
{ &hf_cops_pcmm_down_resequencing,
{ "Downstream Resequencing", "cops.pc_mm_downres",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Downstream Resequencing", HFILL }
},
{ &hf_cops_pcmm_down_peak_traffic_rate,
{ "Downstream Peak Traffic Rate", "cops.pc_mm_downpeak",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Downstream Peak Traffic Rate", HFILL }
},
{ &hf_cops_pcmm_max_downstream_latency,
{ "Maximum Downstream Latency", "cops.pc_mm_mdl",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Maximum Downstream Latency", HFILL }
},
{ &hf_cops_pcmm_volume_based_usage_limit,
{ "Usage Limit", "cops.pc_mm_vbul_ul",
FT_UINT64, BASE_DEC, NULL, 0,
"PacketCable Multimedia Volume-Based Usage Limit", HFILL }
},
{ &hf_cops_pcmm_time_based_usage_limit,
{ "Usage Limit", "cops.pc_mm_tbul_ul",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Time-Based Usage Limit", HFILL }
},
{ &hf_cops_pcmm_gate_time_info,
{ "Gate Time Info", "cops.pc_mm_gti",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia Gate Time Info", HFILL }
},
{ &hf_cops_pcmm_gate_usage_info,
{ "Gate Usage Info", "cops.pc_mm_gui",
FT_UINT64, BASE_DEC, NULL, 0,
"PacketCable Multimedia Gate Usage Info", HFILL }
},
{ &hf_cops_pcmm_packetcable_error_code,
{ "Error-Code", "cops.pc_mm_error_ec",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia PacketCable-Error Error-Code", HFILL }
},
{ &hf_cops_pcmm_packetcable_error_subcode,
{ "Error-code", "cops.pc_mm_error_esc",
FT_UINT16, BASE_HEX, NULL, 0,
"PacketCable Multimedia PacketCable-Error Error Sub-code", HFILL }
},
{ &hf_cops_pcmm_packetcable_gate_state,
{ "State", "cops.pc_mm_gs_state",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Gate State", HFILL }
},
{ &hf_cops_pcmm_packetcable_gate_state_reason,
{ "Reason", "cops.pc_mm_gs_reason",
FT_UINT16, BASE_HEX, NULL, 0,
"PacketCable Multimedia Gate State Reason", HFILL }
},
{ &hf_cops_pcmm_packetcable_version_info_major,
{ "Major Version Number", "cops.pc_mm_vi_major",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Major Version Number", HFILL }
},
{ &hf_cops_pcmm_packetcable_version_info_minor,
{ "Minor Version Number", "cops.pc_mm_vi_minor",
FT_UINT16, BASE_DEC, NULL, 0,
"PacketCable Multimedia Minor Version Number", HFILL }
},
{ &hf_cops_pcmm_psid,
{ "PSID", "cops.pc_mm_psid",
FT_UINT32, BASE_DEC, NULL, 0,
"PacketCable Multimedia PSID", HFILL }
},
{ &hf_cops_pcmm_synch_options_report_type,
{ "Report Type", "cops.pc_mm_synch_options_report_type",
FT_UINT8, BASE_DEC, pcmm_report_type_vals, 0,
"PacketCable Multimedia Synch Options Report Type", HFILL }
},
{ &hf_cops_pcmm_synch_options_synch_type,
{ "Synch Type", "cops.pc_mm_synch_options_synch_type",
FT_UINT8, BASE_DEC, pcmm_synch_type_vals, 0,
"PacketCable Multimedia Synch Options Synch Type", HFILL }
},
{ &hf_cops_pcmm_msg_receipt_key,
{ "Msg Receipt Key", "cops.pc_mm_msg_receipt_key",
FT_UINT32, BASE_HEX, NULL, 0,
"PacketCable Multimedia Msg Receipt Key", HFILL }
},
{ &hf_cops_pcmm_userid,
{ "UserID", "cops.pc_mm_userid",
FT_STRING, BASE_NONE, NULL, 0,
"PacketCable Multimedia UserID", HFILL }
},
{ &hf_cops_pcmm_sharedresourceid,
{ "SharedResourceID", "cops.pc_mm_sharedresourceid",
FT_UINT32, BASE_HEX, NULL, 0,
"PacketCable Multimedia SharedResourceID", HFILL }
},
};
static gint *ett[] = {
&ett_cops,
&ett_cops_ver_flags,
&ett_cops_obj,
&ett_cops_pr_obj,
&ett_cops_obj_data,
&ett_cops_r_type_flags,
&ett_cops_itf,
&ett_cops_reason,
&ett_cops_decision,
&ett_cops_error,
&ett_cops_clientsi,
&ett_cops_asn1,
&ett_cops_gperror,
&ett_cops_cperror,
&ett_cops_pdp,
&ett_cops_subtree,
&ett_docsis_request_transmission_policy,
};
module_t* cops_module;
proto_cops = proto_register_protocol("Common Open Policy Service",
"COPS", "cops");
proto_register_field_array(proto_cops, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("cops", dissect_cops, proto_cops);
cops_module = prefs_register_protocol(proto_cops, proto_reg_handoff_cops);
prefs_register_uint_preference(cops_module,"tcp.cops_port",
"COPS TCP Port",
"Set the TCP port for COPS messages",
10,&global_cops_tcp_port);
prefs_register_bool_preference(cops_module, "desegment",
"Reassemble COPS messages spanning multiple TCP segments",
"Whether the COPS dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&cops_desegment);
prefs_register_bool_preference(cops_module, "packetcable",
"Decode for PacketCable clients",
"Decode the COPS messages using PacketCable clients. (Select port 2126)",
&cops_packetcable);
prefs_register_static_text_preference(cops_module, "info_pibs",
"PIB settings can be changed in the Name Resolution preferences",
"PIB settings can be changed in the Name Resolution preferences");
prefs_register_obsolete_preference(cops_module, "typefrommib");
}
void proto_reg_handoff_cops(void)
{
static gboolean cops_prefs_initialized = FALSE;
static dissector_handle_t cops_handle;
static guint cops_tcp_port;
if (!cops_prefs_initialized) {
cops_handle = find_dissector("cops");
dissector_add_uint("tcp.port", TCP_PORT_PKTCABLE_COPS, cops_handle);
dissector_add_uint("tcp.port", TCP_PORT_PKTCABLE_MM_COPS, cops_handle);
cops_prefs_initialized = TRUE;
} else {
dissector_delete_uint("tcp.port",cops_tcp_port,cops_handle);
}
cops_tcp_port = global_cops_tcp_port;
dissector_add_uint("tcp.port", cops_tcp_port, cops_handle);
}
static proto_item *
info_to_display(tvbuff_t *tvb, proto_item *stt, int offset, int octets, const char *str, const value_string *vsp, int mode,gint *hf_proto_parameter)
{
proto_item *pi = NULL;
guint8 *codestr;
guint8 code8 = 0;
guint16 code16 = 0;
guint32 codeipv4 = 0;
guint32 code32 = 0;
guint64 code64 = 0;
float codefl = 0.0f;
if (mode==FMT_STR) {
codestr = tvb_get_ephemeral_string(tvb, offset, octets);
pi = proto_tree_add_string_format(stt, *hf_proto_parameter, tvb,
offset, octets, codestr, "%-28s : %s", str, codestr);
return pi;
}
switch (octets) {
case 1:
code8 = tvb_get_guint8( tvb, offset );
if (vsp == NULL) {
if (mode==FMT_HEX)
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code8,"%-28s : 0x%02x",str,code8);
else
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code8,"%-28s : %u",str,code8);
} else {
if (mode==FMT_HEX)
pi = proto_tree_add_uint_format(
stt, *hf_proto_parameter,tvb, offset, octets, code8,
"%-28s : %s (0x%02x)",str,val_to_str(code8, vsp, "Unknown"),code8);
else
pi = proto_tree_add_uint_format(
stt, *hf_proto_parameter,tvb, offset, octets, code8,
"%-28s : %s (%u)",str,val_to_str(code8, vsp, "Unknown"),code8);
}
break;
case 2:
code16 = tvb_get_ntohs(tvb,offset);
if (vsp == NULL) {
if (mode==FMT_HEX)
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code16,"%-28s : 0x%04x",str,code16);
else
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code16,"%-28s : %u",str,code16);
} else {
if (mode==FMT_HEX)
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code16,"%-28s : %s (0x%04x)", str,
val_to_str(code16, vsp, "Unknown (0x%04x)"),code16);
else
pi = proto_tree_add_uint_format(
stt, *hf_proto_parameter,tvb, offset, octets, code16,
"%-28s : %s (%u)",str,val_to_str(code16, vsp, "Unknown (0x%04x)"),code16);
}
break;
case 4:
switch (mode) {
case FMT_FLT: codefl = tvb_get_ntohieee_float(tvb,offset);
break;
case FMT_IPv4: codeipv4 = tvb_get_ipv4(tvb, offset);
break;
default: code32 = tvb_get_ntohl(tvb,offset);
}
if (vsp == NULL) {
if (mode==FMT_HEX) {
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb,
offset, octets, code32,"%-28s : 0x%08x",str,code32);
break;
}
if (mode==FMT_IPv4) {
pi = proto_tree_add_ipv4(stt, *hf_proto_parameter,tvb, offset, octets, codeipv4);
break;
}
if (mode==FMT_FLT) {
pi = proto_tree_add_float_format(stt, *hf_proto_parameter,tvb, offset, octets,
codefl,"%-28s : %.10g",str,codefl);
break;
}
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb, offset, octets,
code32,"%-28s : %u",str,code32);
} else {
if (mode==FMT_HEX)
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb, offset, octets,
code32,"%-28s : %s (0x%08x)",str,val_to_str(code32, vsp, "Unknown"),code32);
else
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,tvb, offset, octets,
code32,"%-28s : %s (%u)",str,val_to_str(code32, vsp, "Unknown"),code32);
}
break;
default:
if (mode==FMT_HEX) {
pi = proto_tree_add_item(stt, *hf_proto_parameter,
tvb, offset, octets, ENC_NA);
} else if (mode==FMT_IPv6 && octets==16) {
pi = proto_tree_add_item(stt, *hf_proto_parameter, tvb, offset, octets,
ENC_NA);
} else if (mode==FMT_DEC && octets==8) {
code64 = tvb_get_ntoh64(tvb, offset);
pi = proto_tree_add_uint64_format(stt, *hf_proto_parameter, tvb, offset, octets,
code64, "%-28s : %" G_GINT64_MODIFIER "u", str, code64);
} else {
pi = proto_tree_add_uint_format(stt, *hf_proto_parameter,
tvb, offset, octets, code32,"%s",str);
}
break;
}
return pi;
}
static proto_tree *
info_to_cops_subtree(tvbuff_t *tvb, proto_tree *st, int n, int offset, const char *str) {
proto_item *tv;
tv = proto_tree_add_none_format( st, hf_cops_subtree, tvb, offset, n, "%s", str);
return( proto_item_add_subtree( tv, ett_cops_subtree ) );
}
static void
cops_transaction_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *st, guint8 op_code, guint n, guint32 offset) {
proto_tree *stt;
guint16 code16;
char info[50];
stt = info_to_cops_subtree(tvb,st,n,offset,"D-QoS Transaction ID");
offset += 4;
info_to_display(tvb,stt,offset,2,"D-QoS Transaction Identifier", NULL,FMT_DEC,&hf_cops_pc_transaction_id);
offset +=2;
code16 = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format(stt, hf_cops_pc_gate_command_type,tvb, offset, 2,
code16,"%-28s : %s (%u)", "Gate Command Type",
val_to_str(code16,table_cops_dqos_transaction_id, "Unknown (0x%04x)"),code16);
g_snprintf(info,sizeof(info),"COPS %-20s - %s",val_to_str(op_code,cops_op_code_vals, "Unknown"),
val_to_str(code16,table_cops_dqos_transaction_id, "Unknown"));
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO,info);
}
static void
cops_subscriber_id_v4(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *tv;
tv = info_to_cops_subtree(tvb,st,n,offset,"Subscriber ID (IPv4)");
offset += 4;
info_to_display(tvb,tv,offset,4,"Subscriber Identifier (IPv4)", NULL,FMT_IPv4,&hf_cops_pc_subscriber_id_ipv4);
}
static void
cops_subscriber_id_v6(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *tv;
tv = info_to_cops_subtree(tvb,st,n,offset,"Subscriber ID (IPv6)");
offset += 4;
info_to_display(tvb,tv,offset,16,"Subscriber Identifier (IPv6)", NULL,FMT_IPv6,&hf_cops_pc_subscriber_id_ipv6);
}
static void
cops_gate_id(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate ID");
offset += 4;
info_to_display(tvb,stt,offset,4,"Gate Identifier", NULL,FMT_HEX,&hf_cops_pc_gate_id);
}
static void
cops_activity_count(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Activity Count");
offset += 4;
info_to_display(tvb,stt,offset,4,"Count", NULL,FMT_DEC,&hf_cops_pc_activity_count);
}
static void
cops_gate_specs(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate Specifications");
offset += 4;
info_to_display(tvb,stt,offset,1,"Direction",table_cops_direction,FMT_DEC,&hf_cops_pc_direction);
offset += 1;
info_to_display(tvb,stt,offset,1,"Protocol ID",NULL,FMT_DEC,&hf_cops_pc_protocol_id);
offset += 1;
info_to_display(tvb,stt,offset,1,"Flags",NULL,FMT_DEC,&hf_cops_pc_gate_spec_flags);
offset += 1;
info_to_display(tvb,stt,offset,1,"Session Class",table_cops_session_class,FMT_DEC,&hf_cops_pc_session_class);
offset += 1;
info_to_display(tvb,stt,offset,4,"Source IP Address",NULL,FMT_IPv4,&hf_cops_pc_src_ip);
offset += 4;
info_to_display(tvb,stt,offset,4,"Destination IP Address",NULL,FMT_IPv4,&hf_cops_pc_dest_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"Source IP Port",NULL,FMT_DEC,&hf_cops_pc_src_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Destination IP Port",NULL,FMT_DEC,&hf_cops_pc_dest_port);
offset += 2;
info_to_display(tvb,stt,offset,1,"DS Field (DSCP or TOS)",NULL,FMT_HEX,&hf_cops_pc_ds_field);
offset += 1;
offset += 3;
info_to_display(tvb,stt,offset,2,"Timer T1 Value (sec)",NULL,FMT_DEC,&hf_cops_pc_t1_value);
offset += 2;
info_to_display(tvb,stt,offset,2,"Reserved",NULL,FMT_DEC,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,stt,offset,2,"Timer T7 Value (sec)",NULL,FMT_DEC,&hf_cops_pc_t7_value);
offset += 2;
info_to_display(tvb,stt,offset,2,"Timer T8 Value (sec)",NULL,FMT_DEC,&hf_cops_pc_t8_value);
offset += 2;
info_to_display(tvb,stt,offset,4,"Token Bucket Rate",NULL,FMT_FLT,&hf_cops_pc_token_bucket_rate);
offset += 4;
info_to_display(tvb,stt,offset,4,"Token Bucket Size",NULL,FMT_FLT,&hf_cops_pc_token_bucket_size);
offset += 4;
info_to_display(tvb,stt,offset,4,"Peak Data Rate",NULL,FMT_FLT,&hf_cops_pc_peak_data_rate);
offset += 4;
info_to_display(tvb,stt,offset,4,"Minimum Policed Unit",NULL,FMT_DEC,&hf_cops_pc_min_policed_unit);
offset += 4;
info_to_display(tvb,stt,offset,4,"Maximum Packet Size",NULL,FMT_DEC,&hf_cops_pc_max_packet_size);
offset += 4;
info_to_display(tvb,stt,offset,4,"Rate",NULL,FMT_FLT,&hf_cops_pc_spec_rate);
offset += 4;
info_to_display(tvb,stt,offset,4,"Slack Term",NULL,FMT_DEC,&hf_cops_pc_slack_term);
}
static void
cops_surveillance_parameters(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
guint8 *bcid_str;
stt = info_to_cops_subtree(tvb,st,n,offset,"Electronic Surveillance Parameters");
offset += 4;
info_to_display(tvb,stt,offset,4,"DF IP Address for CDC", NULL,FMT_IPv4,&hf_cops_pc_dfcdc_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"DF IP Port for CDC",NULL,FMT_DEC,&hf_cops_pc_dfcdc_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Flags",NULL,FMT_HEX,&hf_cops_pc_gate_spec_flags);
offset += 2;
info_to_display(tvb,stt,offset,4,"DF IP Address for CCC", NULL,FMT_IPv4,&hf_cops_pc_dfccc_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"DF IP Port for CCC",NULL,FMT_DEC,&hf_cops_pc_dfccc_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,stt,offset,4,"CCCID", NULL,FMT_DEC,&hf_cops_pc_dfccc_id);
offset += 4;
info_to_display(tvb,stt,offset,4,"BCID - Timestamp",NULL,FMT_HEX,&hf_cops_pc_bcid_ts);
offset += 4;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Element ID",bcid_str);
offset += 8;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Time Zone",bcid_str);
offset += 8;
info_to_display(tvb,stt,offset,4,"BCID - Event Counter",NULL,FMT_DEC,&hf_cops_pc_bcid_ev);
}
static void
cops_event_generation_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
guint8 *bcid_str;
stt = info_to_cops_subtree(tvb,st,n,offset,"Event Generation Info");
offset += 4;
info_to_display(tvb,stt,offset,4,"PRKS IP Address", NULL,FMT_IPv4,&hf_cops_pc_prks_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"PRKS IP Port",NULL,FMT_DEC,&hf_cops_pc_prks_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,1,"Flags",NULL,FMT_HEX,&hf_cops_pc_gate_spec_flags);
offset += 1;
info_to_display(tvb,stt,offset,1,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 1;
info_to_display(tvb,stt,offset,4,"SRKS IP Address", NULL,FMT_IPv4,&hf_cops_pc_srks_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"SRKS IP Port",NULL,FMT_DEC,&hf_cops_pc_srks_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,1,"Flags",NULL,FMT_DEC,&hf_cops_pc_gate_spec_flags);
offset += 1;
info_to_display(tvb,stt,offset,1,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 1;
info_to_display(tvb,stt,offset,4,"BCID - Timestamp",NULL,FMT_HEX,&hf_cops_pc_bcid_ts);
offset += 4;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Element ID",bcid_str);
offset += 8;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Time Zone",bcid_str);
offset += 8;
info_to_display(tvb,stt,offset,4,"BCID - Event Counter",NULL,FMT_DEC,&hf_cops_pc_bcid_ev);
}
static void
cops_remote_gate_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Remote Gate Info");
offset += 4;
info_to_display(tvb,stt,offset,4,"CMTS IP Address", NULL,FMT_IPv4,&hf_cops_pc_cmts_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"CMTS IP Port",NULL,FMT_DEC,&hf_cops_pc_cmts_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Flags",NULL,FMT_DEC,&hf_cops_pc_remote_flags);
offset += 2;
info_to_display(tvb,stt,offset,4,"Remote Gate ID", NULL,FMT_HEX,&hf_cops_pc_remote_gate_id);
offset += 4;
info_to_display(tvb,stt,offset,2,"Algorithm", NULL,FMT_DEC,&hf_cops_pc_algorithm);
offset += 2;
info_to_display(tvb,stt,offset,4,"Reserved", NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 4;
info_to_display(tvb,stt,offset,4,"Security Key", NULL,FMT_HEX,&hf_cops_pc_key);
offset += 4;
info_to_display(tvb,stt,offset,4,"Security Key (cont)", NULL,FMT_HEX,&hf_cops_pc_key);
offset += 4;
info_to_display(tvb,stt,offset,4,"Security Key (cont)", NULL,FMT_HEX,&hf_cops_pc_key);
offset += 4;
info_to_display(tvb,stt,offset,4,"Security Key (cont)", NULL,FMT_HEX,&hf_cops_pc_key);
}
static void
cops_packetcable_reason(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
guint16 code16;
stt = info_to_cops_subtree(tvb,st,n,offset,"PacketCable Reason");
offset += 4;
code16 = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format(stt, hf_cops_pc_reason_code,tvb, offset, 2,
code16, "%-28s : %s (%u)","Reason Code",
val_to_str(code16, table_cops_reason_code, "Unknown (0x%04x)"),code16);
offset += 2;
if ( code16 == 0 ) {
info_to_display(tvb,stt,offset,2,"Reason Sub Code",table_cops_reason_subcode_delete,FMT_DEC,&hf_cops_pc_delete_subcode);
} else {
info_to_display(tvb,stt,offset,2,"Reason Sub Code",table_cops_reason_subcode_close,FMT_DEC,&hf_cops_pc_close_subcode);
}
}
static void
cops_packetcable_error(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"PacketCable Error");
offset += 4;
info_to_display(tvb,stt,offset,2,"Error Code",table_cops_packetcable_error,FMT_DEC,&hf_cops_pc_packetcable_err_code);
offset += 2;
info_to_display(tvb,stt,offset,2,"Error Sub Code",NULL,FMT_HEX,&hf_cops_pc_packetcable_sub_code);
}
static void
cops_mm_transaction_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *st, guint8 op_code, guint n, guint32 offset) {
proto_tree *stt;
guint16 code16;
char info[50];
stt = info_to_cops_subtree(tvb,st,n,offset,"MM Transaction ID");
offset += 4;
info_to_display(tvb,stt,offset,2,"Multimedia Transaction Identifier", NULL,FMT_DEC,&hf_cops_pc_transaction_id);
offset +=2;
code16 = tvb_get_ntohs(tvb,offset);
proto_tree_add_uint_format(stt, hf_cops_pc_gate_command_type,tvb, offset, 2,
code16,"%-28s : %s (%u)", "Gate Command Type",
val_to_str(code16,table_cops_mm_transaction_id, "Unknown (0x%04x)"),code16);
g_snprintf(info,sizeof(info),"COPS %-20s - %s",val_to_str(op_code,cops_op_code_vals, "Unknown"),
val_to_str(code16,table_cops_mm_transaction_id, "Unknown"));
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO,info);
}
static void
cops_amid(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"AMID");
offset += 4;
info_to_display(tvb,stt,offset,2,"Application Manager ID Application Type", NULL,FMT_DEC,&hf_cops_pcmm_amid_app_type);
offset += 2;
info_to_display(tvb,stt,offset,2,"Application Manager ID Application Manager Tag", NULL,FMT_DEC,&hf_cops_pcmm_amid_am_tag);
}
static int
cops_mm_gate_spec(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
guint8 gs_flags;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate Spec");
offset += 4;
gs_flags = tvb_get_guint8(tvb, offset);
ti = info_to_display(tvb,stt,offset,1,"Flags",NULL,FMT_HEX,&hf_cops_pcmm_gate_spec_flags);
object_tree = proto_item_add_subtree(ti, ett_cops_subtree );
proto_tree_add_text(object_tree, tvb, offset, 1, "%s gate",
decode_boolean_bitfield(gs_flags, 1 << 0, 8,
"Upstream", "Downstream"));
proto_tree_add_text(object_tree, tvb, offset, 1, "%s DSCP/TOS overwrite",
decode_boolean_bitfield(gs_flags, 1 << 1, 8,
"Enable", "Disable"));
offset += 1;
info_to_display(tvb,stt,offset,1,"DS Field (DSCP or TOS)",NULL,FMT_HEX,&hf_cops_pcmm_gate_spec_dscp_tos_field);
offset += 1;
info_to_display(tvb,stt,offset,1,"DS Field (DSCP or TOS) Mask",NULL,FMT_HEX,&hf_cops_pcmm_gate_spec_dscp_tos_mask);
offset += 1;
ti = info_to_display(tvb,stt,offset,1,"Session Class",table_cops_session_class,FMT_DEC,&hf_cops_pcmm_gate_spec_session_class_id);
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
proto_tree_add_item(object_tree, hf_cops_pcmm_gate_spec_session_class_id_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(object_tree, hf_cops_pcmm_gate_spec_session_class_id_preemption, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(object_tree, hf_cops_pcmm_gate_spec_session_class_id_configurable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
info_to_display(tvb,stt,offset,2,"Timer T1 Value (sec)",NULL,FMT_DEC,&hf_cops_pcmm_gate_spec_timer_t1);
offset += 2;
info_to_display(tvb,stt,offset,2,"Timer T2 Value (sec)",NULL,FMT_DEC,&hf_cops_pcmm_gate_spec_timer_t2);
offset += 2;
info_to_display(tvb,stt,offset,2,"Timer T3 Value (sec)",NULL,FMT_DEC,&hf_cops_pcmm_gate_spec_timer_t3);
offset += 2;
info_to_display(tvb,stt,offset,2,"Timer T4 Value (sec)",NULL,FMT_DEC,&hf_cops_pcmm_gate_spec_timer_t4);
offset += 2;
return offset;
}
static int
cops_classifier(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean extended) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,
extended ? "Extended Classifier" : "Classifier");
offset += 4;
info_to_display(tvb,stt,offset,2,"Protocol ID",NULL,FMT_DEC,&hf_cops_pcmm_classifier_protocol_id);
offset += 2;
info_to_display(tvb,stt,offset,1,"DS Field (DSCP or TOS)",NULL,FMT_HEX,&hf_cops_pcmm_classifier_dscp_tos_field);
offset += 1;
info_to_display(tvb,stt,offset,1,"DS Field (DSCP or TOS) Mask",NULL,FMT_HEX,&hf_cops_pcmm_classifier_dscp_tos_mask);
offset += 1;
info_to_display(tvb,stt,offset,4,"Source IP Address",NULL,FMT_IPv4,&hf_cops_pcmm_classifier_src_addr);
offset += 4;
if (extended) {
info_to_display(tvb,stt,offset,4,"Source Mask",NULL,FMT_IPv4,&hf_cops_pcmm_classifier_src_mask);
offset += 4;
}
info_to_display(tvb,stt,offset,4,"Destination IP Address",NULL,FMT_IPv4,&hf_cops_pcmm_classifier_dst_addr);
offset += 4;
if (extended) {
info_to_display(tvb,stt,offset,4,"Destination Mask",NULL,FMT_IPv4,&hf_cops_pcmm_classifier_dst_mask);
offset += 4;
}
info_to_display(tvb,stt,offset,2,"Source IP Port",NULL,FMT_DEC,&hf_cops_pcmm_classifier_src_port);
offset += 2;
if (extended) {
info_to_display(tvb,stt,offset,2,"Source Port End",NULL,FMT_DEC,&hf_cops_pcmm_classifier_src_port_end);
offset += 2;
}
info_to_display(tvb,stt,offset,2,"Destination IP Port",NULL,FMT_DEC,&hf_cops_pcmm_classifier_dst_port);
offset += 2;
if (extended) {
info_to_display(tvb,stt,offset,2,"Destination Port End",NULL,FMT_DEC,&hf_cops_pcmm_classifier_dst_port_end);
offset += 2;
}
if (extended) {
info_to_display(tvb,stt,offset,2,"ClassifierID",NULL,FMT_HEX,&hf_cops_pcmm_classifier_classifier_id);
offset += 2;
}
info_to_display(tvb,stt,offset,1,"Priority",NULL,FMT_HEX,&hf_cops_pcmm_classifier_priority);
offset += 1;
if (extended) {
info_to_display(tvb,stt,offset,1,"Activation State",NULL,FMT_HEX,&hf_cops_pcmm_classifier_activation_state);
offset += 1;
info_to_display(tvb,stt,offset,1,"Action",NULL,FMT_HEX,&hf_cops_pcmm_classifier_action);
offset += 1;
}
offset += 3;
return offset;
}
static int
cops_ipv6_classifier(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset, "IPv6 Classifier");
offset += 4;
info_to_display(tvb,stt,offset,1,"Flags",NULL,FMT_HEX,&hf_cops_pcmm_classifier_flags);
offset += 1;
info_to_display(tvb,stt,offset,1,"tc-low",NULL,FMT_HEX,&hf_cops_pcmm_classifier_tc_low);
offset += 1;
info_to_display(tvb,stt,offset,1,"tc-high",NULL,FMT_HEX,&hf_cops_pcmm_classifier_tc_high);
offset += 1;
info_to_display(tvb,stt,offset,1,"tc-mask",NULL,FMT_HEX,&hf_cops_pcmm_classifier_tc_mask);
offset += 1;
info_to_display(tvb,stt,offset,4,"Flow Label",NULL,FMT_HEX,&hf_cops_pcmm_classifier_flow_label);
offset += 4;
info_to_display(tvb,stt,offset,2,"Next Header Type",NULL,FMT_DEC,&hf_cops_pcmm_classifier_next_header_type);
offset += 2;
info_to_display(tvb,stt,offset,1,"Source Prefix Length",NULL,FMT_DEC,&hf_cops_pcmm_classifier_source_prefix_length);
offset += 1;
info_to_display(tvb,stt,offset,1,"Destination Prefix Length",NULL,FMT_DEC,&hf_cops_pcmm_classifier_destination_prefix_length);
offset += 1;
info_to_display(tvb,stt,offset,16,"IPv6 Source Address",NULL,FMT_IPv6,&hf_cops_pcmm_classifier_src_addr_v6);
offset += 16;
info_to_display(tvb,stt,offset,16,"IPv6 Destination Address",NULL,FMT_IPv6,&hf_cops_pcmm_classifier_dst_addr_v6);
offset += 16;
info_to_display(tvb,stt,offset,2,"Source Port Start",NULL,FMT_DEC,&hf_cops_pcmm_classifier_src_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Source Port End",NULL,FMT_DEC,&hf_cops_pcmm_classifier_src_port_end);
offset += 2;
info_to_display(tvb,stt,offset,2,"Destination Port Start",NULL,FMT_DEC,&hf_cops_pcmm_classifier_dst_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Destination Port End",NULL,FMT_DEC,&hf_cops_pcmm_classifier_dst_port_end);
offset += 2;
info_to_display(tvb,stt,offset,2,"ClassifierID",NULL,FMT_HEX,&hf_cops_pcmm_classifier_classifier_id);
offset += 2;
info_to_display(tvb,stt,offset,1,"Priority",NULL,FMT_HEX,&hf_cops_pcmm_classifier_priority);
offset += 1;
info_to_display(tvb,stt,offset,1,"Activation State",NULL,FMT_HEX,&hf_cops_pcmm_classifier_activation_state);
offset += 1;
info_to_display(tvb,stt,offset,1,"Action",NULL,FMT_HEX,&hf_cops_pcmm_classifier_action);
offset += 1;
offset += 3;
return offset;
}
static int
cops_flow_spec(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Flow Spec");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_flow_spec_envelope);
offset += 1;
info_to_display(tvb,stt,offset,1,"Service Number",NULL,FMT_DEC,&hf_cops_pcmm_flow_spec_service_number);
offset += 1;
info_to_display(tvb,stt,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
ti = proto_tree_add_text(stt, tvb, offset, 28, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,4,"Token Bucket Rate",NULL,FMT_FLT,&hf_cops_pc_token_bucket_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Token Bucket Size",NULL,FMT_FLT,&hf_cops_pc_token_bucket_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Peak Data Rate",NULL,FMT_FLT,&hf_cops_pc_peak_data_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Policed Unit",NULL,FMT_DEC,&hf_cops_pc_min_policed_unit);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Packet Size",NULL,FMT_DEC,&hf_cops_pc_max_packet_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Rate",NULL,FMT_FLT,&hf_cops_pc_spec_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Slack Term",NULL,FMT_DEC,&hf_cops_pc_slack_term);
offset += 4;
if (n < 64) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 28, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,4,"Token Bucket Rate",NULL,FMT_FLT,&hf_cops_pc_token_bucket_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Token Bucket Size",NULL,FMT_FLT,&hf_cops_pc_token_bucket_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Peak Data Rate",NULL,FMT_FLT,&hf_cops_pc_peak_data_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Policed Unit",NULL,FMT_DEC,&hf_cops_pc_min_policed_unit);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Packet Size",NULL,FMT_DEC,&hf_cops_pc_max_packet_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Rate",NULL,FMT_FLT,&hf_cops_pc_spec_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Slack Term",NULL,FMT_DEC,&hf_cops_pc_slack_term);
offset += 4;
if (n < 92) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 28, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,4,"Token Bucket Rate",NULL,FMT_FLT,&hf_cops_pc_token_bucket_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Token Bucket Size",NULL,FMT_FLT,&hf_cops_pc_token_bucket_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Peak Data Rate",NULL,FMT_FLT,&hf_cops_pc_peak_data_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Policed Unit",NULL,FMT_DEC,&hf_cops_pc_min_policed_unit);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Packet Size",NULL,FMT_DEC,&hf_cops_pc_max_packet_size);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Rate",NULL,FMT_FLT,&hf_cops_pc_spec_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Slack Term",NULL,FMT_DEC,&hf_cops_pc_slack_term);
offset += 4;
return offset;
}
static int
cops_docsis_service_class_name(tvbuff_t *tvb, proto_tree *st, guint object_len, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,object_len,offset,"DOCSIS Service Class Name");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
if (object_len >= 12) {
proto_tree_add_item(stt, hf_cops_pcmm_docsis_scn, tvb, offset, object_len - 8, ENC_ASCII|ENC_NA);
offset += object_len - 8;
} else {
proto_tree_add_text(stt, tvb, offset - 8, 2, "Invalid object length: %u", object_len);
}
return offset;
}
static int
cops_best_effort_service_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Best Effort Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_non_real_time_polling_service_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Non-Real-Time Polling Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 64) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 92) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_real_time_polling_service_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Real-Time Polling Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 64) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 92) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Maximum Concatenated Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_concat_burst);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_unsolicited_grant_service_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Unsolicited Grant Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 28 : 24, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 40) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 28 : 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 28 : 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_ugs_with_activity_detection_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Unsolicited Grant Service with Activity Detection");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 36 : 32, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_downstream_service_i04_i05(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset, gboolean i05) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Downstream Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
info_to_display(tvb,object_tree,offset,1,"Downstream Resequencing",NULL,FMT_HEX,&hf_cops_pcmm_down_resequencing);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 2, "Reserved");
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Downstream Peak Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_down_peak_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
info_to_display(tvb,object_tree,offset,1,"Downstream Resequencing",NULL,FMT_HEX,&hf_cops_pcmm_down_resequencing);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 2, "Reserved");
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Downstream Peak Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_down_peak_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, i05 ? 40 : 36, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
info_to_display(tvb,object_tree,offset,1,"Downstream Resequencing",NULL,FMT_HEX,&hf_cops_pcmm_down_resequencing);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 2, "Reserved");
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Downstream Peak Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_down_peak_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Required Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_req_att_mask);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Forbidden Attribute Mask",NULL,FMT_DEC,&hf_cops_pcmm_forbid_att_mask);
offset += 4;
if (i05) {
info_to_display(tvb,object_tree,offset,4,"Attribute Aggregation Rule Mask",NULL,FMT_DEC,&hf_cops_pcmm_att_aggr_rule_mask);
offset += 4;
}
return offset;
}
static int
cops_upstream_drop_i04(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Upstream Drop");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
return offset;
}
static int
cops_best_effort_service(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Best Effort Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
return offset;
}
static int
cops_non_real_time_polling_service(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Non-Real-Time Polling Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 28, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
if (n < 64) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
if (n < 92) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
return offset;
}
static int
cops_real_time_polling_service(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Real-Time Polling Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 28, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
if (n < 64) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
if (n < 92) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
return offset;
}
static int
cops_unsolicited_grant_service(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Unsolicited Grant Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 16, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
if (n < 40) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 16, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 16, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
return offset;
}
static int
cops_ugs_with_activity_detection(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Unsolicited Grant Service with Activity Detection");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
decode_docsis_request_transmission_policy(tvb, offset, object_tree, hf_cops_pcmm_request_transmission_policy);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Unsolicited Grant Size",NULL,FMT_DEC,&hf_cops_pcmm_unsolicited_grant_size);
offset += 2;
info_to_display(tvb,object_tree,offset,1,"Grants Per Interval",NULL,FMT_DEC,&hf_cops_pcmm_grants_per_interval);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 1, "Reserved");
offset += 1;
info_to_display(tvb,object_tree,offset,4,"Nominal Grant Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_grant_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Grant Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_grant_jitter);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Nominal Polling Interval",NULL,FMT_DEC,&hf_cops_pcmm_nominal_polling_interval);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Tolerated Poll Jitter",NULL,FMT_DEC,&hf_cops_pcmm_tolerated_poll_jitter);
offset += 4;
return offset;
}
static int
cops_downstream_service(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_item *ti;
proto_tree *stt, *object_tree;
stt = info_to_cops_subtree(tvb,st,n,offset,"Downstream Service");
offset += 4;
info_to_display(tvb,stt,offset,1,"Envelope",NULL,FMT_DEC,&hf_cops_pcmm_envelope);
offset += 1;
proto_tree_add_text(stt, tvb, offset, 3, "Reserved");
offset += 3;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Authorized Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
if (n < 56) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Reserved Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
if (n < 80) return offset;
ti = proto_tree_add_text(stt, tvb, offset, 24, "Committed Envelope");
object_tree = proto_item_add_subtree(ti, ett_cops_subtree);
info_to_display(tvb,object_tree,offset,1,"Traffic Priority",NULL,FMT_HEX,&hf_cops_pcmm_traffic_priority);
offset += 1;
proto_tree_add_text(object_tree, tvb, offset, 3, "Reserved");
offset += 3;
info_to_display(tvb,object_tree,offset,4,"Maximum Sustained Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_max_sustained_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Maximum Traffic Burst",NULL,FMT_DEC,&hf_cops_pcmm_max_traffic_burst);
offset += 4;
info_to_display(tvb,object_tree,offset,4,"Minimum Reserved Traffic Rate",NULL,FMT_DEC,&hf_cops_pcmm_min_reserved_traffic_rate);
offset += 4;
info_to_display(tvb,object_tree,offset,2,"Assumed Minimum Reserved Traffic Rate Packet Size",NULL,FMT_DEC,&hf_cops_pcmm_ass_min_rtr_packet_size);
offset += 2;
info_to_display(tvb,object_tree,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,object_tree,offset,4,"Maximum Downstream Latency",NULL,FMT_DEC,&hf_cops_pcmm_max_downstream_latency);
offset += 4;
return offset;
}
static void
cops_mm_event_generation_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
guint8 *bcid_str;
stt = info_to_cops_subtree(tvb,st,n,offset,"Event Generation Info");
offset += 4;
info_to_display(tvb,stt,offset,4,"PRKS IP Address", NULL,FMT_IPv4,&hf_cops_pc_prks_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"PRKS IP Port",NULL,FMT_DEC,&hf_cops_pc_prks_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,stt,offset,4,"SRKS IP Address", NULL,FMT_IPv4,&hf_cops_pc_srks_ip);
offset += 4;
info_to_display(tvb,stt,offset,2,"SRKS IP Port",NULL,FMT_DEC,&hf_cops_pc_srks_ip_port);
offset += 2;
info_to_display(tvb,stt,offset,2,"Reserved",NULL,FMT_HEX,&hf_cops_pc_reserved);
offset += 2;
info_to_display(tvb,stt,offset,4,"BCID - Timestamp",NULL,FMT_HEX,&hf_cops_pc_bcid_ts);
offset += 4;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Element ID",bcid_str);
offset += 8;
bcid_str = (guchar*)tvb_format_text(tvb, offset, 8);
proto_tree_add_text(stt, tvb, offset, 8,"%-28s : '%s'","BCID - Time Zone",bcid_str);
offset += 8;
info_to_display(tvb,stt,offset,4,"BCID - Event Counter",NULL,FMT_DEC,&hf_cops_pc_bcid_ev);
}
static int
cops_volume_based_usage_limit(tvbuff_t *tvb, proto_tree *st, guint object_len, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,object_len,offset,"Volume-Based Usage Limit");
offset += 4;
proto_tree_add_item(stt, hf_cops_pcmm_volume_based_usage_limit, tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int
cops_time_based_usage_limit(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Time-Based Usage Limit");
offset += 4;
info_to_display(tvb,stt,offset,4,"Time Limit", NULL,FMT_DEC,&hf_cops_pcmm_time_based_usage_limit);
offset += 4;
return offset;
}
static void
cops_opaque_data(tvbuff_t *tvb, proto_tree *st, guint object_len, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,object_len,offset,"Opaque Data");
offset += 4;
proto_tree_add_text(stt, tvb, offset, 8,"Opaque Data");
}
static int
cops_gate_time_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate Time Info");
offset += 4;
info_to_display(tvb,stt,offset,4,"Time Committed", NULL,FMT_DEC,&hf_cops_pcmm_gate_time_info);
offset += 4;
return offset;
}
static void
cops_gate_usage_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate Usage Info");
offset += 4;
info_to_display(tvb,stt,offset,8,"Octet Count", NULL,FMT_DEC,&hf_cops_pcmm_gate_usage_info);
}
static int
cops_packetcable_mm_error(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
guint16 code, subcode;
stt = info_to_cops_subtree(tvb,st,n,offset,"PacketCable Error");
offset += 4;
code = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(stt, hf_cops_pcmm_packetcable_error_code, tvb, offset, 2, code,
"Error Code: %s (%u)", val_to_str(code, pcmm_packetcable_error_code, "Unknown"),
code);
offset += 2;
subcode = tvb_get_ntohs(tvb, offset);
if (code == 6 || code == 7)
proto_tree_add_uint_format(stt, hf_cops_pcmm_packetcable_error_subcode,
tvb, offset, 2, code, "Error-Subcode: 0x%02x, S-Num: 0x%02x, S-Type: 0x%02x",
subcode, subcode >> 8, subcode & 0xf);
else
proto_tree_add_uint_format(stt, hf_cops_pcmm_packetcable_error_subcode,
tvb, offset, 2, code, "Error-Subcode: 0x%04x", subcode);
offset += 2;
return offset;
}
static int
cops_gate_state(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Gate State");
offset += 4;
info_to_display(tvb,stt,offset,2,"State",pcmm_gate_state,FMT_DEC,&hf_cops_pcmm_packetcable_gate_state);
offset += 2;
info_to_display(tvb,stt,offset,2,"Reason",pcmm_gate_state_reason,FMT_DEC,&hf_cops_pcmm_packetcable_gate_state_reason);
offset += 2;
return offset;
}
static int
cops_version_info(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Version Info");
offset += 4;
info_to_display(tvb,stt,offset,2,"Major Version Number",NULL,FMT_DEC,&hf_cops_pcmm_packetcable_version_info_major);
offset += 2;
info_to_display(tvb,stt,offset,2,"Minor Version Number",NULL,FMT_DEC,&hf_cops_pcmm_packetcable_version_info_minor);
offset += 2;
return offset;
}
static void
cops_psid(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"PSID");
offset += 4;
info_to_display(tvb,stt,offset,4,"PSID", NULL,FMT_DEC,&hf_cops_pcmm_psid);
}
static int
cops_synch_options(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Synch Options");
offset += 4;
proto_tree_add_text(stt, tvb, offset, 2, "Reserved");
offset += 2;
info_to_display(tvb,stt,offset,1,"Report Type", pcmm_report_type_vals,FMT_DEC,&hf_cops_pcmm_synch_options_report_type);
offset += 1;
info_to_display(tvb,stt,offset,1,"Synch Type", pcmm_synch_type_vals,FMT_DEC,&hf_cops_pcmm_synch_options_synch_type);
offset += 1;
return offset;
}
static void
cops_msg_receipt_key(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"Msg Receipt Key");
offset += 4;
info_to_display(tvb,stt,offset,4,"Msg Receipt Key", NULL,FMT_HEX,&hf_cops_pcmm_msg_receipt_key);
}
static void
cops_userid(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb, st, n, offset, "UserID");
offset += 4;
info_to_display(tvb, stt, offset, n-4, "UserID", NULL, FMT_STR, &hf_cops_pcmm_userid);
}
static void
cops_sharedresourceid(tvbuff_t *tvb, proto_tree *st, guint n, guint32 offset) {
proto_tree *stt;
stt = info_to_cops_subtree(tvb,st,n,offset,"SharedResourceID");
offset += 4;
info_to_display(tvb,stt,offset,4,"SharedResourceID", NULL,FMT_HEX,&hf_cops_pcmm_sharedresourceid);
}
static void
cops_analyze_packetcable_dqos_obj(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 op_code, guint32 offset) {
gint remdata;
guint16 object_len;
guint8 s_num, s_type;
guint16 num_type_glob;
if ( cops_packetcable == FALSE ) {
return;
}
remdata = tvb_length_remaining(tvb, offset);
while (remdata > 4) {
object_len = tvb_get_ntohs(tvb, offset);
if (object_len < 4) {
proto_tree_add_text(tree, tvb, offset, 2,
"Incorrect PacketCable object length %u < 4", object_len);
return;
}
s_num = tvb_get_guint8(tvb, offset + 2);
s_type = tvb_get_guint8(tvb, offset + 3);
num_type_glob = s_num << 8 | s_type;
switch (num_type_glob){
case PCDQ_TRANSACTION_ID:
cops_transaction_id(tvb, pinfo, tree, op_code, object_len, offset);
break;
case PCDQ_SUBSCRIBER_IDv4:
cops_subscriber_id_v4(tvb, tree, object_len, offset);
break;
case PCDQ_SUBSCRIBER_IDv6:
cops_subscriber_id_v6(tvb, tree, object_len, offset);
break;
case PCDQ_GATE_ID:
cops_gate_id(tvb, tree, object_len, offset);
break;
case PCDQ_ACTIVITY_COUNT:
cops_activity_count(tvb, tree, object_len, offset);
break;
case PCDQ_GATE_SPEC:
cops_gate_specs(tvb, tree, object_len, offset);
break;
case PCDQ_REMOTE_GATE_INFO:
cops_remote_gate_info(tvb, tree, object_len, offset);
break;
case PCDQ_EVENT_GENERATION_INFO:
cops_event_generation_info(tvb, tree, object_len, offset);
break;
case PCDQ_PACKETCABLE_ERROR:
cops_packetcable_error(tvb, tree, object_len, offset);
break;
case PCDQ_ELECTRONIC_SURVEILLANCE:
cops_surveillance_parameters(tvb, tree, object_len, offset);
break;
case PCDQ_PACKETCABLE_REASON:
cops_packetcable_reason(tvb, tree, object_len, offset);
break;
}
offset += object_len;
remdata = tvb_length_remaining(tvb, offset);
}
}
static void
decode_docsis_request_transmission_policy(tvbuff_t *tvb, guint32 offset, proto_tree *tree, gint hf) {
proto_tree *drtp_tree;
proto_item *item;
guint32 policy = tvb_get_ntohl(tvb, offset);
int i;
char bit_fld[48];
static const value_string drtp_vals[] = {
{ 1 << 0, "The Service Flow MUST NOT use \"all CMs\" broadcast request opportunities" },
{ 1 << 1, "The Service Flow MUST NOT use Priority Request multicast request opportunities" },
{ 1 << 2, "The Service Flow MUST NOT use Request/Data opportunities for Requests" },
{ 1 << 3, "The Service Flow MUST NOT use Request/Data opportunities for Data" },
{ 1 << 4, "The Service Flow MUST NOT piggyback requests with data" },
{ 1 << 5, "The Service Flow MUST NOT concatenate data" },
{ 1 << 6, "The Service Flow MUST NOT fragment data" },
{ 1 << 7, "The Service Flow MUST NOT suppress payload headers" },
{ 1 << 8, "The Service Flow MUST drop packets that do not fit in the Unsolicited Grant Size" },
{ 0, NULL }
};
item = proto_tree_add_item (tree, hf, tvb, offset, 4, ENC_BIG_ENDIAN);
drtp_tree = proto_item_add_subtree(item, ett_docsis_request_transmission_policy);
for (i = 0 ; i <= 8; i++) {
if (policy & drtp_vals[i].value) {
decode_bitfield_value(bit_fld, policy, drtp_vals[i].value, 32);
proto_tree_add_text(drtp_tree, tvb, offset, 4, "%s%s",
bit_fld, drtp_vals[i].strptr);
}
}
}
static void
cops_analyze_packetcable_mm_obj(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 op_code, guint32 offset) {
guint16 object_len;
guint8 s_num, s_type;
guint16 num_type_glob;
if ( cops_packetcable == FALSE ) {
return;
}
while (tvb_reported_length_remaining(tvb, offset) > 4) {
object_len = tvb_get_ntohs(tvb, offset);
if (object_len < 4) {
proto_tree_add_text(tree, tvb, offset, 2,
"Incorrect PacketCable object length %u < 4", object_len);
return;
}
s_num = tvb_get_guint8(tvb, offset + 2);
s_type = tvb_get_guint8(tvb, offset + 3);
num_type_glob = s_num << 8 | s_type;
switch (num_type_glob){
case PCMM_TRANSACTION_ID:
cops_mm_transaction_id(tvb, pinfo, tree, op_code, object_len, offset);
break;
case PCMM_AMID:
cops_amid(tvb, tree, object_len, offset);
break;
case PCMM_SUBSCRIBER_ID:
cops_subscriber_id_v4(tvb, tree, object_len, offset);
break;
case PCMM_SUBSCRIBER_ID_V6:
cops_subscriber_id_v6(tvb, tree, object_len, offset);
break;
case PCMM_GATE_ID:
cops_gate_id(tvb, tree, object_len, offset);
break;
case PCMM_GATE_SPEC:
cops_mm_gate_spec(tvb, tree, object_len, offset);
break;
case PCMM_CLASSIFIER:
cops_classifier(tvb, tree, object_len, offset, FALSE);
break;
case PCMM_EXTENDED_CLASSIFIER:
cops_classifier(tvb, tree, object_len, offset, TRUE);
break;
case PCMM_IPV6_CLASSIFIER:
cops_ipv6_classifier(tvb, tree, object_len, offset);
break;
case PCMM_FLOW_SPEC:
cops_flow_spec(tvb, tree, object_len, offset);
break;
case PCMM_DOCSIS_SERVICE_CLASS_NAME:
cops_docsis_service_class_name(tvb, tree, object_len, offset);
break;
case PCMM_BEST_EFFORT_SERVICE:
if (object_len == 44 || object_len == 80 || object_len == 116)
cops_best_effort_service_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 40 || object_len == 72 || object_len == 104)
cops_best_effort_service_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_best_effort_service(tvb, tree, object_len, offset);
break;
case PCMM_NON_REAL_TIME_POLLING_SERVICE:
if (object_len == 48 || object_len == 88 || object_len == 128)
cops_non_real_time_polling_service_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 44 || object_len == 80 || object_len == 116)
cops_non_real_time_polling_service_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_non_real_time_polling_service(tvb, tree, object_len, offset);
break;
case PCMM_REAL_TIME_POLLING_SERVICE:
if (object_len == 48 || object_len == 88 || object_len == 128)
cops_real_time_polling_service_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 44 || object_len == 80 || object_len == 116)
cops_real_time_polling_service_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_real_time_polling_service(tvb, tree, object_len, offset);
break;
case PCMM_UNSOLICITED_GRANT_SERVICE:
if (object_len == 36 || object_len == 64 || object_len == 92)
cops_unsolicited_grant_service_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 32 || object_len == 56 || object_len == 80)
cops_unsolicited_grant_service_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_unsolicited_grant_service(tvb, tree, object_len, offset);
break;
case PCMM_UGS_WITH_ACTIVITY_DETECTION:
if (object_len == 44 || object_len == 80 || object_len == 116)
cops_ugs_with_activity_detection_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 40 || object_len == 72 || object_len == 104)
cops_ugs_with_activity_detection_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_ugs_with_activity_detection(tvb, tree, object_len, offset);
break;
case PCMM_DOWNSTREAM_SERVICE:
if (object_len == 48 || object_len == 88 || object_len == 128)
cops_downstream_service_i04_i05(tvb, tree, object_len, offset, TRUE);
else if (object_len == 40 || object_len == 72 || object_len == 104)
cops_downstream_service_i04_i05(tvb, tree, object_len, offset, FALSE);
else
cops_downstream_service(tvb, tree, object_len, offset);
break;
case PCMM_UPSTREAM_DROP:
cops_upstream_drop_i04(tvb, tree, object_len, offset);
break;
case PCMM_EVENT_GENERATION_INFO:
cops_mm_event_generation_info(tvb, tree, object_len, offset);
break;
case PCMM_VOLUME_BASED_USAGE_LIMIT:
cops_volume_based_usage_limit(tvb, tree, object_len, offset);
break;
case PCMM_TIME_BASED_USAGE_LIMIT:
cops_time_based_usage_limit(tvb, tree, object_len, offset);
break;
case PCMM_OPAQUE_DATA:
cops_opaque_data(tvb, tree, object_len, offset);
break;
case PCMM_GATE_TIME_INFO:
cops_gate_time_info(tvb, tree, object_len, offset);
break;
case PCMM_GATE_USAGE_INFO:
cops_gate_usage_info(tvb, tree, object_len, offset);
break;
case PCMM_PACKETCABLE_ERROR:
cops_packetcable_mm_error(tvb, tree, object_len, offset);
break;
case PCMM_GATE_STATE:
cops_gate_state(tvb, tree, object_len, offset);
break;
case PCMM_VERSION_INFO:
cops_version_info(tvb, tree, object_len, offset);
break;
case PCMM_PSID:
cops_psid(tvb, tree, object_len, offset);
break;
case PCMM_SYNCH_OPTIONS:
cops_synch_options(tvb, tree, object_len, offset);
break;
case PCMM_MSG_RECEIPT_KEY:
cops_msg_receipt_key(tvb, tree, object_len, offset);
break;
case PCMM_USERID:
cops_userid(tvb, tree, object_len, offset);
break;
case PCMM_SHAREDRESOURCEID:
cops_sharedresourceid(tvb, tree, object_len, offset);
break;
}
offset += object_len;
}
}
