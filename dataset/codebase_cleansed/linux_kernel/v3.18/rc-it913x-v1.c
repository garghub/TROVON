static int __init init_rc_it913x_v1_map(void)\r\n{\r\nreturn rc_map_register(&it913x_v1_map);\r\n}\r\nstatic void __exit exit_rc_it913x_v1_map(void)\r\n{\r\nrc_map_unregister(&it913x_v1_map);\r\n}
