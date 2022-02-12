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
void
nvkm_snprintbf(char *data, int size, const struct nvkm_bitfield *bf, u32 value)
{
bool space = false;
while (size >= 1 && bf->name) {
if (value & bf->mask) {
int this = snprintf(data, size, "%s%s",
space ? " " : "", bf->name);
size -= this;
data += this;
space = true;
}
bf++;
}
data[0] = '\0';
}
