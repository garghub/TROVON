static void F_1 ( void )
{
F_2 () ;
F_3 ( V_1 , 1 ) ;
}
static void F_4 ( void )
{
F_3 ( V_2 , 0 ) ;
}
static unsigned long T_1 F_5 ( void )
{
return 0 ;
}
static void T_1 F_6 ( void )
{
F_7 () ;
F_8 () ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_3 , NULL , NULL , V_4 ) ;
switch ( V_5 ) {
case V_6 :
break;
case V_7 :
V_8 . V_9 . V_10 = F_6 ;
V_11 . V_10 = V_12 ;
return;
default:
if ( ! F_11 ( V_13 ) )
break;
V_8 . V_9 . V_10 = F_8 ;
V_11 . V_10 = V_12 ;
return;
}
V_8 . V_9 . V_10 = F_7 ;
}
static void F_12 ( void )
{
if ( V_14 . V_15 != 6 ) {
F_13 ( L_1 ,
V_14 . V_15 , V_14 . V_16 ) ;
V_17 = V_18 ;
goto V_19;
}
switch ( V_14 . V_16 ) {
case 0x35 :
V_17 = V_20 ;
break;
case 0x3C :
case 0x4A :
V_17 = V_21 ;
break;
case 0x27 :
default:
V_17 = V_18 ;
break;
}
if ( V_17 < F_14 ( V_22 ) )
V_23 = V_22 [ V_17 ] ( ) ;
else {
V_23 = V_22 [ V_18 ] ( ) ;
F_15 ( L_2 ) ;
}
V_19:
if ( V_23 -> V_24 )
V_23 -> V_24 () ;
F_16 () ;
}
static int F_17 ( void )
{
return 0 ;
}
static unsigned char F_18 ( void )
{
return 0 ;
}
void T_1 F_19 ( void )
{
V_8 . V_25 . V_26 = V_27 ;
V_8 . V_25 . V_28 = V_27 ;
V_8 . V_9 . V_29 = F_9 ;
V_8 . V_9 . V_10 = V_27 ;
V_8 . V_30 . V_31 = V_27 ;
V_8 . V_32 . V_24 = F_12 ;
V_11 . V_10 = V_33 ;
V_34 . V_35 = F_5 ;
V_34 . V_36 = F_17 ;
V_8 . V_9 . V_37 = V_38 ;
V_34 . V_39 = F_18 ;
V_8 . V_40 . V_41 = V_42 ;
V_8 . V_40 . V_43 = V_27 ;
V_44 = & V_45 ;
V_46 = F_1 ;
V_47 . V_48 = F_4 ;
V_8 . V_49 . V_50 = V_27 ;
V_8 . V_49 . V_51 = V_52 ;
F_20 ( V_53 , V_54 ) ;
}
static inline int T_1 F_21 ( char * V_55 )
{
if ( ! V_55 )
return - V_56 ;
if ( strcmp ( L_3 , V_55 ) == 0 )
V_5 = V_6 ;
else if ( strcmp ( L_4 , V_55 ) == 0 )
V_5 = V_7 ;
else {
F_22 ( L_5 ,
V_55 ) ;
return - V_56 ;
}
return 0 ;
}
