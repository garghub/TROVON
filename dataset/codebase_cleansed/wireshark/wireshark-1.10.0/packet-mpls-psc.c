static void
dissect_mpls_psc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *psc_tree;
guint32 offset = 0;
guint8 req;
guint8 fpath;
guint8 path;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PSC");
col_clear(pinfo->cinfo, COL_INFO);
req = (tvb_get_guint8(tvb, offset) & 0x3C) >> 2;
fpath = tvb_get_guint8(tvb, offset + 2);
path = tvb_get_guint8(tvb, offset + 3);
col_add_fstr(pinfo->cinfo, COL_INFO,
"%s(%u,%u)",
val_to_str_const(req, mpls_psc_req_short_vals, "Unknown-Request"),
fpath, path);
if (!tree) {
return;
}
ti = proto_tree_add_item(tree, proto_mpls_psc, tvb, 0, -1, ENC_NA);
psc_tree = proto_item_add_subtree(ti, ett_mpls_psc);
proto_tree_add_item(psc_tree, hf_mpls_psc_ver, tvb, offset, 1, ENC_NA);
proto_tree_add_item(psc_tree, hf_mpls_psc_req, tvb, offset, 1, ENC_NA);
proto_tree_add_item(psc_tree, hf_mpls_psc_pt, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(psc_tree, hf_mpls_psc_rev, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(psc_tree, hf_mpls_psc_fpath, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(psc_tree, hf_mpls_psc_dpath, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(psc_tree, hf_mpls_psc_tlvlen, tvb, offset, 1, ENC_BIG_ENDIAN);
}
void
proto_register_mpls_psc(void)
{
static hf_register_info hf[] = {
{
&hf_mpls_psc_ver,
{
"Version", "mpls_psc.ver",
FT_UINT8, BASE_DEC, NULL, 0xC0,
NULL, HFILL
}
},
{
&hf_mpls_psc_req,
{
"Request", "mpls_psc.req",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_psc_req_rvals), 0x3C,
NULL, HFILL
}
},
{
&hf_mpls_psc_pt,
{
"Protection Type", "mpls_psc.pt",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_psc_pt_rvals), 0x03,
NULL, HFILL
}
},
{
&hf_mpls_psc_rev,
{
"R", "mpls_psc.rev",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_psc_rev_rvals), 0x80,
NULL, HFILL
}
},
{
&hf_mpls_psc_fpath,
{
"Fault Path", "mpls_psc.fpath",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_psc_fpath_rvals), 0x0,
NULL, HFILL
}
},
{
&hf_mpls_psc_dpath,
{
"Data Path", "mpls_psc.dpath",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(mpls_psc_dpath_rvals), 0x0,
NULL, HFILL
}
},
{
&hf_mpls_psc_tlvlen,
{
"TLV Length", "mpls_psc.tlvlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_mpls_psc,
};
proto_mpls_psc =
proto_register_protocol("PSC", "MPLS[-TP] Protection State "
"Coordination (PSC) Protocol",
"mpls_psc");
proto_register_field_array(proto_mpls_psc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mpls_psc", dissect_mpls_psc, proto_mpls_psc);
}
