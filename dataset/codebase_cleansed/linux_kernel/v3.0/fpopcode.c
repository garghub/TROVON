unsigned int checkCondition(const unsigned int opcode, const unsigned int ccodes)
{
return (aCC[opcode >> 28] >> (ccodes >> 28)) & 1;
}
