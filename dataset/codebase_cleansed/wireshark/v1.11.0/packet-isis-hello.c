static void
dissect_hello_mt_port_cap_spb_mcid_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int MCID_LEN = 51;
const int SUBLEN = 2 * MCID_LEN;
if (sublen != SUBLEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPB MCID TLV (%d vs %d)", sublen, SUBLEN);
return;
}
else {
proto_tree *subtree, *ti;
const guint8 *mcid = tvb_get_ptr(tvb, offset, MCID_LEN);
const guint8 *aux_mcid = tvb_get_ptr(tvb, offset + MCID_LEN, MCID_LEN);
int i;
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB MCID: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_hello_clv_mt_port_cap_spb_mcid);
proto_tree_add_text( subtree, tvb, offset, MCID_LEN, "MCID:");
for (i = 0 ; i < 48 ; i+= 8, offset += 8) {
proto_tree_add_text( subtree, tvb, offset, 8,
" %02x %02x %02x %02x %02x %02x %02x %02x",
mcid[i+0], mcid[i+1], mcid[i+2], mcid[i+3],
mcid[i+4], mcid[i+5], mcid[i+6], mcid[i+7]);
}
proto_tree_add_text( subtree, tvb, offset, 3,
" %02x %02x %02x",
mcid[i+0], mcid[i+1], mcid[i+2]);
offset += 3;
proto_tree_add_text( subtree, tvb, offset, MCID_LEN, "Aux MCID:");
for (i = 0 ; i < 48 ; i+= 8, offset += 8) {
proto_tree_add_text( subtree, tvb, offset, 8,
" %02x %02x %02x %02x %02x %02x %02x %02x",
aux_mcid[i+0], aux_mcid[i+1], aux_mcid[i+2], aux_mcid[i+3],
aux_mcid[i+4], aux_mcid[i+5], aux_mcid[i+6], aux_mcid[i+7]);
}
proto_tree_add_text( subtree, tvb, offset, 3,
" %02x %02x %02x",
aux_mcid[i+0], aux_mcid[i+1], aux_mcid[i+2]);
}
}
static void
dissect_hello_mt_port_cap_spb_digest_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
const int DIGEST_LEN = 32;
const int SUBLEN = 1 + DIGEST_LEN;
if (sublen != SUBLEN) {
isis_dissect_unknown( tvb, tree, offset,
"Short SPB Digest TLV (%d vs %d)", sublen, SUBLEN);
return;
}
else {
proto_tree *subtree, *ti;
const guint8 vad = tvb_get_guint8(tvb, offset);
const guint8 *digest = tvb_get_ptr(tvb, offset + 1, DIGEST_LEN);
int i;
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB Digest: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_hello_clv_mt_port_cap_spb_digest);
proto_tree_add_text( subtree, tvb, offset, 1,
"V: %d, A: %d, D: %d",
(vad >> 4) & 0x1,
(vad >> 2) & 0x3,
(vad >> 0) & 0x3);
++offset;
proto_tree_add_text( subtree, tvb, offset, DIGEST_LEN, "Digest:");
for (i = 0 ; i < DIGEST_LEN ; i+= 8, offset += 8) {
proto_tree_add_text( subtree, tvb, offset, 8,
" %02x %02x %02x %02x %02x %02x %02x %02x",
digest[i+0], digest[i+1], digest[i+2], digest[i+3],
digest[i+4], digest[i+5], digest[i+6], digest[i+7]);
}
}
}
static void
dissect_hello_mt_port_cap_spb_bvid_tuples_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int subtype, int sublen)
{
proto_tree *subtree, *ti;
int subofs = offset;
ti = proto_tree_add_text( tree, tvb, offset-2, sublen+2,
"SPB Base Vlan Identifiers: Type: 0x%02x, Length: %d", subtype, sublen);
subtree = proto_item_add_subtree(ti, ett_isis_hello_clv_mt_port_cap_spb_bvid_tuples);
while (sublen > 0) {
if (sublen < 6) {
isis_dissect_unknown( tvb, subtree, offset,
"Short SPB BVID header entry (%d vs %d)", sublen, 6);
return;
}
else {
const guint8 *ect_tlv = tvb_get_ptr(tvb, subofs, 6);
guint16 word = (ect_tlv[4] << 8) | ect_tlv[5];
guint16 bvid = (word >> 4) & 0xfff;
int u_bit = (ect_tlv[5] & 8) ? 1 : 0;
int m_bit = (ect_tlv[5] & 4) ? 1 : 0;
proto_tree_add_text( subtree, tvb, subofs, 6,
"ECT: %02x-%02x-%02x-%02x, BVID: 0x%03x (%d),%s U: %d, M: %d",
ect_tlv[0], ect_tlv[1], ect_tlv[2], ect_tlv[3],
bvid, bvid,
( bvid < 10 ? " "
: bvid < 100 ? " "
: bvid < 1000 ? " "
: ""),
u_bit,
m_bit);
}
sublen -= 6;
subofs += 6;
}
}
static void
dissect_hello_mt_port_cap_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
if (length >= 2) {
guint16 mtid = tvb_get_ntohs(tvb, offset);
proto_tree_add_text( tree, tvb, offset, 2,
"MTID: 0x%03x",
(mtid & 0xfff));
length -= 2;
offset += 2;
while (length >= 2) {
guint8 subtype = tvb_get_guint8(tvb, offset);
guint8 subtlvlen = tvb_get_guint8(tvb, offset+1);
length -= 2;
offset += 2;
if (subtlvlen > length) {
isis_dissect_unknown( tvb, tree, offset,
"Short type 0x%02x TLV (%d vs %d)", subtype, subtlvlen, length);
return;
}
if (subtype == 0x04) {
dissect_hello_mt_port_cap_spb_mcid_clv(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x05) {
dissect_hello_mt_port_cap_spb_digest_clv(tvb, tree, offset, subtype, subtlvlen);
}
else if (subtype == 0x06) {
dissect_hello_mt_port_cap_spb_bvid_tuples_clv(tvb, tree, offset, subtype, subtlvlen);
}
else {
isis_dissect_unknown( tvb, tree, offset,
"Unknown SubTlv: Type: 0x%02x, Length: %d", subtype, subtlvlen);
}
length -= subtlvlen;
offset += subtlvlen;
}
}
}
static void
dissect_hello_restart_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length, int length)
{
int restart_options=0;
proto_tree *flags_tree;
proto_item *restart_flags_item;
proto_item *hold_time_item;
const char *sep;
const guint8 *neighbor_id;
if (length >= 1) {
restart_options = tvb_get_guint8(tvb, offset);
restart_flags_item = proto_tree_add_uint ( tree, hf_isis_hello_clv_restart_flags,
tvb, offset, 1, restart_options);
flags_tree = proto_item_add_subtree(restart_flags_item, ett_isis_hello_clv_restart_flags);
proto_tree_add_boolean (flags_tree, hf_isis_hello_clv_restart_flags_sa,
tvb, offset, 1, restart_options );
proto_tree_add_boolean (flags_tree, hf_isis_hello_clv_restart_flags_ra,
tvb, offset, 1, restart_options );
proto_tree_add_boolean (flags_tree, hf_isis_hello_clv_restart_flags_rr,
tvb, offset, 1, restart_options );
sep = initial_sep;
APPEND_BOOLEAN_FLAG(ISIS_MASK_RESTART_SA(restart_options), restart_flags_item, "%sSA");
APPEND_BOOLEAN_FLAG(ISIS_MASK_RESTART_RA(restart_options), restart_flags_item, "%sRA");
APPEND_BOOLEAN_FLAG(ISIS_MASK_RESTART_RR(restart_options), restart_flags_item, "%sRR");
if (sep != initial_sep)
{
proto_item_append_text (restart_flags_item, ")");
}
}
if (length >= 3 && ISIS_MASK_RESTART_RA(restart_options)) {
hold_time_item = proto_tree_add_uint ( tree, hf_isis_hello_clv_restart_remain_time,
tvb, offset+1, 2, tvb_get_ntohs(tvb, offset+1) );
proto_item_append_text( hold_time_item, "s" );
}
if (length >= 3 + id_length && ISIS_MASK_RESTART_RA(restart_options)) {
neighbor_id = tvb_get_ptr(tvb, offset+3, id_length);
proto_tree_add_bytes_format_value( tree,
hf_isis_hello_clv_restart_neighbor, tvb, offset+3,
id_length, neighbor_id, "%s",
print_system_id( neighbor_id, id_length ) );
}
}
static void
dissect_hello_nlpid_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_nlpid_clv(tvb, tree, offset, length);
}
static void
dissect_hello_mt_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_mt_clv(tvb, tree, offset, length,
hf_isis_hello_clv_mt );
}
static void
dissect_hello_ip_int_addr_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_ip_int_clv(tvb, tree, offset, length,
hf_isis_hello_clv_ipv4_int_addr );
}
static void
dissect_hello_ipv6_int_addr_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_ipv6_int_clv(tvb, tree, offset, length,
hf_isis_hello_clv_ipv6_int_addr );
}
static void
dissect_hello_authentication_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_hello_ip_authentication_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_ip_authentication_clv(tvb, tree, offset, length);
}
static void
dissect_hello_checksum_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length) {
guint16 pdu_length,checksum, cacl_checksum=0;
if (tree) {
if ( length != 2 ) {
proto_tree_add_text ( tree, tvb, offset, length,
"incorrect checksum length (%u), should be (2)", length );
return;
}
checksum = tvb_get_ntohs(tvb, offset);
pdu_length = tvb_get_ntohs(tvb, 17);
switch (check_and_get_checksum(tvb, 0, pdu_length, checksum, offset, &cacl_checksum))
{
case NO_CKSUM :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [unused]", checksum);
break;
case DATA_MISSING :
isis_dissect_unknown(tvb, tree, offset,
"[packet length %d went beyond packet]",
tvb_length(tvb));
break;
case CKSUM_NOT_OK :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
checksum,
cacl_checksum);
break;
case CKSUM_OK :
proto_tree_add_text ( tree, tvb, offset, length,
"Checksum: 0x%04x [correct]", checksum);
break;
default :
g_message("'check_and_get_checksum' returned an invalid value");
}
}
}
static void
dissect_hello_area_address_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length _U_, int length)
{
isis_dissect_area_address_clv(tvb, tree, offset, length);
}
static void
dissect_hello_ptp_adj_clv(tvbuff_t *tvb,
proto_tree *tree, int offset, int id_length, int length)
{
static const value_string adj_state_vals[] = {
{ 0, "Up" },
{ 1, "Initializing" },
{ 2, "Down" },
{ 0, NULL }
};
guint8 adj_state;
const char *adj_state_str;
adj_state = tvb_get_guint8(tvb, offset);
adj_state_str = val_to_str(adj_state, adj_state_vals, "Unknown (%u)");
switch(length) {
case 1:
proto_tree_add_text ( tree, tvb, offset, 1,
"Adjacency State: %s", adj_state_str );
break;
case 5:
proto_tree_add_text ( tree, tvb, offset, 1,
"Adjacency State: %s", adj_state_str );
proto_tree_add_text ( tree, tvb, offset+1, 4,
"Extended Local circuit ID: 0x%08x", tvb_get_ntohl(tvb, offset+1) );
break;
case 11:
proto_tree_add_text ( tree, tvb, offset, 1,
"Adjacency State: %s", adj_state_str );
proto_tree_add_text ( tree, tvb, offset+1, 4,
"Extended Local circuit ID: 0x%08x", tvb_get_ntohl(tvb, offset+1) );
proto_tree_add_text ( tree, tvb, offset+5, id_length,
"Neighbor SystemID: %s",
print_system_id( tvb_get_ptr(tvb, offset+5, id_length), id_length ) );
break;
case 15:
proto_tree_add_text ( tree, tvb, offset, 1,
"Adjacency State: %s", adj_state_str );
proto_tree_add_text ( tree, tvb, offset+1, 4,
"Extended Local circuit ID: 0x%08x", tvb_get_ntohl(tvb, offset+1) );
proto_tree_add_text ( tree, tvb, offset+5, id_length,
"Neighbor SystemID: %s",
print_system_id( tvb_get_ptr(tvb, offset+5, id_length), id_length ) );
proto_tree_add_text ( tree, tvb, offset+5+id_length, 4,
"Neighbor Extended Local circuit ID: 0x%08x",
tvb_get_ntohl(tvb, offset+5+id_length) );
break;
default:
isis_dissect_unknown(tvb, tree, offset,
"malformed TLV (%d vs 1,5,11,15)", length );
return;
}
}
static void
dissect_hello_is_neighbors_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int id_length _U_, int length)
{
while ( length > 0 ) {
if (length<6) {
isis_dissect_unknown(tvb, tree, offset,
"short is neighbor (%d vs 6)", length );
return;
}
if ( tree ) {
proto_tree_add_text ( tree, tvb, offset, 6,
"IS Neighbor: %s", get_ether_name( tvb_get_ptr(tvb, offset, 6)) );
}
offset += 6;
length -= 6;
}
}
static void
dissect_hello_padding_clv(tvbuff_t *tvb _U_, proto_tree *tree _U_, int offset _U_,
int id_length _U_, int length _U_)
{
}
void
isis_dissect_isis_hello(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset,
int hello_type, int header_length, int id_length)
{
proto_item *ti;
proto_tree *hello_tree = NULL;
int len;
guint8 octet;
const guint8 *source_id;
guint16 pdu_length;
const guint8 *lan_id;
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, -1, "ISIS HELLO");
hello_tree = proto_item_add_subtree(ti, ett_isis_hello);
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(hello_tree,
hf_isis_hello_circuit_reserved,
tvb, offset, 1, octet,
"Circuit type : %s, reserved(0x%02x == 0)",
val_to_str(octet&ISIS_HELLO_CTYPE_MASK,
isis_hello_circuit_type_vals,
"Unknown (0x%x)"),
octet&ISIS_HELLO_CT_RESERVED_MASK
);
}
offset += 1;
if (tree) {
source_id = tvb_get_ptr(tvb, offset, id_length);
proto_tree_add_bytes_format_value(hello_tree, hf_isis_hello_source_id, tvb,
offset, id_length, source_id,
"%s", print_system_id( source_id, id_length ) );
}
col_append_fstr(pinfo->cinfo, COL_INFO, ", System-ID: %s",
print_system_id( tvb_get_ptr(tvb, offset, id_length), id_length ) );
offset += id_length;
if (tree) {
proto_tree_add_item(hello_tree, hf_isis_hello_holding_timer, tvb,
offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
pdu_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(hello_tree, hf_isis_hello_pdu_length, tvb,
offset, 2, pdu_length);
}
offset += 2;
if (hello_type == ISIS_TYPE_PTP_HELLO) {
if (tree) {
proto_tree_add_item(hello_tree, hf_isis_hello_local_circuit_id, tvb,
offset, 1, ENC_BIG_ENDIAN );
}
offset += 1;
} else {
if (tree) {
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format(hello_tree, hf_isis_hello_priority_reserved, tvb,
offset, 1, octet,
"Priority : %d, reserved(0x%02x == 0)",
octet&ISIS_HELLO_PRIORITY_MASK,
octet&ISIS_HELLO_P_RESERVED_MASK );
}
offset += 1;
if (tree) {
lan_id = tvb_get_ptr(tvb, offset, id_length+1);
proto_tree_add_bytes_format_value(hello_tree, hf_isis_hello_lan_id, tvb,
offset, id_length + 1, lan_id,
"%s", print_system_id( lan_id, id_length + 1 ) );
}
offset += id_length + 1;
}
len = pdu_length;
len -= header_length;
if (len < 0) {
isis_dissect_unknown(tvb, tree, offset,
"Packet header length %d went beyond packet",
header_length );
return;
}
if (hello_type == ISIS_TYPE_L1_HELLO){
isis_dissect_clvs(tvb, hello_tree, offset,
clv_l1_hello_opts, len, id_length,
ett_isis_hello_clv_unknown);
} else if (hello_type == ISIS_TYPE_L2_HELLO) {
isis_dissect_clvs(tvb, hello_tree, offset,
clv_l2_hello_opts, len, id_length,
ett_isis_hello_clv_unknown);
} else {
isis_dissect_clvs(tvb, hello_tree, offset,
clv_ptp_hello_opts, len, id_length,
ett_isis_hello_clv_unknown);
}
}
void
isis_register_hello(int proto_isis) {
static hf_register_info hf[] = {
{ &hf_isis_hello_circuit_reserved,
{ "Circuit type", "isis.hello.circuit_type",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_source_id,
{ "SystemID {Sender of PDU}", "isis.hello.source_id",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_holding_timer,
{ "Holding timer", "isis.hello.holding_timer",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_pdu_length,
{ "PDU length", "isis.hello.pdu_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_priority_reserved,
{ "Priority", "isis.hello.priority",
FT_UINT8, BASE_DEC, NULL, ISIS_HELLO_P_RESERVED_MASK, NULL, HFILL }},
{ &hf_isis_hello_lan_id,
{ "SystemID {Designated IS}", "isis.hello.lan_id",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_local_circuit_id,
{ "Local circuit ID", "isis.hello.local_circuit_id",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_clv_ipv4_int_addr,
{ "IPv4 interface address", "isis.hello.clv_ipv4_int_addr",
FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_clv_ipv6_int_addr,
{ "IPv6 interface address", "isis.hello.clv_ipv6_int_addr",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#if 0
{ &hf_isis_hello_clv_ptp_adj,
{ "Point-to-point Adjacency", "isis.hello.clv_ptp_adj",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_isis_hello_clv_mt,
{ "MT-ID", "isis.hello.clv_mt",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_clv_restart_flags,
{ "Restart Signaling Flags", "isis.hello.clv_restart_flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isis_hello_clv_restart_flags_rr,
{ "Restart Request", "isis.hello.clv_restart_flags.rr",
FT_BOOLEAN, 8, TFS(&tfs_true_false), ISIS_RESTART_RR,
"When set, the router is beginning a graceful restart", HFILL }},
{ &hf_isis_hello_clv_restart_flags_ra,
{ "Restart Acknowledgment", "isis.hello.clv_restart_flags.ra",
FT_BOOLEAN, 8, TFS(&tfs_true_false), ISIS_RESTART_RA,
"When set, the router is willing to enter helper mode", HFILL }},
{ &hf_isis_hello_clv_restart_flags_sa,
{ "Suppress Adjacency", "isis.hello.clv_restart_flags.sa",
FT_BOOLEAN, 8, TFS(&tfs_true_false), ISIS_RESTART_SA,
"When set, the router is starting as opposed to restarting", HFILL }},
{ &hf_isis_hello_clv_restart_remain_time,
{ "Remaining holding time", "isis.hello.clv_restart.remain_time",
FT_UINT16, BASE_DEC, NULL, 0x0,
"How long the helper router will maintain the existing adjacency", HFILL }},
{ &hf_isis_hello_clv_restart_neighbor,
{ "Restarting Neighbor ID", "isis.hello.clv_restart.neighbor",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The System ID of the restarting neighbor", HFILL }}
};
static gint *ett[] = {
&ett_isis_hello,
&ett_isis_hello_clv_area_addr,
&ett_isis_hello_clv_is_neighbors,
&ett_isis_hello_clv_padding,
&ett_isis_hello_clv_unknown,
&ett_isis_hello_clv_nlpid,
&ett_isis_hello_clv_authentication,
&ett_isis_hello_clv_ip_authentication,
&ett_isis_hello_clv_ipv4_int_addr,
&ett_isis_hello_clv_ipv6_int_addr,
&ett_isis_hello_clv_ptp_adj,
&ett_isis_hello_clv_mt,
&ett_isis_hello_clv_restart,
&ett_isis_hello_clv_restart_flags,
&ett_isis_hello_clv_mt_port_cap,
&ett_isis_hello_clv_mt_port_cap_spb_mcid,
&ett_isis_hello_clv_mt_port_cap_spb_aux_mcid,
&ett_isis_hello_clv_mt_port_cap_spb_digest,
&ett_isis_hello_clv_mt_port_cap_spb_bvid_tuples,
&ett_isis_hello_clv_checksum
};
proto_register_field_array(proto_isis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
