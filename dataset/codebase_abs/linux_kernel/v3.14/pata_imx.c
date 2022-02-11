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
int V_52 ;
V_51 = F_9 ( V_47 , V_53 , 0 ) ;
if ( V_51 == NULL )
return - V_54 ;
V_49 = F_10 ( V_47 , 0 ) ;
if ( V_49 <= 0 )
return - V_54 ;
V_9 = F_11 ( & V_47 -> V_5 ,
sizeof( struct V_8 ) , V_55 ) ;
if ( ! V_9 )
return - V_56 ;
V_9 -> V_57 = F_12 ( & V_47 -> V_5 , NULL ) ;
if ( F_13 ( V_9 -> V_57 ) ) {
F_14 ( & V_47 -> V_5 , L_2 ) ;
return F_15 ( V_9 -> V_57 ) ;
}
V_52 = F_16 ( V_9 -> V_57 ) ;
if ( V_52 )
return V_52 ;
V_10 = F_17 ( & V_47 -> V_5 , 1 ) ;
if ( ! V_10 ) {
V_52 = - V_56 ;
goto V_58;
}
V_10 -> V_11 = V_9 ;
V_7 = V_10 -> V_59 [ 0 ] ;
V_7 -> V_60 = & V_61 ;
V_7 -> V_62 = V_63 ;
V_7 -> V_18 |= V_64 ;
V_9 -> V_20 = F_18 ( & V_47 -> V_5 , V_51 -> V_65 ,
F_19 ( V_51 ) ) ;
if ( ! V_9 -> V_20 ) {
F_14 ( & V_47 -> V_5 , L_3 ) ;
V_52 = - V_66 ;
goto V_58;
}
V_7 -> V_24 . V_26 = V_9 -> V_20 + V_67 ;
V_7 -> V_24 . V_68 = V_9 -> V_20 + V_69 ;
V_7 -> V_24 . V_70 = V_7 -> V_24 . V_68 ;
F_7 ( & V_7 -> V_24 ) ;
F_20 ( V_7 , L_4 ,
( unsigned long long ) V_51 -> V_65 + V_67 ,
( unsigned long long ) V_51 -> V_65 + V_69 ) ;
F_5 ( V_71 |
V_72 ,
V_9 -> V_20 + V_21 ) ;
F_5 ( V_73 ,
V_9 -> V_20 + V_74 ) ;
V_52 = F_21 ( V_10 , V_49 , V_75 , 0 ,
& V_76 ) ;
if ( V_52 )
goto V_58;
return 0 ;
V_58:
F_22 ( V_9 -> V_57 ) ;
return V_52 ;
}
static int F_23 ( struct V_46 * V_47 )
{
struct V_48 * V_10 = F_24 ( V_47 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
F_25 ( V_10 ) ;
F_5 ( 0 , V_9 -> V_20 + V_74 ) ;
F_22 ( V_9 -> V_57 ) ;
return 0 ;
}
static int F_26 ( struct V_77 * V_5 )
{
struct V_48 * V_10 = F_27 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
int V_52 ;
V_52 = F_28 ( V_10 , V_78 ) ;
if ( ! V_52 ) {
F_5 ( 0 , V_9 -> V_20 + V_74 ) ;
V_9 -> V_79 =
F_3 ( V_9 -> V_20 + V_21 ) ;
F_22 ( V_9 -> V_57 ) ;
}
return V_52 ;
}
static int F_29 ( struct V_77 * V_5 )
{
struct V_48 * V_10 = F_27 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
int V_52 = F_16 ( V_9 -> V_57 ) ;
if ( V_52 )
return V_52 ;
F_5 ( V_9 -> V_79 , V_9 -> V_20 + V_21 ) ;
F_5 ( V_73 ,
V_9 -> V_20 + V_74 ) ;
F_30 ( V_10 ) ;
return 0 ;
}
