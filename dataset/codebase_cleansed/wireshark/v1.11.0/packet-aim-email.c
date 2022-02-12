void
proto_register_aim_email(void)
{
static gint *ett[] = {
&ett_aim_email,
};
proto_aim_email = proto_register_protocol("AIM E-mail", "AIM Email", "aim_email");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_email(void)
{
aim_init_family(proto_aim_email, ett_aim_email, FAMILY_EMAIL, aim_fnac_family_email);
}
