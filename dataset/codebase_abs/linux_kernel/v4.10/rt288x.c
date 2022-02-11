static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 ;
F_3 ( V_1 , V_2 ) ;
}
void T_2 F_4 ( void )
{
unsigned long V_4 , V_5 = 40000000 ;
T_1 V_1 = F_2 ( V_6 ) ;
V_1 = ( ( V_1 >> V_7 ) & V_8 ) ;
switch ( V_1 ) {
case V_9 :
V_4 = 250000000 ;
break;
case V_10 :
V_4 = 266666667 ;
break;
case V_11 :
V_4 = 280000000 ;
break;
case V_12 :
V_4 = 300000000 ;
break;
}
F_5 ( L_1 , V_4 ) ;
F_5 ( L_2 , V_4 / 2 ) ;
F_5 ( L_3 , V_4 / 2 ) ;
F_5 ( L_4 , V_4 / 2 ) ;
F_5 ( L_5 , V_4 / 2 ) ;
F_5 ( L_6 , V_4 / 2 ) ;
F_5 ( L_7 , V_5 ) ;
}
void T_2 F_6 ( void )
{
V_13 = F_7 ( L_8 ) ;
V_14 = F_7 ( L_9 ) ;
if ( ! V_13 || ! V_14 )
F_8 ( L_10 ) ;
}
void F_9 ( struct V_15 * V_16 )
{
void T_3 * V_17 = ( void T_3 * ) F_10 ( V_18 ) ;
const char * V_19 ;
T_1 V_20 ;
T_1 V_21 ;
T_1 V_22 ;
V_20 = F_11 ( V_17 + V_23 ) ;
V_21 = F_11 ( V_17 + V_24 ) ;
V_22 = F_11 ( V_17 + V_25 ) ;
if ( V_20 == V_26 && V_21 == V_27 ) {
V_16 -> V_28 = L_11 ;
V_19 = L_12 ;
} else {
F_8 ( L_13 , V_20 , V_21 ) ;
}
snprintf ( V_16 -> V_29 , V_30 ,
L_14 ,
V_19 ,
( V_22 >> V_31 ) & V_32 ,
( V_22 & V_33 ) ) ;
V_16 -> V_34 = V_35 ;
V_16 -> V_36 = V_37 ;
V_16 -> V_38 = V_39 ;
V_40 = V_41 ;
V_42 = V_43 ;
}
