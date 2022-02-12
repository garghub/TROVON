void
isis_dissect_area_address_clv(proto_tree *tree, packet_info* pinfo, tvbuff_t *tvb,
expert_field* expert, int offset, int length)
{
int arealen,area_idx;
while ( length > 0 ) {
arealen = tvb_get_guint8(tvb, offset);
length--;
if (length<=0) {
proto_tree_add_expert_format(tree, pinfo, expert, tvb, offset, -1,
"short address (no length for payload)");
return;
}
if ( arealen > length) {
proto_tree_add_expert_format(tree, pinfo, expert, tvb, offset, -1,
"short address, packet says %d, we have %d left",
arealen, length );
return;
}
if ( tree ) {
proto_item *ti;
tvb_ensure_bytes_exist ( tvb, offset, arealen + 1 );
ti = proto_tree_add_text ( tree, tvb, offset, arealen + 1,
"Area address (%d): ", arealen );
for (area_idx = 0; area_idx < arealen; area_idx++) {
proto_item_append_text(ti, "%02x",
tvb_get_guint8(tvb, offset+area_idx+1));
if (((area_idx & 1) == 0) &&
(area_idx + 1 < arealen)) {
proto_item_append_text(ti, ".");
}
}
}
offset += arealen + 1;
length -= arealen;
}
}
void
isis_dissect_authentication_clv(proto_tree *tree, packet_info* pinfo, tvbuff_t *tvb,
expert_field* auth_expert, int offset, int length)
{
guchar pw_type;
int auth_unsupported;
proto_item *ti;
if ( length <= 0 ) {
return;
}
pw_type = tvb_get_guint8(tvb, offset);
offset += 1;
length--;
auth_unsupported = FALSE;
switch (pw_type) {
case 1:
ti = proto_tree_add_text ( tree, tvb, offset - 1, length + 1,
"clear text (1), password (length %d) = ", length);
if ( length > 0 ) {
proto_item_append_text(ti, "%s",
tvb_format_text(tvb, offset, length));
} else {
proto_item_append_text(ti, "no clear-text password found!!!");
}
break;
case 54:
ti = proto_tree_add_text ( tree, tvb, offset - 1, length + 1,
"hmac-md5 (54), password (length %d) = ", length);
if ( length == 16 ) {
proto_item_append_text(ti, "0x%02x", tvb_get_guint8(tvb, offset));
offset += 1;
length--;
while (length > 0) {
proto_item_append_text(ti, "%02x", tvb_get_guint8(tvb, offset));
offset += 1;
length--;
}
} else {
proto_item_append_text(ti,
"illegal hmac-md5 digest format (must be 16 bytes)");
}
break;
default:
proto_tree_add_text ( tree, tvb, offset - 1, length + 1,
"type 0x%02x (0x%02x): ", pw_type, length );
auth_unsupported=TRUE;
break;
}
if ( auth_unsupported ) {
proto_tree_add_expert(tree, pinfo, auth_expert, tvb, offset, -1);
}
}
void
isis_dissect_ip_authentication_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length)
{
if ( !tree ) return;
if ( length != 0 ) {
proto_tree_add_text ( tree, tvb, offset, length,
"IP Authentication: %.*s", length,
tvb_get_string(wmem_packet_scope(), tvb, offset, length) );
}
}
void
isis_dissect_hostname_clv(tvbuff_t *tvb, proto_tree *tree, int offset,
int length, int tree_id)
{
if ( !tree ) return;
if ( length == 0 ) {
proto_tree_add_text ( tree, tvb, offset, length,
"Hostname: --none--" );
} else {
const char* value = tvb_get_string(wmem_packet_scope(), tvb, offset, length);
proto_tree_add_string_format ( tree, tree_id,
tvb, offset, length,
value, "Hostname: %.*s", length, value);
}
}
void
isis_dissect_mt_clv(tvbuff_t *tvb, proto_tree *tree, int offset, int length,
int tree_id)
{
guint16 mt_block;
const char *mt_desc;
while (length>0) {
if (length!=1) {
mt_block=tvb_get_ntohs(tvb, offset);
switch(mt_block&0x0fff) {
case 0:
mt_desc="IPv4 unicast";
break;
case 1:
mt_desc="In-Band Management";
break;
case 2:
mt_desc="IPv6 unicast";
break;
case 3:
mt_desc="Multicast";
break;
case 4095:
mt_desc="Development, Experimental or Proprietary";
break;
default:
mt_desc="Reserved for IETF Consensus";
break;
}
proto_tree_add_uint_format ( tree, tree_id, tvb, offset, 2,
mt_block,
"%s Topology (0x%03x), %ssubTLVs present%s",
mt_desc,
mt_block&0xfff,
(mt_block&0x8000) ? "" : "no ",
(mt_block&0x4000) ? ", ATT bit set" : "" );
} else {
proto_tree_add_text ( tree, tvb, offset, 1,
"malformed MT-ID");
break;
}
length -= 2;
offset += 2;
}
}
void
isis_dissect_ip_int_clv(proto_tree *tree, packet_info* pinfo, tvbuff_t *tvb, expert_field* expert,
int offset, int length, int tree_id)
{
if ( length <= 0 ) {
return;
}
while ( length > 0 ) {
if ( length < 4 ) {
proto_tree_add_expert_format(tree, pinfo, expert, tvb, offset, -1,
"Short IP interface address (%d vs 4)",length );
return;
}
if ( tree ) {
proto_tree_add_item(tree, tree_id, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
length -= 4;
}
}
void
isis_dissect_ipv6_int_clv(proto_tree *tree, packet_info* pinfo, tvbuff_t *tvb, expert_field* expert,
int offset, int length, int tree_id)
{
guint8 addr [16];
if ( length <= 0 ) {
return;
}
while ( length > 0 ) {
if ( length < 16 ) {
proto_tree_add_expert_format(tree, pinfo, expert, tvb, offset, -1,
"Short IPv6 interface address (%d vs 16)",length );
return;
}
tvb_memcpy(tvb, addr, offset, sizeof(addr));
if ( tree ) {
proto_tree_add_ipv6(tree, tree_id, tvb, offset, 16, addr);
}
offset += 16;
length -= 16;
}
}
void
isis_dissect_te_router_id_clv(proto_tree *tree, packet_info* pinfo, tvbuff_t *tvb, expert_field* expert,
int offset, int length, int tree_id)
{
if ( length <= 0 ) {
return;
}
if ( length != 4 ) {
proto_tree_add_expert_format(tree, pinfo, expert, tvb, offset, -1,
"malformed Traffic Engineering Router ID (%d vs 4)",length );
return;
}
proto_tree_add_item(tree, tree_id, tvb, offset, 4, ENC_BIG_ENDIAN);
}
void
isis_dissect_nlpid_clv(tvbuff_t *tvb, proto_tree *tree, int offset, int length)
{
gboolean first;
proto_item *ti;
if ( !tree ) return;
tvb_ensure_bytes_exist ( tvb, offset, length );
if (length <= 0) {
proto_tree_add_text (tree, tvb, offset, length,
"NLPID(s): --none--");
} else {
first = TRUE;
ti = proto_tree_add_text (tree, tvb, offset, length,
"NLPID(s): ");
while (length-- > 0 ) {
if (!first) {
proto_item_append_text(ti, ", ");
}
proto_item_append_text(ti, "%s (0x%02x)",
(tvb_get_guint8(tvb, offset) == NLPID_IEEE_8021AQ
? "IEEE 802.1aq (SPB)"
: val_to_str_const(tvb_get_guint8(tvb, offset), nlpid_vals, "Unknown")),
tvb_get_guint8(tvb, offset));
offset++;
first = FALSE;
}
}
}
void
isis_dissect_clvs(tvbuff_t *tvb, packet_info* pinfo, proto_tree *tree, int offset,
const isis_clv_handle_t *opts, expert_field* expert_short_len, int len, int id_length,
int unknown_tree_id _U_)
{
guint8 code;
guint8 length;
int q;
proto_item *ti;
proto_tree *clv_tree;
while ( len > 0 ) {
code = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
if (len == 0)
break;
length = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
if (len == 0)
break;
if ( len < length ) {
proto_tree_add_expert_format(tree, pinfo, expert_short_len, tvb, offset, -1,
"Short CLV header (%d vs %d)",
length, len );
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
opts[q].dissect(tvb, pinfo, clv_tree, offset,
id_length, length);
} else {
#if 0
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "Unknown code %u (%u)",
code, length);
clv_tree = proto_item_add_subtree(ti,
unknown_tree_id );
} else {
clv_tree = NULL;
}
#else
if (tree) {
proto_tree_add_text(tree, tvb, offset - 2,
length + 2, "Unknown code %u (%u)",
code, length);
}
#endif
}
offset += length;
len -= length;
}
}
