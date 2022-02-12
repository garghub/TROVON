void\r\nia64_ctl_trace (long on)\r\n{\r\nia64_ssc(on, 0, 0, 0, SSC_CTL_TRACE);\r\n}\r\nvoid __init\r\nhpsim_setup (char **cmdline_p)\r\n{\r\nROOT_DEV = Root_SDA1;\r\nsimcons_register();\r\n}
