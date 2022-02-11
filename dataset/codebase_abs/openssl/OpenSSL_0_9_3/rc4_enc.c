void F_1 ( T_1 * V_1 , unsigned long V_2 , unsigned char * V_3 ,
unsigned char * V_4 )
{
register T_2 * V_5 ;
register T_2 V_6 , V_7 , V_8 , V_9 ;
int V_10 ;
V_6 = V_1 -> V_6 ;
V_7 = V_1 -> V_7 ;
V_5 = V_1 -> V_11 ;
#define F_2 ( T_3 , T_4 ) \
x=((x+1)&0xff); \
tx=d[x]; \
y=(tx+y)&0xff; \
d[x]=ty=d[y]; \
d[y]=tx; \
(out) = d[(tx+ty)&0xff]^ (in);
#ifndef F_3
#define F_4 ( T_5 , T_6 , V_10 ) LOOP(*((a)++),*((b)++))
#else
#define F_4 ( T_5 , T_6 , V_10 ) LOOP(a[i],b[i])
#endif
V_10 = ( int ) ( V_2 >> 3L ) ;
if ( V_10 )
{
for (; ; )
{
F_4 ( V_3 , V_4 , 0 ) ;
F_4 ( V_3 , V_4 , 1 ) ;
F_4 ( V_3 , V_4 , 2 ) ;
F_4 ( V_3 , V_4 , 3 ) ;
F_4 ( V_3 , V_4 , 4 ) ;
F_4 ( V_3 , V_4 , 5 ) ;
F_4 ( V_3 , V_4 , 6 ) ;
F_4 ( V_3 , V_4 , 7 ) ;
#ifdef F_3
V_3 += 8 ;
V_4 += 8 ;
#endif
if ( -- V_10 == 0 ) break;
}
}
V_10 = ( int ) V_2 & 0x07 ;
if ( V_10 )
{
for (; ; )
{
F_4 ( V_3 , V_4 , 0 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 1 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 2 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 3 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 4 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 5 ) ; if ( -- V_10 == 0 ) break;
F_4 ( V_3 , V_4 , 6 ) ; if ( -- V_10 == 0 ) break;
}
}
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
}
