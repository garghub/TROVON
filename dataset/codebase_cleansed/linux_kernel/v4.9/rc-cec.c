static int __init init_rc_map_cec(void)\r\n{\r\nreturn rc_map_register(&cec_map);\r\n}\r\nstatic void __exit exit_rc_map_cec(void)\r\n{\r\nrc_map_unregister(&cec_map);\r\n}
