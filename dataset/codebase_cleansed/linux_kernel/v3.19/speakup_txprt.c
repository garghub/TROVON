static int __init txprt_init(void)\r\n{\r\nreturn synth_add(&synth_txprt);\r\n}\r\nstatic void __exit txprt_exit(void)\r\n{\r\nsynth_remove(&synth_txprt);\r\n}
