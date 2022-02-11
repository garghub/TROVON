static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 () ;
if ( F_3 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_4 ( V_2 ) ) ) {
F_5 ( V_2 -> V_8 -> V_9 ,
L_1 ) ;
return V_5 ;
}
V_2 -> V_10 -> V_11 =
F_6 ( ( V_12 / 48000 ) - 2 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_13 = TRUE ;
V_2 -> V_14 = TRUE ;
V_2 -> V_15 = V_16 ;
V_5 = F_7 ( V_2 ) ;
if ( V_5 < 0 ) {
return V_5 ;
} else if ( V_5 == V_17 ) {
V_2 -> V_18 = V_19 |
V_20 |
V_21 ;
V_2 -> V_22 = L_2 ;
V_2 -> V_23 = V_2 -> V_24 = 6 ;
V_2 -> V_25 = V_2 -> V_26 = 14 ;
V_2 -> V_27 = V_2 -> V_28 = 16 ;
V_2 -> V_29 = V_2 -> V_30 = 24 ;
V_2 -> V_31 = TRUE ;
V_2 -> V_32 = TRUE ;
} else if ( V_5 == V_33 ) {
V_2 -> V_18 = V_19 |
V_20 |
V_21 |
V_34 ;
V_2 -> V_22 = L_3 ;
V_2 -> V_23 = V_2 -> V_24 = 8 ;
V_2 -> V_25 = V_2 -> V_26 = 16 ;
V_2 -> V_27 = V_2 -> V_28 = 24 ;
V_2 -> V_29 = V_2 -> V_30 = 32 ;
} else {
return - V_7 ;
}
V_2 -> V_35 = V_36 |
V_37 |
V_38 ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = FALSE ;
V_2 -> V_42 = FALSE ;
V_2 -> V_13 = FALSE ;
V_2 -> V_43 = FALSE ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , char V_44 )
{
T_2 V_45 = F_11 ( V_2 -> V_10 -> V_46 ) ;
if ( V_44 )
V_45 |= V_47 ;
else
V_45 &= ~ V_47 ;
V_2 -> V_43 = V_44 ;
return F_12 ( V_2 , V_45 ,
F_11 ( V_2 -> V_10 -> V_11 ) ,
0 ) ;
}
