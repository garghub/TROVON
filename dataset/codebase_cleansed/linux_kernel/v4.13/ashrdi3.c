DItype __ashrdi3(DItype u, word_type b)
{
union DIunion w;
union DIunion uu;
word_type bm;
if (b == 0)
return u;
uu.ll = u;
bm = (sizeof(SItype) * BITS_PER_UNIT) - b;
if (bm <= 0) {
w.s.high = uu.s.high >> (sizeof(SItype) * BITS_PER_UNIT - 1);
w.s.low = uu.s.high >> -bm;
} else {
USItype carries = (USItype)uu.s.high << bm;
w.s.high = uu.s.high >> b;
w.s.low = ((USItype)uu.s.low >> b) | carries;
}
return w.ll;
}
