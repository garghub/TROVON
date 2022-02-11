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
void T_3 F_6 ( void )
{
T_1 V_3 , V_4 , V_5 ;
int V_6 ;
V_3 = F_1 () ;
V_4 = ( V_3 >> 8 ) & 0xff ;
V_5 = ( V_3 >> 16 ) & 0xf ;
switch ( V_5 ) {
case 1 :
V_6 = V_7 ;
break;
case 2 :
V_6 = V_8 ;
break;
case 3 :
if ( V_4 == V_9 && ( F_7 ( 18 ) ||
F_7 ( 19 ) ) )
V_6 = V_10 ;
else
V_6 = V_11 ;
break;
case 4 :
V_6 = V_12 ;
break;
default:
V_6 = V_13 ;
}
V_14 . V_15 = V_6 ;
if ( V_4 == V_9 )
V_14 . V_16 = F_8 ( V_17 ) ;
else
V_14 . V_16 = F_9 ( V_17 ) ;
}
void T_3 F_10 ( void )
{
struct V_18 * V_19 ;
V_19 = F_11 ( NULL , V_20 ) ;
V_1 = F_12 ( V_19 , 0 ) ;
if ( ! V_1 ) {
F_13 ( L_2 ,
V_21 ) ;
V_1 = F_14 ( V_21 , V_22 ) ;
}
V_2 = F_12 ( V_19 , 1 ) ;
if ( ! V_2 )
F_15 ( L_3 ) ;
}
