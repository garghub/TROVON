static void
dissect_vjuc(tvbuff_t *tvb, packet_info *pinfo, proto_tree * tree)
{
proto_item *ti;
proto_tree *vj_tree = NULL;
slcompress *comp;
int i;
gint conn_index;
cstate *cs = NULL;
guint8 ihl;
guint8 thl;
guint8 *buffer;
tvbuff_t *next_tvb;
gint isize = tvb_length(tvb);
gint ipsize;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP VJ");
if(tree != NULL) {
ti = proto_tree_add_protocol_format(tree, proto_vj, tvb, 0, -1,
"PPP VJ Compression: Uncompressed data");
vj_tree = proto_item_add_subtree(ti, ett_vj);
}
if(pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
comp = NULL;
} else {
comp = rx_tx_state[pinfo->p2p_dir];
}
if(!tvb_bytes_exist(tvb, IP_FIELD_PROTOCOL, 1)) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (not enough data available)");
if(tree != NULL)
call_dissector(data_handle, tvb, pinfo, tree);
if(comp != NULL) {
for(i = 0; i < TCP_SIMUL_CONV_MAX; i++)
comp->rstate[i].flags |= SLF_TOSS;
}
return;
}
conn_index = tvb_get_guint8(tvb, IP_FIELD_PROTOCOL);
if(tree != NULL)
proto_tree_add_uint(vj_tree, hf_vj_connection_number, tvb,
IP_FIELD_PROTOCOL, 1, conn_index);
if(comp != NULL) {
comp->recv_current = conn_index;
cs = &comp->rstate[conn_index];
}
ihl = tvb_get_guint8(tvb, 0) & IP_HDR_LEN_MASK;
ihl <<= 2;
if(ihl < IP_HDR_LEN) {
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (IP header length (%u) < %u)",
ihl, IP_HDR_LEN);
}
if(cs != NULL)
cs->flags |= SLF_TOSS;
return;
}
if(isize < ihl) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (not enough data available)");
if(tree != NULL)
call_dissector(data_handle, tvb, pinfo, tree);
if(cs != NULL)
cs->flags |= SLF_TOSS;
return;
}
col_set_str(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP");
buffer = tvb_memdup(tvb, 0, isize);
buffer[IP_FIELD_PROTOCOL] = IP_PROTO_TCP;
if(ip_csum(buffer, ihl) != ZERO) {
if(cs != NULL)
cs->flags |= SLF_TOSS;
cs = NULL;
} else {
if(!tvb_bytes_exist(tvb, ihl + TCP_FIELD_HDR_LEN, 1)) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (not enough data available)");
if(cs != NULL)
cs->flags |= SLF_TOSS;
cs = NULL;
} else {
thl = tvb_get_guint8(tvb, ihl + TCP_FIELD_HDR_LEN);
thl = ((thl & 0xf0) >> 4) * 4;
if(thl < TCP_HDR_LEN) {
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (TCP header length (%u) < %u)",
thl, TCP_HDR_LEN);
}
if(cs != NULL)
cs->flags |= SLF_TOSS;
cs = NULL;
} else {
if(isize < thl) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ uncompressed TCP (not enough data available)");
if(cs != NULL)
cs->flags |= SLF_TOSS;
cs = NULL;
}
}
}
}
if(!pinfo->fd->flags.visited) {
if(cs != NULL) {
cs->flags &= ~SLF_TOSS;
memcpy(&cs->cs_ip, &buffer[0], IP_HDR_LEN);
memcpy(&cs->cs_tcp, &buffer[ihl], TCP_HDR_LEN);
if(ihl > IP_HDR_LEN)
memcpy(cs->cs_ipopt, &buffer[sizeof(iphdr_type)], ihl - IP_HDR_LEN);
if(TCP_OFFSET(&(cs->cs_tcp)) > 5)
memcpy(cs->cs_tcpopt, &buffer[ihl + sizeof(tcphdr_type)],
(TCP_OFFSET(&(cs->cs_tcp)) - 5) * 4);
}
}
ipsize = pntohs(&buffer[IP_FIELD_TOT_LEN]);
if (ipsize < isize)
isize = ipsize;
next_tvb = tvb_new_child_real_data(tvb, buffer, isize, ipsize);
tvb_set_free_cb(next_tvb, g_free);
add_new_data_source(pinfo, next_tvb, "VJ Uncompressed");
call_dissector(ip_handle, next_tvb, pinfo, tree);
}
static void
dissect_vjc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *vj_tree = NULL;
tvbuff_t *next_tvb = NULL;
slcompress *comp = NULL;
gint err = VJ_ERROR;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPP VJ");
if(tree != NULL) {
ti = proto_tree_add_protocol_format(tree, proto_vj, tvb, 0, -1,
"PPP VJ Compression: Compressed data");
vj_tree = proto_item_add_subtree(ti, ett_vj);
}
if(!ppp_vj_decomp || pinfo->p2p_dir == P2P_DIR_UNKNOWN) {
comp = NULL;
} else {
comp = rx_tx_state[pinfo->p2p_dir];
}
if(vjc_process(tvb, pinfo, vj_tree, comp) == VJ_ERROR)
return;
err = vjc_tvb_setup(tvb, &next_tvb, pinfo);
if(err == VJ_ERROR) {
if(tree != NULL)
call_dissector(data_handle, tvb, pinfo, vj_tree);
return;
}
call_dissector(ip_handle, next_tvb, pinfo, tree);
}
static void
vj_init(void)
{
gint i = ZERO;
for(i = 0; i < RX_TX_STATE_COUNT; i++) {
rx_tx_state[i] = slhc_init();
}
return;
}
static slcompress *
slhc_init(void)
{
slcompress *comp = se_alloc0(sizeof(slcompress));
int i;
comp->recv_current = TCP_SIMUL_CONV_MAX - 1;
for (i = 0; i < TCP_SIMUL_CONV_MAX; i++)
comp->rstate[i].flags |= SLF_TOSS;
return comp;
}
static gint
vjc_tvb_setup(tvbuff_t *src_tvb,
tvbuff_t **dst_tvb,
packet_info *pinfo)
{
vj_header_t *hdr_buf;
guint8 offset;
guint8 *data_ptr;
gint hdr_len;
gint tot_len;
gint buf_len;
guint8 *pbuf;
DISSECTOR_ASSERT(src_tvb);
hdr_buf = p_get_proto_data(pinfo->fd, proto_vj);
if(hdr_buf == NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ compressed TCP (previous data bad or missing)");
return VJ_ERROR;
}
col_set_str(pinfo->cinfo, COL_INFO, "VJ compressed TCP");
offset = hdr_buf->offset;
data_ptr = hdr_buf->data;
hdr_len = lo_nibble(data_ptr[0]) * 4;
hdr_len += hi_nibble(data_ptr[hdr_len + 12]) * 4;
buf_len = tvb_length(src_tvb) + hdr_len - offset;
pbuf = g_malloc(buf_len);
memcpy(pbuf, data_ptr, hdr_len);
tvb_memcpy(src_tvb, pbuf + hdr_len, offset, buf_len - hdr_len);
memcpy(&tot_len, data_ptr + 2, 2);
*dst_tvb = tvb_new_child_real_data(src_tvb, pbuf, buf_len, g_ntohs(tot_len));
tvb_set_free_cb(*dst_tvb, g_free);
add_new_data_source(pinfo, *dst_tvb, "VJ Decompressed");
return VJ_OK;
}
static gint
vjc_process(tvbuff_t *src_tvb, packet_info *pinfo, proto_tree *tree,
slcompress *comp)
{
int offset = ZERO;
int i;
gint changes;
proto_item *ti;
proto_tree *changes_tree;
guint8 conn_index;
cstate *cs = NULL;
iphdr_type *ip = NULL;
tcphdr_type *thp = NULL;
guint16 tcp_cksum;
gint hdrlen = ZERO;
guint16 word;
int delta;
gint len;
vj_header_t *buf_hdr;
guint8 *data_ptr;
if(tvb_length(src_tvb) < 3){
col_set_str(pinfo->cinfo, COL_INFO, "VJ compressed TCP (not enough data available)");
if(tree != NULL)
call_dissector(data_handle, src_tvb, pinfo, tree);
if(comp != NULL) {
for(i = 0; i < TCP_SIMUL_CONV_MAX; i++)
comp->rstate[i].flags |= SLF_TOSS;
}
return VJ_ERROR;
}
changes = tvb_get_guint8(src_tvb, offset);
if(tree != NULL) {
switch (changes & SPECIALS_MASK) {
case SPECIAL_I:
ti = proto_tree_add_uint_format(tree, hf_vj_change_mask, src_tvb,
offset, 1, changes,
"Change mask: 0x%02x (echoed interactive traffic)",
changes);
break;
case SPECIAL_D:
ti = proto_tree_add_uint_format(tree, hf_vj_change_mask, src_tvb,
offset, 1, changes,
"Change mask: 0x%02x (unidirectional data)",
changes);
break;
default:
ti = proto_tree_add_uint_format(tree, hf_vj_change_mask, src_tvb,
offset, 1, changes,
"Change mask: 0x%02x", changes);
break;
}
changes_tree = proto_item_add_subtree(ti, ett_vj_changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_c, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_i, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_p, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_s, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_a, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_w, src_tvb,
offset, 1, changes);
proto_tree_add_boolean(changes_tree, hf_vj_change_mask_u, src_tvb,
offset, 1, changes);
}
offset++;
if(changes & NEW_C){
conn_index = tvb_get_guint8(src_tvb, offset);
if(tree != NULL)
proto_tree_add_uint(tree, hf_vj_connection_number, src_tvb, offset, 1,
conn_index);
offset++;
if(comp != NULL)
comp->recv_current = conn_index;
}
if(!pinfo->fd->flags.visited) {
if(comp != NULL && !(comp->rstate[comp->recv_current].flags & SLF_TOSS)) {
cs = &comp->rstate[comp->recv_current];
thp = &cs->cs_tcp;
ip = &cs->cs_ip;
}
}
tcp_cksum = tvb_get_ntohs(src_tvb, offset);
if(tree != NULL)
proto_tree_add_uint(tree, hf_vj_tcp_cksum, src_tvb, offset, 2, tcp_cksum);
if(cs != NULL) {
hdrlen = lo_nibble(ip->ihl_version) * 4 + TCP_OFFSET(thp) * 4;
thp->cksum = g_htons(tcp_cksum);
}
offset += 2;
if(cs != NULL) {
if(changes & CHANGE_PUSH_BIT)
thp->flags |= TCP_PUSH_BIT;
else
thp->flags &= ~TCP_PUSH_BIT;
}
switch(changes & SPECIALS_MASK){
guint32 tmp;
case SPECIAL_I:
if(cs != NULL) {
word = g_ntohs(ip->tot_len) - hdrlen;
tmp = g_ntohl(thp->ack_seq) + word;
thp->ack_seq = g_htonl(tmp);
tmp = g_ntohl(thp->seq) + word;
thp->seq = g_htonl(tmp);
}
break;
case SPECIAL_D:
if(cs != NULL) {
tmp = g_ntohl(thp->seq) + g_ntohs(ip->tot_len) - hdrlen;
thp->seq = g_htonl(tmp);
}
break;
default:
if(changes & NEW_U){
delta = get_unsigned_delta(src_tvb, &offset, hf_vj_urp, tree);
if(cs != NULL) {
thp->urg_ptr = delta;
thp->flags |= TCP_URG_BIT;
}
} else {
if(cs != NULL)
thp->flags &= ~TCP_URG_BIT;
}
if(changes & NEW_W) {
delta = get_signed_delta(src_tvb, &offset, hf_vj_win_delta, tree);
if(cs != NULL) {
tmp = g_ntohs(thp->window) + delta;
thp->window = g_htons(tmp);
}
}
if(changes & NEW_A) {
delta = get_unsigned_delta(src_tvb, &offset, hf_vj_ack_delta, tree);
if(cs != NULL) {
tmp = g_ntohl(thp->ack_seq) + delta;
thp->ack_seq = g_htonl(tmp);
}
}
if(changes & NEW_S) {
delta = get_unsigned_delta(src_tvb, &offset, hf_vj_seq_delta, tree);
if(cs != NULL) {
tmp = g_ntohl(thp->seq) + delta;
thp->seq = g_htonl(tmp);
}
}
break;
}
if(changes & NEW_I)
delta = get_unsigned_delta(src_tvb, &offset, hf_vj_ip_id_delta, tree);
else
delta = 1;
if(cs != NULL) {
guint32 tmp;
tmp = g_ntohs(ip->id) + delta;
ip->id = g_htons(tmp);
}
len = tvb_reported_length_remaining(src_tvb, offset);
if(len < ZERO) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ compressed TCP (not enough data available)");
if(cs != NULL)
cs->flags |= SLF_TOSS;
return VJ_ERROR;
}
if(tree != NULL && tvb_offset_exists(src_tvb, offset))
proto_tree_add_text(tree, src_tvb, offset, -1, "TCP payload");
if(comp == NULL) {
col_set_str(pinfo->cinfo, COL_INFO, "VJ compressed TCP (direction unknown)");
return VJ_ERROR;
}
if((cs != NULL) && (!pinfo->fd->flags.visited)) {
len += hdrlen;
ip->tot_len = g_htons(len);
ip->cksum = ZERO;
ip->cksum = ip_csum((guint8 *)ip, lo_nibble(ip->ihl_version) * 4);
buf_hdr = se_alloc(sizeof (vj_header_t));
buf_hdr->offset = offset;
data_ptr = buf_hdr->data;
memcpy(data_ptr, ip, IP_HDR_LEN);
data_ptr += IP_HDR_LEN;
if(lo_nibble(ip->ihl_version) > 5) {
memcpy(data_ptr, cs->cs_ipopt, (lo_nibble(ip->ihl_version) - 5) * 4);
data_ptr += (lo_nibble(ip->ihl_version) - 5) * 4;
}
memcpy(data_ptr, thp, TCP_HDR_LEN);
data_ptr += TCP_HDR_LEN;
if(TCP_OFFSET(thp) > 5)
memcpy(data_ptr, cs->cs_tcpopt, (TCP_OFFSET(thp) - 5) * 4);
p_add_proto_data(pinfo->fd, proto_vj, buf_hdr);
}
return VJ_OK;
}
static int
get_unsigned_delta(tvbuff_t *tvb, int *offsetp, int hf, proto_tree *tree)
{
int offset = *offsetp;
int len;
guint16 del;
len = 1;
del = tvb_get_guint8(tvb, offset++);
if(del == ZERO){
del = tvb_get_ntohs(tvb, offset);
offset += 2;
len += 2;
}
if(tree != NULL)
proto_tree_add_uint(tree, hf, tvb, *offsetp, len, del);
*offsetp = offset;
return del;
}
static int
get_signed_delta(tvbuff_t *tvb, int *offsetp, int hf, proto_tree *tree)
{
int offset = *offsetp;
int len;
gint16 del;
len = 1;
del = tvb_get_guint8(tvb, offset++);
if(del == ZERO){
del = tvb_get_ntohs(tvb, offset);
offset += 2;
len += 2;
}
if(tree != NULL)
proto_tree_add_int(tree, hf, tvb, *offsetp, len, del);
*offsetp = offset;
return del;
}
static guint16
ip_csum(const guint8 * ptr, guint32 len)
{
vec_t cksum_vec[1];
cksum_vec[0].ptr = ptr;
cksum_vec[0].len = len;
return in_cksum(&cksum_vec[0], 1);
}
void
proto_register_vj(void)
{
static hf_register_info hf[] = {
{ &hf_vj_change_mask,
{ "Change mask", "vj.change_mask", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_vj_change_mask_c,
{ "Connection changed", "vj.change_mask_c", FT_BOOLEAN, 8,
NULL, NEW_C, "Connection number changed", HFILL }},
{ &hf_vj_change_mask_i,
{ "IP ID change != 1", "vj.change_mask_i", FT_BOOLEAN, 8,
NULL, NEW_I, "IP ID changed by a value other than 1", HFILL }},
{ &hf_vj_change_mask_p,
{ "Push bit set", "vj.change_mask_p", FT_BOOLEAN, 8,
NULL, CHANGE_PUSH_BIT, "TCP PSH flag set", HFILL }},
{ &hf_vj_change_mask_s,
{ "Sequence number changed", "vj.change_mask_s", FT_BOOLEAN, 8,
NULL, NEW_S, NULL, HFILL }},
{ &hf_vj_change_mask_a,
{ "Ack number changed", "vj.change_mask_a", FT_BOOLEAN, 8,
NULL, NEW_A, "Acknowledgement sequence number changed", HFILL }},
{ &hf_vj_change_mask_w,
{ "Window changed", "vj.change_mask_w", FT_BOOLEAN, 8,
NULL, NEW_W, "TCP window changed", HFILL }},
{ &hf_vj_change_mask_u,
{ "Urgent pointer set", "vj.change_mask_u", FT_BOOLEAN, 8,
NULL, NEW_U, NULL, HFILL }},
{ &hf_vj_connection_number,
{ "Connection number", "vj.connection_number", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_vj_tcp_cksum,
{ "TCP checksum", "vj.tcp_cksum", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_vj_urp,
{ "Urgent pointer", "vj.urp", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_vj_win_delta,
{ "Window delta", "vj.win_delta", FT_INT16, BASE_DEC,
NULL, 0x0, "Delta for window", HFILL }},
{ &hf_vj_ack_delta,
{ "Ack delta", "vj.ack_delta", FT_UINT16, BASE_DEC,
NULL, 0x0, "Delta for acknowledgment sequence number", HFILL }},
{ &hf_vj_seq_delta,
{ "Sequence delta", "vj.seq_delta", FT_UINT16, BASE_DEC,
NULL, 0x0, "Delta for sequence number", HFILL }},
{ &hf_vj_ip_id_delta,
{ "IP ID delta", "vj.ip_id_delta", FT_UINT16, BASE_DEC,
NULL, 0x0, "Delta for IP ID", HFILL }},
};
static gint *ett[] = {
&ett_vj,
&ett_vj_changes,
};
proto_vj = proto_register_protocol("PPP VJ Compression", "PPP VJ", "vj");
proto_register_field_array(proto_vj, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(&vj_init);
}
void
proto_reg_handoff_vj(void)
{
dissector_handle_t vjc_handle;
dissector_handle_t vjuc_handle;
vjc_handle = create_dissector_handle(dissect_vjc, proto_vj);
dissector_add_uint("ppp.protocol", PPP_VJC_COMP, vjc_handle);
vjuc_handle = create_dissector_handle(dissect_vjuc, proto_vj);
dissector_add_uint("ppp.protocol", PPP_VJC_UNCOMP, vjuc_handle);
ip_handle = find_dissector("ip");
data_handle = find_dissector("data");
}
