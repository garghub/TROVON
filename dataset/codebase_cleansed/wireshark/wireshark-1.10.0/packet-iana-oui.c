void
proto_register_iana_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_iana_pid,
{ "PID", "llc.iana_pid", FT_UINT16, BASE_HEX,
VALS(iana_pid_vals), 0x0, NULL, HFILL }
}
};
llc_add_oui(OUI_IANA, "llc.iana_pid", "IANA OUI PID", hf);
}
