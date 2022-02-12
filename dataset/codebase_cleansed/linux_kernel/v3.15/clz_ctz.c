int __weak __ctzsi2(int val)
{
return __ffs(val);
}
int __weak __clzsi2(int val)
{
return 32 - fls(val);
}
int __weak __clzdi2(long val)
{
return 32 - fls((int)val);
}
int __weak __ctzdi2(long val)
{
return __ffs((u32)val);
}
int __weak __clzdi2(long val)
{
return 64 - fls64((u64)val);
}
int __weak __ctzdi2(long val)
{
return __ffs64((u64)val);
}
