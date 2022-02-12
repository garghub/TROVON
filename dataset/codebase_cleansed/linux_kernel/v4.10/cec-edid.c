static unsigned int cec_get_edid_spa_location(const u8 *edid, unsigned int size)
{
unsigned int blocks = size / 128;
unsigned int block;
u8 d;
if (blocks < 2 || size % 128)
return 0;
if (edid[0x7e] + 1 < blocks)
blocks = edid[0x7e] + 1;
for (block = 1; block < blocks; block++) {
unsigned int offset = block * 128;
if (edid[offset] != 0x02 || edid[offset + 1] != 0x03)
continue;
d = edid[offset + 2] & 0x7f;
if (d <= 4)
continue;
if (d > 4) {
unsigned int i = offset + 4;
unsigned int end = offset + d;
do {
u8 tag = edid[i] >> 5;
u8 len = edid[i] & 0x1f;
if (tag == 3 && len >= 5 && i + len <= end &&
edid[i + 1] == 0x03 &&
edid[i + 2] == 0x0c &&
edid[i + 3] == 0x00)
return i + 4;
i += len + 1;
} while (i < end);
}
}
return 0;
}
u16 cec_get_edid_phys_addr(const u8 *edid, unsigned int size,
unsigned int *offset)
{
unsigned int loc = cec_get_edid_spa_location(edid, size);
if (offset)
*offset = loc;
if (loc == 0)
return CEC_PHYS_ADDR_INVALID;
return (edid[loc] << 8) | edid[loc + 1];
}
void cec_set_edid_phys_addr(u8 *edid, unsigned int size, u16 phys_addr)
{
unsigned int loc = cec_get_edid_spa_location(edid, size);
u8 sum = 0;
unsigned int i;
if (loc == 0)
return;
edid[loc] = phys_addr >> 8;
edid[loc + 1] = phys_addr & 0xff;
loc &= ~0x7f;
for (i = loc; i < loc + 127; i++)
sum += edid[i];
edid[i] = 256 - sum;
}
u16 cec_phys_addr_for_input(u16 phys_addr, u8 input)
{
if (WARN_ON(input == 0 || input > 0xf))
return CEC_PHYS_ADDR_INVALID;
if (phys_addr == 0)
return input << 12;
if ((phys_addr & 0x0fff) == 0)
return phys_addr | (input << 8);
if ((phys_addr & 0x00ff) == 0)
return phys_addr | (input << 4);
if ((phys_addr & 0x000f) == 0)
return phys_addr | input;
return CEC_PHYS_ADDR_INVALID;
}
int cec_phys_addr_validate(u16 phys_addr, u16 *parent, u16 *port)
{
int i;
if (parent)
*parent = phys_addr;
if (port)
*port = 0;
if (phys_addr == CEC_PHYS_ADDR_INVALID)
return 0;
for (i = 0; i < 16; i += 4)
if (phys_addr & (0xf << i))
break;
if (i == 16)
return 0;
if (parent)
*parent = phys_addr & (0xfff0 << i);
if (port)
*port = (phys_addr >> i) & 0xf;
for (i += 4; i < 16; i += 4)
if ((phys_addr & (0xf << i)) == 0)
return -EINVAL;
return 0;
}
