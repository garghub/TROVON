static u16
extdev_table(struct nouveau_bios *bios, u8 *ver, u8 *hdr, u8 *len, u8 *cnt)
{
u8 dcb_ver, dcb_hdr, dcb_cnt, dcb_len;
u16 dcb, extdev = 0;
dcb = dcb_table(bios, &dcb_ver, &dcb_hdr, &dcb_cnt, &dcb_len);
if (!dcb || (dcb_ver != 0x30 && dcb_ver != 0x40))
return 0x0000;
extdev = nv_ro16(bios, dcb + 18);
if (!extdev)
return 0x0000;
*ver = nv_ro08(bios, extdev + 0);
*hdr = nv_ro08(bios, extdev + 1);
*cnt = nv_ro08(bios, extdev + 2);
*len = nv_ro08(bios, extdev + 3);
return extdev + *hdr;
}
static u16
nvbios_extdev_entry(struct nouveau_bios *bios, int idx, u8 *ver, u8 *len)
{
u8 hdr, cnt;
u16 extdev = extdev_table(bios, ver, &hdr, len, &cnt);
if (extdev && idx < cnt)
return extdev + idx * *len;
return 0x0000;
}
static void
extdev_parse_entry(struct nouveau_bios *bios, u16 offset,
struct nvbios_extdev_func *entry)
{
entry->type = nv_ro08(bios, offset + 0);
entry->addr = nv_ro08(bios, offset + 1);
entry->bus = (nv_ro08(bios, offset + 2) >> 4) & 1;
}
int
nvbios_extdev_parse(struct nouveau_bios *bios, int idx,
struct nvbios_extdev_func *func)
{
u8 ver, len;
u16 entry;
if (!(entry = nvbios_extdev_entry(bios, idx, &ver, &len)))
return -EINVAL;
extdev_parse_entry(bios, entry, func);
return 0;
}
int
nvbios_extdev_find(struct nouveau_bios *bios, enum nvbios_extdev_type type,
struct nvbios_extdev_func *func)
{
u8 ver, len, i;
u16 entry;
i = 0;
while (!(entry = nvbios_extdev_entry(bios, i++, &ver, &len))) {
extdev_parse_entry(bios, entry, func);
if (func->type == type)
return 0;
}
return -EINVAL;
}
