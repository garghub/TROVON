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
F_6 ( V_5 , V_23 , L_1 ) ;
}
return 0 ;
}
static void F_7 ( struct V_24 * V_25 )
{
V_25 -> V_26 = V_25 -> V_27 + ( V_28 << 2 ) ;
V_25 -> V_29 = V_25 -> V_27 + ( V_30 << 2 ) ;
V_25 -> V_31 = V_25 -> V_27 + ( V_32 << 2 ) ;
V_25 -> V_33 = V_25 -> V_27 + ( V_34 << 2 ) ;
V_25 -> V_35 = V_25 -> V_27 + ( V_36 << 2 ) ;
V_25 -> V_37 = V_25 -> V_27 + ( V_38 << 2 ) ;
V_25 -> V_39 = V_25 -> V_27 + ( V_40 << 2 ) ;
V_25 -> V_41 = V_25 -> V_27 + ( V_42 << 2 ) ;
V_25 -> V_43 = V_25 -> V_27 + ( V_44 << 2 ) ;
V_25 -> V_45 = V_25 -> V_27 + ( V_46 << 2 ) ;
}
static int T_2 F_8 ( struct V_47 * V_48 )
{
struct V_49 * V_10 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_50 = 0 ;
struct V_51 * V_52 ;
V_52 = F_9 ( V_48 , V_53 , 0 ) ;
if ( V_52 == NULL )
return - V_54 ;
V_50 = F_10 ( V_48 , 0 ) ;
if ( V_50 <= 0 )
return - V_54 ;
V_9 = F_11 ( & V_48 -> V_5 ,
sizeof( struct V_8 ) , V_55 ) ;
if ( ! V_9 )
return - V_56 ;
V_9 -> V_57 = F_12 ( & V_48 -> V_5 , NULL ) ;
if ( F_13 ( V_9 -> V_57 ) ) {
F_14 ( & V_48 -> V_5 , L_2 ) ;
return F_15 ( V_9 -> V_57 ) ;
}
F_16 ( V_9 -> V_57 ) ;
V_10 = F_17 ( & V_48 -> V_5 , 1 ) ;
if ( ! V_10 )
goto V_58;
V_10 -> V_11 = V_9 ;
V_7 = V_10 -> V_59 [ 0 ] ;
V_7 -> V_60 = & V_61 ;
V_7 -> V_62 = V_63 ;
V_7 -> V_18 |= V_64 ;
V_9 -> V_20 = F_18 ( & V_48 -> V_5 , V_52 -> V_65 ,
F_19 ( V_52 ) ) ;
if ( ! V_9 -> V_20 ) {
F_14 ( & V_48 -> V_5 , L_3 ) ;
goto V_58;
}
V_7 -> V_25 . V_27 = V_9 -> V_20 + V_66 ;
V_7 -> V_25 . V_67 = V_9 -> V_20 + V_68 ;
V_7 -> V_25 . V_69 = V_7 -> V_25 . V_67 ;
F_7 ( & V_7 -> V_25 ) ;
F_20 ( V_7 , L_4 ,
( unsigned long long ) V_52 -> V_65 + V_66 ,
( unsigned long long ) V_52 -> V_65 + V_68 ) ;
F_5 ( V_70 |
V_71 ,
V_9 -> V_20 + V_21 ) ;
F_5 ( V_72 ,
V_9 -> V_20 + V_73 ) ;
return F_21 ( V_10 , V_50 , V_74 , 0 ,
& V_75 ) ;
V_58:
F_22 ( V_9 -> V_57 ) ;
F_23 ( V_9 -> V_57 ) ;
return - V_56 ;
}
static int T_3 F_24 ( struct V_47 * V_48 )
{
struct V_49 * V_10 = F_25 ( & V_48 -> V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
F_26 ( V_10 ) ;
F_5 ( 0 , V_9 -> V_20 + V_73 ) ;
F_22 ( V_9 -> V_57 ) ;
F_23 ( V_9 -> V_57 ) ;
return 0 ;
}
static int F_27 ( struct V_76 * V_5 )
{
struct V_49 * V_10 = F_25 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
int V_77 ;
V_77 = F_28 ( V_10 , V_78 ) ;
if ( ! V_77 ) {
F_5 ( 0 , V_9 -> V_20 + V_73 ) ;
V_9 -> V_79 =
F_3 ( V_9 -> V_20 + V_21 ) ;
F_22 ( V_9 -> V_57 ) ;
}
return V_77 ;
}
static int F_29 ( struct V_76 * V_5 )
{
struct V_49 * V_10 = F_25 ( V_5 ) ;
struct V_8 * V_9 = V_10 -> V_11 ;
F_16 ( V_9 -> V_57 ) ;
F_5 ( V_9 -> V_79 , V_9 -> V_20 + V_21 ) ;
F_5 ( V_72 ,
V_9 -> V_20 + V_73 ) ;
F_30 ( V_10 ) ;
return 0 ;
}
static int T_4 F_31 ( void )
{
return F_32 ( & V_80 ) ;
}
static void T_5 F_33 ( void )
{
F_34 ( & V_80 ) ;
}
