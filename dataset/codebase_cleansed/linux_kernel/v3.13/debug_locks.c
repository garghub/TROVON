int debug_locks_off(void)\r\n{\r\nif (__debug_locks_off()) {\r\nif (!debug_locks_silent) {\r\nconsole_verbose();\r\nreturn 1;\r\n}\r\n}\r\nreturn 0;\r\n}
