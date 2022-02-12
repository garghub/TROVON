const struct nouveau_enum *
nouveau_enum_find(const struct nouveau_enum *en, u32 value)
{
while (en->name) {
if (en->value == value)
return en;
en++;
}
return NULL;
}
void
nouveau_enum_print(const struct nouveau_enum *en, u32 value)
{
en = nouveau_enum_find(en, value);
if (en)
printk("%s", en->name);
else
printk("(unknown enum 0x%08x)", value);
}
void
nouveau_bitfield_print(const struct nouveau_bitfield *bf, u32 value)
{
while (bf->name) {
if (value & bf->mask) {
printk(" %s", bf->name);
value &= ~bf->mask;
}
bf++;
}
if (value)
printk(" (unknown bits 0x%08x)", value);
}
