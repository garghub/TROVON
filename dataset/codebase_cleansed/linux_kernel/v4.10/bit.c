int
bit_entry(struct nvkm_bios *bios, u8 id, struct bit_entry *bit)
{
if (likely(bios->bit_offset)) {
u8 entries = nvbios_rd08(bios, bios->bit_offset + 10);
u32 entry = bios->bit_offset + 12;
while (entries--) {
if (nvbios_rd08(bios, entry + 0) == id) {
bit->id = nvbios_rd08(bios, entry + 0);
bit->version = nvbios_rd08(bios, entry + 1);
bit->length = nvbios_rd16(bios, entry + 2);
bit->offset = nvbios_rd16(bios, entry + 4);
return 0;
}
entry += nvbios_rd08(bios, bios->bit_offset + 9);
}
return -ENOENT;
}
return -EINVAL;
}
