static void dissect_cooked_ircomm(tvbuff_t* tvb, packet_info* pinfo, proto_tree* root)
{
guint offset = 0;
guint clen;
char buf[128];
guint len;
if (tvb_length(tvb) == 0)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IrCOMM");
clen = tvb_get_guint8(tvb, offset);
len = tvb_length(tvb) - 1 - clen;
if (len > 0)
g_snprintf(buf, 128, "Clen=%d, UserData: %d byte%s", clen, len, (len > 1)? "s": "");
else
g_snprintf(buf, 128, "Clen=%d", clen);
col_add_str(pinfo->cinfo, COL_INFO, buf);
if (root)
{
proto_item* ti = proto_tree_add_item(root, proto_ircomm, tvb, 0, -1, ENC_NA);
proto_tree* tree = proto_item_add_subtree(ti, ett_ircomm);
proto_tree* ctrl_tree;
ti = proto_tree_add_item(tree, hf_control, tvb, 0, clen + 1, ENC_NA);
ctrl_tree = proto_item_add_subtree(ti, ett_ircomm_ctrl);
proto_tree_add_item(ctrl_tree, hf_control_len, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
{
tvbuff_t *cvalue = tvb_new_subset(tvb, offset, clen, clen);
call_dissector(data_handle, cvalue, pinfo, ctrl_tree);
offset += clen;
}
tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, tvb, pinfo, tree);
}
}
static void dissect_raw_ircomm(tvbuff_t* tvb, packet_info* pinfo, proto_tree* root)
{
guint len = tvb_length(tvb);
char buf[128];
if (len == 0)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IrCOMM");
g_snprintf(buf, 128, "User Data: %d byte%s", len, (len > 1)? "s": "");
col_add_str(pinfo->cinfo, COL_INFO, buf);
if (root)
{
proto_item* ti = proto_tree_add_item(root, proto_ircomm, tvb, 0, -1, ENC_NA);
proto_tree* tree = proto_item_add_subtree(ti, ett_ircomm);
call_dissector(data_handle, tvb, pinfo, tree);
}
}
static gboolean dissect_ircomm_parameters(tvbuff_t* tvb, guint offset, packet_info* pinfo _U_,
proto_tree* tree, guint list_index, guint8 attr_type)
{
guint len;
guint n = 0;
proto_item* ti;
proto_tree* p_tree;
char buf[256];
guint8 pv;
if (!check_iap_octet_result(tvb, tree, offset, "Parameters", attr_type))
return TRUE;
if (tree)
{
len = tvb_get_ntohs(tvb, offset) + offset + 2;
offset += 2;
while (offset < len)
{
guint8 p_len = tvb_get_guint8(tvb, offset + 1);
ti = proto_tree_add_item(tree, hf_ircomm_param, tvb, offset, p_len + 2, ENC_NA);
p_tree = proto_item_add_subtree(ti, ett_param[list_index * MAX_PARAMETERS + n]);
buf[0] = 0;
switch (tvb_get_guint8(tvb, offset))
{
case IRCOMM_SERVICE_TYPE:
proto_item_append_text(ti, ": Service Type (");
pv = tvb_get_guint8(tvb, offset+2);
if (pv & IRCOMM_3_WIRE_RAW)
g_strlcat(buf, ", 3-Wire raw", 256);
if (pv & IRCOMM_3_WIRE)
g_strlcat(buf, ", 3-Wire", 256);
if (pv & IRCOMM_9_WIRE)
g_strlcat(buf, ", 9-Wire", 256);
if (pv & IRCOMM_CENTRONICS)
g_strlcat(buf, ", Centronics", 256);
g_strlcat(buf, ")", 256);
proto_item_append_text(ti, "%s", buf+2);
break;
case IRCOMM_PORT_TYPE:
proto_item_append_text(ti, ": Port Type (");
pv = tvb_get_guint8(tvb, offset+2);
if (pv & IRCOMM_SERIAL)
g_strlcat(buf, ", serial", 256);
if (pv & IRCOMM_PARALLEL)
g_strlcat(buf, ", parallel", 256);
g_strlcat(buf, ")", 256);
proto_item_append_text(ti, "%s", buf+2);
break;
case IRCOMM_PORT_NAME:
proto_item_append_text(ti, ": Port Name (\"%s\")",
tvb_format_text(tvb, offset+2, p_len));
break;
default:
proto_item_append_text(ti, ": unknown");
}
offset = dissect_param_tuple(tvb, p_tree, offset);
n++;
}
}
return TRUE;
}
static gboolean dissect_ircomm_ttp_lsap(tvbuff_t* tvb, guint offset, packet_info* pinfo,
proto_tree* tree, guint list_index _U_, guint8 attr_type)
{
guint8 dlsap;
if ((dlsap = check_iap_lsap_result(tvb, tree, offset, "IrDA:TinyTP:LsapSel", attr_type)) == 0)
return FALSE;
add_lmp_conversation(pinfo, dlsap, TRUE, dissect_cooked_ircomm);
return FALSE;
}
static gboolean dissect_ircomm_lmp_lsap(tvbuff_t* tvb, guint offset, packet_info* pinfo,
proto_tree* tree, guint list_index _U_, guint8 attr_type)
{
guint8 dlsap;
if ((dlsap = check_iap_lsap_result(tvb, tree, offset, "IrDA:IrLMP:LsapSel", attr_type)) == 0)
return FALSE;
add_lmp_conversation(pinfo, dlsap, FALSE, dissect_raw_ircomm);
return FALSE;
}
void proto_register_ircomm(void)
{
guint i;
static hf_register_info hf_ircomm[] = {
{ &hf_ircomm_param,
{ "IrCOMM Parameter", "ircomm.parameter",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
#if 0
{ &hf_param_pi,
{ "Parameter Identifier", "ircomm.pi",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_param_pl,
{ "Parameter Length", "ircomm.pl",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_param_pv,
{ "Parameter Value", "ircomm.pv",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#endif
{ &hf_control,
{ "Control Channel", "ircomm.control",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_control_len,
{ "Clen", "ircomm.control.len",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }}
};
static gint* ett[] = {
&ett_ircomm,
&ett_ircomm_ctrl
};
gint* ett_p[MAX_IAP_ENTRIES * MAX_PARAMETERS];
proto_ircomm = proto_register_protocol("IrCOMM Protocol", "IrCOMM", "ircomm");
proto_register_field_array(proto_ircomm, hf_ircomm, array_length(hf_ircomm));
proto_register_subtree_array(ett, array_length(ett));
for (i = 0; i < MAX_IAP_ENTRIES * MAX_PARAMETERS; i++)
{
ett_param[i] = -1;
ett_p[i] = &ett_param[i];
}
proto_register_subtree_array(ett_p, MAX_IAP_ENTRIES * MAX_PARAMETERS);
}
void
proto_reg_handoff_ircomm(void) {
data_handle = find_dissector("data");
}
