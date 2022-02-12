int i2a_ACCESS_DESCRIPTION(BIO *bp, ACCESS_DESCRIPTION* a)\r\n{\r\ni2a_ASN1_OBJECT(bp, a->method);\r\n#ifdef UNDEF\r\ni2a_GENERAL_NAME(bp, a->location);\r\n#endif\r\nreturn 2;\r\n}
