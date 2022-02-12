void __lockfunc tty_lock(void)\r\n{\r\nmutex_lock(&big_tty_mutex);\r\n}\r\nvoid __lockfunc tty_unlock(void)\r\n{\r\nmutex_unlock(&big_tty_mutex);\r\n}
