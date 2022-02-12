void
proto_register_gprscdr(void)
{
static hf_register_info hf[] = {
#include "packet-gprscdr-hfarr.c"
};
static gint *ett[] = {
&ett_gprscdr,
&ett_gprscdr_timestamp,
&ett_gprscdr_plmn_id,
#include "packet-gprscdr-ettarr.c"
};
static ei_register_info ei[] = {
{ &ei_gprscdr_not_dissected, { "gprscdr.not_dissected", PI_UNDECODED, PI_WARN, "Not dissected", EXPFILL }},
};
expert_module_t* expert_gprscdr;
proto_gprscdr = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_gprscdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gprscdr = expert_register_protocol(proto_gprscdr);
expert_register_field_array(expert_gprscdr, ei, array_length(ei));
}
