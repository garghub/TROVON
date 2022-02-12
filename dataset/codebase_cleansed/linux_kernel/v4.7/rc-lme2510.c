static int __init init_rc_lme2510_map(void)\r\n{\r\nreturn rc_map_register(&lme2510_map);\r\n}\r\nstatic void __exit exit_rc_lme2510_map(void)\r\n{\r\nrc_map_unregister(&lme2510_map);\r\n}
