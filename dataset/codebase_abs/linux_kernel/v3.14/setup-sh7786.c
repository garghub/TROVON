void T_1 F_1 ( void )
{
T_2 V_1 = F_2 ( V_2 ) & V_3 ;
F_3 ( V_1 | V_4 , V_2 ) ;
}
static void T_1 F_4 ( void )
{
int V_5 = 1000000 ;
F_3 ( V_6 , V_7 ) ;
F_3 ( V_8 , V_9 ) ;
F_3 ( V_10 | V_11 , V_12 ) ;
while ( V_5 -- ) {
if ( V_13 == ( F_2 ( V_14 ) & V_13 ) ) {
F_3 ( V_10 | V_11 | V_15 , V_12 ) ;
F_5 ( V_16 L_1 ) ;
break;
}
F_6 () ;
}
}
void T_1 F_7 ( void )
{
F_3 ( 0xff000000 , V_17 ) ;
F_3 ( 0xc0000000 , V_18 ) ;
F_3 ( 0xfffefffe , V_19 ) ;
F_3 ( F_2 ( V_20 ) & ~ 0x00c00000 , V_20 ) ;
F_8 ( & V_21 ) ;
}
void T_1 F_9 ( int V_22 )
{
switch ( V_22 ) {
case V_23 :
F_3 ( F_2 ( V_20 ) | 0x00400000 , V_20 ) ;
F_8 ( & V_24 ) ;
break;
case V_25 :
F_3 ( F_2 ( V_20 ) | 0x00800000 , V_20 ) ;
F_8 ( & V_26 ) ;
break;
case V_27 :
F_3 ( 0x40000000 , V_28 ) ;
F_3 ( 0x0000fffe , V_29 ) ;
break;
case V_30 :
F_3 ( 0x80000000 , V_28 ) ;
F_3 ( 0xfffe0000 , V_29 ) ;
break;
case V_31 :
F_3 ( 0x40000000 , V_28 ) ;
F_8 ( & V_32 ) ;
break;
case V_33 :
F_3 ( 0x80000000 , V_28 ) ;
F_8 ( & V_34 ) ;
break;
default:
F_10 () ;
}
}
void T_1 F_11 ( void )
{
}
static int T_1 F_12 ( void )
{
int V_35 , V_36 ;
F_4 () ;
V_36 = F_13 ( V_21 . V_37 , V_38 ) ;
if ( V_36 > 0 ) {
V_39 [ 1 ] . V_40 =
F_13 ( V_21 . V_37 , V_41 ) ;
V_39 [ 2 ] . V_40 =
F_13 ( V_21 . V_37 , V_42 ) ;
V_39 [ 3 ] . V_40 = V_36 ;
V_39 [ 4 ] . V_40 =
F_13 ( V_21 . V_37 , V_43 ) ;
V_44 . V_45 = V_39 ;
V_44 . V_46 = F_14 ( V_39 ) ;
}
V_35 = F_15 ( V_47 ,
F_14 ( V_47 ) ) ;
if ( F_16 ( V_35 != 0 ) )
return V_35 ;
return F_15 ( V_48 ,
F_14 ( V_48 ) ) ;
}
void T_1 F_17 ( void )
{
F_18 ( V_47 ,
F_14 ( V_47 ) ) ;
}
