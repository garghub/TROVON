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
V_4 -> V_5 == V_43 ) ) {
V_2 -> V_12 |= V_44 ;
}
if ( V_4 -> V_7 == V_26 &&
V_4 -> V_5 == V_40 ) {
V_2 -> V_12 |= V_45 ;
}
if ( V_4 -> V_7 == V_26 &&
( V_4 -> V_5 == V_40 ||
V_4 -> V_5 == V_43 ) )
V_2 -> V_12 |= V_46 ;
if ( V_4 -> V_7 == V_47 &&
V_4 -> V_5 == V_48 ) {
V_2 -> V_12 |= V_49 ;
V_2 -> V_12 |= V_18 ;
V_2 -> V_12 |= V_16 ;
}
if ( V_4 -> V_7 == V_50 &&
V_4 -> V_5 == 0x0015 )
V_2 -> V_12 |= V_49 ;
if ( V_4 -> V_7 == V_51 )
V_2 -> V_12 |= V_49 ;
if ( V_4 -> V_7 == V_51 &&
V_4 -> V_5 == 0x3432 )
V_2 -> V_12 |= V_16 ;
if ( V_4 -> V_7 == V_52 &&
V_4 -> V_5 == 0x1042 )
V_2 -> V_12 |= V_16 ;
if ( V_2 -> V_12 & V_49 )
F_6 ( V_2 , V_14 ,
L_9 ) ;
}
static void F_8 ( struct V_3 * V_6 )
{
static const T_1 V_53 [] = {
0xb7 , 0x0c , 0x34 , 0xac , 0x01 , 0xe9 , 0xbf , 0x45 ,
0xb7 , 0xe6 , 0x2b , 0x34 , 0xec , 0x93 , 0x1e , 0x23 ,
} ;
union V_54 * V_55 ;
V_55 = F_9 ( F_10 ( & V_6 -> V_6 ) , V_53 , 3 , 1 ,
NULL ) ;
F_11 ( V_55 ) ;
}
static void F_8 ( struct V_3 * V_6 ) { }
static int F_12 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_5 ( V_57 -> V_58 . V_59 ) ;
int V_60 ;
V_2 = F_13 ( V_57 ) ;
if ( ! V_2 -> V_61 )
F_14 ( V_4 , V_62 , & V_2 -> V_61 ) ;
V_60 = F_15 ( V_57 , F_4 ) ;
if ( V_60 )
return V_60 ;
if ( ! F_16 ( V_57 ) )
return 0 ;
F_3 ( V_2 , L_10 , ( unsigned int ) V_2 -> V_61 ) ;
return F_1 ( V_2 , V_4 ) ;
}
static int F_17 ( struct V_3 * V_6 , const struct V_63 * V_64 )
{
int V_60 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_56 * V_57 ;
V_66 = (struct V_65 * ) V_64 -> V_67 ;
F_18 ( & V_6 -> V_6 ) ;
V_60 = F_19 ( V_6 , V_64 ) ;
if ( V_60 )
goto V_68;
V_57 = F_20 ( & V_6 -> V_6 ) ;
V_2 = F_13 ( V_57 ) ;
V_2 -> V_69 = F_21 ( V_66 , & V_6 -> V_6 ,
F_22 ( V_6 ) , V_57 ) ;
if ( ! V_2 -> V_69 ) {
V_60 = - V_70 ;
goto V_71;
}
V_60 = F_23 ( V_2 -> V_69 , V_6 -> V_72 ,
V_73 ) ;
if ( V_60 )
goto V_74;
if ( ! ( V_2 -> V_12 & V_16 ) &&
F_24 ( V_2 -> V_75 ) >= 4 )
V_2 -> V_69 -> V_76 = 1 ;
if ( V_2 -> V_12 & V_44 )
F_8 ( V_6 ) ;
F_25 ( & V_6 -> V_6 ) ;
return 0 ;
V_74:
F_26 ( V_2 -> V_69 ) ;
V_71:
F_27 ( V_6 ) ;
V_68:
F_25 ( & V_6 -> V_6 ) ;
return V_60 ;
}
static void F_28 ( struct V_3 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( F_29 ( V_6 ) ) ;
V_2 -> V_77 |= V_78 ;
if ( V_2 -> V_69 ) {
F_30 ( V_2 -> V_69 ) ;
F_26 ( V_2 -> V_69 ) ;
}
if ( V_2 -> V_12 & V_37 )
F_31 ( V_6 , V_79 ) ;
F_27 ( V_6 ) ;
}
static void F_32 ( struct V_56 * V_57 , bool V_80 )
{
struct V_1 * V_2 = F_13 ( V_57 ) ;
T_2 V_81 ;
void T_3 * V_82 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
V_82 = ( void T_3 * ) V_2 -> V_85 +
V_86 +
V_83 * V_87 ;
V_81 = F_33 ( V_82 ) & ~ V_88 ;
F_34 ( V_81 , V_82 ) ;
V_81 = F_33 ( V_82 ) ;
if ( V_80 )
V_81 |= V_89 ;
else
V_81 &= ~ V_89 ;
F_34 ( V_81 , V_82 ) ;
V_81 = F_33 ( V_82 ) | V_88 ;
F_34 ( V_81 , V_82 ) ;
F_33 ( V_82 ) ;
}
}
static void F_35 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_13 ( V_57 ) ;
void T_3 * V_82 ;
T_2 V_81 ;
V_82 = ( void T_3 * ) V_2 -> V_85 + 0x80a4 ;
V_81 = F_33 ( V_82 ) ;
F_34 ( V_81 | F_36 ( 28 ) , V_82 ) ;
F_33 ( V_82 ) ;
}
static int F_37 ( struct V_56 * V_57 , bool V_90 )
{
struct V_1 * V_2 = F_13 ( V_57 ) ;
struct V_3 * V_4 = F_5 ( V_57 -> V_58 . V_59 ) ;
int V_91 ;
if ( V_2 -> V_12 & V_92 )
F_38 ( V_4 ) ;
if ( V_2 -> V_12 & V_44 )
F_35 ( V_57 ) ;
if ( V_2 -> V_12 & V_45 )
F_32 ( V_57 , true ) ;
V_91 = F_39 ( V_2 , V_90 ) ;
if ( V_91 && ( V_2 -> V_12 & V_45 ) )
F_32 ( V_57 , false ) ;
return V_91 ;
}
static int F_40 ( struct V_56 * V_57 , bool V_93 )
{
struct V_1 * V_2 = F_13 ( V_57 ) ;
struct V_3 * V_4 = F_5 ( V_57 -> V_58 . V_59 ) ;
int V_60 = 0 ;
if ( V_4 -> V_7 == V_26 )
F_41 ( V_4 ) ;
if ( V_2 -> V_12 & V_45 )
F_32 ( V_57 , false ) ;
if ( V_2 -> V_12 & V_44 )
F_35 ( V_57 ) ;
V_60 = F_42 ( V_2 , V_93 ) ;
return V_60 ;
}
static int T_4 F_43 ( void )
{
F_44 ( & V_94 , & V_95 ) ;
#ifdef F_45
V_94 . V_96 = F_37 ;
V_94 . V_97 = F_40 ;
#endif
return F_46 ( & V_98 ) ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_98 ) ;
}
