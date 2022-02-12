unsigned int checkCondition(const unsigned int opcode, const unsigned int ccodes)\r\n{\r\nreturn (aCC[opcode >> 28] >> (ccodes >> 28)) & 1;\r\n}
