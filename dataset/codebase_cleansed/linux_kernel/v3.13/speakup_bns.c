static int __init bns_init(void)\r\n{\r\nreturn synth_add(&synth_bns);\r\n}\r\nstatic void __exit bns_exit(void)\r\n{\r\nsynth_remove(&synth_bns);\r\n}
