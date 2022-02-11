static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
T_1 V_12 ;
F_2 (dev, link, ENABLED) {
V_5 -> V_13 = V_5 -> V_14 = V_15 ;
V_5 -> V_16 = V_17 ;
V_5 -> V_18 |= V_19 ;
V_12 = F_3 ( V_9 -> V_20 + V_21 ) ;
if ( F_4 ( V_5 ) )
V_12 |= V_22 ;
else
V_12 &= ~ V_22 ;
F_5 ( V_12 , V_9 -> V_20 + V_21 ) ;
F_6 ( V_5 , L_1 ) ;
}
return 0 ;
}
static void F_7 ( struct V_23 * V_24 )
{
V_24 -> V_25 = V_24 -> V_26 + ( V_27 << 2 ) ;
V_24 -> V_28 = V_24 -> V_26 + ( V_29 << 2 ) ;
V_24 -> V_30 = V_24 -> V_26 + ( V_31 << 2 ) ;
V_24 -> V_32 = V_24 -> V_26 + ( V_33 << 2 ) ;
V_24 -> V_34 = V_24 -> V_26 + ( V_35 << 2 ) ;
V_24 -> V_36 = V_24 -> V_26 + ( V_37 << 2 ) ;
V_24 -> V_38 = V_24 -> V_26 + ( V_39 << 2 ) ;
V_24 -> V_40 = V_24 -> V_26 + ( V_41 << 2 ) ;
V_24 -> V_42 = V_24 -> V_26 + ( V_43 << 2 ) ;
V_24 -> V_44 = V_24 -> V_26 + ( V_45 << 2 ) ;
}
static int F_8 ( struct V_46 * V_47 )
{
struct V_48 * V_10 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_49 = 0 ;
struct V_50 * V_51 ;
V_51 = F_9 ( V_47 , V_52 , 0 ) ;
if ( V_51 == NULL )
return - V_53 ;
V_49 = F_10 ( V_47 , 0 ) ;
if ( V_49 <= 0 )
return - V_53 ;
V_9 = F_11 ( & V_47 -> V_5 ,
sizeof( struct V_8 ) , V_54 ) ;
if ( ! V_9 )
return - V_55 ;
V_9 -> V_56 = F_12 ( & V_47 -> V_5 , NULL ) ;
if ( F_13 ( V_9 -> V_56 ) ) {
F_14 ( & V_47 -> V_5 , L_2 ) ;
return F_15 ( V_9 -> V_56 ) ;
}
F_16 ( V_9 -> V_56 ) ;
V_10 = F_17 ( & V_47 -> V_5 , 1 ) ;
if ( ! V_10 )
goto V_57;
V_10 -> V_11 = V_9 ;
V_7 = V_10 -> V_58 [ 0 ] ;
V_7 -> V_59 = & V_60 ;
V_7 -> V_61 = V_62 ;
V_7 -> V_18 |= V_63 ;
V_9 -> V_20 = F_18 ( & V_47 -> V_5 , V_51 -> V_64 ,
F_19 ( V_51 ) ) ;
if ( ! V_9 -> V_20 ) {
F_14 ( & V_47 -> V_5 , L_3 ) ;
goto V_57;
}
V_7 -> V_24 . V_26 = V_9 -> V_20 + V_65 ;
V_7 -> V_24 . V_66 = V_9 -> V_20 + V_67 ;
V_7 -> V_24 . V_68 = V_7 -> V_24 . V_66 ;
F_7 ( & V_7 -> V_24 ) ;
F_20 ( V_7 , L_4 ,
( unsigned long long ) V_51 -> V_64 + V_65 ,
( unsigned long long ) V_51 -> V_64 + V_67 ) ;
F_5 ( V_69 |
V_70 ,
V_9 -> V_20 + V_21 ) ;
F_5 ( V_71 ,
V_9 -> V_20 + V_72 ) ;
return F_21 ( V_10 , V_49 , V_73 , 0 ,
& V_74 ) ;
V_57:
F_22 ( V_9 -> V_56 ) ;
F_23 ( V_9 -> V_56 ) ;
return - V_55 ;
}
static int F_24 ( struct V_46 * V_47 )
{
struct V_48 * V_10 = F_25 ( & V_47 -> V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
F_26 ( V_10 ) ;
F_5 ( 0 , V_9 -> V_20 + V_72 ) ;
F_22 ( V_9 -> V_56 ) ;
F_23 ( V_9 -> V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_75 * V_5 )
{
struct V_48 * V_10 = F_25 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
int V_76 ;
V_76 = F_28 ( V_10 , V_77 ) ;
if ( ! V_76 ) {
F_5 ( 0 , V_9 -> V_20 + V_72 ) ;
V_9 -> V_78 =
F_3 ( V_9 -> V_20 + V_21 ) ;
F_22 ( V_9 -> V_56 ) ;
}
return V_76 ;
}
static int F_29 ( struct V_75 * V_5 )
{
struct V_48 * V_10 = F_25 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
F_16 ( V_9 -> V_56 ) ;
F_5 ( V_9 -> V_78 , V_9 -> V_20 + V_21 ) ;
F_5 ( V_71 ,
V_9 -> V_20 + V_72 ) ;
F_30 ( V_10 ) ;
return 0 ;
}
