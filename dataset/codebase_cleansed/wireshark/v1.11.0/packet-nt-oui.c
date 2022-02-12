void
proto_register_nortel_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_nortel_pid,
{ "PID", "llc.nortel_pid", FT_UINT16, BASE_HEX,
VALS(nortel_pid_vals), 0x0, NULL, HFILL }
}
};
llc_add_oui(OUI_NORTEL, "llc.nortel_pid", "LLC Nortel OUI PID", hf);
}
