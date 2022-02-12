int get_cpuid(char *buffer, size_t sz)\r\n{\r\nconst char *cpuid = "IBM/S390";\r\nif (strlen(cpuid) + 1 > sz)\r\nreturn -1;\r\nstrcpy(buffer, cpuid);\r\nreturn 0;\r\n}
