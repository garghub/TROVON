static int
dissect_lisp_locator(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_mapping_tree)
{
gint offset = 0;
guint8 prio, weight, m_prio, m_weight;
guint16 flags, loc_afi;
guint32 locator_v4;
struct e_in6_addr locator_v6;
tvbuff_t *next_tvb;
prio = tvb_get_guint8(tvb, offset); offset += 1;
weight = tvb_get_guint8(tvb, offset); offset += 1;
m_prio = tvb_get_guint8(tvb, offset); offset += 1;
m_weight = tvb_get_guint8(tvb, offset); offset += 1;
flags = tvb_get_ntohs(tvb, offset); offset += 2;
loc_afi = tvb_get_ntohs(tvb, offset); offset += 2;
switch (loc_afi) {
case AFNUM_INET:
locator_v4 = tvb_get_ipv4(tvb, offset);
proto_tree_add_text(lisp_mapping_tree, tvb, 0, 8 + INET_ADDRLEN,
"%sRLOC: %s%s, %s, Priority/Weight: %d/%d, Multicast Priority/Weight: %d/%d",
(flags&LOCAL_BIT_MASK) ? "Local " : "",
ip_to_str((guint8 *)&locator_v4),
(flags&PROBE_BIT_MASK) ? " (probed)" : "",
(flags&REACH_BIT_MASK) ? "Reachable" : "Unreachable",
prio, weight, m_prio, m_weight);
offset += INET_ADDRLEN;
break;
case AFNUM_INET6:
tvb_get_ipv6(tvb, offset, &locator_v6);
proto_tree_add_text(lisp_mapping_tree, tvb, 0, 8 + INET6_ADDRLEN,
"%sRLOC: %s%s, %s, Priority/Weight: %d/%d, Multicast Priority/Weight: %d/%d",
(flags&LOCAL_BIT_MASK) ? "Local " : "",
ip6_to_str(&locator_v6),
(flags&PROBE_BIT_MASK) ? " (probed)" : "",
(flags&REACH_BIT_MASK) ? "Reachable" : "Unreachable",
prio, weight, m_prio, m_weight);
offset += INET6_ADDRLEN;
break;
default:
proto_tree_add_text(lisp_mapping_tree, tvb, 0, 2, "Unexpected AFI, cannot decode");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_mapping_tree);
}
return offset;
}
static int
dissect_lisp_mapping(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_tree, guint8 rec_cnt)
{
int i;
gint offset = 0;
gint mapver_offset = 0;
guint32 ttl;
guint8 loc_cnt;
guint8 prefix_mask, flags, act;
guint16 prefix_afi;
guint32 prefix_v4;
struct e_in6_addr prefix_v6;
proto_item *tir;
proto_tree *lisp_mapping_tree;
tvbuff_t *next_tvb;
const char *lisp_actions[] = {
"No-Action",
"Natively-Forward",
"Send-Map-Request",
"Drop",
"Illegal action value"
};
ttl = tvb_get_ntohl(tvb, offset); offset += 4;
loc_cnt = tvb_get_guint8(tvb, offset); offset += 1;
prefix_mask = tvb_get_guint8(tvb, offset); offset += 1;
flags = tvb_get_guint8(tvb, offset); offset += 2;
mapver_offset = offset; offset += 2;
prefix_afi = tvb_get_ntohs(tvb, offset); offset += 2;
act = flags & LISP_MAP_ACT;
act >>= 5;
if (act > 3) act = 4;
switch (prefix_afi) {
case AFNUM_INET:
prefix_v4 = tvb_get_ipv4(tvb, offset);
tir = proto_tree_add_text(lisp_tree, tvb, 0, 12 + INET_ADDRLEN,
"EID prefix: %s/%d, TTL: %s, %sAuthoritative, %s",
ip_to_str((guint8 *)&prefix_v4), prefix_mask,
(ttl == 0xFFFFFFFF) ? "Unlimited" : g_strdup_printf("%d", ttl),
(flags&LISP_MAP_AUTH) ? "" : "Not ", lisp_actions[act]);
offset += INET_ADDRLEN;
if (rec_cnt == 1)
col_append_fstr(pinfo->cinfo, COL_INFO, " for %s/%d",
ip_to_str((guint8 *)&prefix_v4), prefix_mask);
break;
case AFNUM_INET6:
tvb_get_ipv6(tvb, offset, &prefix_v6);
tir = proto_tree_add_text(lisp_tree, tvb, 0, 12 + INET6_ADDRLEN,
"EID prefix: %s/%d, TTL: %s, %sAuthoritative, %s",
ip6_to_str(&prefix_v6), prefix_mask,
(ttl == 0xFFFFFFFF) ? "Unlimited" : g_strdup_printf("%d", ttl),
(flags&LISP_MAP_AUTH) ? "" : "Not ", lisp_actions[act]);
offset += INET6_ADDRLEN;
if (rec_cnt == 1)
col_append_fstr(pinfo->cinfo, COL_INFO, " for %s/%d",
ip6_to_str(&prefix_v6), prefix_mask);
break;
default:
proto_tree_add_text(lisp_tree, tvb, 0, 2, "Unexpected AFI, cannot decode");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
return offset;
}
lisp_mapping_tree = proto_item_add_subtree(tir, ett_lisp_mapping);
proto_tree_add_item(lisp_mapping_tree, hf_lisp_mapping_res, tvb, mapver_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_mapping_tree, hf_lisp_mapping_ver, tvb, mapver_offset, 2, ENC_BIG_ENDIAN);
for(i=0; i < loc_cnt; i++) {
tvbuff_t *loc_tvb;
int len = 0;
loc_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_lisp_locator(loc_tvb, pinfo, lisp_mapping_tree);
offset += len;
}
return offset;
}
static void
dissect_lisp_map_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_tree)
{
int i;
gint offset = 0;
gboolean mrep = FALSE;
guint8 flags;
guint8 itr_rec_cnt = 0;
guint8 rec_cnt = 0;
guint16 src_eid_afi;
struct e_in6_addr e_in6_addr;
tvbuff_t *next_tvb;
flags = tvb_get_guint8(tvb, offset);
mrep = flags & (MAP_REQ_FLAG_M >> 16);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_auth, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_mrp, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_probe, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_smr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_pitr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_flags_smri, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_res, tvb, offset, 3, ENC_BIG_ENDIAN);
itr_rec_cnt = tvb_get_guint8(tvb, offset + 2) & 0x1F;
proto_tree_add_item(lisp_tree, hf_lisp_irc, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
rec_cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lisp_tree, hf_lisp_nonce, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
src_eid_afi = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_mreq_srceid_afi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (src_eid_afi) {
case AFNUM_RESERVED:
proto_tree_add_text(lisp_tree, tvb, offset, 0, "(Source EID not present)");
break;
case AFNUM_INET:
proto_tree_add_ipv4(lisp_tree,
hf_lisp_mreq_srceid, tvb, offset, INET_ADDRLEN, tvb_get_ipv4(tvb, offset));
offset += INET_ADDRLEN;
break;
case AFNUM_INET6:
tvb_get_ipv6(tvb, offset, &e_in6_addr);
proto_tree_add_ipv6(lisp_tree,
hf_lisp_mreq_srceidv6, tvb, offset, INET6_ADDRLEN, (guint8 *)&e_in6_addr);
offset += INET6_ADDRLEN;
break;
default:
proto_tree_add_text(lisp_tree, tvb, offset, 0,
"Unexpected Source EID AFI, cannot decode");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
return;
}
for(i=0; i < itr_rec_cnt+1; i++) {
guint16 itr_afi;
guint32 itr_rloc_v4;
struct e_in6_addr itr_rloc_v6;
proto_item *tir;
proto_tree *lisp_itr_tree;
itr_afi = tvb_get_ntohs(tvb, offset);
switch (itr_afi) {
case AFNUM_INET:
itr_rloc_v4 = tvb_get_ipv4(tvb, offset + 2);
tir = proto_tree_add_text(lisp_tree, tvb, offset, INET_ADDRLEN + 2,
"ITR-RLOC %d: %s", i + 1, ip_to_str((guint8 *)&itr_rloc_v4));
lisp_itr_tree = proto_item_add_subtree(tir, ett_lisp_itr);
proto_tree_add_text(lisp_itr_tree, tvb, offset, 2, "ITR-RLOC-AFI: %d", itr_afi);
proto_tree_add_ipv4(lisp_itr_tree, hf_lisp_mreq_srcitr, tvb, offset + 2,
INET_ADDRLEN, itr_rloc_v4);
offset += INET_ADDRLEN + 2;
break;
case AFNUM_INET6:
tvb_get_ipv6(tvb, offset + 2, &itr_rloc_v6);
tir = proto_tree_add_text(lisp_tree, tvb, offset, INET6_ADDRLEN + 2,
"ITR-RLOC %d: %s", i + 1, ip6_to_str(&itr_rloc_v6));
lisp_itr_tree = proto_item_add_subtree(tir, ett_lisp_itr);
proto_tree_add_text(lisp_itr_tree, tvb, offset, 2, "ITR-RLOC-AFI: %d", itr_afi);
proto_tree_add_ipv6(lisp_itr_tree, hf_lisp_mreq_srcitrv6, tvb, offset + 2,
INET6_ADDRLEN, (guint8 *)&itr_rloc_v6);
offset += INET6_ADDRLEN + 2;
break;
default:
proto_tree_add_text(lisp_tree, tvb, offset, 2,
"Unexpected ITR-RLOC-AFI, cannot decode");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
return;
}
}
for(i=0; i < rec_cnt; i++) {
guint8 reserved;
guint8 prefix_mask;
guint16 prefix_afi;
guint32 prefix_v4;
struct e_in6_addr prefix_v6;
proto_item *tir;
proto_tree *lisp_record_tree;
reserved = tvb_get_guint8(tvb, offset);
prefix_mask = tvb_get_guint8(tvb, offset + 1);
prefix_afi = tvb_get_ntohs(tvb, offset + 2);
switch (prefix_afi) {
case AFNUM_INET:
prefix_v4 = tvb_get_ipv4(tvb, offset + 4);
tir = proto_tree_add_text(lisp_tree, tvb, offset, 4 + INET_ADDRLEN,
"Record %d: %s/%d",
i+1, ip_to_str((guint8 *)&prefix_v4), prefix_mask);
if (rec_cnt == 1)
col_append_fstr(pinfo->cinfo, COL_INFO, " for %s/%d",
ip_to_str((guint8 *)&prefix_v4), prefix_mask);
lisp_record_tree = proto_item_add_subtree(tir, ett_lisp_record);
proto_tree_add_text(lisp_record_tree, tvb, offset, 1, "Reserved bits: 0x%02X",
reserved);
proto_tree_add_text(lisp_record_tree, tvb, offset + 1, 1, "Prefix length: %d",
prefix_mask);
proto_tree_add_text(lisp_record_tree, tvb, offset + 2, 2, "Prefix AFI: %d",
prefix_afi);
proto_tree_add_text(lisp_record_tree, tvb, offset + 4, INET_ADDRLEN, "Prefix: %s",
ip_to_str((guint8 *)&prefix_v4));
offset += 4 + INET_ADDRLEN;
break;
case AFNUM_INET6:
tvb_get_ipv6(tvb, offset + 4, &prefix_v6);
tir = proto_tree_add_text(lisp_tree, tvb, offset, 4 + INET6_ADDRLEN,
"Record %d: %s/%d",
i+1, ip6_to_str(&prefix_v6), prefix_mask);
if (rec_cnt == 1)
col_append_fstr(pinfo->cinfo, COL_INFO, " for %s/%d",
ip6_to_str(&prefix_v6), prefix_mask);
lisp_record_tree = proto_item_add_subtree(tir, ett_lisp_record);
proto_tree_add_text(lisp_record_tree, tvb, offset, 1, "Reserved bits: 0x%02X",
reserved);
proto_tree_add_text(lisp_record_tree, tvb, offset + 1, 1, "Prefix length: %d",
prefix_mask);
proto_tree_add_text(lisp_record_tree, tvb, offset + 2, 2, "Prefix AFI: %d",
prefix_afi);
proto_tree_add_text(lisp_record_tree, tvb, offset + 4, INET6_ADDRLEN, "Prefix: %s",
ip6_to_str(&prefix_v6));
offset += 4 + INET6_ADDRLEN;
break;
default:
proto_tree_add_text(lisp_tree, tvb, offset, 2, "Unexpected AFI, cannot decode");
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
return;
}
}
if (mrep) {
int len = 0;
tvbuff_t *rep_tvb;
proto_item *tim;
proto_tree *lisp_mr_tree;
tim = proto_tree_add_text(lisp_tree, tvb, offset, -1, "Map-Reply record");
lisp_mr_tree = proto_item_add_subtree(tim, ett_lisp_mr);
rep_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_lisp_mapping(rep_tvb, pinfo, lisp_mr_tree, 0);
offset += len;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
}
static void
dissect_lisp_map_reply(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_tree)
{
int i;
gint offset = 0;
guint8 rec_cnt = 0;
tvbuff_t *next_tvb;
proto_tree_add_item(lisp_tree, hf_lisp_mrep_flags_probe, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mrep_flags_enlr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mrep_res, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
rec_cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lisp_tree, hf_lisp_nonce, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
for(i=0; i < rec_cnt; i++) {
tvbuff_t *rec_tvb;
int len = 0;
rec_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_lisp_mapping(rec_tvb, pinfo, lisp_tree, rec_cnt);
offset += len;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
}
static void
dissect_lisp_map_register(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_tree)
{
int i;
gint offset = 0;
guint8 rec_cnt = 0;
tvbuff_t *next_tvb;
guint16 authlen = 0;
proto_tree_add_item(lisp_tree, hf_lisp_mreg_flags_pmr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreg_res, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(lisp_tree, hf_lisp_mreg_flags_wmn, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
rec_cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lisp_tree, hf_lisp_nonce, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(lisp_tree, hf_lisp_mreg_keyid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
authlen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_mreg_authlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lisp_tree, hf_lisp_mreg_auth, tvb, offset, authlen, ENC_NA);
offset += authlen;
for(i=0; i < rec_cnt; i++) {
tvbuff_t *rec_tvb;
int len = 0;
rec_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_lisp_mapping(rec_tvb, pinfo, lisp_tree, rec_cnt);
offset += len;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
}
static void
dissect_lisp_map_notify(tvbuff_t *tvb, packet_info *pinfo, proto_tree *lisp_tree)
{
int i;
gint offset = 0;
guint8 rec_cnt = 0;
tvbuff_t *next_tvb;
guint16 authlen = 0;
proto_tree_add_item(lisp_tree, hf_lisp_mnot_res, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
rec_cnt = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_records, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(lisp_tree, hf_lisp_nonce, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(lisp_tree, hf_lisp_mnot_keyid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
authlen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(lisp_tree, hf_lisp_mnot_authlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(lisp_tree, hf_lisp_mnot_auth, tvb, offset, authlen, ENC_NA);
offset += authlen;
for(i=0; i < rec_cnt; i++) {
tvbuff_t *rec_tvb;
int len = 0;
rec_tvb = tvb_new_subset_remaining(tvb, offset);
len = dissect_lisp_mapping(rec_tvb, pinfo, lisp_tree, rec_cnt);
offset += len;
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, lisp_tree);
}
static void
dissect_lisp_ecm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *lisp_tree)
{
tvbuff_t *next_tvb;
guint8 ip_ver;
proto_tree_add_item(lisp_tree, hf_lisp_ecm_res, tvb, 0, 4, ENC_BIG_ENDIAN);
next_tvb = tvb_new_subset_remaining(tvb, LISP_ECM_HEADER_LEN);
ip_ver = tvb_get_bits8(next_tvb, 0, 4);
switch (ip_ver) {
case 4:
call_dissector(ipv4_handle, next_tvb, pinfo, tree);
break;
case 6:
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
encapsulated = FALSE;
}
static int
dissect_lisp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 type;
proto_tree *lisp_tree = NULL;
col_clear(pinfo->cinfo, COL_INFO);
type = tvb_get_bits8(tvb, 0, 4);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LISP");
if (encapsulated) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Encapsulated %s", val_to_str(type, lisp_typevals,
"Unknown (0x%02x)"));
} else {
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(type, lisp_typevals,
"Unknown (0x%02x)"));
}
if (tree) {
proto_item *ti;
ti = proto_tree_add_item(tree, proto_lisp, tvb, 0,
(type == LISP_ECM) ? LISP_ECM_HEADER_LEN : -1, ENC_NA);
lisp_tree = proto_item_add_subtree(ti, ett_lisp);
proto_tree_add_item(lisp_tree,
hf_lisp_type, tvb, 0, 3, ENC_BIG_ENDIAN);
}
switch (type) {
case LISP_MAP_REQUEST:
dissect_lisp_map_request(tvb, pinfo, lisp_tree);
break;
case LISP_MAP_REPLY:
dissect_lisp_map_reply(tvb, pinfo, lisp_tree);
break;
case LISP_MAP_REGISTER:
dissect_lisp_map_register(tvb, pinfo, lisp_tree);
break;
case LISP_MAP_NOTIFY:
dissect_lisp_map_notify(tvb, pinfo, lisp_tree);
break;
case LISP_ECM:
encapsulated = TRUE;
dissect_lisp_ecm(tvb, pinfo, tree, lisp_tree);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
return tvb_length(tvb);
}
void
proto_register_lisp(void)
{
static hf_register_info hf[] = {
{ &hf_lisp_type,
{ "Type", "lisp.type",
FT_UINT24, BASE_DEC, VALS(lisp_typevals), 0xF00000, "LISP Control Message Type", HFILL }},
{ &hf_lisp_irc,
{ "ITR-RLOC Count", "lisp.irc",
FT_UINT24, BASE_DEC, NULL, 0x00001F, NULL, HFILL }},
{ &hf_lisp_records,
{ "Record Count", "lisp.records",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_nonce,
{ "Nonce", "lisp.nonce",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mreq_flags_auth,
{ "A bit (Authoritative)", "lisp.mreq.flags.auth",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_A, NULL, HFILL }},
{ &hf_lisp_mreq_flags_mrp,
{ "M bit (Map-Reply present)", "lisp.mreq.flags.mrp",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_M, NULL, HFILL }},
{ &hf_lisp_mreq_flags_probe,
{ "P bit (Probe)", "lisp.mreq.flags.probe",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_P, NULL, HFILL }},
{ &hf_lisp_mreq_flags_smr,
{ "S bit (Solicit-Map-Request)", "lisp.mreq.flags.smr",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_S, NULL, HFILL }},
{ &hf_lisp_mreq_flags_pitr,
{ "p bit (Proxy ITR)", "lisp.mreq.flags.pitr",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_p, NULL, HFILL }},
{ &hf_lisp_mreq_flags_smri,
{ "s bit (SMR-invoked)", "lisp.mreq.flags.smri",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REQ_FLAG_s, NULL, HFILL }},
{ &hf_lisp_mreq_res,
{ "Reserved bits", "lisp.mreq.res",
FT_UINT24, BASE_HEX, NULL, MAP_REQ_RESERVED, "Must be zero", HFILL }},
{ &hf_lisp_mreq_srceid_afi,
{ "Source EID AFI", "lisp.mreq.srceid_afi",
FT_UINT16, BASE_DEC, NULL, 0x0, "Source EID Address Family Indicator", HFILL }},
{ &hf_lisp_mreq_srceid,
{ "Source EID", "lisp.mreq.srceid",
FT_IPv4, BASE_NONE, NULL, 0x0, "Source EID Address", HFILL }},
{ &hf_lisp_mreq_srceidv6,
{ "Source EID", "lisp.mreq.srceidv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "Source EID Address", HFILL }},
{ &hf_lisp_mreq_srcitr,
{ "ITR-RLOC Address", "lisp.mreq.srcitr",
FT_IPv4, BASE_NONE, NULL, 0x0, "Originating ITR RLOC Address", HFILL }},
{ &hf_lisp_mreq_srcitrv6,
{ "ITR-RLOC Address", "lisp.mreq.srcitrv6",
FT_IPv6, BASE_NONE, NULL, 0x0, "Originating ITR RLOC Address", HFILL }},
{ &hf_lisp_mrep_flags,
{ "Flags", "lisp.mrep.flags",
FT_UINT8, BASE_HEX, NULL, 0x06, NULL, HFILL }},
{ &hf_lisp_mrep_flags_probe,
{ "P bit (Probe)", "lisp.mrep.flags.probe",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REP_FLAG_P, NULL, HFILL }},
{ &hf_lisp_mrep_flags_enlr,
{ "E bit (Echo-Nonce locator reachability algorithm enabled)", "lisp.mrep.flags.enlr",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REP_FLAG_E, NULL, HFILL }},
{ &hf_lisp_mrep_res,
{ "Reserved bits", "lisp.mrep.res",
FT_UINT24, BASE_HEX, NULL, MAP_REP_RESERVED, "Must be zero", HFILL }},
{ &hf_lisp_mreg_flags,
{ "Flags", "lisp.mreg.flags",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL }},
{ &hf_lisp_mreg_flags_pmr,
{ "P bit (Proxy-Map-Reply)", "lisp.mreg.flags.pmr",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REG_FLAG_P, NULL, HFILL }},
{ &hf_lisp_mreg_flags_wmn,
{ "M bit (Want-Map-Notify)", "lisp.mreg.flags.wmn",
FT_BOOLEAN, 24, TFS(&tfs_set_notset), MAP_REG_FLAG_M, NULL, HFILL }},
{ &hf_lisp_mreg_res,
{ "Reserved bits", "lisp.mreg.res",
FT_UINT24, BASE_HEX, NULL, MAP_REG_RESERVED, "Must be zero", HFILL }},
{ &hf_lisp_mreg_keyid,
{ "Key ID", "lisp.mreg.keyid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mreg_authlen,
{ "Authentication Data Length", "lisp.mreg.authlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mreg_auth,
{ "Authentication Data", "lisp.mreg.auth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mnot_res,
{ "Reserved bits", "lisp.mnot.res",
FT_UINT24, BASE_HEX, NULL, MAP_NOT_RESERVED, "Must be zero", HFILL }},
{ &hf_lisp_mnot_keyid,
{ "Key ID", "lisp.mnot.keyid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mnot_authlen,
{ "Authentication Data Length", "lisp.mnot.authlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mnot_auth,
{ "Authentication Data", "lisp.mnot.auth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_lisp_mapping_res,
{ "Reserved", "lisp.mapping.res",
FT_UINT16, BASE_HEX, NULL, 0xF000, NULL, HFILL }},
{ &hf_lisp_mapping_ver,
{ "Mapping Version", "lisp.mapping.ver",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL }},
{ &hf_lisp_ecm_res,
{ "Reserved bits", "lisp.ecm_res",
FT_UINT32, BASE_HEX, NULL, 0x0FFFFFFF, NULL, HFILL }},
};
static gint *ett[] = {
&ett_lisp,
&ett_lisp_mr,
&ett_lisp_mapping,
&ett_lisp_itr,
&ett_lisp_record
};
proto_lisp = proto_register_protocol("Locator/ID Separation Protocol",
"LISP Control", "lisp");
proto_register_field_array(proto_lisp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lisp(void)
{
dissector_handle_t lisp_handle;
lisp_handle = new_create_dissector_handle(dissect_lisp, proto_lisp);
dissector_add_uint("udp.port", LISP_CONTROL_PORT, lisp_handle);
ipv4_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
}
