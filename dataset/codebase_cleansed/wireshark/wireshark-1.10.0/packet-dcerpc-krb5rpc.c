static int
krb5rpc_dissect_sendto_kdc_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
guint8 *drep)
{
guint32 keysize, spare1, remain;
proto_item *item;
tvbuff_t *krb5_tvb;
proto_tree *subtree;
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_rqst_keysize, &keysize);
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_rqst_spare1, &spare1);
item = proto_tree_add_item (tree, hf_krb5rpc_krb5, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree (item, ett_krb5rpc_krb5);
remain = tvb_length_remaining(tvb, offset);
krb5_tvb = tvb_new_subset (tvb, offset, remain, remain);
offset = dissect_kerberos_main (krb5_tvb, pinfo, subtree, TRUE, NULL);
return offset;
}
static int
krb5rpc_dissect_sendto_kdc_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
guint8 *drep)
{
guint32 resp_len, maxsize, spare1, keysize, remain;
proto_item *item;
tvbuff_t *krb5_tvb;
proto_tree *subtree;
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_resp_len, &resp_len);
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_resp_max, &maxsize);
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_resp_spare1, &spare1);
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, drep,
hf_krb5rpc_sendto_kdc_resp_keysize, &keysize);
item = proto_tree_add_item (tree, hf_krb5rpc_krb5, tvb, offset, -1, ENC_NA);
subtree = proto_item_add_subtree (item, ett_krb5rpc_krb5);
remain = tvb_length_remaining(tvb, offset);
krb5_tvb = tvb_new_subset (tvb, offset, remain, remain);
offset = dissect_kerberos_main (krb5_tvb, pinfo, subtree, TRUE, NULL);
offset += 16;
return offset;
}
void
proto_register_krb5rpc (void)
{
static hf_register_info hf[] = {
{&hf_krb5rpc_opnum,
{"Opnum", "krb5rpc.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{&hf_krb5rpc_sendto_kdc_rqst_keysize,
{"Request keysize",
"krb5rpc.sendto_kdc_rqst_keysize", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_krb5rpc_sendto_kdc_rqst_spare1,
{"Request spare1",
"krb5rpc.sendto_kdc_rqst_spare1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{&hf_krb5rpc_sendto_kdc_resp_len,
{"Response length", "krb5rpc.sendto_kdc_resp_len",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_krb5rpc_sendto_kdc_resp_max,
{"Response max", "krb5rpc.sendto_kdc_resp_max",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_krb5rpc_sendto_kdc_resp_spare1,
{"Response spare1",
"krb5rpc.sendto_kdc_resp_spare1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{&hf_krb5rpc_sendto_kdc_resp_keysize,
{"Response key size",
"krb5rpc.sendto_kdc_resp_keysize", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
#if 0
{&hf_krb5rpc_sendto_kdc_resp_st,
{"Response st", "krb5rpc.sendto_kdc_resp_st",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
#endif
{&hf_krb5rpc_krb5,
{"krb5", "krb5rpc.krb5", FT_BYTES, BASE_NONE, NULL, 0x0,
"krb5 blob", HFILL}},
};
static gint *ett[] = {
&ett_krb5rpc,
&ett_krb5rpc_krb5,
};
proto_krb5rpc =
proto_register_protocol ("DCE/RPC Kerberos V", "KRB5RPC", "krb5rpc");
proto_register_field_array (proto_krb5rpc, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_krb5rpc (void)
{
dcerpc_init_uuid (proto_krb5rpc, ett_krb5rpc, &uuid_krb5rpc, ver_krb5rpc,
krb5rpc_dissectors, hf_krb5rpc_opnum);
}
