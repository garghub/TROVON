static inline gint
is_edge_chosen(guint8 e)
{
return e & XIA_CHOSEN_EDGE;
}
static inline gint
is_any_edge_chosen(const struct xia_row *row)
{
return row->s_edge.i & XIA_CHOSEN_EDGES;
}
static inline gint
is_empty_edge(guint8 e)
{
return (e & XIA_EMPTY_EDGE) == XIA_EMPTY_EDGE;
}
static inline gint
xia_is_nat(xid_type_t ty)
{
return ty == XIDTYPE_NAT;
}
static gint
xia_are_edges_valid(const struct xia_row *row,
guint8 node, guint8 num_node, guint32 *pvisited)
{
const guint8 *edge;
guint32 all_edges, bits;
gint i;
if (is_any_edge_chosen(row)) {
return -XIAEADDR_CHOSEN_EDGE;
}
edge = row->s_edge.a;
all_edges = g_ntohl(row->s_edge.i);
bits = 0xffffffff;
for (i = 0; i < XIA_OUTDEGREE_MAX; i++, edge++) {
guint8 e;
e = *edge;
if (e == XIA_EMPTY_EDGE) {
if ((all_edges & bits) !=
(XIA_EMPTY_EDGES & bits))
return -XIAEADDR_EE_MISPLACED;
else
break;
} else if (e >= num_node) {
return -XIAEADDR_EDGE_OUT_RANGE;
} else if (node < (num_node - 1) && e <= node) {
return -XIAEADDR_NOT_TOPOLOGICAL;
}
bits >>= 8;
*pvisited |= 1 << e;
}
return 0;
}
static gint
xia_test_addr(const struct xia_addr *addr)
{
gint i, n;
gint saw_nat = 0;
guint32 visited = 0;
n = XIA_NODES_MAX;
for (i = 0; i < XIA_NODES_MAX; i++) {
xid_type_t ty;
ty = addr->s_row[i].s_xid.xid_type;
if (saw_nat) {
if (!xia_is_nat(ty))
return -XIAEADDR_NAT_MISPLACED;
} else if (xia_is_nat(ty)) {
n = i;
saw_nat = 1;
}
}
for (i = 0; i < n; i++) {
gint rc;
rc = xia_are_edges_valid(&addr->s_row[i], i, n, &visited);
if (rc)
return rc;
}
if (n >= 1) {
guint32 all_edges;
all_edges = addr->s_row[n - 1].s_edge.i;
if (all_edges == XIA_EMPTY_EDGES)
return -XIAEADDR_NO_ENTRY;
if (visited != ((1U << n) - 1))
return -XIAEADDR_MULTI_COMPONENTS;
}
return n;
}
static inline gchar
edge_to_char(guint8 e)
{
const gchar *ch_edge = "0123456789abcdefghijklmnopqrstuvwxyz";
e &= ~XIA_CHOSEN_EDGE;
if (e < INDEX_BASE)
return ch_edge[e];
else if (is_empty_edge(e))
return '*';
else
return '+';
}
static void
add_edges_to_buf(gint valid, wmem_strbuf_t *buf, const guint8 *edges)
{
gint i;
wmem_strbuf_append_c(buf, '-');
for (i = 0; i < XIA_OUTDEGREE_MAX; i++) {
if (valid && edges[i] == XIA_EMPTY_EDGE)
return;
if (is_edge_chosen(edges[i]))
wmem_strbuf_append_c(buf, '>');
wmem_strbuf_append_c(buf, edge_to_char(edges[i]));
}
}
static void
add_type_to_buf(xid_type_t ty, wmem_strbuf_t *buf)
{
const gchar *xid_name;
gsize buflen = wmem_strbuf_get_len(buf);
if (XIA_MAX_STRADDR_SIZE - buflen - 1 < MAX_PPAL_NAME_SIZE)
return;
xid_name = try_val_to_str(ty, xidtype_vals);
if (xid_name)
wmem_strbuf_append_printf(buf, "%s-", xid_name);
else
wmem_strbuf_append_printf(buf, "0x%x-", ty);
}
static inline void
add_id_to_buf(const struct xia_xid *src, wmem_strbuf_t *buf)
{
wmem_strbuf_append_printf(buf, "%08x%08x%08x%08x%08x",
src->xid_id[0],
src->xid_id[1],
src->xid_id[2],
src->xid_id[3],
src->xid_id[4]);
}
static int
xia_ntop(const struct xia_addr *src, wmem_strbuf_t *buf)
{
gint valid, i;
valid = xia_test_addr(src) >= 1;
if (!valid)
wmem_strbuf_append_c(buf, '!');
for (i = 0; i < XIA_NODES_MAX; i++) {
const struct xia_row *row = &src->s_row[i];
if (xia_is_nat(row->s_xid.xid_type))
break;
if (i > 0)
wmem_strbuf_append(buf, ":\n");
add_type_to_buf(row->s_xid.xid_type, buf);
add_id_to_buf(&row->s_xid, buf);
add_edges_to_buf(valid, buf, row->s_edge.a);
}
return 0;
}
static void
construct_dag(tvbuff_t *tvb, proto_tree *xip_tree,
const gint ett, const gint hf, const gint hf_entry,
const guint8 num_nodes, guint8 offset)
{
proto_tree *dag_tree;
proto_item *ti;
struct xia_addr dag;
wmem_strbuf_t *buf;
const gchar *dag_str;
guint i, j;
guint8 dag_offset = offset;
ti = proto_tree_add_item(xip_tree, hf, tvb, offset,
num_nodes * XIA_NODE_SIZE, ENC_BIG_ENDIAN);
buf = wmem_strbuf_sized_new(wmem_packet_scope(),
XIA_MAX_STRADDR_SIZE, XIA_MAX_STRADDR_SIZE);
dag_tree = proto_item_add_subtree(ti, ett);
memset(&dag, 0, sizeof(dag));
for (i = 0; i < num_nodes; i++) {
struct xia_row *row = &dag.s_row[i];
row->s_xid.xid_type = tvb_get_ntohl(tvb, offset);
offset += XIA_TYPE_SIZE;
for (j = 0; j < XIA_XID_SIZE / XIA_XID_CHUNK_SIZE; j++) {
row->s_xid.xid_id[j] = tvb_get_ntohl(tvb, offset);
offset += XIA_XID_CHUNK_SIZE;
}
tvb_memcpy(tvb, row->s_edge.a, offset, XIA_EDGES_SIZE);
offset += XIA_EDGES_SIZE;
}
xia_ntop(&dag, buf);
dag_str = wmem_strbuf_get_str(buf);
proto_tree_add_string_format(dag_tree, hf_entry, tvb, dag_offset,
XIA_NODE_SIZE * num_nodes, dag_str, "%s", dag_str);
}
static gint
dissect_xip_sink_node(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint8 sink_node)
{
tvbuff_t *next_tvb;
switch (sink_node) {
case XIDTYPE_FLOWID:
case XIDTYPE_SRVCID:
next_tvb = tvb_new_subset_remaining(tvb, offset);
return call_dissector(xip_serval_handle, next_tvb, pinfo, tree);
default:
return 0;
}
}
static gint
dissect_xip_next_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_item *next_ti, gint offset)
{
tvbuff_t *next_tvb;
guint8 next_header = tvb_get_guint8(tvb, XIPH_NXTH);
switch (next_header) {
case XIA_NEXT_HEADER_DATA:
next_tvb = tvb_new_subset_remaining(tvb, offset);
return call_data_dissector(next_tvb, pinfo, tree);
default:
expert_add_info_format(pinfo, next_ti, &ei_xip_next_header,
"Unrecognized next header type: 0x%02x", next_header);
return 0;
}
}
static void
display_xip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *xip_tree = NULL;
proto_item *ti = NULL;
proto_item *payload_ti = NULL;
proto_item *next_ti = NULL;
proto_item *num_ti = NULL;
gint offset;
guint16 xiph_len, payload_len;
guint8 num_dst_nodes, num_src_nodes, last_node;
num_dst_nodes = tvb_get_guint8(tvb, XIPH_NDST);
num_src_nodes = tvb_get_guint8(tvb, XIPH_NSRC);
xiph_len = 8 + (XIA_NODE_SIZE * num_dst_nodes) +
(XIA_NODE_SIZE * num_src_nodes);
ti = proto_tree_add_item(tree, proto_xip, tvb, 0, xiph_len, ENC_NA);
xip_tree = proto_item_add_subtree(ti, ett_xip_tree);
proto_tree_add_item(xip_tree, hf_xip_version, tvb,
XIPH_VERS, 1, ENC_BIG_ENDIAN);
next_ti = proto_tree_add_item(xip_tree, hf_xip_next_hdr, tvb,
XIPH_NXTH, 1, ENC_BIG_ENDIAN);
payload_len = tvb_get_ntohs(tvb, XIPH_PLEN);
payload_ti = proto_tree_add_uint_format(xip_tree, hf_xip_payload_len,
tvb, XIPH_PLEN, 2, payload_len, "Payload Length: %u bytes",
payload_len);
if (tvb_captured_length_remaining(tvb, xiph_len) != payload_len)
expert_add_info_format(pinfo, payload_ti, &ei_xip_invalid_len,
"Payload length field (%d bytes) does not match actual payload length (%d bytes)",
payload_len, tvb_captured_length_remaining(tvb, xiph_len));
proto_tree_add_item(xip_tree, hf_xip_hop_limit, tvb,
XIPH_HOPL, 1, ENC_BIG_ENDIAN);
num_ti = proto_tree_add_item(xip_tree, hf_xip_num_dst, tvb,
XIPH_NDST, 1, ENC_BIG_ENDIAN);
if (num_dst_nodes > XIA_NODES_MAX) {
expert_add_info_format(pinfo, num_ti, &ei_xip_bad_num_dst,
"The number of destination DAG nodes (%d) must be less than XIA_NODES_MAX (%d)",
num_dst_nodes, XIA_NODES_MAX);
num_dst_nodes = XIA_NODES_MAX;
}
num_ti = proto_tree_add_item(xip_tree, hf_xip_num_src, tvb,
XIPH_NSRC, 1, ENC_BIG_ENDIAN);
if (num_src_nodes > XIA_NODES_MAX) {
expert_add_info_format(pinfo, num_ti, &ei_xip_bad_num_src,
"The number of source DAG nodes (%d) must be less than XIA_NODES_MAX (%d)",
num_src_nodes, XIA_NODES_MAX);
num_src_nodes = XIA_NODES_MAX;
}
last_node = tvb_get_guint8(tvb, XIPH_LSTN);
proto_tree_add_uint_format_value(xip_tree, hf_xip_last_node, tvb,
XIPH_LSTN, 1, last_node, "%d%s", last_node,
last_node == XIA_ENTRY_NODE_INDEX ? " (entry node)" : "");
if (num_dst_nodes > 0)
construct_dag(tvb, xip_tree, ett_xip_ddag,
hf_xip_dst_dag, hf_xip_dst_dag_entry,
num_dst_nodes, XIPH_DSTD);
if (num_src_nodes > 0)
construct_dag(tvb, xip_tree, ett_xip_sdag,
hf_xip_src_dag, hf_xip_src_dag_entry,
num_src_nodes,
XIPH_DSTD + num_dst_nodes * XIA_NODE_SIZE);
offset = XIPH_DSTD + XIA_NODE_SIZE * (num_dst_nodes + num_src_nodes);
offset += dissect_xip_sink_node(tvb, pinfo, tree, offset,
tvb_get_ntohl(tvb, XIPH_DSTD +
(num_dst_nodes - 1) * XIA_NODE_SIZE));
dissect_xip_next_header(tvb, pinfo, tree, next_ti, offset);
}
static gint
dissect_xip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
if (tvb_reported_length(tvb) < XIPH_MIN_LEN)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "XIP");
col_set_str(pinfo->cinfo, COL_INFO, "XIP Packet");
display_xip(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_xip(void)
{
static hf_register_info hf[] = {
{ &hf_xip_version,
{ "Version", "xip.version", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_next_hdr,
{ "Next Header", "xip.next_hdr", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_payload_len,
{ "Payload Length", "xip.payload_len", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_hop_limit,
{ "Hop Limit", "xip.hop_limit", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_num_dst,
{ "Number of Destination Nodes", "xip.num_dst", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_num_src,
{ "Number of Source Nodes", "xip.num_src", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_last_node,
{ "Last Node", "xip.last_node", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_dst_dag,
{ "Destination DAG", "xip.dst_dag", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_dst_dag_entry,
{ "Destination DAG Entry", "xip.dst_dag_entry", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_src_dag,
{ "Source DAG", "xip.src_dag", FT_NONE,
BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_xip_src_dag_entry,
{ "Source DAG Entry", "xip.src_dag_entry", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_xip_tree,
&ett_xip_ddag,
&ett_xip_sdag
};
static ei_register_info ei[] = {
{ &ei_xip_invalid_len,
{ "xip.invalid.len", PI_MALFORMED, PI_ERROR,
"Invalid length", EXPFILL }},
{ &ei_xip_next_header,
{ "xip.next.header", PI_MALFORMED, PI_ERROR,
"Invalid next header", EXPFILL }},
{ &ei_xip_bad_num_dst,
{ "xip.bad_num_dst", PI_MALFORMED, PI_ERROR,
"Invalid number of destination DAG nodes", EXPFILL }},
{ &ei_xip_bad_num_src,
{ "xip.bad_num_src", PI_MALFORMED, PI_ERROR,
"Invalid number of source DAG nodes", EXPFILL }}
};
expert_module_t* expert_xip;
proto_xip = proto_register_protocol(
"eXpressive Internet Protocol",
"XIP",
"xip");
xip_handle = register_dissector("xip", dissect_xip, proto_xip);
proto_register_field_array(proto_xip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_xip = expert_register_protocol(proto_xip);
expert_register_field_array(expert_xip, ei, array_length(ei));
}
void
proto_reg_handoff_xip(void)
{
dissector_add_uint("ethertype", ETHERTYPE_XIP, xip_handle);
xip_serval_handle = find_dissector_add_dependency("xipserval", proto_xip);
}
