static void
dissect_attrs (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint8 type;
guint16 length;
int pos = 0;
gint total_len;
proto_item *cmid_it, *tekp_it, *scap_it;
proto_item *saqry_it, *dnld_it, *sadsc_it;
proto_tree *cmid_tree, *tekp_tree, *scap_tree;
proto_tree *saqry_tree, *dnld_tree, *sadsc_tree;
tvbuff_t *cmid_tvb, *tekp_tvb, *scap_tvb;
tvbuff_t *saqry_tvb, *dnld_tvb, *sadsc_tvb;
total_len = tvb_reported_length_remaining (tvb, 0);
while (pos < total_len)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_ntohs (tvb, pos);
pos += 2;
switch (type)
{
case BPKM_RESERVED:
break;
case BPKM_SERIAL_NUM:
proto_tree_add_item (tree, hf_docsis_bpkmattr_serial_num, tvb, pos,
length, ENC_ASCII|ENC_NA);
break;
case BPKM_MANUFACTURER_ID:
if (length == 3)
proto_tree_add_item (tree, hf_docsis_bpkmattr_manf_id, tvb, pos,
length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_MAC_ADDR:
if (length == 6)
proto_tree_add_item (tree, hf_docsis_bpkmattr_mac_addr, tvb, pos,
length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_RSA_PUB_KEY:
proto_tree_add_item (tree, hf_docsis_bpkmattr_rsa_pub_key, tvb, pos,
length, ENC_NA);
break;
case BPKM_CM_ID:
cmid_it =
proto_tree_add_text (tree, tvb, pos, length,
"5 CM Identification");
cmid_tree =
proto_item_add_subtree (cmid_it, ett_docsis_bpkmattr_cmid);
cmid_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (cmid_tvb, pinfo, cmid_tree);
break;
case BPKM_DISPLAY_STR:
proto_tree_add_item (tree, hf_docsis_bpkmattr_display_str, tvb, pos,
length, ENC_ASCII|ENC_NA);
break;
case BPKM_AUTH_KEY:
if ((length == 96) || (length == 128))
proto_tree_add_item (tree, hf_docsis_bpkmattr_auth_key, tvb, pos,
length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_TEK:
if (length == 8 || length == 16)
proto_tree_add_item (tree, hf_docsis_bpkmattr_tek, tvb, pos,
length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_KEY_LIFETIME:
if (length == 4)
proto_tree_add_item (tree, hf_docsis_bpkmattr_key_life, tvb, pos,
length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_KEY_SEQ_NUM:
if (length == 1)
proto_tree_add_item (tree, hf_docsis_bpkmattr_key_seq, tvb, pos,
length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_HMAC_DIGEST:
if (length == 20)
proto_tree_add_item (tree, hf_docsis_bpkmattr_hmac_digest, tvb,
pos, length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_SAID:
if (length == 2)
proto_tree_add_item (tree, hf_docsis_bpkmattr_said, tvb, pos,
length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_TEK_PARAM:
tekp_it =
proto_tree_add_text (tree, tvb, pos, length, "13 TEK Parameters");
tekp_tree =
proto_item_add_subtree (tekp_it, ett_docsis_bpkmattr_tekp);
tekp_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (tekp_tvb, pinfo, tekp_tree);
break;
case BPKM_OBSOLETED:
break;
case BPKM_CBC_IV:
if (length == 8 || length == 16)
proto_tree_add_item (tree, hf_docsis_bpkmattr_cbc_iv, tvb, pos,
length, ENC_NA);
else
THROW (ReportedBoundsError);
break;
case BPKM_ERROR_CODE:
if (length == 1)
proto_tree_add_item (tree, hf_docsis_bpkmattr_error_code, tvb,
pos, length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_CA_CERT:
proto_tree_add_item (tree, hf_docsis_bpkmattr_ca_cert, tvb, pos,
length, ENC_NA);
break;
case BPKM_CM_CERT:
proto_tree_add_item (tree, hf_docsis_bpkmattr_cm_cert, tvb, pos,
length, ENC_NA);
break;
case BPKM_SEC_CAPABILITIES:
scap_it =
proto_tree_add_text (tree, tvb, pos, length,
"19 Security Capabilities");
scap_tree =
proto_item_add_subtree (scap_it, ett_docsis_bpkmattr_scap);
scap_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (scap_tvb, pinfo, scap_tree);
break;
case BPKM_CRYPTO_SUITE:
if (length == 2)
proto_tree_add_item (tree, hf_docsis_bpkmattr_crypto_suite, tvb,
pos, length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_CRYPTO_SUITE_LIST:
proto_tree_add_item (tree, hf_docsis_bpkmattr_crypto_suite_list,
tvb, pos, length, ENC_NA);
break;
case BPKM_BPI_VERSION:
if (length == 1)
proto_tree_add_item (tree, hf_docsis_bpkmattr_bpi_version, tvb,
pos, length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_SA_DESCRIPTOR:
sadsc_it =
proto_tree_add_text (tree, tvb, pos, length, "23 SA Descriptor");
sadsc_tree =
proto_item_add_subtree (sadsc_it, ett_docsis_bpkmattr_sadsc);
sadsc_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (sadsc_tvb, pinfo, sadsc_tree);
break;
case BPKM_SA_TYPE:
if (length == 1)
proto_tree_add_item (tree, hf_docsis_bpkmattr_sa_type, tvb, pos,
length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_SA_QUERY:
saqry_it =
proto_tree_add_text (tree, tvb, pos, length, "25 SA Query");
saqry_tree =
proto_item_add_subtree (saqry_it, ett_docsis_bpkmattr_saqry);
saqry_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (saqry_tvb, pinfo, saqry_tree);
break;
case BPKM_SA_QUERY_TYPE:
if (length == 1)
proto_tree_add_item (tree, hf_docsis_bpkmattr_sa_query_type, tvb,
pos, length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_IP_ADDRESS:
if (length == 4)
proto_tree_add_item (tree, hf_docsis_bpkmattr_ip_address, tvb,
pos, length, ENC_BIG_ENDIAN);
else
THROW (ReportedBoundsError);
break;
case BPKM_VENDOR_DEFINED:
proto_tree_add_item (tree, hf_docsis_bpkmattr_vendor_def, tvb, pos,
length, ENC_NA);
break;
case BPKM_DNLD_PARAMS:
dnld_it =
proto_tree_add_text (tree, tvb, pos, length,
"28 Download Parameters");
dnld_tree =
proto_item_add_subtree (dnld_it, ett_docsis_bpkmattr_dnld);
dnld_tvb = tvb_new_subset (tvb, pos, length, length);
dissect_attrs (dnld_tvb, pinfo, dnld_tree);
break;
default:
proto_tree_add_item (tree, hf_docsis_bpkmattr_vendor_def, tvb, pos,
length, ENC_NA);
break;
}
pos += length;
}
}
static void
dissect_bpkmattr (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *bpkmattr_tree;
if (tree)
{
it =
proto_tree_add_protocol_format (tree, proto_docsis_bpkmattr, tvb, 0, -1,
"BPKM Attributes");
bpkmattr_tree = proto_item_add_subtree (it, ett_docsis_bpkmattr);
dissect_attrs (tvb, pinfo, bpkmattr_tree);
}
}
void
proto_register_docsis_bpkmattr (void)
{
static hf_register_info hf[] = {
{&hf_docsis_bpkmattr_serial_num,
{"1 Serial Number", "docsis_bpkmattr.serialnum",
FT_STRING, BASE_NONE, NULL, 0x0,
"Serial Number", HFILL}
},
{&hf_docsis_bpkmattr_manf_id,
{"2 Manufacturer Id", "docsis_bpkmattr.manfid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Manufacturer Id", HFILL}
},
{&hf_docsis_bpkmattr_mac_addr,
{"3 Mac Address", "docsis_bpkmattr.macaddr",
FT_ETHER, BASE_NONE, NULL, 0x0,
"Mac Address", HFILL}
},
{&hf_docsis_bpkmattr_rsa_pub_key,
{"4 RSA Public Key", "docsis_bpkmattr.rsa_pub_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"RSA Public Key", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_cm_id,
{"5 CM Identification", "docsis_bpkmattr.cmid",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CM Identification", HFILL}
},
#endif
{&hf_docsis_bpkmattr_display_str,
{"6 Display String", "docsis_bpkmattr.dispstr",
FT_STRING, BASE_NONE, NULL, 0x0,
"Display String", HFILL}
},
{&hf_docsis_bpkmattr_auth_key,
{"7 Auth Key", "docsis_bpkmattr.auth_key",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Auth Key", HFILL}
},
{&hf_docsis_bpkmattr_tek,
{"8 Traffic Encryption Key", "docsis_bpkmattr.tek",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Traffic Encryption Key", HFILL}
},
{&hf_docsis_bpkmattr_key_life,
{"9 Key Lifetime (s)", "docsis_bpkmattr.keylife",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Key Lifetime (s)", HFILL}
},
{&hf_docsis_bpkmattr_key_seq,
{"10 Key Sequence Number", "docsis_bpkmattr.keyseq",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Key Sequence Number", HFILL}
},
{&hf_docsis_bpkmattr_hmac_digest,
{"11 HMAC Digest", "docsis_bpkmattr.hmacdigest",
FT_BYTES, BASE_NONE, NULL, 0x0,
"HMAC Digest", HFILL}
},
{&hf_docsis_bpkmattr_said,
{"12 SAID", "docsis_bpkmattr.said",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Security Association ID", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_tek_params,
{"13 TEK Parameters", "docsis_bpkmattr.tekparams",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TEK Parameters", HFILL}
},
#endif
{&hf_docsis_bpkmattr_cbc_iv,
{"14 CBC IV", "docsis_bpkmattr.cbciv",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Cypher Block Chaining", HFILL}
},
{&hf_docsis_bpkmattr_error_code,
{"16 Error Code", "docsis_bpkmattr.errcode",
FT_UINT8, BASE_DEC, VALS (error_code_vals), 0x0,
"Error Code", HFILL}
},
{&hf_docsis_bpkmattr_vendor_def,
{"127 Vendor Defined", "docsis_bpkmattr.vendordef",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Vendor Defined", HFILL}
},
{&hf_docsis_bpkmattr_ca_cert,
{"17 CA Certificate", "docsis_bpkmattr.cacert",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CA Certificate", HFILL}
},
{&hf_docsis_bpkmattr_cm_cert,
{"18 CM Certificate", "docsis_bpkmattr.cmcert",
FT_BYTES, BASE_NONE, NULL, 0x0,
"CM Certificate", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_security_cap,
{"19 Security Capabilities", "docsis_bpkmattr.seccap",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Security Capabilities", HFILL}
},
#endif
{&hf_docsis_bpkmattr_crypto_suite,
{"20 Cryptographic Suite", "docsis_bpkmattr.cryptosuite",
FT_UINT16, BASE_HEX, VALS(crypto_suite_attr_vals), 0x0,
"Cryptographic Suite", HFILL}
},
{&hf_docsis_bpkmattr_crypto_suite_list,
{"21 Cryptographic Suite List", "docsis_bpkmattr.crypto_suite_lst",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Cryptographic Suite", HFILL}
},
{&hf_docsis_bpkmattr_bpi_version,
{"22 BPI Version", "docsis_bpkmattr.bpiver",
FT_UINT8, BASE_DEC, VALS (bpi_ver_vals), 0x0,
"BPKM Attributes", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_sa_descr,
{"23 SA Descriptor", "docsis_bpkmattr.sadescr",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Descriptor", HFILL}
},
#endif
{&hf_docsis_bpkmattr_sa_type,
{"24 SA Type", "docsis_bpkmattr.satype",
FT_UINT8, BASE_DEC, NULL, 0x0,
"SA Type", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_sa_query,
{"25 SA Query", "docsis_bpkmattr.saquery",
FT_BYTES, BASE_NONE, NULL, 0x0,
"SA Query", HFILL}
},
#endif
{&hf_docsis_bpkmattr_sa_query_type,
{"26 SA Query Type", "docsis_bpkmattr.saquery_type",
FT_UINT8, BASE_HEX, NULL, 0x0,
"SA Query Type", HFILL}
},
{&hf_docsis_bpkmattr_ip_address,
{"27 IP Address", "docsis_bpkmattr.ipaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"IP Address", HFILL}
},
#if 0
{&hf_docsis_bpkmattr_download_param,
{"28 Download Parameters", "docsis_bpkmattr.dnld_params",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Download Parameters", HFILL}
},
#endif
};
static gint *ett[] = {
&ett_docsis_bpkmattr,
&ett_docsis_bpkmattr_cmid,
&ett_docsis_bpkmattr_scap,
&ett_docsis_bpkmattr_tekp,
&ett_docsis_bpkmattr_sadsc,
&ett_docsis_bpkmattr_saqry,
&ett_docsis_bpkmattr_dnld
};
proto_docsis_bpkmattr =
proto_register_protocol
("DOCSIS Baseline Privacy Key Management Attributes", "DOCSIS BPKM-ATTR",
"docsis_bpkmattr");
proto_register_field_array (proto_docsis_bpkmattr, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_bpkmattr", dissect_bpkmattr,
proto_docsis_bpkmattr);
}
void
proto_reg_handoff_docsis_bpkmattr (void)
{
#if 0
dissector_handle_t docsis_bpkmattr_handle;
docsis_bpkmattr_handle = find_dissector ("docsis_bpkmattr");
dissector_add_uint ("docsis", 0xFE, docsis_bpkmattr_handle);
#endif
}
