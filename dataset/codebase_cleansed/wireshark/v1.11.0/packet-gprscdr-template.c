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
proto_gprscdr = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_gprscdr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
