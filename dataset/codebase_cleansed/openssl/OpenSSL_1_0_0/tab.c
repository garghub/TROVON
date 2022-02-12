main()\r\n{\r\nint i,j;\r\nfor (i=0; i<256; i++)\r\n{\r\nfor (j=0; j<256; j++)\r\nif (ebits_to_num[j] == i)\r\n{\r\nprintf("0x%02x,",j);\r\nbreak;\r\n}\r\n}\r\n}
