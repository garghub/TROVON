void proto_reg_handoff_bt_oui(void)
{
dissector_handle_t eapol_handle;
dissector_handle_t btl2cap_handle;
eapol_handle = find_dissector("eapol");
btl2cap_handle = find_dissector("btl2cap");
dissector_add_uint("llc.bluetooth_pid", AMP_C_SECURITY_FRAME, eapol_handle);
dissector_add_uint("llc.bluetooth_pid", AMP_U_L2CAP, btl2cap_handle);
}
void proto_register_bt_oui(void)
{
static hf_register_info hf[] = {
{ &hf_llc_bluetooth_pid,
{ "PID", "llc.bluetooth_pid", FT_UINT16, BASE_HEX,
VALS(bluetooth_pid_vals), 0x0, "Protocol ID", HFILL }
}
};
llc_add_oui(OUI_BLUETOOTH, "llc.bluetooth_pid", "LLC Bluetooth OUI PID", hf);
}
