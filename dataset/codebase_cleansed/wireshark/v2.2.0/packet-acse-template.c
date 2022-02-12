static guint
acse_ctx_oid_hash(gconstpointer k)
{
acse_ctx_oid_t *aco=(acse_ctx_oid_t *)k;
return aco->ctx_id;
}
static gint
acse_ctx_oid_equal(gconstpointer k1, gconstpointer k2)
{
acse_ctx_oid_t *aco1=(acse_ctx_oid_t *)k1;
acse_ctx_oid_t *aco2=(acse_ctx_oid_t *)k2;
return aco1->ctx_id==aco2->ctx_id;
}
static void
acse_init(void)
{
if (acse_ctx_oid_table) {
g_hash_table_destroy(acse_ctx_oid_table);
acse_ctx_oid_table = NULL;
}
acse_ctx_oid_table = g_hash_table_new(acse_ctx_oid_hash,
acse_ctx_oid_equal);
}
static void
register_ctx_id_and_oid(packet_info *pinfo _U_, guint32 idx, char *oid)
{
acse_ctx_oid_t *aco, *tmpaco;
aco=wmem_new(wmem_file_scope(), acse_ctx_oid_t);
aco->ctx_id=idx;
aco->oid=wmem_strdup(wmem_file_scope(), oid);
tmpaco=(acse_ctx_oid_t *)g_hash_table_lookup(acse_ctx_oid_table, aco);
if (tmpaco) {
g_hash_table_remove(acse_ctx_oid_table, tmpaco);
}
g_hash_table_insert(acse_ctx_oid_table, aco, aco);
}
static char *
find_oid_by_ctx_id(packet_info *pinfo _U_, guint32 idx)
{
acse_ctx_oid_t aco, *tmpaco;
aco.ctx_id=idx;
tmpaco=(acse_ctx_oid_t *)g_hash_table_lookup(acse_ctx_oid_table, &aco);
if (tmpaco) {
return tmpaco->oid;
}
return NULL;
}
static int
dissect_acse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
int offset = 0;
proto_item *item;
proto_tree *tree;
char *oid;
struct SESSION_DATA_STRUCTURE* session;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (data == NULL) {
return 0;
}
if (!tvb_bytes_exist(tvb, 0, 2)) {
proto_tree_add_item(parent_tree, hf_acse_user_data, tvb, offset,
tvb_reported_length_remaining(tvb,offset), ENC_NA);
return 0;
}
session = ( (struct SESSION_DATA_STRUCTURE*)data);
if (session->spdu_type == 0) {
if (parent_tree) {
REPORT_DISSECTOR_BUG(
wmem_strdup_printf(wmem_packet_scope(), "Wrong spdu type %x from session dissector.",session->spdu_type));
return 0;
}
}
asn1_ctx.private_data = session;
top_tree=parent_tree;
switch (session->spdu_type) {
case SES_CONNECTION_REQUEST:
case SES_CONNECTION_ACCEPT:
case SES_REFUSE:
case SES_DISCONNECT:
case SES_FINISH:
case SES_ABORT:
case CLSES_UNIT_DATA:
break;
case SES_DATA_TRANSFER:
oid=find_oid_by_pres_ctx_id(pinfo, indir_ref);
if (oid) {
if (strcmp(oid, ACSE_APDU_OID) == 0) {
proto_tree_add_expert_format(parent_tree, pinfo, &ei_acse_invalid_oid, tvb, offset, -1,
"Invalid OID: %s", ACSE_APDU_OID);
}
else {
call_ber_oid_callback(oid, tvb, offset, pinfo, parent_tree, NULL);
}
} else {
proto_tree_add_expert(parent_tree, pinfo, &ei_acse_dissector_not_available,
tvb, offset, -1);
}
top_tree = NULL;
return 0;
default:
top_tree = NULL;
return 0;
}
if (session->spdu_type == CLSES_UNIT_DATA) {
item = proto_tree_add_item(parent_tree, proto_clacse, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_acse);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CL-ACSE");
col_clear(pinfo->cinfo, COL_INFO);
} else {
item = proto_tree_add_item(parent_tree, proto_acse, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_acse);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ACSE");
col_clear(pinfo->cinfo, COL_INFO);
}
while (tvb_reported_length_remaining(tvb, offset) > 0) {
int old_offset=offset;
offset = dissect_acse_ACSE_apdu(FALSE, tvb, offset, &asn1_ctx, tree, -1);
if (offset == old_offset) {
proto_tree_add_expert(tree, pinfo, &ei_acse_malformed, tvb, offset, -1);
break;
}
}
top_tree = NULL;
return tvb_captured_length(tvb);
}
void proto_register_acse(void) {
static hf_register_info hf[] = {
{ &hf_acse_user_data,
{ "User data", "acse.user_data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
#include "packet-acse-hfarr.c"
};
static gint *ett[] = {
&ett_acse,
#include "packet-acse-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_acse_dissector_not_available, { "acse.dissector_not_available", PI_UNDECODED, PI_WARN, "Dissector is not available", EXPFILL }},
{ &ei_acse_malformed, { "acse.malformed", PI_MALFORMED, PI_ERROR, "Malformed packet", EXPFILL }},
{ &ei_acse_invalid_oid, { "acse.invalid_oid", PI_UNDECODED, PI_WARN, "Invalid OID", EXPFILL }},
};
expert_module_t* expert_acse;
proto_acse = proto_register_protocol(PNAME, PSNAME, PFNAME);
acse_handle = register_dissector("acse", dissect_acse, proto_acse);
proto_clacse = proto_register_protocol(CLPNAME, CLPSNAME, CLPFNAME);
proto_register_field_array(proto_acse, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_acse = expert_register_protocol(proto_acse);
expert_register_field_array(expert_acse, ei, array_length(ei));
}
void proto_reg_handoff_acse(void) {
oid_add_from_string("id-aCSE","2.2.3.1.1");
register_ber_oid_dissector_handle(ACSE_APDU_OID, acse_handle, proto_acse, "id-as-acse");
}
