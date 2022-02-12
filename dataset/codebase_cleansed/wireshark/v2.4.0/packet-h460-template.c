static int
dissect_ies(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
if (q931_ie_handle) {
call_dissector(q931_ie_handle, tvb, pinfo, tree);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_ras(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
int offset = 0;
if (h225_ras_handle) {
call_dissector(h225_ras_handle, tvb, pinfo, tree);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static h460_feature_t *find_ftr(const gchar *key) {
h460_feature_t *ftr = NULL;
h460_feature_t *f;
for (f=h460_feature_tab; f->id; f++) {
if (f->key_gd && !strcmp(key, f->key_gd)) { ftr = f; break; }
if (f->key_fd && !strcmp(key, f->key_fd)) { ftr = f; break; }
if (f->key_gm && !strcmp(key, f->key_gm)) { ftr = f; break; }
if (f->key_gi && !strcmp(key, f->key_gi)) { ftr = f; break; }
}
return ftr;
}
static int
dissect_h460_name(tvbuff_t *tvb _U_, packet_info *pinfo, proto_tree *tree, void *data) {
int offset = 0;
asn1_ctx_t *actx;
h460_feature_t *ftr;
if (data == NULL)
return 0;
actx = get_asn1_ctx(data);
DISSECTOR_ASSERT(actx);
if (tree) {
ftr = find_ftr(pinfo->match_string);
if (ftr) {
proto_item_append_text(actx->created_item, " - %s", ftr->name);
proto_item_append_text(proto_item_get_parent(proto_tree_get_parent(tree)), ": %s", ftr->name);
} else {
proto_item_append_text(actx->created_item, " - unknown(%s)", pinfo->match_string);
}
}
return offset;
}
void proto_register_h460(void) {
h460_feature_t *ftr;
static hf_register_info hf[] = {
#include "packet-h460-hfarr.c"
};
static gint *ett[] = {
#include "packet-h460-ettarr.c"
};
proto_h460 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_h460, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
for (ftr=h460_feature_tab; ftr->id; ftr++) {
if (ftr->opt & GD) ftr->key_gd = wmem_strdup_printf(wmem_epan_scope(), "GenericData/%s", ftr->id);
if (ftr->opt & FD) ftr->key_fd = wmem_strdup_printf(wmem_epan_scope(), "FeatureDescriptor/%s", ftr->id);
if (ftr->opt & GM) ftr->key_gm = wmem_strdup_printf(wmem_epan_scope(), "GenericMessage/%s", ftr->id);
if (ftr->opt & GI) ftr->key_gi = wmem_strdup_printf(wmem_epan_scope(), "GenericInformation/%s", ftr->id);
if (ftr->content_pdu) ftr->content_hnd = create_dissector_handle(ftr->content_pdu, proto_h460);
}
}
void proto_reg_handoff_h460(void)
{
h460_feature_t *ftr;
dissector_handle_t h460_name_handle;
q931_ie_handle = find_dissector_add_dependency("q931.ie", proto_h460);
h225_ras_handle = find_dissector_add_dependency("h225.ras", proto_h460);
h460_name_handle = create_dissector_handle(dissect_h460_name, proto_h460);
for (ftr=h460_feature_tab; ftr->id; ftr++) {
if (ftr->key_gd) dissector_add_string("h225.gef.name", ftr->key_gd, h460_name_handle);
if (ftr->key_fd) dissector_add_string("h225.gef.name", ftr->key_fd, h460_name_handle);
if (ftr->key_gm) dissector_add_string("h245.gef.name", ftr->key_gm, h460_name_handle);
if (ftr->key_gi) dissector_add_string("h245.gef.name", ftr->key_gi, h460_name_handle);
if (ftr->content_hnd) {
if (ftr->key_gd) dissector_add_string("h225.gef.content", ftr->key_gd, ftr->content_hnd);
if (ftr->key_fd) dissector_add_string("h225.gef.content", ftr->key_fd, ftr->content_hnd);
if (ftr->key_gm) dissector_add_string("h245.gef.content", ftr->key_gm, ftr->content_hnd);
if (ftr->key_gi) dissector_add_string("h245.gef.content", ftr->key_gi, ftr->content_hnd);
}
}
}
