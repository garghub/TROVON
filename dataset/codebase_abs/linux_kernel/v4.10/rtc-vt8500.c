static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
T_2 V_4 ;
unsigned long V_5 = 0 ;
F_2 ( & V_3 -> V_6 ) ;
V_4 = F_3 ( V_3 -> V_7 + V_8 ) ;
F_4 ( V_4 , V_3 -> V_7 + V_8 ) ;
F_5 ( & V_3 -> V_6 ) ;
if ( V_4 & V_9 )
V_5 |= V_10 | V_11 ;
F_6 ( V_3 -> V_12 , 1 , V_5 ) ;
return V_13 ;
}
static int F_7 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_3 * V_3 = F_8 ( V_15 ) ;
T_2 V_18 , time ;
V_18 = F_3 ( V_3 -> V_7 + V_19 ) ;
time = F_3 ( V_3 -> V_7 + V_20 ) ;
V_17 -> V_21 = F_9 ( time & V_22 ) ;
V_17 -> V_23 = F_9 ( ( time & V_24 ) >> V_25 ) ;
V_17 -> V_26 = F_9 ( ( time & V_27 ) >> V_28 ) ;
V_17 -> V_29 = F_9 ( V_18 & V_30 ) ;
V_17 -> V_31 = F_9 ( ( V_18 & V_32 ) >> V_33 ) - 1 ;
V_17 -> V_34 = F_9 ( ( V_18 & V_35 ) >> V_36 )
+ ( ( V_18 >> V_37 ) & 1 ? 200 : 100 ) ;
V_17 -> V_38 = ( time & V_39 ) >> V_40 ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_3 * V_3 = F_8 ( V_15 ) ;
if ( V_17 -> V_34 < 100 ) {
F_11 ( V_15 , L_1
L_2 ) ;
return - V_41 ;
}
F_4 ( ( F_12 ( V_17 -> V_34 % 100 ) << V_36 )
| ( F_12 ( V_17 -> V_31 + 1 ) << V_33 )
| ( F_12 ( V_17 -> V_29 ) )
| ( ( V_17 -> V_34 >= 200 ) << V_37 ) ,
V_3 -> V_7 + V_42 ) ;
F_4 ( ( F_12 ( V_17 -> V_38 ) << V_40 )
| ( F_12 ( V_17 -> V_26 ) << V_28 )
| ( F_12 ( V_17 -> V_23 ) << V_25 )
| ( F_12 ( V_17 -> V_21 ) ) ,
V_3 -> V_7 + V_43 ) ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 , struct V_44 * V_45 )
{
struct V_3 * V_3 = F_8 ( V_15 ) ;
T_2 V_4 , V_46 ;
V_46 = F_3 ( V_3 -> V_7 + V_47 ) ;
V_4 = F_3 ( V_3 -> V_7 + V_8 ) ;
V_45 -> time . V_29 = F_9 ( ( V_46 & V_48 ) >> V_49 ) ;
V_45 -> time . V_26 = F_9 ( ( V_46 & V_27 ) >> V_28 ) ;
V_45 -> time . V_23 = F_9 ( ( V_46 & V_24 ) >> V_25 ) ;
V_45 -> time . V_21 = F_9 ( ( V_46 & V_22 ) ) ;
V_45 -> V_50 = ( V_46 & V_51 ) ? 1 : 0 ;
V_45 -> V_52 = ( V_4 & V_9 ) ? 1 : 0 ;
return F_14 ( & V_45 -> time ) ;
}
static int F_15 ( struct V_14 * V_15 , struct V_44 * V_45 )
{
struct V_3 * V_3 = F_8 ( V_15 ) ;
F_4 ( ( V_45 -> V_50 ? V_51 : 0 )
| ( F_12 ( V_45 -> time . V_29 ) << V_49 )
| ( F_12 ( V_45 -> time . V_26 ) << V_28 )
| ( F_12 ( V_45 -> time . V_23 ) << V_25 )
| ( F_12 ( V_45 -> time . V_21 ) ) ,
V_3 -> V_7 + V_47 ) ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 , unsigned int V_50 )
{
struct V_3 * V_3 = F_8 ( V_15 ) ;
unsigned long V_53 = F_3 ( V_3 -> V_7 + V_47 ) ;
if ( V_50 )
V_53 |= V_51 ;
else
V_53 &= ~ V_51 ;
F_4 ( V_53 , V_3 -> V_7 + V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_54 * V_55 )
{
struct V_3 * V_3 ;
struct V_56 * V_57 ;
int V_58 ;
V_3 = F_18 ( & V_55 -> V_15 ,
sizeof( struct V_3 ) , V_59 ) ;
if ( ! V_3 )
return - V_60 ;
F_19 ( & V_3 -> V_6 ) ;
F_20 ( V_55 , V_3 ) ;
V_3 -> V_61 = F_21 ( V_55 , 0 ) ;
if ( V_3 -> V_61 < 0 ) {
F_22 ( & V_55 -> V_15 , L_3 ) ;
return V_3 -> V_61 ;
}
V_57 = F_23 ( V_55 , V_62 , 0 ) ;
V_3 -> V_7 = F_24 ( & V_55 -> V_15 , V_57 ) ;
if ( F_25 ( V_3 -> V_7 ) )
return F_26 ( V_3 -> V_7 ) ;
F_4 ( V_63 ,
V_3 -> V_7 + V_64 ) ;
V_3 -> V_12 = F_27 ( & V_55 -> V_15 , L_4 ,
& V_65 , V_66 ) ;
if ( F_25 ( V_3 -> V_12 ) ) {
V_58 = F_26 ( V_3 -> V_12 ) ;
F_22 ( & V_55 -> V_15 ,
L_5 , V_58 ) ;
goto V_67;
}
V_58 = F_28 ( & V_55 -> V_15 , V_3 -> V_61 ,
F_1 , 0 , L_6 , V_3 ) ;
if ( V_58 < 0 ) {
F_22 ( & V_55 -> V_15 , L_7 ,
V_3 -> V_61 , V_58 ) ;
goto V_67;
}
return 0 ;
V_67:
return V_58 ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_3 * V_3 = F_30 ( V_55 ) ;
F_4 ( 0 , V_3 -> V_7 + V_8 ) ;
return 0 ;
}
