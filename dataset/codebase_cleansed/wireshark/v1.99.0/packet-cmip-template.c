static int
dissect_cmip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data)
{
struct SESSION_DATA_STRUCTURE* session;
proto_item *item;
proto_tree *tree;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_BER, TRUE, pinfo);
if (data == NULL)
return 0;
session = (struct SESSION_DATA_STRUCTURE*)data;
if(session->spdu_type == 0 ) {
proto_tree_add_expert_format(parent_tree, pinfo, &ei_wrong_spdu_type, tvb, 0, -1,
"Internal error: wrong spdu type %x from session dissector.", session->spdu_type);
return 0;
}
asn1_ctx.private_data = session;
item = proto_tree_add_item(parent_tree, proto_cmip, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_cmip);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMIP");
col_clear(pinfo->cinfo, COL_INFO);
switch(session->spdu_type){
case SES_CONNECTION_REQUEST:
case SES_CONNECTION_ACCEPT:
case SES_DISCONNECT:
case SES_FINISH:
case SES_REFUSE:
dissect_cmip_CMIPUserInfo(FALSE,tvb,0,&asn1_ctx,tree,-1);
break;
case SES_ABORT:
dissect_cmip_CMIPAbortInfo(FALSE,tvb,0,&asn1_ctx,tree,-1);
break;
case SES_DATA_TRANSFER:
dissect_cmip_ROS(FALSE,tvb,0,&asn1_ctx,tree,-1);
break;
default:
;
}
return tvb_captured_length(tvb);
}
void proto_register_cmip(void) {
static hf_register_info hf[] = {
{ &hf_cmip_actionType_OID,
{ "actionType", "cmip.actionType_OID",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmip_eventType_OID,
{ "eventType", "cmip.eventType_OID",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmip_attributeId_OID,
{ "attributeId", "cmip.attributeId_OID",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_cmip_errorId_OID,
{ "errorId", "cmip.errorId_OID",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_DiscriminatorConstruct,
{ "DiscriminatorConstruct", "cmip.DiscriminatorConstruct",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_Destination,
{ "Destination", "cmip.Destination",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_NameBinding,
{ "NameBinding", "cmip.NameBinding",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_ObjectClass,
{ "ObjectClass", "cmip.ObjectClass",
FT_UINT32, BASE_DEC, VALS(cmip_ObjectClass_vals), 0,
NULL, HFILL }},
#include "packet-cmip-hfarr.c"
};
static gint *ett[] = {
&ett_cmip,
#include "packet-cmip-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_wrong_spdu_type, { "cmip.wrong_spdu_type", PI_PROTOCOL, PI_ERROR, "Internal error: wrong spdu type", EXPFILL }},
};
expert_module_t* expert_cmip;
proto_cmip = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("cmip", dissect_cmip, proto_cmip);
proto_register_field_array(proto_cmip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cmip = expert_register_protocol(proto_cmip);
expert_register_field_array(expert_cmip, ei, array_length(ei));
#include "packet-cmip-dis-tab.c"
oid_add_from_string("discriminatorId(1)","2.9.3.2.7.1");
attribute_id_dissector_table = register_dissector_table("cmip.attribute_id", "CMIP Attribute Id", FT_UINT32, BASE_DEC);
}
void proto_reg_handoff_cmip(void) {
dissector_handle_t cmip_handle = find_dissector("cmip");
register_ber_oid_dissector_handle("2.9.0.0.2", cmip_handle, proto_cmip, "cmip");
register_ber_oid_dissector_handle("2.9.1.1.4", cmip_handle, proto_cmip, "joint-iso-itu-t(2) ms(9) cmip(1) cmip-pci(1) abstractSyntax(4)");
oid_add_from_string("2.9.3.2.3.1","managedObjectClass(3) alarmRecord(1)");
oid_add_from_string("2.9.3.2.3.2","managedObjectClass(3) attributeValueChangeRecord(2)");
oid_add_from_string("2.9.3.2.3.3","managedObjectClass(3) discriminator(3)");
oid_add_from_string("2.9.3.2.3.4","managedObjectClass(3) eventForwardingDiscriminator(4)");
oid_add_from_string("2.9.3.2.3.5","managedObjectClass(3) eventLogRecord(5)");
oid_add_from_string("2.9.3.2.3.6","managedObjectClass(3) log(6)");
oid_add_from_string("2.9.3.2.3.7","managedObjectClass(3) logRecord(7)");
oid_add_from_string("2.9.3.2.3.8","managedObjectClass(3) objectCreationRecord(8)");
oid_add_from_string("2.9.3.2.3.9","managedObjectClass(3) objectDeletionRecord(9)");
oid_add_from_string("2.9.3.2.3.10","managedObjectClass(3) relationshipChangeRecord(10)");
oid_add_from_string("2.9.3.2.3.11","managedObjectClass(3) securityAlarmReportRecord(11)");
oid_add_from_string("2.9.3.2.3.12","managedObjectClass(3) stateChangeRecord(12)");
oid_add_from_string("2.9.3.2.3.13","managedObjectClass(3) system(13)");
oid_add_from_string("2.9.3.2.3.14","managedObjectClass(3) top(14)");
oid_add_from_string("2.9.3.2.4.14","administrativeStatePackage(14)");
oid_add_from_string("2.9.1.1.4","joint-iso-itu-t(2) ms(9) cmip(1) cmip-pci(1) abstractSyntax(4)");
}
