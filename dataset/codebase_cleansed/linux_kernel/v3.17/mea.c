static int mea_last_char_hash(int count, char *name, int namelen)
{
unsigned int c;
c = name[namelen - 1];
if (c == 0)
CWARN("looks like wrong len is passed\n");
c = c % count;
return c;
}
static int mea_all_chars_hash(int count, char *name, int namelen)
{
unsigned int c = 0;
while (--namelen >= 0)
c += name[namelen];
c = c % count;
return c;
}
int raw_name2idx(int hashtype, int count, const char *name, int namelen)
{
unsigned int c = 0;
int idx;
LASSERT(namelen > 0);
if (filename_is_volatile(name, namelen, &idx)) {
if ((idx >= 0) && (idx < count))
return idx;
goto hashchoice;
}
if (count <= 1)
return 0;
hashchoice:
switch (hashtype) {
case MEA_MAGIC_LAST_CHAR:
c = mea_last_char_hash(count, (char *)name, namelen);
break;
case MEA_MAGIC_ALL_CHARS:
c = mea_all_chars_hash(count, (char *)name, namelen);
break;
case MEA_MAGIC_HASH_SEGMENT:
CERROR("Unsupported hash type MEA_MAGIC_HASH_SEGMENT\n");
break;
default:
CERROR("Unknown hash type 0x%x\n", hashtype);
}
LASSERT(c < count);
return c;
}
int mea_name2idx(struct lmv_stripe_md *mea, const char *name, int namelen)
{
unsigned int c;
LASSERT(mea && mea->mea_count);
c = raw_name2idx(mea->mea_magic, mea->mea_count, name, namelen);
LASSERT(c < mea->mea_count);
return c;
}
