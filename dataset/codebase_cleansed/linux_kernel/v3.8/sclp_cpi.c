static int __init cpi_module_init(void)\r\n{\r\nreturn sclp_cpi_set_data(system_name, sysplex_name, "LINUX",\r\nLINUX_VERSION_CODE);\r\n}\r\nstatic void __exit cpi_module_exit(void)\r\n{\r\n}
