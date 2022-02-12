void
proto_register_aim_chatnav(void)
{
#if 0
static hf_register_info hf[] = {
};
#endif
static gint *ett[] = {
&ett_aim_chatnav,
};
proto_aim_chatnav = proto_register_protocol("AIM Chat Navigation", "AIM ChatNav", "aim_chatnav");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_chatnav(void)
{
aim_init_family(proto_aim_chatnav, ett_aim_chatnav, FAMILY_CHAT_NAV, aim_fnac_family_chatnav);
}
