static inline int F_1 ( void )
{
unsigned char V_1 = * ( volatile unsigned char * ) V_2 ;
return ( V_1 & 0xa0 ) == 0x20 ;
}
int F_2 ( const struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
switch ( V_7 ) {
case V_8 :
if ( V_5 == 4 ) {
while ( V_4 && V_4 -> V_9 -> V_10 != 1 )
V_4 = V_4 -> V_9 -> V_11 ;
if ( V_4 && V_4 -> V_12 >= F_3 ( 4 , 0 ) )
V_5 = 5 ;
}
return V_13 [ V_5 ] [ V_6 ] ;
case V_14 :
return V_15 [ V_5 ] [ V_6 ] ;
case V_16 :
if ( F_1 () )
return V_17 [ V_5 ] [ V_6 ] ;
case V_18 :
return V_19 [ V_5 ] [ V_6 ] ;
case V_20 :
return V_21 [ V_5 ] [ V_6 ] ;
}
return 0 ;
}
int F_4 ( struct V_3 * V_4 )
{
return 0 ;
}
