static int __init mpc512x_generic_probe(void)\r\n{\r\nreturn of_flat_dt_match(of_get_flat_dt_root(), board);\r\n}
