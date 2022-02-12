void
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
void
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
void
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
void
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
void
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
proto_tree *tree, guint offset,
const char *name)
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
proto_tree_add_text (tree, tvb, offset, 36,
"%s: Volume Identification = \"%s\", Volume Sequence Number = %u",
name, volid, tvb_get_ntohs (tvb, offset+34));
}
static void
dissect_scsi_smc_element (tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, guint offset,
guint elem_bytecnt, guint8 elem_type,
guint8 voltag_flags)
{
guint8 flags;
guint8 ident_len;
proto_tree_add_text (tree, tvb, offset, 2,
"Element Address: %u",
tvb_get_ntohs (tvb, offset));
offset += 2;
elem_bytecnt -= 2;
if (elem_bytecnt < 1)
return;
flags = tvb_get_guint8 (tvb, offset);
switch (elem_type) {
case MT_ELEM:
proto_tree_add_text (tree, tvb, offset, 1,
"EXCEPT: %u, FULL: %u",
(flags & EXCEPT) >> 2, flags & 0x01);
break;
case ST_ELEM:
case DT_ELEM:
proto_tree_add_text (tree, tvb, offset, 1,
"ACCESS: %u, EXCEPT: %u, FULL: %u",
(flags & 0x08) >> 3,
(flags & EXCEPT) >> 2, flags & 0x01);
break;
case I_E_ELEM:
proto_tree_add_text (tree, tvb, offset, 1,
"cmc: %u, INENAB: %u, EXENAB: %u, ACCESS: %u, EXCEPT: %u, IMPEXP: %u, FULL: %u",
(flags & 0x40) >> 6,
(flags & 0x20) >> 5,
(flags & 0x10) >> 4,
(flags & 0x08) >> 3,
(flags & EXCEPT) >> 2,
(flags & 0x02) >> 1,
flags & 0x01);
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
proto_tree_add_text (tree, tvb, offset, 2,
"Additional Sense Code+Qualifier: %s",
val_to_str_ext (tvb_get_ntohs (tvb, offset),
&scsi_asc_val_ext, "Unknown (0x%04x)"));
}
offset += 2;
elem_bytecnt -= 2;
if (elem_bytecnt < 3)
return;
switch (elem_type) {
case DT_ELEM:
flags = tvb_get_guint8 (tvb, offset);
if (flags & LU_VALID) {
proto_tree_add_text (tree, tvb, offset, 1,
"NOT BUS: %u, ID VALID: %u, LU VALID: 1, LUN: %u",
(flags & 0x80) >> 7,
(flags & ID_VALID) >> 5,
flags & 0x07);
} else if (flags & ID_VALID) {
proto_tree_add_text (tree, tvb, offset, 1,
"ID VALID: 1, LU VALID: 0");
} else {
proto_tree_add_text (tree, tvb, offset, 1,
"ID VALID: 0, LU VALID: 0");
}
offset += 1;
if (flags & ID_VALID) {
proto_tree_add_text (tree, tvb, offset, 1,
"SCSI Bus Address: %u",
tvb_get_guint8 (tvb, offset));
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
if (flags & SVALID) {
proto_tree_add_text (tree, tvb, offset, 1,
"SVALID: 1, INVERT: %u",
(flags & 0x40) >> 6);
offset += 1;
proto_tree_add_text (tree, tvb, offset, 2,
"Source Storage Element Address: %u",
tvb_get_ntohs (tvb, offset));
offset += 2;
} else {
proto_tree_add_text (tree, tvb, offset, 1,
"SVALID: 0");
offset += 3;
}
elem_bytecnt -= 3;
if (voltag_flags & PVOLTAG) {
if (elem_bytecnt < 36)
return;
dissect_scsi_smc_volume_tag (tvb, pinfo, tree, offset,
"Primary Volume Tag Information");
offset += 36;
elem_bytecnt -= 36;
}
if (voltag_flags & AVOLTAG) {
if (elem_bytecnt < 36)
return;
dissect_scsi_smc_volume_tag (tvb, pinfo, tree, offset,
"Alternate Volume Tag Information");
offset += 36;
elem_bytecnt -= 36;
}
if (elem_bytecnt < 1)
return;
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Code Set: %s",
val_to_str (flags & 0x0F,
scsi_devid_codeset_val,
"Unknown (0x%02x)"));
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Identifier Type: %s",
val_to_str ((flags & 0x0F),
scsi_devid_idtype_val,
"Unknown (0x%02x)"));
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
offset += 1;
elem_bytecnt -= 1;
if (elem_bytecnt < 1)
return;
ident_len = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Identifier Length: %u",
ident_len);
offset += 1;
elem_bytecnt -= 1;
if (ident_len != 0) {
if (elem_bytecnt < ident_len)
return;
proto_tree_add_text (tree, tvb, offset, ident_len,
"Identifier: %s",
tvb_bytes_to_str (tvb, offset, ident_len));
offset += ident_len;
elem_bytecnt -= ident_len;
}
if (elem_bytecnt != 0) {
proto_tree_add_text (tree, tvb, offset, elem_bytecnt,
"Vendor-specific Data: %s",
tvb_bytes_to_str (tvb, offset, elem_bytecnt));
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
guint8 flags;
guint numelem, bytecnt, desc_bytecnt;
guint8 elem_type;
guint8 voltag_flags;
guint16 elem_desc_len;
if (!tree)
return;
if (isreq && iscdb) {
flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"VOLTAG: %u, Element Type Code: %s",
(flags & 0x10) >> 4,
val_to_str (flags & 0xF, element_type_code_vals,
"Unknown (0x%x)"));
proto_tree_add_text (tree, tvb, offset+1, 2,
"Starting Element Address: %u",
tvb_get_ntohs (tvb, offset+1));
proto_tree_add_text (tree, tvb, offset+3, 2,
"Number of Elements: %u",
tvb_get_ntohs (tvb, offset+3));
flags = tvb_get_guint8 (tvb, offset+4);
proto_tree_add_text (tree, tvb, offset+4, 1,
"CURDATA: %u, DVCID: %u",
(flags & 0x02) >> 1, flags & 0x01);
proto_tree_add_text (tree, tvb, offset+6, 3,
"Allocation Length: %u",
tvb_get_ntoh24 (tvb, offset+6));
proto_tree_add_bitmask(tree, tvb, offset+10, hf_scsi_control,
ett_scsi_control, cdb_control_fields, ENC_BIG_ENDIAN);
}
else if (!isreq) {
proto_tree_add_text (tree, tvb, offset, 2,
"First Element Address Reported: %u",
tvb_get_ntohs (tvb, offset));
offset += 2;
numelem = tvb_get_ntohs (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 2,
"Number of Elements Available: %u", numelem);
offset += 2;
offset += 1;
bytecnt = tvb_get_ntoh24 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 3,
"Byte Count of Report Available: %u", bytecnt);
offset += 3;
while (bytecnt != 0) {
if (bytecnt < 1)
break;
elem_type = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"Element Type Code: %s",
val_to_str (elem_type, element_type_code_vals,
"Unknown (0x%x)"));
offset += 1;
bytecnt -= 1;
if (bytecnt < 1)
break;
voltag_flags = tvb_get_guint8 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 1,
"PVOLTAG: %u, AVOLTAG: %u",
(voltag_flags & PVOLTAG) >> 7,
(voltag_flags & AVOLTAG) >> 6);
offset += 1;
bytecnt -= 1;
if (bytecnt < 2)
break;
elem_desc_len = tvb_get_ntohs (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 2,
"Element Descriptor Length: %u",
elem_desc_len);
offset += 2;
bytecnt -= 2;
if (bytecnt < 1)
break;
offset += 1;
bytecnt -= 1;
if (bytecnt < 3)
break;
desc_bytecnt = tvb_get_ntoh24 (tvb, offset);
proto_tree_add_text (tree, tvb, offset, 3,
"Byte Count Of Descriptor Data Available: %u",
desc_bytecnt);
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
{"SMC Opcode", "scsi_smc.opcode", FT_UINT8, BASE_HEX,
VALS (scsi_smc_vals), 0x0, NULL, HFILL}},
{ &hf_scsi_smc_mta,
{"Medium Transport Address", "scsi_smc.mta", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_sa,
{"Source Address", "scsi_smc.sa", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_da,
{"Destination Address", "scsi_smc.da", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_fda,
{"First Destination Address", "scsi_smc.fda", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_sda,
{"Second Destination Address", "scsi_smc.sda", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_medium_flags,
{"Flags", "scsi_smc.medium_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_inv1,
{"INV1", "scsi_smc.inv1", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_smc_inv2,
{"INV2", "scsi_smc.inv2", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_smc_range_flags,
{"Flags", "scsi_smc.range_flags", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_fast,
{"FAST", "scsi_smc.fast", FT_BOOLEAN, 8,
NULL, 0x02, NULL, HFILL}},
{ &hf_scsi_smc_range,
{"RANGE", "scsi_smc.range", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
#if 0
{ &hf_scsi_smc_sea,
{"Starting Element Address", "scsi_smc.sea", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
#endif
{ &hf_scsi_smc_num_elements,
{"Number of Elements", "scsi_smc.num_elements", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_invert,
{"INVERT", "scsi_smc.invert", FT_BOOLEAN, 8,
NULL, 0x01, NULL, HFILL}},
{ &hf_scsi_smc_ea,
{"Element Address", "scsi_smc.ea", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_scsi_smc_action_code,
{"Action Code", "scsi_smc.action_code", FT_UINT8, BASE_HEX,
VALS(action_code_vals), 0x1f, NULL, HFILL}},
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
