void T_1 F_1 ( void )
{
unsigned long V_1 , V_2 = 40000000 ;
T_2 V_3 = F_2 ( V_4 ) ;
V_3 = ( ( V_3 >> V_5 ) & V_6 ) ;
switch ( V_3 ) {
case V_7 :
V_1 = 250000000 ;
break;
case V_8 :
V_1 = 266666667 ;
break;
case V_9 :
V_1 = 280000000 ;
break;
case V_10 :
V_1 = 300000000 ;
break;
}
F_3 ( L_1 , V_1 ) ;
F_3 ( L_2 , V_1 / 2 ) ;
F_3 ( L_3 , V_1 / 2 ) ;
F_3 ( L_4 , V_1 / 2 ) ;
F_3 ( L_5 , V_1 / 2 ) ;
F_3 ( L_6 , V_1 / 2 ) ;
F_3 ( L_7 , V_1 / 2 ) ;
F_3 ( L_8 , V_2 ) ;
}
void T_1 F_4 ( void )
{
V_11 = F_5 ( L_9 ) ;
V_12 = F_5 ( L_10 ) ;
if ( ! V_11 || ! V_12 )
F_6 ( L_11 ) ;
}
void F_7 ( struct V_13 * V_14 )
{
void T_3 * V_15 = ( void T_3 * ) F_8 ( V_16 ) ;
const char * V_17 ;
T_2 V_18 ;
T_2 V_19 ;
T_2 V_20 ;
V_18 = F_9 ( V_15 + V_21 ) ;
V_19 = F_9 ( V_15 + V_22 ) ;
V_20 = F_9 ( V_15 + V_23 ) ;
if ( V_18 == V_24 && V_19 == V_25 ) {
V_14 -> V_26 = L_12 ;
V_17 = L_13 ;
} else {
F_6 ( L_14 , V_18 , V_19 ) ;
}
snprintf ( V_14 -> V_27 , V_28 ,
L_15 ,
V_17 ,
( V_20 >> V_29 ) & V_30 ,
( V_20 & V_31 ) ) ;
V_14 -> V_32 = V_33 ;
V_14 -> V_34 = V_35 ;
V_14 -> V_36 = V_37 ;
V_38 = V_39 ;
V_40 = V_41 ;
}
