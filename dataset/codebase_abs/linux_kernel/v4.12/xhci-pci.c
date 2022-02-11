static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 ) )
F_3 ( V_2 , L_1 ) ;
F_3 ( V_2 , L_2 ) ;
return 0 ;
}
static void F_4 ( struct V_5 * V_6 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_6 ) ;
if ( V_4 -> V_7 == V_8 &&
( V_4 -> V_5 == V_9 ||
V_4 -> V_5 == V_10 ) ) {
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x0 ) {
V_2 -> V_12 |= V_13 ;
F_6 ( V_2 , V_14 ,
L_3
L_4 ) ;
}
if ( V_4 -> V_5 == V_9 &&
V_4 -> V_11 == 0x4 ) {
V_2 -> V_12 |= V_15 ;
F_6 ( V_2 , V_14 ,
L_5
L_6 ,
V_4 -> V_11 ) ;
}
if ( V_4 -> V_5 == V_9 )
V_2 -> V_12 |= V_16 ;
V_2 -> V_12 |= V_17 ;
F_6 ( V_2 , V_14 ,
L_7
L_8 ,
V_4 -> V_11 ) ;
V_2 -> V_12 |= V_18 ;
}
if ( V_4 -> V_7 == V_8 &&
V_4 -> V_5 == V_19 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_20 )
V_2 -> V_12 |= V_21 ;
if ( V_4 -> V_7 == V_22 && V_2 -> V_23 == 0x96 )
V_2 -> V_12 |= V_24 ;
if ( V_4 -> V_7 == V_22 && F_7 () )
V_2 -> V_12 |= V_25 ;
if ( V_4 -> V_7 == V_22 )
V_2 -> V_12 |= V_18 ;
if ( V_4 -> V_7 == V_26 ) {
V_2 -> V_12 |= V_27 ;
V_2 -> V_12 |= V_28 ;
V_2 -> V_12 |= V_29 ;
}
if ( V_4 -> V_7 == V_26 &&
V_4 -> V_5 == V_30 ) {
V_2 -> V_12 |= V_31 ;
V_2 -> V_32 = 64 ;
V_2 -> V_12 |= V_33 ;
V_2 -> V_12 |= V_34 ;
}
if ( V_4 -> V_7 == V_26 &&
( V_4 -> V_5 == V_35 ||
V_4 -> V_5 == V_36 ) ) {
V_2 -> V_12 |= V_34 ;
V_2 -> V_12 |= V_37 ;
}
if ( V_4 -> V_7 == V_26 &&
( V_4 -> V_5 == V_38 ||
V_4 -> V_5 == V_39 ||
V_4 -> V_5 == V_40 ||
V_4 -> V_5 == V_41 ||
V_4 -> V_5 == V_42 ||
V_4 -> V_5 == V_43 ||
V_4 -> V_5 == V_44 ) ) {
V_2 -> V_12 |= V_45 ;
}
if ( V_4 -> V_7 == V_26 &&
V_4 -> V_5 == V_40 ) {
V_2 -> V_12 |= V_46 ;
}
if ( V_4 -> V_7 == V_26 &&
( V_4 -> V_5 == V_40 ||
V_4 -> V_5 == V_43 ||
V_4 -> V_5 == V_44 ) )
V_2 -> V_12 |= V_47 ;
if ( V_4 -> V_7 == V_48 &&
V_4 -> V_5 == V_49 ) {
V_2 -> V_12 |= V_50 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_51 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_50 ;
if ( V_4 -> V_7 == V_52 )
V_2 -> V_12 |= V_50 ;
if ( V_4 -> V_7 == V_52 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_53 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_53 &&
V_4 -> V_5 == 0x1142 )
V_2 -> V_12 |= V_18 ;
if ( V_4 -> V_7 == V_54 && V_4 -> V_5 == 0x8241 )
V_2 -> V_12 |= V_55 ;
if ( V_2 -> V_12 & V_50 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_56 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
union V_57 * V_58 ;
V_58 = F_9 ( F_10 ( & V_6 -> V_6 ) , V_56 , 3 , 1 ,
NULL ) ;
F_11 ( V_58 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_12 ( struct V_59 * V_60 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_60 -> V_61 . V_62 ) ;
int V_63 ;
V_2 = F_13 ( V_60 ) ;
if ( ! V_2 -> V_64 )
F_14 ( V_4 , V_65 , & V_2 -> V_64 ) ;
V_63 = F_15 ( V_60 , F_4 ) ;
if ( V_63 )
return V_63 ;
if ( ! F_16 ( V_60 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_64 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_17 ( struct V_3 * V_6 , const struct V_66 * V_67 )
{
int V_63 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
struct V_59 * V_60 ;
V_69 = (struct V_68 * ) V_67 -> V_70 ;
F_18 ( & V_6 -> V_6 ) ;
V_63 = F_19 ( V_6 , V_67 ) ;
if ( V_63 )
goto V_71;
V_60 = F_20 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_60 ) ;
V_2 -> V_72 = F_21 ( V_69 , & V_6 -> V_6 ,
F_22 ( V_6 ) , V_60 ) ;
if ( ! V_2 -> V_72 ) {
V_63 = - V_73 ;
goto V_74;
}
V_63 = F_23 ( V_2 -> V_72 , V_6 -> V_75 ,
V_76 ) ;
if ( V_63 )
goto V_77;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_24 ( V_2 -> V_78 ) >= 4 )
V_2 -> V_72 -> V_79 = 1 ;
if ( V_2 -> V_12 & V_45 )
F_8 ( V_6 ) ;
F_25 ( & V_6 -> V_6 ) ;
return 0 ;
V_77:
F_26 ( V_2 -> V_72 ) ;
V_74:
F_27 ( V_6 ) ;
V_71:
F_25 ( & V_6 -> V_6 ) ;
return V_63 ;
}
static void F_28 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_29 ( V_6 ) ) ;
V_2 -> V_80 |= V_81 ;
if ( V_2 -> V_72 ) {
F_30 ( V_2 -> V_72 ) ;
F_26 ( V_2 -> V_72 ) ;
}
if ( V_2 -> V_12 & V_37 )
F_31 ( V_6 , V_82 ) ;
F_27 ( V_6 ) ;
}
static void F_32 ( struct V_59 * V_60 , bool V_83 )
{
struct V_1 * V_2 = F_13 ( V_60 ) ;
T_2 V_84 ;
void T_3 * V_85 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
V_85 = ( void T_3 * ) V_2 -> V_88 +
V_89 +
V_86 * V_90 ;
V_84 = F_33 ( V_85 ) & ~ V_91 ;
F_34 ( V_84 , V_85 ) ;
V_84 = F_33 ( V_85 ) ;
if ( V_83 )
V_84 |= V_92 ;
else
V_84 &= ~ V_92 ;
F_34 ( V_84 , V_85 ) ;
V_84 = F_33 ( V_85 ) | V_91 ;
F_34 ( V_84 , V_85 ) ;
F_33 ( V_85 ) ;
}
}
static void F_35 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_13 ( V_60 ) ;
void T_3 * V_85 ;
T_2 V_84 ;
V_85 = ( void T_3 * ) V_2 -> V_88 + 0x80a4 ;
V_84 = F_33 ( V_85 ) ;
F_34 ( V_84 | F_36 ( 28 ) , V_85 ) ;
F_33 ( V_85 ) ;
}
static int F_37 ( struct V_59 * V_60 , bool V_93 )
{
struct V_1 * V_2 = F_13 ( V_60 ) ;
struct V_3 * V_4 = F_5 ( V_60 -> V_61 . V_62 ) ;
int V_94 ;
if ( V_2 -> V_12 & V_95 )
F_38 ( V_4 ) ;
if ( V_2 -> V_12 & V_45 )
F_35 ( V_60 ) ;
if ( V_2 -> V_12 & V_46 )
F_32 ( V_60 , true ) ;
V_94 = F_39 ( V_2 , V_93 ) ;
if ( V_94 && ( V_2 -> V_12 & V_46 ) )
F_32 ( V_60 , false ) ;
return V_94 ;
}
static int F_40 ( struct V_59 * V_60 , bool V_96 )
{
struct V_1 * V_2 = F_13 ( V_60 ) ;
struct V_3 * V_4 = F_5 ( V_60 -> V_61 . V_62 ) ;
int V_63 = 0 ;
if ( V_4 -> V_7 == V_26 )
F_41 ( V_4 ) ;
if ( V_2 -> V_12 & V_46 )
F_32 ( V_60 , false ) ;
if ( V_2 -> V_12 & V_45 )
F_35 ( V_60 ) ;
V_63 = F_42 ( V_2 , V_96 ) ;
return V_63 ;
}
static int T_4 F_43 ( void )
{
F_44 ( & V_97 , & V_98 ) ;
#ifdef F_45
V_97 . V_99 = F_37 ;
V_97 . V_100 = F_40 ;
#endif
return F_46 ( & V_101 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_101 ) ;
}
