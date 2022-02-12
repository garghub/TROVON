void
ipmi_register_update(gint proto_ipmi _U_)
{
ipmi_register_netfn_cmdtab(IPMI_UPDATE_REQ, IPMI_OEM_PPS, NULL, 0, NULL,
cmd_update, array_length(cmd_update));
}
