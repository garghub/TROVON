void\r\nproto_register_ipmi_update(void)\r\n{\r\nipmi_register_netfn_cmdtab(IPMI_UPDATE_REQ, IPMI_OEM_PPS, NULL, 0, NULL,\r\ncmd_update, array_length(cmd_update));\r\n}
