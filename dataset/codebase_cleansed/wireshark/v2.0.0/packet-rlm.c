static gboolean
dissect_rlm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *rlm_tree;
guint8 rlm_type, version;
const char *type_str = NULL;
if (pinfo->srcport < 3000 || pinfo->srcport > 3015
|| pinfo->destport < 3000 || pinfo->destport > 3015
|| pinfo->destport != pinfo->srcport)
return FALSE;
if (tvb_captured_length(tvb) < 2)
return FALSE;
version = tvb_get_guint8(tvb, 0);
rlm_type = tvb_get_guint8(tvb, 1);
if (tvb_captured_length(tvb) != 8 || version != 2) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "RLM");
switch (rlm_type) {
case RLM_START_REQUEST:
type_str = "Start request";
break;
case RLM_START_ACK:
type_str = "Start acknowledgement";
break;
case RLM_ECHO_REQUEST:
type_str = "Echo request";
break;
case RLM_ECHO_REPLY:
type_str = "Echo reply";
break;
default:
type_str = "Unknown type";
break;
}
col_set_str(pinfo->cinfo, COL_INFO, type_str);
if (tree) {
ti = proto_tree_add_item(tree, proto_rlm, tvb, 0, 8, ENC_NA);
rlm_tree = proto_item_add_subtree(ti, ett_rlm);
proto_tree_add_item(rlm_tree, hf_rlm_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(rlm_tree, hf_rlm_type, tvb, 1, 1, rlm_type, "%u (%s)", rlm_type, type_str);
proto_tree_add_item(rlm_tree, hf_rlm_unknown, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rlm_tree, hf_rlm_tid, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rlm_tree, hf_rlm_unknown2, tvb, 6, 2, ENC_BIG_ENDIAN);
}
return TRUE;
}
void
proto_reg_handoff_rlm(void)
{
heur_dissector_add("udp", dissect_rlm, "Redundant Link Management over UDP", "rlm_udp", proto_rlm, HEURISTIC_ENABLE);
}
void
proto_register_rlm(void)
{
static hf_register_info hf[] = {
{ &hf_rlm_version,
{ "Version", "rlm.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rlm_type,
{ "Type", "rlm.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rlm_unknown,
{ "Unknown", "rlm.unknown",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rlm_tid,
{ "Transaction ID", "rlm.tid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_rlm_unknown2,
{ "Unknown", "rlm.unknown2",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_rlm,
};
proto_rlm = proto_register_protocol("Redundant Link Management Protocol",
"RLM", "rlm");
proto_register_field_array(proto_rlm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
