void __init nr_register_sysctl(void)\r\n{\r\nnr_table_header = register_sysctl_paths(nr_path, nr_table);\r\n}\r\nvoid nr_unregister_sysctl(void)\r\n{\r\nunregister_sysctl_table(nr_table_header);\r\n}
