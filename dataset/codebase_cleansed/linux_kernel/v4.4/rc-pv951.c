static int __init init_rc_map_pv951(void)\r\n{\r\nreturn rc_map_register(&pv951_map);\r\n}\r\nstatic void __exit exit_rc_map_pv951(void)\r\n{\r\nrc_map_unregister(&pv951_map);\r\n}
