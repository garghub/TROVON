static inline T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline bool F_3 ( int V_3 )
{
return F_1 ( V_4 + V_3 * 4 ) ;
}
static enum V_5 F_4 ( T_1 V_6 )
{
T_1 V_7 = ( V_6 >> 16 ) & 0xf ;
switch ( V_7 ) {
case 1 :
return V_8 ;
case 2 :
return V_9 ;
case 3 :
if ( V_10 == V_11 &&
( F_3 ( 18 ) || F_3 ( 19 ) ) )
return V_12 ;
else
return V_13 ;
case 4 :
return V_14 ;
default:
return V_15 ;
}
}
void F_5 ( void )
{
T_1 V_6 ;
T_1 V_16 = F_6 ( F_7 ( V_17 + 0x48 ) ) ;
V_16 |= 1 << 28 ;
F_8 ( V_16 , F_7 ( V_17 + 0x48 ) ) ;
V_16 = F_1 ( V_18 ) ;
V_19 = V_16 & 0xFF ;
V_16 = F_1 ( V_4 ) ;
V_20 = ( V_16 >> 6 ) & 3 ;
V_16 = F_1 ( V_4 ) ;
V_21 = ( V_16 >> 12 ) & 3 ;
V_16 = F_2 ( V_22 + V_23 ) ;
V_24 = ( V_16 & V_25 ) >> V_26 ;
V_6 = F_9 ( F_10 ( V_22 ) + 0x804 ) ;
V_10 = ( V_6 >> 8 ) & 0xff ;
V_5 = F_4 ( V_6 ) ;
F_11 ( L_1 ,
V_27 [ V_5 ] ,
V_19 , V_20 ,
V_21 ) ;
}
unsigned long long F_12 ( void )
{
unsigned long long V_28 , V_29 ;
V_28 = F_1 ( V_30 ) ;
V_29 = F_1 ( V_31 ) ;
return ( V_29 << 32ull ) | V_28 ;
}
