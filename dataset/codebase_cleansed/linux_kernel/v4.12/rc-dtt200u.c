static int __init init_rc_map_dtt200u(void)\r\n{\r\nreturn rc_map_register(&dtt200u_map);\r\n}\r\nstatic void __exit exit_rc_map_dtt200u(void)\r\n{\r\nrc_map_unregister(&dtt200u_map);\r\n}
