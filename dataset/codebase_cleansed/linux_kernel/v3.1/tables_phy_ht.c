u32 b43_httab_read(struct b43_wldev *dev, u32 offset)
{
u32 type, value;
type = offset & B43_HTTAB_TYPEMASK;
offset &= ~B43_HTTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
switch (type) {
case B43_HTTAB_8BIT:
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO) & 0xFF;
break;
case B43_HTTAB_16BIT:
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO);
break;
case B43_HTTAB_32BIT:
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_HT_TABLE_DATAHI);
value <<= 16;
value |= b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO);
break;
default:
B43_WARN_ON(1);
value = 0;
}
return value;
}
void b43_httab_read_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, void *_data)
{
u32 type;
u8 *data = _data;
unsigned int i;
type = offset & B43_HTTAB_TYPEMASK;
offset &= ~B43_HTTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_HTTAB_8BIT:
*data = b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO) & 0xFF;
data++;
break;
case B43_HTTAB_16BIT:
*((u16 *)data) = b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO);
data += 2;
break;
case B43_HTTAB_32BIT:
*((u32 *)data) = b43_phy_read(dev, B43_PHY_HT_TABLE_DATAHI);
*((u32 *)data) <<= 16;
*((u32 *)data) |= b43_phy_read(dev, B43_PHY_HT_TABLE_DATALO);
data += 4;
break;
default:
B43_WARN_ON(1);
}
}
}
void b43_httab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
u32 type;
type = offset & B43_HTTAB_TYPEMASK;
offset &= 0xFFFF;
switch (type) {
case B43_HTTAB_8BIT:
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, value);
break;
case B43_HTTAB_16BIT:
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, value);
break;
case B43_HTTAB_32BIT:
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATAHI, value >> 16);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
return;
}
void b43_httab_write_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, const void *_data)
{
u32 type, value;
const u8 *data = _data;
unsigned int i;
type = offset & B43_HTTAB_TYPEMASK;
offset &= ~B43_HTTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_HTTAB_8BIT:
value = *data;
data++;
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, value);
break;
case B43_HTTAB_16BIT:
value = *((u16 *)data);
data += 2;
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, value);
break;
case B43_HTTAB_32BIT:
value = *((u32 *)data);
data += 4;
b43_phy_write(dev, B43_PHY_HT_TABLE_DATAHI, value >> 16);
b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO,
value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
}
}
void b43_phy_ht_tables_init(struct b43_wldev *dev)
{
httab_upload(dev, B43_HTTAB16(0x12, 0), b43_httab_0x12);
httab_upload(dev, B43_HTTAB16(0x27, 0), b43_httab_0x27);
httab_upload(dev, B43_HTTAB16(0x26, 0), b43_httab_0x26);
httab_upload(dev, B43_HTTAB32(0x25, 0), b43_httab_0x25);
httab_upload(dev, B43_HTTAB32(0x2f, 0), b43_httab_0x2f);
httab_upload(dev, B43_HTTAB16(0x1a, 0), b43_httab_0x1a);
httab_upload(dev, B43_HTTAB16(0x1b, 0), b43_httab_0x1b);
httab_upload(dev, B43_HTTAB16(0x1c, 0), b43_httab_0x1c);
httab_upload(dev, B43_HTTAB32(0x1a, 0x0c0), b43_httab_0x1a_0xc0);
httab_upload(dev, B43_HTTAB32(0x1a, 0x140), b43_httab_0x1a_0x140);
httab_upload(dev, B43_HTTAB32(0x1b, 0x140), b43_httab_0x1b_0x140);
httab_upload(dev, B43_HTTAB32(0x1c, 0x140), b43_httab_0x1c_0x140);
httab_upload(dev, B43_HTTAB16(0x1a, 0x1c0), b43_httab_0x1a_0x1c0);
httab_upload(dev, B43_HTTAB16(0x1b, 0x1c0), b43_httab_0x1b_0x1c0);
httab_upload(dev, B43_HTTAB16(0x1c, 0x1c0), b43_httab_0x1c_0x1c0);
httab_upload(dev, B43_HTTAB16(0x1a, 0x240), b43_httab_0x1a_0x240);
httab_upload(dev, B43_HTTAB16(0x1b, 0x240), b43_httab_0x1b_0x240);
httab_upload(dev, B43_HTTAB16(0x1c, 0x240), b43_httab_0x1c_0x240);
httab_upload(dev, B43_HTTAB32(0x1f, 0), b43_httab_0x1f);
httab_upload(dev, B43_HTTAB32(0x21, 0), b43_httab_0x21);
httab_upload(dev, B43_HTTAB32(0x23, 0), b43_httab_0x23);
httab_upload(dev, B43_HTTAB32(0x20, 0), b43_httab_0x20);
httab_upload(dev, B43_HTTAB32(0x22, 0), b43_httab_0x22);
httab_upload(dev, B43_HTTAB32(0x24, 0), b43_httab_0x24);
}
