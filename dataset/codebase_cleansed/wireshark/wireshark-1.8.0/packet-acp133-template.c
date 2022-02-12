void proto_register_acp133(void) {
static hf_register_info hf[] =
{
#include "packet-acp133-hfarr.c"
};
static gint *ett[] = {
&ett_acp133,
#include "packet-acp133-ettarr.c"
};
proto_acp133 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_acp133, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_acp133(void) {
#include "packet-acp133-dis-tab.c"
oid_add_from_string("id-oc-mhs-distribution-list","2.6.5.1.0");
oid_add_from_string("id-oc-mhs-message-store","2.6.5.1.1");
oid_add_from_string("id-oc-mhs-message-transfer-agent","2.6.5.1.2");
oid_add_from_string("id-oc-mhs-user","2.6.5.1.3");
oid_add_from_string("id-oc-secure-user","2.16.840.1.101.2.1.4.13");
oid_add_from_string("id-oc-ukms","2.16.840.1.101.2.1.4.16");
oid_add_from_string("id-oc-plaData","2.16.840.1.101.2.2.3.26");
oid_add_from_string("id-oc-cadACP127","2.16.840.1.101.2.2.3.28");
oid_add_from_string("id-oc-mLA","2.16.840.1.101.2.2.3.31");
oid_add_from_string("id-oc-orgACP127","2.16.840.1.101.2.2.3.34");
oid_add_from_string("id-oc-plaCollectiveACP127","2.16.840.1.101.2.2.3.35");
oid_add_from_string("id-oc-routingIndicator","2.16.840.1.101.2.2.3.37");
oid_add_from_string("id-oc-sigintPLA","2.16.840.1.101.2.2.3.38");
oid_add_from_string("id-oc-sIPLA","2.16.840.1.101.2.2.3.39");
oid_add_from_string("id-oc-spotPLA","2.16.840.1.101.2.2.3.40");
oid_add_from_string("id-oc-taskForceACP127","2.16.840.1.101.2.2.3.41");
oid_add_from_string("id-oc-tenantACP127","2.16.840.1.101.2.2.3.42");
oid_add_from_string("id-oc-plaACP127","2.16.840.1.101.2.2.3.47");
oid_add_from_string("id-oc-aliasCommonName","2.16.840.1.101.2.2.3.52");
oid_add_from_string("id-oc-aliasOrganizationalUnit","2.16.840.1.101.2.2.3.53");
oid_add_from_string("id-oc-distributionCodesHandled","2.16.840.1.101.2.2.3.54");
oid_add_from_string("id-oc-distributionCodeDescription","2.16.840.1.101.2.2.3.55");
oid_add_from_string("id-oc-plaUser","2.16.840.1.101.2.2.3.56");
oid_add_from_string("id-oc-addressList","2.16.840.1.101.2.2.3.57");
oid_add_from_string("id-oc-altSpellingACP127","2.16.840.1.101.2.2.3.58");
oid_add_from_string("id-oc-messagingGateway","2.16.840.1.101.2.2.3.59");
oid_add_from_string("id-oc-network","2.16.840.1.101.2.2.3.60");
oid_add_from_string("id-oc-networkInstructions","2.16.840.1.101.2.2.3.61");
oid_add_from_string("id-oc-otherContactInformation","2.16.840.1.101.2.2.3.62");
oid_add_from_string("id-oc-releaseAuthorityPerson","2.16.840.1.101.2.2.3.63");
oid_add_from_string("id-oc-mLAgent","2.16.840.1.101.2.2.3.64");
oid_add_from_string("id-oc-releaseAuthorityPersonA","2.16.840.1.101.2.2.3.65");
oid_add_from_string("id-oc-securePkiUser","2.16.840.1.101.2.2.3.66");
oid_add_from_string("id-oc-dSSCSPLA","2.16.840.1.101.2.2.3.67");
oid_add_from_string("id-oc-aCPNetworkEdB","2.16.840.1.101.2.2.3.68");
oid_add_from_string("id-oc-aCPNetworkInstructionsEdB","2.16.840.1.101.2.2.3.69");
oid_add_from_string("acp120-acp127","2.16.840.1.101.2.2.5.0");
oid_add_from_string("acp120-janap128","2.16.840.1.101.2.2.5.1");
oid_add_from_string("acp120-mhs","2.16.840.1.101.2.2.5.2");
oid_add_from_string("acp120-mmhs","2.16.840.1.101.2.2.5.3");
oid_add_from_string("acp120-rfc822","2.16.840.1.101.2.2.5.4");
oid_add_from_string("boundaryMTA","2.16.840.1.101.2.2.5.5");
oid_add_from_string("mmhs-mhs","2.16.840.1.101.2.2.5.6");
oid_add_from_string("mmhs-rfc822","2.16.840.1.101.2.2.5.7");
oid_add_from_string("mta-acp127","2.16.840.1.101.2.2.5.8");
}
