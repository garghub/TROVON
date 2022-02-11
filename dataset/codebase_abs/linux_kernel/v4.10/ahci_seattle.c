static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_8 ;
struct V_11 * V_12 = V_6 -> V_12 ;
unsigned long V_13 ;
int V_14 ;
struct V_15 * V_16 ;
T_2 V_17 ;
V_14 = ( V_3 & V_18 ) >> 8 ;
if ( V_14 >= V_19 )
return - V_20 ;
V_16 = & V_10 -> V_21 [ V_14 ] ;
V_17 = F_2 ( V_12 -> V_22 ) ;
if ( V_3 & V_23 )
V_17 |= 1 << F_3 ( ( V_2 -> V_24 ) ) ;
else
V_17 &= ~ ( 1 << F_3 ( ( V_2 -> V_24 ) ) ) ;
if ( V_3 & V_25 )
V_17 |= 1 << F_4 ( ( V_2 -> V_24 ) ) ;
else
V_17 &= ~ ( 1 << F_4 ( ( V_2 -> V_24 ) ) ) ;
if ( V_3 & V_26 )
V_17 |= 1 << F_5 ( ( V_2 -> V_24 ) ) ;
else
V_17 &= ~ ( 1 << F_5 ( ( V_2 -> V_24 ) ) ) ;
F_6 ( V_17 , V_12 -> V_22 ) ;
F_7 ( V_2 -> V_27 , V_13 ) ;
V_16 -> V_28 = V_3 ;
F_8 ( V_2 -> V_27 , V_13 ) ;
return V_4 ;
}
static const struct V_29 * F_9 (
struct V_30 * V_31 , struct V_5 * V_6 )
{
struct V_32 * V_33 = & V_31 -> V_33 ;
struct V_11 * V_12 ;
T_2 V_17 ;
V_12 = F_10 ( V_33 , sizeof( * V_12 ) , V_34 ) ;
if ( ! V_12 )
return & V_35 ;
V_12 -> V_22 = F_11 ( V_33 ,
F_12 ( V_31 , V_36 , 1 ) ) ;
if ( F_13 ( V_12 -> V_22 ) )
return & V_35 ;
V_17 = F_2 ( V_12 -> V_22 ) ;
if ( ! ( V_17 & 0xf ) )
return & V_35 ;
V_6 -> V_37 = 0 ;
V_6 -> V_38 = 4 ;
V_6 -> V_39 = V_40 ;
V_6 -> V_12 = V_12 ;
F_14 ( V_33 , L_1 ) ;
return & V_41 ;
}
static int F_15 ( struct V_30 * V_31 )
{
int V_42 ;
struct V_5 * V_6 ;
V_6 = F_16 ( V_31 ) ;
if ( F_13 ( V_6 ) )
return F_17 ( V_6 ) ;
V_42 = F_18 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_19 ( V_31 , V_6 ,
F_9 ( V_31 , V_6 ) ,
& V_43 ) ;
if ( V_42 )
goto V_44;
return 0 ;
V_44:
F_20 ( V_6 ) ;
return V_42 ;
}
