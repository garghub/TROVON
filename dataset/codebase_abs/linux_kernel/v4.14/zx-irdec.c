static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 -> V_7 + V_3 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 & V_4 ;
F_3 ( V_6 , V_2 -> V_7 + V_3 ) ;
}
static T_2 F_4 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
T_3 V_10 , V_11 ;
T_3 V_12 , V_13 ;
T_1 V_14 , V_15 ;
enum V_16 V_16 ;
F_3 ( 1 , V_2 -> V_7 + V_17 ) ;
if ( F_2 ( V_2 -> V_7 + V_18 ) & V_19 ) {
F_5 ( V_2 -> V_20 ) ;
goto V_21;
}
V_14 = F_2 ( V_2 -> V_7 + V_22 ) ;
V_13 = ( V_14 >> 24 ) & 0xff ;
V_12 = ( V_14 >> 16 ) & 0xff ;
V_11 = ( V_14 >> 8 ) & 0xff ;
V_10 = V_14 & 0xff ;
V_15 = F_6 ( V_10 , V_11 ,
V_12 , V_13 ,
& V_16 ) ;
F_7 ( V_2 -> V_20 , V_16 , V_15 , 0 ) ;
V_21:
return V_23 ;
}
static int F_8 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
struct V_30 * V_20 ;
int V_8 ;
int V_31 ;
V_2 = F_9 ( V_27 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_29 = F_10 ( V_25 , V_34 , 0 ) ;
V_2 -> V_7 = F_11 ( V_27 , V_29 ) ;
if ( F_12 ( V_2 -> V_7 ) )
return F_13 ( V_2 -> V_7 ) ;
V_8 = F_14 ( V_25 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_20 = F_15 ( V_27 , V_35 ) ;
if ( ! V_20 ) {
F_16 ( V_27 , L_1 ) ;
return - V_33 ;
}
V_2 -> V_20 = V_20 ;
V_20 -> V_36 = V_2 ;
V_20 -> V_37 = V_38 L_2 ;
V_20 -> V_39 . V_40 = V_41 ;
V_20 -> V_42 = V_43 ;
V_20 -> V_44 = V_45 | V_46 |
V_47 ;
V_20 -> V_48 = V_38 ;
V_20 -> V_49 = V_38 ;
F_17 ( V_25 , V_2 ) ;
V_31 = F_18 ( V_27 , V_20 ) ;
if ( V_31 ) {
F_16 ( V_27 , L_3 ) ;
return V_31 ;
}
V_31 = F_19 ( V_27 , V_8 , F_4 , 0 , NULL , V_2 ) ;
if ( V_31 ) {
F_16 ( V_27 , L_4 ) ;
return V_31 ;
}
F_1 ( V_2 , V_50 , V_51 , F_20 ( 0 ) ) ;
F_1 ( V_2 , V_50 , V_52 ,
F_21 ( 0x21c ) ) ;
F_3 ( 1 , V_2 -> V_7 + V_53 ) ;
F_1 ( V_2 , V_54 , V_55 , V_55 ) ;
return 0 ;
}
static int F_22 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_23 ( V_25 ) ;
F_1 ( V_2 , V_54 , V_55 , 0 ) ;
F_3 ( 0 , V_2 -> V_7 + V_53 ) ;
return 0 ;
}
