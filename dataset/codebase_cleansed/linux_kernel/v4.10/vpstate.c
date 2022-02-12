static u32
nvbios_vpstate_offset(struct nvkm_bios *b)
{
struct bit_entry bit_P;
if (!bit_entry(b, 'P', &bit_P)) {
if (bit_P.version == 2)
return nvbios_rd32(b, bit_P.offset + 0x38);
}
return 0x0000;
}
int
nvbios_vpstate_parse(struct nvkm_bios *b, struct nvbios_vpstate_header *h)
{
if (!h)
return -EINVAL;
h->offset = nvbios_vpstate_offset(b);
if (!h->offset)
return -ENODEV;
h->version = nvbios_rd08(b, h->offset);
switch (h->version) {
case 0x10:
h->hlen = nvbios_rd08(b, h->offset + 0x1);
h->elen = nvbios_rd08(b, h->offset + 0x2);
h->slen = nvbios_rd08(b, h->offset + 0x3);
h->scount = nvbios_rd08(b, h->offset + 0x4);
h->ecount = nvbios_rd08(b, h->offset + 0x5);
h->base_id = nvbios_rd08(b, h->offset + 0x0f);
h->boost_id = nvbios_rd08(b, h->offset + 0x10);
h->tdp_id = nvbios_rd08(b, h->offset + 0x11);
return 0;
default:
return -EINVAL;
}
}
int
nvbios_vpstate_entry(struct nvkm_bios *b, struct nvbios_vpstate_header *h,
u8 idx, struct nvbios_vpstate_entry *e)
{
u32 offset;
if (!e || !h || idx > h->ecount)
return -EINVAL;
offset = h->offset + h->hlen + idx * (h->elen + (h->slen * h->scount));
e->pstate = nvbios_rd08(b, offset);
e->clock_mhz = nvbios_rd16(b, offset + 0x5);
return 0;
}
