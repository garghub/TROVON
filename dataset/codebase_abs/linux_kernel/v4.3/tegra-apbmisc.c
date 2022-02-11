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
V_19 . V_21 = F_9 ( V_22 ) ;
}
void T_3 F_10 ( void )
{
struct V_23 V_24 , V_3 ;
struct V_25 * V_26 ;
V_26 = F_11 ( NULL , V_27 ) ;
if ( ! V_26 ) {
if ( F_12 ( V_28 ) && F_13 () ) {
V_24 . V_29 = 0x70000800 ;
V_24 . V_30 = 0x70000863 ;
V_24 . V_31 = V_32 ;
if ( F_3 () == V_33 ) {
V_3 . V_29 = 0x7000e864 ;
V_3 . V_30 = 0x7000e867 ;
} else {
V_3 . V_29 = 0x70000008 ;
V_3 . V_30 = 0x7000000b ;
}
V_3 . V_31 = V_32 ;
F_14 ( L_2 , & V_24 ) ;
F_14 ( L_3 ,
& V_3 ) ;
} else {
return;
}
} else {
if ( F_15 ( V_26 , 0 , & V_24 ) < 0 ) {
F_16 ( L_4 ) ;
return;
}
if ( F_15 ( V_26 , 1 , & V_3 ) < 0 ) {
F_16 ( L_5 ) ;
return;
}
}
V_1 = F_17 ( V_24 . V_29 , F_18 ( & V_24 ) ) ;
if ( ! V_1 )
F_16 ( L_6 ) ;
V_2 = F_17 ( V_3 . V_29 , F_18 ( & V_3 ) ) ;
if ( ! V_2 )
F_16 ( L_7 ) ;
V_4 = F_19 ( V_26 , L_8 ) ;
}
