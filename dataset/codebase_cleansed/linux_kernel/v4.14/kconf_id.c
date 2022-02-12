static const struct kconf_id *kconf_id_lookup(register const char *str, register unsigned int len)
{
int i;
for (i = 0; i < KCONF_ID_ARRAY_SIZE; i++) {
struct kconf_id *id = kconf_id_array+i;
int l = strlen(id->name);
if (len == l && !memcmp(str, id->name, len))
return id;
}
return NULL;
}
