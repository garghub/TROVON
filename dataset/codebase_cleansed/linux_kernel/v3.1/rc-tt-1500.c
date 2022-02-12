static int __init init_rc_map_tt_1500(void)\r\n{\r\nreturn rc_map_register(&tt_1500_map);\r\n}\r\nstatic void __exit exit_rc_map_tt_1500(void)\r\n{\r\nrc_map_unregister(&tt_1500_map);\r\n}
