void
proto_register_force10_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_force10_pid,
{ "PID", "llc.force10_pid", FT_UINT16, BASE_HEX,
VALS(force10_pid_vals), 0x0, NULL, HFILL }
}
};
llc_add_oui(OUI_FORCE10, "llc.force10_pid", "LLC FORCE10 OUI PID", hf);
}
