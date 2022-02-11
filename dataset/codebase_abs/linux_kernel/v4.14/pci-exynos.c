static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 ;
V_4 -> V_11 = F_2 ( V_8 , sizeof( * V_4 -> V_11 ) , V_12 ) ;
if ( ! V_4 -> V_11 )
return - V_13 ;
V_10 = F_3 ( V_2 , V_14 , 0 ) ;
V_4 -> V_11 -> V_15 = F_4 ( V_8 , V_10 ) ;
if ( F_5 ( V_4 -> V_11 -> V_15 ) )
return F_6 ( V_4 -> V_11 -> V_15 ) ;
if ( V_4 -> V_16 )
return 0 ;
V_10 = F_3 ( V_2 , V_14 , 1 ) ;
V_4 -> V_11 -> V_17 = F_4 ( V_8 , V_10 ) ;
if ( F_5 ( V_4 -> V_11 -> V_17 ) )
return F_6 ( V_4 -> V_11 -> V_17 ) ;
V_10 = F_3 ( V_2 , V_14 , 2 ) ;
V_4 -> V_11 -> V_18 = F_4 ( V_8 , V_10 ) ;
if ( F_5 ( V_4 -> V_11 -> V_18 ) )
return F_6 ( V_4 -> V_11 -> V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_4 -> V_19 = F_2 ( V_8 , sizeof( * V_4 -> V_19 ) , V_12 ) ;
if ( ! V_4 -> V_19 )
return - V_13 ;
V_4 -> V_19 -> V_20 = F_8 ( V_8 , L_1 ) ;
if ( F_5 ( V_4 -> V_19 -> V_20 ) ) {
F_9 ( V_8 , L_2 ) ;
return F_6 ( V_4 -> V_19 -> V_20 ) ;
}
V_4 -> V_19 -> V_21 = F_8 ( V_8 , L_3 ) ;
if ( F_5 ( V_4 -> V_19 -> V_21 ) ) {
F_9 ( V_8 , L_4 ) ;
return F_6 ( V_4 -> V_19 -> V_21 ) ;
}
return 0 ;
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_22 ;
V_22 = F_11 ( V_4 -> V_19 -> V_20 ) ;
if ( V_22 ) {
F_9 ( V_8 , L_5 ) ;
return V_22 ;
}
V_22 = F_11 ( V_4 -> V_19 -> V_21 ) ;
if ( V_22 ) {
F_9 ( V_8 , L_6 ) ;
goto V_23;
}
return 0 ;
V_23:
F_12 ( V_4 -> V_19 -> V_20 ) ;
return V_22 ;
}
static void F_13 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_19 -> V_21 ) ;
F_12 ( V_4 -> V_19 -> V_20 ) ;
}
static void F_14 ( void T_1 * V_24 , T_2 V_25 , T_2 V_26 )
{
F_15 ( V_25 , V_24 + V_26 ) ;
}
static T_2 F_16 ( void T_1 * V_24 , T_2 V_26 )
{
return F_17 ( V_24 + V_26 ) ;
}
static void F_18 ( struct V_3 * V_4 , bool V_27 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_28 ) ;
if ( V_27 )
V_25 |= V_29 ;
else
V_25 &= ~ V_29 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_28 ) ;
}
static void F_19 ( struct V_3 * V_4 , bool V_27 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_30 ) ;
if ( V_27 )
V_25 |= V_29 ;
else
V_25 &= ~ V_29 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_30 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_31 ) ;
V_25 &= ~ V_32 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_31 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 0 , V_33 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 0 , V_34 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 0 , V_35 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_31 ) ;
V_25 |= V_32 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_31 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 1 , V_34 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 1 , V_35 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 1 , V_36 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 0 , V_36 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 1 , V_37 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_37 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 1 , V_38 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_38 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 1 , V_33 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_39 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_40 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_41 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_42 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_43 ) ;
V_25 &= ~ V_44 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_43 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_45 ) ;
V_25 &= ~ V_46 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_45 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_47 ) ;
V_25 &= ~ V_48 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_47 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_49 ) ;
V_25 &= ~ V_50 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_49 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_51 ) ;
V_25 &= ~ V_52 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_51 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_43 ) ;
V_25 |= V_44 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_43 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_45 ) ;
V_25 |= V_46 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_45 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_47 ) ;
V_25 |= V_48 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_47 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_49 ) ;
V_25 |= V_50 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_49 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_17 , V_51 ) ;
V_25 |= V_52 ;
F_14 ( V_4 -> V_11 -> V_17 , V_25 , V_51 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
F_14 ( V_4 -> V_11 -> V_17 , 0x29 , V_53 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0xd5 , V_54 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x14 , V_55 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x12 , V_56 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x7f , V_57 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x0 , V_58 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0xe7 , V_59 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x82 , V_60 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x82 , V_61 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x82 , V_62 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x82 , V_63 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x39 , V_58 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x39 , V_64 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x39 , V_65 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x39 , V_66 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0x20 , V_67 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0xa0 , V_68 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0xa0 , V_69 ) ;
F_14 ( V_4 -> V_11 -> V_17 , 0xa0 , V_70 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_4 -> V_71 >= 0 )
F_28 ( V_8 , V_4 -> V_71 ,
V_72 , L_7 ) ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_73 * V_74 = & V_6 -> V_74 ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_25 ;
if ( F_30 ( V_6 ) ) {
F_9 ( V_8 , L_8 ) ;
return 0 ;
}
F_20 ( V_4 ) ;
if ( V_4 -> V_16 ) {
F_31 ( V_4 -> V_75 ) ;
F_14 ( V_4 -> V_11 -> V_15 , 1 ,
V_33 ) ;
F_32 ( V_4 -> V_75 ) ;
F_33 ( V_4 -> V_75 ) ;
} else {
F_22 ( V_4 ) ;
F_23 ( V_4 ) ;
F_24 ( V_4 ) ;
F_26 ( V_4 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 1 ,
V_39 ) ;
F_34 ( 500 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 ,
V_39 ) ;
}
F_14 ( V_4 -> V_11 -> V_18 , 1 , V_39 ) ;
F_34 ( 500 ) ;
F_14 ( V_4 -> V_11 -> V_18 , 0 , V_39 ) ;
F_21 ( V_4 ) ;
F_35 ( V_74 ) ;
F_27 ( V_4 ) ;
F_14 ( V_4 -> V_11 -> V_15 , V_76 ,
V_77 ) ;
if ( ! F_36 ( V_6 ) )
return 0 ;
if ( V_4 -> V_16 ) {
F_37 ( V_4 -> V_75 ) ;
return - V_78 ;
}
while ( F_16 ( V_4 -> V_11 -> V_17 ,
V_79 ) == 0 ) {
V_25 = F_16 ( V_4 -> V_11 -> V_18 ,
V_79 ) ;
F_38 ( V_8 , L_9 , V_25 ) ;
}
F_25 ( V_4 ) ;
return - V_78 ;
}
static void F_39 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_80 ) ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_80 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
T_2 V_25 ;
V_25 = V_81 | V_82 |
V_83 | V_84 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_85 ) ;
}
static T_3 F_41 ( int V_86 , void * V_87 )
{
struct V_3 * V_4 = V_87 ;
F_39 ( V_4 ) ;
return V_88 ;
}
static T_3 F_42 ( int V_86 , void * V_87 )
{
struct V_3 * V_4 = V_87 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_73 * V_74 = & V_6 -> V_74 ;
return F_43 ( V_74 ) ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_73 * V_74 = & V_6 -> V_74 ;
T_2 V_25 ;
F_45 ( V_74 ) ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_89 ) ;
V_25 |= V_90 ;
F_14 ( V_4 -> V_11 -> V_15 , V_25 , V_89 ) ;
}
static void F_46 ( struct V_3 * V_4 )
{
F_40 ( V_4 ) ;
if ( F_47 ( V_91 ) )
F_44 ( V_4 ) ;
}
static T_2 F_48 ( struct V_5 * V_6 , void T_1 * V_24 ,
T_2 V_26 , T_4 V_92 )
{
struct V_3 * V_4 = F_49 ( V_6 ) ;
T_2 V_25 ;
F_19 ( V_4 , true ) ;
F_50 ( V_24 + V_26 , V_92 , & V_25 ) ;
F_19 ( V_4 , false ) ;
return V_25 ;
}
static void F_51 ( struct V_5 * V_6 , void T_1 * V_24 ,
T_2 V_26 , T_4 V_92 , T_2 V_25 )
{
struct V_3 * V_4 = F_49 ( V_6 ) ;
F_18 ( V_4 , true ) ;
F_52 ( V_24 + V_26 , V_92 , V_25 ) ;
F_18 ( V_4 , false ) ;
}
static int F_53 ( struct V_73 * V_74 , int V_93 , int V_92 ,
T_2 * V_25 )
{
struct V_5 * V_6 = F_54 ( V_74 ) ;
struct V_3 * V_4 = F_49 ( V_6 ) ;
int V_22 ;
F_19 ( V_4 , true ) ;
V_22 = F_50 ( V_6 -> V_94 + V_93 , V_92 , V_25 ) ;
F_19 ( V_4 , false ) ;
return V_22 ;
}
static int F_55 ( struct V_73 * V_74 , int V_93 , int V_92 ,
T_2 V_25 )
{
struct V_5 * V_6 = F_54 ( V_74 ) ;
struct V_3 * V_4 = F_49 ( V_6 ) ;
int V_22 ;
F_18 ( V_4 , true ) ;
V_22 = F_52 ( V_6 -> V_94 + V_93 , V_92 , V_25 ) ;
F_18 ( V_4 , false ) ;
return V_22 ;
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_49 ( V_6 ) ;
T_2 V_25 ;
V_25 = F_16 ( V_4 -> V_11 -> V_15 , V_95 ) ;
if ( V_25 == V_76 )
return 1 ;
return 0 ;
}
static int F_57 ( struct V_73 * V_74 )
{
struct V_5 * V_6 = F_54 ( V_74 ) ;
struct V_3 * V_4 = F_49 ( V_6 ) ;
F_29 ( V_4 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static int T_5 F_58 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_73 * V_74 = & V_6 -> V_74 ;
struct V_7 * V_8 = & V_2 -> V_8 ;
int V_22 ;
V_74 -> V_86 = F_59 ( V_2 , 1 ) ;
if ( V_74 -> V_86 < 0 ) {
F_9 ( V_8 , L_10 ) ;
return V_74 -> V_86 ;
}
V_22 = F_60 ( V_8 , V_74 -> V_86 , F_41 ,
V_96 , L_11 , V_4 ) ;
if ( V_22 ) {
F_9 ( V_8 , L_12 ) ;
return V_22 ;
}
if ( F_47 ( V_91 ) ) {
V_74 -> V_97 = F_59 ( V_2 , 0 ) ;
if ( V_74 -> V_97 < 0 ) {
F_9 ( V_8 , L_13 ) ;
return V_74 -> V_97 ;
}
V_22 = F_60 ( V_8 , V_74 -> V_97 ,
F_42 ,
V_96 | V_98 ,
L_11 , V_4 ) ;
if ( V_22 ) {
F_9 ( V_8 , L_14 ) ;
return V_22 ;
}
}
V_74 -> V_99 = - 1 ;
V_74 -> V_100 = & V_101 ;
V_22 = F_61 ( V_74 ) ;
if ( V_22 ) {
F_9 ( V_8 , L_15 ) ;
return V_22 ;
}
return 0 ;
}
static int T_5 F_62 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_102 * V_103 = V_8 -> V_104 ;
int V_22 ;
V_4 = F_2 ( V_8 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_6 = F_2 ( V_8 , sizeof( * V_6 ) , V_12 ) ;
if ( ! V_6 )
return - V_13 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_100 = & V_105 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_100 = ( const struct V_106 * )
F_63 ( V_8 ) ;
V_4 -> V_71 = F_64 ( V_103 , L_16 , 0 ) ;
V_4 -> V_16 = false ;
V_4 -> V_75 = F_65 ( V_8 , V_103 , NULL ) ;
if ( F_5 ( V_4 -> V_75 ) ) {
if ( F_6 ( V_4 -> V_75 ) == - V_107 )
return F_6 ( V_4 -> V_75 ) ;
F_66 ( V_8 , L_17 ) ;
} else
V_4 -> V_16 = true ;
if ( V_4 -> V_100 && V_4 -> V_100 -> V_108 ) {
V_22 = V_4 -> V_100 -> V_108 ( V_2 , V_4 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_4 -> V_100 && V_4 -> V_100 -> V_109 ) {
V_22 = V_4 -> V_100 -> V_109 ( V_4 ) ;
if ( V_22 )
return V_22 ;
V_22 = V_4 -> V_100 -> V_110 ( V_4 ) ;
if ( V_22 )
return V_22 ;
}
F_67 ( V_2 , V_4 ) ;
V_22 = F_58 ( V_4 , V_2 ) ;
if ( V_22 < 0 )
goto V_111;
return 0 ;
V_111:
if ( V_4 -> V_16 )
F_68 ( V_4 -> V_75 ) ;
if ( V_4 -> V_100 && V_4 -> V_100 -> V_112 )
V_4 -> V_100 -> V_112 ( V_4 ) ;
return V_22 ;
}
static int T_6 F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_70 ( V_2 ) ;
if ( V_4 -> V_100 && V_4 -> V_100 -> V_112 )
V_4 -> V_100 -> V_112 ( V_4 ) ;
return 0 ;
}
static int T_5 F_71 ( void )
{
return F_72 ( & V_113 , F_62 ) ;
}
