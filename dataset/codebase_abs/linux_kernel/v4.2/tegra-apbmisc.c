T_1 F_1 ( void )
{
return F_2 ( V_1 + 4 ) ;
}
T_2 F_3 ( void )
{
if ( ! V_1 ) {
F_4 ( 1 , L_1 ) ;
return 0 ;
}
return ( F_1 () >> 8 ) & 0xff ;
}
T_1 F_5 ( void )
{
if ( V_2 )
return F_2 ( V_2 ) ;
else
return 0 ;
}
T_1 F_6 ( void )
{
T_1 V_3 = F_5 () ;
if ( V_4 )
V_3 &= V_5 ;
else
V_3 &= V_6 ;
return V_3 >> V_7 ;
}
void T_3 F_7 ( void )
{
T_1 V_8 , V_9 , V_10 ;
int V_11 ;
V_8 = F_1 () ;
V_9 = ( V_8 >> 8 ) & 0xff ;
V_10 = ( V_8 >> 16 ) & 0xf ;
switch ( V_10 ) {
case 1 :
V_11 = V_12 ;
break;
case 2 :
V_11 = V_13 ;
break;
case 3 :
if ( V_9 == V_14 && ( F_8 ( 18 ) ||
F_8 ( 19 ) ) )
V_11 = V_15 ;
else
V_11 = V_16 ;
break;
case 4 :
V_11 = V_17 ;
break;
default:
V_11 = V_18 ;
}
V_19 . V_20 = V_11 ;
if ( V_9 == V_14 )
V_19 . V_21 = F_9 ( V_22 ) ;
else
V_19 . V_21 = F_10 ( V_22 ) ;
}
void T_3 F_11 ( void )
{
struct V_23 * V_24 ;
V_24 = F_12 ( NULL , V_25 ) ;
V_1 = F_13 ( V_24 , 0 ) ;
if ( ! V_1 ) {
F_14 ( L_2 ,
V_26 ) ;
V_1 = F_15 ( V_26 , V_27 ) ;
}
V_2 = F_13 ( V_24 , 1 ) ;
if ( ! V_2 )
F_16 ( L_3 ) ;
V_4 = F_17 ( V_24 , L_4 ) ;
}
