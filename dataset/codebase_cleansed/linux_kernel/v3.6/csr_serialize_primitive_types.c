void CsrUint8Des(u8 *value, u8 *buffer, size_t *offset)
{
*value = buffer[*offset];
*offset += sizeof(*value);
}
void CsrUint16Des(u16 *value, u8 *buffer, size_t *offset)
{
*value = (buffer[*offset + 0] << 0) |
(buffer[*offset + 1] << 8);
*offset += sizeof(*value);
}
void CsrUint32Des(u32 *value, u8 *buffer, size_t *offset)
{
*value = (buffer[*offset + 0] << 0) |
(buffer[*offset + 1] << 8) |
(buffer[*offset + 2] << 16) |
(buffer[*offset + 3] << 24);
*offset += sizeof(*value);
}
void CsrMemCpyDes(void *value, u8 *buffer, size_t *offset, size_t length)
{
memcpy(value, &buffer[*offset], length);
*offset += length;
}
void CsrCharStringDes(char **value, u8 *buffer, size_t *offset)
{
*value = kstrdup((char *) &buffer[*offset], GFP_KERNEL);
*offset += strlen(*value) + 1;
}
void CsrUint8Ser(u8 *buffer, size_t *offset, u8 value)
{
buffer[*offset] = value;
*offset += sizeof(value);
}
void CsrUint16Ser(u8 *buffer, size_t *offset, u16 value)
{
buffer[*offset + 0] = (u8) ((value >> 0) & 0xFF);
buffer[*offset + 1] = (u8) ((value >> 8) & 0xFF);
*offset += sizeof(value);
}
void CsrUint32Ser(u8 *buffer, size_t *offset, u32 value)
{
buffer[*offset + 0] = (u8) ((value >> 0) & 0xFF);
buffer[*offset + 1] = (u8) ((value >> 8) & 0xFF);
buffer[*offset + 2] = (u8) ((value >> 16) & 0xFF);
buffer[*offset + 3] = (u8) ((value >> 24) & 0xFF);
*offset += sizeof(value);
}
void CsrMemCpySer(u8 *buffer, size_t *offset, const void *value, size_t length)
{
memcpy(&buffer[*offset], value, length);
*offset += length;
}
void CsrCharStringSer(u8 *buffer, size_t *offset, const char *value)
{
if (value)
{
strcpy(((char *) &buffer[*offset]), value);
*offset += strlen(value) + 1;
}
else
{
CsrUint8Ser(buffer, offset, 0);
}
}
