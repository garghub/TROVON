static void
x509if_frame_end(void)
{
top_of_dn = NULL;
top_of_rdn = NULL;
rdn_one_value = FALSE;
dn_one_rdn = FALSE;
doing_attr = FALSE;
last_dn = NULL;
last_rdn = NULL;
last_ava = NULL;
}
static int
dissect_x509if_T_type(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_values_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 313 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_values_set_of, hf_index, ett_x509if_T_values);
return offset;
}
static int
dissect_x509if_T_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 283 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback("unknown", tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_contextType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_contextValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 295 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_contextValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_contextValues_set_of, hf_index, ett_x509if_T_contextValues);
return offset;
}
static int
dissect_x509if_BOOLEAN(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_x509if_Context(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Context_sequence, hf_index, ett_x509if_Context);
return offset;
}
static int
dissect_x509if_SET_SIZE_1_MAX_OF_Context(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_Context_set_of, hf_index, ett_x509if_SET_SIZE_1_MAX_OF_Context);
return offset;
}
static int
dissect_x509if_T_valuesWithContext_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_valuesWithContext_item_sequence, hf_index, ett_x509if_T_valuesWithContext_item);
return offset;
}
static int
dissect_x509if_T_valuesWithContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_valuesWithContext_set_of, hf_index, ett_x509if_T_valuesWithContext);
return offset;
}
int
dissect_x509if_Attribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 414 "./asn1/x509if/x509if.cnf"
doing_attr = TRUE;
register_frame_end_routine (actx->pinfo, x509if_frame_end);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Attribute_sequence, hf_index, ett_x509if_Attribute);
return offset;
}
int
dissect_x509if_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
int
dissect_x509if_AttributeValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 301 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_type_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_assertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 307 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_NULL(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_null(implicit_tag, actx, tree, tvb, offset, hf_index);
return offset;
}
static int
dissect_x509if_T_ca_contextType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_ca_contextValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 184 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_ca_contextValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_ca_contextValues_set_of, hf_index, ett_x509if_T_ca_contextValues);
return offset;
}
int
dissect_x509if_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContextAssertion_sequence, hf_index, ett_x509if_ContextAssertion);
return offset;
}
static int
dissect_x509if_SET_SIZE_1_MAX_OF_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_ContextAssertion_set_of, hf_index, ett_x509if_SET_SIZE_1_MAX_OF_ContextAssertion);
return offset;
}
static int
dissect_x509if_T_assertedContexts(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_assertedContexts_choice, hf_index, ett_x509if_T_assertedContexts,
NULL);
return offset;
}
int
dissect_x509if_AttributeValueAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 404 "./asn1/x509if/x509if.cnf"
ava_hf_index = hf_index;
last_ava = (char *)wmem_alloc(wmem_packet_scope(), MAX_AVA_STR_LEN); *last_ava = '\0';
register_frame_end_routine (actx->pinfo, x509if_frame_end);
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeValueAssertion_sequence, hf_index, ett_x509if_AttributeValueAssertion);
ava_hf_index=-1;
return offset;
}
static int
dissect_x509if_OBJECT_IDENTIFIER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_ContextAssertion_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextAssertion);
return offset;
}
int
dissect_x509if_AttributeTypeAssertion(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeTypeAssertion_sequence, hf_index, ett_x509if_AttributeTypeAssertion);
return offset;
}
static int
dissect_x509if_T_type_02(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 190 "./asn1/x509if/x509if.cnf"
const char *fmt;
const char *name;
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
if(actx->external.direct_reference) {
name = oid_resolved_from_string(wmem_packet_scope(), actx->external.direct_reference);
if(!name) name = actx->external.direct_reference;
if(last_rdn) {
g_strlcat(last_rdn, name, MAX_RDN_STR_LEN);
g_strlcat(last_rdn, "=", MAX_RDN_STR_LEN);
proto_item_append_text(tree, " (%s=", name);
} else if(doing_attr) {
proto_item_append_text(tree, " (%s)", name);
}
if((fmt = val_to_str_const(hf_index, fmt_vals, "")) && *fmt) {
last_ava = (char *)wmem_alloc(wmem_packet_scope(), MAX_AVA_STR_LEN); *last_ava = '\0';
register_frame_end_routine (actx->pinfo, x509if_frame_end);
g_snprintf(last_ava, MAX_AVA_STR_LEN, "%s %s", name, fmt);
proto_item_append_text(tree, " %s", last_ava);
}
}
return offset;
}
static int
dissect_x509if_T_atadv_value(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 224 "./asn1/x509if/x509if.cnf"
int old_offset = offset;
tvbuff_t *out_tvb;
char *value = NULL;
const char *fmt;
const char *name = NULL;
const char *orig_oid = actx->external.direct_reference;
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
actx->external.direct_reference = orig_oid;
dissect_ber_octet_string(FALSE, actx, NULL, tvb, old_offset, hf_x509if_any_string, &out_tvb);
if(out_tvb) {
value = tvb_format_text(out_tvb, 0, tvb_reported_length(out_tvb));
if(last_rdn) {
g_strlcat(last_rdn, value, MAX_RDN_STR_LEN);
proto_item_append_text(tree, "%s)", value);
}
if((fmt = val_to_str_const(ava_hf_index, fmt_vals, "")) && *fmt) {
if (!last_ava) {
last_ava = (char *)wmem_alloc(wmem_packet_scope(), MAX_AVA_STR_LEN);
}
if(!(name = oid_resolved_from_string(wmem_packet_scope(), actx->external.direct_reference)))
name = actx->external.direct_reference;
g_snprintf(last_ava, MAX_AVA_STR_LEN, "%s %s %s", name, fmt, value);
proto_item_append_text(tree, " %s", last_ava);
}
}
return offset;
}
static int
dissect_x509if_T_distingAttrValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 328 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_valWithContext_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_valWithContext_item_sequence, hf_index, ett_x509if_T_valWithContext_item);
return offset;
}
static int
dissect_x509if_T_valWithContext(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_valWithContext_set_of, hf_index, ett_x509if_T_valWithContext);
return offset;
}
int
dissect_x509if_AttributeTypeAndDistinguishedValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
AttributeTypeAndDistinguishedValue_sequence, hf_index, ett_x509if_AttributeTypeAndDistinguishedValue);
return offset;
}
static int
dissect_x509if_RelativeDistinguishedName_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 357 "./asn1/x509if/x509if.cnf"
if(!rdn_one_value) {
top_of_rdn = tree;
} else {
if(last_rdn)
g_strlcat(last_rdn, "+", MAX_RDN_STR_LEN);
}
offset = dissect_x509if_AttributeTypeAndDistinguishedValue(implicit_tag, tvb, offset, actx, tree, hf_index);
rdn_one_value = TRUE;
return offset;
}
int
dissect_x509if_RelativeDistinguishedName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 331 "./asn1/x509if/x509if.cnf"
char *temp_dn;
rdn_one_value = FALSE;
top_of_rdn = tree;
last_rdn = (char *)wmem_alloc(wmem_packet_scope(), MAX_DN_STR_LEN); *last_rdn = '\0';
register_frame_end_routine (actx->pinfo, x509if_frame_end);
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
RelativeDistinguishedName_set_of, hf_index, ett_x509if_RelativeDistinguishedName);
proto_item_append_text(top_of_rdn, " (%s)", last_rdn);
if (last_dn) {
if(*last_dn) {
temp_dn = (char *)wmem_strdup_printf(wmem_packet_scope(), "%s,%s", last_rdn, last_dn);
last_dn[0] = '\0';
g_strlcat(last_dn, temp_dn, MAX_DN_STR_LEN);
} else {
g_strlcat(last_dn, last_rdn, MAX_DN_STR_LEN);
}
}
last_rdn = NULL;
return offset;
}
static int
dissect_x509if_RDNSequence_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 393 "./asn1/x509if/x509if.cnf"
if(!dn_one_rdn) {
top_of_dn = tree;
}
offset = dissect_x509if_RelativeDistinguishedName(implicit_tag, tvb, offset, actx, tree, hf_index);
dn_one_rdn = TRUE;
return offset;
}
int
dissect_x509if_RDNSequence(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 372 "./asn1/x509if/x509if.cnf"
const char *fmt;
dn_one_rdn = FALSE;
last_dn = (char *)wmem_alloc(wmem_packet_scope(), MAX_DN_STR_LEN); *last_dn = '\0';
top_of_dn = NULL;
register_frame_end_routine (actx->pinfo, x509if_frame_end);
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
RDNSequence_sequence_of, hf_index, ett_x509if_RDNSequence);
proto_item_append_text(top_of_dn, " (%s)", last_dn);
if((fmt = val_to_str_const(hf_index, fmt_vals, "")) && *fmt) {
col_append_fstr(actx->pinfo->cinfo, COL_INFO, " %s%s", fmt, last_dn);
}
return offset;
}
int
dissect_x509if_Name(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Name_choice, hf_index, ett_x509if_Name,
NULL);
return offset;
}
int
dissect_x509if_DistinguishedName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509if_RDNSequence(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
int
dissect_x509if_LocalName(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_x509if_RDNSequence(implicit_tag, tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_x509if_T_specificExclusions_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_specificExclusions_item_choice, hf_index, ett_x509if_T_specificExclusions_item,
NULL);
return offset;
}
static int
dissect_x509if_T_specificExclusions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_specificExclusions_set_of, hf_index, ett_x509if_T_specificExclusions);
return offset;
}
static int
dissect_x509if_BaseDistance(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509if_SET_OF_Refinement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_OF_Refinement_set_of, hf_index, ett_x509if_SET_OF_Refinement);
return offset;
}
int
dissect_x509if_Refinement(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
Refinement_choice, hf_index, ett_x509if_Refinement,
NULL);
return offset;
}
int
dissect_x509if_SubtreeSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SubtreeSpecification_sequence, hf_index, ett_x509if_SubtreeSpecification);
return offset;
}
static int
dissect_x509if_T_chopSpecificExclusions_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_chopSpecificExclusions_item_choice, hf_index, ett_x509if_T_chopSpecificExclusions_item,
NULL);
return offset;
}
static int
dissect_x509if_T_chopSpecificExclusions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_chopSpecificExclusions_set_of, hf_index, ett_x509if_T_chopSpecificExclusions);
return offset;
}
int
dissect_x509if_ChopSpecification(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ChopSpecification_sequence, hf_index, ett_x509if_ChopSpecification);
return offset;
}
int
dissect_x509if_AttributeUsage(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509if_RuleIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509if_SET_SIZE_1_MAX_OF_RuleIdentifier(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_RuleIdentifier_set_of, hf_index, ett_x509if_SET_SIZE_1_MAX_OF_RuleIdentifier);
return offset;
}
int
dissect_x509if_DITStructureRule(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DITStructureRule_sequence, hf_index, ett_x509if_DITStructureRule);
return offset;
}
static int
dissect_x509if_T_auxiliaries(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_auxiliaries_set_of, hf_index, ett_x509if_T_auxiliaries);
return offset;
}
static int
dissect_x509if_T_mandatory(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_mandatory_set_of, hf_index, ett_x509if_T_mandatory);
return offset;
}
static int
dissect_x509if_T_optional(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_optional_set_of, hf_index, ett_x509if_T_optional);
return offset;
}
static int
dissect_x509if_T_precluded(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_precluded_set_of, hf_index, ett_x509if_T_precluded);
return offset;
}
int
dissect_x509if_DITContentRule(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DITContentRule_sequence, hf_index, ett_x509if_DITContentRule);
return offset;
}
static int
dissect_x509if_T_mandatoryContexts(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_mandatoryContexts_set_of, hf_index, ett_x509if_T_mandatoryContexts);
return offset;
}
static int
dissect_x509if_T_optionalContexts(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
T_optionalContexts_set_of, hf_index, ett_x509if_T_optionalContexts);
return offset;
}
int
dissect_x509if_DITContextUse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
DITContextUse_sequence, hf_index, ett_x509if_DITContextUse);
return offset;
}
static int
dissect_x509if_INTEGER(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509if_T_attributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_ra_selectedValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 274 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_ra_selectedValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_ra_selectedValues_sequence_of, hf_index, ett_x509if_T_ra_selectedValues);
return offset;
}
static int
dissect_x509if_T_entryType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_ra_values_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 280 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_ra_values(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_ra_values_sequence_of, hf_index, ett_x509if_T_ra_values);
return offset;
}
static int
dissect_x509if_T_defaultValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
T_defaultValues_item_sequence, hf_index, ett_x509if_T_defaultValues_item);
return offset;
}
static int
dissect_x509if_T_defaultValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_defaultValues_sequence_of, hf_index, ett_x509if_T_defaultValues);
return offset;
}
static int
dissect_x509if_T_contextType_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_contextValue_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 319 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_contextValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_contextValue_sequence_of, hf_index, ett_x509if_T_contextValue);
return offset;
}
int
dissect_x509if_ContextProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ContextProfile_sequence, hf_index, ett_x509if_ContextProfile);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_0_MAX_OF_ContextProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_0_MAX_OF_ContextProfile_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_0_MAX_OF_ContextProfile);
return offset;
}
static int
dissect_x509if_SEQUENCE_OF_ContextCombination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_ContextCombination_sequence_of, hf_index, ett_x509if_SEQUENCE_OF_ContextCombination);
return offset;
}
int
dissect_x509if_ContextCombination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
ContextCombination_choice, hf_index, ett_x509if_ContextCombination,
NULL);
return offset;
}
static int
dissect_x509if_T_restrictionType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_restrictionValue(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 325 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
int
dissect_x509if_MatchingUse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MatchingUse_sequence, hf_index, ett_x509if_MatchingUse);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_MatchingUse(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_MatchingUse_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MatchingUse);
return offset;
}
int
dissect_x509if_RequestAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RequestAttribute_sequence, hf_index, ett_x509if_RequestAttribute);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_0_MAX_OF_RequestAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_0_MAX_OF_RequestAttribute_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_0_MAX_OF_RequestAttribute);
return offset;
}
static int
dissect_x509if_SEQUENCE_OF_AttributeCombination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_OF_AttributeCombination_sequence_of, hf_index, ett_x509if_SEQUENCE_OF_AttributeCombination);
return offset;
}
int
dissect_x509if_AttributeCombination(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
AttributeCombination_choice, hf_index, ett_x509if_AttributeCombination,
NULL);
return offset;
}
static int
dissect_x509if_T_attributeType_01(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_object_identifier_str(implicit_tag, actx, tree, tvb, offset, hf_x509if_object_identifier_id, &actx->external.direct_reference);
return offset;
}
static int
dissect_x509if_T_selectedValues_item(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 289 "./asn1/x509if/x509if.cnf"
offset=call_ber_oid_callback(actx->external.direct_reference, tvb, offset, actx->pinfo, tree, NULL);
return offset;
}
static int
dissect_x509if_T_selectedValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
T_selectedValues_sequence_of, hf_index, ett_x509if_T_selectedValues);
return offset;
}
static int
dissect_x509if_T_outputValues(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_choice(actx, tree, tvb, offset,
T_outputValues_choice, hf_index, ett_x509if_T_outputValues,
NULL);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextProfile(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_ContextProfile_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextProfile);
return offset;
}
int
dissect_x509if_ResultAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ResultAttribute_sequence, hf_index, ett_x509if_ResultAttribute);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_ResultAttribute(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_ResultAttribute_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ResultAttribute);
return offset;
}
int
dissect_x509if_ControlOptions(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
ControlOptions_sequence, hf_index, ett_x509if_ControlOptions);
return offset;
}
int
dissect_x509if_Mapping(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
Mapping_sequence, hf_index, ett_x509if_Mapping);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_Mapping(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_Mapping_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_Mapping);
return offset;
}
int
dissect_x509if_MRSubstitution(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MRSubstitution_sequence, hf_index, ett_x509if_MRSubstitution);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_MRSubstitution(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_MRSubstitution_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MRSubstitution);
return offset;
}
int
dissect_x509if_MRMapping(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
MRMapping_sequence, hf_index, ett_x509if_MRMapping);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_MRMapping(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_MRMapping_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MRMapping);
return offset;
}
int
dissect_x509if_RelaxationPolicy(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
RelaxationPolicy_sequence, hf_index, ett_x509if_RelaxationPolicy);
return offset;
}
static int
dissect_x509if_SEQUENCE_SIZE_1_MAX_OF_AttributeType(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence_of(implicit_tag, actx, tree, tvb, offset,
SEQUENCE_SIZE_1_MAX_OF_AttributeType_sequence_of, hf_index, ett_x509if_SEQUENCE_SIZE_1_MAX_OF_AttributeType);
return offset;
}
int
dissect_x509if_AllowedSubset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_bitstring(implicit_tag, actx, tree, tvb, offset,
AllowedSubset_bits, hf_index, ett_x509if_AllowedSubset,
NULL);
return offset;
}
int
dissect_x509if_ImposedSubset(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
int
dissect_x509if_EntryLimit(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
EntryLimit_sequence, hf_index, ett_x509if_EntryLimit);
return offset;
}
static int
dissect_x509if_SET_SIZE_1_MAX_OF_DirectoryString(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_set_of(implicit_tag, actx, tree, tvb, offset,
SET_SIZE_1_MAX_OF_DirectoryString_set_of, hf_index, ett_x509if_SET_SIZE_1_MAX_OF_DirectoryString);
return offset;
}
int
dissect_x509if_SearchRuleDescription(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchRuleDescription_sequence, hf_index, ett_x509if_SearchRuleDescription);
return offset;
}
static int
dissect_x509if_HierarchyLevel(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_integer(implicit_tag, actx, tree, tvb, offset, hf_index,
NULL);
return offset;
}
static int
dissect_x509if_HierarchyBelow(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_boolean(implicit_tag, actx, tree, tvb, offset, hf_index, NULL);
return offset;
}
int
dissect_x509if_SearchRule(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchRule_sequence, hf_index, ett_x509if_SearchRule);
return offset;
}
int
dissect_x509if_SearchRuleId(gboolean implicit_tag _U_, tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_ber_sequence(implicit_tag, actx, tree, tvb, offset,
SearchRuleId_sequence, hf_index, ett_x509if_SearchRuleId);
return offset;
}
static int dissect_DistinguishedName_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509if_DistinguishedName(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509if_DistinguishedName_PDU);
return offset;
}
static int dissect_SubtreeSpecification_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509if_SubtreeSpecification(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509if_SubtreeSpecification_PDU);
return offset;
}
static int dissect_HierarchyLevel_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509if_HierarchyLevel(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509if_HierarchyLevel_PDU);
return offset;
}
static int dissect_HierarchyBelow_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
offset = dissect_x509if_HierarchyBelow(FALSE, tvb, offset, &asn1_ctx, tree, hf_x509if_HierarchyBelow_PDU);
return offset;
}
const char * x509if_get_last_dn(void)
{
return last_dn;
}
gboolean x509if_register_fmt(int hf_index, const gchar *fmt)
{
static int idx = 0;
if(idx < (MAX_FMT_VALS - 1)) {
fmt_vals[idx].value = hf_index;
fmt_vals[idx].strptr = fmt;
idx++;
fmt_vals[idx].value = 0;
fmt_vals[idx].strptr = NULL;
return TRUE;
} else
return FALSE;
}
const char * x509if_get_last_ava(void)
{
return last_ava;
}
void proto_register_x509if(void) {
static hf_register_info hf[] = {
{ &hf_x509if_object_identifier_id,
{ "Id", "x509if.id", FT_OID, BASE_NONE, NULL, 0,
"Object identifier Id", HFILL }},
{ &hf_x509if_any_string,
{ "AnyString", "x509if.any.String", FT_BYTES, BASE_NONE,
NULL, 0, "This is any String", HFILL }},
#line 1 "./asn1/x509if/packet-x509if-hfarr.c"
{ &hf_x509if_DistinguishedName_PDU,
{ "DistinguishedName", "x509if.DistinguishedName",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_SubtreeSpecification_PDU,
{ "SubtreeSpecification", "x509if.SubtreeSpecification_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_HierarchyLevel_PDU,
{ "HierarchyLevel", "x509if.HierarchyLevel",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_HierarchyBelow_PDU,
{ "HierarchyBelow", "x509if.HierarchyBelow",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_type,
{ "type", "x509if.type",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_values,
{ "values", "x509if.values",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_values_item,
{ "values item", "x509if.values_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_valuesWithContext,
{ "valuesWithContext", "x509if.valuesWithContext",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_valuesWithContext_item,
{ "valuesWithContext item", "x509if.valuesWithContext_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_valuesWithContext_item", HFILL }},
{ &hf_x509if_value,
{ "value", "x509if.value_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextList,
{ "contextList", "x509if.contextList",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_Context", HFILL }},
{ &hf_x509if_contextList_item,
{ "Context", "x509if.Context_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextType,
{ "contextType", "x509if.contextType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextValues,
{ "contextValues", "x509if.contextValues",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextValues_item,
{ "contextValues item", "x509if.contextValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_fallback,
{ "fallback", "x509if.fallback",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509if_type_01,
{ "type", "x509if.type",
FT_OID, BASE_NONE, NULL, 0,
"T_type_01", HFILL }},
{ &hf_x509if_assertion,
{ "assertion", "x509if.assertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_assertedContexts,
{ "assertedContexts", "x509if.assertedContexts",
FT_UINT32, BASE_DEC, VALS(x509if_T_assertedContexts_vals), 0,
NULL, HFILL }},
{ &hf_x509if_allContexts,
{ "allContexts", "x509if.allContexts_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_selectedContexts,
{ "selectedContexts", "x509if.selectedContexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_ContextAssertion", HFILL }},
{ &hf_x509if_selectedContexts_item,
{ "ContextAssertion", "x509if.ContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_ca_contextType,
{ "contextType", "x509if.contextType",
FT_OID, BASE_NONE, NULL, 0,
"T_ca_contextType", HFILL }},
{ &hf_x509if_ca_contextValues,
{ "contextValues", "x509if.contextValues",
FT_UINT32, BASE_DEC, NULL, 0,
"T_ca_contextValues", HFILL }},
{ &hf_x509if_ca_contextValues_item,
{ "contextValues item", "x509if.contextValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ca_contextValues_item", HFILL }},
{ &hf_x509if_type_02,
{ "type", "x509if.type",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_ata_assertedContexts,
{ "assertedContexts", "x509if.assertedContexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_ContextAssertion", HFILL }},
{ &hf_x509if_ata_assertedContexts_item,
{ "ContextAssertion", "x509if.ContextAssertion_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_rdnSequence,
{ "rdnSequence", "x509if.rdnSequence",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_RDNSequence_item,
{ "RDNSequence item", "x509if.RDNSequence_item",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_RelativeDistinguishedName_item,
{ "RelativeDistinguishedName item", "x509if.RelativeDistinguishedName_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_type_03,
{ "type", "x509if.type",
FT_OID, BASE_NONE, NULL, 0,
"T_type_02", HFILL }},
{ &hf_x509if_atadv_value,
{ "value", "x509if.value_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_atadv_value", HFILL }},
{ &hf_x509if_primaryDistinguished,
{ "primaryDistinguished", "x509if.primaryDistinguished",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509if_valueswithContext,
{ "valuesWithContext", "x509if.valuesWithContext",
FT_UINT32, BASE_DEC, NULL, 0,
"T_valWithContext", HFILL }},
{ &hf_x509if_valueswithContext_item,
{ "valuesWithContext item", "x509if.valuesWithContext_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_valWithContext_item", HFILL }},
{ &hf_x509if_distingAttrValue,
{ "distingAttrValue", "x509if.distingAttrValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_chopSpecificExclusions,
{ "specificExclusions", "x509if.specificExclusions",
FT_UINT32, BASE_DEC, NULL, 0,
"T_chopSpecificExclusions", HFILL }},
{ &hf_x509if_chopSpecificExclusions_item,
{ "specificExclusions item", "x509if.specificExclusions_item",
FT_UINT32, BASE_DEC, VALS(x509if_T_chopSpecificExclusions_item_vals), 0,
"T_chopSpecificExclusions_item", HFILL }},
{ &hf_x509if_chopBefore,
{ "chopBefore", "x509if.chopBefore",
FT_UINT32, BASE_DEC, NULL, 0,
"LocalName", HFILL }},
{ &hf_x509if_chopAfter,
{ "chopAfter", "x509if.chopAfter",
FT_UINT32, BASE_DEC, NULL, 0,
"LocalName", HFILL }},
{ &hf_x509if_minimum,
{ "minimum", "x509if.minimum",
FT_UINT32, BASE_DEC, NULL, 0,
"BaseDistance", HFILL }},
{ &hf_x509if_maximum,
{ "maximum", "x509if.maximum",
FT_UINT32, BASE_DEC, NULL, 0,
"BaseDistance", HFILL }},
{ &hf_x509if_item,
{ "item", "x509if.item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_refinement_and,
{ "and", "x509if.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Refinement", HFILL }},
{ &hf_x509if_refinement_and_item,
{ "Refinement", "x509if.Refinement",
FT_UINT32, BASE_DEC, VALS(x509if_Refinement_vals), 0,
NULL, HFILL }},
{ &hf_x509if_refinement_or,
{ "or", "x509if.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_OF_Refinement", HFILL }},
{ &hf_x509if_refinement_or_item,
{ "Refinement", "x509if.Refinement",
FT_UINT32, BASE_DEC, VALS(x509if_Refinement_vals), 0,
NULL, HFILL }},
{ &hf_x509if_refinement_not,
{ "not", "x509if.not",
FT_UINT32, BASE_DEC, VALS(x509if_Refinement_vals), 0,
"Refinement", HFILL }},
{ &hf_x509if_ruleIdentifier,
{ "ruleIdentifier", "x509if.ruleIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_nameForm,
{ "nameForm", "x509if.nameForm",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_superiorStructureRules,
{ "superiorStructureRules", "x509if.superiorStructureRules",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_RuleIdentifier", HFILL }},
{ &hf_x509if_superiorStructureRules_item,
{ "RuleIdentifier", "x509if.RuleIdentifier",
FT_INT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_structuralObjectClass,
{ "structuralObjectClass", "x509if.structuralObjectClass",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_auxiliaries,
{ "auxiliaries", "x509if.auxiliaries",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_auxiliaries_item,
{ "auxiliaries item", "x509if.auxiliaries_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_mandatory,
{ "mandatory", "x509if.mandatory",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_mandatory_item,
{ "mandatory item", "x509if.mandatory_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_optional,
{ "optional", "x509if.optional",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_optional_item,
{ "optional item", "x509if.optional_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_precluded,
{ "precluded", "x509if.precluded",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_precluded_item,
{ "precluded item", "x509if.precluded_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_attributeType,
{ "attributeType", "x509if.attributeType",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_mandatoryContexts,
{ "mandatoryContexts", "x509if.mandatoryContexts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_mandatoryContexts_item,
{ "mandatoryContexts item", "x509if.mandatoryContexts_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_optionalContexts,
{ "optionalContexts", "x509if.optionalContexts",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_optionalContexts_item,
{ "optionalContexts item", "x509if.optionalContexts_item",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_id,
{ "id", "x509if.id",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_dmdId,
{ "dmdId", "x509if.dmdId",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_attributeType_01,
{ "attributeType", "x509if.attributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_includeSubtypes,
{ "includeSubtypes", "x509if.includeSubtypes",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_x509if_ra_selectedValues,
{ "selectedValues", "x509if.selectedValues",
FT_UINT32, BASE_DEC, NULL, 0,
"T_ra_selectedValues", HFILL }},
{ &hf_x509if_ra_selectedValues_item,
{ "selectedValues item", "x509if.selectedValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ra_selectedValues_item", HFILL }},
{ &hf_x509if_defaultValues,
{ "defaultValues", "x509if.defaultValues",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_defaultValues_item,
{ "defaultValues item", "x509if.defaultValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_entryType,
{ "entryType", "x509if.entryType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_ra_values,
{ "values", "x509if.values",
FT_UINT32, BASE_DEC, NULL, 0,
"T_ra_values", HFILL }},
{ &hf_x509if_ra_values_item,
{ "values item", "x509if.values_item_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_ra_values_item", HFILL }},
{ &hf_x509if_contexts,
{ "contexts", "x509if.contexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_0_MAX_OF_ContextProfile", HFILL }},
{ &hf_x509if_contexts_item,
{ "ContextProfile", "x509if.ContextProfile_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextCombination,
{ "contextCombination", "x509if.contextCombination",
FT_UINT32, BASE_DEC, VALS(x509if_ContextCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_matchingUse,
{ "matchingUse", "x509if.matchingUse",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_MatchingUse", HFILL }},
{ &hf_x509if_matchingUse_item,
{ "MatchingUse", "x509if.MatchingUse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextType_01,
{ "contextType", "x509if.contextType",
FT_OID, BASE_NONE, NULL, 0,
"T_contextType_01", HFILL }},
{ &hf_x509if_contextValue,
{ "contextValue", "x509if.contextValue",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contextValue_item,
{ "contextValue item", "x509if.contextValue_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_context,
{ "context", "x509if.context",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_contextcombination_and,
{ "and", "x509if.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ContextCombination", HFILL }},
{ &hf_x509if_contextcombination_and_item,
{ "ContextCombination", "x509if.ContextCombination",
FT_UINT32, BASE_DEC, VALS(x509if_ContextCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_contextcombination_or,
{ "or", "x509if.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_ContextCombination", HFILL }},
{ &hf_x509if_contextcombination_or_item,
{ "ContextCombination", "x509if.ContextCombination",
FT_UINT32, BASE_DEC, VALS(x509if_ContextCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_contextcombination_not,
{ "not", "x509if.not",
FT_UINT32, BASE_DEC, VALS(x509if_ContextCombination_vals), 0,
"ContextCombination", HFILL }},
{ &hf_x509if_restrictionType,
{ "restrictionType", "x509if.restrictionType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_restrictionValue,
{ "restrictionValue", "x509if.restrictionValue_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_attribute,
{ "attribute", "x509if.attribute",
FT_OID, BASE_NONE, NULL, 0,
"AttributeType", HFILL }},
{ &hf_x509if_and,
{ "and", "x509if.and",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AttributeCombination", HFILL }},
{ &hf_x509if_and_item,
{ "AttributeCombination", "x509if.AttributeCombination",
FT_UINT32, BASE_DEC, VALS(x509if_AttributeCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_or,
{ "or", "x509if.or",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_OF_AttributeCombination", HFILL }},
{ &hf_x509if_or_item,
{ "AttributeCombination", "x509if.AttributeCombination",
FT_UINT32, BASE_DEC, VALS(x509if_AttributeCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_not,
{ "not", "x509if.not",
FT_UINT32, BASE_DEC, VALS(x509if_AttributeCombination_vals), 0,
"AttributeCombination", HFILL }},
{ &hf_x509if_attributeType_02,
{ "attributeType", "x509if.attributeType",
FT_OID, BASE_NONE, NULL, 0,
"T_attributeType_01", HFILL }},
{ &hf_x509if_outputValues,
{ "outputValues", "x509if.outputValues",
FT_UINT32, BASE_DEC, VALS(x509if_T_outputValues_vals), 0,
NULL, HFILL }},
{ &hf_x509if_selectedValues,
{ "selectedValues", "x509if.selectedValues",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_selectedValues_item,
{ "selectedValues item", "x509if.selectedValues_item_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_matchedValuesOnly,
{ "matchedValuesOnly", "x509if.matchedValuesOnly_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_contexts_01,
{ "contexts", "x509if.contexts",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_ContextProfile", HFILL }},
{ &hf_x509if_serviceControls,
{ "serviceControls", "x509if.serviceControls_element",
FT_NONE, BASE_NONE, NULL, 0,
"ServiceControlOptions", HFILL }},
{ &hf_x509if_searchOptions,
{ "searchOptions", "x509if.searchOptions_element",
FT_NONE, BASE_NONE, NULL, 0,
"SearchControlOptions", HFILL }},
{ &hf_x509if_hierarchyOptions,
{ "hierarchyOptions", "x509if.hierarchyOptions_element",
FT_NONE, BASE_NONE, NULL, 0,
"HierarchySelections", HFILL }},
{ &hf_x509if_default,
{ "default", "x509if.default",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_max,
{ "max", "x509if.max",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_basic,
{ "basic", "x509if.basic_element",
FT_NONE, BASE_NONE, NULL, 0,
"MRMapping", HFILL }},
{ &hf_x509if_tightenings,
{ "tightenings", "x509if.tightenings",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_MRMapping", HFILL }},
{ &hf_x509if_tightenings_item,
{ "MRMapping", "x509if.MRMapping_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_relaxations,
{ "relaxations", "x509if.relaxations",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_MRMapping", HFILL }},
{ &hf_x509if_relaxations_item,
{ "MRMapping", "x509if.MRMapping_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_maximum_relaxation,
{ "maximum", "x509if.maximum",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_minimum_relaxation,
{ "minimum", "x509if.minimum",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_mapping,
{ "mapping", "x509if.mapping",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_Mapping", HFILL }},
{ &hf_x509if_mapping_item,
{ "Mapping", "x509if.Mapping_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_substitution,
{ "substitution", "x509if.substitution",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_MRSubstitution", HFILL }},
{ &hf_x509if_substitution_item,
{ "MRSubstitution", "x509if.MRSubstitution_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_mappingFunction,
{ "mappingFunction", "x509if.mappingFunction",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_level,
{ "level", "x509if.level",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_oldMatchingRule,
{ "oldMatchingRule", "x509if.oldMatchingRule",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_newMatchingRule,
{ "newMatchingRule", "x509if.newMatchingRule",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_base,
{ "base", "x509if.base",
FT_UINT32, BASE_DEC, NULL, 0,
"LocalName", HFILL }},
{ &hf_x509if_specificExclusions,
{ "specificExclusions", "x509if.specificExclusions",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_specificExclusions_item,
{ "specificExclusions item", "x509if.specificExclusions_item",
FT_UINT32, BASE_DEC, VALS(x509if_T_specificExclusions_item_vals), 0,
NULL, HFILL }},
{ &hf_x509if_specificationFilter,
{ "specificationFilter", "x509if.specificationFilter",
FT_UINT32, BASE_DEC, VALS(x509if_Refinement_vals), 0,
"Refinement", HFILL }},
{ &hf_x509if_serviceType,
{ "serviceType", "x509if.serviceType",
FT_OID, BASE_NONE, NULL, 0,
"OBJECT_IDENTIFIER", HFILL }},
{ &hf_x509if_userClass,
{ "userClass", "x509if.userClass",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER", HFILL }},
{ &hf_x509if_inputAttributeTypes,
{ "inputAttributeTypes", "x509if.inputAttributeTypes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_0_MAX_OF_RequestAttribute", HFILL }},
{ &hf_x509if_inputAttributeTypes_item,
{ "RequestAttribute", "x509if.RequestAttribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_attributeCombination,
{ "attributeCombination", "x509if.attributeCombination",
FT_UINT32, BASE_DEC, VALS(x509if_AttributeCombination_vals), 0,
NULL, HFILL }},
{ &hf_x509if_outputAttributeTypes,
{ "outputAttributeTypes", "x509if.outputAttributeTypes",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_ResultAttribute", HFILL }},
{ &hf_x509if_outputAttributeTypes_item,
{ "ResultAttribute", "x509if.ResultAttribute_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_defaultControls,
{ "defaultControls", "x509if.defaultControls_element",
FT_NONE, BASE_NONE, NULL, 0,
"ControlOptions", HFILL }},
{ &hf_x509if_mandatoryControls,
{ "mandatoryControls", "x509if.mandatoryControls_element",
FT_NONE, BASE_NONE, NULL, 0,
"ControlOptions", HFILL }},
{ &hf_x509if_searchRuleControls,
{ "searchRuleControls", "x509if.searchRuleControls_element",
FT_NONE, BASE_NONE, NULL, 0,
"ControlOptions", HFILL }},
{ &hf_x509if_familyGrouping,
{ "familyGrouping", "x509if.familyGrouping_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_familyReturn,
{ "familyReturn", "x509if.familyReturn_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_relaxation,
{ "relaxation", "x509if.relaxation_element",
FT_NONE, BASE_NONE, NULL, 0,
"RelaxationPolicy", HFILL }},
{ &hf_x509if_additionalControl,
{ "additionalControl", "x509if.additionalControl",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_MAX_OF_AttributeType", HFILL }},
{ &hf_x509if_additionalControl_item,
{ "AttributeType", "x509if.AttributeType",
FT_OID, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_allowedSubset,
{ "allowedSubset", "x509if.allowedSubset",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_imposedSubset,
{ "imposedSubset", "x509if.imposedSubset",
FT_UINT32, BASE_DEC, VALS(x509if_ImposedSubset_vals), 0,
NULL, HFILL }},
{ &hf_x509if_entryLimit,
{ "entryLimit", "x509if.entryLimit_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x509if_name,
{ "name", "x509if.name",
FT_UINT32, BASE_DEC, NULL, 0,
"SET_SIZE_1_MAX_OF_DirectoryString", HFILL }},
{ &hf_x509if_name_item,
{ "DirectoryString", "x509if.DirectoryString",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
NULL, HFILL }},
{ &hf_x509if_description,
{ "description", "x509if.description",
FT_UINT32, BASE_DEC, VALS(x509sat_DirectoryString_vals), 0,
"DirectoryString", HFILL }},
{ &hf_x509if_AllowedSubset_baseObject,
{ "baseObject", "x509if.baseObject",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_x509if_AllowedSubset_oneLevel,
{ "oneLevel", "x509if.oneLevel",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_x509if_AllowedSubset_wholeSubtree,
{ "wholeSubtree", "x509if.wholeSubtree",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
#line 133 "./asn1/x509if/packet-x509if-template.c"
};
static gint *ett[] = {
#line 1 "./asn1/x509if/packet-x509if-ettarr.c"
&ett_x509if_Attribute,
&ett_x509if_T_values,
&ett_x509if_T_valuesWithContext,
&ett_x509if_T_valuesWithContext_item,
&ett_x509if_SET_SIZE_1_MAX_OF_Context,
&ett_x509if_Context,
&ett_x509if_T_contextValues,
&ett_x509if_AttributeValueAssertion,
&ett_x509if_T_assertedContexts,
&ett_x509if_SET_SIZE_1_MAX_OF_ContextAssertion,
&ett_x509if_ContextAssertion,
&ett_x509if_T_ca_contextValues,
&ett_x509if_AttributeTypeAssertion,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextAssertion,
&ett_x509if_Name,
&ett_x509if_RDNSequence,
&ett_x509if_RelativeDistinguishedName,
&ett_x509if_AttributeTypeAndDistinguishedValue,
&ett_x509if_T_valWithContext,
&ett_x509if_T_valWithContext_item,
&ett_x509if_SubtreeSpecification,
&ett_x509if_ChopSpecification,
&ett_x509if_T_chopSpecificExclusions,
&ett_x509if_T_chopSpecificExclusions_item,
&ett_x509if_Refinement,
&ett_x509if_SET_OF_Refinement,
&ett_x509if_DITStructureRule,
&ett_x509if_SET_SIZE_1_MAX_OF_RuleIdentifier,
&ett_x509if_DITContentRule,
&ett_x509if_T_auxiliaries,
&ett_x509if_T_mandatory,
&ett_x509if_T_optional,
&ett_x509if_T_precluded,
&ett_x509if_DITContextUse,
&ett_x509if_T_mandatoryContexts,
&ett_x509if_T_optionalContexts,
&ett_x509if_SearchRuleDescription,
&ett_x509if_SearchRule,
&ett_x509if_SearchRuleId,
&ett_x509if_AllowedSubset,
&ett_x509if_RequestAttribute,
&ett_x509if_T_ra_selectedValues,
&ett_x509if_T_defaultValues,
&ett_x509if_T_defaultValues_item,
&ett_x509if_T_ra_values,
&ett_x509if_SEQUENCE_SIZE_0_MAX_OF_ContextProfile,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MatchingUse,
&ett_x509if_ContextProfile,
&ett_x509if_T_contextValue,
&ett_x509if_ContextCombination,
&ett_x509if_SEQUENCE_OF_ContextCombination,
&ett_x509if_MatchingUse,
&ett_x509if_AttributeCombination,
&ett_x509if_SEQUENCE_OF_AttributeCombination,
&ett_x509if_ResultAttribute,
&ett_x509if_T_outputValues,
&ett_x509if_T_selectedValues,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ContextProfile,
&ett_x509if_ControlOptions,
&ett_x509if_EntryLimit,
&ett_x509if_RelaxationPolicy,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MRMapping,
&ett_x509if_MRMapping,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_Mapping,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_MRSubstitution,
&ett_x509if_Mapping,
&ett_x509if_MRSubstitution,
&ett_x509if_T_specificExclusions,
&ett_x509if_T_specificExclusions_item,
&ett_x509if_SEQUENCE_SIZE_0_MAX_OF_RequestAttribute,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_ResultAttribute,
&ett_x509if_SEQUENCE_SIZE_1_MAX_OF_AttributeType,
&ett_x509if_SET_SIZE_1_MAX_OF_DirectoryString,
#line 138 "./asn1/x509if/packet-x509if-template.c"
};
proto_x509if = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_x509if, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fmt_vals[0].value = 0;
fmt_vals[0].strptr = NULL;
}
void proto_reg_handoff_x509if(void) {
#line 1 "./asn1/x509if/packet-x509if-dis-tab.c"
register_ber_oid_dissector("2.5.4.1", dissect_DistinguishedName_PDU, proto_x509if, "id-at-aliasedEntryName");
register_ber_oid_dissector("2.5.4.31", dissect_DistinguishedName_PDU, proto_x509if, "id-at-member");
register_ber_oid_dissector("2.5.4.32", dissect_DistinguishedName_PDU, proto_x509if, "id-at-owner");
register_ber_oid_dissector("2.5.4.33", dissect_DistinguishedName_PDU, proto_x509if, "id-at-roleOccupant");
register_ber_oid_dissector("2.5.4.34", dissect_DistinguishedName_PDU, proto_x509if, "id-at-seeAlso");
register_ber_oid_dissector("2.5.4.49", dissect_DistinguishedName_PDU, proto_x509if, "id-at-distinguishedName");
register_ber_oid_dissector("2.5.18.3", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-creatorsName");
register_ber_oid_dissector("2.5.18.4", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-modifiersName");
register_ber_oid_dissector("2.5.18.6", dissect_SubtreeSpecification_PDU, proto_x509if, "id-oa-subtreeSpecification");
register_ber_oid_dissector("2.5.18.10", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-subschemaSubentry");
register_ber_oid_dissector("2.5.18.11", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-accessControlSubentry");
register_ber_oid_dissector("2.5.18.12", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-collectiveAttributeSubentry");
register_ber_oid_dissector("2.5.18.13", dissect_DistinguishedName_PDU, proto_x509if, "id-oa-contextDefaultSubentry");
register_ber_oid_dissector("2.5.18.17", dissect_HierarchyLevel_PDU, proto_x509if, "id-oa-hierarchyLevel");
register_ber_oid_dissector("2.5.18.18", dissect_HierarchyBelow_PDU, proto_x509if, "iid-oa-hierarchyBelow");
register_ber_oid_dissector("2.6.5.2.5", dissect_DistinguishedName_PDU, proto_x509if, "id-at-mhs-message-store-dn");
register_ber_oid_dissector("2.6.5.2.14", dissect_DistinguishedName_PDU, proto_x509if, "id-at-mhs-dl-related-lists");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.3", dissect_DistinguishedName_PDU, proto_x509if, "id-at-alternateRecipient");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.4", dissect_DistinguishedName_PDU, proto_x509if, "id-at-associatedOrganization");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.6", dissect_DistinguishedName_PDU, proto_x509if, "id-at-associatedPLA");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.49", dissect_DistinguishedName_PDU, proto_x509if, "id-at-aliasPointer");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.61", dissect_DistinguishedName_PDU, proto_x509if, "id-at-listPointer");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.110", dissect_DistinguishedName_PDU, proto_x509if, "id-at-administrator");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.111", dissect_DistinguishedName_PDU, proto_x509if, "id-at-aigsExpanded");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.113", dissect_DistinguishedName_PDU, proto_x509if, "id-at-associatedAL");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.114", dissect_DistinguishedName_PDU, proto_x509if, "id-at-copyMember");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.117", dissect_DistinguishedName_PDU, proto_x509if, "id-at-guard");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.121", dissect_DistinguishedName_PDU, proto_x509if, "id-at-networkDN");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.138", dissect_DistinguishedName_PDU, proto_x509if, "id-at-plasServed");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.139", dissect_DistinguishedName_PDU, proto_x509if, "id-at-deployed");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.140", dissect_DistinguishedName_PDU, proto_x509if, "id-at-garrison");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.184", dissect_DistinguishedName_PDU, proto_x509if, "id-at-aCPDutyOfficer");
register_ber_oid_dissector("2.16.840.1.101.2.2.1.188", dissect_DistinguishedName_PDU, proto_x509if, "id-at-primaryMember");
#line 157 "./asn1/x509if/packet-x509if-template.c"
}
