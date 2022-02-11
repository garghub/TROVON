static void F_1 ( void )
{
}
static void F_2 ( void )
{
F_3 ( V_1 , 0 ) ;
}
static unsigned long T_1 F_4 ( void )
{
unsigned long V_2 ;
T_2 V_3 , V_4 , V_5 , V_6 ;
F_5 ( V_7 , V_3 , V_4 ) ;
F_6 ( L_1 , V_3 , V_4 ) ;
V_5 = ( V_4 >> 8 ) & 0x1f ;
F_6 ( L_2 , V_5 ) ;
if ( ! V_5 ) {
F_7 ( L_3 ) ;
F_7 ( L_4 ) ;
V_5 = 16 ;
}
F_5 ( V_8 , V_3 , V_4 ) ;
if ( ( V_3 & 0x7 ) == 0x7 )
V_6 = V_9 ;
else
V_6 = V_10 ;
V_2 = V_5 * V_6 ;
F_6 ( L_5 , V_2 ) ;
V_11 = V_6 * 1000 / V_12 ;
F_8 ( & V_13 , V_14 ) ;
if ( V_2 )
return V_2 ;
return 0 ;
}
static void T_1 F_9 ( void )
{
F_10 ( V_15 , NULL , NULL , V_16 ) ;
switch ( V_17 ) {
case V_18 :
break;
case V_19 :
V_20 . V_21 . V_22 = V_23 ;
V_24 . V_22 = V_25 ;
break;
default:
if ( ! F_11 ( V_26 ) )
break;
V_20 . V_21 . V_22 = V_23 ;
V_24 . V_22 = V_25 ;
return;
}
F_12 () ;
F_13 () ;
}
static void F_14 ( void )
{
if ( V_13 . V_27 == 6 && V_13 . V_28 == 0x27 )
V_29 = V_30 ;
else {
F_7 ( L_6 ,
V_13 . V_27 , V_13 . V_28 ) ;
V_29 = V_30 ;
}
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
V_20 . V_31 . V_32 = V_33 ;
V_20 . V_31 . V_34 = V_33 ;
V_20 . V_21 . V_35 = F_9 ;
V_20 . V_21 . V_22 = V_33 ;
V_20 . V_36 . V_37 = V_33 ;
V_20 . V_38 . V_39 = F_14 ;
V_24 . V_22 = V_40 ;
V_41 . V_42 = F_4 ;
V_41 . V_43 = F_15 ;
V_20 . V_21 . V_44 = V_45 ;
V_41 . V_46 = F_16 ;
V_20 . V_47 . V_48 = V_49 ;
V_20 . V_47 . V_50 = V_33 ;
V_51 = & V_52 ;
V_53 = F_1 ;
V_54 . V_55 = F_2 ;
V_20 . V_56 . V_57 = V_33 ;
V_20 . V_56 . V_58 = V_59 ;
F_18 ( V_60 , V_61 ) ;
}
static inline int T_1 F_19 ( char * V_62 )
{
if ( ! V_62 )
return - V_63 ;
if ( strcmp ( L_7 , V_62 ) == 0 )
V_17 = V_18 ;
else if ( strcmp ( L_8 , V_62 ) == 0 )
V_17 = V_19 ;
else {
F_20 ( L_9
L_10 ,
V_62 ) ;
return - V_63 ;
}
return 0 ;
}
