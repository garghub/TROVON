static const gchar*
s7comm_get_szl_id_index_description_text(guint16 id, guint16 idx)
{
const gchar* str = NULL;
switch (id) {
case 0x0111:
str = val_to_str(idx, szl_0111_index_names, "No description available");
break;
case 0x0112:
str = val_to_str(idx, szl_0112_index_names, "No description available");
break;
case 0x0113:
str = val_to_str(idx, szl_0113_index_names, "No description available");
break;
case 0x0114:
str = val_to_str(idx, szl_0114_index_names, "No description available");
break;
case 0x0115:
str = val_to_str(idx, szl_0115_index_names, "No description available");
break;
case 0x0116:
str = val_to_str(idx, szl_0116_index_names, "No description available");
break;
case 0x0118:
str = val_to_str(idx, szl_0118_index_names, "No description available");
break;
case 0x0119:
str = val_to_str(idx, szl_0119_index_names, "No description available");
break;
case 0x0121:
str = val_to_str(idx, szl_0121_index_names, "No description available");
break;
case 0x0222:
str = val_to_str(idx, szl_0222_index_names, "No description available");
break;
case 0x0524:
str = val_to_str(idx, szl_0524_index_names, "No description available");
break;
case 0x0131:
str = val_to_str(idx, szl_0131_index_names, "No description available");
break;
case 0x0132:
str = val_to_str(idx, szl_0132_index_names, "No description available");
break;
case 0x0174:
str = val_to_str(idx, szl_0174_index_names, "No description available");
break;
}
return str;
}
static void
s7comm_szl_0000_0000_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0000_0000_szl_id,
{ "SZL ID that exists", "s7comm.szl.0000.0000.szl_id", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0000_0000_module_type_class,
{ "Module type class", "s7comm.szl.0000.0000.module_type_class", FT_UINT16, BASE_HEX, NULL, 0xf000,
NULL, HFILL }},
{ &hf_s7comm_szl_0000_0000_partlist_extr_nr,
{ "Number of the SZL partial list extract", "s7comm.szl.0000.0000.partlist_extr_nr", FT_UINT16, BASE_HEX, NULL, 0x0f00,
NULL, HFILL }},
{ &hf_s7comm_szl_0000_0000_partlist_nr,
{ "Number of the SZL partial list", "s7comm.szl.0000.0000.partlist_nr", FT_UINT16, BASE_HEX, NULL, 0x00ff,
NULL, HFILL }}
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_xy00(tvbuff_t *tvb,
proto_tree *tree,
guint16 id,
guint16 idx,
guint32 offset)
{
if (id == 0 && idx == 0) {
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_szl_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (id == 0x0100) {
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_module_type_class, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_partlist_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else if (id == 0x0200 || id == 0x0300) {
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_module_type_class, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_partlist_extr_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_partlist_nr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
proto_tree_add_item(tree, hf_s7comm_szl_0000_0000_szl_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return offset;
}
static void
s7comm_szl_0013_0000_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0013_0000_index,
{ "Index", "s7comm.szl.0013.0000.index", FT_UINT16, BASE_HEX, VALS(szl_0113_index_names), 0x0,
"Index of an identification data record", HFILL }},
{ &hf_s7comm_szl_0013_0000_code,
{ "Code (Memory type)", "s7comm.szl.0013.0000.code", FT_UINT16, BASE_HEX, VALS(szl_memory_type_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_size,
{ "Size (Total size of the selected memory, total of area 1 and area 2)", "s7comm.szl.0013.0000.size", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_mode,
{ "Mode (Logical mode of the memory)", "s7comm.szl.0013.0000.mode", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_mode_0,
{ "Volatile memory area", "s7comm.szl.0013.0000.mode.vol_mem", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Volatile memory area", HFILL }},
{ &hf_s7comm_szl_0013_0000_mode_1,
{ "Non-volatile memory area", "s7comm.szl.0013.0000.mode.nvol_mem", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Non-volatile memory area", HFILL }},
{ &hf_s7comm_szl_0013_0000_mode_2,
{ "Mixed memory area", "s7comm.szl.0013.0000.mode.mixed_mem", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Mixed memory area", HFILL }},
{ &hf_s7comm_szl_0013_0000_mode_3,
{ "Code and data separate (for work memory)", "s7comm.szl.0013.0000.mode.cd_sep", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Code and data separate (for work memory)", HFILL }},
{ &hf_s7comm_szl_0013_0000_mode_4,
{ "Code and data together (for work memory)", "s7comm.szl.0013.0000.mode.cd_tog", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Code and data together (for work memory)", HFILL }},
{ &hf_s7comm_szl_0013_0000_granu,
{ "Granu", "s7comm.szl.0013.0000.granu", FT_UINT16, BASE_HEX, NULL, 0x0,
"Granu (Always has the value 0)", HFILL }},
{ &hf_s7comm_szl_0013_0000_ber1,
{ "ber1 (Size of the volatile memory area in bytes)", "s7comm.szl.0013.0000.ber1", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_belegt1,
{ "belegt1 (Size of the volatile memory area being used)", "s7comm.szl.0013.0000.belegt1", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_block1,
{ "block1 (Largest free block in the volatile memory area)", "s7comm.szl.0013.0000.block1", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_ber2,
{ "ber2 (Size of the non-volatile memory area in bytes)", "s7comm.szl.0013.0000.ber2", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_belegt2,
{ "belegt2 (Size of the non-volatile memory area being used)", "s7comm.szl.0013.0000.belegt2", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0013_0000_block2,
{ "block2 (Largest free block in the non-volatile memory area)", "s7comm.szl.0013.0000.block2", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0013_idx_0000(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_code, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode_0, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode_3, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_mode_4, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_granu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_ber1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_belegt1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_block1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_ber2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_belegt2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0013_0000_block2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static void
s7comm_szl_xy11_0001_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_xy11_0001_index,
{ "Index", "s7comm.szl.xy11.0001.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"Index of an identification data record", HFILL }},
{ &hf_s7comm_szl_xy11_0001_mlfb,
{ "MlfB (Order number of the module)", "s7comm.szl.xy11.0001.anz", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_xy11_0001_bgtyp,
{ "BGTyp (Module type ID)", "s7comm.szl.xy11.0001.bgtyp", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_xy11_0001_ausbg,
{ "Ausbg (Version of the module or release of the operating system)", "s7comm.szl.xy11.0001.ausbg", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_xy11_0001_ausbe,
{ "Ausbe (Release of the PG description file)", "s7comm.szl.xy11.0001.ausbe", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0111_idx_0001(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_xy11_0001_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_xy11_0001_mlfb, tvb, offset, 20, ENC_ASCII|ENC_NA);
offset += 20;
proto_tree_add_item(tree, hf_s7comm_szl_xy11_0001_bgtyp, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_xy11_0001_ausbg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_xy11_0001_ausbe, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static void
s7comm_szl_0131_0001_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0001_index,
{ "Index", "s7comm.szl.0131.0001.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0001: Index for general communication data", HFILL }},
{ &hf_s7comm_szl_0131_0001_pdu,
{ "pdu (Maximum PDU size in bytes)", "s7comm.szl.0131.0001.pdu", FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum PDU size in bytes", HFILL }},
{ &hf_s7comm_szl_0131_0001_anz,
{ "anz (Maximum number of communication connections)", "s7comm.szl.0131.0001.anz", FT_UINT16, BASE_DEC, NULL, 0x0,
"Maximum number of communication connections", HFILL }},
{ &hf_s7comm_szl_0131_0001_mpi_bps,
{ "mpi_bps (Maximum data rate of the MPI in hexadecimal format)", "s7comm.szl.0131.0001.mpi_bps", FT_UINT32, BASE_HEX, NULL, 0x0,
"Maximum data rate of the MPI in hexadecimal format, Example: 0x2DC6C corresponds to 187500 bps", HFILL }},
{ &hf_s7comm_szl_0131_0001_kbus_bps,
{ "mkbus_bps (Maximum data rate of the communication bus)", "s7comm.szl.0131.0001.kbus_bps", FT_UINT32, BASE_HEX, NULL, 0x0,
"Maximum data rate of the communication bus", HFILL }},
{ &hf_s7comm_szl_0131_0001_res,
{ "res (Reserved)", "s7comm.szl.0131.0001.res", FT_BYTES, BASE_NONE, NULL, 0x0,
"Reserved", HFILL }}
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0001(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_pdu, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_anz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_mpi_bps, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_kbus_bps, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0001_res, tvb, offset, 26, ENC_NA);
offset += 26;
return offset;
}
static void
s7comm_szl_0131_0002_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0002_index,
{ "Index", "s7comm.szl.0131.0002.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0002: test and installation", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0,
{ "funkt_0", "s7comm.szl.0131.0002.funkt_0", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_0,
{ "Reserved", "s7comm.szl.0131.0002.funkt_0.bit0_res", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_1,
{ "Block status", "s7comm.szl.0131.0002.funkt_0.block_stat", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Block status", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_2,
{ "Variable status", "s7comm.szl.0131.0002.funkt_0.var_stat", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Variable status", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_3,
{ "Output ISTACK", "s7comm.szl.0131.0002.funkt_0.outp_istack", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Output ISTACK", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_4,
{ "Output BSTACK", "s7comm.szl.0131.0002.funkt_0.outp_bstack", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Output BSTACK", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_5,
{ "Output LSTACK", "s7comm.szl.0131.0002.funkt_0.outp_lstack", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Output LSTACK", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_6,
{ "Time measurement from ... to ...", "s7comm.szl.0131.0002.funkt_0.time_meas", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Time measurement from ... to ...", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_0_7,
{ "Force selection", "s7comm.szl.0131.0002.funkt_0.force_sel", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Force selection", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1,
{ "funkt_1", "s7comm.szl.0131.0002.funkt_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_0,
{ "Modify variable", "s7comm.szl.0131.0002.funkt_1.mod_var", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Modify variable", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_1,
{ "Force", "s7comm.szl.0131.0002.funkt_1.force", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Force", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_2,
{ "Breakpoint", "s7comm.szl.0131.0002.funkt_1.breakp", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Breakpoint", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_3,
{ "Exit HOLD", "s7comm.szl.0131.0002.funkt_1.oexit_hold", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: OExit HOLD", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_4,
{ "Memory reset", "s7comm.szl.0131.0002.funkt_1.mem_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Memory reset", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_5,
{ "Disable job", "s7comm.szl.0131.0002.funkt_1.dis_job", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Disable job", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_6,
{ "Enable job", "s7comm.szl.0131.0002.funkt_1.en_job", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Enable job", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_1_7,
{ "Delete job", "s7comm.szl.0131.0002.funkt_1.del_job", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Delete job", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2,
{ "funkt_2", "s7comm.szl.0131.0002.funkt_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_0,
{ "Read job list", "s7comm.szl.0131.0002.funkt_2.rd_job_list", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Read job list", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_1,
{ "Read job", "s7comm.szl.0131.0002.funkt_2.rd_job", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Read job", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_2,
{ "Replace job", "s7comm.szl.0131.0002.funkt_2.repl_job", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Replace job", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_3,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_4,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_5,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_6,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_2_7,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_3,
{ "funkt_3 (Reserved)", "s7comm.szl.0131.0002.funkt_3", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_4,
{ "funkt_4 (Reserved)", "s7comm.szl.0131.0002.funkt_4", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_funkt_5,
{ "funkt_5 (Reserved)", "s7comm.szl.0131.0002.funkt_5", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted TIS (Test and Installation) functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0002_aseg,
{ "aseg", "s7comm.szl.0131.0002.aseg", FT_BYTES, BASE_NONE, NULL, 0x0,
"aseg (Non-relevant system data)", HFILL }},
{ &hf_s7comm_szl_0131_0002_eseg,
{ "eseg", "s7comm.szl.0131.0002.eseg", FT_BYTES, BASE_NONE, NULL, 0x0,
"eseg (Non-relevant system data)", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0,
{ "trgereig_0 (Permitted trigger events)", "s7comm.szl.0131.0002.trgereig_0", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_0,
{ "Immediately", "s7comm.szl.0131.0002.trgereig_0.immed", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: immediately", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_1,
{ "System trigger", "s7comm.szl.0131.0002.trgereig_0.sys_trig", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: System trigger", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_2,
{ "System checkpoint main cycle start", "s7comm.szl.0131.0002.trgereig_0.sys_cp_mcs", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: System checkpoint main cycle start", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_3,
{ "System checkpoint main cycle end", "s7comm.szl.0131.0002.trgereig_0.sys_cp_mce", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: System checkpoint main cycle end", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_4,
{ "Mode transition RUN-STOP", "s7comm.szl.0131.0002.trgereig_0.mtrans_rs", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Mode transition RUN-STOP", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_5,
{ "After code address", "s7comm.szl.0131.0002.trgereig_0.acode_adr", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: After code address", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_6,
{ "Code address area", "s7comm.szl.0131.0002.trgereig_0.code_adr_a", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Code address area", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_0_7,
{ "Data address", "s7comm.szl.0131.0002.trgereig_0.data_adr", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Data Address", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1,
{ "trgereig_1 (Permitted trigger events)", "s7comm.szl.0131.0002.trgereig_1", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_0,
{ "Data address area", "s7comm.szl.0131.0002.trgereig_1.data_adr_a", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Data address area", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_1,
{ "Local data address", "s7comm.szl.0131.0002.trgereig_1.loc_adr", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Local data address", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_2,
{ "Local data address area", "s7comm.szl.0131.0002.trgereig_1.loc_adr_a", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Local data address area", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_3,
{ "Range trigger", "s7comm.szl.0131.0002.trgereig_1.range_trig", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Range trigger", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_4,
{ "Before code address", "s7comm.szl.0131.0002.trgereig_1.bcode_adr", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Before code address", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_5,
{ "Reserved", "s7comm.szl.0131.0002.trgereig_1.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_6,
{ "Reserved", "s7comm.szl.0131.0002.trgereig_1.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_1_7,
{ "Reserved", "s7comm.szl.0131.0002.trgereig_1.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0002_trgereig_2,
{ "trgereig_2 (Permitted trigger events, reserved)", "s7comm.szl.0131.0002.trgereig_2", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_trgbed,
{ "trgbed (System data with no relevance)", "s7comm.szl.0131.0002.trgbed", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_pfad,
{ "pfad (System data with no relevance)", "s7comm.szl.0131.0002.pfad", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_tiefe,
{ "tiefe (System data with no relevance)", "s7comm.szl.0131.0002.tiefe", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_systrig,
{ "systrig (System data with no relevance)", "s7comm.szl.0131.0002.systrig", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_erg_par,
{ "erg par (System data with no relevance)", "s7comm.szl.0131.0002.erg_par", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_erg_pat_1,
{ "erg pat 1 (System data with no relevance)", "s7comm.szl.0131.0002.erg_pat_1", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_erg_pat_2,
{ "erg pat 2 (System data with no relevance)", "s7comm.szl.0131.0002.erg_pat_2", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_force,
{ "force (Number of modifiable Variables)", "s7comm.szl.0131.0002.force", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0002_time,
{ "time", "s7comm.szl.0131.0002.time", FT_UINT16, BASE_HEX, NULL, 0x0,
"time (Upper time limit run-time meas, Format: bits 0 to 11 contain the time value (0 to 4K-1); bits 12 to 15 contain the time base: 0H= 10^-10s, 1H = 10^-9s,...,AH = 100s, ... FH = 105s)", HFILL }},
{ &hf_s7comm_szl_0131_0002_res,
{ "res (Reserved)", "s7comm.szl.0131.0002.res", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0002(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0002_funkt_0,
ett_s7comm_szl_0131_0002_funkt_0, s7comm_szl_0131_0002_funkt_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0002_funkt_1,
ett_s7comm_szl_0131_0002_funkt_1, s7comm_szl_0131_0002_funkt_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0002_funkt_2,
ett_s7comm_szl_0131_0002_funkt_2, s7comm_szl_0131_0002_funkt_2_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_funkt_3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_funkt_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_funkt_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_aseg, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_eseg, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0002_trgereig_0,
ett_s7comm_szl_0131_0002_trgereig_0, s7comm_szl_0131_0002_trgereig_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0002_trgereig_1,
ett_s7comm_szl_0131_0002_trgereig_1, s7comm_szl_0131_0002_trgereig_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_trgereig_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_trgbed, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_pfad, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_tiefe, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_systrig, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_erg_par, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_erg_pat_1, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_erg_pat_2, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_force, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0002_res, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static void
s7comm_szl_0131_0003_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0003_index,
{ "Index", "s7comm.szl.0131.0003.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0003: Index for operator interface functions", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0,
{ "funkt_0", "s7comm.szl.0131.0003.funkt_0", FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits indicating the available functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_0,
{ "Read once", "s7comm.szl.0131.0003.funkt_0.read_once", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Read once", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_1,
{ "Write once", "s7comm.szl.0131.0003.funkt_0.write_once", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Write once", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_2,
{ "Initialize cyclic reading (start implicitly)", "s7comm.szl.0131.0003.funkt_0.init_cycl_read_impl", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Initialize cyclic reading (start implicitly)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_3,
{ "Initialize cyclic reading (start explicitly)", "s7comm.szl.0131.0003.funkt_0.init_cycl_read_expl", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Initialize cyclic reading (start explicitly)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_4,
{ "Start cyclic reading", "s7comm.szl.0131.0003.funkt_0.start_cycl_read", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Start cyclic reading", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_5,
{ "Stop cyclic reading", "s7comm.szl.0131.0003.funkt_0.stop_cycl_read", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Stop cyclic reading", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_6,
{ "Clear cyclic reading", "s7comm.szl.0131.0002.funkt_0.clr_cycl_read", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Clear cyclic reading", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_0_7,
{ "Reserved", "s7comm.szl.0131.0002.funkt_0.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1,
{ "funkt_1", "s7comm.szl.0131.0003.funkt_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits indicating the available functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_0,
{ "Reserved", "s7comm.szl.0131.0003.funkt_1.bit0_res", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_1,
{ "Reserved", "s7comm.szl.0131.0003.funkt_1.bit1_res", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_2,
{ "Reserved", "s7comm.szl.0131.0003.funkt_1.bit2_res", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_3,
{ "Reserved", "s7comm.szl.0131.0003.funkt_1.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_4,
{ "Peripheral I/Os", "s7comm.szl.0131.0003.funkt_1.periph_io", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Peripheral I/Os", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_5,
{ "Inputs", "s7comm.szl.0131.0003.funkt_1.inputs", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Inputs", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_6,
{ "Outputs", "s7comm.szl.0131.0002.funkt_1.outputs", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Outputs", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_1_7,
{ "Bit memory", "s7comm.szl.0131.0002.funkt_1.bit_mem", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Bit memory", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2,
{ "funkt_2", "s7comm.szl.0131.0003.funkt_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits indicating the available functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_0,
{ "User DB", "s7comm.szl.0131.0003.funkt_2.user_db", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: User DB", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_1,
{ "Data record", "s7comm.szl.0131.0003.funkt_2.data_rec", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Data record", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_2,
{ "Reserved", "s7comm.szl.0131.0003.funkt_2.bit2_res", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_3,
{ "Reserved", "s7comm.szl.0131.0003.funkt_2.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_4,
{ "Reserved", "s7comm.szl.0131.0003.funkt_2.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_5,
{ "Reserved", "s7comm.szl.0131.0003.funkt_2.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_6,
{ "Reserved", "s7comm.szl.0131.0002.funkt_2.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_2_7,
{ "S7 counter", "s7comm.szl.0131.0002.funkt_2.s7_counter", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: S7 counter", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3,
{ "funkt_3", "s7comm.szl.0131.0003.funkt_3", FT_UINT8, BASE_HEX, NULL, 0x0,
"Bits indicating the available functions (bit = 1: function exists)", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_0,
{ "S7 timer", "s7comm.szl.0131.0003.funkt_3.s7_timer", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: S7 timer", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_1,
{ "IEC counter", "s7comm.szl.0131.0003.funkt_3.iec_counter", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: IEC counter", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_2,
{ "IEC timer", "s7comm.szl.0131.0003.funkt_3.iec_timer", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: IEC timer", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_3,
{ "High speed counter", "s7comm.szl.0131.0003.funkt_3.hs_counter", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: High speed counter", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_4,
{ "Reserved", "s7comm.szl.0131.0003.funkt_3.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_5,
{ "Reserved", "s7comm.szl.0131.0003.funkt_3.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_6,
{ "Reserved", "s7comm.szl.0131.0002.funkt_3.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_funkt_3_7,
{ "Reserved", "s7comm.szl.0131.0002.funkt_3.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0003_data,
{ "data (Maximum size of consistently readable data)", "s7comm.szl.0131.0003.data", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0003_anz,
{ "anz (Maximum number of cyclic read jobs)", "s7comm.szl.0131.0003.anz", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0003_per_min,
{ "per min (Minimum period for cyclic read jobs (n x 100 ms)", "s7comm.szl.0131.0003.per_min", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0003_per_max,
{ "per max (Maximum period for cyclic read jobs (n x 100 ms)", "s7comm.szl.0131.0003.per_max", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0003_res,
{ "res (Reserved)", "s7comm.szl.0131.0003.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0003(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0003_funkt_0,
ett_s7comm_szl_0131_0003_funkt_0, s7comm_szl_0131_0003_funkt_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0003_funkt_1,
ett_s7comm_szl_0131_0003_funkt_1, s7comm_szl_0131_0003_funkt_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0003_funkt_2,
ett_s7comm_szl_0131_0003_funkt_2, s7comm_szl_0131_0003_funkt_2_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0003_funkt_3,
ett_s7comm_szl_0131_0003_funkt_3, s7comm_szl_0131_0003_funkt_3_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_data, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_anz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_per_min, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_per_max, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0003_res, tvb, offset, 26, ENC_NA);
offset += 26;
return offset;
}
static void
s7comm_szl_0131_0004_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0004_index,
{ "Index", "s7comm.szl.0131.0004.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0004 Index for OMS", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0,
{ "funkt_0", "s7comm.szl.0131.0004.funkt_0", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_0,
{ "Reserved", "s7comm.szl.0131.0004.funkt_0.bit0_res", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_1,
{ "Directory (hierarchy 1)", "s7comm.szl.0131.0004.funkt_0.dir_h1", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Directory (hierarchy 1)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_2,
{ "Directory (hierarchy 2)", "s7comm.szl.0131.0004.funkt_0.dir_h2", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Directory (hierarchy 2)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_3,
{ "Directory (hierarchy 3)", "s7comm.szl.0131.0004.funkt_0.dir_h3", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Directory (hierarchy 3)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_4,
{ "Copy", "s7comm.szl.0131.0004.funkt_0.copy", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Copy", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_5,
{ "Chain (list)", "s7comm.szl.0131.0004.funkt_0.chain_list", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Chain (list)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_6,
{ "Chain (all copied)", "s7comm.szl.0131.0004.funkt_0.chain_copied", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Chain (all copied)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_0_7,
{ "Delete (list)", "s7comm.szl.0131.0004.funkt_0.delete_list", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Delete (list)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1,
{ "funkt_1", "s7comm.szl.0131.0004.funkt_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_0,
{ "Upload on PG", "s7comm.szl.0131.0004.funkt_1.upl_on_pg", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Upload on PG", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_1,
{ "Assign parameters when chaining", "s7comm.szl.0131.0004.funkt_1.asgn_w_chain", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Assign parameters when chaining", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_2,
{ "LOAD function when exchanging data with CFBs", "s7comm.szl.0131.0004.funkt_1.load_w_chg", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: LOAD function when exchanging data with CFBs", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_3,
{ "Reserved", "s7comm.szl.0131.0004.funkt_1.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_4,
{ "Reserved", "s7comm.szl.0131.0004.funkt_1.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_5,
{ "Reserved", "s7comm.szl.0131.0004.funkt_1.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_6,
{ "Reserved", "s7comm.szl.0131.0004.funkt_1.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_1_7,
{ "Delete *.*", "s7comm.szl.0131.0004.funkt_1.delete_all", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Delete *.*", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2,
{ "funkt_2", "s7comm.szl.0131.0004.funkt_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_0,
{ "Load user program (RAM)", "s7comm.szl.0131.0004.funkt_2.load_ram", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Load user program (RAM)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_1,
{ "Load user program (EPROM)", "s7comm.szl.0131.0004.funkt_2.load_eprom", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Load user program (EPROM)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_2,
{ "Save user program (RAM)", "s7comm.szl.0131.0004.funkt_2.save_ram", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Save user program (RAM)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_3,
{ "Save user program (EPROM)", "s7comm.szl.0131.0004.funkt_2.save_eprom", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Save user program (EPROM)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_4,
{ "Save user program (all)", "s7comm.szl.0131.0004.funkt_2.save_all", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Save user program (all)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_5,
{ "Compress (external)", "s7comm.szl.0131.0004.funkt_2.compress", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Compress (external)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_6,
{ "Firmware update (using communication)", "s7comm.szl.0131.0004.funkt_2.fw_update", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Firmware update (using communication)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_2_7,
{ "Set RAM memory mode", "s7comm.szl.0131.0004.funkt_2.set_ram_mode", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Set RAM memory mode", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3,
{ "funkt_3", "s7comm.szl.0131.0004.funkt_3", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_0,
{ "Set EPROM memory mode", "s7comm.szl.0131.0004.funkt_3.set_eprom_mode", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Set EPROM memory mode", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_1,
{ "Reserved", "s7comm.szl.0131.0004.funkt_3.bit1_res", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_2,
{ "Reserved", "s7comm.szl.0131.0004.funkt_3.bit2_res", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_3,
{ "Reserved", "s7comm.szl.0131.0004.funkt_3.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_4,
{ "Reserved", "s7comm.szl.0131.0004.funkt_3.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_5,
{ "Reserved", "s7comm.szl.0131.0004.funkt_3.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_6,
{ "Assign parameters to newly plugged in modules", "s7comm.szl.0131.0004.funkt_3.asgn_par_mod", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Assign parameters to newly plugged in modules", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_3_7,
{ "Assign parameters when evaluating memory card", "s7comm.szl.0131.0004.funkt_3.asgn_par_mc", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Assign parameters when evaluating memory card", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4,
{ "funkt_4", "s7comm.szl.0131.0004.funkt_4", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_0,
{ "Assign parameters when loading user program", "s7comm.szl.0131.0004.funkt_4.asgn_par_lprog", FT_BOOLEAN, 8, NULL, 0x01,
"Bit 0: Assign parameters when loading user program", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_1,
{ "Assign parameters in complete restart", "s7comm.szl.0131.0004.funkt_4.asgn_par_cres", FT_BOOLEAN, 8, NULL, 0x02,
"Bit 1: Assign parameters in complete restart", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_2,
{ "Assign parameters in restart", "s7comm.szl.0131.0004.funkt_4.asgn_par_res", FT_BOOLEAN, 8, NULL, 0x04,
"Bit 2: Assign parameters in restart", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_3,
{ "Compress (SFC25 COMPRESS)", "s7comm.szl.0131.0004.funkt_4.compress", FT_BOOLEAN, 8, NULL, 0x08,
"Bit 3: Compress (SFC25 COMPRESS)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_4,
{ "Evaluate memory card after switch setting", "s7comm.szl.0131.0004.funkt_4.ev_mc", FT_BOOLEAN, 8, NULL, 0x10,
"Bit 4: Evaluate memory card after switch setting", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_5,
{ "Firmware update using memory card", "s7comm.szl.0131.0004.funkt_4.fw_update_mc", FT_BOOLEAN, 8, NULL, 0x20,
"Bit 5: Firmware update using memory card", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_6,
{ "Reserved", "s7comm.szl.0131.0004.funkt_4.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
"Bit 6: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_4_7,
{ "Reserved", "s7comm.szl.0131.0004.funkt_4.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
"Bit 7: Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_5,
{ "funkt_5 (Reserved)", "s7comm.szl.0131.0004.funkt_5", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_6,
{ "funkt_6 (Reserved)", "s7comm.szl.0131.0004.funkt_6", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_funkt_7,
{ "funkt_7 (Reserved)", "s7comm.szl.0131.0004.funkt_7", FT_UINT8, BASE_HEX, NULL, 0x0,
"Available object management system functions: (Bit = 1: functions available on the CPU)", HFILL }},
{ &hf_s7comm_szl_0131_0004_kop,
{ "kop (Maximum number of copied blocks)", "s7comm.szl.0131.0004.kop", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0004_del,
{ "del (Maximum number of uninterruptable, deletable blocks)", "s7comm.szl.0131.0004.del", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0004_kett,
{ "kett (Maximum number of blocks chained in one job)", "s7comm.szl.0131.0004.kett", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0004_hoch,
{ "hoch (Maximum number of simultaneous upload procedures)", "s7comm.szl.0131.0004.hoch", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0004_ver,
{ "ver (Maximum size (in bytes) of shiftable blocks in RUN)", "s7comm.szl.0131.0004.hoch", FT_UINT8, BASE_DEC, NULL, 0x0,
"ver (Maximum size (in bytes) of shiftable blocks in RUN) With an S7-300, this size refers to the entire block,with the S7-400, it refers to the part of the block relevant to running the program.", HFILL }},
{ &hf_s7comm_szl_0131_0004_res,
{ "res (Reserved)", "s7comm.szl.0131.0004.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0004(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0004_funkt_0,
ett_s7comm_szl_0131_0004_funkt_0, s7comm_szl_0131_0004_funkt_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0004_funkt_1,
ett_s7comm_szl_0131_0004_funkt_1, s7comm_szl_0131_0004_funkt_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0004_funkt_2,
ett_s7comm_szl_0131_0004_funkt_2, s7comm_szl_0131_0004_funkt_2_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0004_funkt_3,
ett_s7comm_szl_0131_0004_funkt_3, s7comm_szl_0131_0004_funkt_3_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0004_funkt_4,
ett_s7comm_szl_0131_0004_funkt_4, s7comm_szl_0131_0004_funkt_4_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_funkt_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_funkt_6, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_funkt_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_kop, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_del, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_kett, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_hoch, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0004_res, tvb, offset, 25, ENC_NA);
offset += 25;
return offset;
}
static void
s7comm_szl_0131_0006_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0006_index,
{ "Index", "s7comm.szl.0131.0006.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0006 Data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0,
{ "funkt_0", "s7comm.szl.0131.0006.funkt_0", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_0,
{ "Bit 0: USEND", "s7comm.szl.0131.0006.funkt_0.usend", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_1,
{ "Bit 1: URCV", "s7comm.szl.0131.0006.funkt_0.urcv", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_2,
{ "Bit 2: SEND", "s7comm.szl.0131.0006.funkt_0.send", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_3,
{ "Bit 3: RCV", "s7comm.szl.0131.0006.funkt_0.rcv", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_4,
{ "Bit 4: BSEND", "s7comm.szl.0131.0006.funkt_0.bsend", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_5,
{ "Bit 5: BRCV", "s7comm.szl.0131.0006.funkt_0.brcv", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_6,
{ "Bit 6: GET", "s7comm.szl.0131.0006.funkt_0.get", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_0_7,
{ "Bit 7: PUT", "s7comm.szl.0131.0006.funkt_0.put", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1,
{ "funkt_1", "s7comm.szl.0131.0006.funkt_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_0,
{ "Bit 0: PRINT", "s7comm.szl.0131.0006.funkt_1.print", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_1,
{ "Bit 1: ABORT", "s7comm.szl.0131.0006.funkt_1.abort", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_2,
{ "Bit 2: INITIATE", "s7comm.szl.0131.0006.funkt_1.initiate", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_3,
{ "Bit 3: START", "s7comm.szl.0131.0006.funkt_1.start", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_4,
{ "Bit 4: STOP", "s7comm.szl.0131.0006.funkt_1.stop", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_5,
{ "Bit 5: RESUME", "s7comm.szl.0131.0006.funkt_1.resume", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_6,
{ "Bit 6: STATUS", "s7comm.szl.0131.0006.funkt_1.status", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_1_7,
{ "Bit 7: USTATUS", "s7comm.szl.0131.0006.funkt_1.ustatus", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2,
{ "funkt_2", "s7comm.szl.0131.0006.funkt_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_0,
{ "Bit 0: PI", "s7comm.szl.0131.0006.funkt_2.pi", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_1,
{ "Bit 1: READ", "s7comm.szl.0131.0006.funkt_2.read", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_2,
{ "Bit 2: WRITE", "s7comm.szl.0131.0006.funkt_2.write", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_3,
{ "Bit 3: LOAD", "s7comm.szl.0131.0006.funkt_2.load", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_4,
{ "Bit 4: LOAD_ME", "s7comm.szl.0131.0006.funkt_2.load_me", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_5,
{ "Bit 5: ALARM", "s7comm.szl.0131.0006.funkt_2.alarm", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_6,
{ "Bit 6: ALARM_8", "s7comm.szl.0131.0006.funkt_2.alarm_8", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_2_7,
{ "Bit 7: ALARM_8P", "s7comm.szl.0131.0006.funkt_2.alarm_8p", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3,
{ "funkt_3", "s7comm.szl.0131.0006.funkt_3", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_0,
{ "Bit 0: NOTIFY", "s7comm.szl.0131.0006.funkt_3.notify", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_1,
{ "Bit 1: AR_SEND", "s7comm.szl.0131.0006.funkt_3.ar_send", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_2,
{ "Bit 2: Reserved", "s7comm.szl.0131.0006.funkt_3.bit2_res", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_3,
{ "Bit 3: Reserved", "s7comm.szl.0131.0006.funkt_3.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_4,
{ "Bit 4: Reserved", "s7comm.szl.0131.0006.funkt_3.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_5,
{ "Bit 5: Reserved", "s7comm.szl.0131.0006.funkt_3.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_6,
{ "Bit 6: Reserved", "s7comm.szl.0131.0006.funkt_3.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_3_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0006.funkt_3.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_4,
{ "funkt_4", "s7comm.szl.0131.0006.funkt_4", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_5,
{ "funkt_5", "s7comm.szl.0131.0006.funkt_5", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6,
{ "funkt_6", "s7comm.szl.0131.0006.funkt_6", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_0,
{ "Bit 0: X_SEND", "s7comm.szl.0131.0006.funkt_6.x_send", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_1,
{ "Bit 1: X_RCV", "s7comm.szl.0131.0006.funkt_6.x_rcv", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_2,
{ "Bit 2: X_GET", "s7comm.szl.0131.0006.funkt_6.x_get", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_3,
{ "Bit 3: X_PUT", "s7comm.szl.0131.0006.funkt_6.x_put", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_4,
{ "Bit 4: X_ABORT", "s7comm.szl.0131.0006.funkt_6.x_abort", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_5,
{ "Bit 5: I_GET", "s7comm.szl.0131.0006.funkt_6.i_get", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_6,
{ "Bit 6: I_PUT", "s7comm.szl.0131.0006.funkt_6.i_put", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_6_7,
{ "Bit 7: I_ABORT", "s7comm.szl.0131.0006.funkt_6.i_abort", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7,
{ "funkt_7", "s7comm.szl.0131.0006.funkt_7", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_0,
{ "Bit 0: SCAN_SND", "s7comm.szl.0131.0006.funkt_7.scan_snd", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_1,
{ "Bit 1: ALARM_SQ", "s7comm.szl.0131.0006.funkt_7.alarm_sq", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_2,
{ "Bit 2: ALARM_S", "s7comm.szl.0131.0006.funkt_7.alarm_s", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_3,
{ "Bit 3: ALARM_SC", "s7comm.szl.0131.0006.funkt_7.alarm_sc", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_4,
{ "Bit 4: EN_MSG", "s7comm.szl.0131.0006.funkt_7.en_msg", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_5,
{ "Bit 5: DIS_MSG", "s7comm.szl.0131.0006.funkt_7.dis_msg", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_6,
{ "Bit 6: CONTROL", "s7comm.szl.0131.0006.funkt_7.control", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_funkt_7_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0006.funkt_7.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_schnell,
{ "schnell (Fast reaction yes/no)", "s7comm.szl.0131.0006.schnell", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0,
{ "zugtyp_0", "s7comm.szl.0131.0006.zugtyp_0", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_0 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_0,
{ "Bit 0: USEND", "s7comm.szl.0131.0006.zugtyp_0.usend", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_1,
{ "Bit 1: URCV", "s7comm.szl.0131.0006.zugtyp_0.urcv", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_2,
{ "Bit 2: SEND", "s7comm.szl.0131.0006.zugtyp_0.send", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_3,
{ "Bit 3: RCV", "s7comm.szl.0131.0006.zugtyp_0.rcv", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_4,
{ "Bit 4: BSEND", "s7comm.szl.0131.0006.zugtyp_0.bsend", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_5,
{ "Bit 5: BRCV", "s7comm.szl.0131.0006.zugtyp_0.brcv", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_6,
{ "Bit 6: GET", "s7comm.szl.0131.0006.zugtyp_0.get", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_0_7,
{ "Bit 7: PUT", "s7comm.szl.0131.0006.zugtyp_0.put", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1,
{ "zugtyp_1", "s7comm.szl.0131.0006.zugtyp_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_1 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_0,
{ "Bit 0: PRINT", "s7comm.szl.0131.0006.zugtyp_1.print", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_1,
{ "Bit 1: ABORT", "s7comm.szl.0131.0006.zugtyp_1abort", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_2,
{ "Bit 2: INITIATE", "s7comm.szl.0131.0006.zugtyp_1.initiate", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_3,
{ "Bit 3: START", "s7comm.szl.0131.0006.zugtyp_1.start", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_4,
{ "Bit 4: STOP", "s7comm.szl.0131.0006.zugtyp_1.stop", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_5,
{ "Bit 5: RESUME", "s7comm.szl.0131.0006.zugtyp_1.resume", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_6,
{ "Bit 6: STATUS", "s7comm.szl.0131.0006.zugtyp_1.status", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_1_7,
{ "Bit 7: USTATUS", "s7comm.szl.0131.0006.zugtyp_1.ustatus", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2,
{ "zugtyp_2", "s7comm.szl.0131.0006.zugtyp_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_2 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_0,
{ "Bit 0: PI", "s7comm.szl.0131.0006.zugtyp_2.pi", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_1,
{ "Bit 1: READ", "s7comm.szl.0131.0006.zugtyp_2.read", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_2,
{ "Bit 2: WRITE", "s7comm.szl.0131.0006.zugtyp_2.write", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_3,
{ "Bit 3: LOAD", "s7comm.szl.0131.0006.zugtyp_2.load", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_4,
{ "Bit 4: LOAD_ME", "s7comm.szl.0131.0006.zugtyp_2.load_me", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_5,
{ "Bit 5: ALARM", "s7comm.szl.0131.0006.zugtyp_2.alarm", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_6,
{ "Bit 6: ALARM_8", "s7comm.szl.0131.0006.zugtyp_2.alarm_8", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_2_7,
{ "Bit 7: ALARM_8P", "s7comm.szl.0131.0006.zugtyp_2.alarm_8p", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3,
{ "zugtyp_3", "s7comm.szl.0131.0006.zugtyp_3", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_3 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_0,
{ "Bit 0: NOTIFY", "s7comm.szl.0131.0006.zugtyp_3.notify", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_1,
{ "Bit 1: AR_SEND", "s7comm.szl.0131.0006.zugtyp_3.ar_send", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_2,
{ "Bit 2: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit2_res", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_3,
{ "Bit 3: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit3_res", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_4,
{ "Bit 4: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_5,
{ "Bit 5: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_6,
{ "Bit 6: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_3_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0006.zugtyp_3.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_4,
{ "zugtyp_4", "s7comm.szl.0131.0006.zugtyp_4", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_4 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_5,
{ "zugtyp_5", "s7comm.szl.0131.0006.zugtyp_5", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_5 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6,
{ "zugtyp_6", "s7comm.szl.0131.0006.zugtyp_6", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_6 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_0,
{ "Bit 0: X_SEND", "s7comm.szl.0131.0006.zugtyp_6.x_send", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_1,
{ "Bit 1: X_RCV", "s7comm.szl.0131.0006.zugtyp_6.x_rcv", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_2,
{ "Bit 2: X_GET", "s7comm.szl.0131.0006.zugtyp_6.x_get", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_3,
{ "Bit 3: X_PUT", "s7comm.szl.0131.0006.zugtyp_6.x_put", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_4,
{ "Bit 4: X_ABORT", "s7comm.szl.0131.0006.zugtyp_6.x_abort", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_5,
{ "Bit 5: I_GET", "s7comm.szl.0131.0006.zugtyp_6.i_get", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_6,
{ "Bit 6: I_PUT", "s7comm.szl.0131.0006.zugtyp_6.i_put", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_6_7,
{ "Bit 7: I_ABORT", "s7comm.szl.0131.0006.zugtyp_6.i_abort", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7,
{ "zugtyp_7", "s7comm.szl.0131.0006.zugtyp_7", FT_UINT8, BASE_HEX, NULL, 0x0,
"zugtyp_7 (Permitted module types for fast reaction)", HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_0,
{ "Bit 0: SCAN_SND", "s7comm.szl.0131.0006.zugtyp_7.scan_snd", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_1,
{ "Bit 1: ALARM_SQ", "s7comm.szl.0131.0006.zugtyp_7.alarm_sq", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_2,
{ "Bit 2: ALARM_S", "s7comm.szl.0131.0006.zugtyp_7.alarm_s", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_3,
{ "Bit 3: ALARM_SC", "s7comm.szl.0131.0006.zugtyp_7.alarm_sc", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_4,
{ "Bit 4: EN_MSG", "s7comm.szl.0131.0006.zugtyp_7.en_msg", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_5,
{ "Bit 5: DIS_MSG", "s7comm.szl.0131.0006.zugtyp_7.dis_msg", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_6,
{ "Bit 6: CONTROL", "s7comm.szl.0131.0006.zugtyp_7.control", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_zugtyp_7_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0006.zugtyp_7.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_res1,
{ "res1 (Reserved)", "s7comm.szl.0131.0006.res1", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_max_sd_empf,
{ "max_sd_empf (Maximum number of send and receive parameters per block)", "s7comm.szl.0131.0006.max_sd_empf", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_max_sd_al8p,
{ "max_sd_al8p (Maximum number of send parameters for ALARM_8P)", "s7comm.szl.0131.0006.max_sd_al8p", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_max_inst,
{ "max_inst (Maximum number of instances for communication SFBs for configured connections)", "s7comm.szl.0131.0006.max_inst", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_res2,
{ "res2 (Reserved)", "s7comm.szl.0131.0006.res2", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_verb_proj,
{ "verb_proj (Connection configured (yes=1) possible)", "s7comm.szl.0131.0006.verb_proj", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_verb_prog,
{ "verb_prog (Connection programmed (yes=1) possible)", "s7comm.szl.0131.0006.verb_prog", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0006_res3,
{ "res3 (Reserved)", "s7comm.szl.0131.0006.res3", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0006(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_0,
ett_s7comm_szl_0131_0006_funkt_0, s7comm_szl_0131_0006_funkt_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_1,
ett_s7comm_szl_0131_0006_funkt_1, s7comm_szl_0131_0006_funkt_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_2,
ett_s7comm_szl_0131_0006_funkt_2, s7comm_szl_0131_0006_funkt_2_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_3,
ett_s7comm_szl_0131_0006_funkt_3, s7comm_szl_0131_0006_funkt_3_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_6,
ett_s7comm_szl_0131_0006_funkt_6, s7comm_szl_0131_0006_funkt_6_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_funkt_7,
ett_s7comm_szl_0131_0006_funkt_7, s7comm_szl_0131_0006_funkt_7_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_schnell, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_0,
ett_s7comm_szl_0131_0006_zugtyp_0, s7comm_szl_0131_0006_zugtyp_0_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_1,
ett_s7comm_szl_0131_0006_zugtyp_1, s7comm_szl_0131_0006_zugtyp_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_2,
ett_s7comm_szl_0131_0006_zugtyp_2, s7comm_szl_0131_0006_zugtyp_2_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_3,
ett_s7comm_szl_0131_0006_zugtyp_3, s7comm_szl_0131_0006_zugtyp_3_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_zugtyp_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_zugtyp_5, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_6,
ett_s7comm_szl_0131_0006_zugtyp_6, s7comm_szl_0131_0006_zugtyp_6_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0006_zugtyp_7,
ett_s7comm_szl_0131_0006_zugtyp_7, s7comm_szl_0131_0006_zugtyp_7_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_res1, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_max_sd_empf, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_max_sd_al8p, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_max_inst, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_res2, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_verb_proj, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_verb_prog, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_res3, tvb, offset, 10, ENC_NA);
offset += 10;
return offset;
}
static void
s7comm_szl_0131_0010_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0131_0010_index,
{ "Index", "s7comm.szl.0131.0010.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0010 Message parameter", HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1,
{ "funk_1", "s7comm.szl.0131.0010.funk_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Block types available for data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_0,
{ "Bit 0: Group status messages exist", "s7comm.szl.0131.0010.funk_1.grp_status_msg", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_1,
{ "Bit 1: Scan possible", "s7comm.szl.0131.0010.funk_1.scan_possible", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_2,
{ "Bit 2: NOTIFY, ALARM, ALARM_8P, ALARM_8, (multicast) possible", "s7comm.szl.0131.0010.funk_1.notify_alarm", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_3,
{ "Bit 3: Sending archive data possible", "s7comm.szl.0131.0010.funk_1.send_arc", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_4,
{ "Bit 4: Reserved", "s7comm.szl.0131.0010.funk_1.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_5,
{ "Bit 5: Reserved", "s7comm.szl.0131.0010.funk_1.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_6,
{ "Bit 6: Reserved", "s7comm.szl.0131.0010.funk_1.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_1_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0010.funk_1.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_funk_2,
{ "funk_2", "s7comm.szl.0131.0010.funk_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1,
{ "ber_meld_1", "s7comm.szl.0131.0010.ber_meld_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted address areas for messages (SCAN)", HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_0,
{ "Bit 0: PII", "s7comm.szl.0131.0010.ber_meld_1.pii", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_1,
{ "Bit 1: PIQ", "s7comm.szl.0131.0010.ber_meld_1.piq", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_2,
{ "Bit 2: M", "s7comm.szl.0131.0010.ber_meld_1.m", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_3,
{ "Bit 3: DB", "s7comm.szl.0131.0010.ber_meld_1.db", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_4,
{ "Bit 4: Reserved", "s7comm.szl.0131.0010.ber_meld_1.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_5,
{ "Bit 5: Reserved", "s7comm.szl.0131.0010.ber_meld_1.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_6,
{ "Bit 6: Reserved", "s7comm.szl.0131.0010.ber_meld_1.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_1_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0010.ber_meld_1.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_meld_2,
{ "ber_meld_2", "s7comm.szl.0131.0010.ber_meld_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1,
{ "ber_zus_1", "s7comm.szl.0131.0010.ber_zus_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted address areas for messages (SCAN)", HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_0,
{ "Bit 0: PII", "s7comm.szl.0131.0010.ber_zus_1.pii", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_1,
{ "Bit 1: PIQ", "s7comm.szl.0131.0010.ber_zus_1.piq", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_2,
{ "Bit 2: M", "s7comm.szl.0131.0010.ber_zus_1.m", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_3,
{ "Bit 3: DB", "s7comm.szl.0131.0010.ber_zus_1.db", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_4,
{ "Bit 4: Reserved", "s7comm.szl.0131.0010.ber_zus_1.bit4_res", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_5,
{ "Bit 5: Reserved", "s7comm.szl.0131.0010.ber_zus_1.bit5_res", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_6,
{ "Bit 6: Reserved", "s7comm.szl.0131.0010.ber_zus_1.bit6_res", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_1_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0010.ber_zus_1.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_ber_zus_2,
{ "ber_zus_2", "s7comm.szl.0131.0010.ber_zus_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1,
{ "typ_zus_1", "s7comm.szl.0131.0010.typ_zus_1", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permitted data types for additional values (SCAN)", HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_0,
{ "Bit 0: Bit", "s7comm.szl.0131.0010.typ_zus_1.bit", FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_1,
{ "Bit 1: Byte", "s7comm.szl.0131.0010.typ_zus_1.byte", FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_2,
{ "Bit 2: Word", "s7comm.szl.0131.0010.typ_zus_1.word", FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_3,
{ "Bit 3: DWord", "s7comm.szl.0131.0010.typ_zus_1.dword", FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_4,
{ "Bit 4: Timer", "s7comm.szl.0131.0010.typ_zus_1.timer", FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_5,
{ "Bit 5: Counter", "s7comm.szl.0131.0010.typ_zus_1.counter", FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_6,
{ "Bit 6: Array of char[16]", "s7comm.szl.0131.0010.typ_zus_1.array_char", FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_1_7,
{ "Bit 7: Reserved", "s7comm.szl.0131.0010.typ_zus_1.bit7_res", FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_typ_zus_2,
{ "typ_zus_2", "s7comm.szl.0131.0010.typ_zus_2", FT_UINT8, BASE_HEX, NULL, 0x0,
"Reserved", HFILL }},
{ &hf_s7comm_szl_0131_0010_maxanz_arch,
{ "maxanz_arch (Maximum number of archives for 'Send Archive')", "s7comm.szl.0132.0010.maxanz_arch", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0131_0010_res,
{ "res (Reserved)", "s7comm.szl.0131.0010.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0131_idx_0010(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0010_funk_1,
ett_s7comm_szl_0131_0010_funk_1, s7comm_szl_0131_0010_funk_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_funk_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0010_ber_meld_1,
ett_s7comm_szl_0131_0010_ber_meld_1, s7comm_szl_0131_0010_ber_meld_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_ber_meld_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0010_ber_zus_1,
ett_s7comm_szl_0131_0010_ber_zus_1, s7comm_szl_0131_0010_ber_zus_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_ber_zus_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0131_0010_typ_zus_1,
ett_s7comm_szl_0131_0010_typ_zus_1, s7comm_szl_0131_0010_typ_zus_1_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_typ_zus_2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_maxanz_arch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0131_0010_res, tvb, offset, 28, ENC_NA);
offset += 28;
return offset;
}
static void
s7comm_szl_0132_0001_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0132_0001_index,
{ "Index", "s7comm.szl.0132.0001.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0001: General status data for communication", HFILL }},
{ &hf_s7comm_szl_0132_0001_res_pg,
{ "res pg (Guaranteed number of PG connections)", "s7comm.szl.0132.0001.res_pg", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_res_os,
{ "res os (Guaranteed number of OS connections)", "s7comm.szl.0132.0001.res_os", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_u_pg,
{ "u pg (Current number of PG connections)", "s7comm.szl.0132.0001.u_pg", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_u_os,
{ "u os (Current number of OS connections)", "s7comm.szl.0132.0001.u_os", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_proj,
{ "proj (Current number of configured connections)", "s7comm.szl.0132.0001.proj", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_auf,
{ "auf (Current number of connections established by proj)", "s7comm.szl.0132.0001.auf", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_free,
{ "free (Number of free connections)", "s7comm.szl.0132.0001.free", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_used,
{ "used (Number of free connections used)", "s7comm.szl.0132.0001.used", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_last,
{ "last (Maximum selected communication load of the CPU in %)", "s7comm.szl.0132.0001.last", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0001_res,
{ "res (Reserved)", "s7comm.szl.0132.0001.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0132_idx_0001(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_res_pg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_res_os, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_u_pg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_u_os, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_proj, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_auf, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_free, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_used, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_last, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0001_res, tvb, offset, 10, ENC_NA);
offset += 10;
return offset;
}
static void
s7comm_szl_0132_0002_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0132_0002_index,
{ "Index", "s7comm.szl.0132.0002.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0002: Test and installation status", HFILL }},
{ &hf_s7comm_szl_0132_0002_anz,
{ "anz (Number of initialized test and installation jobs)", "s7comm.szl.0132.0002.anz", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0002_res,
{ "res (Reserved)", "s7comm.szl.0132.0002.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0132_idx_0002(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0132_0002_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0002_anz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0002_res, tvb, offset, 36, ENC_NA);
offset += 36;
return offset;
}
static void
s7comm_szl_0132_0004_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0132_0004_index,
{ "Index", "s7comm.szl.0132.0004.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0004 Protection status data", HFILL }},
{ &hf_s7comm_szl_0132_0004_key,
{ "key (Protection level for the key switch, possible values: 1,2 or 3)", "s7comm.szl.0132.0004.key", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0004_param,
{ "param (Assigned protection level (possible values: 0, 1, 2 or 3)", "s7comm.szl.0132.0004.param", FT_UINT16, BASE_DEC, NULL, 0x0,
"param (Assigned protection level (possible values: 0, 1, 2 or 3;0 means: no password assigned, assigned protection level is not valid)", HFILL }},
{ &hf_s7comm_szl_0132_0004_real,
{ "real (Valid protection level of the CPU, possible values: 1, 2 or 3)", "s7comm.szl.0132.0004.real", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0004_bart_sch,
{ "bart_sch (Position of the mode switch)", "s7comm.szl.0132.0004.bart_sch", FT_UINT16, BASE_DEC, VALS(szl_bart_sch_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0004_crst_wrst,
{ "crst_wrst (Setting of the CRST/WRST switch)", "s7comm.szl.0132.0004.crst_wrst", FT_UINT16, BASE_DEC, VALS(szl_crst_wrst_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0004_res,
{ "res (Reserved)", "s7comm.szl.0132.0004.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0132_idx_0004(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_key, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_param, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_real, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_bart_sch, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_crst_wrst, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0004_res, tvb, offset, 28, ENC_NA);
offset += 28;
return offset;
}
static void
s7comm_szl_0132_0005_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0132_0005_index,
{ "Index", "s7comm.szl.0132.0005.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0005: Diagnostics", HFILL }},
{ &hf_s7comm_szl_0132_0005_erw,
{ "erw (Extended functions)", "s7comm.szl.0132.0005.erw", FT_UINT16, BASE_DEC, VALS(szl_0132_0005_func_exist_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0005_send,
{ "send (Automatic sending)", "s7comm.szl.0132.0005.send", FT_UINT16, BASE_DEC, VALS(szl_0132_0005_func_exist_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0005_moeg,
{ "moeg (Sending user-defined diagnostic messages currently possible)", "s7comm.szl.0132.0005.moeg", FT_UINT16, BASE_DEC, VALS(szl_0132_0005_func_exist_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0005_ltmerz,
{ "ltmerz (Generation of status message active)", "s7comm.szl.0132.0005.ltmerz", FT_UINT16, BASE_DEC, VALS(szl_0132_0005_func_exist_names), 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0005_res,
{ "res (Reserved)", "s7comm.szl.0132.0005.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0132_idx_0005(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_erw, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_send, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_moeg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_ltmerz, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0005_res, tvb, offset, 30, ENC_NA);
offset += 30;
return offset;
}
static void
s7comm_szl_0132_0006_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0132_0006_index,
{ "Index", "s7comm.szl.0132.0006.index", FT_UINT16, BASE_HEX, NULL, 0x0,
"W#16#0006: Data exchange with communication SFBs for configured connections", HFILL }},
{ &hf_s7comm_szl_0132_0006_used_0,
{ "used_0 (Blocks used)", "s7comm.szl.0132.0006.used_0", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_1,
{ "used_1 (Blocks used)", "s7comm.szl.0132.0006.used_1", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_2,
{ "used_2 (Blocks used)", "s7comm.szl.0132.0006.used_2", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_3,
{ "used_3 (Blocks used)", "s7comm.szl.0132.0006.used_3", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_4,
{ "used_4 (Blocks used)", "s7comm.szl.0132.0006.used_4", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_5,
{ "used_5 (Blocks used)", "s7comm.szl.0132.0006.used_5", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_6,
{ "used_6 (Blocks used)", "s7comm.szl.0132.0006.used_6", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_used_7,
{ "used_7 (Blocks used)", "s7comm.szl.0132.0006.used_7", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_anz_schnell,
{ "anz_schnell (Reserved)", "s7comm.szl.0132.0006.anz_schnell", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_anz_inst,
{ "anz_inst (Number of loaded SFB instances)", "s7comm.szl.0132.0006.anz_inst", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_anz_multicast,
{ "anz_multicast (Number of blocks used for multicast)", "s7comm.szl.0132.0006.anz_multicast", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0132_0006_res,
{ "res (Reserved)", "s7comm.szl.0132.0006.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0132_idx_0006(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_0, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_0_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_1_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_2, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_2_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_3, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_3_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_4, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_5, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_6, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_6_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_used_7, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_0, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_3, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_0131_0006_funkt_7_7, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_anz_schnell, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_anz_inst, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_anz_multicast, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0132_0006_res, tvb, offset, 25, ENC_NA);
offset += 25;
return offset;
}
static void
s7comm_szl_xy74_0000_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_xy74_0000_cpu_led_id,
{ "cpu_led_id", "s7comm.szl.xy74.0000.cpu_led_id", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_xy74_0000_cpu_led_id_rackno,
{ "Bits 0, 1, 2: Rack number", "s7comm.szl.xy74.0000.cpu_led_id.rackno", FT_UINT16, BASE_DEC, NULL, 0x0700,
NULL, HFILL }},
{ &hf_s7comm_szl_xy74_0000_cpu_led_id_cputype,
{ "Bit 3: CPU Type (0=Standby, 1=Master)", "s7comm.szl.xy74.0000.cpu_led_id.cputype", FT_UINT16, BASE_DEC, NULL, 0x0800,
NULL, HFILL }},
{ &hf_s7comm_szl_xy74_0000_cpu_led_id_id,
{ "Byte 1: LED ID", "s7comm.szl.xy74.0000.cpu_led_id.id", FT_UINT16, BASE_DEC, VALS(szl_0174_index_names), 0x00ff,
NULL, HFILL }},
{ &hf_s7comm_szl_xy74_0000_led_on,
{ "Status of the LED", "s7comm.szl.xy74.0000.led_on", FT_UINT8, BASE_DEC, VALS(szl_xy74_0000_led_on_names), 0x00,
NULL, HFILL }},
{ &hf_s7comm_szl_xy74_0000_led_blink,
{ "Flashing status of the LED", "s7comm.szl.xy74.0000.led_blink", FT_UINT8, BASE_DEC, VALS(szl_xy74_0000_led_blink_names), 0x00,
NULL, HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_xy74_idx_0000(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_cpu_led_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_cpu_led_id_rackno, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_cpu_led_id_cputype, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_cpu_led_id_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_led_on, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_xy74_0000_led_blink, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static void
s7comm_szl_0424_0000_register(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_szl_0424_0000_ereig,
{ "ereig", "s7comm.szl.0424.0000.ereig", FT_UINT16, BASE_HEX, NULL, 0x0,
"Event ID", HFILL }},
{ &hf_s7comm_szl_0424_0000_ae,
{ "ae", "s7comm.szl.0424.0000.ereig", FT_UINT8, BASE_HEX, NULL, 0x0,
"ae (B#16#FF)", HFILL }},
{ &hf_s7comm_szl_0424_0000_bzu_id,
{ "bzu-id", "s7comm.szl.0424.0000.bzu_id", FT_UINT8, BASE_HEX, NULL, 0x0,
"bzu-id (ID of the mode change divided into 4 bits, Bit 0 to 3: Requested mode, Bit 4 to 7: Previous mode", HFILL }},
{ &hf_s7comm_szl_0424_0000_bzu_id_req,
{ "Requested mode", "s7comm.szl.0424.0000.bzu_id.req", FT_UINT8, BASE_HEX, VALS(szl_0424_0000_bzu_id_names), 0x0f,
"bzu-id Requested mode", HFILL }},
{ &hf_s7comm_szl_0424_0000_bzu_id_pre,
{ "Previous mode", "s7comm.szl.0424.0000.bzu_id.pre", FT_UINT8, BASE_HEX, VALS(szl_0424_0000_bzu_id_names), 0xf0,
"bzu-id Previous mode", HFILL }},
{ &hf_s7comm_szl_0424_0000_res,
{ "res (Reserved)", "s7comm.szl.0424.0000.res", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0424_0000_anlinfo1,
{ "anlinfo1", "s7comm.szl.0424.0000.anlinfo1", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_szl_0424_0000_anlinfo2,
{ "anlinfo2", "s7comm.szl.0424.0000.anlinfo2", FT_UINT8, BASE_HEX, VALS(szl_0424_0000_anlinfo2_names), 0x0,
"Type of startup just exceeded", HFILL }},
{ &hf_s7comm_szl_0424_0000_anlinfo3,
{ "anlinfo3", "s7comm.szl.0424.0000.anlinfo3", FT_UINT8, BASE_HEX, NULL, 0x0,
"Permissibility of startup types", HFILL }},
{ &hf_s7comm_szl_0424_0000_anlinfo4,
{ "anlinfo4", "s7comm.szl.0424.0000.anlinfo4", FT_UINT8, BASE_HEX, VALS(szl_0424_0000_anlinfo4_names), 0x0,
"Last valid operation or setting of the automatic startup type at power on", HFILL }},
{ &hf_s7comm_szl_0424_0000_time,
{ "time", "s7comm.szl.0424.0000.time", FT_BYTES, BASE_NONE, NULL, 0x0,
"time (Time stamp)", HFILL }},
};
proto_register_field_array(proto, hf, array_length(hf));
}
static guint32
s7comm_decode_szl_id_0424_idx_0000(tvbuff_t *tvb,
proto_tree *tree,
guint32 offset)
{
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_ereig, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_ae, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_bitmask(tree, tvb, offset, hf_s7comm_szl_0424_0000_bzu_id,
ett_s7comm_szl_0424_0000_bzu_id, s7comm_szl_0424_0000_bzu_id_fields, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_res, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_anlinfo1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_anlinfo2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_anlinfo3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_anlinfo4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_s7comm_szl_0424_0000_time, tvb, offset, 8, ENC_NA);
offset += 8;
return offset;
}
void
s7comm_register_szl_types(int proto)
{
static hf_register_info hf[] = {
{ &hf_s7comm_userdata_szl_partial_list,
{ "SZL partial list data", "s7comm.param.userdata.szl_part_list", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_id,
{ "SZL-ID", "s7comm.data.userdata.szl_id", FT_UINT16, BASE_HEX, NULL, 0x0,
"SZL-ID (System Status List) Bits 15-12: Diagnostic type, Bits 11-8: Number of the partial list extract, Bits 7-0: Number of the partial list", HFILL }},
{ &hf_s7comm_userdata_szl_id_type,
{ "Diagnostic type", "s7comm.data.userdata.szl_id.diag_type", FT_UINT16, BASE_HEX, VALS(szl_module_type_names), 0xf000,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_id_partlist_ex,
{ "Number of the partial list extract", "s7comm.data.userdata.szl_id.partlist_ex", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &szl_id_partlist_ex_names_ext, 0xffff,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_id_partlist_num,
{ "Number of the partial list", "s7comm.data.userdata.szl_id.partlist_num", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &szl_partial_list_names_ext, 0x00ff,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_index,
{ "SZL-Index", "s7comm.data.userdata.szl_index", FT_UINT16, BASE_HEX, NULL, 0x0,
"SZL-Index (System Status List)", HFILL }},
{ &hf_s7comm_userdata_szl_tree,
{ "SZL data tree", "s7comm.data.userdata.szl_data_tree", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_id_partlist_len,
{ "SZL partial list length in bytes", "s7comm.data.userdata.szl_id.partlist_len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_s7comm_userdata_szl_id_partlist_cnt,
{ "SZL partial list count", "s7comm.data.userdata.szl_id.partlist_cnt", FT_UINT16, BASE_DEC, NULL, 0x0,
"SZL partial list count: the number of datasets in the results", HFILL }},
{ &hf_s7comm_userdata_szl_data,
{ "SZL data", "s7comm.param.userdata.szl_data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_s7comm_szl,
&ett_s7comm_userdata_szl_id,
&ett_s7comm_szl_0131_0002_funkt_0,
&ett_s7comm_szl_0131_0002_funkt_1,
&ett_s7comm_szl_0131_0002_funkt_2,
&ett_s7comm_szl_0131_0002_trgereig_0,
&ett_s7comm_szl_0131_0002_trgereig_1,
&ett_s7comm_szl_0131_0003_funkt_0,
&ett_s7comm_szl_0131_0003_funkt_1,
&ett_s7comm_szl_0131_0003_funkt_2,
&ett_s7comm_szl_0131_0003_funkt_3,
&ett_s7comm_szl_0131_0004_funkt_0,
&ett_s7comm_szl_0131_0004_funkt_1,
&ett_s7comm_szl_0131_0004_funkt_2,
&ett_s7comm_szl_0131_0004_funkt_3,
&ett_s7comm_szl_0131_0004_funkt_4,
&ett_s7comm_szl_0131_0006_funkt_0,
&ett_s7comm_szl_0131_0006_funkt_1,
&ett_s7comm_szl_0131_0006_funkt_2,
&ett_s7comm_szl_0131_0006_funkt_3,
&ett_s7comm_szl_0131_0006_funkt_6,
&ett_s7comm_szl_0131_0006_funkt_7,
&ett_s7comm_szl_0131_0006_zugtyp_0,
&ett_s7comm_szl_0131_0006_zugtyp_1,
&ett_s7comm_szl_0131_0006_zugtyp_2,
&ett_s7comm_szl_0131_0006_zugtyp_3,
&ett_s7comm_szl_0131_0006_zugtyp_6,
&ett_s7comm_szl_0131_0006_zugtyp_7,
&ett_s7comm_szl_0131_0010_funk_1,
&ett_s7comm_szl_0131_0010_ber_meld_1,
&ett_s7comm_szl_0131_0010_ber_zus_1,
&ett_s7comm_szl_0131_0010_typ_zus_1,
&ett_s7comm_szl_0424_0000_bzu_id,
};
proto_register_subtree_array(ett, array_length (ett));
proto_register_field_array(proto, hf, array_length(hf));
s7comm_szl_0000_0000_register(proto);
s7comm_szl_0013_0000_register(proto);
s7comm_szl_xy11_0001_register(proto);
s7comm_szl_0131_0001_register(proto);
s7comm_szl_0131_0002_register(proto);
s7comm_szl_0131_0003_register(proto);
s7comm_szl_0131_0004_register(proto);
s7comm_szl_0131_0006_register(proto);
s7comm_szl_0131_0010_register(proto);
s7comm_szl_0132_0001_register(proto);
s7comm_szl_0132_0002_register(proto);
s7comm_szl_0132_0004_register(proto);
s7comm_szl_0132_0005_register(proto);
s7comm_szl_0132_0006_register(proto);
s7comm_szl_xy74_0000_register(proto);
s7comm_szl_0424_0000_register(proto);
}
guint32
s7comm_decode_ud_cpu_szl_subfunc(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *data_tree,
guint8 type,
guint8 ret_val,
guint16 len,
guint16 dlength,
guint8 data_unit_ref,
guint8 last_data_unit,
guint32 offset)
{
guint16 id;
guint16 idx;
guint16 list_len;
guint16 list_count;
guint16 i;
guint16 tbytes = 0;
proto_item *szl_item = NULL;
proto_tree *szl_item_tree = NULL;
proto_item *szl_item_entry = NULL;
const gchar* szl_index_description;
gboolean know_data = FALSE;
gboolean szl_decoded = FALSE;
if (type == S7COMM_UD_TYPE_REQ) {
id = tvb_get_ntohs(tvb, offset);
proto_tree_add_bitmask(data_tree, tvb, offset, hf_s7comm_userdata_szl_id,
ett_s7comm_userdata_szl_id, s7comm_userdata_szl_id_fields, ENC_BIG_ENDIAN);
offset += 2;
idx = tvb_get_ntohs(tvb, offset);
szl_item_entry = proto_tree_add_item(data_tree, hf_s7comm_userdata_szl_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
szl_index_description = s7comm_get_szl_id_index_description_text(id, idx);
if (szl_index_description != NULL) {
proto_item_append_text(szl_item_entry, " [%s]", szl_index_description);
}
proto_item_append_text(data_tree, " (SZL-ID: 0x%04x, Index: 0x%04x)", id, idx);
col_append_fstr(pinfo->cinfo, COL_INFO, " ID=0x%04x Index=0x%04x" , id, idx);
know_data = TRUE;
} else if (type == S7COMM_UD_TYPE_RES) {
if (ret_val == S7COMM_ITEM_RETVAL_DATA_OK) {
if (data_unit_ref != 0 && last_data_unit == 0) {
szl_item = proto_tree_add_item(data_tree, hf_s7comm_userdata_szl_tree, tvb, offset, len, ENC_NA);
szl_item_tree = proto_item_add_subtree(szl_item, ett_s7comm_szl);
proto_item_append_text(szl_item, " [Fragment, continuation of previous data]");
proto_tree_add_bytes(szl_item_tree, hf_s7comm_userdata_szl_data, tvb, offset, len,
tvb_get_ptr (tvb, offset, len));
offset += len;
col_append_fstr(pinfo->cinfo, COL_INFO, " SZL data fragment");
} else {
id = tvb_get_ntohs(tvb, offset);
proto_tree_add_bitmask(data_tree, tvb, offset, hf_s7comm_userdata_szl_id,
ett_s7comm_userdata_szl_id, s7comm_userdata_szl_id_fields, ENC_BIG_ENDIAN);
offset += 2;
idx = tvb_get_ntohs(tvb, offset);
szl_item_entry = proto_tree_add_item(data_tree, hf_s7comm_userdata_szl_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
szl_index_description = s7comm_get_szl_id_index_description_text(id, idx);
if (szl_index_description != NULL) {
proto_item_append_text(szl_item_entry, " [%s]", szl_index_description);
}
proto_item_append_text(data_tree, " (SZL-ID: 0x%04x, Index: 0x%04x)", id, idx);
col_append_fstr(pinfo->cinfo, COL_INFO, " ID=0x%04x Index=0x%04x" , id, idx);
list_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_userdata_szl_id_partlist_len, tvb, offset, 2, list_len);
offset += 2;
list_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(data_tree, hf_s7comm_userdata_szl_id_partlist_cnt, tvb, offset, 2, list_count);
tbytes = 0;
if ((list_count * list_len) > (len - 8)) {
list_count = (len - 8) / list_len;
if (list_count > 0) {
tbytes = (len - 8) % list_count;
}
}
offset += 2;
if (len > 8) {
for (i = 1; i <= list_count; i++) {
szl_item = proto_tree_add_item(data_tree, hf_s7comm_userdata_szl_tree, tvb, offset, list_len, ENC_NA);
szl_item_tree = proto_item_add_subtree(szl_item, ett_s7comm_szl);
proto_item_append_text(szl_item, " (list count no. %d)", i);
szl_decoded = FALSE;
switch (id) {
case 0x0000:
offset = s7comm_decode_szl_id_xy00(tvb, szl_item_tree, id, idx, offset);
szl_decoded = TRUE;
break;
case 0x0013:
if (idx == 0x0000) {
offset = s7comm_decode_szl_id_0013_idx_0000(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
}
break;
case 0x0011:
case 0x0111:
if ((idx == 0x0001) || (idx == 0x0000)) {
offset = s7comm_decode_szl_id_0111_idx_0001(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
}
break;
case 0x0131:
if (idx == 0x0001) {
offset = s7comm_decode_szl_id_0131_idx_0001(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0002) {
offset = s7comm_decode_szl_id_0131_idx_0002(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0003) {
offset = s7comm_decode_szl_id_0131_idx_0003(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0004) {
offset = s7comm_decode_szl_id_0131_idx_0004(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0006) {
offset = s7comm_decode_szl_id_0131_idx_0006(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0010) {
offset = s7comm_decode_szl_id_0131_idx_0010(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
}
break;
case 0x0132:
if (idx == 0x0001) {
offset = s7comm_decode_szl_id_0132_idx_0001(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0002) {
offset = s7comm_decode_szl_id_0132_idx_0002(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0004) {
offset = s7comm_decode_szl_id_0132_idx_0004(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0005) {
offset = s7comm_decode_szl_id_0132_idx_0005(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
} else if (idx == 0x0006) {
offset = s7comm_decode_szl_id_0132_idx_0006(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
}
break;
case 0x0019:
case 0x0119:
case 0x0074:
case 0x0174:
offset = s7comm_decode_szl_id_xy74_idx_0000(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
break;
case 0x0124:
case 0x0424:
if (idx == 0x0000) {
offset = s7comm_decode_szl_id_0424_idx_0000(tvb, szl_item_tree, offset);
szl_decoded = TRUE;
}
break;
default:
szl_decoded = FALSE;
break;
}
if (szl_decoded == FALSE) {
proto_tree_add_bytes(szl_item_tree, hf_s7comm_userdata_szl_partial_list, tvb, offset, list_len,
tvb_get_ptr (tvb, offset, list_len));
offset += list_len;
}
}
}
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, " Return value:[%s]", val_to_str(ret_val, s7comm_item_return_valuenames, "Unknown return value:0x%02x"));
}
know_data = TRUE;
}
if (know_data == TRUE && tbytes > 0) {
szl_item = proto_tree_add_item(data_tree, hf_s7comm_userdata_szl_tree, tvb, offset, tbytes, ENC_NA);
szl_item_tree = proto_item_add_subtree(szl_item, ett_s7comm_szl);
proto_item_append_text(szl_item, " [Fragment, complete response doesn't fit one PDU]");
proto_tree_add_bytes(szl_item_tree, hf_s7comm_userdata_szl_data, tvb, offset, tbytes,
tvb_get_ptr (tvb, offset, tbytes));
offset += tbytes;
}
if (know_data == FALSE && dlength > 4) {
proto_tree_add_bytes(data_tree, hf_s7comm_userdata_szl_data, tvb, offset, dlength - 4,
tvb_get_ptr (tvb, offset, dlength - 4));
offset += dlength;
}
return offset;
}
