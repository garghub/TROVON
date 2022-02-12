void
proto_register_ipmi_bridge(void)
{
ipmi_register_netfn_cmdtab(IPMI_BRIDGE_REQ, IPMI_OEM_NONE, NULL, 0, NULL,
cmd_bridge, array_length(cmd_bridge));
}
