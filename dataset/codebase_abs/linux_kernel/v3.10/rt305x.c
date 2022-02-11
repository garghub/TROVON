static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 <<
V_4 ;
F_3 ( V_1 , V_2 ) ;
}
static unsigned long F_4 ( void )
{
void T_2 * V_5 = ( void T_2 * ) F_5 ( V_6 ) ;
unsigned long V_7 ;
T_1 V_1 ;
V_1 = F_6 ( V_5 + V_2 ) ;
V_1 = ( V_1 >> V_8 ) &
V_9 ;
switch ( V_1 ) {
case V_10 :
V_7 = 2 ;
break;
case V_11 :
V_7 = 8 ;
break;
case V_12 :
V_7 = 16 ;
break;
case V_13 :
V_7 = 32 ;
break;
case V_14 :
V_7 = 64 ;
break;
default:
F_7 ( L_1 , V_1 ) ;
break;
}
return V_7 ;
}
void T_3 F_8 ( void )
{
unsigned long V_15 , V_16 , V_17 , V_18 ;
unsigned long V_19 = 40000000 ;
T_1 V_1 = F_2 ( V_2 ) ;
if ( F_9 () || F_10 () ) {
V_1 = ( V_1 >> V_20 ) &
V_21 ;
switch ( V_1 ) {
case V_22 :
V_15 = 320000000 ;
break;
case V_23 :
V_15 = 384000000 ;
break;
}
V_16 = V_18 = V_17 = V_15 / 3 ;
} else if ( F_11 () ) {
V_1 = ( V_1 >> V_24 ) &
V_25 ;
switch ( V_1 ) {
case V_26 :
V_15 = 384000000 ;
break;
case V_27 :
V_15 = 400000000 ;
break;
}
V_16 = V_17 = V_15 / 3 ;
V_18 = 40000000 ;
} else if ( F_12 () ) {
V_1 = ( V_1 >> V_28 ) &
V_29 ;
switch ( V_1 ) {
case V_30 :
V_15 = 360000000 ;
V_16 = V_15 / 3 ;
break;
case V_31 :
V_15 = 320000000 ;
V_16 = V_15 / 4 ;
break;
case V_32 :
V_15 = 300000000 ;
V_16 = V_15 / 3 ;
break;
default:
F_13 () ;
}
V_18 = 40000000 ;
V_17 = V_16 ;
} else {
F_13 () ;
}
if ( F_11 () || F_12 () ) {
T_1 V_33 = F_2 ( V_34 ) ;
if ( ! ( V_33 & V_35 ) )
V_19 = 20000000 ;
}
F_14 ( L_2 , V_15 ) ;
F_14 ( L_3 , V_16 ) ;
F_14 ( L_4 , V_17 ) ;
F_14 ( L_5 , V_17 ) ;
F_14 ( L_6 , V_18 ) ;
F_14 ( L_7 , V_18 ) ;
F_14 ( L_8 , V_16 ) ;
F_14 ( L_9 , V_19 ) ;
}
void T_3 F_15 ( void )
{
V_36 = F_16 ( L_10 ) ;
V_37 = F_16 ( L_11 ) ;
if ( ! V_36 || ! V_37 )
F_7 ( L_12 ) ;
}
void F_17 ( struct V_38 * V_39 )
{
void T_2 * V_5 = ( void T_2 * ) F_5 ( V_6 ) ;
unsigned char * V_40 ;
T_1 V_41 ;
T_1 V_42 ;
T_1 V_43 ;
V_41 = F_6 ( V_5 + V_44 ) ;
V_42 = F_6 ( V_5 + V_45 ) ;
if ( V_41 == V_46 && V_42 == V_47 ) {
unsigned long V_48 ;
V_48 = ( F_18 () >> 22 ) & 7 ;
if ( V_48 == 1 ) {
V_49 = V_50 ;
V_40 = L_13 ;
V_39 -> V_51 = L_14 ;
} else {
V_49 = V_52 ;
V_40 = L_15 ;
V_39 -> V_51 = L_16 ;
}
} else if ( V_41 == V_53 && V_42 == V_54 ) {
V_49 = V_55 ;
V_40 = L_17 ;
V_39 -> V_51 = L_18 ;
} else if ( V_41 == V_56 && V_42 == V_57 ) {
V_49 = V_58 ;
V_40 = L_19 ;
V_39 -> V_51 = L_20 ;
} else if ( V_41 == V_59 && V_42 == V_60 ) {
V_49 = V_61 ;
V_40 = L_21 ;
V_39 -> V_51 = L_22 ;
} else {
F_7 ( L_23 , V_41 , V_42 ) ;
}
V_43 = F_6 ( V_5 + V_62 ) ;
snprintf ( V_39 -> V_63 , V_64 ,
L_24 ,
V_40 ,
( V_43 >> V_65 ) & V_66 ,
( V_43 & V_67 ) ) ;
V_39 -> V_68 = V_69 ;
if ( F_12 () ) {
V_39 -> V_70 = F_4 () ;
} else if ( F_9 () || F_10 () ) {
V_39 -> V_71 = V_72 ;
V_39 -> V_73 = V_74 ;
} else if ( F_11 () ) {
V_39 -> V_71 = V_75 ;
V_39 -> V_73 = V_76 ;
}
}
