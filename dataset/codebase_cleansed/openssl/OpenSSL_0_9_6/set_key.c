void des_set_odd_parity(des_cblock *key)
{
int i;
for (i=0; i<DES_KEY_SZ; i++)
(*key)[i]=odd_parity[(*key)[i]];
}
int des_check_key_parity(const_des_cblock *key)
{
int i;
for (i=0; i<DES_KEY_SZ; i++)
{
if ((*key)[i] != odd_parity[(*key)[i]])
return(0);
}
return(1);
}
int des_is_weak_key(const_des_cblock *key)
{
int i;
for (i=0; i<NUM_WEAK_KEY; i++)
if (memcmp(weak_keys[i],key,sizeof(des_cblock)) == 0) return(1);
return(0);
}
int des_set_key(const_des_cblock *key, des_key_schedule schedule)
{
if (des_check_key)
{
return des_set_key_checked(key, schedule);
}
else
{
des_set_key_unchecked(key, schedule);
return 0;
}
}
int des_set_key_checked(const_des_cblock *key, des_key_schedule schedule)
{
if (!des_check_key_parity(key))
return(-1);
if (des_is_weak_key(key))
return(-2);
des_set_key_unchecked(key, schedule);
return 0;
}
void des_set_key_unchecked(const_des_cblock *key, des_key_schedule schedule)
{
static int shifts2[16]={0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};
register DES_LONG c,d,t,s,t2;
register const unsigned char *in;
register DES_LONG *k;
register int i;
k = &schedule->ks.deslong[0];
in = &(*key)[0];
c2l(in,c);
c2l(in,d);
PERM_OP (d,c,t,4,0x0f0f0f0fL);
HPERM_OP(c,t,-2,0xcccc0000L);
HPERM_OP(d,t,-2,0xcccc0000L);
PERM_OP (d,c,t,1,0x55555555L);
PERM_OP (c,d,t,8,0x00ff00ffL);
PERM_OP (d,c,t,1,0x55555555L);
d= (((d&0x000000ffL)<<16L)| (d&0x0000ff00L) |
((d&0x00ff0000L)>>16L)|((c&0xf0000000L)>>4L));
c&=0x0fffffffL;
for (i=0; i<ITERATIONS; i++)
{
if (shifts2[i])
{ c=((c>>2L)|(c<<26L)); d=((d>>2L)|(d<<26L)); }
else
{ c=((c>>1L)|(c<<27L)); d=((d>>1L)|(d<<27L)); }
c&=0x0fffffffL;
d&=0x0fffffffL;
s= des_skb[0][ (c )&0x3f ]|
des_skb[1][((c>> 6L)&0x03)|((c>> 7L)&0x3c)]|
des_skb[2][((c>>13L)&0x0f)|((c>>14L)&0x30)]|
des_skb[3][((c>>20L)&0x01)|((c>>21L)&0x06) |
((c>>22L)&0x38)];
t= des_skb[4][ (d )&0x3f ]|
des_skb[5][((d>> 7L)&0x03)|((d>> 8L)&0x3c)]|
des_skb[6][ (d>>15L)&0x3f ]|
des_skb[7][((d>>21L)&0x0f)|((d>>22L)&0x30)];
t2=((t<<16L)|(s&0x0000ffffL))&0xffffffffL;
*(k++)=ROTATE(t2,30)&0xffffffffL;
t2=((s>>16L)|(t&0xffff0000L));
*(k++)=ROTATE(t2,26)&0xffffffffL;
}
}
int des_key_sched(const_des_cblock *key, des_key_schedule schedule)
{
return(des_set_key(key,schedule));
}
void des_fixup_key_parity(des_cblock *key)
{
des_set_odd_parity(key);
}
