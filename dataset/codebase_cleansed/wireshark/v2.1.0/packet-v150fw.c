static int
dissect_v150fw(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *v150fw_tree, *field_tree;
guint8 extb, ric;
guint16 ext_len = 0;
gint payload_length;
unsigned int offset = 0;
if(tree)
{
ti = proto_tree_add_item(tree, proto_v150fw, tvb, 0, -1, ENC_NA);
v150fw_tree = proto_item_add_subtree(ti, ett_v150fw);
payload_length = tvb_reported_length(tvb);
extb = tvb_get_guint8(tvb, offset) & 0x01;
ric = tvb_get_guint8(tvb, offset + 1);
if(extb && payload_length >= 6)
ext_len = tvb_get_ntohs(tvb, offset + 4) & 0x07FF;
proto_tree_add_item(v150fw_tree, hf_v150fw_event_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v150fw_tree, hf_v150fw_force_response_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v150fw_tree, hf_v150fw_extension_bit, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(v150fw_tree, hf_v150fw_reason_id_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
switch(ric)
{
case V150FW_RIC_CM:
case V150FW_RIC_JM:
ti = proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_mod_avail, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_available_modulations);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_pcm_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v34_duplex, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v34_half_duplex, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v32_v32bis, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v22_v22bis, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v17, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v29_half_duplex, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v27ter, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v26ter, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v26bis, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v23_duplex, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v23_half_duplex, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v21, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v90_or_v92_analog, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v90_or_v92_digital, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(field_tree, hf_v150fw_cm_jm_mod_avail_v91, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case V150FW_RIC_TIMEOUT:
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_timeout, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_timeout_vendor, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
break;
case V150FW_RIC_CLEARDOWN:
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_cleardown, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_cleardown_reserved, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(v150fw_tree, hf_v150fw_reason_id_code_info, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
offset += 2;
if(extb && payload_length >= 6)
{
proto_tree_add_item(v150fw_tree, hf_v150fw_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
if(ext_len != (payload_length - 6))
{
proto_tree_add_item(v150fw_tree, hf_v150fw_extension_len, tvb, offset, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(v150fw_tree, hf_v150fw_extension_len, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset += 2;
switch(ric) {
case V150FW_RIC_CLEARDOWN:
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_cleardown_vendor_tag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(v150fw_tree, hf_v150fw_ric_info_cleardown_vendor_info, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(v150fw_tree, hf_v150fw_remainder, tvb, offset, (payload_length - 6), ENC_NA);
break;
}
}
}
return tvb_captured_length(tvb);
}
void
proto_register_v150fw(void)
{
static hf_register_info hf[] =
{
{
&hf_v150fw_event_id,
{
"Event ID",
"v150fw.event",
FT_UINT8,
BASE_DEC | BASE_RANGE_STRING,
RVALS(v150fw_event_id_name),
0xFC,
NULL, HFILL
}
},
{
&hf_v150fw_force_response_bit,
{
"Force response",
"v150fw.frb",
FT_BOOLEAN,
8,
TFS(&tfs_yes_no),
0x02,
NULL, HFILL
}
},
{
&hf_v150fw_extension_bit,
{
"Payload extension",
"v150fw.extb",
FT_BOOLEAN,
8,
TFS(&tfs_present_absent),
0x01,
NULL, HFILL
}
},
{
&hf_v150fw_reason_id_code,
{
"Reason ID",
"v150fw.ric",
FT_UINT8,
BASE_DEC | BASE_RANGE_STRING,
RVALS(v150fw_ric_name),
0xFF,
NULL, HFILL
}
},
{
&hf_v150fw_reason_id_code_info,
{
"Info",
"v150fw.ricinfo",
FT_UINT16,
BASE_HEX,
NULL,
0xFFFF,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_timeout,
{
"Timeout type",
"v150fw.ricinfo.timeout",
FT_UINT16,
BASE_HEX,
VALS(v150fw_ric_info_timeout_type),
0xFF00,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_timeout_vendor,
{
"Vendor-specific timeout info",
"v150fw.ricinfo.timeout_vendor",
FT_UINT16,
BASE_HEX,
NULL,
0x00FF,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_cleardown,
{
"Cleardown type",
"v150fw.ricinfo.cleardown",
FT_UINT16,
BASE_HEX,
VALS(v150fw_ric_info_cleardown_type),
0xFF00,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_cleardown_reserved,
{
"Reserved for use by the ITU-T",
"v150fw.ricinfo.cleardown_reserved",
FT_UINT16,
BASE_HEX,
NULL,
0x00FF,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_cleardown_vendor_tag,
{
"Vendor tag",
"v150fw.cleardown_vendor_tag",
FT_UINT8,
BASE_HEX,
NULL,
0xFF,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_cleardown_vendor_info,
{
"Vendor-specific info",
"v150fw.cleardown_vendor_info",
FT_UINT8,
BASE_HEX,
NULL,
0xFF,
NULL, HFILL
}
},
{
&hf_v150fw_ric_info_mod_avail,
{
"Modulation availability",
"v150fw.rinfo.mod_avail",
FT_UINT16,
BASE_HEX,
NULL,
0xFFFF,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_pcm_mode,
{
"PCM mode",
"v150fw.rinfo.mod_avail.pcm_mode",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x8000,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v34_duplex,
{
"V.34 duplex",
"v150fw.rinfo.mod_avail.v34_duplex",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x4000,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v34_half_duplex,
{
"V.34 half-duplex",
"v150fw.rinfo.mod_avail.v34_half_duplex",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x2000,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v32_v32bis,
{
"V.32/V.32bis",
"v150fw.rinfo.mod_avail.v32_v32bis",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x1000,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v22_v22bis,
{
"V.22/V.22bis",
"v150fw.rinfo.mod_avail.v22_v22bis",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0800,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v17,
{
"V.17",
"v150fw.rinfo.mod_avail.v17",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0400,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v29_half_duplex,
{
"V.29 half-duplex",
"v150fw.rinfo.mod_avail.v29_half_duplex",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0200,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v27ter,
{
"V.27ter",
"v150fw.rinfo.mod_avail.v27ter",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0100,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v26ter,
{
"V.26ter",
"v150fw.rinfo.mod_avail.v26ter",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0080,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v26bis,
{
"V.26bis",
"v150fw.rinfo.mod_avail.v26bis",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0040,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v23_duplex,
{
"V.23 duplex",
"v150fw.rinfo.mod_avail.v23_duplex",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0020,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v23_half_duplex,
{
"V.23 half-duplex",
"v150fw.rinfo.mod_avail.half_duplex",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0010,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v21,
{
"V.21",
"v150fw.rinfo.mod_avail.v21",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0008,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v90_or_v92_analog,
{
"V.90 or V.92 analog",
"v150fw.rinfo.mod_avail.v90_or_v92_analog",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0004,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v90_or_v92_digital,
{
"V.90 or V.92 digital",
"v150fw.rinfo.mod_avail.v90_or_v92_digital",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0002,
NULL, HFILL
}
},
{
&hf_v150fw_cm_jm_mod_avail_v91,
{
"V.91",
"v150fw.rinfo.mod_avail.v91",
FT_BOOLEAN,
16,
TFS(&tfs_available_not_available),
0x0001,
NULL, HFILL
}
},
{
&hf_v150fw_reserved,
{
"Reserved",
"v150fw.reserved",
FT_UINT16,
BASE_HEX,
NULL,
0xF800,
NULL, HFILL
}
},
{
&hf_v150fw_extension_len,
{
"Extension field length",
"v150fw.eflen",
FT_UINT16,
BASE_DEC,
NULL,
0x07FF,
NULL, HFILL
}
},
{
&hf_v150fw_remainder,
{
"Remaining bytes",
"v150fw.remainder",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_v150fw,
&ett_available_modulations
};
proto_v150fw = proto_register_protocol("v150fw State Signaling Event", "v150fw", "v150fw");
proto_register_field_array(proto_v150fw, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("v150fw", dissect_v150fw, proto_v150fw);
}
