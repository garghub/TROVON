static void *
ess_copy_cb(void *dest, const void *orig, size_t len _U_)
{
ess_category_attributes_t *u = (ess_category_attributes_t *)dest;
const ess_category_attributes_t *o = (ess_category_attributes_t *)orig;
u->oid = g_strdup(o->oid);
u->lacv = o->lacv;
u->name = g_strdup(o->name);
return dest;
}
static void
ess_free_cb(void *r)
{
ess_category_attributes_t *u = (ess_category_attributes_t *)r;
g_free(u->oid);
g_free(u->name);
}
static void
ess_dissect_attribute (guint32 value, asn1_ctx_t *actx)
{
guint i;
for (i = 0; i < num_ess_category_attributes; i++) {
ess_category_attributes_t *u = &(ess_category_attributes[i]);
if ((strcmp (u->oid, object_identifier_id) == 0) &&
(u->lacv == value))
{
proto_item_append_text (actx->created_item, " (%s)", u->name);
break;
}
}
}
static void
ess_dissect_attribute_flags (tvbuff_t *tvb, asn1_ctx_t *actx)
{
proto_tree *tree;
guint8 *value;
guint i;
tree = proto_item_add_subtree (actx->created_item, ett_Category_attributes);
value = tvb_get_ephemeral_string (tvb, 0, tvb_length (tvb));
for (i = 0; i < num_ess_category_attributes; i++) {
ess_category_attributes_t *u = &(ess_category_attributes[i]);
if ((strcmp (u->oid, object_identifier_id) == 0) &&
((u->lacv / 8) < tvb_length (tvb)) &&
(value[u->lacv / 8] & (1 << (7 - (u->lacv % 8)))))
{
proto_tree_add_string_format (tree, hf_ess_Category_attribute, tvb,
u->lacv / 8, 1, u->name,
"%s (%d)", u->name, u->lacv);
}
}
}
void proto_register_ess(void) {
static hf_register_info hf[] = {
{ &hf_ess_SecurityCategory_type_OID,
{ "type", "ess.type_OID", FT_STRING, BASE_NONE, NULL, 0,
"Type of Security Category", HFILL }},
{ &hf_ess_Category_attribute,
{ "Attribute", "ess.attribute", FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-ess-hfarr.c"
};
static gint *ett[] = {
&ett_Category_attributes,
#include "packet-ess-ettarr.c"
};
static uat_field_t attributes_flds[] = {
UAT_FLD_CSTRING(ess_category_attributes,oid, "Tag Set", "Category Tag Set (Object Identifier)"),
UAT_FLD_DEC(ess_category_attributes,lacv, "Value", "Label And Cert Value"),
UAT_FLD_CSTRING(ess_category_attributes,name, "Name", "Category Name"),
UAT_END_FIELDS
};
uat_t *attributes_uat = uat_new("ESS Category Attributes",
sizeof(ess_category_attributes_t),
"ess_category_attributes",
TRUE,
(void**) &ess_category_attributes,
&num_ess_category_attributes,
UAT_AFFECTS_DISSECTION,
"ChEssCategoryAttributes",
ess_copy_cb,
NULL,
ess_free_cb,
NULL,
attributes_flds);
static module_t *ess_module;
proto_ess = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_ess, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ess_module = prefs_register_protocol(proto_ess, NULL);
prefs_register_uat_preference(ess_module, "attributes_table",
"ESS Category Attributes",
"ESS category attributes translation table",
attributes_uat);
}
void proto_reg_handoff_ess(void) {
#include "packet-ess-dis-tab.c"
}
