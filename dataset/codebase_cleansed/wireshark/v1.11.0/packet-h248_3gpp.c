static void dissect_3gcsd_plmnbc(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* cu _U_, void* implicit_param) {
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
dissect_ber_octet_string(implicit_param ? *((gboolean*)implicit_param) : FALSE, &asn1_ctx, tree, tvb, 0, hfid, NULL);
de_bearer_cap(tvb, tree, pinfo, 4, tvb_length(tvb)-4, NULL, 0);
}
static void dissect_3GTFO_codec_mode(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* cu _U_, void* ignored _U_) {
tvbuff_t* sub_tvb = NULL;
gint8 appclass;
gboolean pc;
gint32 tag;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
get_ber_identifier(tvb, 0, &appclass, &pc, &tag);
if (tag==BER_UNI_TAG_OCTETSTRING) {
dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, 0, hfid, &sub_tvb );
if (sub_tvb) {
proto_tree* pt = proto_item_add_subtree(asn1_ctx.created_item, ett_h248_3GTFO_codec);
dissect_codec_mode(pt, sub_tvb, 0, tvb_length(tvb));
}
} else {
proto_tree_add_item(tree,hfid,tvb,0,-1,ENC_NA);
}
}
static void dissect_3GTFO_codec_list(proto_tree* tree, tvbuff_t* tvb, packet_info* pinfo, int hfid, h248_curr_info_t* cu _U_, void* ignored _U_) {
tvbuff_t* sub_tvb = NULL;
gint8 appclass;
gboolean pc;
gint32 tag;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
get_ber_identifier(tvb, 0, &appclass, &pc, &tag);
if (tag==BER_UNI_TAG_OCTETSTRING) {
dissect_ber_octet_string(FALSE, &asn1_ctx, tree, tvb, 0, hfid, &sub_tvb );
if (sub_tvb) {
proto_tree* pt = proto_item_add_subtree(asn1_ctx.created_item,ett_h248_3GTFO_codec_list);
int len = tvb_length(sub_tvb);
int offset = 0;
do {
offset = dissect_codec_mode(pt, sub_tvb, offset, len);
} while(offset < len);
}
} else {
proto_tree_add_item(tree,hfid,tvb,0,-1,ENC_NA);
}
}
void proto_register_h248_3gpp(void) {
static hf_register_info hf[] = {
{ &hf_h248_package_3GUP_Mode,
{ "Mode", "h248.package_3GUP.Mode",
FT_UINT32, BASE_DEC, VALS(h248_3GUP_Mode_vals), 0,
NULL, HFILL }},
{ &hf_h248_package_3GUP_UPversions,
{ "UPversions", "h248.package_3GUP.upversions",
FT_UINT32, BASE_DEC, VALS(h248_3GUP_upversions_vals), 0,
NULL, HFILL }},
{ &hf_h248_package_3GUP_delerrsdu,
{ "Delivery of erroneous SDUs", "h248.package_3GUP.delerrsdu",
FT_UINT32, BASE_DEC, VALS(h248_3GUP_delerrsdu_vals), 0,
NULL, HFILL }},
{ &hf_h248_package_3GUP_interface,
{ "Interface", "h248.package_3GUP.interface",
FT_UINT32, BASE_DEC, VALS(h248_3GUP_interface_vals), 0,
NULL, HFILL }},
{ &hf_h248_package_3GUP_initdir,
{ "Initialisation Direction", "h248.package_3GUP.initdir",
FT_UINT32, BASE_DEC, VALS(h248_3GUP_initdir_vals), 0,
NULL, HFILL }},
{ &hf_h248_package_3GCSD,
{ "CSD Package", "h248.package_3GCSD",
FT_BYTES, BASE_NONE, NULL, 0,
"Circuit Switched Data Package", HFILL }},
{ &hf_h248_package_3GCSD_plmnbc,
{ "PLMN Bearer Capability", "h248.package_3GCSD.plmnbc",
FT_BYTES, BASE_NONE, NULL, 0,
"The PLMN Bearer Capability", HFILL }},
{ &hf_h248_package_3GCSD_gsmchancod,
{ "GSM channel coding", "h248.package_3GCSD.gsmchancod",
FT_BYTES, BASE_NONE, NULL, 0,
"Channel information needed for GSM", HFILL }},
{ &hf_h248_pkg_3GCSD_evt_protres,
{ "Protocol Negotiation Result", "h248.package_3GCSD.protres",
FT_BYTES, BASE_NONE, NULL, 0,
"This event is used to report the result of the protocol negotiation", HFILL }},
{ &hf_h248_pkg_3GCSD_evt_protres_result,
{ "Negotiation Result", "h248.package_3GCSD.protres.result",
FT_UINT32, BASE_DEC, VALS(h248_3GCSD_evt_protres_result_vals), 0,
"reports whether the protocol negotiation has been successful", HFILL }},
{ &hf_h248_pkg_3GCSD_evt_protres_cause,
{ "Possible Failure Cause", "h248.package_3GCSD.protres.cause",
FT_UINT32, BASE_DEC, VALS(h248_3GCSD_evt_protres_cause_vals), 0,
"indicates the possible failure cause", HFILL }},
{ &hf_h248_pkg_3GCSD_evt_ratechg,
{ "Rate Change", "h248.package_3GCSD.ratechg",
FT_BYTES, BASE_NONE, NULL, 0,
"This event is used to report a rate change", HFILL }},
{ &hf_h248_pkg_3GCSD_evt_ratechg_rate,
{ "New Rate", "h248.package_3GCSD.ratechg.rate",
FT_UINT32, BASE_DEC, NULL, 0,
"reports the new rate for the termination", HFILL }},
{ &hf_h248_pkg_3GCSD_sig_actprot,
{ "Activate Protocol", "h248.package_3GCSD.actprot",
FT_BYTES, BASE_NONE, NULL, 0,
"Activate the higher layer protocol", HFILL }},
{ &hf_h248_pkg_3GCSD_actprot_sig_localpeer,
{ "Local Peer Role", "h248.package_3GCSD.actprot.localpeer",
FT_UINT32, BASE_DEC, VALS(h248_3GCSD_actprot_sig_localpeer_vals), 0,
"It is used to inform the modem whether it should act as originating or terminating peer", HFILL }},
{ &hf_h248_package_3GTFO,
{ "Tandem Free Operation", "h248.package_3GTFO",
FT_BYTES, BASE_NONE, NULL, 0,
"This package defines events and properties for Tandem Free Operation (TFO) control", HFILL }},
{ &hf_h248_pkg_3GTFO_enable,
{ "TFO Activity Control", "h248.package_3GTFO.tfoenable",
FT_UINT32, BASE_DEC, VALS(tfoenable_vals), 0,
"Defines if TFO is enabled or not", HFILL }},
{ &hf_h248_pkg_3GTFO_codeclist,
{ "TFO Codec List", "h248.package_3GTFO.codeclist",
FT_BYTES, BASE_NONE, NULL, 0,
"List of codecs for use in TFO protocol", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_codec_modify,
{ "Optimal Codec Event", "h248.package_3GTFO.codec_modify",
FT_BYTES, BASE_NONE, NULL, 0,
"The event is used to notify the MGC that TFO negotiation has resulted in an optimal codec type being proposed", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_codec_modify_optimalcodec,
{ "Optimal Codec Type", "h248.package_3GTFO.codec_modify.optimalcodec",
FT_BYTES, BASE_NONE, NULL, 0,
"indicates which is the proposed codec type for TFO", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_distant_codec_list,
{ "Codec List Event", "h248.package_3GTFO.distant_codec_list",
FT_BYTES, BASE_NONE, NULL, 0,
"The event is used to notify the MGC of the distant TFO partner's supported codec list", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_distant_codec_list_distlist,
{ "Distant Codec List", "h248.package_3GTFO.distant_codec_list.distlist",
FT_BYTES, BASE_NONE, NULL, 0,
"indicates the codec list for TFO", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_status,
{ "TFO Status Event", "h248.package_3GTFO.status",
FT_BYTES, BASE_NONE, NULL, 0,
"The event is used to notify the MGC that a TFO link has been established or broken", HFILL }},
{ &hf_h248_pkg_3GTFO_evt_status_tfostatus,
{ "TFO Status", "h248.package_3GTFO.status.tfostatus",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"reports whether TFO has been established or broken", HFILL }},
};
static gint *ett[] = {
&ett_h248_package_3GUP,
&ett_h248_package_3GCSD,
&ett_h248_3GCSD_evt_protres,
&ett_h248_3GCSD_evt_ratechg,
&ett_h248_package_3GTFO,
&ett_h248_3GTFO_evt_status,
&ett_h248_3GTFO_evt_distant_codec_list,
&ett_h248_3GTFO_evt_codec_modify,
&ett_h248_3GTFO_codec_list,
&ett_h248_3GTFO_codec,
&ett_pkg_3GCSD_sig_actprot
};
proto_h248_package_3GUP = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h248_package_3GUP, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h248_register_package(&h248_package_3GUP,REPLACE_PKG);
h248_register_package(&h248_package_3GCSD, REPLACE_PKG);
h248_register_package(&h248_package_3GTFO, REPLACE_PKG);
}
