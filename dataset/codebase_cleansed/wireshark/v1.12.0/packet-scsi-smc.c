static void
dissect_smc_exchangemedium (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *exchg_fields[] = {
&hf_scsi_smc_inv1,
&hf_scsi_smc_inv2,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_smc_mta, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_sa, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_fda, tvb, offset+5, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_sda, tvb, offset+7, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+9, hf_scsi_smc_medium_flags,
ett_scsi_exchange_medium, exchg_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_smc_position_to_element (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *pte_fields[] = {
&hf_scsi_smc_invert,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_smc_mta, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_da, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+7, hf_scsi_smc_medium_flags,
ett_scsi_exchange_medium, pte_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_smc_initialize_element_status (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_smc_initialize_element_status_with_range (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *range_fields[] = {
&hf_scsi_smc_fast,
&hf_scsi_smc_range,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_bitmask(tree, tvb, offset, hf_scsi_smc_range_flags,
ett_scsi_range, range_fields, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_sa, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_num_elements, tvb, offset+5, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+8, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_smc_openclose_importexport_element (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_smc_ea, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_action_code, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+4, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
void
dissect_smc_movemedium (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint offset, gboolean isreq, gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
static const int *move_fields[] = {
&hf_scsi_smc_invert,
NULL
};
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item (tree, hf_scsi_smc_mta, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_sa, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (tree, hf_scsi_smc_da, tvb, offset+5, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+9, hf_scsi_smc_range_flags,
ett_scsi_move, move_fields, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
}
static void
dissect_scsi_smc_volume_tag (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset, int hf_vol_id, int hf_vol_seq_num)
{
char volid[32+1];
char *p;
tvb_memcpy (tvb, (guint8 *)volid, offset, 32);
p = &volid[32];
for (;;) {
*p = '\0';
if (p == volid)
break;
if (*(p - 1) != ' ')
break;
p--;
}
proto_tree_add_string(tree, hf_vol_id, tvb, offset, 32, volid);
proto_tree_add_item(tree, hf_vol_seq_num, tvb, offset+34, 2, ENC_BIG_ENDIAN);
}
static void
dissect_scsi_smc_element (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset,
guint elem_bytecnt, guint8 elem_type,
guint8 voltag_flags)
{
guint8 flags;
guint8 ident_len;
proto_tree_add_item(tree, hf_scsi_smc_ea, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
elem_bytecnt -= 2;
if (elem_bytecnt < 1)
return;
flags = tvb_get_guint8 (tvb, offset);
switch (elem_type) {
case MT_ELEM:
proto_tree_add_item(tree, hf_scsi_smc_except, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_full, tvb, offset, 1, ENC_NA);
break;
case ST_ELEM:
case DT_ELEM:
proto_tree_add_item(tree, hf_scsi_smc_access, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_except, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_full, tvb, offset, 1, ENC_NA);
break;
case I_E_ELEM:
proto_tree_add_item(tree, hf_scsi_smc_cmc, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_inenab, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_exenab, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_impexp, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_access, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_except, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_full, tvb, offset, 1, ENC_NA);
break;
}
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 2)
return;
if (flags & EXCEPT) {
proto_tree_add_item(tree, hf_scsi_smc_additional_sense_code_qualifier, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
elem_bytecnt -= 2;
if (elem_bytecnt < 3)
return;
switch (elem_type) {
case DT_ELEM:
flags = tvb_get_guint8 (tvb, offset);
if (flags & LU_VALID) {
proto_tree_add_item(tree, hf_scsi_smc_lun, tvb, offset, 1, ENC_NA);
}
proto_tree_add_item(tree, hf_scsi_smc_not_bus, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_id_valid, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_lu_valid, tvb, offset, 1, ENC_NA);
offset += 1;
if (flags & ID_VALID) {
proto_tree_add_item(tree, hf_scsi_smc_scsi_bus_address, tvb, offset, 1, ENC_NA);
}
offset += 1;
offset += 1;
break;
default:
offset += 3;
break;
}
elem_bytecnt -= 3;
if (elem_bytecnt < 3)
return;
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_svalid, tvb, offset, 1, ENC_NA);
if (flags & SVALID) {
proto_tree_add_item(tree, hf_scsi_smc_invert, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_scsi_smc_source_storage_element_address, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
offset += 3;
}
elem_bytecnt -= 3;
if (voltag_flags & PVOLTAG) {
if (elem_bytecnt < 36)
return;
dissect_scsi_smc_volume_tag (tvb, pinfo, tree, offset, hf_scsi_smc_primary_vol_tag_id,
hf_scsi_smc_primary_vol_seq_num);
offset += 36;
elem_bytecnt -= 36;
}
if (voltag_flags & AVOLTAG) {
if (elem_bytecnt < 36)
return;
dissect_scsi_smc_volume_tag (tvb, pinfo, tree, offset, hf_scsi_smc_alternate_vol_tag_id,
hf_scsi_smc_alternate_vol_seq_num);
offset += 36;
elem_bytecnt -= 36;
}
if (elem_bytecnt < 1)
return;
proto_tree_add_item(tree, hf_scsi_smc_code_set, tvb, offset, 1, ENC_NA);
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
proto_tree_add_item(tree, hf_scsi_smc_identifier_type, tvb, offset, 1, ENC_NA);
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
ident_len = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_identifier_length, tvb, offset, 1, ENC_NA);
offset += 1;
elem_bytecnt -= 1;
if (ident_len != 0) {
if (elem_bytecnt < ident_len)
return;
proto_tree_add_item(tree, hf_scsi_smc_identifier, tvb, offset, ident_len, ENC_NA);
offset += ident_len;
elem_bytecnt -= ident_len;
}
if (elem_bytecnt != 0) {
proto_tree_add_item(tree, hf_scsi_smc_vendor_specific_data, tvb, offset, elem_bytecnt, ENC_NA);
}
}
static void
dissect_scsi_smc_elements (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset,
guint desc_bytecnt, guint8 elem_type,
guint8 voltag_flags, guint16 elem_desc_len)
{
guint elem_bytecnt;
while (desc_bytecnt != 0) {
elem_bytecnt = elem_desc_len;
if (elem_bytecnt > desc_bytecnt)
elem_bytecnt = desc_bytecnt;
if (elem_bytecnt < 2)
break;
dissect_scsi_smc_element (tvb, pinfo, tree, offset, elem_bytecnt,
elem_type, voltag_flags);
offset += elem_bytecnt;
desc_bytecnt -= elem_bytecnt;
}
}
void
dissect_smc_readelementstatus (tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint offset, gboolean isreq,
gboolean iscdb,
guint payload_len _U_, scsi_task_data_t *cdata _U_)
{
guint bytecnt, desc_bytecnt;
guint8 elem_type;
guint8 voltag_flags;
guint16 elem_desc_len;
if (!tree)
return;
if (isreq && iscdb) {
proto_tree_add_item(tree, hf_scsi_smc_voltag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_element_type_code_0F, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_starting_element_address, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_smc_number_of_elements, tvb, offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_scsi_smc_curdata, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_dvcid, tvb, offset+4, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_allocation_length, tvb, offset+6, 3, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!isreq) {
proto_tree_add_item(tree, hf_scsi_smc_first_element_address_reported, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_scsi_smc_number_of_elements_available, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 1;
bytecnt = tvb_get_ntoh24 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_byte_count_of_report_available, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
while (bytecnt != 0) {
if (bytecnt < 1)
break;
elem_type = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_element_type_code, tvb, offset, 1, ENC_NA);
offset += 1;
bytecnt -= 1;
if (bytecnt < 1)
break;
voltag_flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_pvoltag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_scsi_smc_avoltag, tvb, offset, 1, ENC_NA);
offset += 1;
bytecnt -= 1;
if (bytecnt < 2)
break;
elem_desc_len = tvb_get_ntohs (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_element_descriptor_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
bytecnt -= 2;
if (bytecnt < 1)
break;
offset += 1;
bytecnt -= 1;
if (bytecnt < 3)
break;
desc_bytecnt = tvb_get_ntoh24 (tvb, offset);
proto_tree_add_item(tree, hf_scsi_smc_byte_count_of_descriptor_data_available, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
bytecnt -= 3;
if (desc_bytecnt > bytecnt)
desc_bytecnt = bytecnt;
dissect_scsi_smc_elements (tvb, pinfo, tree, offset,
desc_bytecnt, elem_type,
voltag_flags, elem_desc_len);
offset += desc_bytecnt;
bytecnt -= desc_bytecnt;
}
}
}
void
proto_register_scsi_smc(void)
{
static hf_register_info hf[] = {
{ &hf_scsi_smc_opcode,
{"SMC Opcode", "scsi_smc.opcode",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &scsi_smc_vals_ext, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_mta,
{"Medium Transport Address", "scsi_smc.mta",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_sa,
{"Source Address", "scsi_smc.sa",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_da,
{"Destination Address", "scsi_smc.da",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_fda,
{"First Destination Address", "scsi_smc.fda",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_sda,
{"Second Destination Address", "scsi_smc.sda",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_medium_flags,
{"Flags", "scsi_smc.medium_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_inv1,
{"INV1", "scsi_smc.inv1",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_scsi_smc_inv2,
{"INV2", "scsi_smc.inv2",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_scsi_smc_range_flags,
{"Flags", "scsi_smc.range_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_fast,
{"FAST", "scsi_smc.fast",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL}
},
{ &hf_scsi_smc_range,
{"RANGE", "scsi_smc.range",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
#if 0
{ &hf_scsi_smc_sea,
{"Starting Element Address", "scsi_smc.sea",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
#endif
{ &hf_scsi_smc_num_elements,
{"Number of Elements", "scsi_smc.num_elements",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_invert,
{"INVERT", "scsi_smc.invert",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL}
},
{ &hf_scsi_smc_ea,
{"Element Address", "scsi_smc.ea",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_scsi_smc_action_code,
{"Action Code", "scsi_smc.action_code",
FT_UINT8, BASE_HEX, VALS(action_code_vals), 0x1f,
NULL, HFILL}
},
{ &hf_scsi_smc_scsi_bus_address,
{ "SCSI Bus Address", "scsi_smc.scsi_bus_address",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_source_storage_element_address,
{ "Source Storage Element Address", "scsi_smc.source_storage_element_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_code_set,
{ "Code Set", "scsi_smc.code_set",
FT_UINT8, BASE_DEC, VALS(scsi_devid_codeset_val), 0x0F,
NULL, HFILL }
},
{ &hf_scsi_smc_identifier_type,
{ "Identifier Type", "scsi_smc.identifier_type",
FT_UINT8, BASE_DEC, VALS(scsi_devid_idtype_val), 0x0F,
NULL, HFILL }
},
{ &hf_scsi_smc_identifier_length,
{ "Identifier Length", "scsi_smc.identifier_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_identifier,
{ "Identifier", "scsi_smc.identifier",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_vendor_specific_data,
{ "Vendor-specific Data", "scsi_smc.vendor_specific_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_voltag,
{ "VOLTAG", "scsi_smc.voltag",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_scsi_smc_starting_element_address,
{ "Starting Element Address", "scsi_smc.starting_element_address",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_number_of_elements,
{ "Number of Elements", "scsi_smc.number_of_elements",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_curdata,
{ "CURDATA", "scsi_smc.curdata",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_scsi_smc_allocation_length,
{ "Allocation Length", "scsi_smc.allocation_length",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_first_element_address_reported,
{ "First Element Address Reported", "scsi_smc.first_element_address_reported",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_number_of_elements_available,
{ "Number of Elements Available", "scsi_smc.number_of_elements_available",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_byte_count_of_report_available,
{ "Byte Count of Report Available", "scsi_smc.byte_count_of_report_available",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_element_type_code,
{ "Element Type Code", "scsi_smc.element_type_code",
FT_UINT8, BASE_DEC, VALS(element_type_code_vals), 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_element_type_code_0F,
{ "Element Type Code", "scsi_smc.element_type_code",
FT_UINT8, BASE_DEC, VALS(element_type_code_vals), 0x0F,
NULL, HFILL }
},
{ &hf_scsi_smc_pvoltag,
{ "PVOLTAG", "scsi_smc.pvoltag",
FT_BOOLEAN, 8, NULL, PVOLTAG,
NULL, HFILL }
},
{ &hf_scsi_smc_element_descriptor_length,
{ "Element Descriptor Length", "scsi_smc.element_descriptor_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_byte_count_of_descriptor_data_available,
{ "Byte Count Of Descriptor Data Available", "scsi_smc.byte_count_of_descriptor_data_available",
FT_UINT24, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_except,
{ "EXCEPT", "scsi_smc.except",
FT_BOOLEAN, 8, NULL, EXCEPT,
NULL, HFILL }
},
{ &hf_scsi_smc_access,
{ "ACCESS", "scsi_smc.access",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_scsi_smc_cmc,
{ "cmc", "scsi_smc.cmc",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_scsi_smc_additional_sense_code_qualifier,
{ "Additional Sense Code+Qualifier", "scsi_smc.additional_sense_code_qualifier",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &scsi_asc_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_not_bus,
{ "NOT BUS", "scsi_smc.not_bus",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_scsi_smc_id_valid,
{ "ID VALID", "scsi_smc.id_valid",
FT_BOOLEAN, 8, NULL, ID_VALID,
NULL, HFILL }
},
{ &hf_scsi_smc_lu_valid,
{ "LU VALID", "scsi_smc.lu_valid",
FT_BOOLEAN, 8, NULL, LU_VALID,
NULL, HFILL }
},
{ &hf_scsi_smc_svalid,
{ "SVALID", "scsi_smc.svalid",
FT_BOOLEAN, 8, NULL, SVALID,
NULL, HFILL }
},
{ &hf_scsi_smc_dvcid,
{ "DVCID", "scsi_smc.dvcid",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_scsi_smc_avoltag,
{ "AVOLTAG", "scsi_smc.pvoltag",
FT_BOOLEAN, 8, NULL, AVOLTAG,
NULL, HFILL }
},
{ &hf_scsi_smc_full,
{ "FULL", "scsi_smc.full",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_scsi_smc_exenab,
{ "EXENAB", "scsi_smc.exenab",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_scsi_smc_inenab,
{ "INENAB", "scsi_smc.inenab",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_scsi_smc_impexp,
{ "IMPEXP", "scsi_smc.impexp",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_scsi_smc_lun,
{ "LUN", "scsi_smc.lun",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_scsi_smc_primary_vol_tag_id,
{ "Primary Volume Identification", "scsi_smc.primary_vol_tag_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_alternate_vol_tag_id,
{ "Alternate Volume Identification", "scsi_smc.alternate_vol_tag_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_primary_vol_seq_num,
{ "Primary Volume Sequence Number", "scsi_smc.primary_vol_seq_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_scsi_smc_alternate_vol_seq_num,
{ "Alternate Volume Sequence Number", "scsi_smc.alternate_vol_seq_num",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_scsi_exchange_medium,
&ett_scsi_range,
&ett_scsi_move
};
proto_scsi_smc = proto_register_protocol("SCSI_SMC", "SCSI_SMC", "scsi_smc");
proto_register_field_array(proto_scsi_smc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_scsi_smc(void)
{
}
