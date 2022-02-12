static int __init init_rc_map_anysee(void)\r\n{\r\nreturn rc_map_register(&anysee_map);\r\n}\r\nstatic void __exit exit_rc_map_anysee(void)\r\n{\r\nrc_map_unregister(&anysee_map);\r\n}
