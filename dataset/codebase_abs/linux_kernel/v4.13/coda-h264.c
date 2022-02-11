static const T_1 * F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
T_2 V_3 = 0xffffffff ;
do {
V_3 = V_3 << 8 | * V_1 ++ ;
if ( V_1 >= V_2 )
return NULL ;
} while ( V_3 != 0x00000001 );
return V_1 ;
}
int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
const T_1 * V_1 = F_3 ( V_7 , 0 ) ;
const T_1 * V_2 = V_1 + F_4 ( V_7 , 0 ) ;
do {
V_1 = F_1 ( V_1 , V_2 ) ;
if ( ! V_1 )
return - V_8 ;
} while ( ( * V_1 ++ & 0x1f ) != 0x7 );
V_5 -> V_9 . V_10 = V_1 [ 0 ] ;
V_5 -> V_9 . V_11 = V_1 [ 2 ] ;
return 0 ;
}
int F_5 ( int V_12 , char * V_13 )
{
if ( V_12 < 6 )
return - V_8 ;
V_13 [ 0 ] = 0x00 ;
V_13 [ 1 ] = 0x00 ;
V_13 [ 2 ] = 0x00 ;
V_13 [ 3 ] = 0x01 ;
V_13 [ 4 ] = 0x0c ;
memset ( V_13 + 5 , 0xff , V_12 - 6 ) ;
V_13 [ V_12 - 1 ] = 0x80 ;
return 0 ;
}
int F_6 ( int V_12 , char * V_13 )
{
int V_14 ;
int V_15 ;
V_15 = V_12 - ( V_12 & ~ 0x7 ) ;
if ( V_15 == 0 )
return 0 ;
V_14 = V_16 [ V_15 ] ;
F_5 ( V_14 , V_13 ) ;
return V_14 ;
}
int F_7 ( int V_17 )
{
switch ( V_17 ) {
case 66 : return V_18 ;
case 77 : return V_19 ;
case 88 : return V_20 ;
case 100 : return V_21 ;
default: return - V_8 ;
}
}
int F_8 ( int V_22 )
{
switch ( V_22 ) {
case 10 : return V_23 ;
case 9 : return V_24 ;
case 11 : return V_25 ;
case 12 : return V_26 ;
case 13 : return V_27 ;
case 20 : return V_28 ;
case 21 : return V_29 ;
case 22 : return V_30 ;
case 30 : return V_31 ;
case 31 : return V_32 ;
case 32 : return V_33 ;
case 40 : return V_34 ;
case 41 : return V_35 ;
default: return - V_8 ;
}
}
