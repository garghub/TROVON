void proto_register_h248_dot2(void) {
static hf_register_info hf[] = {
#if 0
{ &hf_h248_2_dtone_evt,
{ "Discriminating Tone Type", "h248.2.dtt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
#endif
{ &hf_h248_2_dtone_dtt_obs_evt,
{ "Discriminating Tone Type(dtt)", "h248.2.dtt",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_h248_2_dtone_dtt_obs_evt_val,
{ "call type", "h248.2.dtt.val",
FT_UINT32, BASE_DEC, VALS(hf_h248_2_dtone_dtt_obs_evt_val_values) , 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_h248_2,
&ett_h248_2_dtone_dtt_obs_evt,
};
proto_h248_2 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h248_2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h248_register_package(&h248_pkg_ctype,MERGE_PKG_HIGH);
}
