void F_1 ( T_1 * V_1 , T_2 V_2 , const unsigned char * V_3 ,
unsigned char * V_4 )
{
register T_3 * V_5 ;
register T_3 V_6 , V_7 , V_8 , V_9 ;
T_2 V_10 ;
V_6 = V_1 -> V_6 ;
V_7 = V_1 -> V_7 ;
V_5 = V_1 -> V_11 ;
#define F_2 ( T_4 , T_5 ) \
x=((x+1)&0xff); \
tx=d[x]; \
y=(tx+y)&0xff; \
d[x]=ty=d[y]; \
d[y]=tx; \
(out) = d[(tx+ty)&0xff]^ (in);
V_10 = V_2 >> 3 ;
if ( V_10 ) {
for (; ; ) {
F_2 ( V_3 [ 0 ] , V_4 [ 0 ] ) ;
F_2 ( V_3 [ 1 ] , V_4 [ 1 ] ) ;
F_2 ( V_3 [ 2 ] , V_4 [ 2 ] ) ;
F_2 ( V_3 [ 3 ] , V_4 [ 3 ] ) ;
F_2 ( V_3 [ 4 ] , V_4 [ 4 ] ) ;
F_2 ( V_3 [ 5 ] , V_4 [ 5 ] ) ;
F_2 ( V_3 [ 6 ] , V_4 [ 6 ] ) ;
F_2 ( V_3 [ 7 ] , V_4 [ 7 ] ) ;
V_3 += 8 ;
V_4 += 8 ;
if ( -- V_10 == 0 )
break;
}
}
V_10 = V_2 & 0x07 ;
if ( V_10 ) {
for (; ; ) {
F_2 ( V_3 [ 0 ] , V_4 [ 0 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 1 ] , V_4 [ 1 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 2 ] , V_4 [ 2 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 3 ] , V_4 [ 3 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 4 ] , V_4 [ 4 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 5 ] , V_4 [ 5 ] ) ;
if ( -- V_10 == 0 )
break;
F_2 ( V_3 [ 6 ] , V_4 [ 6 ] ) ;
if ( -- V_10 == 0 )
break;
}
}
V_1 -> V_6 = V_6 ;
V_1 -> V_7 = V_7 ;
}
