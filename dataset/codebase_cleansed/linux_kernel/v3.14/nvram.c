void *brcmf_nvram_strip(const struct firmware *nv, u32 *new_length)
{
u8 *nvram;
u32 i;
u32 len;
u32 column;
u8 val;
bool comment;
u32 token;
__le32 token_le;
nvram = kmalloc(nv->size + 1 + 3 + sizeof(token_le), GFP_KERNEL);
if (!nvram)
return NULL;
len = 0;
column = 0;
comment = false;
for (i = 0; i < nv->size; i++) {
val = nv->data[i];
if (val == 0)
break;
if (val == '\r')
continue;
if (comment && (val != '\n'))
continue;
comment = false;
if (val == '#') {
comment = true;
continue;
}
if (val == '\n') {
if (column == 0)
continue;
nvram[len] = 0;
len++;
column = 0;
continue;
}
nvram[len] = val;
len++;
column++;
}
column = len;
*new_length = roundup(len + 1, 4);
while (column != *new_length) {
nvram[column] = 0;
column++;
}
token = *new_length / 4;
token = (~token << 16) | (token & 0x0000FFFF);
token_le = cpu_to_le32(token);
memcpy(&nvram[*new_length], &token_le, sizeof(token_le));
*new_length += sizeof(token_le);
return nvram;
}
void brcmf_nvram_free(void *nvram)
{
kfree(nvram);
}
