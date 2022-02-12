const char* lookup_bulkcmd_name(u16 id)\r\n{\r\nif (id < 9)\r\n{\r\nreturn Unifi_bulkcmd_names[id].name;\r\n}\r\nif (id == 15)\r\n{\r\nreturn "Padding";\r\n}\r\nreturn "UNKNOWN";\r\n}
