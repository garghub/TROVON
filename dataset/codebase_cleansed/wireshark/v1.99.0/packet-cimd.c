static void dissect_cimd_parameter(tvbuff_t *tvb, proto_tree *tree, gint pindex, gint startOffset, gint endOffset)
{
proto_tree *param_tree;
param_tree = proto_tree_add_subtree(tree, tvb, startOffset + 1, endOffset - (startOffset + 1),
(*vals_hdr_PC[pindex].ett_p), NULL, cimd_vals_PC[pindex].strptr);
proto_tree_add_item(param_tree, hf_cimd_pcode_indicator, tvb,
startOffset + 1, CIMD_PC_LENGTH, ENC_ASCII|ENC_NA);
proto_tree_add_item(param_tree, (*vals_hdr_PC[pindex].hf_p), tvb,
startOffset + 1 + CIMD_PC_LENGTH + 1, endOffset - (startOffset + 1 + CIMD_PC_LENGTH + 1), ENC_ASCII|ENC_NA);
}
static void dissect_cimd_ud(tvbuff_t *tvb, proto_tree *tree, gint pindex, gint startOffset, gint endOffset)
{
proto_tree *param_tree;
gchar *payloadText, *tmpBuffer, *tmpBuffer1;
int loop,i,poz, bufPoz = 0, bufPoz1 = 0, size, size1, resch;
gint g_offset, g_size;
gchar token[4];
gchar ch;
static const char* mapping[128] = {
"_Oa" , "_L-", "" , "_Y-", "_e`", "_e'", "_u`", "_i`", "_o`", "_C,",
"" , "_O/", "_o/" , "" , "_A*", "_a*", "_gd", "_--", "_gf", "_gg", "_gl",
"_go" , "_gp", "_gi" , "_gs", "_gt", "_gx", "_XX", "_AE", "_ae", "_ss", "_E'",
"" , "" , "_qq" , "" , "_ox", "" , "" , "" , "" , "" , "" , "" , "" , "" , "", "",
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "", "",
"_!!" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "", "",
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "_A\"", "_O\"", "_N~",
"_U\"", "_so", "_??" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "", "_a\"",
"_o\"", "_n~", "_n\"","_a`"
};
param_tree = proto_tree_add_subtree(tree, tvb,
startOffset + 1, endOffset - (startOffset + 1),
(*vals_hdr_PC[pindex].ett_p), NULL, cimd_vals_PC[pindex].strptr
);
proto_tree_add_item(param_tree, hf_cimd_pcode_indicator, tvb,
startOffset + 1, CIMD_PC_LENGTH, ENC_ASCII|ENC_NA);
g_offset = startOffset + 1 + CIMD_PC_LENGTH + 1;
g_size = endOffset - g_offset;
payloadText = tvb_format_text(tvb, g_offset, g_size);
size = (int)strlen(payloadText);
tmpBuffer = (gchar*)wmem_alloc(wmem_packet_scope(), size+1);
for (loop = 0; loop < size; loop++)
{
if (payloadText[loop] == '_')
{
if (loop < size - 2)
{
token[0] = payloadText[loop++];
token[1] = payloadText[loop++];
token[2] = payloadText[loop];
token[3] = '\0';
poz = -1;
for (i = 0; i < 128; i++)
{
if (strcmp(token, mapping[i]) == 0)
{
poz = i;
break;
}
}
if (poz > 0)
{
tmpBuffer[bufPoz++] = poz;
}
else
{
tmpBuffer[bufPoz++] = payloadText[loop-2];
tmpBuffer[bufPoz++] = payloadText[loop-1];
tmpBuffer[bufPoz++] = payloadText[loop];
}
}
else
{
if (loop < size) tmpBuffer[bufPoz++] = payloadText[loop++];
if (loop < size) tmpBuffer[bufPoz++] = payloadText[loop++];
if (loop < size) tmpBuffer[bufPoz++] = payloadText[loop++];
}
}
else
{
tmpBuffer[bufPoz++] = payloadText[loop];
}
}
tmpBuffer[bufPoz] = '\0';
size1 = (int)strlen(tmpBuffer);
tmpBuffer1 = (gchar*)wmem_alloc(wmem_packet_scope(), size1+1);
for (loop=0; loop<size1; loop++)
{
ch = tmpBuffer[loop];
switch ((gint)ch)
{
case 0x40: resch = 0x0040; break;
case 0x01: resch = 0x00A3; break;
case 0x02: resch = 0x0024; break;
case 0x03: resch = 0x00A5; break;
case 0x04: resch = 0x00E8; break;
case 0x05: resch = 0x00E9; break;
case 0x06: resch = 0x00F9; break;
case 0x07: resch = 0x00EC; break;
case 0x08: resch = 0x00F2; break;
case 0x09: resch = 0x00E7; break;
case 0x0B: resch = 0x00D8; break;
case 0x0C: resch = 0x00F8; break;
case 0x0E: resch = 0x00C5; break;
case 0x0F: resch = 0x00E5; break;
case 0x11: resch = 0x005F; break;
case 0x1C: resch = 0x00C6; break;
case 0x1D: resch = 0x00E6; break;
case 0x1E: resch = 0x00DF; break;
case 0x1F: resch = 0x00C9; break;
case 0x20: resch = 0x0020; break;
case 0x21: resch = 0x0021; break;
case 0x22: resch = 0x0022; break;
case 0x23: resch = 0x0023; break;
case 0xA4: resch = 0x00A4; break;
case 0x25: resch = 0x0025; break;
case 0x26: resch = 0x0026; break;
case 0x27: resch = 0x0027; break;
case 0x28: resch = 0x0028; break;
case 0x29: resch = 0x0029; break;
case 0x2A: resch = 0x002A; break;
case 0x2B: resch = 0x002B; break;
case 0x2C: resch = 0x002C; break;
case 0x2D: resch = 0x002D; break;
case 0x2E: resch = 0x002E; break;
case 0x2F: resch = 0x002F; break;
case 0x30: resch = 0x0030; break;
case 0x31: resch = 0x0031; break;
case 0x32: resch = 0x0032; break;
case 0x33: resch = 0x0033; break;
case 0x34: resch = 0x0034; break;
case 0x35: resch = 0x0035; break;
case 0x36: resch = 0x0036; break;
case 0x37: resch = 0x0037; break;
case 0x38: resch = 0x0038; break;
case 0x39: resch = 0x0039; break;
case 0x3A: resch = 0x003A; break;
case 0x3B: resch = 0x003B; break;
case 0x3C: resch = 0x003C; break;
case 0x3D: resch = 0x003D; break;
case 0x3E: resch = 0x003E; break;
case 0x3F: resch = 0x003F; break;
case 0x41: resch = 0x0041; break;
case 0x42: resch = 0x0042; break;
case 0x43: resch = 0x0043; break;
case 0x44: resch = 0x0044; break;
case 0x45: resch = 0x0045; break;
case 0x46: resch = 0x0046; break;
case 0x47: resch = 0x0047; break;
case 0x48: resch = 0x0048; break;
case 0x49: resch = 0x0049; break;
case 0x4A: resch = 0x004A; break;
case 0x4B: resch = 0x004B; break;
case 0x4C: resch = 0x004C; break;
case 0x4D: resch = 0x004D; break;
case 0x4E: resch = 0x004E; break;
case 0x4F: resch = 0x004F; break;
case 0x50: resch = 0x0050; break;
case 0x51: resch = 0x0051; break;
case 0x52: resch = 0x0052; break;
case 0x53: resch = 0x0053; break;
case 0x54: resch = 0x0054; break;
case 0x55: resch = 0x0055; break;
case 0x56: resch = 0x0056; break;
case 0x57: resch = 0x0057; break;
case 0x58: resch = 0x0058; break;
case 0x59: resch = 0x0059; break;
case 0x5A: resch = 0x005A; break;
case 0x5B: resch = 0x00C4; break;
case 0x5C: resch = 0x00D6; break;
case 0x5D: resch = 0x00D1; break;
case 0x5E: resch = 0x00DC; break;
case 0x5F: resch = 0x00A7; break;
case 0x60: resch = 0x00BF; break;
case 0x61: resch = 0x0061; break;
case 0x62: resch = 0x0062; break;
case 0x63: resch = 0x0063; break;
case 0x64: resch = 0x0064; break;
case 0x65: resch = 0x0065; break;
case 0x66: resch = 0x0066; break;
case 0x67: resch = 0x0067; break;
case 0x68: resch = 0x0068; break;
case 0x69: resch = 0x0069; break;
case 0x6A: resch = 0x006A; break;
case 0x6B: resch = 0x006B; break;
case 0x6C: resch = 0x006C; break;
case 0x6D: resch = 0x006D; break;
case 0x6E: resch = 0x006E; break;
case 0x6F: resch = 0x006F; break;
case 0x70: resch = 0x0070; break;
case 0x71: resch = 0x0071; break;
case 0x72: resch = 0x0072; break;
case 0x73: resch = 0x0073; break;
case 0x74: resch = 0x0074; break;
case 0x75: resch = 0x0075; break;
case 0x76: resch = 0x0076; break;
case 0x77: resch = 0x0077; break;
case 0x78: resch = 0x0078; break;
case 0x79: resch = 0x0079; break;
case 0x7A: resch = 0x007A; break;
case 0x7B: resch = 0x00E4; break;
case 0x7C: resch = 0x00F6; break;
case 0x7D: resch = 0x00F1; break;
case 0x7F: resch = 0x00E0; break;
default:resch = ch; break;
}
tmpBuffer1[bufPoz1++] = (gchar)resch;
}
tmpBuffer1[bufPoz1] = '\0';
proto_tree_add_string(param_tree, (*vals_hdr_PC[pindex].hf_p), tvb, g_offset, g_size, tmpBuffer1);
}
static void dissect_cimd_dcs(tvbuff_t *tvb, proto_tree *tree, gint pindex, gint startOffset, gint endOffset)
{
proto_tree *param_tree;
gint offset;
guint32 dcs;
guint32 dcs_cg;
param_tree = proto_tree_add_subtree(tree, tvb,
startOffset + 1, endOffset - (startOffset + 1),
(*vals_hdr_PC[pindex].ett_p), NULL, cimd_vals_PC[pindex].strptr
);
proto_tree_add_item(param_tree, hf_cimd_pcode_indicator, tvb,
startOffset + 1, CIMD_PC_LENGTH, ENC_ASCII|ENC_NA);
offset = startOffset + 1 + CIMD_PC_LENGTH + 1;
dcs = (guint32) strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, offset, endOffset - offset, ENC_ASCII), NULL, 10);
proto_tree_add_uint(param_tree, (*vals_hdr_PC[pindex].hf_p), tvb, offset, endOffset - offset, dcs);
dcs_cg = (dcs & 0xF0) >> 4;
if (dcs_cg <= 0x07)
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_coding_group_indicatorC0, tvb, offset, 1, dcs);
}
else
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_coding_group_indicatorF0, tvb, offset, 1, dcs);
}
if (dcs_cg <= 0x07)
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_compressed_indicator, tvb, offset, 1, dcs);
proto_tree_add_uint(param_tree, hf_cimd_dcs_message_class_meaning_indicator, tvb, offset, 1, dcs);
proto_tree_add_uint(param_tree, hf_cimd_dcs_character_set_indicator0C, tvb, offset, 1, dcs);
if (dcs & 0x10)
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_message_class_indicator, tvb, offset, 1, dcs);
}
}
else if (dcs_cg >= 0x0C && dcs_cg <= 0x0E)
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_indication_sense, tvb, offset, 1, dcs);
proto_tree_add_uint(param_tree, hf_cimd_dcs_indication_type, tvb, offset, 1, dcs);
}
else if (dcs_cg == 0x0F)
{
proto_tree_add_uint(param_tree, hf_cimd_dcs_character_set_indicator04, tvb, offset, 1, dcs);
proto_tree_add_uint(param_tree, hf_cimd_dcs_message_class_indicator, tvb, offset, 1, dcs);
}
}
static void dissect_cimd_error_code( tvbuff_t *tvb, proto_tree *tree, gint pindex, gint startOffset, gint endOffset )
{
proto_tree *param_tree;
guint32 err_code;
param_tree = proto_tree_add_subtree(tree, tvb, startOffset + 1, endOffset - (startOffset + 1),
(*vals_hdr_PC[pindex].ett_p), NULL, cimd_vals_PC[pindex].strptr);
proto_tree_add_item(param_tree, hf_cimd_pcode_indicator, tvb, startOffset + 1, CIMD_PC_LENGTH, ENC_ASCII|ENC_NA);
err_code = (guint32) strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb,
startOffset + 1 + CIMD_PC_LENGTH + 1, endOffset - (startOffset + 1 + CIMD_PC_LENGTH + 1), ENC_ASCII),
NULL, 10);
proto_tree_add_uint(param_tree, (*vals_hdr_PC[pindex].hf_p), tvb, startOffset + 1 + CIMD_PC_LENGTH + 1, endOffset - (startOffset + 1 + CIMD_PC_LENGTH + 1), err_code);
}
static void
dissect_cimd_operation(tvbuff_t *tvb, proto_tree *tree, gint etxp, guint16 checksum, guint8 last1,guint8 OC, guint8 PN)
{
guint32 PC = 0;
gint idx;
gint offset = 0;
gint endOffset = 0;
proto_item *cimd_item;
proto_tree *cimd_tree;
cimd_item = proto_tree_add_item(tree, proto_cimd, tvb, 0, etxp + 1, ENC_NA);
cimd_tree = proto_item_add_subtree(cimd_item, ett_cimd);
proto_tree_add_uint(cimd_tree, hf_cimd_opcode_indicator, tvb, CIMD_OC_OFFSET, CIMD_OC_LENGTH, OC);
proto_tree_add_uint(cimd_tree, hf_cimd_packet_number_indicator, tvb, CIMD_PN_OFFSET, CIMD_PN_LENGTH, PN);
offset = CIMD_PN_OFFSET + CIMD_PN_LENGTH;
while (offset < etxp && tvb_get_guint8(tvb, offset) == CIMD_DELIM)
{
endOffset = tvb_find_guint8(tvb, offset + 1, etxp, CIMD_DELIM);
if (endOffset == -1)
break;
PC = (guint32) strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, offset + 1, CIMD_PC_LENGTH, ENC_ASCII), NULL, 10);
try_val_to_str_idx(PC, cimd_vals_PC, &idx);
if (idx != -1 && tree)
{
(vals_hdr_PC[idx].diss)(tvb, cimd_tree, idx, offset, endOffset);
}
offset = endOffset;
}
if (last1 != CIMD_DELIM)
{
proto_tree_add_uint(cimd_tree, hf_cimd_checksum_indicator, tvb, etxp - 2, 2, checksum);
}
}
static void
dissect_cimd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 OC;
guint8 PN;
guint16 checksum = 0;
guint16 pkt_check = 0;
gint etxp = 0;
gint offset = 0;
gboolean checksumIsValid = TRUE;
guint8 last1, last2, last3;
etxp = tvb_find_guint8(tvb, CIMD_PN_OFFSET + CIMD_PN_LENGTH, -1, CIMD_ETX);
if (etxp == -1) return;
OC = (guint8)strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, CIMD_OC_OFFSET, CIMD_OC_LENGTH, ENC_ASCII), NULL, 10);
PN = (guint8)strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, CIMD_PN_OFFSET, CIMD_PN_LENGTH, ENC_ASCII), NULL, 10);
last1 = tvb_get_guint8(tvb, etxp - 1);
last2 = tvb_get_guint8(tvb, etxp - 2);
last3 = tvb_get_guint8(tvb, etxp - 3);
if (last1 == CIMD_DELIM) {
} else if (last1 != CIMD_DELIM && last2 != CIMD_DELIM && last3 == CIMD_DELIM) {
checksum = (guint16)strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, etxp - 2, 2, ENC_ASCII), NULL, 16);
for (; offset < (etxp - 2); offset++)
{
pkt_check += tvb_get_guint8(tvb, offset);
pkt_check &= 0xFF;
}
checksumIsValid = (checksum == pkt_check);
} else {
checksumIsValid = FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIMD");
if (checksumIsValid)
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(OC, vals_hdr_OC, "Unknown (%d)"));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%s - %s", val_to_str(OC, vals_hdr_OC, "Unknown (%d)"), "invalid checksum");
dissect_cimd_operation(tvb, tree, etxp, checksum, last1, OC, PN);
}
static gboolean
dissect_cimd_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int etxp;
guint8 opcode = 0;
if (tvb_length(tvb) < CIMD_MIN_LENGTH)
return FALSE;
if (tvb_get_guint8(tvb, 0) != CIMD_STX)
return FALSE;
etxp = tvb_find_guint8(tvb, CIMD_OC_OFFSET, -1, CIMD_ETX);
if (etxp == -1)
{
return FALSE;
}
opcode = (guint8)strtoul(tvb_get_string_enc(wmem_packet_scope(), tvb, CIMD_OC_OFFSET, CIMD_OC_LENGTH, ENC_ASCII), NULL, 10);
if (try_val_to_str(opcode, vals_hdr_OC) == NULL)
return FALSE;
if (tvb_get_guint8(tvb, CIMD_OC_OFFSET + CIMD_OC_LENGTH) != CIMD_COLON)
return FALSE;
if (tvb_get_guint8(tvb, CIMD_PN_OFFSET + CIMD_PN_LENGTH) != CIMD_DELIM)
return FALSE;
dissect_cimd(tvb, pinfo, tree);
return TRUE;
}
void
proto_register_cimd(void)
{
static hf_register_info hf[] = {
{ &hf_cimd_opcode_indicator,
{ "Operation Code", "cimd.opcode",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cimd_packet_number_indicator,
{ "Packet Number", "cimd.pnumber",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cimd_pcode_indicator,
{ "Parameter Code", "cimd.pcode",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cimd_checksum_indicator,
{ "Checksum", "cimd.chksum",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cimd_dcs_coding_group_indicatorC0,
{ "DCS Coding Group", "cimd.dcs.cg",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_coding_groups), 0xC0,
NULL, HFILL }
},
{ &hf_cimd_dcs_coding_group_indicatorF0,
{ "DCS Coding Group", "cimd.dcs.cg",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_coding_groups), 0xF0,
NULL, HFILL }
},
{ &hf_cimd_dcs_compressed_indicator,
{ "DCS Compressed Flag", "cimd.dcs.cf",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_compressed), 0x20,
NULL, HFILL }
},
{ &hf_cimd_dcs_message_class_meaning_indicator,
{ "DCS Message Class Meaning", "cimd.dcs.mcm",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_message_class_meaning), 0x10,
NULL, HFILL }
},
{ &hf_cimd_dcs_message_class_indicator,
{ "DCS Message Class", "cimd.dcs.mc",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_message_class), 0x03,
NULL, HFILL }
},
{ &hf_cimd_dcs_character_set_indicator0C,
{ "DCS Character Set", "cimd.dcs.chs",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_character_set), 0x0C,
NULL, HFILL }
},
{ &hf_cimd_dcs_character_set_indicator04,
{ "DCS Character Set", "cimd.dcs.chs",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_character_set), 0x04,
NULL, HFILL }
},
{ &hf_cimd_dcs_indication_sense,
{ "DCS Indication Sense", "cimd.dcs.is",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_indication_sense), 0x04,
NULL, HFILL }
},
{ &hf_cimd_dcs_indication_type,
{ "DCS Indication Type", "cimd.dcs.it",
FT_UINT8, BASE_DEC, VALS(cimd_dcs_indication_type), 0x03,
NULL, HFILL }
},
{ &hf_index[0],
{ "User Identity", "cimd.ui",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[1],
{ "Password", "cimd.passwd",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[2],
{ "Subaddress", "cimd.saddr",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[3],
{ "Window Size", "cimd.ws",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[4],
{ "Destination Address", "cimd.da",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[5],
{ "Originating Address", "cimd.oa",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[6],
{ "Originating IMSI", "cimd.oimsi",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[7],
{ "Alphanumeric Originating Address", "cimd.aoi",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[8],
{ "Originated Visited MSC Address", "cimd.ovma",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[9],
{ "Data Coding Scheme", "cimd.dcs",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[10],
{ "User Data Header", "cimd.udh",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[11],
{ "User Data", "cimd.ud",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[12],
{ "User Data Binary", "cimd.udb",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[13],
{ "More Messages To Send", "cimd.mms",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[14],
{ "Validity Period Relative", "cimd.vpr",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[15],
{ "Validity Period Absolute", "cimd.vpa",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[16],
{ "Protocol Identifier", "cimd.pi",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[17],
{ "First Delivery Time Relative", "cimd.fdtr",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[18],
{ "First Delivery Time Absolute", "cimd.fdta",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[19],
{ "Reply Path", "cimd.rpath",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[20],
{ "Status Report Request", "cimd.srr",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[21],
{ "Cancel Enabled", "cimd.ce",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[22],
{ "Cancel Mode", "cimd.cm",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[23],
{ "Service Center Time Stamp", "cimd.scts",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[24],
{ "Status Code", "cimd.stcode",
FT_UINT8, BASE_DEC, VALS(cimd_status_code_vals), 0x00,
NULL, HFILL }
},
{ &hf_index[25],
{ "Status Error Code", "cimd.sterrcode",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &cimd_status_error_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_index[26],
{ "Discharge Time", "cimd.dt",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[27],
{ "Tariff Class", "cimd.tclass",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[28],
{ "Service Description", "cimd.sdes",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[29],
{ "Message Count", "cimd.mcount",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[30],
{ "Priority", "cimd.priority",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[31],
{ "Delivery Request Mode", "cimd.drmode",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[32],
{ "Service Center Address", "cimd.scaddr",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[33],
{ "Get Parameter", "cimd.gpar",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[34],
{ "SMS Center Time", "cimd.smsct",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_index[35],
{ "Error Code Description", "cimd.errcode",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &cimd_error_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_index[36],
{ "Error Text", "cimd.errtext",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
gint *ett[MAXPARAMSCOUNT + 1];
int i;
ett[0] = &ett_cimd;
for(i=0;i<MAXPARAMSCOUNT;i++)
{
ett_index[i] = -1;
ett[i + 1] = &(ett_index[i]);
vals_hdr_PC[i].ett_p = &(ett_index[i]);
vals_hdr_PC[i].hf_p = &(hf_index[i]);
vals_hdr_PC[i].diss = cimd_pc_handles[i];
};
proto_cimd = proto_register_protocol("Computer Interface to Message Distribution", "CIMD", "cimd");
proto_register_field_array(proto_cimd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cimd(void)
{
dissector_handle_t cimd_handle;
heur_dissector_add("tcp", dissect_cimd_heur, proto_cimd);
cimd_handle = create_dissector_handle(dissect_cimd, proto_cimd);
dissector_add_for_decode_as("tcp.port", cimd_handle);
}
