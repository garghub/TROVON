static guint
dissect_etv_bif_platform_ids(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_tree *platform_tree;
proto_item *pi;
pi = proto_tree_add_text(tree, tvb, offset, 15, "Platform Id");
platform_tree = proto_item_add_subtree(pi, ett_eiss_platform_id);
proto_tree_add_item(platform_tree, hf_pdtHWManufacturer, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(platform_tree, hf_pdtHWModel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(platform_tree, hf_pdtHWVersionMajor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(platform_tree, hf_pdtHWVersionMinor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(platform_tree, hf_pdtSWManufacturer, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(platform_tree, hf_pdtSWModel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(platform_tree, hf_pdtSWVersionMajor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(platform_tree, hf_pdtSWVersionMinor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(platform_tree, hf_pdtProfile, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return 15;
}
static guint
dissect_eiss_descriptors(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset)
{
proto_item *pi;
proto_tree *sub_tree;
guint tag;
tag = tvb_get_guint8(tvb, offset);
if (0xe0 == tag) {
guint total_length;
total_length = tvb_get_guint8(tvb, offset+1);
pi = proto_tree_add_text(tree, tvb, offset, (2+total_length),
"ETV Application Information Descriptor");
sub_tree = proto_item_add_subtree(pi, ett_eiss_desc);
proto_tree_add_item(sub_tree, hf_eiss_descriptor_tag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_descriptor_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_app_control_code, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_app_version_major, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_app_version_minor, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_max_proto_version_major,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_max_proto_version_minor,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_test_flag, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_aid_reserved, tvb, offset,
3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(sub_tree, hf_eiss_aid_priority, tvb, offset,
1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_irl_type, tvb, offset, 2,
ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eiss_irl_length, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_eiss_irl_string, tvb, offset, 2,
ENC_ASCII|ENC_NA);
return (2+total_length);
} else if (0xe1 == tag) {
pi = proto_tree_add_text(tree, tvb, offset, 6,
"ETV Media Time Descriptor");
sub_tree = proto_item_add_subtree(pi, ett_eiss_desc);
proto_tree_add_item(sub_tree, hf_eiss_descriptor_tag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_descriptor_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_mtd_time_value, tvb,
offset, 4, ENC_BIG_ENDIAN);
return 6;
} else if (0xe2 == tag) {
guint tmp;
tvbuff_t *payload;
tmp = tvb_get_ntohs(tvb, offset+1);
pi = proto_tree_add_text(tree, tvb, offset, (3+tmp),
"ETV Stream Event Descriptor");
sub_tree = proto_item_add_subtree(pi, ett_eiss_desc);
proto_tree_add_item(sub_tree, hf_eiss_descriptor_tag,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_eiss_sed_reserved, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_eiss_sed_descriptor_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_eiss_sed_time_value, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
payload = tvb_new_subset(tvb, offset, tmp-4, tmp-4);
call_dissector(data_handle, payload, pinfo, sub_tree);
return (3+tmp);
} else {
pi = proto_tree_add_text(tree, tvb, offset, -1,
"Unknown Descriptor");
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Unknown Descriptor");
return 1000;
}
}
static void
dissect_eiss(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint offset = 0, packet_length, sect_len;
proto_item *ti;
proto_item *pi;
proto_tree *eiss_tree;
proto_item *items[PACKET_MPEG_SECT_PI__SIZE];
gboolean ssi;
guint reserved;
guint8 reserved2;
guint8 sect_num, last_sect_num;
guint16 eiss_application_type;
guint8 platform_id_length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EISS");
ti = proto_tree_add_item(tree, proto_eiss, tvb, offset, -1, ENC_NA);
eiss_tree = proto_item_add_subtree(ti, ett_eiss);
offset += packet_mpeg_sect_header_extra(tvb, offset, eiss_tree, &sect_len,
&reserved, &ssi, items);
packet_length = sect_len + 3 - 4;
if (FALSE != ssi) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__SSI];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid section_syntax_indicator (should be 0)");
}
if (0 != reserved) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__RESERVED];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid reserved1 bits (should all be 0)");
}
if (1021 < sect_len) {
proto_item *msg_error;
msg_error = items[PACKET_MPEG_SECT_PI__LENGTH];
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info_format(pinfo, msg_error, PI_MALFORMED, PI_ERROR,
"Invalid section_length (must not exceed 1021)");
}
reserved2 = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(eiss_tree, hf_eiss_reserved2, tvb, offset, 1, ENC_BIG_ENDIAN);
if (0 != reserved2) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid reserved2 bits (should all be 0)");
}
offset++;
sect_num = tvb_get_guint8(tvb, offset);
last_sect_num = tvb_get_guint8(tvb, offset + 1);
pi = proto_tree_add_item(eiss_tree, hf_eiss_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
if (last_sect_num < sect_num) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid section_number (must be <= last_section_number)");
}
offset++;
proto_tree_add_item(eiss_tree, hf_eiss_last_section_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(eiss_tree, hf_eiss_protocol_version_major, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(eiss_tree, hf_eiss_protocol_version_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
eiss_application_type = tvb_get_ntohs(tvb, offset);
pi = proto_tree_add_item(eiss_tree, hf_eiss_application_type, tvb, offset, 2, ENC_BIG_ENDIAN);
if (8 != eiss_application_type) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid application_type (must be 0x0008)");
}
offset += 2;
proto_tree_add_item(eiss_tree, hf_eiss_organisation_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(eiss_tree, hf_eiss_application_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
platform_id_length = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(eiss_tree, hf_eiss_platform_id_length, tvb, offset, 1, ENC_BIG_ENDIAN);
if (0 != platform_id_length % 15) {
PROTO_ITEM_SET_GENERATED(pi);
expert_add_info_format(pinfo, pi, PI_MALFORMED, PI_ERROR,
"Invalid platform_id_length (must be a multiple of sizeof(etv_bif_platform_ids) == 15)");
}
offset++;
while (0 < platform_id_length) {
guint tmp;
tmp = dissect_etv_bif_platform_ids(tvb, eiss_tree, offset);
offset += tmp;
if (platform_id_length < tmp) {
platform_id_length = 0;
} else {
platform_id_length -= tmp;
}
}
if (0 < packet_length) {
proto_tree *eiss_desc_tree;
pi = proto_tree_add_text(eiss_tree, tvb, offset,
packet_length-offset,
"%s", "EISS Descriptor(s)");
eiss_desc_tree = proto_item_add_subtree(pi, ett_eiss_desc);
while (offset < packet_length) {
offset += dissect_eiss_descriptors(tvb, pinfo,
eiss_desc_tree, offset);
}
}
packet_mpeg_sect_crc(tvb, pinfo, eiss_tree, 0, sect_len - 1);
}
void
proto_register_eiss(void)
{
static hf_register_info hf[] = {
{ &hf_eiss_reserved2, {
"Reserved", "eiss.reserved",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_section_number, {
"Section Number", "eiss.sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_last_section_number, {
"Last Section Number", "eiss.last_sect_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_protocol_version_major, {
"Major Version Number", "eiss.version_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_protocol_version_minor, {
"Minor Version Number", "eiss.version_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_application_type, {
"Application Type", "eiss.app_type",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_organisation_id, {
"Organisation Id", "eiss.org_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_application_id, {
"Application Id", "eiss.app_id",
FT_UINT16, BASE_HEX|BASE_RANGE_STRING, RVALS(application_id_values), 0, NULL, HFILL
} },
{ &hf_eiss_platform_id_length, {
"Platform Id Length", "eiss.platform_id_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_pdtHWManufacturer, {
"Platform Hardware Manufacturer", "eiss.plat_hw_man",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtHWModel, {
"Platform Hardware Model", "eiss.plat_hw_model",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtHWVersionMajor, {
"Platform Hardware Major Version", "eiss.plat_hw_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtHWVersionMinor, {
"Platform Hardware Minor Version", "eiss.plat_hw_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtSWManufacturer, {
"Platform Software Manufacturer", "eiss.plat_sw_man",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtSWModel, {
"Platform Software Model", "eiss.plat_sw_model",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtSWVersionMajor, {
"Platform Software Major Version", "eiss.plat_sw_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtSWVersionMinor, {
"Platform Software Minor Version", "eiss.plat_sw_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_pdtProfile, {
"Platform Profile", "eiss.plat_profile",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_descriptor_tag, {
"EISS Descriptor Tag", "eiss.desc.tag",
FT_UINT8, BASE_HEX, VALS(eiss_descriptor_values), 0, NULL, HFILL
} },
{ &hf_eiss_descriptor_length, {
"Descriptor Length", "eiss.desc.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_app_control_code, {
"Application Control Code", "eiss.aid.app_control_code",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(aid_control_code_values), 0, NULL, HFILL
} },
{ &hf_eiss_aid_app_version_major, {
"Application Version Major", "eiss.aid.app_version_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_app_version_minor, {
"Application Version Minor", "eiss.aid.app_version_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_max_proto_version_major, {
"Max Protocol Version Major", "eiss.aid.max_proto_version_major",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_max_proto_version_minor, {
"Max Protocol Version Minor", "eiss.aid.max_proto_version_minor",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_test_flag, {
"Application Test Flag", "eiss.aid.test_flag",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_reserved, {
"Reserved", "eiss.aid.reserved",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_aid_priority, {
"Application Priority", "eiss.aid.priority",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_irl_type, {
"Initial Resource Locator Type", "eiss.aid.irl.type",
FT_UINT16, BASE_HEX, NULL, 0xfc00, NULL, HFILL
} },
{ &hf_eiss_irl_length, {
"Initial Resource Locator Length", "eiss.aid.irl.length",
FT_UINT16, BASE_DEC, NULL, 0x03ff, NULL, HFILL
} },
{ &hf_eiss_irl_string, {
"Initial Resource Locator String", "eiss.aid.irl.string",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_mtd_time_value, {
"Time Value (ms)", "eiss.mtd.time_value",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_eiss_sed_reserved, {
"Reserved", "eiss.sed.reserved",
FT_UINT16, BASE_DEC, NULL, 0xf000, NULL, HFILL
} },
{ &hf_eiss_sed_descriptor_length, {
"Descriptor Length", "eiss.desc.length",
FT_UINT16, BASE_DEC, NULL, 0x0fff, NULL, HFILL
} },
{ &hf_eiss_sed_time_value, {
"Time Value (ms)", "eiss.sed.time_value",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_eiss,
&ett_eiss_platform_id,
&ett_eiss_desc,
};
proto_eiss = proto_register_protocol("ETV-AM EISS Section", "ETV-AM EISS", "eiss");
proto_register_field_array(proto_eiss, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_eiss(void)
{
dissector_handle_t eiss_handle;
eiss_handle = create_dissector_handle(dissect_eiss, proto_eiss);
dissector_add_uint("mpeg_sect.tid", EISS_SECTION_TID, eiss_handle);
data_handle = find_dissector("data");
}
