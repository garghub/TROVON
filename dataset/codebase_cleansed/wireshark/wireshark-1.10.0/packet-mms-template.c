static void
dissect_mms(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
int offset = 0;
int old_offset;
proto_item *item=NULL;
proto_tree *tree=NULL;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if(parent_tree){
item = proto_tree_add_item(parent_tree, proto_mms, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_mms);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MMS");
col_clear(pinfo->cinfo, COL_INFO);
while (tvb_reported_length_remaining(tvb, offset) > 0){
old_offset=offset;
offset=dissect_mms_MMSpdu(FALSE, tvb, offset, &asn1_ctx , tree, -1);
if(offset == old_offset){
proto_tree_add_text(tree, tvb, offset, -1,"Internal error, zero-byte MMS PDU");
break;
}
}
}
void proto_register_mms(void) {
static hf_register_info hf[] =
{
#include "packet-mms-hfarr.c"
};
static gint *ett[] = {
&ett_mms,
#include "packet-mms-ettarr.c"
};
proto_mms = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("mms", dissect_mms, proto_mms);
proto_register_field_array(proto_mms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
static gboolean
dissect_mms_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void *data _U_)
{
int offset = 0;
guint32 length = 0 ;
guint32 oct;
gint idx = 0 ;
gint8 tmp_class;
gboolean tmp_pc;
gint32 tmp_tag;
if (!tvb_bytes_exist(tvb, 0, 2))
return FALSE;
offset = get_ber_identifier(tvb, offset, &tmp_class, &tmp_pc, &tmp_tag);
if (tmp_class!=BER_CLASS_CON)
return FALSE;
try_val_to_str_idx(tmp_tag, mms_MMSpdu_vals, &idx);
if (idx == -1) {
return FALSE;
}
oct = tvb_get_guint8(tvb, offset)& 0x7F;
if (oct==0)
return FALSE;
offset = get_ber_length(tvb, offset, &length, NULL);
if (!tvb_bytes_exist(tvb, offset, length))
return FALSE;
dissect_mms(tvb, pinfo, parent_tree);
return TRUE;
}
void proto_reg_handoff_mms(void) {
register_ber_oid_dissector("1.0.9506.2.3", dissect_mms, proto_mms,"MMS");
register_ber_oid_dissector("1.0.9506.2.1", dissect_mms, proto_mms,"mms-abstract-syntax-version1(1)");
heur_dissector_add("cotp", dissect_mms_heur, proto_mms);
heur_dissector_add("cotp_is", dissect_mms_heur, proto_mms);
}
