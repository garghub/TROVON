T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
bool F_3 ( int V_3 )
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
static void F_5 ( void )
{
T_1 V_16 ;
V_16 = F_1 ( V_4 ) ;
V_17 = ( V_16 >> 6 ) & 3 ;
V_16 = F_1 ( V_4 ) ;
V_18 = ( V_16 >> 12 ) & 3 ;
}
T_1 F_6 ( void )
{
return F_7 ( F_8 ( V_19 ) + 0x804 ) ;
}
void F_9 ( void )
{
T_1 V_6 ;
T_1 V_16 = F_10 ( F_8 ( V_20 + 0x48 ) ) ;
V_16 |= 1 << 28 ;
F_11 ( V_16 , F_8 ( V_20 + 0x48 ) ) ;
V_16 = F_1 ( V_21 ) ;
V_22 = V_16 & 0xFF ;
V_16 = F_2 ( V_19 + V_23 ) ;
V_24 = ( V_16 & V_25 ) >> V_26 ;
V_6 = F_6 () ;
V_10 = ( V_6 >> 8 ) & 0xff ;
switch ( V_10 ) {
case V_11 :
V_4 = V_27 ;
V_28 = & V_29 ;
break;
case V_30 :
V_4 = V_31 ;
V_28 = & V_32 ;
break;
default:
F_12 ( L_1 , V_10 ) ;
V_4 = V_27 ;
V_28 = & F_5 ;
}
V_5 = F_4 ( V_6 ) ;
V_28 () ;
F_13 ( L_2 ,
V_33 [ V_5 ] ,
V_22 , V_17 ,
V_18 ) ;
}
unsigned long long F_14 ( void )
{
unsigned long long V_34 , V_35 ;
V_34 = F_1 ( V_36 ) ;
V_35 = F_1 ( V_37 ) ;
return ( V_35 << 32ull ) | V_34 ;
}
