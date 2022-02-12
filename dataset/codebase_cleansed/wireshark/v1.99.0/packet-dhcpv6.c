static void
initialize_hopount_info(hopcount_info *hpi) {
memset(hpi, 0, sizeof(hopcount_info));
}
static int
dissect_packetcable_ccc_option(proto_tree *v_tree, proto_item *v_item, packet_info *pinfo, tvbuff_t *tvb, int optoff,
int optend)
{
int suboptoff = optoff;
guint16 subopt, subopt_len;
proto_item *vti;
proto_tree *pkt_s_tree;
subopt = tvb_get_ntohs(tvb, optoff);
suboptoff += 2;
subopt_len = tvb_get_ntohs(tvb, suboptoff);
suboptoff += 2;
if (optend <= 0) {
expert_add_info_format(pinfo, v_item, &ei_dhcpv6_no_suboption_len, "Sub element %d: no room left in option for suboption length", subopt);
return (optend);
}
vti = proto_tree_add_item(v_tree, hf_packetcable_ccc_suboption, tvb, optoff, 2, ENC_BIG_ENDIAN);
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
switch (subopt) {
case PKT_CCC_PRI_DHCP:
if (subopt_len == 4) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_ccc_pri_dhcp, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
}
else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCC_SEC_DHCP:
if (subopt_len == 4) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_ccc_sec_dhcp, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
}
else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
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
dhcpv6_domain(proto_tree *subtree, proto_item *v_item, packet_info *pinfo, int hfindex, tvbuff_t *tvb, int offset, guint16 optlen)
{
int start_offset = offset;
char domain[256];
int pos;
guint8 len;
pos = 0;
while (optlen) {
if (!pos) {
start_offset = offset;
}
domain[pos] = '\0';
len = tvb_get_guint8(tvb, offset);
if (optlen < len) {
expert_add_info(pinfo, v_item, &ei_dhcpv6_malformed_dns);
return;
}
offset += 1;
optlen -= 1;
if (!len) {
if (!pos) {
expert_add_info(pinfo, v_item, &ei_dhcpv6_malformed_option);
return;
} else {
proto_tree_add_string(subtree, hfindex, tvb, start_offset, offset-start_offset, domain);
pos = 0;
continue;
}
}
if (pos) {
domain[pos] = '.';
pos++;
}
if ((pos + len) > 254) {
expert_add_info(pinfo, v_item, &ei_dhcpv6_malformed_option);
return;
}
tvb_memcpy(tvb, domain+pos, offset, len);
pos += len;
offset += len;
optlen -= len;
}
if (pos) {
domain[pos] = '\0';
proto_tree_add_string(subtree, hfindex, tvb, start_offset, offset-start_offset, domain);
}
}
static int
dissect_packetcable_cccV6_option(proto_tree *v_tree, proto_item *v_item, packet_info *pinfo, tvbuff_t *tvb, int optoff,
int optend)
{
int suboptoff = optoff;
guint16 subopt, subopt_len;
guint8 type;
proto_item *vti, *ti;
proto_tree *pkt_s_tree;
int i;
subopt = tvb_get_ntohs(tvb, optoff);
suboptoff += 2;
subopt_len = tvb_get_ntohs(tvb, suboptoff);
suboptoff += 2;
if (optend <= 0) {
expert_add_info_format(pinfo, v_item, &ei_dhcpv6_no_suboption_len, "Sub element %d: no room left in option for suboption length", subopt);
return (optend);
}
vti = proto_tree_add_item(v_tree, hf_packetcable_cccV6_suboption, tvb, optoff, 2, ENC_BIG_ENDIAN);
pkt_s_tree = proto_item_add_subtree(vti, ett_dhcpv6_pkt_option);
switch (subopt) {
case PKT_CCCV6_PRI_DSS:
if (subopt_len < 35) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_pri_dss, tvb, suboptoff, subopt_len, ENC_ASCII|ENC_NA);
} else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_SEC_DSS:
if (subopt_len < 35) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_sec_dss, tvb, suboptoff, subopt_len, ENC_ASCII|ENC_NA);
} else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_PROV_SRV:
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_prov_srv_type, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
type = tvb_get_guint8(tvb, suboptoff);
if (type == 0) {
dhcpv6_domain(pkt_s_tree, vti, pinfo, hf_packetcable_cccV6_prov_srv_fqdn, tvb, suboptoff+1, subopt_len-1);
} else if (type == 1) {
if ((subopt_len % 16) == 0) {
for (i = 0; i < subopt_len/16; i++) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_prov_srv_ipv6, tvb, suboptoff+1, 4, ENC_NA);
suboptoff += 16;
}
}
} else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_invalid_type, "Invalid type: %u (%u byte%s)",
type, subopt_len, plurality(subopt_len, "", "s"));
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_AS_KRB:
if (subopt_len == 12) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_as_krb_nominal_timeout, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_as_krb_max_timeout, tvb, suboptoff+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_as_krb_max_retry_count, tvb, suboptoff+8, 4, ENC_BIG_ENDIAN);
} else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_AP_KRB:
if (subopt_len == 12) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_ap_krb_nominal_timeout, tvb, suboptoff, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_ap_krb_max_timeout, tvb, suboptoff+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_ap_krb_max_retry_count, tvb, suboptoff+8, 4, ENC_BIG_ENDIAN);
} else {
proto_item_append_text(vti, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_KRB_REALM:
if (subopt_len > 0) {
dhcpv6_domain(pkt_s_tree, vti, pinfo, hf_packetcable_cccV6_krb_realm, tvb, suboptoff, subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_TGT_FLAG:
if (subopt_len == 1) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_tgt_flag, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_tgt_flag_fetch, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
}
else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_PROV_TIMER:
if (subopt_len == 1) {
ti = proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_prov_timer, tvb, suboptoff, 1, ENC_BIG_ENDIAN);
if (tvb_get_guint8(tvb, suboptoff) > 30)
expert_add_info(pinfo, ti, &ei_dhcpv6_invalid_time_value);
}
else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
}
suboptoff += subopt_len;
break;
case PKT_CCCV6_IETF_SEC_TKT:
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_sec_tcm, tvb, suboptoff, 2, ENC_BIG_ENDIAN);
if (subopt_len == 2) {
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_sec_tcm_provisioning_server, tvb, suboptoff, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pkt_s_tree, hf_packetcable_cccV6_sec_tcm_call_manager_server, tvb, suboptoff, 2, ENC_BIG_ENDIAN);
} else {
expert_add_info_format(pinfo, vti, &ei_dhcpv6_bogus_length, "Bogus length: %d", subopt_len);
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
dissect_cablelabs_specific_opts(proto_tree *v_tree, proto_item *v_item, packet_info *pinfo, tvbuff_t *tvb, int voff, int len)
{
guint16 type,
tlv_len,
opt_len,
sub_value;
proto_item *ti;
proto_item *ti2;
proto_tree *subtree;
proto_tree *subtree2;
gint tlv5_cap_index,
tlv5_counter,
tlv5_cap_len;
int off = voff,
sub_off,
i,
field_len,
field_value;
gchar *device_type = NULL;
if (len > 4) {
while (off - voff < len) {
type = tvb_get_ntohs(tvb, off);
ti = proto_tree_add_item(v_tree, hf_cablelabs_opts, tvb, off, 2, ENC_BIG_ENDIAN);
tlv_len = tvb_get_ntohs(tvb, off+2);
sub_off = off + 4;
switch (type) {
case CL_OPTION_DEVICE_TYPE:
opt_len = tlv_len;
field_len = tlv_len;
device_type = tvb_get_string_enc(wmem_packet_scope(), tvb, sub_off, field_len, ENC_ASCII);
if ((device_type == NULL) || (strlen(device_type) == 0)) {
proto_item_append_text(ti, "Packet does not contain Device Type.");
} else {
proto_item_append_text(ti, "\"%s\"", device_type);
}
break;
case CL_OPTION_DEVICE_SERIAL_NUMBER:
case CL_OPTION_HARDWARE_VERSION_NUMBER:
case CL_OPTION_SOFTWARE_VERSION_NUMBER:
case CL_OPTION_BOOT_ROM_VERSION:
case CL_OPTION_MODEL_NUMBER:
case CL_OPTION_VENDOR_NAME:
case CL_OPTION_CONFIG_FILE_NAME:
case CL_OPTION_EMBEDDED_COMPONENT_LIST:
opt_len = tlv_len;
field_len = tlv_len;
proto_item_append_text(ti, "\"%s\"",
tvb_format_stringzpad(tvb, sub_off, field_len));
break;
case CL_OPTION_VENDOR_OUI:
opt_len = tlv_len;
if (tlv_len == 3) {
proto_item_append_text(ti, "%s",
tvb_bytes_to_ep_str_punct(tvb, sub_off, 3, ':'));
} else if (tlv_len == 6) {
proto_item_append_text(ti, "\"%s\"", tvb_format_stringzpad(tvb, sub_off, tlv_len));
} else {
expert_add_info_format(pinfo, ti, &ei_dhcpv6_bogus_length, "Suboption %d: suboption length isn't 3 or 6", type);
}
break;
case CL_OPTION_ORO:
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
case CL_OPTION_TFTP_SERVERS:
case CL_OPTION_SYSLOG_SERVERS:
case CL_OPTION_RFC868_SERVERS:
field_len = 16;
opt_len = tlv_len;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
if ((tlv_len % field_len) == 0) {
for (i = 0; i < tlv_len/field_len; i++) {
ti = proto_tree_add_item(subtree, hf_cablelabs_ipv6_server, tvb, sub_off, 16, ENC_NA);
proto_item_prepend_text(ti, " %d ", i + 1);
sub_off += field_len;
}
}
break;
case CL_OPTION_DEVICE_ID:
opt_len = tlv_len;
field_len = tlv_len;
if (tlv_len != 6) {
expert_add_info_format(pinfo, ti, &ei_dhcpv6_bogus_length, "Bogus length: %d", tlv_len);
}
else {
proto_item_append_text(ti, "%s",
tvb_bytes_to_ep_str(tvb, sub_off, field_len));
}
break;
case CL_OPTION_TLV5:
opt_len = tlv_len;
if (device_type == NULL)
break;
tlv5_counter = 0;
tlv5_cap_index = sub_off;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_tlv5_type);
while (tlv5_counter < tlv_len) {
if (!g_ascii_strncasecmp(device_type, "ecm", 3)) {
ti2 = proto_tree_add_item(subtree, hf_modem_capabilities_encoding_type, tvb, tlv5_cap_index, 1, ENC_BIG_ENDIAN);
} else if (!g_ascii_strncasecmp(device_type, "edva", 3)) {
ti2 = proto_tree_add_item(subtree, hf_eue_capabilities_encoding_type, tvb, tlv5_cap_index, 1, ENC_BIG_ENDIAN);
} else {
break;
}
tlv5_cap_index++;
tlv5_counter++;
subtree2 = proto_item_add_subtree(ti2, ett_dhcpv6_tlv5_type);
proto_tree_add_item(subtree2, hf_capabilities_encoding_length, tvb, tlv5_cap_index, 1, ENC_BIG_ENDIAN);
tlv5_cap_len = (guint8) tvb_get_guint8(tvb, tlv5_cap_index);
tlv5_cap_index++;
tlv5_counter += tlv5_cap_len;
if (tlv5_cap_len > 2) {
proto_tree_add_item(subtree2, hf_capabilities_encoding_bytes, tvb, tlv5_cap_index, tlv5_cap_len, ENC_NA);
} else {
proto_tree_add_item(subtree2, hf_capabilities_encoding_number, tvb, tlv5_cap_index, tlv5_cap_len, ENC_BIG_ENDIAN);
}
tlv5_cap_index += tlv5_cap_len;
tlv5_counter++;
}
break;
case CL_OPTION_TIME_OFFSET:
opt_len = tlv_len;
proto_item_append_text(ti, "%d", tvb_get_ntohl(tvb, sub_off));
break;
case CL_OPTION_IP_PREF:
opt_len = tlv_len;
field_value = tvb_get_guint8(tvb, sub_off);
if (field_value == 1) {
proto_item_append_text(ti, "%s", "IPv4");
} else if (field_value == 2) {
proto_item_append_text(ti, "%s", "IPv6");
} else if (field_value == 6) {
proto_item_append_text(ti, "%s", "Dual Stack");
} else {
proto_item_append_text(ti, "%s%d", "Invalid IP Preference value ", field_value);
}
break;
case CL_OPTION_DOCS_CMTS_CAP:
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
if ((tag == CL_OPTION_DOCS_CMTS_TLV_VERS_NUM) && (tagLen == 2)) {
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
case CL_CM_MAC_ADDR:
opt_len = tlv_len;
if (tlv_len != 6) {
expert_add_info_format(pinfo, ti, &ei_dhcpv6_bogus_length, "Bogus length: %d", tlv_len);
}
else {
proto_item_append_text(ti, "%s", tvb_bytes_to_ep_str_punct(tvb, sub_off, opt_len, ':'));
}
break;
case CL_EROUTER_CONTAINER_OPTION:
opt_len = tlv_len;
proto_item_append_text(ti, " %s (len=%d)",
tvb_bytes_to_ep_str(tvb, sub_off, opt_len), tlv_len);
break;
case CL_OPTION_CCC:
opt_len = tlv_len;
field_len = 0;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
proto_item_append_text(ti, " (%d bytes)", opt_len);
while (field_len < opt_len) {
sub_value = dissect_packetcable_ccc_option(subtree, ti, pinfo, tvb,
sub_off, (opt_len - field_len));
sub_off += sub_value;
field_len += sub_value;
}
break;
case CL_OPTION_CCCV6:
opt_len = tlv_len;
field_len = 0;
subtree = proto_item_add_subtree(ti, ett_dhcpv6_vendor_option);
proto_item_append_text(ti, " (%d bytes)", opt_len);
while (field_len < opt_len) {
sub_value = dissect_packetcable_cccV6_option(subtree, ti, pinfo, tvb,
sub_off, (opt_len - field_len));
sub_off += sub_value;
field_len += sub_value;
}
break;
case CL_OPTION_CORRELATION_ID:
opt_len = tlv_len;
if (tlv_len != 4) {
proto_item_append_text(ti, "Bogus value length=%d",
tlv_len);
}
else {
proto_item_append_text(ti, "%u", tvb_get_ntohl(tvb, sub_off));
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
expert_add_info_format(pinfo, v_item, &ei_dhcpv6_bogus_length, "Bogus length: %d", len);
}
}
static int
dhcpv6_option(tvbuff_t *tvb, packet_info *pinfo, proto_tree *bp_tree,
gboolean downstream, int off, int eoff, gboolean *at_end, int protocol, hopcount_info hpi)
{
guint16 opttype, hwtype, subopt_type;
int temp_optlen, optlen, subopt_len;
proto_item *ti = NULL, *option_item;
proto_tree *subtree;
proto_tree *subtree_2;
int i;
guint16 duidtype;
guint32 enterprise_no;
if ((eoff - off) < 4) {
*at_end = TRUE;
return 0;
}
opttype = tvb_get_ntohs(tvb, off);
optlen = tvb_get_ntohs(tvb, off + 2);
if ((eoff - off) < (4 + optlen)) {
*at_end = TRUE;
return 0;
}
subtree = proto_tree_add_subtree(bp_tree, tvb, off, 4 + optlen, ett_dhcpv6_option, &option_item,
val_to_str_ext(opttype, &opttype_vals_ext, "DHCP option %u"));
proto_tree_add_item(subtree, hf_option_type, tvb, off, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_option_length, tvb, off + 2, 2, ENC_BIG_ENDIAN);
off += 4;
if (optlen)
proto_tree_add_item(subtree, hf_option_value, tvb, off, optlen, ENC_NA);
switch (opttype) {
case OPTION_CLIENTID:
col_append_fstr(pinfo->cinfo, COL_INFO, "CID: %s ", tvb_bytes_to_ep_str(tvb, off, optlen));
case OPTION_SERVERID:
case OPTION_RELAYID:
if (optlen < 2) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "DUID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_duid_bytes, tvb, off, optlen, ENC_NA);
duidtype = tvb_get_ntohs(tvb, off);
proto_tree_add_item(subtree, hf_duid_type, tvb, off, 2, ENC_BIG_ENDIAN);
switch (duidtype) {
case DUID_LLT:
{
nstime_t llt_time;
if (optlen < 8) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "DUID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_duidllt_hwtype, tvb, off + 2, 2, ENC_BIG_ENDIAN);
llt_time.secs = tvb_get_ntohl(tvb, off + 4) + 946684800U;
llt_time.nsecs = 0;
proto_tree_add_time(subtree, hf_duidllt_time, tvb, off + 4, 4, &llt_time);
if (optlen > 8) {
hwtype = tvb_get_ntohs(tvb, off + 2);
proto_tree_add_string(subtree, hf_duidllt_link_layer_addr, tvb, off + 8,
optlen - 8, tvb_arphrdaddr_to_str(tvb, off+8, optlen-8, hwtype));
}
}
break;
case DUID_EN:
if (optlen < 6) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "DUID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_duiden_enterprise, tvb, off + 2, 4, ENC_BIG_ENDIAN);
if (optlen > 6) {
proto_tree_add_item(subtree, hf_duiden_identifier, tvb, off + 6, optlen - 6, ENC_NA);
}
break;
case DUID_LL:
case DUID_LL_OLD:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "DUID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_duidll_hwtype, tvb, off + 2, 2, ENC_BIG_ENDIAN);
if (optlen > 4) {
hwtype = tvb_get_ntohs(tvb, off + 2);
proto_tree_add_string(subtree, hf_duidll_link_layer_addr, tvb, off + 4,
optlen - 4, tvb_arphrdaddr_to_str(tvb, off+4, optlen-4, hwtype));
}
break;
}
break;
case OPTION_NTP_SERVER:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "NTP Server: malformed option");
break;
}
temp_optlen = 0;
while (optlen > temp_optlen) {
subopt_type = tvb_get_ntohs(tvb, off + temp_optlen);
subopt_len = tvb_get_ntohs(tvb, off + 2 + temp_optlen);
subtree_2 = proto_tree_add_subtree(subtree, tvb, off+temp_optlen, 4 + subopt_len, ett_dhcpv6_netserver_option, &ti,
val_to_str(subopt_type, ntp_server_opttype_vals, "NTP Server suboption %u"));
proto_tree_add_item(subtree_2, hf_option_ntpserver_type, tvb, off + temp_optlen, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree_2, hf_option_ntpserver_length, tvb, off + temp_optlen + 2, 2, ENC_BIG_ENDIAN);
temp_optlen += 4;
switch (subopt_type) {
case NTP_SUBOPTION_SRV_ADDR:
proto_tree_add_item(subtree_2, hf_option_ntpserver_addr, tvb, off + temp_optlen, 16, ENC_NA);
break;
case NTP_SUBOPTION_MC_ADDR:
proto_tree_add_item(subtree_2, hf_option_ntpserver_mc_addr, tvb, off + temp_optlen, 16, ENC_NA);
break;
case NTP_SUBOPTION_SRV_FQDN:
dhcpv6_domain(subtree_2, ti, pinfo, hf_option_ntpserver_fqdn, tvb, off + temp_optlen, subopt_len);
break;
}
temp_optlen += subopt_len;
}
break;
case OPTION_IA_NA:
case OPTION_IA_PD:
if (optlen < 12) {
if (opttype == OPTION_IA_NA)
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "IA_NA: malformed option");
else
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "IA_PD: malformed option");
break;
}
proto_tree_add_string(subtree, hf_iaid, tvb, off,
4, tvb_arphrdaddr_to_str(tvb, off, 4, opttype));
if (tvb_get_ntohl(tvb, off+4) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format_value(subtree, hf_iaid_t1, tvb, off+4,
4, DHCPV6_LEASEDURATION_INFINITY, "infinity");
} else {
proto_tree_add_item(subtree, hf_iaid_t1, tvb, off+4,
4, ENC_BIG_ENDIAN);
}
if (tvb_get_ntohl(tvb, off+8) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format_value(subtree, hf_iaid_t2, tvb, off+8,
4, DHCPV6_LEASEDURATION_INFINITY, "infinity");
} else {
proto_tree_add_item(subtree, hf_iaid_t2, tvb, off+8,
4, ENC_BIG_ENDIAN);
}
temp_optlen = 12;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end, protocol, hpi);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_IA_TA:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "IA_TA: malformed option");
break;
}
proto_tree_add_string(subtree, hf_iata, tvb, off,
4, tvb_arphrdaddr_to_str(tvb, off, 4, opttype));
temp_optlen = 4;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end, protocol, hpi);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_IAADDR:
{
guint32 preferred_lifetime, valid_lifetime;
if (optlen < 24) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "IA_TA: malformed option");
break;
}
proto_tree_add_item(subtree, hf_iaaddr_ip, tvb, off, 16, ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "IAA: %s ", tvb_ip6_to_str(tvb, off));
preferred_lifetime = tvb_get_ntohl(tvb, off + 16);
valid_lifetime = tvb_get_ntohl(tvb, off + 20);
if (preferred_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format_value(subtree, hf_iaaddr_pref_lifetime, tvb, off+16,
4, DHCPV6_LEASEDURATION_INFINITY, "infinity");
} else {
proto_tree_add_item(subtree, hf_iaaddr_pref_lifetime, tvb, off+16,
4, ENC_BIG_ENDIAN);
}
if (valid_lifetime == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format(subtree, hf_iaaddr_valid_lifetime, tvb, off+20,
4, DHCPV6_LEASEDURATION_INFINITY, "Preferred lifetime: infinity");
} else {
proto_tree_add_item(subtree, hf_iaaddr_valid_lifetime, tvb, off+20,
4, ENC_BIG_ENDIAN);
}
temp_optlen = 24;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end, protocol, hpi);
if (*at_end) {
temp_optlen = optlen;
}
}
}
break;
case OPTION_ORO:
case OPTION_ERO:
for (i = 0; i < optlen; i += 2) {
proto_tree_add_item(subtree, hf_requested_option_code, tvb, off+i,
2, ENC_BIG_ENDIAN);
}
break;
case OPTION_PREFERENCE:
if (optlen != 1) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "PREFERENCE: malformed option");
break;
}
proto_tree_add_item(subtree, hf_option_preference, tvb, off, 1, ENC_BIG_ENDIAN);
break;
case OPTION_ELAPSED_TIME:
if (optlen != 2) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "ELAPSED-TIME: malformed option");
break;
}
temp_optlen = tvb_get_ntohs(tvb, off);
proto_tree_add_uint_format_value(subtree, hf_elapsed_time, tvb, off,
2, temp_optlen*10, "%u ms", temp_optlen*10);
break;
case OPTION_RELAY_MSG:
if (optlen == 0) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "RELAY-MSG: malformed option");
} else {
dissect_dhcpv6(tvb, pinfo, subtree, downstream, off, off + optlen, hpi);
}
break;
case OPTION_AUTH:
if (optlen < 11) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "AUTH: malformed option");
break;
}
proto_tree_add_item(subtree, hf_auth_protocol, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_auth_algorithm, tvb, off+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_auth_rdm, tvb, off+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_auth_replay_detection, tvb, off+3, 8, ENC_NA);
if (optlen != 11)
proto_tree_add_item(subtree, hf_auth_info, tvb, off+11, optlen-11, ENC_NA);
break;
case OPTION_UNICAST:
if (optlen != 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "UNICAST: malformed option");
break;
}
proto_tree_add_item(subtree, hf_opt_unicast, tvb, off, 16, ENC_NA);
break;
case OPTION_STATUS_CODE:
proto_tree_add_item(subtree, hf_opt_status_code, tvb, off, 2, ENC_BIG_ENDIAN);
if (optlen > 2)
proto_tree_add_item(subtree, hf_opt_status_msg, tvb, off+2, optlen - 2, ENC_ASCII|ENC_NA);
break;
case OPTION_VENDOR_CLASS:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "VENDOR_CLASS: malformed option");
break;
}
proto_tree_add_item(subtree, hf_vendorclass_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
if (optlen > 4)
proto_tree_add_item(subtree, hf_vendorclass_data, tvb, off+6, optlen-6, ENC_ASCII|ENC_NA);
break;
case OPTION_VENDOR_OPTS:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "VENDOR_OPTS: malformed option");
break;
}
enterprise_no = tvb_get_ntohl(tvb, off);
ti = proto_tree_add_item(subtree, hf_vendoropts_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
if (optlen >= 4) {
if (enterprise_no == 4491) {
dissect_cablelabs_specific_opts(subtree, ti, pinfo, tvb, off+4, optlen-4);
} else {
int optoffset = 0;
while ((optlen - 4 - optoffset) > 0) {
int olen = tvb_get_ntohs(tvb, off + optoffset + 6);
subtree_2 = proto_tree_add_subtree(subtree, tvb, off + optoffset + 4,
4 + olen, ett_dhcpv6_option_vsoption, NULL, "option");
proto_tree_add_item(subtree_2, hf_vendoropts_enterprise_option_code, tvb, off + optoffset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree_2, hf_vendoropts_enterprise_option_length, tvb, off + optoffset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree_2, hf_vendoropts_enterprise_option_data, tvb, off + optoffset + 8, olen, ENC_NA);
optoffset += (4 + olen);
}
}
}
break;
case OPTION_INTERFACE_ID:
{
if (optlen == 0) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "INTERFACE_ID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_interface_id, tvb, off, optlen, ENC_NA);
}
break;
case OPTION_RECONF_MSG:
if (optlen != 1) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "RECONF_MSG: malformed option");
break;
}
proto_tree_add_item(subtree, hf_reconf_msg, tvb, off, 1, ENC_BIG_ENDIAN);
break;
case OPTION_RECONF_ACCEPT:
if (optlen)
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "RECONF_ACCEPT: malformed option");
break;
case OPTION_SIP_SERVER_D:
if (optlen > 0) {
ti = proto_tree_add_text(subtree, tvb, off, optlen, "SIP Servers Domain Search List");
dhcpv6_domain(subtree, ti, pinfo, hf_sip_server_domain_search_fqdn, tvb, off, optlen);
}
break;
case OPTION_SIP_SERVER_A:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "SIP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_sip_server_a, tvb, off + i, 16, ENC_NA);
break;
case OPTION_DNS_SERVERS:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "DNS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16) {
ti = proto_tree_add_item(subtree, hf_dns_servers, tvb, off + i, 16, ENC_NA);
proto_item_prepend_text(ti, " %d ", i/16 + 1);
}
break;
case OPTION_DOMAIN_LIST:
if (optlen > 0) {
ti = proto_tree_add_text(subtree, tvb, off, optlen, "DNS Domain Search List");
dhcpv6_domain(subtree, ti, pinfo, hf_domain_search_list_fqdn, tvb, off, optlen);
}
break;
case OPTION_NIS_SERVERS:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "NIS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_nis_servers, tvb, off + i, 16, ENC_NA);
break;
case OPTION_NISP_SERVERS:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "NISP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_nisp_servers, tvb, off + i, 16, ENC_NA);
break;
case OPTION_NIS_DOMAIN_NAME:
if (optlen > 0) {
ti = proto_tree_add_text(subtree, tvb, off, optlen, "nis-domain-name");
dhcpv6_domain(subtree, ti, pinfo, hf_nis_fqdn, tvb, off, optlen);
}
break;
case OPTION_NISP_DOMAIN_NAME:
if (optlen > 0) {
ti = proto_tree_add_text(subtree, tvb, off, optlen, "nisp-domain-name");
dhcpv6_domain(subtree, ti, pinfo, hf_nisp_fqdn, tvb, off, optlen);
}
break;
case OPTION_SNTP_SERVERS:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "SNTP servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
ti = proto_tree_add_item(subtree, hf_sntp_servers, tvb, off + i, 16, ENC_NA);
proto_item_prepend_text(ti, " %d ", i/16 + 1);
break;
case OPTION_LIFETIME:
if (optlen != 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "LIFETIME: malformed option");
break;
}
proto_tree_add_item(subtree, hf_opt_lifetime, tvb, off, 4, ENC_BIG_ENDIAN);
break;
case OPTION_BCMCS_SERVER_D:
if (optlen > 0) {
ti = proto_tree_add_text(subtree, tvb, off, optlen, "BCMCS Servers Domain Search List");
dhcpv6_domain(subtree, ti, pinfo, hf_bcmcs_servers_fqdn, tvb, off, optlen);
}
break;
case OPTION_BCMCS_SERVER_A:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "BCMCS servers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_bcmcs_servers_a, tvb, off + i, 16, ENC_NA);
break;
case OPTION_REMOTE_ID:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "REMOTE_ID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_remoteid_enterprise, tvb, off, 4, ENC_BIG_ENDIAN);
off += 4;
proto_tree_add_item(subtree, hf_remoteid_enterprise_id, tvb, off, optlen - 4, ENC_NA);
break;
case OPTION_SUBSCRIBER_ID:
if (optlen == 0) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "SUBSCRIBER_ID: malformed option");
break;
}
proto_tree_add_item(subtree, hf_subscriber_id, tvb, off, optlen, ENC_ASCII|ENC_NA);
break;
case OPTION_CLIENT_FQDN:
if (optlen < 1) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "FQDN: malformed option");
} else {
proto_tree_add_item(subtree, hf_clientfqdn_reserved, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_n, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_o, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_clientfqdn_s, tvb, off, 1, ENC_BIG_ENDIAN);
dhcpv6_domain(subtree, option_item, pinfo, hf_client_fqdn, tvb, off+1, optlen-1);
}
break;
case OPTION_PANA_AGENT:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "PANA agent address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_pana_agent, tvb, off + i, 16, ENC_NA);
break;
case OPTION_TIME_ZONE:
if (optlen > 0)
proto_tree_add_item(subtree, hf_opt_timezone, tvb, off, optlen, ENC_ASCII|ENC_NA);
break;
case OPTION_TZDB:
if (optlen > 0)
proto_tree_add_item(subtree, hf_opt_tzdb, tvb, off, optlen, ENC_ASCII|ENC_NA);
break;
case OPTION_LQ_QUERY:
{
guint8 query_type;
if (optlen < 17) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "LQ-QUERY: malformed option");
break;
}
query_type = tvb_get_guint8(tvb, off);
ti = proto_tree_add_item(subtree, hf_lq_query, tvb, off, 1, ENC_BIG_ENDIAN);
if ((protocol == proto_dhcpv6) &&
((query_type == LQ_QUERY_RELAYID) ||
(query_type == LQ_QUERY_LINK_ADDRESS) ||
(query_type == LQ_QUERY_REMOTEID))) {
expert_add_info(pinfo, ti, &ei_dhcpv6_bulk_leasequery_bad_query_type);
}
proto_tree_add_item(subtree, hf_lq_query_link_address, tvb, off+1, 16, ENC_NA);
temp_optlen = 17;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree,
downstream, off + temp_optlen,
off + optlen, at_end, protocol, hpi);
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
off + optlen, at_end, protocol, hpi);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_CLT_TIME:
if (optlen != 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "CLT_TIME: malformed option");
break;
}
proto_tree_add_item(subtree, hf_clt_time, tvb, off, 4, ENC_BIG_ENDIAN);
break;
case OPTION_LQ_RELAY_DATA:
if (optlen < 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "LQ_RELAY_DATA: malformed option");
break;
}
if (protocol == proto_dhcpv6_bulk_leasequery) {
expert_add_info(pinfo, option_item, &ei_dhcpv6_bulk_leasequery_no_lq_relay_data);
}
proto_tree_add_item(subtree, hf_lq_relay_data_peer_addr, tvb, off, 16, ENC_NA);
proto_tree_add_item(subtree, hf_lq_relay_data_msg, tvb, off+16, optlen - 16, ENC_ASCII|ENC_NA);
break;
case OPTION_LQ_CLIENT_LINK:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "LQ client links address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_lq_client_link, tvb, off + i, 16, ENC_NA);
break;
case OPTION_CAPWAP_AC_V6:
if (optlen % 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "CAPWAP Access Controllers address: malformed option");
break;
}
for (i = 0; i < optlen; i += 16)
proto_tree_add_item(subtree, hf_capwap_ac_v6, tvb, off + i, 16, ENC_NA);
break;
case OPTION_AFTR_NAME:
{
dhcpv6_domain(subtree, option_item, pinfo, hf_aftr_name, tvb, off, optlen);
break;
}
case OPTION_IAPREFIX:
if (optlen < 25) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "IAPREFIX: malformed option");
break;
}
if (tvb_get_ntohl(tvb, off) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format_value(subtree, hf_iaprefix_pref_lifetime, tvb, off,
4, DHCPV6_LEASEDURATION_INFINITY, "infinity");
} else {
proto_tree_add_item(subtree, hf_iaprefix_pref_lifetime, tvb, off,
4, ENC_BIG_ENDIAN);
}
if (tvb_get_ntohl(tvb, off + 4) == DHCPV6_LEASEDURATION_INFINITY) {
proto_tree_add_uint_format_value(subtree, hf_iaprefix_valid_lifetime, tvb, off+4,
4, DHCPV6_LEASEDURATION_INFINITY, "infinity");
} else {
proto_tree_add_item(subtree, hf_iaprefix_valid_lifetime, tvb, off+4,
4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(subtree, hf_iaprefix_pref_len, tvb, off+8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_iaprefix_pref_addr, tvb, off+9, 16, ENC_NA);
temp_optlen = 25;
while ((optlen - temp_optlen) > 0) {
temp_optlen += dhcpv6_option(tvb, pinfo, subtree, downstream,
off+temp_optlen, off + optlen, at_end, protocol, hpi);
if (*at_end) {
temp_optlen = optlen;
}
}
break;
case OPTION_MIP6_HA:
if (optlen != 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "MIP6_HA: malformed option");
break;
}
proto_tree_add_item(subtree, hf_mip6_ha, tvb, off, 16, ENC_NA);
break;
case OPTION_MIP6_HOA:
if (optlen != 16) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "MIP6_HOA: malformed option");
break;
}
proto_tree_add_item(subtree, hf_mip6_hoa, tvb, off, 16, ENC_NA);
break;
case OPTION_NAI:
if (optlen < 4) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "NAI: malformed option");
break;
}
proto_tree_add_item(subtree, hf_nai, tvb, off, optlen - 2, ENC_ASCII|ENC_NA);
break;
case OPTION_PD_EXCLUDE:
if ((optlen < 2) || (optlen > 17)) {
expert_add_info_format(pinfo, option_item, &ei_dhcpv6_malformed_option, "PD_EXCLUDE: malformed option");
break;
}
proto_tree_add_item(subtree, hf_pd_exclude_pref_len, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_pd_exclude_subnet_id , tvb, off+1, optlen-1, ENC_NA);
break;
}
return 4 + optlen;
}
static void
dissect_dhcpv6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean downstream, int off, int eoff, hopcount_info hpi)
{
proto_tree *bp_tree = NULL;
proto_item *ti;
guint8 msgtype;
gboolean at_end;
struct e_in6_addr in6;
msgtype = tvb_get_guint8(tvb, off);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_ext(msgtype, &msgtype_vals_ext, "Message Type %u"));
if (tree) {
ti = proto_tree_add_item(tree, proto_dhcpv6, tvb, off, eoff - off, ENC_NA);
bp_tree = proto_item_add_subtree(ti, ett_dhcpv6);
}
if ((msgtype == RELAY_FORW) || (msgtype == RELAY_REPLY)) {
const guint8 previous_hopcount = hpi.hopcount;
proto_item *previous_pi = hpi.pi;
if (tree) {
proto_tree_add_item(bp_tree, hf_dhcpv6_msgtype, tvb, off, 1, ENC_BIG_ENDIAN);
hpi.pi = proto_tree_add_item(bp_tree, hf_dhcpv6_hopcount, tvb, off + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_dhcpv6_linkaddr, tvb, off + 2, 16, ENC_NA);
proto_tree_add_item(bp_tree, hf_dhcpv6_peeraddr, tvb, off + 18, 16, ENC_NA);
}
hpi.hopcount = tvb_get_guint8(tvb, off + 1);
if (hpi.hopcount > HOP_COUNT_LIMIT) {
expert_add_info_format(pinfo, hpi.pi, &ei_dhcpv6_error_hopcount, "Hopcount (%d) exceeds the maximum limit HOP_COUNT_LIMIT (%d)", hpi.hopcount, HOP_COUNT_LIMIT);
}
if (hpi.relay_message_previously_detected && hpi.hopcount != previous_hopcount - 1) {
expert_add_info_format(pinfo, previous_pi, &ei_dhcpv6_error_hopcount, "hopcount is not correctly incremented by 1 (expected : %d, actual : %d)", hpi.hopcount + 1, previous_hopcount);
}
hpi.relay_message_previously_detected = TRUE;
tvb_get_ipv6(tvb, off + 2, &in6);
col_append_fstr(pinfo->cinfo, COL_INFO, "L: %s ", ip6_to_str(&in6));
off += 34;
} else {
if (hpi.hopcount) {
expert_add_info_format(pinfo, hpi.pi, &ei_dhcpv6_error_hopcount, "Hopcount of most inner message has to equal 0 instead of %d", hpi.hopcount);
}
if (tree) {
proto_tree_add_item(bp_tree, hf_dhcpv6_msgtype, tvb, off, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(bp_tree, hf_dhcpv6_xid, tvb, off + 1, 3, ENC_BIG_ENDIAN);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "XID: 0x%x ", tvb_get_ntoh24(tvb, off + 1));
off += 4;
}
at_end = FALSE;
while ((off < eoff) && !at_end)
off += dhcpv6_option(tvb, pinfo, bp_tree, downstream, off, eoff, &at_end, proto_dhcpv6, hpi);
}
static void
dissect_dhcpv6_downstream(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
hopcount_info hpi;
initialize_hopount_info(&hpi);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPv6");
col_clear(pinfo->cinfo, COL_INFO);
dissect_dhcpv6(tvb, pinfo, tree, TRUE, 0, tvb_reported_length(tvb), hpi);
}
static void
dissect_dhcpv6_upstream(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
hopcount_info hpi;
initialize_hopount_info(&hpi);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPv6");
col_clear(pinfo->cinfo, COL_INFO);
dissect_dhcpv6(tvb, pinfo, tree, FALSE, 0, tvb_reported_length(tvb), hpi);
}
static guint
get_dhcpv6_bulk_leasequery_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return (tvb_get_ntohs(tvb, offset)+2);
}
static int
dissect_dhcpv6_bulk_leasequery_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *bulk_tree, *option_tree;
gint offset = 0, end;
guint16 size, trans_id;
guint8 msg_type;
gboolean at_end = FALSE;
hopcount_info hpi;
initialize_hopount_info(&hpi);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DHCPv6 BulkLease");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_dhcpv6_bulk_leasequery, tvb, 0, -1, ENC_NA );
bulk_tree = proto_item_add_subtree(ti, ett_dhcpv6_bulk_leasequery);
size = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(bulk_tree, hf_dhcpv6_bulk_leasequery_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
msg_type = tvb_get_guint8( tvb, offset );
ti = proto_tree_add_item(bulk_tree, hf_dhcpv6_bulk_leasequery_msgtype, tvb, offset, 1, ENC_BIG_ENDIAN);
if ((msg_type != LEASEQUERY) &&
(msg_type != LEASEQUERY_REPLY) &&
(msg_type != LEASEQUERY_DONE) &&
(msg_type != LEASEQUERY_DATA))
expert_add_info_format(pinfo, ti, &ei_dhcpv6_bulk_leasequery_bad_msg_type,
"Message Type %d not allowed by DHCPv6 Bulk Leasequery", msg_type);
offset += 1;
proto_tree_add_item(bulk_tree, hf_dhcpv6_bulk_leasequery_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
trans_id = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(bulk_tree, hf_dhcpv6_bulk_leasequery_trans_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s, Transaction ID: %5u",
val_to_str_ext_const(msg_type, &msgtype_vals_ext, "Unknown"), trans_id);
option_tree = proto_tree_add_subtree(bulk_tree, tvb, offset, -1, ett_dhcpv6_bulk_leasequery_options, NULL, "DHCPv6 Options");
end = size + 2;
while ((offset < end) && !at_end)
offset += dhcpv6_option(tvb, pinfo, option_tree, FALSE, offset,
end, &at_end, proto_dhcpv6_bulk_leasequery, hpi);
return tvb_length(tvb);
}
static int
dissect_dhcpv6_bulk_leasequery(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, dhcpv6_bulk_leasequery_desegment, 2,
get_dhcpv6_bulk_leasequery_pdu_len, dissect_dhcpv6_bulk_leasequery_pdu, data);
return tvb_length(tvb);
}
void
proto_register_dhcpv6(void)
{
module_t *bulkquery_module;
static hf_register_info hf[] = {
{ &hf_dhcpv6_msgtype,
{ "Message type", "dhcpv6.msgtype", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &msgtype_vals_ext, 0x0, NULL, HFILL }},
{ &hf_dhcpv6_hopcount,
{ "Hopcount", "dhcpv6.hopcount", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_xid,
{ "Transaction ID", "dhcpv6.xid", FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_linkaddr,
{ "Link address", "dhcpv6.linkaddr", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_dhcpv6_peeraddr,
{ "Peer address", "dhcpv6.peeraddr", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL}},
{ &hf_option_type,
{ "Option", "dhcpv6.option.type", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &opttype_vals_ext, 0x0, NULL, HFILL}},
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
{ &hf_duid_bytes,
{ "DUID", "dhcpv6.duid.bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_duid_type,
{ "DUID Type", "dhcpv6.duid.type", FT_UINT16, BASE_DEC, VALS(duidtype_vals), 0x0, NULL, HFILL}},
{ &hf_duidllt_time,
{ "DUID Time", "dhcpv6.duidllt.time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL}},
{ &hf_duidllt_link_layer_addr,
{ "Link-layer address", "dhcpv6.duidllt.link_layer_addr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_duidllt_hwtype,
{ "Hardware type", "dhcpv6.duidllt.hwtype", FT_UINT16, BASE_DEC, VALS(arp_hrd_vals), 0, "DUID LLT Hardware Type", HFILL }},
{ &hf_duidll_hwtype,
{ "Hardware type", "dhcpv6.duidll.hwtype", FT_UINT16, BASE_DEC, VALS(arp_hrd_vals), 0, "DUID LL Hardware Type", HFILL }},
{ &hf_duiden_enterprise,
{ "Enterprise ID", "dhcpv6.duiden.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "DUID EN Enterprise Number", HFILL }},
{ &hf_duiden_identifier,
{ "Identifier", "dhcpv6.duiden.identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_duidll_link_layer_addr,
{ "Link-layer address", "dhcpv6.duidll.link_layer_addr", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_iaid,
{ "IAID", "dhcpv6.iaid", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_iaid_t1,
{ "T1", "dhcpv6.iaid.t1", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_iaid_t2,
{ "T2", "dhcpv6.iaid.t2", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_iata,
{ "IATA", "dhcpv6.iata", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_iaaddr_ip,
{ "IPv6 address", "dhcpv6.iaaddr.ip", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_iaaddr_pref_lifetime,
{ "Preferred lifetime", "dhcpv6.iaaddr.pref_lifetime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_iaaddr_valid_lifetime,
{ "Valid lifetime", "dhcpv6.iaaddr.valid_lifetime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_requested_option_code,
{ "Requested Option code", "dhcpv6.requested_option_code", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &opttype_vals_ext, 0, NULL, HFILL }},
{ &hf_option_preference,
{ "Pref-value", "dhcpv6.option_preference", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_elapsed_time,
{ "Elapsed time", "dhcpv6.elapsed_time", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_auth_protocol,
{ "Protocol", "dhcpv6.auth.protocol", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_auth_algorithm,
{ "Algorithm", "dhcpv6.auth.algorithm", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_auth_rdm,
{ "RDM", "dhcpv6.auth.rdm", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_auth_replay_detection,
{ "Replay Detection", "dhcpv6.auth.replay_detection", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_auth_info,
{ "Authentication Information", "dhcpv6.auth.info", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_opt_unicast,
{ "IPv6 address", "dhcpv6.unicast", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_opt_status_code,
{ "Status Code", "dhcpv6.status_code", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &statuscode_vals_ext, 0, NULL, HFILL }},
{ &hf_opt_status_msg,
{ "Status Message", "dhcpv6.status_msg", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_vendorclass_enterprise,
{ "Enterprise ID", "dhcpv6.vendorclass.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "Vendor Class Enterprise Number", HFILL }},
{ &hf_vendorclass_data,
{ "vendor-class-data", "dhcpv6.vendorclass.data", FT_STRINGZ, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_vendoropts_enterprise,
{ "Enterprise ID", "dhcpv6.vendoropts.enterprise", FT_UINT32, BASE_DEC|BASE_EXT_STRING, &sminmpec_values_ext, 0, "Vendor opts Enterprise Number", HFILL }},
{ &hf_vendoropts_enterprise_option_code,
{ "Option code", "dhcpv6.vendoropts.enterprise.option_code", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_vendoropts_enterprise_option_length,
{ "Option length", "dhcpv6.vendoropts.enterprise.option_length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_vendoropts_enterprise_option_data,
{ "Option data", "dhcpv6.vendoropts.enterprise.option_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_interface_id,
{ "Interface-ID", "dhcpv6.interface_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_reconf_msg,
{ "Reconfigure message type", "dhcpv6.reconf_msg", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &msgtype_vals_ext, 0, NULL, HFILL }},
{ &hf_sip_server_domain_search_fqdn,
{ "SIP Server Domain Search FQDN", "dhcpv6.sip_server_domain_search_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sip_server_a,
{ "SIP server address", "dhcpv6.sip_server_a", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_dns_servers,
{ "DNS server address", "dhcpv6.dns_server", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_domain_search_list_fqdn,
{ "Domain Search List FQDN", "dhcpv6.domain_search_list_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nis_servers,
{ "NIS server address", "dhcpv6.nis_server", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_nisp_servers,
{ "NISP server address", "dhcpv6.nisp_server", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_nis_fqdn,
{ "NIS FQDN", "dhcpv6.nis_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nisp_fqdn,
{ "NISP FQDN", "dhcpv6.nisp_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_sntp_servers,
{ "SNTP server address", "dhcpv6.sntp_server", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_opt_lifetime,
{ "Lifetime", "dhcpv6.lifetime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_bcmcs_servers_fqdn,
{ "BCMCS server FQDN", "dhcpv6.bcmcs_server_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_bcmcs_servers_a,
{ "BCMCS server address", "dhcpv6.bcmcs_server_a", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_remoteid_enterprise_id,
{ "Remote-ID", "dhcpv6.remoteid_enterprise_id", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_subscriber_id,
{ "Subscriber-ID", "dhcpv6.subscriber_id", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_client_fqdn,
{ "Client FQDN", "dhcpv6.client_fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pana_agent,
{ "PANA agents address", "dhcpv6.pana_agent", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_opt_timezone,
{ "Time-zone", "dhcpv6.timezone", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_opt_tzdb,
{ "TZ-database", "dhcpv6.tzdb", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_lq_query,
{ "Query-type", "dhcpv6.lq_query", FT_UINT8, BASE_DEC, VALS(lq_query_vals), 0, NULL, HFILL }},
{ &hf_lq_query_link_address,
{ "Link address", "dhcpv6.lq_query_link_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_clt_time,
{ "Clt_time", "dhcpv6.clt_time", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_lq_relay_data_peer_addr,
{ "Peer address", "dhcpv6.lq_relay_data_peer_addr", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_lq_relay_data_msg,
{ "DHCPv6 relay message", "dhcpv6.lq_relay_data_msg", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_lq_client_link,
{ "LQ client links address", "dhcpv6.lq_client_link", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_capwap_ac_v6,
{ "CAPWAP Access Controllers address", "dhcpv6.capwap_ac_v6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_aftr_name,
{ "DS-Lite AFTR Name", "dhcpv6.aftr_name", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_iaprefix_pref_lifetime,
{ "Preferred lifetime", "dhcpv6.iaprefix.pref_lifetime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_iaprefix_valid_lifetime,
{ "Valid lifetime", "dhcpv6.iaprefix.valid_lifetime", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL}},
{ &hf_iaprefix_pref_len,
{ "Prefix length", "dhcpv6.iaprefix.pref_len", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_iaprefix_pref_addr,
{ "Prefix address", "dhcpv6.iaprefix.pref_addr", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_mip6_ha,
{ "Home Agent", "dhcpv6.mip6_home_agent", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_mip6_hoa,
{ "Home Address", "dhcpv6.mip6_home_address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_nai,
{ "NAI", "dhcpv6.nai", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_pd_exclude_pref_len,
{ "Prefix length", "dhcpv6.pd_exclude.pref_len", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_pd_exclude_subnet_id,
{ "IPv6 subnet ID", "dhcpv6.pd_exclude.subnet_id", FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_option_ntpserver_type,
{ "Suboption", "dhcpv6.ntpserver.option.type", FT_UINT16, BASE_DEC, VALS(ntp_server_opttype_vals), 0x0, NULL, HFILL}},
{ &hf_option_ntpserver_length,
{ "Length", "dhcpv6.ntpserver.option.length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_option_ntpserver_addr,
{ "NTP Server Address", "dhcpv6.ntpserver.addr", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_option_ntpserver_mc_addr,
{ "NTP Multicast Address", "dhcpv6.ntpserver.mc_addr", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_option_ntpserver_fqdn,
{ "NTP Server FQDN", "dhcpv6.ntpserver.fqdn", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_packetcable_ccc_suboption,
{ "Sub element", "dhcpv6.packetcable.ccc.suboption", FT_UINT16, BASE_DEC, VALS(pkt_ccc_opt_vals), 0, NULL, HFILL }},
{ &hf_packetcable_ccc_pri_dhcp,
{ "Primary DHCP", "dhcpv6.packetcable.ccc.pri_dhcp", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_ccc_sec_dhcp,
{ "Secondary DHCP", "dhcpv6.packetcable.ccc.sec_dhcp", FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_suboption,
{ "Sub element", "dhcpv6.packetcable.cccV6.suboption", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &pkt_cccV6_opt_vals_ext, 0, NULL, HFILL }},
{ &hf_modem_capabilities_encoding_type,
{ "Type", "dhcpv6.docsis.cccV6.tlv5.suboption", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &modem_capabilities_encoding_ext, 0, NULL, HFILL }},
{ &hf_eue_capabilities_encoding_type,
{ "Type", "dhcpv6.packetcable.cccV6.tlv5.suboption", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &eue_capabilities_encoding_ext, 0, NULL, HFILL }},
{ &hf_capabilities_encoding_length,
{ "Length", "dhcpv6.cccV6.tlv5.suboption.length", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_capabilities_encoding_bytes,
{ "Value", "dhcpv6.cccV6.tlv5.suboption.value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_capabilities_encoding_number,
{ "Value", "dhcpv6.cccV6.tlv5.suboption.value", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_pri_dss,
{ "Primary SSID", "dhcpv6.packetcable.cccV6.pri_dss", FT_STRINGZ, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_sec_dss,
{ "Secondary SSID", "dhcpv6.packetcable.cccV6.sec_dss", FT_STRINGZ, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_prov_srv_type,
{ "Type", "dhcpv6.packetcable.cccV6.prov_srv.type", FT_UINT8, BASE_DEC, VALS(pkt_cccV6_prov_srv_type_vals), 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_prov_srv_fqdn,
{ "FQDN", "dhcpv6.packetcable.cccV6.prov_srv.fqdn", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_prov_srv_ipv6,
{ "IPv6 address", "dhcpv6.packetcable.cccV6.prov_srv.ipv6", FT_IPv6, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_as_krb_nominal_timeout,
{ "Nominal Timeout", "dhcpv6.packetcable.cccV6.as_krb.nominal_timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_as_krb_max_timeout,
{ "Maximum Timeout", "dhcpv6.packetcable.cccV6.as_krb.max_timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_as_krb_max_retry_count,
{ "Maximum Retry Count", "dhcpv6.packetcable.cccV6.as_krb.max_retry_count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_ap_krb_nominal_timeout,
{ "Nominal Timeout", "dhcpv6.packetcable.cccV6.ap_krb.nominal_timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_ap_krb_max_timeout,
{ "Maximum Timeout", "dhcpv6.packetcable.cccV6.ap_krb.max_timeout", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_ap_krb_max_retry_count,
{ "Maximum Retry Count", "dhcpv6.packetcable.cccV6.ap_krb.max_retry_count", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_krb_realm,
{ "KRB Realm", "dhcpv6.packetcable.cccV6.krb_realm", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_tgt_flag,
{ "TGT Flags", "dhcpv6.packetcable.cccV6.tgt_flag", FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_tgt_flag_fetch,
{ "Fetch TGT", "dhcpv6.packetcable.cccV6.tgt_flag.fetch", FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01, NULL, HFILL }},
{ &hf_packetcable_cccV6_prov_timer,
{ "Provisioning timer", "dhcpv6.packetcable.cccV6.prov_timer", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_sec_tcm,
{ "SEC TCM Flags", "dhcpv6.packetcable.cccV6.sec_tcm", FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }},
{ &hf_packetcable_cccV6_sec_tcm_provisioning_server,
{ "Provisioning Server", "dhcpv6.packetcable.cccV6.sec_tcm.provisioning_server", FT_BOOLEAN, 16, TFS(&tfs_on_off), 0x01, NULL, HFILL }},
{ &hf_packetcable_cccV6_sec_tcm_call_manager_server,
{ "Call Manager Servers", "dhcpv6.packetcable.cccV6.tgt_flag.call_manager_server", FT_BOOLEAN, 16, TFS(&tfs_on_off), 0x02, NULL, HFILL }},
{ &hf_cablelabs_opts,
{ "Suboption", "dhcpv6.cablelabs.opt", FT_UINT16, BASE_DEC | BASE_EXT_STRING, &cl_vendor_subopt_values_ext, 0, NULL, HFILL }},
{ &hf_cablelabs_ipv6_server,
{ "IPv6 address", "dhcpv6.cablelabs.ipv6_server", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}},
};
static gint *ett[] = {
&ett_dhcpv6,
&ett_dhcpv6_option,
&ett_dhcpv6_option_vsoption,
&ett_dhcpv6_vendor_option,
&ett_dhcpv6_pkt_option,
&ett_dhcpv6_netserver_option,
&ett_dhcpv6_tlv5_type
};
static ei_register_info ei[] = {
{ &ei_dhcpv6_bogus_length, { "dhcpv6.bogus_length", PI_MALFORMED, PI_ERROR, "Bogus length", EXPFILL }},
{ &ei_dhcpv6_malformed_option, { "dhcpv6.malformed_option", PI_MALFORMED, PI_ERROR, "Malformed option", EXPFILL }},
{ &ei_dhcpv6_no_suboption_len, { "dhcpv6.no_suboption_len", PI_PROTOCOL, PI_WARN, "no room left in option for suboption length", EXPFILL }},
{ &ei_dhcpv6_invalid_time_value, { "dhcpv6.invalid_time_value", PI_PROTOCOL, PI_WARN, "Invalid time value", EXPFILL }},
{ &ei_dhcpv6_invalid_type, { "dhcpv6.invalid_type", PI_PROTOCOL, PI_WARN, "Invalid type", EXPFILL }},
{ &ei_dhcpv6_malformed_dns, { "dhcpv6.malformed_dns", PI_PROTOCOL, PI_WARN, "Malformed DNS name record (MS Vista client?)", EXPFILL }},
{ &ei_dhcpv6_error_hopcount, { "dhcpv6.error_hopcount", PI_PROTOCOL, PI_WARN, "Detected error on hop-count", EXPFILL }},
};
static hf_register_info bulk_leasequery_hf[] = {
{ &hf_dhcpv6_bulk_leasequery_size,
{ "Message size", "dhcpv6.bulk_leasequery.size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dhcpv6_bulk_leasequery_msgtype,
{ "Message type", "dhcpv6.bulk_leasequery.msgtype", FT_UINT8, BASE_DEC | BASE_EXT_STRING, &msgtype_vals_ext, 0x0, NULL, HFILL }},
{ &hf_dhcpv6_bulk_leasequery_reserved,
{ "Reserved", "dhcpv6.bulk_leasequery.reserved", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_dhcpv6_bulk_leasequery_trans_id,
{ "Transaction ID", "dhcpv6.bulk_leasequery.trans_id", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett_bulk_leasequery[] = {
&ett_dhcpv6_bulk_leasequery,
&ett_dhcpv6_bulk_leasequery_options
};
static ei_register_info ei_bulk_leasequery[] = {
{ &ei_dhcpv6_bulk_leasequery_bad_query_type, { "dhcpv6.bulk_leasequery.bad_query_type", PI_MALFORMED, PI_WARN, "LQ-QUERY: Query types only supported by Bulk Leasequery", EXPFILL }},
{ &ei_dhcpv6_bulk_leasequery_no_lq_relay_data, { "dhcpv6.bulk_leasequery.no_lq_relay_data", PI_MALFORMED, PI_WARN, "LQ_RELAY_DATA: Not allowed in Bulk Leasequery", EXPFILL }},
{ &ei_dhcpv6_bulk_leasequery_bad_msg_type, { "dhcpv6.bulk_leasequery.bad_msg_type", PI_MALFORMED, PI_WARN, "Message Type %d not allowed by DHCPv6 Bulk Leasequery", EXPFILL }},
};
expert_module_t *expert_dhcpv6;
expert_module_t *expert_dhcpv6_bulk_leasequery;
proto_dhcpv6 = proto_register_protocol("DHCPv6", "DHCPv6", "dhcpv6");
proto_register_field_array(proto_dhcpv6, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dhcpv6 = expert_register_protocol(proto_dhcpv6);
expert_register_field_array(expert_dhcpv6, ei, array_length(ei));
proto_dhcpv6_bulk_leasequery = proto_register_protocol("DHCPv6 Bulk Leasequery", "DHCPv6 Bulk Leasequery", "dhcpv6.bulk_leasequery");
proto_register_field_array(proto_dhcpv6_bulk_leasequery, bulk_leasequery_hf, array_length(bulk_leasequery_hf));
proto_register_subtree_array(ett_bulk_leasequery, array_length(ett_bulk_leasequery));
expert_dhcpv6_bulk_leasequery = expert_register_protocol(proto_dhcpv6_bulk_leasequery);
expert_register_field_array(expert_dhcpv6_bulk_leasequery, ei_bulk_leasequery, array_length(ei_bulk_leasequery));
register_dissector("dhcpv6", dissect_dhcpv6_upstream, proto_dhcpv6);
bulkquery_module = prefs_register_protocol(proto_dhcpv6_bulk_leasequery, NULL);
prefs_register_bool_preference(bulkquery_module, "desegment",
"Desegment all Bulk Leasequery messages spanning multiple TCP segments",
"Whether the Bulk Leasequery dissector should desegment all messages spanning multiple TCP segments",
&dhcpv6_bulk_leasequery_desegment);
}
void
proto_reg_handoff_dhcpv6(void)
{
dissector_handle_t dhcpv6_handle, dhcpv6_bulkquery_handle;
dhcpv6_handle = create_dissector_handle(dissect_dhcpv6_downstream,
proto_dhcpv6);
dissector_add_uint("udp.port", UDP_PORT_DHCPV6_DOWNSTREAM, dhcpv6_handle);
dhcpv6_handle = create_dissector_handle(dissect_dhcpv6_upstream,
proto_dhcpv6);
dissector_add_uint("udp.port", UDP_PORT_DHCPV6_UPSTREAM, dhcpv6_handle);
dhcpv6_bulkquery_handle = new_create_dissector_handle(dissect_dhcpv6_bulk_leasequery,
proto_dhcpv6_bulk_leasequery);
dissector_add_uint("tcp.port", UDP_PORT_DHCPV6_UPSTREAM, dhcpv6_bulkquery_handle);
}
