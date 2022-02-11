static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 V_6 ;
unsigned long V_7 ;
T_1 V_8 , V_9 ;
V_7 = F_2 ( V_4 -> V_10 ) ;
if ( V_2 -> V_11 < V_12 || V_2 -> V_11 > V_13 ||
! V_7 )
return;
V_8 = 1000000000 / V_7 ;
F_3 ( V_2 , V_2 -> V_11 , & V_6 , V_8 * 1000 , 0 ) ;
V_9 = V_2 -> V_11 - V_12 ;
F_4 ( 3 , V_4 -> V_14 + V_15 ) ;
F_4 ( 3 , V_4 -> V_14 + V_16 ) ;
F_4 ( V_6 . V_17 , V_4 -> V_14 + V_18 ) ;
F_4 ( V_6 . V_19 , V_4 -> V_14 + V_20 ) ;
F_4 ( V_6 . V_19 , V_4 -> V_14 + V_21 ) ;
F_4 ( 1 , V_4 -> V_14 + V_22 ) ;
F_4 ( V_23 [ V_9 ] / V_8 + 1 , V_4 -> V_14 + V_24 ) ;
F_4 ( V_25 [ V_9 ] / V_8 + 1 , V_4 -> V_14 + V_26 ) ;
F_4 ( V_27 [ V_9 ] / V_8 + 1 , V_4 -> V_14 + V_28 ) ;
}
static void F_5 ( struct V_29 * V_30 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_30 -> V_31 -> V_32 ;
T_1 V_33 ;
F_1 ( V_2 , V_4 ) ;
V_33 = F_6 ( V_4 -> V_14 + V_34 ) ;
if ( F_7 ( V_2 ) )
V_33 |= V_35 ;
else
V_33 &= ~ V_35 ;
F_8 ( V_33 , V_4 -> V_14 + V_34 ) ;
}
static void F_9 ( struct V_36 * V_37 )
{
V_37 -> V_38 = V_37 -> V_39 + ( V_40 << 2 ) ;
V_37 -> V_41 = V_37 -> V_39 + ( V_42 << 2 ) ;
V_37 -> V_43 = V_37 -> V_39 + ( V_44 << 2 ) ;
V_37 -> V_45 = V_37 -> V_39 + ( V_46 << 2 ) ;
V_37 -> V_47 = V_37 -> V_39 + ( V_48 << 2 ) ;
V_37 -> V_49 = V_37 -> V_39 + ( V_50 << 2 ) ;
V_37 -> V_51 = V_37 -> V_39 + ( V_52 << 2 ) ;
V_37 -> V_53 = V_37 -> V_39 + ( V_54 << 2 ) ;
V_37 -> V_55 = V_37 -> V_39 + ( V_56 << 2 ) ;
V_37 -> V_57 = V_37 -> V_39 + ( V_58 << 2 ) ;
}
static int F_10 ( struct V_59 * V_60 )
{
struct V_61 * V_31 ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
int V_62 = 0 ;
struct V_63 * V_64 ;
int V_65 ;
V_62 = F_11 ( V_60 , 0 ) ;
if ( V_62 < 0 )
return V_62 ;
V_4 = F_12 ( & V_60 -> V_66 ,
sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_4 )
return - V_68 ;
V_4 -> V_10 = F_13 ( & V_60 -> V_66 , NULL ) ;
if ( F_14 ( V_4 -> V_10 ) ) {
F_15 ( & V_60 -> V_66 , L_1 ) ;
return F_16 ( V_4 -> V_10 ) ;
}
V_65 = F_17 ( V_4 -> V_10 ) ;
if ( V_65 )
return V_65 ;
V_31 = F_18 ( & V_60 -> V_66 , 1 ) ;
if ( ! V_31 ) {
V_65 = - V_68 ;
goto V_69;
}
V_31 -> V_32 = V_4 ;
V_30 = V_31 -> V_70 [ 0 ] ;
V_30 -> V_71 = & V_72 ;
V_30 -> V_73 = V_74 ;
V_30 -> V_75 |= V_76 ;
V_64 = F_19 ( V_60 , V_77 , 0 ) ;
V_4 -> V_14 = F_20 ( & V_60 -> V_66 , V_64 ) ;
if ( F_14 ( V_4 -> V_14 ) ) {
V_65 = F_16 ( V_4 -> V_14 ) ;
goto V_69;
}
V_30 -> V_37 . V_39 = V_4 -> V_14 + V_78 ;
V_30 -> V_37 . V_79 = V_4 -> V_14 + V_80 ;
V_30 -> V_37 . V_81 = V_30 -> V_37 . V_79 ;
F_9 ( & V_30 -> V_37 ) ;
F_21 ( V_30 , L_2 ,
( unsigned long long ) V_64 -> V_82 + V_78 ,
( unsigned long long ) V_64 -> V_82 + V_80 ) ;
F_8 ( V_83 |
V_84 ,
V_4 -> V_14 + V_34 ) ;
F_8 ( V_85 ,
V_4 -> V_14 + V_86 ) ;
V_65 = F_22 ( V_31 , V_62 , V_87 , 0 ,
& V_88 ) ;
if ( V_65 )
goto V_69;
return 0 ;
V_69:
F_23 ( V_4 -> V_10 ) ;
return V_65 ;
}
static int F_24 ( struct V_59 * V_60 )
{
struct V_61 * V_31 = F_25 ( V_60 ) ;
struct V_3 * V_4 = V_31 -> V_32 ;
F_26 ( V_31 ) ;
F_8 ( 0 , V_4 -> V_14 + V_86 ) ;
F_23 ( V_4 -> V_10 ) ;
return 0 ;
}
static int F_27 ( struct V_89 * V_66 )
{
struct V_61 * V_31 = F_28 ( V_66 ) ;
struct V_3 * V_4 = V_31 -> V_32 ;
int V_65 ;
V_65 = F_29 ( V_31 , V_90 ) ;
if ( ! V_65 ) {
F_8 ( 0 , V_4 -> V_14 + V_86 ) ;
V_4 -> V_91 =
F_6 ( V_4 -> V_14 + V_34 ) ;
F_23 ( V_4 -> V_10 ) ;
}
return V_65 ;
}
static int F_30 ( struct V_89 * V_66 )
{
struct V_61 * V_31 = F_28 ( V_66 ) ;
struct V_3 * V_4 = V_31 -> V_32 ;
int V_65 = F_17 ( V_4 -> V_10 ) ;
if ( V_65 )
return V_65 ;
F_8 ( V_4 -> V_91 , V_4 -> V_14 + V_34 ) ;
F_8 ( V_85 ,
V_4 -> V_14 + V_86 ) ;
F_31 ( V_31 ) ;
return 0 ;
}
