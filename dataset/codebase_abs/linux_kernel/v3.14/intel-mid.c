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
F_6 ( V_2 , NULL , NULL , V_3 ) ;
switch ( V_4 ) {
case V_5 :
break;
case V_6 :
V_7 . V_8 . V_9 = V_10 ;
V_11 . V_9 = V_12 ;
break;
default:
if ( ! F_7 ( V_13 ) )
break;
V_7 . V_8 . V_9 = V_10 ;
V_11 . V_9 = V_12 ;
return;
}
F_8 () ;
F_9 () ;
}
static void F_10 ( void )
{
if ( V_14 . V_15 != 6 ) {
F_11 ( L_1 ,
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
if ( V_17 < F_12 ( V_22 ) )
V_23 = V_22 [ V_17 ] ( ) ;
else {
V_23 = V_22 [ V_18 ] ( ) ;
F_13 ( L_2 ) ;
}
V_19:
if ( V_23 -> V_24 )
V_23 -> V_24 () ;
}
static int F_14 ( void )
{
return 0 ;
}
static unsigned char F_15 ( void )
{
return 0 ;
}
void T_1 F_16 ( void )
{
V_7 . V_25 . V_26 = V_27 ;
V_7 . V_25 . V_28 = V_27 ;
V_7 . V_8 . V_29 = F_5 ;
V_7 . V_8 . V_9 = V_27 ;
V_7 . V_30 . V_31 = V_27 ;
V_7 . V_32 . V_24 = F_10 ;
V_11 . V_9 = V_33 ;
V_34 . V_35 = F_4 ;
V_34 . V_36 = F_14 ;
V_7 . V_8 . V_37 = V_38 ;
V_34 . V_39 = F_15 ;
V_7 . V_40 . V_41 = V_42 ;
V_7 . V_40 . V_43 = V_27 ;
V_44 = & V_45 ;
V_46 = F_1 ;
V_47 . V_48 = F_2 ;
V_7 . V_49 . V_50 = V_27 ;
V_7 . V_49 . V_51 = V_52 ;
F_17 ( V_53 , V_54 ) ;
}
static inline int T_1 F_18 ( char * V_55 )
{
if ( ! V_55 )
return - V_56 ;
if ( strcmp ( L_3 , V_55 ) == 0 )
V_4 = V_5 ;
else if ( strcmp ( L_4 , V_55 ) == 0 )
V_4 = V_6 ;
else {
F_19 ( L_5
L_6 ,
V_55 ) ;
return - V_56 ;
}
return 0 ;
}
