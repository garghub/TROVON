int enter_vmx_usercopy(void)\r\n{\r\nif (in_interrupt())\r\nreturn 0;\r\npagefault_disable();\r\nenable_kernel_altivec();\r\nreturn 1;\r\n}\r\nint exit_vmx_usercopy(void)\r\n{\r\npagefault_enable();\r\nreturn 0;\r\n}\r\nint enter_vmx_copy(void)\r\n{\r\nif (in_interrupt())\r\nreturn 0;\r\npreempt_disable();\r\nenable_kernel_altivec();\r\nreturn 1;\r\n}\r\nvoid *exit_vmx_copy(void *dest)\r\n{\r\npreempt_enable();\r\nreturn dest;\r\n}
