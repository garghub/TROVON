static void
mdi_power_base(gchar *buf, guint32 value) {
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u.%u. Watt", value/10, value%10);
}
static void
media_power_base(gchar *buf, guint32 value) {
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u mW", value * 100);
}
static void
get_latitude_or_longitude(gchar *buf, int option, guint64 unmasked_value)
{
guint64 value = unmasked_value & G_GINT64_CONSTANT(0x03FFFFFFFF);
guint64 tempValue = value;
gboolean negativeNum = FALSE;
guint32 integerPortion = 0;
const char *direction;
if (value & G_GINT64_CONSTANT(0x0000000200000000))
{
negativeNum = TRUE;
tempValue = ~value;
tempValue += 1;
}
integerPortion = (guint32)((tempValue & G_GINT64_CONSTANT(0x00000003FE000000)) >> 25);
tempValue = (tempValue & G_GINT64_CONSTANT(0x0000000001FFFFFF))/33554432;
if (option == 0)
{
if (negativeNum)
direction = "South";
else
direction = "North";
}
else
{
if (negativeNum)
direction = "West";
else
direction = "East";
}
g_snprintf(buf, ITEM_LABEL_LENGTH, "%u.%04" G_GINT64_MODIFIER "u degrees %s (0x%010" G_GINT64_MODIFIER "X)",
integerPortion, tempValue, direction, value);
}
static void
latitude_base(gchar *buf, guint64 value) {
get_latitude_or_longitude(buf, 0, value);
}
static void
longitude_base(gchar *buf, guint64 value) {
get_latitude_or_longitude(buf, 1, value);
}
static gint32
dissect_lldp_chassis_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
guint8 tlvsubType;
guint16 tempShort;
guint32 dataLen = 0;
const char *strPtr=NULL;
guint8 addr_family = 0;
proto_tree *chassis_tree = NULL;
proto_item *tf = NULL, *lf = NULL;
tempShort = tvb_get_ntohs(tvb, offset);
tlvsubType = TLV_TYPE(tempShort);
if (tlvsubType != CHASSIS_ID_TLV_TYPE)
{
proto_tree_add_expert_format(tree, pinfo, &ei_lldp_bad_type , tvb, offset, TLV_INFO_LEN(tempShort),
"Invalid Chassis ID (0x%02X), expected (0x%02X)", tlvsubType, CHASSIS_ID_TLV_TYPE);
return -1;
}
dataLen = TLV_INFO_LEN(tempShort);
tlvsubType = tvb_get_guint8(tvb, (offset+2));
chassis_tree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2), ett_chassis_id, &tf, "Chassis Subtype = %s",
val_to_str_const(tlvsubType, chassis_id_subtypes, "Reserved" ));
proto_tree_add_item(chassis_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
lf = proto_tree_add_item(chassis_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (dataLen < 2)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Chassis ID Length (%u), expected > (2)", dataLen);
return -1;
}
proto_tree_add_item(chassis_tree, hf_chassis_id_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (tlvsubType)
{
case 4:
{
if (dataLen != 7)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Chassis ID Length (%u) for Type (%s), expected (7)", dataLen, val_to_str_const(tlvsubType, chassis_id_subtypes, ""));
return -1;
}
strPtr = tvb_ether_to_str(tvb, offset);
proto_tree_add_item(chassis_tree, hf_chassis_id_mac, tvb, offset, 6, ENC_NA);
offset += (dataLen - 1);
break;
}
case 5:
{
proto_tree_add_item(chassis_tree, hf_lldp_network_address_family, tvb, offset, 1, ENC_BIG_ENDIAN);
addr_family = tvb_get_guint8(tvb,offset);
offset++;
switch(addr_family){
case AFNUM_INET:
if (dataLen == 6){
strPtr = tvb_ip_to_str(tvb, offset);
}else{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Chassis ID Length (%u) for Type (%s, %s), expected (6)", dataLen, val_to_str_const(tlvsubType, chassis_id_subtypes, ""), val_to_str_const(addr_family, afn_vals, ""));
return -1;
}
proto_tree_add_item(chassis_tree, hf_chassis_id_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case AFNUM_INET6:
if (dataLen == 18){
strPtr = tvb_ip6_to_str(tvb, offset);
}else{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Chassis ID Length (%u) for Type (%s, %s), expected (18)", dataLen, val_to_str_const(tlvsubType, chassis_id_subtypes, ""), val_to_str_const(addr_family, afn_vals, ""));
return -1;
}
proto_tree_add_item(chassis_tree, hf_chassis_id_ip6, tvb, offset, 16, ENC_NA);
break;
default:
strPtr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, (dataLen-2));
proto_tree_add_item(chassis_tree, hf_chassis_id, tvb, offset, (dataLen-2), ENC_NA);
break;
}
offset += (dataLen - 2);
break;
}
case 1:
case 2:
case 3:
case 6:
case 7:
default:
{
if (dataLen > 256)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length_excess,
"Invalid Chassis ID Length (%u) for Type (%s), expected < (256)", dataLen, val_to_str_const(tlvsubType, chassis_id_subtypes, ""));
return -1;
}
switch(tlvsubType)
{
case 2:
case 6:
case 7:
strPtr = tvb_format_stringzpad(tvb, offset, (dataLen-1));
break;
case 1:
case 3:
strPtr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, (dataLen-1));
break;
default:
strPtr = "Reserved";
break;
}
proto_tree_add_item(chassis_tree, hf_chassis_id, tvb, offset, (dataLen-1), ENC_NA);
offset += (dataLen - 1);
break;
}
}
proto_item_append_text(tf, ", Id: %s", strPtr);
return offset;
}
static gint32
dissect_lldp_port_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
guint8 tlvsubType;
guint16 tempShort;
guint32 dataLen = 0;
const char *strPtr=NULL;
guint8 addr_family = 0;
proto_tree *port_tree = NULL;
proto_item *tf = NULL, *lf = NULL;
tempShort = tvb_get_ntohs(tvb, offset);
tlvsubType = TLV_TYPE(tempShort);
if (tlvsubType != PORT_ID_TLV_TYPE)
{
proto_tree_add_expert_format(tree, pinfo, &ei_lldp_bad_type , tvb, offset, TLV_INFO_LEN(tempShort),
"Invalid Port ID (0x%02X), expected (0x%02X)", tlvsubType, PORT_ID_TLV_TYPE);
return -1;
}
dataLen = TLV_INFO_LEN(tempShort);
tlvsubType = tvb_get_guint8(tvb, (offset+2));
port_tree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2), ett_port_id, &tf, "Port Subtype = %s",
val_to_str_const(tlvsubType, port_id_subtypes, "Unknown" ));
proto_tree_add_item(port_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
lf = proto_tree_add_item(port_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (dataLen < 2) {
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Port ID Length (%u), expected > (2)", dataLen);
return -1;
}
proto_tree_add_item(port_tree, hf_port_id_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (tlvsubType)
{
case 3:
if (dataLen != 7)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Port ID Length (%u) for Type (%s), expected (7)", dataLen, val_to_str_const(tlvsubType, port_id_subtypes, ""));
return -1;
}
strPtr = tvb_ether_to_str(tvb, offset);
proto_tree_add_item(port_tree, hf_port_id_mac, tvb, offset, 6, ENC_NA);
offset += (dataLen - 1);
break;
case 4:
addr_family = tvb_get_guint8(tvb,offset);
proto_tree_add_item(port_tree, hf_lldp_network_address_family, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(addr_family){
case AFNUM_INET:
if (dataLen == 6){
strPtr = tvb_ip_to_str(tvb, offset);
}else{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Port ID Length (%u) for Type (%s, %s), expected (6)", dataLen, val_to_str_const(tlvsubType, port_id_subtypes, ""), val_to_str_const(addr_family, afn_vals, ""));
return -1;
}
proto_tree_add_item(port_tree, hf_port_id_ip4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case AFNUM_INET6:
if (dataLen == 18){
strPtr = tvb_ip6_to_str(tvb, offset);
}else{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"Invalid Port ID Length (%u) for Type (%s, %s), expected (18)", dataLen, val_to_str_const(tlvsubType, port_id_subtypes, ""), val_to_str_const(addr_family, afn_vals, ""));
return -1;
}
proto_tree_add_item(port_tree, hf_port_id_ip6, tvb, offset, 16, ENC_NA);
break;
default:
strPtr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, (dataLen-2));
proto_tree_add_item(port_tree, hf_port_id, tvb, offset, (dataLen-2), ENC_ASCII|ENC_NA);
break;
}
offset += (dataLen - 2);
break;
case 1:
case 2:
case 5:
case 6:
case 7:
default:
if (dataLen > 256)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length_excess,
"Invalid Port ID Length (%u) for Type (%s), expected < (256)", dataLen, val_to_str_const(tlvsubType, port_id_subtypes, ""));
return -1;
}
switch (tlvsubType)
{
case 2:
strPtr = tvb_bytes_to_str(wmem_packet_scope(), tvb, offset, (dataLen-1));
break;
case 1:
case 5:
case 6:
case 7:
strPtr = tvb_format_stringzpad(tvb, offset, (dataLen-1));
break;
default:
strPtr = "Reserved";
break;
}
proto_tree_add_item(port_tree, hf_port_id, tvb, offset, (dataLen-1), ENC_ASCII|ENC_NA);
offset += (dataLen - 1);
break;
}
proto_item_append_text(tf, ", Id: %s", strPtr);
return offset;
}
static gint32
dissect_lldp_time_to_live(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
guint8 tlvsubType;
guint16 tempShort;
guint32 dataLen = 0;
proto_tree *time_to_live_tree;
tempShort = tvb_get_ntohs(tvb, offset);
tlvsubType = TLV_TYPE(tempShort);
if (tlvsubType != TIME_TO_LIVE_TLV_TYPE)
return -1;
dataLen = TLV_INFO_LEN(tempShort);
tempShort = tvb_get_ntohs(tvb, (offset+2));
col_append_fstr(pinfo->cinfo, COL_INFO, "TTL = %u ", tempShort);
time_to_live_tree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2),
ett_time_to_live, NULL, "Time To Live = %u sec", tempShort);
proto_tree_add_item(time_to_live_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(time_to_live_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(time_to_live_tree, hf_time_to_live, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint32
dissect_lldp_end_of_lldpdu(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 dataLen;
guint16 tempShort;
proto_tree *end_of_lldpdu_tree;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
end_of_lldpdu_tree = proto_tree_add_subtree(tree, tvb, offset, (dataLen + 2), ett_end_of_lldpdu, NULL, "End of LLDPDU");
proto_tree_add_item(end_of_lldpdu_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(end_of_lldpdu_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
return -1;
}
static gint32
dissect_lldp_port_desc(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempShort;
guint32 dataLen = 0;
const char *strPtr;
proto_tree *port_desc_tree;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
strPtr = tvb_format_stringzpad(tvb, (offset+2), dataLen);
port_desc_tree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2),
ett_port_description, NULL, "Port Description = %s", strPtr);
proto_tree_add_item(port_desc_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(port_desc_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(port_desc_tree, hf_port_desc, tvb, offset, dataLen, ENC_ASCII|ENC_NA);
offset += dataLen;
return offset;
}
static gint32
dissect_lldp_system_name(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempShort;
guint32 dataLen = 0;
guint8 tlvsubType;
const char *strPtr;
proto_tree *system_subtree;
tempShort = tvb_get_ntohs(tvb, offset);
tlvsubType = TLV_TYPE(tempShort);
dataLen = TLV_INFO_LEN(tempShort);
strPtr = tvb_format_stringzpad(tvb, (offset+2), dataLen);
if (tlvsubType == SYSTEM_NAME_TLV_TYPE) {
system_subtree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2),
ett_system_name, NULL, "System Name = %s", strPtr);
col_append_fstr(pinfo->cinfo, COL_INFO, "System Name = %s ", strPtr);
} else {
system_subtree = proto_tree_add_subtree_format(tree, tvb, offset, (dataLen + 2),
ett_system_desc, NULL, "System Description = %s", strPtr);
col_append_fstr(pinfo->cinfo, COL_INFO, "System Description = %s ", strPtr);
}
proto_tree_add_item(system_subtree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(system_subtree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
if (tlvsubType == SYSTEM_NAME_TLV_TYPE)
proto_tree_add_item(system_subtree, hf_lldp_tlv_system_name, tvb, offset, dataLen, ENC_ASCII|ENC_NA);
else
proto_tree_add_item(system_subtree, hf_lldp_tlv_system_desc, tvb, offset, dataLen, ENC_ASCII|ENC_NA);
offset += dataLen;
return offset;
}
static gint32
dissect_lldp_system_capabilities(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempShort;
guint32 dataLen = 0;
proto_tree *system_capabilities_tree;
proto_tree *capabilities_summary_tree;
proto_tree *capabilities_enabled_tree;
proto_item *tf;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
system_capabilities_tree = proto_tree_add_subtree(tree, tvb, offset, (dataLen + 2), ett_system_cap, NULL, "Capabilities");
proto_tree_add_item(system_capabilities_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(system_capabilities_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tf = proto_tree_add_item(system_capabilities_tree, hf_lldp_tlv_system_cap, tvb, offset, 2, ENC_BIG_ENDIAN);
capabilities_summary_tree = proto_item_add_subtree(tf, ett_system_cap_summary);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_other, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_repeater, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_bridge, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_wlan_access_pt, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_router, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_telephone, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_docsis_cable_device, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_summary_tree, hf_lldp_tlv_system_cap_station_only, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tf = proto_tree_add_item(system_capabilities_tree, hf_lldp_tlv_enable_system_cap, tvb, offset, 2, ENC_BIG_ENDIAN);
capabilities_enabled_tree = proto_item_add_subtree(tf, ett_system_cap_enabled);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_other, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_repeater, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_bridge, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_wlan_access_pt, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_router, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_telephone, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_docsis_cable_device, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(capabilities_enabled_tree, hf_lldp_tlv_enable_system_cap_station_only, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint32
dissect_lldp_management_address(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 tempShort;
guint32 dataLen = 0;
guint8 subtypeByte;
guint8 stringLen = 0;
proto_tree *system_mgm_addr;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
system_mgm_addr = proto_tree_add_subtree(tree, tvb, offset, (dataLen + 2), ett_management_address, NULL, "Management Address");
proto_tree_add_item(system_mgm_addr, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(system_mgm_addr, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
stringLen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(system_mgm_addr, hf_mgn_address_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
subtypeByte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(system_mgm_addr, hf_mgn_address_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (subtypeByte)
{
case 1:
proto_tree_add_item(system_mgm_addr, hf_mgn_addr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(system_mgm_addr, hf_mgn_addr_ipv6, tvb, offset, 16, ENC_NA);
break;
default:
proto_tree_add_item(system_mgm_addr, hf_mgn_addr_hex, tvb, offset, (stringLen-1), ENC_NA);
break;
}
offset += (stringLen-1);
proto_tree_add_item(system_mgm_addr, hf_mgn_interface_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(system_mgm_addr, hf_mgn_interface_number, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
stringLen = tvb_get_guint8(tvb, offset);
proto_tree_add_item(system_mgm_addr, hf_mgn_oid_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (stringLen > 0)
{
proto_tree_add_item(system_mgm_addr, hf_mgn_obj_id, tvb, offset, stringLen, ENC_NA);
offset += stringLen;
}
return offset;
}
static void
dissect_dcbx_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
guint8 priomaskByte, prioCounter, appCount = 0;
guint16 dataLen;
guint16 tempShort;
proto_tree *subtlv_tree = NULL;
proto_tree *apptlv_tree = NULL;
proto_tree_add_item(tree, hf_dcbx_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
while (tvb_reported_length_remaining(tvb, offset) && tree) {
tempShort = tvb_get_ntohs(tvb, offset);
subType = TLV_TYPE(tempShort);
dataLen = TLV_INFO_LEN(tempShort);
switch (subType)
{
case 0x1:
subtlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, dataLen + 2,
ett_org_spc_dcbx_cee_1, NULL, "%s TLV", val_to_str_const(subType, dcbx_subtypes, "Unknown"));
break;
case 0x2:
subtlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, dataLen + 2,
ett_org_spc_dcbx_cee_2, NULL, "%s TLV", val_to_str_const(subType, dcbx_subtypes, "Unknown"));
break;
case 0x3:
subtlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, dataLen + 2,
ett_org_spc_dcbx_cee_3, NULL, "%s TLV", val_to_str_const(subType, dcbx_subtypes, "Unknown"));
break;
case 0x4:
subtlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, dataLen + 2,
ett_org_spc_dcbx_cee_4, NULL, "%s TLV", val_to_str_const(subType, dcbx_subtypes, "Unknown"));
break;
case 0x6:
subtlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, dataLen + 2,
ett_org_spc_dcbx_cin_6, NULL, "%s TLV", val_to_str_const(subType, dcbx_subtypes, "Unknown"));
break;
}
proto_tree_add_item(subtlv_tree, hf_dcbx_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(subtlv_tree, hf_dcbx_tlv_oper_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_tlv_max_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (subType == 0x1) {
proto_tree_add_item(subtlv_tree, hf_dcbx_control_sequence, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
proto_tree_add_item(subtlv_tree, hf_dcbx_control_ack, tvb, offset, 4, ENC_BIG_ENDIAN);
offset +=4;
} else {
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_flag_enabled, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_flag_willing, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_flag_error, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(subType)
{
case 0x2:
{
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_5, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pgid_prio_7, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_per_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pg_numtcs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0x3:
{
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_prio7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_pfc_numtcs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0x4:
{
appCount = (dataLen - 4)/6;
while(appCount--) {
tempShort = tvb_get_ntohs(tvb, offset);
apptlv_tree = proto_tree_add_subtree_format(subtlv_tree, tvb, offset, 6,
ett_org_spc_dcbx_cee_app, NULL, "%s Application",
val_to_str_const(tempShort, dcbx_app_types, "Unknown"));
proto_tree_add_item(apptlv_tree, hf_dcbx_feature_app_proto, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(apptlv_tree, hf_dcbx_feature_app_oui, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(apptlv_tree, hf_dcbx_feature_app_selector, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
priomaskByte = tvb_get_guint8(tvb, offset);
for (prioCounter = 0; prioCounter < 8; prioCounter++)
if(priomaskByte & (0x1 << prioCounter)) {
proto_tree_add_uint(apptlv_tree, hf_dcbx_feature_app_prio, tvb, offset, 1, prioCounter);
break;
}
offset++;
}
break;
}
case 0x6:
{
proto_tree_add_item(subtlv_tree, hf_dcbx_feature_flag_llink_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
}
}
}
return;
}
static int
dissect_ieee_802_1_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
guint8 tempByte;
guint16 dcbApp, appCount;
proto_tree *vlan_flags_tree = NULL;
proto_tree *apptlv_tree = NULL;
proto_item *tf = NULL;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee_802_1_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (subType)
{
case 0x01:
{
proto_tree_add_item(tree, hf_ieee_802_1_port_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
break;
}
case 0x02:
{
tf = proto_tree_add_item(tree, hf_ieee_802_1_port_and_vlan_id_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
vlan_flags_tree = proto_item_add_subtree(tf, ett_port_vlan_flags);
proto_tree_add_item(vlan_flags_tree, hf_ieee_802_1_port_and_vlan_id_flag_supported, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(vlan_flags_tree, hf_ieee_802_1_port_and_vlan_id_flag_enabled, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_802_1_port_proto_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
break;
}
case 0x03:
{
proto_tree_add_item(tree, hf_ieee_802_1_vlan_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tempByte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee_802_1_vlan_name_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tempByte > 0)
{
proto_tree_add_item(tree, hf_ieee_802_1_vlan_name, tvb, offset, tempByte, ENC_ASCII|ENC_NA);
offset += tempByte;
}
break;
}
case 0x04:
{
tempByte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee_802_1_proto_id_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tempByte > 0)
{
proto_tree_add_item(tree, hf_ieee_802_1_proto_id, tvb, offset, tempByte, ENC_ASCII|ENC_NA);
offset += tempByte;
}
break;
}
case 0x8:
{
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_cnpv_prio7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021qau_ready_prio7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0x9:
{
proto_tree_add_item(tree, hf_ieee_8021az_feature_flag_willing, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021az_feature_flag_cbs, tvb, offset, 1, ENC_BIG_ENDIAN);
tempByte = (tvb_get_guint8(tvb, offset) & 0x7);
proto_tree_add_uint_format_value(tree, hf_ieee_8021az_maxtcs, tvb, offset, 1, tempByte, "%u (0x%X)", tempByte ? tempByte : 8, tempByte);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_5, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_7, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0xA:
{
proto_tree_add_item(tree, hf_dcbx_feature_pgid_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_3, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_5, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_6, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pgid_prio_7, tvb, offset, 2, ENC_BIG_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pg_per_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class0, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_8021az_tsa_class7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0xB:
{
proto_tree_add_item(tree, hf_ieee_8021az_feature_flag_willing, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021az_feature_flag_mbc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_ieee_8021az_pfc_numtcs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dcbx_feature_pfc_prio7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 0xC:
{
proto_tree_add_item(tree, hf_ieee_8021az_app_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
appCount = tvb_reported_length_remaining(tvb, offset)/3;
while(appCount--) {
dcbApp = tvb_get_ntohs(tvb, offset + 1);
apptlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, 3,
ett_org_spc_ieee_dcbx_app, NULL, "%s Application",
val_to_str_const(dcbApp, dcbx_app_types, "Unknown"));
proto_tree_add_item(apptlv_tree, hf_ieee_8021az_app_prio, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(apptlv_tree, hf_ieee_8021az_app_selector, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(apptlv_tree, hf_dcbx_feature_app_proto, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
}
}
return offset;
}
static void
dissect_oui_default_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
proto_tree_add_item(tree, hf_unknown_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_unknown_subtype_content, tvb, (offset+1), -1, ENC_NA);
}
static void
dissect_ieee_802_1qbg_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
proto_tree *evb_capabilities_subtree = NULL;
proto_item *tf = NULL;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee_802_1qbg_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (subType) {
case 0x00:
tf = proto_tree_add_item(tree, hf_ieee_802_1qbg_evb_support_caps, tvb, offset, 2, ENC_BIG_ENDIAN);
evb_capabilities_subtree = proto_item_add_subtree(tf, ett_802_1qbg_capabilities_flags);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_support_caps_std, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_support_caps_rr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_support_caps_rte, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_support_caps_ecp, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_support_caps_vdp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tf = proto_tree_add_item(tree, hf_ieee_802_1qbg_evb_configure_caps, tvb, offset, 2, ENC_BIG_ENDIAN);
evb_capabilities_subtree = proto_item_add_subtree(tf, ett_802_1qbg_capabilities_flags);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_configure_caps_std, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_configure_caps_rr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_configure_caps_rte, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_configure_caps_ecp, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(evb_capabilities_subtree, hf_ieee_802_1qbg_evb_configure_caps_vdp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee_802_1qbg_evb_supported_vsi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee_802_1qbg_evb_configured_vsi, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee_802_1qbg_evb_retrans_timer, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
}
return;
}
static int
dissect_ieee_802_3_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
guint8 tempByte;
guint16 tlvLen = tvb_reported_length(tvb)-offset;
proto_tree *mac_phy_flags = NULL;
proto_tree *autoneg_advertised_subtree = NULL;
proto_item *tf = NULL;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_ieee_802_3_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (subType)
{
case 0x01:
{
tf = proto_tree_add_item(tree, hf_ieee_802_3_mac_phy_auto_neg_status, tvb, offset, 1, ENC_BIG_ENDIAN);
mac_phy_flags = proto_item_add_subtree(tf, ett_802_3_flags);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mac_phy_auto_neg_status_supported, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mac_phy_auto_neg_status_enabled, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tf = proto_tree_add_item(tree, hf_ieee_802_3_pmd_auto_neg_advertised_caps, tvb, offset, 2, ENC_BIG_ENDIAN);
autoneg_advertised_subtree = proto_item_add_subtree(tf, ett_802_3_autoneg_advertised);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_tfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_t, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_xfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_x, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_bpause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_spause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_apause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_pause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t2fd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_txfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_tx, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_10base_tfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_10base_t, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_other, tvb, offset, 2, ENC_BIG_ENDIAN);
autoneg_advertised_subtree = proto_tree_add_subtree(tree, tvb, offset, 2, ett_802_3_autoneg_advertised, NULL, "Same in inverse (wrong) bitorder");
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_tfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_t, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_xfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_x, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_bpause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_spause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_apause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_pause, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t2fd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_txfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_tx, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t4, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_10base_tfd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_10base_t, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(autoneg_advertised_subtree, hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_other, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_ieee_802_3_pmd_mau_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
}
case 0x02:
{
tf = proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_support, tvb, offset, 1, ENC_BIG_ENDIAN);
mac_phy_flags = proto_item_add_subtree(tf, ett_802_3_power);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mdi_power_support_port_class, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mdi_power_support_pse_power_support, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mdi_power_support_pse_power_enabled, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_mdi_power_support_pse_pairs, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_pse_pair, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (tlvLen == 4)
break;
tempByte = tvb_get_guint8(tvb, offset);
subType = ((tempByte & 0xC0) >> 6);
proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_type, tvb, offset, 1, ENC_BIG_ENDIAN);
tf = proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_source, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (subType)
{
case 0:
case 2:
{
subType = ((tempByte & 0x30) >> 4);
proto_item_append_text(tf, " %s", val_to_str_const(subType, media_power_pse_device, "Reserved"));
break;
}
case 1:
case 3:
{
subType = ((tempByte & 0x30) >> 4);
proto_item_append_text(tf, " %s", val_to_str_const(subType, media_power_pd_device, "Reserved"));
break;
}
default:
{
proto_item_append_text(tf, " %s", "Unknown");
break;
}
}
proto_tree_add_item(tree, hf_ieee_802_3_mdi_power_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_802_3_mdi_requested_power, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(tree, hf_ieee_802_3_mdi_allocated_power, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
}
case 0x03:
{
tf = proto_tree_add_item(tree, hf_ieee_802_3_aggregation_status, tvb, offset, 1, ENC_BIG_ENDIAN);
mac_phy_flags = proto_item_add_subtree(tf, ett_802_3_aggregation);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_aggregation_status_cap, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mac_phy_flags, hf_ieee_802_3_aggregation_status_enabled, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_ieee_802_3_aggregated_port_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
break;
}
case 0x04:
{
proto_tree_add_item(tree, hf_ieee_802_3_max_frame_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
break;
}
}
return offset;
}
static void
dissect_media_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
guint16 tlvLen = tvb_reported_length(tvb)-offset;
guint8 subType;
guint8 tempByte;
guint32 LCI_Length;
proto_tree *media_flags = NULL;
proto_item *tf = NULL;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_media_tlv_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tlvLen--;
switch (subType)
{
case 1:
{
if (tlvLen < 2)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
tf = proto_tree_add_item(tree, hf_media_tlv_subtype_caps, tvb, offset, 2, ENC_BIG_ENDIAN);
media_flags = proto_item_add_subtree(tf, ett_media_capabilities);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_llpd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_network_policy, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_location_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_mdi_pse, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_mid_pd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(media_flags, hf_media_tlv_subtype_caps_inventory, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tlvLen -= 2;
if (tlvLen < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_tlv_subtype_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tlvLen--;
break;
}
case 2:
{
if (tlvLen < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_application_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tlvLen--;
if (tlvLen < 3)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_policy_flag, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_tag_flag, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_vlan_id, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_l2_prio, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_dscp, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
}
case 3:
{
if (tlvLen < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
tempByte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_media_loc_data_format, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tlvLen--;
switch (tempByte)
{
case 1:
{
if (tlvLen < 16)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_loc_lat_resolution, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_loc_lat, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_media_loc_long_resolution, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_loc_long, tvb, offset, 5, ENC_BIG_ENDIAN);
offset += 5;
proto_tree_add_item(tree, hf_media_loc_alt_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_media_loc_alt_resolution, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_media_loc_alt, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_media_loc_datum, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
}
case 2:
{
if (tlvLen < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
tempByte = tvb_get_guint8(tvb, offset);
tlvLen--;
if (tempByte > tlvLen)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length_excess , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_civic_lci_length, tvb, offset, 1 , ENC_BIG_ENDIAN);
LCI_Length = (guint32)tempByte;
offset++;
if (LCI_Length < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_civic_what, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
LCI_Length--;
if (LCI_Length < 2)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_civic_country, tvb, offset, 2, ENC_ASCII|ENC_NA);
offset += 2;
LCI_Length -= 2;
while (LCI_Length > 0)
{
if (LCI_Length < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
proto_tree_add_item(tree, hf_media_civic_addr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
LCI_Length--;
if (LCI_Length < 1)
{
proto_tree_add_expert(tree, pinfo, &ei_lldp_bad_length , tvb, offset, tlvLen);
return;
}
tempByte = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_media_civic_addr_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
LCI_Length--;
if (tempByte > LCI_Length)
return;
if (tempByte > 0)
{
proto_tree_add_item(tree, hf_media_civic_addr_value, tvb, offset, tempByte, ENC_ASCII|ENC_NA);
offset += tempByte;
LCI_Length -= tempByte;
}
}
break;
}
case 3:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_ecs, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
}
break;
}
case 4:
{
tempByte = tvb_get_guint8(tvb, offset);
subType = ((tempByte & 0xC0) >> 6);
proto_tree_add_item(tree, hf_media_power_type, tvb, offset, 1, ENC_BIG_ENDIAN);
tf = proto_tree_add_item(tree, hf_media_power_source, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (subType)
{
case 0:
{
subType = ((tempByte & 0x30) >> 4);
proto_item_append_text(tf, " %s", val_to_str_const(subType, media_power_pse_device, "Reserved"));
break;
}
case 1:
{
subType = ((tempByte & 0x30) >> 4);
proto_item_append_text(tf, " %s", val_to_str_const(subType, media_power_pd_device, "Reserved"));
break;
}
default:
{
proto_item_append_text(tf, " %s", "Unknown");
break;
}
}
proto_tree_add_item(tree, hf_media_power_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_media_power_value, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
case 5:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_hardware, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 6:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_firmware, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 7:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_software, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 8:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_sn, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 9:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_manufacturer, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 10:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_model, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
case 11:
{
if (tlvLen > 0)
{
proto_tree_add_item(tree, hf_media_asset, tvb, offset, tlvLen, ENC_ASCII|ENC_NA);
}
break;
}
}
return;
}
static guint32
dissect_profinet_period(tvbuff_t *tvb, proto_tree *tree, guint32 offset, const gchar *name, int hf_valid, int hf_value)
{
guint32 period;
proto_tree *period_tree;
period = tvb_get_ntohl(tvb, offset);
period_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_profinet_period, NULL, "%s: %s, %uns",
name, (period & 0x80000000) ? "Valid" : "Invalid", period & 0x7FFFFFFF);
proto_tree_add_uint(period_tree, hf_valid, tvb, offset, 4, period);
proto_tree_add_uint(period_tree, hf_value, tvb, offset, 4, period);
offset+=4;
return offset;
}
static void
dissect_profinet_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
proto_item *tf = NULL;
guint16 class2_PortStatus;
guint16 class3_PortStatus;
guint32 port_rx_delay_local;
guint32 port_rx_delay_remote;
guint32 port_tx_delay_local;
guint32 port_tx_delay_remote;
guint32 cable_delay_local;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_profinet_tlv_subtype, tvb, offset, 1, subType);
offset++;
switch (subType)
{
case 1:
{
port_rx_delay_local = tvb_get_ntohl(tvb, offset);
tf = proto_tree_add_uint(tree, hf_profinet_port_rx_delay_local, tvb, offset, 4, port_rx_delay_local);
if(port_rx_delay_local) {
proto_item_append_text(tf, "ns");
} else {
proto_item_append_text(tf, " (unknown)");
}
offset+=4;
port_rx_delay_remote = tvb_get_ntohl(tvb, offset);
tf = proto_tree_add_uint(tree, hf_profinet_port_rx_delay_remote, tvb, offset, 4, port_rx_delay_remote);
if(port_rx_delay_remote) {
proto_item_append_text(tf, "ns");
} else {
proto_item_append_text(tf, " (unknown)");
}
offset+=4;
port_tx_delay_local = tvb_get_ntohl(tvb, offset);
tf = proto_tree_add_uint(tree, hf_profinet_port_tx_delay_local, tvb, offset, 4, port_tx_delay_local);
if(port_tx_delay_local) {
proto_item_append_text(tf, "ns");
} else {
proto_item_append_text(tf, " (unknown)");
}
offset+=4;
port_tx_delay_remote = tvb_get_ntohl(tvb, offset);
tf = proto_tree_add_uint(tree, hf_profinet_port_tx_delay_remote, tvb, offset, 4, port_tx_delay_remote);
if(port_tx_delay_remote) {
proto_item_append_text(tf, "ns");
} else {
proto_item_append_text(tf, " (unknown)");
}
offset+=4;
cable_delay_local = tvb_get_ntohl(tvb, offset);
tf = proto_tree_add_uint(tree, hf_profinet_cable_delay_local, tvb, offset, 4, cable_delay_local);
if(cable_delay_local) {
proto_item_append_text(tf, "ns");
} else {
proto_item_append_text(tf, " (unknown)");
}
break;
}
case 2:
{
class2_PortStatus = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_profinet_class2_port_status, tvb, offset, 2, class2_PortStatus);
offset+=2;
class3_PortStatus = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, hf_profinet_class3_port_status, tvb, offset, 2, class3_PortStatus);
proto_tree_add_uint(tree, hf_profinet_class3_port_status_reserved, tvb, offset, 2, class3_PortStatus);
proto_tree_add_uint(tree, hf_profinet_class3_port_status_Fragmentation, tvb, offset, 2, class3_PortStatus);
proto_tree_add_uint(tree, hf_profinet_class3_port_status_PreambleLength, tvb, offset, 2, class3_PortStatus);
class3_PortStatus = class3_PortStatus & 0x7;
col_append_fstr(pinfo->cinfo, COL_INFO,"RTClass3 Port Status = %s", val_to_str(class3_PortStatus, profinet_port3_status_vals, "Unknown %d"));
break;
}
case 4:
{
proto_tree_add_item(tree, hf_profinet_mrp_domain_uuid, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_profinet_mrrt_port_status, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
case 5:
{
proto_tree_add_item(tree, hf_profinet_cm_mac, tvb, offset, 6, ENC_NA);
break;
}
case 6:
{
proto_tree_add_item(tree, hf_profinet_master_source_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_profinet_subdomain_uuid, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(tree, hf_profinet_ir_data_uuid, tvb, offset, 16, ENC_BIG_ENDIAN);
offset += 16;
offset = dissect_profinet_period(tvb, tree, offset, "LengthOfPeriod",
hf_profinet_length_of_period_valid, hf_profinet_length_of_period_length);
offset = dissect_profinet_period(tvb, tree, offset, "RedPeriodBegin",
hf_profinet_red_period_begin_valid, hf_profinet_red_period_begin_offset);
offset = dissect_profinet_period(tvb, tree, offset, "OrangePeriodBegin",
hf_profinet_orange_period_begin_valid, hf_profinet_orange_period_begin_offset);
dissect_profinet_period(tvb, tree, offset, "GreenPeriodBegin",
hf_profinet_green_period_begin_valid, hf_profinet_green_period_begin_offset);
break;
}
default:
proto_tree_add_item(tree, hf_unknown_subtype_content, tvb, offset, -1, ENC_NA);
}
}
static void
dissect_cisco_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subType;
proto_tree *fourwire_data = NULL;
proto_item *tf = NULL;
subType = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cisco_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch (subType)
{
case 0x01:
tf = proto_tree_add_item(tree, hf_cisco_four_wire_power, tvb, offset, 1, ENC_BIG_ENDIAN);
fourwire_data = proto_item_add_subtree(tf, ett_cisco_fourwire_tlv);
proto_tree_add_item(fourwire_data, hf_cisco_four_wire_power_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fourwire_data, hf_cisco_four_wire_power_spare_pair_arch, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fourwire_data, hf_cisco_four_wire_power_req_spare_pair_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fourwire_data, hf_cisco_four_wire_power_pse_spare_pair_poe, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_unknown_subtype_content, tvb, offset, -1, ENC_NA);
break;
}
}
static void
dissect_hytec_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint8 subtype, group, identifier;
gint32 bit_offset, msg_len, expected_data_length, maximum_data_length, temp_gint32;
proto_tree *hytec_data = NULL;
proto_item *tf = NULL;
proto_item *tlm, *group_proto_item, *identifier_proto_item;
float float_value = 0.0f;
subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_hytec_tlv_subtype, tvb, offset, 1, subtype);
offset++;
bit_offset = (gint32)(offset *8);
group = tvb_get_bits8(tvb, bit_offset + HYTEC_GROUP_MASK_OFFSET, HYTEC_GROUP_MASK_SIZE);
identifier = tvb_get_bits8(tvb, bit_offset + HYTEC_IDENTIFIER_MASK_OFFSET, HYTEC_IDENTIFIER_MASK_SIZE);
group_proto_item = proto_tree_add_item(tree, hf_hytec_group, tvb, offset, 1, ENC_BIG_ENDIAN);
identifier_proto_item = proto_tree_add_item(tree, hf_hytec_identifier, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(identifier_proto_item, " (");
offset++;
msg_len = tvb_reported_length_remaining(tvb, offset);
switch (subtype)
{
case HYTEC_SUBTYPE__TRANSCEIVER:
proto_item_append_text(group_proto_item, " (%s)", val_to_str_const(group, hytec_transceiver_groups, "Unknown" ));
switch (group)
{
case HYTEC_TRANSG__TRANCEIVER_IDENTIFIER:
proto_item_append_text(identifier_proto_item, "%s", val_to_str_const(identifier, hytec_tid, "Unknown"));
switch (identifier)
{
case HYTEC_TID__VENDOR_PRODUCT_REVISION:
maximum_data_length = 64;
if(0 < msg_len && msg_len <= maximum_data_length)
proto_tree_add_item(tree, hf_hytec_transceiver_vendor_product_revision, tvb, offset, msg_len, ENC_ASCII|ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) is beyond valid range (1-%d)", val_to_str_const(identifier, hytec_tid, ""), msg_len, maximum_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
default: proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
case HYTEC_TRANSG__TRANSCEIVER_BRIDGEABLE_DISTANCE:
expected_data_length = 4;
proto_item_append_text(identifier_proto_item, "%s", val_to_str_const(identifier, hytec_tbd, "Unknown"));
switch (identifier)
{
case HYTEC_TBD__SINGLE_MODE:
if(msg_len == expected_data_length)
{
tlm = proto_tree_add_item(tree, hf_hytec_single_mode, tvb, offset, msg_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlm, " m");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_tbd, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_TBD__MULTI_MODE_50:
if(msg_len == expected_data_length)
{
tlm = proto_tree_add_item(tree, hf_hytec_multi_mode_50, tvb, offset, msg_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlm, " m");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_tbd, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_TBD__MULTI_MODE_62_5:
if(msg_len == expected_data_length)
{
tlm = proto_tree_add_item(tree, hf_hytec_multi_mode_62_5, tvb, offset, msg_len, ENC_BIG_ENDIAN);
proto_item_append_text(tlm, " m");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_tbd, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
default: proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
case HYTEC_TRANSG__MEASUREMENT_DATA:
expected_data_length = 4;
proto_item_append_text(identifier_proto_item, "%s", val_to_str_const(identifier, hytec_md, "Unknown"));
switch (identifier)
{
case HYTEC_MD__TX_CURRENT_OUTPUT_POWER:
if(msg_len == expected_data_length)
{
temp_gint32 = (gint32) tvb_get_ntohl(tvb, offset);
float_value = (float) 0.1 * (float) temp_gint32;
tlm = proto_tree_add_float(tree, hf_hytec_tx_current_output_power, tvb, offset, msg_len, float_value);
proto_item_append_text(tlm, " uW");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_md, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MD__RX_CURRENT_INPUT_POWER:
if(msg_len == expected_data_length)
{
temp_gint32 = (gint32) tvb_get_ntohl(tvb, offset);
float_value = (float) 0.1 * (float) temp_gint32;
tlm = proto_tree_add_float(tree, hf_hytec_rx_current_input_power, tvb, offset, msg_len, float_value);
proto_item_append_text(tlm, " uW");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_md, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MD__RX_INPUT_SNR:
if(msg_len == expected_data_length)
{
temp_gint32 = (gint32) tvb_get_ntohl(tvb, offset);
if(temp_gint32 < 0) float_value = (float)-1.0 * (float)((~temp_gint32) >> 8);
else float_value = (float) (temp_gint32 >> 8);
float_value += (float)(temp_gint32 & 0xFF) * (float)0.00390625;
tlm = proto_tree_add_float(tree, hf_hytec_rx_input_snr, tvb, offset, msg_len, float_value);
proto_item_append_text(tlm, " dB");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_md, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MD__LINELOSS:
if(msg_len == expected_data_length)
{
temp_gint32 = (gint32) tvb_get_ntohl(tvb, offset);
if(temp_gint32 < 0) float_value = (float)-1.0 * (float)((~temp_gint32) >> 8);
else float_value = (float) (temp_gint32 >> 8);
float_value += (float)(temp_gint32 & 0xFF) * (float)0.00390625;
tlm = proto_tree_add_float(tree, hf_hytec_lineloss, tvb, offset, msg_len, float_value);
proto_item_append_text(tlm, " dB");
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_md, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
default: proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
default:
proto_item_append_text(identifier_proto_item, "Unknown");
proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
case HYTEC_SUBTYPE__TRACE:
proto_item_append_text(group_proto_item, " (%s)", val_to_str_const(group, hytec_trace_groups, "Unknown"));
switch (group)
{
case HYTEC_TRACEG__MAC_TRACE:
proto_item_append_text(identifier_proto_item, "%s", val_to_str_const(identifier, hytec_mc, "Unknown"));
switch (identifier)
{
case HYTEC_MC__MAC_TRACE_REQUEST:
expected_data_length = 13;
if(msg_len == expected_data_length)
{
tf = proto_tree_add_item(tree, hf_hytec_mac_trace_request, tvb, offset, -1, ENC_NA);
hytec_data = proto_item_add_subtree(tf, ett_org_spc_hytec_trace_request);
proto_tree_add_item(hytec_data, hf_hytec_trace_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hytec_data, hf_hytec_request_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hytec_data, hf_hytec_maximum_depth, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__MAC_TRACE_REPLY:
expected_data_length = 13;
if(msg_len == expected_data_length)
{
tf = proto_tree_add_item(tree, hf_hytec_mac_trace_reply, tvb, offset, -1, ENC_NA);
hytec_data = proto_item_add_subtree(tf, ett_org_spc_hytec_trace_reply);
proto_tree_add_item(hytec_data, hf_hytec_trace_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hytec_data, hf_hytec_answering_mac_address, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hytec_data, hf_hytec_actual_depth, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__NAME_OF_REPLYING_DEVICE:
maximum_data_length = 64;
if(0 < msg_len && msg_len <= maximum_data_length) proto_tree_add_item(tree, hf_hytec_name_of_replying_device, tvb, offset, msg_len, ENC_ASCII|ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) is beyond valid range (1-%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, maximum_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__OUTGOING_PORT_NAME:
maximum_data_length = 64;
if(0 < msg_len && msg_len <= maximum_data_length) proto_tree_add_item(tree, hf_hytec_outgoing_port_name, tvb, offset, msg_len, ENC_ASCII|ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) is beyond valid range (1-%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, maximum_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__IPV4_ADDRESS_OF_REPLYING_DEVICE:
expected_data_length = 4;
if(msg_len == expected_data_length) proto_tree_add_item(tree, hf_hytec_ipv4_address_of_replying_device, tvb, offset, msg_len, ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__END_OF_TRACE:
expected_data_length = 1;
if(msg_len == expected_data_length) proto_tree_add_item(tree, hf_hytec_end_of_trace, tvb, offset, msg_len, ENC_BIG_ENDIAN);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__IPV6_ADDRESS_OF_REPLYING_DEVICE:
expected_data_length = 16;
if(msg_len == expected_data_length) proto_tree_add_item(tree, hf_hytec_ipv6_address_of_replying_device, tvb, offset, msg_len, ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__INCOMING_PORT_NAME:
maximum_data_length = 64;
if(0 < msg_len && msg_len <= maximum_data_length) proto_tree_add_item(tree, hf_hytec_incoming_port_name, tvb, offset, msg_len, ENC_ASCII|ENC_NA);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) is beyond valid range (1-%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, maximum_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
case HYTEC_MC__TRACE_IDENTIFIER:
expected_data_length = 4;
if(msg_len == expected_data_length) proto_tree_add_item(tree, hf_hytec_trace_identifier, tvb, offset, msg_len, ENC_BIG_ENDIAN);
else
{
expert_add_info_format(pinfo, tree, &ei_lldp_bad_length, "%s length (%d) != expected length (%d)", val_to_str_const(identifier, hytec_mc, ""), msg_len, expected_data_length);
if(msg_len) proto_tree_add_item(tree, hf_hytec_invalid_object_data, tvb, offset, msg_len, ENC_STR_HEX);
}
break;
default: proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
default:
proto_item_append_text(identifier_proto_item, "Unknown");
proto_tree_add_item(tree, hf_hytec_unknown_identifier_content, tvb, offset, -1, ENC_NA);
}
break;
default:
proto_item_append_text(group_proto_item, " (Unknown)");
proto_item_append_text(identifier_proto_item, "Unknown");
proto_tree_add_item(tree, hf_unknown_subtype_content, tvb, offset, -1, ENC_NA);
break;
}
proto_item_append_text(identifier_proto_item, ")");
}
static gint32
dissect_organizational_specific_tlv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 offset)
{
guint16 dataLen;
guint16 tempShort;
gint tempTree;
guint32 oui, tLength = tvb_reported_length(tvb);
guint8 subType;
const char *ouiStr;
const char *subTypeStr;
proto_tree *org_tlv_tree = NULL;
proto_item *lf = NULL;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
oui = tvb_get_ntoh24(tvb, (offset+2));
subType = tvb_get_guint8(tvb, (offset+5));
if( dissector_try_uint(oui_unique_code_table, oui, tvb, pinfo, tree) ) {
return tLength;
}
ouiStr = val_to_str_const(oui, oui_vals, "Unknown");
if (strcmp(ouiStr, "Unknown")==0) {
ouiStr = uint_get_manuf_name_if_known(oui);
if(ouiStr==NULL) ouiStr="Unknown";
}
tempTree = ett_org_spc_ProfinetSubTypes_1;
switch(oui)
{
case OUI_DCBX:
subTypeStr = val_to_str(subType, dcbx_protocol_types, "Unknown subtype (0x%x)");
switch(subType)
{
case 1: tempTree = ett_org_spc_dcbx_cin;
break;
case 2: tempTree = ett_org_spc_dcbx_cee;
break;
}
break;
case OUI_IEEE_802_1:
subTypeStr = val_to_str(subType, ieee_802_1_subtypes, "Unknown subtype 0x%x");
switch(subType)
{
case 0x1: tempTree = ett_org_spc_ieee_802_1_1;
break;
case 0x2: tempTree = ett_org_spc_ieee_802_1_2;
break;
case 0x3: tempTree = ett_org_spc_ieee_802_1_3;
break;
case 0x4: tempTree = ett_org_spc_ieee_802_1_4;
break;
case 0x8: tempTree = ett_org_spc_ieee_802_1_8;
break;
case 0x9: tempTree = ett_org_spc_ieee_802_1_9;
break;
case 0xa: tempTree = ett_org_spc_ieee_802_1_a;
break;
case 0xb: tempTree = ett_org_spc_ieee_802_1_b;
break;
case 0xc: tempTree = ett_org_spc_ieee_802_1_c;
break;
}
break;
case OUI_IEEE_802_3:
subTypeStr = val_to_str(subType, ieee_802_3_subtypes, "Unknown subtype 0x%x");
switch(subType)
{
case 1: tempTree = ett_org_spc_ieee_802_3_1;
break;
case 2: tempTree = ett_org_spc_ieee_802_3_2;
break;
case 3: tempTree = ett_org_spc_ieee_802_3_3;
break;
case 4: tempTree = ett_org_spc_ieee_802_3_4;
break;
}
break;
case OUI_MEDIA_ENDPOINT:
subTypeStr = val_to_str(subType, media_subtypes, "Unknown subtype 0x%x");
switch(subType)
{
case 1: tempTree = ett_org_spc_media_1;
break;
case 2: tempTree = ett_org_spc_media_2;
break;
case 3: tempTree = ett_org_spc_media_3;
break;
case 4: tempTree = ett_org_spc_media_4;
break;
case 5: tempTree = ett_org_spc_media_5;
break;
case 6: tempTree = ett_org_spc_media_6;
break;
case 7: tempTree = ett_org_spc_media_7;
break;
case 8: tempTree = ett_org_spc_media_8;
break;
case 9: tempTree = ett_org_spc_media_9;
break;
case 10: tempTree = ett_org_spc_media_10;
break;
case 11: tempTree = ett_org_spc_media_11;
break;
}
break;
case OUI_PROFINET:
subTypeStr = val_to_str(subType, profinet_subtypes, "Reserved (0x%x)");
switch(subType)
{
case 1: tempTree = ett_org_spc_ProfinetSubTypes_1;
break;
case 2: tempTree = ett_org_spc_ProfinetSubTypes_2;
break;
case 3: tempTree = ett_org_spc_ProfinetSubTypes_3;
break;
case 4: tempTree = ett_org_spc_ProfinetSubTypes_4;
break;
case 5: tempTree = ett_org_spc_ProfinetSubTypes_5;
break;
case 6: tempTree = ett_org_spc_ProfinetSubTypes_6;
break;
}
break;
case OUI_CISCO_2:
subTypeStr = val_to_str(subType, cisco_subtypes, "Unknown subtype (0x%x)");
break;
case OUI_IEEE_802_1QBG:
subTypeStr = val_to_str(subType, ieee_802_1qbg_subtypes, "Unknown subtype 0x%x");
break;
case OUI_HYTEC_GER:
subTypeStr = val_to_str(subType, hytec_subtypes, "Unknown subtype (0x%x)");
switch(subType)
{
case HYTEC_SUBTYPE__TRANSCEIVER: tempTree = ett_org_spc_hytec_subtype_transceiver;
break;
case HYTEC_SUBTYPE__TRACE: tempTree = ett_org_spc_hytec_subtype_trace;
break;
}
break;
default:
subTypeStr = wmem_strdup_printf(wmem_packet_scope(), "Unknown (%d)",subType);
break;
}
org_tlv_tree = proto_tree_add_subtree_format(tree, tvb, offset, tLength, tempTree, NULL, "%s - %s", ouiStr, subTypeStr);
proto_tree_add_item(org_tlv_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
lf = proto_tree_add_item(org_tlv_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
if (dataLen < 4)
{
expert_add_info_format(pinfo, lf, &ei_lldp_bad_length,
"TLV length (%u) too short, must be >=4)", dataLen);
return tLength;
}
proto_tree_add_uint(org_tlv_tree, hf_org_spc_oui, tvb, (offset + 2), 3, oui);
switch (oui)
{
case OUI_DCBX:
dissect_dcbx_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_IEEE_802_1:
dissect_ieee_802_1_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_IEEE_802_3:
dissect_ieee_802_3_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_MEDIA_ENDPOINT:
dissect_media_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_PROFINET:
dissect_profinet_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_CISCO_2:
dissect_cisco_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_IEEE_802_1QBG:
dissect_ieee_802_1qbg_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
case OUI_HYTEC_GER:
dissect_hytec_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
break;
default:
dissect_oui_default_tlv(tvb, pinfo, org_tlv_tree, (offset + 5));
}
return offset + tvb_reported_length(tvb);
}
static gint32
dissect_lldp_unknown_tlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, guint32 offset)
{
guint16 dataLen;
guint16 tempShort;
proto_tree *unknown_tlv_tree;
tempShort = tvb_get_ntohs(tvb, offset);
dataLen = TLV_INFO_LEN(tempShort);
unknown_tlv_tree = proto_tree_add_subtree(tree, tvb, offset, (dataLen + 2), ett_unknown_tlv, NULL, "Unknown TLV");
proto_tree_add_item(unknown_tlv_tree, hf_lldp_tlv_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(unknown_tlv_tree, hf_lldp_tlv_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += dataLen;
return offset;
}
static void
dissect_lldp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *lldp_tree = NULL;
tvbuff_t *new_tvb = NULL;
guint32 offset = 0;
gint32 rtnValue = 0;
guint16 tempShort;
guint8 tlvType;
gboolean reachedEnd = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LLDP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_lldp, tvb, offset, -1, ENC_NA);
lldp_tree = proto_item_add_subtree(ti, ett_lldp);
tempShort = tvb_get_ntohs(tvb, offset);
new_tvb = tvb_new_subset_length(tvb, offset, TLV_INFO_LEN(tempShort)+2);
rtnValue = dissect_lldp_chassis_id(new_tvb, pinfo, lldp_tree, 0);
if (rtnValue < 0)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid Chassis ID TLV");
return;
}
offset += rtnValue;
tempShort = tvb_get_ntohs(tvb, offset);
new_tvb = tvb_new_subset_length(tvb, offset, TLV_INFO_LEN(tempShort)+2);
rtnValue = dissect_lldp_port_id(new_tvb, pinfo, lldp_tree, 0);
if (rtnValue < 0)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid Port ID TLV");
return;
}
offset += rtnValue;
tempShort = tvb_get_ntohs(tvb, offset);
new_tvb = tvb_new_subset_length(tvb, offset, TLV_INFO_LEN(tempShort)+2);
rtnValue = dissect_lldp_time_to_live(new_tvb, pinfo, lldp_tree, 0);
if (rtnValue < 0)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid Time-to-Live TLV");
return;
}
offset += rtnValue;
while (!reachedEnd)
{
tempShort = tvb_get_ntohs(tvb, offset);
tlvType = TLV_TYPE(tempShort);
new_tvb = tvb_new_subset_length(tvb, offset, TLV_INFO_LEN(tempShort)+2);
switch (tlvType)
{
case CHASSIS_ID_TLV_TYPE:
dissect_lldp_chassis_id(new_tvb, pinfo, lldp_tree, 0);
rtnValue = -1;
col_set_str(pinfo->cinfo, COL_INFO, "Duplicate Chassis ID TLV");
break;
case PORT_ID_TLV_TYPE:
dissect_lldp_port_id(new_tvb, pinfo, lldp_tree, 0);
rtnValue = -1;
col_set_str(pinfo->cinfo, COL_INFO, "Duplicate Port ID TLV");
break;
case TIME_TO_LIVE_TLV_TYPE:
dissect_lldp_time_to_live(new_tvb, pinfo, lldp_tree, 0);
rtnValue = -1;
col_set_str(pinfo->cinfo, COL_INFO, "Duplicate Time-To-Live TLV");
break;
case END_OF_LLDPDU_TLV_TYPE:
rtnValue = dissect_lldp_end_of_lldpdu(new_tvb, pinfo, lldp_tree, 0);
break;
case PORT_DESCRIPTION_TLV_TYPE:
rtnValue = dissect_lldp_port_desc(new_tvb, pinfo, lldp_tree, 0);
break;
case SYSTEM_NAME_TLV_TYPE:
case SYSTEM_DESCRIPTION_TLV_TYPE:
rtnValue = dissect_lldp_system_name(new_tvb, pinfo, lldp_tree, 0);
break;
case SYSTEM_CAPABILITIES_TLV_TYPE:
rtnValue = dissect_lldp_system_capabilities(new_tvb, pinfo, lldp_tree, 0);
break;
case MANAGEMENT_ADDR_TLV_TYPE:
rtnValue = dissect_lldp_management_address(new_tvb, pinfo, lldp_tree, 0);
break;
case ORGANIZATION_SPECIFIC_TLV_TYPE:
rtnValue = dissect_organizational_specific_tlv(new_tvb, pinfo, lldp_tree, 0);
break;
default:
rtnValue = dissect_lldp_unknown_tlv(new_tvb, pinfo, lldp_tree, 0);
break;
}
if (rtnValue < 0)
reachedEnd = TRUE;
else
offset += rtnValue;
}
}
void
proto_register_lldp(void)
{
expert_module_t *expert_lldp;
static hf_register_info hf[] = {
{ &hf_lldp_tlv_type,
{ "TLV Type", "lldp.tlv.type", FT_UINT16, BASE_DEC,
VALS(tlv_types), TLV_TYPE_MASK, NULL, HFILL }
},
{ &hf_lldp_tlv_len,
{ "TLV Length", "lldp.tlv.len", FT_UINT16, BASE_DEC,
NULL, TLV_INFO_LEN_MASK, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap,
{ "Capabilities", "lldp.tlv.system_cap", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_other,
{ "Other", "lldp.tlv.system_cap.other", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_OTHER, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_repeater,
{ "Repeater", "lldp.tlv.system_cap.repeater", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_REPEATER, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_bridge,
{ "Bridge", "lldp.tlv.system_cap.bridge", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_BRIDGE, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_wlan_access_pt,
{ "WLAN access point", "lldp.tlv.system_cap.wlan_access_pt", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_WLAN, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_router,
{ "Router", "lldp.tlv.system_cap.router", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_ROUTER, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_telephone,
{ "Telephone", "lldp.tlv.system_cap.telephone", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_TELEPHONE, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_docsis_cable_device,
{ "DOCSIS cable device", "lldp.tlv.system_cap.docsis_cable_device", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_DOCSIS, NULL, HFILL }
},
{ &hf_lldp_tlv_system_cap_station_only,
{ "Station only", "lldp.tlv.system_cap.station_only", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_STATION, NULL, HFILL }
},
{ &hf_lldp_tlv_system_name,
{ "System Name", "lldp.tlv.system.name", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_lldp_tlv_system_desc,
{ "System Description", "lldp.tlv.system.desc", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap,
{ "Enabled Capabilities", "lldp.tlv.enable_system_cap", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_other,
{ "Other", "lldp.tlv.enable_system_cap.other", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_OTHER, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_repeater,
{ "Repeater", "lldp.tlv.enable_system_cap.repeater", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_REPEATER, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_bridge,
{ "Bridge", "lldp.tlv.enable_system_cap.bridge", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_BRIDGE, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_wlan_access_pt,
{ "WLAN access point", "lldp.tlv.enable_system_cap.wlan_access_pt", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_WLAN, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_router,
{ "Router", "lldp.tlv.enable_system_cap.router", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_ROUTER, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_telephone,
{ "Telephone", "lldp.tlv.enable_system_cap.telephone", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_TELEPHONE, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_docsis_cable_device,
{ "DOCSIS cable device", "lldp.tlv.enable_system_cap.docsis_cable_device", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_DOCSIS, NULL, HFILL }
},
{ &hf_lldp_tlv_enable_system_cap_station_only,
{ "Station only", "lldp.tlv.enable_system_cap.station_only", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), SYSTEM_CAPABILITY_STATION, NULL, HFILL }
},
{ &hf_chassis_id_subtype,
{ "Chassis Id Subtype", "lldp.chassis.subtype", FT_UINT8, BASE_DEC,
VALS(chassis_id_subtypes), 0, NULL, HFILL }
},
{ &hf_chassis_id,
{ "Chassis Id", "lldp.chassis.id", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_chassis_id_mac,
{ "Chassis Id", "lldp.chassis.id.mac", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_chassis_id_ip4,
{ "Chassis Id", "lldp.chassis.id.ip4", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_chassis_id_ip6,
{ "Chassis Id", "lldp.chassis.id.ip6", FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_port_id_subtype,
{ "Port Id Subtype", "lldp.port.subtype", FT_UINT8, BASE_DEC,
VALS(port_id_subtypes), 0, NULL, HFILL }
},
{ &hf_port_id,
{ "Port Id", "lldp.port.id", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_port_desc,
{ "Port Description", "lldp.port.desc", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_port_id_mac,
{ "Port Id", "lldp.port.id.mac", FT_ETHER, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_lldp_network_address_family,
{ "Network Address family", "lldp.network_address.subtype", FT_UINT8, BASE_DEC,
VALS(afn_vals), 0, NULL, HFILL }
},
{ &hf_port_id_ip4,
{ "Port Id", "lldp.port.id.ip4", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_port_id_ip6,
{ "Port Id", "lldp.port.id.ip6", FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_time_to_live,
{ "Seconds", "lldp.time_to_live", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_address_len,
{ "Address String Length", "lldp.mgn.address.len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_address_subtype,
{ "Address Subtype", "lldp.mgn.address.subtype", FT_UINT8, BASE_DEC,
VALS(afn_vals), 0, "Undefined", HFILL }
},
{ &hf_mgn_addr_ipv4,
{ "Management Address", "lldp.mgn.addr.ip4", FT_IPv4, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_addr_ipv6,
{ "Management Address", "lldp.mgn.addr.ip6", FT_IPv6, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_addr_hex,
{ "Management Address", "lldp.mgn.addr.hex", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_interface_subtype,
{ "Interface Subtype", "lldp.mgn.interface.subtype", FT_UINT8, BASE_DEC,
VALS(interface_subtype_values), 0, "Undefined", HFILL }
},
{ &hf_mgn_interface_number,
{ "Interface Number", "lldp.mgn.interface.number", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_oid_len,
{ "OID String Length", "lldp.mgn.obj.len", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_mgn_obj_id,
{ "Object Identifier", "lldp.mgn.obj.id", FT_OID, BASE_NONE,
NULL, 0, NULL, HFILL }
},
{ &hf_org_spc_oui,
{ "Organization Unique Code", "lldp.orgtlv.oui", FT_UINT24, BASE_HEX,
VALS(oui_vals), 0x0, NULL, HFILL }
},
{ &hf_dcbx_type,
{ "DCBx Protocol", "lldp.dcbx.proto", FT_UINT8, BASE_HEX,
VALS(dcbx_protocol_types), 0x0, NULL, HFILL }
},
{ &hf_dcbx_tlv_type,
{ "DCBx TLV Type", "lldp.dcbx.type", FT_UINT16, BASE_DEC,
VALS(dcbx_subtypes), TLV_TYPE_MASK, NULL, HFILL }
},
{ &hf_dcbx_tlv_len,
{ "DCBx TLV Length", "lldp.dcbx.len", FT_UINT16, BASE_DEC,
NULL, TLV_INFO_LEN_MASK, NULL, HFILL }
},
{ &hf_dcbx_tlv_oper_version,
{ "Operating Version", "lldp.dcbx.version", FT_UINT8, BASE_HEX,
VALS(dcbx_protocol_types), 0x0, "Unknown", HFILL }
},
{ &hf_dcbx_tlv_max_version,
{ "Max Version", "lldp.dcbx.max_version", FT_UINT8, BASE_HEX,
VALS(dcbx_protocol_types), 0x0, "Unknown", HFILL }
},
{ &hf_dcbx_control_sequence,
{ "Sequence No", "lldp.dcbx.contol.seq", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_control_ack,
{ "Ack No", "lldp.dcbx.control.ack", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_flag_enabled,
{ "Feature", "lldp.dcbx.feature.enabled", FT_BOOLEAN , 8,
TFS(&tfs_enabled_disabled), 0x80, NULL, HFILL }
},
{ &hf_dcbx_feature_flag_willing,
{ "Willing", "lldp.dcbx.feature.willing", FT_BOOLEAN , 8,
TFS(&tfs_yes_no), 0x40, NULL, HFILL }
},
{ &hf_dcbx_feature_flag_error,
{ "Error", "lldp.dcbx.feature.error", FT_BOOLEAN , 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }
},
{ &hf_dcbx_feature_subtype,
{ "Subtype", "lldp.dcbx.feature.subtype", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pgid_reserved,
{ "Reserved", "lldp.dcbx.feature.pg.reserved", FT_UINT8, BASE_HEX,
NULL, 0xF000, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_0,
{ "PGID for Prio 0", "lldp.dcbx.feature.pg.pgid_prio0", FT_UINT16, BASE_DEC,
NULL, 0xF000, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_1,
{ "PGID for Prio 1", "lldp.dcbx.feature.pg.pgid_prio1", FT_UINT16, BASE_DEC,
NULL, 0xF00, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_2,
{ "PGID for Prio 2", "lldp.dcbx.feature.pg.pgid_prio2", FT_UINT16, BASE_DEC,
NULL, 0xF0, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_3,
{ "PGID for Prio 3", "lldp.dcbx.feature.pg.pgid_prio3", FT_UINT16, BASE_DEC,
NULL, 0xF, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_4,
{ "PGID for Prio 4", "lldp.dcbx.feature.pg.pgid_prio4", FT_UINT16, BASE_DEC,
NULL, 0xF000, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_5,
{ "PGID for Prio 5", "lldp.dcbx.feature.pg.pgid_prio5", FT_UINT16, BASE_DEC,
NULL, 0xF00, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_6,
{ "PGID for Prio 6", "lldp.dcbx.feature.pg.pgid_prio6", FT_UINT16, BASE_DEC,
NULL, 0xF0, 0, HFILL }
},
{ &hf_dcbx_feature_pgid_prio_7,
{ "PGID for Prio 7", "lldp.dcbx.feature.pg.pgid_prio7", FT_UINT16, BASE_DEC,
NULL, 0xF, 0, HFILL }
},
{ &hf_dcbx_feature_pg_per_0,
{ "Bandwidth for PGID 0", "lldp.dcbx.feature.pg.per0", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_1,
{ "Bandwidth for PGID 1", "lldp.dcbx.feature.pg.per1", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_2,
{ "Bandwidth for PGID 2", "lldp.dcbx.feature.pg.per2", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_3,
{ "Bandwidth for PGID 3", "lldp.dcbx.feature.pg.per3", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_4,
{ "Bandwidth for PGID 4", "lldp.dcbx.feature.pg.per4", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_5,
{ "Bandwidth for PGID 5", "lldp.dcbx.feature.pg.per5", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_6,
{ "Bandwidth for PGID 6", "lldp.dcbx.feature.pg.per6", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_per_7,
{ "Bandwidth for PGID 7", "lldp.dcbx.feature.pg.per7", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pg_numtcs,
{ "Number of Traffic Classes Supported", "lldp.dcbx.feature.pg.numtcs", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio0,
{ "PFC for Priority 0", "lldp.dcbx.feature.pfc.prio0", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x1, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio1,
{ "PFC for Priority 1", "lldp.dcbx.feature.pfc.prio1", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x2, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio2,
{ "PFC for Priority 2", "lldp.dcbx.feature.pfc.prio2", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x4, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio3,
{ "PFC for Priority 3", "lldp.dcbx.feature.pfc.prio3", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x8, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio4,
{ "PFC for Priority 4", "lldp.dcbx.feature.pfc.prio4", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x10, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio5,
{ "PFC for Priority 5", "lldp.dcbx.feature.pfc.prio5", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio6,
{ "PFC for Priority 6", "lldp.dcbx.feature.pfc.prio6", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x40, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_prio7,
{ "PFC for Priority 7", "lldp.dcbx.feature.pfc.prio7", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x80, NULL, HFILL }
},
{ &hf_dcbx_feature_pfc_numtcs,
{ "Number of Traffic Classes Supported", "lldp.dcbx.feature.pfc.numtcs", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_app_proto,
{ "Application Protocol Id", "lldp.dcbx.feature.app.proto", FT_UINT16, BASE_HEX,
NULL, 0, NULL, HFILL }
},
{ &hf_dcbx_feature_app_selector,
{ "Selector Field", "lldp.dcbx.feature.app.sf", FT_UINT24, BASE_DEC,
VALS(dcbx_app_selector), 0x3 << 16, NULL, HFILL }
},
{ &hf_dcbx_feature_app_oui,
{ "Application OUI", "lldp.dcbx.feature.app.oui", FT_UINT24, BASE_HEX,
NULL, ~(0x3 << 16), NULL, HFILL }
},
{ &hf_dcbx_feature_app_prio,
{ "Application Priority", "lldp.dcbx.feature.app.prio", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_dcbx_feature_flag_llink_type,
{ "Logical Link Down Type", "lldp.dcbx.feature.llink.type", FT_UINT8, BASE_HEX,
VALS(dcbx_llink_types), 0x80, NULL, HFILL }
},
{ &hf_ieee_802_1_subtype,
{ "IEEE 802.1 Subtype", "lldp.ieee.802_1.subtype", FT_UINT8, BASE_HEX,
VALS(ieee_802_1_subtypes), 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_port_and_vlan_id_flag,
{ "Flags", "lldp.ieee.802_1.port_and_vlan_id_flag", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_port_and_vlan_id_flag_supported,
{ "Port and Protocol VLAN", "lldp.ieee.802_1.port_and_vlan_id_flag.supported", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }
},
{ &hf_ieee_802_1_port_and_vlan_id_flag_enabled,
{ "Port and Protocol VLAN", "lldp.ieee.802_1.port_and_vlan_id_flag.enabled", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }
},
{ &hf_ieee_802_1_port_vlan_id,
{ "Port VLAN Identifier", "lldp.ieee.802_1.port_vlan.id", FT_UINT16, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_port_proto_vlan_id,
{ "Port and Protocol VLAN Identifier", "lldp.ieee.802_1.port_proto_vlan.id", FT_UINT16, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_vlan_id,
{ "VLAN Identifier", "lldp.ieee.802_1.vlan.id", FT_UINT16, BASE_DEC_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_vlan_name_length,
{ "VLAN Name Length", "lldp.ieee.802_1.vlan.name_len", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_vlan_name,
{ "VLAN Name", "lldp.ieee.802_1.vlan.name", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_proto_id_length,
{ "Protocol Identity Length", "lldp.ieee.802_1.proto.id_length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1_proto_id,
{ "Protocol Identity", "lldp.ieee.802_1.proto.id", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio0,
{ "Priority 0 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio0", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x01, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio1,
{ "Priority 1 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio1", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio2,
{ "Priority 2 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio2", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio3,
{ "Priority 3 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio3", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x08, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio4,
{ "Priority 4 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio4", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x10, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio5,
{ "Priority 5 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio5", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x20, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio6,
{ "Priority 6 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio6", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x40, NULL, HFILL }
},
{ &hf_ieee_8021qau_cnpv_prio7,
{ "Priority 7 CNPV Capability", "lldp.ieee.802_1qau.cnpv.prio7", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x80, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio0,
{ "Priority 0 Ready Indicator", "lldp.ieee.802_1qau.ready.prio0", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x01, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio1,
{ "Priority 1 Ready Indicator", "lldp.ieee.802_1qau.ready.prio1", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x02, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio2,
{ "Priority 2 Ready Indicator", "lldp.ieee.802_1qau.ready.prio2", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x04, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio3,
{ "Priority 3 Ready Indicator", "lldp.ieee.802_1qau.ready.prio3", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x08, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio4,
{ "Priority 4 Ready Indicator", "lldp.ieee.802_1qau.ready.prio4", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x10, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio5,
{ "Priority 5 Ready Indicator", "lldp.ieee.802_1qau.ready.prio5", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x20, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio6,
{ "Priority 6 Ready Indicator", "lldp.ieee.802_1qau.ready.prio6", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x40, NULL, HFILL }
},
{ &hf_ieee_8021qau_ready_prio7,
{ "Priority 7 Ready Indicator", "lldp.ieee.802_1qau.ready.prio7", FT_BOOLEAN, 8,
TFS(&tfs_set_notset), 0x80, NULL, HFILL }
},
{ &hf_ieee_8021az_feature_flag_willing,
{ "Willing", "lldp.dcbx.ieee.willing", FT_BOOLEAN , 8,
TFS(&tfs_yes_no), 0x80, NULL, HFILL }
},
{ &hf_ieee_8021az_feature_flag_cbs,
{ "Credit-Based Shaper", "lldp.dcbx.ieee.ets.cbs", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x40, NULL, HFILL }
},
{ &hf_ieee_8021az_maxtcs,
{ "Maximum Number of Traffic Classes", "lldp.dcbx.ieee.ets.maxtcs", FT_UINT8, BASE_DEC,
NULL, 0x7, NULL, HFILL }
},
{ &hf_ieee_8021az_tsa_class0,
{ "TSA for Traffic Class 0", "lldp.dcbx.ieee.ets.tsa0", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class1,
{ "TSA for Traffic Class 1", "lldp.dcbx.ieee.ets.tsa1", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class2,
{ "TSA for Traffic Class 2", "lldp.dcbx.ieee.ets.tsa2", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class3,
{ "TSA for Traffic Class 3", "lldp.dcbx.ieee.ets.tsa3", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class4,
{ "TSA for Traffic Class 4", "lldp.dcbx.ieee.ets.tsa4", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class5,
{ "TSA for Traffic Class 5", "lldp.dcbx.ieee.ets.tsa5", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class6,
{ "TSA for Traffic Class 6", "lldp.dcbx.ieee.ets.tsa6", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_tsa_class7,
{ "TSA for Traffic Class 7", "lldp.dcbx.ieee.ets.tsa7", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_tsa), 0, "Reserved", HFILL }
},
{ &hf_ieee_8021az_feature_flag_mbc,
{ "MACsec Bypass Capability", "lldp.dcbx.ieee.pfc.mbc", FT_BOOLEAN, 8,
TFS(&tfs_capable_not_capable), 0x40, NULL, HFILL }
},
{ &hf_ieee_8021az_pfc_numtcs,
{ "Max PFC Enabled Traffic Classes", "lldp.dcbx.ieee.pfc.numtcs", FT_UINT8, BASE_DEC,
NULL, 0xF, NULL, HFILL }
},
{ &hf_ieee_8021az_app_reserved,
{ "Reserved", "lldp.dcbx.ieee.app.reserved", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_8021az_app_prio,
{ "Application Priority", "lldp.dcbx.ieee.app.prio", FT_UINT8, BASE_DEC,
NULL, 0xE0, NULL, HFILL }
},
{ &hf_ieee_8021az_app_selector,
{ "Application Selector", "lldp.dcbx.iee.app.sf", FT_UINT8, BASE_DEC,
VALS(dcbx_ieee_8021az_sf), 0x7, NULL, HFILL }
},
{ &hf_ieee_802_3_subtype,
{ "IEEE 802.3 Subtype", "lldp.ieee.802_3.subtype", FT_UINT8, BASE_HEX,
VALS(ieee_802_3_subtypes), 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_mac_phy_auto_neg_status,
{ "Auto-Negotiation Support/Status", "lldp.ieee.802_3.mac_phy_auto_neg_status", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_mac_phy_auto_neg_status_supported,
{ "Auto-Negotiation", "lldp.ieee.802_3.mac_phy_auto_neg_status.supported", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }
},
{ &hf_ieee_802_3_mac_phy_auto_neg_status_enabled,
{ "Auto-Negotiation", "lldp.ieee.802_3.mac_phy_auto_neg_status.enabled", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps,
{ "PMD Auto-Negotiation Advertised Capability", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_tfd,
{ "1000BASE-T (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.1000base_tfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_1000BASE_TFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_t,
{ "1000BASE-T (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.1000base_t", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_1000BASE_T, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_xfd,
{ "1000BASE-X (-LX, -SX, -CX full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.1000base_xfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_1000BASE_XFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_1000base_x,
{ "1000BASE-X (-LX, -SX, -CX half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.1000base_x", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_1000BASE_X, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_bpause,
{ "Asymmetric and Symmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.fdx_bpause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_FDX_BPAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_spause,
{ "Symmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.fdx_spause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_FDX_SPAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_apause,
{ "Asymmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.fdx_apause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_FDX_APAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_fdx_pause,
{ "PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.fdx_pause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_FDX_PAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t2fd,
{ "100BASE-T2 (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.100base_t2fd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_100BASE_T2FD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t2,
{ "100BASE-T2 (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.100base_t2", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_100BASE_T2, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_txfd,
{ "100BASE-TX (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.100base_txfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_100BASE_TXFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_tx,
{ "100BASE-TX (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.100base_tx", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_100BASE_TX, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_100base_t4,
{ "100BASE-T4", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.100base_t4", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_100BASE_T4, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_10base_tfd,
{ "10BASE-T (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.10base_tfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_10BASET_FD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_10base_t,
{ "10BASE-T (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.10base_t", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_10BASE_T, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_other,
{ "Other or unknown", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps.other", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), AUTONEG_OTHER, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_tfd,
{ "1000BASE-T (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.1000base_tfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_1000BASE_TFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_t,
{ "1000BASE-T (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.1000base_t", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_1000BASE_T, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_xfd,
{ "1000BASE-X (-LX, -SX, -CX full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.1000base_xfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_1000BASE_XFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_1000base_x,
{ "1000BASE-X (-LX, -SX, -CX half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.1000base_x", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_1000BASE_X, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_bpause,
{ "Asymmetric and Symmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.fdx_bpause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_FDX_BPAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_spause,
{ "Symmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.fdx_spause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_FDX_SPAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_apause,
{ "Asymmetric PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.fdx_apause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_FDX_APAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_fdx_pause,
{ "PAUSE (for full-duplex links)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.fdx_pause", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_FDX_PAUSE, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t2fd,
{ "100BASE-T2 (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.100base_t2fd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_100BASE_T2FD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t2,
{ "100BASE-T2 (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.100base_t2", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_100BASE_T2, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_txfd,
{ "100BASE-TX (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.100base_txfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_100BASE_TXFD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_tx,
{ "100BASE-TX (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.100base_tx", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_100BASE_TX, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_100base_t4,
{ "100BASE-T4", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.100base_t4", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_100BASE_T4, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_10base_tfd,
{ "10BASE-T (full duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.10base_tfd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_10BASET_FD, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_10base_t,
{ "10BASE-T (half duplex mode)", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.10base_t", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_10BASE_T, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_auto_neg_advertised_caps_inv_other,
{ "Other or unknown", "lldp.ieee.802_3.pmd_auto_neg_advertised_caps_inv.other", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), INV_AUTONEG_OTHER, NULL, HFILL }
},
{ &hf_ieee_802_3_pmd_mau_type,
{ "Operational MAU Type", "lldp.ieee.802_3.pmd_mau_type", FT_UINT16, BASE_HEX,
VALS(operational_mau_type_values), 0x0, "Unknown", HFILL }
},
{ &hf_ieee_802_3_mdi_power_support,
{ "MDI Power Support", "lldp.ieee.802_3.mdi_power_support", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_support_port_class,
{ "Port Class", "lldp.ieee.802_3.mdi_power_support.port_class", FT_BOOLEAN, 8,
TFS(&tfs_ieee_802_3_pse_pd), 0x01, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_support_pse_power_support,
{ "PSE MDI Power", "lldp.ieee.802_3.mdi_power_support.supported", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x02, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_support_pse_power_enabled,
{ "PSE MDI Power", "lldp.ieee.802_3.mdi_power_support.enabled", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x04, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_support_pse_pairs,
{ "PSE Pairs Control Ability", "lldp.ieee.802_3.mdi_power_support.pse_pairs", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x08, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_pse_pair,
{ "PSE Power Pair", "lldp.ieee.802_3.mdi_pse_pair", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_class,
{ "Power Class", "lldp.ieee.802_3.mdi_power_class", FT_UINT8, BASE_DEC,
VALS(power_class_802_3), 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_type,
{ "Power Type", "lldp.ieee.802_3.mdi_power_type", FT_UINT8, BASE_DEC,
VALS(power_type_802_3), 0xC0, "Unknown", HFILL }
},
{ &hf_ieee_802_3_mdi_power_source,
{ "Power Source", "lldp.ieee.802_3.mdi_power_source", FT_UINT8, BASE_DEC,
NULL, 0x30, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_power_priority,
{ "Power Priority", "lldp.ieee.802_3.mdi_power_priority", FT_UINT8, BASE_DEC,
VALS(media_power_priority), 0x0F, "Reserved", HFILL }
},
{ &hf_ieee_802_3_mdi_requested_power,
{ "PD Requested Power Value", "lldp.ieee.802_3.mdi_pde_requested", FT_UINT16, BASE_CUSTOM,
CF_FUNC(mdi_power_base), 0, NULL, HFILL }
},
{ &hf_ieee_802_3_mdi_allocated_power,
{ "PSE Allocated Power Value", "lldp.ieee.802_3.mdi_pse_allocated", FT_UINT16, BASE_CUSTOM,
CF_FUNC(mdi_power_base), 0, NULL, HFILL }
},
{ &hf_ieee_802_3_aggregation_status,
{ "Aggregation Status", "lldp.ieee.802_3.aggregation_status", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_3_aggregation_status_cap,
{ "Aggregation Capability", "lldp.ieee.802_3.aggregation_status.cap", FT_BOOLEAN, 8,
TFS(&tfs_yes_no), 0x01, NULL, HFILL }
},
{ &hf_ieee_802_3_aggregation_status_enabled,
{ "Aggregation Status", "lldp.ieee.802_3.aggregation_status.enabled", FT_BOOLEAN, 8,
TFS(&tfs_enabled_disabled), 0x02, NULL, HFILL }
},
{ &hf_ieee_802_3_aggregated_port_id,
{ "Aggregated Port Id", "lldp.ieee.802_3.aggregated_port_id", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_ieee_802_3_max_frame_size,
{ "Maximum Frame Size", "lldp.ieee.802_3.max_frame_size", FT_UINT16, BASE_DEC,
NULL, 0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_subtype,
{ "IEEE 802.1Qbg Subtype", "lldp.ieee.802_1qbg.subtype", FT_UINT8, BASE_HEX,
VALS(ieee_802_1qbg_subtypes), 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps,
{ "Supported capabilities", "lldp.ieee.802_1qbg.evb_support_caps", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps_std,
{ "Standard bridging (STD)", "lldp.ieee.802_1qbg.evb_support_caps.std", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_STD, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps_rr,
{ "Reflective relay (RR)", "lldp.ieee.802_1qbg.evb_support_caps.rr", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_RR, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps_rte,
{ "Retransmission timer exponent (RTE)", "lldp.ieee.802_1qbg.evb_support_caps.rte", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_RTE, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps_ecp,
{ "Edge control protocol (ECP)", "lldp.ieee.802_1qbg.evb_support_caps.ecp", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_ECP, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_support_caps_vdp,
{ "VSI discovery protocol (VDP)", "lldp.ieee.802_1qbg.evb_support_caps.vdp", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_VDP, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps,
{ "Configured capabilities", "lldp.ieee.802_1qbg.evb_configure_caps", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps_std,
{ "Standard bridging (STD)", "lldp.ieee.802_1qbg.evb_configure_caps.std", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_STD, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps_rr,
{ "Reflective relay (RR)", "lldp.ieee.802_1qbg.evb_configure_caps.rr", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_RR, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps_rte,
{ "Retransmission timer exponent (RTE)", "lldp.ieee.802_1qbg.evb_configure_caps.rte", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_RTE, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps_ecp,
{ "Edge control protocol (ECP)", "lldp.ieee.802_1qbg.evb_configure_caps.ecp", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_ECP, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configure_caps_vdp,
{ "VSI discovery protocol (VDP)", "lldp.ieee.802_1qbg.evb_configure_caps.vdp", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), EVB_CAPA_VDP, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_supported_vsi,
{ "Supported No of VSIs", "lldp.ieee.802_1qbg.evb_supported_vsi", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_configured_vsi,
{ "Configured No of VSIs", "lldp.ieee.802_1qbg.evb_configured_vsi", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_ieee_802_1qbg_evb_retrans_timer,
{ "Retransmission timer exponent", "lldp.ieee.802_1qbg.evb_retrans_timer", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_tlv_subtype,
{ "Media Subtype", "lldp.media.subtype", FT_UINT8, BASE_HEX,
VALS(media_subtypes), 0x0, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps,
{ "Capabilities", "lldp.media.subtype.caps", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_llpd,
{ "LLDP-MED Capabilities", "lldp.media.subtype.caps.llpd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_LLDP, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_network_policy,
{ "Network Policy", "lldp.media.subtype.caps.network_policy", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_NETWORK_POLICY, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_location_id,
{ "Location Identification", "lldp.media.subtype.caps.location_id", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_LOCATION_ID, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_mdi_pse,
{ "Extended Power via MDI-PSE", "lldp.media.subtype.caps.mdi_pse", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_MDI_PSE, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_mid_pd,
{ "Extended Power via MDI-PD", "lldp.media.subtype.caps.mid_pd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_MDI_PD, NULL, HFILL }
},
{ &hf_media_tlv_subtype_caps_inventory,
{ "Inventory", "lldp.media.subtype.caps.inventory", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), MEDIA_CAPABILITY_INVENTORY, NULL, HFILL }
},
{ &hf_media_tlv_subtype_class,
{ "Class Type", "lldp.media.subtype.class", FT_UINT8, BASE_DEC,
VALS(media_class_values), 0x0, "Unknown", HFILL }
},
{ &hf_media_application_type,
{ "Application Type", "lldp.media.app_type", FT_UINT8, BASE_DEC,
VALS(media_application_type), 0x0, "Unknown", HFILL }
},
{ &hf_media_policy_flag,
{ "Policy", "lldp.media.policy_flag", FT_BOOLEAN, 24,
TFS(&tfs_unknown_defined), 0x800000, NULL, HFILL }
},
{ &hf_media_tag_flag,
{ "Tagged", "lldp.media.tag_flag", FT_BOOLEAN, 24,
TFS(&tfs_yes_no), 0x400000, NULL, HFILL }
},
{ &hf_media_vlan_id,
{ "VLAN Id", "lldp.media.vlan_id", FT_UINT24, BASE_DEC,
NULL, 0x1FFE00, NULL, HFILL }
},
{ &hf_media_l2_prio,
{ "L2 Priority", "lldp.media.l2_prio", FT_UINT24, BASE_DEC,
NULL, 0x1C0, NULL, HFILL }
},
{ &hf_media_dscp,
{ "DSCP Priority", "lldp.media.dscp", FT_UINT24, BASE_DEC,
NULL, 0x3F, NULL, HFILL }
},
{ &hf_media_loc_data_format,
{ "Location Data Format", "lldp.media.loc.data_format", FT_UINT8, BASE_DEC,
VALS(location_data_format), 0x0, NULL, HFILL }
},
{ &hf_media_loc_lat_resolution,
{ "Latitude Resolution", "lldp.media.loc.lat_resolution", FT_UINT8, BASE_DEC,
NULL, 0xFC, NULL, HFILL }
},
{ &hf_media_loc_lat,
{ "Latitude", "lldp.media.loc.latitude", FT_UINT40, BASE_CUSTOM,
CF_FUNC(latitude_base), 0x0, NULL, HFILL }
},
{ &hf_media_loc_long_resolution,
{ "Longitude Resolution", "lldp.media.loc.long_resolution", FT_UINT8, BASE_DEC,
NULL, 0xFC, NULL, HFILL }
},
{ &hf_media_loc_long,
{ "Longitude", "lldp.media.loc.longitude", FT_UINT40, BASE_CUSTOM,
CF_FUNC(longitude_base), 0x0, NULL, HFILL }
},
{ &hf_media_loc_alt_type,
{ "Altitude Type", "lldp.media.loc.alt_type", FT_UINT8, BASE_DEC,
VALS(altitude_type), 0xF0, "Unknown", HFILL }
},
{ &hf_media_loc_alt_resolution,
{ "Altitude Resolution", "lldp.media.loc.alt_resolution", FT_UINT16, BASE_DEC,
NULL, 0x0FC0, NULL, HFILL }
},
{ &hf_media_loc_alt,
{ "Altitude", "lldp.media.loc.altitude", FT_UINT32, BASE_DEC,
NULL, 0x03FFFFFFF, NULL, HFILL }
},
{ &hf_media_loc_datum,
{ "Datum", "lldp.media.loc.datum", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_civic_lci_length,
{ "LCI Length", "lldp.media.civic.lenth", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_civic_what,
{ "What", "lldp.media.civic.what", FT_UINT8, BASE_DEC,
VALS(civic_address_what_values), 0x0, "Unknown", HFILL }
},
{ &hf_media_civic_country,
{ "Country", "lldp.media.civic.country", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_civic_addr_type,
{ "CA Type", "lldp.media.civic.type", FT_UINT8, BASE_DEC,
VALS(civic_address_type_values), 0x0, "Unknown", HFILL }
},
{ &hf_media_civic_addr_len,
{ "CA Length", "lldp.media.civic.length", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_civic_addr_value,
{ "CA Value", "lldp.media.civic.value", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_ecs,
{ "ELIN", "lldp.media.ecs", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_power_type,
{ "Power Type", "lldp.media.power.type", FT_UINT8, BASE_DEC,
VALS(media_power_type), 0xC0, "Unknown", HFILL }
},
{ &hf_media_power_source,
{ "Power Source", "lldp.media.power.source", FT_UINT8, BASE_DEC,
NULL, 0x30, NULL, HFILL }
},
{ &hf_media_power_priority,
{ "Power Priority", "lldp.media.power.prio", FT_UINT8, BASE_DEC,
VALS(media_power_priority), 0x0F, "Reserved", HFILL }
},
{ &hf_media_power_value,
{ "Power Value", "lldp.media.power.value", FT_UINT16, BASE_CUSTOM,
CF_FUNC(media_power_base), 0x0, NULL, HFILL }
},
{ &hf_media_hardware,
{ "Hardware Revision", "lldp.media.hardware", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_firmware,
{ "Firmware Revision", "lldp.media.firmware", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_software,
{ "Software Revision", "lldp.media.software", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_sn,
{ "Serial Number", "lldp.media.sn", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_manufacturer,
{ "Manufacturer Name", "lldp.media.manufacturer", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_model,
{ "Model Name", "lldp.media.model", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_media_asset,
{ "Asset ID", "lldp.media.asset", FT_STRINGZPAD, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_tlv_subtype,
{ "Subtype", "lldp.profinet.subtype", FT_UINT8, BASE_HEX,
VALS(profinet_subtypes), 0x0, "PROFINET Subtype", HFILL }
},
{ &hf_profinet_port_rx_delay_local,
{ "Port RX Delay Local", "lldp.profinet.port_rx_delay_local", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_port_rx_delay_remote,
{ "Port RX Delay Remote", "lldp.profinet.port_rx_delay_remote", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_port_tx_delay_local,
{ "Port TX Delay Local", "lldp.profinet.port_tx_delay_local", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_port_tx_delay_remote,
{ "Port TX Delay Remote", "lldp.profinet.port_tx_delay_remote", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_cable_delay_local,
{ "Port Cable Delay Local", "lldp.profinet.cable_delay_local", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_class2_port_status,
{ "RTClass2 Port Status", "lldp.profinet.rtc2_port_status", FT_UINT16, BASE_HEX,
VALS(profinet_port2_status_vals), 0x0, NULL, HFILL }
},
{ &hf_profinet_class3_port_status,
{ "RTClass3 Port Status", "lldp.profinet.rtc3_port_status", FT_UINT16, BASE_HEX,
VALS(profinet_port3_status_vals), 0x07, NULL, HFILL }
},
{ &hf_profinet_class3_port_status_Fragmentation,
{ "RTClass3_PortStatus.Fragmentation", "lldp.profinet.rtc3_port_status.fragmentation", FT_UINT16, BASE_HEX,
VALS(profinet_port3_status_OnOff), 0x1000, NULL, HFILL }
},
{ &hf_profinet_class3_port_status_reserved,
{ "RTClass3_PortStatus.reserved", "lldp.profinet.rtc3_port_status.reserved", FT_UINT16, BASE_HEX,
NULL, 0x0FF8, "reserved", HFILL }
},
{ &hf_profinet_class3_port_status_PreambleLength,
{ "RTClass3_PortStatus.PreambleLength", "lldp.profinet.rtc3_port_status.preambleLength", FT_UINT16, BASE_HEX,
VALS(profinet_port3_status_PreambleLength), 0x2000, NULL, HFILL }
},
{ &hf_profinet_mrp_domain_uuid,
{ "MRP DomainUUID", "lldp.profinet.mrp_domain_uuid", FT_GUID, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_mrrt_port_status,
{ "MRRT PortStatus", "lldp.profinet.mrrt_port_status", FT_UINT16, BASE_HEX,
VALS(profinet_mrrt_port_status_vals), 0x0, NULL, HFILL }
},
{ &hf_profinet_cm_mac,
{ "CMMacAdd", "lldp.profinet.cm_mac_add", FT_ETHER, BASE_NONE,
NULL, 0x0, "CMResponderMacAdd or CMInitiatorMacAdd", HFILL }
},
{ &hf_profinet_master_source_address,
{ "MasterSourceAddress", "lldp.profinet.master_source_address", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_subdomain_uuid,
{ "SubdomainUUID", "lldp.profinet.subdomain_uuid", FT_GUID, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_ir_data_uuid,
{ "IRDataUUID", "lldp.profinet.ir_data_uuid", FT_GUID, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_profinet_length_of_period_valid,
{ "LengthOfPeriod.Valid", "lldp.profinet.length_of_period_valid", FT_UINT32, BASE_DEC,
NULL, 0x80000000, "Length field is valid/invalid", HFILL }
},
{ &hf_profinet_length_of_period_length,
{ "LengthOfPeriod.Length", "lldp.profinet.length_of_period_length", FT_UINT32, BASE_DEC,
NULL, 0x7FFFFFFF, "Duration of a cycle in nanoseconds", HFILL }
},
{ &hf_profinet_red_period_begin_valid,
{ "RedPeriodBegin.Valid", "lldp.profinet.red_period_begin_valid", FT_UINT32, BASE_DEC,
NULL, 0x80000000, "Offset field is valid/invalid", HFILL }
},
{ &hf_profinet_red_period_begin_offset,
{ "RedPeriodBegin.Offset", "lldp.profinet.red_period_begin_offset", FT_UINT32, BASE_DEC,
NULL, 0x7FFFFFFF, "RT_CLASS_3 period, offset to cycle begin in nanoseconds", HFILL }
},
{ &hf_profinet_orange_period_begin_valid,
{ "OrangePeriodBegin.Valid", "lldp.profinet.orange_period_begin_valid", FT_UINT32, BASE_DEC,
NULL, 0x80000000, "Offset field is valid/invalid", HFILL }
},
{ &hf_profinet_orange_period_begin_offset,
{ "OrangePeriodBegin.Offset","lldp.profinet.orange_period_begin_offset", FT_UINT32, BASE_DEC,
NULL, 0x7FFFFFFF, "RT_CLASS_2 period, offset to cycle begin in nanoseconds", HFILL }
},
{ &hf_profinet_green_period_begin_valid,
{ "GreenPeriodBegin.Valid", "lldp.profinet.green_period_begin_valid", FT_UINT32, BASE_DEC,
NULL, 0x80000000, "Offset field is valid/invalid", HFILL }
},
{ &hf_profinet_green_period_begin_offset,
{ "GreenPeriodBegin.Offset", "lldp.profinet.green_period_begin_offset", FT_UINT32, BASE_DEC,
NULL, 0x7FFFFFFF, "Unrestricted period, offset to cycle begin in nanoseconds", HFILL }
},
{ &hf_cisco_subtype,
{ "Cisco Subtype", "lldp.cisco.subtype", FT_UINT8, BASE_HEX,
VALS(cisco_subtypes), 0x0, NULL, HFILL }
},
{ &hf_cisco_four_wire_power,
{ "Four-Wire Power-via-MDI", "lldp.cisco.four_wire_power", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }
},
{ &hf_cisco_four_wire_power_poe,
{ "PSE Four-Wire PoE", "lldp.cisco.four_wire_power.poe", FT_BOOLEAN, 8,
TFS(&tfs_supported_not_supported), 0x01, NULL, HFILL }
},
{ &hf_cisco_four_wire_power_spare_pair_arch,
{ "PD Spare Pair Architecture", "lldp.cisco.four_wire_power.spare_pair_arch", FT_BOOLEAN, 8,
TFS(&tfs_shared_independent), 0x02, NULL, HFILL }
},
{ &hf_cisco_four_wire_power_req_spare_pair_poe,
{ "PD Request Spare Pair PoE", "lldp.cisco.four_wire_power.req_spare_pair_poe", FT_BOOLEAN, 8,
TFS(&tfs_on_off), 0x04, NULL, HFILL }
},
{ &hf_cisco_four_wire_power_pse_spare_pair_poe,
{ "PSE Spare Pair PoE", "lldp.cisco.four_wire_power.pse_spare_pair_poe", FT_BOOLEAN, 8,
TFS(&tfs_on_off), 0x08, NULL, HFILL }
},
{ &hf_hytec_tlv_subtype,
{ "Hytec Subtype", "lldp.hytec.tlv_subtype", FT_UINT8, BASE_DEC,
VALS(hytec_subtypes), 0x0, NULL, HFILL }
},
{ &hf_hytec_group,
{ "Group", "lldp.hytec.group", FT_UINT8, BASE_DEC,
NULL, HYTEC_GROUP_MASK, NULL, HFILL }
},
{ &hf_hytec_identifier,
{ "Identifier", "lldp.hytec.identifier", FT_UINT8, BASE_DEC,
NULL, HYTEC_IDENTIFIER_MASK, NULL, HFILL }
},
{ &hf_hytec_transceiver_vendor_product_revision,
{ HYTEC_TID__VENDOR_PRODUCT_REVISION_STR, "lldp.hytec.transceiver_vendor_product_revision", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_hytec_single_mode,
{ HYTEC_TBD__SINGLE_MODE_STR, "lldp.hytec.single_mode", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_multi_mode_50,
{ HYTEC_TBD__MULTI_MODE_50_STR, "lldp.hytec.multi_mode_50", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_multi_mode_62_5,
{ HYTEC_TBD__MULTI_MODE_62_5_STR, "lldp.hytec.multi_mode_62_5", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_tx_current_output_power,
{ HYTEC_MD__TX_CURRENT_OUTPUT_POWER_STR, "lldp.hytec.tx_current_output_power", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_rx_current_input_power,
{ HYTEC_MD__RX_CURRENT_INPUT_POWER_STR, "lldp.hytec.rx_current_input_power", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_rx_input_snr,
{ HYTEC_MD__RX_INPUT_SNR_STR, "lldp.hytec.rx_input_snr", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_lineloss,
{ HYTEC_MD__LINELOSS_STR, "lldp.hytec.lineloss", FT_FLOAT, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_mac_trace_request,
{ HYTEC_MC__MAC_TRACE_REQUEST_STR, "lldp.hytec.mac_trace_request", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_trace_mac_address,
{ "Trace MAC address", "lldp.hytec.trace_mac_address", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_request_mac_address,
{ "Requester's MAC address", "lldp.hytec.requesters_mac_address", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_maximum_depth,
{ "Maximum depth", "lldp.hytec.maximum_depth", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_mac_trace_reply,
{ HYTEC_MC__MAC_TRACE_REPLY_STR, "lldp.hytec.mac_trace_reply", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_answering_mac_address,
{ "Answering MAC address", "lldp.hytec.answering_mac_address", FT_ETHER, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_actual_depth,
{ "Actual depth", "lldp.hytec.actual_depth", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_name_of_replying_device,
{ HYTEC_MC__NAME_OF_REPLYING_DEVICE_STR, "lldp.hytec.name_of_replying_device", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_outgoing_port_name,
{ HYTEC_MC__OUTGOING_PORT_NAME_STR, "lldp.hytec.outgoing_port_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_ipv4_address_of_replying_device,
{ HYTEC_MC__IPV4_ADDRESS_OF_REPLYING_DEVICE_STR, "lldp.hytec.ipv4_address_of_replying_device", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_end_of_trace,
{ HYTEC_MC__END_OF_TRACE_STR, "lldp.hytec.end_of_trace", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_ipv6_address_of_replying_device,
{ HYTEC_MC__IPV6_ADDRESS_OF_REPLYING_DEVICE_STR, "lldp.hytec.ipv6_address_of_replying_device", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_incoming_port_name,
{ HYTEC_MC__INCOMING_PORT_NAME_STR, "lldp.hytec.incoming_port_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_trace_identifier,
{ HYTEC_MC__TRACE_IDENTIFIER_STR, "lldp.hytec.trace_identifier", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}
},
{ &hf_hytec_invalid_object_data,
{ "Invalid object data", "lldp.hytec.invalid_object_data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_hytec_unknown_identifier_content,
{ "Unknown Identifier Content","lldp.hytec.unknown_identifier_content", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
{ &hf_unknown_subtype,
{ "Unknown Subtype","lldp.unknown_subtype", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }
},
{ &hf_unknown_subtype_content,
{ "Unknown Subtype Content","lldp.unknown_subtype.content", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }
},
};
static gint *ett[] = {
&ett_lldp,
&ett_chassis_id,
&ett_port_id,
&ett_time_to_live,
&ett_end_of_lldpdu,
&ett_port_description,
&ett_system_name,
&ett_system_desc,
&ett_system_cap,
&ett_system_cap_summary,
&ett_system_cap_enabled,
&ett_management_address,
&ett_unknown_tlv,
&ett_org_spc_tlv,
&ett_org_spc_def,
&ett_org_spc_dcbx_cin,
&ett_org_spc_dcbx_cee,
&ett_org_spc_dcbx_cee_1,
&ett_org_spc_dcbx_cee_2,
&ett_org_spc_dcbx_cee_3,
&ett_org_spc_dcbx_cee_4,
&ett_org_spc_dcbx_cin_6,
&ett_org_spc_dcbx_cee_app,
&ett_org_spc_ieee_802_1_1,
&ett_org_spc_ieee_802_1_2,
&ett_org_spc_ieee_802_1_3,
&ett_org_spc_ieee_802_1_4,
&ett_org_spc_ieee_802_1_8,
&ett_org_spc_ieee_802_1_9,
&ett_org_spc_ieee_802_1_a,
&ett_org_spc_ieee_802_1_b,
&ett_org_spc_ieee_802_1_c,
&ett_org_spc_ieee_dcbx_app,
&ett_org_spc_ieee_802_3_1,
&ett_org_spc_ieee_802_3_2,
&ett_org_spc_ieee_802_3_3,
&ett_org_spc_ieee_802_3_4,
&ett_org_spc_media_1,
&ett_org_spc_media_2,
&ett_org_spc_media_3,
&ett_org_spc_media_4,
&ett_org_spc_media_5,
&ett_org_spc_media_6,
&ett_org_spc_media_7,
&ett_org_spc_media_8,
&ett_org_spc_media_9,
&ett_org_spc_media_10,
&ett_org_spc_media_11,
&ett_org_spc_ProfinetSubTypes_1,
&ett_org_spc_ProfinetSubTypes_2,
&ett_org_spc_ProfinetSubTypes_3,
&ett_org_spc_ProfinetSubTypes_4,
&ett_org_spc_ProfinetSubTypes_5,
&ett_org_spc_ProfinetSubTypes_6,
&ett_port_vlan_flags,
&ett_802_3_flags,
&ett_802_3_autoneg_advertised,
&ett_802_3_power,
&ett_802_3_aggregation,
&ett_802_1qbg_capabilities_flags,
&ett_media_capabilities,
&ett_profinet_period,
&ett_cisco_fourwire_tlv,
&ett_org_spc_hytec_subtype_transceiver,
&ett_org_spc_hytec_subtype_trace,
&ett_org_spc_hytec_trace_request,
&ett_org_spc_hytec_trace_reply
};
static ei_register_info ei[] = {
{ &ei_lldp_bad_length, { "lldp.incorrect_length", PI_MALFORMED, PI_WARN, "Invalid length, too short", EXPFILL }},
{ &ei_lldp_bad_length_excess, { "lldp.excess_length", PI_MALFORMED, PI_WARN, "Invalid length, greater than expected", EXPFILL }},
{ &ei_lldp_bad_type, { "lldp.bad_type", PI_MALFORMED, PI_WARN, "Incorrect type", EXPFILL }},
};
proto_lldp = proto_register_protocol("Link Layer Discovery Protocol", "LLDP", "lldp");
proto_register_field_array(proto_lldp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
oui_unique_code_table = register_dissector_table("lldp.orgtlv.oui", "LLDP OUI", FT_UINT24, BASE_HEX );
expert_lldp = expert_register_protocol(proto_lldp);
expert_register_field_array(expert_lldp, ei, array_length(ei));
}
void
proto_reg_handoff_lldp(void)
{
dissector_handle_t lldp_handle;
lldp_handle = create_dissector_handle(dissect_lldp,proto_lldp);
dissector_add_uint("ethertype", ETHERTYPE_LLDP, lldp_handle);
}
