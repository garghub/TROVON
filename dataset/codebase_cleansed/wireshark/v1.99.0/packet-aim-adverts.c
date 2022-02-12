void
proto_register_aim_adverts(void)
{
#if 0
static hf_register_info hf[] = {
};
#endif
static gint *ett[] = {
&ett_aim_adverts,
};
proto_aim_adverts = proto_register_protocol("AIM Advertisements", "AIM Advertisements", "aim_adverts");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_adverts(void)
{
aim_init_family(proto_aim_adverts, ett_aim_adverts, FAMILY_ADVERTS, aim_fnac_family_adverts);
}
