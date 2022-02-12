static int __init dummy_init(void)\r\n{\r\nreturn synth_add(&synth_dummy);\r\n}\r\nstatic void __exit dummy_exit(void)\r\n{\r\nsynth_remove(&synth_dummy);\r\n}
