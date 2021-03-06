static int dissect_simpdu(tvbuff_t *tvb, proto_tree *tree, guint16 offset, guint8 lenIndicator)
{
guint16 bytesProcessed;
guint8 paramCode;
proto_item *simpduItem;
proto_tree *simpduVarTree;
proto_tree *simpduVarTree1;
bytesProcessed = 0;
proto_tree_add_item(tree, hf_pdc_credit, tvb, offset, 1, ENC_BIG_ENDIAN);
bytesProcessed += 1;
proto_tree_add_item(tree, hf_pdc_simpdu_state, tvb, offset + bytesProcessed , 1, ENC_BIG_ENDIAN);
bytesProcessed += 1;
proto_tree_add_item(tree, hf_pdc_yr_admu_nr, tvb, offset + bytesProcessed , 4, ENC_BIG_ENDIAN);
bytesProcessed += 4;
if (lenIndicator > 7)
{
simpduItem = proto_tree_add_item (tree, hf_pdc_simpdu_var, tvb, offset + bytesProcessed, lenIndicator - 7, ENC_NA);
simpduVarTree = proto_item_add_subtree (simpduItem, ett_pdc_simpdu_var);
while ((offset + bytesProcessed) < ( lenIndicator + 1 ))
{
paramCode = tvb_get_guint8(tvb, offset + bytesProcessed);
simpduItem = proto_tree_add_item (simpduVarTree, hf_pdc_simpdu_param, tvb, offset + bytesProcessed, 1, ENC_NA);
simpduVarTree1 = proto_item_add_subtree (simpduItem, ett_pdc_simpdu_var);
bytesProcessed += 1;
switch (paramCode)
{
case PARAM_CODE_VERSION:
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_len, tvb, offset + bytesProcessed, 1, ENC_NA);
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_version, tvb, offset + bytesProcessed + 1, 1, ENC_NA);
bytesProcessed += 2;
break;
case PARAM_CODE_REFERENCES:
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_len, tvb, offset + bytesProcessed, 1, ENC_NA);
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_REFSRC, tvb, offset + bytesProcessed + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_REFDEST, tvb, offset + bytesProcessed + 3, 2, ENC_BIG_ENDIAN);
bytesProcessed += 5;
break;
case PARAM_CODE_TRANSPORT:
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_len, tvb, offset + bytesProcessed, 1, ENC_NA);
proto_tree_add_item(simpduVarTree1, hf_pdc_simpdu_var_TSEL, tvb, offset + bytesProcessed + 1, 2, ENC_BIG_ENDIAN);
bytesProcessed += 3;
break;
}
}
}
return (bytesProcessed);
}
static int dissect_rsmpdu(void)
{
return (0);
}
static int dissect_drmpdu(tvbuff_t *tvb, proto_tree *tree, guint16 offset)
{
proto_tree_add_item(tree, hf_pdc_drmpdu_abort, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_pdc_drmpdu_mode, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_pdc_drmpdu_init, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_pdc_drmpdu_reason, tvb, offset + 1, 1, ENC_NA);
return (2);
}
static int dissect_admpdu(tvbuff_t *tvb, proto_tree *parent_tree, proto_tree *tree, guint16 offset, packet_info *pinfo)
{
guint16 userDataLen;
guint16 returnLen;
tvbuff_t *asterixTVB;
proto_tree_add_item(tree, hf_pdc_admpdu_admpdunr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (PDC_VERSION == 2)
{
proto_tree_add_item(tree, hf_pdc_admpdu_size, tvb, offset, 2, ENC_BIG_ENDIAN);
userDataLen = tvb_get_ntohs(tvb, offset);
offset += 2;
returnLen = userDataLen + 6;
asterixTVB = tvb_new_subset_length(tvb, offset, userDataLen);
if (asterix_handle != NULL)
call_dissector(asterix_handle, asterixTVB, pinfo, parent_tree);
return (returnLen);
}
return (2);
}
static int dissect_dtmpdu(tvbuff_t *tvb, proto_tree *parent_tree, proto_tree *tree, guint16 offset, packet_info *pinfo)
{
guint16 userDataLen;
guint16 returnLen;
tvbuff_t *asterixTVB;
if (PDC_VERSION == 2)
{
proto_tree_add_item(tree, hf_pdc_dtmpdu_user_size, tvb, offset, 2, ENC_BIG_ENDIAN);
userDataLen = tvb_get_ntohs(tvb, 2);
returnLen = userDataLen + 2;
asterixTVB = tvb_new_subset_length(tvb, offset + 2, userDataLen);
if (asterix_handle != NULL)
call_dissector(asterix_handle, asterixTVB, pinfo, parent_tree);
return (returnLen);
}
return (2);
}
static int dissect_edmpdu(tvbuff_t *tvb, proto_tree *parent_tree, proto_tree *tree, guint16 offset, packet_info *pinfo)
{
guint16 userDataLen;
guint16 returnLen;
tvbuff_t *asterixTVB;
if (PDC_VERSION == 2)
{
proto_tree_add_item(tree, hf_pdc_dtmpdu_user_size, tvb, offset, 2, ENC_BIG_ENDIAN);
userDataLen = tvb_get_ntohs(tvb, 2);
returnLen = userDataLen + 2;
asterixTVB = tvb_new_subset_length(tvb, offset + 2, userDataLen);
if (asterix_handle != NULL)
call_dissector(asterix_handle, asterixTVB, pinfo, parent_tree);
return (returnLen);
}
return 2;
}
static int dissect_akmpdu(tvbuff_t *tvb, proto_tree *tree, guint16 offset)
{
proto_tree_add_item(tree, hf_pdc_akmpdu_mns, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pdc_akmpdu_cdt, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pdc_yr_admu_nr, tvb, offset + 2, 4, ENC_BIG_ENDIAN);
return (6);
}
static int dissect_pdc_packet(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo)
{
guint i = 0;
guint8 len_indicator;
guint8 mpduCode;
guint16 length;
proto_item *pdcPacketItem;
proto_tree *pdcPacketTree;
length = 0;
len_indicator = tvb_get_guint8 (tvb, i);
mpduCode = tvb_get_guint8 (tvb, i + 1);
length += 2;
pdcPacketItem = proto_tree_add_item (tree, proto_pdc, tvb, i, len_indicator + 1, ENC_NA);
pdcPacketTree = proto_item_add_subtree (pdcPacketItem, ett_pdc);
proto_tree_add_item(pdcPacketTree, hf_pdc_len, tvb, i, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pdcPacketTree, hf_pdc_mpdu_code, tvb, i + 1, 1, ENC_BIG_ENDIAN);
switch (mpduCode)
{
case SIMPDU:
length += dissect_simpdu(tvb, pdcPacketTree, length, len_indicator);
col_set_str(pinfo->cinfo, COL_INFO, "SIMPDU");
break;
case RSMPDU:
length += dissect_rsmpdu();
col_set_str(pinfo->cinfo, COL_INFO, "RSMPDU");
break;
case DRMPDU:
length += dissect_drmpdu(tvb, pdcPacketTree, length);
col_set_str(pinfo->cinfo, COL_INFO, "DRMPDU");
break;
case DTMPDU:
length += dissect_dtmpdu(tvb, tree, pdcPacketTree, length, pinfo);
col_set_str(pinfo->cinfo, COL_INFO, "DTMPDU");
break;
case ADMPDU:
length += dissect_admpdu(tvb, tree, pdcPacketTree, length, pinfo);
col_set_str(pinfo->cinfo, COL_INFO, "ADMPDU");
break;
case EDMPDU:
length += dissect_edmpdu(tvb, tree, pdcPacketTree, length, pinfo);
col_set_str(pinfo->cinfo, COL_INFO, "EDMPDU");
break;
case AKMPDU:
length += dissect_akmpdu(tvb, pdcPacketTree, length);
col_set_str(pinfo->cinfo, COL_INFO, "AKMPDU");
break;
default:
break;
};
return (length);
}
static int dissect_pdc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, PDC_PROCOTOL );
col_clear(pinfo->cinfo, COL_INFO);
dissect_pdc_packet(tvb, tree, pinfo);
return tvb_reported_length(tvb);
}
static guint get_pdc_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint size;
guint extra;
guint8 mpdu_type;
mpdu_type = tvb_get_guint8(tvb, offset+1);
switch (mpdu_type)
{
case SIMPDU:
size = tvb_get_guint8(tvb, offset);
extra = 1;
break;
case RSMPDU:
size = tvb_get_guint8(tvb, offset);
extra = 1;
break;
case DRMPDU:
size = tvb_get_guint8(tvb, offset);
extra = 1;
break;
case DTMPDU:
size = tvb_get_ntohs(tvb, offset+2);
extra = 4;
break;
case ADMPDU:
size = tvb_get_ntohs(tvb, offset+6);
extra = 8;
break;
case EDMPDU:
size = tvb_get_guint8(tvb, offset);
extra = 1;
break;
case AKMPDU:
size = tvb_get_guint8(tvb, offset)+1;
extra = 0;
break;
default:
size = 0;
extra = 0;
}
return size + extra;
}
static void tcp_dissect_pdc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 mpdu_type;
guint8 minimum_bytes;
mpdu_type = tvb_get_guint8(tvb,1);
switch (mpdu_type)
{
case SIMPDU:
minimum_bytes = 2;
break;
case RSMPDU:
minimum_bytes = 2;
break;
case DRMPDU:
minimum_bytes = 2;
break;
case DTMPDU:
minimum_bytes = 4;
break;
case ADMPDU:
minimum_bytes = 8;
break;
case EDMPDU:
minimum_bytes = 2;
break;
case AKMPDU:
minimum_bytes = 2;
break;
default:
minimum_bytes = 2;
break;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, minimum_bytes, get_pdc_message_len, dissect_pdc, NULL);
}
void proto_register_pdc(void)
{
module_t *pdc_pref_module;
static hf_register_info hf[] =
{
{ &hf_pdc_len,
{ "Length Indicator", "pdc.li",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_mpdu_code,
{ "MPDU code", "pdc.mpducode",
FT_UINT8, BASE_DEC, VALS(valstr_mpdus), 0x0, NULL, HFILL }},
{ &hf_pdc_credit,
{ "Credit", "pdc.cdt",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_yr_admu_nr,
{ "YR-ADMU-NR", "pdc.yradmunr",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL , HFILL }},
{ &hf_pdc_simpdu_state,
{ "State", "pdc.state",
FT_UINT8, BASE_DEC, VALS(valstr_simpdu_state), 0x0, NULL, HFILL }},
{ &hf_pdc_akmpdu_mns,
{ "MNS", "pdc.akmpdu.mns",
FT_UINT16, BASE_DEC, NULL, 0x8000, NULL, HFILL }},
{ &hf_pdc_akmpdu_cdt,
{ "CDT", "pdc.akmpdu.cdt",
FT_UINT16, BASE_DEC, NULL, 0x07FF, NULL, HFILL }},
{ &hf_pdc_simpdu_var,
{ "Variable Part", "pdc.simpdu.variable",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_simpdu_param,
{ "Parameter", "pdc.simpdu.param",
FT_UINT8, BASE_DEC, VALS(valstr_simpdu_param), 0x0, NULL, HFILL }},
{ &hf_pdc_simpdu_var_len,
{ "Length", "pdc.simpdu.variable.length",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_simpdu_var_version,
{ "PDC Version Number", "pdc.simpdu.variable.version",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_simpdu_var_REFSRC,
{ "Reference Source", "pdc.simpdu.variable.refsrc",
FT_UINT32, BASE_DEC, NULL, 0x0,NULL, HFILL }},
{ &hf_pdc_simpdu_var_REFDEST,
{ "Reference Destination", "pdc.simpdu.variable.refdst",
FT_UINT32, BASE_DEC, NULL, 0x0,NULL, HFILL }},
{ &hf_pdc_simpdu_var_TSEL,
{ "Transport Selector", "pdc.simpdu.tsel",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_pdc_drmpdu_abort,
{ "Abort", "pdc.drmpdu.abort",
FT_UINT8, BASE_DEC, VALS(valstr_drmpdu_abort), 0x80, NULL, HFILL }},
{ &hf_pdc_drmpdu_reason,
{ "Reason", "pdc.drmpdu.reason",
FT_UINT8, BASE_DEC, VALS(valstr_drmpdu_reason), 0x0, NULL, HFILL }},
{ &hf_pdc_drmpdu_mode,
{ "Mode", "pdc.drmpdu.mode",
FT_UINT8, BASE_DEC, VALS(valstr_drmpdu_mode), 0x70, NULL, HFILL }},
{ &hf_pdc_drmpdu_init,
{ "Reason", "pdc.drmpdu.init",
FT_UINT8, BASE_DEC, VALS(valstr_drmpdu_initatior), 0x0F, NULL, HFILL }},
{ &hf_pdc_dtmpdu_user_size,
{ "User Data Length", "pdc.dtmpdu.usersize",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL , HFILL }},
{ &hf_pdc_admpdu_admpdunr,
{ "AD-MPDU-NR", "pdc.admpdu.admpdunr",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL , HFILL }},
{ &hf_pdc_admpdu_size,
{ "User Data Size", "pdc.admpdu.usersize",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL , HFILL }},
};
static gint *ett[] = {
&ett_pdc,
&ett_pdc_simpdu_var
};
proto_pdc = proto_register_protocol (
"PDC Protocol",
"PDC",
"pdc"
);
proto_register_field_array(proto_pdc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
pdc_pref_module = prefs_register_protocol(proto_pdc, proto_reg_handoff_pdc);
prefs_register_uint_preference(pdc_pref_module, "tcp.port", "PDC Port", "PDC Port if other then the default", 10, &gPREF_PORT_NUM_TCP);
}
void proto_reg_handoff_pdc(void)
{
static dissector_handle_t pdc_tcp_handle;
static int pdc_tcp_port;
static gboolean initialized = FALSE;
if (! initialized)
{
asterix_handle = find_dissector("asterix");
pdc_tcp_handle = create_dissector_handle(tcp_dissect_pdc, proto_pdc);
dissector_add_for_decode_as("tcp.port", pdc_tcp_handle);
initialized = TRUE;
}
else
{
if (pdc_tcp_port != 0)
dissector_delete_uint("tcp.port", pdc_tcp_port, pdc_tcp_handle);
}
pdc_tcp_port = gPREF_PORT_NUM_TCP;
if (pdc_tcp_port != 0)
dissector_add_uint("tcp.port", pdc_tcp_port, pdc_tcp_handle);
}
