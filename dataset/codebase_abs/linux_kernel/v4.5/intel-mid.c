static void F_1 ( void )
{
}
static void F_2 ( void )
{
F_3 ( V_1 , 0 ) ;
}
static unsigned long T_1 F_4 ( void )
{
return 0 ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
F_7 () ;
}
static void T_1 F_8 ( void )
{
F_9 ( V_2 , NULL , NULL , V_3 ) ;
switch ( V_4 ) {
case V_5 :
break;
case V_6 :
V_7 . V_8 . V_9 = F_5 ;
V_10 . V_9 = V_11 ;
return;
default:
if ( ! F_10 ( V_12 ) )
break;
V_7 . V_8 . V_9 = F_7 ;
V_10 . V_9 = V_11 ;
return;
}
V_7 . V_8 . V_9 = F_6 ;
}
static void F_11 ( void )
{
if ( V_13 . V_14 != 6 ) {
F_12 ( L_1 ,
V_13 . V_14 , V_13 . V_15 ) ;
V_16 = V_17 ;
goto V_18;
}
switch ( V_13 . V_15 ) {
case 0x35 :
V_16 = V_19 ;
break;
case 0x3C :
case 0x4A :
V_16 = V_20 ;
break;
case 0x27 :
default:
V_16 = V_17 ;
break;
}
if ( V_16 < F_13 ( V_21 ) )
V_22 = V_21 [ V_16 ] ( ) ;
else {
V_22 = V_21 [ V_17 ] ( ) ;
F_14 ( L_2 ) ;
}
V_18:
if ( V_22 -> V_23 )
V_22 -> V_23 () ;
}
static int F_15 ( void )
{
return 0 ;
}
static unsigned char F_16 ( void )
{
return 0 ;
}
void T_1 F_17 ( void )
{
V_7 . V_24 . V_25 = V_26 ;
V_7 . V_24 . V_27 = V_26 ;
V_7 . V_8 . V_28 = F_8 ;
V_7 . V_8 . V_9 = V_26 ;
V_7 . V_29 . V_30 = V_26 ;
V_7 . V_31 . V_23 = F_11 ;
V_10 . V_9 = V_32 ;
V_33 . V_34 = F_4 ;
V_33 . V_35 = F_15 ;
V_7 . V_8 . V_36 = V_37 ;
V_33 . V_38 = F_16 ;
V_7 . V_39 . V_40 = V_41 ;
V_7 . V_39 . V_42 = V_26 ;
V_43 = & V_44 ;
V_45 = F_1 ;
V_46 . V_47 = F_2 ;
V_7 . V_48 . V_49 = V_26 ;
V_7 . V_48 . V_50 = V_51 ;
F_18 ( V_52 , V_53 ) ;
}
static inline int T_1 F_19 ( char * V_54 )
{
if ( ! V_54 )
return - V_55 ;
if ( strcmp ( L_3 , V_54 ) == 0 )
V_4 = V_5 ;
else if ( strcmp ( L_4 , V_54 ) == 0 )
V_4 = V_6 ;
else {
F_20 ( L_5 ,
V_54 ) ;
return - V_55 ;
}
return 0 ;
}
