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
if ( ( V_4 -> V_7 == V_22 ) &&
( ( V_4 -> V_5 == V_26 ) ||
( V_4 -> V_5 == V_27 ) ||
( V_4 -> V_5 == V_28 ) ||
( V_4 -> V_5 == V_29 ) ) )
V_2 -> V_12 |= V_30 ;
if ( V_4 -> V_7 == V_31 ) {
V_2 -> V_12 |= V_32 ;
V_2 -> V_12 |= V_33 ;
V_2 -> V_12 |= V_34 ;
}
if ( V_4 -> V_7 == V_31 &&
V_4 -> V_5 == V_35 ) {
V_2 -> V_12 |= V_36 ;
V_2 -> V_37 = 64 ;
V_2 -> V_12 |= V_38 ;
V_2 -> V_12 |= V_39 ;
}
if ( V_4 -> V_7 == V_31 &&
( V_4 -> V_5 == V_40 ||
V_4 -> V_5 == V_41 ) ) {
V_2 -> V_12 |= V_39 ;
V_2 -> V_12 |= V_42 ;
}
if ( V_4 -> V_7 == V_31 &&
( V_4 -> V_5 == V_43 ||
V_4 -> V_5 == V_44 ||
V_4 -> V_5 == V_45 ||
V_4 -> V_5 == V_46 ||
V_4 -> V_5 == V_47 ||
V_4 -> V_5 == V_48 ||
V_4 -> V_5 == V_49 ) ) {
V_2 -> V_12 |= V_50 ;
}
if ( V_4 -> V_7 == V_31 &&
V_4 -> V_5 == V_45 ) {
V_2 -> V_12 |= V_51 ;
}
if ( V_4 -> V_7 == V_31 &&
( V_4 -> V_5 == V_45 ||
V_4 -> V_5 == V_48 ||
V_4 -> V_5 == V_49 ) )
V_2 -> V_12 |= V_52 ;
if ( V_4 -> V_7 == V_53 &&
V_4 -> V_5 == V_54 ) {
V_2 -> V_12 |= V_55 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_56 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_55 ;
if ( V_4 -> V_7 == V_57 )
V_2 -> V_12 |= V_55 ;
if ( V_4 -> V_7 == V_57 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_58 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_58 &&
V_4 -> V_5 == 0x1142 )
V_2 -> V_12 |= V_18 ;
if ( V_4 -> V_7 == V_58 &&
V_4 -> V_5 == V_59 )
V_2 -> V_12 |= V_60 ;
if ( V_4 -> V_7 == V_61 && V_4 -> V_5 == 0x8241 )
V_2 -> V_12 |= V_62 ;
if ( V_2 -> V_12 & V_55 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_63 =
F_9 ( 0xac340cb7 , 0xe901 , 0x45bf ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ) ;
union V_64 * V_65 ;
V_65 = F_10 ( F_11 ( & V_6 -> V_6 ) , & V_63 , 3 , 1 ,
NULL ) ;
F_12 ( V_65 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_13 ( struct V_66 * V_67 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_67 -> V_68 . V_69 ) ;
int V_70 ;
V_2 = F_14 ( V_67 ) ;
if ( ! V_2 -> V_71 )
F_15 ( V_4 , V_72 , & V_2 -> V_71 ) ;
V_70 = F_16 ( V_67 , F_4 ) ;
if ( V_70 )
return V_70 ;
if ( ! F_17 ( V_67 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_71 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_18 ( struct V_3 * V_6 , const struct V_73 * V_74 )
{
int V_70 ;
struct V_1 * V_2 ;
struct V_75 * V_76 ;
struct V_66 * V_67 ;
V_76 = (struct V_75 * ) V_74 -> V_77 ;
if ( F_19 ( V_6 ) ) {
F_20 ( & V_6 -> V_6 , L_11 ) ;
if ( F_21 ( V_6 ) )
F_22 ( & V_6 -> V_6 , L_12 ) ;
}
F_23 ( & V_6 -> V_6 ) ;
V_70 = F_24 ( V_6 , V_74 ) ;
if ( V_70 )
goto V_78;
V_67 = F_25 ( & V_6 -> V_6 ) ;
V_2 = F_14 ( V_67 ) ;
V_2 -> V_79 = F_26 ( V_76 , & V_6 -> V_6 ,
F_27 ( V_6 ) , V_67 ) ;
if ( ! V_2 -> V_79 ) {
V_70 = - V_80 ;
goto V_81;
}
V_70 = F_28 ( V_2 -> V_79 , V_6 -> V_82 ,
V_83 ) ;
if ( V_70 )
goto V_84;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_29 ( V_2 -> V_85 ) >= 4 )
V_2 -> V_79 -> V_86 = 1 ;
if ( V_2 -> V_12 & V_50 )
F_8 ( V_6 ) ;
F_30 ( & V_6 -> V_6 ) ;
return 0 ;
V_84:
F_31 ( V_2 -> V_79 ) ;
V_81:
F_32 ( V_6 ) ;
V_78:
F_30 ( & V_6 -> V_6 ) ;
return V_70 ;
}
static void F_33 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( F_34 ( V_6 ) ) ;
V_2 -> V_87 |= V_88 ;
if ( V_2 -> V_79 ) {
F_35 ( V_2 -> V_79 ) ;
F_31 ( V_2 -> V_79 ) ;
}
if ( V_2 -> V_12 & V_42 )
F_36 ( V_6 , V_89 ) ;
F_32 ( V_6 ) ;
}
static void F_37 ( struct V_66 * V_67 , bool V_90 )
{
struct V_1 * V_2 = F_14 ( V_67 ) ;
T_2 V_91 ;
void T_3 * V_92 ;
int V_93 ;
for ( V_93 = 0 ; V_93 < V_94 ; V_93 ++ ) {
V_92 = ( void T_3 * ) V_2 -> V_95 +
V_96 +
V_93 * V_97 ;
V_91 = F_38 ( V_92 ) & ~ V_98 ;
F_39 ( V_91 , V_92 ) ;
V_91 = F_38 ( V_92 ) ;
if ( V_90 )
V_91 |= V_99 ;
else
V_91 &= ~ V_99 ;
F_39 ( V_91 , V_92 ) ;
V_91 = F_38 ( V_92 ) | V_98 ;
F_39 ( V_91 , V_92 ) ;
F_38 ( V_92 ) ;
}
}
static void F_40 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_14 ( V_67 ) ;
void T_3 * V_92 ;
T_2 V_91 ;
V_92 = ( void T_3 * ) V_2 -> V_95 + 0x80a4 ;
V_91 = F_38 ( V_92 ) ;
F_39 ( V_91 | F_41 ( 28 ) , V_92 ) ;
F_38 ( V_92 ) ;
}
static int F_42 ( struct V_66 * V_67 , bool V_100 )
{
struct V_1 * V_2 = F_14 ( V_67 ) ;
struct V_3 * V_4 = F_5 ( V_67 -> V_68 . V_69 ) ;
int V_101 ;
if ( V_2 -> V_12 & V_102 )
F_43 ( V_4 ) ;
if ( V_2 -> V_12 & V_50 )
F_40 ( V_67 ) ;
if ( V_2 -> V_12 & V_51 )
F_37 ( V_67 , true ) ;
V_101 = F_44 ( V_2 , V_100 ) ;
if ( V_101 && ( V_2 -> V_12 & V_51 ) )
F_37 ( V_67 , false ) ;
return V_101 ;
}
static int F_45 ( struct V_66 * V_67 , bool V_103 )
{
struct V_1 * V_2 = F_14 ( V_67 ) ;
struct V_3 * V_4 = F_5 ( V_67 -> V_68 . V_69 ) ;
int V_70 = 0 ;
if ( V_4 -> V_7 == V_31 )
F_46 ( V_4 ) ;
if ( V_2 -> V_12 & V_51 )
F_37 ( V_67 , false ) ;
if ( V_2 -> V_12 & V_50 )
F_40 ( V_67 ) ;
V_70 = F_47 ( V_2 , V_103 ) ;
return V_70 ;
}
static int T_4 F_48 ( void )
{
F_49 ( & V_104 , & V_105 ) ;
#ifdef F_50
V_104 . V_106 = F_42 ;
V_104 . V_107 = F_45 ;
#endif
return F_51 ( & V_108 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_108 ) ;
}
