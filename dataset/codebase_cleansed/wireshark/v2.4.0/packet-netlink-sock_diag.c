static int
_tvb_check_if_zeros(tvbuff_t *tvb, int offset, int len)
{
while (len >= 0) {
if (tvb_get_guint8(tvb, offset) != 0)
return 1;
offset++;
len--;
}
return 0;
}
static void
_dissect_padding(proto_tree *tree _U_, tvbuff_t *tvb, int offset, int len)
{
if (_tvb_check_if_zeros(tvb, offset, len)) {
}
}
static int
dissect_sock_diag_meminfo(proto_tree *tree, netlink_sock_diag_info_t *info, tvbuff_t *tvb, int offset, int len)
{
static header_field_info *hfis[] = {
&hfi_netlink_sock_diag_rmem_alloc,
&hfi_netlink_sock_diag_rcvbuf,
&hfi_netlink_sock_diag_wmem_alloc,
&hfi_netlink_sock_diag_sndbuf,
&hfi_netlink_sock_diag_fwd_alloc,
&hfi_netlink_sock_diag_wmem_queued,
};
guint i;
if (len == 0 || (len % 4) != 0)
return 0;
for (i = 0; len >= 4 && i < G_N_ELEMENTS(hfis); i++) {
proto_tree_add_item(tree, hfis[i], tvb, offset, 4, info->encoding);
offset += 4; len -= 4;
}
if (len != 0) {
}
return 1;
}
static void
sock_diag_proto_tree_add_cookie(proto_tree *tree, netlink_sock_diag_info_t *info _U_, tvbuff_t *tvb, int offset)
{
guint64 cookie;
cookie = tvb_get_letohl(tvb, offset + 4);
cookie <<= 32;
cookie |= tvb_get_letohl(tvb, offset);
proto_tree_add_uint64(tree, hfi_netlink_sock_diag_cookie.id, tvb, offset, 8, cookie);
}
static void
sock_diag_proto_tree_add_shutdown(proto_tree *tree, tvbuff_t *tvb, int offset)
{
guint8 how = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_netlink_sock_diag_shutdown, tvb, offset, 1, ENC_NA);
proto_item_append_text(tree, ": %s", val_to_str(how, netlink_sock_diag_shutdown_flags_vals, "Invalid how value (%x)"));
}
static int
dissect_netlink_unix_sock_diag_reply_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_unix_diag_attr_type type = (enum ws_unix_diag_attr_type) nla_type;
netlink_sock_diag_info_t *info = (netlink_sock_diag_info_t *) data;
switch (type) {
case WS_UNIX_DIAG_NAME:
{
const char *name;
if (len > 0 && tvb_get_guint8(tvb, offset) == '\0') {
name = wmem_strconcat(wmem_packet_scope(),
"@",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset+1, len-1, ENC_ASCII | ENC_NA),
NULL);
} else
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII | ENC_NA);
proto_item_append_text(tree, ": %s", name);
proto_tree_add_string(tree, &hfi_netlink_sock_diag_unix_name, tvb, offset, len, name);
return 1;
}
case WS_UNIX_DIAG_PEER:
if (len == 4) {
proto_item_append_text(tree, ": Peer inode %u", tvb_get_letohl(tvb, offset));
proto_tree_add_item(tree, &hfi_netlink_sock_diag_unix_peer_inode, tvb, offset, 4, info->encoding);
return 1;
}
return 0;
case WS_UNIX_DIAG_RQLEN:
if (len == 8) {
proto_tree_add_item(tree, &hfi_netlink_sock_diag_rqueue, tvb, offset, 4, info->encoding);
proto_tree_add_item(tree, &hfi_netlink_sock_diag_wqueue, tvb, offset, 4, info->encoding);
return 1;
}
return 0;
case WS_UNIX_DIAG_MEMINFO:
return dissect_sock_diag_meminfo(tree, info, tvb, offset, len);
case WS_UNIX_DIAG_SHUTDOWN:
if (len == 1)
sock_diag_proto_tree_add_shutdown(tree, tvb, offset);
return 0;
case WS_UNIX_DIAG_VFS:
case WS_UNIX_DIAG_ICONS:
default:
return 0;
}
}
static int
dissect_sock_diag_unix_reply(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_state, tvb, offset, 1, ENC_NA);
offset += 1;
_dissect_padding(tree, tvb, offset, 1);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return dissect_netlink_attributes(tvb, &hfi_netlink_sock_diag_unix_attr, ett_netlink_sock_diag_attr, info, info->data, tree, offset, -1, dissect_netlink_unix_sock_diag_reply_attrs);
}
static int
dissect_sock_diag_unix_request_show(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *flags_tree;
ti = proto_tree_add_item(tree, &hfi_netlink_sock_diag_unix_show, tvb, offset, 4, info->encoding);
flags_tree = proto_item_add_subtree(ti, ett_netlink_sock_diag_show);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_name, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_vfs, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_peer, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_icons, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_rqlen, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_unix_show_meminfo, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_sock_diag_unix_request(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 1;
_dissect_padding(tree, tvb, offset, 2);
offset += 2;
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
offset = dissect_sock_diag_unix_request_show(tvb, info, tree, offset);
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return offset;
}
static int
dissect_sock_diag_inet_attributes(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_inet_diag_attr_type type = (enum ws_inet_diag_attr_type) nla_type;
netlink_sock_diag_info_t *info = (netlink_sock_diag_info_t *) data;
switch (type) {
case WS_INET_DIAG_MEMINFO:
if (len == 16) {
proto_tree_add_item(tree, &hfi_netlink_sock_diag_rmem_alloc, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_wmem_queued, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_fwd_alloc, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_wmem_alloc, tvb, offset, 4, info->encoding);
return 1;
}
return 0;
case WS_INET_DIAG_SKMEMINFO:
return dissect_sock_diag_meminfo(tree, info, tvb, offset, len);
case WS_INET_DIAG_SHUTDOWN:
if (len == 1)
sock_diag_proto_tree_add_shutdown(tree, tvb, offset);
return 0;
case WS_INET_DIAG_INFO:
case WS_INET_DIAG_VEGASINFO:
case WS_INET_DIAG_CONG:
case WS_INET_DIAG_TOS:
case WS_INET_DIAG_TCLASS:
case WS_INET_DIAG_DCTCPINFO:
case WS_INET_DIAG_PROTOCOL:
case WS_INET_DIAG_SKV6ONLY:
case WS_INET_DIAG_LOCALS:
case WS_INET_DIAG_PEERS:
case WS_INET_DIAG_PAD:
case WS_INET_DIAG_MARK:
case WS_INET_DIAG_BBRINFO:
default:
return 0;
}
}
static int
dissect_sock_diag_inet_sockid(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset, int family)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_sport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_dport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (family) {
case LINUX_AF_INET:
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_src_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
_dissect_padding(tree, tvb, offset, 12);
offset += 12;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_dst_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
_dissect_padding(tree, tvb, offset, 12);
offset += 12;
break;
case LINUX_AF_INET6:
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_src_ip6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_dst_ip6, tvb, offset, 16, ENC_NA);
offset += 16;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_interface, tvb, offset, 4, info->encoding);
offset += 4;
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return offset;
}
static int
dissect_sock_diag_inet_reply(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
guint8 af_family;
af_family = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_state, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 2;
offset = dissect_sock_diag_inet_sockid(tvb, info, tree, offset, af_family);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_rqueue, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_wqueue, tvb, offset, 4, info->encoding);
offset += 4;
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
return dissect_netlink_attributes(tvb, &hfi_netlink_sock_diag_inet_attr, ett_netlink_sock_diag_attr, info, info->data, tree, offset, -1, dissect_sock_diag_inet_attributes);
}
static int
dissect_sock_diag_inet_request(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
guint8 af_family;
af_family = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inet_proto, tvb, offset, 1, ENC_NA);
offset += 1;
offset += 1;
_dissect_padding(tree, tvb, offset, 1);
offset += 1;
offset += 4;
offset = dissect_sock_diag_inet_sockid(tvb, info, tree, offset, af_family);
return offset;
}
static int
dissect_sock_diag_netlink_attributes(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_netlink_diag_attr_type type = (enum ws_netlink_diag_attr_type) nla_type;
netlink_sock_diag_info_t *info = (netlink_sock_diag_info_t *) data;
switch (type) {
case WS_NETLINK_DIAG_MEMINFO:
return dissect_sock_diag_meminfo(tree, info, tvb, offset, len);
case WS_NETLINK_DIAG_GROUPS:
case WS_NETLINK_DIAG_RX_RING:
case WS_NETLINK_DIAG_TX_RING:
default:
return 0;
}
}
static int
dissect_sock_diag_netlink_reply(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_type, tvb, offset, 1, ENC_NA);
switch (tvb_get_guint8(tvb, offset)) {
case WS_SOCK_DGRAM:
case WS_SOCK_RAW:
break;
default:
break;
}
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_netlink_proto, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_state, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_netlink_port_id, tvb, offset, 4, info->encoding);
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_netlink_dst_port_id, tvb, offset, 4, info->encoding);
offset += 4;
offset += 4;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return dissect_netlink_attributes(tvb, &hfi_netlink_sock_diag_netlink_attr, ett_netlink_sock_diag_attr, info, info->data, tree, offset, -1, dissect_sock_diag_netlink_attributes);
}
static int
dissect_sock_diag_netlink_request_show(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *flags_tree;
ti = proto_tree_add_item(tree, &hfi_netlink_sock_diag_netlink_show, tvb, offset, 4, info->encoding);
flags_tree = proto_item_add_subtree(ti, ett_netlink_sock_diag_show);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_netlink_show_meminfo, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_netlink_show_groups, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_netlink_show_ring_cfg, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_sock_diag_netlink_request(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_netlink_proto, tvb, offset, 1, ENC_NA);
offset += 1;
_dissect_padding(tree, tvb, offset, 2);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
offset = dissect_sock_diag_netlink_request_show(tvb, info, tree, offset);
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return offset;
}
static int
dissect_netlink_packet_sock_diag_reply_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_packet_diag_attr_type type = (enum ws_packet_diag_attr_type) nla_type;
netlink_sock_diag_info_t *info = (netlink_sock_diag_info_t *) data;
switch (type) {
case WS_PACKET_DIAG_MEMINFO:
return dissect_sock_diag_meminfo(tree, info, tvb, offset, len);
case WS_PACKET_DIAG_INFO:
case WS_PACKET_DIAG_MCLIST:
case WS_PACKET_DIAG_RX_RING:
case WS_PACKET_DIAG_TX_RING:
case WS_PACKET_DIAG_FANOUT:
case WS_PACKET_DIAG_UID:
case WS_PACKET_DIAG_FILTER:
default:
return 0;
}
}
static int
dissect_sock_diag_packet_reply(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_type, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_packet_proto, tvb, offset, 2, info->encoding);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return dissect_netlink_attributes(tvb, &hfi_netlink_sock_diag_packet_attr, ett_netlink_sock_diag_attr, info, info->data, tree, offset, -1, dissect_netlink_packet_sock_diag_reply_attrs);
}
static int
dissect_sock_diag_packet_request_show(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *flags_tree;
ti = proto_tree_add_item(tree, &hfi_netlink_sock_diag_packet_show, tvb, offset, 4, info->encoding);
flags_tree = proto_item_add_subtree(ti, ett_netlink_sock_diag_show);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_info, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_mclist, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_ring_cfg, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_fanout, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_meminfo, tvb, offset, 4, info->encoding);
proto_tree_add_item(flags_tree, &hfi_netlink_sock_diag_packet_show_filter, tvb, offset, 4, info->encoding);
offset += 4;
return offset;
}
static int
dissect_sock_diag_packet_request(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_sock_diag_family, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_packet_proto, tvb, offset, 1, ENC_NA);
offset += 1;
_dissect_padding(tree, tvb, offset, 2);
offset += 2;
proto_tree_add_item(tree, &hfi_netlink_sock_diag_inode, tvb, offset, 4, info->encoding);
offset += 4;
offset = dissect_sock_diag_packet_request_show(tvb, info, tree, offset);
sock_diag_proto_tree_add_cookie(tree, info, tvb, offset);
offset += 8;
return offset;
}
static int
dissect_sock_diag_by_family(tvbuff_t *tvb, netlink_sock_diag_info_t *info, proto_tree *tree, int offset)
{
const gboolean is_req = (info->pinfo->p2p_dir == P2P_DIR_SENT);
guint8 af_family;
af_family = tvb_get_guint8(tvb, offset);
switch (af_family) {
case LINUX_AF_LOCAL:
offset = (is_req) ?
dissect_sock_diag_unix_request(tvb, info, tree, offset) :
dissect_sock_diag_unix_reply(tvb, info, tree, offset);
break;
case LINUX_AF_INET:
case LINUX_AF_INET6:
offset = (is_req) ?
dissect_sock_diag_inet_request(tvb, info, tree, offset) :
dissect_sock_diag_inet_reply(tvb, info, tree, offset);
break;
case LINUX_AF_NETLINK:
offset = (is_req) ?
dissect_sock_diag_netlink_request(tvb, info, tree, offset) :
dissect_sock_diag_netlink_reply(tvb, info, tree, offset);
break;
case LINUX_AF_PACKET:
offset = (is_req) ?
dissect_sock_diag_packet_request(tvb, info, tree, offset) :
dissect_sock_diag_packet_reply(tvb, info, tree, offset);
break;
}
return offset;
}
static int
dissect_netlink_sock_diag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data)
{
struct packet_netlink_data *data = (struct packet_netlink_data *)_data;
netlink_sock_diag_info_t info;
proto_tree *nlmsg_tree;
proto_item *pi;
int offset = 0;
DISSECTOR_ASSERT(data && data->magic == PACKET_NETLINK_MAGIC);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink sock diag");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_item(tree, proto_registrar_get_nth(proto_netlink_sock_diag), tvb, 0, -1, ENC_NA);
nlmsg_tree = proto_item_add_subtree(pi, ett_netlink_sock_diag);
offset = dissect_netlink_header(tvb, nlmsg_tree, offset, data->encoding, &hfi_netlink_sock_diag_nltype, NULL);
info.encoding = data->encoding;
info.pinfo = pinfo;
info.data = data;
switch (data->type) {
case WS_TCPDIAG_GETSOCK:
case WS_DCCPDIAG_GETSOCK:
break;
case WS_SOCK_DIAG_BY_FAMILY:
offset = dissect_sock_diag_by_family(tvb, &info, nlmsg_tree, offset);
break;
}
return offset;
}
void
proto_register_netlink_sock_diag(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_netlink_sock_diag_nltype,
&hfi_netlink_sock_diag_family,
&hfi_netlink_sock_diag_type,
&hfi_netlink_sock_diag_state,
&hfi_netlink_sock_diag_inode,
&hfi_netlink_sock_diag_rqueue,
&hfi_netlink_sock_diag_wqueue,
&hfi_netlink_sock_diag_shutdown,
&hfi_netlink_sock_diag_cookie,
&hfi_netlink_sock_diag_rmem_alloc,
&hfi_netlink_sock_diag_rcvbuf,
&hfi_netlink_sock_diag_wmem_alloc,
&hfi_netlink_sock_diag_sndbuf,
&hfi_netlink_sock_diag_fwd_alloc,
&hfi_netlink_sock_diag_wmem_queued,
&hfi_netlink_sock_diag_unix_show,
&hfi_netlink_sock_diag_unix_show_name,
&hfi_netlink_sock_diag_unix_show_vfs,
&hfi_netlink_sock_diag_unix_show_peer,
&hfi_netlink_sock_diag_unix_show_icons,
&hfi_netlink_sock_diag_unix_show_rqlen,
&hfi_netlink_sock_diag_unix_show_meminfo,
&hfi_netlink_sock_diag_unix_attr,
&hfi_netlink_sock_diag_unix_name,
&hfi_netlink_sock_diag_unix_peer_inode,
&hfi_netlink_sock_diag_inet_proto,
&hfi_netlink_sock_diag_inet_attr,
&hfi_netlink_sock_diag_inet_sport,
&hfi_netlink_sock_diag_inet_dport,
&hfi_netlink_sock_diag_inet_src_ip4,
&hfi_netlink_sock_diag_inet_dst_ip4,
&hfi_netlink_sock_diag_inet_src_ip6,
&hfi_netlink_sock_diag_inet_dst_ip6,
&hfi_netlink_sock_diag_inet_interface,
&hfi_netlink_sock_diag_netlink_show,
&hfi_netlink_sock_diag_netlink_show_meminfo,
&hfi_netlink_sock_diag_netlink_show_groups,
&hfi_netlink_sock_diag_netlink_show_ring_cfg,
&hfi_netlink_sock_diag_netlink_proto,
&hfi_netlink_sock_diag_netlink_attr,
&hfi_netlink_sock_diag_netlink_port_id,
&hfi_netlink_sock_diag_netlink_dst_port_id,
&hfi_netlink_sock_diag_packet_show,
&hfi_netlink_sock_diag_packet_show_info,
&hfi_netlink_sock_diag_packet_show_mclist,
&hfi_netlink_sock_diag_packet_show_ring_cfg,
&hfi_netlink_sock_diag_packet_show_fanout,
&hfi_netlink_sock_diag_packet_show_meminfo,
&hfi_netlink_sock_diag_packet_show_filter,
&hfi_netlink_sock_diag_packet_proto,
&hfi_netlink_sock_diag_packet_attr
};
#endif
static gint *ett[] = {
&ett_netlink_sock_diag,
&ett_netlink_sock_diag_show,
&ett_netlink_sock_diag_attr
};
proto_netlink_sock_diag = proto_register_protocol("Linux netlink sock diag protocol", "sock_diag", "netlink-sock_diag" );
hfi_netlink_sock_diag = proto_registrar_get_nth(proto_netlink_sock_diag);
proto_register_fields(proto_netlink_sock_diag, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_sock_diag_handle = create_dissector_handle(dissect_netlink_sock_diag, proto_netlink_sock_diag);
}
void
proto_reg_handoff_netlink_sock_diag(void)
{
dissector_add_uint("netlink.protocol", WS_NETLINK_SOCK_DIAG, netlink_sock_diag_handle);
}
