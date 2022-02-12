void
proto_register_ipmi_update(void)
{
ipmi_register_netfn_cmdtab(IPMI_UPDATE_REQ, IPMI_OEM_PPS, NULL, 0, NULL,
cmd_update, array_length(cmd_update));
}
