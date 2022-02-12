main()\r\n{\r\nDH *dh;\r\ndh=DH_new();\r\ndh->p=BN_bin2bn(data,sizeof(data),NULL);\r\ndh->g=BN_new();\r\nBN_set_word(dh->g,2);\r\nPEM_write_DHparams(stdout,dh);\r\n}
