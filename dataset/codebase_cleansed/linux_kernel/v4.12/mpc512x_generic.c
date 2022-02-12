static int __init mpc512x_generic_probe(void)\r\n{\r\nif (!of_device_compatible_match(of_root, board))\r\nreturn 0;\r\nmpc512x_init_early();\r\nreturn 1;\r\n}
