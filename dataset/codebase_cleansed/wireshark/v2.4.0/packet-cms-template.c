static void
cms_verify_msg_digest(proto_item *pi, tvbuff_t *content, const char *alg, tvbuff_t *tvb, int offset)
{
int i= 0, buffer_size = 0;
if(strcmp(alg, HASH_SHA1) == 0) {
gcry_md_hash_buffer(GCRY_MD_SHA1, digest_buf, tvb_get_ptr(content, 0, tvb_captured_length(content)), tvb_captured_length(content));
buffer_size = HASH_SHA1_LENGTH;
} else if(strcmp(alg, HASH_MD5) == 0) {
gcry_md_hash_buffer(GCRY_MD_MD5, digest_buf, tvb_get_ptr(content, 0, tvb_captured_length(content)), tvb_captured_length(content));
buffer_size = HASH_MD5_LENGTH;
}
if(buffer_size) {
if(tvb_bytes_exist(tvb, offset, buffer_size) &&
(tvb_memeql(tvb, offset, digest_buf, buffer_size) != 0)) {
proto_item_append_text(pi, " [incorrect, should be ");
for(i = 0; i < buffer_size; i++)
proto_item_append_text(pi, "%02X", digest_buf[i]);
proto_item_append_text(pi, "]");
}
else
proto_item_append_text(pi, " [correct]");
} else {
proto_item_append_text(pi, " [unable to verify]");
}
}
void proto_register_cms(void) {
static hf_register_info hf[] = {
{ &hf_cms_ci_contentType,
{ "contentType", "cms.contentInfo.contentType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-cms-hfarr.c"
};
static gint *ett[] = {
#include "packet-cms-ettarr.c"
};
proto_cms = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_cms, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_ber_syntax_dissector("ContentInfo", proto_cms, dissect_ContentInfo_PDU);
register_ber_syntax_dissector("SignedData", proto_cms, dissect_SignedData_PDU);
register_ber_oid_syntax(".p7s", NULL, "ContentInfo");
register_ber_oid_syntax(".p7m", NULL, "ContentInfo");
register_ber_oid_syntax(".p7c", NULL, "ContentInfo");
}
void proto_reg_handoff_cms(void) {
dissector_handle_t content_info_handle;
#include "packet-cms-dis-tab.c"
oid_add_from_string("id-data","1.2.840.113549.1.7.1");
oid_add_from_string("id-alg-des-ede3-cbc","1.2.840.113549.3.7");
oid_add_from_string("id-alg-des-cbc","1.3.14.3.2.7");
content_info_handle = create_dissector_handle (dissect_ContentInfo_PDU, proto_cms);
dissector_add_string("media_type", "application/pkcs7-mime", content_info_handle);
dissector_add_string("media_type", "application/pkcs7-signature", content_info_handle);
}
