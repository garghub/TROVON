static int __init init_rc_map_ati_x10(void)\r\n{\r\nreturn rc_map_register(&ati_x10_map);\r\n}\r\nstatic void __exit exit_rc_map_ati_x10(void)\r\n{\r\nrc_map_unregister(&ati_x10_map);\r\n}
