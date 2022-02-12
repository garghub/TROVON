void
proto_register_cisco_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_cisco_pid,
{ "PID", "llc.cisco_pid", FT_UINT16, BASE_HEX,
VALS(cisco_pid_vals), 0x0, "Protocol ID", HFILL }
}
};
llc_add_oui(OUI_CISCO, "llc.cisco_pid", "LLC Cisco OUI PID", hf);
}
