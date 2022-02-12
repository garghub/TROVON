void\r\nproto_register_ipmi_bridge(void)\r\n{\r\nipmi_register_netfn_cmdtab(IPMI_BRIDGE_REQ, IPMI_OEM_NONE, NULL, 0, NULL,\r\ncmd_bridge, array_length(cmd_bridge));\r\n}
