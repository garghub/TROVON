static int __init init_rc_map_tevii_nec(void)\r\n{\r\nreturn rc_map_register(&tevii_nec_map);\r\n}\r\nstatic void __exit exit_rc_map_tevii_nec(void)\r\n{\r\nrc_map_unregister(&tevii_nec_map);\r\n}
