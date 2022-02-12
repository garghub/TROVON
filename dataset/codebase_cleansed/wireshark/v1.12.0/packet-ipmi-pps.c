void
ipmi_register_pps(gint proto_ipmi _U_)
{
static guint8 sig_pps[3] = { 0x0a, 0x40, 0x00 };
static guint8 sig_pps_rev[3] = { 0x00, 0x40, 0x0a };
ipmi_register_netfn_cmdtab(IPMI_OEM_REQ, IPMI_OEM_NONE, sig_pps, 3,
"Pigeon Point Systems", cmd_pps, array_length(cmd_pps));
ipmi_register_netfn_cmdtab(IPMI_OEM_REQ, IPMI_OEM_NONE, sig_pps_rev, 3,
"Pigeon Point Systems (reversed)", cmd_pps, array_length(cmd_pps));
}
