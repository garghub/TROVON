const TBISTR *__TBIFindStr(const TBISTR *start,
const char *str, int match_len)
{
const TBISTR *search = start;
bool exact = true;
const TBISEG *seg;
if (match_len < 0) {
match_len = -match_len;
exact = false;
} else {
if (match_len && str[match_len-1] == '\0')
match_len--;
}
if (!search) {
seg = __TBIFindSeg(NULL, TBID_SEG(TBID_THREAD_GLOBAL,
TBID_SEGSCOPE_GLOBAL,
TBID_SEGTYPE_STRING));
if (!seg || seg->Bytes < sizeof(TBISTR))
return NULL;
search = seg->pGAddr;
}
for (;;) {
while (!search->Tag)
search = (const TBISTR *)((const char *)search + 8);
if (search->Tag == METAG_TBI_STRE) {
search = NULL;
break;
}
if ((search->Len >= match_len) &&
(!exact || (search->Len == match_len + 1)) &&
(search->Tag != METAG_TBI_STRG)) {
if (!strncmp(str, (const char *)search->String,
match_len))
break;
}
search = (const TBISTR *)((const char *)search + search->Bytes);
}
return search;
}
const void *__TBITransStr(const char *str, int len)
{
const TBISTR *search = NULL;
const void *res = NULL;
for (;;) {
search = __TBIFindStr(search, str, len);
if (!search)
break;
if (search->TransLen != METAG_TBI_STRX) {
res = (const char *)search->String +
((search->Len + 7) & ~7);
break;
}
search = (const TBISTR *)((const char *)search + search->Bytes);
}
return res;
}
