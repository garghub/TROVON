static int __init init_rc_map_norwood(void)\r\n{\r\nreturn rc_map_register(&norwood_map);\r\n}\r\nstatic void __exit exit_rc_map_norwood(void)\r\n{\r\nrc_map_unregister(&norwood_map);\r\n}
