static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= V_3 ;
F_3 ( V_1 , V_2 ) ;
}
void T_2 F_4 ( void )
{
unsigned long V_4 ;
T_1 V_1 = F_2 ( V_5 ) ;
V_1 = ( ( V_1 >> V_6 ) & V_7 ) ;
switch ( V_1 ) {
case V_8 :
V_4 = 250000000 ;
break;
case V_9 :
V_4 = 266666667 ;
break;
case V_10 :
V_4 = 280000000 ;
break;
case V_11 :
V_4 = 300000000 ;
break;
}
F_5 ( L_1 , V_4 ) ;
F_5 ( L_2 , V_4 / 2 ) ;
F_5 ( L_3 , V_4 / 2 ) ;
F_5 ( L_4 , V_4 / 2 ) ;
F_5 ( L_5 , V_4 / 2 ) ;
F_5 ( L_6 , V_4 / 2 ) ;
}
void T_2 F_6 ( void )
{
V_12 = F_7 ( L_7 ) ;
V_13 = F_7 ( L_8 ) ;
if ( ! V_12 || ! V_13 )
F_8 ( L_9 ) ;
}
void F_9 ( struct V_14 * V_15 )
{
void T_3 * V_16 = ( void T_3 * ) F_10 ( V_17 ) ;
const char * V_18 ;
T_1 V_19 ;
T_1 V_20 ;
T_1 V_21 ;
V_19 = F_11 ( V_16 + V_22 ) ;
V_20 = F_11 ( V_16 + V_23 ) ;
V_21 = F_11 ( V_16 + V_24 ) ;
if ( V_19 == V_25 && V_20 == V_26 ) {
V_15 -> V_27 = L_10 ;
V_18 = L_11 ;
} else {
F_8 ( L_12 , V_19 , V_20 ) ;
}
snprintf ( V_15 -> V_28 , V_29 ,
L_13 ,
V_18 ,
( V_21 >> V_30 ) & V_31 ,
( V_21 & V_32 ) ) ;
V_15 -> V_33 = V_34 ;
V_15 -> V_35 = V_36 ;
V_15 -> V_37 = V_38 ;
}
