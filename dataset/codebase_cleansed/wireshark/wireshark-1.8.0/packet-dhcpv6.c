static int
dissect_packetcable_ccc_option(proto_tree *v_tree, tvbuff_t *tvb, int optoff,
int optend)
{
int suboptoff = optoff;
guint16 subopt, subopt_len, sec_tcm;
guint8 fetch_tgt, timer_val, type;
proto_item *vti;
proto_tree *pkt_s_tree;
guint32 ipv4_address;
guchar kr_name;
guint8 kr_value;
int kr_fail_flag = 0;
int kr_pos = 0;
int i = 0;
char bit_fld[24];
subopt = tvb_get_ntohs(tvb, optoff);
suboptoff += 2;
subopt_len = tvb_get_ntohs(tvb, suboptoff);
suboptoff += 2;
if (optend <= 0) {
proto_tree_add_text(v_tree, tvb, optoff, 1,
"Sub element %d: no room left in option for suboption length",
subopt);
return (optend);
}
vti = proto_tree_add_text(v_tree, tvb, optoff, subopt_len + 4,
"Sub element %u: %s: ", subopt,
val_to_str(subopt, pkt_ccc_opt_vals, "unknown/reserved") );
switch (subopt) {
case PKT_CCC_PRI_DHCP:
case PKT_CCC_SEC_DHCP:
if (subopt_len == 4) {
ipv4_address = tvb_get_ipv4(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
ip_to_str((guint8 *)&ipv4_address), subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 4 ? " [Invalid]" : "");
}
else {
proto_tree_add_text(vti, tvb, suboptoff, subopt_len,
"Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCC_IETF_PROV_SRV :
type = tvb_get_guint8(tvb, suboptoff);
if (type == 0) {
proto_item_append_text(vti, "%s (%u byte%s)",
tvb_format_stringzpad(tvb, suboptoff+1, subopt_len-1),
subopt_len,
plurality(subopt_len-1, "", "s") );
}
else if (type == 1) {
if (subopt_len == 5) {
ipv4_address = tvb_get_ipv4(tvb, suboptoff+1);
proto_item_append_text(vti, "%s (%u byte%s%s)",
ip_to_str((guint8 *)&ipv4_address), subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 5 ? " [Invalid]" : "");
}
else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
}
else {
proto_item_append_text(vti, "Invalid type: %u (%u byte%s)",
type, subopt_len, plurality(subopt_len, "", "s"));
}
suboptoff += subopt_len;
break;
case PKT_CCC_IETF_AS_KRB :
case PKT_CCC_IETF_AP_KRB :
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"Nominal Timeout : %u", tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff+4, 4,
"Maximum Timeout : %u", tvb_get_ntohl(tvb, suboptoff+4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff+8, 4,
"Maximum Retry Count : %u", tvb_get_ntohl(tvb, suboptoff+8));
}
else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCC_KRB_REALM:
if (subopt_len > 0) {
for (i=0; i < subopt_len; i++) {
kr_name = tvb_get_guint8(tvb, suboptoff + i);
kr_value = (int)kr_name;
if ((kr_value >= 65 && kr_value <= 90) ||
kr_value == 34 ||
kr_value == 44 ||
kr_value == 46 ||
kr_value == 47 ||
kr_value == 58 ||
kr_value == 61 ||
kr_value == 92) {
}
else if (!kr_fail_flag) {
kr_pos = i;
kr_fail_flag = 1;
}
proto_item_append_text(vti, "%c", kr_name);
}
if (kr_fail_flag) {
proto_item_append_text(vti, " (%u byte%s [Invalid at byte=%d]) ",
subopt_len,
plurality(subopt_len, "", "s"),
kr_pos);
}
else {
proto_item_append_text(vti, " (%u byte%s%s) ",
subopt_len,
plurality(subopt_len, "", "s"),
kr_fail_flag != 0 ? " [Invalid]" : "");
}
}
suboptoff += subopt_len;
break;
case PKT_CCC_TGT_FLAG:
fetch_tgt = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
fetch_tgt == 1 ? "True" : "False",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCC_PROV_TIMER:
timer_val = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%u (%u byte%s%s)", timer_val,
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCC_IETF_SEC_TKT :
sec_tcm = tvb_get_ntohs(tvb, suboptoff);
proto_item_append_text(vti, "0x%04x (%u byte%s%s)",
sec_tcm, subopt_len, plurality(subopt_len, "", "s"),
subopt_len != 2 ? " [Invalid]" : "");
if (subopt_len == 2) {
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
for (i=0; i< 2; i++) {
if (sec_tcm & sec_tcm_vals[i].value) {
decode_bitfield_value(bit_fld, sec_tcm, sec_tcm_vals[i].value, 16);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 2, "%s %s",
bit_fld, sec_tcm_vals[i].strptr);
}
}
}
suboptoff += subopt_len;
break;
default:
suboptoff += subopt_len;
break;
}
return (suboptoff - optoff);
}
static int
dissect_packetcable_cccV6_option(proto_tree *v_tree, tvbuff_t *tvb, int optoff,
int optend)
{
int suboptoff = optoff;
guint16 subopt, subopt_len, sec_tcm;
guint8 fetch_tgt, timer_val, type;
proto_item *vti;
proto_tree *pkt_s_tree;
guchar kr_name;
guint8 kr_value;
int kr_fail_flag = 0;
int kr_pos = 0;
int i = 0;
char bit_fld[24];
struct e_in6_addr in6;
subopt = tvb_get_ntohs(tvb, optoff);
suboptoff += 2;
subopt_len = tvb_get_ntohs(tvb, suboptoff);
suboptoff += 2;
if (optend <= 0) {
proto_tree_add_text(v_tree, tvb, optoff, 1,
"Sub element %d: no room left in option for suboption length",
subopt);
return (optend);
}
vti = proto_tree_add_text(v_tree, tvb, optoff, subopt_len + 4,
"Sub element %u: %s: ", subopt,
val_to_str(subopt, pkt_cccV6_opt_vals, "unknown/reserved") );
switch (subopt) {
case PKT_CCCV6_PRI_DSS:
case PKT_CCCV6_SEC_DSS:
if (subopt_len < 35) {
proto_item_append_text(vti, "%s (%u byte%s)",
tvb_format_stringzpad(tvb, suboptoff, subopt_len),
subopt_len,
plurality(subopt_len-1, "", "s") );
} else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_PROV_SRV:
type = tvb_get_guint8(tvb, suboptoff);
if (type == 0) {
proto_item_append_text(vti, "%s (%u byte%s)",
tvb_format_stringzpad(tvb, suboptoff+1, subopt_len-1),
subopt_len,
plurality(subopt_len-1, "", "s") );
} else if (type == 1) {
if ((subopt_len % 16) == 0) {
for (i = 0; i < subopt_len/16; i++) {
tvb_get_ipv6(tvb, suboptoff, &in6);
proto_item_append_text(vti, "IPv6 address %d: %s",
i+1, ip6_to_str(&in6));
suboptoff += 16;
}
}
} else {
proto_item_append_text(vti, "Invalid type: %u (%u byte%s)",
type, subopt_len, plurality(subopt_len, "", "s"));
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_AS_KRB:
case PKT_CCCV6_IETF_AP_KRB:
if (subopt_len == 12) {
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 4,
"Nominal Timeout : %u", tvb_get_ntohl(tvb, suboptoff));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff+4, 4,
"Maximum Timeout : %u", tvb_get_ntohl(tvb, suboptoff+4));
proto_tree_add_text(pkt_s_tree, tvb, suboptoff+8, 4,
"Maximum Retry Count : %u", tvb_get_ntohl(tvb, suboptoff+8));
} else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_KRB_REALM:
if (subopt_len > 0) {
for (i=0; i < subopt_len; i++) {
kr_name = tvb_get_guint8(tvb, suboptoff + i);
kr_value = (int)kr_name;
if ((kr_value >= 65 && kr_value <= 90) ||
kr_value == 34 ||
kr_value == 44 ||
kr_value == 46 ||
kr_value == 47 ||
kr_value == 58 ||
kr_value == 61 ||
kr_value == 92) {
} else if (!kr_fail_flag) {
kr_pos = i;
kr_fail_flag = 1;
}
proto_item_append_text(vti, "%c", kr_name);
}
if (kr_fail_flag) {
proto_item_append_text(vti, " (%u byte%s [Invalid at byte=%d]) ",
subopt_len,
plurality(subopt_len, "", "s"),
kr_pos);
} else {
proto_item_append_text(vti, " (%u byte%s%s) ",
subopt_len,
plurality(subopt_len, "", "s"),
kr_fail_flag != 0 ? " [Invalid]" : "");
}
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_TGT_FLAG:
fetch_tgt = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%s (%u byte%s%s)",
fetch_tgt == 1 ? "True" : "False",
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCCV6_PROV_TIMER:
timer_val = tvb_get_guint8(tvb, suboptoff);
proto_item_append_text(vti, "%u (%u byte%s%s)", timer_val,
subopt_len,
plurality(subopt_len, "", "s"),
subopt_len != 1 ? " [Invalid]" : "");
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_SEC_TKT:
sec_tcm = tvb_get_ntohs(tvb, suboptoff);
proto_item_append_text(vti, "0x%04x (%u byte%s%s)",
sec_tcm, subopt_len, plurality(subopt_len, "", "s"),
subopt_len != 2 ? " [Invalid]" : "");
if (subopt_len == 2) {
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
for (i=0; i< 2; i++) {
if (sec_tcm & sec_tcm_vals[i].value) {
decode_bitfield_value(bit_fld, sec_tcm, sec_tcm_vals[i].value, 16);
proto_tree_add_text(pkt_s_tree, tvb, suboptoff, 2, "%s %s",
bit_fld, sec_tcm_vals[i].strptr);
}
}
}
suboptoff += subopt_len;
break;
default:
suboptoff += subopt_len;
break;
}
return (suboptoff - optoff);
}
static void
dissect_cablelabs_specific_opts(proto_tree *v_tree, tvbuff_t *tvb, int voff, int len)
{
guint16 type;
guint16 tlv_len;
guint16 opt_len;
guint16 sub_value;
int off = voff;
int sub_off;
proto_item *ti;
int i;
int field_len;
int field_value;
proto_tree *subtree;
struct e_in6_addr in6;
if (len > 4) {
while (off - voff < len) {
type = tvb_get_ntohs(tvb, off);
ti = proto_tree_add_text(v_tree, tvb, off, 2,
"Suboption %d: %s", type, val_to_str(type,
cl_vendor_subopt_values, "unknown"));
tlv_len = tvb_get_ntohs(tvb, off+2);
sub_off = off + 4;
switch(type) {
case CL_OPTION_DEVICE_TYPE :
case CL_OPTION_DEVICE_SERIAL_NUMBER :
case CL_OPTION_HARDWARE_VERSION_NUMBER :
case CL_OPTION_SOFTWARE_VERSION_NUMBER :
case CL_OPTION_BOOT_ROM_VERSION :
case CL_OPTION_MODEL_NUMBER :
case CL_OPTION_VENDOR_NAME :
case CL_OPTION_CONFIG_FILE_NAME :
case CL_OPTION_EMBEDDED_COMPONENT_LIST :
opt_len = tlv_len;
field_len = tlv_len;
proto_item_append_text(ti, "\"%s\"",
tvb_format_stringzpad(tvb, sub_off, field_len));
break;
case CL_OPTION_VENDOR_OUI :
opt_len = tlv_len;
if (tlv_len == 3) {
proto_item_append_text(ti, "%s",
tvb_bytes_to_str_punct(tvb, sub_off, 3, ':'));
} else if (tlv_len == 6) {
proto_item_append_text(ti, "\"%s\"", tvb_format_stringzpad(tvb, sub_off, tlv_len));
} else {
proto_item_append_text(ti, "Suboption %d: suboption length isn't 3 or 6", type);
}
break;
case CL_OPTION_ORO :
field_len = 2;
opt_len = tlv_len;
if (opt_len > 0) {
for (i = 0; i < tlv_len; i += field_len) {
sub_value = tvb_get_ntohs(tvb, sub_off);
proto_item_append_text(ti, " %d", sub_value);
sub_off += field_len;
}
}
break;
case CL_OPTION_TFTP_SERVERS :
case CL_OPTION_SYSLOG_SERVERS :
case CL_OPTION_RFC868_SERVERS :
field_len = 16;
opt_len = tlv_len;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
if ((tlv_len % field_len) == 0) {
for (i = 0; i < tlv_len/field_len; i++) {
tvb_get_ipv6(tvb, sub_off, &in6);
proto_tree_add_text(subtree, tvb, sub_off,
sizeof(in6), "IPv6 address %d: %s",
i+1, ip6_to_str(&in6));
sub_off += field_len;
}
}
break;
case CL_OPTION_DEVICE_ID :
opt_len = tlv_len;
field_len = tlv_len;
if (tlv_len != 6) {
proto_item_append_text(ti, "Bogus value length=%d",
tlv_len);
}
else {
proto_item_append_text(ti, "%s",
tvb_bytes_to_str(tvb, sub_off, field_len));
}
break;
case CL_OPTION_TLV5 :
opt_len = tlv_len;
field_len = tlv_len;
proto_item_append_text(ti, "%s",
tvb_bytes_to_str(tvb, sub_off, field_len));
break;
case CL_OPTION_TIME_OFFSET :
opt_len = tlv_len;
proto_item_append_text(ti, "%d", tvb_get_ntohl(tvb, sub_off));
break;
case CL_OPTION_IP_PREF :
opt_len = tlv_len;
field_value = tvb_get_guint8(tvb, sub_off);
if (field_value == 1) {
proto_item_append_text(ti, "%s", "IPv4");
} else if (field_value == 2) {
proto_item_append_text(ti, "%s", "IPv6");
} else {
proto_item_append_text(ti, "%s", "Unknown");
}
break;
case CL_OPTION_DOCS_CMTS_CAP :
opt_len = tlv_len;
field_len = 0;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
if (tlv_len > 0) {
for (i = 0; field_len < opt_len; i++) {
int tagLen = 0;
int tag = 0;
tag = tvb_get_guint8(tvb, sub_off);
sub_off++;
tagLen = tvb_get_guint8(tvb, sub_off);
sub_off++;
if (tag == CL_OPTION_DOCS_CMTS_TLV_VERS_NUM &&
tagLen == 2) {
int major = 0;
int minor = 0;
major = tvb_get_guint8(tvb, sub_off);
sub_off++;
minor = tvb_get_guint8(tvb, sub_off);
sub_off++;
proto_tree_add_text(subtree, tvb, sub_off-2,
2, "DOCSIS Version Number %d.%d",
major, minor);
}
else
sub_off += tagLen;
field_len += tagLen + 2;
}
}
else
proto_tree_add_text(subtree, tvb, sub_off, 0, "empty");
break;
case CL_CM_MAC_ADDR :
opt_len = tlv_len;
field_len = tlv_len;
if (tlv_len != 6) {
proto_item_append_text(ti, "Bogus value length=%d",
tlv_len);
}
else {
proto_item_append_text(ti, "%s", tvb_bytes_to_str_punct(tvb, sub_off, opt_len, ':'));
}
sub_off += field_len;
break;
case CL_EROUTER_CONTAINER_OPTION :
opt_len = tlv_len;
field_len = tlv_len;
proto_item_append_text(ti, " %s (len=%d)",
tvb_bytes_to_str(tvb, sub_off, opt_len), tlv_len);
sub_off += field_len;
break;
case CL_OPTION_CCC :
opt_len = tlv_len;
field_len = 0;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
proto_item_append_text(ti, " (%d bytes)", opt_len);
while (field_len < opt_len) {
sub_value = dissect_packetcable_ccc_option(subtree, tvb,
sub_off, (opt_len - field_len));
sub_off += sub_value;
field_len += sub_value;
}
sub_off += field_len;
break;
case CL_OPTION_CCCV6 :
opt_len = tlv_len;
field_len = 0;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
proto_item_append_text(ti, " (%d bytes)", opt_len);
while (field_len < opt_len) {
sub_value = dissect_packetcable_cccV6_option(subtree, tvb,
sub_off, (opt_len - field_len));
sub_off += sub_value;
field_len += sub_value;
}
sub_off += field_len;
break;
case CL_OPTION_CORRELATION_ID :
opt_len = tlv_len;
if (tlv_len != 4) {
proto_item_append_text(ti, "Bogus value length=%d",
tlv_len);
}
else {
proto_item_append_text(ti, "%d", tvb_get_ntohl(tvb, sub_off));
}
break;
default:
opt_len = tlv_len;
break;
}
off += (opt_len + 4);
}
}
else {
proto_tree_add_text(v_tree, tvb, off, len-off,
"Bogus length: %d", len);
}
}
static void
dhcpv6_domain(proto_tree * subtree, tvbuff_t *tvb, int offset, guint16 optlen)
{
int start_offset=offset;
char domain[256];
int pos;
guint8 len;
pos=0;
while(optlen){
if(!pos){
start_offset=offset;
}
domain[pos]=0;
len = tvb_get_guint8(tvb, offset);
if ( optlen < len ) {
proto_tree_add_text(subtree, tvb, start_offset, optlen, "Malformed DNS name record (MS Vista client?)");
return;
}
offset++;
optlen--;
if(!len){
if(!pos){
proto_tree_add_text(subtree, tvb, start_offset, offset-start_offset, "Malformed option");
return;
} else {
proto_tree_add_text(subtree, tvb, start_offset, offset-start_offset, "Domain: %s", domain);
pos=0;
continue;
}
}
if(pos){
domain[pos]='.';
pos++;
}
if(pos+len>254){
proto_tree_add_text(subtree, tvb, start_offset, offset-start_offset, "Malformed option");
return;
}
tvb_memcpy(tvb, domain+pos, offset, len);
pos+=len;
offset+=len;
optlen-=len;
}
if(pos){
domain[pos]=0;
proto_tree_add_text(subtree, tvb, start_offset, offset-start_offset, "Domain: %s", domain);
}
}
static int
dhcpv6_option(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bp_tree,
gboolean downstream, int off, int eoff, gboolean *at_end)
{
guint8 *buf;
guint16 opttype;
guint16 optlen;
guint16 hwtype;
guint16 temp_optlen = 0;
proto_item *ti;
proto_tree *subtree;
proto_tree *subtree_2;
int i;
struct e_in6_addr in6;
guint16 duidtype;
guint32 enterprise_no;
if (eoff - off < 4) {
*at_end = TRUE;
return 0;
}
opttype = tvb_get_ntohs(tvb, off);
optlen = tvb_get_ntohs(tvb, off + 2);
if (eoff - off < 4 + optlen) {
*at_end = TRUE;
return 0;
}
ti = proto_tree_add_text(bp_tree, tvb, off, 4 + optlen,
"%s", val_to_str(opttype, opttype_vals, "DHCP option %u"));
subtree = proto_item_add_subtree(ti, ett_dhcpv6_option);
proto_tree_add_item(subtree, hf_option_type, tvb, off, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_option_length, tvb, off + 2, 2, ENC_BIG_ENDIAN);
off += 4;
if (optlen)
proto_tree_add_item(subtree, hf_option_value, tvb, off, optlen, ENC_NA);
switch (opttype) {
case OPTION_CLIENTID:
col_append_fstr(pinfo->cinfo, COL_INFO, "CID: %s ", tvb_bytes_to_str(tvb, off, optlen));
case OPTION_SERVERID:
if (optlen < 2) {
proto_tree_add_text(subtree, tvb, off, optlen,
"DUID: malformed option");
break;
}
proto_item_append_text(ti, ": %s", tvb_bytes_to_str(tvb, off, optlen));
duidtype = tvb_get_ntohs(tvb, off);
proto_tree_add_text(subtree, tvb, off, 2,
"DUID type: %s (%u)",
val_to_str(duidtype,
duidtype_vals, "Unknown"),
duidtype);
switch (duidtype) {
case DUID_LLT:
if (optlen < 8) {
proto_tree_add_text(subtree, tvb, off,
optlen, "DUID: malformed option");
break;
}
hwtype=tvb_get_ntohs(tvb, off + 2);
proto_tree_add_text(subtree, tvb, off + 2, 2,
"Hardware type: %s (%u)", arphrdtype_to_str(hwtype, "Unknown"),
hwtype);
proto_tree_add_text(subtree, tvb, off + 4, 4,
"Time: %s",
abs_time_secs_to_str(tvb_get_ntohl(tvb, off + 4)+946684800U, ABSOLUTE_TIME_LOCAL, TRUE));
if (optlen > 8) {
proto_tree_add_text(subtree, tvb, off + 8,
optlen - 8, "Link-layer address: %s",
tvb_arphrdaddr_to_str(tvb, off+8, optlen-8, hwtype));
}
break;
case DUID_EN:
if (optlen < 6) {
proto_tree_add_text(subtree, tvb, off,
optlen, "DUID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_duiden_enterprise, tvb, off + 2, 4, ENC_BIG_ENDIAN);
if (optlen > 6) {
buf = tvb_bytes_to_str(tvb, off + 6, optlen - 6);
proto_tree_add_text(subtree, tvb, off + 6,
optlen - 6, "identifier: %s", buf);
}
break;
case DUID_LL:
case DUID_LL_OLD:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "DUID: malformed option");
break;
}
hwtype=tvb_get_ntohs(tvb, off + 2);
proto_tree_add_text(subtree, tvb, off + 2, 2,
"Hardware type: %s (%u)",
arphrdtype_to_str(hwtype, "Unknown"),
hwtype);
if (optlen > 4) {
proto_tree_add_text(subtree, tvb, off + 4,
optlen - 4, "Link-layer address: %s",
tvb_arphrdaddr_to_str(tvb, off+4, optlen-4, hwtype));
}
break;
}
break;
case OPTION_IA_NA:
case OPTION_IA_PD:
if (optlen < 12) {
if (opttype == OPTION_IA_NA)
proto_tree_add_text(subtree, tvb, off,
optlen, "IA_NA: malformed option");
else
proto_tree_add_text(subtree, tvb, off,
optlen, "IA_PD: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 4,
"IAID: %s",
tvb_arphrdaddr_to_str(tvb, off, 4, opttype));
if (tvb_get_ntohl(tvb, off+4) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off+4, 4,
"T1: infinity");
} else {
proto_tree_add_text(subtree, tvb, off+4, 4,
"T1: %u", tvb_get_ntohl(tvb, off+4));
}
if (tvb_get_ntohl(tvb, off+8) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off+8, 4,
"T2: infinity");
} else {
proto_tree_add_text(subtree, tvb, off+8, 4,
"T2: %u", tvb_get_ntohl(tvb, off+8));
}
temp_optlen = 12;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_IA_TA:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "IA_TA: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 4,
"IAID: %s",
tvb_arphrdaddr_to_str(tvb, off, 4, opttype));
temp_optlen = 4;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_IAADDR:
{
guint32 preferred_lifetime, valid_lifetime;
if (optlen < 24) {
proto_tree_add_text(subtree, tvb, off,
optlen, "IAADDR: malformed option");
break;
}
tvb_get_ipv6(tvb, off, &in6);
proto_tree_add_text(subtree, tvb, off,
sizeof(in6), "IPv6 address: %s",
ip6_to_str(&in6));
col_append_fstr(pinfo->cinfo, COL_INFO, "IAA: %s ", ip6_to_str(&in6));
proto_item_append_text(ti, ": %s", ip6_to_str(&in6));
preferred_lifetime = tvb_get_ntohl(tvb, off + 16);
valid_lifetime = tvb_get_ntohl(tvb, off + 20);
if (preferred_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off + 16, 4,
"Preferred lifetime: infinity");
} else {
proto_tree_add_text(subtree, tvb, off + 16, 4,
"Preferred lifetime: %u", preferred_lifetime);
}
if (valid_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off + 20, 4,
"Valid lifetime: infinity");
} else {
proto_tree_add_text(subtree, tvb, off + 20, 4,
"Valid lifetime: %u", valid_lifetime);
}
temp_optlen = 24;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
}
break;
case OPTION_ORO:
case OPTION_ERO:
for (i = 0; i < optlen; i += 2) {
guint16 requested_opt_code;
requested_opt_code = tvb_get_ntohs(tvb, off + i);
proto_tree_add_text(subtree, tvb, off + i,
2, "Requested Option code: %s (%d)",
val_to_str(requested_opt_code,
opttype_vals,
"Unknown"),
requested_opt_code);
}
break;
case OPTION_PREFERENCE:
if (optlen != 1) {
proto_tree_add_text(subtree, tvb, off,
optlen, "PREFERENCE: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 1,
"pref-value: %d",
(guint32)tvb_get_guint8(tvb, off));
break;
case OPTION_ELAPSED_TIME:
if (optlen != 2) {
proto_tree_add_text(subtree, tvb, off,
optlen, "ELAPSED-TIME: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 2,
"elapsed-time: %u ms",
10*(guint32)tvb_get_ntohs(tvb, off));
break;
case OPTION_RELAY_MSG:
if (optlen == 0) {
proto_tree_add_text(subtree, tvb, off,
optlen, "RELAY-MSG: malformed option");
} else {
dissect_dhcpv6(tvb, pinfo, subtree, downstream, off, off + optlen);
}
break;
case OPTION_AUTH:
if (optlen < 11) {
proto_tree_add_text(subtree, tvb, off,
optlen, "AUTH: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 1,
"Protocol: %d",
(guint32)tvb_get_guint8(tvb, off));
proto_tree_add_text(subtree, tvb, off+1, 1,
"Algorithm: %d",
(guint32)tvb_get_guint8(tvb, off+1));
proto_tree_add_text(subtree, tvb, off+2, 1,
"RDM: %d",
(guint32)tvb_get_guint8(tvb, off+2));
proto_tree_add_text(subtree, tvb, off+3, 8,
"Replay Detection");
if (optlen != 11)
proto_tree_add_text(subtree, tvb, off+11, optlen-11,
"Authentication Information");
break;
case OPTION_UNICAST:
if (optlen != 16) {
proto_tree_add_text(subtree, tvb, off,
optlen, "UNICAST: malformed option");
break;
}
tvb_get_ipv6(tvb, off, &in6);
proto_tree_add_text(subtree, tvb, off,
sizeof(in6), "IPv6 address: %s",
ip6_to_str(&in6));
break;
case OPTION_STATUS_CODE:
{
guint16 status_code;
char *status_message = 0;
status_code = tvb_get_ntohs(tvb, off);
proto_tree_add_text(subtree, tvb, off, 2,
"Status Code: %s (%d)",
val_to_str(status_code, statuscode_vals,
"Unknown"),
status_code);
if (optlen - 2 > 0) {
status_message = tvb_get_ephemeral_string(tvb, off + 2, optlen - 2);
proto_tree_add_text(subtree, tvb, off + 2, optlen - 2,
"Status Message: %s",
status_message);
}
}
break;
case OPTION_VENDOR_CLASS:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "VENDOR_CLASS: malformed option");
break;
}
proto_tree_add_item(subtree, hf_vendorclass_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
if (optlen > 4) {
proto_tree_add_text(subtree, tvb, off+6, optlen-6,
"vendor-class-data: \"%s\"", tvb_format_stringzpad(tvb, off + 6, optlen - 6));
}
break;
case OPTION_VENDOR_OPTS:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "VENDOR_OPTS: malformed option");
break;
}
enterprise_no = tvb_get_ntohl(tvb, off);
proto_tree_add_item(subtree, hf_vendoropts_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
if (optlen >= 4) {
if (enterprise_no == 4491) {
dissect_cablelabs_specific_opts(subtree, tvb, off+4, optlen-4);
} else {
int optoffset = 0;
while((optlen - 4 - optoffset) > 0) {
int olen = tvb_get_ntohs(tvb, off + optoffset + 6);
ti = proto_tree_add_text(subtree, tvb, off + optoffset + 4,
4 + olen, "option");
subtree_2 = proto_item_add_subtree(ti, ett_dhcpv6_option_vsoption);
proto_tree_add_text(subtree_2, tvb, off + optoffset + 4, 2,
"option code: %u", tvb_get_ntohs(tvb, off + optoffset + 4));
proto_tree_add_text(subtree_2, tvb, off + optoffset + 6, 2,
"option length: %u", olen);
proto_tree_add_text(subtree_2, tvb, off + optoffset + 8, olen,
"option-data");
optoffset += (4 + olen);
}
}
}
break;
case OPTION_INTERFACE_ID:
{
gint namelen;
if (optlen == 0) {
proto_tree_add_text(subtree, tvb, off,
optlen, "INTERFACE_ID: malformed option");
break;
}
namelen = tvb_strnlen(tvb, off, optlen)+1;
if (namelen == 0)
{
buf = tvb_get_ephemeral_string(tvb, off, optlen);
proto_tree_add_text(subtree, tvb, off, optlen, "Interface-ID: %s", buf);
} else {
buf = tvb_get_ephemeral_string(tvb, off, namelen-1);
proto_tree_add_text(subtree, tvb, off, namelen, "Interface-ID: %s", buf);
temp_optlen = optlen - namelen;
off += namelen;
if (temp_optlen >= 6)
proto_tree_add_text(subtree, tvb, off,
temp_optlen, "Link-layer address: %s",
tvb_arphrdaddr_to_str(tvb, off, 6, ARPHRD_ETHER));
}
}
break;
case OPTION_RECONF_MSG:
if (optlen != 1) {
proto_tree_add_text(subtree, tvb, off,
optlen, "RECONF_MSG: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, optlen,
"Reconfigure-type: %s",
val_to_str(tvb_get_guint8(tvb, off),
msgtype_vals,
"Message Type %u"));
break;
case OPTION_SIP_SERVER_D:
if (optlen > 0) {
proto_tree_add_text(subtree, tvb, off, optlen,
"SIP Servers Domain Search List");
}
dhcpv6_domain(subtree,tvb, off, optlen);
break;
case OPTION_SIP_SERVER_A:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"SIP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "SIP servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_DNS_SERVERS:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"DNS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "DNS servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_DOMAIN_LIST:
if (optlen > 0) {
proto_tree_add_text(subtree, tvb, off, optlen, "DNS Domain Search List");
}
dhcpv6_domain(subtree,tvb, off, optlen);
break;
case OPTION_NIS_SERVERS:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"NIS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "NIS servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_NISP_SERVERS:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"NISP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "NISP servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_NIS_DOMAIN_NAME:
if (optlen > 0) {
proto_tree_add_text(subtree, tvb, off, optlen, "nis-domain-name");
}
dhcpv6_domain(subtree,tvb, off, optlen);
break;
case OPTION_NISP_DOMAIN_NAME:
if (optlen > 0) {
proto_tree_add_text(subtree, tvb, off, optlen, "nisp-domain-name");
}
dhcpv6_domain(subtree,tvb, off, optlen);
break;
case OPTION_SNTP_SERVERS:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"SNTP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "SNTP servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_LIFETIME:
if (optlen != 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "LIFETIME: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 4,
"Lifetime: %d",
(guint32)tvb_get_ntohl(tvb, off));
break;
case OPTION_BCMCS_SERVER_D:
if (optlen > 0) {
proto_tree_add_text(subtree, tvb, off, optlen,
"BCMCS Servers Domain Search List");
}
dhcpv6_domain(subtree,tvb, off, optlen);
break;
case OPTION_BCMCS_SERVER_A:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"BCMCS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "BCMCS servers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_REMOTE_ID:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off,
optlen, "REMOTE_ID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_remoteid_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
off += 4;
buf = tvb_bytes_to_str(tvb, off, optlen - 4);
proto_tree_add_text(subtree, tvb, off, optlen - 4, "Remote-ID: %s", buf);
break;
case OPTION_SUBSCRIBER_ID:
if (optlen == 0) {
proto_tree_add_text(subtree, tvb, off,
optlen, "SUBSCRIBER_ID: malformed option");
break;
}
buf = tvb_get_ephemeral_string(tvb, off, optlen);
proto_tree_add_text(subtree, tvb, off, optlen, "Subscriber-ID: %s", buf);
break;
case OPTION_CLIENT_FQDN:
if (optlen < 1) {
proto_tree_add_text(subtree, tvb, off,
optlen, "FQDN: malformed option");
} else {
proto_tree_add_item(subtree, hf_clientfqdn_reserved, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_n, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_o, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_s, tvb, off, 1, ENC_BIG_ENDIAN);
dhcpv6_domain(subtree, tvb, off+1, optlen-1);
}
break;
case OPTION_PANA_AGENT:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"PANA agent address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "PANA agents address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_TIME_ZONE:
if (optlen > 0) {
buf = tvb_get_ephemeral_string(tvb, off, optlen);
proto_tree_add_text(subtree, tvb, off, optlen, "time-zone: %s", buf);
}
break;
case OPTION_TZDB:
if (optlen > 0) {
buf = tvb_get_ephemeral_string(tvb, off, optlen);
proto_tree_add_text(subtree, tvb, off, optlen, "tz-database: %s", buf);
}
break;
case OPTION_LQ_QUERY:
{
guint8 query_type;
struct e_in6_addr in6_local;
if (optlen < 17) {
proto_tree_add_text(subtree, tvb, off, optlen,
"LQ-QUERY: malformed option");
break;
}
query_type = tvb_get_guint8(tvb, off);
switch (query_type) {
case 1:
proto_tree_add_text(subtree, tvb, off, 1,
"Query-type: %s (%u)",
"by-address", query_type);
break;
case 2:
proto_tree_add_text(subtree, tvb, off, 1,
"Query-type: %s (%u)",
"by-clientID", query_type);
break;
default:
proto_tree_add_text(subtree, tvb, off, 1,
"Query-type: %s (%u)",
"unknown?", query_type);
break;
}
tvb_get_ipv6(tvb, off + 1, &in6_local);
proto_tree_add_text(subtree, tvb, off + 1, 16,
"Link address: %s", ip6_to_str(&in6_local));
temp_optlen = 17;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree,
downstream, off + temp_optlen,
off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
}
break;
case OPTION_CLIENT_DATA:
temp_optlen = 0;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree,
downstream, off + temp_optlen,
off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_CLT_TIME:
if (optlen != 4) {
proto_tree_add_text(subtree, tvb, off, optlen,
"CLT_TIME: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, 4,
"Clt_time: %d",
(guint32)tvb_get_ntohl(tvb, off));
break;
case OPTION_LQ_RELAY_DATA:
if (optlen < 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"LQ_RELAY_DATA: malformed option");
break;
}
tvb_get_ipv6(tvb, off, &in6);
proto_tree_add_text(subtree, tvb, off, 16,
"Peer address: %s", ip6_to_str(&in6));
proto_tree_add_text(subtree, tvb, off + 16, optlen - 16,
"DHCPv6 relay message");
break;
case OPTION_LQ_CLIENT_LINK:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"LQ client links address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "LQ client links address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_CAPWAP_AC_V6:
if (optlen % 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"CAPWAP Access Controllers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
tvb_get_ipv6(tvb, off + i, &in6);
proto_tree_add_text(subtree, tvb, off + i,
sizeof(in6), "CAPWAP Access Controllers address: %s",
ip6_to_str(&in6));
}
break;
case OPTION_AFTR_NAME:
{
const guchar *dns_name;
get_dns_name(tvb, off, optlen, off, &dns_name);
proto_tree_add_text(subtree, tvb, off, optlen,
"DS-Lite AFTR Name: %s", dns_name);
break;
}
case OPTION_IAPREFIX:
{
guint32 preferred_lifetime, valid_lifetime;
guint8 prefix_length;
struct e_in6_addr in6_local;
if (optlen < 25) {
proto_tree_add_text(subtree, tvb, off,
optlen, "IAPREFIX: malformed option");
break;
}
preferred_lifetime = tvb_get_ntohl(tvb, off);
valid_lifetime = tvb_get_ntohl(tvb, off + 4);
prefix_length = tvb_get_guint8(tvb, off + 8);
if (preferred_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off, 4,
"Preferred lifetime: infinity");
} else {
proto_tree_add_text(subtree, tvb, off, 4,
"Preferred lifetime: %u", preferred_lifetime);
}
if (valid_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_text(subtree, tvb, off + 4, 4,
"Valid lifetime: infinity");
} else {
proto_tree_add_text(subtree, tvb, off + 4, 4,
"Valid lifetime: %u", valid_lifetime);
}
proto_tree_add_text(subtree, tvb, off + 8, 1,
"Prefix length: %d", prefix_length);
tvb_get_ipv6(tvb, off + 9, &in6_local);
proto_tree_add_text(subtree, tvb, off + 9,
16, "Prefix address: %s",
ip6_to_str(&in6_local));
temp_optlen = 25;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end);
if (*at_end) {
temp_optlen = optlen;
}
}
}
break;
case OPTION_MIP6_HA:
if (optlen != 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"MIP6_HA: malformed option");
break;
}
tvb_get_ipv6(tvb, off, &in6);
proto_tree_add_text(subtree, tvb, off,
16, "Home Agent: %s", ip6_to_str(&in6));
break;
case OPTION_MIP6_HOA:
if (optlen != 16) {
proto_tree_add_text(subtree, tvb, off, optlen,
"MIP6_HOA: malformed option");
break;
}
tvb_get_ipv6(tvb, off, &in6);
proto_tree_add_text(subtree, tvb, off,
16, "Home Address: %s", ip6_to_str(&in6));
break;
case OPTION_NAI:
if (optlen < 4) {
proto_tree_add_text(subtree, tvb, off, optlen,
"NAI: malformed option");
break;
}
proto_tree_add_text(subtree, tvb, off, optlen,
"NAI : %s", tvb_get_ephemeral_string(tvb, off, optlen - 2));
break;
}
return 4 + optlen;
}
static void
dissect_dhcpv6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean downstream, int off, int eoff)
{
proto_tree *bp_tree = NULL;
proto_item *ti;
guint8 msgtype;
gboolean at_end;
struct e_in6_addr in6;
msgtype = tvb_get_guint8(tvb, off);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str(msgtype, msgtype_vals, "Message Type %u"));
if (tree) {
ti = proto_tree_add_item(tree, proto_dhcpv6, tvb, off, eoff - off, ENC_NA);
bp_tree = proto_item_add_subtree(ti, ett_dhcpv6);
}
if (msgtype == RELAY_FORW || msgtype == RELAY_REPLY) {
if (tree) {
proto_tree_add_item(bp_tree, hf_dhcpv6_msgtype, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_dhcpv6_hopcount, tvb, off + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_dhcpv6_linkaddr, tvb, off + 2, 16, ENC_NA);
tvb_get_ipv6(tvb, off + 2, &in6);
col_append_fstr(pinfo->cinfo, COL_INFO, "L: %s ", ip6_to_str(&in6));
proto_tree_add_item(bp_tree, hf_dhcpv6_peeraddr, tvb, off + 18, 16, ENC_NA);
}
off += 34;
} else {
if (tree) {
proto_tree_add_item(bp_tree, hf_dhcpv6_msgtype, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_dhcpv6_xid, tvb, off + 1, 3, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "XID: 0x%x ", tvb_get_ntoh24(tvb, off + 1));
off += 4;
}
at_end = FALSE;
while (off < eoff && !at_end)
off += dhcpv6_option(tvb, pinfo, bp_tree, downstream, off, eoff, &at_end);
}
static void
dissect_dhcpv6_downstream(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPv6");
col_clear(pinfo->cinfo, COL_INFO);
dissect_dhcpv6(tvb, pinfo, tree, TRUE, 0, tvb_reported_length(tvb));
}
static void
dissect_dhcpv6_upstream(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPv6");
col_clear(pinfo->cinfo, COL_INFO);
dissect_dhcpv6(tvb, pinfo, tree, FALSE, 0, tvb_reported_length(tvb));
}
void
proto_register_dhcpv6(void)
{
static hf_register_info hf[] = {
{ &hf_dhcpv6_msgtype,
{ "Message type", "dhcpv6.msgtype", FT_UINT8, BASE_DEC, VALS(msgtype_vals), 0x0, NULL, HFILL }},
{ &hf_dhcpv6_hopcount,
{ "Hopcount", "dhcpv6.hopcount", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_xid,
{ "Transaction ID", "dhcpv6.xid", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_linkaddr,
{ "Link address", "dhcpv6.linkaddr", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_peeraddr,
{ "Peer address", "dhcpv6.peeraddr", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_option_type,
{ "Option", "dhcpv6.option.type", FT_UINT16, BASE_DEC, VALS(opttype_vals), 0x0, NULL, HFILL}},
{ &hf_option_length,
{ "Length", "dhcpv6.option.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_option_value,
{ "Value", "dhcpv6.option.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_clientfqdn_reserved,
{ "Reserved", "dhcpv6.clientfqdn.reserved", FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL}},
{ &hf_clientfqdn_n,
{ "N bit", "dhcpv6.clientfqdn.n", FT_BOOLEAN, 8, TFS(&fqdn_n), 0x4, "Whether the server SHOULD NOT perform any DNS updates", HFILL}},
{ &hf_clientfqdn_o,
{ "O bit", "dhcpv6.clientfqdn.o", FT_BOOLEAN, 8, TFS(&fqdn_o), 0x2, "Whether the server has overridden the client's preference for the S bit. Must be 0 when sent from client", HFILL}},
{ &hf_clientfqdn_s,
{ "S bit", "dhcpv6.clientfqdn.s", FT_BOOLEAN, 8, TFS(&fqdn_s), 0x1, "Whether the server SHOULD or SHOULD NOT perform the AAAA RR (FQDN-to-address) DNS updates", HFILL}},
{ &hf_remoteid_enterprise,
{ "Enterprise ID", "dhcpv6.remoteid.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "RemoteID Enterprise Number", HFILL }},
{ &hf_vendoropts_enterprise,
{ "Enterprise ID", "dhcpv6.vendoropts.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "Vendor opts Enterprise Number", HFILL }},
{ &hf_vendorclass_enterprise,
{ "Enterprise ID", "dhcpv6.vendorclass.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "Vendor Class Enterprise Number", HFILL }},
{ &hf_duiden_enterprise,
{ "Enterprise ID", "dhcpv6.duiden.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "DUID EN Enterprise Number", HFILL }},
};
static gint *ett[] = {
&ett_dhcpv6,
&ett_dhcpv6_option,
&ett_dhcpv6_option_vsoption,
&ett_dhcpv6_vendor_option,
&ett_dhcpv6_pkt_option,
};
proto_dhcpv6 = proto_register_protocol("DHCPv6", "DHCPv6", "dhcpv6");
proto_register_field_array(proto_dhcpv6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("dhcpv6", dissect_dhcpv6_upstream, proto_dhcpv6);
}
void
proto_reg_handoff_dhcpv6(void)
{
dissector_handle_t dhcpv6_handle;
dhcpv6_handle = create_dissector_handle(dissect_dhcpv6_downstream,
proto_dhcpv6);
dissector_add_uint("udp.port", UDP_PORT_DHCPV6_DOWNSTREAM, dhcpv6_handle);
dhcpv6_handle = create_dissector_handle(dissect_dhcpv6_upstream,
proto_dhcpv6);
dissector_add_uint("udp.port", UDP_PORT_DHCPV6_UPSTREAM, dhcpv6_handle);
}
