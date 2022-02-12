wchar_t
cifs_toupper(wchar_t in)
{
unsigned char idx;
const wchar_t *tbl;
wchar_t out;
idx = (in & 0xff00) >> 8;
tbl = toplevel[idx];
if (!tbl)
return in;
idx = in & 0xff;
out = tbl[idx];
if (out)
return out;
return in;
}
