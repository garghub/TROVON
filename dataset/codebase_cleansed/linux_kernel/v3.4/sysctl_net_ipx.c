void ipx_register_sysctl(void)\r\n{\r\nipx_table_header = register_sysctl_paths(ipx_path, ipx_table);\r\n}\r\nvoid ipx_unregister_sysctl(void)\r\n{\r\nunregister_sysctl_table(ipx_table_header);\r\n}
