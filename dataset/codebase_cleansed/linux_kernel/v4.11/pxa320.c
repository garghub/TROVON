static int __init pxa320_init(void)\r\n{\r\nif (cpu_is_pxa320()) {\r\nmfp_init_base(io_p2v(MFPR_BASE));\r\nmfp_init_addr(pxa320_mfp_addr_map);\r\n}\r\nreturn 0;\r\n}
