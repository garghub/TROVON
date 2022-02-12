static void
dissect_charging_ase(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *it;
proto_tree *tr;
it=proto_tree_add_protocol_format(tree, proto_charging_ase, tvb, 0, -1, "Charging ASE");
tr=proto_item_add_subtree(it, ett_charging_ase);
if(tvb_reported_length(tvb)>0)
{
dissect_charging_ase_ChargingMessageType_PDU(tvb , pinfo, tr, NULL);
}
}
void
proto_register_charging_ase(void)
{
static hf_register_info hf[] = {
#include "packet-charging_ase-hfarr.c"
};
static gint *ett[] = {
&ett_charging_ase,
#include "packet-charging_ase-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_charging_ase_extensions_not_dissected, { "charging_ase.extensions_not_dissected", PI_UNDECODED, PI_WARN, "Extensions not dissected", EXPFILL }},
};
expert_module_t* expert_charging_ase;
proto_charging_ase = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_charging_ase, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_charging_ase = expert_register_protocol(proto_charging_ase);
expert_register_field_array(expert_charging_ase, ei, array_length(ei));
}
void
proto_reg_handoff_charging_ase(void)
{
charging_ase_handle = create_dissector_handle(dissect_charging_ase, proto_charging_ase);
}
