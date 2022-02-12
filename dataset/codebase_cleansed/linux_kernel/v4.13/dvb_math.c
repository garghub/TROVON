unsigned int intlog2(u32 value)
{
unsigned int msb;
unsigned int logentry;
unsigned int significand;
unsigned int interpolation;
if (unlikely(value == 0)) {
WARN_ON(1);
return 0;
}
msb = fls(value) - 1;
significand = value << (31 - msb);
logentry = (significand >> 23) & 0xff;
interpolation = ((significand & 0x7fffff) *
((logtable[(logentry + 1) & 0xff] -
logtable[logentry]) & 0xffff)) >> 15;
return ((msb << 24) + (logtable[logentry] << 8) + interpolation);
}
unsigned int intlog10(u32 value)
{
u64 log;
if (unlikely(value == 0)) {
WARN_ON(1);
return 0;
}
log = intlog2(value);
return (log * 646456993) >> 31;
}
