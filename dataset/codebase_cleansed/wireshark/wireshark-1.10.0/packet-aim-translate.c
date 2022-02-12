void
proto_register_aim_translate(void)
{
static gint *ett[] = {
&ett_aim_translate,
};
proto_aim_translate = proto_register_protocol("AIM Translate", "AIM Translate", "aim_translate");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_translate(void)
{
aim_init_family(proto_aim_translate, ett_aim_translate, FAMILY_TRANSLATE, aim_fnac_family_translate);
}
