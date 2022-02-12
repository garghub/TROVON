static void __init mpc836x_rdk_setup_arch(void)\r\n{\r\nmpc83xx_setup_arch();\r\n}\r\nstatic int __init mpc836x_rdk_probe(void)\r\n{\r\nreturn of_machine_is_compatible("fsl,mpc8360rdk");\r\n}
