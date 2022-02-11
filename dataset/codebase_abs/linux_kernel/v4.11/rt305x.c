static unsigned long F_1 ( void )
{
void T_1 * V_1 = ( void T_1 * ) F_2 ( V_2 ) ;
unsigned long V_3 ;
T_2 V_4 ;
V_4 = F_3 ( V_1 + V_5 ) ;
V_4 = ( V_4 >> V_6 ) &
V_7 ;
switch ( V_4 ) {
case V_8 :
V_3 = 2 ;
break;
case V_9 :
V_3 = 8 ;
break;
case V_10 :
V_3 = 16 ;
break;
case V_11 :
V_3 = 32 ;
break;
case V_12 :
V_3 = 64 ;
break;
default:
F_4 ( L_1 , V_4 ) ;
break;
}
return V_3 ;
}
void T_3 F_5 ( void )
{
unsigned long V_13 , V_14 , V_15 , V_16 ;
unsigned long V_17 = 40000000 ;
T_2 V_4 = F_6 ( V_5 ) ;
if ( F_7 () || F_8 () ) {
V_4 = ( V_4 >> V_18 ) &
V_19 ;
switch ( V_4 ) {
case V_20 :
V_13 = 320000000 ;
break;
case V_21 :
V_13 = 384000000 ;
break;
}
V_14 = V_16 = V_15 = V_13 / 3 ;
} else if ( F_9 () ) {
V_4 = ( V_4 >> V_22 ) &
V_23 ;
switch ( V_4 ) {
case V_24 :
V_13 = 384000000 ;
break;
case V_25 :
V_13 = 400000000 ;
break;
}
V_14 = V_15 = V_13 / 3 ;
V_16 = 40000000 ;
} else if ( F_10 () ) {
V_4 = ( V_4 >> V_26 ) &
V_27 ;
switch ( V_4 ) {
case V_28 :
V_13 = 360000000 ;
V_14 = V_13 / 3 ;
break;
case V_29 :
V_13 = 320000000 ;
V_14 = V_13 / 4 ;
break;
case V_30 :
V_13 = 300000000 ;
V_14 = V_13 / 3 ;
break;
default:
F_11 () ;
}
V_16 = 40000000 ;
V_15 = V_14 ;
} else {
F_11 () ;
}
if ( F_9 () || F_10 () ) {
T_2 V_31 = F_6 ( V_32 ) ;
if ( ! ( V_31 & V_33 ) )
V_17 = 20000000 ;
}
F_12 ( L_2 , V_13 ) ;
F_12 ( L_3 , V_14 ) ;
F_12 ( L_4 , V_16 ) ;
F_12 ( L_5 , V_16 ) ;
F_12 ( L_6 , V_14 ) ;
F_12 ( L_7 , V_14 ) ;
F_12 ( L_8 , V_15 ) ;
F_12 ( L_9 , V_15 ) ;
F_12 ( L_10 , V_16 ) ;
F_12 ( L_11 , V_16 ) ;
F_12 ( L_12 , V_14 ) ;
F_12 ( L_13 , V_17 ) ;
}
void T_3 F_13 ( void )
{
V_34 = F_14 ( L_14 ) ;
V_35 = F_14 ( L_15 ) ;
if ( ! V_34 || ! V_35 )
F_4 ( L_16 ) ;
}
void F_15 ( struct V_36 * V_37 )
{
void T_1 * V_1 = ( void T_1 * ) F_2 ( V_2 ) ;
unsigned char * V_38 ;
T_2 V_39 ;
T_2 V_40 ;
T_2 V_41 ;
V_39 = F_3 ( V_1 + V_42 ) ;
V_40 = F_3 ( V_1 + V_43 ) ;
if ( V_39 == V_44 && V_40 == V_45 ) {
unsigned long V_46 ;
V_46 = ( F_16 () >> 22 ) & 7 ;
if ( V_46 == 1 ) {
V_47 = V_48 ;
V_38 = L_17 ;
V_37 -> V_49 = L_18 ;
} else {
V_47 = V_50 ;
V_38 = L_19 ;
V_37 -> V_49 = L_20 ;
}
} else if ( V_39 == V_51 && V_40 == V_52 ) {
V_47 = V_53 ;
V_38 = L_21 ;
V_37 -> V_49 = L_22 ;
} else if ( V_39 == V_54 && V_40 == V_55 ) {
V_47 = V_56 ;
V_38 = L_23 ;
V_37 -> V_49 = L_24 ;
} else if ( V_39 == V_57 && V_40 == V_58 ) {
V_47 = V_59 ;
V_38 = L_25 ;
V_37 -> V_49 = L_26 ;
} else {
F_4 ( L_27 , V_39 , V_40 ) ;
}
V_41 = F_3 ( V_1 + V_60 ) ;
snprintf ( V_37 -> V_61 , V_62 ,
L_28 ,
V_38 ,
( V_41 >> V_63 ) & V_64 ,
( V_41 & V_65 ) ) ;
V_37 -> V_66 = V_67 ;
if ( F_10 () ) {
V_37 -> V_68 = F_1 () ;
V_69 = V_70 ;
} else if ( F_7 () || F_8 () ) {
V_37 -> V_71 = V_72 ;
V_37 -> V_73 = V_74 ;
V_69 = V_75 ;
} else if ( F_9 () ) {
V_37 -> V_71 = V_76 ;
V_37 -> V_73 = V_77 ;
V_69 = V_78 ;
}
}
