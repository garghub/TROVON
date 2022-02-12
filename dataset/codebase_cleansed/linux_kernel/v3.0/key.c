char *cachefiles_cook_key(const u8 *raw, int keylen, uint8_t type)
{
unsigned char csum, ch;
unsigned int acc;
char *key;
int loop, len, max, seg, mark, print;
_enter(",%d", keylen);
BUG_ON(keylen < 2 || keylen > 514);
csum = raw[0] + raw[1];
print = 1;
for (loop = 2; loop < keylen; loop++) {
ch = raw[loop];
csum += ch;
print &= cachefiles_filecharmap[ch];
}
if (print) {
max = keylen - 2;
max += 2;
max += 5;
max += 3 * 2;
max += 1;
} else {
keylen = (keylen + 2) / 3;
max = keylen * 4;
max += 5;
max += 3 * 2;
max += 1;
}
max += 1;
_debug("max: %d", max);
key = kmalloc(max, GFP_KERNEL);
if (!key)
return NULL;
len = 0;
sprintf(key, "@%02x%c+", (unsigned) csum, 0);
len = 5;
mark = len - 1;
if (print) {
acc = *(uint16_t *) raw;
raw += 2;
key[len + 1] = cachefiles_charmap[acc & 63];
acc >>= 6;
key[len] = cachefiles_charmap[acc & 63];
len += 2;
seg = 250;
for (loop = keylen; loop > 0; loop--) {
if (seg <= 0) {
key[len++] = '\0';
mark = len;
key[len++] = '+';
seg = 252;
}
key[len++] = *raw++;
ASSERT(len < max);
}
switch (type) {
case FSCACHE_COOKIE_TYPE_INDEX: type = 'I'; break;
case FSCACHE_COOKIE_TYPE_DATAFILE: type = 'D'; break;
default: type = 'S'; break;
}
} else {
seg = 252;
for (loop = keylen; loop > 0; loop--) {
if (seg <= 0) {
key[len++] = '\0';
mark = len;
key[len++] = '+';
seg = 252;
}
acc = *raw++;
acc |= *raw++ << 8;
acc |= *raw++ << 16;
_debug("acc: %06x", acc);
key[len++] = cachefiles_charmap[acc & 63];
acc >>= 6;
key[len++] = cachefiles_charmap[acc & 63];
acc >>= 6;
key[len++] = cachefiles_charmap[acc & 63];
acc >>= 6;
key[len++] = cachefiles_charmap[acc & 63];
ASSERT(len < max);
}
switch (type) {
case FSCACHE_COOKIE_TYPE_INDEX: type = 'J'; break;
case FSCACHE_COOKIE_TYPE_DATAFILE: type = 'E'; break;
default: type = 'T'; break;
}
}
key[mark] = type;
key[len++] = 0;
key[len] = 0;
_leave(" = %p %d", key, len);
return key;
}
