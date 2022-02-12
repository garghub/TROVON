static gint
dissect_lon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gint pdu_fmt, addr_fmt, dom_len, pdutype, length;
gint addr_a;
proto_tree *ti;
proto_tree *lon_tree;
gint npdu, type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LON");
col_clear(pinfo->cinfo, COL_INFO);
npdu = tvb_get_guint8(tvb, 0);
type = tvb_get_guint8(tvb, 1);
type = (type&0x30)>>4;
col_add_fstr(pinfo->cinfo, COL_INFO,
"%sDelta_BL: %i Type: %s",
npdu&0x80?"Priority ":"",
npdu&0x3F,
val_to_str_const(type, pdu_fmt_vs, "Unknown"));
ti = proto_tree_add_item(tree, proto_lon, tvb, offset, -1, ENC_NA);
lon_tree = proto_item_add_subtree(ti, ett_lon);
{
static const gint *ppdu_fields[] = {
&hf_lon_ppdu_prio,
&hf_lon_ppdu_alt,
&hf_lon_ppdu_deltabl,
NULL
};
proto_tree_add_bitmask(lon_tree, tvb, offset, hf_lon_ppdu,
ett_ppdu, ppdu_fields, ENC_BIG_ENDIAN);
offset++;
}
{
static const gint *npdu_fields[] = {
&hf_lon_npdu_version,
&hf_lon_npdu_pdu_fmt,
&hf_lon_npdu_addr_fmt,
&hf_lon_npdu_dom_len,
NULL
};
proto_tree_add_bitmask(lon_tree, tvb, offset, hf_lon_npdu,
ett_npdu, npdu_fields, ENC_BIG_ENDIAN);
pdu_fmt = (tvb_get_guint8(tvb, offset) >> 4) & 0x03;
addr_fmt = (tvb_get_guint8(tvb, offset) >> 2) & 0x03;
dom_len = tvb_get_guint8(tvb, offset) & 0x03;
offset++;
}
switch(addr_fmt)
{
case 0:
ti = proto_tree_add_subtree(lon_tree, tvb, offset, 3, ett_address, NULL, "Address type 0 (broadcast)");
proto_tree_add_item(ti, hf_lon_addr_srcsub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_srcnode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstsub, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += 3;
break;
case 1:
ti = proto_tree_add_subtree(lon_tree, tvb, offset, 3, ett_address, NULL, "Address type 1 (multicast)");
proto_tree_add_item(ti, hf_lon_addr_srcsub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_srcnode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstgrp, tvb, offset+2, 1, ENC_BIG_ENDIAN);
offset += 3;
break;
case 2:
addr_a = tvb_get_guint8(tvb, offset+1) >> 7;
if (addr_a) {
ti = proto_tree_add_subtree(lon_tree, tvb, offset, 4, ett_address, NULL, "Address type 2a (unicast)");
proto_tree_add_item(ti, hf_lon_addr_srcsub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_srcnode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstsub, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstnode, tvb, offset+3, 1, ENC_BIG_ENDIAN);
offset += 4;
} else {
ti = proto_tree_add_subtree(lon_tree, tvb, offset, 6, ett_address, NULL, "Address type 2b (multicast)");
proto_tree_add_item(ti, hf_lon_addr_srcsub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_srcnode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstgrp, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstnode, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_grp, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_grpmem, tvb, offset+5, 1, ENC_BIG_ENDIAN);
offset += 6;
}
break;
case 3:
ti = proto_tree_add_subtree(lon_tree, tvb, offset, 9, ett_address, NULL, "Address type 3 (UID)");
proto_tree_add_item(ti, hf_lon_addr_srcsub, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_srcnode, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_dstsub, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti, hf_lon_addr_uid, tvb, offset+3, 6, ENC_NA);
offset += 9;
break;
}
switch(dom_len)
{
case 0:
proto_tree_add_bytes_format(lon_tree, hf_lon_domain, tvb, offset, 0, NULL, "Domain wide addressing");
break;
case 1:
proto_tree_add_item(lon_tree, hf_lon_domain, tvb, offset, 1, ENC_NA);
offset++;
break;
case 2:
proto_tree_add_item(lon_tree, hf_lon_domain, tvb, offset, 3, ENC_NA);
offset += 3;
break;
case 3:
proto_tree_add_item(lon_tree, hf_lon_domain, tvb, offset, 6, ENC_NA);
offset += 6;
break;
}
switch(pdu_fmt)
{
case 0:
{
static const gint *tpdu_fields[] = {
&hf_lon_auth,
&hf_lon_tpdu_tpdu_type,
&hf_lon_trans_no,
NULL
};
proto_tree_add_bitmask(lon_tree, tvb, offset, hf_lon_tpdu,
ett_tpdu, tpdu_fields, ENC_BIG_ENDIAN);
pdutype = (tvb_get_guint8(tvb, offset)>>4)& 0x07;
offset++;
switch(pdutype)
{
case 0:
case 1:
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
case 2:
break;
case 4:
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lon_tree, hf_lon_mlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(lon_tree, hf_lon_mlist, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
break;
case 5:
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lon_tree, hf_lon_mlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length > 0)
proto_tree_add_item(lon_tree, hf_lon_mlist, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
default:
expert_add_info_format(pinfo, lon_tree, &ei_lon_tpdu_tpdu_type_unknown, "Unexpected TPDU type %i", pdutype);
break;
}
}
break;
case 1:
{
static const gint *spdu_fields[] = {
&hf_lon_auth,
&hf_lon_spdu_spdu_type,
&hf_lon_trans_no,
NULL
};
proto_tree_add_bitmask(lon_tree, tvb, offset, hf_lon_spdu,
ett_spdu, spdu_fields, ENC_BIG_ENDIAN);
pdutype = (tvb_get_guint8(tvb, offset)>>4)& 0x07;
offset++;
switch(pdutype)
{
case 0:
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
case 2:
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
case 4:
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lon_tree, hf_lon_mlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(lon_tree, hf_lon_mlist, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
break;
case 5:
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(lon_tree, hf_lon_mlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (length > 0)
proto_tree_add_item(lon_tree, hf_lon_mlist, tvb, offset, length, ENC_BIG_ENDIAN);
offset += length;
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
default:
expert_add_info_format(pinfo, lon_tree, &ei_lon_tpdu_spdu_type_unknown, "Unexpected SPDU type %i", pdutype);
break;
}
}
break;
case 2:
{
static const gint *authpdu_fields[] = {
&hf_lon_authpdu_fmt,
&hf_lon_authpdu_authpdu_type,
&hf_lon_trans_no,
NULL
};
proto_tree_add_bitmask(lon_tree, tvb, offset, hf_lon_authpdu,
ett_authpdu, authpdu_fields, ENC_BIG_ENDIAN);
pdutype = (tvb_get_guint8(tvb, offset)>>4)& 0x03;
offset++;
switch(pdutype)
{
case 0:
case 2:
offset += 9;
break;
default:
expert_add_info_format(pinfo, lon_tree, &ei_lon_tpdu_authpdu_type_unknown, "Unexpected AuthPDU type %i", pdutype);
break;
}
}
break;
case 3:
offset += dissect_apdu(lon_tree, pinfo, tvb, offset);
break;
}
return offset;
}
static gint
dissect_apdu(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb,
gint offset)
{
tvbuff_t *next_tvb;
gint old_offset = offset, dest_type;
dest_type = tvb_get_guint8(tvb, offset);
if ((dest_type&0x80) == 0x80) {
static const gint *nv_fields[] = {
&hf_lon_nv_dir,
&hf_lon_nv_selector,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_lon_nv,
ett_nv, nv_fields, ENC_BIG_ENDIAN);
offset += 2;
} else if ((dest_type&0xc0) == 0) {
static const gint *app_fields[] = {
&hf_lon_app_code,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_lon_app,
ett_app, app_fields, ENC_BIG_ENDIAN);
offset++;
} else if ((dest_type&0xe0) == 0x60) {
static const gint *nm_fields[] = {
&hf_lon_nm_code,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_lon_nm,
ett_nm, nm_fields, ENC_BIG_ENDIAN);
offset++;
if (dest_type == 0x7F) {
proto_tree_add_item(tree, hf_lon_addr_uid, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_lon_name, tvb, offset, 8, ENC_NA);
offset += 8;
}
} else if ((dest_type&0xf0) == 0x50) {
static const gint *nd_fields[] = {
&hf_lon_nd_code,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_lon_nd,
ett_nd, nd_fields, ENC_BIG_ENDIAN);
offset++;
} else if ((dest_type&0xf0) == 0x40) {
static const gint *ff_fields[] = {
&hf_lon_ff_code,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_lon_ff,
ett_ff, ff_fields, ENC_BIG_ENDIAN);
offset++;
} else {
expert_add_info_format(pinfo, tree, &ei_lon_tpdu_apdu_dest_type, "Malformed APDU destin&type %i", dest_type);
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
return offset - old_offset + call_data_dissector(next_tvb, pinfo, tree);
}
void
proto_register_lon(void)
{
static hf_register_info hf[] =
{
{&hf_lon_ppdu,
{"PPDU", "lon.ppdu",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_ppdu_prio,
{"Priority", "lon.prio",
FT_UINT8, BASE_DEC, NULL, 0x80,
"Priority packet", HFILL }
},
{&hf_lon_ppdu_alt,
{"Alt path", "lon.alt_path",
FT_UINT8, BASE_DEC, NULL, 0x40,
"Alternate path", HFILL }
},
{&hf_lon_ppdu_deltabl,
{"Delta BL", "lon.delta_bl",
FT_UINT8, BASE_DEC, NULL, 0x3f,
"How many packets to expect from this one", HFILL }
},
{&hf_lon_npdu,
{"NPDU", "lon.npdu",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{&hf_lon_npdu_version,
{"version", "lon.vers",
FT_UINT8, BASE_HEX, NULL, 0xc0,
"LON protocol version", HFILL }
},
{&hf_lon_npdu_pdu_fmt,
{"PDU format", "lon.pdufmt",
FT_UINT8, BASE_HEX, VALS(pdu_fmt_vs), 0x30,
NULL, HFILL }
},
{&hf_lon_npdu_addr_fmt,
{"Address format", "lon.addrfmt",
FT_UINT8, BASE_HEX, VALS(addr_fmt_vs), 0x0c,
NULL, HFILL }
},
{&hf_lon_npdu_dom_len,
{"Domain length", "lon.domainlen",
FT_UINT8, BASE_HEX, VALS(domain_length_vs), 0x03,
NULL, HFILL }
},
{&hf_lon_addr_srcsub,
{"Source subnet", "lon.srcnet",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_addr_srcnode,
{"Source node", "lon.srcnode",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL }
},
{&hf_lon_addr_dstsub,
{"Destination subnet", "lon.dstnet",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_addr_dstgrp,
{"Destination group", "lon.dstgrp",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_addr_dstnode,
{"Destination node", "lon.dstnode",
FT_UINT8, BASE_HEX, NULL, 0x7f,
NULL, HFILL }
},
{&hf_lon_addr_grp,
{"Group", "lon.grp",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_addr_grpmem,
{"Group member", "lon.grpmem",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_addr_uid,
{"Unique node ID", "lon.uid",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{&hf_lon_domain,
{"Domain", "lon.domain",
FT_BYTES, BASE_NONE, NULL , 0,
NULL, HFILL }
},
{&hf_lon_tpdu,
{"TPDU", "lon.tpdu",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_auth,
{"Auth", "lon.auth",
FT_UINT8, BASE_HEX, NULL, 0x80,
NULL, HFILL }
},
{&hf_lon_tpdu_tpdu_type,
{"TPDU type", "lon.tpdu_type",
FT_UINT8, BASE_HEX, VALS(tpdu_type_vs), 0x70,
NULL, HFILL }
},
{&hf_lon_trans_no,
{"Transaction number", "lon.trans_no",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }
},
{&hf_lon_spdu,
{"SPDU", "lon.spdu",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_spdu_spdu_type,
{"SPDU type", "lon.spdu_type",
FT_UINT8, BASE_HEX, VALS(spdu_type_vs), 0x70,
NULL, HFILL }
},
{&hf_lon_mlen,
{"Length of M_List", "lon.spdu.mlen",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_mlist,
{"M_List", "lon.spdu.mlist",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_authpdu,
{"AuthPDU", "lon.authpdu",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_authpdu_fmt,
{"FMT (same as AddrFmt)", "lon.authpdu_addrfmt",
FT_UINT8, BASE_HEX, NULL, 0xc,
NULL, HFILL }
},
{&hf_lon_authpdu_authpdu_type,
{"AuthPDU type", "lon.authpdu_type",
FT_UINT8, BASE_HEX, VALS(authpdu_type_vs), 0x2,
NULL, HFILL }
},
{&hf_lon_nv,
{"Network Variable", "lon.nv",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_nv_dir,
{"NV direction", "lon.nv.dir",
FT_UINT16, BASE_HEX, NULL, 0x4000,
NULL, HFILL }
},
{&hf_lon_nv_selector,
{"NV selector", "lon.nv.selector",
FT_UINT16, BASE_HEX, NULL, 0x3fff,
NULL, HFILL }
},
{&hf_lon_app,
{"Application", "lon.application",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_app_code,
{"Code", "lon.code",
FT_UINT8, BASE_HEX, NULL, 0x3f,
NULL, HFILL }
},
{&hf_lon_nm,
{"Network Management", "lon.nm",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_nm_code,
{"Code", "lon.code",
FT_UINT8, BASE_HEX, VALS(nm_code_vs), 0xff,
NULL, HFILL }
},
{&hf_lon_nd,
{"Network Diagnostic", "lon.nd",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_nd_code,
{"Code", "lon.code",
FT_UINT8, BASE_HEX, VALS(nd_code_vs), 0xff,
NULL, HFILL }
},
{&hf_lon_ff,
{"Foreign Frame", "lon.ff",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{&hf_lon_ff_code,
{"Code", "lon.code",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }
},
{&hf_lon_name,
{"Node name", "lon.name",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#if 0
{&hf_lon_checksum,
{"Checksum", "lon.chksum",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
}
#endif
};
static gint *ett[] =
{
&ett_lon,
&ett_address,
&ett_ppdu,
&ett_npdu,
&ett_tpdu,
&ett_spdu,
&ett_authpdu,
&ett_apdu,
&ett_nv,
&ett_app,
&ett_nm,
&ett_nd,
&ett_ff
};
static ei_register_info ei[] = {
{ &ei_lon_tpdu_tpdu_type_unknown, { "lon.tpdu_type.unknown", PI_PROTOCOL, PI_WARN, "Unexpected TPDU type", EXPFILL }},
{ &ei_lon_tpdu_spdu_type_unknown, { "lon.spdu_type.unknown", PI_PROTOCOL, PI_WARN, "Unexpected SPDU type", EXPFILL }},
{ &ei_lon_tpdu_authpdu_type_unknown, { "lon.authpdu_type.unknown", PI_PROTOCOL, PI_WARN, "Unexpected AuthPDU type", EXPFILL }},
{ &ei_lon_tpdu_apdu_dest_type, { "lon.authpdu_dest_type.unknown", PI_PROTOCOL, PI_WARN, "Malformed APDU destin&type", EXPFILL }},
};
expert_module_t* expert_lon;
proto_lon = proto_register_protocol("Local Operating Network",
"LON", "lon");
proto_register_field_array (proto_lon, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_lon = expert_register_protocol(proto_lon);
expert_register_field_array(expert_lon, ei, array_length(ei));
}
void
proto_reg_handoff_lon(void)
{
dissector_handle_t lon_handle;
lon_handle = create_dissector_handle(dissect_lon, proto_lon);
dissector_add_uint("cnip.protocol", 0, lon_handle);
}
