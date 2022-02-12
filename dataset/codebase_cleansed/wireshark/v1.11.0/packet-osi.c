cksum_status_t
calc_checksum( tvbuff_t *tvb, int offset, guint len, guint checksum) {
const gchar *buffer;
guint available_len;
const guint8 *p;
guint32 c0, c1;
guint seglen;
guint i;
if ( 0 == checksum )
return( NO_CKSUM );
available_len = tvb_length_remaining( tvb, offset );
if ( available_len < len )
return( DATA_MISSING );
buffer = tvb_get_ptr( tvb, offset, len );
p = buffer;
c0 = 0;
c1 = 0;
while (len != 0) {
seglen = len;
if (seglen > 5803)
seglen = 5803;
for (i = 0; i < seglen; i++) {
c0 = c0 + *(p++);
c1 += c0;
}
c0 = c0 % 255;
c1 = c1 % 255;
len -= seglen;
}
if (c0 != 0 || c1 != 0)
return( CKSUM_NOT_OK );
else
return( CKSUM_OK );
}
cksum_status_t
check_and_get_checksum( tvbuff_t *tvb, int offset, guint len, guint checksum, int offset_check, guint16* result) {
const gchar *buffer;
guint available_len;
const guint8 *p;
guint8 discard = 0;
guint32 c0, c1, factor;
guint seglen, initlen = len;
guint i;
int block, x, y;
if ( 0 == checksum )
return( NO_CKSUM );
available_len = tvb_length_remaining( tvb, offset );
offset_check -= offset;
if ( ( available_len < len ) || ( offset_check < 0 ) || ( (guint)(offset_check+2) > len ) )
return( DATA_MISSING );
buffer = tvb_get_ptr( tvb, offset, len );
block = offset_check / 5803;
p = buffer;
c0 = 0;
c1 = 0;
while (len != 0) {
seglen = len;
if ( block-- == 0 ) {
seglen = offset_check % 5803;
discard = 1;
} else if ( seglen > 5803 )
seglen = 5803;
for (i = 0; i < seglen; i++) {
c0 = c0 + *(p++);
c1 += c0;
}
if ( discard ) {
p += 2;
c1 += 2*c0;
len -= 2;
discard = 0;
}
c0 = c0 % 255;
c1 = c1 % 255;
len -= seglen;
}
factor = ( initlen - offset_check ) * c0;
x = factor - c0 - c1;
y = c1 - factor - 1;
if (x < 0 ) x--;
if (y > 0 ) y++;
x %= 255;
y %= 255;
if (x == 0) x = 0xFF;
if (y == 0) y = 0x01;
*result = ( x << 8 ) | ( y & 0xFF );
if (*result != checksum)
return( CKSUM_NOT_OK );
else
return( CKSUM_OK );
}
gboolean check_atn_ec_32(
tvbuff_t *tvb, guint tpdu_len,
guint offset_ec_32_val,
guint offset_iso8073_val,
guint clnp_dst_len,
const guint8 *clnp_dst,
guint clnp_src_len,
const guint8 *clnp_src)
{
guint i = 0;
guint32 c0 = 0;
guint32 c1 = 0;
guint32 c2 = 0;
guint32 c3 = 0;
guint32 sum = 0;
for ( i =0; i< tpdu_len; i++){
c0 += tvb_get_guint8(tvb, i) ;
if( ( i >= offset_ec_32_val ) &&
( i < ( offset_ec_32_val + 4 ) ) ) {
c0 -= tvb_get_guint8(tvb, i);
}
if( ( offset_iso8073_val ) &&
( i >= offset_iso8073_val ) &&
( i < ( offset_iso8073_val + 2 ) ) ) {
c0 -= tvb_get_guint8(tvb, i);
}
if ( c0 >= 0x000000FF )
c0 -= 0x00000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
}
c0 += clnp_dst_len;
if ( c0 >= 0x000000FF )
c0 -= 0x000000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
for ( i =0; i< clnp_dst_len; i++){
c0 += clnp_dst[i];
if ( c0 >= 0x000000FF )
c0 -= 0x000000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
}
c0 += clnp_src_len;
if ( c0 >= 0x000000FF )
c0 -= 0x000000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
for ( i =0; i< clnp_src_len; i++){
c0 += clnp_src[i];
if ( c0 >= 0x000000FF )
c0 -= 0x000000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
}
for ( i = offset_ec_32_val; i< (offset_ec_32_val+4); i++){
c0 += tvb_get_guint8(tvb, i) ;
if ( c0 >= 0x000000FF )
c0 -= 0x00000FF;
c1 += c0;
if ( c1 >= 0x000000FF )
c1 -= 0x000000FF;
c2 += c1;
if ( c2 >= 0x000000FF )
c2 -= 0x000000FF;
c3 += c2;
if ( c3 >= 0x000000FF )
c3 -= 0x000000FF;
}
sum = (c3 << 24) + (c2 << 16 ) + (c1 << 8) + c0 ;
if(!sum)
return TRUE;
else
return FALSE;
}
gboolean check_atn_ec_16(
tvbuff_t *tvb,
guint tpdu_len,
guint offset_ec_16_val,
guint offset_iso8073_val,
guint clnp_dst_len,
const guint8 *clnp_dst,
guint clnp_src_len,
const guint8 *clnp_src)
{
guint i = 0;
guint16 c0 = 0;
guint16 c1 = 0;
guint16 sum = 0;
for ( i =0; i< tpdu_len; i++){
c0 += tvb_get_guint8(tvb, i);
if( (i >= offset_ec_16_val) &&
(i < (offset_ec_16_val + 2) ) ) {
c0 -= tvb_get_guint8(tvb, i) ;
}
if( (i >= offset_iso8073_val) &&
(i < (offset_iso8073_val + 2) ) ) {
c0 -= tvb_get_guint8(tvb, i) ;
}
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
}
c0 += clnp_dst_len;
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
for ( i =0; i< clnp_dst_len; i++){
c0 += clnp_dst[i];
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
}
c0 += clnp_src_len;
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
for ( i =0; i< clnp_src_len; i++){
c0 += clnp_src[i];
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
}
for ( i = offset_ec_16_val; i< (offset_ec_16_val+2); i++){
c0 += tvb_get_guint8(tvb, i) ;
if ( c0 >= 0x00FF )
c0 -= 0x00FF;
c1 += c0;
if ( c1 >= 0x00FF )
c1 -= 0x00FF;
}
sum = (c1 << 8) + c0 ;
if(!sum)
return TRUE;
else
return FALSE;
}
static void
dissect_osi_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_tpkt_encap(tvb, pinfo, tree, tpkt_desegment, osi_handle);
}
static void dissect_osi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 nlpid;
tvbuff_t *new_tvb;
pinfo->current_proto = "OSI";
nlpid = tvb_get_guint8(tvb, 0);
if (dissector_try_uint(osinl_incl_subdissector_table, nlpid, tvb, pinfo, tree))
return;
new_tvb = tvb_new_subset_remaining(tvb, 1);
if (dissector_try_uint(osinl_excl_subdissector_table, nlpid, new_tvb, pinfo, tree))
return;
switch (nlpid) {
case NLPID_ISO9542X25_ESIS:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ESIS (X.25)");
call_dissector(data_handle,tvb, pinfo, tree);
break;
case NLPID_ISO10747_IDRP:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IDRP");
call_dissector(data_handle,tvb, pinfo, tree);
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISO");
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown ISO protocol (%02x)", nlpid);
call_dissector(data_handle,tvb, pinfo, tree);
break;
}
}
void
proto_reg_handoff_osi(void)
{
static gboolean osi_prefs_initialized = FALSE;
static dissector_handle_t osi_tpkt_handle;
static guint tcp_port_osi_over_tpkt;
if (!osi_prefs_initialized) {
osi_handle = create_dissector_handle(dissect_osi, proto_osi);
dissector_add_uint("llc.dsap", SAP_OSINL1, osi_handle);
dissector_add_uint("llc.dsap", SAP_OSINL2, osi_handle);
dissector_add_uint("llc.dsap", SAP_OSINL3, osi_handle);
dissector_add_uint("llc.dsap", SAP_OSINL4, osi_handle);
dissector_add_uint("llc.dsap", SAP_OSINL5, osi_handle);
dissector_add_uint("ppp.protocol", PPP_OSI, osi_handle);
dissector_add_uint("chdlc.protocol", CHDLCTYPE_OSI, osi_handle);
dissector_add_uint("null.type", BSD_AF_ISO, osi_handle);
dissector_add_uint("gre.proto", SAP_OSINL5, osi_handle);
dissector_add_uint("ip.proto", IP_PROTO_ISOIP, osi_handle);
data_handle = find_dissector("data");
ppp_handle = find_dissector("ppp");
osi_tpkt_handle = create_dissector_handle(dissect_osi_tpkt, proto_osi);
dissector_add_handle("tcp.port", osi_tpkt_handle);
osi_prefs_initialized = TRUE;
} else {
if (tcp_port_osi_over_tpkt != 0) {
dissector_delete_uint("tcp.port", tcp_port_osi_over_tpkt, osi_tpkt_handle);
}
}
if (global_tcp_port_osi_over_tpkt != 0) {
dissector_add_uint("tcp.port", global_tcp_port_osi_over_tpkt, osi_tpkt_handle);
}
tcp_port_osi_over_tpkt = global_tcp_port_osi_over_tpkt;
}
void
proto_register_osi(void)
{
module_t *osi_module;
osinl_incl_subdissector_table = register_dissector_table("osinl.incl",
"OSI incl NLPID", FT_UINT8, BASE_HEX);
osinl_excl_subdissector_table = register_dissector_table("osinl.excl",
"OSI excl NLPID", FT_UINT8, BASE_HEX);
proto_osi = proto_register_protocol("OSI", "OSI", "osi");
osi_module = prefs_register_protocol(proto_osi, proto_reg_handoff_osi);
prefs_register_uint_preference(osi_module, "tpkt_port",
"TCP port for OSI over TPKT",
"TCP port for OSI over TPKT",
10, &global_tcp_port_osi_over_tpkt);
prefs_register_bool_preference(osi_module, "tpkt_reassemble",
"Reassemble segmented TPKT datagrams",
"Whether segmented TPKT datagrams should be reassembled",
&tpkt_desegment);
}
