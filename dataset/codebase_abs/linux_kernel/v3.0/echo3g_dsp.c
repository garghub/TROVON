static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 () ;
F_3 ( ( L_1 ) ) ;
if ( F_4 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_5 ( V_2 ) ) ) {
F_3 ( ( L_2 ) ) ;
return V_5 ;
}
V_2 -> V_8 -> V_9 =
F_6 ( ( V_10 / 48000 ) - 2 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_11 = TRUE ;
V_2 -> V_12 = TRUE ;
V_2 -> V_13 = V_14 ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 ) {
return V_5 ;
} else if ( V_5 == V_15 ) {
V_2 -> V_16 = V_17 |
V_18 |
V_19 ;
V_2 -> V_20 = L_3 ;
V_2 -> V_21 = V_2 -> V_22 = 6 ;
V_2 -> V_23 = V_2 -> V_24 = 14 ;
V_2 -> V_25 = V_2 -> V_26 = 16 ;
V_2 -> V_27 = V_2 -> V_28 = 24 ;
V_2 -> V_29 = TRUE ;
V_2 -> V_30 = TRUE ;
} else if ( V_5 == V_31 ) {
V_2 -> V_16 = V_17 |
V_18 |
V_19 |
V_32 ;
V_2 -> V_20 = L_4 ;
V_2 -> V_21 = V_2 -> V_22 = 8 ;
V_2 -> V_23 = V_2 -> V_24 = 16 ;
V_2 -> V_25 = V_2 -> V_26 = 24 ;
V_2 -> V_27 = V_2 -> V_28 = 32 ;
} else {
return - V_7 ;
}
V_2 -> V_33 = V_34 |
V_35 |
V_36 ;
F_3 ( ( L_5 ) ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
V_2 -> V_37 = V_38 ;
V_2 -> V_39 = FALSE ;
V_2 -> V_40 = FALSE ;
V_2 -> V_11 = FALSE ;
V_2 -> V_41 = FALSE ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , char V_42 )
{
T_2 V_43 = F_11 ( V_2 -> V_8 -> V_44 ) ;
if ( V_42 )
V_43 |= V_45 ;
else
V_43 &= ~ V_45 ;
V_2 -> V_41 = V_42 ;
return F_12 ( V_2 , V_43 ,
F_11 ( V_2 -> V_8 -> V_9 ) ,
0 ) ;
}
