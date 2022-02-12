static guint
qname_labels_count(const guchar* name, guint name_len)
{
guint labels = 0;
unsigned i;
if (name_len > 1) {
for (i = 0; i < strlen(name); i++) {
if (name[i] == '.')
labels++;
}
labels++;
}
return labels;
}
int
expand_dns_name(tvbuff_t *tvb, int offset, int max_len, int dns_data_offset,
const guchar **name)
{
int start_offset = offset;
guchar *np;
int len = -1;
int chars_processed = 0;
int data_size = tvb_reported_length_remaining(tvb, dns_data_offset);
int component_len;
int indir_offset;
int maxname;
const int min_len = 1;
maxname=MAXDNAME;
np=(guchar *)wmem_alloc(wmem_packet_scope(), maxname);
*name=np;
maxname--;
for (;;) {
if (max_len && offset - start_offset > max_len - 1) {
break;
}
component_len = tvb_get_guint8(tvb, offset);
offset++;
if (component_len == 0) {
break;
}
chars_processed++;
switch (component_len & 0xc0) {
case 0x00:
if (np != *name) {
if (maxname > 0) {
*np++ = '.';
maxname--;
}
}
while (component_len > 0) {
if (max_len && offset - start_offset > max_len - 1) {
THROW(ReportedBoundsError);
}
if (maxname > 0) {
*np++ = tvb_get_guint8(tvb, offset);
maxname--;
}
component_len--;
offset++;
chars_processed++;
}
break;
case 0x40:
switch (component_len & 0x3f) {
case 0x01:
{
int bit_count;
int label_len;
int print_len;
bit_count = tvb_get_guint8(tvb, offset);
offset++;
label_len = (bit_count - 1) / 8 + 1;
if (maxname > 0) {
print_len = g_snprintf(np, maxname + 1, "\\[x");
if (print_len <= maxname) {
np += print_len;
maxname -= print_len;
} else {
maxname = 0;
}
}
while (label_len--) {
if (maxname > 0) {
print_len = g_snprintf(np, maxname + 1, "%02x",
tvb_get_guint8(tvb, offset));
if (print_len <= maxname) {
np += print_len;
maxname -= print_len;
} else {
maxname = 0;
}
}
offset++;
}
if (maxname > 0) {
print_len = g_snprintf(np, maxname + 1, "/%d]", bit_count);
if (print_len <= maxname) {
np += print_len;
maxname -= print_len;
} else {
maxname = 0;
}
}
}
break;
default:
*name="<Unknown extended label>";
len = offset - start_offset;
if (len < min_len) {
THROW(ReportedBoundsError);
}
return len;
}
break;
case 0x80:
THROW(ReportedBoundsError);
break;
case 0xc0:
indir_offset = dns_data_offset +
(((component_len & ~0xc0) << 8) | tvb_get_guint8(tvb, offset));
offset++;
chars_processed++;
if (len < 0) {
len = offset - start_offset;
}
if (chars_processed >= data_size) {
*name="<Name contains a pointer that loops>";
if (len < min_len) {
THROW(ReportedBoundsError);
}
return len;
}
offset = indir_offset;
break;
}
}
*np = '\0';
if (len < 0) {
len = offset - start_offset;
}
if (len < min_len) {
THROW(ReportedBoundsError);
}
return len;
}
int
get_dns_name(tvbuff_t *tvb, int offset, int max_len, int dns_data_offset,
const guchar **name)
{
int len;
len = expand_dns_name(tvb, offset, max_len, dns_data_offset, name);
if (**name == '\0') {
*name="<Root>";
}
return len;
}
static int
get_dns_name_type_class(tvbuff_t *tvb, int offset, int dns_data_offset,
const guchar **name_ret, int *name_len_ret, int *type_ret, int *class_ret)
{
int len;
int name_len;
int type;
int dns_class;
int start_offset = offset;
name_len = get_dns_name(tvb, offset, 0, dns_data_offset, name_ret);
offset += name_len;
type = tvb_get_ntohs(tvb, offset);
offset += 2;
dns_class = tvb_get_ntohs(tvb, offset);
offset += 2;
*type_ret = type;
*class_ret = dns_class;
*name_len_ret = name_len;
len = offset - start_offset;
return len;
}
static double
rfc1867_size(tvbuff_t *tvb, int offset)
{
guint8 val;
double size;
guint32 exponent;
val = tvb_get_guint8(tvb, offset);
size = (val & 0xF0) >> 4;
exponent = (val & 0x0F);
while (exponent != 0) {
size *= 10;
exponent--;
}
return size / 100;
}
static char *
rfc1867_angle(tvbuff_t *tvb, int offset, const char *nsew)
{
guint32 angle;
char direction;
guint32 degrees, minutes, secs, tsecs;
static char buf[10+1+3+1 + 2+1+3+1 + 2+1+3+1+3+1 + 1 + 1];
angle = tvb_get_ntohl(tvb, offset);
if (angle < 0x80000000U) {
angle = 0x80000000U - angle;
direction = nsew[1];
} else {
angle = angle - 0x80000000U;
direction = nsew[0];
}
tsecs = angle % 1000;
angle = angle / 1000;
secs = angle % 60;
angle = angle / 60;
minutes = angle % 60;
degrees = angle / 60;
g_snprintf(buf, sizeof(buf), "%u deg %u min %u.%03u sec %c", degrees, minutes, secs,
tsecs, direction);
return buf;
}
static int
dissect_dns_query(tvbuff_t *tvb, int offset, int dns_data_offset,
packet_info *pinfo, proto_tree *dns_tree, gboolean is_mdns)
{
int len;
const guchar *name;
gchar *name_out;
int name_len;
int type;
int dns_class;
int qu;
const char *type_name;
int data_start;
guint16 labels;
proto_tree *q_tree;
proto_item *tq;
data_start = offset;
len = get_dns_name_type_class(tvb, offset, dns_data_offset, &name, &name_len,
&type, &dns_class);
if (is_mdns) {
qu = dns_class & C_QU;
dns_class &= ~C_QU;
} else {
qu = 0;
}
type_name = val_to_str_ext(type, &dns_types_vals_ext, "Unknown (%d)");
name_out = format_text(name, strlen(name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s %s", type_name, name_out);
if (is_mdns) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", \"%s\" question", qu ? "QU" : "QM");
}
if (dns_tree != NULL) {
q_tree = proto_tree_add_subtree_format(dns_tree, tvb, offset, len, ett_dns_qd, &tq, "%s: type %s, class %s",
name_out, type_name, val_to_str_const(dns_class, dns_classes, "Unknown"));
if (is_mdns) {
proto_item_append_text(tq, ", \"%s\" question", qu ? "QU" : "QM");
}
proto_tree_add_string(q_tree, hf_dns_qry_name, tvb, offset, name_len, name);
tq = proto_tree_add_uint(q_tree, hf_dns_qry_name_len, tvb, offset, name_len, name_len > 1 ? (guint32)strlen(name) : 0);
PROTO_ITEM_SET_GENERATED(tq);
labels = qname_labels_count(name, name_len);
tq = proto_tree_add_uint(q_tree, hf_dns_count_labels, tvb, offset, name_len, labels);
PROTO_ITEM_SET_GENERATED(tq);
offset += name_len;
proto_tree_add_item(q_tree, hf_dns_qry_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (is_mdns) {
proto_tree_add_uint(q_tree, hf_dns_qry_class_mdns, tvb, offset, 2, dns_class);
proto_tree_add_boolean(q_tree, hf_dns_qry_qu, tvb, offset, 2, qu);
} else {
proto_tree_add_uint(q_tree, hf_dns_qry_class, tvb, offset, 2, dns_class);
}
offset += 2;
}
if (data_start + len != offset) {
}
return len;
}
static void
add_rr_to_tree(proto_tree *rr_tree, tvbuff_t *tvb, int offset,
const guchar *name, int namelen, int type,
packet_info *pinfo, gboolean is_mdns)
{
proto_item *ttl_item;
gchar **srv_rr_info;
if (type == T_SRV) {
srv_rr_info = g_strsplit(name, ".", 3);
proto_tree_add_string(rr_tree, hf_dns_srv_service, tvb, offset,
namelen, srv_rr_info[0]);
if (srv_rr_info[1]) {
proto_tree_add_string(rr_tree, hf_dns_srv_proto, tvb, offset,
namelen, srv_rr_info[1]);
if (srv_rr_info[2]) {
proto_tree_add_string(rr_tree, hf_dns_srv_name, tvb, offset,
namelen, srv_rr_info[2]);
}
}
g_strfreev(srv_rr_info);
} else {
proto_tree_add_string(rr_tree, hf_dns_rr_name, tvb, offset, namelen, name);
}
offset += namelen;
proto_tree_add_item(rr_tree, hf_dns_rr_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (is_mdns) {
proto_tree_add_item(rr_tree, hf_dns_rr_class_mdns, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rr_tree, hf_dns_rr_cache_flush, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(rr_tree, hf_dns_rr_class, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
ttl_item = proto_tree_add_item(rr_tree, hf_dns_rr_ttl, tvb, offset, 4, ENC_BIG_ENDIAN);
if (tvb_get_ntohl(tvb, offset) & 0x80000000) {
expert_add_info(pinfo, ttl_item, &ei_ttl_negative);
}
offset += 4;
proto_tree_add_item(rr_tree, hf_dns_rr_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static void
add_opt_rr_to_tree(proto_tree *rr_tree, tvbuff_t *tvb, int offset,
const char *name, int namelen, gboolean is_mdns)
{
proto_tree *Z_tree;
proto_item *Z_item;
proto_tree_add_string(rr_tree, hf_dns_rr_name, tvb, offset, namelen, name);
offset += namelen;
proto_tree_add_item(rr_tree, hf_dns_rr_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (is_mdns) {
proto_tree_add_item(rr_tree, hf_dns_rr_udp_payload_size_mdns, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rr_tree, hf_dns_rr_cache_flush, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(rr_tree, hf_dns_rr_udp_payload_size, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
proto_tree_add_item(rr_tree, hf_dns_rr_ext_rcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(rr_tree, hf_dns_rr_edns0_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
Z_item = proto_tree_add_item(rr_tree, hf_dns_rr_z, tvb, offset, 2, ENC_BIG_ENDIAN);
Z_tree = proto_item_add_subtree(Z_item, ett_dns_rr);
proto_tree_add_item(Z_tree, hf_dns_rr_z_do, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(Z_tree, hf_dns_rr_z_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(rr_tree, hf_dns_rr_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
static int
dissect_type_bitmap(proto_tree *rr_tree, tvbuff_t *tvb, int cur_offset, int rr_len)
{
int mask, blockbase, blocksize;
int i, initial_offset, rr_type;
guint8 bits;
initial_offset = cur_offset;
while (rr_len != 0) {
blockbase = tvb_get_guint8(tvb, cur_offset);
blocksize = tvb_get_guint8(tvb, cur_offset + 1);
cur_offset += 2;
rr_len -= 2;
rr_type = blockbase * 256;
for( ; blocksize; blocksize-- ) {
bits = tvb_get_guint8(tvb, cur_offset);
mask = 1<<7;
for (i = 0; i < 8; i++) {
if (bits & mask) {
proto_tree_add_uint_format(rr_tree, hf_dns_rr_type, tvb, cur_offset, 1, rr_type,
"RR type in bit map: %s",
val_to_str_ext(rr_type, &dns_types_description_vals_ext, "Unknown (%d)"));
}
mask >>= 1;
rr_type++;
}
cur_offset += 1;
rr_len -= 1;
}
}
return(initial_offset - cur_offset);
}
static int
dissect_type_bitmap_nxt(proto_tree *rr_tree, tvbuff_t *tvb, int cur_offset, int rr_len)
{
int mask;
int i, initial_offset, rr_type;
guint8 bits;
initial_offset = cur_offset;
rr_type = 0;
while (rr_len != 0) {
bits = tvb_get_guint8(tvb, cur_offset);
mask = 1<<7;
for (i = 0; i < 8; i++) {
if (bits & mask) {
proto_tree_add_uint_format(rr_tree, hf_dns_rr_type, tvb, cur_offset, 1, rr_type,
"RR type in bit map: %s",
val_to_str_ext(rr_type, &dns_types_description_vals_ext, "Unknown (%d)"));
}
mask >>= 1;
rr_type++;
}
cur_offset += 1;
rr_len -= 1;
}
return(initial_offset - cur_offset);
}
static guint16
compute_key_id(tvbuff_t *tvb, int offset, int size, guint8 algo)
{
guint32 ac;
guint8 c1, c2;
DISSECTOR_ASSERT(size >= 4);
switch( algo ) {
case DNS_ALGO_RSAMD5:
return (guint16)(tvb_get_guint8(tvb, offset + size - 3) << 8) + tvb_get_guint8( tvb, offset + size - 2 );
default:
for (ac = 0; size > 1; size -= 2, offset += 2) {
c1 = tvb_get_guint8( tvb, offset );
c2 = tvb_get_guint8( tvb, offset + 1 );
ac += (c1 << 8) + c2 ;
}
if (size > 0) {
c1 = tvb_get_guint8( tvb, offset );
ac += c1 << 8;
}
ac += (ac >> 16) & 0xffff;
return (guint16)(ac & 0xffff);
}
}
static int
dissect_dns_answer(tvbuff_t *tvb, int offsetx, int dns_data_offset,
proto_tree *dns_tree, packet_info *pinfo,
gboolean is_mdns)
{
int len;
const guchar *name;
gchar *name_out;
int name_len;
int dns_type;
int dns_class;
int flush;
const char *class_name;
const char *type_name;
int data_offset;
int cur_offset;
int data_start;
gushort data_len;
proto_tree *rr_tree = NULL;
proto_item *trr = NULL;
data_start = data_offset = offsetx;
cur_offset = offsetx;
len = get_dns_name_type_class(tvb, offsetx, dns_data_offset, &name, &name_len,
&dns_type, &dns_class);
data_offset += len;
cur_offset += len;
if (is_mdns) {
flush = dns_class & C_FLUSH;
dns_class &= ~C_FLUSH;
} else {
flush = 0;
}
type_name = val_to_str_ext(dns_type, &dns_types_vals_ext, "Unknown (%d)");
class_name = val_to_str_const(dns_class, dns_classes, "Unknown");
data_offset += 4;
cur_offset += 4;
data_len = tvb_get_ntohs(tvb, data_offset);
data_offset += 2;
cur_offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", type_name);
if (is_mdns && flush) {
col_append_str(pinfo->cinfo, COL_INFO, ", cache flush");
}
if (dns_tree != NULL) {
name_out = format_text(name, strlen(name));
if (dns_type != T_OPT) {
rr_tree = proto_tree_add_subtree_format(dns_tree, tvb, offsetx,
(data_offset - data_start) + data_len,
ett_dns_rr, &trr, "%s: type %s, class %s",
name_out, type_name, class_name);
add_rr_to_tree(rr_tree, tvb, offsetx, name, name_len,
dns_type, pinfo, is_mdns);
} else {
rr_tree = proto_tree_add_subtree_format(dns_tree, tvb, offsetx,
(data_offset - data_start) + data_len,
ett_dns_rr, &trr, "%s: type %s", name_out, type_name);
add_opt_rr_to_tree(rr_tree, tvb, offsetx, name, name_len, is_mdns);
}
if (is_mdns && flush) {
proto_item_append_text(trr, ", cache flush");
}
}
if (data_len == 0) {
return data_offset - data_start;
}
switch (dns_type) {
case T_A:
{
const char *addr;
addr = tvb_ip_to_str(tvb, cur_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", addr);
proto_item_append_text(trr, ", addr %s", addr);
proto_tree_add_item(rr_tree, hf_dns_a, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
if (gbl_resolv_flags.dns_pkt_addr_resolution && (dns_class & 0x7f) == C_IN) {
guint32 addr_int;
tvb_memcpy(tvb, &addr_int, cur_offset, sizeof(addr_int));
add_ipv4_name(addr_int, name);
}
}
break;
case T_NS:
{
const guchar *ns_name;
int ns_name_len;
ns_name_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &ns_name);
name_out = format_text(ns_name, strlen(ns_name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", ns %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_ns, tvb, cur_offset, ns_name_len, name_out);
}
break;
case T_MD:
{
int hostname_len;
const guchar *hostname_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hostname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &hostname_str);
proto_tree_add_string(rr_tree, hf_dns_md, tvb, cur_offset, hostname_len, hostname_str);
}
break;
case T_MF:
{
int hostname_len;
const guchar *hostname_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hostname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &hostname_str);
proto_tree_add_string(rr_tree, hf_dns_mf, tvb, cur_offset, hostname_len, hostname_str);
}
break;
case T_CNAME:
{
const guchar *cname;
int cname_len;
cname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &cname);
name_out = format_text(cname, strlen(cname));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", cname %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_cname, tvb, cur_offset, cname_len, name_out);
}
break;
case T_SOA:
{
const guchar *mname;
int mname_len;
const guchar *rname;
int rname_len;
proto_item *ti_soa;
mname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &mname);
name_out = format_text(mname, strlen(mname));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", mname %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_soa_mname, tvb, cur_offset, mname_len, name_out);
cur_offset += mname_len;
rname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &rname);
name_out = format_text(rname, strlen(rname));
proto_tree_add_string(rr_tree, hf_dns_soa_rname, tvb, cur_offset, rname_len, name_out);
cur_offset += rname_len;
proto_tree_add_item(rr_tree, hf_dns_soa_serial_number, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
ti_soa = proto_tree_add_item(rr_tree, hf_dns_soa_refresh_interval, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_soa, " (%s)", signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, cur_offset)));
cur_offset += 4;
ti_soa = proto_tree_add_item(rr_tree, hf_dns_soa_retry_interval, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_soa, " (%s)", signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, cur_offset)));
cur_offset += 4;
ti_soa = proto_tree_add_item(rr_tree, hf_dns_soa_expire_limit, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_soa, " (%s)", signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, cur_offset)));
cur_offset += 4;
ti_soa = proto_tree_add_item(rr_tree, hf_dns_soa_minimum_ttl, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti_soa, " (%s)", signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, cur_offset)));
}
break;
case T_MB:
{
int hostname_len;
const guchar *hostname_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hostname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &hostname_str);
proto_tree_add_string(rr_tree, hf_dns_mb, tvb, cur_offset, hostname_len, hostname_str);
}
break;
case T_MG:
{
int hostname_len;
const guchar *hostname_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hostname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &hostname_str);
proto_tree_add_string(rr_tree, hf_dns_mg, tvb, cur_offset, hostname_len, hostname_str);
}
break;
case T_MR:
{
int hostname_len;
const guchar *hostname_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hostname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &hostname_str);
proto_tree_add_string(rr_tree, hf_dns_mr, tvb, cur_offset, hostname_len, hostname_str);
}
break;
case T_NULL:
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_null, tvb, cur_offset, data_len, ENC_NA);
}
break;
case T_WKS:
{
int rr_len = data_len;
const char *wks_addr;
guint8 protocol;
guint8 bits;
int mask;
int port_num;
int i;
proto_item *ti_wks;
wmem_strbuf_t *bitnames = wmem_strbuf_new_label(wmem_packet_scope());
wks_addr = tvb_ip_to_str(tvb, cur_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", wks_addr);
proto_item_append_text(trr, ", addr %s", wks_addr);
proto_tree_add_item(rr_tree, hf_dns_wks_address, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_wks_protocol, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
protocol = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
rr_len -= 1;
port_num = 0;
while (rr_len != 0) {
bits = tvb_get_guint8(tvb, cur_offset);
if (bits != 0) {
mask = 1<<7;
wmem_strbuf_truncate(bitnames, 0);
for (i = 0; i < 8; i++) {
if (bits & mask) {
if (wmem_strbuf_get_len(bitnames) > 0) {
wmem_strbuf_append(bitnames, ", ");
}
switch (protocol) {
case IP_PROTO_TCP:
wmem_strbuf_append(bitnames, tcp_port_to_display(wmem_packet_scope(), port_num));
break;
case IP_PROTO_UDP:
wmem_strbuf_append(bitnames, udp_port_to_display(wmem_packet_scope(), port_num));
break;
default:
wmem_strbuf_append_printf(bitnames, "%u", port_num);
break;
}
}
mask >>= 1;
port_num++;
}
ti_wks = proto_tree_add_item(rr_tree, hf_dns_wks_bits, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti_wks, " (%s)", wmem_strbuf_get_str(bitnames));
} else {
port_num += 8;
}
cur_offset += 1;
rr_len -= 1;
}
}
break;
case T_PTR:
{
const guchar *pname;
int pname_len;
pname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &pname);
name_out = format_text(pname, strlen(pname));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_ptr_domain_name, tvb, cur_offset, pname_len, name_out);
}
break;
case T_HINFO:
{
int cpu_offset;
int cpu_len;
const char *cpu;
int os_offset;
int os_len;
const char *os;
cpu_offset = cur_offset;
cpu_len = tvb_get_guint8(tvb, cpu_offset);
cpu = tvb_get_string_enc(wmem_packet_scope(), tvb, cpu_offset + 1, cpu_len, ENC_ASCII|ENC_NA);
os_offset = cpu_offset + 1 + cpu_len;
os_len = tvb_get_guint8(tvb, os_offset);
os = tvb_get_string_enc(wmem_packet_scope(), tvb, os_offset + 1, os_len, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " %.*s %.*s", cpu_len, cpu, os_len, os);
proto_item_append_text(trr, ", CPU %.*s, OS %.*s", cpu_len, cpu, os_len, os);
proto_tree_add_item(rr_tree, hf_dns_hinfo_cpu_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_hinfo_cpu, tvb, cur_offset, cpu_len, ENC_ASCII|ENC_NA);
cur_offset += cpu_len;
proto_tree_add_item(rr_tree, hf_dns_hinfo_os_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_hinfo_os, tvb, cur_offset, os_len, ENC_ASCII|ENC_NA);
}
break;
case T_MINFO:
{
int rmailbx_len, emailbx_len;
const guchar *rmailbx_str, *emailbx_str;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
rmailbx_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &rmailbx_str);
proto_tree_add_string(rr_tree, hf_dns_minfo_r_mailbox, tvb, cur_offset, rmailbx_len, rmailbx_str);
cur_offset += rmailbx_len;
emailbx_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &emailbx_str);
proto_tree_add_string(rr_tree, hf_dns_minfo_e_mailbox, tvb, cur_offset, emailbx_len, emailbx_str);
}
break;
case T_MX:
{
guint16 preference = 0;
const guchar *mx_name;
int mx_name_len;
preference = tvb_get_ntohs(tvb, cur_offset);
mx_name_len = get_dns_name(tvb, cur_offset + 2, 0, dns_data_offset, &mx_name);
name_out = format_text(mx_name, strlen(mx_name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %u %s", preference, name_out);
proto_item_append_text(trr, ", preference %u, mx %s",
preference, name_out);
proto_tree_add_item(rr_tree, hf_dns_mx_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_string(rr_tree, hf_dns_mx_mail_exchange, tvb, cur_offset, mx_name_len, name_out);
}
break;
case T_TXT:
{
int rr_len = data_len;
int txt_offset;
int txt_len;
txt_offset = cur_offset;
while (rr_len != 0) {
txt_len = tvb_get_guint8(tvb, txt_offset);
proto_tree_add_item(rr_tree, hf_dns_txt_length, tvb, txt_offset, 1, ENC_BIG_ENDIAN);
txt_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_txt, tvb, txt_offset, txt_len, ENC_ASCII|ENC_NA);
txt_offset += txt_len;
rr_len -= txt_len;
}
}
break;
case T_RP:
{
int mbox_dname_len, txt_dname_len;
const guchar *mbox_dname, *txt_dname;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
mbox_dname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &mbox_dname);
proto_tree_add_string(rr_tree, hf_dns_rp_mailbox, tvb, cur_offset, mbox_dname_len, mbox_dname);
cur_offset += mbox_dname_len;
txt_dname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &txt_dname);
proto_tree_add_string(rr_tree, hf_dns_rp_txt_rr, tvb, cur_offset, txt_dname_len, txt_dname);
}
break;
case T_AFSDB:
{
const guchar *host_name;
int host_name_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
host_name_len = get_dns_name(tvb, cur_offset + 2, 0, dns_data_offset, &host_name);
proto_tree_add_item(rr_tree, hf_dns_afsdb_subtype, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_string(rr_tree, hf_dns_afsdb_hostname, tvb, cur_offset, host_name_len, host_name);
}
break;
case T_X25:
{
guint8 x25_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_x25_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
x25_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_x25_psdn_address, tvb, cur_offset, x25_len, ENC_ASCII|ENC_NA);
}
break;
case T_ISDN:
{
guint8 isdn_address_len, isdn_sa_len;
int rr_len = data_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_isdn_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
isdn_address_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_isdn_address, tvb, cur_offset, isdn_address_len, ENC_ASCII|ENC_NA);
cur_offset += isdn_address_len;
rr_len -= isdn_address_len;
if (rr_len > 1) {
proto_tree_add_item(rr_tree, hf_dns_isdn_sa_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
isdn_sa_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_isdn_sa, tvb, cur_offset, isdn_sa_len, ENC_ASCII|ENC_NA);
}
}
break;
case T_RT:
{
const guchar *host_name;
int host_name_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
host_name_len = get_dns_name(tvb, cur_offset + 2, 0, dns_data_offset, &host_name);
proto_tree_add_item(rr_tree, hf_dns_rt_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_string(rr_tree, hf_dns_rt_intermediate_host, tvb, cur_offset, host_name_len, host_name);
}
break;
case T_NSAP:
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_nsap_rdata, tvb, cur_offset, data_len, ENC_NA);
}
break;
case T_NSAP_PTR:
{
int nsap_ptr_owner_len;
const guchar *nsap_ptr_owner;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
nsap_ptr_owner_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &nsap_ptr_owner);
proto_tree_add_string(rr_tree, hf_dns_nsap_ptr_owner, tvb, cur_offset, nsap_ptr_owner_len, nsap_ptr_owner);
}
break;
case T_KEY:
{
int rr_len = data_len;
guint16 flags;
proto_item *tf, *ti_gen;
proto_tree *flags_tree;
guint8 algo;
guint16 key_id;
tf = proto_tree_add_item(rr_tree, hf_dns_key_flags, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(tf, ett_key_flags);
flags = tvb_get_ntohs(tvb, cur_offset);
proto_tree_add_item(flags_tree, hf_dns_key_flags_authentication, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_confidentiality, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
if ((flags & 0xC000) != 0xC000) {
proto_tree_add_item(flags_tree, hf_dns_key_flags_key_required, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_associated_user, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_associated_named_entity, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_ipsec, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_mime, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_key_flags_signatory, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
}
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_key_protocol, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_key_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
algo = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
rr_len -= 1;
key_id = compute_key_id(tvb, cur_offset-4, rr_len+4, algo);
ti_gen = proto_tree_add_uint(rr_tree, hf_dns_key_key_id, tvb, 0, 0, key_id);
PROTO_ITEM_SET_GENERATED(ti_gen);
if (rr_len != 0) {
proto_tree_add_item(rr_tree, hf_dns_key_public_key, tvb, cur_offset, rr_len, ENC_NA);
}
}
break;
case T_PX:
{
int px_map822_len, px_mapx400_len;
const guchar *px_map822_dnsname, *px_mapx400_dnsname;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_px_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
px_map822_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &px_map822_dnsname);
proto_tree_add_string(rr_tree, hf_dns_px_map822, tvb, cur_offset, px_map822_len, px_map822_dnsname);
cur_offset += px_map822_len;
px_mapx400_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &px_mapx400_dnsname);
proto_tree_add_string(rr_tree, hf_dns_px_mapx400, tvb, cur_offset, px_mapx400_len, px_mapx400_dnsname);
}
break;
case T_GPOS:
{
guint8 long_len, lat_len, alt_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_gpos_longitude_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
long_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_gpos_longitude, tvb, cur_offset, long_len, ENC_ASCII|ENC_NA);
cur_offset += long_len;
proto_tree_add_item(rr_tree, hf_dns_gpos_latitude_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
lat_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_gpos_latitude, tvb, cur_offset, lat_len, ENC_ASCII|ENC_NA);
cur_offset += lat_len;
proto_tree_add_item(rr_tree, hf_dns_gpos_altitude_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
alt_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_gpos_altitude, tvb, cur_offset, alt_len, ENC_ASCII|ENC_NA);
}
break;
case T_AAAA:
{
const char *addr6;
addr6 = tvb_ip6_to_str(tvb, cur_offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", addr6);
proto_item_append_text(trr, ", addr %s", addr6);
proto_tree_add_item(rr_tree, hf_dns_aaaa, tvb, cur_offset, 16, ENC_NA);
if (gbl_resolv_flags.dns_pkt_addr_resolution && (dns_class & 0x7f) == C_IN) {
struct e_in6_addr addr_in6;
tvb_memcpy(tvb, &addr_in6, cur_offset, sizeof(addr_in6));
add_ipv6_name(&addr_in6, name);
}
}
break;
case T_LOC:
{
guint8 version;
proto_item *ti;
version = tvb_get_guint8(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_dns_loc_version, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
if (version == 0) {
cur_offset++;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_size, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%g m)", rfc1867_size(tvb, cur_offset));
cur_offset++;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_horizontal_precision, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%g m)", rfc1867_size(tvb, cur_offset));
cur_offset++;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_vertical_precision, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%g m)", rfc1867_size(tvb, cur_offset));
cur_offset++;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_latitude, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", rfc1867_angle(tvb, cur_offset, "NS"));
cur_offset += 4;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_longitude, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", rfc1867_angle(tvb, cur_offset, "EW"));
cur_offset += 4;
ti = proto_tree_add_item(rr_tree, hf_dns_loc_altitude, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%g m)", ((gint32)tvb_get_ntohl(tvb, cur_offset) - 10000000)/100.0);
} else {
proto_tree_add_item(rr_tree, hf_dns_loc_unknown_data, tvb, cur_offset, data_len, ENC_NA);
}
}
break;
case T_NXT:
{
int rr_len = data_len;
const guchar *next_domain_name;
int next_domain_name_len;
next_domain_name_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset,
&next_domain_name);
name_out = format_text(next_domain_name, strlen(next_domain_name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", next domain name %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_nxt_next_domain_name, tvb, cur_offset, next_domain_name_len, name_out);
cur_offset += next_domain_name_len;
rr_len -= next_domain_name_len;
dissect_type_bitmap_nxt(rr_tree, tvb, cur_offset, rr_len);
}
break;
case T_SRV:
{
guint16 priority = 0;
guint16 weight = 0;
guint16 port = 0;
const guchar *target;
int target_len;
proto_tree_add_item(rr_tree, hf_dns_srv_priority, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
priority = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_srv_weight, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
weight = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_srv_port, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
port = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
target_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &target);
name_out = format_text(target, strlen(target));
proto_tree_add_string(rr_tree, hf_dns_srv_target, tvb, cur_offset, target_len, name_out);
col_append_fstr(pinfo->cinfo, COL_INFO, " %u %u %u %s", priority, weight, port, name_out);
proto_item_append_text(trr,
", priority %u, weight %u, port %u, target %s",
priority, weight, port, name_out);
}
break;
case T_NAPTR:
{
proto_item *ti_len;
int offset = cur_offset;
guint16 order;
guint16 preference;
gchar *flags;
guint8 flags_len;
guint8 service_len;
guint8 regex_len;
const guchar *replacement;
int replacement_len;
proto_tree_add_item(rr_tree, hf_dns_naptr_order, tvb, offset, 2, ENC_BIG_ENDIAN);
order = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(rr_tree, hf_dns_naptr_preference, tvb, offset, 2, ENC_BIG_ENDIAN);
preference = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(rr_tree, hf_dns_naptr_flags_length, tvb, offset, 1, ENC_BIG_ENDIAN);
flags_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(rr_tree, hf_dns_naptr_flags, tvb, offset, flags_len, ENC_ASCII|ENC_NA);
flags = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, flags_len, ENC_ASCII|ENC_NA);
offset += flags_len;
proto_tree_add_item(rr_tree, hf_dns_naptr_service_length, tvb, offset, 1, ENC_BIG_ENDIAN);
service_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(rr_tree, hf_dns_naptr_service, tvb, offset, service_len, ENC_ASCII|ENC_NA);
offset += service_len;
proto_tree_add_item(rr_tree, hf_dns_naptr_regex_length, tvb, offset, 1, ENC_BIG_ENDIAN);
regex_len = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(rr_tree, hf_dns_naptr_regex, tvb, offset, regex_len, ENC_ASCII|ENC_NA);
offset += regex_len;
replacement_len = get_dns_name(tvb, offset, 0, dns_data_offset, &replacement);
name_out = format_text(replacement, strlen(replacement));
ti_len = proto_tree_add_uint(rr_tree, hf_dns_naptr_replacement_length, tvb, offset, 0, replacement_len);
PROTO_ITEM_SET_GENERATED(ti_len);
proto_tree_add_string(rr_tree, hf_dns_naptr_replacement, tvb, offset, replacement_len, name_out);
col_append_fstr(pinfo->cinfo, COL_INFO, " %u %u %s", order, preference, flags);
proto_item_append_text(trr, ", order %u, preference %u, flags %s",
order, preference, flags);
}
break;
case T_KX:
{
const guchar *kx_name;
int kx_name_len;
kx_name_len = get_dns_name(tvb, cur_offset + 2, 0, dns_data_offset, &kx_name);
name_out = format_text(kx_name, strlen(kx_name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %u %s", tvb_get_ntohs(tvb, cur_offset), name_out);
proto_item_append_text(trr, ", preference %u, kx %s",
tvb_get_ntohs(tvb, cur_offset), name_out);
proto_tree_add_item(rr_tree, hf_dns_kx_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_string(rr_tree, hf_dns_kx_key_exchange, tvb, cur_offset + 2, kx_name_len, name_out);
}
break;
case T_CERT:
{
int rr_len = data_len;
proto_tree_add_item(rr_tree, hf_dns_cert_type, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_cert_key_tag, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_cert_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
if (rr_len != 0) {
proto_tree_add_item(rr_tree, hf_dns_cert_certificate, tvb, cur_offset, rr_len, ENC_NA);
}
}
break;
case T_A6:
{
unsigned short pre_len;
unsigned short suf_len;
unsigned short suf_octet_count;
const guchar *pname;
int pname_len;
int a6_offset;
int suf_offset;
struct e_in6_addr suffix;
address suffix_addr;
a6_offset = cur_offset;
pre_len = tvb_get_guint8(tvb, cur_offset);
cur_offset++;
suf_len = 128 - pre_len;
suf_octet_count = suf_len ? (suf_len - 1) / 8 + 1 : 0;
for (suf_offset = 0; suf_offset < 16 - suf_octet_count; suf_offset++) {
suffix.bytes[suf_offset] = 0;
}
for (; suf_offset < 16; suf_offset++) {
suffix.bytes[suf_offset] = tvb_get_guint8(tvb, cur_offset);
cur_offset++;
}
if (pre_len > 0) {
pname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset,
&pname);
} else {
pname="";
pname_len = 0;
}
name_out = format_text(pname, strlen(pname));
set_address(&suffix_addr, AT_IPv6, 16, suffix.bytes);
col_append_fstr(pinfo->cinfo, COL_INFO, " %d %s %s",
pre_len,
address_to_str(wmem_packet_scope(), &suffix_addr),
name_out);
proto_tree_add_item(rr_tree, hf_dns_a6_prefix_len,tvb, a6_offset, 1, ENC_BIG_ENDIAN);
a6_offset++;
if (suf_len) {
proto_tree_add_ipv6(rr_tree, hf_dns_a6_address_suffix,tvb, a6_offset, suf_octet_count, &suffix);
a6_offset += suf_octet_count;
}
if (pre_len > 0) {
proto_tree_add_string(rr_tree, hf_dns_a6_prefix_name, tvb, a6_offset, pname_len, name_out);
}
proto_item_append_text(trr, ", addr %d %s %s",
pre_len,
address_to_str(wmem_packet_scope(), &suffix_addr),
name_out);
}
break;
case T_DNAME:
{
const guchar *dname;
int dname_len;
dname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset,
&dname);
name_out = format_text(dname, strlen(dname));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", dname %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_dname, tvb, cur_offset, dname_len, name_out);
}
break;
case T_OPT:
{
int rropt_len = data_len;
guint16 optcode, optlen;
proto_item *rropt, *rroptlen;
proto_tree *rropt_tree;
while (rropt_len > 0) {
optcode = tvb_get_ntohs(tvb, cur_offset);
rropt_len -= 2;
optlen = tvb_get_ntohs(tvb, cur_offset + 2);
rropt_len -= 2;
rropt = proto_tree_add_item(rr_tree, hf_dns_opt, tvb, cur_offset, 4 + optlen, ENC_NA);
proto_item_append_text(rropt, ": %s", val_to_str(optcode, edns0_opt_code_vals, "Unknown (%d)"));
rropt_tree = proto_item_add_subtree(rropt, ett_dns_opts);
rropt = proto_tree_add_item(rropt_tree, hf_dns_opt_code, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rroptlen = proto_tree_add_item(rropt_tree, hf_dns_opt_len, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rropt_tree, hf_dns_opt_data, tvb, cur_offset, optlen, ENC_NA);
switch(optcode) {
case O_DAU:
while(optlen != 0 ) {
proto_tree_add_item(rropt_tree, hf_dns_opt_dau, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rropt_len -= 1;
optlen -= 1;
}
break;
case O_DHU:
while(optlen != 0 ) {
proto_tree_add_item(rropt_tree, hf_dns_opt_dhu, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rropt_len -= 1;
optlen -= 1;
}
break;
case O_N3U:
while(optlen != 0 ) {
proto_tree_add_item(rropt_tree, hf_dns_opt_n3u, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rropt_len -= 1;
optlen -= 1;
}
break;
case O_CLIENT_SUBNET_EXP:
expert_add_info_format(pinfo, rropt, &ei_dns_depr_opc,
"Deprecated opcode. Client subnet OPT assigned as %d.", O_CLIENT_SUBNET);
case O_CLIENT_SUBNET:{
guint16 family;
guint16 addr_len = optlen - 4;
union {
guint32 addr;
guint8 bytes[16];
} ip_addr = {0};
family = tvb_get_ntohs(tvb, cur_offset);
proto_tree_add_item(rropt_tree, hf_dns_opt_client_family, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rropt_tree, hf_dns_opt_client_netmask, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
proto_tree_add_item(rropt_tree, hf_dns_opt_client_scope, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
if (addr_len > 16) {
expert_add_info(pinfo, rroptlen, &ei_dns_opt_bad_length);
addr_len = 16;
}
tvb_memcpy(tvb, ip_addr.bytes, cur_offset, addr_len);
switch(family) {
case AFNUM_INET:
proto_tree_add_ipv4(rropt_tree, hf_dns_opt_client_addr4, tvb,
cur_offset, addr_len, ip_addr.addr);
break;
case AFNUM_INET6:
proto_tree_add_ipv6(rropt_tree, hf_dns_opt_client_addr6, tvb,
cur_offset, addr_len, (struct e_in6_addr *)&ip_addr);
break;
default:
proto_tree_add_item(rropt_tree, hf_dns_opt_client_addr, tvb, cur_offset, (optlen - 4),
ENC_NA);
break;
}
cur_offset += (optlen - 4);
rropt_len -= optlen;
}
break;
case O_COOKIE:
proto_tree_add_item(rropt_tree, hf_dns_opt_cookie_client, tvb, cur_offset, 8, ENC_NA);
cur_offset += 8;
rropt_len -= 8;
optlen -= 8;
proto_tree_add_item(rropt_tree, hf_dns_opt_cookie_server, tvb, cur_offset, optlen, ENC_NA);
cur_offset += optlen;
rropt_len -= optlen;
break;
case O_EDNS_TCP_KA:
if(optlen == 2){
proto_tree_add_item(rropt_tree, hf_dns_opt_edns_tcp_keepalive_timeout, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
}
cur_offset += optlen;
rropt_len -= optlen;
break;
case O_PADDING:
proto_tree_add_item(rropt_tree, hf_dns_opt_padding, tvb, cur_offset, optlen, ENC_NA);
cur_offset += optlen;
rropt_len -= optlen;
break;
case O_CHAIN:
if(optlen){
proto_tree_add_item(rropt_tree, hf_dns_opt_chain_fqdn, tvb, cur_offset, optlen, ENC_ASCII|ENC_NA);
}
cur_offset += optlen;
rropt_len -= optlen;
break;
default:
cur_offset += optlen;
rropt_len -= optlen;
break;
}
}
}
break;
case T_APL:
{
int rr_len = data_len;
guint16 afamily;
guint8 afdpart_len;
guint8 *addr_copy;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
while (rr_len > 1) {
afamily = tvb_get_ntohs(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_dns_apl_address_family, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_apl_coded_prefix, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
afdpart_len = tvb_get_guint8(tvb, cur_offset) & DNS_APL_AFDLENGTH;
proto_tree_add_item(rr_tree, hf_dns_apl_negation, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rr_tree, hf_dns_apl_afdlength, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
if (afamily == 1 && afdpart_len <= 4) {
addr_copy = (guint8 *)wmem_alloc0(wmem_file_scope(), 4);
tvb_memcpy(tvb, (guint8 *)addr_copy, cur_offset, afdpart_len);
proto_tree_add_ipv4(rr_tree, hf_dns_apl_afdpart_ipv4, tvb, cur_offset, afdpart_len, *addr_copy);
} else if (afamily == 2 && afdpart_len <= 16) {
addr_copy = (guint8 *)wmem_alloc0(wmem_file_scope(), 16);
tvb_memcpy(tvb, (guint8 *)addr_copy, cur_offset, afdpart_len);
proto_tree_add_ipv6(rr_tree, hf_dns_apl_afdpart_ipv6, tvb, cur_offset, afdpart_len, (struct e_in6_addr *)addr_copy);
} else {
proto_tree_add_item(rr_tree, hf_dns_apl_afdpart_data, tvb, cur_offset, afdpart_len, ENC_NA);
}
cur_offset += afdpart_len;
rr_len -= afdpart_len;
}
}
break;
case T_DS:
case T_CDS:
case T_DLV:
{
int rr_len = data_len;
proto_tree_add_item(rr_tree, hf_dns_ds_key_id, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_ds_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_ds_digest_type, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_ds_digest, tvb, cur_offset, rr_len, ENC_NA);
}
break;
case T_SSHFP:
{
int rr_len = data_len;
proto_tree_add_item(rr_tree, hf_dns_sshfp_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_sshfp_fingerprint_type, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
if (rr_len != 0) {
proto_tree_add_item(rr_tree, hf_dns_sshfp_fingerprint, tvb, cur_offset, rr_len, ENC_NA);
}
}
break;
case T_IPSECKEY:
{
int rr_len = data_len;
guint8 gw_type;
const guchar *gw;
int gw_name_len;
proto_tree_add_item(rr_tree, hf_dns_ipseckey_gateway_precedence, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_ipseckey_gateway_type, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
gw_type = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_ipseckey_gateway_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
switch( gw_type ) {
case 0:
break;
case 1:
proto_tree_add_item(rr_tree, hf_dns_ipseckey_gateway_ipv4, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
break;
case 2:
proto_tree_add_item(rr_tree, hf_dns_ipseckey_gateway_ipv6, tvb, cur_offset, 16, ENC_NA);
cur_offset += 16;
rr_len -= 16;
break;
case 3:
gw_name_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &gw);
proto_tree_add_string(rr_tree, hf_dns_ipseckey_gateway_dns, tvb, cur_offset, gw_name_len, gw);
cur_offset += gw_name_len;
rr_len -= gw_name_len;
break;
default:
break;
}
if (rr_len != 0) {
proto_tree_add_item(rr_tree, hf_dns_ipseckey_public_key, tvb, cur_offset, rr_len, ENC_NA);
}
}
break;
case T_RRSIG:
case T_SIG:
{
int rr_len = data_len;
const guchar *signer_name;
int signer_name_len;
proto_item *ti;
proto_tree_add_item(rr_tree, hf_dns_rrsig_type_covered, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_rrsig_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_rrsig_labels, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
ti = proto_tree_add_item(rr_tree, hf_dns_rrsig_original_ttl, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)", signed_time_secs_to_str(wmem_packet_scope(), tvb_get_ntohl(tvb, cur_offset)));
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_rrsig_signature_expiration, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_rrsig_signature_inception, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_rrsig_key_tag, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
signer_name_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &signer_name);
proto_tree_add_string(rr_tree, hf_dns_rrsig_signers_name, tvb, cur_offset, signer_name_len, signer_name);
cur_offset += signer_name_len;
rr_len -= signer_name_len;
if (rr_len != 0) {
proto_tree_add_item(rr_tree, hf_dns_rrsig_signature, tvb, cur_offset, rr_len, ENC_NA);
}
}
break;
case T_NSEC:
{
int rr_len = data_len;
const guchar *next_domain_name;
int next_domain_name_len;
next_domain_name_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset,
&next_domain_name);
name_out = format_text(next_domain_name, strlen(next_domain_name));
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", next domain name %s", name_out);
proto_tree_add_string(rr_tree, hf_dns_nsec_next_domain_name, tvb, cur_offset, next_domain_name_len, name_out);
cur_offset += next_domain_name_len;
rr_len -= next_domain_name_len;
dissect_type_bitmap(rr_tree, tvb, cur_offset, rr_len);
}
break;
case T_DNSKEY:
case T_CDNSKEY:
{
int rr_len = data_len;
proto_item *tf, *ti_gen;
proto_tree *flags_tree;
guint16 key_id;
guint8 algo;
tf = proto_tree_add_item(rr_tree, hf_dns_dnskey_flags, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(tf, ett_key_flags);
proto_tree_add_item(flags_tree, hf_dns_dnskey_flags_zone_key, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_dnskey_flags_key_revoked, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_dnskey_flags_secure_entry_point, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(flags_tree, hf_dns_dnskey_flags_reserved, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(flags_tree, hf_dns_dnskey_protocol, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(flags_tree, hf_dns_dnskey_algorithm, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
algo = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
rr_len -= 1;
key_id = compute_key_id(tvb, cur_offset-4, rr_len+4, algo);
ti_gen = proto_tree_add_uint(rr_tree, hf_dns_dnskey_key_id, tvb, 0, 0, key_id);
PROTO_ITEM_SET_GENERATED(ti_gen);
proto_tree_add_item(rr_tree, hf_dns_dnskey_public_key, tvb, cur_offset, rr_len, ENC_NA);
}
break;
case T_DHCID:
{
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_dhcid_rdata, tvb, cur_offset, data_len, ENC_NA);
}
break;
case T_NSEC3:
{
int rr_len, initial_offset = cur_offset;
guint8 salt_len, hash_len;
proto_item *flags_item;
proto_tree *flags_tree;
proto_tree_add_item(rr_tree, hf_dns_nsec3_algo, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
flags_item = proto_tree_add_item(rr_tree, hf_dns_nsec3_flags, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
flags_tree = proto_item_add_subtree(flags_item, ett_nsec3_flags);
proto_tree_add_item(flags_tree, hf_dns_nsec3_flag_optout, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_iterations, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_nsec3_salt_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
salt_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_salt_value, tvb, cur_offset, salt_len, ENC_NA);
cur_offset += salt_len;
proto_tree_add_item(rr_tree, hf_dns_nsec3_hash_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
hash_len = tvb_get_guint8(tvb, cur_offset);
cur_offset += 1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_hash_value, tvb, cur_offset, hash_len, ENC_NA);
cur_offset += hash_len;
rr_len = data_len - (cur_offset - initial_offset);
dissect_type_bitmap(rr_tree, tvb, cur_offset, rr_len);
}
break;
case T_NSEC3PARAM:
{
int salt_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_nsec3_algo, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset +=1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_flags, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset +=1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_iterations, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_nsec3_salt_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
salt_len = tvb_get_guint8(tvb, cur_offset);
cur_offset +=1;
proto_tree_add_item(rr_tree, hf_dns_nsec3_salt_value, tvb, cur_offset, salt_len, ENC_NA);
}
break;
case T_TLSA:
{
int rr_len = data_len;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
proto_tree_add_item(rr_tree, hf_dns_tlsa_certificate_usage, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset ++;
rr_len --;
proto_tree_add_item(rr_tree, hf_dns_tlsa_selector, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset ++;
rr_len --;
proto_tree_add_item(rr_tree, hf_dns_tlsa_matching_type, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset ++;
rr_len --;
proto_tree_add_item(rr_tree, hf_dns_tlsa_certificate_association_data, tvb, cur_offset, rr_len, ENC_NA);
}
break;
case T_HIP:
{
guint8 hit_len;
guint16 pk_len;
int rr_len = data_len;
int rendezvous_len;
const guchar *rend_server_dns_name;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name);
hit_len = tvb_get_guint8(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_dns_hip_hit_length, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_hip_pk_algo, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
rr_len -= 1;
pk_len = tvb_get_ntohs(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_dns_hip_pk_length, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
rr_len -= 2;
proto_tree_add_item(rr_tree, hf_dns_hip_hit, tvb, cur_offset, hit_len, ENC_NA);
cur_offset += hit_len;
rr_len -= hit_len;
proto_tree_add_item(rr_tree, hf_dns_hip_pk, tvb, cur_offset, pk_len, ENC_NA);
cur_offset += pk_len;
rr_len -= pk_len;
while (rr_len > 1) {
rendezvous_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &rend_server_dns_name);
proto_tree_add_string(rr_tree, hf_dns_hip_rendezvous_server, tvb, cur_offset, rendezvous_len, rend_server_dns_name);
cur_offset += rendezvous_len;
rr_len -= rendezvous_len;
}
}
break;
case T_OPENPGPKEY:
{
proto_tree_add_item(rr_tree, hf_dns_openpgpkey, tvb, cur_offset, data_len, ENC_ASCII|ENC_NA);
}
break;
case T_CSYNC:
{
int rr_len, initial_offset = cur_offset;
proto_tree_add_item(rr_tree, hf_dns_csync_soa, tvb, cur_offset, 4, ENC_ASCII|ENC_NA);
cur_offset += 4;
proto_tree_add_bitmask_with_flags(rr_tree, tvb, cur_offset,
hf_dns_csync_flags, ett_dns_csdync_flags, dns_csync_flags, ENC_BIG_ENDIAN, BMT_NO_APPEND);
cur_offset += 2;
rr_len = data_len - (cur_offset - initial_offset);
proto_tree_add_item(rr_tree, hf_dns_csync_type_bitmap, tvb, cur_offset, rr_len, ENC_NA);
dissect_type_bitmap(rr_tree, tvb, cur_offset, rr_len);
}
break;
case T_SPF:
{
int rr_len = data_len;
int spf_offset;
int spf_len;
spf_offset = cur_offset;
while (rr_len != 0) {
spf_len = tvb_get_guint8(tvb, spf_offset);
proto_tree_add_item(rr_tree, hf_dns_spf_length, tvb, spf_offset, 1, ENC_BIG_ENDIAN);
spf_offset += 1;
rr_len -= 1;
proto_tree_add_item(rr_tree, hf_dns_spf, tvb, spf_offset, spf_len, ENC_ASCII|ENC_NA);
spf_offset += spf_len;
rr_len -= spf_len;
}
}
break;
case T_NID:
{
proto_tree_add_item(rr_tree, hf_dns_ilnp_nodeid_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_ilnp_nodeid, tvb, cur_offset, 8, ENC_NA);
}
break;
case T_L32:
{
proto_tree_add_item(rr_tree, hf_dns_ilnp_locator32_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_ilnp_locator32, tvb, cur_offset, 4, ENC_NA);
}
break;
case T_L64:
{
proto_tree_add_item(rr_tree, hf_dns_ilnp_locator64_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_ilnp_locator64, tvb, cur_offset, 8, ENC_NA);
}
break;
case T_LP:
{
int lp_len;
const guchar *lp_str;
proto_tree_add_item(rr_tree, hf_dns_ilnp_locatorfqdn_preference, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
lp_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &lp_str);
proto_tree_add_string(rr_tree, hf_dns_ilnp_locatorfqdn, tvb, cur_offset, lp_len, lp_str);
}
break;
case T_EUI48:
{
proto_tree_add_item(rr_tree, hf_dns_eui48, tvb, cur_offset, 6, ENC_NA);
}
break;
case T_EUI64:
{
proto_tree_add_item(rr_tree, hf_dns_eui64, tvb, cur_offset, 8, ENC_NA);
}
break;
case T_TKEY:
{
const guchar *tkey_algname;
int tkey_algname_len;
guint16 tkey_mode, tkey_keylen, tkey_otherlen;
proto_tree *key_tree;
proto_item *key_item;
tkey_algname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &tkey_algname);
proto_tree_add_string(rr_tree, hf_dns_tkey_algo_name, tvb, cur_offset, tkey_algname_len, tkey_algname);
cur_offset += tkey_algname_len;
proto_tree_add_item(rr_tree, hf_dns_tkey_signature_inception, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
proto_tree_add_item(rr_tree, hf_dns_tkey_signature_expiration, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
proto_tree_add_item(rr_tree, hf_dns_tkey_mode, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
tkey_mode = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_tkey_error, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_tkey_key_size, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
tkey_keylen = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
if (tkey_keylen != 0) {
key_item = proto_tree_add_item(rr_tree, hf_dns_tkey_key_data, tvb, cur_offset, tkey_keylen, ENC_NA);
key_tree = proto_item_add_subtree(key_item, ett_t_key);
switch(tkey_mode) {
case TKEYMODE_GSSAPI: {
tvbuff_t *gssapi_tvb;
gssapi_tvb = tvb_new_subset_length(
tvb, cur_offset, tkey_keylen);
if (tvb_strneql(gssapi_tvb, 0, "NTLMSSP", 7) == 0) {
call_dissector(ntlmssp_handle, gssapi_tvb, pinfo, key_tree);
} else {
call_dissector(gssapi_handle, gssapi_tvb, pinfo, key_tree);
}
break;
}
default:
break;
}
cur_offset += tkey_keylen;
}
proto_tree_add_item(rr_tree, hf_dns_tkey_other_size, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
tkey_otherlen = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
if (tkey_otherlen != 0) {
proto_tree_add_item(rr_tree, hf_dns_tkey_other_data, tvb, cur_offset, tkey_otherlen, ENC_NA);
}
}
break;
case T_TSIG:
{
guint16 tsig_siglen, tsig_otherlen;
const guchar *tsig_algname;
int tsig_algname_len;
proto_item *ti;
tsig_algname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &tsig_algname);
proto_tree_add_string(rr_tree, hf_dns_tsig_algorithm_name, tvb, cur_offset, tsig_algname_len, tsig_algname);
cur_offset += tsig_algname_len;
ti = proto_tree_add_item(rr_tree, hf_dns_tsig_time_signed ,tvb, cur_offset, 6, ENC_NA);
if(tvb_get_ntohs(tvb, cur_offset))
{
proto_item_append_text(ti, " (high bits set)");
}
cur_offset += 6;
proto_tree_add_item(rr_tree, hf_dns_tsig_fudge, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
tsig_siglen = tvb_get_ntohs(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_dns_tsig_mac_size, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
if (tsig_siglen != 0) {
proto_item *mac_item;
proto_tree *mac_tree;
tvbuff_t *sub_tvb;
mac_item = proto_tree_add_item(rr_tree, hf_dns_tsig_mac, tvb, cur_offset, tsig_siglen, ENC_NA);
mac_tree = proto_item_add_subtree(mac_item, ett_dns_mac);
sub_tvb=tvb_new_subset_length(tvb, cur_offset, tsig_siglen);
if (!dissector_try_string(dns_tsig_dissector_table, tsig_algname, sub_tvb, pinfo, mac_tree, NULL)) {
expert_add_info_format(pinfo, mac_item, &ei_dns_tsig_alg,
"No dissector for algorithm:%s", tsig_algname);
}
cur_offset += tsig_siglen;
}
proto_tree_add_item(rr_tree, hf_dns_tsig_original_id, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_tsig_error, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
proto_tree_add_item(rr_tree, hf_dns_tsig_other_len, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
tsig_otherlen = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
if (tsig_otherlen != 0) {
proto_tree_add_item(rr_tree, hf_dns_tsig_other_data, tvb, cur_offset, tsig_otherlen, ENC_NA);
}
}
break;
case T_CAA:
{
proto_item *caa_item;
proto_tree *caa_tree;
guint8 tag_len;
const char *tag;
gushort value_len;
const guchar *value;
int cur_hf = -1;
caa_item = proto_tree_add_item(rr_tree, hf_dns_caa_flags, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
caa_tree = proto_item_add_subtree(caa_item, ett_caa_flags);
proto_tree_add_item(caa_tree, hf_dns_caa_flag_issuer_critical, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset++;
tag_len = tvb_get_guint8(tvb, cur_offset);
tag = tvb_get_string_enc(wmem_packet_scope(), tvb, cur_offset + 1, tag_len, ENC_ASCII|ENC_NA);
value_len = data_len - (tag_len + 2);
value = tvb_get_string_enc(wmem_packet_scope(), tvb, cur_offset + 1 + tag_len, value_len, ENC_ASCII|ENC_NA);
value = format_text(value, value_len);
if (strncmp(tag, "issue", tag_len) == 0) {
cur_hf = hf_dns_caa_issue;
} else if (strncmp(tag, "issuewild", tag_len) == 0) {
cur_hf = hf_dns_caa_issuewild;
} else if (strncmp(tag, "iodef", tag_len) == 0) {
cur_hf = hf_dns_caa_iodef;
} else {
cur_hf = hf_dns_caa_unknown;
}
caa_item = proto_tree_add_string(rr_tree, cur_hf, tvb, cur_offset, 1 + tag_len + value_len, value);
caa_tree = proto_item_add_subtree(caa_item, ett_caa_data);
proto_tree_add_uint(caa_tree, hf_dns_caa_tag_length, tvb, cur_offset, 1, tag_len);
proto_tree_add_string(caa_tree, hf_dns_caa_tag, tvb, cur_offset + 1, tag_len, tag);
proto_tree_add_string(caa_tree, hf_dns_caa_value, tvb, cur_offset + 1 + tag_len, value_len, value);
}
break;
case T_WINS:
{
int rr_len = data_len;
guint32 nservers;
proto_tree_add_item(rr_tree, hf_dns_wins_local_flag, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_wins_lookup_timeout, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_wins_cache_timeout, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
rr_len -= 4;
proto_tree_add_item(rr_tree, hf_dns_wins_nb_wins_servers, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
nservers = tvb_get_ntohl(tvb, cur_offset);
cur_offset += 4;
rr_len -= 4;
while (rr_len != 0 && nservers != 0) {
proto_tree_add_item(rr_tree, hf_dns_wins_server, tvb, cur_offset, 4, ENC_NA);
cur_offset += 4;
rr_len -= 4;
nservers--;
}
}
break;
case T_WINS_R:
{
const guchar *dname;
int dname_len;
proto_tree_add_item(rr_tree, hf_dns_winsr_local_flag, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
proto_tree_add_item(rr_tree, hf_dns_winsr_lookup_timeout, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
proto_tree_add_item(rr_tree, hf_dns_winsr_cache_timeout, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
dname_len = get_dns_name(tvb, cur_offset, 0, dns_data_offset, &dname);
name_out = format_text(dname, strlen(dname));
proto_tree_add_string(rr_tree, hf_dns_winsr_name_result_domain, tvb, cur_offset, dname_len, name_out);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", name_out);
proto_item_append_text(trr, ", name result domain %s", name_out);
}
break;
default:
expert_add_info_format(pinfo, trr, &ei_dns_undecoded_option,
"Dissector for DNS Type (%d)"
" code not implemented, Contact Wireshark developers"
" if you want this supported", dns_type);
proto_tree_add_item(rr_tree, hf_dns_data, tvb, cur_offset, data_len, ENC_NA);
break;
}
data_offset += data_len;
return data_offset - data_start;
}
static int
dissect_query_records(tvbuff_t *tvb, int cur_off, int dns_data_offset,
int count, packet_info *pinfo, proto_tree *dns_tree, gboolean isupdate,
gboolean is_mdns)
{
int start_off, add_off;
proto_tree *qatree;
proto_item *ti;
const char *s = (isupdate ? "Zone" : "Queries");
start_off = cur_off;
qatree = proto_tree_add_subtree(dns_tree, tvb, start_off, -1, ett_dns_qry, &ti, s);
while (count-- > 0) {
add_off = dissect_dns_query(tvb, cur_off, dns_data_offset, pinfo, qatree,
is_mdns);
cur_off += add_off;
}
if (ti) {
proto_item_set_len(ti, cur_off - start_off);
}
return cur_off - start_off;
}
static int
dissect_answer_records(tvbuff_t *tvb, int cur_off, int dns_data_offset,
int count, proto_tree *dns_tree, const char *name,
packet_info *pinfo, gboolean is_mdns)
{
int start_off, add_off;
proto_tree *qatree = NULL;
proto_item *ti = NULL;
start_off = cur_off;
if (dns_tree) {
qatree = proto_tree_add_subtree(dns_tree, tvb, start_off, -1, ett_dns_ans, &ti, name);
}
while (count-- > 0) {
add_off = dissect_dns_answer(
tvb, cur_off, dns_data_offset, qatree, pinfo, is_mdns);
cur_off += add_off;
}
if (ti) {
proto_item_set_len(ti, cur_off - start_off);
}
return cur_off - start_off;
}
static void
dissect_dns_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_tcp, gboolean is_mdns, gboolean is_llmnr)
{
int offset = is_tcp ? 2 : 0;
int dns_data_offset;
proto_tree *dns_tree = NULL, *field_tree;
proto_item *ti, *tf;
guint16 flags, opcode, rcode, quest, ans, auth, add;
guint id;
int cur_off;
gboolean isupdate;
conversation_t *conversation;
dns_conv_info_t *dns_info;
dns_transaction_t *dns_trans;
wmem_tree_key_t key[3];
struct DnsTap *dns_stats;
guint qtype = 0;
guint qclass = 0;
const guchar *name;
int name_len;
dns_data_offset = offset;
col_clear(pinfo->cinfo, COL_INFO);
id = tvb_get_ntohs(tvb, offset + DNS_ID);
flags = tvb_get_ntohs(tvb, offset + DNS_FLAGS);
opcode = (guint16) ((flags & F_OPCODE) >> OPCODE_SHIFT);
rcode = (guint16) (flags & F_RCODE);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s%s 0x%04x",
val_to_str(opcode, opcode_vals, "Unknown operation (%u)"),
(flags&F_RESPONSE)?" response":"", id);
if (flags & F_RESPONSE) {
if (rcode != RCODE_NOERROR) {
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str(rcode, rcode_vals, "Unknown error (%u)"));
}
}
if (opcode == OPCODE_UPDATE) {
isupdate = TRUE;
} else {
isupdate = FALSE;
}
if (tree) {
if (is_llmnr) {
ti = proto_tree_add_protocol_format(tree, proto_llmnr, tvb, 0, -1,
"Link-local Multicast Name Resolution (%s)", (flags & F_RESPONSE) ? "response" : "query");
} else if (is_mdns){
ti = proto_tree_add_protocol_format(tree, proto_mdns, tvb, 0, -1,
"Multicast Domain Name System (%s)", (flags & F_RESPONSE) ? "response" : "query");
} else {
ti = proto_tree_add_protocol_format(tree, proto_dns, tvb, 0, -1,
"Domain Name System (%s)", (flags & F_RESPONSE) ? "response" : "query");
}
dns_tree = proto_item_add_subtree(ti, ett_dns);
}
conversation = find_or_create_conversation(pinfo);
dns_info = (dns_conv_info_t *)conversation_get_proto_data(conversation, proto_dns);
if (!dns_info) {
dns_info = wmem_new(wmem_file_scope(), dns_conv_info_t);
dns_info->pdus=wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_dns, dns_info);
}
key[0].length = 1;
key[0].key = &id;
key[1].length = 1;
key[1].key = &pinfo->num;
key[2].length = 0;
key[2].key = NULL;
if (!pinfo->fd->flags.visited) {
if (!(flags&F_RESPONSE)) {
dns_trans=wmem_new(wmem_file_scope(), dns_transaction_t);
dns_trans->req_frame=pinfo->num;
dns_trans->rep_frame=0;
dns_trans->req_time=pinfo->abs_ts;
dns_trans->id = id;
wmem_tree_insert32_array(dns_info->pdus, key, (void *)dns_trans);
} else {
dns_trans=(dns_transaction_t *)wmem_tree_lookup32_array_le(dns_info->pdus, key);
if (dns_trans) {
if (dns_trans->id != id) {
dns_trans = NULL;
} else {
dns_trans->rep_frame=pinfo->num;
}
}
}
} else {
dns_trans=(dns_transaction_t *)wmem_tree_lookup32_array_le(dns_info->pdus, key);
if (dns_trans && dns_trans->id != id) {
dns_trans = NULL;
}
}
if (!dns_trans) {
dns_trans=wmem_new(wmem_packet_scope(), dns_transaction_t);
dns_trans->req_frame=0;
dns_trans->rep_frame=0;
dns_trans->req_time=pinfo->abs_ts;
}
if (!(flags&F_RESPONSE)) {
if (dns_trans->rep_frame) {
proto_item *it;
it=proto_tree_add_uint(dns_tree, hf_dns_response_in, tvb, 0, 0, dns_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
} else {
if (dns_trans->req_frame) {
proto_item *it;
nstime_t ns;
it=proto_tree_add_uint(dns_tree, hf_dns_response_to, tvb, 0, 0, dns_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
nstime_delta(&ns, &pinfo->abs_ts, &dns_trans->req_time);
it=proto_tree_add_time(dns_tree, hf_dns_time, tvb, 0, 0, &ns);
PROTO_ITEM_SET_GENERATED(it);
}
}
if (is_tcp) {
proto_tree_add_item(dns_tree, hf_dns_length, tvb, offset - 2, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_uint(dns_tree, hf_dns_transaction_id, tvb,
offset + DNS_ID, 2, id);
tf = proto_tree_add_item(dns_tree, hf_dns_flags, tvb,
offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
proto_item_append_text(tf, " %s",
val_to_str_const(opcode, opcode_vals, "Unknown operation"));
if (flags & F_RESPONSE) {
proto_item_append_text(tf, " response, %s",
val_to_str_const(rcode, rcode_vals, "Unknown error"));
}
field_tree = proto_item_add_subtree(tf, ett_dns_flags);
proto_tree_add_item(field_tree, hf_dns_flags_response,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_dns_flags_opcode,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
if (is_llmnr) {
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_conflict_response,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(field_tree, hf_dns_flags_conflict_query,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(field_tree, hf_dns_flags_truncated,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_dns_flags_tentative,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_rcode,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
} else {
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_authoritative,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(field_tree, hf_dns_flags_truncated,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_dns_flags_recdesired,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_recavail,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(field_tree, hf_dns_flags_z,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_authenticated,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
} else if (flags & F_AUTHENTIC) {
proto_tree_add_item(field_tree, hf_dns_flags_ad,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(field_tree, hf_dns_flags_checkdisable,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
if (flags & F_RESPONSE) {
proto_tree_add_item(field_tree, hf_dns_flags_rcode,
tvb, offset + DNS_FLAGS, 2, ENC_BIG_ENDIAN);
}
}
quest = tvb_get_ntohs(tvb, offset + DNS_QUEST);
if (tree) {
if (isupdate) {
proto_tree_add_uint(dns_tree, hf_dns_count_zones, tvb,
offset + DNS_QUEST, 2, quest);
} else {
proto_tree_add_uint(dns_tree, hf_dns_count_questions, tvb,
offset + DNS_QUEST, 2, quest);
}
}
ans = tvb_get_ntohs(tvb, offset + DNS_ANS);
if (tree) {
if (isupdate) {
proto_tree_add_uint(dns_tree, hf_dns_count_prerequisites, tvb,
offset + DNS_ANS, 2, ans);
} else {
proto_tree_add_uint(dns_tree, hf_dns_count_answers, tvb,
offset + DNS_ANS, 2, ans);
}
}
auth = tvb_get_ntohs(tvb, offset + DNS_AUTH);
if (tree) {
if (isupdate) {
proto_tree_add_uint(dns_tree, hf_dns_count_updates, tvb,
offset + DNS_AUTH, 2, auth);
} else {
proto_tree_add_uint(dns_tree, hf_dns_count_auth_rr, tvb,
offset + DNS_AUTH, 2, auth);
}
}
add = tvb_get_ntohs(tvb, offset + DNS_ADD);
if (tree) {
proto_tree_add_uint(dns_tree, hf_dns_count_add_rr, tvb,
offset + DNS_ADD, 2, add);
}
cur_off = offset + DNS_HDRLEN;
dns_stats = wmem_new0(wmem_packet_scope(), struct DnsTap);
dns_stats->packet_rcode = rcode;
dns_stats->packet_opcode = opcode;
dns_stats->packet_qr = flags >> 15;
if (quest > 0) {
get_dns_name_type_class(tvb, cur_off, dns_data_offset, &name, &name_len, &qtype, &qclass);
dns_stats->packet_qtype = qtype;
dns_stats->packet_qclass = qclass;
}
dns_stats->payload_size = tvb_captured_length(tvb);
dns_stats->nquestions = quest;
dns_stats->nanswers = ans;
dns_stats->nauthorities = auth;
dns_stats->nadditionals = add;
if (quest > 0) {
cur_off += dissect_query_records(tvb, cur_off, dns_data_offset, quest, pinfo,
dns_tree, isupdate, is_mdns);
dns_stats->qname_len = name_len;
dns_stats->qname_labels = qname_labels_count(name, name_len);
}
if (ans > 0) {
cur_off += dissect_answer_records(tvb, cur_off, dns_data_offset, ans,
dns_tree,
(isupdate ? "Prerequisites" : "Answers"),
pinfo, is_mdns);
}
if (auth > 0) {
cur_off += dissect_answer_records(tvb, cur_off, dns_data_offset, auth, dns_tree,
(isupdate ? "Updates" :
"Authoritative nameservers"),
pinfo, is_mdns);
}
if (add > 0) {
dissect_answer_records(tvb, cur_off, dns_data_offset, add, dns_tree, "Additional records",
pinfo, is_mdns);
}
tap_queue_packet(dns_tap, pinfo, dns_stats);
}
static int
dissect_dns_udp_sctp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DNS");
dissect_dns_common(tvb, pinfo, tree, FALSE, FALSE, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_mdns_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MDNS");
dissect_dns_common(tvb, pinfo, tree, FALSE, TRUE, FALSE);
return tvb_captured_length(tvb);
}
static int
dissect_llmnr_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLMNR");
dissect_dns_common(tvb, pinfo, tree, FALSE, FALSE, TRUE);
return tvb_captured_length(tvb);
}
static guint
get_dns_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset);
return plen + 2;
}
static int
dissect_dns_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DNS");
dissect_dns_common(tvb, pinfo, tree, TRUE, FALSE, FALSE);
return tvb_reported_length(tvb);
}
static int
dissect_dns_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
tcp_dissect_pdus(tvb, pinfo, tree, dns_desegment, 2, get_dns_pdu_len,
dissect_dns_tcp_pdu, data);
return tvb_reported_length(tvb);
}
static int
dissect_dns(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
if (pinfo->ptype == PT_TCP) {
return dissect_dns_tcp(tvb, pinfo, tree, data);
} else {
dissect_dns_udp_sctp(tvb, pinfo, tree, data);
return tvb_captured_length(tvb);
}
}
static void dns_stats_tree_init(stats_tree* st)
{
st_node_packets = stats_tree_create_node(st, st_str_packets, 0, TRUE);
st_node_packet_qr = stats_tree_create_pivot(st, st_str_packet_qr, st_node_packets);
st_node_packet_qtypes = stats_tree_create_pivot(st, st_str_packet_qtypes, st_node_packets);
st_node_packet_qclasses = stats_tree_create_pivot(st, st_str_packet_qclasses, st_node_packets);
st_node_packet_rcodes = stats_tree_create_pivot(st, st_str_packet_rcodes, st_node_packets);
st_node_packet_opcodes = stats_tree_create_pivot(st, st_str_packet_opcodes, st_node_packets);
st_node_packets_avg_size = stats_tree_create_node(st, st_str_packets_avg_size, 0, FALSE);
st_node_query_stats = stats_tree_create_node(st, st_str_query_stats, 0, TRUE);
st_node_query_qname_len = stats_tree_create_node(st, st_str_query_qname_len, st_node_query_stats, FALSE);
st_node_query_domains = stats_tree_create_node(st, st_str_query_domains, st_node_query_stats, TRUE);
st_node_query_domains_l1 = stats_tree_create_node(st, st_str_query_domains_l1, st_node_query_domains, FALSE);
st_node_query_domains_l2 = stats_tree_create_node(st, st_str_query_domains_l2, st_node_query_domains, FALSE);
st_node_query_domains_l3 = stats_tree_create_node(st, st_str_query_domains_l3, st_node_query_domains, FALSE);
st_node_query_domains_lmore = stats_tree_create_node(st, st_str_query_domains_lmore, st_node_query_domains, FALSE);
st_node_response_stats = stats_tree_create_node(st, st_str_response_stats, 0, TRUE);
st_node_response_nquestions = stats_tree_create_node(st, st_str_response_nquestions,
st_node_response_stats, FALSE);
st_node_response_nanswers = stats_tree_create_node(st, st_str_response_nanswers,
st_node_response_stats, FALSE);
st_node_response_nauthorities = stats_tree_create_node(st, st_str_response_nauthorities,
st_node_response_stats, FALSE);
st_node_response_nadditionals = stats_tree_create_node(st, st_str_response_nadditionals,
st_node_response_stats, FALSE);
}
static int dns_stats_tree_packet(stats_tree* st, packet_info* pinfo _U_, epan_dissect_t* edt _U_, const void* p)
{
const struct DnsTap *pi = (const struct DnsTap *)p;
tick_stat_node(st, st_str_packets, 0, FALSE);
stats_tree_tick_pivot(st, st_node_packet_qr,
val_to_str(pi->packet_qr, dns_qr_vals, "Unknown qr (%d)"));
stats_tree_tick_pivot(st, st_node_packet_qtypes,
val_to_str(pi->packet_qtype, dns_types_description_vals, "Unknown packet type (%d)"));
stats_tree_tick_pivot(st, st_node_packet_qclasses,
val_to_str(pi->packet_qclass, dns_classes, "Unknown class (%d)"));
stats_tree_tick_pivot(st, st_node_packet_rcodes,
val_to_str(pi->packet_rcode, rcode_vals, "Unknown rcode (%d)"));
stats_tree_tick_pivot(st, st_node_packet_opcodes,
val_to_str(pi->packet_opcode, opcode_vals, "Unknown opcode (%d)"));
avg_stat_node_add_value(st, st_str_packets_avg_size, 0, FALSE,
pi->payload_size);
if (pi->packet_qr == 0) {
avg_stat_node_add_value(st, st_str_query_qname_len, 0, FALSE, pi->qname_len);
switch(pi->qname_labels) {
case 1:
tick_stat_node(st, st_str_query_domains_l1, 0, FALSE);
break;
case 2:
tick_stat_node(st, st_str_query_domains_l2, 0, FALSE);
break;
case 3:
tick_stat_node(st, st_str_query_domains_l3, 0, FALSE);
break;
default:
tick_stat_node(st, st_str_query_domains_lmore, 0, FALSE);
break;
}
} else {
avg_stat_node_add_value(st, st_str_response_nquestions, 0, FALSE, pi->nquestions);
avg_stat_node_add_value(st, st_str_response_nanswers, 0, FALSE, pi->nanswers);
avg_stat_node_add_value(st, st_str_response_nauthorities, 0, FALSE, pi->nauthorities);
avg_stat_node_add_value(st, st_str_response_nadditionals, 0, FALSE, pi->nadditionals);
}
return 1;
}
void
proto_reg_handoff_dns(void)
{
static range_t *dns_tcp_port_range;
static range_t *dns_udp_port_range;
static gboolean Initialized = FALSE;
if (!Initialized) {
dissector_handle_t mdns_udp_handle;
dissector_handle_t llmnr_udp_handle;
mdns_udp_handle = create_dissector_handle(dissect_mdns_udp, proto_mdns);
llmnr_udp_handle = create_dissector_handle(dissect_llmnr_udp, proto_llmnr);
dissector_add_uint("udp.port", UDP_PORT_MDNS, mdns_udp_handle);
dissector_add_uint("tcp.port", TCP_PORT_MDNS, dns_handle);
dissector_add_uint("udp.port", UDP_PORT_LLMNR, llmnr_udp_handle);
dissector_add_uint("sctp.port", SCTP_PORT_DNS, dns_handle);
#if 0
dissector_add_uint("sctp.ppi", DNS_PAYLOAD_PROTOCOL_ID, dns_handle);
#endif
stats_tree_register("dns", "dns", "DNS", 0, dns_stats_tree_packet, dns_stats_tree_init, NULL);
gssapi_handle = find_dissector_add_dependency("gssapi", proto_dns);
ntlmssp_handle = find_dissector_add_dependency("ntlmssp", proto_dns);
ssl_dissector_add(TCP_PORT_DNS_TLS, dns_handle);
dtls_dissector_add(UDP_PORT_DNS_DTLS, dns_handle);
Initialized = TRUE;
} else {
dissector_delete_uint_range("tcp.port", dns_tcp_port_range, dns_handle);
dissector_delete_uint_range("udp.port", dns_udp_port_range, dns_handle);
g_free(dns_tcp_port_range);
g_free(dns_udp_port_range);
}
dns_tcp_port_range = range_copy(global_dns_tcp_port_range);
dns_udp_port_range = range_copy(global_dns_udp_port_range);
dissector_add_uint_range("tcp.port", dns_tcp_port_range, dns_handle);
dissector_add_uint_range("udp.port", dns_udp_port_range, dns_handle);
}
void
proto_register_dns(void)
{
static hf_register_info hf[] = {
{ &hf_dns_length,
{ "Length", "dns.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of DNS-over-TCP request or response", HFILL }},
{ &hf_dns_flags,
{ "Flags", "dns.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_flags_response,
{ "Response", "dns.flags.response",
FT_BOOLEAN, 16, TFS(&tfs_flags_response), F_RESPONSE,
"Is the message a response?", HFILL }},
{ &hf_dns_flags_opcode,
{ "Opcode", "dns.flags.opcode",
FT_UINT16, BASE_DEC, VALS(opcode_vals), F_OPCODE,
"Operation code", HFILL }},
{ &hf_dns_flags_authoritative,
{ "Authoritative", "dns.flags.authoritative",
FT_BOOLEAN, 16, TFS(&tfs_flags_authoritative), F_AUTHORITATIVE,
"Is the server is an authority for the domain?", HFILL }},
{ &hf_dns_flags_conflict_query,
{ "Conflict", "dns.flags.conflict",
FT_BOOLEAN, 16, TFS(&tfs_flags_conflict_query), F_CONFLICT,
"Did we receive multiple responses to a query?", HFILL }},
{ &hf_dns_flags_conflict_response,
{ "Conflict", "dns.flags.conflict",
FT_BOOLEAN, 16, TFS(&tfs_flags_conflict_response), F_CONFLICT,
"Is the name considered unique?", HFILL }},
{ &hf_dns_flags_truncated,
{ "Truncated", "dns.flags.truncated",
FT_BOOLEAN, 16, TFS(&tfs_flags_truncated), F_TRUNCATED,
"Is the message truncated?", HFILL }},
{ &hf_dns_flags_recdesired,
{ "Recursion desired", "dns.flags.recdesired",
FT_BOOLEAN, 16, TFS(&tfs_flags_recdesired), F_RECDESIRED,
"Do query recursively?", HFILL }},
{ &hf_dns_flags_tentative,
{ "Tentative", "dns.flags.tentative",
FT_BOOLEAN, 16, TFS(&tfs_flags_tentative), F_TENTATIVE,
"Is the responder authoritative for the name, but not yet verified the uniqueness?", HFILL }},
{ &hf_dns_flags_recavail,
{ "Recursion available", "dns.flags.recavail",
FT_BOOLEAN, 16, TFS(&tfs_flags_recavail), F_RECAVAIL,
"Can the server do recursive queries?", HFILL }},
{ &hf_dns_flags_z,
{ "Z", "dns.flags.z",
FT_BOOLEAN, 16, TFS(&tfs_flags_z), F_Z,
"Z flag", HFILL }},
{ &hf_dns_flags_authenticated,
{ "Answer authenticated", "dns.flags.authenticated",
FT_BOOLEAN, 16, TFS(&tfs_flags_authenticated), F_AUTHENTIC,
"Was the reply data authenticated by the server?", HFILL }},
{ &hf_dns_flags_ad,
{ "AD bit", "dns.flags.authenticated",
FT_BOOLEAN, 16, TFS(&tfs_set_notset), F_AUTHENTIC,
NULL, HFILL }},
{ &hf_dns_flags_checkdisable,
{ "Non-authenticated data", "dns.flags.checkdisable",
FT_BOOLEAN, 16, TFS(&tfs_flags_checkdisable), F_CHECKDISABLE,
"Is non-authenticated data acceptable?", HFILL }},
{ &hf_dns_flags_rcode,
{ "Reply code", "dns.flags.rcode",
FT_UINT16, BASE_DEC, VALS(rcode_vals), F_RCODE,
NULL, HFILL }},
{ &hf_dns_transaction_id,
{ "Transaction ID", "dns.id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Identification of transaction", HFILL }},
{ &hf_dns_qry_type,
{ "Type", "dns.qry.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &dns_types_description_vals_ext, 0,
"Query Type", HFILL }},
{ &hf_dns_qry_class,
{ "Class", "dns.qry.class",
FT_UINT16, BASE_HEX, VALS(dns_classes), 0x0,
"Query Class", HFILL }},
{ &hf_dns_qry_class_mdns,
{ "Class", "dns.qry.class",
FT_UINT16, BASE_HEX, VALS(dns_classes), 0x7FFF,
"Query Class", HFILL }},
{ &hf_dns_qry_qu,
{ "\"QU\" question", "dns.qry.qu",
FT_BOOLEAN, 16, NULL, C_QU,
"QU flag", HFILL }},
{ &hf_dns_qry_name,
{ "Name", "dns.qry.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Query Name", HFILL }},
{ &hf_dns_qry_name_len,
{ "Name Length", "dns.qry.name.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Query Name Len", HFILL }},
{ &hf_dns_count_labels,
{ "Label Count", "dns.count.labels",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Query Label Count", HFILL }},
{ &hf_dns_rr_type,
{ "Type", "dns.resp.type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &dns_types_description_vals_ext, 0x0,
"Response Type", HFILL }},
{ &hf_dns_rr_class,
{ "Class", "dns.resp.class",
FT_UINT16, BASE_HEX, VALS(dns_classes), 0x0,
"Response Class", HFILL }},
{ &hf_dns_rr_class_mdns,
{ "Class", "dns.resp.class",
FT_UINT16, BASE_HEX, VALS(dns_classes), 0x7FFF,
"Response Class", HFILL }},
{ &hf_dns_rr_cache_flush,
{ "Cache flush", "dns.resp.cache_flush",
FT_BOOLEAN, 16, NULL, C_FLUSH,
"Cache flush flag", HFILL }},
{ &hf_dns_rr_ext_rcode,
{ "Higher bits in extended RCODE", "dns.resp.ext_rcode",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_rr_edns0_version,
{ "EDNS0 version", "dns.resp.edns0_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_rr_z,
{ "Z", "dns.resp.z",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_rr_z_do,
{ "DO bit", "dns.resp.z.do",
FT_BOOLEAN, 16, TFS(&tfs_dns_rr_z_do), 0x8000,
"DNSSEC OK", HFILL }},
{ &hf_dns_rr_z_reserved,
{ "Reserved", "dns.resp.z.reserved",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
NULL, HFILL }},
{ &hf_dns_srv_service,
{ "Service", "dns.srv.service",
FT_STRING, BASE_NONE, NULL, 0x0,
"Desired service", HFILL }},
{ &hf_dns_srv_proto,
{ "Protocol", "dns.srv.proto",
FT_STRING, BASE_NONE, NULL, 0x0,
"Desired protocol", HFILL }},
{ &hf_dns_srv_name,
{ "Name", "dns.srv.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Domain this resource record refers to", HFILL }},
{ &hf_dns_srv_priority,
{ "Priority", "dns.srv.priority",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_srv_weight,
{ "Weight", "dns.srv.weight",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_srv_port,
{ "Port", "dns.srv.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_srv_target,
{ "Target", "dns.srv.target",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_order,
{ "Order", "dns.naptr.order",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_preference,
{ "Preference", "dns.naptr.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_flags_length,
{ "Flags Length", "dns.naptr.flags_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_flags,
{ "Flags", "dns.naptr.flags",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_service_length,
{ "Service Length", "dns.naptr.service_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_service,
{ "Service", "dns.naptr.service",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_regex_length,
{ "Regex Length", "dns.naptr.regex_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_regex,
{ "Regex", "dns.naptr.regex",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_replacement_length,
{ "Replacement Length", "dns.naptr.replacement_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_naptr_replacement,
{ "Replacement", "dns.naptr.replacement",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_rr_name,
{ "Name", "dns.resp.name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Response Name", HFILL }},
{ &hf_dns_rr_ttl,
{ "Time to live", "dns.resp.ttl",
FT_INT32, BASE_DEC, NULL, 0x0,
"Response TTL", HFILL }},
{ &hf_dns_rr_len,
{ "Data length", "dns.resp.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Response Length", HFILL }},
{ &hf_dns_a,
{ "Address", "dns.a",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Response Address", HFILL }},
{ &hf_dns_md,
{ "Mail Destination", "dns.md",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mf,
{ "Mail Forwarder", "dns.mf",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mb,
{ "MailBox Domaine", "dns.mb",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mg,
{ "Mail Group member", "dns.mg",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mr,
{ "Mail Rename domaine", "dns.mr",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_null,
{ "Null (data)", "dns.null",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_aaaa,
{ "AAAA Address", "dns.aaaa",
FT_IPv6, BASE_NONE, NULL, 0x0,
"AAAA Response Address", HFILL }},
{ &hf_dns_cname,
{ "CNAME", "dns.cname",
FT_STRING, BASE_NONE, NULL, 0x0,
"Response Primary Name", HFILL }},
{ &hf_dns_rr_udp_payload_size_mdns,
{ "UDP payload size", "dns.rr.udp_payload_size",
FT_UINT16, BASE_HEX, NULL, 0x7FFF,
NULL, HFILL }},
{ &hf_dns_rr_udp_payload_size,
{ "UDP payload size", "dns.rr.udp_payload_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_mname,
{ "Primary name server", "dns.soa.mname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_rname,
{ "Responsible authority's mailbox", "dns.soa.rname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_serial_number,
{ "Serial Number", "dns.soa.serial_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_refresh_interval,
{ "Refresh Interval", "dns.soa.refresh_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_retry_interval,
{ "Retry Interval", "dns.soa.retry_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_expire_limit,
{ "Expire limit", "dns.soa.expire_limit",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_soa_minimum_ttl,
{ "Minimum TTL", "dns.soa.mininum_ttl",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ptr_domain_name,
{ "Domain Name", "dns.ptr.domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_wks_address,
{ "Address", "dns.wks.address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_wks_protocol,
{ "Protocol", "dns.wks.protocol",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }},
{ &hf_dns_wks_bits,
{ "Bits", "dns.wks.bits",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_hinfo_cpu_length,
{ "CPU Length", "dns.hinfo.cpu_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_hinfo_cpu,
{ "CPU", "dns.hinfo.cpu",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_hinfo_os_length,
{ "OS Length", "dns.hinfo.os_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_hinfo_os,
{ "OS", "dns.hinfo.os",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ & hf_dns_minfo_r_mailbox,
{ "Responsible Mailbox", "dns.minfo.r",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ & hf_dns_minfo_e_mailbox,
{ "Error Mailbox", "dns.minfo.e",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mx_preference,
{ "Preference", "dns.mx.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_mx_mail_exchange,
{ "Mail Exchange", "dns.mx.mail_exchange",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_txt_length,
{ "TXT Length", "dns.txt.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_txt,
{ "TXT", "dns.txt",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_openpgpkey,
{ "OpenPGP Key", "dns.openpgpkey",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_csync_soa,
{ "SOA", "dns.csync.soa",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_csync_flags,
{ "Flags", "dns.csync.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_csync_flags_immediate,
{ "immediate", "dns.csync.flags.immediate",
FT_BOOLEAN, 16, NULL, 0x0001,
NULL, HFILL }},
{ &hf_dns_csync_flags_soaminimum,
{ "soaminimum", "dns.csync.flags.soaminimum",
FT_BOOLEAN, 16, NULL, 0x0002,
NULL, HFILL }},
{ &hf_dns_csync_type_bitmap,
{ "Type Bitmap", "dns.csync.type_bitmap",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_spf_length,
{ "SPF Length", "dns.spf.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_spf,
{ "SPF", "dns.spf",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_nodeid_preference,
{ "Preference", "dns.ilnp.nid.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_nodeid,
{ "NodeID", "dns.ilnp.nid",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locator32_preference,
{ "Preference", "dns.ilnp.l32.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locator32,
{ "Locator32", "dns.ilnp.l32",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locator64_preference,
{ "Preference", "dns.ilnp.l64.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locator64,
{ "Locator64", "dns.ilnp.l64",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locatorfqdn_preference,
{ "Preference", "dns.ilnp.lp.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ilnp_locatorfqdn,
{ "Locator FQDN", "dns.ilnp.lp",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_eui48,
{ "EUI48 Address", "dns.eui48",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_eui64,
{ "EUI64 Address", "dns.eui64",
FT_EUI64, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_rrsig_type_covered,
{ "Type Covered", "dns.rrsig.type_covered",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &dns_types_description_vals_ext, 0x0,
"Identifies the type of the RRset that is covered by this RRSIG record", HFILL }},
{ &hf_dns_rrsig_algorithm,
{ "Algorithm", "dns.rrsig.algorithm",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0x0,
"Identifies the cryptographic algorithm used to create the signature", HFILL }},
{ &hf_dns_rrsig_labels,
{ "Labels", "dns.rrsig.labels",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the number of labels in the original RRSIG RR owner name", HFILL }},
{ &hf_dns_rrsig_original_ttl,
{ "Original TTL", "dns.rrsig.original_ttl",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the TTL of the covered RRset as it appears in the authoritative zone", HFILL }},
{ &hf_dns_rrsig_signature_expiration,
{ "Signature Expiration", "dns.rrsig.signature_expiration",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Specify a validity period for the signature", HFILL }},
{ &hf_dns_rrsig_signature_inception,
{ "Signature Inception", "dns.rrsig.signature_inception",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Specify a validity period for the signature", HFILL }},
{ &hf_dns_rrsig_key_tag,
{ "Key Tag", "dns.rrsig.key_tag",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Contains the key tag value of the DNSKEY RR that validates this signature", HFILL }},
{ &hf_dns_rrsig_signers_name,
{ "Signer's name", "dns.rrsig.signers_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Identifies the owner name of the DNSKEY RR that a validator is supposed to use to validate this signature", HFILL }},
{ &hf_dns_rrsig_signature,
{ "Signature", "dns.rrsig.signature",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Contains the cryptographic signature that covers the RRSIG RDATA", HFILL }},
{ &hf_dns_dnskey_flags,
{ "Flags", "dns.dnskey.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_dnskey_flags_zone_key,
{ "Zone Key", "dns.dnskey.flags.zone_key",
FT_BOOLEAN, 16, TFS(&dns_dnskey_zone_key_tfs), DNSKEY_FLAGS_ZK,
NULL, HFILL }},
{ &hf_dns_dnskey_flags_key_revoked,
{ "Key Revoked", "dns.dnskey.flags.key_revoked",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), DNSKEY_FLAGS_KR,
NULL, HFILL }},
{ &hf_dns_dnskey_flags_secure_entry_point,
{ "Key Signing Key", "dns.dnskey.flags.secure_entry_point",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), DNSKEY_FLAGS_SEP,
NULL, HFILL }},
{ &hf_dns_dnskey_flags_reserved,
{ "Key Signing Key", "dns.dnskey.flags.reserved",
FT_UINT16, BASE_HEX, NULL, DNSKEY_FLAGS_RSV,
"Must be zero", HFILL }},
{ &hf_dns_dnskey_protocol,
{ "Protocol", "dns.dnskey.protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Must be 3", HFILL }},
{ &hf_dns_dnskey_algorithm,
{ "Algorithm", "dns.dnskey.algorithm",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0x0,
"Identifies the public key's cryptographic algorithm and determines the format of the Public Key field", HFILL }},
{ &hf_dns_dnskey_key_id,
{ "Key id", "dns.dnskey.key_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_dnskey_public_key,
{ "Public Key", "dns.dnskey.public_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_key_flags,
{ "Flags", "dns.key.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_key_flags_authentication,
{ "Key allowed for authentication", "dns.key.flags.authentication",
FT_BOOLEAN, 16, TFS(&tfs_not_allowed_allowed), 0x8000,
NULL, HFILL }},
{ &hf_dns_key_flags_confidentiality,
{ "Key allowed for confidentiality", "dns.key.flags.confidentiality",
FT_BOOLEAN, 16, TFS(&tfs_not_allowed_allowed), 0x4000,
NULL, HFILL }},
{ &hf_dns_key_flags_key_required,
{ "Key required", "dns.key.flags.required",
FT_BOOLEAN, 16, TFS(&tfs_required_experimental), 0x2000,
NULL, HFILL }},
{ &hf_dns_key_flags_associated_user,
{ "Key is associated with a user", "dns.key.flags.associated_user",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0400,
NULL, HFILL }},
{ &hf_dns_key_flags_associated_named_entity,
{ "Key is associated with the named entity", "dns.key.flags.associated_named_entity",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x0200,
NULL, HFILL }},
{ &hf_dns_key_flags_ipsec,
{ "Key use with IPSEC", "dns.key.flags.ipsec",
FT_BOOLEAN, 16, TFS(&tfs_valid_invalid), 0x0080,
NULL, HFILL }},
{ &hf_dns_key_flags_mime,
{ "Key use with MIME security multiparts", "dns.key.flags.mime",
FT_BOOLEAN, 16, TFS(&tfs_valid_invalid), 0x0040,
NULL, HFILL }},
{ &hf_dns_key_flags_signatory,
{ "Signatory", "dns.key.flags.signatory",
FT_UINT16, BASE_DEC, NULL, 0x000F,
NULL, HFILL }},
{ &hf_dns_key_protocol,
{ "Protocol", "dns.key.protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_key_algorithm,
{ "Algorithm", "dns.key.algorithm",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_key_key_id,
{ "Key ID", "dns.key.key_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_key_public_key,
{ "Public Key", "dns.key.public_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_px_preference,
{ "Preference", "dns.px.preference",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_px_map822,
{ "MAP822", "dns.px.map822",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_px_mapx400,
{ "MAPX400", "dns.px.map400",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_algo_name,
{ "Algorithm name", "dns.tkey.algo_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_signature_expiration,
{ "Signature Expiration", "dns.tkey.signature_expiration",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Specify a validity period for the signature", HFILL }},
{ &hf_dns_tkey_signature_inception,
{ "Signature Inception", "dns.tkey.signature_inception",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Specify a validity period for the signature", HFILL }},
{ &hf_dns_tkey_mode,
{ "Mode", "dns.tkey.mode",
FT_UINT16, BASE_DEC, VALS(tkey_mode_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_error,
{ "Error", "dns.tkey.error",
FT_UINT16, BASE_DEC, VALS(rcode_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_key_size,
{ "Key Size", "dns.tkey.key_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_key_data,
{ "Key Data", "dns.tkey.key_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_other_size,
{ "Other Size", "dns.tkey.other_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tkey_other_data,
{ "Other Data", "dns.tkey.other_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_precedence,
{ "Gateway Precedence", "dns.ipseckey.gateway_precedence",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_algorithm,
{ "Gateway Algorithm", "dns.ipseckey.gateway_algorithm",
FT_UINT8, BASE_DEC, VALS(gw_algo_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_type,
{ "Gateway Type", "dns.ipseckey.gateway_type",
FT_UINT8, BASE_DEC, VALS(gw_type_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_ipv4,
{ "IPv4 Gateway", "dns.ipseckey.gateway_ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_ipv6,
{ "IPv6 Gateway", "dns.ipseckey.gateway_ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_gateway_dns,
{ "DNS Gateway", "dns.ipseckey.gateway_dns",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ipseckey_public_key,
{ "Public Key", "dns.ipseckey.public_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_a6_prefix_len,
{ "Prefix len", "dns.a6.prefix_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_a6_address_suffix,
{ "Address Suffix", "dns.a6.address_suffix",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_a6_prefix_name,
{ "Prefix name", "dns.a6.prefix_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_dname,
{ "Dname", "dns.dname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_version,
{ "Version", "dns.loc.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_size,
{ "Size", "dns.loc.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_horizontal_precision,
{ "Horizontal Precision", "dns.loc.horizontal_precision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_vertical_precision,
{ "Vertial Precision", "dns.loc.vertial_precision",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_latitude,
{ "Latitude", "dns.loc.latitude",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_longitude,
{ "Longitude", "dns.loc.longitude",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_altitude,
{ "Altitude", "dns.loc.altitude",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_loc_unknown_data,
{ "Unknown data", "dns.loc.unknown_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_nxt_next_domain_name,
{ "Next Domain Name", "dns.nxt.next_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_kx_preference,
{ "Preference", "dns.kx.preference",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_kx_key_exchange,
{ "Key Exchange", "dns.kx.key_exchange",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_cert_type,
{ "Type", "dns.cert.type",
FT_UINT16, BASE_DEC, VALS(dns_cert_type_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_cert_key_tag,
{ "Key Tag", "dns.cert.key_tag",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_cert_algorithm,
{ "Algorithm", "dns.cert.algorithm",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_cert_certificate,
{ "Certificate (or CRL)", "dns.cert.certificate",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_nsec_next_domain_name,
{ "Next Domain Name", "dns.nsec.next_domain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_ns,
{ "Name Server", "dns.ns",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt,
{ "Option", "dns.opt",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_code,
{ "Option Code", "dns.opt.code",
FT_UINT16, BASE_DEC,
VALS(edns0_opt_code_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_opt_len,
{ "Option Length", "dns.opt.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_data,
{ "Option Data", "dns.opt.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_dau,
{ "DAU", "dns.opt.dau",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0x0,
"DNSSEC Algorithm Understood", HFILL }},
{ &hf_dns_opt_dhu,
{ "DHU", "dns.opt.dhu",
FT_UINT8, BASE_DEC, VALS(dns_ds_digest_vals), 0x0,
"DS Hash Understood", HFILL }},
{ &hf_dns_opt_n3u,
{ "N3U", "dns.opt.n3u",
FT_UINT8, BASE_DEC, VALS(hash_algorithms), 0x0,
"NSEC3 Hash Understood", HFILL }},
{ &hf_dns_opt_client_family,
{ "Family", "dns.opt.client.family",
FT_UINT16, BASE_DEC,
VALS(afamily_vals), 0x0,
NULL, HFILL }},
{ &hf_dns_opt_client_netmask,
{ "Source Netmask", "dns.opt.client.netmask",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_client_scope,
{ "Scope Netmask", "dns.opt.client.scope",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_client_addr,
{ "Client Subnet", "dns.opt.client.addr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_client_addr4,
{ "Client Subnet", "dns.opt.client.addr4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_client_addr6,
{ "Client Subnet", "dns.opt.client.addr6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_cookie_client,
{ "Client Cookie", "dns.opt.cookie.client",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_cookie_server,
{ "Server Cookie", "dns.opt.cookie.server",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_opt_edns_tcp_keepalive_timeout,
{ "Timeout", "dns.opt.edns_tcp_keepalive.timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
"an idle timeout value for the TCP connection, specified in units of 100 milliseconds", HFILL }},
{ &hf_dns_opt_padding,
{ "Padding", "dns.opt.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
"The PADDING octets SHOULD be set to 0x00", HFILL }},
{ &hf_dns_opt_chain_fqdn,
{ "Closest Trust Point", "dns.opt.chain.fqdn",
FT_STRING, BASE_NONE, NULL, 0x0,
"A variable length Fully Qualified Domain Name (FQDN) in DNS wire format of the requested start point of the chain", HFILL }},
{ &hf_dns_count_questions,
{ "Questions", "dns.count.queries",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of queries in packet", HFILL }},
{ &hf_dns_count_zones,
{ "Zones", "dns.count.zones",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of zones in packet", HFILL }},
{ &hf_dns_count_answers,
{ "Answer RRs", "dns.count.answers",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of answers in packet", HFILL }},
{ &hf_dns_count_prerequisites,
{ "Prerequisites", "dns.count.prerequisites",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of prerequisites in packet", HFILL }},
{ &hf_dns_count_auth_rr,
{ "Authority RRs", "dns.count.auth_rr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of authoritative records in packet", HFILL }},
{ &hf_dns_count_updates,
{ "Updates", "dns.count.updates",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of updates records in packet", HFILL }},
{ &hf_dns_nsec3_algo,
{ "Hash algorithm", "dns.nsec3.algo",
FT_UINT8, BASE_DEC, VALS(hash_algorithms), 0,
NULL, HFILL }},
{ &hf_dns_nsec3_flags,
{ "NSEC3 flags", "dns.nsec3.flags",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_nsec3_flag_optout,
{ "NSEC3 Opt-out flag", "dns.nsec3.flags.opt_out",
FT_BOOLEAN, 8, TFS(&tfs_flags_nsec3_optout), NSEC3_FLAG_OPTOUT,
NULL, HFILL }},
{ &hf_dns_nsec3_iterations,
{ "NSEC3 iterations", "dns.nsec3.iterations",
FT_UINT16, BASE_DEC, NULL, 0,
"Number of hashing iterations", HFILL }},
{ &hf_dns_nsec3_salt_length,
{ "Salt length", "dns.nsec3.salt_length",
FT_UINT8, BASE_DEC, NULL, 0,
"Length of salt in bytes", HFILL }},
{ &hf_dns_nsec3_salt_value,
{ "Salt value", "dns.nsec3.salt_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_nsec3_hash_length,
{ "Hash length", "dns.nsec3.hash_length",
FT_UINT8, BASE_DEC, NULL, 0,
"Length in bytes of next hashed owner", HFILL }},
{ &hf_dns_nsec3_hash_value,
{ "Next hashed owner", "dns.nsec3.hash_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_tlsa_certificate_usage,
{ "Certificate Usage", "dns.tlsa.certificate_usage",
FT_UINT8, BASE_DEC, VALS(tlsa_certificate_usage_vals), 0,
"Specifies the provided association that will be used to match the certificate presented in the TLS handshake", HFILL }},
{ &hf_dns_tlsa_selector,
{ "Selector", "dns.tlsa.selector",
FT_UINT8, BASE_DEC, VALS(tlsa_selector_vals), 0,
"Specifies which part of the TLS certificate presented by the server will be matched against the association data", HFILL }},
{ &hf_dns_tlsa_matching_type,
{ "Matching Type", "dns.tlsa.matching_type",
FT_UINT8, BASE_DEC, VALS(tlsa_matching_type_vals), 0,
"Specifies how the certificate association is presented", HFILL }},
{ &hf_dns_tlsa_certificate_association_data,
{ "Certificate Association Data", "dns.tlsa.certificate_association_data",
FT_BYTES, BASE_NONE, NULL, 0,
"The data refers to the certificate in the association", HFILL }},
{ &hf_dns_tsig_algorithm_name,
{ "Algorithm Name", "dns.tsig.algorithm_name",
FT_STRING, BASE_NONE, NULL, 0x0,
"Name of algorithm used for the MAC", HFILL }},
{ &hf_dns_tsig_time_signed,
{ "Time Signed", "dns.tsig.time_signed",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tsig_original_id,
{ "Original Id", "dns.tsig.original_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tsig_error,
{ "Error", "dns.tsig.error",
FT_UINT16, BASE_DEC, VALS(rcode_vals), 0x0,
"Expanded RCODE for TSIG", HFILL }},
{ &hf_dns_tsig_fudge,
{ "Fudge", "dns.tsig.fudge",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of bytes for the MAC", HFILL }},
{ &hf_dns_tsig_mac_size,
{ "MAC Size", "dns.tsig.mac_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of bytes for the MAC", HFILL }},
{ &hf_dns_tsig_other_len,
{ "Other Len", "dns.tsig.other_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of bytes for Other Data", HFILL }},
{ &hf_dns_tsig_mac,
{ "MAC", "dns.tsig.mac",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_tsig_other_data,
{ "Other Data", "dns.tsig.other_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_response_in,
{ "Response In", "dns.response_in",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_RESPONSE), 0x0,
"The response to this DNS query is in this frame", HFILL }},
{ &hf_dns_response_to,
{ "Request In", "dns.response_to",
FT_FRAMENUM, BASE_NONE, FRAMENUM_TYPE(FT_FRAMENUM_REQUEST), 0x0,
"This is a response to the DNS query in this frame", HFILL }},
{ &hf_dns_time,
{ "Time", "dns.time",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"The time between the Query and the Response", HFILL }},
{ &hf_dns_count_add_rr,
{ "Additional RRs", "dns.count.add_rr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of additional records in packet", HFILL }},
{ &hf_dns_sshfp_algorithm,
{ "Algorithm", "dns.sshfp.algorithm",
FT_UINT8, BASE_DEC, VALS(sshfp_algo_vals), 0,
NULL, HFILL }},
{ &hf_dns_sshfp_fingerprint_type,
{ "Fingerprint type", "dns.sshfp.fingerprint.type",
FT_UINT8, BASE_DEC, VALS(sshfp_fingertype_vals), 0,
NULL, HFILL }},
{ &hf_dns_sshfp_fingerprint,
{ "Fingerprint", "dns.sshfp.fingerprint",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_hip_hit_length,
{ "HIT length", "dns.hip.hit.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_hip_pk_algo,
{ "HIT length", "dns.hip.hit.pk.algo",
FT_UINT8, BASE_DEC, VALS(hip_algo_vals), 0,
NULL, HFILL }},
{ &hf_dns_hip_pk_length,
{ "PK length", "dns.hip.pk.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_hip_hit,
{ "Host Identity Tag", "dns.hip.hit",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_hip_pk,
{ "HIP Public Key", "dns.hip.pk",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_hip_rendezvous_server,
{ "Rendezvous Server", "dns.hip.rendezvous_server",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_dhcid_rdata,
{ "DHCID Data", "dns.dhcid.rdata",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_ds_key_id,
{ "Key id", "dns.ds.key_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_dns_ds_algorithm,
{ "Algorithm", "dns.ds.algorithm",
FT_UINT8, BASE_DEC, VALS(dnssec_algo_vals), 0,
NULL, HFILL }},
{ &hf_dns_ds_digest_type,
{ "Digest Type", "dns.ds.digest_type",
FT_UINT8, BASE_DEC, VALS(dns_ds_digest_vals), 0,
NULL, HFILL }},
{ &hf_dns_ds_digest,
{ "Digest", "dns.ds.digest",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_apl_address_family,
{ "Address Family", "dns.apl.address_family",
FT_UINT16, BASE_DEC, VALS(afamily_vals), 0,
NULL, HFILL }},
{ &hf_dns_apl_coded_prefix,
{ "Prefix Length", "dns.apl.coded_prefix",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_apl_negation,
{ "Negation Flag", "dns.apl.negation",
FT_BOOLEAN, 8, TFS(&tfs_dns_apl_negation), DNS_APL_NEGATION,
NULL, HFILL }},
{ &hf_dns_apl_afdlength,
{ "Address Length","dns.apl.afdlength",
FT_UINT8, BASE_DEC, NULL, DNS_APL_AFDLENGTH,
"in octets", HFILL }},
{ &hf_dns_apl_afdpart_ipv4,
{ "Address","dns.apl.afdpart.ipv4",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_apl_afdpart_ipv6,
{ "Address","dns.apl.afdpart.ipv6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_apl_afdpart_data,
{ "Address","dns.apl.afdpart.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_longitude_length,
{ "Longitude length","dns.gpos.longitude_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_longitude,
{ "Longitude","dns.gpos.longitude",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_latitude_length,
{ "Latitude length","dns.gpos.latitude_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_latitude,
{ "Latitude","dns.gpos.latitude",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_altitude_length,
{ "Altitude length","dns.gpos.altitude_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_gpos_altitude,
{ "Altitude","dns.gpos.altitude",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_rp_mailbox,
{ "Mailbox","dns.rp.mailbox",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_rp_txt_rr,
{ "TXT RR","dns.rp.txt_rr",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_afsdb_subtype,
{ "Subtype","dns.afsdb.subtype",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_afsdb_hostname,
{ "Hostname","dns.afsdb.hostname",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_x25_length,
{ "Length","dns.x25.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_x25_psdn_address,
{ "PSDN-Address","dns.x25.psdn_address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_isdn_length,
{ "Length","dns.idsn.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_isdn_address,
{ "ISDN Address","dns.idsn.address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_isdn_sa_length,
{ "Length","dns.idsn.sa.length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_isdn_sa,
{ "Sub Address","dns.idsn.sa.address",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_rt_preference,
{ "Preference","dns.rt.subtype",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_rt_intermediate_host,
{ "Intermediate Hostname","dns.rt.intermediate_host",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_nsap_rdata,
{ "NSAP Data", "dns.nsap.rdata",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_nsap_ptr_owner,
{ "Owner", "dns.nsap_ptr.owner",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_dns_caa_flags,
{ "CAA Flags", "dns.caa.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_caa_flag_issuer_critical,
{ "Issuer Critical", "dns.caa.flags.issuer_critical",
FT_BOOLEAN, 8, TFS(&tfs_critical_not_critical), CAA_FLAG_ISSUER_CRITICAL,
"Other CAs must not issue certificates", HFILL }},
{ &hf_dns_caa_issue,
{ "Issue", "dns.caa.issue",
FT_STRING, BASE_NONE, NULL, 0x0,
"CA which is allowed to issue certificates", HFILL }},
{ &hf_dns_caa_issuewild,
{ "Issue Wildcard", "dns.caa.issuewild",
FT_STRING, BASE_NONE, NULL, 0x0,
"CA which is allowed to issue wildcard certificates", HFILL }},
{ &hf_dns_caa_iodef,
{ "Report URL", "dns.caa.iodef",
FT_STRING, BASE_NONE, NULL, 0x0,
"URL or email address for certificate issue requests and violation reports", HFILL }},
{ &hf_dns_caa_unknown,
{ "Unknown tag", "dns.caa.unknown",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_caa_tag_length,
{ "Tag length", "dns.caa.tag_length",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_dns_caa_tag,
{ "Tag", "dns.caa.tag",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_caa_value,
{ "Value", "dns.caa.value",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_wins_local_flag,
{ "Local Flag", "dns.wins.local_flag",
FT_BOOLEAN, 32, TFS(&tfs_true_false), 0x1,
NULL, HFILL }},
{ &hf_dns_wins_lookup_timeout,
{ "Lookup timeout", "dns.wins.lookup_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"In seconds", HFILL }},
{ &hf_dns_wins_cache_timeout,
{ "Cache timeout", "dns.wins.cache_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"In seconds", HFILL }},
{ &hf_dns_wins_nb_wins_servers,
{ "Number of WINS servers", "dns.wins.nb_wins_servers",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_wins_server,
{ "WINS Server Address", "dns.wins.wins_server",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_winsr_local_flag,
{ "Local Flag", "dns.winsr.local_flag",
FT_BOOLEAN, 32, TFS(&tfs_true_false), 0x1,
NULL, HFILL }},
{ &hf_dns_winsr_lookup_timeout,
{ "Lookup timeout", "dns.winsr.lookup_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"In seconds", HFILL }},
{ &hf_dns_winsr_cache_timeout,
{ "Cache timeout", "dns.winsr.cache_timeout",
FT_UINT32, BASE_DEC, NULL, 0x0,
"In seconds", HFILL }},
{ &hf_dns_winsr_name_result_domain,
{ "Name Result Domain", "dns.winsr.name_result_domain",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_dns_data,
{ "Data", "dns.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_dns_opt_bad_length, { "dns.rr.opt.bad_length", PI_MALFORMED, PI_ERROR, "Length too long for any type of IP address.", EXPFILL }},
{ &ei_dns_undecoded_option, { "dns.undecoded.type", PI_UNDECODED, PI_NOTE, "Undecoded option", EXPFILL }},
{ &ei_dns_depr_opc, { "dns.depr.opc", PI_PROTOCOL, PI_WARN, "Deprecated opcode", EXPFILL }},
{ &ei_ttl_negative, { "dns.ttl.negative", PI_PROTOCOL, PI_WARN, "TTL can't be negative", EXPFILL }},
{ &ei_dns_tsig_alg, { "dns.tsig.noalg", PI_UNDECODED, PI_WARN, "No dissector for algorithm", EXPFILL }},
};
static gint *ett[] = {
&ett_dns,
&ett_dns_qd,
&ett_dns_rr,
&ett_dns_qry,
&ett_dns_ans,
&ett_dns_flags,
&ett_dns_opts,
&ett_nsec3_flags,
&ett_key_flags,
&ett_t_key,
&ett_dns_mac,
&ett_caa_flags,
&ett_caa_data,
&ett_dns_csdync_flags,
};
module_t *dns_module;
expert_module_t* expert_dns;
proto_dns = proto_register_protocol("Domain Name System", "DNS", "dns");
proto_mdns = proto_register_protocol("Multicast Domain Name System", "mDNS", "mdns");
proto_llmnr = proto_register_protocol("Link-local Multicast Name Resolution", "LLMNR", "llmnr");
proto_register_field_array(proto_dns, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dns = expert_register_protocol(proto_dns);
expert_register_field_array(expert_dns, ei, array_length(ei));
range_convert_str(&global_dns_tcp_port_range, DEFAULT_DNS_PORT_RANGE, MAX_TCP_PORT);
range_convert_str(&global_dns_udp_port_range, DEFAULT_DNS_PORT_RANGE, MAX_UDP_PORT);
dns_module = prefs_register_protocol(proto_dns, proto_reg_handoff_dns);
prefs_register_range_preference(dns_module, "tcp.ports", "DNS TCP ports",
"TCP ports to be decoded as DNS (default: "
DEFAULT_DNS_PORT_RANGE ")",
&global_dns_tcp_port_range, MAX_TCP_PORT);
prefs_register_range_preference(dns_module, "udp.ports", "DNS UDP ports",
"UDP ports to be decoded as DNS (default: "
DEFAULT_DNS_PORT_RANGE ")",
&global_dns_udp_port_range, MAX_UDP_PORT);
prefs_register_bool_preference(dns_module, "desegment_dns_messages",
"Reassemble DNS messages spanning multiple TCP segments",
"Whether the DNS dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&dns_desegment);
prefs_register_obsolete_preference(dns_module, "use_for_addr_resolution");
prefs_register_static_text_preference(dns_module, "text_use_for_addr_resolution",
"DNS address resolution settings can be changed in the Name Resolution preferences",
"DNS address resolution settings can be changed in the Name Resolution preferences");
dns_tsig_dissector_table = register_dissector_table("dns.tsig.mac", "DNS TSIG MAC Dissectors", proto_dns, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
dns_handle = register_dissector("dns", dissect_dns, proto_dns);
dns_tap = register_tap("dns");
}
