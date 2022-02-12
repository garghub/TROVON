const char *lookup_bulkcmd_name(u16 id)\r\n{\r\nif (id < 9)\r\nreturn Unifi_bulkcmd_names[id].name;\r\nif (id == 15)\r\nreturn "Padding";\r\nreturn "UNKNOWN";\r\n}
