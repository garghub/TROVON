void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 <<
V_4 ;
F_3 ( V_1 , V_2 ) ;
}
void T_2 F_4 ( void )
{
unsigned long V_5 , V_6 , V_7 , V_8 ;
T_1 V_1 = F_2 ( V_2 ) ;
if ( F_5 () || F_6 () ) {
V_1 = ( V_1 >> V_9 ) &
V_10 ;
switch ( V_1 ) {
case V_11 :
V_5 = 320000000 ;
break;
case V_12 :
V_5 = 384000000 ;
break;
}
V_6 = V_8 = V_7 = V_5 / 3 ;
} else if ( F_7 () ) {
V_1 = ( V_1 >> V_13 ) &
V_14 ;
switch ( V_1 ) {
case V_15 :
V_5 = 384000000 ;
break;
case V_16 :
V_5 = 400000000 ;
break;
}
V_6 = V_7 = V_5 / 3 ;
V_8 = 40000000 ;
} else if ( F_8 () ) {
V_1 = ( V_1 >> V_17 ) &
V_18 ;
switch ( V_1 ) {
case V_19 :
V_5 = 360000000 ;
V_6 = V_5 / 3 ;
break;
case V_20 :
V_5 = 320000000 ;
V_6 = V_5 / 4 ;
break;
case V_21 :
V_5 = 300000000 ;
V_6 = V_5 / 3 ;
break;
default:
F_9 () ;
}
V_8 = 40000000 ;
V_7 = V_6 ;
} else {
F_9 () ;
}
F_10 ( L_1 , V_5 ) ;
F_10 ( L_2 , V_6 ) ;
F_10 ( L_3 , V_7 ) ;
F_10 ( L_4 , V_8 ) ;
F_10 ( L_5 , V_8 ) ;
}
void T_2 F_11 ( void )
{
V_22 = F_12 ( L_6 ) ;
V_23 = F_12 ( L_7 ) ;
if ( ! V_22 || ! V_23 )
F_13 ( L_8 ) ;
}
void F_14 ( struct V_24 * V_25 )
{
void T_3 * V_26 = ( void T_3 * ) F_15 ( V_27 ) ;
unsigned char * V_28 ;
T_1 V_29 ;
T_1 V_30 ;
T_1 V_31 ;
V_29 = F_16 ( V_26 + V_32 ) ;
V_30 = F_16 ( V_26 + V_33 ) ;
if ( V_29 == V_34 && V_30 == V_35 ) {
unsigned long V_36 ;
V_36 = ( F_17 () >> 22 ) & 7 ;
if ( V_36 == 1 ) {
V_37 = V_38 ;
V_28 = L_9 ;
V_25 -> V_39 = L_10 ;
} else {
V_37 = V_40 ;
V_28 = L_11 ;
V_25 -> V_39 = L_12 ;
}
} else if ( V_29 == V_41 && V_30 == V_42 ) {
V_37 = V_43 ;
V_28 = L_13 ;
V_25 -> V_39 = L_14 ;
} else if ( V_29 == V_44 && V_30 == V_45 ) {
V_37 = V_46 ;
V_28 = L_15 ;
V_25 -> V_39 = L_16 ;
} else if ( V_29 == V_47 && V_30 == V_48 ) {
V_37 = V_49 ;
V_28 = L_17 ;
V_25 -> V_39 = L_18 ;
} else {
F_13 ( L_19 , V_29 , V_30 ) ;
}
V_31 = F_16 ( V_26 + V_50 ) ;
snprintf ( V_25 -> V_51 , V_52 ,
L_20 ,
V_28 ,
( V_31 >> V_53 ) & V_54 ,
( V_31 & V_55 ) ) ;
}
