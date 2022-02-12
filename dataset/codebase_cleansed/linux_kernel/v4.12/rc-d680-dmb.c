static int __init init_rc_map_d680_dmb(void)\r\n{\r\nreturn rc_map_register(&d680_dmb_map);\r\n}\r\nstatic void __exit exit_rc_map_d680_dmb(void)\r\n{\r\nrc_map_unregister(&d680_dmb_map);\r\n}
