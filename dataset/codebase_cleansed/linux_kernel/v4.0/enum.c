const struct nvkm_enum *
nvkm_enum_find(const struct nvkm_enum *en, u32 value)
{
while (en->name) {
if (en->value == value)
return en;
en++;
}
return NULL;
}
const struct nvkm_enum *
nvkm_enum_print(const struct nvkm_enum *en, u32 value)
{
en = nvkm_enum_find(en, value);
if (en)
pr_cont("%s", en->name);
else
pr_cont("(unknown enum 0x%08x)", value);
return en;
}
void
nvkm_bitfield_print(const struct nvkm_bitfield *bf, u32 value)
{
while (bf->name) {
if (value & bf->mask) {
pr_cont(" %s", bf->name);
value &= ~bf->mask;
}
bf++;
}
if (value)
pr_cont(" (unknown bits 0x%08x)", value);
}
