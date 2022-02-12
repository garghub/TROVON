static void
ip_defragment_init(void)
{
fragment_table_init(&ip_fragment_table);
reassembled_table_init(&ip_reassembled_table);
}
void
capture_ip(const guchar *pd, int offset, int len, packet_counts *ld) {
if (!BYTES_ARE_IN_FRAME(offset, len, IPH_MIN_LEN)) {
ld->other++;
return;
}
switch (pd[offset + 9]) {
case IP_PROTO_TCP:
ld->tcp++;
break;
case IP_PROTO_UDP:
case IP_PROTO_UDPLITE:
ld->udp++;
break;
case IP_PROTO_ICMP:
case IP_PROTO_ICMPV6:
ld->icmp++;
break;
case IP_PROTO_SCTP:
ld->sctp++;
break;
case IP_PROTO_OSPF:
ld->ospf++;
break;
case IP_PROTO_GRE:
ld->gre++;
break;
case IP_PROTO_VINES:
ld->vines++;
break;
default:
ld->other++;
}
}
static void
add_geoip_info_entry(proto_item *geoip_info_item, tvbuff_t *tvb, gint offset, guint32 ip, int isdst)
{
proto_tree *geoip_info_tree;
guint num_dbs = geoip_db_num_dbs();
guint item_cnt = 0;
guint dbnum;
geoip_info_tree = proto_item_add_subtree(geoip_info_item, ett_geoip_info);
for (dbnum = 0; dbnum < num_dbs; dbnum++) {
const char *geoip_str = geoip_db_lookup_ipv4(dbnum, ip, NULL);
int db_type = geoip_db_type(dbnum);
int geoip_hf, geoip_local_hf;
switch (db_type) {
case GEOIP_COUNTRY_EDITION:
geoip_hf = hf_geoip_country;
geoip_local_hf = (isdst) ? hf_geoip_dst_country : hf_geoip_src_country;
break;
case GEOIP_CITY_EDITION_REV0:
geoip_hf = hf_geoip_city;
geoip_local_hf = (isdst) ? hf_geoip_dst_city : hf_geoip_src_city;
break;
case GEOIP_CITY_EDITION_REV1:
geoip_hf = hf_geoip_city;
geoip_local_hf = (isdst) ? hf_geoip_dst_city : hf_geoip_src_city;
break;
case GEOIP_ORG_EDITION:
geoip_hf = hf_geoip_org;
geoip_local_hf = (isdst) ? hf_geoip_dst_org : hf_geoip_src_org;
break;
case GEOIP_ISP_EDITION:
geoip_hf = hf_geoip_isp;
geoip_local_hf = (isdst) ? hf_geoip_dst_isp : hf_geoip_src_isp;
break;
case GEOIP_ASNUM_EDITION:
geoip_hf = hf_geoip_asnum;
geoip_local_hf = (isdst) ? hf_geoip_dst_asnum : hf_geoip_src_asnum;
break;
case WS_LAT_FAKE_EDITION:
geoip_hf = hf_geoip_lat;
geoip_local_hf = (isdst) ? hf_geoip_dst_lat : hf_geoip_src_lat;
break;
case WS_LON_FAKE_EDITION:
geoip_hf = hf_geoip_lon;
geoip_local_hf = (isdst) ? hf_geoip_dst_lon : hf_geoip_src_lon;
break;
default:
continue;
break;
}
if (geoip_str) {
proto_item *item;
if (db_type == WS_LAT_FAKE_EDITION || db_type == WS_LON_FAKE_EDITION) {
item = proto_tree_add_double_format_value(geoip_info_tree, geoip_local_hf,
tvb, offset, 4, g_ascii_strtod(geoip_str, NULL), "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_double_format_value(geoip_info_tree, geoip_hf,
tvb, offset, 4, g_ascii_strtod(geoip_str, NULL), "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
} else {
item = proto_tree_add_string_format_value(geoip_info_tree, geoip_local_hf,
tvb, offset, 4, geoip_str, "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_string_format_value(geoip_info_tree, geoip_hf,
tvb, offset, 4, geoip_str, "%s", geoip_str);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
}
item_cnt++;
proto_item_append_text(geoip_info_item, "%s%s",
plurality(item_cnt, "", ", "), geoip_str);
}
}
if (item_cnt == 0)
proto_item_append_text(geoip_info_item, "Unknown");
}
static void
add_geoip_info(proto_tree *tree, tvbuff_t *tvb, gint offset, guint32 src32,
guint32 dst32)
{
guint num_dbs;
proto_item *geoip_info_item;
num_dbs = geoip_db_num_dbs();
if (num_dbs < 1)
return;
geoip_info_item = proto_tree_add_text(tree, tvb, offset + IPH_SRC, 4, "Source GeoIP: ");
PROTO_ITEM_SET_GENERATED(geoip_info_item);
add_geoip_info_entry(geoip_info_item, tvb, offset + IPH_SRC, src32, 0);
geoip_info_item = proto_tree_add_text(tree, tvb, offset + IPH_DST, 4,
"Destination GeoIP: ");
PROTO_ITEM_SET_GENERATED(geoip_info_item);
add_geoip_info_entry(geoip_info_item, tvb, offset + IPH_DST, dst32, 1);
}
static void
dissect_ipopt_type(tvbuff_t *tvb, int offset, proto_tree *tree)
{
proto_tree *type_tree;
proto_item *ti;
ti = proto_tree_add_item(tree, hf_ip_opt_type, tvb, offset, 1, ENC_NA);
type_tree = proto_item_add_subtree(ti, ett_ip_opt_type);
proto_tree_add_item(type_tree, hf_ip_opt_type_copy, tvb, offset, 1, ENC_NA);
proto_tree_add_item(type_tree, hf_ip_opt_type_class, tvb, offset, 1, ENC_NA);
proto_tree_add_item(type_tree, hf_ip_opt_type_number, tvb, offset, 1, ENC_NA);
}
static void
dissect_ipopt_eool(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen _U_, packet_info *pinfo _U_,
proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, 1, "%s", optp->name);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
}
static void
dissect_ipopt_security(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
proto_item *tf_sub;
guint val;
guint curr_offset = offset;
tf = proto_tree_add_text(opt_tree, tvb, curr_offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, curr_offset, field_tree);
curr_offset++;
tf_sub = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, curr_offset, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf_sub, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
curr_offset++;
if (optlen == 11) {
val = tvb_get_ntohs(tvb, curr_offset);
if (match_strval(val, secl_rfc791_vals)) {
proto_tree_add_item(field_tree, hf_ip_opt_sec_rfc791_sec,
tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(field_tree, hf_ip_opt_sec_rfc791_comp,
tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(field_tree, hf_ip_opt_sec_rfc791_hr,
tvb, curr_offset, 2, ENC_ASCII|ENC_NA);
curr_offset += 2;
proto_tree_add_item(field_tree, hf_ip_opt_sec_rfc791_tcc,
tvb, curr_offset, 3, ENC_ASCII|ENC_NA);
return;
}
}
proto_tree_add_item(field_tree, hf_ip_opt_sec_cl, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if ((curr_offset - offset) >= optlen) {
return;
}
val = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bitmask(field_tree, tvb, curr_offset, hf_ip_opt_sec_prot_auth_flags,
ett_ip_opt_sec_prot_auth_flags, ip_opt_sec_prot_auth_fields_byte_1,
ENC_BIG_ENDIAN);
curr_offset++;
while (val & 0x01) {
if ((val & 0x01) && ((curr_offset - offset) == optlen)) {
expert_add_info_format(pinfo, tf_sub, PI_PROTOCOL, PI_WARN,
"Field Termination Indicator set to 1 for last byte of option");
break;
}
val = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bitmask(field_tree, tvb, curr_offset, hf_ip_opt_sec_prot_auth_flags,
ett_ip_opt_sec_prot_auth_flags, ip_opt_sec_prot_auth_fields_byte_n,
ENC_BIG_ENDIAN);
curr_offset++;
}
if ((curr_offset - offset) < optlen) {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Extraneous data in option");
}
}
static void
dissect_ipopt_ext_security(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
proto_item *tf_sub;
guint curr_offset = offset;
gint remaining;
tf = proto_tree_add_text(opt_tree, tvb, curr_offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, curr_offset, field_tree);
curr_offset++;
tf_sub = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, curr_offset, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf_sub, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
curr_offset++;
proto_tree_add_item(field_tree, hf_ip_opt_ext_sec_add_sec_info_format_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
remaining = optlen - (curr_offset - offset);
if (remaining > 0) {
proto_tree_add_item(field_tree, hf_ip_opt_ext_sec_add_sec_info, tvb, curr_offset, remaining, ENC_NA);
}
}
static void
dissect_ipopt_cipso(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
guint tagtype, taglen;
int offset_max = offset + optlen;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
offset += 2;
proto_tree_add_text(field_tree, tvb, offset, 4, "DOI: %u",
tvb_get_ntohl(tvb, offset));
offset += 4;
while (offset < offset_max) {
tagtype = tvb_get_guint8(tvb, offset);
if ((offset + 1) < offset_max)
taglen = tvb_get_guint8(tvb, offset + 1);
else
taglen = 1;
switch (tagtype) {
case 0:
offset += 1;
continue;
case 1:
if ((taglen < 4) || (taglen > CIPSO_TAG_LEN_MAX) ||
((offset + (int)taglen - 1) > offset_max)) {
proto_tree_add_text(field_tree, tvb, offset, offset_max - offset,
"Malformed CIPSO tag");
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Restrictive Category Bitmap (%u)",
tagtype);
offset += 3;
proto_tree_add_text(field_tree, tvb, offset, 1, "Sensitivity Level: %u",
tvb_get_guint8(tvb, offset));
offset += 1;
if (taglen > 4) {
guint bit_spot = 0;
guint byte_spot = 0;
unsigned char bitmask;
char *cat_str;
char *cat_str_tmp = ep_alloc(USHRT_MAX_STRLEN);
size_t cat_str_len;
const guint8 *val_ptr = tvb_get_ptr(tvb, offset, taglen - 4);
cat_str_len = 256;
cat_str = ep_alloc0(cat_str_len);
while (byte_spot < (taglen - 4)) {
bitmask = 0x80;
bit_spot = 0;
while (bit_spot < 8) {
if (val_ptr[byte_spot] & bitmask) {
g_snprintf(cat_str_tmp, USHRT_MAX_STRLEN, "%u",
byte_spot * 8 + bit_spot);
if (cat_str_len < (strlen(cat_str) + 2 + USHRT_MAX_STRLEN)) {
char *cat_str_new;
while (cat_str_len < (strlen(cat_str) + 2 + USHRT_MAX_STRLEN))
cat_str_len += cat_str_len;
cat_str_new = ep_alloc(cat_str_len);
g_strlcpy(cat_str_new, cat_str, cat_str_len);
cat_str_new[cat_str_len - 1] = '\0';
cat_str = cat_str_new;
}
if (cat_str[0] != '\0')
g_strlcat(cat_str, ",", cat_str_len);
g_strlcat(cat_str, cat_str_tmp, cat_str_len);
}
bit_spot++;
bitmask >>= 1;
}
byte_spot++;
}
if (cat_str)
proto_tree_add_text(field_tree, tvb, offset, taglen - 4,
"Categories: %s", cat_str);
else
proto_tree_add_text(field_tree, tvb, offset, taglen - 4,
"Categories: ERROR PARSING CATEGORIES");
offset += taglen - 4;
}
break;
case 2:
if ((taglen < 4) || (taglen > CIPSO_TAG_LEN_MAX) ||
((offset + (int)taglen - 1) > offset_max)) {
proto_tree_add_text(field_tree, tvb, offset, offset_max - offset,
"Malformed CIPSO tag");
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Enumerated Categories (%u)", tagtype);
offset += 3;
proto_tree_add_text(field_tree, tvb, offset, 1, "Sensitivity Level: %u",
tvb_get_guint8(tvb, offset));
offset += 1;
if (taglen > 4) {
int offset_max_cat = offset + taglen - 4;
char *cat_str = ep_alloc0(USHRT_MAX_STRLEN * 15);
char *cat_str_tmp = ep_alloc(USHRT_MAX_STRLEN);
while ((offset + 2) <= offset_max_cat) {
g_snprintf(cat_str_tmp, USHRT_MAX_STRLEN, "%u",
tvb_get_ntohs(tvb, offset));
offset += 2;
if (cat_str[0] != '\0')
g_strlcat(cat_str, ",", USHRT_MAX_STRLEN * 15);
g_strlcat(cat_str, cat_str_tmp, USHRT_MAX_STRLEN * 15);
}
proto_tree_add_text(field_tree, tvb, offset - taglen + 4, taglen - 4,
"Categories: %s", cat_str);
}
break;
case 5:
if ((taglen < 4) || (taglen > CIPSO_TAG_LEN_MAX) ||
((offset + (int)taglen - 1) > offset_max)) {
proto_tree_add_text(field_tree, tvb, offset, offset_max - offset,
"Malformed CIPSO tag");
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Ranged Categories (%u)", tagtype);
offset += 3;
proto_tree_add_text(field_tree, tvb, offset, 1, "Sensitivity Level: %u",
tvb_get_guint8(tvb, offset));
offset += 1;
if (taglen > 4) {
guint16 cat_low, cat_high;
int offset_max_cat = offset + taglen - 4;
char *cat_str = ep_alloc0(USHRT_MAX_STRLEN * 16);
char *cat_str_tmp = ep_alloc(USHRT_MAX_STRLEN * 2);
while ((offset + 2) <= offset_max_cat) {
cat_high = tvb_get_ntohs(tvb, offset);
if ((offset + 4) <= offset_max_cat) {
cat_low = tvb_get_ntohs(tvb, offset + 2);
offset += 4;
} else {
cat_low = 0;
offset += 2;
}
if (cat_low != cat_high)
g_snprintf(cat_str_tmp, USHRT_MAX_STRLEN * 2, "%u-%u",
cat_high, cat_low);
else
g_snprintf(cat_str_tmp, USHRT_MAX_STRLEN * 2, "%u", cat_high);
if (cat_str[0] != '\0')
g_strlcat(cat_str, ",", USHRT_MAX_STRLEN * 16);
g_strlcat(cat_str, cat_str_tmp, USHRT_MAX_STRLEN * 16);
}
proto_tree_add_text(field_tree, tvb, offset - taglen + 4, taglen - 4,
"Categories: %s", cat_str);
}
break;
case 6:
if ((taglen < 4) || (taglen > CIPSO_TAG_LEN_MAX) ||
((offset + (int)taglen - 1) > offset_max)) {
proto_tree_add_text(field_tree, tvb, offset, offset_max - offset,
"Malformed CIPSO tag");
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Permissive Categories (%u)", tagtype);
proto_tree_add_text(field_tree, tvb, offset + 2, taglen - 2, "Tag data");
offset += taglen;
break;
case 7:
if ((taglen < 2) || (taglen > CIPSO_TAG_LEN_MAX) ||
((offset + (int)taglen - 1) > offset_max)) {
proto_tree_add_text(field_tree, tvb, offset, offset_max - offset,
"Malformed CIPSO tag");
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Free Form (%u)", tagtype);
proto_tree_add_text(field_tree, tvb, offset + 2, taglen - 2, "Tag data");
offset += taglen;
break;
default:
if ((offset + 1) <= offset_max) {
taglen = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Unknown (%u) (%u bytes)",
tagtype, taglen);
return;
}
proto_tree_add_text(field_tree, tvb, offset, 1,
"Tag Type: Unknown (%u) (invalid format)", tagtype);
return;
}
}
}
static void
dissect_option_route(proto_tree *tree, tvbuff_t *tvb, int offset, int hf,
int hf_host, gboolean next)
{
proto_item *ti;
guint32 route;
route = tvb_get_ipv4(tvb, offset);
if (next)
proto_tree_add_ipv4_format_value(tree, hf, tvb, offset, 4, route,
"%s <- (next)",
ip_to_str((gchar *)&route));
else
proto_tree_add_ipv4(tree, hf, tvb, offset, 4, route);
ti = proto_tree_add_string(tree, hf_host, tvb, offset, 4, get_hostname(route));
PROTO_ITEM_SET_GENERATED(ti);
PROTO_ITEM_SET_HIDDEN(ti);
}
static void
dissect_ipopt_route(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
guint8 len, ptr;
int optoffset = 0;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
ptr = tvb_get_guint8(tvb, offset + 2);
tf = proto_tree_add_item(field_tree, hf_ip_opt_ptr, tvb, offset + 2, 1, ENC_NA);
if ((ptr < (optp->optlen + 1)) || (ptr & 3)) {
if (ptr < (optp->optlen + 1)) {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Pointer points before first address");
}
else {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Pointer points to middle of address");
}
return;
}
len = optlen;
optoffset = 3;
for (optlen -= 3; optlen > 0; optlen -= 4, optoffset += 4) {
if (optlen < 4) {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Suboption would go past end of option");
break;
}
if (ptr > len) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_rec_rt,
hf_ip_rec_rt_host, FALSE);
} else if (optoffset == (len - 4)) {
proto_item *item;
guint32 addr;
const char *dst_host;
addr = tvb_get_ipv4(tvb, offset + optoffset);
dst_host = get_hostname(addr);
proto_tree_add_ipv4(field_tree, hf_ip_dst, tvb,
offset + optoffset, 4, addr);
item = proto_tree_add_ipv4(field_tree, hf_ip_addr, tvb,
offset + optoffset, 4, addr);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(field_tree, hf_ip_dst_host, tvb,
offset + optoffset, 4, dst_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(field_tree, hf_ip_host, tvb,
offset + optoffset, 4, dst_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
} else if ((optoffset + 1) < ptr) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_rec_rt,
hf_ip_rec_rt_host, FALSE);
} else if ((optoffset + 1) == ptr) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_src_rt,
hf_ip_src_rt_host, TRUE);
} else {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_src_rt,
hf_ip_src_rt_host, FALSE);
}
}
}
static void
dissect_ipopt_record_route(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo,
proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
guint8 len, ptr;
int optoffset = 0;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
ptr = tvb_get_guint8(tvb, offset + 2);
tf = proto_tree_add_item(field_tree, hf_ip_opt_ptr, tvb, offset + 2, 1, ENC_NA);
if ((ptr < (optp->optlen + 1)) || (ptr & 3)) {
if (ptr < (optp->optlen + 1)) {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Pointer points before first address");
}
else {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Pointer points to middle of address");
}
return;
}
len = optlen;
optoffset = 3;
for (optlen -= 3; optlen > 0; optlen -= 4, optoffset += 4) {
if (optlen < 4) {
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Suboption would go past end of option");
break;
}
if (ptr > len) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_rec_rt,
hf_ip_rec_rt_host, FALSE);
} else if ((optoffset + 1) < ptr) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_rec_rt,
hf_ip_rec_rt_host, FALSE);
} else if ((optoffset + 1) == ptr) {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_empty_rt,
hf_ip_empty_rt_host, TRUE);
} else {
dissect_option_route(field_tree, tvb, offset + optoffset, hf_ip_empty_rt,
hf_ip_empty_rt_host, FALSE);
}
}
}
static void
dissect_ipopt_sid(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes): %u",
optp->name, optlen, tvb_get_ntohs(tvb, offset + 2));
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen != (guint)optp->optlen)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
proto_tree_add_item(field_tree, hf_ip_opt_sid, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ipopt_mtu(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes): %u",
optp->name, optlen, tvb_get_ntohs(tvb, offset + 2));
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen != (guint)optp->optlen)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
proto_tree_add_item(field_tree, hf_ip_opt_mtu, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ipopt_tr(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen != (guint)optp->optlen)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
proto_tree_add_item(field_tree, hf_ip_opt_id_number, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ip_opt_ohc, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ip_opt_rhc, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_ip_opt_originator, tvb, offset + 8, 4, ENC_BIG_ENDIAN);
}
static void
dissect_ipopt_timestamp(const ip_tcp_opt *optp, tvbuff_t *tvb,
int offset, guint optlen, packet_info *pinfo,
proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
int ptr;
int optoffset = 0;
int flg;
static const value_string flag_vals[] = {
{IPOPT_TS_TSONLY, "Time stamps only" },
{IPOPT_TS_TSANDADDR, "Time stamp and address" },
{IPOPT_TS_PRESPEC, "Time stamps for prespecified addresses"},
{0, NULL }};
guint32 addr;
guint ts;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
optoffset += 2;
optlen -= 2;
ptr = tvb_get_guint8(tvb, offset + optoffset);
proto_tree_add_text(field_tree, tvb, offset + optoffset, 1, "Pointer: %d%s",
ptr, ((ptr == 1) ? " (header is full)" :
(ptr < 5) ? " (points before first address)" :
(((ptr - 1) & 3) ? " (points to middle of field)" : "")));
optoffset++;
optlen--;
ptr--;
flg = tvb_get_guint8(tvb, offset + optoffset);
proto_tree_add_text(field_tree, tvb, offset + optoffset, 1, "Overflow: %u",
flg >> 4);
flg &= 0xF;
proto_tree_add_text(field_tree, tvb, offset + optoffset, 1, "Flag: %s",
val_to_str(flg, flag_vals, "Unknown (0x%x)"));
optoffset++;
optlen--;
while (optlen > 0) {
if (flg == IPOPT_TS_TSANDADDR || flg == IPOPT_TS_PRESPEC) {
if (optlen < 8) {
proto_tree_add_text(field_tree, tvb, offset + optoffset, optlen,
"(suboption would go past end of option)");
break;
}
addr = tvb_get_ipv4(tvb, offset + optoffset);
ts = tvb_get_ntohl(tvb, offset + optoffset + 4);
optlen -= 8;
proto_tree_add_text(field_tree, tvb, offset + optoffset, 8,
"Address = %s, time stamp = %u",
((addr == 0) ? "-" :
get_hostname(addr)), ts);
optoffset += 8;
} else {
if (optlen < 4) {
proto_tree_add_text(field_tree, tvb, offset + optoffset, optlen,
"(suboption would go past end of option)");
break;
}
ts = tvb_get_ntohl(tvb, offset + optoffset);
optlen -= 4;
proto_tree_add_text(field_tree, tvb, offset + optoffset, 4,
"Time stamp = %u", ts);
optoffset += 4;
}
}
}
static void
dissect_ipopt_ra(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
guint16 value = tvb_get_ntohs(tvb, offset + 2);
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s (%u bytes): %s (%u)", optp->name, optlen,
rval_to_str(value, ra_rvals, "Unknown (%u)"),
value);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen != (guint)optp->optlen)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
proto_tree_add_item(field_tree, hf_ip_opt_ra, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
static void
dissect_ipopt_sdb(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen, "%s (%u bytes)",
optp->name, optlen);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
tf = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen > IPOLEN_MAX)
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
for (offset += 2, optlen -= 2; optlen >= 4; offset += 4, optlen -= 4)
proto_tree_add_item(field_tree, hf_ip_opt_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
if (optlen > 0)
proto_tree_add_item(field_tree, hf_ip_opt_padding, tvb, offset, optlen, ENC_NA);
}
static void
dissect_ipopt_qs(const ip_tcp_opt *optp, tvbuff_t *tvb, int offset,
guint optlen, packet_info *pinfo, proto_tree *opt_tree)
{
proto_tree *field_tree;
proto_item *tf;
proto_item *ti;
guint8 command = tvb_get_guint8(tvb, offset + 2);
guint8 function = command >> 4;
guint8 rate = command & QS_RATE_MASK;
guint8 ttl_diff;
tf = proto_tree_add_text(opt_tree, tvb, offset, optlen,
"%s (%u bytes): %s (%u)", optp->name, optlen,
val_to_str(function, qs_func_vals, "Unknown (%u)"),
function);
field_tree = proto_item_add_subtree(tf, *optp->subtree_index);
dissect_ipopt_type(tvb, offset, field_tree);
ti = proto_tree_add_item(field_tree, hf_ip_opt_len, tvb, offset + 1, 1, ENC_NA);
if (optlen != (guint)optp->optlen)
expert_add_info_format(pinfo, ti, PI_PROTOCOL, PI_WARN,
"Invalid length for option");
proto_tree_add_item(field_tree, hf_ip_opt_qs_func, tvb, offset + 2, 1, ENC_NA);
if (function == QS_RATE_REQUEST) {
proto_tree_add_item(field_tree, hf_ip_opt_qs_rate, tvb, offset + 2, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_opt_qs_ttl, tvb, offset + 3, 1, ENC_NA);
ttl_diff = (pinfo->ip_ttl - tvb_get_guint8(tvb, offset + 3) % 256);
ti = proto_tree_add_uint_format_value(field_tree, hf_ip_opt_qs_ttl_diff,
tvb, offset + 3, 1, ttl_diff,
"%u", ttl_diff);
PROTO_ITEM_SET_GENERATED(ti);
proto_item_append_text(tf, ", %s, QS TTL %u, QS TTL diff %u",
val_to_str_ext_const(rate, &qs_rate_vals_ext, "Unknown"),
tvb_get_guint8(tvb, offset + 3), ttl_diff);
proto_tree_add_item(field_tree, hf_ip_opt_qs_nonce, tvb, offset + 4, 4, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_opt_qs_reserved, tvb, offset + 4, 4, ENC_NA);
} else if (function == QS_RATE_REPORT) {
proto_tree_add_item(field_tree, hf_ip_opt_qs_rate, tvb, offset + 2, 1, ENC_NA);
proto_item_append_text(tf, ", %s",
val_to_str_ext_const(rate, &qs_rate_vals_ext, "Unknown (%u)"));
proto_tree_add_item(field_tree, hf_ip_opt_qs_unused, tvb, offset + 3, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_opt_qs_nonce, tvb, offset + 4, 4, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_opt_qs_reserved, tvb, offset + 4, 4, ENC_NA);
}
}
void
dissect_ip_tcp_options(tvbuff_t *tvb, int offset, guint length,
const ip_tcp_opt *opttab, int nopts, int eol,
packet_info *pinfo, proto_tree *opt_tree,
proto_item *opt_item)
{
guchar opt;
const ip_tcp_opt *optp;
opt_len_type len_type;
unsigned int optlen;
const char *name;
void (*dissect)(const struct ip_tcp_opt *, tvbuff_t *,
int, guint, packet_info *, proto_tree *);
guint len, nop_count = 0;
while (length > 0) {
opt = tvb_get_guint8(tvb, offset);
for (optp = &opttab[0]; optp < &opttab[nopts]; optp++) {
if (optp->optcode == opt)
break;
}
if (optp == &opttab[nopts]) {
optp = NULL;
len_type = VARIABLE_LENGTH;
optlen = 2;
name = ep_strdup_printf("Unknown (0x%02x)", opt);
dissect = NULL;
nop_count = 0;
} else {
len_type = optp->len_type;
optlen = optp->optlen;
name = optp->name;
dissect = optp->dissect;
if (opt_item && len_type == NO_LENGTH && optlen == 0 && opt == 1 &&
(nop_count == 0 || offset % 4)) {
nop_count++;
} else {
nop_count = 0;
}
}
--length;
if (len_type != NO_LENGTH) {
if (length == 0) {
proto_tree_add_text(opt_tree, tvb, offset, 1,
"%s (length byte past end of options)", name);
return;
}
len = tvb_get_guint8(tvb, offset + 1);
--length;
if (len < 2) {
proto_tree_add_text(opt_tree, tvb, offset, 2,
"%s (with too-short option length = %u byte%s)",
name, len, plurality(len, "", "s"));
return;
} else if (len - 2 > length) {
proto_tree_add_text(opt_tree, tvb, offset, length,
"%s (option length = %u byte%s says option goes "
"past end of options)",
name, len, plurality(len, "", "s"));
return;
} else if (len_type == FIXED_LENGTH && len != optlen) {
proto_tree_add_text(opt_tree, tvb, offset, len,
"%s (with option length = %u byte%s; should be %u)",
name, len, plurality(len, "", "s"), optlen);
return;
} else if (len_type == VARIABLE_LENGTH && len < optlen) {
proto_tree_add_text(opt_tree, tvb, offset, len,
"%s (with option length = %u byte%s; "
"should be >= %u)",
name, len, plurality(len, "", "s"), optlen);
return;
} else {
if (optp == NULL) {
proto_tree_add_text(opt_tree, tvb, offset, len, "%s (%u byte%s)",
name, len, plurality(len, "", "s"));
} else {
if (dissect != NULL) {
proto_item_append_text(proto_tree_get_parent(opt_tree), ", %s",
optp->name);
(*dissect)(optp, tvb, offset, len, pinfo, opt_tree);
} else {
proto_tree *field_tree;
proto_item *tf;
proto_item_append_text(proto_tree_get_parent(opt_tree), ", %s",
name);
tf = proto_tree_add_text(opt_tree, tvb, offset, len, "%s", name);
field_tree = proto_item_add_subtree(tf, ett_ip_option_other);
dissect_ipopt_type(tvb, offset, field_tree);
}
}
len -= 2;
offset += 2 + len;
}
length -= len;
} else {
if (dissect != NULL) {
proto_item_append_text(proto_tree_get_parent(opt_tree), ", %s",
optp->name);
(*dissect)(optp, tvb, offset, 1, pinfo, opt_tree);
} else {
proto_tree *field_tree;
proto_item *tf;
proto_item_append_text(proto_tree_get_parent(opt_tree), ", %s", name);
tf = proto_tree_add_text(opt_tree, tvb, offset, 1, "%s", name);
field_tree = proto_item_add_subtree(tf, ett_ip_option_other);
dissect_ipopt_type(tvb, offset, field_tree);
}
offset += 1;
if (nop_count == 4 && strcmp (name, "No-Operation (NOP)") == 0) {
expert_add_info_format(pinfo, opt_item, PI_PROTOCOL, PI_WARN,
"4 NOP in a row - a router may have removed "
"some options");
}
}
if (opt == eol)
break;
}
}
static int
get_dst_offset(tvbuff_t *tvb, int offset, guint length,
const ip_tcp_opt *opttab, int nopts, int eol)
{
guchar opt;
const ip_tcp_opt *optp;
opt_len_type len_type;
unsigned int optlen;
guint len;
int orig_offset = offset;
while (length > 0) {
opt = tvb_get_guint8(tvb, offset);
for (optp = &opttab[0]; optp < &opttab[nopts]; optp++) {
if (optp->optcode == opt)
break;
}
if (optp == &opttab[nopts]) {
optp = NULL;
len_type = VARIABLE_LENGTH;
optlen = 2;
} else {
len_type = optp->len_type;
optlen = optp->optlen;
}
--length;
if (len_type != NO_LENGTH) {
if (length == 0) {
return 0;
}
len = tvb_get_guint8(tvb, offset + 1);
--length;
if (len < 2) {
return 0;
} else if (len - 2 > length) {
return 0;
} else if (len_type == FIXED_LENGTH && len != optlen) {
return 0;
} else if (len_type == VARIABLE_LENGTH && len < optlen) {
return 0;
} else {
if (optp != NULL) {
if (opt == IPOPT_SSR || opt == IPOPT_LSR) {
guint8 ptr;
ptr = tvb_get_guint8(tvb, offset + 2);
if (ptr < 4 || (ptr & 3) || (ptr > len)) {
return 0;
}
return (offset - orig_offset) + 4 + (len - 4);
}
}
len -= 2;
offset += 2 + len;
}
length -= len;
} else {
offset += 1;
}
if (opt == eol)
return 0;
}
return 0;
}
static guint16
local_network_control_block_addr_valid_ttl(guint32 addr)
{
if (IPLOCAL_NETWRK_CTRL_BLK_VRRP_ADDR == addr)
return IPLOCAL_NETWRK_CTRL_BLK_VRRP_TTL;
if (IPLOCAL_NETWRK_CTRL_BLK_GLPB_ADDR == addr)
return IPLOCAL_NETWRK_CTRL_BLK_GLPB_TTL;
if (IPLOCAL_NETWRK_CTRL_BLK_MDNS_ADDR == addr)
return IPLOCAL_NETWRK_CTRL_BLK_MDNS_TTL;
if (IPLOCAL_NETWRK_CTRL_BLK_LLMNR_ADDR == addr)
return IPLOCAL_NETWRK_CTRL_BLK_ANY_TTL;
return IPLOCAL_NETWRK_CTRL_BLK_DEFAULT_TTL;
}
guint16
ip_checksum(const guint8 *ptr, int len)
{
vec_t cksum_vec[1];
cksum_vec[0].ptr = ptr;
cksum_vec[0].len = len;
return in_cksum(&cksum_vec[0], 1);
}
static void
dissect_ip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
proto_tree *ip_tree = NULL, *field_tree = NULL;
proto_item *ti = NULL, *tf;
guint32 addr;
int offset = 0, dst_off;
guint hlen, optlen;
guint16 flags;
guint8 nxt;
guint16 ipsum;
fragment_data *ipfd_head = NULL;
tvbuff_t *next_tvb;
gboolean update_col_info = TRUE;
gboolean save_fragmented;
ws_ip *iph;
const guchar *src_addr, *dst_addr;
guint32 src32, dst32;
proto_tree *tree;
proto_item *item = NULL, *ttl_item;
proto_tree *checksum_tree;
guint16 ttl;
tree = parent_tree;
iph = ep_alloc(sizeof(ws_ip));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPv4");
col_clear(pinfo->cinfo, COL_INFO);
iph->ip_v_hl = tvb_get_guint8(tvb, offset);
if ( hi_nibble(iph->ip_v_hl) == 6) {
call_dissector(ipv6_handle, tvb, pinfo, parent_tree);
return;
}
hlen = lo_nibble(iph->ip_v_hl) * 4;
if (tree) {
ti = proto_tree_add_item(tree, proto_ip, tvb, offset, hlen, ENC_NA);
ip_tree = proto_item_add_subtree(ti, ett_ip);
proto_tree_add_uint(ip_tree, hf_ip_version, tvb, offset, 1,
hi_nibble(iph->ip_v_hl));
}
if (!proto_field_is_referenced(parent_tree, proto_ip)) {
tree = NULL;
}
if (hlen < IPH_MIN_LEN) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Bogus IP header length (%u, must be at least %u)",
hlen, IPH_MIN_LEN);
if (tree) {
proto_tree_add_uint_format(ip_tree, hf_ip_hdr_len, tvb, offset, 1, hlen,
"Header length: %u bytes (bogus, must be "
"at least %u)", hlen, IPH_MIN_LEN);
}
return;
}
if (tree) {
proto_tree_add_uint_format(ip_tree, hf_ip_hdr_len, tvb, offset, 1, hlen,
"Header length: %u bytes", hlen);
}
iph->ip_tos = tvb_get_guint8(tvb, offset + 1);
if (g_ip_dscp_actif) {
col_add_fstr(pinfo->cinfo, COL_DSCP_VALUE, "%u",
IPDSFIELD_DSCP(iph->ip_tos));
}
if (tree) {
if (g_ip_dscp_actif) {
tf = proto_tree_add_uint_format(ip_tree, hf_ip_dsfield, tvb, offset + 1,
1, iph->ip_tos, "Differentiated Services Field: 0x%02x "
"(DSCP 0x%02x: %s; ECN: 0x%02x: %s)", iph->ip_tos,
IPDSFIELD_DSCP(iph->ip_tos), val_to_str_ext_const(IPDSFIELD_DSCP(iph->ip_tos),
&dscp_vals_ext, "Unknown DSCP"),
IPDSFIELD_ECN(iph->ip_tos), val_to_str_const(IPDSFIELD_ECN(iph->ip_tos),
ecn_vals, "Unknown ECN"));
field_tree = proto_item_add_subtree(tf, ett_ip_dsfield);
proto_tree_add_item(field_tree, hf_ip_dsfield_dscp, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_dsfield_ecn, tvb, offset + 1, 1, ENC_NA);
} else {
tf = proto_tree_add_uint_format(ip_tree, hf_ip_tos, tvb, offset + 1, 1,
iph->ip_tos,
"Type of service: 0x%02x (%s)",
iph->ip_tos,
val_to_str_const(IPTOS_TOS(iph->ip_tos),
iptos_vals, "Unknown"));
field_tree = proto_item_add_subtree(tf, ett_ip_tos);
proto_tree_add_item(field_tree, hf_ip_tos_precedence, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_tos_delay, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_tos_throughput, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_tos_reliability, tvb, offset + 1, 1, ENC_NA);
proto_tree_add_item(field_tree, hf_ip_tos_cost, tvb, offset + 1, 1, ENC_NA);
}
}
iph->ip_len = tvb_get_ntohs(tvb, offset + 2);
if (ip_tso_supported && !iph->ip_len)
iph->ip_len = tvb_reported_length(tvb);
if (iph->ip_len < hlen) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Bogus IP length (%u, less than header length %u)",
iph->ip_len, hlen);
if (tree) {
if (!iph->ip_len) {
tf = proto_tree_add_uint_format(ip_tree, hf_ip_len, tvb, offset + 2, 2,
iph->ip_len,
"Total length: 0 bytes (may be caused by \"TCP segmentation offload\" (TSO)?)");
} else {
tf = proto_tree_add_uint_format(ip_tree, hf_ip_len, tvb, offset + 2, 2,
iph->ip_len,
"Total length: %u bytes (bogus, less than header length %u)",
iph->ip_len, hlen);
}
expert_add_info_format(pinfo, tf, PI_PROTOCOL, PI_ERROR, "Bogus IP length");
}
return;
}
set_actual_length(tvb, iph->ip_len);
if (tree)
proto_tree_add_uint(ip_tree, hf_ip_len, tvb, offset + 2, 2, iph->ip_len);
iph->ip_id = tvb_get_ntohs(tvb, offset + 4);
if (tree)
proto_tree_add_uint(ip_tree, hf_ip_id, tvb, offset + 4, 2, iph->ip_id);
iph->ip_off = tvb_get_ntohs(tvb, offset + 6);
if (tree) {
int bit_offset = (offset + 6) * 8;
flags = (iph->ip_off & (IP_RF | IP_DF | IP_MF)) >> IP_OFFSET_WIDTH;
tf = proto_tree_add_uint(ip_tree, hf_ip_flags, tvb, offset + 6, 1, flags);
field_tree = proto_item_add_subtree(tf, ett_ip_off);
if (ip_security_flag) {
proto_item *sf;
sf = proto_tree_add_bits_item(field_tree, hf_ip_flags_sf, tvb,
bit_offset + 0, 1, ENC_BIG_ENDIAN);
if (iph->ip_off & IP_RF) {
proto_item_append_text(tf, " (Evil packet!)");
expert_add_info_format(pinfo, sf, PI_SECURITY, PI_WARN,
"This is an Evil packet (RFC 3514)");
}
} else {
proto_tree_add_bits_item(field_tree, hf_ip_flags_rf, tvb, bit_offset + 0,
1, ENC_LITTLE_ENDIAN);
}
if (iph->ip_off & IP_DF)
proto_item_append_text(tf, " (Don't Fragment)");
proto_tree_add_bits_item(field_tree, hf_ip_flags_df, tvb, bit_offset + 1,
1, ENC_BIG_ENDIAN);
if (iph->ip_off & IP_MF)
proto_item_append_text(tf, " (More Fragments)");
proto_tree_add_bits_item(field_tree, hf_ip_flags_mf, tvb, bit_offset + 2,
1, ENC_BIG_ENDIAN);
proto_tree_add_uint(ip_tree, hf_ip_frag_offset, tvb, offset + 6, 2,
(iph->ip_off & IP_OFFSET)*8);
}
iph->ip_ttl = tvb_get_guint8(tvb, offset + 8);
pinfo->ip_ttl = iph->ip_ttl;
if (tree) {
ttl_item = proto_tree_add_item(ip_tree, hf_ip_ttl, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
} else {
ttl_item = NULL;
}
iph->ip_p = tvb_get_guint8(tvb, offset + 9);
if (tree) {
proto_tree_add_item(ip_tree, hf_ip_proto, tvb, offset + 9, 1, ENC_BIG_ENDIAN);
}
iph->ip_sum = tvb_get_ntohs(tvb, offset + 10);
if (ip_check_checksum && tvb_bytes_exist(tvb, offset, hlen)) {
ipsum = ip_checksum(tvb_get_ptr(tvb, offset, hlen), hlen);
if (tree) {
if (ipsum == 0) {
item = proto_tree_add_uint_format(ip_tree, hf_ip_checksum, tvb,
offset + 10, 2, iph->ip_sum,
"Header checksum: 0x%04x [correct]",
iph->ip_sum);
checksum_tree = proto_item_add_subtree(item, ett_ip_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_good, tvb,
offset + 10, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_bad, tvb,
offset + 10, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
} else {
item = proto_tree_add_uint_format(ip_tree, hf_ip_checksum, tvb,
offset + 10, 2, iph->ip_sum,
"Header checksum: 0x%04x "
"[incorrect, should be 0x%04x "
"(may be caused by \"IP checksum "
"offload\"?)]", iph->ip_sum,
in_cksum_shouldbe(iph->ip_sum,
ipsum));
checksum_tree = proto_item_add_subtree(item, ett_ip_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_good, tvb,
offset + 10, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_bad, tvb,
offset + 10, 2, TRUE);
PROTO_ITEM_SET_GENERATED(item);
}
}
if (ipsum != 0) {
expert_add_info_format(pinfo, item, PI_CHECKSUM, PI_ERROR,
"Bad checksum");
}
} else {
ipsum = 0;
if (tree) {
item = proto_tree_add_uint_format(ip_tree, hf_ip_checksum, tvb,
offset + 10, 2, iph->ip_sum,
"Header checksum: 0x%04x [%s]",
iph->ip_sum, ip_check_checksum ?
"not all data available" :
"validation disabled");
checksum_tree = proto_item_add_subtree(item, ett_ip_checksum);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_good, tvb,
offset + 10, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
item = proto_tree_add_boolean(checksum_tree, hf_ip_checksum_bad, tvb,
offset + 10, 2, FALSE);
PROTO_ITEM_SET_GENERATED(item);
}
}
src_addr = tvb_get_ptr(tvb, offset + IPH_SRC, 4);
src32 = tvb_get_ntohl(tvb, offset + IPH_SRC);
SET_ADDRESS(&pinfo->net_src, AT_IPv4, 4, src_addr);
SET_ADDRESS(&pinfo->src, AT_IPv4, 4, src_addr);
SET_ADDRESS(&iph->ip_src, AT_IPv4, 4, src_addr);
if (tree) {
const char *src_host;
memcpy(&addr, iph->ip_src.data, 4);
src_host = get_hostname(addr);
if (ip_summary_in_tree) {
proto_item_append_text(ti, ", Src: %s (%s)", src_host,
ip_to_str(iph->ip_src.data));
}
proto_tree_add_ipv4(ip_tree, hf_ip_src, tvb, offset + 12, 4, addr);
item = proto_tree_add_ipv4(ip_tree, hf_ip_addr, tvb, offset + 12, 4, addr);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(ip_tree, hf_ip_src_host, tvb, offset + 12, 4,
src_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(ip_tree, hf_ip_host, tvb, offset + 12, 4,
src_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
}
if (hlen > IPH_MIN_LEN) {
dst_off = get_dst_offset(tvb, offset + 20, hlen - IPH_MIN_LEN, ipopts,
N_IP_OPTS, IPOPT_EOOL);
}
else
dst_off = 0;
dst_addr = tvb_get_ptr(tvb, offset + IPH_DST + dst_off, 4);
dst32 = tvb_get_ntohl(tvb, offset + IPH_DST + dst_off);
SET_ADDRESS(&pinfo->net_dst, AT_IPv4, 4, dst_addr);
SET_ADDRESS(&pinfo->dst, AT_IPv4, 4, dst_addr);
SET_ADDRESS(&iph->ip_dst, AT_IPv4, 4, dst_addr);
if (is_a_local_network_control_block_addr(dst32)) {
ttl = local_network_control_block_addr_valid_ttl(dst32);
if (ttl != iph->ip_ttl && ttl != IPLOCAL_NETWRK_CTRL_BLK_ANY_TTL) {
expert_add_info_format(pinfo, ttl_item, PI_SEQUENCE, PI_NOTE,
"\"Time To Live\" != %d for a packet sent to the "
"Local Network Control Block (see RFC 3171)",
ttl);
}
} else if (!is_a_multicast_addr(dst32) && iph->ip_ttl < 5 &&
(iph->ip_p != IP_PROTO_PIM)) {
expert_add_info_format(pinfo, ttl_item, PI_SEQUENCE, PI_NOTE,
"\"Time To Live\" only %u", iph->ip_ttl);
}
if (tree) {
const char *dst_host;
guint32 cur_rt;
memcpy(&addr, iph->ip_dst.data, 4);
dst_host = get_hostname(addr);
if (dst_off)
cur_rt = tvb_get_ipv4(tvb, offset + 16);
if (ip_summary_in_tree) {
proto_item_append_text(ti, ", Dst: %s (%s)", dst_host,
ip_to_str(iph->ip_dst.data));
if (dst_off)
proto_item_append_text(ti, ", Via: %s (%s)", get_hostname(cur_rt),
ip_to_str((gchar *)&cur_rt));
}
if (dst_off) {
proto_tree_add_ipv4(ip_tree, hf_ip_cur_rt, tvb, offset + 16, 4, cur_rt);
item = proto_tree_add_string(ip_tree, hf_ip_cur_rt_host, tvb,
offset + 16, 4, get_hostname(cur_rt));
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
}
else {
proto_tree_add_ipv4(ip_tree, hf_ip_dst, tvb, offset + 16, 4, addr);
item = proto_tree_add_ipv4(ip_tree, hf_ip_addr, tvb, offset + 16, 4,
addr);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(ip_tree, hf_ip_dst_host, tvb, offset + 16,
4, dst_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
item = proto_tree_add_string(ip_tree, hf_ip_host, tvb,
offset + 16 + dst_off, 4, dst_host);
PROTO_ITEM_SET_GENERATED(item);
PROTO_ITEM_SET_HIDDEN(item);
}
}
#ifdef HAVE_GEOIP
if (tree && ip_use_geoip) {
add_geoip_info(ip_tree, tvb, offset, src32, dst32);
}
#endif
if (hlen > IPH_MIN_LEN) {
optlen = hlen - IPH_MIN_LEN;
tf = proto_tree_add_text(ip_tree, tvb, offset + 20, optlen,
"Options: (%u bytes)", optlen);
field_tree = proto_item_add_subtree(tf, ett_ip_options);
dissect_ip_tcp_options(tvb, offset + 20, optlen, ipopts, N_IP_OPTS,
IPOPT_EOOL, pinfo, field_tree, tf);
}
pinfo->ipproto = iph->ip_p;
pinfo->iplen = iph->ip_len;
pinfo->iphdrlen = hlen;
tap_queue_packet(ip_tap, pinfo, iph);
offset += hlen;
nxt = iph->ip_p;
save_fragmented = pinfo->fragmented;
if (ip_defragment && (iph->ip_off & (IP_MF|IP_OFFSET)) &&
tvb_bytes_exist(tvb, offset, pinfo->iplen - pinfo->iphdrlen) &&
ipsum == 0) {
ipfd_head = fragment_add_check(tvb, offset, pinfo,
iph->ip_p ^ iph->ip_id ^ src32 ^ dst32,
ip_fragment_table, ip_reassembled_table,
(iph->ip_off & IP_OFFSET) * 8,
pinfo->iplen - pinfo->iphdrlen,
iph->ip_off & IP_MF);
next_tvb = process_reassembled_data(tvb, offset, pinfo, "Reassembled IPv4",
ipfd_head, &ip_frag_items,
&update_col_info, ip_tree);
} else {
if (iph->ip_off & IP_OFFSET) {
next_tvb = NULL;
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (iph->ip_off & IP_MF)
pinfo->fragmented = TRUE;
else
pinfo->fragmented = FALSE;
}
}
if (next_tvb == NULL) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Fragmented IP protocol (proto=%s %u, off=%u, ID=%04x)",
ipprotostr(iph->ip_p), iph->ip_p,
(iph->ip_off & IP_OFFSET) * 8, iph->ip_id);
if ( ipfd_head && ipfd_head->reassembled_in != pinfo->fd->num ) {
col_append_fstr(pinfo->cinfo, COL_INFO, " [Reassembled in #%u]",
ipfd_head->reassembled_in);
}
call_dissector(data_handle, tvb_new_subset_remaining(tvb, offset), pinfo,
parent_tree);
pinfo->fragmented = save_fragmented;
return;
}
if (nxt == IP_PROTO_IPIP && (tvb_get_guint8(next_tvb, 0) & 0xF0) != 0x40 &&
tvb_get_ntohs(next_tvb, 2) < 20) {
call_dissector(tapa_handle,next_tvb, pinfo, parent_tree);
} else if (!dissector_try_uint(ip_dissector_table, nxt, next_tvb, pinfo,
parent_tree)) {
if (update_col_info) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s (%u)",
ipprotostr(iph->ip_p), iph->ip_p);
}
call_dissector(data_handle,next_tvb, pinfo, parent_tree);
}
pinfo->fragmented = save_fragmented;
}
void
proto_register_ip(void)
{
#define ARG_TO_STR(ARG) #ARG
#define FLAGS_OFFSET_WIDTH_MSG(WIDTH) \
"Flags (" ARG_TO_STR(WIDTH) " bits)"
#define FRAG_OFFSET_WIDTH_MSG(WIDTH) \
"Fragment offset (" ARG_TO_STR(WIDTH) " bits)"
static hf_register_info hf[] = {
{ &hf_ip_version,
{ "Version", "ip.version", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_hdr_len,
{ "Header Length", "ip.hdr_len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_dsfield,
{ "Differentiated Services field", "ip.dsfield", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_dsfield_dscp,
{ "Differentiated Services Codepoint", "ip.dsfield.dscp", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&dscp_vals_ext, IPDSFIELD_DSCP_MASK, NULL, HFILL }},
{ &hf_ip_dsfield_ecn,
{ "Explicit Congestion Notification", "ip.dsfield.ecn", FT_UINT8, BASE_HEX,
VALS(ecn_vals), IPDSFIELD_ECN_MASK, NULL, HFILL }},
{ &hf_ip_tos,
{ "Type of Service", "ip.tos", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_tos_precedence,
{ "Precedence", "ip.tos.precedence", FT_UINT8, BASE_DEC,
VALS(precedence_vals), IPTOS_PREC_MASK, NULL, HFILL }},
{ &hf_ip_tos_delay,
{ "Delay", "ip.tos.delay", FT_BOOLEAN, 8,
TFS(&tos_set_low), IPTOS_LOWDELAY, NULL, HFILL }},
{ &hf_ip_tos_throughput,
{ "Throughput", "ip.tos.throughput", FT_BOOLEAN, 8,
TFS(&tos_set_high), IPTOS_THROUGHPUT, NULL, HFILL }},
{ &hf_ip_tos_reliability,
{ "Reliability", "ip.tos.reliability", FT_BOOLEAN, 8,
TFS(&tos_set_high), IPTOS_RELIABILITY, NULL, HFILL }},
{ &hf_ip_tos_cost,
{ "Cost", "ip.tos.cost", FT_BOOLEAN, 8,
TFS(&tos_set_low), IPTOS_LOWCOST, NULL, HFILL }},
{ &hf_ip_len,
{ "Total Length", "ip.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_id,
{ "Identification", "ip.id", FT_UINT16, BASE_HEX_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_dst,
{ "Destination", "ip.dst", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_dst_host,
{ "Destination Host", "ip.dst_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_src,
{ "Source", "ip.src", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_src_host,
{ "Source Host", "ip.src_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_addr,
{ "Source or Destination Address", "ip.addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_host,
{ "Source or Destination Host", "ip.host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
#ifdef HAVE_GEOIP
{ &hf_geoip_country,
{ "Source or Destination GeoIP Country", "ip.geoip.country",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_city,
{ "Source or Destination GeoIP City", "ip.geoip.city",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_org,
{ "Source or Destination GeoIP Organization", "ip.geoip.org",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_isp,
{ "Source or Destination GeoIP ISP", "ip.geoip.isp",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_asnum,
{ "Source or Destination GeoIP AS Number", "ip.geoip.asnum",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_lat,
{ "Source or Destination GeoIP Latitude", "ip.geoip.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_lon,
{ "Source or Destination GeoIP Longitude", "ip.geoip.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_country,
{ "Source GeoIP Country", "ip.geoip.src_country",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_city,
{ "Source GeoIP City", "ip.geoip.src_city",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_org,
{ "Source GeoIP Organization", "ip.geoip.src_org",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_isp,
{ "Source GeoIP ISP", "ip.geoip.src_isp",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_asnum,
{ "Source GeoIP AS Number", "ip.geoip.src_asnum",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_lat,
{ "Source GeoIP Latitude", "ip.geoip.src_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_src_lon,
{ "Source GeoIP Longitude", "ip.geoip.src_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_country,
{ "Destination GeoIP Country", "ip.geoip.dst_country",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_city,
{ "Destination GeoIP City", "ip.geoip.dst_city",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_org,
{ "Destination GeoIP Organization", "ip.geoip.dst_org",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_isp,
{ "Destination GeoIP ISP", "ip.geoip.dst_isp",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_asnum,
{ "Destination GeoIP AS Number", "ip.geoip.dst_asnum",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_lat,
{ "Destination GeoIP Latitude", "ip.geoip.dst_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_geoip_dst_lon,
{ "Destination GeoIP Longitude", "ip.geoip.dst_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
#endif
{ &hf_ip_flags,
{ "Flags", "ip.flags", FT_UINT8, BASE_HEX,
NULL, 0x0, FLAGS_OFFSET_WIDTH_MSG(IP_FLAGS_WIDTH), HFILL }},
{ &hf_ip_flags_sf,
{ "Security flag", "ip.flags.sf", FT_BOOLEAN, BASE_NONE,
TFS(&flags_sf_set_evil), 0x0, "Security flag (RFC 3514)", HFILL }},
{ &hf_ip_flags_rf,
{ "Reserved bit", "ip.flags.rb", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_set_notset), 0x0, NULL, HFILL }},
{ &hf_ip_flags_df,
{ "Don't fragment", "ip.flags.df", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_set_notset), 0x0, NULL, HFILL }},
{ &hf_ip_flags_mf,
{ "More fragments", "ip.flags.mf", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_set_notset), 0x0, NULL, HFILL }},
{ &hf_ip_frag_offset,
{ "Fragment offset", "ip.frag_offset", FT_UINT16, BASE_DEC,
NULL, 0x0, FRAG_OFFSET_WIDTH_MSG(IP_OFFSET_WIDTH), HFILL }},
{ &hf_ip_ttl,
{ "Time to live", "ip.ttl", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_proto,
{ "Protocol", "ip.proto", FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&ipproto_val_ext, 0x0, NULL, HFILL }},
{ &hf_ip_checksum,
{ "Header checksum", "ip.checksum", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_checksum_good,
{ "Good", "ip.checksum_good", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_ip_checksum_bad,
{ "Bad", "ip.checksum_bad", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"True: checksum doesn't match packet content; False: matches content or not checked", HFILL }},
{ &hf_ip_opt_type,
{ "Type", "ip.opt.type", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_type_copy,
{ "Copy on fragmentation", "ip.opt.type.copy", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), IPOPT_COPY_MASK, NULL, HFILL }},
{ &hf_ip_opt_type_class,
{ "Class", "ip.opt.type.class", FT_UINT8, BASE_DEC,
VALS(ipopt_type_class_vals), IPOPT_CLASS_MASK, NULL, HFILL }},
{ &hf_ip_opt_type_number,
{ "Number", "ip.opt.type.number", FT_UINT8, BASE_DEC,
VALS(ipopt_type_number_vals), IPOPT_NUMBER_MASK, NULL, HFILL }},
{ &hf_ip_opt_len,
{ "Length", "ip.opt.len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_ptr,
{ "Pointer", "ip.opt.ptr", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_sid,
{ "Stream Identifier", "ip.opt.sid", FT_UINT16, BASE_DEC,
NULL, 0x0, "SATNET stream identifier", HFILL }},
{ &hf_ip_opt_mtu,
{ "MTU", "ip.opt.mtu", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_id_number,
{ "ID Number", "ip.opt.id_number", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_ohc,
{ "Outbound Hop Count", "ip.opt.ohc", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_rhc,
{ "Return Hop Count", "ip.opt.rhc", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_originator,
{ "Originator IP Address", "ip.opt.originator", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_ra,
{ "Router Alert", "ip.opt.ra", FT_UINT16, BASE_DEC | BASE_RANGE_STRING,
RVALS(ra_rvals), 0x0, NULL, HFILL }},
{ &hf_ip_opt_addr,
{ "IP Address", "ip.opt.addr", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_padding,
{ "Padding", "ip.opt.padding", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_qs_func,
{ "Function", "ip.opt.qs_func", FT_UINT8, BASE_DEC,
VALS(qs_func_vals), QS_FUNC_MASK, NULL, HFILL }},
{ &hf_ip_opt_qs_rate,
{ "Rate", "ip.opt.qs_rate", FT_UINT8, BASE_DEC | BASE_EXT_STRING,
&qs_rate_vals_ext, QS_RATE_MASK, NULL, HFILL }},
{ &hf_ip_opt_qs_ttl,
{ "QS TTL", "ip.opt.qs_ttl", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_qs_ttl_diff,
{ "TTL Diff", "ip.opt.qs_ttl_diff", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_qs_unused,
{ "Not Used", "ip.opt.qs_unused", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_qs_nonce,
{ "QS Nonce", "ip.opt.qs_nonce", FT_UINT32, BASE_HEX,
NULL, 0xFFFFFFFC, NULL, HFILL }},
{ &hf_ip_opt_qs_reserved,
{ "Reserved", "ip.opt.qs_reserved", FT_UINT32, BASE_HEX,
NULL, 0x00000003, NULL, HFILL }},
{ &hf_ip_opt_sec_rfc791_sec,
{ "Security", "ip.opt.sec_rfc791_sec", FT_UINT8, BASE_HEX,
VALS(secl_rfc791_vals), 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_rfc791_comp,
{ "Compartments", "ip.opt.sec_rfc791_comp", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_rfc791_hr,
{ "Handling Restrictions", "ip.opt.sec_rfc791_hr", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_rfc791_tcc,
{ "Transmission Control Code", "ip.opt.sec_rfc791_tcc", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_cl,
{ "Classification Level", "ip.opt.sec_cl", FT_UINT8, BASE_HEX,
VALS(sec_cl_vals), 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_flags,
{ "Protection Authority Flags", "ip.opt.sec_prot_auth_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_genser,
{ "GENSER", "ip.opt.sec_prot_auth_genser", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_flag_tfs), 0x80, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_siop_esi,
{ "SIOP-ESI", "ip.opt.sec_prot_auth_siop_esi", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_flag_tfs), 0x40, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_sci,
{ "SCI", "ip.opt.sec_prot_auth_sci", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_flag_tfs), 0x20, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_nsa,
{ "NSA", "ip.opt.sec_prot_auth_nsa", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_flag_tfs), 0x10, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_doe,
{ "DOE", "ip.opt.sec_prot_auth_doe", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_flag_tfs), 0x08, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_unassigned,
{ "Unassigned", "ip.opt.sec_prot_auth_unassigned", FT_UINT8, BASE_HEX,
NULL, 0x06, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_unassigned2,
{ "Unassigned", "ip.opt.sec_prot_auth_unassigned", FT_UINT8, BASE_HEX,
NULL, 0xFE, NULL, HFILL }},
{ &hf_ip_opt_sec_prot_auth_fti,
{ "Field Termination Indicator", "ip.opt.sec_prot_auth_fti", FT_BOOLEAN, 8,
TFS(&ip_opt_sec_prot_auth_fti_tfs), 0x01, NULL, HFILL }},
{ &hf_ip_opt_ext_sec_add_sec_info_format_code,
{ "Additional Security Info Format Code", "ip.opt.ext_sec_add_sec_info_format_code", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_opt_ext_sec_add_sec_info,
{ "Additional Security Info", "ip.opt.ext_sec_add_sec_info", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_rec_rt,
{ "Recorded Route", "ip.rec_rt", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ip_rec_rt_host,
{ "Recorded Route Host", "ip.rec_rt_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_cur_rt,
{ "Current Route", "ip.cur_rt", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ip_cur_rt_host,
{ "Current Route Host", "ip.cur_rt_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_src_rt,
{ "Source Route", "ip.src_rt", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ip_src_rt_host,
{ "Source Route Host", "ip.src_rt_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_empty_rt,
{ "Empty Route", "ip.empty_rt", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ip_empty_rt_host,
{ "Empty Route Host", "ip.empty_rt_host", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_fragment_overlap,
{ "Fragment overlap", "ip.fragment.overlap", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "Fragment overlaps with other fragments", HFILL }},
{ &hf_ip_fragment_overlap_conflict,
{ "Conflicting data in fragment overlap", "ip.fragment.overlap.conflict",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_ip_fragment_multiple_tails,
{ "Multiple tail fragments found", "ip.fragment.multipletails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_ip_fragment_too_long_fragment,
{ "Fragment too long", "ip.fragment.toolongfragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_ip_fragment_error,
{ "Defragmentation error", "ip.fragment.error", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "Defragmentation error due to illegal fragments", HFILL }},
{ &hf_ip_fragment_count,
{ "Fragment count", "ip.fragment.count", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_fragment,
{ "IPv4 Fragment", "ip.fragment", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_fragments,
{ "IPv4 Fragments", "ip.fragments", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_ip_reassembled_in,
{ "Reassembled IPv4 in frame", "ip.reassembled_in", FT_FRAMENUM, BASE_NONE,
NULL, 0x0, "This IPv4 packet is reassembled in this frame", HFILL }},
{ &hf_ip_reassembled_length,
{ "Reassembled IPv4 length", "ip.reassembled.length", FT_UINT32, BASE_DEC,
NULL, 0x0, "The total length of the reassembled payload", HFILL }}
};
static gint *ett[] = {
&ett_ip,
&ett_ip_dsfield,
&ett_ip_tos,
&ett_ip_off,
&ett_ip_options,
&ett_ip_option_eool,
&ett_ip_option_nop,
&ett_ip_option_sec,
&ett_ip_option_route,
&ett_ip_option_timestamp,
&ett_ip_option_ext_security,
&ett_ip_option_cipso,
&ett_ip_option_sid,
&ett_ip_option_mtu,
&ett_ip_option_tr,
&ett_ip_option_ra,
&ett_ip_option_sdb,
&ett_ip_option_qs,
&ett_ip_option_other,
&ett_ip_fragments,
&ett_ip_fragment,
&ett_ip_checksum,
&ett_ip_opt_type,
&ett_ip_opt_sec_prot_auth_flags,
#ifdef HAVE_GEOIP
&ett_geoip_info
#endif
};
module_t *ip_module;
proto_ip = proto_register_protocol("Internet Protocol Version 4", "IPv4", "ip");
proto_register_field_array(proto_ip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ip_dissector_table = register_dissector_table("ip.proto", "IPv4 protocol",
FT_UINT8, BASE_DEC);
ip_module = prefs_register_protocol(proto_ip, NULL);
prefs_register_bool_preference(ip_module, "decode_tos_as_diffserv",
"Decode IPv4 TOS field as DiffServ field",
"Whether the IPv4 type-of-service field should be decoded as a "
"Differentiated Services field (see RFC2474/RFC2475)", &g_ip_dscp_actif);
prefs_register_bool_preference(ip_module, "defragment",
"Reassemble fragmented IPv4 datagrams",
"Whether fragmented IPv4 datagrams should be reassembled", &ip_defragment);
prefs_register_bool_preference(ip_module, "summary_in_tree",
"Show IPv4 summary in protocol tree",
"Whether the IPv4 summary line should be shown in the protocol tree",
&ip_summary_in_tree);
prefs_register_bool_preference(ip_module, "check_checksum",
"Validate the IPv4 checksum if possible",
"Whether to validate the IPv4 checksum", &ip_check_checksum);
prefs_register_bool_preference(ip_module, "tso_support",
"Support packet-capture from IP TSO-enabled hardware",
"Whether to correct for TSO-enabled (TCP segmentation offload) hardware "
"captures, such as spoofing the IP packet length", &ip_tso_supported);
#ifdef HAVE_GEOIP
prefs_register_bool_preference(ip_module, "use_geoip",
"Enable GeoIP lookups",
"Whether to look up IP addresses in each GeoIP database we have loaded",
&ip_use_geoip);
#endif
prefs_register_bool_preference(ip_module, "security_flag" ,
"Interpret Reserved flag as Security flag (RFC 3514)",
"Whether to interpret the originally reserved flag as security flag",
&ip_security_flag);
register_dissector("ip", dissect_ip, proto_ip);
register_init_routine(ip_defragment_init);
ip_tap = register_tap("ip");
}
void
proto_reg_handoff_ip(void)
{
dissector_handle_t ip_handle;
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
tapa_handle = find_dissector("tapa");
data_handle = find_dissector("data");
dissector_add_uint("ethertype", ETHERTYPE_IP, ip_handle);
dissector_add_uint("ppp.protocol", PPP_IP, ip_handle);
dissector_add_uint("ppp.protocol", ETHERTYPE_IP, ip_handle);
dissector_add_uint("gre.proto", ETHERTYPE_IP, ip_handle);
dissector_add_uint("gre.proto", GRE_WCCP, ip_handle);
dissector_add_uint("llc.dsap", SAP_IP, ip_handle);
dissector_add_uint("ip.proto", IP_PROTO_IPIP, ip_handle);
dissector_add_uint("null.type", BSD_AF_INET, ip_handle);
dissector_add_uint("chdlctype", ETHERTYPE_IP, ip_handle);
dissector_add_uint("osinl.excl", NLPID_IP, ip_handle);
dissector_add_uint("fr.ietf", NLPID_IP, ip_handle);
dissector_add_uint("x.25.spi", NLPID_IP, ip_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_IP_1051, ip_handle);
dissector_add_uint("arcnet.protocol_id", ARCNET_PROTO_IP_1201, ip_handle);
dissector_add_handle("udp.port", ip_handle);
}
