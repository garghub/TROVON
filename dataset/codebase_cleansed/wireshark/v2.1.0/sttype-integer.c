void\r\nsttype_register_integer(void)\r\n{\r\nstatic sttype_t integer_type = {\r\nSTTYPE_INTEGER,\r\n"INTEGER",\r\nNULL,\r\nNULL,\r\nNULL\r\n};\r\nsttype_register(&integer_type);\r\n}
