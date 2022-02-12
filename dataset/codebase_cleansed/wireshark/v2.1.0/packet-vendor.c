static int
dissect_vsif (tvbuff_t * tvb, packet_info * pinfo _U_, proto_tree * tree, void* data _U_)
{
proto_item *it;
proto_tree *vsif_tree;
guint8 type;
guint8 length;
guint32 value;
gint vsif_len;
vsif_len = tvb_reported_length_remaining (tvb, 0);
type = tvb_get_guint8 (tvb, 0);
if (type != 0x08)
{
THROW (ReportedBoundsError);
}
length = tvb_get_guint8 (tvb, 1);
if (length != 3)
{
THROW (ReportedBoundsError);
}
value = tvb_get_ntoh24 (tvb, 2);
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_vsif, tvb, 0, -1,
"VSIF Encodings");
vsif_tree = proto_item_add_subtree (it, ett_docsis_vsif);
proto_tree_add_item (vsif_tree, hf_docsis_vsif_vendorid, tvb, 2, 3, ENC_BIG_ENDIAN);
switch (value)
{
case VENDOR_CISCO:
proto_item_append_text (it, " (Cisco)");
dissect_cisco (tvb, vsif_tree, vsif_len);
break;
default:
proto_item_append_text (it, " (Unknown)");
proto_tree_add_item (vsif_tree, hf_docsis_vsif_vendor_unknown, tvb,
0, -1, ENC_NA);
break;
}
}
return tvb_captured_length(tvb);
}
static void
dissect_cisco (tvbuff_t * tvb, proto_tree * tree, gint vsif_len)
{
int pos = 5;
guint8 type, length;
proto_tree *ipprec_tree;
int templen;
while (pos < vsif_len)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case NUM_PHONES:
proto_tree_add_item (tree, hf_docsis_vsif_cisco_numphones, tvb,
pos, length, ENC_BIG_ENDIAN);
break;
case IP_PREC:
ipprec_tree =
proto_tree_add_subtree(tree, tvb, pos, length, ett_docsis_vsif_ipprec, NULL, "IP Precedence");
templen = pos + length;
while (pos < templen)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case IP_PREC_VAL:
if (length != 1)
THROW (ReportedBoundsError);
proto_tree_add_item (ipprec_tree,
hf_docsis_vsif_cisco_ipprec_val, tvb,
pos, length, ENC_BIG_ENDIAN);
break;
case IP_PREC_BW:
if (length != 4)
THROW (ReportedBoundsError);
proto_tree_add_item (ipprec_tree,
hf_docsis_vsif_cisco_ipprec_bw, tvb,
pos, length, ENC_BIG_ENDIAN);
break;
default:
THROW (ReportedBoundsError);
}
pos += length;
}
break;
case IOS_CONFIG_FILE:
proto_tree_add_item (tree, hf_docsis_vsif_cisco_config_file, tvb,
pos, length, ENC_ASCII|ENC_NA);
}
pos += length;
}
}
void
proto_register_docsis_vsif (void)
{
static hf_register_info hf[] = {
{&hf_docsis_vsif_vendorid,
{"Vendor Id", "docsis_vsif.vendorid",
FT_UINT24, BASE_HEX, VALS(vendorid_vals), 0x0,
"Vendor Identifier", HFILL}
},
{&hf_docsis_vsif_vendor_unknown,
{"VSIF Encodings", "docsis_vsif.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Unknown Vendor", HFILL}
},
{&hf_docsis_vsif_cisco_numphones,
{"Number of phone lines", "docsis_vsif.cisco.numphones",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
#if 0
{&hf_docsis_vsif_cisco_ipprec,
{"IP Precedence Encodings", "docsis_vsif.cisco.ipprec",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
#endif
{&hf_docsis_vsif_cisco_ipprec_val,
{"IP Precedence Value", "docsis_vsif.cisco.ipprec.value",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_vsif_cisco_ipprec_bw,
{"IP Precedence Bandwidth", "docsis_vsif.cisco.ipprec.bw",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_docsis_vsif_cisco_config_file,
{"IOS Config File", "docsis_vsif.cisco.iosfile",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
};
static gint *ett[] = {
&ett_docsis_vsif,
&ett_docsis_vsif_ipprec,
};
proto_docsis_vsif =
proto_register_protocol ("DOCSIS Vendor Specific Encodings",
"DOCSIS VSIF", "docsis_vsif");
proto_register_field_array (proto_docsis_vsif, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_vsif", dissect_vsif, proto_docsis_vsif);
}
void
proto_reg_handoff_docsis_vsif (void)
{
#if 0
dissector_handle_t docsis_vsif_handle;
docsis_vsif_handle = find_dissector ("docsis_vsif");
dissector_add_uint ("docsis", 0xFD, docsis_vsif_handle);
#endif
}
