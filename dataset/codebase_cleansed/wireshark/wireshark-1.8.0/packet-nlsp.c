static void
nlsp_dissect_unknown(tvbuff_t *tvb, proto_tree *tree, int offset,
const char *fmat, ...)
{
va_list ap;
va_start(ap, fmat);
proto_tree_add_text_valist(tree, tvb, offset, -1, fmat, ap);
va_end(ap);
}
static void
nlsp_dissect_clvs(tvbuff_t *tvb, proto_tree *tree, int offset,
const nlsp_clv_handle_t *opts, int len, int unknown_tree_id _U_)
{
guint8 code;
guint8 length;
int q;
proto_item *ti;
proto_tree *clv_tree;
int adj;
while ( len > 0 ) {
code = tvb_get_guint8(tvb, offset);
offset += 1;
length = tvb_get_guint8(tvb, offset);
offset += 1;
adj = (sizeof(code) + sizeof(length) + length);
len -= adj;
if ( len < 0 ) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short CLV header (%d vs %d)",
adj, len + adj );
return;
}
q = 0;
while ((opts[q].dissect != NULL )&&( opts[q].optcode != code )){
q++;
}
if ( opts[q].dissect ) {
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "%s (%u)",
opts[q].tree_text, length );
clv_tree = proto_item_add_subtree(ti,
*opts[q].tree_id );
} else {
clv_tree = NULL;
}
opts[q].dissect(tvb, clv_tree, offset,
length);
} else {
if (tree) {
#if 0
ti = proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "Unknown code %u (%u)",
code, length);
clv_tree = proto_item_add_subtree(ti,
unknown_tree_id );
} else {
clv_tree = NULL;
#else
proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "Unknown code %u (%u)",
code, length);
#endif
}
}
offset += length;
}
}
static void
dissect_area_address_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short area address entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Area address network number: 0x%08x",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short area address entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Area address mask: 0x%08x",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
}
}
static void
dissect_neighbor_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 6) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short neighbor entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Neighbor: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
length -= 6;
}
}
static void
dissect_hello_local_mtu_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"MTU Size: %u",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
}
static void
nlsp_dissect_nlsp_hello(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int hello_type, int header_length)
{
guint16 packet_length;
int len;
guint16 holding_timer;
if (tree) {
if (hello_type == NLSP_TYPE_WAN_HELLO) {
proto_tree_add_item(tree, hf_nlsp_hello_state, tvb,
offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_nlsp_hello_multicast, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree, hf_nlsp_hello_circuit_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Sending Router System ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", System ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
holding_timer = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint_format(tree, hf_nlsp_hello_holding_timer,
tvb, offset, 2, holding_timer,
"Holding Timer: %us", holding_timer);
}
offset += 2;
packet_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
}
offset += 2;
if (tree) {
proto_tree_add_item(tree, hf_nlsp_hello_priority, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
if (hello_type == NLSP_TYPE_WAN_HELLO) {
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Local WAN Circuit ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
} else {
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Designated Router System ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_text(tree, tvb, offset+6, 1,
"Designated Router Pseudonode ID: %u",
tvb_get_guint8(tvb, offset+6));
}
offset += 7;
}
len = packet_length - header_length;
if (len < 0) {
nlsp_dissect_unknown(tvb, tree, offset,
"packet header length %d went beyond packet",
header_length);
return;
}
nlsp_dissect_clvs(tvb, tree, offset,
clv_hello_opts, len, ett_nlsp_hello_clv_unknown);
}
static void
dissect_lsp_mgt_info_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
guint8 name_length;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short management info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Network number: 0x%08x",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 6) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short management info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Node number: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
length -= 6;
if (length < 1) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short management info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"IPX version number: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
length -= 1;
if (length < 1) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short management info entry");
return;
}
name_length = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Name length: %u", name_length);
}
offset += 1;
length -= 1;
if (name_length != 0) {
if (length < name_length) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short management info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, name_length,
"Name: %s",
tvb_format_text(tvb, offset, name_length));
}
offset += name_length;
length -= name_length;
}
}
static void
dissect_lsp_link_info_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
guint8 flags_cost;
if (length < 1) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
flags_cost = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(flags_cost, 0x80, 1*8,
"Cost not present", "Cost present"));
if (!(flags_cost & 0x80)) {
proto_tree_add_text(tree, tvb, offset, 1, "%s",
decode_boolean_bitfield(flags_cost, 0x40, 1*8,
"Cost is internal metric",
"Cost is external metric"));
proto_tree_add_text(tree, tvb, offset, 1, "%s",
decode_numeric_bitfield(flags_cost, 0x3F, 1*8,
"Cost = %u"));
}
}
offset += 1;
length -= 1;
if (length < 3) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
offset += 3;
length -= 3;
if (length < 7) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Router System ID: %s",
tvb_ether_to_str(tvb, offset));
proto_tree_add_text(tree, tvb, offset+6, 1,
"Router Pseudonode ID: %u",
tvb_get_guint8(tvb, offset+6));
}
offset += 7;
length -= 7;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"MTU Size: %u",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Delay: %uus",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Throughput: %u bits/s",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 2) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short link info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2,
"Media type: %s",
val_to_str(tvb_get_ntohs(tvb, offset), media_type_vals,
"Unknown (0x%04x)"));
}
offset += 2;
length -= 2;
}
static void
dissect_lsp_svcs_info_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
if (length < 1) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short services info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Hops to reach the service: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
length -= 1;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short services info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Network number: 0x%08x",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 6) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short services info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Node number: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
length -= 6;
if (length < 2) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short services info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2,
"Socket: %s",
val_to_str_ext(tvb_get_ntohs(tvb, offset), &ipx_socket_vals_ext,
"Unknown (0x%04x)"));
}
offset += 2;
length -= 2;
if (length < 2) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short services info entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2,
"Type: %s",
val_to_str_ext(tvb_get_ntohs(tvb, offset), &novell_server_vals_ext,
"Unknown (0x%04x)"));
}
offset += 2;
length -= 2;
if (length > 0) {
if (tree) {
proto_tree_add_text(tree, tvb, offset, length,
"Service Name: %s",
tvb_format_text(tvb, offset, length));
}
}
}
static void
dissect_lsp_ext_routes_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
while (length > 0) {
if (length < 1) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short external routes entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Hops: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
length -= 1;
if (length < 4) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short external routes entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 4,
"Network number: 0x%08x",
tvb_get_ntohl(tvb, offset));
}
offset += 4;
length -= 4;
if (length < 2) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short external routes entry");
return;
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2,
"RIP delay: %u ticks",
tvb_get_ntohs(tvb, offset));
}
offset += 2;
length -= 2;
}
}
static void
nlsp_dissect_nlsp_lsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
guint16 remaining_lifetime;
guint32 sequence_number;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
}
offset += 2;
remaining_lifetime = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_text(tree, tvb, offset, 2,
"Remaining Lifetime: %us",
remaining_lifetime);
}
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", LSP ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"LSP ID system ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"LSP ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"LSP ID LSP number: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
sequence_number = tvb_get_ntohl(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO,
", Sequence: 0x%08x, Lifetime: %us",
sequence_number, remaining_lifetime);
}
if (tree) {
proto_tree_add_uint(tree, hf_nlsp_lsp_sequence_number, tvb,
offset, 4, sequence_number);
}
offset += 4;
if (tree) {
proto_tree_add_item(tree, hf_nlsp_lsp_checksum, tvb,
offset, 2, ENC_BIG_ENDIAN );
}
offset += 2;
if (tree) {
proto_tree_add_item(tree, hf_nlsp_lsp_p, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_attached_flag, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_lspdbol, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_nlsp_lsp_router_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len = packet_length - header_length;
if (len < 0) {
nlsp_dissect_unknown(tvb, tree, offset,
"packet header length %d went beyond packet",
header_length);
return;
}
nlsp_dissect_clvs(tvb, tree, offset,
clv_l1_lsp_opts, len, ett_nlsp_lsp_clv_unknown);
}
static void
dissect_csnp_lsp_entries(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
proto_tree *subtree,*ti;
while (length > 0) {
if (length < 16) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short CSNP header entry");
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 16,
"LSP-ID: %s, Sequence: 0x%08x, Lifetime: %5us, Checksum: 0x%04x",
tvb_ether_to_str(tvb, offset+2),
tvb_get_ntohl(tvb, offset+10),
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, offset+14));
subtree = proto_item_add_subtree(ti, ett_nlsp_csnp_lsp_entry);
proto_tree_add_text(subtree, tvb, offset+2, 6,
"LSP ID source ID: %s",
tvb_ether_to_str(tvb, offset+2));
proto_tree_add_text(subtree, tvb, offset+8, 1,
"LSP ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset+8));
proto_tree_add_text(subtree, tvb, offset+9, 1,
"LSP ID LSP number: %u",
tvb_get_guint8(tvb, offset+9));
proto_tree_add_text(subtree, tvb, offset+10, 4,
"LSP Sequence Number: 0x%08x",
tvb_get_ntohl(tvb, offset+10));
proto_tree_add_text(subtree, tvb, offset, 2,
"Remaining Lifetime: %us",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(subtree, tvb, offset+14, 2,
"LSP checksum: 0x%04x",
tvb_get_ntohs(tvb, offset+14));
length -= 16;
offset += 16;
}
}
static void
dissect_psnp_lsp_entries(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
proto_tree *subtree,*ti;
while (length > 0) {
if (length < 16) {
nlsp_dissect_unknown(tvb, tree, offset,
"Short PSNP header entry");
return;
}
ti = proto_tree_add_text(tree, tvb, offset, 16,
"LSP-ID: %s, Sequence: 0x%08x, Lifetime: %5us, Checksum: 0x%04x",
tvb_ether_to_str(tvb, offset+2),
tvb_get_ntohl(tvb, offset+10),
tvb_get_ntohs(tvb, offset),
tvb_get_ntohs(tvb, offset+14));
subtree = proto_item_add_subtree(ti, ett_nlsp_psnp_lsp_entry);
proto_tree_add_text(subtree, tvb, offset+2, 6,
"LSP ID source ID: %s",
tvb_ether_to_str(tvb, offset+2));
proto_tree_add_text(subtree, tvb, offset+8, 1,
"LSP ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset+8));
proto_tree_add_text(subtree, tvb, offset+9, 1,
"LSP ID LSP number: %u",
tvb_get_guint8(tvb, offset+9));
proto_tree_add_text(subtree, tvb, offset+10, 4,
"LSP Sequence Number: 0x%08x",
tvb_get_ntohl(tvb, offset+10));
proto_tree_add_text(subtree, tvb, offset, 2,
"Remaining Lifetime: %us",
tvb_get_ntohs(tvb, offset));
proto_tree_add_text(subtree, tvb, offset+14, 2,
"LSP checksum: 0x%04x",
tvb_get_ntohs(tvb, offset+14));
length -= 16;
offset += 16;
}
}
static void
nlsp_dissect_nlsp_csnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
}
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Source ID system ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Source ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Start LSP ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Start LSP ID source ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Start LSP ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Start LSP ID LSP number: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", End LSP ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"End LSP ID source ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"End LSP ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"End LSP ID LSP number: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
len = packet_length - header_length;
if (len < 0) {
return;
}
nlsp_dissect_clvs(tvb, tree, offset,
clv_l1_csnp_opts, len, ett_nlsp_csnp_clv_unknown);
}
static void
nlsp_dissect_nlsp_psnp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, int header_length)
{
guint16 packet_length;
int len;
packet_length = tvb_get_ntohs(tvb, offset);
if (tree) {
proto_tree_add_uint(tree, hf_nlsp_packet_length, tvb,
offset, 2, packet_length);
}
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", Source ID: %s",
tvb_ether_to_str(tvb, offset));
}
if (tree) {
proto_tree_add_text(tree, tvb, offset, 6,
"Source ID system ID: %s",
tvb_ether_to_str(tvb, offset));
}
offset += 6;
if (tree) {
proto_tree_add_text(tree, tvb, offset, 1,
"Source ID pseudonode ID: %u",
tvb_get_guint8(tvb, offset));
}
offset += 1;
len = packet_length - header_length;
if (len < 0) {
return;
}
nlsp_dissect_clvs(tvb, tree, offset,
clv_l1_psnp_opts, len, ett_nlsp_psnp_clv_unknown);
}
static void
dissect_nlsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *nlsp_tree = NULL;
int offset = 0;
guint8 nlsp_major_version;
guint8 nlsp_header_length;
guint8 packet_type_flags;
guint8 packet_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NLSP");
col_clear(pinfo->cinfo, COL_INFO);
nlsp_major_version = tvb_get_guint8(tvb, 5);
if (nlsp_major_version != 1){
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Unknown NLSP version (%u vs 1)",
nlsp_major_version);
}
nlsp_dissect_unknown(tvb, tree, 0,
"Unknown NLSP version (%d vs 1)",
nlsp_major_version, 1);
return;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_nlsp, tvb, 0, -1, ENC_NA);
nlsp_tree = proto_item_add_subtree(ti, ett_nlsp);
}
if (tree) {
proto_tree_add_item(nlsp_tree, hf_nlsp_irpd, tvb, offset, 1,
ENC_BIG_ENDIAN );
}
offset += 1;
nlsp_header_length = tvb_get_guint8(tvb, 1);
if (tree) {
proto_tree_add_uint(nlsp_tree, hf_nlsp_header_length, tvb,
offset, 1, nlsp_header_length );
}
offset += 1;
if (tree) {
proto_tree_add_item(nlsp_tree, hf_nlsp_minor_version, tvb,
offset, 1, ENC_BIG_ENDIAN );
}
offset += 1;
offset += 1;
packet_type_flags = tvb_get_guint8(tvb, offset);
packet_type = packet_type_flags & PACKET_TYPE_MASK;
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(packet_type, nlsp_packet_type_vals, "Unknown (%u)"));
}
if (tree) {
if (packet_type == NLSP_TYPE_L1_LSP) {
proto_tree_add_boolean(nlsp_tree, hf_nlsp_nr, tvb, offset, 1,
packet_type_flags );
}
proto_tree_add_uint(nlsp_tree, hf_nlsp_type, tvb, offset, 1,
packet_type_flags );
}
offset += 1;
if (tree) {
proto_tree_add_item(nlsp_tree, hf_nlsp_major_version, tvb,
offset, 1, ENC_BIG_ENDIAN );
}
offset += 1;
offset += 2;
switch (packet_type) {
case NLSP_TYPE_L1_HELLO:
case NLSP_TYPE_WAN_HELLO:
nlsp_dissect_nlsp_hello(tvb, pinfo, nlsp_tree, offset,
packet_type, nlsp_header_length);
break;
case NLSP_TYPE_L1_LSP:
nlsp_dissect_nlsp_lsp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
case NLSP_TYPE_L1_CSNP:
nlsp_dissect_nlsp_csnp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
case NLSP_TYPE_L1_PSNP:
nlsp_dissect_nlsp_psnp(tvb, pinfo, nlsp_tree, offset,
nlsp_header_length);
break;
default:
nlsp_dissect_unknown(tvb, tree, offset,
"Unknown NLSP packet type");
}
}
void
proto_register_nlsp(void)
{
static hf_register_info hf[] = {
{ &hf_nlsp_irpd,
{ "NetWare Link Services Protocol Discriminator", "nlsp.irpd",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_header_length,
{ "PDU Header Length", "nlsp.header_length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_minor_version,
{ "Minor Version", "nlsp.minor_version", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_nr,
{ "Multi-homed Non-routing Server", "nlsp.nr", FT_BOOLEAN, 8,
NULL, 0x80, NULL, HFILL }},
{ &hf_nlsp_type,
{ "Packet Type", "nlsp.type", FT_UINT8, BASE_DEC,
VALS(nlsp_packet_type_vals), PACKET_TYPE_MASK, NULL, HFILL }},
{ &hf_nlsp_major_version,
{ "Major Version", "nlsp.major_version", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_packet_length,
{ "Packet Length", "nlsp.packet_length",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_hello_state,
{ "State", "nlsp.hello.state", FT_UINT8, BASE_DEC,
VALS(nlsp_hello_state_vals), NLSP_HELLO_STATE_MASK,
NULL, HFILL }},
{ &hf_nlsp_hello_multicast,
{ "Multicast Routing", "nlsp.hello.multicast", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), NLSP_HELLO_MULTICAST_MASK,
"If set, this router supports multicast routing", HFILL }},
{ &hf_nlsp_hello_circuit_type,
{ "Circuit Type", "nlsp.hello.circuit_type", FT_UINT8, BASE_DEC,
VALS(nlsp_hello_circuit_type_vals), NLSP_HELLO_CTYPE_MASK,
NULL, HFILL }},
{ &hf_nlsp_hello_holding_timer,
{ "Holding Timer", "nlsp.hello.holding_timer", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_hello_priority,
{ "Priority", "nlsp.hello.priority", FT_UINT8, BASE_DEC,
NULL, NLSP_HELLO_PRIORITY_MASK,
NULL, HFILL }},
{ &hf_nlsp_lsp_sequence_number,
{ "Sequence Number", "nlsp.sequence_number",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_lsp_checksum,
{ "Checksum", "nlsp.lsp.checksum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nlsp_lsp_p,
{ "Partition Repair", "nlsp.lsp.partition_repair", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), NLSP_LSP_PARTITION_MASK,
"If set, this router supports the optional Partition Repair function", HFILL }},
{ &hf_nlsp_lsp_attached_flag,
{ "Attached Flag", "nlsp.lsp.attached_flag", FT_UINT8, BASE_DEC,
VALS(nlsp_attached_flag_vals), NLSP_LSP_ATT_MASK, NULL, HFILL }},
{ &hf_nlsp_lsp_lspdbol,
{ "LSP Database Overloaded", "nlsp.lsp.lspdbol", FT_BOOLEAN, 8,
NULL, NLSP_LSP_OVERFLOW_MASK, NULL, HFILL }},
{ &hf_nlsp_lsp_router_type,
{ "Router Type", "nlsp.lsp.router_type", FT_UINT8, BASE_DEC,
VALS(nlsp_router_type_vals), NLSP_LSP_ROUTER_TYPE_MASK,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_nlsp,
&ett_nlsp_hello_clv_area_addr,
&ett_nlsp_hello_clv_neighbors,
&ett_nlsp_hello_local_mtu,
&ett_nlsp_hello_clv_unknown,
&ett_nlsp_lsp_info,
&ett_nlsp_lsp_clv_area_addr,
&ett_nlsp_lsp_clv_mgt_info,
&ett_nlsp_lsp_clv_link_info,
&ett_nlsp_lsp_clv_svcs_info,
&ett_nlsp_lsp_clv_ext_routes,
&ett_nlsp_lsp_clv_unknown,
&ett_nlsp_csnp_lsp_entries,
&ett_nlsp_csnp_lsp_entry,
&ett_nlsp_csnp_clv_unknown,
&ett_nlsp_psnp_lsp_entries,
&ett_nlsp_psnp_lsp_entry,
&ett_nlsp_psnp_clv_unknown,
};
proto_nlsp = proto_register_protocol("NetWare Link Services Protocol",
"NLSP", "nlsp");
proto_register_field_array(proto_nlsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nlsp(void)
{
dissector_handle_t nlsp_handle;
nlsp_handle = create_dissector_handle(dissect_nlsp, proto_nlsp);
dissector_add_uint("ipx.socket", IPX_SOCKET_NLSP, nlsp_handle);
}
