void
proto_register_aim_stats(void)
{
static gint *ett[] = {
&ett_aim_stats,
};
proto_aim_stats = proto_register_protocol("AIM Statistics", "AIM Stats", "aim_stats");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_stats(void)
{
aim_init_family(proto_aim_stats, ett_aim_stats, FAMILY_STATS, aim_fnac_family_stats);
}
